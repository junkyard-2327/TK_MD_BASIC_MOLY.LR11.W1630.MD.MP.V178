# Define source file lists to SRC_LIST
SRC_LIST += ${CORE_ROOT}/driver/devdrv/usim/mt6306/src/icc_switchControl0_mt6306.c \
           ${CORE_ROOT}/driver/devdrv/usim/mt6306/src/icc_switchControl1_mt6306.c \
           ${CORE_ROOT}/driver/devdrv/usim/mt6306/src/icc_switchControl2_mt6306.c \
           ${CORE_ROOT}/driver/devdrv/usim/mt6306/src/MT6306_HW_I2C.c \
           ${CORE_ROOT}/driver/devdrv/usim/mt6306/src/MT6306_I2C.c


# Define include path lists to INC_DIR
INC_DIR += ${CORE_ROOT}/driver/drv/include \
          ${CORE_ROOT}/driver/devdrv/usim/inc \
          ${CORE_ROOT}/service/sst/include \
          ${CORE_ROOT}/service/ssf/inc \
          ${CORE_ROOT}/driver/devdrv/usim/mt6306/inc
          
		#interface/driver/devdrv/usim
          #driver/sys_drv/regbase/inc \
          #driver/sys_drv/dma/inc \
         # driver/sys_drv/counter/inc \
          
# Define the specified compile options to COMP_DEFS
COMP_DEFS +=

# Define the source file search paths to SRC_PATH
SRC_PATH += ${CORE_ROOT}/driver/devdrv/usim/mt6306/src

