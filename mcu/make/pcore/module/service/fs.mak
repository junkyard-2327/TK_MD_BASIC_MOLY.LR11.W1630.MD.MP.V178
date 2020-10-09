ifeq ($(strip $(CCCI_FS_SUPPORT))$(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))), TRUE__MTK_TARGET__)
	SRC_LIST = ${CORE_ROOT}/service/fs/ccci_fs/src/mdfs_wrapper.c
#	INC_DIR = ${CORE_ROOT}/service/nvram/include \
#          ${CORE_ROOT}/driver/drv/include \
#          ${CORE_ROOT}/interface/modem/general

else
TARGET_SRC_LIST = ${CORE_ROOT}/service/fs/fat/src/fs_kal.c \
                  ${CORE_ROOT}/service/fs/fat/src/rtfbs.c \
                  ${CORE_ROOT}/service/fs/fat/src/rtfex.c \
                  ${CORE_ROOT}/service/fs/fat/src/format.c \
                  ${CORE_ROOT}/service/fs/fat/src/rtfiles.c \
                  ${CORE_ROOT}/service/fs/fat/src/rtfcore.c \
                  ${CORE_ROOT}/service/fs/fat/src/rtfbuf.c \
                  ${CORE_ROOT}/service/fs/common/src/fs_internal_api.c \
                  ${CORE_ROOT}/service/fs/common/src/fs_sst.c \
                  ${CORE_ROOT}/service/fs/Efs/src/fs_internal.c \
                  ${CORE_ROOT}/service/fs/Efs/src/fs_func.c \
                  ${CORE_ROOT}/service/fs/Efs/src/fs_func_adv.c \
                  ${CORE_ROOT}/service/fs/Efs/src/fs_func_async.c \
                  ${CORE_ROOT}/service/fs/Efs/src/fs_utility.c \
                  ${CORE_ROOT}/service/fs/Efs/src/fs_task.c \
                  ${CORE_ROOT}/service/fs/Efs/src/fs_usbms.c

MODIS_SRC_LIST = pcore/MoDIS_VC9/FileSystem/FileSystemSrc/FSSim_core.c \
                 pcore/MoDIS_VC9/FileSystem/FileSystemSrc/FSSim_data.c \
                 pcore/MoDIS_VC9/FileSystem/FileSystemSrc/FSSim_supplemental.c


# if defined(__FS_BENCHMARK__)
ifneq ($(filter __FS_BENCHMARK__, $(strip $(MODULE_DEFS))),)
  TARGET_SRC_LIST    += ${CORE_ROOT}/service/fs/Efs/src/fs_task.c
endif

# if !defined(__SMART_PHONE_MODEM__) || !defined(__MTK_TARGET__)
ifeq ($(filter __SMART_PHONE_MODEM__, $(strip $(MODULE_DEFS))),)
	 TARGET_SRC_LIST    += ${CORE_ROOT}/service/fs/Efs/src/fs_internal.c \
	                    ${CORE_ROOT}/service/fs/Efs/src/fs_func.c \
	                    ${CORE_ROOT}/service/fs/Efs/src/fs_func_adv.c
else
  ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
	 TARGET_SRC_LIST    += ${CORE_ROOT}/service/fs/Efs/src/fs_internal.c \
	                    ${CORE_ROOT}/service/fs/Efs/src/fs_func.c \
	                    ${CORE_ROOT}/service/fs/Efs/src/fs_func_adv.c
  endif
endif

# if defined(__FS_TRACE_SUPPORT__)
ifneq ($(filter __FS_TRACE_SUPPORT__, $(strip $(MODULE_DEFS))),)
	TARGET_SRC_LIST    += ${CORE_ROOT}/service/fs/Efs/src/fs_utility.c
endif


# Define source file lists to SRC_LIST
ifneq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
 SRC_LIST = $(TARGET_SRC_LIST)
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  SRC_LIST = $(TARGET_SRC_LIST)
 else
  SRC_LIST = $(MODIS_SRC_LIST)
 endif
endif
SRC_LIST    += ${CORE_ROOT}/service/fs/fsal/src/fsal.c \
		  ${CORE_ROOT}/service/fs/fsal/src/fsal_buffer.c \
		  ${CORE_ROOT}/service/fs/fsal/src/fsal_read.c \
		  ${CORE_ROOT}/service/fs/fsal/src/fsal_write.c
			
#  Define include path lists to INC_DIR
ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
 INC_DIR = ${CORE_ROOT}/service/fs/fat/include \
           ${CORE_ROOT}/service/fs/Efs/include \
           ${CORE_ROOT}/driver/drv/include \
           ${CORE_ROOT}/service/fs/common/include \
           ${CORE_ROOT}/middleware/hif/usbclass/msd/include
           
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  INC_DIR = ${CORE_ROOT}/service/fs/fat/include \
            ${CORE_ROOT}/service/fs/Efs/include \
            ${CORE_ROOT}/driver/drv/include \
            ${CORE_ROOT}/service/fs/common/include \
            ${CORE_ROOT}/middleware/hif/usbclass/msd/include
 else
  INC_DIR = pcore/MoDIS_VC9/FileSystem/FileSystemInc
 endif
endif

  INC_DIR += ${COMMON_ROOT}/interface/service/sst

# Define the source file search paths to SRC_PATH
ifneq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
 SRC_PATH = ${CORE_ROOT}/service/fs/fat/src \
            ${CORE_ROOT}/service/fs/common/src \
            ${CORE_ROOT}/service/fs/Efs/src
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  SRC_PATH = ${CORE_ROOT}/service/fs/fat/src \
             ${CORE_ROOT}/service/fs/common/src \
             ${CORE_ROOT}/service/fs/Efs/src
 else
  SRC_PATH = pcore/MoDIS_VC9/FileSystem/FileSystemSrc
 endif
endif

SRC_PATH    += ${CORE_ROOT}/service/fs/fsal/src

# Define the specified compile options to COMP_DEFS
COMP_DEFS = NODEBUG
ifneq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
 COMP_DEFS = NODEBUG
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  COMP_DEFS = NODEBUG
 else
  COMP_DEFS = 
 endif
endif

COMP_DEFS += CURR_MODULE=MOD_$(strip $(call Upper,$(COMPONENT))) 

ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  INC_DIR += ${COMMON_ROOT}/interface/service/hif \
    ${CORE_ROOT}/interface/service/hif  \
             ${CORE_ROOT}/service/fs/Efs/include \
             ${CORE_ROOT}/middleware/hif/usbclass/msd/include
endif
INC_DIR += ${CORE_ROOT}/service/fs/fat/include

endif
