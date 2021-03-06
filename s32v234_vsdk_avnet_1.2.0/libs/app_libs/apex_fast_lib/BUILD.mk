##############################################################################
#
# Freescale Confidential Proprietary
#
# Copyright (c) 2014 Freescale Semiconductor;
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


##############################################################################
# X86 TARGET VARIABLES
##############################################################################
X86_LIB = libapex_fast.a

ifeq ($(PDIR), x86)
   ifeq ($(OSDIR), linux)
     X86_DEFS += -D__LINUX__
  endif

  X86_DEFS += -DAPEX2_EMULATE
endif

##############################################################################
# X86 TARGET VARIABLES
##############################################################################

X86_LIB_SRCS =                                                              \
    apex_fast.cpp                                                           \

X86_INCS +=                                                                 \
    -I$(SDK_ROOT)/libs/apex/icp/include                                     \
    -I$(SDK_ROOT)/libs/apex/acf/include                                     \
    -I$(SDK_ROOT)/include                                                   \
    -I$(OPENCV_ROOT)/include                                                \
    -I$(SDK_ROOT)/libs/utils/oal/user/include                               \
    -I$(SDK_ROOT)/libs/utils/oal/kernel/include                             \
    -I$(SDK_ROOT)/libs/utils/umat/include                                   \
    -I$(SDK_ROOT)/libs/utils/common/include                                 \
    -I../inc                                                                \
    -I../graphs                                                             \
    -I../graphs/build-apu-$(APU_COMP)-sa-d

X86_DEFS += -DVSDK_UMAT_USE_OPENCV -DTARGET_NUM_CORES=4

###############################################################################
# S32V244 TARGET VARIABLES
##############################################################################
ARM_LIB = $(X86_LIB)
ARM_LIB_SRCS = $(X86_LIB_SRCS)
ARM_INCS = $(X86_INCS)
ARM_CCOPTS = $(X86_CCOPTS)
ARM_CXOPTS += $(X86_CXOPTS)
ARM_DEFS +=$(X86_DEFS)


ifeq ($(PDIR), x86)
  #emulation for Linux/Windows host
  X86_DEFS += -DAPEX2_EMULATE \
    -DACF_KERNEL_IMPLEMENTATION

  X86_INCS += -I$(SDK_ROOT)/tools/emu/apu/src \
    -I$(SDK_ROOT)/tools/emu/acf/src \
    -I$(SDK_ROOT)/kernels/apu/sample_feature_detection_kernels/src/ \
    -I$(SDK_ROOT)/kernels/apu/sample_filtering_kernels/src/
endif
