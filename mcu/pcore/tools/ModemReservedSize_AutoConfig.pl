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
#*   ModemReservedSize_AutoConfig.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parses sym/linker script 
#*   and give some recommendation or create new MEMORY config file
#* Author:
#* -------
#*   Carl Kao (mtk08237)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, "pcore/" , './pcore/tools/', './common/tools/MemoryUtility/' }  # add additional library path             
use auto_adjust_mem; #pm file name without case sensitivity
use FileInfoParser;
use sysGenUtility;
use CommonUtility;
use BasicMemInfoQuery;
use systemInfo;
use ldsFrame;
use File::Basename;
use File::Copy;
use File::Path;
use LinkerOutputParser;
use POSIX qw(floor ceil);
#****************************************************************************
# AutoCheckin Information
#****************************************************************************
use constant OWNER        => "";
#****************************************************************************
# Constants
#****************************************************************************
my $MODEMSIZE_CONFIG_VERNO    = " LR11_v0.02";
           # LR11_v0.02,   2017/May/24, Carl,   New Layout
           # LR11_v0.01,   2015/08/31,  Carl,   Reduce total memory size of MT6755 and MT6797 from 160MB to 128MB
                               #  u0.18  20150623 by Carl,  Refine the way to use GetSharedMemorySize. It includes dsp tx/rx section now
                               #  u0.17  20150518 by Carl,  Align the end address of MD to MPU alignment
                               #  u0.16  20150514 by Carl,  Support Ramdisk for TK6291
                               #  u0.15  20150126 by Carl,  Refine GetMPUAligned for adding debug log
                               #  u0.14  20150114 by Carl,  Refine Memory Utility
                               #  u0.13  20150106 by Carl,  lds refinement: 1) auto adjust shared region size, 2) reserve pcore, l1core SWLA space
                               #  u0.12  20141105 by Carl,  move align_for_mpu() to commun utility
                               #  u0.11  20140926 by Carl,  Support GFH + SIG
                               #  u0.10  20140905 by Carl,  Reduce default shared memory size for PCORE ONLY project
                               #  u0.09, 20140805 by Carl,  Increase default shared memory region size
                               #  u0.08, 20140731 by Carl,  Dump l1core region
                               #  ...
                               #  v0.08, 20130625 by mei, Support COPRO auto config
                               #  v0.07, 20130603 by mei, Add infomake.log input
                               #  v0.06, 20130425 by mei, Not to limit SetMemorySegment() in NOR project only 
                               #  v0.05, 20130321 by mei, Support to show basic ram info during checking load view
                               #  v0.04, 20130321 by mei, Set MT6572&6582 to be 2 MB aligned
                               #  v0.03, 20130208 by mei, perl 5.58 can't support: make_path
                               #  v0.02, 20130124 by mei, to replace chip with cloned chip
                               #  v0.01, initial draft

#****************************************************************************
# Inputs
#****************************************************************************
my $MAP_PATH                    = $ARGV[0]; 
my $SYM_PATH                    = $ARGV[1];
my $LDS_PATH                    = $ARGV[2];
my $BUILD_FOLDER                = $ARGV[3];
my $FEATURE_CONFIG_H            = $ARGV[3] . "/custom_FeatureConfig.h";
my $MAKE_FILE                   = $ARGV[4];
my $INTERMEDIATE_FILE           = $ARGV[5];  #build/.../tmp/~ModemReservedSize_AutoConfig.tmp 
my $LOG_PATH                    = $ARGV[6];
my $INFOMAKE_PATH               = $ARGV[7];
my $COPRO_INFO_PATH             = $ARGV[8];
my $PROJECT_NAME                = basename($MAKE_FILE);

print "Input:\n$ARGV[0]\n$ARGV[1]\n$ARGV[2]\n$ARGV[3]\n$ARGV[4]\n$ARGV[5]\n$ARGV[6]\n$ARGV[7]\n$ARGV[8]\n";

#****************************************************************************
# Global Variables
#****************************************************************************
my $COPRO_INFO_FILE_2       = $COPRO_INFO_PATH."2";
my %MAKEFILE_OPTIONS;
my %CmplOption;
my %RelOption;
my $g_bAutoConfig = 0;
my $ERR_CODE;
my $g_nExpectedROMSize = undef;
my $g_nExpectedRAMSize = undef;
my $g_nExpectedRAMBase = undef;
my $g_nCOPRO_TOTAL_USAGE = 0;
my $g_nROM1_Size = 0;
my $g_nL1CORE_LV_SIZE = 0;
my $g_nROM2_Size = 0;
my $g_nL1CORE_RWZI_SIZE = 0;
my $g_nSHARED_REGION_SIZE = 0;
my $g_strMsg;
#****************************************************************************
# >>>  Check if it's able to adjust
#****************************************************************************
# Combine Copro_info into MakeFile Option, and then it can be queried by FileInfo.
my $strCoproInfo = CommonUtil::GetFileContent($COPRO_INFO_PATH);
CommonUtil::HashStringParser($strCoproInfo, \%MAKEFILE_OPTIONS) if($strCoproInfo ne "");
my $bEnableAutoConfig = 
    IsEnabledAutoConfig($MAKE_FILE, \%MAKEFILE_OPTIONS, $INFOMAKE_PATH, \%CmplOption, \%RelOption);

#****************************************************************************
# WARNING:: necessarily to set g_nCOPRO_TOTAL_USAGE because BasicInfo will reparse make file again
#$g_nCOPRO_TOTAL_USAGE = FileInfo::get(FileInfo::COPRO_TOTAL_USAGE); if(FileInfo::is_BuiltWithCopro()); 
#****************************************************************************
$g_nROM1_Size           = FileInfo::get(FileInfo::PCORE_LV1_SIZE);
$g_nL1CORE_LV_SIZE      = FileInfo::get(FileInfo::L1CORE_LV_SIZE);
$g_nROM2_Size           = FileInfo::get(FileInfo::PCORE_LV2_SIZE);
$g_nL1CORE_RWZI_SIZE    = FileInfo::get(FileInfo::L1CORE_RWZI_SIZE);
$g_nSHARED_REGION_SIZE  = FileInfo::get(FileInfo::SHARED_REGION_SIZE);

my $bHasHistory = (1==sysUtil::HasCheckinHistory($LDS_PATH) ? 1 : 0);  # if may return undef
my $g_bb = sysUtil::SwitchToClonedChip(FileInfo::GetChip());
my $g_bSupportedToAdjustLoadView = sysUtil::isSupportedToAdjustLoadView($g_bb);
my $g_bSupportedToAdjustRAMSize = sysUtil::isSupportedToAdjustRAMSize($g_bb);
my $bSupportedCompiler = (FileInfo::GetCompiler() eq "GCC");
my $g_bPcoreOnly = &BuildInfo::exist(BuildOPT::CMPL, "__PCORE_ONLY__");
$g_bAutoConfig = ($bEnableAutoConfig 
             and ($g_bSupportedToAdjustLoadView or $g_bSupportedToAdjustRAMSize) 
             and $bSupportedCompiler
             and !$bHasHistory
             and !$g_bPcoreOnly);

print "-----------------------------------------------------------------\n";
print "Check if it's able to adjust($g_bAutoConfig):\n";
print "bEnableAutoConfig      = $bEnableAutoConfig\n";
print "bHasHistory            = $bHasHistory\n";
print "SupportedMDAutoConfig  = (LoadView=$g_bSupportedToAdjustLoadView or RamSize=$g_bSupportedToAdjustRAMSize)\n";
print "bSupportedCompiler     = $bSupportedCompiler\n";
print "bPcoreOnly             = $g_bPcoreOnly\n";
my $strPrompt = (!$g_bAutoConfig) ? "disabled" : "enabled";
PrintLog("AutoConfig is $strPrompt\n");
#****************************************************************************
# >>>  Main Flow
#****************************************************************************
if(!$g_bAutoConfig) # not able to config
{
    if(!$bSupportedCompiler)
    {
        print "Unsupported Compiler: ".FileInfo::GetCompiler()."\n";
        $ERR_CODE = ERR::CANNOT_ADJUST;
    }
    else
    {
        $ERR_CODE = CheckLoadViewSize($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE);
    }
}
else
{
    $ERR_CODE = AutoAdjust($g_bb, $MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH);
}

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
PrintLog("-----------------------------------------------------------------\n");
PrintLog("RESULT = ". ERR::QueryErrMeaning($ERR_CODE)."\n");
CommonUtil::WriteFileContent($INTERMEDIATE_FILE, $g_strMsg);
exit $ERR_CODE;



sub AutoAdjust
{
    my ($bb, $MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH)= @_;

    my $nL1CORE_SWLA_SPACE = 0;

    
    # <1> Total ROM 
    # note: it is better not to use CMD_GetROMSize() during AAPMC since no L1core ROM is inside two Pcore ROMs
    my $nActualROMSize = $g_nROM1_Size + $g_nL1CORE_LV_SIZE + $g_nROM2_Size;


    # 1.5 Copro
    #$strCopro = "arm7" if(FileInfo::is_BuiltWithCopro());
    #$g_nExpectedROMSize = CommonUtil::GetMBAligned($nActualROMSize, sysUtil::GetCopro_KBAlignment($strCopro)/1024); 

    $g_nExpectedROMSize = $nActualROMSize;



    # <2> L1CORE_LV
    my $nL1CORE_LVBase = $g_nROM1_Size;    
    # l1core TCM: 0x0 ~ 0x80000, so the smallest size shoould be 0x80000. It should sync with TK6291_MemorySetting() in LdsGen.pl & L1coreLdsGen.pl
    $nL1CORE_LVBase = 0x80000 if ($nL1CORE_LVBase < 0x80000); 
    my $nL1CORE_LVEnd = $nL1CORE_LVBase + $g_nL1CORE_LV_SIZE;


    # <3> PCORE ROM2
    my $nROM2_Base = $nL1CORE_LVEnd;
    my $nROM2_Size = $g_nROM2_Size;


    # <4> L1CORE_RWZI
    my $nL1CORE_RWZIBase = &CommonUtil::GetMPUAligned( $nROM2_Base + $nROM2_Size, "L1CORE_RWZIBase");
        # calculate L1CORE SWLA space part 1
        $nL1CORE_SWLA_SPACE += &CommonUtil::GetMPUAligned($nL1CORE_RWZIBase + $g_nL1CORE_RWZI_SIZE) - ($nL1CORE_RWZIBase + $g_nL1CORE_RWZI_SIZE, "L1CORE_SWLA_SPACE");
    # MPU alignment
    my $nL1CORE_RWZIEnd = &CommonUtil::GetMPUAligned($nL1CORE_RWZIBase + $g_nL1CORE_RWZI_SIZE, "L1CORE_RWZIEnd");
    # update size
    $g_nL1CORE_RWZI_SIZE = $nL1CORE_RWZIEnd - $nL1CORE_RWZIBase;



    # <5> RAM Size # reserved margin at least 0.5MB for SWLA (for pcore and l1core)
    my $nReservedMargin = 0.5*1024*1024;
    $g_nExpectedRAMBase = $nL1CORE_RWZIEnd;
    #my ($region_size_tx, $region_size_rx) = &sysUtil::DSPTXRX_query_length($g_bb, undef);
    my $nSharedMemorySize = $g_nSHARED_REGION_SIZE; # + $region_size_tx + $region_size_rx;  
        # calculate L1CORE SWLA space part 2
        $nL1CORE_SWLA_SPACE += &CommonUtil::GetMPUAligned($g_nExpectedRAMBase + $nSharedMemorySize) - ($g_nExpectedRAMBase + $nSharedMemorySize, "L1CORE_SWLA_SPACE");
        # if the space between "end of l1core RWZI" to "base of shared region" is smaller than $nReservedMargin, we should increae shared memory size about $nReservedMargin
        if ($nL1CORE_SWLA_SPACE<$nReservedMargin){  $nSharedMemorySize += $nReservedMargin;
            PrintLog("nL1CORE_SWLA_SPACE: $nL1CORE_SWLA_SPACE is smaller than $nReservedMargin -> add $nReservedMargin to nSharedMemorySize: $nSharedMemorySize\n");
        }else{ PrintLog("nL1CORE_SWLA_SPACE = $nL1CORE_SWLA_SPACE \n"); }
    # $nNonSharedMemoryInRamBase = the end address of shared region = start address of PS RW. need MPU alignment
    my $nNonSharedMemoryInRamBase = &CommonUtil::GetMPUAligned($g_nExpectedRAMBase + $nSharedMemorySize, "NonSharedMemoryInRamBase");
    # update size
    $nSharedMemorySize = $nNonSharedMemoryInRamBase - $g_nExpectedRAMBase; 
    my ($nRAMUsage, $nRAMMargin) = BasicMemInfo::DispatchCommand("CMD_GetNonSharedRAMUsage", $MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    $g_nExpectedRAMSize = GetExpectedRAMSize($nNonSharedMemoryInRamBase, $nRAMUsage, $nReservedMargin) + $nSharedMemorySize;

    
    
    # 4. Get LDS ROM Length and RAM Length, and the 1stRegion Base in RAM
    my $nROM_Length = hex(sysInfo::GetMemoryInfo("ROM", 2, $LDS_PATH));
    my $nRAM_Length = hex(sysInfo::GetMemoryInfo("RAM", 2, $LDS_PATH));
    my $ERsInRAM_aref = BasicMemInfo::DispatchCommand("GetERsInRAM", $MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $n1stERInRAMVMA = hex(&LinkerOutputParser::GetExeRegionInfo($ERsInRAM_aref->[0], Region::VMA));
    my $nMB = ($g_nExpectedRAMBase+$g_nExpectedRAMSize)/(1024*1024);


    
    PrintLog("----------------------------Auto Adjust--------------------------\n");
    PrintLog("Actual ROM Size = ". CommonUtil::Dec2Hex($nActualROMSize)."\n");
    PrintLog("current ROM Length in LDS = ". CommonUtil::Dec2Hex($nROM_Length)."\n");    
    PrintLog("current L1CORE_LV Origin = ". CommonUtil::Dec2Hex($nL1CORE_LVBase)."\n");
    PrintLog("current L1CORE_LV Lendth = ". CommonUtil::Dec2Hex($g_nL1CORE_LV_SIZE)."\n");
    PrintLog("current L1CORE_RWZI Origin = ". CommonUtil::Dec2Hex($nL1CORE_RWZIBase)."\n");
    PrintLog("current L1CORE_RWZI Lendth = ". CommonUtil::Dec2Hex($g_nL1CORE_RWZI_SIZE)."\n");
    PrintLog("current RAM Origin in LDS = ". sysInfo::GetMemoryInfo("RAM", 1, $LDS_PATH). "\n");
    PrintLog("current RAM Length in LDS = ". CommonUtil::Dec2Hex($nRAM_Length)."\n");
    PrintLog("current 1stER in ram = ".$ERsInRAM_aref->[0].", VMA=". CommonUtil::Dec2Hex($n1stERInRAMVMA)."\n");
    PrintLog("current RAM Usage = ".CommonUtil::Dec2Hex($nRAMUsage)."\n");
#    PrintLog("current RAM Reserved Sizes = ".CommonUtil::Dec2Hex($nReservedSize)."\n");
    PrintLog("current RAM Margin = ".CommonUtil::Dec2Hex($nRAMMargin)."\n");
    PrintLog("current at least Margin setting = ".CommonUtil::Dec2Hex($nReservedMargin)."\n");
#    PrintLog("current CORPO Reserved Size = ". CommonUtil::Dec2Hex($g_nCOPRO_TOTAL_USAGE) ."\n") if(FileInfo::is_BuiltWithCopro());
    PrintLog("expected ROM Sizes = ". CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
    PrintLog("expected RAM Base = ". CommonUtil::Dec2Hex($g_nExpectedRAMBase)."\n");
    PrintLog("expected RAM Sizes = ". CommonUtil::Dec2Hex($g_nExpectedRAMSize)."\n");
    PrintLog("expected MD Sizes(ROM+ L1CORE_LV + RAM) = ". CommonUtil::Dec2Hex($g_nExpectedRAMBase+$g_nExpectedRAMSize)." = $nMB MB \n");
    PrintLog("-----------------------------------------------------------------\n");
    
    my $err;

    # check MD size before adjusting
    my $nMDLimit = &sysUtil::GetMDTotolSizeLimitation($g_bb)/1024/1024;
    if( $nMB > $nMDLimit )
    {
        PrintLog("AAPMC Error: Actual total MD size $nMB MB > Limitation $nMDLimit MB. Please reduce total MD size\n");
        $err = ERR::TOTAL_MD_MEMORY_SIZE_EXCEED_LIMIT;
        return $err;
    }
    
    if(($g_bSupportedToAdjustLoadView and ($nActualROMSize > $nROM_Length)) 
    or ($g_bSupportedToAdjustRAMSize  and ($g_nExpectedRAMSize != $nRAM_Length) )) # RAM size is RAM BASE+LEN
    {
        my $strFilePath = PrepareFileToModify();
        ModifyMEMORY($strFilePath);
        $err = ERR::AUTOCONFIG_SELF_MODIFY_SUCCESS;
        RecommendDuringAutoAdjust($err, $nActualROMSize, $nROM_Length, $nL1CORE_RWZIBase,
                                 $n1stERInRAMVMA, $ERsInRAM_aref->[0], $nRAM_Length, $nRAMUsage);
    }
    else
    {
        $err = ERR::NO_NEED_TO_UPDATE;
        $err = RecommendDuringAutoAdjust($err, $nActualROMSize, $nROM_Length, 0,
                                 $n1stERInRAMVMA, $ERsInRAM_aref->[0], $nRAM_Length, $nRAMUsage);
    }        

    # Memory in lds is changed
    # -> dump offset for adjusting l1core memory dump region address
    {
        my $minus_ref = { FileInfo::L1CORE_REGION__OFFSET => $nL1CORE_RWZIBase };
        my $srtOffset = CommonUtil::HashStringGenerator($minus_ref);
        CommonUtil::WriteFileContent($COPRO_INFO_FILE_2, $srtOffset);
    }
    return $err;
}

sub RecommendDuringAutoAdjust
{
    my ($err, $nActualROMSize, $nROM_Length, $nL1CORE_RWZIBase, $n1stERInRAMVMA, $ER1st, $nRAM_Length, $nRAMTotalUsage) = @_;
    if($nActualROMSize > $nROM_Length)
    {
        if(!$g_bSupportedToAdjustLoadView)
        {
            PrintLog("Actual ROM Size > ROM Length in LDS\n");
            PrintLog("[Recommend] Setting ROM Length to " . CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
        }
        $err = ERR::CANNOT_ADJUST;
    }
    if($g_nExpectedRAMSize != $nRAM_Length)
    {
        if(!$g_bSupportedToAdjustRAMSize)
        {
            PrintLog("[Recommend] Setting RAM Length to " . CommonUtil::Dec2Hex($g_nExpectedRAMSize)."\n");
        }
        $err = ERR::CANNOT_ADJUST if($nRAM_Length < $nRAMTotalUsage);
    }
    return $err;
}

sub PrepareFileToModify
{
    ldsFrame::CleanCallBackFunc();
    my $strDefaultMEMORYPath = ldsFrame::GetPath($g_bb, ldsFrame::MEMORY);
    my $strFilePath = $strDefaultMEMORYPath;
    if($strDefaultMEMORYPath =~ /custom\/system\/(.+)/i)
    {
        my $strTemp = $1;
        $BUILD_FOLDER .= "/" if($BUILD_FOLDER !~ /\/$/);
        $strFilePath = $BUILD_FOLDER . $strTemp;
        if(!-e $strFilePath)
        {
            my $DIR = dirname($strFilePath);
            mkpath($DIR) if(!-f $DIR);
            print "[PrepareFileToModify]copy $strDefaultMEMORYPath \nto $strFilePath\n";
            copy($strDefaultMEMORYPath, $strFilePath) or config_die("Copy Fail!");
            # chmod for read-only codebase
            chmod(0640, $strFilePath) if($^O eq "MSWin32");
        }
    }
    return $strFilePath;
}
sub ModifyMEMORY
{
    my ($strFilePath) = @_;
    &ldsFrame::CleanCallBackFunc();
    &ldsFrame::SetCallBackFunc("GetChip", \&GetChip);
    &ldsFrame::SetCallBackFunc("SetMemorySegment", \&SetMemorySegment);
    &ldsFrame::SetCallBackFunc("GetCustomFolder", \&GetCustomFolder);
    my $strContent = ldsFrame::GenMEMORY(ldsFrame::MAIN);
    CommonUtil::WriteFileContent($strFilePath, $strContent);
    print "Generate $strFilePath successfully!\n";
}
sub GetCustomFolder  #ldsFrame's callback func
{
    return $BUILD_FOLDER;
}
sub GetChip  # ldsFrame's callback func
{
    return $g_bb;
}

sub GetExpectedRAMSize
{
    my ($nLVMBAlignedSize, $nRAMSize, $nReservedMargin) = @_;
    my $nOrgSize = $nLVMBAlignedSize + $nRAMSize;
    # extern RAM to MPU alignment to protect whole RAM
    my $nExpectedRamSize = &CommonUtil::GetMPUAligned($nOrgSize, "GetExpectedRAMSize-1");
    if(($nExpectedRamSize - $nOrgSize) < $nReservedMargin)
    {
        $nExpectedRamSize = &CommonUtil::GetMPUAligned($nOrgSize+$nReservedMargin, "GetExpectedRAMSize-2");
    }
    return $nExpectedRamSize - $nLVMBAlignedSize;
}

sub SetMemorySegment # ldsFrame's callback func
{
    my ($MEMORY_SEGMENT_aref) = @_;
    my $nIndex = 0;
#    my $NCPrefix = sysUtil::GetNonCacheablePrefix($g_bb);
#    my $CPrefix = sysUtil::GetCacheablePrefix($g_bb);
    foreach my $i (@$MEMORY_SEGMENT_aref)
    {
        my $strName = $i->[0];
        if($strName eq "ROM")
        {
            if($g_bSupportedToAdjustLoadView)
            {
            	# we calaulate the size of ROM_GFH twice!
                $MEMORY_SEGMENT_aref->[$nIndex]->[2] = CommonUtil::Dec2Hex($g_nExpectedROMSize);
                PrintLog("Modify ROM Length = ".CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
            }
        }
        else
        {
            if($strName eq "RAM" and $g_bSupportedToAdjustLoadView)
            {
                $MEMORY_SEGMENT_aref->[$nIndex]->[1] = CommonUtil::Dec2Hex($g_nExpectedRAMBase);
                PrintLog("Modify RAM ORIGIN = ".CommonUtil::Dec2Hex($g_nExpectedRAMBase)."\n");
            }
            if($strName eq "RAM" and $g_bSupportedToAdjustRAMSize)
            {
                $MEMORY_SEGMENT_aref->[$nIndex]->[2] = CommonUtil::Dec2Hex($g_nExpectedRAMSize);
                PrintLog("Modify RAM Length = ".CommonUtil::Dec2Hex($g_nExpectedRAMSize)."\n");
            }
            if($strName eq "COPRO_SPACE")
            {
                $MEMORY_SEGMENT_aref->[$nIndex]->[2] = CommonUtil::Dec2Hex($g_nCOPRO_TOTAL_USAGE);
                PrintLog("Modify COPRO_RESERVED_LEN= ".CommonUtil::Dec2Hex($g_nCOPRO_TOTAL_USAGE)."\n");
            }
        }
        $nIndex++;
    }
}

sub ShowBasicInfo
{
    config_die("not support ShowBasicInfo()");

    my ($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE, $nExpectedROMSize)= @_;
    my ($nRAMUsage, $nRAMMargin) = BasicMemInfo::DispatchCommand("CMD_GetRAMUsage", $MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $nExpectedRAMSize = &CommonUtil::GetMBAligned($nRAMUsage, 1);
    my $nMB = ($nExpectedROMSize + $nExpectedRAMSize)/(1024*1024);
    PrintLog("-----------------Current BasicInfo for reference-----------------\n");
    PrintLog("current RAM Usage = ".CommonUtil::Dec2Hex($nRAMUsage)."\n");
#    PrintLog("current RAM Reserved Sizes = ".CommonUtil::Dec2Hex($nReservedSize)."\n");
    PrintLog("current RAM Margin = ".CommonUtil::Dec2Hex($nRAMMargin)."\n");
    PrintLog("After 1MB aligned:\n");
    PrintLog("ROM Sizes = ". CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
    PrintLog("RAM Sizes (RAM Usage + Reserved Sizes) = ". CommonUtil::Dec2Hex($nExpectedRAMSize)."\n");
    PrintLog("Actual MD Usage(ROM+RAM) = ". CommonUtil::Dec2Hex($nExpectedROMSize+$nExpectedRAMSize)." = $nMB MB \n");
    PrintLog("-----------------------------------------------------------------\n");
}

sub CheckLoadViewSize
{
    #######################
    # we don't need this function
    #######################
    return ERR::NO_MODIFY;


    my ($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE)= @_;
    my $err;
    #Check LoadView size with ROM Length and 1st RAM Base
    # 1. ROM(LoadViewSize)
    my $nActualROMSize = BasicMemInfo::DispatchCommand("CMD_GetROMSize", $MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $nExpectedROMSize = $nActualROMSize; #&CommonUtil::GetMBAligned($nActualROMSize, 1);

    
    # 1.5 Copro
    #my $strCopro;
    #$strCopro = "arm7" if(FileInfo::is_BuiltWithCopro());
    #$nActualROMSize = &CommonUtil::GetMBAligned($nActualROMSize, sysUtil::GetCopro_KBAlignment($strCopro)/1024); 
    
    #my $nExpectedROMSize = $nActualROMSize;
    #$nActualROMSize += $g_nCOPRO_TOTAL_USAGE if(FileInfo::is_BuiltWithCopro());
    #$nExpectedROMSize = &CommonUtil::GetMBAligned($nActualROMSize, 1); 


    # 2. L1CORE_LV
    #my $nL1CORE_LVBase = $g_nExpectedROMSize;
    #my $nL1CORE_LVEnd = &CommonUtil::GetMPUAligned( $nL1CORE_LVBase + $g_nL1CORE_LV_SIZE);
    # update size
    #$g_nL1CORE_LV_SIZE = $nL1CORE_LVEnd - $nL1CORE_LVBase;



    # 3. L1CORE_RWZI
    #my $nL1CORE_RWZIBase = $nL1CORE_LVEnd;
    #my $nL1CORE_RWZIEnd = &CommonUtil::GetMPUAligned($nL1CORE_RWZIBase + $g_nL1CORE_RWZI_SIZE);
    # update size
    #$g_nL1CORE_RWZI_SIZE = $nL1CORE_RWZIEnd - $nL1CORE_RWZIBase;


    
    # 2. ROM of MEMORY in LDS
    my $nROM_Length = hex(sysInfo::GetMemoryInfo("ROM", 2, $LDS_PATH));
    # 3. VMA of 1st Region in RAM
    my $ERsInRAM_aref = BasicMemInfo::DispatchCommand("GetERsInRAM", $MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $n1stERInRAMVMA = 0x0FFFFFFF & hex(&LinkerOutputParser::GetExeRegionInfo($ERsInRAM_aref->[0], Region::VMA));
    
    PrintLog("-------------------------Check Load View------------------------\n");
    PrintLog("Actual ROM(Load View) Size = ". CommonUtil::Dec2Hex($nActualROMSize)."\n");
    PrintLog("current ROM Length in LDS= ". CommonUtil::Dec2Hex($nROM_Length)."\n");
    PrintLog("current RAM Origin in LDS = ". sysInfo::GetMemoryInfo("RAM", 1, $LDS_PATH). "\n");
    PrintLog("current 1st ER in ram = ".$ERsInRAM_aref->[0].", VMA=". CommonUtil::Dec2Hex($n1stERInRAMVMA)."\n");
    PrintLog("-----------------------------------------------------------------\n");
    # ShowBasicInfo($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE, $nExpectedROMSize);
    #-----------------------------------------------------
    if(($nActualROMSize > $nROM_Length) or ($nActualROMSize > $n1stERInRAMVMA))
    {
        if($nActualROMSize > $nROM_Length)
        {
            PrintLog("Actual ROM(Load View) Size > ROM Length in LDS\n");
            PrintLog("[Recommend] Setting ROM Length to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        if($nActualROMSize > $n1stERInRAMVMA)
        {
            PrintLog("Actual ROM(Load View) Size > 1st VMA in RAM\n");
            PrintLog("[Recommend] Setting the base address of " . $ERsInRAM_aref->[0] . 
                        " to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        $err = ERR::ERR_LOADVIEWSIZE_INSUFFICIENT;
    }
    else
    {
        if($n1stERInRAMVMA != $nExpectedROMSize)
        {
            PrintLog("[Recommend] Setting the base address of " . $ERsInRAM_aref->[0] . 
                    " to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        if($nROM_Length < $nExpectedROMSize)
        {
            PrintLog("[Recommend] Setting ROM Length to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        if(!(($nROM_Length < $nExpectedROMSize) or ($n1stERInRAMVMA != $nExpectedROMSize)))
        {
            PrintLog("[Load View Analysis] PASS \n");
        }
        PrintLog("-----------------------------------------------------------------\n");
        $err = IsPrvLinkedPASS($INTERMEDIATE_FILE) ? ERR::NO_MODIFY : ERR::CANNOT_ADJUST;
        ($err == ERR::NO_MODIFY) ? PrintLog("Previous Linkage: PASS\n") : PrintLog("Previous Linkage: FAIL\n");
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
    if(!&FileInfo::PreProcess($MK_PATH, $mk_option_href, $INFOMAKELOG, $CmplOption_href, $RelOption_href))
    {
        print "MakeFile/Infomake.log Parse Error: ERR_UNEXPECTED\n";
        exit ERR::ERR_UNEXPECTED;
    }
    my $bEnable = FileInfo::get(uc("ModemReservedSize_AutoConfig")) eq "TRUE" ? 1 : 0;
    return $bEnable;
}

sub IsPrvLinkedPASS
{
    my ($INTERMEDIATE_FILE) = @_;
    my $strContent = CommonUtil::GetFileContent($INTERMEDIATE_FILE);
    return $strContent eq ""; # equal "" = PASS, having contents = FAIL
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
    &AUTO_ADJUST::error_handler($error_msg, $file, $line_no, 'ModemReservedSize_Config');
}
