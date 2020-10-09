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
#*   DspInfo.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module is used for getting information of copro. 
#*       
#*
#* Author:
#* -------
#*   Carina Liao (mtk04017)
#*
#****************************************************************************/

use strict;
#use warnings;
BEGIN { push @INC, './l1core/tools/'}  # add additional library path
use DspMapFileParser;
use tclInfo;
#use tools::pack_dep_gen;
#PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
package SectionName;
use constant Bss                  => 0;
use constant Data                 => 1;
use constant Rodata               => 2;
use constant Text                 => 3;

package DspInfo;
use constant COPRO_LV_SIZE                => "DspLoadViewSize";
use constant COPRO_EV_RWZI_SIZE             => "DspExecViewRWZISize";

my %g_DspInfo;
my $g_DSPtclInfo;
#****************************************************************************
# Constants
#****************************************************************************
my $DSPINFO_VERNO     = " v0.01";
                        # v0.01 , 2013/06/06,  Initial revision

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# subroutine:  GetDspInfo - for Master core usage
# input:       $key: which info the master want to get
#              $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $g_DspInfoo{$key}
#****************************************************************************
sub GetDspInfo
{
    my ($key, $bNeedString) = @_;
    $bNeedString = 0 if(!defined $bNeedString);
    return $bNeedString ? &CommonUtil::Dec2Hex($g_DspInfo{$key}) : $g_DspInfo{$key};
}

#****************************************************************************
# subroutine:  GenDspInfo - for GetDspInfo
# input:       x
# output:      x
#****************************************************************************
sub GenDspInfo
{  
    my ($strTclPath, $strMapPath) = @_;    
    $g_DSPtclInfo = new tclInfo;
    $g_DSPtclInfo->ParseLinkerScript($strTclPath);
    &DspMapFileParser::ParseMAP($strMapPath);
    $g_DspInfo{DspLoadViewSize} =     &DspMapFileParser::GetExtsramRWDataEnd(0) - $g_DSPtclInfo->GetPreDefinedBaseAddr(tclInfo::DSP_COPRO_LV_BASE) + 1;
    print "[DSPInfo]Actual Binary Size = ".$g_DspInfo{DspLoadViewSize}."\n";
    $g_DspInfo{DspExecViewRWZISize} = &DspMapFileParser::GetExecViewRWZISize();
}

#****************************************************************************
# subroutine:  DspInfo_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub DspInfo_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'DspInfo');    
}
