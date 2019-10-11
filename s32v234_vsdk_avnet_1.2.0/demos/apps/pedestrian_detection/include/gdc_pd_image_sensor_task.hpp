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

#ifndef GDCPDIMAGESENSORTASK_HPP
#define GDCPDIMAGESENSORTASK_HPP

#include "gdc_pd_types.hpp"
#include "apexcv_pro_resize.h"
#include "global_errors.h"
#include <stdint.h>



//**************************************************************************/
// Literals & definitions



//**************************************************************************/
// Class declaration.

/*
 *  \brief GdcPd_ImageSensorTask
 *
 */
class GdcPd_ImageSensorTask : public GdcPd_Task
{
public:
   GdcPd_ImageSensorTask();
   virtual ~GdcPd_ImageSensorTask();

   LIB_RESULT Configure(const int32_t cReceiveMessageQueueId,
                        const int32_t cResizeTaskMessageQueueId,
                        const  int32_t cSceneWidthInPixels,
                        const  int32_t cSceneHeightInPixels,
                        const uint32_t cSceneBitsPerPixel,
                        const uint32_t cScenePaddingInBytes);

private:
   int32_t mReceiveMessageQueueId;
   int32_t mFeatureDetectorTaskMessageQueueId;
   bool    mIsTaskClosing;
   bool    mIsConfigured;

   //
   // Used to capture images from the sensor
   //
   sdi_grabber mSdiGrabber;

   //
   // Used to convert captured image into the resolution and image format needed by the algorithm
   //
   vsdk::Rect mRect;

   uint32_t            mSceneCounter;
   uint32_t            mImageSensorWidthInPixels;
   uint32_t            mImageSensorHeightInPixels;
   uint32_t            mImageSensorBitsPerPixel;

   uint32_t            mSceneWidthInPixels;
   uint32_t            mSceneHeightInPixels;
   uint32_t            mSceneBitsPerPixel;
   uint32_t            mScenePaddingInBytes;

public:
   /*!*********************************************************************************
    *  @brief Method called in the context of the spawned task, contains initialization code.
    */
   LIB_RESULT TaskOpen();

   /*!*********************************************************************************
    *  @brief Method called in the context of the spawned task, contains the main body.
    */
   LIB_RESULT TaskService();

   /*!*********************************************************************************
    *  @brief Method called in the context of the spawned task, contains the uninitialization code.
    */
   LIB_RESULT TaskClose();

private:
   LIB_RESULT HandleImageRequest();

private:
   GdcPd_ImageSensorTask( const GdcPd_ImageSensorTask& );            // Do not implement
   GdcPd_ImageSensorTask& operator=( const GdcPd_ImageSensorTask& ); // Do not implement
};

#endif /* GDCPDIMAGESENSORTASK_HPP */


