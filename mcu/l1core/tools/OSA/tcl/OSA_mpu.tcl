Class issMPU -superclass IssPlugin -parameter {iss view top title}
issMPU instproc init args {
    next
my instvar iss top mpu_list state
    set iod [$iss set issoptions]

    set info [ttk::frame $top.info]
    
    set mpu_list ""

    pack $info -fill both -expand true

    set mclb [tablelist::tablelist $info.mclb -spacing 0 -showseparators yes -selectmode extended \
          -labelcommand tablelist::sortByColumn -font TkFixedFont \
          -xscrollcommand [list $info.sx set] -yscrollcommand [list $info.sy set] \
          -incrarrowtype down -listvariable [myvar mpu_list] -activestyle none \
          -selectborderwidth 0 -selectbackground $::color(selectbackground) -selectforeground $::color(selectforeground) \
          -columns {
              0 "channel" left
              0 "start" left
              0 "end" left
              0 "permission" left
          }]
     $mclb columnconfigure 0 -editable 0 -hide 0 -sortmode dictionary
     $mclb columnconfigure 1 -editable 0 -hide 0 -sortmode dictionary
     $mclb columnconfigure 2 -editable 0 -hide 0 -sortmode dictionary
     $mclb columnconfigure 3 -editable 0 -hide 0 -sortmode dictionary

    set sx [ttk::scrollbar $info.sx -orient horizontal -command [list $mclb xview]]
    set sy [ttk::scrollbar $info.sy -orient vertical -command [list $mclb yview]]

    grid $mclb $sy -sticky ewns
    grid $sx -sticky ewns
    grid columnconfigure $info 0 -weight 1
    grid rowconfigure $info 0 -weight 1        

        set state normal
    my redraw
}

issMPU instproc set_state {new_state} {
    my instvar state pc asm
    # Keep state for use in redraw method
    set state $new_state
    # Set PC as unknown when simulation is running
}

issMPU instproc redraw {} {
my instvar iss state mpu_list
    set mpu_list ""
    
    if {$state eq "run"} return

    set output [OSA_communication $iss mpu]
    foreach {name max_mails mail_size pending_mails} $output {
        lappend mpu_list [list $name $max_mails $mail_size $pending_mails]
    }
}

project iss add_plugin issMPU -view "issMPUView" -title "MPU"