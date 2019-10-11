/*****************************************************************************
* 
* NXP Confidential Proprietary
*
* Copyright (c) 2015-2016 Freescale Semiconductor
* Copyright 2017 NXP 
* All Rights Reserved
*
******************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************/

/*!*********************************************************************************
*  @file
*
***********************************************************************************/

#ifndef GDCPEDESTRIANDETECTIONTYPES_HPP
#define GDCPEDESTRIANDETECTIONTYPES_HPP

#define MAX_OF(x, y) (((x) > (y)) ? (x) : (y))
#define PRINT_MESSAGES
/***************************************************************************/
/* Include files. */
#include "gdc_pd_configuration.hpp"
#include "gdc_pd_messages.hpp"
#include "GDC_OAL_Semaphore.hpp"
#include "frame_io_types.h"
#if !defined(__CYGWIN__) && !defined(_WIN32)
#include "sdi.hpp"
#ifdef __STANDALONE__
#include "frame_output_dcu.h"
typedef io::FrameOutputDCU io_FrameOutput_t;
#else
#include "frame_output_v234fb.h"
typedef io::FrameOutputV234Fb io_FrameOutput_t;
#endif
#endif // #if defined(__CYGWIN__) || defined(_WIN32)
#include "acf_process_apu.h"
#include "umat.hpp"
#include "frame_io_types.h"
#include "oal.h"
#include <global_errors.h>
#include "common_time_measure.h"
#include <time.h>
#include <vector>
#include <stdint.h>
#include <stdio.h>

#include <apexcv_pro_aggcf_pd.h>

class GdcPd_ImageReply;
class GdcPd_DetectorData;
class GdcPd_CompositionData;


/*!*********************************************************************************
*  @file
*  @brief Support functions for this application.
*
*  This file contains support classes and functions related to this application
*
***********************************************************************************/

//**************************************************************************/
// Literals & definitions
#define SHOW_ERROR(expr) if(!(expr)) { printf("%s : %s [%d]\n", __FILE__, __PRETTY_FUNCTION__, __LINE__); }

//#define GDC_TRACE fprintf(stderr, "%s - %u\n", __PRETTY_FUNCTION__, __LINE__);
#define GDC_TRACE


//**************************************************************************/
// Class declaration.
struct ROI
{
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    int32_t score_low;
    int32_t score_high;
    double h_scale;
    double v_scale;
    int32_t s_width;
    int32_t s_height;
    uint32_t mDetectionCounter;
    uint32_t mResolutionDetectionCounters[gcNumberOfRealScales]; // 11 corresponds to gcNumberOfSceneResizes
};


// Class declaration.
class GdcPd_MovingAverage
{
public:
   GdcPd_MovingAverage();
   ~GdcPd_MovingAverage();

   void Initialize(const uint32_t cCount_Max);
   uint64_t Update(const uint64_t cNewValue); // Returns new average
   uint64_t Get() const;

private:
   uint64_t mSum;
   uint64_t mOldestValue;
   uint32_t mCount_Current;
   uint32_t mCount_Max;
};


class GdcPd_FrameSize
{
public:
   GdcPd_FrameSize();
   GdcPd_FrameSize(const uint32_t cWidth,
                   const uint32_t cHeight);
  ~GdcPd_FrameSize();

  uint32_t Area() const;

public:
  uint32_t mWidth;
  uint32_t mHeight;
  uint32_t mSpan;
};



#if defined(__CYGWIN__) || defined(_WIN32)

class io_FrameOutput_t
{
public:
   void Init( uint32_t aWidth,
              uint32_t aHeight,
              io::IO_DATA_DEPTH aDepth,
              io::IO_DATA_CHANNELS aChannels,
              uint32_t aFormat = 0);

   void PutFrame(void *frame, bool aInvalidateCache);
};

#endif



/*
 *  \brief Class which hides the complexities of the io::FrameOutputV234Fb class
 *
 */
class GdcPd_Composition
{
public:
   GdcPd_Composition();
   ~GdcPd_Composition();

   LIB_RESULT Initialize();
   LIB_RESULT Deinitialize();

   LIB_RESULT PutFrame(GdcPd_DetectorData& rData);

private:
   GdcPd_MovingAverage mMovingAverage_Scene;
   GdcPd_MovingAverage mMovingAverage_LuvApexCv;
   GdcPd_MovingAverage mMovingAverage_1stOctaveApexCv;
   GdcPd_MovingAverage mMovingAverage_NthOctaveApexCv;
   GdcPd_MovingAverage mMovingAverage_detector;
   GdcPd_MovingAverage mMovingAverage_FramePeriod;
   uint64_t mFrameTicks;

   bool mIsInitialized;
};



typedef void* GdcPd_TCB; ///< opaque value returned to the task creator to be used when referring to a task
const uint32_t gcGdcPdTaskNameMaximumSizeInChar = 32;
const char gcGdcPdTaskSemaphoreThreadSafetyName[] = "TaskTS";


class GdcPd_Task  // Abstract Task Class
{
/**
*  \addtogroup GdcPd_Task OAL Task
*  @{
*/
public:
   /***************************************************************************/
   /**
    * \details
    * This function initializes the data members of the object
    *
    **************************************************************************/
   GdcPd_Task();



   /***************************************************************************/
   /**
    * \details
    * This function frees any outstanding resources in the objects possession.
    *
    **************************************************************************/
   virtual ~GdcPd_Task();



   /***************************************************************************/
   /**
    * \details
    * This function creates and activates a new task.
    * It is equivalent to calling "Init" and "Activate".
    *
    *
    * \param  cStackSizeInBytes - [in] Size in bytes of the tasks stack
    * \param  cTaskPriority     - [in] Specifies a priority value between 0 and 255.
    *                             The lower the numeric value, the higher the tasks priority.
    * \param  cTaskName         - [in] Pointer to a 31 character name for the task.
    *                             This name is shared by the task and its default message queue.
    *                             For name registration to succeed this name must be unique.
    *
    *
    * \return
    *    - #LIB_SUCCESS
    *    - #LIB_FAILURE
    *    - #OAL_ERR_LOG_EINVALIDPARAM
    **************************************************************************/
   LIB_RESULT Spawn(const uint32_t cStackSizeInBytes,
                    const uint32_t cTaskPriority,
                    const char   cTaskName[]);


   /***************************************************************************/
   /**
   * \details
   * This function waits for the thread to finish.
   *
   * \return
   *    - #LIB_SUCCESS
   *    - #LIB_FAILURE
   **************************************************************************/
   LIB_RESULT Join();


   /***************************************************************************/
   /**
    * \details
    * This function causes the task to cease to exist; the stack and control block
    * resources are freed. If the task is safe from deletion, This function will block
    * until the task is made unsafe.
    *
    *
    * \return
    *    - #LIB_SUCCESS
    *    - #LIB_FAILURE
    **************************************************************************/
   LIB_RESULT Delete();


private:
   virtual LIB_RESULT TaskOpen(){ return LIB_SUCCESS; };
   virtual LIB_RESULT TaskService() = 0; // Pure Virtual hence you CANNOT instantiate this class
   virtual LIB_RESULT TaskClose(){ return LIB_SUCCESS; };


private:
   GdcPd_TCB     mTaskControlBlock;
   uint32_t      mStackSizeInBytes;
   uint32_t      mPriority;   // Lower the value; higher the priority
   char          mName[gcGdcPdTaskNameMaximumSizeInChar];
   GDC_OAL_SEMAPHORE mSemaphoreThreadSafety;
   bool          mIsSemaphoreThreadSafetyCreated;
   bool          mIsTaskSpawned;
   bool          mIsTaskFinished;


   //TODO: was void instead of void*...
   static void* TaskEntryRoutine(void* pVoid);

private:
   GdcPd_Task( const GdcPd_Task& );            // Do not implement
   GdcPd_Task& operator=( const GdcPd_Task& ); // Do not implement
}; // End of GdcPd_Task declaration.






/*!*********************************************************************************
*  @brief Class used to gather utility function needed by the application or its tasks.
 */
namespace GdcPd_Helper
{
   /*!*********************************************************************************
    *  @brief Function used to set a logo of RGB24 format buffer
    *
    */
   void SetLogo(int32_t  const cWidthInPixels,
                int32_t  const cHeightInPixels,
                uint32_t const cHorizontalOffsetInPixels,
                uint32_t const cVerticalOffsetInPixels,
                uint8_t* const cpBuffer);

   /*!*********************************************************************************
    *  @brief Function used to render a string of RGB24 formast buffer
    *
    */
   void RenderTextToRgb24Buffer(int32_t const cFrameWidthInPixels,
                                int32_t const cFrameHeightInPixels,
                                uint32_t const cHorizontalOffsetInPixels,
                                uint32_t const cVerticalOffsetInPixels,
                                const uint8_t* const cpText,
                                uint32_t const cTextColor,
                                uint8_t* const cpBuffer,
                                uint32_t const cScale = 1);

   LIB_RESULT CropAndConvertRgb24ToRgb32(vsdk::UMat& rSensorRgb24_umat,
                                         vsdk::UMat& rSceneRgb24_umat,
                                         vsdk::UMat& rSceneRgb32_umat);

   LIB_RESULT CropAndConvertBgr24ToRgb32(vsdk::UMat& rSensorRgb24_umat,
                                         vsdk::UMat& rSceneRgb24_umat,
                                         vsdk::UMat& rSceneRgb32_umat);


   /*!*********************************************************************************
    *  @brief Function used to convert a set of RGB32 pixels to the RGB24 pixel format
    */
   LIB_RESULT ConvertRgb32ToRgb24(vsdk::UMat& rSource_umat,
                                  vsdk::UMat& rDestination_umat);


   /*!*********************************************************************************
    *  @brief Function used to convert a set of RGB32 pixels to the RGB24 pixel format
    */
   LIB_RESULT ConvertRgb24ToRgb32(uint32_t const cFrameWidthInPixels,
                                  uint32_t const cFrameHeightInPixels,
                                  uint8_t* const cpSourceFrame,
                                  uint8_t* const cpDestinationFrame);


   LIB_RESULT ReverseCopyRgb24(void* const    cpDestination,
                               void* const    cpSource,
                               uint32_t const cWidthInPixels,
                               uint32_t const cHeightInPixels);


   /*!*********************************************************************************
    *  @brief Function used to crop a RGB24 image
    */
   LIB_RESULT CropRgb24(uint32_t const       cSourceWidthInPixels,
                        uint32_t const       cSourceHeightInLines,
                        uint32_t const       (* const cpcSourceRoi)[4],  // Left, Top, Width, Height
                        const uint8_t* const cpcSourceFrame,
                              uint8_t* const cpcDestinationFrame);

   /*!*********************************************************************************
    *  @brief Function used to draw a rectangle in an RGB24 image
    */
   LIB_RESULT DrawRectangleRgb24(uint8_t* const     cpFrame,
                                 int32_t  const     cFrameWidthInPixels,
                                 int32_t  const     cFrameHeightInPixels,
                                 const apexcv::bbs& rcRoi,
                                 const uint32_t     cRgb24Color);


   /*!*********************************************************************************
    *  @brief Calculates the optimal sensor region of interest(ROI), based on the scene dimensions
    */
   LIB_RESULT CalculateSensorRoi(const uint32_t  cSensorWidthInPixels,
                                 const uint32_t  cSensorHeightInPixels,
                                 const uint32_t  cSceneWidthInPixels,
                                 const uint32_t  cSceneHeightInPixels,
                        /*out*/  vsdk::Rect&     rRect);


   LIB_RESULT SendRequest(const int32_t cMessageId,
                          const int32_t cSenderQueueId,
                          const int32_t cReceiverQueueId);

   LIB_RESULT SendRequest(const int32_t cMessageId,
                          const int32_t cSenderQueueId,
                          const int32_t cReceiverQueueId,
                          const int32_t cPriority);


   LIB_RESULT SendImageReply(const int32_t  cReceiverQueueId,
                             vsdk::UMat&    rSceneRgb24_umat,
                             const void*    pcSceneRgb24_umat_data,
                             vsdk::UMat&    rSceneRgb32_umat,
                             const void*    pcSceneRgb32_umat_data,
                             const uint32_t cSceneCounter,
                             const uint64_t (&cTicks)[2]);


   LIB_RESULT SendDetectorData(const int32_t             cReceiverQueueId,
                               vsdk::UMat&               rSceneRgb24_umat,
                               const void*               pcSceneRgb24_umat_data,
                               const uint32_t            cSceneCounter,
                               std::vector<apexcv::bbs>& rPedestrianRois,
                               const uint64_t            (&mFeatureTicks)[gcApexCvEndTick],
                               const AcfProfilingInfo    (&cPerAcfProfilingInfo)[gcNumberOfRealScales]);

   LIB_RESULT SendFeatureData(const int32_t          cReceiverQueueId,
                              vsdk::UMat&            rSceneRgb24_umat,
                              const void*            pcSceneRgb24_umat_data,
                              const uint32_t         cSceneCounter,
                              vsdk::UMat*            rOutput_py_umat,
                              const uint64_t         (&cAggcfTicks)[gcApexCvEndTick],
                              const AcfProfilingInfo (&cPerAcfProfilingInfo)[gcNumberOfRealScales]);

   LIB_RESULT SendLUVData(const int32_t           cReceiverQueueId,
                          vsdk::UMat&             rSceneRgb24_umat,
                          const void*             pcSceneRgb24_umat_data,
                          const uint32_t          cSceneCounter,
                          vsdk::UMat&             rSceneLUV_umat,
                          vsdk::UMat*             rOutput_py_umat,
                          const uint64_t          (&cAggcfTicks)[gcApexCvEndTick],
                          const AcfProfilingInfo (&cPerAcfProfilingInfo)[gcNumberOfRealScales]);


   /*!*********************************************************************************
    *  @brief Method used to send a message using inter-task communications
    */
   LIB_RESULT SendCompositionData(const int32_t cReceiverQueueId,
                                  vsdk::UMat&    rSceneRgb24_umat,
                                  const void*    pcSceneRgb24_umat_data);

   LIB_RESULT FreeImageReply(GdcPd_ImageReply* const cpReply);
   LIB_RESULT FreeDetectorData(GdcPd_DetectorData* const cpData);
   LIB_RESULT FreeCompositionData(GdcPd_CompositionData* const cpData);

   GdcPd_SceneTask_Enum ConvertToSceneTaskEnum(const uint32_t cValue);
}

#endif /* GDCPEDESTRIANDETECTIONTYPES_HPP */
