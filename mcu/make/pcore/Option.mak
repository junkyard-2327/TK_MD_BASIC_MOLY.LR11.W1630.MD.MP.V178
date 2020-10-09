#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).

# *************************************************************************
# Include GNU Make Standard Library (GMSL)
# *************************************************************************
include ${CORE_ROOT}/tools/GMSL/gmsl
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))


CUSTOM_FLD_MAPPING = $(if $($(subst /,_,$(patsubst %/,%,$(subst //,/,$(subst \,/,$(call lc, $(1))))))), \
                     $($(subst /,_,$(patsubst %/,%,$(subst //,/,$(subst \,/,$(call lc, $(1))))))),\
                     $(if $(wildcard $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/$(strip $(CUSTOM_FLAVOR))),\
                     $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/$(strip $(CUSTOM_FLAVOR)),\
                     $(if $(wildcard $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/DEFAULT), \
                     $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/DEFAULT,)))

                      
AUTO_MERGE_FILE_CHECK = $(if $(shell $(LIST_DIR) "$(call CUSTOM_FLD_MAPPING,$(1))/$(2)"  2>$(DEV_NUL)), $(call CUSTOM_FLD_MAPPING,$(1))/$(2), \
                        $(if $(shell $(LIST_DIR) "$(1)/_Default_BB/$(strip $(PLATFORM))/$(2)"  2>$(DEV_NUL)), $(1)/_Default_BB/$(strip $(PLATFORM))/$(2),))

ifndef PROJECT_NAME
$(error PROJECT_NAME is not defined)
endif
ifndef PROJECT_MAKEFILE
$(error PROJECT_MAKEFILE is not defined)
endif
ifndef FLAVOR
$(error FLAVOR is not defined)
endif

# *************************************************************************
# Include temporary build script
# *************************************************************************

# Custom specific build script
include make/${CORE_ROOT}/Custom.bld         # Custom release build
# default cmd setting
include make/common/cmd_cfg.mak

ifndef CUSTOM_RELEASE
  CUSTOM_RELEASE = FALSE         # Default custom release
endif
ifndef MTK_SUBSIDIARY
  MTK_SUBSIDIARY = FALSE
endif

-include make/common/Verno.bld
HW_VER := $(call Upper,$(strip $(PROJECT_NAME)))_HW
include $(PROJECT_MAKEFILE)
include make/common/Option.mak
VERNO := $(call Upper,$(strip $(VERNO)))

ifndef CUSTOM_FLAVOR
$(error CUSTOM_FLAVOR is not defined)
endif

-include $(strip $(TMPDIR))/~buildinfo.tmp
-include $(strip $(TMPDIR))/~net_path.tmp
-include $(strip $(TMPDIR))/cus_folder.tmp

ENABLE_PARTIAL_TRACE=FALSE
ifdef KAL_TRACE_OUTPUT
  ifdef PARTIAL_TRACE_LIB
    ifeq ($(strip $(KAL_TRACE_OUTPUT)),CUST_PARTIAL)
      ifneq ($(strip $(PARTIAL_TRACE_LIB)),)
        ENABLE_PARTIAL_TRACE=TRUE
      endif
    endif
  endif
endif

COMMINCDIRS    += $(CUSTOM_COMMINC)
COM_DEFS       += $(CUSTOM_OPTION)

#*************************************************************************
# auto-add ${CORE_ROOT}/interface/* folder to global include path if it exist *.h 
#*************************************************************************
#disable since some interface folder cannot open
COMMINCDIRS += ${COMMON_ROOT}/interface/driver/audio \
               ${CORE_ROOT}/interface/driver/audio 
COMMINCDIRS += ${CORE_ROOT}/interface/driver/cipher/include
COMMINCDIRS += ${CORE_ROOT}/interface/driver/cmux
COMMINCDIRS += ${CORE_ROOT}/interface/driver/connectivity/sdio_device
COMMINCDIRS += ${CORE_ROOT}/interface/driver/connectivity/usb_driver
COMMINCDIRS += ${CORE_ROOT}/interface/driver/drv_sw_def
COMMINCDIRS += ${CORE_ROOT}/interface/driver/hwdrv
COMMINCDIRS += ${CORE_ROOT}/interface/driver/peripheral
COMMINCDIRS += ${CORE_ROOT}/interface/driver/storage/mc
COMMINCDIRS += ${CORE_ROOT}/interface/driver/storage/sim
COMMINCDIRS += ${CORE_ROOT}/interface/middleware/general
COMMINCDIRS += ${CORE_ROOT}/interface/middleware/gps
COMMINCDIRS += ${CORE_ROOT}/interface/middleware/media
COMMINCDIRS += ${COMMON_ROOT}/interface/middleware/meta
COMMINCDIRS += ${COMMON_ROOT}/interface/modem/general
COMMINCDIRS += ${COMMON_ROOT}/interface/cross_core
COMMINCDIRS += ${CORE_ROOT}/interface/service/asn1_common
COMMINCDIRS += ${CORE_ROOT}/interface/service/fota
COMMINCDIRS += ${CORE_ROOT}/interface/service/fsm
COMMINCDIRS += ${COMMON_ROOT}/interface/service/kal
COMMINCDIRS += ${CORE_ROOT}/interface/service/qmu_bm
COMMINCDIRS += ${COMMON_ROOT}/interface/service/qmu_bm
COMMINCDIRS += ${COMMON_ROOT}/interface/service/sst
COMMINCDIRS += ${CORE_ROOT}/interface/service/flc2
COMMINCDIRS += ${CORE_ROOT}/driver/devdrv/mdl_ebc/inc
COMMINCDIRS += ${COMMON_ROOT}/driver/sys_drv/pmu/inc
COMMINCDIRS += ${CORE_ROOT}/interface/driver/devdrv/coresight
COMMINCDIRS += ${CORE_ROOT}/interface/driver/devdrv/cpu
COMMINCDIRS += ${CORE_ROOT}/interface/driver/devdrv/gdma
COMMINCDIRS += ${CORE_ROOT}/interface/driver/devdrv/l1gdma
COMMINCDIRS += ${CORE_ROOT}/interface/driver/devdrv/busmon
COMMINCDIRS += ${CORE_ROOT}/interface/driver/devdrv/rstctl
COMMINCDIRS += ${CORE_ROOT}/interface/driver/devdrv/mdipc
COMMINCDIRS += ${CORE_ROOT}/interface/driver/drvtest
COMMINCDIRS += ${CORE_ROOT}/interface/service/sst
# *************************************************************************
# Include checkvalue.mak to check invalid feature values.
# *************************************************************************
-include make/common/checkvalue.mak
-include make/common/OLD_FEATURES.mak

CPU_ARCH = CR4
ifneq ($(filter MT6752,$(PLATFORM)),)
  ifeq ($(strip $(MDSYS)),MD2)
    CPU_ARCH = ARM9
  endif
endif

ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COMMINCDIRS    += $(strip $(TSTDIR))/database/unionTag
endif

ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/drv/include/drv_trc.h
endif

ifeq ($(filter UDVT,$(TEST_LOAD_TYPE)),)
  COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/drv/include/drv_trc.h
endif

ifneq ($(strip $(RAM_SUPPORT_TYPE)),NONE)
  COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/driver/devdrv/emi/inc/emi_trace.h
endif

ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  COMPLIST += sleep_drv sys_svc sys_drv tty devdrv qmu_bm sib_drv
  ifeq ($(filter L1S,$(TEST_LOAD_TYPE)),)
    COMPLIST += tft_pf upcm
  endif
  ifeq ($(strip $(HIF_USB_SUPPORT)),TRUE)
    COMPLIST += drv_hif
  else
    ifeq ($(strip $(HIF_SDIO_SUPPORT)),TRUE)
      COMPLIST += drv_hif
    endif
  endif
else
  ifeq ($(ORIGINAL_FLAVOR),BASIC_HIF)
    COMPLIST += drv_hif
  endif
  COMPLIST += sleep_drv sys_svc sys_drv tty devdrv qmu_bm sib_drv
endif

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(strip $(UE_SIMULATOR)),TRUE)
	  COMPLIST += utt
  endif
endif

ifeq ($(strip $(HW_PFC_SUPPORT)),TRUE)
  COMPLIST += drv_pfc
endif

COMPLIST += sys_svc_sec

# GEMINI
ifdef GEMINI
  ifneq ($(strip $(GEMINI)),FALSE)
    ifneq ($(strip $(GEMINI)),2)
      ifneq ($(filter __LOWCOST_MERGE_TASK__,$(COM_DEFS)),)
            $(warning ERROR: __LOWCOST_MERGE_TASK__ cannot be defined when GEMINI_PLUS is larger than 2)
            DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    COMPLIST += rsva
    
    ifdef UNIFIED_MESSAGE_FOLDER
      ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)),TRUE)
        ifneq ($(strip $(MMS_SUPPORT)), OBIGO_Q03C_MMS_V02)
          $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,GEMINI & UNIFIED_MESSAGE)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif

    COMP_TRACE_DEFS_MODEM += ${L1CORE_ROOT}/modem/gl1/common/l1a_trace.h

    COM_DEFS += __GEMINI__ __GEMINI_GSM__ __GSM_RAT__ DRV_MULTIPLE_SIM __CTA_DUAL_SIM_STANDARD__
    COM_DEFS += __L4C_ROOT__ __GEMINI_3G_SWITCH__

    # assign GEMINI to GEMINI_PLUS_GSM
    ifndef GEMINI_PLUS
      GEMINI_PLUS = $(strip $(GEMINI))
    endif
    ifndef GEMINI_PLUS_GSM
      GEMINI_PLUS_GSM = $(strip $(GEMINI))
    endif

    COM_DEFS    += GEMINI_PLUS=$(strip $(GEMINI))
    COM_DEFS    += GEMINI_PLUS_GSM=$(strip $(GEMINI_PLUS_GSM))
       
    COMPLIST += as_semaphore_utility
  endif
endif

# GPS_SUPPORT
ifdef GPS_SUPPORT
  ifeq ($(strip $(GPS_SUPPORT)),SMART_PHONE_MODEM)
    COM_DEFS    += __GPS_SUPPORT__
  endif
endif

#always enable except l1s/basic
ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/middleware/lbs/common/inc/lbs_trc.h
  COMPLIST    += lbs
else
  COM_DEFS += LBS_NOT_PRESENT
endif

COM_DEFS += __PCORE__
ifeq ($(SINGLE_CORE),TRUE)
COM_DEFS += __PCORE_ONLY__
endif

ifeq ($(filter L1S BASIC UDVT,$(strip $(TEST_LOAD_TYPE))),)
  #COMP_TRACE_DEFS_MODEM   += inet_ps\ems\include\ems_trc.h
  ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
    COMP_TRACE_DEFS_MODEM   +=    $(strip $(GAS_FDD_FOLDER))/mpal/include/mpal_trace.h
    COMP_TRACE_DEFS_MODEM   +=    $(strip $(GAS_TDD_FOLDER))/mpal/include/mpal_trace.h
  else
    ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
      ifeq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
        COMP_TRACE_DEFS_MODEM   +=    $(strip $(GAS_FDD_FOLDER))/mpal/include/mpal_trace.h
        COMP_TRACE_DEFS_MODEM   +=    $(strip $(GAS_TDD_FOLDER))/mpal/include/mpal_trace.h
      endif
    endif
  endif
endif

  L1_TMD_FILES   +=   $(strip $(SLEEPDRV_FOLDER))/common/PCORE_DCXO_DIV_Trace1.tmd \
                      $(strip $(SLEEPDRV_FOLDER))/common/PCORE_OSTD_Trace1.tmd \
                      $(strip $(SLEEPDRV_FOLDER))/common/PCORE_PTP_Trace1.tmd \
                      $(strip $(SLEEPDRV_FOLDER))/common/PCORE_SleepDrv_Trace1.tmd \
                      $(strip $(SLEEPDRV_FOLDER))/common/PCORE_MD_TOPSM_Trace1.tmd \
                      $(strip $(SLEEPDRV_FOLDER))/common/PCORE_DVFS_Trace1.tmd \
                      $(strip $(SLEEPDRV_FOLDER))/common/PCORE_TPPA_SleepDrv_Trace1.tmd
  ifneq (${CORE_ROOT},pcore)
    L1_TMD_FILES +=   $(strip $(SLEEPDRV_FOLDER))/common/MODEM_TOPSM_Trace1.tmd
  endif

COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/driver/devdrv/mdipc/inc/cc_irq_trace.h 
COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/driver/dp_engine/dp_engine_trc.h
COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/middleware/meta/ft/inc/ft_trace_def.h

# ---------------------------------------------------------------
# The followings are global options from $(PROJECT_NAME).bld
# ---------------------------------------------------------------
# Platform Options
COM_DEFS_FOR_FPGA    = FPGA
COM_DEFS_FOR_TK6291  = TK6291                TK6291_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6755  = MT6755                MT6755_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6797  = MT6797                MT6797_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6757  = MT6757                MT6757_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6757P = MT6757P               MT6757P_$(strip $(CHIP_VER)) MT6757 MT6757_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6750  = MT6750                MT6750_$(strip $(CHIP_VER)) MT6755 MT6755_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6750S = MT6750S               MT6750S_$(strip $(CHIP_VER))

COM_DEFS_FOR_PLATFORM =  COM_DEFS_FOR_$(strip $(PLATFORM))
ifdef $(COM_DEFS_FOR_PLATFORM)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(PLATFORM)))
else
  $(warning ERROR: [COM_DEFS_FOR_$(strip $(PLATFORM))] was not defined)
  DEPENDENCY_CONFLICT = TRUE
endif

NEED_BUILD_BOOTLOADER = FALSE
MAIN_CODE_NEED_GFH = TRUE

ifdef UMTS_MODE_SUPPORT
  ifneq ($(strip $(UMTS_MODE_SUPPORT)),NONE)
    ifeq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
      $(warning ERROR: UMTS_MODE_SUPPORT can only be turned on when __UMTS_RAT__ defined)
      DEPENDENCY_CONFLICT = TRUE
    endif

      COM_DEFS   += __3G_AUTO_BAND_MECHANISM__
    ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS += __UMTS_FDD_MODE__ __ME_STORED_EHPLMN__
    endif
    ifeq ($(strip $(UMTS_TDD_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
       COM_DEFS += __UMTS_TDD128_MODE__ __R7_EHPLMN__ __ME_STORED_EHPLMN__ __VSIM__
       ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
         COM_DEFS += __TDD_UMAC_HISR_DISABLE__
       endif   
    endif
  else
    ifeq ($(strip $(SMART_PHONE_CORE)),ANDROID_MODEM)
      ifneq ($(filter MT6575 MT6577,$(strip $(PLATFORM))),)
        COM_DEFS +=  __SMARTPHONE_GPRS_ONLY__
      endif
    endif
  endif
endif

CENTRALIZED_SLEEP_MANAGER_PLATFORM = MT6575 MT6280 MT6577 MT6589 MT6290
ifeq ($(strip $(CENTRALIZED_SLEEP_MANAGER)),TRUE)
  COM_DEFS += __CENTRALIZED_SLEEP_MANAGER__
  ifneq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    COM_DEFS += __EVENT_BASED_TIMER__
  endif
else
  ifneq ($(filter $(strip $(PLATFORM)),$(CENTRALIZED_SLEEP_MANAGER_PLATFORM)),)
    $(warning ERROR: CENTRALIZED_SLEEP_MANAGER must be TRUE on $(strip $(PLATFORM)))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef PS_MCU_CLOCK
  # convert MCU_XXX_YYM to XXX.YY
  CLOCK_MHZ = $(subst _,.,$(subst M,,$(subst MCU_,,$(strip $(PS_MCU_CLOCK)))))
  ifneq ($(CLOCK_MHZ),)
    COM_DEFS += CPU_CLOCK_MHZ=$(CLOCK_MHZ)
  endif
endif

ifeq ($(strip $(SMART_PHONE_CORE)),ANDROID_MODEM)
  COM_DEFS += MED_NOT_PRESENT MED_V_NOT_PRESENT
else
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    ifneq ($(filter NONE MODEM_ONLY,$(strip $(SMART_PHONE_CORE))),)
      COMPLIST += media
    endif
  endif
endif

ifdef CTM_SUPPORT
  ifeq ($(strip $(CPU_ARCH)),ARM9)
    CTM_SRC_LIB_PATH = ${CORE_ROOT}/driver/audio/lib/MTKGCC_ARM9
    else #CR4
    CTM_SRC_LIB_PATH = ${CORE_ROOT}/driver/audio/lib/MTKGCC_CR4
  endif
  ifneq ($(strip $(CTM_SUPPORT)),FALSE)
    COM_DEFS    +=  __CTM_SUPPORT__
    COMPLIST += dp_engine
    COMPOBJS += $(strip $(CTM_SRC_LIB_PATH))/libctm_blisrc.a
  endif
endif

COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/interface/driver/storage/sim/sim_drv_trc.h

#end of option_HAL.mak
# *************************************************************************
# Environment and Tools
# *************************************************************************

include make/${COMMON_ROOT}/compiler.mak

# -----------------------------
# custom release library path
# -----------------------------
# *************************************************************************
# Common include file and output directory path
# *************************************************************************

COMMINCDIRS   +=  $(strip $(BUILD_SYSDIR))
ifeq ($(strip $(CUST_CODE)),TC01)
  COMMINCDIRS += $(strip $(BUILD_SYSDIR))/ERS
endif

COMMINCDIRS    += ${CORE_ROOT}/driver/drv/include
COMMINCDIRS    += $(strip $(PROJDIR))/nvram_auto_gen

ifneq ($(filter FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
  ifneq ($(filter fmt,$(COMPLIST)),)
    $(warning ERROR: Please remove FMT_NOT_PRESENT from CUSTOM_OPTION when fmt module is defined in COMPLIST)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# *************************************************************************
# Include LTE compile settings.
# *************************************************************************
include make/${COMMON_ROOT}/LTE_DEF.mak

# *************************************************************************
# Components
# *************************************************************************
# -----------------------------
# Common Components
# -----------------------------

AUTO_MERGE_FLR = ${CORE_ROOT}/custom/driver/audio ${CORE_ROOT}/custom/driver/drv/misc_drv
AUTO_MERGE_PTH = $(foreach DIR,$(AUTO_MERGE_FLR),$(call CUSTOM_FLD_MAPPING,$(DIR)) $(DIR)/_Default_BB/$(strip $(PLATFORM)))
COMMINCDIRS := $(AUTO_MERGE_PTH) $(COMMINCDIRS)

# *************************************************************************
# Component trace definition header files
# *************************************************************************
# -----------------------------
# Common trace
# -----------------------------
#
# Check the dependency of each options
#

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    FLC_LIB_INCLUDE_CONDITION = FALSE
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      FLC_LIB_INCLUDE_CONDITION = TRUE
    endif
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      FLC_LIB_INCLUDE_CONDITION = TRUE
    endif
    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      FLC_LIB_INCLUDE_CONDITION = TRUE
    endif
    ifeq ($(strip $(FLC_LIB_INCLUDE_CONDITION)),TRUE)
      ifeq ($(strip $(UMTS_TDD_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
        ifeq ($(strip $(3G_NEW_DATA_PLANE_ARCH)), TRUE)
          COMPLIST += flc2_v2 flc2_v2_sec
        else
          COMPLIST += flc2_v1
        endif
      else
        COMPLIST += flc2_v2 flc2_v2_sec
      endif
      COMP_TRACE_DEFS_MODEM += $(strip $(FLC_FOLDER))/include/flc_trc.h
      COM_DEFS += __FLC2__ __FLC_SUPPORT__
    endif
  endif
endif

COM_DEFS    += __PHB_0x81_SUPPORT__
COM_DEFS    += __2G_CAP_FORCE_R9__

EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLATFORM = MT6575 MT6577
ifeq ($(strip $(PS_HANDOVER)),TRUE)
  ## temporary not support PS_HANDOVER
  $(warning ERROR: PS_HANDOVER cannot be TRUE for current platform.)
  DEPENDENCY_CONFLICT = TRUE
  ##
  ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
    ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R7_SUPPORT)
      ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R8_SUPPORT)
        $(call DEP_ERR_SETA_OR_OFFB,GERAN_RELEASE_SUPPORT,GERAN_R6_SUPPORT,PS_HANDOVER)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifneq ($(filter __EGPRS_MODE__,$(COM_DEFS)),)
    ifeq ($(filter $(strip $(PLATFORM)),$(EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLATFORM)),)
      $(warning ERROR: PS_HANDOVER cannot be TRUE for PLATFORM $(strip $(PLATFORM)).)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __PS_HO__  __EXT_SEG_CTRL_BLK__
endif

ifeq ($(strip $(MULTIPLE_TBF)),TRUE)
  ## temporary not support MULTIPLE_TBF
  $(warning ERROR: MULTIPLE_TBF cannot be TRUE for current platform.)
  DEPENDENCY_CONFLICT = TRUE
  ##
  ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
    ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R7_SUPPORT)
      ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R8_SUPPORT)
        $(call DEP_ERR_SETA_OR_OFFB,GERAN_RELEASE_SUPPORT,GERAN_R6_SUPPORT,MULTIPLE_TBF)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif  
  endif
  ifneq ($(filter __EGPRS_MODE__,$(COM_DEFS)),)
    ifeq ($(filter $(strip $(PLATFORM)),$(EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLATFORM)),)
      $(warning ERROR: MULTIPLE_TBF cannot be TRUE for PLATFORM $(strip $(PLATFORM)).)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __MTBF__
endif

ifeq ($(strip $(L1_CATCHER)),TRUE)
  ifeq ($(strip $(TST_SUPPORT)),TRUE)
    COM_DEFS    += L1_CATCHER
    DHL_L1_TMD_FILE := ${COMMON_ROOT}/interface/service/dhl/dhl_l1_trace.tmd
  endif
  ifeq ($(strip $(DHL_SUPPORT)),TRUE)
    COM_DEFS    += L1_CATCHER
    DHL_L1_TMD_FILE := ${COMMON_ROOT}/interface/service/dhl/dhl_l1_trace.tmd
  endif
endif

ifdef FS_TRACE_SUPPORT
  ifdef TST_SUPPORT
    ifeq ($(strip $(FS_TRACE_SUPPORT)),TRUE)
      ifeq ($(strip $(DHL_SUPPORT)),TRUE)
        COM_DEFS   += __FS_TRACE_SUPPORT__
      else
        $(call DEP_ERR_ONA_OR_OFFB,DHL_SUPPORT,FS_TRACE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
  COM_DEFS += KAL_ENH_MUTEX
else
  ifneq ($(filter __CS_SERVICE__,$(COM_DEFS)),)
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      COM_DEFS    += KAL_ENH_MUTEX
    endif
  endif
endif

ifeq ($(filter __KBD_JOYSTICK_SUPPORT__,$(COM_DEFS)),__KBD_JOYSTICK_SUPPORT__)
   ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__TWO_KEY_DETECTION_SWITCHABLE__)
      $(call DEP_ERR_OFFA_OR_OFFB,__TWO_KEY_DETECTION_SWITCHABLE__,__KBD_JOYSTICK_SUPPORT__)
      DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __DISABLE_SMS_CONTROLLED_BY_SIM__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __SAT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: Please define __SAT__ or do not define __DISABLE_SMS_CONTROLLED_BY_SIM__)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __SAIC__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(SAIC_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __SAIC__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

REPEATED_ACCH_NOT_SUPPORT_FLATFORM = MT6205 MT6205B MT6208 MT6217 MT6218 MT6218B MT6219 MT6223 MT6223P MT6225 MT6226 MT6226D MT6226M MT6227 MT6227D MT6228 MT6229 MT6230 MT6235B MT6238 MT6239 MT6268T MT6268H
ifeq ($(filter $(strip $(PLATFORM)),$(REPEATED_ACCH_NOT_SUPPORT_FLATFORM)),)
  COM_DEFS    +=    __REPEATED_ACCH__
endif
ifneq ($(filter __REPEATED_ACCH__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(REPEATED_ACCH_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __REPEATED_ACCH__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __VAMOS_1__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(VAMOS_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __VAMOS_1__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __VAMOS_2__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(VAMOS_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __VAMOS_2__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef BIP_SCWS_SUPPORT
  ifeq ($(strip $(BIP_SCWS_SUPPORT)),TRUE)
    ifneq ($(strip $(TCPIP_LOOP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_LOOP_SUPPORT,BIP_SCWS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter __SAT__,$(COM_DEFS)),)
        $(warning ERROR: __SAT__ must be defined when BIP_SCWS_SUPPORT is turned on.)
        DEPENDENCY_CONFLICT = TRUE
    endif   
    COM_DEFS    += __SATCE__
  endif
endif

ifdef SIM_SWTICH_CONTROLLER_MT6306
  ifeq ($(strip $(SIM_SWTICH_CONTROLLER_MT6306)),TRUE)
    COM_DEFS += __SIM_DRV_SWITCH_MT6306__
  endif
endif

ifneq ($(filter __SMS_DEPERSONALIZATION__,$(COM_DEFS)),)
  ifeq ($(filter __MOD_SMU__,$(COM_DEFS)),)
    $(call DEP_ERR_ONA_OR_OFFB,__MOD_SMU__,__SMS_DEPERSONALIZATION__)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __MOD_SMS__,$(COM_DEFS)),)
    $(call DEP_ERR_ONA_OR_OFFB,__MOD_SMS__,__SMS_DEPERSONALIZATION__)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

COMPOBJS += ${CORE_ROOT}/modem/common/kdf/lib/gcc/libkdf.a

#####do not support MODEM_FLODER RULE#####
ifneq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
  ifeq ($(strip $(LPP_SUPPORT)),CONTROL_PLANE)
    COMPLIST   += lpp
    COM_DEFS   += __LPP_SUPPORT__
    COM_DEFS   += __LPP_CP_SUPPORT__
    COMP_TRACE_DEFS_MODEM += $(PCORE_ROOT)/modem/agps/lpp/include/lpp_trc.h
  endif
endif
ifeq ($(strip $(LPP_SUPPORT)),CONTROL_PLANE)
  ifeq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
    $(warning ERROR: please turn on EUTRAN_MODE_SUPPORT, when LPP_SUPPORT is set.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(LPP_SUPPORT)),CONTROL_PLANE)
  ifeq ($(call Upper,$(strip $(LTE_OTDOA_SUPPORT))),FALSE)
  ifeq ($(call Upper,$(strip $(LTE_ECID_SUPPORT))),FALSE)
    $(warning ERROR: please turn on at least one of AGPS_SUPPORT, LTE_OTDOA_SUPPORT, LTE_ECID_SUPPORT, when LPP_SUPPORT is set.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  endif
endif

ifneq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
  ifeq ($(strip $(LPP_SUPPORT)),CONTROL_PLANE)
    ifeq ($(strip $(LTE_ECID_SUPPORT)),TRUE)
      COM_DEFS += __LTE_ECID_SUPPORT__
    endif
  endif
endif
ifeq ($(strip $(LTE_ECID_SUPPORT)),TRUE)
  ifeq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
    $(warning ERROR: please turn on EUTRAN_MODE_SUPPORT and LPP_SUPPORT, when LTE_ECID_SUPPORT is set to TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(LPP_SUPPORT)), NONE)
        $(warning ERROR: please turn on EUTRAN_MODE_SUPPORT and LPP_SUPPORT, when LTE_ECID_SUPPORT is set to TRUE.)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef L1_GPS_REF_TIME_SUPPORT 
  ifeq ($(strip $(L1_GPS_REF_TIME_SUPPORT)), TRUE)
    COM_DEFS += __L1_GPS_AUTO_TIMING_SYNC_SUPPORT__
  endif
endif
#####do not support MODEM_FLODER RULE#####
ifdef AGPS_SUPPORT
  ifneq ($(strip $(AGPS_SUPPORT)), NONE)
    ifeq ($(strip $(AGPS_SUPPORT)), CP_AGPS_AGLONASS)
      COM_DEFS += __AGPS_SUPPORT__ __AGNSS_SUPPORT__ __AGLONASS_SUPPORT__ __RRLP_SUPPORT__ __AGPS_CONTROL_PLANE__ __NBR_CELL_INFO__
      COM_DEFS += __RRLP_REL_5__ __RRLP_REL_7__ __POS_CAP_TRANSFER_PROCEDURE_SUPPORT__ 
      COMPLIST        += rrlp asn1_common
      COMP_TRACE_DEFS_MODEM += $(PCORE_ROOT)/modem/agps/rrlp/include/rrlp_trc.h
      ifdef L1_GPS_REF_TIME_SUPPORT 
        ifeq ($(strip $(L1_GPS_REF_TIME_SUPPORT)), TRUE)
          COM_DEFS += __L1_GPS_REF_TIME_SUPPORT__
        endif
      endif
      COM_DEFS += __UAGPS_CP_SUPPORT__
      COMPLIST += ulcs
      COMP_TRACE_DEFS_MODEM += $(PCORE_ROOT)/modem/agps/ulcs/uagps_cp/include/uagps_cp_trc.h
      COMP_TRACE_DEFS_MODEM += $(PCORE_ROOT)/modem/agps/ulcs/common/include/uagps_trc.h
      COM_DEFS += __AGPS_CP_SIB15__
      COM_DEFS += __ULCS_ASN_SUPPORT_R6__
      COM_DEFS += __ULCS_ASN_SUPPORT_R7__
      COM_DEFS += __ULCS_ASN_SUPPORT_R8__
      COM_DEFS += __ULCS_ASN_SUPPORT_R9__
      COM_DEFS += __ULCS_ASN_SUPPORT_R10__
      COM_DEFS += __ULCS_ASN_SUPPORT_R11__
    endif
  endif
endif

MCD_DEFS  = __R99__
MCD_DEFS += MAX_PS_NAME_SIZE=$(call plus,$(PHB_NAME_LENGTH),2)
ifdef MCD_CODESET_SHIFT_SUPPORT
  ifneq ($(strip $(MCD_CODESET_SHIFT_SUPPORT)),NONE)
    MCD_DEFS += __MCD_CODESET_SHIFT__
    MCD_DEFS += $(foreach def, $(MCD_CODESET_SHIFT_SUPPORT), __MCD_CODESET_SHIFT_$(def)__)
    COM_DEFS += __MCD_CODESET_SHIFT__
    COM_DEFS += $(foreach def, $(MCD_CODESET_SHIFT_SUPPORT), __MCD_CODESET_SHIFT_$(def)__)
  endif
endif

ifneq ($(filter __L4_MAX_NAME_60__,$(COM_DEFS)),)
  MCD_DEFS += __L4_MAX_NAME_60__
endif

ifneq ($(filter __MONITOR_PAGE_DURING_TRANSFER__,$(COM_DEFS)),)
  ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    $(warning ERROR: __MONITOR_PAGE_DURING_TRANSFER__ can only be defined when __PS_SERVICE__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef OPTR_SPEC_MODEM
  ifeq ($(strip $(OPTR_SPEC_MODEM)), ATT_0402_ADAPT)
    ifeq ($(strip $(USIM_SUPPORT)), TRUE)
      COM_DEFS  += __U_CSP_SUPPORT__
    endif
    COM_DEFS  += __GPRS_PDP_ALL_QOS_ARE_SUBSCRIBED__
    COM_DEFS  += __IOT_TEST__ 
    COM_DEFS  += __ENS__
    COM_DEFS  += __ENS_RAT_BALANCING__ 
    COM_DEFS  += __ATT_FLIGHT_MODE_GPS_HANDLING__
    COM_DEFS  += __ATNT_HPPLMN_SEARCH__
    COM_DEFS  += __DISABLE_AUTO_RETURN_PRE_RPLMN__
    COM_DEFS  += __OPTIMAL_SIM_FILE_UPDATE__
    COM_DEFS  += __DISABLE_RPLMN_FROM_GLOCI__
    COM_DEFS  += __RESUME_GPRS_AFTER_LU_ABNORMAL__
    COM_DEFS  += __CSIM__
    COM_DEFS  += __ATCFUN_FLIGHTMODE_SUPPORT__
    COM_DEFS  += __NW_DETACH_SUPPORT__
    COM_DEFS  += __CLAC_SUPPORT__
    COM_DEFS  += __CGSMS_FULL_SUPPORT__
    COM_DEFS  += __UDH_MESSAGE_WAITING_HIGH_PRIORITY__
    COM_DEFS  += __AT_ME_IDENTIFICATION_WITHOUT_HEADER__
    COM_DEFS  += __SAT_NO_EVDL_IN_SESSION__
    COM_DEFS  += __IMEI_LOCK_SUPPORT__
    COM_DEFS  += __STAR_SHORT_STRING_AS_CALL__
    COM_DEFS  += __CUSTOMIZED_IDLE_STRING_AS_CALL__
    COM_DEFS  += __MM_DISABLE_RETRY_ABNORMAL_LAI__
  endif
  ifeq ($(strip $(OPTR_SPEC_MODEM)), H3G)
    COM_DEFS  += __PERMANENT_AUTO_SEL_MODE__
    COM_DEFS  += __DUMMY_OFF_R7_AUTO_RHPLMN_SEL__
    COM_DEFS  += __MM_HPPLMN_1ST_ATTEMPT_ENHANCE__
    COM_DEFS  += __MM_TRY_ABNORMAL_LAI_ONCE_MORE__
  endif
endif

ifdef SMS_OVER_PS_SUPPORT
  ifeq ($(strip $(SMS_OVER_PS_SUPPORT)),TRUE)
    ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      $(warning ERROR: __PS_SERVICE__ must be defined when SMS_OVER_PS_SUPPORT is turned on.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __SMS_OVER_PS_SUPPORT__
  endif
endif

ifneq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
  COM_DEFS += __R6_OOS__
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifndef LOW_COST_SUPPORT
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)), NONE)
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
  ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    ifndef LOW_COST_SUPPORT
      COMPLIST       += scsi
    endif
    ifeq ($(strip $(LOW_COST_SUPPORT)), NONE)
      COMPLIST       += scsi
    endif
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      COMPLIST       += scsi
    endif
  endif
endif

ifeq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),TC01)
  ifeq ($(filter __TC01__,$(COM_DEFS)),)
    $(warning ERROR: USB_COMPORT_PC_DRIVER_SUPPORT can not be TC01 when __TC01__ not defined!)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __USB_COMPOSITE_REMOVE_IAD__
  COM_DEFS    += __USB_COMPORT_SUPPORT_TC01_DRIVER__
  COM_DEFS    += __USB_BOOT_NOT_CHECK_NVRAM_SETTING__
endif

ifeq ($(strip $(CUST_CODE)),TC01)
  COM_DEFS += __LATCH_POWER_IN_BOOTLOADER__
  COM_DEFS += __LATCH_POWER_IN_BOOTLOADER_TC01__
endif

COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/sys_drv/init/inc/system_trc.h

ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
  COM_DEFS += __NEW_TBF_ARCH__
  COM_DEFS += __REMOVE_FA__
endif


ifneq ($(filter __L1_STANDALONE__,$(COM_DEFS)),)
    COM_DEFS  +=  DRV_LCD_NOT_EXIST 
endif

ifeq ($(strip $(ECC_RETRY_ENHANCEMENT)),TRUE)
  ifeq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: ECC_RETRY_ENHANCEMENT can only be turned on when __UMTS_RAT__ defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __GSM_RAT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: ECC_RETRY_ENHANCEMENT can only be turned on when __GSM_RAT__ defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __ECC_RETRY_ENHANCEMENT__
endif

ifeq ($(strip $(SML_SUPPORT)),TRUE)
  COM_DEFS += __SIM_ME_LOCK__
  ifdef TMO_SIM_LOCK
    ifeq ($(strip $(TMO_SIM_LOCK)),TRUE)
      COM_DEFS += __TMO_SIM_LOCK__
    endif
  endif
endif
    
ifneq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
  ifeq ($(strip $(FAST_DORMANCY_SUPPORT)),TRUE)
    COM_DEFS     += __FAST_DORMANCY__
    COM_DEFS     += __DIALUP_GPRS_COUNTER_SUPPORT__
  endif
  ifeq ($(strip $(FAST_DORMANCY_SUPPORT)),FALSE)
    COM_DEFS     += __NO_PSDATA_SEND_SCRI__
    COM_DEFS     += __DIALUP_GPRS_COUNTER_SUPPORT__
  endif
endif

ifeq ($(filter __TC02__,$(strip $(COM_DEFS))),)
  ifneq ($(filter __TC02_SECURITY_REQUIREMENT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: __TC02_SECURITY_REQUIREMENT__ can only be turned on for MOTO project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef SML_SUPPORT
  ifneq ($(strip $(SML_SUPPORT)),TRUE)
    ifneq ($(filter __TC02_SECURITY_REQUIREMENT__,$(strip $(COM_DEFS))),)
      $(warning ERROR: __TC02_SECURITY_REQUIREMENT__ need set SML_SUPPORT = TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef COSMOS_3D_VERSION
  ifneq ($(strip $(COSMOS_3D_VERSION)),NONE)
    ifeq ($(filter __VENUS_3D_UI_ENGINE__,$(strip $(COM_DEFS))),)
      $(call DEP_ERR_SETA_OR_OFFB,VENUS_MMI,VENUS_3D,COSMOS_3D_VERSION)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter __L4_INIT_MULTIUSB_COM__,$(COM_DEFS)),)
  ifeq ($(filter __USB_MULTIPLE_COMPORT_SUPPORT__,$(COM_DEFS)),)
    $(warning ERROR: __L4_INIT_MULTIUSB_COM__ can only be defined when __USB_MULTIPLE_COMPORT_SUPPORT__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# EMI latency setting, MPLLDISABLED, MPLLXHALF, MPLLX1, MPLLX2, MPLLX3, MPLLX4

MPLL_SETTING_FOR =  MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK))

ifdef $(MPLL_SETTING_FOR)
  MPLL_SETTING      =  $(MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK)))
endif
COM_DEFS    += $(MCU_CLOCK) $(EXT_CLOCK) $(MPLL_SETTING)

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
   COM_DEFS    += DCM_ENABLE
endif

COMPLIST += sst_sec
COMPLIST += che
COMPLIST += keygen

COMP_TRACE_DEFS_MODEM  +=  ${CORE_ROOT}/modem/keygen/include/keygen_trc.h


ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  COMPLIST    +=  drv mc
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R9_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__ __REL6__ __UMTS_R7__ __REL7__ __UMTS_R8__ __REL8__ __UMTS_R9__ __REL9__
                  __HSDPA_2MS_DATA_IND__ __HSDPA_2MS_DATA_IND_LATENCY_IMPROVE__ __FDD_REDIRECTION__ __PPACR_SUPPORT__ __CMCC_FR__ __SIB19_DEFFER__ __3G_CSG_SUPPORT__
  
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__ __FDD_MAC_EHS_SUPPORT__ __FDD_ENHANCED_COMMON_STATE_SUPPORT__ __FDD_HSDSCH_DRX_CELL_FACH_SUPPORT__
    ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    ifeq ($(strip $(UMTS_TDD_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    
    ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSUPA_SUPPORT__ __DCHSDPA_ADJ_FREQ_SUPPORT__ __FDD_CPC_SUPPORT__ __FDD_COMMON_EDCH_SUPPORT__ __FDD_MAC_IIS_SUPPORT__ __HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__
      
      ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        COM_DEFS    +=   FDD_EDCH_CATEGORY=$(strip $(FDD_EDCH_PHYSICAL_CATEGORY))
      endif

      ifeq ($(call gt,$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),12),T)
         ifneq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),15)
            ifneq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),16)
                 COM_DEFS    +=   __HOM_DL64QAM_SUPPORT__
            endif
         endif
      endif

      ifeq ($(call gt,$(strip $(FDD_EDCH_PHYSICAL_CATEGORY)),6),T)
           COM_DEFS    +=   __HOM_UL16QAM_SUPPORT__
      endif

      ifeq ($(strip $(UMTS_TDD_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
        COM_DEFS    +=   TDD_EDCH_CATEGORY=$(strip $(TDD_EDCH_PHYSICAL_CATEGORY))
        ifeq ($(strip $(TDD_HSPA_PLUS_SUPPORT)),TRUE)
          COM_DEFS    +=   __TDD_ENHANCED_COMMON_STATE_SUPPORT__
          COM_DEFS    +=   __TDD_CPC_SUPPORT__
          COM_DEFS    +=   __TDD_COMMON_EDCH_SUPPORT__
          COM_DEFS    +=   __TDD_MAC_IIS_SUPPORT__
          COM_DEFS    +=   __TDD_MAC_EHS_SUPPORT__
          COM_DEFS    +=   __TDD128_HSPA_PLUS__
        endif
      endif
    endif
  endif
  ifeq ($(strip $(NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION)),TRUE)
    COM_DEFS    +=   __NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION__
  endif
  ifeq ($(strip $(R7R8_FULL_SET_SUPPORT)),TRUE)
    COM_DEFS    +=   __CUSTOMIZE_ENHANCED_COMMON_STATE_SUPPORT__ __CUSTOMIZE_CSHSPA_SUPPORT__ __CUSTOMIZE_HSSCCH_LESS_SUPPORT__ __CUSTOMIZE_UEA2_UIA2_SUPPORT__
    COM_DEFS    +=   __CUSTOMIZE_MAC_IIS_SUPPORT__ __CUSTOMIZE_HSDSCH_DRX_CELL_FACH_SUPPORT__ __CUSTOMIZE_COMMON_EDCH_SUPPORT__ __CUSTOMIZE_HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__
    COM_DEFS    +=   __CUSTOMIZE_RFC2507_SUPPORT__
  endif
endif

ifneq ($(filter __DYNAMIC_HSPA_PREFERENCE__,$(COM_DEFS)),)
  ifeq ($(filter __HSPA_PREFERENCE_SETTING__,$(strip $(COM_DEFS))),)
    $(error ERROR: PLEASE turn off __DYNAMIC_HSPA_PREFERENCE__ when __HSPA_PREFERENCE_SETTING__ is not defined.)
  endif
endif

ifeq ($(filter __UMTS_R6__,$(strip $(COM_DEFS))),)
  ifneq ($(filter __R6_DSAC__,$(strip $(COM_DEFS))),)
    $(error __R6_DSAC__ can only be turned on when __UMTS_R6__ defined)
  endif
endif

ifneq ($(filter __UMTS_R6__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __R6_DSAC__,$(strip $(COM_DEFS))),)
    COM_DEFS += __R6_DSAC__
  endif
endif

ifneq ($(filter __REL7__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __R7_EHPLMN__,$(strip $(COM_DEFS))),)
    COM_DEFS += __R7_EHPLMN__
  endif
  ifeq ($(filter __PLMN_LIST_WITH_LAC__,$(strip $(COM_DEFS))),)
    COM_DEFS += __PLMN_LIST_WITH_LAC__
  endif
endif

ifneq ($(filter __REL8__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __ETWS_SUPPORT__,$(strip $(COM_DEFS))),)
    COM_DEFS += __ETWS_SUPPORT__ __EXT_SEG_CTRL_BLK__
  endif
endif

ifeq ($(filter __CPHS__,$(COM_DEFS)),)
  ifeq ($(filter __REL4__,$(COM_DEFS)),)
    ifneq ($(filter __SS_CPHS_QUERY_CFU_ALWAYS__,$(strip $(COM_DEFS))),)
      $(error ERROR: PLEASE turn on __CPHS__ or __REL4__ when __SS_CPHS_QUERY_CFU_ALWAYS__ is on)
    endif
  endif
endif

ifneq ($(filter __KTEST__,$(CUSTOM_OPTION)),)
  COMPLIST += ktest
endif

ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  COMPLIST += cipher
endif

ifneq ($(filter DUAL_LCD,$(COM_DEFS)),)
  ifeq ($(strip $(SUB_LCD_SIZE)),NONE)
    ifneq ($(strip $(PLATFORM)),TK6516)
        $(warning ERROR: Please set SUB_LCD_SIZE when DUAL LCD (LCD_MODULE=$(strip $(LCD_MODULE))) is used)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter __ACL_SUPPORT__,$(COM_DEFS)),)
  ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    $(warning ERROR:  __ACL_SUPPORT__ cannot be defined if __PS_SERVICE__ not defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifneq ($(filter __UCM_SUPPORT__,$(COM_DEFS)),)
  COM_DEFS    += __FORCE_RELEASE__
endif

ifneq ($(filter __CTP_SHIFT_FOR_HVGA_LCM__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __MTK_INTERNAL__,$(strip $(COM_DEFS))),)
    $(warning ERROR: __CTP_SHIFT_FOR_HVGA_LCM__ is only available for VICTOR56V12 MTK internal project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

#Rachel 20131125 add dependency for __4G_SW_DISABLE__
ifneq ($(filter __4G_SW_DISABLE__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __MTK_INTERNAL__,$(strip $(COM_DEFS))),)
    $(warning ERROR: __4G_SW_DISABLE__ is only available for MTK internal project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif 

ifeq ($(filter __EM_MODE__,$(CUSTOM_OPTION)),)
  COM_DEFS  := $(filter-out __SLIM_MODEM_EM_MODE__ __MODEM_EM_MODE__,$(COM_DEFS))
endif

ifneq ($(filter __R7_EHPLMN__,$(strip $(COM_DEFS))),)
  COM_DEFS += __SEARCH_ALL_EHPLMN_TOGETHER__
endif

ifeq ($(strip $(SDIO_DEVICE_CONNECTIVITY)),ENABLE)
  COM_DEFS += __SDIO_DEVICE_CONNECTIVITY__
  COMPLIST += sdio_device
  COMMINCDIRS    += ${CORE_ROOT}/interface/driver/connectivity/sdio_device
endif

CHK_UPPER_CASE = $(shell perl ${COMMON_ROOT}/tools/chkUpperCase.pl "$(PROJECT_MAKEFILE)")
ifneq ($(strip $(CHK_UPPER_CASE)),)
  $(warning ERROR: $(strip $(CHK_UPPER_CASE)).)
  DEPENDENCY_CONFLICT = TRUE
endif

COMPLIST += tdd_drv

ifneq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
  COM_DEFS    +=  __SMART_PAGING_3G_FDD__
endif

# Non LTE single-mode
ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  ifneq ($(filter __REL7__,$(strip $(COM_DEFS))),)
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      COM_DEFS    +=   __MEDIATEK_SMART_QOS__
    endif
  endif
endif

ifdef CCCI_FS_SUPPORT
  ifeq ($(strip $(CCCI_FS_SUPPORT)), TRUE)
    COM_DEFS += __CCCIFS_SUPPORT__
    COM_DEFS += __NVRAM_IMPORTANT_PARTITIONS__
  endif
    COMPLIST += fs
else
  COMPLIST += fs
endif

ifeq ($(strip $(BTT_AGENT_ENABLE)),TRUE)
  ifneq ($(strip $(DHL_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,DHL_SUPPORT,BTT_AGENT_ENABLE)
    DEPENDENCY_CONFLICT = TRUE
  else
    COMPLIST    += btt_agent
    COM_DEFS    += BTT_USE_DHL_VC __BTT_AGENT_ENABLE__
  endif
endif

ifneq ($(filter __23G_PRI_RESEL_SUPPORT__,$(COM_DEFS)),)
  COM_DEFS    +=  __PRI_RESEL_SUPPORT__
endif

ifeq ($(strip $(IMS_SUPPORT)),TRUE)
  COM_DEFS    += __IMS_SUPPORT__ __ISIM_SUPPORT__
  ifeq ($(strip $(VOLTE_SUPPORT)),TRUE)
    COM_DEFS    += __VOLTE_SUPPORT__
    COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/middleware/lte/csr/inc/ltecsr_trc.h 
    ifeq ($(strip $(EVS_SUPPORT)),TRUE)
        COM_DEFS    += __EVS_SUPPORT__
        COMPOBJS += ${CORE_ROOT}/driver/sphevs/lib/libEVS.a
    endif
  endif
  ifeq ($(strip $(VOHSPA_SUPPORT)),TRUE)
    COM_DEFS    += __VOHSPA_SUPPORT__
  endif
  ifeq ($(strip $(WFC_SUPPORT)),TRUE)
    COM_DEFS += __WFC_SUPPORT__
    ifeq ($(strip $(EVS_SUPPORT)),TRUE)
        COM_DEFS    += __EVS_SUPPORT__
        COMPOBJS += ${CORE_ROOT}/driver/sphevs/lib/libEVS.a
    endif    
  endif
  ifneq ($(strip $(GEMINI)),FALSE)
    ifeq ($(strip $(MULTIPLE_IMS_SUPPORT)),TRUE)
        COM_DEFS    += __MULTIPLE_IMS_SUPPORT__
    endif
  endif 
  ifeq ($(strip $(IMS_OTA_MESSAGE_SUPPORT)),TRUE)
      COM_DEFS    += __IMS_OTA_MESSAGE_SUPPORT__
  endif 
endif

# SPHEVS
COMPLIST += sphevs
COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/sphevs/sp_EVS_trc.h

ifeq ($(strip $(UE_SIMULATOR)),TRUE)
  COM_DEFS += DHL_DEFAULT_FILTER_OFF
endif

ifdef USB_FW_DL_SUPPORT
  ifeq ($(strip $(USB_FW_DL_SUPPORT)),TRUE)
    COM_DEFS += __USB_FW_DL_SUPPORT__
  endif
endif

ifeq ($(strip $(DCS_TX_NOTCH_SWITCH_SUPPORT)),TRUE)
  COM_DEFS    += __DCS_TX_NOTCH_SWITCH_SUPPORT__
endif

ifeq ($(strip $(CTA_ECC_SUPPORT)),TRUE)
    COM_DEFS    += __CTA_ECC_SUPPORT__
endif

ifeq ($(strip $(CSFB_WITH_SGLTE_HW_SUPPORT)),TRUE)
  COM_DEFS    += __CSFB_WITH_SGLTE_HW__
endif

ifeq ($(strip $(2G_MIPI_INTERSLOT_RAMPING_OPTIMIZE_SUPPORT)),TRUE)
  COM_DEFS    += __2G_MIPI_INTERSLOT_RAMPING_OPTIMIZE_SUPPORT__
endif

ifdef SET_IMEI_BY_PLMN
  ifeq ($(strip $(SET_IMEI_BY_PLMN)),TRUE)
    COM_DEFS    += __SET_IMEI_BY_PLMN__
  endif
endif

ifdef LTE_TX_PATH_SWITCH_SUPPORT
  ifeq ($(strip $(LTE_TX_PATH_SWITCH_SUPPORT)),TRUE)
    COM_DEFS += __LTE_TX_PATH_SWITCH_SUPPORT__
  endif
endif

ifeq ($(strip $(DUAL_MODEM_SUPPORT)),TRUE)
  COM_DEFS    += __DUAL_MODEM_SUPPORT__
endif

ifdef TX_POWER_OFFSET_SUPPORT
  ifeq ($(strip $(TX_POWER_OFFSET_SUPPORT)),TRUE)
    COM_DEFS += __TX_POWER_OFFSET_SUPPORT__
  endif
endif

ifdef DSP_IMG_ON_EMI
  ifeq ($(strip $(DSP_IMG_ON_EMI)),TRUE)
    ifneq ($(filter MT6752,$(PLATFORM)),)
      ifeq ($(strip $(MDSYS)),MD1)
        COM_DEFS += __DSP_IMG_ON_EMI__
      else
        $(warning ERROR: Can NOT set DSP_IMG_ON_EMI = TRUE on $(PLATFORM) $(MDSYS).)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef DHL_SET_LOG_BUF_SIZ
  ifneq ($(strip $(DHL_SET_LOG_BUF_SIZ)),NONE)
    ifeq ($(strip $(DHL_SUPPORT)),TRUE)
      COM_DEFS += FORCE_DHL_RING_BUFFER_SCALE=$(strip $(DHL_SET_LOG_BUF_SIZ))
    endif
  endif
endif

#####
# COMMON SECTION used by build.mak and custom_release.mak
#####

COMP_TRACE_DEFS = $(COMP_TRACE_DEFS_MODEM) $(COMP_TRACE_DEFS_FP)

# *************************************************************************
# Include extra dependency check.
# *************************************************************************
-include make/common/Extra_dep.mak

# Generate CUS_REL_SRC_COMP/REL_MTK_COMP
CUS_REL_SRC_COMP_TEMP := $(filter $(REL_SRC_COMP),$(COMPLIST))
CUS_REL_SRC_COMP += $(CUS_REL_SRC_COMP_TEMP)

CUS_REL_MTK_COMP_TEMP := $(filter $(REL_MTK_COMP),$(COMPLIST))
CUS_REL_MTK_COMP += $(CUS_REL_MTK_COMP_TEMP)
#


ifneq ($(findstring FPGA,$(ORIGINAL_PROJECT_NAME)),)
  ifneq ($(findstring EL1S,$(ORIGINAL_FLAVOR)),)
    COM_DEFS += __L1_ISR_DISABLE__
    COM_DEFS += __L1_TASK_DISABLE__
    COM_DEFS += __L1_PCORE_TASK_DISABLE__  
    #COM_DEFS += __DUMMYMPAL_TASK_DISABLE__
    COM_DEFS += __UL1_TASK_DISABLE__
    COM_DEFS += __EL1D_ENABLE__
  endif
endif

ifneq ($(findstring L1DISABLE,$(ORIGINAL_FLAVOR)),)
  COM_DEFS += __L1_ISR_DISABLE__
  COM_DEFS += __L1_TASK_DISABLE__
  COM_DEFS += __L1_PCORE_TASK_DISABLE__
  #COM_DEFS += __DUMMYMPAL_TASK_DISABLE__
  COM_DEFS += __UL1_TASK_DISABLE__
endif

# Remove the REMOVE_CUSTOM_OPTION specified in project makefile from COM_DEFS
COM_DEFS  := $(filter-out $(REMOVE_CUSTOM_OPTION),$(COM_DEFS))

CLEANROOM_COMP = j2me_11 j2me_hi sb51 sbpki2 sslplus5 bsci wndrv supc

###########################################
#temp add for module list
###########################################

ifeq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
ifeq ($(LTE_SOURCE_BUILD),TRUE)
COMPLIST += $(LTE_SEC_COMP)
CUS_REL_MTK_COMP += $(LTE_SEC_COMP)
endif
endif

ifeq ($(strip $(ATEST_SYS_ENABLE)),TRUE)
include make/${CORE_ROOT}/module/middleware/autotest/atest_sys.mak
endif

ifdef VARIATION_PROJ
ifneq ($(strip $(VARIATION_PROJ)),)
include make/common/variation/$(strip $(VARIATION_PROJ)).mak
CUS_REL_SRC_COMP_TEMP := $(filter $(REL_SRC_COMP) $(CUS_REL_SRC_COMP),$(COMPLIST))
CUS_REL_SRC_COMP := $(CUS_REL_SRC_COMP_TEMP)
CUS_REL_MTK_COMP_TEMP := $(filter $(REL_MTK_COMP) $(CUS_REL_MTK_COMP),$(COMPLIST))
CUS_REL_MTK_COMP := $(CUS_REL_MTK_COMP_TEMP)
endif
endif

# consistency check for COMPLIST & CUS_REL_XXX_COMP
# check each comp in $(COMPLIST) if it has been put in $(CUS_REL_XXX_COMP)
COMPLIST_NO_REL_TYPE_COMP = $(filter-out $(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP),$(COMPLIST))
COMPLIST_NO_REL_TYPE_COMP := $(filter-out $(CLEANROOM_COMP),$(COMPLIST_NO_REL_TYPE_COMP))
ifneq ($(words $(COMPLIST_NO_REL_TYPE_COMP)),0)
  $(warning ERROR: $(foreach comp,$(COMPLIST_NO_REL_TYPE_COMP),"$(comp)") in COMPLIST but NOT in CUS_REL_XXX_COMP)
  DEPENDENCY_CONFLICT = TRUE
endif

# check each comp in $(CUS_REL_XXX_COMP) if it has been put in $(COMPLIST)
CREL_COMP_NOT_COMPLIST = $(filter-out $(COMPLIST),$(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP))
CREL_COMP_NOT_COMPLIST := $(filter-out bootloader bootloader_ext,$(CREL_COMP_NOT_COMPLIST))
# CREL_COMP_NOT_COMPLIST := $(filter-out fota,$(CREL_COMP_NOT_COMPLIST))
ifneq ($(words $(CREL_COMP_NOT_COMPLIST)),0)
  $(warning ERROR: $(foreach comp,$(CREL_COMP_NOT_COMPLIST),"$(comp)") in CUS_REL_XXX_COMP but NOT in COMPLIST)
  DEPENDENCY_CONFLICT = TRUE
endif

# check no module define in $(CUS_REL_SRC_COMP) and $(CUS_REL_MTK_COMP) both
COMP_BOTH_IN_SRC_MTK = $(filter $(CUS_REL_SRC_COMP),$(CUS_REL_MTK_COMP))
ifneq ($(words $(COMP_BOTH_IN_SRC_MTK)),0)
  $(warning ERROR: $(foreach comp,$(COMP_BOTH_IN_SRC_MTK),"$(comp)") in CUS_REL_SRC_COMP but also in CUS_REL_MTK_COMP)
  DEPENDENCY_CONFLICT = TRUE
endif

# COMPLIST(during CUSTOM_RELEASE)      = CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  COMPLIST =     $(strip $(CUS_REL_SRC_COMP))
  COMPLIST := $(filter-out bootloader bootloader_ext,$(COMPLIST))
endif

# check the COM_DEFS value
COM_DEFS_INVALID_LIST := TRUE FALSE ENABLE DISABLE FULL SLIM NONE
ifdef COM_DEFS
  COM_DEFS_INVALID_VALUE := $(filter $(strip $(COM_DEFS)),$(COM_DEFS_INVALID_LIST))
  ifneq ($(COM_DEFS_INVALID_VALUE),)
    $(warning ERROR: COM_DEFS value ($(strip $(COM_DEFS_INVALID_VALUE))) is NOT allowable, please do Not assign COM_DEFS value as : ($(strip $(COM_DEFS_INVALID_LIST)))) 
    DEPENDENCY_CONFLICT = TRUE 
  endif
endif

# L1_TMD_FILES check: the LTE security files can NOT be added to L1_TMD_FILES.
ifdef L1_TMD_FILES
L1_TMD_FILES_TEMP := $(filter ${PCORE_ROOT}/modem/lte_sec/% ,$(L1_TMD_FILES))
L1_TMD_FILES_TEMP := $(filter ${L1CORE_ROOT}/modem/lte_sec/% ,$(L1_TMD_FILES_TEMP))
  ifneq ($(strip $(L1_TMD_FILES_TEMP)),)
    $(warning ERROR: L1_TMD_FILES value $(foreach comp,$(L1_TMD_FILES_TEMP),"$(comp)") is NOT allowable,)
    $(warning ERROR: the LTE security files can NOT be added to L1_TMD_FILES.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# COMP_TRACE_DEFS_MODEM check: the LTE security files can NOT be added to COMP_TRACE_DEFS_MODEM
ifdef COMP_TRACE_DEFS_MODEM
COMP_TRACE_DEFS_MODEM_TEMP := $(filter ${PCORE_ROOT}/modem/lte_sec/% ,$(COMP_TRACE_DEFS_MODEM))
COMP_TRACE_DEFS_MODEM_TEMP := $(filter ${L1CORE_ROOT}/modem/lte_sec/% ,$(COMP_TRACE_DEFS_MODEM_TEMP))
  ifneq ($(strip $(COMP_TRACE_DEFS_MODEM_TEMP)),)
    $(warning ERROR: COMP_TRACE_DEFS_MODEM value $(foreach comp,$(COMP_TRACE_DEFS_MODEM_TEMP),"$(comp)") is NOT allowable,)
    $(warning ERROR: the LTE security files can NOT be added to COMP_TRACE_DEFS_MODEM.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# L1_TMD_FILES_LTE_SEC check: only the LTE security files can be added.
ifdef L1_TMD_FILES_LTE_SEC
L1_TMD_FILES_LTE_SEC_TEMP := $(filter-out ${PCORE_ROOT}/modem/lte_sec/% ,$(L1_TMD_FILES_LTE_SEC))
L1_TMD_FILES_LTE_SEC_TEMP := $(filter-out ${L1CORE_ROOT}/modem/lte_sec/% ,$(L1_TMD_FILES_LTE_SEC_TEMP))
  ifneq ($(strip $(L1_TMD_FILES_LTE_SEC_TEMP)),)
    $(warning ERROR: L1_TMD_FILES_LTE_SEC value $(foreach comp,$(L1_TMD_FILES_LTE_SEC_TEMP),"$(comp)") is NOT allowable,)
    $(warning ERROR: only the LTE security files can be added to L1_TMD_FILES_LTE_SEC.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# COMP_TRACE_DEFS_MODEM_LTE_SEC check: only the LTE security files can be added.
ifdef COMP_TRACE_DEFS_MODEM_LTE_SEC
COMP_TRACE_DEFS_MODEM_LTE_SEC_TEMP := $(filter-out ${PCORE_ROOT}/modem/lte_sec/% ,$(COMP_TRACE_DEFS_MODEM_LTE_SEC))
COMP_TRACE_DEFS_MODEM_LTE_SEC_TEMP := $(filter-out ${L1CORE_ROOT}/modem/lte_sec/% ,$(COMP_TRACE_DEFS_MODEM_LTE_SEC_TEMP))
  ifneq ($(strip $(COMP_TRACE_DEFS_MODEM_LTE_SEC_TEMP)),)
    $(warning ERROR: COMP_TRACE_DEFS_MODEM_LTE_SEC value $(foreach comp,$(COMP_TRACE_DEFS_MODEM_LTE_SEC_TEMP),"$(comp)") is NOT allowable,)
    $(warning ERROR: only the LTE security files can be added to COMP_TRACE_DEFS_MODEM_LTE_SEC.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifneq ($(strip $(FLAVOR)), $(strip $(ORIGINAL_FLAVOR)))
   $(warning ERROR: ORIGINAL_FLAVOR value should be $(FLAVOR))
   DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifneq ($(strip $(PROJECT_NAME)), $(strip $(ORIGINAL_PROJECT_NAME)))
   $(warning ERROR: ORIGINAL_PROJECT_NAME value should be $(PROJECT_NAME))
   DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef DEPENDENCY_CONFLICT
  ifeq ($(strip $(DEPENDENCY_CONFLICT)),TRUE)
    $(error PLEASE check above dependency errors!)
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  RELEASE_LEVEL = NONE_RELEASE
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    RELEASE_LEVEL = SUB_RELEASE
  endif
endif

#rule for copy_br_bin
BR_FLAVOR := DEFAULT
BR_FILE   := cmdScript.bin
ifneq ($(strip $(CHIP_VER)),S00)
  BR_FLAVOR := $(CHIP_VER)
endif
ifneq ($(filter __FPGA__,$(strip $(COM_DEFS))),)
  BR_FLAVOR := FPGA
endif

# temp add
UNIVERSAL_DATABASE_SUPPORT = TRUE
