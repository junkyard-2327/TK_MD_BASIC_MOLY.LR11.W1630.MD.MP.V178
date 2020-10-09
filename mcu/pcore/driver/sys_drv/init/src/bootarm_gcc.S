/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bootarm_gcc.S
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the boot sequence of asm level.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/*************************************************************************/
/*                                                                       */
/*            Copyright (c) 1994 -2000 Accelerated Technology, Inc.      */
/*                                                                       */
/* PROPRIETARY RIGHTS of Accelerated Technology are involved in the      */
/* subject matter of this material.  All manufacturing, reproduction,    */
/* use, and sales rights pertaining to this subject matter are governed  */
/* by the license agreement.  The recipient of this software implicitly  */
/* accepts the terms of the license.                                     */
/*                                                                       */
/*************************************************************************/

/*************************************************************************/
/*                                                                       */
/* FILE NAME                                            VERSION          */
/*                                                                       */
/*      bootarm.s                                   ARM 6/7/9 1.11.19    */
/*                                                                       */
/* COMPONENT                                                             */
/*                                                                       */
/*      IN - Initialization                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This file contains the target processor dependent initialization */
/*      routines and data.                                               */
/*                                                                       */
/*                                                                       */
/* DATA STRUCTURES                                                       */
/*                                                                       */
/*      INT_Vectors                         Interrupt vector table       */
/*                                                                       */
/* FUNCTIONS                                                             */
/*                                                                       */
/*      INT_Initialize                      Target initialization        */
/*      INT_Vectors_Loaded                  Returns a NU_TRUE if all the */
/*                                            default vectors are loaded */
/*      INT_Setup_Vector                    Sets up an actual vector     */
/*                                                                       */
/*                                                                       */
/*************************************************************************/
   #include "asm_def.h"

   CPU_ISA()
   ISA_UNIFIED_SETTING()

#include "reg_base.h"
#include "bootarm.h"

/* Define constants used in low-level initialization.  */

#include "bootarm_var_gcc.inc"

.macro declare_stack name, val=0
   .type \name , %object
   \name :
   .ascii "STACKEND"
   .space \val
   1:
   .size \name , 1b - \name
.endm

/*************************************************************************
 * Macro definition
 *************************************************************************/
#if !defined(__COSIM_BYPASS_DRV__)
    //Normal BootUp Trace
    .macro  INT_TRC trace_id
#if defined(__SP_BOOTTRC_ENABLE__)
        LDR a1, =Init_Magic_Num
        LDR a1, [a1]
        MOV a2, #\trace_id
        BL INC_TRC
#endif
    .endm
    
#else
    
    // Bootup trace for MDM supported RTL CoSim
    .global MDM_HEXPRINT_BASE
    MDM_HEXPRINT_BASE:
        //.word  0xF6020F0C
        .word  0xF0390F54
    .global MDM_INT_INIT_MAGIC
    MDM_INT_INIT_MAGIC:
        .word 0x544E4900
    
    .macro  INT_TRC trace_id
        LDR a1, =MDM_HEXPRINT_BASE
        LDR a1, [a1]
        LDR a2, =MDM_INT_INIT_MAGIC
        LDR a2, [a2]
        ADD a2, a2, #\trace_id
        STR a2, [a1]
    .endm
#endif


   .section ".rodata"
   .align 3

   
//YH: cmm solution for SYNC bypass
   .global  pcore_sync_bypass    
pcore_sync_bypass:               
   .word  0x0

/* used for vector table diagnosis */
/* used to handle abnormal reset in remapping case  */
   .global  LDR_PC_Initialize    
LDR_PC_Initialize:               
   .word  PC_INITIALIZE_VAL      @ ldr pc,INT_Table

/*************************************************************************
 *   Global system stack variable (Setup by the initialization routine)  *
 *************************************************************************/

    .data
    .align 3

    .global  INT_Loaded_Flag
INT_Loaded_Flag:
    .word      0x00000000

/* External ram stack */  
   .align STACK_ALIGN_NUM
declare_stack ABT_Stack_Pool OTHER_STACK_SIZE-8
//ABT_Stack_Pool:
//   .ascii      "STACKEND"
//   .space    OTHER_STACK_SIZE-8

   .align STACK_ALIGN_NUM
declare_stack UND_Stack_Pool OTHER_STACK_SIZE-8
//UND_Stack_Pool:
//   .ascii      "STACKEND"
//   .space    OTHER_STACK_SIZE-8

   .align STACK_ALIGN_NUM
declare_stack FIQ_Stack_Pool FIQ_STACK_SIZE-8
//FIQ_Stack_Pool:
//   .ascii      "STACKEND"
//   .space    FIQ_STACK_SIZE-8

    
 /*
  * NoteXXX: The exception stack space must be allocated in TCM for MT6235/8.
  *          This is because the exception handler is special designed for MT6235/8.
  */

   .align STACK_ALIGN_NUM
   .global   EX_Stack_Pool
declare_stack EX_Stack_Pool EX_STACK_SIZE-8
//EX_Stack_Pool:
//   .ascii      "STACKEND"
//   .space    EX_STACK_SIZE-8

   .section "INTSRAM_RW", "w", %progbits

   .align STACK_ALIGN_NUM
declare_stack IRQ_Stack_Pool IRQ_STACK_SIZE-8
//IRQ_Stack_Pool:
//   .ascii      "STACKEND"
//   .space    IRQ_STACK_SIZE-8
   
   .align STACK_ALIGN_NUM
declare_stack EX_SYS_Stack_Pool EX_SYS_STACK_SIZE-8
//EX_SYS_Stack_Pool:
//   .ascii      "STACKEND"
//   .space    EX_SYS_STACK_SIZE-8
   
Abnormal_info_Pool:
   .space    ABNORMAL_POOL_SIZE

#define STACK_ZI_INIT
#if 1//defined(STACK_ZI_INIT)
   .section "INTSRAM_ZI", "w", %progbits
   
   .align STACK_ALIGN_NUM
   .global   SYS_Stack_Pool
SYS_Stack_Pool:
   .space    SYS_STACK_SIZE
   .size SYS_Stack_Pool, .-SYS_Stack_Pool
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     
   .section "INT_VECTOR_CODE", "ax"
   .align 2

/* Define the global data structures that need to be initialized by this
   routine.  These structures are used to define the system timer management
   HISR.  */


   .global  BOOT_EX_Stack_End


/* Define the ARM60 interrupt vector table, INT_Vectors.  This table is
   assumed to be loaded or copied to address 0.  If coexistence with a
   target-resident-monitor program is required, it is externant to only
   copy the IRQ and possibly the FIQ interrupt vectors in this table into
   the actual table.  The idea is to not mess with the monitor's vectors.  */
@VOID    *INT_Vectors[NU_MAX_VECTORS];

   CPU_ISA()
   ISA_UNIFIED_SETTING()
   FUNC_ATTR(INT_Vectors)
   .global  INT_Vectors
INT_Vectors:
   #if defined(REMAPPING)
      B     INT_Initialize
   #else
      LDR   pc,INT_Table_Local
   #endif
   LDR   pc,(INT_Table_Local + 4)
   LDR   pc,(INT_Table_Local + 8)
   LDR   pc,(INT_Table_Local + 12)
   LDR   pc,(INT_Table_Local + 16)
   LDR   pc,(INT_Table_Local + 20)
   LDR   pc,(INT_Table_Local + 24)
   LDR   pc,(INT_Table_Local + 28)
.size INT_Vectors, .-INT_Vectors


   .global   INT_Table
   
INT_Table:
INT_Table_Local:
INT_Initialize_Addr:  .word   INT_Initialize
Undef_Instr_Addr:     .word   Undef_Instr_ISR
SWI_Addr:             .word   SWI_ISR
Prefetch_Abort_Addr:  .word   Prefetch_Abort_ISR
Data_Abort_Addr:      .word   Data_Abort_ISR
Undefined_Addr:       .word   0              @ NO LONGER USED
IRQ_Handler_Addr:     .word   INT_IRQ_Parse
FIQ_Handler_Addr:     .word   INT_FIQ_Parse

INT_Table_End:

    .text
    .align 3

#include "bootarm_gcc.inc"
   

#if !defined(_NAND_FLASH_BOOTING_) && !defined(_NOR_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
  
ROM_Base_Ptr:
   .word     Image$$ROM$$Base

INT_Table_End_PTR:
   .word     INT_Table_End

#else
   
   #if defined(__SV5_ENABLED__)||defined(__SV5X_ENABLED__)
ROM_Base_Ptr:
   .word     Image$$ROM$$Base

INT_Table_End_PTR:
   .word     INT_Table_End

#endif /* __SV5_ENABLED__ || __SV5X_ENABLED__ */
   
#endif   


Loaded_Flag:
   .word     INT_Loaded_Flag



   #if defined(KAL_ON_NUCLEUS)

   #if defined(__NUCLEUS_VERSION_2__)
@ Nucleus Plus2: rename TCD_System_Stack to ESAL_GE_STK_System_SP
@ and remove TCT_System_Limit
System_Stack:
   .word     ESAL_GE_STK_System_SP
   #else
System_Stack:
   .word     TCD_System_Stack

System_Limit:
   .word     TCT_System_Limit

   #endif
   #else     /* KAL_ON_NUCLEUS */

System_Stack:
   .word     _tx_thread_system_stack_ptr

   #endif   /* KAL_ON_NUCLEUS */

   
BOOT_IRQ_Stack_End:
   .word     IRQ_Stack_Pool+IRQ_STACK_SIZE-4

BOOT_FIQ_Stack_End:
   .word     FIQ_Stack_Pool+FIQ_STACK_SIZE-4

BOOT_ABT_Stack_End:
   .word     ABT_Stack_Pool+OTHER_STACK_SIZE-4

BOOT_UND_Stack_End:
   .word     UND_Stack_Pool+OTHER_STACK_SIZE-4

   .global   BOOT_SYS_Stack_End
BOOT_SYS_Stack_End:
   .word     SYS_Stack_Pool+SYS_STACK_SIZE-4

BOOT_SYS_Stack_End_Local:
   .word     SYS_Stack_Pool+SYS_STACK_SIZE-4
   
BOOT_SYS_Stack:
   .word     SYS_Stack_Pool

BOOT_EX_Stack_End:
   .word     EX_Stack_Pool+EX_STACK_SIZE-0x44

   .global   BOOT_EX_SYS_Stack_End
BOOT_EX_SYS_Stack_End:
   .word     EX_SYS_Stack_Pool+EX_SYS_STACK_SIZE-4

   #if 0//defined(REMAPPING)
/* under construction !*/
/* under construction !*/
   #endif

RAND_NUM_SEED_PTR:
   .word     rand_num_seed

ECO_VERSION_PTR:
   .word     eco_version

ABN_RST_PTR:
   .word     Abnormal_info_Pool

/* Literal Pool */
.global Init_Magic_Num
Init_Magic_Num:
    .word  INIT_MAGIC

@ void INC_TRC(kal_uint32 trace_log1, kal_uint32 trace_log2)
@ {

.global INC_TRC
.type   INC_TRC, %function

INC_TRC:
    MOV     r7, lr
    //#if defined(__SP_BOOTTRC_ENABLE__)
    LDR a3, =g_EMM_BOOTTRC_MAGIC_ADDR
    LDR a3, [a3]
    STR a1, [a3]
    LDR a3, =g_EMM_BOOTTRC_INDEX_ADDR
    LDR a3, [a3]
    STR a2, [a3]
    //#endif
    BX      lr 
.size INC_TRC, .-INC_TRC
@ } /* INC_TRC */


STAC_PATTERN:
    .ascii      "STAC"
KEND_PATTERN:
    .ascii      "KEND"
        

//void INT_StackEnd_Guard(void)
//{
.global INT_StackEnd_Guard
.type   INT_StackEnd_Guard, %function
INT_StackEnd_Guard:
    LDR a1, BOOT_SYS_Stack
    LDR a2, =STAC_PATTERN
    LDR a2, [a2]
    LDR a3, =KEND_PATTERN
    LDR a3, [a3]
    STM a1, {a2,a3}
    BX lr
.size INT_StackEnd_Guard, .-INT_StackEnd_Guard
//}



/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      INT_Initialize                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function sets up the global system stack variable and       */
/*      transfers control to the target independent initialization       */
/*      function INC_Initialize.  Responsibilities of this function      */
/*      include the following:                                           */
/*                                                                       */
/*             - Setup necessary processor/system control registers      */
/*             - Initialize the vector table                             */
/*             - Setup the system stack pointers                         */
/*             - Setup the timer interrupt                               */
/*             - Calculate the timer HISR stack and priority             */
/*             - Calculate the first available memory address            */
/*             - Transfer control to INC_Initialize to initialize all of */
/*               the system components.                                  */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      INC_Initialize                      Common initialization        */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*                                                                       */
/*************************************************************************/
@VOID    INT_Initialize(void)
@{
   .global  INT_Initialize
.type INT_Initialize, %function
INT_Initialize:

    // INT_TRC LABEL_START_INIT
    
@   /* Insure that the processor is in supervisor mode.  */
    MRS   a1,CPSR                            @ Pickup current CPSR
    BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
    ORR   a1,a1,#KERN_MODE                   @ Set the kernel mode bits
    ORR   a1,a1,#LOCKOUT                     @ Insure IRQ/FIQ interrupts are
                                            @ locked out
    MSR   CPSR_cxsf,a1                       @ Setup the new CPSR


    /* restart watchdog in order to avoid the unexpected wdt reset when booting */
    // INT_TRC LABEL_RESTART_WDT
    @ Restart watchdog in order to avoid the unexpected wdt reset when booting
    LDR   a1,=g_WATCHDOG_RESTART_REG            @ Restart watchdog
    LDR   a1,[a1]
    LDR   a2,=g_WATCHDOG_RESTART_VALUE
    LDR   a2,[a2]
    STR   a2,[a1]      


    /* Can not call any function which will use link register before save the abnormal reset value */ 
    /* backup lr and sp for abnormal-reset scenario */
    // INT_TRC LABEL_BACKUP_LRSP
    MOV   v1,lr
    MOV   v2,sp


#if defined(__CR4__)
    /* Set the Normal Exception Vector Selection (0x0) */
    INT_TRC LABEL_SWITCH_VECTOR
    MOV r0, #0
    BL cp15_switch_vector   
#endif


#if defined(__CR4__)
    /* disable branch prediction (branch always not taken) */
    INT_TRC LABEL_DISABLE_BP
    MOV r0, #0x2
    BL cp15_set_bp_policy
#endif


#if defined(__CR4__)
    INT_TRC LABEL_TCM_INIT
    
    /* disable 64-bit read-modify-write of TCMs */
    BL cp15_disable_atcmrmw
    BL cp15_disable_btcmrmw

#if !defined(__TCM_ONLY_LOAD__)
    LDR r0, =Image$$INTSRAM_CODE$$Base
    BL cp15_enable_atcm

    LDR r0, =Image$$INTSRAM_PHYSICAL_BOUNDARY$$Base
    BL cp15_enable_btcm     
#endif
#endif /* __CR4__ */


    /* save backup lr and sp for abnormal-reset scenario */
    INT_TRC  LABEL_SAVE_LRSP
    LDR   a1,ABN_RST_PTR
    STR   v1,[a1]
    STR   v2,[a1,#0x4]


    LDR   a1, BOOT_SYS_Stack_End_Local
    MOV   sp,a1                              @ Setup initial stack pointer


    /* Check if abnormal reset */
    INT_TRC  LABEL_ABN_RST_CHECK
    LDR   a1,ABN_RST_PTR
    BL    INT_SystemReset_Check


    /* Version check should after abnormal reset check    */
    /* to avoid calling tst_sys_trace when abnormal reset */
    /* happends with interrupt disabled                   */
#if defined(__CHIP_VERSION_CHECK__)
    INT_TRC  LABEL_VER_CHECK
    BL    INT_Version_Check
#endif


    INT_TRC  LABEL_GET_RAND_SEED
    BL    INT_GetRandomSeed
    /*
    * NoteXXX: Store the return value of INT_GetRandomSeed 
    *          in r11 temporarily. Thus in the following program r11 should be
    *          used before we store r11 back to rand_num_seed.
    */
    MOV   r11,a1

      
#if !defined(_SIMULATION)
    /* used for PLL setting */
    INT_TRC  LABEL_REG_INIT_EMI
    BL    INT_InitEMIInitCode

    /* used for PLL setting */
    BL     INT_ecoVersion
    LDR   a2, ECO_VERSION_PTR
    STR   a1,[a2]

    /* configure EMI wait state after system stack is set up */
    INT_TRC  LABEL_INT_CONFIG
    BL    INT_Config
#endif


#if !defined(__PCORE_ONLY__)
    INT_TRC  LABEL_L1CORE_VEC_INIT
    /* init L1core vector through TCM backdoor before MPUPreInit to prevent DataAbort */
    BL    INT_L1CoreVectorInit
#endif


#if defined(__CR4__)
    INT_TRC  LABEL_MPU_PRE_INIT
    BLX   MpuPreInit
#endif


#if !defined(_SIMULATION)
    /* Shared Region Initialization */
    INT_TRC  LABEL_REG_INIT_SHARE
    BLX   INT_InitShareRegions
#endif
    
   
#if !defined(__PCORE_ONLY__)
    /* ungate it after share region init completion */
    INT_TRC  LABEL_UNGATE_L1CORE
    BL    INT_UngateL1Core
#endif


#if !defined(_SIMULATION)
    /* Region Initialization */
    /* Do system stack guard pattern init for exception handling requirement */
    /* Note:Do NOT use any TCM data and global variable before here!!! */
    INT_TRC  LABEL_REG_INIT_MAIN
    BL    INT_InitRegions                    @ in regioninit.s
#else
    BLX   RegionInitDummyReference
#endif

    
#if !defined(__PCORE_ONLY__)
    INT_TRC  LABEL_POLLING_L1_REG_INIT
    /* polling L1Core region init done */
    BLX   INT_L1CoreRegionInitPolling
#endif


    /* after INT_InitRegions, we can store the random number seed to rand_num_seed */
    LDR   a2,RAND_NUM_SEED_PTR
    STR   r11,[a2]


    /* Initialize Cache/MMU/MPU */
    INT_TRC  LABEL_CACHE_INIT
    BL    CacheInit


#if defined(__CR4__)
    /* enable branch prediction (normal operation) */
    INT_TRC  LABEL_ENABLE_BP
    MOV r0, #0x0
    BL cp15_set_bp_policy
#endif


    MOV   a1,#1                              @ All vectors are assumed loaded   
    LDR   a2, Loaded_Flag
    STR   a1,[a2,#0]                         @ Initialize loaded flag

    /* Setup system stacks */
    INT_TRC  LABEL_STACK_INIT
#if defined(KAL_ON_NUCLEUS)

    LDR   a1, BOOT_SYS_Stack            

#if !defined(__NUCLEUS_VERSION_2__)
    LDR   a4,System_Limit                    @ Setup initial stack limit
    STR   a1,[a4, #0]                        @ Save stack limit   
#endif

#endif

    LDR   a4, System_Stack
    STR   sp,[a4, #0]                        @ Save stack pointer

    LDR   a3,BOOT_IRQ_Stack_End
    MRS   a1,CPSR                            @ Pickup current CPSR
    BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
    ORR   a1,a1,#IRQ_MODE                    @ Set the IRQ mode bits
    MSR   CPSR_cxsf,a1                       @ Move to IRQ mode
    MOV   sp,a3                              @ Setup IRQ stack pointer
#if defined(__NUCLEUS_VERSION_2__)
    SUB   sp, #8                             @ Nucleus V2 sp adjust
#endif

    LDR   a3,BOOT_FIQ_Stack_End
    MRS   a1,CPSR                            @ Pickup current CPSR
    BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
    ORR   a1,a1,#FIQ_MODE                    @ Set the FIQ mode bits
    MSR   CPSR_cxsf,a1                       @ Move to the FIQ mode
    MOV   sp,a3                              @ Setup FIQ stack pointer
#if defined(__NUCLEUS_VERSION_2__)
    SUB   sp, #8                             @ Nucleus V2 sp adjust
#endif

    LDR   a3,BOOT_ABT_Stack_End
    MRS   a1,CPSR                            @ Pickup current CPSR
    BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
    ORR   a1,a1,#ABORT_MODE                  @ Set the Abort mode bits
    MSR   CPSR_cxsf,a1                       @ Move to the Abort mode
    MOV   sp,a3                              @ Setup Abort stack pointer

    LDR   a3,BOOT_UND_Stack_End
    MRS   a1,CPSR                            @ Pickup current CPSR
    BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
    ORR   a1,a1,#UND_MODE                    @ Set the Undefine mode bits
    MSR   CPSR_cxsf,a1                       @ Move to the Undefine mode
    MOV   sp,a3                              @ Setup Undefine stack pointer

    LDR   a3,BOOT_SYS_Stack_End_Local

    MRS   a1,CPSR                            @ Pickup current CPSR
    BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
#if defined(__NUCLEUS_VERSION_2__)
    ORR   a1,a1,#SUP_MODE                    @ Set the Supervisor mode bits
#else
    ORR   a1,a1,#SYS_MODE                    @ Set the System mode bits
#endif
    MSR   CPSR_cxsf,a1                       @ Move to the System/Supervisor mode
    MOV   sp,a3                              @ Setup System/Supervisor stack pointer

    MRS   a1,CPSR                            @ Pickup current CPSR
    BIC   a1,a1,#MODE_MASK                   @ Clear mode bits
    ORR   a1,a1,#KERN_MODE                   @ Set the kernel running mode bits
    MSR   CPSR_cxsf,a1                       @ All interrupt stacks are setup,

    INT_TRC  LABEL_ASM_DONE
    MOV   a1, #0

#if defined(KAL_ON_NUCLEUS)

    LDR   a4,=INC_Initialize                 @ to high-level initialization
    BX    a4

#else

    LDR   a4,=_tx_initialize_kernel_enter    @ to high-level initialization
    BX    a4
#endif
.size INT_Initialize, .-INT_Initialize
@}



   .end

