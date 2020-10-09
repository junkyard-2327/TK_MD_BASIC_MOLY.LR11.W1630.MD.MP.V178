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
#*   copro_info_gen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is used to parse copro information
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
BEGIN { push @INC, "pcore/" , './pcore/tools/', './common/tools/MemoryUtility/' }  # add additional library path         
use CommonUtility;
use BasicMemInfoQuery;
use FileInfoParser;
use POSIX qw(floor ceil);

#use L1coreInfo;

#****************************************************************************
# Constants
#****************************************************************************
my $COPRO_INFO_VERNO     = " v0.33";
                           # v0.33 , 2017/May/24,Carl,  New Layout
                           # v0.32,  2016/11/14, Carl,  Change Pcore/L1core ROM size for custom/MP load
                           # v0.31,  2015/11/17, Tero,  Added L1CORE_SWLA_SIZE to copro info
                           # v0.30,  2015/11/02, Carl,  Change DSP TX/RX sections to ZI (.bss) section
                           # v0.29,  2015/09/17, Carl,  Move dsp bin from l1core rom to l1core ram, change the 1st EMI RMPU channel base to Image$$L1CORE_DSP$$:imit
                           # v0.28 , 2015/06/23, Carl,  Refine GetSharedMemorySize. It includes dsp tx/rx section now
                           # v0.27 , 2015/06/22, Carl,  Change default l1core ROM, RAM size
                           # v0.26 , 2015/05/11, Carl,  Correct output log
                           # v0.25 , 2015/04/15, Carl,  Refine setting for (MCU RO, MDHW RW)  DNC+NC, (MCU RW, MDHW RW)  DNC+NC
                           # v0.24,  2015/04/09, Carl,  Align the shared DNC base to 64KB for input section MCU-RO, HW-RW (EMI RMPU)
                           # v0.23 , 2015/03/27, Carl,  set default value of L1CORE_DSP_TX_LENGTH, L1CORE_DSP_RX_LENGTH to 0
                           # v0.22 , 2015/03/19, Carl,  add L1CORE_DSP_TX_LENGTH, L1CORE_DSP_RX_LENGTH for dsp sections
                           # v0.21 , 2015/03/11, Carl,  Increase default l1core ROM size to 16MB
                           # v0.20 , 2015/03/04, Carl,  Increase default l1core RAM size to 48MB
                           # v0.19 , 2015/01/14, Carl,  Memory Utility Refinement
                           # v0.18 , 2015/01/06, Carl,  lds refinement: 1) auto adjust shared region size, 2) reserve pcore, l1core SWLA space
                           # v0.17 , 2014/12/22, Carl,  Support L2SRAM section (in L1CORE) 
                           # v0.16 , 2014/10/29, Carl,  Increase l1core default size
                           # v0.15 , 2014/10/06, Carl,  Reserve sig space for L1CORE_LV 
                           # v0.14 , 2014/09/26, Carl,  Support GFH + SIG (reserve space for L1CORE_RWZI)
                           # v0.13 , 2014/09/26, Carl,  Support GFH + SIG (reserve space for L1CORE_LV)
                           # v0.12 , 2014/09/26, Carl,  Support GFH + SIG
                           # v0.11 , 2014/09/11, Carl,  Increase pcore ROM size for pcore only load
                           # v0.10 , 2014/09/11, mei,  support memory dump
                           # v0.09 , 2014/09/05, Carl,  reduce default shared memory size for PCORE ONLY project
                           # v0.08 , 2014/08/20, Carl,  refine l1core dump region
                           # v0.07 , 2014/08/19, Carl,  add l1core reset vector address
                           # v0.06 , 2014/07/31, Carl,  add l1core dump region
                           # v0.05 , 2014/07/14, Carl,  update the lasst section in l1ocre
                           # v0.04 , 2014/05/08, Carl,  enlarge default size for build
                           # v0.03 , 2014/05/07, Carl,  2-phase linking
                           # v0.02 , 2014/03/31, Carl,  Support to generate L1CORE input (reference:TK6280 pcore\tools\copro_info_gen.pl)
                           # v0.01 , 2014/03/03, BM,    Initial revision

my $debug_flag = "0";
#****************************************************************************
# Input
#****************************************************************************
my $FORCE_GEN             = $ARGV[0];
my $COPRO_INFO_TEMP       = $ARGV[1];
my $COPRO_INFO_OUTPUT     = $ARGV[1];
my $themf                 = $ARGV[2];
my $INFOMAKELOG           = $ARGV[3];
my $SINGLE_CORE           = $ARGV[4];


print "copro_info_gen input:\n$ARGV[0]\n$ARGV[1]\n$ARGV[2]\n$ARGV[3]\n$ARGV[4]\n\n";

#****************************************************************************
# Global Variables
#****************************************************************************
my $g_bFORCE = ($FORCE_GEN eq "TRUE") ? 1 : 0;
   $g_bFORCE = ($debug_flag eq "1") ? 1 : $g_bFORCE;
my %g_COPRO_INFO;
my %g_MKFILE;
my %g_CmplOpt;
my %g_RelInfo;
my %g_PathInfo;
my $mode;

#****************************************************************************
# >>>  Main Flow
#****************************************************************************
FileInfo::PreProcess($themf, \%g_MKFILE, $INFOMAKELOG, \%g_CmplOpt, \%g_RelInfo,1);
SetPathInfo($COPRO_INFO_TEMP, \%g_PathInfo);

$mode = &FileInfo::get("MODE");

if(NeedToGen($g_bFORCE, $themf, \%g_PathInfo))
{
    get_L1CORE_INFO($themf, GetPath("L1CORE_IMAGELAYOUT"), GetPath("L1CORE_MAP"), \%g_COPRO_INFO);
}
else
{
    SetDefaultValue(\%g_COPRO_INFO);
}
$g_COPRO_INFO{FileInfo::L1CORE_INFO_FORCE} = $g_bFORCE;
map {print "$_ => ".$g_COPRO_INFO{$_}. "(".CommonUtil::Dec2Hex($g_COPRO_INFO{$_}).")"."\n"; } sort keys %g_COPRO_INFO;
gen_COPRO_INFO_LOG(\%g_COPRO_INFO, $COPRO_INFO_OUTPUT);

exit 0;
#****************************************************************************
# Subroutines
#****************************************************************************
sub NeedToGen
{
    my ($bFORCE, $MAKE_FILE)=@_;
    my $bNeed = 0; # no need to generate
    print "[NeedToGen] FORCE=$bFORCE, SINGLE_CORE=". $SINGLE_CORE ." debug_flag=". $debug_flag ."\n";
    if( ($bFORCE and $SINGLE_CORE eq "FALSE" )or (($debug_flag eq "1") ? 1 : 0))
    {       
        #die for BasicMemInfo
        coproinfo_die("$MAKE_FILE doesn't exist!\n") if(!-e $MAKE_FILE);
        coproinfo_die(GetPath("L1CORE_IMAGELAYOUT")." doesn't exist!\n") if(!-e GetPath("L1CORE_IMAGELAYOUT"));
        coproinfo_die(GetPath("L1CORE_MAP")." doesn't exist!\n") if(!-e GetPath("L1CORE_MAP"));
        coproinfo_die(GetPath("L1CORE_SYM")." doesn't exist!\n") if(!-e GetPath("L1CORE_SYM"));
        $bNeed = 1;
    }
    print $bNeed ? "=> Generate tmp file contents\n" : "=> NO NEED to generate tmp file contents\n";
    return $bNeed;
}

sub SetPathInfo
{
    my ($strInfoPath, $PathInfo_href) = @_;
    my $strContent = CommonUtil::GetFileContent($strInfoPath);
    print "Path Info:\n$strContent\n";
    CommonUtil::HashStringParser($strContent, $PathInfo_href);
}
sub GetPath
{
    my ($strKeyword) = @_;  #keyword is defined in codegen.mak's copro_info_gen
    return $g_PathInfo{$strKeyword};    
}
sub gen_COPRO_INFO_LOG
{
    my ($COPRO_INFO_href, $OUTPUT_PATH) = @_;
    my $strCOPRO_INFO = CommonUtil::HashStringGenerator($COPRO_INFO_href);
    CommonUtil::WriteFileContent($OUTPUT_PATH, $strCOPRO_INFO, 0);
}


#####################
# FIX_ME, copro
#####################
sub wait_for_reuse
#sub get_COPRO_INFO
{
    coproinfo_die("not suppoet ARM7 !\n");

    my ($MAKE_FILE, $IMAGELAYOUT, $MAP_PATH, $SYM_PATH, $COPRO_INFO_href) = @_;
    print "Set COPRO INFO:\n";
    print "--------------------------------------------------------------\n";
#    my $nLoadViewSize = BasicMemInfo::CMD_GetLoadViewSize($MAKE_FILE, $IMAGELAYOUT, $MAP_PATH, $SYM_PATH, undef);
#    $COPRO_INFO_href->{FileInfo::COPRO_LV_SIZE} = $nLoadViewSize;
#    my $nTotalRamUsage = BasicMemInfo::CMD_GetPhysicalRAMUsage($MAKE_FILE, $IMAGELAYOUT, $MAP_PATH, $SYM_PATH, undef);
#    $COPRO_INFO_href->{FileInfo::COPRO_TOTAL_USAGE} = $nTotalRamUsage;
}

sub get_L1CORE_INFO
{
    my ($MAKE_FILE, $IMAGELAYOUT, $MAP_PATH, $COPRO_INFO_href) = @_;
    print "Set L1CORE INFO:\n";
    print "--------------------------------------------------------------\n";

    my $strL1coreLdsPath = GetPath("L1CORE_IMAGELAYOUT");
    my $strL1coreLdsMapPath = GetPath("L1CORE_MAP");
    my $strL1coreLdsSymPath = GetPath("L1CORE_SYM");

    #######################
    # warning, it input pcore makefile to get l1core load info.
    #######################
    my $nL1coreLoadViewSize = BasicMemInfo::DispatchCommand("CMD_GetLoadViewSize", $MAKE_FILE, $strL1coreLdsPath, $strL1coreLdsMapPath, $strL1coreLdsSymPath, undef);
    # subtract base of frist section since the base is not 0


    #my $nTotalRamUsage = BasicMemInfo::GetTotalRAMUsageFromLDS($MAKE_FILE, $strL1coreLdsPath, $strL1coreLdsMapPath, $strL1coreLdsSymPath, undef);

    SymFileParser::ParseSYM($strL1coreLdsSymPath);
    my $nPcoreROM1Usage = (0x0FFFFFFF & hex(SymFileParser::GetLinkerSymbolAddress("ROM", LinkerSymPostfix::Base, LinkerSymPrefix::Image)));

    my $nL1coreTotalRamUsage = (0x0FFFFFFF & hex(SymFileParser::GetLinkerSymbolAddress("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image))) -
                               (0x0FFFFFFF & hex(SymFileParser::GetLinkerSymbolAddress("CACHED_EXTSRAM_L1DSPBIN_ZI", LinkerSymPostfix::Base, LinkerSymPrefix::Image)));

    my $nPcoreROM2Usage = (0x0FFFFFFF & hex(SymFileParser::GetLinkerSymbolAddress("PCORE_LV2_LENGTH", LinkerSymPostfix::Length, LinkerSymPrefix::Image)));


#    $COPRO_INFO_href->{FileInfo::PCORE_LV_SIZE} = $nL1coreFirstSectionBase;
    $COPRO_INFO_href->{FileInfo::PCORE_LV1_SIZE} = $nPcoreROM1Usage;
    $COPRO_INFO_href->{FileInfo::L1CORE_LV_SIZE} = $nL1coreLoadViewSize;
    $COPRO_INFO_href->{FileInfo::PCORE_LV2_SIZE} = $nPcoreROM2Usage;
    $COPRO_INFO_href->{FileInfo::L1CORE_RWZI_SIZE} = $nL1coreTotalRamUsage;

    # shared memory size
    my ($region_size_tx, $region_size_rx) = &sysUtil::DSPTXRX_query_length(sysUtil::SwitchToClonedChip(FileInfo::GetChip()), $mode);
    my $nSharedRegionSize = hex(SymFileParser::GetLinkerSymbolAddress("SHARED_DNC_LENGTH", LinkerSymPostfix::Length, LinkerSymPrefix::Image))
                          + hex(SymFileParser::GetLinkerSymbolAddress("SHARED_NC_LENGTH", LinkerSymPostfix::Length, LinkerSymPrefix::Image))
                          + hex(SymFileParser::GetLinkerSymbolAddress("SHARED_DNC_MCURO_HWRW_LENGTH", LinkerSymPostfix::Length, LinkerSymPrefix::Image))
                          + hex(SymFileParser::GetLinkerSymbolAddress("SHARED_NC_MCURO_HWRW_LENGTH", LinkerSymPostfix::Length, LinkerSymPrefix::Image))
                          + hex(SymFileParser::GetLinkerSymbolAddress("SHARED_DNC_MCURW_HWRW_LENGTH", LinkerSymPostfix::Length, LinkerSymPrefix::Image))
                          + hex(SymFileParser::GetLinkerSymbolAddress("SHARED_NC_MCURW_HWRW_LENGTH", LinkerSymPostfix::Length, LinkerSymPrefix::Image))
                          + $region_size_tx
                          + $region_size_rx;
    $COPRO_INFO_href->{FileInfo::SHARED_REGION_SIZE} = CommonUtil::GetKBAligned($nSharedRegionSize, 64);

	# l1core dsp tx/rx length
    my $nL1coreDSP_Limit = hex(SymFileParser::GetLinkerSymbolAddress("L1CORE_DSP", LinkerSymPostfix::Limit, LinkerSymPrefix::None));
    my $nL1coreDSP_TXLength = hex(SymFileParser::GetLinkerSymbolAddress("L1CORE_EXTRAM_TXDATA", LinkerSymPostfix::ZILength, LinkerSymPrefix::None));
    my $nL1coreDSP_RXLength = hex(SymFileParser::GetLinkerSymbolAddress("L1CORE_EXTRAM_RXDATA", LinkerSymPostfix::ZILength, LinkerSymPrefix::None));

    $COPRO_INFO_href->{FileInfo::L1CORE_DSP_LIMIT} = $nL1coreDSP_Limit;
    $COPRO_INFO_href->{FileInfo::L1CORE_DSP_TX_LENGTH} = $nL1coreDSP_TXLength;
    $COPRO_INFO_href->{FileInfo::L1CORE_DSP_RX_LENGTH} = $nL1coreDSP_RXLength;


	# l1core memory dump (C)
	my $L1CoreC_Base = hex(SymFileParser::GetLinkerSymbolAddress("CACHED_EXTSRAM_L1DSPBIN_ZI", LinkerSymPostfix::Base, LinkerSymPrefix::Image));
	my $L1CoreC_Size = hex(SymFileParser::GetLinkerSymbolAddress("CACHED_EXTSRAM_NVRAM_LTABLE", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image)) -
                          $L1CoreC_Base;

	# l1core memory dump (DC)
	my $L1CoreDC_Base = hex(SymFileParser::GetLinkerSymbolAddress("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW", LinkerSymPostfix::Base, LinkerSymPrefix::Image));
	my $L1CoreDC_Size = hex(SymFileParser::GetLinkerSymbolAddress("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_DSP_SECTION", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image)) -
                        $L1CoreDC_Base;

	# l1core memory dump (NC)
	my $L1CoreNC_Base = hex(SymFileParser::GetLinkerSymbolAddress("EXTSRAM", LinkerSymPostfix::Base, LinkerSymPrefix::Image));
	my $L1CoreNC_Size = hex(SymFileParser::GetLinkerSymbolAddress("EXTSRAM", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image)) -
	                    $L1CoreNC_Base;

	# l1core memory dump (DNC)
	my $L1CoreDNC_Base = hex(SymFileParser::GetLinkerSymbolAddress("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI", LinkerSymPostfix::ZIBase, LinkerSymPrefix::Image));
	my $L1CoreDNC_Size = hex(SymFileParser::GetLinkerSymbolAddress("DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW", LinkerSymPostfix::Limit, LinkerSymPrefix::Image)) -
                         $L1CoreDNC_Base ;

    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__C_BASE} = $L1CoreC_Base;
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__C_SIZE} = $L1CoreC_Size;
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__DC_BASE} = $L1CoreDC_Base;
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__DC_SIZE} = $L1CoreDC_Size;
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__NC_BASE} = $L1CoreNC_Base;
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__NC_SIZE} = $L1CoreNC_Size;
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__DNC_BASE} = $L1CoreDNC_Base;
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__DNC_SIZE} = $L1CoreDNC_Size;


    # l1core memory dump (L2SRAM)
    my $L1CoreL2SRAM_DATA_Base = hex(SymFileParser::GetLinkerSymbolAddress("L2SRAM_DATA", LinkerSymPostfix::Base, LinkerSymPrefix::Image));
    my $L1CoreL2SRAM_DATA_ZI_ZILIMIT = hex(SymFileParser::GetLinkerSymbolAddress("L2SRAM_DATA_ZI", LinkerSymPostfix::ZILimit, LinkerSymPrefix::Image));

    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__L2SRAM_DATA_BASE}    = $L1CoreL2SRAM_DATA_Base;
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT} = $L1CoreL2SRAM_DATA_ZI_ZILIMIT;

    
    # get l1core vector load view
    $COPRO_INFO_href->{FileInfo::L1CORE_VECTOR} = hex(SymFileParser::GetLinkerSymbolAddress("INTSRAM_CODE", LinkerSymPostfix::Base, LinkerSymPrefix::Load));

    $COPRO_INFO_href->{FileInfo::L1CORE_SWLA_SIZE} = hex(SymFileParser::GetLinkerSymbolAddress("SWLA_REGION",LinkerSymPostfix::Length, LinkerSymPrefix::Image));

}

sub SetDefaultValue
{
    my ($COPRO_INFO_href) = @_;
    print "Set Default Value:\n";
    print "--------------------------------------------------------------\n";

    if ( &FileInfo::find("SINGLE_CORE_ONLY", "PCORE") )
    {
#        $COPRO_INFO_href->{FileInfo::PCORE_LV_SIZE}    = 0x700000;
        $COPRO_INFO_href->{FileInfo::PCORE_LV1_SIZE}   =  0xC00000; # 12MB
        $COPRO_INFO_href->{FileInfo::PCORE_LV2_SIZE}   =  0xA00000; # 10MB  # P total = 12 + 10 = 22 MB

        # reserve space for GFH + SIG
        $COPRO_INFO_href->{FileInfo::L1CORE_LV_SIZE}   = &sysUtil::GetSigSize() + 0x4; # always reserve 4 bytes for location counter
        $COPRO_INFO_href->{FileInfo::L1CORE_RWZI_SIZE} = &sysUtil::GetSigSize();
    }
    else
    {
#        $COPRO_INFO_href->{FileInfo::PCORE_LV_SIZE}    = 0x1800000; # 24MB  # P = 20 - 6 = 14 MB
        $COPRO_INFO_href->{FileInfo::PCORE_LV1_SIZE}   =  0xC00000; # 12MB
        $COPRO_INFO_href->{FileInfo::L1CORE_LV_SIZE}   =  0x600000; #  6MB
        $COPRO_INFO_href->{FileInfo::PCORE_LV2_SIZE}   =  0xA00000; # 10MB  # P total = 12 + 10 = 22 MB
        $COPRO_INFO_href->{FileInfo::L1CORE_RWZI_SIZE} =  0xC00000; # 12MB, it also control l1core RAM size
    }

    $COPRO_INFO_href->{FileInfo::SHARED_REGION_SIZE} = 0x0; # set it to zero for l1core to auto adjust size. watch out if you want to change it to non-zero value

    $COPRO_INFO_href->{FileInfo::L1CORE_DSP_LIMIT} =
    $COPRO_INFO_href->{FileInfo::L1CORE_DSP_TX_LENGTH} =
    $COPRO_INFO_href->{FileInfo::L1CORE_DSP_RX_LENGTH} = 0x0;
    
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__C_BASE} =
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__C_SIZE} =
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__DC_BASE}   =
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__DC_SIZE}   =
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__NC_BASE}   =
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__NC_SIZE}   =
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__DNC_BASE}  =
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__DNC_SIZE}  = 0;
    
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__L2SRAM_DATA_BASE}  =
    $COPRO_INFO_href->{FileInfo::L1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT}  = 0;

    $COPRO_INFO_href->{FileInfo::L1CORE_VECTOR} = 0;
    $COPRO_INFO_href->{FileInfo::L1CORE_SWLA_SIZE} = 0;
}

sub coproinfo_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'COPRO_INFO_GEN'); 
}
