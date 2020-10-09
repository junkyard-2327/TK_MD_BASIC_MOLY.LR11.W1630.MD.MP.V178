# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/driver/drv/src/bf.c \
           ${CORE_ROOT}/driver/drv/src/e_compass_sensor.c \
           ${CORE_ROOT}/driver/drv/src/e_compass_main.c \
           ${CORE_ROOT}/driver/drv/src/BC_drv.c

#  Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/driver/drv/include \
          ${CORE_ROOT}/interface/driver/connectivity/usb_driver \
          ${CORE_ROOT}/driver/connectivity/usb_driver/inc \
          ${CORE_ROOT}/driver/storage/flash/mtd/inc \
          ${CORE_ROOT}/driver/storage/flash/fdm/inc \
          ${CORE_ROOT}/driver/storage/mc/inc \
          ${CORE_ROOT}/driver/connectivity/usb_class/include \
          ${CORE_ROOT}/service/sst/include \
          ${COMMON_ROOT}/service/sst/include \
          ${CORE_ROOT}/service/ssf/inc \
          ${CORE_ROOT}/driver/drv_def \
          ${CORE_ROOT}/driver/regbase/inc \
          ${CORE_ROOT}/driver/peripheral/inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/driver/drv/src \
           ${CORE_ROOT}/driver/connectivity/usb_driver/src \
           ${CORE_ROOT}/driver/storage/mc/src
