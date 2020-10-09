Class OSA -superclass IssPlugin -parameter {iss view top title}
OSA instproc init args {
next
my instvar iss top set state task_enabled semaphore_enabled mutex_enabled timer_enabled event_enabled mail_enabled exception_enabled mpu_enabled
# Add GUI elements as child of $top

set task_enabled 0 
set semaphore_enabled 0
set mutex_enabled 0 
set timer_enabled 0
set event_enabled 0
set mail_enabled 0
set exception_enabled 0
set mpu_enabled 0



set all_cb         [ttk::button $top.all_cb -text "Run All Plug-Ins" -command [myproc run_cmd all]]
set task_cb        [ttk::button $top.task_cb -text "Task" -command [myproc run_cmd task]]
set semaphore_cb   [ttk::button $top.semaphore_cb -text "Semaphore" -command [myproc run_cmd semaphore]]
set mutex_cb       [ttk::button $top.mutex_cb -text "Mutex" -command [myproc run_cmd mutex]]
set timer_cb       [ttk::button $top.timer_cb -text "Timer" -command [myproc run_cmd timer]]
set event_cb       [ttk::button $top.event_cb -text "Event" -command [myproc run_cmd event]]
set mail_cb        [ttk::button $top.mail_cb -text "Mail" -command [myproc run_cmd mail]]
set exception_cb   [ttk::button $top.exception_cb -text "Exception" -command [myproc run_cmd exception]]
set mpu_cb         [ttk::button $top.mpu_cb -text "MPU" -command [myproc run_cmd mpu]]

set test_cb   [ttk::button $top.test_cb -text "Test" -command [myproc run_cmd test]]

source ../../../../../l1core/tools/OSA/tcl/OSA_communication.tcl

grid $all_cb -sticky ewns
grid $task_cb $exception_cb -sticky ewns
grid $semaphore_cb $mutex_cb -sticky ewns
grid $timer_cb $event_cb -sticky ewns
grid $mail_cb -sticky ewns
grid $mpu_cb -sticky ewns

#grid $test_cb -sticky ewns
}

OSA instproc run_cmd { type } {
my instvar iss top set state task_enabled semaphore_enabled mutex_enabled timer_enabled event_enabled mail_enabled exception_enabled mpu_enabled
    if { ($type == "all" || $type == "task") && $task_enabled == 0 } {
        source ../../../../../l1core/tools/OSA/tcl/OSA_task.tcl
        set task_enabled 1
    }
    
    if { ($type == "all" || $type == "semaphore") && $semaphore_enabled == 0 } {
        source ../../../../../l1core/tools/OSA/tcl/OSA_semaphore.tcl
        set semaphore_enabled 1
    }
    
    if { ($type == "all" || $type == "mutex") && $mutex_enabled == 0 } {
        source ../../../../../l1core/tools/OSA/tcl/OSA_mutex.tcl
        set mutex_enabled 1
    }
    
    if { ($type == "all" || $type == "timer") && $timer_enabled == 0 } {
        source ../../../../../l1core/tools/OSA/tcl/OSA_timer.tcl
        set timer_enabled 1
    }
    
    if { ($type == "all" || $type == "event") && $event_enabled == 0 } {
        source ../../../../../l1core/tools/OSA/tcl/OSA_event.tcl
        set event_enabled 1
    }
    
    if { ($type == "all" || $type == "mail") && $mail_enabled == 0 } {
        source ../../../../../l1core/tools/OSA/tcl/OSA_mail.tcl
        set mail_enabled 1
    }
    
    if { ($type == "all" || $type == "exception") && $exception_enabled == 0 } {
        source ../../../../../l1core/tools/OSA/tcl/OSA_exception.tcl
        set exception_enabled 1
    }
    
    if { ($type == "all" || $type == "mpu") && $mpu_enabled == 0 } {
        source ../../../../../l1core/tools/OSA/tcl/OSA_mpu.tcl
        set mpu_enabled 1
    }
    
    if { $type == "test" } {
        source test.tcl
    }
}

OSA instproc set_state {new_state} {
my instvar iss top set state task_enabled semaphore_enabled mutex_enabled timer_enabled event_enabled mail_enabled exception_enabled mpu_enabled
}

OSA instproc redraw {} {
my instvar iss top set state task_enabled semaphore_enabled mutex_enabled timer_enabled event_enabled mail_enabled exception_enabled mpu_enabled
}

project iss add_plugin OSA -view "OSAView" -title "OS Awareness"