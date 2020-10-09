##############################################################################
#                             devdrv/gpio                                     #
##############################################################################
SRC_LIST  += ${CORE_ROOT}/driver/devdrv/gpio/src/dcl_gpio.c \
             ${CORE_ROOT}/driver/devdrv/gpio/src/drv_gpio.c \
             ${CORE_ROOT}/driver/devdrv/gpio/src/gpio_setting.c \

SRC_PATH  += ${CORE_ROOT}/driver/devdrv/gpio/src

INC_DIR   += ${CORE_ROOT}/driver/devdrv/gpio/inc \
	     $(strip $(PROJDIR))/custom/driver/drv_gen

