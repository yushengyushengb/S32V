#ifndef _ACF_PROCESS_APU_FIRE10_1ST_E1E3
#define _ACF_PROCESS_APU_FIRE10_1ST_E1E3

#include <acf_process_apu.h>
#include <FIRE10_1ST_E1E3_APU_LOAD.h> //APU load associated with this process
#include <stdint.h>


//SCENARIO LIST*************************************************
static acf_scenario_buffer_data gScenarioBufferData0_FIRE10_1ST_E1E3[] = {{912, 2, 3, 0, {1, 1, 0, 0}}, {14, 1, 1, 1, {0, 0, 0, 0}}, {56, 2, 2, 1, {0, 0, 0, 0}}, {56, 2, 2, 1, {0, 0, 0, 0}}, {64, 45, 1, 0, {0, 0, 0, 0}}, {16, 1, 1, 0, {0, 0, 0, 0}}};

static acf_scenario_kernel_data gScenarioKernelData0_FIRE10_1ST_E1E3[] = {{1, 0}};

static acf_scenario gScenarioArray_FIRE10_1ST_E1E3[] = {
{0, 0, 3384, 10960, 1, gScenarioBufferData0_FIRE10_1ST_E1E3, 96, gScenarioKernelData0_FIRE10_1ST_E1E3, 4}
};

static acf_scenario_list gScenarioList_FIRE10_1ST_E1E3 = {
1, //number of scenarios
gScenarioArray_FIRE10_1ST_E1E3};
//**************************************************************

class FIRE10_1ST_E1E3 : public ACF_Process_APU
{

public:
   FIRE10_1ST_E1E3(int32_t apex_id = 0) : ACF_Process_APU(apex_id)
   {} 

   int32_t Initialize()
   {
      int32_t lRetVal = 0;

      if (!Initialized()) //initialization steps that only need to occur once
      {
         SetProcessIdentifier("FIRE10_1ST_E1E3");
         SetApuLoadInfo(FIRE10_1ST_E1E3_LOAD_SEGMENTS,
                        FIRE10_1ST_E1E3_LOAD_PMEM, FIRE10_1ST_E1E3_LOAD_PMEM_SIZE,
                        FIRE10_1ST_E1E3_LOAD_DMEM, FIRE10_1ST_E1E3_LOAD_DMEM_SIZE,
                        0, 0); //assuming _LOAD_CMEM does not exist

         lRetVal = NonParametricInitialization();
         if (lRetVal != 0) return lRetVal;

         //***NOTE: the order in which the following ports are added is meaningful; do not change!

         AddPort("FIRE10_1ST_E1E3_INPUT_IMAGE", icp::DATATYPE_08S, 1, 1, 912, 2, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
         AddPort("FIRE10_1ST_E1E3_INPUT_WEIGHT", icp::DATATYPE_08S, 1, 1, 64, 45, 0, 0, 1, 0, 1, 0, 4, 0, 0, 0, 0, 0);
         AddPort("FIRE10_1ST_E1E3_INPUT_PARAMS", icp::DATATYPE_08S, 1, 1, 16, 1, 0, 1, 1, 0, 1, 0, 5, 0, 0, 0, 0, 0);
         AddPort("FIRE10_1ST_E1E3_OUTPUT_E1", icp::DATATYPE_08S, 1, 1, 56, 2, 1, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0);
         AddPort("FIRE10_1ST_E1E3_OUTPUT_E3", icp::DATATYPE_08S, 1, 1, 56, 2, 1, 0, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0);

         CfgScenarios(&gScenarioList_FIRE10_1ST_E1E3);

         FlagAsInitialized();
      }

      lRetVal = SelectApuConfiguration(mApuCfg, mApexId); //by default mApuCfg = ACF_APU_CFG__APEX0_DEFAULT and mApexId = 0

      return lRetVal;
   }
};

#endif //_ACF_PROCESS_APU_FIRE10_1ST_E1E3
