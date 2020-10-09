# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/driver/storage/sim/src/dcl_sim.c \
		   ${CORE_ROOT}/driver/storage/sim/src/icc_sim_common_mtk.c \
		   ${CORE_ROOT}/driver/storage/sim/src/icc_switchControl0.c \
		   ${CORE_ROOT}/driver/storage/sim/src/icc_switchControl1.c \
		   ${CORE_ROOT}/driver/storage/sim/src/icc_switchControl2.c \
		   ${CORE_ROOT}/driver/storage/sim/src/icc_switchControl_al.c \
		   ${CORE_ROOT}/driver/storage/sim/src/icc_switchControl_mtk_0.c \
		   ${CORE_ROOT}/driver/storage/sim/src/icc_switchControl_mtk_1.c \
		   ${CORE_ROOT}/driver/storage/sim/src/MT6302_SPI.c



#  Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/driver/drv/include \
          ${CORE_ROOT}/driver/storage/sim/inc \
          ${CORE_ROOT}/service/sst/include \
          ${CORE_ROOT}/service/ssf/inc \
          ${CORE_ROOT}/driver/regbase/inc


# Define the specified compile options to COMP_DEFS
COMP_DEFS =

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/driver/storage/sim/src

