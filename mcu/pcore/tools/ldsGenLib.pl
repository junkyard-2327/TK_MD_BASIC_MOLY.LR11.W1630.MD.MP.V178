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
#*   ldsGenLib.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to generate memory layout
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
BEGIN { push @INC, "pcore/" , './pcore/tools/' }  # add additional library path
use sysGenUtility;
use ldsFrame;
use FileInfoParser;
use config_MemSegment;
use tools::pack_dep_gen;
use POSIX qw(floor ceil);
PrintDependModule();

#****************************************************************************
# 0 >>> exit;
#****************************************************************************
return 1;
#****************************************************************************
# Constant
#****************************************************************************


#****************************************************************************
# ldsGen Version
#****************************************************************************
sub ldsGen_verno
{
    return " LR11_v0.05 + ldsFrame.pm ".&ldsFrame::ldsFrame_verno;
           # LR11_v0.05,   2017/May/17, Carl,   New Layout
           # LR11_v0.04,   2015/11/17,  Tero,   Added L1CORE_SWLA_SIZE calculation
           # LR11_v0.03,   2015/11/09,  Tero,   Support ldsGen for MT6750 and MT6757
           # LR11_v0.02,   2015/09/17,  Carl,   Move dsp bin from l1core rom to l1core ram, change the 1st EMI RMPU channel base to Image$$L1CORE_DSP$$:imit
           # LR11_v0.01,   2015/08/31,  Carl,   Reduce total memory size of MT6755 and MT6797 from 160MB to 128MB
           # u0.33_UMOLY,  2015/07/20,  Carl,   Support ldsGen for MT6797
           # u0.32_UMOLY,  2015/07/03,  Carl,   Change MT6755 MD only load size
           # u0.31_UMOLY,  2015/06/23,  Carl,   Refine the way to use GetSharedMemorySize. It includes dsp tx/rx section now
           # u0.30_UMOLY,  2015/06/05,  Carl,   Add MD size setting with ramdisk 
           # u0.29_UMOLY,  2015/06/04,  Carl,   Support ldsGen for MT6755
           # u0.28_UMOLY,  2015/05/11,  Carl,   Support Ramdisk for TK6291
           # u0.27_UMOLY,  2015/04/09,  Carl,   Align the shared DNC base to 64KB for input section MCU-RO, HW-RW (EMI RMPU)
           # u0.26_UMOLY,  2015/01/26,  Carl,   Refine GetMPUAligned for adding debug log
           # u0.25_UMOLY,  2015/01/06,  Carl,   lds refinement: 1) auto adjust shared region size, 2) reserve pcore, l1core SWLA space
           # u0.24_UMOLY,  2014/12/22,  Carl,   Support L2SRAM section (in L1CORE)
           # u0.23_UMOLY,  2014/11/25,  Carl,   Merge ATCM and BTCM as a single TCM
           # u0.22_UMOLY,  2014/10/05,  Carl,   Align start address of shared memory section to 1MB
           # u0.21_UMOLY,  2014/09/26,  Carl,   support GFH + SIG, move sig size to sysGenUtility.pm
           # u0.21_UMOLY,  2014/09/26,  Carl,   support GFH + SIG
           # u0.20_UMOLY,  2014/09/22,  Carl,   rename MT6291 to TK6291
           # u0.19_UMOLY,  2014/09/11,  mei,    support l1core memory dump
           # u0.18_UMOLY,  2014/09/05,  Carl,   reduce default shared memory size for PCORE ONLY project
           # u0.17_UMOLY,  2014/08/20,  Carl,   refine l1core dump region
           # u0.16_UMOLY,  2014/08/19,  Carl,   update L1core reset vector load view
           # u0.15_UMOLY,  2014/07/31,  Carl,   dump l1core region
           # u0.14_UMOLY,  2014/06/27,  Carl,   provide linker symbol rather than hardcode
           # ...
           # u0.01_UMOLY,  2014/02/20,  BM,     porting to MT6291_DEV

}

#****************************************************************************
# Constants
#****************************************************************************


#****************************************************************************
# Global Variables
#****************************************************************************
my $g_bb = undef;
my $g_nRamSize = undef;
my $g_bNeedBL = undef;
my $g_BBFolder = undef;
my $g_MakeFilePath = undef;
my $g_MakeFile_ref = undef;
my $g_nRAM_BASE = 0;

my $g_l1core_offset = 0;
#****************************************************************************
# Input Parameters
#****************************************************************************

#****************************************************************************
# subroutines
#****************************************************************************

#****************************************************************************
# Unsupport: $flash_href, $flash_blk_href
#            $nor_device, $fota_cfg,
#            $mem_dev_h_cfg
#            $IsFlashtoolLayoutInput, $use_dummy_scatter, $feature_config, $nFactoryBinSize
#****************************************************************************
sub ldsGen_main
{
    ($g_bb, $g_nRamSize, $g_bNeedBL, $g_BBFolder, $g_MakeFilePath) = @_;
    $g_bb = &sysUtil::SwitchToClonedChip($g_bb);
    $g_MakeFile_ref = &FileInfo::GetMakeFileRef($g_MakeFilePath);
    my $strLayout = &GenLDSProcess();
    return $strLayout;
}
sub GenLDSProcess
{
    &ldsFrame::CleanCallBackFunc();
    &ldsFrame::SetCallBackFunc("GetChip", \&GetChip);
    &ldsFrame::SetCallBackFunc("CollectMemorySetting", \&CollectMemorySetting);
    &ldsFrame::SetCallBackFunc("SetMemorySegment", \&SetMemorySegment) if(&FileInfo::is_NOR());
    &ldsFrame::SetCallBackFunc("SetRegionList", \&SetRegionList);
    &ldsFrame::SetCallBackFunc("GetCustomFolder", \&GetCustomFolder);
    
    return &ldsFrame::GenLDS(ldsFrame::MAIN);
}
sub GetChip  #CallBack func
{
    return $g_bb;
}
sub GetCustomFolder #CallBack func
{
    return $g_BBFolder;   
}

sub CollectMemorySetting  #CallBack func
{
    my ($MEMORYPath, $RegionList_ref, $Index_ref) = @_;
    my $bb = $g_bb;
    $bb =~ s/\_(\S+)//;
    my $func = "$bb\_MemorySetting";
    #&sysUtil::sysgen_die("Unsupported Memory Setting on $g_bb! $func must exist.", __FILE__, __LINE__) if not defined &{$func}; 
    no strict 'refs';
    my %Setting;
    RefineMEMORYWithInput($MEMORYPath, \%Setting);
    if (defined &{$func}) {
        &{$func}(\%Setting);
    }else {
        Default_MemorySetting(\%Setting);
    }
#    my $nReservedSize = &GetReservedSize_FromBottomToTop_OnRAM(undef, $RegionList_ref, $Index_ref,  "DSP_RX", "DUMMY_END");
#    $Setting{"RESERVED_FOR_DUMMY_END"} = &CommonUtil::Dec2Hex($nReservedSize);
    $Setting{"CACHEABLE_PREFIX"} = &CommonUtil::Dec2Hex(sysUtil::GetCacheablePrefix($g_bb));
    $Setting{"NONCACHEABLE_PREFIX"} = &CommonUtil::Dec2Hex(sysUtil::GetNonCacheablePrefix($g_bb));
    
    return \%Setting;
}

sub SetMemorySegment   #CallBack func
{   
    my ($MEMORY_SEGMENT_aref) = @_;
    #nor
}

sub RefineMEMORYWithInput
{
    my ($MEMORYPath, $Setting_href) = @_;
    my $Memory_aref = &ldsInfo::ParseMEMORY(&CommonUtil::GetFileContent($MEMORYPath));
    foreach my $info (@$Memory_aref)
    {
        if($info->[0] eq "ROM")
        {
            my $strBase = GetUsefulInfo($info->[1]);
            my $strLen = GetUsefulInfo($info->[2]);
            $Setting_href->{ROM_BASE} = $strBase if(defined $strBase);
            $Setting_href->{ROM_LEN}  = $strLen  if(defined $strLen);
        }
        elsif($info->[0] eq "RAM")
        {
            my $strBase = GetUsefulInfo($info->[1]);
            my $strLen = GetUsefulInfo($info->[2]);
            $Setting_href->{RAM_BASE} = $strBase if(defined $strBase);
            $Setting_href->{RAM_LEN}  = $strLen  if(defined $strLen);
        }
        elsif($info->[0] eq "VRAM")
        {
            my $strBase = GetUsefulInfo($info->[1]);
            my $strLen = GetUsefulInfo($info->[2]);
            $Setting_href->{VRAM_BASE} = $strBase if(defined $strBase);
            $Setting_href->{VRAM_LEN}  = $strLen  if(defined $strLen);
        }
    }
}
sub GetUsefulInfo
{
    my ($strInput) = @_;
    $strInput =~ s/\[(.+)\]|\s//g;
    $strInput = undef if($strInput !~ /^0x(\w+)$|(\w+)$/);
    return $strInput;
}

sub SetRegionList  #CallBack func
{
    my ($BasicRegionList_ref, $Index_ref, $MEMORYSetting_href) = @_;
    my @RegionList;
    foreach my $item (@$BasicRegionList_ref)
    {
        my $strCondition = $item->[$Index_ref->{Condition}];
        next if($strCondition ne "" and 0 == &FileInfo::EvaluateFeatureOptionCondition($strCondition, $g_MakeFile_ref));
        my $strCompileOption = $item->[$Index_ref->{CompileOption}];
        next if($strCompileOption ne "" and (0 == BuildInfo::EvaluateCompileOption($strCompileOption)));
        push @RegionList, $item;
    }
    for(my $i=0; $i<= $#RegionList; $i++)
    {
        my $nColumnCount = scalar(@{$RegionList[$i]});
        for(my $j=0; $j <= $nColumnCount; $j++)
        {
            if($RegionList[$i]->[$j] =~/\[(\w+)\]/)
            {
                my $strToReplace = $1;
                no strict 'refs';
                my $func = "Gen".$1;
                my $template = &{$func}($MEMORYSetting_href, \@RegionList, $Index_ref) if (exists &{$func})
                  or &sysUtil::sysgen_die("$func() doesn't exists!", __FILE__, __LINE__);
                $RegionList[$i]->[$j] =~ s/\[$strToReplace\]/$template/g;
            }  
        }
    }
    return \@RegionList;
}

sub L1CORE_DUMP_REGION_preprocess()
{
	my $l1core_offset = FileInfo::get(FileInfo::L1CORE_REGION__OFFSET);
	my $l1core_non_cached_region_base = (0x0FFFFFFF & FileInfo::get(FileInfo::L1CORE_DUMP_REGION__C_BASE));

	if( 0 == $g_l1core_offset && 
		undef != $l1core_offset && 
		$l1core_offset < $l1core_non_cached_region_base )
	{
		$g_l1core_offset = $l1core_non_cached_region_base - $l1core_offset;
		print "[ldsGen] l1core_offset = $l1core_offset \n";
		print "[ldsGen] l1core_non_cached_region_base = $l1core_non_cached_region_base \n";
		print "[ldsGen] update g_l1core_offset = $g_l1core_offset \n";
	}
}

sub GenL1CORE_DUMP_REGION__C_BASE # Fill in RegionList.csv
{
	&L1CORE_DUMP_REGION_preprocess();
	my $nL1CORE_DUMP_REGION__C_BASE = &FileInfo::get(FileInfo::L1CORE_DUMP_REGION__C_BASE) - $g_l1core_offset;
	my $hexL1CORE_DUMP_REGION__C_BASE = &CommonUtil::Dec2Hex($nL1CORE_DUMP_REGION__C_BASE);

	print "[ldsGen] nL1CORE_DUMP_REGION__C_BASE \t $nL1CORE_DUMP_REGION__C_BASE ($hexL1CORE_DUMP_REGION__C_BASE)\n";
	
    return $hexL1CORE_DUMP_REGION__C_BASE;
}

sub GenL1CORE_DUMP_REGION__C_SIZE # Fill in RegionList.csv
{
	my $nL1CORE_DUMP_REGION__C_SIZE = &FileInfo::get(FileInfo::L1CORE_DUMP_REGION__C_SIZE);
	my $hexL1CORE_DUMP_REGION__C_SIZE = &CommonUtil::Dec2Hex($nL1CORE_DUMP_REGION__C_SIZE);

	print "[ldsGen] nL1CORE_DUMP_REGION__C_SIZE \t $nL1CORE_DUMP_REGION__C_SIZE ($hexL1CORE_DUMP_REGION__C_SIZE)\n";
	
    return $hexL1CORE_DUMP_REGION__C_SIZE;
}

sub GenL1CORE_DUMP_REGION__C_ZILIMIT # Fill in RegionList.csv
{
    &CommonUtil::Dec2Hex( hex(&GenL1CORE_DUMP_REGION__C_BASE()) + hex(&GenL1CORE_DUMP_REGION__C_SIZE()) );
}


sub GenL1CORE_DUMP_REGION__DC_BASE # Fill in RegionList.csv
{
	&L1CORE_DUMP_REGION_preprocess();
	my $nL1CORE_DUMP_REGION__DC_BASE = &FileInfo::get(FileInfo::L1CORE_DUMP_REGION__DC_BASE) - $g_l1core_offset;
	my $hexL1CORE_DUMP_REGION__DC_BASE = &CommonUtil::Dec2Hex($nL1CORE_DUMP_REGION__DC_BASE);

	print "[ldsGen] nL1CORE_DUMP_REGION__DC_BASE \t $nL1CORE_DUMP_REGION__DC_BASE ($hexL1CORE_DUMP_REGION__DC_BASE)\n";
	
    return $hexL1CORE_DUMP_REGION__DC_BASE;
}

sub GenL1CORE_DUMP_REGION__DC_SIZE # Fill in RegionList.csv
{
	my $nL1CORE_DUMP_REGION__DC_SIZE = &FileInfo::get(FileInfo::L1CORE_DUMP_REGION__DC_SIZE);
	my $hexL1CORE_DUMP_REGION__DC_SIZE = &CommonUtil::Dec2Hex($nL1CORE_DUMP_REGION__DC_SIZE);

	print "[ldsGen] nL1CORE_DUMP_REGION__DC_SIZE \t $nL1CORE_DUMP_REGION__DC_SIZE ($hexL1CORE_DUMP_REGION__DC_SIZE)\n";
	
    return $hexL1CORE_DUMP_REGION__DC_SIZE;
}

sub GenL1CORE_DUMP_REGION__DC_ZILIMIT # Fill in RegionList.csv
{
    &CommonUtil::Dec2Hex( hex(&GenL1CORE_DUMP_REGION__DC_BASE()) + hex(&GenL1CORE_DUMP_REGION__DC_SIZE()) );
}


sub GenL1CORE_DUMP_REGION__NC_BASE # Fill in RegionList.csv
{
	&L1CORE_DUMP_REGION_preprocess();
	my $nL1CORE_DUMP_REGION__NC_BASE = &FileInfo::get(FileInfo::L1CORE_DUMP_REGION__NC_BASE) - $g_l1core_offset;
	my $hexL1CORE_DUMP_REGION__NC_BASE = &CommonUtil::Dec2Hex($nL1CORE_DUMP_REGION__NC_BASE);

	print "[ldsGen] nL1CORE_DUMP_REGION__NC_BASE \t $nL1CORE_DUMP_REGION__NC_BASE ($hexL1CORE_DUMP_REGION__NC_BASE)\n";
	
    return $hexL1CORE_DUMP_REGION__NC_BASE;
}

sub GenL1CORE_DUMP_REGION__NC_SIZE # Fill in RegionList.csv
{
	my $nL1CORE_DUMP_REGION__NC_SIZE = &FileInfo::get(FileInfo::L1CORE_DUMP_REGION__NC_SIZE);
	my $hexL1CORE_DUMP_REGION__NC_SIZE = &CommonUtil::Dec2Hex($nL1CORE_DUMP_REGION__NC_SIZE);

	print "[ldsGen] nL1CORE_DUMP_REGION__NC_SIZE \t $nL1CORE_DUMP_REGION__NC_SIZE ($hexL1CORE_DUMP_REGION__NC_SIZE)\n";
	
    return $hexL1CORE_DUMP_REGION__NC_SIZE;
}

sub GenL1CORE_DUMP_REGION__NC_ZILIMIT # Fill in RegionList.csv
{
    &CommonUtil::Dec2Hex( hex(&GenL1CORE_DUMP_REGION__NC_BASE()) + hex(&GenL1CORE_DUMP_REGION__NC_SIZE()) );
}


sub GenL1CORE_DUMP_REGION__DNC_BASE # Fill in RegionList.csv
{
	&L1CORE_DUMP_REGION_preprocess();
	my $nL1CORE_DUMP_REGION__DNC_BASE = &FileInfo::get(FileInfo::L1CORE_DUMP_REGION__DNC_BASE) - $g_l1core_offset;
	my $hexL1CORE_DUMP_REGION__DNC_BASE = &CommonUtil::Dec2Hex($nL1CORE_DUMP_REGION__DNC_BASE);

	print "[ldsGen] nL1CORE_DUMP_REGION__DNC_BASE \t $nL1CORE_DUMP_REGION__DNC_BASE ($hexL1CORE_DUMP_REGION__DNC_BASE)\n";
	
    return $hexL1CORE_DUMP_REGION__DNC_BASE;
}

sub GenL1CORE_DUMP_REGION__DNC_SIZE # Fill in RegionList.csv
{
	my $nL1CORE_DUMP_REGION__DNC_SIZE = &FileInfo::get(FileInfo::L1CORE_DUMP_REGION__DNC_SIZE);
	my $hexL1CORE_DUMP_REGION__DNC_SIZE = &CommonUtil::Dec2Hex($nL1CORE_DUMP_REGION__DNC_SIZE);

	print "[ldsGen] nL1CORE_DUMP_REGION__DNC_SIZE \t $nL1CORE_DUMP_REGION__DNC_SIZE ($hexL1CORE_DUMP_REGION__DNC_SIZE)\n";
	
    return $hexL1CORE_DUMP_REGION__DNC_SIZE;
}

sub GenL1CORE_DUMP_REGION__DNC_ZILIMIT # Fill in RegionList.csv
{
    &CommonUtil::Dec2Hex( hex(&GenL1CORE_DUMP_REGION__DNC_BASE()) + hex(&GenL1CORE_DUMP_REGION__DNC_SIZE()) );
}


sub GenL1CORE_DUMP_REGION__L2SRAM_DATA_BASE # Fill in RegionList.csv
{
	my $nL1CORE_DUMP_REGION__L2SRAM_DATA_BASE = &FileInfo::get(FileInfo::L1CORE_DUMP_REGION__L2SRAM_DATA_BASE);
	my $hexL1CORE_DUMP_REGION__L2SRAM_DATA_BASE = &CommonUtil::Dec2Hex($nL1CORE_DUMP_REGION__L2SRAM_DATA_BASE);

	print "[ldsGen] nL1CORE_DUMP_REGION__L2SRAM_DATA_BASE \t &nL1CORE_DUMP_REGION__L2SRAM_DATA_BASE ($hexL1CORE_DUMP_REGION__L2SRAM_DATA_BASE)\n";
	
    return $hexL1CORE_DUMP_REGION__L2SRAM_DATA_BASE;
}

sub GenL1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT # Fill in RegionList.csv
{
	my $nL1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT = &FileInfo::get(FileInfo::L1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT);
	my $hexL1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT = &CommonUtil::Dec2Hex($nL1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT);

	print "[ldsGen] nL1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT \t &nL1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT ($hexL1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT)\n";
	
    return $hexL1CORE_DUMP_REGION__L2SRAM_DATA_ZI_ZILIMIT;
}


sub GenITCM_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;

    # old way
    #my $Keyword = "ITCM";
    #$Keyword = "TCM" if((&sysUtil::is_CR4($g_bb) and !&sysUtil::is_LTE($g_bb)) 
    #                 or (&sysUtil::is_arm7($g_bb) and &sysUtil::is_LTE($g_bb)) );

    # new way
    # please sync this method with SetTCMSize() @ ldsInfoWrap.pm
    # please sync this method with GetDumpExeRegions() @ scatInfo.pm
    # please sync this method with GetL1COREDumpExeRegions() @ scatInfo.pm
    my $Keyword = (defined $MEMORYSetting_href->{"ITCM"}?"ITCM":"TCM");
    #print "Keyword=$Keyword\n";
    
    return $MEMORYSetting_href->{$Keyword}->[0];
}

sub GenDTCM_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my $Keyword = "DTCM";
    return $MEMORYSetting_href->{$Keyword}->[0];
}

sub GenDTCM_SIZE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my $Keyword = "DTCM";
    return &CommonUtil::Dec2Hex( hex($MEMORYSetting_href->{$Keyword}->[1]) );
}

sub GenBTCM1_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my $Keyword = "BTCM1";
    return $MEMORYSetting_href->{$Keyword}->[0];
}

sub GenBTCM_SIZE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my $B1 = "BTCM1";
    my $B0 = "DTCM";
    return &CommonUtil::Dec2Hex( hex($MEMORYSetting_href->{$B0}->[1]) + 
                                 hex($MEMORYSetting_href->{$B1}->[1]));
}

sub GenSIG_SIZE_X
{
	return &sysUtil::GetSigSize();
}

sub GenSIG_BASE_X # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my $L1CORE_RWZI = "L1CORE_RWZI";
    return &CommonUtil::Dec2Hex( hex($MEMORYSetting_href->{$L1CORE_RWZI}->[0]) 
                               + hex($MEMORYSetting_href->{$L1CORE_RWZI}->[1])
                               - &GenSIG_SIZE() );
}


# Return 2nd linking ROM end_address
# Since the size of ROM in 2nd linking is bigger than 1st linking due to veneer
sub GenROM_LIMIT
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;

    my $hexL1CORE_vector_addr = GenL1CORE_BOOT_VECTOR_BASE($MEMORYSetting_href, $RegionList_aref, $Index_ref);

    if (0==hex($hexL1CORE_vector_addr))
    {
        return "__exidx_end";
    }
    else
    {
        my $nL1CORE_base_addr = FileInfo::get(FileInfo::PCORE_LV1_SIZE);
        return &CommonUtil::Dec2Hex($nL1CORE_base_addr);
    }
}

# Return 1st linking ROM_P end_address
# Since the size of ROM_P in 2nd linking is bigger than 1st linking due to veneer
sub GenROM_P_LIMIT
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;

    # default size defined in copro_info_gen.pl
    my $nROM1_Size       = FileInfo::get(FileInfo::PCORE_LV1_SIZE);
    my $nL1CORE_LVSize  = FileInfo::get(FileInfo::L1CORE_LV_SIZE);
    my $nROM2_Size       = FileInfo::get(FileInfo::PCORE_LV2_SIZE);

    return &CommonUtil::Dec2Hex($nROM1_Size + $nL1CORE_LVSize + $nROM2_Size);
}

sub GenL1CORE_BOOT_VECTOR_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
	my $L1CORE_LV = "L1CORE_LV";
	
    my $nL1CORE_vector_addr = FileInfo::get(FileInfo::L1CORE_VECTOR);
    my $hextrL1CORE_vector_addr = &CommonUtil::Dec2Hex( $nL1CORE_vector_addr);

	&L1CORE_DUMP_REGION_preprocess();
	
	print "[ldsGen] L1CORE_vector_addr \t $nL1CORE_vector_addr ($hextrL1CORE_vector_addr)\n";
    
#    return &CommonUtil::Dec2Hex( $L1CORE_vector_addr - $g_l1core_offset);
    return $hextrL1CORE_vector_addr;
}

#sub GenL1CORE_BOOT_VECTOR_SIZE # Fill in RegionList.csv
sub wait_for_reuse
{
    return &CommonUtil::Dec2Hex(0x40);
}


#sub GetReservedSize_FromBottomToTop_OnRAM
sub wait_for_reuse
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref, $strBottom, $strTop) = @_;
    my @TopDownRegions;
    my $NameIndex = $Index_ref->{Name};
    my $MaxSizeIndex = $Index_ref->{MaxSize};
    my $bStart = 0;
    
    foreach my $region (@$RegionList_aref)
    {
        if($region->[$NameIndex] =~/$strTop/i)
        {
            $bStart=1;
        }
        elsif($region->[$NameIndex] =~/$strBottom/i)
        {
            push(@TopDownRegions, $region);
            $bStart=0;
        }
        if($bStart ==1)
        {
            push(@TopDownRegions, $region);
        }
    }
    my $nReservedSize;
    foreach my $item (@TopDownRegions)
    {
        my $strSize = $item->[$MaxSizeIndex];
        if($item->[$MaxSizeIndex] =~/\[(\S+)\]/)
        {
            no strict 'refs';
            my $func = "Gen".$1;
            $strSize = &{$func}($MEMORYSetting_href, $RegionList_aref, $Index_ref) if (exists &{$func})
              or &sysUtil::sysgen_die("$func() doesn't exists!", __FILE__, __LINE__);
            
        }
        $nReservedSize += hex($strSize);
    }
    return $nReservedSize;
}
#sub GetAddress_FromBottomToTop_OnRAM
sub wait_for_reuse
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref, $strBottom, $strTop) = @_;
    my $nReservedSize = &GetReservedSize_FromBottomToTop_OnRAM($MEMORYSetting_href, $RegionList_aref, $Index_ref, $strBottom, $strTop);
    my $nRamSize = hex($MEMORYSetting_href->{RAM}->[0]) + hex($MEMORYSetting_href->{RAM}->[1]);
    my $nBase = $nRamSize - $nReservedSize;
    my $strTopRegionName;
    my $NameIndex = $Index_ref->{Name};
    foreach my $item (@$RegionList_aref)
    {
        if($item->[$NameIndex] =~ /$strTop/i)
        {
            $strTopRegionName = $item->[$NameIndex];
            last;
        }
    }
        $nBase = $strTopRegionName =~ /cached/i ? (sysUtil::GetCacheablePrefix($g_bb) | $nBase) : $nBase;
    return &CommonUtil::Dec2Hex($nBase);
}


sub GenSHARED_DNC_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    
    my $nSharedDNCbase = hex(GenRX_BASE($MEMORYSetting_href, $RegionList_aref, $Index_ref))
                       + hex(GenRX_SIZE($MEMORYSetting_href, $RegionList_aref, $Index_ref))
                       - &FileInfo::GetSharedMemorySize($g_bb, $g_MakeFile_ref->{mode});

    # my $shared_region_base_alignd_size = 32;
    # add some "buffer" for section base (or size) alignment. Please sync this way as GetSharedMemoryInfo() in L1coreLdsGen.pl
    # $nSharedDNCbase = ( $nSharedDNCbase - $shared_region_base_alignd_size ) & (~($shared_region_base_alignd_size-1));

    &sysUtil::sysgen_die("base address of shared memory region ($nSharedDNCbase) are not 64KB align", __FILE__, __LINE__)
        if($nSharedDNCbase != &CommonUtil::GetKBAligned($nSharedDNCbase, 64));
        
    return &CommonUtil::Dec2Hex($nSharedDNCbase);
}


sub GenL1CORE_DSP_TX_LENGTH # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(FileInfo::get(FileInfo::L1CORE_DSP_TX_LENGTH));
}

sub GenL1CORE_DSP_RX_LENGTH # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(FileInfo::get(FileInfo::L1CORE_DSP_RX_LENGTH));
}

sub GenTX_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    
    return &CommonUtil::Dec2Hex(hex(GenRX_BASE($MEMORYSetting_href, $RegionList_aref, $Index_ref)) - 
                                hex(GenTX_SIZE($MEMORYSetting_href, $RegionList_aref, $Index_ref)));
}

sub GenL1CORE_SWLA_SIZE
{
  return  &CommonUtil::Dec2Hex(FileInfo::get(FileInfo::L1CORE_SWLA_SIZE));
}
##################################
# RX  is base line for above/below output sections
##################################
sub GenRX_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;

    my $nSharedRegionSize = &FileInfo::GetSharedMemorySize();

    my $nSharedRegionEnd = &CommonUtil::GetMPUAligned($g_nRAM_BASE + $nSharedRegionSize, "SharedRegionEnd");

    return &CommonUtil::Dec2Hex($nSharedRegionEnd - hex(GenRX_SIZE($MEMORYSetting_href, $RegionList_aref, $Index_ref)));
}
sub GenTX_SIZE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my ($nTXLength,$nRXLength) = &sysUtil::DSPTXRX_query_length($g_bb, $g_MakeFile_ref->{mode});
    return &CommonUtil::Dec2Hex($nTXLength);
}
sub GenRX_SIZE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my ($nTXLength,$nRXLength) = &sysUtil::DSPTXRX_query_length($g_bb, $g_MakeFile_ref->{mode});
    return &CommonUtil::Dec2Hex($nRXLength);
}

sub GenCACHED_EXTSRAM_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    return &CommonUtil::Dec2Hex(sysUtil::GetCacheablePrefix($g_bb) | 
                                ( hex(GenRX_BASE($MEMORYSetting_href, $RegionList_aref, $Index_ref)) + 
                                  hex(GenRX_SIZE($MEMORYSetting_href, $RegionList_aref, $Index_ref))));
}

sub GenEXTSRAM_FS_ZI_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;    
    return &CommonUtil::Dec2Hex( &GetMDTotolSize($g_bb) );
}


sub GenL1CORE_DSP_LIMIT
{
	&L1CORE_DUMP_REGION_preprocess();

	my $nL1CORE_DSP_LIMIT = &FileInfo::get(FileInfo::L1CORE_DSP_LIMIT) - $g_l1core_offset;
	my $hexL1CORE_DSP_LIMIT = &CommonUtil::Dec2Hex($nL1CORE_DSP_LIMIT);
	
	print "[ldsGen] nL1CORE_DSP_LIMIT \t $nL1CORE_DSP_LIMIT ($hexL1CORE_DSP_LIMIT)\n";
    
    return $hexL1CORE_DSP_LIMIT;
}

###################################################################################################
# 
#  MemorySetting By chip
#
###################################################################################################
sub GetMDTotolSize
{   # remember to check shared memory size in GetDefaultSharedMemorySize ( sysGenUtility.pm)
    # please keep the same condition as GetMDTotolSizeLimitation @ sysGenUtility.pm
    my ($bb) = @_;

    # Note, this MD size setting is only for build pass
    # The reals size setting is in GetMDTotolSizeLimitation @ sysGenUtility.pm
    my %BBtbl_MD_size = 
    (
        'TK6291'  => 0x10000000,    # 256 MB
        'MT6755'  =>  0xA000000,    # 160 MB
        'MT6797'  =>  0xA000000,    # 160 MB
        'MT6750'  =>  0xA000000,    # 160 MB
        'MT6757'  =>  0xA000000,    # 160 MB
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

sub MT6755_MemorySetting  # Called by CollectMemorySetting($Setting_href),  fill in MEMORY
{
    my ($Setting_href) = @_;
    &Default_MemorySetting($Setting_href);
}

sub TK6291_MemorySetting  # Called by CollectMemorySetting($Setting_href),  fill in MEMORY
{
    my ($Setting_href) = @_;
    &Default_MemorySetting($Setting_href);
}

sub Default_MemorySetting  # Called by CollectMemorySetting($Setting_href),  fill in MEMORY
{
    my ($Setting_href) = @_;
    my $nTotalSize = GetMDTotolSize($g_bb);


    my $nROMBase = 0;
    SetExistentValueByDefault($Setting_href, "ROM_BASE", $nROMBase);


    # default size defined in copro_info_gen.pl
    my $nROM1_Size       = FileInfo::get(FileInfo::PCORE_LV1_SIZE);
    my $nL1CORE_LVSize  = FileInfo::get(FileInfo::L1CORE_LV_SIZE);
    my $nROM2_Size       = FileInfo::get(FileInfo::PCORE_LV2_SIZE);

    
    # <1> Total ROM, the values could be got by 2-phase linking
    my $nROMSize = $nROM1_Size + $nL1CORE_LVSize + $nROM2_Size;
    SetExistentValueByDefault($Setting_href, "ROM_LEN", $nROMSize);


    # <2> L1CORE_LV, the values could be got by 2-phase linking
    my $nL1CORE_LVBase = $nROM1_Size;
    # l1core TCM: 0x0 ~ 0x80000, so the smallest size shoould be 0x80000.  It should sync with AutoAdjust() in ModemReservedSize_AutoConfig.pl and AutoAdjust() in ModemReservedSize_AutoConfig.pl
    $nL1CORE_LVBase = 0x80000 if ($nL1CORE_LVBase < 0x80000);
    my $nL1CORE_LVEnd = $nL1CORE_LVBase + $nL1CORE_LVSize;
    SetExistentValueByDefault($Setting_href, "L1CORE_LV_BASE", $nL1CORE_LVBase);
    SetExistentValueByDefault($Setting_href, "L1CORE_LV_LEN", $nL1CORE_LVEnd - $nL1CORE_LVBase);


    # there is (1) PCORE ROM 2 and (2) a free space between L1CORE_LV and L1CORE_RQZI

    # <3> PCORE ROM2
    my $nROM2_Base = $nL1CORE_LVEnd;
    SetExistentValueByDefault($Setting_href, "ROM2_BASE", $nL1CORE_LVEnd);
    SetExistentValueByDefault($Setting_href, "ROM2_LEN",  $nROM2_Size);


    # <4> L1CORE_RWZI, the values could be got by 2-phase linking
    my $nL1CORE_RWZIBase = $nROM2_Base + $nROM2_Size;
    $nL1CORE_RWZIBase = &CommonUtil::GetMPUAligned($nL1CORE_RWZIBase, "L1CORE_RWZIBase");
    my $nL1CORE_RWZIEnd = $nL1CORE_RWZIBase + FileInfo::get(FileInfo::L1CORE_RWZI_SIZE);
    $nL1CORE_RWZIEnd = &CommonUtil::GetMPUAligned($nL1CORE_RWZIEnd, "L1CORE_RWZIEnd");
    SetExistentValueByDefault($Setting_href, "L1CORE_RWZI_BASE", $nL1CORE_RWZIBase);
    SetExistentValueByDefault($Setting_href, "L1CORE_RWZI_LEN", $nL1CORE_RWZIEnd - $nL1CORE_RWZIBase);


    # <5> RAM, the values could be got by 2-phase linking
    my $nRAM_BASE = GetPredefinedValue($Setting_href, "RAM_BASE", undef, $nL1CORE_RWZIEnd);
    my $nRAM_SIZE = $nROMBase + $nTotalSize - $nRAM_BASE; 
    SetExistentValueByDefault($Setting_href, "RAM_BASE", $nRAM_BASE);
    SetExistentValueByDefault($Setting_href, "RAM_LEN", $nRAM_SIZE);
    $g_nRAM_BASE = $nRAM_BASE ;


    # <10> L1CORE TCM, the values could be got by 2-phase linking
    my $nL1CORE_ITCM_LEN = GetPredefinedValue($Setting_href, "L1CORE_ITCM_LEN", undef, 0x40000);
    my $nL1CORE_DTCM_LEN = GetPredefinedValue($Setting_href, "L1CORE_DTCM_LEN", undef, 0x20000);
    my $nL1CORE_BTCM1_LEN = GetPredefinedValue($Setting_href, "L1CORE_BTCM1_LEN", undef, 0x20000);
    SetExistentValueByDefault($Setting_href, "L1CORE_ITCM_LEN", $nL1CORE_ITCM_LEN);
    SetExistentValueByDefault($Setting_href, "L1CORE_DTCM_LEN", $nL1CORE_DTCM_LEN);
    SetExistentValueByDefault($Setting_href, "L1CORE_BTCM1_LEN", $nL1CORE_BTCM1_LEN);
    
}

sub SetExistentValueByDefault
{
    my ($Setting_href, $strKey, $nValue) = @_;
    $Setting_href->{$strKey}  = (defined $Setting_href->{$strKey}) ? 
                                         $Setting_href->{$strKey} : CommonUtil::Dec2Hex($nValue);
}
sub GetPredefinedValue
{   # to collocate with AAPMC
    my ($Setting_href, $strFirst, $strSecond, $nDefaultValue) = @_;
    my $nValue = $nDefaultValue;
    if(defined $Setting_href->{$strFirst}) #1st Priority
    {
        $nValue = hex($Setting_href->{$strFirst});
    }
    elsif(defined $Setting_href->{$strSecond}) #2nd Priority
    {
        $nValue = hex($Setting_href->{$strSecond});
    }
    return $nValue;
    
}




##############################################
# work around for 90 build pass
##############################################

sub GenDUMMY_END # Fill in RegionList.csv
{
    return 0;
}



sub MT6290_MemorySetting  # Called by CollectMemorySetting($Setting_href)
{
    my ($Setting_href) = @_;
    my $nCOPRO_Reserved_Size = 0x0;
    $nCOPRO_Reserved_Size = 0x400000 if(FileInfo::is_BuiltWithCopro());
    my $nAPLimit_LVSize = 0xD00000;
    my $nDefault_ROMLen = 0x2000000;
    $nDefault_ROMLen = $nAPLimit_LVSize if(FileInfo::is_with_AP());
    my $nROM_LEN = GetPredefinedValue($Setting_href, "ROM_LEN", undef, $nDefault_ROMLen);
    my $nRamStart = GetPredefinedValue($Setting_href, "VRAM_BASE", undef, $nROM_LEN+$nCOPRO_Reserved_Size);
    my $nTotalMDSize = $g_nRamSize;
    if(&FileInfo::is_RNDISDongle())
    {  
        $nTotalMDSize = 0x4800000; #72MB
    }
    elsif(&FileInfo::is_HostedDongle())
    {
        $nTotalMDSize = 0x4800000; #72MB
    }
    my $nRamSize = $nTotalMDSize - $nRamStart;
    if($g_bb eq "MT6290_COPRO")
    {
        $nRamStart = GetPredefinedValue($Setting_href, "RAM_BASE", "ROM_LEN", 0x100000);
        $nRamSize = 0x400000;
    }
    SetExistentValueByDefault($Setting_href, "ROM_LEN", $nROM_LEN);
    SetExistentValueByDefault($Setting_href, "VRAM_BASE", (sysUtil::GetCacheablePrefix($g_bb) | $nRamStart));
    SetExistentValueByDefault($Setting_href, "RAM_LEN", $nRamSize);
    SetExistentValueByDefault($Setting_href, "COPRO_RESERVED_LEN", $nCOPRO_Reserved_Size);
    SetExistentValueByDefault($Setting_href, "COPRO_ALIGNMENT", sysUtil::GetCopro_KBAlignment("arm7")*1024);
    
    if(FileInfo::is_with_AP())
    {
        &sysUtil::sysgen_die("TotalMDLVSize($nROM_LEN) exceeds AP flash mpu setting($nAPLimit_LVSize\MB)!", __FILE__, __LINE__)
            if($nROM_LEN>$nAPLimit_LVSize);
    }
}





