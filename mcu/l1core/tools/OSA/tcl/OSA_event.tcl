Class Issevent -superclass IssPlugin -parameter {iss view top title}
Issevent instproc init args {
    next
my instvar iss top event_list state
    set iod [$iss set issoptions]

    set info [ttk::frame $top.info]
    
    set event_list ""

    pack $info -fill both -expand true

    set mclb [tablelist::tablelist $info.mclb -spacing 0 -showseparators yes -selectmode extended \
          -labelcommand tablelist::sortByColumn -font TkFixedFont \
          -xscrollcommand [list $info.sx set] -yscrollcommand [list $info.sy set] \
          -incrarrowtype down -listvariable [myvar event_list] -activestyle none \
          -selectborderwidth 0 -selectbackground $::color(selectbackground) -selectforeground $::color(selectforeground) \
          -columns {
              0 "name" left              
              0 "value" left
          }]
     $mclb columnconfigure 0 -editable 0 -hide 0 -sortmode dictionary     
     $mclb columnconfigure 1 -editable 0 -hide 0 -sortmode integer    

    set sx [ttk::scrollbar $info.sx -orient horizontal -command [list $mclb xview]]
    set sy [ttk::scrollbar $info.sy -orient vertical -command [list $mclb yview]]

    grid $mclb $sy -sticky ewns
    grid $sx -sticky ewns
    grid columnconfigure $info 0 -weight 1
    grid rowconfigure $info 0 -weight 1        

		set state normal
    my redraw
}

Issevent instproc set_state {new_state} {
    my instvar state pc asm
    # Keep state for use in redraw method
    set state $new_state
    # Set PC as unknown when simulation is running
}

Issevent instproc redraw {} {
my instvar iss state event_list
    set event_list ""
    
    if {$state eq "run"} return
      
    set output [OSA_communication $iss event]
    
    foreach {name value} $output {
        lappend event_list [list $name $value]
    }
}

project iss add_plugin Issevent -view "IsseventView" -title "event"