##############################################################
# Define bootloader folder path
##############################################################

# Define source file lists to SRC_LIST
      SRC_LIST  = ${CORE_ROOT}/service/sys_svc/excep_hdlr/src/excep_hdlr.c
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/compression/src/lzmadec.c
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/dsp_loader/src/dsp_loader.c

ifneq ($(filter __SV5_ENABLED__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/compression/src/code_decompression_hal.c 
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/compression/src/code_decompression.c
#      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/dp/src/fault.c 
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/gfh/public/br_GFH_parser.c 
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/gfh/public/br_GFH_file_info.c 
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/ftl/src/FTL.c 
#      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/dcmgr/src/dcmgr.c
else ifneq ($(filter __SV5X_ENABLED__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/ftl/src/FTL.c 
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/gfh/public/br_GFH_parser.c 
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/gfh/public/br_GFH_file_info.c 
else
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/gfh/public/br_GFH_parser.c 
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/gfh/public/br_GFH_file_info.c 	
endif


ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/region/src/init_memory_stack.c
endif

ifneq ($(filter __VI_ENABLED__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/compression/src/viva.c
endif

SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/gfh/public/maui_GFH_body.c
      
ifeq ($(strip $(COMPILER)), GCC)
   ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/region/src/stack_gcc.S
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/region/src/regioninit_gcc.S 
   endif
else  # RVCT
   ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/region/src/stack_rvct.S 
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/region/src/regioninit_rvct.S 
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/region/src/l6478e.s
   endif
endif


ifeq ($(TS_PROFILING),TRUE)
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/profile/src/br_time_stamp.c
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/profile/src/maui_time_stamp_util.c
      SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/profile/src/time_stamp_timer.c
endif

ifneq ($(filter __LTE_RAT__, $(strip $(MODULE_DEFS))),)
       SRC_LIST +=   ${CORE_ROOT}/service/sys_svc/dspfm_lte/src/dspfm.c
endif

###################################################################
# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/interface/modem/general \
          ${CORE_ROOT}/service/sst/include \
          ${COMMON_ROOT}/service/sst/include \
          $(strip $(PROJDIR))/verno \
          ${CORE_ROOT}/service/ssf/inc \
          ${COMMON_ROOT}/service/sss/interface/inc \
          ${CORE_ROOT}/driver/drv/include \
          ${CORE_ROOT}/driver/peripheral/inc \
          ${CORE_ROOT}/driver/storage/flash/fdm/inc \
          ${COMMON_ROOT}/driver/sys_drv/cache/inc \
          ${CORE_ROOT}/driver/sys_drv/emi/inc \
          ${CORE_ROOT}/driver/sys_drv/init/inc \
          ${CORE_ROOT}/driver/regbase/inc \
          ${COMMON_ROOT}/driver/sys_drv/pmu/inc \
          ${CORE_ROOT}/service/sys_svc/region/inc \
          ${CORE_ROOT}/service/sys_svc/excep_hdlr/inc \
          ${CORE_ROOT}/service/sys_svc/gfh/public \
          ${CORE_ROOT}/service/sys_svc/compression/inc \
          ${CORE_ROOT}/service/sys_svc/profile/inc \
          ${CORE_ROOT}/service/sys_svc/dspfm_lte/inc \
          ${COMMON_ROOT}/interface/service/sst \
          ${L1CORE_ROOT}/service/sst/include \
          ${L1CORE_ROOT}/interface/service/sst 
#          ${CORE_ROOT}/service/sys_svc/dp/inc
#          ${CORE_ROOT}/service/sys_svc/dcmgr/inc 

###################################################################
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

COMP_DEFS += $(strip $(PLATFORM))


ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ifdef EMMC_BOOTING
      ifeq ($(strip $(EMMC_BOOTING)),NONE)  
        COMP_DEFS += __BL_ENABLE__
      endif
    else
      COMP_DEFS += __BL_ENABLE__
    endif
  endif
endif

ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    COMP_DEFS  += _NAND_FLASH_BOOTING_
  endif
endif

ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    COMP_DEFS  += __EMMC_BOOTING__
  endif
endif

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
  COMP_DEFS += DCM_ENABLE
endif

ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
  COMP_DEFS += SINGLE_BANK_SUPPORT
endif

ifeq ($(TS_PROFILING),TRUE)
    COMP_DEFS   +=  __TIME_STAMP__\
                    __TIME_STAMP_UTIL__\
                    __TIME_STAMP_TDMA_TIMER__\
                    __TIME_STAMP_FORCE_ENABLE__
endif

