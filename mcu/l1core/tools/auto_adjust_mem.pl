#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
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
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   auto_adjust_mem.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   1. This script will read link error and decide to enter two-phase linking
#*   2. If need, it will calculate recommand memory configuration value.
#*   3. If turn on *_AUTO_CONFIG option, it will triger two-phase linking.
#*
#* Author:
#* -------
#*   Amber Su  (mtk03389)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 04 01 2014 carl.kao
#* [MOLY00061134] [SYSTEM SERVICE][AutoGen] AutoGen for TK6291
#* [TK6291] l1core ldsGen
#*
#* 09 16 2013 carina.liao
#* [MOLY00037976] [system service] U3G_TK6280_CC_DEV patch back to U3G_TK6280_DEV
#* phase in autoGen related scripts and new image layout
#*
#* 09 11 2013 ray.lin-wang
#* [MOLY00034122] [Build Environment] phase in MD32/CR4 flow
#* integrate from reorg CBr.
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************

#use strict;
BEGIN { push @INC, './l1core/tools/' }  # add additional library path
use auto_adjust_mem; #pm file name without case sensitivity/for AAPMC
use File::Path;
use File::Copy;
use File::Basename;
use L1coreCommonUtility;

#*************************************************************************************************
# Global Variable
#*************************************************************************************************
my $DEBUG = 1;

#*************************************************************************************************
# Input and Parameters initialization
#*************************************************************************************************
my ($TEP_LOG) = @ARGV;

#Set global variable
open (LOGFILE, "<$TEP_LOG") or &AAPMC_die("cannot open $TEP_LOG!");
while (<LOGFILE>) 
{
    if (/^(\S+)\s*=\s*(\S+)/) 
    {
      $keyname = $1;
      $${keyname} = $2;
    }
}
close LOGFILE;

my $ERR_CODE = ERR::ERR_UNEXPECTED;
my $remd_str;
my $out_str;
if($AAPMC_SCRIPT eq "DspSectionBase_AutoConfig")
{
    unlink $AAPMC_DSP_AUTOCONFIG_LOG if(-e $AAPMC_DSP_AUTOCONFIG_LOG);
    L1coreCommonUtil::WriteFileContent($AAPMC_DSP_AUTOCONFIG_LOG, undef); # create dsp temp for dsp script
    CheckExistence($AAPMC_DSP_AUTOCONFIG_LOG, 1);
    CheckExistence($AAPMC_MAKEFILE, 1);
    CheckExistence($AAPMC_CUSTOM_FOLDER_PATH, 0);
    backup_file($AAPMC_IMGLAYOUT,$AAPMC_DEBUG_FOLDER);
    backup_file($AAPMC_MASTER_INFO_LOG,$AAPMC_DEBUG_FOLDER);
    backup_file($AAPMC_ELF_PATH,$AAPMC_DEBUG_FOLDER);
    backup_file($AAPMC_READELF_PATH,$AAPMC_DEBUG_FOLDER);
    backup_file($AAPMC_DSP_MAP_PATH,$AAPMC_DEBUG_FOLDER);
    my $cmd = "perl l1core/tools/$AAPMC_SCRIPT.pl $AAPMC_IMGLAYOUT $AAPMC_TARGDIR \"$AAPMC_MAKEFILE\" $AAPMC_INFOMAKE_LOG $AAPMC_DSP_AUTOCONFIG_LOG $AAPMC_LOG_FOLDER $AAPMC_MASTER_INFO_LOG > $AAPMC_LOG_FOLDER/$AAPMC_SCRIPT.log 2>&1";
    print $cmd."\n" if($DEBUG);
    my $result = system($cmd);
    $ERR_CODE = $result>>8;
    $remd_str = L1coreCommonUtil::GetFileContent($AAPMC_DSP_AUTOCONFIG_LOG);
}  

my $out_str = ErrDispatch($ERR_CODE, $remd_str);
my $exit_err = OutputResult($ERR_CODE, $out_str);
exit $exit_err;


#****************************************************************************
# Subroutine
#****************************************************************************
sub OutputResult
{
    my ($err, $out_str) = @_;
    my $EXIT_CODE = 0;
    $EXIT_CODE = 1 if(($err != ERR::AAPMCLOG_SUCCESS) and
     ($err != ERR::AUTOCONFIG_SELF_MODIFY_SUCCESS) and
     ($err != ERR::NO_NEED_TO_UPDATE) and
     ($err != ERR::NO_MODIFY) and 
     ($err != ERR::NEED_TO_UPDATE));
    
    my $return_code = ERR::QueryErrMeaning($err);
    print "Result:$return_code: $out_str\n";
    print STDERR "Result:$return_code: $out_str\n";
    if(-e "$AAPMC_LOG_FOLDER/auto_adjust_mem.log"){
        mkpath($AAPMC_DEBUG_FOLDER) or AAPMC_die("create $AAPMC_DEBUG_FOLDER folder failed!") 
            if(!-d $AAPMC_DEBUG_FOLDER);
        print "copy $AAPMC_DEBUG_FOLDER/auto_adjust_mem.log from $AAPMC_LOG_FOLDER\n";
        copy("$AAPMC_LOG_FOLDER/auto_adjust_mem.log", "$AAPMC_DEBUG_FOLDER/auto_adjust_mem.log");
    }
    return $EXIT_CODE;
}

sub CheckExistence
{
    my ($strPath, $bFile) = @_;
    my ($pack_name, $file, $line_no) = caller;
    if($bFile)
    {
        AAPMC_die("File: $strPath did NOT exist!", $file, $line_no) if(!-e $strPath);    
    }
    else
    {
        AAPMC_die("Folder: $strPath did NOT exist!", $file, $line_no) if(!-d $strPath);    
    }    
}

sub ErrDispatch
{
    my ($err, $remd_str) = @_;
    my $check_log = "$AAPMC_LOG_FOLDER/$AAPMC_SCRIPT.log";
    my $sperate_line = "====================================================================\n";
    $remd_str .= "\n";
    my $out_str = "Executing $AAPMC_SCRIPT........";
    if($err == ERR::NO_MODIFY) { # NO_MODIFY: recommand a value but not modify custom_featureConfig.h || scatter file is checkin by human
        $out_str .= "Done.\nPlease adjust memory configuration manually and refer to $check_log\n";
        $out_str .= "$sperate_line$remd_str$sperate_line";
        if($AAPMC_SCRIPT eq "DspSectionBase_AutoConfig"){
            L1coreCommonUtil::WriteFileContent("$AAPMC_TEMP_FOLDER/~NoAAPMC.tmp", "." );
        }
    } elsif ($err == ERR::AAPMCLOG_SUCCESS) { # AAPMCLOG_SUCCESS: recommand a value and write to AAMPC.log
        $out_str .= "Done.\nThe adjustment of memory configuration is done and refer to $check_log\n";
        $out_str .= "$sperate_line$remd_str$sperate_line";
    } elsif ($err == ERR::NEED_TO_UPDATE) { # NEED_TO_UPDATE: recommand a value and write to AAMPC.log and do link directly
        $out_str .= "Done.\nJudgement: Need to re-link and refer to $check_log\n";
        $out_str .= "$sperate_line$remd_str$sperate_line";
    } elsif ($err == ERR::AUTOCONFIG_SELF_MODIFY_SUCCESS) { # AUTOCONFIG_SELF_MODIFY_SUCCESS: skip AAPMC operation and treat it as AAPMCLOG_SUCCESS
        # The pattern "The adjustment of memory configuration is done and refer to $check_log" will be parsed by auto-notify
        $out_str .= "Done.\nThe adjustment of memory configuration is done and refer to $check_log\n";
        $out_str .= "$sperate_line$remd_str$sperate_line";
    } elsif ($err == ERR::CANNOT_ADJUST) { # CANT_ADJUST: cannot adjust memory config
        $out_str .= "Failed.\nPlease check link error or check $check_log.\n";
        $out_str .= "$sperate_line$remd_str$sperate_line";
    }elsif ($err == ERR::ERR_LOADVIEWSIZE_INSUFFICIENT) { # ERR_LOADVIEWSIZE_INSUFFICIENT: cannot adjust memory config
        $out_str .= "Failed.\nPlease refer to $check_log for the recommended modification.\n";
        $out_str .= "$sperate_line$remd_str$sperate_line";
    } elsif ($err == ERR::NO_NEED_TO_UPDATE) { # NO_NEED_TO_UPDATE: skip AAPMC operation and treat it as AAPMCLOG_SUCCESS
        # The pattern "The adjustment of memory configuration is done and refer to $check_log" will be parsed by auto-notify
        $out_str .= "Done.\nNo need to adjust memory configuration and refer to $check_log\n";
        if($AAPMC_SCRIPT eq "DspSectionBase_AutoConfig"){
            L1coreCommonUtil::WriteFileContent("$AAPMC_TEMP_FOLDER/~NoAAPMC.tmp", ".");
        }
    } elsif ($err == ERR::ERR_MODIFYDUPLICATED) { # ERR_MODIFYDUPLICATED: cannot modify same memory config more than twice
        $out_str .= "Failed.\nDuplicate memory configuration value are existed. Please check $check_log\n";
    } elsif ((101 <= $err) && ( $err <= 110)) { # special error code
        $out_str .= "Failed.\nsome errors occured while executing l1core/tools/$AAPMC_SCRIPT.pl. Please check $check_log\n";
    } else {
        $out_str .= "Failed.\nsome errors occured while executing l1core/tools/$AAPMC_SCRIPT.pl. Please check $check_log\n";
    }
    return $out_str;
}

#*************************************************************************************************
# Error Handling Message
#*************************************************************************************************
sub AAPMC_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    my $final_error_msg = "ERROR: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    print STDERR $final_error_msg;
    exit 99;
}

#*************************************************************************************************
# Backup files to debug
#*************************************************************************************************
sub backup_file
{
    my ($input_file,$out_folder) = @_;
    if(-e $input_file)
    {
        my $bk_file = basename($input_file);
        mkpath("$out_folder") or &error_handler("create $out_folder folder failed!", __FILE__, __LINE__) if(!-d "$out_folder");
        print "copy $input_file \nto $out_folder/$bk_file.backup\n";
        copy("$input_file","$out_folder/$bk_file.backup");
    }
}
