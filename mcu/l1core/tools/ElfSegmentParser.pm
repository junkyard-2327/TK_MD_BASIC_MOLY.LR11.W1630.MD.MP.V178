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
#*   ElfSegmentParser.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module is used for getting information in readelf ouput file. 
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
my $ELFSEGMENTPARSER_VERNO     = " v0.01";
                                 # v0.01 , 2013/07/02,  Initial revision
                              
#****************************************************************************
# Constants
#****************************************************************************
my $g_ElfPath;
my %g_PragramHeaderInfo;
my @g_aPragramHeaderInfo;
my $g_SegmentCount = 0;

package SegmentList;
use constant Type                  => 0;
use constant Offset                => 1;
use constant VirtAddr              => 2;
use constant PhysAddr              => 3;
use constant FileSize              => 4;
use constant MemSize               => 5;


package ElfSegmentParser;

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# subroutine:  ParseMAP
# input:  MAP Path string     
# output: x     
#****************************************************************************
sub ParseReadElf
{
    ($g_ElfPath) = (@_);
    my $bMatch;
    my $strLine;
    if(defined $g_ElfPath and -e $g_ElfPath)
    {

        my ($strType, $nOffset, $nVirtAddr, $nPhysAddr, $nFileSize, $nMemSize) = (undef, 0,0,0,0,0);
        open (FILE_HANDLE, "<$g_ElfPath") or &ReadElf_die("[2.0]$g_ElfPath: file error!", __FILE__, __LINE__);
        while (<FILE_HANDLE>) 
        {
            $strLine = $_;
            $bMatch = 0;
            if(/\s+(\w+)\s+(0x\w+)\s+(0x\w+)\s+(0x\w+)\s+(0x\w+)\s+(0x\w+)\s+(\w+)\s+(\d+)/)
            {
                #  LOAD           0x195793 0x00002000 0x00002000 0x0000c 0x0000c R   0
                #print "[Pattern 1]$strLine [Base]$nBaseAddress, [End]$nEndAddress, [Size]$nSize, [Obj]$strObject, [Lib]$strLibrary, [Symbol]$strSymbolName, [Type]$strType, [Scope]$strScope, [Section]$strSectionName, [StackFrameSize]$nStackFrameSize, [strSegment]$strSegment\n";
                $strType      = $1;
                $nOffset      = hex($2);
                $nVirtAddr    = hex($3);
                $nPhysAddr    = hex($4);
                $nFileSize    = hex($5);
                $nMemSize     = hex($6);

                $bMatch = 1;
                #print "[Pattern 1]$strLine [Type]$strType, [Offset]$nOffset, [VirtAddr]$nVirtAddr, [PhysAddr]$nPhysAddr, [FileSize]$nFileSize, [MemSize]$nMemSize\n";
            }
            elsif(/(\w+)\s+(0x\w+)\s+(0x\w+)\s+(0x\w+)\s+(0x\w+)\s+(0x\w+)\s+(\w+)\s+(\w+)\s+(\d+)/)
            {
                #  LOAD           0x19702a 0x00000000 0x00000000 0x00074 0x00074 R E 0
                $strType      = $1;
                $nOffset      = hex($2);
                $nVirtAddr    = hex($3);
                $nPhysAddr    = hex($4);
                $nFileSize    = hex($5);
                $nMemSize     = hex($6);

                $bMatch = 1;
                #print "[Pattern 2]$strLine [Type]$strType, [Offset]$nOffset, [VirtAddr]$nVirtAddr, [PhysAddr]$nPhysAddr, [FileSize]$nFileSize, [MemSize]$nMemSize\n";
            }
            if($bMatch == 1)
            {
                #$g_PragramHeaderInfo{$g_SegmentCount} = [$strType, $nOffset, $nVirtAddr, $nPhysAddr, $nFileSize, $nMemSize];
                push (@g_aPragramHeaderInfo, [$strType, $nOffset, $nVirtAddr, $nPhysAddr, $nFileSize, $nMemSize]);
                #push (@{$g_InputSections{$strMemoryName}}, $g_SymboCount);
                $g_SegmentCount++;
                #print "[$g_SegmentCount]$strLine\n";
            } 
        }

        close FILE_HANDLE;
    }
    else
    {
        &ReadElf_die("[1.4]ELF Path($g_ElfPath) doesn't exist", __FILE__, __LINE__);   
    }
    SortPragramHeaderInfo();
}

#Sort Info by nPhysAddr
sub SortPragramHeaderInfo
{   
	  @g_aPragramHeaderInfo = sort { $a->[SegmentList::PhysAddr] <=> $b->[SegmentList::PhysAddr] } @g_aPragramHeaderInfo;
    foreach my $index (0..$g_SegmentCount) {
        $g_PragramHeaderInfo{$index} = shift(@g_aPragramHeaderInfo);
    }
}

sub GetOffsetInElf
{
    my ($nAddr) = @_;
    my $nPhysAddr = 0;
    my $nOffset = 0;
    my $nPrevPhysAddr = 0xFFFFFFFF;
    my $nSegmentBase = 0xFFFFFFFF;
    my $nAddrInElf = 0xFFFFFFFF;
    foreach my $nIndex (0..$g_SegmentCount)
    {     
        
        $nPhysAddr = $g_PragramHeaderInfo{$nIndex}->[SegmentList::PhysAddr];
        #print "[$nIndex] nAddr = $nAddr, nPhysAddr = $nPhysAddr, nPrevPhysAddr = $nPrevPhysAddr\n";
        if(($nAddr >= $nPrevPhysAddr) && ($nAddr < $nPhysAddr))
        {
           $nSegmentBase = $g_PragramHeaderInfo{$nIndex - 1}->[SegmentList::Offset];
           $nOffset = $nAddr - $nPrevPhysAddr;
           last;
        }
        $nPrevPhysAddr = $nPhysAddr;
    }
    #print "nSegmentBase = $nSegmentBase, nOffset = $nOffset\n";
    $nAddrInElf = $nSegmentBase + $nOffset;
    return ($nAddrInElf);
}

sub GetReadElfInfo
{  
    return ($g_SegmentCount, \%g_PragramHeaderInfo);
}
#****************************************************************************
# subroutine:  ReadElf_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub ReadElf_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &L1coreCommonUtil::error_handler($error_msg, $file, $line_no, 'ELF_SEGMENT_PARSER');    
}
