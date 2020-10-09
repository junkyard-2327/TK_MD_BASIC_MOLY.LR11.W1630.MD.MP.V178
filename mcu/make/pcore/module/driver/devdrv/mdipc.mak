##############################################################################
#                             devdrv/gpt                                     #
##############################################################################
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/mdipc/src/cc_irq.c \
             ${CORE_ROOT}/driver/devdrv/mdipc/src/cc_irq_hw.c \
             ${CORE_ROOT}/driver/devdrv/mdipc/src/cc_irq_sys_comm.c \
             ${CORE_ROOT}/driver/devdrv/mdipc/src/cc_irq_msg.c \
             ${CORE_ROOT}/driver/devdrv/mdipc/src/cc_irq_rpc.c \
             ${CORE_ROOT}/driver/devdrv/mdipc/src/cc_irq_sync.c \
             ${CORE_ROOT}/driver/devdrv/mdipc/src/cc_spinlock.c \

SRC_PATH  += ${CORE_ROOT}/driver/devdrv/mdipc/src

INC_DIR   += ${CORE_ROOT}/driver/devdrv/mdipc/inc
INC_DIR   += ${CORE_ROOT}/interface/driver/devdrv/mdipc
