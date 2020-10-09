AUTO_MERGE_FOLDER = 

INC_DIR =
COMP_DEFS =
FOLDER_LIST =

# source file folder for xgen
GEN_FOLDER_LIST = $(strip $(BUILD_SYSDIR)) $(strip $(BUILD_CODEGENDIR))
INC_DIR += $(strip $(BUILD_SYSDIR)) $(strip $(BUILD_CODEGENDIR))


# Define source file lists to SRC_LIST
# Define source file folder to FOLDER_LIST


FOLDER_LIST +=$(strip ${CORE_ROOT})/custom/driver/common

               
ifneq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifdef GPS_SUPPORT
      ifneq ($(strip $(GPS_SUPPORT)),NONE)
        FOLDER_LIST += $(call CUSTOM_FLD_MAPPIN,$(strip ${CORE_ROOT})/custom/driver/drv/gps)
        INC_DIR += $(call CUSTOM_FLD_MAPPIN,$(strip ${CORE_ROOT})/custom/driver/drv/gps)
      endif
    endif
  endif
endif


ifneq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  FOLDER_LIST += $(call CUSTOM_FLD_MAPPIN,$(strip ${CORE_ROOT})/custom/middleware/meta)
endif

#modem
FOLDER_LIST += $(call CUSTOM_FLD_MAPPIN,$(strip ${CORE_ROOT})/custom/modem/ps)

#service
FOLDER_LIST +=$(strip ${CORE_ROOT})/custom/service/tst \
              $(strip ${CORE_ROOT})/custom/service/fs \
              $(strip ${CORE_ROOT})/custom/service/nvram \
              $(strip ${CORE_ROOT})/custom/service/common \
               $(strip $(PROJDIR))/nvram_auto_gen

## 
AUTO_MERGE_TMP := $(foreach DIR,$(AUTO_MERGE_FOLDER),$(if $(filter $(DIR)/_Default_BB/$(strip $(PLATFORM)) $(call CUSTOM_FLD_MAPPING,$(DIR)),$(FOLDER_LIST)),$(DIR),))

SRC_LIST += $(foreach DIR,$(AUTO_MERGE_TMP), \
  $(subst /,/,$(foreach file,$(wildcard $(DIR)/_Default_BB/$(strip $(PLATFORM))/*.c) $(wildcard $(DIR)/_Default_BB/$(strip $(PLATFORM))/*.cpp),$(if $(wildcard $(call CUSTOM_FLD_MAPPING,$(DIR))/$(notdir $(file))),,$(file))) $(wildcard $(call CUSTOM_FLD_MAPPING,$(DIR))/*.c) $(wildcard $(call CUSTOM_FLD_MAPPING,$(DIR))/*.cpp)) \
)

FOLDER_LIST := $(filter-out $(foreach DIR,$(AUTO_MERGE_TMP),$(DIR)/_Default_BB/$(strip $(PLATFORM)) $(call CUSTOM_FLD_MAPPING,$(DIR))),$(FOLDER_LIST))

FOLDER_LIST += $(GEN_FOLDER_LIST)

SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(wildcard $(DIR)/*.c),$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(wildcard $(DIR)/*.cpp),$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(wildcard $(DIR)/*.s),$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(wildcard $(DIR)/*.dws),$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(wildcard $(DIR)/*.rec),$(FILE)) \
)

# For cgen
ifneq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
#    SRC_LIST += $(BUILD_TSTDIR)/src/tst_file_default_Catcher_filter.c
#    SRC_LIST += $(BUILD_TSTDIR)/src/tst_mini_log_default_Catcher_filter.c
  endif
endif

#only in MoDIS
ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  MODIS_DIS_FILE := custom_emi.c custom_flash.c usb_custom.c wndrv_configure.c wndrv_rf_ah.c wndrv_rf_maxim.c
  MODIS_DIS_FILE += custom_flash_norfdm5.c afe.c mal1_create.c kbdmain_joystick.c ERS_api.c ERS_sys.s custom_sfi.c
  MODIS_DIS_FILE += combo_flash_init.c combo_flash_nor.c
  SRC_LIST := $(foreach file,$(SRC_LIST),$(if $(filter $(notdir $(call Lower,$(file))),$(call Lower,$(MODIS_DIS_FILE))),,$(file)))
endif

SRC_LIST :=  $(call uniq,$(SRC_LIST))

#  Define include path lists to INC_DIR
ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  AUDFOLDER =$(strip ${CORE_ROOT})/driver/audio/src/v2
else
  AUDFOLDER =$(strip ${CORE_ROOT})/driver/audio/src/v1
endif

# Build follow file in L1CORE for tl1 use
ifdef UMTS_TDD128_RF_MODULE
   ifneq ($(strip $(UMTS_TDD128_RF_MODULE)), NONE)
      SRC_LIST += $(strip ${PCORE_ROOT})/custom/modem/tl1_rf/$(strip $(UMTS_TDD128_RF_MODULE))/t12193.c
      INC_DIR += $(strip ${PCORE_ROOT})/custom/modem/tl1_rf/$(strip $(UMTS_TDD128_RF_MODULE))
   endif
endif

INC_DIR +=$(call CUSTOM_FLD_MAPPIN,$(strip ${CORE_ROOT})/custom/modem/ps) \
           $(call CUSTOM_FLD_MAPPIN,$(strip ${CORE_ROOT})/custom/middleware/meta) 


INC_DIR += $(strip $(PROJDIR))/verno \
           $(strip $(PROJDIR))/nvram_auto_gen \
          $(strip ${CORE_ROOT})/driver/peripheral/inc 

INC_DIR    +=$(strip ${CORE_ROOT})/driver/sys_drv/init/inc \
             $(strip ${PCORE_ROOT})/interface/service/sys_svc \
             $(strip ${PCORE_ROOT})/interface/driver/peripheral \
             $(strip ${PCORE_ROOT})/driver/drv_def


# SV5
INC_DIR    +=$(strip ${CORE_ROOT})/service/sst/include \
             $(strip ${COMMON_ROOT})/service/sst/include 

INC_DIR    +=$(strip ${COMMON_ROOT})/driver/sys_drv/cache/inc


ifeq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
  INC_DIR += pcore/MoDIS_VC9/drv_sim/include
endif

INC_DIR :=  $(call uniq,$(INC_DIR))



# Define the specified compile options to COMP_DEFS
COMP_DEFS += __UCS2_ENCODING \
            MMI_ON_HARDWARE_P \
            APCS_INTWORK \
            USE_JAM=0 \
            COMPILER_SUPPORTS_LONG=1


ifdef USB_DOWNLOAD_IN_BL
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    COMP_DEFS += REMAPPING
  endif
endif

ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
  COMP_DEFS += REMAPPING
endif

ifneq ($(words $(wildcard $(call CUSTOM_FLD_MAPPIN,$(strip ${CORE_ROOT})/custom/modem/ps)/custom_port_setting.c)), 0)
    COMP_DEFS += __CUSTOMIZED_PORT_SETTING__
endif


