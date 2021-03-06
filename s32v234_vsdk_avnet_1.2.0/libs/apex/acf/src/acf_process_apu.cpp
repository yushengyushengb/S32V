/******************************************************************************
 *  (C) Copyright CogniVue Corporation. 2015 All right reserved.
 *  
 *  Confidential Information
 *
 *  All parts of the CogniVue Program Source are protected by copyright law
 *  and all rights are reserved.
 *  This documentation may not, in whole or in part, be copied, photocopied,
 *  reproduced, translated, or reduced to any electronic medium or machine
 *  readable form without prior consent, in writing, from CogniVue.
 ******************************************************************************/

#include <acf_common.h>
#include <acf_process.h>
#include <acf_process_apu.h>
#include <acf_process_portinfo.h>
#include <acf_process_portinfo_apu.h>
#include <acf_apu_program_params.h>
#include <resource_manager_protected.h>
#include <resource_manager_apex.h>
#include <seq_hal.h>
#include <apu_hal.h>
#include <apu_microkernel_hal.h>
#include <cmem_if_hal.h>
#include <mcdma_hal.h>
#include <mce_hal.h>
#include <stio_hal.h>
#include <kernel_manager.h>
#include <hw_reg_user.h>
#include <apex.h>
#include <apex_interrupt.h>

#if 0
  #define INTR_DEBUG_PRINTF(...) printf( __VA_ARGS__)
#else
  #define INTR_DEBUG_PRINTF(...)
#endif

//these currently required to allow ACF to query the APU configuration and to set the desired default configuration
#include <global_hal.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h> //for memcpy

using namespace std;

const double APEX_CLOCK_FREQ = 500000000.0;
#include <time_helper.h>

#if (ACF_DEBUG_HW_REG == 1 || ACF_DEBUG_DUMP == 1)
typedef unsigned int REG32;
#include <apex_642cl_mcdma_map.h>
#include <apex_642cl_stream_dma_map.h>
#include <apex_642cl_seq_map.h>
#include <apex_642cl_motion_comp_map.h>
#endif

#if (ACF_HOST_PROFILING_LVL == 0)
   #define ACF_HOST_PROBE_LVL1(idx)
   #define ACF_HOST_PROBE_LVL2(idx)
#elif (ACF_HOST_PROFILING_LVL == 1)
   #define ACF_HOST_PROBE_LVL1(idx) (mProbeArray[idx] = RET_TICKS)
   #define ACF_HOST_PROBE_LVL2(idx)
#elif (ACF_HOST_PROFILING_LVL == 2)
   #define ACF_HOST_PROBE_LVL1(idx) (mProbeArray[idx] = RET_TICKS)
   #define ACF_HOST_PROBE_LVL2(idx) (mProbeArray[idx] = RET_TICKS)
#endif

#if (ACF_ENABLE_HW_PROFILING == 1)
#include <mcdma_hal.h> //for use of 'performance' profiling registers
#endif

#if (ACF_DEBUG_HW_REG == 1)
void DUMP_SMEM_TO_FILE(const char* lFileName, int32_t lSizeInBytes, int32_t lSmemOffset)
{
   FILE* lpFileDump = fopen (lFileName,"wb");
   volatile uint32_t* lpSMEM = (volatile uint32_t*)((intptr_t)ReturnVirtualHwPtr(0, HW_REG_SMEM) + lSmemOffset);
   fwrite((void*)lpSMEM, 1, lSizeInBytes, lpFileDump);
   fclose(lpFileDump);
}

void DUMP_CMEM_TO_FILE(const char* lFileName, int32_t lSizeInBytes)
{
   FILE* lpFileDump = fopen (lFileName,"wb");
   volatile uint32_t* lpCMEM = (volatile uint32_t*)((intptr_t)ReturnVirtualHwPtr(0, HW_REG_CMEM_GOC));
   fwrite((void*)lpCMEM, 1, lSizeInBytes, lpFileDump);
   fclose(lpFileDump);
}
#endif

#if (ACF_DEBUG_CMEM == 1)
const int CMEMSIZE = 4096;
const int GOCSIZE  = 8;
void dumpcmem8(int cuid, int cmemaddr, int chunkwidth, int chunkheight, int chunkstride)
{
   ///**cmemaddr must be byte addressable from ACP's perspective (i.e. must be divisible by 2)

   int* gpCmem = (int*)ReturnVirtualHwPtr(HW_REG_CMEM_GOC);
   uint8_t* lpVal8 = (uint8_t*)gpCmem + ((cuid/GOCSIZE)*CMEMSIZE*GOCSIZE) + (cuid%GOCSIZE)*2 + (cmemaddr>>1)*16;

   for (int y=0; y<chunkheight; y++)
   {
      for (int x=0; x<chunkwidth; x+=2)
      {
         printf("%3d ", lpVal8[(y*(chunkstride>>1)+(x>>1))*16]);
         printf("%3d ", lpVal8[(y*(chunkstride>>1)+(x>>1))*16 + 1]);
      }
      printf("\n");
   }
   printf("\n");
}

void dumpcmem16(int cuid, int cmemaddr, int chunkwidth, int chunkheight, int chunkstride)
{
   //**cmemaddr must be byte addressable from ACP's perspective (i.e. must be divisible by 2)

   int* gpCmem = (int*)ReturnVirtualHwPtr(HW_REG_CMEM_GOC);
   uint8_t* lpVal8   = (uint8_t*)gpCmem + ((cuid/GOCSIZE)*CMEMSIZE*GOCSIZE) + (cuid%GOCSIZE)*2 + (cmemaddr>>1)*16;
   uint16_t* lpVal16 = (uint16_t*)lpVal8;

   for (int y=0; y<chunkheight; y++)
   {
      for (int x=0; x<chunkwidth; x++)
      {
         printf("%5d ", lpVal16[(y*chunkstride+x)*8]);
      }
      printf("\n");
   }
   printf("\n");
}
#endif

#if (ACF_ENABLE_HW_PROFILING == 1)
#include <mcdma_hal.h> //for use of 'performance' profiling registers
#endif

//translate ACF_APU_CFG to CMEM_IF_APU_CFG (don't want to expose CMEM_IF_APU_CFG through interface)
CMEM_IF_APU_CFG Translate_AcfApuCfg_CmemIfApuCfg(ACF_APU_CFG lApuConfig, int32_t lHwVersion)
{
   CMEM_IF_APU_CFG lRetVal = CFG_UNKNOWN_CONFIGURATION;

   switch (lApuConfig)
   {
   case ACF_APU_CFG__DEFAULT:
      if      (0x321 == lHwVersion) lRetVal = CFG_321__APU_0_CU_0_31_SMEM_0_1;
      else if (0x642 == lHwVersion) lRetVal = CFG_642__APU_0_CU_0_63_SMEM_0_3;
      break;
   case ACF_APU_CFG__APU_0_CU_0_63_SMEM_0_3:
      lRetVal = CFG_642__APU_0_CU_0_63_SMEM_0_3;
      break;
   case ACF_APU_CFG__APU_0_CU_0_31_SMEM_0_1:
      if      (0x321 == lHwVersion) lRetVal = CFG_321__APU_0_CU_0_31_SMEM_0_1;
      else if (0x642 == lHwVersion) lRetVal = CFG_642__APU_0_CU_0_31_SMEM_0_1__APU_1_CU_32_63_SMEM_2_3;
      break;
   case ACF_APU_CFG__APU_1_CU_32_63_SMEM_2_3:
      lRetVal = CFG_642__APU_0_CU_0_31_SMEM_0_1__APU_1_CU_32_63_SMEM_2_3;
      break;
   }

   return lRetVal;
}

void CfgResSet_321_ALL(acf_res_info* lpAcfResInfo);
void CfgResSet_642_ALL(acf_res_info* lpAcfResInfo);
void CfgResSet_642_HALF_APU0(acf_res_info* lpAcfResInfo);
void CfgResSet_642_HALF_APU1(acf_res_info* lpAcfResInfo);

void AcfInterruptCallback(void* lpParam, int32_t* lpRetVal)
{
   ACF_Process_APU* lpAcfProcessApu = (ACF_Process_APU*) lpParam;

   INTR_DEBUG_PRINTF("[%08X] AcfInterruptCallback() activated\n", lpAcfProcessApu);

   int32_t lRes = 0;
   lRes |= lpAcfProcessApu->ClearCallback();
   lRes |= lpAcfProcessApu->ReleaseWaitSync();

   if (0 != lRes)
   {
      printf("AcfInterruptCallback failure!!\n");
      *lpRetVal = lRes;
   }
   else
   {
      *lpRetVal = 0;
   }

   //call user defined callback
   lpAcfProcessApu->CallUserDefinedCallback();
}

//-------------------------------------------------------------------------------
//***********************ACF_Process_APU*****************************************
//-------------------------------------------------------------------------------

ACF_Process_APU::ACF_Process_APU()
{
   ConstructorInitialize();
}

ACF_Process_APU::ACF_Process_APU(int apexID)
{
   ConstructorInitialize();
   mApexId = apexID;
}

void ACF_Process_APU::ConstructorInitialize()
{
   mApexId                 = 0;
   mApuCfg                 = ACF_APU_CFG__DEFAULT;
   mApuId                  = 0;
   mCuArrayWidth           = 32;
   mHwVersion              = 0;

   mCmemHeapBaseAddrOffset = 0;
   mCmemHeapSizeInBytes    = 0;
   mSmemBaseAddrOffset     = 0;
   mPmemBaseAddrOffset     = 0;
   mPmemSizeInBytes        = 0;
   mDmemBaseAddrOffset     = 0;
   mDmemSizeInBytes        = 0;
   mDmemHeapBaseAddrOffset = 0;
   mDmemHeapSizeInBytes    = 0;

   mLoadSegments = 0;
   mpLoadPmem    = 0;
   mLoadPmemSize = 0;
   mpLoadDmem    = 0;
   mLoadDmemSize = 0;
   mpLoadCmem    = 0;
   mLoadCmemSize = 0;

   mpScenarioList              = 0;
   mpSelectedScenario          = 0;
   mUserControlledScenarioFlag = 0;

   mClover389Flag = 0;

   mUserId    = 0;
   mNumResReq = 0;

   mProgramParamSizeInWords = 0;

   mpPmemLoadOal       = 0;
   mpDmemLoadOal       = 0;
   mpCmemLoadOal       = 0;
   mpLoadSegmentsLLOal = 0;

   mProcessStartedFlag = 0;

   mApuProgFuncPtr     = 0;

   //must be initialized to 0 (used to know if they have been allocated or not)
   mSelectedScenario.pBufferData = 0;
   mSelectedScenario.pKernelData = 0;

   mApuProgramRetVal = ACF_SUCCESS;

   mWaitSemaphore              = 0;
   mWaitMode                   = ACF_WAIT_MODE_INTERRUPT; //use interrupt-based wait mode by default
   mWaitSync                   = 0;
   mpCallbackParam             = 0;
   mCallbackRetVal             = 0;
   mpUserDefinedCallback       = 0;
   mpUserDefinedCallbackParam  = 0;
   mpUserDefinedCallbackRetVal = 0;

   mCycles_apu_total      = 0;
   mCycles_apu_init       = 0;
   mCycles_apu_processing = 0;
   mCycles_apu_idle       = 0;
   mCycles_apu_kernel     = 0;
   mCycles_apu_padPlusCb  = 0;

   mScenarioSelectionBufferPolicy = ACF_SCENARIO_SELECTION_BUFFER_POLICY_STRICT;
   mScenarioSelectionBias = ACF_SCENARIO_SELECTION_BIAS_BALANCED;
}

ACF_Process_APU::~ACF_Process_APU()
{
   if (mpPmemLoadOal)       OAL_MemoryFree(mpPmemLoadOal);
   if (mpDmemLoadOal)       OAL_MemoryFree(mpDmemLoadOal);
   if (mpCmemLoadOal)       OAL_MemoryFree(mpCmemLoadOal);
   if (mpLoadSegmentsLLOal) OAL_MemoryFree(mpLoadSegmentsLLOal);
   if (mWaitSemaphore)      OAL_SemaphoreDelete(mWaitSemaphore);

   CleanupLocalScenario();
}

int32_t ACF_Process_APU::Start_Setup()
{
#if (ACF_DEBUG_HW_REG == 1 || ACF_DEBUG_DUMP == 1)
   mpSmem = (uint32_t*)ReturnVirtualHwPtr(mApexId, HW_REG_SMEM);
   mpCmem = (uint32_t*)ReturnVirtualHwPtr(mApexId, HW_REG_CMEM_GOC);
   mpDma  = (_APEX_642CL_MCDMA_TAG*)ReturnVirtualHwPtr(mApexId, HW_REG_MCDMA);
   mpStio = (_APEX_642CL_STREAM_DMA_TAG*)ReturnVirtualHwPtr(mApexId, HW_REG_STIO);
   mpSeq  = (_APEX_642CL_SEQ_TAG*)ReturnVirtualHwPtr(mApexId, HW_REG_USEQ);
   mpMotionComp = (_APEX_642CL_MOTION_COMP_TAG*)ReturnVirtualHwPtr(mApexId, HW_REG_MODMA);
#endif

   ACF_HOST_PROBE_LVL1(0);

   int32_t lRetVal = ACF_SUCCESS;
   
   //TODO: implement the idea of a 'dirty' flag that indicates whether or not SelectScenario and DetWorstCaseRoiInfo
   //      need to be re-run or not.  The flag could be raised whenever a new IO is connected (although it should be
   //      even more intelligent than that in theory ... if only the address changes many things don't need to be
   //      recalculated, but if the ROI location changes (for example) they do).  This could actually get pretty
   //      complicated ... until this is implemented properly some things may be called redundantly or unnecessarily.

   if (0 == Initialized()) //if process was never never successfully initialized, exit immediately
   {
      printf("ACF_Process_APU::Start_Setup() -> process was never successfully initialized; not starting\n");
      lRetVal = ACF_ERROR;
      return lRetVal;
   }

   //if any internal state errors have occurred prior to invocation of Start_Setup(), exit immediately
   if (mErrorState != 0)
   {
      printf("ACF_Process_APU::Start_Setup() -> internal state error detected; not starting\n");
      lRetVal = ACF_ERROR;
      return lRetVal;
   }

   if (mRoiInfoManualFlag != 1)
   {
      if (DetWorstCaseRoiInfo() != 0) //check applicable inputs for ROI information
      {
         lRetVal = ACF_ERROR;
         return lRetVal;
      }
   }

   ACF_HOST_PROBE_LVL2(1);

   //**************************************************************
   //SCENARIO SELECTION

   //if the user is not in control of scenario selection
   if (0 == mUserControlledScenarioFlag)
   {
      //if a scenario has not already been selected or if the connected IO sizes have changed
      if (0 == mpSelectedScenario || 1 == QueryIoSizeChangeFlag())
      {
         SelectScenario_internal("", 0, 0); //select optimal scenario
      }
   }

   if (mpSelectedScenario != 0)
   {
      //update chunk information associated with input/output ports based on the selected scenario
      //(done like this to eliminate need to change GenApuProgramParams ... should probably be cleaned up
      for (int32_t i=0; i<(int32_t)mPortInfoVec.size(); i++)
      {
         mPortInfoVec[i].mChunkWidth = mpSelectedScenario->pBufferData[mPortInfoVec[i].mLmIndex].chunkWidth;
         mPortInfoVec[i].mChunkHeight = mpSelectedScenario->pBufferData[mPortInfoVec[i].mLmIndex].chunkHeight;
      }
   }
   else
   {
      lRetVal = ACF_SCENARIO_DETECTION_ERROR;
      return lRetVal; //<<<<<<<<<<
   }
   //***********************************************************************

   ACF_HOST_PROBE_LVL2(2);

   //based on the selected scenario, determine if a 1D processing pipeline should be utilized
   //if the graph has any spatial dependencies it will be treated as 2D, regardless of input dimensions
   int32_t lFlag1D = 0;
   if (mSpatialDepFlag == 0)
   {
      lFlag1D = CheckIf1D_pipeline(mPortInfoVec);
   }

   mProgramParamSizeInWords = MAX_PARAM_LIST_SIZE_IN_WORDS; //init with 'max' - GenApuProgramParams will override it with 'actual' size

   ACF_HOST_PROBE_LVL2(3);
   
   int32_t lFlag_hwResAlloc = 0;

   if (0 == GenApuProgramParams(mPortInfoVec, mPortInfoApuVec, mRoiInfoL, mRoiInfoR, mRoiInfoT, mRoiInfoB,
                                lFlag1D, mCuArrayWidth, mProgramParams, &mProgramParamSizeInWords,
                                mpSelectedScenario))
   {
      ACF_HOST_PROBE_LVL2(4);

      //*************************
      //acquire HW resources
      //*************************

      if (ACF_SUCCESS == AllocateHwResources())
      {
         ACF_HOST_PROBE_LVL2(5);

         if (ACF_WAIT_MODE_INTERRUPT == mWaitMode)
         {
            //register interrupt callback
            int32_t lInterrupt = SEQUENCER_RES_30;
            if (mAcfResInfo.zeroSeqRes_Done == 31)
               lInterrupt = SEQUENCER_RES_31;
            mpCallbackParam = (void*)this;
            mCallbackRetVal = 0;
            lRetVal = APEX_InterruptRegisterCallback(mApexId, lInterrupt, &AcfInterruptCallback, mpCallbackParam, &mCallbackRetVal);
            INTR_DEBUG_PRINTF("[%08X] ACF_Process_APU::Start_Setup() -> apexid=%d apuid=%d intr=%d sem=%X\n", (uintptr_t)this, mApexId, mApuId, mAcfResInfo.zeroSeqRes_Done, (intptr_t)mWaitSemaphore);
         }

         lFlag_hwResAlloc = 1;

         //----------------------------------------------------------------------------
         switch (mApexId)
         {
            case 0:
               mProgramParams[8] = 0x74000000 + mSmemBaseAddrOffset + mDmemBaseAddrOffset; //physical DMEM start address from ARM/DMA perspective
               break;
            case 1:
               mProgramParams[8] = 0x78000000 + mSmemBaseAddrOffset + mDmemBaseAddrOffset; //physical DMEM start address from ARM/DMA perspective
               break;
         }
         
         mProgramParams[9] = mCmemHeapBaseAddrOffset;
         mProgramParams[10] = mCmemHeapSizeInBytes;
         mProgramParams[11] = mDmemHeapBaseAddrOffset; //DMEM heap start address from APU's perspective (relative to DMEM start)
         mProgramParams[12] = mDmemHeapSizeInBytes;
         mProgramParams[13] = mClover389Flag;

         memcpy((void*)&mProgramParams[14], (void*)&mAcfResInfo, sizeof(acf_res_info));
         //----------------------------------------------------------------------------

         //****************************
         //APU setup and program launch
         //****************************

         int32_t lMsg = 0;

         ACF_HOST_PROBE_LVL2(6);

         //printf("STATE: apex=%d apu=%d dmaChIn[0]=%d pmemaddr=0x%08X dmemaddr=0x%08X\n", mApexId, mAcfResInfo.apuId, mAcfResInfo.dmaChIn[0], mSmemBaseAddrOffset + mPmemBaseAddrOffset, mSmemBaseAddrOffset + mDmemBaseAddrOffset);

         //NOTE: cmem_if MUST be configured prior to invoking the apu loader (apu loader will query cmem_if for relevant information)
         cmem_if_hal_set_apu_cfg(mApexId, Translate_AcfApuCfg_CmemIfApuCfg(mApuCfg, mHwVersion));
         cmem_if_hal_set_apu_pmem_start(mApexId, mApuId, mSmemBaseAddrOffset + mPmemBaseAddrOffset);
         cmem_if_hal_set_apu_dmem_start(mApexId, mApuId, mSmemBaseAddrOffset + mDmemBaseAddrOffset);

         ACF_HOST_PROBE_LVL2(7);
         ACF_HOST_PROBE_LVL2(8);

         int32_t lRetVal_apuload = -1;

         #if 1 //use DMA-based segment loading (faster)
         lRetVal_apuload = apu_hal_LoadSegments_DMA(mApexId, mApuId, mAcfResInfo.dmaChIn[0], mpLoadSegmentsLLOal);
         #else //use memcpy based segment loading (better for debugging)
         lRetVal_apuload = apu_hal_LoadSegment(mApexId, mApuId, mLoadSegments);
         #endif

         ACF_HOST_PROBE_LVL2(9);

         //SanityCheck_ProgramMem((volatile uint32_t*)((intptr_t)ReturnVirtualHwPtr(mApexId, HW_REG_SMEM) + mSmemBaseAddrOffset + mPmemBaseAddrOffset));
         //SanityCheck_ProgramMem_Dma();

         if (0 == lRetVal_apuload) //if the apu load was successful
         {
            apu_hal_Enable(mApexId, mApuId, 1); //enable the apu

            #if 0
            //DO WHAT HOST WOULD USUALLY DO but without calling any functions
            volatile int32_t* lpAPU0_DMEM_SHARED = (volatile int32_t*)((int32_t)ReturnVirtualHwPtr(HW_REG_SMEM) + DMEM_SHARED_OFFSET);
            FILE* lpFileInit = fopen ("C:\\SMEMDUMP_0x600_0xDFF_APU_GFTT_GET_CORNER_2D.bin","rb");
            fread((void*)(lpAPU0_DMEM_SHARED), 1, 2048, lpFileInit);
            fclose(lpFileInit);
            #endif

            int lRetVal_rx = apumk_hal_host_com_rx(mApexId, (int)mApuId, &lMsg, 500000);
            if (0 == lRetVal_rx)
            {
               //printf("ACF_Process_APU::Start_Setup() -> APU enabled (0x%X)\n",lMsg);

               ACF_HOST_PROBE_LVL2(10);
               //FlushAndInvalidateAllIO();
               ACF_HOST_PROBE_LVL2(11);

               //**************************
               //EVERYTHING IS READY TO GO
               //**************************

               ACF_HOST_PROBE_LVL2(12);

               int lRetVal_sendcmd = apumk_hal_send_cmd(mApexId, mApuId, (int)mApuProgFuncPtr, mProgramParamSizeInWords, (const int32_t*)mProgramParams);
               if (0 == lRetVal_sendcmd)
               {
                  #if (ACF_ENABLE_HW_PROFILING == 1)
                  mcdma_hal_enable_perf_counter(mApexId);
                  #endif
                  //SanityCheck_ProgramParams();
               }
               else //apu send command failure
               {
                  printf("ACF_Process_APU::Start_Setup() -> apu send command failed (apumk_hal_send_cmd, return value = %d)\n", lRetVal_sendcmd);

                  #if (ACF_DEBUG_DUMP == 1)
                  SanityCheck_ProgramMem_Dma();
                  #endif

                  lRetVal = ACF_ERROR;
               }

               ACF_HOST_PROBE_LVL2(13);

               #if 0
               //dump the shared region for easier SIM
               //IN THE FUTURE I SHOULD ALSO UPDATE ALL PHYSICAL ADDRESSES SO THEY ARE MEANINGFUL
               const int32_t SHARED_REGION_SIZE = 2*1024;
               uint32_t lDmemShared[SHARED_REGION_SIZE];
               volatile int32_t* lpAPU0_DMEM_SHARED = (volatile int32_t*)((int32_t)ReturnVirtualHwPtr(HW_REG_SMEM) + DMEM_SHARED_OFFSET);
               memcpy((void*)lDmemShared, (void*)lpAPU0_DMEM_SHARED, SHARED_REGION_SIZE);

               //this file needs to be copied into DMEM at a specific time: <break @ last line of apu_mk_main() in apu_mk_main.cpp>

               //update a couple values so this can be used to kickstart the ISS/RTLSIM (satisfy the MK handshaking so program execution can begin)
               lDmemShared[5] ++; //send init acknowledgment
               lDmemShared[2] = HOST_MSG_SENDCMD;
               lDmemShared[0] ++; //trigger things

               std::string lFileName = "C:\\SMEMDUMP_0x600_0xDFF_"+RetProcessIdentifier()+".bin";
               FILE* lpFileSharedRegionDump = fopen (lFileName .c_str(),"wb");
               fwrite((void*)lDmemShared, 1, SHARED_REGION_SIZE , lpFileSharedRegionDump);
               fclose(lpFileSharedRegionDump);
               #endif

               #if 0
               std::string lFileName;
               lFileName = "C:\\SMEM_RESULT_DUMP_" + RetProcessIdentifier() + ".bin";
               DUMP_SMEM_TO_FILE(lFileName.c_str(), 1024*64);
               lFileName = "C:\\CMEM_RESULT_DUMP_" + RetProcessIdentifier() + ".bin";
               DUMP_CMEM_TO_FILE(lFileName.c_str(), 4096*32);
               #endif
            }
            else //apu mk communication failure
            {
               printf("ACF_Process_APU::Start_Setup() -> apu mk communication failed (apumk_hal_host_com_rx, return value = %d)\n", lRetVal_rx);

               #if (ACF_DEBUG_DUMP == 1)
               SanityCheck_ProgramMem_Dma();
               #endif

               lRetVal = ACF_ERROR;
            }
         }
         else //apu load failure
         {
            printf("ACF_Process_APU::Start_Setup() -> apu load failed (return value = %d)\n", lRetVal_apuload);
            lRetVal = ACF_ERROR;
         }
      }
      else //HW resource acquisition failure
      {
         printf("ACF_Process_APU::Start_Setup() -> HW resources could not be acquired\n");
         lRetVal = ACF_HW_RESOURCE_ERROR;
      }
   }
   else //GenApuProgramParams failure
   {
      printf("ACF_Process_APU::Start_Setup() -> program parameter generation failed\n");
      lRetVal = ACF_ERROR;
   }
   
   //---------------------------------------------------------
   //if any errors occurred above, perform appropriate cleanup
   //---------------------------------------------------------

   if (lRetVal != ACF_SUCCESS)
   {
      #if (ACF_DEBUG_DUMP == 1)
      DebugDump();
      #endif

      if (1 == lFlag_hwResAlloc)
      {
         apu_hal_Enable(mApexId, mApuId, 0); //disable the apu

         if (0 != DeallocateHwResources())
            printf("ACF_Process_APU::Start_Setup() -> HW resource deallocation failed\n");
      }
   }

   return lRetVal;
}

int32_t ACF_Process_APU::Start_Kick()
{
   int32_t lRetVal = 0;

   ACF_HOST_PROBE_LVL2(14);

   int lRetVal_tx = apumk_hal_host_com_tx(mApexId, (int)mApuId, HOST_MSG_SENDCMD, 500000);
   if (0 == lRetVal_tx)
   {
      mProcessStartedFlag = 1;
   }
   else //apu mk communication failure
   {
      printf("ACF_Process_APU::Start_Kick() -> apu mk communication failed (apumk_hal_host_com_tx, return value = %d)\n", lRetVal_tx);

      #if (ACF_DEBUG_DUMP == 1)
      SanityCheck_ProgramParams();
      SanityCheck_ProgramMem_Dma();
      DebugDump();
      #endif

      apu_hal_Enable(mApexId, mApuId, 0); //disable the apu

      if (0 != DeallocateHwResources())
         printf("ACF_Process_APU::Start_Kick() -> HW resource deallocation failed\n");

      lRetVal = ACF_ERROR;
   }

   ACF_HOST_PROBE_LVL1(15);

   return lRetVal;
}

int32_t ACF_Process_APU::Start()
{
   int32_t lRetVal = ACF_SUCCESS;

   if (0 == mProcessStartedFlag) //if the process is not currently running
   {
      lRetVal = Start_Setup();
      if (0 == lRetVal)
      {
         lRetVal = Start_Kick();
      }
   }
   else //wait was never paired with the previous Start()
   {
      printf("ACF_Process_APU::Start() -> the previous Start() call was not paired with a Wait(); not starting\n");
      lRetVal = ACF_ERROR;
   }

   return lRetVal;
}

int32_t ACF_Process_APU::CleanupSuccess()
{
   int32_t lRetVal = 0;

   //sync with mk and retrieve apu program return value
   int32_t lMsg = 0;
   int lRetVal_rx = apumk_hal_host_com_rx(mApexId, (int)mApuId, &lMsg, 500000);
   if (0 == lRetVal_rx)
   {
      mApuProgramRetVal = RET_VAL(lMsg);
   }
   else
   {
      printf("ACF_Process_APU::Wait() -> apu mk communication failed (apumk_hal_host_com_rx, return value = %d)\n", lRetVal_rx);
      lRetVal = ACF_ERROR;
   }

   //disable APU
   apu_hal_Enable(mApexId, mApuId, 0);

   //extract apu cycle info from DMEM before releasing HW resources
   int32_t* lpDmem = (int32_t*)((uintptr_t)ReturnVirtualHwPtr(mApexId, HW_REG_SMEM) + mSmemBaseAddrOffset + mDmemBaseAddrOffset);
   struct ApuPerfInfoStruct * lpPerfInfo = (struct ApuPerfInfoStruct *)&lpDmem[0x1200/4];
   mCycles_apu_total      = lpPerfInfo->total;
   mCycles_apu_init       = lpPerfInfo->init;
   mCycles_apu_processing = lpPerfInfo->processing;
   mCycles_apu_idle       = lpPerfInfo->idle;
   mCycles_apu_kernel     = lpPerfInfo->kernel;
   mCycles_apu_padPlusCb  = lpPerfInfo->padPlusCb;

   #if (ACF_DEBUG_DUMP == 1)
   //check the 'state' of all the allocated DMA channels (all should be done and ready to be re-used)
   int lRetVal_chstate = 0;
   for (int i=0; i<mAcfResInfo.numDmaChIn; i++)
      lRetVal_chstate |= mcdma_hal_checkChState(mApexId, mAcfResInfo.dmaChIn[i]);
   for (int i=0; i<mAcfResInfo.numDmaChOut; i++)
      lRetVal_chstate |= mcdma_hal_checkChState(mApexId, mAcfResInfo.dmaChOut[i]);
   #endif

   return lRetVal;
}

int32_t ACF_Process_APU::CleanupFailure()
{
   //disable APU
   apu_hal_Enable(mApexId, mApuId, 0);

   //disable sequencer
   seq_hal_disable_seq(mApexId, mAcfResInfo.procIdSeqRes);

   //disable SCBs
   int lScbMask = 0;
   for (int i=0; i<mAcfResInfo.numDmaChIn; i++)
      lScbMask |= (1ul << mAcfResInfo.dmaChIn[i]);
   for (int i=0; i<mAcfResInfo.numDmaChOut; i++)
      lScbMask |= (1ul << mAcfResInfo.dmaChOut[i]);
   for (int i=0; i<mAcfResInfo.numMceChIn; i++)
      lScbMask |= (1ul << RetMceScbId(mAcfResInfo.mceChIn[i]));
   seq_hal_scb_disable(mApexId, lScbMask);

   //wait until DMA channels have nothing in flight and try to clean them up

   const int32_t lTransferTimeoutInUs = 500000;

   for (int i=0; i<mAcfResInfo.numDmaChIn; i++)
   {
      mcdma_hal_wait_ch_enable_timeout(mApexId, mAcfResInfo.dmaChIn[i], lTransferTimeoutInUs);
      //mcdma_hal_ch_clear(mApexId, mAcfResInfo.dmaChIn[i]);
      mcdma_hal_ch_flush(mApexId, mAcfResInfo.dmaChIn[i]);
   }

   for (int i=0; i<mAcfResInfo.numMceChIn; i++)
   {
      mce_hal_wait_ch_enable_timeout(mApexId, mAcfResInfo.mceChIn[i], lTransferTimeoutInUs);
      //mce_hal_clear_ch(mApexId, mAcfResInfo.mceChIn[i]);
   }

   for (int i=0; i<mAcfResInfo.numDmaChOut; i++)
   {
      mcdma_hal_wait_ch_enable_timeout(mApexId, mAcfResInfo.dmaChOut[i], lTransferTimeoutInUs);
      //mcdma_hal_ch_clear(mApexId, mAcfResInfo.dmaChOut[i]);
      mcdma_hal_ch_flush(mApexId, mAcfResInfo.dmaChOut[i]);
   }

   //clear interrupts associated with DMA, MCE, STIO channels
   for (int i=0; i<mAcfResInfo.numDmaChIn; i++)
      mcdma_hal_interruptclear_ch_done(mApexId, mAcfResInfo.dmaChIn[i]);
   for (int i=0; i<mAcfResInfo.numStreamInChForDma; i++)
      stio_hal_interruptclear_sti_done(mApexId, mAcfResInfo.streamInChForDma[i]);
   for (int i=0; i<mAcfResInfo.numMceChIn; i++)
      mce_hal_clear_int(mApexId, mAcfResInfo.mceChIn[i]);
   for (int i=0; i<mAcfResInfo.numStreamInForMce; i++)
      stio_hal_interruptclear_sti_done(mApexId, mAcfResInfo.streamInChForMce[i]);
   for (int i=0; i<mAcfResInfo.numDmaChOut; i++)
      mcdma_hal_interruptclear_ch_done(mApexId, mAcfResInfo.dmaChOut[i]);
   for (int i=0; i<mAcfResInfo.numStreamOutChForDma; i++)
      stio_hal_interruptclear_sto_done(mApexId, mAcfResInfo.streamOutChForDma[i]);

   //mask sequencer proc interrupts (apu's perspective)
   int lProcIntMask = ((1ul<<mAcfResInfo.procIntSeqRes[0]) | (1ul<<mAcfResInfo.procIntSeqRes[1]) | (1ul<<mAcfResInfo.procIntSeqRes[2]));
   seq_hal_mask_interrupts_apu(mApexId, mAcfResInfo.apuId, lProcIntMask);

   //clear sequencer interrupts associated with proc and done
   for (int i=0; i<mAcfResInfo.numProcIntSeqRes; i++)
      seq_hal_clear_interrupt(mApexId, mAcfResInfo.procIntSeqRes[i]);
   seq_hal_clear_interrupt(mApexId, mAcfResInfo.zeroSeqRes_Done);

   return 0;
}

int32_t ACF_Process_APU::ACF_Process_APU::ClearCallback()
{
   int32_t lRetVal = 0;

   //clear registered interrupt callback
   int32_t lInterrupt = SEQUENCER_RES_30;
   if (mAcfResInfo.zeroSeqRes_Done == 31)
      lInterrupt = SEQUENCER_RES_31;
   APEX_InterruptClearCallback(mApexId, lInterrupt);

   return lRetVal;
}

int32_t ACF_Process_APU::ObtainWaitSync()
{
   INTR_DEBUG_PRINTF("[%08X] ACF_Process_APU::ObtainWaitSync() -> apexid=%d apuid=%d intr=%d sem=%X\n", (uintptr_t)this, mApexId, mApuId, mAcfResInfo.zeroSeqRes_Done, (intptr_t)mWaitSemaphore);

   int32_t lRetVal = 0;

#ifdef __STANDALONE__

   uint64_t lTimeoutProbe = RET_TICKS;
   while (0 == mWaitSync)
   {
      if (CONVERT_TICKS_TO_US(RET_TICKS - lTimeoutProbe) >= mWaitTimeoutInUs)
      {
         printf("ACF_Process_APU::ObtainWaitSync() -> polling-based timeout (%d us)\n", mWaitTimeoutInUs);
         lRetVal = ACF_TIMEOUT_ERROR;
         break;
      }
   }
   mWaitSync = 0; //reset state back to 0

#else //all other OS

   if (OAL_SUCCESS != OAL_SemaphoreObtain(mWaitSemaphore, mWaitTimeoutInUs))
   {
      INTR_DEBUG_PRINTF("[%08X] ACF_Process_APU::ObtainWaitSync() -> failed to obtain semaphore %X (seq_isr = 0x%08X)\n", (uintptr_t)this, (uintptr_t)mWaitSemaphore, seq_hal_query_interrupts(mApexId));
      printf("ACF_Process_APU::ObtainWaitSync() -> semaphore-based timeout (%d us)\n", mWaitTimeoutInUs);
      lRetVal = ACF_TIMEOUT_ERROR;
   }

#endif

   return lRetVal;
}

int32_t ACF_Process_APU::ReleaseWaitSync()
{
   INTR_DEBUG_PRINTF("[%08X] ACF_Process_APU::ReleaseWaitSync() -> apexid=%d apuid=%d intr=%d sem=%X\n", (uintptr_t)this, mApexId, mApuId, mAcfResInfo.zeroSeqRes_Done, (intptr_t)mWaitSemaphore);

   int32_t lRetVal = 0;

#ifdef __STANDALONE__

   mWaitSync = 1;

#else //all other OS

   int32_t lRes = OAL_SemaphoreRelease(mWaitSemaphore);
   if (0 != lRes)
   {
      printf("ACF_Process_APU::ReleaseWaitSemaphore() -> OAL_SemaphoreRelease failed\n");
      lRetVal = 1;
   }

#endif

   return lRetVal;
}

int32_t ACF_Process_APU::CallUserDefinedCallback()
{
   if (0 != mpUserDefinedCallback)
      mpUserDefinedCallback(mpUserDefinedCallbackParam, mpUserDefinedCallbackRetVal);

   return 0;
}

int32_t ACF_Process_APU::Wait()
{
   ACF_HOST_PROBE_LVL1(20);

   int32_t lRetVal = 0;

   if (mProcessStartedFlag) //if the process was successfully started
   {
      //------------------------------
      //WAIT FOR EXECUTION TO COMPLETE
      //------------------------------

      ACF_HOST_PROBE_LVL2(21);

      if (ACF_WAIT_MODE_INTERRUPT == mWaitMode)
      {
         lRetVal = ObtainWaitSync();
      }
      else //polling-based wait mode
      {
         uint64_t lTimeoutProbe = RET_TICKS;

         uint32_t lSeqIsrVal = 0;
         uint32_t lMask = (1ul<<mAcfResInfo.zeroSeqRes_Done);
         while ((lSeqIsrVal & lMask) != lMask)
         {
            lSeqIsrVal = seq_hal_query_interrupts(mApexId);

            if (CONVERT_TICKS_TO_US(RET_TICKS - lTimeoutProbe) >= mWaitTimeoutInUs)
            {
               printf("ACF_Process_APU::Wait() -> polling-based timeout (%d us)\n", mWaitTimeoutInUs);
               lRetVal = ACF_TIMEOUT_ERROR;
               break;
            }
         }

         seq_hal_clear_interrupts(mApexId, lMask);
      }

      ACF_HOST_PROBE_LVL2(22);

      if (0 != lRetVal) //an unexpected wait timeout occurred
      {
         CleanupFailure(); //perform resource specific cleanup
      }
      else //execution completed without issue
      {
         int32_t lCleanupRetVal = CleanupSuccess(); //sets mApuProgramRetVal

         ACF_HOST_PROBE_LVL2(23);

         if (0 != lCleanupRetVal)
         {
            printf("ACF_Process_APU::Wait() -> error detected during Cleanup()\n");
            lRetVal = ACF_ERROR;
         }
         else //Cleanup is OK; check for mApuProgramRetVal errors
         {
            switch (mApuProgramRetVal)
            {
               case ACF_SUCCESS:
                  //apu program execution completed without error
                  break;
               case ACF_HW_RESOURCE_ERROR:
                  printf("ACF_Process_APU::Wait() -> apu program runtime error (hardware resource)\n");
                  lRetVal = ACF_HW_RESOURCE_ERROR;
                  break;
               case ACF_MEMORY_ALLOCATION_ERROR:
                  printf("ACF_Process_APU::Wait() -> apu program runtime error (memory allocation)\n");
                  lRetVal = ACF_MEMORY_ALLOCATION_ERROR;
                  break;
               default:
                  printf("ACF_Process_APU::Wait() -> apu program runtime error (unknown error code [%d])\n", mApuProgramRetVal);
                  lRetVal = ACF_ERROR;
                  break;
            }

            #if (ACF_DEBUG_DUMP == 1)
            SanityCheck_ProgramParams();
            SanityCheck_ProgramMem_Dma();
            DebugDump();
            #endif
         }
      }

      ACF_HOST_PROBE_LVL2(24);

      //release HW resources
      if (0 != DeallocateHwResources())
      {
         printf("ACF_Process_APU::Wait() -> HW resource deallocation failed\n");
         lRetVal = ACF_ERROR;
      }

      ACF_HOST_PROBE_LVL2(25);

      mProcessStartedFlag = 0;
      mpUserDefinedCallback = 0; //clear the user-defined callback
   }
   else //program execution never started
   {
      printf("ACF_Process_APU::Wait() -> process was never started (i.e. nothing to wait for)\n");
      lRetVal = ACF_ERROR;
   }

   ACF_HOST_PROBE_LVL1(26);

   return lRetVal;
}

AcfProfilingInfo ACF_Process_APU::RetAcfProfilingInfo()
{
   AcfProfilingInfo lProfInfo;

#if (ACF_HOST_PROFILING_LVL > 0)
   lProfInfo.host_start     = (int32_t)CONVERT_TICKS_TO_US(mProbeArray[15]-mProbeArray[0]);
   lProfInfo.host_wait      = (int32_t)CONVERT_TICKS_TO_US(mProbeArray[26]-mProbeArray[20]);
#else
   lProfInfo.host_start     = 0;
   lProfInfo.host_wait      = 0;
#endif
   lProfInfo.apu_total      = (int32_t)(1000000*((double)mCycles_apu_total/APEX_CLOCK_FREQ));
   lProfInfo.apu_init       = (int32_t)(1000000*((double)mCycles_apu_init/APEX_CLOCK_FREQ));
   lProfInfo.apu_processing = (int32_t)(1000000*((double)mCycles_apu_processing/APEX_CLOCK_FREQ));
   lProfInfo.apu_idle       = (int32_t)(1000000*((double)mCycles_apu_idle/APEX_CLOCK_FREQ));
   lProfInfo.apu_misc       = lProfInfo.apu_total - (lProfInfo.apu_init + lProfInfo.apu_processing + lProfInfo.apu_idle);

   return lProfInfo;
}

int32_t ACF_Process_APU::Start(void (*lpCallback)(void* lpParam, int32_t* lpRetVal),
                               void* lpCallbackParam,
                               int32_t* lpCallbackRetVal)
{
   mpUserDefinedCallback = lpCallback;
   mpUserDefinedCallbackParam = lpCallbackParam;
   mpUserDefinedCallbackRetVal = lpCallbackRetVal;

   return Start();
}

void ACF_Process_APU::DumpHostProfilingInfoToStdout()
{
#if (ACF_HOST_PROFILING_LVL == 1)
   printf("*******************************************************\n");
   printf("LVL1 HOST profiling (ticks, usec, description):\n");
   printf("*******************************************************\n");
   printf("%8d, %6d, total Start() function execution time\n", (int)(mProbeArray[15]-mProbeArray[0]),  (int)CONVERT_TICKS_TO_US(mProbeArray[15]-mProbeArray[0]));
   printf("%8d, %6d, total Wait() function execution time\n",  (int)(mProbeArray[26]-mProbeArray[20]), (int)CONVERT_TICKS_TO_US(mProbeArray[26]-mProbeArray[20]));
#elif (ACF_HOST_PROFILING_LVL == 2)
   printf("*******************************************************\n");
   printf("LVL2 HOST profiling (ticks, usec, description):\n");
   printf("*******************************************************\n");
   printf("-------------------------------------------------------\n");
   printf("%d, %d, total Start() function execution time\n",              (int)(mProbeArray[15]-mProbeArray[0]),  (int)CONVERT_TICKS_TO_US(mProbeArray[15]-mProbeArray[0]));
   printf("-------------------------------------------------------\n");
   printf("   %8d, %6d, roi check\n",                                     (int)(mProbeArray[1] -mProbeArray[0]),  (int)CONVERT_TICKS_TO_US(mProbeArray[1]- mProbeArray[0]));
   printf("   %8d, %6d, scenario selection\n",                            (int)(mProbeArray[2] -mProbeArray[1]),  (int)CONVERT_TICKS_TO_US(mProbeArray[2]- mProbeArray[1]));
   printf("   %8d, %6d, misc\n",                                          (int)(mProbeArray[3] -mProbeArray[2]),  (int)CONVERT_TICKS_TO_US(mProbeArray[3]- mProbeArray[2]));
   printf("   %8d, %6d, generate program parameters\n",                   (int)(mProbeArray[4] -mProbeArray[3]),  (int)CONVERT_TICKS_TO_US(mProbeArray[4]- mProbeArray[3]));
   printf("   %8d, %6d, allocate hw resources\n",                         (int)(mProbeArray[5] -mProbeArray[4]),  (int)CONVERT_TICKS_TO_US(mProbeArray[5]- mProbeArray[4]));
   printf("   %8d, %6d, misc parameter init + interrupt cfg\n",           (int)(mProbeArray[6] -mProbeArray[5]),  (int)CONVERT_TICKS_TO_US(mProbeArray[6]- mProbeArray[5]));
   printf("   %8d, %6d, cmem if setup\n",                                 (int)(mProbeArray[7] -mProbeArray[6]),  (int)CONVERT_TICKS_TO_US(mProbeArray[7]- mProbeArray[6]));
   printf("   %8d, %6d, apu load dma transfer (%d bytes)\n",              (int)(mProbeArray[9] -mProbeArray[8]),  (int)CONVERT_TICKS_TO_US(mProbeArray[9]- mProbeArray[8]), mLoadPmemSize*4);
   printf("   %8d, %6d, apu enable + microkernel handshake\n",            (int)(mProbeArray[10]-mProbeArray[9]),  (int)CONVERT_TICKS_TO_US(mProbeArray[10]-mProbeArray[9]));
   //printf("   %8d, %6d, cache flush and invalidate\n",                    (int)(mProbeArray[11]-mProbeArray[10]), (int)CONVERT_TICKS_TO_US(mProbeArray[11]-mProbeArray[10]));
   printf("   %8d, %6d, interrupt cfg\n",                                 (int)(mProbeArray[12]-mProbeArray[11]), (int)CONVERT_TICKS_TO_US(mProbeArray[12]-mProbeArray[11]));
   printf("   %8d, %6d, apumk send cmd\n",                                (int)(mProbeArray[13]-mProbeArray[12]), (int)CONVERT_TICKS_TO_US(mProbeArray[13]-mProbeArray[12]));
   printf("   %8d, %6d, apumk tx (i.e. kick program)\n",                  (int)(mProbeArray[15]-mProbeArray[14]), (int)CONVERT_TICKS_TO_US(mProbeArray[15]-mProbeArray[14]));
   printf("-------------------------------------------------------\n");
   printf("%d, %d, total Wait() function execution time\n",               (int)(mProbeArray[26]-mProbeArray[20]), (int)CONVERT_TICKS_TO_US(mProbeArray[26]-mProbeArray[20]));
   printf("-------------------------------------------------------\n");
   printf("   %8d, %6d, wait for process to complete\n",                  (int)(mProbeArray[22]-mProbeArray[21]), (int)CONVERT_TICKS_TO_US(mProbeArray[22]-mProbeArray[21]));
   printf("   %8d, %6d, cleanup (i.e. apumk rx, apu disable, apu prof)\n",(int)(mProbeArray[23]-mProbeArray[22]), (int)CONVERT_TICKS_TO_US(mProbeArray[23]-mProbeArray[22]));
   printf("   %8d, %6d, deallocate hw resources\n",                       (int)(mProbeArray[25]-mProbeArray[24]), (int)CONVERT_TICKS_TO_US(mProbeArray[25]-mProbeArray[24]));
#else
   printf("**********************************************************************\n");
   printf("HOST profiling is disabled!\n");
   printf("--> to enable it modify ACF_HOST_PROFILING_LVL in acf_process_apu.cpp)\n");
   printf("**********************************************************************\n");
#endif
}

void ACF_Process_APU::DumpHostProfilingInfoToStdout_CSV(int32_t lHeaderFlag)
{
   if (lHeaderFlag)
   {
      printf("ticks,usec,description\n");
   }

#if (ACF_HOST_PROFILING_LVL == 1)
   printf("%d,%d,total Start() function execution time\n", (int)(mProbeArray[15]-mProbeArray[0]),  (int)CONVERT_TICKS_TO_US(mProbeArray[15]-mProbeArray[0]));
   printf("%d,%d,total Wait() function execution time\n",  (int)(mProbeArray[26]-mProbeArray[20]), (int)CONVERT_TICKS_TO_US(mProbeArray[26]-mProbeArray[20]));
#elif (ACF_HOST_PROFILING_LVL == 2)
   printf("%d,%d,total Start() function execution time\n",         (int)(mProbeArray[15]-mProbeArray[0]),  (int)CONVERT_TICKS_TO_US(mProbeArray[15]-mProbeArray[0]));
   printf("%d,%d,roi check\n",                                     (int)(mProbeArray[1] -mProbeArray[0]),  (int)CONVERT_TICKS_TO_US(mProbeArray[1]- mProbeArray[0]));
   printf("%d,%d,scenario selection\n",                            (int)(mProbeArray[2] -mProbeArray[1]),  (int)CONVERT_TICKS_TO_US(mProbeArray[2]- mProbeArray[1]));
   printf("%d,%d,misc\n",                                          (int)(mProbeArray[3] -mProbeArray[2]),  (int)CONVERT_TICKS_TO_US(mProbeArray[3]- mProbeArray[2]));
   printf("%d,%d,generate program parameters\n",                   (int)(mProbeArray[4] -mProbeArray[3]),  (int)CONVERT_TICKS_TO_US(mProbeArray[4]- mProbeArray[3]));
   printf("%d,%d,allocate hw resources\n",                         (int)(mProbeArray[5] -mProbeArray[4]),  (int)CONVERT_TICKS_TO_US(mProbeArray[5]- mProbeArray[4]));
   printf("%d,%d,misc parameter init + interrupt cfg\n",           (int)(mProbeArray[6] -mProbeArray[5]),  (int)CONVERT_TICKS_TO_US(mProbeArray[6]- mProbeArray[5]));
   printf("%d,%d,cmem if setup\n",                                 (int)(mProbeArray[7] -mProbeArray[6]),  (int)CONVERT_TICKS_TO_US(mProbeArray[7]- mProbeArray[6]));
   printf("%d,%d,apu load dma transfer (%d bytes)\n",              (int)(mProbeArray[9] -mProbeArray[8]),  (int)CONVERT_TICKS_TO_US(mProbeArray[9]- mProbeArray[8]), mLoadPmemSize*4);
   printf("%d,%d,apu enable + microkernel handshake\n",            (int)(mProbeArray[10]-mProbeArray[9]),  (int)CONVERT_TICKS_TO_US(mProbeArray[10]-mProbeArray[9]));
   //printf("%d,%d,cache flush and invalidate\n",                    (int)(mProbeArray[11]-mProbeArray[10]), (int)CONVERT_TICKS_TO_US(mProbeArray[11]-mProbeArray[10]));
   printf("%d,%d,interrupt cfg\n",                                 (int)(mProbeArray[12]-mProbeArray[11]), (int)CONVERT_TICKS_TO_US(mProbeArray[12]-mProbeArray[11]));
   printf("%d,%d,apumk send cmd\n",                                (int)(mProbeArray[13]-mProbeArray[12]), (int)CONVERT_TICKS_TO_US(mProbeArray[13]-mProbeArray[12]));
   printf("%d,%d,apumk tx (i.e. kick program)\n",                  (int)(mProbeArray[15]-mProbeArray[14]), (int)CONVERT_TICKS_TO_US(mProbeArray[15]-mProbeArray[14]));
   printf("%d,%d,total Wait() function execution time\n",          (int)(mProbeArray[26]-mProbeArray[20]), (int)CONVERT_TICKS_TO_US(mProbeArray[26]-mProbeArray[20]));
   printf("%d,%d,wait for process to complete\n",                  (int)(mProbeArray[22]-mProbeArray[21]), (int)CONVERT_TICKS_TO_US(mProbeArray[22]-mProbeArray[21]));
   printf("%d,%d,cleanup (i.e. apumk rx, apu disable, apu prof)\n",(int)(mProbeArray[23]-mProbeArray[22]), (int)CONVERT_TICKS_TO_US(mProbeArray[23]-mProbeArray[22]));
   printf("%d,%d,deallocate hw resources\n",                       (int)(mProbeArray[25]-mProbeArray[24]), (int)CONVERT_TICKS_TO_US(mProbeArray[25]-mProbeArray[24]));
#else
   printf("**********************************************************************\n");
   printf("HOST profiling is disabled!\n");
   printf("--> to enable it modify ACF_HOST_PROFILING_LVL in acf_process_apu.cpp)\n");
   printf("**********************************************************************\n");
#endif
}

void ACF_Process_APU::DumpApuProfilingInfoToStdout()
{
   int32_t lRemainingOverhead = mCycles_apu_total - (mCycles_apu_init + mCycles_apu_processing + mCycles_apu_idle);

   if (mCycles_apu_total != 0)
   {
      printf("*******************************************************\n");
      printf("APU profiling (cycles, usec, description):\n");
      printf("*******************************************************\n");
      printf("-------------------------------------------------------\n");
      printf("%d, %d, total apu process execution time\n",                                       (int)mCycles_apu_total,      (int)(1000000*((double)mCycles_apu_total/APEX_CLOCK_FREQ)));
      printf("-------------------------------------------------------\n");
      printf("    %8d, %6d, initialization\n",                                                   (int)mCycles_apu_init,       (int)(1000000*((double)mCycles_apu_init/APEX_CLOCK_FREQ)));
      printf("    %8d, %6d, processing (i.e. kernel execution + padding + cb management)\n",     (int)mCycles_apu_processing, (int)(1000000*((double)mCycles_apu_processing/APEX_CLOCK_FREQ)));
      if (mCycles_apu_kernel != 0)
      printf("        %8d, %6d, kernel execution\n",                                             (int)mCycles_apu_kernel,     (int)(1000000*((double)mCycles_apu_kernel/APEX_CLOCK_FREQ)));
      if (mCycles_apu_padPlusCb != 0)
      printf("        %8d, %6d, padding + circular buffer management\n",                         (int)mCycles_apu_padPlusCb,  (int)(1000000*((double)mCycles_apu_padPlusCb/APEX_CLOCK_FREQ)));
      printf("    %8d, %6d, idle (i.e. waiting for data transfer to complete)\n",                (int)mCycles_apu_idle,       (int)(1000000*((double)mCycles_apu_idle/APEX_CLOCK_FREQ)));
      printf("    %8d, %6d, remaining overhead (i.e. control + descriptor management + misc)\n", (int)lRemainingOverhead,     (int)(1000000*((double)lRemainingOverhead/APEX_CLOCK_FREQ)));
   }
   else
   {
      printf("**************************\n");
      printf("APU profiling is disabled!\n");
      printf("**************************\n");
   }

   printf("-------------------------------------------------------\n");
   printf("Additional information:\n");
   printf("-------------------------------------------------------\n");
   printf("APU load size (in bytes): %d\n", mLoadPmemSize*4);
   printf("Base chunk size (in elements): %dx%d\n", mpSelectedScenario->baseChunkWidth, mpSelectedScenario->baseChunkHeight);
}

void ACF_Process_APU::DumpApuProfilingInfoToStdout_CSV(int32_t lHeaderFlag)
{
   if (lHeaderFlag)
   {
      printf("cycles,usec,description\n");
   }

   int32_t lRemainingOverhead = mCycles_apu_total - (mCycles_apu_init + mCycles_apu_processing + mCycles_apu_idle);

   if (mCycles_apu_total != 0)
   {
      printf("%d,%d,total apu process execution time\n",                                 (int)mCycles_apu_total,      (int)(1000000*((double)mCycles_apu_total/APEX_CLOCK_FREQ)));
      printf("%d,%d,initialization\n",                                                   (int)mCycles_apu_init,       (int)(1000000*((double)mCycles_apu_init/APEX_CLOCK_FREQ)));
      printf("%d,%d,processing (i.e. kernel execution + padding + cb management)\n",     (int)mCycles_apu_processing, (int)(1000000*((double)mCycles_apu_processing/APEX_CLOCK_FREQ)));
      if (mCycles_apu_kernel != 0)
      printf("%d,%d,kernel execution\n",                                                 (int)mCycles_apu_kernel,     (int)(1000000*((double)mCycles_apu_kernel/APEX_CLOCK_FREQ)));
      if (mCycles_apu_padPlusCb != 0)
      printf("%d,%d,padding + circular buffer management\n",                             (int)mCycles_apu_padPlusCb,  (int)(1000000*((double)mCycles_apu_padPlusCb/APEX_CLOCK_FREQ)));
      printf("%d,%d,idle (i.e. waiting for data transfer to complete)\n",                (int)mCycles_apu_idle,       (int)(1000000*((double)mCycles_apu_idle/APEX_CLOCK_FREQ)));
      printf("%d,%d,remaining overhead (i.e. control + descriptor management + misc)\n", (int)lRemainingOverhead,     (int)(1000000*((double)lRemainingOverhead/APEX_CLOCK_FREQ)));
   }
   else
   {
      printf("**************************\n");
      printf("APU profiling is disabled!\n");
      printf("**************************\n");
   }
}

int32_t ACF_Process_APU::ApexInitSanityCheck()
{
   int32_t lRetVal = ACF_SUCCESS;

   //perform a sanity check to ensure APEX_Init() was was called
   if (0 == RetApexInitFlag())
   {
      printf("ACF_Process_APU::ApexInitSanityCheck() -> APEX_Init() was never called in this scope\n");
      lRetVal = ACF_APEX_INIT_ERROR;
   }

   return lRetVal;
}

void ACF_Process_APU::SetApuLoadInfo(const LOAD_SEGMENT_t* lLoadSegments,
                                     const SEG_MEM_TYPE* lpLoadPmem, const int32_t lLoadPmemSizeInWords,
                                     const SEG_MEM_TYPE* lpLoadDmem, const int32_t lLoadDmemSizeInBytes,
                                     const SEG_MEM_TYPE* lpLoadCmem, const int32_t lLoadCmemSize)
{
   mLoadSegments = lLoadSegments;
   mpLoadPmem    = lpLoadPmem;
   mLoadPmemSize = (lLoadPmemSizeInWords+3) & 0xFFFFFFFC; //round up to 128-bit
   mpLoadDmem    = lpLoadDmem;
   mLoadDmemSize = ((lLoadDmemSizeInBytes+15) & 0xFFFFFFF0)>>2; //round up to 128-bit and convert to words
   mpLoadCmem    = lpLoadCmem;
   mLoadCmemSize = lLoadCmemSize; //this one is currently always 0
}

int32_t ACF_Process_APU::NonParametricInitialization()
{
   int32_t lRetVal = 0;

   lRetVal |= CopyApuLoad();
   lRetVal |= InitKernelManager();

   //create semaphore for interrupt-based wait
   int32_t lRes = OAL_SemaphoreCreate(&mWaitSemaphore, RetProcessIdentifier().c_str(), OAL_SEMAPHORE_COUNTING, 0);
   if (OAL_SUCCESS != lRes)
      lRetVal |= 1;

   return lRetVal;
}

int32_t ACF_Process_APU::CopyApuLoad()
{
   int32_t lRetVal = apu_hal_CopyLoadToOalMemory(mpLoadPmem, mLoadPmemSize,
                                                 mpLoadDmem, mLoadDmemSize,
                                                 mpLoadCmem, mLoadCmemSize,
                                                 &mpPmemLoadOal,
                                                 &mpDmemLoadOal,
                                                 &mpCmemLoadOal);
   return lRetVal;
}

int32_t ACF_Process_APU::InitKernelManager()
{
   int32_t lRetVal = ACF_SUCCESS;

   KernelManager lKernelManager;

   if (0 == lKernelManager.InitLoadKernelDB(0, mLoadSegments)) //first param is 'apuid' but it is not used ...
   {
      //the name of the apu program is the same as the process identifier
      if (lKernelManager.ReturnKernelID((int*)&mApuProgFuncPtr, RetProcessIdentifier().c_str()) != -1)
      {
         //OK
      }
      else
      {
         printf("ACF_Process_APU::InitKernelManager() -> '%s' could not be found in the APU load\n", RetProcessIdentifier().c_str());
         lRetVal = ACF_ERROR;
      }
   }
   else
   {
      lRetVal = ACF_ERROR;
   }

   return lRetVal;
}

void ACF_Process_APU::AddPort(std::string lPortIdentifier,
                              icp::DATATYPE lE0DataType,
                              int32_t lE0x, int32_t lE0y,
                              int32_t lChunkWidth, int32_t lChunkHeight,
                              int32_t lInputOutput,
                              int32_t lCmemDmem,
                              int32_t lNonstaticStatic,
                              int32_t lDirectIndirect,
                              int32_t lNonfixedFixed,
                              int32_t lRegFifo,
                              int32_t lLmIndex,
                              int32_t lSDInfoN,
                              int32_t lSDInfoS,
                              int32_t lSDInfoE,
                              int32_t lSDInfoW,
                              int32_t lVerDepOverlapFlag)
{
   ACF_Process::AddPort(lPortIdentifier, lE0DataType, lE0x, lE0y,
                        lChunkWidth, lChunkHeight,
                        lInputOutput,
                        lNonstaticStatic,
                        lDirectIndirect,
                        lNonfixedFixed,
                        lRegFifo,
                        lLmIndex,
                        lSDInfoN,
                        lSDInfoS,
                        lSDInfoE,
                        lSDInfoW,
                        lVerDepOverlapFlag);

   ACF_Process_PortInfo_APU lPortInfoApu;
   lPortInfoApu.mPortIdentifier = lPortIdentifier;
   lPortInfoApu.mCmemDmem = lCmemDmem;
   mPortInfoApuVec.push_back(lPortInfoApu);
}

int32_t ACF_Process_APU::DetectHwVersion()
{
   int32_t lRetVal = 0;

   mHwVersion = global_hal_RetHwVersion(mApexId);
   if (mHwVersion != 0x321 && mHwVersion != 0x642)
   {
      printf("ACF_Process_APU::DetectHwResources() -> unknown HW version detected (%d)\n", mHwVersion);
      lRetVal = 1;
   }

   return lRetVal;
}

int32_t ACF_Process_APU::SelectApuConfiguration(ACF_APU_CFG lApuConfig, int32_t lApexId)
{
   int32_t lRetVal = ACF_SUCCESS;

   //this function accesses APEX HW - check that APEX_Init has been called
   lRetVal = ApexInitSanityCheck();
   if (lRetVal != ACF_SUCCESS)
   {
      mErrorState = 1; //flag internal error state
      return lRetVal;
   }

   //ensure lApexId refers to a valid APEX instance (must be 0 or 1 on s32v234)
   //TODO: the number of APEXs available on the chip should come from some global/central HW description instead
   //      of hard-coding it in this manner
   if ((lApexId >= 0) && (lApexId < 2))
   {
      mApexId = lApexId;
   }
   else
   {
      printf("ACF_Process_APU::SelectApuConfiguration() -> lApexId=%d refers to an invalid APEX instance; select 0 or 1\n", lApexId);
      lRetVal = ACF_ERROR;
      return lRetVal;
   }

   if (lApuConfig != mApuCfg)
   {
      mApuCfg = lApuConfig;

      //if the apu configuration changes, scenario selection must be revisited
      mpSelectedScenario = 0;
   }

   if (Initialized()) //if the process was successfully initialized
   {
      memset((void*)&mAcfResInfo, 0, sizeof(acf_res_info));

      if (0 == DetectHwVersion())
      {
         if (0x321 == mHwVersion)
         {
            switch (lApuConfig)
            {
            case ACF_APU_CFG__DEFAULT:
            case ACF_APU_CFG__APU_0_CU_0_31_SMEM_0_1:
               mApuId = 0;
               mCuArrayWidth = 32;
               mSmemBaseAddrOffset = 0;
               CfgResSet_321_ALL(&mAcfResInfo);

               InitApexResReq(mResReqArray[0], mApexId, RES__APEX__APU,   0);
               InitApexResReq(mResReqArray[1], mApexId, RES__APEX__CU_32, 0);
               InitApexResReq(mResReqArray[2], mApexId, RES__SMEM_64K,    0);
               mNumResReq = 3;
               break;

            default:
               printf("ACF_Process_APU::SelectApuConfiguration() -> invalid 321 APU configuration detected\n");
               lRetVal = ACF_ERROR;
               break;
            }
         }
         else if (0x642 == mHwVersion)
         {
            switch (lApuConfig)
            {
            case ACF_APU_CFG__DEFAULT:
            case ACF_APU_CFG__APU_0_CU_0_63_SMEM_0_3:
               mApuId = 0;
               mCuArrayWidth = 64;
               mSmemBaseAddrOffset = 0;
               CfgResSet_642_ALL(&mAcfResInfo);

               InitApexResReq(mResReqArray[0], mApexId, RES__APEX__APU,   0);
               InitApexResReq(mResReqArray[1], mApexId, RES__APEX__CU_32, 0);
               InitApexResReq(mResReqArray[2], mApexId, RES__APEX__CU_32, 1);
               InitApexResReq(mResReqArray[3], mApexId, RES__SMEM_64K,    0);
               InitApexResReq(mResReqArray[4], mApexId, RES__SMEM_64K,    1);
               mNumResReq = 5;
               break;

            case ACF_APU_CFG__APU_0_CU_0_31_SMEM_0_1:
               mApuId = 0;
               mCuArrayWidth = 32;
               mSmemBaseAddrOffset = 0;
               CfgResSet_642_HALF_APU0(&mAcfResInfo);

               InitApexResReq(mResReqArray[0], mApexId, RES__APEX__APU,   0);
               InitApexResReq(mResReqArray[1], mApexId, RES__APEX__CU_32, 0);
               InitApexResReq(mResReqArray[2], mApexId, RES__SMEM_64K,    0);
               mNumResReq = 3;
               break;

            case ACF_APU_CFG__APU_1_CU_32_63_SMEM_2_3:
               mApuId = 1;
               mCuArrayWidth = 32;
               mSmemBaseAddrOffset = (1024*64);
               CfgResSet_642_HALF_APU1(&mAcfResInfo);

               InitApexResReq(mResReqArray[0], mApexId, RES__APEX__APU,   1);
               InitApexResReq(mResReqArray[1], mApexId, RES__APEX__CU_32, 1);
               InitApexResReq(mResReqArray[2], mApexId, RES__SMEM_64K,    1);
               mNumResReq = 3;
               break;

            default:
               printf("ACF_Process_APU::SelectApuConfiguration() -> invalid 642 APU configuration detected\n");
               lRetVal = ACF_ERROR;
               break;
            }
         }

         if (832 != global_hal_RetRtlBuildNumber(mApexId)) //if RTL build is NOT cut 2.0
         {
            //CLOVER-389 workaround:
            //in the case where the APEX is configured for multi-apu operation, all mem-to-mem dma writes directly to the first 64K of SMEM and first 128K of CMEM must be single beat!!
            mClover389Flag = 0;
            if ((0x642 == mHwVersion) && (ACF_APU_CFG__APU_0_CU_0_31_SMEM_0_1 == mApuCfg))
               mClover389Flag = 1;
         }

         if (0 == lRetVal)
         {
            if (0 == DetectAvailApexMemory())
            {
               if (0 != apu_hal_GenLoadLL(mApexId, mApuId, mLoadSegments, mpLoadPmem, mpLoadDmem, mpLoadCmem,
                                          (mpPmemLoadOal != 0) ? (uint32_t)(uintptr_t)OAL_MemoryReturnAddress(mpPmemLoadOal, ACCESS_PHY) : 0,
                                          (mpDmemLoadOal != 0) ? (uint32_t)(uintptr_t)OAL_MemoryReturnAddress(mpDmemLoadOal, ACCESS_PHY) : 0,
                                          (mpCmemLoadOal != 0) ? (uint32_t)(uintptr_t)OAL_MemoryReturnAddress(mpCmemLoadOal, ACCESS_PHY) : 0,
                                          mSmemBaseAddrOffset + mPmemBaseAddrOffset, //pmem offset
                                          mSmemBaseAddrOffset + mDmemBaseAddrOffset, //dmem offset
                                          mDmemSizeInBytes,
                                          Translate_AcfApuCfg_CmemIfApuCfg(mApuCfg, mHwVersion),
                                          &mpLoadSegmentsLLOal,
                                          mClover389Flag))
               {
                  mErrorState = 1;
                  lRetVal = ACF_ERROR;
               }
            }
            else
            {
               lRetVal = ACF_ERROR;
            }
         }
      }
      else
      {
         lRetVal = ACF_HW_DETECTION_ERROR;
      }
   }
   else //process was never never successfully initialized
   {
      printf("ACF_Process_APU::SelectApuConfiguration() -> process was never successfully initialized\n");
      lRetVal = ACF_ERROR;
   }

   return lRetVal;
}

int32_t ACF_Process_APU::DetectAvailApexMemory()
{
   int lRetVal = 0;

   //Based on the load determine CMEM/DMEM available to the scenario (for 'dynamic' ACF heap)
   //Note that memory size calculations (specifically related to SMEM) depend on the APU configuration

   int32_t lCmemReq  = 0;
   int32_t lDmemReq  = 0;
   int32_t lPmemReq  = 0;
   int32_t lSmemSize = 0;
   int32_t lCmemSize = 0;
   int32_t lTmp      = 0;

   if (0 == RetApuMemSizes(Translate_AcfApuCfg_CmemIfApuCfg(mApuCfg, mHwVersion), &lSmemSize, &lCmemSize))
   {
      apu_hal_QueryLoad_MEM_REQ(mLoadSegments, &lCmemReq, &lDmemReq, &lPmemReq);

      //PMEM offset/size calculation (PMEM will reside at the end of the contiguous SMEM region and the calculated offset
      //is relative to the start of the contiguous SMEM region)

      if (832 != global_hal_RetRtlBuildNumber(mApexId)) //if RTL build is NOT cut 2.0
      {
         //WORKAROUND FOR CLOVER-386
         //for the purpose of this calculation, assume PMEM will occupy 'entire' SMEM banks to ensure there is no overlap between
         //the SMEM bank used for DMEM and the SMEM bank used for PMEM; round up required PMEM to multiple of SMEM_BANK_SIZE
         const int32_t SMEM_BANK_SIZE = (1024*32); //32K
         mPmemSizeInBytes = lPmemReq;
         if (mPmemSizeInBytes%SMEM_BANK_SIZE != 0)
            mPmemSizeInBytes = ((lPmemReq/SMEM_BANK_SIZE)+1)*SMEM_BANK_SIZE;
      }
      else
      {
         //ensure 16-byte alignment of PMEM region in SMEM
         lTmp = ((lPmemReq&0xF) == 0) ? 0 : (16-(lPmemReq&0xF));
         mPmemSizeInBytes = lPmemReq + lTmp;
      }

      mDmemBaseAddrOffset = 0;                            //DMEM set to reside at the start of the allocated SMEM region
      mPmemBaseAddrOffset = lSmemSize - mPmemSizeInBytes; //PMEM set to reside at the end of the allocated SMEM region
      mDmemSizeInBytes = lSmemSize - mPmemSizeInBytes;    //DMEM size = all allocated SMEM that doesn't belong to PMEM

      //DEBUGGING: swap order so PMEM occurs at start of the allocated SMEM region and DMEM occurs after it (FOR DEBUGGING!!!)
      //mPmemBaseAddrOffset = 0;                            //PMEM set to reside at the start of the allocated SMEM region
      //mDmemBaseAddrOffset = mPmemSizeInBytes;             //DMEM set to reside just after PMEM

      if (mPmemSizeInBytes <= (lSmemSize - lDmemReq))
      {
         //create dmem/cmem heaps with remainder of SMEM region (between linked mapped DMEM at the top and PMEM at the bottom)

         //DMEM HEAP
         lTmp = ((lDmemReq&0xF) == 0) ? 0 : (16-(lDmemReq&0xF)); //start of dmem heap should be 16-byte aligned
         mDmemHeapBaseAddrOffset = lDmemReq + lTmp; //assume DMEM heap follows 'blob' of DMEM reserved by the linker
         mDmemHeapSizeInBytes = lSmemSize - (lDmemReq + lTmp) - mPmemSizeInBytes;

         //CMEM HEAP
         lTmp = ((lCmemReq&0x3) == 0) ? 0 : (4-(lCmemReq&0x3)); //start of cmem heap should be 4-byte aligned
         mCmemHeapBaseAddrOffset = lCmemReq + lTmp; //assume CMEM heap follows 'blob' of CMEM reserved by the linker
         mCmemHeapSizeInBytes = lCmemSize - (lCmemReq + lTmp);
      }
      else
      {
         printf("ACF_Process_APU::DetectAvailApexMemory() -> insufficient program memory space for %s (%d bytes required).\n", RetProcessIdentifier().c_str(), lPmemReq);
         lRetVal = 1;
      }

   #if 0
         printf("CMEM HEAP: OFFSET = 0x%08X | SIZE = %d\n", mCmemHeapBaseAddrOffset, mCmemHeapSizeInBytes);
         printf("SMEM:      OFFSET = 0x%08X | SIZE = %d (first %d bytes reserved by linker)\n", mSmemBaseAddrOffset, lSmemSize, lDmemReq);
         printf("   PMEM: OFFSET = 0x%08X | SIZE = %d\n", mPmemBaseAddrOffset, mPmemSizeInBytes);
         printf("   DMEM: OFFSET = 0x%08X | SIZE = %d\n", mDmemBaseAddrOffset, mDmemSizeInBytes);
         printf("      DMEM STATIC BLOB: OFFSET = 0x00000000 | SIZE = %d\n", lDmemReq);
         printf("      DMEM HEAP:        OFFSET = 0x%08X | SIZE = %d\n", mDmemHeapBaseAddrOffset, mDmemHeapSizeInBytes);
         printf("\n");
   #endif

   }
   else
   {
      printf("ACF_Process_APU::DetectAvailApexMemory() -> RetApuMemSizes(...) failed\n");
      lRetVal = 1;
   }

   return lRetVal;
}

int32_t VerifyROI(int32_t lWorstCaseDataComingFromSource,
                  int32_t lDataAvailFromSource,
                  int32_t lDepInfo)
{
   //the purpose of this function is to flag unsupported ROIs given the already calculated 'lWorstCaseDataComingFromSource' values
   //(i.e. trying to identify the unsupported 'crop' use case)

   int32_t lRetVal = 0;
   int32_t lDataComingFromSource = 0;

   if (lDepInfo >= lDataAvailFromSource)
      lDataComingFromSource = lDataAvailFromSource;
   else //(lDepInfo < lDataAvailFromSource)
      lDataComingFromSource = lDepInfo;

   if (lDataComingFromSource != lWorstCaseDataComingFromSource)
   {
      if (lDataComingFromSource > lWorstCaseDataComingFromSource)
         lRetVal = 1;
      else if (lDataComingFromSource != lDepInfo)
         lRetVal = 1;
   }

   return lRetVal;
}

//determine worst case additional 'from source' transfer requirements for each direction (for ROI)
//TODO: should probably be in ACF_Process - requires some cleanup related to CMEM/DMEM attribute info first
int32_t ACF_Process_APU::DetWorstCaseRoiInfo()
{
   int32_t lRetVal = 0;

   mRoiInfoL = 0;
   mRoiInfoR = 0;
   mRoiInfoT = 0;
   mRoiInfoB = 0;

   int32_t lTmp, lDepDataAvailFromSource, lDepInfo;

   for (int32_t i=0; i<(int32_t)mPortInfoVec.size(); i++)
   {
      if (mPortInfoVec[i].IsNonStatic() && mPortInfoVec[i].IsInput() && mPortInfoApuVec[i].IsCmem())
      {
         //TOP
         lDepDataAvailFromSource = mPortInfoVec[i].mDataDesc.RetRoiInfoT();
         lDepInfo = mPortInfoVec[i].mSDInfoN;
         lTmp = lDepDataAvailFromSource;
         if (lDepDataAvailFromSource >= lDepInfo)
            lTmp = lDepInfo;
         if (lTmp > mRoiInfoT)
            mRoiInfoT = lTmp;

         //BOTTOM
         lDepDataAvailFromSource = mPortInfoVec[i].mDataDesc.RetRoiInfoB();
         lDepInfo = mPortInfoVec[i].mSDInfoS;
         lTmp = lDepDataAvailFromSource;
         if (lDepDataAvailFromSource >= lDepInfo)
            lTmp = lDepInfo;
         if (lTmp > mRoiInfoB)
            mRoiInfoB = lTmp;

         //LEFT
         lDepDataAvailFromSource = mPortInfoVec[i].mDataDesc.RetRoiInfoL();
         lDepInfo = mPortInfoVec[i].mSDInfoW;
         lTmp = lDepDataAvailFromSource;
         if (lDepDataAvailFromSource >= lDepInfo)
            lTmp = lDepInfo;
         if (lTmp > mRoiInfoL)
            mRoiInfoL = lTmp;

         //RIGHT
         lDepDataAvailFromSource = mPortInfoVec[i].mDataDesc.RetRoiInfoR();
         lDepInfo = mPortInfoVec[i].mSDInfoE;
         lTmp = lDepDataAvailFromSource;
         if (lDepDataAvailFromSource >= lDepInfo)
            lTmp = lDepInfo;
         if (lTmp > mRoiInfoR)
            mRoiInfoR = lTmp;
      }
   }

   //VERIFY THAT ROI SCENARIO IS SUPPORTED

   for (int32_t i=0; i<(int32_t)mPortInfoVec.size(); i++)
   {
      if (mPortInfoVec[i].IsNonStatic() && mPortInfoVec[i].IsInput() && mPortInfoApuVec[i].IsCmem())
      {
         lRetVal |= VerifyROI(mRoiInfoT, mPortInfoVec[i].mDataDesc.RetRoiInfoT(), mPortInfoVec[i].mSDInfoN);
         lRetVal |= VerifyROI(mRoiInfoB, mPortInfoVec[i].mDataDesc.RetRoiInfoB(), mPortInfoVec[i].mSDInfoS);
         lRetVal |= VerifyROI(mRoiInfoL, mPortInfoVec[i].mDataDesc.RetRoiInfoL(), mPortInfoVec[i].mSDInfoW);
         lRetVal |= VerifyROI(mRoiInfoR, mPortInfoVec[i].mDataDesc.RetRoiInfoR(), mPortInfoVec[i].mSDInfoE);

         if (lRetVal)
         {
            printf("ACF_Process_APU::DetWorstCaseRoiInfo() -> multiple ROIs have been specified that are not compatible\n");
            break;
         }
      }
   }

   return lRetVal;
}

#if (ACF_DEBUG_DUMP == 1)

#include <sstream>
void mcdma_hal_memcpy(int apexID, int ChannelN, uint32_t dest, uint32_t src, uint32_t count, DMA_BURST_SIZE burstsize, DMA_BURST_BEAT_SIZE wordsize);
//#include "GDC_OAL_Semaphore.hpp"
//extern GDC_OAL_SEMAPHORE gsApuEnableSemaphore[2]; //semaphore to protect apu enable/disable (requires read-modify-write)

int32_t ACF_Process_APU::SanityCheck_ProgramMem(volatile uint32_t* lpBufferToCompareWithGolden)
{
   int32_t lErrorFlag = 0;

   //GDC_OAL_SemaphoreObtain(gsApuEnableSemaphore[mApexId], 0xFFFFFFFF);

   //printf("IN:%d,%d OUT:%d,%d SMEMOFF=%d PMEMOFF=%d APUID=%d\n",
   //      mAcfResInfo.dmaChIn[0], mAcfResInfo.dmaChIn[1], mAcfResInfo.dmaChOut[0], mAcfResInfo.dmaChOut[1], mSmemBaseAddrOffset, mPmemBaseAddrOffset, mAcfResInfo.apuId);

   volatile uint32_t* lpPmemFromSmem = lpBufferToCompareWithGolden;
   uint32_t* lpPmemGoldenRef = (uint32_t*)mpLoadPmem;

   int32_t lCount = 0;
   int32_t lBeg   = 0;
   //uint32_t w0 = 0;
   //uint32_t w1 = 0;
   //uint32_t w2 = 0;
   //uint32_t w3 = 0;

   for (int i=0; i<mLoadPmemSize; i++)
   {
      if (lpPmemFromSmem[mLoadPmemSize-1-i] != lpPmemGoldenRef[mLoadPmemSize-1-i])
      {
         if (0 == lCount)
         {
            lBeg = mLoadPmemSize-1-i;
            //w0 = lpPmemFromSmem[i+0];
            //w1 = lpPmemFromSmem[i+1];
            //w2 = lpPmemFromSmem[i+2];
            //w3 = lpPmemFromSmem[i+3];
         }

         lCount++;
      }
   }

   if (lCount > 0)
   {
      printf("SanityCheck_ProgramMem lCount=%d lBeg=%d (apex=%d apuid=%d)\n", lCount, lBeg, mApexId, mApuId);
      lCount = 0;
      for (int i=0; i<mLoadPmemSize; i++)
      {
         int32_t lIdx = mLoadPmemSize-1-i;
         if (lpPmemFromSmem[lIdx] != lpPmemGoldenRef[lIdx])
         {
            if (lCount < 8)
               printf("SanityCheck_ProgramMem (word %d of %d: GOOD=%08X BAD=%08X lCount=%d, backwards)!\n", lIdx, mLoadPmemSize, lpPmemGoldenRef[lIdx], lpPmemFromSmem[lIdx], lCount);
            lCount++;
         }
      }

      /*
      lCount = 0;
      for (int i=0; i<mLoadPmemSize; i++)
      {
         int32_t lIdx = i;
         if (lpPmemFromSmem[lIdx] != lpPmemGoldenRef[lIdx])
         {
            if (lCount < 8)
               printf("F: apu program memory sanity check failed (word %d of %d: GOOD=%08X BAD=%08X lCount=%d)!\n", lIdx, mLoadPmemSize, lpPmemGoldenRef[lIdx], lpPmemFromSmem[lIdx], lCount);
            lCount++;
         }
      }
      */

#if 0
      // Where did it go?!?
      if (w0 !=0)
      {
         // const uint32_t w0 = lpPmemGoldenRef[lBeg+0];
         // const uint32_t w1 = lpPmemGoldenRef[lBeg+1];
         // const uint32_t w2 = lpPmemGoldenRef[lBeg+2];
         // const uint32_t w3 = lpPmemGoldenRef[lBeg+3];

         volatile uint32_t* lpSMEM = (volatile uint32_t*)((intptr_t)ReturnVirtualHwPtr(mApexId, HW_REG_SMEM) + 0);

         for (int k=0; k<(128*1024/4)-3; ++k)
         {
            if (  (w0 == lpSMEM[k+0])
               && (w1 == lpSMEM[k+1])
               && (w2 == lpSMEM[k+2])
               && (w3 == lpSMEM[k+3]) )
            {
               printf("%6i %08X %08X %08X %08X \n", k, w0, w1, w2, w3);
            }
         }
      }
      // Where did it go?!?
      if (w0 !=0)
      {
         // const uint32_t w0 = lpPmemGoldenRef[lBeg+0];
         // const uint32_t w1 = lpPmemGoldenRef[lBeg+1];
         // const uint32_t w2 = lpPmemGoldenRef[lBeg+2];
         // const uint32_t w3 = lpPmemGoldenRef[lBeg+3];

         volatile uint32_t* lpSMEM = (volatile uint32_t*)((intptr_t)ReturnVirtualHwPtr(mApexId, HW_REG_SMEM) + 0);

         for (int k=0; k<(128*1024/4)-3; k+=4)
         {
            if (  (w0 == lpSMEM[k+0])
               && (w1 == lpSMEM[k+1])
               && (w2 == lpSMEM[k+2])
               && (w3 == lpSMEM[k+3]) )
            {
               printf("%6i %08X %08X %08X %08X \n", k, w0, w1, w2, w3);
            }
         }
      }
#endif
   }

   //GDC_OAL_SemaphoreRelease(gsApuEnableSemaphore[mApexId]);

   return lErrorFlag;
}

int32_t ACF_Process_APU::SanityCheck_ProgramMem_Dma()
{
   int32_t lRetVal = 0;

   void* lpPmemDebugOal = OAL_MemoryAllocFlag(mPmemSizeInBytes, OAL_MEMORY_FLAG_ALIGN(ALIGN2_CACHELINE)|OAL_MEMORY_FLAG_CONTIGUOUS);
   if (lpPmemDebugOal)
   {
      OAL_MemoryFlushAndInvalidate(OAL_MemoryReturnAddress(lpPmemDebugOal, ACCESS_CH_WB), mPmemSizeInBytes);

      mcdma_hal_memcpy(mApexId, mAcfResInfo.dmaChIn[0],
            (uint32_t)(uintptr_t)OAL_MemoryReturnAddress(lpPmemDebugOal, ACCESS_PHY),
            (uint32_t)((uintptr_t)ReturnPhysicalHwPtr(mApexId, HW_REG_SMEM) + mSmemBaseAddrOffset + mPmemBaseAddrOffset),
            mPmemSizeInBytes,
            INCR1,                       //burstsize
            DMA_BURST_BEAT_DDWORD_SIZE); //wordsize

      if (0 != SanityCheck_ProgramMem((volatile uint32_t*)lpPmemDebugOal))
      {
         //sanity check failed
         lRetVal = 1;
      }

      OAL_MemoryFree(lpPmemDebugOal);
   }
   else
   {
      printf("ACF_Process_APU::SanityCheck_ProgramMem_Dma() -> pmem debug memory allocation failed!");
      lRetVal = 2;
   }

   return lRetVal;
}

int32_t ACF_Process_APU::SanityCheck_ProgramParams()
{
   int32_t lErrorFlag = 0;

   volatile uint32_t* lpSMEM = (volatile uint32_t*)((intptr_t)ReturnVirtualHwPtr(mApexId, HW_REG_SMEM) + mSmemBaseAddrOffset + mDmemBaseAddrOffset);
   volatile uint32_t* lpParamsFromSmem = lpSMEM + (0x644/4);
   uint32_t* lpParamsGoldenRef = (uint32_t*)mProgramParams;

   for (int i=0; i<mProgramParamSizeInWords; i++)
   {
      if (lpParamsFromSmem[i] != lpParamsGoldenRef[i])
      {
         printf("SanityCheck_ProgramParams (word %d of %d: GOOD=%08X BAD=%08X)!\n", i, mProgramParamSizeInWords, lpParamsGoldenRef[i], lpParamsFromSmem[i]);
         lErrorFlag = 1;
      }
   }

   return lErrorFlag;
}

void ACF_Process_APU::DebugDump()
{
   std::stringstream lApuCfgString;
   if (mApuCfg == ACF_APU_CFG__APU_0_CU_0_31_SMEM_0_1)
      lApuCfgString << "APEX_" << mApexId << "_APU_0_32";
   else if (mApuCfg == ACF_APU_CFG__APU_1_CU_32_63_SMEM_2_3)
      lApuCfgString << "APEX_" << mApexId << "_APU_1_32";
   else if (mApuCfg == ACF_APU_CFG__APU_0_CU_0_63_SMEM_0_3 || mApuCfg == ACF_APU_CFG__DEFAULT)
      lApuCfgString << "APEX_" << mApexId << "_APU_0_64";
   else
      lApuCfgString << "APEX_" << mApexId << "_unknown!!!!";

   printf("-----------------------------------------------\n");
   printf("DebugDump() - apu cfg = %s\n", lApuCfgString.str().c_str());
   printf("-----------------------------------------------\n");

   //------------------------------------------
   //HW register stuff
   //------------------------------------------

   printf("*********HW REGISTER STUFF**************\n");

   printf("gpDma->Isr              = 0x%08X\n", mpDma->Isr.as32BitValue);
   printf("gpDma->ChEnable         = 0x%08X\n", mpDma->ChEnable.as32BitValue);

   for (int32_t i=0; i<mAcfResInfo.numDmaChIn; i++)
   printf("gpDma->Ch[%d].Byte       = 0x%08X (in)\n", mAcfResInfo.dmaChIn[i], mpDma->Ch[mAcfResInfo.dmaChIn[i]].Byte.as32BitValue);
   for (int32_t i=0; i<mAcfResInfo.numDmaChOut; i++)
   printf("gpDma->Ch[%d].Byte       = 0x%08X (out)\n", mAcfResInfo.dmaChOut[i], mpDma->Ch[mAcfResInfo.dmaChOut[i]].Byte.as32BitValue);

   printf("gpStio->Isr             = 0x%08X\n", mpStio->Isr.as32BitValue);
   printf("gpStio->Enable          = 0x%08X\n", mpStio->Enable.as32BitValue);
   printf("gpMotionComp->Isr       = 0x%08X\n", mpMotionComp->Isr.as32BitValue);
   printf("gpMotionComp->ChEnable  = 0x%08X\n", mpMotionComp->ChEnable.as32BitValue);
   printf("gpSeq->Isr              = 0x%08X\n", mpSeq->Isr.as32BitValue);
   printf("gpSeq->ScbStatus        = 0x%08X\n", mpSeq->ScbStatus.as32BitValue);
   printf("gpSeq->ScbIdle          = 0x%08X\n", mpSeq->ScbIdle.as32BitValue);

   for (int32_t i=0; i<20; i++)
   printf("gpSeq->ResourceFix[%2d]  = 0x%08X\n", i, mpSeq->ResourceFix[i].as32BitValue);

   for (int32_t i=0; i<4; i++)
   printf("gpSeq->ResourceZero[%2d] = 0x%08X\n", i, mpSeq->ResourceZero[i].as32BitValue);

   //------------------------------------------
   //apu program specific stuff
   //------------------------------------------

   printf("*********APU PROGRAM STUFF**************\n");

   //Some diagnostic info collected from the APU program
   volatile uint32_t* lpSMEM = (volatile uint32_t*)((intptr_t)ReturnVirtualHwPtr(mApexId, HW_REG_SMEM) + mSmemBaseAddrOffset + mDmemBaseAddrOffset);
   printf("lNumInputIterations     = %d\n", lpSMEM[0x1220/4]);
   printf("lInputIter              = %d\n", lpSMEM[0x1224/4]);
   printf("lInputIterMce           = %d\n", lpSMEM[0x122C/4]);
   printf("lProcIter               = %d\n", lpSMEM[0x1228/4]);

   //mApuProgFuncPtr
   printf("mApuProgFuncPtr         = 0x%X\n", mApuProgFuncPtr);
   printf("mApuProgFuncPtr in DMEM = 0x%X\n", lpSMEM[0x1f88/4]);
   printf("mApuProgFuncPtr in LOAD = 0x%X\n", mpLoadDmem[0x558/4]);
   printf("mApuProgFuncPtr in XMEM = 0x%X\n", ((uint32_t*)mpDmemLoadOal)[0x558/4]);
   printf("APU load LL VA:0x%08X PA:0x%08X\n",
          (uint32_t)(uintptr_t)mpLoadSegmentsLLOal,
          (uint32_t)(uintptr_t)OAL_MemoryReturnAddress(mpLoadSegmentsLLOal, ACCESS_PHY));

   //------------------------------------------
   //file dumps
   //------------------------------------------

   FILE* lpFile = 0;
   std::stringstream lSmemDumpHostFileName;
   std::stringstream lSmemDumpDmaFileName;
   std::stringstream lPmemExtMemDumpFileName;
   std::stringstream lDmemExtMemDumpFileName;
   std::stringstream lApuLoadDescFileName;

   uint64_t lTimestamp = RET_TICKS;

   lSmemDumpHostFileName   << lTimestamp << "_smem_dump_host_" << lApuCfgString << ".bin";
   lSmemDumpDmaFileName    << lTimestamp << "_smem_dump_dma_"  << lApuCfgString << ".bin";
   lPmemExtMemDumpFileName << lTimestamp << "_pmem_oal_dump_"  << lApuCfgString << ".bin";
   lDmemExtMemDumpFileName << lTimestamp << "_dmem_oal_dump_"  << lApuCfgString << ".bin";
   lApuLoadDescFileName    << lTimestamp << "_apuload_ll.bin";

   int32_t lSmemSizeInBytes = 0;
   int32_t lCmemSizeInBytes = 0;
   RetApuMemSizes(Translate_AcfApuCfg_CmemIfApuCfg(mApuCfg, mHwVersion), &lSmemSizeInBytes, &lCmemSizeInBytes);

   volatile uint32_t* lpSMEMBase = (volatile uint32_t*)((intptr_t)ReturnVirtualHwPtr(mApexId, HW_REG_SMEM));
   lpFile = fopen(lSmemDumpHostFileName.str().c_str(), "wb");
   fwrite((void*)lpSMEMBase, 4, lSmemSizeInBytes/4, lpFile);
   fclose(lpFile);

   lpFile = fopen(lPmemExtMemDumpFileName.str().c_str(), "wb");
   fwrite((void*)mpPmemLoadOal, 4, mLoadPmemSize, lpFile);
   fclose(lpFile);

   lpFile = fopen(lDmemExtMemDumpFileName.str().c_str(), "wb");
   fwrite((void*)mpDmemLoadOal, 4, mLoadDmemSize, lpFile);
   fclose(lpFile);

   lpFile = fopen(lApuLoadDescFileName.str().c_str(), "wb");
   fwrite((void*)mpLoadSegmentsLLOal, 4, 8*2 + 8*21, lpFile); //number of segments is hard-coded here!!!
   fclose(lpFile);

   //--------------------------------------------------------
   //use the DMA to retrieve SMEM contents and perform a dump
   //--------------------------------------------------------

   void* lpSmemDebugOal = OAL_MemoryAllocFlag(lSmemSizeInBytes, OAL_MEMORY_FLAG_ALIGN(ALIGN2_CACHELINE)|OAL_MEMORY_FLAG_CONTIGUOUS);
   if (lpSmemDebugOal)
   {
      OAL_MemoryFlushAndInvalidate(OAL_MemoryReturnAddress(lpSmemDebugOal, ACCESS_CH_WB), lSmemSizeInBytes);

      mcdma_hal_memcpy(mApexId, mAcfResInfo.dmaChIn[0],
            (uint32_t)(uintptr_t)OAL_MemoryReturnAddress(lpSmemDebugOal, ACCESS_PHY),
            (uint32_t)((uintptr_t)ReturnPhysicalHwPtr(mApexId, HW_REG_SMEM) + mSmemBaseAddrOffset),
            lSmemSizeInBytes,
            INCR1,                       //burstsize
            DMA_BURST_BEAT_DDWORD_SIZE); //wordsize

      lpFile = fopen(lSmemDumpDmaFileName.str().c_str(), "wb");
      fwrite((void*)lpSmemDebugOal, 4, lSmemSizeInBytes/4, lpFile); //number of segments is hard-coded here!!!
      fclose(lpFile);

      OAL_MemoryFree(lpSmemDebugOal);
   }
   else
   {
      printf("ACF_Process_APU::DebugDump() -> smem debug memory allocation failed!");
   }
}
#endif

//********************************************************************
//METHODS RELATED TO SCENARIO SELECTION
//********************************************************************

#define MAX_CHUNK_WIDTH_IN_BYTES 128
#define MAX_CHUNK_HEIGHT         32

int32_t SelectChunkWidth(ACF_Process_PortInfo* lpPortInfo,
                         acf_scenario_list* lpScenarioList,
                         int32_t lRoiInfoL, int32_t lRoiInfoR, int32_t lCuArrayWidth,
                         int32_t lCriteriaChunkWidthDivisibilityInBytes, int32_t lCriteriaMinArrayUtilization,
                         ACF_SCENARIO_SELECTION_BUFFER_POLICY lBufferPolicy)
{

   int32_t lChunkWidth = 0;

   ACF_DataDesc* lpDD = &lpPortInfo->mDataDesc;

   //calculate the starting candidate chunk width in bytes, rounded up to the nearest multiple of
   //'lCriteriaChunkWidthDivisibilityInBytes'
   int32_t lE0WidthInBytes = lpDD->RetElementDimX()*RetDataTypeSizeInBytes(lpDD->RetElementDataType());
   int32_t lStartingCandidateChunkWidth = lpDD->RetWidth()/lCuArrayWidth;
   int32_t lStartingCandidateChunkWidthInBytes = (lStartingCandidateChunkWidth > 0) ? lStartingCandidateChunkWidth*lE0WidthInBytes : lCriteriaChunkWidthDivisibilityInBytes;
   int32_t lTmp = lStartingCandidateChunkWidthInBytes%lCriteriaChunkWidthDivisibilityInBytes;
   if (0 != lTmp)
      lStartingCandidateChunkWidthInBytes += (lCriteriaChunkWidthDivisibilityInBytes - lTmp);

   //loop from smallest to largest; the first valid candidate we find will be the one with
   //the highest array utilization that satisfies 'lCriteriaChunkWidthDivisibilityInBytes'
   for (int32_t lCandidateChunkWidthInBytes = lStartingCandidateChunkWidthInBytes;
                lCandidateChunkWidthInBytes <= MAX_CHUNK_WIDTH_IN_BYTES;
                lCandidateChunkWidthInBytes += lCriteriaChunkWidthDivisibilityInBytes)
   {
      int32_t lCandidateChunkWidth = lCandidateChunkWidthInBytes/lE0WidthInBytes;

      int32_t lAdditionalCusReqForRoi = ((lRoiInfoL+lCandidateChunkWidth-1)/lCandidateChunkWidth) +
                                        ((lRoiInfoR+lCandidateChunkWidth-1)/lCandidateChunkWidth);

      //criteria satisfaction flags
      int32_t lRespectMemSatisfiedFlag          = 0;
      int32_t lMinArrayUtilisationSatisfiedFlag = 0;
      int32_t lScenarioExistsFlag               = 0;

      //does the chunk width divide nicely into the IO width?
      switch(lBufferPolicy)
      {
      case ACF_SCENARIO_SELECTION_BUFFER_POLICY_STRICT:
         //chunk width must divide nicely into IO width
         if (0 == lpDD->RetWidth()%lCandidateChunkWidth)
            lRespectMemSatisfiedFlag = 1;
         break;
      case ACF_SCENARIO_SELECTION_BUFFER_POLICY_RELAXED:
         //it's OK if chunk width doesn't divide nicely into IO width
         lRespectMemSatisfiedFlag = 1;
         break;
      }

      if (1 == lRespectMemSatisfiedFlag)
      {
         int32_t lNumCusReqForCore = (lpDD->RetWidth() + lCandidateChunkWidth - 1)/lCandidateChunkWidth;
         int32_t lNumCusReqTotal = lNumCusReqForCore + lAdditionalCusReqForRoi;

         //does array utilization satisfy lCriteriaArrayUtilization?
         float lPercentArrayUtilization = ((float)lNumCusReqTotal)/((float)lCuArrayWidth)*100.0;
         if (lPercentArrayUtilization >= lCriteriaMinArrayUtilization && lPercentArrayUtilization <= 100)
         {
            lMinArrayUtilisationSatisfiedFlag = 1;
         }

         //does a scenario exist that has this chunk width?
         if (1 == lMinArrayUtilisationSatisfiedFlag)
         {
            for (int32_t k=0; k<lpScenarioList->numScenarios; k++)
            {
               if (lCandidateChunkWidth == lpScenarioList->pScenarioList[k].pBufferData[lpPortInfo->mLmIndex].chunkWidth)
               {
                  lScenarioExistsFlag = 1;
                  break;
               }
            }
         }

         //if the scenario exists AND the desired array utilization is satisfied, pick this and get out
         if (1 == lScenarioExistsFlag && 1 == lMinArrayUtilisationSatisfiedFlag)
         {
            lChunkWidth = lCandidateChunkWidth;
            break;
         }
      }
   }

   return lChunkWidth;
}

int32_t SelectChunkWidth_Balanced(ACF_Process_PortInfo* lpPortInfo,
                                  acf_scenario_list* lpScenarioList,
                                  int32_t lRoiInfoL, int32_t lRoiInfoR, int32_t lCuArrayWidth,
                                  ACF_SCENARIO_SELECTION_BUFFER_POLICY lBufferPolicy)
{
   //- try to use as many CUs as possible while favoring chunk widths that are at least a multiple of 4
   //- this will be the default behavior if the user doesn't change it

   int32_t lChunkWidth = 0;

   //1st choice: chunk width in bytes is divisible by 8 and array utilization is >= 70%
   lChunkWidth = SelectChunkWidth (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 8, 70, lBufferPolicy);

   if (0 == lChunkWidth)
   {
      //2nd choice: chunk width in bytes is divisible by 4 and array utilization is >= 70%
      lChunkWidth = SelectChunkWidth (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 4, 70, lBufferPolicy);

      if (0 == lChunkWidth)
      {
         //last resort: chunk width in bytes is divisible by 2 and array utilization is >= 0%
         lChunkWidth = SelectChunkWidth (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 2, 0, lBufferPolicy);
      }
   }

   return lChunkWidth;
}

int32_t SelectChunkWidth_ProcessingLimited(ACF_Process_PortInfo* lpPortInfo,
                                           acf_scenario_list* lpScenarioList,
                                           int32_t lRoiInfoL, int32_t lRoiInfoR, int32_t lCuArrayWidth,
                                           ACF_SCENARIO_SELECTION_BUFFER_POLICY lBufferPolicy)
{
   //- try to use as many CUs as possible, even if it means inefficient chunk widths
   //- this was basically the old 'default' behavior

   int32_t lChunkWidth = 0;

   //1st choice: chunk width in bytes is divisible by 8 and array utilization is >= 90%
   lChunkWidth = SelectChunkWidth (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 8, 90, lBufferPolicy);

   if (0 == lChunkWidth)
   {
      //2nd choice: chunk width in bytes is divisible by 4 and array utilization is >= 90%
      lChunkWidth = SelectChunkWidth (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 4, 90, lBufferPolicy);

      if (0 == lChunkWidth)
      {
         //last resort: chunk width in bytes is divisible by 2 and array utilization is >= 0%
         lChunkWidth = SelectChunkWidth (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 2, 0, lBufferPolicy);
      }
   }

   return lChunkWidth;
}

int32_t SelectChunkWidth_BandwidthLimited(ACF_Process_PortInfo* lpPortInfo,
                                          acf_scenario_list* lpScenarioList,
                                          int32_t lRoiInfoL, int32_t lRoiInfoR, int32_t lCuArrayWidth,
                                          ACF_SCENARIO_SELECTION_BUFFER_POLICY lBufferPolicy)
{
   //- top priority is to ensure chunk width is a multiple of 8 bytes, even if it means wasting CUs

   int32_t lChunkWidth = 0;

   //1st choice: chunk width in bytes is divisible by 8 and array utilization is >= 50%
   lChunkWidth = SelectChunkWidth (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 8, 50, lBufferPolicy);

   if (0 == lChunkWidth)
   {
      //2nd choice: chunk width in bytes is divisible by 4 and array utilization is >= 50%
      lChunkWidth = SelectChunkWidth (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 4, 50, lBufferPolicy);

      if (0 == lChunkWidth)
      {
         //last resort: chunk width in bytes is divisible by 2 and array utilization is >= 0%
         lChunkWidth = SelectChunkWidth (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 2, 0, lBufferPolicy);
      }
   }

   return lChunkWidth;
}

int32_t SelectChunkHeight(ACF_Process_PortInfo* lpPortInfo,
                          acf_scenario_list* lpScenarioList,
                          int32_t lChunkWidth,
                          int32_t lAvailableCmem,
                          int32_t lAvailableDmem,
                          ACF_SCENARIO_SELECTION_BUFFER_POLICY lBufferPolicy)
{
   //want chunk height selection to be influenced by the total number of tiles; goal is to pick the largest height while
   //still allowing some amount of pipelining to take place (e.g. if IO size has a height of 8, don't want to choose a
   //chunk height of 8 since there will be no pipelining!)

   int32_t lChunkHeight = 0;

   int32_t lChunkHeightChoices[3] = {0, 0, MAX_CHUNK_HEIGHT};

   ACF_DataDesc* lpDD = &lpPortInfo->mDataDesc;

   for (int32_t k=0; k<lpScenarioList->numScenarios; k++)
   {
      int32_t lTmpChunkWidth = lpScenarioList->pScenarioList[k].pBufferData[lpPortInfo->mLmIndex].chunkWidth;

      //chunk width has already been chosen
      if (lTmpChunkWidth == lChunkWidth)
      {
         int32_t lCandidateChunkHeight = lpScenarioList->pScenarioList[k].pBufferData[lpPortInfo->mLmIndex].chunkHeight;

         //criteria satisfaction flags
         int32_t lRespectMemSatisfiedFlag = 0;

         //does the chunk height divide nicely into the IO height?
         switch(lBufferPolicy)
         {
         case ACF_SCENARIO_SELECTION_BUFFER_POLICY_STRICT:
            //chunk height must divide nicely into IO height
            if (0 == lpDD->RetHeight()%lCandidateChunkHeight)
               lRespectMemSatisfiedFlag = 1;
            break;
         case ACF_SCENARIO_SELECTION_BUFFER_POLICY_RELAXED:
            //it's OK if chunk height doesn't divide nicely into IO height
            lRespectMemSatisfiedFlag = 1;
            break;
         }

         //the chosen chunk height should allow for some degree of pipelining to occur, so in general
         //try to limit chunk height selection
         int32_t lNumTiles = (lpDD->RetHeight() + lCandidateChunkHeight - 1)/lCandidateChunkHeight;

         if (1 == lRespectMemSatisfiedFlag)
         {
            if (((int32_t)lpScenarioList->pScenarioList[k].cmemReq <= lAvailableCmem) &&
                ((int32_t)lpScenarioList->pScenarioList[k].dmemReq <= lAvailableDmem))
            {
               //1st choice: choose largest chunk height that allows for at least 16 tiles
               if ((lCandidateChunkHeight > lChunkHeightChoices[0]) && (lNumTiles >= 16))
                  lChunkHeightChoices[0] = lCandidateChunkHeight;
               //2nd choice: choose largest chunk height that allows for at least 8 tiles
               if ((lCandidateChunkHeight > lChunkHeightChoices[1]) && (lNumTiles >= 8))
                  lChunkHeightChoices[1] = lCandidateChunkHeight;
               //last resort: choose the smallest available chunk height (maximize the number of tiles)
               if ((lCandidateChunkHeight < lChunkHeightChoices[2]))
                  lChunkHeightChoices[2] = lCandidateChunkHeight;
            }
         }
      }
   }

   if (lChunkHeightChoices[0] != 0)
      lChunkHeight = lChunkHeightChoices[0];
   else if (lChunkHeightChoices[1] != 0)
      lChunkHeight = lChunkHeightChoices[1];
   else if (lChunkHeightChoices[2] != 0)
      lChunkHeight = lChunkHeightChoices[2];

   return lChunkHeight;
}

/*
Select optimal scenario based on IO configuration.
lUserSelPort, lUserSelChunkWidth, and lUserSelChunkHeight are for advanced use
where the user wants to choose a scenario based on a specific width/height/both for a specific port
*/

acf_scenario* SelectOptimalScenario(std::vector<ACF_Process_PortInfo> &lPortInfoVec,
                                    std::vector<ACF_Process_PortInfo_APU> &lPortInfoApuVec,
                                    int32_t lRoiInfoL, int32_t lRoiInfoR,
                                    int32_t lCuArrayWidth, int32_t lAvailableCmem, int32_t lAvailableDmem,
                                    acf_scenario_list* lpScenarioList,
                                    std::string lUserSelPort,
                                    int32_t     lUserSelChunkWidth,
                                    int32_t     lUserSelChunkHeight,
                                    ACF_SCENARIO_SELECTION_BIAS lBias,
                                    ACF_SCENARIO_SELECTION_BUFFER_POLICY lBufferPolicy)
{
   ACF_Process_PortInfo* lpPortInfo = 0;
   acf_scenario* lpSelectedScenario = 0;
   int32_t lFlagNotEnoughMemory = 0;

   if (lpScenarioList->numScenarios == 1) //there is only a single scenario available
   {
      if (lUserSelPort != "") //user has singled out a specific port so find it
      {
         for (int32_t i=0; i<(int32_t)lPortInfoVec.size(); i++)
         {
            if (lPortInfoVec[i].mPortIdentifier == lUserSelPort)
            {
               lpPortInfo = &lPortInfoVec[i];
               break;
            }
         }

         if (lpPortInfo)
         {
            int32_t lTmpChunkWidth = lpScenarioList->pScenarioList[0].pBufferData[lpPortInfo->mLmIndex].chunkWidth;
            int32_t lTmpChunkHeight = lpScenarioList->pScenarioList[0].pBufferData[lpPortInfo->mLmIndex].chunkHeight;

            if ((lUserSelChunkWidth == 0) || (lUserSelChunkWidth != 0 && lUserSelChunkWidth == lTmpChunkWidth))
            {
               if ((lUserSelChunkHeight == 0) || (lUserSelChunkHeight != 0 && lUserSelChunkHeight == lTmpChunkHeight))
               {
                  if ((int32_t)lpScenarioList->pScenarioList[0].cmemReq <= lAvailableCmem &&
                      (int32_t)lpScenarioList->pScenarioList[0].dmemReq <= lAvailableDmem)
                  {
                     lpSelectedScenario = &lpScenarioList->pScenarioList[0];
                  }
                  else
                  {
                     lFlagNotEnoughMemory = 1;
                  }
               }
               else
               {
                  printf("SelectOptimalScenario() -> no scenario exists where port '%s' has a chunk height of %d.\n",
                         lUserSelPort.c_str(), lUserSelChunkHeight);
               }
            }
            else
            {
               printf("SelectOptimalScenario() -> no scenario exists where port '%s' has a chunk width of %d.\n",
                      lUserSelPort.c_str(), lUserSelChunkWidth);
            }
         }
         else
         {
            printf("SelectOptimalScenario() -> port '%s' cannot be found\n", lUserSelPort.c_str());
         }
      }
      else if (lUserSelPort == "") //no specific port has been singled out
      {
         if ((int32_t)lpScenarioList->pScenarioList[0].cmemReq <= lAvailableCmem &&
             (int32_t)lpScenarioList->pScenarioList[0].dmemReq <= lAvailableDmem)
         {
            lpSelectedScenario = &lpScenarioList->pScenarioList[0];
         }
         else
         {
            lFlagNotEnoughMemory = 1;
         }
      }

      if (lFlagNotEnoughMemory)
      {
         printf("SelectOptimalScenario() -> The single available scenario overflows available APEX memory resources (CMEM: %d/%d DMEM: %d/%d)\n",
                lpScenarioList->pScenarioList[0].cmemReq, lAvailableCmem, lpScenarioList->pScenarioList[0].dmemReq, lAvailableDmem);
      }
   }
   else //multiple scenarios available
   {
      //if user has selected a specific port
      if (lUserSelPort != "")
      {
         for (int32_t i=0; i<(int32_t)lPortInfoVec.size(); i++)
         {
            if (lPortInfoVec[i].IsNonFixed() && lPortInfoVec[i].IsDirect() && lPortInfoApuVec[i].IsCmem() && lPortInfoVec[i].mPortIdentifier == lUserSelPort)
            {
               lpPortInfo = &lPortInfoVec[i];
               break;
            }
         }
      }
      else //user has not specified a port so ACF will select one
      {
         //first choice is to select a direct non-fixed non-static cmem port (an indirect port cannot be used for scenario selection
         //because chunk size and array utilization are already predetermined, and a static port should only be use if the first
         //choice is not available)
         //NOTE: ACF will not try to choose a scenario based on a DMEM port; it is unlikely that a suitable scenario has been
         //      pre-calculated, and it is generally expected that the user has fixed or overridden the DMEM chunk size to suit
         //      their use case
         for (int32_t i=0; i<(int32_t)lPortInfoVec.size(); i++)
         {
            if (lPortInfoVec[i].IsNonFixed() && lPortInfoVec[i].IsDirect() && lPortInfoVec[i].IsNonStatic() && lPortInfoApuVec[i].IsCmem())
            {
               lpPortInfo = &lPortInfoVec[i];
               break;
            }
         }

         if (0 == lpPortInfo) //if first choice isn't found, accept a direct non-fixed static cmem port port as a candidate
         {
            for (int32_t i=0; i<(int32_t)lPortInfoVec.size(); i++)
            {
               if (lPortInfoVec[i].IsNonFixed() && lPortInfoVec[i].IsDirect() && lPortInfoApuVec[i].IsCmem())
               {
                  lpPortInfo = &lPortInfoVec[i];
                  break;
               }
            }
         }
      }

      if (lpPortInfo) //acceptable port identified
      {
         int32_t lChunkWidth = 0;
         int32_t lChunkHeight = 0;

         //---------------------------------
         //select an appropriate chunk width
         //---------------------------------

         if (lUserSelChunkWidth != 0) //user wants a specific chunk width
         {
            lChunkWidth = lUserSelChunkWidth;
         }
         else //acf is choosing the chunk width
         {
            switch (lBias)
            {
            case ACF_SCENARIO_SELECTION_BIAS_BALANCED:
               lChunkWidth = SelectChunkWidth_Balanced(lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, lBufferPolicy);
               break;
            case ACF_SCENARIO_SELECTION_BIAS_PROCESSING_LIM:
               lChunkWidth = SelectChunkWidth_ProcessingLimited(lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, lBufferPolicy);
               break;
            case ACF_SCENARIO_SELECTION_BIAS_BANDWIDTH_LIM:
               lChunkWidth = SelectChunkWidth_BandwidthLimited(lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, lBufferPolicy);
               break;
            default:
               lChunkWidth = SelectChunkWidth_Balanced(lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, lBufferPolicy);
               break;
            }
         }

         //----------------------------------
         //select an appropriate chunk height
         //----------------------------------

         if (lUserSelChunkHeight != 0) //user wants a specific chunk height
         {
            lChunkHeight = lUserSelChunkHeight;
         }
         else //acf is choosing the chunk height
         {
            if (0 != lChunkWidth)
            {
               if (lpPortInfo->IsStatic())
               {
                  //only end up here if all direct non-fixed cmem inputs are static
                  lChunkHeight = lpPortInfo->mDataDesc.RetHeight();
               }
               else
               {
                  lChunkHeight = SelectChunkHeight(lpPortInfo, lpScenarioList, lChunkWidth, lAvailableCmem, lAvailableDmem, lBufferPolicy);
               }
            }
         }

#if 0 //debugging code
         ACF_DataDesc* lpDD = &lpPortInfo->mDataDesc;
         int32_t lChunkWidth_Rel[3] = {0}; //PL,BL,BAL
         int32_t lChunkWidth_Str[3] = {0}; //PL,BL,BAL
         lChunkWidth_Str[0] = SelectChunkWidth_ProcessingLimited(lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 1);
         lChunkWidth_Rel[0] = SelectChunkWidth_ProcessingLimited(lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 0);
         lChunkWidth_Str[1] = SelectChunkWidth_BandwidthLimited (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 1);
         lChunkWidth_Rel[1] = SelectChunkWidth_BandwidthLimited (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 0);
         lChunkWidth_Str[2] = SelectChunkWidth_Balanced         (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 1);
         lChunkWidth_Rel[2] = SelectChunkWidth_Balanced         (lpPortInfo, lpScenarioList, lRoiInfoL, lRoiInfoR, lCuArrayWidth, 0);

         printf("[%4dx%4d]\n", lpDD->RetWidth(), lpDD->RetHeight());
         printf("   [STR] CHUNK WIDTH: PL=%3d BL=%3d BAL=%3d\n", lChunkWidth_Str[0], lChunkWidth_Str[1], lChunkWidth_Str[2]);
         printf("   [REL] CHUNK WIDTH: PL=%3d BL=%3d BAL=%3d\n", lChunkWidth_Rel[0], lChunkWidth_Rel[1], lChunkWidth_Rel[2]);
         printf("   SELECTED CHUNK SIZE = %dx%d\n", lChunkWidth, lChunkHeight);
#endif

         //retrieve the associated scenario with the selected chunk width and height
         for (int32_t k=0; k<lpScenarioList->numScenarios; k++)
         {

            if ((lpScenarioList->pScenarioList[k].pBufferData[lpPortInfo->mLmIndex].chunkWidth == lChunkWidth) &&
                (lpScenarioList->pScenarioList[k].pBufferData[lpPortInfo->mLmIndex].chunkHeight == lChunkHeight) &&
                ((int32_t)lpScenarioList->pScenarioList[k].cmemReq <= lAvailableCmem) &&
                ((int32_t)lpScenarioList->pScenarioList[k].dmemReq <= lAvailableDmem))
            {
               lpSelectedScenario = &lpScenarioList->pScenarioList[k];
               break;
            }
         }
      }
      else //valid port was not found
      {
         if (lUserSelPort == "") //a specific port was not specified
         {
            printf("SelectOptimalScenario() -> A valid scenario selection port cannot be found (must be a non-fixed direct vector port)\n");
         }
         else //a specific port was specified
         {
            printf("SelectOptimalScenario() -> port '%s' cannot be found or cannot be used for scenario selection (must be a non-fixed direct vector port)\n", lUserSelPort.c_str());
         }
      }
   }

   return lpSelectedScenario;
}

void ACF_Process_APU::CfgScenarioSelectionBufferPolicy(ACF_SCENARIO_SELECTION_BUFFER_POLICY lBufferPolicy)
{
   mScenarioSelectionBufferPolicy = lBufferPolicy;
}

void ACF_Process_APU::CfgScenarioSelectionBias(ACF_SCENARIO_SELECTION_BIAS lBias)
{
   mScenarioSelectionBias = lBias;
}

int32_t ACF_Process_APU::SelectScenario(std::string lPortIdentifier, int32_t lChunkWidth, int32_t lChunkHeight)
{
   //if the user calls this they are now in full control of scenario selection (i.e. ACF start will no longer
   //perform scenario selection)
   mUserControlledScenarioFlag = 1;

   return SelectScenario_internal(lPortIdentifier, lChunkWidth, lChunkHeight);
}

int32_t ACF_Process_APU::SelectScenario_internal(std::string lPortIdentifier, int32_t lChunkWidth, int32_t lChunkHeight)
{
   int lRetVal = ACF_SUCCESS;

   //Consider this scenario: a graph has  a single input, no spatial dep, input data region = 1024x32, and NUMCUs = 32
   //Should ACF consider this a 2D processing pipeline with eight tiles of 32x4 chunks (for example) or should it consider it
   //a 1D processing pipeline with eight tiles of 4x32 chunks (for example)?
   //***For now, ACF will perform scenario selection assuming that a 2D processing pipeline will be established.  If the user wants
   //the processing pipeline to be treated as 1D, they will have to call SelectScenario with a suitable chunk width and a chunk height that is equal
   //to the height of the data region they are processing.

   //Since scenario selection is taking place, the IO size change flag can be cleared.
   ClearIoSizeChangeFlag();

   if (mRoiInfoManualFlag != 1)
   {
      if (DetWorstCaseRoiInfo() != 0) //check applicable inputs for ROI information
      {
         lRetVal = ACF_ERROR;
         return lRetVal;
      }
   }

   acf_scenario* lpScenario = SelectOptimalScenario(mPortInfoVec, mPortInfoApuVec, mRoiInfoL, mRoiInfoR,
         mCuArrayWidth, mCmemHeapSizeInBytes, mDmemHeapSizeInBytes, mpScenarioList,
         lPortIdentifier, lChunkWidth, lChunkHeight, mScenarioSelectionBias, mScenarioSelectionBufferPolicy);

   if (lpScenario != 0)
   {
      //copy target scenario information from the global table into a local entity
      if (0 == CfgLocalScenario(lpScenario))
      {
         mpSelectedScenario = &mSelectedScenario;
         //printf("ACF_Process_APU::SelectScenario_internal() -> Selected 'base' chunk size = [%d,%d]\n", mpSelectedScenario->baseChunkWidth, mpSelectedScenario->baseChunkHeight);
      }
      else
      {
         printf("ACF_Process_APU::InitLocalScenario() -> Failure\n");
         lRetVal = ACF_ERROR;
      }
   }
   else
   {
      if (lPortIdentifier != "" && lChunkWidth != 0 && lChunkHeight != 0)
      {
         printf("ACF_Process_APU::SelectScenario_internal() -> The user-specified scenario (port %s = [%d,%d]) could not be found, or there is not enough available memory\n",
                lPortIdentifier.c_str(), lChunkWidth, lChunkHeight);
      }
      else
      {
         printf("ACF_Process_APU::SelectScenario_internal() -> A suitable scenario could not be found\n");
      }
      lRetVal = ACF_SCENARIO_DETECTION_ERROR;
   }

   return lRetVal;
}

int32_t ACF_Process_APU::QueryPortChunkSize(std::string lPortIdentifier, int32_t& lChunkWidth, int32_t& lChunkHeight)
{
   int32_t lRetVal = 0;
   int32_t lPortIdentifierFound = 0;

   if (mpSelectedScenario != 0)
   {
      for (int32_t i=0; i<(int32_t)mPortInfoVec.size(); i++)
      {
         if(lPortIdentifier == mPortInfoVec[i].mPortIdentifier)
         {
            lPortIdentifierFound = 1;
            lChunkWidth  = mpSelectedScenario->pBufferData[mPortInfoVec[i].mLmIndex].chunkWidth;
            lChunkHeight = mpSelectedScenario->pBufferData[mPortInfoVec[i].mLmIndex].chunkHeight;
            break;
         }
      }

      if (!lPortIdentifierFound)
      {
         printf("ACF_Process_APU::QueryPortChunkSize -> Port '%s' could not be found\n", lPortIdentifier.c_str());
         lRetVal = 1;
      }
   }
   else
   {
      printf("ACF_Process_APU::QueryPortChunkSize -> No scenario has been selected\n");
      lRetVal = 1;
   }

   return lRetVal;
}

//Override the chunk size of a port for the currently 'selected' scenario (must be used in tandem with 'SelectScenario')
int32_t ACF_Process_APU::OverridePortChunkSize(std::string lPortIdentifier, int32_t lChunkWidth, int32_t lChunkHeight)
{
   int32_t lRetVal = 1;
   int32_t lPortFoundFlag = 0;

   //only proceed if a specific scenario has already been selected
   if (mpSelectedScenario != 0)
   {
      for (int32_t i=0; i<(int32_t)mPortInfoVec.size(); i++)
      {
         ACF_Process_PortInfo* lpPortInfo = &mPortInfoVec[i];
         ACF_Process_PortInfo_APU* lpPortInfoApu = &mPortInfoApuVec[i];
         if (lpPortInfo->mPortIdentifier == lPortIdentifier)
         {
            lPortFoundFlag = 1;

            /*
            Existing CMEM/DMEM req for the scenario is known.  Calculate and subtract the 'original' cost of this
            buffer and add the cost of the updated size.  Make sure the new 'total'
            doesn't exceed the available CMEM/DMEM!  Update the scenario description accordingly.
            */

            int32_t lLmIndex = lpPortInfo->mLmIndex;

            ACF_LocalMemDesc lLmDescOrig;
            lLmDescOrig.e0 = lpPortInfo->mE0;
            lLmDescOrig.chunkWidth = mpSelectedScenario->pBufferData[lLmIndex].chunkWidth;
            lLmDescOrig.chunkHeight = mpSelectedScenario->pBufferData[lLmIndex].chunkHeight;
            lLmDescOrig.numBuffers = mpSelectedScenario->pBufferData[lLmIndex].numBuffers;
            lLmDescOrig.padding.w = mpSelectedScenario->pBufferData[lLmIndex].padding.w;
            lLmDescOrig.padding.e = mpSelectedScenario->pBufferData[lLmIndex].padding.e;
            lLmDescOrig.padding.n = mpSelectedScenario->pBufferData[lLmIndex].padding.n;
            lLmDescOrig.padding.s = mpSelectedScenario->pBufferData[lLmIndex].padding.s;
            lLmDescOrig.chunkE0Span = (lLmDescOrig.chunkWidth + lLmDescOrig.padding.e + lLmDescOrig.padding.w)*RetE0SizeInBytes(&lLmDescOrig.e0);

            ACF_LocalMemDesc lLmDescNew = lLmDescOrig;
            lLmDescNew.chunkWidth = lChunkWidth;
            lLmDescNew.chunkHeight = lChunkHeight;
            lLmDescNew.chunkE0Span = (lLmDescNew.chunkWidth + lLmDescNew.padding.e + lLmDescNew.padding.w)*RetE0SizeInBytes(&lLmDescNew.e0);

            if (lpPortInfoApu->IsCmem())
            {
               int32_t lCmemReq = mpSelectedScenario->cmemReq - RetLocalMemDescSizeInBytes(&lLmDescOrig) + RetLocalMemDescSizeInBytes(&lLmDescNew);
               if (lCmemReq <= mCmemHeapSizeInBytes)
               {
                  mpSelectedScenario->pBufferData[lLmIndex].chunkWidth = lChunkWidth;
                  mpSelectedScenario->pBufferData[lLmIndex].chunkHeight = lChunkHeight;
                  mpSelectedScenario->cmemReq = lCmemReq;
                  lRetVal = 0;
               }
               else
               {
                  printf("ACF_Process_APU::OverridePortChunkSize -> Given the selected scenario, changing the chunk size of port %s to %d x %d exceeds available CMEM by %d bytes\n",
                         lPortIdentifier.c_str(), lChunkWidth, lChunkHeight, lCmemReq-mCmemHeapSizeInBytes);
               }
            }
            else //DMEM
            {
               int32_t lDmemReq = mpSelectedScenario->dmemReq - RetLocalMemDescSizeInBytes(&lLmDescOrig) + RetLocalMemDescSizeInBytes(&lLmDescNew);
               if (lDmemReq <= mDmemHeapSizeInBytes)
               {
                  mpSelectedScenario->pBufferData[lLmIndex].chunkWidth = lChunkWidth;
                  mpSelectedScenario->pBufferData[lLmIndex].chunkHeight = lChunkHeight;
                  mpSelectedScenario->dmemReq = lDmemReq;
                  lRetVal = 0;
               }
               else
               {
                  printf("ACF_Process_APU::OverridePortChunkSize -> Given the selected scenario, changing the chunk size of port %s to %d x %d exceeds available DMEM by %d bytes\n",
                         lPortIdentifier.c_str(), lChunkWidth, lChunkHeight, lDmemReq-mDmemHeapSizeInBytes);
               }
            }

            break;
         }
      }

      if (0 == lPortFoundFlag)
      {
         printf("ACF_Process_APU::OverridePortChunkSize -> Couldn't find a port with the identifier %s\n", lPortIdentifier.c_str());
      }
   }

   return lRetVal;
}

void ACF_Process_APU::CfgScenarios(acf_scenario_list* lpScenarioList)
{
   mpScenarioList = lpScenarioList;
}

int32_t ACF_Process_APU::RetCuArrayWidth()
{
   return mCuArrayWidth;
}

int32_t ACF_Process_APU::RetCmemHeapSizeInBytes()
{
   return mCmemHeapSizeInBytes;
}

acf_scenario* ACF_Process_APU::RetSelectedScenario()
{
   return mpSelectedScenario;
}

int32_t ACF_Process_APU::CfgLocalScenario(acf_scenario* lpScenario)
{
   int32_t lRetVal = 0;

   //back up original pointers
   acf_scenario_buffer_data* lpTmpBufferDataPtr = mSelectedScenario.pBufferData;
   acf_scenario_kernel_data* lpTmpKernelDataPtr = mSelectedScenario.pKernelData;
   //struct copy
   mSelectedScenario = *lpScenario;
   //restore original pointers (they were clobbered by the struct copy)
   mSelectedScenario.pBufferData = lpTmpBufferDataPtr;
   mSelectedScenario.pKernelData = lpTmpKernelDataPtr;

   //allocate memory for bufferdata and kerneldata if it has not been done yet
   if (0 == mSelectedScenario.pBufferData && 0 == mSelectedScenario.pKernelData)
   {
      mSelectedScenario.pBufferData = new acf_scenario_buffer_data[lpScenario->scenarioBufferDataSizeInBytes/sizeof(acf_scenario_buffer_data)];
      mSelectedScenario.pKernelData = new acf_scenario_kernel_data[lpScenario->scenarioKernelDataSizeInBytes/sizeof(acf_scenario_kernel_data)];

      if ((0 == mSelectedScenario.pBufferData) || (0 == mSelectedScenario.pKernelData))
      {
         CleanupLocalScenario();
         lRetVal = 1;
      }
   }

   //copy bufferdata and kerneldata 'data'
   memcpy((void*)mSelectedScenario.pBufferData, (void*)lpScenario->pBufferData, lpScenario->scenarioBufferDataSizeInBytes);
   memcpy((void*)mSelectedScenario.pKernelData, (void*)lpScenario->pKernelData, lpScenario->scenarioKernelDataSizeInBytes);

   return lRetVal;
}

void ACF_Process_APU::CleanupLocalScenario()
{
   if (mSelectedScenario.pBufferData) delete[] mSelectedScenario.pBufferData;
   mSelectedScenario.pBufferData = 0;
   if (mSelectedScenario.pKernelData) delete[] mSelectedScenario.pKernelData;
   mSelectedScenario.pKernelData = 0;
}

int32_t ACF_Process_APU::AllocateHwResources(uint32_t* lpUserId, uint32_t lResReqArray[][4], uint32_t lResAcqArray[][5], int32_t lNumResReq)
{
   int32_t lRetVal = ACF_SUCCESS;

   if(LIB_SUCCESS == ResMgr_User_Allocate(UserTypeId(USER__ACF), lpUserId))
   {
      if(LIB_SUCCESS == ResMgr_Resource_Allocate_II(*lpUserId, lResReqArray, lNumResReq, lResAcqArray, lNumResReq))
      {
         //allocations successful
      }
      else //resource allocation failed
      {
         ResMgr_User_Deallocate(*lpUserId); //deallocate user
         lRetVal = ACF_HW_RESOURCE_ERROR;
      }
   }
   else //failed to allocate a user slot
   {
      lRetVal = ACF_HW_RESOURCE_ERROR;
   }

   return lRetVal;
}

int32_t ACF_Process_APU::AllocateHwResources()
{
   return AllocateHwResources(&mUserId, mResReqArray, mResAcqArray, mNumResReq);
}

int32_t ACF_Process_APU::DeallocateHwResources(uint32_t lUserId, uint32_t lResAcqArray[][5], int32_t lNumResReq)
{
   int lRetVal = ACF_ERROR;
   
   if (LIB_SUCCESS == ResMgr_Resource_Deallocate(lUserId, lResAcqArray, lNumResReq))
   {
      if (LIB_SUCCESS == ResMgr_User_Deallocate(lUserId))
      {
         lRetVal = ACF_SUCCESS;
      }
   }

   return lRetVal;
}

int32_t ACF_Process_APU::DeallocateHwResources()
{
   return DeallocateHwResources(mUserId, mResAcqArray, mNumResReq);
}

void ACF_Process_APU::FlushAndInvalidateAllIO()
{
#if defined(__STANDALONE__) || defined(__INTEGRITY__)
   for (int32_t i=0; i<(int32_t)mPortInfoVec.size(); i++)
   {
      if (mPortInfoVec[i].mDataDesc.RetDataPtrPhys() != NULL)
      {
         OAL_MemoryFlushAndInvalidate((void *)((int64_t)mPortInfoVec[i].mDataDesc.RetDataPtrPhys() & 0x00000000FFFFFFFF),
                                     mPortInfoVec[i].mDataDesc.RetSpan() * mPortInfoVec[i].mDataDesc.RetElementDimY() * mPortInfoVec[i].mDataDesc.RetHeight());
      }
      if (mPortInfoVec[i].IsIndirect() && mPortInfoVec[i].mOffsetArray.RetDataPtrPhys() != NULL)
      {
        OAL_MemoryFlushAndInvalidate((void *)((int64_t)mPortInfoVec[i].mOffsetArray.RetDataPtrPhys() & 0x00000000FFFFFFFF),
                                    mPortInfoVec[i].mOffsetArray.RetSpan() * mPortInfoVec[i].mDataDesc.RetElementDimY() * mPortInfoVec[i].mOffsetArray.RetHeight());
      }
   }
#else
   for (int32_t i=0; i<(int32_t)mPortInfoVec.size(); i++)
   {
      if (mPortInfoVec[i].mDataDesc.RetDataPtr() != NULL)
      {
         OAL_MemoryFlushAndInvalidate((void *)((int64_t)mPortInfoVec[i].mDataDesc.RetDataPtr()),
                                     mPortInfoVec[i].mDataDesc.RetSpan() * mPortInfoVec[i].mDataDesc.RetElementDimY() * mPortInfoVec[i].mDataDesc.RetHeight());
      }
      if (mPortInfoVec[i].IsIndirect() && mPortInfoVec[i].mOffsetArray.RetDataPtr() != NULL)
      {
         OAL_MemoryFlushAndInvalidate((void *)((int64_t)mPortInfoVec[i].mOffsetArray.RetDataPtr()),
                                     mPortInfoVec[i].mOffsetArray.RetSpan() * mPortInfoVec[i].mDataDesc.RetElementDimY() * mPortInfoVec[i].mOffsetArray.RetHeight());
      }
   }
#endif
}

void ACF_Process_APU::ReturnDebugValues(int32_t* lpSmemBaseAddrOffset, int32_t* lpPmemBaseAddrOffset, int32_t* lpPmemSizeInBytes)
{
   *lpSmemBaseAddrOffset = mSmemBaseAddrOffset;
   *lpPmemBaseAddrOffset = mPmemBaseAddrOffset;
   *lpPmemSizeInBytes = mPmemSizeInBytes;
}

//For now, ACF will take ownership of as many resources as it can for a given configuration
//(even if it cannot necessarily utilize them all).  For example, if a process is executing with the
//ACF_APU_CFG__APEX0_APU_0_CU_0_63_SMEM_0_3 configuration ACF will take everything (all DMAs, STREAMS, MCE, etc.).
//In more advanced cases the decision about which resources to give a specific process will depend on a number of
//factors and may require user intervention to get the optimal resource allocation.
void CfgResSet_321_ALL(acf_res_info* lpAcfResInfo)
{
   lpAcfResInfo->numDmaChIn = 2;
      lpAcfResInfo->dmaChIn[0] = 0;
      lpAcfResInfo->dmaChIn[1] = 1;

   lpAcfResInfo->numStreamInChForDma = 1;
      lpAcfResInfo->streamInChForDma[0] = 1;

   lpAcfResInfo->numDmaChOut = 2;
      lpAcfResInfo->dmaChOut[0] = 2;
      lpAcfResInfo->dmaChOut[1] = 3;

   lpAcfResInfo->numStreamOutChForDma = 1;
      lpAcfResInfo->streamOutChForDma[0] = 0;

   lpAcfResInfo->numMceChIn = 1;
      lpAcfResInfo->mceChIn[0] = 0;

   lpAcfResInfo->numStreamInForMce = 1;
      lpAcfResInfo->streamInChForMce[0] = 0;

   lpAcfResInfo->numFixedSeqRes = 20;
      for (int i=0; i<20; i++)
         lpAcfResInfo->fixedSeqRes[i] = i;

   lpAcfResInfo->numProcIntSeqRes = 3;
      lpAcfResInfo->procIntSeqRes[0] = 1;
      lpAcfResInfo->procIntSeqRes[1] = 2;
      lpAcfResInfo->procIntSeqRes[2] = 3;

   lpAcfResInfo->zeroSeqRes_Done = 30;
   lpAcfResInfo->procIdSeqRes = 0;
   lpAcfResInfo->apuId = 0;
}

void CfgResSet_642_ALL(acf_res_info* lpAcfResInfo)
{
   lpAcfResInfo->numDmaChIn = 4;
      lpAcfResInfo->dmaChIn[0] = 0;
      lpAcfResInfo->dmaChIn[1] = 1;
      lpAcfResInfo->dmaChIn[2] = 2;
      lpAcfResInfo->dmaChIn[3] = 3;

   lpAcfResInfo->numStreamInChForDma = 2;
      lpAcfResInfo->streamInChForDma[0] = 2;
      lpAcfResInfo->streamInChForDma[1] = 3;

   lpAcfResInfo->numDmaChOut = 4;
      lpAcfResInfo->dmaChOut[0] = 4;
      lpAcfResInfo->dmaChOut[1] = 5;
      lpAcfResInfo->dmaChOut[2] = 6;
      lpAcfResInfo->dmaChOut[3] = 7;

   lpAcfResInfo->numStreamOutChForDma = 2;
      lpAcfResInfo->streamOutChForDma[0] = 0;
      lpAcfResInfo->streamOutChForDma[1] = 1;

   lpAcfResInfo->numMceChIn = 2;
      lpAcfResInfo->mceChIn[0] = 0;
      lpAcfResInfo->mceChIn[1] = 1;

   lpAcfResInfo->numStreamInForMce = 2;
      lpAcfResInfo->streamInChForMce[0] = 0;
      lpAcfResInfo->streamInChForMce[1] = 1;

   lpAcfResInfo->numFixedSeqRes = 20;
      for (int i=0; i<20; i++)
         lpAcfResInfo->fixedSeqRes[i] = i;

   lpAcfResInfo->numProcIntSeqRes = 3;
      lpAcfResInfo->procIntSeqRes[0] = 1;
      lpAcfResInfo->procIntSeqRes[1] = 2;
      lpAcfResInfo->procIntSeqRes[2] = 3;

   lpAcfResInfo->zeroSeqRes_Done = 30;
   lpAcfResInfo->procIdSeqRes = 0;
   lpAcfResInfo->apuId = 0;
}

void CfgResSet_642_HALF_APU0(acf_res_info* lpAcfResInfo)
{
   lpAcfResInfo->numDmaChIn = 2;
      lpAcfResInfo->dmaChIn[0] = 0;
      lpAcfResInfo->dmaChIn[1] = 1;

   lpAcfResInfo->numStreamInChForDma = 1;
      lpAcfResInfo->streamInChForDma[0] = 2;

   lpAcfResInfo->numDmaChOut = 2;
      lpAcfResInfo->dmaChOut[0] = 2;
      lpAcfResInfo->dmaChOut[1] = 3;

   lpAcfResInfo->numStreamOutChForDma = 1;
      lpAcfResInfo->streamOutChForDma[0] = 0;

   lpAcfResInfo->numMceChIn = 1;
      lpAcfResInfo->mceChIn[0] = 0;

   lpAcfResInfo->numStreamInForMce = 1;
      lpAcfResInfo->streamInChForMce[0] = 0;

   lpAcfResInfo->numFixedSeqRes = 10;
      for (int i=0; i<10; i++)
         lpAcfResInfo->fixedSeqRes[i] = i;

   lpAcfResInfo->numProcIntSeqRes = 3;
      lpAcfResInfo->procIntSeqRes[0] = 1;
      lpAcfResInfo->procIntSeqRes[1] = 2;
      lpAcfResInfo->procIntSeqRes[2] = 3;

   lpAcfResInfo->zeroSeqRes_Done = 30;
   lpAcfResInfo->procIdSeqRes = 0;
   lpAcfResInfo->apuId = 0;
}

void CfgResSet_642_HALF_APU1(acf_res_info* lpAcfResInfo)
{
   lpAcfResInfo->numDmaChIn = 2;
      lpAcfResInfo->dmaChIn[0] = 4;
      lpAcfResInfo->dmaChIn[1] = 5;

   lpAcfResInfo->numStreamInChForDma = 1;
      lpAcfResInfo->streamInChForDma[0] = 3;

   lpAcfResInfo->numDmaChOut = 2;
      lpAcfResInfo->dmaChOut[0] = 6;
      lpAcfResInfo->dmaChOut[1] = 7;

   lpAcfResInfo->numStreamOutChForDma = 1;
      lpAcfResInfo->streamOutChForDma[0] = 1;

   lpAcfResInfo->numMceChIn = 1;
      lpAcfResInfo->mceChIn[0] = 1;

   lpAcfResInfo->numStreamInForMce = 1;
      lpAcfResInfo->streamInChForMce[0] = 1;

   lpAcfResInfo->numFixedSeqRes = 10;
      for (int i=0; i<10; i++)
         lpAcfResInfo->fixedSeqRes[i] = 10+i;

   lpAcfResInfo->numProcIntSeqRes = 3;
      lpAcfResInfo->procIntSeqRes[0] = 4;
      lpAcfResInfo->procIntSeqRes[1] = 5;
      lpAcfResInfo->procIntSeqRes[2] = 6;

   lpAcfResInfo->zeroSeqRes_Done = 31;
   lpAcfResInfo->procIdSeqRes = 1;
   lpAcfResInfo->apuId = 1;
}
