# Define source file lists to SRC_LIST
SRC_LIST = ${CORE_ROOT}/service/nvram/src/nvram_factory_config.c \
           ${CORE_ROOT}/service/nvram/src/nvram_handler_read.c \
           ${CORE_ROOT}/service/nvram/src/nvram_handler_reset.c \
           ${CORE_ROOT}/service/nvram/src/nvram_handler_startup.c \
           ${CORE_ROOT}/service/nvram/src/nvram_handler_write.c \
           ${CORE_ROOT}/service/nvram/src/nvram_drval_fat.c \
           ${CORE_ROOT}/service/nvram/src/nvram_ilm.c \
           ${CORE_ROOT}/service/nvram/src/nvram_io.c \
           ${CORE_ROOT}/service/nvram/src/nvram_ltable.c \
           ${CORE_ROOT}/service/nvram/src/nvram_main.c \
           ${CORE_ROOT}/service/nvram/src/nvram_multi_folder.c \
           ${CORE_ROOT}/service/nvram/src/nvram_msg_handler.c \
           ${CORE_ROOT}/service/nvram/src/nvram_interface.c \
           ${CORE_ROOT}/service/nvram/src/nvram_l1def.c \
           ${CORE_ROOT}/service/nvram/src/nvram_util.c \
           ${CORE_ROOT}/service/nvram/src/nvram_el1def.c \
           ${CORE_ROOT}/service/nvram/src/nvram_mml1def.c \
           ${CORE_ROOT}/service/nvram/src/nvram_tl1def.c 

SRC_LIST    += ${CORE_ROOT}/service/nvram/src/nvram_pseudo_merge.c
SRC_LIST    += ${CORE_ROOT}/service/nvram/src/nvram_ex_io.c

ifneq ($(filter __UMTS_RAT__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __MTK_UL1_FDD__, $(strip $(MODULE_DEFS))),)
    SRC_LIST    += ${CORE_ROOT}/service/nvram/src/nvram_ul1def.c
  endif
endif

ifneq ($(filter __NVRAM_COMPRESS_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += ${CORE_ROOT}/service/nvram/src/nvram_unzip.c
endif

ifneq ($(filter __SYSDRV_BACKUP_DISK__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += ${CORE_ROOT}/service/nvram/src/nvram_msg_handler.c
endif

ifneq ($(filter __CUSTOMER_TC01_DISK__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += ${CORE_ROOT}/service/nvram/src/nvram_msg_handler.c
endif

ifneq ($(filter __SECURE_DATA_STORAGE__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += ${CORE_ROOT}/service/nvram/src/nvram_msg_handler.c
endif

ifneq ($(filter TST_HANDLER, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += ${CORE_ROOT}/service/nvram/src/nvram_handler_tst.c
endif

ifneq ($(filter __NVRAM_UNIT_TEST__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += ${CORE_ROOT}/service/nvram/src/nvram_tst.c
endif




# ifneq ($(filter __XXX__, $(strip $(MODULE_DEFS))),)
#	SRC_LIST += xxxx\xxxxx\AAA.c
# endif
# ifeq ($(strip $(NAND_SUPPORT)),FALSE)
#                SRC_LIST += xxxx
# endif

# Define include path lists to INC_DIR
INC_DIR = ${CORE_ROOT}/service/nvram/include \
          ${CORE_ROOT}/driver/drv/include \
          ${CORE_ROOT}/interface/modem/general

# Define the specified compile options to COMP_DEFS
COMP_DEFS =

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/service/nvram/src

COMP_DEFS += CURR_MODULE=MOD_$(strip $(call Upper,$(COMPONENT))) 

