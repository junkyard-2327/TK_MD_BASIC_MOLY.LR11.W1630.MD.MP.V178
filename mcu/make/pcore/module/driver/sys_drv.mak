##############################################################
# Define bootloader folder path
##############################################################

# Define source file lists to SRC_LIST
SRC_LIST =          ${COMMON_ROOT}/driver/sys_drv/cache/src/cache.c \
                    ${CORE_ROOT}/driver/sys_drv/init/src/idle_task.c
#                    ${CORE_ROOT}/driver/sys_drv/init/src/info.c
#                    ${COMMON_ROOT}/driver/sys_drv/pmu/src/arm11_pmu_montr.c \
#                    ${CORE_ROOT}/driver/sys_drv/init/src/nfb_loader.c \

ifeq ($(strip $(ESL_COSIM_LTE)),FALSE)
  ifeq ($(strip $(COMPILER)),GCC)
	CFLAGS += -Werror
  endif
endif

ifneq ($(filter __EVENT_BASED_TIMER__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/timer/src/event_timer.c
endif

ifneq ($(filter __DSP_FCORE4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/driver/sys_drv/init/src/dmdsp_init.c
endif

ifneq ($(filter __SMART_PHONE_MODEM__ , $(strip $(MODULE_DEFS))),)
#      SRC_LIST +=   ${CORE_ROOT}/driver/sys_drv/emi/src/emimpu.c
endif

ifeq ($(filter __SMART_PHONE_MODEM__, $(strip $(MODULE_DEFS))),)
#      SRC_LIST +=   ${CORE_ROOT}/driver/sys_drv/emi/src/emi.c
else
#      SRC_LIST +=   ${CORE_ROOT}/driver/sys_drv/emi/src/emi.c
endif

ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __DSP_FCORE4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/driver/sys_drv/ipc/src/mdci.c
  endif
endif


ifneq ($(filter __MCU_DORMANT_MODE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST   += ${COMMON_ROOT}/driver/sys_drv/dormant/src/dormant_service.c
  ifneq ($(filter MT6290, $(strip $(MODULE_DEFS))),)
      SRC_LIST += ${COMMON_ROOT}/driver/sys_drv/dormant/src/mt6290_dormant_entry.S
  endif
endif

ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/driver/sys_drv/init/src/init.c 
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/init/src/init_comm.c 
      SRC_LIST +=   ${CORE_ROOT}/driver/sys_drv/init/src/init_trc.c 
#      SRC_LIST +=   ${CORE_ROOT}/driver/sys_drv/init/src/boot_cert_pattern.c 
endif

ifeq ($(strip $(COMPILER)), GCC)
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/cache/src/cp15_gcc.S
   ifneq ($(filter __ARM_FPUV2__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/vfp/src/vfp_gcc.S
   endif
   ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/driver/sys_drv/init/src/bootarm_gcc.S
   endif
 ifneq ($(filter __MCU_DORMANT_MODE__, $(strip $(MODULE_DEFS))),)
   ifneq ($(filter __ARM1176__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += ${COMMON_ROOT}/driver/sys_drv/dormant/src/arm1176-dormantMode_gcc.S 
   endif
   ifneq ($(filter __CR4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += ${COMMON_ROOT}/driver/sys_drv/dormant/src/cortexr4-dormantMode_gcc.S 
   endif
 endif
else  # RVCT
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/cache/src/cp15_rvct.S
   ifneq ($(filter __ARM_FPUV2__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/vfp/src/vfp_rvct.S
   endif         
   ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${CORE_ROOT}/driver/sys_drv/init/src/bootarm_rvct.S 
   endif
 ifneq ($(filter __MCU_DORMANT_MODE__, $(strip $(MODULE_DEFS))),)
   ifneq ($(filter __ARM1176__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += ${COMMON_ROOT}/driver/sys_drv/dormant/src/arm1176-dormantMode_rvct.s 
   endif
   ifneq ($(filter __CR4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += ${COMMON_ROOT}/driver/sys_drv/dormant/src/cortexr4-dormantMode_rvct.s 
   endif
 endif
endif

ifneq ($(filter __ARM9_MMU__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/cache/src/mmu.c
endif

ifneq ($(filter __ARM11_MMU__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/cache/src/mmu.c
endif

ifneq ($(filter __CR4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/cache/src/mpu.c
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/pmu/src/cr4_pmu_montr.c
endif

ifneq ($(filter __MTK_MMU_V2__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/cache/src/mpu_mtk_mmu_v2_int.c
endif


###################################################################
# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/interface/modem/general \
          ${CORE_ROOT}/service/sst/include \
          ${COMMON_ROOT}/service/sst/include \
          $(strip $(PROJDIR))/verno \
          ${COMMON_ROOT}/service/sss/interface/inc \
          ${CORE_ROOT}/driver/drv/include \
          ${CORE_ROOT}/driver/peripheral/inc \
          ${CORE_ROOT}/driver/storage/flash/fdm/inc \
          ${COMMON_ROOT}/driver/sys_drv/cache/inc \
          ${COMMON_ROOT}/driver/sys_drv/init/inc \
          ${CORE_ROOT}/driver/devdrv/bus/inc \
          ${CORE_ROOT}/driver/sys_drv/emi/inc \
          ${CORE_ROOT}/driver/sys_drv/init/inc \
          ${CORE_ROOT}/driver/regbase/inc \
          ${COMMON_ROOT}/driver/sys_drv/pmu/inc \
          ${CORE_ROOT}/service/sys_svc/region/inc \
          ${CORE_ROOT}/service/sys_svc/dp/inc \
          ${CORE_ROOT}/service/sys_svc/dcmgr/inc \
          ${CORE_ROOT}/service/sys_svc/excep_hdlr/inc \
          ${CORE_ROOT}/service/sys_svc/gfh/public \
          ${CORE_ROOT}/service/sys_svc/compression/inc \
          ${CORE_ROOT}/service/sys_svc/profile/inc \
          ${CORE_ROOT}/service/sys_svc/dspfm_lte/inc \
          ${CORE_ROOT}/driver/devdrv/emi/inc \
          ${COMMON_ROOT}/driver/devdrv/iomux/inc	\
          ${CORE_ROOT}/driver/devdrv/cfgctl/inc \
          ${COMMON_ROOT}/driver/sys_drv/dormant/inc \
          ${COMMON_ROOT}/driver/sys_drv/dormant/src \
          ${CORE_ROOT}/interface/service/sys_svc \
          ${COMMON_ROOT}/interface/service/sst \
          ${CORE_ROOT}/interface/driver/devdrv/mdipc \
          ${CORE_ROOT}/driver/devdrv/rstctl/inc \
          ${COMMON_ROOT}/interface/driver/devdrv/ect
          

ifeq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
    INC_DIR += ${L1CORE_ROOT}/modem/gl1/common \
               ${L1CORE_ROOT}/modem/gl1/interface \
               ${L1CORE_ROOT}/modem/gl1/l1c \
               ${L1CORE_ROOT}/modem/gl1/l1d \
               ${L1CORE_ROOT}/modem/gl1/l1d_ext \
               ${COMMON_ROOT}/modem/interface/l1/gsm \
               ${COMMON_ROOT}/modem/interface/l1/inner \
    ${L1CORE_ROOT}/modem/interface/l1/inner \
    ${CORE_ROOT}/modem/interface/l1/inner \
               ${L1CORE_ROOT}/modem/md_sm/l1sm \
               ${L1CORE_ROOT}/modem/md_sm/common/l1sm
endif


ifneq ($(filter __ESL_COSIM_LTE__, $(strip $(MODULE_DEFS))),)
    INC_DIR += ${CORE_ROOT}/driver/devdrv/hsl/inc
endif

###################################################################
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

COMP_DEFS += $(strip $(PLATFORM))

ifneq ($(filter __MCU_DORMANT_MODE__, $(strip $(MODULE_DEFS))),)
    COMP_DEFS  += CACHE_FLUSH_IN_DORMANT=1
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

ifeq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
    COMP_DEFS   +=  L1_SIM
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  INC_DIR += ${COMMON_ROOT}/interface/service/hif \
    ${CORE_ROOT}/interface/service/hif
endif
