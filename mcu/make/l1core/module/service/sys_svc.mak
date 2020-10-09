# Define source file lists to SRC_LIST
SRC_LIST =$(strip ${CORE_ROOT})/service/sys_svc/region/src/regioninit_gcc.S
SRC_LIST  += ${CORE_ROOT}/service/sys_svc/excep_hdlr/src/excep_hdlr.c

ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=  $(strip ${CORE_ROOT})/service/sys_svc/region/src/init_memory_stack.c
endif

#  Define include path lists to INC_DIR
INC_DIR =$(strip ${CORE_ROOT})/service/sys_svc/region/inc \
         $(strip ${CORE_ROOT})/interface/service/sys_svc \
         $(strip ${CORE_ROOT})/driver/sys_drv/init/inc \
         $(strip ${CORE_ROOT})/interface/service/sys_svc \
         $(strip $(COMMON_ROOT))/driver/sys_drv/cache/inc \
         $(strip ${CORE_ROOT})/service/sys_svc/excep_hdlr/inc \
         $(strip $(COMMON_ROOT))/interface/driver/sys_drv \
         $(strip $(COMMON_ROOT))/interface/service/sst \
         $(strip $(CORE_ROOT))/interface/service/sst \
         $(strip ${CORE_ROOT})/service/sst/include

# Define the specified compile options to COMP_DEFS
COMP_DEFS =

# Define the source file search paths to SRC_PATH
SRC_PATH =$(strip ${CORE_ROOT})/service/sys_svc/thread/src \
          $(strip ${CORE_ROOT})/service/sys_svc/region/src

