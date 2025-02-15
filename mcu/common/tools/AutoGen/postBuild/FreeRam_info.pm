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

use strict;
BEGIN { push @INC, './common/tools/MemoryUtility/' }  # add additional library path
use LinkerOutputParser;
use CommonUtility;
use FileInfoParser;

package FreeRam_info;


#****************************************************************************
# Constants
#*****************************************************************************
my $FREERAM_INFO_VERNO = " v0.03";
		# v0.03 , 2017/May/25, Carl Kao,       New Layout
		# v0.02 , 2015/12/22,  Tero Jarkko,    SWLA configuration change
		# v0.01 , 2015/12/02,  Tero Jarkko,    Initial version



my @symbol_list = (["PCORE_END",LinkerSymPostfix::Limit,0],
		   ["L1CORE_RWZI", LinkerSymPostfix::Base,0],
		   ["L1CORE_DUMP_REGION__DNC", LinkerSymPostfix::ZILimit,1],
		   ["SHARED_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW",LinkerSymPostfix::Base,1],
		   ["DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW", LinkerSymPostfix::ZILimit,2],
		   ["DUMMY_END", LinkerSymPostfix::Base,2]);

sub GetFreeRamInfo
  {
    my ($g_sym_file) = @_;
    my $g_area_begin = 0;
    my $g_area_end = 0;
    my $g_area_length = 0;
    my @freemem;

    LinkerOutputParser::FileParse($g_sym_file) if(-e $g_sym_file) or die("Can't open symbol file: $g_sym_file\n");

    for(my $i = 0 ; $i<6; $i = $i+2) {
      $g_area_begin = hex(LinkerOutputParser::GetLinkerSymbolAddress($symbol_list[$i][0],$symbol_list[$i][1], LinkerSymPrefix::Image));
      #Check if free region has SWLA area

      if($symbol_list[$i][2] != 0) {
	# Adjust SWLA area to 4KB
	$g_area_begin = ($g_area_begin+16+hex("fff") >> 12) << 12;
	$g_area_end = hex(LinkerOutputParser::GetLinkerSymbolAddress($symbol_list[$i+1][0],$symbol_list[$i+1][1], LinkerSymPrefix::Image));
	# Add SWLA area length
	my $swla_region_name = "";

	if($symbol_list[$i][2] == 1) {
	  $swla_region_name = "L1CORE_SWLA_REGION";
	} else {
	  $swla_region_name = "SWLA_REGION";
	}
	my $swla_size = hex(LinkerOutputParser::GetLinkerSymbolAddress($swla_region_name,LinkerSymPostfix::Length, LinkerSymPrefix::Image));
	if (($swla_size == hex("0xFFFFFFFF")) || (($swla_size+$g_area_begin) > $g_area_end)) {
	  $swla_size = $g_area_end - $g_area_begin;
	}
	$g_area_begin = $g_area_begin+$swla_size;
      }

      # Adjust Free area begin address to 64kB
      $g_area_begin = ($g_area_begin + hex("ffff") >> 16) << 16;
      $g_area_end = hex(LinkerOutputParser::GetLinkerSymbolAddress($symbol_list[$i+1][0],$symbol_list[$i+1][1],, LinkerSymPrefix::Image));
      # Adjust Free area end address to 64kB
      $g_area_end = ($g_area_end + hex("ffff") >> 16) << 16;
      # Calculate length
      $g_area_length = $g_area_end - $g_area_begin;

      if ($g_area_length > 0) {
	push @freemem,[$g_area_begin, $g_area_length];
      } else {
	push @freemem,[0,0];
      }

    }
    return @freemem;
  }
