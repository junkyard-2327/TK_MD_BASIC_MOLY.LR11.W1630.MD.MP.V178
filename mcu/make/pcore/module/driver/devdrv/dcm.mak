##############################################################################
#                             devdrv/gpt                                     #
##############################################################################
SRC_LIST  += ${COMMON_ROOT}/driver/devdrv/dcm/src/drv_dcm.c \
             ${COMMON_ROOT}/driver/devdrv/dcm/src/dcm_service.c \
             ${COMMON_ROOT}/driver/devdrv/dcm/src/drv_lpm.c \
             ${COMMON_ROOT}/driver/devdrv/dcm/src/peterson_lock.c

SRC_PATH  += ${COMMON_ROOT}/driver/devdrv/dcm/src

INC_DIR   += ${COMMON_ROOT}/driver/devdrv/dcm/inc

