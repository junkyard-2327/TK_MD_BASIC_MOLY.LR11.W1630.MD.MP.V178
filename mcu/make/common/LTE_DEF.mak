#------------------------------
# LTE Components
#------------------------------
ifneq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)

  ifeq ($(filter L1S,$(TEST_LOAD_TYPE)),)
    #MODEM
    ifeq ($(CORE_ROOT),$(PCORE_ROOT))
        COMPLIST += pam tft_pf upcm rohc ratdm ratdm_sec
    endif
  endif

  #COMMINCDIRS      += interface
  COMMINCDIRS      += ${PCORE_ROOT}/interface/modem/lte
  COMMINCDIRS      += ${PCORE_ROOT}/modem/interface/lte
  COMMINCDIRS      += ${COMMON_ROOT}/interface/modem/l1/lte/external
  
  COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/nwsel/nwsel/include/nwsel_trc.h
  COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/interface/modem/upcm/upcm_trc.h
  COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/nas/ratdm/include/ratdm_trc.h
  COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/nwsel/gmss/include/gmss_trc.h

  LTE_SOURCE_BUILD = FALSE
  ifneq ($(wildcard ${PCORE_ROOT}/modem/lte_sec/),)
    LTE_SOURCE_BUILD = TRUE
  endif

  ifeq ($(LTE_SOURCE_BUILD),TRUE)
    NO_LTELIB = FALSE
  endif

  #LTE sec module list
  LTE_SEC_COMP := 
  ifeq ($(strip $(LTE_DUMMY_PROTOCOL_ENABLE)),TRUE)
    #Temp add special module
    COM_DEFS += __L1EDPS_ENABLE__
    ifeq ($(CORE_ROOT),pcore)
      LTE_SEC_COMP      = l1edps
    endif
  else
    COM_DEFS += __EL2_ENABLE__ __EMM_ENABLE__ __ESM_ENABLE__ __EVAL_ENABLE__ __ERRC_ENABLE__ __ETC_ENABLE__
    ifeq ($(CORE_ROOT),pcore)     
      LTE_SEC_COMP      = el2 emm esm eval errc etc
  endif
    ifeq ($(filter L1S BASIC,$(TEST_LOAD_TYPE)),)
      ifneq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
        ifeq ($(CORE_ROOT),pcore)
          LTE_SEC_COMP += eise
        endif
      else
        ifeq ($(CORE_ROOT),l1core)
         LTE_SEC_COMP += eise
        endif
      endif
    endif
  endif
  
  ifeq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
    LTE_SEC_COMP      += el1b u4ghlsim_hw_sec u4ghlsim_l1_sec
    ifeq ($(CORE_ROOT),pcore)
      LTE_SEC_COMP      += edyn etmr
    endif
  else
    ifeq (${CORE_ROOT}, $(L1CORE_ROOT))      
      ifneq ($(strip $(LTE_EL1S_COSIM)),TRUE)      
        LTE_SEC_COMP += el1 tstm
      endif      
      COMPLIST += el1d_pub
      ifneq ($(wildcard l1core/modem/el1/el1d),)
        COMPLIST += el1d
        LTE_SEC_COMP += el1d
      else
        COMPOBJS += $(CUS_MTK_LIB)/el1d.a
      endif 
      COM_DEFS += __EL1D_ENABLE__
    else
      ifeq ($(strip $(MODIS_CONFIG)),TRUE)
        LTE_SEC_COMP += el1
      endif
      LTE_SEC_COMP += edyn etmr
      COMPLIST += el1d_ext_pcore
      ifneq ($(wildcard pcore/modem/el1/el1d),)
        COMPLIST += el1d_pcore edsphwram
        LTE_SEC_COMP += el1d_pcore edsphwram
      else
        COMPOBJS += $(CUS_MTK_LIB)/el1d_pcore.a
        COMPOBJS += $(CUS_MTK_LIB)/edsphwram.a
      endif
    endif
    ifeq ($(strip $(UE_SIMULATOR)), TRUE)
      LTE_SEC_COMP   += esim_phy 
    endif    
  endif

  #LTE Test Task Module
  ifeq ($(CORE_ROOT),pcore)
    ifeq ($(strip $(MODIS_CONFIG)),TRUE)
      ifneq ($(strip $(UE_SIMULATOR)),TRUE)
        LTE_SEC_COMP += ltt
    endif
  endif
  endif

  COM_DEFS += $(foreach mod,$(call Upper,$(LTE_SEC_COMP)), __$(mod)_ENABLE__)
  
   # TFT library trace
  COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/l4/tcm/tftlib/tftlib_dhl_trace.h

  # DSPFM trace
  COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/service/sys_svc/dspfm_lte/inc/dspfm_trace.h

  ifeq ($(strip $(ETSTM_EN)),TRUE)
      COM_DEFS += __ETSTM_ENABLE__ 
  endif

  COM_DEFS         += __MASK_L4__ __LTE_RAT__ __LTE_REL9__  
  
  ifeq ($(strip $(SIM_STANDALONE)),TRUE)
    COM_DEFS         += __SIM_STANDALONE__
    #COM_DEFS         += __USIM_UT__ 
  endif

  ifeq ($(filter L1S,$(TEST_LOAD_TYPE)),)
    #BSP
    ifeq ($(CORE_ROOT),pcore)
        COMPLIST += el1d_ext_pcore    
      ifneq ($(wildcard pcore/modem/el1/el1d),)
          COMPLIST += el1d_pcore edsphwram
          LTE_SEC_COMP += el1d_pcore edsphwram
      else
          COMPOBJS += $(CUS_MTK_LIB)/el1d_pcore.a
          COMPOBJS += $(CUS_MTK_LIB)/edsphwram.a
      endif
    endif    
    ifneq (,$(findstring __EL1_IT__,$(COM_DEFS)))
    COMPLIST += ll1_pcore
    endif
  endif
  #ifeq ($(CORE_ROOT),pcore)
    COMPLIST += l2_lte_copro
  #endif
  ifeq ($(__ESL_COSIM_LTE__),TRUE)
    ifeq ($(LTE_SOURCE_BUILD),TRUE)
      COMMINCDIRS += ${COMMON_ROOT}/interface/driver/l2copro
    endif
  endif
  COM_DEFS += __23G_PRI_RESEL_SUPPORT__
  
  ifeq ($(LTE_SOURCE_BUILD),TRUE)

    COMMINCDIRS      += ${CORE_ROOT}/modem/lte_sec
    COMMINCDIRS      += ${COMMON_ROOT}/modem/lte_sec/interface
    
    # CODEGEN PATH
    COMMINCDIRS      += ${COMMON_ROOT}/modem/lte_sec/interface/etmr
    
    COMMINCDIRS      += ${COMMON_ROOT}/modem/lte_sec/interface/eise
    
    # EL2 CODEGEN PATH
    COMMINCDIRS      += ${CORE_ROOT}/modem/lte_sec/el2/interface \
                        ${COMMON_ROOT}/modem/lte_sec/interface/el2 \
                        ${L1CORE_ROOT}/modem/lte_sec/interface
                        
    # LTE Test Mode CODEGEN PTAH
    ifneq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
       COMMINCDIRS      += $(strip $(EL1_FOLDER))/tstm/include
    endif
    
    # PS TRACE FILES
    ifneq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
       COMP_TRACE_DEFS_MODEM_LTE_SEC += $(strip $(EL1_FOLDER))/common/include/el1_trc.h \
                                        $(strip $(EL1_FOLDER))/tstm/include/test_mode_trc.h
       L1_COMP_TRACE_DEFS_MODEM_LTE_SEC += $(strip $(EL1_FOLDER))/common/include/el1_trc.h \
                                           $(strip $(EL1_FOLDER))/tstm/include/test_mode_trc.h \
                                           $(PCORE_ROOT)/modem/lte_sec/el2/interface/el2_trc.h

    endif                                     
    
    #EISE CODEGEN PATH
    ifneq ($(filter __EISE_ENABLE__ __L1EDPS_ENABLE__,$(COM_DEFS)),)
      # internal structure
      COMMINCDIRS      += ${L1CORE_ROOT}/modem/lte_sec/eise/common/include \
                          ${L1CORE_ROOT}/modem/lte_sec/eise/lcel/include \
                          ${L1CORE_ROOT}/modem/lte_sec/eise/lmob/include
      
      ifneq ($(filter TRUE,$(MODIS_CONFIG) $(UE_SIMULATOR)),)
        COMP_TRACE_DEFS_MODEM_LTE_SEC += ${L1CORE_ROOT}/modem/lte_sec/eise/lcel/include/lcel_trc.h \
                                         ${L1CORE_ROOT}/modem/lte_sec/eise/lmob/include/errc_lmob_trc.h
      else
        L1_COMP_TRACE_DEFS_MODEM_LTE_SEC += ${L1CORE_ROOT}/modem/lte_sec/eise/lcel/include/lcel_trc.h \
                                            ${L1CORE_ROOT}/modem/lte_sec/eise/lmob/include/errc_lmob_trc.h
      endif
    endif

    # L1 TRACE FILES
    ifneq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
      ifneq (,$(findstring __EL1_ENABLE__,$(COM_DEFS)))
        ifeq ($(CORE_ROOT),$(L1CORE_ROOT))
          L1_TMD_FILES_LTE_SEC += $(strip $(EL1_FOLDER))/phs/src/el1_phs_1_trace.tmd \
                                  $(strip $(EL1_FOLDER))/phs/src/el1_phs_2_trace.tmd \
                                  $(strip $(EL1_FOLDER))/phs/src/el1_phs_rtb_1_trace.tmd \
                                  $(strip $(EL1_FOLDER))/irt/src/el1_irt_1_trace.tmd \
                                  $(strip $(EL1_FOLDER))/idc/src/el1_idc_1_trace.tmd \
                                  $(strip $(EL1_FOLDER))/tx/src/el1tx_trace.tmd \
                                  $(strip $(EL1_FOLDER))/common/src/el1_main_trace.tmd \
                                  $(strip $(EL1_FOLDER))/tstm/src/el1_tstm_1_trace.tmd \
                                  $(strip $(EL1_FOLDER))/tstm/src/el1_tstm_2_trace.tmd
        endif 
        ifeq ($(strip $(MODIS_CONFIG)),TRUE)
          L1_TMD_FILES_LTE_SEC += $(strip $(EL1_FOLDER))/phs/src/el1_phs_1_trace.tmd \
                                  $(strip $(EL1_FOLDER))/phs/src/el1_phs_2_trace.tmd \
                                  $(strip $(EL1_FOLDER))/phs/src/el1_phs_rtb_1_trace.tmd \
                                  $(strip $(EL1_FOLDER))/irt/src/el1_irt_1_trace.tmd \
                                  $(strip $(EL1_FOLDER))/idc/src/el1_idc_1_trace.tmd \
                                  $(strip $(EL1_FOLDER))/tx/src/el1tx_trace.tmd \
                                  $(strip $(EL1_FOLDER))/common/src/el1_main_trace.tmd \
                                  $(strip $(EL1_FOLDER))/tstm/src/el1_tstm_1_trace.tmd
        endif 
      endif
    else
      COMP_TRACE_DEFS_MODEM_LTE_SEC += ${PCORE_ROOT}/modem/lte_sec/smt/u4gHlAdaptor/el1b/intf/el1b_trc.h
    endif

    # MBMS TRACE FILES
    ifneq (,$(findstring __EL2_ENABLE__,$(COM_DEFS)))
      ifeq ($(strip $(MODIS_CONFIG)),TRUE)
        ifeq ($(CORE_ROOT),$(PCORE_ROOT))
          L1_TMD_FILES_LTE_SEC += ${L1CORE_ROOT}/modem/lte_sec/el2/emac/src/el2_mbms_trace.tmd
        endif
      endif
    endif
    ifneq (,$(findstring __EL1_ENABLE__,$(COM_DEFS)))
      ifneq ($(strip $(MODIS_CONFIG)),TRUE)
        ifeq ($(CORE_ROOT),$(L1CORE_ROOT))
          L1_TMD_FILES_LTE_SEC += ${L1CORE_ROOT}/modem/lte_sec/el2/emac/src/el2_mbms_trace.tmd
        endif
      endif
    endif
    
    # L2 TRACE FILES (re-use L1_TMD_FILES_LTE_SEC)
    ifeq (${CORE_ROOT},${PCORE_ROOT})
      L1_TMD_FILES_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/edyn/src/edata_path_trace.tmd
      L1_TMD_FILES_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/edyn/src/edata_path_detail_trace.tmd
    
      ifneq (,$(findstring __L1EDPS_ENABLE__,$(COM_DEFS)))
        COMP_TRACE_DEFS_MODEM_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/el2/interface/el2_trc.h
      endif

      # L2 TRACE FILES (re-use L1_TMD_FILES_LTE_SEC)
      ifneq (,$(findstring __L1EDPS_ENABLE__,$(COM_DEFS)))
        COMP_TRACE_DEFS_MODEM_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/el2/interface/el2_trc.h
      endif
      
      ifneq (,$(findstring __EL2_ENABLE__,$(COM_DEFS)))
        COMP_TRACE_DEFS_MODEM_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/el2/interface/el2_trc.h

        L1_TMD_FILES_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/el2/erlcul/erlcul_trace.tmd \
                              ${CORE_ROOT}/modem/lte_sec/el2/erlcul/erlcul_detail_trace.tmd \
                              ${CORE_ROOT}/modem/lte_sec/el2/erlcdl/erlcdl_trace.tmd \
                              ${CORE_ROOT}/modem/lte_sec/el2/erlcdl/erlcdl_detail_trace.tmd \
                              ${CORE_ROOT}/modem/lte_sec/el2/emac/src/emac_trace.tmd \
                              ${CORE_ROOT}/modem/lte_sec/el2/emac/src/emac_detail_trace.tmd \
                              ${CORE_ROOT}/modem/lte_sec/el2/epdcp/src/epdcp_trace.tmd \
                              ${CORE_ROOT}/modem/lte_sec/el2/epdcp/src/epdcp_detail_trace.tmd
      endif
    endif
    
    # L1-TX TRACE FILES
    ifneq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
    ifneq (,$(findstring __EL1TX_ENABLE__,$(COM_DEFS)))
        ifeq ($(CORE_ROOT),$(L1CORE_ROOT))
            L1_TMD_FILES_LTE_SEC += $(strip $(EL1_FOLDER))/tx/src/el1tx_trace.tmd
        endif
    endif
    endif
      
    # MT6290 FPGA setting
    ifeq ($(strip $(MT6290_FIRST_CALL)),TRUE)
      ifneq ($(strip $(MODIS_CONFIG)),TRUE)
        COM_DEFS       += __MT6290_FIRST_CALL__
      endif
    endif
    ifeq ($(strip $(MT6290E2_FIRST_CALL)),TRUE)
      ifneq ($(strip $(MODIS_CONFIG)),TRUE)
        COM_DEFS       += __MT6290E2_FIRST_CALL__
      endif
    endif
    ifeq ($(strip $(MT6290_FPGA)),TRUE)
      COM_DEFS       += __MT6290_FPGA__
    endif

    ifeq ($(strip $(LTE_DUMMY_PROTOCOL_ENABLE)),TRUE)
      COMMINCDIRS      += ${CORE_ROOT}/modem/lte_sec/l1edps/include/internal \
                          ${PCORE_ROOT}/interface/modem/lte 
    endif
    
    # ERRC CODEGEN PATH
    # external structure
    ifneq ($(filter __ERRC_ENABLE__ __L1EDPS_ENABLE__,$(COM_DEFS)),)
      COMMINCDIRS      += ${COMMON_ROOT}/modem/lte_sec/interface/el2 \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/interface \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/common/include
      # internal structure
      COMMINCDIRS      += ${CORE_ROOT}/modem/lte_sec/errc/cel/include \
                          ${CORE_ROOT}/modem/lte_sec/errc/conn/include \
                          ${CORE_ROOT}/modem/lte_sec/errc/chm/include \
                          ${CORE_ROOT}/modem/lte_sec/errc/sys/include \
                          ${CORE_ROOT}/modem/lte_sec/errc/rcm/include \
                          ${CORE_ROOT}/modem/lte_sec/errc/mob/include \
                          ${CORE_ROOT}/modem/lte_sec/errc/spv/include \
                          ${CORE_ROOT}/modem/lte_sec/errc/evth/include
      # trace file path
      COMP_TRACE_DEFS_MODEM_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/errc/evth/include/errc_evth_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/errc/conn/include/errc_conn_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/errc/chm/include/errc_chm_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/errc/sys/include/errc_sys_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/errc/rcm/include/errc_rcm_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/errc/mob/include/errc_mob_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/errc/cel/include/errc_cel_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/errc/spv/include/errc_spv_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/errc/common/include/errc_trc.h
     L1_COMP_TRACE_DEFS_MODEM_LTE_SEC += $(L1CORE_ROOT)/modem/lte_sec/el1/ch/include/el1_ch_api.h
    endif
   
    # ESM CODEGEN PATH
    ifneq (,$(findstring __ESM_ENABLE__,$(COM_DEFS)))
      COMMINCDIRS      += ${CORE_ROOT}/modem/lte_sec/enas/esm \
                          ${COMMON_ROOT}/modem/lte_sec/interface/ltm_multi
                          
      COMP_TRACE_DEFS_MODEM_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/enas/esm/esm_dhl_trace.h
      COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/modem/nas/pam/pam_trc.h
    endif

    # ETC CODEGEN PATH
    ifneq (,$(findstring __ETC_ENABLE__,$(COM_DEFS)))
      COMMINCDIRS      += ${CORE_ROOT}/modem/lte_sec/enas/etc/include
    
      COMP_TRACE_DEFS_MODEM_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/enas/etc/include/etc_trc.h
    endif

    ifneq (,$(findstring __EMM_ENABLE__,$(COM_DEFS)))
      # EMM CODEGEN PATH
      COMMINCDIRS      += ${CORE_ROOT}/modem/lte_sec/enas/emm/interface \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/common/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/evtctrl/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/plmnsel/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/sv/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/ratband/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/call/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/conn/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/nasmsg/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/opidsrv/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/sec/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/reg/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/nmsrv/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/usimsrv/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/nvmsrv/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/cmnproc/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/errcif/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/etcif/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/ratchg/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/evalif/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/esmif/include \
                          ${CORE_ROOT}/modem/lte_sec/enas/emm/mmif \
                          $(CORE_ROOT)/modem/lte_sec/enas/emm/timersrv/include


      COMP_TRACE_DEFS_MODEM_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/enas/emm/evtctrl/include/emm_evtctrl_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/plmnsel/include/emm_plmnsel_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/conn/include/emm_conn_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/nasmsg/include/emm_nasmsg_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/opidsrv/include/emm_opidsrv_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/sec/include/emm_sec_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/call/include/emm_call_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/common/include/emm_dhl_trace.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/reg/include/emm_reg_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/nmsrv/include/emm_nmsrv_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/usimsrv/include/emm_usimsrv_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/nvmsrv/include/emm_nvmsrv_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/cmnproc/include/emm_cmnproc_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/errcif/include/emm_errcif_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/sv/include/emm_sv_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/etcif/include/emm_etcif_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/ratband/include/emm_ratband_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/ratchg/include/emm_ratchg_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/evalif/include/emm_evalif_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/esmif/include/emm_esmif_trc.h \
                                       ${CORE_ROOT}/modem/lte_sec/enas/emm/mmif/include/emm_mmif_trc.h
    endif
    
    # EVAL trace
    COMMINCDIRS      += ${CORE_ROOT}/modem/lte_sec/enas/eval/include
    COMP_TRACE_DEFS_MODEM_LTE_SEC += ${CORE_ROOT}/modem/lte_sec/enas/eval/include/eval_trc.h
  
    COMPLIST         += $(LTE_SEC_COMP)
  else
      COMPOBJS += $(call sort,$(foreach lib,$(LTE_SEC_COMP),$(CUS_MTK_LIB)/$(lib).a))
  endif#ifeq ($(LTE_SOURCE_BUILD),TRUE)

endif

ifeq ($(LTE_SOURCE_BUILD),TRUE)
  ifeq ($(CORE_ROOT),$(PCORE_ROOT))
    COMMINCDIRS      += ${CORE_ROOT}/interface/driver/hif
    COMMINCDIRS      += ${CORE_ROOT}/interface/driver/hif/hif_usbdev
    COMMINCDIRS      += ${CORE_ROOT}/interface/driver/hif/hif_sdiodev
    COMMINCDIRS      += ${CORE_ROOT}/interface/driver/hif/hif_cldmadev
    COMMINCDIRS      += ${CORE_ROOT}/interface/driver/devdrv/coresight
  endif
  ifeq ($(strip $(UE_SIMULATOR)), TRUE)  
    COMMINCDIRS      += ${CORE_ROOT}/interface/driver/devdrv/hif/
    COMMINCDIRS      += ${CORE_ROOT}/interface/driver/devdrv/hif/hif_usbdev
    COMMINCDIRS      += ${CORE_ROOT}/interface/driver/devdrv/hif/hif_sdiodev
    COMMINCDIRS      += ${CORE_ROOT}/interface/driver/devdrv/hif/hif_cldmadev 
  endif
endif

ifdef OS_TICK_PERIOD_IN_US
  COM_DEFS      += OS_TICK_PERIOD_US=$(strip $(OS_TICK_PERIOD_IN_US))
endif

ifeq ($(strip $(HIF_USB_SUPPORT)),TRUE)
  COM_DEFS += __CREATE_USB_HISR__
endif

ifeq ($(strip $(HIF_SDIO_SUPPORT)),TRUE)
  COM_DEFS      += __CREATE_SDIO_HISR__
endif

ifeq ($(strip $(SYS_TEST_EMSC_ENABLE)),TRUE)
  COM_DEFS      += SYS_TEST_EMSC_ENABLE
endif

ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  include make/${COMMON_ROOT}/hif_main.mak
else
  ifeq ($(ORIGINAL_FLAVOR),BASIC_HIF)
    include make/${COMMON_ROOT}/hif_main.mak
  else
    COMMINCDIRS += ${PCORE_ROOT}/interface/middleware/hif
  endif
endif
