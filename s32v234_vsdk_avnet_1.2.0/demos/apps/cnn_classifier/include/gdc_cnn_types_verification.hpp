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

#ifndef GDCCNNTYPESVERIFICATION_HPP
#define GDCCNNTYPESVERIFICATION_HPP


/***************************************************************************/
/* Include files. */
#include "gdc_cnn_types.hpp"


/*!*********************************************************************************
*  @file
*  @brief Support functions for this application.
*
*  This file contains support classes and functions related to the application verification
*
***********************************************************************************/

//**************************************************************************/
// Literals & definitions



//**************************************************************************/
// Class declaration.



/*!*********************************************************************************
*  @brief Class used to write or read output sequence to/from files.
 */
class GdcCnn_OutputFile
{
public:
   GdcCnn_OutputFile();
   ~GdcCnn_OutputFile();

   LIB_RESULT Open(const char* const cpcFilenameWrite,
                   const char* const cpcFilenameRead);

   LIB_RESULT Close();

protected:
   FILE* mpFileWrite;
   FILE* mpFileRead;
};




/*!*********************************************************************************
*  @brief structure storing output values generated by the algorithm for one image.
 *  \details The output structure is used for regression testing.
 *  It is used to store the output for a video sequence and/or compare
 *  a reference output to the current output if modification were made to the algorithm.
 */
struct GdcCnn_Output_HarrisCorners
{
   uint32_t               mSceneCounter;
   void*                  mhFeatureDescriptorOal;
   icp::FeatureDescriptor mFeatureDescriptor;
   bool                   mWeFreeBuffers;

public:
   GdcCnn_Output_HarrisCorners();
   ~GdcCnn_Output_HarrisCorners();
};



bool operator==(const icp::Feature& rcLeft, const icp::Feature& rcRight);
bool operator==(const GdcCnn_Output_HarrisCorners& rcLeft, const GdcCnn_Output_HarrisCorners& rcRight);



/*!*********************************************************************************
*  @brief Class used to write or read output sequence to/from files.
 */
class GdcCnn_OutputFile_HarrisCorners : public GdcCnn_OutputFile
{
public:
   GdcCnn_OutputFile_HarrisCorners();
   ~GdcCnn_OutputFile_HarrisCorners();

   LIB_RESULT Write(GdcCnn_Output_HarrisCorners& rOutput);

   LIB_RESULT Read(GdcCnn_Output_HarrisCorners& rOutput);
};



/*!*********************************************************************************
*  @brief structure storing output values generated by the algorithm for one image.
 *  \details The output structure is used for regression testing.
 *  It is used to store the output for a video sequence and/or compare
 *  a reference output to the current output if modification were made to the algorithm.
 */
struct GdcCnn_Output_PyramidMultiCreation
{
   uint32_t            mSceneCounter;
   void*               mhImagePyramidOal[gcDepthOfImagePyramid];
   icp::DataDescriptor mImagePyramidDd[gcDepthOfImagePyramid];
   bool                mWeFreeBuffers;

public:
   GdcCnn_Output_PyramidMultiCreation();
   ~GdcCnn_Output_PyramidMultiCreation();
};



bool operator==(const GdcCnn_Output_PyramidMultiCreation& rcLeft, const GdcCnn_Output_PyramidMultiCreation& rcRight);



/*!*********************************************************************************
*  @brief Class used to write or read output sequence to/from files.
 */
class GdcCnn_OutputFile_PyramidMultiCreation : public GdcCnn_OutputFile
{
public:
   GdcCnn_OutputFile_PyramidMultiCreation();
   ~GdcCnn_OutputFile_PyramidMultiCreation();

   LIB_RESULT Write(GdcCnn_Output_PyramidMultiCreation& rOutput);

   LIB_RESULT Read(GdcCnn_Output_PyramidMultiCreation& rOutput);
};


/*!*********************************************************************************
*  @brief structure storing output values generated by the algorithm for one image.
 *  \details The output structure is used for regression testing.
 *  It is used to store the output for a video sequence and/or compare
 *  a reference output to the current output if modification were made to the algorithm.
 */
struct GdcCnn_Output_LKTrackerOpticalFlow
{
   uint32_t                  mSceneCounter;
   icp::Feature32SDescriptor mFeature32SDescriptor;
   bool                      mWeFreeBuffers;

public:
   GdcCnn_Output_LKTrackerOpticalFlow();
   ~GdcCnn_Output_LKTrackerOpticalFlow();
};



bool operator==(const icp::Feature32S& rcLeft, const icp::Feature32S& rcRight);
bool operator==(const GdcCnn_Output_LKTrackerOpticalFlow& rcLeft, const GdcCnn_Output_LKTrackerOpticalFlow& rcRight);



/*!*********************************************************************************
*  @brief Class used to write or read output sequence to/from files.
 */
class GdcCnn_OutputFile_LKTrackerOpticalFlow : public GdcCnn_OutputFile
{
public:
   GdcCnn_OutputFile_LKTrackerOpticalFlow();
   ~GdcCnn_OutputFile_LKTrackerOpticalFlow();

   LIB_RESULT Write(GdcCnn_Output_LKTrackerOpticalFlow& rOutput);

   LIB_RESULT Read(GdcCnn_Output_LKTrackerOpticalFlow& rOutput);
};



/*!*********************************************************************************
*  @brief structure storing output values generated by the algorithm for one image.
 *  \details The output structure is used for regression testing.
 *  It is used to store the output for a video sequence and/or compare
 *  a reference output to the current output if modification were made to the algorithm.
 */
struct GdcCnn_Output_FeatureTracking
{
   uint32_t               mSceneCounter;
   uint32_t               mNumberOfDetectedFeatures;
   GdcCnn_TrackedFeature** mppTrackedFeatures;
   bool                   mWeFreeBuffers;

public:
   GdcCnn_Output_FeatureTracking();
   ~GdcCnn_Output_FeatureTracking();
};



bool operator==(const GdcCnn_TrackedFeature& rcLeft, const GdcCnn_TrackedFeature& rcRight);
bool operator==(const GdcCnn_Output_FeatureTracking& rcLeft, const GdcCnn_Output_FeatureTracking& rcRight);



/*!*********************************************************************************
*  @brief Class used to write or read output sequence to/from files.
 */
class GdcCnn_OutputFile_FeatureTracking : public GdcCnn_OutputFile
{
public:
   GdcCnn_OutputFile_FeatureTracking();
   ~GdcCnn_OutputFile_FeatureTracking();

   LIB_RESULT Write(GdcCnn_Output_FeatureTracking& rOutput);

   LIB_RESULT Read(GdcCnn_Output_FeatureTracking& rOutput);
};



/*!*********************************************************************************
*  @brief Class used to gather utility function needed by the verification application or its tasks.
 */
namespace GdcCnn_Helper
{
   void PrintMismatch_HarrisCorners(FILE* const cpFile,
                                    const GdcCnn_Output_HarrisCorners& rcLocalOutput,
                                    const GdcCnn_Output_HarrisCorners& rcReferenceOutput);

   void PrintMismatch_PyramidMultiCreation(FILE* const cpFile,
                                           const GdcCnn_Output_PyramidMultiCreation& rcLocalOutput,
                                           const GdcCnn_Output_PyramidMultiCreation& rcReferenceOutput);

   void PrintMismatch_LKTrackerOpticalFlow(FILE* const cpFile,
                                           const GdcCnn_Output_LKTrackerOpticalFlow& rcLocalOutput,
                                           const GdcCnn_Output_LKTrackerOpticalFlow& rcReferenceOutput);

   void PrintMismatch_FeatureTracking(FILE* const cpFile,
                                      const GdcCnn_Output_FeatureTracking& rcLocalOutput,
                                      const GdcCnn_Output_FeatureTracking& rcReferenceOutput);

   bool LessThan(const icp::Feature& rcLeft,
                 const icp::Feature& rcRight);

   bool LessThan32S(const icp::Feature32S& rcLeft,
                    const icp::Feature32S& rcRight);
}


#endif /* GDCCNNTYPESVERIFICATION_HPP */
