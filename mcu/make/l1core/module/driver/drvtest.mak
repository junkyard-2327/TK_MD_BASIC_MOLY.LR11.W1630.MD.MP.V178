# Define source file lists to SRC_LIST
SRC_LIST  = ${CORE_ROOT}/driver/drvtest/common/src/drvtest_common.c \
            ${CORE_ROOT}/driver/drvtest/common/src/drvtest_dummy.c
ifeq ($(filter __ARM7EJ_S__, $(strip $(MODULE_DEFS))),)
    SRC_LIST  += ${CORE_ROOT}/driver/drvtest/common/src/drvtest_sm.c
endif

# Define include path lists to INC_DIR
INC_DIR   = ${CORE_ROOT}/driver/devdrv/common/inc \
            ${COMMON_ROOT}/driver/devdrv/iomux/inc \
            ${CORE_ROOT}/driver/drvtest/common/inc \
            ${COMMON_ROOT}/driver/sys_drv/cache/inc \
            ${CORE_ROOT}/service/sst/include

# Define the specified compile options to COMP_DEFS
COMP_DEFS =

# Define the source file search paths to SRC_PATH
SRC_PATH  = ${CORE_ROOT}/driver/drvtest/common/src

-include make/${CORE_ROOT}/module/driver/devdrv/iomux.mak
include make/${CORE_ROOT}/module/driver/drvtest/gpt.mak
-include make/${CORE_ROOT}/module/driver/drvtest/lmac.mak
include make/${CORE_ROOT}/module/driver/drvtest/spic.mak
include make/${CORE_ROOT}/module/driver/drvtest/nfi.mak
-include make/${CORE_ROOT}/module/driver/drvtest/l2_cipher.mak
-include make/${CORE_ROOT}/module/driver/drvtest/mac_phy_cosim.mak
-include make/${CORE_ROOT}/module/driver/drvtest/l2_hw_logging.mak
include make/${CORE_ROOT}/module/driver/drvtest/gdma.mak
include make/${CORE_ROOT}/module/driver/drvtest/hif.mak
include make/${CORE_ROOT}/module/driver/drvtest/usim.mak
include make/${CORE_ROOT}/module/driver/drvtest/rstctl.mak
include make/${CORE_ROOT}/module/driver/drvtest/cpu.mak
include make/${CORE_ROOT}/module/driver/drvtest/coresight.mak
include make/${CORE_ROOT}/module/driver/drvtest/gpio.mak
 include make/${CORE_ROOT}/module/driver/drvtest/eint.mak

include make/${CORE_ROOT}/module/driver/drvtest/dem.mak

include make/${CORE_ROOT}/module/driver/drvtest/pfc.mak
include make/${CORE_ROOT}/module/driver/drvtest/uart.mak
include make/${CORE_ROOT}/module/driver/drvtest/idc.mak
include make/${CORE_ROOT}/module/driver/drvtest/stress.mak
include make/${CORE_ROOT}/module/driver/drvtest/drvtest_slt.mak
include make/${CORE_ROOT}/module/driver/drvtest/mc_drvtest.mak
include make/${CORE_ROOT}/module/driver/drvtest/dspfm.mak
include make/${CORE_ROOT}/module/driver/drvtest/busmon.mak
include make/${CORE_ROOT}/module/driver/drvtest/bsi.mak
include make/${CORE_ROOT}/module/driver/drvtest/dormant.mak
-include make/${CORE_ROOT}/module/driver/drvtest/ss.mak
-include make/${CORE_ROOT}/module/driver/drvtest/emi.mak
-include make/${CORE_ROOT}/module/driver/drvtest/pcc.mak
-include make/${CORE_ROOT}/module/driver/drvtest/scc.mak
-include make/${CORE_ROOT}/module/driver/drvtest/ppc.mak
