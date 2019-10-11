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
/*!
* \file remap_bilinear_apu.h
* \brief element-wise interpolation between pixels of an image for APEX
* \addtogroup remap_bilinear
* @{
****************************************************************************/

#ifndef APUREMAPBILINEARIMPL_H
#define APUREMAPBILINEARIMPL_H

#ifdef APEX2_EMULATE 
#include "apu_lib.hpp" // if using the APU emulation library
using namespace APEX2;
#endif

/*!
remap_bilinear btw the rgb pixels of an image
\brief Elementwise bilinear interpolation 
\param dst		- [Output] unsigned 32bit destination block pointer
\param srcImage0- [Input]  unsigned 32bit source block pointer of img 0
\param offset	- [Input]  unsigned 16bit offsets inside source block pointer of img 0
\param delta	- [Input]  unsigned 8bit deltas inside source block pointer of img 0
\param sstride	- [Input]  Source block width (in elements not bytes) including padding
\param dstride 	- [Input]  Destination block width (in elements not bytes) including padding
\param bw		- [Input]  Block width
\param bh		- [Input]  Block height
*/
void
remap_bilinear_rgb_impl (vec32u* dst, vec32u* src, vec16u* offset, vec08u* delta,
						int sstride, int dstride, int bw, int bh); 

						
						
/*!
remap_bilinear btw the grayscale pixels of an image
\brief Elementwise bilinear interpolation 
\param dst		- [Output] unsigned 8bit destination block pointer
\param srcImage0- [Input]  unsigned 8bit source block pointer of img 0
\param offset	- [Input]  unsigned 16bit offsets inside source block pointer of img 0
\param delta	- [Input]  unsigned 8bit deltas inside source block pointer of img 0
\param sstride 	- [Input]  Source block width (in elements not bytes) including padding
\param dstride 	- [Input]  Destination block width (in elements not bytes) including padding
\param bw		- [Input]  Block width
\param bh		- [Input]  Block height
*/
void
remap_bilinear_grayscale_impl(vec08u* dst, vec08u* src, vec16u* offset, vec08u* delta, 
							  int sstride, int dstride, int bw, int bh);
							  
							  
#endif /* APUREMAPBILINEARIMPL_H */

/*! @} */
