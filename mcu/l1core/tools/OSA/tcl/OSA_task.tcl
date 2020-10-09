Class IssTask -superclass IssPlugin -parameter {iss view top title}
IssTask instproc init args {
    next
my instvar iss top task_info_list task_context_list mclb mclb2 state selected_task_index tasks

    set iod [$iss set issoptions]
    
    set pw [ttk::panedwindow $top.pw -orient horizontal]
    set info [ttk::frame $pw.info]
    set context [ttk::frame $pw.context]
    
    ################################################
    # info
    ################################################
    set mclb [tablelist::tablelist $info.mclb -spacing 0 -showseparators yes -selectmode extended \
          -labelcommand tablelist::sortByColumn -font TkFixedFont \
          -xscrollcommand [list $info.sx set] -yscrollcommand [list $info.sy set] \
          -incrarrowtype down -listvariable [myvar task_info_list] -activestyle none \
          -selectborderwidth 0 -selectbackground $::color(selectbackground) -selectforeground $::color(selectforeground) \
          -columns {
              0 "id" left
              0 "name" left
              0 "status" left
              0 "priority" left
              0 "stack usage" left
              0 "stack pinter" left
              0 "stack start" left
              0 "stack size" left
              0 "call stack depth" left
          }]
    $mclb columnconfigure 0 -editable 0 -hide 0 -sortmode integer
    $mclb columnconfigure 1 -editable 0 -hide 0 -sortmode dictionary
    $mclb columnconfigure 2 -editable 0 -hide 0 -sortmode dictionary
    $mclb columnconfigure 3 -editable 0 -hide 0 -sortmode integer
    $mclb columnconfigure 4 -editable 0 -hide 0 -sortmode integer
    $mclb columnconfigure 5 -editable 0 -hide 0 -sortmode integer
    $mclb columnconfigure 6 -editable 0 -hide 0 -sortmode integer
    $mclb columnconfigure 7 -editable 0 -hide 0 -sortmode integer
    $mclb columnconfigure 8 -editable 0 -hide 0 -sortmode integer
    
    set sx [ttk::scrollbar $info.sx -orient horizontal -command [list $mclb xview]]
    set sy [ttk::scrollbar $info.sy -orient vertical -command [list $mclb yview]]
    grid $mclb $sy -sticky ewns
    grid $sx -sticky ewns
    grid columnconfigure $info 0 -weight 1
    grid rowconfigure $info 0 -weight 1

    ################################################
    # context
    ################################################
    set mclb2 [tablelist::tablelist $context.mclb2 -spacing 0 -showseparators yes -selectmode extended \
          -labelcommand tablelist::sortByColumn -font TkFixedFont \
          -xscrollcommand [list $context.sx set] -yscrollcommand [list $context.sy set] \
          -incrarrowtype down -listvariable [myvar task_context_list] -activestyle none \
          -selectborderwidth 0 -selectbackground $::color(selectbackground) -selectforeground $::color(selectforeground) \
          -columns {
              0 "level" left
              0 "function name" left
              0 "pc" left              
          }]
    $mclb2 columnconfigure 0 -editable 0 -hide 0 -sortmode integer
    $mclb2 columnconfigure 1 -editable 0 -hide 0 -sortmode dictionary    
    $mclb2 columnconfigure 2 -editable 0 -hide 0 -sortmode integer
    
    set sx [ttk::scrollbar $context.sx -orient horizontal -command [list $mclb2 xview]]
    set sy [ttk::scrollbar $context.sy -orient vertical -command [list $mclb2 yview]]
    grid $mclb2 $sy -sticky ewns
    grid $sx -sticky ewns
    grid columnconfigure $context 0 -weight 1
    grid rowconfigure $context 0 -weight 1

    ################################################
    # pack
    ################################################
    $pw add $info
    $pw add $context
    #pack $pw -side left -expand 1 -fill both
    pack $pw -expand 1 -fill both
    
    ################################################
    # bind
    ################################################
    bind [$mclb bodytag] <Button-1> "[myproc showStack %y %W]"
    bind [$mclb2 bodytag] <Button-1> "[myproc showInCode %y %W]"
    
    ################################################
    # init variables
    ################################################
    set selected_task_index 0
    set tasks ""
    set state normal
    set task_info_list ""
    set task_context_list ""    
    my getTasks
    my redraw
    # Initialise member variables
}

IssTask instproc getTasks {} {
    my instvar iss task_info_list task_context_list selected_task_index tasks
    
    ################################################
    # getting output
    ################################################
    set output [OSA_communication $iss task]    

    ################################################
    #get tasks
    ################################################
    
    set task_index 0
    set tasks ""
    
    if {$output == ""} {
        return
    }

    for {set i 0} {$i < [llength $output]} {incr i} {
        # id
        dict set tasks $task_index id [lindex $output $i]
    
        # name
        incr i
        dict set tasks $task_index name [lindex $output $i]
        
        # status
        incr i
        dict set tasks $task_index status [lindex $output $i]
        
        #priority
        incr i
        dict set tasks $task_index priority [lindex $output $i]
        
        # stack usage
        incr i
        dict set tasks $task_index stack_usage [lindex $output $i]
        
        # sp
        incr i
        dict set tasks $task_index sp [lindex $output $i]
        
        # stack start
        incr i
        dict set tasks $task_index stack_start [lindex $output $i]
        
        # stack size
        incr i
        dict set tasks $task_index stack_size [lindex $output $i]
        
        # call stack depth
        incr i
        dict set tasks $task_index call_stack_depth [lindex $output $i]
        
        # context
        for {set j 0} {$j < [dict get $tasks $task_index call_stack_depth]} {incr j} {
            # function name
            incr i        
            dict set tasks $task_index context $j function_name [lindex $output $i]
            
            # pc
            incr i
            dict set tasks $task_index context $j pc [lindex $output $i]
        }

        incr task_index
    }

    ################################################
    # task_info_list
    ################################################
    set task_info_list ""
    for {set i 0} {$i < $task_index} {incr i} {   
        lappend task_info_list [list \
            [dict get $tasks $i id] \
            [dict get $tasks $i name] \
            [dict get $tasks $i status] \
            [dict get $tasks $i priority] \
            [dict get $tasks $i stack_usage] \
            [dict get $tasks $i sp] \
            [dict get $tasks $i stack_start] \
            [dict get $tasks $i stack_size] \
            [dict get $tasks $i call_stack_depth]]
    }
    
    ################################################
    # task_context_list
    ################################################    
    set task_context_list ""
    
    for {set i 0} {$i < [dict get $tasks $selected_task_index call_stack_depth]} {incr i} {
        lappend task_context_list [list \
            $i \
            [dict get $tasks $selected_task_index context $i function_name] \
            [dict get $tasks $selected_task_index context $i pc]]
    }
}

IssTask instproc getTaskInfoList {} {
    my instvar iss task_info_list tasks
}

IssTask instproc getTaskContextList {} {
}

IssTask instproc showStack {y W} {
    my instvar iss mclb task_info_list selected_task_index tasks    
    
    focus $mclb
    set y [expr {$y + [winfo y $W] + [winfo y [winfo parent $W]]}]
    set idx [$mclb containing $y]    
        
    set selected_task_index $idx    
    
    if {$idx >= 0 && $idx < [llength $task_info_list]} {
        set selected_task_index $idx
        my getTasks
        my redraw
    }
}

IssTask instproc showInCode {y W} {
    my instvar iss mclb2 task_info_list task_context_list selected_task_index tasks    
    
    focus $mclb2
    set y [expr {$y + [winfo y $W] + [winfo y [winfo parent $W]]}]
    set idx [$mclb2 containing $y]

    if {$idx >= 0 && $idx < [llength $task_context_list]} {
        set selected_context_index $idx
        set pc [dict get $tasks $selected_task_index context $selected_context_index pc]        
        set pc_in_decimal [expr $pc]        
        $iss show_in_code $pc_in_decimal
    }
}


IssTask instproc set_state {new_state} {
    my instvar state pc asm
    # Keep state for use in redraw method
    set state $new_state
    
    if {$state eq "run"} {
        set task_info_list ""
        set task_context_list ""
        my redraw
    }
}

IssTask instproc redraw {} {
my instvar iss state task_info_list task_context_list selected_task_index
    if {$state == "run"} return
    my getTasks
}

project iss add_plugin IssTask -view "IssTaskView" -title "Task"