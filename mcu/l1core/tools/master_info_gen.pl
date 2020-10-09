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
BEGIN { push @INC, './l1core/tools/', './common/tools/MemoryUtility/' }  # add additional library path         
use L1coreCommonUtility;
use L1coreFileInfoParser;
use SymFileParser;
use BasicMemInfoQuery;
#****************************************************************************
# Constants
#*****************************************************************************
my $MASTER_INFO_VERNO     = " v0.18";
                      # v0.18 , 2017/May/24, Carl,  New Layout
                      # v0.17 , 2016/01/29,  Tero,  Pcore symbol file not required in codegen compilation
                      # v0.16 , 2015/11/02,  Carl,  Change DSP TX/RX sections to ZI (.bss) section
                      # v0.15 , 2015/05/11,  Carl,  Support Ramdisk for TK6291
                      # v0.14 , 2015/04/15,  Carl,  Refine setting for (MCU RO, MDHW RW)  DNC+NC, (MCU RW, MDHW RW)  DNC+NC
                      # v0.13 , 2015/02/03,  Carl,  Fix typo
                      # v0.12 , 2015/01/19,  Carl,  Memory Utility Refinement
                      # v0.11 , 2015/01/06,  Carl,  lds refinement: 1) auto adjust shared region size, 2) reserve pcore, l1core SWLA space
                      # v0.10 , 2014/10/29,  Carl,  Increase l1core default size
                      # v0.09 , 2014/09/26,  Carl,  Support GFH + SIG
                      # v0.08 , 2014/09/16,  Carl,  fix L1core RW/ZI size
                      # v0.07 , 2014/07/25,  Carl,  sync shared section length from pcore to l1core
                      # v0.07 , 2014/06/14,  Carl,  refine error message for avoid false alarm in EWS build
                      # v0.06 , 2014/06/10,  Carl,  use default value for master_info_gen if pcore build fail by "bm_new" command
                      # v0.05 , 2014/05/08,  Carl,  AAPMC( enlarge default size for build )
                      # v0.04 , 2014/05/07,  Carl,  2-phase linking
                      # v0.03 , 2014/05/07,  Carl,  2-phase linking
                      # v0.02 , 2014/04/01,  Carl,  l1core ldsGen
                      # v0.01 , 2014/03/28,  Carl,  Initial revision

#****************************************************************************
# Input
#****************************************************************************
my $BM_NEW                = $ARGV[0];
my $MASTER_INFO_OUTPUT    = $ARGV[1];
my $themf                 = $ARGV[2];
my $INFOMAKELOG           = $ARGV[3];
my $MASTER_LDS_FILE       = $ARGV[4];
my $MASTER_MAP_FILE       = $ARGV[5];
my $MASTER_SYM_FILE       = $ARGV[6];
my $SINGLE_CORE           = $ARGV[7];

print "master_info_gen input:\n\
BM_NEW = $ARGV[0]\n\
MASTER_INFO_OUTPUT = $ARGV[1]\n\
themf = $ARGV[2]\n\
INFOMAKELOG = $ARGV[3]\n\
MASTER_LDS_FILE = $ARGV[4]\n\
MASTER_MAP_FILE = $ARGV[5]\n\
MASTER_SYM_FILE = $ARGV[6]\n\
SINGLE_CORE = $ARGV[7]\n\
";

#****************************************************************************
# Global Variables
#****************************************************************************
my $g_bBM_NEW = (($BM_NEW eq "bm_new") || ($BM_NEW eq "codegen"))? 1 : 0;
my %g_MASTER_INFO;
my %g_MKFILE;
my %g_CmplOpt;
my %g_RelInfo;
my $g_bSINGLE_CORE = ($SINGLE_CORE eq "TRUE") ? 1 : 0;
my %g_PathInfo;

#****************************************************************************
# >>>  Main Flow
#****************************************************************************
L1coreFileInfo::PreProcess($themf, \%g_MKFILE, $INFOMAKELOG, \%g_CmplOpt, \%g_RelInfo,1);
if(&NeedToGen($themf, $MASTER_SYM_FILE))
{
    get_MASTER_INFO($MASTER_SYM_FILE, \%g_MASTER_INFO);
}
else
{
    SetDefaultValue($MASTER_SYM_FILE, \%g_MASTER_INFO);
}
map {print "$_ => ".$g_MASTER_INFO{$_}. "(".L1coreCommonUtil::Dec2Hex($g_MASTER_INFO{$_}).")"."\n"; } sort keys %g_MASTER_INFO;
gen_MASTER_INFO_LOG(\%g_MASTER_INFO, $MASTER_INFO_OUTPUT);

exit 0;
#****************************************************************************
# Subroutines
#****************************************************************************
sub NeedToGen
{
    my ($MAKE_FILE, $SYM_PATH)=@_;
    my $bNeed = 0; # no need to generate
    print "[NeedToGen] SINGLE_CORE=$g_bSINGLE_CORE \n";
    if( !$g_bSINGLE_CORE )
    {
        $bNeed = 1;
        if( !$g_bBM_NEW )
        {
            #die for BasicMemInfo
            masterinfo_die("[1.4]$MAKE_FILE doesn't exist. \"Please fix Pcore build error to avoid this error!\"\n") if(!-e $MAKE_FILE);
            masterinfo_die("[1.4]$SYM_PATH doesn't exist. \"Please fix Pcore build error to avoid this error!\"\n") if(!-e $SYM_PATH);
        }
        elsif( !-e $MAKE_FILE || !-e $SYM_PATH )
        {
            # use default value for master_info_gen if pcore build fail by "bm_new" command
            $bNeed = 0;
            print "no sym file, pcore build fail \n";
        }
    }
    print $bNeed ? "=> Need to generate tmp file contents by pcore \n" : "=> Generate tmp file contents by default values\n";
    return $bNeed;
}

sub gen_MASTER_INFO_LOG
{
    my ($MASTER_INFO_href, $OUTPUT_PATH) = @_;
    my $strMASTER_INFO = L1coreCommonUtil::HashStringGenerator($MASTER_INFO_href);
    L1coreCommonUtil::WriteFileContent($OUTPUT_PATH, $strMASTER_INFO, 1, 1);
}

sub get_MASTER_COMMON_INFO
{
    my $nPCORELV1Size = hex(SymFileParser::GetLinkerSymbolAddress("ROM_L1CORE_LV", LinkerSymPostfix::Base, LinkerSymPrefix::Load));


    masterinfo_die("[1.5] Load view and execution view of Pcore ROM_P are different! \"\n") if 
        ( SymFileParser::GetLinkerSymbolAddress("ROM_P", LinkerSymPostfix::Base, LinkerSymPrefix::Load)
      !=  SymFileParser::GetLinkerSymbolAddress("ROM_P", LinkerSymPostfix::Length, LinkerSymPrefix::Image));

	# note1 : $nPCORELVSize != BasicMemInfo::DispatchCommand("CMD_GetLoadViewSize", $themf, $MASTER_LDS_FILE, $MASTER_MAP_FILE, $MASTER_SYM_FILE, undef);
	# note2 : EXTSRAM_FS_ZI is ZI, not in PCORE LV size 
	
    my $nL1CORELVSize = hex(SymFileParser::GetLinkerSymbolAddress("ROM_L1CORE_LV", LinkerSymPostfix::Length, LinkerSymPrefix::Image));


    # note A: cannot use ROM_P, it only include Pcore RODATA and some code. No Pcore RW load view inside ROM_P
    my $nPCORELV2Size_A = hex(SymFileParser::GetLinkerSymbolAddress("ROM_SIGNATURE_SECTION", LinkerSymPostfix::Base, LinkerSymPrefix::Load))
                      + hex(SymFileParser::GetLinkerSymbolAddress("ROM_SIGNATURE_SECTION", LinkerSymPostfix::Length, LinkerSymPrefix::Image))
                      - hex(SymFileParser::GetLinkerSymbolAddress("ROM_P", LinkerSymPostfix::Base, LinkerSymPrefix::Load));
    # note B: use ROM_2 1st linking time size rather than 2nd linking time size for avoiding shifting due to less veneer
    my $nPCORELV2Size_B = hex(SymFileParser::GetLinkerSymbolAddress("PCORE_END", LinkerSymPostfix::Limit, LinkerSymPrefix::Image));
    my $nPCORELV2Size = $nPCORELV2Size_A; # real end, the result of 1st linking size
    if (($nPCORELV2Size_B % 0x10000)!=0 && ($nL1CORELVSize % 0x10000)!=0) 
    {
        $nPCORELV2Size = $nPCORELV2Size_B - $nPCORELV1Size - $nL1CORELVSize;
    }
    
    my $nL1CORERWZISize = hex(SymFileParser::GetLinkerSymbolAddress("L1CORE_RWZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image))
                        - hex(SymFileParser::GetLinkerSymbolAddress("L1CORE_RWZI", LinkerSymPostfix::ZIBase, LinkerSymPrefix::Image));


    return ($nPCORELV1Size, $nPCORELV2Size, $nL1CORELVSize, $nL1CORERWZISize);
}

sub get_MASTER_INFO
{
    my ($SYM_PATH, $MASTER_INFO_href) = @_;
   	my ($strTemp1, $strTemp2) = (0,0);
    print "Set MASTER INFO:\n";

    print "--------------------------------------------------------------\n";

    ######################
    # take the end of last load view section
    ######################    

    SymFileParser::ParseSYM($SYM_PATH);
    
    my ($nPCORELV1Size, $nPCORELV2Size, $nL1CORELVSize, $nL1CORERWZISize) = &get_MASTER_COMMON_INFO();

    ######################
    # watchout the third parameter 
    ######################
    my $strDYN_DNCSharedBuffBase = SymFileParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    my $strDYN_DNCSharedBuffEnd  = SymFileParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);
    my $nDYN_DNCSharedBuffLength = hex($strDYN_DNCSharedBuffEnd) - hex($strDYN_DNCSharedBuffBase) ;
    
    my $strNCSharedBuffBase = SymFileParser::GetLinkerSymbolAddress("SHARED_EXTSRAM", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    my $strNCSharedBuffEnd  = SymFileParser::GetLinkerSymbolAddress("SHARED_EXTSRAM_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);
    my $nNCSharedBuffLength = hex($strNCSharedBuffEnd) - hex($strNCSharedBuffBase) ;
    
    my $strTemp1 = SymFileParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURO_HWRW", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    my $strTemp2 = SymFileParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURO_HWRW_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DYN_DNC_MCURO_HWRW_SHARED_BUFF_LENGTH} = hex($strTemp2) - hex($strTemp1);    
    
    my $strTemp1 = SymFileParser::GetLinkerSymbolAddress("SHARED_EXTSRAM_MCURO_HWRW", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    my $strTemp2 = SymFileParser::GetLinkerSymbolAddress("SHARED_EXTSRAM_MCURO_HWRW_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_NC_MCURO_HWRW_SHARED_BUFF_LENGTH} = hex($strTemp2) - hex($strTemp1);    

    my $strTemp1 = SymFileParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURW_HWRW", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    my $strTemp2 = SymFileParser::GetLinkerSymbolAddress("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURW_HWRW_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DYN_DNC_MCURW_HWRW_SHARED_BUFF_LENGTH} = hex($strTemp2) - hex($strTemp1);    
   
    my $strTemp1 = SymFileParser::GetLinkerSymbolAddress("SHARED_EXTSRAM_MCURW_HWRW", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    my $strTemp2 = SymFileParser::GetLinkerSymbolAddress("SHARED_EXTSRAM_MCURW_HWRW_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image);
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_NC_MCURW_HWRW_SHARED_BUFF_LENGTH} = hex($strTemp2) - hex($strTemp1);    


    my $strDSP_TXBase = SymFileParser::GetLinkerSymbolAddress("EXTSRAM_DSP_TX", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    my $strDSP_RXBase = SymFileParser::GetLinkerSymbolAddress("EXTSRAM_DSP_RX", LinkerSymPostfix::Base, LinkerSymPrefix::Image);
    my $nPcoreDSP_TXLength = SymFileParser::GetLinkerSymbolAddress("PCORE_EXTRAM_TXDATA", LinkerSymPostfix::ZILength, LinkerSymPrefix::None);
    my $nPcoreDSP_RXLength = SymFileParser::GetLinkerSymbolAddress("PCORE_EXTRAM_RXDATA", LinkerSymPostfix::ZILength, LinkerSymPrefix::None);


    $MASTER_INFO_href->{L1coreFileInfo::L1CORE_LV_SIZE} = $nL1CORELVSize;
    $MASTER_INFO_href->{L1coreFileInfo::L1CORE_RWZI_SIZE} = $nL1CORERWZISize;
    
#    $MASTER_INFO_href->{L1coreFileInfo::PCORE_LV_SIZE} = $nPCORELVSize;
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_LV1_SIZE} = $nPCORELV1Size;
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_LV2_SIZE} = $nPCORELV2Size;
    $MASTER_INFO_href->{L1coreFileInfo::TOTAL_LV_SIZE} = $nPCORELV1Size + $nL1CORELVSize + $nPCORELV2Size;
    
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DYN_DNC_SHARED_BUFF_BASE} = hex($strDYN_DNCSharedBuffBase);
#    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DYN_DNC_SHARED_BUFF_END} = hex($strDYN_DNCSharedBuffEnd);
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DYN_DNC_SHARED_BUFF_LENGTH} = $nDYN_DNCSharedBuffLength;
    
#    $MASTER_INFO_href->{L1coreFileInfo::PCORE_NC_SHARED_BUFF_BASE} = hex($strNCSharedBuffBase);
#    $MASTER_INFO_href->{L1coreFileInfo::PCORE_NC_SHARED_BUFF_END} = hex($strNCSharedBuffEnd);
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_NC_SHARED_BUFF_LENGTH} = $nNCSharedBuffLength;
    
    $MASTER_INFO_href->{L1coreFileInfo::DSP_TX_BASE} = hex($strDSP_TXBase);
    $MASTER_INFO_href->{L1coreFileInfo::DSP_RX_BASE} = hex($strDSP_RXBase);
    
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DSP_TX_LENGTH} = hex($nPcoreDSP_TXLength);
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DSP_RX_LENGTH} = hex($nPcoreDSP_RXLength);

}

sub SetDefaultValue
{
    # note: only for single core

    my ($SYM_PATH, $MASTER_INFO_href) = @_;
    print "Set Default Value:\n";
    print "--------------------------------------------------------------\n";


    my ($nPCORELV1Size, $nPCORELV2Size, $nL1CORELVSize, $nL1CORERWZISize) = (0,0,0,0);
    
    if(defined $SYM_PATH and -e $SYM_PATH)
    {
        SymFileParser::ParseSYM($SYM_PATH);
    
        ($nPCORELV1Size, $nPCORELV2Size, $nL1CORELVSize, $nL1CORERWZISize) = &get_MASTER_COMMON_INFO();
    }

    # for l1core only; for multi-core project, please change copro_info_gen.pl
    $MASTER_INFO_href->{L1coreFileInfo::L1CORE_LV_SIZE} = (($nL1CORELVSize==0) ? 0x600000 : $nL1CORELVSize); #   6MB
    $MASTER_INFO_href->{L1coreFileInfo::L1CORE_RWZI_SIZE} = (($nL1CORERWZISize==0) ? 0x2000000 : $nL1CORERWZISize); #   32MB

    $MASTER_INFO_href->{L1coreFileInfo::PCORE_LV1_SIZE} = (($nPCORELV1Size==0) ? 0xA00000 : $nPCORELV1Size); #   10MB
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_LV2_SIZE} = (($nPCORELV2Size==0) ? 0xB00000 : $nPCORELV2Size); #   11MB
    

    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DYN_DNC_SHARED_BUFF_BASE} = 0x16c0000; # 23855104(0x16c0000)
#    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DYN_DNC_SHARED_BUFF_END} = 0x16c0060; # 23855200(0x16c0060)
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DYN_DNC_SHARED_BUFF_LENGTH} = 0x60; # 96(0x60)
    
#    $MASTER_INFO_href->{L1coreFileInfo::PCORE_NC_SHARED_BUFF_BASE} = 0x16c1000; # 23859200(0x16c1000)
#    $MASTER_INFO_href->{L1coreFileInfo::PCORE_NC_SHARED_BUFF_END} = 0x16c2000; # 23863296(0x16c2000)
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_NC_SHARED_BUFF_LENGTH} = 0x1000; # 4096(0x1000)
    
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DYN_DNC_MCURO_HWRW_SHARED_BUFF_LENGTH} = 
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_NC_MCURO_HWRW_SHARED_BUFF_LENGTH} = 
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DYN_DNC_MCURW_HWRW_SHARED_BUFF_LENGTH} = 
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_NC_MCURW_HWRW_SHARED_BUFF_LENGTH} = 0;    

    $MASTER_INFO_href->{L1coreFileInfo::DSP_TX_BASE} = 0x17c0000; # 24903680(0x17c0000)
    $MASTER_INFO_href->{L1coreFileInfo::DSP_RX_BASE} = 0x17e0000; # 25034752(0x17e0000)
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DSP_TX_LENGTH} =
    $MASTER_INFO_href->{L1coreFileInfo::PCORE_DSP_RX_LENGTH} = 0x0;

}
sub masterinfo_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    &L1coreCommonUtil::error_handler($error_msg, $file, $line_no, 'MASTER_INFO_GEN'); 
}
