# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/modem/smt/uesim_lte/gsim_hw/src/m134000.c \
					 ${CORE_ROOT}/modem/smt/uesim_lte/gsim_hw/src/m134001.c \
					 ${CORE_ROOT}/modem/smt/uesim_lte/gsim_hw/src/m134002.c \
					 ${CORE_ROOT}/modem/smt/uesim_lte/gsim_hw/src/m134003.c

SRC_LIST += ${CORE_ROOT}/modem/smt/uesim_lte/gsim_hw/src/m13500.c

# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/intf \
					${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208 \
					${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/rf \
					${CORE_ROOT}/modem/smt/uesim_lte/gsim_nw/intf \
					${CORE_ROOT}/modem/smt/uesim_lte/gsim_hw/intf \
					${L1CORE_ROOT}/modem/gl1/common \
					${L1CORE_ROOT}/modem/gl1/interface \
					${L1CORE_ROOT}/modem/gl1/l1c \
					${L1CORE_ROOT}/modem/gl1/l1d \
					${L1CORE_ROOT}/modem/gl1/l1d_ext \
					${COMMON_ROOT}/modem/interface/l1/gsm \
					${COMMON_ROOT}/modem/interface/l1/inner \
    ${L1CORE_ROOT}/modem/interface/l1/inner \
    ${CORE_ROOT}/modem/interface/l1/inner \
					${L1CORE_ROOT}/modem/md_sm/l1sm \
					${L1CORE_ROOT}/modem/md_sm/common/l1sm

# Define the specified compile options to COMP_DEFS
COMP_DEFS = INTEGER_SIM_TIME \
						L1_SIM \
						L1D_SIM \
						__HYPER_SLEEP_MODE_CHIP__ \
						AFC_13bit \
						TRACING_SUPPORT

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/modem/smt/uesim_lte/gsim_hw/src
