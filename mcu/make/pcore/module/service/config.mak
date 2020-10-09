# Define source file lists to SRC_LIST
SRC_LIST = ${COMMON_ROOT}/service/config/src/hal/syscomp_config.c \
           ${COMMON_ROOT}/service/config/src/hal/task_config.c \
           ${COMMON_ROOT}/service/config/src/hal/stack_config.c \
           ${COMMON_ROOT}/service/config/src/hal/ctrl_buff_pool.c

#  Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/driver/peripheral/inc \
          ${COMMON_ROOT}/service/kal/adaptation/include \
          ${COMMON_ROOT}/interface/service/dhl\
          ${CORE_ROOT}/service/sys_svc/dp/inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  ifeq ($(strip $(UL1_3GSOLUTION)),MTK_UL1_FDD)
    # special for AST projects
    COMP_DEFS += __UL1_ON_MNT__
  endif
endif

# Define the source file search paths to SRC_PATH
SRC_PATH = ${COMMON_ROOT}/service/config/src/hal


ifeq ($(strip $(COMPILER)),GCC)
    CFLAGS += -Werror
endif
