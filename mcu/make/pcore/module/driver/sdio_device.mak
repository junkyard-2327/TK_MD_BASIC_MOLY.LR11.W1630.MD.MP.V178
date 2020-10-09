SRC_LIST = ${CORE_ROOT}/driver/connectivity/sdio_device/src/sdio_custom.c \
    	   ${CORE_ROOT}/driver/connectivity/sdio_device/src/sdio_hw.c \
		   ${CORE_ROOT}/driver/connectivity/sdio_device/src/sdio_queue.c \
		   ${CORE_ROOT}/driver/connectivity/sdio_device/src/sdio_fw.c \
		   ${CORE_ROOT}/driver/connectivity/sdio_device/src/sdio_interrupt.c \
		   ${CORE_ROOT}/driver/connectivity/sdio_device/src/sdio_test_util.c


#  Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/driver/drv_def \
          ${CORE_ROOT}/driver/connectivity/sdio_device/inc \
          ${CORE_ROOT}/driver/regbase/inc \
          ${CORE_ROOT}/driver/sleep_drv


# Define the specified compile options to COMP_DEFS
COMP_DEFS =

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/driver/connectivity/sdio_device/src
