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
#*   tclInfo.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to parse LinkerScript (tcl script)
#*
#* Author:
#* -------
#*   Carina Liao (mtk04017)
#*
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './l1core/tools/' }  # add additional library path
use L1coreCommonUtility;
use L1coreSysGenUtility;

#****************************************************************************
# Constants
#****************************************************************************
package tclInfo;

use constant DSP_COPRO_LV_BASE              => "BINARY_BASE";
use constant INTSRAM_CODE_BASE              => "INTSRAM_CODE_BASE";
use constant DSP_COPRO_RWZI_BASE            => "NONCACHED_EXTSRAM_RW_BASE";
use constant MASTER_DYN_DNC_SHARED_BUFF_BASE        => "DYN_DNC_MASTER_SHARED_BUFF_BASE";
use constant MASTER_DYN_DNC_SHARED_BUFF_END         => "DYN_DNC_MASTER_SHARED_BUFF_END";
use constant MASTER_DYN_DNC_SHARED_BUFF_LENGTH      => "DYN_DNC_MASTER_SHARED_BUFF_LENGTH";
use constant MASTER_NC_SHARED_BUFF_BASE             => "NC_MASTER_SHARED_BUFF_BASE";
use constant MASTER_NC_SHARED_BUFF_END              => "NC_MASTER_SHARED_BUFF_END";
use constant MASTER_NC_SHARED_BUFF_LENGTH           => "NC_MASTER_SHARED_BUFF_LENGTH";
#****************************************************************************
# Global Variables
#****************************************************************************
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# tclInfo Version
#****************************************************************************
sub tclInfo_verno
{
    return " v0.03_U3GDEV";
           # v0.03_U3GDEV , 20131127 by Carina, support parsing input sections
           # v0.02_U3GDEV , 20131118 by Carina, support sysgen2
           # v0.01_U3GDEV , 20131111 by Carina, rename EXTSRAM_RW_BASE to NONCACHED_EXTSRAM_RW_BASE
           # v0.01 , 20130504 by Carina, initial version
}

sub new
{
    my $class = shift;
    my $self = {};
    #default value
    $self->{BaseAddr} = undef;
    $self->{BaseAddrInfo} = undef;
    $self->{ExeRegion} = undef;
    $self->{ExeRegionCount} = 0;        #$g_ExeRegionCount = 0;
    $self->{ExeRegionLookUpTable} = {}; #%g_ExeRegionLookUpTable; # RegionName -> Index
    $self->{InputSection} = {}; # $self->{InputSection}{$strRegionName} = @InputSections;
    $self->{SharedBuffRegion} = undef;
    $self->{SharedBuffRegionCount} = 0;
    $self->{SharedBuffRegionLookUpTable} = {};
    $self->{Pragma} = undef;
    bless $self, $class;
    return $self;
}

#****************************************************************************
# subroutine:  GetPreDefinedBaseAddr
# input:       $strkey: the region name
# output:      the base address of the input region 
#****************************************************************************
sub GetPreDefinedBaseAddr
{
    my $self = shift;
    my ($strkey) = @_;
    my $nBaseAddr = 0;

    $nBaseAddr = $self->{BaseAddrInfo}->{$strkey};

    return $nBaseAddr;
}

#****************************************************************************
# subroutine:  GetAllExeRegion
# input:       x
# output:      an array reference of execution region 
#****************************************************************************
sub GetAllExeRegion
{
    my $self = shift;
    my @ExeRegions;
    foreach my $i (1 .. $self->{ExeRegionCount})
    {
        push(@ExeRegions, $self->{ExeRegion}{$i}->[0]);
    }
    return \@ExeRegions;
}

#****************************************************************************
# subroutine:  GetInputSectionsByRegion
# input:       x
# output:      an array reference of input sections
#****************************************************************************
sub GetInputSectionsByRegion
{

    my $self = shift;
    my ($strRegionName) = @_;
    return \@{$self->{InputSection}{$strRegionName}}
}
#****************************************************************************
# subroutine:  GetDYNAMIC_DNC_SharedBuffRegion
# input:       x
# output:      an array reference of DYN shared buffer regions 
#****************************************************************************
sub GetDYNAMIC_DNC_SharedBuffRegion
{
    my $self = shift;
    
    my $Regions_aref = $self->GetAllSharedBuffRegion();
    my @region = grep(/DYN\_DNC/, @$Regions_aref);
    return \@region;
}

#****************************************************************************
# subroutine:  GetAllSharedBuffRegion
# input:       x
# output:      an array reference of execution region 
#****************************************************************************
sub GetAllSharedBuffRegion
{
    my $self = shift;
    my @SharedBuffRegions;
    foreach my $i (1 .. $self->{SharedBuffRegionCount})
    {
        push(@SharedBuffRegions, $self->{SharedBuffRegion}{$i}->[0]);
    }
    return \@SharedBuffRegions;
}

#---------------------------------------------------------------------------
sub ParseLinkerScript
{
    my $self = shift;
    my ($tclPath) = @_;

    if(defined $tclPath and -e $tclPath)
    {
        open (FILE_HANDLE, "<$tclPath") or &tcl_die("[1.4]$tclPath: file error!", __FILE__, __LINE__);
        my $strStart = undef;
        while (<FILE_HANDLE>) 
        {
            #print "$_\n";
            #set LV_BASE                "0x0000e000"
            if(/\# Pre-defined BASE/)
            {
                $strStart = "BaseAddr";
            }
            elsif(/# Pre-defined PRAGMA/)
            {
                $strStart = "Pragma";
            }
            elsif(/# Start To/)
            {
                $strStart = "RegionBlock";	
            }
            elsif(/# Create Shared Buff Linker Symbol/)
            {
                $strStart = "SharedBuffSymbol";	
            }
            elsif(/^# /)
            {
                undef $strStart;    
            }
            elsif(defined $strStart)
            {
                $self->{$strStart} .= $_;
            }
        }
        close FILE_HANDLE;
        $self->{BaseAddrInfo} = &ParseBaseAddr($self->{BaseAddr});
        $self->ParseRegion($self->{RegionBlock});
        $self->ParseSharedBuffRegion($self->{SharedBuffSymbol});
    }
    else
    {
        &tcl_die("[1.4]LinkerScript Path($tclPath) doesn't exist", __FILE__, __LINE__);   
    }
}

sub ParseBaseAddr
{
    my ($strBaseAddr) = @_;
    my %BaseAddrInfo;
    my @lines = split(/\n/, $strBaseAddr);
    my ($strName, $strBase);
    foreach my $line (@lines) 
    {
        my ($strName, $strBase) = &ParseBaseAddrLine($line);
        $BaseAddrInfo{$strName} = hex($strBase) if(defined $strName);
    }
    return \%BaseAddrInfo;
}

sub ParseBaseAddrLine
{
    my ($strLine) = @_;
    my ($strName, $strBase) = (undef, undef);
    if($strLine =~ /^set\s+(\w+)\s+\"(\w+)\"/)
    {
        $strName = $1;
        $strBase = $2;
    }
    return ($strName, $strBase);
}

sub ParseRegion
{
    my $self = shift;
    my ($strRegion) = @_;
    my @lines = split(/\n/, $strRegion);
    my $strRegionName;
    map {$self->parse_linker_symbol($_)} @lines;

    foreach my $line (@lines) 
    {

        if($line =~ /#-+(\w+)-+/)
        {
            $strRegionName = $1;
        }
        elsif($line =~ /map_seg_all/ or $line =~/bridge::map_symbol/)
        {
            $self->parse_input_section($line, $strRegionName);
        }
    }
    return 0;
}

sub parse_input_section #used by ParseRegion
{
    my $self = shift;
    my ($strLine, $strRegionName)= @_;

    if($strLine =~ /bridge::map_symbol\s+\[bridge::symbol\s+(\w+)\]/)
    {
        push(@{$self->{InputSection}{$strRegionName}}, $1);
    }
    elsif( $strLine =~ /map_seg_all\s+\$(\w+)\s+(\{\w+\})\s+/)
    {
        push(@{$self->{InputSection}{$strRegionName}}, $2);
    }
}

sub ParseSharedBuffRegion
{
    my $self = shift;
    my ($strRegion) = @_;
    my @lines = split(/\n/, $strRegion);
    map {$self->Parse_SharedBuff_Linker_Symbol($_)} @lines;
    foreach my $line (@lines) 
    {
        if( $line =~ /Image__(\S+)__(\S+)\s+\$(\S+)/)
        {
            my ($strRegionName, $strIndexName, $strIndexValue) = ($1, $2, $3);
            my $nIndex = $self->{SharedBuffRegionLookUpTable}{$strRegionName};
            if($strIndexName =~ /Base/)
            {
                my $strBase = $self->GetPreDefinedBaseAddr($strIndexValue);
                $self->{SharedBuffRegion}->{$nIndex}->[1] = $strBase;
            }
            if($strIndexName =~ /End/)
            {
                my $strEnd = $self->GetPreDefinedBaseAddr($strIndexValue);
                $self->{SharedBuffRegion}->{$nIndex}->[2] = $strEnd;
            }
            if($strIndexName =~ /Length/)
            {
                my $strLength = $self->GetPreDefinedBaseAddr($strIndexValue);
                $self->{SharedBuffRegion}->{$nIndex}->[3] = $strLength;
            }
        }
    }
    return 0;
}

sub parse_linker_symbol #used by ParseRegion
{
    my $self = shift;
    my ($strLine) = @_;
    if( $strLine =~ /Image__(\S+)__(\S+)/)
    {
        my ($strRegionName, $strBase, $strOffset, $nMaxSize, @Attr) = ($1, undef, "+0x0", undef, ());
        my$strIndexName = $2;
        if(!exists $self->{ExeRegionLookUpTable}{$strRegionName})
        {
            $self->{ExeRegion}->{++$self->{ExeRegionCount}} = [$strRegionName, $strBase, $strOffset, $nMaxSize, \@Attr];
            $self->{ExeRegionLookUpTable}{$strRegionName} = $self->{ExeRegionCount};
        }
    }
}

sub Parse_SharedBuff_Linker_Symbol
{
    my $self = shift;
    my ($strLine) = @_;
    if( $strLine =~ /Image__(\S+)__(\S+)\s+\$(\S+)/)
    {
        my ($strRegionName, $strBase, $strEnd, $strLength) = ($1, undef, undef, undef);
        if(!exists $self->{SharedBuffRegionLookUpTable}{$strRegionName})
        {
            $self->{SharedBuffRegion}->{++$self->{SharedBuffRegionCount}} = [$strRegionName, $strBase, $strEnd, $strLength];
            $self->{SharedBuffRegionLookUpTable}{$strRegionName} = $self->{SharedBuffRegionCount};
        }
    }	
}

#****************************************************************************
# subroutine:  ClassifyRegionType
# input:       x
# return:      x
#RegionType = INTSRAM, DYNAMIC_DNC, DYNAMIC_DC, CACHED_RO, CACHED_RW, NONCACHED_RO, NONCACHED_RW;
#****************************************************************************
sub ClassifyRegionType
{
    my $self = shift;
    foreach (keys %{$self->{ExeRegionLookUpTable}})
    {
        #if-else order is important (this order is related to image layout)
        if(/DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE/)
        {
            $self->add_region_into_group("DYNAMIC_DNC", $_); next;
        }
        elsif(/DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE/)
        {
            $self->add_region_into_group("DYNAMIC_DC", $_); next;
        }
        elsif(/^EXTSRAM_CODE$/ or /^EXTSRAM_RO/)
        {
            $self->add_region_into_group("CACHED_RO", $_); next;
        }
        elsif(/NONCACHED/)
        {
            $self->add_region_into_group("NONCACHED_RW", $_); next;
        }
        elsif(/CACHED/)
        {
            $self->add_region_into_group("CACHED_RW", $_); next;
        }
        elsif(/INTSRAM/)
        {
             $self->add_region_into_group("INTSRAM", $_); next;
        }
    }
}
sub add_region_into_group #used by ClassifyRegionType
{
    my $self = shift;
    my ($strKey, $strRegionName) = @_;
    if(exists $self->{RegionGroup}{$strKey})
    {
        my $temp_ref = $self->{RegionGroup}{$strKey};
        push(@$temp_ref, $strRegionName);
        #print $_ ."\n" foreach (@$temp_ref);
    }
    else
    {
        $self->{RegionGroup}{$strKey}= [$strRegionName];
    }
}

#****************************************************************************
# subroutine:  GetGroupedRegions
# input:       $strKey:
# RegionType = INTSRAM, DYNAMIC_DNC, DYNAMIC_DC, CACHED_RO, CACHED_RW, NONCACHED_RO, NONCACHED_RW;
#              MBA, MULTIROM, EXTCODE, MCU_C_DSP_C, MCU_C_DSP_NC, MCU_NC_DSP_C,MCU_NC_DSP_NC
# output:      array_ref:  #[[Region1], [Region3, Region4], [Region6]] in order
#****************************************************************************
sub GetGroupedRegions
{
    my $self = shift;
    #RegionType = INTSRAM, DYNAMIC_DNC, DYNAMIC_DC, CACHED_RO, CACHED_RW, NONCACHED_RO, NONCACHED_RW;
    my ($strKey) = @_;
    my @CombinedRegions = (); #[[Region1], [Region3, Region4], [Region6]]
    if(exists $self->{RegionGroup}{$strKey})
    {
            my $temp_ref = $self->{RegionGroup}{$strKey};
            my @temp = map{ $self->{ExeRegionLookUpTable}->{$_} } @$temp_ref ;
            my @Sort_temp = sort {$a <=> $b} @temp;
            
            my ($nPreviousIndex, $nIndex) = (-1,0);
            foreach(@Sort_temp)
            {
                my $strRegionName = $self->{ExeRegion}->{$_}->[0];
                my ($bIsFixed, $strFixedLength) = $self->IsFixedLengthRegion($strRegionName);
                if(($nPreviousIndex+1 == $_) and ($bIsFixed == 0)) #non fixed region or not load region
                {
                    my $array = $CombinedRegions[$nIndex-1];
                    push(@$array , $strRegionName);
                }
                else
                {
                    push(@CombinedRegions, [ $strRegionName ]);
                    $nIndex++;
                }
                $nPreviousIndex = $_;
            }
    }
    #map {print "[$strKey]Combination:".$_->[0]."\n"} @CombinedRegions;
    return \@CombinedRegions;
}

#****************************************************************************
# subroutine:  IsFixedLengthRegion
#              to see if its size needs to be fixed
# input:       RegionName
# output:      1. $bIsFixed: 0=not fixed, 1= fixed
#****************************************************************************
sub IsFixedLengthRegion
{
    my $self = shift;
    my ($strRegionName) = @_;
    my $bIsFixed = 0;
    my $strFixedLength = 0;
    my @FixedLenPattern = ();
    foreach my $strPattern (@FixedLenPattern)
    {
        if($strRegionName =~ /$strPattern/)
        {
            $bIsFixed = 1;
            last;
        }
    }
    return ($bIsFixed, $strFixedLength);
}
#****************************************************************************
# subroutine:  tcl_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub tcl_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &L1coreCommonUtil::error_handler($error_msg, $file, $line_no, 'tclInfo');    
}
