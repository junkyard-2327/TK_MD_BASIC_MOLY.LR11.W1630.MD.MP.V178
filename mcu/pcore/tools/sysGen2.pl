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
#*   sysGen2.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parse scatter file and 
#*       1. force generate custom_scatstruct.h if update required
#*       2. force generate custom_scatstruct.c if update required
#*       3. force generate custom_blconfig.c if update required
#*
#* Author:
#* -------
#*   Qmei Yang  (mtk03726)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, "pcore/" , './pcore/tools/' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use scatInfo;
use CommonUtility;
use FileInfoParser;
use config_MemSegment;
use tools::pack_dep_gen;
PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $SYSGEN2_VERNO    = " u0.20_LR11";
                        #  u0.20_LR11,     2015/12/17,  Tero,   Added SWLA max size calculation
                        #  u0.18_LR11,     2015/11/02,  Carl,   Change DSP TX/RX sections to ZI (.bss) section
                        #  u0.17_LR11,     2015/09/17,  Carl,   Move dsp bin from l1core rom to l1core ram, change the 1st EMI RMPU channel base to Image$$L1CORE_DSP$$:imit
                        #  u0.16_UMOLY,  2015/07/15,  Carl,   Suppoet runtime (not exception time) dump memory
                        #  u0.15_UMOLY,  2015/06/26,  Carl,   Adjust custom_get_INTSRAMDATA_End for DSM
                        #  u0.14_UMOLY   2015/05/11,  Carl,   Support Ramdisk for TK6291
                        #  u0.13_UMOLY   2015/04/15,  Carl,   Refine setting for (MCU RO, MDHW RW)  DNC+NC, (MCU RW, MDHW RW)  DNC+NC
                        #  u0.12_UMOLY,  2015/04/07,  Carl,   Use GetExeRegionsInROMByLoadRegion in custom_get_1st_ROM_ROMBase()
                        #  u0.11_UMOLY,  2015/01/20,  Carl,   Remove bootloader and legacy security code from UMOLY
                        #  u0.10_UMOLY,  2014/11/02,  Carl,   support custom_scatStruct.c to get L1CORE_LV info
                        #  u0.09_UMOLY,  2014/10/20,  Carl,   call L1coreCommonUtil function 
                        #  u0.08_UMOLY,  2014/08/26,  Carl,   Refine L1core memory dump
                        #  u0.07_UMOLY,  2014/07/31,  Carl,   Remove unused library path
                        #  u0.06_UMOLY,  2014/06/27,  Carl,   Refine the base and end address of SWLA
                        #  u0.05_UMOLY,  2014/04/07,  Carl,   Rename "l1dsp" to "l1core", "L1DSP" to "L1CORE"
                        #  u0.04_UMOLY,  2014/04/02,  Carl,   pcore sysGen2
                        #  u0.03_UMOLY,  2014/04/02,  Carl,   1) pcore sysGen2. 2) Remove useless secure region query API
                        #  u0.02_UMOLY,  2014/03/03,  Carl,   initial version, fix build fail
                        #  u0.01_UMOLY,  2014/02/20,  BM,     porting to MT291_DEV

#****************************************************************************
# Global Variable
#****************************************************************************
my $g_bb;
my $g_MAUILinkInfo = undef;
my $g_BLLinkerInfo = undef;
my %g_GroupedRegions; # Key => [content count, contents] #for saving time
my $g_DumpRegions_href = undef;  # Key => [[], [], []]
my $g_DumpRegionOrder_aref = undef; # [GroupName, GroupName,...]
my $g_L1DSPDumpRegions_href = undef;  # Key => [[], [], []]
my $g_L1DSPDumpRegionOrder_aref = undef; # [GroupName, GroupName,...]
my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

# File Name
my $CUSTOM_SCATSTRUCT_C;
my $CUSTOM_SCATSTRUCT_H;
my $CUSTOM_DEMP_H;
my $CUSTOM_FEATURE_CFG_H;
my $CUSTOM_MEM_DEV_H ;
my $CUSTOM_IMG_CONFIG_H ;
my $CUSTOM_FLASH_H;
my $CUSTOM_EMI_OFFSET_H;
my $SCATTERFILE;
my $BL_SCATTERFILE;
my $EXT_BL_SCATTERFILE;

1;
#****************************************************************************
# Subroutine: GetOBJCOPYInput - API for objcopy input on Build Flow of GCC
# Purpose: To provide command for objcopy
# Input : $LDS_FILEPATH
# Output : undef or a hash reference contains LoadRegionName => Corresponding command line
#                   e.g. "ROM" => "-R BOOT_CERT -R SECURE_RO -R SECURE_RO_GFH "
#                        "BOOT_CERT" => "-j BOOT_CERT "
#                        "SECURE_RO" => "-j SECURE_RO -j SECURE_RO_GFH "
# [!!!Caution!!!] if there is only one LoadRegion in RegionMap, it should return undef.
#****************************************************************************
sub GetOBJCOPYInput
{
    my ($LDS_FILEPATH) = @_;
    my %OBJCopyInput;
    my $LinkInfo = lds_new scatInfo($LDS_FILEPATH, "ROM");
    my $RegionMap_href = $LinkInfo->GetRegionMap();
    my $LRSize = scalar keys %$RegionMap_href;
    if($LRSize > 1)
    {
        my $strROMER;
        foreach my $strLRName (keys %$RegionMap_href)
        {
            my $LR = $RegionMap_href->{$strLRName};
            if($strLRName !~ /rom/i)
            {
                map{ $strROMER .= "-R $_ ";}@$LR;
                my $strER;
                map {$strER .= "-j $_ ";}@$LR;
                $OBJCopyInput{$strLRName} = $strER;
            }
        }
        $OBJCopyInput{ROM} = $strROMER;
#print "[OBJCopyInput]\n";
#foreach my $item (keys %OBJCopyInput)
#{
#    print "$item: ".  $OBJCopyInput{$item}. "\n";
#}
        return \%OBJCopyInput;
    }
    else
    {
        return undef;
    }
}
#****************************************************************************
# subroutine:  sysgen2_main 
#              to be called by scatGen.pl
# Input:       4 paths: $BB_PATH, $IMAGELAYOUT, $BL_IMAGELAYOUT, $EXT_BL_IMAGELAYOUT
# Output:      x
#****************************************************************************
sub sysgen2_main
{
    my ($BB_PATH, $IMAGELAYOUT, $BL_IMAGELAYOUT, $EXT_BL_IMAGELAYOUT) = @_;
    #****************************************************************************
    # >>>  Setting
    #****************************************************************************    
    $CUSTOM_SCATSTRUCT_C   = $BB_PATH . '/' . "custom_scatstruct.c";            
    $CUSTOM_SCATSTRUCT_H   = $BB_PATH . '/' . "custom_scatstruct.h";            
    $CUSTOM_DEMP_H         = $BB_PATH . '/' . "custom_demp.h";                  
    $CUSTOM_FEATURE_CFG_H  = $BB_PATH . '/' . "custom_FeatureConfig.h";         
    $CUSTOM_MEM_DEV_H      = $BB_PATH . '/' . "custom_MemoryDevice.h";          
    $CUSTOM_IMG_CONFIG_H   = $BB_PATH . '/' . "custom_img_config.h";            
    $CUSTOM_FLASH_H        = $BB_PATH . '/' . "custom_flash.h";                      
    $CUSTOM_EMI_OFFSET_H   = $BB_PATH . '/' . "custom_emi_offset.h"; 
    $SCATTERFILE           = $IMAGELAYOUT;                                          
    $BL_SCATTERFILE        = $BL_IMAGELAYOUT;                                          
    $EXT_BL_SCATTERFILE = $EXT_BL_IMAGELAYOUT;                                      
    $g_bb = &sysUtil::SwitchToClonedChip(&FileInfo::GetChip());
    #****************************************************************************
    # >>>  Generate files
    #****************************************************************************
    &GCC_Process() if(&FileInfo::GetCompiler() eq "GCC");
}

#****************************************************************************
# subroutine:  GCC_Process
# Input:       x
# Output:      x
#****************************************************************************
sub GCC_Process
{
    # >>>  Parse Scatter File
    $g_MAUILinkInfo = lds_new scatInfo($SCATTERFILE, "ROM");
    $g_MAUILinkInfo->ClassifyRegionType( &FileInfo::GetMakeFileRef() );
    ($g_DumpRegions_href, $g_DumpRegionOrder_aref) = $g_MAUILinkInfo->GetDumpExeRegions($g_bb);
#    if(FileInfo::is("MD_OFFLOAD_COPRO", "MP300"))
    {
        ($g_L1DSPDumpRegions_href, $g_L1DSPDumpRegionOrder_aref)  = $g_MAUILinkInfo->GetL1COREDumpExeRegions($g_bb);
    }
    if(-e $EXT_BL_SCATTERFILE)
    {
        $g_BLLinkerInfo = lds_new scatInfo($EXT_BL_SCATTERFILE, "EXT_BOOTLOADER");
    }
    &Generate_Process();
}

sub Generate_Process
{
    # >>>  Generate files
    &GenerateFile($CUSTOM_SCATSTRUCT_C, \&SCAT_C_Preprocess);
    &GenerateFile($CUSTOM_SCATSTRUCT_H, undef);
    &GenerateFile($CUSTOM_IMG_CONFIG_H, undef);
    &GenerateFile($CUSTOM_EMI_OFFSET_H, undef);
}
#****************************************************************************
# subroutine:  GenerateFile
# Input:       $strFilePath = the file to be generated if it exists without check-in history.
#              $PreprocessFunc_ref = to preprocess if there is any condition 
#                                    which needs to be tested before generating
# Output:      x
#****************************************************************************
sub GenerateFile
{
    my ($strFilePath, $PreprocessFunc_ref) = @_;
    if(&isToGen($strFilePath))
    {
        &$PreprocessFunc_ref() if(defined $PreprocessFunc_ref);
        my $content = &ProcessTemplate($strFilePath);
        &WriteFile($strFilePath, $content);
    }
}
#****************************************************************************
# subroutine:  isToGen
# Input:       $strFilePath = the file to be generated if it exists without check-in history.
# Output:      $bToGen: undef = not to generate file, 1=need to generate file 
#****************************************************************************
sub isToGen
{
    my ($strFilePath) = @_;
    my $bToGen = undef;
    if(-e $strFilePath)
    {
        $bToGen = 1 if(1 != &sysUtil::HasCheckinHistory($strFilePath));
    }
    else
    {
        &sysUtil::sysgen_die("$strFilePath: the template must exist!", __FILE__, __LINE__);   
    }
    return $bToGen;
}
#****************************************************************************
# subroutine:  ProcessTemplate
# Input:       $strFilePath: the file to be processed
# Output:      $content: the content after processing
# Description: if there is the pattern as [AUTOGEN_funcname], 
#              the whole pattern will be replaced by calling funcname().
#              if funcname() doesn't exist, it'll fail and report error.
#****************************************************************************
sub ProcessTemplate
{
    my ($strFilePath) = @_;
    my $content;
    open (FILE_HANDLE, $strFilePath) or &sysUtil::sysgen_die("Cannot open $strFilePath\n", __FILE__, __LINE__);
    while(<FILE_HANDLE>)
    {
        my $strLine = $_;
        while ($strLine =~ /\[AUTOGEN_(\w+)\]/)
        {
            my $func = $1;
            my $template;
            {
                no strict 'refs';
                $template = &{$func}() if(exists &{$func}) 
                    or &sysUtil::sysgen_die("$func() doesn't exist!\n", __FILE__, __LINE__);
            }
            $strLine =~ s/\[AUTOGEN_$func\]/$template/g;
        }
        $content .= $strLine;
    }
    close FILE_HANDLE;
    return $content;
}
#****************************************************************************
# subroutine:  WriteFile
# Input:       $strFilePath: the file to be generated
#              $content: the content to be written into $strFilePath
# Output:      x
#****************************************************************************
sub WriteFile
{
    my ($strFilePath, $content) = @_;
    open (FILE, ">$strFilePath") or &sysUtil::sysgen_die("Cannot open $strFilePath\n", __FILE__, __LINE__);
    print FILE $content;
    close FILE;
}
#-----------------------------------------------------------------------------
# Preprocess fucntions:
#-----------------------------------------------------------------------------
sub SCAT_C_Preprocess
{
    # Report error if there is another region ahead of SINGLE_BANK_CODE (between SINGLE_BANK_CODE and vector table)
    # Because MPU channel will be wrapped from vector table (0x0) to the end of SINGLE_BANK_CODE to reduce the number of channels
    my $strRegionName = $g_MAUILinkInfo->SearchExeRegionName("SINGLE_BANK_CODE");
    if(defined $strRegionName)
    {
        my $array_ref = $g_MAUILinkInfo->GetExeRegionsByLoadRegion("ROM");
        my $SINGLE_BANK_CODE_Base = $g_MAUILinkInfo->GetRegionInfo($strRegionName, Region::Base);
        foreach (@$array_ref)
        {
            next if(/SINGLE_BANK_CODE/);
            my $Info = $g_MAUILinkInfo->GetExeRegionInfo($_);
            if(defined $Info->[Region::Base])
            {
                if ((hex($Info->[Region::Base])) <= (hex($SINGLE_BANK_CODE_Base)) 
                and ((hex($Info->[Region::Base]) >= (0xFF000000 & hex($SINGLE_BANK_CODE_Base))) ))
                {
                    &sysUtil::sysgen_die("$SCATTERFILE: No region($_) can exist between vector table and SINGLE_BANK_CODE for MPU configuration!", __FILE__, __LINE__);
                }
            }
        }
    }
}
#-----------------------------------------------------------------------------
# Gen fucntions:
#-----------------------------------------------------------------------------
sub DieIfEmpty
{
    my ($Input, $strInputDescription) = @_;
    my ($pack_name, $file, $line_no) = caller;
    &sysUtil::sysgen_die("Please check $strInputDescription($Input) which can't be empty ", $file, $line_no) 
        if(!defined $Input or $Input eq "");
}
sub GenVersion
{
    return "system auto generator". $SYSGEN2_VERNO. " + sysGenUtility" . &sysUtil::sysgenUtility_verno();
}

sub DEMP_H_Gen_MBA_LIST
{
    my $template;
    my $MBA_href = &GetGroupedRegions("MBA");
    foreach(@$MBA_href)
    {
        my $temp = uc($_->[0]); 
        $temp =~ s/_ROM//;
        $template .= "    DEMP_$temp,\n";
    }
    return $template;
}
sub DEMP_H_Gen_DEMP_MAIN_BINSIZE
{
    my $nMaxSize = 0;
    if($g_MAUILinkInfo->IsRegionExistent("DEMAND_PAGING_ROM0"))
    {
        my $Info = $g_MAUILinkInfo->GetLoadRegionInfo("DEMAND_PAGING_ROM0");
        $nMaxSize = hex($Info->[Region::MaxSize])/ (1024*1024);
    }
    return $nMaxSize;
}
sub DEMP_H_Gen_MBA_BINSIZE_LIST
{
    my $template;
    my $MBA_href = &GetGroupedRegions("MBA");
    foreach(@$MBA_href)
    {
        my $temp = uc($_->[0]); 
        $temp =~ s/_ROM//;
        my $Info = $g_MAUILinkInfo->GetLoadRegionInfo($_->[0]);
        my $nMaxSize = hex($Info->[Region::MaxSize])/ (1024*1024);
        $template .= "#define DEMP_$temp\_SIZE $nMaxSize\n";
    }
    return $template;
}
sub DEMP_H_Gen_DEMP_MBA_BINSIZE
{
    my $template;
    my $MBA_href = &GetGroupedRegions("MBA");
    foreach(@$MBA_href)
    {
        my $temp = uc($_->[0]); 
        $temp =~ s/_ROM//;
        $template .= " + DEMP_$temp\_SIZE";
    }
    return $template;
}


sub SCAT_H_Gen_DUMP_REGION_COUNT
{
    my $nCount = 0;
    if(!defined $g_DumpRegions_href or !defined $g_DumpRegionOrder_aref)
    {
        ($g_DumpRegions_href, $g_DumpRegionOrder_aref) = $g_MAUILinkInfo->GetDumpExeRegions($g_bb);
    }
    foreach my $strGroupName (keys %$g_DumpRegions_href)
    {
        my $array_ref = $g_DumpRegions_href->{$strGroupName};
        $nCount += ($#$array_ref +1);
    }
    return $nCount;
}
sub SCAT_H_Gen_L1CORE_DUMP_REGION_COUNT
{
    my $nCount = 0;
#    if(FileInfo::is("MD_OFFLOAD_COPRO", "MP300"))
    {
        if(!defined $g_L1DSPDumpRegions_href or !defined $g_L1DSPDumpRegionOrder_aref)
        {
            ($g_L1DSPDumpRegions_href, $g_L1DSPDumpRegionOrder_aref) = $g_MAUILinkInfo->GetL1COREDumpExeRegions($g_bb);
        }
        foreach my $strGroupName (keys %$g_L1DSPDumpRegions_href)
        {
            my $array_ref = $g_L1DSPDumpRegions_href->{$strGroupName};
            $nCount += ($#$array_ref +1);
        }
    }
    return $nCount;
}

sub SCAT_C_Gen_TEMPLATE_FirstRODumpRegionBase
{
    if(!defined $g_DumpRegions_href or !defined $g_DumpRegionOrder_aref)
    {
        ($g_DumpRegions_href, $g_DumpRegionOrder_aref) = $g_MAUILinkInfo->GetDumpExeRegions($g_bb);
    }
    my $DumpRegions_ref = &Get_Dump_Regions($g_DumpRegions_href, $g_DumpRegionOrder_aref);
    my $template = &Get_FirstROM_Dump_Region_Base_String($DumpRegions_ref);
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_DUMP_REGION_ASSIGN
{
    my $template;
    if(!defined $g_DumpRegions_href or !defined $g_DumpRegionOrder_aref)
    {
        ($g_DumpRegions_href, $g_DumpRegionOrder_aref) = $g_MAUILinkInfo->GetDumpExeRegions($g_bb);
    }
    my $DumpRegions_ref = &Get_Dump_Regions($g_DumpRegions_href, $g_DumpRegionOrder_aref);
    $template = DumpAssign($DumpRegions_ref);
    return $template;
}

sub SCAT_C_Gen_TEMPLATE_L1CORE_DUMP_REGION_ASSIGN
{
    my $template;
#    if(FileInfo::is("MD_OFFLOAD_COPRO", "MP300"))
    {
        if(!defined $g_L1DSPDumpRegions_href or !defined $g_L1DSPDumpRegionOrder_aref)
        {
            ($g_L1DSPDumpRegions_href, $g_L1DSPDumpRegionOrder_aref) = $g_MAUILinkInfo->GetL1COREDumpExeRegions($g_bb);
        }
        my $DumpRegions_ref = &Get_Dump_Regions($g_L1DSPDumpRegions_href, $g_L1DSPDumpRegionOrder_aref);
        $template = DumpAssign($DumpRegions_ref);
    }
    return $template;
}

sub SCAT_C_Gen_TEMPLATE_CACHEABLE_PREFIX
{
    return &CommonUtil::Dec2Hex(sysUtil::GetCacheablePrefix($g_bb)); 
}

sub DumpAssign
{
    my ($DumpRegions_ref) = @_;
    my $template = "    extern kal_bool INT_IsAnyCore_Enter_Exception(void);\n\n";
    for(my $i = 0; $i < $#$DumpRegions_ref+1; $i++)
    {
        my $GroupName = $DumpRegions_ref->[$i]->[0];
        $template .= "    region[$i].addr = ".$DumpRegions_ref->[$i]->[1].";\n";
        $template .= "    region[$i].len = ".$DumpRegions_ref->[$i]->[2].";\n";

        if($GroupName =~ /VECTOR_TABLE/i)
        {
            $template .= "    if( FirstRODumpRegionBase == 0x0)\n        region[$i].addr += 4;\n";
        }
        elsif ($GroupName =~ /INTSRAM/i)
        {
            $template .= "    if (!INT_IsAnyCore_Enter_Exception())\n";
            $template .= "        region[$i].len = (custom_get_INTSRAMDATA_End() -custom_get_INTSRAMCODE_Base());\n";
            #$template .= "        region[$i].len = (".&GetGroupBase("INTSRAM")." - ".&GetGroupEnd("INTSRAM").";\n";
        }
        
        $template .= "    region[$i].addr = MAP2CREGPA(region[$i].addr);\n" if($GroupName =~ /DYNAMIC_DC_PA|CACHED_RW_PA/i);
        $template .= "    region[$i].addr = MAP2CREGVA(region[$i].addr);\n" if($GroupName =~ /DYNAMIC_DNC_.*VA/i);
        $template .= "    region[$i].addr |= ".&CommonUtil::Dec2Hex(sysUtil::GetCacheablePrefix($g_bb)).";\n" if($GroupName =~ /L1CORE_DUMP_REGION__.*_VA/i);
        $template .= "    region[$i].addr &= ~(".&CommonUtil::Dec2Hex(sysUtil::GetCacheablePrefix($g_bb)).");\n" if($GroupName =~ /L1CORE_DUMP_REGION__.*_PA/i);
    }
    return $template;    
}
sub Get_FirstROM_Dump_Region_Base_String
{
    my ($DumpRegions_aref)= @_; #[[GroupName, Base, Length]...]
    my $strBase = "0xFFFFFFFF";
    for(my $i = 0; $i < $#$DumpRegions_aref+1; $i++)
    {
        my $GroupName = $DumpRegions_aref->[$i]->[0];
        if($GroupName ne "ROM")
        {
            next;
        }
        else
        {
            $strBase = $DumpRegions_aref->[$i]->[1];
            last;
        }
    }
    return $strBase;
}

sub Get_Dump_Regions
{
    my ($DumpRegion_href, $DumpRegionOrder_aref) = @_;
    my @DumpRegions;
    my $nIndex = 0;
    foreach my $strGroupName (@$DumpRegionOrder_aref)
    {
        my $array_ref = $DumpRegion_href->{$strGroupName};
        foreach my $RegionItem (@$array_ref)
        {
            my $RegionName = $RegionItem->[0];
            my $Info = $g_MAUILinkInfo->GetExeRegionInfo($RegionName);
            if($RegionName eq "DUMP_VECTOR_TABLE")
            {
                #print "[$strGroupName]$RegionName: ".$Info->[Region::Base].", ".$Info->[Region::MaxSize]."\n";
                push(@DumpRegions, [$strGroupName, $Info->[Region::Base], $Info->[Region::MaxSize]]); 
                $nIndex++; next;
            }
            if($g_MAUILinkInfo->IsFixedLengthDumpGroup($strGroupName))
            {
                #print "[$strGroupName]$RegionName: (kal_uint32)&Image\$\$$RegionName\$\$Base, ".$Info->[Region::MaxSize]."\n";
                push(@DumpRegions, [$strGroupName, "(kal_uint32)&Image\$\$$RegionName\$\$Base", $Info->[Region::MaxSize]]); 
                $nIndex++; next;
            }
            else
            {
                my $LastRegionName =  $RegionItem->[ scalar(@$RegionItem)-1 ];
                my $strLength = undef;
                if(scalar(@$RegionItem) == 1)
                {
                    my ($bIsFixed, $strFixedLength) = $g_MAUILinkInfo->IsFixedLengthRegion($RegionName);
                    $strLength = $strFixedLength if ($bIsFixed == 1);
                }
                if(!defined $strLength)
                {
                    $strLength = "(kal_uint32)&Image\$\$$LastRegionName\$\$ZI\$\$Limit - region\[$nIndex].addr";
                }
                print "[$strGroupName]$RegionName: (kal_uint32)&Image\$\$$RegionName\$\$Base, $strLength\n" if($DebugPrint);
                push(@DumpRegions, [$strGroupName, "(kal_uint32)&Image\$\$$RegionName\$\$Base", $strLength]); 
                $nIndex++; next;
            }
        }
    }
    return \@DumpRegions; #[[GroupName, Base, Length]...]
}

sub SCAT_C_Gen_REGION_SYMBOL
{
    my $template;
    my $ExeRegion_ref = $g_MAUILinkInfo->GetAllExeRegion();
    foreach (@$ExeRegion_ref)
    {
        $template .= "extern kal_uint32 Image\$\$$_\$\$Base;\n";
        $template .= "extern kal_uint32 Image\$\$$_\$\$Length;\n";
        $template .= "extern kal_uint32 Image\$\$$_\$\$ZI\$\$Limit;\n";
    }
    my $MULTIROM_ref = &GetGroupedRegions("MULTIROM");
    my ($BOOTCERT, $SECURE_MAC, $SECURE_RO) = (undef, undef, undef);
    my $bSetDCM = 0;
    foreach (@$MULTIROM_ref)
    {
        my $array_ref = $_;
        if(scalar(@$array_ref) > 1)
        {
            if($array_ref->[0] =~ /DYNAMIC_CODE/ and $bSetDCM == 0)
            {
                my ($strRegionName, $strLenght) = &Get_DCM_Region_Info($array_ref);
                $template .= "extern kal_uint32 Load\$\$$strRegionName\$\$Base;\n";
                $bSetDCM = 1;
            }
            else
            {
                $template .= "extern kal_uint32 Load\$\$".$array_ref->[ 0 ]."\$\$Base;\n"; #FirstRegion
                $template .= "extern kal_uint32 Load\$\$".$array_ref->[ scalar(@$array_ref)-1 ]."\$\$Base;\n"; #LastRegion
            }
        }
        else
        {
            $template .= "extern kal_uint32 Load\$\$".$array_ref->[0]."\$\$Base;\n";
            $BOOTCERT = $_->[0] if($_->[0] =~ /BOOT_CERT/);
            $SECURE_MAC = $_->[0] if($_->[0] =~ /__HIDDEN_SECURE_MAC/);
            $SECURE_RO = $_->[0] if($_->[0] =~ /SECURE_RO/);
        }
    }
    my $ROM_End = &Gen_RegionName_EV_ROM_END("ROM");
    $template .= "extern kal_uint32 Load\$\$$ROM_End\$\$Base;\n";
    
    return $template;
}
sub SCAT_C_Gen_ARRAY_DEMP_RESOURCE_TABLE
{
    my $template;
    my $MBA_href = &GetGroupedRegions("MBA");
    foreach(@$MBA_href)
    {
        my $temp = $_->[0]; 
        $temp =~ s/_ROM//;
        $template .= "static kal_uint16 demp_".lc($temp)."_image_table[DEMP_".uc($temp)."_SIZE * DEMP_BLOCK_PER_MB];\n";
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_DEMP_RESOURCE_TABLE_ASSIGN
{
    my $template;
    my $MBA_href = &GetGroupedRegions("MBA");
    foreach(@$MBA_href)
    {
        my $temp = $_->[0]; 
        $temp =~ s/_ROM//;
        $template .= "    demp_image_table[DEMP_".uc($temp)."] = demp_".lc($temp)."_image_table;\n";
    }
    return $template;
}
sub GetGroupedRegionCount
{
    my ($strKey) = @_;
    my $nCount = 0;
    if($strKey eq "CPT")
    {
        my $fpt_count = 1; # ROM
#        $fpt_count++ if($g_MAUILinkInfo->IsRegionExistent("SECONDARY_ROM"));
        $nCount = 1 + (4*&GetGroupedRegionCount("DYNAMIC_DNC")) + 
                      (4*&GetGroupedRegionCount("DYNAMIC_DC")) + 
                      (4*&GetGroupedRegionCount("CACHED_RW")) + 
                      (4*&GetGroupedRegionCount("CACHED_RO")) + 
                      (2*&GetGroupedRegionCount("NONCACHED_RW")) + 
                      (2*&GetGroupedRegionCount("NONCACHED_RO")) + 
                      1 + #cpt_for_last: DSPTX, DSPRX
                      (&GetGroupedRegionCount("EXTCODE")-1) + 2 +
                      $fpt_count;
    }
    else
    {
        if(exists $g_GroupedRegions{$strKey})
        {
            $nCount = $g_GroupedRegions{$strKey}->[0];
        }
        else
        {
            my $Array_ref = $g_MAUILinkInfo->GetGroupedRegions($strKey);
            $nCount = (scalar(@$Array_ref));
            $g_GroupedRegions{$strKey} = [$nCount, $Array_ref];
        }
    }
    return $nCount;
}
sub SCAT_C_Gen_ARM9_PT_POOLSIZE
{
    my $template;
    my $cpt_count = &GetGroupedRegionCount("CPT");
    $template = "#define MAX_FPT_POOL_SIZE ( 0 )\n";
    $template .="#define MAX_CPT_POOL_SIZE ($cpt_count * 1 * 1024)";

    return $template;
}
sub SCAT_C_Gen_ARM11_PT_POOLSIZE
{
    my $template;
    my $cpt_count = &GetGroupedRegionCount("CPT");
    $template = "#define MAX_CPT_POOL_SIZE ( $cpt_count * 1 * 1024)";

    return $template;
}
sub SCAT_C_Gen_ARRAY_EXTSRAM_REGION
{
    my $DYNAMIC_DNC_Count = 1+&GetGroupedRegionCount("DYNAMIC_DNC");
    my $DYNAMIC_DC_Count = 1+&GetGroupedRegionCount("DYNAMIC_DC");
    my $CACHED_RW_Count = 1+&GetGroupedRegionCount("CACHED_RW"); 
    my $CACHED_RO_Count = 1+&GetGroupedRegionCount("CACHED_RO"); 
    my $NONCACHED_RW_Count = 1+&GetGroupedRegionCount("NONCACHED_RW");
    my $NONCACHED_RO_Count = 1+&GetGroupedRegionCount("NONCACHED_RO"); 
    my $EXTCODE_Count = 1+&GetGroupedRegionCount("EXTCODE");
    my $template = <<"__TEMPLATE";
__TCMZI static EXTSRAM_REGION_INFO_T DYNAMIC_CACHED_EXTSRAM_DNC_REGION[$DYNAMIC_DNC_Count];
__TCMZI static EXTSRAM_REGION_INFO_T DYNAMIC_CACHED_EXTSRAM_DC_REGION[$DYNAMIC_DC_Count];
__TCMZI static EXTSRAM_REGION_INFO_T CACHED_EXTSRAM_REGION[$CACHED_RW_Count];
__TCMZI static EXTSRAM_REGION_INFO_T CACHED_EXTSRAM_CODE_REGION[$CACHED_RO_Count];
__TCMZI static EXTSRAM_REGION_INFO_T NONCACHED_EXTSRAM_REGION[$NONCACHED_RW_Count];
__TCMZI static EXTSRAM_REGION_INFO_T NONCACHED_EXTSRAM_RO_REGION[$NONCACHED_RO_Count];
__TEMPLATE
}

sub SCAT_C_Gen_TEMPLATE_1stRAM_BEGIN
{
    my $template = "0";
    my $array_ref = $g_MAUILinkInfo->GetExeRegionsInRAMByLoadRegion("ROM");
    &sysUtil::sysgen_die("There should be execution regions in ROM!", __FILE__, __LINE__) if(!defined $array_ref);
    my $strRegionName = $array_ref->[0];
    my $Offset = lc($g_MAUILinkInfo->GetRegionInfo($strRegionName, Region::Offset));
    if($Offset =~ /\+0xf/)
    {
        $template = "(kal_uint32)((kal_uint32)&Image\$\$$strRegionName\$\$Base & (~0xf0000000))";
    }
    else
    {
        $template = "(kal_uint32)&Image\$\$$strRegionName\$\$Base";
    }
    return $template;
}
sub SCAT_C_Gen_RegionName_EV_1stRAM_END
{
    my $array_ref = $g_MAUILinkInfo->GetExeRegionsInRAMByLoadRegion("ROM");
    &sysUtil::sysgen_die("There should be execution regions in ROM!", __FILE__, __LINE__) if(!defined $array_ref);
    return $array_ref->[$#{$array_ref}];
}
sub SCAT_C_Gen_RegionName_EV_1stROM_BEGIN
{
    my $array_ref = $g_MAUILinkInfo->GetExeRegionsInROMByLoadRegion("ROM");
    &sysUtil::sysgen_die("There should be execution regions in ROM!", __FILE__, __LINE__) if(!defined $array_ref);
    return $array_ref->[0];
}
sub SCAT_C_Gen_TEMPLATE_1stROM_LENGTH
{
    my $array_ref = $g_MAUILinkInfo->GetExeRegionsInROMByLoadRegion("ROM");
    &sysUtil::sysgen_die("There should be execution regions in ROM!", __FILE__, __LINE__) if(!defined $array_ref);
    return &get_region_length($array_ref);
}
sub get_region_length
{
    my ($array_ref) = @_;
    my $template = "";
    foreach (@$array_ref)
    {
        my $Info = $g_MAUILinkInfo->GetExeRegionInfo($_);
        if(defined $Info->[Region::Offset])
        {
            my $Offset = "";
            if($Info->[Region::Offset] =~ /^+(\w+)/)
            {
                $Offset = " + $1" if(hex($1)!=0);
            }
            $template .= "    ROMLength += (kal_uint32)&Image\$\$$_\$\$Length$Offset;\n";
        }
        else
        {
            my $strBase = $Info->[Region::Base];
            my $strFirstBase = $g_MAUILinkInfo->GetRegionInfo($array_ref->[0], Region::Base);
            if(!defined $strFirstBase)
            {
                my $LoadInfo = $g_MAUILinkInfo->GetLoadRegionInfo($array_ref->[0]);
                $strFirstBase = $LoadInfo->[Region::Base];
            }
            if($strBase ne $strFirstBase)
            {
                $template .= "    ROMLength = $strBase - $strFirstBase; /* $_ define fixed address */ \n";
            }
            $template .= "    ROMLength += (kal_uint32)&Image\$\$$_\$\$Length;\n";
        }
    }
    return $template;
}
sub SCAT_C_Gen_RegionName_EV_1stROM_END
{
    return &Gen_RegionName_EV_ROM_END("ROM");
}
sub Gen_RegionName_EV_ROM_END
{
    my ($ROM) = @_;
    my $array_ref = $g_MAUILinkInfo->GetExeRegionsByLoadRegion($ROM);
    &sysUtil::sysgen_die("There should be execution regions in ROM!", __FILE__, __LINE__) if(!defined $array_ref and $ROM eq "ROM");
    my $LastRegion = undef;
    if(defined $array_ref)
    {
        my $nIndex = $#{$array_ref};
        foreach my $i (0 .. $nIndex)
        {
            if($array_ref->[$#{$array_ref} - $i] !~ /INTSRAM_BLINUSED|FLEXL2_DATA|FLMM|DSP/)
            {
                $LastRegion = $array_ref->[$#{$array_ref} - $i];
                last;
            }
        }
    }
    return $LastRegion;
}
sub SCAT_C_Gen_TEMPLATE_SYSRAM_BEGIN
{
    my $strBase = "0xE0000000";
    $strBase = '(kal_uint32)&Image$$INTSRAM_MULTIMEDIA$$Base' if($g_MAUILinkInfo->IsRegionExistent("INTSRAM_MULTIMEDIA"));
    return $strBase;
}
sub SCAT_C_Gen_TEMPLATE_SYSRAM_END
{
    my $strBase = "0xE0000000";
    $strBase = '(kal_uint32)&Image$$INTSRAM_MULTIMEDIA$$ZI$$Limit' if($g_MAUILinkInfo->IsRegionExistent("INTSRAM_MULTIMEDIA"));
    return $strBase;
}
sub SCAT_C_Gen_MaxSize_SYSRAM
{
    my $strMaxSize = "0";
    $strMaxSize = $g_MAUILinkInfo->GetRegionInfo("INTSRAM_MULTIMEDIA", Region::MaxSize) if($g_MAUILinkInfo->IsRegionExistent("INTSRAM_MULTIMEDIA"));
    return $strMaxSize;
}
sub GetGroupBase
{
    my ($strGroupName) = @_;
    my $template = "0";
    my $aref = GetGroupedRegions($strGroupName);
    if(scalar(@$aref)>0)
    {
        my $strRegionName = $aref->[0]->[0];
        $template = "(kal_uint32)&Image\$\$$strRegionName\$\$Base";
    }
    return $template;
}
sub GetGroupEnd
{
    my ($strGroupName) = @_;
    my $template = "0";
    my $aref = GetGroupedRegions($strGroupName);
    if(scalar(@$aref)>0)
    {
        my $end_index = scalar(@{$aref->[0]}) -1;
        my $strRegionName =  $aref->[0]->[$end_index];
        $template = "(kal_uint32)&Image\$\$$strRegionName\$\$ZI\$\$Limit";
    }
    return $template;
}

sub GetGroupBaseRegionName
{
    my ($strGroupName) = @_;
    my $strRegionName = undef;
    my $aref = GetGroupedRegions($strGroupName);
    if(scalar(@$aref)>0)
    {
        my $end_index = scalar(@{$aref->[0]}) -1;
        $strRegionName =  $aref->[0]->[$end_index];
    }
    return $strRegionName;
}
sub SCAT_C_Gen_L1CORE_LV_Base
{
    return GetGroupBase("L1CORE_LV");
}
sub SCAT_C_Gen_L1CORE_LV_End
{
    return GetGroupEnd("L1CORE_LV");
}
sub SCAT_C_Gen_L1CORE_RWZI_Base
{
    return GetGroupBase("L1CORE_RWZI");
}


sub SCAT_C_Gen_L1CORE_RWZI_End
{
    return GetGroupEnd("L1CORE_RWZI");
}
sub SCAT_C_Gen_DNC_SharedMem_Base
{
    return GetGroupBase("SHARED_DYNAMIC_DNC");
}
sub SCAT_C_Gen_DNC_SharedMem_End
{
    return GetGroupEnd("SHARED_DYNAMIC_DNC");
}
sub SCAT_C_Gen_DNC_MCURO_HWRW_SharedMem_Base
{
    return GetGroupBase("SHARED_DYNAMIC_DNC_MCURO_HWRW");
}
sub SCAT_C_Gen_DNC_MCURO_HWRW_SharedMem_End
{
    return GetGroupEnd("SHARED_DYNAMIC_DNC_MCURO_HWRW");
}
sub SCAT_C_Gen_DNC_MCURW_HWRW_SharedMem_Base
{
    return GetGroupBase("SHARED_DYNAMIC_DNC_MCURW_HWRW");
}
sub SCAT_C_Gen_DNC_MCURW_HWRW_SharedMem_End
{
    return GetGroupEnd("SHARED_DYNAMIC_DNC_MCURW_HWRW");
}


sub SCAT_C_Gen_NC_SharedMem_Base
{
    return GetGroupBase("SHARED_NONCACHED_RW");
}
sub SCAT_C_Gen_NC_SharedMem_End
{
    return GetGroupEnd("SHARED_NONCACHED_RW");
}
sub SCAT_C_Gen_NC_MCURO_HWRW_SharedMem_Base
{
    return GetGroupBase("SHARED_DYNAMIC_NC_MCURO_HWRW");
}
sub SCAT_C_Gen_NC_MCURO_HWRW_SharedMem_End
{
    return GetGroupEnd("SHARED_DYNAMIC_NC_MCURO_HWRW");
}
sub SCAT_C_Gen_NC_MCURW_HWRW_SharedMem_Base
{
    return GetGroupBase("SHARED_DYNAMIC_NC_MCURW_HWRW");
}
sub SCAT_C_Gen_NC_MCURW_HWRW_SharedMem_End
{
    return GetGroupEnd("SHARED_DYNAMIC_NC_MCURW_HWRW");
}


sub SCAT_C_Gen_INTSRAMDATA_END
{
    my $template = "kal_uint32 ret=0;\n";
    my $INTSRAM_ref = &GetGroupedRegions("INTSRAM");
    foreach (@$INTSRAM_ref)
    {
        my $array_ref = $_;
        my $nCount = (scalar(@$array_ref));
        for(my $i=0; $i<$nCount;++$i)
        {
            next if ( $array_ref->[ $i ] =~ /INTSRAM_PHYSICAL_BOUNDARY/ );
            my $strEnd = "(kal_uint32)&Image\$\$".$array_ref->[ $i ]."\$\$ZI\$\$Limit";
            $template .= "\tret = ($strEnd > ret ? $strEnd : ret);\n";
        }
    }
    $template .= "\treturn ret;\n";
    return $template;
}

sub SCAT_C_Gen_RegionName_EV_INTSRAM_HW_BOUNDARY
{
    my $strRegion = "INTSRAM_DATA";
    $strRegion = "INTSRAM_PHYSICAL_BOUNDARY" if($g_MAUILinkInfo->IsRegionExistent("INTSRAM_PHYSICAL_BOUNDARY"));
    return $strRegion;
}
sub SCAT_C_Gen_MaxSize_INTSRAM_HW_BOUNDARY
{
    my $strMaxSize = "0";
    $strMaxSize = $g_MAUILinkInfo->GetRegionInfo("INTSRAM_PHYSICAL_BOUNDARY", Region::MaxSize) if($g_MAUILinkInfo->IsRegionExistent("INTSRAM_PHYSICAL_BOUNDARY"));
    return $strMaxSize;
}
sub SCAT_C_Gen_TEMPLATE_PROTECTED_RES_BEGIN
{
    return &Gen_Region_EV_TEMPLATE("PROTECTED_RES", "Base");
}
sub SCAT_C_Gen_TEMPLATE_PROTECTED_RES_LEGNTH
{
    return &Gen_Region_EV_TEMPLATE("PROTECTED_RES", "Length");
}
sub SCAT_C_Gen_TEMPLATE_BOOTCERT_BEGIN
{
    my $template = "0";
    $template = '(kal_uint32)&Load$$BOOT_CERT$$Base' if($g_MAUILinkInfo->IsRegionExistent("BOOT_CERT"));
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_SECUREMAC_BEGIN
{
    my $template = "0";
    $template = '(kal_uint32)&Load$$__HIDDEN_SECURE_MAC$$Base' if($g_MAUILinkInfo->IsRegionExistent("__HIDDEN_SECURE_MAC"));
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_SECUREMAC_LEGNTH
{
    my $template = "0";
    $template = '(kal_uint32)&Image$$__HIDDEN_SECURE_MAC$$Length' if($g_MAUILinkInfo->IsRegionExistent("__HIDDEN_SECURE_MAC"));
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_SECURERO_BEGIN
{
    my $template = "0";
    $template = '(kal_uint32)&Load$$SECURE_RO$$Base' if($g_MAUILinkInfo->IsRegionExistent("SECURE_RO"));
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_SECURERO_LEGNTH
{
    my $template = "0";
    $template = '(kal_uint32)&Image$$SECURE_RO$$Length' if($g_MAUILinkInfo->IsRegionExistent("SECURE_RO"));
    return $template;
}

sub SCAT_C_Gen_TEMPLATE_DSPTXRX_BEGIN
{
    my $template = "0";
    my $strRegionName = $g_MAUILinkInfo->SearchExeRegionName("_DSP_TX\$");                         	# add \$ to avoid get DSP_TX_ZI section
    $strRegionName = $g_MAUILinkInfo->SearchExeRegionName("_DSP_RX\$") if(!defined $strRegionName);	# add \$ to avoid get DSP_TX_ZI section
    $template = "(kal_uint32)&Image\$\$$strRegionName\$\$Base" if(defined $strRegionName);
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_DSPTXRX_MAXSIZE
{
    my ($nTXLength,$nRXLength) = &sysUtil::DSPTXRX_query_length($g_bb, &FileInfo::get("MODE"));
    return &CommonUtil::Dec2Hex($nTXLength) ." + ". &CommonUtil::Dec2Hex($nRXLength);
}
sub SCAT_C_Gen_TEMPLATE_MAX_FREERAM_NON_MMU
{
    my $template;
    if(0 == &sysUtil::is_mmu($g_bb))
    {
        my $array_ref = &GetGroupedRegions("NONCACHED_RW");
        my $nIndex = 0;
        my $PreviousLastRegion;
        foreach(@$array_ref)
        {
            if($nIndex > 0)
            {
                my $ThisRegion = $_->[0];
                $template .= <<"__TEMPLATE";
    /* Round $nIndex */
    ThisRegionBegin = (kal_uint32)&Image\$\$$ThisRegion\$\$Base;
    LastRegionEnd   = (kal_uint32)&Image\$\$$PreviousLastRegion\$\$ZI\$\$Limit;
    LastRegionEnd   = (LastRegionEnd + 16) & 0xFFFFFFF0;
    if ((ThisRegionBegin - LastRegionEnd) > MaxLength)
    {
       MaxBeginAddr = LastRegionEnd;
       MaxLength    = ThisRegionBegin - LastRegionEnd;
    }
__TEMPLATE
            }
            $PreviousLastRegion = $_->[$#$_];
            $nIndex++;
        }
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_MAX_FREERAM_MMU
{
    my $DUMMY_END = &Gen_RegionName_UNUSED_END_Base();
    my $LAST_CACHED_REGION = &Gen_RegionName_EV_LAST_CACHED_REGION();
    my $template = <<"__TEMPLATE";
    /* Direct Assign the Cached Region */
    ThisRegionBegin = (kal_uint32)&Image\$\$$DUMMY_END\$\$Base;
    LastRegionEnd   = (kal_uint32)&Image\$\$$LAST_CACHED_REGION\$\$ZI\$\$Limit;    
    LastRegionEnd   = (LastRegionEnd + 16) & 0xFFFFFFF0;

    MaxLength       = ThisRegionBegin - LastRegionEnd;
    MaxBeginAddr    = LastRegionEnd;

    /* round to 4KB aligned */
    MaxBeginAddr = ((MaxBeginAddr + 4096 - 1) >> 12) << 12;

    if (MaxLength < 4096) {
        MaxLength = 0;
    } else {
        /* round down to 4KB aligned */
        MaxLength -= 4096;
        /* round up end address to 4KB aligned */
        MaxLength = (MaxLength / 4096) * 4096;
        if (((kal_uint32)&Image\$\$SWLA_REGION\$\$Length != 0xFFFFFFFF) && ((kal_uint32)&Image\$\$SWLA_REGION\$\$Length < MaxLength)){
            MaxLength = (kal_uint32)&Image\$\$SWLA_REGION\$\$Length;
        }
    }

    /* Reserve to convert to non-cached address */
    /* MaxBeginAddr  =  MAP2CREGPA(MaxBeginAddr); */

__TEMPLATE

    return (1 == &sysUtil::is_mmu($g_bb)) ? $template: "";
}
sub Gen_RegionName_UNUSED_END_Base
{
    my $strRegionName;
    if(1 == &sysUtil::is_mmu($g_bb))
    {
        $strRegionName = "CACHED_DUMMY_END";
        $strRegionName = $g_MAUILinkInfo->SearchExeRegionName("DUMMY_END") if(! $g_MAUILinkInfo->IsRegionExistent($strRegionName));
    }
    $strRegionName = $g_MAUILinkInfo->SearchExeRegionName("EXTSRAM_FS_ZI") if( $g_MAUILinkInfo->IsRegionExistent("EXTSRAM_FS_ZI") );
    return $strRegionName;
}
sub Gen_RegionName_EV_LAST_CACHED_REGION
{
    my $strPreviousRegionName;
    if(1 == &sysUtil::is_mmu($g_bb))
    {
        my $strRegionName = &Gen_RegionName_UNUSED_END_Base();
        $strPreviousRegionName = $g_MAUILinkInfo->GetPreviousExeRegionName($strRegionName) if(defined $strRegionName);
        $strPreviousRegionName = $g_MAUILinkInfo->GetPreviousExeRegionName($strPreviousRegionName) if( $strPreviousRegionName eq "EXECUTION_VIEW_END" );	
        &sysUtil::sysgen_die("Region Name can't be empty!", __FILE__, __LINE__) if(!defined $strPreviousRegionName);
    }
    return $strPreviousRegionName;
}

sub SCAT_C_Gen_TEMPLATE_NVRAM_BASE
{
    return &Gen_Region_EV_TEMPLATE("NVRAM", "Base");
}
sub SCAT_C_Gen_TEMPLATE_NVRAM_LENGTH
{
    return &Gen_Region_EV_TEMPLATE("NVRAM", "Length");
}
sub Gen_Region_EV_TEMPLATE
{
    my ($strKey, $strPostfix) = @_;
    my $template = "0";
    my $RegionName = $g_MAUILinkInfo->SearchExeRegionName($strKey);
    if(defined $RegionName)
    {
        $template = "(kal_uint32)&Image\$\$$RegionName\$\$$strPostfix";
    }
    return $template;
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_DYNAMIC_DC_ASSIGN
{
    return &get_region_info_template("DYNAMIC_DC","DYNAMIC_CACHED_EXTSRAM_DC_REGION");
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_DYNAMIC_DNC_ASSIGN
{
    return &get_region_info_template("DYNAMIC_DNC","DYNAMIC_CACHED_EXTSRAM_DNC_REGION");
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_CACHED_RW_ASSIGN
{
    return &get_region_info_template("CACHED_RW","CACHED_EXTSRAM_REGION");
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_CACHED_RO_ASSIGN
{
    return &get_region_info_template("CACHED_RO","CACHED_EXTSRAM_CODE_REGION");
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_NONCACHED_RW_ASSIGN
{
    return &get_region_info_template("NONCACHED_RW","NONCACHED_EXTSRAM_REGION");
}
sub SCAT_C_Gen_TEMPLATE_EXTSRAM_REGION_NONCACHED_RO_ASSIGN
{
    return &get_region_info_template("NONCACHED_RO","NONCACHED_EXTSRAM_RO_REGION");
}

sub GetGroupedRegions
{
    my ($strKey) = @_;
    my $Array_ref = undef;
    my $nCount = 0;
    if(exists $g_GroupedRegions{$strKey})
    {
        $Array_ref = $g_GroupedRegions{$strKey}->[1];
    }
    else
    {
        $Array_ref = $g_MAUILinkInfo->GetGroupedRegions($strKey);
        $nCount = (scalar(@$Array_ref));
        $g_GroupedRegions{$strKey} = [$nCount, $Array_ref];
    }
    return $Array_ref;
}
sub get_region_info_template
{
    my ($strKey, $strArrayName) = @_;
    my $template;
    my $GroupedRegion_ref = &GetGroupedRegions($strKey);
    my $nIndex =0;
    my $RegionPrefix = ($strKey ne "MULTIROM") ? "Image" : "Load";
    foreach (@$GroupedRegion_ref) #[[], [], []]
    {
        my $array_ref = $_;
        my $Region = $array_ref->[0];
        my $strLength = undef;
        if($Region =~ /DYNAMIC_CODE/ and $strKey eq "MULTIROM")
        {# DCM Regions in MULTIROM should be handled especially
            ($Region, $strLength) = &Get_DCM_Region_Info($array_ref);
        }
        $template .= "    $strArrayName\[$nIndex].addr = (kal_uint32)&$RegionPrefix\$\$$Region\$\$Base;\n";
        
        if(scalar(@$array_ref) > 1)
        {
            $Region = $array_ref->[ scalar(@$array_ref)-1 ]; #LastRegion
            
        }
        else
        {
            my ($bIsFixed, $strFixedLength) = $g_MAUILinkInfo->IsFixedLengthRegion($Region);
            $strLength = $strFixedLength if ($bIsFixed == 1 
                                         or ($g_bb eq "MT6256" and $Region eq "DSP_ROM") 
                                         or ($strKey =~ /MCU_([NC|C]+)_DSP_([NC|C]+)/ and $Region =~/SHAREMEM/));
        }
        if(!defined $strLength)
        {
            if($Region =~/RW$|JUMP_TABLE/)
            {
                $strLength = "(kal_uint32)((kal_uint32)&$RegionPrefix\$\$$Region\$\$Base + (kal_uint32)&Image\$\$$Region\$\$Length) - $strArrayName\[$nIndex].addr";
            }
            elsif($Region =~/SECURE|FLASHTOOL_CFG|CUST_PARA|BOOT_CERT/)
            {   
                $strLength = "(kal_uint32)&Image\$\$$Region\$\$Length";
            }
            else
            {
                $strLength = "(kal_uint32)&Image\$\$$Region\$\$ZI\$\$Limit - $strArrayName\[$nIndex].addr";
            }
        }
        $template .= "    $strArrayName\[$nIndex].len = $strLength;\n";
        $nIndex++;
    }
    $template .= "    $strArrayName\[$nIndex].addr = $strArrayName\[$nIndex].len = 0;\n";
    return $template;
}
sub IMG_CFG_H_Gen_CBR_NORMAL_BLOCK_NUM
{
    my $template = "0";
    if(!&FileInfo::is_NOR() or $g_bb eq "MT6290") # smart phone can be default 0
    {
        $template = "2";
    }
    elsif(&FileInfo::is("secure_ro_enable","TRUE") or &FileInfo::is("secure_support","TRUE"))
    {
        $template = "1";
    }
    return $template;
}
sub IMG_CFG_H_Gen_CBR_SPARE_BLOCK_NUM
{
    my $template = "0";
    if(!&FileInfo::is_NOR()) # smart phone can be default 0
    {
        $template = "2";
    }
    return $template;
}

sub EMI_OFFSET_H_Gen_MD_SIZE
{
    my($strBase, $strLen) = $g_MAUILinkInfo->{ldsInfo}->GetMEMORYInfoByName("RAM"); 
    my $nBase = hex($strBase);
    my $nLen = hex($strLen);
    #xor bank address
    my $nPrefix = sysUtil::GetNonCacheablePrefix($g_bb);
    my $nMDSize = ($nBase ^ $nPrefix) + $nLen;
    return CommonUtil::Dec2Hex($nMDSize);
}
