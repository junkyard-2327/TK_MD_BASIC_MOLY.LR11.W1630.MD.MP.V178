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
#if (defined(__CORE_BRP__) || defined(__CORE_RAKE__) || defined(__CORE_DFE__))
#include "cmif.h"
#include "vic_public.h"
#else
#include "drv_cmif.h"
#endif

#if defined(__MD32S_CMIF_DRV_TEST__)
#if __CMIF_MD32S_CORE__
#include "intrCtrl.h"
#include "vic_public.h"
#include "mos_core.h"
#else  /* __CMIF_MD32S_CORE__  */
#include "intrCtrl.h"
#include "kal_public_api.h"
#include "kal_general_types.h"

#define dbg_print(str, args...)  

#endif  /* __CMIF_MD32S_CORE__  */
#endif /*  __MD32S_CMIF_DRV_TEST__ */


/*******************************************************************************
 * Function prototypes
 *******************************************************************************/
#if defined(__CMIF_DEBUG__)
extern CMIF_DebugRecordList cmif_debug_records;
#endif


#if !defined(__CMIF_DEBUG__)
void cmif_InterruptHandlerInternal(volatile cmif_uint32* sreg,
                                   volatile cmif_uint32* creg,
                                   CMIF_InterruptEntryFun* handler,
                                   cmif_bool* auto_eoi);
#else     /* __CMIF_DEBUG__ */
void cmif_InterruptHandlerInternal(volatile cmif_uint32* sreg,
                                   volatile cmif_uint32* creg,
                                   CMIF_InterruptEntryFun* handler,
                                   cmif_bool* auto_eoi,
#if !__CMIF_MD32S_CORE__
                                   CMIF_MD32_Core_t core,
#endif /* !__CMIF_MD32S_CORE__  */
                                   CMIF_DebugInterruptType u3g);
#endif    /* __CMIF_DEBUG__ */

/*******************************************************************************
 * Functions - Common Part
 *******************************************************************************/
void CMIF_DefaultISR(CMIF_Mask_t* mask)
{
    CMIF_ASSERT(0);
}

#if defined(__CMIF_DEBUG__)
void cmif_DebugAddRecord(CMIF_Mask_t* before,
                         CMIF_Mask_t* after,
                         cmif_uint32 set_addr,
                         cmif_uint32 set_value,
                         cmif_uint32 caller)
{
    cmif_uint32 save_index = 0;
    cmif_uint32 mask;

#if __CMIF_MD32S_CORE__
    mask = VIC_DisableAllSource();
#else
    mask = SaveAndSetIRQMask();
#endif
    // fetch and add top_index atomically. 
    save_index = cmif_debug_records.top_index;

    ++cmif_debug_records.top_index;
    if(cmif_debug_records.top_index == CMIF_DEBUG_ISR_HANDLE_CODE_SIZE){
        cmif_debug_records.top_index = 0; 
    }

#if __CMIF_MD32S_CORE__
    VIC_RestoreAllSource(mask);
#else
    RestoreIRQMask(mask);
#endif

    cmif_debug_records.records[save_index].before.mask31_0 = before->mask31_0;
    cmif_debug_records.records[save_index].after.mask31_0 = after->mask31_0;
    cmif_debug_records.records[save_index].set_addr = set_addr;
    cmif_debug_records.records[save_index].set_value = set_value;
    cmif_debug_records.records[save_index].caller = caller;
}
#endif /*  __CMIF_DEBUG__ */

/**
  *   General interrupt handler function
  *
  *   @param[in] sreg            CMIF interrupt status register
  *   @param[in] creg            CMIF interrupt clean register
  *   @param[in] handler         CMIF user entry function lists 
  *   @param[in] core            CMIF interrupt core type - BRP, DFE and RAKE (Debug only)
  *   @param[in] interrupt_type  CMIF interrupt type - U3G or U4G (Debug only)
  **/
#if !defined(__CMIF_DEBUG__)
void cmif_InterruptHandlerInternal(volatile cmif_uint32* sreg,
                                   volatile cmif_uint32* creg,
                                   CMIF_InterruptEntryFun* handler,
                                   cmif_bool* auto_eoi 
                                   )
#else     /* __CMIF_DEBUG__ */
void cmif_InterruptHandlerInternal(volatile cmif_uint32* sreg,
                                   volatile cmif_uint32* creg,
                                   CMIF_InterruptEntryFun* handler,
                                   cmif_bool* auto_eoi,
#if !__CMIF_MD32S_CORE__
                                   CMIF_MD32_Core_t core,
#endif     /* !__CMIF_MD32S_CORE__  */
                                   CMIF_DebugInterruptType interrupt_type)
#endif    /* __CMIF_DEBUG__ */
{
    cmif_uint8 eidx;  // entry function index 
    CMIF_Mask_t cmif_mask;

    while(CMIF_REG_READ(sreg)){
        // read the sreg to the mask
        cmif_mask.mask31_0 = CMIF_REG_READ(sreg);

        // find the lsb
        eidx = CMIF_GET_LSB(cmif_mask.mask31_0);

        // invoke the user register interupt handler function
        (*handler[eidx])(&cmif_mask);

        // if the `irq_auto_eoi` is CMIF_TRUE, clean the interupt bit
        if(auto_eoi[eidx] == CMIF_TRUE){
#if defined(__CMIF_DEBUG__)
            CMIF_Mask_t before;
            CMIF_Mask_t after;
            cmif_uint32 caller;

            before.mask31_0 = CMIF_REG_READ(creg);
#endif /* __CMIF_DEBUG__ */
           /* In 6291, JADE CMIF has a clear fail bug */
           /* This workaround ensure the clear transaction is success */
			do{
				CMIF_REG_WRITE(creg, 1 << eidx);
			}while(((CMIF_REG_READ(sreg) >> eidx) & 0x1) == 0x1);

#if defined(__CMIF_DEBUG__)
            after.mask31_0 = CMIF_REG_READ(creg);
            CMIF_GET_RETURN_ADDRESS(caller);
            cmif_DebugAddRecord(&before, &after, (cmif_uint32)creg, (1 << eidx), caller);
#endif /* __CMIF_DEBUG__ */
        }

#if defined(__CMIF_DEBUG__)
#if __CMIF_MD32S_CORE__
        cmif_DebugAddISRHandleCode(eidx, interrupt_type);
#else    /* __CMIF_MD32S_CORE__  */
        cmif_DebugAddISRHandleCode(eidx, core, interrupt_type);
#endif   /* __CMIF_MD32S_CORE__  */
#endif   /* __CMIF_DEBUG__ */
    }
}


/*******************************************************************************
 * Functions - Driver test 
 *******************************************************************************/

#if defined(__MD32S_CMIF_DRV_TEST__)

#if __CMIF_MD32S_CORE__
extern CMIF_Ctrl_t cmif_ctrl_u3g;
#if __CMIF_INTERRUPT_U4G__
extern CMIF_Ctrl_t cmif_ctrl_u4g;
#endif
#else
extern CMIF_Ctrl_t cmif_ctrl_brp_u3g;
extern CMIF_Ctrl_t cmif_ctrl_brp_u4g;
extern CMIF_Ctrl_t cmif_ctrl_rake_u3g;
extern CMIF_Ctrl_t cmif_ctrl_dfe_u3g;
extern CMIF_Ctrl_t cmif_ctrl_dfe_u4g;
#endif

extern cmif_uint32 cmif_drvtest_case;
extern cmif_uint32 cmif_drvtest_prev_irq;
extern cmif_uint32 cmif_drvtest_irq_test_success;

extern void CMIF_DriverAPIM2CTest(CMIF_Ctrl_t* ctrl);
extern void CMIF_DriverAPIC2MTest(CMIF_Ctrl_t* ctrl);

extern void CMIF_DriverISRTestC2M(CMIF_Ctrl_t* ctrl, cmif_uint32 case_num);
extern void CMIF_DriverISRTestM2C(CMIF_Ctrl_t* ctrl, cmif_uint32 case_num);

void cmif_drv_test_sync(CMIF_Ctrl_t* ctrl)
{
    volatile cmif_uint32* sync = ctrl->sync;
#if __CMIF_MD32S_CORE__
    // MD32 Part
    while(sync[0] == 1) ; 
    sync[0] = 1;          

    while(sync[1] == 0) ; 
    sync[1] = 0;
#else
    // CR4 Part
    while(sync[1] == 1) ;
    sync[1] = 1;             

    while(sync[0] == 0) ;
    sync[0] = 0;             
#endif
}


void CMIF_DriverAPITest()
{
#if __CMIF_MD32S_CORE__
    // MD32 part
    CMIF_DriverAPIM2CTest(&cmif_ctrl_u3g);
    dbg_print("CMIF M2C U3G API Test success\n");

    CMIF_DriverAPIC2MTest(&cmif_ctrl_u3g);
    dbg_print("CMIF C2M U3G API Test success\n");
#if __CMIF_INTERRUPT_U4G__
    CMIF_DriverAPIM2CTest(&cmif_ctrl_u4g);
    dbg_print("CMIF M2C U4G API Test success\n");

    CMIF_DriverAPIC2MTest(&cmif_ctrl_u4g);
    dbg_print("CMIF C2M U4G API Test success\n");
#endif

#else
    // CR4 Part
    // test brp
    CMIF_DriverAPIM2CTest(&cmif_ctrl_brp_u3g);
    CMIF_DriverAPIC2MTest(&cmif_ctrl_brp_u3g);

    CMIF_DriverAPIM2CTest(&cmif_ctrl_brp_u4g);
    CMIF_DriverAPIC2MTest(&cmif_ctrl_brp_u4g);

    // test rake
    CMIF_DriverAPIM2CTest(&cmif_ctrl_rake_u3g);
    CMIF_DriverAPIC2MTest(&cmif_ctrl_rake_u3g);
#endif
}


void CMIF_DisableInterrupt()
{
#if __CMIF_MD32S_CORE__
    // MD32 Part
#if defined(__CORE_BRP__) 
    IRQMask(IRQ_SW_LISR3E_CODE);
    IRQMask(IRQ_SW_LISR3F_CODE);
#endif

#if defined(__CORE_DFE__) 
    IRQMask(IRQ_SW_LISR1E_CODE);
    IRQMask(IRQ_SW_LISR1F_CODE);
#endif

#if defined(__CORE_RAKE__) 
    VIC_DisableSource(VIC_ISR_INDX_IRQ1);
#endif
#else
    // CR4 Part
    // u3g
    IRQMask(IRQ_BRP_M2C_1_CODE);
    IRQMask(IRQ_DFE_M2C_1_CODE);
    IRQMask(IRQ_INR_M2C_1_CODE);

    // u4g
    IRQMask(IRQ_BRP_M2C_2_CODE);
    IRQMask(IRQ_DFE_M2C_2_CODE);
#endif 
}

void CMIF_EnableInterrupt()
{
    // clear interrupt pending
#if __CMIF_MD32S_CORE__


    // MD32 Part
#if defined(__CORE_BRP__) 
    IRQUnmask(IRQ_SW_LISR3E_CODE);
    IRQUnmask(IRQ_SW_LISR3F_CODE);
#endif

#if defined(__CORE_DFE__) 
    IRQUnmask(IRQ_SW_LISR21_CODE);
    IRQUnmask(IRQ_SW_LISR22_CODE);
#endif

#if defined(__CORE_RAKE__) 
    VIC_EnableSource(VIC_ISR_INDX_IRQ1);
#endif

#else
    extern void CMIF_Init();
    CMIF_Init();
#endif
}

void CMIF_ClearPendingInterrupt()
{
#if __CMIF_MD32S_CORE__
// clear interrupt pending
#if (defined(__CORE_BRP__) || defined(__CORE_DFE__)) 
    IRQClearAllInt();
    MOS_CORE_IO_WRITE(0x0, MOS_VIC_PEND);
#endif

#if (defined(__CORE_RAKE__))
    MOS_CORE_IO_WRITE(0x0, MOS_VIC_PEND);
#endif

#else
    extern void IRQClearAllInt();
    IRQClearAllInt();
#endif
}

void CMIF_InterruptTest()
{
#if __CMIF_MD32S_CORE__
    CMIF_DriverISRTestC2M(&cmif_ctrl_u3g, 1);
#if __CMIF_INTERRUPT_U4G__
    CMIF_DriverISRTestC2M(&cmif_ctrl_u4g, 1);
#endif

    CMIF_DriverISRTestM2C(&cmif_ctrl_u3g, 1);
#if __CMIF_INTERRUPT_U4G__
    CMIF_DriverISRTestM2C(&cmif_ctrl_u4g, 1);
#endif

    CMIF_DriverISRTestC2M(&cmif_ctrl_u3g, 2);
#if __CMIF_INTERRUPT_U4G__
    CMIF_DriverISRTestC2M(&cmif_ctrl_u4g, 2);
#endif

    CMIF_DriverISRTestM2C(&cmif_ctrl_u3g, 2);
#if __CMIF_INTERRUPT_U4G__
    CMIF_DriverISRTestM2C(&cmif_ctrl_u4g, 2);
#endif

#else
    // test brp u3g & u4g 
    CMIF_DriverISRTestC2M(&cmif_ctrl_brp_u3g, 1);
    CMIF_DriverISRTestC2M(&cmif_ctrl_brp_u4g, 1);

    CMIF_DriverISRTestM2C(&cmif_ctrl_brp_u3g, 1);
    CMIF_DriverISRTestM2C(&cmif_ctrl_brp_u4g, 1);

    CMIF_DriverISRTestC2M(&cmif_ctrl_brp_u3g, 2);
    CMIF_DriverISRTestC2M(&cmif_ctrl_brp_u4g, 2);

    CMIF_DriverISRTestM2C(&cmif_ctrl_brp_u3g, 2);
    CMIF_DriverISRTestM2C(&cmif_ctrl_brp_u4g, 2);

    // test rake u3g
    CMIF_DriverISRTestC2M(&cmif_ctrl_rake_u3g, 1);
    CMIF_DriverISRTestM2C(&cmif_ctrl_rake_u3g, 1);

    CMIF_DriverISRTestC2M(&cmif_ctrl_rake_u3g, 2);
    CMIF_DriverISRTestM2C(&cmif_ctrl_rake_u3g, 2);
#endif
}

/* how to run cmif driver test ? */
/* MD32 Side: insert CMIF_DriverTest to basic load function */
/* CR4 Side: insert CMIF_DriverTest to idle task function */

void CMIF_DriverTest()
{
#if __CMIF_MD32S_CORE__
    extern void CMIF_DriverInitTest();
    CMIF_DriverInitTest();
#endif

    CMIF_DisableInterrupt();
    dbg_print("-- CMIF API Test Start.\n");
    CMIF_DisableInterrupt();
    CMIF_DriverAPITest();
    dbg_print("-- CMIF API Test End.\n");

    dbg_print("-- CMIF Interrupt Start.\n");
    CMIF_EnableInterrupt();
    CMIF_InterruptTest();
    dbg_print("-- CMIF Interrupt End.\n");

}

#endif /* __MD32S_CMIF_DRV_TEST__ */

