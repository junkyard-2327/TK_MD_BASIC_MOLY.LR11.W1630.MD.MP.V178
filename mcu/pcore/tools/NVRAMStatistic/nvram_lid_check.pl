use strict;
use warnings;
use Cwd;
use File::Find;
use File::Copy;

	my ($ERR_OK, $ERR_ERROR, $ERR_WARNING, $ERR_OPEN_FILE) = 0..2;
	my $PrelogPath = "";
	my $CurrlogPath = "";
	my $OutputPath = "";
	my $Parameter = "";
	my @PreDatabase;
	my @CurrDatabase;
	my $PreDatabaseIdx;
	my $CurrDatabaseIdx;
	my $Result = $ERR_OK;
	my $SkipWarning = 0;
	my $cnt;

	my $platform = 0;
	my $streamstr = "";
	my $starttime = time();
	my $usetime = 0;

	$PrelogPath = $ARGV[0];
	$CurrlogPath = $ARGV[1];
	$OutputPath = $ARGV[2];
	$Parameter = $ARGV[3];

	if ($PrelogPath eq "")
	{
	  $PrelogPath = "./pcore/tools/NVRAMStatistic/debug";
	}
	if ($CurrlogPath eq "")
	{
	  $CurrlogPath = "./build/";
	}
	if ($OutputPath eq "")
	{
	  $OutputPath = "./nvram_lid_check.log";
	}	
	if ($Parameter =~ /\/s/)
	{
	  $SkipWarning = 1;
	}
	if ($^O eq "MSWin32")
	{
		print "nvram_lid_check.pl not support MSWin32!!";
		exit $ERR_OK;
	}

	&kal_print(0, "Platform is: $^O\n");
	#$streamstr .= sprintf("Param: \n", $parrameter);
	&kal_print(0, "Parameter: $Parameter\n");
	&kal_print(0, "Path1: $PrelogPath   ");
	@PreDatabase = &scan_context($PrelogPath);
	$PreDatabaseIdx = @PreDatabase;
	&kal_print(0, "lid_count:$PreDatabaseIdx\n");

	&kal_print(0, "Path2: $CurrlogPath   ");
	@CurrDatabase = &scan_context($CurrlogPath);
	$CurrDatabaseIdx = @CurrDatabase;
	&kal_print(0, "lid_count:$CurrDatabaseIdx\n");	

	if(($PreDatabaseIdx eq 0) or ($CurrDatabaseIdx eq 0))
	{
		&kal_print(0, "Open file fail. Skip check script.\n");
		exit $ERR_OK;
	}

	#$cnt = check_lid_filename_length(\@PreDatabase);
	#$cnt = check_lid_filename_duplicate(\@PreDatabase);
	$cnt = &check_lid_filename_length(\@CurrDatabase);
	if($cnt ne 0)
	{
		$Result = $ERR_ERROR;
	}
	$cnt = &check_lid_filename_duplicate(\@CurrDatabase);
	if($cnt ne 0)
	{
		$Result = $ERR_ERROR;
	}	
	$cnt = &check_OTA_delete(\@PreDatabase, \@CurrDatabase);
	if($cnt ne 0)
	{
		$Result = $ERR_ERROR;
	}	
	$cnt = &check_OTA_assert(\@PreDatabase, \@CurrDatabase);
	if($cnt ne 0)
	{
		$Result = $ERR_ERROR;
	}
	$cnt = &check_OTA_filename_conflict(\@PreDatabase, \@CurrDatabase);
	if($cnt ne 0)
	{
		$Result = $ERR_ERROR;
	}
		
	#&kal_print(0, "=======================\n");
	$cnt = &check_OTA_add(\@PreDatabase, \@CurrDatabase);
	if(($cnt ne 0) and ($Result eq $ERR_OK) and ($SkipWarning eq 0))
	{
		$Result = $ERR_WARNING;
	}	
	$cnt = &check_OTA_filename(\@PreDatabase, \@CurrDatabase);
	if(($cnt ne 0) and ($Result eq $ERR_OK) and ($SkipWarning eq 0))
	{
		$Result = $ERR_WARNING;
	}	
	$cnt = &check_OTA_category(\@PreDatabase, \@CurrDatabase);
	if(($cnt ne 0) and ($Result eq $ERR_OK) and ($SkipWarning eq 0))
	{
		$Result = $ERR_WARNING;
	}		
	$cnt = &check_OTA_size_warning(\@PreDatabase, \@CurrDatabase);
	if(($cnt ne 0) and ($Result eq $ERR_OK) and ($SkipWarning eq 0))
	{
		$Result = $ERR_WARNING;
	}	
	$cnt = &check_OTA_attibute(\@PreDatabase, \@CurrDatabase);
	if(($cnt ne 0) and ($Result eq $ERR_OK) and ($SkipWarning eq 0))
	{
		$Result = $ERR_WARNING;
	}	

	$usetime = time() - $starttime;	
	&kal_print(0, "nvram_lid_check spend time:  $usetime s\n");
	&kal_print(0, "outputfile: $OutputPath\n");
	&WriteFile("$OutputPath",$streamstr); 
	exit $Result;
	
sub get_lid_size
{	 
	(my ($lidname),my ($lidid),my($strFilePath)) = @_;
	my ($filename) = "$strFilePath/~nvram_lid_size.log";

	open FILEHANDLE2, "<$filename" or die "couldn't open $filename\n" && return $ERR_OPEN_FILE;
	while (<FILEHANDLE2>) 
	{		
		my $line = $_;      
		chomp($line);

		if($line =~ /\s$lidname/g)
		{
			$line = trim($line);
			my @lidinfo = split(/ +/, $line);
			if($lidid eq $lidinfo[0])
			{
				return $lidinfo[1];
				last;
			}
		}
    } 	
	close FILEHANDLE2;
	return 0;
}	
	
sub scan_context
{	
	my (@database);
	my ($strFilePath) = @_;
	my ($filename) = "$strFilePath/~nvram_lid_information.log";
	my $count = 0;
	
	open FILEHANDLE, "<$filename" or die "couldn't open $filename\n" && return;

	while (<FILEHANDLE>) 
	{		
		my $line = $_;      
		chomp($line);

		if($line =~ /\s*NVRAM_EF*/g)
		{
			$line = trim($line);
			my @lidinfo = split(/ +/, $line);
			$lidinfo[4] = get_lid_size($lidinfo[1], $lidinfo[0], $strFilePath);
			#print "@lidinfo\r\n";
			push(@database, [@lidinfo]);
			$count++;
		} 
	}
	close FILEHANDLE;
	return @database; 
}	
	
sub check_lid_filename_length()
{
	my $param1 = shift;
	my @database = @$param1;
	my $length = @database;
	my ($i, $j);
	my $ret = 0;

	for($i = 0; $i < ($length-1); $i++)
	{
		# check filename length
		if(length($database[$i][2]) ne 4)
		{
			&kal_print($ERR_ERROR, "LID:$database[$i][0] $database[$i][1] filename \"$database[$i][2]\" unexpected.\n");
			$ret ++;
		}
		# check file verno length
		if(length($database[$i][3]) ne 3)
		{
			&kal_print($ERR_ERROR, "LID:$database[$i][0] $database[$i][1] file verno \"$database[$i][3]\" unexpected.\n");
			$ret ++;
		}
	}
	return $ret;
}

sub check_lid_filename_duplicate()
{
	my $param1 = shift;
	my @database = @$param1;
	my $length = @database;
	my ($i, $j);
	my $ret = 0;

	for($i = 0; $i < ($length-1); $i++)
	{
		for($j = ($i+1); $j < $length; $j++)
		{
			# check filename duplicate
			if(($database[$i][2] eq $database[$j][2]) and
			   ((hex($database[$i][5]) & 0x7021) eq (hex($database[$j][5]) & 0x7021)) )
			{
				&kal_print($ERR_ERROR, "LID:$database[$i][0] $database[$i][1] filename \"$database[$i][2]\" duplicate with LID:$database[$j][0] $database[$j][1].\n");
				$ret ++;
			}
		}
	}
	return $ret;
}

sub check_OTA_add()
{
	my $param1 = shift;
	my $param2 = shift;
	my @database1 = @$param1;
	my @database2 = @$param2;
	my $db1_idx = @database1;
	my $db2_idx = @database2;
	my $ret = 0;
	my ($i,$j,$flag);
	
	#  @database[][0]  LID,
	#  @database[][1]  LID_Str,
	#  @database[][2]  Filename,
	#  @database[][3]  Verno,
	#  @database[][4]  Length,
	#  @database[][5]  Category,
	#  @database[][6]  Attribute
	for($j = 0; $j < $db2_idx; $j++)
	{
		$flag = 0;
		for($i = 0; $i < $db1_idx; $i++)
		{
			if($database2[$j][1] eq $database1[$i][1])
			{
				$flag = 1;
				last;
			}
		}
		if($flag eq 0)
		{
			&kal_print($ERR_WARNING, "New LID:$database2[$j][0] $database2[$j][1] reset to default value.\r\n");
			$ret ++;
		}
	}
	return $ret;
}

sub check_OTA_filename()
{
	my $param1 = shift;
	my $param2 = shift;
	my @database1 = @$param1;
	my @database2 = @$param2;
	my $db1_idx = @database1;
	my $db2_idx = @database2;
	my $ret = 0;
	my ($i,$j,$flag);
	
	#  @database[][0]  LID,
	#  @database[][1]  LID_Str,
	#  @database[][2]  Filename,
	#  @database[][3]  Verno,
	#  @database[][4]  Length,
	#  @database[][5]  Category,
	#  @database[][6]  Attribute
	for($j = 0; $j < $db2_idx; $j++)
	{
		$flag = 0;
		for($i = 0; $i < $db1_idx; $i++)
		{
			if(($database2[$j][1] eq $database1[$i][1]) and
			   (($database2[$j][2] ne $database1[$i][2]) or 
			   ($database2[$j][3] ne $database1[$i][3])) )
			{
				&kal_print($ERR_WARNING, "    $database1[$i][0] $database1[$i][1] $database1[$i][2] $database1[$i][3]\r\n");
				&kal_print($ERR_WARNING, "  ->$database2[$j][0] $database2[$j][1] $database2[$j][2] $database2[$j][3]\r\n");
				$flag = 1;
				last;
			}
		}
		if($flag eq 1)
		{
			&kal_print($ERR_WARNING, "Update LID:$database2[$j][0] $database2[$j][1] reset to default value.\r\n");
			$ret ++;
		}
	}
	return $ret;
}

sub check_OTA_delete()
{
	my $param1 = shift;
	my $param2 = shift;
	my @database1 = @$param1;
	my @database2 = @$param2;
	my $db1_idx = @database1;
	my $db2_idx = @database2;
	my $ret = 0;
	my ($i,$j,$flag);
	
	#  @database[][0]  LID,
	#  @database[][1]  LID_Str,
	#  @database[][2]  Filename,
	#  @database[][3]  Verno,
	#  @database[][4]  Length,
	#  @database[][5]  Category,
	#  @database[][6]  Attribute
	for($i = 0; $i < $db1_idx; $i++)
	{
		$flag = 0;
		for($j = 0; $j < $db2_idx; $j++)
		{
			if($database2[$j][1] eq $database1[$i][1])
			{
				$flag = 1;
				last;
			}
		}
		if(($flag eq 0) and ((hex($database1[$i][5]) & 0x7000) ne 0) )
		{
			&kal_print($ERR_ERROR, "Delete LID:$database1[$i][0] $database1[$i][1].\r\n");
			$ret ++;
		}
	}
	return $ret;
}

sub trim()
{
	my ($str) = @_;
	$str =~ s/^\s+//;
	$str =~ s/\s+$//;
	return $str;
}
	
sub check_OTA_assert()
{
	my $param1 = shift;
	my $param2 = shift;
	my @database1 = @$param1;
	my @database2 = @$param2;
	my $db1_idx = @database1;
	my $db2_idx = @database2;
	my $ret = 0;
	my ($i,$j,$flag);
	
	#  @database[][0]  LID,
	#  @database[][1]  LID_Str,
	#  @database[][2]  Filename,
	#  @database[][3]  Verno,
	#  @database[][4]  Length,
	#  @database[][5]  Category,
	#  @database[][6]  Attribute
	for($i = 0; $i < $db1_idx; $i++)
	{
		$flag = 0;
		for($j = 0; $j < $db2_idx; $j++)
		{
			# calibration & important LID length change.
			if($database1[$i][2] eq $database2[$j][2] and
				$database1[$i][3] eq $database2[$j][3])
			{
				#CALIBRAT
				if((hex($database1[$i][5]) & 0x1000) and 
					(hex($database2[$j][5]) & 0x1000) and
					$database1[$i][4] ne $database2[$j][4])
				{
					&kal_print($ERR_ERROR, "CALIBRAT LID:$database2[$j][0] $database2[$j][1] length changed. $database1[$i][4] -> $database2[$j][4]\r\n");
					$flag = 1;
				}
				#IMPORTANT
				if((hex($database1[$i][5]) & 0x2000) and
					(hex($database2[$j][5]) & 0x2000) and
					$database1[$i][4] ne $database2[$j][4])
				{
					&kal_print($ERR_ERROR, "IMPORTANT LID:$database2[$j][0] $database2[$j][1] length changed. $database1[$i][4] -> $database2[$j][4]\r\n");
					$flag = 1;
				}
				#IMPORTANT_L4
				if((hex($database1[$i][5]) & 0x4000) and
					(hex($database2[$j][5]) & 0x4000) and
					$database1[$i][4] ne $database2[$j][4])
				{
					&kal_print($ERR_ERROR, "IMPORTANT_L4 LID:$database2[$j][0] $database2[$j][1] length changed. $database1[$i][4] -> $database2[$j][4]\r\n");
					$flag = 1;
				}
				last;
			}
		}
		if($flag eq 1)
		{
			$ret ++;
		}
	}
	return $ret;
}	

sub check_OTA_size_warning()
{
	my $param1 = shift;
	my $param2 = shift;
	my @database1 = @$param1;
	my @database2 = @$param2;
	my $db1_idx = @database1;
	my $db2_idx = @database2;
	my $ret = 0;
	my ($i,$j,$flag);
	
	#  @database[][0]  LID,
	#  @database[][1]  LID_Str,
	#  @database[][2]  Filename,
	#  @database[][3]  Verno,
	#  @database[][4]  Length,
	#  @database[][5]  Category,
	#  @database[][6]  Attribute
	for($i = 0; $i < $db1_idx; $i++)
	{
		$flag = 0;
		for($j = 0; $j < $db2_idx; $j++)
		{
			# user LID length change.
			if($database1[$i][2] eq $database2[$j][2] and
				$database1[$i][3] eq $database2[$j][3])
			{
				#USER
				if(((hex($database1[$i][5]) & 0xF000) eq 0) and 
					((hex($database2[$j][5]) & 0xF000) eq 0) and
					$database1[$i][4] ne $database2[$j][4])
				{
					&kal_print($ERR_WARNING, "USER LID:$database2[$j][0] $database2[$j][1] reset to default value. length changed $database1[$i][4] -> $database2[$j][4]\r\n");
					$flag = 1;
				}
				last;
			}
		}
		if($flag eq 1)
		{
			$ret ++;
		}
	}
	return $ret;
}	

sub check_OTA_filename_conflict()
{
	my $param1 = shift;
	my $param2 = shift;
	my @database1 = @$param1;
	my @database2 = @$param2;
	my $db1_idx = @database1;
	my $db2_idx = @database2;
	my $ret = 0;
	my ($i,$j,$flag);
	
	#  @database[][0]  LID,
	#  @database[][1]  LID_Str,
	#  @database[][2]  Filename,
	#  @database[][3]  Verno,
	#  @database[][4]  Length,
	#  @database[][5]  Category,
	#  @database[][6]  Attribute
	for($i = 0; $i < $db1_idx; $i++)
	{
		$flag = 0;
		for($j = 0; $j < $db2_idx; $j++)
		{
			# user LID length change.
			if($database1[$i][2] eq $database2[$j][2] and
				$database1[$i][1] ne $database2[$j][1] and
				(hex($database1[$i][5]) & 0xF000) eq (hex($database2[$j][5]) & 0xF000) )
			{

				&kal_print($ERR_ERROR, "$database1[$i][1]:$database1[$i][2] $database2[$j][1]:$database2[$j][2]\r\n");
				$flag = 1;
				last;
			}
		}
		if($flag eq 1)
		{
			$ret ++;
		}
	}
	return $ret;
}	
	
sub check_OTA_category()
{
	my $param1 = shift;
	my $param2 = shift;
	my @database1 = @$param1;
	my @database2 = @$param2;
	my $db1_idx = @database1;
	my $db2_idx = @database2;
	my $ret = 0;
	my ($i,$j,$flag);
	
	#  @database[][0]  LID,
	#  @database[][1]  LID_Str,
	#  @database[][2]  Filename,
	#  @database[][3]  Verno,
	#  @database[][4]  Length,
	#  @database[][5]  Category,
	#  @database[][6]  Attribute
	for($i = 0; $i < $db1_idx; $i++)
	{
		$flag = 0;
		for($j = 0; $j < $db2_idx; $j++)
		{
			# calibration & important LID length change.
			if($database1[$i][1] eq $database2[$j][1])
			{
				#CALIBRAT category change
				if(((hex($database1[$i][5]) & 0x1000) and ((hex($database2[$j][5]) & 0x1000) eq 0)) or
				   ((hex($database2[$j][5]) & 0x1000) and ((hex($database1[$i][5]) & 0x1000) eq 0)) )
				{
					&kal_print($ERR_WARNING, "CALIBRAT LID:$database2[$j][0] $database2[$j][1] category changed. $database1[$i][5] -> $database2[$j][5]\r\n");
					$flag = 1;
					last;
				}
				#IMPORTANT category change
				if(((hex($database1[$i][5]) & 0x2000) and ((hex($database2[$j][5]) & 0x2000) eq 0)) or
				   ((hex($database2[$j][5]) & 0x2000) and ((hex($database1[$i][5]) & 0x2000) eq 0)) )
				{
					&kal_print($ERR_WARNING, "IMPORTANT LID:$database2[$j][0] $database2[$j][1] category changed. $database1[$i][5] -> $database2[$j][5]\r\n");
					$flag = 1;
					last;
				}
				#IMPORTANT_L4 category change
				if(((hex($database1[$i][5]) & 0x4000) and ((hex($database2[$j][5]) & 0x4000) eq 0)) or
				   ((hex($database2[$j][5]) & 0x4000) and ((hex($database1[$i][5]) & 0x4000) eq 0)) )
				{
					&kal_print($ERR_WARNING, "IMPORTANT_L4 LID:$database2[$j][0] $database2[$j][1] category changed. $database1[$i][5] -> $database2[$j][5]\r\n");
					$flag = 1;
					last;
				}
			}
		}
		if($flag eq 1)
		{
			$ret ++;
		}
	}
	return $ret;
}	
	
sub check_OTA_attibute()
{
	my $param1 = shift;
	my $param2 = shift;
	my @database1 = @$param1;
	my @database2 = @$param2;
	my $db1_idx = @database1;
	my $db2_idx = @database2;
	my $ret = 0;
	my ($i,$j,$flag);
	
	#  @database[][0]  LID,
	#  @database[][1]  LID_Str,
	#  @database[][2]  Filename,
	#  @database[][3]  Verno,
	#  @database[][4]  Length,
	#  @database[][5]  Category,
	#  @database[][6]  Attribute
	for($i = 0; $i < $db1_idx; $i++)
	{
		$flag = 0;
		for($j = 0; $j < $db2_idx; $j++)
		{
			# multiple attribute change.
			if($database1[$i][1] eq $database2[$j][1])
			{
				#MULTIPLE
				if(((hex($database1[$i][6]) & 0x0004) and ((hex($database2[$j][6]) & 0x0004) eq 0)) or
				   ((hex($database2[$j][6]) & 0x0004) and ((hex($database1[$i][6]) & 0x0004) eq 0)) )
				{
					&kal_print($ERR_WARNING, "MULTIPLE LID:$database2[$j][0] $database2[$j][1] attribute changed. $database1[$i][6] -> $database2[$j][6]\r\n");
					$flag = 1;
					last;
				}

			}
		}
		if($flag eq 1)
		{
			$ret ++;
		}
	}
	return $ret;
}		

sub kal_print()
{
	my ($level, $msg) = @_;
	if($level eq $ERR_ERROR)
	{
		print "Error: ";
		$streamstr .= "Error: ";
	}
	if($level eq $ERR_WARNING)
	{
		print "Warning: ";
		$streamstr .= "Warning: ";
	}	
	print "$msg";
	$streamstr .= "$msg";
}
	
sub WriteFile
{
    my ($strFilePath, $strContent) = @_;
    open FILE_HANDLE, ">$strFilePath" or  print "couldn't open $strFilePath\n" && return $ERR_OPEN_FILE;
    print FILE_HANDLE $strContent;
    close FILE_HANDLE;
}