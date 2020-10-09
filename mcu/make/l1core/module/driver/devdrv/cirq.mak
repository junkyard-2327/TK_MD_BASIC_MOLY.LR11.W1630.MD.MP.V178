##############################################################################
#                             devdrv/gpt                                     #
##############################################################################

SRC_LIST  += ${CORE_ROOT}/driver/devdrv/cirq/src/drv_mdcirq.c \
             ${CORE_ROOT}/driver/devdrv/cirq/src/$(COMPILER)/vic_entry.S
             
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/cirq/src/isrentry.c \
             ${CORE_ROOT}/driver/devdrv/cirq/src/$(COMPILER)/irq_gcc.S
             
SRC_PATH  += ${CORE_ROOT}/driver/devdrv/cirq/src
INC_DIR   += ${CORE_ROOT}/driver/devdrv/cirq/inc

