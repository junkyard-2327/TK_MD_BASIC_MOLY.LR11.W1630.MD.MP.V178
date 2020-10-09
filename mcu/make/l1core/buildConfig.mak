#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
SHELL:=/bin/bash
# *************************************************************************
#  Setting folder path accodring to core
# *************************************************************************
PCORE_ROOT     = pcore
L1CORE_ROOT    = l1core
UC_PCORE_ROOT  = PCORE
UC_L1CORE_ROOT = L1CORE
COMMON_ROOT    = common
UNIVERSAL_COMMON = ../common

NO_LTECGEN = FALSE
NO_LTELIB = FALSE
# *************************************************************************
# Build path, directories
# *************************************************************************
FIXPATH        =  .
BUILDDIR       =  $(strip $(FIXPATH))/build
RELDIR         =  $(strip $(FIXPATH))/mtk_rel

COPRODIR      =  l1core
COPRO_PROJDIR =  $(strip $(BUILDDIR))/$(strip $(PROJECT_NAME))/$(strip $(FLAVOR))
COPRO_TARGDIR =  $(strip $(COPRO_PROJDIR))/bin
COPRO_SYSDIR  =  $(strip $(COPRO_PROJDIR))/custom/system

PROJDIR        =  $(strip $(BUILDDIR))/$(strip $(PROJECT_NAME))/$(strip $(FLAVOR))/$(COPRODIR)
CUS_MTK_REL    =  $(strip $(RELDIR))/$(strip $(ORIGINAL_PROJECT_NAME))/$(strip $(ORIGINAL_FLAVOR))/$(COPRODIR)
PROJ_INTERNAL_DIR := $(subst build/,build_internal/,$(PROJDIR))

PROJDIR_PCORE = $(strip $(BUILDDIR))/$(strip $(PROJECT_NAME))/$(strip $(FLAVOR))

include $(strip $(BUILDDIR))/$(strip $(PROJECT_NAME))/$(strip $(FLAVOR))/${CORE_ROOT}/Custom.bld

TARGDIR        =  $(strip $(PROJDIR))/bin
TMPDIR         =  $(strip $(PROJDIR))/tmp
CUSTPACKDIR    =  $(strip $(PROJDIR))/custpack
BUILD_RELDIR   =  $(strip $(PROJDIR))/rel

VIADIR         =  $(strip $(TARGDIR))/via
OBJSDIR        =  $(strip $(TARGDIR))/obj
RULESDIR       =  $(strip $(TARGDIR))/dep
COMPLIBDIR     =  $(strip $(TARGDIR))/lib
COMPLOGDIR     =  $(strip $(TARGDIR))/log
MODULEINFODIR  =  $(strip $(TARGDIR))/module

CUS_MTK_LIB    = $(strip $(CUS_MTK_REL))/lib

GEN_L4DIR      =  $(strip $(BUILD_RELDIR))/L4
GEN_MMIDIR     =  $(strip $(BUILD_RELDIR))/BASIC
REL_L4DIR      =  $(strip $(CUS_MTK_REL))/L4
REL_MMIDIR     =  $(strip $(CUS_MTK_REL))/BASIC

BUILD_L4DIR    =  $(strip $(GEN_L4DIR))
BUILD_MMIDIR   =  $(strip $(GEN_MMIDIR))
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  BUILD_L4DIR    =  $(strip $(REL_L4DIR))
  BUILD_MMIDIR   =  $(strip $(REL_MMIDIR))
  ifneq ($(findstring _PROTOCOL, $(RELEASE_PACKAGE)),)
    BUILD_L4DIR    =  $(strip $(GEN_L4DIR))
    BUILD_MMIDIR   =  $(strip $(GEN_MMIDIR))
  else ifneq ($(findstring _L4, $(RELEASE_PACKAGE)),)
    BUILD_MMIDIR   =  $(strip $(GEN_MMIDIR))
  endif
  ifneq ($(RELEASE_PACKAGE_SUB_PS),)
  ifneq ($(wildcard $(strip $(MAKEDIR))/rel/sub_ps/$(strip $(RELEASE_PACKAGE_SUB_PS)).mak),)
    BUILD_L4DIR    =  $(strip $(GEN_L4DIR))
  endif
  endif
endif

GEN_SSDIR = $(strip $(PROJDIR))/rel/L4/csm/ss
REL_SSDIR = $(strip $(CUS_MTK_REL))/L4/csm/ss
BUILD_SSDIR = $(strip $(GEN_SSDIR))
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  BUILD_SSDIR = $(strip $(REL_SSDIR))
endif

TARGNAME       =  $(strip $(PROJECT_NAME))_$(strip $(SUB_BOARD_VER))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
TARGNAME_L     =  $(strip $(PROJECT_NAME))_$(strip $(SUB_BOARD_VER))_L_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
COPRO_TARGNAME =  $(strip $(PROJECT_NAME))_$(strip $(SUB_BOARD_VER))_P_$(strip $(PLATFORM))_$(strip $(CHIP_VER))


DBG_INFO_VERNO = $(call uc,$(subst .,_,$(VERNO)))
CODE_GEN_LOG := $(strip $(COMPLOGDIR))/codegen.log
BUILD_TSTDIR := $(strip $(PROJDIR))/dhl
BUILD_TSTDIR_SEC := $(strip $(PROJDIR))/dhl/lte_sec
BUILD_TST_DB := $(BUILD_TSTDIR)/database
BUILD_TST_DB_SEC := $(BUILD_TSTDIR_SEC)/database
BPLGUINFOCUSTOMPREFIX = MDDB.L_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
MODISBUILD_TST_DB := $(strip $(BUILD_TST_DB))
MODISBUILD_TST_DB_SEC := $(strip $(BUILD_TST_DB_SEC))
TSTDIR         =  $(strip ${CORE_ROOT})/service/dhl
TSTDIR_SEC =  $(strip $(FIXPATH))/${CORE_ROOT}/modem/lte_sec/dhl
TST_DB         =  $(strip $(TSTDIR))/database
TST_DB_SEC =  $(strip $(TSTDIR_SEC))/database
MODIS_TST_DB   := $(strip $(TST_DB))
MODIS_TST_DB_SEC := $(strip $(TST_DB_SEC))
MODIS_RULESDIR := $(strip $(RULESDIR))
ADT_RULESDIR := $(strip $(PROJ_INTERNAL_DIR))/l1ADT
CGEN_L1_OUTDIR := $(strip $(PROJ_INTERNAL_DIR))/l1trace
ifeq ($(strip $(COMPILER)),GCC)
  CGEN_DEF_FILE = Tgt_Cnf_GCC
else
  CGEN_DEF_FILE = Tgt_Cnf
endif


BUILD_SYSDIR = $(strip $(PROJDIR))/custom/system
BUILD_CODEGENDIR = $(strip $(PROJDIR))/custom/driver/drv_gen

NOT_REMOVAL_DIR_FILE = $(strip $(MAKEDIR))/NotRemovalCodeDir.def

# Settings for emigen
EMI_GENERATOR     = $(strip ${PCORE_ROOT})/tools/emigenMD.pl
MEMORY_DEVICE_HDR = $(strip $(BUILD_SYSDIR))/custom_MemoryDevice.h

# Settings for append2
FLASHFILE = $(strip $(TMPDIR))/~flash_cfg_tmp.c

# Settings for update_img
KEYFILE_PATH = $(strip ${CORE_ROOT})/tools/sw_binding_key.ini

PPP_FOLDER   = ppp_v2
UAS_FDD_FOLDER   = uas
UAS_TDD_FOLDER   = uas_tdd128
GAS_FDD_FOLDER   = gas
GAS_TDD_FOLDER   = gas_tdd128
SCSI_FOLDER  = scsi
FLC_FOLDER     = flc2_v2
ifeq ($(strip $(L1_TDD128)),TRUE)
  #UAS_FOLDER  = uas_tdd128
  #GAS_FOLDER  = gas_tdd128
  #SCSI_FOLDER = scsi_tdd128
  #PPP_FOLDER  = ppp_v1
  ifneq ($(strip $(3G_NEW_DATA_PLANE_ARCH)),TRUE)
    FLC_FOLDER = flc2_v1
  endif
endif
LAS_FOLDER=${L1CORE_ROOT}/modem/las
EISE_FOLDER=${L1CORE_ROOT}/modem/lte_sec/eise

UESIM_SMT_FOLDER =  $(strip ${CORE_ROOT})/modem/smt/uesim
SLEEPDRV_FOLDER = ${CORE_ROOT}/driver/sleep_drv

PURE_VERNO = $(subst .,_, $(call Upper,$(VERNO)))
BPLGUINFOCUSTOMSRCP := MDDB.L_InfoCustomAppSrcP_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_$(strip $(PURE_VERNO)).EDB
NEWTARGNAME    =  $(strip $(TARGNAME)).$(strip $(PURE_VERNO))

# version no dir
VERNODIR       =  $(strip $(PROJDIR))/verno

# summary log
LOG            =  $(strip $(TARGDIR))/link.log
BOOTLOADER_LOG =  $(strip $(TARGDIR))/bootloader.log
BOOTLOADER_EXT_LOG =  $(strip $(TARGDIR))/bootloader_ext.log
LNKERRORLOG    =  $(strip $(TARGDIR))/link_error.log

# Component's log file
COMPLOGDIR     =  $(strip $(TARGDIR))/log
COMPLINTLOGDIR     =  $(strip $(TARGDIR))/lint_log
DB_CHECK_LOG   =  $(strip $(COMPLOGDIR))/db_check.log

ifeq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
EL1_FOLDER=${PCORE_ROOT}/modem/lte_sec/el1_smt
else
EL1_FOLDER=${L1CORE_ROOT}/modem/lte_sec/el1
endif

INFOLOG := $(strip $(COMPLOGDIR))/info.log
INFOMAKELOG = $(strip $(COMPLOGDIR))/infomake.log
MCDDLL_INFOLOG = $(strip $(COMPLOGDIR))/mcddll_info.log
MCDDLL_UPDATE_LOG = $(strip $(COMPLOGDIR))/mcddll_update.log
INFOLOG_$(strip $(BLUETOOTH_SUPPORT)) = $(strip $(COMPLOGDIR_BT))/info_$(strip $(BLUETOOTH_SUPPORT)).log

ifeq ($(strip $(DEMO_PROJECT)),TRUE)
VERNOFILE     :=  make/common/Verno.bld
else
VERNOFILE     := 
endif

SLIM_BRANCH := $(call Upper,$(strip $(BRANCH)))
BRANCH   +=   $(call Upper,$(strip $(PROJECT_NAME)))
# *************************************************************************
# Set defaul value to eliminate "option not define" warning
# *************************************************************************
BM_NEW      = FALSE

INSIDE_MTK = 0
ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
    INSIDE_MTK = 1
endif

DEFAULT_CUSTOMER = MTK MTK_RF PLUTO
ifneq ($(filter $(call Upper,$(strip $(PROJECT_NAME))),$(strip $(DEFAULT_CUSTOMER))),)
  SCATTERNAME = scat$(strip $(PLATFORM)).txt
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    SCATTERNAME := scat$(strip $(PLATFORM))_L1S.txt
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
    SCATTERNAME := scat$(strip $(PLATFORM))_BASIC.txt
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    SCATTERNAME := scat$(strip $(PLATFORM))_UDVT.txt
  endif
else
  SCATTERNAME = scat$(strip $(PROJECT_NAME)).txt
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    SCATTERNAME := scat$(strip $(PROJECT_NAME))_L1S.txt
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
    SCATTERNAME := scat$(strip $(PROJECT_NAME))_BASIC.txt
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    SCATTERNAME := scat$(strip $(PROJECT_NAME))_UDVT.txt
  endif
endif

SCATTERFILE := $(strip $(BUILD_SYSDIR))/$(strip $(SCATTERNAME))
COPRO_SCATTERFILE = $(strip $(COPRO_SYSDIR))/$(strip $(SCATTERNAME))

BL_SCATTERFILE   = $(strip $(BUILD_SYSDIR))/scatBL_$(strip $(PLATFORM)).txt
BL_EXT_SCATTERFILE   = $(strip $(BUILD_SYSDIR))/scatBL_$(strip $(PLATFORM))_ext.txt

ifeq ($(strip $(COMPILER)),GCC)
  SCATTERFILE:= $(subst scat,lds,$(strip $(SCATTERFILE)))
  COPRO_SCATTERFILE := $(subst scat,lds,$(strip $(COPRO_SCATTERFILE)))
  BL_SCATTERFILE:= $(subst scat,lds,$(strip $(BL_SCATTERFILE)))
  BL_EXT_SCATTERFILE:= $(subst scat,lds,$(strip $(BL_EXT_SCATTERFILE)))
else ifeq ($(strip $(COMPILER)),DSPTK)
  SCATTERFILE = $(strip $(BUILD_SYSDIR))/$(strip $(PLATFORM))_dsptk.bcf
else ifeq ($(strip $(COMPILER)),CHESS)
  SCATTERFILE = $(strip $(BUILD_SYSDIR))/$(strip $(PLATFORM))_chess.tcl
endif

SCATTERFILE_FLASHTOOL := $(subst .txt,_flashtool.txt,$(strip $(SCATTERFILE)))
SCATTERFILE_FLASHTOOL_NAME := $(filter %.txt,$(subst /, ,$(SCATTERFILE_FLASHTOOL)))

# *************************************************************************
#  Implicit Rules and Compiler Options
# *************************************************************************
BIN_FILE       =  $(strip $(NEWTARGNAME)).bin
IMG_FILE       =  $(strip $(TARGNAME_L)).elf
SYM_FILE       =  $(strip $(TARGNAME_L)).sym
DMB_FILE       =  $(strip $(TARGNAME)).elf.DMb
PMB_FILE       =  $(strip $(TARGNAME)).elf.PMb
DMBBIN_FILE    =  $(strip $(TARGNAME)).DMb
PMBBIN_FILE    =  $(strip $(TARGNAME)).PMb
READELF_FILE   =  $(strip $(TARGNAME))_readelf.txt

ROM_IMG_FILE   =  rompatch/$(strip $(PLATFORM))/$(strip $(CHIP_VER))/ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
#ifeq ($(strip $(COMPILER)),DSPTK)
MAP_FILE       =  $(strip $(TARGNAME_L)).map
ifneq ($(filter DSPTK CHESS,$(COMPILER)),)
LIS_FILE       =  $(strip $(TARGNAME)).elf.map
else
LIS_FILE       =  $(strip $(TARGNAME_L)).map
endif

COPRO_MAP_FILE = $(strip $(COPRO_TARGNAME)).map
COPRO_SYM_FILE = $(strip $(COPRO_TARGNAME)).sym
# *************************************************************************
# File setting for linux/win
# *************************************************************************
ifeq ($(strip $(OS_VERSION)),MSWin32)
   CGEN := $(subst /,\,$(strip ${COMMON_ROOT})/tools)\Cgen.exe
   POSTGEN := $(strip $(FIXPATH))\common\tools\PostGen\PostGen.exe
   DRV_GEN := $(subst /,\,$(strip ${CORE_ROOT}))\custom\driver\drv\Drv_Tool\DrvGen.exe
   CREATE_EMPTY_TRC_GEN_FILES := $(subst /,\,$(strip ${CORE_ROOT})/tools)\CreateEmptyTrcGenFiles.exe
   MBL_COMPOSER := $(subst /,\,$(strip ${CORE_ROOT})/tools)\MBL_Composer.exe
   DBG_INFOGEN  := $(subst /,\,$(strip ${CORE_ROOT})/tools)\DbgInfoGen.exe
   UPDATE_IMG   := $(subst /,\,$(strip ${CORE_ROOT})/tools)\update_img.exe
   HEADER_TEMP  := $(subst /,\,$(strip $(PROJDIR)))\header_temp
   HTOGETHER    := $(subst /,\,$(strip ${CORE_ROOT})/tools)\hTogether\htogether_list.bat
else ifeq ($(strip $(OS_VERSION)),msys)
   CGEN := $(strip ${COMMON_ROOT})/tools/Cgen.exe
   POSTGEN := $(strip $(FIXPATH))/common/tools/PostGen/PostGen.exe
   CREATE_EMPTY_TRC_GEN_FILES := $(strip ${CORE_ROOT})/tools/CreateEmptyTrcGenFiles.exe
   MBL_COMPOSER := $(strip ${CORE_ROOT})/tools/MBL_Composer
   DBG_INFOGEN  := $(strip ${COMMON_ROOT})/tools/DbgInfo/DbgInfoGen
   UPDATE_IMG   := $(strip ${CORE_ROOT})/tools/update_img
   HEADER_TEMP  := $(strip $(PROJDIR))/header_temp
   HTOGETHER    := $(strip ${CORE_ROOT})/tools/hTogether/htogether_list.sh
else #Linux
   CGEN := $(strip ${COMMON_ROOT})/tools/Cgen
   POSTGEN := $(strip $(FIXPATH))/$(strip ${COMMON_ROOT})/tools/PostGen/PostGen
   CREATE_EMPTY_TRC_GEN_FILES := $(strip ${CORE_ROOT})/tools/CreateEmptyTrcGenFiles
   MBL_COMPOSER := $(strip ${CORE_ROOT})/tools/MBL_Composer
   DBG_INFOGEN  := $(strip ${COMMON_ROOT})/tools/DbgInfo/DbgInfoGen
   UPDATE_IMG   := $(strip ${CORE_ROOT})/tools/update_img
   HEADER_TEMP  := $(strip $(PROJDIR))/header_temp
   HTOGETHER    := $(strip ${CORE_ROOT})/tools/hTogether/htogether_list.sh
endif
# *************************************************************************
# Settings for DSP
# *************************************************************************
DSPDIR       := $(strip $(RELDIR))/$(strip $(ORIGINAL_PROJECT_NAME))/$(strip $(ORIGINAL_FLAVOR))/dsp_rel
DSP_DBF      := $(DSPDIR)/$(strip $(DSP_PROJECT))/$(strip $(DSP_FLAVOR))/final_bin/xml/DSP_Default.dbf

