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
#*   DspShareBufferUpdate.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is used to modify elf file for share buffer mechanism
#* 
#*
#* Author:
#* -------
#*   Carl Kao  (mtk08237)
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './l1core/tools/', './common/tools/MemoryUtility/', './pcore/tools/'}  # add additional library path
use L1coreCommonUtility;
use L1coreSysGenUtility;

use SymFileParser;  #tools of pcore
use LinkerOutputParser;   #tools of pcore

#****************************************************************************
# Constants
#****************************************************************************
my $L1CORE_SHAREBUFFER_UPDATE_VERNO     = " v0.16";
                      # v0.16,  2015/10/26,  Carl, Using memory utility to parser input section rather than using temp parser (the parser will be merged to memory utility by SM team)
                      # v0.15,  2015/06/25,  Carl, Refine error message for avoid false alarm in EWS build
                      # v0.14,  2015/06/18,  Carl, Refine error message for avoid false alarm in EWS build
                      # v0.13,  2015/04/15,  Carl, refine setting for (MCU RO, MDHW RW)  DNC+NC, (MCU RW, MDHW RW)  DNC+NC
                      # v0.12 , 2015/04/02,  Rename SHARED_HW_BUFF_NONCACHEDZI to  SHARED_MCURO_HWRW_BUFF_NONCACHEDZI, 
                      #                      parsing new input section  SHARED_MCURW_HWRW_BUFF_NONCACHEDZI
                      # v0.11 , 2015/03/30,  Parsing new input section SHARED_HW_BUFF_NONCACHEDZI
                      # v0.10 , 2015/01/19,  Memory Utility Refinement
                      # v0.09 , 2014/12/29,  enhanced for (1) show located obj file, (2) support more configuration
                      # v0.08 , 2014/11/05,  print warning log when corresponding l1core symbol could not be found
                      # v0.07 , 2014/06/14,  refine error message for avoid false alarm in EWS build
                      # v0.06 , 2014/05/13,  refine error message for pcore/l1core
                      # v0.05 , 2014/05/10,  2-phase linking
                      # v0.04 , 2014/05/07,  2-phase linking
                      # v0.03 , 2014/05/07,  2-phase linking
                      # v0.02 , 2014/04/01,  2-phase linking
                      # v0.01 , 2014/03/28,  Initial revision


use constant Pcore        => "Pcore";
use constant L1core       => "L1core";

use constant VarName      => 0;
use constant VarAddr      => 1;
use constant VarObjName   => 2;

#****************************************************************************
# Input
#****************************************************************************
my $NeedToUpdate         = $ARGV[0];
my $L1CORE_MAP_FILE      = $ARGV[1];
my $L1CORE_SYM_FILE      = $ARGV[2];
my $L1CORE_ELF_FILE      = $ARGV[3];
my $PCORE_MAP_FILE       = $ARGV[4];
my $PCORE_SYM_FILE       = $ARGV[5];
my $BM_NEW               = $ARGV[6];
print "Input:\n$ARGV[0]\n$ARGV[1]\n$ARGV[2]\n$ARGV[3]\n$ARGV[4]\n$ARGV[5]\n$ARGV[6]\n\n";


#****************************************************************************
# Global
#****************************************************************************
my @default_pCore_SharedBuffRegion = ("SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW", 
                                      "SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI", 
                                      "SHARED_EXTSRAM_ZI",
                                      "SHARED_EXTSRAM") ;

my @inputSectionList = ("SHARED_BUFF_DYNAMICCACHEABLERW_NC\
|SHARED_BUFF_DYNAMICCACHEABLEZI_NC\
|SHARED_BUFF_NONCACHEDRW\
|SHARED_BUFF_NONCACHEDZI\
|SHARED_BUFF_MCURO_HWRW_DYNAMICCACHEABLEZI_NC\
|SHARED_BUFF_MCURO_HWRW_DYNAMICCACHEABLERW_NC\
|SHARED_BUFF_MCURO_HWRW_NONCACHEDZI\
|SHARED_BUFF_MCURO_HWRW_NONCACHEDRW\
|SHARED_BUFF_MCURW_HWRW_DYNAMICCACHEABLEZI_NC\
|SHARED_BUFF_MCURW_HWRW_DYNAMICCACHEABLERW_NC\
|SHARED_BUFF_MCURW_HWRW_NONCACHEDZI\
|SHARED_BUFF_MCURW_HWRW_NONCACHEDRW\
");

my %g_L1coreShareBuffSymbol_Info;
my %g_PcoreShareBuffSymbol_Info;
my %g_L1coreShareBuffNameToIndex;
my %g_PcoreShareBuffNameToIndex;
my $g_PcoreSymbolCount;
my $g_L1coreSymbolCount;
my @g_NoMatchPcoreSymbol;
my @g_NoMatchL1coreSymbol;
     
my $bNeedToUpdate = ($NeedToUpdate eq "TRUE") ? 1 : 0;
my $g_nCacheline = L1coreSysUtil::GetCacheLineSize();

#****************************************************************************
# >>>  Main Flow
#****************************************************************************
if($bNeedToUpdate == 0)
{
    print "bNeedToUpdate = $bNeedToUpdate, no need to update share buffer\n";
    exit 0 ;
}

ProcessSharedBUfferUpdate(0,   # ! it should be set to 1 after MP
                          "EXTSRAM_SHARE_BUFFER", "p_",
                          $inputSectionList[0], &ExcludeInputSection(0),
                          @default_pCore_SharedBuffRegion);

exit 0;


#****************************************************************************
# Subroutines
#****************************************************************************
sub ExcludeInputSection
{
    my ($nIncludeIndex) = (@_);
	my $nIdx;
	my $strRet = "";
    
    for ($nIdx=0; $nIdx<=$#inputSectionList; ++$nIdx)
    {
		next if ($nIdx == $nIncludeIndex);		
		$strRet .= $inputSectionList[ $nIdx ];
    }

    return $strRet;
}

sub ProcessSharedBUfferUpdate
{
    my ($bCheckPcore, 
        $L1coreSection, $L1coreSpecficSymbolPattern, 
        $PcoreSection, $PcoreSkipSection, 
        @pCore_SharedBuffRegion) = (@_);

    resetGlobalVar();

    # add below checking for avoid false alarm in EWS build
    &CheckParamForEWS();

    # 1 Get Copro-side share buffer symbol and base
    $g_L1coreSymbolCount =GetShareBufferSymbolListIn(\%g_L1coreShareBuffSymbol_Info, \%g_L1coreShareBuffNameToIndex, $L1CORE_MAP_FILE, $L1coreSection, "", $L1coreSpecficSymbolPattern);


    # 2 Get Master-side share buffer symbol and base & check alignment
    $g_PcoreSymbolCount = GetShareBufferSymbolListIn(\%g_PcoreShareBuffSymbol_Info, \%g_PcoreShareBuffNameToIndex, $PCORE_MAP_FILE, $PcoreSection, $PcoreSkipSection, "");


    # 3 Make sure all of the primary symbols have correspondig copro symbols, vise versa
    my $PcoreResult = CheckPcoreSymbolList($L1coreSpecficSymbolPattern);
    my $L1coreResult = CheckL1coreSymbolList($L1coreSpecficSymbolPattern);
    PrintWarnSymboList($bCheckPcore) if ($PcoreResult);
    PrintErrorSymboList($L1coreSpecficSymbolPattern) if ($L1coreResult);


    # 4 Parse ReadElf output txt
    SymFileParser::ParseSYM($L1CORE_SYM_FILE);
    my $strL1coreSymSection = "ROM";
    my $nL1coreSymSectionVMA    = hex(SymFileParser::GetExeRegionInfo($strL1coreSymSection, Region::VMA));
    my $nL1coreSymSectionOffset = hex(SymFileParser::GetExeRegionInfo($strL1coreSymSection, Region::Offsets));


    # 5 Modify each symbol
    my $nPcoreSymbolVMA = 0;
    print "----------Modify symbol list----------\n";
    foreach my $nIndex (keys %g_L1coreShareBuffSymbol_Info)
    {
        my $strSymbolName = $g_L1coreShareBuffSymbol_Info{$nIndex}->[VarName];
        my $nL1coreSymbolVMA = $g_L1coreShareBuffSymbol_Info{$nIndex}->[VarAddr];

        $nPcoreSymbolVMA = GetModifyBassAddr($strSymbolName, $L1coreSpecficSymbolPattern);

        my $nAddrInElf = $nL1coreSymbolVMA - $nL1coreSymSectionVMA + $nL1coreSymSectionOffset;
        # print "CoproSymbolName:$strSymbolName, CoproSymbolBase:$nL1coreSymbolVMA, nAddrInElf:$nAddrInElf, MasterSymbolBase:$nPcoreSymbolVMA\n";
        printf("L1coreSymbolName:%s, l1coreSymbolBase:0x%.8x, nAddrInElf:0x%.8x, MasterSymbolBase:0x%.8x\n", $strSymbolName, $nL1coreSymbolVMA, $nAddrInElf, $nPcoreSymbolVMA);
        ModifyElf($nAddrInElf, $nPcoreSymbolVMA);
    }
    
    #6 Done
}


#---------------------------------------------------------------------


sub resetGlobalVar
{
     %g_L1coreShareBuffSymbol_Info=();
     %g_PcoreShareBuffSymbol_Info=();
     %g_L1coreShareBuffNameToIndex=();
     %g_PcoreShareBuffNameToIndex=();
     $g_PcoreSymbolCount = 0;
     $g_L1coreSymbolCount = 0;
     @g_NoMatchPcoreSymbol =();
     @g_NoMatchL1coreSymbol=();
}


#---------------------------------------------------------------------


sub ModifyElf
{
    my ($ModifyAddr, $nModifyValue) = (@_);
    my $buffer;

    open (FILE_HANDLE, "+<$L1CORE_ELF_FILE") or &ReadElf_die("[2.0]$L1CORE_ELF_FILE: file error!", __FILE__, __LINE__);
    binmode FILE_HANDLE;
    seek FILE_HANDLE,$ModifyAddr,0;
    $buffer = pack("L", $nModifyValue);
    print FILE_HANDLE $buffer;
}

sub wait_for_resue
#sub GetMasterShareBuffSymbolList
{  
    my (@pCore_SharedBuffRegion) = (@_);
    
    SymFileParser::ParseSYM($PCORE_SYM_FILE);

    foreach my $SharedBuffRegion (@pCore_SharedBuffRegion)
    {
        my $symbol_aref = SymFileParser::GrepSymbolBySection($SharedBuffRegion);
        foreach my $tmp (@$symbol_aref)
        {
            my $strSymbolName = $tmp->[SymTable::Name];
            my $strAddress = $tmp->[SymTable::Addr];
            #check alignment
            if(($SharedBuffRegion =~ /DYNAMIC_CACHEABLE/) && (($strAddress%$g_nCacheline) != 0))
            {
                sharebufferupdate_die("[3.3]The base address($strAddress) of shared buffer symbol($strSymbolName) in pcore is not $g_nCacheline bytes aligned\n");
            }
            $g_PcoreShareBuffSymbol_Info{$g_PcoreSymbolCount} = [$strSymbolName, $strAddress];
            $g_PcoreSymbolCount++;
            print "Region = $SharedBuffRegion, SymbolName = $strSymbolName, Address = $strAddress\n";
        }    	
    }
}


#---------------------------------------------------------------------


sub GetModifyBassAddr
{
    my ($strCoproSymbolName, $SpecficSymbolPattern) = (@_);
    $SpecficSymbolPattern= "^".$SpecficSymbolPattern;
    
    my $strFileName;
    foreach my $nIndex (0..($g_PcoreSymbolCount-1))
    {     
        my $strMasterSymbolName = $g_PcoreShareBuffSymbol_Info{$nIndex}->[VarName];
        my $strMasterSymbolBase = $g_PcoreShareBuffSymbol_Info{$nIndex}->[VarAddr];
        $strCoproSymbolName =~ s/$SpecficSymbolPattern//;

        if($strMasterSymbolName eq $strCoproSymbolName)
        {
            return 	$strMasterSymbolBase;
        }
    }
    my $strCoproSymbol = "$SpecficSymbolPattern"."$strCoproSymbolName";
    sharebufferupdate_die("The L1CORE Symbol($strCoproSymbolName) can not find the corresponding PCORE Symbol!\nPlease also define this share buffer in PCORE\n")
}


#---------------------------------------------------------------------


sub CheckPcoreSymbolList
{
    my ($SpecficSymbolPattern) = @_;
    $SpecficSymbolPattern= "^".$SpecficSymbolPattern;
    
    my $bmatch = 0;
    my $bNomatch = 0;
    foreach my $nMasterIndex (0..($g_PcoreSymbolCount-1))
    {     
        $bmatch = 0;
        my $strMasterSymbolName = $g_PcoreShareBuffSymbol_Info{$nMasterIndex}->[VarName];
        
        # todo : use   %g_L1coreShareBuffNameToIndex or %g_PcoreShareBuffNameToIndex rather than foreach
        foreach my $nCoproIndex (keys %g_L1coreShareBuffSymbol_Info)
        {
            my $strCoproSymbolName = $g_L1coreShareBuffSymbol_Info{$nCoproIndex}->[VarName];
            $strCoproSymbolName =~ s/$SpecficSymbolPattern//;
            if($strMasterSymbolName eq $strCoproSymbolName)
            {
                $bmatch = 1;
                last;
            }
        }
        if(!$bmatch)
        {
            push @g_NoMatchPcoreSymbol , $strMasterSymbolName;
            $bNomatch = 1;
        }
    }
    return $bNomatch;
}

sub CheckL1coreSymbolList
{
    my ($SpecficSymbolPattern) = @_;
    $SpecficSymbolPattern= "^".$SpecficSymbolPattern;
    
    my $bmatch = 0;
    my $bNomatch = 0;
    foreach my $nCoproIndex (keys %g_L1coreShareBuffSymbol_Info)
    {
        $bmatch = 0;
        my $strCoproSymbolName = $g_L1coreShareBuffSymbol_Info{$nCoproIndex}->[VarName];
        $strCoproSymbolName =~ s/$SpecficSymbolPattern//;

        # todo : use   %g_L1coreShareBuffNameToIndex or %g_PcoreShareBuffNameToIndex rather than foreach
        foreach my $nMasterIndex (0..($g_PcoreSymbolCount-1))
        {
            my $strMasterSymbolName = $g_PcoreShareBuffSymbol_Info{$nMasterIndex}->[VarName];
            if($strMasterSymbolName eq $strCoproSymbolName)
            {
                $bmatch = 1;
                last;
            }
        }
        if(!$bmatch)
        {
            push @g_NoMatchL1coreSymbol , $strCoproSymbolName;
            $bNomatch = 1;
        }
    }    
    return $bNomatch;
}


#---------------------------------------------------------------------


sub PrintWarnSymboList
{
    my ($bReportError) = (@_);

    # BM will search the key word "cannot find" in the log and report error. DO NOT print "cannot find" in this function
    if(scalar(@g_NoMatchPcoreSymbol))
    {
        print "\n!!!!!!!!The listed PCORE Symbols can not find the corresponding L1CORE Symbols!!!!!!!!\n";
        foreach my $symbol (@g_NoMatchPcoreSymbol)
        {
            my $strLocatedObjName = SymbolToObjName(Pcore, "$symbol");
            print"    The PCORE Symbol($symbol) @ $strLocatedObjName can not find the corresponding L1CORE Symbol\n"
        }
        print("The PCORE Symbols can not find the corresponding L1CORE Symbols!\nPlease also define this share buffer in L1CORE\n");       
        print("If the shared variable will not be used in L1CORE, please declare it as non-shared variable to save shared memory space\n");
    }
    sharebufferupdate_die("[3.4]please resolve the above errors",__FILE__,__LINE__) if($bReportError);
}


sub PrintErrorSymboList
{
    my ($SpecficSymbolPattern) = @_;
    
    # BM will search the key word "cannot find" in the log and report error
    if(scalar(@g_NoMatchL1coreSymbol))
    {
        print "\n!!!!!!!!The listed L1CORE Symbols can not find the corresponding PCORE Symbols!!!!!!!!\n";
        foreach my $symbol (@g_NoMatchL1coreSymbol)
        {
            my $strLocatedObjName = SymbolToObjName(L1core, "$SpecficSymbolPattern"."$symbol");
            print"    The L1CORE Symbol(".$SpecficSymbolPattern."$symbol) @ $strLocatedObjName cannot find the corresponding PCORE Symbol\n"
        }
        print("The L1CORE Symbols can not find the corresponding PCORE Symbols!\nPlease also define this share buffer in PCORE\n")
    }
    
    (($BM_NEW ne "bm_new") ?
        sharebufferupdate_die("[3.2]please resolve the above errors",__FILE__,__LINE__):
        sharebufferupdate_exit0("[3.2]please resolve the above matching problem",__FILE__,__LINE__));
}


#---------------------------------------------------------------------


sub sharebufferupdate_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    &L1coreCommonUtil::error_handler($error_msg, $file, $line_no, 'L1CORE_SHAREBUFF_UPDATE'); 
}

sub sharebufferupdate_exit0
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    &L1coreCommonUtil::error_handler_no_error_keyowrd($error_msg, $file, $line_no, 'L1CORE_SHAREBUFF_UPDATE'); 
}


#---------------------------------------------------------------------

sub GetShareBufferSymbolListIn
{
    my ($SymbolInfo_aref, $SymbolNameToIndex_aref, $MAPPath, $region_pattern, $skip_region_pattern, $SpecficSymbolPattern) = @_;
    my $ShareBuffSymbol_count = 0;

    
    my $start_parsing = 0;       
    my $strLocatedObjName = "NOT_FOUND";


if(1)
{# using memory utility parser

    $region_pattern =~ s/\n//g;
    my @strInputSectionList= split(/\|/, $region_pattern);

    &LinkerOutputParser::FileParse($MAPPath);

    for my $j (0 .. (scalar(@strInputSectionList)-1))
    {
        my $strInputSectionName = $strInputSectionList[$j];        
        my $InputSectionSymbolInfo_aref = &LinkerOutputParser::GrepSymbolByInputSection($strInputSectionName);

        for my $i (0 .. (scalar(@$InputSectionSymbolInfo_aref)-1))
        {
            my $strSymbolName =         ${@$InputSectionSymbolInfo_aref[$i]}[0];
            my $nSymbolAddr =           hex(${@$InputSectionSymbolInfo_aref[$i]}[1]);
            my $strLocatedObjName =     ${@$InputSectionSymbolInfo_aref[$i]}[2];
            my $strInputSectionName =   ${@$InputSectionSymbolInfo_aref[$i]}[5];

            if ( $strInputSectionName != /$region_pattern/)
            {
                print "undef expected symbol: $strSymbolName, $nSymbolAddr, $strLocatedObjName, $strInputSectionName\n";
                exit 1;
            }
            $SymbolNameToIndex_aref->{$strSymbolName} = $ShareBuffSymbol_count;
            $SymbolInfo_aref->{$ShareBuffSymbol_count++} = [$strSymbolName, $nSymbolAddr, $strLocatedObjName];
        }
    }
    
}
else
{# using my parser

    # for below case 
    #                0x00800000                Image$$SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$ZI$$Limit = .   
    #                0x00800000        0x0 load address 0x0001e668
    #                0x005c0000        0x4 LONG 0x0
    my $skip_pattern = "Image\\$\\$|\\$\\$Base|\\$\\$Limit|\\$\\$Length|load address|\ LONG\ ";
    
    open (FILE_HANDLE, "<$MAPPath") or &MAP_die("$MAPPath: file error!", __FILE__, __LINE__);
    
    while (<FILE_HANDLE>)
    {
        my $strLine = $_;
        if(/^\s+(0x\w+)\s+(\w+)/)
        {
            # for below case
            #                0x00024054                p_SLILM
            my $nSymbolAddr = hex($1);
            my $strSymbolName = $2;

            next if(!$start_parsing or $strLine =~ /$skip_pattern/);
            if($strLine =~ /\((\w+\.obj)\)/)
            {
                # for below case
                # SHARED_HW_BUFF_NONCACHEDZI
                #                0x00810000       0x20 ./build/TK6291_FPGA/BASIC/bin/lib/libkal.a(kal_nucleus_itc.obj)
                #                0x00810000                SLILM
                $strLocatedObjName = $1;

                # for below case
                # SHARED_BUFF_NONCACHEDZI
                # 0x00000000        0x8 ./build/TK6291_FPGA/BASIC/bin/lib/libdevdrv.a(cc_irq_sys_comm.obj)  <-- skip such case
                if ($strLine =~ /0x00000000/) 
                {
                    $start_parsing = 0;
                    $strLocatedObjName = "NOT_FOUND";
                }
                next;
            }
            next if($strLine !~ /$SpecficSymbolPattern/);
            
            $SymbolNameToIndex_aref->{$strSymbolName} = $ShareBuffSymbol_count;
            $SymbolInfo_aref->{$ShareBuffSymbol_count++} = [$strSymbolName, $nSymbolAddr, $strLocatedObjName];
        }
        elsif(/$region_pattern/)
        {
            $start_parsing = 1;
        }
        elsif(/^\s\.(\w+)|$skip_region_pattern/)
        {
            $start_parsing = 0;
        }
    }
    close FILE_HANDLE;
} # end of using my parser

    return ($ShareBuffSymbol_count);    
}


#---------------------------------------------------------------------


sub SymbolToObjName
{
    my ($strCore, $strSymbolName)= (@_);

    if( $strCore eq L1core)
    {
        my $nIndex = $g_L1coreShareBuffNameToIndex{$strSymbolName};
        return $g_L1coreShareBuffSymbol_Info{$nIndex}->[VarObjName];
    }
    else
    {
        my $nIndex = $g_PcoreShareBuffNameToIndex{$strSymbolName};
        return $g_PcoreShareBuffSymbol_Info{$nIndex}->[VarObjName];
    }    
}

#---------------------------------------------------------------------


sub CheckParam
{
    my ($stage, $file, $checkCore) = @_;
    
    if(!(defined $file and -e $file))
    {
        if($BM_NEW ne "bm_new")
        {
            &sharebufferupdate_die("[Parameter $stage] $file doesn't exist. \"Please fix $checkCore build error (check error message in log folder) to avoid this error!\"", __FILE__, __LINE__);
        }
        else
        {
            print("[Parameter $stage] $file doesn't exist. \"Please fix $checkCore build error (check error message in log folder) to avoid this build check!\"", __FILE__, __LINE__);;
            exit 0;
        }
    }
}


#---------------------------------------------------------------------


sub CheckParamForEWS
{
    &CheckParam(1, $L1CORE_MAP_FILE, "L1core");
    &CheckParam(2, $L1CORE_SYM_FILE, "L1core");
    &CheckParam(3, $L1CORE_ELF_FILE, "L1core");
    &CheckParam(4, $PCORE_MAP_FILE,  "Pcore");
    &CheckParam(5, $PCORE_SYM_FILE,  "Pcore");
}


#---------------------------------------------------------------------




