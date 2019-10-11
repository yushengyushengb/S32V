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
*  @file ht_saturate_08s_proc_desc.hpp
*  @brief Process description for hand-tuned saturate filter
***********************************************************************************/
 
#ifndef HTSATURATE08SAPUPROCESSDESC_HPP
#define HTSATURATE08SAPUPROCESSDESC_HPP 
 
#include <acf_process_desc_apu.hpp>
#include "ht_saturate_08s_graph.hpp"



class ht_saturate_08s_apu_process_desc : public ACF_Process_Desc_APU
{
public:
   void Create()
   {
      Initialize(mGraph, "HT_SATURATE_08S");
   }
   
   ht_saturate_08s_graph mGraph;
};
#endif /* HTSATURATE08SAPUPROCESSDESC_HPP */
