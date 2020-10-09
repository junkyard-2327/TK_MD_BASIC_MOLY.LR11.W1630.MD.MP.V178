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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
/* Doxygen Group Header ****************************************************//**
 * @addtogroup EL1D_SHM_DATA
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @file       lrfpocdata.c
 * @author     Kent Ho (MTK06396)
 * @date       2015.07.31
 * @brief      LTE POC default value by Band
 * @details    
 ******************************************************************************/

/*******************************************************************************
 * #include
 ******************************************************************************/
#include "lrfpocdata.h"        //For POC default table

#if defined(__MTK_INTERNAL__) || defined (__LTE_BAND32_SUPPORT__)
#include "el1d_rf_cid.h"               // for Band extension
#endif

/*******************************************************************************
 * #define
 ******************************************************************************/

/*******************************************************************************
 * typedef
 ******************************************************************************/

/*******************************************************************************
 * Constant
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*************************************************************************************/
/* Default Compensation table of LTE Bands                                           */
/* Power on cal init value pointer array                                             */
/*************************************************************************************/

/*** DO NOT MODIFY VALUE IN TABLES ***/

/* LTE_BandNone */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_BandNone_PWRON_CAL_DATA =
{  
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif
   LTE_BandNone,
   {{{{{{0}}}}}},
   {0},
   {0},
};


/* LTE_Band1 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band1_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif
  LTE_Band1,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x2C,          //tx_lo_capcal_peak_cap
      0x0C,          //tx_lo_in_bias_hpm
      0x0C,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    },          
};

/* LTE_Band2 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band2_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif
  LTE_Band2,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x3C,          //tx_lo_capcal_peak_cap
      0x0C,          //tx_lo_in_bias_hpm
      0x0C,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      9, //cap_tuning_pga_a
      16, //cap_tuning_pga_b
    },          
};

/* LTE_Band3 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band3_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif  
  LTE_Band3,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0x1,           //tx_lo_ind 
      0x6,           //tx_lo_capcal_peak_cap
      0x0B,          //tx_lo_in_bias_hpm
      0x0B,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      17, //cap_tuning_pga_a
      23, //cap_tuning_pga_b
    },          
};

/* LTE_Band4 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band4_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif     
  LTE_Band4,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0x1,           //tx_lo_ind 
      0x7,           //tx_lo_capcal_peak_cap
      0x0B,          //tx_lo_in_bias_hpm
      0x0B,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      17, //cap_tuning_pga_a
      24, //cap_tuning_pga_b
    },         
};

/* LTE_Band5 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band5_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif  
  LTE_Band5,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0x1,           //tx_lo_ind 
      0x2B,          //tx_lo_capcal_peak_cap
      0x0E,          //tx_lo_in_bias_hpm
      0x0E,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      9, //cap_tuning_pga_a
      10, //cap_tuning_pga_b
    },            
};

/* LTE_Band6 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band6_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band6,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0x1,           //tx_lo_ind 
      0x2B,          //tx_lo_capcal_peak_cap
      0x0E,          //tx_lo_in_bias_hpm
      0x0E,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      9, //cap_tuning_pga_a
      10, //cap_tuning_pga_b
    },            
};

/* LTE_Band7 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band7_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band7,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0x0,           //tx_lo_ind 
      0x19,          //tx_lo_capcal_peak_cap
      0x03,          //tx_lo_in_bias_hpm
      0x03,          //tx_lo_in_bias_lpm      
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      8, //cap_tuning_pga_a
      13, //cap_tuning_pga_b
    },           
};

/* LTE_Band8 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band8_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band8,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      1,             //tx_lo_ind 
      0x19,          //tx_lo_capcal_peak_cap
      0x0E,          //tx_lo_in_bias_hpm
      0x0E,          //tx_lo_in_bias_lpm      
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      6, //cap_tuning_pga_a
      8, //cap_tuning_pga_b
    },            
};

/* LTE_Band9 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band9_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band9,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0x1,           //tx_lo_ind 
      0x5,           //tx_lo_capcal_peak_cap
      0x8,           //tx_lo_in_bias_hpm
      0x8,           //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      15, //cap_tuning_pga_a
      22, //cap_tuning_pga_b
    },
};

/* LTE_Band10 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band10_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band10,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0x1,           //tx_lo_ind 
      0x8,           //tx_lo_capcal_peak_cap
      0x8,           //tx_lo_in_bias_hpm
      0x8,           //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      15, //cap_tuning_pga_a
      23, //cap_tuning_pga_b
    },
};

/* LTE_Band11 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band11_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band11,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0x1,           //tx_lo_ind 
      0x3E,          //tx_lo_capcal_peak_cap
      0x6,           //tx_lo_in_bias_hpm
      0x6,           //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      36, //cap_tuning_pga_a
      46, //cap_tuning_pga_b
    },
};

/* LTE_Band12 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band12_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band12,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0x1,           //tx_lo_ind 
      0x60,          //tx_lo_capcal_peak_cap
      0x15,          //tx_lo_in_bias_hpm
      0x15,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      19, //cap_tuning_pga_a
      17, //cap_tuning_pga_b
    },           
};

/* LTE_Band13 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band13_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band13,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x29,          //tx_lo_capcal_peak_cap
      0x0C,          //tx_lo_in_bias_hpm
      0x0C,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      13, //cap_tuning_pga_a
      12, //cap_tuning_pga_b
    },           
};

/* LTE_Band14 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band14_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band14,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x27,          //tx_lo_capcal_peak_cap
      0x0C,          //tx_lo_in_bias_hpm
      0x0C,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      12, //cap_tuning_pga_a
      12, //cap_tuning_pga_b
    },            
};

/* LTE_Band17 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band17_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band17,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      1,             //tx_lo_ind 
      0x60,          //tx_lo_capcal_peak_cap
      0x15,          //tx_lo_in_bias_hpm
      0x15,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      19, //cap_tuning_pga_a
      17, //cap_tuning_pga_b
    },           
};

/* LTE_Band18 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band18_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band18,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },

    { 
      1,             //tx_lo_ind 
      0x2E,          //tx_lo_capcal_peak_cap
      0x0E,          //tx_lo_in_bias_hpm
      0x0E,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      10, //cap_tuning_pga_a
      10, //cap_tuning_pga_b
    },            
};

/* LTE_Band19 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band19_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band19,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      1,             //tx_lo_ind 
      0x2B,          //tx_lo_capcal_peak_cap
      0x0E,          //tx_lo_in_bias_hpm
      0x0E,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      9, //cap_tuning_pga_a
      10, //cap_tuning_pga_b
    },            
};

/* LTE_Band20 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band20_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band20,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      1,             //tx_lo_ind 
      0x28,          //tx_lo_capcal_peak_cap
      0x12,          //tx_lo_in_bias_hpm
      0x12,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      9, //cap_tuning_pga_a
      9, //cap_tuning_pga_b
    },           
};

/* LTE_Band21 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band21_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band21,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      1,             //tx_lo_ind 
      0x3E,          //tx_lo_capcal_peak_cap
      0x06,          //tx_lo_in_bias_hpm
      0x06,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      34, //cap_tuning_pga_a
      45, //cap_tuning_pga_b
    },        
};

/* LTE_Band23 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band23_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band23,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x22,          //tx_lo_capcal_peak_cap
      0x0A,          //tx_lo_in_bias_hpm
      0x0A,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      3, //cap_tuning_pga_a
      13, //cap_tuning_pga_b
    },        
};

/* LTE_Band24 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band24_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band24,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      1,             //tx_lo_ind 
      0x0D,          //tx_lo_capcal_peak_cap
      0x08,          //tx_lo_in_bias_hpm
      0x08,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      22, //cap_tuning_pga_a
      29, //cap_tuning_pga_b
    },        
};

/* LTE_Band25 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band25_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band25,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x3C,          //tx_lo_capcal_peak_cap
      0x0C,          //tx_lo_in_bias_hpm
      0x0C,          //tx_lo_in_bias_lpm 
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      8, //cap_tuning_pga_a
      17, //cap_tuning_pga_b
    },            
};

/* LTE_Band26 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band26_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band26,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x17,          //tx_lo_capcal_peak_cap
      0x0F,          //tx_lo_in_bias_hpm
      0x0F,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      9, //cap_tuning_pga_a
      10, //cap_tuning_pga_b
    },            
};

/* LTE_Band27 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band27_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band27,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      1,             //tx_lo_ind 
      0x34,          //tx_lo_capcal_peak_cap
      0x10,          //tx_lo_in_bias_hpm
      0x10,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      11, //cap_tuning_pga_a
      11, //cap_tuning_pga_b
    },            
};

/* LTE_Band28 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band28_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band28,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      1,             //tx_lo_ind 
      0x5E,          //tx_lo_capcal_peak_cap
      0x18,          //tx_lo_in_bias_hpm
      0x18,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      17, //cap_tuning_pga_a
      16, //cap_tuning_pga_b
    },           
};

/* LTE_Band29 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band29_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band29,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      1,             //tx_lo_ind 
      0x2,           //tx_lo_capcal_peak_cap
      0x1,           //tx_lo_in_bias_hpm
      0x2,           //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      0, //cap_tuning_pga_a
      0, //cap_tuning_pga_b
    },           
};

/* LTE_Band30 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band30_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band30,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  

    { 
      0,             //tx_lo_ind 
      0x3B,          //tx_lo_capcal_peak_cap
      0x03,          //tx_lo_in_bias_hpm
      0x03,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      13, //cap_tuning_pga_a
      19, //cap_tuning_pga_b
    },         
};

#if IS_4G_BAND32_SUPPORT
/* LTE_Band32 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band32_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band32,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      1,             //tx_lo_ind 
      0x2,           //tx_lo_capcal_peak_cap
      0x1,           //tx_lo_in_bias_hpm
      0x2,           //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      0, //cap_tuning_pga_a
      0, //cap_tuning_pga_b
    },           
};
#endif

/* LTE_Band33 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band33_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band33,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  

    { 
      0,             //tx_lo_ind 
      0x33,          //tx_lo_capcal_peak_cap
      0x06,          //tx_lo_in_bias_hpm
      0x06,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      7, //cap_tuning_pga_a
      15, //cap_tuning_pga_b
    },         
};

/* LTE_Band34 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band34_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band34,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x1C,          //tx_lo_capcal_peak_cap
      0x03,          //tx_lo_in_bias_hpm
      0x03,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      2, //cap_tuning_pga_a
      12, //cap_tuning_pga_b
    },
};

/* LTE_Band35 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band35_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band35,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x3A,          //tx_lo_capcal_peak_cap
      0x06,          //tx_lo_in_bias_hpm
      0x06,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      9, //cap_tuning_pga_a
      17, //cap_tuning_pga_b
    },
};

/* LTE_Band36 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band36_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band36,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x27,          //tx_lo_capcal_peak_cap
      0x05,          //tx_lo_in_bias_hpm
      0x05,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      4, //cap_tuning_pga_a
      13, //cap_tuning_pga_b
    },
};

/* LTE_Band37 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band37_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band37,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x33,          //tx_lo_capcal_peak_cap
      0x06,          //tx_lo_in_bias_hpm
      0x06,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      6, //cap_tuning_pga_a
      15, //cap_tuning_pga_b
    },
};


/* LTE_Band38 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band38_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band38,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0xE,           //tx_lo_capcal_peak_cap
      0x2,           //tx_lo_in_bias_hpm
      0x2,           //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      6, //cap_tuning_pga_a
      11, //cap_tuning_pga_b
    },           
};

/* LTE_Band39 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band39_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band39,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x36,          //tx_lo_capcal_peak_cap
      0x06,          //tx_lo_in_bias_hpm
      0x06,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      7, //cap_tuning_pga_a
      16, //cap_tuning_pga_b
    },
};

/* LTE_Band40 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band40_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band40,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x35,          //tx_lo_capcal_peak_cap
      0x4,           //tx_lo_in_bias_hpm
      0x4,           //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      13, //cap_tuning_pga_a
      18, //cap_tuning_pga_b
    },            
};

/* LTE_Band41 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band41_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif   
  LTE_Band41,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0xE,           //tx_lo_capcal_peak_cap
      0x2,           //tx_lo_in_bias_hpm
      0x2,           //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      6, //cap_tuning_pga_a
      11, //cap_tuning_pga_b
    },           
};

/******************************LTE TX POC Subband2 & Subband3 default data*************************/

/* LTE_Band40 Subband2 & Subband3 */
const LTE_RF_POWER_ON_CAL_DATA_TX_SUBBAND_T LTE_Band40_PWRON_CAL_TX_2ND_3RD_SUBBAND_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif    
   LTE_Band40,
   /** SUBBAND2 DATA */
   { 
     0,             //tx_lo_ind 
     0x35,          //tx_lo_capcal_peak_cap
     0x4,           //tx_lo_in_bias_hpm
     0x4,           //tx_lo_in_bias_lpm
     0,             //stx_delta_duty_cycle 
     LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
     LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
     {{0,0}},       //tx_iq_lin
     {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
     {{0,0}},       //tx_iq_dpd
     {{0,0}},       //tx_dc_dpd
#endif
     LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
     LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
     { /*MMRFC_LTE_TX_CBW_NUM = 6*/
       {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
     }, //tx_fdiq_lin_1
     {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
       {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
     }, //tx_fdiq_lin_2
     {
       /*tx_ga_w_ET*/
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
     }, 
     {
       /*tx_ga_wo_ET*/
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
     }, 
     LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
     13, //cap_tuning_pga_a
     18, //cap_tuning_pga_b
   },

   /** SUBBAND3 DATA */
   { 
     0,             //tx_lo_ind 
     0x35,          //tx_lo_capcal_peak_cap
     0x4,           //tx_lo_in_bias_hpm
     0x4,           //tx_lo_in_bias_lpm
     0,             //stx_delta_duty_cycle 
     LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
     LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
     {{0,0}},       //tx_iq_lin
     {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
     {{0,0}},       //tx_iq_dpd
     {{0,0}},       //tx_dc_dpd
#endif
     LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
     LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
     { /*MMRFC_LTE_TX_CBW_NUM = 6*/
       {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
     }, //tx_fdiq_lin_1
     {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
       {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
     }, //tx_fdiq_lin_2
     {
       /*tx_ga_w_ET*/
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
     }, 
     {
       /*tx_ga_wo_ET*/
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
     }, 
     LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
     13, //cap_tuning_pga_a
     18, //cap_tuning_pga_b
   },                
};

/* LTE_Band41 Subband2 & Subband3 */
const LTE_RF_POWER_ON_CAL_DATA_TX_SUBBAND_T LTE_Band41_PWRON_CAL_TX_2ND_3RD_SUBBAND_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif    
   LTE_Band41,
   /** SUBBAND2 DATA */
   { 
     0,             //tx_lo_ind 
     0xE,           //tx_lo_capcal_peak_cap
     0x2,           //tx_lo_in_bias_hpm
     0x2,           //tx_lo_in_bias_lpm
     0,             //stx_delta_duty_cycle 
     LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
     LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
     {{0,0}},       //tx_iq_lin
     {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
     {{0,0}},       //tx_iq_dpd
     {{0,0}},       //tx_dc_dpd
#endif
     LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
     LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
     { /*MMRFC_LTE_TX_CBW_NUM = 6*/
       {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
     }, //tx_fdiq_lin_1
     {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
       {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
     }, //tx_fdiq_lin_2
     {
       /*tx_ga_w_ET*/
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
     }, 
     {
       /*tx_ga_wo_ET*/
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
     }, 
     LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
     6, //cap_tuning_pga_a
     11, //cap_tuning_pga_b
   },

   /** SUBBAND3 DATA */
   { 
     0,             //tx_lo_ind 
     0xE,           //tx_lo_capcal_peak_cap
     0x2,           //tx_lo_in_bias_hpm
     0x2,           //tx_lo_in_bias_lpm
     0,             //stx_delta_duty_cycle 
     LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
     LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
     {{0,0}},       //tx_iq_lin
     {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
     {{0,0}},       //tx_iq_dpd
     {{0,0}},       //tx_dc_dpd
#endif
     LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
     LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
     { /*MMRFC_LTE_TX_CBW_NUM = 6*/
       {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
     }, //tx_fdiq_lin_1
     {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
       {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
          LTE_TX_FD_Iq_5Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
       {
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
          LTE_TX_FD_Iq_7Tap_Comp_Default,
       },
     }, //tx_fdiq_lin_2
     {
       /*tx_ga_w_ET*/
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
     }, 
     {
       /*tx_ga_wo_ET*/
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
       {
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_5tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
          LTE_TX_GA_7tap_Comp_Default,
       },
     }, 
     LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
     6, //cap_tuning_pga_a
     11, //cap_tuning_pga_b
   },                
};

/* LTE_BandNone */
const LTE_RF_2ND_POWER_ON_CAL_DATA_PER_BAND_T LTE_BandNone_2ND_PWRON_CAL_DATA =
{  
   0, //Verno
   LTE_BandNone,
   {0},
   {0},
};


/* LTE_Band12 */
const LTE_RF_2ND_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band12_2ND_PWRON_CAL_DATA =
{
   0, //Verno
  LTE_Band12,
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x2C,          //tx_lo_capcal_peak_cap
      0x0C,          //tx_lo_in_bias_hpm
      0x0C,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      {160,160,160,128,80,80}, //tx_rc_lpf 
      21,            //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd

      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    },          
};

/* LTE_Band17 */
const LTE_RF_2ND_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band17_2ND_PWRON_CAL_DATA =
{
   0, //Verno
  LTE_Band17,
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x2C,          //tx_lo_capcal_peak_cap
      0x0C,          //tx_lo_in_bias_hpm
      0x0C,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      {160,160,160,128,80,80}, //tx_rc_lpf 
      21,            //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd

      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    },          
};

/* LTE_Band28 */
const LTE_RF_2ND_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band28_2ND_PWRON_CAL_DATA =
{
   0, //Verno
  LTE_Band17,
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo_ind 
      0x2C,          //tx_lo_capcal_peak_cap
      0x0C,          //tx_lo_in_bias_hpm
      0x0C,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      {160,160,160,128,80,80}, //tx_rc_lpf 
      21,            //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd

      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    },          
};

#if IS_4G_BAND_EXTENSION_SUPPORT
/* LTE_Band66 */
const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band66_PWRON_CAL_DATA =
{
#ifdef TK6291_E1EVB
#else
   LTE_POC_NVRAM_LATEST_VERNO, //Verno
#endif     
  LTE_Band66,
  { 
    /*RX POC Compensation default value*/
    LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE,    
    LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE,
    LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE,
  },
  {
    0x84210, //det_coarse_dcoc_cw807
    0x84210, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_5Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,
         LTE_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    LTE_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0x1,           //tx_lo_ind 
      0x6,           //tx_lo_capcal_peak_cap
      0x0B,          //tx_lo_in_bias_hpm
      0x0B,          //tx_lo_in_bias_lpm
      0,             //stx_delta_duty_cycle 
      LTE_TX_LPF_COMP_DEFAULT, //tx_rc_lpf 
      LTE_TX_RCF_COMP_DEFAULT, //tx_rc_rcf 
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifdef TK6291_E1EVB
#else
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      LTE_TX_DNL_PGA_A_Default,           //tx_dnl_pga_a
      LTE_TX_DNL_PGA_B_Default,           //tx_dnl_pga_b
      { /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_LTE_TX_CBW_NUM = 6*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
           LTE_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
        {
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
           LTE_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
        {
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_5tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
           LTE_TX_GA_7tap_Comp_Default,
        },
      }, 
      LTE_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      17, //cap_tuning_pga_a
      23, //cap_tuning_pga_b
    },
};
#endif

/*******************************************************************************
 * Local Variables
 * Static variables declaration
 ******************************************************************************/

/*******************************************************************************
 * Local Functions
 * Static Functions Prototype
 ******************************************************************************/

/*******************************************************************************
 * Static Functions declaration
 ******************************************************************************/

/*******************************************************************************
 * Global Functions declaration (interface)
 ******************************************************************************/





/* Doxygen Group End ***************************************************//**@}*/

