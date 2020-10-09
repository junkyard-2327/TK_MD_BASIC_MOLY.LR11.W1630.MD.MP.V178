use File::Path;
use File::Basename;
use File::Copy;
use File::Copy::Recursive qw (fcopy rcopy dircopy fmove rmove dirmove);
use POSIX qw(strftime);

&usage() if $#ARGV ne 9;
my $debug = 0;

my $core_root       =  $ARGV[0];
my $build_folder    =  $ARGV[1];
my $mtk_rel         =  $ARGV[2];
my $modem_cfg       =  $ARGV[3];
my $gen_tools       =  $ARGV[4];
my $mddb            =  $ARGV[5];
my $customization   =  $ARGV[6];
my $filter_ini      =  $ARGV[7];
my $dsp_project     =  $ARGV[8];
my $dsp_flavor      =  $ARGV[9];

if ($core_root eq "l1core") {
	$mtk_rel =~ s/\/l1core//;
}
my $dsp_rel_xml = "$mtk_rel/dsp_rel/$dsp_project/$dsp_flavor/final_bin/xml";

print "CORE_ROOT              = $core_root\n"      if ($debug);
print "BUILD_FOLDER           = $build_folder\n"   if ($debug);
print "MTK_REL                = $mtk_rel\n"        if ($debug);
print "MODFM_CFG              = $modem_cfg\n"      if ($debug);
print "POST/CGEN_TOOL         = $gen_tools\n"      if ($debug);
print "DATABASE               = $mddb\n"           if ($debug);
print "CUSTOMIZATION_FOLDER   = $customization\n"  if ($debug);
print "FILTER_INI             = $filter_ini\n"     if ($debug);
print "DSP_PROJECT            = $dsp_project\n"    if ($debug);
print "DSP_FLAVOR             = $dsp_flavor\n"     if ($debug);

#=========================================================
# Check log2SD_Catcher_filters File and DSP dbf Existence
#=========================================================
my @ori_log2SD_list = glob "$customization/log2SD_Catcher_filters*";
print "log2SD_Catcher_filters = @ori_log2SD_list\n"   if ($debug);

my @ori_dsp_dbf = glob "$dsp_rel_xml/*.dbf";
print "DSP_DBF                = @ori_dsp_dbf\n"   if ($debug);

#=========================================================
# parsing postfix string from log2SD_Catcher_filters
#=========================================================
my @logsSD_list;
foreach my $file (@ori_log2SD_list) {
  if ($file =~ /log2SD_Catcher_filters_(\S+)\.ini/) {
    push(@logsSD_list,$1);
  }
}
print "log2SD_STRING          = @logsSD_list\n"   if ($debug);

#=========================================================
# parsing postfix string from dsp dbf
#=========================================================
my @dsp_dbf_list;
foreach my $dsp_file (@ori_dsp_dbf) {
  if ($dsp_file =~ /\/DSP_(\S+)\.dbf/) {
    if ($1 ne "Default") {
      push(@dsp_dbf_list,$1);
    }
  }
}
print "DSP_DBF_STRING         = @dsp_dbf_list\n"   if ($debug);

#=========================================================
# parsing mapping relationship from FilterSetting.ini
#=========================================================
if (-e $filter_ini) {
  open (FILE_HANDLE, "<$filter_ini") or die "cannot open $filter_ini\n";
  while (<FILE_HANDLE>) {
    if (/^(\S+)\s*=\s*(\S+)/) {
      $keyname = $1;
      $${keyname} = $2;
    }
  }
  close FILE_HANDLE;
}

#=========================================================
# print Catcher_filters and dbf file and merge to cgenModem.cfg
#=========================================================
if ($core_root eq "pcore") {
	if($#logsSD_list ne -1) {
	  open(my $fh, '>>', $modem_cfg) or die "Could not open file '$modem_cfg' $!";
	  foreach my $postfix (@logsSD_list) {
      print $fh "$gen_tools -filter_gen bin $mddb $customization/log2SD_Catcher_filters_$postfix.ini $build_folder/dhl/database/pcore_db/catcher_P_filter_$postfix.bin\n";
    }
    foreach my $dsp_postfix (@dsp_dbf_list) {
      print $fh "$gen_tools -dsp_filter_gen coresonic $mddb $dsp_rel_xml/DSP_$dsp_postfix.dbf $build_folder/dhl/database/pcore_db/dsp_filter_$dsp_postfix.bin\n";
    }
    
    foreach my $postfix (@logsSD_list) {
    	my $tmpINI = "log2SD_Catcher_filters_". $postfix .".ini";
    	my $tmpDspDbf = $$tmpINI;
    	if ($tmpDspDbf =~ /^DSP_(\S+)\.dbf/) {
        if ($1 eq "Default") {
          print $fh "$gen_tools -filter_merge $mddb $build_folder/dhl/database/pcore_db/catcher_P_filter_$postfix.bin $build_folder/dhl/database/dsp_filter.bin $build_folder/dhl/database/pcore_db/catcher_P_filter_$postfix.bin\n";
        }
        else {
    	    my $DspDbf = "dsp_filter_". $1 .".bin";
          print $fh "$gen_tools -filter_merge $mddb $build_folder/dhl/database/pcore_db/catcher_P_filter_$postfix.bin $build_folder/dhl/database/pcore_db/$DspDbf $build_folder/dhl/database/pcore_db/catcher_P_filter_$postfix.bin\n";
        }
      } 
      else {
      	print $fh "$gen_tools -filter_merge $mddb $build_folder/dhl/database/pcore_db/catcher_P_filter_$postfix.bin $build_folder/dhl/database/dsp_filter.bin $build_folder/dhl/database/pcore_db/catcher_P_filter_$postfix.bin\n";
      }
    }
    
    close $fh;
  }
}

if ($core_root eq "l1core") {
	if($#logsSD_list ne -1) {
	  open(my $fh, '>>', $modem_cfg) or die "Could not open file '$modem_cfg' $!";
	  foreach my $postfix (@logsSD_list) {
      print $fh "$gen_tools -filter_gen bin $mddb $customization/log2SD_Catcher_filters_$postfix.ini $build_folder/dhl/database/catcher_L_filter_$postfix.bin\n";
    }
    foreach my $dsp_postfix (@dsp_dbf_list) {
      print $fh "$gen_tools -dsp_filter_gen coresonic $mddb $dsp_rel_xml/DSP_$dsp_postfix.dbf $build_folder/dhl/database/dsp_filter_$dsp_postfix.bin\n";
    }
    
    foreach my $postfix (@logsSD_list) {
    	my $tmpINI = "log2SD_Catcher_filters_". $postfix .".ini";
    	my $tmpDspDbf = $$tmpINI;
    	if ($tmpDspDbf =~ /^DSP_(\S+)\.dbf/) {
        if ($1 eq "Default") {
          print $fh "$gen_tools -filter_merge $mddb $build_folder/dhl/database/catcher_L_filter_$postfix.bin $build_folder/dhl/database/dsp_filter.bin $build_folder/dhl/database/catcher_L_filter_$postfix.bin\n";
        }
        else {
    	    my $DspDbf = "dsp_filter_". $1 .".bin";
          print $fh "$gen_tools -filter_merge $mddb $build_folder/dhl/database/catcher_L_filter_$postfix.bin $build_folder/dhl/database/$DspDbf $build_folder/dhl/database/catcher_L_filter_$postfix.bin\n";
        }
      }
      else {
      	print $fh "$gen_tools -filter_merge $mddb $build_folder/dhl/database/catcher_L_filter_$postfix.bin $build_folder/dhl/database/dsp_filter.bin $build_folder/dhl/database/catcher_L_filter_$postfix.bin\n";
      }
    }
    
    close $fh;
  }
}

exit 0;

#=========================================================
# Return Result
#=========================================================
sub endWithError {
  my $error_msg = $_[0];
  print ("Error: $error_msg\n");
  exit -1;
}

#=========================================================
# Usage
#=========================================================
sub usage {
  print "Usage:\n";
  print "\tperl multi_catcher_filter.pl <PROJECT_NAME> <PROJECT_FLAVOR> <BUILD_FOLDER> <MTK_REL> <modem_cfg> <CGEN_TOOL>\n\n";
  my $error_msg = "multi_catcher_filter.pl Unsupport command.";
  &endWithError($error_msg);
}
