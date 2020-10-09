##############################################################################
#                             devdrv/bsi                                     #
##############################################################################
ifneq ($(filter MT6290, $(strip $(MODULE_DEFS))),)
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/bsi/src/drv_bsi.c

SRC_PATH  += ${CORE_ROOT}/driver/devdrv/bsi/src

INC_DIR   += ${CORE_ROOT}/driver/devdrv/bsi/inc
endif
