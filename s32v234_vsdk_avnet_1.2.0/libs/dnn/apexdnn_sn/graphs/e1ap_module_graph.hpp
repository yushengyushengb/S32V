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
 *  @file e1ap_module_graph.hpp
 *  @brief Graph for E1AP_MODULE
 * ***********************************************************************************/
#ifndef E1APMODULEGRAPH_HPP
#define E1APMODULEGRAPH_HPP

#include <acf_graph.hpp>
#include "apexdnn_sn_acf.h"

class e1ap_module_graph : public ACF_Graph
{
public:
   e1ap_module_graph() : ACF_Graph()
   {
      GET_KERNEL_HANDLE(&_kernel_info_apu_e1ap_module_nhcw_forward, "apu_e1ap_module_nhcw_forward");
   }


   void Create()
   {
      /* set identifier for graph */
      SetIdentifier("e1ap_module_graph");

      /* add kernels */
      AddKernel("APU_E1AP_MODULE", "apu_e1ap_module_nhcw_forward");

      /* add graph port */
      AddInputPort ("E1AP_MODULE_INPUT_IMAGE");
      AddInputPort ("E1AP_MODULE_INPUT_WEIGHT");
      AddInputPort ("E1AP_MODULE_INPUT_ACCM");
      AddInputPort ("E1AP_MODULE_INPUT_PARAMS");
      AddOutputPort("E1AP_MODULE_OUTPUT");

      /* specify connection */
      Connect(GraphPort("E1AP_MODULE_INPUT_IMAGE"),   KernelPort("APU_E1AP_MODULE", "INPUT_IMAGE"));
      Connect(GraphPort("E1AP_MODULE_INPUT_WEIGHT"),  KernelPort("APU_E1AP_MODULE", "INPUT_WEIGHT"));
      Connect(GraphPort("E1AP_MODULE_INPUT_ACCM"),    KernelPort("APU_E1AP_MODULE", "INPUT_ACCM"));
      Connect(GraphPort("E1AP_MODULE_INPUT_PARAMS"),  KernelPort("APU_E1AP_MODULE", "INPUT_PARAMS"));

      Connect(KernelPort("APU_E1AP_MODULE", "OUTPUT"), GraphPort("E1AP_MODULE_OUTPUT"));
   }
};

#endif /* E1APMODULEGRAPH_HPP */

