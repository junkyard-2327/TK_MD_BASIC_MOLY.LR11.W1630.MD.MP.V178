/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *   cmif.c
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   
 *   
 *
 * Author:
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
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_cmif.h"

#include "intrCtrl.h"
#include "kal_public_api.h"
#include "kal_general_types.h"


/*******************************************************************************
  * Register List 
  *******************************************************************************/
// BRP
#define CMIF_C2M_U3G_BRP_STATUS     ((volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_C2M_U3G_BRP_INTERRUPT_STATUS_OFFSET))
#define CMIF_C2M_U3G_BRP_SET        ((volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_C2M_U3G_BRP_INTERRUPT_SET_OFFSET))
#define CMIF_M2C_U3G_BRP_STATUS     ((volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_M2C_U3G_BRP_INTERRUPT_STATUS_OFFSET))
#define CMIF_M2C_U3G_BRP_CLEAN      ((volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_M2C_U3G_BRP_INTERRUPT_CLEAN_OFFSET))
#define CMIF_C2M_U4G_BRP_STATUS     ((volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_C2M_U4G_BRP_INTERRUPT_STATUS_OFFSET))
#define CMIF_C2M_U4G_BRP_SET        ((volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_C2M_U4G_BRP_INTERRUPT_SET_OFFSET))
#define CMIF_M2C_U4G_BRP_STATUS     ((volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_M2C_U4G_BRP_INTERRUPT_STATUS_OFFSET))
#define CMIF_M2C_U4G_BRP_CLEAN      ((volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_M2C_U4G_BRP_INTERRUPT_CLEAN_OFFSET))

// RAKE
#define CMIF_C2M_U3G_RAKE_STATUS    ((volatile cmif_uint32*)(CMIF_CR4_RAKE_BASE_ADDR + CMIF_C2M_U3G_RAKE_INTERRUPT_STATUS_OFFSET))
#define CMIF_C2M_U3G_RAKE_SET       ((volatile cmif_uint32*)(CMIF_CR4_RAKE_BASE_ADDR + CMIF_C2M_U3G_RAKE_INTERRUPT_SET_OFFSET))
#define CMIF_M2C_U3G_RAKE_STATUS    ((volatile cmif_uint32*)(CMIF_CR4_RAKE_BASE_ADDR + CMIF_M2C_U3G_RAKE_INTERRUPT_STATUS_OFFSET))
#define CMIF_M2C_U3G_RAKE_CLEAN     ((volatile cmif_uint32*)(CMIF_CR4_RAKE_BASE_ADDR + CMIF_M2C_U3G_RAKE_INTERRUPT_CLEAN_OFFSET))

// DFE
#define CMIF_C2M_U3G_DFE_STATUS     ((volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_C2M_U3G_DFE_INTERRUPT_STATUS_OFFSET))
#define CMIF_C2M_U3G_DFE_SET        ((volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_C2M_U3G_DFE_INTERRUPT_SET_OFFSET))
#define CMIF_M2C_U3G_DFE_STATUS     ((volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_M2C_U3G_DFE_INTERRUPT_STATUS_OFFSET))
#define CMIF_M2C_U3G_DFE_CLEAN      ((volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_M2C_U3G_DFE_INTERRUPT_CLEAN_OFFSET))
#define CMIF_C2M_U4G_DFE_STATUS     ((volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_C2M_U4G_DFE_INTERRUPT_STATUS_OFFSET))
#define CMIF_C2M_U4G_DFE_SET        ((volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_C2M_U4G_DFE_INTERRUPT_SET_OFFSET))
#define CMIF_M2C_U4G_DFE_STATUS     ((volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_M2C_U4G_DFE_INTERRUPT_STATUS_OFFSET))
#define CMIF_M2C_U4G_DFE_CLEAN      ((volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_M2C_U4G_DFE_INTERRUPT_CLEAN_OFFSET))


/*******************************************************************************
 * Data Structure 
 *******************************************************************************/
#undef  irq_index
#undef  irq_name 
#undef  irq_entry_function 
#undef  irq_auto_eoi

#define irq_index(code)  
#define irq_name(name)
#define irq_entry_function(fun_name) extern void fun_name(CMIF_Mask_t*);
#define irq_auto_eoi(eoi)

#include "cmif_m2c_isr_config_u3g_brp.h"
#include "cmif_m2c_isr_config_u3g_dfe.h"
#include "cmif_m2c_isr_config_u3g_rake.h"
#include "cmif_m2c_isr_config_u4g_brp.h"
#include "cmif_m2c_isr_config_u4g_dfe.h"

#undef  irq_index
#undef  irq_name 
#undef  irq_entry_function 
#undef  irq_auto_eoi

#define irq_index(code)  
#define irq_name(name)
#define irq_entry_function(fun_name) fun_name, 
#define irq_auto_eoi(eoi)

CMIF_InterruptEntryFun cmif_isr_handler_u3g_brp[] = {
    #include "cmif_m2c_isr_config_u3g_brp.h"
};
CMIF_InterruptEntryFun cmif_isr_handler_u3g_dfe[] = {
    #include "cmif_m2c_isr_config_u3g_dfe.h"
};
CMIF_InterruptEntryFun cmif_isr_handler_u3g_rake[] = {
    #include "cmif_m2c_isr_config_u3g_rake.h"
};
CMIF_InterruptEntryFun cmif_isr_handler_u4g_brp[] = {
    #include "cmif_m2c_isr_config_u4g_brp.h"
};
CMIF_InterruptEntryFun cmif_isr_handler_u4g_dfe[] = {
    #include "cmif_m2c_isr_config_u4g_dfe.h"
};

#undef  irq_index
#undef  irq_name 
#undef  irq_entry_function 
#undef  irq_auto_eoi

#define irq_index(code)  
#define irq_name(name)
#define irq_entry_function(fun_name)  
#define irq_auto_eoi(eoi)    eoi,

cmif_bool cmif_isr_eoi_u3g_brp[] = {
    #include "cmif_m2c_isr_config_u3g_brp.h"
};

cmif_bool cmif_isr_eoi_u3g_dfe[] = {
    #include "cmif_m2c_isr_config_u3g_dfe.h"
};

cmif_bool cmif_isr_eoi_u3g_rake[] = {
    #include "cmif_m2c_isr_config_u3g_rake.h"
};

cmif_bool cmif_isr_eoi_u4g_brp[] = {
    #include "cmif_m2c_isr_config_u4g_brp.h"
};

cmif_bool cmif_isr_eoi_u4g_dfe[] = {
    #include "cmif_m2c_isr_config_u4g_dfe.h"
};

/*******************************************************************************
 * Debug 
 *******************************************************************************/
#if defined(__CMIF_DEBUG__)

#define CMIF_DEBUG_CR4_U3G_SIZE            3
#define CMIF_DEBUG_CR4_U4G_SIZE            2

CMIF_DebugISRCodeList cmif_debug_isr_handle_u3g[CMIF_DEBUG_CR4_U3G_SIZE];
CMIF_DebugISRCodeList cmif_debug_isr_handle_u4g[CMIF_DEBUG_CR4_U4G_SIZE]; 

CMIF_DebugRecordList cmif_debug_records;
#endif



/*******************************************************************************
 * Function prototypes
 *******************************************************************************/
#if !defined(__CMIF_DEBUG__)
extern void cmif_InterruptHandlerInternal(volatile cmif_uint32* sreg,
                                          volatile cmif_uint32* creg,
                                          CMIF_InterruptEntryFun* handler,
                                          cmif_bool* auto_eoi);
#else     /* __CMIF_DEBUG__ */
extern void cmif_InterruptHandlerInternal(volatile cmif_uint32* sreg,
                                          volatile cmif_uint32* creg,
                                          CMIF_InterruptEntryFun* handler,
                                          cmif_bool* auto_eoi,
                                          CMIF_MD32_Core_t core,
                                          CMIF_DebugInterruptType u3g);
#endif    /* __CMIF_DEBUG__ */

void CMIF_InterruptHandler_U3G_BRP();
void CMIF_InterruptHandler_U4G_BRP();

void CMIF_InterruptHandler_U3G_DFE();
void CMIF_InterruptHandler_U4G_DFE();

void CMIF_InterruptHandler_U3G_RAKE();


/*******************************************************************************
 * Functions - CR4 Part
 *******************************************************************************/
#define CMIF_CHECK_ALLOW_POWER_DOWN_OFFSET          0x2c

#define CMIF_BRP_CHECK_ALLOW_POWER_DOWN_STATUS      ((volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_CHECK_ALLOW_POWER_DOWN_OFFSET))
#define CMIF_DFE_CHECK_ALLOW_POWER_DOWN_STATUS      ((volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_CHECK_ALLOW_POWER_DOWN_OFFSET))
#define CMIF_RAKE_CHECK_ALLOW_POWER_DOWN_STATUS     ((volatile cmif_uint32*)(CMIF_CR4_RAKE_BASE_ADDR + CMIF_CHECK_ALLOW_POWER_DOWN_OFFSET))

#define CMIF_MD32_PATTERN_WFI_SEND                  0x32DE32DE


cmif_bool CMIF_MD32AllowPowerDown(CMIF_MD32_Core_t core){

    cmif_uint32 md32_status = 0;
    switch(core){
        case CMIF_MD32_BRP:
            md32_status = *CMIF_BRP_CHECK_ALLOW_POWER_DOWN_STATUS;
            break;
        case CMIF_MD32_RAKE:
            md32_status = *CMIF_RAKE_CHECK_ALLOW_POWER_DOWN_STATUS;
            break;
        case CMIF_MD32_DFE:
            md32_status = *CMIF_DFE_CHECK_ALLOW_POWER_DOWN_STATUS;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };

    if(md32_status == CMIF_MD32_PATTERN_WFI_SEND){
        return CMIF_TRUE;
    }else{
        return CMIF_FALSE;
    }

}


cmif_uint32 CMIF_C2M_STATUS_U3G_READ(CMIF_MD32_Core_t core){

    cmif_uint32 cmif_u3g_status = 0;

    switch(core){
        case CMIF_MD32_BRP:
            cmif_u3g_status = *CMIF_C2M_U3G_BRP_STATUS;
            break;
        case CMIF_MD32_RAKE:
            cmif_u3g_status = *CMIF_C2M_U3G_RAKE_STATUS;
            break;
        case CMIF_MD32_DFE:
            cmif_u3g_status = *CMIF_C2M_U3G_DFE_STATUS;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };

    return cmif_u3g_status;
}

cmif_uint32 CMIF_C2M_STATUS_U4G_READ(CMIF_MD32_Core_t core){

    cmif_uint32 cmif_u4g_status = 0;

    switch(core){
        case CMIF_MD32_BRP:
            cmif_u4g_status = *CMIF_C2M_U4G_BRP_STATUS;
            break;
        case CMIF_MD32_DFE:
            cmif_u4g_status = *CMIF_C2M_U4G_DFE_STATUS;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };

    return cmif_u4g_status;
}

cmif_uint32 CMIF_M2C_STATUS_U3G_READ(CMIF_MD32_Core_t core){

    cmif_uint32 cmif_u3g_status = 0;

    switch(core){
        case CMIF_MD32_BRP:
            cmif_u3g_status = *CMIF_M2C_U3G_BRP_STATUS;
            break;
        case CMIF_MD32_RAKE:
            cmif_u3g_status = *CMIF_M2C_U3G_RAKE_STATUS;
            break;
        case CMIF_MD32_DFE:
            cmif_u3g_status = *CMIF_M2C_U3G_DFE_STATUS;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };

    return cmif_u3g_status;

}


cmif_uint32 CMIF_M2C_STATUS_U4G_READ(CMIF_MD32_Core_t core){
    
    cmif_uint32 cmif_u4g_status = 0;

    switch(core){
        case CMIF_MD32_BRP:
            cmif_u4g_status = *CMIF_M2C_U4G_BRP_STATUS;
            break;
        case CMIF_MD32_DFE:
            cmif_u4g_status = *CMIF_M2C_U4G_DFE_STATUS;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };

    return cmif_u4g_status;

}


void CMIF_Init()
{
    // debugging purpose, these variable is useless. Just for save data structure in elf files
    volatile MD32_EX_Log*  cmif_brp_3g_handler = (volatile MD32_EX_Log*)(CMIF_InterruptHandler_U3G_BRP);
    volatile MD32_EX_CMIF_Log*  cmif_dfe_3g_handler = (volatile MD32_EX_CMIF_Log*)(CMIF_InterruptHandler_U3G_DFE);

    // register u3g brp interrupt handler
    IRQ_Register_LISR(IRQ_RXBRP_M2C_1_CODE, (void*)cmif_brp_3g_handler, "CMIF_U3G_BRP");
    IRQSensitivity(IRQ_RXBRP_M2C_1_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_RXBRP_M2C_1_CODE);

    // register u3g dfe interrupt handler
    IRQ_Register_LISR(IRQ_DFE_M2C_1_CODE, (void*)cmif_dfe_3g_handler, "CMIF_U3G_DFE");
    IRQSensitivity(IRQ_DFE_M2C_1_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_DFE_M2C_1_CODE);

    // register u3g rake interrupt handler
    IRQ_Register_LISR(IRQ_INR_M2C_1_CODE, CMIF_InterruptHandler_U3G_RAKE, "CMIF_U3G_RAKE");
    IRQSensitivity(IRQ_INR_M2C_1_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_INR_M2C_1_CODE);

    // register u4g brp interrupt handler
    IRQ_Register_LISR(IRQ_RXBRP_M2C_2_CODE, CMIF_InterruptHandler_U4G_BRP, "CMIF_U4G_BRP");
    IRQSensitivity(IRQ_RXBRP_M2C_2_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_RXBRP_M2C_2_CODE);

    // register u4g dfe interrupt handler
    IRQ_Register_LISR(IRQ_DFE_M2C_2_CODE, CMIF_InterruptHandler_U4G_DFE, "CMIF_U4G_DFE");
    IRQSensitivity(IRQ_DFE_M2C_2_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_DFE_M2C_2_CODE);
}

void CMIF_M2C_STATUS_U3G(CMIF_MD32_Core_t core, CMIF_Mask_t* mask)
{
    switch(core){
        case CMIF_MD32_BRP:
            mask -> mask31_0 = *CMIF_M2C_U3G_BRP_STATUS;
            break;
        case CMIF_MD32_RAKE:
            mask -> mask31_0 = *CMIF_M2C_U3G_RAKE_STATUS;
            break;
        case CMIF_MD32_DFE:
            mask -> mask31_0 = *CMIF_M2C_U3G_DFE_STATUS;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };
}

void CMIF_M2C_STATUS_U4G(CMIF_MD32_Core_t core, CMIF_Mask_t* mask)
{
    switch(core){
        case CMIF_MD32_BRP:
            mask -> mask31_0 = *CMIF_M2C_U4G_BRP_STATUS;
            break;
        case CMIF_MD32_DFE:
            mask -> mask31_0 = *CMIF_M2C_U4G_DFE_STATUS;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };
}

void CMIF_C2M_STATUS_U3G(CMIF_MD32_Core_t core, CMIF_Mask_t* mask)
{
    switch(core){
        case CMIF_MD32_BRP:
            mask -> mask31_0 = *CMIF_C2M_U3G_BRP_STATUS;
            break;
        case CMIF_MD32_RAKE:
            mask -> mask31_0 = *CMIF_C2M_U3G_RAKE_STATUS;
            break;
        case CMIF_MD32_DFE:
            mask -> mask31_0 = *CMIF_C2M_U3G_DFE_STATUS;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };
}

void CMIF_C2M_STATUS_U4G(CMIF_MD32_Core_t core, CMIF_Mask_t* mask)
{
    switch(core){
        case CMIF_MD32_BRP:
            mask -> mask31_0 = *CMIF_C2M_U4G_BRP_STATUS;
            break;
        case CMIF_MD32_DFE:
            mask -> mask31_0 = *CMIF_C2M_U4G_DFE_STATUS;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };
}

void CMIF_C2M_SWI_SW_U3G(cmif_uint8 code, CMIF_MD32_Core_t core)
{
    volatile cmif_uint32* set_addr = CMIF_NULL;
    volatile cmif_uint32* status_addr = CMIF_NULL;
    cmif_uint8 code_size = 32;

    switch(core){
        case CMIF_MD32_BRP:
            set_addr = CMIF_C2M_U3G_BRP_SET;
            status_addr = CMIF_C2M_U3G_BRP_STATUS;
            code_size = CMIF_C2M_U3G_TOTAL_NUMBER_BRP;
            break;
        case CMIF_MD32_RAKE:
            set_addr = CMIF_C2M_U3G_RAKE_SET;
            status_addr = CMIF_C2M_U3G_RAKE_STATUS;
            code_size = CMIF_C2M_U3G_TOTAL_NUMBER_RAKE;
            break;
        case CMIF_MD32_DFE:
            set_addr = CMIF_C2M_U3G_DFE_SET;
            status_addr = CMIF_C2M_U3G_DFE_STATUS;
            code_size = CMIF_C2M_U3G_TOTAL_NUMBER_DFE;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };
   
    // check the code in the range
    CMIF_ASSERT(code < code_size);

    // avoid set the same interrupt again 
    CMIF_ASSERT(((CMIF_REG_READ(status_addr) >> code) & 0x1) == 0);

#if defined(__CMIF_DEBUG__)
    cmif_uint32 caller;

    CMIF_Mask_t before;
    CMIF_Mask_t after;

    CMIF_REG_WRITE(before.mask31_0, status_addr);
#endif /* __CMIF_DEBUG__ */

    // set the status bit to send the interrupt
    CMIF_REG_WRITE(set_addr, 1 << code);

#if defined(__CMIF_DEBUG__)
    after.mask31_0 = CMIF_REG_READ(status_addr);
    CMIF_GET_RETURN_ADDRESS(caller);
    cmif_DebugAddRecord(&before, &after, (cmif_uint32)set_addr, (1 << code), caller);
#endif /* __CMIF_DEBUG__ */
}

void CMIF_C2M_SWI_SW_U4G(cmif_uint8 code, CMIF_MD32_Core_t core)
{
    volatile cmif_uint32* set_addr= CMIF_NULL;
    volatile cmif_uint32* status_addr = CMIF_NULL;
    cmif_uint8 code_size = 32;

    switch(core){
        case CMIF_MD32_BRP:
            set_addr = CMIF_C2M_U4G_BRP_SET;
            status_addr = CMIF_C2M_U4G_BRP_STATUS;
            code_size = CMIF_C2M_U4G_TOTAL_NUMBER_BRP;
            break;
        case CMIF_MD32_DFE:
            set_addr = CMIF_C2M_U4G_DFE_SET;
            status_addr = CMIF_C2M_U4G_DFE_STATUS;
            code_size = CMIF_C2M_U4G_TOTAL_NUMBER_DFE;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };

    // check the code in the range
    CMIF_ASSERT(code < code_size);

    // avoid set the same interrupt again 
    CMIF_ASSERT(((CMIF_REG_READ(status_addr) >> code) & 0x1) == 0);

#if defined(__CMIF_DEBUG__)
    cmif_uint32 caller;

    CMIF_Mask_t before;
    CMIF_Mask_t after;

    CMIF_REG_WRITE(before.mask31_0, status_addr);
#endif /* __CMIF_DEBUG__ */

    CMIF_REG_WRITE(set_addr, 1 << code);

#if defined(__CMIF_DEBUG__)
    after.mask31_0 = CMIF_REG_READ(status_addr);
    CMIF_GET_RETURN_ADDRESS(caller);
    cmif_DebugAddRecord(&before, &after, (cmif_uint32)set_addr, (1 << code), caller);
#endif /* __CMIF_DEBUG__ */
}

void CMIF_M2C_EOI_U3G(cmif_uint8 code, CMIF_MD32_Core_t core)
{
    volatile cmif_uint32* clear_addr= CMIF_NULL;
    volatile cmif_uint32* status_addr = CMIF_NULL;
    cmif_uint8 code_size = 32;

    switch(core){
        case CMIF_MD32_BRP:
            clear_addr = CMIF_M2C_U3G_BRP_CLEAN;
            status_addr = CMIF_M2C_U3G_BRP_STATUS;
            code_size = CMIF_M2C_U3G_TOTAL_NUMBER_BRP;
            break;
        case CMIF_MD32_RAKE:
            clear_addr = CMIF_M2C_U3G_RAKE_CLEAN;
            status_addr = CMIF_M2C_U3G_RAKE_STATUS;
            code_size = CMIF_M2C_U3G_TOTAL_NUMBER_RAKE;
            break;
        case CMIF_MD32_DFE:
            clear_addr = CMIF_M2C_U3G_DFE_CLEAN;
            status_addr = CMIF_M2C_U3G_DFE_STATUS;
            code_size = CMIF_M2C_U3G_TOTAL_NUMBER_DFE;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };
    
    // check the code in the range
    CMIF_ASSERT(code < code_size);

    // avoid set the same interrupt again 
    CMIF_ASSERT(((CMIF_REG_READ(status_addr) >> code) & 0x1) == 1);
    
#if defined(__CMIF_DEBUG__)
    cmif_uint32 caller;

    CMIF_Mask_t before;
    CMIF_Mask_t after;

    CMIF_REG_WRITE(before.mask31_0, status_addr);
#endif /* __CMIF_DEBUG__ */
    
    /* Add this work around to ensure cmif status is cleared correctly */
    /* This hardware bug is existed in TK6291, Jade, Everest */
    /* For C2M IRQ, the same T access will give CR4 higher priority */
    /* For M2C IRQ, the same T access will give MD32 higher priority */
    do{
        CMIF_REG_WRITE(clear_addr, 1 << code);
    }while(((CMIF_REG_READ(status_addr) >> code) & 0x1) == 1);

    /* This assert help us find the hw bug above */
    CMIF_ASSERT(((CMIF_REG_READ(status_addr) >> code) & 0x1) == 0);

#if defined(__CMIF_DEBUG__)
    after.mask31_0 = CMIF_REG_READ(status_addr);
    CMIF_GET_RETURN_ADDRESS(caller);
    cmif_DebugAddRecord(&before, &after, (cmif_uint32)clear_addr, (1 << code), caller);
#endif /* __CMIF_DEBUG__ */

}

void CMIF_M2C_EOI_U4G(cmif_uint8 code, CMIF_MD32_Core_t core)
{
    volatile cmif_uint32* clear_addr= CMIF_NULL;
    volatile cmif_uint32* status_addr = CMIF_NULL;
    cmif_uint8 code_size = 32;

    switch(core){
        case CMIF_MD32_BRP:
            clear_addr = CMIF_M2C_U4G_BRP_CLEAN;
            status_addr = CMIF_M2C_U4G_BRP_STATUS;
            code_size = CMIF_M2C_U4G_TOTAL_NUMBER_BRP;
            break;
        case CMIF_MD32_DFE:
            clear_addr = CMIF_M2C_U4G_DFE_CLEAN;
            status_addr = CMIF_M2C_U4G_DFE_STATUS;
            code_size = CMIF_M2C_U4G_TOTAL_NUMBER_DFE;
            break;
        default:
            CMIF_ASSERT(0);
            break;
    };
    
    // check the code in the range
    CMIF_ASSERT(code < code_size);

    // avoid set the same interrupt again 
    CMIF_ASSERT(((CMIF_REG_READ(status_addr) >> code) & 0x1) == 1);

#if defined(__CMIF_DEBUG__)
    cmif_uint32 caller;

    CMIF_Mask_t before;
    CMIF_Mask_t after;

    CMIF_REG_WRITE(before.mask31_0, status_addr);
#endif /* __CMIF_DEBUG__ */

    /* Add this work around to ensure cmif status is cleared correctly */
    /* This hardware bug is existed in TK6291, Jade, Everest */
    /* For C2M IRQ, the same T access will give CR4 higher priority */
    /* For M2C IRQ, the same T access will give MD32 higher priority */
    do{
        CMIF_REG_WRITE(clear_addr, 1 << code);
    }while(((CMIF_REG_READ(status_addr) >> code) & 0x1) == 1);

    /* This assert help us find the hw bug above */
    CMIF_ASSERT(((CMIF_REG_READ(status_addr) >> code) & 0x1) == 0);

#if defined(__CMIF_DEBUG__)
    after.mask31_0 = CMIF_REG_READ(status_addr);
    CMIF_GET_RETURN_ADDRESS(caller);
    cmif_DebugAddRecord(&before, &after, (cmif_uint32)clear_addr, (1 << code), caller);
#endif /* __CMIF_DEBUG__ */
}

/**
  *  CMIF Interrupt handler: MD32 trigger CR4 
  *
  **/
void CMIF_InterruptHandler_U3G_BRP()
{
#if !defined(__CMIF_DEBUG__)
    cmif_InterruptHandlerInternal(CMIF_M2C_U3G_BRP_STATUS,
                                  CMIF_M2C_U3G_BRP_CLEAN,
                                  cmif_isr_handler_u3g_brp,
                                  cmif_isr_eoi_u3g_brp);
#else    /* __CMIF_DEBUG__  */
    cmif_InterruptHandlerInternal(CMIF_M2C_U3G_BRP_STATUS,
                                  CMIF_M2C_U3G_BRP_CLEAN,
                                  cmif_isr_handler_u3g_brp,
                                  cmif_isr_eoi_u3g_brp,
                                  CMIF_MD32_BRP,
                                  CMIF_DEBUG_U3G_INTERRUPT);
#endif   /* __CMIF_DEBUG__  */
}

/**
  *  CMIF Interrupt handler: MD32 trigger CR4 
  *
  **/
void CMIF_InterruptHandler_U4G_BRP()
{
#if !defined(__CMIF_DEBUG__)
    cmif_InterruptHandlerInternal(CMIF_M2C_U4G_BRP_STATUS,
                                  CMIF_M2C_U4G_BRP_CLEAN,
                                  cmif_isr_handler_u4g_brp,
                                  cmif_isr_eoi_u4g_brp);
#else    /* __CMIF_DEBUG__  */
    cmif_InterruptHandlerInternal(CMIF_M2C_U4G_BRP_STATUS,
                                  CMIF_M2C_U4G_BRP_CLEAN,
                                  cmif_isr_handler_u4g_brp,
                                  cmif_isr_eoi_u4g_brp,
                                  CMIF_MD32_BRP,
                                  CMIF_DEBUG_U4G_INTERRUPT);
#endif   /* __CMIF_DEBUG__  */
}

/**
  *  CMIF Interrupt handler: MD32 trigger CR4 
  *
  **/
void CMIF_InterruptHandler_U3G_DFE()
{
#if !defined(__CMIF_DEBUG__)
    cmif_InterruptHandlerInternal(CMIF_M2C_U3G_DFE_STATUS,
                                  CMIF_M2C_U3G_DFE_CLEAN,
                                  cmif_isr_handler_u3g_dfe,
                                  cmif_isr_eoi_u3g_dfe);
#else    /* __CMIF_DEBUG__  */
    cmif_InterruptHandlerInternal(CMIF_M2C_U3G_DFE_STATUS,
                                  CMIF_M2C_U3G_DFE_CLEAN,
                                  cmif_isr_handler_u3g_dfe,
                                  cmif_isr_eoi_u3g_dfe,
                                  CMIF_MD32_DFE,
                                  CMIF_DEBUG_U3G_INTERRUPT);
#endif   /* __CMIF_DEBUG__  */
}

/**
  *  CMIF Interrupt handler: MD32 trigger CR4 
  *
  **/
void CMIF_InterruptHandler_U4G_DFE()
{
#if !defined(__CMIF_DEBUG__)
    cmif_InterruptHandlerInternal(CMIF_M2C_U4G_DFE_STATUS,
                                  CMIF_M2C_U4G_DFE_CLEAN,
                                  cmif_isr_handler_u4g_dfe,
                                  cmif_isr_eoi_u4g_dfe);
#else    /* __CMIF_DEBUG__  */
    cmif_InterruptHandlerInternal(CMIF_M2C_U4G_DFE_STATUS,
                                  CMIF_M2C_U4G_DFE_CLEAN,
                                  cmif_isr_handler_u4g_dfe,
                                  cmif_isr_eoi_u4g_dfe,
                                  CMIF_MD32_DFE,
                                  CMIF_DEBUG_U4G_INTERRUPT);
#endif   /* __CMIF_DEBUG__  */
}

/**
  *  CMIF Interrupt handler: MD32 trigger CR4 
  *
  **/
void CMIF_InterruptHandler_U3G_RAKE()
{
#if !defined(__CMIF_DEBUG__)
    cmif_InterruptHandlerInternal(CMIF_M2C_U3G_RAKE_STATUS,
                                  CMIF_M2C_U3G_RAKE_CLEAN,
                                  cmif_isr_handler_u3g_rake,
                                  cmif_isr_eoi_u3g_rake);
#else    /* __CMIF_DEBUG__  */
    cmif_InterruptHandlerInternal(CMIF_M2C_U3G_RAKE_STATUS,
                                  CMIF_M2C_U3G_RAKE_CLEAN,
                                  cmif_isr_handler_u3g_rake,
                                  cmif_isr_eoi_u3g_rake,
                                  CMIF_MD32_RAKE,
                                  CMIF_DEBUG_U3G_INTERRUPT);
#endif   /* __CMIF_DEBUG__  */
}


#if defined(__CMIF_DEBUG__)
void cmif_DebugAddISRHandleCode(CMIF_DebugISRCode code,
        CMIF_MD32_Core_t core,
        CMIF_DebugInterruptType isr_type)
{
    CMIF_DebugISRCodeList* code_list = CMIF_NULL;
    cmif_uint32 save_index;

    if(isr_type == CMIF_DEBUG_U3G_INTERRUPT){
        code_list = &cmif_debug_isr_handle_u3g[core];
    }
    else if(isr_type == CMIF_DEBUG_U4G_INTERRUPT){
        code_list = &cmif_debug_isr_handle_u3g[core];
    }

    if(code_list != CMIF_NULL){
        save_index = code_list -> top_index;
            
        ++code_list -> top_index;
        if(code_list -> top_index == CMIF_DEBUG_ISR_HANDLE_CODE_SIZE){
            code_list -> top_index = 0;
        }
        code_list->code[save_index] = code;
    }
}
#endif


/*******************************************************************************
 * Functions - Driver test 
 *******************************************************************************/
#if defined(__MD32S_CMIF_DRV_TEST__)

#define CMIF_DRV_TEST_ASSERT_EQ(a, b)                                               \
    do{                                                                          \
        if((a) != (b)){                                                          \
            while(1); \
        }                                                                        \
    }while(0);

CMIF_Ctrl_t cmif_ctrl_brp_u3g = {
   .send_set              = CMIF_C2M_U3G_BRP_SET,
   .send_status           = CMIF_C2M_U3G_BRP_STATUS, 
   .receive_clr           = CMIF_M2C_U3G_BRP_CLEAN, 
   .receive_status        = CMIF_M2C_U3G_BRP_STATUS, 
   .sync                  = (volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_DRV_TET_SYNC_OFFSET),
   
   .send_func             = CMIF_C2M_SWI_SW_U3G, 
   .send_stats_func       = CMIF_C2M_STATUS_U3G, 
   .receive_clr_func      = CMIF_M2C_EOI_U3G, 
   .receive_stats_func    = CMIF_M2C_STATUS_U3G,
   .md32_core             = CMIF_MD32_BRP
};

CMIF_Ctrl_t cmif_ctrl_brp_u4g = {
   .send_set              = CMIF_C2M_U4G_BRP_SET,
   .send_status           = CMIF_C2M_U4G_BRP_STATUS, 
   .receive_clr           = CMIF_M2C_U4G_BRP_CLEAN, 
   .receive_status        = CMIF_M2C_U4G_BRP_STATUS, 
   .sync                  = (volatile cmif_uint32*)(CMIF_CR4_BRP_BASE_ADDR + CMIF_DRV_TET_SYNC_OFFSET),
   
   .send_func             = CMIF_C2M_SWI_SW_U4G, 
   .send_stats_func       = CMIF_C2M_STATUS_U4G, 
   .receive_clr_func      = CMIF_M2C_EOI_U4G, 
   .receive_stats_func    = CMIF_M2C_STATUS_U4G, 
   .md32_core             = CMIF_MD32_BRP
};

CMIF_Ctrl_t cmif_ctrl_rake_u3g = {
   .send_set              = CMIF_C2M_U3G_RAKE_SET,
   .send_status           = CMIF_C2M_U3G_RAKE_STATUS, 
   .receive_clr           = CMIF_M2C_U3G_RAKE_CLEAN, 
   .receive_status        = CMIF_M2C_U3G_RAKE_STATUS, 
   .sync                  = (volatile cmif_uint32*)(CMIF_CR4_RAKE_BASE_ADDR + CMIF_DRV_TET_SYNC_OFFSET),
   
   .send_func             = CMIF_C2M_SWI_SW_U3G, 
   .send_stats_func       = CMIF_C2M_STATUS_U3G, 
   .receive_clr_func      = CMIF_M2C_EOI_U3G, 
   .receive_stats_func    = CMIF_M2C_STATUS_U3G,
   .md32_core             = CMIF_MD32_RAKE
};

CMIF_Ctrl_t cmif_ctrl_dfe_u3g = {
   .send_set              = CMIF_C2M_U3G_DFE_SET,
   .send_status           = CMIF_C2M_U3G_DFE_STATUS, 
   .receive_clr           = CMIF_M2C_U3G_DFE_CLEAN, 
   .receive_status        = CMIF_M2C_U3G_DFE_STATUS, 
   .sync                  = (volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_DRV_TET_SYNC_OFFSET),
   
   .send_func             = CMIF_C2M_SWI_SW_U3G, 
   .send_stats_func       = CMIF_C2M_STATUS_U3G, 
   .receive_clr_func      = CMIF_M2C_EOI_U3G, 
   .receive_stats_func    = CMIF_M2C_STATUS_U3G,
   .md32_core             = CMIF_MD32_DFE
};

CMIF_Ctrl_t cmif_ctrl_dfe_u4g = {
   .send_set              = CMIF_C2M_U4G_DFE_SET,
   .send_status           = CMIF_C2M_U4G_DFE_STATUS, 
   .receive_clr           = CMIF_M2C_U4G_DFE_CLEAN, 
   .receive_status        = CMIF_M2C_U4G_DFE_STATUS, 
   .sync                  = (volatile cmif_uint32*)(CMIF_CR4_DFE_BASE_ADDR + CMIF_DRV_TET_SYNC_OFFSET),
   
   .send_func             = CMIF_C2M_SWI_SW_U4G, 
   .send_stats_func       = CMIF_C2M_STATUS_U4G, 
   .receive_clr_func      = CMIF_M2C_EOI_U4G, 
   .receive_stats_func    = CMIF_M2C_STATUS_U4G,
   .md32_core             = CMIF_MD32_DFE
};

extern void cmif_drv_test_sync(CMIF_Ctrl_t* ctrl);
extern void CMIF_DisableInterrupt();
extern void CMIF_EnableInterrupt();
extern void CMIF_ClearPendingInterrupt();

cmif_uint32 cmif_drvtest_case;
cmif_uint32 cmif_drvtest_prev_irq;
cmif_uint32 cmif_drvtest_irq_test_success;

void CMIF_DriverAPIM2CTest(CMIF_Ctrl_t* ctrl)
{
    CMIF_Mask_t mask;

    cmif_drv_test_sync(ctrl);

    // 1. Wait for MD32

    cmif_drv_test_sync(ctrl);

    // 2. Check the status and clear the status registers

    (*ctrl->receive_stats_func)(ctrl->md32_core, &mask);
    CMIF_DRV_TEST_ASSERT_EQ(*(ctrl->receive_status), 0x1E);
    CMIF_DRV_TEST_ASSERT_EQ(mask.mask31_0, 0x1E);

    (*ctrl->receive_clr_func)(1, ctrl->md32_core);
    (*ctrl->receive_clr_func)(2, ctrl->md32_core);
    (*ctrl->receive_clr_func)(3, ctrl->md32_core);
    (*ctrl->receive_clr_func)(4, ctrl->md32_core);

    (*ctrl->receive_stats_func)(ctrl->md32_core, &mask);
    CMIF_DRV_TEST_ASSERT_EQ(*(ctrl->receive_status), 0x0);
    CMIF_DRV_TEST_ASSERT_EQ(mask.mask31_0, 0x0);

    cmif_drv_test_sync(ctrl);

    // 3. Wait for MD32


    cmif_drv_test_sync(ctrl);
}

void CMIF_DriverAPIC2MTest(CMIF_Ctrl_t* ctrl)
{ 
    CMIF_Mask_t mask;

    cmif_drv_test_sync(ctrl);

    // 1. set the interrupt bit and check status registers
    ctrl->send_func(1, ctrl->md32_core);
    ctrl->send_func(2, ctrl->md32_core);
    ctrl->send_func(3, ctrl->md32_core);
    ctrl->send_func(4, ctrl->md32_core);

    (*ctrl->send_stats_func)(ctrl->md32_core, &mask);
    CMIF_DRV_TEST_ASSERT_EQ(*(ctrl->send_status), 0x1E);
    CMIF_DRV_TEST_ASSERT_EQ(mask.mask31_0, 0x1E);
    

    cmif_drv_test_sync(ctrl);

    // 2. Wait for MD32 

    cmif_drv_test_sync(ctrl);

    // 3. Check the status regsiters 
    (*ctrl->send_stats_func)(ctrl->md32_core, &mask);
    CMIF_DRV_TEST_ASSERT_EQ(*(ctrl->send_status), 0x0);
    CMIF_DRV_TEST_ASSERT_EQ(mask.mask31_0, 0x0);

    cmif_drv_test_sync(ctrl);

}

void CMIF_DriverISRTestC2M(CMIF_Ctrl_t* ctrl, cmif_uint32 case_num)
{

    cmif_drvtest_case = case_num;

    cmif_drv_test_sync(ctrl);
    
    // 1. Wait for MD32

    cmif_drv_test_sync(ctrl);

    // 2. Send interrupt to md32 
    if(cmif_drvtest_case == 1){
        ctrl->send_func(1, ctrl->md32_core);
        ctrl->send_func(2, ctrl->md32_core);
        ctrl->send_func(3, ctrl->md32_core);
        ctrl->send_func(4, ctrl->md32_core);
    }
    else if(cmif_drvtest_case == 2){
        ctrl->send_func(5, ctrl->md32_core);
        ctrl->send_func(6, ctrl->md32_core);
        ctrl->send_func(7, ctrl->md32_core);
        ctrl->send_func(8, ctrl->md32_core);
    }

    cmif_drv_test_sync(ctrl);

    // 3. Wait for MD32

    cmif_drv_test_sync(ctrl);
}

void CMIF_DriverISRTestM2C(CMIF_Ctrl_t* ctrl, cmif_uint32 case_num)
{
    cmif_drvtest_case = case_num;

    cmif_drv_test_sync(ctrl);

    // 1. Disalbe interrupt and clean the pending interrupt 
    CMIF_DisableInterrupt();
    CMIF_ClearPendingInterrupt();

    cmif_drv_test_sync(ctrl);

    // 2. Wait for MD32

    cmif_drv_test_sync(ctrl);

    // 3. Enable the interrupt
    CMIF_EnableInterrupt();
    while(cmif_drvtest_irq_test_success != cmif_drvtest_case);
    CMIF_DisableInterrupt();


    cmif_drv_test_sync(ctrl);
}


void CMIF_DriverTestISRU3G_Internal(CMIF_Mask_t* mask, CMIF_MD32_Core_t core)
{
    cmif_uint32 cmif_drvtest_curr_irq;
    if(cmif_drvtest_case == 1){
        // auto eoi mode
        cmif_drvtest_curr_irq = CMIF_GET_LSB(mask->mask31_0);

        CMIF_DRV_TEST_ASSERT_EQ(cmif_drvtest_curr_irq - cmif_drvtest_prev_irq, 1);

        cmif_drvtest_prev_irq = cmif_drvtest_curr_irq;
        if(cmif_drvtest_prev_irq == 4){
            cmif_drvtest_prev_irq = 0;
            cmif_drvtest_irq_test_success = cmif_drvtest_case;
        }
    }
    else if(cmif_drvtest_case== 2){
        // non-auto eoi mode
        cmif_drvtest_curr_irq = CMIF_GET_LSB(mask->mask31_0);
   
        switch (cmif_drvtest_prev_irq) {
            case 0:
                CMIF_M2C_EOI_U3G(8, core);
                break;
            case 5:
                if(cmif_drvtest_curr_irq == 5)
                    CMIF_M2C_EOI_U3G(5, core);
                else if(cmif_drvtest_curr_irq == 6)
                    CMIF_M2C_EOI_U3G(6, core);
                break;
            case 6:
                CMIF_M2C_EOI_U3G(7, core);
                break;
            default:
                CMIF_DRV_TEST_ASSERT_EQ(1,2);
        }

        cmif_drvtest_prev_irq = cmif_drvtest_curr_irq;
        if(cmif_drvtest_prev_irq == 7){
            cmif_drvtest_prev_irq = 0; 
            cmif_drvtest_irq_test_success = cmif_drvtest_case;
        }
    }
}

void CMIF_DriverTestISRU4G_Internal(CMIF_Mask_t* mask, CMIF_MD32_Core_t core)
{
    cmif_uint32 cmif_drvtest_curr_irq;
    if(cmif_drvtest_case == 1){
        // auto eoi mode
        cmif_drvtest_curr_irq = CMIF_GET_LSB(mask->mask31_0);

        CMIF_DRV_TEST_ASSERT_EQ(cmif_drvtest_curr_irq - cmif_drvtest_prev_irq, 1);

        cmif_drvtest_prev_irq = cmif_drvtest_curr_irq;
        if(cmif_drvtest_prev_irq == 4){
            cmif_drvtest_prev_irq = 0;
            cmif_drvtest_irq_test_success = cmif_drvtest_case;
        }
    }
    else if(cmif_drvtest_case== 2){
        // non-auto eoi mode
        cmif_drvtest_curr_irq = CMIF_GET_LSB(mask->mask31_0);
   
        switch (cmif_drvtest_prev_irq) {
            case 0:
                CMIF_M2C_EOI_U4G(8, core);
                break;
            case 5:
                if(cmif_drvtest_curr_irq == 5)
                    CMIF_M2C_EOI_U4G(5, core);
                else if(cmif_drvtest_curr_irq == 6)
                    CMIF_M2C_EOI_U4G(6, core);
                break;
            case 6:
                CMIF_M2C_EOI_U4G(7, core);
                break;
            default:
                CMIF_DRV_TEST_ASSERT_EQ(1,2);
        }

        cmif_drvtest_prev_irq = cmif_drvtest_curr_irq;
        if(cmif_drvtest_prev_irq == 7){
            cmif_drvtest_prev_irq = 0; 
            cmif_drvtest_irq_test_success = cmif_drvtest_case;
        }
    }
}

void CMIF_DrierTestISR_BRP_U3G(CMIF_Mask_t* mask)
{
    CMIF_DriverTestISRU3G_Internal(mask, CMIF_MD32_BRP);
}

void CMIF_DrierTestISR_BRP_U4G(CMIF_Mask_t* mask)
{
    CMIF_DriverTestISRU4G_Internal(mask, CMIF_MD32_BRP);
}

void CMIF_DrierTestISR_RAKE_U3G(CMIF_Mask_t* mask)
{
    CMIF_DriverTestISRU3G_Internal(mask, CMIF_MD32_RAKE);
}

#endif /* __MD32S_CMIF_DRV_TEST__ */
