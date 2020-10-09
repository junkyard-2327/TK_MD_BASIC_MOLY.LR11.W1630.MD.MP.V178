#!/usr/bin/perl -w


#-------------------------------------------------------------------
#Tool version
$tool_version = 'v20150527';  

#-------------------------------------------------------------------
#DBG_MODE
$DBG_MODE = 0;

#-------------------------------------------------------------------
#Parameters Configuration
$file_fun_list = shift @ARGV;
$file_out_c    = shift @ARGV;
$file_out_h    = shift @ARGV;


die "[ADT][ERROR] 1st parameter must be ADT/AutoTCM function list file.\n" if( $file_fun_list eq '');
die "[ADT][ERROR] 2nd parameter must be ouput ADT C source file.\n" if( $file_out_c eq '');
die "[ADT][ERROR] 2nd parameter must be ouput ADT H header file.\n" if( $file_out_h eq '');
die "[ADT][ERROR] \"$file_out_c\" is not C file.\n " unless( $file_out_c =~ /\.c$/);
die "[ADT][ERROR] \"$file_out_h\" is not H file.\n " unless( $file_out_h =~ /\.h$/);

#-------------------------------------------------------------------
print "\n";
print "==========================\n";
print "ADT Codegen ($tool_version)\n";
print "==========================\n";
print "ADT Func List File: $file_fun_list\n";
print "ADT Output C File : $file_out_c\n";
print "ADT Output H File : $file_out_h\n";

#-------------------------------------------------------------------
# Replace '\' with '/'
$file_fun_list  =~ s/\\/\//g;  
$file_out_c     =~ s/\\/\//g;
$file_out_h     =~ s/\\/\//g;

#-------------------------------------------------------------------
#Remove existed output files
unlink( $file_out_c ) or die "[ADT][ERROR] Can't delete \"$file_out_c\"\n" if( -e $file_out_c );
unlink( $file_out_h ) or die "[ADT][ERROR] Can't delete \"$file_out_h\"\n" if( -e $file_out_h );

#-------------------------------------------------------------------
#Parse ADT function list file
($fn_switch_tcm, $fn_switch_emi, @fn_list) = Parse_Func_List( $file_fun_list );

#-------------------------------------------------------------------
#Generate ADT output H header file
Gen_ADT_H_File( $file_out_h, $fn_switch_tcm, $fn_switch_emi );

#-------------------------------------------------------------------
#Generate ADT output C source file
Gen_ADT_C_File( $file_out_c, $fn_switch_tcm, $fn_switch_emi, @fn_list );

#-------------------------------------------------------------------
#Done
print "\nADT Codegen is Done!\n";
#exit 0;  #return 0 if it is successful



#Parameters Configuration
$file_in_c   = $file_out_c;
$file_bak_c  = $file_out_c.'bak';

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
unlink( $file_bak_c ) or die "[ADT][ERROR] Can't delete \"$file_out_c\"\n" if( -e $file_bak_c );

#-------------------------------------------------------------------
# Add compiler option on POS function
Add_Compiler_Option( $file_in_c , $file_bak_c);

#-------------------------------------------------------------------
# Replace file
unlink( $file_in_c ) or die "[ADT][ERROR] Can't delete \"$file_out_c\"\n" if( -e $file_in_c );
rename $file_bak_c, $file_in_c;

#-------------------------------------------------------------------
#Done
print "\nADT Codegen (Add compiler option) is Done!\n";
exit 0;  #return 0 if it is successful

#===================================================================
#-------------------------------------------------------------------


#===================================================================
#-------------------------------------------------------------------
sub Parse_Func_List
{
   my $file_list = shift @_;
   
   print "\nStart to parse ADT function list:\n$file_list\n";
   
   open (FILE_LIST, "<$file_list" ) or die "[ADT][ERROR] Can't open ADT function list file \"$file_list\"\n";

   my $set_tcm_fn = '';
   my $set_emi_fn = '';   
   my @adt_fun_list;
         
   while (<FILE_LIST>)
   {  
      s/#.*//;
      s/^\s*//;
      s/\s*$//;
      next if( $_ eq '' );            

      if( /^__attribute__/ )
      {
         #__attribute__ ((section("INTSRAM_ROCODE")))
         last if( $set_tcm_fn.$set_emi_fn ne '' );  #ADT file list is finished
      }
      elsif( /^\[ADT\]\[SET_TCM_FN]\s*(.*)/)
      {          
         #[ADT][SET_TCM_FN] void EL1D_ADT_Switch_TCM( void )
         $set_tcm_fn = $1;
      }
      elsif( /^\[ADT\]\[SET_EMI_FN]\s*(.*)/)
      {
         #[ADT][SET_TCM_FN] void EL1D_ADT_Switch_EMI( void )
         $set_emi_fn = $1;
      }
      elsif( ($set_tcm_fn.$set_emi_fn ne '')  &&  /^\s*(\w+)\s*,?\s*(\S+)/ )
      {
         push( @adt_fun_list, "$1,$2" );         
         print "$1,$2\n" if( $DBG_MODE );
      }
   }

   close FILE_LIST;
      
   print "[ADT][SET_TCM_FN] $set_tcm_fn\n" ;
   print "[ADT][SET_EMI_FN] $set_emi_fn\n" ;
   print "There are ". scalar @adt_fun_list." ADT functions.\n";

   die "[ADT][ERROR] \"[ADT][SET_TCM_FN]\" is not be found in $file_list!\n" if( $set_tcm_fn eq '' );
   die "[ADT][ERROR] \"[ADT][SET_EMI_FN]\" is not be found in $file_list!\n" if( $set_emi_fn eq '' );
         
   return ( $set_tcm_fn, $set_emi_fn, @adt_fun_list );

}

#-------------------------------------------------------------------
sub Gen_ADT_H_File
{   
   my $file_out    = shift @_;
   my $set_tcm_fn  = shift @_;
   my $set_emi_fn  = shift @_;
      
   print "\nStart to output ADT H header file:\n$file_out\n";
      
   open (FILE_OUT_H, ">$file_out" ) or die "[ADT][ERROR] Failed to open output file \"$file_out\"\n";
   
   print FILE_OUT_H "extern $set_tcm_fn;\n";
   print FILE_OUT_H "extern $set_emi_fn;\n";
      
   close FILE_OUT_H;
   
}

#-------------------------------------------------------------------
sub Gen_ADT_C_File
{
   my $file_out   = shift @_;
   my $set_tcm_fn = shift @_;   
   my $set_emi_fn = shift @_;   
   my @fn_list    = @_;

   print "\nStart to output ADT C source file:\n$file_out\n";   
   
   my $extern_declare = '';   
   my $set_tcm_fn_body = '';
   my $set_emi_fn_body = '';
         
   foreach( @fn_list )
   {
      my $fn, $file;
      ($fn, $file) = split( /,/, $_ );
      
      $extern_declare  .= "extern void $fn"."__adtfp_set_tcm( void );//$file\n";
      $extern_declare  .= "extern void $fn"."__adtfp_set_emi( void );//$file\n";
      
      $set_tcm_fn_body .= "   $fn"."__adtfp_set_tcm(); //$file\n";
      $set_emi_fn_body .= "   $fn"."__adtfp_set_emi(); //$file\n";      
      
   }
  
   open (FILE_OUT_C, ">$file_out" ) or die "[ADT][ERROR] Failed to open output file \"$file_out\"\n";
   
   print FILE_OUT_C "$extern_declare\n";
   print FILE_OUT_C "\n";
      
   print FILE_OUT_C "$set_tcm_fn\n";
   print FILE_OUT_C "\{\n";
   print FILE_OUT_C "$set_tcm_fn_body\n";
   print FILE_OUT_C "\}\n";
   print FILE_OUT_C "\n";

   print FILE_OUT_C "$set_emi_fn\n";
   print FILE_OUT_C "\{\n";
   print FILE_OUT_C "$set_emi_fn_body\n";
   print FILE_OUT_C "\}\n";
   print FILE_OUT_C "\n";

   close FILE_OUT_C;
}

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
