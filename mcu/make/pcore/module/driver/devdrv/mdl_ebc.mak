##############################################################################
#                             mdl_ebc                                        #
##############################################################################
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/mdl_ebc/src/ebc_drv.c

SRC_PATH  += ${CORE_ROOT}/driver/devdrv/mdl_ebc/src

INC_DIR   += ${CORE_ROOT}/driver/devdrv/common/inc \
						 ${CORE_ROOT}/driver/devdrv/mdl_ebc/inc

ifeq ($(strip $(COMPILER)),GCC)
	CFLAGS += -Werror
endif

