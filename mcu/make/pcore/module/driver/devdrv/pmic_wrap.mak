##############################################################################
#                             devdrv/pmic_wrap                               #
##############################################################################
#PMIC_WRAP_COMPILER_FILTER_LIST = MT6331_PLUS_MT6332 MT6331 MT6332 MT6325 MT6328 MT6351 MT6353 MT6355

#ifneq ($(filter $(PMIC_WRAP_COMPILER_FILTER_LIST),$(PMIC)),)

SRC_LIST  += ${CORE_ROOT}/driver/devdrv/pmic_wrap/src/pmic_wrap.c

SRC_PATH  += ${CORE_ROOT}/driver/devdrv/pmic_wrap/src

INC_DIR   += ${CORE_ROOT}/driver/devdrv/pmic_wrap/inc \
             ${CORE_ROOT}/driver/devdrv/pmic/inc
#endif
