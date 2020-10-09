Class IssException -superclass IssPlugin -parameter {iss view top title}
IssException instproc init args {
    next
my instvar iss top state paned_window info context mclb \
    exception_type file_name line_number expression ext1 ext2 ext3 code1 code2 execution_unit \
    exception_context_list selected_context_index current_window

    set iod [$iss set issoptions]
    
    set paned_window [ttk::panedwindow $top.paned_window -orient horizontal]

    ################################################
    # init variables
    ################################################
    set state normal
    set exception ""
    set exception_type 0
    set file_name ""
    set line_number 0
    set expression ""
    set ext1 ""
    set ext2 ""
    set ext3 ""
    set code1 0
    set code2 0
    set exception_context_list ""
    set selected_context_index 0
    set current_window NONE
    my redraw
    # Initialise member variables
}

IssException instproc showInCode {y W} {
my instvar iss top state paned_window info context mclb \
    exception_type file_name line_number expression ext1 ext2 ext3 code1 code2 execution_unit \
    exception_context_list selected_context_index current_window
    
    focus $mclb
    set y [expr {$y + [winfo y $W] + [winfo y [winfo parent $W]]}]
    set idx [$mclb containing $y]

    if {$idx >= 0 && $idx < [llength $exception_context_list]} {
        set selected_context_index $idx
        set pc [lindex [lindex $exception_context_list $idx] 2]
        set pc_in_decimal [expr $pc]        
        $iss show_in_code $pc_in_decimal
    }
}


IssException instproc set_state {new_state} {
my instvar iss top state paned_window info context mclb \
    exception_type file_name line_number expression ext1 ext2 ext3 code1 code2 execution_unit \
    exception_context_list selected_context_index current_window
    
    # Keep state for use in redraw method
    set state $new_state
    
    if {$state eq "run"} {
        set exception_type 0
    } elseif {$state eq "normal"} {
    }
}

IssException instproc redraw {} {
my instvar iss top state paned_window info context mclb \
    exception_type file_name line_number expression ext1 ext2 ext3 code1 code2 execution_unit \
    exception_context_list selected_context_index current_window

    if {$state == "run"} {
        if {$current_window != "NONE"} {
            destroy $info
            destroy $context
        }
        set current_window NONE
        return
    }

    set output [OSA_communication $iss exception]    

    set exception_type [lindex $output 0]
    
    if {$exception_type == "NONE"} {
        if {$current_window != "NONE"} {
            destroy $info
            destroy $context
        }
        set current_window NONE
        return
    }
    
    if {$exception_type == "ASSERT" || $exception_type == "EXT ASSERT"} {
        set file_name [lindex $output 1]
        set line_number [lindex $output 2]
        set expression [lindex $output 3]
        set ext1 [lindex $output 4]
        set ext2 [lindex $output 5]
        set ext3 [lindex $output 6]
        set execution_unit [lindex $output 7]
        set context_depth [lindex $output 8]
        
        set exception_context_list ""
        set level 0

        for {set i 9} {$i < [llength $output]} {set i [expr $i + 2]} {
            lappend exception_context_list [list $level [lindex $output $i] [lindex $output [expr $i + 1]]]
            incr level
        }
        my showAssert
        set current_window ASSERT
        return
    }
    
    if {$exception_type == "FATAL ERROR"} {
        set code1 [lindex $output 1]
        set code2 [lindex $output 2]
        set execution_unit [lindex $output 3]
        set context_depth [lindex $output 4]
        
        set exception_context_list ""
        set level 0

        for {set i 5} {$i < [llength $output]} {set i [expr $i + 2]} {
            lappend exception_context_list [list $level [lindex $output $i] [lindex $output [expr $i + 1]]]
            incr level
        }
        my showFatalError
        set current_window ASSERT
        return
    }
    
}

IssException instproc showAssert {} {
my instvar iss top state paned_window info context mclb \
    exception_type file_name line_number expression ext1 ext2 ext3 code1 code2 execution_unit \
    exception_context_list selected_context_index current_window

    if {$current_window != "NONE"} {
        destroy $info
        destroy $context
    }

    ################################################
    # info
    ################################################
    set info [ttk::frame $paned_window.info]
    
    set exception_type_label [ttk::label $info.exception_type_label -text "Exception Type"]
    set exception_type_entry [ttk::entry $info.exception_type_entry -textvariable [myvar exception_type] -state readonly -width 40]
    
    set file_name_label [ttk::label $info.file_name_label -text "File name"]
    set file_name_entry [ttk::entry $info.file_name_entry -textvariable [myvar file_name] -state readonly -width 40]
    
    set line_number_label [ttk::label $info.line_number_label -text "Line_number"]
    set line_number_entry [ttk::entry $info.line_number_entry -textvariable [myvar line_number] -state readonly -width 40]
    
    set expression_label [ttk::label $info.expression_label -text "Expression"]
    set expression_entry [ttk::entry $info.expression_entry -textvariable [myvar expression] -state readonly -width 40]
    
    set execution_unit_label [ttk::label $info.execution_unit_label -text "Execution unit"]
    set execution_unit_entry [ttk::entry $info.execution_unit_entry -textvariable [myvar execution_unit] -state readonly -width 40]
    
    set ext1_label [ttk::label $info.ext1_label -text "ext1"]
    set ext1_entry [ttk::entry $info.ext1_entry -textvariable [myvar ext1] -state readonly -width 40]

    set ext2_label [ttk::label $info.ext2_label -text "ext2"]
    set ext2_entry [ttk::entry $info.ext2_entry -textvariable [myvar ext2] -state readonly -width 40]

    set ext3_label [ttk::label $info.ext3_label -text "ext3"]
    set ext3_entry [ttk::entry $info.ext3_entry -textvariable [myvar ext3] -state readonly -width 40]    

    grid $exception_type_label $exception_type_entry -sticky ewns
    grid $file_name_label $file_name_entry -sticky ewns
    grid $line_number_label $line_number_entry -sticky ewns
    grid $expression_label $expression_entry -sticky ewns
    grid $execution_unit_label $execution_unit_entry -sticky ewns
    grid $ext1_label $ext1_entry -sticky ewns
    grid $ext2_label $ext2_entry -sticky ewns
    grid $ext3_label $ext3_entry -sticky ewns


    ################################################
    # context
    ################################################
    set context [ttk::frame $paned_window.context]
    set mclb [tablelist::tablelist $context.mclb -spacing 0 -showseparators yes -selectmode extended \
          -labelcommand tablelist::sortByColumn -font TkFixedFont \
          -xscrollcommand [list $context.sx set] -yscrollcommand [list $context.sy set] \
          -incrarrowtype down -listvariable [myvar exception_context_list] -activestyle none \
          -selectborderwidth 0 -selectbackground $::color(selectbackground) -selectforeground $::color(selectforeground) \
          -columns {
              0 "level" left
              0 "function name" left
              0 "pc" left              
          }]
    $mclb columnconfigure 0 -editable 0 -hide 0 -sortmode integer
    $mclb columnconfigure 1 -editable 0 -hide 0 -sortmode dictionary    
    $mclb columnconfigure 2 -editable 0 -hide 0 -sortmode integer
    
    set sx [ttk::scrollbar $context.sx -orient horizontal -command [list $mclb xview]]
    set sy [ttk::scrollbar $context.sy -orient vertical -command [list $mclb yview]]
    grid $mclb $sy -sticky ewns
    grid $sx -sticky ewns
    grid columnconfigure $context 0 -weight 1
    grid rowconfigure $context 0 -weight 1

    ################################################
    # pack
    ################################################
    $paned_window add $info
    $paned_window add $context    
    pack $paned_window -expand 1 -fill both
    
    ################################################
    # bind
    ################################################    
    bind [$mclb bodytag] <Button-1> "[myproc showInCode %y %W]"
    
}

IssException instproc showFatalError {} {
my instvar iss top state paned_window info context mclb \
    exception_type file_name line_number expression ext1 ext2 ext3 code1 code2 execution_unit \
    exception_context_list selected_context_index current_window

    if {$current_window != "NONE"} {
        destroy $info
        destroy $context
    }

    ################################################
    # info
    ################################################
    set info [ttk::frame $paned_window.info]
    
    set exception_type_label [ttk::label $info.exception_type_label -text "Exception Type"]
    set exception_type_entry [ttk::entry $info.exception_type_entry -textvariable [myvar exception_type] -state readonly -width 40]
    
    set file_name_label [ttk::label $info.file_name_label -text "code 1"]
    set file_name_entry [ttk::entry $info.file_name_entry -textvariable [myvar code1] -state readonly -width 40]
    
    set line_number_label [ttk::label $info.line_number_label -text "code 2"]
    set line_number_entry [ttk::entry $info.line_number_entry -textvariable [myvar code2] -state readonly  -width 40]
    
    set execution_unit_label [ttk::label $info.execution_unit_label -text "Execution unit"]
    set execution_unit_entry [ttk::entry $info.execution_unit_entry -textvariable [myvar execution_unit] -state readonly  -width 40]
    
    grid $exception_type_label $exception_type_entry -sticky ewns
    grid $file_name_label $file_name_entry -sticky ewns
    grid $line_number_label $line_number_entry -sticky ewns
    grid $execution_unit_label $execution_unit_entry -sticky ewns

    ################################################
    # context
    ################################################
    set context [ttk::frame $paned_window.context]
    set mclb [tablelist::tablelist $context.mclb -spacing 0 -showseparators yes -selectmode extended \
          -labelcommand tablelist::sortByColumn -font TkFixedFont \
          -xscrollcommand [list $context.sx set] -yscrollcommand [list $context.sy set] \
          -incrarrowtype down -listvariable [myvar exception_context_list] -activestyle none \
          -selectborderwidth 0 -selectbackground $::color(selectbackground) -selectforeground $::color(selectforeground) \
          -columns {
              0 "level" left
              0 "function name" left
              0 "pc" left              
          }]
    $mclb columnconfigure 0 -editable 0 -hide 0 -sortmode integer
    $mclb columnconfigure 1 -editable 0 -hide 0 -sortmode dictionary    
    $mclb columnconfigure 2 -editable 0 -hide 0 -sortmode integer
    
    set sx [ttk::scrollbar $context.sx -orient horizontal -command [list $mclb xview]]
    set sy [ttk::scrollbar $context.sy -orient vertical -command [list $mclb yview]]
    grid $mclb $sy -sticky ewns
    grid $sx -sticky ewns
    grid columnconfigure $context 0 -weight 1
    grid rowconfigure $context 0 -weight 1

    ################################################
    # pack
    ################################################
    $paned_window add $info
    $paned_window add $context    
    pack $paned_window -expand 1 -fill both
    
    ################################################
    # bind
    ################################################    
    bind [$mclb bodytag] <Button-1> "[myproc showInCode %y %W]"
}

project iss add_plugin IssException -view "IssExceptionView" -title "exception"