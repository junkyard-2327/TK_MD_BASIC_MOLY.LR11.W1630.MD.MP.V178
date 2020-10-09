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
#*   BasicInfoQuery.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This perl module is used to get system basic information
#*       
#*
#* Author:
#* -------
#*   Carl Kao (mtk08237)
#*
#****************************************************************************/

BEGIN { push @INC, '../', './pcore/tools/', './common/tools/MemoryUtility/' }  # add additional library path
use strict;
use POSIX qw(floor ceil);

use systemInfo;
use LinkerOutputParser;
use FileInfoParser;
use CommonUtility;

package BasicMemInfoPcore;

#****************************************************************************
# Constants
#****************************************************************************
my $VERNO     = " u0.05";
             # u0.05,  2017/June/06, Modify MemoryUtility for new layout 
             # u0.04 , 2017/May/24, New Layout
             # u0.03 , 2015/12/02,  Added SWLA region calculation to CMD_GetRAMUsage
             # u0.02 , 2015/01/20,  Memory Utility Refinement (Add shared region info to CMD_GetRAMUsage)
             # u0.01 , 2015/01/14,  Memory Utility Refinement
             # m0.06 , 2014/02/20,  Correct GetTotalRAMUsageFromLDS's base address
             # m0.05 , 2013/12/25,  Fix LoadView which can't count in .bss
             # m0.04 , 2013/10/20,  Support Secure region
             # m0.03 , 2013/06/25,  Support CMD_GetROMSize() for filtering out COPRO section
             # m0.02 , 2013/03/21,  Support GetMBAlignment()
             # m0.01 , 2013/01/08,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************
my $g_bParseSYM = 0;
my $g_bParseMAP = 0;
my $g_bParseMAKEFILE = 0;
my %g_MAKEFILE_OPTIONS;

#****************************************************************************
# Subroutine:  BasicInfoQuery_verno - to query this package's version number
# Parameters:  x
# Returns:     version number string
#****************************************************************************
sub BasicInfoQuery_verno
{
    return $VERNO;
}

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

sub DispatchCommand
{
    my ($cmd, $MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;

    # force the Parse to be called in DispatchCommand in order to make sure the only entry function of this file is DispatchCommand
    sub Parse
    {
        my ($nOption, $PATH) = @_;
        if($nOption == FILEOPTION::MAP and !$g_bParseMAP)
        {
            basicinfo_die("$PATH doesn't exist!") if(!-e $PATH);
            &LinkerOutputParser::FileParse($PATH);
            $g_bParseMAP = 1;
        }
        elsif($nOption == FILEOPTION::SYM and !$g_bParseSYM)
        {
            basicinfo_die("$PATH doesn't exist!") if(!-e $PATH);
            &LinkerOutputParser::FileParse($PATH);
            $g_bParseSYM = 1;
        }
        elsif($nOption == FILEOPTION::MAKEFILE and !$g_bParseMAKEFILE)
        {
            basicinfo_die("$PATH doesn't exist!") if(!-e $PATH);
            &FileInfo::Parse_MAKEFILE($PATH, \%g_MAKEFILE_OPTIONS);
            $g_bParseMAKEFILE = 1;
        }
}
    
    Parse(FILEOPTION::SYM, $SYM_PATH);
    Parse(FILEOPTION::MAKEFILE, $MAKEFILE_PATH, \%g_MAKEFILE_OPTIONS);
    $cmd = "help" if($cmd eq "-h" or $cmd eq "--help");
    my ($pack_name, $file, $line_no) = caller;   
    no strict 'refs';
    &{$cmd}($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) if (exists &{$cmd})
        or basicinfo_die("$cmd() doesn't exists!", $file, $line_no);
}

# It  HAS  L1core and Secure region !
sub CMD_GetLoadViewSize
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $ERs_aref = &LinkerOutputParser::ListAllExeRegion(1);
    
    # $ERs_aref = sysInfo::FilterOutCoproReservedRegion($ERs_aref); #if(FileInfo::is_BuiltWithCopro());
    # $ERs_aref = sysInfo::FilterOutSecureRegion($ERs_aref); # if(FileInfo::is_BuiltWithCopro());

    my $nCount = scalar(@$ERs_aref);
    my $strLastRegion = $ERs_aref->[$nCount-1];
    my $nLastRegionSize = 0;
    my $nLoadViewSize = hex(&LinkerOutputParser::GetExeRegionInfo($strLastRegion, Region::LMA));
    if($strLastRegion !~/zi|bss/i) {
        $nLastRegionSize = hex(&LinkerOutputParser::GetExeRegionInfo($strLastRegion, Region::Size));
        $nLoadViewSize += $nLastRegionSize;
    }    
    my $strROMTotal_Length  = sysInfo::GetMemoryInfo("ROM", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strROM1_Base        = sysInfo::GetMemoryInfo("ROM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strROM1_Length      = sysInfo::GetMemoryInfo("L1CORE_LV", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strL1CORE_LV_Base   = $strROM1_Length;
    my $strL1CORE_LV_Length = sysInfo::GetMemoryInfo("L1CORE_LV", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strROM2_Base        = CommonUtil::Dec2Hex(hex($strL1CORE_LV_Base)+hex($strL1CORE_LV_Length));
    my $strROM2_Length      = CommonUtil::Dec2Hex(hex($strROMTotal_Length) - hex($strROM2_Base));

    PrintLog($PrintFunc, "Load Information:\n");
    PrintLog($PrintFunc, "ROM1 Base Address = $strROM1_Base\n");
    PrintLog($PrintFunc, "ROM1 Length = $strROM1_Length\n");
    PrintLog($PrintFunc, "L1CORE_LV Base Address = $strL1CORE_LV_Base\n");
    PrintLog($PrintFunc, "L1CORE_LV Length = $strL1CORE_LV_Length\n");
    PrintLog($PrintFunc, "ROM2 Base = $strROM2_Base\n");
    PrintLog($PrintFunc, "ROM2 Length = $strROM2_Length\n");
    PrintLog($PrintFunc, "Last Region in load = $strLastRegion\n");
    if($strLastRegion !~/zi|bss/i) {
        PrintLog($PrintFunc, "Last Region Size in Load = ". CommonUtil::Dec2Hex($nLastRegionSize) . " = $nLastRegionSize(Bytes) \n");
    } else {
        PrintLog($PrintFunc, "Last Region Size in load = 0 (Bytes) \n");
    }
    PrintLog($PrintFunc, "End address of last Region LMA in load = ". CommonUtil::Dec2Hex($nLoadViewSize) . " = $nLoadViewSize(Bytes) \n");
    PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
    PrintLog($PrintFunc, "Total Pcore + L1core Load Size (ROM1 + L1CORE_LV + ROM2) = ". CommonUtil::Dec2Hex($nLoadViewSize) . " = $nLoadViewSize(Bytes) \n");
#    PrintLog($PrintFunc, "(ROM size is treated as 0x80000 since ".CommonUtil::Dec2Hex(hex($strROM1_Length))." to 0x80000 is reserved for l1core TCM space)\n") if (hex($strROM1_Length) < hex(80000));
    return $nLoadViewSize;
}

#TODO: merge CMD_GetROMSize to CMD_GetLoadViewSize
# NO  L1core but it contains Secure region !
sub CMD_GetROMSize
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $ERs_aref = &LinkerOutputParser::ListAllExeRegion(1);
    
    $ERs_aref = sysInfo::FilterOutCoproReservedRegion($ERs_aref); #if(FileInfo::is_BuiltWithCopro());
#     $ERs_aref = sysInfo::FilterOutSecureRegion($ERs_aref); # if(FileInfo::is_BuiltWithCopro());

    my $nCount = scalar(@$ERs_aref);
    my $strLastRegion = $ERs_aref->[$nCount-1];
    my $nLastRegionSize = 0;
    my $nLoadViewSize = hex(&LinkerOutputParser::GetExeRegionInfo($strLastRegion, Region::LMA));
    if($strLastRegion !~/zi|bss/i) {
        $nLastRegionSize = hex(&LinkerOutputParser::GetExeRegionInfo($strLastRegion, Region::Size));
        $nLoadViewSize += $nLastRegionSize;
    }    
    my $strROMTotal_Length  = sysInfo::GetMemoryInfo("ROM", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strROM1_Base        = sysInfo::GetMemoryInfo("ROM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strROM1_Length      = sysInfo::GetMemoryInfo("L1CORE_LV", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strL1CORE_LV_Base   = $strROM1_Length;
    my $strL1CORE_LV_Length = sysInfo::GetMemoryInfo("L1CORE_LV", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strROM2_Base        = CommonUtil::Dec2Hex(hex($strL1CORE_LV_Base)+hex($strL1CORE_LV_Length));
    my $strROM2_Length      = CommonUtil::Dec2Hex(hex($strROMTotal_Length) - hex($strROM2_Base));

#    PrintLog($PrintFunc, "ROM Information:\n");
#    PrintLog($PrintFunc, "ROM1 Base Address = $strROM1_Base\n");
#    PrintLog($PrintFunc, "ROM1 Length = $strROM1_Length\n");
#    PrintLog($PrintFunc, "L1CORE_LV Base Address = $strL1CORE_LV_Base\n");
#    PrintLog($PrintFunc, "L1CORE_LV Length = $strL1CORE_LV_Length\n");
#    PrintLog($PrintFunc, "ROM2 Base = $strROM2_Base\n");
#    PrintLog($PrintFunc, "ROM2 Length = $strROM2_Length\n");
#    PrintLog($PrintFunc, "Last Region in load = $strLastRegion\n");
#    if($strLastRegion !~/zi|bss/i) {
#        PrintLog($PrintFunc, "Last Region Size in Load = ". CommonUtil::Dec2Hex($nLastRegionSize) . " = $nLastRegionSize(Bytes) \n");
#    } else {
#        PrintLog($PrintFunc, "Last Region Size in load = 0 (Bytes) \n");
#    }
#    PrintLog($PrintFunc, "End address of last Region LMA in load = ". CommonUtil::Dec2Hex($nLoadViewSize) . " = $nLoadViewSize(Bytes) \n");  
    

    my $nROM_Length = hex($strROM1_Length) + hex($strROM2_Length);
#    PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
    PrintLog($PrintFunc, "Total Pcore ROM Size (ROM1 + ROM2 = Code + RO Data + RW Data) = $strROM1_Length + $strROM2_Length = $nROM_Length(Bytes) \n");
#    PrintLog($PrintFunc, "(The space from $strROMSize to 0x80000 is reserved for l1core TCM space)\n") if ($nROMSize < hex(80000));
    
    return $nLoadViewSize;
}

sub CMD_GetNonSharedRAMUsage
{

    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;

    my $ERinRAM_aref = GetERsInRAM($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
    my ($nNonSharedRAMUsage, $nRAMMargin) = (0, 0, 0);
    if(scalar(@$ERinRAM_aref)>0)
    {   
        my $EndRegion = @$ERinRAM_aref[scalar(@$ERinRAM_aref)-1];
        
        # 1. calculate current RAM usage by "end of last section - base of first section "
        
        #my $nFirstERInRAMVMA = hex(&LinkerOutputParser::GetExeRegionInfo($ERinRAM_aref->[0], Region::VMA)); 

        my $nFirstNonSharedERInRAMVMAinBank0 = hex(&LinkerOutputParser::GetExeRegionInfo('CACHED_EXTSRAM', Region::VMA)) & 0x0FFFFFFF;
        my $nEndRegionVMA =  hex(&LinkerOutputParser::GetExeRegionInfo($EndRegion, Region::VMA));        
        my $nEndRegionSize = hex(&LinkerOutputParser::GetExeRegionInfo($EndRegion, Region::Size));
        $nNonSharedRAMUsage = $nEndRegionVMA + $nEndRegionSize - $nFirstNonSharedERInRAMVMAinBank0;


        # 2. get RAM Margin, 1:base, 2:length
        my $nRAM_Base = hex(sysInfo::GetMemoryInfo("RAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS));
        my $nRAM_Length = hex(sysInfo::GetMemoryInfo("RAM", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS));
        my $nVRAM_Base = sysInfo::GetMemoryInfo("VRAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        $nRAMMargin = ($nRAM_Base + $nRAM_Length) - ($nEndRegionVMA + $nEndRegionSize);

        
        # 3. no need to get the space of dsp tx/rx since there is no region in the end of RAM
        # $nReservedSize = GetReservedSize($IMAGELAYOUT_PATH, $SYM_PATH, $MAKEFILE_PATH);

    }
    return ($nNonSharedRAMUsage, $nRAMMargin);
}

sub CMD_GetRAMUsage
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc, $nRAM_Base) = @_;
    $nRAM_Base = hex(sysInfo::GetMemoryInfo("RAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS)) if(!defined $nRAM_Base);

    my $ERinRAM_aref = GetERsInRAM($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
    my ($nRAMUsage, $nRAMMargin, $nRAMMarin1) = (0, 0, 0);
    if(scalar(@$ERinRAM_aref)>0)
    {   
        my $strRAM_Base = sysInfo::GetMemoryInfo("RAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        my $strVRAM_Base = sysInfo::GetMemoryInfo("VRAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        my $strRAM_Length = sysInfo::GetMemoryInfo("RAM", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        
        my $nDummyEndBase = hex(&LinkerOutputParser::Get_DUMMY_END_Base());
        my $ER = $ERinRAM_aref->[scalar(@$ERinRAM_aref)-1];
        my $nEndRegionVMA =  hex(&LinkerOutputParser::GetExeRegionInfo($ER, Region::VMA));
        my $nEndRegionSize = hex(&LinkerOutputParser::GetExeRegionInfo($ER, Region::Size));
        my $strEndRegionEndVMA = CommonUtil::Dec2Hex($nEndRegionVMA+$nEndRegionSize);
        my $nFirstERInRAMVMA = hex(&LinkerOutputParser::GetExeRegionInfo($ERinRAM_aref->[0], Region::VMA));
        my $strFirstERInRAMVMA = CommonUtil::Dec2Hex($nFirstERInRAMVMA);
        $nRAMUsage = (0x0FFFFFFF & $nEndRegionVMA) + $nEndRegionSize - (0x0FFFFFFF & $nFirstERInRAMVMA);
        $nRAMMargin = $nDummyEndBase - ($nEndRegionVMA + $nEndRegionSize);
        $nRAMMarin1 = $nFirstERInRAMVMA-hex($strRAM_Base);
        my $SWLABase = (($nEndRegionVMA + $nEndRegionSize+16+hex("fff"))>>12)<<12;
	my $SWLASize = hex(&LinkerOutputParser::GetLinkerSymbolAddress("SWLA_REGION",LinkerSymPostfix::Length));
	if (($SWLASize == hex("FFFFFFFF")) || (($SWLASize+$SWLABase) > $nDummyEndBase)) {
	   $SWLASize = $nDummyEndBase - $SWLABase;
	 }
	$nRAMMargin =$nDummyEndBase - ($SWLABase + $SWLASize);
        my $strRAMMarin1 = CommonUtil::Dec2Hex($nRAMMarin1);

        my $ERinRAMnoShared_aref = GetNonSharedMemoryERsInRAM($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
        my $nFirstNonSharedERInRAMVMA = hex(&LinkerOutputParser::GetExeRegionInfo($ERinRAMnoShared_aref->[0], Region::VMA));
        $nFirstNonSharedERInRAMVMA = (0x0FFFFFFF & $nFirstNonSharedERInRAMVMA);
        my $strFirstNonSharedERInRAMVMA = CommonUtil::Dec2Hex($nFirstNonSharedERInRAMVMA);

        PrintLog($PrintFunc, "RAM Information:\n");
        PrintLog($PrintFunc, "RAM Base Address in LDS = $strRAM_Base\n");
        PrintLog($PrintFunc, "VRAM Base Address in LDS = $strVRAM_Base\n");
        PrintLog($PrintFunc, "RAM Length in LDS = $strRAM_Length\n");
        PrintLog($PrintFunc, "1st Region in RAM: ".$ERinRAM_aref->[0].", VMA=$strFirstERInRAMVMA\n");
        PrintLog($PrintFunc, "RegionBeforeDummyEnd: $ER, VMA=".CommonUtil::Dec2Hex($nEndRegionVMA).
                 ", Size=".CommonUtil::Dec2Hex($nEndRegionSize).", End address=$strEndRegionEndVMA\n");
        PrintLog($PrintFunc, "DummyEndBase = ".CommonUtil::Dec2Hex($nDummyEndBase)." (the end address of total MD memory)\n");
        PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
        PrintLog($PrintFunc, "RAM Margin 1 $strRAMMarin1 = $nRAMMarin1(Bytes) \tfrom $strRAM_Base to $strFirstERInRAMVMA (for part of l1core SWLA)\n");
        PrintLog($PrintFunc, "RAM Usage    ".CommonUtil::Dec2Hex($nRAMUsage)." = $nRAMUsage(Bytes) \tfrom $strFirstERInRAMVMA to $strEndRegionEndVMA\n");
	PrintLog($PrintFunc, "SWLA Space   ".CommonUtil::Dec2Hex($SWLASize)." = $SWLASize(Bytes)\t from ".CommonUtil::Dec2Hex($SWLABase)." to ".CommonUtil::Dec2Hex($SWLABase+$SWLASize)."\n");
        PrintLog($PrintFunc, "RAM Margin 2 ".CommonUtil::Dec2Hex($nRAMMargin)." = $nRAMMargin(Bytes) \tfrom ".CommonUtil::Dec2Hex($SWLABase+$SWLASize)." to ".CommonUtil::Dec2Hex($nDummyEndBase)."\n");
        PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
        PrintLog($PrintFunc, "RAM Usage consist of\n");
        PrintLog($PrintFunc, "    1) Shared memory : ".($nFirstNonSharedERInRAMVMA-$nFirstERInRAMVMA)."(Bytes) \tfrom $strFirstERInRAMVMA to $strFirstNonSharedERInRAMVMA\n");      
        PrintLog($PrintFunc, "    2) PCORE RW + ZI : ".(hex($strEndRegionEndVMA)-$nFirstNonSharedERInRAMVMA)."(Bytes) \tfrom $strFirstNonSharedERInRAMVMA to $strEndRegionEndVMA\n");   
        PrintLog($PrintFunc, "Total RAM Size (Shared Region + RW + ZI Data) = ". CommonUtil::Dec2Hex($nRAMUsage) . " = $nRAMUsage (Bytes) \n");
    }
    return ($nRAMUsage, $nRAMMargin, $nRAMMarin1); # add $strRAMMarin1 as return value,  the 3rd return value is different than l1core
}

sub GetERsInRAM
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $ERs_aref = &LinkerOutputParser::ListAllExeRegion(1);
    my $ERinRAM_aref = &sysInfo::FilterOutRegionInRAM($ERs_aref, \%g_MAKEFILE_OPTIONS);
    return $ERinRAM_aref;
}

sub GetNonSharedMemoryERsInRAM
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $ERinRAM_aref = GetERsInRAM($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
    my $ERinRAMnoShared_aref = &sysInfo::FilterOutSharedRegion($ERinRAM_aref, \%g_MAKEFILE_OPTIONS);
    return $ERinRAMnoShared_aref;
}

sub GetExpectedLoadViewSize
{
    basicinfo_die("not support GetExpectedLoadViewSize");

    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $nActualROMSize = CMD_GetLoadViewSize($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
    PrintLog($PrintFunc, "ActualROMSize = ".CommonUtil::Dec2Hex($nActualROMSize)." = $nActualROMSize(Bytes)\n");
    my $nExpectedROMSize = &CommonUtil::GetMBAligned($nActualROMSize, 1);
    PrintLog($PrintFunc, "ExpectedROMSize = ".CommonUtil::Dec2Hex($nExpectedROMSize)." = $nExpectedROMSize(Bytes)\n");
    return $nExpectedROMSize;
}

sub GetExpectedROMSize
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $nActualROMSize = CMD_GetROMSize($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
    PrintLog($PrintFunc, "ActualROMSize = ".CommonUtil::Dec2Hex($nActualROMSize)." = $nActualROMSize(Bytes)\n");
    my $nExpectedROMSize = $nActualROMSize;
    #$nExpectedROMSize = 0x80000 if ($nActualROMSize < hex(0x80000)) ;
    PrintLog($PrintFunc, "ExpectedROMSize = ".CommonUtil::Dec2Hex($nExpectedROMSize)." = $nExpectedROMSize(Bytes)\n");
    #PrintLog($PrintFunc, "(The space from ".CommonUtil::Dec2Hex($nActualROMSize)." to 0x80000 is reserved for l1core TCM space)\n") if ($nActualROMSize < hex(0x80000));
    PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
    return $nExpectedROMSize;
}

sub GetExpectedRAMSize
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my ($nRAMUsage, $nRAMMargin, $nRAMMargin1) = 
                    CMD_GetRAMUsage($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
    my $nActualRAMSize = $nRAMUsage;
    PrintLog($PrintFunc, "ActualRAMSize = ".CommonUtil::Dec2Hex($nActualRAMSize)." = $nActualRAMSize(Bytes)\n");
    my $nExpectedRAMSize = $nRAMUsage ; #+ $nRAMMargin + $nRAMMargin1;
    PrintLog($PrintFunc, "RAM Margin 1 ".CommonUtil::Dec2Hex($nRAMMargin1)." = $nRAMMargin1(Bytes)\n");
    PrintLog($PrintFunc, "RAM Usage    ".CommonUtil::Dec2Hex($nRAMUsage).  " = $nRAMUsage(Bytes)\n");
    PrintLog($PrintFunc, "RAM Margin 2 ".CommonUtil::Dec2Hex($nRAMMargin). " = $nRAMMargin(Bytes)\n");
    PrintLog($PrintFunc, "ExpectedRAMSize = ".CommonUtil::Dec2Hex($nExpectedRAMSize)." = $nExpectedRAMSize(Bytes)\n");
  
    return $nExpectedRAMSize;
}

sub GetTotalRAMUsageFromLDS
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $strRAM_Base = sysInfo::GetMemoryInfo("RAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strRAM_Length = sysInfo::GetMemoryInfo("RAM", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    return (hex($strRAM_Base)&0x0FFFFFFF) + hex($strRAM_Length);
}

sub CMD_GetPhysicalRAMUsage
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $nExepectedROMSize = GetExpectedROMSize($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $nExpectedRAMSize = GetExpectedRAMSize($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $nPRAMUsage = $nExepectedROMSize + $nExpectedRAMSize;
    PrintLog($PrintFunc, "Total Physical RAMUsage(ROM + RAM) = ".CommonUtil::Dec2Hex($nExepectedROMSize)." + ".
             CommonUtil::Dec2Hex($nExpectedRAMSize)." = ". CommonUtil::Dec2Hex($nPRAMUsage) ."\n");
    return $nPRAMUsage ;
}

sub CMD_GetL1CORE_RWZISize
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $strL1CORE_RWZI_Base = sysInfo::GetMemoryInfo("L1CORE_RWZI", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strL1CORE_RWZI_Length = sysInfo::GetMemoryInfo("L1CORE_RWZI", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    
    PrintLog($PrintFunc, "L1CORE_RWZI Base Address in LDS = $strL1CORE_RWZI_Base\n");
    PrintLog($PrintFunc, "L1CORE_RWZI Length in LDS = $strL1CORE_RWZI_Length\n");
}

sub wait_for_reuse
#sub GetReservedSize
{
    my ($IMAGELAYOUT_PATH, $SYM_PATH, $MAKEFILE_PATH) = @_;
    my @ERinRAM;
    my $BB_PATH = dirname($IMAGELAYOUT_PATH);
    sysInfo::GetRAMregion($BB_PATH, $IMAGELAYOUT_PATH, \@ERinRAM, \%g_MAKEFILE_OPTIONS);
    my $FixedER_aref = &sysInfo::FilterOutFixedRegion(\@ERinRAM, \%g_MAKEFILE_OPTIONS);

    #######################
    # FIX_ME, what is the reserve size?
    #######################

#    my $nReservedSize = 0;
#    foreach my $ER (@$FixedER_aref)
#    {
#        my $strSize = sysInfo::GetRegionInfo($ER, Region::MaxSize, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
#        $nReservedSize += hex($strSize);
#    }
#    return $nReservedSize;
}


sub PrintLog
{
    my ($LogFunc, $strLog) = @_;
    &{$LogFunc}($strLog) if(exists &{$LogFunc});
}
#****************************************************************************
# Subroutine:  basicinfo_die
# Parameters:  1. string error message, 2. __FILE__ 3. __LINE__
# Returns:     x
#****************************************************************************
sub basicinfo_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'BasicMemInfoPcore');    
}
