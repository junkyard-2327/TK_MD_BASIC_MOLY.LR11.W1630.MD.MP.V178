#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
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
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   DspSectionBase_AutoConfig.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parses master information/linker script 
#*   and give some recommendation or create new MEMORY config file
#*
#*
#* Author:
#* -------
#*   Carina Liao  (mtk04017)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './l1core/tools/'}  # add additional library path             
use auto_adjust_mem; #pm file name without case sensitivity
use L1coreFileInfoParser;
use L1coreSysGenUtility;
use L1coreCommonUtility;
use tclInfo;

#****************************************************************************
# AutoCheckin Information
#****************************************************************************

#****************************************************************************
# Constants
#****************************************************************************
my $DSPSECTIONBASE_CONFIG_VERNO    = " v0.01";
                                    #  v0.01, 20130701 by Carina, initial version

#****************************************************************************
# Inputs
#****************************************************************************
my $IMAGELAYOUT                 = $ARGV[0];
my $BUILD_FOLDER                = $ARGV[1];
my $MAKE_FILE                   = $ARGV[2];
my $INFOMAKE_PATH               = $ARGV[3];
my $INTERMEDIATE_FILE           = $ARGV[4];  #build/.../tmp/~DspSectionBase_AutoConfig.tmp 
my $LOG_PATH                    = $ARGV[5];
my $MASTER_INFO_PATH            = $ARGV[6];  #build/.../tmp/~master_info.tmp
#my $PROJECT_NAME                = basename($MAKE_FILE);

print "Input:\n$ARGV[0]\n$ARGV[1]\n$ARGV[2]\n$ARGV[3]\n$ARGV[4]\n$ARGV[5]\n$ARGV[6]\n";


#****************************************************************************
# Global Variables
#****************************************************************************
my %MAKEFILE_OPTIONS;
my %CmplOption;
my %RelOption;
my $g_bAutoConfig = 0;
my $ERR_CODE;
my $g_strMsg;

my $g_DSPtclInfo;
#****************************************************************************
# >>>  Check if it's able to adjust
#****************************************************************************
# Combine Copro_info into MakeFile Option, and then it can be queried by CoproFileInfo.
my $strMasterInfo = L1coreCommonUtil::GetFileContent($MASTER_INFO_PATH);
L1coreCommonUtil::HashStringParser($strMasterInfo, \%MAKEFILE_OPTIONS) if($strMasterInfo ne "");
my $bEnableAutoConfig = 
    IsEnabledAutoConfig($MAKE_FILE, \%MAKEFILE_OPTIONS, $INFOMAKE_PATH, \%CmplOption, \%RelOption);

my $bHasHistory = CoproSysUtil::HasCheckinHistory($IMAGELAYOUT);
#my $g_bb = CoproSysUtil::SwitchToClonedChip(L1coreFileInfo::GetChip());
my $bSupportedCompiler = (L1coreFileInfo::GetCompiler() eq "CHESS");
$g_bAutoConfig = ($bEnableAutoConfig 
             and (defined $bHasHistory and $bHasHistory == 0)
             and $bSupportedCompiler);

print "-----------------------------------------------------------------\n";
print "Check if it's able to adjust($g_bAutoConfig):\n";
print "bEnableAutoConfig      = $bEnableAutoConfig\n";
print "bHasHistory            = $bHasHistory\n";
print "bSupportedCompiler     = $bSupportedCompiler\n";
my $strPrompt = (!$g_bAutoConfig) ? "disabled" : "enabled";
PrintLog("AutoConfig is $strPrompt\n");
#****************************************************************************
# >>>  Main Flow
#****************************************************************************
if(!$g_bAutoConfig) # not able to config
{
    if(!$bSupportedCompiler)
    {
        print "Unsupported Compiler: ".L1coreFileInfo::GetCompiler()."\n";
        $ERR_CODE = ERR::CANNOT_ADJUST;
    }
    else
    {
        $ERR_CODE = ERR::NO_MODIFY;
    }
}
else
{
    $ERR_CODE = CheckSectionBase($MAKE_FILE, $IMAGELAYOUT, $MASTER_INFO_PATH, $INTERMEDIATE_FILE);
}

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
PrintLog("-----------------------------------------------------------------\n");
PrintLog("RESULT = ". ERR::QueryErrMeaning($ERR_CODE)."\n");
L1coreCommonUtil::WriteFileContent($INTERMEDIATE_FILE, $g_strMsg);
exit $ERR_CODE;

sub CheckSectionBase
{
    my ($MAKE_FILE, $IMAGELAYOUT, $MASTER_INFO_PATH, $INTERMEDIATE_FILE)= @_;
    my $err;
    # 1. Check the SectionBase in tcl
    $g_DSPtclInfo = new tclInfo;
    $g_DSPtclInfo->ParseLinkerScript($IMAGELAYOUT);
    my $nActualLoadViewBase = $g_DSPtclInfo->GetPreDefinedBaseAddr(tclInfo::DSP_COPRO_LV_BASE);
    my $nActualExecViewRWZIBase = $g_DSPtclInfo->GetPreDefinedBaseAddr(tclInfo::DSP_COPRO_RWZI_BASE);
    my $nActualDYN_DNC_MasterShareBuffBase = $g_DSPtclInfo->GetPreDefinedBaseAddr(tclInfo::MASTER_DYN_DNC_SHARED_BUFF_BASE);
    my $nActualDYN_DNC_MasterShareBuffEnd = $g_DSPtclInfo->GetPreDefinedBaseAddr(tclInfo::MASTER_DYN_DNC_SHARED_BUFF_END);
    my $nActualDYN_DNC_MasterShareBuffLength = $g_DSPtclInfo->GetPreDefinedBaseAddr(tclInfo::MASTER_DYN_DNC_SHARED_BUFF_LENGTH);
    my $nActualNC_MasterShareBuffBase = $g_DSPtclInfo->GetPreDefinedBaseAddr(tclInfo::MASTER_NC_SHARED_BUFF_BASE);
    my $nActualNC_MasterShareBuffEnd = $g_DSPtclInfo->GetPreDefinedBaseAddr(tclInfo::MASTER_NC_SHARED_BUFF_END);
    my $nActualNC_MasterShareBuffLength = $g_DSPtclInfo->GetPreDefinedBaseAddr(tclInfo::MASTER_NC_SHARED_BUFF_LENGTH);
    
    # 2. Get the SectionBase in ~master_info.tmp
    my $nExpectedLoadViewBase = $MAKEFILE_OPTIONS{L1coreFileInfo::DSP_COPRO_LV_BASE};
    my $nExpectedExecViewRWZIBase = $MAKEFILE_OPTIONS{L1coreFileInfo::DSP_COPRO_RWZI_BASE};
    my $nExpectedDYN_DNC_MasterShareBuffBase = $MAKEFILE_OPTIONS{L1coreFileInfo::MASTER_DYN_DNC_SHARED_BUFF_BASE};
    my $nExpectedDYN_DNC_MasterShareBuffEnd = $MAKEFILE_OPTIONS{L1coreFileInfo::MASTER_DYN_DNC_SHARED_BUFF_END};
    my $nExpectedDYN_DNC_MasterShareBuffLength = $MAKEFILE_OPTIONS{L1coreFileInfo::MASTER_DYN_DNC_SHARED_BUFF_LENGTH};
    my $nExpectedNC_MasterShareBuffBase = $MAKEFILE_OPTIONS{L1coreFileInfo::MASTER_NC_SHARED_BUFF_BASE};
    my $nExpectedNC_MasterShareBuffEnd = $MAKEFILE_OPTIONS{L1coreFileInfo::MASTER_NC_SHARED_BUFF_END};
    my $nExpectedNC_MasterShareBuffLength = $MAKEFILE_OPTIONS{L1coreFileInfo::MASTER_NC_SHARED_BUFF_LENGTH};

    
    PrintLog("-------------------------Check SectionBase------------------------\n");
    PrintLog("current Load View Base in TCL= ". L1coreCommonUtil::Dec2Hex($nActualLoadViewBase)."\n");
    PrintLog("current Execution View RW/ZI BASE in TCL= ". L1coreCommonUtil::Dec2Hex($nActualExecViewRWZIBase)."\n");
    PrintLog("current Master Share Buff(DYN_DNC) Base in TCL= ". L1coreCommonUtil::Dec2Hex($nActualDYN_DNC_MasterShareBuffBase)."\n");
    PrintLog("current Master Share Buff(DYN_DNC) End in TCL= ". L1coreCommonUtil::Dec2Hex($nActualDYN_DNC_MasterShareBuffEnd)."\n");
    PrintLog("current Master Share Buff(DYN_DNC) Length in TCL= ". L1coreCommonUtil::Dec2Hex($nActualDYN_DNC_MasterShareBuffLength)."\n");
    PrintLog("current Master Share Buff(NC) Base in TCL= ". L1coreCommonUtil::Dec2Hex($nActualNC_MasterShareBuffBase)."\n");
    PrintLog("current Master Share Buff(NC) End in TCL= ". L1coreCommonUtil::Dec2Hex($nActualNC_MasterShareBuffEnd)."\n");
    PrintLog("current Master Share Buff(NC) Length in TCL= ". L1coreCommonUtil::Dec2Hex($nActualNC_MasterShareBuffLength)."\n");
    PrintLog("-----------------------------------------------------------------\n");
    #-----------------------------------------------------
    if(($nActualLoadViewBase == $nExpectedLoadViewBase) and ($nActualExecViewRWZIBase == $nExpectedExecViewRWZIBase)
    and ($nActualDYN_DNC_MasterShareBuffBase == $nExpectedDYN_DNC_MasterShareBuffBase) and ($nActualDYN_DNC_MasterShareBuffEnd == $nExpectedDYN_DNC_MasterShareBuffEnd) 
    and ($nActualNC_MasterShareBuffBase == $nExpectedNC_MasterShareBuffBase) and ($nActualNC_MasterShareBuffEnd == $nExpectedNC_MasterShareBuffEnd))
    {
            PrintLog("All of the base addresses are the same in tcl(linker configuration file) and ~master_info.tmp\n");
            $err = ERR::NO_NEED_TO_UPDATE;
    }
    else
    {
        PrintLog("[Recommend] Setting the base address of Load View base to ". L1coreCommonUtil::Dec2Hex($nExpectedLoadViewBase)."\n");
        PrintLog("[Recommend] Setting the base address of Execution View RW/ZI Base to ". L1coreCommonUtil::Dec2Hex($nExpectedExecViewRWZIBase)."\n");
        PrintLog("[Recommend] Setting the base address of Master Share Buff(DYN_DNC) Base to ". L1coreCommonUtil::Dec2Hex($nExpectedDYN_DNC_MasterShareBuffBase)."\n");
        PrintLog("[Recommend] Setting the base address of Master Share Buff(DYN_DNC) End to ". L1coreCommonUtil::Dec2Hex($nExpectedDYN_DNC_MasterShareBuffEnd)."\n");
        PrintLog("[Recommend] Setting the base address of Master Share Buff(DYN_DNC) Length to ". L1coreCommonUtil::Dec2Hex($nExpectedDYN_DNC_MasterShareBuffLength)."\n");
        PrintLog("[Recommend] Setting the base address of Master Share Buff(NC) Base to ". L1coreCommonUtil::Dec2Hex($nExpectedNC_MasterShareBuffBase)."\n");
        PrintLog("[Recommend] Setting the base address of Master Share Buff(NC) End to ". L1coreCommonUtil::Dec2Hex($nExpectedNC_MasterShareBuffEnd)."\n");
        PrintLog("[Recommend] Setting the base address of Master Share Buff(NC) Length to ". L1coreCommonUtil::Dec2Hex($nExpectedNC_MasterShareBuffLength)."\n");
        $err = ERR::NEED_TO_UPDATE;
    }
    return $err;
}

sub PrintLog
{
    my ($strContent) = @_;
    print $strContent;
    $g_strMsg .= $strContent;
}

sub IsEnabledAutoConfig
{
    my ($MK_PATH, $mk_option_href, $INFOMAKELOG, $CmplOption_href, $RelOption_href) = @_; 
    if(!&L1coreFileInfo::PreProcess($MK_PATH, $mk_option_href, $INFOMAKELOG, $CmplOption_href, $RelOption_href))
    {
        print "MakeFile/Infomake.log Parse Error: ERR_UNEXPECTED\n";
        exit ERR::ERR_UNEXPECTED;
    }
    my $bEnable = L1coreFileInfo::get(uc("DspSectionBase_AutoConfig")) eq "TRUE" ? 1 : 0;
    return $bEnable;
}

#****************************************************************************
# subroutine:  config_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub config_die
{
    my ($error_msg) = @_;
    my ($pack_name, $file, $line_no) = caller;
    &AUTO_ADJUST::error_handler($error_msg, $file, $line_no, 'DspSectionBase_AutoConfig');
}
