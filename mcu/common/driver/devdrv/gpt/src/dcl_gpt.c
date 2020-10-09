/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *    dcl_gpt.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the GPT driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features_gpt.h"
#include "drv_comm.h"
#include "drv_gpt.h"
#include "drv_litegpt.h"
#include "intrCtrl.h"
#include "us_timer.h"


#include "dcl_gpt.h"
#include "dcl_gpt_hw.h"
#include "dcl.h"
#include "devdrv_ls.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drvpdn.h"
#include "sleepdrv_interface.h"


//#define DCL_GPT_INTERFACE
//#ifdef  DCL_GPT_INTERFACE

#if !defined(DRV_GPT_OFF)

/*****************************************************************************
 *                        Symbol/Type Definition                             *
 *****************************************************************************/
//DCL_GPT_CB  this software gpt provide register callback function.
#define DCL_GPT_CB_MAGIC_NUM                (0x02000000)
#define DCL_GPT_BW_MAGIC_NUM                (0x04000000)
#define DCL_FGPT_MAGIC_NUM                  (0x08000000)
#define DCL_GPT_CBUS_MAGIC_NUM              (0x10000000)

#if defined(__L1CORE__)
#define DCL_GPT_DEBUG_MAGIC_NUM             (0x20000000)
#endif

#if defined(__PCORE__)
#define DCL_LITEGPT_CBETMR_MAGIC_NUM              (0x40000000)
#endif
#define DCL_GPT_CB_TICK2US                  (10000U)
#define DCL_GPT_CBUS_TICK2US                (1U)

#if defined(MT6290) || defined(TK6291)
  #define MDGPTM_PDN_SET() PDN_SET(PDN_MDGPTM);
  #define MDGPTM_PDN_CLR() PDN_CLR(PDN_MDGPTM);
#else  /* MT6290 */
  #define MDGPTM_PDN_SET() PDN_SET(PDN_GPT);
  #define MDGPTM_PDN_CLR() PDN_CLR(PDN_GPT);
#endif /* MT6290 */

/*****************************************************************************
 *                         Macro Function Definition                           *
 *****************************************************************************/

#define DCL_GPT_CB_IS_HANDLE_MAGIC(handl_)    ((handl_)& DCL_GPT_CB_MAGIC_NUM)
#define DCL_GPT_CB_GET_DEV(handle_)           ((handle_) & (~DCL_GPT_CB_MAGIC_NUM))
#define DCL_GPT_CBUS_IS_HANDLE_MAGIC(handl_)  ((handl_)& DCL_GPT_CBUS_MAGIC_NUM)
#if defined(__L1CORE__)
#define DCL_GPT_DEBUG_IS_HANDLE_MAGIC(handl_) ((handl_)& DCL_GPT_DEBUG_MAGIC_NUM)
#define DCL_GPT_DEBUG_GET_DEV(handle_)        ((handle_) & (~DCL_GPT_DEBUG_MAGIC_NUM))
#endif
#if defined(__PCORE__)
#define DCL_LITEGPT_CBETMR_IS_HANDLE_MAGIC(handl_)  ((handl_)& DCL_LITEGPT_CBETMR_MAGIC_NUM)
#endif

#define DCL_GPT_BUS_CLOCK_ON()                      \
    do{                                             \
        if(KAL_FALSE == gpt_bus_clock_en)           \
        {                                           \
            MDGPTM_PDN_CLR();                       \
            gpt_bus_clock_en = KAL_TRUE;            \
        }                                           \
    }while(0);
#if defined(__EVENT_BASED_TIMER__) /* OST as os tick */
    #define DCL_GPT_BUS_CLOCK_OFF()                 \
    do{                                             \
        if(KAL_TRUE == gpt_bus_clock_en)            \
        {                                           \
            MDGPTM_PDN_SET();                       \
            gpt_bus_clock_en = KAL_FALSE;           \
        }                                           \
    }while(0);
#else /* __EVENT_BASED_TIMER__, GPT as OS tick */
    #define DCL_GPT_BUS_CLOCK_OFF()
#endif /* */

#if defined(__L1CORE__)
#define DCL_GPT_IS_USED() ((KAL_TRUE == gptCBUS_running) || (0!=gptCB_status) || (NULL!=gpt_DEBUG_head.next))
#elif defined(__PCORE__)
#define DCL_GPT_IS_USED() ((KAL_TRUE == gptCBUS_running) || (0!=gptCB_status))
#endif

#define DCL_GPT_BUS_CLOCK_TRY_OFF()                     \
    if(!DCL_GPT_IS_USED()) { DCL_GPT_BUS_CLOCK_OFF(); }

/*****************************************************************************
 *                         Structure/Type Definition                         *
 *****************************************************************************/
typedef struct gptimer_instance{
	kal_uint32 ticks;
	void (*gptimer_func)(void *parameter);
	void *param;
	struct gptimer_instance *next;
}gpt_inst;

/*****************************************************************************
 *                         Global/External Variable                          *
 *****************************************************************************/
kal_bool gpt_bus_clock_en = KAL_FALSE;

/* For mini-second Callback Function */
static kal_uint32   gptCB_status;               /* 1,activated ,0:de-activated */
static kal_uint32   gptCB_ticks;                /* CB gpt current ticks number */
static kal_uint32   gptCB_users;                /* Indicate the current registered GPT users */
static kal_uint8    gptCB_used[MAX_GPT_ITEMS];  /* 0: Not registered by user, 1: Registerd by used */
static gptimer_item gptCB_items[MAX_GPT_ITEMS]; /* gpt callback function instance */


/* For micro-second Callback Function */
static kal_bool     gptCBUS_used    = KAL_FALSE;
static kal_bool     gptCBUS_running = KAL_FALSE;
static gptimer_item gptCBUS_instance;

#if defined(__L1CORE__)
/* For micro-second Debug Callback Function */
static kal_uint32   gpt_DEBUG_users;                /* Indicate the current registered GPT users */
static gpt_inst     gpt_DEBUG_head;                 /* BSS section, default field value == 0 */
static kal_uint8    gpt_DEBUG_used[MAX_GPT_ITEMS];  /* 0: Not registered by user, 1: Registerd by used */
static gpt_inst     gpt_DEBUG_items[MAX_GPT_ITEMS]; /* gpt callback function instance */
static kal_hisrid   gpt_debug_hisr;
#endif

#if defined(__PCORE__)
/* For ETMR Callback Function */
static kal_bool     litegptCBETMR_used    = KAL_FALSE;
static kal_bool     litegptCBETMR_running = KAL_FALSE;

static kal_bool     litegptCBETMR_second_level = KAL_FALSE;
static gptimer_item litegptCBETMR_instance;
static kal_hisrid   litegpt_etmr_hisr;

kal_uint32 gpt_etmr_level2_start_time = 0;
kal_uint32 gpt_etmr_level2_stop_time = 0;
kal_uint32 gpt_etmr_level2_duration = 0;
kal_uint32 gpt_etmr_level2_tick = 0;

kal_uint32 gpt_etmr_level2_settle_tick = 0;//32K unit

/*JADE PU GPT do not have 3T 32K Stop -> Start issue*/
#if !defined(JADE_VER)
static kal_bool     litegptCBETMR_gpt2    = KAL_FALSE;
kal_uint32 gpt_etmr_stop_time = 0;
kal_uint32 gpt_etmr_restart_time = 0;
kal_uint32 gpt_etmr_duration = 0;
#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
kal_uint8 gpt_sm_handle;
#endif

#endif

#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
kal_uint8 gpt_26m_handle;
#endif

#ifdef ATEST_DRV_GPT
extern kal_uint32 gpt_etmr_drvtest_stop_time1;
extern kal_uint32 gpt_etmr_drvtest_start_time1;
extern kal_uint32 gpt_etmr_drvtest_duration1;

extern kal_uint32 gpt_etmr_drvtest_stop_time2;
extern kal_uint32 gpt_etmr_drvtest_start_time2;
extern kal_uint32 gpt_etmr_drvtest_duration2;
#endif

#if defined(__FPGA__)
#define gpt_get_current_time()   (DRV_Reg32((kal_uint32) USCNTI_VAL))
#else
#define gpt_get_current_time()   ust_get_current_time()
#endif

#define UT_GPT_GET_32BIT_COUNTER_DURATION(start, end) \
    (((end) >= (start))? ((end) - (start)): ((0xFFFFFFFF - (start) + (end) + 1)))
    
#endif
static kal_hisrid gpt1_hisrid;
static kal_hisrid gpt2_hisrid;
/*****************************************************************************
 *                       function declaration                                *
 *****************************************************************************/
void GPTCB_10MS_HISR(void);
void GPTCB_US_HISR(void);

#if defined(__L1CORE__)
void GPTCB_DEBUG_HISR(void);
#endif

static kal_bool GPTCB_StartItem(DCL_HANDLE module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
static void GPTCB_StopItem(DCL_HANDLE module);

#if defined(__L1CORE__)
static void GPT_DEBUG_Insert(kal_uint32 indx, kal_uint32 tick,void (*gptimer_func)(void *),void *parameter);
static void GPT_DEBUG_Stop(kal_uint32 indx);
#endif

#if defined(__PCORE__)
void LITEGPT_ETMR_HISR(void);
#endif

/*****************************************************************************
 *                        debug informaiton                                  *
 *****************************************************************************/
//#define __DRV_GPT_TRACE__ 1
#if defined(__DRV_GPT_TRACE__)

#define IFDEF_GPT_TRACE(x) x

#define MAX_GPT_HISR_DBG_INFO_SIZE 128
typedef struct
{
    kal_uint16      tag;
    kal_uint32      enter_time;
    kal_uint32      leave_time;
} GPT_HISR_DBG_DATA;
typedef struct{
   GPT_HISR_DBG_DATA       dbg_data[MAX_GPT_HISR_DBG_INFO_SIZE];
   kal_uint16             dbg_data_idx;
}
GPT_HISR_DBG_STRUCT;

GPT_HISR_DBG_STRUCT    GPT_HISR_DBG_INFO_DATA;
#define GPT_DBG(a, b, c) GPT_hisr_dbg_trace(a,b, c);
void GPT_hisr_dbg_trace(kal_uint32 index, kal_uint32 time1, kal_uint32 time2)
{
    kal_uint32 savedMask;
    savedMask = SaveAndSetIRQMask();
    GPT_HISR_DBG_INFO_DATA.dbg_data[GPT_HISR_DBG_INFO_DATA.dbg_data_idx].tag = (kal_uint16)index;
    GPT_HISR_DBG_INFO_DATA.dbg_data[GPT_HISR_DBG_INFO_DATA.dbg_data_idx].enter_time = time1;
    GPT_HISR_DBG_INFO_DATA.dbg_data[GPT_HISR_DBG_INFO_DATA.dbg_data_idx].leave_time = time2;
    GPT_HISR_DBG_INFO_DATA.dbg_data_idx = (GPT_HISR_DBG_INFO_DATA.dbg_data_idx+1)%MAX_GPT_HISR_DBG_INFO_SIZE;
    RestoreIRQMask(savedMask);
    /*
    kal_prompt_trace(MOD_DRVKBD, "index=%d, time=%d, time2=%d", index, time, time2);
    */
}
#else  /* __DRV_GPT_TRACE__ */
#define GPT_DBG(a, b, c) ;
#define IFDEF_GPT_TRACE(x)
#endif  /* __DRV_GPT_TRACE__ */

//#define GPT_CB_MEASURE_TIME 1
#if defined(GPT_CB_MEASURE_TIME)
/* to measure time */
#if defined(__CR4__)
#include "cp15_int.h"
#elif defined(__MTK_MMU_V2__) /* __CR4__*/
#include "mpu_mtk_mmu_v2_int.h"
#endif /* __MTK_MMU_V2__ */
#define IFDEF_GPT_CB_MEASURE_TIME(x) x
kal_uint32 gpt_cb_enter_time[MAX_GPT_ITEMS];
kal_uint32 gpt_cb_leave_time[MAX_GPT_ITEMS];
kal_uint32 gpt_uscb_enter_time;
kal_uint32 gpt_uscb_leave_time;

#else  /* GPT_CB_MEASURE_TIME */

#define IFDEF_GPT_CB_MEASURE_TIME(x)
#endif /* GPT_CB_MEASURE_TIME */

/*[end]***********************************debug informaiton end *****************************/

void GPT_ERROR_CB(void *p)
{
    kal_uint32 CANNOT_FIND_GPT_CB_HANDLER = 0;
    ASSERT(CANNOT_FIND_GPT_CB_HANDLER);
}

/*-----------------------------------------------------------------------*
*                                                                            
*                        GPT 10ms LISR function,                                  
*                pass to gpt_hw layer as a function pointer     
*                                                                        
*------------------------------------------------------------------------*/
void GPTCB_Lisr(kal_uint32 vector)
{
    /*ASSERT( (MDGPT_INTR_ID(DRV_GPT_CALLBACK_TIMER) == vector) || \
            (MDGPT_INTR_ID(DRV_GPT_CBUS_TIMER) == vector)          );*/
#if defined(MT6290) && defined(__ARM7EJ_S__)
    IRQClearInt(vector);
#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
    kal_activate_hisr(gpt1_hisrid);
}

/*-----------------------------------------------------------------------*
*                                                                            
*                        GPT 1us LISR function,                                  
*                pass to gpt_hw layer as a function pointer     
*                                                                        
*------------------------------------------------------------------------*/
DEVDRV_LS_INTSRAM_ROCODE void GPTCB_US_Lisr(kal_uint32 vector)
{
    /*ASSERT( (MDGPT_INTR_ID(DRV_GPT_CALLBACK_TIMER) == vector) || \
            (MDGPT_INTR_ID(DRV_GPT_CBUS_TIMER) == vector)          );*/
#if defined(MT6290) && defined(__ARM7EJ_S__)
    IRQClearInt(vector);
#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
    kal_activate_hisr(gpt2_hisrid);
}

#if defined(__L1CORE__)
/*-----------------------------------------------------------------------*
*                                                                            
*                        GPT 1us LISR function,                                  
*                pass to gpt_hw layer as a function pointer     
*                                                                        
*------------------------------------------------------------------------*/
void GPT_DEBUG_Lisr(kal_uint32 vector)
{
    /*ASSERT( (MDGPT_INTR_ID(DRV_GPT_CALLBACK_TIMER) == vector) || \
            (MDGPT_INTR_ID(DRV_GPT_CBUS_TIMER) == vector)          );*/
#if defined(MT6290) && defined(__ARM7EJ_S__)
    IRQClearInt(vector);
#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
	kal_activate_hisr(gpt_debug_hisr);
}
#endif

#if defined(__PCORE__)
/*-----------------------------------------------------------------------*
*                                                                            
*                        GPT ETMR LISR function,                                  
*                    
*                                                                        
*------------------------------------------------------------------------*/
//For TOPSM Test Scenario
#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
void LITEGPT_ETMR_Lisr(kal_uint32 vector)
{
	IRQMask(LITE_GPT_INTR_ID);
	kal_activate_hisr(litegpt_etmr_hisr);
}
#endif
#endif

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize SW GPT module. 
*
* PARAMETERS
*    DCL_STATUS_OK
*
* RETURNS
*  none
*
*------------------------------------------------------------------------*/
DCL_STATUS DclSGPT_Initialize(void)
{
    kal_uint8 index;

    /* Workaroud for LITE GPT interrupt maybe issued after power on!*/
    DRV_WriteReg32_NPW(LITE_GPT_BASE + 0x10, 0x3);

    DCL_GPT_BUS_CLOCK_ON();
    /* GPT hardware reset */
    drv_gpt_reset();
    IRQ_Register_LISR(MDGPT_INTR_ID(DRV_GPT_CALLBACK_TIMER), GPTCB_Lisr, "GPTCBMS");
    IRQ_Register_LISR(MDGPT_INTR_ID(DRV_GPT_CBUS_TIMER), GPTCB_US_Lisr, "GPTCBUS");

#if defined(__L1CORE__)
    IRQ_Register_LISR(MDGPT_INTR_ID(DRV_GPT_DEBUG_TIMER), GPT_DEBUG_Lisr, "GPTDEBUG");

    gpt_debug_hisr = kal_init_hisr(GPT_DEBUG_HISR);
#endif

#if defined(__PCORE__)
//For TOPSM Test Scenario
#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
    //LITE GPT
    IRQ_Register_LISR(LITE_GPT_INTR_ID, LITEGPT_ETMR_Lisr, "GPTETMR");
#endif
    litegpt_etmr_hisr = kal_init_hisr(LITE_GPT_HISR);
#endif

    /* set gpt CB timer */
    drv_gpt_set_timer(DRV_GPT_CALLBACK_TIMER, DCL_GPT_CB_TICK2US, MDGPT_CTRL_MODE_REPEAT);

    /* set gpt CBUS timer */
    drv_gpt_set_timer(DRV_GPT_CBUS_TIMER, DCL_GPT_CBUS_TICK2US, MDGPT_CTRL_MODE_REPEAT);

#if defined(__L1CORE__)
    /* set gpt Debug timer, tick unit = us */
    drv_gpt_set_timer(DRV_GPT_DEBUG_TIMER, DCL_GPT_CBUS_TICK2US, MDGPT_CTRL_MODE_ONESHOT);
#endif

    /* set OS timer */
    drv_gpt_set_timer(DRV_GPT_SYSTEM_TIMER, KAL_MICROSECS_PER_TICK, MDGPT_CTRL_MODE_REPEAT);

#if defined(__PCORE__)
    /* set LITE GPT */
    drv_litegpt_set_timer(DRV_LITEGPT_ETMR_TIMER1, LITEGPT_CNT_MAX, LITEGPT_CTRL_MODE_ONESHOT, LITEGPT_MIN_PRESCALE);

#if !defined(JADE_VER)
    drv_litegpt_set_timer(DRV_LITEGPT_ETMR_TIMER2, LITEGPT_CNT_MAX, LITEGPT_CTRL_MODE_ONESHOT, LITEGPT_MIN_PRESCALE);
#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
    gpt_sm_handle = SleepDrv_GetHandle();//get sleep handler
#endif
#endif

#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
    gpt_26m_handle = MD_TOPSM_SRCLK_SW_Control_GetHandle("LITE GPT");

    gpt_etmr_level2_settle_tick = MD_TOPSM_GetRMResourceSettleTime();
#endif

#endif

    /* gptCB variables are initialized in BSS reset procedure */

    /* Register the GPT CB HISR */
    gpt1_hisrid = kal_init_hisr(GPT1_HISR);
    gpt2_hisrid = kal_init_hisr(GPT2_HISR);

    for (index = 0; index < MAX_GPT_ITEMS; index++)
    {
        gptCB_items[index].gptimer_func = GPT_ERROR_CB;
#if defined(__L1CORE__)
        gpt_DEBUG_items[index].gptimer_func = GPT_ERROR_CB;
#endif
    }

    IRQUnmask(MDGPT_INTR_ID(DRV_GPT_CALLBACK_TIMER));
    IRQUnmask(MDGPT_INTR_ID(DRV_GPT_CBUS_TIMER));

#if defined(__L1CORE__)
    IRQUnmask(MDGPT_INTR_ID(DRV_GPT_DEBUG_TIMER));
#endif

#if defined(__PCORE__)
#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
    //LITE GPT
    IRQSensitivity(LITE_GPT_INTR_ID,LEVEL_SENSITIVE);//Need ?
    IRQUnmask(LITE_GPT_INTR_ID);
#endif
#endif
    
    IRQUnmask(MDGPT_INTR_ID(DRV_GPT_SYSTEM_TIMER));
    DCL_GPT_BUS_CLOCK_OFF();
    
    return STATUS_OK;
}

/*-----------------------------------------------------------------------
* FUNCTION
*  DclSGPT_Open
*
* DESCRIPTION
*  This function is to open the SW GPT module and get a handle. Note that 
* multiple opens are allowed.
*
* PARAMETERS
*    eDev - only valid for DCL_GPT1
*    flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*    DCL_HANDLE_INVALID - Open failed.
*  other value - a valid handle
*
*------------------------------------------------------------------------*/
DCL_HANDLE DclSGPT_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
    kal_uint32 savedMask;
    kal_int32 i;
    if (DCL_GPT_CB==eDev)
    {
//#if defined(__L1CORE__)//L1Core no such user
//	ASSERT(0);
//#endif
        savedMask = SaveAndSetIRQMask();
        for (i=0; i < MAX_GPT_ITEMS; i++)
        {
            if (gptCB_used[i] == 0)
            {
                gptCB_used[i] = 1;
                gptCB_users++;
                RestoreIRQMask(savedMask);
                return DCL_GPT_CB_MAGIC_NUM|i;
            }
        }
        RestoreIRQMask(savedMask);
        // The case that we do NOT return in the loop:
        // Indicate there is NO GPT handle!!!!!
        ASSERT(i < MAX_GPT_ITEMS);
        // return invalid handle
        return DCL_HANDLE_OCCUPIED;
    }
    else if (DCL_GPT_CB_MS==eDev)
    {
//#if defined(__L1CORE__)//L1Core no such user
//	ASSERT(0);
//#endif
        savedMask = SaveAndSetIRQMask();
        if( KAL_FALSE == gptCBUS_used )
        {
            gptCBUS_used = KAL_TRUE;
            RestoreIRQMask(savedMask);
            return DCL_GPT_CBUS_MAGIC_NUM;
        }
        RestoreIRQMask(savedMask);
        
        return DCL_HANDLE_OCCUPIED;
    }

#if defined(__L1CORE__)
    else if (DCL_GPT_DEBUG==eDev)
    {
        savedMask = SaveAndSetIRQMask();
        for (i=0; i < MAX_GPT_ITEMS; i++)
        {
            if (gpt_DEBUG_used[i] == 0)
            {
                gpt_DEBUG_used[i] = 1;
                gpt_DEBUG_users++;
                RestoreIRQMask(savedMask);
                return DCL_GPT_DEBUG_MAGIC_NUM|i;
            }
        }
        RestoreIRQMask(savedMask);
		ASSERT( gpt_DEBUG_users < MAX_GPT_ITEMS );
        // return invalid handle
        return DCL_HANDLE_OCCUPIED;
    }
#endif
#if defined(__PCORE__)
    else if (DCL_LITEGPT_CB_ETMR==eDev)//ETMR using
    {
        savedMask = SaveAndSetIRQMask();
        if(KAL_FALSE == litegptCBETMR_used )
        {
            litegptCBETMR_used = KAL_TRUE;
            RestoreIRQMask(savedMask);
            return DCL_LITEGPT_CBETMR_MAGIC_NUM;
        }
        RestoreIRQMask(savedMask);
        
        return DCL_HANDLE_OCCUPIED;
    }
#endif
    else
    {
        kal_uint32 Invaild_GPT_DEV_Type = 0;

        ASSERT(Invaild_GPT_DEV_Type);
        return DCL_HANDLE_INVALID;
    }
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*    N/A
*
* RETURNS
*    STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*    N/A
*
* RETURNS
*    STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*    N/A
*
* RETURNS
*    STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}


/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*    N/A
*
* RETURNS
*    STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}


/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the SW GPT module.
*
* PARAMETERS
*    handle - a valid handle return by DclSGPT_Open()
*  cmd   - a control command for GPT module
*          1. SGPT_CMD_START: to start a GPT timer
*          2. SGPT_CMD_STOP: to stop a GPT timer
*  data - for 1. SGPT_CMD_START: pointer to a SGPT_CTRL_START_T structure
*             2. SGPT_CMD_STOP: a NULL pointer
*
* RETURNS
*    STATUS_OK - command is executed successfully.
*    STATUS_FAIL - command is failed.
*  STATUS_INVALID_CMD - It's a invalid command.
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    DCL_UINT32 gpt_unknown_command = 0;
    DCL_UINT8  gpt_handle = 0;
    kal_uint32 savedMask;
    gpt_handle = DCL_GPT_CB_GET_DEV(handle) & 0x1F;
    
    if(DCL_GPT_CB_IS_HANDLE_MAGIC(handle))
    {
        switch(cmd)
        {
            case SGPT_CMD_START:
            {
                kal_bool ret_b;
                SGPT_CTRL_START_T  *prStart;

                prStart = &(data->rSGPTStart);
                
                //test if callback function is null.
                ASSERT( NULL!=prStart->pfCallback );
                savedMask = SaveAndSetIRQMask();
                DCL_GPT_BUS_CLOCK_ON(); 
                ret_b = GPTCB_StartItem(gpt_handle, prStart->u2Tick, prStart->pfCallback, prStart->vPara);
                RestoreIRQMask(savedMask);
                if (ret_b == KAL_TRUE)
                {
                    return STATUS_OK;
                }
                else
                {
                    return STATUS_FAIL;
                }
            }
            //break; we can return in any case.
            case SGPT_CMD_STOP:
                GPTCB_StopItem(gpt_handle);
                return STATUS_OK;
            default:
                ASSERT(gpt_unknown_command);
                return STATUS_INVALID_CMD;
        }
    }
    else if(DCL_GPT_CBUS_IS_HANDLE_MAGIC(handle))
    {
        ASSERT( KAL_TRUE == gptCBUS_used );
        switch(cmd)
        {
            case SGPT_CMD_START:
            {
                SGPT_CTRL_START_T  *prStart;
                prStart = &(data->rSGPTStart);

                //test if callback function is null.
                ASSERT( NULL!=prStart->pfCallback );

                savedMask = SaveAndSetIRQMask();
                if( KAL_TRUE == gptCBUS_running )
                {
                    RestoreIRQMask(savedMask);
                    return STATUS_FAIL;
                }
                gptCBUS_instance.tick = prStart->u2Tick*1000; // 1 ms duration
                gptCBUS_instance.gptimer_func = prStart->pfCallback;
                gptCBUS_instance.parameter = prStart->vPara;
                gptCBUS_running = KAL_TRUE;

                DCL_GPT_BUS_CLOCK_ON();
                drv_gpt_set_timer(DRV_GPT_CBUS_TIMER, gptCBUS_instance.tick, MDGPT_CTRL_MODE_ONESHOT);
                drv_gpt_start_timer(DRV_GPT_CBUS_TIMER);
                RestoreIRQMask(savedMask);

                return STATUS_OK;
            }
            //break; we can return in any case.
            case SGPT_CMD_STOP:

                savedMask = SaveAndSetIRQMask();
                drv_gpt_stop_timer(DRV_GPT_CBUS_TIMER);
                gptCBUS_running = KAL_FALSE;
                DCL_GPT_BUS_CLOCK_TRY_OFF();
                RestoreIRQMask(savedMask);

                return STATUS_OK;
            default:
                ASSERT(gpt_unknown_command);
                return STATUS_INVALID_CMD;
        }
    }
#if defined(__L1CORE__)
    else if(DCL_GPT_DEBUG_IS_HANDLE_MAGIC(handle))
    {
        switch(cmd)
        {
            case SGPT_CMD_START:
            {
                SGPT_CTRL_START_T  *prStart;
                prStart = &(data->rSGPTStart);

				GPT_DEBUG_Insert(DCL_GPT_DEBUG_GET_DEV(handle), prStart->u4Tick, prStart->pfCallback, prStart->vPara);

                return STATUS_OK;
            }
            //break; we can return in any case.
            case SGPT_CMD_STOP:
				GPT_DEBUG_Stop(DCL_GPT_DEBUG_GET_DEV(handle));
                return STATUS_OK;
            default:
                ASSERT(gpt_unknown_command);
                return STATUS_INVALID_CMD;
        }
	}
#endif
//ETMR
#if defined(__PCORE__)
    else if(DCL_LITEGPT_CBETMR_IS_HANDLE_MAGIC(handle))
    {
        ASSERT( KAL_TRUE == litegptCBETMR_used );
        switch(cmd)
        {
            case SGPT_CMD_START:
            {
                SGPT_CTRL_START_T  *prStart;
                prStart = &(data->rSGPTStart);

                //test if callback function is null.
                ASSERT( NULL!=prStart->pfCallback );

                savedMask = SaveAndSetIRQMask();
                if( KAL_TRUE == litegptCBETMR_running )
                {
                    RestoreIRQMask(savedMask);
                    return STATUS_FAIL;
                }

#if defined(JADE_VER)

		  if(prStart->u2Tick > (gpt_etmr_level2_settle_tick + 10))	//tick duration is more than 5ms, must enable 2-level GPT
		  {
		  	litegptCBETMR_instance.tick = (prStart->u2Tick - gpt_etmr_level2_settle_tick); // tick number, the duration is prStart->u2Tick*16KHz
		  	/****************************
                	Up line settle time need to modify
                	****************************/
		  	litegptCBETMR_second_level = KAL_TRUE;//enable 2-level GPT
		  	
		  }
		  else//case1, <=5ms level 1 GPT(need lock 26M); case2, user trig 3T GPT count(use GPT2, need lock sleep); Pay attention that level 2 GPT is start in HISR!!
		  {
                	litegptCBETMR_instance.tick = prStart->u2Tick; // tick number, the duration is prStart->u2Tick*16KHz
                	//lock sleep operation, need to add
                	/****************************
                	Add lock 26M??
                	****************************/
                	
			//lock 26M when GPT duration is less than settle time, and unlock 26M when GPT expired
			#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
			MD_TOPSM_SRCLK_SW_Control(gpt_26m_handle, KAL_TRUE);
			#endif
			
		  }
                litegptCBETMR_instance.gptimer_func = prStart->pfCallback;
                litegptCBETMR_instance.parameter = prStart->vPara;

                litegptCBETMR_running = KAL_TRUE;

		  drv_litegpt_set_timer(DRV_LITEGPT_ETMR_TIMER1, litegptCBETMR_instance.tick, LITEGPT_CTRL_MODE_ONESHOT, LITEGPT_MIN_PRESCALE);
		  drv_litegpt_start_timer(DRV_LITEGPT_ETMR_TIMER1);

		  if(KAL_TRUE == litegptCBETMR_second_level)
		  {
		  	gpt_etmr_level2_start_time = gpt_get_current_time();
		  }

		  #ifdef ATEST_DRV_GPT
		  if(KAL_TRUE == litegptCBETMR_second_level)
		  {
		  	gpt_etmr_drvtest_start_time1 = gpt_get_current_time();//stage 1 record
		  }
		  else
		  {
		  	gpt_etmr_drvtest_start_time2 = gpt_get_current_time();//stage 2 record
		  }
		  #endif
		  

#else

		  if(KAL_TRUE == litegptCBETMR_gpt2)//Record GPT STOP -> Re-start duration
                {
			  gpt_etmr_restart_time = gpt_get_current_time();
			  gpt_etmr_duration = UT_GPT_GET_32BIT_COUNTER_DURATION(gpt_etmr_stop_time, gpt_etmr_restart_time);
			  if(gpt_etmr_duration < 92)//Need GPT2 to count
			  {
			  	 //gpt_etmr_restart_time = 0; //re-init global para
				 //gpt_etmr_stop_time = 0;
				 //gpt_etmr_duration = 0;
				 litegptCBETMR_gpt2 = KAL_FALSE;
				 
			  	 RestoreIRQMask(savedMask);
			  	 return STATUS_INVALID_CMD;//remind up layer user START GPT2 
			  }
			  else//Not need GPT2 to count
			  {
			  	 //gpt_etmr_restart_time = 0;//re-init global para
				 //gpt_etmr_stop_time = 0;
				 //gpt_etmr_duration = 0;
				 litegptCBETMR_gpt2 = KAL_FALSE;
			  }
                }
		  else{
		  	 //gpt_etmr_restart_time = 0;//re-init global para
			 //gpt_etmr_stop_time = 0;
			 //gpt_etmr_duration = 0;
		  }

		  if((prStart->u2Tick > (gpt_etmr_level2_settle_tick/2 + 10)) && (prStart->u2Tick != 0xFFFF))//tick duration is more than 5ms, must enable 2-level GPT
		  {
		  	litegptCBETMR_instance.tick = (prStart->u2Tick - gpt_etmr_level2_settle_tick/2); // tick number, the duration is prStart->u2Tick*16KHz
		  	/****************************
                	Up line settle time need to modify
                	****************************/
		  	litegptCBETMR_second_level = KAL_TRUE;//enable 2-level GPT
		  	
		  }
		  else//case1, <=5ms level 1 GPT(need lock 26M); case2, user trig 3T GPT count(use GPT2, need lock sleep); Pay attention that level 2 GPT is start in HISR!!
		  {
                	litegptCBETMR_instance.tick = prStart->u2Tick; // tick number, the duration is prStart->u2Tick*16KHz
                	//lock sleep operation, need to add
                	/****************************
                	Add lock sleep API or 26M??
                	****************************/
                	if(0xFFFF == prStart->u2Tick)//case2, user trig 3T GPT count(use GPT2, need lock sleep)
                	{
				//lock sleep
				//!!!maybe add below line 886!!!
			}
			else//case1, <=5ms level 1 GPT(need lock 26M)
			{
				//lock 26M but first need lock sleep, after 5T lock sleep done, unlock sleep and lock 26M only
				//MD_TOPSM_SRCLK_SW_Control(gpt_26m_handle, KAL_TRUE);
			}
		  }
                litegptCBETMR_instance.gptimer_func = prStart->pfCallback;
                litegptCBETMR_instance.parameter = prStart->vPara;

		  if(0xFFFF != litegptCBETMR_instance.tick)//NOT use GPT2 to count 3T
		  {
                	  litegptCBETMR_running = KAL_TRUE;
		  }

		  if(0xFFFF == litegptCBETMR_instance.tick)//use GPT2 to count 3T
		  {
		  	  drv_litegpt_set_timer(DRV_LITEGPT_ETMR_TIMER2, 0x3, LITEGPT_CTRL_MODE_ONESHOT, LITEGPT_MIN_PRESCALE);
			  drv_litegpt_start_timer(DRV_LITEGPT_ETMR_TIMER2);
		  }
		  else//use GPT1 to count
		  {
			  drv_litegpt_set_timer(DRV_LITEGPT_ETMR_TIMER1, litegptCBETMR_instance.tick, LITEGPT_CTRL_MODE_ONESHOT, LITEGPT_MIN_PRESCALE);
			  drv_litegpt_set_timer(DRV_LITEGPT_ETMR_TIMER2, 0x3, LITEGPT_CTRL_MODE_ONESHOT, LITEGPT_MIN_PRESCALE);//GPT2
			  drv_litegpt_start_timer(DRV_LITEGPT_ETMR_TIMER1);
			  drv_litegpt_start_timer(DRV_LITEGPT_ETMR_TIMER2);//GPT2

			  #ifdef ATEST_DRV_GPT
			  if(KAL_TRUE == litegptCBETMR_second_level)
			  {
			  	gpt_etmr_drvtest_start_time1 = gpt_get_current_time();//stage 1 record
			  }
			  else
			  {
			  	gpt_etmr_drvtest_start_time2 = gpt_get_current_time();//stage 2 record
			  }
			  #endif

			  if(KAL_TRUE == litegptCBETMR_second_level)
			  {
			  	gpt_etmr_level2_start_time = gpt_get_current_time();
			  }
		  }
		  
		  /****************************
            	  Add 5T lock sleep operation? use GPT2?
            	  ****************************/
            	  #if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
            	  SleepDrv_SleepEnable(gpt_sm_handle);
		  #endif

#endif

                RestoreIRQMask(savedMask);
                return STATUS_OK;
            }
            //break; we can return in any case.
            case SGPT_CMD_STOP:
            {
                savedMask = SaveAndSetIRQMask();

		  drv_litegpt_stop_timer(DRV_LITEGPT_ETMR_TIMER1);
                litegptCBETMR_running = KAL_FALSE;

		  if(KAL_TRUE == litegptCBETMR_second_level)
		  {
		  	litegptCBETMR_second_level = KAL_FALSE;
			gpt_etmr_level2_start_time = 0;
			gpt_etmr_level2_stop_time = 0;
			gpt_etmr_level2_duration = 0;
			gpt_etmr_level2_tick = 0;
		  }

		  /****************************
            	  1. Unlock 26M
            	  ****************************/
            	  //Unlock 26M
            	  #if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
	         MD_TOPSM_SRCLK_SW_Control(gpt_26m_handle, KAL_FALSE);
		  #endif


#if !defined(JADE_VER)//TK6291 Version, record STOP time for 3T issue

		  /****************************
            	  2. Unlock Sleep
            	  ****************************/
            	  //Unlock Sleep
            	  //maybe GPT is Stop when in 5T issue stage, at that time system is locked by driver!!
            	  #if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
            	  SleepDrv_SleepDisable(gpt_sm_handle);
		  #endif
		  
		  litegptCBETMR_gpt2 = KAL_TRUE;//enable GPT2
		  gpt_etmr_stop_time = gpt_get_current_time();//get current ust counter

#endif
                
                RestoreIRQMask(savedMask);
                return STATUS_OK;
            }
	     case SGPT_CMD_GET_REMAINING_TICK:
            {
		  SGPT_CTRL_START_T  *prStart;
                prStart = &(data->rSGPTStart);

                savedMask = SaveAndSetIRQMask();

		  if(KAL_FALSE == litegptCBETMR_running)//PU_GPT is STOP!
		  {
		  	prStart->u4Tick = 0;
		  }

#if defined(JADE_VER)
		  else
		  {
			  if(KAL_TRUE == litegptCBETMR_second_level)
			  {
			      prStart->u4Tick = drv_litegpt_time_remaining(DRV_LITEGPT_ETMR_TIMER1) + gpt_etmr_level2_settle_tick;
			  }
			  else
			  {
			      prStart->u4Tick = drv_litegpt_time_remaining(DRV_LITEGPT_ETMR_TIMER1);
			  }
		  }
#else       
                //if( KAL_TRUE == litegptCBETMR_running )
                //{
                    //RestoreIRQMask(savedMask);
                    //return STATUS_FAIL;
                //}
                //ASSERT(KAL_FALSE == litegptCBETMR_gpt2);
                //if(KAL_TRUE == litegptCBETMR_gpt2)//already stopped GPT!!
                //{
                     //prStart->u4Tick = 0;
		  //}
		  else
		  {
			  if(KAL_TRUE == litegptCBETMR_second_level)
			  {
			      prStart->u4Tick = drv_litegpt_time_remaining(DRV_LITEGPT_ETMR_TIMER1) + gpt_etmr_level2_settle_tick/2;
			  }
			  else
			  {
			    prStart->u4Tick = drv_litegpt_time_remaining(DRV_LITEGPT_ETMR_TIMER1);
			  }
		  }
#endif
		
                RestoreIRQMask(savedMask);
                return STATUS_OK;
	     }
            default:
                ASSERT(gpt_unknown_command);
                return STATUS_INVALID_CMD;
        }
    }
#endif
    else
    {
        kal_uint32 Error_DCL_HANDLE = 0;
        //if assert happen here, that means DCL_HANDLE pass in is wrong!
        ASSERT(Error_DCL_HANDLE);
        return DCL_HANDLE_INVALID;
    }
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Close
*
* DESCRIPTION
*  This function is to close the SW GPT module.
*
* PARAMETERS
*    handle  - hanlde previous got from DclSGPT_Open()
*
* RETURNS
*    DCL_STATUS_OK - successfully close the SW GPT module.
*    DCL_STATUS_fail - fails to close the SW GPT module.
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Close(DCL_HANDLE *handle)
{
    DCL_UINT8 gpt_handle;
    kal_uint32 savedMask;
    gpt_handle=DCL_GPT_CB_GET_DEV(*handle) & 0x1F;
    
    if(DCL_GPT_CB_IS_HANDLE_MAGIC(*handle))
    {
        // Make sure the GPT handle is activated
        ASSERT(gptCB_used[gpt_handle]);    

        savedMask = SaveAndSetIRQMask();
        
        if( gptCB_status & (1<<gpt_handle) )
        {
            GPTCB_StopItem(gpt_handle);
        }
        
        gptCB_used[gpt_handle] = 0;
        gptCB_users--;
        
        DCL_GPT_BUS_CLOCK_TRY_OFF();
        RestoreIRQMask(savedMask);
        
        *handle = EMPTY_GPT_CB_HANDLER;
        return STATUS_OK;
    }
    else if(DCL_GPT_CBUS_IS_HANDLE_MAGIC(*handle))
    {
        savedMask = SaveAndSetIRQMask();
        if( KAL_TRUE == gptCBUS_running )
        {
            drv_gpt_stop_timer(DRV_GPT_CBUS_TIMER);
            gptCBUS_running = KAL_FALSE;
        }
        gptCBUS_used = KAL_FALSE;
        *handle = EMPTY_GPT_CB_HANDLER;
        DCL_GPT_BUS_CLOCK_TRY_OFF();
        RestoreIRQMask(savedMask);
        return STATUS_OK;
    }

#if defined(__L1CORE__)
    else if(DCL_GPT_DEBUG_IS_HANDLE_MAGIC(*handle))
    {
		gpt_inst *iter;
        savedMask = SaveAndSetIRQMask();
		iter = gpt_DEBUG_head.next;
		while(NULL!=iter)
		{
			if(iter == &gpt_DEBUG_items[gpt_handle])
			{
				GPT_DEBUG_Stop(gpt_handle);
				break;
			}
		}
        gpt_DEBUG_used[gpt_handle] = 0;
        gpt_DEBUG_users--;
        *handle = EMPTY_GPT_CB_HANDLER;
        DCL_GPT_BUS_CLOCK_TRY_OFF();
        RestoreIRQMask(savedMask);
        return STATUS_OK;
    }
#endif
#if defined(__PCORE__)
    else if(DCL_LITEGPT_CBETMR_IS_HANDLE_MAGIC(*handle))
    {
        savedMask = SaveAndSetIRQMask();

        if( KAL_TRUE == litegptCBETMR_running )
        {
            drv_litegpt_stop_timer(DRV_LITEGPT_ETMR_TIMER1);

#if !defined(JADE_VER)
	     drv_litegpt_stop_timer(DRV_LITEGPT_ETMR_TIMER2);//GPT2 maybe is used in TK6291 3T/5T issue
#endif

            litegptCBETMR_running = KAL_FALSE;
        }
        litegptCBETMR_used = KAL_FALSE;

        litegptCBETMR_second_level = KAL_FALSE;
	 gpt_etmr_level2_start_time = 0;
 	 gpt_etmr_level2_stop_time = 0;
 	 gpt_etmr_level2_duration = 0;
 	 gpt_etmr_level2_tick = 0;

	 /****************************
        1. Unlock 26M
        ****************************/
        //Unlock 26M
        #if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
        MD_TOPSM_SRCLK_SW_Control(gpt_26m_handle, KAL_FALSE);
	 #endif

#if !defined(JADE_VER)

	 /****************************
	 2. Unlock Sleep
	 ****************************/
	 //Unlock Sleep
	 //maybe GPT is Stop when in 5T issue stage, at that time system is locked by driver!!
	 #if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
	 SleepDrv_SleepDisable(gpt_sm_handle);
	 #endif

 	 litegptCBETMR_gpt2    = KAL_FALSE;
 	 gpt_etmr_stop_time = 0;
 	 gpt_etmr_restart_time = 0;
 	 gpt_etmr_duration = 0;
#endif
	 
        *handle = EMPTY_GPT_CB_HANDLER;
        RestoreIRQMask(savedMask);
        return STATUS_OK;
    }
#endif
    else
    {
        kal_uint32 Invalid_DCL_GPT_HANDLE = 0;
        ASSERT(Invalid_DCL_GPT_HANDLE);
        return STATUS_INVALID_DCL_HANDLE;
    }
}

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*    GPTCB_StartItem
*
* DESCRIPTION                                                           
*       GPT CB start a item.
*
* CALLS  
*
* PARAMETERS
*        handler = instance number
*           tick = the delay(the unit is 10ms)
*  gptimer_func = the callback function when the tick is reached.
*     parameter = the parameter inputed into gptimer_func
*
* RETURNS
*    KAL_TRUE, start item successfully
*  KAL_FALSE, start item fail
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
static kal_bool GPTCB_StartItem(DCL_HANDLE handler,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter)
{
    if (gptCB_status & (1<<handler))
    {
        return KAL_FALSE;
    }
   
    gptCB_items[handler].tick = gptCB_ticks + tick;
    gptCB_items[handler].gptimer_func = gptimer_func;
    gptCB_items[handler].parameter = parameter;
   
    if(0 == gptCB_status)
    {
        drv_gpt_start_timer(DRV_GPT_CALLBACK_TIMER);
    }
    gptCB_status |= (1<<handler);

    return KAL_TRUE;
}

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*    GPTCB_StopItem
*
* DESCRIPTION                                                           
*       GPT CB stop a item.
*
* CALLS  
*
* PARAMETERS
*    handler = instance number
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
static void GPTCB_StopItem(DCL_HANDLE handler)
{
    kal_uint32 savedMask;

    ASSERT(gptCB_used[handler]);
    
    savedMask = SaveAndSetIRQMask();
   
    gptCB_status &= ~(1<<handler);
    
    if(0==gptCB_status)
    {
        gptCB_ticks = 0;
        drv_gpt_stop_timer(DRV_GPT_CALLBACK_TIMER);
        DCL_GPT_BUS_CLOCK_TRY_OFF();
    }
    RestoreIRQMask(savedMask);
}

#if defined(__L1CORE__)
static void GPT_DEBUG_Insert(kal_uint32 indx, kal_uint32 tick, void (*fp)(void *) ,void *parameter)
{
	kal_uint32 savedMask;
	kal_uint32 elapsed, time; /* elapsed: current - start time; time: eariest time-out setting */
	gpt_inst *iter = gpt_DEBUG_head.next;

    ASSERT( NULL!=fp );
    gpt_DEBUG_items[indx].gptimer_func = fp;
    gpt_DEBUG_items[indx].param = parameter;

    savedMask = SaveAndSetIRQMask();

	elapsed = drv_gpt_get_data(DRV_GPT_DEBUG_TIMER);
    drv_gpt_stop_timer(DRV_GPT_DEBUG_TIMER);

	if( (NULL == gpt_DEBUG_head.next))
	{
		gpt_DEBUG_head.next = &gpt_DEBUG_items[indx];
		time = tick;
        DCL_GPT_BUS_CLOCK_ON();
	}
	else if((iter->ticks-elapsed) > tick)
	{
		gpt_DEBUG_items[indx].next = iter;
		gpt_DEBUG_head.next = &gpt_DEBUG_items[indx];
		iter->ticks -= elapsed + tick;
		time = tick;
	}
	else
	{
		time = iter->ticks - elapsed;
		tick -= time;
		iter->ticks = time;
		while( NULL != iter->next )
		{
			if(iter->next->ticks > tick)
			{
				gpt_DEBUG_items[indx].next = iter->next;
				gpt_DEBUG_items[indx].next->ticks -= tick;
				iter->next = &gpt_DEBUG_items[indx];
				break;
			}
			iter = iter->next;
			tick -= iter->ticks;
		}
		if(NULL == iter->next)
		{
			gpt_DEBUG_items[indx].next = NULL;
			iter->next = &gpt_DEBUG_items[indx];
		}
	}
	gpt_DEBUG_items[indx].ticks = tick;

    //test if callback function is null.
    drv_gpt_set_timer(DRV_GPT_DEBUG_TIMER, time, MDGPT_CTRL_MODE_ONESHOT);
    drv_gpt_start_timer(DRV_GPT_DEBUG_TIMER);

    RestoreIRQMask(savedMask);
}

/*-----------------------------------------------------------------------
* FUNCTION                                                            
*    GPT_DEBUG_Stop
*
* DESCRIPTION                                                           
*    Remove Debug Timer Instance from queue
*
* CALLS  
*
* PARAMETERS
*    indx = instance number
*
* RETURNS
*    None
*
*------------------------------------------------------------------------*/
static void GPT_DEBUG_Stop(kal_uint32 indx)
{
	kal_uint32 savedMask;
	gpt_inst *iter = &gpt_DEBUG_head;

    savedMask = SaveAndSetIRQMask();

	while( (iter->next!=&gpt_DEBUG_items[indx]) && (NULL!=iter->next) )
	{
		iter = iter->next;
	}
	ASSERT(NULL!=iter->next);

	if(iter == &gpt_DEBUG_head)
	{
	    kal_uint32 elapsed;
	    elapsed = drv_gpt_get_data(DRV_GPT_DEBUG_TIMER);
        drv_gpt_stop_timer(DRV_GPT_DEBUG_TIMER);
		IRQClearInt(MDGPT_INTR_ID(DRV_GPT_DEBUG_TIMER));

	    gpt_DEBUG_head.next = gpt_DEBUG_items[indx].next;
		if(NULL != gpt_DEBUG_head.next)
		{
			gpt_DEBUG_head.next->ticks = gpt_DEBUG_head.next->ticks - elapsed + gpt_DEBUG_items[indx].ticks ;
            drv_gpt_set_timer(DRV_GPT_DEBUG_TIMER, gpt_DEBUG_head.next->ticks, MDGPT_CTRL_MODE_ONESHOT);
            drv_gpt_start_timer(DRV_GPT_DEBUG_TIMER);
		}
		else
		{
            DCL_GPT_BUS_CLOCK_TRY_OFF();
		}
	}
	else
	{
		if(NULL != gpt_DEBUG_items[indx].next)
		{
			gpt_DEBUG_items[indx].next->ticks += gpt_DEBUG_items[indx].ticks;
		}
		iter->next = iter->next->next;
	}
	gpt_DEBUG_items[indx].next = NULL;
    RestoreIRQMask(savedMask);
}
#endif

/*-----------------------------------------------------------------------
* FUNCTION                                                            
*    GPTCB_10MS_HISR
*
* DESCRIPTION                                                           
*       GPT Callback HISR : 10ms
*
* CALLS
*
* PARAMETERS
*    void
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
DEVDRV_LS_INTSRAM_ROCODE void GPTCB_10MS_HISR(void)
{
    kal_uint8 index; 
    kal_uint32 savedMask;
    kal_uint32 checkMask = 0xFFFFFFFF;
    IFDEF_GPT_TRACE(kal_uint32 time1);
    IFDEF_GPT_TRACE(kal_uint32 time2);

    gptCB_ticks++;
    
    // Bit matched method to check if a GPT items is activated
    // Search whole GPT items
    for (index = 0; (index < MAX_GPT_ITEMS)&&(gptCB_status&checkMask); index++)
    {
        savedMask = SaveAndSetIRQMask();
        if( (gptCB_status & (1 << index)) && (gptCB_ticks >= gptCB_items[index].tick) )
        {
            gptCB_status &= ~(1<<index);
            RestoreIRQMask(savedMask);
            IFDEF_GPT_TRACE(time1 = ust_get_current_time());
#if defined(__CR4__)
            IFDEF_GPT_CB_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(gpt_cb_enter_time[index]));
#elif defined(__MTK_MMU_V2__) /* __CR4__ */
            IFDEF_GPT_CB_MEASURE_TIME(gpt_cb_enter_time[index]=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif /* __MTK_MMU_V2__ */
            gptCB_items[index].gptimer_func(gptCB_items[index].parameter);
#if defined(__CR4__)
            IFDEF_GPT_CB_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(gpt_cb_leave_time[index]));
#elif defined(__MTK_MMU_V2__) /* __CR4__ */
            IFDEF_GPT_CB_MEASURE_TIME(gpt_cb_leave_time[index]=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif /* __MTK_MMU_V2__ */
            IFDEF_GPT_TRACE(time2 = ust_get_current_time());
            GPT_DBG(index, time1, time2);
        }
        else
        {
            RestoreIRQMask(savedMask);
        }
        checkMask ^= (1 << index);
    }
    
    savedMask = SaveAndSetIRQMask();

    if (gptCB_status == 0)
    {
        // UT Test road test.
        gptCB_ticks = 0;
        drv_gpt_stop_timer(DRV_GPT_CALLBACK_TIMER);
        DCL_GPT_BUS_CLOCK_TRY_OFF();
    }
    RestoreIRQMask(savedMask);
}


/*-----------------------------------------------------------------------
* FUNCTION                                                            
*    GPTCB_Debug_HISR
*
* DESCRIPTION                                                           
*       GPT Callback HISR : 1us
*
* CALLS
*
* PARAMETERS
*    void
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
#if defined(__L1CORE__)
void GPTCB_DEBUG_HISR(void)
{
    //if(NULL != gpt_DEBUG_head.next->gptimer_func)
    {
        gpt_DEBUG_head.next->gptimer_func(gpt_DEBUG_head.next->param);
    }
#if !defined(ATEST_DRV_ENABLE) && !defined(DSPFNC_DSP_SWTRACER)
    ASSERT(0);
#endif /* !ATEST_DRV_ENABLE */
}
#endif
/*-----------------------------------------------------------------------
* FUNCTION                                                            
*    GPTCB_US_HISR
*
* DESCRIPTION                                                           
*       GPT Callback HISR : 10ms
*
* CALLS
*
* PARAMETERS
*    void
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
DEVDRV_LS_INTSRAM_ROCODE void GPTCB_US_HISR(void)
{
    kal_uint32 savedMask;

    savedMask = SaveAndSetIRQMask();
    if( KAL_TRUE == gptCBUS_running )
    {
        gptCBUS_running = KAL_FALSE;
        RestoreIRQMask(savedMask);
#if defined(__CR4__)
        IFDEF_GPT_CB_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(gpt_uscb_enter_time));
#elif defined(__MTK_MMU_V2__) /* __CR4__ */
        IFDEF_GPT_CB_MEASURE_TIME(gpt_uscb_enter_time=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif /* __MTK_MMU_V2__ */
        gptCBUS_instance.gptimer_func(gptCBUS_instance.parameter);
#if defined(__CR4__)
        IFDEF_GPT_CB_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(gpt_uscb_leave_time));
#elif defined(__MTK_MMU_V2__) /* __CR4__ */
        IFDEF_GPT_CB_MEASURE_TIME(gpt_uscb_leave_time=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif /* __MTK_MMU_V2__ */
    }
    else
    {
        RestoreIRQMask(savedMask);
    }
    savedMask = SaveAndSetIRQMask();
    DCL_GPT_BUS_CLOCK_TRY_OFF();
    RestoreIRQMask(savedMask);
}

/*-----------------------------------------------------------------------
* FUNCTION                                                            
*    GPTETMR_US_HISR
*
* DESCRIPTION                                                           
*       GPT Callback HISR for ETMR
*
* CALLS
*
* PARAMETERS
*    void
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
#if defined(__PCORE__)

DEVDRV_LS_INTSRAM_ROCODE void LITEGPT_ETMR_HISR(void)
{
	kal_uint32 savedMask;
	kal_uint16 GPT_Status;

    	savedMask = SaveAndSetIRQMask();

#if defined(JADE_VER)

	//drv_litegpt_clr_wakeup_event();//clr INT and Wakeup Event
	GPT_Status = DRV_Reg32(LITE_GPT_BASE + 0x10);
	//DRV_WriteReg32_NPW(LITE_GPT_BASE + 0x10, GPT_Status);//W1C interrupt status

	DRV_WriteReg32_NPW(LITE_GPT_BASE + 0x34, GPT_Status); //clear wakeup event/interrupt

	if(GPT_Status & 0x0004)//PU_GPT1 Expired
	{
		if( KAL_TRUE == litegptCBETMR_running )
		{
			litegptCBETMR_running = KAL_FALSE;
			if(KAL_TRUE == litegptCBETMR_second_level)//Two LEVEL GPT stage 1
			{
				gpt_etmr_level2_stop_time = gpt_get_current_time();
			       gpt_etmr_level2_duration = UT_GPT_GET_32BIT_COUNTER_DURATION(gpt_etmr_level2_start_time, gpt_etmr_level2_stop_time);

				ASSERT(LITEGPT_US_TO_TICK(gpt_etmr_level2_duration) <= (litegptCBETMR_instance.tick + gpt_etmr_level2_settle_tick));
				
			       gpt_etmr_level2_tick = (gpt_etmr_level2_settle_tick - LITEGPT_US_TO_TICK(gpt_etmr_level2_duration) + litegptCBETMR_instance.tick);
				
			       litegptCBETMR_instance.tick = gpt_etmr_level2_tick;
			       if(litegptCBETMR_instance.tick >= 10)//need level 2 GPT
			       {
			  	
				     litegptCBETMR_second_level = KAL_FALSE;
				     litegptCBETMR_running = KAL_TRUE;
				
			  	     drv_litegpt_set_timer(DRV_LITEGPT_ETMR_TIMER1, litegptCBETMR_instance.tick, LITEGPT_CTRL_MODE_ONESHOT, LITEGPT_MIN_PRESCALE);
 			            drv_litegpt_start_timer(DRV_LITEGPT_ETMR_TIMER1);
				     /****************************
	            	            stage 2 GPT need lock 26M
	            	            unlock in
	            	            1. STOP CMD
	            	            2. Close CMD
	            	            3. Timeout HISR operation
	            	            ****************************/
	            	            //lock 26M
	            	            //lock 26M when GPT duration is less than settle time, and unlock 26M when GPT expired
	            	            #if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
				     MD_TOPSM_SRCLK_SW_Control(gpt_26m_handle, KAL_TRUE);
				     #endif
			       }
			       else
			       {
				     litegptCBETMR_second_level = KAL_FALSE;
			  	     litegptCBETMR_instance.gptimer_func(litegptCBETMR_instance.parameter);//excute CB function
			       }
			}
			else
			{
				/****************************
	            	       1. previous operation is lock 26M
	            	       here need unlock 26M clock
	            	       ****************************/
	            	       //unlock 26M
	            	       #if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
			       MD_TOPSM_SRCLK_SW_Control(gpt_26m_handle, KAL_FALSE);
				#endif
				
		    	       litegptCBETMR_instance.gptimer_func(litegptCBETMR_instance.parameter);//excute CB function
			}
		}
		else
		{
			RestoreIRQMask(savedMask);
		       IRQUnmask(LITE_GPT_INTR_ID);
		       ASSERT(0);//only one GPT is using at one time
		}
	}
	if(GPT_Status & 0x0008)//PU_GPT2 Expired
	{
		RestoreIRQMask(savedMask);
		IRQUnmask(LITE_GPT_INTR_ID);
		ASSERT(0);//JADE PU_GPT2 is not used
	}

#else
	//drv_litegpt_clr_wakeup_event();//clr INT and Wakeup Event
	GPT_Status = DRV_Reg32(LITE_GPT_BASE + 0x10);
	DRV_WriteReg32_NPW(LITE_GPT_BASE + 0x10, GPT_Status);//W1C interrupt status

	DRV_WriteReg32_NPW(LITE_GPT_BASE + 0x34, 0x3); //clear wakeup event

	if(GPT_Status & 0x0001)//GPT1 Expired
	{
		if( KAL_TRUE == litegptCBETMR_running )
		{
		    litegptCBETMR_running = KAL_FALSE;
		    //RestoreIRQMask(savedMask);

		    if(KAL_TRUE == litegptCBETMR_second_level)//Two LEVEL GPT stage 1
		    {
			  gpt_etmr_level2_stop_time = gpt_get_current_time();
			  gpt_etmr_level2_duration = UT_GPT_GET_32BIT_COUNTER_DURATION(gpt_etmr_level2_start_time, gpt_etmr_level2_stop_time);
			  
			  ASSERT(LITEGPT_US_TO_TICK(gpt_etmr_level2_duration) <= (litegptCBETMR_instance.tick + gpt_etmr_level2_settle_tick/2));
			  
			  gpt_etmr_level2_tick = (gpt_etmr_level2_settle_tick/2 - LITEGPT_US_TO_TICK(gpt_etmr_level2_duration) + litegptCBETMR_instance.tick);
			  
			  litegptCBETMR_instance.tick = gpt_etmr_level2_tick;
			  if(litegptCBETMR_instance.tick >= 10)//need level 2 GPT
			  {
			  	
				litegptCBETMR_second_level = KAL_FALSE;
				litegptCBETMR_running = KAL_TRUE;
				
			  	drv_litegpt_set_timer(DRV_LITEGPT_ETMR_TIMER1, litegptCBETMR_instance.tick, LITEGPT_CTRL_MODE_ONESHOT, LITEGPT_MIN_PRESCALE);
 			       drv_litegpt_set_timer(DRV_LITEGPT_ETMR_TIMER2, 0x3, LITEGPT_CTRL_MODE_ONESHOT, LITEGPT_MIN_PRESCALE);//GPT2
 			       drv_litegpt_start_timer(DRV_LITEGPT_ETMR_TIMER1);
 			       drv_litegpt_start_timer(DRV_LITEGPT_ETMR_TIMER2);//GPT2

				#ifdef ATEST_DRV_GPT
				gpt_etmr_drvtest_start_time2 = gpt_get_current_time();//Stage 2 5T recorder
				#endif

				/****************************
	                	1. lock Sleep for 5T, will unlock in GPT2 HISR below
	                	****************************/
				//lock Sleep
				#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
				SleepDrv_SleepEnable(gpt_sm_handle);
				#endif

				/****************************
	                	2. level 2 GPT stage, need lock 26M clock
	                	****************************/
	                	//lock 26M
	                	//MD_TOPSM_SRCLK_SW_Control(gpt_26m_handle, KAL_TRUE);
				
			  }
			  else
			  {
			  	//gpt_etmr_level2_start_time = 0;
			 	//gpt_etmr_level2_stop_time = 0;
			 	//gpt_etmr_level2_duration = 0;
			 	//gpt_etmr_level2_tick = 0;

				litegptCBETMR_second_level = KAL_FALSE;
				
			  	litegptCBETMR_instance.gptimer_func(litegptCBETMR_instance.parameter);//excute CB function
			  }
		    }
		    else //Two LEVEL GPT stage 2 or GPT start duration less than 5ms
		    {

			  /****************************
                	  1. previous operation is lock 26M
                	  here need unlock 26M clock
                	  ****************************/
                	  //unlock 26M
			  #if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
		         MD_TOPSM_SRCLK_SW_Control(gpt_26m_handle, KAL_FALSE);
			  #endif
                	  
		    	  litegptCBETMR_instance.gptimer_func(litegptCBETMR_instance.parameter);//excute CB function
		    }
		    //RestoreIRQMask(savedMask);

		}
		else
		{
		    RestoreIRQMask(savedMask);
		    IRQUnmask(LITE_GPT_INTR_ID);
		    ASSERT(0);//only one GPT is using at one time
		}
	}
	if(GPT_Status & 0x0002)//GPT2 Expired
	{
		if(0xFFFF == litegptCBETMR_instance.tick)//use GPT2 as count STOP->START 3T duration
		{
			/****************************
                	1. Unlock Sleep
                	****************************/
                	//Unlock Sleep
                	#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
                	SleepDrv_SleepDisable(gpt_sm_handle);
			#endif
                	
			/****************************
                	2. Execute CB function
                	****************************/
                	litegptCBETMR_instance.gptimer_func(litegptCBETMR_instance.parameter);//excute CB function
                	
                	#ifdef ATEST_DRV_GPT
			gpt_etmr_drvtest_stop_time1 = gpt_get_current_time();//Stage 1 5T recorder
			gpt_etmr_drvtest_duration1 = UT_GPT_GET_32BIT_COUNTER_DURATION(gpt_etmr_drvtest_start_time1, gpt_etmr_drvtest_stop_time1);
			#endif
		}
		else//use GPT2 as count to lock sleep 5T duration
		{
			/****************************
                	1. Unlock Sleep, level 1 GPT do not lock 26M
                	****************************/
			//Unlock Sleep
			#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
			SleepDrv_SleepDisable(gpt_sm_handle);
			#endif

			//if(litegptCBETMR_instance.tick <= (gpt_etmr_level2_settle_tick/2 + 10))//this indicate GPT is in level 2 stage, lock 26M
			if(KAL_FALSE == litegptCBETMR_second_level)
			{
				/****************************
	                	Up line settle time need to modify
	                	****************************/
	                	
				/****************************
	                	2. level 2 GPT stage, need lock 26M clock
	                	****************************/
	                	//lock 26M
	                	#if !defined(ATEST_DRV_ENABLE) || (defined(ATEST_DRV_ENABLE) && defined(ATEST_DRV_GPT))
	                	MD_TOPSM_SRCLK_SW_Control(gpt_26m_handle, KAL_TRUE);
				#endif

				#ifdef ATEST_DRV_GPT
				gpt_etmr_drvtest_stop_time2 = gpt_get_current_time();//Stage 2 5T recorder
				gpt_etmr_drvtest_duration2 = UT_GPT_GET_32BIT_COUNTER_DURATION(gpt_etmr_drvtest_start_time2, gpt_etmr_drvtest_stop_time2);
				#endif
			}
			#ifdef ATEST_DRV_GPT
			else
			{
				gpt_etmr_drvtest_stop_time1 = gpt_get_current_time();//Stage 1 5T recorder
				gpt_etmr_drvtest_duration1 = UT_GPT_GET_32BIT_COUNTER_DURATION(gpt_etmr_drvtest_start_time1, gpt_etmr_drvtest_stop_time1);
			}
			#endif
			
		}
	}

#endif

	RestoreIRQMask(savedMask);
	IRQUnmask(LITE_GPT_INTR_ID);
}
#endif
#else /* else of !defined(DRV_GPT_OFF) */

DCL_STATUS DclSGPT_Initialize(void)
{
    return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclSGPT_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Close(DCL_HANDLE *handle)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Initialize(void)
{
    return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclFGPT_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Close(DCL_HANDLE handle)
{
    return STATUS_UNSUPPORTED;
}
#if defined (__ESL_COSIM_LTE__)
void GPTCB_DEBUG_HISR(void)
{
}

#if defined(__PCORE__)
void LITEGPT_ETMR_HISR(void)
{
}
#endif

#endif /* __ESL_COSIM_LTE__ */
#endif /* end of else of !defined(DRV_GPT_OFF) */

DCL_HANDLE DclHGPT_Open(DCL_DEV dev, DCL_FLAGS flags){return STATUS_UNSUPPORTED;}
DCL_STATUS DclHGPT_Control(DCL_HANDLE handle, HGPT_CMD cmd, HGPT_CTRL *data){return STATUS_UNSUPPORTED;}
DCL_STATUS DclHGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){return STATUS_UNSUPPORTED;}
DCL_STATUS DclHGPT_Close(DCL_HANDLE handle){return STATUS_UNSUPPORTED;}

//#endif 

