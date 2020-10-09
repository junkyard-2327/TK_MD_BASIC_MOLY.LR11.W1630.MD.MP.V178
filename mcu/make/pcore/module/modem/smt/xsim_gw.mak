# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/src/uegw2_mngr.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/src/uegw2_mngr.h \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/src/uegw2_typedb.h \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/src/sim_utc.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/src/sim_utc_intf.h 

# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/xcomm/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/esim_nw/mns_f_generic/intf  \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/intf  \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/aos/intf

# Define the specified compile options to COMP_DEFS
COMP_DEFS = TRACING_SUPPORT \
            INTEGER_SIM_TIME \
            AOS_DLL_RELATIVE_PATH='&quot;&quot;..\\..\\modem\\smt\\uesim_lte\\xsim_generic\\aos\\lib&quot;&quot';

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/modem/smt/xsim_generic/uegw2/src \
           ${CORE_ROOT}/modem/smt/xsim_generic/uegw2/intf \
           ${CORE_ROOT}/modem/smt/xsim_generic/xcomm/intf
           

