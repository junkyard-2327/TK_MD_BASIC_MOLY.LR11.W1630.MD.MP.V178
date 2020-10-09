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
#*   DspMapFileParser.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module is used for getting information from dsp map file. 
#*
#*
#* Author:
#* -------
#*   Carina Liao (mtk04017)
#*
#****************************************************************************/

use strict;
#use warnings;
BEGIN { push @INC, './l1core/tools/' }  # add additional library path
use L1coreCommonUtility; 
#use tools::pack_dep_gen;
#PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $MAPFILEPARSER_VERNO     = " v0.04_U3GDEV";
                              # v0.04_U3GDEV , 2013/11/27,  Refine 
                              # v0.03_U3GDEV , 2013/11/27,  Refine GetExtsramRWDataEnd()
                              # v0.02_U3GDEV , 2013/11/25,  Refine GetTCMInfo()
                              # v0.01_U3GDEV , 2013/11/22,  Add APIs for code integrity check
                              # v0.01 , 2013/06/06,  Initial revision

#****************************************************************************
# Constants
#****************************************************************************
package SymbolList;
use constant Base                 => 0;
use constant End                  => 1;
use constant Size                 => 2;
use constant ObjName              => 3;
use constant LibName              => 4;
use constant SymbolName           => 5;
use constant Type                 => 6;
use constant Scope                => 7;
use constant Section              => 8;
use constant Stack                => 9;
use constant Segment              => 10;

package SectionName;
use constant Bss                  => 0;
use constant Data                 => 1;
use constant Rodata               => 2;
use constant Text                 => 3;

package DspMapFileParser;

#****************************************************************************
# global variable
#****************************************************************************
my $g_MAPPath;
my $g_tclPath;

my %g_Memory;
my %g_File;
my %g_SymbolDetails;
my %g_CoproInfo;

my $g_SymbolCount = 0;
my $g_Total_bss = 0;
my $g_Total_data = 0;
my $g_Total_rodata = 0;
my $g_Total_text = 0;


#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# subroutine:  ParseMAP
# input:  MAP Path string     
# output: x     
#****************************************************************************
sub ParseMAP
{
    ($g_MAPPath) = (@_);
    if(defined $g_MAPPath and -e $g_MAPPath)
    {
        open (FILE_HANDLE, "<$g_MAPPath") or &MAP_die("[2.0]$g_MAPPath: file error!", __FILE__, __LINE__);
        #my $strPreExeRegionName = undef;
        my $strMemoryName = undef;
        my $strMemory = undef;
        my $bParseMemoryEnd = 0;
        my $bSymbolList = 0;
        my $bParseSummary = 0;
        my ($nMemorySize, $nMemoryWidth, $nMemoryOffset, $nMemoryUsed) = (0, 0, 0, 0);                
        while (<FILE_HANDLE>) 
        {
            my $strLine = $_;
            #print "$strLine\n";
            $bParseMemoryEnd = 0;
            $bSymbolList = 0;
            if(/^Memory\s+map\s+for\s+memory\s+\'(\w+)\':/)
            {
                $strMemoryName = $1;                
                #print "Memory = $strMemoryName\n";
                $nMemorySize = 0;
                $nMemoryWidth = 0;
                $nMemoryOffset = 0;
                $nMemoryUsed = 0;
            }
            #($nMemorySize, $nMemoryWidth, $nMemoryOffset, $nMemoryUsed) = &ParseMemoryInfo($strMemoryName) if(defined $strMemoryName);
            elsif(/\s+Size\s+\=\s+(\d+)/)
            {
            	  $nMemorySize = $1;
            	  #print "Size = $nMemorySize\n";
            }
            elsif(/\s+Width\s+\=\s+(\d+)\s+bits/)
            {
            	  $nMemoryWidth = $1;
            	  #print "Width = $nMemoryWidth\n";
            }
            elsif(/\s+Offset\s+\=\s+(\d+)/)
            {
            	  $nMemoryOffset = $1;
            	  #print "Offset = $nMemoryOffset\n";
            }
            elsif(/\s+Used\s+\=\s+(\d+)/)
            {
            	  $nMemoryUsed = $1;
            	  $bParseMemoryEnd = 1;
            	  #print "Used = $nMemoryUsed\n";
            }
            elsif(/\s+(\w+)\.\.\s*(\w+)\s*/)
            {
                $bSymbolList = 1;
            }
            elsif(/\s*Section\s+summary\s+for\s+(\w+)/)
            {
                $strMemory = $1;
            }
            elsif((defined $strMemory) and /(\w+)+\s+File/)
            {
                $bParseSummary = 1;
            }
            $g_Memory{$strMemoryName} = [$nMemorySize, $nMemoryWidth, $nMemoryOffset, $nMemoryOffset] if($bParseMemoryEnd == 1);
            &ParseSymbolList($strMemoryName, $strLine) if($bSymbolList == 1);
            &ParseSummary($strMemory, $strLine) if($bParseSummary == 1);
            
        }
        close FILE_HANDLE;   
        #print "bass = $g_Total_bss, data = $g_Total_data , rodata = $g_Total_rodata, text = $g_Total_text";
    }
    else
    {
        &MAP_die("[1.4]MAP Path($g_MAPPath) doesn't exist", __FILE__, __LINE__);   
    }      
}

#****************************************************************************
# subroutine:  ParseSummary
# input:       $strMemoryName: PMb/DMb
#              $strLine
# output:      x
#****************************************************************************
sub ParseSummary
{
    #print "InParseSummary\n";
    my ($strMemoryName, $strLine) = @_;
    if(/(.\w+)\s+(.\w+)*\s*(.\w+)*\s*Non merged total\s*/)
    {
        #492889        5776         544  Non merged total
        $g_Total_bss =    $1   if($strMemoryName eq "DMb");
        $g_Total_data =   $2   if($strMemoryName eq "DMb");
        $g_Total_rodata = $3   if($strMemoryName eq "DMb");
        $g_Total_text =   $1   if($strMemoryName eq "PMb");
    }
    elsif(/(.\w+)\s+(.\w+)*\s*(.\w+)*\s*(.\w+)*\s*(.\w+)*\s*Merged total\s*/)
    {
        #empty
    }
    elsif(/(.\w+)\s+(.\w+)*\s*(.\w+)*\s*(.\w+)*\s*(.\w+)*\s*/)
    {
    	  #empty
    }

    return 0;
     
}

#****************************************************************************
# subroutine:  ParseSymbolList
# input:       $strMemoryName: PMb/DMb
#              $strLine
# output:      x
#****************************************************************************
sub ParseSymbolList
{
    #print "InParseSymbolList\n";
    my ($strMemoryName, $strLine) = @_;
    return if(!defined $strMemoryName);

    my ($nBaseAddress, $nEndAddress, $nSize, $strObject, $strLibrary, $strSymbolName, $strType, $strScope, $strSectionName, $nStackFrameSize, $strSegment)
     = (0, 0, 0, undef, undef, undef, undef, undef, undef, 0, undef);
    my $bMatchSymbol = 0; 
        
    if(/\s+(\d+)\.\.\s*(\d+)\s*\(\s*(\d+)\s+items\)\s+:\s+(\w+.o)\s*\(\s*(.*)\)::(.*)\s+\((.*),\s+(.*),\s+(.*)\s*\)\s+\(stack frame size\s*=\s*(\d+)\)\s*(\(segment\s*=\s*(\w+)\))*/)
    {
        #0..       103 (   104 items) : boot.o(build/MT6280_BASIC/DEFAULT/bin/lib/libsys_drv.a)::ss_vic_table (Function, Global, .text.ss_vic_table) (stack frame size = 0) (segment = VIC_TABLE)
        $nBaseAddress = $1;
        $nEndAddress = $2;
        $nSize = $3;
        $strObject = $4;
        $strLibrary = $5;
        $strSymbolName = $6;
        $strType = $7;
        $strScope = $8;
        $strSectionName = $9;
        $nStackFrameSize = $10;
        $strSegment = $12;
        
        $bMatchSymbol = 1; 
        #print "[DspMapFileParser][Pattern 1]$strLine [Base]$nBaseAddress, [End]$nEndAddress, [Size]$nSize, [Obj]$strObject, [Lib]$strLibrary, [Symbol]$strSymbolName, [Type]$strType, [Scope]$strScope, [Section]$strSectionName, [StackFrameSize]$nStackFrameSize, [strSegment]$strSegment\n";
    }
    elsif(/\s+(\w+)\.\.\s*(\w+)\s*\(\s*(\d+)\s+items\)\s+:\s+(\w+.o)\s*\(\s*(.*)\)::(.*)\s+\((.*),\s+(.*),\s+(.*)\s*\)\s*\(segment\s*=\s*(\w+)\)/)
    {
        #1023396..   1023435 (    40 items) : tmk_globals.o(build/MT6280_BASIC/DEFAULT/bin/lib/libtmk.a)::tmk (Data, Global, .data.DMb.4) (segment = FAST_RW)
        $nBaseAddress = $1;
        $nEndAddress = $2;
        $nSize = $3;
        $strObject = $4;
        $strLibrary = $5;
        $strSymbolName = $6;
        $strType = $7;
        $strScope = $8;
        $strSectionName = $9;
        $strSegment = $10;
        
        $bMatchSymbol = 1; 
        #print "[DspMapFileParser][Pattern 2]$strLine [Base]$nBaseAddress, [End]$nEndAddress, [Size]$nSize, [Obj]$strObject, [Lib]$strLibrary, [Symbol]$strSymbolName, [Type]$strType, [Scope]$strScope, [Section]$strSectionName, [StackFrameSize]$nStackFrameSize, [strSegment]$strSegment\n";
    }
    elsif(/\s+(\w+)\.\.\s*(\w+)\s*\(\s*(\d+)\s+items\)\s+:\s+(\w+.o)\s*\(\s*(.*)\)::(.*)\s+\((.*),\s+(.*),\s+(.*)\s*\)/)
    {
        #1023396..   1023435 (    40 items) : tmk_globals.o(build/MT6280_BASIC/DEFAULT/bin/lib/libtmk.a)::tmk (Data, Global, .data.DMb.4) (segment = FAST_RW)
        $nBaseAddress = $1;
        $nEndAddress = $2;
        $nSize = $3;
        $strObject = $4;
        $strLibrary = $5;
        $strSymbolName = $6;
        $strType = $7;
        $strScope = $8;
        $strSectionName = $9;
        $strSegment = $10;
        
        $bMatchSymbol = 1; 
        #print "[DspMapFileParser][Pattern 3]$strLine [Base]$nBaseAddress, [End]$nEndAddress, [Size]$nSize, [Obj]$strObject, [Lib]$strLibrary, [Symbol]$strSymbolName, [Type]$strType, [Scope]$strScope, [Section]$strSectionName, [StackFrameSize]$nStackFrameSize, [strSegment]$strSegment\n";
    }
    if($bMatchSymbol == 1)
    {
        $g_SymbolDetails{$g_SymbolCount} = [$nBaseAddress, $nEndAddress, $nSize, $strObject, $strLibrary, $strSymbolName, 
                                          $strType, $strScope, $strSectionName, $nStackFrameSize, $strSegment];
        $g_SymbolCount++;
    }    
    return 0;
}

#****************************************************************************
# subroutine:  GetTotalTextSize - Get total text size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nTEXTSize/ $bNeedString=1:strTEXTSize
#****************************************************************************
sub GetTotalTextSize
{
    my ($bNeedString) = @_;
    return $bNeedString ? &L1coreCommonUtil::Dec2Hex($g_Total_text) : $g_Total_text; 
}

#****************************************************************************
# subroutine:  GetTotalBssSize - Get total bss size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nBSSSize/ $bNeedString=1:strBSSSize
#****************************************************************************
sub GetTotalBssSize
{
    my ($bNeedString) = @_;
    return $bNeedString ? &L1coreCommonUtil::Dec2Hex($g_Total_bss) : $g_Total_bss; 
}
#****************************************************************************
# subroutine:  GetTotalDataSize - Get total Data size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nDATASize/ $bNeedString=1:strDATASize
#****************************************************************************
sub GetTotalDataSize
{
    my ($bNeedString) = @_;
    return $bNeedString ? &L1coreCommonUtil::Dec2Hex($g_Total_data) : $g_Total_data; 
}
#****************************************************************************
# subroutine:  GetTotalRoDataSize - Get total rodata size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nRODATASize/ $bNeedString=1:strRODATASize
#****************************************************************************
sub GetTotalRoDataSize
{
    my ($bNeedString) = @_;
    return $bNeedString ? &L1coreCommonUtil::Dec2Hex($g_Total_rodata) : $g_Total_rodata; 
}

#****************************************************************************
# subroutine:  GetExtsramRWDataEnd (for calculating binary size)
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nLVSize/ $bNeedString=1:strLVSize
#****************************************************************************
sub GetExtsramRWDataEnd
{
    my ($bNeedString) = @_;
    $bNeedString = 0 if(!defined $bNeedString);
    my $nExtsramRWDataEnd = 0;
    my $nPadding = 0;
    my $LoadViewExtsramNonCachedRWDataEnd = 0;
    my $LoadViewDynExtsramDefaultNonCachedRWDataEnd = 0;
    my $LoadViewExtsramCachedRWDataEnd = 0;
    
    #[ToDo] Refine to support adding new RW region
    $nPadding = &GetPaddingForAlignment(&GetExtsramRODataEnd());
    $LoadViewExtsramNonCachedRWDataEnd = &GetExtsramRODataEnd() + &GetSegmentRegionSize("data","NONCACHEDRW") + $nPadding;
    #print "[DspMapFileParser]LoadViewExtsramNonCachedRWDataEnd = $LoadViewExtsramNonCachedRWDataEnd\n";
    
    $nPadding = &GetPaddingForAlignment($LoadViewExtsramNonCachedRWDataEnd);
    $LoadViewDynExtsramDefaultNonCachedRWDataEnd = $LoadViewExtsramNonCachedRWDataEnd + &GetSegmentRegionSize("data","DYNAMICCACHEABLERW_NC") + $nPadding;
    #print "[DspMapFileParser]LoadViewDynExtsramDefaultNonCachedRWDataEnd = $LoadViewDynExtsramDefaultNonCachedRWDataEnd\n";
    
    $nPadding = &GetPaddingForAlignment($LoadViewDynExtsramDefaultNonCachedRWDataEnd);
    $LoadViewExtsramCachedRWDataEnd = $LoadViewDynExtsramDefaultNonCachedRWDataEnd + &GetSegmentRegionSize("data","") + &GetSegmentRegionSize("data","CACHEDRW") + $nPadding;
    #print "[DspMapFileParser]LoadViewExtsramCachedRWDataEnd = $LoadViewExtsramCachedRWDataEnd\n";

    $nPadding = &GetPaddingForAlignment($LoadViewExtsramCachedRWDataEnd);
    $nExtsramRWDataEnd = $LoadViewExtsramCachedRWDataEnd + &GetSegmentRegionSize("data","DYNAMICCACHEABLERW_C") + $nPadding;

    #print "[DspMapFileParser]GetExtsramRODataEnd = ".&GetExtsramRODataEnd()."\n";
    #print "[DspMapFileParser]nExtsramRWDataEnd = $nExtsramRWDataEnd\n";
    return $bNeedString ? &CommonUtil::Dec2Hex($nExtsramRWDataEnd) : ($nExtsramRWDataEnd); 
}

sub GetPaddingForAlignment
{
    my ($nAddr) = @_;
    my $nPadding = 0;
    if(($nAddr % 4) != 3 )
    {
        $nPadding = (3 - ($nAddr % 4));
    }
    print "[DspMapFileParser]InGetPaddingForAlignment: nAddr = $nAddr, nPadding = $nPadding\n";
    return $nPadding;
}

#****************************************************************************
# subroutine:  GetExtsramRODataEnd (for calculating binary size)
# input:       -
# output:      $nLastRocodeAddr:last extsram rocode address
#****************************************************************************
sub GetExtsramRODataEnd
{
    my $nLastRocodeAddr = 0;
    foreach my $nIndex (0..$g_SymbolCount)
    {     
        my $strSection = $g_SymbolDetails{$nIndex}->[SymbolList::Section];
        my $strSegment = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];
        my $nEndAddr = $g_SymbolDetails{$nIndex}->[SymbolList::End];
        if(($strSection =~ /\.rodata/) or (($strSection =~ /\.data/) and ($strSegment eq "EXTSRAM_SHARE_BUFFER")))
        {
            $nLastRocodeAddr = $nEndAddr if($nEndAddr > $nLastRocodeAddr);
        }
    }
    return $nLastRocodeAddr;
}

#****************************************************************************
# subroutine:  GetIntsramROEnd (for calculating INTSRAM RO size in binary)
# input:       -
# output:      $nLastRodataAddr:last intsram rodata address
#****************************************************************************
sub GetIntsramROEnd
{
    my $nLastRodataAddr = 0;
    foreach my $nIndex (0..$g_SymbolCount)
    {
        my $strSegment = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];
        my $nEndAddr = $g_SymbolDetails{$nIndex}->[SymbolList::End];
        if(($strSegment =~ /^INTSRAM_RO/) or ($strSegment =~ /^FAST_RO/))
        {
            $nLastRodataAddr = $nEndAddr if($nEndAddr > $nLastRodataAddr);
        }
    }
    return $nLastRodataAddr;
}

#****************************************************************************
# subroutine:  GetExtsramROCodeBase (for calculating EXTSRAM RO size in binary)
# input:       -
# output:      $nFirstRocodeAddr:First intsram rocode address
#****************************************************************************
sub GetExtsramROCodeBase
{
    my $nFirstRocodeAddr = 0xFFFFFFFF;
    foreach my $nIndex (0..$g_SymbolCount)
    {
        my $strSection = $g_SymbolDetails{$nIndex}->[SymbolList::Section];
        my $strSegment = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];
        my $nBaseAddr = $g_SymbolDetails{$nIndex}->[SymbolList::Base];
        #the first symbol is always from assembly file, so ".text." can be used as matching pattern
        if(($strSection =~ /^\.text\./) and ($strSegment !~ /^INTSRAM_RO/) and ($strSegment !~ /^FAST_RO/))
        {
            $nFirstRocodeAddr = $nBaseAddr if($nBaseAddr < $nFirstRocodeAddr);
        }
    }
    return $nFirstRocodeAddr;
}

#****************************************************************************
# subroutine:  GetIntsramROSize (for code integrity)
# input:       -
# output:      $nIntsramRoSize: the total size of INTSRAM ROCODE/RODATA in Binary
#****************************************************************************
sub GetIntsramROSize
{
    my $nIntsramRoSize = 0;
    
    $nIntsramRoSize = GetIntsramROEnd() + 1;
    #INTSRAM ROCODE starts from 0x0, the INTSRAM RO size and the end address of INTSRAM RODATA add 1 is the same value
    return $nIntsramRoSize;
}

#****************************************************************************
# subroutine:  GetExtsramROSize (for code integrity)
# input:       -
# output:      $nIntsramRoSize: the total size of EXTSRAM ROCODE/RODATA in Binary
#****************************************************************************
sub GetExtsramROSize
{
    my $nExtsramRoSize = 0;
    
    my $nExtsramRoCodeBase = GetExtsramROCodeBase();
    my $nExtsramRoDataEnd = GetExtsramRODataEnd();
    $nExtsramRoSize = $nExtsramRoDataEnd - $nExtsramRoCodeBase + 1;
    return $nExtsramRoSize;
}

#****************************************************************************
# subroutine:  GetSegmentRegionSize (for calculating binary size)
# input:       -
# output:      nSize: the total size of a segment region
#****************************************************************************
sub GetSegmentRegionSize # only used for .data. and .bss. not for .text
{
    my ($SectionName, $SegmentName) = @_;
    my ($nFirstAddr, $nLastAddr) = (0xFFFFFFFF, 0);
    my $bMatched = 0;
    foreach my $nIndex (0..$g_SymbolCount)
    {
        my $nBase = $g_SymbolDetails{$nIndex}->[SymbolList::Base];
        my $nEndAddr = $g_SymbolDetails{$nIndex}->[SymbolList::End];
        my $strSection = $g_SymbolDetails{$nIndex}->[SymbolList::Section];
        my $strSegment = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];

        if($SegmentName eq "")
        {
            if(($strSection =~ /^\.$SectionName\./) and ($strSegment eq "$SegmentName"))
            {
                $nFirstAddr = $nBase if($nBase < $nFirstAddr);
                $nLastAddr = $nEndAddr if($nEndAddr > $nLastAddr);
                $bMatched = 1;        	
            }
        }
        else
        {
            if(($strSection =~ /^\.$SectionName\./) and ($strSegment =~ /^$SegmentName/))
            {
                $nFirstAddr = $nBase if($nBase < $nFirstAddr);
                $nLastAddr = $nEndAddr if($nEndAddr > $nLastAddr);
                $bMatched = 1;
            }
        }
    }
    my $nSize = ($nLastAddr - $nFirstAddr + 1);
    print "[DspMapFileParser][bMatched:$bMatched] InGetSegmentRegionSize: SectionName = $SectionName, SegmentName = $SegmentName, Size = $nLastAddr - $nFirstAddr + 1 = $nSize\n";   
    return ($bMatched) ? $nSize : 0;
}
#---------------------------------------------------------------------------------

#****************************************************************************
# subroutine:  GetTCMInfo
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $nTCM_bss, $nTCM_data, $nTCM_rodata, $nTCM_text
#****************************************************************************
sub GetTCMInfo
{
    my ($bNeedString) = @_;
    my ($nTCM_bss, $nTCM_data, $nTCM_rodata, $nTCM_text) = (0,0,0,0);
    foreach my $nIndex (0..$g_SymbolCount)
    {     
        my $SegmentName = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];
        my $Section = $g_SymbolDetails{$nIndex}->[SymbolList::Section];
        my $Size = $g_SymbolDetails{$nIndex}->[SymbolList::Size];

        if(($SegmentName =~ /^INTSRAM_/) or ($SegmentName =~ /^FAST_/))
        {
            $nTCM_bss += $Size if ($Section =~ /^\.bss\./);
            $nTCM_data += $Size if ($Section =~ /^\.data\./);
            $nTCM_rodata += $Size if ($Section =~ /^\.rodata\./);
            $nTCM_text += $Size if ($Section =~ /^\.text/);
        }
    }
    #$g_MemoryInfo{Memory::TCM} = [$nTCM_bss, $nTCM_data, $nTCM_rodata, $nTCM_text];
    return ($nTCM_bss, $nTCM_data, $nTCM_rodata, $nTCM_text);
}

#****************************************************************************
# subroutine:  GetExecViewRWZISize (reserved RW/ZI side for slave core)
# input:       -
# output:      Reserved size (includes padding between RW/ZI)
#****************************************************************************
sub GetExecViewRWZISize
{
    my ($nFirstRWZIDataAddr, $nLastRWZIDataAddr) = (0xFFFFFFFF, 0);
    my $nRWZISize = 0;
    my $bMatched = 0;
    foreach my $nIndex (0..$g_SymbolCount)
    {     
        my $strSection = $g_SymbolDetails{$nIndex}->[SymbolList::Section];
        my $nBase = $g_SymbolDetails{$nIndex}->[SymbolList::Base];
        my $nBaseAddress = ($nBase & 0x0FFFFFFF);
        my $nEndAddr = $g_SymbolDetails{$nIndex}->[SymbolList::End];
        my $nEndAddress = ($nEndAddr & 0x0FFFFFFF);
        my $strSegment = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];

        if(&IsExtsramRWZIRegion($strSegment, $strSection))
        {
            $nFirstRWZIDataAddr = $nBaseAddress if($nBaseAddress < $nFirstRWZIDataAddr);
            $nLastRWZIDataAddr = $nEndAddress if($nEndAddress > $nLastRWZIDataAddr);
            $bMatched = 1;
        }
    }
    $nRWZISize = ($nLastRWZIDataAddr - $nFirstRWZIDataAddr + 1);
    print "[DspMapFileParser]LastRWZIDataAddr  => $nLastRWZIDataAddr\n";
    print "[DspMapFileParser]FirstRWZIDataAddr => $nFirstRWZIDataAddr\n";
    return ($bMatched == 0) ? 0 : $nRWZISize;   
}

sub IsExtsramRWZIRegion
{
    my ($strSegmentName, $strSection) = @_;
    my $bIsIsExtsramRWZIRegion = 0;
    my @ExtsramSegmentPattern = ("NONCACHEDRW", "NONCACHEDZI", "CACHEDRW", "CACHEDZI", "DYNAMICCACHEABLEZI_NC", "DYNAMICCACHEABLERW_NC", "DYNAMICCACHEABLEZI_C", "DYNAMICCACHEABLERW_C");
    foreach my $Segment (@ExtsramSegmentPattern)
    {
        $bIsIsExtsramRWZIRegion = 1 if($strSegmentName =~ /^$Segment/);
    }
    $bIsIsExtsramRWZIRegion = 1 if ((($strSection =~ /^\.bss\./) or ($strSection =~ /^\.data\./)) and ($strSegmentName eq ""));

    return $bIsIsExtsramRWZIRegion;
}

#------------------------------------------------------------------------------
sub GetShareBufferSymbolList
{
    my ($Symbol_href) = @_;
    my $ShareBuffSymbol_count = 0;
    foreach my $nIndex (0..$g_SymbolCount)
    {     
        my $strSymbolName = $g_SymbolDetails{$nIndex}->[SymbolList::SymbolName];
        my $strSegmentName = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];
        my $nBaseAddr = $g_SymbolDetails{$nIndex}->[SymbolList::Base];
        if($strSegmentName eq "EXTSRAM_SHARE_BUFFER")
        {
            $Symbol_href->{$ShareBuffSymbol_count} = [$strSymbolName, $nBaseAddr];
            $ShareBuffSymbol_count++;
        }
    }
    return ($ShareBuffSymbol_count);
}

sub GetNoBinPaddingSegment
{
    my @PaddingSegment;
    my ($nTCMRwdata, $nNoncachedExtsramRwdata, $nDYN_DC_ExtsramRwdata, $nCachedExtsramRwdata, $nDYN_DNC_ExtsramRwdata) = (0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
    my $ntempAddr = 0;
    foreach my $nIndex (0..$g_SymbolCount)
    {
        my $strSymbolName = $g_SymbolDetails{$nIndex}->[SymbolList::SymbolName];
        my $strSegmentName = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];
        my $strSectionName = $g_SymbolDetails{$nIndex}->[SymbolList::Section];
        my $strBaseName = $g_SymbolDetails{$nIndex}->[SymbolList::Base];
        #[ToDo] put these nopadding segments in an array and simplify this function
        if(($strSectionName =~ /^\.data\./) and (($strSegmentName =~ /^FAST_RW/) or ($strSegmentName =~ /^INTSRAM_RW/)))
        {
            $nTCMRwdata = $strBaseName if ($strBaseName < $nTCMRwdata);
        }
        elsif(($strSectionName =~ /^\.data\./) and ($strSegmentName =~ /^NONCACHEDRW/))
        {
            $nNoncachedExtsramRwdata = $strBaseName if ($strBaseName < $nNoncachedExtsramRwdata);
        }
        elsif(($strSectionName =~ /^\.data\./) and ($strSegmentName =~ /^DYNAMICCACHEABLERW_NC/))
        {
            $nDYN_DC_ExtsramRwdata = $strBaseName if ($strBaseName < $nDYN_DC_ExtsramRwdata);
        }
        elsif(($strSectionName =~ /^\.data\./) and (($strSegmentName eq "") or ($strSegmentName =~ /^CACHEDRW/)))
        {
            $nCachedExtsramRwdata = $strBaseName if ($strBaseName < $nCachedExtsramRwdata);
        }
        elsif(($strSectionName =~ /^\.data\./) and ($strSegmentName =~ /^DYNAMICCACHEABLERW_C/))
        {
            $nDYN_DNC_ExtsramRwdata = $strBaseName if ($strBaseName < $nDYN_DNC_ExtsramRwdata);
        }
    }
    @PaddingSegment = (0, $nTCMRwdata, $nNoncachedExtsramRwdata, $nDYN_DC_ExtsramRwdata, $nCachedExtsramRwdata, $nDYN_DNC_ExtsramRwdata);
    return \@PaddingSegment;
}

sub GetTCMUsedSize
{
    my ($nFirstTCMAddr, $nLastTCMAddr) = (0xFFFFFFFF, 0);
    my $nTCMUsedSize;
    my $bMatched = 0;
    foreach my $nIndex (0..$g_SymbolCount)
    {     
        my $strSegmentName = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];
        my $nBaseAddr = $g_SymbolDetails{$nIndex}->[SymbolList::Base];
        my $nEndAddr = $g_SymbolDetails{$nIndex}->[SymbolList::End];

        if(($strSegmentName =~ /^INTSRAM_/) or ($strSegmentName =~ /^FAST_/))
        {
            $nFirstTCMAddr = $nBaseAddr if($nBaseAddr < $nFirstTCMAddr);
            $nLastTCMAddr = $nEndAddr if($nEndAddr > $nLastTCMAddr);
            $bMatched = 1;
        }
    }
    $nTCMUsedSize = ($nLastTCMAddr - $nFirstTCMAddr + 1);
    return ($bMatched == 0) ? 0 : $nTCMUsedSize;   
}

sub isZIdata
{
    my ($nPhysAddr) = @_;
    my $bIsZIdata = 0;
    my ($nFirstIntsramZIAddr, $nLastIntsramZIAddr) = (0xFFFFFFFF, 0);
    my ($nFirstNonCachedZIAddr, $nLastNonCachedZIAddr) = (0xFFFFFFFF, 0);

    foreach my $nIndex (0..$g_SymbolCount)
    { 
        my $nBase = $g_SymbolDetails{$nIndex}->[SymbolList::Base];
        my $nEndAddr = $g_SymbolDetails{$nIndex}->[SymbolList::End];
        
        my $strSegment = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];
        
            if(($strSegment =~ /^INTSRAM_ZI/) or ($strSegment =~ /^FAST_ZI/))
            {
                $nFirstIntsramZIAddr = $nBase if($nBase < $nFirstIntsramZIAddr);
                $nLastIntsramZIAddr = $nEndAddr if($nEndAddr > $nLastIntsramZIAddr);
            }
            elsif($strSegment =~ /^NONCACHEDZI/)
            {
                $nFirstNonCachedZIAddr = $nBase if($nBase < $nFirstNonCachedZIAddr);
                $nLastNonCachedZIAddr = $nEndAddr if($nEndAddr > $nLastNonCachedZIAddr);                
            }

            if((($nPhysAddr >= $nFirstIntsramZIAddr) and ($nPhysAddr <= $nLastIntsramZIAddr))
            or (($nPhysAddr >= $nFirstNonCachedZIAddr) and ($nPhysAddr <= $nLastNonCachedZIAddr)))
            {
                $bIsZIdata = 1;
            }
    }
    return $bIsZIdata;
}

sub isRootRegion #LoadView = ExecView
{
    my ($nPhysAddr) = @_;
    my $bIsRootRegion = 0;
    my $nExtsramROCODE_Base = 0xFFFFFFFF;
    my $nExtsramRODATA_Base = 0xFFFFFFFF;

    foreach my $nIndex (0..$g_SymbolCount)
    {
        my $strSegment = $g_SymbolDetails{$nIndex}->[SymbolList::Segment];
        my $strSectionName = $g_SymbolDetails{$nIndex}->[SymbolList::Section];
        my $nBase = $g_SymbolDetails{$nIndex}->[SymbolList::Base];
        #the first symbol is always from assembly file, so ".text." can be used as matching pattern
        if((($strSegment eq "") or ($strSegment =~ /^EXTSRAM_RO/)) and ($strSectionName =~ /^\.text\./))
        {
            $nExtsramROCODE_Base = $nBase if($nBase < $nExtsramROCODE_Base);
        }
        elsif((($strSegment eq "EXTSRAM_SHARE_BUFFER") and ($strSectionName =~ /^\.data\./)) or ((($strSegment eq "") or ($strSegment =~ /^EXTSRAM_RO/)) and ($strSectionName =~ /^\.rodata\./)))
        {
            $nExtsramRODATA_Base = $nBase if($nBase < $nExtsramRODATA_Base);
        }
    }
    #print "[DspMapFileParser]nExtsramROCODE_Base = $nExtsramROCODE_Base, nExtsramRODATA_Base = $nExtsramRODATA_Base\n";
    $bIsRootRegion = 1 if(($nPhysAddr == $nExtsramROCODE_Base) or ($nPhysAddr == $nExtsramRODATA_Base));

    return $bIsRootRegion;
}

sub GetFileNameFromSymbol
{
    my ($strSymbol) = @_;
    my $strFileName = undef;
    foreach my $nIndex (0..$g_SymbolCount)
    { 
        my $strSymbolName = $g_SymbolDetails{$nIndex}->[SymbolList::SymbolName];
        if($strSymbol eq $strSymbolName)
        {
            $strFileName = $g_SymbolDetails{$nIndex}->[SymbolList::ObjName];
        }
    }
    return $strFileName;
}

#****************************************************************************
# subroutine:  MAP_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub MAP_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &L1coreCommonUtil::error_handler($error_msg, $file, $line_no, 'DspMapFileParser');    
}
