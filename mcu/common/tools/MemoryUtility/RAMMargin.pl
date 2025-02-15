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
#*   RAMmargin.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This perl is used to get RAM margin
#*       
#*
#* Author:
#* -------
#*   Carina Liao (mtk04017)
#*
#****************************************************************************/

BEGIN { push @INC, "pcore/" , '../', './pcore/tools/', './common/tools/MemoryUtility/' }  # add additional library path
use systemInfo;
use LinkerOutputParser;
use CommonUtility;
use FileInfoParser;
use BasicMemInfoQuery;
use strict;

#****************************************************************************
# Constants
#****************************************************************************
my $RAMMARGIN_VERNO     = " u0.02";
             # u0.02 , 2015/01/27,  Correct pm name (CommonUtility)
             # u0.01 , 2015/01/19,  Memory Utility Refinement
             # m0.03 , 2013/02/12,  Fix RamMargin
             # m0.02 , 2012/08/03,  Push additional library path
             # m0.01 , 2012/07/21,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************
my $DebugPrint = 0;

#****************************************************************************
# 1 >>>  Get in put parameters
#****************************************************************************
&Usage() if($#ARGV != 2);
my ($makeFile, $memorymapfile, $symfile) = @ARGV;

#****************************************************************************
# 2 >>>  Parse make file
#****************************************************************************
my %MAKEFILE_OPTIONS;
&FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS);

#****************************************************************************
# 3 >>>  Calculate RAM margin
#****************************************************************************
&CalcRAMmargin($makeFile, $memorymapfile, $symfile);

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit 0;

#****************************************************************************
# subroutine:  CalcRAMmargin - calculate RAM margin
# Input:       x
# Output:      x
#****************************************************************************
sub CalcRAMmargin
{
    my ($makeFile, $memorymapfile, $symfile) = @_;
    my $mapfile = $symfile;
    my  ($nRAMUsage, $nRAMmargin, $nRAMmargin1) = (0,0,0);
    if($symfile =~ /sym$/)
    {
        $mapfile =~ s/\.sym/\.map/;
        ($nRAMUsage, $nRAMmargin, $nRAMmargin1) = BasicMemInfo::DispatchCommand("CMD_GetRAMUsage", $makeFile, $memorymapfile, $mapfile, $symfile, undef);
    }
    else
    {
        &Usage();
    }
    my $RamMarginInHex = CommonUtil::Dec2Hex($nRAMmargin);
    my $RamMargin1InHex = CommonUtil::Dec2Hex($nRAMmargin1);
    if(CORE_ID::PCORE == &BasicMemInfo::GetCurrentCore($mapfile, $symfile))
    {
        print "RAM Margin 1 = $RamMargin1InHex = $nRAMmargin1 (Bytes)\n";
        print "RAM Margin 2 = $RamMarginInHex = $nRAMmargin (Bytes)\n";
        print "For more information, please use \"\.\/m memquery basicinfo\" command\n";
    } else {
        print "RAM Margin = $RamMarginInHex = $nRAMmargin (Bytes)\n";
        print "SWLA Space = $RamMargin1InHex = $nRAMmargin1 (Bytes)\n";
        print "For more information, please use \"\.\/m -l1core memquery basicinfo\" command\n";
    }
}

#****************************************************************************
# subroutine:  Usage - usage template
# Input:       x
# Output:      x
#****************************************************************************
sub Usage
{
  print <<"__EOFUSAGE";

usage: perl RAMMargin.pl makefile_path lds_file_path sym_file_path 

e.g. 
perl RAMMargin.pl "/[path]/MT6280_R7R8_HSPA(FULL_VERSION_RVCT).mak" "/[path]/lds_MT6280_R7R8.txt" "/[path]/MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.sym"

__EOFUSAGE

  exit 1;
}

#****************************************************************************
# Subroutine:  TCMmargin_verno - to query this package's version number
# Parameters:  x
# Returns:     version number string
#****************************************************************************
sub RAMmargin_verno
{
    return $RAMMARGIN_VERNO;
}