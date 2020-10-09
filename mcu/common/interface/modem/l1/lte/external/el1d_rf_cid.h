/******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

/*==============================================================================
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
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
/* Doxygen Group Header ****************************************************//**
 * @addtogroup EL1D_RF_CID
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @file       el1d_rf_cid.h
 * @author     LY Chen (MTK04356)
 * @date       2014.12.16
 * @brief      EL1D RF CID
 * @details    EL1D RF Chip ID and chip compile option
 ******************************************************************************/
  
#ifndef __EL1D_RF_CID_H__
#define __EL1D_RF_CID_H__

/*******************************************************************************
 * #include
 ******************************************************************************/


/*******************************************************************************
 * #define
 ******************************************************************************/

/*******************************************************************************
 ** Define RF chip in use
 ******************************************************************************/
/*------------------------------------------*/
/* Use in EL1D :                            */
/*   ( 1) EL1D_RF_ID_MT6176 (Orion+)        */
/*        ES1, ES1B (with TK6291),          */
/*        and MP (with JADE) version        */
/*------------------------------------------*/
#define EL1D_RF_ID_MT6176                         0x00000001

/*.......................................................*/
#define IS_EL1D_RF_MT6176                        ( EL1D_RF_ID == EL1D_RF_ID_MT6176 )

/*.......................................................*/
#ifndef EL1D_RF_ID
   #if defined(MT6176_RF) || defined(MT6169_RF)  // for ESL building, need to change MT6176 later
#define EL1D_RF_ID                                EL1D_RF_ID_MT6176
   #else
#error "No Valid RF Chip was defined"
   #endif
#else
   #error "Unexpected RF Chip was defined"
#endif //EL1D_RF_ID

#if defined(__TAS_SUPPORT__)
#define IS_4G_TAS_SUPPORT                             1  /* The 4G TAS is supported                                       */
   #if defined (__TAS_INTERNAL_NVRAM_VISIBLE__)
#define IS_4G_TAS_INTERNAL_NVRAM_VISIBLE              1  /* The 4G TAS internal parameters can be controlled by NVRAM     */
   #else
#define IS_4G_TAS_INTERNAL_NVRAM_VISIBLE              0  /* The 4G TAS internal parameters can NOT be controlled by NVRAM */
   #endif
   
   #if defined (__TAS_ANTENNA_IDX_ON_TEST_SIM__)
#define IS_4G_TAS_INIT_SUPPORT 1 /*The 4G TAS INIT Index can be set by band when test sim is inserted*/
   #else
#define IS_4G_TAS_INIT_SUPPORT 0 /*The 4G TAS INIT Index can NOT be set by band when test sim is inserted*/
   #endif
#else
#define IS_4G_TAS_SUPPORT                             1
#define IS_4G_TAS_INTERNAL_NVRAM_VISIBLE              0  /* The 4G TAS internal parameters can NOT be controlled by NVRAM */
#define IS_4G_TAS_INIT_SUPPORT 0 /*The 4G TAS INIT Index can NOT be set by band when test sim is inserted*/
#endif

#define IS_4G_DPD_SUPPORT                             1
#define IS_4G_CIM3_SUPPORT                            1
#define IS_4G_CIM3_SHM_SUPPORT                        0
#define IS_4G_PCFE_SA_TUNE_PARA_SUPPORT               1

#define IS_DPD_LUT_SIZE_GAIN_NUM_8_OR_16              1

#if (!IS_DPD_LUT_SIZE_GAIN_NUM_8_OR_16)
   #define IS_DPD_LUT_SIZE_GAIN_NUM_40                1   
#endif

#if defined(__LTE_L1SIM__) || defined(__EL1D_COSIM__)
#define IS_4G_ET_FEATURE_SUPPORT                      0  // Disable ET feature in xL1SIM and EL1S_COSIM.
#else
#define IS_4G_ET_FEATURE_SUPPORT                      1  /* The 4G ET feature is supported or not */
#endif   // #ifndef __LTE_L1SIM__
/*****************************************************
** LTE ELNA define           
*****************************************************/
#if defined(__L1_EXTERNAL_LNA_SUPPORT__)
#define IS_4G_ELNA_SUPPORT                            1   /* Enable 4G ELNA feautre support */
#else
#define IS_4G_ELNA_SUPPORT                            0  
#endif

/*****************************************************
** TX Power offset define           
*****************************************************/
#if defined (__TX_POWER_OFFSET_SUPPORT__)
#define IS_4G_TX_POWER_OFFSET_SUPPORT                 1  /* Enable Tx power offset for 4G part */
#else
#define IS_4G_TX_POWER_OFFSET_SUPPORT                 0  /* Disable Tx power offset for 4G part */
#endif /*__TX_POWER_OFFSET_SUPPORT__*/  

/*****************************************************
** SAR TX Power offset define           
*****************************************************/
#if defined (__SAR_TX_POWER_BACKOFF_SUPPORT__)
#define IS_4G_SAR_TX_POWER_OFFSET_SUPPORT             1  /* Enable SAR Tx power offset for 4G part */
#else
#define IS_4G_SAR_TX_POWER_OFFSET_SUPPORT             0  /* Disable SAR Tx power offset for 4G part */
#endif /*__SAR_TX_POWER_BACKOFF_SUPPORT__*/  

/*****************************************************
**  HPUE feature  define
*****************************************************/
#if defined (__HPUE_FEATURE_SUPPORT__)
#define IS_4G_HPUE_FEATURE_SUPPORT                 1  /* Enable HPUE for 4G part */
#else
#define IS_4G_HPUE_FEATURE_SUPPORT                 0  /* Disable HPUE for 4G part */
#endif /*__HPUE_FEATURE_SUPPORT__*/

/*****************************************************
** MIPI Antenna tuner define
*****************************************************/

#if defined (__MIPI_ANT_TUNER_SUPPORT__)
#define IS_MIPI_ANT_TUNER_SUPPORT                 1  /* Enable MIPI ANT tuner for 4G part */
#else
#define IS_MIPI_ANT_TUNER_SUPPORT                 0  
#endif /*__MIPI_ANT_TUNER_SUPPORT__*/ 

/*****************************************************
** Dynamic antenna tuning feature
*****************************************************/
#if defined(__DYNAMIC_ANTENNA_TUNING__)
#define __IS_LTE_RF_DAT_SUPPORT__                 1
#else
#define __IS_LTE_RF_DAT_SUPPORT__                 0
#endif

/*****************************************************
** Band 32 support define
*****************************************************/

#if defined(__MTK_INTERNAL__) || defined (__LTE_BAND32_SUPPORT__)
#define IS_4G_BAND32_SUPPORT                     1  /* Enable Support Band32 */
#else
#define IS_4G_BAND32_SUPPORT                     0  
#endif /*__BAND_32_SUPPORT__*/ 

/*****************************************************
** BAND extension define
*****************************************************/
#if defined (__BAND_EXTENSION_SUPPORT__)
#define IS_4G_BAND_EXTENSION_SUPPORT                 1  /* Enable Band extension for 4G part */
#else
#define IS_4G_BAND_EXTENSION_SUPPORT                 0  
#endif /*__BAND_EXTENSION_SUPPORT__*/ 

/*****************************************************
** MPR 64QAM define
*****************************************************/
#if defined (__UL64QAM__)
#define IS_MPR_64QAM_SUPPORT                     1  /* Enable MPR 64QAM */
#else
#define IS_MPR_64QAM_SUPPORT                     0  
#endif /*__UL64QAM__*/ 


/*******************************************************************************
 * Typedef
 ******************************************************************************/

/*******************************************************************************
 * Constant
 ******************************************************************************/

/*******************************************************************************
 * Global variables (Extern)
 ******************************************************************************/




/*******************************************************************************
 * Global Functions Prototype (Interface)
 ******************************************************************************/


#endif /*__EL1D_RF_CID_H__*/

/* Doxygen Group End ***************************************************//**@}*/
