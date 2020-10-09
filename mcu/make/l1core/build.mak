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
#     tools/make -f[make file] [build_flag] <CUSTOMER> <PROJECT> <ACTION>
#
#     Example:
#     tools/make -fmake/build.mak -r -R CUSTOMER=mtk PROJECT=gprs new
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
.PHONY : new cleanall emigen cmmgen asngen nvram_auto_gen codegen sysgen_init asnregen update genlog cleanbin genverno gencustominfo cksysdrv cksysdrv_slim cksysdrv_clean scan remake libs code_generate cleancodegen cleanmod done gen_bl_verno startbuildlibs bootloader gen_infolog drv_feature_check ckmake ckmemlayout ckmemlayout2 removecode genremoveinfo clean_codegen slim_codegen slim_mcddll slim_update ss_lcs_gen backup findpad elfpatch gendsp cfggen codegen_check FORCE nvram_edit_h_gen gen_gfh_cfg umts_gen asngen asngen_l4 asnregen copycmm master_info_gen update_share_buffer adjust_memconfig

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
include make/l1core/Option.mak            # Build option definitons
include make/l1core/standalone_action.mak

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

ifeq ($(strip $(COMPILER)),GCC)
    ifneq ($(strip $(COMPOBJS)),)
      ifneq ($(wildcard l1core/modem/el1/el1d),)
        COMPOBJS := $(filter-out $(CUS_MTK_LIB)/el1d.a,$(COMPOBJS))
      endif
      COMPOBJS := $(filter-out $(CUS_MTK_LIB)/el1d_pcore.a $(CUS_MTK_LIB)/edsphwram.a,$(COMPOBJS))

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
    ADEFTrans = -pd "$(1) SETL {$(strip $(2))}"
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  NO_PCIBT = TRUE
endif

ifneq ($(filter DSPTK CHESS,$(COMPILER)),)
ifeq ($(strip $(C2K_RELEASE)),TRUE)
  COMPLIST  := $(filter-out $(CUS_REL_MTK_COMP) ,$(COMPLIST))
endif

  LIBDIR_TEMP := $(COMPLIBDIR)
  LINK_LIB_LIST = $(call sort,$(foreach lib,$(COMPLIST),$(COMPLIBDIR)/lib$(lib).a))
  LINK_SEARCH_PATH += -L $(COMPLIBDIR)
  
ifeq ($(strip $(C2K_RELEASE)),TRUE)
  LINK_LIB_LIST += $(call sort,$(foreach lib,$(CUS_REL_MTK_COMP),$(CUS_MTK_LIB)/lib$(lib).a))
  LINK_SEARCH_PATH += -L $(CUS_MTK_LIB)
endif
  LNKOPT += $(strip $(LINK_LIB_LIST)) -pmd32
  LNKOPT := $(subst \,/,$(LNKOPT))
endif

-include $(strip $(TMPDIR))/~cleanmod.tmp      # Define clean modules
ifndef DO_CLEAN_MODULE
   # Default clean all
  DO_CLEAN_MODULE   =  FALSE
  CLEAN_MODS        =
else
endif

-include $(strip $(TMPDIR))/~updatemod.tmp     # Define update modules
ifndef DO_UPDATE_MODULE
   # Default update all
  DO_UPDATE_MODULE  =  FALSE
  UPDATE_MODS       =
endif

-include $(strip $(TMPDIR))/~remakemod.tmp     # Define remake modules
ifndef DO_REMAKE_MODULE
   # Default remake all
  DO_REMAKE_MODULE  =  FALSE
  REMAKE_MODS       =
endif

# default mbis tempfile
ifndef MBIS_BUILD_TIME_TMP
   MBIS_BUILD_TIME_TMP = tmp
endif
ifndef MBIS_BUILD_INFO_LOG
   MBIS_BUILD_INFO_LOG = tmp
endif

CHK_LTE_COMP = FALSE

FULL_PRJ_NAME = $(strip $(PROJECT_NAME))($(strip $(FLAVOR)))

####################################################################
# End of alias build settings.
####################################################################

include make/l1core/xgen/xgen.mak

COM_DEFS_TARGET := $(COM_DEFS)
COMMINCDIRS_TARGET := $(COMMINCDIRS)
RULESDIR_TARGET := $(RULESDIR)
XGEN_INC_DIR_ORI := $(XGEN_INC_DIR)
XGEN_INC_DIR_TARGET ?= $(XGEN_INC_DIR)

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

ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
    ifeq ($(filter verno,$(UPDATE_MODS)),)
        UPDATE_MODS := $(UPDATE_MODS) verno
    endif
    ifeq ($(filter dbinfo,$(UPDATE_MODS)),)
      ifneq ($(TEST_LOAD_TYPE),BASIC)
        UPDATE_MODS := $(UPDATE_MODS) dbinfo
      endif
    endif
  COMPLIBLIST = $(call sort,$(foreach comp,$(UPDATE_MODS),$(comp).a))
else
  ifeq ($(strip $(DO_REMAKE_MODULE)),TRUE)
      ifeq ($(filter verno,$(REMAKE_MODS)),)
        REMAKE_MODS := $(REMAKE_MODS) verno
      endif
      ifeq ($(filter dbinfo,$(REMAKE_MODS)),)
        ifneq ($(TEST_LOAD_TYPE),BASIC)
          REMAKE_MODS := $(REMAKE_MODS) dbinfo
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

COM_DEFS_TARGET := $(COM_DEFS)
COMMINCDIRS_TARGET := $(COMMINCDIRS)

CHK_COMPLIST = $(filter-out $(foreach comp,$(COMPLIST),$(comp).a),$(call lc,$(COMPLIBLIST)))
ifneq ($(words $(CHK_COMPLIST)),0)
  $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in COMPLIST)
endif

ifndef MODULELIS
  MODULELIS := $(foreach comp,$(call lc,$(COMPLIBLIST)),$(subst .a,.lis,$(comp)))
endif

CHK_SCANLIST = $(filter-out $(foreach comp,$(COMPLIST),$(comp)),$(COMPSCANLIST))
ifneq ($(words $(CHK_SCANLIST)),0)
  $(error $(CHK_SCANLIST) NOT in COMPLIST)
endif

COMP_DEP_LIST = $(foreach comp,$(sort $(COMPSCANLIST)),$(comp).dep)

# *************************************************************************
# Search Paths
# *************************************************************************
vpath
vpath %.dep $(subst \,/,$(strip $(RULESDIR)))
vpath %.a $(strip $(OBJSDIR))/lib
vpath %.bin $(strip $(TARGDIR))

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

NEED_CHECK_CODEGEN_LIST := make/l1core/Codegen.mak
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
	@$$(IF_EXIST) $$(FIXPATH)/${PCORE_ROOT}/tools/ckMemLayout.pl $$(THEN)\
		$$(IF_EXIST) $$(strip $(TARGDIR))/$(2) $$(THEN)\
			$$(IF_EXIST) $$(strip $(TARGDIR))/$(3) $$(THEN)\
				(perl $$(FIXPATH)/${PCORE_ROOT}/tools/ckMemLayout.pl 2 TRUE $(4) "$$(strip $(TARGDIR))/$(2)" $$(TMPDIR)/~flash_cfg_tmp.c "$$(strip $$(PROJECT_MAKEFILE))" $$(strip $$(BUILD_SYSDIR)) $$(strip $$(INSIDE_MTK)) $(strip $(INFOMAKELOG)) > $$(strip $$(COMPLOGDIR))/ckmemlayout2_$(1).log  2>&1)$$(WITH) \
				($$(IF_ERR_TRUE) $$(THEN) (echo Error: Failed in ckMemLayout.pl. Please check $$(strip $$(COMPLOGDIR))/ckmemlayout2_$(1).log $$(WITH) exit 1) $$(CMD_END))\
			$$(CMD_END)\
		$$(CMD_END)\
	$$(CMD_END)
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,ckMemLayout_$(1).det,T," >> $(MBIS_BUILD_TIME_TMP)
endif
endef
$(eval $(call ckMemLayoutProcess,target,$(MAP_FILE),$(SYM_FILE),$(SCATTERFILE)))

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

new : cleanall genlog sysgen cleancodegen umts_gen codegen update

# *************************************************************************
#  Update Build
# *************************************************************************
update : genlog cleanbin codegen remake

# *************************************************************************
#  Remake Build
# *************************************************************************
remake : genlog cleanbin genverno sysgen libs $(BIN_FILE)
ifeq ($(SINGLE_CORE),TRUE)
remake : cmmgen
endif
remake : done

include make/l1core/Codegen.mak


# *************************************************************************
# TARGET: LINK_BIN_FILE
#  Executable Targets
# *************************************************************************
LINK_BIN_FILE : GCC_LINK_BIN_FILE

# *************************************************************************
# TARGET: GCC_LINK_BIN_FILE
#  Executable Targets
# *************************************************************************
GCC_LINK_BIN_FILE:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
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
		$(CMD_END))
  else
	@$(strip $(LINK)) $(strip $(VIA))$(strip $(TMPDIR))/~libs.tmp > $(TARGDIR)/link.log 2>&1 $(WITH) \
		($(IF_ERR_TRUE) $(THEN) \
			(echo Error: link failed. Please check $(TARGDIR)/link.log) $(WITH) \
			($(COPY_FILE) $(TARGDIR)/link.log $(strip $(TMPDIR))/aapmc_link.log) $(WITH) \
				($(IF_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(IMG_FILE)) $(CMD_END))\
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
# TARGET: DSPTK_LINK_BIN_FILE
#  Executable Targets
# *************************************************************************
DSPTK_LINK_BIN_FILE:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,B," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

	@$(ECHOLONGSTRING4) $(strip $(TMPDIR))/~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@$(ECHO) -n "-D__NULL_DEF__" >> $(strip $(TMPDIR))/~customIncDef.tmp
	@$(ECHOLONGSTRING4) $(strip $(TMPDIR))/~customInc.tmp $(foreach inc,$(subst \,/,$(COMMINCDIRS)),-I$(inc))
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
	@echo Linking $(strip $(NEWTARGNAME)) ...
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n

	@$(ECHO) -n "$(LNKOPT)" > $(strip $(TMPDIR))/~libs.tmp
	@$(IF_EXIST) $(strip $(TMPDIR))/~libs.tmp $(THEN) ($(COPY_FILE) $(strip $(TMPDIR))/~libs.tmp $(strip $(COMPLOGDIR))/link_option.log) $(CMD_END)
		@$(strip $(LINK)) $(LNKOPT) > $(TARGDIR)/link.log 2>&1 $(WITH) \
			($(IF_ERR_TRUE) $(THEN) \
				(echo Error: link failed. Please check $(TARGDIR)/link.log) $(WITH) \
				($(IF_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(IMG_FILE)) $(CMD_END))\
			$(CMD_END))
	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n  >> $(strip $(TARGDIR))/build.log

 # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# Target:  update_share_buffer
# *************************************************************************
update_share_buffer: 
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif	
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
	@$(ECHO) -n "======== Begin update_share_buffer ========"
	@$(IF_EXIST) $(FIXPATH)/$(strip ${CORE_ROOT})/tools/DspShareBufferUpdate.pl $(THEN)\
		(perl $(FIXPATH)/$(strip ${CORE_ROOT})/tools/DspShareBufferUpdate.pl TRUE $(strip $(TARGDIR))/$(strip $(LIS_FILE)) $(strip $(TARGDIR))/$(strip $(SYM_FILE)) $(strip $(TARGDIR))/$(strip $(IMG_FILE)) $(strip $(COPRO_TARGDIR))/$(strip $(COPRO_MAP_FILE)) $(strip $(COPRO_TARGDIR))/$(strip $(COPRO_SYM_FILE)) $(ORIACTION) > $(strip $(COMPLOGDIR))/update_share_buffer.log 2>&1) $(WITH) \
		($(IF_ERR_TRUE) $(THEN) echo Error: $(strip ${CORE_ROOT})/tools/DspShareBufferUpdate.pl failed. Please check $(strip $(COMPLOGDIR))/update_share_buffer.log $(WITH) exit 1 $(CMD_END))\
	$(CMD_END)
	@$(ECHO) -n "======== End update_memconfig ========"
	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n  >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: FROMELF_BIN_FILE:
#  Executable Targets
# *************************************************************************
FROMELF_BIN_FILE:

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,B," >> $(MBIS_BUILD_TIME_TMP)
endif

	@$(IF_NOT_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN)\
		(echo $(strip $(TARGDIR))/$(IMG_FILE) is not existed!Please check $(TARGDIR)/link.log. $(WITH) exit 1)\
	$(CMD_END)
   # -----------------------------
   # The size of the binary image depends on the available memory on the target
   # platform.
   # -----------------------------
	@echo Creating binary file $(BIN_FILE)
ifeq ($(strip $(COMPILER)),GCC)
	@$(strip $(BIN_CREATE)) -O binary $(strip $(TARGDIR))/$(IMG_FILE) $(strip $(TARGDIR))/$(BIN_FILE) > $(strip $(COMPLOGDIR))/fromelf_bin_file.log 2>&1 $(WITH) \
	($(IF_ERR_TRUE) $(THEN) (echo Error: Failed $(BIN_CREATE). Please check $(strip $(COMPLOGDIR))/fromelf_bin_file.log $(WITH) exit 1) $(CMD_END))
endif

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: $(BIN_FILE) and LINK
# *************************************************************************
$(BIN_FILE): LINK POSTBUILD

#Tafang: Not to do DSP_POSTBUILD temporarily
#LINK: LINK_BIN_FILE FROMELF_BIN_FILE DSP_POSTBUILD
LINK: LINK_BIN_FILE FROMELF_BIN_FILE

adjust_memconfig: LINK_BIN_FILE_CHECK update_share_buffer FROMELF_BIN_FILE DSP_POSTBUILD cmmgen done

# *************************************************************************
# TARGET: POSTBUILD
# *************************************************************************
ifeq ($(strip $(COMPILER)),GCC)
POSTBUILD :GCC_POSTBUILD
endif

# *************************************************************************
# TARGET: GCC_POSTBUILD
# *************************************************************************
# Tafang: Skip dsp_process temporarily
GCC_POSTBUILD: ckMemLayout_target.det

# To support DBG Info Gen.
	@$(IF_EXIST) $(strip $(TMPDIR))/~DbgInfoGen.cfg $(THEN) ($(DEL_FILE) $(strip $(TMPDIR))/~DbgInfoGen.cfg) $(CMD_END)
	@$(ECHOLONGSTRING4) $(strip $(TMPDIR))/~DbgInfoGen.cfg ELF=$(strip $(TARGDIR))/$(IMG_FILE) HW=$(strip $(PLATFORM))_$(strip $(CHIP_VER)) SW=$(strip $(VERNO))
	@$(LNITEM) $(strip $(TMPDIR))/~DbgInfoGen.cfg
	@echo PRJ=$(strip $(BRANCH)) >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
	@echo TIME=$(strip $(BUILD_DATE_TIME)) >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
  ifeq ($(strip $(PARTIAL_SOURCE)),TRUE)
		@echo DB="$(strip $(NET_PATH))"/$(strip $(BUILD_TST_DB))/DbgInfo_L_$(strip $(SLIM_BRANCH))_$(strip $(PROJECT_NAME))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME))  >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
		@echo SIGN=TRUE  >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
  else
		@echo DB=$(strip $(BUILD_TST_DB))/DbgInfo_L_$(strip $(SLIM_BRANCH))_$(strip $(PROJECT_NAME))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME))  >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
  endif
	@echo DBNAME="MCU_$(UC_L1CORE_ROOT)" >> $(strip $(TMPDIR))/~DbgInfoGen.cfg
	@$(ECHOLONGSTRING4) $(strip $(TMPDIR))/~DbgInfoGen.cfg LNKOPT="$(strip $(LNKOPT))"
	@$(LIST_DIR) "$(strip $(TARGDIR))/DbgInfo_*" 1>$(DEV_NUL) 2>&1 $(WITH) \
		$(IF_ERR_FALSE) $(THEN) $(DEL_FILE) $(strip $(TARGDIR))/DbgInfo_* $(CMD_END)
	@$(LIST_DIR) "$(strip $(BUILD_TST_DB))/DbgInfo_*" 1>$(DEV_NUL) 2>&1 $(WITH) \
		$(IF_ERR_FALSE) $(THEN) $(DEL_FILE) $(strip $(BUILD_TST_DB))/DbgInfo_* $(CMD_END)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(IMG_FILE)) $(THEN)\
		($echo Generating DbgInfo Database... $(WITH) \
		$(DBG_INFOGEN) -CFG-"$(strip $(TMPDIR))/~DbgInfoGen.cfg" 2>$(strip $(COMPLOGDIR))/DbgInfoGen.log $(WITH)  \
		($(IF_ERR_TRUE) $(THEN) (echo DbgInfoGen Error. Please check $(strip $(COMPLOGDIR))/DbgInfoGen.log $(WITH) exit 1) $(CMD_END)))\
		$(CMD_END)

	@$(IF_EXIST) $(strip $(BUILD_TST_DB))/DbgInfo_L_$(strip $(SLIM_BRANCH))_$(strip $(PROJECT_NAME))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME)) $(THEN)\
		($(COPY_FILE) $(strip $(BUILD_TST_DB))/DbgInfo_L_$(strip $(SLIM_BRANCH))_$(strip $(PROJECT_NAME))_$(strip $(DBG_INFO_VERNO))_$(strip $(DBG_BUILD_DATE_TIME))* $(strip $(TARGDIR))) \
		$(CMD_END)

	@$(IF_EXIST) $(strip $(BUILD_SYSDIR))/$(strip $(BOARD_VER)).cfg $(THEN)\
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
			($(COPY_FILE) $(strip $(BUILD_SYSDIR))/$(strip $(BOARD_VER)).cfg $(strip $(TARGDIR))/$(strip $(BOARD_VER)).cfg) \
		$(CMD_END))\
	$(CMD_END)

# *************************************************************************
# TARGET: LINK_BIN_FILE_CHECK
#  Executable Targets
# *************************************************************************
LINK_BIN_FILE_CHECK:

ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

	@($(MAKE) -fmake/l1core/build.mak -r -R FORCE_GEN=TRUE CORE_ROOT=${CORE_ROOT} master_info_gen $(AND)\
		($(IF_ERR_TRUE) $(THEN) (exit 1) $(CMD_END))) 

	@($(MAKE) -fmake/l1core/build.mak -r -R CORE_ROOT=${CORE_ROOT} update_memconfig) $(WITH) \
				($(IF_ERR_TRUE) $(THEN) (exit 1) $(CMD_END))

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n  >> $(strip $(TARGDIR))/build.log
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: DSP_POSTBUILD
# *************************************************************************
DSP_POSTBUILD:
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif	
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

	@$(ECHO) -n "[elfparser] start to parse the elf..."
#@$(IF_EXIST) $(strip ${CORE_ROOT})/tools/OSA/elfparser $(THEN)\
		($(strip ${CORE_ROOT})/tools/OSA/elfparser  $(strip $(TARGDIR))/$(strip $(IMG_FILE)) > $(strip $(COMPLOGDIR))/elfparser.log 2>&1) $(WITH) \
		($(IF_ERR_TRUE) $(THEN) echo Error: tools/OSA/elfparser failed. Please check $(strip $(COMPLOGDIR))/elfparser.log $(WITH) exit 1 $(CMD_END))\
	$(CMD_END)
	@$(ECHO) -n "[elfparser] done for parsing the elf..."

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl  -n  >> $(strip $(TARGDIR))/build.log
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
		perl $(strip ${CORE_ROOT})/tools/time.pl -n>>$(strip $(TARGDIR))/build.log) $(CMD_END)

	@echo Generate version number ... [start]>> $(LOG)
	@$(IF_NOT_EXIST) $(VERNODIR) $(THEN)\
		($(MKDIR) $(VERNODIR)) $(CMD_END)

	@$(IF_EXIST) $(strip $(VERNODIR))/verno.c $(THEN) \
		($(DEL_FILE) $(strip $(VERNODIR))/verno.c) $(CMD_END)

	@perl $(strip ${COMMON_ROOT})/tools/genverno.pl "$(strip $(VERNODIR))" "$(strip $(VERNO))" "$(strip $(BUILD_DATE_TIME))" "$(strip $(BRANCH))" "$(strip $(HAL_VERNO))" "$(strip $(HW_VER))" "$(strip $(BUILD))" "$(strip $(FLAVOR))" "$(strip $(PLATFORM))" "$(strip $(DSP_PROJECT))" "$(strip $(DSP_FLAVOR))" "$(strip $(PROJECT_NAME))"

	@echo Generate version number ... [done]>> $(LOG)
	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN)\
		($(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log $(AND) \
		 perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log) $(CMD_END)

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

	@echo Generate cmm files
  ifeq ($(strip $(COMPILER)),GCC)
		@$(IF_EXIST) ${CORE_ROOT}/tools/CMMAutoGen.pl $(THEN) \
			((perl ${CORE_ROOT}/tools/CMMAutoGen.pl 0 $(strip $(PROJDIR))/cmm/$(strip $(TARGNAME_L))_nocode.cmm ../bin/$(IMG_FILE) "$(strip $(PROJECT_MAKEFILE))" $(strip $(BIN_FILE)) $(strip $(TARGDIR))/$(SYM_FILE) "$(CC)" "$(VIA)" $(strip $(TMPDIR))/~customIncDef.tmp $(strip $(TMPDIR)) $(strip $(INFOMAKELOG)) $(strip $(TMPDIR))/cp_dsp_info.tmp $(ORIACTION) > $(strip $(COMPLOGDIR))/cmmgen_nocode.log) $(WITH)  \
			$(IF_ERR_TRUE) $(THEN) (echo Error: generate CMM file Failed. Please check $(strip $(COMPLOGDIR))/cmmgen_nocode.log $(WITH) exit 1) $(CMD_END)) \
		$(CMD_END)
    ifeq ($(strip $(RUN_CMMGEN_HQ)),TRUE)
			@$(IF_EXIST) ${CORE_ROOT}/tools/CMMAutoGen.pl  $(THEN)\
				((perl ${CORE_ROOT}/tools/CMMAutoGen.pl 1 $(strip $(PROJDIR))/cmm/$(strip $(TARGNAME_L))_HQ_Only.cmm ../bin/$(IMG_FILE) "$(strip $(PROJECT_MAKEFILE))" $(strip $(BIN_FILE)) $(strip $(TARGDIR))/$(SYM_FILE) "$(CC)" "$(VIA)" $(strip $(TMPDIR))/~customIncDef.tmp $(strip $(TMPDIR)) $(strip $(INFOMAKELOG)) $(strip $(TMPDIR))/cp_dsp_info.tmp $(ORIACTION) > $(strip $(COMPLOGDIR))/cmmgen_hqonly.log) $(WITH) \
				$(IF_ERR_TRUE) $(THEN) (echo Error: generate CMM file Failed. Please check $(strip $(COMPLOGDIR))/cmmgen_hqonly.log $(WITH) exit 1) $(CMD_END))\
			$(CMD_END)
    endif
  endif

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl ${CORE_ROOT}/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET:  $(strip $(TMPDIR))/~customIncDef.tmp:
# *************************************************************************
$(strip $(TMPDIR))/~customIncDef.tmp:
	@$(STRCMPEX) def def e  $(strip $(TMPDIR))/~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >>  $(strip $(TMPDIR))/~customIncDef.tmp
	@$(STRCMPEX) inc inc e  $(strip $(TMPDIR))/~customInc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@$(CAT)  $(strip $(TMPDIR))/~customInc.tmp >>  $(strip $(TMPDIR))/~customIncDef.tmp
	@$(IF_NOT_EXIST) $(TARGDIR)/module/custom $(THEN) \
		($(MAKE) -fmake/l1core/build.mak -r -R PROJECT_NAME=$(strip $(PROJECT_NAME)) PROJECT_MAKEFILE="$(strip $(PROJECT_MAKEFILE))" FLAVOR=$(strip $(FLAVOR)) MODULELIS=custom.lis genmoduleinfo)\
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
	@-$(MAKE) -fmake/common/parallel.mak -r -R $(strip $(CMD_ARGU)) --no-print-directory PARALLEL_CORE=$(L1CORE_ROOT) COMPLIBLIST="$(COMPLIBLIST)" TMPDIR=$(strip $(TMPDIR)) PROJECT_NAME=$(strip $(PROJECT_NAME)) PROJECT_MAKEFILE="$(strip $(PROJECT_MAKEFILE))" FLAVOR=$(strip $(FLAVOR)) MBIS_EN=$(strip $(MBIS_EN))
else	
	@$(MAKE) -fmake/common/parallel.mak -r -R $(strip $(CMD_ARGU)) --no-print-directory PARALLEL_CORE=$(L1CORE_ROOT) COMPLIBLIST="$(COMPLIBLIST)" TMPDIR=$(strip $(TMPDIR)) PROJECT_NAME=$(strip $(PROJECT_NAME)) PROJECT_MAKEFILE="$(strip $(PROJECT_MAKEFILE))" FLAVOR=$(strip $(FLAVOR)) MBIS_EN=$(strip $(MBIS_EN))
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
startbuildlibs: gencompbld

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@echo Start to build $(COMPLIBLIST)
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
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

   # can be moved to genlog
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(IMG_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(IMG_FILE))) $(CMD_END)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(LIS_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(LIS_FILE))) $(CMD_END)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(READELF_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(READELF_FILE))) $(CMD_END)
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

	@$(FOR) $(DECLARE_VAR)i $(IN) $(COMPLIBLIST) $(DO) \
		($(IF_EXIST) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i $(THEN) ($(DEL_FILE) $(strip $(COMPLIBDIR))/lib$(PRE_VAR)i) $(CMD_END))\
	$(DONE)

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: %.a
# *************************************************************************
%.a:

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,L_$(@F),L," >> $(MBIS_BUILD_TIME_TMP)
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

	@perl $(strip ${CORE_ROOT})/tools/time.pl
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
			($(LIST_DIR) "$(subst \,/,$(OBJSDIR))/$*/*.obj" 1>$(DEV_NUL) 2>&1 || perl $(strip ${CORE_ROOT})/tools/extract_obj_from_lib.pl  $(subst \,/,$(OBJSDIR))/$*/lib$*.a_bak  $(subst \,/,$(OBJSDIR))/$* $(subst \,/,$(LIB)) $(TARGDIR)/module/$*/$*.lis) \
		$(CMD_END)
    endif
# End of extract obj

	@$(ECHO) "$* START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log
	@$(MAKE) -fmake/${COMMON_ROOT}/Comp.mak -k -r -R TMPDIR=$(strip $(TMPDIR)) $(strip $(CMD_ARGU)) --no-print-directory COMPONENT=$* setup_env > $(strip $(COMPLOGDIR))/$*_setEnv.log 2>&1

  ifeq ($(strip $(call Upper,$(BM_NEW))),TRUE)
		@$(IF_NOT_EXIST) $(strip $(COMPLOGDIR))/$* $(THEN) \
			$(MKDIR) $(strip $(COMPLOGDIR))/$* \
		$(CMD_END)

		@($(MAKE) -fmake/${COMMON_ROOT}/Comp.mak -k -r -R TMPDIR=$(strip $(TMPDIR)) $(strip $(CMD_ARGU)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))/$*.log 2>&1) $(WITH) \
		($(IF_ERR_TRUE) $(THEN)\
			(perl $(strip ${CORE_ROOT})/tools/get_log.pl $(strip $(COMPLOGDIR))/$*.log $(strip $(COMPLOGDIR))/$* $(HTOGETHER) $(strip $(HEADER_TEMP))) $(AND) \
			($(DEL_DIR) $(strip $(COMPLOGDIR))/$*) $(AND) \
			($(IF_EXIST) $(HEADER_TEMP) $(THEN) $(DEL_DIR) $(strip $(HEADER_TEMP)) $(CMD_END)) $(AND) \
			(exit 1) \
		$(ELSE) \
			(perl $(strip ${CORE_ROOT})/tools/get_log.pl $(strip $(COMPLOGDIR))/$*.log $(strip $(COMPLOGDIR))/$* $(HTOGETHER) $(strip $(HEADER_TEMP))) $(AND) \
			($(DEL_DIR) $(strip $(COMPLOGDIR))/$*) \
		$(CMD_END))
  else
		@$(IF_NOT_EXIST) $(strip $(COMPLOGDIR))/$* $(THEN) \
			$(MKDIR) $(strip $(COMPLOGDIR))/$* \
		$(CMD_END)

		@($(MAKE) -fmake/${COMMON_ROOT}/Comp.mak -r -R TMPDIR=$(strip $(TMPDIR)) $(strip $(CMD_ARGU)) COMPONENT=$* update_lib > $(strip $(COMPLOGDIR))/$*.log 2>&1) $(WITH) \
		($(IF_ERR_TRUE) $(THEN) \
			(echo Error in libs) $(AND) \
			(perl $(strip ${CORE_ROOT})/tools/get_log.pl $(strip $(COMPLOGDIR))/$*.log $(strip $(COMPLOGDIR))/$* $(HTOGETHER) $(strip $(HEADER_TEMP))) $(AND) \
			($(DEL_DIR) $(strip $(COMPLOGDIR))/$*) $(AND) \
			($(IF_EXIST) $(HEADER_TEMP) $(THEN) $(DEL_DIR) $(strip $(HEADER_TEMP)) $(CMD_END)) $(AND) \
			(exit 1) \
		$(ELSE) \
			(perl $(strip ${CORE_ROOT})/tools/get_log.pl $(strip $(COMPLOGDIR))/$*.log $(strip $(COMPLOGDIR))/$* $(HTOGETHER) $(strip $(HEADER_TEMP))) $(AND) \
			($(DEL_DIR) $(strip $(COMPLOGDIR))/$*) \
		$(CMD_END))
  endif

ifeq ($(strip $(WIFI_SUPPORT)),MT5911)
	@$(IF) "$*" $(EQU) "wndrv" $(THEN)\
		(($(IF_NOT_EXIST) $(call CUSTOM_FLD_MAPPING,$(strip ${CORE_ROOT})/custom/drv/wifi) $(THEN) \
			$(MKDIR) $(call CUSTOM_FLD_MAPPING,$(strip ${CORE_ROOT})/custom/drv/wifi)) $(AND) \
			($(IF_EXIST) $(OBJSDIR)/lib/libwndrv.a $(THEN)\
				($(MOVE) $(OBJSDIR)/lib/libwndrv.a $(call CUSTOM_FLD_MAPPING,$(strip ${CORE_ROOT})/custom/drv/wifi)/libwndrv.a))\
			$(CMD_END)\
		$(CMD_END))\
	$(CMD_END)
endif

	@$(CAT) $(strip $(COMPLOGDIR))/$*.log >> $(LOG)

	@perl ./$(strip ${CORE_ROOT})/tools/chk_lib_err_warn.pl $(strip $(COMPLOGDIR))/$*.log

	@$(ECHO) "$* END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

   # mbis time probe
	@$(IF) "$(strip $(MBIS_EN_OBJ_LOG))" $(EQU) "TRUE" $(THEN)\
		($(LIST_DIR) "$(TARGDIR)/log/mbis/$*/*.mbis" 1>$(DEV_NUL) 2>&1 || exit 0 $(AND) (perl $(strip ${CORE_ROOT})/tools/mbis.pl -o $(TARGDIR)/log/mbis/$*)) \
	$(CMD_END)
	@$(LIST_DIR) "$(TARGDIR)/log/mbis/$*/*.mbis" 1>$(DEV_NUL) 2>&1 || exit 0 $(AND) (($(DEL_FILE) $(TARGDIR)/log/mbis/$*/*.mbis) $(AND) ($(DEL_DIR) $(TARGDIR)/log/mbis/$*))
   ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,L_$(@F),L," >> $(MBIS_BUILD_TIME_TMP)
   endif

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
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

   # -----------------------------
   # Check build root, target, and project directories
   #
   # build ->
   #  +-$(PROJECT_NAME)
   #     +-$(FLAVOR)
   #        +-dep    - Dependency directory
   #        +-obj    - Object directory
   #        +-log    - log directory
   #        +-lib    - libraries directory
   # -----------------------------

	@$(ECHO) -n "Cleaning directories under $(strip $(PROJDIR)) ..."

	-@$(IF_NOT_EXIST) $(TARGDIR) $(THEN)\
		($(MKDIR) $(TARGDIR)) \
	$(ELSE) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(BIN_FILE))) $(CMD_END)) $(AND) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(IMG_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(IMG_FILE))) $(CMD_END)) $(AND) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(LIS_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(LIS_FILE))) $(CMD_END)) $(AND) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(READELF_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(READELF_FILE))) $(CMD_END)) $(AND) \
		($(LIST_DIR) "$(strip $(TARGDIR))/*.log" > $(DEV_NUL) 2>&1 $(WITH) \
			$(IF_ERR_FALSE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/*.log) $(CMD_END))\
	$(CMD_END)

	@$(IF_EXIST) $(COMPLOGDIR) $(THEN)\
		($(LIST_DIR) "$(strip $(COMPLOGDIR))/*.log" > $(DEV_NUL) 2>&1 $(WITH) \
			$(IF_ERR_FALSE) $(THEN) ($(DEL_FILE) $(strip $(COMPLOGDIR))/*.log) $(CMD_END))\
	$(CMD_END)

	@$(IF_NOT_EXIST) $(COMPLOGDIR) $(THEN)\
		($(MKDIR) $(COMPLOGDIR)) \
	$(CMD_END)

	@$(IF_NOT_EXIST) $(PROJDIR) $(THEN) ($(MKDIR) $(PROJDIR)) $(CMD_END)

	@$(ECHO) -n "Cleaning dep files under $(RULESDIR)"
#KKKK#@$(IF_EXIST) $(strip $(RULESDIR)) $(THEN) ($(DEL_DIR) $(strip $(RULESDIR))) $(CMD_END)
	@$(IF_NOT_EXIST) $(RULESDIR) $(THEN) ($(MKDIR) $(RULESDIR)) $(CMD_END)
	@$(ECHO) -n "Cleaning via files under $(VIADIR)"
	@$(IF_EXIST) $(strip $(VIADIR)) $(THEN) ($(DEL_DIR) $(strip $(VIADIR))) $(CMD_END)
	@$(IF_NOT_EXIST) $(VIADIR) $(THEN) ($(MKDIR) $(VIADIR)) $(CMD_END)
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

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n  >> $(strip $(TARGDIR))/build.log
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
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN) ($(DEL_DIR) $(strip $(TARGDIR))/$(strip $(BIN_FILE))) $(CMD_END)

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n>>$(strip $(TARGDIR))/build.log
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: genlog
# Standard "genlog" Target
# *************************************************************************
genlog: gen_infolog gen_infomakelog

genlog:
ifneq ($(PCIBT_ACTION_LIST),)
	@$(PCIBT_SCRIPT_CMD) $(INFOMAKELOG) $(PCIBT_ACTION_LIST) 2>$(strip $(TARGDIR))/GlobalIncCheck.log $(WITH) $(IF_ERR_TRUE) $(THEN) ($(CAT) $(strip $(TARGDIR))/GlobalIncCheck.log $(WITH) exit 1) $(CMD_END)
	@$(ECHO) -n L1CORE GENLOG done.
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
   #        +-obj    - Object directory
   #        +-log    - log directory
   #        +-lib    - libraries directory
   # -----------------------------
	@echo Cleaning directories under $(strip $(PROJDIR)) ...
	@$(IF_NOT_EXIST) $(BUILDDIR) $(THEN) \
		($(MKDIR) $(BUILDDIR)) $(CMD_END)

	@$(IF_NOT_EXIST) $(TARGDIR) $(THEN) \
		($(MKDIR) $(TARGDIR)) \
	$(ELSE) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(BIN_FILE))) $(CMD_END)) $(WITH) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(IMG_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(IMG_FILE))) $(CMD_END)) $(WITH) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(LIS_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(LIS_FILE))) $(CMD_END)) $(WITH) \
		($(IF_EXIST) $(strip $(TARGDIR))/$(strip $(READELF_FILE)) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(strip $(READELF_FILE))) $(CMD_END)) $(WITH) \
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
		perl $(strip ${CORE_ROOT})/tools/time.pl -n>>$(strip $(TARGDIR))/build.log) $(CMD_END)

	@$(IF_NOT_EXIST) $(COMPLOGDIR) $(THEN) \
		($(MKDIR) $(COMPLOGDIR)) $(CMD_END)

	@$(ECHOLONGSTRING4) $(strip $(TMPDIR))/~def.tmp $(foreach def,$(sort $(COM_DEFS_TARGET)),$(def))
	@$(ECHOLONGSTRING4) $(strip $(TMPDIR))/~inc.tmp $(foreach inc,$(COMMINCDIRS_TARGET),$(inc))
	@$(LNITEM) $(strip $(TMPDIR))/~def.tmp
	@$(LNITEM) $(strip $(TMPDIR))/~inc.tmp
	@($(ECHO) -n "[ COMMON OPTION ]" > $(INFOLOG)) $(AND) \
		($(CAT) $(strip $(TMPDIR))/~def.tmp >> $(INFOLOG))
	@($(ECHO) -n "[ COMMON INCLUDE PATH ]" >> $(INFOLOG)) $(AND) \
		($(CAT) $(strip $(TMPDIR))/~inc.tmp >> $(INFOLOG))

	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN) \
		($(ECHO) "$@ END TIME=" >>$(strip $(TARGDIR))/build.log $(AND) \
		perl $(strip ${CORE_ROOT})/tools/time.pl -n>>$(strip $(TARGDIR))/build.log) $(CMD_END)
   
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
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log

	@$(STRCMPEX) def def e $(INFOMAKELOG) COM_DEFS = $(call sort, $(foreach def,$(COM_DEFS),$(def)))
	@$(STRCMPEX) def def e $(strip $(TMPDIR))/~remove.tmp COMMINCDIRS = $(foreach inc,$(COMMINCDIRS),$(inc))
	@$(CAT) $(strip $(TMPDIR))/~remove.tmp >> $(INFOMAKELOG)
	@$(ECHOLONGSTRING) $(INFOMAKELOG) COMP_TRACE_DEFS_MODEM $(COMP_TRACE_DEFS_MODEM)
	@$(ECHOLONGSTRING) $(INFOMAKELOG) COMP_TRACE_DEFS_FP $(COMP_TRACE_DEFS_FP)
	@$(ECHOLONGSTRING) $(INFOMAKELOG) COMP_TRACE_DEFS $(COMP_TRACE_DEFS_MODEM) $(COMP_TRACE_DEFS_FP)
	@$(ECHO) -n COMPLIST = $(call sort, $(foreach def,$(COMPLIST),$(def))) >> $(INFOMAKELOG)

	@$(ECHOLONGSTRING) $(INFOMAKELOG) COMPOBJS $(COMPOBJS)
	@$(ECHOLONGSTRING) $(INFOMAKELOG) CUS_REL_BASE_COMP $(CUS_REL_BASE_COMP)
	@$(ECHOLONGSTRING5) $(INFOMAKELOG) XGEN_INC_DIR_ORI $(strip $(XGEN_INC_DIR_ORI))

	@$(ECHO) -n CUS_REL_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_SRC_COMP),$(def))) >> $(INFOMAKELOG)
	@$(ECHO) -n CUS_REL_PAR_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_PAR_SRC_COMP),$(def))) >> $(INFOMAKELOG)
	@$(ECHOLONGSTRING5) $(INFOMAKELOG) XGEN_INC_DIR_ORI $(strip $(XGEN_INC_DIR_ORI))
	@$(ECHO) -n LTE_SEC_COMP = $(call sort, $(foreach def,$(LTE_SEC_COMP),$(def))) >> $(INFOMAKELOG)

ifneq ($(words $(CUS_REL_PAR_SRC_COMP)),0)
	@$(STRCMPEX) def def e $(strip $(TMPDIR))/~remove.tmp ALL_CUS_REL_PAR_SRC_COMP = $(foreach comp,$(call Upper,$(CUS_REL_PAR_SRC_COMP)),$(CUS_REL_$(comp)_PAR_SRC_LIST))
	@$(CAT) $(strip $(TMPDIR))/~remove.tmp >> $(INFOMAKELOG)
endif
	@$(IF_EXIST) $(strip $(TMPDIR))/~remove.tmp $(THEN) $(DEL_FILE) $(strip $(TMPDIR))/~remove.tmp $(CMD_END)
	@echo CUS_REL_MTK_COMP = $(call sort, $(foreach def,$(CUS_REL_MTK_COMP),$(def))) >> $(INFOMAKELOG)
	@echo TST_DB = $(strip $(BUILD_TST_DB)) >> $(INFOMAKELOG)

ifneq ($(strip $(SWITCH_FOLDER)),)
	@echo SWITCH_FOLDER = $(strip $(SWITCH_FOLDER))>> $(INFOMAKELOG)
endif

	@$(ECHOLONGSTRING) $(INFOMAKELOG) CUS_REL_OBJ_LIST $(CUS_REL_OBJ_LIST)

	@$(ECHO) -n LEVEL = $(strip $(LEVEL)) >> $(INFOMAKELOG)
	@$(ECHO) -n CUSTOM_RELEASE = $(strip $(CUSTOM_RELEASE)) >> $(INFOMAKELOG)
	@$(ECHO) -n VERNO = $(strip $(VERNO)) >> $(INFOMAKELOG)
	@$(ECHO) -n MTK_SUBSIDIARY = $(strip $(MTK_SUBSIDIARY)) >> $(INFOMAKELOG)
	@$(ECHO) -n CUSTOM_DEBUG_MODULES = $(strip $(CUSTOM_DEBUG_MODULES))>> $(INFOMAKELOG)
	@$(ECHO) -n CUSTOM_NON_DEBUG_MODULES = $(strip $(CUSTOM_NON_DEBUG_MODULES))>> $(INFOMAKELOG)
	@$(IF_EXIST) $(strip $(TMPDIR))/cus_folder.tmp $(THEN) \
		($(CAT) $(strip $(TMPDIR))/cus_folder.tmp >> $(INFOMAKELOG)) $(CMD_END)
	@$(ECHO) -n CUSTOM_SYSTEM_FOLDER = $(call CUSTOM_FLD_MAPPING,custom\system)>> $(INFOMAKELOG)

ifdef TK_MD_CUS
	@$(ECHO) -n TK_MD_CUS = $(TK_MD_CUS) >> $(INFOMAKELOG)
endif

	@$(IF_EXIST) $(strip $(TARGDIR))/build.log $(THEN)\
		($(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log $(AND) \
		 perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log) $(CMD_END)
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

done: end send

# *************************************************************************
# TARGET: gen_infomakelog
# dump details compile info, release info to $(INFOMAKELOG) for debugging or tracking
# *************************************************************************
end:
# -----------------------------
# Clean temporary files in make directory
# -----------------------------
   # mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@echo Check if any error happened during the build process .....
	@echo TARGDIR: $(TARGDIR)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
		perl $(strip ${CORE_ROOT})/tools/parse_comp_err.pl "$(strip $(PROJECT_NAME)/$(FLAVOR))/l1core" "$(MODIS_CONFIG)" "$(strip $(TMPDIR))" $(CMD_END)
	@$(IF_EXIST) $(strip $(TMPDIR))/comp_err.txt $(THEN)\
		$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN)\
			(echo Some error happened during the build process. Delete the binary file.) $(WITH) \
			($(DEL_DIR) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(WITH) exit 1) $(CMD_END)\
		$(CMD_END)
endif

	@echo L1CORE Done.
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n
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
		perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log) \
	$(CMD_END)
	
ifeq ($(SINGLE_CORE),TRUE)
	@perl $(strip ${COMMON_ROOT})/tools/chk_verno.pl $(VERNO)
	@$(IF_NOT_EXIST) $(strip $(COMPLOGDIR)) $(THEN) \
		($(MKDIR) $(strip $(COMPLOGDIR))) \
	 $(CMD_END)
	@perl $(strip ${COMMON_ROOT})/tools/chk_feature_option.pl "$(strip $(PROJECT_MAKEFILE))" $(strip $(COMPLOGDIR)) > $(strip $(COMPLOGDIR))/chk_feature_option.log

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
		perl $(strip ${CORE_ROOT})/tools/time.pl -n >> $(strip $(TARGDIR))/build.log) \
	 $(CMD_END)
# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
# TARGET: gencompbld
# Write required script variables to config file
# *************************************************************************
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
#@$(ECHO) -n "DEBUG_SAVE_CUR_THREAD	= $(strip $(DEBUG_SAVE_CUR_THREAD))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "APCSINT	= $(strip $(APCSINT))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "ASM	= $(strip $(ASM))" 	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "LIB	= $(strip $(LIB))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CC		= $(strip $(CC))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CODEGEN_CC		= $(strip $(CODEGEN_CC))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CC32	= $(strip $(CC32))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CCINCLUDE	= $(strip $(CCINCLUDE))"	>> $(strip $(TMPDIR))/~compbld.tmp	
	@$(ECHO) -n "CPPC    	= $(strip $(CPPC))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CPPC32 	= $(strip $(CPPC32))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CFLAGS 	= $(strip $(CFLAGS))"	>> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CPLUSFLAGS = $(strip $(CPLUSFLAGS))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "VIA	= $(VIA)"		  >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "LIBOPT	= $(LIBOPT)"		  >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CUS_MTK_LIB = $(strip $(CUS_MTK_LIB))" >> $(strip $(TMPDIR))/~compbld.tmp

	@echo AFLAGS	= $(strip $(AFLAGS))    >> $(strip $(TMPDIR))/~compbld.tmp

	@$(ECHOLONGSTRING5) $(strip $(TMPDIR))/~compbld_2.tmp INCDIRS $(strip $(COMMINCDIRS))
	@$(CAT) $(strip $(TMPDIR))/~compbld_2.tmp >> $(strip $(TMPDIR))/~compbld.tmp
	@$(IF_EXIST) $(strip $(TMPDIR))/~compbld_2.tmp $(THEN) ($(DEL_FILE) $(strip $(TMPDIR))/~compbld_2.tmp) $(CMD_END)
	@$(ECHOLONGSTRING5) $(strip $(TMPDIR))/~compbld_2.tmp DEFINES $(strip $(COM_DEFS))		
	@$(CAT) $(strip $(TMPDIR))/~compbld_2.tmp >> $(strip $(TMPDIR))/~compbld.tmp
	@$(IF_EXIST) $(strip $(TMPDIR))/~compbld_2.tmp $(THEN) ($(DEL_FILE) $(strip $(TMPDIR))/~compbld_2.tmp) $(CMD_END)
	@$(ECHO) -n "PROJECT_NAME  = $(strip $(PROJECT_NAME))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "PROJECT_MAKEFILE   = $(strip $(PROJECT_MAKEFILE))"   >> $(strip $(TMPDIR))/~compbld.tmp
	@$(IF_NOT) $(P_VAR)0$(COMPILER) == $(P_VAR)0 $(THEN) \
		$(ECHO) -n "COMPILER = $(COMPILER)" >> $(strip $(TMPDIR))/~compbld.tmp $(CMD_END)
	@$(IF_NOT) $(P_VAR)0$(HEADER_TEMP) == $(P_VAR)0 $(THEN) \
		$(ECHO) -n "HEADER_TEMP = $(strip $(HEADER_TEMP))" >> $(strip $(TMPDIR))/~compbld.tmp $(CMD_END)
	@$(ECHO) -n "ACTION = $(strip $(ACTION))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CUSTOM_DEBUG_MODULES = $(strip $(CUSTOM_DEBUG_MODULES))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CUSTOM_NON_DEBUG_MODULES = $(strip $(CUSTOM_NON_DEBUG_MODULES))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "LTE_SEC_COMP = $(strip $(LTE_SEC_COMP))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "CHK_LTE_COMP = $(strip $(CHK_LTE_COMP))" >> $(strip $(TMPDIR))/~compbld.tmp
	@$(ECHO) -n "DWARF_FLAGS = $(strip $(DWARF_FLAGS))" >> $(strip $(TMPDIR))/~compbld.tmp
	
ifdef NO_PCIBT
  ifeq ($(strip $(NO_PCIBT)),TRUE)
	@$(ECHO) -n "NO_PCIBT = TRUE" >> $(strip $(TMPDIR))/~compbld.tmp
  endif
endif

# mbis time probe
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *****************************************************************************************************
# TARGET: gen_concatenate_proj
# concatenate the project makefiles and the result is placed on build/$project/$flavorn/bin
# Notice: the PROJECT_MAKEFILE should be the original project makefile in make folder. ext: make/XXX.mak
# *****************************************************************************************************
CONCATENATE_PROJ_MAK := $(strip $(TARGDIR))/~$(subst ~,,$(notdir $(strip $(PROJECT_MAKEFILE))))
ORIGINAL_PROJ_MAK    := make/projects/$(subst ~,,$(notdir $(strip $(PROJECT_MAKEFILE))))

gen_concatenate_proj:  $(strip $(CONCATENATE_PROJ_MAK))
# *****************************************************************************************************
# TARGET: $(CONCATENATE_PROJ_MAK)
# concatenate the project makefiles and the result is placed on build/$project/$flavorn/bin
# Notice: the PROJECT_MAKEFILE should be the original project makefile in make folder. ext: make/XXX.mak
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
	@perl $(strip ${COMMON_ROOT})/tools/cat_proj_mak.pl "$(strip $(ORIGINAL_PROJ_MAK))" "$(strip $(CONCATENATE_PROJ_MAK))" $(WITH) \
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

# FORCE is a phony target, any target depending on it will run forcely
FORCE:
