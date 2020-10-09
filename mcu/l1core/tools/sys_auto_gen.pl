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
#*   sys_auto_gen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is used to control autoGen flow
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
# *============================================================================
# *             HISTORY
# * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
# *------------------------------------------------------------------------------
# * $Revision:   0.01  $
# * $Modtime:   Jul 28 2005 21:51:58  $
# * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/kal/nucleus/src/kal_nucleus_itc.c-arc  $
# *
# * 04 02 2014 carl.kao
# * [MOLY00061134] [SYSTEM SERVICE][AutoGen] AutoGen for TK6291
# * l1core sysgen2
# *
# * 04 01 2014 carl.kao
# * [MOLY00061134] [SYSTEM SERVICE][AutoGen] AutoGen for TK6291
# * [TK6291] l1core ldsGen
# *
# *------------------------------------------------------------------------------
# * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
# *============================================================================
# ****************************************************************************/

use strict;
#****************************************************************************
# Included Modules
#****************************************************************************
BEGIN { push @INC, './l1core/tools/' }  # add additional library path
use L1coreSysGenUtility;                 #pm file name without case sensitivity
use L1coreFileInfoParser;
use File::Copy;
#use tools::pack_dep_gen;
#PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $SYSAUTOGEN_VERNO = " v0.01_U3GDEV";
                       # v0.01 by Carl, initial version

#****************************************************************************
# Global Variables
#****************************************************************************
my $g_exit = 0;
my %g_MAKEFILE_OPTIONS;
my $g_strCOMPILER;

#****************************************************************************
# Input Parameters
#****************************************************************************
my $IMAGELAYOUT               = $ARGV[0];
my $themf                     = $ARGV[1];
my $BB_PATH                   = $ARGV[2];
my $INSIDE_MTK                = $ARGV[3];
my $DUMMY_IMAGELAYOUT_FORCE   = $ARGV[4];  # DUMMY TCL:
my $INFOMAKELOG               = $ARGV[5];
my $MASTER_INFO_FILE          = $ARGV[6];
my $CORE_ROOT                 = $ARGV[7];

my $BL_IMAGELAYOUT=0;
my $NEED_BUILD_BOOTLOADER=0;
my $DUMMY_IMAGELAYOUT_FORCE=0;

print "IMAGELAYOUT = $ARGV[0], themf = $ARGV[1], BB_PATH = $ARGV[2], INSIDE_MTK = $ARGV[3], DUMMY_IMAGELAYOUT_FORCE = $ARGV[4]
       INFOMAKELOG = $ARGV[5], MASTER_INFO_FILE = $ARGV[6], CORE_ROOT = $ARGV[7]\n";

#****************************************************************************
# 1 >>> Run Process
#****************************************************************************
if(1!=&L1coreFileInfo::Parse_MAKEFILE($themf, \%g_MAKEFILE_OPTIONS))
{
   &L1coreSysUtil::sysgen_die("Parse MakeFile failed");
}
$g_strCOMPILER = &L1coreFileInfo::GetCompiler();

#****************************************************************************
# 2 >>> Run Process
#****************************************************************************
$g_exit = &RunProcess("perl l1core/tools/sysGen1.pl $BB_PATH", 0);
print("perl l1core/tools/L1coreScatGen.pl $IMAGELAYOUT $BL_IMAGELAYOUT \"$ARGV[1]\" $BB_PATH $NEED_BUILD_BOOTLOADER $INSIDE_MTK $DUMMY_IMAGELAYOUT_FORCE $INFOMAKELOG $MASTER_INFO_FILE");
$g_exit = &RunProcess("perl l1core/tools/L1coreScatGen.pl $IMAGELAYOUT $BL_IMAGELAYOUT \"$ARGV[1]\" $BB_PATH $NEED_BUILD_BOOTLOADER $INSIDE_MTK $DUMMY_IMAGELAYOUT_FORCE $INFOMAKELOG $MASTER_INFO_FILE", $g_exit);


#****************************************************************************
# 0 >>> exit - no error: 0, error code: > 0
#****************************************************************************
exit $g_exit>>8;

#****************************************************************************
# subroutines
#****************************************************************************
sub RunProcess
{#exit - no error: 0, error code: > 0
    my ($CMD, $n_exit) = @_;
    if($n_exit == 0)
    {
        print "========COMMAND==========\n$CMD\n==\n";
        $n_exit = system($CMD);
        print "===========$n_exit=============\n"
    }
    return $n_exit;
}

#sub RunPreprocess
#{
#    my ($SrcPath, $nExit) = @_;
#    my ($DestPath, $bBackup) = &BackupFile($SrcPath, "txt", "h");
#    if($bBackup && $CC_CMD ne "")
#    {
#        $nExit = &RunProcess("$CC_CMD -C -E -P -D  LIB_PATH=$LIB_PATH $DestPath > $SrcPath", $nExit);        
#        &ChompEmptyLine($SrcPath) if($nExit == 0);
#    }
#    my $pch = $DestPath;
#    $pch =~ s/\.h/\.pch/;
#    move($DestPath, $pch);
#    return $nExit;
#}

sub BackupFile
{
    my ($SrcPath, $strNameToBeReplaced, $strNameToReplace)=@_;
    my $nRes = undef;
    my $DestPath = $SrcPath;
    $DestPath =~ s/$strNameToBeReplaced/$strNameToReplace/;
    print "[BackupFile] $SrcPath => $DestPath\n";
    copy($SrcPath, $DestPath);    
    $nRes = 1 if(-e $DestPath);
    return ($DestPath, $nRes);
}

sub ChompEmptyLine
{
    my ($strFilePath) = @_;
    my $content;
    open FILE, "<$strFilePath" or &L1coreSysUtil::sysgen_die("$strFilePath: open file error!", __FILE__, __LINE__);
    while(<FILE>)
    {
        chomp;
        $content .= $_. "\n" if ($_ ne "");
    }
    close FILE;
    open FILE, ">$strFilePath" or &L1coreSysUtil::sysgen_die("$strFilePath: open file error!", __FILE__, __LINE__);
    print FILE $content;
    close FILE;
}
