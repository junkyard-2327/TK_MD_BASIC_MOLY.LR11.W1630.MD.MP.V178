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
 *   pcore_hisr_config_internal.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file provides the HISR config parameter
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
#include "module_hisrid_range.h"


          /*NO. Enum_Name  Name       priority     stack_size       callback_function     INT/EXT RAM*/

/*service  start */
#if !defined(__MAUI_BASIC__) && !defined(__MEUT__) && !defined(ATEST_DRV_ENVIRON) && !defined(L1_SIM) && (defined(__MTK_TARGET__)||(defined(__DHL_MODULE__)&&defined(L1_CATCHER))) && !defined(__TRC_PRC_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 1),   TRCPRCHISR,   "TRC_PRC_HISR",2,584,trc_process_HisrEntry,KAL_FALSE)
#endif
X_MULTI_CORE_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 1), MOD_TRCPRCHISR)

#if defined(__MTK_TARGET__) && !defined(__TIMER_HISR_DISABLE__)
#if defined(__NUCLEUS_VERSION_2__)
#if defined(__KTEST__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 3),   TIMER_HISR,   "TIMER_HISR", 2, 2304, TMC_Timer_HISR, KAL_FALSE)
#else /* else of __KTEST__ */
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 3),   TIMER_HISR,   "TIMER_HISR", 2, 768, TMC_Timer_HISR, KAL_FALSE)
#endif /* end of "else of __KTEST__ " */
#else
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 3),   TIMER_HISR,   "TIMER_HISR", 2, 512, TMC_Timer_HISR, KAL_FALSE)
#endif /* __NUCLEUS_VERSION_2__ */
#else
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 3),   TIMER_HISR,   "TIMER_HISR", 2, 1024, OSC_Timer_HISR, KAL_FALSE)
#endif
X_MULTI_CORE_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 3), MOD_TIMER_HISR)

#if defined(__IS_BYTECOPY_SUPPORT__) && defined(__MTK_TARGET__) && !defined(__BC_ISR_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 4), BC_HISR, "BC_HISR", 1, 2048, bc_isr_hisr, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 4), MOD_BCHISR)

#if defined(__DHL_MODULE__) && defined(__MTK_TARGET__)  && !defined(__L1DMA_HISR_DISABLE__) && !defined(__FPGA__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 5), L1DMA_HISR, "L1DMA_HISR", 2, 2048, l1dma_hisr, KAL_FALSE)
#endif
X_MULTI_CORE_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 5), MOD_L1DMA_HISR)

#if defined(__DHL_MODULE__) && defined(__MTK_TARGET__) && !defined(__MALMO_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 6), MALMO_HISR, "MALMO_HISR", 2, 2048, MALMO_ASM_PS_Hisr, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 6), MOD_MALMO_HISR)

#if defined(__DHL_MODULE__) && defined(__MTK_TARGET__) && !defined(__MALMO_HISR_DISABLE__) && !defined(__PCORE_ONLY__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 7), ASM_L1_HISR, "ASM_L1_HISR", 2, 2048, MALMO_ASM_L1_Hisr, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 7), MOD_ASM_L1_HISR)

#if defined(__DSPIRDBG__) && defined(__MTK_TARGET__) && !defined(__IRDEBUG_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_SS_CODE_BEGIN + 8), IRDEBUG_HISR, "IRDEBUG_HISR", 1, 2048, irdebug_hisr, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 8), MOD_IRDEBUG_HISR)

#if !defined(__MTK_SECURE_PLATFORM__) && !defined(__PRODUCTION_RELEASE__) && defined(__MTK_TARGET__) && !defined(__MDDBG_HISR_DISABLE__)
/* under construction !*/
#endif
X_HISR_MOD((HISR_ID_SS_CODE_BEGIN + 9), MOD_MDDBG_HISR)


//srv max : 9 

 /* service end */


    
 /* modem start */

    
//TDD UMAC on PCore
#if defined(__MTK_TARGET__) && defined(__UMTS_TDD128_MODE__)&& !defined(__TDD_UMAC_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 1), TDD_UMAC_DSCH_HISR, "MAC0_DSCH_HISR", 0, 1024, umac_dsch_hisr_entry, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 1), MOD_TDD_UMAC_DSCH_HISR)


    /* added for 3G L1 on Pcore */
#if (defined(__UL1_HS_PLATFORM__) || defined(__UL1_HS_PLUS_PLATFORM__))  && defined(__UMTS_FDD_MODE__) && (defined(__MTK_TARGET__) || defined (__UE_SIMULATOR__) || defined (L1_SIM)) && !defined(__UL1D_PCORE_REAL_HISR_DISABLE__) || (defined(ESIM_BUILD_CONFIG)&&(ESIM_BUILD_CONFIG == ESIM_MULTI_MODE_ON_FIBERS))
    X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 2),   UL1D_PCORE_REAL_HISR,   "PU1D_REAL_HISR", 0, 1024, UL1D_RealHISR_Pcore, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 2), MOD_UL1_PCORE_LOW_HISR)

    /* added for 3G L1 on Pcore */
#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__) && (defined(__MTK_TARGET__) || defined (__UE_SIMULATOR__) || defined (L1_SIM)) && !defined(__UL1C_PCORE_HISR_DISABLE__) || (defined(ESIM_BUILD_CONFIG)&&(ESIM_BUILD_CONFIG == ESIM_MULTI_MODE_ON_FIBERS))
    X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 3),   UL1C_PCORE_HISR,   "PU1C_HISR ", 1, 2048, UL1C_Pcore_HISR, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 3), MOD_UL1C_PCORE_HISR)

#if (defined(__UL1_HS_PLATFORM__) || defined(__UL1_HS_PLUS_PLATFORM__))  && defined(__UMTS_FDD_MODE__) && (defined(__MTK_TARGET__) || defined (__UE_SIMULATOR__) || defined (L1_SIM)) || (defined(ESIM_BUILD_CONFIG)&&(ESIM_BUILD_CONFIG == ESIM_MULTI_MODE_ON_FIBERS))
#if !defined(__UL1D_UL2_HISR_DISABLE__)
    X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 4),   UL2HISR,   "UL2HISR", 0, 2048, UL1D_UL2HISR, KAL_FALSE)
#endif /* __UL1D_UL2_HISR_DISABLE__ */
#endif
    X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 4), MOD_UUL2HISR)



#if defined(__RLC_HSDPA_COPRO__) && defined(__MTK_TARGET__)
#if !defined(__SEQ_ISR_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 5),   UL2SEQ_HISR, "UL2SEQ_HISR", 1, 1024, FDD_seq_isr_hisr, KAL_FALSE)
#endif /* __SEQ_ISR_HISR_DISABLE__ */
#endif
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 5), MOD_UL2ACCRXHISR)


#if ( defined(__LTE_RAT__)||defined(ATEST_ENABLE)) && defined(__MTK_TARGET__) && !defined(__L2COPRO_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 9), L2_LTE_COPRO_HISR, "L2CO_HISR", 0, 2048,l2_lte_copro_hisr , KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 9), MOD_L2_LTE_COPRO_HISR)

#if (defined(__LTE_RAT__)||defined(ATEST_ENABLE)) && defined(__MTK_TARGET__) && !defined(__LMAC_RAR_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 10), L2_LMAC_RAR_HISR, "L2RA_HISR", 0, 2048, l2lmac_dl_rar_hisr, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 10), MOD_L2_LMAC_RAR_HISR)

#if (defined(__LTE_RAT__)||defined(ATEST_ENABLE)) && defined(__MTK_TARGET__) && !defined(__LMAC_EAR_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 11), L2_LMAC_EAR_HISR, "L2EA_HISR", 0, 2048, l2lmac_dl_ear_hisr, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 11), MOD_L2_LMAC_EAR_HISR)

#if defined(__LTE_RAT__) && defined(__EDYN_ENABLE__) && !defined(__ERT_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 13), ERT_HISR, "ERT_HISR", 0, 4096, ert_hisr, KAL_TRUE)
#endif/*__LTE_RAT__, __EDYN_ENABLE__, (!ATEST_ENABLE, ATEST_SYS_ENABLE)*/
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 13), MOD_ERT_HISR)

#if defined(__RLC_HSDPA_COPRO__) && defined(__UL2_ACC_TEST_FPGA__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 14), UL2ACCFINT_HISR, "UL2ACCFINT_HISR", 2, 512, UL2_ACC_FINT_HISR, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 14), MOD_UL2ACCFINT_HISR)

#if defined(ESIM_BUILD_CONFIG) || defined(__LTE_L1SIM__)
// We should see if we can remove this definition as this is only used for simulation.
#if (ESIM_BUILD_CONFIG == ESIM_SINGLE_MODE_ON_FIBERS) || (ESIM_BUILD_CONFIG == ESIM_MULTI_MODE_ON_FIBERS) || defined(__LTE_L1SIM__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 15),   LMAC_HISR,   "LMAC_HISR", 2, 2048, _lmac_hisr, KAL_FALSE)
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 15), MOD_LMAC_HISR)
#endif 
#endif
 
#if defined (__U4G_ADAPTOR__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 16),   U4G_HL_EVENT_TIMER_HISR,   "U4G_HL_EVENT_TIMER_HISR", 2, 2048, u4g_hl_event_timer_hisr, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 16), MOD_U4G_HL_EVENT_TIMER_HISR)

//TDD UMAC on PCore
#if defined(__MTK_TARGET__) && defined(__UMTS_TDD128_MODE__)&& !defined(__TDD_UMAC_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 17), TDD_UMAC_DCH_CSR_EDCH_HISR, "MAC1_DCH_CSR_EDCH_HISR_0", 1, 1024, umac_dch_csr_edch_hisr_entry, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 17), MOD_TDD_UMAC_DCH_CSR_EDCH_HISR)  

#if ((defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__))) && !defined(__LTE_SM__) && !defined(__L1I_HISR_DISABLE__) && !defined(__L1_PCORE_TASK_DISABLE__) || (defined(ESIM_BUILD_CONFIG)&&(ESIM_BUILD_CONFIG == ESIM_MULTI_MODE_ON_FIBERS))
    X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 18), L1_PCORE_HISR, "L1_PCORE_HISR", 0, 2248, gl1_pcore_hisr, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 18), MOD_L1_PCORE_HISR)

#if defined(__LTE_RAT__) && defined(__EDYN_ENABLE__) && defined(__EL1_IT__)
X_HISR_CONST((HISR_ID_MODEM_CODE_BEGIN + 19), EL1C_IT_HISR, "EL1C_IT_HISR", 0, 4096, lte_el1c_it_hisr, KAL_TRUE)
#endif/*__LTE_RAT__, __EDYN_ENABLE__, __EL1_IT__*/
X_HISR_MOD((HISR_ID_MODEM_CODE_BEGIN + 19), MOD_EL1C_IT_HISR)
//modem max : 19 

 /* modem end */
 
 /* drv start */
#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__) && !defined(__MEUT__) && !defined(__LTE_SM__)
#if !defined(__L1AUDIO_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 2),   L1AUDIO_HISR,   "L1Audio_HISR", 1, 2048, L1Audio_HISR, KAL_FALSE)
#endif /* __L1AUDIO_HISR_DISABLE__ */
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 2), MOD_L1SPHISR)

#if !defined(__MTK_TARGET__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 3),   UARTHISR,   "UAR0_HISR", 2, 512,UART_HISR,KAL_FALSE)
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 3), MOD_UARTHISR)
#endif

#if defined(__CREATE_USB_HISR__) && defined(__MTK_TARGET__)  && !defined(__USB_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 4), HIF_USB_HISR, "USB_HISR", 0, 2048,hifusb_hisr_handler , KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 4), MOD_HIF_USB_HISR)

#if defined(__CREATE_SDIO_HISR__) && defined(__MTK_TARGET__) && !defined(__SDIO_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 5), HIF_SDIO_HISR, "sdio_HISR", 0, 1024, hifsdio_hisr_handler , KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 5), MOD_HIF_SDIO_HISR)

#if defined (__MTK_TARGET__) && defined(__HIF_CLDMA_SUPPORT__) && !defined(__CLDMA_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 6), HIF_CLDMA_HISR, "CLDMA_HISR", 0, 1024, hifcldma_hisr_handler , KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 6), MOD_HIF_CLDMA_HISR)

/* middleware hisr is included in driver category now, TBC... */
#if !defined(__MTK_TARGET__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 7), UHS_ISR,   "UHS_ISR", 2, 512, uhs_hisr, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 7), MOD_UHS_HISR)

#if !defined(__MTK_TARGET__) && defined(__LTM_SIMULATION_SUPPORT__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 8), LMS_ISR,   "LMS_ISR", 2, 512, lms_hisr, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 8), MOD_LMS_HISR)

#if defined (__MTK_TARGET__) && defined(__HIF_CCIF_SUPPORT__) && !defined(__CCIFRX_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 9), HIF_CCIFRX_HISR, "RXCCIF_H", 0, 1024, hifccifrx_hisr_handler , KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 9), MOD_HIF_CCIFRX_HISR)

#if defined (__MTK_TARGET__) && defined(__HIF_CCIF_SUPPORT__) && !defined(__CCIFTX_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 10), HIF_CCIFTX_HISR, "TXCCIF_H", 0, 1024, hifcciftx_hisr_handler , KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 10), MOD_HIF_CCIFTX_HISR)
	

#if defined(__MTK_TARGET__) && defined(__KTEST__)
	X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 11), KTESTHISR0_1, "0_1KETST", 0, 2048, KTEST_HISR_PRIORITY0_1,KAL_FALSE)
	X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 11), MOD_KTEST_HISR01)

	X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 12), KTESTHISR0_2, "0_2KETST", 0, 2048, KTEST_HISR_PRIORITY0_2,KAL_FALSE)
	X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 12), MOD_KTEST_HISR02)

	X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 13), KTESTHISR0_3, "0_3KETST", 0, 2048, KTEST_HISR_PRIORITY0_3,KAL_FALSE)
	X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 13), MOD_KTEST_HISR03)

	X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 14), KTESTHISR1_1, "1_1KETST", 1, 2048, KTEST_HISR_PRIORITY1_1,KAL_FALSE)
	X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 14), MOD_KTEST_HISR11)

	X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 15), KTESTHISR1_2, "1_2KETST", 1, 2048, KTEST_HISR_PRIORITY1_2,KAL_FALSE)
	X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 15), MOD_KTEST_HISR12)

	X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 16), KTESTHISR1_3, "1_3KETST", 1, 2048, KTEST_HISR_PRIORITY1_3,KAL_FALSE)
	X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 16), MOD_KTEST_HISR13)

	X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 17), KTESTHISR2_1, "2_1KETST", 2, 2048, KTEST_HISR_PRIORITY2_1,KAL_FALSE)
	X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 17), MOD_KTEST_HISR21)

	X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 18), KTESTHISR2_2, "2_2KETST", 2, 2048, KTEST_HISR_PRIORITY2_2,KAL_FALSE)
	X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 18), MOD_KTEST_HISR22)

	X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 19), KTESTHISR2_3, "2_3KETST", 2, 2048, KTEST_HISR_PRIORITY2_3,KAL_FALSE)
	X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 19), MOD_KTEST_HISR23)
#endif


#if defined (__MTK_TARGET__) && !defined(__LITEGPT_HISR_DISABLE__)
 X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 20), LITE_GPT_HISR, "LITEGPT", 2, 1024, LITEGPT_ETMR_HISR, KAL_FALSE)
#endif
 X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 20), MOD_LITE_GPT_HISR)
	
#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 21),   CC_SYS_HISR,   "CCHISR", 1,           2560,            cc_sys_comm_hisr,             KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 21), MOD_P_CC_SYS_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 22), GPT1_HISR, "GPT1_HISR", 1, 1280, GPTCB_10MS_HISR, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 22), MOD_GPT1_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 23), GPT2_HISR, "GPT2_HISR", 1, 1280, GPTCB_US_HISR, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 23), MOD_GPT2_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 24), BUSMON_HISR, "BUSMON_HISR", 1, 1280, drv_busmon_hisr, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 24), MOD_BUSMON_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 25), EINT_HISR, "EINT_HISR", 1, 1280, EINT_HISR_Entry, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 25), MOD_EINTHISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 26), DEINT_HISR, "DEINT_HISR", 1, 1280, DEINT_HISR_Entry, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 26), MOD_DEINT_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 27), GDMA_HISR, "GDMA_HISR", 1, 1280, drv_gdma_hisr, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 27), MOD_GDMA_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 28), EBC_HISR, "EBC_HISR", 1, 1280, ebc_hisr, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 28), MOD_EBC_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 29), DCL_WDT_HISR, "WDT_HISR", 1, 1280, dcl_wdt_hisr, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 29), MOD_DCL_WDT_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 30), UART_1_HISR, "UAR1_HISR", 1, 1280, UART1_HISR, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 30), MOD_UART_1_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 31), UART_2_HISR, "UAR2_HISR", 1, 1280, UART2_HISR, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 31), MOD_UART_2_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 32), GDMA2_HISR, "GDM2_HISR", 1, 1280, uart_hdma_hisr, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 32), MOD_GDMA2_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 33), SIM_HISR, "SIMA_HISR", 1, 1408, SIM_HISR_Multiple, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 33), MOD_SIM_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 34), SIM2_HISR, "SIMB_HISR", 1, 1408, SIM_HISR2_Multiple, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 34), MOD_SIM2_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 35), USIM_HISR, "USIA_HISR", 1, 1408, usim_hisr, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 35), MOD_USIM_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 36), USIM2_HISR, "USIB_HISR", 1, 1408, usim_hisr2, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 36), MOD_USIM2_HISR)

#if defined(__MTK_TARGET__) || defined (__UE_SIMULATOR__) || defined(__FPGA__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 37), DEM_HISR, "DEM_HISR", 1, 1280, drv_dem_hisr, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 37), MOD_DEM_HISR)

#if defined(__MTK_TARGET__) || defined (__UE_SIMULATOR__) || defined(__FPGA__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 38), MTAD_HISR, "MTAD_HISR", 1, 1280, mtad_hisr, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 38), MOD_MTAD_HISR)

#if defined (__MTK_TARGET__) && defined(__HIF_WCCIF_SUPPORT__) && !defined(__WCCIF_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 39), HIF_WCCIF_HISR, "WCCIF_HISR", 0, 1024, hifwccif_hisr_handler, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 39), MOD_HIF_WCCIF_HISR)

#if defined (__MTK_TARGET__) && defined(__HIF_PCCIF_ARM7_SUPPORT__) && !defined(__PCCIF_ARM7_HISR_DISABLE__)
X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 40), HIF_PCCIF_ARM7_HISR, "PCCIF_ARM7_HISR", 0, 1024, hifpccif_arm7_hisr_handler, KAL_FALSE)
#endif
X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 40), MOD_HIF_PCCIF_ARM7_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 41), MDAP_PS_HISR, "MA_PS_HISR", 1, 1280, Drv_MDAPInterface_PS_HISR, KAL_FALSE)
#endif
    X_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 41), MOD_MDAP_PS_HISR)

#if defined(__MTK_TARGET__)
    X_HISR_CONST((HISR_ID_DRV_CODE_BEGIN + 42), PCM_HISR, "PCM_HISR", 1, 512, drv_pcm_hisr, KAL_FALSE)
#endif
    X_MULTI_CORE_HISR_MOD((HISR_ID_DRV_CODE_BEGIN + 42), MOD_PCM_HISR)

//drv max : 40
 /* drv end */



 
