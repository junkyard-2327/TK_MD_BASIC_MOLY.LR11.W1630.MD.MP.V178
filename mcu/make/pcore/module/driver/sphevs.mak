# Define source file folder to SRC_LIST

   EVSFOLDER = ${CORE_ROOT}/driver/sphevs

# Start Define source file lists to SRC_LIST
SRC_LIST += $(strip $(EVSFOLDER))/evs_main.c \
            $(strip $(EVSFOLDER))/sp_EVS_exp.c \
            $(strip $(EVSFOLDER))/sp_EVS_global.c

#  Define include path lists to INC_DIR
INC_DIR = $(strip $(EVSFOLDER)) \
          ${COMMON_ROOT}/interface/driver/audio \
          ${COMMON_ROOT}/interface/driver/sys_drv \
          ${CORE_ROOT}/driver/audio/src32_inc \
          ${CORE_ROOT}/driver/audio/src/v1/inc \
          ${CORE_ROOT}/driver/drv/include \
          ${CORE_ROOT}/driver/sys_drv/init/inc \
          ${CORE_ROOT}/driver/devdrv/common/inc \
          ${CORE_ROOT}/modem/interface/l4 \
          ${CORE_ROOT}/modem/interface/lte \
          ${CORE_ROOT}/interface/modem/mml1 \
          ${CORE_ROOT}/modem/interface/general \
          ${CORE_ROOT}/interface/driver/peripheral \
          ${CORE_ROOT}/modem/interface/general \
          ${CORE_ROOT}/interface/driver/devdrv/mdipc \
          ${CORE_ROOT}/custom/driver/common \
          ${CORE_ROOT}/interface/driver/sleep_drv \
          ${CORE_ROOT}/service/sst/include \
          ${COMMON_ROOT}/driver/sys_drv/cache/inc \
          ${COMMON_ROOT}/interface/modem/general \
          ${COMMON_ROOT}/driver/devdrv/mdap_interface/inc \
          ${COMMON_ROOT}/driver/sleep_drv/inc/ 
 
# Define the source file search paths to SRC_PATH
SRC_PATH += $(strip $(EVSFOLDER))
SRC_PATH += ${CORE_ROOT}/driver/audio/src/v1/inc
SRC_PATH += ${CORE_ROOT}/driver/sphevs_lib
# SRC_PATH += ${COMMON_ROOT}/service/security/swip

