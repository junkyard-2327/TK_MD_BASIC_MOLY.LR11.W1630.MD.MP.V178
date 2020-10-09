#
# Define source file lists to SRC_LIST
#

# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/middleware/kpalv/src/kpalv_task.c \
           ${CORE_ROOT}/middleware/kpalv/src/kpalv_data.c \
            ${CORE_ROOT}/middleware/kpalv/src/kpalv_ut.c


# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/middleware/kpalv/include \
          ${CORE_ROOT}/middleware/hif/ipcore/include \
          ${CORE_ROOT}/interface/middleware/hif


# Define the specified compile options to COMP_DEFS
COMP_DEFS += 
 
# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/middleware/kpalv/src

