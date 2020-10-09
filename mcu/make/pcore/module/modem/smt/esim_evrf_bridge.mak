# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/modem/smt/uesim_lte/esim_evrf_bridge/src/evrf_bridge.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/esim_evrf_bridge/src/evrf_bridge.h \
           ${CORE_ROOT}/modem/smt/uesim_lte/esim_evrf_bridge/src/evrf_bridge_task.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/esim_evrf_bridge/src/evrf_bridge_task.h 

# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/xcomm/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/esim_evrf_bridge/intf  \
          ${CORE_ROOT}/modem/smt/uesim_lte/esim_nw/mns_f_generic/intf  \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/intf  \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/aos/intf

# Define the specified compile options to COMP_DEFS
COMP_DEFS = TRACING_SUPPORT \
            INTEGER_SIM_TIME

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/modem/smt/esim_evrf_bridge/src \
           ${CORE_ROOT}/modem/smt/esim_evrf_bridge/intf
           

