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
#*   BasicInfoQuery.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This perl module is used to get system basic information
#*       
#*
#* Author:
#* -------
#*   Carl Kao (mtk08237)
#*
#****************************************************************************/

BEGIN { push @INC, '../', './pcore/tools/', './common/tools/MemoryUtility/' }  # add additional library path
use strict;
use POSIX qw(floor ceil);

use systemInfo;
use LinkerOutputParser;
use FileInfoParser;
use CommonUtility;


package FILEOPTION;
use constant LIS         => 1;
use constant MAP         => 2;
use constant SYM         => 3;
use constant MAKEFILE    => 4;
use constant INFOMAKE    => 5;

package CORE_ID;
use constant PCORE       => 0;
use constant L1CORE      => 1;

use BasicMemInfoQueryPcore;
use BasicMemInfoQueryL1core;


package BasicMemInfo;

#****************************************************************************
# Constants
#****************************************************************************
my $VERNO     = " m0.01";
             # u0.01 , 2015/01/14,  Memory Utility Refinement
             # m0.06 , 2014/02/20,  Correct GetTotalRAMUsageFromLDS's base address
             # m0.05 , 2013/12/25,  Fix LoadView which can't count in .bss
             # m0.04 , 2013/10/20,  Support Secure region
             # m0.03 , 2013/06/25,  Support CMD_GetROMSize() for filtering out COPRO section
             # m0.02 , 2013/03/21,  Support GetMBAlignment()
             # m0.01 , 2013/01/08,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************
my $DebugPrint = 0;
my $g_bParseSYM = 0;
my $g_bParseMAP = 0;
my $g_bParseLIS = 0;
my $g_bParseMAKEFILE = 0;
my %g_MAKEFILE_OPTIONS;

#****************************************************************************
# Subroutine:  BasicInfoQuery_verno - to query this package's version number
# Parameters:  x
# Returns:     version number string
#****************************************************************************
sub BasicInfoQuery_verno
{
    return $VERNO;
}

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

sub GetCurrentCore
{
    my ($MAP_PATH, $SYM_PATH) = @_;
    my $current_core = ($MAP_PATH =~/_P_/i == 1 ? CORE_ID::PCORE : CORE_ID::L1CORE);
    &BasicMemInfoCommon::CommonMemUtil_die("map and sym must be belong to same core", __FILE__, __LINE__) if( $current_core != ($SYM_PATH =~/_P_/i == 1 ? CORE_ID::PCORE : CORE_ID::L1CORE));
    return $current_core;
}

sub DispatchCommand
{
    my ($cmd, $MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $current_core = GetCurrentCore($MAP_PATH, $SYM_PATH);
    $cmd = "help" if($cmd eq "-h" or $cmd eq "--help");
    no strict 'refs';
    if($current_core == CORE_ID::PCORE){
        # dispatch to pcore
        &BasicMemInfoPcore::DispatchCommand($cmd, $MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
    }else{
        # dispatch to l1core
        &BasicMemInfoL1core::DispatchCommand($cmd, $MAKEFILE_PATH, $IMAGELAYOUT_PATH, $MAP_PATH, $SYM_PATH, $PrintFunc);
    }
}

