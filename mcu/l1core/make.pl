#!/usr/bin/env perl
# 
# Copyright Statement:
# --------------------
# This software is protected by Copyright and the information contained
# herein is confidential. The software may not be copied and the information
# contained herein may not be used or disclosed except with the written
# permission of MediaTek Inc. (C) 2005
# 
# BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
# NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
# SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
# 
# BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
# LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
# 
# THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
# WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
# LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
# RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
# THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
# 

require v5.8.6;
use Cwd;
use File::Copy;
use File::Path;
#Carina#use if ($^O eq "MSWin32"), Win32API::Registry => qw(:ALL);

$ENV{"NUMBER_OF_PROCESSORS"} = `cat /proc/cpuinfo | grep 'processor' | wc -l | tr -d '\n'`;

# for mbis start stamp
$build_time_sec = time;
($sec, $min, $hour, $mday, $mon, $year) = localtime($build_time_sec);
$build_time_string = sprintf("%4.4d.%2.2d.%2.2d.%2.2d.%2.2d.%2.2d", $year+1900, $mon+1, $mday, $hour, $min, $sec);

$core_root = "l1core";
$plat = "";
@arguments = ();
$project = "";
$action = "";
$m_in_lsf = 0;
$local_q = 0;
@mOpts = ();
$fullOpts = "";
$level = "";
$relDir = "";
$relative_path = "./";
$ini = "$relative_path/build/make.ini";
$myMF = "build.mak";
$enINI = 1;
($#ARGV < 0) && &Usage;
(($#ARGV < 1) && ($enINI == 0)) && &Usage;

# Single Core
my $single_core = "FALSE";
if($ARGV[0] eq "single_core") {
  $single_core = "TRUE";
  shift @ARGV;
}

my $concatenate_proj_mak = "";
my $modisDir = "";
my $target_option = "";
my $chk_cmd = 0;
my $dsp_root = "l1core";
my $toolsFolder = "$dsp_root/tools/";
my $MTKtoolsFolder = "$dsp_root/mtk_tools/";
my $makeFolder = "make/l1core/";
my $projMakeFolder = "make/projects/";

$dummyvm = 0;
$disable_ib = 1;

#mbis default enable
$mbis = "$toolsFolder/mbis.pl";
$arg_mbis_en = "FALSE";
$arg_mbis_en_obj_log = "FALSE";
$arg_mbis_en_save_log = "FALSE";
$mbis_arg_exist = 0;
$mbis_en = "FALSE";
$mbis_en_obj_log = "FALSE";
$mbis_en_save_log = "FALSE";
@mbis_arg = ();
#$mbis_conf_file = "\\\\glbfs14\\sw_releases\\mbis\\scripts\\MBIS_conf.ini" if($^O eq "MSWin32");
$mbis_conf_file = "/mtkeda/wcpsm/mbis/config/mbis_conf.ini"; #if($^O eq "linux");
@orgARGVwithFlavor = ();
$mbis_num_proc = 0;
$mbis_target_build_with_Modis = 0;
@levels = qw(level2_src level2_obj level1 vendor);
@actions = qw(new update remake clean codegen nvram_auto_gen bootloader emiclean emigen sysgen sys_auto_gen sys_mem_gen ckmemlayout drv_feature_check c,r c,u scan check_scan check check_dep remake_dep update_dep clean_codegen slim_codegen slim_update genlog nvram_auto_gen genmoduleinfo gendummylis memquery master_info_gen update_share_buffer adjust_memconfig update_memconfig gendummysym);

@projects = qw(l1s gsm gprs basic umts hspa udvt tdd128 tdd128dpa tdd128hspa);
@orgARGV = @ARGV;
@orgARGVwithFlavor = @orgARGV;
$flavor = "DEFAULT";
$localq_disk = "z:";
#Carina#$OSversion = $^O;
$OSversion = "linux";

#Carina#if ($^O eq "MSWin32")
#Carina#{
#Carina#	$makeCmd = "tools/make.exe";
#Carina#}
#Carina#else
#Carina#{
	$makeCmd = "make";
#Carina#}

#$ENV{'mypath'}= $FindBin::Bin;

#Carina#if ($ENV{'MTK_INTERNAL'} eq 'TRUE') {
#Carina#	# MTK_INTERNAL is a internal environment flag
#Carina#} elsif (($ENV{'USERDOMAIN'} =~ /MTK|PMT|MBJ|MSZ|MTI|WISE|MEDIATEK|MWS|GCN|APJ/i) && ($ENV{'USERDNSDOMAIN'} =~ /MEDIATEK\.INC/i)) {
#Carina#	warn "Current user is from MTK internal, but the environment MTK_INTERNAL != TRUE\nPlease check ! Build script will continue after 30 sec.\n";
#Carina#	sleep 30;
#Carina#	$ENV{'MTK_INTERNAL'} = 'TRUE';
#Carina#}

#Carina#if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && (-e "mtk_tools/Internal_function.pm")) {
#Carina#	require mtk_tools::Internal_function;
#Carina#}
$no_pcibt = "FALSE";
$no_dsp = "FALSE";
$VarioationProj_name = "";


if($single_core eq "TRUE"){
  print "ENV REDIRECT_OUT_DIR = $ENV{'REDIRECT_OUT_DIR'}\n";
  print "OUT_DIR = $ENV{'OUT_DIR'}\n";

  if(($ENV{'REDIRECT_OUT_DIR'} eq 'TRUE') && (defined $ENV{'OUT_DIR'})){
	  print "Trigger CF TO LOCAL success\n";
	  print "Prepare to create OUT folder and link...\n";
	  system("mkdir -p $ENV{'OUT_DIR'}/build") if (!-d "$ENV{'OUT_DIR'}/build");
	  system("mkdir -p $ENV{'OUT_DIR'}/build_internal") if (!-d "$ENV{'OUT_DIR'}/build_internal");
	  system("ln -sf $ENV{'OUT_DIR'}/build build");
	  system("ln -sf $ENV{'OUT_DIR'}/build_internal build_internal");
	  print "Prepare to create OUT folder and link...Done\n";
  }
}

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /^(p|pl|pla|plat|platf|platfo|platfor|platform)=(\w+)/i) {
    $plat = $2;
  } elsif ($ARGV[0] =~ /^(c|cu|cus|cust|custo|custom)=(\w+)/i) {
    $custom = $2;
  } elsif ($ARGV[0] =~ /-dummyvm/i) {
    $dummyvm = 1;
  } elsif ($ARGV[0] =~ /-release/i) {
    $modisDir = "Release";
  } elsif ($ARGV[0] =~ /-debug/i) {
    $modisDir = "Debug";
  } elsif ($ARGV[0] =~ /-h/i) {
    &Usage;
  } elsif ($ARGV[0] =~ /^-(o|op|opt)=(.*)$/i) {
    $fullOpts = "CMD_ARGU=$2";
    @mOpts = split(",", $2);
  } elsif ($ARGV[0] =~ /-lsf/i) {
    $m_in_lsf = 1;
  } elsif ($ARGV[0] =~ /-no_lsf/i) {
    $not_enter_lsf = 1;
  } elsif ($ARGV[0] =~ /-localq/i) {
    $local_q = 1;
  } elsif ($ARGV[0] =~ /-localpath/i) {
    $local_p = 1;
  } elsif ($ARGV[0] =~ /-disable_ib/i) {
    $disable_ib = 1;
  } elsif ($ARGV[0] =~ /-no_ib/i) {
    $disable_ib = 1;
  } elsif ($ARGV[0] =~ /-bm/i) {
    $disable_ib = 1;
  } elsif ($ARGV[0] =~ /-klocwork/i) {
    $RUN_KLOCWORK = 1;
  } elsif ($ARGV[0] =~ /-disk=(.*)/i) {
    $localq_disk = $1;
  } elsif ($ARGV[0] =~ /-chkcmd/i) {
    $chk_cmd = 1;
  }elsif ($ARGV[0] =~ /^-mbis=(.*)$/i) {
    # mbis get argument
    @mbis_arg = split(",", $1);
    &mbis_parse_arg;
  } elsif ($ARGV[0] =~ /-no_cgen/i) {
    $target_option .= " REMAKE_WITH_CGEN=FALSE";
  } elsif ($ARGV[0] =~ /-bulk/i) {
    $target_option .= " BULK=TRUE";
  }
  elsif ($ARGV[0] =~ /(-no_dsp)\b/i) {
    $no_dsp = "TRUE";
  }
  #Add for daily build
  elsif ($ARGV[0] =~ /-dbld/i) {
    $daily_build = 1;
  } elsif ($ARGV[0] =~ /(-no_pcibt|-no_pc)\b/i) {
    $no_pcibt = "TRUE";
  } elsif($ARGV[0] =~ /^-test=(.*)$/i){
     $VarioationProj_name = $1;
     $VarioationProj_fullPath = "make/common/variation/${VarioationProj_name}.mak";
     &cktheMF($VarioationProj_fullPath);
  } else {
    foreach $m (@projects) {
    	print "DEBUG: $ARGV[0], $ARGV[1]\n" if ($debug == 1);
      if (lc($ARGV[0]) eq $m) {
        $project = uc($m);
        $project_makefile = uc("${custom}_${project}");
        shift(@ARGV);
        last;
      } elsif (lc($ARGV[1]) eq $m) {
        $project = uc($m);
        $custom = $ARGV[0];
        $project_makefile = uc("${custom}_${project}");
        shift(@ARGV);
        shift(@ARGV);
        last;
      }
    }

    #if (($project eq "") && ($enINI == 1) && (-e $ini)) {
    #  open (FILE_HANDLE, "<$ini") or die "cannot open $ini\n";
    #  while (<FILE_HANDLE>) {
    #    if (/^(\S+)\s*=\s*(\S+)/) {
    #      $keyname = $1;
    #      $${keyname} = $2;
    #    }
    #  }
    #  close FILE_HANDLE;
    #  print "custom=$custom; FLAVOR=$flavor; project=$project\n";
    #  $custom = $custom."($flavor)";
    #}
    if ($custom =~ /^(\w+)\((\w+)\)$/i) # match <custom>(<flavor>)=>SUPERMAN29_DEMO(FLAVOR)
    {
        $custom = uc($1);
        $flavor = uc($2);
        $project_makefile = "${custom}_${project}($flavor)";
        writeMakeINI();
    }
    if($ARGV[0] =~ /(.+)\.mak/i){
      $project_makefile = uc($1);
      writeMakeINI();
      shift(@ARGV);
    }   
    if (($project_makefile eq "") && ($enINI == 1) && (-e $ini)) {
      open (FILE_HANDLE, "<$ini") or die "cannot open $ini\n";
      while (<FILE_HANDLE>) {
        if (/^(\S+)\s*=\s*(\S+)/) {
          $keyname = $1;
          $${keyname} = $2;
        }
      }
      print "project_makefile=$project_makefile\n";
      close FILE_HANDLE;
    }

    if($project_makefile =~ /\W/){
      ($project_name,$flavor) = split (/\W/, $project_makefile);
    }
    else
    {
      $project_name = $project_makefile;
    }
    print "project_name = $project_name\n";
    print "flavor = $flavor\n";
    ($project_makefile eq "") && (die "Unrecognized \"$ARGV[0]\" or \"$ARGV[1]\"\nOr try $myCmd -h\n");

    if ($#ARGV != -1) {
      if ($ARGV[0] =~ /^[ucrUCR]$/) {
        ($action = "clean") if ($ARGV[0] =~ /^[cC]$/);
        ($action = "update") if ($ARGV[0] =~ /^[uU]$/);
        ($action = "remake") if ($ARGV[0] =~ /^[rR]$/);
        shift(@ARGV);
        @arguments = @ARGV;
        @ARGV = ();
        last;
      } else {
        #if ($ENV{'MTK_INTERNAL'} eq 'TRUE')
        #{
          unshift(@actions, "bm_new", "notify","warn_notify", "cq_notify", "err_out", "db_notify",  "db_modis_notify", "bm_remake", "bm_update", "patch", "patch_hal", "find", "rm_cleanroom", "ckmake", "gendoc");
          unshift(@actions, "cmmgen");
          unshift(@actions, "cfggen","ckmemlayout2");
        #}
        foreach $act (@actions) {
          if (lc($ARGV[0]) eq $act) {
            $action = $act;
            if (($act eq "bm_update") || ($act eq "bm_remake")) {
              ($action = "update") if ($act eq "bm_update");
              ($action = "remake") if ($act eq "bm_remake");
              ($fullOpts eq "") ? ($fullOpts = "CMD_ARGU=-k") : ($fullOpts .= ",-k");
              push(@mOpts, "-k");
            }
            shift(@ARGV);
            @arguments = @ARGV;
            @ARGV = ();
            last;
          }
        }
      }
    }
    ($action eq "") && (die "Unrecognized \"$ARGV[0]\"\nLack off one of (@actions)\nOr try $myCmd -h\n");
    ($#ARGV != -1) && (die "Unrecognized \"@ARGV\"\nPlease check again or try $myCmd -h\n");
    if ($action eq "rel" || $action eq "ckcr" || $action eq "rel_modis") {
      $relDir = $arguments[0];
      shift(@arguments);
      ($#arguments == -1) && die "Lack off release level(@levels).\nOr try $myCmd -h\n";
      foreach $arg (@levels) {
        if (lc($arguments[0]) eq $arg) {
          $level = $arg;
          shift(@arguments);
          last;
        }
      }
      ($level eq "") && die "Lack off release level(@levels).\nOr try $myCmd -h\n";
      ($#arguments != -1) && (warn "Unrecognized \"@arguments\"\n");
    }
    if ($action eq "removecode") {
      $remove_dir = $arguments[0];
    }
    last;
  }
  shift(@ARGV);
}
(!-d "make")&&(die "Folder \"make\" does NOT exist!\nPlease help to check.\n");

if($single_core eq "TRUE"){
  if(($ENV{'REDIRECT_OUT_DIR'} eq 'TRUE') && (defined $ENV{'OUT_DIR'})){
	  $hostname = `hostname`;
	  system("perl -e \"print \'COMPUTERNAME=$hostname\';\" > \"${project_makefile}_cf.log\"");
  }
}

if ($action =~ /^(bm_new|bm_update|bm_remake)$/i)
{
  $ENV{"PCIBT_NO_STOP"} = "TRUE";
}

if ((-e "$MTKtoolsFolder/Perl") && ($] >= 5.008006)){
	use lib "$MTKtoolsFolder/Perl";
	use Net::SMTP;
}

if (($local_q == 1) && ($local_p != 1)) {
  chomp(my $cwd = cwd());
  $cwd =~ s/\//\\/g;
  system("subst $localq_disk $cwd");
  chdir("$localq_disk");
  print "cwd = $cwd\n";
}

chomp($cwd = cwd());
if ($cwd =~ /\s+/)
{
  $arrow = $cwd;
  $arrow =~ s/\s/\^/g;
  $arrow =~ s/[^\^]/ /g;
  print "\n$cwd\n";
  print "$arrow\n";
  print "Space is not a legal character for a folder name.\nPlease check it !!\n";
  exit 1;
}

sub cktheMF
{
  $the_makefile = $_[0];
  (!-e $the_makefile) && (die "$the_makefile does NOT exist!\nPlease help to check.\n");
  open (FILE_HANDLE, "<$the_makefile") or die "Cannot open $the_makefile. Please check if the file is READ-ONLY or not exists.\n";
  while (<FILE_HANDLE>){
    if (/^(\w+)\b\s*=\s*(\S+)/) {
      $keyname = lc($1);
      $${keyname} = uc($2);
    }
  }
  close FILE_HANDLE;
  return 0;
}

if ($VarioationProj_name ne "") {
  &cktheMF($VarioationProj_fullPath);
}

my $copro_folder = "l1core";
$projectFolder = "$relative_path"."build/".uc "${project_name}"."/$flavor";
$projectFolder .= "/$copro_folder"; 
if ($chk_cmd == 1) 
{
print "\n$projectFolder\n";
exit 0;
}
$original_projectFolder = $projectFolder;
writeMakeINI();
$tmpFolder = "$projectFolder/tmp";
if ($action =~ /_(modis|uesim)$/i)
{
	($projectFolder, $tmpFolder) = &MoDIS_xgen_check($action);
}
$targetFolder = "$projectFolder/bin";
$logFolder = "$targetFolder/log";

# delete temp. files in make folder before executing build command
$plat = "NONE";
$enFile = "${makeFolder}${project_name}_en.def";
$disFile = "${makeFolder}${project_name}_dis.def";
$theVerno = "make/common/Verno.bld";
$ori_prj_make_full_path = "${projMakeFolder}${project_makefile}.mak";
$theMF = $ori_prj_make_full_path;
&cktheMF($theMF);
if(defined $project_makefile_ext && $project_makefile_ext ne "NONE"){
	$theMF_ext = "${projMakeFolder}/custom_config/${project_makefile_ext}.mak";
	&cktheMF($theMF_ext);
}

print "clean $tmpFolder/*.*\n";
my @delTempFile = glob("$tmpFolder/*.*");
unlink(@delTempFile) or die "[make.pl][Error:] Remove failed @delTempFile $!" if(@delTempFile);
mkpath($tmpFolder) or die "[make.pl][Error:] Can Not create $tmpFolder! $!" if(!-d "$tmpFolder");
mkpath($logFolder) or die "[make.pl][Error:] Can Not create $logFolder! $!" if(!-d "$logFolder");
mkpath($targetFolder) or die "[make.pl][Error:] Can Not create $targetFolder! $!" if(!-d "$targetFolder");

# generate custom.bld
&genCustombld();

# smybol link to central tool chain if it's in MTK_INTERNAL
if(!-l "./common/tools/GCC/4.9.3/linux" && !-d "./common/tools/GCC/4.9.3/linux" && -d "/mtkoss/linaro/gcc-arm-none-eabi/4.9.3/linux")
{
  system("ln -s /mtkoss/linaro/gcc-arm-none-eabi/4.9.3/linux ./common/tools/GCC/4.9.3");
}

# concatenate the project makefiles and the result is placed on build/$project/$flavorn/bin.
# In here, the gen_concatenate_proj target does NOT do PCIBT.
$concatenate_proj_mak = "${targetFolder}/~${project_makefile}.mak";
my $gen_concate_option = "";
if ($action =~ /_(modis|uesim)$/i) {
	# $target_option is set in MoDIS_xgen_check;
	$gen_concate_option = $target_option . " MODIS_CONFIG=TRUE";
}
$gen_concate_option = $gen_concate_option . " NO_PCIBT=TRUE MBIS_EN=FALSE";
if ($action =~ /new/i and -e "$concatenate_proj_mak") {
	unlink($concatenate_proj_mak) or die "[make.pl][Error:] Remove failed $concatenate_proj_mak $!";
}
print "${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor \"VARIATION_PROJ=$VarioationProj_name\" CORE_ROOT=$core_root $gen_concate_option gen_concatenate_proj\n";
my $return_code = system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CORE_ROOT=$core_root \"VARIATION_PROJ=$VarioationProj_name\" $gen_concate_option gen_concatenate_proj");
die "Error: concatenate project makefiles failed." if(($return_code >> 8) ne 0);
(!-e $concatenate_proj_mak) && (die "$concatenate_proj_mak does NOT exist!\nPlease help to check.\n");
print "concatenate_proj_mak = $concatenate_proj_mak\n";

$theMF = $concatenate_proj_mak;
&cktheMF($theMF);
exit 0 if($action eq "getusr");

# for initial mbis config 
&mbis_init;
&mbis_start_probe;
# mbis options
system("echo MBIS_EN=$mbis_en >> $tmpFolder/~buildinfo.tmp");
system("echo MBIS_EN_OBJ_LOG=$mbis_en_obj_log >> $tmpFolder/~buildinfo.tmp");
system("echo VARIATION_PROJ=$VarioationProj_name >> $tmpFolder/~buildinfo.tmp");
system("echo NO_PCIBT=$no_pcibt >> $tmpFolder/~buildinfo.tmp");
system("echo NO_DSP=$no_dsp >> $tmpFolder/~buildinfo.tmp");

if (($action ne "ckmake") && ($action ne "drv_feature_check")) {
  if ($m_in_lsf != 1) {
    # Before executing actions, dump environment information to the build.log
    if(-e "./SubReleaseConfig.ini")
    {
      print "copy ./SubReleaseConfig.ini $targetFolder";
      #copy("./SubReleaseConfig.ini $targetFolder");
    }
    system("echo USERNAME=$ENV{'USERNAME'} > $targetFolder/build.log");
    system("perl -e \"print \'START TIME=\';\" >> $targetFolder/build.log");
    system("perl $toolsFolder/time.pl -n >> $targetFolder/build.log");
  }
}

(!-e $theMF) && (die "$theMF does NOT exist!\nPlease help to check.\n");
  open (FILE_HANDLE, "<$theMF") or die "Cannot open $theMF. Please check if the file is READ-ONLY or not exists.\n";
  while (<FILE_HANDLE>){
    if (/^(\w+)\b\s*=\s*(\S+)/) {
      $keyname = lc($1);
      $${keyname} = uc($2);
    }
  }
  close FILE_HANDLE;

if(-e $theVerno)
{
  open (FILE_HANDLE, "<$theVerno") or die "cannot open $theVerno\n";
  while (<FILE_HANDLE>) {
    if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/)) {
      $keyname = lc($1);
      $${keyname} = uc($2);
    }
  }
  close FILE_HANDLE;
}

die "Please define VERNO in project makefile or $theVerno." if($verno eq "");
if ($verno =~ /\s+/) {
  $arrow = $verno;
  $arrow =~ s/\s/\^/g;
  $arrow =~ s/[^\^]/ /g;
  print "\n$verno\n";
  print "$arrow\n";
  print "Space is not a legal character for VERNO name.\nPlease check it !!\n\n";
  exit 1;
}

# Get custom_release value
  open (FILE_HANDLE, "<$makeFolder/Custom.bld") or die "Cannot open make/Custom.bld\n";
  while (<FILE_HANDLE>) {
    if (/^(\S+)\s*=\s*(\S+)/) {
      $keyname = lc($1);
      if(defined($${keyname}) && $${keyname} ne ""){
        next;
      }
      #defined($${keyname}) && warn "$1 redefined in $thefile!\n";
      $${keyname} = uc($2);
    }
  }
  close FILE_HANDLE;

# To check if FLAVOR length is less than 36 bytes
die "ERROR: FLAVOR name should be less than 36 characters.\n" if(length($flavor)>36);
die "ERROR: ORIGINAL_PROJECT_NAME name should be less than 128 characters.\n" if(length($original_project_name)>128);
die "ERROR: ORIGINAL_FLAVOR name should be less than 36 characters.\n" if(length($original_flavor)>36);
die "ERROR: ORIGINAL_VERNO name should be less than 64 characters.\n" if(defined $original_verno && length($original_verno)>64);

#Carina#if ($^O ne "MSWin32")
#Carina#{
  @tools_Dirs = qw(l1core/tools/);
#Carina#}
#Carina#else
#Carina#{
#Carina#  @tools_Dirs = qw(tools/ tools/MinGW tools/MSYS);
#Carina#}


push (@tools_file,$makeCmd);
if ($ENV{'MTK_INTERNAL'} eq 'TRUE')
{
  $VerCmd = "$makeFolder/verifyCus.mak";
  push (@tools_file,$VerCmd);
}

foreach $tools_Dirs (@tools_Dirs)
{
  if (!-d $tools_Dirs)
  {
    warn "$tools_Dirs folder does NOT exist!\n";
    #Carina#&cp_3rdpartyTool;
  }
}

foreach $tools_file (@tools_file)
{
  if (!-e $tools_file)
  {
    warn "$tools_file does NOT exist!\n";
    #Carina#&cp_3rdpartyTool;
  }
}

my $no_of_proc=1;

  if ($ENV{"NUMBER_OF_PROCESSORS"} > 1) {
      $PROCESS_NUM = $ENV{"NUMBER_OF_PROCESSORS"};
      $license_num = -1;
      # Check if license number is enough.
#KK#      if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && ($compiler ne "GCC")) {
#KK#        if (!-e "$LICENSE_FILE") {
#KK#          $license_num += 1;
#KK#          system ("lmutil lmstat -f compiler>$logFolder/license.log 2>$logFolder/license.log");
#KK#          open (FILE_HANDLE, "$logFolder/license.log");
#KK#          while (<FILE_HANDLE>) {
#KK#            if ($_ =~ /.+ (\d+) licenses .+ (\d+) .+/) {
#KK#              $license_num = $license_num + $1 - $2;
#KK#            }
#KK#          }
#KK#          close(FILE_HANDLE);
#KK#        }
#KK#        if (($license_num > 0) && ($license_num < $PROCESS_NUM)) {
#KK#          $PROCESS_NUM = ($license_num%2) ? int($license_num/2)+1 : int($license_num/2);
#KK#        }
#KK#      }

      if ($fullOpts eq "") {
        $fullOpts = "CMD_ARGU=-j$PROCESS_NUM";
      } else {
        $fullOpts .= ",-j$PROCESS_NUM";
      }

      if ($mbis_en eq "TRUE")
      {
        $mbis_num_proc = $PROCESS_NUM;
      }
  }


if ($fullOpts ne "") {
# Fix build errors when "parallel jobs processing" fuction enabled by argument "-o|-op|-opt" in command line
  my @temp = @mOpts;
  @mOpts = ();
  foreach (@temp)
  {
    if ($_ =~ /^\s*(-j|--jobs)/)
    {
      $fullOpts .= ",$_";
    }
    else
    {
      push(@mOpts,$_);
    }
  }
# End
  $fullOpts =~ s/"/\\"/g;
# $fullOpts = "\"$fullOpts\"";
  $fullOpts =~ s/,/ /g;
# $makeCmd .= " " . join(" ", @mOpts) . " $fullOpts ";
  $makeCmd .= " " . join(" ", @mOpts);
}


if ($m_in_lsf == 1) {
  die "NOT IN LSF SERVER!\n" if ($ENV{"LS_ADMINNAME"} eq "");
  $computerName = $ENV{"COMPUTERNAME"};
  if ($local_q != 1) {
    system("echo set LAST_SUBMITTED_CF=$computerName >  build/last_cf.log");
    $ENV{"TMP"} = "e:\\temp";
    $ENV{"TEMP"} = "e:\\temp";
    mkdir("e:/temp") if (!-d "e:/temp");
  }
  $ENV{"INLSF"} = $computerName;
}

#run flavor_conf.pl
if ($demo_project eq "TRUE") {
  print ("perl $makeFolder/flavor_conf.pl \"$theMF\" $original_flavor $tmpFolder/cus_folder.tmp\n");
  $fla_rel = system("perl $makeFolder/flavor_conf.pl \"$theMF\" $original_flavor $tmpFolder/cus_folder.tmp> $logFolder/flavor_conf.log 2>&1");
  die "\nError: $makeFolder/flavor_conf.pl failed, please check error message in $logFolder/flavor_conf.log\n" if($fla_rel);
}

# Check if the node-locked license still works.
#Carina#$LICENSE_FILE = $BM_conf{'NODELOCKED_LICENSE'}->{'LICENSE_FILE'};
#Carina#$ARM_COMPILER = $BM_conf{'NODELOCKED_LICENSE'}->{'ARM_COMPILER'};
#Carina#$nodelock_fail = 0;

#Carina#if($compiler ne "GCC"){
#Carina#	if (-e "$logFolder/license_check.log") {
#Carina#		unlink("$logFolder/license_check.log") or die "Remove failed $!";
#Carina#	}
#Carina#	if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && ($ENV{"USERDOMAIN"} =~ /MTK/i) && (-e "$LICENSE_FILE")) {
#Carina#		$orig_ARMLMD_LICENSE_FILE = $ENV{"ARMLMD_LICENSE_FILE"};
#Carina#		$ENV{"ARMLMD_LICENSE_FILE"} = $LICENSE_FILE;
#Carina#		system("$ARM_COMPILER 2>$logFolder/license_check.log");
#Carina#		open(license_check_file, "<$logFolder/license_check.log") or die "Cannot open $logFolder/license_check.log";
#Carina#		$backup = $/; undef $/;
#Carina#		$log_content = <license_check_file>;
#Carina#		$/ = $backup;
#Carina#		if ($log_content =~ /FLEXlm error:/i) {
#Carina#			$nodelock_fail = 1;
#Carina#		}
#Carina#		close(license_check_file);
#Carina#
#Carina#		if ($nodelock_fail == 1) {
#Carina#			$email_list = $BM_conf{'NODELOCKED_LICENSE'}->{'MAIL_LIST'};
#Carina#			$smtp = Net::SMTP->new('smtp.mediatek.inc');
#Carina#			$smtp->mail($curr_usr);
#Carina#			map { $smtp->recipient($_); } split(/,/, $email_list);
#Carina#			$smtp->data();
#Carina#			$smtp->datasend("Subject:[ERROR: Nodelocked License Failed on $ENV{COMPUTERNAME}].\n");
#Carina#			$smtp->datasend("$log_content\n\n");
#Carina#			$smtp->quit;
#Carina#			system("echo ERROR: Nodelocked License Failed on $ENV{COMPUTERNAME} >> $logFolder/license_check.log");
#Carina#		} else {
#Carina#			system("echo License Check Successfully on COMPUTERNAME=$ENV{COMPUTERNAME} > $logFolder/license_check.log");
#Carina#		}
#Carina#		$ENV{"ARMLMD_LICENSE_FILE"}=$orig_ARMLMD_LICENSE_FILE;
#Carina#	}
#Carina#}

if ($ENV{COMPUTERNAME} =~ /mtks(cf|ib)/i) {
  $m_in_lsf = 1;
}

if (($m_in_lsf == 0) && ($not_enter_lsf != 1))
{
  if ($action =~ /^(bm_new|bm_update|bm_remake)$/i)
  {
    system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CORE_ROOT=$core_root drv_feature_check") && exit 1;
  }
  if (($action =~ /new/i) && ($action !~ /new_viti/i) && ($ENV{"SESSIONNAME"} ne "") &&
    ($ENV{"LSF_BINDIR"} ne "") && ($project !~ /BASIC/i) && ($project !~ /L1S/i) && ($project !~ /UDVT/i) && ($ENV{'MTK_INTERNAL'} eq 'TRUE')) {

    chomp($cwd = cwd());
    if ($cwd =~ /^[abg-z]/i) {
      #Carina#&pre_gen();
      $env_last_S_CF = "";
      $lastSC = "build/last_cf.log";
      if ((-e $lastSC) && (open(LOGF, "${lastSC}"))) {
        while (<LOGF>) {
          if (/set LAST_SUBMITTED_CF=(\S+)/) {
            $env_last_S_CF = $1;
            last;
          }
        }
        close(LOGF);
      }
#    $ENV{"NUMBER_OF_PROCESSORS"} = 1;
      if ($mbis_en eq "TRUE")
      {
        $mbis_time = time;
        system("echo T_S,DISPATCH_CF,P,$mbis_time >>$ENV{MBIS_BUILD_TIME_TMP}");
      }
      my $result = 0;
      if ($env_last_S_CF eq "") {
         $result = system("bsub -I \"perl $net_path\\m_cp2lsf.pl\" \"$net_path\" @orgARGV");
      } else {
        if (($output = `bhosts ${env_last_S_CF} mtkcf 2>&1`) =~ / Bad host name, host group name or cluster name/)
        {
          $result = system("bsub -I \"perl $net_path\\m_cp2lsf.pl\" \"$net_path\" @orgARGV");
        }
        else
        {
          $result = system("bsub -I -m \"${env_last_S_CF}+2 mtkcf+1\" \"perl $net_path\\m_cp2lsf.pl\" \"$net_path\" @orgARGV");
        }
      }
      &writeINI;
      exit $result >> 8;
    } else {
      # make new in local E: driver
      if (($ENV{"SESSIONNAME"} ne "") && ($ENV{"LSF_BINDIR"} ne "") && ($compiler eq "RVCT") && ($ENV{'MTK_INTERNAL'} eq 'TRUE')) {
        &localq;
      }
    }
  } else {
    if ($action !~ /ckmake|check|notify|patch|patch_hal|modis|uesim|sysgen|sys_auto_gen|emigen|nvram_auto_gen|find|rel|cmmgen|removecode|ckcr|elfpatch|codegen|gendsp|viewlog|genmoduleinfo|gen_bt_switch_info|viti|memquery/ig) {
      if (($ENV{"SESSIONNAME"} ne "") && ($ENV{"LSF_BINDIR"} ne "") && ($compiler eq "RVCT") && ($ENV{'MTK_INTERNAL'} eq 'TRUE')) {
        $local_path = "";
        $current_path=Win32::GetCwd();
        if($current_path=~/^([A-CG-Z]:)(.*)/i)
        {
          my $tmp_string1=$1;
          my $tmp_string2=$2;
          my @tmp_str2=`net use $tmp_string1`;
          my ($tmp_str3)=($tmp_str2[1]=~/\s+(\\\\.*)\s*$/);
          $net_path = lc("\\\\".$ENV{"COMPUTERNAME"}."\\E\\home");
          $tmp_str3=lc($tmp_str3);
          if ($tmp_str3 eq $net_path) {
            $local_path = "E:\\home\\$tmp_string2";
            chdir("E:\\home\\$tmp_string2");
          }
        }
        if ($local_path ne "") {
          &localq($local_path);
        }else{
          &localq();
        }
      }
    }
  }
}

if ($action eq "c,r") {
	@theAct = qw(clean remake);
} elsif ($action eq "c,u") {
	@theAct = qw(clean update);
} elsif ($action eq "c,r_modis") {
	@theAct = ("clean_modis remake_modis");
} elsif ($action eq "c,u_modis") {
	@theAct = ("clean_modis update_modis");
} else {
	@theAct = ($action);
}

if (($action ne "ckmake") && ($action ne "drv_feature_check")) {
  # Before executing actions, dump environment information to the build.log
  if(-e "./SubReleaseConfig.ini")
  {
    print "copy ./SubReleaseConfig.ini $targetFolder";
    copy("./SubReleaseConfig.ini", $targetFolder);
  }
  system("perl -e \"print \'BUILD START TIME=\';\" >> $targetFolder/build.log");
  system("perl $toolsFolder/time.pl -n >> $targetFolder/build.log");
  system("echo NUMBER_OF_PROCESSORS=$ENV{\"NUMBER_OF_PROCESSORS\"} >>$targetFolder/build.log");
  &mbis_info_probe;
}

# check current working folder length
# if it is too long, it will cause build error. The max length is defined 90 characters.
chomp($cwd = cwd());
$len = length($cwd);
$folder_limit = 90;
#Carina#if($^O eq "MSWin32" && $len > $folder_limit)
#Carina#{
#Carina#	if ($cwd =~ /.+\\(.+)/) {
#Carina#		$folder_name = $1;
#Carina#	}
#Carina#	print "Folder: $cwd\n";
#Carina#	print "Error: The folder length from $folder_name($len characters) exceeds $folder_limit characters. Please reduce folder lengths!\n";
#Carina#	exit 1;
#Carina#}

# notify error setting
# mtkeda folder is a tools sharefolder on Linux
my $mtkeda_wcpsm_folder = "/mtkeda/wcpsm";
my $error_notify_path;
$error_notify_path = "${mtkeda_wcpsm_folder}/error_notify/" if($^O eq "linux");
$error_notify_path = "\\\\mtkrs12\\Software_Management_Material\\Script\\Error_Notify\\" if($^O eq "MSWin32");
my $notify_err_pl = "${error_notify_path}notify_err.pl";

my $result = 0;
my %saw;
@theAct = grep (!$saw{$_}++, @theAct);
foreach my $action (@theAct) {
  $ENV{"ACTION"} = $action;
  if ($action ne "ckcr") {
	if (open FILE_HANDLE, ">$tmpFolder/~buildinfo.tmp")
	{
		my $timeStr = &CurrTimeStr;
		my $dbg_timeStr = $timeStr;
		$dbg_timeStr =~ s/ /_/g;
		$dbg_timeStr =~ s/:/_/g;
		$dbg_timeStr =~ s/\//_/g;
		print FILE_HANDLE "PROJECT_NAME=$project_name\n";
		print FILE_HANDLE "FLAVOR=$flavor\n";
		print FILE_HANDLE "APLAT=$plat\n";
		print FILE_HANDLE "$fullOpts\n";
		print FILE_HANDLE "BUILD_DATE_TIME=$timeStr\n";
		# mbis options
		print FILE_HANDLE "MBIS_EN=$mbis_en\n";
		print FILE_HANDLE "MBIS_EN_OBJ_LOG=$mbis_en_obj_log\n";
		print FILE_HANDLE "DBG_BUILD_DATE_TIME=$dbg_timeStr\n";
		print FILE_HANDLE "NO_PCIBT=$no_pcibt\n";
		print FILE_HANDLE "NO_DSP=$no_dsp\n";
    print FILE_HANDLE "VARIATION_PROJ=$VarioationProj_name\n";
		close FILE_HANDLE;
	}
	else
	{
		warn "Fail to write $tmpFolder/~buildinfo.tmp: $!\n";
	}
  }

  if ($action eq "clean") {
    if ($#arguments != -1) {
      system("echo DO_CLEAN_MODULE=TRUE > $tmpFolder/~cleanmod.tmp");
      system("echo CLEAN_MODS=@arguments >> $tmpFolder/~cleanmod.tmp");
      system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CORE_ROOT=$core_root cleanmod");
    } else {
      system("echo DO_CLEAN_MODULE=FALSE > $tmpFolder/~cleanmod.tmp");
      system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CORE_ROOT=$core_root cleanall");
    }
  } elsif (($action eq "remake") || ($action =~ /\b(remake)_(modis|uesim)\b/)) {
    if ($#arguments != -1) {
      system("echo DO_REMAKE_MODULE=TRUE > $tmpFolder/~remakemod.tmp");
      system("echo REMAKE_MODS=@arguments >> $tmpFolder/~remakemod.tmp");
    }
  } elsif (($action eq "update") || ($action =~ /\b(gen|update)_(modis|uesim)\b/)) {
    if ($#arguments != -1) {
      system("echo DO_UPDATE_MODULE=TRUE > $tmpFolder/~updatemod.tmp");
      system("echo UPDATE_MODS=@arguments >> $tmpFolder/~updatemod.tmp");
    }
  } elsif (($action eq "scan") || ($action =~ /\b(scan)_(modis|uesim)\b/)) {
    if ($#arguments != -1) {
      system("echo DO_SCAN_MODULE=TRUE > $tmpFolder/~scanmod.tmp");
      system("echo SCAN_MODS=@arguments >> $tmpFolder/~scanmod.tmp");
    }
  } elsif (($action eq "new") || ($action eq "bm_new") || ($action eq "codegen") || ($action =~ /_(modis|uesim)\b/)) {    
    # empty here to run through BT switch
  } elsif ($action eq "check_scan") {
    if ($#arguments != -1) {
      system("echo DO_SCAN_MODULE=TRUE > $tmpFolder/~scanmod.tmp");
      system("echo SCAN_MODS=@arguments >> $tmpFolder/~scanmod.tmp");
    }
    system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CHECK_SCAN=TRUE CORE_ROOT=$core_root scan");
  } elsif ($action eq "check") {
    system("perl ${toolsFolder}parse_comp_err.pl ${project_name}/$flavor FALSE $tmpFolder TRUE");
  } elsif ($action eq "notify") {
    system("perl ${notify_err_pl} bm_notify");
  } elsif ($action eq "warn_notify") {
    system("perl ${notify_err_pl} warn_notify");
  } elsif ($action eq "cq_notify") {
    system("perl ${notify_err_pl} cq_notify");  
  } elsif ($action eq "err_out") {
    system("perl ${notify_err_pl} err_out");
  } elsif ($action eq "db_notify") {
    system("perl ${notify_err_pl} db_notify");
  } elsif ($action eq "db_modis_notify") {
    system("perl ${notify_err_pl} db_modis_notify");
  } elsif ($action eq "patch") {
    system("perl ${MTKtoolsFolder}patch_file.pl @arguments");
  } elsif ($action eq "patch_hal") {
    system("perl ${MTKtoolsFolder}patch_tool_HAL.pl $project_name @arguments");
  } elsif ($action eq "find") {
    system("cqperl ${MTKtoolsFolder}find_file.pl $theMF $theVerno @arguments");
  } elsif ($action eq "rm_cleanroom") {
    &rm_cleanroom();
  } elsif ($action eq "check_dep") {
    	&Usage if (!@arguments);
    	&writeINI;
    	system("perl $toolsFolder/GetDepMod.pl ./ \"$theMF\" $project_name $flavor @arguments") && exit 1;
    	exit 0;
  } elsif ($action =~ /update_dep|remake_dep/i) {
    	&Usage if (!@arguments);
    	print "Scanning dependency modules...\n";
    	my $output;
    	if (($output = `perl $toolsFolder/GetDepMod.pl ./ \"$theMF\" $project_name $flavor @arguments 2>&1`) =~ /=+DEPENDENCY MODULE\(S\)=+\n(.*)\n/)
    	{
    		@arguments = split(/\s+/,$1);
    		$action = "update" if ($action eq "update_dep");
    		$action = "remake" if ($action eq "remake_dep");
    		print "The following module(s) will be rebuilt!\n";
    		print "===========================================================\n";
    		print "@arguments","\n";
    		print "===========================================================\n";
    		redo; # redo to generate ${makeFolder}~remakemod.tmp
    	}
    	else
    	{
    		print $output;
    		&writeINI;
    		exit 1;
    	}
  } elsif ($action =~ /_viti/i) {
    $result = system("perl ${MTKtoolsFolder}build_viti.pl $project_name $flavor \"$theMF\" $tmpFolder $action @arguments");
    exit 1 if($result != 0);
  } elsif ($action eq "viewlog") {
    die "$logFolder does NOT exist\n" if (!-d $logFolder);
    if ($#arguments != -1) {
      foreach my $argu (@arguments) {
        if (-e "${logFolder}\\${argu}.log") {
          system("start ${logFolder}\\${argu}.log");
        } elsif (-e "${logFolder}\\${argu}_classb.log") {
          system("start ${logFolder}\\${argu}_classb.log");
        } else {
          warn "${logFolder}\\${argu}.log does NOT exist\n";
        }
      }
    } else {
      while ($argu = <$logFolder\\*.log>) {
        system("start ${argu}") if (-e "${argu}");
      }
    }
  } elsif ($action eq "rel") {
    #(!-e $disFile) && (die "$disFile does NOT exist!\nPlease help to check.\n");
    if (!-e $enFile) {
      warn "$enFile does NOT exist!\nCreate an EMPTY $enFile\n";
      sleep 2;
      system "copy /y nul $enFile > nul";
    }
    my $result = system("$makeCmd -f${makeFolder}custom_release.mak -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor RELEASE_DIR_O=$relDir LEVEL=$level ckcr");    
    if($result){
      print "ckcr fail\n";
      exit 1;
    }
    system("echo LEVEL=$level >> $tmpFolder\\~buildinfo.tmp");
    system("echo DUMMYVM=TRUE >> $tmpFolder\\~buildinfo.tmp") if ($dummyvm == 1);
    $result = system("$makeCmd -f${makeFolder}custom_release.mak custom_release -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor RELEASE_DIR_O=$relDir LEVEL=$level");
    &writeINI;
    exit 1 if ($result);
    exit 0;
  } elsif ($action eq "ckcr") {
    my $result = system("$makeCmd -f${makeFolder}custom_release.mak -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor RELEASE_DIR_O=$relDir LEVEL=$level ckcr");    
    if($result){
      print "ckcr fail\n";
      exit 1;
    }
  } elsif ($action eq "removecode") {
    print "${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor REMOVE_DIR=$remove_dir CORE_ROOT=$core_root $action";
    system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor REMOVE_DIR=$remove_dir CORE_ROOT=$core_root $action");
  } elsif (($action eq "gendoc") && ($#arguments != -1)) {
    system("echo DO_GENDOC_MODULE=TRUE > $tmpFolder\\~gendocmod.tmp");
    system("echo GENDOC_MODS=@arguments >> $tmpFolder\\~gendocmod.tmp");
  } elsif ($action eq "memquery") {
    if ($#arguments != -1) {
      system("echo @arguments > $tmpFolder/~memquery.tmp");
    }
    system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CORE_ROOT=$core_root memquery");
  } else {
    if ($action !~ /^ckmake$/i) {
      $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CORE_ROOT=$core_root ckmake");
      die "Error: ckmake failed!!!\n" if($result != 0);
    }
    $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CORE_ROOT=$core_root $target_option $action");
    if($result != 0) {
      &error_handle;
    } else{
      &mbis_success if ($mbis_en eq "TRUE");
      if (($custom_release eq "FALSE") && ($ENV{'MTK_INTERNAL'} eq 'TRUE')&& (-e "$MTKtoolsFolder\\Internal_function.pm")) {
        die "AAPMC parser Error!!!\n" if ($result != 0)
      }
    }
    next;
  }

  if (($action eq "remake") || ($action eq "update") || ($action eq "new") || ($action eq "bm_new") || ($action eq "scan") || ($action eq "codegen") || ($action =~ /^new_(modis|uesim)$/i)) {
#Carina#    $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor $target_option ckmake");
#Carina#    die "Error: ckmake failed!!!\n" if($result != 0);
  }
  if (($action eq "remake") || ($action eq "update") || ($action eq "new") || ($action eq "bm_new") || ($action eq "scan")) {
    if ($action eq "bm_new") {
      system("echo BM_NEW=TRUE >> $tmpFolder/~buildinfo.tmp");
      #Add for daily build
      if ($daily_build){
        system("echo DAILY_BUILD=TRUE >> $tmpFolder/~buildinfo.tmp");
      }
      $result = system("${makeCmd} -f${makeFolder}${myMF} -k -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CORE_ROOT=$core_root $target_option new");
    } else {
      $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CORE_ROOT=$core_root $target_option $action");
    }
    if ($result == 0) {
      if (($custom_release eq "FALSE") && ($ENV{'MTK_INTERNAL'} eq 'TRUE')&& (-e "$MTKtoolsFolder\\Internal_function.pm")) {
        $result = &AAPMC::Parse_AAPMCLog($AAPMCLOG,$project_name,$flavor,"$theMF");
        die "AAPMC parser Error!!!\n" if ($result != 0)
      }
      &mbis_success if ($mbis_en eq "TRUE");
    } else {
      &error_handle;
    }
    last if ($mbis_target_build_with_Modis != 1);
  } elsif ($action =~ /_(modis|uesim)\b/) {
    $result = &MoDIS_build_process($action);
  } elsif ($action eq "codegen") {
    $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R SINGLE_CORE=$single_core PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CORE_ROOT=$core_root code_generate");
    #mbis end probe
    if ($result == 0) {
      &mbis_success if ($mbis_en eq "TRUE");
    }
  }
  if ($result != 0) {
    system("perl $mbis -i SUCCESSFUL_BUILD,0") if ($mbis_en eq "TRUE");
    print "Failed in $action\n";
    last;
  }
}
# [Linux] temporarily add
#Carina#unlink("nul") if($^O eq "linux" && -e "nul");
#Carina#unlink("NUL") if($^O eq "linux" && -e "NUL");
unlink("nul");
unlink("NUL");
&writeINI;
if (($m_in_lsf != 1) && ($mbis_target_build_with_Modis == 1) && ($ENV{"MTK_CF"} ne "TRUE") && ($single_core ne "FALSE"))
{
  &mbis_end_probe;
}
#die "make.pl\n" if ($result != 0);
exit $result >> 8;

#usage:
#      my %hash=iniToHash('/tmp/myini.ini');
#      print $hash{'TITLE'}->{'Name'},"\n";
#
sub iniToHash {
  open(MYINI, $_[0]);
  my %hash;
  my $hashref;

  while(<MYINI>)
  {
    next if ((/^\s*$/) || (/^\s*#/));
    if (/^\s*\[(.+)\]/)
    {
      $hashref = $hash{$1} ||= {};
    }
    elsif (/^\s*(\S+)\s*=\s*(.+)\s*$/)
    {
      $hashref->{$1} = $2;
    }
    elsif (/^\s*(\S+)\s*\+=\s*(.+)\s*$/)
    {
      $hashref->{$1} = $hashref->{$1} . " $2";
    }
  }

  close MYINI;
  return %hash;
}

sub CurrTimeStr {
  my($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
  return (sprintf "%4.4d/%2.2d/%2.2d %2.2d:%2.2d", $year+1900, $mon+1, $mday, $hour, $min);
}

sub Usage {

  warn << "__END_OF_USAGE";

Usage:
  ./make.sh ["project makefile"] action [modules]|file1[ file2[ ...]] | \@files
  ./m       ["project makefile"] action [modules]|file1[ file2[ ...]] | \@files

Description:
  project makefile = firefly_demo.mak          (FIREFLY_DEMO Default customer)
                   = firefly_demo(flavor).mak  (FIREFLY_DEMO(FLAVOR) project)
                   = ...

  action     = new             (codegen, clean, update) (default)
             = update or u     (scan, compile, link)
             = slim_update     (scan, compile, link without generating mcddll)
             = remake or r     (compile, link)
             = clean or c      (clean)
             = cci or clean_codegen (clean codegen intermedia files)
             = c,u             (clean then update)
             = c,r             (clean then remake)
             = codegen         (codegen)
             = slim_codegen    (codegen without generating mcddll)
             = mcddll_update   (codegen and generate mcddll)
             = slim_mcddll     (generate mcddll without codegen)
             = viewlog         (open edit to view build log)
             = emigen          (emigen)
             = emiclean        (emiclean)
             = check_dep       (check dependency module(s) after source(s)/header(s) changed)
             = remake_dep      (check_dep, remake)
             = update_dep      (check_dep, update)

  module(s)  = modules' name   (kal, l1, ...)
   => OPTIONAL when action is one of (clean c remake r update u c,r c,u)

  file1      = changed source/header's name (init\\include\\init.h, ...)
   => VALID ONLY when action is one of (check_dep remake_dep update_dep)
   => MANDATORY when action is one of (check_dep remake_dep update_dep) and \@files is NOT specified

  \@files     = Specify more changed sources/headers via a file (change list)
   => VALID ONLY when action is one of (check_dep remake_dep update_dep)
   => MANDATORY when action is one of (check_dep remake_dep update_dep) and file1 is NOT specified

Example:
  ./make.sh "firefly17_demo_gprs(DEFAULT).mak" new
  ./make.sh "milan_demo_gprs(FULL_VERSION).mak" c,u custom
  ./m "milan_demo_gprs(FULL_VERSION).mak" r drv custom
__END_OF_USAGE

  exit 1;
}

sub writeINI {

  &writeMakeINI();
  if (($action ne "ckmake") && ($action ne "drv_feature_check")) {
    system("echo LOCAL_MACHINE=%COMPUTERNAME% >>$targetFolder/build.log");
    system("echo PROJECT_NAME=$project_name>>$targetFolder/build.log");
    system("echo PLATFORM=$plat>>$targetFolder/build.log");
    system("echo FLAVOR=$flavor>>$targetFolder/build.log");
    system("echo VERNO=$verno>>$targetFolder/build.log");
    system("echo ARMLMD_LICENSE_FILE=%ARMLMD_LICENSE_FILE%>>$targetFolder/build.log");
    system("perl common/tools/init/echo.pl -n COMMAND=make \"@orgARGV\">>$targetFolder/build.log");
    system("perl -e \"print \'BUILD END TIME=\'\">>$targetFolder/build.log");
    system("perl $toolsFolder/time.pl -n>>$targetFolder/build.log");
    $time_num=time;
    #mbis end probe
    # to aviod be called twice when enable lsf 
    if (($m_in_lsf != 1)&&($mbis_target_build_with_Modis != 1) && ($ENV{"MTK_CF"} ne "TRUE") && ($single_core ne "FALSE"))
    { 
      &mbis_end_probe;
    }
    #if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && (-d "$BuildInfoServer")) {
      #system("copy /y .\\build\\${custom}\\build.log $BuildInfoServer\\$verno\_$time_num\.log >nul");
    #}
  }
}

sub writeMakeINI{
  if(($ENV{'REDIRECT_OUT_DIR'} ne 'TRUE') || (!defined $ENV{'OUT_DIR'})){
    mkpath("$relative_path/build") if(!-d "$relative_path/build");
  }
  if ($enINI == 1) {
    open (FILE_HANDLE, ">$ini") or die "cannot open $ini\n";
    print FILE_HANDLE "project_makefile = ".uc $project_makefile."\n";
    print FILE_HANDLE "project_folder = ". $original_projectFolder."\n";
    close FILE_HANDLE;
  }
}

sub localq
{
  my ($islocalpath) = @_;
  my $result = 0;
  print "Check if localq is available .... ";
	unlink("$logFolder/localq.log") if (-e "$logFolder/localq.log");
  #system("bjobs -u all -q localq >localq.log 2>nul");
	system("bhosts $ENV{\"COMPUTERNAME\"} >$logFolder/localq.log 2>nul");
	open(LOCALQ, "$logFolder/localq.log") || die "Can not open $logFolder/localq.log!";
  while (<LOCALQ>) {
  	next if ($_ =~ /HOST_NAME/ig);
  	$_ =~ /(\S+)\s+(\S+)\s+(\S+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)/ig;
  	$STATUS = $2;
  	$MAX = $4;
  	$NJOBS = $5;
  }
  close LOCALQ;
  if (($NJOBS < $MAX) && ($STATUS =~ /ok/ig)) {
    print "YES\n";
    print "Enter the local queue.\n";
    if (($action =~ /new/i)) {
      #Carina#&pre_gen();
    }
    if ($islocalpath ne "") {
      if ($RUN_KLOCWORK eq 1) {
        print "bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I kwinject --detach Cgen.exe,DrvGen.exe -T kwinject.trace perl make.pl -lsf -localq -localpath @orgARGV\n";
        $result = system("bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I kwinject --detach Cgen.exe,DrvGen.exe -T kwinject.trace perl make.pl -lsf -localq -localpath @orgARGV");
      } else {
        print "bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I perl make.pl -lsf -localq -localpath @orgARGV\n";
        $result = system("bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I perl make.pl -lsf -localq -localpath @orgARGV");
      }
    }else{
      if ($RUN_KLOCWORK eq 1) {
        print "bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I kwinject --detach Cgen.exe,DrvGen.exe -T kwinject.trace perl make.pl -lsf -localq @orgARGV\n";
        $result = system("bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I kwinject --detach Cgen.exe,DrvGen.exe -T kwinject.trace perl make.pl -lsf -localq @orgARGV");
      } else {
        print "bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I perl make.pl -lsf -localq @orgARGV\n";
        $result = system("bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I perl make.pl -lsf -localq @orgARGV");
      }
    }
    &writeINI;
    exit $result >> 8;
  } else {
    print "NO\n";
  }
}

sub mbis_start_probe
{
  my $mbis_log_folder;

  if ($mbis_en eq "TRUE")
  {
    if (!defined($ENV{"MBIS_BUILD_TIME_TMP"}) || !defined($ENV{"MBIS_BUILD_TIME_LOG"}) || !defined($ENV{"MBIS_BUILD_INFO_LOG"}))
    {
      $mbis_log_folder = "$logFolder/mbis";
      if (!-d "$mbis_log_folder")
      {
				mkpath($mbis_log_folder) or die "Create Folder $mbis_log_folder Faild $!";
      }
      else
      {
        # delete last log file
        if ($mbis_en_save_log ne "TRUE")
        {
					my @f = glob("$mbis_log_folder/*.log");
					unlink(@f) or die "Remove failed $!" if(@f);
					my @f = glob("$mbis_log_folder/*.tmp");
					unlink(@f) or die "Remove failed $!" if(@f);
        }
      }

      if (!defined($ENV{MBIS_BUILD_TIME_TMP}))
      {
        $ENV{MBIS_BUILD_TIME_TMP} = $mbis_log_folder . "/". $build_time_string . "_" . "mbis" . "_" . "time" . ".tmp";
        #set title of mbis time tmp file
        system("echo Time Stamp,Item Name,Type,Time>>$ENV{MBIS_BUILD_TIME_TMP}");
        system("echo T_S,TOTAL,A,$build_time_sec >>$ENV{MBIS_BUILD_TIME_TMP}");
      }

      if (!defined($ENV{MBIS_BUILD_TIME_LOG}))
      {
        $ENV{MBIS_BUILD_TIME_LOG} = $mbis_log_folder . "/". $build_time_string . "_" . "mbis" . "_" . "time" . ".log";
        #set title of mbis time tmp file
        system("echo Item Name,Type,Start Time,End Time,Duration Time>>$ENV{MBIS_BUILD_TIME_LOG}");
      }

      if (!defined($ENV{MBIS_BUILD_INFO_LOG}))
      {
        $ENV{MBIS_BUILD_INFO_LOG} = $mbis_log_folder . "/". $build_time_string . "_" . "mbis" . "_" . "info" . ".log";
        #set title of mbis time tmp file
        system("echo Information Name,Information Content>>$ENV{MBIS_BUILD_INFO_LOG}");
        system("echo BUILD_START_DATATIME,$build_time_string>>$ENV{MBIS_BUILD_INFO_LOG}");
      }
      system("perl $mbis -s \"@orgARGVwithFlavor\"");
    }
  }
  else
  {
    # MBIS_BUILD_TIME_TMP must not be null for makefile expand the command
    $ENV{MBIS_BUILD_TIME_TMP}=tmp;
  }
}

sub mbis_info_probe
{
  if ($mbis_en eq "TRUE")
  {
    if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && (-e "$mbis_conf_file"))
    {
      %mbis_conf = iniToHash($mbis_conf_file);
      $pilot_bm_list = $mbis_conf{'INIT_CONF'}->{'BM_LIST'};
      if ($pilot_bm_list =~ /$ENV{USERNAME}/i)
      {
         system("perl $mbis -i BM_BUILD,1");
      }
      else
      {
         system("perl $mbis -i BM_BUILD,0");
      }
    }
    
		$cur_path=cwd(); 
    system("perl $mbis -i BUILD_FOLDER,\"$cur_path\"");
    if($^O eq" MSWin32") {
      system("perl $mbis -i BUILD_MACHINE,$ENV{COMPUTERNAME}");
    }else{
      $hostname = `hostname`;
      system("perl $mbis -i BUILD_MACHINE,$hostname");
    }
    system("perl $mbis -i CUSTOM_RELEASE,$custom_release");
    if ($mbis_num_proc == 0)
    {
      $mbis_num_proc = $ENV{"NUMBER_OF_PROCESSORS"};
    }
    system("perl $mbis -i NUMBER_OF_PROCESSORS,$mbis_num_proc");
    system("perl $mbis -i LSF,$m_in_lsf");
    system("perl $mbis -i COMPILER,$compiler");
    system("perl $mbis -i USER,$ENV{USERNAME}");
    system("perl $mbis -i PROJECT_NAME,$project_name");
    system("perl $mbis -i FLAVOR,$flavor");
    system("perl $mbis -i VERNO,$verno");
    system("perl $mbis -i PLATFORM,$plat");
    system("perl $mbis -i PID,$$");
    if (-e "make/common/rel/hq/USR.txt") 
    {
      system("perl $mbis -i CODEBASE,FULL");
    }
    else
    {
      system("perl $mbis -i CODEBASE,RELEASE");
      if (-d "make/common/rel/sub_ps") 
      {
        system("perl $mbis -i REL_PACKAGE,SUB_PS");
      }
      else
      {
        system("perl $mbis -i REL_PACKAGE,SUB_L4");
      }
    }
    if (-e "dailybuild.txt") 
    {
      system("perl $mbis -i DAILY_BUILD_PRODUCER,1");
    }
    else
    {
      system("perl $mbis -i DAILY_BUILD_PRODUCER,0");
    }
    if (-e "ewsprebuild.txt") 
    {
      system("perl $mbis -i EWS_PREBUILD_PRODUCER,1");
    }
    else
    {
      system("perl $mbis -i EWS_PREBUILD_PRODUCER,0");
    }
    my @folder_cnt = <./build/*/*>;
    my $fld_cnt = 0;
    foreach (@folder_cnt){
     $fld_cnt ++ if(-d "$_");
    }
    system("perl $mbis -i NUMBER_OF_PROJECT_FOLDER,$fld_cnt");
  }
}

sub mbis_end_probe
{
  if ($mbis_en eq "TRUE")
  { 
    system("perl $mbis -e");
  }
}

sub mbis_parse_arg
{
  $mbis_arg_exist = 1;
  foreach $arg (@mbis_arg)
  {
    if ($arg =~ /^en_mbis$/i)
    {
      $arg_mbis_en = "TRUE";
    }
    elsif ($arg =~ /^dis_mbis$/i)
    {
      $arg_mbis_en = "FALSE";
    }
    elsif ($arg =~ /^dis_obj$/i)
    {
      $arg_mbis_en_obj_log = "FALSE";
    }
    elsif ($arg =~ /^en_obj$/i)
    {
      $arg_mbis_en_obj_log = "TRUE";      
    }
    elsif ($arg =~ /^save_log$/i)
    {
      $arg_mbis_en_save_log = "TRUE";
    }
    else
    {
      # with error command
      $mbis_arg_exist = 0;
      return ;
    }
  }

  if ($arg_mbis_en ne "TRUE")
  {
    $arg_mbis_en_obj_log = "FALSE";
    $arg_mbis_en_save_log = "FALSE";
  }

}

sub mbis_init
{
  if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && (-e "$mbis_conf_file"))
  {
    %mbis_conf = iniToHash($mbis_conf_file);
    $mbis_bm_list = $mbis_conf{'INIT_CONF'}->{'BM_LIST'};
    $mbis_project_list = $mbis_conf{'INIT_CONF'}->{'PROJECT_LIST'};
    @mbis_project_array=split /,/, $mbis_project_list;
    $mbis_en = $mbis_conf{'INIT_CONF'}->{'EN_ALL_PROJECT'};
    $mbis_en_obj_log = $mbis_conf{'INIT_CONF'}->{'EN_OBJ_LOG'};
    # force all project enable mbis
    # enable obj log for BM only
    if ($mbis_en eq "TRUE")
    {
      # check bm list
      if ($mbis_bm_list =~ /$ENV{USERNAME}/i)
      {
        $mbis_en = "TRUE";
        $mbis_en_obj_log = "TRUE";
      }
      else
      {
        $mbis_en = "TRUE";
        $mbis_en_obj_log = "FALSE";
      }
    }

    # deal with mbis option from arg
    if ($mbis_en eq "TRUE")
    {
      print("MBIS init enable\n");
      if ($mbis_en_obj_log eq "TRUE")
      {
        print("MBIS obj log enable\n");
      }
 
      if ($mbis_arg_exist == 1)
      {
        $mbis_en = $arg_mbis_en;
        $mbis_en_obj_log = $arg_mbis_en_obj_log;
        $mbis_en_save_log = $arg_mbis_en_save_log;
        if ($mbis_en eq "TRUE")
        {
          print("MBIS arg enable\n");
        }
        else
        {
          print("MBIS arg disable\n");
        }
      }
    }
    else
    {
      $mbis_en_obj_log = "FALSE";
      $mbis_en_save_log = "FALSE";
      print("MBIS init disable\n");
    }
  }
}

sub mbis_success
{
  my $build_custom_folder;
  my @files;
  my $elfname;
  my $elfsize;
  # get elf size
  $build_custom_folder = "$targetFolder";
  opendir (DIR, $build_custom_folder) or die "no folder : $build_custom_folder";
  my @files = grep {/^$project_name.*\.elf$/}  readdir DIR;
  close DIR;
  if (@files == 1)
  {
    $elfname = pop @files;
    # add elf file name 
    system("perl $mbis -i ELF_FILE,$elfname");
    $elfsize = -s "$build_custom_folder\\$elfname";
    # add elf file size
    system("perl $mbis -i ELF_SIZE,$elfsize");
  }

  # add success flag
  system("perl $mbis -i SUCCESSFUL_BUILD,1");
}

sub error_handle
{
	my $build_folder = "$targetFolder";
	opendir (DIR, $build_folder) or die "no folder : $build_folder\n";
	my @files = grep {/.+\.bin$/}  readdir DIR;
	close DIR;
	my $flag = 0;
	foreach (@files) {
		next if($_ =~ /BOOTLOADER/i);
		my $bin_file = $build_folder."/$_";
		if (-d "$bin_file") {
			rmtree($bin_file);
			$flag = 1;
		} elsif(-e "$bin_file") {
			unlink($bin_file) or die "Remove failed $!";
			$flag = 1;
		}
	}
	print "Some errors happened during the build process. Delete the binary file\n" if($flag);
# [Linux] temporarily add
#Carina#	unlink("nul") if($^O eq "linux" && -e "nul");
#Carina#	unlink("NUL") if($^O eq "linux" && -e "NUL");
unlink("nul");
unlink("NUL");
	exit 1;
}

sub genCustombld{
  $bldPathName = "$projectFolder/Custom.bld";
  if(-e "make/common/rel/hq/USR.txt"){
    $bldValue = "FALSE";
  }
  else{
    $bldValue = "TRUE";
  }
  if(-e $bldPathName){
    open BLDFILE,"<$projectFolder/Custom.bld" or die "Can not open $projectFolder/Custom.bld";
    while(<BLDFILE>){
      if(/CUSTOM_RELEASE = $bldValue/){
        close BLDFILE;
        return 0;
      }
    }
    close BLDFILE;
  }
  open BLDFILE,">$projectFolder/Custom.bld" or die "Can not open $projectFolder/Custom.bld";
  print BLDFILE "CUSTOM_RELEASE = $bldValue\n";
  close BLDFILE;
}
