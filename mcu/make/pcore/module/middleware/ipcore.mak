#
# Define source file lists to SRC_LIST
#
SRC_LIST = ${CORE_ROOT}/middleware/hif/ipcore/src/ipc_task.c \
           ${CORE_ROOT}/middleware/hif/ipcore/src/ipc_if.c \
           ${CORE_ROOT}/middleware/hif/ipcore/src/ipc_session.c \
           ${CORE_ROOT}/middleware/hif/ipcore/src/ipc_filter.c \
           ${CORE_ROOT}/middleware/hif/ipcore/src/ipc_dhcp_adp.c \
           ${CORE_ROOT}/middleware/hif/ipcore/src/ipc_notify.c \
           ${CORE_ROOT}/middleware/hif/ipcore/src/ipc_utils.c

# Packet Filter Manager file lists
SRC_LIST += ${CORE_ROOT}/middleware/hif/ipcore/src/pfm_garbage_filter.c \
			${CORE_ROOT}/middleware/hif/ipcore/src/pfm_if.c

ifneq ($(filter ATEST_SYS_IPCORE, $(strip $(MODULE_DEFS))),)
SRC_LIST += ${CORE_ROOT}/middleware/hif/ipcore/src/ipc_ut.c
endif

#
#  Define include path lists to INC_DIR
#
INC_DIR = ${CORE_ROOT}/middleware/hif/interface \
          ${CORE_ROOT}/middleware/hif/ipcore/include \
          ${CORE_ROOT}/interface/modem/upcm

#
# Define the specified compile options to COMP_DEFS
#
COMP_DEFS =

ifeq ($(strip $(LTM_EPDCP_SIMULATION_SUPPORT)), TRUE)
COMP_DEFS += __LTM_EPDCP_SIMULATION_SUPPORT__
endif

#
# Define the source file search paths to SRC_PATH
#
SRC_PATH = ${CORE_ROOT}/middleware/hif/ipcore/src
