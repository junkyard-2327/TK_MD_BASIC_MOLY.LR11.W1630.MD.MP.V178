# Define source file lists to SRC_LIST
# flash_mtd.c is necessary for L1 to call NOR_GetReturnReadyLatency
SRC_LIST = ${CORE_ROOT}/driver/storage/flash/mtd/src/flash_mtd.c

ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
    SRC_LIST += ${CORE_ROOT}/driver/storage/flash/mtd/src/mtd_dal_spi.c \
                	     ${CORE_ROOT}/driver/storage/flash/mtd/src/drv_spi.c
    ifeq ($(strip $(FLASH_TEST_SELECT)),NOR_FLASH)
      SRC_LIST    += ${CORE_ROOT}/driver/storage/flash/mtd/src/flash_mtd_sf_ut.c
    endif
endif

# NOR/SF driver
ifeq ($(filter _NAND_FLASH_BOOTING_, $(strip $(MODULE_DEFS))),)
ifeq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += \
              ${CORE_ROOT}/driver/storage/flash/mtd/src/flash_mtd.ramdisk.c \
              ${CORE_ROOT}/driver/storage/flash/mtd/src/flash_cfi.c \
              ${CORE_ROOT}/driver/storage/flash/mtd/src/flash_disk.c \
              ${CORE_ROOT}/driver/storage/flash/mtd/src/flash_mtd_pf_dal.c \
              ${CORE_ROOT}/driver/storage/flash/mtd/src/flash_mtd.amd.c \
              ${CORE_ROOT}/driver/storage/flash/mtd/src/flash_mtd.intel.c
  ifneq ($(filter __SERIAL_FLASH_EN__, $(strip $(MODULE_DEFS))),)
    #SRC_LIST += \
                #driver/storage/flash/mtd/src/flash_mtd_sf_common.c \
                #driver/storage/flash/mtd/src/flash_mtd_sf_dal.c \
                #driver/storage/flash/mtd/src/flash_mtd_sf_ut.c
  endif
endif
endif

ifeq ($(strip $(NAND_SUPPORT)),TRUE)
# NAND driver build condition
SRC_LIST    += ${CORE_ROOT}/driver/storage/flash/mtd/src/NAND_MTD.c \
            ${CORE_ROOT}/driver/storage/flash/mtd/src/flash_user.c
endif
# #if ( defined(__NAND_FDM_50__) && (defined(__NFI_VERSION2__)||defined(__NFI_VERSION3_1__)) )
ifneq ($(filter __NAND_FDM_50__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __NFI_VERSION2__, $(strip $(MODULE_DEFS))),)
    SRC_LIST    += ${CORE_ROOT}/driver/storage/flash/mtd/src/NAND_DAL.c
    SRC_LIST    += ${CORE_ROOT}/driver/storage/flash/mtd/src/NAND_MTD_FDM50.c
    SRC_LIST    += ${CORE_ROOT}/driver/storage/flash/mtd/src/NAND_DevConfig.c
  else 
     ifneq ($(filter __NFI_VERSION3_1__, $(strip $(MODULE_DEFS))),)
       SRC_LIST    += ${CORE_ROOT}/driver/storage/flash/mtd/src/NAND_DAL.c
       SRC_LIST    += ${CORE_ROOT}/driver/storage/flash/mtd/src/NAND_MTD_FDM50.c
       SRC_LIST    += ${CORE_ROOT}/driver/storage/flash/mtd/src/NAND_DevConfig.c
       SRC_LIST    += ${CORE_ROOT}/driver/storage/flash/mtd/src/NAND_MTD_DRV.c
     endif
  endif
endif

#  RAM Disk for smartphone modem-only projects
ifneq ($(filter __FS_RAMDISK__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += ${CORE_ROOT}/driver/storage/flash/mtd/src/flash_mtd.ramdisk.c
endif

#  Define include path lists to INC_DIR
INC_DIR = ${COMMON_ROOT}/service/sss/interface/inc \
          ${CORE_ROOT}/driver/drv/include \
          ${CORE_ROOT}/service/sst/include \
          ${CORE_ROOT}/driver/storage/flash/fdm/inc \
          ${CORE_ROOT}/driver/storage/flash/mtd/inc \
          ${CORE_ROOT}/driver/peripheral/inc \
          ${CORE_ROOT}/service/fs/common/include \
          ${CORE_ROOT}/service/sys_svc/dp/inc \
          ${CORE_ROOT}/service/sys_svc/gfh/public \
          ${CORE_ROOT}/driver/devdrv/common/inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

# Define the source file search paths to SRC_PATH
SRC_PATH = ${CORE_ROOT}/driver/storage/flash/mtd/src

