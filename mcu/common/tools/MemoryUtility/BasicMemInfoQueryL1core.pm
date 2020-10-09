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

package BasicMemInfoL1core;

#****************************************************************************
# Constants
#****************************************************************************
my $VERNO     = " u0.02";
             # u0.02 , 2015/12/02,  Added SWLA region calculation to BasicMemInfo CMD_GetRAMUsage
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
    
    Parse(FILEOPTION::MAP, $MAP_PATH);
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
    return CMD_GetROMSize($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
}

#  NO  L1core and Secure region !
sub CMD_GetROMSize
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    
    my $strROM_Base = sysInfo::GetMemoryInfo("ROM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strROM_Length = sysInfo::GetMemoryInfo("ROM", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    PrintLog($PrintFunc, "ROM Information:\n");
    PrintLog($PrintFunc, "ROM Base Address in LDS = $strROM_Base\n");
    PrintLog($PrintFunc, "ROM Length in LDS = $strROM_Length\n");
    
    my $ERs_aref = &LinkerOutputParser::ListAllExeRegion(1);
    $ERs_aref = sysInfo::FilterOutCoproReservedRegion($ERs_aref); 
    $ERs_aref = sysInfo::FilterOutSecureRegion($ERs_aref);# if(FileInfo::is_BuiltWithCopro());;     
    my $nCount = scalar(@$ERs_aref);
    my $strLastRegion = $ERs_aref->[$nCount-1];
    my $nROMBase = hex($strROM_Base);
    my $nROMSize = hex(&LinkerOutputParser::GetExeRegionInfo($strLastRegion, Region::LMA)) - $nROMBase;
    PrintLog($PrintFunc, "Last Region in ROM = $strLastRegion\n");
    if($strLastRegion !~/zi|bss/i) {
        my $nLastRegionSize = hex(&LinkerOutputParser::GetExeRegionInfo($strLastRegion, Region::Size));
        PrintLog($PrintFunc, "Last Region Size in ROM = ". CommonUtil::Dec2Hex($nLastRegionSize) ." = $nLastRegionSize(Bytes) \n");        
        $nROMSize += $nLastRegionSize;
    } else {
        PrintLog($PrintFunc, "Last Region Size in ROM = 0 (Bytes) \n");
    }
    my $strROMSize = CommonUtil::Dec2Hex($nROMSize);
    my $nROMendAddress = $nROMBase + $nROMSize;
    PrintLog($PrintFunc, "End address of last Region LMA = ". CommonUtil::Dec2Hex($nROMendAddress) ." = $nROMendAddress(Bytes) \n");
    PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
    PrintLog($PrintFunc, "Total ROM Size (Code + RO Data + RW Data) = $strROMSize = $nROMSize(Bytes) \n");
    
    return $nROMSize;
}


sub CMD_GetRAMUsage
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc, $nRAM_Base) = @_;
    $nRAM_Base = hex(sysInfo::GetMemoryInfo("RAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS)) if(!defined $nRAM_Base);

    my $ERinRAM_aref = GetERsInRAM($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
    my ($nRAMUsage, $nRAMMargin, $nSWLAMargin) = (0, 0, 0);
    if(scalar(@$ERinRAM_aref)>0)
    {   
        my $strRAM_Base = sysInfo::GetMemoryInfo("RAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        my $strVRAM_Base = sysInfo::GetMemoryInfo("VRAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        my $strRAM_Length = sysInfo::GetMemoryInfo("RAM", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        my $nRAM_End = hex($strRAM_Base)+hex($strRAM_Length);

        my $nDummyEndBase = hex(&LinkerOutputParser::Get_DUMMY_END_Base());
        $ERinRAM_aref = sysInfo::FilterOutSharedRegion($ERinRAM_aref, \%g_MAKEFILE_OPTIONS);
        my $ER = $ERinRAM_aref->[scalar(@$ERinRAM_aref)-1];
        my $nEndRegionVMA =  hex(&LinkerOutputParser::GetExeRegionInfo($ER, Region::VMA));
        my $nEndRegionSize = hex(&LinkerOutputParser::GetExeRegionInfo($ER, Region::Size));
        my $strEndRegionEndVMA = CommonUtil::Dec2Hex($nEndRegionVMA+$nEndRegionSize);
        my $nFirstERInRAMVMA = hex(&LinkerOutputParser::GetExeRegionInfo($ERinRAM_aref->[0], Region::VMA));
        my $strFirstERInRAMVMA = CommonUtil::Dec2Hex($nFirstERInRAMVMA);
        $nRAMUsage = (0x0FFFFFFF & $nEndRegionVMA) + $nEndRegionSize - (0x0FFFFFFF & $nFirstERInRAMVMA);
        $nSWLAMargin =  hex(&LinkerOutputParser::GetLinkerSymbolAddress("SWLA_REGION",LinkerSymPostfix::Length));
#$nDummyEndBase - ($nEndRegionVMA + $nEndRegionSize);
        my $SWLABase = (($nEndRegionVMA + $nEndRegionSize+16+hex("fff"))>>12)<<12;
	if (($nSWLAMargin == hex("FFFFFFFF")) || (($nSWLAMargin+$SWLABase) > $nDummyEndBase)) {
	   $nSWLAMargin = $nDummyEndBase - $SWLABase;
	 }
        $nRAMMargin = $nDummyEndBase - ($SWLABase + $nSWLAMargin);

        PrintLog($PrintFunc, "RAM Information:\n");
        PrintLog($PrintFunc, "RAM Base Address in LDS = $strRAM_Base\n");
        PrintLog($PrintFunc, "VRAM Base Address in LDS = $strVRAM_Base\n");
        PrintLog($PrintFunc, "RAM Length in LDS = $strRAM_Length\n");
        PrintLog($PrintFunc, "1st Region in RAM: ".$ERinRAM_aref->[0].", VMA=$strFirstERInRAMVMA\n");
        PrintLog($PrintFunc, "RAM end address = ". CommonUtil::Dec2Hex($nRAM_End). " = $nRAM_End\n");
        PrintLog($PrintFunc, "RegionBeforeDummyEnd: $ER, VMA=".CommonUtil::Dec2Hex($nEndRegionVMA).
                 ", Size=".CommonUtil::Dec2Hex($nEndRegionSize).", End address=$strEndRegionEndVMA\n");
        PrintLog($PrintFunc, "DummyEndBase = ".CommonUtil::Dec2Hex($nDummyEndBase)." (the end address of L1core memory (without shared memory))\n");
        PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
        PrintLog($PrintFunc, "RAM Usage    ".CommonUtil::Dec2Hex($nRAMUsage)." = $nRAMUsage(Bytes) \tfrom ".CommonUtil::Dec2Hex(0x0FFFFFFF & $nFirstERInRAMVMA)." to $strEndRegionEndVMA\n");
        PrintLog($PrintFunc, "SWLA Space   ".CommonUtil::Dec2Hex($nSWLAMargin)." = $nSWLAMargin(Bytes) \tfrom ".CommonUtil::Dec2Hex($SWLABase)." to ".CommonUtil::Dec2Hex($SWLABase+$nSWLAMargin)."\n");
        PrintLog($PrintFunc, "RAM Margin   ".CommonUtil::Dec2Hex($nRAMMargin)." = $nRAMMargin(Bytes) \tfrom ".CommonUtil::Dec2Hex($SWLABase+$nSWLAMargin)." to ".CommonUtil::Dec2Hex($nDummyEndBase)."\n");
        PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
        PrintLog($PrintFunc, "Total RAM Size (RW + ZI Data, no Shared Region) = ". CommonUtil::Dec2Hex($nRAMUsage) . " = $nRAMUsage (Bytes) \n");
    }
    return ($nRAMUsage, $nRAMMargin, $nSWLAMargin); # add $nSWLAMargin as return value,  the 3rd return value is different than pcore
}

sub GetERsInRAM
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $ERs_aref = &LinkerOutputParser::ListAllExeRegion(1);
    my $ERinRAM_aref = &sysInfo::FilterOutRegionInRAM($ERs_aref, \%g_MAKEFILE_OPTIONS);
    return $ERinRAM_aref;
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
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'BasicMemInfoL1core');    
}
