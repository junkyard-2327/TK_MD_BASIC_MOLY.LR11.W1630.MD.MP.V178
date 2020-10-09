##############################################################
# Define bootloader folder path
##############################################################

# Define source file lists to SRC_LIST
SRC_LIST =          ${COMMON_ROOT}/driver/sys_drv/cache/src/cache.c \
                    ${CORE_ROOT}/driver/sys_drv/init/src/idle_task.c
#                    ${CORE_ROOT}/driver/sys_drv/init/src/info.c
#                    ${COMMON_ROOT}/driver/sys_drv/pmu/src/arm11_pmu_montr.c \
#                    ${CORE_ROOT}/driver/sys_drv/init/src/nfb_loader.c \

ifeq ($(strip $(COMPILER)),GCC)
	CFLAGS += -Werror
endif


ifneq ($(filter __EVENT_BASED_TIMER__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/timer/src/event_timer.c
endif

ifneq ($(filter __MCU_DORMANT_MODE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += ${COMMON_ROOT}/driver/sys_drv/dormant/src/dormant_service.c
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
   ifneq ($(filter __CR4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += ${COMMON_ROOT}/driver/sys_drv/dormant/src/cortexr4-dormantMode_rvct.s 
   endif
 endif
endif

ifneq ($(filter __CR4__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/cache/src/mpu.c
      SRC_LIST +=   ${COMMON_ROOT}/driver/sys_drv/pmu/src/cr4_pmu_montr.c
endif


###################################################################
# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/service/sst/include \
          ${COMMON_ROOT}/service/sst/include \
          $(strip $(PROJDIR))/verno \
          ${CORE_ROOT}/driver/peripheral/inc \
          ${COMMON_ROOT}/driver/sys_drv/cache/inc \
          ${COMMON_ROOT}/driver/sys_drv/init/inc \
          ${CORE_ROOT}/driver/devdrv/bus/inc \
          ${CORE_ROOT}/driver/sys_drv/init/inc \
          ${CORE_ROOT}/driver/regbase/inc \
          ${COMMON_ROOT}/driver/sys_drv/pmu/inc \
          ${CORE_ROOT}/service/sys_svc/region/inc \
          ${CORE_ROOT}/service/sys_svc/excep_hdlr/inc \
          ${CORE_ROOT}/driver/devdrv/pll/inc	\
          ${COMMON_ROOT}/driver/sys_drv/dormant/inc \
          ${CORE_ROOT}/interface/service/sys_svc \
          ${CORE_ROOT}/interface/driver/devdrv/cirq \
          ${COMMON_ROOT}/interface/driver/sys_drv \
          ${COMMON_ROOT}/interface/driver/devdrv/ect \
          ${COMMON_ROOT}/driver/sys_drv/dormant/src \
          ${CORE_ROOT}/interface/driver/devdrv/rstctl \
          ${CORE_ROOT}/driver/sys_drv/init/inc \
          ${CORE_ROOT}/interface/service/sst \
          ${COMMON_ROOT}/interface/service/sst \
          ${CORE_ROOT}/interface/driver/devdrv/mdipc

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

###################################################################
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

COMP_DEFS += $(strip $(PLATFORM))

ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    COMP_DEFS  += _NAND_FLASH_BOOTING_
  endif
endif

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
  COMP_DEFS += DCM_ENABLE
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
    ${PCORE_ROOT}/interface/service/hif
endif
