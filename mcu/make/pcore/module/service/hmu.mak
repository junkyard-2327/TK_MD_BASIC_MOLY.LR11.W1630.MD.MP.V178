# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/service/hif/hmu/src/hmu.c
SRC_LIST += ${CORE_ROOT}/service/hif/hmu/src/hmu_conf_data.c


#  Define include path lists to INC_DIR
INC_DIR = ${COMMON_ROOT}/interface/service/hif \
    ${CORE_ROOT}/interface/service/hif		\
		  ${CORE_ROOT}/service/hif/hmu/include	\
		  ${CORE_ROOT}/service/hif/interface
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = _HMU_

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/service/hif/hmu/src
