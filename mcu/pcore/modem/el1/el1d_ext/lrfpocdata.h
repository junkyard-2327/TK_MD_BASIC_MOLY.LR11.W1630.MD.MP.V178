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
 * @addtogroup EL1D_RF_CUSTOM_DATA
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @file       lrfpocdata.h
 * @author     Kent Ho (MTK06396)
 * @date       2015.07.31
 * @brief      LTE POC default value header file
 * @details    
 ******************************************************************************/
 
#ifndef  __LRFPOCDATA_H__
#define  __LRFPOCDATA_H__


/*******************************************************************************
 * #include
 ******************************************************************************/
#include "el1d_rf_cal_poc_data.h"

/*******************************************************************************
 * #define
 ******************************************************************************/

#define LTE_Band_PWRON_CAL_DATA(b)        b##_PWRON_CAL_DATA
#define LTE_PWRON_CAL_DATA(b)             LTE_Band_PWRON_CAL_DATA(b)
#define LTE_BAND_2ND_PWRON_CAL_DATA(b)    b##_2ND_PWRON_CAL_DATA
#define LTE_2ND_PWRON_CAL_DATA(b)         LTE_BAND_2ND_PWRON_CAL_DATA(b)

/*************************************************************************************/
/* RX DC default value                                                               */
/*************************************************************************************/
#define LTE_Rx_Dc_Comp_Poc_Default                                                                                                                                                                                                                          \
{                                                                                                                                                                                                                                                           \
   /*rx_rf_dc_hpm: 2(MMRFC_ANT_NUM)*2(MMRFC_RXDC_TIA_GAIN_STEPS)*7(MMRFC_RXDC_PGA_GAIN_STEPS)*/                                                                                                                                                             \
   {                                                                                                                                                                                                                                                        \
      {{{{0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}}, {{0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}}}}, \
      {{{{0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}}, {{0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}, {0xFFE0,0xFFE0}}}}, \
   },                                                                                                                                                                          \
                                                                                                                                                                               \
   /*rx_rf_dc_lpm*/                                                                                                                                                            \
   {                                                                                                                                                                           \
      {0xFFE0,0xFFE0},                                                                                                                                                         \
      {0xFFE0,0xFFE0},                                                                                                                                                         \
   },                                                                                                                                                                          \
                                                                                                                                                                               \
   /*rx_dig_dc_hpm*/                                                                                                                                                           \
   {                                                                                                                                                                           \
      {{{{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}, {{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}}},                                                                \
      {{{{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}, {{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}}},                                                                \
   },                                                                                                                                                                          \
                                                                                                                                                                               \
   /*rx_dig_dc_lpm*/                                                                                                                                                           \
   {                                                                                                                                                                           \
      {0,0},                                                                                                                                                                   \
      {0,0},                                                                                                                                                                   \
   },                                                                                                                                                                          \
                                                                                                                                                                               \
}                                                                                                                                                                              \

/*************************************************************************************/
/* RX IRR default value                                                              */
/*************************************************************************************/
#ifdef TK6291_E1EVB

   #define LTE_Rx_Irr_5Tap_Comp_Poc_Default   \
   {                                          \
      {                                       \
         {0,0,{0,0,511,0,0,0,0}},             \
         {0,0,{0,0,511,0,0,0,0}},             \
      },                                      \
      {                                       \
         {0,0,{0,0,511,0,0,0,0}},             \
         {0,0,{0,0,511,0,0,0,0}},             \
      },                                      \
   }                                          

   #define LTE_Rx_Irr_7Tap_Comp_Poc_Default   \
   {                                          \
      {                                       \
         {0,0,{0,0,0,511,0,0,0}},             \
         {0,0,{0,0,0,511,0,0,0}},             \
      },                                      \
      {                                       \
         {0,0,{0,0,0,511,0,0,0}},             \
         {0,0,{0,0,0,511,0,0,0}},             \
      },                                      \
   }      

#else
   
   #define LTE_Rx_Irr_5Tap_Comp_Poc_Default   \
   {                                          \
      {                                       \
         {0,0,{0,0,511,0,0,0,0}},             \
         {0,0,{0,0,511,0,0,0,0}},             \
      },                                      \
      {                                       \
         {0,0,{0,0,511,0,0,0,0}},             \
         {0,0,{0,0,511,0,0,0,0}},             \
      },                                      \
      {                                       \
         {0,0,{0,0,511,0,0,0,0}},             \
         {0,0,{0,0,511,0,0,0,0}},             \
      },                                      \
   }                                          

   #define LTE_Rx_Irr_7Tap_Comp_Poc_Default   \
   {                                          \
      {                                       \
         {0,0,{0,0,0,511,0,0,0}},             \
         {0,0,{0,0,0,511,0,0,0}},             \
      },                                      \
      {                                       \
         {0,0,{0,0,0,511,0,0,0}},             \
         {0,0,{0,0,0,511,0,0,0}},             \
      },                                      \
      {                                       \
         {0,0,{0,0,0,511,0,0,0}},             \
         {0,0,{0,0,0,511,0,0,0}},             \
      },                                      \
   }                                      

#endif
/*************************************************************************************/
/* IIP2 default value                                                                */
/*************************************************************************************/
#define LTE_Rx_Iip2_Comp_Poc_Default {64, 64} 


/*************************************************************************************/
/* DET IQ default value                                                              */
/*************************************************************************************/
#define LTE_Det_Iq_5Tap_Comp_Default   {0,0,{0,0,511,0,0,0,0}}
#define LTE_Det_Iq_7Tap_Comp_Default   {0,0,{0,0,0,511,0,0,0}}


/****************************************************************************************/
/* RX IRR default value for all BW                                                      */
/****************************************************************************************/
#ifdef TK6291_E1EVB
   //MMRFC_RX_IRR_COMP_ROUTE_MAX = 4
   #define LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE \
   {                                             \
      {                                          \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
      },                                         \
      {                                          \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
      },                                         \
      {                                          \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
      },                                         \
      {                                          \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
      },                                         \
   }
#else
   //LTE_RX_IRR_COMP_ROUTE_MAX = 6
   #define LTE_RX_IRR_COMP_POC_DEFAULT_ALL_ROUTE \
   {                                             \
      {                                          \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
      },                                         \
      {                                          \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
      },                                         \
      {                                          \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
      },                                         \
      {                                          \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
      },                                         \
      {                                          \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
      },                                         \
      {                                          \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_5Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
         LTE_Rx_Irr_7Tap_Comp_Poc_Default,       \
      },                                         \
   }
#endif
/************************************************************************************/
/* RX DC default value                                                              */
/************************************************************************************/
#ifdef TK6291_E1EVB
   //MMRFC_RX_DC_COMP_ROUTE_MAX =4
   #define LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE  \
   {                                             \
      LTE_Rx_Dc_Comp_Poc_Default,                \
      LTE_Rx_Dc_Comp_Poc_Default,                \
      LTE_Rx_Dc_Comp_Poc_Default,                \
      LTE_Rx_Dc_Comp_Poc_Default,                \
   }
#else
   //LTE_RX_DC_COMP_ROUTE_MAX =6
   #define LTE_RX_DC_COMP_POC_DEFAULT_ALL_ROUTE  \
   {                                             \
      LTE_Rx_Dc_Comp_Poc_Default,                \
      LTE_Rx_Dc_Comp_Poc_Default,                \
      LTE_Rx_Dc_Comp_Poc_Default,                \
      LTE_Rx_Dc_Comp_Poc_Default,                \
      LTE_Rx_Dc_Comp_Poc_Default,                \
      LTE_Rx_Dc_Comp_Poc_Default,                \
   }
#endif

/****************************************************************************************/
/* IIP2 default value                                                                   */
/****************************************************************************************/
#ifdef TK6291_E1EVB
   // MMRFC_RX_IIP2_COMP_ROUTE_MAX = 10
   #define LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE  \
   {                                               \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
   }
#else
   // MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11
   #define LTE_RX_IIP2_COMP_POC_DEFAULT_ALL_ROUTE  \
   {                                               \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
      LTE_Rx_Iip2_Comp_Poc_Default,                \
   }
#endif

/****************************************************************************************/
/* TX RC default value                                                                  */
/****************************************************************************************/
#define LTE_TX_LPF_COMP_DEFAULT     {168, 168, 168, 134, 84, 84}
#define LTE_TX_RCF_COMP_DEFAULT     22

/****************************************************************************************/
/* TX IQ default value                                                                  */
/****************************************************************************************/
#ifdef TK6291_E1EVB
   #define LTE_TX_FD_Iq_5Tap_Comp_Default {{0,0,511,0,0,0,0}}
#else
   #define LTE_TX_FD_Iq_5Tap_Comp_Default {{0,0,0,511,0,0,0}}
#endif

#define LTE_TX_FD_Iq_7Tap_Comp_Default {{0,0,0,511,0,0,0}}


/****************************************************************************************/
/* TX GA default value                                                                  */
/****************************************************************************************/
#ifdef TK6291_E1EVB
   #define LTE_TX_GA_5tap_Comp_Default                                                               \
   {                                                                                                 \
      {                                                                                              \
         { {0, 0}, {0, 0}, {0x1FF, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} }, /*tx_ga_filt_lin_1*/        \
         { {0, 0}, {0, 0}, {0x1FF, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} }, /*tx_ga_filt_lin_2*/        \
      },                                                                                             \
      {                                                                                              \
         {0,0,0,0,0,0,0,0,0},  /*slope : MMRFC_TXGA_MAX_TONES-1 */                                   \
         {0,0,0,0,0,0,0,0,0,0},/*mag_inv_norm : MMRFC_TXGA_MAX_TONES */                              \
      },                                                                                             \
   }
#else
   #define LTE_TX_GA_5tap_Comp_Default                                                               \
   {                                                                                                 \
      {                                                                                              \
         { {0, 0}, {0, 0}, {0, 0}, {0x1FF, 0}, {0, 0}, {0, 0}, {0, 0} }, /*tx_ga_filt_lin_1*/        \
         { {0, 0}, {0, 0}, {0, 0}, {0x1FF, 0}, {0, 0}, {0, 0}, {0, 0} }, /*tx_ga_filt_lin_2*/        \
      },                                                                                             \
      {                                                                                              \
         {0,0,0,0,0,0,0,0,0},  /*slope : MMRFC_TXGA_MAX_TONES-1 */                                   \
         {0,0,0,0,0,0,0,0,0,0},/*mag_inv_norm : MMRFC_TXGA_MAX_TONES */                              \
      },                                                                                             \
   }
#endif


#define LTE_TX_GA_7tap_Comp_Default                                                               \
{                                                                                                 \
  {                                                                                               \
    { {0, 0}, {0, 0}, {0, 0}, {0x1FF, 0}, {0, 0}, {0, 0}, {0, 0} }, /*tx_ga_filt_lin_1*/          \
    { {0, 0}, {0, 0}, {0, 0}, {0x1FF, 0}, {0, 0}, {0, 0}, {0, 0} }, /*tx_ga_filt_lin_2*/          \
  },                                                                                              \
  {                                                                                               \
    {0,0,0,0,0,0,0,0,0},  /*slope : MMRFC_TXGA_MAX_TONES-1 */                                     \
    {0,0,0,0,0,0,0,0,0,0},/*mag_inv_norm : MMRFC_TXGA_MAX_TONES */                                \
  },                                                                                              \
}  

/****************************************************************************************/
/* TX/DET DNL default value                                                             */
/****************************************************************************************/
#define LTE_DET_DNL_Default           \
{                                     \
   8115, /* G0 */                     \
   7347, /* G1 */                     \
   6579, /* G2 */                     \
   5811, /* G3 */                     \
   5043, /* G4 */                     \
   4275, /* G5 */                     \
   3507, /* G6 */                     \
   2739, /* G7 */                     \
   1971, /* G8 */                     \
   1203, /* G9 */                     \
   435 , /* G10*/                     \
   -333, /* G11*/                     \
  -1101, /* G12*/                     \
  -1869, /* G13*/                     \
  -2637, /* G14*/                     \
}
  
#define LTE_TX_DNL_PGA_A_Default          \
{                                         \
   /*G00:  */   0,                        \
   /*G01:  */-144,                        \
   /*G02:  */-296,                        \
   /*G03:  */-464,                        \
   /*G04:  */-640,                        \
   /*G05:  */-832,                        \
   /*G06:  */-1048,                       \
   /*G07:  */-1280,                       \
   /*G08:  */-1544,                       \
   /*G09:  */-1840,                       \
   /*G10:  */-2184,                       \
   /*G11:  */-2584,                       \
   /*G12a: */-3080,                       \
   /*G13a: */-3720,                       \
   /*G14a: */-4624,                       \
   /*G15a: */-4920,                       \
   /*G16a: */-5264,                       \
   /*G17a: */-5672,                       \
   /*G18a: */-6168,                       \
   /*G19a: */-6808,                       \
   /*G20a: */-7704,                       \
}

#define PGA_B_COMMON_OFFSET_DB   (3080)  // G12b shift to 0

#define LTE_TX_DNL_PGA_B_Default  /*total 17 */           \
{                                                         \
   /*G12b: */ -3080   +PGA_B_COMMON_OFFSET_DB,            \
   /*G13b: */ -3720   +PGA_B_COMMON_OFFSET_DB,            \
   /*G14b: */ -4624   +PGA_B_COMMON_OFFSET_DB,            \
   /*G15b: */ -4920   +PGA_B_COMMON_OFFSET_DB,            \
   /*G16b: */ -5264   +PGA_B_COMMON_OFFSET_DB,            \
   /*G17b: */ -5672   +PGA_B_COMMON_OFFSET_DB,            \
   /*G18b: */ -6168   +PGA_B_COMMON_OFFSET_DB,            \
   /*G19b: */ -6808   +PGA_B_COMMON_OFFSET_DB,            \
   /*G20b: */ -7704   +PGA_B_COMMON_OFFSET_DB,            \
   /*G21b: */ -9248   +PGA_B_COMMON_OFFSET_DB,            \
   /*G22:  */ -10784  +PGA_B_COMMON_OFFSET_DB,            \
   /*G23:  */ -12320  +PGA_B_COMMON_OFFSET_DB,            \
   /*G24:  */ -13856  +PGA_B_COMMON_OFFSET_DB,            \
   /*G25:  */ -15392  +PGA_B_COMMON_OFFSET_DB,            \
   /*G26:  */ -16928  +PGA_B_COMMON_OFFSET_DB,            \
   /*G27:  */ -18464  +PGA_B_COMMON_OFFSET_DB,            \
   /*G28:  */ -20000  +PGA_B_COMMON_OFFSET_DB,            \
}

//pga_gain_step[MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM/*12*/][MMRFC_TX_PGA_GAIN_STEP_NUM/*10*/]
#define LTE_TX_PGA_AB_Default                                    \
{                                                                \
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
   {-496, -640, -904, -296, -344, -408, -496, -640, -896, -1544},\
}                                        

/*******************************************************************************
 * Typedef
 ******************************************************************************/

/*******************************************************************************
 * Constant
 ******************************************************************************/

/*******************************************************************************
 * Global variables (Extern)
 ******************************************************************************/
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_BandNone_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band1_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band2_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band3_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band4_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band5_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band6_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band7_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band8_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band9_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band10_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band11_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band12_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band13_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band14_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band17_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band18_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band19_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band20_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band21_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band23_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band24_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band25_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band26_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band27_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band28_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band29_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band30_PWRON_CAL_DATA;
#if IS_4G_BAND32_SUPPORT
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band32_PWRON_CAL_DATA;
#endif
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band33_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band34_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band35_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band36_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band37_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band38_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band39_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band40_PWRON_CAL_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band41_PWRON_CAL_DATA;
#if IS_4G_BAND_EXTENSION_SUPPORT
extern const LTE_RF_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band66_PWRON_CAL_DATA;
#endif
extern const LTE_RF_POWER_ON_CAL_DATA_TX_SUBBAND_T LTE_Band40_PWRON_CAL_TX_2ND_3RD_SUBBAND_DATA;
extern const LTE_RF_POWER_ON_CAL_DATA_TX_SUBBAND_T LTE_Band41_PWRON_CAL_TX_2ND_3RD_SUBBAND_DATA;
extern const LTE_RF_2ND_POWER_ON_CAL_DATA_PER_BAND_T LTE_BandNone_2ND_PWRON_CAL_DATA;
extern const LTE_RF_2ND_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band12_2ND_PWRON_CAL_DATA;
extern const LTE_RF_2ND_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band17_2ND_PWRON_CAL_DATA;
extern const LTE_RF_2ND_POWER_ON_CAL_DATA_PER_BAND_T LTE_Band28_2ND_PWRON_CAL_DATA;

 /*****************************************************************************
 * Global Functions Prototype (Interface)
 ******************************************************************************/


#endif //__LRFPOCDATA_H__

/* Doxygen Group End ***************************************************//**@}*/
