#######################################################################
#                             tty                                     #
#######################################################################
# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/driver/tty/src/dcl_tty.c

ifneq ($(filter __TTY_UT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += ${CORE_ROOT}/driver/tty/src/tty_ut.c
endif

ifneq ($(filter __EXCEPT_TTY_UT__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += ${CORE_ROOT}/driver/tty/src/excp_tty_ut.c
endif

#  Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/driver/tty/inc \
          ${CORE_ROOT}/driver/devdrv/common/inc \
          ${CORE_ROOT}/interface/service/flc2

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/driver/tty/src
