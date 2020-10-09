# Define source file lists to SRC_LIST
ifeq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
SRC_LIST = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/MTxxxx_u4G/src/m14000_u4g.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/MTxxxx_u4G/src/m14999_u4g.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/MTxxxx_u4G/src/m14999_2g.c
else
SRC_LIST = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14000_uesim.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14100.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14101.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14102.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14103.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14104.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14105.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14106.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14107.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14108.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14109.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14110.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14111.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14120.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14121.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14122.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14123.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14124.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14125.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14126.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14127.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14128.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14129.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14130.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14140.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/m14999.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/os_timer.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/tdma_sm.c \
           ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/mt6208/top_sm.c
endif

# Define include path lists to INC_DIR
ifeq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
INC_DIR = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/scripting/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/uhlsim_hw/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/xcomm/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/esim_evrf_bridge/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/vmmi_bridge/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/gsim_nw/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/gsim_hw/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/usim_uvrf_hl_bridge/intf \
          ${CORE_ROOT}/modem/gl1/l1_dm/common \
          ${CORE_ROOT}/modem/gl1/l1_dm/interface \
          ${CORE_ROOT}/modem/gl1/l1_dm/l1c \
          ${CORE_ROOT}/modem/gl1/l1_dm/l1d \
          ${CORE_ROOT}/modem/gl1/l1_dm/l1d_ext \
          ${CORE_ROOT}/modem/interface/l1/gsm \
          ${CORE_ROOT}/modem/interface/l1/inner \
          ${CORE_ROOT}/modem/md_sm/l1sm \
          ${CORE_ROOT}/modem/md_sm/common/l1sm
          
INC_DIR += ${COMMON_ROOT}/interface/modem/l1/fdd/internal \
           ${COMMON_ROOT}/modem/interface/l1/inner \
           ${L1CORE_ROOT}/modem/gl1/common

else
INC_DIR = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/generic/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_framework/scripting/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/uegw2/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/xsim_generic/xcomm/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/esim_evrf_bridge/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/gsim_nw/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/gsim_hw/intf \
          ${CORE_ROOT}/modem/smt/uesim_lte/usim_hw/uvrf/intf \
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
endif

# Define the specified compile options to COMP_DEFS
ifeq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
COMP_DEFS = INTEGER_SIM_TIME \
            SIM_MT6280 \
            L1_SIM \
            REG_MAY_NOT_EXIST \
            HARDWARE_SIMULATION=1 \
            TRACING_SUPPORT
else
COMP_DEFS = __ESIM_3G_HWSIM_DATA_PATH_ENABLE__ \
            __ESIM_3G_HWSIM_ASSERT_DISABLE__ \
            INTEGER_SIM_TIME \
            SIM_MT6280 \
            L1_SIM \
            L1D_SIM \
            REG_MAY_NOT_EXIST \
            AFC_13bit \
            CH_RF_TEST \
            __HYPER_SLEEP_MODE_CHIP__ \
            USE_WAKEUP_INT \
            MEM_CHECK_ON \
            __HSPA_PLUS_SIM__ \
            HARDWARE_SIMULATION=1 \
            MT6326 \
            TRACING_SUPPORT
endif

# Define the source file search paths to SRC_PATH
ifeq ($(strip $(U4G_ADAPTOR_SUPPORT)),TRUE)
SRC_PATH = ${CORE_ROOT}/modem/smt/uesim_lte/xsim_platform/MTxxxx_u4G/src
else
SRC_PATH = ${CORE_ROOT}/modem/smt/xsim_platform/mt6208
endif
