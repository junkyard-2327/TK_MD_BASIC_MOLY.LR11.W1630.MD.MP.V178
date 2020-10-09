#
# HIF service interface exported to other catagories (e.g. modem)
#
COMMINCDIRS += ${COMMON_ROOT}/interface/service/hif
COMMINCDIRS += ${PCORE_ROOT}/interface/service/hif

#
# HIF service common components
#
ifneq (${CORE_ROOT},l1core)
  COMPLIST         += hmu
  COM_DEFS         += __HMU_ENABLE__
  ifneq ($(ORIGINAL_FLAVOR),BASIC_HIF)
    COMPLIST         += hmu_sec
  endif
endif
COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/service/hif/hmu/include/hmu_trace.h

#
# HIF middleware interface exported to other catagories (e.g. modem)
#
COMMINCDIRS += ${PCORE_ROOT}/interface/middleware/hif

#
# HIF middleware common compnents
#
ifneq (${CORE_ROOT},l1core)
  ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifneq ($(ORIGINAL_FLAVOR),BASIC_HIF)
      COMPLIST         += nmu
      COM_DEFS         += __NMU_ENABLE__
      COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/nmu/core/inc/nmu_trace.h
      COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/nmu/dhcp4c/include/dhcp4c_trace.h
      COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/nmu/ndpc/include/ndpc_trace.h
    endif
  endif
endif

ifneq (${CORE_ROOT},l1core)
  ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifneq ($(ORIGINAL_FLAVOR),BASIC_HIF)
      COMPLIST         += ipcore
      COMPLIST         += tmc
      COM_DEFS         += __IPCORE_SUPPORT__
      COM_DEFS         += __TMC_SUPPORT__
      COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/ipcore/include/ipc_trace.h
      COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/tmc/include/tmc_trace.h
    endif
  endif
endif

#
# HIF data path trace log
#
ifneq (${CORE_ROOT},l1core)
  COMMON_TMD_FILES	+= ${CORE_ROOT}/driver/hif_drv/src/hif_drv_data_path_trace.tmd
  COMMON_TMD_FILES	+= ${CORE_ROOT}/middleware/hif/interface/hif_mw_data_path_trace.tmd
  COMMON_TMD_FILES	+= ${CORE_ROOT}/service/hif/interface/hif_srv_data_path_trace.tmd
endif

#COM_DEFS	+= __TTY_UT__
#COM_DEFS	+= __EXCEPT_TTY_UT__

#
# HIF dependent makefile
#
ifdef HIF_AOMGR_SUPPORT
  ifeq ($(strip $(HIF_AOMGR_SUPPORT)), TRUE)
    COM_DEFS        += __HIF_AOMGR_SUPPORT__
    COMPLIST        += aomgr
    COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/aomgr/include/aomgr_trace.h
  endif
endif

ifdef HIF_USB_SUPPORT
ifeq ($(strip $(HIF_USB_SUPPORT)), TRUE)
  #
  # USB common compiler option
  #
  COM_DEFS         += __HIF_USB_SUPPORT__
  
  #
  # USB common components
  #
  ifneq (${CORE_ROOT},l1core)
    COMPLIST         += usbcore
    COMPLIST         += usbidle
    COM_DEFS         += __USBCORE_SUPPORT__
    COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/usbcore/include/usbcore_trace.h
  
    COMPLIST         += usbclass
    COM_DEFS         += __USBCLASS_SUPPORT__
    COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/usbclass/task/include/ucd_trace.h
  endif
  #
  # USB Class specific makefile macro and compiler option
  #
  ifdef USB_ACM_SUPPORT
    ifeq ($(strip $(USB_ACM_SUPPORT)), TRUE)
         COM_DEFS += __USB_ACM_SUPPORT__
         COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/usbclass/acm/include/cdcacm_trace.h
    endif
  endif
  
  ifdef USB_RNDIS_SUPPORT
    ifeq ($(strip $(USB_RNDIS_SUPPORT)), TRUE) 
       COM_DEFS += __USB_RNDIS_SUPPORT__
       COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/middleware/hif/usbclass/rndis/include/rndis_trace.h
  
       # RNDIS needs to attach with ETHERCORE
       ETHERCORE_SUPPORT = TRUE
    endif
  endif

  ifdef USB_ECM_SUPPORT
    ifeq ($(strip $(USB_ECM_SUPPORT)), TRUE) 
       COM_DEFS += __USB_ECM_SUPPORT__
       COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/middleware/hif/usbclass/ecm/include/cdcecm_trace.h

       # ECM needs to attach with ETHERCORE
       ETHERCORE_SUPPORT = TRUE
    endif
  endif
 
  ifdef USB_MBIM_SUPPORT
    ifeq ($(strip $(USB_MBIM_SUPPORT)), TRUE) 
         COM_DEFS += __USB_MBIM_SUPPORT__
         COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/middleware/hif/usbclass/mbim/include/mbim_trace.h
    endif
  endif

  ifdef USB_MSD_SUPPORT
    ifeq ($(strip $(USB_MSD_SUPPORT)), TRUE) 
         COM_DEFS += __USB_MSD_SUPPORT__
         COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/middleware/hif/usbclass/msd/include/ms_trace.h
    endif
  endif
  
  ifdef USB_OSD_SUPPORT
    ifeq ($(strip $(USB_OSD_SUPPORT)), TRUE)
      COMPLIST        += usbosd
      COM_DEFS        += __USB_OSD_SUPPORT__
      COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/middleware/hif/usbosd/include/usbosd_trace.h
    endif
  endif

endif
endif

ifneq ($(CORE_ROOT),l1core)
ifdef HIF_CLDMA_SUPPORT
  ifeq ($(strip $(HIF_CLDMA_SUPPORT)), TRUE)
    #
    # CLDMA common compiler option
    #
    COM_DEFS         += __HIF_CLDMA_SUPPORT__
    
    #
    # CLDMA common components
    #
    COMPLIST         += cldmacore
    COM_DEFS         += __CLDMACORE_SUPPORT__ 
    #COM_DEFS         += __CLDMAIPC_SUPPORT__
	  COMPLIST += cldmadev
	  
    #
    # CLDMA common Include Path
    #
    INC_DIR = ${CORE_ROOT}/driver/regbase/inc            \
          ${CORE_ROOT}/driver/hif/inc/hif_cldmadev

    COMMINCDIRS += ${CORE_ROOT}/interface/driver/cldmacore
  endif
endif
endif

ifneq (${CORE_ROOT},l1core)
ifdef HIF_CCIF_SUPPORT
  ifeq ($(strip $(HIF_CCIF_SUPPORT)), TRUE)
    #
    # CCIF common compiler option
    #
    COM_DEFS         += __HIF_CCIF_SUPPORT__
    
    #
    # CCIF common components
    #
    #COMPLIST         += ccifcore
    #COM_DEFS         += __CCIFCORE_SUPPORT__
    COMPLIST += ccifdev
ifdef HIF_USB_SUPPORT
ifeq ($(strip $(HIF_USB_SUPPORT)), FALSE)  
    COM_DEFS         += __CCIFTTY_SUPPORT__ 
endif
else
    COM_DEFS	     += __CCIFTTY_SUPPORT__
endif

    COM_DEFS         += __CCIFGPD_SUPPORT__ 

    #
    # CCIF common Include Path
    #
    INC_DIR = ${CORE_ROOT}/driver/regbase/inc            \
          ${CORE_ROOT}/driver/hif/inc/hif_ccif

    COMMINCDIRS += ${CORE_ROOT}/interface/driver/ccifcore
  endif
endif
endif

ifdef HIF_WCCIF_SUPPORT
  ifeq ($(strip $(HIF_WCCIF_SUPPORT)), TRUE)
    ifneq ($(CORE_ROOT),l1core)
    #
    # CCIF common compiler option
    #
    COM_DEFS         += __HIF_WCCIF_SUPPORT__
    COMPLIST += wccifdev
    #
    # CCIF common components
    #
    #COMPLIST         += wccifcore
    ifeq ($(strip $(HIF_CLDMA_SUPPORT)), FALSE)
      COM_DEFS         += __CCIFCORE_SUPPORT__  __CCIFRX_HISR_DISABLE__
      COMPLIST += ccifcore
    endif
    #
    # CCIF common Include Path
    #
    INC_DIR = ${CORE_ROOT}/driver/regbase/inc            \
          ${CORE_ROOT}/driver/hif/inc/hif_ccif

    #COMMINCDIRS += ${CORE_ROOT}/interface/driver/wccifcore
    endif
  endif
endif

ifdef HIF_PCCIF_ARM7_SUPPORT
  ifeq ($(strip $(HIF_PCCIF_ARM7_SUPPORT)), TRUE)
    ifneq ($(CORE_ROOT),l1core)
    #
    # PCCIF common compiler option
    #
    COM_DEFS         += __HIF_PCCIF_ARM7_SUPPORT__
    COMPLIST += pccifdev
    #
    # PCCIF common components
    #
    #COMPLIST         += wccifcore
    #ifeq ($(strip $(HIF_CLDMA_SUPPORT)), FALSE)
    #  COM_DEFS         += __CCIFCORE_SUPPORT__  __CCIFRX_HISR_DISABLE__
    #  COMPLIST += ccifcore
    #endif
    #
    # PCCIF common Include Path
    #
    INC_DIR = ${CORE_ROOT}/driver/regbase/inc            \
          ${CORE_ROOT}/driver/hif/inc/hif_pccif
    #COMMINCDIRS += ${CORE_ROOT}/interface/driver/wccifcore
    endif
  endif
endif

ifneq ($(CORE_ROOT),l1core)
ifdef HIF_CCISM_SUPPORT
  ifeq ($(strip $(HIF_CCISM_SUPPORT)), TRUE)
    #
    # CCISM common compiler option
    #
    COM_DEFS         += __HIF_CCISM_SUPPORT__

    #
    # CCISM common components
    #
    COMPLIST         += ccismcore
    COM_DEFS         += __CCISMCORE_SUPPORT__

    #
    # CCISM IT
    #
    #COM_DEFS         += __CCISMCORE_IT__
    #COM_DEFS         += __CCISMCORE_IT_BUFF__
    #COM_DEFS         += __CCISMCORE_IT_TTY__

    COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/driver/ccismcore/include/ccismcore_trace.h

    #
    # CCISM interface exported to other catagories (e.g. service/CCCI)
    #
    COMMINCDIRS += ${CORE_ROOT}/interface/driver/ccismcore
  endif
endif
endif

ifdef HIF_UART_SUPPORT
  ifeq ($(strip $(HIF_UART_SUPPORT)), TRUE)
    #
    # UART common compiler option
    #
    COM_DEFS		+= __HIF_UART_SUPPORT__

    #
    # UART common components
    #
    ifneq (${CORE_ROOT},l1core)
    COMPLIST		+= uartcore
    COM_DEFS		+= __UARTCORE_SUPPORT__
    endif
  endif
endif

#
# HIF optional components
#
ifdef ETHERCORE_SUPPORT
  ifeq ($(strip $(ETHERCORE_SUPPORT)), TRUE)
    ifneq (${CORE_ROOT},l1core)
      COMPLIST         += ethercore
    endif
    COM_DEFS += __ETHERCORE_SUPPORT__
  endif
endif

ifneq (${CORE_ROOT},l1core)
ifdef LTM_SIMULATION_SUPPORT
  ifeq ($(strip $(LTM_SIMULATION_SUPPORT)), TRUE)
       COMPLIST         += ltm_sim
       COM_DEFS         += __LTM_SIMULATION_SUPPORT__
  endif
endif
endif

ifdef HIF_SDIO_SUPPORT
  ifeq ($(strip $(HIF_SDIO_SUPPORT)), TRUE)
    #
    # SDIO common compiler option
    #
    COM_DEFS         += __HIF_SDIO_SUPPORT__
    
    #
    # SDIO common components
    #
    COMPLIST         += sdiocore
    COM_DEFS         += __SDIOCORE_SUPPORT__
    
    COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/driver/sdiocore/include/sdiocore_trace.h

	#
	# SDIO interface exported to other catagories (e.g. ${CORE_ROOT}/service/CCCI)
	#
    COMMINCDIRS += ${CORE_ROOT}/interface/driver/sdiocore
  endif
endif

ifeq (${CORE_ROOT},l1core)
	ifdef HIF_CCCI_SUPPORT
	  ifeq ($(strip $(HIF_CCCI_SUPPORT)), TRUE)
	    COM_DEFS         += __HIF_CCCI_SUPPORT__
	  endif
	  ifdef CCCI_DEV_SUPPORT
		ifeq ($(strip $(CCCI_DEV_SUPPORT)), TRUE)
		  COMPLIST         += cccisrv
		  COM_DEFS         += __CCCIDEV_SUPPORT__ __CCCIIPC_SUPPORT__ __CCCIRPC_SUPPORT__ __CCCIMSG_SUPPORT__
          L1_COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/service/hif/cccisrv/ccci_ipc/include/ccci_ipc_trace.h
          L1_COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/service/hif/cccisrv/ccci_rpc/include/ccci_rpc_trace.h		  
          L1_COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/service/hif/cccisrv/cccisrv_task/include/cccisrv_trace.h
          L1_COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/service/hif/cccisrv/ccci_sys_msg/include/ccci_sys_msg_trace.h
		endif
	  endif  
	endif
else
	ifdef HIF_CCCI_SUPPORT
	  ifeq ($(strip $(HIF_CCCI_SUPPORT)), TRUE)
		#
		# CCCI common compiler option
		#
		COM_DEFS         += __HIF_CCCI_SUPPORT__
		
		#
		# CCCI common components
		#
		COMPLIST         += ccci
		COM_DEFS         += __CCCI_SUPPORT__
		
		#
		# For CCCI MT6575 loopback test
		#
		#COM_DEFS         += __CCCI_LB_IT__  #conflict with __CCCI_FS_IT__
		
		COMP_TRACE_DEFS_MODEM += ${CORE_ROOT}/service/hif/ccci/include/ccci_trace.h
	  endif
	  
	  ifdef CCCI_DEV_SUPPORT
		ifeq ($(strip $(CCCI_DEV_SUPPORT)), TRUE)
		  COMPLIST         += cccidev cccisrv
		  COM_DEFS         += __CCCIDEV_SUPPORT__ __CCCITTY_SUPPORT__ __CCCIIPC_SUPPORT__ __CCCIRPC_SUPPORT__
	  
		   #
		   # For CCCI_FS/EMCS IT 
		   #
		   #COM_DEFS         += __CCCI_FS_IT__  #conflict with __CCCI_LB_IT__

		   #
		   # For CCCI_TTY IT 
		   #
		   #COM_DEFS         += __CCCI_TTY_IT__  #conflict with __CCCI_LB_IT__

		   #
		   # For CCCI IT MODE CONTROL
		   #
		   #COM_DEFS		 += __CCCI_IT_CTRL__ CCCI_IT_MODE_CONTROL_CCCI_IPC CCCI_IT_MODE_CONTROL_CCCI_RPC

		  COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/cccidev/cccidev_task/include/cccidev_trace.h
		  COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/cccidev/ccci_tty/include/cccitty_trace.h
		  COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/service/hif/cccisrv/ccci_ipc/include/ccci_ipc_trace.h
		  COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/service/hif/cccisrv/ccci_rpc/include/ccci_rpc_trace.h
		  COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/service/hif/cccisrv/cccisrv_task/include/cccisrv_trace.h
		  COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/service/hif/cccisrv/ccci_sys_msg/include/ccci_sys_msg_trace.h
		  #RPC IPC shall add here like ccci_fs

		  ifdef CCCI_FS_SUPPORT
			ifeq ($(strip $(CCCI_FS_SUPPORT)), TRUE)
			  COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/service/hif/cccisrv/ccci_fs/include/ccci_fs_trace.h
			endif
		  endif  
		  #	
		  # CCMNI
		  # if not ROUTER MODE enable CCMNI 
		  #
		  ifdef CCCI_CCMNI_SUPPORT
			 ifeq ($(strip $(CCCI_CCMNI_SUPPORT)), TRUE)
				COM_DEFS   += __CCCICCMNI_SUPPORT__

				#
				# For CCCI_CCMNI/EMCS IT 
				#
				#COM_DEFS         += __CCMNI_IT__ __CCCI_IT_CTRL__ CCCI_IT_MODE_CONTROL_CCCI_CCMNI

				COMP_TRACE_DEFS_MODEM  += ${CORE_ROOT}/middleware/hif/cccidev/ccci_ccmni/include/ccmni_trace.h
			 endif    
		  endif	
	   
		endif
	  endif
	endif
endif

#
# HIF Latency Trace
#
COMPLIST         += hlt
COM_DEFS         += __HLT_SUPPORT__
ifeq (${CORE_ROOT},pcore)
  COMP_TRACE_DEFS_MODEM  += ${COMMON_ROOT}/service/hif/hlt/include/hlt_trace.h
endif
ifeq (${CORE_ROOT},l1core)
  L1_COMP_TRACE_DEFS_MODEM += ${COMMON_ROOT}/service/hif/hlt/include/hlt_trace.h
endif

