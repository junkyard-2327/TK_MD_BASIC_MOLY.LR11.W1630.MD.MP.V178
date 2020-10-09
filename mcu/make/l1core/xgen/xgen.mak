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

#  Define include path lists to XGEN_INC_DIR
#XGEN_INC_DIR = $(COMMINCDIRS)


  XGEN_INC_DIR +=   $(strip $(COMMON_ROOT))/interface/service/dhl

ifneq ($(strip $(L1_UMTS)),TRUE)
  XGEN_INC_DIR +=   $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/common/include \
                    $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/rrm/common/include \
                    $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/rrm/rmc/include \
                    $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/rrm/rcs/include \
                    $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/lapdm/include \
                    $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/mpal/include \
                    $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/rlc/include \
                    $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/mac/include \
                    $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/rrm/rmp/include \
                    $(strip ${PCORE_ROOT})/modem/nas/mm/cmm/include \
                    $(strip ${PCORE_ROOT})/modem/nas/mm/common/include \
                    $(strip ${PCORE_ROOT})/modem/nas/mm/pmm/include \
                    $(strip ${PCORE_ROOT})/modem/nas/ratcm/include \
                    $(strip ${PCORE_ROOT})/modem/nas/ratdm/include \
                    $(strip ${PCORE_ROOT})/modem/common/scsi/gen/include \
                    $(strip ${PCORE_ROOT})/modem/common/scsi/include \
                    $(strip ${COMMON_ROOT})/modem/interface/l1/inner \
                    $(strip ${L1CORE_ROOT})/modem/interface/l1/inner \
                    $(strip ${COMMON_ROOT})/interface/modem/l1/fdd/internal \
                    $(strip ${PCORE_ROOT})/interface/modem/l1/gsm/internal \
                    $(strip ${PCORE_ROOT})/service/fsm/include 

 ifdef GEMINI
    ifneq ($(strip $(GEMINI)),FALSE)
      XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/common/rsva/rsvas/include \
                        $(strip ${PCORE_ROOT})/modem/common/rsva/interface/enum \
                        $(strip ${PCORE_ROOT})/modem/common/rsva/interface/local_inc \
                        $(strip ${PCORE_ROOT})/modem/common/rsva/common/include

    endif
  endif
else
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    GAS_INC_SUPPORT = TRUE
  else
    ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
      GAS_INC_SUPPORT = TRUE
    endif
  endif
  ifeq ($(strip $(GAS_INC_SUPPORT)),TRUE)
      XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/common/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/rrm/common/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/rrm/rmc/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/rrm/rcs/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/lapdm/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/mpal/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/rlc/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/mac/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/rrm/rmp/include \
                      $(strip ${PCORE_ROOT})/modem/nas/mm/cmm/include \
                      $(strip ${PCORE_ROOT})/modem/nas/mm/common/include \
                      $(strip ${PCORE_ROOT})/modem/nas/mm/pmm/include \
                      $(strip ${PCORE_ROOT})/modem/nas/ratcm/include \
                      $(strip ${PCORE_ROOT})/modem/nas/ratdm/include \
                      $(strip ${PCORE_ROOT})/modem/common/scsi/gen/include \
                      $(strip ${PCORE_ROOT})/modem/common/scsi/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/interface/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/asn1/gen/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/common/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/interface/enum \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/interface/local_inc \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/common/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/bmc/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/csr/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/pdcp/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/rabm/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/umac/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/urlc/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/seq/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/urr/common/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/urr/meme/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/urr/rrce/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/urr/slce/include \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/urr/dbme/include \
                      $(strip $(PROJDIR))/l1core/modem/dbme \
                      $(strip $(PROJDIR_PCORE))/modem/dbme \
                      $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/urr/cise/include \
                      $(strip ${PCORE_ROOT})/service/fsm/include \
                      $(strip ${PCORE_ROOT})/interface/modem/secured \
                      $(strip ${PCORE_ROOT})/driver/bytecopy/inc \
                      $(strip ${PCORE_ROOT})/service/event_info \
                      ${COMMON_ROOT}/interface/modem/urr \
                      ${COMMON_ROOT}/interface/service/asn1_common \
                      $(strip $(COPRO_PROJDIR))/modem/rrc_asn \
                      $(strip ${L1CORE_ROOT})/modem/las/tise/interface \
                      ${COMMON_ROOT}/interface/modem/gas \
                      ${COMMON_ROOT}/interface/modem/general \
                      ${COMMON_ROOT}/interface/cross_core
      ifdef GEMINI
        ifneq ($(strip $(GEMINI)),FALSE)
          XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/common/rsva/rsvas/include \
                          $(strip ${PCORE_ROOT})/modem/common/rsva/interface/enum \
                          $(strip ${PCORE_ROOT})/modem/common/rsva/interface/local_inc \
                          $(strip ${PCORE_ROOT})/modem/common/rsva/common/include \
                          $(strip ${PCORE_ROOT})/modem/common/rsva/rsvak/include \
                          $(strip ${PCORE_ROOT})/modem/common/rsva/rsvau/include \
                          $(strip ${PCORE_ROOT})/modem/common/rsva/rsvag/include  
        endif
      endif
      XGEN_INC_DIR += $(strip ${PCORE_ROOT})/interface/uas
  endif
endif


ifeq ($(strip $(L1_UMTS)),TRUE)
  XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/nas/sndcp/include \
                  $(strip ${PCORE_ROOT})/modem/nas/sm/include \
                  $(strip ${PCORE_ROOT})/modem/nas/llc/include \
                  $(strip ${PROJDIR_PCORE})/modem/dbme/fdd \
                  $(strip ${PROJDIR_PCORE})/modem/dbme/tdd \
                  $(strip ${COMMON_ROOT})/modem/uas/urr/dbme/include \
                  $(strip ${COMMON_ROOT})/modem/uas_tdd128/urr/dbme/include \
                  $(strip ${L1CORE_ROOT})/modem/las/uise/ldbme/include \
                  $(strip ${L1CORE_ROOT})/modem/las/tise/ldbme/include
else
  ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
    ifeq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
      XGEN_INC_DIR +=   $(strip ${PCORE_ROOT})/modem/nas/sndcp/include \
                        $(strip ${PCORE_ROOT})/modem/nas/sm/include \
                        $(strip ${PCORE_ROOT})/modem/nas/llc/include
    endif
  endif
endif

# EL1 CODEGEN PATH
XGEN_INC_DIR     += ${L1CORE_ROOT}/modem/el1/el1d/inc/cm \
                    ${L1CORE_ROOT}/modem/el1/el1d/inc/common \
                    ${L1CORE_ROOT}/modem/el1/el1d/inc/cs \
                    ${L1CORE_ROOT}/modem/el1/el1d/inc/pos \
                    ${L1CORE_ROOT}/modem/el1/el1d/inc/ps \
                    ${L1CORE_ROOT}/modem/el1/el1d/inc/rfdfe \
                    ${L1CORE_ROOT}/modem/el1/el1d/inc/rx \
                    ${L1CORE_ROOT}/modem/el1/el1d/inc/tx \
                    ${L1CORE_ROOT}/modem/el1/el1d_pub/trc \
                    ${L1CORE_ROOT}/modem/el1/el1d_pub/inc/common \
                    ${L1CORE_ROOT}/modem/el1/el1c/interface \
                    ${L1CORE_ROOT}/modem/el1/common \
                    $(strip $(EL1_FOLDER))/irt/include    \
                    $(strip $(EL1_FOLDER))/irt/src        \
                    $(strip $(EL1_FOLDER))/common/include \
                    $(strip $(EL1_FOLDER))/interface      \
                    ${CORE_ROOT}/modem/lte_sec/common/include     \
                    ${COMMON_ROOT}/modem/lte_sec/interface/el1      \
                    $(strip $(EL1_FOLDER))/csr/include    \
                    $(strip $(EL1_FOLDER))/csr/src        \
                    $(strip $(EL1_FOLDER))/meas/include   \
                    $(strip $(EL1_FOLDER))/meas/src       \
                    $(strip $(EL1_FOLDER))/ch/include     \
                    $(strip $(EL1_FOLDER))/ch/src         \
                    $(strip $(EL1_FOLDER))/common/include \
                    ${L1CORE_ROOT}/modem/lte_sec/interface/etmr \
                    ${L1CORE_ROOT}/modem/lte_sec/interface
                    
XGEN_INC_DIR    += $(strip ${PCORE_ROOT})/modem/common/config/include \
                   $(strip ${PCORE_ROOT})/modem/nas/cc-ss/cc/include \
                   $(strip ${PCORE_ROOT})/modem/nas/sms/include \
                   $(strip ${PCORE_ROOT})/middleware/$(strip $(PPP_FOLDER))/include \
                   $(strip ${PCORE_ROOT})/modem/nas/data/include \
                   $(strip ${PCORE_ROOT})/modem/nas/data/l2r/include \
                   $(strip ${PCORE_ROOT})/modem/nas/data/rlp/include \
                   $(strip ${PCORE_ROOT})/modem/nas/data/tdt/include \
                   $(strip ${PCORE_ROOT})/modem/nas/data/t30/include \
                   $(strip ${PCORE_ROOT})/modem/nas/data/fa/include \
                   $(strip ${PCORE_ROOT})/modem/common/mcd/include \
                   $(strip ${PCORE_ROOT})/modem/ircomm/include \
                   $(strip ${PCORE_ROOT})/modem/gl1/l1_dm/common \
                   $(strip ${COMMON_ROOT})/modem/interface/l1/gsm \
                   $(strip ${L1CORE_ROOT})/modem/interface/l1/inner \
                   $(strip ${COMMON_ROOT})/modem/interface/l1/inner \
                   $(strip ${L1CORE_ROOT})/modem/interface/l1/tdd \
                   $(strip ${PCORE_ROOT})/modem/interface/l1/fdd \
                   $(strip ${PCORE_ROOT})/modem/interface/l1/tdd \
                   $(strip ${PCORE_ROOT})/modem/interface/l4 \
                   $(strip ${PCORE_ROOT})/modem/interface/l4misc \
                   $(strip ${PCORE_ROOT})/modem/interface/general \
                   $(strip ${PCORE_ROOT})/modem/interface/asn/rr/include \
                   $(strip ${PCORE_ROOT})/modem/l4/include \
                   $(strip ${PCORE_ROOT})/modem/l4/csm \
                   $(strip ${PCORE_ROOT})/modem/l4/csm/cc/include \
                   $(strip ${PCORE_ROOT})/modem/l4/smu/include \
                   $(strip ${PCORE_ROOT})/modem/l4/smsal/include \
                   $(strip ${PCORE_ROOT})/modem/l4/tcm/common \
                   $(strip ${PCORE_ROOT})/modem/l4/rac/include \
                   $(strip ${PCORE_ROOT})/modem/interface/mcd/include \
                   $(strip ${PCORE_ROOT})/modem/l4/tcm/ugtcm \
                   $(strip ${CORE_ROOT})/service/sst/include \
                   $(strip ${COMMON_ROOT})/service/sst/include \
                   $(strip $(COMMON_ROOT))/service/kal/common/include \
                   $(strip $(COMMON_ROOT))/service/kal/mlib/include \
                   $(strip ${PCORE_ROOT})/middleware/interfaces/local_inc \
                   $(strip ${PCORE_ROOT})/middleware/media/audio/include \
                   $(strip ${PCORE_ROOT})/middleware/media/common/include \
                   $(strip ${COMMON_ROOT})/interface/modem/l1/fdd/internal \
                   $(strip ${L1CORE_ROOT})/interface/modem/el1c \
                   $(strip ${PCORE_ROOT})/interface/modem/l1/gsm/internal 
  
XGEN_INC_DIR += ${COMMON_ROOT}/modem/ul1/common
#XGEN_INC_DIR += ${COMMON_ROOT}/modem/ul1/common
                  
ifdef RFC2507_SUPPORT
  ifeq ($(strip $(RFC2507_SUPPORT)),TRUE)
    XGEN_INC_DIR    += $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/rfc2507/include
  endif
endif

ifdef AGPS_SUPPORT
  ifneq ($(strip $(AGPS_SUPPORT)), NONE)
    ifeq ($(strip $(AGPS_SUPPORT)), USER_PLANE)
      XGEN_INC_DIR     += inet_ps/supl/include
      XGEN_INC_DIR     += $(strip ${PCORE_ROOT})/modem/agps/rrlp/include
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
      XGEN_INC_DIR     += inet_ps/supl/include
      XGEN_INC_DIR     += $(strip ${PCORE_ROOT})/modem/agps/rrlp/include
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
      XGEN_INC_DIR     += $(strip ${PCORE_ROOT})/modem/agps/rrlp/include
    endif
  endif
endif


ifdef USB_TETHERING
  ifeq ($(strip $(USB_TETHERING)),TRUE)
    XGEN_INC_DIR    += $(strip ${PCORE_ROOT})/middleware/ups/rndis/include
  endif
endif

ifdef NDIS_SUPPORT
  ifeq ($(strip $(NDIS_SUPPORT)),UPS)
    XGEN_INC_DIR    += $(strip ${PCORE_ROOT})/middleware/ups/ups/include
  endif
endif



ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
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
  ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
    FLC_LIB_INCLUDE_CONDITION = TRUE
  endif
  ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
    FLC_LIB_INCLUDE_CONDITION = TRUE
  endif
  ifeq ($(strip $(FLC_LIB_INCLUDE_CONDITION)),TRUE)
    XGEN_INC_DIR += $(strip $(PPCORE_ROOT))/service/$(strip $(FLC_FOLDER))/include
  endif
endif


ifdef GEMINI
  ifneq ($(strip $(GEMINI)),FALSE)
    XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/common/as_semaphore_utility/include
  endif
endif

XGEN_INC_DIR +=  $(strip ${PCORE_ROOT})/modem/common/mcddll/include
XGEN_INC_DIR +=  $(strip ${PCORE_ROOT})/modem/l4/dt/include
XGEN_INC_DIR +=  inet_ps/ems/include $(strip ${PCORE_ROOT})/modem/nas/cc-ss/ss/include

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      XGEN_INC_DIR       += $(strip ${PCORE_ROOT})/modem/l4/dt/include
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  XGEN_INC_DIR += inet_ps/ems/include
endif

XGEN_INC_DIR    +=  external_mmi/wise/bal/telephony/include \
                    $(strip ${PCORE_ROOT})/modem/interface/asn/asn1lib/include \
                    $(strip ${PCORE_ROOT})/modem/gl1/l1_dm/common 

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
    XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/$(strip $(GAS_FOLDER))/mpal/include
  endif
endif

#COMMINCDIRS += $(strip ${PCORE_ROOT})/modem\common\rsva\interface\sap 
#COMMINCDIRS += $(strip ${PCORE_ROOT})/modem\common\rsva\interface\enum

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/interface/l1/l1s
endif

ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
  XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/ul1/ul1_hs/ul1c \
                  $(strip ${PCORE_ROOT})/modem/ul1/ul1_hs/ul1d \
                  $(strip ${L1CORE_ROOT})/modem/ul1/common \
                  $(strip ${PCORE_ROOT})/modem/md_sm/ul1sm \
                  $(strip ${PCORE_ROOT})/modem/md_sm/common\ul1sm
else ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLUS_PLATFORM)),)
  XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/ul1/ul1_hs_plus/ul1c \
                  $(strip ${PCORE_ROOT})/modem/ul1/ul1_hs_plus/ul1d \
                  $(strip ${PCORE_ROOT})/modem/ul1/ul1_hs_plus/common \
                  $(strip ${PCORE_ROOT})/modem/md_sm/ul1sm \
                  $(strip ${PCORE_ROOT})/modem/md_sm/common\ul1sm
endif

ifdef AGPS_SUPPORT
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
      XGEN_INC_DIR    +=  $(strip ${PCORE_ROOT})/modem/agps/ulcs/common/include
      XGEN_INC_DIR    +=  $(strip ${PCORE_ROOT})/modem/agps/ulcs/uagps_up/include
      XGEN_INC_DIR    +=  $(strip ${PCORE_ROOT})/modem/agps/ulcs/uagps_cp/include 
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
      XGEN_INC_DIR    +=  $(strip ${PCORE_ROOT})/modem/agps/ulcs/common/include
      XGEN_INC_DIR    +=  $(strip ${PCORE_ROOT})/modem/agps/ulcs/uagps_up/include
      XGEN_INC_DIR    +=  $(strip ${PCORE_ROOT})/modem/agps/ulcs/uagps_cp/include 
    endif
endif

XGEN_INC_DIR += $(strip ${PCORE_ROOT})/interface/ul1interface/internal 

ifeq ($(strip $(L2_HSDPA_COPRO)), TRUE)
  ifeq ($(call gt,$(strip $(GPRS_MAX_PDP_SUPPORT)),6),T)
  else
    XGEN_INC_DIR     += $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/seq/include
  endif
endif

ifeq ($(strip $(L2_HSUPA_COPRO)), TRUE)
  ifneq ($(strip $(L2_HSDPA_COPRO)),TRUE)
  else
    XGEN_INC_DIR     += $(strip ${PCORE_ROOT})/modem/$(strip $(UAS_FOLDER))/ul2/seq/include
  endif
endif

XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/smt/l1s/dummyps/include/internal

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  XGEN_INC_DIR += dummyups/include/internal
endif

XGEN_INC_DIR += plutommi/service/browsersrv
XGEN_INC_DIR += $(strip ${COMMON_ROOT})/service/dhl/local_inc
XGEN_INC_DIR += $(strip ${L1CORE_ROOT})/modem/md_sm/l1sm \
                $(strip ${L1CORE_ROOT})/modem/md_sm/common/l1sm \
                $(strip ${PCORE_ROOT})/service/sys_svc_sec/inc \
                $(strip ${L1CORE_ROOT})/driver/sleep_drv/internal/inc \
                $(strip ${L1CORE_ROOT})/driver/sleep_drv/public/inc

XGEN_INC_DIR += $(strip ${CORE_ROOT})/service/dhl/database/gv \
                $(strip ${CORE_ROOT})/modem/lte_sec/dhl/database/gv \
                $(strip ${PCORE_ROOT})/service/dhl/database/unionTag \
                $(BUILD_TSTDIR)/database/unionTag \
                $(BUILD_TSTDIR)/database/pstrace_db \
                $(strip ${CORE_ROOT})/service/dhl/database \
                $(strip ${PCORE_ROOT})/custom/service/nvram \
                $(strip ${PCORE_ROOT})/interface/service/nvram \
                $(strip ${COMMON_ROOT})/modem/interface/l1/inner \
                $(strip ${L1CORE_ROOT})/modem/interface/l1/inner

XGEN_INC_DIR += $(strip ${PCORE_ROOT})/service/fs/common/include
XGEN_INC_DIR_TARGET := $(XGEN_INC_DIR)

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/nas/ratdm/include 
  XGEN_INC_DIR := $(strip ${PCORE_ROOT})/service/dhl/database_modis/gv \
                  $(strip ${PCORE_ROOT})/service/dhl/database_modis/unionTag \
                  $(BUILD_TSTDIR)/database_modis/unionTag \
                  $(XGEN_INC_DIR)
endif

XGEN_INC_DIR += $(strip ${PCORE_ROOT})/modem/smt/uesim/shu/hwsim/simulation/generic/dummy_sap \
                $(strip ${L1CORE_ROOT})/modem/ul1/common \
                $(strip ${L1CORE_ROOT})/modem/gl1/common \
                $(strip ${COMMON_ROOT})/interface/middleware/meta \
                $(strip ${PCORE_ROOT})/interface/driver/peripheral \
                $(strip ${PCORE_ROOT})/interface/driver/connectivity/usb_driver \
                $(strip $(CORE_ROOT))/modem/ul1/ul1d \
                $(strip $(COMMON_ROOT))/modem/ul1/ul1d

ifeq ($(LTE_SOURCE_BUILD),TRUE)
  ifeq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
    XGEN_INC_DIR += ${COMMON_ROOT}/interface/sap \
                    ${COMMON_ROOT}/interface/sap/md \
                    ${COMMON_ROOT}/interface/modem/general \
                    ${COMMON_ROOT}/interface/cross_core \
                    ${COMMON_ROOT}/modem/lte_sec/interface \
                    ${COMMON_ROOT}/modem/lte_sec/interface/el1 \
                    ${COMMON_ROOT}/modem/lte_sec/interface/eise \
                    ${COMMON_ROOT}/modem/lte_sec/errc/include \
                    ${COMMON_ROOT}/interface/service/asn1_common \
                    ${L1CORE_ROOT}/modem/lte_sec/eise/common/include \
                    ${L1CORE_ROOT}/modem/lte_sec/eise/lcel/include \
                    ${L1CORE_ROOT}/modem/lte_sec/eise/lmob/include \
                    ${L1CORE_ROOT}/modem/interface/general \
                    ${L1CORE_ROOT}/modem/las/common/include \
                    ${L1CORE_ROOT}/interface/service/event_info \
                    $(strip ${PROJDIR_PCORE})/modem/eas_asn \
                    $(strip ${PROJDIR_PCORE})/modem/scsi \
                    $(strip ${PCORE_ROOT})/modem/lte_sec/errc/common/include \
                    $(strip ${PCORE_ROOT})/modem/interface/general \
                    $(UNIVERSAL_COMMON)/interface/modem/$(call lc,$(strip $(MTK_MODEM_ARCH)))/brp/inc
  endif
endif


XGEN_INC_DIR += $(strip $(PROJDIR))/../rel/BASIC/mcd
XGEN_INC_DIR += $(strip $(PROJDIR))/../rel/L4/mcd
