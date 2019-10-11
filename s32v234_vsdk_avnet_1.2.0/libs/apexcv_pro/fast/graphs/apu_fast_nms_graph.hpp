/*****************************************************************************
* 
* NXP Confidential Proprietary
*
* Copyright (c) 2014-2016 Freescale Semiconductor
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
#ifndef APUFASTNMSGRAPH_HPP
#define APUFASTNMSGRAPH_HPP

#include <acf_graph.hpp>
#include "fast_apu.h"
#include "fast_acf.h"

class apu_fast_nms_graph : public ACF_Graph
{
public:
	const char* m_graphName;
public:
   apu_fast_nms_graph() : ACF_Graph()
   {
      GET_KERNEL_HANDLE(&_kernel_info_fast_offset, "fastx_offsets");
      GET_KERNEL_HANDLE(&_kernel_info_fast_nms, "fast_nms");
      GET_KERNEL_HANDLE(&_kernel_info_nms3x3, "nms3x3");
   }

   void Create()
   {
     // Set identifier for graph
      SetIdentifier("fast_graph_nms");

      // add kernels
      AddKernel("OFFSETS",  "fastx_offsets");
      AddKernel("FAST_NMS",     "fast_nms");
      AddKernel("nms",      "nms3x3");

      // add graph port
      AddInputPort("INPUT");
      AddInputPort("THRESHOLD");
      AddInputPort("CIRCUMFERENCE");
      AddOutputPort("OUTPUT");

      // specify connections
      //connecting offset kernels inputs
      Connect(GraphPort("INPUT"),              KernelPort("OFFSETS", "INPUT_0"));
      Connect(GraphPort("CIRCUMFERENCE"),      KernelPort("OFFSETS", "CIRCUMFERENCE"));

      //connecting offset kernel output into fast kernel input
      Connect(KernelPort("OFFSETS", "OUTPUT_OFFSETS"), KernelPort("FAST_NMS", "OFFSET_TABLE"));
      
      //connecting other fast kernel inputs
      Connect(GraphPort("INPUT"),              KernelPort("FAST_NMS", "INPUT_0"));
      Connect(GraphPort("THRESHOLD"),          KernelPort("FAST_NMS", "THRESHOLD"));

      //NMS
      Connect(KernelPort("FAST_NMS", "OUTPUT_0"),   KernelPort("nms", "input"));

      //connecting fast kernel output to graphs output
      Connect(KernelPort("nms", "output"), GraphPort("OUTPUT"));
   }
};

#endif /* APUFASTNMSGRAPH_HPP */
