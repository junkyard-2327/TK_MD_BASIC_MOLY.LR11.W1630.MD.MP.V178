##############################################################################
#                             devdrv/eint                                     #
##############################################################################
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/auxadc/src/dcl_adc.c \
             ${CORE_ROOT}/driver/devdrv/auxadc/src/adc.c \
             ${CORE_ROOT}/driver/devdrv/auxadc/src/drv_thermal_protect.c \

SRC_PATH  += ${CORE_ROOT}/driver/devdrv/auxadc/src

INC_DIR   += ${CORE_ROOT}/driver/devdrv/auxadc/inc \
             ${CORE_ROOT}/interface/driver/devdrv/emi \
             ${CORE_ROOT}/interface/driver/devdrv/thermal \
             $(call CUSTOM_FLD_MAPPING,${CORE_ROOT}/custom/driver/drv/misc_drv)
