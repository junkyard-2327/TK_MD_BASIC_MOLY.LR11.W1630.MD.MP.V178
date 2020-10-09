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
# STANDALONE_ACTION.mak - independent build action
#
#  DISCUSSION:
#
#  USAGE:
#
#  IMPORTANT NOTES:
#
# *************************************************************************
#
# $Revision:$
# $Modtime:$
# $Log:$
#
# 01 27 2015 chi-chun.lu
# [MOLY00093671] [SM] modify memquery.pl related parameter in standalone_action.mak
# 	.
#
# 01 20 2015 chi-chun.lu
# [MOLY00092726] [TK6291] [SystemService][Auto-Gen] Memory Utility Refinement
# 	.
#
# 06 17 2014 tafang.chen
# [MOLY00062786] [UMOLY][SM]
# Remove named debug message.
#
# 05 16 2014 tafang.chen
# [MOLY00062786] [UMOLY][SM]
# sys_mem_gen (Carl.Kao)
#
# 05 07 2014 tafang.chen
# [MOLY00062786] [UMOLY][SM]
# Implement two phase linking.
#
# 05 02 2014 tafang.chen
# [MOLY00062786] [UMOLY][SM]
# Provide "memquery" for l1core
#
# 04 25 2014 tafang.chen
# [MOLY00062786] [UMOLY][SM]
# Add gendummysym for l1core.
#
# 09 13 2013 ray.lin-wang
# [MOLY00034122] [Build Environment] phase in MD32/CR4 flow
# fix build flow after moving make/* to make/pcore.
#
# *************************************************************************

.PHONY: update_memconfig post_memconfig gen_dsp_auto_adjust_mem_log gendummysym memquery

# *************************************************************************
#  Generate Binary File with Auto-Memory-Config
# *************************************************************************			
gen_dsp_auto_adjust_mem_log:
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n  >> $(strip $(TARGDIR))/build.log

#for DspSectionBase_AutoConfig.pl
	@$(ECHO) -n "AAPMC_IMGLAYOUT = $(strip $(SCATTERFILE))">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_TARGDIR = $(strip $(TARGDIR))">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_MAKEFILE = $(strip $(PROJECT_MAKEFILE))">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_INFOMAKE_LOG = $(strip $(INFOMAKELOG))">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_DSP_AUTOCONFIG_LOG = $(strip $(TMPDIR))/~DspSectionBase_AutoConfig.tmp">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_LOG_FOLDER = $(strip $(COMPLOGDIR))">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_MASTER_INFO_LOG = $(strip $(TMPDIR))/~master_info.tmp">>$(TMPDIR)/~auto_adjust_mem.tmp

#for auto_adjust_mem.pl
	@$(ECHO) -n "AAPMC_SCRIPT = DspSectionBase_AutoConfig">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_TEMP_FOLDER = $(strip $(TMPDIR))">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_DEBUG_FOLDER = $(strip $(TARGDIR))/DSP_AAPMC_DEBUG">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_CUSTOM_FOLDER_PATH = $(strip $(BUILD_SYSDIR))">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_ELF_PATH = $(strip $(TARGDIR))/$(strip $(IMG_FILE))">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_READELF_PATH = $(strip $(TARGDIR))/$(strip $(READELF_FILE))">>$(TMPDIR)/~auto_adjust_mem.tmp
	@$(ECHO) -n "AAPMC_DSP_MAP_PATH = $(strip $(TARGDIR))/$(strip $(LIS_FILE))">>$(TMPDIR)/~auto_adjust_mem.tmp


	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n  >> $(strip $(TARGDIR))/build.log

ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

update_memconfig: gen_dsp_auto_adjust_mem_log
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n    >> $(strip $(TARGDIR))/build.log
	@$(ECHO) -n "======== Begin update_memconfig ========"
#	@perl $(strip ${CORE_ROOT})/tools/auto_adjust_mem.pl $(TMPDIR)/~auto_adjust_mem.tmp > $(strip $(COMPLOGDIR))/auto_adjust_mem.log $(AND) \
		($(IF_ERR_TRUE) $(THEN) (exit 1) $(CMD_END))

#	@$(IF_EXIST) $(TMPDIR)/~NoAAPMC.tmp $(THEN)\
#		($(DEL_FILE) $(TMPDIR)/~NoAAPMC.tmp) \
#	$(ELSE) \
#		$(ECHO) -n "" $(AND)\
#		$(ECHO) -n "======== Two-Phase Linking Process Start... ========" $(AND)\
#		$(ECHO) -n "" $(AND)\
#		($(MAKE) -fmake/l1core/build.mak -r -R post_memconfig $(WITH) \
#			($(IF_ERR_TRUE) $(THEN) (exit 1) $(CMD_END))) \
#	$(CMD_END)

	($(MAKE) -fmake/l1core/build.mak -r -R post_memconfig DISABLE_SYS=TRUE $(WITH) \
		($(IF_ERR_TRUE) $(THEN) (exit 1) $(CMD_END))) \

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n  >> $(strip $(TARGDIR))/build.log
	@$(ECHO) -n "======== End update_memconfig ========"
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
#  Enter Build Flow after AAPMC
# *************************************************************************
post_memconfig: sysgen_conf LINK_BIN_FILE
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif
	@$(ECHO) "$@ START TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n  >> $(strip $(TARGDIR))/build.log

	@$(ECHO) -n ""
	@$(ECHO) -n "======== Two-Phase Linking Process Finished ========"
	@$(ECHO) -n ""

	@$(ECHO) "$@ END TIME=" >> $(strip $(TARGDIR))/build.log
	@perl $(strip ${CORE_ROOT})/tools/time.pl -n  >> $(strip $(TARGDIR))/build.log
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif


# *************************************************************************
#  Generate dummy .sym file
# *************************************************************************
gendummysym:
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

	@$(IF_EXIST) $(strip $(TMPDIR))/~libs.tmp $(THEN)\
		($(ECHO) "--noinhibit-exec " >$(TMPDIR)/~dummylibs.tmp) $(WITH) \
		($(CAT) $(strip $(TMPDIR))/~libs.tmp >> $(TMPDIR)/~dummylibs.tmp) \
	$(CMD_END)

	@$(IF_EXIST) $(strip $(COMPLOGDIR))/link_option.log $(THEN)\
		($(ECHO) "--noinhibit-exec " >$(TMPDIR)/~dummylibs.tmp) $(WITH) \
		($(CAT) $(strip $(COMPLOGDIR))/link_option.log >> $(TMPDIR)/~dummylibs.tmp) \
	$(CMD_END)

	@$(IF_NOT_EXIST) $(strip $(TMPDIR))/~dummylibs.tmp  $(THEN)\
		(echo Error: $(strip $(TMPDIR))/~dummylibs.tmp does not existed! $(WITH) exit 1) $(CMD_END)

	@$(IF_EXIST) $(strip $(TMPDIR))/~libs.tmp $(THEN)\
		($(ECHO) "--noinhibit-exec " >$(TMPDIR)/~dummylibs.tmp) $(WITH) \
		($(CAT) $(strip $(TMPDIR))/~libs.tmp >> $(TMPDIR)/~dummylibs.tmp) \
	$(CMD_END)

	@$(strip $(LINK)) $(strip $(VIA))$(TMPDIR)/~dummylibs.tmp >$(DEV_NUL) 2>&1
	@$(strip $(DUMP)) -x $(strip $(TARGDIR))/$(IMG_FILE) > $(strip $(TARGDIR))/dummy_$(TARGNAME_L).sym $(WITH) \
		($(IF_ERR_TRUE) $(THEN) \
			($(IF_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(IMG_FILE)) $(CMD_END)) $(WITH) \
			(echo Error: failed to generate .sym file $(WITH) exit 1)\
		$(CMD_END))

	@$(IF_EXIST) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) $(THEN) ($(DEL_DIR) $(strip $(TARGDIR))/$(strip $(BIN_FILE))) $(CMD_END)
	@$(IF_EXIST) $(strip $(TARGDIR))/$(IMG_FILE) $(THEN) ($(DEL_FILE) $(strip $(TARGDIR))/$(IMG_FILE)) $(CMD_END)
	@$(IF_NOT_EXIST) $(strip $(TARGDIR))/dummy_$(TARGNAME_L).sym  $(THEN) (echo Error: gendummysym failed! $(WITH) exit 1) $(CMD_END)
	@$(IF_EXIST) $(TMPDIR)/~dummylibs.tmp $(THEN) ($(DEL_FILE) $(TMPDIR)/~dummylibs.tmp) $(CMD_END)
	@echo Done for gendummysym

ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

# *************************************************************************
#  Get Memory Usage Information
# *************************************************************************
memquery:
ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_S,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

	@$(IF_EXIST) $(FIXPATH)/${COMMON_ROOT}/tools/MemoryUtility/memquery.pl $(THEN) \
		perl $(FIXPATH)/${COMMON_ROOT}/tools/MemoryUtility/memquery.pl 2 $(strip $(TMPDIR))/~memquery.tmp $(SCATTERFILE) "$(strip $(PROJECT_MAKEFILE))" $(strip $(TARGDIR))/$(TARGNAME_L).map $(strip $(COMPLOGDIR)) $(strip $(INFOMAKELOG)) $(strip $(TARGDIR))/$(strip $(BIN_FILE)) \
	$(CMD_END)

ifeq ($(strip $(MBIS_EN)),TRUE)
	@$(ECHO) -n -t "T_E,$@,T," >> $(MBIS_BUILD_TIME_TMP)
endif

