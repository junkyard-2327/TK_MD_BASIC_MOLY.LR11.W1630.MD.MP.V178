#!/usr/bin/perl -w

#-------------------------------------------------------------------
#Tool version
$tool_version = 'v20151027';  

#-------------------------------------------------------------------
#DBG_MODE
$DBG_MODE = 0;

#-------------------------------------------------------------------
#Parameters Configuration
$file_in_c   = shift @ARGV;
$file_out_c  = './ladt.bak.c';

die "[ADT][ERROR] 1st parameter must be ADT C source file.\n" if( $file_in_c eq '');
die "[ADT][ERROR] \"$file_in_c\" is not C file.\n " unless( $file_in_c =~ /\.c$/);

#-------------------------------------------------------------------
print "\n";
print "==========================\n";
print "ADT Codegen (Add compiler option) ($tool_version)\n";
print "==========================\n";
print "ADT Input C File : $file_in_c\n";


#-------------------------------------------------------------------
# Replace '\' with '/'
$file_in_c     =~ s/\\/\//g;

#-------------------------------------------------------------------
#Remove existed temp files
unlink( $file_out_c ) or die "[ADT][ERROR] Can't delete \"$file_out_c\"\n" if( -e $file_out_c );

#-------------------------------------------------------------------
# Add compiler option on POS function
Add_Compiler_Option( $file_in_c , $file_out_c);

#-------------------------------------------------------------------
# Replace file
unlink( $file_in_c ) or die "[ADT][ERROR] Can't delete \"$file_out_c\"\n" if( -e $file_in_c );
rename $file_out_c, $file_in_c;

#-------------------------------------------------------------------
#Done
print "\nADT Codegen (Add compiler option) is Done!\n";
exit 0;  #return 0 if it is successful

#===================================================================
#-------------------------------------------------------------------
sub Add_Compiler_Option
{
   my $file_list = shift @_;
   my $file_out = shift @_;
   my $pos_func = '';
   
   print "\nStart to parse POS ADT function list:\n$file_list\n";
   
   open (FILE_LIST, "<$file_list" ) or die "[ADT][ERROR] Can't open ADT function list file \"$file_list\"\n";
   open (FILE_OUT, ">$file_out" ) or die "[ADT][ERROR] Failed to open output file \"$file_out\"\n";
         
   while (<FILE_LIST>)
   {  
      # since ladt.c is generated by codegen, so we does not remove unused symbols...
      next if( $_ eq '' );
 
      if ( /el1d_pos_/i ) 
      {
        $_ = "#ifdef __LTE_OTDOA_SUPPORT__\n".$_."#endif\n";
      }
      
      print FILE_OUT $_;
   }

   close FILE_LIST;
   close FILE_OUT;
}

#-------------------------------------------------------------------
