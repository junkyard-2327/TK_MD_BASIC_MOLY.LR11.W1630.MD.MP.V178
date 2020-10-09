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
#*   ListTopSizeObj.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This perl is used to list the top size object files
#*       
#*
#* Author:
#* -------
#*   
#*
#****************************************************************************/
use strict;
BEGIN { push @INC, './common/tools/', './common/tools/MemoryUtility/' }
use LinkerOutputParser;
use File::Basename;
use constant Top_N  => 15;

use constant PSCORE         => "(PS) ";
use constant L1CORE         => "(L1) ";


my $nVerion = "v1.00";
             # v1.00 , 20150918 , Carl , 1st version for LR11

my ($file_PS, $file_L1) = @ARGV;
$file_PS =~ s/\\/\\\\/;
$file_L1 =~ s/\\/\\\\/;


if( !($file_PS =~ /\.map$/) || !($file_PS =~ /_P_/) ||
    !($file_L1 =~ /\.map$/) || !($file_L1 =~ /_L_/) ||
    scalar(@ARGV) != 2 )
{
    &Usage();
}

my ($objs1_aref, $RO_1_href, $RW_1_href, $ZI_1_href) = &GetAllOBJs($file_PS);
my ($objs1_aref_L1, $RO_1_href_L1, $RW_1_href_L1, $ZI_1_href_L1) = &GetAllOBJs($file_L1);

my $total_RO_1 = 0;
my $total_RW_1 = 0;
my $total_ZI_1 = 0;


my @objs = @$objs1_aref;
my $core = PSCORE;
foreach my $obj (@objs)
{
if(1){
    $total_RO_1 += $$RO_1_href{$obj};
    $total_RW_1 += $$RW_1_href{$obj};
    $total_ZI_1 += $$ZI_1_href{$obj};
    $$RO_1_href{$core.$obj} = $$RO_1_href{$obj};
    $$RW_1_href{$core.$obj} = $$RW_1_href{$obj};
    $$ZI_1_href{$core.$obj} = $$ZI_1_href{$obj};
}
    delete  $$RO_1_href{$obj};
    delete  $$RW_1_href{$obj};
    delete  $$ZI_1_href{$obj}
}

my $RO_FILL_size = $$RO_1_href_L1{'*fill*'};
my $RW_FILL_size = $$RW_1_href_L1{'*fill*'};
my $ZI_FILL_size = $$ZI_1_href_L1{'*fill*'};
$$RO_1_href_L1{'*fill*'} = 0;
$$RW_1_href_L1{'*fill*'} = 0;
$$ZI_1_href_L1{'*fill*'} = 0;

@objs = @$objs1_aref_L1;
$core = L1CORE;
foreach my $obj (@objs)
{
    $total_RO_1 += $$RO_1_href_L1{$obj};
    $total_RW_1 += $$RW_1_href_L1{$obj};
    $total_ZI_1 += $$ZI_1_href_L1{$obj};
    $$RO_1_href{$core.$obj} = $$RO_1_href_L1{$obj};
    $$RW_1_href{$core.$obj} = $$RW_1_href_L1{$obj};
    $$ZI_1_href{$core.$obj} = $$ZI_1_href_L1{$obj};
}


my @objs_PS = map {PSCORE.$_} @$objs1_aref;
my @objs_L1 = map {L1CORE.$_} @$objs1_aref_L1;
@objs = (@objs_PS, @objs_L1);






my @RW_Top = sort { $$RW_1_href{$b} <=> $$RW_1_href{$a} } @objs ;
my @ZI_Top = sort { $$ZI_1_href{$b} <=> $$ZI_1_href{$a} } @objs ;


print "Top", Top_N, " result as below:\n";
    print "*"x80 . "\n";
    print "Rank Core ObjectName                RW/ZI_Size ROSize;RWSize;ZISize\n";
    my $sum=0;
    for my $i (0..Top_N)
    {
    printf (" %2d %-30s\t%5dK\t%d;%d;%d\n", $i+1, $RW_Top[$i], int($$RW_1_href{$RW_Top[$i]}/1024),
        $$RO_1_href{$RW_Top[$i]}, $$RW_1_href{$RW_Top[$i]}, $$ZI_1_href{$RW_Top[$i]} );
        $sum += $$RW_1_href{$RW_Top[$i]};
    }
    print "Top", Top_N, " Contribute ", $sum, "\tTotal:", $total_RW_1, "\t=", int(100*$sum/$total_RW_1), "%\n";
    print "*"x80 . "\n";
    my $sum=0;
    for my $i (0..Top_N)
    {
    printf (" %2d %-30s\t%5dK\t%d;%d;%d\n", $i+1, $ZI_Top[$i], int($$ZI_1_href{$ZI_Top[$i]}/1024),
        $$RO_1_href{$ZI_Top[$i]}, $$RW_1_href{$ZI_Top[$i]}, $$ZI_1_href{$ZI_Top[$i]} );
        $sum += $$ZI_1_href{$ZI_Top[$i]};
    }
    print "Top", Top_N, " Contribute ", $sum, "\tTotal:", $total_ZI_1, "\t=", int(100*$sum/$total_ZI_1), "%\n";
    print "*"x80 . "\n";
    
    
    #print "(result without fill)\n";
    print_result($total_RO_1, $total_RW_1, $total_ZI_1);
    if(0)
    {
    printf (" *  %-30s\t%5dK\t%d;%d;%d\n", '*fill*', int(($RW_FILL_size+$ZI_FILL_size)/1024),
        $RO_FILL_size, $RW_FILL_size, $ZI_FILL_size );
    print "*"x80 . "\n";
    print "(result with fill)\n";
    print_result($total_RO_1+$RO_FILL_size, $total_RW_1+$RW_FILL_size, $total_ZI_1+$ZI_FILL_size,); 
    }


exit 0;

    
sub print_result
{
        my ($RO, $RW, $ZI) = @_;
    printf ("Total RO = %d, RO+RW+RW+ZI = %9d\n",$RO, $RO+$ZI+$RW*2); 
    my $sum1=1+int(($RO+$RW)/(1024*1024));
    printf ("Estimate RAM Usage = ROM (RO+RW) %2dMB\n", $sum1);
    my $sum2=1+int(($ZI+ 64*1024*(1+int($RW/(64*1024))))/(1024*1024));

    printf ("                   +Data (RW+ZI) %2dMB\n", $sum2);
    printf ("                   =        SUM  %2dMB\n", $sum1+$sum2);
    print "*"x80 . "\n";
    
}
    

sub GetAllOBJs
{
    my ($file) = @_;
    my $symfile = $file;
    my $exeregion_aref;
    
    if($file =~ /\.map$/)
    {
        $symfile =~ s/map/sym/;
        if(!-f $symfile)
        {
            my $file = basename($symfile);
            my $dirname  = dirname($symfile);
            $symfile = $dirname."\/dummy_$file";
        } 
        &LinkerOutputParser::FileParse($symfile);
    }
    &LinkerOutputParser::FileParse($file);
    $exeregion_aref = &LinkerOutputParser::ListAllExeRegion(1);
    

    my @objs = ();
    my @uni_objs = ();
    my %RO_Size;
    my %RW_Size;
    my %ZI_Size;
    my %RWZI_Size;
    my %count;
    
    if (defined $exeregion_aref)
    {
        foreach my $temp(@$exeregion_aref)
        {
            my $obj_aref = &LinkerOutputParser::GetObjByExeRegion($temp);
            if (defined $obj_aref)
            {
                foreach (@$obj_aref)
                {
                    push(@objs, $_);
                }
            }
        }
    }
    
    @uni_objs = grep { ++$count{ $_ } < 2; } @objs; 
    
    foreach my $obj(@uni_objs)
    {
        my ($nRO_Size, $nRW_Size, $nZI_Size) = (0,0,0);
        
        if($file =~ /\.lis$/)
        {
            $nRO_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "RO Data") + &LinkerOutputParser::ListObjSummaryInfo($obj, "Code");
            $nRW_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "RW Data");
            $nZI_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "ZI Data");
            $RO_Size{$obj} = $nRO_Size;
            $RW_Size{$obj} = $nRW_Size;
            $ZI_Size{$obj} = $nZI_Size;
        }
        elsif($file =~ /\.map$/)
        {
            $nRO_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "RO");
            $nRW_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "RW");
            $nZI_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "ZI");
            $RO_Size{$obj} = $nRO_Size;
            $RW_Size{$obj} = $nRW_Size;
            $ZI_Size{$obj} = $nZI_Size;
        }
    }
    
    return (\@uni_objs, \%RO_Size, \%RW_Size, \%ZI_Size);
}


sub Usage
{
  print <<"__EOFUSAGE";

usage: perl ListTopSizeObj.pl PSCORE_map_file_path L1CORE_map_file_path

PSCORE_map_file_path, L1CORE_map_file_path: map file path for codebase you want to list the top RWZI

e.g. perl ./common/tools/MemoryUtility/ListTopSizeObj_LR11.pl ./build/MT6755_SP/LWCTG_MP1/bin/MT6755_SP_PCB01_P_MT6755_S00.map  ./build/MT6755_SP/LWCTG_MP1/l1core/bin/MT6755_SP_PCB01_L_MT6755_S00.map

Note: 
For GCC linker output, there should be corresponding .sym file in the same folder of .map file.

__EOFUSAGE
  exit 1;
}



