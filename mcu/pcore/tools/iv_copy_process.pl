#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2011
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
#
#*****************************************************************************
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 01 20 2015 raymondwt.chen
#* [MOLY00092726] [TK6291] [SystemService][Auto-Gen] Memory Utility Refinement
#* .
#*
#* 09 21 2014 raymondwt.chen
#* .Fix after layout change
#* 
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './pcore/tools/', './common/tools/MemoryUtility/' }  # add additional library path
use SymFileParser;  #tools of pcore


#****************************************************************************
# Variables
#****************************************************************************
my $nSizeInitialVector = 0x40;


#****************************************************************************
# Input
#****************************************************************************
my ($elf_file,$sym_file)=@ARGV;
print "Input: $elf_file $sym_file\n";


#****************************************************************************
# >>>  Main Flow
#****************************************************************************

# 1. parsing PCORE SYM 
SymFileParser::ParseSYM($sym_file);

# 2. get section info
my $strROMIVRegion = "ROM_GFH";
my $strROMSection = "ROM";
my $nROMIVRegionOffset = hex(SymFileParser::GetExeRegionInfo($strROMIVRegion, Region::Offsets));
my $nROMSectionOffset = hex(SymFileParser::GetExeRegionInfo($strROMSection, Region::Offsets));

printf "IV Region file offset in ELF : 0x%x\n", $nROMIVRegionOffset;
printf "ROM file offset in ELF : 0x%x\n", $nROMSectionOffset;

# 3. copy input vector to the head of ROM image (IV Region)
CopyInitialVectorInElf($nROMIVRegionOffset, $nROMSectionOffset, $nSizeInitialVector);



#****************************************************************************
# Subroutines
#****************************************************************************
sub CopyInitialVectorInElf
{
    my ($DstAddr, $SrcAddr, $nSize) = (@_);
    my ($buffer, $data, $n);

    open (FILE_HANDLE, "+<$elf_file") or &ReadElf_die("[2.0]$elf_file: file error!", __FILE__, __LINE__);
    binmode FILE_HANDLE;

    # Read initial vector
    seek FILE_HANDLE,$SrcAddr,0;    
    if (($n = read FILE_HANDLE, $data, $nSize) != 0)
    {
    	  $buffer .= $data;    	  
    }
    else
    {
    	die "Error : Read IV failed\n";
    }
    
    #write initial vector
    seek FILE_HANDLE,$DstAddr,0;    
    print FILE_HANDLE $buffer;
    
    
    close(FILE_HANDLE);
}
