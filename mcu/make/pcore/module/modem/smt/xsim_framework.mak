# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/huge_time.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13000.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13003.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13004.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13005.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13006.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13007.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13100.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13101.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13102.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13103.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13200.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13201.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/m13202.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/os_adaptation/src/xsim_kal_assert.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/os_adaptation/src/xsim_main_task.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/os_adaptation/src/xsim_oscar_consume_time.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/os_adaptation/src/xsim_oscar_os_timer.c

# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/scripting/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208 \
          ${CORE_ROOT}/modem/smt/uesim_lte/gsim_hw/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/gsim_nw/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/usim_nw \
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
          ${L1CORE_ROOT}/modem/md_sm/common/l1sm \

# Define the specified compile options to COMP_DEFS
COMP_DEFS = INTEGER_SIM_TIME \
            SIMULATION_SUPPORT \
            TRACING_SUPPORT

ifeq ($(strip $(FLAVOR)), MULTI_MODE)
	ifneq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
COMP_DEFS += __ESIM_3G_HWSIM_DATA_PATH_ENABLE__ \
             __ESIM_3G_HWSIM_ASSERT_DISABLE__
endif
endif

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/os_adaptation/src
