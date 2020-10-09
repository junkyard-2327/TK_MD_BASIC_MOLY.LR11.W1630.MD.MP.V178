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
#*   L1coreSysGenUtility.pm
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
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './l1core/tools/' }  # add additional library path
use L1coreFileInfoParser;
#****************************************************************************
# SYSGEN ERROR MESSAGE
#****************************************************************************
package genERR;
use constant SYSERR_1_1         => "SYSGEN ERROR: [1.1][Feature Option Related]";
use constant SYSERR_1_2         => "SYSGEN ERROR: [1.2][Memory Expired]";
use constant SYSERR_1_3         => "SYSGEN ERROR: [1.3][UnSupported/Wrong Configuration]";
use constant SYSERR_1_4         => "SYSGEN ERROR: [1.4][File/Path doesn't exist]";
use constant SYSERR_1_5         => "SYSGEN ERROR: [1.5][Other errors]";
use constant SYSERR_2_0         => "SYSGEN ERROR: [2.0]";
use constant SYSERR_3_1         => "SYSGEN ERROR: [3.1]";
use constant SYSERR_3_2         => "SYSGEN ERROR: [3.2]";

package L1coreSysUtil;
use strict;
use Cwd;
#use warnings;

#****************************************************************************
# Constants
#****************************************************************************
my $SYSGENUTILITY_VERNO     = " LR11_v0.07";
           # LR11_v0.07,   2016/12/01,  Tero,   Added MT6750S to SwitchToClonedChipForCMM
           # LR11_v0.06,   2016/11/24,  Tero,   Support for MT6750S
           # LR11_v0.05,   2016/09/26,  Tero,   Added SwitchToClonedChipForCMM
           # LR11_v0.04,   2016/07/20,  Tero,   Add support MT6757P -> MT6757 for SwitchToClonedChip
           # LR11_v0.03,   2015/11/19,  Carl,   Remove support MT6757 for SwitchToClonedChip
           # LR11_v0.02,   2015/11/19,  Carl,   Support MT6750 and MT6757
           # LR11_v0.01,   2015/11/02,  Carl,   Change DSP TX/RX sections to ZI (.bss) section
                              # u0.09,   2015/07/20,  Carl,   Support ldsGen for MT6797
                              # u0.08,   2015/06/04,  Carl,   Support ldsGen for MT6755
                              # u0.07,   2014/09/22,  Carl,   Rename MT6291 to TK6291
                              # ...
                              # v0.01_U3GDEV , 2013/11/11,  Refined GetIntsramInfo()
                              # v0.01 , 2013/07/01,  Initial revision

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
# Parameters:  BB chip  (eg. TK6291)
#              CoreType  (eg. l1core/brp)
# Returns:     $strCODEBase, $strCODESize, $strDATABase, $strDATASize
#****************************************************************************
sub GetIntsramInfo
{
    my ($bb, $CoreType) = @_;
    my ($strCODEBase, $strCODESize, $strDATABase, $strDATASize) = (undef, undef, undef, undef);
    my %BB_INTSRAM_tbl =
    (   
        #$CoreType => [INTSRAM_CODE_Base, INTSRAM_CODE_Size, INTSRAM_DATA_Base, INTSRAM_DATA_Size]
        #'TK6280' => {    'l1core'  => ["0x0", "0x40000", "0x0" , "0x40000"],        }

        # $bb => [INTSRAM_CODE_Base, INTSRAM_CODE_Size, INTSRAM_DATA_Base, INTSRAM_DATA_Size]
        #'TK6291'  => ["0xBF000000", "0x40000",    "0xBF040000", "0x00040000"],
    );
    if(exists $BB_INTSRAM_tbl{$bb})
    {
        $strCODEBase = $BB_INTSRAM_tbl{$bb}[0];
        $strCODESize = $BB_INTSRAM_tbl{$bb}[1];
        $strDATABase = $BB_INTSRAM_tbl{$bb}[2];
        $strDATASize = $BB_INTSRAM_tbl{$bb}[3];
    }
#    if(exists $BB_INTSRAM_tbl{$bb}{$CoreType})
#    {
#        $strCODEBase = $BB_INTSRAM_tbl{$bb}{$CoreType}[0];
#        $strCODESize = $BB_INTSRAM_tbl{$bb}{$CoreType}[1];
#        $strDATABase = $BB_INTSRAM_tbl{$bb}{$CoreType}[2];
#        $strDATASize = $BB_INTSRAM_tbl{$bb}{$CoreType}[3];
#    }

    return ($strCODEBase, $strCODESize, $strDATABase, $strDATASize);
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
                #'TK6291'  => 1,
                #'MT6755'  => 1,
       );
    #############
    # WARNING,  return 1 if $bb = CR4  -> is_mmu is a legacy function 
    #############
	if(defined $BBtbl_MTKMMU_Family{$bb} or &is_CR4($bb))
	{
		$nIsMMU = 1;
	}
	return $nIsMMU;	
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
   # remember to sync the setting to DSPTXRX_query_length in sysGenUtility.pm
   
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
    my $bSupported = 0; # support to adjust ROM Length and RAM base by default
    $bb = SwitchToClonedChip($bb);
    my %BBtbl_Family =
       ( 
            #################
            # FIX_ME, set to 1 after AAPMC is fixed
            #################
            #"TK6291"  => 0,
            #"MT6755"  => 0,
       );
    $bSupported = $BBtbl_Family{$bb} if(defined $BBtbl_Family{$bb});
    $bSupported = 1 if(L1coreFileInfo::is("ORIGINAL_FLAVOR", "SLT")); #SLT default = md only load
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
            #################
            # FIX_ME, set to 1 after AAPMC is fixed
            #################
            "TK6291"  => 0,
            #"MT6755"  => 1,
       );
    $bSupported = $BBtbl_Family{$bb} if(defined $BBtbl_Family{$bb});
    $bSupported = 0 if(L1coreFileInfo::is("SMART_PHONE_CORE", "MODEM_ONLY"));
    $bSupported = 1 if(L1coreFileInfo::is("ORIGINAL_FLAVOR", "SLT")); #SLT default = md only load
    return $bSupported;
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
            'L1CORE'  => 4,
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
# Subroutine:   GetCacheLineSize
# Parameters:   N/A
# Returns:      cache line size, default= 32
#****************************************************************************
sub GetCacheLineSize
{
    return 32;
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
        $nReturn = 1;
    }   
    return $nReturn;
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
    if(&L1coreFileInfo::is('dummy_scatter_enable', "TRUE"))
    {
        $bIsDummy = 1 if($bINSIDE_MTK == 1);
    }

    $bIsDummy = 1 if($strDUMMY_SCATTER_FORCE eq 'TRUE');
    return $bIsDummy;
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
