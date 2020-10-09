/******************************************************************************
#*
#* The confidential and proprietary information contained in this file may
#* only be used by a person authorised under and to the extent permitted
#* by a subsisting licensing agreement from ARM Limited.
#*
#*                 (C) COPYRIGHT 2007-2008 ARM Limited.
#*                       ALL RIGHTS RESERVED
#*
#* This entire notice must be reproduced on all copies of this file
#* and copies of this file may only be made by a person if such person is
#* permitted to do so under the terms of a subsisting license agreement
#* from ARM Limited.
#*
#*               Dormant handling code 
#*              ======================
#*
#*      Origin: cortexr4_generic
#*      SVN Information
#*      Checked In          : $Date: 2008-03-11 14:56:14 +0000 (Tue, 11 Mar 2008) $
#*      Revision            : $Revision: 25009 $
#*      Release Information :
#*
#*
#******************************************************************************/
/* Important. Don't forget to include: */
#include "cortexr4_dorm_macros_gcc.hs"
#if defined(__PCORE__) 
#include "rstctl_reg.h"
#endif
.equ DORMANT_ENTER_CPU_BU,       0xDA01  /* Enter CPU Backup */
.equ DORMANT_EXIT_CPU_BU ,       0xDA02
.equ DORMANT_ENTER_WFI,          0xDA3F  /* Enter WFI */
.equ DORMANT_EXIT_WFI_ABORT,     0xDA40  /* WFI dormant abort */
.equ DORMANT_EXIT_WFI_RESET,     0xDA80  /* WFI dormant reset */

/* To get 3G RTR time, turn-on this option definition in dormant_service.c and cortexr4-dormantMode_gcc.S */
/*#define MODEM_3G_RTR_TIME_CHECK 1*/

                .text
                .arm
                .align 2
/*******************************************************************************
*      Configuration and constants
*******************************************************************************/
  .extern dorm_stack
  .extern dorm_emi_backup_buf /* .extern dormant_tcm_storage */
  .extern dorm_tcm_backup_buf /* .extern dormant_mode_storage */
  .extern dormant_mode_abort_reset
  .extern mddbg_restore

/* For Debug Purpose */
/* Time Information */
  .extern dormant_frc_val
  .extern dormant_reset_frc
  .extern dormant_standby_frc
  .extern dormant_abort_frc
  .extern dormant_reset_end_frc

/* Counter Information */
  .extern dormant_reset_count
  .extern dormant_abort_count

#if defined(CACHE_FLUSH_IN_DORMANT)
  .extern dormant_cache_flush_start_frc
#endif /* CACHE_FLUSH_IN_DORMANT */
#if defined(CACHE_FLUSH_IN_DORMANT) || defined(ATEST_DRV_ENABLE)
  .extern dormant_cache_flush_end_frc
#endif /* CACHE_FLUSH_IN_DORMANT || ATEST_DRV_ENABLE */

/*******************************************************************************
*      Dormant mode reset handler
*******************************************************************************/
    .thumb
    .global dormant_mode_reset_interwork
dormant_mode_reset_interwork:
    /* disable branch prediction to avoid the MPU violation */
    MOV r0, #0x2
    MOVW r2, #:lower16:0xFFFE7FFF
    MOVT r2, #:upper16:0xFFFE7FFF
    MRC p15, 0, r1, c1, c0, 1
    AND r1, r1, r2
    LSL r0, r0, #15
    ORR r1, r1, r0
    MCR p15, 0, r1, c1, c0, 1

	/*==================================================================*/
	/* Cortex-R4 Call-Return-Stack(CRS) Initialization                  */
	/*==================================================================*/
		BL    call1
call1:  BL    call2
call2:  BL    call3
call3:  BL    next
next:

    BLX  arm_dormant_reset_handler

@void arm_dormant_reset_handler(void) 
    .arm
    .global arm_dormant_reset_handler
    .type arm_dormant_reset_handler, %function
arm_dormant_reset_handler:
/*   B   arm_dormant_reset_handler */

#if defined(__PCORE__)
/* Kick WDT for WDT kick durning 1T 32K issue */
    LDR r0,=REG_MDRSTCTL_WDTRR
    LDR r1,=RSTCTL_WDTRR_KEY|RSTCTL_WDTRR_WDT_RESTART
    STR r1, [r0]
#endif /* __PCORE__ */


#if defined(__L1CORE__)&&(defined(MT6755)||defined(MT6797)||defined(MT6757)||defined(MT6750S)||defined(MT6750))
	/* Set L1core domain ID */
    LDR r0,=0xF60F0220
    LDR r1,=0x1
    LDR r2,=0x81
    STR r1, [r0]
    STR r2, [r0]
    DSB
#endif /* __L1CORE__ && MT6755 */
#if (defined(__HIF_CLDMA_SUPPORT__) && defined(__PCORE__)) || (defined(__CCCIDEV_SUPPORT__) && defined(__L1CORE__))
    LDR r0, dormant_dbg_ptr_local
    LDR r0, [r0]
    MOVW r1, #DORMANT_EXIT_WFI_RESET
    STR r1, [r0]
#endif /*(__HIF_CLDMA_SUPPORT__ && __PCORE__) || (__CCCIDEV_SUPPORT__ && __L1CORE__)*/

#if defined(MODEM_3G_RTR_TIME_CHECK)
/* get current RTR value */
   LDR r0, dormant_hw_rtr_val
   MOV r1, #0x0
   LDR r0, [r0]
   STR r1, [r0]
   LDR r0, [r0, #0x4]
   LDR r1, dormant_sw_reset_rtr
   STR r0, [r1]
#endif /* MODEM_3G_RTR_TIME_CHECK */

/* get current FRC value */
   LDR r0, dormant_hw_frc_val
   LDR r1, dormant_sw_reset_frc
   LDR r0, [r0]
   LDR r0, [r0]
   STR r0, [r1]

#if defined(CACHE_FLUSH_IN_DORMANT)
/* Invalidate D-cache, I-cache */
    MOV r0,#0 

    MCR p15, 0, r0, c15, c5, 0
    DSB

    MCR p15, 0, r0, c7, c5, 0
    ISB
#endif /* CACHE_FLUSH_IN_DORMANT */

# record reset times
   LDR r0, dormant_reset_round
   LDR r1, [r0]
   ADD r1, #0x1
   STR r1, [r0]

# switch to dormant mode stack
   LDR r0, dormant_sp
   LDR r0, [r0]
   MOV sp, r0
   BLX mddbg_restore    /* Not in HVT flow */

# check whether dormant mode is triggered
   BL  leave_dormant_mode

/* unexpected reset
arm_halt_loop:
   B arm_halt_loop*/
.size arm_dormant_reset_handler, .-arm_dormant_reset_handler

dormant_hw_frc_val:     
                    .long     dormant_frc_val
#if defined(MODEM_3G_RTR_TIME_CHECK)
dormant_hw_rtr_val:     
                    .long     dormant_rtr_val
dormant_sw_reset_rtr:   
                    .long     dormant_reset_rtr
#endif /* MODEM_3G_RTR_TIME_CHECK */
dormant_sw_reset_frc:   
                    .long     dormant_reset_frc
dormant_sw_standby_frc:   
                    .long     dormant_standby_frc
dormant_sw_abort_frc:
                    .long     dormant_abort_frc
dormant_sp:   
                    .long     dorm_stack
dormant_reset_round:
                    .long     dormant_reset_count
dormant_abort_round:
                    .long     dormant_abort_count
dormant_interrupt_func:
                    .long     dormant_mode_abort_reset
dormant_sw_reset_end_frc:
                    .long     dormant_reset_end_frc
#if defined(CACHE_FLUSH_IN_DORMANT)
dormant_sw_cache_flush_start_frc:
                    .long     dormant_cache_flush_start_frc
#endif /* CACHE_FLUSH_IN_DORMANT */
#if defined(CACHE_FLUSH_IN_DORMANT) || defined(ATEST_DRV_ENABLE)
dormant_sw_cache_flush_end_frc:
                    .long     dormant_cache_flush_end_frc
#endif /* CACHE_FLUSH_IN_DORMANT || ATEST_DRV_ENABLE*/

#if (defined(__HIF_CLDMA_SUPPORT__) && defined(__PCORE__)) || (defined(__CCCIDEV_SUPPORT__) && defined(__L1CORE__))
dormant_dbg_ptr_local:
                    .long     dormant_dbg_ptr
#endif /*(__HIF_CLDMA_SUPPORT__ && __PCORE__) || (__CCCIDEV_SUPPORT__ && __L1CORE__)*/

/*------------------------------------------------------------------------------
#     Cortex-R4 dormant mode entry
#     # 
#     The dormant mode DormantSupport() function uses a block of 
#     memory with base address DORMANT_BASE. 
#  
# 
# Assumptions:
# =========== 
#     A Cortex-R4 (ARMv7-R compliant) system
#
#     DORMANT_BASE memory is configured as non-cacheable 
#
#     The primary code support for dormant save/restore is consistent with a 
#     function call from supervisor mode:
#     - DORMANT_BASE passed as an argument in r0
#     - function entered by a BL instruction
#     - function return uses BX lr
#     - execution starts in Supervisor mode 
#
#
#     Instructions are 'clean' and can be read from cache or main memory 
#     Execution of the save context code will not generate an abort
#     There is no saving of debug context
#
# Cortex-R4 and debug through powerdown
# # PLEASE NOTE: Cortex-R4 does _not_ support the ARMv7 OS lock mechanism
#              (DBGOSLSR, DBGPRSR and DBGOSSRR).
#              In addition, the cpu and debug share a single power domain. 
# To maintain a debug connection through the execution of dormant mode save 
# and restore code, power must be maintained to the resources accessed by
# the debugger. 
#
# The ARM debug architecture supports the following mechanisms for this:
# (a) PRCR.DBGNOPWRDWN - part of the core. When asserted, a system power 
#                        controller must not remove power from the 
#                        associated core.
# (b) CDBGPWRUPREQ/ACK - signals in the Debug Access Port (DAP).
#     The signals are global to the debug control domain. The signals
#     are used by a debugger to ensure debug specific resources are
#     powered up and available to it. 
# (c) CSYSPWRUPREQ/ACK - signals in the Debug Access Port (DAP).
#     The signals are redundant in a single power domain. They are used
#     in a split power domain for a debugger to communicate with more 
#     than debug specific resources in a system.
#
#
# System level assumptions:
# #     WFI wakeup events not required for dormant exit are inhibited at 
#     the system level where necessary.
#
#     External AXI activity to the TCMs is suppressed.
#
#     Handshake of power controller, STANDBYWFI, the PL310 IDLE signal
#     and debug (PRCR.DBGNOPWRDWN and CDBGPWRUPREQ/ACK) external to the core.
*/

/*******************************************************************************/
/*      Enter dormant mode */
/*******************************************************************************/

/*void enter_dormant_mode(void) */

    .global  enter_dormant_mode
    .type enter_dormant_mode, %function
enter_dormant_mode:

    PUSH {r0, r1}

    LDR r0, dormant_hw_frc_val
    LDR r1, dormant_sw_standby_frc
    LDR r0, [r0]
    LDR r0, [r0]
    STR r0, [r1]

#if (defined(__HIF_CLDMA_SUPPORT__) && defined(__PCORE__)) || (defined(__CCCIDEV_SUPPORT__) && defined(__L1CORE__))
    LDR r0, dormant_dbg_ptr_local
    LDR r0, [r0]
    MOVW r1, #DORMANT_ENTER_CPU_BU
    STR r1, [r0]
#endif /*(__HIF_CLDMA_SUPPORT__ && __PCORE__) || (__CCCIDEV_SUPPORT__ && __L1CORE__)*/

    LDR r0,dorm_tcm_backup   /* TCM region to keep other register content for lower latency */
    LDR r1,dorm_emi_backup   /* non-cached EMI region to keep information */
                             /* needed before TCM has been configured. */

    DORMANT_SAVE

#if (defined(__HIF_CLDMA_SUPPORT__) && defined(__PCORE__)) || (defined(__CCCIDEV_SUPPORT__) && defined(__L1CORE__))
    LDR r0, dormant_dbg_ptr_local
    LDR r0, [r0]
    MOVW r1, #DORMANT_EXIT_CPU_BU
    STR r1, [r0]
#endif /*(__HIF_CLDMA_SUPPORT__ && __PCORE__) || (__CCCIDEV_SUPPORT__ && __L1CORE__)*/

# switch to dormant mode stack
    LDR r0, dormant_sp
    LDR r0, [r0]
    MOV sp, r0

#if defined(CACHE_FLUSH_IN_DORMANT)
#  Clean Dcache
/* get current FRC value */
   LDR r0, dormant_hw_frc_val
   LDR r1, dormant_sw_cache_flush_start_frc
   LDR r0, [r0]
   LDR r0, [r0]
   STR r0, [r1]
   
/* Clean D-cache */
    BLX cp15_clean_dcache
    DSB
    
#endif /* CACHE_FLUSH_IN_DORMANT */
#if defined(CACHE_FLUSH_IN_DORMANT) || defined(ATEST_DRV_ENABLE)
/* get current FRC value */
   LDR r0, dormant_hw_frc_val
   LDR r1, dormant_sw_cache_flush_end_frc
   LDR r0, [r0]
   LDR r0, [r0]
   STR r0, [r1]
#endif /* CACHE_FLUSH_IN_DORMANT || ATEST_DRV_ENABLE*/

#if (defined(__HIF_CLDMA_SUPPORT__) && defined(__PCORE__)) || (defined(__CCCIDEV_SUPPORT__) && defined(__L1CORE__))
    LDR r0, dormant_dbg_ptr_local
    LDR r0, [r0]
    MOVW r1, #DORMANT_ENTER_WFI
    STR r1, [r0]
#endif /*(__HIF_CLDMA_SUPPORT__ && __PCORE__) || (__CCCIDEV_SUPPORT__ && __L1CORE__)*/

    DSB
    ISB

/*dbg_loop_beforeWFI:
    B dbg_loop_beforeWFI*/

    WFI

/*dbg_loop_afterWFI:
    B dbg_loop_afterWFI*/

#if (defined(__HIF_CLDMA_SUPPORT__) && defined(__PCORE__)) || (defined(__CCCIDEV_SUPPORT__) && defined(__L1CORE__))
    LDR r0, dormant_dbg_ptr_local
    LDR r0, [r0]
    MOVW r1, #DORMANT_EXIT_WFI_ABORT
    STR r1, [r0]
#endif /*(__HIF_CLDMA_SUPPORT__ && __PCORE__) || (__CCCIDEV_SUPPORT__ && __L1CORE__)*/

# record reset times
    LDR r0, dormant_abort_round
    LDR r1, [r0]
    ADD r1, #0x1
    STR r1, [r0]

    # MCU MTCMOS mode is not triggered due to pause abort
    LDR r0, dormant_hw_frc_val
    LDR r1, dormant_sw_abort_frc
    LDR r0, [r0]
    LDR r0, [r0]
    STR r0, [r1]

    # add a log for pause abort event, i.e. MCU did not enter MTCMOS mode
    LDR     r1,dormant_interrupt_func
    BLX     r1

    # restore register content before DORMAN_SAVE
    LDR r12,dorm_tcm_backup          /* TCM region to keep other register content for lower latency */

    ADD     r0,r12,#(DM_BLOCK+4*13)
    LDM     r0,{r1-r4}              /* recover CPSR,SPSR & exclusive */
    CMP     r4,#0
    LDREXEQ r4,[r3]
    MSR     CPSR_fsxc,r1            /* restore the CPSR */
    MSR     SPSR_fsxc,r2            /* restore the SPSR */
    ADD     r0,r12,#DM_BLOCK
    LDM     r0,{r2-r14}             /* restore ARM registers (but r0, r1 and PC) */

    #if defined(__NUCLEUS_VERSION_2__)
    CPS    #MODE_SYS               /* switch back to System mode */
    #endif
    POP {r0, r1}
    # return to caller
    BX lr
.size enter_dormant_mode, .-enter_dormant_mode

#*******************************************************************************
#*      Leave dormant mode
#*******************************************************************************

#void leave_dormant_mode(void) 

    .global  leave_dormant_mode
    .type leave_dormant_mode, %function
leave_dormant_mode:

    LDR r0,dorm_tcm_backup   /* TCM region to keep other register content for lower latency */

    LDR r1,dorm_emi_backup   /* non-cachedable EMI region to keep information */
                             /* needed before TCM has been configured. */

    DORMANT_RESTORE

    LDR r0, dormant_hw_frc_val
    LDR r1, dormant_sw_reset_end_frc
    LDR r0, [r0]
    LDR r0, [r0]
    STR r0, [r1]
    POP {r0, r1}
    BX r14
.size leave_dormant_mode, .-leave_dormant_mode

# Literal pool && backup data buffer
dorm_tcm_backup:      
                    .long     dorm_tcm_backup_buf
dorm_emi_backup:  
                    .long     dorm_emi_backup_buf

#*******************************************************************************
#*      End of code
#*******************************************************************************

        .end
