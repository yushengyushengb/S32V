/*****************************************************************************
* 
* NXP Confidential Proprietary
*
* Copyright (c) 2013-2016 Freescale Semiconductor
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
*  @file convolve_scale_5x5_16s_proc_desc.hpp
*  @brief Process description for convolve with scale filter (signed 16 bit)
***********************************************************************************/
#ifndef CONVOLVESCALE5X516SAPUPROCESSDESC_HPP
#define CONVOLVESCALE5X516SAPUPROCESSDESC_HPP

#include <acf_process_desc_apu.hpp>
#include "convolve_scale_5x5_16s_graph.hpp"



class convolve_scale_5x5_16s_apu_process_desc : public ACF_Process_Desc_APU
{
public:
   void Create()
   {
      Initialize(mGraph, "CONVOLVE_SCALE_5X5_16S");
   }
   
   convolve_scale_5x5_16s_graph mGraph;
};
#endif /* CONVOLVESCALE5X516SAPUPROCESSDESC_HPP */

