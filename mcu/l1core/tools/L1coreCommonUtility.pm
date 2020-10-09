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
#*   CoproCommonUtility.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to provide common utility
#*
#* Author:
#* -------
#*   Carina Liao (mtk04017)
#*
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './l1core/tools/' }  # add additional library path
package L1coreCommonUtil;
use POSIX qw(floor ceil);
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# CommonUtility Version
#****************************************************************************
my $COMMONUTILITY_VERNO     = " v0.02";
                              # v0.02,  2015/06/25,  Carl, Add error_handler_no_error_keyowrd() for avoid false alarm in EWS build
                              # v0.01 , 2013/07/01,  Initial revision


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

#****************************************************************************
# subroutine:  error_handler_no_error_keyowrd
# input:       $error_msg:     error message
# note: this function is the same as error_handler except showing keyowrd "error"
#          using this function if you do not want to receive build fail false alarm by bm_new
#****************************************************************************
sub error_handler_no_error_keyowrd
{
    my ($error_msg, $file, $line_no, $strTitle) = @_;
       
    my $final_error_msg = "$strTitle : $error_msg at $file line $line_no : $!\n";
    print $final_error_msg;
    die $final_error_msg;
}


#****************************************************************************
# subroutine:  Dec2Hex: translate dec number to hex string
# input:       Number in dec
# output:      hex in string 
#****************************************************************************
#Hex2Dex() : hex string to dec number = hex()
sub Dec2Hex
{
    my ($num) = @_;
    return sprintf("0x%x", $num);
}

#****************************************************************************
# subroutine:  Dec2Hex_8bit: translate dec number to hex string (padding zero to 8bits)
# input:       Number in dec
# output:      hex in string 
#****************************************************************************
#Hex2Dex() : hex string to dec number = hex()
sub Dec2Hex_8bit
{
    my ($num) = @_;
    return sprintf("%08X", $num);
}

#****************************************************************************
# subroutine:  GetFileContent
# input:   strFilePath
# output:  strFileContent after chomp
#****************************************************************************
sub GetFileContent
{
    my ($strFilePath) = @_;
    my $content;
    my ($pack_name, $file, $line_no) = caller;
    open FILE, "<$strFilePath" or &error_handler("$strFilePath: open file error!", $file, $line_no, 'L1coreCommonUtil::GetFileContent');
    {
        local $/;
        $content = <FILE>;
    }
    close FILE;
    chomp($content);
    return $content;
}

#****************************************************************************
# subroutine:  WriteFileContent
# input:   $strFilePath, $$strFileContent, 
#          $bAppend: 0 or undef= not append in the file, 1=need to append
# output:  x
#****************************************************************************
sub WriteFileContent
{
    my ($strFilePath, $strContent, $bAppend) = @_;
    my $strAppend = "";
    $strAppend = ">" if($bAppend);
    open FILE, ">$strAppend$strFilePath" or &error_handler("$strFilePath: open file error!", __FILE__, __LINE__, 'L1coreCommonUtil::WriteFileContent');
    print FILE $strContent;    
    close FILE;
}

#****************************************************************************
# subroutine:  ParseCSV
# input:   1. strFilePath
#          2. $bSkipFirstLine: 1=skip, 0 or undef=not to skip
# output:  1. \@ContentList: array reference [[column, column, column...], [column, column, column...], ...]
#          2. \@LineMeaning: if $bSkipFirstLine==1, return undef; if not, return FirstLine in [colume, colume,...]
#****************************************************************************
sub ParseCSV
{
    my ($strFilePath, $bSkipFirstLine) = @_;
    my @ContentList;
    my @LineMeaning;
    my %IndexByName;
    open FILE, "<$strFilePath" or &error_handler("$strFilePath: open file error!", __FILE__, __LINE__, 'L1coreCommonUtil::ParseCSV');
    if(1 != $bSkipFirstLine)
    {
        my $FirstLine = <FILE>;
        $FirstLine =~ s/\r|\n//g;
        @LineMeaning = split(/,/, $FirstLine, -1);
        for(my $i=0; $i<=$#LineMeaning ; $i++)
        {
            $IndexByName{$LineMeaning[$i]} = $i;
        }
    }
    while(<FILE>)
    {
        $_ =~ s/\r|\n//g;
        my @entry = split(/,/, $_, -1);
        for(my $i= (scalar(@LineMeaning)- scalar(@entry)); (($i>0) && (1 != $bSkipFirstLine)); $i--)
        {
            push @entry, "";
        }
        my @Removed_Empty; # to replace "  " by ""  
        foreach my $item(@entry)
        {
            my $orgitem = $item;
            $item =~ s/\s//g;
            push (@Removed_Empty, ($item eq "") ? "" : $orgitem );
        }
        push @ContentList, \@Removed_Empty;
    }
    close FILE;
    return (\@ContentList, \%IndexByName);
}

#****************************************************************************
# subroutine:  ConnetString
# input:   1. \@token
#          2. string to conect
#          3. $bConnectEmptyString: 1=support emptystring connect, 0 or undef=not support it
# output:  string
#****************************************************************************
sub ConnetString
{
    my ($token_ref, $strConnector, $bConnectEmptyString) = @_;
    my $strResult;
    if($bConnectEmptyString)
    {
        $strResult = join($strConnector, @$token_ref);
    }
    else
    {
        foreach my $i (@$token_ref)
        {
            my $temp = $i;
            $temp =~ s/\s//g;
            if($strResult eq "" and $temp ne "")
            {
                $strResult = $i;
            }
            else
            {
                $strResult = join($strConnector, $strResult, $i) if($i ne "");
            }
        }
    }
    return $strResult;
}
#****************************************************************************
# subroutine:  HashStringGenerator
# input:   1. \%Hash
# output:  string
#****************************************************************************
sub HashStringGenerator
{
    my ($href) = @_;
    my $strOutput;
    map { $strOutput .= "$_=".$href->{$_}."\n";} sort keys %$href;
    return $strOutput;
}

#****************************************************************************
# subroutine:  HashStringParser
# input:   1.HashStringGenerator's content 2. output:\%Hash
# output:  N/A
#****************************************************************************
sub HashStringParser
{
    my ($strHash, $Output_href)= @_;
    my @items = split(/\n/, $strHash);
    foreach my $item (@items)
    {
        my @KeyValue = split(/\=/, $item);
        my $key = $KeyValue[0];
        my $value = $KeyValue[1];
        $key =~ s/\s//;
        $value =~ s/\s//;
        $Output_href->{$key} = $value;
        $Output_href->{uc($key)} = $value;
    }
}

sub GetMBAligned
{
    my ($nSize, $nMBAligned) = @_;
    return ceil($nSize/($nMBAligned*1024*1024)) *$nMBAligned*1024*1024;
}

sub GetKBAligned
{
    my ($nSize, $nKBAligned) = @_;
    return ceil($nSize/($nKBAligned*1024)) *$nKBAligned*1024;
}
