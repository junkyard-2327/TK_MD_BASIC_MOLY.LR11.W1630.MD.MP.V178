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
 *   dcm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides APIs to get device information 
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __MTK_TARGET__

#include "dormant_mode.h" //for dormant options
#include "us_timer.h"     //for FMA, us counter
#include "init.h"         //for bootslave ctrl
#include "swla_public.h"  //for SWLA API, labels
#include "bus_drv.h"      //for SMI restore
#include "ex_mem_manager_public.h"
//#include "drv_asm.h"      //for ASM backup/restore, TBC

#define DORMANT_TOP_HEAD         (0xDADA0000UL)
#define DORMANT_ACT_ENTER        (DORMANT_TOP_HEAD|0x00001001)
#define DORMANT_SETBS_OUT        (DORMANT_TOP_HEAD|0x00001002)
#define DORMANT_SAVE_ASM_IN      (DORMANT_TOP_HEAD|0x00001003)
#define DORMANT_SAVE_ASM_OUT     (DORMANT_TOP_HEAD|0x00001004)
#define DORMANT_2ND_WFI_IN       (DORMANT_TOP_HEAD|0x00002001)
#define DORMANT_2ND_WFI_OUT      (DORMANT_TOP_HEAD|0x00002002)
#define DORMANT_RSTBS_IN         (DORMANT_TOP_HEAD|0x00002003)
#define DORMANT_RSTBS_OUT        (DORMANT_TOP_HEAD|0x00002004)
#define DORMANT_BUS_SMI_IN       (DORMANT_TOP_HEAD|0x00002005)
#define DORMANT_BUS_SMI_OUT      (DORMANT_TOP_HEAD|0x00002006)
#define DORMANT_PFB_ENABLE_IN    (DORMANT_TOP_HEAD|0x00002007)
#define DORMANT_PFB_ENABLE_OUT   (DORMANT_TOP_HEAD|0x00002008)
#define DORMANT_RESTORE_ASM_IN   (DORMANT_TOP_HEAD|0x00002009)
#define DORMANT_RESTORE_ASM_OUT  (DORMANT_TOP_HEAD|0x0000200A)
#define DORMANT_ACT_EXIT         (DORMANT_TOP_HEAD|0x00003000)

#if defined(__MCU_DORMANT_MODE__)

#define DORMANT_FRC_VAL_R                   (USCNTI_VAL)

#if defined(__L1CORE__)
    /* Boot Rom Control */
    #define DORMANT_BOOT_JUMP_ADDR           MCU_BOOTSLV_JUMP_ADDR
    #define BOOT_VECTOR_KEY                  MCU_BOOTSLV_JUMP_KEY_ADDR
    #define BOOT_VECTOR_KEY_UNLOCK           (0x6291F8EE)
    #define BOOT_VECTOR_KEY_LOCK             (0x629110C4)
    #define BOOT_VECTOR_ENABLE               MCU_BOOTSLV_JUMP_ADDR_UPDATE
    #define BOOT_VECTOR_ENABLE_VAL           (0x1)
#else  /* __L1CORE__ */
    /* Boot Rom Control */
    #define DORMANT_BOOT_JUMP_ADDR           ((volatile kal_uint32 *)(BASE_MADDR_MDPERIMISC+0x4))
    #define BOOT_VECTOR_KEY                  ((volatile kal_uint32 *)(BASE_MADDR_MDPERIMISC+0xc))
    #define BOOT_VECTOR_KEY_UNLOCK           (0x00005500)
    #define BOOT_VECTOR_KEY_LOCK             (0x00000000)
    #define BOOT_VECTOR_ENABLE               ((volatile kal_uint32 *)(BASE_MADDR_MDPERIMISC+0x8))
    #define BOOT_VECTOR_ENABLE_VAL           (0x1)
#endif /* __L1CORE__ */

/* TOPSM related regiaters/fields, strongly order to avoid early response */
//#define DORMANT_RM_PWR_STA                  (BASE_MADDR_MDTOPSM+0x0820UL)
//#define DORMANT_RM_PWR_STA_ARM_PWR_ACK      (0x100000)

/* MD_Config related regiaters/fields, strongly order to avoid early response */
#define DORMANT_MD_REMAPPING_CON            (CONFIG_base+0x0100)

/* To get 3G RTR time, turn-on this option definition in dormant_service.c and cortexr4-dormantMode_gcc.S */
//#define MODEM_3G_RTR_TIME_CHECK 1


/*
 * Following variables are expected to locate on EMI space.
 */
/* variable to keep information of dormant mode entry and exit procedure */
__DOR_TCM_BSS__       __attribute__((aligned(8))) volatile kal_uint32 dorm_tcm_backup_buf[DORMANT_TCM_STORAGE_SIZE>>2];
__DOR_NONCACHED_BSS__ __attribute__((aligned(8))) volatile kal_uint32 dorm_emi_backup_buf[DORMANT_EMI_STORAGE_SIZE>>2];
__DOR_NONCACHED_BSS__ __attribute__((aligned(8))) volatile kal_uint32 dorm_stack_buf[DORMANT_STACK_SIZE>>2];
__DOR_NONCACHED_DATA__ volatile kal_uint32 dorm_stack;

/* For Debug Purpose */
//Time Information: FRC
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_standby_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_abort_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_leave_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_enter_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_end_frc;
__DOR_TCM_BSS__ volatile kal_uint32 dormant_smi_start_frc;
__DOR_TCM_BSS__ volatile kal_uint32 dormant_smi_end_frc;
__DOR_TCM_BSS__ volatile kal_uint32 dormant_asm_save_start_frc;
__DOR_TCM_BSS__ volatile kal_uint32 dormant_pfb_enable_end_frc;
//#if defined(MT6755)&&defined(__PCORE__)
//__DOR_TCM_BSS__ volatile kal_uint32 dormant_swEnableDDRenOn_start_frc;
//__DOR_TCM_BSS__ volatile kal_uint32 dormant_swEnableDDRenOff_start_frc;
//#endif /* MT6755 && __PCORE__ */
__DOR_TCM_BSS__ volatile kal_uint32 dormant_asm_restore_end_frc;
#if defined(CACHE_FLUSH_IN_DORMANT)
    __DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_cache_flush_start_frc;
#endif /* CACHE_FLUSH_IN_DORMANT */
#if defined(CACHE_FLUSH_IN_DORMANT) || defined(ATEST_DRV_ENABLE)
    __DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_cache_flush_end_frc;
#endif /* CACHE_FLUSH_IN_DORMANT || ATEST_DRV_ENABLE */


//Counter Information:
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_count;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_abort_count;
#if defined(MODEM_3G_RTR_TIME_CHECK)
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_rtr;
#endif /* MODEM_3G_RTR_TIME_CHECK */



/* variable to keep chip dependent register definition. */
//const kal_uint32 dormant_status_reg = (kal_uint32)DORMANT_RM_PWR_STA;
//const kal_uint32 dormant_power_ack_mask = (kal_uint32)DORMANT_RM_PWR_STA_ARM_PWR_ACK;
const kal_uint32 dormant_frc_val = (kal_uint32)DORMANT_FRC_VAL_R;

#if defined(MODEM_3G_RTR_TIME_CHECK)
const kal_uint32 dormant_rtr_val = (kal_uint32)WCDMA_TIMER_BASE;
#endif /* MODEM_3G_RTR_TIME_CHECK */

//const kal_uint32 dormant_remapping_val = (kal_uint32)DORMANT_MD_REMAPPING_CON;

//#if defined(MT6290) && !(defined(_SMART_PHONE_MODEM__)&&defined(__CCCIFS_SUPPORT__)&&defined(__X_BOOTING__)) /* 90 !SP */
//extern void dormant_tcm_reset_entry(void);
//#endif /* MT6290 && !SmartPhone */

extern void enablePrefetchBuffer(void);

#if (defined(__HIF_CLDMA_SUPPORT__) && defined(__PCORE__)) || (defined(__CCCIDEV_SUPPORT__) && defined(__L1CORE__))
    #define IFDEF_HIFCLDMA(x) x
#else /* __HIF_CLDMA_SUPPORT__ */
    #define IFDEF_HIFCLDMA(x)
#endif /* __HIF_CLDMA_SUPPORT__ */

IFDEF_HIFCLDMA(__DOR_NONCACHED_DATA__ kal_uint32 dormant_dbg_ptr);
IFDEF_HIFCLDMA(__DOR_NONCACHED_DATA__ kal_uint32 dormant_dbg_ptr_size;);

/**********************************************************
Description : dormant mode init
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_init(void)
{
    /* init dormant mode stack */
    dorm_stack_buf[0] = 0x43415453;
    dorm_stack_buf[1] = 0x444E454B;

    /* set stack start address - 8 byte aligned address */
    dorm_stack = (kal_uint32)&dorm_stack_buf[(DORMANT_STACK_SIZE>>2)-2];
    DRV_WriteReg32( 0xF0000024,0x00000001 );          //boot from dormant
    IFDEF_HIFCLDMA(EMM_DirInfo_Query(EMM_DIRECT_WRITE_DORMANT, &dormant_dbg_ptr, &dormant_dbg_ptr_size));
}

/**********************************************************
Description : trigger dormant mode procedure
Input       : Non
Output      : Non
***********************************************************/
__DOR_TCM_LOCAL_FUNC__ void dormant_mode_activate(void)
{
    kal_uint32 orig_reset = 0;
//    volatile kal_uint32 pre_reset_cnt;

//    pre_reset_cnt = dormant_reset_count;

    SLA_CustomLogging("DOR", SA_start);

    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_ACT_ENTER));
    DRV_WriteReg32(BOOT_VECTOR_KEY, BOOT_VECTOR_KEY_UNLOCK);
    DRV_WriteReg32(DORMANT_BOOT_JUMP_ADDR, ((kal_uint32)dormant_mode_reset_interwork) | 0x01);
    DRV_WriteReg32(BOOT_VECTOR_ENABLE, BOOT_VECTOR_ENABLE_VAL);
    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_SETBS_OUT));

    dormant_asm_save_start_frc = ust_get_current_time();
    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_SAVE_ASM_IN));
    MALMO_ASM_SleepSave(ASM_SLEEP_MODE_SPM);
    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_SAVE_ASM_OUT));
//#if defined(MT6755)&&defined(__PCORE__)
//    dormant_swEnableDDRenOn_start_frc = ust_get_current_time();
//    DRV_ClrReg32(0xF0060404, 1UL<<17); //ToBeRemoved, for debugging
//#endif /* MT6755 && __PCORE__ */

    dormant_enter_frc = ust_get_current_time();

    enter_dormant_mode();

    /* Use TOPSM timer directly */
    dormant_leave_frc = DRV_Reg32(dormant_frc_val);

    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_2ND_WFI_IN));
    cp15_enter_low_pwr_state();
    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_2ND_WFI_OUT));

#if defined(TK6291)||defined(MT6755)||defined(MT6797)||defined(MT6757)||defined(MT6750)||defined(MT6750S)
    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_RSTBS_IN));
    DRV_WriteReg32(DORMANT_BOOT_JUMP_ADDR, orig_reset);
    DRV_WriteReg32(BOOT_VECTOR_ENABLE, BOOT_VECTOR_ENABLE_VAL);
    DRV_WriteReg32(BOOT_VECTOR_KEY, BOOT_VECTOR_KEY_LOCK);
    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_RSTBS_OUT));
#else
    #error "Dormant: unsupported Chip"
#endif /* Chips */
//#if defined(MT6755)&&defined(__PCORE__)
//    dormant_swEnableDDRenOff_start_frc = ust_get_current_time();
//    DRV_SetReg32(0xF0060404, 1UL<<17); //ToBeRemoved, for debugging
//#endif /* MT6755 && __PCORE__ */
//    if( (pre_reset_cnt+1) == dormant_reset_count)
//    {
        dormant_smi_start_frc = ust_get_current_time();

        IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_BUS_SMI_IN));
        BusDrv_SetSMI();
        IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_BUS_SMI_OUT));

        dormant_smi_end_frc = ust_get_current_time();

        IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_SAVE_ASM_IN));
        MALMO_ASM_SleepRestore();
        IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_SAVE_ASM_OUT));

        dormant_asm_restore_end_frc = ust_get_current_time();

        IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_PFB_ENABLE_IN));
        enablePrefetchBuffer();
        IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_PFB_ENABLE_OUT));

        dormant_pfb_enable_end_frc = ust_get_current_time();

//    }

    SLA_CustomLogging("DOR", SA_stop);
    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_ACT_EXIT));

    return ;
}

/**********************************************************
Description : mark a flag to indicate that entry to dormant mode is abort
Input       : Non
Output      : Non
***********************************************************/
__DOR_TCM_LOCAL_FUNC__ void dormant_mode_abort_entry(void)
{
    SLA_CustomLogging("dab", SA_label);
}

/**********************************************************
Description : mark a flag to indicate that dormant mode reset is abort
Input       : Non
Output      : Non
***********************************************************/
__DOR_TCM_LOCAL_FUNC__ void dormant_mode_abort_reset(void)
{
#ifndef ATEST_DRV_ENABLE
    SLA_CustomLogging("dra", SA_label);
#endif
}

#else /* !__MCU_DORMANT_MODE__ */

/**********************************************************
Description : dormant mode init
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_init(void)
{
    /* do nothing */
}

/**********************************************************
Description : trigger dormant mode procedure
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_activate(void)
{
    /* do nothing */
}

#endif /* __MCU_DORMANT_MODE__ */

#endif /* __MTK_TARGET__ */
