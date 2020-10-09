# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/aos/interface/aos_intf.h \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/intf/uegw2_intf.h \
           ${CORE_ROOT}/modem/smt/uesim_lte/gbst_bridge/intf/csap_g_intf.h \
           ${CORE_ROOT}/modem/smt/uesim_lte/gbst_bridge/intf/gbst_bridge_intf.h \
           ${CORE_ROOT}/modem/smt/uesim_lte/gbst_bridge/src/gbst_bridge.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/gbst_bridge/src/gbst_bridge_task.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/gbst_bridge/src/gbst_oscar.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/gbst_bridge/src/gbst_oscar.h
           

# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/aos/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/src/ \
          ${CORE_ROOT}/modem/smt/uesim_lte/gbst_bridge/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/gsim_nw/intf \
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
            TRACING_SUPPORT \
            __EL1SIM_WITH_MODIS__ \
            __MODIS_WITH_EPHYSIM__ \
            IDLE_TASK \
            KAL_ON_OSCAR \
            _MODIS_ON_VC9_ \
            __EL1TX_ENABLE__ \
            __EL1_ENABLE__ \
            __OSCAR_ON_WIN32__ \
            __PROTECT_OPTIMIZE__ \
            __UT_ISR_OPTIMIZE__ \
            __VM_CODEC_SUPPORT__ \
            __WATCHDOG_RESTART_DISABLE__

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/modem/smt/uesim_lte/gbst_bridge/src

