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
#*   CMMAutoGen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script generates the CMM files for debugging
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, "l1core/" , './l1core/tools/' }  # add additional library path
use L1coreSysGenUtility;                 #pm file name without case sensitivity
use L1coreFileInfoParser;
use LISInfo;
use File::Copy;
use File::Basename;
use CommonUtility;
#****************************************************************************
# Constants
#****************************************************************************
my $CMMGEN_VERNO     = " u1.02";
                      #  u1.02 , Refine error message for avoid false alarm in EWS build
                      #  u1.01 , Rename l1core's memory dump name
                      #  u1.00 , initial version for multicore support
my $CMMGEN_AUTHOR    = "Qmei Yang";

#****************************************************************************
# Input Parameters and Global Variables
#****************************************************************************
my $ACTION        = $ARGV[0];  # 0: MAUI nocode.cmm; 1: HQ_Only.cmm; 2: BL nocode.cmm; 3: EXT_BL nocode.cmm; 4: FOTA nocode.cmm
my $CMMFILE       = $ARGV[1];
my $ELFFILE       = $ARGV[2];
my $MAKEFILE      = $ARGV[3];
my $MAUI_BIN      = $ARGV[4];
my $LISFILE       = $ARGV[5];
my $CC_CMD        = $ARGV[6];
my $VIA_CMD       = $ARGV[7];
my $OPTION_TMP    = $ARGV[8];
my $TMP_FOLDER    = $ARGV[9];
my $INFOMAKE_PATH = $ARGV[10];
my $TMPFILE_PATH  = $ARGV[11];
my $BM_NEW        = $ARGV[12];


my $DebugPrint = 0;
my $CMMDIR  = dirname($CMMFILE);
my $BUILDDIR  = dirname($ELFFILE);
my $g_strCOMPILER = undef;
print "ACTION: $ACTION,\nCMMFILE: $CMMFILE,\nCMMDIR:  $CMMDIR,\n
ELFFILE: $ELFFILE, \nMAKEFILE: $MAKEFILE,\n
MAUI_BIN: $MAUI_BIN, \nLISFILE: $LISFILE, \n
CC_CMD: $CC_CMD, \nVIA_CMD: $VIA_CMD, \nOPTION_TMP: $OPTION_TMP\n
TMP_FOLDER: $TMP_FOLDER\nINFOMAKE_PATH: $INFOMAKE_PATH\n
TMPFILE_PATH: $TMPFILE_PATH\n";

#****************************************************************************
# 1 >>> Parse makefile
#****************************************************************************
my %MAKEFILE_OPTIONS;
my %CmplOption;
my %RelOption;
FileInfo::PreProcess($MAKEFILE, \%MAKEFILE_OPTIONS, $INFOMAKE_PATH, \%CmplOption, \%RelOption, 1);
my $PLATFORM = &FileInfo::GetChip();
$PLATFORM = &sysUtil::SwitchToClonedChipForCMM($PLATFORM);
$PLATFORM =~ s/\_COPRO// if($PLATFORM =~ /\_COPRO/); # temporarily workaround
$g_strCOMPILER = &FileInfo::GetCompiler();


#****************************************************************************
# 2 >>> Parse reg_base.h
#****************************************************************************
my $REG_BASE_TMP_AFTER_TRANSFORM = "$TMP_FOLDER/~reg_base_after_transform.h";
my $REG_BASE_TMP_AFTER_PRECOMPILE = "$TMP_FOLDER/~reg_base_after_precompile.h";
my $REG_BASE_H = "./l1core/driver/regbase/inc/";
my %REG_BASE_DEFS;

### Determine reg_base.h by platform
my $platform_lc = lc($PLATFORM);
my $reg_base_h_file = "reg_base_" . $platform_lc . "\.h";
$REG_BASE_H .= $reg_base_h_file;
copy ($REG_BASE_H, "$TMP_FOLDER/$reg_base_h_file");

### Change reg_base definitions to data structure for pre-compile
&reg_base_define_to_struct($TMP_FOLDER, $reg_base_h_file, $REG_BASE_TMP_AFTER_TRANSFORM);

### Pre-compile reg_base.h to get the correct register base addresses
my $status = system("$CC_CMD $VIA_CMD $OPTION_TMP -E $REG_BASE_TMP_AFTER_TRANSFORM > $REG_BASE_TMP_AFTER_PRECOMPILE") if($g_strCOMPILER eq "RVCT");
my $status = system("$CC_CMD $VIA_CMD$OPTION_TMP -E $REG_BASE_TMP_AFTER_TRANSFORM > $REG_BASE_TMP_AFTER_PRECOMPILE") if($g_strCOMPILER eq "GCC");
&error_handler("pcore/tools/CMMAutoGen.pl: pre-compile $REG_BASE_TMP_AFTER_TRANSFORM error!", __FILE__, __LINE__) if ($status != 0);

### Parse pre-compiled results and get the correct base address for each address
&parse_reg_base($REG_BASE_TMP_AFTER_PRECOMPILE, \%REG_BASE_DEFS);
if ($DebugPrint == 1)
{
    foreach (keys %REG_BASE_DEFS)
    {
        my $key = $_;
        my $value = $REG_BASE_DEFS{$_};
        print "#define $key $value\n";
    }
}

#****************************************************************************
# 3 >>> Generate MAUI nocode.cmm and utility cmm files
#****************************************************************************


if( $BM_NEW eq "bm_new" && !(-e $LISFILE) )
{
    print("[Parameter] $LISFILE doesn't exist. exit 0 without checking \"", __FILE__, __LINE__);
    exit 0;
}

if ($ACTION == 0)
{
    ### Parse LIS file first (do not parse LIS file outside to prevent unnecessary errors when LIS does not exist)
    &LISInfo::Parse($LISFILE);
    
    ### Generate MAUI nocode.cmm
    {
        my $maui_nocode_template;
    
        ### Copyright Statement
        $maui_nocode_template .= &template_copyright_file_header();
        
        ### verno string
        $maui_nocode_template .= &template_verno();
        
        ### CPU-related information and commands (chip-dependent)
        $maui_nocode_template .= &template_cpu_info_command($PLATFORM);
    
        ### clean win and endup
        $maui_nocode_template .= &template_clean_win_and_endup(1);
        
        open (CMM_FILE, ">$CMMFILE") or &error_handler("$CMMFILE: Unable to open $CMMFILE!\n", __FILE__, __LINE__);
        print CMM_FILE $maui_nocode_template;
        close CMM_FILE;
    }
    
    ### Generate BuildInfo.cmm
    {
        my $BuildInfoCMM = "$CMMDIR/L_BuildInfo.cmm";
        my $TemplateFolder = "./l1core/tools/DebuggingSuite/Misc/";
        my $template = &CommonUtil::GetFileContent($TemplateFolder."L_BuildInfoTemplate.cmm");
        $template = &Gen_Info_CMMContent($PLATFORM, $template, $ELFFILE, $MAUI_BIN);
        my $bbreg = &Gen_bb_reg_content(\%REG_BASE_DEFS);
        $template =~ s/\[CMMAUTOGEN_BBREG\]/$bbreg/g;
        open (OUTPUT_FILE, ">$BuildInfoCMM") or &error_handler("Unable to open $BuildInfoCMM!\n", __FILE__, __LINE__);
        print OUTPUT_FILE $template;
        close OUTPUT_FILE;
        print "Generate $BuildInfoCMM from ./pcore/tools/DebuggingSuite/Misc/BuildInfoTemplate.cmm\n";        
    }
}

#****************************************************************************
# 4 >>> Generate MAUI HQ_Only.cmm
#****************************************************************************
if ($ACTION == 1)
{
    my $hq_only_template;
    
    ### Parse LIS file first (do not parse LIS file outside to prevent unnecessary errors when LIS does not exist)
    &LISInfo::Parse($LISFILE);
    
    ### Read Template.cmm
    my $Template_cmm_file = "./common/tools/DebuggingSuite/Misc/Template.cmm";
    open (TEMPLATE_CMM_FILE, "<$Template_cmm_file") or &error_handler("$Template_cmm_file: Unable to open $Template_cmm_file!\n", __FILE__, __LINE__);
    {
        local $/;
        my $template_cmm_content = <TEMPLATE_CMM_FILE>;
        $hq_only_template .= &gen_hq_only_cmm_from_template_cmm($template_cmm_content);
    }
    close TEMPLATE_CMM_FILE;
    
    ### Write HQ_Only.cmm
    open (CMM_FILE, ">$CMMFILE") or &error_handler("$CMMFILE: Unable to open $CMMFILE!\n", __FILE__, __LINE__);
    print CMM_FILE $hq_only_template;
    close CMM_FILE;
    
    # [note]must be running gen_dump_address_size_template() 
    #       after generating hqonly.cmm for ClassifyRegionType()
    ### Generate OnTargetMemoryDump.cmm
    {
        my $DumpCMM = "$CMMDIR/L1CoreOnTargetMemoryDump.cmm";
        if(-e $DumpCMM)
        {
            my $template = &CommonUtil::GetFileContent($DumpCMM);
            my $regions = &gen_dump_address_size_template($PLATFORM);
            $template =~ s/\[CMMAUTOGEN_DUMP_L1CORE_REGIONS\]/$regions/g;
            open (OUTPUT_FILE, ">$DumpCMM") or &error_handler("Unable to open $DumpCMM!\n", __FILE__, __LINE__);
            print OUTPUT_FILE $template;
            close OUTPUT_FILE;
            print "Generate $DumpCMM\n";
        }
    }
}

exit;


#****************************************************************************
# subroutine:  reg_base_define_to_struct
# input:       $strInputFileFolder : folder of input reg_base.h
#              $strInputFile:  reg_base.h
#              $strOutputFilePath: path of output file for definitions of reg_base
#****************************************************************************
sub reg_base_define_to_struct
{
    my ($strInputFileFolder, $strInputFile, $strOutputFilePath) = @_;

    open (INPUT_FILE, "<$strInputFileFolder/$strInputFile") or &error_handler("$strInputFileFolder/$strInputFile: Unable to open $strInputFile!\n", __FILE__, __LINE__);
    open (OUTPUT_FILE, ">$strOutputFilePath") or &error_handler("$strOutputFilePath: Unable to open $strOutputFilePath!\n", __FILE__, __LINE__);

    print OUTPUT_FILE "\#include \"$strInputFile\"\n\n";
    print OUTPUT_FILE "typedef struct dummy_reg\n{\n";
    while (<INPUT_FILE>)
    {
        my ($reg);

        if (/^#define\s+(\w+)\s+\(*\w+\)*/)
        {
            $reg = $1;
            print OUTPUT_FILE "\tint $reg\_decl = $reg;\n";
        }
    }
    print OUTPUT_FILE "}\n";

    close INPUT_FILE;
    close OUTPUT_FILE;
    
    return;
}

#****************************************************************************
# subroutine:  parse_reg_base
# input:       $strInputFilePath: pre-compiled reg_base.h
#              $hrefRegBase:      hash reference to reg_base
#****************************************************************************
sub parse_reg_base
{
    my ($strInputFilePath, $hrefRegBase) = @_;

    open (INPUT_FILE, "<$strInputFilePath") or &error_handler("$strInputFilePath: Unable to open $strInputFilePath!\n", __FILE__, __LINE__);

    while (<INPUT_FILE>)
    {
        if (/\s*int\s+(\w+)\_decl\s+\=\s+\((.*)\);/)
        {
            my $reg = uc($1);
            my $nDecl = eval($2);
            $hrefRegBase->{$reg} = CommonUtil::Dec2Hex($nDecl);
        }
    }

    close INPUT_FILE;
    
    return;
}

#****************************************************************************
# subroutine:  get_cpu_type
# input:       $bb: platform
# output:      CPU type string
#****************************************************************************
sub get_cpu_type
{
    my ($bb) = @_;
    
    ### Determine CPU type
    my $strCPUType;
    if (&sysUtil::is_arm7($bb))
    {
        $strCPUType = "ARM7EJS";
    }
    elsif (&sysUtil::is_arm9($bb))
    {
        $strCPUType = "ARM926EJ";
    }
    elsif (&sysUtil::is_arm11($bb))
    {
        $strCPUType = "ARM1176JZ";
    }
    elsif (&sysUtil::is_CR4($bb))
    {
        $strCPUType = "CortexR4";
    }
    else
    {
        &error_handler("$MAKEFILE: Unsupported platform $bb!\n", __FILE__, __LINE__);
    }
    
    return $strCPUType;
}

sub FindBBRelatedFile 
{
    my ($Folder, $bb, $FileExtension) = @_;
    opendir( my $DIR, $Folder) || &sysUtil::sysgen_die("Can't open $Folder!", __FILE__, __LINE__);
    my @Files = grep { /$bb/i and /$FileExtension/i} readdir( $DIR );
    closedir $DIR; 
    return \@Files;
}

sub Gen_Info_CMMContent #called by gen_info_cmm_from_template
{
    my ($org_bb, $template, $strELFPath, $strBinName) = @_;
    my $strBinPath = dirname($strELFPath)."/".$strBinName;
    
    $template =~ s/\[CMMAUTOGEN_ELFPath\]/$strELFPath/g;
    $template =~ s/\[CMMAUTOGEN_BINPath\]/$strBinPath/g;
    my $cmmgen_verno = &template_verno();
    $template =~ s/\[CMMAUTOGEN_VERNO\]/$cmmgen_verno/g;
    
    return $template;
}

sub Gen_bb_reg_content
{
    my ($reg_base_href) = @_;
    my $template;
    foreach my $key (keys %$reg_base_href)
    {
        my $value = $reg_base_href->{$key};
        $template .= "GLOBAL &$key\n&$key=($value)\n";
    }
    return $template;    
}

#****************************************************************************
# subroutine:  gen_hq_only_cmm_from_template_cmm
# input:       $strInputContent: one line from Template.cmm to be replaced into HQ_Only.cmm
# output:      replaced HQ_Only.cmm line
#****************************************************************************
sub gen_hq_only_cmm_from_template_cmm
{
    my ($strInputContent) = @_;

    my $strReplacedContent = $strInputContent;

    ### Replace [CMMGEN_VERNO] with template_verno
    my $cmmgen_verno = &template_verno();
    $strReplacedContent =~ s/\[CMMGEN_VERNO\]/$cmmgen_verno/g;
    
    ### Replace [ARM] with the correct CPU
    my $strCPUType = &get_cpu_type($PLATFORM);
    $strReplacedContent =~ s/\[ARM\]/$strCPUType/g;

    ### Replace [ELF] with ELF path
    $strReplacedContent =~ s/\[ELF\]/$ELFFILE/g;

    ### Replace [PATH] with .
    $strReplacedContent =~ s/\[PATH\]/..\/..\/..\/..\/../g;

    ### Replace [ELFPARA] with empty 
    $strReplacedContent =~ s/\[ELFPARA\]/\/ZeroSym/g;

    ### Replace [BIN_PATH] with T:
    $strReplacedContent =~ s/\[BIN_PATH\]/T:/g;

    ### Replace [DBGSUITE_PATH] with pcore\\tools\\DebuggingSuite
    $strReplacedContent =~ s/\[DBGSUITE_PATH\]/..\\..\\..\\..\\..\\common\\tools\\DebuggingSuite/g;

    ### Replace [DBG_BUTTON] with GPRS/UAS buttons
    my $DBG_BUTTON= <<"__TEMPLATE";
menu.reprogram &DBGSUITE_PATH\\Misc\\Assistant
__TEMPLATE
    $strReplacedContent =~ s/\[DBG_BUTTON\]/$DBG_BUTTON/g;
    
    ### before using all dump information, parse lis/sym first:
    &LISInfo::ClassifyRegionType(\%MAKEFILE_OPTIONS);
    
    ### Replace [DATA_COPY_TO_VM] with CODE region list
    my $strDATA_COPY_TO_VM = &gen_DATA_COPY_TO_VM();
    $strReplacedContent =~ s/\[DATA_COPY_TO_VM\]/$strDATA_COPY_TO_VM/g;

    ### Replace [ASSIGN_VERNO_INFO] with verno info assignment
    my $strASSIGN_VERNO_INFO = &get_version_from_elf_template();
    $strReplacedContent =~ s/\[ASSIGN_VERNO_INFO\]/$strASSIGN_VERNO_INFO/g;
    ### Replace [BINARY] with loading memory dump regions
    my $strBinary = &gen_dump_regions_template();
    $strReplacedContent =~ s/\[BINARY\]/$strBinary/g;
    
    ### Replace [CHECK_CODE]
    my $strSAVE_CHECK_CODE_CMD = &gen_SAVE_CHECK_CODE_CMD();
    $strReplacedContent =~ s/\[CHECK_CODE\]/$strSAVE_CHECK_CODE_CMD/g;
    
    print "strReplacedContent=$strReplacedContent" if ($DebugPrint == 1);
    return $strReplacedContent;
}
sub gen_DATA_COPY_TO_VM
{
    my $template;
    my $Region_aref = LISInfo::GetDumpCodeRegions(\%MAKEFILE_OPTIONS);
    foreach my $RegionName (@$Region_aref)
    {
        if($RegionName =~ /0x/)
        {#workaround for VECTOR_TABLE dump region
            $template .= "data.copy $RegionName--($RegionName+0x200) VM:$RegionName\n";
        }
        else
        {
            $template .= "data.copy Load\$\$$RegionName\$\$Base--(Load\$\$$RegionName\$\$Base+Image\$\$$RegionName\$\$Length) VM:Image\$\$$RegionName\$\$Base\n";
        }
    }
    return $template;
}

sub gen_SAVE_CHECK_CODE_CMD
{
    my $template;
    my $Region_aref = LISInfo::GetDumpCodeRegions(\%MAKEFILE_OPTIONS);
    my $i = 0;
    foreach my $RegionName (@$Region_aref)
    {
        $template .= '&command_count=&command_count+1'."\n" if($i!=0);
        my ($strBase, $strLength, $strHintName) = (undef, undef, "ROM_CODE");
        if($RegionName =~ /0x/)
        {#workaround for VECTOR_TABLE dump region
            ($strBase, $strLength) = ($RegionName, "0x200");
        }
        else
        {
            ($strBase, $strLength) = ("Image\$\$$RegionName\$\$Base", "Image\$\$$RegionName\$\$Length");
            $strHintName = "INT_CODE" if($RegionName =~/INTSRAM/i);
        }

        my $strDataSet = <<"__TEMPLATE";
DATA.SET VM:(&pool_addr+&command_size*&command_count) %LONG 0x1 ; op code
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x4) %LONG $strBase ; start address
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x8) %LONG $strLength ; length
DATA.SET VM:(&pool_addr+&command_size*&command_count+0xC) "$strHintName" 0x0 ; name
__TEMPLATE
        $template .= $strDataSet;
        $i++;
    }
    
    if(FileInfo::isnot("SW_BINDING_SUPPORT", "NONE"))
    {
        my $strDataSet = <<"__TEMPLATE";
&command_count=&command_count+1
; bypass INT_IntializeSystemMemory in ROM_CODE
DATA.SET VM:(&pool_addr+&command_size*&command_count) %LONG 0xFFFFFFFF ; op code
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x4) %LONG INT_IntializeSystemMemory ; start address
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x8) %LONG Y.SIZEOF(INT_IntializeSystemMemory) ; length
DATA.SET VM:(&pool_addr+&command_size*&command_count+0xC) "BYPASS" 0x0 ; name
__TEMPLATE
        $template .= $strDataSet;
    }
    
    if(FileInfo::is("BOOT_CERT_SUPPORT", "BOOT_CERT_V2"))
    {
        my $strDataSet = <<"__TEMPLATE";
&command_count=&command_count+1
; bypass g_SRD_INFO in ROM_CODE
DATA.SET VM:(&pool_addr+&command_size*&command_count) %LONG 0xFFFFFFFF ; op code
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x4) %LONG g_SRD_INFO ; start address
DATA.SET VM:(&pool_addr+&command_size*&command_count+0x8) %LONG Y.SIZEOF(g_SRD_INFO) ; length
DATA.SET VM:(&pool_addr+&command_size*&command_count+0xC) "BYPASS" 0x0 ; name
__TEMPLATE
        $template .= $strDataSet;
    }
    return $template;
}

sub get_version_from_elf_template
{
    my $template;
    my $strRegionName = "PRIMARY_CACHED_EXTSRAM";
    if(!&LISInfo::IsRegionExistent($strRegionName) and &LISInfo::IsRegionExistent("CACHED_EXTSRAM"))
    {
        $strRegionName = "CACHED_EXTSRAM";
    }
    elsif(!&LISInfo::IsRegionExistent("CACHED_EXTSRAM") and &LISInfo::IsRegionExistent("EXTSRAM"))
    {
        $strRegionName = "EXTSRAM";
    }
    elsif(!&LISInfo::IsRegionExistent("EXTSRAM") and &LISInfo::IsRegionExistent("INTSRAM_DATA"))
    {
        $strRegionName = "INTSRAM_DATA";
    }
    else
    {
        &error_handler("Can't judge verno in which section", __FILE__, __LINE__);            
    }
    
    $template = <<"__TEMPLATE";
&ELF_VERNO_ADDR=V.VALUE((int)&RELEASE_VERNO_RW\$\$Base - (int)&Image\$\$$strRegionName\$\$Base + (int)&Load\$\$$strRegionName\$\$Base)
&ELF_BRANCH_ADDR=V.VALUE((int)&RELEASE_BRANCH_RW\$\$Base - (int)&Image\$\$$strRegionName\$\$Base + (int)&Load\$\$$strRegionName\$\$Base)
&ELF_BTIME_ADDR=V.VALUE((int)&BUILD_TIME_RW\$\$Base - (int)&Image\$\$$strRegionName\$\$Base + (int)&Load\$\$$strRegionName\$\$Base)
__TEMPLATE
    return $template;
}

sub gen_dump_regions_template
{
    my $template;
    my $DumpRegions_ref = &LISInfo::GetDumpExeRegions(\%MAKEFILE_OPTIONS);
    my $BIN_PATH = $BUILDDIR ."\\". $MAUI_BIN;
    print "-----------------DUMP Regions-----------------\n";
    foreach my $strGroupName (keys %$DumpRegions_ref)
    {
        my $array_ref = $DumpRegions_ref->{$strGroupName};
        foreach my $RegionItem (@$array_ref)
        {
            my $RegionName = $RegionItem->[0];
            my $strBase = &LISInfo::GetDumpRegionBase($strGroupName, $RegionName, $BIN_PATH, $PLATFORM);
            print "[$strGroupName]$RegionName: $strBase\n";
            $template .= "D.LOAD.BINARY &BIN_PATH\\slave_sys_mem_$strBase.bin $strBase /byte /nosymbol\n";
        }
    }
    print "----------------------------------------------\n";
    return $template;
}

sub gen_dump_address_size_template
{  
    my ($bb) = @_;
    my $template;
        print "------------On Target Dump Region Info--------------\n";
        my $DumpRegion_aref = LISInfo::GetCMMDumpRegionInfo($bb);
        foreach my $item (@$DumpRegion_aref)
        {
            my $strBase = $item->[1];
            my $strEnd = CommonUtil::Dec2Hex(hex($item->[1])+hex($item->[2])-0x1);
            print $item->[0].":".$item->[1].",".$item->[2].", $strEnd\n";
            $template .= "print \"L1CORE::Dumping [$item->[0]]slave_sys_mem_$strBase.bin\"\n"; 
            $template .= "DATA.SAVE.BINARY \"\&store_folder\\slave_sys_mem_$strBase.bin\" $strBase--$strEnd\n";
        } 
    print "----------------------------------------------\n";
        
    return $template;    
}

#****************************************************************************
# subroutine:  template_copyright_file_header
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# output:      template of copyright file header
#****************************************************************************
sub template_copyright_file_header
{
    my $template = <<"__TEMPLATE";
; Copyright Statement:
; --------------------
; This software is protected by Copyright and the information contained
; herein is confidential. The software may not be copied and the information
; contained herein may not be used or disclosed except with the written
; permission of MediaTek Inc. (C) 2005
; 
; BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
; THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
; RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
; AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
; EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
; MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
; NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
; SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
; SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
; THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
; NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
; SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
; 
; BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
; LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
; AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
; OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
; MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
; 
; THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
; WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
; LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
; RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
; THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_verno
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# output:      template of verno and author information
#****************************************************************************
sub template_verno
{
    my $template = <<"__TEMPLATE";
; CMMAutoGen$CMMGEN_VERNO by $CMMGEN_AUTHOR

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_cpu_info_command
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       $bb: platform
# output:      template of CPU-related information and commands
#****************************************************************************
sub template_cpu_info_command
{
    my ($bb) = @_;
    
    ### Determine CPU type
    my $strCPUType = &get_cpu_type($bb);
    
    my $template = "; CPU_info_command\n";
    if (&sysUtil::is_arm11($bb))
    {
        $template .= <<"__TEMPLATE_ARM11";
SYStem.RESet
SYStem.CPU $strCPUType
SYStem.JtagClock Rtck
System.Option Cflush on     ;flush the cache to avoid data consistency
System.Option ResBreak off  ;Dont hold the ARM11 core after reset
SYStem.Up
R.S PC 0x00000000

setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_ARM11
    }
    elsif($bb eq "MT6290")
    {
        $template .= <<"__TEMPLATE_CR4";
SYStem.RESet
SYStem.CPU $strCPUType
System.Option Cflush on                    ; flush the cache to avoid data consistency
SYStem.JtagClock 1MHz                     ; For DAP-lite Jtag connection
System.Multicore SWDP on
SYStem.MultiCore COREBASE APB:0x80210000    ; For CoreSight
SYStem.MultiCore DEBUGACCESSPORT 1         ; Specify which port of DAP is used for access ARM Debug Registers (0~255)
SYStem.MultiCore MEMORYACCESSPORT 0        ; Specify which port of DAP is used for access Memory (0~255)
System.Option ResBreak off                 ; Turn off ResBreak option to avoid connect to target before it is ready
System.Option EnReset off
SYSTEM.OPTION WaitReset off
SYStem.Up

setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_CR4
    }
    elsif (&sysUtil::is_CR4($bb))
    {
        my %COREBASE_tbl = 
        (
            "MT6290" => "0x80210000",
        );
        my $COREBASE = $COREBASE_tbl{$bb};
        $template .= <<"__TEMPLATE_CR4";
SYStem.RESet
SYStem.CPU $strCPUType
System.Option Cflush on                    ; flush the cache to avoid data consistency
SYStem.JtagClock 10MHz                     ; For DAP-lite Jtag connection
System.Multicore SWDP on
SYStem.MultiCore COREBASE APB:$COREBASE    ; For CoreSight
SYStem.MultiCore DEBUGACCESSPORT 1         ; Specify which port of DAP is used for access ARM Debug Registers (0~255)
SYStem.MultiCore MEMORYACCESSPORT 0        ; Specify which port of DAP is used for access Memory (0~255)
System.Option ResBreak off                 ; Turn off ResBreak option to avoid connect to target before it is ready
System.Option EnReset on
SYStem.Up

setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_CR4
    }
    else
    {
        $template .= <<"__TEMPLATE_OTHER";
SYStem.RESet
SYStem.CPU $strCPUType
SYStem.JtagClock RTCK.
sys.o cflush on
SYStem.Up
setup.IMASKHLL ON
setup.IMASKASM ON

__TEMPLATE_OTHER
    }

    return $template;
}
#****************************************************************************
# subroutine:  template_specify_load_elf
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       
# output:      template of loading ELF
#****************************************************************************
sub template_specify_load_elf
{
    my $template = <<"__TEMPLATE";
; specify_load_elf
D.LOAD.ELF $ELFFILE \/RELPATH \/PATH "..\/..\/..\/.." \/nocode
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  template_add_utility_for_debug
#              (this template will be used by MAUI nocode.cmm)
# input:
# output:      template of debugging utilities
#****************************************************************************
sub template_add_utility_for_debug
{
    my $template = <<"__TEMPLATE";
; add_utility_for_debugging
menu.reset
GLOBAL &DBGSUITE_PATH
&DBGSUITE_PATH=\"..\\..\\..\\..\\pcore\\tools\\DebuggingSuite\"

if version.build()==0x100000 
(
    task.config &DBGSUITE_PATH\\Misc\\NUCLEUS
)
else
(
    if y.exist(TCT_Schedule)
    (
        task.config &DBGSUITE_PATH\\Misc\\NUCLEUS
        menu.reprogram &DBGSUITE_PATH\\Misc\\NUCLEUS
    )
    else
    (
        task.config &DBGSUITE_PATH\\Misc\\NUCLEUS_V2
        menu.reprogram &DBGSUITE_PATH\\Misc\\NUCLEUS_V2
    )
)

__TEMPLATE

    return $template;
}


#****************************************************************************
# subroutine:  template_clean_win_and_endup
#              (this template will be used by MAUI nocode.cmm, BL nocode.cmm, EXT_BL nocode.cmm, and FOTA nocode.cmm)
# input:       $bWinClear = 1: gen winclear, 0 or undef: not to generate winclear
# output:      template of clean win and endup
#****************************************************************************
sub template_clean_win_and_endup
{
    my ($bWinClear) = @_;
    my $winclear = undef;
    if($bWinClear == 1){
    $winclear = <<"__TEMPLATE";
; clean_win
winclear
__TEMPLATE
    }
    my $template = <<"__TEMPLATE";
$winclear
; endup
d.l
enddo

__TEMPLATE

    return $template;
}


#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($strErrorMsg, $strFile, $strLine) = @_;
    
    my $strFinalErrorMsg = "CMMGEN ERROR: $strErrorMsg at $strFile line $strLine\n";
    print $strFinalErrorMsg;
    die $strFinalErrorMsg;
}
