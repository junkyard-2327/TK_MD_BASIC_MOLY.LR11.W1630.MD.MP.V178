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
#*   DspBinaryCreate.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This sciprt is used for generating DSP binary file. 
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
use DspMapFileParser;
use ElfSegmentParser;
use tclInfo;
#use tools::pack_dep_gen;
#PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $DSPBINARYCREATE_VERNO     = " v0.01";
                                # v0.01 , 2013/07/04,  Initial revision

#****************************************************************************
# Input
#****************************************************************************
my $TCL_FILE          = $ARGV[0];
my $MAP_FILE          = $ARGV[1];
my $ELF_FILE          = $ARGV[2];
my $READELF_FILE      = $ARGV[3];
my $OUTPUT_BIN_FILE   = $ARGV[4];

#****************************************************************************
# Global Variables
#****************************************************************************
my $g_ElfInfo_href;
my $g_nElfInfoCount = 0;
my $g_noPaddingSegment_aref;
my $g_DSPtclInfo;
my $g_nBinaryAddr;

#****************************************************************************
# >>>  Main Flow
#****************************************************************************

#1. Parse the output file of ELF to get the segment information
ElfSegmentParser::ParseReadElf($READELF_FILE);
($g_nElfInfoCount, $g_ElfInfo_href) = ElfSegmentParser::GetReadElfInfo();

#2. Parse Map File
DspMapFileParser::ParseMAP($MAP_FILE);
$g_noPaddingSegment_aref = DspMapFileParser::GetNoBinPaddingSegment();
#print "g_noPaddingSegment_aref = $g_noPaddingSegment_aref->[0], $g_noPaddingSegment_aref->[1], $g_noPaddingSegment_aref->[2], $g_noPaddingSegment_aref->[3]\n";

#3. Parse tcl File
$g_DSPtclInfo = new tclInfo;
$g_DSPtclInfo->ParseLinkerScript($TCL_FILE);
$g_nBinaryAddr = $g_DSPtclInfo->GetPreDefinedBaseAddr(tclInfo::DSP_COPRO_LV_BASE);

#4. Start to Create Binary file

if(defined $ELF_FILE and -e $ELF_FILE)
{
    &CreatBinaryFile();
}
else
{
    &dspbinarycreate_die("[1.4]ELF Path($ELF_FILE) doesn't exist", __FILE__, __LINE__);   
}



exit 0;

#****************************************************************************
# Subroutines
#****************************************************************************
sub CreatBinaryFile
{
    unlink $OUTPUT_BIN_FILE if(defined $OUTPUT_BIN_FILE and -e $OUTPUT_BIN_FILE);
    my ($nPhysAddr, $nPrevEndAddr, $nFileSize, $nOffset, $nPaddingNum, $BinFileCurrentSize) = (0, 0, 0, 0, 0, 0);  
    my $bNeedPadding = 0;
    my $Buffer = undef;
    my @FileStat;

    foreach my $nIndex (0..$g_nElfInfoCount)
    {
        $nPhysAddr = $g_ElfInfo_href->{$nIndex}->[SegmentList::PhysAddr];
        $nFileSize = $g_ElfInfo_href->{$nIndex}->[SegmentList::FileSize];
        $nOffset   = $g_ElfInfo_href->{$nIndex}->[SegmentList::Offset];
        $bNeedPadding = 0;
        $nPaddingNum = 0;      
        
        next if (($nFileSize == 0) or DspMapFileParser::isZIdata($nPhysAddr)); #nFileSize = 0 or has ZI pragma -> ZI region
        #print "PhysAddr = $nPhysAddr, FileSize = $nFileSize, Offset = $nOffset\n";

        #Get Semgment in Readelf output file
        open (FILE_HANDLE, "<$ELF_FILE") or &dspbinarycreate_die("[2.0]$ELF_FILE: file error!", __FILE__, __LINE__);
        binmode FILE_HANDLE;
        seek FILE_HANDLE,$nOffset,0;
        read FILE_HANDLE, $Buffer, $nFileSize;
        close FILE_HANDLE;
        
        #Get Binary file current size
        @FileStat = stat "$OUTPUT_BIN_FILE";
        $BinFileCurrentSize = $FileStat[7];
        
        ($bNeedPadding, $nPaddingNum) = NeedToAddPadding($nPhysAddr, $nPrevEndAddr, $BinFileCurrentSize);
        
        WriteToBinary($bNeedPadding, $Buffer, $nPaddingNum);

        $nPrevEndAddr = $nPhysAddr + $nFileSize - 1;
    }
    #binary should be 4byte aligned
    @FileStat = stat "$OUTPUT_BIN_FILE";
    $BinFileCurrentSize = $FileStat[7];
    AddPaddingForAlignment($BinFileCurrentSize);
}

sub WriteToBinary
{
    my ($bNeedPadding, $Buffer, $nPaddingNum) = @_;
    open (BIN_NEW, ">>$OUTPUT_BIN_FILE") or &dspbinarycreate_die("[2.0]$OUTPUT_BIN_FILE: file error!", __FILE__, __LINE__);
    binmode BIN_NEW;
    
    if($bNeedPadding == 1)
    {
        print BIN_NEW pack("c[$nPaddingNum]",0);
        print BIN_NEW $Buffer;
        close BIN_NEW;
    }
    else
    {
        print BIN_NEW $Buffer;
        close BIN_NEW;
    }
}

sub NeedToAddPadding
{
    my ($nPhysAddr, $nPrevEndAddr, $nFileTotalSize) = @_;
    my $bNeedPadding = 1;
    my $nPaddingNum = 0;
    foreach my $nPaddingSeg (@$g_noPaddingSegment_aref)
    {
        if($nPhysAddr == $nPaddingSeg)
        {
            if((($nFileTotalSize % 4) == 0) or ($nPhysAddr == 0))
            {
                $bNeedPadding = 0;
                print "NoNeedPadding_Addr: $nPhysAddr\n";
            }
            else
            {
                $nPaddingNum = 4 - ($nFileTotalSize % 4); 
                print "NoNeedPadding_Addr(Padding for region init): nPhysAddr = $nPhysAddr, nPaddingNum = $nPaddingNum\n";
            }
            return ($bNeedPadding, $nPaddingNum);
        }
    }
    $nPaddingNum = $nPhysAddr - $nPrevEndAddr - 1;
    #print "[CommonRegion]nPhysAddr = $nPhysAddr , nPrevEndAddr = $nPrevEndAddr, g_nBinaryAddr = $g_nBinaryAddr, nFileTotalSize = $nFileTotalSize\n";
    if(&DspMapFileParser::isRootRegion($nPhysAddr))
    {
        print "[RootRegion]nPhysAddr = $nPhysAddr , nPrevEndAddr = $nPrevEndAddr, g_nBinaryAddr = $g_nBinaryAddr, nFileTotalSize = $nFileTotalSize\n";
        $nPaddingNum = ($nPhysAddr - $g_nBinaryAddr - $nFileTotalSize);
    }
    print "[NeedPadding]$bNeedPadding  [nPaddingNum]$nPaddingNum\n";
    &dspbinarycreate_die("[2.0]Padding can not be nagtive number, please contact autoGen owner!", __FILE__, __LINE__) if(($bNeedPadding == 1) && ($nPaddingNum < 0));
    return ($bNeedPadding, $nPaddingNum);
}

sub AddPaddingForAlignment
{
    my ($BinFileCurrentSize) = @_;
    my $nPadding = $BinFileCurrentSize % 4;
    my $AddLastPadding = 0;
    return if($nPadding == 0); #no need to add padding

    $AddLastPadding = (4 - $nPadding);
    print "AddLastPadding = $AddLastPadding\n";
    open (BIN_NEW, ">>$OUTPUT_BIN_FILE") or &dspbinarycreate_die("[2.0]$OUTPUT_BIN_FILE: file error!", __FILE__, __LINE__);
    binmode BIN_NEW;
    print BIN_NEW pack("c[$AddLastPadding]",0);
    close BIN_NEW;

}
sub dspbinarycreate_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    &L1coreCommonUtil::error_handler($error_msg, $file, $line_no, 'DSP_BINARY_CREATE'); 
}
