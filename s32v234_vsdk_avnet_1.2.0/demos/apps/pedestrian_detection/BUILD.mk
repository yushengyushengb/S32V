##############################################################################
#
# Freescale Confidential Proprietary
#
# Copyright (c) 2016 Freescale Semiconductor;
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

SDK_ROOT := $(call path_relative_to,$(CURDIR),$(CURR_SDK_ROOT))

ARM_APP = gdc_pd
ISP_GRAPH = mipi_simple
SEQ_MODE = dynamic
SEQ_FW = $(SEQ_MODE)_$(ISP_GRAPH)
##############################################################################
# ARM_APP
##############################################################################

VPATH = ../src/lib

ARM_DEFS += -DVSDK_UMAT_USE_OPENCV

ARM_APP_SRCS +=                                            \
    gdc_pd_main.cpp                                        \
    gdc_pd_types.cpp                                       \
    gdc_pd_types_verification.cpp                          \
    gdc_pd_app.cpp                                         \
    gdc_pd_composition_task.cpp                            \
    gdc_pd_display_task.cpp                                \
    gdc_pd_file_reader_task.cpp                            \
    gdc_pd_resize_task.cpp                                 \
    gdc_pd_hog_task.cpp                                    \
    gdc_pd_image_sensor_task.cpp                           \
    gdc_pd_task_stdin.cpp


ARM_INCS +=                                                                  \
    -I$(SDK_ROOT)/demos/apps/pedestrian_detection/include                \
    -I$(SDK_ROOT)/platform/s32_v234                                          \
    -I$(OPENCV_ROOT)/include                                                 \
    -I$(SDK_ROOT)/include                                                    \
	-I$(SDK_ROOT)/libs/utils/umat/include                                    \
	-I$(SDK_ROOT)/libs/utils/oal/user/include                                \
	-I$(SDK_ROOT)/libs/utils/oal/kernel/include                              \
    -I$(SDK_ROOT)/libs/utils/common/include                                  \
    -I$(SDK_ROOT)/isp/inc                                                    \
    -I$(SDK_ROOT)/libs/io/frame_io/include                                   \
    -I$(SDK_ROOT)/isp/graphs/$(ISP_GRAPH)/inc                                \
    -I$(SDK_ROOT)/libs/io/dcu/include                                        \
    -I$(SDK_ROOT)/libs/apex/drivers/user/include                             \
    -I$(SDK_ROOT)/libs/apex/icp/include                                      \
    -I$(SDK_ROOT)/libs/apexcv_pro/blockmatching/$(ODIR)                      \
    -I$(SDK_ROOT)/libs/apexcv_pro/blockmatching/graphs/build-apu-$(APU_COMP)-sa-d    \
    -I$(SDK_ROOT)/libs/apexcv_pro/hog/graphs                                 \
    -I$(SDK_ROOT)/libs/apexcv_pro/hog/$(ODIR)                                \
    -I$(SDK_ROOT)/libs/apexcv_pro/hog/graphs/build-apu-$(APU_COMP)-sa-d              \
    -I$(SDK_ROOT)/libs/io/semihost/include                                   \
    -I$(SDK_ROOT)/libs/apexcv_pro/image_pyramid/graphs/build-apu-$(APU_COMP)-sa-d    \
    -I$(SDK_ROOT)/libs/utils/communications/include                          \
    -I$(SDK_ROOT)/libs/utils/communications/src                              \
    -I$(SDK_ROOT)/libs/apex/common/include                                   \
    -I$(SDK_ROOT)/3rdparty/iniparser4/src                                    \
    -I$(SDK_ROOT)/libs/isp/h264dec/kernel/common/include                     \
    -I$(SDK_ROOT)/libs/isp/h264dec/kernel/linux/include                      \
    -I$(SDK_ROOT)/libs/apexcv_ref/apexcv_pro/resize/include                  \
    -I$(SDK_ROOT)/libs/apexcv_ref/apexcv_pro/hog/include



ARM_APP_LIBS +=                                                                 \
    $(SDK_ROOT)/libs/apexcv_pro/image_pyramid/$(ODIR)/apexcv_pro_pyramid.a \
    $(SDK_ROOT)/libs/io/frame_io/$(ODIR)/libframe_io.a                          \
    $(SDK_ROOT)/libs/io/sdi/$(ODIR)/libsdi.a                                    \
    $(SDK_ROOT)/libs/isp/cam_generic/user/$(ODIR)/libcamdrv.a                   \
    $(SDK_ROOT)/libs/isp/csi/user/$(ODIR)/libcsidrv.a                           \
    $(SDK_ROOT)/libs/utils/log/$(ODIR)/liblog.a                                 \
    $(SDK_ROOT)/libs/isp/sequencer/user/$(ODIR)/libseqdrv.a                     \
    $(SDK_ROOT)/libs/isp/fdma/user/$(ODIR)/libfdmadrv.a                         \
    $(SDK_ROOT)/isp/graphs/$(ISP_GRAPH)/$(SEQ_FW)/$(ODIR)/lib$(SEQ_FW).a        \
    $(SDK_ROOT)/libs/apexcv_pro/util/$(ODIR)/apexcv_pro_util.a                   \
    $(SDK_ROOT)/libs/apexcv_pro/hog/$(ODIR)/apexcv_pro_hog.a                     \
    $(SDK_ROOT)/libs/apexcv_pro/resize/$(ODIR)/apexcv_pro_resize.a               \
    $(SDK_ROOT)/libs/apex/acf/$(ODIR)/libacf.a                                  \
    $(SDK_ROOT)/libs/apex/icp/$(ODIR)/libicp.a                                  \
    $(SDK_ROOT)/libs/apex/drivers/user/$(ODIR)/libapexdrv.a                     \
    $(SDK_ROOT)/libs/utils/oal/user/$(ODIR)/liboal.a                            \
    $(SDK_ROOT)/libs/utils/common/$(ODIR)/libcommon.a                           \
    $(SDK_ROOT)/libs/utils/umat/$(ODIR)/libumat.a                               \
    $(SDK_ROOT)/libs/apex/drivers/user/$(ODIR)/libapexdrv.a                     \
    $(SDK_ROOT)/libs/utils/communications/$(ODIR)/lib_communications.a          \
    $(SDK_ROOT)/libs/io/sdi/$(ODIR)/libsdi.a                                    \
    $(SDK_ROOT)/libs/io/gdi/$(ODIR)/libgdi.a                                    \
    $(SDK_ROOT)/libs/isp/sequencer/user/$(ODIR)/libseqdrv.a                     \
    $(SDK_ROOT)/libs/isp/fdma/user/$(ODIR)/libfdmadrv.a                         \
    $(SDK_ROOT)/libs/utils/oal/user/$(ODIR)/liboal.a                            \
    $(SDK_ROOT)/libs/isp/csi/user/$(ODIR)/libcsidrv.a                           \
    $(SDK_ROOT)/3rdparty/iniparser4/$(ODIR)/libiniparser4.a                     \
    $(SDK_ROOT)/libs/apexcv_ref/apexcv_pro/resize/$(ODIR)/resize_ref.a          \
    $(SDK_ROOT)/libs/apexcv_ref/apexcv_pro/hog/$(ODIR)/hog_ref.a

##############################################################################
# gdi_srv
##############################################################################

ARM_LDOPTS +=                                                                \
    -lopencv_core                                                            \
    -lopencv_imgproc                                                         \
    -lavcodec                                                                \
    -lavdevice                                                               \
    -lavfilter                                                               \
    -lavformat                                                               \
    -lavutil                                                                 \
    -lswresample                                                             \
    -lswscale

ifneq ($(findstring -linux,$(ODIR)),)
ARM_LDOPTS +=                                                                \
    -lavcodec                                                                \
    -lavdevice                                                               \
    -lavfilter                                                               \
    -lavformat                                                               \
    -lavutil                                                                 \
    -lswresample                                                             \
    -lswscale
endif

##############################################################################
# LINUX SPECIFIC INCLUDES
##############################################################################

ifneq (,$(findstring gnu-linux,$(ODIR))) 

ARM_APP_LIBS +=                                                              \
    $(SDK_ROOT)/libs/isp/jpegdec/user/$(ODIR)/libjpegdecdrv.a                \
    $(SDK_ROOT)/libs/isp/h264enc/user/$(ODIR)/libh264encdrv.a                \
    $(SDK_ROOT)/libs/isp/h264dec/user/$(ODIR)/libh264decdrv.a                \
    $(SDK_ROOT)/libs/isp/viu/user/$(ODIR)/libviudrv.a                        \
    
endif

##############################################################################
# STANDALONE SPECIFIC INCLUDES
##############################################################################

ifneq (,$(findstring gnu-sa,$(ODIR))) 

ARM_APP_LIBS +=                                                              \
    $(SDK_ROOT)/libs/io/i2c/$(ODIR)/libi2c.a                                 \
    $(SDK_ROOT)/libs/io/dcu/$(ODIR)/libdcu.a                                 \
    $(SDK_ROOT)/libs/startup/v234ce_standalone/$(ODIR)/libv234ce.a           \
    $(SDK_ROOT)/libs/io/i2c/$(ODIR)/libi2c.a                                 \
    $(SDK_ROOT)/libs/io/semihost/$(ODIR)/libSemihost.a                       \
    $(SDK_ROOT)/libs/io/uartlinflex_io/$(ODIR)/liblinflex.a
    
endif