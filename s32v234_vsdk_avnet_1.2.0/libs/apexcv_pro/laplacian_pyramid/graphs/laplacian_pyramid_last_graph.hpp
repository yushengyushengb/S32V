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

/*==================================================================================================
Revision History:
                              Modification     Tracking
Author (core ID)              Date D/M/Y       Number     Description of Changes
---------------------------   ----------    ------------  ------------------------------------------
Adrian Grigore (nxa11567)     14/12/2016    VSDK-554      Created
---------------------------   ----------    ------------  ------------------------------------------
==================================================================================================*/
/*!*********************************************************************************
*  \file laplacian_pyramid_last_graph.hpp
*  \brief ACF graph for the Laplacian image pyramid creation - last level
***********************************************************************************/
#ifndef LAPLACIANPYRAMIDLASTGRAPH_HPP
#define LAPLACIANPYRAMIDLASTGRAPH_HPP

#include <acf_graph.hpp>
#include "laplacian_acf.h"

class laplacian_pyramid_last_graph : public ACF_Graph
{
public:
   laplacian_pyramid_last_graph() : ACF_Graph()
   {
      GET_KERNEL_HANDLE(&kernel_info_horizontal_gaus_laplacian_last, "horizontal_gaus_laplacian_last");
      GET_KERNEL_HANDLE(&kernel_info_vertical_gaus_laplacian_last, "vertical_gaus_laplacian_last");
   }
   void Create()
   {
      // set identifier for graph
      SetIdentifier("laplacian_pyramid_last_graph");
      
      // add kernels
      AddKernel("GAUS_X",     "horizontal_gaus_laplacian_last");
      AddKernel("GAUS_Y",     "vertical_gaus_laplacian_last");
      
      // add graph ports
      AddInputPort("INPUT");
      AddOutputPort("OUTPUT_PYRAMID");
      AddOutputPort("OUTPUT_RECONSTRUCT");
      
      // specify connections
      Connect( GraphPort("INPUT"),                 KernelPort("GAUS_X", "INPUT"));
      Connect( GraphPort("INPUT"),                 KernelPort("GAUS_Y", "INPUT"));
      Connect( KernelPort("GAUS_X", "OUTPUT"),     KernelPort("GAUS_Y", "INPUT_GAUSS"));
      Connect( KernelPort("GAUS_Y", "OUTPUT"),     GraphPort("OUTPUT_PYRAMID"));
      Connect( KernelPort("GAUS_Y", "OUTPUT_REC"), GraphPort("OUTPUT_RECONSTRUCT"));
   }
   
};


#endif /* LAPLACIANPYRAMIDLASTGRAPH_HPP */


