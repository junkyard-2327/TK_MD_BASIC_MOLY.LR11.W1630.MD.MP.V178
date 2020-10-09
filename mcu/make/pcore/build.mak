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
#
# *************************************************************************
# build.mak  - MOLY build script
#
#  USAGE:
#     ${CORE_ROOT}/tools/make -f[make file] [build_flag] <CUSTOMER> <PROJECT> <ACTION>
#
#     Example:
#     ${CORE_ROOT}/tools/make -fmake/${CORE_ROOT}/build.mak -r -R CUSTOMER=mtk PROJECT=gprs new
#
#  IMPORTANT NOTES:
#
# *************************************************************************

# *************************************************************************
# Set SUFFIXES
# *************************************************************************
.SUFFIXES:
.SUFFIXES: .lis

# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : new cleanall emigen cmmgen asngen nvram_auto_gen codegen asnregen update genlog cleanbin genverno gencustominfo cksysdrv cksysdrv_slim cksysdrv_clean scan remake libs code_generate cleancodegen cleanmod done startbuildlibs gen_infolog drv_feature_check ckmake ckmemlayout ckmemlayout2 removecode genremoveinfo clean_codegen slim_codegen slim_mcddll slim_update ss_lcs_gen backup findpad elfpatch gendsp prepend_gfh cp_dsp_files copy_br_bin cfggen FORCE nvram_edit_h_gen gen_gfh_cfg umts_gen asngen asngen_l4 asnregen copycmm mcddll_update_ltesm ckBBU new_corp copro_info_gen copro_injection pack_bin

# *************************************************************************
# MediaTek is the default CUSTOMER.
# *************************************************************************

# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))
Lower = $(subst Z,z,$(subst Y,y,$(subst X,x,$(subst W,w,$(subst V,v,$(subst U,u,$(subst T,t,$(subst S,s,$(subst R,r,$(subst Q,q,$(subst P,p,$(subst O,o,$(subst N,n,$(subst M,m,$(subst L,l,$(subst K,k,$(subst J,j,$(subst I,i,$(subst H,h,$(subst G,g,$(subst F,f,$(subst E,e,$(subst D,d,$(subst C,c,$(subst B,b,$(subst A,a,$(1)))))))))))))))))))))))))))
# -----------------------------
#  Include scripts
# -----------------------------
include make/${CORE_ROOT}/Option.mak            # Build option definitons
-include make/${CORE_ROOT}/internal_action.mak
-include make/${CORE_ROOT}/standalone_action.mak
ifeq ($(strip $(OS_VERSION)),MSWin32)
-include ${CORE_ROOT}/tools/NVRAMStatistic/nvram_edit_gen.mak
endif

ifeq ($(strip $(COMPILER)),GCC)
    ifneq ($(strip $(COMPOBJS)),)
      ifneq ($(wildcard pcore/modem/el1/el1d),)
        COMPOBJS := $(filter-out $(CUS_MTK_LIB)/el1d_pcore.a,$(COMPOBJS))
      endif
      LINK_OBJ_LIST =$(call sort,$(foreach lib,$(COMPOBJS),-l$(patsubst lib%,%,$(basename $(notdir $(lib))))))
    endif
    ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
      LIBDIR_TEMP := $(CUS_MTK_LIB)
      ifneq ($(strip $(CUS_REL_SRC_COMP) $(CUS_REL_MTK_COMP)),)
        LINK_LIB_LIST = $(call sort,$(foreach lib,$(COMPLIST) $(CUS_REL_MTK_COMP),-l$(lib)))
      endif
      LINK_SEARCH_PATH += -L "$(COMPLIBDIR)" -L "$(CUS_MTK_LIB)"
      LINK_SEARCH_PATH += $(foreach compobjs,$(COMPOBJS) $(BL_COMPOBJS),-L "$(dir $(compobjs))")
    else
      LIBDIR_TEMP := $(COMPLIBDIR)
      LINK_LIB_LIST = $(call sort,$(foreach lib,$(COMPLIST),-l$(lib)))
      LINK_SEARCH_PATH += -L "$(COMPLIBDIR)"
      LINK_SEARCH_PATH += $(foreach compobjs,$(COMPOBJS) $(BL_COMPOBJS),-L "$(dir $(compobjs))")
    endif
    LNKOPT += --start-group -lnosys -lm -lc -lgcc $(sort $(strip $(LINK_OBJ_LIST) $(LINK_LIB_LIST))) --end-group
    LNKOPT := $(subst \,/,$(LNKOPT))
    ADEFTrans = $(strip -defsym $(1)=$(strip $(2)))
endif

ifndef ZIMAGE_AUTO_CONFIG
  ZIMAGE_AUTO_CONFIG = FALSE
endif

NEED_TRANS_CLASSB = FALSE
ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  ifeq ($(strip $(L1_GPRS)),TRUE)
      NEED_TRANS_CLASSB = TRUE
  endif
else
  ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
    ifeq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
      NEED_TRANS_CLASSB = TRUE
    endif
  endif
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  NO_PCIBT = TRUE
endif

ifeq ($(strip $(ORIGINAL_FLAVOR)),SLT)
  NO_PCIBT = TRUE
endif

ifeq ($(strip $(RELEASE_PACKAGE)),REL_SUB_C2K)
  NO_PCIBT = TRUE
endif

NEED_TRANS_UMTS = FALSE
ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
   NEED_TRANS_UMTS = TRUE
endif

ifneq ($(strip $(TEST_LOAD_TYPE)),BASIC)
   ifeq ($(strip $(L1_WCDMA)),TRUE)
      NEED_TRANS_UMTS = TRUE
   endif
endif

-include $(strip $(TMPDIR))/~cleanmod.tmp      # Define clean modules
ifndef DO_CLEAN_MODULE
   # Default clean all
  DO_CLEAN_MODULE   =  FALSE
  CLEAN_MODS        =
else

  ifneq ($(filter L1,$(call Upper,$(CLEAN_MODS))),)
    NEED_CLEAN_CGENLST = TRUE
  else
    NEED_CLEAN_CGENLST = FALSE
  endif
  ifneq ($(filter GL1,$(call Upper,$(CLEAN_MODS))),)
    CLEAN_MODS := $(CLEAN_MODS) l1_ext
  endif
  ifneq ($(filter UL1_W,$(call Upper,$(CLEAN_MODS))),)
    CLEAN_MODS := $(CLEAN_MODS) ul1_ext
  endif
  ifneq ($(filter UL1_HS,$(call Upper,$(CLEAN_MODS))),)
    CLEAN_MODS := $(CLEAN_MODS) ul1_hs_ext
  endif
  ifneq ($(filter UL1_HS_PLUS,$(call Upper,$(CLEAN_MODS))),)
    CLEAN_MODS := $(CLEAN_MODS) ul1_hs_plus_ext
  endif
  ifneq ($(filter EPHY,$(call Upper,$(CLEAN_MODS))),)
    CLEAN_MODS := $(CLEAN_MODS) ephy_ext
  endif
  ifneq ($(filter EL1,$(call Upper,$(CLEAN_MODS))),)
    CLEAN_MODS := $(CLEAN_MODS) el1d_ext_pcore
  endif
  ifneq ($(filter MML1_RF,$(call Upper,$(CLEAN_MODS))),)
    CLEAN_MODS := $(CLEAN_MODS) mml1_rf_ext
  endif

  ifdef SIM_NEW_ARCH
    ifeq ($(strip $(SIM_NEW_ARCH)),TRUE)
      CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out sim,$(comp)),$(comp),$(comp)2))
    endif
  endif

endif

ifeq ($(strip $(call Upper,$(RELEASE_PACKAGE))),REL_SUB_UAS_UMTS)
  REDUCE_HEADER_DEPTH  := FALSE
endif

-include $(strip $(TMPDIR))/~updatemod.tmp     # Define update modules
ifndef DO_UPDATE_MODULE
   # Default update all
  DO_UPDATE_MODULE  =  FALSE
  UPDATE_MODS       =                          #for pcore update modules
  L_UPDATE_MODS     =                          #for l1core update modules
endif

L_ACTION_MODS = 
ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
	L_ACTION_MODS   +=  $(L_UPDATE_MODS)
endif

-include $(strip $(TMPDIR))/~remakemod.tmp     # Define remake modules
ifndef DO_REMAKE_MODULE
   # Default remake all
  DO_REMAKE_MODULE  =  FALSE
   #for pcore  remake modules
  REMAKE_MODS       =
   #for l1core remkae modules
  L_REMAKE_MODS     =
endif

ifeq ($(strip $(DO_REMAKE_MODULE)),TRUE)
	L_ACTION_MODS   +=  $(L_REMAKE_MODS)
endif

-include $(strip $(TMPDIR))/~scanmod.tmp     # Define scan modules
ifndef DO_SCAN_MODULE
   # Default scan all
  DO_SCAN_MODULE  =  FALSE
  SCAN_MODS       =
endif

ifndef EXT_CAM_MODULE
  EXT_CAM_MODULE = NONE
endif

ifndef CMOS_SENSOR
  CMOS_SENSOR = NONE
endif

# default mbis tempfile
ifndef MBIS_BUILD_TIME_TMP
   MBIS_BUILD_TIME_TMP = tmp
endif
ifndef MBIS_BUILD_INFO_LOG
   MBIS_BUILD_INFO_LOG = tmp
endif

ifndef DUMMY_LIS
   DUMMY_LIS = FALSE
endif

CHK_LTE_COMP = FALSE

FULL_PRJ_NAME = $(strip $(PROJECT_NAME))($(strip $(FLAVOR)))

####################################################################
# End of alias build settings.
####################################################################

include make/${CORE_ROOT}/xgenInc.mak

COM_DEFS_TARGET := $(COM_DEFS)
COMMINCDIRS_TARGET := $(COMMINCDIRS)
RULESDIR_TARGET := $(RULESDIR)
XGEN_INC_DIR_ORI := $(XGEN_INC_DIR)
XGEN_INC_DIR_TARGET ?= $(XGEN_INC_DIR)

#################
# MoDIS setting #
#################
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  include make/${CORE_ROOT}/modisConfig.mak
endif

# *************************************************************************
#  Remove Repeated Common Include Path
# *************************************************************************
XGEN_INC_DIR += $(COMMINCDIRS)
XGEN_INC_DIR_TARGET += $(COMMINCDIRS_TARGET)
ifneq ($(call uc,$(strip $(ACTION))),CRIP)
  COMMINCDIRS := $(call uniq,$(COMMINCDIRS))
  XGEN_INC_DIR := $(call uniq,$(XGEN_INC_DIR))
  COMMINCDIRS_TARGET := $(call uniq,$(COMMINCDIRS_TARGET))
  XGEN_INC_DIR_TARGET := $(call uniq,$(XGEN_INC_DIR_TARGET))
endif

# *************************************************************************
# Build path, directories
# *************************************************************************
COM_SCANDEFS   = $(foreach def, $(COM_DEFS),-define $(def))
COM_SCANDEFS_NEW  = $(foreach def, $(COM_DEFS),-D$(def))

# *************************************************************************
#  Target Definitions
# *************************************************************************
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)

  INITLIB        =  $(strip $(COMPLIBDIR))/libsys_drv.a

ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
  MTK_LIBS =  $(foreach COMP,$(filter-out $(PARTIAL_TRACE_LIB),$(CUS_REL_HDR_COMP)),$(CUS_MTK_LIB)/lib$(COMP).a)
  MTK_LIBS += $(foreach COMP,$(filter-out $(PARTIAL_TRACE_LIB),$(CUS_REL_MTK_COMP)),$(CUS_MTK_LIB)/lib$(COMP).a)
  MTK_LIBS += $(foreach COMP,$(filter $(PARTIAL_TRACE_LIB),$(CUS_REL_HDR_COMP)),$(CUS_MTK_LIB_TRACE)/lib$(COMP).a)
  MTK_LIBS += $(foreach COMP,$(filter $(PARTIAL_TRACE_LIB),$(CUS_REL_MTK_COMP)),$(CUS_MTK_LIB_TRACE)/lib$(COMP).a)
else
  MTK_LIBS =  $(foreach COMP,$(CUS_REL_HDR_COMP),$(CUS_MTK_LIB)/lib$(COMP).a)
  MTK_LIBS += $(foreach COMP,$(CUS_REL_MTK_COMP),$(CUS_MTK_LIB)/lib$(COMP).a)
endif

else

  ifneq ($(filter sys_drv,$(COMPLIST)),)
    INITLIB        =  $(strip $(COMPLIBDIR))/libsys_drv.a
  endif

  MTK_LIBS       =

endif


ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(filter gl1,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) l1_ext
  endif
  ifneq ($(filter ul1_w,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) ul1_ext
  endif
  ifneq ($(filter ul1_hs,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) ul1_hs_ext
  endif
  ifneq ($(filter ul1_hs_plus,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) ul1_hs_plus_ext
  endif
  ifneq ($(filter ephy,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) ephy_ext
  endif
  ifneq ($(filter el1d_pcore,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) el1d_ext_pcore
  endif
  ifneq ($(filter mml1_rf,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) mml1_rf_ext
  endif
  ifeq ($(filter verno,$(UPDATE_MODS)),)
    UPDATE_MODS := $(UPDATE_MODS) verno
  endif
  ifeq ($(filter dbinfo,$(UPDATE_MODS)),)
    ifneq ($(TEST_LOAD_TYPE),BASIC)
      UPDATE_MODS := $(UPDATE_MODS) dbinfo
    endif
  endif
  endif
  COMPLIBLIST = $(call sort,$(foreach comp,$(UPDATE_MODS),$(comp).a))
else
  ifeq ($(strip $(DO_REMAKE_MODULE)),TRUE)
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifneq ($(filter gl1,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) l1_ext
    endif
    ifneq ($(filter ul1_w,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) ul1_ext
    endif
    ifneq ($(filter ul1_hs,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) ul1_hs_ext
    endif
    ifneq ($(filter ul1_hs_plus,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) ul1_hs_plus_ext
    endif
    ifneq ($(filter ephy,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) ephy_ext
    endif
    ifneq ($(filter el1d_pcore,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) el1d_ext_pcore
    endif 
    ifneq ($(filter mml1_rf,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) mml1_rf_ext
    endif 
    ifeq ($(filter verno,$(REMAKE_MODS)),)
      REMAKE_MODS := $(REMAKE_MODS) verno
    endif   
    ifeq ($(filter dbinfo,$(REMAKE_MODS)),)
      ifneq ($(TEST_LOAD_TYPE),BASIC)
        REMAKE_MODS := $(REMAKE_MODS) dbinfo
      endif
    endif   
    endif
    COMPLIBLIST = $(call sort,$(foreach comp,$(REMAKE_MODS),$(comp).a))
  else
    COMPLIBLIST = $(call sort,$(foreach comp,$(COMPLIST),$(comp).a))
  endif
endif

ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
  COMPSCANLIST = $(UPDATE_MODS)
else
  ifeq ($(strip $(DO_SCAN_MODULE)),TRUE)
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifneq ($(filter gl1,$(SCAN_MODS)),)
      SCAN_MODS := $(SCAN_MODS) l1_ext
    endif
    ifneq ($(filter ul1_w,$(SCAN_MODS)),)
      SCAN_MODS := $(SCAN_MODS) ul1_ext
    endif
    ifneq ($(filter ul1_hs,$(SCAN_MODS)),)
      SCAN_MODS := $(SCAN_MODS) ul1_hs_ext
    endif
    ifneq ($(filter ul1_hs_plus,$(SCAN_MODS)),)
      SCAN_MODS := $(SCAN_MODS) ul1_hs_plus_ext
    endif
    ifneq ($(filter ephy,$(SCAN_MODS)),)
      SCAN_MODS := $(SCAN_MODS) ephy_ext
    endif
    ifneq ($(filter el1d_pcore,$(SCAN_MODS)),)
      SCAN_MODS := $(SCAN_MODS) el1d_ext_pcore
    endif
    ifneq ($(filter mml1_rf,$(SCAN_MODS)),)
      SCAN_MODS := $(SCAN_MODS) mml1_rf_ext
    endif  
    endif
    COMPSCANLIST = $(SCAN_MODS)
  else
   COMPSCANLIST = $(COMPLIST)
  endif
endif

# either drmadp.a or custom.a will run custominfo.pl
# but some project may not have to compile drmadp.a, so put drmadp.a first
ifneq ($(filter drmadp.a,$(COMPLIBLIST)),)
  CUSTOM_EXIST   =  TRUE
else
  CUSTOM_EXIST   =  FALSE
endif

ifneq ($(filter custom.a,$(COMPLIBLIST)),)
  CUSTOM_EXIST   =  TRUE
else
  ifneq ($(filter ecompass.a image_sensor_sec.a obigo03cpushadp.a obigo03cpushlib.a lgoem.a wise.a,$(COMPLIBLIST)),)
    CUSTOM_EXIST   =  TRUE
  else
    CUSTOM_EXIST   =  FALSE
  endif
endif

ifdef SIM_NEW_ARCH
  ifeq ($(strip $(SIM_NEW_ARCH)),TRUE)
    COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out sim.a,$(comp)),$(comp),sim2.a))
  endif
endif


ifneq ($(strip $(call Upper,$(REMAKE_MODS))),BOOTLOADER)
   CHK_COMPLIST = $(filter-out $(foreach comp,$(COMPLIST),$(comp).a),$(call lc,$(COMPLIBLIST)))
   ifneq ($(words $(CHK_COMPLIST)),0)
         ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
            ifeq ($(strip $(PARTIAL_COPY)),TRUE)
               $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in PC_SRC_COMP of pc_cfg.ini when Partial Copy)
            else
               $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in CUS_REL_SRC_COMP or NOT in CUS_REL_PAR_SRC_COMP)
            endif
         else
            $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in COMPLIST)
         endif
   endif
endif

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  MODULELIS := $(foreach comp,$(sort $(COMPLIST)),$(comp).lis)
else
  ifndef MODULELIS
    MODULELIS := $(foreach comp,$(call lc,$(COMPLIBLIST)),$(subst .a,.lis,$(comp)))
  endif
endif

ifdef SIM_NEW_ARCH
  ifeq ($(strip $(SIM_NEW_ARCH)),TRUE)
    COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out sim,$(comp)),$(comp),$(comp)2))
  endif
endif

CHK_SCANLIST = $(filter-out $(foreach comp,$(COMPLIST),$(comp)),$(COMPSCANLIST))
ifneq ($(words $(CHK_SCANLIST)),0)
  $(error $(CHK_SCANLIST) NOT in COMPLIST)
endif

COMP_DEP_LIST = $(foreach comp,$(sort $(COMPSCANLIST)),$(comp).dep)

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifndef RUN_HTOGETHER
    RUN_HTOGETHER = FALSE
  endif
else
  ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
    ifndef RUN_HTOGETHER
      RUN_HTOGETHER = TRUE
    endif
  endif
endif
else
  RUN_HTOGETHER = FALSE
endif

# *************************************************************************
# Search Paths
# *************************************************************************
vpath
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
vpath %.dep $(subst \,/,$(strip $(RULESDIR)))
vpath %.a $(strip $(OBJSDIR))/lib
vpath %.bin $(strip $(TARGDIR))
endif

# *************************************************************************
#  Debug
# *************************************************************************
ifndef CUSTOM_DEBUG_MODULES
  CUSTOM_DEBUG_MODULES :=
else
  ifneq ($(filter ALL,$(call Upper,$(CUSTOM_DEBUG_MODULES))),)
    CUSTOM_DEBUG_MODULES := $(call Upper,$(COMPLIST))
  else
    ifneq ($(strip $(CUSTOM_DEBUG_MODULES)),NONE)
      CUSTOM_DEBUG_MODULES := $(filter-out NONE,$(call Upper,$(CUSTOM_DEBUG_MODULES)))
    endif
  endif
endif

ifndef CUSTOM_NON_DEBUG_MODULES
  CUSTOM_NON_DEBUG_MODULES :=
else
  ifneq ($(filter ALL,$(call Upper,$(CUSTOM_NON_DEBUG_MODULES))),)
    CUSTOM_NON_DEBUG_MODULES := $(call Upper,$(COMPLIST))
  else
    ifneq ($(strip $(CUSTOM_NON_DEBUG_MODULES)),NONE)
      CUSTOM_NON_DEBUG_MODULES := $(filter-out NONE,$(call Upper,$(CUSTOM_NON_DEBUG_MODULES)))
    endif
  endif
endif

#************************************************************************
# Dependency check
#************************************************************************
# default AUTO_CHECK_DEPEND value depends on the build action, if it is not passed by make command from make.pl
ifndef AUTO_CHECK_DEPEND
  AUTO_CHECK_DEPEND := FALSE
endif
ifneq ($(filter $(MAKECMDGOALS),remake cgen),)
  AUTO_CHECK_CGEN := TRUE
else
  AUTO_CHECK_CGEN := $(AUTO_CHECK_DEPEND)
endif

# CheckNeedCopy
# input: file list to find, priority from low to high
# output: the file that really exists and is needed
CheckNeedCopy = $(lastword $(foreach file,$(1),$(wildcard $(file))))

# CheckNeedCopyDir
# function: find which file need to be copied in different folders, but have same filename
# argument 1: input folder list where to find files, priority from low to high
# argument 2: input file extention name to find
# output: file list that really need copy
CheckNeedCopyDir = $(strip $(subst /,\,$(foreach basefile,$(sort $(foreach file,$(foreach dir,$(subst \,/,$(1)),$(wildcard $(dir)/*$(strip $(2)))),$(notdir $(file)))),$(lastword $(foreach dir,$(subst \,/,$(1)),$(wildcard $(dir)/$(basefile)))))))

# NEED_CHECK_DEPEND_LIST: the common files that affect all actions
NEED_CHECK_DEPEND_LIST := $(PROJECT_MAKEFILE) make/${CORE_ROOT}/Option.mak make/${COMMON_ROOT}/Option.mak
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  NEED_CHECK_DEPEND_LIST += make/${CORE_ROOT}/modisConfig.mak
endif
NEED_CHECK_CODEGEN_LIST := make/${CORE_ROOT}/Codegen.mak
NEED_CHECK_MODIS_LIST := make/${CORE_ROOT}/modisBuild.mak
NEED_CHECK_COMP_LIST := make/${COMMON_ROOT}/Comp.mak

# AUTO_CHECK_DEBUG = TRUE will not delete temp file for gen dep
AUTO_CHECK_DEBUG := FALSE

# CheckNeedDepend
# function: generate makefile command for dependency check
# argument 1: action name, it is used to name the dependency file
# argument 2: folder that the dependency file exists
define CheckNeedDepend
  ifneq ($$(strip $$(AUTO_CHECK_DEPEND)),TRUE)
$$(strip $$(RULESDIR))/$(2)/$(1).det: FORCE
  else
-include $$(strip $$(RULESDIR))/$(2)/./$(1).det
  endif
$(1): $$(strip $$(RULESDIR))/$(2)/$(1).det
$$(strip $$(RULESDIR))/$(2)/$(1).det: $$(NEED_CHECK_DEPEND_LIST)
endef

define CheckNeedDependTarget
  ifneq ($$(strip $$(AUTO_CHECK_DEPEND)),TRUE)
$$(strip $$(RULESDIR_TARGET))/$(2)/$(1).det: FORCE
  else
-include $$(strip $$(RULESDIR_TARGET))/$(2)/./$(1).det
  endif
$(1): $$(strip $$(RULESDIR_TARGET))/$(2)/$(1).det
$$(strip $$(RULESDIR_TARGET))/$(2)/$(1).det: $$(NEED_CHECK_DEPEND_LIST)
endef

define ckMemLayoutProcess
ckMemLayout_$(1).det:
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,ckMemLayout_$(1).det,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$$(IF_EXIST) $$(FIXPATH)/${CORE_ROOT}/tools/ckMemLayout.pl $$(THEN)\
		$$(IF_EXIST) $$(strip $(TARGDIR))/$(2) $$(THEN)\
			$$(IF_EXIST) $$(strip $(TARGDIR))/$(3) $$(THEN)\
				(perl $$(FIXPATH)/${CORE_ROOT}/tools/ckMemLayout.pl 2 TRUE $(4) "$$(strip $(TARGDIR))/$(2)" $$(TMPDIR)/~flash_cfg_tmp.c "$$(strip $$(PROJECT_MAKEFILE))" $$(strip $$(BUILD_SYSDIR)) $$(strip $$(INSIDE_MTK)) $(strip $(INFOMAKELOG)) > $$(strip $$(COMPLOGDIR))/ckmemlayout2_$(1).log  2>&1)$$(WITH) \
				($$(IF_ERR_TRUE) $$(THEN) (echo Error: Failed in ckMemLayout.pl. Please check $$(strip $$(COMPLOGDIR))/ckmemlayout2_$(1).log $$(WITH) exit 1) $$(CMD_END))\
			$$(CMD_END)\
		$$(CMD_END)\
	$$(CMD_END)
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,ckMemLayout_$(1).det,T," >> $(MBIS_BUILD_TIME_TMP)
endif
endef
ifeq ($(strip $(COMPILER)),GCC)
$(eval $(call ckMemLayoutProcess,target,$(MAP_FILE),$(SYM_FILE),$(SCATTERFILE)))
$(eval $(call ckMemLayoutProcess,bootloader,$(BTLD_PREFIX).map,$(BTLD_PREFIX).sym,$(BL_SCATTERFILE)))
$(eval $(call ckMemLayoutProcess,bootloader_ext,$(BTLD_EXT_PREFIX).map,$(BTLD_EXT_PREFIX).sym,$(BL_EXT_SCATTERFILE)))
else
$(eval $(call ckMemLayoutProcess,target,$(TARGNAME).lis,$(SYM_FILE),$(SCATTERFILE)))
$(eval $(call ckMemLayoutProcess,bootloader,$(BTLD_PREFIX).lis,$(BTLD_PREFIX).sym,$(BL_SCATTERFILE)))
$(eval $(call ckMemLayoutProcess,bootloader_ext,$(BTLD_EXT_PREFIX).lis,$(BTLD_EXT_PREFIX).sym,$(BL_EXT_SCATTERFILE)))
endif
#*************************************************************************
# PCIBT check
#*************************************************************************
ifneq ($(strip $(NO_PCIBT)),TRUE)
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    include make/${COMMON_ROOT}/rel/hq/Comp_PCIBT.mak
  endif
endif
TEMP3 := $(patsubst %/,%,$(dir $(subst \,/,$(COMPOBJS))))
TEMP3 :=  $(call uniq,$(TEMP3))
TEMP4 := $(TEMP3) $(COMMINCDIRS)
TEMP4 := $(subst \,/,$(strip $(TEMP4)))


# *************************************************************************
# MD Cooperation Build
# *************************************************************************
new_corp: new

# *************************************************************************
# New Build
# *************************************************************************
ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
  ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
# [TATAKA Migrate] multi-mode skip sysgen asngen asnregen
# multi-mode
new : backup cleanall genlog sysgen cleancodegen eas_gen asngen umts_gen codegen asnregen
  else
# HSPA, TDD128HSPA
new : backup cleanall genlog sysgen cleancodegen asngen umts_gen codegen asnregen
  endif
else
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
# GSM, GPRS
new : backup cleanall genlog sysgen cleancodegen asngen codegen asnregen
  else
# single-mode
# [TATAKA Migrate] single-mode skip sysgen asngen asnregen
new : backup cleanall genlog sysgen cleancodegen eas_gen asngen codegen
#new : backup cleanall genlog sysgen cleancodegen asngen codegen asnregen
  endif
endif

# *************************************************************************
#  concatenate new and update
# *************************************************************************
new : update

# *************************************************************************
#  Update Build
# *************************************************************************
#update : genlog cleanbin codegen mcddll_update cksysdrv_slim remake

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
# HSPA, TDD128HSPA, multi-mode
update : backup genlog cleanbin eas_gen umts_gen codegen
  else
    ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
# GSM, GPRS
update : backup genlog cleanbin codegen
    else
# single-mode
update : backup genlog cleanbin codegen
    endif
  endif
else
# CUSTOM_RELEASE = FALSE
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
# HSPA, TDD128HSPA, multi-mode
update : backup genlog cleanbin eas_gen umts_gen codegen
  else
    ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
# GSM, GPRS
update : backup genlog cleanbin codegen
    else
# single-mode
update : backup genlog cleanbin eas_gen codegen
    endif
  endif
endif

# *************************************************************************
#  concatenate mcddll
# *************************************************************************
ifeq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
# [TATAKA Migrate] LTE single-mode
update : mcddll_update_ltesm
endif

ifneq ($(strip $(ACTION)),slim_update)
# [TATAKA Migrate] only NON single-mode need to build mcddll_update
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
update : mcddll_update
  endif
endif

# *************************************************************************
#  concatenate errc_gen
# *************************************************************************
ifeq ($(LTE_SOURCE_BUILD),TRUE)
update : errc_gen
endif

# *************************************************************************
#  concatenate update and remake
# *************************************************************************
update : cksysdrv_slim remake

# *************************************************************************
#  Remake Build
# *************************************************************************
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(SINGLE_CORE),TRUE)
    ifneq ($(TEST_LOAD_TYPE),BASIC)
remake : backup genlog cleanbin genverno sysgen libs $(BIN_FILE) cmmgen cfggen ckBBU codegen_merge done
    else
remake : backup genlog cleanbin genverno sysgen libs $(BIN_FILE) cmmgen cfggen ckBBU done
    endif
  else
remake : backup genlog cleanbin genverno sysgen libs $(BIN_FILE) cmmgen cfggen ckBBU done
  endif
else # MODIS_CONFIG == TRUE
remake : genlog cleanbin genverno sysgen
endif #ifneq ($(strip $(MODIS_CONFIG)),TRUE)

include make/${CORE_ROOT}/Codegen.mak


# *************************************************************************
# TARGET: LINK_BIN_FILE
#  Executable Targets
# *************************************************************************
LINK_BIN_FILE :GCC_LINK_BIN_FILE

# *************************************************************************
# TARGET: GCC_LINK_BIN_FILE
#  Executable Targets
# *************************************************************************
GCC_LINK_BIN_FILE:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,B," >> $(MBIS_BUILD_TIME_TMP)
endif

	@$(STRCMPEX) def def e $(strip $(TMPDIR))/~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@$(ECHO) -n "-D__NULL_DEF__" >> $(strip $(TMPDIR))/~customIncDef.tmp

	@$(STRCMPEX) inc inc e $(strip $(TMPDIR))/~customInc.tmp $(foreach inc,$(subst \,/,$(COMMINCDIRS)),-I$(inc))

	@$(CAT) $(strip $(TMPDIR))/~customInc.tmp >> $(strip $(TMPDIR))/~customIncDef.tmp

	@$(IF_EXIST) $(strip $(TARGDIR))/module/custom $(THEN)\
		(($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN)  `$(CAT) $(strip $(TARGDIR))/module/custom/custom.def` \
		 $(DO) \
			($(ECHO) -n "-D$(PRE_VAR)i" >>  $(strip $(TMPDIR))/~customIncDef.tmp) $(DONE)) \
		 $(AND) \
		($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(CAT) $(strip $(TARGDIR))/module/custom/custom.inc` \
		 $(DO) \
			(echo -I$(PRE_VAR)i >>  $(strip $(TMPDIR))/~customIncDef.tmp) $(DONE)))\
	 $(CMD_END)

	@$(IF_EXIST) ${CORE_ROOT}/tools/NVRAMStatistic/src/ckSySDrv_flash_cfg_preproc.c $(THEN)\
		$(CC) $(VIA)$(strip $(TMPDIR))/~customIncDef.tmp -E ${CORE_ROOT}/tools/NVRAMStatistic/src/ckSySDrv_flash_cfg_preproc.c > $(strip $(TMPDIR))/~flash_cfg_tmp.c \
	$(CMD_END)

	@echo Linking $(strip $(NEWTARGNAME)) ...
	@perl ${CORE_ROOT}/tools/time.pl -n

	@$(IF_EXIST) $(LOG) $(THEN) ($(DEL_FILE) $(LOG)) $(CMD_END)
	@$(IF_EXIST) $(strip $(COMPLOGDIR))/ckImgSize.log $(THEN) ($(DEL_FILE) $(strip $(COMPLOGDIR))/ckImgSize.log) $(CMD_END)

	@$(ECHO) -n "$(LNKOPT)" > $(strip $(TMPDIR))/~libs.tmp
	@$(IF_EXIST) $(strip $(TMPDIR))/~libs.tmp $(THEN) ($(COPY_FILE) $(strip $(TMPDIR))/~libs.tmp $(strip $(COMPLOGDIR))/link_option.log) $(CMD_END)

 ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
		@$(strip $(LINKER)) -gcc TARGET $(strip $(LINK)) $(strip $(LOG)) $(strip $(VIA)) $(strip $(BIN_CREATE)) $(strip $(TARGDIR)) $(strip $(IMG_FILE)) "$(strip $(BIN_FORMAT))" $(strip $(BIN_FILE)) $(strip $(BUILD_TST_DB)) $(MAP_FILE) $(SYM_FILE) $(strip $(TMPDIR)) "$(strip $(CPL))" $(strip $(DUMP)) $(WITH) \
			($(IF_ERR_TRUE) $(THEN) \
				($(IF_EXIST) $(strip $(TMPDIR))/~aapmc_link_error.tmp $(THEN) \
					(echo Error: link failed. Please check $(TARGDIR)/link.log) $(AND) \
					($(COPY_FILE) $(TARGDIR)/link.log $(strip $(TMPDIR))/aapmc_link.log) $(CMD_END))\
					$(WITH) exit 1\
			$(CMD_END))
  else
		@$(strip $(LINK)) $(strip $(VIA))$(strip $(TMPDIR))/~libs.tmp > $(TARGDIR)/link.log 2>&1 $(WITH) \
			($(IF_ERR_TRUE) $(THEN) \
				(echo Error: link failed. Please check $(TARGDIR)/link.log) $(WITH) \
				($(COPY_FILE) $(TARGDIR)/link.log $(strip $(TMPDIR))/aapmc_link.log) $(WITH) \
				($(IF_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(IMG_FILE)) $(CMD_END))\
				$(WITH) exit 1\
			$(CMD_END))
		@$(IF_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN)\
			$(strip $(DUMP)) -x $(strip $(TARGDIR))/$(IMG_FILE) > $(strip $(TARGDIR))/$(SYM_FILE) 2>&1 \
		$(CMD_END)
  endif
 # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: check_modid
#  check the module id between pcore and l1core
# *************************************************************************
check_modid:
# mbis time probe
ifneq ($(filter __KAL_CROSS_CORE_SUPPORT__ ,$(strip $(COM_DEFS))),)
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip $(PCORE_ROOT))/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

	@$(ECHO) -n "[Start] check module ID between pcore & l1core"
	@$(IF_EXIST) $(PCORE_ROOT)/tools/check_modid.pl $(THEN) \
		(perl ./pcore/tools/check_modid.pl  $(strip $(BUILD_TST_DB))/enumFile $(strip $(L1CORE_BUILD_TST_DB))/enumFile $(strip $(COMPLOGDIR))/$@.log > $(strip $(COMPLOGDIR))/$@.log 2>&1 \
		$(WITH)\
		$(IF_ERR_TRUE) $(THEN) (echo Error: $@ Failed. Please check $(strip $(COMPLOGDIR))/$@.log $(WITH) exit 1) $(CMD_END))\
	 $(CMD_END)
	@$(ECHO) -n "[Done]  check module ID between pcore & l1core"

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip $(PCORE_ROOT))/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
endif


# *************************************************************************
# TARGET: LINK_BIN_FILE_CHECK
#  Executable Targets
# *************************************************************************
ifneq ($(SINGLE_CORE),TRUE)
LINK_BIN_FILE_CHECK: $(COPRO_SYM_FILE) check_modid
endif
LINK_BIN_FILE_CHECK: gen_auto_adjust_mem_1

ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@perl ${CORE_ROOT}/tools/auto_adjust_mem.pl 1 $(TMPDIR)/~auto_adjust_mem_1.log > $(strip $(COMPLOGDIR))/auto_adjust_mem.log $(WITH) \
		($(IF_ERR_TRUE) $(THEN) \
			($(MAKE) -fmake/${CORE_ROOT}/build.mak -r -R update_memconfig) $(WITH) \
				($(IF_ERR_TRUE) $(THEN) (exit 1) $(CMD_END)) \
		$(CMD_END))

ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: copro_injection
#  Get COPRO File offset from Master's sym
# Copy COPRO Binary File to Master's COPRO file offset
# *************************************************************************
copro_injection:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# for checking pcore/l1core layout
	@$(IF_EXIST) $(FIXPATH)/$(strip $(COMMON_ROOT))/tools/AutoGen/postBuild/Check_Layout.pl $(THEN)\
		(perl $(FIXPATH)/$(strip $(COMMON_ROOT))/tools/AutoGen/postBuild/Check_Layout.pl $(strip $(TARGDIR))/$(SYM_FILE) $(L1CORE_SYM_FILE) > $(strip $(COMPLOGDIR))/Check_Layout.log 2>&1) $(WITH) \
		($(IF_ERR_TRUE) $(THEN) echo Error: Check_Layout.pl failed. Please check $(strip $(COMPLOGDIR))/Check_Layout.log $(WITH) exit 1 $(CMD_END))\
	$(CMD_END)

# for update pcore symbol 
	@$(IF_EXIST) $(FIXPATH)/$(strip $(CORE_ROOT))/tools/DSP/PcoreUpdateDSPAddress.pl $(THEN)\
		(perl $(FIXPATH)/$(strip $(CORE_ROOT))/tools/DSP/PcoreUpdateDSPAddress.pl $(strip $(TARGDIR))/$(SYM_FILE) $(strip $(TARGDIR))/$(strip $(IMG_FILE)) $(L1CORE_SYM_FILE) $(ORIACTION) > $(strip $(COMPLOGDIR))/PcoreUpdateDSPAddress.log 2>&1) $(WITH) \
		($(IF_ERR_TRUE) $(THEN) echo Error: PcoreUpdateDSPAddress.pl failed. Please check $(strip $(COMPLOGDIR))/PcoreUpdateDSPAddress.log $(WITH) exit 1 $(CMD_END))\
	$(CMD_END)


# remember to judge the bin_file is folder or not.
#	@$(ECHO) -n "COPRO_BIN = $(strip $(COPRO_TARGDIR))/$(BIN_FILE)" >$(strip $(TMPDIR))/~copro_injection.tmp
	@$(ECHO) -n "L1CORE_BIN = $(strip $(L1CORE_BIN_FILE))" >>$(strip $(TMPDIR))/~copro_injection.tmp
	@$(ECHO) -n "BACKUP_ELF = $(strip $(TMPDIR))/~$(strip $(IMG_FILE))" >>$(strip $(TMPDIR))/~copro_injection.tmp
	@$(ECHO) -n "MAIN_SYM = $(strip $(TARGDIR))/$(SYM_FILE)" >>$(strip $(TMPDIR))/~copro_injection.tmp
	@$(ECHO) -n "MAIN_ELF = $(strip $(TARGDIR))/$(strip $(IMG_FILE))" >>$(strip $(TMPDIR))/~copro_injection.tmp

	@$(IF_EXIST) $(FIXPATH)/$(strip $(CORE_ROOT))/tools/copro_injection.pl $(THEN)\
		(perl $(FIXPATH)/$(strip $(CORE_ROOT))/tools/copro_injection.pl "$(strip $(PROJECT_MAKEFILE))" $(strip $(INFOMAKELOG)) $(strip $(TMPDIR))/~copro_injection.tmp $(ORIACTION) > $(strip $(COMPLOGDIR))/copro_injection.log 2>&1) $(WITH) \
		($(IF_ERR_TRUE) $(THEN) echo Error: copro_injection.pl failed. Please check $(strip $(COMPLOGDIR))/copro_injection.log $(WITH) exit 1 $(CMD_END))\
	$(CMD_END)

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif



# *************************************************************************
# TARGET: FROMELF_BIN_FILE:
#  Executable Targets
# *************************************************************************
ifneq ($(SINGLE_CORE),TRUE)
FROMELF_BIN_FILE: l1core_copro_adj_mem copro_injection
endif
FROMELF_BIN_FILE:

 # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,B," >> $(MBIS_BUILD_TIME_TMP)
endif

	@$(IF_NOT_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN)\
			(echo $(strip $(TARGDIR))/$(IMG_FILE) is not existed!Please check $(TARGDIR)/link.log. $(WITH) exit 1)\
		$(CMD_END)

ifeq ($(strip $(MAIN_CODE_NEED_GFH)),TRUE)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN)\
		(perl $(CORE_ROOT)/tools/iv_copy_process.pl $(strip $(TARGDIR))/$(IMG_FILE) $(strip $(TARGDIR))/$(SYM_FILE) > $(strip $(COMPLOGDIR))/iv_copy_process.log) 2>&1 $(WITH) \
		($(IF_ERR_TRUE) $(THEN) (echo Error: Failed in iv_copy_process.pl. Please check $(strip $(COMPLOGDIR))/iv_copy_process.log $(WITH) exit 1) $(CMD_END)) \
	$(CMD_END)
endif


   # -----------------------------
   # The size of the binary image depends on the available memory on the target
   # platform.
   # -----------------------------
	@echo Creating binary file $(BIN_FILE)
ifeq ($(strip $(COMPILER)),GCC)
	@perl ${CORE_ROOT}/tools/gen_bin_from_elf.pl $(strip $(BIN_CREATE)) $(strip $(SCATTERFILE)) $(strip $(TARGDIR))/$(IMG_FILE) $(strip $(TARGDIR))/$(BIN_FILE) > $(strip $(COMPLOGDIR))/gen_bin_from_elf.log 2>&1 $(WITH) \
	($(IF_ERR_TRUE) $(THEN) (echo Error: Failed in gen_bin_from_elf.pl. Please check $(strip $(COMPLOGDIR))/gen_bin_from_elf.log $(WITH) exit 1) $(CMD_END))
else
	ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
		ifeq ($(strip $(DEMO_PROJECT)),TRUE)
			@$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
		else
			@$(strip $(DIR_INT_569))\win_32-pentium\fromelf.exe $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
		endif
	else
	  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
		@$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
	  else
	    ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
			@$(strip $(DIR_INT_569))\win_32-pentium\fromelf.exe $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
	    else
			@$(strip $(BIN_CREATE)) $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
	    endif
	  endif
	endif
endif

ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
	@$(LIST_DIR) "$(strip $(TARGDIR))/$(strip $(BIN_FILE))/*_GFH" 1>$(DEV_NUL) 2>&1 $(WITH) \
	$(IF_ERR_FALSE) $(THEN) \
		perl ${CORE_ROOT}/tools/get_gfh_files.pl $(strip $(TARGDIR))/$(strip $(BIN_FILE)) GFH > $(strip $(COMPLOGDIR))/get_gfh_files.log 2>&1 $(WITH) \
		($(IF_ERR_TRUE) $(THEN) (echo Error: Failed in get_gfh_files.pl. Please check $(strip $(COMPLOGDIR))/get_gfh_files.log $(WITH) exit 1) $(CMD_END))\
	$(CMD_END)
endif

ifneq ($(filter $(strip $(SV5X_PLATFORM)),$(PLATFORM)),)
	@$(LIST_DIR) "$(strip $(TARGDIR))/$(strip $(BIN_FILE))/*_GFH" 1>$(DEV_NUL) 2>&1 $(WITH) \
	$(IF_ERR_FALSE) $(THEN) \
		perl ${CORE_ROOT}/tools/get_gfh_files.pl $(strip $(TARGDIR))/$(strip $(BIN_FILE)) GFH > $(strip $(COMPLOGDIR))/get_gfh_files.log 2>&1 $(WITH) \
		($(IF_ERR_TRUE) $(THEN) (echo Error: Failed in get_gfh_files.pl. Please check $(strip $(COMPLOGDIR))/get_gfh_files.log $(WITH) exit 1) $(CMD_END))\
	$(CMD_END)
endif

ifneq ($(filter __VI_ENABLED__,$(strip $(COM_DEFS))),)
	@perl pcore\tools\vivaProcess.pl $(strip $(TARGDIR))\$(strip $(BIN_FILE)) $(strip $(PROJECT_MAKEFILE)) >$(strip $(TARGDIR))\log\vivaProcess.log & \
		(if ERRORLEVEL 1 (echo Error in vivaProcess.pl. Please check $(strip $(TARGDIR))\log\vivaProcess.log & exit 1))
endif

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: $(BIN_FILE) and LINK
# *************************************************************************
$(BIN_FILE): LINK POSTBUILD

LINK: LINK_BIN_FILE LINK_BIN_FILE_CHECK FROMELF_BIN_FILE


# *************************************************************************
# TARGET: POSTBUILD
# *************************************************************************
POSTBUILD: GCC_POSTBUILD pack_bin
ifneq ($(wildcard $(CUSTOMIZATION)/log2SD_Catcher_filters_meta.ini),)
ifneq ($(SINGLE_CORE),TRUE)
ifeq ($(filter L1S BASIC,$(TEST_LOAD_TYPE)),)
POSTBUILD: merge_catcher
endif
endif
endif
POSTBUILD:
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
ifneq ($(strip $(PARTIAL_SOURCE)),TRUE)
	@$(MAKE) -fmake/${CORE_ROOT}/build.mak -r -R gen_sfini
  ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
		@$(IF_EXIST) $(CODEGEN_DATABASE_OUT) $(THEN) ($(CGEN) -ltedbv2 -sf $(CODEGEN_DATABASE_OUT) $(MODISBUILD_TST_DB)/sf.ini) $(CMD_END)
    ifneq ($(wildcard $(CUSTOMIZATION)/log2SD_Catcher_filters_meta.ini),)
			@$(IF_EXIST) $(MODISBUILD_TST_DB)/$(BPMDMETADATABASE) $(THEN) \
				($(CGEN) -ltedbv2 -sf $(MODISBUILD_TST_DB)/$(BPMDMETADATABASE) $(MODISBUILD_TST_DB)/sf_meta.ini) \
			$(CMD_END)
    endif
  else
		@$(IF_EXIST) $(CODEGEN_DATABASE_OUT) $(THEN) ($(CGEN) -ltedbv2 -sfcm $(CODEGEN_DATABASE_OUT) $(MODISBUILD_TST_DB)/sf.ini) $(CMD_END)
    ifneq ($(wildcard $(CUSTOMIZATION)/log2SD_Catcher_filters_meta.ini),)
			@$(IF_EXIST) $(MODISBUILD_TST_DB)/$(BPMDMETADATABASE) $(THEN) \
				($(CGEN) -ltedbv2 -sfcm $(MODISBUILD_TST_DB)/$(BPMDMETADATABASE) $(MODISBUILD_TST_DB)/sf_meta.ini) \
			$(CMD_END)
    endif
  endif
endif
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: GCC_POSTBUILD
# *************************************************************************
# Tafang: Skip dsp_process temporarily
ifeq ($(NO_DSP),FALSE)
GCC_POSTBUILD: ckMemLayout_target.det dsp_process copy_br_bin
else
GCC_POSTBUILD: ckMemLayout_target.det copy_br_bin
endif

#=== SBC
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
		(perl $(CORE_ROOT)/tools/gfh_cfg_flash.pl $(strip $(FLASHFILE)) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(call Upper,$(strip $(PROJECT_NAME))_$(strip $(SUB_BOARD_VER))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).bin $(VERNO) "$(strip $(PROJECT_MAKEFILE))" "$(strip $(BUILD_DATE_TIME))" $(strip $(TMPDIR)) > $(strip $(COMPLOGDIR))/gfh_cfg_flash.log 2>&1 $(WITH) \
		($(IF_ERR_TRUE) $(THEN) (echo Error: gfh_cfg_flash.pl Failed!! Please check $(strip $(COMPLOGDIR))/gfh_cfg_flash.log) $(CMD_END))) \
	$(CMD_END)

	@$(IF_NOT_EXIST) $(strip $(TMPDIR))/~gfh_cfg.tmp $(THEN) ($(MAKE) -fmake/$(CORE_ROOT)/build.mak -r -R gen_gfh_cfg) $(CMD_END)
	@$(IF_EXIST) $(strip $(TMPDIR))/~gfh_cfg_flash.tmp $(THEN) ($(CAT) $(strip $(TMPDIR))/~gfh_cfg_flash.tmp >> $(strip $(TMPDIR))/~gfh_cfg.tmp) $(CMD_END)	

	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
		(perl $(CORE_ROOT)/tools/gfh_process.pl $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(strip $(TMPDIR))/~gfh_cfg.tmp "$(strip $(PROJECT_MAKEFILE))" $(strip $(COMPLOGDIR))/gfh_process.log) > $(strip $(COMPLOGDIR))/gfh_process.log 2>&1 $(WITH) \
		($(IF_ERR_TRUE) $(THEN) (echo Error: Failed in gfh_process.pl. Please check $(strip $(COMPLOGDIR))/gfh_process.log $(WITH) exit 1) $(CMD_END)) \
	$(CMD_END)

	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
		(perl $(CORE_ROOT)/tools/append2.pl $(strip $(FLASHFILE)) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(call Upper,$(strip $(PROJECT_NAME))_$(strip $(SUB_BOARD_VER))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))).$(strip $(PURE_VERNO)).bin $(VERNO) "$(strip $(PROJECT_MAKEFILE))" "$(strip $(BUILD_DATE_TIME))" $(strip $(TMPDIR)) $(strip $(SCATTERFILE)) $(SYM_FILE) $(L1CORE_SYM_FILE) $(strip $(INFOMAKELOG))> $(strip $(COMPLOGDIR))/append2.log 2>&1 $(WITH) \
		($(IF_ERR_TRUE) $(THEN) (echo Error: append2.pl Failed!! Please check $(strip $(COMPLOGDIR))/append2.log) $(CMD_END))) \
	$(CMD_END)
#=== SBC

	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/ROM $(THEN)\
		$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BTLD_BIN_FILE)) $(THEN)\
			$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/$(strip $(BTLD_BIN_FILE)) $(THEN)\
				$(DEL_FILE) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/$(strip $(BTLD_BIN_FILE)) \
			$(CMD_END) \
			$(AND) \
			$(COPY_FILE) $(strip $(TARGDIR))/$(strip $(BTLD_BIN_FILE)) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/$(strip $(BTLD_BIN_FILE)) \
		$(CMD_END)\
	$(CMD_END)

ifneq ($(strip $(PARTIAL_SOURCE)),TRUE)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/ROM $(THEN)\
		($(COPY_FILE) $(SCATTERFILE_FLASHTOOL) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/$(strip $(SCATTERFILE_FLASHTOOL_NAME))) \
	$(ELSE) \
		($(COPY_FILE) $(SCATTERFILE_FLASHTOOL) $(strip $(TARGDIR))/$(strip $(SCATTERFILE_FLASHTOOL_NAME))) \
	$(CMD_END)
endif

	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/ROM $(THEN)\
		($(IF_EXIST) $(strip $(TARGDIR))/EXT_BOOTLOADER $(THEN)\
			($(COPY_FILE) $(strip $(TARGDIR))/EXT_BOOTLOADER $(strip $(TARGDIR))/$(strip $(BIN_FILE))/EXT_BOOTLOADER) \
		$(CMD_END))\
	$(CMD_END)

ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
	$(strip $(LINKER)) -gcc TARGETs $(strip $(TARGDIR)) $(strip $(BIN_FILE))
endif

	@$(IF_EXIST) $(strip $(TARGDIR))/"$(subst ~,,$(strip $(notdir $(PROJECT_MAKEFILE))))" $(THEN) $(DEL_FILE) $(strip $(TARGDIR))/"$(subst ~,,$(strip $(notdir $(PROJECT_MAKEFILE))))" $(CMD_END)
	@$(IF_EXIST) "make/${CORE_ROOT}/$(subst ~,,$(notdir $(strip $(PROJECT_MAKEFILE))))" $(THEN) ($(COPY_FILE) "make/${CORE_ROOT}/$(subst ~,,$(notdir $(strip $(PROJECT_MAKEFILE))))" $(strip $(TARGDIR)) > $(DEV_NUL)) $(CMD_END)

	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
		(echo "[MCU MK IMAGE] Generate mk image - Begin" $(AND) \
		$(MOVE) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(strip $(TARGDIR))/$(strip $(BIN_FILE))_ori $(AND) \
		$(MCU_MK_IMAGE_TOOL) $(strip $(TARGDIR))/$(strip $(BIN_FILE))_ori $(MCU_MK_IMAGE_CFG) > $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(AND) \
		$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))_ori $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(BIN_FILE))_ori) $(CMD_END) $(AND) \
		echo "[MCU MK IMAGE] Generate mk image - End")\
	$(CMD_END)

# To support DBG Info Gen.
	@$(IF_EXIST) $(strip $(TMPDIR))/~DbgInfoGen.cfg $(THEN) ($(DEL_FILE) $(strip $(TMPDIR))/~DbgInfoGen.cfg) $(CMD_END)
	@$(ECHOLONGSTRING4) $(strip $(TMPDIR))/~DbgInfoGen.cfg ELF=$(strip $(TARGDIR))/$(IMG_FILE) HW=$(strip $(PLATFORM))_$(strip $(CHIP_VER)) SW=$(strip $(VERNO))
	@$(LNITEM) $(strip $(TMPDIR))/~DbgInfoGen.cfg
	@echo PRJ=$(strip $(BRANCH)) >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
	@echo TIME=$(strip $(BUILD_DATE_TIME)) >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
	@echo DBNAME=MCU_$(UC_PCORE_ROOT) >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
  ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
		@echo DB="$(strip $(NET_PATH))"/$(strip $(BUILD_TST_DB))/DbgInfo_P_$(strip $(SLIM_BRANCH))_$(strip $(PROJECT_NAME))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME))  >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
		@echo SIGN=TRUE  >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
  else
		@echo DB=$(strip $(BUILD_TST_DB))/DbgInfo_P_$(strip $(SLIM_BRANCH))_$(strip $(PROJECT_NAME))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME))  >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
  endif
	@$(ECHOLONGSTRING4) $(strip $(TMPDIR))/~DbgInfoGen.cfg LNKOPT="$(strip $(LNKOPT))"
	@$(LIST_DIR) "$(strip $(TARGDIR))/DbgInfo_$(strip $(SLIM_BRANCH))*" 1>$(DEV_NUL) 2>&1 $(WITH) \
		$(IF_ERR_FALSE) $(THEN) $(DEL_FILE) $(strip $(TARGDIR))/DbgInfo_$(strip $(SLIM_BRANCH))* $(CMD_END)
	@$(LIST_DIR) "$(strip $(BUILD_TST_DB))/DbgInfo_*" 1>$(DEV_NUL) 2>&1 $(WITH) \
		$(IF_ERR_FALSE) $(THEN) $(DEL_FILE) $(strip $(BUILD_TST_DB))/DbgInfo_* $(CMD_END)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(IMG_FILE)) $(THEN)\
		(echo Generating DbgInfo Database... $(WITH) \
		$(DBG_INFOGEN) -CFG-"$(strip $(TMPDIR))/~DbgInfoGen.cfg" 2>$(strip $(COMPLOGDIR))/DbgInfoGen.log $(WITH)  \
		($(IF_ERR_TRUE) $(THEN) (echo DbgInfoGen Error. Please check $(strip $(COMPLOGDIR))/DbgInfoGen.log $(WITH) exit 1) $(CMD_END)))\
		$(CMD_END)

	@$(LIST_DIR) "$(strip $(TARGDIR))/DbgInfo_P*" 1>$(DEV_NUL) 2>&1 $(WITH) \
		$(IF_ERR_FALSE) $(THEN) $(DEL_FILE) $(strip $(TARGDIR))/DbgInfo_P* $(CMD_END)
	@$(IF_EXIST) $(strip $(BUILD_TST_DB))/DbgInfo_P_$(strip $(SLIM_BRANCH))_$(strip $(PROJECT_NAME))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME)) $(THEN)\
		($(COPY_FILE) $(strip $(BUILD_TST_DB))/DbgInfo_P_$(strip $(SLIM_BRANCH))_$(strip $(PROJECT_NAME))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME))* $(strip $(TARGDIR))) \
		$(CMD_END)

	@$(IF_EXIST) $(strip $(BUILD_SYSDIR))/$(strip $(BOARD_VER)).cfg $(THEN)\
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
			($(COPY_FILE) $(strip $(BUILD_SYSDIR))/$(strip $(BOARD_VER)).cfg $(strip $(TARGDIR))/$(strip $(BOARD_VER)).cfg) \
		$(CMD_END))\
	$(CMD_END)
	
# To merge DBG Info Gen.
ifneq ($(SINGLE_CORE),TRUE)
	@perl $(strip $(COMMON_ROOT))/tools/DbgInfo/merge_dbginfo.pl $(strip $(PROJDIR)) $(strip $(SLIM_BRANCH)) $(strip $(PROJECT_NAME)) $(strip $(DBG_INFO_VERNO)) $(WITH)\
	$(IF_ERR_TRUE) $(THEN) (exit 1) $(CMD_END)
endif

# *************************************************************************
# TARGET: pack_bin
# *************************************************************************
pack_bin:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: genverno
# Generate VersionNo
# *************************************************************************
genverno:
   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN)\
		($(ECHO) "$@ START TIME=" >>$(strip $(TARGDIR))/build.log $(AND) \
		perl ${CORE_ROOT}/tools/time.pl -n>>$(strip $(TARGDIR))/build.log) $(CMD_END)

	@echo Generate version number ... [start]>> $(LOG)
	@$(IF_NOT_EXIST) $(VERNODIR) $(THEN)\
		($(MKDIR) $(VERNODIR)) $(CMD_END)

	@$(IF_EXIST) $(strip $(VERNODIR))/verno.c $(THEN) \
		($(DEL_FILE) $(strip $(VERNODIR))/verno.c) $(CMD_END)

	@perl $(strip ${COMMON_ROOT})/tools/genverno.pl "$(strip $(VERNODIR))" "$(strip $(VERNO))" "$(strip $(BUILD_DATE_TIME))" "$(strip $(BRANCH))" "$(strip $(HAL_VERNO))" "$(strip $(HW_VER))" "$(strip $(BUILD))" "$(strip $(FLAVOR))" "$(strip $(PLATFORM))" "$(strip $(DSP_PROJECT))" "$(strip $(DSP_FLAVOR))" "$(strip $(PROJECT_NAME))"

	@echo Generate version number ... [done]>> $(LOG)
	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN)\
		($(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log $(AND) \
		 perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log) $(CMD_END)

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: drv_feature_check
# Check DRV Feature Files
# *************************************************************************
drv_feature_check: gencustominfo gen_infolog
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN)\
		($(ECHO) "$@ START TIME=" >>$(strip $(TARGDIR))/build.log $(AND) \
		perl ${CORE_ROOT}/tools/time.pl -n>>$(strip $(TARGDIR))/build.log) $(CMD_END)

	@$(IF_EXIST) $(strip $(TARGDIR))/log/drv_check.log $(THEN) \
		($(DEL_FILE) $(strip $(TARGDIR))/log/drv_check.log) $(CMD_END)
	@$(IF_EXIST) $(strip $(TARGDIR))/MMI_DRV_DEFS.mak $(THEN) \
		($(DEL_FILE) $(strip $(TARGDIR))/MMI_DRV_DEFS.mak) $(CMD_END)

	@perl ${CORE_ROOT}/tools/drv_feature_check.pl $(subst \,/,$(strip $(PROJDIR))) $(subst \,/,$(strip $(PROJECT_NAME))) $(firstword $(strip $(CC))) $(subst \,/,$(strip $(VIA))) ${CORE_ROOT}/driver/drv_def/drv_features.h $(subst \,/,$(strip $(TARGDIR))/drv_features_option.h) FALSE 0 $(subst \,/,$(strip $(TARGDIR))\MMI_DRV_DEFS.mak) DRV 2>>$(strip $(TARGDIR))/log/drv_check.log

	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN)\
		($(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log $(AND) \
		 perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log) $(CMD_END)

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# To remove codes from the specified file
# *************************************************************************
genremoveinfo:
	@pcore\tools\strcmpex.exe abc abc e $(strip $(TMPDIR))\~com_def.tmp $(strip $(COM_DEFS))
ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	@echo _SST_FUNCTION_ENABLE_ >> $(strip $(TMPDIR))\~com_def.tmp
endif
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
	@if not exist make\$(strip $(PROJECT_NAME))_en.def \
		(type make\SUPERSET_CUSTOM_en.def > make\$(strip $(PROJECT_NAME))_en.def)
endif
	@if not exist make\$(strip $(PROJECT_NAME))_en.def \
		(copy /y nul make\$(strip $(PROJECT_NAME))_en.def > nul)
	@if not exist make\$(strip $(PROJECT_NAME))_dis.def \
		(perl pcore\mtk_tools\Auto_RemovingCode.pl "$(strip $(PROJECT_MAKEFILE))" $(strip $(PROJECT_NAME)) "$(CC)" $(MTK_SUBSIDIARY) $(COMPLOGDIR))
removecode: genremoveinfo
	@echo .> $(TMPDIR)\~customRemovalDir.tmp
	@if exist pcore\mtk_tools\traversedir.pl \
		(perl pcore\mtk_tools\traverseDir.pl "$(REMOVE_DIR)" make\$(strip $(PROJECT_NAME))_en.def make\$(strip $(PROJECT_NAME))_dis.def TRUE TRUE $(TMPDIR)\~customRemovalDir.tmp $(strip $(NOT_REMOVAL_DIR_FILE)))
	@if exist $(strip $(TMPDIR))\~com_def.tmp del $(strip $(TMPDIR))\~com_def.tmp

# *************************************************************************
# Set the CKSYSDRV_DEP
# *************************************************************************
CKSYSDRV_DEP := ${CORE_ROOT}/tools/NVRAMStatistic/src/ckSySDrv_flash_cfg_preproc.c $(strip $(BUILD_SYSDIR))/custom_MemoryDevice.h ${CORE_ROOT}/custom/driver/common/flash_opt.h

# *************************************************************************
# TARGET: $(strip $(COMPLOGDIR))/ckSysDrv.log :
# Check if system drive space is enough or not
# *************************************************************************
$(strip $(COMPLOGDIR))/ckSysDrv.log : $(strip $(CKSYSDRV_DEP))

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
   # If building for basic, l1s, don't run cksysdrv.pl
   # If module "custom" is released to customer with .a only, don't run cksysdrv.pl
   # If NAND_FLASH_BOOTING is TRUE, don't run cksysdrv.pl
ifneq ($(filter __FS_ON__,$(strip $(COM_DEFS))),)
	@echo checking system drive space ...
	@$(STRCMPEX) def def e $(strip $(TMPDIR))/~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> $(strip $(TMPDIR))/~customIncDef.tmp
  ifeq ($(strip $(COMPILER)),GCC)
		@$(STRCMPEX) inc inc e $(strip $(TMPDIR))/~customInc.tmp $(foreach inc,$(subst \,/,$(COMMINCDIRS)),-I$(inc))
  endif
	@($(CAT) $(strip $(TMPDIR))/~customInc.tmp >> $(strip $(TMPDIR))/~customIncDef.tmp) $(AND) \
		($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(CAT) $(strip $(TARGDIR))/module/custom/custom.def `$(DO) \
			($(ECHO) -n "-D$(PRE_VAR)i" >> $(strip $(TMPDIR))/~customIncDef.tmp) \
		$(DONE)) $(AND) \
		($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(CAT) $(strip $(TARGDIR))/module/custom/custom.inc` $(DO) \
			($(ECHO) -n "-I$(PRE_VAR)i" >> $(strip $(TMPDIR))/~customIncDef.tmp) \
		$(DONE)) $(AND)\
		($(CC) $(VIA)$(strip $(TMPDIR))/~customIncDef.tmp -E ${CORE_ROOT}/tools/NVRAMStatistic/src/ckSySDrv_flash_cfg_preproc.c > $(TMPDIR)/~flash_cfg_tmp.c)

	@perl ${CORE_ROOT}/tools/ckSysDrv.pl $(TMPDIR)/~flash_cfg_tmp.c $(strip $(PROJDIR))/cksysdrv/~fs_quota_usage.log $(strip $(PROJDIR))/nvram_auto_gen/~nvram_lid_size.log $(strip $(FEATURE_OVERLOAD)) $(strip $(SYSTEM_DRIVE_ON_NAND)) $(strip $(NVRAM_PSEUDO_MERGE))> $(strip $(COMPLOGDIR))/ckSysDrv.log

endif
	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: cksysdrv_slim
# Check operator setting Files (An independent target)
# *************************************************************************
ifeq ($(MODIS_CONFIG),FALSE)
cksysdrv_slim: $(strip $(COMPLOGDIR))/ckSysDrv.log
	@echo cksysdrv was done.
else
cksysdrv_slim:
endif

cksysdrv: cksysdrv_clean nvram_auto_gen $(strip $(COMPLOGDIR))/ckSysDrv.log
	@echo cksysdrv was done.

cksysdrv_clean:
	@$(IF_EXIST) $(strip $(COMPLOGDIR))/cksysdrv.log $(THEN) \
		($(DEL_FILE) $(strip $(COMPLOGDIR))/cksysdrv.log) $(CMD_END)

# *************************************************************************
# Target: errc_gen
# gen some files by excel table setting
# *************************************************************************
errc_gen:
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@$(IF_EXIST) ${CORE_ROOT}/modem/lte_sec/errc/gen_evt_tbl/gen_evt_tbl.pl $(THEN) \
			((perl ${CORE_ROOT}/modem/lte_sec/errc/gen_evt_tbl/gen_evt_tbl.pl "$(strip $(PROJECT_MAKEFILE))" TARGET $(PROJDIR)  $(strip $(COMPLOGDIR))> $(strip $(COMPLOGDIR))/errc_gen_tbl.log) $(WITH)  \
			$(IF_ERR_TRUE) $(THEN) (echo Error: generate errc files Failed. Please check $(strip $(COMPLOGDIR))/errc_gen_tbl.log $(WITH) exit 1) $(CMD_END)) \
		$(CMD_END)
else
	@$(IF_EXIST) ${CORE_ROOT}/modem/lte_sec/errc/gen_evt_tbl/gen_evt_tbl.pl $(THEN) \
			((perl ${CORE_ROOT}/modem/lte_sec/errc/gen_evt_tbl/gen_evt_tbl.pl "$(strip $(PROJECT_MAKEFILE))" MODIS $(MODISPROJDIR)/_BUILD_XGEN  $(strip $(MODISPROJDIR))/_BUILD_LOG > $(strip $(MODISPROJDIR))/_BUILD_LOG/errc_gen_tbl.log) $(WITH)  \
			$(IF_ERR_TRUE) $(THEN) (echo Error: generate errc files Failed. Please check $(strip $(MODISPROJDIR))/_BUILD_LOG/errc_gen_tbl.log $(WITH) exit 1) $(CMD_END)) \
		$(CMD_END)
endif
	
	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# Target: ckmemlayout
# check scatter file and memory device consistency
# *************************************************************************
ckmemlayout:
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

	@$(IF_EXIST) $(FIXPATH)/${CORE_ROOT}/tools/ckMemLayout.pl $(THEN)\
		(perl $(FIXPATH)/${CORE_ROOT}/tools/ckMemLayout.pl 1 TRUE $(SCATTERFILE) $(strip $(TMPDIR))/~lis_temp $(TMPDIR)/~flash_cfg_tmp.c "$(strip $(PROJECT_MAKEFILE))" $(strip $(BUILD_SYSDIR)) $(strip $(INSIDE_MTK)) $(strip $(INFOMAKELOG)) > $(strip $(COMPLOGDIR))/ckmemlayout1.log) $(CMD_END)

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


ckmemlayout2: ckMemLayout_target.det
   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) -n Done for ckmemlayout2
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: copycmm
# Generate cmm files for different SUB_BOARD_VER
# *************************************************************************
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  RUN_CMMGEN_HQ = TRUE
else ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  RUN_CMMGEN_HQ = TRUE
else
  RUN_CMMGEN_HQ = FALSE
endif

copycmm:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(IF_NOT_EXIST) $(strip $(PROJDIR))/cmm $(THEN)\
		($(MKDIR) $(strip $(PROJDIR))/cmm) $(CMD_END)

#delete files
	@($(LIST_DIR) -n -b "${COMMON_ROOT}/tools/DebuggingSuite/Scripts/*.*" > $(strip $(TMPDIR))/debuggin_suite_scripts_list.tmp 2> $(DEV_NUL) $(WITH)\
	$(IF_ERR_FALSE) $(THEN)\
	$(IF_EXIST) $(strip $(TMPDIR))/debuggin_suite_scripts_list.tmp $(THEN)\
		($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(CAT) $(strip $(TMPDIR))/debuggin_suite_scripts_list.tmp` $(DO) \
			($(IF_EXIST) $(strip $(PROJDIR))/cmm/$(PRE_VAR)i $(THEN) $(DEL_FILE) $(strip $(PROJDIR))/cmm/$(PRE_VAR)i $(CMD_END)) \
		$(DONE))\
	$(CMD_END)\
	$(CMD_END))

	@($(LIST_DIR) -n -b "${COMMON_ROOT}/tools/DebuggingSuite/Scripts/ChipDependent/$(strip $(PLATFORM))/*" > $(strip $(TMPDIR))/debuggin_suite_scripts_chip_list.tmp 2> $(DEV_NUL) $(WITH)\
	$(IF_ERR_FALSE) $(THEN)\
	$(IF_EXIST) $(strip $(TMPDIR))/debuggin_suite_scripts_chip_list.tmp $(THEN)\
		($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(CAT) $(strip $(TMPDIR))/debuggin_suite_scripts_chip_list.tmp` $(DO) \
			($(IF_EXIST) $(strip $(PROJDIR))/cmm/$(PRE_VAR)i $(THEN) $(DEL_DIR) $(strip $(PROJDIR))/cmm/$(PRE_VAR)i $(CMD_END)) \
		$(DONE))\
	$(CMD_END)\
	$(CMD_END))

	@($(LIST_DIR) -n -b "${CORE_ROOT}/tools/DebuggingSuite/Scripts/*.*" > $(strip $(TMPDIR))/debuggin_suite_scripts_list.tmp 2> $(DEV_NUL) $(WITH)\
	$(IF_ERR_FALSE) $(THEN)\
	$(IF_EXIST) $(strip $(TMPDIR))/debuggin_suite_scripts_list.tmp $(THEN)\
		($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(CAT) $(strip $(TMPDIR))/debuggin_suite_scripts_list.tmp` $(DO) \
			($(IF_EXIST) $(strip $(PROJDIR))/cmm/$(PRE_VAR)i $(THEN) $(DEL_FILE) $(strip $(PROJDIR))/cmm/$(PRE_VAR)i $(CMD_END)) \
		$(DONE))\
	$(CMD_END)\
	$(CMD_END))

	@($(LIST_DIR) -n -b "${CORE_ROOT}/tools/DebuggingSuite/Scripts/ChipDependent/$(strip $(PLATFORM))/*" > $(strip $(TMPDIR))/debuggin_suite_scripts_chip_list.tmp 2> $(DEV_NUL) $(WITH)\
	$(IF_ERR_FALSE) $(THEN)\
	$(IF_EXIST) $(strip $(TMPDIR))/debuggin_suite_scripts_chip_list.tmp $(THEN)\
		($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(CAT) $(strip $(TMPDIR))/debuggin_suite_scripts_chip_list.tmp` $(DO) \
			($(IF_EXIST) $(strip $(PROJDIR))/cmm/$(PRE_VAR)i $(THEN) $(DEL_DIR) $(strip $(PROJDIR))/cmm/$(PRE_VAR)i $(CMD_END)) \
		$(DONE))\
	$(CMD_END)\
	$(CMD_END))


#copy files
	@$(IF_EXIST) ${COMMON_ROOT}/tools/DebuggingSuite/Scripts $(THEN)\
		($(COPY_FILE) ${COMMON_ROOT}/tools/DebuggingSuite/Scripts/*.* $(strip $(PROJDIR))/cmm/) \
	$(CMD_END)
	
	@$(IF_EXIST) ${COMMON_ROOT}/tools/DebuggingSuite/Scripts/ChipDependent/$(strip $(PLATFORM)) $(THEN)\
		($(COPY_DIR) ${COMMON_ROOT}/tools/DebuggingSuite/Scripts/ChipDependent/$(strip $(PLATFORM))/ $(strip $(PROJDIR))/cmm/) \
	$(CMD_END)

	@$(IF_EXIST) ${CORE_ROOT}/tools/DebuggingSuite/Scripts $(THEN)\
		($(COPY_FILE) ${CORE_ROOT}/tools/DebuggingSuite/Scripts/*.* $(strip $(PROJDIR))/cmm/) \
	$(CMD_END)
	
	@$(IF_EXIST) ${CORE_ROOT}/tools/DebuggingSuite/Scripts/ChipDependent/$(strip $(PLATFORM)) $(THEN)\
		($(COPY_DIR) ${CORE_ROOT}/tools/DebuggingSuite/Scripts/ChipDependent/$(strip $(PLATFORM))/ $(strip $(PROJDIR))/cmm/) \
	$(CMD_END)

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: cmmgen
# Generate cmm files for different SUB_BOARD_VER
# *************************************************************************
# Tafang: skip cp_dsp_files temporarily
# cmmgen: $(strip $(TMPDIR))/~customIncDef.tmp copycmm cp_dsp_files
cmmgen: $(strip $(TMPDIR))/~customIncDef.tmp copycmm

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

	@$(IF_NOT_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
		((echo $(strip $(TARGDIR))/$(strip $(BIN_FILE)) does not exist. Please check it.) $(WITH) (exit 2)) \
	$(CMD_END)

	@echo Generate cmm files
		@$(IF_EXIST) ${CORE_ROOT}/tools/CMMAutoGen.pl $(THEN) \
			((perl ${CORE_ROOT}/tools/CMMAutoGen.pl 0 $(strip $(PROJDIR))/cmm/$(strip $(TARGNAME_P))_nocode.cmm ../bin/$(IMG_FILE) "$(strip $(PROJECT_MAKEFILE))" $(strip $(BIN_FILE)) $(strip $(TARGDIR))/$(SYM_FILE) $(L1CORE_SYM_FILE) "$(CC)" "$(VIA)" $(strip $(TMPDIR))/~customIncDef.tmp $(strip $(TMPDIR)) $(strip $(INFOMAKELOG)) $(strip $(TMPDIR))/cp_dsp_info.tmp> $(strip $(COMPLOGDIR))/cmmgen_nocode.log) $(WITH)  \
			$(IF_ERR_TRUE) $(THEN) (echo Error: generate CMM file Failed. Please check $(strip $(COMPLOGDIR))/cmmgen_nocode.log $(WITH) exit 1) $(CMD_END)) \
		$(CMD_END)
    ifeq ($(strip $(RUN_CMMGEN_HQ)),TRUE)
			@$(IF_EXIST) ${CORE_ROOT}/tools/CMMAutoGen.pl  $(THEN)\
				((perl ${CORE_ROOT}/tools/CMMAutoGen.pl 1 $(strip $(PROJDIR))/cmm/$(strip $(TARGNAME_P))_HQ_Only.cmm ../bin/$(IMG_FILE) "$(strip $(PROJECT_MAKEFILE))" $(strip $(BIN_FILE)) $(strip $(TARGDIR))/$(SYM_FILE) $(L1CORE_SYM_FILE) "$(CC)" "$(VIA)" $(strip $(TMPDIR))/~customIncDef.tmp $(strip $(TMPDIR)) $(strip $(INFOMAKELOG)) $(strip $(TMPDIR))/cp_dsp_info.tmp> $(strip $(COMPLOGDIR))/cmmgen_hqonly.log) $(WITH) \
				$(IF_ERR_TRUE) $(THEN) (echo Error: generate CMM file Failed. Please check $(strip $(COMPLOGDIR))/cmmgen_hqonly.log $(WITH) exit 1) $(CMD_END))\
			$(CMD_END)
    endif

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: dsp_process
# *************************************************************************
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
  dsp_process: chk_dsp
else
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
     dsp_process: chk_dsp
  endif
endif
dsp_process: cp_dsp_files

# *************************************************************************

# *************************************************************************
# *************************************************************************
# TARGET: chk_dsp
# *************************************************************************
chk_dsp:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) -n "Warning: [DSP Check] Skip DSP Version Check for TK6291 DSP not ready"
#	@$(ECHO) -n "[DSP Check] Start DSP Version Check"
#	@perl ${CORE_ROOT}/mtk_tools/checkDSP.pl $(DSPDIR) "$(strip $(PROJECT_MAKEFILE))" $(VERNO) > $(strip $(COMPLOGDIR))/checkDSP.log 2>&1 $(WITH)\
#	($(IF_ERR_TRUE) $(THEN) echo Error: ${CORE_ROOT}/mtk_tools/checkDSP.pl failed. Please check $(strip $(COMPLOGDIR))/checkDSP.log $(WITH) exit 1 $(CMD_END))
#	@$(ECHO) -n "[DSP Check] End DSP Version Check."

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: cp_dsp_fils
# *************************************************************************
cp_dsp_files:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@perl ${CORE_ROOT}/tools/cp_dsp_files.pl $(strip $(DSPDIR)) $(strip $(BUILD_DSPDIR)) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) "$(strip $(PROJECT_MAKEFILE))" "$(strip $(DSP_VER))" $(strip $(PARTIAL_SOURCE)) $(strip $(TMPDIR))/cp_dsp_info.tmp> $(strip $(COMPLOGDIR))/cp_dsp_files.log 2>&1 $(WITH) \
	($(IF_ERR_TRUE) $(THEN) echo Error: ${CORE_ROOT}/tools/cp_dsp_files.pl failed. Please check $(strip $(COMPLOGDIR))/cp_dsp_files.log $(WITH) exit 1 $(CMD_END))
	
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
# *************************************************************************
# TARGET: copy_br_bin
# Copy boot region files to bin folder 
# *************************************************************************
BR_FLAVOR := DEFAULT
BR_FILE   := cmdScript.bin
ifneq ($(strip $(CHIP_VER)),S00)
  BR_FLAVOR := $(CHIP_VER)
endif
ifneq ($(filter __FPGA__,$(strip $(COM_DEFS))),)
  BR_FLAVOR := FPGA
endif

copy_br_bin:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

ifneq ($(filter $(strip $(PLATFORM)),$(SV5X_PLATFORM)),)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/ROM $(THEN)\
	($(COPY_FILE) ${CORE_ROOT}/custom/system/br_bin/$(strip $(BR_FLAVOR))/$(strip $(BR_FILE)) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/$(strip $(BR_FILE))) \
	$(CMD_END)
	@$(IF_NOT_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/ROM $(THEN)\
	($(COPY_FILE) ${CORE_ROOT}/custom/system/br_bin/$(strip $(BR_FLAVOR))/$(strip $(BR_FILE)) $(strip $(TARGDIR))//$(strip $(BR_FILE))) \
	$(CMD_END)
endif
	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: cfggen
# Generate CFG file for flash tool
# *************************************************************************
cfggen:
ifneq ($(filter $(strip $(PLATFORM)),$(SV5X_PLATFORM)),)
	@echo Generate CFG file for flash tool
	@$(IF_NOT_EXIST)  $(strip $(TMPDIR))/~customIncDef.tmp $(THEN) \
		($(MAKE) -fmake/${CORE_ROOT}/build.mak -r -R PROJECT_NAME=$(strip $(PROJECT_NAME)) PROJECT_MAKEFILE="$(strip $(PROJECT_MAKEFILE))" FLAVOR=$(strip $(FLAVOR)) $(strip $(TMPDIR))/~customIncDef.tmp) $(CMD_END)	
  ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
		@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
			(perl $(FIXPATH)/${CORE_ROOT}/tools/cfgGen.pl 1 $(strip $(TARGDIR)) $(strip $(BIN_FILE)) $(strip $(BTLD_BIN_FILE)) "$(strip $(PROJECT_MAKEFILE))" $(strip $(BUILD_SYSDIR)) $(SCATTERFILE) "$(CC)" "$(VIA)" $(strip $(TMPDIR))/~customIncDef.tmp "$(strip $(NET_PATH))" $(strip $(TMPDIR)) $(strip $(INFOMAKELOG)) -sign> $(strip $(COMPLOGDIR))/cfggen.log) \
		 $(CMD_END)
  else
		@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
			(perl $(FIXPATH)/${CORE_ROOT}/tools/cfgGen.pl 1 $(strip $(TARGDIR)) $(strip $(BIN_FILE)) $(strip $(BTLD_BIN_FILE)) "$(strip $(PROJECT_MAKEFILE))" $(strip $(BUILD_SYSDIR)) $(SCATTERFILE) "$(CC)" "$(VIA)" $(strip $(TMPDIR))/~customIncDef.tmp "$(strip $(NET_PATH))" $(strip $(TMPDIR)) $(strip $(INFOMAKELOG))>  $(strip $(COMPLOGDIR))/cfggen.log) \
		$(CMD_END)
  endif
endif

# *************************************************************************
# TARGET: ckBBU
# *************************************************************************
ckBBU:
ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
	@$(IF_EXIST) ./${CORE_ROOT}/tools/CheckBinaryBlockUsage.pl $(THEN)\
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/ROM $(THEN)\
			(perl ./${CORE_ROOT}/tools/CheckBinaryBlockUsage.pl $(strip $(TMPDIR))/~flash_cfg_tmp.c $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(strip $(PLATFORM)) $(strip $(BUILD_SYSDIR)) > $(strip $(COMPLOGDIR))/CheckBinaryBlockUsage.log 2>&1) $(WITH) \
			($(IF_ERR_TRUE) $(THEN) (echo Error: CheckBinaryBlockUsage Failed!! Please check $(strip $(COMPLOGDIR))/CheckBinaryBlockUsage.log for more details. $(WITH) exit 1) $(CMD_END))\
		$(CMD_END)) $(AND)\
		($(IF_NOT_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/ROM $(THEN)\
			(perl ./${CORE_ROOT}/tools/CheckBinaryBlockUsage.pl $(strip $(TMPDIR))/~flash_cfg_tmp.c $(strip $(TARGDIR)) $(strip $(PLATFORM)) $(strip $(BUILD_SYSDIR)) > $(strip $(COMPLOGDIR))/CheckBinaryBlockUsage.log 2>&1) $(WITH) \
			($(IF_ERR_TRUE) $(THEN) (echo Error: CheckBinaryBlockUsage Failed!! Please check $(strip $(COMPLOGDIR))/CheckBinaryBlockUsage.log for more details. $(WITH) exit 1) $(CMD_END))\
		$(CMD_END))\
	$(CMD_END)
endif

# *************************************************************************
# TARGET:  $(strip $(TMPDIR))/~customIncDef.tmp:
# *************************************************************************
$(strip $(TMPDIR))/~customIncDef.tmp:
	@$(STRCMPEX) def def e  $(strip $(TMPDIR))/~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >>  $(strip $(TMPDIR))/~customIncDef.tmp
  ifeq ($(strip $(COMPILER)),GCC)
		@$(STRCMPEX) inc inc e  $(strip $(TMPDIR))/~customInc.tmp $(foreach inc,$(subst \,/,$(COMMINCDIRS)),-I$(inc))
  else
		@$(STRCMPEX) inc inc e  $(strip $(TMPDIR))/~customInc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
  endif
	@$(CAT)  $(strip $(TMPDIR))/~customInc.tmp >>  $(strip $(TMPDIR))/~customIncDef.tmp
	@$(IF_NOT_EXIST) $(TARGDIR)/module/custom $(THEN) \
		($(MAKE) -fmake/${CORE_ROOT}/build.mak -r -R PROJECT_NAME=$(strip $(PROJECT_NAME)) PROJECT_MAKEFILE="$(strip $(PROJECT_MAKEFILE))" FLAVOR=$(strip $(FLAVOR)) MODULELIS=custom.lis genmoduleinfo)\
	 $(CMD_END)

	@$(IF_EXIST) $(strip $(TARGDIR))/module/custom $(THEN)\
		(($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN)  `$(CAT) $(strip $(TARGDIR))/module/custom/custom.def` \
		 $(DO) \
			(echo -D$(PRE_VAR)i >>  $(strip $(TMPDIR))/~customIncDef.tmp) $(DONE)) \
		 $(AND) \
		($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(CAT) $(strip $(TARGDIR))/module/custom/custom.inc` \
		 $(DO) \
			(echo -I$(PRE_VAR)i >>  $(strip $(TMPDIR))/~customIncDef.tmp) $(DONE)))\
	 $(CMD_END)


# *************************************************************************
# Library Targets
# *************************************************************************
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
ifneq ($(filter $(MAKECMDGOALS),remake),)
ifneq ($(strip $(REMAKE_WITH_CGEN)),FALSE)
libs: cgen
endif
endif
endif

# Michael Chiu add to parallel build in libs
ifneq ($(strip $(PARALLEL)),TRUE)
libs: cleanlib startbuildlibs $(COMPLIBLIST)
else
libs: cleanlib startbuildlibs parallel_lib
endif
parallel_lib:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) -n "================== Start Parallel build =================="
	@$(CHK_TIME)
	@$(IF_EXIST) $(strip $(COMPLOGDIR)/mbis_parallel.log) $(THEN) $(DEL_FILE) $(strip $(COMPLOGDIR)/mbis_parallel.log) $(CMD_END)
ifeq ($(strip $(call Upper,$(BM_NEW))),TRUE)
	@-$(MAKE) -fmake/common/parallel.mak -r -R $(strip $(CMD_ARGU)) --no-print-directory PARALLEL_CORE=$(PCORE_ROOT) COMPLIBLIST="$(COMPLIBLIST)" TMPDIR=$(strip $(TMPDIR)) PROJECT_NAME=$(strip $(PROJECT_NAME)) PROJECT_MAKEFILE="$(strip $(PROJECT_MAKEFILE))" FLAVOR=$(strip $(FLAVOR)) MBIS_EN=$(strip $(MBIS_EN))
else	
	@$(MAKE) -fmake/common/parallel.mak -r -R $(strip $(CMD_ARGU)) --no-print-directory PARALLEL_CORE=$(PCORE_ROOT) COMPLIBLIST="$(COMPLIBLIST)" TMPDIR=$(strip $(TMPDIR)) PROJECT_NAME=$(strip $(PROJECT_NAME)) PROJECT_MAKEFILE="$(strip $(PROJECT_MAKEFILE))" FLAVOR=$(strip $(FLAVOR)) MBIS_EN=$(strip $(MBIS_EN))
endif
	@$(ECHO) -n ""
	@$(ECHO) -n "----------------------------------------------------------------------"
	@$(ECHO) -n "  module                time(min:sec)   warning found    result"
	@$(ECHO) -n "----------------------------------------------------------------------"
	@$(FOR) $(DECLARE_VAR)i $(IN) $(basename $(COMPLIBLIST)) $(DO) \
        (grep -A2 "\[ $(PRE_VAR)i \]" $(strip $(COMPLOGDIR)/$(PRE_VAR)i.log)) $(AND) \
        ($(ECHO) -n "") \
        $(DONE)
	@$(IF_EXIST) $(strip $(COMPLOGDIR)/mbis_parallel.log) $(THEN) $(CAT) $(strip $(COMPLOGDIR)/mbis_parallel.log)| sort -k1.4 -k1.3r >> $(MBIS_BUILD_TIME_TMP) $(CMD_END)
	@$(ECHO) -n "==================  End Parallel build  =================="
	@$(CHK_TIME)
	@$(ECHO) -n ""
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: startbuildlibs
# *************************************************************************
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  startbuildlibs: gencompbld
else
  startbuildlibs:
endif
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@echo Start to build $(COMPLIBLIST)

ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
	@echo Copying header files ......
	@$(IF_EXIST) $(strip $(HEADER_TEMP)) $(THEN) $(DEL_DIR) $(strip $(HEADER_TEMP)) $(CMD_END)
	@$(IF_NOT_EXIST) $(strip $(HEADER_TEMP)) $(THEN) ($(MKDIR) $(strip $(HEADER_TEMP))) $(CMD_END)
	-@$(IF_EXIST) $(HTOGETHER) $(THEN) $(HTOGETHER) $(strip $(HEADER_TEMP)) > $(DEV_NUL) $(CMD_END)
endif

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: cleanlib
# *************************************************************************
cleanlib:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

   # can be moved to genlog
	@$(IF_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(IMG_FILE))) $(CMD_END)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(LIS_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(LIS_FILE))) $(CMD_END)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(SYM_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(SYM_FILE))) $(CMD_END)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(TARGNAME).htm $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(TARGNAME)).htm) $(CMD_END)

	@$(ECHO) -n "Clean $(COMPLIBLIST) under $(strip $(COMPLIBDIR))"
	@$(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(GET_FNAME) $(COMPLIBLIST)` $(DO) \
		($(IF_EXIST) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i".a" $(THEN)\
			$(IF_NOT_EXIST) $(strip $(OBJSDIR))/$(PRE_VAR)i $(THEN) $(MKDIR) $(strip $(OBJSDIR))/$(PRE_VAR)i $(CMD_END)\
		$(CMD_END))\
	$(DONE)
	@$(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(GET_FNAME) $(COMPLIBLIST)` $(DO) \
		($(IF_EXIST) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i".a" $(THEN)\
			$(LIST_DIR) "$(strip $(OBJSDIR))/$(PRE_VAR)i/*.obj" > $(DEV_NUL) 2>&1 $(WITH) \
			$(IF_ERR_FALSE) $(THEN)\
				($(COPY_FILE) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i".a" $(strip $(OBJSDIR))/$(PRE_VAR)i/lib$(PRE_VAR)i".a_bak" > $(DEV_NUL))\
			$(CMD_END)\
		$(CMD_END))\
	$(DONE)

ifdef BOOTLOADER_CHE
  ifeq ($(strip $(call Upper,$(BOOTLOADER_CHE))),ON)
    ifneq ($(strip $(DO_UPDATE_MODULE)),TRUE)
      ifneq ($(strip $(DO_REMAKE_MODULE)),TRUE)
			@$(FOR) $(DECLARE_VAR)i $(IN) $(COMPLIBLIST) $(DO) \
				($(IF_EXIST) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i $(THEN)\
					($(IF) "$(PRE_VAR)i" $(NEQ) "che.a" $(THEN)\
					($(IF) "$(PRE_VAR)i" $(NEQ) "sst_sec.a" $(THEN)\
						($(IF) "$(PRE_VAR)i" $(NEQ) "ssf.a" $(THEN) ($(DEL_FILE) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i) $(CMD_END))\
					$(CMD_END))\
					$(CMD_END))\
				$(CMD_END))\
			$(DONE)
      else
			@$(FOR)  $(DECLARE_VAR)i $(IN) $(COMPLIBLIST) $(DO)\
				($(IF_EXIST) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i $(THEN) ($(DEL_FILE) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i) $(CMD_END))\
			$(DONE)
      endif
    else
			@$(FOR) $(DECLARE_VAR)i $(IN) $(COMPLIBLIST) $(DO) \
				($(IF_EXIST) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i $(THEN) ($(DEL_FILE) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i) $(CMD_END))\
			$(DONE)
    endif
  else
	@$(FOR) $(DECLARE_VAR)i $(IN) $(COMPLIBLIST) $(DO) \
		($(IF_EXIST) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i $(THEN) ($(DEL_FILE) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i) $(CMD_END))\
	$(DONE)
  endif
else
	@$(FOR) $(DECLARE_VAR)i $(IN) $(COMPLIBLIST) $(DO) \
		($(IF_EXIST) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i $(THEN) ($(DEL_FILE) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i) $(CMD_END))\
	$(DONE)
endif

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: %.a
# *************************************************************************
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
%.a:

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,P_$(@F),L," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(IF) "$(strip $(MBIS_EN_OBJ_LOG))" $(EQU) "TRUE" $(THEN)\
		($(IF_NOT_EXIST) $(TARGDIR)/log/mbis/$* $(THEN) \
			($(MKDIR) $(TARGDIR)/log/mbis/$*) \
		$(CMD_END) $(AND)\
		($(LIST_DIR) "$(TARGDIR)/log/mbis/$*/*.mbis" 1>$(DEV_NUL) 2>&1 $(WITH) \
		$(IF_ERR_FALSE) $(THEN) \
			($(DEL_FILE) $(TARGDIR)/log/mbis/$*/*.mbis)\
		$(CMD_END)))\
	 $(CMD_END)

	@$(IF_NOT_EXIST) $(strip $(COMPLIBDIR)) $(THEN) \
		($(MKDIR) $(COMPLIBDIR)) \
	$(CMD_END)

	@echo Beginning $* component build process ... >> $(LOG)

	@perl ${CORE_ROOT}/tools/time.pl
	@$(ECHO) -n Building $*
	@$(ECHO) -n "                    LOG: $(strip $(COMPLOGDIR))/$*.log"

	@$(IF_NOT_EXIST) $(strip $(OBJSDIR))/$* $(THEN) \
		($(MKDIR) $(strip $(OBJSDIR))/$*) \
	$(CMD_END)
	@$(IF) "$(ACTION)" $(EQU) "new" $(THEN) \
		$(IF_EXIST) $(strip $(RULESDIR))/$*.dep $(THEN) \
			$(DEL_FILE) $(strip $(RULESDIR))/$*.dep \
		$(CMD_END) \
	$(CMD_END)
	@$(IF) "$(ACTION)" $(EQU) "bm_new" $(THEN) \
		$(IF_EXIST) $(strip $(RULESDIR))/$*.dep $(THEN)\
			$(DEL_FILE) $(strip $(RULESDIR))/$*.dep \
		$(CMD_END)\
	$(CMD_END)
	@$(IF_NOT) "$(ACTION)" $(EQU) "remake" $(THEN) \
		$(IF_NOT_EXIST) $(strip $(RULESDIR))/$* $(THEN) \
			$(MKDIR) $(strip $(RULESDIR))/$* \
		$(CMD_END)\
	$(CMD_END)
	@$(IF) "$(ACTION)" $(EQU) "new" $(THEN)\
		($(LIST_DIR) "$(strip $(RULESDIR))/$*/*.det" 1>$(DEV_NUL) 2>&1 $(WITH) \
		$(IF_ERR_FALSE) $(THEN) $(DEL_FILE) $(strip $(RULESDIR))/$*/*.det $(CMD_END))\
	$(CMD_END)
	@$(IF) "$(ACTION)" $(EQU) "bm_new" $(THEN) \
		($(LIST_DIR) "$(strip $(RULESDIR))/$*/*.det" 1>$(DEV_NUL) 2>&1 $(WITH)\
		$(IF_ERR_FALSE) $(THEN) $(DEL_FILE) $(strip $(RULESDIR))/$*/*.det $(CMD_END))\
	$(CMD_END)

	@$(LIST_DIR) "*.via" 1>$(DEV_NUL) 2>&1 $(WITH) \
		$(IF_ERR_FALSE) $(THEN)  $(DEL_FILE) *.via $(CMD_END)
	@$(LIST_DIR) "*.d" 1>$(DEV_NUL) 2>&1 $(WITH) \
		$(IF_ERR_FALSE) $(THEN) $(DEL_FILE) *.d $(CMD_END)

   # -----------------------------
   # invoke component build script
   # -----------------------------
# Start to extract obj
    ifneq ($(strip $(RVCT_PARTIAL_LINK)),TRUE)
		@$(IF_EXIST) $(strip $(OBJSDIR))/$*/lib$*.a_bak $(THEN)\
			($(LIST_DIR) "$(subst \,/,$(OBJSDIR))/$*/*.obj" 1>$(DEV_NUL) 2>&1 || perl ${CORE_ROOT}/tools/extract_obj_from_lib.pl  $(subst \,/,$(OBJSDIR))/$*/lib$*.a_bak  $(subst \,/,$(OBJSDIR))/$* $(subst \,/,$(LIB)) $(TARGDIR)/module/$*/$*.lis) \
		$(CMD_END)
    endif
# End of extract obj

	@$(ECHO) "$* START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

	@$(MAKE) -fmake/${COMMON_ROOT}/Comp.mak -k -r -R TMPDIR=$(strip $(TMPDIR)) $(strip $(CMD_ARGU)) --no-print-directory COMPONENT=$* setup_env > $(strip $(COMPLOGDIR))/$*_setEnv.log 2>&1

  ifeq ($(strip $(call Upper,$(BM_NEW))),TRUE)
		@$(IF_NOT_EXIST) $(strip $(COMPLOGDIR))/$* $(THEN) \
			$(MKDIR) $(strip $(COMPLOGDIR))/$* \
		$(CMD_END)

		@($(MAKE) -fmake/${COMMON_ROOT}/Comp.mak -k -r -R TMPDIR=$(strip $(TMPDIR)) $(strip $(CMD_ARGU)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))/$*.log 2>&1) $(WITH) \
		($(IF_ERR_TRUE) $(THEN)\
			(perl ${CORE_ROOT}/tools/get_log.pl $(strip $(COMPLOGDIR))/$*.log $(strip $(COMPLOGDIR))/$* $(HTOGETHER) $(strip $(HEADER_TEMP))) $(AND) \
			($(DEL_DIR) $(strip $(COMPLOGDIR))/$*) $(AND) \
			(exit 1) \
		$(ELSE) \
			(perl ${CORE_ROOT}/tools/get_log.pl $(strip $(COMPLOGDIR))/$*.log $(strip $(COMPLOGDIR))/$* $(HTOGETHER) $(strip $(HEADER_TEMP))) $(AND) \
			($(DEL_DIR) $(strip $(COMPLOGDIR))/$*) \
		$(CMD_END))
  else
		@$(IF_NOT_EXIST) $(strip $(COMPLOGDIR))/$* $(THEN) \
			$(MKDIR) $(strip $(COMPLOGDIR))/$* \
		$(CMD_END)

		@($(MAKE) -fmake/${COMMON_ROOT}/Comp.mak -r -R TMPDIR=$(strip $(TMPDIR)) $(strip $(CMD_ARGU)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))/$*.log 2>&1) $(WITH) \
		($(IF_ERR_TRUE) $(THEN) \
			(perl ${CORE_ROOT}/tools/get_log.pl $(strip $(COMPLOGDIR))/$*.log $(strip $(COMPLOGDIR))/$* $(HTOGETHER) $(strip $(HEADER_TEMP))) $(AND) \
			($(DEL_DIR) $(strip $(COMPLOGDIR))/$*) $(AND) \
			(exit 1) \
		$(ELSE) \
			(perl ${CORE_ROOT}/tools/get_log.pl $(strip $(COMPLOGDIR))/$*.log $(strip $(COMPLOGDIR))/$* $(HTOGETHER) $(strip $(HEADER_TEMP))) $(AND) \
			($(DEL_DIR) $(strip $(COMPLOGDIR))/$*) \
		$(CMD_END))
  endif

ifeq ($(strip $(WIFI_SUPPORT)),MT5911)
	@$(IF) "$*" $(EQU) "wndrv" $(THEN)\
		(($(IF_NOT_EXIST) $(call CUSTOM_FLD_MAPPING,${CORE_ROOT}/custom/drv/wifi) $(THEN) \
			$(MKDIR) $(call CUSTOM_FLD_MAPPING,${CORE_ROOT}/custom/drv/wifi)) $(AND) \
			($(IF_EXIST) $(OBJSDIR)/lib/libwndrv.a $(THEN)\
				($(MOVE) $(OBJSDIR)/lib/libwndrv.a $(call CUSTOM_FLD_MAPPING,${CORE_ROOT}/custom/drv/wifi)/libwndrv.a))\
			$(CMD_END)\
		$(CMD_END))\
	$(CMD_END)
endif

	@($(CAT) $(strip $(COMPLOGDIR))/$*.log >> $(LOG))

	@perl ./${CORE_ROOT}/tools/chk_lib_err_warn.pl $(strip $(COMPLOGDIR))/$*.log

	@$(ECHO) "$* END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

   # mbis time probe
	@$(IF) "$(strip $(MBIS_EN_OBJ_LOG))" $(EQU) "TRUE" $(THEN)\
		($(LIST_DIR) "$(TARGDIR)/log/mbis/$*/*.mbis" 1>$(DEV_NUL) 2>&1 || exit 0 $(AND) (perl ${CORE_ROOT}/tools/mbis.pl -o $(TARGDIR)/log/mbis/$*)) \
	$(CMD_END)
	@$(LIST_DIR) "$(TARGDIR)/log/mbis/$*/*.mbis" 1>$(DEV_NUL) 2>&1 || exit 0 $(AND) (($(DEL_FILE) $(TARGDIR)/log/mbis/$*/*.mbis) $(AND) ($(DEL_DIR) $(TARGDIR)/log/mbis/$*))
   ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,P_$(@F),L," >> $(MBIS_BUILD_TIME_TMP)
   endif
endif #ifneq ($(strip $(MODIS_CONFIG)),TRUE)


# *************************************************************************
# Scan Target For Scanning Header Dependencies
# *************************************************************************
ifeq ($(strip $(CHECK_SCAN)),TRUE)
scan: $(COMP_DEP_LIST)
else
scan: cleandep $(COMP_DEP_LIST)
endif
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@echo Scanning Header Dependencies finished.

ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
	@$(IF_EXIST) $(strip $(HEADER_TEMP)) $(THEN) $(DEL_DIR) $(strip $(HEADER_TEMP)) $(CMD_END)
endif
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

cleandep:
   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(FOR) $(DECLARE_VAR)i $(IN) $(COMPSCANLIST) $(DO) \
		(echo clean $(PRE_VAR)i.dep) $(WITH) \
		($(IF_EXIST) $(strip $(RULESDIR))/$(PRE_VAR)i.dep $(THEN) $(DEL_FILE) $(strip $(RULESDIR))/$(PRE_VAR)i.dep $(CMD_END)) \
	$(DONE)

ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
	@$(IF_EXIST) $(strip $(HEADER_TEMP)) $(THEN) $(DEL_DIR) $(strip $(HEADER_TEMP)) $(CMD_END)
	@$(IF_NOT_EXIST) $(strip $(HEADER_TEMP)) $(THEN) ($(MKDIR) $(strip $(HEADER_TEMP))) $(CMD_END)
	-@$(IF_EXIST) $(HTOGETHER) $(THEN) $(HTOGETHER) $(strip $(HEADER_TEMP)) > $(DEV_NUL) $(CMD_END)
endif

   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
%.dep: gencompbld
   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@echo scan $* dependency. >> $(LOG)
	@echo scan $* dependency ...
	@$(IF_NOT_EXIST) $(strip $(RULESDIR))/$@ $(THEN)\
		($(MAKE) -fmake/${COMMON_ROOT}/Comp.mak -k -r -R --no-print-directory TMPDIR=$(strip $(TMPDIR)) $(strip $(CMD_ARGU)) COMPONENT=$* setup_env > $(strip $(COMPLOGDIR))/$*_setEnv.log 2>&1) $(AND) \
		($(MAKE) -fmake/${COMMON_ROOT}/Comp.mak -k -r -R --no-print-directory TMPDIR=$(strip $(TMPDIR)) $(strip $(CMD_ARGU)) COMPONENT=$* update_dep > $(strip $(COMPLOGDIR))/$*_dep.log 2>&1) $(AND) \
		($(IF_EXIST) $(strip $(COMPLOGDIR))/$* $(THEN) ($(DEL_DIR) $(strip $(COMPLOGDIR))/$*)$(CMD_END)) $(AND) \
		($(LIST_DIR) "$(strip $(COMPLOGDIR))/$*_dep.log" > $(DEV_NUL) 2>&1 $(WITH) \
			$(IF_ERR_FALSE) $(THEN) ($(DEL_FILE) $(strip $(COMPLOGDIR))/$*_dep.log) $(CMD_END)) \
	$(CMD_END)

   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
endif

# *************************************************************************
# TARGET: cleanall
# Standard "cleanall" Target
# *************************************************************************
cleanall:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(IF_NOT_EXIST) $(BUILDDIR) $(THEN)\
		$(MKDIR) $(BUILDDIR)\
	$(CMD_END)
	@$(IF_NOT_EXIST) $(TARGDIR) $(THEN)\
		$(MKDIR) $(TARGDIR) \
	$(CMD_END)
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

   # -----------------------------
   # Check build root, target, and project directories
   #
   # build ->
   #  +-$(PROJECT_NAME)
   #     +-$(FLAVOR)
   #        +-dep    - Dependency directory
   #        +-ojb    - Object directory
   #        +-log    - log directory
   #        +-lib    - libraries directory
   # -----------------------------

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@$(ECHO) -n "Cleaning directories under $(strip $(PROJDIR)) ..."

	-@$(IF_NOT_EXIST) $(TARGDIR) $(THEN)\
		($(MKDIR) $(TARGDIR)) \
	$(ELSE) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(NEWTARGNAME).bin/ROM $(THEN) ($(DEL_DIR)  $(strip $(TARGDIR))/$(NEWTARGNAME).bin) $(CMD_END)) $(AND) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(NEWTARGNAME).bin     $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(NEWTARGNAME).bin) $(CMD_END)) $(AND) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(IMG_FILE)) $(CMD_END)) $(AND) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(LIS_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(LIS_FILE))) $(CMD_END)) $(AND) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(SYM_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(SYM_FILE)) $(CMD_END)) $(AND) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(TARGNAME).htm $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(TARGNAME).htm) $(CMD_END)) $(AND) \
		($(LIST_DIR) "$(strip $(TARGDIR))/*.log" > $(DEV_NUL) 2>&1 $(WITH) \
			$(IF_ERR_FALSE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/*.log) $(CMD_END))\
	$(CMD_END)

	@$(IF_EXIST) $(COMPLOGDIR) $(THEN)\
		($(LIST_DIR) "$(strip $(COMPLOGDIR))/*.log" > $(DEV_NUL) 2>&1 $(WITH) \
			$(IF_ERR_FALSE) $(THEN) ($(DEL_FILE) $(strip $(COMPLOGDIR))/*.log) $(CMD_END))\
	$(CMD_END)
else
  ifeq ($(strip $(PROJDIR)),$(strip $(BUILDDIR))/$(strip $(PROJECT_NAME))/$(strip $(FLAVOR)))
    # MoDIS is not separated from Target
	@$(IF_EXIST) $(MODISPROJDIR)/_BUILD_XGEN $(THEN) $(DEL_DIR) $(MODISPROJDIR)/_BUILD_XGEN $(CMD_END)
  endif
endif #ifneq ($(strip $(MODIS_CONFIG)),TRUE)

	@$(IF_NOT_EXIST) $(COMPLOGDIR) $(THEN)\
		($(MKDIR) $(COMPLOGDIR)) \
	$(CMD_END)

ifneq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
   # -----------------------------
   # Remove TST database files
   # -----------------------------
	@$(IF_EXIST) $(CODE_GEN_LST) $(THEN)\
		($(COPY_FILE) $(CODE_GEN_LST) $(strip $(TMPDIR))/~codegenlis.tmp > $(DEV_NUL)) $(AND) \
		($(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(CAT) $(CODE_GEN_LST)` $(DO) \
			($(IF_EXIST) $(PRE_VAR)i $(THEN) ($(DEL_FILE) $(PRE_VAR)i) $(CMD_END)) \
		 $(DONE)) $(AND) \
		($(IF_EXIST) $(CODE_GEN_LST) $(THEN) ($(DEL_FILE) $(CODE_GEN_LST)) $(CMD_END)) \
	 $(CMD_END)

	@$(IF_NOT_EXIST) $(PROJDIR) $(THEN) ($(MKDIR) $(PROJDIR)) $(CMD_END)

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
   # -----------------------------
   # Check component directories
   # -----------------------------
   #
	@$(ECHO) -n "Cleaning dep files under $(RULESDIR)"
	@$(IF_EXIST) $(strip $(RULESDIR)) $(THEN) ($(DEL_DIR) $(strip $(RULESDIR))) $(CMD_END)
	@$(IF_NOT_EXIST) $(RULESDIR) $(THEN) ($(MKDIR) $(RULESDIR)) $(CMD_END)
	@$(ECHO) -n "Cleaning obj files under $(OBJSDIR)"
	@$(IF_EXIST) $(strip $(OBJSDIR)) $(THEN) ($(DEL_DIR) $(strip $(OBJSDIR))) $(CMD_END)
	@$(IF_NOT_EXIST) $(OBJSDIR) $(THEN) ($(MKDIR) $(OBJSDIR)) $(CMD_END)
	@$(ECHO) -n "Cleaning lib files under $(COMPLIBDIR)"
	@$(IF_EXIST) $(strip $(COMPLIBDIR)) $(THEN) ($(DEL_DIR) $(strip $(COMPLIBDIR))) $(CMD_END)
	@$(IF_NOT_EXIST) $(COMPLIBDIR) $(THEN) ($(MKDIR) $(COMPLIBDIR)) $(CMD_END)

	@$(IF_NOT_EXIST) $(strip $(COMPLIBDIR)) $(THEN)\
		($(MKDIR) $(COMPLIBDIR)) \
	$(ELSE) \
		($(ECHO) -n Cleaning lib files under $(COMPLIBDIR)) $(AND) \
		($(LIST_DIR) "$(strip $(COMPLIBDIR))/*.a" > $(DEV_NUL) 2>&1 $(WITH) \
			($(IF_ERR_FALSE) $(THEN) $(DEL_FILE) $(strip $(COMPLIBDIR))/*.a $(CMD_END)))\
	$(CMD_END)
	
	@$(IF_EXIST) $(strip $(PROJDIR))/nvram_auto_gen $(THEN) ($(DEL_DIR) $(strip $(PROJDIR))/nvram_auto_gen) $(CMD_END)
endif #ifneq ($(strip $(MODIS_CONFIG)),TRUE)
endif
	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n  >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: cleanbin
# Standard "genlog" Target
# *************************************************************************
cleanbin:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN) ($(DEL_DIR) $(strip $(TARGDIR))/$(strip $(BIN_FILE))) $(CMD_END)
else
	@$(IF_EXIST) $(MODISPROJDIR)/MoDIS/$(MODIS_MODE)/MoDIS.exe $(THEN) $(DEL_FILE) $(MODISPROJDIR)/MoDIS/$(MODIS_MODE)/MoDIS.exe $(CMD_END)
	@$(IF_EXIST) $(MODISPROJDIR)/MoDIS/$(MODIS_MODE)/MoDIS.exe $(THEN) exit 2 $(CMD_END)
endif
ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
	@$(IF_EXIST) $(strip $(CGEN_CFG_MODEM)) $(THEN) $(DEL_FILE) $(strip $(CGEN_CFG_MODEM)) $(CMD_END)
endif

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n>>$(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: genlog
# Standard "genlog" Target
# *************************************************************************
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(filter $(MAKECMDGOALS),new),)
    genlog: gen_infolog drv_feature_check
  endif
  genlog: gen_infolog_modis gen_infomakelog
else
  genlog: gen_infolog gen_infomakelog drv_feature_check
endif

genlog:
ifneq ($(PCIBT_ACTION_LIST),)
	@$(PCIBT_SCRIPT_CMD) $(INFOMAKELOG) $(PCIBT_ACTION_LIST) 2>$(strip $(TARGDIR))/GlobalIncCheck.log $(WITH) $(IF_ERR_TRUE) $(THEN) ($(CAT) $(strip $(TARGDIR))/GlobalIncCheck.log $(WITH) exit 1) $(CMD_END)
	@$(ECHO) -n PCORE GENLOG done.
endif

ifeq ($(strip $(ACTION)),genlog)
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
ifneq ($(strip $(SINGLE_CORE)),TRUE)
	@perl $(strip $(L1CORE_ROOT))/make.pl "$(strip $(PROJECT_NAME))($(strip $(FLAVOR))).mak" "genlog" $(WITH)\
	$(IF_ERR_TRUE) $(THEN) echo Error: l1core generate genlog failed. $(WITH) exit 1 $(CMD_END)
endif
endif
endif

# *************************************************************************
# Standard "cleanmod" Target
# *************************************************************************
cleanmod:
   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
   # -----------------------------
   # Check build root, target, and project directories
   #
   # build ->
   #  +-$(PROJECT_NAME)
   #     +-$(FLAVOR)
   #        +-dep    - Dependency directory
   #        +-ojb    - Object directory
   #        +-log    - log directory
   #        +-lib    - libraries directory
   # -----------------------------
	@echo Cleaning directories under $(strip $(PROJDIR)) ...
	@$(IF_NOT_EXIST) $(BUILDDIR) $(THEN) \
		($(MKDIR) $(BUILDDIR)) $(CMD_END)

	@$(IF_NOT_EXIST) $(TARGDIR) $(THEN) \
		($(MKDIR) $(TARGDIR)) \
	$(ELSE) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(NEWTARGNAME).bin/NUL $(THEN) ($(DEL_DIR) $(strip $(TARGDIR))/$(NEWTARGNAME).bin) $(CMD_END)) $(WITH) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(NEWTARGNAME).bin $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(NEWTARGNAME).bin) $(CMD_END)) $(WITH) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(IMG_FILE)) $(CMD_END)) $(WITH) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(LIS_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(LIS_FILE))) $(CMD_END)) $(WITH) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(SYM_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(SYM_FILE)) $(CMD_END)) $(WITH) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(TARGNAME).htm $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(TARGNAME).htm) $(CMD_END)) $(WITH) \
		($(LIST_DIR) "$(strip $(TARGDIR))/*.log" 1>$(DEV_NUL) 2>&1 $(WITH)\
			$(IF_ERR_FALSE) $(THEN) \
				($(DEL_FILE) $(strip $(TARGDIR))/*.log) \
			$(CMD_END)) \
	$(CMD_END)

	@$(IF_NOT_EXIST) $(COMPLOGDIR) $(THEN)\
		($(MKDIR) $(COMPLOGDIR)) \
	$(ELSE) \
		($(FOR) $(DECLARE_VAR)i $(IN) $(CLEAN_MODS) $(DO) \
			($(IF_EXIST) $(strip $(COMPLOGDIR))/$(PRE_VAR)i.log $(THEN) ($(DEL_FILE) $(strip $(COMPLOGDIR))/$(PRE_VAR)i.log) $(CMD_END)) \
			$(DONE)) \
	$(CMD_END)

	@$(IF_NOT_EXIST) $(PROJDIR) $(THEN) ($(MKDIR) $(PROJDIR)) $(CMD_END)
	@$(IF_NOT_EXIST) $(OBJSDIR) $(THEN) ($(MKDIR) $(OBJSDIR)) $(CMD_END)

   # -----------------------------
   # Check component directories
   # -----------------------------
	@$(FOR) $(DECLARE_VAR)i $(IN) $(CLEAN_MODS) $(DO)\
		($(IF_NOT_EXIST) $(strip $(OBJSDIR))/$(PRE_VAR)i $(THEN) ($(MKDIR) $(strip $(OBJSDIR))/$(PRE_VAR)i) \
		$(ELSE) \
			(echo Cleaning object files under $(PRE_VAR)i) $(WITH) \
			($(LIST_DIR) "$(OBJSDIR)/$(PRE_VAR)i/*.*" 1>$(DEV_NUL) 2>&1 $(WITH)\
					$(IF_ERR_FALSE) $(THEN) \
					($(DEL_FILE) $(OBJSDIR)/$(PRE_VAR)i/*.*) \
			$(CMD_END)) \
		$(CMD_END))\
	$(DONE) \

	@$(IF_NOT_EXIST) $(COMPLIBDIR) $(THEN)\
		($(MKDIR) $(COMPLIBDIR)) \
	$(ELSE) \
		(echo Cleaning library files $(CLEAN_MODS) under $(COMPLIBDIR)) $(WITH) \
		($(FOR) $(DECLARE_VAR)i $(IN) $(CLEAN_MODS) $(DO)\
			($(IF_EXIST) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i.a $(THEN) ($(DEL_FILE) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i.a) $(CMD_END))\
		$(DONE)) \
	$(CMD_END)

ifeq ($(NEED_CLEAN_CGENLST),TRUE)
		echo Cleaning code gen files
		@$(IF_EXIST) $(CODE_GEN_LST) $(THEN)\
			($(FOR) $(DECLARE_VAR)i $(IN) $(CODE_GEN_LST) $(DO)\
				($(IF_EXIST) $(PRE_VAR)i $(THEN) ($(DEL_FILE) $(PRE_VAR)i) $(CMD_END))\
			$(DONE)) \
		$(CMD_END)

		@$(IF_EXIST) $(CODE_GEN_LST) $(THEN)\
		(($(COPY_FILE) $(CODE_GEN_LST) $(strip $(TMPDIR))/~codegenlis.tmp >$(DEV_NUL)) $(AND) \
		($(DEL_FILE) $(CODE_GEN_LST)) \
	 $(CMD_END)
endif
   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: gen_infolog
# dump the compile option & include path to $(INFOLOG)
# *************************************************************************
gen_infolog:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN)\
		($(ECHO) "$@ START TIME=" >>$(strip $(TARGDIR))/build.log $(AND) \
		perl ${CORE_ROOT}/tools/time.pl -n>>$(strip $(TARGDIR))/build.log) $(CMD_END)

	@$(IF_NOT_EXIST) $(COMPLOGDIR) $(THEN) \
		($(MKDIR) $(COMPLOGDIR)) $(CMD_END)

	@$(STRCMPEX) def def e $(strip $(TMPDIR))/~def.tmp $(foreach def,$(sort $(COM_DEFS_TARGET)),$(def))
	@$(STRCMPEX) inc inc e $(strip $(TMPDIR))/~inc.tmp $(foreach inc,$(COMMINCDIRS_TARGET),$(inc))
	@$(LNITEM) $(strip $(TMPDIR))/~def.tmp
	@$(LNITEM) $(strip $(TMPDIR))/~inc.tmp

	@($(ECHO) -n "[ COMMON OPTION ]" > $(INFOLOG)) $(AND) \
		($(CAT) $(strip $(TMPDIR))/~def.tmp >> $(INFOLOG))
	@($(ECHO) -n "[ COMMON INCLUDE PATH ]" >> $(INFOLOG)) $(AND) \
		($(CAT) $(strip $(TMPDIR))/~inc.tmp >> $(INFOLOG))

	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN) \
		($(ECHO) "$@ END TIME=" >>$(strip $(TARGDIR))/build.log $(AND) \
		perl ${CORE_ROOT}/tools/time.pl -n>>$(strip $(TARGDIR))/build.log) $(CMD_END)
   
   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: gen_infomakelog
# dump details compile info, release info to $(INFOMAKELOG) for debugging or tracking
# *************************************************************************
gen_infomakelog:
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

	@$(STRCMPEX) def def e $(INFOMAKELOG) COM_DEFS = $(call sort, $(foreach def,$(COM_DEFS),$(def)))
	@$(STRCMPEX) def def e $(strip $(TMPDIR))/~remove.tmp COMMINCDIRS = $(foreach inc,$(COMMINCDIRS),$(inc))
	@$(ECHOLONGSTRING5) $(INFOMAKELOG) XGEN_INC_DIR_ORI $(strip $(XGEN_INC_DIR_ORI))
	@$(CAT) $(strip $(TMPDIR))/~remove.tmp >> $(INFOMAKELOG)
	@$(ECHOLONGSTRING) $(INFOMAKELOG) COMP_TRACE_DEFS_MODEM $(COMP_TRACE_DEFS_MODEM)
	@$(ECHOLONGSTRING) $(INFOMAKELOG) COMP_TRACE_DEFS_FP $(COMP_TRACE_DEFS_FP)
	@$(ECHOLONGSTRING) $(INFOMAKELOG) COMP_TRACE_DEFS $(COMP_TRACE_DEFS_MODEM) $(COMP_TRACE_DEFS_FP)
	@$(ECHO) -n COMPLIST = $(call sort, $(foreach def,$(COMPLIST),$(def))) >> $(INFOMAKELOG)
	@$(ECHO) -n LTE_SEC_COMP = $(call sort, $(foreach def,$(LTE_SEC_COMP),$(def))) >> $(INFOMAKELOG)
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@$(ECHOLONGSTRING) $(INFOMAKELOG) COMPOBJS $(COMPOBJS)
	@$(ECHOLONGSTRING) $(INFOMAKELOG) CUS_REL_OBJ_LIST $(CUS_REL_OBJ_LIST)
	@$(ECHOLONGSTRING) $(INFOMAKELOG) CUS_REL_BASE_COMP $(CUS_REL_BASE_COMP)
endif
	@$(ECHO) -n CUS_REL_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_SRC_COMP),$(def))) >> $(INFOMAKELOG)

	@$(ECHO) -n CUS_REL_MTK_COMP = $(call sort, $(foreach def,$(CUS_REL_MTK_COMP),$(def))) >> $(INFOMAKELOG)
	@$(ECHO) -n TST_DB = $(strip $(BUILD_TST_DB)) >> $(INFOMAKELOG)

ifneq ($(strip $(SWITCH_FOLDER)),)
	@$(ECHO) -n SWITCH_FOLDER = $(strip $(SWITCH_FOLDER))>> $(INFOMAKELOG)
endif
	@$(ECHO) -n LEVEL = $(strip $(LEVEL)) >> $(INFOMAKELOG)
	@$(ECHO) -n CUSTOM_RELEASE = $(strip $(CUSTOM_RELEASE)) >> $(INFOMAKELOG)
	@$(ECHO) -n VERNO = $(strip $(VERNO)) >> $(INFOMAKELOG)
	@$(ECHO) -n MTK_SUBSIDIARY = $(strip $(MTK_SUBSIDIARY)) >> $(INFOMAKELOG)
#	@$(ECHO) -n HEADER_TEMP = $(strip $(HEADER_TEMP)) >> $(INFOMAKELOG)
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@$(ECHO) -n CUSTOM_DEBUG_MODULES = $(strip $(CUSTOM_DEBUG_MODULES))>> $(INFOMAKELOG)
	@$(ECHO) -n CUSTOM_NON_DEBUG_MODULES = $(strip $(CUSTOM_NON_DEBUG_MODULES))>> $(INFOMAKELOG)
else
	@$(ECHO) -n MODIS_EN_LIBS = $(strip $(MODIS_EN_LIBS)) >> $(INFOMAKELOG)
	@$(ECHO) -n MODIS_DIS_LIBS = $(strip $(MODIS_DIS_LIBS)) >> $(INFOMAKELOG)
	@$(ECHO) -n MODIS_MTK_LIBS = $(strip $(MODIS_MTK_LIBS)) >> $(INFOMAKELOG)
	@$(ECHO) -n MODIS_EN_OBJS = $(strip $(MODIS_EN_OBJS)) >> $(INFOMAKELOG)
	@$(ECHO) -n CUS_MODIS_LIB = $(strip $(CUS_MODIS_LIB)) >> $(INFOMAKELOG)
	@$(ECHO) -n MODIS_MODE = $(strip $(MODIS_MODE)) >> $(INFOMAKELOG)
	@$(ECHO) -n MODIS_MODE_DEFAULT = $(strip $(MODIS_MODE_DEFAULT)) >> $(INFOMAKELOG)
	@$(ECHO) -n MODIS_INCREDIBUILD = $(strip $(MODIS_INCREDIBUILD)) >> $(INFOMAKELOG)
	@$(ECHO) -n MODIS_UESIM = $(strip $(MODIS_UESIM)) >> $(INFOMAKELOG)
	@$(ECHO) -n MODISDIR = $(MODISDIR) >>$(INFOMAKELOG)
	@$(ECHO) -n MODISPROJDIR = $(MODISPROJDIR) >>$(INFOMAKELOG)
  ifeq ($(strip $(MODIS_COMPILER)),MINGW)
	@$(ECHO) -n CFLAGS_MODIS = $(CFLAGS_MODIS) >>$(INFOMAKELOG)
	@$(ECHO) -n LNKOPT_MODIS_START = $(LNKOPT_MODIS_START) >>$(INFOMAKELOG)
	@$(ECHO) -n LNKOPT_MODIS_END = $(LNKOPT_MODIS_END) >>$(INFOMAKELOG)
  endif
endif
	@$(IF_EXIST) $(strip $(TMPDIR))/cus_folder.tmp $(THEN) \
		($(CAT) $(strip $(TMPDIR))/cus_folder.tmp >> $(INFOMAKELOG)) $(CMD_END)
	@$(ECHO) -n CUSTOM_SYSTEM_FOLDER = $(call CUSTOM_FLD_MAPPING,custom\system)>> $(INFOMAKELOG)

ifdef TK_MD_CUS
	@$(ECHO) -n TK_MD_CUS = $(TK_MD_CUS) >> $(INFOMAKELOG)
endif

	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN)\
		($(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log $(AND) \
		 perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log) $(CMD_END)
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


ifeq ($(strip $(ACTION)),new)
  ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
done: end send
  else
done: end send
  endif
else
done: end send
endif


# *************************************************************************
# TARGET: end
# *************************************************************************
end:
# -----------------------------
# Clean temporary files in make directory
# -----------------------------
   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/ROM $(THEN)\
		($(LIST_DIR) "$(strip $(TARGDIR))/$(strip $(BIN_FILE))/*.cfg" > $(DEV_NUL) 2>&1 $(WITH) \
		 $(IF_ERR_FALSE) $(THEN)\
		 $(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/$(SCATTERFILE_FLASHTOOL_NAME) $(THEN) \
			($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(BIN_FILE))/$(SCATTERFILE_FLASHTOOL_NAME)*) \
		$(CMD_END) \
		$(CMD_END)) \
	$(ELSE) \
		($(LIST_DIR) "$(strip $(TARGDIR))/*.cfg" > $(DEV_NUL) 2>&1 $(WITH)\
		$(IF_ERR_FALSE) $(THEN) \
		$(IF_EXIST) $(strip $(TARGDIR))/$(SCATTERFILE_FLASHTOOL_NAME) $(THEN) \
			($(DEL_FILE) $(strip $(TARGDIR))/$(SCATTERFILE_FLASHTOOL_NAME)*) \
		$(CMD_END) \
		$(CMD_END)) \
	$(CMD_END)

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ifneq ($(strip $(FEATURE_OVERLOAD)),TRUE)
	@echo check system drive ....
	@$(IF_EXIST) $(strip $(COMPLOGDIR))/ckSysDrv.log $(THEN)\
		(perl ${CORE_ROOT}/tools/chk_sysdrv_log.pl $(strip $(COMPLOGDIR))/ckSysDrv.log $(strip $(TARGDIR))/$(strip $(BIN_FILE))) $(WITH) \
		($(IF_ERR_TRUE) $(THEN) (echo Error: cksysdrv has errors. Delete the binary file. $(WITH) exit 1) $(CMD_END)) \
	$(CMD_END)
    endif
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@echo Check if any error happened during the build process .....
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
		perl ${CORE_ROOT}/tools/parse_comp_err.pl $(strip $(PROJDIR)) $(MODIS_CONFIG) $(strip $(TMPDIR)) $(CMD_END)
	@$(IF_EXIST) $(strip $(TMPDIR))/comp_err.txt $(THEN)\
		$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
			(echo Some error happened during the build process. Delete the binary file.) $(WITH) \
			($(DEL_DIR) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(WITH) exit 1) $(CMD_END)\
		$(CMD_END)
endif

# -----------------------------
# remove dep and via folders under build folder
# -----------------------------
#	@if exist $(strip $(TARGDIR))\dep (rd /S /Q $(strip $(TARGDIR))\dep)
#	@$(IF_EXIST) $(strip $(TARGDIR))/via $(THEN) ($(DEL_DIR) $(strip $(TARGDIR))/via) $(CMD_END)  

#	echo Cleaning $(strip $(TMPDIR))\~*.tmp files ...
#	if exist $(strip $(TMPDIR))\~*.tmp \
#		del $(strip $(TMPDIR))\~*.tmp
	@$(IF_EXIST) $(strip $(HEADER_TEMP)) $(THEN) ($(DEL_DIR) $(strip $(HEADER_TEMP))) $(CMD_END)
ifneq ($(strip $(OS_VERSION)),MSWin32)
	@$(IF_EXIST) $(FIXPATH)/nul $(THEN) $(DEL_FILE) $(FIXPATH)/nul $(CMD_END)
	@$(IF_EXIST) $(FIXPATH)/NUL $(THEN) $(DEL_FILE) $(FIXPATH)/NUL $(CMD_END)
endif
	@echo Done.
	@perl ${CORE_ROOT}/tools/time.pl -n
   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: send
# *************************************************************************
send:
ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
  ifeq ($(strip $(SEND_FILE)),TRUE)
		-perl pcore\tools\packbin.pl $(strip $(TARGDIR)) $(strip $(BUILD_TST_DB))
			$(strip $(SENDER)) -all $(strip $(TARGDIR)) $(strip $(BIN_FILE)) "$(strip $(PROJECT_NAME))($(strip $(FLAVOR)))"
  else
    ifneq ($(strip $(NOT_SEND_FILE_BY_DEFAULT)),TRUE)
			$(strip $(SENDER)) -all $(strip $(TARGDIR)) $(strip $(BIN_FILE)) "$(strip $(PROJECT_NAME))($(strip $(FLAVOR)))"
    endif
  endif
endif


# *************************************************************************
# TARGET: ckmake
# *************************************************************************
ckmake:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN)\
		($(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log $(AND) \
		perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log) \
	$(CMD_END)
	@perl $(strip ${COMMON_ROOT})/tools/chk_verno.pl $(VERNO)
	@$(IF_NOT_EXIST) $(strip $(COMPLOGDIR)) $(THEN) \
		($(MKDIR) $(strip $(COMPLOGDIR))) \
	 $(CMD_END)
	@perl $(strip ${COMMON_ROOT})/tools/chk_feature_option.pl "$(strip $(PROJECT_MAKEFILE))" $(strip $(COMPLOGDIR)) > $(strip $(COMPLOGDIR))/chk_feature_option.log

ifeq ($(strip $(OS_VERSION)),MSWin32)
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	perl $(strip ${COMMON_ROOT})/tools/chk_env.pl make "$(strip $(PROJECT_MAKEFILE))" -internal $(strip $(COMPLOGDIR))
  else
	perl $(strip ${COMMON_ROOT})/tools/chk_env.pl make "$(strip $(PROJECT_MAKEFILE))" -customer $(strip $(COMPLOGDIR))
  endif
else
	perl $(strip ${COMMON_ROOT})/tools/chk_env.pl make "$(strip $(PROJECT_MAKEFILE))" -internal $(strip $(COMPLOGDIR))
endif
else
  ifeq ($(strip $(call Upper,$(OS_VERSION))),LINUX)
    ifeq ($(strip $(CHK_ENV_FLAG)),TRUE)
	@perl $(strip ${COMMON_ROOT})/tools/chk_env_linux.pl -chkenv "$(strip $(CC))" $(WITH) \
	($(IF_ERR_TRUE) $(THEN) (echo Error: current Build Env. is not recommendation. $(WITH) exit 1) $(CMD_END))
    else
	@perl $(strip ${COMMON_ROOT})/tools/chk_env_linux.pl -no_chkenv "$(strip $(CC))" $(WITH) \
	($(IF_ERR_TRUE) $(THEN) (echo Error: current Build Env. is not recommendation. $(WITH) exit 1) $(CMD_END))
    endif
  endif
endif

	@echo makefile check is done

	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN)\
		($(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log $(AND)\
		perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log) \
	 $(CMD_END)
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: backup
# *************************************************************************
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
backup : getoptions
  ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
  endif
	@$(IF_EXIST) $(strip $(COMPLOGDIR))/auto_adjust_mem.log $(THEN) ($(DEL_FILE) $(strip $(COMPLOGDIR))/auto_adjust_mem.log) $(CMD_END)
	@$(IF_EXIST) $(strip $(TARGDIR))/MODEM_RESV_SIZE_DEBUG $(THEN) ($(DEL_DIR)  $(strip $(TARGDIR))/MODEM_RESV_SIZE_DEBUG) $(CMD_END)

	@$(IF_EXIST) $(strip $(PROJDIR))/md_rename $(THEN) \
		($(DEL_DIR) $(strip $(PROJDIR))/md_rename)$(CMD_END)

	@$(IF_EXIST) $(strip $(TARGDIR))/dummy_$(SYM_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/dummy_$(SYM_FILE)) $(CMD_END)
  ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
  endif
else
backup:
endif

# *************************************************************************
# TARGET: getoptions
# *************************************************************************
getoptions:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T,"             >> $(MBIS_BUILD_TIME_TMP)
	@$(ECHO) -n "CFLAGS,$(CFLAGS)"         >> $(MBIS_BUILD_INFO_LOG)  $(AND)\
	 $(ECHO) -n "CPLUSFLAGS,$(CPLUSFLAGS)" >> $(MBIS_BUILD_INFO_LOG)  $(AND)\
	 $(ECHO) -n "LIBOPT,$(LIBOPT)"         >> $(MBIS_BUILD_INFO_LOG)  $(AND)\
	 $(ECHO) -n "LNKOPT,$(LNKOPT)"         >> $(MBIS_BUILD_INFO_LOG)  
endif
	@$(STRCMPEX) def def e $(strip $(TMPDIR))/~mbis_def.tmp $(foreach def,$(COM_DEFS),$(def))

ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) "COM_DEFS," >>$(MBIS_BUILD_INFO_LOG) $(AND)\
	$(CAT) $(strip $(TMPDIR))/~mbis_def.tmp >> $(MBIS_BUILD_INFO_LOG)
endif
	@$(IF_EXIST) $(strip $(TMPDIR))/~mbis_def.tmp $(THEN) $(DEL_FILE) $(strip $(TMPDIR))/~mbis_def.tmp $(CMD_END)

   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: elfpatch
# *************************************************************************
elfpatch:
	@echo $(strip $(TARGDIR))\$(IMG_FILE)!!
	@if exist $(strip $(TARGDIR))\$(IMG_FILE) \
	(@echo elfpatcher start....) &\
	(@pcore\tools\elfpatcher.exe $(strip $(TARGDIR))\$(IMG_FILE)) &\
	(@echo elfpatcher done!) \
	else \
	(@echo $(strip $(TARGDIR))\$(IMG_FILE) is not existed!Please build firstly!)


# *************************************************************************
# TARGET: gencompbld
# Write required script variables to config file
# *************************************************************************
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
gencompbld: gen_gfh_cfg
endif
gencompbld: gencategorymapping
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# Write the variable info to ~sub_compbld.tmp for Comp.mak
	@$(ECHO) -n "CUS_REL_SRC_COMP = $(strip $(CUS_REL_SRC_COMP))" > $(strip $(TMPDIR))/~sub_compbld.tmp

# mbis time probe for enable mbis time probe in Comp.mak
	@$(ECHO) -n "MBIS_EN_OBJ_LOG 	= $(strip $(MBIS_EN_OBJ_LOG))" >>  $(strip $(TMPDIR))/~compbld.tmp

# Write the variable info to ~compbld.tmp for Comp.mak
	@$(ECHO) -n "DEBUG_SAVE_CUR_THREAD	= $(strip $(DEBUG_SAVE_CUR_THREAD))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "APCSINT	= $(strip $(APCSINT))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "ASM	= $(strip $(ASM))" 	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "LIB	= $(strip $(LIB))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CC		= $(strip $(CC))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CC32	= $(strip $(CC32))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CPPC    	= $(strip $(CPPC))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CPPC32 	= $(strip $(CPPC32))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CFLAGS 	= $(strip $(CFLAGS))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CPLUSFLAGS = $(strip $(CPLUSFLAGS))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "VIA	= $(VIA)"		  >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CUS_MTK_LIB = $(strip $(CUS_MTK_LIB))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "NEED_BUILD_BOOTLOADER = $(strip $(NEED_BUILD_BOOTLOADER))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "FLASH_TEST_SELECT	   = $(strip $(FLASH_TEST_SELECT))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CARD_DOWNLOAD_SUPPORT_PLATFORM = $(strip $(CARD_DOWNLOAD_SUPPORT_PLATFORM))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "L1_TDD128            = $(strip $(L1_TDD128))"	      >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "ENABLE_PARTIAL_TRACE = $(strip $(ENABLE_PARTIAL_TRACE))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CUS_MTK_LIB_TRACE    = $(strip $(CUS_MTK_LIB_TRACE))"    >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "VFP_OPTION           = $(strip $(VFP_OPTION))"           >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "VFP_OPTION_SOFT      = $(strip $(VFP_OPTION_SOFT))"      >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "COM_DEFS_FOR_$(strip $(PLATFORM)) = $(strip $(COM_DEFS_FOR_$(strip $(PLATFORM))))">> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "SV5_PLATFORM = $(strip $(SV5_PLATFORM))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "SV5X_PLATFORM = $(strip $(SV5X_PLATFORM))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "LTE_SEC_COMP = $(strip $(LTE_SEC_COMP))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CHK_LTE_COMP = $(strip $(CHK_LTE_COMP))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "DWARF_FLAGS = $(strip $(DWARF_FLAGS))" >> $(strip $(TMPDIR))/~compbld.tmp

# According to the custom_MemoryDevice.h, write the variable info to ~compbld.tmp for Comp.mak
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@echo AFLAGS	= $(strip $(AFLAGS))    >> $(strip $(TMPDIR))/~compbld.tmp

	@$(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(CAT) "-cut=2" $(strip $(BUILD_SYSDIR))/custom_MemoryDevice.h` $(DO) \
		($(IF) "$(PRE_VAR)i" $(EQU) "NOR_LPSDRAM_MCP" $(THEN)\
			(echo AFLAGS	= $(strip $(AFLAGS)) $(call ADEFTrans,_NOR_LPSDRAM_MCP_, TRUE) >> $(strip $(TMPDIR))/~compbld.tmp)\
		$(CMD_END)) $(AND)\
		($(IF) "$(PRE_VAR)i" $(EQU) "LPSDRAM" $(THEN)\
			(echo AFLAGS	= $(strip $(AFLAGS)) $(call ADEFTrans,_LPSDRAM_, TRUE) >> $(strip $(TMPDIR))/~compbld.tmp)\
		$(CMD_END)) $(AND)\
		($(IF) "$(PRE_VAR)i" $(EQU) "NOR_RAM_MCP" $(THEN) \
			(echo AFLAGS	= $(strip $(AFLAGS)) $(call ADEFTrans,_NOR_RAM_MCP_, TRUE) >> $(strip $(TMPDIR))/~compbld.tmp)\
		$(CMD_END)) \
	$(DONE)
endif


ifeq ($(strip $(REDUCE_HEADER_DEPTH)),TRUE)
	@$(STRCMPEX) abc abc e $(strip $(TMPDIR))/~compbld_2.tmp  INCDIRS  = $(strip $(HEADER_TEMP)) $(strip $(COMMINCDIRS))
else
	@$(STRCMPEX) abc abc e $(strip $(TMPDIR))/~compbld_2.tmp  INCDIRS  = $(strip $(COMMINCDIRS))
endif

	@$(CAT) $(strip $(TMPDIR))/~compbld_2.tmp >> $(strip $(TMPDIR))/~compbld.tmp
	@$(IF_EXIST) $(strip $(TMPDIR))/~compbld_2.tmp $(THEN) ($(DEL_FILE) $(strip $(TMPDIR))/~compbld_2.tmp) $(CMD_END)
	@$(STRCMPEX) abc abc e $(strip $(TMPDIR))/~compbld_2.tmp  DEFINES  = $(strip $(COM_DEFS))
	@$(CAT) $(strip $(TMPDIR))/~compbld_2.tmp >> $(strip $(TMPDIR))/~compbld.tmp
	@$(IF_EXIST) $(strip $(TMPDIR))/~compbld_2.tmp $(THEN) ($(DEL_FILE) $(strip $(TMPDIR))/~compbld_2.tmp) $(CMD_END)
	@$(ECHO) -n "PROJECT_NAME  = $(strip $(PROJECT_NAME))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "PROJECT_MAKEFILE   = $(strip $(PROJECT_MAKEFILE))"   >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "ARM9_PLATFORM  = $(strip $(ARM9_PLATFORM))"  >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "ARM11_PLATFORM = $(strip $(ARM11_PLATFORM))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CR4_PLATFORM   = $(strip $(CR4_PLATFORM))"   >> $(strip $(TMPDIR))/~compbld.tmp
	@$(IF_NOT) $(P_VAR)0$(COMPILER) == $(P_VAR)0 $(THEN) \
		$(ECHO) -n "COMPILER = $(COMPILER)" >> $(strip $(TMPDIR))/~compbld.tmp $(CMD_END)
	@$(IF_NOT) $(P_VAR)0$(HEADER_TEMP) == $(P_VAR)0 $(THEN) \
		$(ECHO) -n "HEADER_TEMP = $(strip $(HEADER_TEMP))" >> $(strip $(TMPDIR))/~compbld.tmp $(CMD_END)
	@$(ECHO) -n "AUTO_MERGE_PTH = $(AUTO_MERGE_PTH)">> $(strip $(TMPDIR))/~compbld.tmp

ifdef DUAL_MODE_SUPPORT
	@$(ECHO) -n "DUAL_MODE_SUPPORT = $(strip $(DUAL_MODE_SUPPORT))" >> $(strip $(TMPDIR))/~compbld.tmp
endif

	@$(ECHO) -n "ACTION = $(strip $(ACTION))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CUSTOM_DEBUG_MODULES = $(strip $(CUSTOM_DEBUG_MODULES))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CUSTOM_NON_DEBUG_MODULES = $(strip $(CUSTOM_NON_DEBUG_MODULES))" >> $(strip $(TMPDIR))/~compbld.tmp

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
	@$(ECHO) -n "MODIS_CONFIG     = $(MODIS_CONFIG)"     >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "MODIS_MODE = $(MODIS_MODE)" >> $(strip $(TMPDIR))/~compbld.tmp
endif

ifdef NO_PCIBT
  ifeq ($(strip $(NO_PCIBT)),TRUE)
		@$(ECHO) -n "NO_PCIBT = TRUE" >> $(strip $(TMPDIR))/~compbld.tmp
  endif
endif
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
# TARGET: gen_gfh_cfg
# *************************************************************************
gen_gfh_cfg:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@echo PROJECT_NAME = $(strip $(PROJECT_NAME))>$(strip $(TMPDIR))/~gfh_cfg.tmp
	@echo PLATFORM_ID = $(strip $(BIN_FILE))>>$(strip $(TMPDIR))/~gfh_cfg.tmp
	@echo PROJECT_ID = $(strip $(VERNO))>>$(strip $(TMPDIR))/~gfh_cfg.tmp
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *****************************************************************************************************
# TARGET: gen_concatenate_proj
# concatenate the project makefiles and the result is placed on build/$project/$flavorn/bin
# Notice: the PROJECT_MAKEFILE should be the original project makefile in make folder. ext: make/${CORE_ROOT}/XXX.mak
# *****************************************************************************************************
CONCATENATE_PROJ_MAK := $(strip $(TARGDIR))/~$(subst ~,,$(notdir $(strip $(PROJECT_MAKEFILE))))
ORIGINAL_PROJ_MAK    := make/projects/$(subst ~,,$(notdir $(strip $(PROJECT_MAKEFILE))))

gen_concatenate_proj:  $(strip $(CONCATENATE_PROJ_MAK))

# *****************************************************************************************************
# TARGET: $(CONCATENATE_PROJ_MAK)
# concatenate the project makefiles and the result is placed on build/$project/$flavorn/bin
# Notice: the PROJECT_MAKEFILE should be the original project makefile in make folder. ext: make/${CORE_ROOT}/XXX.mak
# *****************************************************************************************************
$(CONCATENATE_PROJ_MAK): $(strip $(ORIGINAL_PROJ_MAK))
ifdef MODEM_SPEC
  ifneq ($(strip $(MODEM_SPEC)),NONE)
$(CONCATENATE_PROJ_MAK): make/${COMMON_ROOT}/modem_spec/$(strip $(MODEM_SPEC)).mak
  endif
endif
ifdef PROJECT_MAKEFILE_EXT
  ifneq ($(strip $(PROJECT_MAKEFILE_EXT)),NONE)
    ifeq ($(strip $(DEMO_PROJECT)),FALSE)
$(CONCATENATE_PROJ_MAK): make/projects/custom_config/$(strip $(PROJECT_MAKEFILE_EXT)).mak
    endif
  endif
endif

ifdef VARIATION_PROJ
ifneq ($(strip $(VARIATION_PROJ)),)
$(CONCATENATE_PROJ_MAK): make/common/variation/$(strip $(VARIATION_PROJ)).mak
endif
endif

ifdef TK_MD_CUS
ifneq ($(strip $(TK_MD_CUS)),NONE)
$(CONCATENATE_PROJ_MAK): make/projects/tk_md_cus/$(strip $(TK_MD_CUS)).mak
endif
endif

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(IF_NOT_EXIST) $(strip $(TARGDIR)) $(THEN) ($(MKDIR) $(strip $(TARGDIR))) $(CMD_END)
	@perl ${COMMON_ROOT}/tools/cat_proj_mak.pl "$(strip $(ORIGINAL_PROJ_MAK))" "$(strip $(CONCATENATE_PROJ_MAK))" $(WITH) \
		($(IF_ERR_TRUE) $(THEN) \
			($(DEL_FILE) "$(strip $(CONCATENATE_PROJ_MAK))" $(AND) \
			echo "Error: concatenate project makefiles failed." $(WITH) exit 1)\
		$(CMD_END))

ifdef VARIATION_PROJ
ifneq ($(strip $(VARIATION_PROJ)),)
		@perl ${COMMON_ROOT}/mtk_tools/cat_vari_mak.pl "make/common/variation/$(strip $(VARIATION_PROJ)).mak" "$(strip $(CONCATENATE_PROJ_MAK))" $(WITH) \
		($(IF_ERR_TRUE) $(THEN) \
			($(DEL_FILE) "$(strip $(CONCATENATE_PROJ_MAK))" $(AND) \
			echo "Error: concatenate variation makefiles failed." $(WITH) exit 1)\
		$(CMD_END))
endif
endif

ifdef TK_MD_CUS
ifneq ($(strip $(TK_MD_CUS)),NONE)
		@perl ${COMMON_ROOT}/tools/cat_tkmd_mak.pl "make/projects/tk_md_cus/$(strip $(TK_MD_CUS)).mak" "$(strip $(CONCATENATE_PROJ_MAK))" $(WITH) \
		($(IF_ERR_TRUE) $(THEN) \
			($(DEL_FILE) "$(strip $(CONCATENATE_PROJ_MAK))" $(AND) \
			echo "Error: concatenate variation makefiles failed." $(WITH) exit 1)\
		$(CMD_END))
endif
endif

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
###############################
# Begin of MoDIS only actions #
###############################
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
include make/${CORE_ROOT}/modisBuild.mak
endif #ifeq ($(strip $(MODIS_CONFIG)),TRUE)
#############################
# End of MoDIS only actions #
#############################

# FORCE is a phony target, any target depending on it will run forcely
FORCE:

