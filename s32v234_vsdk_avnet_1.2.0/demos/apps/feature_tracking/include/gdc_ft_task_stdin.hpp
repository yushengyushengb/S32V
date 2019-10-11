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

#ifndef GDCFTSTDINTASK_HPP
#define GDCFTSTDINTASK_HPP

#include "gdc_ft_types.hpp"
#include "global_errors.h"
#include <string>
#include <stdint.h>



//**************************************************************************/
// Literals & definitions



//**************************************************************************/
// Class declaration.

/*
 *  \brief GdcCnn_StdinTask
 *
 */
class GdcFt_StdinTask : public GdcFt_Task
{
public:
   GdcFt_StdinTask();
   virtual ~GdcFt_StdinTask();

   LIB_RESULT Configure(const int32_t cReceiveMessageQueueId,
                        const int32_t cResizeTaskMessageQueueId);

private:
   int32_t mReceiveMessageQueueId;
   int32_t mSceneTaskMessageQueueId;
   bool    mIsTaskClosing;
   bool    mIsConfigured;
   
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
   GdcFt_StdinTask( const GdcFt_StdinTask& );            // Do not implement
   GdcFt_StdinTask& operator=( const GdcFt_StdinTask& ); // Do not implement
};

#endif /* GDCFTSTDINTASK_HPP */


