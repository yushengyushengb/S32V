/*****************************************************************************
* 
* NXP Confidential Proprietary
*
* Copyright 2018 NXP 
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
*  @file scharr_y_5x5_08u_graph.hpp
*  @brief ACF graph for scharr y 5x5 (unsigned 8 bit)
***********************************************************************************/
 
#ifndef SCHARRY5X508UGRAPH_HPP
#define SCHARRY5X508UGRAPH_HPP

#include <acf_graph.hpp>
#include "image_filters_acf.h"
#include "graph_templates.h"

class scharr_y_5x5_08u_graph : public ACF_Graph
{
public:
  scharr_y_5x5_08u_graph() : ACF_Graph()
{
    XREGISTER_ACF_KERNEL(SCHARR_Y_5X5_08U_K);
  }
   void Create()
   {
      //set identifier for graph
      SetIdentifier("scharr_y_5x5_08u_graph");
      
      //add kernels
      AddKernel("_scharr_y_5x5_08u", SCHARR_Y_5X5_08U_KN);

      //add graph ports
      AddInputPort(GR_IN_0);

      AddOutputPort(GR_OUT_0);

      //specify connections
      Connect(GraphPort(GR_IN_0),   KernelPort("_scharr_y_5x5_08u", INPUT_0));
      Connect(KernelPort("_scharr_y_5x5_08u", OUTPUT_0), GraphPort(GR_OUT_0));
   }
};

#endif /* SCHARRY5X508UGRAPH_HPP */
