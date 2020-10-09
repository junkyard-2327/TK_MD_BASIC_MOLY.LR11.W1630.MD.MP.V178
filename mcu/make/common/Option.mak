# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

# *************************************************************************
# Common definitions
# *************************************************************************
include make/${CORE_ROOT}/buildConfig.mak

# *************************************************************************
# Set defaul value to Ckmake flag 
# *************************************************************************
DEPENDENCY_CONFLICT = FALSE
# *************************************************************************
# Dependency Check error message Interfaces
# *************************************************************************
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,ValB)
#               $(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,ValB1/ValB2/.../ValBn)
#               $(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,non ValB)
# Output:       PLEASE set OptA as ValA or set OptB as ValB
#               PLEASE set OptA as ValA or set OptB as ValB1/ValB2/.../ValBn
#               PLEASE set OptA as ValA or set OptB as non ValB
#
# Example:      $(call DEP_ERR_SETA_OR_SETB,BROWSER_SUPPORT,OBIGO_Q05A,UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT,non OBIGO_Q05A)
#               PLEASE set BROWSER_SUPPORT as OBIGO_Q05A or set UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT as non OBIGO_Q05A
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_SETB = $(warning ERROR: PLEASE set $1 as $2 or set $3 as $4)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_ONA_OR_OFFB,OptA,OptB)
#               $(call DEP_ERR_ONA_OR_OFFB,OptA,OptB$OptC&...&OptN)
# Output:       PLEASE turn on OptA or turn off OptB
#
# Example:      $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,NAND_FLASH_BOOTING)
#               PLEASE turn on NAND_SUPPORT or turn off NAND_FLASH_BOOTING
# ------------------------------------------------------------------------
DEP_ERR_ONA_OR_OFFB = $(warning ERROR: PLEASE turn on $1 or turn off $2)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_SETA_OR_OFFB,OptA,ValA,OptB)
#               $(call DEP_ERR_SETA_OR_OFFB,OptA,ValA1/ValA2/.../ValAn,OptB)
#               $(call DEP_ERR_SETA_OR_OFFB,OptA,non ValA,OptB)
# Output:       PLEASE set OptA as ValA or turn off OptB
#               PLEASE set OptA as ValA1/ValA2/.../ValAn or turn off OptB
#               PLEASE set OptA as non ValA or turn off OptB
#
# Example:      $(call DEP_ERR_SETA_OR_OFFB,MELODY_VER,DSP_WT_SYN,J2ME_SUPPORT)
#               PLEASE set MELODY_VER as DSP_WT_SYN or turn off J2ME_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_OFFB = $(warning ERROR: PLEASE set $1 as $2 or turn off $3)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_SETA_OR_ONB,OptA,ValA,OptB)
#               $(call DEP_ERR_SETA_OR_ONB,OptA,ValA1/ValA2/.../ValAn,OptB)
#               $(call DEP_ERR_SETA_OR_ONB,OptA,non ValA,OptB)
# Output:       PLEASE set OptA as ValA or turn on OptB
#               PLEASE set OptA as ValA1/ValA2/.../ValAn or turn on OptB
#               PLEASE set OptA as non ValA or turn on OptB
#
# Example:      $(call DEP_ERR_SETA_OR_ONB,MMS_SUPPORT,non OBIGO_Q05A,UNIFIED_MESSAGE_FOLDER)
#               PLEASE set MMS_SUPPORT as non OBIGO_Q05A or turn on UNIFIED_MESSAGE_FOLDER
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_ONB = $(warning ERROR: PLEASE set $1 as $2 or turn on $3)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_OFFA_OR_OFFB,OptA,OptB)
# Output:       PLEASE turn off OptA or turn off OptB
#
# Example:      $(call DEP_ERR_OFFA_OR_OFFB,CMUX_SUPPORT,BLUETOOTH_SUPPORT)
#               PLEASE turn off CMUX_SUPPORT or turn off BLUETOOTH_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_OFFA_OR_OFFB = $(warning ERROR: PLEASE turn off $1 or turn off $2)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_ONA_OR_ONB,OptA,OptB)
# Output:       PLEASE turn on OptA or turn on OptB
#
# Example:      $(call DEP_ERR_ONA_OR_ONB,UCM_SUPPORT,VOIP_SUPPORT)
#               PLEASE turn on UCM_SUPPORT or turn on VOIP_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_ONA_OR_ONB = $(warning ERROR: PLEASE turn on $1 or turn on $2)
# *************************************************************************
# Set defaul value to eliminate "option not define" warning
# *************************************************************************
BM_NEW      = FALSE

ifndef RTOS
  RTOS = NUCLEUS
endif

ifndef RTOS_DEBUG
  RTOS_DEBUG = TRUE
endif

ifeq ($(strip $(RTOS)),THREADX)
  COMMINCDIRS   +=  threadx/inc \
                    ${COMMON_ROOT}/service/kal/threadx/include
endif

ifdef DISABLE_AUTOTCM
  ifeq ($(strip $(DISABLE_AUTOTCM)),TRUE)
    COM_DEFS += __L1_KW_SCAN__
    CUSTOM_OPTION  := $(filter-out __MML1_ADT_ENABLE__,$(CUSTOM_OPTION))
  endif
endif

ifdef C2K_MODE_SUPPORT
  ifeq ($(strip $(C2K_MODE_SUPPORT)),TRUE)
    COM_DEFS +=  __CDMA2000_RAT__ __EXTERNAL_CDMA_SUPPORT__ 
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
  COM_DEFS += KAL_ON_NUCLEUS
  ifeq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += NU_DEBUG
  else
     COM_DEFS += NU_NO_ERROR_CHECKING
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  COM_DEFS += KAL_ON_NUCLEUS __NUCLEUS_VERSION_2__
  ifeq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += NU_DEBUG
  else
     COM_DEFS += NU_NO_ERROR_CHECKING
  endif
endif

ifeq ($(strip $(RTOS)),THREADX)
  COM_DEFS += KAL_ON_THREADX
  COM_DEFS += TX_ENABLE_IRQ_NESTING TX_DISABLE_NOTIFY_CALLBACKS \
              TX_DISABLE_PREEMPTION_THRESHOLD TX_DISABLE_STACK_FILLING TX_REACTIVE_INLINE
  ifneq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += TX_DISABLE_ERROR_CHECKING
  endif
endif

ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    COM_DEFS    +=  IDMA_DOWNLOAD
  endif
endif

ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COM_DEFS +=  EMPTY_MMI
endif

L1S_BASIC=FALSE
ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  L1S_BASIC=TRUE
endif

L1_UMTS=FALSE
ifeq ($(strip $(L1_WCDMA)),TRUE)
  L1_UMTS=TRUE
endif
ifeq ($(strip $(L1_TDD128)),TRUE)
  L1_UMTS=TRUE
endif

ETCM = FALSE
ifeq ($(CORE_ROOT),$(PCORE_ROOT))
  ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
    ETCM = TRUE
  endif
endif

SV5_PLATFORM = MT6280 TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
SV5X_PLATFORM = MT6290

# *************************************************************************
# Components list
# *************************************************************************
ifeq ($(strip $(EL1_IT)),TRUE)
COMPLIST       += ll1_pcore
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
COMPLIST       =  nucleus nucleus_int nucleus_ctrl_code nucleus_critical_data
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
COMPLIST       =  nucleus_v2 nucleus_v2_int nucleus_v2_ctrl_code nucleus_v2_critical_data
endif

ifeq ($(strip $(RTOS)),THREADX)
COMPLIST       =  threadx threadx_ctrl_code threadx_ctrl_data
endif

ifeq ($(strip $(RTOS_DEBUG)),TRUE)
  ifeq ($(strip $(RTOS)),NUCLEUS)
    COMPLIST    += nucleus_debug
  endif
  ifeq ($(strip $(RTOS)),NUCLEUS_V2)
    COMPLIST    += nucleus_v2_debug
  endif
  ifeq ($(strip $(RTOS)),THREADX)
    COMPLIST    += threadx_debug
  endif
endif

ifeq ($(strip $(L1S_BASIC)),TRUE)
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    COMPLIST       += md_drv
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
      ifneq (${CORE_ROOT},l1core)
        COMPLIST       += dummyps
      endif
    endif
    ifeq ($(strip $(NVRAM_SUPPORT)),TRUE)
      ifneq (${CORE_ROOT},l1core)
        COMPLIST  += nvram nvram_sec sbp gmss_public
      endif
    endif
    ifneq ($(strip $(L1_UMTS)),TRUE)
      ifeq ($(strip $(L1_GPRS)),TRUE)
        COMPLIST       += md_drv       # GPRS classb
      else
        ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
          COMPLIST       +=  md_drv                     # GSM only
        endif
      endif
    else
    endif
  endif
else
  # For PS team developers add component module here.
  ifeq (${CORE_ROOT},pcore)
	COMPLIST       += nvram nvram_sec l4misc sim nwsel gmss nas_common_utility
	ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
	  COMPLIST += cc ciss sms data
	endif
	ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
      COMPLIST += sms
    endif
  endif

  COMPLIST += sbp gmss_public
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  ifeq ($(strip $(L1_GPRS)),TRUE)
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      ifeq ($(strip $(UL1_3GSOLUTION)),MTK_UL1_FDD)
        COMPLIST       += md_drv                    # DM (EGPRS + 3G) or DM (GPRS + 3G)
        ifneq (${CORE_ROOT},l1core)
          COMPLIST       += dummyps dummyups      # DM (EGPRS + 3G) or DM (GPRS + 3G)
        else
          COMPLIST       += ll1      # DM (EGPRS + 3G) or DM (GPRS + 3G)
        endif
      endif
    endif
  endif

  ifeq ($(strip $(L1_GPRS)),TRUE)
    ifeq ($(strip $(L1_WCDMA)),FALSE)
      COMPLIST       += md_drv dummyps                       # 2G Only (EGPRS) or 2G Only (GPRS)
    endif
  endif

  ifeq ($(strip $(L1_GPRS)),FALSE)
    ifeq ($(strip $(L1_EGPRS)),FALSE)
      ifeq ($(strip $(L1_WCDMA)),FALSE)
        ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
          COMPLIST       += md_drv                                     # 2G Only (GSM)
          ifneq (${CORE_ROOT},l1core)
          COMPLIST       += dummyps                                     # 2G Only (GSM)
          endif
        endif
      endif
    endif
  endif

  ifeq ($(strip $(L1_GPRS)),FALSE)
    ifeq ($(strip $(L1_EGPRS)),TRUE)
      $(error: Not support EDGE wihtout GPRS)
    endif
  endif

  ifeq ($(strip $(L1_GPRS)),FALSE)
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      $(error: Not support WCDMA wihtout GPRS)
    endif
  endif
endif

# For SWITCH MODEM TEMPERATURE RANGE.
MODEM_TEMPERATURE_RANGE_M10_TO_65 = MT6169_2G_CUSTOM MT6169_2G A1EU_2G_MT6169 A1US_2G_MT6169 K82CMCC_2G_MT6169 K82V2_2G_MT6169 K95_2G_MT6165 K95_2G_MT6169 K95_DEMO_2G_MT6165 \
                                    K95_DEMO_2G_MT6169 MT6169_MIFI_2G MT6169_MIFI_2G_CUSTOM MT6582LTE_2G_MT6169 V1UK_2G_MT6169 V1UK_EVB_2G_MT6169 MT6165_DUAL_TALK_2G \
                                    MT6582LTE_2G_MT6165 RIO5EU_2G_MT6169 RIO5US_2G_MT6169 AD6546 AD6546_CUSTOM AD6548_AST AD6548_CUSTOM ATHENS15V3_MODEM_6140D LENOVO75_DEMO_MT6162 \
                                    MT6140_CUSTOM MT6140D MT6162 MT6162_CUSTOM MT6162_DUAL MT6163_2G MT6163_2G_CUSTOM MT6166_DUAL_TALK_2G MT6280_CUSTOM MT6280RF_2G MT6582LTE_2G_MT6166    
ifneq ($(filter $(strip $(RF_MODULE)),$(MODEM_TEMPERATURE_RANGE_M10_TO_65)),)
# Modem L1 temperature range { -10, 5, 20 ,35 ,45 ,55 ,60, 65 }
else
# Modem L1 temperature range { -10, 5, 20, 35, 55, 70, 85, 90 }
  COM_DEFS += __L1_TEMPERATURE_RANGE_V2__
endif

ifeq ($(strip $(ORIGINAL_PROJECT_NAME)),TK6291_FPGA)
  COM_DEFS += __NO_MD2G_HW_PLATFORM__
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
     COM_DEFS += __MTK_3G_MRAT_ARCH__
  endif
endif

ifndef SMART_PHONE_CORE
  SMART_PHONE_CORE = NONE
endif

COMPLIST += config custom kal sst dsmgr

ifeq (${CORE_ROOT},pcore)
  COMPLIST  += mtkdebug
else
  COMPLIST += audio peripheral
endif

ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    #COMPLIST += bmt
    COM_DEFS  += __BMT_TASK_DISABLE__
  endif
endif

ifeq ($(filter BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq (${CORE_ROOT},l1core)
    COMPLIST += audio ft ftc media
  endif
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
  COMPLIST += meut
endif

ifndef AST_SUPPORT
  AST_SUPPORT = NONE
endif

ifneq (${CORE_ROOT},pcore)
  ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
      COMPLIST += ll1
  else
    ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
      COMPLIST += ll1
    endif
  endif
endif

ifeq ($(strip $(UMTS_TDD_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
  ifdef L1_TDD128
    ifeq ($(strip $(L1_TDD128)),TRUE)
      ifeq ($(strip $(TL1_3GSOLUTION)),MTK_TL1_TDD)
        ifeq (${CORE_ROOT},pcore)
          COMPLIST       += tl1_pcore
        endif
        ifeq (${CORE_ROOT},l1core)
          COMPLIST       += tl1 ll1       # DM (EGPRS + 3G TD) or DM (GPRS + 3G TD)
        endif
      endif

      ifeq ($(strip $(TL1_3GSOLUTION)),AST_TL1_TDD)
        ifeq ($(strip $(AST_SUPPORT)),AST1001)
          COMPLIST       += ast_l1_ast1001 ll1    # DM (EGPRS + 3G) or DM (GPRS + 3G)
          #COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001)
          COMPLIST       += ast_l1_ast2001 ll1     # DM (EGPRS + 3G) or DM (GPRS + 3G)
          #COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001FPGA)
          COMPLIST       += ast_l1_ast2001 ll1    # DM (EGPRS + 3G) or DM (GPRS + 3G)
          #COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST3001)
          COMPLIST       += ast_l1_ast3001 ll1     # DM (EGPRS + 3G) or DM (GPRS + 3G)
          #COMPLIST       += fta
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST3002)
          COMPLIST       += ast_l1_ast3002 ll1     # DM (EGPRS + 3G) or DM (GPRS + 3G)
          #COMPLIST       += fta
        endif
      endif 
    endif
  endif
endif

UL1_HS_PLUS_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
  UL1_SUPPORT = TRUE
else
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
      UL1_SUPPORT = TRUE
    endif
  endif
endif
ifeq ($(strip $(UL1_SUPPORT)),TRUE)
  ifdef UL1_3GSOLUTION
    ifneq ($(strip $(UL1_3GSOLUTION)),NONE)
      ifneq (${CORE_ROOT},pcore)
        COMPLIST += ll1
      endif
    endif
  endif
  ifdef L1_WCDMA
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      ifeq ($(strip $(UL1_3GSOLUTION)),MTK_UL1_FDD)
        ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
          UMTS_FDD_PLATFORM = FALSE
          ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLUS_PLATFORM)),)
            ifeq (${CORE_ROOT},pcore)
              ifneq ($(strip $(UE_SIMULATOR)),TRUE)
                COMPLIST       += ul1_pcore       # DM (EGPRS + 3G) or DM (GPRS + 3G)
                L1_TMD_FILES   += ${PCORE_ROOT}/modem/ul1/ul1d_public/UL1D_Pcore_Trace.tmd
                L1_TMD_FILES   += ${PCORE_ROOT}/modem/ul1/ul1c_public/UL1C_Pcore_Trace.tmd
              endif

              ifeq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
                COMPLIST       += ul1b
                COM_DEFS       +=   __U4G_ADAPTOR__
              endif
            else
              ifeq (${CORE_ROOT},l1core)
                COMPLIST       += ul1 ul1_ext       # DM (EGPRS + 3G) or DM (GPRS + 3G)
              endif
            endif
            COM_DEFS       +=   __UL1_HS_PLUS_PLATFORM__ 
            UMTS_FDD_PLATFORM = TRUE
          endif
          ifneq ($(strip $(UMTS_FDD_PLATFORM)),TRUE)
            $(warning ERROR: PLATFORM $(strip $(PLATFORM)) is not vaild UMTS_FDD_MODE_SUPPORT platform.) 
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifdef BYTECOPY_SUPPORT
    ifeq ($(strip $(BYTECOPY_SUPPORT)),TRUE)
      COM_DEFS  += __IS_BYTECOPY_SUPPORT__
      ifeq (${CORE_ROOT},pcore)
        COMPLIST  += bytecopy
      endif
    endif
  endif
endif

ifneq ($(filter L1S L1S_CA7, $(ORIGINAL_FLAVOR)),)
    COM_DEFS += __HAPS_FPGA_CLK_ADJUST__
endif

ifeq ($(strip $(EUTRAN_MODE_SUPPORT)),EUTRAN_MODE)
  COM_DEFS += __4G_IDC__
endif

ifeq ($(filter BASIC ,$(TEST_LOAD_TYPE)),)
  ifeq (${CORE_ROOT},pcore)
    COMPLIST += mml1_pcore mml1_rf_pcore mml1_rf_ext_pcore
  else
    ifeq (${CORE_ROOT},l1core)
      COMPLIST += mml1_rf
      COMPLIST += mml1
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  # add las for MoDIS pcore and Target l1core
  ifeq ($(filter L1S BASIC,$(TEST_LOAD_TYPE)),)
    ifeq ($(strip $(MODIS_CONFIG)),TRUE)
      ifeq ($(CORE_ROOT),pcore)
        COMPLIST += las tlas gas_public
      endif
    else
      ifeq ($(CORE_ROOT),l1core)
        COMPLIST += las tlas gas_public
      endif
    endif
  endif

  ifeq ($(CORE_ROOT),pcore)
    COMPLIST += mrs
	ifeq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
	  # add scci for LTE single-mode
	  COMPLIST += scsi 
	else
	  COMPLIST += mm gas_fdd gas_tdd ratcm gas_public
	endif
  endif

  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    COMPLIST += md_drv 
  endif  
  
  COMPLIST += asn1_common
  
  ifeq ($(CORE_ROOT),pcore)
    COMPLIST += l4 tftlib
	ifneq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
	  COMPLIST += erac etcm mbmsal
	endif
  endif
  
  ifdef SGLTE_SUPPORT
    ifneq ($(strip $(SGLTE_SUPPORT)),NONE)
      COMPLIST += psdm
    endif
  endif
  
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    COMPLIST += asinterfaces
    ifeq ($(CORE_ROOT),$(PCORE_ROOT))
        COMPLIST += ratdm ratdm_sec uas_fdd uas_tdd fsm sndcp sm llc pam    
	    ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
	      COMPLIST += ul2_fdd
	    endif
    endif
  else
    ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
      ifeq ($(CORE_ROOT),$(PCORE_ROOT))
        COMPLIST += ratdm ratdm_sec sndcp sm llc pam
      endif
    endif
  endif
endif

ifeq ($(strip $(MCD_SUPPORT)),TRUE)
  ifeq ($(CORE_ROOT),pcore)
    ifeq ($(strip $(L1S_BASIC)),FALSE)
      COMPLIST += mcd
    endif
  endif
else
  ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
    COMPLIST += peer_classb
  endif
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
      COMPLIST += email emlst
  endif
endif

ifeq ($(strip $(DHL_SUPPORT)),TRUE)
  ifneq (${CORE_ROOT},l1core)
      COMPLIST    += dhl
  endif
else
  ifeq ($(strip $(TST_SUPPORT)),TRUE)
    COMPLIST     += tst
  endif
endif

ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  COMPLIST += dbinfo
endif

ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
  ifneq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    COMPLIST    += irda ircomm obex
  else
    COMPLIST    += irda
  endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  COMPLIST    += usb
endif

ifeq ($(strip $(XML_SUPPORT)),TRUE)
  COMPLIST    += xmlp
endif

ifdef SDP_SUPPORT
  ifneq ($(strip $(SDP_SUPPORT)),FALSE)
     COMPLIST    	+= sdp
  endif   
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
  COMPLIST          += btadp btprofiles btstack 
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
     COMPLIST    	+= dt
  endif   
endif

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
    COMPLIST         += xdm
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     COMPLIST    	+= iperf
  endif   
endif

ifeq ($(filter BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COMPLIST += event_info
endif

ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  ifeq (${CORE_ROOT},l1core)
    COMPLIST += gl1 l1_ext
  else
    COMPLIST += gl1_pcore l1_ext_pcore
    L1_TMD_FILES +=  ${PCORE_ROOT}/modem/gl1/l1c/gl1_pcore_trace.tmd
  endif
endif

ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  ifneq (${CORE_ROOT},l1core)
      COMPLIST    += ul1_ext_pcore
  endif
endif

ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  ifeq (${CORE_ROOT},l1core)
    COMPLIST += md_sm
  endif
endif

ifneq ($(strip $(SSS_SUPPORT)),SSS_LIB)
  ifneq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
    $(warning ERROR: Please define SSS_SUPPORT as SSS_LIB or SSS_SOURCE)
    DEPENDENCY_CONFLICT = TRUE
  else
    COMPLIST += sss
  endif
endif

COMPLIST       += verno

# *************************************************************************
# Components Object Files
# *************************************************************************
COMPOBJS =

ifdef SSS_SUPPORT
  ifeq ($(strip $(SSS_SUPPORT)),SSS_LIB)
    ifeq ($(strip $(COMPILER)),GCC)
      ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM) $(SV5X_PLATFORM)),)
        COMPOBJS    += ${COMMON_ROOT}/service/sss/lib/libsss_gcc_sv5.a
#        CUS_REL_OBJ_LIST    += ${COMMON_ROOT}/service/sss/lib/sss_gcc_sv5.lib
      else
        COMPOBJS    += ${COMMON_ROOT}/service/sss/lib/libsss_gcc_dummy.a
#        CUS_REL_OBJ_LIST    += ${COMMON_ROOT}/service/sss/lib/sss_gcc_dummy.lib
      endif
    else
     COMPOBJS    += ${COMMON_ROOT}/service/sss/lib/libsss.a
#     CUS_REL_OBJ_LIST    += ${COMMON_ROOT}/service/sss/lib/sss.lib
    endif
  endif
endif

# *************************************************************************
# L1 TMD Files
# *************************************************************************

ifeq ($(strip $(TEST_LOAD_TYPE)),NONE)
ifeq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
ifeq (${CORE_ROOT},pcore)
    L1_TMD_FILES    += ${CORE_ROOT}/driver/audio/src/v1/l1audio_trace.tmd
endif
endif
endif

#data path trace macro definition.
ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
  ifneq (${CORE_ROOT},l1core)
    COMMON_TMD_FILES += ${CORE_ROOT}/modem/upcm/src/data_path.tmd
    COMMON_TMD_FILES += ${CORE_ROOT}/modem/upcm/src/data_path_detail.tmd
  endif
endif

ifeq ($(filter BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq (${CORE_ROOT},l1core)
    COMMON_TMD_FILES += ${PCORE_ROOT}/service/qmu_bm/src/qmu_bm_trace.tmd
  endif
endif

ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifneq (${CORE_ROOT},pcore)
      L1_TMD_FILES += ${CORE_ROOT}/modem/ephy/common/ephy_trace.tmd
    endif
    ifeq (${CORE_ROOT},pcore)
      L1_TMD_FILES += ${COMMON_ROOT}/driver/l2copro/common/src/lte_l2_trace.tmd
      L1_TMD_FILES += ${CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_rf.tmd
    endif
  endif
endif

# *************************************************************************
# Component trace definition header files
# *************************************************************************
ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  ifeq ($(strip $(DHL_SUPPORT)),TRUE)
  COMP_TRACE_DEFS_MODEM = ${COMMON_ROOT}/service/dhl/local_inc/dhl_trace_def.h
  else
  COMP_TRACE_DEFS_MODEM = ${CORE_ROOT}/service/tst/local_inc/tst_trace.h
  endif
endif
ifeq ($(filter UDVT,$(TEST_LOAD_TYPE)),)
  ifeq ($(strip $(DHL_SUPPORT)),TRUE)
  COMP_TRACE_DEFS_MODEM = ${COMMON_ROOT}/service/dhl/local_inc/dhl_trace_def.h
  else
  COMP_TRACE_DEFS_MODEM = ${CORE_ROOT}/service/tst/local_inc/tst_trace.h
  endif
endif

ifeq (${CORE_ROOT},l1core)
ifneq ($(strip $(TEST_LOAD_TYPE)),BASIC)
ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
  L1_COMP_TRACE_DEFS_MODEM   += ${CORE_ROOT}/modem/ll1/include/mll1_trc.h 
else
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    L1_COMP_TRACE_DEFS_MODEM   += ${CORE_ROOT}/modem/ll1/include/mll1_trc.h 
  endif
endif
endif
endif

ifeq ($(strip $(EL1_IT)),TRUE)
    L1_COMP_TRACE_DEFS_MODEM   += ${L1CORE_ROOT}/modem/ll1/include/mll1_trc.h 
endif

ifeq ($(strip $(L1S_BASIC)),TRUE)
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
        COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/smt/l1s/dummyps/include/internal/dps_trc.h \
                                 ${CORE_ROOT}/driver/peripheral/inc/bmt_trc.h \
                                 ${CORE_ROOT}/modem/sim/include/sim_trc.h
    endif 
  endif

  COMP_TRACE_DEFS_MODEM += ${L1CORE_ROOT}/modem/gl1/common/l1a_trace.h

  ifeq ($(strip $(L1_WCDMA)),TRUE)
    ifneq ($(strip $(TEST_LOAD_TYPE)),UDVT)
      COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/modem/interface/l1/inner/udps_trc.h
    endif
  endif

  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifeq ($(strip $(NVRAM_SUPPORT)),TRUE)
      COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/service/nvram/include/nvram_trc.h
    endif
  endif

  ifeq ($(strip $(L1_GPRS)),TRUE)
    ifeq ($(strip $(L1_WCDMA)),TRUE)
          COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/interface/l1/inner/ul1a_trc.h
    endif
  endif

  ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/modem/sim/include/sim_trc.h
    COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/peripheral/inc/bmt_trc.h
  endif

else

  ifneq ($(strip $(L1_UMTS)),TRUE)
    COMP_TRACE_DEFS_MODEM  +=  ${L1CORE_ROOT}/modem/gl1/common/l1a_trace.h 
    COMP_TRACE_DEFS_MODEM  +=  ${CORE_ROOT}/modem/nas/mm/common/include/mm_trc.h \
                         $(strip $(GAS_FDD_FOLDER))/common/include/rr_trc.h \
                         $(strip $(GAS_FDD_FOLDER))/lapdm/include/lapdm_trc.h \
                         $(strip $(GAS_FDD_FOLDER))/rlc/include/rlc_trc.h \
                         $(strip $(GAS_FDD_FOLDER))/mac/include/mac_trc.h \
                         $(strip $(GAS_TDD_FOLDER))/common/include/rr_trc.h \
                         $(strip $(GAS_TDD_FOLDER))/lapdm/include/lapdm_trc.h \
                         $(strip $(GAS_TDD_FOLDER))/rlc/include/rlc_trc.h \
                         $(strip $(GAS_TDD_FOLDER))/mac/include/mac_trc.h \
                         ${CORE_ROOT}/modem/nas/ratcm/include/ratcm_trc.h \
                         ${CORE_ROOT}/modem/nas/ratdm/include/ratdm_trc.h

    ifneq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
      COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/gise/include/gise_trc.h \
                                ${L1CORE_ROOT}/modem/las/gise_tdd128/include/gise_trc.h
    else
      L1_COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/gise/include/gise_trc.h \
                                   ${L1CORE_ROOT}/modem/las/gise_tdd128/include/gise_trc.h
    endif

    ifdef GEMINI
      ifneq ($(strip $(GEMINI)),FALSE)
        COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/common/rsva/rsvas/include/rsvas_trc.h
      endif
    endif
  else
    ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
      COMP_TRACE_DEFS_MODEM  +=  ${L1CORE_ROOT}/modem/gl1/common/l1a_trace.h
      COMP_TRACE_DEFS_MODEM  +=  ${CORE_ROOT}/modem/nas/mm/common/include/mm_trc.h \
                           $(strip $(GAS_FDD_FOLDER))/common/include/rr_trc.h \
                           $(strip $(GAS_FDD_FOLDER))/lapdm/include/lapdm_trc.h \
                           $(strip $(GAS_FDD_FOLDER))/rlc/include/rlc_trc.h \
                           $(strip $(GAS_FDD_FOLDER))/mac/include/mac_trc.h \
                           $(strip $(GAS_TDD_FOLDER))/common/include/rr_trc.h \
                           $(strip $(GAS_TDD_FOLDER))/lapdm/include/lapdm_trc.h \
                           $(strip $(GAS_TDD_FOLDER))/rlc/include/rlc_trc.h \
                           $(strip $(GAS_TDD_FOLDER))/mac/include/mac_trc.h \
                           ${CORE_ROOT}/modem/nas/ratcm/include/ratcm_trc.h \
                           ${CORE_ROOT}/modem/nas/ratdm/include/ratdm_trc.h

      ifneq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
        COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/gise/include/gise_trc.h \
                                  ${L1CORE_ROOT}/modem/las/gise_tdd128/include/gise_trc.h
      else
        L1_COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/gise/include/gise_trc.h \
                                     ${L1CORE_ROOT}/modem/las/gise_tdd128/include/gise_trc.h
      endif
    else
      COMP_TRACE_DEFS_MODEM  +=  ${L1CORE_ROOT}/modem/gl1/common/l1a_trace.h
      COMP_TRACE_DEFS_MODEM  +=  ${CORE_ROOT}/modem/mm/common/include/mm_trc.h \
                           $(strip $(GAS_FDD_FOLDER))/include/rr_trc.h \
                           $(strip $(GAS_FDD_FOLDER))/lapdm/include/lapdm_trc.h \
                           $(strip $(GAS_FDD_FOLDER))/rlc/include/rlc_trc.h \
                           $(strip $(GAS_FDD_FOLDER))/mac/include/mac_trc.h \
                           $(strip $(GAS_FDD_FOLDER))/rrm/include/rrm_trc.h \
                           $(strip $(GAS_TDD_FOLDER))/include/rr_trc.h \
                           $(strip $(GAS_TDD_FOLDER))/lapdm/include/lapdm_trc.h \
                           $(strip $(GAS_TDD_FOLDER))/rlc/include/rlc_trc.h \
                           $(strip $(GAS_TDD_FOLDER))/mac/include/mac_trc.h \
                           $(strip $(GAS_TDD_FOLDER))/rrm/include/rrm_trc.h

      ifneq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
        COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/gise/include/gise_trc.h \
                                  ${L1CORE_ROOT}/modem/las/gise_tdd128/include/gise_trc.h
      else
        L1_COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/gise/include/gise_trc.h \
                                     ${L1CORE_ROOT}/modem/las/gise_tdd128/include/gise_trc.h
      endif
    endif
  endif

  COMP_TRACE_DEFS_MODEM   += ${CORE_ROOT}/modem/sim/include/sim_trc.h
  COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/service/nvram/include/nvram_trc.h \
                       ${CORE_ROOT}/modem/l4/smsal/include/smsal_trc.h \
                       ${CORE_ROOT}/modem/l4/phb/include/phb_trc.h \
                       ${CORE_ROOT}/modem/l4/smu/include/smu_trc.h \
                       ${CORE_ROOT}/modem/nas/cc-ss/ss/include/ciss_trc.h \
                       ${CORE_ROOT}/modem/nas/cc-ss/cc/include/cc_trc.h \
                       ${CORE_ROOT}/modem/l4/csm/csm_trc.h \
                       ${CORE_ROOT}/modem/nwsel/nwsel/include/nwsel_trc.h \
                       ${CORE_ROOT}/interface/modem/upcm/upcm_trc.h \
                       ${CORE_ROOT}/modem/interface/l4misc/l4_trc.h \
                       ${CORE_ROOT}/modem/nas/sms/include/sms_trc.h \
                       ${CORE_ROOT}/modem/l4/uem/include/uem_trc.h \
                       ${CORE_ROOT}/modem/l4/rac/common/include/rac_trc.h \
                       ${CORE_ROOT}/modem/l4/tcm/common/tcm_trc.h \
                       ${CORE_ROOT}/modem/l4/tcm/rat_tcm/inc/rat_tcm_trc.h \
                       ${CORE_ROOT}/middleware/media/common/include/med_trc.h \
                       ${CORE_ROOT}/modem/nas/data/l2r/include/l2r_trc.h \
                       ${CORE_ROOT}/modem/nas/data/tdt/include/tdt_trc.h \
                       ${CORE_ROOT}/modem/nas/data/rlp/include/rlp_trc.h \
                       ${CORE_ROOT}/modem/nas/data/t30/include/t30_trc.h \
                       ${CORE_ROOT}/modem/nas/data/fa/include/fa_trc.h \
                       ${CORE_ROOT}/driver/peripheral/inc/bmt_trc.h \
                       ${CORE_ROOT}/modem/mrs/include/mrs_trc.h \
                       ${CORE_ROOT}/modem/l4/mbmsal/src/mbmsal_trc.h \
                       ${CORE_ROOT}/modem/nwsel/gmss/include/gmss_trc.h

  ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
    COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/nas/llc/include/llc_trc.h \
                             ${CORE_ROOT}/modem/nas/sndcp/include/snd_trc.h \
                             ${CORE_ROOT}/modem/nas/sm/include/sm_trc.h \
                             $(CORE_ROOT)/modem/nas/pam/pam_trc.h
    ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
      COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/nas/llc/include/llc_trc.h \
                               ${CORE_ROOT}/modem/nas/sndcp/include/snd_trc.h \
                               ${CORE_ROOT}/modem/nas/sm/include/sm_trc.h \
                               ${COMMON_ROOT}/modem/uas/urr/dbme/include/dbme_trc.h \
                               ${COMMON_ROOT}/modem/uas_tdd128/urr/dbme/include/dbme_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/ul2/bmc/include/bmc_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/ul2/common/include/ul2_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/ul2/csr/include/csr_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/ul2/pdcp/include/pdcp_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/ul2/rabm/include/rabm_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/ul2/umac/include/umac_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/ul2/urlc/include/urlc_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/urr/common/include/adr_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/urr/cise/include/csce_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/urr/cise/include/cse_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/urr/cise/include/sibe_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/urr/cise/include/usime_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/urr/common/include/urr_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/urr/meme/include/meme_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/urr/rrce/include/rrce_trc.h \
                               $(strip $(UAS_FDD_FOLDER))/urr/slce/include/slce_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/ul2/bmc/include/bmc_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/ul2/common/include/ul2_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/ul2/csr/include/csr_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/ul2/pdcp/include/pdcp_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/ul2/rabm/include/rabm_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/ul2/umac/include/umac_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/ul2/urlc/include/urlc_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/urr/common/include/adr_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/urr/cise/include/csce_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/urr/cise/include/cse_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/urr/cise/include/sibe_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/urr/cise/include/usime_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/urr/common/include/urr_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/urr/meme/include/meme_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/urr/rrce/include/rrce_trc.h \
                               $(strip $(UAS_TDD_FOLDER))/urr/slce/include/slce_trc.h \
                               $(CORE_ROOT)/modem/nas/pam/pam_trc.h

    ifneq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
      COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/uise/lcsce/include/lcsce_trc.h \
                                ${L1CORE_ROOT}/modem/las/uise/common/include/lurr_trc.h \
                                ${L1CORE_ROOT}/modem/las/uise/lmeme/include/lmeme_trc.h \
                                ${L1CORE_ROOT}/modem/las/tise/lcsce/include/lcsce_trc.h \
                                ${L1CORE_ROOT}/modem/las/tise/common/include/lurr_trc.h \
                                ${L1CORE_ROOT}/modem/las/tise/lmeme/include/lmeme_trc.h \
                                ${L1CORE_ROOT}/modem/las/tise/lrrce/include/lrrce_trc.h \
                                ${L1CORE_ROOT}/modem/las/tise/lurlc/include/lurlc_trc.h \
                                ${L1CORE_ROOT}/modem/las/tise/lumac/include/lumac_trc.h 
    else
      L1_COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/uise/lcsce/include/lcsce_trc.h \
                                   ${L1CORE_ROOT}/modem/las/uise/common/include/lurr_trc.h \
                                   ${L1CORE_ROOT}/modem/las/uise/lmeme/include/lmeme_trc.h \
                                   ${COMMON_ROOT}/modem/uas/urr/dbme/include/dbme_trc.h \
                                   ${COMMON_ROOT}/../pcore/modem/uas/urr/common/include/adr_trc.h \
                                   ${L1CORE_ROOT}/modem/las/tise/lcsce/include/lcsce_trc.h \
                                   ${L1CORE_ROOT}/modem/las/tise/common/include/lurr_trc.h \
                                   ${L1CORE_ROOT}/modem/las/tise/lmeme/include/lmeme_trc.h \
                                   ${COMMON_ROOT}/modem/uas_tdd128/urr/dbme/include/dbme_trc.h \
                                   ${COMMON_ROOT}/../pcore/modem/uas_tdd128/urr/common/include/adr_trc.h \
                                   ${L1CORE_ROOT}/modem/las/tise/lrrce/include/lrrce_trc.h \
                                   ${L1CORE_ROOT}/modem/las/tise/lurlc/include/lurlc_trc.h \
                                   ${L1CORE_ROOT}/modem/las/tise/lumac/include/lumac_trc.h
    endif

      ifneq ($(strip $(UE_SIMULATOR)),TRUE)
        ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
          COMP_TRACE_DEFS_MODEM += ${L1CORE_ROOT}/modem/interface/l1/inner/ul1a_trc.h
        endif
      endif

      ifeq ($(strip $(UE_SIMULATOR)),TRUE)
        COMP_TRACE_DEFS_MODEM += $(strip $(UAS_FDD_FOLDER))/l2hwaccsim/common/include/l2_hw_acc_sim_trc.h
      endif

      ifdef GEMINI
        ifneq ($(strip $(GEMINI)),FALSE)
          COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/common/rsva/rsvas/include/rsvas_trc.h \
                             ${CORE_ROOT}/modem/common/rsva/rsvak/include/rsvak_trc.h \
                             ${CORE_ROOT}/modem/common/rsva/rsvau/include/rsvau_trc.h \
                             ${CORE_ROOT}/modem/common/rsva/rsvae/include/rsvae_trc.h \
                             ${CORE_ROOT}/modem/common/rsva/rsvac/include/rsvac_trc.h \
                             ${CORE_ROOT}/modem/common/rsva/rsvag/include/rsvag_trc.h
        endif
      endif
    endif
  endif
endif

ifneq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
  COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/modem/rohc/interface/rohc_trc.h
  ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifneq ($(strip $(CORE_ROOT)),l1core)
      COMMON_TMD_FILES += ${CORE_ROOT}/modem/rohc/rohc_core/rohc_trace.tmd
      COMMON_TMD_FILES += ${CORE_ROOT}/modem/rohc/rohc_core/rohc_detail_trace.tmd
      COMMON_TMD_FILES += ${CORE_ROOT}/modem/rohc/ral/ral_trace.tmd
      COMMON_TMD_FILES += ${CORE_ROOT}/modem/rohc/ral/ral_detail_trace.tmd
      COMPLIST += waal
      COMP_TRACE_DEFS_MODEM += ${PCORE_ROOT}/modem/l4/waal/src/waal_trc.h
    endif
  endif
endif 

COMP_TRACE_DEFS_MODEM    += ${COMMON_ROOT}/service/sst/include/ex_trc.h
COMP_TRACE_DEFS_MODEM    += ${COMMON_ROOT}/service/sst/include/SST_trc.h
ifneq ($(wildcard common/driver/sys_drv/init/inc/init_comm_trc.h),)
  COMP_TRACE_DEFS_MODEM    += ${COMMON_ROOT}/driver/sys_drv/init/inc/init_comm_trc.h
endif
COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/modem/l4/include/atci_trc.h
COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/modem/l4/psdm/include/psdm_trc.h
COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/devdrv/trace/devdrv_trace.h

ifneq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
  COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/gise/include/gise_trc.h \
                            ${L1CORE_ROOT}/modem/las/gise_tdd128/include/gise_trc.h \
                            ${L1CORE_ROOT}/modem/las/uise/lcsce/include/lcsce_trc.h \
                            ${L1CORE_ROOT}/modem/las/uise/common/include/lurr_trc.h \
                            ${L1CORE_ROOT}/modem/las/uise/lmeme/include/lmeme_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/lcsce/include/lcsce_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/common/include/lurr_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/lmeme/include/lmeme_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/lrrce/include/lrrce_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/lurlc/include/lurlc_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/lumac/include/lumac_trc.h 
else
  L1_COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/gise/include/gise_trc.h \
                               ${L1CORE_ROOT}/modem/las/gise_tdd128/include/gise_trc.h \
                               ${L1CORE_ROOT}/modem/las/uise/lcsce/include/lcsce_trc.h \
                               ${L1CORE_ROOT}/modem/las/uise/common/include/lurr_trc.h \
                               ${L1CORE_ROOT}/modem/las/uise/lmeme/include/lmeme_trc.h \
                               ${COMMON_ROOT}/modem/uas/urr/dbme/include/dbme_trc.h \
                               ${COMMON_ROOT}/../pcore/modem/uas/urr/common/include/adr_trc.h \
                               ${COMMON_ROOT}/modem/uas_tdd128/urr/dbme/include/dbme_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/lcsce/include/lcsce_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/common/include/lurr_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/lmeme/include/lmeme_trc.h \
                               ${COMMON_ROOT}/../pcore/modem/uas_tdd128/urr/common/include/adr_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/lrrce/include/lrrce_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/lurlc/include/lurlc_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/lumac/include/lumac_trc.h 
endif

ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
  ifneq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    COMP_TRACE_DEFS_MODEM   += ${CORE_ROOT}/modem/ircomm/include/ircomm_trc.h \
                         ${CORE_ROOT}/modem/obex/include/obex_trc.h \
                         irda/inc/irda_trace.h
  else
    COMP_TRACE_DEFS_MODEM   += irda/inc/irda_trace.h
  endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
        COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/connectivity/usb_class/include/usb_trc.h
endif

ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
  #COMP_TRACE_DEFS_MODEM	+= inet_ps\imps\include\imps_trc.h
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  L1_COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/interface/service/event_info/ul1_event_info_trc.h
  COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/interface/service/event_info/ul1_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/gas_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/ul2_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/uas_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/cc_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/mm_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/ratdm_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/sm_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/sms_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/llc_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/sndcp_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/l4_event_info_trc.h \
  ${CORE_ROOT}/interface/service/event_info/ppp_event_info_trc.h
endif

ifneq ($(strip $(TTY_CONSOLE_TRACE_ENABLED)),1)
  COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/tty/inc/tty_trace.h
endif

# TFT library trace
COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/l4/tcm/tftlib/tftlib_dhl_trace.h

# L1CORE library trace
ifeq (${CORE_ROOT},l1core)
# UL1 COMPLIST
UL1_HS_PLUS_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
  UL1_SUPPORT = TRUE
else
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
      UL1_SUPPORT = TRUE
    endif
  endif
endif
ifeq ($(strip $(UL1_SUPPORT)),TRUE)
  ifdef L1_WCDMA
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      ifeq ($(strip $(UL1_3GSOLUTION)),MTK_UL1_FDD)
        ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
          UMTS_FDD_PLATFORM = FALSE
          ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLUS_PLATFORM)),)
            COMPLIST       += ul1 ul1_ext       # DM (EGPRS + 3G) or DM (GPRS + 3G)
            COM_DEFS       +=   __UL1_HS_PLUS_PLATFORM__ 
            UMTS_FDD_PLATFORM = TRUE
          endif          
          ifneq ($(strip $(UMTS_FDD_PLATFORM)),TRUE)
            $(warning ERROR: PLATFORM $(strip $(PLATFORM)) is not vaild UMTS_FDD_MODE_SUPPORT platform.) 
            DEPENDENCY_CONFLICT = TRUE
          endif
        endif
      endif
    endif
  endif
endif

# MML1 COMPLIST
ifeq ($(filter BASIC ,$(TEST_LOAD_TYPE)),)
  COMPLIST += mml1_rf
  COMPLIST += mml1
endif

ifneq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
  COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/uise/lcsce/include/lcsce_trc.h \
                            ${L1CORE_ROOT}/modem/las/uise/common/include/lurr_trc.h \
                            ${L1CORE_ROOT}/modem/las/uise/lmeme/include/lmeme_trc.h	\
                            ${L1CORE_ROOT}/modem/las/tise/lcsce/include/lcsce_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/common/include/lurr_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/lmeme/include/lmeme_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/lrrce/include/lrrce_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/lurlc/include/lurlc_trc.h \
                            ${L1CORE_ROOT}/modem/las/tise/lumac/include/lumac_trc.h 
else
  L1_COMP_TRACE_DEFS_MODEM  += ${L1CORE_ROOT}/modem/las/uise/lcsce/include/lcsce_trc.h \
                               ${L1CORE_ROOT}/modem/las/uise/common/include/lurr_trc.h \
                               ${L1CORE_ROOT}/modem/las/uise/lmeme/include/lmeme_trc.h \
                               ${COMMON_ROOT}/modem/uas/urr/dbme/include/dbme_trc.h \
                               ${COMMON_ROOT}/modem/uas_tdd128/urr/dbme/include/dbme_trc.h \
                               ${COMMON_ROOT}/../pcore/modem/uas/urr/common/include/adr_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/lcsce/include/lcsce_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/common/include/lurr_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/lmeme/include/lmeme_trc.h \
                               ${COMMON_ROOT}/../pcore/modem/uas_tdd128/urr/common/include/adr_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/lrrce/include/lrrce_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/lurlc/include/lurlc_trc.h \
                               ${L1CORE_ROOT}/modem/las/tise/lumac/include/lumac_trc.h
endif

# *************************************************************************
# L1 TMD Files
# *************************************************************************
ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
  ifeq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    L1_TMD_FILES = ${L1CORE_ROOT}/modem/gl1/common/l1c_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1c2_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1i_cs_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1i_ps_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1sc_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1c_csd_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/L1D_Trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/L1D2_Trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/L1D_EDGE_Trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1i_egprs_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1c_egprs_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1i_amr_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1t_amr_trace.tmd
  endif
endif

ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_GSM_MODE)
    L1_TMD_FILES    =  ${L1CORE_ROOT}/modem/gl1/common/l1c_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/l1sc_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/l1i_cs_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/L1D_Trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/l1c_csd_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/L1D2_Trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/l1i_amr_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/l1t_amr_trace.tmd 
endif
                     
ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
      L1_TMD_FILES  =  ${L1CORE_ROOT}/modem/gl1/common/l1c_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/l1sc_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/l1i_cs_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/L1D_Trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/l1c_csd_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/L1D2_Trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/l1i_amr_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/l1t_amr_trace.tmd \
                       ${L1CORE_ROOT}/modem/gl1/common/L1D_EDGE_Trace.tmd
    endif                 
    ifeq ($(strip $(L1_GPRS)),TRUE)
      L1_TMD_FILES += ${L1CORE_ROOT}/modem/gl1/common/l1i_ps_trace.tmd
      L1_TMD_FILES += ${L1CORE_ROOT}/modem/gl1/common/l1c_egprs_trace.tmd \
                      ${L1CORE_ROOT}/modem/gl1/common/l1i_egprs_trace.tmd \
                      ${L1CORE_ROOT}/modem/gl1/common/l1c2_trace.tmd
    endif  
    ifeq ($(strip $(L1_UMTS)),TRUE)
        L1_TMD_FILES  +=   ${L1CORE_ROOT}/modem/gl1/common/L1D3_Trace.tmd
        L1_TMD_FILES  +=   ${L1CORE_ROOT}/modem/gl1/common/L1_AFC_Trace.tmd
        ifneq ($(strip $(UE_SIMULATOR)),TRUE)
        ifeq ($(strip $(L1_WCDMA)),TRUE)
           ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
              L1_TMD_FILES += ${L1CORE_ROOT}/modem/ul1/ul1c_public/UL1C_Trace1.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1c_public/UL1C_Trace2.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1c_public/UL1C_Trace3.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1c_public/UL1C_Trace4.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1c_public/UL1TST_Trace1.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_MLT_Trace1.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_MLT_Trace2.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace1.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace2.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace3.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace4.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace5.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace6.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_HSPA_Trace.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_HSPA_Trace1.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_HSPA_Trace2.tmd \
                              ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_PLUS_Trace1.tmd \
                              ${L1CORE_ROOT}/modem/md_sm/common/ul1sm/UL1SM_Trace1.tmd \
                              ${L1CORE_ROOT}/modem/md_sm/common/ul1sm/TPPA_UL1SM_Trace1.tmd
           endif
        endif
        endif
        ifeq ($(strip $(L1_GPRS)),TRUE)
         L1_TMD_FILES  +=   ${L1CORE_ROOT}/modem/gl1/common/l1dm_trace.tmd
        endif
    endif
endif

ifeq ($(strip $(L1_UMTS)),TRUE)
   L1_TMD_FILES  = ${L1CORE_ROOT}/modem/gl1/common/l1c_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1c2_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1i_cs_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1i_ps_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1sc_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1c_csd_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/L1D_Trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/L1D2_Trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/L1D_EDGE_Trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1i_egprs_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1c_egprs_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1i_amr_trace.tmd \
                   ${L1CORE_ROOT}/modem/gl1/common/l1t_amr_trace.tmd 
   ifneq ($(strip $(UMTS_MODE_SUPPORT)),NONE)                
      L1_TMD_FILES += ${L1CORE_ROOT}/modem/gl1/common/l1dm_trace.tmd
   endif

   ifneq ($(strip $(UE_SIMULATOR)),TRUE)
   ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      L1_TMD_FILES += ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_MLT_Trace1.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_MLT_Trace2.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace1.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace2.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace3.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace4.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace5.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_Trace6.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_HSPA_Trace.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_HSPA_Trace1.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_HSPA_Trace2.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1d_public/UL1D_PLUS_Trace1.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1c_public/UL1C_Trace1.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1c_public/UL1C_Trace2.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1c_public/UL1C_Trace3.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1c_public/UL1C_Trace4.tmd \
                      ${L1CORE_ROOT}/modem/ul1/ul1c_public/UL1TST_Trace1.tmd \
                      ${L1CORE_ROOT}/modem/md_sm/common/ul1sm/UL1SM_Trace1.tmd \
                      ${L1CORE_ROOT}/modem/md_sm/common/ul1sm/TPPA_UL1SM_Trace1.tmd
   endif
   endif
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),NONE)
ifeq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
ifeq (${CORE_ROOT},l1core)
    L1_TMD_FILES    += ${CORE_ROOT}/driver/audio/src/v1/l1audio_trace_l1core.tmd
    L1_COMP_TRACE_DEFS_MODEM   += ${CORE_ROOT}/driver/audio/src/v1/inc/l1sp_trc_l1core.h
endif
endif
endif

ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
   L1_TMD_FILES += ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_cm0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_cm1.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_cmif.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_common0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_common1.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_cs.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_csif.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_pos.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_ps.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_rf0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_rf1.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_rx0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_rx1.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_rx2.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_agc0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_tpc0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_tx0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_cosim.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_rxdfe0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_txdfe0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_rxlif0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_dpd0.tmd \
                   ${L1CORE_ROOT}/modem/el1/el1d_pub/trc/el1d_trace_et0.tmd
                   
   ifeq (${CORE_ROOT},l1core)
      L1_TMD_FILES += ${COMMON_ROOT}/driver/l2copro/common/src/lte_l2_trace_l1core.tmd
   endif
endif

L1_COMP_TRACE_DEFS_MODEM += ${COMMON_ROOT}/service/dhl/local_inc/dhl_trace_def.h 
L1_COMP_TRACE_DEFS_MODEM += ${L1CORE_ROOT}/modem/gl1/common/l1a_trace.h
L1_COMP_TRACE_DEFS_MODEM += ${COMMON_ROOT}/service/sst/include/SST_trc.h
ifneq ($(wildcard common/driver/sys_drv/init/inc/init_comm_trc.h),)
  L1_COMP_TRACE_DEFS_MODEM += ${COMMON_ROOT}/driver/sys_drv/init/inc/init_comm_trc.h
endif
L1_COMP_TRACE_DEFS_MODEM += ${L1CORE_ROOT}/driver/devdrv/trace/devdrv_trace.h
L1_COMP_TRACE_DEFS_MODEM += ${COMMON_ROOT}/service/sst/include/ex_trc.h
L1_COMP_TRACE_DEFS_MODEM += ${L1CORE_ROOT}/modem/interface/l1/inner/ul1c_trc.h
L1_COMP_TRACE_DEFS_MODEM += ${L1CORE_ROOT}/modem/interface/l1/inner/ul1a_trc.h
endif

# *************************************************************************
# Common include path
# *************************************************************************
COMMINCDIRS    +=    ${COMMON_ROOT}/interface/service/stacklib \
                     ${PCORE_ROOT}/interface/driver/hwdrv \
                     ${COMMON_ROOT}/interface/driver/md_drv \
                     ${COMMON_ROOT}/interface/modem/l1/gsm/external \
                     ${COMMON_ROOT}/interface/modem/l1/fdd/external \
                     ${CORE_ROOT}/interface/modem/mml1 \
                     ${COMMON_ROOT}/interface/modem/l1/mml1/external \
                     ${COMMON_ROOT}/interface/modem/l1/tdd \
                     $(BUILD_TSTDIR)/include
COMMINCDIRS    +=    ${COMMON_ROOT}/interface/modem/sim \
                     ${COMMON_ROOT}/modem/interface/l1/mml1 \
                     ${L1CORE_ROOT}/modem/gl1/l1d_ext \
                     ${COMMON_ROOT}/interface/modem/l4
COMMINCDIRS    +=    ${COMMON_ROOT}/interface/driver/dp_engine/che
COMMINCDIRS    +=    ${COMMON_ROOT}/modem/interface/general
COMMINCDIRS    +=    ${COMMON_ROOT}/interface/service/sys_svc
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
COMMINCDIRS      +=  $(strip $(CUS_MTK_REL))/dhl/include
endif

COMMINCDIRS    += ${PCORE_ROOT}/modem/gl1/l1d_ext
COMMINCDIRS    += ${COMMON_ROOT}/modem/gl1/l1d_ext
COMMINCDIRS    += ${COMMON_ROOT}/interface/service/dhl
ifneq ($(strip $(DHL_SUPPORT)),TRUE)
COMMINCDIRS    += ${PCORE_ROOT}/interface/service/tst
endif

COMMINCDIRS    +=    ${PCORE_ROOT}/interface/service/nvram \
                     ${COMMON_ROOT}/interface/service/nvram \
                     ${CORE_ROOT}/interface/driver/sleep_drv \
                     ${COMMON_ROOT}/interface/driver/sleep_drv \
                     ${PCORE_ROOT}/interface/service/fs \
                     ${PCORE_ROOT}/driver/connectivity/usb_driver/inc \
                     ${PCORE_ROOT}/driver/connectivity/usb_driver/src \
                     ${PCORE_ROOT}/interface/driver/connectivity/usb_driver \
                     ${PCORE_ROOT}/interface/driver/storage \
                     ${PCORE_ROOT}/interface/modem/general \
                     ${PCORE_ROOT}/interface/modem/mcd \
                     $(strip $(PROJDIR))/modem \
                     $(strip $(PROJDIR))/modem/rrc_asn \
                     $(strip $(PROJDIR))/modem/dbme \
                     $(strip $(PROJDIR))/modem/scsi \
                     $(strip $(PROJDIR))/modem/mcd \
                     $(strip $(PROJDIR))/modem/mcddll \
                     $(strip $(GEN_L4DIR))/mcd \
                     $(strip $(GEN_MMIDIR))/mcd

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
COMMINCDIRS      +=  $(strip $(REL_L4DIR))/mcd \
                     $(strip $(REL_MMIDIR))/mcd \
                     $(strip $(REL_SCSIDIR)) \
                     $(strip $(REL_MCDDIR))
endif

COMMINCDIRS    +=    ${PCORE_ROOT}/interface/driver/drv_sw_def \
                     ${CORE_ROOT}/driver/drv_def \
                     ${PCORE_ROOT}/interface/driver/sys_drv \
                     ${COMMON_ROOT}/interface/driver/sys_drv \
                     ${CORE_ROOT}/interface/service/sys_svc \
                     ${PCORE_ROOT}/driver/sys_drv/emi/inc \
                     ${CORE_ROOT}/driver/sys_drv/init/inc \
                     ${CORE_ROOT}/driver/devdrv/pdn/inc \
                     ${CORE_ROOT}/driver/devdrv/pll/inc \
                     ${CORE_ROOT}/driver/devdrv/cirq/inc \
                     ${CORE_ROOT}/interface/driver/devdrv/cirq \
                     ${COMMON_ROOT}/interface/driver/devdrv/dcm \
                     ${COMMON_ROOT}/interface/driver/devdrv/asm \
                     ${PCORE_ROOT}/interface/driver/devdrv/eint \
                     ${PCORE_ROOT}/interface/driver/devdrv/emi \
                     ${COMMON_ROOT}/driver/devdrv/us_counter/inc \
                     ${PCORE_ROOT}/driver/devdrv/eint/inc \
                     ${CORE_ROOT}/driver/devdrv/drv_def \
                     ${CORE_ROOT}/driver/regbase/inc \
                     ${PCORE_ROOT}/driver/storage/flash/fdm/inc \
                     ${PCORE_ROOT}/driver/cipher/include \
                     ${PCORE_ROOT}/driver/connectivity/usb_driver/inc \
                     ${PCORE_ROOT}/driver/storage/flash/mtd/inc \
                     ${PCORE_ROOT}/driver/drv/include \
                     ${COMMON_ROOT}/interface/sap \
                     ${COMMON_ROOT}/interface/sap/md \
                     ${COMMON_ROOT}/interface/sap/mw \
                     ${COMMON_ROOT}/interface/sap/drv \
                     ${COMMON_ROOT}/interface/sap/svc
COMMINCDIRS      +=  ${COMMON_ROOT}/driver/devdrv/mdap_interface/inc

ifeq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
ifeq ($(strip $(EUTRAN_MODE_SUPPORT)), EUTRAN_MODE)
ifeq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
  COMMINCDIRS += ${COMMON_ROOT}/driver/devdrv/us_counter/inc
endif
endif
endif

COMMINCDIRS += $(strip $(GEN_SSDIR))
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  COMMINCDIRS += $(strip $(REL_SSDIR))
endif

COMMINCDIRS       += $(BUILD_TST_DB)/pstrace_db
COMMINCDIRS       += ${PCORE_ROOT}/interface/service/fs \
                     ${COMMON_ROOT}/interface/common

# Poying: There should be some feature option defining __UGTCM__
UGTCM = FALSE
ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  UGTCM = TRUE
else
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    UGTCM = TRUE
  endif
endif

COMMINCDIRS    += ${PCORE_ROOT}/custom/modem/l1_rf/$(RF_MODULE)
COMMINCDIRS    += ${COMMON_ROOT}/interface/service/config
COMMINCDIRS    += ${PCORE_ROOT}/interface/modem/mml1
COMMINCDIRS    += ${PCORE_ROOT}/custom/modem/mml1_rf/$(MM_RF_MODULE)

ifeq ($(strip $(L1_WCDMA)),TRUE)
  ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT) 
    COMMINCDIRS += ${PCORE_ROOT}/custom/modem/ul1_rf/$(UMTS_RF_MODULE)
  endif
endif

ifeq ($(strip $(L1_TDD128)),TRUE)
  COMMINCDIRS += ${PCORE_ROOT}/custom/modem/tl1_rf/$(UMTS_TDD128_RF_MODULE)
endif

ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
  COMMINCDIRS += ${PCORE_ROOT}/custom/modem/el1_rf/$(LTE_RF_MODULE)
endif

COMMINCDIRS       +=  $(call CUSTOM_FLD_MAPPING,${CORE_ROOT}/custom/modem/ps) \
                      ${PCORE_ROOT}/custom/modem/common/ps \
                      ${PCORE_ROOT}/custom/service/nvram \
                      ${PCORE_ROOT}/custom/service/flc2 \
                      ${PCORE_ROOT}/custom/driver/common \
                      ${PCORE_ROOT}/custom/middleware/common \
                      ${PCORE_ROOT}/custom/modem/common
COMMINCDIRS       +=  ${CORE_ROOT}/interface/service/event_info
COMMINCDIRS       +=  ${PCORE_ROOT}/modem/l4/tcm/rat_tcm/inc \
                      ${PCORE_ROOT}/modem/interface/lte \
                      ${PCORE_ROOT}/modem/interface/upcm \
                      ${PCORE_ROOT}/interface/modem/upcm \
                      ${COMMON_ROOT}/interface/driver/devdrv/pcmon \
                      ${COMMON_ROOT}/interface/driver/devdrv/pfb

ifeq ($(strip $(ETCM)),TRUE)
  COMMINCDIRS += ${CORE_ROOT}/modem/l4/tcm/etcm/include
endif

ifeq (${CORE_ROOT},l1core)
  COMMINCDIRS += ${CORE_ROOT}/modem/gl1/l1d_ext \
                 ${COMMON_ROOT}/interface/service/sys_svc
endif
COMMINCDIRS += $(UNIVERSAL_COMMON)/interface/driver/sys_drv

# *************************************************************************
# Common preprocessor definitions
# *************************************************************************

# L1S and full load
ifneq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  CUSTOM_OPTION +=  __PS_L1_DC_ARCH__
endif

ifeq ($(strip $(L1S_BASIC)),TRUE)
  CUSTOM_OPTION    +=  __L1_STANDALONE__ __CS_SERVICE__

  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    CUSTOM_OPTION    +=  DUMMY_PROTOCOL __FS_ON__ 
    ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
      CUSTOM_OPTION    +=  __MULTI_BOOT__
    endif
  endif

  ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
    CUSTOM_OPTION    +=  L1_NOT_PRESENT NVRAM_NOT_PRESENT
#    ifneq (${CORE_ROOT},l1core)
        CUSTOM_OPTION += __MAUI_BASIC__
#    endif
    ifneq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
      CUSTOM_OPTION     += MTK_SYSSERV_DEBUG 
    endif
  
    ifeq ($(strip $(IC_TEST_TYPE)),IC_MODULE_TEST)
      CUSTOM_OPTION += IC_MODULE_TEST
      CUSTOM_OPTION += DEVDRV_TEST
    endif

    ifeq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
      CUSTOM_OPTION    +=  IC_BURNIN_TEST
      CUSTOM_OPTION += DEVDRV_TEST
    endif
  endif

  ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    CUSTOM_OPTION    +=  L1_NOT_PRESENT __MEUT__ NVRAM_NOT_PRESENT __MAUI_BASIC__
    CUSTOM_OPTION    +=  __UDVT__
  endif

CUSTOM_OPTION    += L4_NOT_PRESENT MM_NOT_PRESENT CC_NOT_PRESENT CISS_NOT_PRESENT NWSEL_NOT_PRESENT\
                      SMS_NOT_PRESENT SIM_NOT_PRESENT RR_NOT_PRESENT \
                      MMI_NOT_PRESENT SNDCP_NOT_PRESENT SM_NOT_PRESENT REASM_NOT_PRESENT \
                      LLC_NOT_PRESENT DATA_NOT_PRESENT PPP_NOT_PRESENT MED_NOT_PRESENT \
                      WAP_NOT_PRESENT ABM_NOT_PRESENT SOC_NOT_PRESENT TCPIP_NOT_PRESENT \
                      __18V_30V_ME__ MED_V_NOT_PRESENT

  ifdef L1_UMTS
    ifeq ($(strip $(L1_UMTS)),TRUE)
      CUSTOM_OPTION    += RATCM_NOT_PRESENT RATDM_NOT_PRESENT UL2D_NOT_PRESENT UL2_NOT_PRESENT URR_NOT_PRESENT
      ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        CUSTOM_OPTION    += __UL1_STANDALONE__
      endif
    endif
  endif

  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S) 
    ifeq ($(strip $(NVRAM_SUPPORT)),TRUE)
      CUSTOM_OPTION  += __MOD_NVRAM__
    else
      CUSTOM_OPTION  += NVRAM_NOT_PRESENT
    endif
  
    ifeq ($(strip $(L1_GPRS)),TRUE)
      ifeq ($(strip $(PLATFORM)),MT6205B)
        $(error: MT6205B not support GPRS)
      endif
      CUSTOM_OPTION    +=  __PS_SERVICE__
    endif
  
    ifeq ($(strip $(L1_EGPRS)),TRUE)
      CUSTOM_OPTION    += __EGPRS_MODE__
      ifeq ($(strip $(L1_EPSK_TX)),TRUE)
        CUSTOM_OPTION    +=  __EPSK_TX__
      endif   
    endif
  
    ifeq ($(strip $(L1D_LOOPBACK)),1)
      COMPLIST         +=  l1d_lp1
      L1_TMD_FILES     +=  ${L1CORE_ROOT}/modem/gl1/common/L1DLP_Trace.tmd
      ifneq ($(strip $(L1_UMTS)),TRUE)
        COMMINCDIRS   +=  ${L1CORE_ROOT}/modem/gl1/l1d_lp1
      endif
      CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),2)
      COMPLIST         +=  l1d_lp2
      L1_TMD_FILES     +=  ${L1CORE_ROOT}/modem/gl1/common/L1DLP_Trace.tmd
      ifneq ($(strip $(L1_UMTS)),TRUE)
        COMMINCDIRS   +=  ${L1CORE_ROOT}/modem/gl1/l1d_lp2
      endif
      CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),3)
      COMPLIST         +=  l1d_lp3
      L1_TMD_FILES     +=  ${L1CORE_ROOT}/modem/gl1/common/L1DLP3_Trace.tmd
      ifneq ($(strip $(L1_UMTS)),TRUE)
        COMMINCDIRS   +=  ${L1CORE_ROOT}/modem/gl1/l1d_lp3
      endif
      CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),5)
       COMPLIST         +=  l1d_lp5
       L1_TMD_FILES     +=  ${L1CORE_ROOT}/modem/gl1/common/L1DLP5_Trace.tmd
       COMMINCDIRS   +=  ${L1CORE_ROOT}/modem/gl1/l1d_lp5
       CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),6)
       COMPLIST         +=  l1d_lp6
       L1_TMD_FILES     +=  ${L1CORE_ROOT}/modem/gl1/common/L1DLP6_Trace.tmd
       COMMINCDIRS   +=  ${L1CORE_ROOT}/modem/gl1/l1d_lp6
       CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),7)
       COMPLIST         +=  l1d_lp7
       L1_TMD_FILES     +=  ${L1CORE_ROOT}/modem/gl1/common/L1DLP7_Trace.tmd
       COMMINCDIRS   +=  ${L1CORE_ROOT}/modem/gl1/l1d_lp7
       CUSTOM_OPTION    +=  L1D_TEST
    endif

    ifeq ($(strip $(L1D_LOOPBACK)),8)
       COMPLIST         +=  l1d_lp8
       L1_TMD_FILES     +=  ${L1CORE_ROOT}/modem/gl1/common/L1DLP8_Trace.tmd
       COMMINCDIRS   +=  ${L1CORE_ROOT}/modem/gl1/l1d_lp8
       CUSTOM_OPTION    +=  L1D_TEST
    endif
  
    ifeq ($(strip $(L1D_COSIM)),TRUE)
      CUSTOM_OPTION    +=  L1D_TEST_COSIM
    endif

    ifeq ($(strip $(ISP_SUPPORT)),TRUE)
      CUSTOM_OPTION    += ISP_SUPPORT
    endif
  endif
else # L1S_BASIC = FALSE

  CUSTOM_OPTION    +=   __MOD_L4C__ __MOD_RAC__ __MOD_SMU__ __MOD_SMSAL__ \
                       __MOD_PHB__ __MOD_UEM__  \
                      __MOD_NVRAM__ __MOD_SIM__ \
                       __SAT__ __EM_MODE__ __CPHS__ \
                       __18V_30V_ME__  __PHB_COMPARE_NUMBER_9_DIGIT__
  # Non LTE single-mode  
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    CUSTOM_OPTION    += __MULTI_BOOT__ __MOD_CC__ __MOD_CISS__ __MOD_CSM__ __MOD_SMS__ __MOD_NWSEL__ __MOD_MM__
  else
    CUSTOM_OPTION    += MM_NOT_PRESENT ABM_NOT_PRESENT CC_NOT_PRESENT CISS_NOT_PRESENT DATA_NOT_PRESENT LLC_NOT_PRESENT \
                        MED_NOT_PRESENT MED_V_NOT_PRESENT MMI_NOT_PRESENT PPP_NOT_PRESENT RATCM_NOT_PRESENT RATDM_NOT_PRESENT \
                        REASM_NOT_PRESENT RR_NOT_PRESENT SM_NOT_PRESENT SNDCP_NOT_PRESENT SOC_NOT_PRESENT \
                        TCPIP_NOT_PRESENT UL1_NOT_PRESENT UL2D_NOT_PRESENT URR_NOT_PRESENT
  endif
  
  ifneq ($(filter NONE MODEM_ONLY,$(SMART_PHONE_CORE)),)
    CUSTOM_OPTION    += __FS_ON__
  endif
endif

#MML1 trace macro
ifneq ($(strip $(UE_SIMULATOR)),TRUE)
  ifneq (${CORE_ROOT},pcore)
    L1_TMD_FILES += ${L1CORE_ROOT}/modem/mml1/common/mml1_trace.tmd \
                    ${L1CORE_ROOT}/modem/mml1/common/mml1_trace_bb_dsp0.tmd \
                    ${L1CORE_ROOT}/modem/mml1/common/mml1_trace_rfc.tmd
  else
    L1_TMD_FILES += ${PCORE_ROOT}/modem/mml1/common/mmrf_pcore_trace.tmd
  endif
endif

ifneq ($(strip $(L1_UMTS)),TRUE)
  ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_GSM_MODE)
    CUSTOM_OPTION += RATDM_NOT_PRESENT
  endif
  ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
    CUSTOM_OPTION += RATDM_NOT_PRESENT RATCM_NOT_PRESENT
  endif
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    CUSTOM_OPTION +=  __GSM_RAT__ __MTK_3G_MRAT_ARCH__
  endif
endif

ifneq ($(strip $(CENTRALIZED_SLEEP_MANAGER)),TRUE)
  CUSTOM_OPTION += __NEW_OS_TICK__
endif

CUSTOM_OPTION     += FMT_NOT_PRESENT
CUSTOM_OPTION     += __FLIGHT_MODE_SUPPORT__

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
    CUSTOM_OPTION += __CS_SERVICE__ __PS_SERVICE__ __MOD_TCM__ __MOD_TFTLIB__
  else
    ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
      CUSTOM_OPTION += __CS_SERVICE__ __PS_SERVICE__ __MOD_TCM__ __MOD_TFTLIB__
    else
      ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
        CUSTOM_OPTION += __CS_SERVICE__ __PS_SERVICE__ __MOD_TCM__ __MOD_TFTLIB__
      else
        CUSTOM_OPTION += __CS_SERVICE__ SNDCP_NOT_PRESENT SM_NOT_PRESENT REASM_NOT_PRESENT LLC_NOT_PRESENT
      endif
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    CUSTOM_OPTION += __GSM_RAT__
  endif
endif

ifeq ($(filter BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    CUSTOM_OPTION += __MTK_GL1_GSM__
  endif
  ifdef L1_WCDMA
    ifeq ($(strip $(L1_WCDMA)),TRUE)
      CUSTOM_OPTION    +=  __UMTS_RAT__ __MTK_3G_MRAT_ARCH__
      CUSTOM_OPTION  += MAL1_NOT_PRESENT __MTK_UL1_FDD__
    endif
  endif
  ifdef L1_TDD128
   ifeq ($(strip $(OP01_2G_ONLY)),FALSE)
    ifeq ($(strip $(L1_TDD128)),TRUE)
      CUSTOM_OPTION    +=  __UMTS_RAT__ __MTK_3G_MRAT_ARCH__ __TDD_DM_GAP_OPTIMIZATION__
      ifeq ($(strip $(TL1_3GSOLUTION)),MTK_TL1_TDD)
        CUSTOM_OPTION  += __AST_TL1_TDD__ __RACH_FACH_TL1_BITOFFSET__
      endif
      ifeq ($(strip $(TL1_3GSOLUTION)),AST_TL1_TDD)
        ifeq ($(strip $(AST_SUPPORT)),AST1001)
          CUSTOM_OPTION  += __AST1001__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST1001_LIB)
          CUSTOM_OPTION  += __AST1001__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001)
          CUSTOM_OPTION  += __AST2001__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001_LIB)
          CUSTOM_OPTION  += __AST2001__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001FPGA)
          CUSTOM_OPTION  += __AST2001FPGA__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST2001FPGA_LIB)
          CUSTOM_OPTION  += __AST2001FPGA__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST3001)
          CUSTOM_OPTION  += __AST3001__
        endif
        ifeq ($(strip $(AST_SUPPORT)),AST3001_LIB)
          CUSTOM_OPTION  += __AST3001__
        endif
        CUSTOM_OPTION  += __AST_TL1_TDD__ __RACH_FACH_TL1_BITOFFSET__
        CUSTOM_OPTION  += __AST_$(strip $(AST_CHIP_VERSION))__
      endif
    endif
   endif
  endif
endif

CUSTOM_OPTION += __SYS_INTERN_RAM__
CUSTOM_OPTION += MTK_NEW_API

ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  CUSTOM_OPTION  += __PRODUCTION_RELEASE__
endif

ifeq ($(strip $(DHL_SUPPORT)),TRUE)
  CUSTOM_OPTION    += __DHL_MODULE__ TST_TRACE_COMPAT __TST_MODULE__
else
  ifeq ($(strip $(TST_SUPPORT)),TRUE)
    CUSTOM_OPTION    += __TST_MODULE__
  else
      CUSTOM_OPTION    += DRV_DEBUG
  endif
endif

ifeq ($(strip $(MCD_SUPPORT)),TRUE)
  ifeq ($(CORE_ROOT),pcore)
    ifeq ($(strip $(L1S_BASIC)),FALSE)
      CUSTOM_OPTION    += __MCD__
    endif
  endif
endif

CUSTOM_OPTION += EMPTY_MMI

ifeq ($(strip $(SPLIT_SYSTEM)),TRUE)
   CUSTOM_OPTION    += UT_ON_TARGET SPLIT_SYS
endif

ifeq ($(strip $(EMAIL_SUPPORT)),TRUE)
   CUSTOM_OPTION    += __EMAIL__
endif

ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
   CUSTOM_OPTION    += __IRDA_SUPPORT__
endif

ifneq ($(strip $(PHB_SIM_ENTRY)),)
  CUSTOM_OPTION += __PHB_SIM_$(strip $(PHB_SIM_ENTRY))__
endif

ifneq ($(strip $(PHB_PHONE_ENTRY)),)
  CUSTOM_OPTION += __PHB_PHONE_$(strip $(PHB_PHONE_ENTRY))__
endif

ifeq ($(strip $(PMIC)),MT6305)
     CUSTOM_OPTION    += MT6305 __CHARGER_WITH_IMMEDIMATE_ADC__
endif

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  CUSTOM_OPTION    += __DSP_FCORE4__
endif

ifdef BROWSER_SUPPORT
  ifneq ($(strip $(BROWSER_SUPPORT)),NONE)
    ifneq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_GSM_MODE)
      CUSTOM_OPTION    +=  __SATCC__ 
    endif
  endif
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  CUSTOM_OPTION    += __IDLE_INTERF_MEAS__ __PKT_EXT_MEAS__
endif

CUSTOM_OPTION += __AMR_WB_WHITE_LIST__
ifeq ($(strip $(UGTCM)),TRUE)
  CUSTOM_OPTION += __UGTCM__
endif

ifeq ($(strip $(ETCM)),TRUE)
  CUSTOM_OPTION += __ETCM__
endif

ifeq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  CUSTOM_OPTION    +=  L1_NOT_PRESENT
endif

ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
  #enable 4G
  ifdef FDD_LTE_SUPPORT
    ifeq ($(strip $(FDD_LTE_SUPPORT)),FALSE)
        CUSTOM_OPTION += __4G_TDD_ONLY__
    endif
  endif
  ifdef TDD_LTE_SUPPORT
    ifeq ($(strip $(TDD_LTE_SUPPORT)),FALSE)
        CUSTOM_OPTION += __4G_FDD_ONLY__
    endif
  endif
  ifeq ($(filter TRUE,$(FDD_LTE_SUPPORT) $(TDD_LTE_SUPPORT)),)
    $(warning ERROR: One of FDD_LTE_SUPPORT/TDD_LTE_SUPPORT need to be supported at least when EUTRAN_MODE_SUPPORT is supported.)
    DEPENDENCY_CONFLICT = TRUE
  endif
else
  #do not enable 4G
  ifdef FDD_LTE_SUPPORT
    ifeq ($(strip $(FDD_LTE_SUPPORT)),TRUE)
      $(warning ERROR: FDD_LTE_SUPPORT only can be supported when EUTRAN_MODE_SUPPORT is not supported.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef TDD_LTE_SUPPORT
    ifeq ($(strip $(TDD_LTE_SUPPORT)),TRUE)
      $(warning ERROR: TDD_LTE_SUPPORT only can be supported when EUTRAN_MODE_SUPPORT is not supported.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq (${CORE_ROOT},pcore)
ifeq ($(strip $(IMS_SUPPORT)),TRUE)
  #imc/imcb
  COMPLIST          += imc

  CUSTOM_OPTION      += __IMCF_MTK_MD__=1 __IMC_IGNORE_TODO_ASSERT__=1
  CUSTOM_OPTION      += __MOD_IMC__=1 __MOD_IMCB__=1 __IMC_SUB_IMC__=1 
  CUSTOM_OPTION      += __IMC_SUB_IMC_MNGR__=1 __IMC_SUB_IMC_REG__=1 __IMC_SUB_IMC_CC__=1  __IMC_SUB_IMC_SMSIP__=1 __IMC_SUB_IMC_SS__=1
  CUSTOM_OPTION      += __IMC_MULTIPLE_CONTEXT__

  ifneq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
    CUSTOM_OPTION      += __IMC_RELAY_TYPE_CCCI__
  endif

  COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/imc/sub_imc/include/imc_trc.h

  COMPLIST += vdm

  COMMINCDIRS += ${CORE_ROOT}/modem/interface/ims
  
  COMP_TRACE_DEFS_MODEM  +=  ${CORE_ROOT}/modem/vdm/common/include/vdm_trc.h \
                             ${CORE_ROOT}/modem/vdm/trk/include/vdm_trk_trc.h \
                             ${CORE_ROOT}/modem/vdm/ads/include/vdm_ads_trc.h \
                             ${CORE_ROOT}/modem/vdm/vcc/include/vdm_vcc_trc.h

  # LTECSR
  COMPLIST += rtp ltecsr ltecsr_src
  
  # SDM
  COMPLIST += sdm
  COMP_TRACE_DEFS_MODEM  +=  ${CORE_ROOT}/modem/sdm/include/sdm_trc.h

  # IMSP
  COMPLIST    +=  imsp
  COMP_TRACE_DEFS_MODEM  +=  ${CORE_ROOT}/modem/imsp/include/imsp_trc.h

  # IMCSMS
  CUSTOM_OPTION += __MOD_IMCSMS__
  COMPLIST    +=  imcsms
  COMP_TRACE_DEFS_MODEM  +=  ${CORE_ROOT}/modem/imc/imcsms/include/imcsms_trc.h

endif
endif

ifneq (${CORE_ROOT},l1core)
  ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifneq ($(ORIGINAL_FLAVOR),BASIC_HIF)
      ifeq ($(strip $(KPALV_SUPPORT)),TRUE)
        COMPLIST         += kpalv
        COM_DEFS         += __KPALV_SUPPORT__
        COMMINCDIRS      += ${CORE_ROOT}/interface/middleware/kpalv
        COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/kpalv/include/kpalv_trace.h
      endif
    endif
  endif
endif

#always turn on
COM_DEFS    +=   __3G_RX_PATH_SELECTION_SUPPORT__
COM_DEFS    +=   __DOCOMO_IOT_LR_BEFORE_ECC__
COM_DEFS    +=  __ANDROID_TXRX_ACTIVE_TIME__

#Custom Option for SE3 UT
ifneq ($(strip $(UE_SIMULATOR)),TRUE)
  ifeq ($(strip $(MODIS_CONFIG)),TRUE)
      COM_DEFS += __L4C_GPRS_UT__
      COM_DEFS += __EM_MODE__ __MODEM_EM_MODE__ UNIT_TEST __TCM_UT__ __TCM_UGTCM_UT__ __IMS_SUPPORT__
      COM_DEFS += __IPV6__ __IPV4V6__ __REL7__ __REL8__
      COM_DEFS += __SP_GEMINI_3G_SWITCH__ __NRSPCA__
      COM_DEFS += __SM_UT__ __IPV6_8960_RD_INTERNAL_TEST__ __SM_PRESERVE_RT_PDP_SEVERAL_SECONDS__
      COM_DEFS += __TCM_RAT_TCM_UT__ __TCM_CID_0_SUPPORT__
      COM_DEFS += __PAM_UT__
      #COM_DEFS += __TFTLIB_UT__

      #RATDM UT
      COM_DEFS += __RATDM_UT__

      #PDCP/RABM/RFC2507 UT
      COM_DEFS += __PDCP_UT__ __RFC2507_PDCP_UT__ __PDCP_LOOPBACK_UT__
      COM_DEFS += __RFC2507_CHECK_MEM_LEAK__ __RFC2507_PKT_GEN_TEST__ __RFC2507_CHECK_MEM_LEAK__ __RFC2507_PKT_GEN_TEST__

      #LLC UT
      COM_DEFS += __LLC_UT__

      #SNDCP UT
      COM_DEFS += __SNDCP_UT__ SND_UT_FLC

      #CSD UT
      COM_DEFS += RLP_UT L2R_UT TDT_UT
      CSD_SUPPORT = T_NT
      COM_DEFS += __CSD_T__
      COM_DEFS += __CSD_NT__

      #Removed due to PS1 request (Hope UT logic is same with real target)
      #COM_DEFS += __MULTI_CARRIER_HSDPA__=3
      #COM_DEFS += __DCHSUPA_ADJ_FREQ_SUPPORT__
  endif
endif

ifeq ($(filter REL_CR_%,$(strip $(RELEASE_PACKAGE))),)
  COM_DEFS += __MTK_INTERNAL_ENG_USER__
  ifeq ($(filter __MTK_INTERNAL_ENG_USER__,$(COM_DEFS)),)
    $(warning ERROR: __MTK_INTERNAL_ENG_USER__ should be enabled in MTK_INTERNAL(eng/user) projects.)
    DEPENDENCY_CONFLICT = TRUE
  endif
else #neq REL_CR_xxx
  ifneq ($(filter __MTK_INTERNAL_ENG_USER__,$(COM_DEFS)),)
    $(warning ERROR: __MTK_INTERNAL_ENG_USER__ cannot be enabled in customer projects.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# RF Module Options
#add for UESIM project
COM_DEFS_FOR_MT6176_UMTS_FDD = MT6176_RF MT6176_UMTS_FDD
COM_DEFS_FOR_MT6176_LTE = MT6176_RF MT6176_LTE_RF

COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(RF_MODULE))
ifdef $(COM_DEFS_FOR_RF_MODULE)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(RF_MODULE)))
else
  $(warning ERROR: [COM_DEFS_FOR_$(strip $(RF_MODULE))] was not defined)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef UMTS_RF_MODULE
ifneq ($(strip $(UMTS_RF_MODULE)),NONE)
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS  +=  $(COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE)))
  else
    $(warning ERROR: [COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))] was not defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif

ifdef UMTS_TDD128_RF_MODULE
ifneq ($(strip $(UMTS_TDD128_RF_MODULE)),NONE)
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(UMTS_TDD128_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS  +=  $(COM_DEFS_FOR_$(strip $(UMTS_TDD128_RF_MODULE)))
  else
    $(warning ERROR: [COM_DEFS_FOR_$(strip $(UMTS_TDD128_RF_MODULE))] was not defined) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif

ifdef LTE_RF_MODULE
ifneq ($(strip $(LTE_RF_MODULE)),NONE)
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(LTE_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS  +=  $(COM_DEFS_FOR_$(strip $(LTE_RF_MODULE)))
  else
    $(warning ERROR: [COM_DEFS_FOR_$(strip $(LTE_RF_MODULE))] was not defined) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif

# check AFC_VCXO_TYPE matches RF_MODULE
ifdef AFC_VCXO_TYPE
  ifdef RF_MODULE

    VCXO_PLATFORM = MT6139B MT6139C MT6139E
    ifneq ($(filter $(strip $(RF_MODULE)),$(VCXO_PLATFORM)),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        ifeq ($(filter MT6268A MT6270A MT6276,$(strip $(PLATFORM))),)
          $(warning ERROR: MT6139 series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    
    VCTCXO_RF_MODULE_LIST = MT6129D MT6129 MT6119 BRIGHT4 MT6140A SKY74117 SKY74045 BRIGHT5P FOUNTAIN
    ifneq ($(filter $(strip $(VCTCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE))),)
      VCTCXO_RF_MODULE = $(filter $(strip $(VCTCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE)))
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING $(VCTCXO_RF_MODULE) series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif

    VCXO_RF_MODULE_LIST = AERO MT6139
    ifneq ($(filter $(strip $(VCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE))),)
      VCXO_RF_MODULE = $(filter $(strip $(VCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE)))
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        $(warning WARNING $(VCXO_RF_MODULE) series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
      endif
    endif

  endif
endif

# Board Options
ifneq ($(strip $(BOARD_VER)),)
  COM_DEFS    += $(BOARD_VER)
endif

# Board Subversion
ifneq ($(strip $(SUB_BOARD_VER)),)
  COM_DEFS    += $(SUB_BOARD_VER)
endif

# BAND_SUPPORT Options
COM_DEFS_FOR_PGSM900   = __PGSM900__
COM_DEFS_FOR_EGSM900   = __EGSM900__
COM_DEFS_FOR_RGSM900   = __RGSM900__
COM_DEFS_FOR_DCS1800   = __DCS1800__
COM_DEFS_FOR_PCS1900   = __PCS1900__
COM_DEFS_FOR_GSM850    = __GSM850__
COM_DEFS_FOR_GSM450    = __GSM450__
COM_DEFS_FOR_DUAL900   = __EGSM900__ __DCS1800__
COM_DEFS_FOR_TRIPLE    = __EGSM900__ __DCS1800__ __PCS1900__
COM_DEFS_FOR_QUAD      = __EGSM900__ __DCS1800__ __PCS1900__  __GSM850__
COM_DEFS_FOR_DUAL850   = __GSM850__ __PCS1900__
COM_DEFS_FOR_TRIPLE850 = __GSM850__ __DCS1800__ __PCS1900__  TRIPLE850

COM_DEFS_FOR_BAND_SUPPORT =  COM_DEFS_FOR_$(strip $(BAND_SUPPORT))
ifdef $(COM_DEFS_FOR_BAND_SUPPORT)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(BAND_SUPPORT)))
else
  COM_DEFS += __EGSM900__ __DCS1800__   # the same as DUAL900
endif


# UMTS_BAND_SUPPORT Options
UMTS_SUPPORT_BAND =
ifdef UMTS_BAND_I
  ifeq ($(strip $(UMTS_BAND_I)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_I__
  endif
endif
ifdef UMTS_BAND_II
  ifeq ($(strip $(UMTS_BAND_II)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_II__
  endif
endif
ifdef UMTS_BAND_III
  ifeq ($(strip $(UMTS_BAND_III)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_III__
  endif
endif
ifdef UMTS_BAND_IV
  ifeq ($(strip $(UMTS_BAND_IV)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_IV__
  endif
endif
ifdef UMTS_BAND_V
  ifeq ($(strip $(UMTS_BAND_V)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_V__
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VI__
  endif
endif
ifdef UMTS_BAND_VI
  ifeq ($(strip $(UMTS_BAND_VI)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_V__
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VI__
  endif
endif
ifdef UMTS_BAND_VII
  ifeq ($(strip $(UMTS_BAND_VII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VII__
  endif
endif
ifdef UMTS_BAND_VIII
  ifeq ($(strip $(UMTS_BAND_VIII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VIII__
  endif
endif
ifdef UMTS_BAND_IX
  ifeq ($(strip $(UMTS_BAND_IX)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_IX__
  endif
endif
ifdef UMTS_BAND_X
  ifeq ($(strip $(UMTS_BAND_X)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_X__
  endif
endif
ifeq ($(strip $(UMTS_BAND_XI)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XI__
endif
ifeq ($(strip $(UMTS_BAND_XII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XII__
endif
ifeq ($(strip $(UMTS_BAND_XIII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XIII__
endif
ifeq ($(strip $(UMTS_BAND_XIV)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XIV__
endif
ifeq ($(strip $(UMTS_BAND_XV)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XV__
endif
ifeq ($(strip $(UMTS_BAND_XVI)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XVI__
endif
ifeq ($(strip $(UMTS_BAND_XVII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XVII__
endif
ifeq ($(strip $(UMTS_BAND_XVIII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XVIII__
endif
ifeq ($(strip $(UMTS_BAND_XIX)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XIX__
endif
ifeq ($(strip $(UMTS_BAND_XX)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XX__
endif
ifeq ($(strip $(UMTS_BAND_XXI)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XXI__
endif
ifeq ($(strip $(UMTS_BAND_XXII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XXII__
endif
COM_DEFS    +=  $(strip $(UMTS_SUPPORT_BAND))
# Due to uas ul2 RRC Specification (InterRATHandoverInfo message) limitation, UE at most supports 4 bands in band I~VII.
UMTS_SUPPORT_BAND_I_TO_VII_COUNT = $(words $(filter __UMTS_BAND_I__ __UMTS_BAND_II__ __UMTS_BAND_III__ __UMTS_BAND_IV__ __UMTS_BAND_V__ __UMTS_BAND_VI__ __UMTS_BAND_VII__,$(sort $(strip $(UMTS_SUPPORT_BAND)))))
ifeq ($(call gt,$(strip $(UMTS_SUPPORT_BAND_I_TO_VII_COUNT)),4),T)
  $(warning ERROR: UE at most supports 4 bands in band I~VII due to RRC Specification limitation (UE supports $(strip $(UMTS_SUPPORT_BAND))))
  DEPENDENCY_CONFLICT = TRUE
endif

# UMTS TDD128 BAND SUPPORT Options
ifdef UMTS_TDD128_BAND_A
  ifeq ($(strip $(UMTS_TDD128_BAND_A)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_A__
  endif
endif
ifdef UMTS_TDD128_BAND_B
  ifeq ($(strip $(UMTS_TDD128_BAND_B)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_B__
  endif
endif
ifdef UMTS_TDD128_BAND_C
  ifeq ($(strip $(UMTS_TDD128_BAND_C)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_C__
  endif
endif
ifdef UMTS_TDD128_BAND_D
  ifeq ($(strip $(UMTS_TDD128_BAND_D)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_D__
  endif
endif
ifdef UMTS_TDD128_BAND_E
  ifeq ($(strip $(UMTS_TDD128_BAND_E)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_E__
  endif
endif
ifdef UMTS_TDD128_BAND_F
  ifeq ($(strip $(UMTS_TDD128_BAND_F)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_F__
  endif
endif

# AFC_VCXO_TYPE Options
COM_DEFS_FOR_VCXO       = AFC_VCXO
COM_DEFS_FOR_VCXO_SC    = AFC_VCXO AFC_SC
COM_DEFS_FOR_VCXO_TC    = AFC_VCXO AFC_TC
COM_DEFS_FOR_VCXO_SC_TC = AFC_VCXO AFC_SC AFC_TC
COM_DEFS_FOR_VCXO_2G    = AFC_VCXO_2G

COM_DEFS_FOR_AFC_VCXO_TYPE =  COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE))
ifdef $(COM_DEFS_FOR_AFC_VCXO_TYPE)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE)))
endif

COM_DEFS_FOR_AFC_VCXO_TYPE_2G =  COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE_2G))
ifdef $(COM_DEFS_FOR_AFC_VCXO_TYPE_2G)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE_2G)))
endif

ifeq ($(strip $(DUAL_TALK_RFIC2_SUPPORT)),TRUE)
  COM_DEFS    += __DUAL_TALK_SUPPORT__
endif

DUMMY_SCATTER_ENABLE_PLATFORM = MT6252 MT6250
ifeq ($(filter $(strip $(PLATFORM)),$(DUMMY_SCATTER_ENABLE_PLATFORM)),)
  ifeq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
    $(warning ERROR: DUMMY_SCATTER_ENABLE can only be enabled when PLATFORM is $(DUMMY_SCATTER_ENABLE_PLATFORM))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    $(warning ERROR: DUMMY_SCATTER_ENABLE cannot be enabled when DEMO_PROJECT=TRUE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifdef NAND_FLASH_BOOTING
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(warning ERROR: DUMMY_SCATTER_ENABLE cannot be enabled when NAND_FLASH_BOOTING is not NONE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef PMIC_PRESENT
  ifeq ($(strip $(PMIC_PRESENT)),TRUE)
    COM_DEFS    += PMIC_PRESENT
  endif
endif

ifdef PMIC
  ifneq ($(strip $(PMIC)),NONE)
     COM_DEFS    += PMIC_PRESENT
  endif

  ifeq ($(strip $(PMIC)),MT6353)
    COM_DEFS    +=   __INCREASE_VS1_VOLTAGE_SUPPORT__   
  endif  
  
  PMIC_MT6339_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
  ifeq ($(strip $(PMIC)),MT6339)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6339_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(PMIC)),MT6332)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6331_MT6332_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  
  ifeq ($(strip $(PMIC)),MT6331_PLUS_MT6332)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6331_MT6332_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  
  PMIC_MT6325_SUPPORT_PLATFORM = MT6752 TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
  ifeq ($(strip $(PMIC)),MT6325)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6325_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  
  PMIC_MT6351_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
  ifeq ($(strip $(PMIC)),MT6351)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6351_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif  
  PMIC_MT6355_SUPPORT_PLATFORM = MT6798 MT6757 MT6757P
  ifeq ($(strip $(PMIC)),MT6355)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6355_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif  
endif

NEED_ADD_PMIC_COMPILE_LIST =  MT6327 MT6320 MT6339 MT6331 MT6332 MT6331_PLUS_MT6332 MT6325 MT6351 MT6353 MT6355
ifneq ($(filter $(NEED_ADD_PMIC_COMPILE_LIST),$(PMIC)),)
	ifeq ($(strip $(PMIC)),MT6331_PLUS_MT6332)
	    COM_DEFS    += MT6331 MT6332
	else
	    COM_DEFS    += $(PMIC)
	endif
endif

ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
     #COM_DEFS    +=  __CUST_NEW__
  endif
endif

CRYSTAL_ON_PMIC_SUPPORT_PMIC_VER = MT6351 MT6353 MT6355
ifeq ($(strip $(L1_CRYSTAL_ON_PMIC_SUPPORT)),TRUE) 
  ifneq ($(filter $(CRYSTAL_ON_PMIC_SUPPORT_PMIC_VER),$(strip $(PMIC))),)
    COM_DEFS    +=   __L1_CRYSTAL_ON_PMIC_SUPPORT__
  endif
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NAND_FLASH)
  ifneq ($(strip $(NAND_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FLASH_TEST_SELECT,non NAND_FLASH,NAND_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __NAND_FLASH_HARDWARE_TEST__
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NOR_FLASH)
  COM_DEFS    += __NOR_FLASH_HARDWARE_TEST__
endif

ifdef NAND_SUPPORT
  ifdef SYSTEM_DRIVE_ON_NAND
    ifeq ($(strip $(NAND_SUPPORT)),FALSE)
      ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,SYSTEM_DRIVE_ON_NAND)
         DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    COM_DEFS    += NAND_SUPPORT
  endif
endif

ifdef NAND_SUPPORT
  ifdef SYSTEM_DRIVE_ON_NAND
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM =  MT6575 MT6577 MT6280
      ifeq ($(filter $(strip $(PLATFORM)) ,$(SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support SYSTEM_DRIVE_ON_NAND.)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(NAND_SUPPORT)),TRUE)
          COM_DEFS    += __FS_SYSDRV_ON_NAND__
        endif
      endif
    endif
  endif
endif

ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    NAND_FLASH_BOOTING_SUPPORT_PLATFORM = MT6575 MT6280 MT6290
    NFB_ONDEMAND_SUPPORT_PLATFORM = MT6575 MT6280
    ifeq ($(strip $(SMART_PHONE_CORE)),AP)
      NAND_FLASH_BOOTING_SUPPORT_PLATFORM += MT6573 MT6575 MT6577
      NFB_ONDEMAND_SUPPORT_PLATFORM += MT6573 MT6575 MT6577
    endif
    ifeq ($(filter $(strip $(PLATFORM)) ,$(NAND_FLASH_BOOTING_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef NAND_SUPPORT
      ifeq ($(strip $(NAND_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,NAND_FLASH_BOOTING)
       DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += _NAND_FLASH_BOOTING_
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ENFB)
      ifneq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) should use NAND_FLASH_BOOTING = ONDEMAND / MIXED instead of ENFB) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING = ONDEMAND) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __DEMAND_PAGING__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),MIXED)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING = MIXED) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
      COM_DEFS    += __DEMAND_PAGING__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),SINGLE)
      COM_DEFS    += __NFB_SINGLE_ROM__
    endif
  endif
endif

ifdef DEMAND_PAGING_LEVEL
  ifeq ($(strip $(DEMAND_PAGING_LEVEL)),DPV2)
    ifneq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
      $(warning ERROR: Please set NAND_FLASH_BOOTING = ONDEMAND to enable DEMAND_PAGING_LEVEL = DPV2.)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __DEMAND_PAGING_V2__
    endif
  endif
endif

ifneq ($(strip $(USB_SUPPORT)),TRUE)
  ifneq ($(filter __CHARGER_USB_DETECT_WIHT_ONE_EINT__ ,$(CUSTOM_OPTION)),)
    $(warning ERROR: Please remove __CHARGER_USB_DETECT_WIHT_ONE_EINT__ from CUSTOM_OPTION when USB_SUPPORT is not TRUE!) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(filter __USB_AND_UART_WITH_ONE_GPIO__ ,$(CUSTOM_OPTION)),)
    $(warning ERROR: Please remove __USB_AND_UART_WITH_ONE_GPIO__ from CUSTOM_OPTION when USB_SUPPORT is not TRUE!) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  USB_SUPPORT_PLATFORM = MT6280 MT6575 MT6577 MT6589
  ifeq ($(filter $(strip $(PLATFORM)) ,$(USB_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB.) 
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(USB_SUPPORT)),TRUE)
      COM_DEFS    += __USB_ENABLE__ __NVRAM_IN_USB_MS__
      ifeq ($(strip $(BOARD_VER)),MT6228_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6229_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6229_MGM_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6230_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
    endif
  endif
endif

ifdef AEC_ENABLE
  ifeq ($(strip $(AEC_ENABLE)),TRUE)
    COM_DEFS    += AEC_ENABLE
  else
    ifdef IC_TEST_TYPE
      ifneq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
        $(warning ERROR: AEC_ENABLE is a mandatory feature. Please turn on AEC_ENABLE!)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef IC_TEST_TYPE
  ifneq ($(strip $(IC_TEST_TYPE)),NONE)
    ifeq ($(findstring _SLT,$(IC_TEST_TYPE)),_SLT)
      COMPLIST     += slt
      COM_DEFS += __IC_SLT__
      COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/driver/drvtest/slt/inc/slt_trace.h
      L1_COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/driver/drvtest/slt/inc/slt_trace.h
    endif
  endif
endif

ifdef AMR_LINK_SUPPORT
  ifeq ($(strip $(AMR_LINK_SUPPORT)),TRUE)
    COM_DEFS   += __AMR_SUPPORT__
  endif
endif

ifdef DEFAULT_WORLD_MODE_ID
  COM_DEFS += DEFAULT_WORLD_MODE_ID=$(strip $(DEFAULT_WORLD_MODE_ID))
endif

COM_DEFS          += __EXT_PDP_CONTEXT_ON__
COM_DEFS          += __EXT_SECONDARY_PDP_FEASIBLE__
COM_DEFS          += __TURN_ON_EXTERNAL_SECONDARY_PDP__
COM_DEFS          += __TURN_ON_GENERAL_SECONDARY_PDP__  

ifdef IPV6_PDP_SUPPORT
  ifeq ($(strip $(IPV6_PDP_SUPPORT)),TRUE)
    COM_DEFS          += __IPV6__
    COM_DEFS          += __IPV4V6__
  endif
endif

ifdef UART3_SUPPORT
  ifeq ($(strip $(UART3_SUPPORT)),TRUE)

    COM_DEFS    += __UART3_SUPPORT__
    UART_PORT_FREE_COUNT = 1
  else
    UART_PORT_FREE_COUNT = 0
  endif
else
    UART_PORT_FREE_COUNT = 0
endif

UART_PORT_USED_COUNT = 0

ifeq ($(strip $(UART_PORT_FREE_COUNT)),1)
  ifeq ($(strip $(UART_PORT_USED_COUNT)),2)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif

ifeq ($(strip $(UART_PORT_FREE_COUNT)),0)
  ifneq ($(strip $(UART_PORT_USED_COUNT)),0)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif

ifdef ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT
  ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT,SYSTEM_DRIVE_ON_NAND)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT,SINGLE_BANK_NOR_FLASH_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __SINGLE_BANK_NOR_FLASH_SUPPORT__
    endif
  endif
endif

ifdef EDGE_SUPPORT
  ifeq ($(strip $(EDGE_SUPPORT)),TRUE)
    EDGE_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
    ifeq ($(filter $(strip $(PLATFORM)) ,$(EDGE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support EGPRS.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(R99_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,R99_SUPPORT,EDGE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS    += __EGPRS_MODE__

    ifeq ($(strip $(L1_EPSK_TX)),TRUE)
      COM_DEFS    +=  __EPSK_TX__
    endif
  else
     ifdef L1_EPSK_TX
       ifeq ($(strip $(L1_EPSK_TX)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,EDGE_SUPPORT,L1_EPSK_TX)
         DEPENDENCY_CONFLICT = TRUE
       endif
     endif
   endif
endif

ifdef R99_SUPPORT
  ifeq ($(strip $(R99_SUPPORT)),TRUE)
    COM_DEFS    +=   __R99__
    ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
      ifeq ($(strip $(L1_GPRS)),TRUE)
        COM_DEFS    +=   __TBF_EST__
      endif
    endif
  endif
endif

ifdef R4_SUPPORT
  ifeq ($(strip $(R4_SUPPORT)),TRUE)
    ifneq ($(strip $(R99_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,R99_SUPPORT,R4_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS    +=   __REL4__ __GERAN_R4__
  endif
endif

ifdef R5_SUPPORT
  ifeq ($(strip $(R5_SUPPORT)),TRUE)
    ifneq ($(strip $(R4_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,R4_SUPPORT,R5_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(USIM_SUPPORT)),TRUE)
      ifeq ($(filter ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
        $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,R5_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    COM_DEFS    +=   __REL5__ __GERAN_R5__
  endif
endif

ifdef DSPIRDBG
  ifeq ($(strip $(DSPIRDBG)),TRUE)
    COM_DEFS    += __DSPIRDBG__
  endif
endif

ifdef DSPIRDBG_SP
  ifeq ($(strip $(DSPIRDBG_SP)),TRUE)
    COM_DEFS    += __DSPIRDBG_SP__
  endif
endif

ifdef OPEN_DSP_SPEECH_SUPPORT
	ifeq ($(strip $(OPEN_DSP_SPEECH_SUPPORT)),TRUE)
		COM_DEFS += __OPEN_DSP_SPEECH_SUPPORT__
	endif
endif

ifdef DISPLAY_TYPE
  COM_DEFS    += __MMI_DISPLAY_TYPE_$(call Upper,$(strip $(DISPLAY_TYPE)))__
endif

ifdef SECURE_SUPPORT
  ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
    COM_DEFS    += __MTK_SECURE_PLATFORM__
  endif
endif

ifdef CHIP_VERSION_CHECK
  ifeq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
    COM_DEFS += __CHIP_VERSION_CHECK__
  endif
else
  $(warning ERROR: The feature CHIP_VERSION_CHECK should be defined as TRUE or FALSE)
  DEPENDENCY_CONFLICT = TRUE
endif

ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),RAW)
  ifneq ($(strip $(NOR_SUPPORT_RAW_DISK)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,SYSDRV_BACKUP_DISK_SUPPORT),non RAW,NOR_SUPPORT_RAW_DISK)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),FAT)
  ifneq ($(strip $(NANDFDM_MULTI_INSTANCE)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,SYSDRV_BACKUP_DISK_SUPPORT),non FAT,NANDFDM_MULTI_INSTANCE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DISABLE_A5_2)),TRUE)
  COM_DEFS += __DISABLE_A5_2__
endif

ifeq ($(strip $(TST_LOGACC_SUPPORT)),TRUE)
  ifneq ($(strip $(TST_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_LOGACC_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS    += __LOGACC_ENABLE__
  endif
endif

ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MASS_STORAGE_SUPPORT )
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS +=  __USB_MASS_STORAGE_ENABLE__
endif

ifeq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_COM_PORT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS +=  __USB_COM_PORT_ENABLE__
endif

ifdef USB_HS_SUPPORT
  ifeq ($(strip $(USB_HS_SUPPORT)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_HS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     else
       USB_HS_SUPPORT_PLATFORM = MT6575 MT6577 MT6280 MT6589
       ifeq ($(filter $(strip $(PLATFORM)),$(USB_HS_SUPPORT_PLATFORM)),)
         $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB_HS_SUPPORT.)
         DEPENDENCY_CONFLICT = TRUE
       else
         COM_DEFS += __USB_HS_ENABLE__
       endif
     endif
   endif
endif

ifeq ($(strip $(AMRWB_LINK_SUPPORT)),TRUE)
  AMRWB_LINK_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
  ifeq ($(filter $(strip $(PLATFORM)) ,$(AMRWB_LINK_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support AMRWB_LINK_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS  +=  __AMRWB_LINK_SUPPORT__
endif

ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    EMMC_BOOTING_SUPPORT_PLATFORM = MT6256 MT6276
    ifeq ($(filter $(strip $(PLATFORM)) ,$(EMMC_BOOTING_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support EMMC_BOOTING)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef NAND_FLASH_BOOTING
      ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        $(warning ERROR: NAND_FLASH_BOOTING and EMMC_BOOTING could not turn on simutaneously. Please turn of one.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif 
    ifeq ($(strip $(NAND_SUPPORT)),TRUE)
      $(warning ERROR: EMMC_BOOTING cannot be enabled when NAND_SUPPORT is TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      $(warning ERROR: EMMC_BOOTING cannot be enabled when SYSTEM_DRIVE_ON_NAND is TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
      $(warning ERROR: EMMC_BOOTING cannot be enabled when COMBO_MEMORY_SUPPORT is TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __EMMC_BOOTING__
    ifeq ($(strip $(EMMC_BOOTING)),ONDEMAND)
      COM_DEFS    += __DEMAND_PAGING__
    endif
    ifeq ($(strip $(EMMC_BOOTING)),MIXED)
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
      COM_DEFS    += __DEMAND_PAGING__
    endif
  endif
endif

ifdef USB_MULTIPLE_COMPORT_ENABLE
  ifeq ($(strip $(USB_MULTIPLE_COMPORT_ENABLE)),TRUE)
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MULTIPLE_COMPORT_ENABLE)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifneq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_COM_PORT_SUPPORT,USB_MULTIPLE_COMPORT_ENABLE)
        DEPENDENCY_CONFLICT = TRUE
      else
          COM_DEFS += __USB_SUPPORT_MULTIPLE_DMA_CHANNEL__
          COM_DEFS += __USB_MULTIPLE_COMPORT_SUPPORT__
          COM_DEFS += __USB_COMPOSITE_DEVICE_SUPPORT__
      endif
    endif
  endif
endif

# Customer specific factory mode detection
ifdef CUSTOMER_SPECIFIC_FACTORY_DETECTION
  ifneq ($(strip $(CUSTOMER_SPECIFIC_FACTORY_DETECTION)),NONE)
    COM_DEFS    +=  __CS_FAC_DET__
    COM_DEFS    +=  __$(strip $(CUSTOMER_SPECIFIC_FACTORY_DETECTION))__
  endif
endif

ifeq ($(strip $(KAL_RECORD_BOOTUP_LOG)),TRUE)
  COM_DEFS += __KAL_RECORD_BOOTUP_LOG__
endif

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  COM_DEFS += __DSP_FCORE4__ __ARM_MOVE_DATA__
endif

ifeq ($(strip $(USB_HIGH_SPEED_COM_PORT_SUPPORT)),TRUE)
  ifneq ($(strip $(USB_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_HIGH_SPEED_COM_PORT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_COM_PORT_SUPPORT,USB_HIGH_SPEED_COM_PORT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS +=  __USB_HIGH_SPEED_COM_PORT_ENABLE__
endif

ifdef GPRS_CLASS_10
  ifeq ($(strip $(GPRS_CLASS_10)),TRUE)
    COM_DEFS    += __GPRS_MULTISLOT_CLASS_10__
  endif
endif

ifdef EDGE_CLASS_10 
  ifeq ($(strip $(EDGE_CLASS_10 )),TRUE)
    COM_DEFS    += __EDGE_MULTISLOT_CLASS_10__
  endif
endif
# =================================================
# MD OFFLOAD COPRO Setting
# =================================================
MD_COPRO_CONFIG := FALSE

FORCE_GEN := FALSE

ifdef NAND_FLASH_BOOTING
  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    NAND_FLASH_BOOTING_IS_NONE = TRUE
  endif
else
  NAND_FLASH_BOOTING_IS_NONE = TRUE
endif

ifdef EMMC_BOOTING
  ifeq ($(strip $(EMMC_BOOTING)),NONE)
    EMMC_BOOTING_IS_NONE = TRUE
  endif
else
  EMMC_BOOTING_IS_NONE = TRUE
endif

ifndef SMART_PHONE_CORE
  SMART_PHONE_CORE = NONE
endif

ifeq ($(strip $(USB_MASS_STORAGE_CDROM_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MASS_STORAGE_CDROM_SUPPORT )
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_MASS_STORAGE_SUPPORT,USB_MASS_STORAGE_CDROM_SUPPORT )
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS +=  __USB_MASS_STORAGE_CDROM_ENABLE__
endif

MDP_VT_PREVIEW_UPSCALE_PLATFORM = MT6276 MT6256 MT6236 MT6255 MT6922
ifneq ($(filter $(strip $(PLATFORM)),$(MDP_VT_PREVIEW_UPSCALE_PLATFORM)),)
  COM_DEFS    += __MDP_VT_PREVIEW_UPSCALE_SUPPORT__
endif

ifneq ($(filter __RF_DESENSE_TEST__,$(CUSTOM_OPTION)),)
  COMPLIST     += btmt
#  CUS_REL_MTK_COMP  +=  btmt
endif

ifdef AVI_FILE_FORMAT_SUPPORT
  ifeq ($(strip $(AVI_FILE_FORMAT_SUPPORT)),TRUE)
    COM_DEFS    += __AVI_FILE_FORMAT_SUPPORT__
  endif
endif

ifdef RM_FILE_FORMAT_SUPPORT
  ifeq ($(strip $(RM_FILE_FORMAT_SUPPORT)),TRUE)
    COM_DEFS    += __RM_FILE_FORMAT_SUPPORT__
  else
    ifeq ($(strip $(COOK_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,RM_FILE_FORMAT_SUPPORT,COOK_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(RM_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,RM_FILE_FORMAT_SUPPORT,RM_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

COM_DEFS    += __EMPTY_MMI__

ifdef WAV_CODEC
  ifeq ($(strip $(WAV_CODEC)),TRUE)
    COM_DEFS    += WAV_CODEC
  endif
endif

ifdef BACKGROUND_SOUND
  ifeq ($(strip $(BACKGROUND_SOUND)),TRUE)
    COM_DEFS += BGSND_ENABLE
  endif
endif

ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
  ifdef EMMC_BOOTING
    ifneq ($(strip $(EMMC_BOOTING)),NONE)
      $(warning ERROR: when SERIAL_FLASH_SUPPORT is TRUE, please set EMMC_BOOTING = NONE.)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifdef NAND_FLASH_BOOTING
        ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
          $(warning ERROR: when SERIAL_FLASH_SUPPORT is TRUE, please set NAND_FLASH_BOOTING = NONE.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  else
    ifdef NAND_FLASH_BOOTING
      ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        $(warning ERROR: when SERIAL_FLASH_SUPPORT is TRUE, please set NAND_FLASH_BOOTING = NONE.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  COM_DEFS     += __SERIAL_FLASH_EN__
  COM_DEFS     += __SERIAL_FLASH_SUPPORT__
  COM_DEFS     += __NOR_IDLE_SWEEP__
  COMPLIST += mtd 
endif

ifeq ($(strip $(ECALL_SUPPORT)),TRUE)
  ifneq ($(strip $(R4_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,R4_SUPPORT,ECALL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __ECALL_SUPPORT__
  COM_DEFS    += __ECALL_PSAP_SUPPORT__
  ifeq ($(CORE_ROOT),pcore)
    COMPLIST    += dp_engine
  endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
endif

ifeq ($(strip $(HIF_USB_SUPPORT)),TRUE)
  ifeq ($(strip $(HIF_USB30_SUPPORT)),TRUE)
    COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/hif/inc/hif_usbdev/hif_u3dev/u3dev_trace.h
  endif
endif

ifdef 3G_VIDEO_CALL
  ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
      COM_DEFS    += __VT_MONA__
  endif
endif

COM_DEFS    += __ATCI_QUEUE_AT__

XIP_SHADOWING_ENABLE_PLATFORM = MT6280
ifneq ($(filter $(strip $(XIP_SHADOWING_ENABLE_PLATFORM)),$(strip $(PLATFORM))),)
  ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
    COM_DEFS += __XIP_SHADOWING__
  endif
endif

# *************************************************************************
# feature option from core-Option.mak
# *************************************************************************

COM_DEFS  += __SMART_PAGING_IN_IDLE__ __SMART_PAGING__

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COM_DEFS  += __MONITOR_PAGE_DURING_TRANSFER__
endif

ifeq ($(strip $(GEMINI_VERSION)),V2)
  ifdef GEMINI
    ifneq ($(strip $(GEMINI)),FALSE)
      COM_DEFS  += __GEMINI_PREEMPT_PEER_SERVICE__ __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ __SMART_PAGING__ __SMART_PAGING_IN_IDLE__
      ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
        COM_DEFS  += __MONITOR_PEER_PAGING_IN_CELL_PCH__
      endif
    endif
  endif
endif

ifneq ($(filter __SMART_PAGING_IN_IDLE__,$(COM_DEFS)),)
  ifeq ($(filter __SMART_PAGING__,$(COM_DEFS)),)
    $(warning ERROR: __SMART_PAGING_IN_IDLE__ can only be defined when __SMART_PAGING__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __MONITOR_PAGE_DURING_TRANSFER__ __GEMINI_MONITOR_PAGE_DURING_TRANSFER__,$(COM_DEFS)),)
  COM_DEFS  += __ADAPTIVE_PAGING_PERIOD_IN_UNACK_MODE__
endif

ifndef GPRS_MAX_PDP_SUPPORT
  GPRS_MAX_PDP_SUPPORT = 2
  ifdef LOW_COST_SUPPORT
    ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
      GPRS_MAX_PDP_SUPPORT = 1
    endif
  endif
endif

ifdef LTE_MAX_EPSB_SUPPORT
  COM_DEFS    += LTE_MAX_EPSB_SUPPORT=$(strip $(LTE_MAX_EPSB_SUPPORT))
endif

# define GPRS_MAX_PDP_SUPPORT = 2~7
ifdef GPRS_MAX_PDP_SUPPORT
  COM_DEFS    += GPRS_MAX_PDP_SUPPORT=$(strip $(GPRS_MAX_PDP_SUPPORT))
endif

ifdef GPRS_MAX_PDP_SUPPORT
  ifdef LTE_MAX_EPSB_SUPPORT
    MAX_EXT_PDP_CONTEXT := $(call max,$(strip $(GPRS_MAX_PDP_SUPPORT)),$(strip $(LTE_MAX_EPSB_SUPPORT)))
    COM_DEFS    += MAX_EXT_PDP_CONTEXT=$(call plus,$(strip $(MAX_EXT_PDP_CONTEXT)),3)
  endif
endif

# for backward compatible, need define a value for MAX_INT_PDP_CONTEXT
MAX_INT_PDP_CONTEXT = 0
COM_DEFS    += MAX_INT_PDP_CONTEXT=0

ifeq ($(strip $(SCC_SIB_SUPPORT)),TRUE)
  COM_DEFS    += __SCC_SIB_SUPPORT__
endif

ifeq ($(strip $(SCC_FORCE_LOG_TO_SIB)),TRUE)
  COM_DEFS    += __SCC_FORCE_LOG_TO_SIB__
endif

ifdef TAS_SUPPORT
 ifeq ($(strip $(TAS_SUPPORT)),TRUE)
    COM_DEFS    += __TAS_SUPPORT__
    ifeq ($(strip $(MTK_INTERNAL_NVRAM_VISIBLE)),TRUE)
      COM_DEFS += __TAS_INTERNAL_NVRAM_VISIBLE__
    endif
  endif
endif

ifdef DVFS_ENABLE
  ifeq ($(strip $(DVFS_ENABLE)),TRUE)
    COM_DEFS    += DVFS_ENABLE
  endif
endif

# Add option to select DSP CODEBASE
ifeq ($(strip $(MTK_MODEM_ARCH)),MT6291)
  COM_DEFS += __DSP_CODEBASE_MT6291__
endif

ifdef MTK_AUDIO_HIERARCHICAL_PARAM_SUPPORT
  ifeq ($(strip $(MTK_AUDIO_HIERARCHICAL_PARAM_SUPPORT)),TRUE)
    COM_DEFS += MTK_AUDIO_HIERARCHICAL_PARAM_SUPPORT
  endif
endif

#DRDI Capability support
ifeq ($(strip $(RF_DRDI_CAPABILITY_SUPPORT)),TRUE)
  COM_DEFS    += __RF_DRDI_CAPABILITY_SUPPORT__
endif

ifdef 2G_APC_OFF_DELAY_SUPPORT
  ifeq ($(strip $(2G_APC_OFF_DELAY_SUPPORT)),TRUE)
    COM_DEFS += __2G_APC_OFF_DELAY_SUPPORT__
  endif
endif

ifeq ($(strip $(RF_DRDI_SPECIAL_MEMORY_SUPPORT)),TRUE)
  COM_DEFS    += __RF_DRDI_SPECIAL_MEMORY_SUPPORT__
endif

ifdef NVRAM_SEC_KEY_RUNTIME_GEN
  ifeq ($(strip $(NVRAM_SEC_KEY_RUNTIME_GEN)),TRUE)
    COM_DEFS    += __NVRAM_KEY_RUNTIME_GEN__
  endif
endif

ifdef SPEECH_EVS_SUPPORT
  ifeq ($(strip $(SPEECH_EVS_SUPPORT)),TRUE)
    COM_DEFS    += __SPEECH_EVS_SUPPORT__
  endif
endif

ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
    COM_DEFS += __SV5_ENABLED__
endif

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/audio/src/v2/inc/l1sp_trc.h
else
  COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/audio/src/v1/inc/l1sp_trc.h
endif

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(filter __MAUI_BASIC__,$(COM_DEFS)),)
    ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
      COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/audio/src/v2/inc/l1audio_sph_trc.h
    else
      COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/audio/src/v1/inc/l1audio_sph_trc.h
    endif
  endif
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
    ifeq ($(filter L1S BASIC UDVT,$(strip $(TEST_LOAD_TYPE))),)
      COMP_TRACE_DEFS_MODEM   += ${CORE_ROOT}/modem/l4/dt/include/dt_trc.h
    endif
  endif
endif

# assign GEMINI_W to GEMINI_PLUS_WCDMA
ifdef GEMINI_W
  ifneq ($(strip $(GEMINI_W)),FALSE)
    COM_DEFS += __GEMINI_WCDMA__
    COM_DEFS += GEMINI_PLUS_WCDMA=$(strip $(GEMINI_W))
    ifeq ($(call gt,$(strip $(GEMINI_W)),$(strip $(GEMINI))),T)
      $(warning ERROR: GEMINI_W shall not large than GEMINI, GEMINI_W = $(GEMINI_W), GEMINI = $(GEMINI))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef LG_WG_SUPPORT
  ifneq ($(strip $(LG_WG_SUPPORT)),FALSE)
    COM_DEFS += __GEMINI_WCDMA_WORLD_PHONE__
    COM_DEFS += __OP01_FDD__
    ifndef GEMINI_W
      $(warning ERROR: LG+WG feature is only meaningful when GEMINI_W is defined)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter __GEMINI_LG_WG_MODE__,$(CUSTOM_OPTION)),)
  ifneq ($(strip $(LG_WG_SUPPORT)),TRUE)
    $(warning ERROR: Please enable LG+WG feature option "LG_WG_SUPPORT" before default turn on LG+WG feature)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef LG_WG_SUPPORT
  ifneq ($(strip $(LG_WG_SUPPORT)),FALSE)
    COM_DEFS += __GEMINI_WCDMA_WORLD_PHONE__
    COM_DEFS += __OP01_FDD__
    ifndef GEMINI_W
      $(warning ERROR: LG+WG feature is only meaningful when GEMINI_W is defined)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter __GEMINI_LG_WG_MODE__,$(CUSTOM_OPTION)),)
  ifneq ($(strip $(LG_WG_SUPPORT)),TRUE)
    $(warning ERROR: Please enable LG+WG feature option "LG_WG_SUPPORT" before default turn on LG+WG feature)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# *************************************************************************
# Component Compile Options
# *************************************************************************

ifndef FLAVOR
   COM_DEFS     += __FLAVOR_NOT_PRESENT__
endif

ifdef FLAVOR
  ifneq ($(strip $(FLAVOR)),NONE)
    COM_DEFS    += __FLAVOR_$(strip $(FLAVOR))__
  else
    COM_DEFS    += __FLAVOR_NOT_PRESENT__
  endif
endif

ifeq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
  ifneq ($(strip $(KAL_DEBUG_LEVEL)), RELEASE_KAL)
    $(warning ERROR: Please set KAL_DEBUG_LEVEL=RELEASE_KAL when  IC_TEST_TYPE = IC_BURNIN_TEST ) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef KAL_TRACE_OUTPUT
  ifeq ($(strip $(KAL_TRACE_OUTPUT)),NONE)
    COM_DEFS += MODULE_TRACE_OFF
  endif
  ifeq ($(strip $(KAL_TRACE_OUTPUT)),CUST_PARTIAL)
    COM_DEFS += MODULE_TRACE_OFF
  endif
endif

ifdef KAL_DEBUG_LEVEL
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),RICH_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF2 DEBUG_BUF3 DEBUG_ITC DEBUG_SWLA DEBUG_TIMER DEBUG_TIMER2
     DEP_DEBUG_COMPILE_OPTION =DEBUG_KAL DEBUG_BUF2 DEBUG_BUF3 DEBUG_ITC DEBUG_TIMER DEBUG_TIMER2
     ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),NORMAL_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF2 DEBUG_ITC DEBUG_TIMER
     DEP_DEBUG_COMPILE_OPTION =DEBUG_KAL DEBUG_BUF2 DEBUG_ITC DEBUG_TIMER
     ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),SLIM_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF1
    DEP_DEBUG_COMPILE_OPTION = DEBUG_KAL DEBUG_BUF1
    ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
  # dependency rule for KAL,BUFFER & ITC debug compile options
  ifneq ($(strip $(ENABLED_DEBUG_COMPILE_OPTION)),)
    ifneq ($(strip $(ENABLED_DEBUG_COMPILE_OPTION)),$(sort $(strip $(DEP_DEBUG_COMPILE_OPTION))))
      DISABLED_DEBUG_COMPILE_OPTION = $(filter-out $(strip $(ENABLED_DEBUG_COMPILE_OPTION)),$(strip $(DEP_DEBUG_COMPILE_OPTION)))
      $(warning ERROR: PLEASE turn on $(DISABLED_DEBUG_COMPILE_OPTION) or turn off $(ENABLED_DEBUG_COMPILE_OPTION))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  # end
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),RELEASE_KAL)
    COM_DEFS += RELEASE_KAL
    DEP_DEBUG_COMPILE_OPTION =
    ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
endif

COM_DEFS    += __BLIND_HANDOVER__
COM_DEFS    +=  IDLE_TASK _DEBUG MTK_KAL  __MTK_TARGET__
COM_DEFS    +=  SME_NOT_PRESENT SME_READER_NOT_PRESENT STDC_HEADERS TARGET_BUILD
COM_DEFS    += DEBUG_LEVEL=0
COM_DEFS    += __MSLT__
COM_DEFS += __OPTR_NONE__

ifdef DEMO_PROJECT
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    COM_DEFS   += MTK_INTERNAL_MMI_FEATURES
    COM_DEFS   += __MTK_INTERNAL__  
  endif
endif

ifdef RSAT_SUPPORT
  ifeq ($(strip $(RSAT_SUPPORT)),MODEM_WITH_RSAT)
      COM_DEFS    += __RSAT__
  endif
  ifeq ($(strip $(RSAT_SUPPORT)),MMI_WITH_RSAT)
    COM_DEFS    += __RSAT__
  endif
endif

ifdef UL1D_COSIM
  ifeq ($(strip $(UL1D_COSIM)),TRUE)
    ifeq ($(strip $(UL1D_LOOPBACK)),0)
      $(call DEP_ERR_SETA_OR_OFFB,UL1D_LOOPBACK,non 0,UL1D_COSIM)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

# *************************************************************************
# Component trace definition header files
# *************************************************************************
# -----------------------------
# Common trace
# -----------------------------

#
# Check the dependency of each options
#
# WIFI_BB_MODULE Options
COM_DEFS_FOR_NONE         = WIFI_BB_NONE

# WIFI_RF_MODULE Options
COM_DEFS_FOR_NONE        = WIFI_RF_NONE

#ifdef WIFI_SUPPORT
#  ifeq ($(strip $(WIFI_SUPPORT)),NONE)
     COM_DEFS   +=  $(COM_DEFS_FOR_NONE)
#  endif
#endif

ifdef 3G_VIDEO_CALL
  ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COMPLIST        += 3g324m
      COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/3g324m/appl/inc/vt_trc.h
      COM_DEFS   += __MEDIA_VT__ __VIDEO_CALL_SUPPORT__
    endif
  endif
endif

ifdef SP_VIDEO_CALL_SUPPORT
  ifeq ($(strip $(SP_VIDEO_CALL_SUPPORT)),TRUE)
    ifdef 3G_VIDEO_CALL
      ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
        $(warning ERROR: 3G_VIDEO_CALL, SP_VIDEO_CALL_SUPPORT can not enable at the same time)
      endif
    endif
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      ifneq (${CORE_ROOT},l1core)
        COMPLIST        += 3g324m_tvt
        COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/middleware/3g324m/tvt/inc/TVT_trc.h
        COM_DEFS   += __VT_TRANSPORT_SUPPORT__ __VIDEO_CALL_SUPPORT__
      endif
    endif
  endif
endif

ifdef UUS_SUPPORT
  ifeq ($(strip $(UUS_SUPPORT)),TRUE)
     COM_DEFS    += __UUS_SUPPORT__
  endif   
endif

ifdef EMLPP_SUPPORT
  ifeq ($(strip $(EMLPP_SUPPORT)),TRUE)
     COM_DEFS    += __EMLPP_SUPPORT__
  endif   
endif

ifeq ($(strip $(MTK_DSP_DEBUG)),TRUE)
  COM_DEFS    += MTK_DSP_DEBUG
endif

ifeq ($(strip $(FAX_SUPPORT)),TRUE)
  ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
    $(warning ERROR: FAX_SUPPORT cannot be turned on in $(strip $(TEST_LOAD_TYPE)) project.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(FAX_SUPPORT)),TRUE)
  ifeq ($(strip $(CSD_SUPPORT)),NONE)
    $(warning ERROR: Please turn off FAX_SUPPORT when CSD_SUPPORT = NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef CSD_SUPPORT
  ifneq ($(strip $(CSD_SUPPORT)),NONE)
    ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
      $(warning ERROR: Please turn off CSD_SUPPORT in $(strip $(TEST_LOAD_TYPE)) project.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    # Support CSD
    COM_DEFS    += CSD_SUPPORT 
    ifeq ($(strip $(CSD_SUPPORT)),T_NT)
      COM_DEFS    += __CSD_NT__ __CSD_T__
    else
      ifeq ($(strip $(CSD_SUPPORT)),NT_ONLY)
        COM_DEFS    += __CSD_NT__ 
      else
        $(warning ERROR: CSD_SUPPORT setting is wrong) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += __CSD_FAX__
    endif
  else
    # FAX only, Not support CSD
    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += CSD_SUPPORT __CSD_FAX__
    endif
  endif
else
  # FAX only, Not support CSD
  ifeq ($(strip $(FAX_SUPPORT)),TRUE)
    COM_DEFS    += CSD_SUPPORT __CSD_FAX__
  endif
endif

ifeq ($(strip $(FAST_UART)),TRUE)
  COM_DEFS    += __FAST_UART__
endif

ifdef BOOT_FAT_RESET
  ifeq ($(strip $(BOOT_FAT_RESET)),TRUE)
    COM_DEFS    += __BOOT_FAT_RESET__
  endif
endif

#ifdef APP_STORAGE_IN_SYS_DRV
#  ifeq ($(strip $(APP_STORAGE_IN_SYS_DRV)),FALSE)
#    ifdef MMS_SUPPORT
      COM_DEFS    += MMS_IN_LARGE_STORAGE
#    endif
#    ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
#      COM_DEFS   += IMPS_IN_LARGE_STORAGE
#    endif
#  else
#    COM_DEFS    += APP_STORAGE_IN_SYS_DRV
#  endif
#endif

ifdef MSDC_CARD_SUPPORT_TYPE
  ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
    MSDC_SUPPORT_PLATFORM = MT6280 MT6290
    ifeq ($(filter $(strip $(PLATFORM)) ,$(MSDC_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support MSDC_CARD_SUPPORT_TYPE) 
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __FS_CARD_SUPPORT__
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_SD_MMC)
        COM_DEFS += __MSDC_SD_MMC__
      endif
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MS)
        COM_DEFS += __MSDC_MS__
      endif
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MSPRO)
        COM_DEFS += __MSDC_MSPRO__
      endif
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_SD_SDIO)
        COM_DEFS += __MSDC_SD_MMC__ __MSDC_SD_SDIO__
      endif
    endif
  endif
endif

ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
  COM_DEFS      += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
else
  ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
    COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
  endif
endif

ifndef FS_SORT_MAX_ENTRY
  FS_SORT_MAX_ENTRY = 256
endif

ifdef FS_SORT_MAX_ENTRY
  FS_SORT_MAX_ENTRY_PLATFORM =  MT6280
  ifneq ($(filter $(strip $(PLATFORM)),$(FS_SORT_MAX_ENTRY_PLATFORM)),)
    ifeq ($(call gt,$(strip $(FS_SORT_MAX_ENTRY)),20000),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be larger than 20000)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call lt,$(strip $(FS_SORT_MAX_ENTRY)),64),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be less than 64)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifeq ($(call gt,$(strip $(FS_SORT_MAX_ENTRY)),256),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be larger than 256)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call lt,$(strip $(FS_SORT_MAX_ENTRY)),64),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be less than 64)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef FS_OPEN_HINT_SUPPORT
  ifeq ($(strip $(FS_OPEN_HINT_SUPPORT)),TRUE)
     COM_DEFS   += __FS_OPEN_HINT__
  endif
endif

ifdef FS_DEDICATED_BUFFER
  ifeq ($(strip $(FS_DEDICATED_BUFFER)),TRUE)
     COM_DEFS   += __FS_DEDICATED_BUFFER__  
  endif
endif

ifdef TST_SUPPORT
  ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
    ifeq ($(strip $(TST_SUPPORT)),TRUE)
      $(warning ERROR: TST_SUPPORT should be FALSE in BASIC project)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/service/fs/common/include/fs_trc.h

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      ifeq ($(CORE_ROOT),pcore)
        COMPLIST          += cmux
      endif
      COM_DEFS     += __CMUX_SUPPORT__
      COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/cmux/include/cmux_trc.h
    endif
  endif
endif

ifdef DMA_UART_VIRTUAL_FIFO
  VFIFO_NOT_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
  ifneq ($(filter $(strip $(PLATFORM)),$(VFIFO_NOT_SUPPORT_PLATFORM)),)
    ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) dose NOT support DMA_UART_VIRTUAL_FIFO.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      ifeq ($(filter MT6256 MT6276 MT6573 MT6575 MT6577,$(strip $(PLATFORM))),)
        $(warning ERROR: DMA_UART_VIRTUAL_FIFO is a mandatory feature on PLATFORM $(strip $(PLATFORM)))
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
    COM_DEFS    += __DMA_UART_VIRTUAL_FIFO__
  endif
endif

ifndef PHB_SIM_ENTRY
  PHB_SIM_ENTRY = 250
endif

ifdef PHB_SIM_ENTRY
  COM_DEFS    += MAX_PHB_SIM_ENTRY=$(strip $(PHB_SIM_ENTRY))
endif

ifndef PHB_PHONE_ENTRY
  PHB_PHONE_ENTRY = 200
endif

ifdef PHB_PHONE_ENTRY
  COM_DEFS    += MAX_PHB_PHONE_ENTRY=$(strip $(PHB_PHONE_ENTRY))
endif

ifndef PHB_LN_ENTRY
  PHB_LN_ENTRY = 20
endif

ifdef PHB_LN_ENTRY
  COM_DEFS    += MAX_PHB_LN_ENTRY=$(strip $(PHB_LN_ENTRY))
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS    +=  LOW_COST_SUPPORT
    COM_DEFS    +=  __SAT_DISABLE_ICON_SUPPORT__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)),COMMON)
    COM_DEFS    +=  __LOW_COST_SUPPORT_COMMON__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)),ULC)
    COM_DEFS    +=  __LOW_COST_SUPPORT_COMMON__ __LOW_COST_SUPPORT_ULC__
  endif
endif

ifndef MAX_MIDI_FILE_SIZE
  MAX_MIDI_FILE_SIZE = 2097152
endif

ifdef EMS_SUPPORT
  ifeq ($(strip $(EMS_SUPPORT)),EMS_50)
    COM_DEFS    +=  __EMS_REL5__
  endif
  ifeq ($(strip $(EMS_SUPPORT)),EMS_40)
    # do nothing
  endif
  ifeq ($(strip $(EMS_SUPPORT)),EMS_SLIM)
    COM_DEFS    +=  __SLIM_EMS__
  endif
  ifeq ($(strip $(EMS_SUPPORT)),EMS_ULC_SLIM)
    COM_DEFS    +=  __SLIM_EMS__ __ULC_SLIM_EMS__
  endif
endif

MULTI_LNA_MODE_CALIBRATION_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
ifneq ($(filter $(MULTI_LNA_MODE_CALIBRATION_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  COM_DEFS    +=  __MULTI_LNA_MODE_CALIBRATION_SUPPORT__
endif

ifeq ($(strip $(2G_RF_CUSTOM_TOOL_SUPPORT)),TRUE)
  COM_DEFS    += __2G_RF_CUSTOM_TOOL_SUPPORT__
endif

ifeq ($(strip $(USIM_SUPPORT)),TRUE)
  COM_DEFS    +=   __USIM_SUPPORT__ __EF_NETPAR_SUPPORT__
  COM_DEFS    +=   __PHB_USIM_SUPPORT__
endif

ifndef SUB_LCD_SIZE
  SUB_LCD_SIZE = NONE
endif

ifdef SUB_LCD_SIZE
  COM_DEFS += __MMI_SUBLCD_$(call Upper,$(strip $(SUB_LCD_SIZE)))__
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
     COM_DEFS    +=  __DT_SUPPORT__
     COMPLIST    +=  dt
  endif
endif

ifdef L1_EXTERNAL_LNA_SUPPORT
  ifeq ($(strip $(L1_EXTERNAL_LNA_SUPPORT)),TRUE)
     COM_DEFS += __L1_EXTERNAL_LNA_SUPPORT__
  endif
endif

ifdef USB_IN_NORMAL_MODE_SUPPORT
  ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
    ifeq ($(strip $(USB_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_IN_NORMAL_MODE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __USB_IN_NORMAL_MODE__
        COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
    endif
  endif
endif

ifeq ($(filter MT6205B MT6208 MT6218B MT6217,$(strip $(PLATFORM))),)
  COM_DEFS +=  __USIM_DRV__
endif

ifeq ($(strip $(DHL_MONITOR_MODE_SUPPORT)),TRUE)
  COM_DEFS     += __DHL_MONITOR_MODE_SUPPORT__
endif

COM_DEFS    += WAP_NOT_PRESENT
COM_DEFS    += WPS_NOT_PRESENT

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COM_DEFS    += __MANUAL_MODE_NW_SEL__ 
endif

ifdef CUST_PARA_SUPPORT
  ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
    ifneq ($(strip $(SECURE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_SUPPORT,CUST_PARA_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __CUST_PARA_SUPPORT__
  endif
endif

ifdef OTP_SUPPORT
  ifeq ($(strip $(OTP_SUPPORT)),TRUE)
    COM_DEFS    += __SECURITY_OTP__
    COM_DEFS    += __NVRAM_OTP__
  endif
endif

ifndef DLT_ALWAYS_LOAD_BUFFER_SIZE
  DLT_ALWAYS_LOAD_BUFFER_SIZE = 0
endif

ifdef DLT_ALWAYS_LOAD_BUFFER_SIZE
  COM_DEFS    += __DLT_ALWAYS_LOAD_BUFFER_SIZE__=$(strip $(DLT_ALWAYS_LOAD_BUFFER_SIZE))
endif

ifndef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
  DLT_LOAD_ON_DEMAND_BUFFER_SIZE = 0
endif

ifdef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
  COM_DEFS    += __DLT_LOAD_ON_DEMAND_BUFFER_SIZE__=$(strip $(DLT_LOAD_ON_DEMAND_BUFFER_SIZE))
endif

ifneq ($(strip $(OPTR_CODE)),OP12)
  COM_DEFS    += __IP_NUMBER__
endif

ARM9_PLATFORM = MT6238 MT6239 MT6235B MT6236 MT6236B MT6268A MT6270A MT6921 MT6255 MT6922
ARM11_PLATFORM = MT6256 MT6276 MT6573 MT6575 MT6577
CR4_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
CR4_WITH_COPRO_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
ifdef PLATFORM
  ifeq ($(strip $(PLATFORM)),MT6280)
    COM_DEFS    += __CR4__ __DYNAMIC_SWITCH_CACHEABILITY__ __IS_NAS_ITCM_DTCM__
  endif
  ifeq ($(strip $(PLATFORM)),MT6575)
    COM_DEFS    += __ARM11_MMU__ __ARM1176__ __DYNAMIC_SWITCH_CACHEABILITY__ __UNALIGNED_ACCESS_SUPPORT__
  endif
  ifeq ($(strip $(PLATFORM)),MT6577)
    COM_DEFS    += __ARM11_MMU__ __ARM1176__ __DYNAMIC_SWITCH_CACHEABILITY__ __UNALIGNED_ACCESS_SUPPORT__
  endif
  ifeq ($(strip $(PLATFORM)),MT6589)
     ifeq ($(strip $(MDSYS)),MD1)
       COM_DEFS    += __CR4__ __DYNAMIC_SWITCH_CACHEABILITY__ __IS_NAS_ITCM_DTCM__
     endif
     ifeq ($(strip $(MDSYS)),MD2)
       COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
     endif
  endif
  ifneq ($(filter $(strip $(PLATFORM)), $(strip $(CR4_WITH_COPRO_PLATFORM))),)
    COM_DEFS    += __CR4__ __DYNAMIC_SWITCH_CACHEABILITY__ __IS_NAS_ITCM_DTCM__ ARMV6_INST_ENABLE
  endif
endif

ifeq ($(strip $(CLIB_TIME_SUPPORT)), TRUE)
  COM_DEFS += __SUPPORT_CLIB_TIME__
  ifneq ($(strip $(CCCI_DEV_SUPPORT)), TRUE)
    $(warning ERROR: please turn on CCCI_DEV_SUPPORT and HIF_CCCI_SUPPORT, when CLIB_TIME_SUPPORT is set.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(HIF_CCCI_SUPPORT)), TRUE)
    $(warning ERROR: please turn on CCCI_DEV_SUPPORT and HIF_CCCI_SUPPORT, when CLIB_TIME_SUPPORT is set.)
    DEPENDENCY_CONFLICT = TRUE
  endif	
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    COM_DEFS +=  __GSM_RAT__ 
  endif
endif

ifeq ($(strip $(PLATFORM)),MT6575)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6577)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6280)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__ __ECC_8_BIT_SUPPORT__ __NAND_MDL_APPEND__
endif

ifdef NOR_SUPPORT_RAW_DISK
  ifeq ($(strip $(NOR_SUPPORT_RAW_DISK)),TRUE)
    COM_DEFS += __NOR_SUPPORT_RAW_DISK__
    ifdef SYSDRV_BACKUP_DISK_SUPPORT
      ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),RAW)
        COM_DEFS += __SYSDRV_BACKUP_DISK__
        COM_DEFS += __SYSDRV_BACKUP_DISK_RAW__
      endif
    endif
    ifdef LGE_SECURITY
      ifeq ($(strip $(LGE_SECURITY)),TRUE)
        COM_DEFS += __CUSTOMER_TC01_DISK__
      endif
    endif
  endif
endif

SAIC_NOT_SUPPORT_FLATFORM = MT6205 MT6205B MT6208 MT6217 MT6218 MT6218B MT6219 MT6225 MT6226 MT6226D MT6226M MT6227 MT6227D MT6228 MT6229 MT6230 
ifeq ($(filter $(strip $(PLATFORM)),$(SAIC_NOT_SUPPORT_FLATFORM)),)
  COM_DEFS    +=    __SAIC__
endif

VAMOS_NOT_SUPPORT_FLATFORM = MT6575 MT6577
VAMOS_CAP_DEFAULT_NOT_SUPPORT_FLATFORM = MT6280
ifeq ($(strip $(VAMOS_SUPPORT)),TRUE)
  ifneq ($(filter $(strip $(PLATFORM)),$(VAMOS_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support VAMOS_SUPPORT.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS  += __VAMOS_1__ __VAMOS_2__
  ifeq ($(strip $(R7R8_FULL_SET_SUPPORT)),TRUE)
    COM_DEFS    +=   __CUSTOMIZE_VAMOS__
  else
    ifneq ($(strip $(OP01_2G_ONLY)),TRUE) 
      ifeq ($(filter $(strip $(PLATFORM)),$(VAMOS_CAP_DEFAULT_NOT_SUPPORT_FLATFORM)),)
        COM_DEFS    +=   __CUSTOMIZE_VAMOS__
      endif
    endif
  endif
endif

ifeq ($(strip $(TST_WRITE_TO_FILE)),TRUE)
  ifeq ($(strip $(TST_SUPPORT)),TRUE)
    COM_DEFS    += __TST_WRITE_TO_FILE__
  endif
endif

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  ifdef LOW_COST_SUPPORT
    ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
      COM_DEFS += __GIS_INTERNAL__
    endif
  else
    COM_DEFS += __GIS_INTERNAL__
  endif
endif


ifdef RFC2507_SUPPORT
  ifeq ($(strip $(RFC2507_SUPPORT)),TRUE)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      ifeq ($(CORE_ROOT),pcore)
        COMPLIST          += rfc2507
      endif
      COMP_TRACE_DEFS_MODEM   += $(strip $(UAS_FDD_FOLDER))/ul2/rfc2507/include/rfc2507_lib_trc.h \
                                 $(strip $(UAS_TDD_FOLDER))/ul2/rfc2507/include/rfc2507_lib_trc.h
      COM_DEFS          += __RFC2507_SUPPORT__
    endif
  endif
endif


#ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  ifeq ($(strip $(USB_SUPPORT)),TRUE)
    ifneq ($(strip $(MODEM_CARD)),NONE)
      COM_DEFS += __USB_MODEM_CARD_SUPPORT__
      COM_DEFS += __USB_MASS_STORAGE_CDROM_ENABLE__
      ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
        ifneq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
          $(warning ERROR: please turn on USB_IN_NORMAL_MODE_SUPPORT , when USB_MASS_STORAGE_SUPPORT is set to TRUE .)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
  ifneq ($(strip $(RSAT_SUPPORT)),MODEM_WITH_RSAT)
    $(call DEP_ERR_SETA_OR_OFFB,RSAT_SUPPORT,MODEM_WITH_RSAT,EMPTY_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
#endif

ifneq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
  ifeq ($(strip $(LPP_SUPPORT)),CONTROL_PLANE)
    ifeq ($(strip $(LTE_OTDOA_SUPPORT)),TRUE)
      COM_DEFS += __LTE_OTDOA_SUPPORT__
    endif
  endif
endif
ifeq ($(strip $(LTE_OTDOA_SUPPORT)),TRUE)
  ifeq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
    $(warning ERROR: please turn on EUTRAN_MODE_SUPPORT and LPP_SUPPORT, when LTE_OTDOA_SUPPORT is set to TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(LPP_SUPPORT)),NONE)
        $(warning ERROR: please turn on EUTRAN_MODE_SUPPORT and LPP_SUPPORT, when LTE_OTDOA_SUPPORT is set to TRUE.)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef NDIS_SUPPORT
  ifeq ($(strip $(NDIS_SUPPORT)),TRUE)
    $(warning ERROR: Please set new value NONE/NDIS/UPS for NDIS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif  
  ifeq ($(strip $(NDIS_SUPPORT)),FALSE)
    $(warning ERROR: Please set new value NONE/NDIS/UPS for NDIS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(NDIS_SUPPORT)),NDIS)
    ifneq ($(strip $(CMUX_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CMUX_SUPPORT,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __NDIS_SUPPORT__
  endif
  ifeq ($(strip $(NDIS_SUPPORT)),UPS)
    ifneq ($(strip $(CMUX_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CMUX_SUPPORT,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COM_DEFS    += __NDIS_SUPPORT__ __UPS_SUPPORT__
      COMPLIST    += ups
      COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/middleware/ups/ups/include/ups_trc.h
    endif
  endif

endif

ifdef CCBS_SUPPORT
  ifeq ($(strip $(CCBS_SUPPORT)),TRUE)
     COM_DEFS    += __CCBS_SUPPORT__
  endif
endif

ifdef CNAP_SUPPORT
  ifeq ($(strip $(CNAP_SUPPORT)),TRUE)
     COM_DEFS    += __CNAP_SUPPORT__
  endif
endif

ifdef CHANNEL_LOCK
  ifeq ($(strip $(CHANNEL_LOCK)),TRUE)
    COM_DEFS    += __CHANNEL_LOCK__
  endif
endif

ifdef SWITCHABLE_FEATURE_2ND
  ifneq ($(strip $(SWITCHABLE_FEATURE_2ND)),NONE)
    ifndef SWITCHABLE_FEATURE
      $(call DEP_ERR_ONA_OR_OFFB,SWITCHABLE_FEATURE,SWITCHABLE_FEATURE_2ND)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SWITCHABLE_FEATURE,SWITCHABLE_FEATURE_2ND)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef MODEM_3G_LOGGING
  ifeq ($(strip $(MODEM_3G_LOGGING)),TRUE)
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,MODEM_3G_LOGGING)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __MODEM_3G_LOGGING__
    COM_DEFS    += __USB_LOGGING__
  endif
endif

ifdef EXT_MODEM_SUPPORT
  ifeq ($(strip $(EXT_MODEM_SUPPORT)), TRUE)
    COMPLIST          += ext_modem
    COMP_TRACE_DEFS_MODEM   += ${CORE_ROOT}/modem/ext_modem/include/ext_modem_trc.h
    COM_DEFS += __EXT_MODEM__
  endif
endif

ifndef SMS_PHONE_ENTRY
  $(warning ERROR: Please define SMS_PHONE_ENTRY in project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifndef SMS_TOTAL_ENTRY
  $(warning ERROR: Please define SMS_TOTAL_ENTRY in project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef SMS_PHONE_ENTRY
  COM_DEFS    += SMS_PHONE_ENTRY=$(strip $(SMS_PHONE_ENTRY))
endif

ifdef SMS_TOTAL_ENTRY
  COM_DEFS    += SMS_TOTAL_ENTRY=$(strip $(SMS_TOTAL_ENTRY))
endif

ifdef SECURE_PORT_SUPPORT
  ifeq ($(strip $(SECURE_PORT_SUPPORT)),TRUE)
      COM_DEFS    += __SECURE_PORT_SUPPORT__
  endif
endif

ifdef IPSEC_SUPPORT
  ifneq ($(strip $(IPSEC_SUPPORT)),FALSE)
    COM_DEFS    += __IPSEC__
    COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/service/security/ike/include/ike_trc.h
    COMMINCDIRS     +=  ${CORE_ROOT}/interface/security
    COMPLIST    += ipsec netkey ike
  endif
endif

ifndef VENDOR
  VENDOR = NONE
endif

ifdef VENDOR
  ifneq ($(strip $(VENDOR)),NONE)
    COM_DEFS +=  DEVAPP_RESOURCE
  endif
  COM_DEFS += VENDOR_$(strip $(VENDOR))
endif

ifdef PRODUCTION_RELEASE
  ifeq ($(strip $(PRODUCTION_RELEASE)),FALSE)
    COM_DEFS += L1A_DEVELOP_DEBUG
    ifeq ($(strip $(VENDOR)),NONE)
      ifneq ($(strip $(DEMO_PROJECT)),TRUE)
        ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_ONB,PRODUCTION_RELEASE,DEMO_PROJECT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    
      ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
        ifeq ($(filter REL_CR_OBJ_JAL_SRC% REL_CR_MMI_VOGINS% REL_CR_INET_MMI_ROLLTECH%,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_ONB,PRODUCTION_RELEASE,MTK_SUBSIDIARY)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  else
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,DEMO_PROJECT,PRODUCTION_RELEASE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO)), TRUE)
    COM_DEFS += __GPRS_DIALUP_ESCAPE_ATO_SUPPORT__
  endif
endif

ifdef GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND 
  ifeq ($(strip $(GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND)), TRUE)
    COM_DEFS += __PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND__
  endif
endif

ifdef MULTIPLE_PPP_DIALUP_SUPPORT
  ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
    ifeq ($(call gt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),$(strip $(GPRS_MAX_PDP_SUPPORT))),T)
      $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be larger than GPRS_MAX_PDP_SUPPORT value ($(GPRS_MAX_PDP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call gt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),3),T)
      $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be larger than 3)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call lt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),2),T)
      $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be less than 2)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS          += __MULTIPLE_PPP_DIALUP_SUPPORT__
    COM_DEFS          += __MAX_NUM_OF_PPP_DIALUP_SUPPORT__=$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT))
  endif
endif

ifdef LTE_BAND_EXTENSION_SUPPORT
  ifeq ($(strip $(LTE_BAND_EXTENSION_SUPPORT)), TRUE)
    COM_DEFS += __BAND_EXTENSION_SUPPORT__
  endif
endif

ifdef 2G_ALTERNATIVE_RX_PATH_SUPPORT
  ifeq ($(strip $(2G_ALTERNATIVE_RX_PATH_SUPPORT)),TRUE)
    COM_DEFS += __2G_ALTERNATIVE_RX_PATH_SUPPORT__
  endif
endif

ifneq ($(strip $(MODEM_CARD)),NONE)
  COM_DEFS += __MODEM_CARD__
  COM_DEFS += __DISABLE_MODEM_AUTO_POWER_OFF__
  COM_DEFS += __MODEM_AUTO_STARTUP_TO_FLIGHT_MODE__
  COM_DEFS += __CSCB_ALL_LANGUAGE_ON__
  COM_DEFS += __AT_LINUX_DATA_PORT__
  COM_DEFS += __MOBILE_BROADBAND_PROVISION_CONTEXT__
  COM_DEFS += __CSMSS_EXPLICIT_SS_OPERATION__
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    ifeq ($(filter $(ORIGINAL_FLAVOR),L1S_CA7 L1S_CA7_L1DISABLE),)
      COM_DEFS += __SPEECH_OVER_USB__
    endif
  endif
  ifeq ($(strip $(MODEM_CARD)),CS_CALL_DISABLE)
    COM_DEFS += __DISABLE_CSCALL__
  endif
  COM_DEFS += __SAT_AP_NOT_SUPPORT__
endif

ifdef MULTIPLE_NDIS_SUPPORT
  ifeq ($(strip $(MULTIPLE_NDIS_SUPPORT)),TRUE)
     ifndef NDIS_SUPPORT
       $(call DEP_ERR_ONA_OR_OFFB,NDIS_SUPPORT,MULTIPLE_NDIS_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(NDIS_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,NDIS_SUPPORT,MULTIPLE_NDIS_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
       $(call DEP_ERR_OFFA_OR_OFFB,MULTIPLE_NDIS_SUPPORT,MULTIPLE_PPP_DIALUP_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),$(strip $(GPRS_MAX_PDP_SUPPORT))),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be larger than GPRS_MAX_PDP_SUPPORT value ($(GPRS_MAX_PDP_SUPPORT)))
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),6),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be larger than 6)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call lt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),2),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be less than 2)
       DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS          += __MULTIPLE_NDIS_SUPPORT__
     COM_DEFS          += __MAX_NUM_OF_NDIS_SUPPORT__=$(strip $(MAX_NUM_OF_NDIS_SUPPORT))
  endif
endif

ifndef NVRAM_NOT_PRESENT
  ifdef NVRAM_PSEUDO_MERGE
    ifeq ($(strip $(NVRAM_PSEUDO_MERGE)),ON)
      COM_DEFS +=  __NVRAM_PSEUDO_MERGE__
    endif
  endif
endif

ifeq ($(strip $(SMS_R8_NATION_LANGUAGE)),TRUE)
  COM_DEFS += __SMS_R8_NATION_LANGUAGE__
endif

ifdef SMS_R8_TABLE_MECHANISM
  COM_DEFS += __$(strip $(SMS_R8_TABLE_MECHANISM))__
else
  COM_DEFS += __SMS_R8_DEFAULT__
endif

ifndef MELODY_BUFFER_LEN
  ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
     MELODY_BUFFER_LEN = 512
  else
    ifeq ($(strip $(MED_PROFILE)),MED_LOW)
      MELODY_BUFFER_LEN = 1300
    else
      MELODY_BUFFER_LEN = 102400
    endif
  endif
endif 

ifdef OPTR_CODE
  ifeq ($(strip $(OPTR_CODE)),OP12)
    MELODY_BUFFER_LEN = 307200
  endif
endif

ifdef MELODY_BUFFER_LEN
  COM_DEFS += MAX_MELODY_BUF_LEN=$(strip $(MELODY_BUFFER_LEN))
endif

ifdef GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP)),TRUE)
    COM_DEFS += __PPP_SPEED_UP_IPV4_GPRS_DIALUP__
  endif
endif

COM_DEFS += __HO_IMPROVE__

ifdef DRV_DEBUG_MEMORY_TRACE_SUPPORT
  ifeq ($(strip $(DRV_DEBUG_MEMORY_TRACE_SUPPORT)),TRUE)
    COM_DEFS    +=  __DRV_DBG_MEMORY_TRACE_SUPPORT__
  endif
endif

ifdef SMART_PHONE_CORE
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    COM_DEFS += __AT_EPBW_SUPPORT__
  endif
endif

ifndef PHB_NAME_LENGTH
    PHB_NAME_LENGTH = 40
endif

ifdef PHB_NAME_LENGTH
  ifeq ($(call gt,$(strip $(PHB_NAME_LENGTH)),80),T)
    $(warning ERROR: PHB_NAME_LENGTH value should not be larger than 80)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += MAX_PHB_NAME_LENGTH=$(strip $(PHB_NAME_LENGTH))
  COM_DEFS    += MAX_PS_NAME_SIZE=$(call plus,$(PHB_NAME_LENGTH),2)
endif  

ifdef UART_CHARGER_THE_SAME_INTERFACE
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART1)
    COM_DEFS    += __UART1_WITH_CHARGER__
  endif
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART2)
    COM_DEFS    += __UART2_WITH_CHARGER__
  endif
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART3)
    COM_DEFS    += __UART3_WITH_CHARGER__
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS    +=  __SLIM_NWK_PROFILE__
  endif
endif

ifdef PPP_TYPE_PDP_DIALUP_SUPPORT
  ifeq ($(strip $(PPP_TYPE_PDP_DIALUP_SUPPORT)),TRUE)
    COM_DEFS  +=  __PPP_TYPE_PDP_DIALUP_SUPPORT__
  endif
endif

#############################################################################################
# Add PPP_SUPPORT feature rule here
# firstly, set/reset PS_DIALUP and TCPIP_OVER_CSD sub_feature_option
# then check rule of each option
# last modify COMPLIST, if PPP_SUPPORT != NONE, then compile PPP
# this part should after PPP_DEPENDENCE_OPTION define to check valid or not
# if not define PPP_SUPPORT, we should keep option as what it is before wrapping action
#############################################################################################

ifdef PPP_SUPPORT
  ifeq ($(strip $(PPP_SUPPORT)),CSD_PPP_SUPPORT)
    PS_DIALUP = FALSE
    TCPIP_OVER_CSD = TRUE
  endif
  ifeq ($(strip $(PPP_SUPPORT)),GPRS_PPP_SUPPORT)
    PS_DIALUP = TRUE
    TCPIP_OVER_CSD = FALSE
  endif
  ifeq ($(strip $(PPP_SUPPORT)),FULL_SUPPORT)
    PS_DIALUP = TRUE
    TCPIP_OVER_CSD = TRUE
  endif
  
  ifeq ($(strip $(PS_DIALUP)),TRUE)
#    COM_DEFS += __PS_DIALUP__
  else
    PS_DIALUP_DEPENDENCE_OPTION = __MULTIPLE_PPP_DIALUP_SUPPORT__
    ifneq ($(filter $(PS_DIALUP_DEPENDENCE_OPTION),$(COM_DEFS)),)
      $(call DEP_ERR_SETA_OR_ONB, MULTIPLE_PPP_DIALUP_SUPPORT, FALSE, PS_DIALUP)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(TCPIP_OVER_CSD)),TRUE)
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      ifdef CSD_SUPPORT
        ifneq ($(strip $(CSD_SUPPORT)),NONE)
          COM_DEFS += __TCPIP_OVER_CSD__
        else
          $(warning ERROR: When TCPIP_OVER_CSD support, some related option should be open, must open TCPIP_SUPPORT & CSD_SUPPORT.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      else
        $(warning ERROR: When TCPIP_OVER_CSD support, some related option should be open, must open TCPIP_SUPPORT & CSD_SUPPORT.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      $(warning ERROR: When TCPIP_OVER_CSD support, some related option should be open, must open TCPIP_SUPPORT & CSD_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifneq ($(filter __TCPIP_OVER_CSD__,$(COM_DEFS)),)
      $(warning ERROR: When TCPIP_OVER_CSD is not support, some related option should be closed.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  
  ifeq ($(strip $(PPP_SUPPORT)),NONE)
    PPP_DEPENDENCE_OPTION =__MULTIPLE_PPP_DIALUP_SUPPORT__ __TCPIP_OVER_CSD__ __EXT_MODEM__
    ifneq ($(filter $(PPP_DEPENDENCE_OPTION),$(COM_DEFS)),)
      $(call DEP_ERR_SETA_OR_ONB, MULTIPLE_PPP_DIALUP_SUPPORT, FALSE, PPP_SUPPORT)
      $(call DEP_ERR_SETA_OR_ONB, EXT_MODEM_SUPPORT, FALSE, PPP_SUPPORT)
      $(call DEP_ERR_SETA_OR_ONB, CSD_SUPPORT, NONE, PPP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += PPP_NOT_PRESENT
  endif
else
  ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    PS_DIALUP = TRUE
  else
    PS_DIALUP = FALSE
  endif
  ifeq ($(strip $(PS_DIALUP)),TRUE)
#    COM_DEFS += __PS_DIALUP__
  endif
endif

PPP_MODULE_BUILD=FALSE
ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    PPP_MODULE_BUILD=TRUE
  else
    ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
      PPP_MODULE_BUILD=TRUE
    endif
  endif
endif

ifeq ($(strip $(PPP_MODULE_BUILD)),TRUE)
  ifndef PPP_SUPPORT
    ifeq ($(strip $(EUTRAN_MODE_SUPPORT)), EUTRAN_MODE)
      COM_DEFS += PPP_NOT_PRESENT
    endif
  else
     ifneq ($(strip $(PPP_SUPPORT)),NONE)
       ifeq ($(strip $(EUTRAN_MODE_SUPPORT)), EUTRAN_MODE)
         COM_DEFS += PPP_NOT_PRESENT
       endif
     endif
  endif
endif

#####################################################################
# End related rule of PPP_SUPPORT
#####################################################################

ifdef TST_SET_LOG_BUF_SIZ
  ifneq ($(strip $(TST_SET_LOG_BUF_SIZ)),NONE)
    ifeq ($(strip $(TST_SUPPORT)),TRUE)
      COM_DEFS += FORCE_TST_RING_BUFFER_SCALE=$(strip $(TST_SET_LOG_BUF_SIZ))
    else
      $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_SET_LOG_BUF_SIZ)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef AT_COMMAND_SET
  ifeq ($(strip $(AT_COMMAND_SET)),SLIM)
      $(call DEP_ERR_SETA_OR_SETB,MMI_VERSION,not EMPTY_MMI,AT_COMMAND_SET,FULL)
      DEPENDENCY_CONFLICT = TRUE
    ifdef RSAT_SUPPORT
      ifneq ($(strip $(RSAT_SUPPORT)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,RSAT_SUPPORT,NONE,AT_COMMAND_SET,FULL)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += __SLIM_AT__
  endif

  ifeq ($(strip $(AT_COMMAND_SET)),ULC)
      $(call DEP_ERR_SETA_OR_SETB,MMI_VERSION,not EMPTY_MMI,AT_COMMAND_SET,FULL)
      DEPENDENCY_CONFLICT = TRUE
    ifdef RSAT_SUPPORT
      ifneq ($(strip $(RSAT_SUPPORT)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,RSAT_SUPPORT,NONE,AT_COMMAND_SET,FULL)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += __SLIM_AT__ __ULC_AT__
  endif
endif

ifeq ($(filter MS TC01 MTK MAC,$(strip $(USB_COMPORT_PC_DRIVER_SUPPORT))),)
  $(warning ERROR: USB_COMPORT_PC_DRIVER_SUPPORT must be defined as MS/TC01/MTK/MAC!)
  DEPENDENCY_CONFLICT = TRUE
endif

ifeq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),MAC)
  COM_DEFS    += __USB_COMPOSITE_REMOVE_IAD__
  COM_DEFS    += __USB_COMPORT_SUPPORT_MAC_DRIVER__
endif

ifeq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),MTK)
  COM_DEFS    += __USB_COMPORT_SUPPORT_MTK_DRIVER__
endif

ifeq ($(strip $(PHB_SYNC)),ON)
  ifneq ($(strip $(USIM_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,PHB_SYNC)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=   __PHB_USIM_SYNC__
endif

ifdef KAL_ASSERT_LEVEL
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL4)
    COM_DEFS += __KAL_ASSERT_LEVEL4__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL3)
    COM_DEFS += __KAL_ASSERT_LEVEL3__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL2)
    COM_DEFS += __KAL_ASSERT_LEVEL2__ __KAL_ASSERT_SHRINKING__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL1)
    COM_DEFS += __KAL_ASSERT_LEVEL1__ __KAL_ASSERT_SHRINKING__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL0)
    COM_DEFS += __KAL_ASSERT_LEVEL0__ __KAL_ASSERT_SHRINKING__
  endif
endif

COM_DEFS +=  __SW_MP4_LOSSY_SUPPORT__
COM_DEFS +=  __SW_H264_LOSSY_SUPPORT__

ifeq ($(strip $(USIM_SUPPORT)),TRUE)
  ifeq ($(call gt,$(strip $(PHB_SIM_ENTRY)),1000),T)
    $(warning ERROR: PHB_SIM_ENTRY value ($(PHB_SIM_ENTRY)) of USIM projects should not be larger than 1000)
    DEPENDENCY_CONFLICT = TRUE
  endif
else
  ifeq ($(call gt,$(strip $(PHB_SIM_ENTRY)),254),T)
    $(warning ERROR: PHB_SIM_ENTRY value ($(PHB_SIM_ENTRY)) of non USIM projects should not be larger than 254)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# Copro dependency check is valid only for FDD mode and non l1s project
  ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifeq ($(strip $(L2_HSDPA_COPRO)), TRUE)
      ifeq ($(call gt,$(strip $(GPRS_MAX_PDP_SUPPORT)),8),T)
        $(warning ERROR: GPRS_MAX_PDP_SUPPORT maximum value is 8 when HSDPA Copro exist due to hardware limitation, please reduce GPRS_MAX_PDP_SUPPORT value)
        DEPENDENCY_CONFLICT = TRUE 
      endif
      COM_DEFS        += __RLC_HSDPA_COPRO__ __MAC_HSDPA_COPRO__
      COMP_TRACE_DEFS_MODEM += $(strip $(UAS_FDD_FOLDER))/ul2/seq/include/seq_trc.h
    else
      ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,L2_HSDPA_COPRO,HSDPA_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    ifeq ($(strip $(L2_HSUPA_COPRO)), TRUE)
      ifneq ($(strip $(L2_HSDPA_COPRO)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,L2_HSDPA_COPRO,L2_HSUPA_COPRO)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(HSUPA_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,HSUPA_SUPPORT,L2_HSUPA_COPRO)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(HSDPA_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,HSDPA_SUPPORT,L2_HSUPA_COPRO)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS        += __L2_HSUPA_COPRO__
      COMP_TRACE_DEFS_MODEM += $(strip $(UAS_FDD_FOLDER))/ul2/seq/include/seq_trc.h
    else
      ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,L2_HSUPA_COPRO,HSUPA_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif

ifeq ($(strip $(TST_DNT_LOGGING)),TRUE)
  ifneq ($(strip $(TST_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_DNT_LOGGING)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS    += __TST_DNT_LOGGING__ __TST_LMU_LOGGING__ __TST_DCC_ENABLED__
  endif
endif

ifneq ($(filter UNICORN53%,$(BOARD_VER)),)
  COM_DEFS    +=  __PHONE__
else
  ifneq ($(filter MT6921%,$(BOARD_VER)),)
     COM_DEFS    +=  __EVB__
  else
    ifneq ($(filter %_EVB,$(BOARD_VER)),)
      COM_DEFS    +=  __EVB__
    else  
      COM_DEFS    +=  __PHONE__
    endif
  endif
endif

ifdef AOC_SUPPORT
  ifeq ($(strip $(AOC_SUPPORT)),TRUE)
     COM_DEFS    += __AOC_SUPPORT__
  endif   
endif

ifeq ($(strip $(PHB_ADDITIONAL_SUPPORT)),TRUE)
  ifneq ($(strip $(USIM_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,PHB_ADDITIONAL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=   __PHB_USIM_ADDITIONAL_SUPPORT__
endif

ifdef MTK_SLEEP_ENABLE
  ifeq ($(strip $(MTK_SLEEP_ENABLE)),TRUE)
    COM_DEFS    += MTK_SLEEP_ENABLE
  else
    ifneq ($(strip $(DEMO_PROJECT)),TRUE)
      $(warning ERROR: MTK_SLEEP_ENABLE must be TRUE in all customer projects .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(ICUSB_SUPPORT)),TRUE)
  COM_DEFS    +=   __ICUSB_SUPPORT__
endif

ifeq ($(strip $(MOBILE_VIDEO_SUPPORT)),WONDER)
  ifneq ($(strip $(PGDL_SUPPORT)),TRUE)
    $(warning ERROR: Please turn on PGDL_SUPPORT when MOBILE_VIDEO_SUPPORT  defined! )
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS         += __MOBILE_VIDEO_SUPPORT__
  MMI_INCDIRS      += vendor/mobilevideo/adaption/mobilevideoinc
  COMPLIST         += mobilevideo
endif

ifdef USB_TETHERING
  ifeq ($(strip $(USB_TETHERING)),TRUE)
    ifneq ($(strip $(DHCPD_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,DHCPD_SUPPORT,USB_TETHERING)
      DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(strip $(NDIS_SUPPORT)),UPS)
      $(call DEP_ERR_ONA_OR_OFFB,USB_TETHERING,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    
    ifeq ($(strip $(USB_HIGH_SPEED_COM_PORT_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_HIGH_SPEED_COM_PORT_SUPPORT,USB_TETHERING)
      DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COM_DEFS    += __USB_TETHERING__ __UPS_SUPPORT__
      COMPLIST    += ups
      COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/middleware/ups/rndis/include/rndis_trc.h
      COMP_TRACE_DEFS_MODEM    += ${CORE_ROOT}/driver/cmux/include/rndis_ctrl_trc.h
      ifeq ($(filter cmux,$(COMPLIST)),)
        ifeq ($(CORE_ROOT),pcore)
          COMPLIST    += cmux
        endif
      endif
    endif 
  endif
endif

ifdef RF_BSI_CLK_DIV_BY_AP_ENABLE
  ifeq ($(strip $(RF_BSI_CLK_DIV_BY_AP_ENABLE)),TRUE)
    COM_DEFS    += __RF_BSI_CLK_DIV_BY_AP_ENABLE__
  endif
endif

ifdef MODIS_FDM
  ifeq ($(strip $(MODIS_FDM)),ON)
    COM_DEFS   += __FS_MODIS_FDM__ 
  endif
endif

COM_DEFS += __MP4_DEC_ASP_PARTIAL_SUPPORT__

ifdef ZIMAGE_SUPPORT
  ifeq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
    COM_DEFS   +=  __ZIMAGE_SUPPORT__
    COM_DEFS   +=  __VI_ENABLED__
  endif
endif

ifeq ($(strip $(ZIMAGE_AUTO_CONFIG)),TRUE)
   ifneq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
      $(warning ERROR: PLEASE set ZIMAGE_SUPPORT=TRUE when ZIMAGE_AUTO_CONFIG=TRUE)
      DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifndef PHB_FDN_ENTRY
     PHB_FDN_ENTRY = 32
endif

ifdef PHB_FDN_ENTRY
     COM_DEFS    += MAX_PHB_FDN_ENTRY=$(strip $(PHB_FDN_ENTRY))
endif

2G_TX_POWER_CONTROL_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
ifneq ($(filter $(2G_TX_POWER_CONTROL_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  COM_DEFS    +=  __2G_TX_POWER_CONTROL_SUPPORT__
endif

ifeq ($(strip $(2G_TX_VOLTAGE_COMPENSATION_SUPPORT)),TRUE)
  COM_DEFS    += __2G_TX_VOLTAGE_COMPENSATION_SUPPORT__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R99_SUPPORT)
  COM_DEFS    +=   __R99__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R4_SUPPORT)
  COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R5_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__ __GERAN_R5__ __REL5__ __USIM_SUPPORT__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__ __GERAN_R5__ __REL5__ __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __FDD_REDIRECTION__ __CMCC_FR__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R7_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__ __GERAN_R5__ __REL5__ __GERAN_R6__ __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__ __GERAN_R7__ __FDD_REDIRECTION__ __CMCC_FR__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R8_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__ __GERAN_R7__ __GERAN_R8__ __FDD_REDIRECTION__ __CMCC_FR__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R9_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__ __GERAN_R7__ __GERAN_R8__ __GERAN_R9__ __FDD_REDIRECTION__ __CMCC_FR__
    endif    
    
ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R10_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__ __GERAN_R7__ __GERAN_R8__ __GERAN_R9__ __GERAN_R10__ __FDD_REDIRECTION__ __CMCC_FR__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R11_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__ __GERAN_R7__ __GERAN_R8__ __GERAN_R9__ __GERAN_R10__ __GERAN_R11__ __FDD_REDIRECTION__ __CMCC_FR__
endif

ifeq ($(strip $(EUTRAN_MODE_SUPPORT)),EUTRAN_MODE)
    COM_DEFS    +=   __REL4__ __REL5__ __REL6__ __REL7__ __REL8__ __CSG_SUPPORT__ __R6_NETWORK_SHARING__
endif

ifeq ($(strip $(EUTRAN_MODE_SUPPORT)),EUTRAN_MODE)
  COM_DEFS += __ETWS_SUPPORT__ __EXT_SEG_CTRL_BLK__
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R4_SUPPORT)
  COM_DEFS    +=   __UMTS_R4__ __REL4__
endif
ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R5_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
    
    ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    ifeq ($(strip $(UMTS_TDD_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R6_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ __FDD_REDIRECTION__ __CMCC_FR__
    
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
    
    ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    ifeq ($(strip $(UMTS_TDD_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    
    ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSUPA_SUPPORT__
      
      ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        COM_DEFS    +=   FDD_EDCH_CATEGORY=$(strip $(FDD_EDCH_PHYSICAL_CATEGORY))
      endif
    endif
  endif
  ifeq ($(strip $(NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION)),TRUE)
    COM_DEFS    +=   __NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION__
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R7_SUPPORT)
  COM_DEFS    +=   __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ __UMTS_R7__  __REL7__ __FDD_REDIRECTION__ __CMCC_FR__
  ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
      
      ifeq ($(strip $(R7_HSDPA_PLUS_SUPPORT)),TRUE)
        COM_DEFS    +=   __R7_HSDPA_PLUS_SUPPORT__ __FDD_MAC_EHS_SUPPORT__ __FDD_ENHANCED_COMMON_STATE_SUPPORT__
      endif
      
      ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
        COM_DEFS    +=   __HSUPA_SUPPORT__
        COM_DEFS    +=   FDD_EDCH_CATEGORY=$(strip $(FDD_EDCH_PHYSICAL_CATEGORY))
        
        ifeq ($(strip $(R7_HSUPA_PLUS_SUPPORT)),TRUE)
          COM_DEFS    +=   __R7_HSUPA_PLUS_SUPPORT__ __FDD_CPC_SUPPORT__
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
      endif
    endif
    ifeq ($(strip $(R7R8_FULL_SET_SUPPORT)),TRUE)
      COM_DEFS    +=   __CUSTOMIZE_ENHANCED_COMMON_STATE_SUPPORT__ __CUSTOMIZE_CSHSPA_SUPPORT__ __CUSTOMIZE_HSSCCH_LESS_SUPPORT__ __CUSTOMIZE_UEA2_UIA2_SUPPORT__
      COM_DEFS    +=   __CUSTOMIZE_RFC2507_SUPPORT__
    endif
  endif
  ifeq ($(strip $(UMTS_TDD_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
      ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
        COM_DEFS    +=   __HSUPA_SUPPORT__
        COM_DEFS    +=   TDD_EDCH_CATEGORY=$(strip $(TDD_EDCH_PHYSICAL_CATEGORY))
        ifeq ($(strip $(HSUPA_CAPABILITY_NOT_SUPPORT)),TRUE)
          COM_DEFS    +=   __HSUPA_CAPABILITY_NOT_SUPPORT__
        endif
      endif
    endif
  endif
endif

HSDSCH_HARQ_OFF_NOT_SUPPORT_PLATFORM = MT6280 MT6589 MT6572 MT6582
ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
  ifeq ($(filter $(HSDSCH_HARQ_OFF_NOT_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
    COM_DEFS    +=   __HSDSCH_HARQ_OFF__
  endif
endif

#always turn on
COM_DEFS    += __3G_MIPI_SUPPORT__

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R8_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__ __REL6__ __UMTS_R7__ __REL7__ __UMTS_R8__ __REL8__  \
                  __HSDPA_2MS_DATA_IND__ __HSDPA_2MS_DATA_IND_LATENCY_IMPROVE__ __FDD_REDIRECTION__ __PPACR_SUPPORT__ __CMCC_FR__ __3G_CSG_SUPPORT__
  
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

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R11_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__ __REL6__ __UMTS_R7__ __REL7__ __UMTS_R8__ __REL8__ __UMTS_R9__ __REL9__ __UMTS_R10__ __REL10__ __UMTS_R11__ __REL11__ \
                  __HSDPA_2MS_DATA_IND__ __HSDPA_2MS_DATA_IND_LATENCY_IMPROVE__ __FDD_REDIRECTION__ __PPACR_SUPPORT__ __CMCC_FR__ __SIB19_DEFFER__ __3G_CSG_SUPPORT__
  
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__ __FDD_MAC_EHS_SUPPORT__ __FDD_ENHANCED_COMMON_STATE_SUPPORT__ __FDD_HSDSCH_DRX_CELL_FACH_SUPPORT__ __CUSTOMIZE_ENHANCED_COMMON_STATE_SUPPORT__ __CUSTOMIZE_HSDSCH_DRX_CELL_FACH_SUPPORT__ __CUSTOMIZE_HSSCCH_LESS_SUPPORT__ 
    ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    ifeq ($(strip $(UMTS_TDD_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    
    ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSUPA_SUPPORT__ __DCHSDPA_ADJ_FREQ_SUPPORT__ __FDD_CPC_SUPPORT__ __FDD_COMMON_EDCH_SUPPORT__ __FDD_MAC_IIS_SUPPORT__ __HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__ __CUSTOMIZE_MAC_IIS_SUPPORT__ 
      ifneq (${CORE_ROOT},pcore)
      	COM_DEFS    +=   __CUSTOMIZE_COMMON_EDCH_SUPPORT__
      endif
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
        
        # we now only handle HSDPA category 29~32 for 3C/4C
        ifeq ($(call gt,$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),28),T)           
           ifeq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),29)
              NUM_SUPPORT_HSDPA_CARRIES=3
           else
              ifeq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),30)
                NUM_SUPPORT_HSDPA_CARRIES=3
              else
                 ifeq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),31)
                    NUM_SUPPORT_HSDPA_CARRIES=4
                 else
                    ifeq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),32)
                       NUM_SUPPORT_HSDPA_CARRIES=4
                    endif
                 endif
              endif
           endif
           COM_DEFS    += __MULTI_CARRIER_HSDPA__=$(strip $(NUM_SUPPORT_HSDPA_CARRIES))        
        endif        

        ifeq ($(call gt,$(strip $(FDD_EDCH_PHYSICAL_CATEGORY)),6),T)
             COM_DEFS    +=   __HOM_UL16QAM_SUPPORT__
        endif
        
        # UEs of EDCH Category 8 support only QPSK in Dual Cell E-DCH operation, no combine with UL16QAM
        ifeq ($(call gt,$(strip $(FDD_EDCH_PHYSICAL_CATEGORY)),7),T)
             COM_DEFS    +=   __DCHSUPA_ADJ_FREQ_SUPPORT__
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

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R5_SUPPORT)
  COM_DEFS    +=   __UMTS_R5__ __REL4__ __REL5__
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R6_SUPPORT)
  COM_DEFS    +=   __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ 
endif

ifeq ($(findstring LTE_RB,$(LTE_RELEASE_SUPPORT)),LTE_RB)
  COM_DEFS += __LTE_R11__
  COM_DEFS += __LTE_EPLMN_SEARCH__
  ifeq ($(strip $(LTEA_FEATURE_SET)),STAGE2)
    COM_DEFS += __LTE_A_CA__ __LTE_A_EDDA__
  endif
  ifeq ($(strip $(LTEA_FEATURE_SET)),FULL)
    COM_DEFS += __LTE_A_CA__ __LTE_A_EDDA__
    COM_DEFS += __LTE_A_EICIC__ __LTE_A_FEICIC__ __LTE_A_EMBMS__ __LTE_A_UL_COMP__
  endif  
endif

ifeq ($(strip $(LATENCY_REDUCTION)),TRUE)
  ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R7_SUPPORT)
    ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R8_SUPPORT)
      $(call DEP_ERR_SETA_OR_OFFB,GERAN_RELEASE_SUPPORT,GERAN_R7_SUPPORT,LATENCY_REDUCTION)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __GERAN_RTTI__ __GERAN_FANR__
# Evelyn temp add for R7 feature detection
  COM_DEFS += __GERAN_EGPRS2__ __GERAN_RLC_PRESISTEN_MODE__ __GERAN_DLDC__
endif

ifdef CUST_CODE
  ifneq ($(strip $(CUST_CODE)),NONE)
    COM_DEFS += __$(strip $(CUST_CODE))__
  endif
  ifeq ($(strip $(CUST_CODE)),TC01)
    COM_DEFS += __RMMI_EXTEND_CUSTOM_CMD__ __AT_ME_IDENTIFICATION_WITHOUT_HEADER__
    COM_DEFS += __ATH_HANGUP_OTHER_SRC_CALL__
    COM_DEFS += __TC01_IMS_SUPPORT__
    ifneq ($(strip $(DRM_SUPPORT)),NONE)
      COM_DEFS += __LONG_AT_CMD_SUPPORT__
    endif
    ifdef TC01_ERS_LOCATION
      ifneq ($(strip $(TC01_ERS_LOCATION)),NONE)
        COM_DEFS += __TC01_ERS_SUPPORT__
      endif
    endif 
  endif
endif
    
ifdef TC01_ERS_LOCATION
  ifeq ($(strip $(TC01_ERS_LOCATION)),NVRAM)
    COM_DEFS += __TC01_ERS_NVRAM__
  endif
  ifeq ($(strip $(TC01_ERS_LOCATION)),BACKUP)
    ifndef SYSDRV_BACKUP_DISK_SUPPORT
      $(warning ERROR: PLEASE set SYSDRV_BACKUP_DISK_SUPPORT to be FAT or set TC01_ERS_LOCATION to be NVRAM)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),FAT)
      $(warning ERROR: PLEASE set SYSDRV_BACKUP_DISK_SUPPORT to be FAT or set TC01_ERS_LOCATION to be NVRAM)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __TC01_ERS_BACKUP__
  endif
endif

ifdef BOOT_CERT_SUPPORT
  ifeq ($(strip $(BOOT_CERT_SUPPORT)),BOOT_CERT_V1)
    COM_DEFS += __BOOT_CERT__ __BOOT_CERT_V1__
  endif
  ifeq ($(strip $(BOOT_CERT_SUPPORT)),BOOT_CERT_V2)
    COM_DEFS += __BOOT_CERT__ __BOOT_CERT_V2__
  endif
endif

MMA_MAX_NUM_VALUE = 2 3 4 5 6 7 8 9 10 11 12
ifdef MMA_MAX_NUM
  ifeq ($(filter $(strip $(MMA_MAX_NUM)),$(strip $(MMA_MAX_NUM_VALUE))),)
    $(warning ERROR: Please set MMA_MAX_NUM to 2-12.)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS += MMA_MAX_NUM=$(strip $(MMA_MAX_NUM))
  endif
else
  COM_DEFS += MMA_MAX_NUM=12
endif

ifdef PACKAGE_SEG
  ifneq ($(strip $(PACKAGE_SEG)), NONE)
    COM_DEFS    +=  __$(strip $(PACKAGE_SEG))__
  endif
endif

ifeq ($(strip $(PACKAGE_SEG)),16_3_SEG)
  ifneq ($(strip $(SECURE_SUPPORT)),FALSE)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when SECURE_SUPPORT = FALSE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

#SWTP feature support
ifdef TX_POWER_OFFSET_SUPPORT
  ifeq ($(strip $(TX_POWER_OFFSET_SUPPORT)),TRUE)
    COM_DEFS    += __TX_POWER_OFFSET_SUPPORT__
  endif
endif

ifeq ($(strip $(DATA_CARD_SPEECH)),TRUE)
  DATA_CARD_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
  ifeq ($(filter $(strip $(PLATFORM)) ,$(DATA_CARD_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support DATA_CARD_SPEECH.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __MODEM_CARD__,$(COM_DEFS)),)
    $(warning ERROR: only __MODEM_CARD__ project support DATA_CARD_SPEECH.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __DATA_CARD_SPEECH__
endif

ifdef SIM_HOT_SWAP
  ifneq ($(strip $(SIM_HOT_SWAP)), NONE)
    COM_DEFS    +=  __SIM_HOT_SWAP_SUPPORT__
    ifneq ($(findstring SIM_SLOT_1,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_1_SUPPORT__
    endif
    ifneq ($(findstring SIM_SLOT_2,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_2_SUPPORT__
    endif
    ifneq ($(findstring SIM_SLOT_3,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_3_SUPPORT__
    endif
    ifneq ($(findstring SIM_SLOT_4,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_4_SUPPORT__
    endif
  endif
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
  ifeq ($(strip $(DEMAND_PAGING_VERSION)),DPV2)
     COM_DEFS    += __DEMAND_PAGING_V2__
  endif
endif

# For smart phone settings.
#ifdef SMART_PHONE_CORE
#  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    include make/${COMMON_ROOT}/smart_phone_option.mak
#  endif
#endif

ifdef SMART_PHONE_CORE
  ifeq ($(strip $(SMART_PHONE_CORE)),ANDROID_MODEM)
    COM_DEFS += __CSCB_ALL_LANGUAGE_ON__
    ifeq ($(strip $(USIM_SUPPORT)),TRUE)
      COM_DEFS += __AT_EPBUM_SUPPORT__ __PHB_USIM_ADDITIONAL_SUPPORT__
    endif
  endif
endif

ifdef SMART_PHONE_CORE
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    COM_DEFS += __ALLOW_SIM_REFRESH_RESET_WHEN_IN_CALL__
  endif
endif

# BASIC or UDVT projects do not need L1_TMD_FILES
ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  L1_TMD_FILES :=
endif
ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
  L1_TMD_FILES :=
endif

ifdef PBCCH_SUPPORT
  ifeq ($(strip $(PBCCH_SUPPORT)),TRUE)
    COM_DEFS    +=    __RMP_PRESENT__
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS += _L1_DISABLE_TRACE_LEVEL_=2
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS += __SLIM_MODEM_EM_MODE__
  else
    COM_DEFS += __SLIM_MODEM_EM_MODE__ __MODEM_EM_MODE__
  endif
else
  COM_DEFS += __SLIM_MODEM_EM_MODE__ __MODEM_EM_MODE__
endif

ifdef SIP_SERIAL_FLASH_SIZE
  ifneq ($(strip $(SIP_SERIAL_FLASH_SIZE)),NONE)
    ifneq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
      $(warning COMBO_MEMORY_SUPPORT must be TRUE when SIP_SERIAL_FLASH_SIZE is not NONE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

COM_DEFS    += __CSMCC_CALLCONFIRM_TIMER__

# MIPI ANT tuner feature support
COM_DEFS    += __MIPI_ANT_TUNER_SUPPORT__

ifdef CSD_SUPPORT
  ifneq ($(strip $(CSD_SUPPORT)),NONE)
    ifeq ($(strip $(AT_COMMAND_SET)),ULC)
       $(warning ERROR: PLease set AT_COMMAND_SET to SLIM or set CSD_SUPPORT  to NONE)
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

DSP_SOLUTION_SUPPORT_PLATFORM = MT6575 MT6577
ifneq ($(filter $(strip $(PLATFORM)) ,$(DSP_SOLUTION_SUPPORT_PLATFORM)),)
  ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    $(warning ERROR: DSP_SOLUTION must be DUALMACDSP,when PLATFORM is $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
  ifdef NAND_FLASH_BOOTING
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,ZIMAGE_SUPPORT,NAND_FLASH_BOOTING)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef EMMC_BOOTING
    ifneq ($(strip $(EMMC_BOOTING)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,ZIMAGE_SUPPORT,EMMC_BOOTING)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MCU_DORMANT_MODE)),TRUE)
  COM_DEFS += __MCU_DORMANT_MODE__
endif

ifeq ($(strip $(SIM_RECOVERY_ENHANCEMENT)),TRUE)
  COM_DEFS    +=  __SIM_RECOVERY_ENHANCEMENT__
endif

ifeq ($(strip $(TDD_RF_CUSTOM_TOOL_SUPPORT)),TRUE)
  COM_DEFS    += __TDD_RF_CUSTOM_TOOL_SUPPORT__
  ifneq ($(strip $(L1_TDD128)),TRUE)
    $(warning ERROR: TDD_RF_CUSTOM_TOOL_SUPPORT can NOT be TRUE when L1_TDD128 is not TRUE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MCU_DORMANT_MODE)),TRUE)
  ifeq ($(strip $(CENTRALIZED_SLEEP_MANAGER)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,CENTRALIZED_SLEEP_MANAGER,MCU_DORMANT_MODE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(MTK_SLEEP_ENABLE)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,MTK_SLEEP_ENABLE,MCU_DORMANT_MODE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USB_BOOTUP_TRACE)),TRUE)
  ifdef SMART_PHONE_CORE
    ifeq ($(filter NONE MODEM_ONLY,$(strip $(SMART_PHONE_CORE))),)
      $(warning ERROR: Smart Phone does not support USB_BOOTUP_TRACE!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __USB_BOOTUP_TRACE__
endif

ifdef SIP_RAM_SIZE
  ifneq ($(strip $(SIP_RAM_SIZE)),NONE)
    COM_DEFS  += __SIP_RAM_SIZE__
  endif
endif

DCM_ENABLE_SUPPORT_PLATFORM = MT6280
ifneq ($(strip $(MCU_DCM)),DCM_ENABLE)
  ifneq ($(filter $(DCM_ENABLE_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
    $(warning ERROR: PLEASE set MCU_DCM as DCM_ENABLE on $(strip $(PLATFORM)) project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# turn on the feature by default, except TDD, low cost, l1s, basic, udvt project
ifeq ($(strip $(PLMN_LIST_PREF_SUPPORT)),DEFAULT)
  ifdef LOW_COST_SUPPORT
    ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
      ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
        COM_DEFS += __PLMN_LIST_PREF_SUPPORT__
      endif
    endif
  else
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COM_DEFS += __PLMN_LIST_PREF_SUPPORT__
    endif
  endif
endif

ifeq ($(strip $(3G_DATA_PLANE_MEMORY_SHRINK)),TRUE)
  COM_DEFS += __DL_MEMORY_SHRINK__ __UL_MEMORY_SHRINK__
endif

ifeq ($(strip $(3G_NEW_DATA_PLANE_ARCH)), TRUE)
  COM_DEFS +=   __3G_NEW_DATA_PLANE_ARCH__ __RATDM_UL_SHAQ__ __RATDM_SHAQ_HAS_PRIORITY_QUEUE__ __CSHSPA_SUPPORT__
else
  ifeq ($(strip $(UMTS_TDD_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    COM_DEFS += __RATDM_UL_SHAQ__ __RATDM_SHAQ_HAS_PRIORITY_QUEUE__
  endif
endif

ifeq ($(strip $(UL2_HSPA_PLUS_RX_COPRO)), TRUE)
  ifneq ($(strip $(3G_NEW_DATA_PLANE_ARCH)),TRUE)
    $(warning ERROR: when UL2_HSPA_PLUS_RX_COPRO is set to TRUE , 3G_NEW_DATA_PLANE_ARCH must to be TRUE .)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(L2_HSDPA_COPRO)),TRUE)
    $(warning ERROR: when UL2_HSPA_PLUS_RX_COPRO is set to TRUE , L2_HSDPA_COPRO must to be TRUE .)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS        += __UL2_HSPA_PLUS_RX_COPRO__
endif

ifeq ($(strip $(UL2_HSPA_PLUS_TX_COPRO)), TRUE)
  ifneq ($(strip $(UL2_HSPA_PLUS_RX_COPRO)),TRUE)
    $(warning ERROR: when UL2_HSPA_PLUS_TX_COPRO is set to TRUE , UL2_HSPA_PLUS_RX_COPRO must to be TRUE .)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(L2_HSUPA_COPRO)),TRUE)
    $(warning ERROR: when UL2_HSPA_PLUS_TX_COPRO is set to TRUE , L2_HSDPA_COPRO must to be TRUE .)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS        += __UL2_HSPA_PLUS_TX_COPRO__
endif

ifndef MAX_NUM_OF_PPP_DIALUP_SUPPORT
  ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
    $(warning ERROR: please set MULTIPLE_PPP_DIALUP_SUPPORT as FALSE on ${CORE_ROOT}/custom/internal project,otherwise there will be errors like:non-numeric second argument to 'wordlist' function.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(NVRAM_BIND_TO_CHIP_CIPHER)),ENABLE)
  ifeq ($(strip $(IC_TEST_TYPE)),IC_MODULE_TEST)
    $(warning ERROR: please enable NVRAM_BIND_TO_CHIP_CIPHER only when IC_TEST_TYPE is not set as IC_MODULE_TEST.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=  __NVRAM_BIND_TO_CHIP_CIPHER__
endif

ifeq ($(strip $(3D_ANAGLYPH)),TRUE)
  COM_DEFS += __VIDEO_3D_ANAGLYPH__
endif

ifneq ($(filter MT6575 MT6577,$(PLATFORM)),)
  ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    $(warning ERROR: please set DSP_SOLUTION = DUALMACDSP, when PLATFORM = $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
  COM_DEFS   += __FS_AUTO_CONFIG_SUPPORT__
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    COM_DEFS   += __FS_AUTO_CONFIG_SUPPORT__
  endif
endif

ifeq ($(strip $(GAMELOFT_CONTENT_SUPPORT)),TRUE)
  COM_DEFS     +=  __GAMELOFT_CONTENT_SUPPORT__
endif

ifeq ($(strip $(HD_RECORD_SUPPORT)),TRUE)
  COM_DEFS  +=  __HD_RECORD__
endif

ifeq ($(strip $(USB_TETHERING)),TRUE)
  ifdef USB_MULTIPLE_COMPORT_ENABLE
    ifneq ($(strip $(USB_MULTIPLE_COMPORT_ENABLE)),TRUE)
      $(warning ERROR: please turn on USB_MULTIPLE_COMPORT_ENABLE when USB_TETHERING = TRUE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

2G_RF_CUSTOM_TOOL_SUPPORT_PLATFORM = MT6575 MT6577
ifeq ($(strip $(2G_RF_CUSTOM_TOOL_SUPPORT)),FALSE)
  ifneq ($(filter $(strip $(PLATFORM)),$(2G_RF_CUSTOM_TOOL_SUPPORT_PLATFORM)),)
    $(warning ERROR: 2G_RF_CUSTOM_TOOL_SUPPORT can NOT be FALSE when PLATFORM = $(strip $(PLATFORM)) .)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(WCDMA_PREFERRED)),TRUE)
  ifeq ($(strip $(UMTS_FDD_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    COM_DEFS        += __WCDMA_PREFERRED__
    COM_DEFS        += __UMTS_FDD_PREFER__
  endif
endif

ifeq ($(strip $(TST_MALMO_SUPPORT)),TRUE)
  ifneq ($(strip $(TST_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_MALMO_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS     += __TST_MALMO_SUPPORT__ __TST_ALC_SUPPORT__ __TST_ASM_SUPPORT__
  endif
endif

COM_DEFS += __CMCC_STD_FR__

ifndef VIRTUAL_PORTS_NUM
 VIRTUAL_PORTS_NUM         = 3
endif
ifdef VIRTUAL_PORTS_NUM
  COM_DEFS    += VIRTUAL_PORTS_NUM=$(strip $(VIRTUAL_PORTS_NUM))
endif

NVRAM_REDUCTION_NOT_SUPPORT_PLATFORM = MT6236
ifeq ($(filter $(strip $(PLATFORM)) ,$(NVRAM_REDUCTION_NOT_SUPPORT_PLATFORM)),)
   COM_DEFS    += __CAMERA_NVRAM_REDUCTION_ISP_SUPPORT__
   COM_DEFS    += __CAMERA_NVRAM_REDUCTION__
endif

ifdef SSDVT_TEST
  ifeq ($(strip $(SSDVT_TEST)),TRUE)
    COMPLIST     += ssdvt
    COM_DEFS     += __SSDVT_TEST__
  endif
endif

ifeq ($(strip $(FS_RAMDISK)),TRUE)
  COM_DEFS     += __FS_RAMDISK__
  COMPLIST += mtd
endif

ifdef MOBILE_BROADBAND
  ifeq ($(strip $(MOBILE_BROADBAND)),MBIM)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COM_DEFS     += __MBIM_SUPPORT__ __NDIS_SUPPORT__
      ifneq ($(strip $(USB_MBIM_SUPPORT)),TRUE)
        ifeq ($(filter cmux,$(COMPLIST)),)
	      ifeq ($(CORE_ROOT),pcore)
	        COMPLIST     += cmux
	      endif
        endif
        COM_DEFS     += __UPS_SUPPORT__
        COMPLIST     += ups
        COMP_TRACE_DEFS_MODEM   += ${CORE_ROOT}/middleware/ups/mbim/include/mbim_ctrl_trc.h
        COMP_TRACE_DEFS_MODEM   += ${CORE_ROOT}/middleware/ups/mbim/include/mbim_trc.h
      endif
      COMP_TRACE_DEFS_MODEM   += ${CORE_ROOT}/modem/l4/mbci/include/mbci_trc.h
    endif
  endif
endif

32K_CRYSTAL_REMOVAL_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
QUERY_32K_CRYSTAL_FROM_MD_PLATFORM = MT6280 MT6290
QUERY_32K_CRYSTAL_FROM_AP_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
ifdef 32K_XOSC_REMOVE
  ifeq ($(strip $(32K_XOSC_REMOVE)), TRUE)
    ifeq ($(filter $(32K_CRYSTAL_REMOVAL_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
      DEPENDENCY_CONFLICT = TRUE
      $(warning ERROR: 32K_XOSC_REMOVE only can be supported in $(32K_CRYSTAL_REMOVAL_SUPPORT_PLATFORM), $(PLATFORM) can not be supported)
    endif
  endif
endif
ifdef 32K_XOSC_REMOVE
  ifeq ($(strip $(32K_XOSC_REMOVE)), TRUE)
    COM_DEFS     +=  __F32_XOSC_REMOVAL_SUPPORT__
    ifneq ($(filter $(QUERY_32K_CRYSTAL_FROM_MD_PLATFORM), $(strip $(PLATFORM))),)
      COM_DEFS     +=  __QUERY_32K_CRYSTAL_FROM_MD__
    else
      ifneq ($(filter $(QUERY_32K_CRYSTAL_FROM_AP_PLATFORM), $(strip $(PLATFORM))),)
        COM_DEFS     +=  __QUERY_32K_CRYSTAL_FROM_AP__
      else 
        $(warning ERROR: MUST define query 32K crystal in MD or AP side )
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

DUAL_TALK_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
ifdef MDSYS
  ifeq ($(strip $(MDSYS)),MD1)
    COM_DEFS += __MD1__
    else
      ifeq ($(strip $(MDSYS)),MD2)
      COM_DEFS += __MD2__
    endif
  endif
endif

LTE_MEAS_OPT_PLATFORM = MT6757 MT6757P
ifneq ($(filter $(strip $(PLATFORM)),$(LTE_MEAS_OPT_PLATFORM)),)
  COM_DEFS += __LTE_MEAS_OPT__
  COM_DEFS += __ENABLE_LTE_ALL_MEAS_OPT__
endif 

ifdef MDSYS
  ifneq ($(strip $(MDSYS)),NONE)
    ifeq ($(filter $(PLATFORM), $(strip $(DUAL_TALK_SUPPORT_PLATFORM))),)
      DEPENDENCY_CHECK = TRUE
      $(warning ERROR: MDSYS only can be set on $(DUAL_TALK_SUPPORT_PLATFORM).)
    endif
  endif
endif

COMBO_MEMORY_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
ifdef COMBO_MEMORY_SUPPORT
  ifeq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
    ifeq ($(filter $(PLATFORM), $(strip $(COMBO_MEMORY_SUPPORT_PLATFORM))),)
      $(warning ERROR: COMBO_MEMORY_SUPPORT = TRUE just can be supported on $(COMBO_MEMORY_SUPPORT_PLATFORM).)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
ifdef COMBO_MEMORY_SUPPORT
  ifeq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
    COM_DEFS    += __COMBO_MEMORY_SUPPORT__
  endif
endif

ifdef GEMINI
 ifeq ($(strip $(GEMINI)),2)
    ifeq ($(strip $(GEMINI_VERSION)),V1)
      $(warning ERROR: Please set GEMINI_VERSION other than V1 when GEMINI = 2!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

DHL_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
ifdef DHL_SUPPORT
 ifeq ($(strip $(DHL_SUPPORT)),TRUE)
    ifeq ($(filter $(PLATFORM), $(strip $(DHL_SUPPORT_PLATFORM))),)
      $(warning ERROR: DHL_SUPPORT can NOT be TRUE when PLATFORM = $(strip $(PLATFORM))!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(DHL_MALMO_SUPPORT)),TRUE)
  COM_DEFS     += __DHL_MALMO_SUPPORT__ __MALMO_ASM_SWTR__
else
  COM_DEFS     += DEBUG_SWLA
endif

# LTE single-mode
ifeq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  COM_DEFS += __LTE_SM__ __MULTI_BOOT__
endif

ifeq ($(strip $(NAND_FLASH_BOOTING_IS_NONE)),TRUE)
  ifeq ($(strip $(EMMC_BOOTING_IS_NONE)),TRUE)
    ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
#      COM_DEFS += __NOR_IDLE_SWEEP__
    endif
  endif
endif

# For NONE_FLASH_EXIST Setting
ifeq ($(strip $(NAND_SUPPORT)),FALSE)
  ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),FALSE)
    COM_DEFS += __NONE_FLASH_EXIST__
  endif
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R9_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__ __GERAN_R7__ __GERAN_R8__ __GERAN_R9__
endif

ifeq ($(strip $(ORIGINAL_FLAVOR)),SKYPA_R5)
    COM_DEFS    += __TDD_MODEM__  
endif

EDCH_HRT_IMPROVE_NOT_SUPPORT_PLATFORM = MT6280 MT6589
ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
  ifeq ($(filter $(EDCH_HRT_IMPROVE_NOT_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
    COM_DEFS    +=   __EDCH_HRT_IMPROVE__
  endif
endif

ifeq ($(strip $(DUAL_EXT_BL)),TRUE)
  COM_DEFS += __DUAL_EXT_BL__
endif

ifeq ($(strip $(DUAL_LTE_DSP)),TRUE)
  COM_DEFS += __DUAL_LTE_DSP__
endif

ifeq ($(strip $(DUAL_PRIMARY_ROM)),TRUE)
  COM_DEFS += __DUAL_PRIMARY_ROM__
endif

ifdef L1_GPS_CO_CLOCK_SUPPORT 
  ifeq ($(strip $(L1_GPS_CO_CLOCK_SUPPORT)), TRUE)
    COM_DEFS += __L1_GPS_CO_CLOCK_SUPPORT__
  endif
endif

ifdef L1_LOCK_AFCDAC_AT_STARTUP_SUPPORT
  ifeq ($(strip $(L1_LOCK_AFCDAC_AT_STARTUP_SUPPORT)), TRUE)
    COM_DEFS += __L1_LOCK_AFCDAC_AT_STARTUP_SUPPORT__
  endif
endif

ifdef MODEM_NFC_SUPPORT
  ifeq ($(strip $(MODEM_NFC_SUPPORT)),TRUE)
    ifneq ($(strip $(USIM_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,MODEM_NFC_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=  __CGLA__ __UICC_CHANNEL_SUPPORT__
  endif
endif

ifeq ($(strip $(HIF_USB_SUPPORT)),TRUE)
  ifeq ($(strip $(HIF_USB30_SUPPORT)),TRUE)
        COM_DEFS        += USB30_ENABLE
  endif
endif

ifdef RTOS
  ifeq ($(strip $(RTOS)),NUCLEUS)
    ifneq ($(strip $(PLATFORM)),MT6589)
    ifneq ($(strip $(MDSYS)),MD2)
      $(warning ERROR: Only allow RTOS = NUCLEUS, when PLATFORM = MT6589 and MDSYS = MD2. Otherwise, RTOS = NUCLEUS_V2.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    endif
  endif
endif

ifeq ($(strip $(UNIFIED_ISR_LEVEL)),TRUE)
  COM_DEFS        += __UNIFIED_ISR_LEVEL__
endif

ifdef GDB_STUB_SUPPORT
  ifeq ($(strip $(GDB_STUB_SUPPORT)),TRUE)
    COM_DEFS      += GDB_DEBUGGER=1
    COMMINCDIRS += ${CORE_ROOT}/driver/devdrv/gdb/inc
  endif
endif

ifneq ($(strip $(PMIC_INIT_TYPE)),)
  COM_DEFS += $(PMIC_INIT_TYPE)
endif

ifdef SGLTE_SUPPORT
  ifeq ($(strip $(SGLTE_SUPPORT)),TYPE2_SINGLE_LOAD)
    COM_DEFS    += __SGLTE__ __4G_BACKGROUND_SEARCH__ __CTA_DUAL_SIM_STANDARD__ __L4C_ROOT__
  endif
endif

ifdef LTE_REPORT_CAP_AS_RELEASE
  ifeq ($(strip $(LTE_REPORT_CAP_AS_RELEASE)), AS_REL_10)
    COM_DEFS +=  __LTE_REPORT_CAP_AS_REL_10__ 
  endif
  ifeq ($(strip $(LTE_REPORT_CAP_AS_RELEASE)), AS_REL_11)
    COM_DEFS +=  __LTE_REPORT_CAP_AS_REL_11__ 
  endif
endif

ifeq ($(strip $(DUAL_SIM_HOT_SWAP_CO_DECK)),TRUE)
  ifeq ($(strip $(SIM_HOT_SWAP)),NONE)
    $(warning ERROR: DUAL_SIM_HOT_SWAP_CO_DECK only can be TRUE when SIM_HOT_SWAP != NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__
endif

COM_DEFS += __DISABLE_2MIN_MINIMUM_HPPLMN_TIMER__ \
            __DYNAMIC_ROAMING_SUPPORT__ \
            __R7_MANUAL_RHPLMN_SEL__ \
            __RESUME_GPRS_AFTER_LU_ABNORMAL__

GGE_MIPI_SUPPORT_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S

ifneq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
  ifneq ($(filter $(GGE_MIPI_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
    COM_DEFS    += __2G_MIPI_SUPPORT__
  endif
endif

# always turn on IVSR feature support
COM_DEFS    +=  __BT_SIM_PROFILE__

# always turn on MDMI feature support
COM_DEFS    +=  __MDMI_SUPPORT__

MULTI_RAT_AFC_TADC_SHARE_PLATFORM = TK6291 MT6755 MT6797 MT6750 MT6757 MT6757P MT6750S
ifneq ($(filter $(MULTI_RAT_AFC_TADC_SHARE_PLATFORM), $(strip $(PLATFORM))),)
  COM_DEFS    +=  __MULTI_RAT_AFC_TADC_SHARE_SUPPORT__
endif

ifdef EVDO_CT_SUPPORT
  ifeq ($(strip $(EVDO_CT_SUPPORT)),TRUE)
    COM_DEFS    +=  __REPORT_AVAILABLE_PLMN__
    COM_DEFS    +=  __2STAGE_NW_SELECTION__
    COM_DEFS    +=  __UE_EFOPLMN__
    COM_DEFS    +=  __MM_SEARCH_HPLMN_BEFORE_RPLMN__
    COM_DEFS    +=  __PERMANENT_AUTO_SEL_MODE__
  endif
endif

ifdef LOG_BUF_IN_SHM_SUPPORT
  ifeq ($(strip $(LOG_BUF_IN_SHM_SUPPORT)),TRUE)
    COM_DEFS    +=  __LOG_BUF_IN_SHM_SUPPORT__
  endif 
endif

ifeq ($(strip $(DMA_EMI_TYPE_RESTRICT)),NON_CACHEABLE)
  COM_DEFS += __DMA_EMI_TYPE_NON_CACHEABLE__
endif

ifdef SGLTE_DSDS_SUPPORT
  ifeq ($(strip $(SGLTE_DSDS_SUPPORT)),TRUE)
    COM_DEFS    +=   __SGLTE_DSDS__
  endif
endif

ifeq ($(strip $(DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT)),TRUE)
  COM_DEFS    += __DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT__
endif

ifneq ($(strip $(PLATFORM)),MT6589)
  COM_DEFS         += __FAST_FRC__
  COM_DEFS         += __STACK_ALIGN_MPU__=32
  COM_DEFS         += __THUMB2_UNIFIED__
endif

# L1 DISABLE Options
ifeq ($(strip $(ORIGINAL_PROJECT_NAME)),TK6291_FPGA)
    COM_DEFS += __L1_ISR_DISABLE__
    COM_DEFS += __L1_TASK_DISABLE__
    COM_DEFS += __L1_PCORE_TASK_DISABLE__  
    #COM_DEFS += __DUMMYMPAL_TASK_DISABLE__
endif

ifdef CUSTOMER_MODEM_LICENSE
  ifeq ($(strip $(CUSTOMER_MODEM_LICENSE)),LICENSE_LWG)
    COM_DEFS += __MODEM_PACKAGE_DISABLE_UMTS_TDD__
  endif
  ifeq ($(strip $(CUSTOMER_MODEM_LICENSE)),LICENSE_LTTG)
    COM_DEFS += __MODEM_PACKAGE_DISABLE_UMTS_FDD__
    COM_DEFS += __MODEM_PACKAGE_DISABLE_LTE_FDD__
  endif
endif
  
ifeq ($(strip $(PLMN_LIST_PREF_SUPPORT)),ON)
  COM_DEFS += __PLMN_LIST_PREF_SUPPORT__
endif

ifneq ($(filter __MTK_INTERNAL__,$(strip $(COM_DEFS))),)
  COM_DEFS    += __CATCHER_EVENT_INFO__
endif

ifeq ($(strip $(HW_PFC_SUPPORT)),TRUE)
  COM_DEFS += __HW_PFC_SUPPORT__
endif

ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
COM_DEFS  += __TX_NEW_ARCHITECTURE__
endif

ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  COMPLIST += dsp_ram
endif

ifeq ($(strip $(2G_BPI_PT3A_SUPPORT)),TRUE)
  COM_DEFS    += __2G_BPI_PT3A_SUPPORT__
endif

ifeq ($(strip $(TCM_ONLY_LOAD)),TRUE)
  COM_DEFS += __TCM_ONLY_LOAD__
endif

ifdef SPEECH_WW_OPERATOR_SCORE_ENHANCE
  ifeq ($(strip $(SPEECH_WW_OPERATOR_SCORE_ENHANCE)),TRUE)
    COM_DEFS += __SPEECH_WW_OPERATOR_SCORE_ENHANCE__
  endif
endif

ifdef LTE_GTT_SUPPORT
  ifeq ($(strip $(LTE_GTT_SUPPORT)),TRUE)
      COM_DEFS += __LTE_GTT_SUPPORT__
  endif
endif

ifdef ABB_TXDAC_CAL_ONLY_IN_FIRST_BOOT
  ifeq ($(strip $(ABB_TXDAC_CAL_ONLY_IN_FIRST_BOOT)),TRUE)
    COM_DEFS   +=__ABB_TXDAC_CAL_ONLY_IN_FIRST_BOOT__
  endif
endif

ifdef ABB_TXDAC_CAL_AUXADC2_PULL_LOW
  ifeq ($(strip $(ABB_TXDAC_CAL_AUXADC2_PULL_LOW)),TRUE)
    COM_DEFS   +=__ABB_TXDAC_CAL_AUXADC2_PULL_LOW__
  endif
endif

ifdef LWA_SUPPORT
  ifeq ($(strip $(LWA_SUPPORT)),TRUE)
      COM_DEFS += __LWA_SUPPORT__
  endif
endif

ifdef UL64QAM_SUPPORT
  ifeq ($(strip $(UL64QAM_SUPPORT)), TRUE)
    COM_DEFS += __UL64QAM__
  endif
endif

ifdef MULTIPLE_PS
  ifdef GEMINI
    ifneq ($(strip $(MULTIPLE_PS)),FALSE)
      COM_DEFS += __MULTIPLE_PS__
      COM_DEFS += MAX_CONCURRENT_PS=$(strip $(GEMINI))
    endif
  endif
endif

ifdef RSIM_SINGLE_RF_SUPPORT
  ifneq ($(strip $(RSIM_SINGLE_RF_SUPPORT)),FALSE) 
    ifneq ($(strip $(MULTIPLE_PS)),TRUE)
      $(warning ERROR: RSIM Single RF feature is based on Multiple PS feature. Please enabled MULTIPLE_PS)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef SIM_HOT_SWAP
      $(warning ERROR: SIM_HOT_SWAP is required for RSIM Single RF feature. Please enabled SIM_HOT_SWAP)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifneq ($(strip $(RSIM_SINGLE_RF_SUPPORT)),FALSE)
    COM_DEFS += __REMOTE_SIM__
  endif
endif

ifdef 2G_GMSK_EPSK_MIPI_TX_TIMING_OPTIMIZATION_SUPPORT 
  ifeq ($(strip $(2G_GMSK_EPSK_MIPI_TX_TIMING_OPTIMIZATION_SUPPORT)),TRUE)
    COM_DEFS += __2G_GMSK_EPSK_MIPI_TX_TIMING_OPTIMIZATION_SUPPORT__
  endif
endif

ifdef DHL_DISABLE_DATA_OUTPUT
  ifeq ($(strip $(DHL_DISABLE_DATA_OUTPUT)),TRUE)
    COM_DEFS     += __DHL_DISABLE_DATA_OUTPUT__
  endif
endif

ifdef 2G_MIPI_MULTI_PA_DATA_SUPPORT 
  ifeq ($(strip $(2G_MIPI_MULTI_PA_DATA_SUPPORT)),TRUE)
    COM_DEFS += __2G_MIPI_MULTI_PA_DATA_SUPPORT__
  endif
endif

ifdef 2G_STANDBY_DAC_ENHANCEMENT_ENABLE
  ifeq ($(strip $(2G_STANDBY_DAC_ENHANCEMENT_ENABLE)),TRUE) 
    COM_DEFS += __2G_STANDBY_DAC_ENHANCEMENT_ENABLE__ 
  endif
endif

ifdef 3G_BAND5_AND_BAND6_INDICATOR_SUPPORT
  ifeq ($(strip $(3G_BAND5_AND_BAND6_INDICATOR_SUPPORT)),TRUE) 
    COM_DEFS += __3G_BAND5_AND_BAND6_INDICATOR_SUPPORT__ 
  endif
endif

# *************************************************************************
# check custom folder exist or not
# *************************************************************************
ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
define CheckCusFolder
  ifneq ($(1),RF_MODULE)
    ifeq ($$(wildcard $$(call CUSTOM_FLD_MAPPING,$$(strip $(2)))),)
      $$(warning ERROR: $$(strip $(2))/$(BOARD_VER) or $(2)/_Default_BB does not exist, please help to check!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifeq ($$(wildcard $$(strip $(2))),)
      $$(warning ERROR: $$(strip $(2)) does not exist, please help to check!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endef

CUS_FLD_SYS            = ${PCORE_ROOT}/custom/system
CUS_FLD_DRV_GEN        = ${PCORE_ROOT}/custom/driver/drv_gen
CUS_FLD_PS             = ${PCORE_ROOT}/custom/modem/ps
CUS_FLD_AUDIO          = ${PCORE_ROOT}/custom/driver/audio
CUS_FLD_MISC_DRV       = ${PCORE_ROOT}/custom/driver/drv/misc_drv
CUS_FLD_META           = ${PCORE_ROOT}/custom/middleware/meta
CUS_FLD_RF             = ${PCORE_ROOT}/custom/modem/l1_rf/$(strip $(RF_MODULE))
CUS_FLD_MM_RF          = ${PCORE_ROOT}/custom/modem/mml1_rf/$(strip $(MM_RF_MODULE))
CUS_FLD_UMTS_RF        = ${PCORE_ROOT}/custom/modem/ul1_rf/$(strip $(UMTS_RF_MODULE))
CUS_FLD_UMTS_TDD128_RF = ${PCORE_ROOT}/custom/modem/tl1_rf/$(strip $(UMTS_TDD128_RF_MODULE))
CUS_FLD_LTE_RF         = ${PCORE_ROOT}/custom/modem/el1_rf/$(strip $(LTE_RF_MODULE))

$(eval $(call CheckCusFolder,OTHERS,$(strip ${CUS_FLD_SYS})))
$(eval $(call CheckCusFolder,OTHERS,$(strip ${CUS_FLD_DRV_GEN})))
$(eval $(call CheckCusFolder,OTHERS,$(strip ${CUS_FLD_PS})))
$(eval $(call CheckCusFolder,OTHERS,$(strip ${CUS_FLD_AUDIO})))
$(eval $(call CheckCusFolder,OTHERS,$(strip ${CUS_FLD_MISC_DRV})))
$(eval $(call CheckCusFolder,OTHERS,$(strip ${CUS_FLD_META})))
$(eval $(call CheckCusFolder,RF_MODULE,$(strip ${CUS_FLD_RF})))
$(eval $(call CheckCusFolder,RF_MODULE,$(strip ${CUS_FLD_MM_RF})))
$(eval $(call CheckCusFolder,RF_MODULE,$(strip ${CUS_FLD_UMTS_RF})))
$(eval $(call CheckCusFolder,RF_MODULE,$(strip ${CUS_FLD_UMTS_TDD128_RF})))
$(eval $(call CheckCusFolder,RF_MODULE,$(strip ${CUS_FLD_LTE_RF})))
endif
