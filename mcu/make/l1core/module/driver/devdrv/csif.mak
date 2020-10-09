##############################################################################
#                             devdrv/cirq_v1                                    #
##############################################################################
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/csif/src/csif_global_variables.c \
             ${CORE_ROOT}/driver/devdrv/csif/src/csif_main.c 
ifneq ($(filter __CSIF_PRETEST_LOAD_ONLY__ , $(strip $(CUSTOM_OPTION))),)
             SRC_LIST += ${CORE_ROOT}/driver/devdrv/csif/src/csif_pretest_load.c
endif             

SRC_PATH  += ${CORE_ROOT}/driver/devdrv/csif/src

INC_DIR   += ${CORE_ROOT}/driver/devdrv/csif/inc \
             ${CORE_ROOT}/interface/driver/devdrv/csif

