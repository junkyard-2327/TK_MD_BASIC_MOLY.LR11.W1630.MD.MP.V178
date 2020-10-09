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
 *   l1core_hisr_config_internal.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file provides the hisr configuration.
 *
 * Author:
 * -------
 *   
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 

          /*NO. Enum_Name  Name       priority     stack_size       callback_function     INT/EXT RAM*/
 /* service*/

#if defined(__MTK_TARGET__) && !defined(__TIMER_HISR_DISABLE__)
    X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 1),	 TIMER_HISR,   "TIMER_HISR", 2, 768, TMC_Timer_HISR, KAL_FALSE)
#else
    X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 1),	 TIMER_HISR,   "TIMER_HISR", 2, 1024, OSC_Timer_HISR, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 1), MOD_TIMER_HISR)

#if !defined(__MAUI_BASIC__) && !defined(__MEUT__) && !defined(ATEST_DRV_ENVIRON) && !defined(L1_SIM) && ((defined(__MTK_TARGET__)&&defined(L1_CATCHER))||(defined(__DHL_MODULE__)&&defined(L1_CATCHER))) && !defined(__TRC_PRC_HISR_DISABLE__)
    X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 2),   TRCPRCHISR,   "TRC_PRC_HISR",2,584,trc_process_HisrEntry,KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 2), MOD_TRCPRCHISR)
    
#if !defined(__MTK_SECURE_PLATFORM__) && !defined(__PRODUCTION_RELEASE__) && defined(__MTK_TARGET__) && !defined(__MDDBG_HISR_DISABLE__)
/* under construction !*/
#endif
	X_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 3), MOD_MDDBG_L1_HISR)

 /* service end */
 
 /* modem start */

#if ((defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)) || defined (__UE_SIMULATOR__) || defined(L1_SIM)) && !defined(__LTE_L1SIM_SM__) && !defined(__L1I_HISR_DISABLE__) || (defined(ESIM_BUILD_CONFIG)&&(ESIM_BUILD_CONFIG == ESIM_MULTI_MODE_ON_FIBERS))
    X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 1),   L1_HISR,   "L1_HISR", 0, 2248, L1I_HISR, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 1), MOD_L1HISR)

#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__) && (defined(__MTK_TARGET__) || defined (__UE_SIMULATOR__) || defined(L1_SIM)) && !defined(__UL1C_HISR_DISABLE__) || (defined(ESIM_BUILD_CONFIG)&&(ESIM_BUILD_CONFIG == ESIM_MULTI_MODE_ON_FIBERS))
     X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 2),   UMTS_HISR,   "UMTS_HISR", 0, 2048, UL1C_HISR, KAL_FALSE)
#endif
     X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 2), MOD_UMTS_HISR)

#if (defined(__UL1_HS_PLATFORM__) || defined(__UL1_HS_PLUS_PLATFORM__))  && defined(__UMTS_FDD_MODE__) && (defined(__MTK_TARGET__) || defined (__UE_SIMULATOR__) ) && !defined(__UL1D_REAL_HISR_DISABLE__)  || (defined(ESIM_BUILD_CONFIG)&&(ESIM_BUILD_CONFIG == ESIM_MULTI_MODE_ON_FIBERS))|| (defined(L1_SIM) && !defined(__LTE_L1SIM_SM__))
    X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 3),   UL1D_REAL_HISR,   "UL1D_REAL_HISR", 0, 1024, UL1D_RealHISR, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 3), MOD_UL1_LOW_HISR)

#if defined(__LTE_RAT__) && defined(__EL1D_ENABLE__) && (defined(__MTK_TARGET__) || defined(__UE_SIMULATOR__) || defined(__LTE_L1SIM__)) && !defined(__EL1D_HISR_DISABLE__)
     X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 4),   EL1D_HISR,   "EL1D_HISR", 0, 2048, EL1D_RealHISR, KAL_FALSE)
#endif
     X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 4), MOD_EL1D_HISR)
 
#if defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__) && !defined(__AST_TL1_TDD_HISR_DISABLE__)
     X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 5), TL1_HISR, "TL1_HISR", 0, 760, tl1_m_h_entry, KAL_FALSE)
#endif
     X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 5), MOD_TL1HISR)

 /* modem end */
 
#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 2),   CC_SYS_HISR,   "CCHISR", 1,           2560,            cc_sys_comm_hisr,             KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 2), MOD_L1_CC_SYS_HISR)


#if defined (__MTK_TARGET__) && !defined(__GPTDEBUG_HISR_DISABLE__)
 X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 3), GPT_DEBUG_HISR, "GPTD", 0, 1024, GPTCB_DEBUG_HISR, KAL_FALSE)
#endif
 X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 3), MOD_GPT_DEBUG_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 4), GPT1_HISR, "GPT1_HISR", 1, 1280, GPTCB_10MS_HISR, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 4), MOD_GPT1_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 5), GPT2_HISR, "GPT2_HISR", 1, 1280, GPTCB_US_HISR, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 5), MOD_GPT2_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 6), BUSMON_HISR, "BUSMON_HISR", 1, 1280, drv_busmon_hisr, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 6), MOD_BUSMON_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 7), IDC_PM_HISR, "IDCPM_HISR", 1, 1280, idc_pm_hisr, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 7), MOD_IDC_PM_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 8), IDC_UART_HISR, "IDCUART_HISR", 1, 1280, idc_uart_hisr, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 8), MOD_IDC_UART_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 9), DEM_HISR, "DEM_HISR", 1, 1280, drv_dem_hisr, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 9), MOD_DEM_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 10), PCC_HISR, "PCC_HISR", 1, 1280, DRV_PCC_HISR, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 10), MOD_PCC_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 11), GDMA_HISR, "GDMA_HISR", 1, 1280, drv_gdma_hisr, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 11), MOD_GDMA_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 12), PPC_HISR, "PPC_HISR", 1, 1280, DRV_PPC_HISR, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 12), MOD_PPC_HISR)

#if defined(__MTK_TARGET__)
	 X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 13), MDAP_L1_HISR, "MA_L1_HISR", 1, 1280, Drv_MDAPInterface_L1_HISR, KAL_FALSE)
#endif
	 X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 13), MOD_MDAP_L1_HISR)

#if defined(__MTK_TARGET__)
     X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 14), PCM_HISR, "PCM_HISR", 1, 512, drv_pcm_hisr, KAL_FALSE)
#endif
     X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 14), MOD_PCM_HISR)
 
 /* drv end */
 




