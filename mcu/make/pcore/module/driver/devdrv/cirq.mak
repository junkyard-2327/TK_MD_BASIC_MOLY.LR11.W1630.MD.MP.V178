##############################################################################
#                             devdrv/gpt                                     #
##############################################################################
ifeq ($(filter __ARM7EJ_S__, $(strip $(MODULE_DEFS))),)
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/cirq/src/drv_mdcirq.c \
             ${CORE_ROOT}/driver/devdrv/cirq/src/$(COMPILER)/vic_entry.S
else
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/cirq/src/drv_arm7cirq.c
endif
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/cirq/src/isrentry.c \
             ${CORE_ROOT}/driver/devdrv/cirq/src/$(COMPILER)/irq_gcc.S
SRC_PATH  += ${CORE_ROOT}/driver/devdrv/cirq/src
INC_DIR   += ${CORE_ROOT}/driver/devdrv/cirq/inc

