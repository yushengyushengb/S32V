##############################################################################
#
# NXP Confidential Proprietary
#
# Copyright (c) 2017 NXP Semiconductor
# All Rights Reserved
#
##############################################################################
#
# THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
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

##############################################################################
# ARM_APP
##############################################################################
ARM_APP = apexcv_camdisp
ISP_GRAPH = mipi_simple
SEQ_MODE = dynamic
SEQ_FW = $(SEQ_MODE)_$(ISP_GRAPH)

ARM_DEFS += -DVSDK_UMAT_USE_OPENCV

ARM_APP_SRCS +=                                                               \
    main.cpp                                                                 \
    user_disp.cpp                                                            \
    user_cam.cpp                                                             \
    user_process.cpp                                                         \

ARM_INCS +=                                                                  \
    -I../src                                                                 \
    -I$(SDK_ROOT)/include                                                    \
	-I$(SDK_ROOT)/libs/utils/umat/include                                    \
	-I$(SDK_ROOT)/libs/utils/oal/user/include                                \
	-I$(SDK_ROOT)/libs/utils/oal/kernel/include                              \
    -I$(OPENCV_ROOT)/include                                                 \
    -I$(SDK_ROOT)/libs/apex/icp/include                                      \
    -I$(SDK_ROOT)/libs/apex/drivers/user/include                             \
    -I$(SDK_ROOT)/isp/inc                                                    \
    -I$(SDK_ROOT)/isp/graphs/$(ISP_GRAPH)/inc                                \
    -I$(SDK_ROOT)/libs/io/frame_io/include                                   \
    -I$(SDK_ROOT)/platform/s32_v234                                          \
    -I$(SDK_ROOT)/libs/io/dcu/include                                        \

ARM_APP_LIBS =                                                               \
    $(SDK_ROOT)/libs/apex/acf/$(ODIR)/libacf.a                               \
    $(SDK_ROOT)/libs/apex/icp/$(ODIR)/libicp.a                               \
    $(SDK_ROOT)/libs/utils/common/$(ODIR)/libcommon.a                        \
    $(SDK_ROOT)/libs/utils/umat/$(ODIR)/libumat.a                            \
    $(SDK_ROOT)/libs/apex/drivers/user/$(ODIR)/libapexdrv.a                  \
    $(SDK_ROOT)/libs/apexcv_base/apexcv_core/$(ODIR)/apexcv_core.a           \
    $(SDK_ROOT)/libs/apexcv_base/histogram/$(ODIR)/apexcv_histogram.a        \
    $(SDK_ROOT)/libs/io/frame_io/$(ODIR)/libframe_io.a                       \
    $(SDK_ROOT)/libs/io/sdi/$(ODIR)/libsdi.a                                 \
    $(SDK_ROOT)/libs/io/gdi/$(ODIR)/libgdi.a                                 \
    $(SDK_ROOT)/libs/utils/log/$(ODIR)/liblog.a                              \
    $(SDK_ROOT)/libs/utils/oal/user/$(ODIR)/liboal.a                         \
    $(SDK_ROOT)/libs/isp/csi/user/$(ODIR)/libcsidrv.a                        \
    $(SDK_ROOT)/libs/isp/sequencer/user/$(ODIR)/libseqdrv.a                  \
    $(SDK_ROOT)/libs/isp/fdma/user/$(ODIR)/libfdmadrv.a                      \
    $(SDK_ROOT)/isp/graphs/$(ISP_GRAPH)/$(SEQ_FW)/$(ODIR)/lib$(SEQ_FW).a     \
    $(SDK_ROOT)/libs/isp/cam_generic/user/$(ODIR)/libcamdrv.a                \
    $(SDK_ROOT)/libs/utils/oal/user/$(ODIR)/liboal.a                         \
    $(SDK_ROOT)/libs/utils/communications/$(ODIR)/lib_communications.a       \
    $(SDK_ROOT)/libs/apexcv_base/apexcv_core/$(ODIR)/apexcv_core.a                    \
    $(SDK_ROOT)/libs/apexcv_base/arithmetic/$(ODIR)/apexcv_arithmetic.a               \
    $(SDK_ROOT)/libs/apexcv_base/image_filters/$(ODIR)/apexcv_image_filters.a         \
    $(SDK_ROOT)/libs/apexcv_base/color_conversion/$(ODIR)/apexcv_color_conversion.a   \
    $(SDK_ROOT)/libs/apexcv_base/interpolation/$(ODIR)/apexcv_interpolation.a         \
    $(SDK_ROOT)/libs/apexcv_base/histogram/$(ODIR)/apexcv_histogram.a                 \
    $(SDK_ROOT)/libs/apexcv_base/integral_image/$(ODIR)/apexcv_integral_image.a       \

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
    -lopencv_flann                                                           \
    -lopencv_features2d                                                      \
    -lopencv_imgproc                                                         \
    -lopencv_highgui                                                         \
    -lopencv_core                                                            \
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

ARM_LDOPTS +=                                                                \
    -lopencv_core                                                            \
    -lopencv_features2d                                                      \
    -lopencv_flann                                                           \
    -lopencv_highgui                                                         \
    -lopencv_imgcodecs                                                       \
    -lopencv_imgproc                                                         \
    -lopencv_ml                                                              \
    -lopencv_videoio                                                         \
    -lavcodec                                                                \
    -lavdevice                                                               \
    -lavfilter                                                               \
    -lavformat                                                               \
    -lavutil                                                                 \
    -lswresample                                                             \
    -lswscale
    
    
endif


