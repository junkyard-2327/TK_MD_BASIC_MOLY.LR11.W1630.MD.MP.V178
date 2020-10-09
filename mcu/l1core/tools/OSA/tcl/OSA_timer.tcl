Class IssTimer -superclass IssPlugin -parameter {iss view top title}
IssTimer instproc init args {
    next
my instvar iss top timer_list state
    set iod [$iss set issoptions]

    set info [ttk::frame $top.info]
    
    set timer_list ""

    pack $info -fill both -expand true

    set mclb [tablelist::tablelist $info.mclb -spacing 0 -showseparators yes -selectmode extended \
          -labelcommand tablelist::sortByColumn -font TkFixedFont \
          -xscrollcommand [list $info.sx set] -yscrollcommand [list $info.sy set] \
          -incrarrowtype down -listvariable [myvar timer_list] -activestyle none \
          -selectborderwidth 0 -selectbackground $::color(selectbackground) -selectforeground $::color(selectforeground) \
          -columns {
              0 "name" left              
              0 "expire" left
              0 "delay" left
          }]
     $mclb columnconfigure 0 -editable 0 -hide 0 -sortmode dictionary     
     $mclb columnconfigure 1 -editable 0 -hide 0 -sortmode integer
     $mclb columnconfigure 2 -editable 0 -hide 0 -sortmode integer

    set sx [ttk::scrollbar $info.sx -orient horizontal -command [list $mclb xview]]
    set sy [ttk::scrollbar $info.sy -orient vertical -command [list $mclb yview]]

    grid $mclb $sy -sticky ewns
    grid $sx -sticky ewns
    grid columnconfigure $info 0 -weight 1
    grid rowconfigure $info 0 -weight 1        

		set state normal
    my redraw
}

IssTimer instproc set_state {new_state} {
    my instvar state pc asm
    # Keep state for use in redraw method
    set state $new_state
    # Set PC as unknown when simulation is running
}

IssTimer instproc redraw {} {
my instvar iss state timer_list    
    set timer_list ""
    
    if {$state eq "run"} return

    set output [OSA_communication $iss timer]
    foreach {name expire delay} $output {
        lappend timer_list [list $name $expire $delay]
    }
}

project iss add_plugin IssTimer -view "IssTimerView" -title "timer"