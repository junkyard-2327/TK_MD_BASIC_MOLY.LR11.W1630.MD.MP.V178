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
 *   ect.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
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
 *
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*******************************************************************************
 * Include header files.
 *******************************************************************************/
#include "ect.h"
#include "init.h"
#include "intrCtrl.h"
#include "reg_base.h"
#include "sleepdrv_interface.h"
#include "ex_public.h"
#include "cp15.h"
#include "drv_pcmon.h"
#include "us_timer.h"
#if defined(__L1CORE__)
#include "RM_public.h"

#include "dsp_file_public.h"
#else
#include "svc_sap.h"
#include "hif_svc_msgid.h"
#include "ccci_if.h" 
#endif /* __L1CORE__ */


/*******************************************************************************
 * Macro
 *******************************************************************************/

#define __intsram_zi__     __attribute__((zero_init, section("INTSRAM_ZI")))
#define __intsram_rocode__       __attribute__ ((section ("INTSRAM_ROCODE")))

/* ECT register offsets */
#define CTIREGSZ    (0x1000)
#define CTICONTROL  (0x00)
#define CTIINTACK   (0x10)
#define CTIINEN0    (0x20)
#define CTIINEN1    (0x24)
#define CTIINEN2    (0x28)
#define CTIINEN3    (0x2C)
#define CTIINEN4    (0x30)
#define CTIINEN5    (0x34)
#define CTIINEN6    (0x38)
#define CTIINEN7    (0x3C)

#define CTIOUTEN0   (0xA0)
#define CTIOUTEN1   (0xA4)
#define CTIOUTEN2   (0xA8)
#define CTIOUTEN3   (0xAC)
#define CTIOUTEN4   (0xb0)
#define CTIOUTEN5   (0xB4)
#define CTIOUTEN6   (0xB8)
#define CTIOUTEN7   (0xBC)

#define CTITRIGINSTATUS     (0x130)
#define CTITRIGOUTSTATUS    (0x134)
#define LAR             (0xFB0)
#define LSR             (0xFB4)

/*the following registers should be 0x06, 0xB9, 0x4B, 0x0*/
/*#define CTIPERIPHID0    (0xFE0)*/
/*#define CTIPERIPHID1    (0xFE4)*/
/*#define CTIPERIPHID2    (0xFE8)*/
/*#define CTIPERIPHID3    (0xFEC)*/

#define CTI_MAGIC           (0xC5ACCE55)

/* Platform dependent setting */
/* CTI events */
#define L1_CTI_EVENT        (0xF6030080)
#define PS_CTI_EVENT        (0xF6040080)


#define PS_CTI              (BASE_MADDR_PS_CTI)
#define L1_CTI              (BASE_MADDR_L1_CTI)
#define MD_CTI              (BASE_MADDR_MD_CTI)

/* channel setting */
#define CH_NON (0x0)
#define CH_RST (0x1 << 0)
#define CH_EXP (0x1 << 1)
#define CH_DBG (0x1 << 2)

/* we will disable RMPU for user load */
#ifndef __PRODUCTION_RELEASE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __PRODUCTION_RELEASE__ */ 

#define CH_RMPU CH_NON 

#endif //ifndef __PRODUCTION_RELEASE__

/* REG RW */
#define REG_WRITE32(addr, val)  do{ *(volatile kal_uint32 *)(addr) = (val); }while(0)
#define REG_READ32(var, addr)   do{ (var) = *(volatile kal_uint32 *)(addr); }while(0)
/*******************************************************************************
 * Instance
 *******************************************************************************/
/* control variables */
/* g_ect_dsp is used to control if DSPs shoudl break when CR4s break */
/* default value is 0x1, which means DSPs dose not break if CR4s break */
/* it could be changed by CVD button */
/* 0x1 --> do not break DSPs when CR4s break (default) */
/* 0x2 --> break DSPs when CR4s break (configured by .cmm) */
__attribute__ ((section ("DRAM_EX_ROCODE"))) volatile const kal_uint32 g_ect_dsp = 0x1;

EX_BBREG_DUMP cti_dump;
const kal_uint32 cti_dump_regions[] = {
    PS_CTI, CTIREGSZ, 4,        // PS CTI
    L1_CTI, CTIREGSZ, 4,        // L1 CTI
    MD_CTI, CTIREGSZ, 4,        // MD CTI
};


__intsram_zi__ volatile kal_uint32 cti_dbgclock_start = 0;
__intsram_zi__ volatile kal_uint32 cti_dbgclock_end = 0;

__intsram_zi__ volatile kal_uint32 cti_dbgclock_start_exp = 0;
__intsram_zi__ volatile kal_uint32 cti_dbgclock_end_exp = 0;

__intsram_zi__ volatile kal_uint32 cti_pcmon_backup_start = 0;
__intsram_zi__ volatile kal_uint32 cti_pcmon_backup_end = 0;
__intsram_zi__ volatile kal_uint32 cti_pcmon_backup_timestamp = 0;

__intsram_zi__ volatile kal_uint32 cti_rmpu_check_start = 0;
__intsram_zi__ volatile kal_uint32 cti_rmpu_check_end = 0;

__intsram_zi__ volatile kal_uint32 cti_rmpu_read_disable_start = 0;
__intsram_zi__ volatile kal_uint32 cti_rmpu_read_disable_end = 0;



#define ECT_PCMON_DATA_NUM    5

typedef struct _ECT_PCMON_BK_INDEX_STRUCT {
    kal_uint32 count;
    kal_uint32 index;
    kal_uint32 frc_time[ECT_PCMON_DATA_NUM];
} ECT_PCMON_BK_INDEX_STRUCT;


PCM_RECORD ect_pcmon_bk[ECT_PCMON_DATA_NUM];
__intsram_zi__ ECT_PCMON_BK_INDEX_STRUCT ect_pcmon_bk_index;

__intsram_zi__ kal_uint32 PS_CTI_TriggerIn_Status;
__intsram_zi__ kal_uint32 L1_CTI_TriggerIn_Status;
__intsram_zi__ kal_uint32 DSP_CTI_TriggerIn_Status;
__intsram_zi__ kal_uint32 PCmon_Stop_Src;

kal_timerid ect_rmpu_timer_id = NULL;
kal_uint32 CTI_RMPU_Resume_Count = 0;
kal_uint32 CTI_RMPU_Set_Timer_Count = 0;
kal_uint32 CTI_RMPU_Cancel_Timer_Count = 0;


#ifdef __L1CORE__
kal_bool l1_dbgapb_pwr = KAL_FALSE;
volatile kal_uint32 l1_cti_wait_topsm_start_time;
volatile kal_uint32 l1_cti_wait_topsm_current_time;
volatile kal_uint32 l1_cti_enable_dbgclk_start;
volatile kal_uint32 l1_cti_enable_dbgclk_end;
#endif /* __L1CORE__ */



/*******************************************************************************
 * Foward declaration 
 *******************************************************************************/
#ifdef __L1CORE__
extern kal_bool RM_Resource_CheckReady( RM_Module module );
#endif  //__L1CORE__

extern void CTI_Triggered_ex_handler();

kal_bool ECT_DumpCallback(void);
void ECT_Enable_Dbgclk(void);


/*******************************************************************************
 * Functions 
 *******************************************************************************/

/*************************************************************************
* FUNCTION
*  ECT_Init_ReEnable_RMPU
*
* DESCRIPTION
*  ECT_Init_ReEnable_RMPU
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/		
void ECT_Init_ReEnable_RMPU(void)
{
#if defined(__PCORE__)
    ECT_Enable_Dbgclk();
    REG_WRITE32(PS_CTI + CTIINTACK, (1<<3));
    IRQClearInt(IRQ_ECT_CODE);

#else
    ECT_Enable_Dbgclk();
    REG_WRITE32(L1_CTI + CTIINTACK, (1<<3));
    IRQClearInt(L1_L1MCU_ECT_IRQ_B);
#endif
}


/*************************************************************************
* FUNCTION
*  ECT_ReEnable_RMPU
*
* DESCRIPTION
*  ECT_ReEnable_RMPU
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/		
void ECT_ReEnable_RMPU(void)
{
    ECT_Enable_Dbgclk();
#if defined(__PCORE__)
    REG_WRITE32(PS_CTI + CTIOUTEN3, CH_EXP | CH_RMPU);
#else
    REG_WRITE32(L1_CTI + CTIOUTEN3, CH_EXP | CH_RMPU);
#endif
}

/*************************************************************************
* FUNCTION
*  ECT_ReEnable_RMPU_PCMON_CTI
*
* DESCRIPTION
*  ECT_ReEnable_RMPU_PCMON_CTI
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/		
void ECT_ReEnable_RMPU_PCMON_CTI(void)
{
    CTI_RMPU_Resume_Count++;
    if(KAL_TRUE== drv_pcm_is_backup_done())
    {
        drv_pcm_mask_stop_source(PCMON_SRC_RMPU,KAL_FALSE);
        CTI_RMPU_Cancel_Timer_Count++;
        kal_cancel_timer(ect_rmpu_timer_id);
        ECT_ReEnable_RMPU();
    }
}

/*************************************************************************
* FUNCTION
*  ECT_RMPU_Resume
*
* DESCRIPTION
*  resume ECT RMPU
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/		
void ECT_RMPU_Resume(kal_uint32 para)
{
#if defined(__PCORE__)
    //Pcore send msg to L1core for L1 ack
    msg_send6_cc(MOD_ECT, MOD_CCCIMSG_L1CORE, CCCISRV_SAP, 
		MSG_ID_CCCI_EMI_ACCESS_VIOLATION_L1C_IND, NULL, NULL);

#endif
    //resume ECT RMPU
	CTI_RMPU_Set_Timer_Count++;
	kal_set_timer(ect_rmpu_timer_id, (kal_timer_func_ptr)ECT_ReEnable_RMPU_PCMON_CTI, NULL, KAL_TICKS_10_MSEC/10, KAL_TICKS_10_MSEC/10);
	
}


/*************************************************************************
* FUNCTION
*  ECT_Init
*
* DESCRIPTION
*  ECT initialization
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/		
void ECT_Init(void)
{
#if defined(__PCORE__)        

    /* enable DBG APB clock */
    cti_dbgclock_start = cp15_PMU_read_cycle_counter();
    MD_TOPSM_PLL_SW_Control(PS_PLL_FORCEON_USER_CTI, PS_TOPSM_DBG_PLL, KAL_TRUE);
    cti_dbgclock_end = cp15_PMU_read_cycle_counter();

    /* enter magic key */ 
    REG_WRITE32(PS_CTI + LAR, CTI_MAGIC);
    REG_WRITE32(L1_CTI + LAR, CTI_MAGIC);
    REG_WRITE32(MD_CTI + LAR, CTI_MAGIC);

#if defined(TK6291)
    /* setting exception propagation */
    /* PS CTI part */
    /*********************PS_CTI**********************
        I                   O
    7   psmcu_rccif         DBGRESTART
    6   1'b1
    5   COMMTX
    4   COMMRX
    3   rmpu                psmcu_ect_irq_b
    2   arm7_rccif          arm7_ect_irq_b
    1   nPMUIQ
    0   DEBACK              EDBGRQ
    **************************************************/
    REG_WRITE32(PS_CTI + CTIINEN7, CH_EXP);
    REG_WRITE32(PS_CTI + CTIINEN0, CH_DBG);
    REG_WRITE32(PS_CTI + CTIINEN2, CH_EXP);
    REG_WRITE32(PS_CTI + CTIINEN3, CH_RMPU);
    
    REG_WRITE32(PS_CTI + CTIOUTEN3, CH_EXP | CH_RMPU);
    REG_WRITE32(PS_CTI + CTIOUTEN0, CH_DBG);
    REG_WRITE32(PS_CTI + CTIOUTEN2, CH_EXP);
    
    /* restart */
    // mark the following statement since AP don't want us to tie it
    /*REG_WRITE32(PS_CTI + CTIINEN6,  CH_RST);*/
    // Note: to resume PSCORE, write 0xF00A80BC to 0x1
#else
    /* setting exception propagation */
    /* PS CTI part */
    /*********************PS_CTI**********************
        I                   O
    7   psmcu_rccif         DBGRESTART
    6   1'b1
    5   COMMTX
    4   COMMRX
    3   rmpu                psmcu_ect_irq_b
    2   arm7_rccif          arm7_ect_irq_b
    1   C2K_TRIGGIN         C2K_TRIGGOUT
    0   DEBACK              EDBGRQ
    **************************************************/
    REG_WRITE32(PS_CTI + CTIINEN0, CH_DBG);
    REG_WRITE32(PS_CTI + CTIINEN1, CH_EXP);
    REG_WRITE32(PS_CTI + CTIINEN2, CH_EXP);
    REG_WRITE32(PS_CTI + CTIINEN3, CH_RMPU);
    REG_WRITE32(PS_CTI + CTIINEN7, CH_EXP);
    
    REG_WRITE32(PS_CTI + CTIOUTEN0, CH_DBG);
    REG_WRITE32(PS_CTI + CTIOUTEN1, CH_EXP);
    REG_WRITE32(PS_CTI + CTIOUTEN2, CH_EXP);
    REG_WRITE32(PS_CTI + CTIOUTEN3, CH_EXP | CH_RMPU);
    
    /* restart */
    // mark the following statement since AP don't want us to tie it
    /*REG_WRITE32(PS_CTI + CTIINEN6,  CH_RST);*/
    // Note: to resume PSCORE, write 0xF00A80BC to 0x1
#endif  /*TK6291*/
    
    /* MD CTI part */
    /*********************MD_CTI**********************
        I                   O
    7
    6   1'b1
    5                       cs_fiq
    4                       md32_fiq
    3   cs_cti_event        cs_dbgrestart
    2   md32_cti_event      md32_dbgrestart
    1   sc_dbgack           cs_dbgrq
    0   md32_dbgack         md32_dbgrq
    **************************************************/
    REG_WRITE32(MD_CTI + CTIINEN3, CH_EXP);
    REG_WRITE32(MD_CTI + CTIINEN2, CH_EXP);
    REG_WRITE32(MD_CTI + CTIINEN1, CH_DBG);
    REG_WRITE32(MD_CTI + CTIINEN0, CH_DBG);
    
    REG_WRITE32(MD_CTI + CTIOUTEN5, CH_EXP);
    REG_WRITE32(MD_CTI + CTIOUTEN4, CH_EXP);
    
    if(g_ect_dsp != 0x2)
    {
        REG_WRITE32(MD_CTI + CTIOUTEN1, CH_DBG);
        REG_WRITE32(MD_CTI + CTIOUTEN0, CH_DBG);
    }
    
    /* restart */
    // mark the following statement since AP don't want us to tie it
    /*REG_WRITE32(MD_CTI + CTIINEN6, CH_RST);*/
    // Note: to resume CS, write 0xF009C0AC to 0x1
    // Note: to resume MD32, write 0xF009C0A8 to 0x1    

    /* L1 CTI part */
    /*********************L1_CTI*********************
        I                   O
    7   l1mcu_rccif_cti     DBGRESTART
    6   1'b1
    5   COMMTX
    4   COMMRX
    3                       l1mcu_ect_irq_b
    2
    1   nPMUIRQ
    0   DBGTRIGGER          EDBRGQ
    *************************************************/
    REG_WRITE32(L1_CTI + CTIINEN7, CH_EXP);
    REG_WRITE32(L1_CTI + CTIINEN0, CH_DBG);
    REG_WRITE32(L1_CTI + CTIOUTEN0, CH_DBG);
    REG_WRITE32(L1_CTI + CTIOUTEN3, CH_EXP | CH_RMPU);
    
    /* restart */
    // mark the following statement since AP don't want us to tie it
    /*REG_WRITE32(L1_CTI + CTIINEN6, CH_RST);*/
    // Note: to resume L1, write 0xF009B0BC to 0x1
    
    /* enabling CTI */
    REG_WRITE32(PS_CTI + CTICONTROL, 0x1);
    REG_WRITE32(MD_CTI + CTICONTROL, 0x1);
    REG_WRITE32(L1_CTI + CTICONTROL, 0x1);  
    
    /* turn off debug sys clock */
//    MD_TOPSM_PLL_SW_Control(PS_PLL_FORCEON_USER_CTI, PS_TOPSM_DBG_PLL, KAL_FALSE);

    /* LISR registration */
    IRQ_Register_LISR((IRQ_ECT_CODE), ECT_Hdlr, "Embedded Cross Trigger");
    IRQSensitivity(IRQ_ECT_CODE,LEVEL_SENSITIVE);
    IRQUnmask(IRQ_ECT_CODE);

    /* bbreg dump setting */
    cti_dump.regions = (kal_uint32 *)cti_dump_regions;
    cti_dump.num = sizeof(cti_dump_regions)/(sizeof(kal_uint32) * 3);
    cti_dump.bbreg_dump_callback = NULL;
    EX_REGISTER_BBREG_DUMP(&cti_dump);
#if defined(__CCCIDEV_SUPPORT__)
    ccci_register_sysmsgsvc_callback(CCMSG_ID_SYSMSGSVC_EMI_ACCESS_VIOLATION_ACK, ECT_RMPU_Resume);
#endif

#elif defined(__L1CORE__)    
    IRQ_Register_LISR(L1_L1MCU_ECT_IRQ_B, ECT_Hdlr, "Embedded Cross Trigger");
    IRQSensitivity(L1_L1MCU_ECT_IRQ_B,LEVEL_SENSITIVE);
    IRQUnmask(L1_L1MCU_ECT_IRQ_B);
#endif  /*__PCORE__*/

    ect_pcmon_bk_index.index = 0;
    ect_pcmon_bk_index.count = 0;
	ect_rmpu_timer_id =  kal_create_timer("ECT_RMPU_Timer");
}


/*************************************************************************
* FUNCTION
*  ECT_Enable_Dbgclk
*
* DESCRIPTION
*  ECT_Enable_Dbgclk
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/
void ECT_Enable_Dbgclk(void)
{
    
//Dbgsys_apb_clock will default always on, so do not have to enable!    
    return;
    
#if defined(__PCORE__) 
    MD_TOPSM_PLL_SW_Control(PS_PLL_FORCEON_USER_CTI, PS_TOPSM_DBG_PLL, KAL_TRUE);
#elif defined(__L1CORE__) 
    l1_cti_enable_dbgclk_start = ust_get_current_time();
    do
    {
       l1_cti_enable_dbgclk_end = ust_get_current_time();

       if(l1_cti_enable_dbgclk_end - l1_cti_enable_dbgclk_start > 100000)
            break;
       l1_dbgapb_pwr = MODEM_TOPSM_ForceOnDBGCK();
    }while(l1_dbgapb_pwr == KAL_FALSE);

#else
    #error "Unknown Core!!"
#endif  //if defined(__PCORE__) 



}

//For test MCU backup pcmon
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  //if 0
/*************************************************************************
* FUNCTION
*  ECT_RMPU_Check
*
* DESCRIPTION
*  ECT_RMPU_Check
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/
__intsram_rocode__ kal_bool ECT_RMPU_Check(void)
{
    ECT_Enable_Dbgclk();
    
    cti_rmpu_read_disable_start= cp15_PMU_read_cycle_counter();
    REG_READ32(PS_CTI_TriggerIn_Status, PS_CTI + CTITRIGINSTATUS);
    if(PS_CTI_TriggerIn_Status == 0x68 || PS_CTI_TriggerIn_Status == 0x48)
    {
#if defined(__PCORE__) 
        //Disable RMPU channel and ack PS trigger out
        REG_WRITE32(PS_CTI + CTIOUTEN3, CH_EXP);
        REG_WRITE32(PS_CTI + CTIINTACK, (1<<3));
#else        
        //Disable RMPU channel and ack L1 trigger out
        REG_WRITE32(L1_CTI + CTIOUTEN3, CH_EXP);
        REG_WRITE32(L1_CTI + CTIINTACK, (1<<3));
#endif  //if defined(__PCORE__)        
        
        cti_rmpu_read_disable_end= cp15_PMU_read_cycle_counter();
        return KAL_TRUE;
    }
    else if(PS_CTI_TriggerIn_Status == 0x60)
    {
        REG_READ32(L1_CTI_TriggerIn_Status, L1_CTI + CTITRIGINSTATUS);
        REG_READ32(DSP_CTI_TriggerIn_Status, MD_CTI + CTITRIGINSTATUS);
        
        if(L1_CTI_TriggerIn_Status == 0x60 && DSP_CTI_TriggerIn_Status == 0x40)
        {
            if(PCMON_OK == drv_pcm_get_stop_source(&PCmon_Stop_Src))
            {
            
                //Disable RMPU channel and ack L1 trigger out
                REG_WRITE32(L1_CTI + CTIOUTEN3, CH_EXP);
                REG_WRITE32(L1_CTI + CTIINTACK, (1<<3));
                cti_rmpu_read_disable_end= cp15_PMU_read_cycle_counter();
                return KAL_TRUE;
            }
        }
    }
    
    cti_rmpu_read_disable_end= cp15_PMU_read_cycle_counter();
    return KAL_FALSE;

    
}

/*************************************************************************
* FUNCTION
*  ECT_Hdlr
*
* DESCRIPTION
*  ECT ISRs
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/
__intsram_rocode__ void ECT_Hdlr(void)
{
    kal_uint32 rmpu_trigger;
    
    cti_rmpu_check_start= cp15_PMU_read_cycle_counter();
    rmpu_trigger = ECT_RMPU_Check();
    cti_rmpu_check_end= cp15_PMU_read_cycle_counter();
    
    if(rmpu_trigger)
    {
         cti_pcmon_backup_start= cp15_PMU_read_cycle_counter();
         ect_pcmon_bk_index.count++;
         ect_pcmon_bk_index.index++;
         if(ect_pcmon_bk_index.index >= ECT_PCMON_DATA_NUM)
             ect_pcmon_bk_index.index = 0;    
         ect_pcmon_bk_index.frc_time[ect_pcmon_bk_index.index] = ust_get_current_time();
         cti_pcmon_backup_timestamp = cp15_PMU_read_cycle_counter();
         drv_pcm_backup_and_restart(KAL_FALSE,&ect_pcmon_bk[ect_pcmon_bk_index.index],KAL_TRUE);
         cti_pcmon_backup_end= cp15_PMU_read_cycle_counter();
         
//         ECT_RMPU_Backup_PCMON();

    }
    else
    {
#ifdef __L1CORE__
	
        l1_cti_wait_topsm_start_time = ust_get_current_time();
        
        do
        {
           l1_cti_wait_topsm_current_time = ust_get_current_time();
        
           if(l1_cti_wait_topsm_current_time - l1_cti_wait_topsm_start_time > 2000) //2ms
               break;
        
        // Wait TOPSM CTI Ready 
        }while(RM_Resource_CheckReady(RM_MODEM_CTI) != KAL_TRUE);
	    
        DSP_ExcpNotify();
#endif /* __L1CORE__ */

        /* entering exception ASAP */
        CTI_Triggered_ex_handler();
    }
}


/*************************************************************************
* FUNCTION
*  ECT_TrgExcp
*
* DESCRIPTION
*  Exception propagation
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/
void ECT_TrgExcp(void)
{
#if defined(__PCORE__)

    REG_WRITE32(PS_CTI_EVENT, 1);

#elif defined(__L1CORE__)

    REG_WRITE32(L1_CTI_EVENT, 1);

    l1_cti_wait_topsm_start_time = ust_get_current_time();

    do
    {
       l1_cti_wait_topsm_current_time = ust_get_current_time();

       if(l1_cti_wait_topsm_current_time - l1_cti_wait_topsm_start_time > 2000) //2ms
           break;

    // Wait TOPSM CTI Ready 
    }while(RM_Resource_CheckReady(RM_MODEM_CTI) != KAL_TRUE);
	
    DSP_ExcpNotify();
#endif  /*__PCORE__*/
}


/*************************************************************************
* FUNCTION
*  ECT_Query
*
* DESCRIPTION
*  
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/
kal_uint32 ECT_Query(void)
{
    kal_uint32 ect_st = ECT_SRC_NONE;
    kal_uint32 l1_cti;
    kal_uint32 md_cti;
    kal_uint32 ps_cti;    
#ifdef __L1CORE__
    kal_uint32 start_time;
    kal_uint32 current_time;
#endif /* __L1CORE__ */

    /* remove the following option once L1 core api is ready */
#if defined(__PCORE__)        
    /* enable DBG APB clock */
    /* do not disable it, since we have to dump it ... */
    
    cti_dbgclock_start_exp = cp15_PMU_read_cycle_counter();
    MD_TOPSM_PLL_SW_Control(PS_PLL_FORCEON_USER_CTI, PS_TOPSM_DBG_PLL, KAL_TRUE);
    cti_dbgclock_end_exp = cp15_PMU_read_cycle_counter();
#elif defined(__L1CORE__)

    /* try to power up the dbg apb from L1 */
    /* timeout is 100ms */
    start_time = ust_get_current_time();

    cti_dbgclock_start_exp = cp15_PMU_read_cycle_counter();
    do
    {
       current_time = ust_get_current_time();

       if(current_time - start_time > 100000)
       {
           cti_dbgclock_end_exp = cp15_PMU_read_cycle_counter(); 
           return 0;
       }

       l1_dbgapb_pwr = MODEM_TOPSM_ForceOnDBGCK();
    }while(l1_dbgapb_pwr == KAL_FALSE);
    cti_dbgclock_end_exp = cp15_PMU_read_cycle_counter();

#else
    #error "Unknown Core!!"
#endif  /*__PCORE__*/



    REG_READ32(l1_cti, L1_CTI + CTITRIGINSTATUS);
    REG_READ32(md_cti, MD_CTI + CTITRIGINSTATUS);
    REG_READ32(ps_cti, PS_CTI + CTITRIGINSTATUS);
    
    if(ps_cti & (0x1 << 7))
        ect_st |= ECT_SRC_PS;
        
    if(ps_cti & (0x1 << 2))
        ect_st |= ECT_SRC_ARM7;
        
    if(ps_cti & (0x1 << 3))
        ect_st |= ECT_SRC_RMPU;

#ifndef TK6291
    if(ps_cti & (0x1 << 1))
        ect_st |= ECT_SRC_C2K;
#endif /*TK6291*/
        
    if(l1_cti & (0x1 << 7))
        ect_st |= ECT_SRC_L1;
        
    if(md_cti & (0x1 << 3))
			ect_st |= ECT_SRC_CS;
        
    if(md_cti & (0x1 << 2))
			ect_st |= ECT_SRC_MD32;

    return ect_st;
}


/*************************************************************************
* FUNCTION
*  ECT_IsEnabled
*
* DESCRIPTION
*  
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/
kal_uint32 ECT_IsEnabled(void)
{
	kal_uint32 ps_cti_sta, l1_cti_sta, md_cti_sta; 
	
	REG_READ32(ps_cti_sta, PS_CTI + CTICONTROL);
	REG_READ32(l1_cti_sta, L1_CTI + CTICONTROL);
	REG_READ32(md_cti_sta, MD_CTI + CTICONTROL);
	
	return ps_cti_sta && l1_cti_sta && md_cti_sta;
}


/*************************************************************************
* FUNCTION
*  ECT_DumpCallback 
*
* DESCRIPTION
*  ECT callback for register dump, it turns on the dbg apb clock 
*
* PARAMETERS
*  
*
* RETURNS
*
*
*************************************************************************/
kal_bool ECT_DumpCallback(void)
{
    /* remove the following option once L1 core api is ready */
#if defined(__PCORE__)        
    /* enable DBG APB clock */
    MD_TOPSM_PLL_SW_Control(PS_PLL_FORCEON_USER_CTI, PS_TOPSM_DBG_PLL, KAL_TRUE);
#endif /* __PCORE__ */

    return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*  ECT_GetPCMON_BK_Buf_Ptr
*
* DESCRIPTION
*  Get Ect PCmon backup beffer pointer
*
* PARAMETERS
*  
*
* RETURNS
*
* PCM_RECORD* pcmon backup structure
*
*************************************************************************/
PCM_RECORD* ECT_GetPCMON_BK_Buf_Ptr(void)
{

    return &ect_pcmon_bk[ect_pcmon_bk_index.index];
}