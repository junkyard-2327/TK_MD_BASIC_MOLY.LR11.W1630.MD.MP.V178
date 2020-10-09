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
#*   L1coreLdsGen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to generate memory layout(tcl script)
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
BEGIN { push @INC, './l1core/tools/', './l1core/tools/' }  # add additional library path
use L1coreSysGenUtility;
use L1coreLdsFrame;
use L1coreFileInfoParser;
#use l1core::tools::pack_dep_gen;
#PrintDependModule();

use POSIX qw(floor ceil);

#****************************************************************************
# 0 >>> exit;
#****************************************************************************
return 1;
#****************************************************************************
# tclGen Version
#****************************************************************************
sub tclGen_verno
{
    return " u0.23_UMOLY + L1coreLdsFrame.pm ".&L1coreLdsFrame::ldsFrame_verno;
           # u0.23_UMOLY,  2017/May/24, Carl,   New Layout
           # u0.22_UMOLY,  2015/11/02,  Carl,   Change DSP TX/RX sections to ZI (.bss) section
           # u0.21_UMOLY,  2015/07/20,  Carl,   Support ldsGen for MT6797
           # u0.20_UMOLY,  2015/06/04,  Carl,   Support ldsGen for MT6755
           # u0.19_UMOLY,  2015/04/15,  Carl,   Refine setting for (MCU RO, MDHW RW)  DNC+NC, (MCU RW, MDHW RW)  DNC+NC
           # u0.18_UMOLY,  2015/04/09,  Carl,   Align the shared DNC base to 64KB for input section MCU-RO, HW-RW (EMI RMPU)
           # u0.17_UMOLY,  2015/01/26,  Carl,   Refine GetMPUAligned for adding debug log
           # u0.16_UMOLY,  2015/01/06,  lds refinement: 1) auto adjust shared region size, 2) reserve pcore, l1core SWLA space
           # u0.15_UMOLY,  2014/12/22,  Carl,   Support L2SRAM section (in L1CORE)
           # u0.14_UMOLY,  2014/11/25,  Carl,   Merge ATCM and BTCM as a single TCM
           # u0.13_UMOLY,  2014/09/22,  Carl,   Rename TK6291 to TK6291
           # u0.12_UMOLY,  2014/08/22,  Carl,   add linker symbol to init L1CORE TCM
           # u0.11_UMOLY,  2014/07/25,  Carl,   sync shared section length from pcore to l1core
           # u0.10_UMOLY,  2014/04/27,  Carl,   provide linker symbol rather than hardcode
           # ...
           # u0.01_UMOLY,  2014/02/20,  BM,     porting to TK6291_DEV
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
    $g_bb = &L1coreSysUtil::SwitchToClonedChip($g_bb);
    $g_MakeFile_ref = &L1coreFileInfo::GetMakeFileRef($g_MakeFilePath);
    my $strLayout = &GenLDSProcess();
    return $strLayout;
}
sub GenLDSProcess
{
    &L1coreLdsFrame::CleanCallBackFunc();
    &L1coreLdsFrame::SetCallBackFunc("GetChip", \&GetChip);
    &L1coreLdsFrame::SetCallBackFunc("CollectMemorySetting", \&CollectMemorySetting);
    &L1coreLdsFrame::SetCallBackFunc("SetMemorySegment", \&SetMemorySegment);
    &L1coreLdsFrame::SetCallBackFunc("SetRegionList", \&SetRegionList);
    &L1coreLdsFrame::SetCallBackFunc("GetCustomFolder", \&GetCustomFolder);
    
    return &L1coreLdsFrame::GenLDS(L1coreLdsFrame::MAIN);
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
    $bb =~ s/build\///;
    my $func = "$bb\_MemorySetting";
    #&L1coreSysUtil::sysgen_die("Unsupported Memory Setting on $g_bb! $func must exist.", __FILE__, __LINE__) if not defined &{$func}; 
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
    $Setting{"CACHEABLE_PREFIX"} = &CommonUtil::Dec2Hex(&L1coreSysUtil::GetCacheablePrefix($g_bb));
    $Setting{"NONCACHEABLE_PREFIX"} = &CommonUtil::Dec2Hex(&L1coreSysUtil::GetNonCacheablePrefix($g_bb));
    
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
        next if($strCondition ne "" and 0 == &L1coreFileInfo::EvaluateFeatureOptionCondition($strCondition, $g_MakeFile_ref));
        my $strCompileOption = $item->[$Index_ref->{CompileOption}];
        next if($strCompileOption ne "" and 0 == BuildInfo::EvaluateCompileOption($strCompileOption));
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
                  or &L1coreSysUtil::sysgen_die("$func() doesn't exists!", __FILE__, __LINE__);
                $RegionList[$i]->[$j] =~ s/\[$strToReplace\]/$template/g;
            }  
        }
    }
    return \@RegionList;
}

sub GenITCM_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;

    # old way
    #my $Keyword = "ITCM";
    #$Keyword = "TCM" if((&L1coreSysUtil::is_CR4($g_bb) and !&L1coreSysUtil::is_LTE($g_bb))  
    #                 or (&L1coreSysUtil::is_arm7($g_bb) and &L1coreSysUtil::is_LTE($g_bb)) );

    # new way
    # please sync this method with SetTCMSize() @ ldsInfoWrap.pm
    # please sync this method with GetDumpExeRegions() @ scatInfo.pm
    my $Keyword = (defined $MEMORYSetting_href->{"ITCM"}?"ITCM":"TCM");
    print "Keyword=$Keyword\n";
    
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

sub GenBOOT_VECTOR_SIZE # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(0x40);
}

sub wait_for_reuse
#sub GenDUMMY_END # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    return &GetAddress_FromBottomToTop_OnRAM($MEMORYSetting_href, $RegionList_aref, $Index_ref,
                                           "DSP_RX", "DUMMY_END");
}

sub GenL2SRAM_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    return $MEMORYSetting_href->{L2SRAM}->[0];
}

sub GenL2SRAM_SIZE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    return $MEMORYSetting_href->{L2SRAM}->[1];
}

sub wait_for_reuse
#sub GetReservedSize_FromBottomToTop_OnRAM
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
              or &L1coreSysUtil::sysgen_die("$func() doesn't exists!", __FILE__, __LINE__);
            
        }
        $nReservedSize += hex($strSize);
    }
    return $nReservedSize;
}
sub wait_for_reuse
#sub GetAddress_FromBottomToTop_OnRAM
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
        $nBase = $strTopRegionName =~ /cached/i ? (&L1coreSysUtil::GetCacheablePrefix($g_bb) | $nBase) : $nBase;
    return &CommonUtil::Dec2Hex($nBase);
}

sub GenSHARED_DNC_RW_BASE # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(L1coreFileInfo::get(L1coreFileInfo::PCORE_DYN_DNC_SHARED_BUFF_BASE));
}

sub GenSHARED_DNC_LENGTH # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(L1coreFileInfo::get(L1coreFileInfo::PCORE_DYN_DNC_SHARED_BUFF_LENGTH));
}

sub GenSHARED_NC_LENGTH # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(L1coreFileInfo::get(L1coreFileInfo::PCORE_NC_SHARED_BUFF_LENGTH));
}

sub GenSHARED_DNC_MCURO_HWRW_LENGTH # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(L1coreFileInfo::get(L1coreFileInfo::PCORE_DYN_DNC_MCURO_HWRW_SHARED_BUFF_LENGTH));
}

sub GenSHARED_NC_MCURO_HWRW_LENGTH # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(L1coreFileInfo::get(L1coreFileInfo::PCORE_NC_MCURO_HWRW_SHARED_BUFF_LENGTH));
}

sub GenSHARED_DNC_MCURW_HWRW_LENGTH # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(L1coreFileInfo::get(L1coreFileInfo::PCORE_DYN_DNC_MCURW_HWRW_SHARED_BUFF_LENGTH));
}

sub GenSHARED_NC_MCURW_HWRW_LENGTH # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(L1coreFileInfo::get(L1coreFileInfo::PCORE_NC_MCURW_HWRW_SHARED_BUFF_LENGTH));
}


sub GenPCORE_DSP_TX_LENGTH # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(L1coreFileInfo::get(L1coreFileInfo::PCORE_DSP_TX_LENGTH));
}

sub GenPCORE_DSP_RX_LENGTH # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(L1coreFileInfo::get(L1coreFileInfo::PCORE_DSP_RX_LENGTH));
}

sub GenTX_BASE # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex( L1coreFileInfo::get(L1coreFileInfo::DSP_TX_BASE) );
}

sub GenPCORE_LV2_SIZE # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex( L1coreFileInfo::get(L1coreFileInfo::PCORE_LV2_SIZE) );
}

##################################
# RX  is base line for above/below output sections
##################################
sub GenRX_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;

    my ($nTXLength,$nRXLength) = &L1coreSysUtil::DSPTXRX_query_length($g_bb, $g_MakeFile_ref->{mode});

    my ($nSHARED_REGIONBase, $nSHARED_REGIONEnd, $nSHARED_REGIONLength) = GetSharedMemoryInfo();
    
    return &CommonUtil::Dec2Hex( $nSHARED_REGIONEnd - $nRXLength );
}
sub GenTX_SIZE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my ($nTXLength,$nRXLength) = &L1coreSysUtil::DSPTXRX_query_length($g_bb, $g_MakeFile_ref->{mode});
    return &CommonUtil::Dec2Hex($nTXLength);
}
sub GenRX_SIZE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    my ($nTXLength,$nRXLength) = &L1coreSysUtil::DSPTXRX_query_length($g_bb, $g_MakeFile_ref->{mode});
    return &CommonUtil::Dec2Hex($nRXLength);
}

sub wait_for_reuse
#sub GenCOPRO_LV_SIZE
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
#    return CommonUtil::Dec2Hex(L1coreFileInfo::get(L1coreFileInfo::COPRO_LV_SIZE));
}

sub GetSharedMemoryInfo
{
    my ($nTXLength,$nRXLength) = &L1coreSysUtil::DSPTXRX_query_length(GetChip(), $g_MakeFile_ref->{mode});

    my $nSHARED_REGIONEnd = L1coreFileInfo::get(L1coreFileInfo::DSP_RX_BASE) + $nRXLength;
    my $nSHARED_REGIONBase = L1coreFileInfo::get(L1coreFileInfo::PCORE_DYN_DNC_SHARED_BUFF_BASE);
    my $nSHARED_REGIONLength = $nSHARED_REGIONEnd - $nSHARED_REGIONBase;

    #my $shared_region_base_alignd_size = 32; # shared region align 32 bytes    
    # add some "buffer" for section base (or size) alignment. Please sync this way as GenSHARED_DNC_BASE() in ldsGenLib.pl
    #$nSHARED_REGIONLength =  ($nSHARED_REGIONLength + $shared_region_base_alignd_size + ($shared_region_base_alignd_size-1)) & (~($shared_region_base_alignd_size-1));
    
    $nSHARED_REGIONEnd = &CommonUtil::GetMPUAligned($nSHARED_REGIONEnd, "SHARED_REGIONEnd");
    $nSHARED_REGIONBase = $nSHARED_REGIONEnd - $nSHARED_REGIONLength;

    return ($nSHARED_REGIONBase, $nSHARED_REGIONEnd, $nSHARED_REGIONLength);
}

###################################################################################################
# 
#  MemorySetting By chip
#
###################################################################################################

sub TK6291_MemorySetting  # Called by CollectMemorySetting($Setting_href)
{
    my ($Setting_href) = @_;
    &Default_MemorySetting($Setting_href);
}

sub MT6755_MemorySetting  # Called by CollectMemorySetting($Setting_href)
{
    my ($Setting_href) = @_;
    &Default_MemorySetting($Setting_href);
}

sub Default_MemorySetting  # Called by CollectMemorySetting($Setting_href)
{
    my ($Setting_href) = @_;
    # my $nTotalSize = (((4096)>>3)<<20); # default 512 MB
    
    # PCORE_LV1
    my $nPCORE_LV1_BASE = 0;
    my $nPCORE_LV1_LEN = GetPredefinedValue($Setting_href, "PCORE_LV1_LEN", undef, L1coreFileInfo::get(L1coreFileInfo::PCORE_LV1_SIZE)); # default is setting in master_info_gen.pl


    # ROM
    my $nROM_BASE = $nPCORE_LV1_BASE + $nPCORE_LV1_LEN;
    # l1core TCM: 0x0 ~ 0x80000, so the smallest size shoould be 0x80000. It should sync with AutoAdjust() in ModemReservedSize_AutoConfig.pl and TK6291_MemorySetting() in LdsGen.pl
    $nROM_BASE = 0x80000 if ($nROM_BASE < 0x80000);
    my $nROM_LEN = L1coreFileInfo::get(L1coreFileInfo::L1CORE_LV_SIZE); # default is setting in master_info_gen.pl


    # PCORE_LV2
    my $nPCORE_LV2_BASE = $nROM_BASE + $nROM_LEN;
    my $nPCORE_LV2_LEN = GetPredefinedValue($Setting_href, "PCORE_LV2_LEN", undef, L1coreFileInfo::get(L1coreFileInfo::PCORE_LV2_SIZE)); # default is setting in master_info_gen.pl


    # RAM base
    my $nRAM_BASE = GetPredefinedValue($Setting_href, "RAM_BASE", undef, $nPCORE_LV2_BASE + $nPCORE_LV2_LEN);  
    $nRAM_BASE = &CommonUtil::GetMPUAligned($nRAM_BASE, "RAM_BASE");
    my $nRAM_LEN = GetPredefinedValue($Setting_href, "RAM_LEN", undef, L1coreFileInfo::get(L1coreFileInfo::L1CORE_RWZI_SIZE)); # default is setting in master_info_gen.pl


    # SHARED_REGION
    my ($nSHARED_REGIONBase, $nSHARED_REGIONEnd, $nSHARED_REGIONLength) = GetSharedMemoryInfo();


    SetExistentValueByDefault($Setting_href, "PCORE_LV1_LEN", $nPCORE_LV1_LEN);
    SetExistentValueByDefault($Setting_href, "ROM_BASE", $nROM_BASE);
    SetExistentValueByDefault($Setting_href, "ROM_LEN", $nROM_LEN);
    SetExistentValueByDefault($Setting_href, "RAM_BASE", $nRAM_BASE);
    SetExistentValueByDefault($Setting_href, "RAM_LEN", $nRAM_LEN);
    SetExistentValueByDefault($Setting_href, "PCORE_LV2_BASE", $nPCORE_LV2_BASE);
    SetExistentValueByDefault($Setting_href, "PCORE_LV2_LEN", $nPCORE_LV2_LEN);
    SetExistentValueByDefault($Setting_href, "SHARED_REGION_BASE", $nSHARED_REGIONBase);
    SetExistentValueByDefault($Setting_href, "SHARED_REGION_END", $nSHARED_REGIONEnd);
    SetExistentValueByDefault($Setting_href, "SHARED_REGION_LEN", $nSHARED_REGIONLength);

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
