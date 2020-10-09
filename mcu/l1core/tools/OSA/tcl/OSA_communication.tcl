proc OSA_communication {iss item} {
    set io [open "|../../../../../l1core/tools/OSA/osa" r+]
    
    # verno
    gets $io verno
    #puts $verno

    # usage    
    gets $io command
    #puts $command
    
    # item
    puts $io $item
    flush $io

    # command loop    
    gets $io command
    set value 0
    
    while { $command != "done" } {  
      if {$command == "M"} {
          gets $io addr
          set value [$iss iss_exec get DMb $addr -radix hexadecimal]          
      }  
      
      if {$command == "PC" } {
          set value [$iss iss_exec get PC -radix hexadecimal]
          #puts "OSA wants PC: $value"
      }
      
      if {$command == "SP" } {
          set value [$iss iss_exec get SP -radix hexadecimal]
          #puts "OSA wants SP: $value"
      }
      
      if {$command == "R" } {
          gets $io reg_num
          set value [$iss iss_exec get R[expr $reg_num - 20] -radix hexadecimal]
          #puts "OSA wants R[expr $reg_num - 20]: $value"
      }

      if {$command == "MPU"} {
        for {set i 0} {$i < 16} {incr i} {
            puts $io [eval [format "$iss iss_exec get MPU_L%02d -radix hexadecimal" $i]]
            flush $io
            puts $io [eval [format "$iss iss_exec get MPU_H%02d -radix hexadecimal" $i]]
            flush $io
        }

        puts $io [$iss iss_exec get MPU_LITCM -radix hexadecimal]
        flush $io
        puts $io [$iss iss_exec get MPU_HITCM -radix hexadecimal]
        flush $io
        puts $io [$iss iss_exec get MPU_LDTCM -radix hexadecimal]
        flush $io
        puts $io [$iss iss_exec get MPU_HDTCM -radix hexadecimal]
        flush $io        
        gets $io command
        continue
      }
      
      
      puts $io "0x$value"
      flush $io
      gets $io command
    }
    
    # getting output

    set output ""
    gets $io str
    while {$str != "end"} {
        lappend output $str
        gets $io str
    }

    return $output
}