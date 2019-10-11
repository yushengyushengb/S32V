##############################################################################
#
# Freescale Confidential Proprietary
#
# Copyright (c) 2018 NXP Semiconductors;
# All Rights Reserved
#
##############################################################################
#
# THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
# THE POSSIBILITY OF SUCH DAMAGE.
#
##############################################################################
#
#  CONTENT
#    ISP demo for static image
#
#  AUTHOR
#    Armin Strobl
#
#  DATE
#    2018-01-16
#
#  LANGUAGE
#    make
#
##############################################################################

SDK_ROOT := $(call path_relative_to,$(CURDIR),$(CURR_SDK_ROOT))

ARM_APP = isp_static_simple
ISP_GRAPH = static_simple
SEQ_MODE = static
SEQ_FW = $(SEQ_MODE)_$(ISP_GRAPH)

##############################################################################
# ARM_APP
##############################################################################

ARM_DEFS += -DVSDK_UMAT_USE_OPENCV

ARM_APP_SRCS +=                                                              \
    main.cpp 

ARM_INCS +=                                                                  \
    -I$(SDK_ROOT)/platform/s32_v234                                          \
    -I$(OPENCV_ROOT)/include                                                 \
    -I$(SDK_ROOT)/include                                                    \
    -I$(SDK_ROOT)/libs/utils/common/include                                  \
    -I$(SDK_ROOT)/isp/inc                                                    \
    -I$(SDK_ROOT)/libs/io/frame_io/include                                   \
    -I$(SDK_ROOT)/isp/graphs/$(ISP_GRAPH)/inc                                \
    -I$(SDK_ROOT)/libs/io/dcu/include                                        \
    -I../include

ARM_APP_LIBS +=                                                              \
    $(SDK_ROOT)/libs/io/frame_io/$(ODIR)/libframe_io.a                       \
    $(SDK_ROOT)/libs/io/sdi/$(ODIR)/libsdi.a                                 \
    $(SDK_ROOT)/libs/isp/csi/user/$(ODIR)/libcsidrv.a                        \
    $(SDK_ROOT)/libs/isp/cam_generic/user/$(ODIR)/libcamdrv.a                \
    $(SDK_ROOT)/libs/utils/log/$(ODIR)/liblog.a                              \
    $(SDK_ROOT)/libs/isp/sequencer/user/$(ODIR)/libseqdrv.a                  \
    $(SDK_ROOT)/libs/isp/fdma/user/$(ODIR)/libfdmadrv.a                      \
    $(SDK_ROOT)/libs/utils/oal/user/$(ODIR)/liboal.a                         \
    $(SDK_ROOT)/libs/utils/common/$(ODIR)/libcommon.a                        \
    $(SDK_ROOT)/libs/utils/umat/$(ODIR)/libumat.a                            \
    $(SDK_ROOT)/isp/graphs/$(ISP_GRAPH)/$(SEQ_FW)/$(ODIR)/lib$(SEQ_FW).a

ARM_LDOPTS +=                                                                \
    -lopencv_core  

##############################################################################
# STANDALONE SPECIFIC INCLUDES
##############################################################################
ifneq (,$(findstring -sa,$(ODIR)))

ARM_APP_LIBS +=                                                              \
    $(SDK_ROOT)/libs/startup/v234ce_standalone/$(ODIR)/libv234ce.a           \
    $(SDK_ROOT)/libs/io/i2c/$(ODIR)/libi2c.a                                 \
    $(SDK_ROOT)/libs/io/semihost/$(ODIR)/libSemihost.a                       \
    $(SDK_ROOT)/libs/io/uartlinflex_io/$(ODIR)/liblinflex.a                  \
    $(SDK_ROOT)/libs/io/dcu/$(ODIR)/libdcu.a            

ARM_LDOPTS +=                                                                \
    -lzlib                 

##############################################################################
# LINUX SPECIFIC INCLUDES
##############################################################################	    
else

ARM_APP_LIBS +=                                                              \
    $(SDK_ROOT)/libs/isp/jpegdec/user/$(ODIR)/libjpegdecdrv.a                \
    $(SDK_ROOT)/libs/isp/h264enc/user/$(ODIR)/libh264encdrv.a                \
    $(SDK_ROOT)/libs/isp/h264dec/user/$(ODIR)/libh264decdrv.a                \
    $(SDK_ROOT)/libs/isp/viu/user/$(ODIR)/libviudrv.a                        \
    
endif    