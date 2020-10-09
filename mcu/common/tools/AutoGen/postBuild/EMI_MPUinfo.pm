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
#*   EMI_MPIinfo.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is used to get linker symbol for setting EMI RMPU
#* 
#*
#* Author:
#* -------
#*   KC Tsai (mtk06471)
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

BEGIN { push @INC, './common/tools/MemoryUtility/' }  # add additional library path
use LinkerOutputParser;
use CommonUtility;
use FileInfoParser;

package EMI_MPUinfo;

use constant ATTR__NO_PROTECTION  => 0x0;
use constant ATTR_________SEC_RW  => 0x1;
use constant ATTR__SEC_RW_NSEC_R  => 0x2;
use constant ATTR__SEC_RW_NSEC_W  => 0x3;
use constant ATTR___SEC_R_NSEC_R  => 0x4;
use constant ATTR______FORBIDDEN  => 0x5;
use constant ATTR__SEC_R_NSEC_RW  => 0x6;
use constant ATTR________UNUNSED  => 0xF;



############# user configuration##############

my $nKBalign = 64; # 64KB alignment
my @aEMI_MPU_config = ( 
    # (1) Image:execution view, (2) section name, (3) base or zi limit,  (1) + (2) + (3) = end address of this region (base address = pre section end address)
    #                                                                      (4) HW domain 1(pcore/l1core), (5) unused domain,  (6) HW domain 7, (7) unused domain
    [LinkerSymPrefix::Image,  "L1CORE_DSP",                LinkerSymPostfix::Limit, ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED],     # 0, L1core RW ZI base = Image$$L1CORE_DSP$$:imit
    [LinkerSymPrefix::Image,  "SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURO_HWRW", LinkerSymPostfix::Base, 
	                                                                                ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED],     # 1, MD HW base = Image$$SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURO_HWRW$$Base
    [LinkerSymPrefix::Image,  "SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURW_HWRW", LinkerSymPostfix::Base, 
	                                                                                ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED],     # 2, MD HW base = Image$$SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_MCURW_HWRW$$Base
    [LinkerSymPrefix::Image,  "CACHED_EXTSRAM",            LinkerSymPostfix::Base,  ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED],     # 3, Pcore RAM  base   = Image$$CACHED_EXTSRAM$$Base
    [LinkerSymPrefix::Image,  "DUMMY_END",                 LinkerSymPostfix::Base,  ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED],     # 4, Pcore RAM  end    = Image$$DUMMY_END$$Base
    [0,                       "",                          0,                       ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED],     # 5
    [0,                       "",                          0,                       ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED],     # 6
    [0,                       "",                          0,                       ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED, ATTR________UNUNSED],     # 7
);

#######################################

my $version = "u0.06";
                         # u0.06,  2015/09/17,  Carl, move dsp bin from l1core rom to l1core ram, change the 1st EMI RMPU channel base to Image$$L1CORE_DSP$$:imit
                         # u0.05,  2015/07/06,  Carl, return directly when processing TCM only load
                         # u0.04,  2015/04/15,  Carl, refine setting for (MCU RO, MDHW RW)  DNC+NC, (MCU RW, MDHW RW)  DNC+NC
                         # u0.03,  2015/04/02,  Carl, refine setting 
                         # u0.02,  2015/03/30,  Carl, refine setting 
                         # u0.01,  2015/01/31,  Carl, return EMI RMPU settion
           
sub retrieveEMI_MPU_info()
{
    my ($strFilePath, $themf) = @_;
    my $nAvailableChannel=0;
    my @aEMI_MPU;
    my @aEMI_Domain;


    &FileInfo::Parse_MAKEFILE($themf, \%g_MAKEFILE_OPTIONS);

    if( &FileInfo::find("TCM_ONLY_LOAD", "TRUE") )
    {
        return (0, undef, undef);
    }


    LinkerOutputParser::FileParse($strFilePath);

    
# offset(base), size
    my $base=0;
    for( my $i=0; $i<scalar(@aEMI_MPU_config); ++$i)
    {
        my $channel_ref = @aEMI_MPU_config[$i];
        if( @{$channel_ref}[1] ne ""  )
        {
            my $end_addr = &getAddr( @{$channel_ref}[0], @{$channel_ref}[1], @{$channel_ref}[2] );
            push @aEMI_MPU, [$base, $end_addr-$base];
            $base = $end_addr;
        }
        else
        {
            $nAvailableChannel = $i if ($nAvailableChannel==0);
            push @aEMI_MPU, [0,0];
            $base = 0;
        }
    }

# domain, 4 = nNumEmiMuDomain
    for( my $i=0; $i<4; ++$i) 
    {
        my $nChannelAttr = 0;    	
        for( my $j=0; $j<scalar(@aEMI_MPU_config); ++$j)
        {
            my $channel_ref = @aEMI_MPU_config[$j];
            $nChannelAttr |= @{$channel_ref}[3+$i] << ($j*4);
        }
        push @aEMI_Domain, $nChannelAttr;
    }
    return ($nAvailableChannel, \@aEMI_MPU, \@aEMI_Domain);
}

sub getAddr()
{
    my ($nPrefix, $strName, $nPostfix) = @_;

    my $strSymbol = "0x0FFFFFFF & ";
    
    $strSymbol.= "Image\$\$" if( $nPrefix == LinkerSymPrefix::Image );
    $strSymbol.= "Load\$\$" if( $nPrefix == LinkerSymPrefix::Load );
    $strSymbol.= $strName;
    $strSymbol.= "\$\$Base" if( $nPostfix == LinkerSymPostfix::Base );
    $strSymbol.= "\$\$Limit" if( $nPostfix == LinkerSymPostfix::Limit );
    $strSymbol.= "\$\$ZIBase" if( $nPostfix == LinkerSymPostfix::ZIBase );
    $strSymbol.= "\$\$ZILimit" if( $nPostfix == LinkerSymPostfix::ZILimit );

    my $strAddr = &LinkerOutputParser::GetLinkerSymbolAddress( $strName, $nPostfix, $nPrefix );
    &EMP_MPUinfo_die("no linker symbol $strSymbol") if (defined $strAddr == undef);
    
    my $nAddr = 0x0FFFFFFF & hex($strAddr);
    $strAddr = CommonUtil::Dec2Hex($nAddr);
    &EMP_MPUinfo_die("symbol $strSymbol is not 64KB alignment") if ($nAddr != &CommonUtil::GetKBAligned($nAddr, $nKBalign));

    $strSymbol.= " = $strAddr = $nAddr\n";
    print $strSymbol;

    return $nAddr;    
}

sub EMP_MPUinfo_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'EMP_MPUinfo');    
}


