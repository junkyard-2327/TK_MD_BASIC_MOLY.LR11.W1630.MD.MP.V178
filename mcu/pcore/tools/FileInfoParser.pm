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
#*   FileInfoParser.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module collects the subroutines for common utility. 
#*       
#*
#* Author:
#* -------
#*   Carl Kao (mtk08237)
#*
#****************************************************************************/
use strict;
#use warnings;
BEGIN { push @INC, './pcore/tools/' }  # add additional library path
#--------------------------------------------------------------------------------------------------------------
package BuildOPT;
#****************************************************************************
# Constant
#****************************************************************************
use constant CMPL         => 0;
use constant REL          => 1;
#--------------------------------------------------------------------------------------------------------------
package FileInfo;

use constant L1CORE_INFO_FORCE      => "L1CORE_INFO_FORCE";

use constant L1CORE_LV_SIZE         => "L1CORE_LV_SIZE";
use constant L1CORE_RWZI_SIZE       => "L1CORE_RWZI_SIZE";

use constant SHARED_REGION_SIZE     => "SHARED_REGION_SIZE";

#use constant PCORE_LV_SIZE          => "PCORE_LV_SIZE";
use constant PCORE_LV1_SIZE          => "PCORE_LV1_SIZE";
use constant PCORE_LV2_SIZE          => "PCORE_LV2_SIZE";

use constant L1CORE_DSP_TX_LENGTH                   => "L1CORE_DSP_TX_LENGTH";
use constant L1CORE_DSP_RX_LENGTH                   => "L1CORE_DSP_RX_LENGTH";

use constant L1CORE_DSP_LIMIT                 => "L1CORE_DSP_LIMIT";

use constant L1CORE_DUMP_REGION__C_BASE       => "L1CORE_DUMP_REGION__C_BASE";
use constant L1CORE_DUMP_REGION__C_SIZE       => "L1CORE_DUMP_REGION__C_SIZE";
use constant L1CORE_DUMP_REGION__DC_BASE      => "L1CORE_DUMP_REGION__DC_BASE";
use constant L1CORE_DUMP_REGION__DC_SIZE      => "L1CORE_DUMP_REGION__DC_SIZE";
use constant L1CORE_DUMP_REGION__NC_BASE      => "L1CORE_DUMP_REGION__NC_BASE";
use constant L1CORE_DUMP_REGION__NC_SIZE      => "L1CORE_DUMP_REGION__NC_SIZE";
use constant L1CORE_DUMP_REGION__DNC_BASE     => "L1CORE_DUMP_REGION__DNC_BASE";
use constant L1CORE_DUMP_REGION__DNC_SIZE     => "L1CORE_DUMP_REGION__DNC_SIZE";

use constant L1CORE_DUMP_REGION__L2SRAM_DATA_BASE       => "L1CORE_DUMP_REGION__L2SRAM_DATA_BASE";
use constant L1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT    => "L1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT";

use constant L1CORE_REGION__OFFSET            => "L1CORE_REGION__OFFSET";

use constant L1CORE_VECTOR                    => "L1CORE_VECTOR";

use constant L1CORE_SWLA_SIZE                 => "L1CORE_SWLA_SIZE";

use sysGenUtility;               #pm file name without case sensitivity
use CommonUtility;
#****************************************************************************
# Constants
#****************************************************************************
my $FILEINFOPARSER_VERNO     = " v0.21";
                               # v0.21 , 2017/May/24,  Carl,  New Layout
                               # v0.20,  2016/01/05,   Tero,  Merge m0.15 from MOLY (Fix compiler option parsing bug in EvaluateCompileOption())
                               # v0.19,  2015/11/17,   Tero,  Added L1CORE_SWLA_SIZE constant
                               # v0.18,  2015/11/02,   Carl,  Change DSP TX/RX sections to ZI (.bss) section
                               # v0.17,  2015/09/17,   Carl,  Move dsp bin from l1core rom to l1core ram, change the 1st EMI RMPU channel base to Image$$L1CORE_DSP$$:imit
                               # u0.16 , 2015/07/03,   Carl,  Call GetDefaultSharedMemorySize to get default shared memory size
                               # u0.15 , 2015/06/23,   Carl,  Refine GetSharedMemorySize. It includes dsp tx/rx section now
                               # u0.14 , 2015/06/22,   Carl,  Decrease shared region size (in 1st linking time) from  96 MB to  80 MB
                               # u0.13 , 2015/06/22,   Carl,  Decrease shared region size (in 1st linking time) from 112 MB to  96 MB
                               # u0.12 , 2015/05/19,   Carl,  Increase shared region size (in 1st linking time) from  80 MB to 112 MB
                               # u0.11 , 2015/04/17,   Carl,  Increase shared region size (in 1st linking time) from  48 MB to  80 MB
                               # u0.10 , 2015/02/06,   Carl,  disable isSupportedToAdjustLoadView for ESL COSIM
                               # u0.09 , 2015/01/06,   Carl,  lds refinement: 1) auto adjust shared region size, 2) reserve pcore, l1core SWLA space
                               # u0.08 , 2014/22/22,   Carl,  Support L2SRAM section (in L1CORE) 
                               # u0.07 , 2014/08/20,   Carl,  refine l1core dump region
                               # u0.06 , 2014/08/19,   Carl,  add constant value for l1core rector vector load view
                               # u0.05 , 2014/07/31,   Carl,  add constant value for dump l1core region
                               # ...
                               # m0.15 , 2014/08/04, Fix compiler option parsing bug in EvaluateCompileOption()
                               # m0.14 , 2013/12/24, Support is_with_AP
                               # m0.13 , 2013/06/28, Ignore MD5 in MDSYS option
                               # m0.12 , 2013/06/25, Support Copro related query and combined cmp_option+mkfile parsing and query
                               # m0.11 , 2013/05/28, Support to evaluate compiler option
                               # m0.10 , 2012/11/16, Support is_MAIN_CODE_NEED_GFH
                               # m0.09 , 2013/03/22, Support parsing informake.log
                               # m0.08 , 2012/01/14, Support basic query functions more flexible
                               # m0.07 , 2012/10/19, Support is_XBOOTING, is_HostedDongle, is_RNDISDongle
                               # m0.06 , 2012/09/18, Fix MakeFile mode parsing
                               # m0.05 , 2012/08/17, Support GetChip()
                               # m0.04 , 2012/08/06, Add more common functions and ParseDefinition()
                               # m0.03 , 2012/07/26, Support is_NonSPNOR()
                               # m0.02 , 2012/05/28, Support path and filename case sensitive on Linux
                               # v0.07 , 2012/05/13, Move is_NOR from sysgenUtility to here and support general query
                               # m0.01 , 2012/05/09, Provide GetCompiler()
                               # v0.06 , 2012/05/08, Copy parseFeatureOptionCondition 
                               #                     and EvaluateFeatureOptionCondition from objListHelper.pm to here
                               # v0.05 , 2012/05/08,  Query is_SmartPhone
                               # v0.04 , 2012/01/30,  To provide CUSTOMER and MODE in %MAKEFILE_OPTIONS
                               # v0.03 , 2011/12/17,  Fix parsing MakeFile
                               # v0.02 , 2011/11/01,  Remove $$ to support Perl v5.12.*
                               # v0.01 , 2011/09/21,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************
my $g_MAKEFILE_href = undef;
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

sub PreProcess
{
    my ($MAKE_FILE, $mk_href, $INFOMAKE, $CmplOpt_href, $RelInfo_href, $bDie) = @_;
    my $bResult = 1;
    if(!BuildInfo::Parse_InfoMakeLog($INFOMAKE, $CmplOpt_href, $RelInfo_href))
    {
        $bResult = 0;
        FileInfoParser_die("Parse infomake.log failed")if($bDie);
    }
    if(!FileInfo::Parse_MAKEFILE($MAKE_FILE, $mk_href))
    {
        $bResult = 0;
        FileInfoParser_die("Parse MakeFile failed")if($bDie);
    }
    return $bResult;
}

#****************************************************************************
# subroutine:  Parse_MAKEFILE
# input:    1. MAKEFILE path
#           2. a Hash to contain MAKEFILE information.
# output:   1=Parse successfully, 0 or die= Parse failed.
# sample code: my %MAKEFILE_OPTIONS;
#              &FileInfo::Parse_MAKEFILE($MAKEFILE_Path, \%MAKEFILE_OPTIONS);   
#****************************************************************************

sub Parse_MAKEFILE
{
    my ($strMAKEFILE_Path, $Info_href) = @_;
    my $bResult = 0;
    if(-e $strMAKEFILE_Path)
    {
        open (FILE_HANDLE, $strMAKEFILE_Path) or &FileInfoParser_die("Cannot open $strMAKEFILE_Path\n", __FILE__, __LINE__);
        while (<FILE_HANDLE>) 
        {
            if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/))
            {
                my $keyname = lc($1);
                #defined($Info_href->{$keyname}) && warn "$1 redefined in $strMAKEFILE_Path!\n";
                $Info_href->{$keyname} = uc($2);
                $keyname = uc($1);
                #defined($Info_href->{$keyname}) && warn "$1 redefined in $strMAKEFILE_Path!\n";
                $Info_href->{$keyname} = uc($2);
                $bResult = 1;
            }
        }
        close FILE_HANDLE;
        if ($strMAKEFILE_Path =~ /(\w+)_(\w+)\((\w+)\).mak/i) 
        {
            #$Info_href->{'CUSTOMER'} = uc($3); // Carl: what's this?
            #$Info_href->{'customer'} = uc($3);
            $Info_href->{'MODE'} = uc($3);
            $Info_href->{'mode'} = uc($3);
        }
        $g_MAKEFILE_href = $Info_href;
    }
    else
    {
        &FileInfoParser_die("$strMAKEFILE_Path: NOT exist!", __FILE__, __LINE__);
    }
    return $bResult;
}

sub GetMakeFileRef
{
    my ($strMAKEFILE_Path) = @_;
    if(!defined $g_MAKEFILE_href)
    {
        my %MakeFileOption;
        &Parse_MAKEFILE($strMAKEFILE_Path, \%MakeFileOption);
    }
    return $g_MAKEFILE_href;    
}
sub is
{
    my ($strKey, $strValue, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $bEqual = 0;
    if(exists $MakeFile_ref->{uc($strKey)} and uc($MakeFile_ref->{uc($strKey)}) eq uc($strValue))
    {
        $bEqual = 1;
    }
    return $bEqual;
}
sub find
{
    my ($strKey, $strValue, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $bFound = 0;
    if(exists $MakeFile_ref->{uc($strKey)} and $MakeFile_ref->{uc($strKey)} =~ /$strValue/)
    {
        $bFound = 1;
    }
    return $bFound;
}
sub isnot
{
    my ($strKey, $strValue, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $bNotEqual = 0;
    if(exists $MakeFile_ref->{uc($strKey)} and uc($MakeFile_ref->{uc($strKey)}) ne uc($strValue))
    {   #exist but not equal
        $bNotEqual = 1;
    }
    return $bNotEqual;
}
sub get
{
    my ($strKey, $MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $Value = undef;
    if(exists $MakeFile_ref->{uc($strKey)})
    {
        $Value = $MakeFile_ref->{uc($strKey)};
    }
    elsif(exists $MakeFile_ref->{$strKey})
    {
        $Value = $MakeFile_ref->{$strKey};
    }
    return $Value;
}
sub ParseDefinition
{
    my ($strFilePath, $Hash_ref, $bAllowDuplicated) = @_;
    my $content = &CommonUtil::GetFileContent($strFilePath);
    #strip comments
    $content =~ s/\/\/(.+)//g;
    $content =~s#/\*[^*]*\*+([^/*][^*]*\*+)*/|([^/"']*("[^"\\]*(\\[\d\D][^"\\]*)*"[^/"']*|'[^'\\]*(\\[\d\D][^'\\]*)*'[^/"']*|/+[^*/][^/"']*)*)#$2#g;

    my @lines = split(/\n|\r/, $content);
    my $nDuplicatedIndex=0;
    foreach my $line (@lines)
    {
        if ($line =~ /#define\s+(\w+)\s+\((.*)\)\s*$/ || $line =~ /#define\s+(\w+)\s+(\S*)\s*$/)
        {
            my $option = $1;
            my $value  = $2;
            &FileInfoParser_die("$strFilePath: $option redefined in $strFilePath!", __FILE__, __LINE__) 
                if (!$bAllowDuplicated and defined($Hash_ref->{$option}));
            if (!defined $value)
            {
                $Hash_ref->{$option} = 'TRUE';
                $Hash_ref->{uc($option)} = 'TRUE';
                $Hash_ref->{lc($option)} = 'TRUE';
            }
            else
            {
                $Hash_ref->{$option} = $value;
                $Hash_ref->{uc($option)} = $value;
                $Hash_ref->{lc($option)} = $value;
            }
        }
    }
    close (FILE_HANDLE);
}


#****************************************************************************
# subroutine: is_SmartPhone - Query if it belongs smart phone project
# Input:      x
# Output:     1=it's SmartPhone, others=not SmartPhone
#****************************************************************************
sub is_SmartPhone
{
    my ($MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $bIsSmartPhone = 0;
    if( exists $MakeFile_ref->{SMART_PHONE_CORE} and $MakeFile_ref->{SMART_PHONE_CORE} ne "NONE" ) #NONE = feature phone
    {
        $bIsSmartPhone = 1;
    }
    return $bIsSmartPhone;
}

#****************************************************************************
# subroutine: is_with_AP - Query if it is paired with AP
# Input:      x
# Output:     1=it's paired with AP, others=other combination
#****************************************************************************
sub is_with_AP
{
    my ($MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $bIsWithAP = 0;
    if( exists $MakeFile_ref->{SMART_PHONE_CORE} and $MakeFile_ref->{SMART_PHONE_CORE} =~/ANDROID_MODEM/i )
    {
        $bIsWithAP = 1;
    }
    return $bIsWithAP;
}


#****************************************************************************
# subroutine: is_NOR - Query if it's NOR flash
# Input:      \%MAKEFILE_OPTION
# Output:     0=not NOR, 1=NOR
#****************************************************************************
sub is_NOR
{
    my ($MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bNOR = 1; # 0=not NOR, 1= NOR
    if((exists $MAKEFILE_ref->{'nand_flash_booting'} and $MAKEFILE_ref->{'nand_flash_booting'} ne 'NONE') 
    or (exists $MAKEFILE_ref->{'emmc_booting'} and $MAKEFILE_ref->{'emmc_booting'} ne 'NONE'))
    {
        $bNOR = 0;
    }
    return $bNOR;
}
#****************************************************************************
# subroutine: is_NonSPNOR - Query if it's not nand flash and not smart_phone project
# Input:      \%MAKEFILE_OPTION
# Output:     0=not NOR, 1=NOR
#****************************************************************************
sub is_NonSPNOR
{
    my ($MAKEFILE_ref) = @_;
    return (&is_NOR($MAKEFILE_ref) and !&is_SmartPhone($MAKEFILE_ref));
}

#****************************************************************************
# subroutine: is_BuiltWithCopro - Query if it's built with copro
# Input:      \%MAKEFILE_OPTION, \%Compile_OPTION
# Output:     0=not building with copro, 1=building with containing copro now 
#****************************************************************************
sub is_BuiltWithCopro
{
    my ($MAKEFILE_ref, $CMPL_href) = @_;
    my $bBuiltWithCopro = 0;
    $bBuiltWithCopro = 1 if(is("MD_OFFLOAD_COPRO", "ARM7EJ-S", $MAKEFILE_ref) 
               and !BuildInfo::exist(BuildOPT::CMPL, "NEED_BUILD_MD_OFFLOAD_COPRO", $CMPL_href));
    return $bBuiltWithCopro;
}
#****************************************************************************
# subroutine: is_Copro - Query if it's COPRO
# Input:      \%MAKEFILE_OPTION, \%Compile_OPTION
# Output:     0=not copro, 1=it's copro
#****************************************************************************
sub is_Copro
{
    my ($MAKEFILE_ref, $CMPL_href) = @_;
    my $bCopro = 0;
    $bCopro = 1 if(is("MD_OFFLOAD_COPRO", "ARM7EJ-S", $MAKEFILE_ref) 
               and BuildInfo::exist(BuildOPT::CMPL, "NEED_BUILD_MD_OFFLOAD_COPRO", $CMPL_href));
    return $bCopro;
}

#****************************************************************************
# subroutine: is_MAIN_CODE_NEED_GFH - Query if it's MAIN_CODE_NEED_GFH:
#             SMART_PHONE_CORE != NONE && X_BOOTING==NONE => MAIN_CODE_NEED_GFH = FALSE
# Input:      \%MAKEFILE_OPTION
# Output:     0=no GFH, 1=having GFH
#****************************************************************************
sub is_MAIN_CODE_NEED_GFH
{
    my ($bb, $MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bNEED_GFH = 0;
    if(&sysUtil::is_sv5($bb))
    {
        $bNEED_GFH = 1;
        if(&is_SmartPhone($MAKEFILE_ref) && &is("X_BOOTING", "NONE", $MAKEFILE_ref) )
        {
            $bNEED_GFH = 0;
        }
    }
    return $bNEED_GFH;
}

#****************************************************************************
# subroutine: is_XBOOTING - Query if it's X_BOOTING: X_BOOTING != NONE
# Input:      \%MAKEFILE_OPTION
# Output:     0=not X BOOTING, 1=X BOOTING
#****************************************************************************
sub is_XBOOTING
{
    my ($MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bX = 0;
    $bX = 1 if(&isnot("X_BOOTING", "NONE"));
    return $bX;
}

#****************************************************************************
# subroutine: is_HostedDongle - Query if it's HostedDongle
#             SMART_PHONE_CORE=MODEM_HOST and X_BOOTING=NONE
# Input:      \%MAKEFILE_OPTION
# Output:     0=not Hosted dongle, 1=Hosted dongle
#****************************************************************************
sub is_HostedDongle
{
    my ($MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bX = 0;
    $bX = 1 if(&is("SMART_PHONE_CORE", "MODEM_HOST") and !&is_XBOOTING());
    return $bX;
}


#****************************************************************************
# subroutine: is_RNDISDongle - Query if it's RNDIS Dongle
#             (is smartphone but SMART_PHONE_CORE != MODEM_HOST) and X_BOOTING=NONE
# Input:      \%MAKEFILE_OPTION
# Output:     0=not RNDIS, 1=RNDIS
#****************************************************************************
sub is_RNDISDongle
{  
    my ($MAKEFILE_ref) = @_;
    $MAKEFILE_ref = $g_MAKEFILE_href if (!defined $MAKEFILE_ref);
    &NoMakeFile_die($MAKEFILE_ref, __FILE__, __LINE__);
    my $bX = 0;
    $bX = 1 if(&is_SmartPhone() and !&is_XBOOTING() and !is_HostedDongle());
    return $bX;
}

#****************************************************************************
# subroutine: GetCompiler()
# Input:      \%MAKEFILE_OPTION
# Output:     Should be "GCC" or "RVCT" in string
#****************************************************************************
sub GetCompiler
{
    my ($MakeFile_ref) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $strCompiler = undef;
    $strCompiler = uc($MakeFile_ref->{COMPILER}) if(exists $MakeFile_ref->{COMPILER});
    &FileInfoParser_die("Unsupported ToolChain!\n", __FILE__, __LINE__) if(($strCompiler ne "GCC") and ($strCompiler ne "RVCT"));
    return $strCompiler;
}
#****************************************************************************
# subroutine: GetChip()
# Input:      \%MAKEFILE_OPTION
#             \%COMPILER_OPTION
# Output:     string (e.g. MT6280 or MT6280_XX)
#****************************************************************************
sub GetChip
{
    my ($MakeFile_ref, $CMPL_href) = @_;
    $MakeFile_ref = $g_MAKEFILE_href if (!defined $MakeFile_ref);
    &NoMakeFile_die($MakeFile_ref, __FILE__, __LINE__);
    my $strChip = undef;
    $strChip = uc($MakeFile_ref->{PLATFORM}) if(exists $MakeFile_ref->{PLATFORM});
    $strChip .= "_".uc($MakeFile_ref->{MDSYS}) if(exists $MakeFile_ref->{MDSYS} and $MakeFile_ref->{MDSYS} !~/none|md5/i);
    $strChip .= "_COPRO" if(is_Copro($MakeFile_ref, $CMPL_href));
    return $strChip;
}

#****************************************************************************
# subroutine:  GetSharedMemorySize
# description: return shared region size 
# input:       N/A
# output:     size of SHARED_REGION_SIZE in ~copro_info.tmp or default value (inculde dsp tx/rx sections)
# need init:   No
#****************************************************************************
sub GetSharedMemorySize
{
    my $nSharedRegionEnd = &FileInfo::get(SHARED_REGION_SIZE);
    return ( 0==$nSharedRegionEnd ? &sysUtil::GetDefaultSharedMemorySize(&GetChip()) : $nSharedRegionEnd );
}

#****************************************************************************
# subroutine:  EvaluateFeatureOptionCondition
# description: Evaluate the feature option condition.
# input:       Feature option condition(string), makefile options hash ref
# output:      1: true, 0: false
# need init:   No
#****************************************************************************
sub EvaluateFeatureOptionCondition
{
   my $condition = shift;
   my $makefileOptionsRef = shift;

   my @expressionTree;
   my @stack;

   # Transform the condition to expression tree in postfix form
   &parseFeatureOptionCondition($condition,  \@expressionTree);

   # Evaluate the expression tree
   foreach my $token (@expressionTree)
   {
      if ($token eq "&&" or $token eq "||")
      {
         my $second = pop(@stack);
         my $first = pop(@stack);
         push (@stack, eval "$first $token $second");
      }
      elsif ($token eq "=")
      {
         my $second = pop(@stack);
         my $first = pop(@stack);
         my $value = $makefileOptionsRef->{$first};
         $value = "" unless defined $value;
         if ($value eq $second)
         {
            push (@stack, 1);
         }
         else
         {
            push (@stack, 0);
         }
      }
      elsif ($token eq "!")
      {
         my $first = pop(@stack);
         if ($first == 1)
         {
            push (@stack, 0);
         }
         else
         {
            push (@stack, 1);
         }
      }
      else
      {
         push @stack, $token;
      }
   }
   &FileInfoParser_die("Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
      unless (1 == @stack);

   return $stack[0];
}

#****************************************************************************
# subroutine:  parseFeatureOptionCondition
# description: Parse the feature option condition to postfix form.
# input:       Feature option condition, expression tree ref
# output:      Expression tree
# need init:   No
#****************************************************************************
sub parseFeatureOptionCondition
{
   my $condition = shift;
   my $expressionTreeRef = shift;
   my $conditionNoSpace = $condition;
   $conditionNoSpace =~ s/ //g;

   my @tokens = split(/(=|\(|\)|&&|\|\||!)/, $conditionNoSpace);
   my @stack;

   # For error checking
   my $parenthesis = 0;
   my $operand = 0;
   my $operator = 0;

   foreach my $token (@tokens)
   {
      if ($token eq "")
      {
         # Skip empty token
         next;
      }
      elsif ($token eq "(")
      {
         push @stack, $token;
         ++$parenthesis;
      }
      elsif ($token eq ")")
      {
         &FileInfoParser_die("Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
            unless (0 < $parenthesis);
         my $temp = pop(@stack);

         &FileInfoParser_die("Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
            if ($temp eq "(");

         do
         {
            push @$expressionTreeRef, $temp;
            $temp = pop(@stack);
         } while ($temp ne "(");

         --$parenthesis;
      }
      elsif ($token eq "=" or $token eq "&&" or $token eq "||" or $token eq "!")
      {
         my $needLoop = 0;

         do
         {
            if (0 == scalar(@stack) or $stack[-1] eq "(")
            {
               # Stack is empty or stack top eqals to (
               push @stack, $token;
               $needLoop = 0;
            }
            elsif (0 < compareFeatureOptionOperator($stack[-1], $token))
            {
               # Stack top has higher priority than current token
               push @stack, $token;
               $needLoop = 0;
            }
            else
            {
               push @$expressionTreeRef, pop(@stack);
               $needLoop = 1;
            }
         } while ($needLoop);

         $operator += 1 unless ($token eq "!");
      }
      elsif ($token =~ /\w+/)
      {
         # Operand
         push @$expressionTreeRef, $token;
         $operand += 1;
      }
      else
      {
         &FileInfoParser_die("Incorrect syntax of feature option condition \"$condition\"",  __FILE__, __LINE__);
      }
   }

   &FileInfoParser_die("Incorrect syntax of feature option condition \"$condition\"", __FILE__, __LINE__)
      unless ($operator == ($operand - 1) and 0 == $parenthesis);

   push @$expressionTreeRef, reverse(@stack);
}

sub compareFeatureOptionOperator
{
   my $first = shift;
   my $second = shift;
   my %operatorToNumber = ("=" => 0, "!" => 1, "&&" => 2, "||" => 2);

   return $operatorToNumber{$first} <=> $operatorToNumber{$second};
}

#****************************************************************************
# subroutine:  FileInfoParser_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub FileInfoParser_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;
    }
    &sysUtil::error_handler($error_msg, $file, $line_no, 'ProjectMakeFileParser');    
}
sub NoMakeFile_die
{
    my ($MAKEFILE_ref, $file, $line_no) = @_;
    &FileInfoParser_die("Please parse project makefile by FileInfo::Parse_MAKEFILE() before using it.", $file, $line_no) 
        if(!defined $MAKEFILE_ref);
}

package BuildInfo;
#****************************************************************************
# Global variable
#****************************************************************************
my $g_CmplOpt_href = undef; # compiler option
my $g_RelInfo_href = undef; # release info
#****************************************************************************
# Subroutine
#****************************************************************************
#****************************************************************************
# subroutine:  Parse_InfoMakeLog
# input:    1. Infomake.log path
#           2. a Hash reference to contain CompilerOption information.
#           3. a Hash reference to contain Release information.
# output:   1=Parse successfully, 0 or die= Parse failed.
# sample code: my %CmplOption;
#              my %RelOption;
#              BuildInfo::Parse_InfoMakeLog($infomake_path, \%CmplOption, \%RelOption);
#****************************************************************************
sub Parse_InfoMakeLog
{
    my ($strInfomake_Path, $CmplOpt_href, $RelInfo_href) = @_;
    my $bResult = 0;
    if(-e $strInfomake_Path)
    {
        open (FILE_HANDLE, $strInfomake_Path) or BuildInfo_die("Cannot open $strInfomake_Path\n", __FILE__, __LINE__);
        while (<FILE_HANDLE>) 
        {
            if(/^(\S+)\s*\=\s*(.*)/)
            {
                my $key = $1;
                my $value = $2;
                if($key =~ /COM_DEFS/)
                {
                    _ParseCMPLOpt($value, $CmplOpt_href);
                }
                else
                {
                    $RelInfo_href->{$1} = $2;
                    $RelInfo_href->{lc($1)} = $2;
                }
            }
        }
        close FILE_HANDLE;
        $g_CmplOpt_href = $CmplOpt_href;
        $g_RelInfo_href = $RelInfo_href;
        $bResult = 1;
    }
    else
    {
        BuildInfo_die("$strInfomake_Path: NOT exist!", __FILE__, __LINE__);
    }
    return $bResult;
}

sub _ParseCMPLOpt
{
    my ($strOptions, $CmplOpt_href) = @_;
    my @ComlOpt = split(/\s/,$strOptions);
    foreach my $Opt(@ComlOpt)
    {
        $Opt =~ s/\s\n\r//;
        next if($Opt eq "");
        my $strkey = $Opt;
        my $strvalue = undef;
        if($Opt =~ /(.*)=(.*)/)
        {
            $strkey = $1;
            $strvalue = $2;
        }
        $CmplOpt_href->{$strkey} = $strvalue;
        $CmplOpt_href->{lc($strkey)} = $strvalue;
    }
}
sub GetCmplOptRef
{
    my ($strInfoMake_Path) = @_;
    if(!defined $g_CmplOpt_href)
    {
        my %CmplOption;
        my %RelOption;
        &Parse_InfoMakeLog($strInfoMake_Path, \%CmplOption, \%RelOption);
    }
    return $g_CmplOpt_href; 
}
sub GetRelOptRef
{
    my ($strInfoMake_Path) = @_;
    if(!defined $g_RelInfo_href)
    {
        my %CmplOption;
        my %RelOption;
        &Parse_InfoMakeLog($strInfoMake_Path, \%CmplOption, \%RelOption);
    }
    return $g_RelInfo_href;
}
#****************************************************************************
# subroutine: exist
# Input:      $nOption: BuildOPT::CMPL or BuildOPT::REL
# Output:     In compiler option, if $strKey exists in compiler option, it will return 1,
#                                 otherwises returns 0
#             In release information, it's usually meaningless to see if $strKey exists 
#****************************************************************************
sub exist
{
    my ($nOption, $strKey, $href) = @_;
    if (!defined $href)
    {
        $href = $g_CmplOpt_href if($nOption == BuildOPT::CMPL);
        $href = $g_RelInfo_href if($nOption == BuildOPT::REL);  
    }
    &NoInfoMake_die($href, __FILE__, __LINE__);
    my $bExist = 0;
    if(exists $href->{$strKey})
    {
        $bExist = 1;
    }
    return $bExist;
}

#****************************************************************************
# subroutine:  EvaluateCompileOption
# description: Evaluate the compile option
# input:       Compile option condition(string), compile options hash ref
# output:      1: true, 0: false
# need init:   No
#****************************************************************************
sub EvaluateCompileOption
{
    my ($condition, $CmpOption_href) = @_;
    $CmpOption_href = $g_CmplOpt_href if(!defined $CmpOption_href);
    &NoInfoMake_die($CmpOption_href, __FILE__, __LINE__);

    # Transform the condition to expression tree in postfix form
    my @expressionTree;
    _parseCompileOptionCondition($condition, \@expressionTree);
    
    # Evaluate the expression tree
    my @stack;
    foreach my $token (@expressionTree)
    {
        if ($token eq "&&" or $token eq "||")
        {
            my $second = pop(@stack);
            my $first  = pop(@stack);
            $first = exist(BuildOPT::CMPL, $first) if($first =~ /\D+/);
            $second = exist(BuildOPT::CMPL, $second) if($second =~ /\D+/);    
            push (@stack, eval "$first $token $second");
        }
        elsif ($token eq "=")
        {
            my $second = pop(@stack);
            my $first  = pop(@stack);
            my $value = $CmpOption_href->{$first};
            $value = "" unless defined $value;
            if ($value eq $second)
            {
                push (@stack, 1);
            }
            else
            {
                push (@stack, 0);
            }
        }
        elsif ($token eq "!")
        {
            my $first = pop(@stack);
            $first = exist(BuildOPT::CMPL, $first) if($first =~ /\D+/);
            if ($first == 1)
            {
                push (@stack, 0);
            }
            else
            {
                push (@stack, 1);
            }
        }
        else
        {
            push @stack, $token;
        }
    }
    
    &BuildInfo_die("Incorrect syntax of compile option condition \"$condition\"", __FILE__, __LINE__)
         unless (1 == @stack);

    # for single compile option
    my $ZeroString = "0"; $ZeroString = sprintf("%d", $ZeroString); # convert
    my $OneString = "1";  $OneString = sprintf("%d", $OneString);   # convert
    $stack[0] = (exist(BuildOPT::CMPL, $stack[0])?1:0) if($ZeroString ne $stack[0] && $OneString ne $stack[0]) ;
    
    #use above safer syntax
    #$stack[0] = (exist(BuildOPT::CMPL, $stack[0])?1:0) if("0" ne $stack[0] && "1" ne $stack[0]) ;

    return $stack[0];
}
#****************************************************************************
# subroutine:  _parseCompileOptionCondition
# description: Parse the feature option condition to postfix form.
# input:       Feature option condition, expression tree ref
# output:      Expression tree
# need init:   No
#****************************************************************************
sub _parseCompileOptionCondition
{
   my ($condition, $expressionTreeRef) = @_;
   my $conditionNoSpace = $condition;
   $conditionNoSpace =~ s/ //g;

   my @tokens = split(/(=|\(|\)|&&|\|\||!)/, $conditionNoSpace);
   my @stack;

   # For error checking
   my $parenthesis = 0;
   my $operand = 0;
   my $operator = 0;

   foreach my $token (@tokens)
   {
      if ($token eq "")
      {
         # Skip empty token
         next;
      }
      elsif ($token eq "(")
      {
         push @stack, $token;
         ++$parenthesis;
      }
      elsif ($token eq ")")
      {
         &BuildInfo_die("Incorrect syntax of compile option condition \"$condition\"", __FILE__, __LINE__)
            unless (0 < $parenthesis);
         my $temp = pop(@stack);

         while ($temp ne "(")
         {
            push @$expressionTreeRef, $temp;
            $temp = pop(@stack);
         }

         --$parenthesis;
      }
      elsif ($token eq "=" or $token eq "&&" or $token eq "||" or $token eq "!")
      {
         my $needLoop = 0;

         do
         {
            if (0 == scalar(@stack) or $stack[-1] eq "(")
            {
               # Stack is empty or stack top eqals to (
               push @stack, $token;
               $needLoop = 0;
            }
            elsif (0 < _compareCompileOptionOperator($stack[-1], $token))
            {
               # Stack top has higher priority than current token
               push @stack, $token;
               $needLoop = 0;
            }
            else
            {
               push @$expressionTreeRef, pop(@stack);
               $needLoop = 1;
            }
         } while ($needLoop);

         $operator += 1 unless ($token eq "!");
      }
      elsif ($token =~ /\w+/)
      {
         # Operand
         push @$expressionTreeRef, $token;
         $operand += 1;
      }
      else
      {
         &BuildInfo_die("Incorrect syntax of compile option condition \"$condition\"",  __FILE__, __LINE__);
      }
   }

   &BuildInfo_die("Incorrect syntax of compile option condition \"$condition\"", __FILE__, __LINE__)
      unless ($operator == ($operand - 1) and 0 == $parenthesis);

   push @$expressionTreeRef, reverse(@stack);
}

sub _compareCompileOptionOperator
{
   my $first = shift;
   my $second = shift;
   my %operatorToNumber = ("=" => 0, "!" => 1, "&&" => 2, "||" => 2);

   return $operatorToNumber{$first} <=> $operatorToNumber{$second};
}

#****************************************************************************
# subroutine: get
# Input:      $nOption: BuildOPT::CMPL or BuildOPT::REL
# Output:     In compiler option, if it's ooo=xxx, it returns xxx
#                                 otherwises, it returns undef
#             In release information, it returns value directly
#****************************************************************************
sub get
{
    my ($nOption, $strKey, $href) = @_;
    if (!defined $href)
    {
        $href = $g_CmplOpt_href if($nOption == BuildOPT::CMPL);
        $href = $g_RelInfo_href  if($nOption == BuildOPT::REL);  
    }
    &NoInfoMake_die($href, __FILE__, __LINE__);
    my $strValue = undef;
    if(exists $href->{$strKey})
    {
        $strValue = $href->{$strKey};
    }
    return $strValue;
}
#****************************************************************************
# subroutine: is
# Input:      $nOption: BuildOPT::CMPL or BuildOPT::REL
# Output:     1=$href->{$strKey} equals to $strValue, 0=not equal
#****************************************************************************
sub is
{
    my ($nOption, $strKey, $strValue, $href) = @_;
    if (!defined $href)
    {
        $href = $g_CmplOpt_href if($nOption == BuildOPT::CMPL);
        $href = $g_RelInfo_href  if($nOption == BuildOPT::REL);  
    }
    &NoInfoMake_die($href, __FILE__, __LINE__);
    my $bResult = 0;
    if(exists $href->{$strKey})
    {
        $bResult =1 if(lc($strValue) eq lc($href->{$strKey}));
    }
    return $bResult;
}
#****************************************************************************
# subroutine:  BuildInfo_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub BuildInfo_die
{
    my ($error_msg, $file, $line_no) = @_;
    &sysUtil::error_handler($error_msg, $file, $line_no, 'BuildInfoParser');    
}

sub NoInfoMake_die
{
    my ($temp_ref, $file, $line_no) = @_;
    &BuildInfo_die("Please parse infomake.log by BuildInfo::ParseInfoMakeLog() before using it.", $file, $line_no) 
        if(!defined $temp_ref);
}
