# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/middleware/hif/usbidle/src/usbidle_task.c    \
           ${CORE_ROOT}/middleware/hif/usbidle/src/usbidle_hif.c     \
           ${CORE_ROOT}/middleware/hif/usbidle/src/usbidle_if.c

# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/middleware/hif/interface                                             \
          ${CORE_ROOT}/middleware/hif/usbidle/include \
          ${CORE_ROOT}/interface/driver/hif \
          ${CORE_ROOT}/interface/driver/hif/hif_usbdev \
          ${CORE_ROOT}/interface/service/flc2

# Define the specified compile options to COMP_DEFS
ifdef HIF_USB30_SUPPORT
  ifeq ($(strip $(HIF_USB30_SUPPORT)), TRUE) 
       COMP_DEFS = __USBC_USB30_SUPPORT__
  endif
endif

# Patch for MoDIS
ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
   COMP_DEFS += __USBC_USB30_SUPPORT__
endif

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    COMP_DEFS += __USBC_TARGET_HIF_DRIVER_SUPPORT__
endif

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/middleware/hif/usbidle/src 

