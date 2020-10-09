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
#*   sysGenUtility.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module collects the subroutines for common utility. 
#*       
#*
#* Author:
#* -------
#*   Carl Kao (mtk08237)
#*
#****************************************************************************/

#****************************************************************************
# SYSGEN ERROR MESSAGE
#****************************************************************************
use FileInfoParser;

package genERR;
use constant SYSERR_1_1         => "SYSGEN ERROR: [1.1][Feature Option Related]";
use constant SYSERR_1_2         => "SYSGEN ERROR: [1.2][Memory Expired]";
use constant SYSERR_1_3         => "SYSGEN ERROR: [1.3][UnSupported/Wrong Configuration]";
use constant SYSERR_1_4         => "SYSGEN ERROR: [1.4][File/Path doesn't exist]";
use constant SYSERR_1_5         => "SYSGEN ERROR: [1.5][Other errors]";
use constant SYSERR_2_0         => "SYSGEN ERROR: [2.0]";
use constant SYSERR_3_1         => "SYSGEN ERROR: [3.1]";
use constant SYSERR_3_2         => "SYSGEN ERROR: [3.2]";

package sysUtil;
use strict;
use Cwd;
#use warnings;

#****************************************************************************
# Constants
#****************************************************************************

my $SYSGENUTILITY_VERNO     = " LR11_v0.11";
           # LR11_v0.11,   2017/May/24, Carl,   New Layout
           # LR11_v0.10,   2016/12/01,  Tero,   Added MT6750S to SwitchToClonedChipForCMM
           # LR11_v0.09,   2016/11/24,  Tero,   Support for MT6750S
           # LR11_v0.08,   2016/09/26,  Tero,   Added SwitchToClonedChipForCMM
           # LR11_v0.07,   2016/07/28,  Tero,   Support for MT6757P
           # LR11_v0.06,   2016/07/20,  Tero,   Add support MT6757P -> MT6757 for SwitchToClonedChip
           # LR11_v0.05,   2015/11/19,  Carl,   Remove support MT6757 for SwitchToClonedChip
           # LR11_v0.04,   2015/11/19,  Carl,   Support MT6750 and MT6757 for SwitchToClonedChip
           # LR11_v0.03,   2015/11/09,  Tero,   Support MT6750 and MT6757
           # LR11_v0.02,   2015/11/02,  Carl,   Change DSP TX/RX sections to ZI (.bss) section
           # LR11_v0.01,   2015/08/31,  Carl,   Reduce total memory size of MT6755 and MT6797 from 160MB to 128MB (add GetMDTotolSizeLimitation())
             # u0.21, 2015/07/20,  Carl,   Support ldsGen for MT6797
             # u0.20, 2015/07/03,  Carl,   Add GetDefaultSharedMemorySize for setting default shared memory size
             # u0.19, 2015/06/04,  Carl,   Support ldsGen for MT6755
             # u0.18, 2015/05/11,  Carl,   Support Ramdisk for TK6291
             # u0.17, 2015/02/06,  disable isSupportedToAdjustLoadView for ESL COSIM
             # u0.16, 2015/01/06,  lds refinement: 1) auto adjust shared region size, 2) reserve pcore, l1core SWLA space
             # u0.15, 2014/11/05,  Align start address of shared memory section to 1MB
             # u0.14, 2014/10/06,  Increase default shared memory size to 48 MB
             # u0.13, 2014/09/26,  Support GFH + SIG
             # u0.12, 2014/09/22,  Rename MT6291 to TK6291
             # u0.11, 2014/09/09,  Revert default shared memory size since there are still shared memory users  
             # u0.10, 2014/09/05,  Reduce default shared memory size for PCORE ONLY project
             # ...
             # m0.32, 2014/01/02, Let aapmc apply on modem only load for load view part 
             # m0.31, 2013/11/06, Support MT6595
             # m0.30, 2013/09/11, MT6290=SV5
             # m0.29, 2013/05/21, Support MT6290_COPRO
             # m0.28, 2013/03/21, Support GetMD_AlignmentByChip()
             # m0.27, 2013/02/03, Rename MT7208 to MT6290
             # m0.26, 2013/01/24, Enable MT6280 to be able to auto-config LoadView part
             # m0.25, 2013/01/16, Add isSupportedToAdjustLoadView() and isSupportedToAdjustRAMSize()
             # m0.24, 2013/01/15, Support address prefix query function
             #                    Remove useless chip
             # m0.22, 2012/12/28, Add MT7208 into XIP_Shadowing
             # m0.21, 2012/10/31, Refine Error Message not to meet \w+ for easier function naming in ldsGen
             # m0.20, 2012/10/02, Support MT7208
             # m0.17, 2012/09/02, Support ALPS database check-in history 
             # m0.16, [Reserved for WR8]
             # m0.15, 2012/08/17, Support Total RAM size in smartphone
             #                    Support MT6583 MD1/MD2
             # m0.14, 2012/08/13, Support MT6577
             # m0.13, 2012/08/07, Move Dec2Hex to CommonUtility.pm and add isDummyScatter()
             # m0.12, 2012/07/24, Support sysgen common error code/messages.
             # m0.11, 2012/07/12, Remove booting type query to FileInfoParser.pm
             # m0.10, 2012/07/02, Remove PrintDependency() to use tools::pack_dep_gen; PrintDependModule();
             # m0.09, 2012/07/02, Support SwitchToClonedChip
             # m0.08, 2012/06/28, Support MOLY database check-in history 
             # m0.07, 2012/05/28, Support path and filename case sensitive on Linux
             # m0.06, 2012/05/01, Support lds description_file_header
             # m0.05, 2012/01/20, Support NOR for CR4 
             # m0.04, 2012/01/13, Support MT6280 BLscatGen
             # m0.03, 2012/01/13, Remove MT6280 from SmartPhone
             # m0.02, 2012/01/08, Support MT6280
             # m0.01 , 2012/05/07, Move DSPTXRX_query_length from scatGenLib.pl to here.
             # v0.22 , 2012/04/12,  Modify GetIntsramInfo() to enhance 6250 FTE performance
             # v0.21 , 2012/03/26,  Modify the query method of vivaHelper.pm in query_viva_size()
             # v0.20 , 2012/03/22,  Add query_viva_size to support VIVA
             # v0.19 , 2012/03/21,  Support MT6250
             # v0.18 , 2012/04/17,  Support EWS to print file dependency
             # v0.17 , 2012/02/14,  Add check_cs1_base() and modify query_cs1_addr() to determine CS1 base address
             # v0.16 , 2012/01/30,  Support MT6922
             # v0.15 , 2012/01/28,  Add is_NOR() without supporting smartphone part
             # v0.14 , 2012/01/08,  Add is_CR4(), GetIntsramHWBoundary() and Support TK6280
             # v0.13 , 2012/01/08,  Add GetIntsramInfo() to get intsram CODE/DATA's information
             # v0.12 , 2012/01/08,  Remove has_cache()
             # v0.11 , 2011/11/04,  Remove phased-out chips and add is_arm7()
             # v0.10 , 2011/10/29,  modify query_cs1_addr for MT6255 bootloader workaround
             # v0.09 , 2011/10/28,  To support MT6255
             # v0.08 , 2011/10/28,  print an error message if the file can't be deleted
             # v0.07 , 2011/10/10,  Add has_cache()
             # v0.06 , 2011/09/25,  Move ChangeDefineValue() to auto_adjust_mem.pm and 
             #                      seperate HasCheckinHistory out from del_noCheckinHistory_file
             # v0.05 , 2011/09/16,  Add ChangeDefineValue() for common usage 
             #                      if needed to modify define value in some header files.
             # v0.04 , 2011/09/15,  Collect common functions which can be reused
             # v0.02 , 2011/05/24,  Support MT6921 in arm9 family
             # v0.01 , 2011/03/30,  Initial revision

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# Subroutine:  sysgenUtility_verno - to query this package's version number
# Parameters:  x
# Returns:     version number string
#****************************************************************************
sub sysgenUtility_verno
{
    return $SYSGENUTILITY_VERNO;
}

#****************************************************************************
# Subroutine:  GetIntsramInfo - to query INTSRAM_CODE and INTSRAM_DATA's Base/MaxSize
# Parameters:  BB chip  (eg. MT6276)
# Returns:     $strCODEBase, $strCODESize, $strDATABase, $strDATASize
#****************************************************************************
sub GetIntsramInfo
{#unsupported on ldsGen's chip
    my ($bb) = @_;
    my ($strCODEBase, $strCODESize, $strDATABase, $strDATASize) = (undef, undef, undef, undef);
    my %BB_INTSRAM_tbl =
       (        # $bb => [INTSRAM_CODE_Base, INTSRAM_CODE_Size, INTSRAM_DATA_Base, INTSRAM_DATA_Size]
                # 'TK6291'  => ["0xBF000000", "0x40000",    "0xBF040000", "0x00040000"],
       );
    if(exists $BB_INTSRAM_tbl{$bb})
    {
        $strCODEBase = $BB_INTSRAM_tbl{$bb}[0];
        $strCODESize = $BB_INTSRAM_tbl{$bb}[1];
        $strDATABase = $BB_INTSRAM_tbl{$bb}[2];
        $strDATASize = $BB_INTSRAM_tbl{$bb}[3];
    }
    return ($strCODEBase, $strCODESize, $strDATABase, $strDATASize);
}
#****************************************************************************
# Subroutine:  GetIntsramHWBoundary - to query INTSRAM_PHYSICAL_BOUNDARY's Base/MaxSize
# Parameters:  BB chip  (eg. MT6276)
# Returns:     $strBase, $strSize
#****************************************************************************
sub GetIntsramHWBoundary
{#unsupported on ldsGen's chip
    my ($bb) = @_;
    my ($strBase, $strSize) = (undef, undef);
    my %BB_tbl =
       (        # $bb => [ Base, Size]
                #'MT6290'  => ["0xBF040000", "0x00040000"],
       );
    if(&is_CR4($bb)==1 and exists $BB_tbl{$bb})
    {
        $strBase = $BB_tbl{$bb}[0];
        $strSize = $BB_tbl{$bb}[1];
    }
    return ($strBase, $strSize);
}
#****************************************************************************
# Subroutine:  is_arm7 - Query if it's ARM7 Family
# Parameters:  BB chip  (eg. MT6276)
# Returns:     1=belongs arm7 family, undef=not arm7 family
#****************************************************************************
sub is_arm7
{
    my ($bb) = @_;
    my %BBtbl_ARM7_Family =
       (        
                #'MT6290_COPRO' => 1,
       );
    return $BBtbl_ARM7_Family{$bb};
}
#****************************************************************************
# subroutine: is_mpu_capable - Query if it has mpu capability
# Input:      BB chip  (eg. MT6276)
# Output:     1=has mpu capability, others=doesn't have mpu capability
#****************************************************************************
sub is_mpu_capable
{
    my ($bb) = (@_);
    my $nDefault_MPU_Capability = 1;
    my %BBtbl_MPU_Capability =
       (       
                #'TK6291' => 1,
                #'MT6755' => 1,
       );
    return (exists $BBtbl_MPU_Capability{$bb} ? 
        $BBtbl_MPU_Capability{$bb} : $nDefault_MPU_Capability);
}

#****************************************************************************
# Subroutine:  is_arm9 - Query if it's ARM9 Family
# Parameters:  BB chip (eg. MT6235)
# Returns:     1=belongs arm9 family, undef=not arm9 family
#****************************************************************************
sub is_arm9
{
    my ($bb) = @_;
    my %BBtbl_ARM9_Family =
       (        
            #'MT6589_MD2'  => 1,
       );
    return $BBtbl_ARM9_Family{$bb};
}


#****************************************************************************
# Subroutine:  is_arm11 - Query if it's ARM11 Family
# Parameters:  BB chip  (eg. MT6276)
# Returns:     1=belongs arm11 family, undef=not arm11 family
#****************************************************************************
sub is_arm11
{
    my ($bb) = @_;
    my %BBtbl_ARM11_Family =
       (        
               # 'MT6577'  => 1,
       );
    return $BBtbl_ARM11_Family{$bb};
}

#****************************************************************************
# Subroutine:  is_CR4 - Query if it's CR4
# Parameters:  BB chip  (eg. MT6280)
# Returns:     1=belongs CR4, undef=not CR4
#****************************************************************************
sub is_CR4
{
    my ($bb) = @_;
    my $nDefault_CR4_Family = 1;
    my %BBtbl_CR4_Family =
       (        
                #'TK6291'  => 1,
                #'MT6755'  => 1,
       );
    return (exists $BBtbl_CR4_Family{$bb} 
        ? $BBtbl_CR4_Family{$bb} : $nDefault_CR4_Family);
}

#****************************************************************************
# Subroutine:  is_LTE - Query if it's LTE project
# Parameters:  BB chip  (eg. MT6280)
# Returns:     1=belongs CR4, undef=not CR4
#****************************************************************************
sub is_LTE
{
    my ($bb) = @_;
    my $nDefault_LTE_Family = 1;
    my %BBtbl_LTE_Family =
       (        
                #'TK6291'  => 1,
                #'MT6755'  => 1,
       );
    return (exists $BBtbl_LTE_Family{$bb}
        ? $BBtbl_LTE_Family{$bb}: $nDefault_LTE_Family);
}


#****************************************************************************
# subroutine:  Query if it has MMU(arm9, arm11, mtkmmu) or MPU (CR4)
#              to map the address like 0xf------- 
# input:       BB chip  (eg. MT6276)
# Output:      0=non-mmu, 1=it has mmu
#****************************************************************************
sub is_mmu
{
	my ($bb) = (@_);
	my $nIsMMU = 0; #0=non-MMU, 1=hasMMU;
	my %BBtbl_MTKMMU_Family =
       (        
                'MT6252'   => 1,
                'MT6252H'  => 1,
                'MT6250'   => 1,
       );
    #############
    # WARNING,  return 1 if $bb = CR4
    #############
	if(&is_arm9($bb) or &is_arm11($bb) or defined $BBtbl_MTKMMU_Family{$bb} or &is_CR4($bb))
	{
		$nIsMMU = 1;
	}
	return $nIsMMU;	
}
#****************************************************************************
# subroutine: is_sv5 - Query if it's SV5 Family
# Input:      BB chip  (eg. MT6276)
# Output:     1=belongs sv5 family, undef=not sv5 family
#****************************************************************************
sub is_sv5
{
    my ($bb) = (@_);
    my $nDefault_SV5_Family = 1;
    my %BBtbl_SV5_Family =
       (        
                #'TK6291'  => 1,
                #'MT6755'  => 1,
       );
    return (exists $BBtbl_SV5_Family{$bb}
        ? $BBtbl_SV5_Family{$bb}: $nDefault_SV5_Family);
}

#****************************************************************************
# subroutine: DSPTXRX_query_length
# purpose : Exec View :: DSP TX RX :: Size Of TX RX query
# Input:      1. $bb: e.g. MT6280 
#             2. $mode: e.g. BASIC, L1S, GSM, GPRS, UMTS
# Output:     (nTXLength, nRXLength)
#****************************************************************************
sub DSPTXRX_query_length
{
   # remember to sync the setting to DSPTXRX_query_length in L1coreSysGenUtility.pm

    my ($bb, $mode) = @_;
    # --- --- --- 
    my %BBtbl_l1s_tx =
       (
            #'TK6291'  => 0x20000,            # format: '"chip"' -> 'size'
       );
       #map {print $_, "\n";} keys %BBtbl;
    my %BBtbl_l1s_rx =
       (
            #'TK6291'  => 0x20000,            # format: '"chip"' -> 'size'
       );
       #map {print $_, "\n";} keys %BBtbl;
    # --- --- --- 
    
    my ($nTX, $nRX) = (0x10000, 0x20000); #default on MD are 64KB, 128KB

    ($nTX, $nRX) = (0x20000, 0x20000) if ($mode =~ /L1S/i);

if(0) {
    if ((exists $BBtbl_l1s_tx{$bb}) and (exists $BBtbl_l1s_rx{$bb}))
    {
        ($nTX, $nRX) = ($BBtbl_l1s_tx{$bb}, $BBtbl_l1s_rx{$bb});
    }
}

    return ($nTX, $nRX)
}

#****************************************************************************
# subroutine:  determine CS1 base address
# input:       BB chip
# Output:      1 = CS1 base address is 0x08000000, others = CS1 base address is 0x10000000
#****************************************************************************
sub check_cs1_base
{
    my ($bb) = (@_);
    my %BBtbl_cs1_base =
       (
            #'MT6251'  => 1,
       );
    return $BBtbl_cs1_base{$bb};

}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: CS1 base address
# Note      :  this function doesn't guarantee if the chip needs to remap.
#              it only returns the address if needing remapping.
# input:       BB chip, base address(if no input, it's 0 in default), isBootloader(undef or 0= not bootloader)
# Output:      CS1 default base address
#****************************************************************************
sub query_cs1_addr
{
    my ($bb, $nBaseAddress, $bisBL) = @_;
    $nBaseAddress = 0 if(!defined $nBaseAddress);
    my $nCS1BaseAddress = $nBaseAddress;
    if (&check_cs1_base($bb) == 1)
    {
        $nCS1BaseAddress = $nBaseAddress ^ 0x08000000;
    }
    else
    {
        $nCS1BaseAddress = $nBaseAddress ^ 0x10000000;
    }
    if(defined $bisBL and $bisBL != 0)
    {
        if($bb eq "MT6255")
        {
            $nCS1BaseAddress = $nBaseAddress;
        }
    }
    return $nCS1BaseAddress;
}
#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: viva header size
# note:        This function is used to get viva header size if
#              DCMP support or ZIMAGE support or ALICE support
# input:       BB chip
# Output:      viva header size
#****************************************************************************
sub query_viva_size
{
    require "pcore/tools/vivaHelper.pm";
    my ($bb) = @_;
    my $viva_size = &vivaHelper::GetVIVAHeaderSize_NI(&is_sv5($bb));
    return $viva_size;
}
#****************************************************************************
# subroutine:  is_XIP_Shadowing
# Note      :  this function is to query which chip needs to do shadowing
#              due to speeding up on NOR or Serial Flash
# input:       BB chip
# Output:      0=unsupported, 1=supported
#****************************************************************************
sub is_XIP_Shadowing
{
    my ($bb) = @_;
    my $nDefault_XIP_Family = 1;
    my %BBtbl_XIP_Family =
       (        
            #'TK6291'  => 1,            
            #'MT6755'  => 1,
       );
    return (exists $BBtbl_XIP_Family{$bb}
        ? $BBtbl_XIP_Family{$bb}: $nDefault_XIP_Family);
}

#****************************************************************************
# subroutine:  SwitchToClonedChip
# Note      :  this function is to get original cloned chip 
#              otherwises it returns input chip.
# input:       strBBChip (e.g. MT6280) 
# Output:      strBBChip (e.g. MT6280)
#****************************************************************************
sub SwitchToClonedChip
{
    my ($bb) = @_;
    my %BBtbl_Family =
       (
            "MT6757P"  => "MT6757",
            "MT6750S"  => "MT6750",
       );
    $bb = $BBtbl_Family{$bb} if(defined $BBtbl_Family{$bb});
    return $bb;
}

#****************************************************************************
# subroutine:  SwitchToClonedChipForCMM
# Note      :  this function is to get original cloned chip 
#              otherwises it returns input chip.
# input:       strBBChip (e.g. MT6280) 
# Output:      strBBChip (e.g. MT6280)
#****************************************************************************
sub SwitchToClonedChipForCMM
{
    my ($bb) = @_;
    my %BBtbl_Family =
       (
            "MT6750"  => "MT6755",
            "MT6757P"  => "MT6757",
            "MT6750S"  => "MT6755",
       );
    $bb = $BBtbl_Family{$bb} if(defined $BBtbl_Family{$bb});
    return $bb;
}

#****************************************************************************
# subroutine:  isSupportedtoAdjustLoadView
# Note      :  this function is to get if this chip supported AAPMC to adjust rom length and ram base
# input:       strBBChip (e.g. MT6280) 
# Output:      0: not supported, 1= supported by default
#****************************************************************************
sub isSupportedToAdjustLoadView
{
    my ($bb) = @_;
    my $bSupported = 1; # support to adjust ROM Length and RAM base by default
    $bb = SwitchToClonedChip($bb);
    my %BBtbl_Family =
       (        
            #"TK6291"  => 1,
       );
    $bSupported = $BBtbl_Family{$bb} if(defined $BBtbl_Family{$bb});
    $bSupported = 1 if(FileInfo::is("ORIGINAL_FLAVOR", "SLT")); #SLT default = md only load
    $bSupported = 0 if(BuildInfo::exist(BuildOPT::CMPL, "__ESL_COSIM_LTE__"));
    return $bSupported;
}
#****************************************************************************
# subroutine:  isSupportedToAdjustRAMSize
# Note      :  this function is to get if this chip supported AAPMC to adjust RAM Length
# input:       strBBChip (e.g. MT6280) 
# Output:      0: not supported by default, 1= supported 
#****************************************************************************
sub isSupportedToAdjustRAMSize
{
    my ($bb) = @_;
    my $bSupported = 1; # do support to adjust RAM Length by default
    $bb = SwitchToClonedChip($bb);
    my %BBtbl_Family =
       (        
            #"TK6291"  => 1,
       );
    $bSupported = $BBtbl_Family{$bb} if(defined $BBtbl_Family{$bb});
    $bSupported = 0 if(FileInfo::is("SMART_PHONE_CORE", "MODEM_ONLY"));
    $bSupported = 1 if(FileInfo::is("ORIGINAL_FLAVOR", "SLT")); #SLT default = md only load
    $bSupported = 0 if(FileInfo::is("FS_RAMDISK", "TRUE"));
    return $bSupported;
}

#****************************************************************************
# subroutine:  GetMDTotolSizeLimitation
# Note      :  this function is to get total MD size by chip
# input:       strBBChip (e.g. MT6280) 
# Output:      total MD size
#****************************************************************************
sub GetMDTotolSizeLimitation
{   # remember to check shared memory size in GetDefaultSharedMemorySize ( sysGenUtility.pm)
    # please keep the same condition as GetMDTotolSize @ ldsGenLib.pl
    my ($bb) = @_;

    # this real MD size setting, check it in AutoAdjust() @ ModemReservedSize_AutoConfig.pl
    my %BBtbl_MD_size = 
    (
        'TK6291'  => 0x10000000,    # 256 MB
        'MT6755'  =>  0x8000000,    # 128 MB
        'MT6797'  =>  0x8000000,    # 128 MB
        'MT6750'  =>  0x8000000,    # 128 MB
        'MT6750S'  =>  0x8000000,    # 128 MB
        'MT6757'  =>  0x8000000,    # 128 MB
        'MT6757P'  =>  0x8000000,    # 128 MB
    );

    my $MD_with_ramdisk_default_size = 0x10000000;  # 256 MB
    my %BBtbl_MD_with_ramdisk_size = 
    (   # format: '"chip"' -> 'size'    
    );    
    
    &sysUtil::sysgen_die("No default MD total size for this chip $bb !", __FILE__, __LINE__) 
        if (!exists $BBtbl_MD_size{$bb});

    # for ramdisk or MD only load
    if ( FileInfo::is("FS_RAMDISK", "TRUE")
        or FileInfo::is("SMART_PHONE_CORE", "MODEM_ONLY") )
    {
        return $BBtbl_MD_with_ramdisk_size{$bb} if (exists $BBtbl_MD_with_ramdisk_size{$bb});
        return $MD_with_ramdisk_default_size;
    }

    # return default size
    return $BBtbl_MD_size{$bb};
}

#****************************************************************************
# subroutine:  GetDefaultSharedMemorySize
# Note      :  this function is to get default shared memory size by chip, for 1st linking
# input:       strBBChip (e.g. MT6280) 
# Output:      $nAlignment: default =1 
#****************************************************************************
sub GetDefaultSharedMemorySize
{   #remember to check MD total size in GetMDTotolSize (ldsGenLib.pl)

    my ($bb) = @_;

    my %BBtbl_SHMsize =
    (        
        'TK6291'  => 0x8000000,     # 128 MB
        'MT6755'  => 0x5000000,     #  80 MB
        'MT6797'  => 0x5000000,     #  80 MB
        'MT6750'  => 0x5000000,     #  80 MB
        'MT6750S' =>  0x5000000,    #  80 MB
        'MT6757'  => 0x5000000,     #  80 MB
        'MT6757P'  => 0x5000000,     #  80 MB
    );
  
    my $SHM_with_ramdisk_default_size = 0x8000000;   # 128 MB
    my %BBtbl_SHM_with_ramdisk_size = 
    (   # format: '"chip"' -> 'size'
    );

    &error_handler("No default shared memory size for this chip $bb", __FILE__, __LINE__)
        if(! exists $BBtbl_SHMsize{$bb});

    # for ramdisk or MD only load
    if ( FileInfo::is("FS_RAMDISK", "TRUE")
        or FileInfo::is("SMART_PHONE_CORE", "MODEM_ONLY") )
    {
        return $BBtbl_SHM_with_ramdisk_size{$bb} if (exists $BBtbl_SHM_with_ramdisk_size{$bb});
        return $SHM_with_ramdisk_default_size;
    }

    # return default size
    return $BBtbl_SHMsize{$bb};
}

#****************************************************************************
# subroutine:  GetMD_AlignmentByChip
# Note      :  this function is to get MD Ram Alignment by chip
# input:       strBBChip (e.g. MT6280) 
# Output:      $nAlignment: default =1 
#****************************************************************************
sub GetMD_AlignmentByChip
{
    my ($bb) = @_;
    my $nAlignment = 1; #1MB aligned
    my %BBtbl_Alignment =
    (        
            #'MT6582'  => 2,
    );
    if(exists $BBtbl_Alignment{$bb})
    {
        $nAlignment = $BBtbl_Alignment{$bb};
    }
    return $nAlignment;
}

#****************************************************************************
# subroutine:  GetMD_AlignmentByChip
# Note      :  this function is to get MD Ram Alignment by chip
# input:       strBBChip (e.g. MT6280) 
# Output:      $nAlignment: default =1 
#****************************************************************************
sub GetCopro_KBAlignment
{
    my ($strCopro) = @_;
    my $nAlignment = 1024; # 1MB aligned
    my %BBtbl_Alignment =
    (        
 #           'L1CORE'  => 4,
    );
    if(exists $BBtbl_Alignment{$strCopro})
    {
        $nAlignment = $BBtbl_Alignment{$strCopro};
    }
    return $nAlignment;
}


#****************************************************************************
# Subroutine:   GetNonCacheablePrefix
# Parameters:   strBBChip (e.g. MT6280) 
# Returns:      an bank adress for OR
#               default: 0x0
#****************************************************************************
sub GetNonCacheablePrefix
{
    my ($bb) = @_;
    my %BBtbl_Family =
       (        
            
       );
    my $prefix = 0;
    $prefix = $BBtbl_Family{$bb} if(defined $BBtbl_Family{$bb});
    return $prefix;
}
#****************************************************************************
# Subroutine:   GetCacheablePrefix
# Parameters:   strBBChip (e.g. MT6280) 
# Returns:      an bank adress for OR
#               default: 0xF0000000
#****************************************************************************
sub GetCacheablePrefix
{
    my ($bb) = @_;
    my %BBtbl_Family =
       (
            
       );
    my $prefix = 0xA0000000;
    $prefix = $BBtbl_Family{$bb} if(defined $BBtbl_Family{$bb});
    return $prefix;

}
#****************************************************************************
# Subroutine:   del_noCheckinHistory_file
# Parameters:   one file path
# Returns:      N/A
#****************************************************************************
sub del_noCheckinHistory_file
{
    my ($filepath) = @_;
    return unless (-e $filepath);

    my $nHas = &HasCheckinHistory($filepath);
    if($nHas == 1)
    {
        print "$filepath: Check-in message is found. No need to update.\n";
    }
    elsif($nHas == 0)
    {
        unlink $filepath;
        print "$filepath can't be deleted properly!\n" if(-f $filepath);
    }
    return;
}
#****************************************************************************
# Subroutine:   HasCheckinHistory
# Parameters:   one file path
# Returns:      undef=not exists, 0=no history, 1=has history
#****************************************************************************
sub HasCheckinHistory
{
    my ($filepath) = @_;
    return undef unless (-e $filepath);
    my $nReturn = 0; # Empty=not exists, 0=no history, 1=has history

    ## Now check if the $target file check-in or auto-gen
    open SRC_FILE_R , "<$filepath" or &error_handler("$filepath: file error!", __FILE__, __LINE__);
    my $reading;
    {
		local $/;
		$reading = <SRC_FILE_R>; 
	}    
    close SRC_FILE_R;

    ## Look for check-in pattern ##
    if (($reading =~ /\[MAUI_\d{8}\]|\[MOLY\d{8}\]|\[ALPS\d{8}\]/) or ($reading =~ /MANUAL-CHECKIN/i))
    {
        return 1;
    }   
    return 0;
}
#****************************************************************************
# Subroutine:   isDummyScatter
# Parameters:   $bINSIDE_MTK = 0 or 1, $strDUMMY_SCATTER_FORCE = TRUE or FALSE
# Returns:      0=not dummy , 1=is dummy
#****************************************************************************
sub isDummyScatter
{
    my ($bINSIDE_MTK, $strDUMMY_SCATTER_FORCE) = @_;
    my $bIsDummy = 0; #not dummy by default
    if (1 == &FileInfo::is_NOR())
    {
        if(&FileInfo::is('dummy_scatter_enable', "TRUE"))
        {
            $bIsDummy = 1 if($bINSIDE_MTK == 1);
        }
    }
    $bIsDummy = 1 if($strDUMMY_SCATTER_FORCE eq 'TRUE');
    return $bIsDummy;
}

sub GetSigSize_X
{
	return 256;
}




#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no, $strTitle) = @_;
       
    my $final_error_msg = "$strTitle ERROR: $error_msg at $file line $line_no : $!\n";
    print $final_error_msg;
    die $final_error_msg;
}

sub sysgen_die
{
    my ($error_msg, $file, $line_no) = @_;
    &error_handler($error_msg, $file, $line_no, 'SYSGEN');
}
sub sysUtil_die
{
    my ($error_msg, $file, $line_no) = @_;
    &error_handler($error_msg, $file, $line_no, 'SYSGENUTILITY');
}

#****************************************************************************
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
# input:       $strComment:   optional
# input:       $bAutoGen      optional: 1=AutoGen, 0 or undef = not AutoGen
#****************************************************************************
sub description_file_header
{
    my ($filename, $description, $author, $strComment, $bAutoGen) = @_;
    $filename =~ s/.*\///;
    my $strAutoGeneratedDate = " *\n";
    my $strWarning;
    if($bAutoGen == 1)
    {
        my ($day, $month, $year) = (localtime)[3,4,5]; $month++; $year+=1900;
        $strAutoGeneratedDate = <<"__TEMPLATE";
 *
 * Auto Generated Date:
 * -------
 *   $year/$month/$day
 *
__TEMPLATE
        $strWarning = <<"__TEMPLATE";
 * This file is auto-generated and please DO NOT change the content at will
 *=========================================================================
__TEMPLATE
        $strComment = $strWarning.$strComment;
    }
    my $template = <<"__TEMPLATE";
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   $filename
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   $description
 *
 * Author:
 * -------
 *   $author
$strAutoGeneratedDate
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * \$Revision\$
 * \$Modtime\$
 * \$Log\$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
$strComment
 ****************************************************************************/

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  copyright_file_header
# return:      file header -- copyright
#****************************************************************************
sub copyright_file_header
{
    my $template = <<"__TEMPLATE";
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

__TEMPLATE

   return $template;
}
