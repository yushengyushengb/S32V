/**************************************************************************************************
 * 
 * NXP Confidential Proprietary
 *
 * Copyright 2013-2017 NXP 
 * All Rights Reserved
 *
 *****************************************************************************
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
 **************************************************************************************************/

/***************************************************************************/
/* Include files. */
// Add include files here
#include <gdc_ldw_app.hpp>
#include <oal_protected.h>
#include "global_errors.h"
#include <ShowMessage.h>
#include <stdint.h>
#include <stdlib.h>

/***************************************************************************/
/**
 * \details
 * This function is called during the startup sequence;
 * it is the 3rd parties' responsibility to provide a definition for it.
 *
 * It shall be called by startup code once our own initialization is complete.
 *
 * It offers a 3rd party the opportunity to execute their initialization code
 * and start tasks within the initialization sequence.
 *
 **************************************************************************/
void UserStartupTask()
{
  LIB_RESULT libResult = LIB_FAILURE;

  GdcLdw_App gGdcLdw_App;

  libResult = gGdcLdw_App.Start();
  SHOW_ERROR(libResult == LIB_SUCCESS);
}

#ifndef APEX2_EMULATE
#include "apex.h"
#include <oal.h>
#endif

#include <common_helpers.h>
#include <string>

int main(int argc, char** argv)
{
  std::string helpMsg =
      std::string("Demonstrates the Lane Departure warning application on APEX with camera input.\n\tUsage: ") +
      COMMON_ExtractProgramName(argv[0]);
  int idxHelp = COMMON_HelpMessage(argc, argv, helpMsg.c_str());
  if(idxHelp > 0)
  {
    //found help in application arguments thus exiting application
    return -1;
  }

  APEX_Init();

  UserStartupTask();

  APEX_Deinit();

  return 0;
}
