#############################################
#				EMI Driver					#
#############################################
# DRAM is controlled by Modem System
ifneq ($(strip $(RAM_SUPPORT_TYPE)),NONE)
	# Define source file lists to SRC_LIST
	SRC_LIST += ${CORE_ROOT}/driver/devdrv/emi/src/emi.c

	ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  	SRC_LIST +=   ${CORE_ROOT}/driver/devdrv/emi/src/emimpu.c
	endif

	# Define include path lists to INC_DIR
	INC_DIR +=  ${CORE_ROOT}/driver/devdrv/emi/inc/ \
	            ${CORE_ROOT}/service/sst/include/

	# Define the source file search paths to SRC_PATH
	SRC_PATH += ${CORE_ROOT}/driver/devdrv/emi/src

	# Define the specified compile options to COMP_DEFS
	COMP_DEFS +=
else
	#temporary solution for bypassing build error
  	SRC_LIST +=   ${CORE_ROOT}/driver/devdrv/emi/src/emimpu.c
	# Define include path lists to INC_DIR
	INC_DIR +=  ${CORE_ROOT}/driver/devdrv/emi/inc/
	# Define the source file search paths to SRC_PATH
	SRC_PATH += ${CORE_ROOT}/driver/devdrv/emi/src
endif
