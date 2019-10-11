/*****************************************************************************
* 
* NXP Confidential Proprietary
*
* Copyright (c) 2016 Freescale Semiconductor
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

#ifndef AGGCFHISTTI4GRAPH_HPP
#define AGGCFHISTTI4GRAPH_HPP

#include <acf_graph.hpp>
#include "aggcf_acf.h"

class aggcfhistti4_graph : public ACF_Graph
{
public:
   aggcfhistti4_graph() : ACF_Graph()
   {
      GET_KERNEL_HANDLE(&_kernel_info_agg_acfhist_ti_4x4, "agg_acfhist_ti_4x4");
   }

   void Create()
   {
      // Set identifier for graph
      SetIdentifier("aggcfhistti4_graph");

      // add kernels
      AddKernel("AGGCF", "agg_acfhist_ti_4x4");

      // add graph port
      AddInputPort("INPUTM");
      AddInputPort("INPUTO");
      AddInputPort("OFFSET");
      
      AddOutputPort("OUTPUTH1");
      AddOutputPort("OUTPUTH2");
      AddOutputPort("OUTPUTH3");
      AddOutputPort("OUTPUTH4");
      AddOutputPort("OUTPUTH5");
      AddOutputPort("OUTPUTH6");
      AddInputPort("PARAMS");
      
      // specify connections
      Connect(  GraphPort("INPUTM"),                     KernelPort("AGGCF", "INPUTM"));
      Connect(  GraphPort("INPUTO"),                     KernelPort("AGGCF", "INPUTO"));
      Connect(  GraphPort("OFFSET"),                     KernelPort("AGGCF", "OFFSET"));
      Connect(  GraphPort("PARAMS"),                     KernelPort("AGGCF", "PARAMS"));

      Connect(  KernelPort("AGGCF", "OUTPUTH1"),          GraphPort("OUTPUTH1")); 
      Connect(  KernelPort("AGGCF", "OUTPUTH2"),          GraphPort("OUTPUTH2")); 
      Connect(  KernelPort("AGGCF", "OUTPUTH3"),          GraphPort("OUTPUTH3")); 
      Connect(  KernelPort("AGGCF", "OUTPUTH4"),          GraphPort("OUTPUTH4")); 
      Connect(  KernelPort("AGGCF", "OUTPUTH5"),          GraphPort("OUTPUTH5")); 
      Connect(  KernelPort("AGGCF", "OUTPUTH6"),          GraphPort("OUTPUTH6")); 

   }
};



#endif /* AGGCFHISTTI4GRAPH_HPP */

