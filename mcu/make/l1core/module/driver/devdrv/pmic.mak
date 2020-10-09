##############################################################################
#                             devdrv/pmic                                    #
##############################################################################
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmu.c \
             ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmu_common.c \

ifeq ($(strip $(PMIC)),MT6339)
COMP_DEFS += MT6339
SRC_LIST    += ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6339.c \
  ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6339_init.c \

INC_DIR   += ${CORE_ROOT}/driver/devdrv/bsi/inc

endif

MT6331_MT6332_COMPILER_FILTER_LIST = MT6331_PLUS_MT6332 MT6331 MT6332

ifneq ($(filter $(MT6331_MT6332_COMPILER_FILTER_LIST),$(PMIC)),)
COMP_DEFS += DRV_PMIC_WRAP_6595_REG DRV_PMIC_WRAP_V2
SRC_LIST    += ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6331_32.c
  ifeq ($(strip $(PMIC)),MT6331)
        SRC_LIST    += ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6331_init.c  
  endif
  ifeq ($(strip $(PMIC)),MT6332)
        SRC_LIST    += ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6332_init.c  
  endif
  ifeq ($(strip $(PMIC)),MT6331_PLUS_MT6332)
        SRC_LIST    += ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6331_init.c \
                       ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6332_init.c
  endif
INC_DIR   += ${CORE_ROOT}/driver/devdrv/pmic_wrap/inc

endif

ifeq ($(strip $(PMIC)),MT6325)

ifeq ($(strip $(PLATFORM)), TK6291)
COMP_DEFS += MT6325 DRV_PMIC_WRAP_6291_REG DRV_PMIC_WRAP_V2
endif

SRC_LIST    += ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6325.c \
               ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6325_init.c  
INC_DIR   += ${CORE_ROOT}/driver/devdrv/pmic_wrap/inc
endif

ifeq ($(strip $(PMIC)),MT6351)

COMP_DEFS += MT6351

ifeq ($(strip $(PLATFORM)), TK6291)
COMP_DEFS += DRV_PMIC_WRAP_6291_REG DRV_PMIC_WRAP_V2
endif

ifeq ($(strip $(PLATFORM)), MT6755)
COMP_DEFS += DRV_PMIC_WRAP_6755_REG DRV_PMIC_WRAP_V2
endif

ifeq ($(strip $(PLATFORM)), MT6797)
COMP_DEFS += DRV_PMIC_WRAP_6797_REG DRV_PMIC_WRAP_V2
endif

ifeq ($(strip $(PLATFORM)), MT6757)
COMP_DEFS += DRV_PMIC_WRAP_6755_REG DRV_PMIC_WRAP_6757_REG DRV_PMIC_WRAP_V2
endif


SRC_LIST    += ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6351.c \
               ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6351_init.c  
INC_DIR   += ${CORE_ROOT}/driver/devdrv/pmic_wrap/inc
endif

ifeq ($(strip $(PMIC)),MT6353)

COMP_DEFS += MT6353

ifeq ($(strip $(PLATFORM)), MT6750)
COMP_DEFS += DRV_PMIC_WRAP_6750_REG DRV_PMIC_WRAP_V2
endif

ifeq ($(strip $(PLATFORM)), MT6750S)
COMP_DEFS += DRV_PMIC_WRAP_6750_REG DRV_PMIC_WRAP_V2
endif

SRC_LIST    += ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6353.c \
               ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6353_init.c
INC_DIR   += ${CORE_ROOT}/driver/devdrv/pmic_wrap/inc
endif

ifeq ($(strip $(PMIC)),MT6355)

COMP_DEFS += MT6355

ifeq ($(strip $(PLATFORM)), MT6757)
COMP_DEFS += DRV_PMIC_WRAP_6755_REG DRV_PMIC_WRAP_6757_REG DRV_PMIC_WRAP_V2
endif

ifeq ($(strip $(PLATFORM)), MT6757P)
COMP_DEFS += DRV_PMIC_WRAP_6755_REG DRV_PMIC_WRAP_6757_REG DRV_PMIC_WRAP_V2
endif

SRC_LIST    += ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6355.c \
               ${CORE_ROOT}/driver/devdrv/pmic/src/dcl_pmic6355_init.c  
INC_DIR   += ${CORE_ROOT}/driver/devdrv/pmic_wrap/inc
endif

SRC_PATH  += ${CORE_ROOT}/driver/devdrv/pmic/src

INC_DIR   += ${CORE_ROOT}/driver/devdrv/pmic/inc

