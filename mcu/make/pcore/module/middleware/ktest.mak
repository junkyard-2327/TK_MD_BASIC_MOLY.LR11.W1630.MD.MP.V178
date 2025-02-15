# Define source file lists to SRC_LIST
SRC_PATH = ${CORE_ROOT}/middleware/mtkdebug/ktest
ifneq ($(filter __KTEST__, $(strip $(MODULE_DEFS))),)
SRC_LIST += ${CORE_ROOT}/middleware/mtkdebug/ktest/kal_autotest.c \
		   ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_adaptation_oscar.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_timer.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_nu_timer.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_lib_timer.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_adaptation_target.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_fsm.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_interface.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_ipc.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_mm_adm.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_mm_afm.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_mm_ctrlbuf.c  \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_task.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_utl.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_sandbox.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_mlib.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_slmm.c \
           ${CORE_ROOT}/middleware/mtkdebug/ktest/ktest_tc_vm.c
endif 
#  Define include path lists to INC_DIR
INC_DIR = ${COMMON_ROOT}/interface/service/config \
          ${COMMON_ROOT}/interface/service/kal \
          ${CORE_ROOT}/interface/driver/peripheral \
          ${CORE_ROOT}/interface/service/tst \
          ${CORE_ROOT}/interface/driver/hwdrv \
          ${CORE_ROOT}/middleware/mtkdebug/ktest \
          ${COMMON_ROOT}/service/kal/adaptation/include \
          ${COMMON_ROOT}/service/kal/common/include \
          ${COMMON_ROOT}/service/kal/mlib/include \
          ${COMMON_ROOT}/service/kal/nucleus/include \
          ${COMMON_ROOT}/service/kal/oscar/include \
          ${COMMON_ROOT}/interface/sap/svc \
          ${CORE_ROOT}/service/fsm/include \
          ${COMMON_ROOT}/driver/sys_drv/cache/inc/ \
          ${CORE_ROOT}/service/sys_svc/dp/inc \
          ${CORE_ROOT}/service/sst/include \
          ${COMMON_ROOT}/service/sst/include \
          ${CORE_ROOT}/modem/interface \
          ${CORE_ROOT}/modem/interface/general \
          ${CORE_ROOT}/interface/service/fsm \
          ${COMMON_ROOT}/service/nucleus_v2/inc \
          ${COMMON_ROOT}/service/nucleus/inc 

# Define the specified compile options to COMP_DEFS
COMP_DEFS =

 
