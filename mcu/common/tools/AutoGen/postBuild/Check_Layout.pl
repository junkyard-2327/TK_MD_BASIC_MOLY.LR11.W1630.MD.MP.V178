#!/usr/bin/env perl
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
#*   master_info_gen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is used to parse master information
#* 
#*
#* Author:
#* -------
#*   Carl Kao (mtk08237)
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;

use constant P_ENUM => qw(
    P_P_ROM1_BASE
    P_P_ROM1_END
    P_L_ROM_BASE
    P_L_ROM_LEN
    P_P_ROM2_BASE
    P_P_ROM2_LEN
    P_P_ROM2_END
    P_L_RW_BASE
    P_L_RW_LEN
    P_L_RW_END
    P_SHM__DNC_BASE
    P_SHM__DNC_NC_END
    P_SHM__MCURO_HWRW__DNC_BASE
    P_SHM__MCURO_HWRW__DNC_NC_END
    P_SHM__MCURW_HWRW__DNC_BASE
    P_SHM__MCURW_HWRW__DNC_NC_END
    P_P_RW_BASE
    P_P_RW_END
    P_L_BOOT_VECTOR
);

use constant L_ENUM => qw(
    L_P_ROM1_END
    L_L_ROM_BASE
    L_L_ROM_LEN
    L_L_ROM_END
    L_P_ROM2_BASE
    L_P_ROM2_END
    L_L_RW_BASE
    L_L_RW_END
    L_SHM__DNC_BASE
    L_SHM__DNC_NC_END
    L_SHM__MCURO_HWRW__DNC_BASE
    L_SHM__MCURO_HWRW__DNC_NC_END
    L_SHM__MCURW_HWRW__DNC_BASE
    L_SHM__MCURW_HWRW__DNC_NC_END
    L_P_RW_BASE
    L_P_RW_END
    L_L_BOOT_VECTOR
);

BEGIN { 
    push @INC, './pcore/tools/', './common/tools/MemoryUtility/';
    eval "use constant (P_ENUM)[$_] => $_;" foreach 0..(P_ENUM)-1;
    eval "use constant (L_ENUM)[$_] => $_;" foreach 0..(L_ENUM)-1;
}  # add additional library path         


use LinkerOutputParser;
use BasicMemInfoQuery;
use CommonUtility;

#****************************************************************************
# Constants
#*****************************************************************************
my $CHECK_LAYOPUT_VERNO = " v0.01";
		# v0.01 , 2017/May/25,  Carl,  Initial version



#****************************************************************************
# Input
#****************************************************************************
my $PCORE_SYM_FILE      = $ARGV[0];
my $PCORE_MAP_FILE      =~ s/\.sym$/\.map/;
my $L1CORE_SYM_FILE     = $ARGV[1];
my $L1CORE_MAP_FILE     =~ s/\.sym$/\.map/;

print "$0 input:\n\
$ARGV[0]\n\
$ARGV[1]\n\
$ARGV[2]\n\
$ARGV[3]\n\
";

#****************************************************************************
# Global Variables
#****************************************************************************
my %g_hP;
my %g_hL;
my $g_idx=0;
my $g_error_count=0;

#****************************************************************************
# >>>  Main Flow
#****************************************************************************
get_PCORE_INFO($PCORE_SYM_FILE, $PCORE_MAP_FILE);
get_L1CORE_INFO($L1CORE_SYM_FILE, $L1CORE_MAP_FILE);

compare_all();

exit 0;
#****************************************************************************
# Subroutines
#****************************************************************************
sub compare
{
    my ($c2, $c3) = @_;
    my ($c0, $c1) = ($g_hP{$c2}, $g_hL{$c3});

    if (hex($c0) > hex($c1))
    {
        print "[X]\t[$g_idx]\tPcore $c0 \t>\tL1core $c1\n";  
        $g_error_count++;
    }
    elsif (hex($c0) < hex($c1))
    {
        print "[X]\t[$g_idx]\tPcore $c0 \t<\tL1core $c1\n";  
        $g_error_count++;
    }
    else
    {
        print "[O]\t[$g_idx]\tPcore $c0 \t==\t L1core $c1\n";  
    }

    $g_idx++;
}

sub add2hex
{
    my ($c0, $c1) = @_;
    return CommonUtil::Dec2Hex( hex($c0) + hex($c1) );
}

sub remap2bank0
{
    my ($c0) = @_;
    return CommonUtil::Dec2Hex( hex($c0) & 0x0FFFFFFF );
}

sub get_PCORE_INFO
{
    my ($pcore_sym_file, $pcore_map_file) = @_;

    LinkerOutputParser::FileParse($pcore_sym_file);

    #0
    $g_hP{int(P_P_ROM1_END)} = LinkerOutputParser::GetLinkerSymbolAddress("ROM", LinkerSymPostfix::Limit, LinkerSymPrefix::Image);
    $g_hP{int(P_L_ROM_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("ROM_L1CORE_LV", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    $g_hP{int(P_P_ROM2_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("ROM_P", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    $g_hP{int(P_P_ROM2_END)} = 
        #add2hex(
        #LinkerOutputParser::GetLinkerSymbolAddress("ROM_SIGNATURE_SECTION", LinkerSymPostfix::Limit, LinkerSymPrefix::Load),
        #LinkerOutputParser::GetLinkerSymbolAddress("ROM_SIGNATURE_SECTION", LinkerSymPostfix::Length, LinkerSymPrefix::Image));
        LinkerOutputParser::GetLinkerSymbolAddress("PCORE_END", LinkerSymPostfix::Limit, LinkerSymPrefix::Image);
    $g_hP{int(P_L_RW_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("L1CORE_RWZI", LinkerSymPostfix::Base, LinkerSymPrefix::Image);


    #5
    $g_hP{int(P_L_RW_END)} = LinkerOutputParser::GetLinkerSymbolAddress("L1CORE_DUMP_REGION__DNC", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);
    $g_hP{int(P_SHM__DNC_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    $g_hP{int(P_SHM__DNC_NC_END)} = LinkerOutputParser::GetLinkerSymbolAddress("SHARED_EXTSRAM_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);
    $g_hP{int(P_SHM__MCURO_HWRW__DNC_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURO_HWRW_ZI", LinkerSymPostfix::ZIBase, LinkerSymPrefix::Image);
    $g_hP{int(P_SHM__MCURO_HWRW__DNC_NC_END)} = LinkerOutputParser::GetLinkerSymbolAddress("SHARED_EXTSRAM_MCURO_HWRW_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);


    # 10
    $g_hP{int(P_SHM__MCURW_HWRW__DNC_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("SHARED_EXTSRAM_MCURW_HWRW_ZI", LinkerSymPostfix::ZIBase, LinkerSymPrefix::Image);
    $g_hP{int(P_SHM__MCURW_HWRW__DNC_NC_END)} = add2hex(LinkerOutputParser::GetLinkerSymbolAddress("EXTSRAM_DSP_RX", LinkerSymPostfix::Base, LinkerSymPrefix::Image), "0x20000");
    $g_hP{int(P_L_BOOT_VECTOR)} = LinkerOutputParser::GetLinkerSymbolAddress("L1CORE_BOOT_VECTOR", LinkerSymPostfix::Base, LinkerSymPrefix::Load);


    # 15
    # 20



#    $g_hP{int(P_P_RW_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("CACHED_EXTSRAM", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
#    $g_hP{int(P_P_RW_END)} = LinkerOutputParser::GetLinkerSymbolAddress("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW", LinkerSymPostfix::Limit, LinkerSymPrefix::Image);
}


sub get_L1CORE_INFO
{
    my ($l1core_sym_file, $l1core_map_file) = @_;

    LinkerOutputParser::FileParse($l1core_sym_file);

    # 0
    $g_hL{int(L_P_ROM1_END)} = LinkerOutputParser::GetLinkerSymbolAddress("ROM", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    $g_hL{int(L_L_ROM_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("ROM", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    $g_hL{int(L_P_ROM2_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI", LinkerSymPostfix::Base, LinkerSymPrefix::Load);
    $g_hL{int(L_P_ROM2_END)} =  add2hex( $g_hL{int(L_P_ROM2_BASE)},
        LinkerOutputParser::GetLinkerSymbolAddress("PCORE_LV2_LENGTH", LinkerSymPostfix::Length, LinkerSymPrefix::Image));
    $g_hL{int(L_L_RW_BASE)} = remap2bank0(LinkerOutputParser::GetLinkerSymbolAddress("CACHED_EXTSRAM_L1DSPBIN_ZI", LinkerSymPostfix::Base, LinkerSymPrefix::Image));


    # 5
    $g_hL{int(L_L_RW_END)} = LinkerOutputParser::GetLinkerSymbolAddress("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);
    $g_hL{int(L_SHM__DNC_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    $g_hL{int(L_SHM__DNC_NC_END)} = LinkerOutputParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURO_HWRW_ZI", LinkerSymPostfix::Limit, LinkerSymPrefix::Image);
    $g_hL{int(L_SHM__MCURO_HWRW__DNC_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURO_HWRW_ZI", LinkerSymPostfix::ZIBase, LinkerSymPrefix::Image);
    $g_hL{int(L_SHM__MCURO_HWRW__DNC_NC_END)} = LinkerOutputParser::GetLinkerSymbolAddress("SHARED_EXTSRAM_MCURO_HWRW_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);


    # 10
    $g_hL{int(L_SHM__MCURW_HWRW__DNC_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("SHARED_EXTSRAM_MCURW_HWRW_ZI", LinkerSymPostfix::ZIBase, LinkerSymPrefix::Image);
    $g_hL{int(L_SHM__MCURW_HWRW__DNC_NC_END)} = add2hex(LinkerOutputParser::GetLinkerSymbolAddress("EXTSRAM_DSP_RX", LinkerSymPostfix::Base, LinkerSymPrefix::Image), "0x20000");
    $g_hL{int(L_L_BOOT_VECTOR)} = LinkerOutputParser::GetLinkerSymbolAddress("INTSRAM_CODE", LinkerSymPostfix::Base, LinkerSymPrefix::Load);


    # 15
    # 20


#    $g_hL{int(L_P_RW_BASE)} = LinkerOutputParser::GetLinkerSymbolAddress("CACHED_EXTSRAM", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
#    $g_hL{int(L_P_RW_END)} = LinkerOutputParser::GetLinkerSymbolAddress("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW", LinkerSymPostfix::Limit, LinkerSymPrefix::Image);
}

sub compare_all
{
    # 0
    compare(P_P_ROM1_END,   L_P_ROM1_END);
    compare(P_L_ROM_BASE,   L_L_ROM_BASE);
    compare(P_P_ROM2_BASE,  L_P_ROM2_BASE);
    compare(P_P_ROM2_END,   L_P_ROM2_END);
    compare(P_L_RW_BASE,    L_L_RW_BASE);

    # 5
    compare(P_L_RW_END,     L_L_RW_END);
    compare(P_SHM__DNC_BASE,                L_SHM__DNC_BASE);
    compare(P_SHM__DNC_NC_END,              L_SHM__DNC_NC_END);
    compare(P_SHM__MCURO_HWRW__DNC_BASE,    L_SHM__MCURO_HWRW__DNC_BASE);
    compare(P_SHM__MCURO_HWRW__DNC_NC_END,  L_SHM__MCURO_HWRW__DNC_NC_END);


    # 10
    compare(P_SHM__MCURW_HWRW__DNC_BASE,    L_SHM__MCURW_HWRW__DNC_BASE);
    compare(P_SHM__MCURW_HWRW__DNC_NC_END,  L_SHM__MCURW_HWRW__DNC_NC_END);
    compare(P_L_BOOT_VECTOR,                L_L_BOOT_VECTOR);

    # L1core cannot detect pcore RW

    # 15
    # 20


    print "Finish comparing! Total difference: $g_error_count\/$g_idx\n";

#    compare(P_P_RW_BASE,    L_P_RW_BASE);
#    compare(P_P_RW_END,     L_P_RW_END);
}






