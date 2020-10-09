##############################################################################
#   NOTICE : We have no HW for this IP (lcd) now.                            #
#            But for SW complie request,                                     #
#            temporarily add the 'fake api' to make compile success.         #
##############################################################################

SRC_LIST  += ${CORE_ROOT}/driver/devdrv/lcd/src/wfd_lcd_adapter.c

SRC_PATH  += ${CORE_ROOT}/driver/devdrv/lcd/src

INC_DIR   += ${CORE_ROOT}/driver/devdrv/lcd/inc \
             ${CORE_ROOT}/interface/driver/display/ddv1/ \

COMP_DEFS += 
