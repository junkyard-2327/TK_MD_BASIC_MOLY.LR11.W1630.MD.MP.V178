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
 * wdata.c
 *
 * Project:
 * --------
 * MT6268
 *
 * Description:
 * ------------
 * Variables/Arrays for customer to make their own configurations.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*===============================================================================*/

#include "kal_general_types.h"

#include "ul1d_custom_rf.h"
#include "wcustomdata.h"

#include "ul1d_rf_public.h"
#include "ul1d_rf_common.h"
#include "ul1d_rf_cid.h"
#include "ul1cal.h"
#if (IS_3G_MIPI_SUPPORT)
#include "ul1d_custom_mipi.h"
#endif

#if defined(L1_SIM)
#include "SymWrap.h"
#endif

#include "ul1d_custom_rf_ca.h"
#if IS_3G_DAT_UL1_CUSTOM_SUPPORT
#include "ul1d_custom_rf_dat.h"
#endif
/*===============================================================================*/


//ANT0/1
#define W_Rx_Irr_5Tap_Comp_Poc_Default   \
{                                         \
   {0,0,{0,0,511,0,0,0,0}},               \
   {0,0,{0,0,511,0,0,0,0}},               \
}                                         \

//ANT0/1
#define W_Rx_Irr_7Tap_Comp_Poc_Default   \
{                                      \
   {0,0,{0,0,0,511,0,0,0}},         \
   {0,0,{0,0,0,511,0,0,0}},         \
}                                      \

#define W_Rx_Iip2_Comp_Poc_Default {64, 64} 

//TX part
#define UMTS_Det_Iq_5Tap_Comp_Default   {0,0,{0,0,511,0,0,0,0}}
#define UMTS_Det_Iq_7Tap_Comp_Default   {0,0,{0,0,0,511,0,0,0}}
#define UMTS_TX_FD_Iq_5Tap_Comp_Default {{0,0,511,0,0,0,0}}
#define UMTS_TX_FD_Iq_7Tap_Comp_Default {{0,0,0,511,0,0,0}}

#define UMTS_TX_GA_5tap_Comp_Default                                                               \
{                                                                                                 \
  {                                                                                               \
    { {0, 0}, {0, 0}, {0x1FF, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} }, /*tx_ga_filt_lin_1*/         \
    { {0, 0}, {0, 0}, {0x1FF, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} }, /*tx_ga_filt_lin_2*/         \
  },                                                                                              \
  {                                                                                               \
    {0,0,0,0,0,0,0,0,0},  /*slope : MMRFC_TXGA_MAX_TONES-1 */                                     \
    {0,0,0,0,0,0,0,0,0,0},/*mag_inv_norm : MMRFC_TXGA_MAX_TONES */                                \
  },                                                                                              \
}                                                                                                 

#define UMTS_TX_GA_7tap_Comp_Default                                                               \
{                                                                                                 \
  {                                                                                               \
    { {0, 0}, {0, 0}, {0, 0}, {0x1FF, 0}, {0, 0}, {0, 0}, {0, 0} }, /*tx_ga_filt_lin_1*/         \
    { {0, 0}, {0, 0}, {0, 0}, {0x1FF, 0}, {0, 0}, {0, 0}, {0, 0} }, /*tx_ga_filt_lin_2*/         \
  },                                                                                              \
  {                                                                                               \
    {0,0,0,0,0,0,0,0,0},  /*slope : MMRFC_TXGA_MAX_TONES-1 */                                     \
    {0,0,0,0,0,0,0,0,0,0},/*mag_inv_norm : MMRFC_TXGA_MAX_TONES */                                \
  },                                                                                              \
} 

/* Default value from EVB2 V2SKU1-MB#133 + RF#028 with MT6176, B1/2/4/5/8 almost the same */
#define UMTS_DET_DNL_Default                                          \
{                                                                    \
   1024, /*   G0*/                      \
    928, /*   G1*/                      \
    832, /*   G2*/                      \
    736, /*   G3*/                       \
    640, /*   G4*/                       \
    544, /*   G5*/                       \
    448, /*   G6*/            \
    361, /*   G7*/                     \
    265, /*   G8*/                     \
    169, /*   G9*/                     \
     73, /*   G10*/                     \
    -23, /*   G11*/                     \
   -119, /*   G12*/            \
   -215, /*   G13*/                     \
   -311, /*   G14*/                     \
}

//pga_gain_step[MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM/*12*/][MMRFC_TX_PGA_GAIN_STEP_NUM/*10*/]
#define UMTS_TX_PGA_AB_Default                                    \
{                                                                \
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
}  

#define UMTS_TX_PGA_PHASE_Default  (0)


kal_uint8 ul1d_BandInfo[5] ={ RX_BAND_INDICATOR_0,
                              RX_BAND_INDICATOR_1,
                              RX_BAND_INDICATOR_2,
                              RX_BAND_INDICATOR_3,
                              RX_BAND_INDICATOR_4};

kal_uint32 ul1d_CaBandInfo[UMTS_RF_CA_FE_NUM_MAX] ={RX_CABAND_IND_00,
                                                    RX_CABAND_IND_01,
                                                    RX_CABAND_IND_02,
                                                    RX_CABAND_IND_03,
                                                    RX_CABAND_IND_04};

UMTS_FE_ROUTE_TABLE_T UMTS_FRONT_END_ROUTE_TABLE_PCORE[] =
{
   /* Single Band FE Route Table */
   UMTS_SB_FE_SETTING(RX_BAND_INDICATOR_0, SetDefault),
   UMTS_SB_FE_SETTING(RX_BAND_INDICATOR_1, SetDefault),
   UMTS_SB_FE_SETTING(RX_BAND_INDICATOR_2, SetDefault),
   UMTS_SB_FE_SETTING(RX_BAND_INDICATOR_3, SetDefault),
   UMTS_SB_FE_SETTING(RX_BAND_INDICATOR_4, SetDefault),

   /* CA Band FE Route Table*/
   UMTS_CA_FE_SETTING(RX_CABAND_IND_00, SetDefault),
   UMTS_CA_FE_SETTING(RX_CABAND_IND_01, SetDefault),
   UMTS_CA_FE_SETTING(RX_CABAND_IND_02, SetDefault),
   UMTS_CA_FE_SETTING(RX_CABAND_IND_03, SetDefault),
   UMTS_CA_FE_SETTING(RX_CABAND_IND_04, SetDefault),
};

//kevin phase3 for COSIM RF
/* To fit the case once user who does not use Modem Bin Update tool but modifies makefile/ul1d_custom_rf.h band setting and rebuild */
U_sUl1dRfCustomInputData UMTS_RF_CUSTOM_INPUT_DATA_PCORE =
{
   /* Start Pattern */
   0x1234ABCD,

   /* Structure Version */
   1,

   /* RF Type */
   UMTS_RF_TYPE,

   /* isDataUpdate */
   1,

#if defined (__UL1_HS_PLUS_PLATFORM__)
   /* proityOfNvramInCustomization */
   RF_SETTING_BY_NVRAM,
#endif

   /* umtsRfPaControlTimingOffset */
   {
      MAX_OFFSET,
      VM_OFFSET,
      VBIAS_OFFSET,
      DC2DC_OFFSET,
      VGA_OFFSET
   },

   /* umtsBsiBpiTiming */
   {
      /* RX window end timing */
      -TC_PR1,
      -TC_PR2,
      -TC_PR2B,

      /* RX window end timing */
      TC_PR3,
      TC_PR3A,

      /* TX window start timing */
      -TC_PT1,
      -TC_PT2,
      -TC_PT2B,

      /* TX window end timing */
      TC_PT3,
      TC_PT3A
   },

   /* umtsPdata */
   {
      /* rxBpi */
      {
         /*Band_Ind_0*/
         {
            RX_BAND_INDICATOR_0, 
            {
               M_UMTS_PDATA_PR1(RX_BAND_INDICATOR_0),
               M_UMTS_PDATA_PR2(RX_BAND_INDICATOR_0),
               M_UMTS_PDATA_PR2(RX_BAND_INDICATOR_0), /* PR2b */
               M_UMTS_PDATA_PR3(RX_BAND_INDICATOR_0),
               M_UMTS_PDATA_PR3(RX_BAND_INDICATOR_0)  /* PR3a */
            }
         },
         /*Band_Ind_1*/
         {
            RX_BAND_INDICATOR_1, 
            {
               M_UMTS_PDATA_PR1(RX_BAND_INDICATOR_1),
               M_UMTS_PDATA_PR2(RX_BAND_INDICATOR_1),
               M_UMTS_PDATA_PR2(RX_BAND_INDICATOR_1), /* PR2b */
               M_UMTS_PDATA_PR3(RX_BAND_INDICATOR_1),
               M_UMTS_PDATA_PR3(RX_BAND_INDICATOR_1)  /* PR3a */
            }
         },
         /*Band_Ind_2*/
         {
            RX_BAND_INDICATOR_2, 
            {
               M_UMTS_PDATA_PR1(RX_BAND_INDICATOR_2),
               M_UMTS_PDATA_PR2(RX_BAND_INDICATOR_2),
               M_UMTS_PDATA_PR2(RX_BAND_INDICATOR_2), /* PR2b */
               M_UMTS_PDATA_PR3(RX_BAND_INDICATOR_2),
               M_UMTS_PDATA_PR3(RX_BAND_INDICATOR_2)  /* PR3a */
            }
         },
         /*Band_Ind_3*/
         {
            RX_BAND_INDICATOR_3, 
            {
               M_UMTS_PDATA_PR1(RX_BAND_INDICATOR_3),
               M_UMTS_PDATA_PR2(RX_BAND_INDICATOR_3),
               M_UMTS_PDATA_PR2(RX_BAND_INDICATOR_3), /* PR2b */
               M_UMTS_PDATA_PR3(RX_BAND_INDICATOR_3),
               M_UMTS_PDATA_PR3(RX_BAND_INDICATOR_3)  /* PR3a */
            }
         },
         /*Band_Ind_4*/
         {
            RX_BAND_INDICATOR_4, 
            {
               M_UMTS_PDATA_PR1(RX_BAND_INDICATOR_4),
               M_UMTS_PDATA_PR2(RX_BAND_INDICATOR_4),
               M_UMTS_PDATA_PR2(RX_BAND_INDICATOR_4), /* PR2b */
               M_UMTS_PDATA_PR3(RX_BAND_INDICATOR_4),
               M_UMTS_PDATA_PR3(RX_BAND_INDICATOR_4)  /* PR3a */
            }
         },
         /* CA usage */
         {0}
      }, //RxBpi structure

      /* txBpi */
      {
         /*Band_Ind_0*/
         {
            RX_BAND_INDICATOR_0, 
            {
               M_UMTS_PDATA_PT1(RX_BAND_INDICATOR_0),
               M_UMTS_PDATA_PT2(RX_BAND_INDICATOR_0),
               M_UMTS_PDATA_PT2(RX_BAND_INDICATOR_0), /* PT2b */
               M_UMTS_PDATA_PT3(RX_BAND_INDICATOR_0),
               M_UMTS_PDATA_PT3(RX_BAND_INDICATOR_0)  /* PT3a */
            }
         },
         /*Band_Ind_1*/
         {
            RX_BAND_INDICATOR_1, 
            {
               M_UMTS_PDATA_PT1(RX_BAND_INDICATOR_1),
               M_UMTS_PDATA_PT2(RX_BAND_INDICATOR_1),
               M_UMTS_PDATA_PT2(RX_BAND_INDICATOR_1), /* PT2b */
               M_UMTS_PDATA_PT3(RX_BAND_INDICATOR_1),
               M_UMTS_PDATA_PT3(RX_BAND_INDICATOR_1)  /* PT3a */
            }
         },
         /*Band_Ind_2*/
         {
            RX_BAND_INDICATOR_2, 
            {
               M_UMTS_PDATA_PT1(RX_BAND_INDICATOR_2),
               M_UMTS_PDATA_PT2(RX_BAND_INDICATOR_2),
               M_UMTS_PDATA_PT2(RX_BAND_INDICATOR_2), /* PT2b */
               M_UMTS_PDATA_PT3(RX_BAND_INDICATOR_2),
               M_UMTS_PDATA_PT3(RX_BAND_INDICATOR_2)  /* PT3a */
            }
         },
         /*Band_Ind_3*/
         {
            RX_BAND_INDICATOR_3, 
            {
               M_UMTS_PDATA_PT1(RX_BAND_INDICATOR_3),
               M_UMTS_PDATA_PT2(RX_BAND_INDICATOR_3),
               M_UMTS_PDATA_PT2(RX_BAND_INDICATOR_3), /* PT2b */
               M_UMTS_PDATA_PT3(RX_BAND_INDICATOR_3),
               M_UMTS_PDATA_PT3(RX_BAND_INDICATOR_3)  /* PT3a */
            }
         },
         /*Band_Ind_4*/
         {
            RX_BAND_INDICATOR_4, 
            {
               M_UMTS_PDATA_PT1(RX_BAND_INDICATOR_4),
               M_UMTS_PDATA_PT2(RX_BAND_INDICATOR_4),
               M_UMTS_PDATA_PT2(RX_BAND_INDICATOR_4), /* PT2b */
               M_UMTS_PDATA_PT3(RX_BAND_INDICATOR_4),
               M_UMTS_PDATA_PT3(RX_BAND_INDICATOR_4)  /* PT3a */
            }
         },
         /* CA usage */
         {0}
      } //TxBpi structure
   },

   /* umtsBandIndicator */
   {
      RX_BAND_INDICATOR_0,
      RX_BAND_INDICATOR_1,
      RX_BAND_INDICATOR_2,
      RX_BAND_INDICATOR_3,
      RX_BAND_INDICATOR_4
   },

   /* sUl1dRfRxLnaPortSel */
   {
    {
      /* Band_ind_0 */
      {
         RX_BAND_INDICATOR_0,
         {M_UMTS_RX_IO(RX_BAND_INDICATOR_0), M_UMTS_RXD_IO(RX_BAND_INDICATOR_0)}
      },
      /* Band_ind_1 */
      {
         RX_BAND_INDICATOR_1,
         {M_UMTS_RX_IO(RX_BAND_INDICATOR_1), M_UMTS_RXD_IO(RX_BAND_INDICATOR_1)}
      },
      /* Band_ind_2 */
      {
         RX_BAND_INDICATOR_2,
         {M_UMTS_RX_IO(RX_BAND_INDICATOR_2), M_UMTS_RXD_IO(RX_BAND_INDICATOR_2)}
      },
      /* Band_ind_3 */
      {
         RX_BAND_INDICATOR_3,
         {M_UMTS_RX_IO(RX_BAND_INDICATOR_3), M_UMTS_RXD_IO(RX_BAND_INDICATOR_3)}
      },
      /* Band_ind_4 */
      {
         RX_BAND_INDICATOR_4,
         {M_UMTS_RX_IO(RX_BAND_INDICATOR_4), M_UMTS_RXD_IO(RX_BAND_INDICATOR_4)}
      },
      /* CA usage */
      {0}
    }
   },

   /* umtsTxPathSel */
   {
    {
      /* Band_ind_0 */
      {
         RX_BAND_INDICATOR_0,
         {M_UMTS_TX_IO(RX_BAND_INDICATOR_0),M_UMTS_TX_DET_IO(RX_BAND_INDICATOR_0)}  
      },
      /* Band_ind_1 */
      {
         RX_BAND_INDICATOR_1,
         {M_UMTS_TX_IO(RX_BAND_INDICATOR_1),M_UMTS_TX_DET_IO(RX_BAND_INDICATOR_1)}
      },
      /* Band_ind_2 */
      {
         RX_BAND_INDICATOR_2,
         {M_UMTS_TX_IO(RX_BAND_INDICATOR_2),M_UMTS_TX_DET_IO(RX_BAND_INDICATOR_2)}
      },
      /* Band_ind_3 */
      {
         RX_BAND_INDICATOR_3,
         {M_UMTS_TX_IO(RX_BAND_INDICATOR_3),M_UMTS_TX_DET_IO(RX_BAND_INDICATOR_3)}
      },
      /* Band_ind_4 */
      {
         RX_BAND_INDICATOR_0,
         {M_UMTS_TX_IO(RX_BAND_INDICATOR_4),M_UMTS_TX_DET_IO(RX_BAND_INDICATOR_4)}
      },
      /* CA usage */
      {0}
    }
   },

   /* xPMU_PA_CONTROL */
   PMU_PASETTING,

#if defined (__UL1_HS_PLUS_PLATFORM__)   
   /* umtsMprBackOff */
   {
      {
         MPR_BACK_OFF_HSDPA_BAND1 , MPR_BACK_OFF_HSDPA_BAND2 , MPR_BACK_OFF_HSDPA_BAND3 , MPR_BACK_OFF_HSDPA_BAND4 , MPR_BACK_OFF_HSDPA_BAND5 ,
         MPR_BACK_OFF_HSDPA_BAND6 , MPR_BACK_OFF_HSDPA_BAND7 , MPR_BACK_OFF_HSDPA_BAND8 , MPR_BACK_OFF_HSDPA_BAND9 , MPR_BACK_OFF_HSDPA_BAND10,
         MPR_BACK_OFF_HSDPA_BAND11, MPR_BACK_OFF_HSDPA_BAND12, MPR_BACK_OFF_HSDPA_BAND13, MPR_BACK_OFF_HSDPA_BAND14, MPR_BACK_OFF_HSDPA_BAND15,
         MPR_BACK_OFF_HSDPA_BAND16, MPR_BACK_OFF_HSDPA_BAND17, MPR_BACK_OFF_HSDPA_BAND18, MPR_BACK_OFF_HSDPA_BAND19, MPR_BACK_OFF_HSDPA_BAND19
      },
      {
         MPR_BACK_OFF_HSUPA_BAND1 , MPR_BACK_OFF_HSUPA_BAND2 , MPR_BACK_OFF_HSUPA_BAND3 , MPR_BACK_OFF_HSUPA_BAND4 , MPR_BACK_OFF_HSUPA_BAND5 ,
         MPR_BACK_OFF_HSUPA_BAND6 , MPR_BACK_OFF_HSUPA_BAND7 , MPR_BACK_OFF_HSUPA_BAND8 , MPR_BACK_OFF_HSUPA_BAND9 , MPR_BACK_OFF_HSUPA_BAND10,
         MPR_BACK_OFF_HSUPA_BAND11, MPR_BACK_OFF_HSUPA_BAND12, MPR_BACK_OFF_HSUPA_BAND13, MPR_BACK_OFF_HSUPA_BAND14, MPR_BACK_OFF_HSUPA_BAND15,
         MPR_BACK_OFF_HSUPA_BAND16, MPR_BACK_OFF_HSUPA_BAND17, MPR_BACK_OFF_HSUPA_BAND18, MPR_BACK_OFF_HSUPA_BAND19, MPR_BACK_OFF_HSUPA_BAND19
      }
   },
#endif
   
   /* RxD support bit map*/
   RX_DIVERSITY_ALWAYS_ON,
   
   /* Tx PA dirft compensation bit map*/
   PA_DIRFT_COMPENSATION,

   /*At MT6589+MT6320PMIC, Vrf18_1(MD1) can use bulk/LDO mode, this is the switch*/
   ULTRA_LOW_COST_EN,

   /*At MT6589/MT6280+OrionRF, temperature measurement enable switch */
   TEAMPERATURE_MEAS_EN,
	  
   /* Baseband Idle Mode RXD Feature enable Default ON */
   KAL_FALSE,

   /* VPA Mode Setting */
   VPA_FPWM_MODE,

   /* PA Section */
   PA_SECTION,

#if IS_3G_MIPI_SUPPORT
   {
      IS_3G_MIPI_ENABLE,
      MIPI_OFFSET
      #if IS_3G_ET_SUPPORT
      ,IS_3G_ET_ENABLE
      #endif
   },
#endif

   /* umtsCaBandIndicator */
   {
      RX_CABAND_IND_00,
      RX_CABAND_IND_01,
      RX_CABAND_IND_02,
      RX_CABAND_IND_03,
      RX_CABAND_IND_04,
   },
   
   /* CA RF FE usage table */
   //UMTS_FE_USAGE_T umtsCaFrontEndUsageLut[UMTS_RF_FRONT_END_NUM_MAX];
   {
      {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
      {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
      {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
      {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
      {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
      {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
      {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
      {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
      {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
      {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}}
   },

#if IS_3G_FDD_RX_PATH_SELECTION_SUPPORT   
   {
      KAL_FALSE,
      ANT_RX_BOTH,
   },
#endif

#if IS_3G_BAND5_AND_BAND6_INDICATOR_SUPPORT
   BAND5_AND_BAND6_INDICATOR,
#endif

   /* End Pattern */
   0xABCD1234
};

#if IS_3G_TAS_SUPPORT

U_sUl1dRfTasData UMTS_TAS_RF_TABLE_PCORE =
{
 /*umtsTasMask*/
  UMTS_TAS_BPI_PIN_MASK,
 /*umtsTasPdata*/
 {
  PDATA_Band1_TAS1,
  PDATA_Band1_TAS2,
  PDATA_Band1_TAS3,
  PDATA_Band2_TAS1,
  PDATA_Band2_TAS2,
  PDATA_Band2_TAS3,
  PDATA_Band3_TAS1,
  PDATA_Band3_TAS2,
  PDATA_Band3_TAS3,
  PDATA_Band4_TAS1,
  PDATA_Band4_TAS2,
  PDATA_Band4_TAS3,
  PDATA_Band5_TAS1,
  PDATA_Band5_TAS2,
  PDATA_Band5_TAS3,
  PDATA_Band6_TAS1,
  PDATA_Band6_TAS2,
  PDATA_Band6_TAS3,
  PDATA_Band7_TAS1,
  PDATA_Band7_TAS2,
  PDATA_Band7_TAS3,
  PDATA_Band8_TAS1,
  PDATA_Band8_TAS2,
  PDATA_Band8_TAS3,
  PDATA_Band9_TAS1,
  PDATA_Band9_TAS2,
  PDATA_Band9_TAS3,
  PDATA_Band10_TAS1,
  PDATA_Band10_TAS2,
  PDATA_Band10_TAS3,
  PDATA_Band11_TAS1,
  PDATA_Band11_TAS2,
  PDATA_Band11_TAS3,
  PDATA_Band19_TAS1,
  PDATA_Band19_TAS2,
  PDATA_Band19_TAS3
 }
};

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
#endif

#if IS_3G_DAT_UL1_CUSTOM_SUPPORT
UMTS_CUSTOM_DAT_FE_DATABASE_T UMTS_DAT_FE_DATABASE_SetDefault = 
{
   {{{0}}}, {{{0}}}
};

UMTS_CUSTOM_DAT_FEATURE_BY_RAT_T UMTS_DAT_FEATURE_BY_RAT_SetDefault = 
{
   UMTS_DAT_FEATURE_ENABLE(SetDefault),  
   UMTS_DAT_SCENARIO_DEFAULT
};
#endif

#endif/*IS_3G_TAS_SUPPORT*/

//Power on CAL
const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBandNone_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBandNone,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif
      },
   }, //wcdma_rx_comp
   
   {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      0,             //tx_lo_ind
      0x2C,          //tx_lo_capcal_peak_cap
      0x0F,          //tx_lo_in_bias_hpm
      0x0F,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf 
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    }, 
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand1_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand1,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif
      },
   }, //wcdma_rx_comp
   
   {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      0,             //tx_lo_ind
      0x2C,          //tx_lo_capcal_peak_cap
      0x0F,          //tx_lo_in_bias_hpm
      0x0F,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf 
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    }, 
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand2_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand2,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif         
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif        
      },
   },
   
  {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      0,             //tx_lo_ind
      0x3C,          //tx_lo_capcal_peak_cap
      0x10,          //tx_lo_in_bias_hpm
      0x10,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf 
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    }, 
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand3_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand3,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif
      },
   }, //wcdma_rx_comp
   
   {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      1,             //tx_lo_ind
      0x06,          //tx_lo_capcal_peak_cap
      0x0B,          //tx_lo_in_bias_hpm
      0x0B,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf 
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      17, //cap_tuning_pga_a
      23, //cap_tuning_pga_b
    }, 
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand4_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand4,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif          
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif         
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif        
      },
   },
  {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      1,             //tx_lo_ind
      0x7,           //tx_lo_capcal_peak_cap
      0x13,          //tx_lo_in_bias_hpm
      0x13,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    }, 
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand5_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand5,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif         
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif        
      },
   },
  {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      1,             //tx_lo_ind
      0x2B,          //tx_lo_capcal_peak_cap
      0x0E,          //tx_lo_in_bias_hpm
      0x0E,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    },
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand6_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand6,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif         
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif        
      },
   },
  {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      1,             //tx_lo_ind
      0x2B,          //tx_lo_capcal_peak_cap
      0x0E,          //tx_lo_in_bias_hpm
      0x0E,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    },
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand8_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand8,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif         
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif        
      },
   },
   
  {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      1,             //tx_lo_ind
      0x19,          //tx_lo_capcal_peak_cap
      0x0C,          //tx_lo_in_bias_hpm
      0x0C,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      5, //cap_tuning_pga_a
      14, //cap_tuning_pga_b
    },  
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand9_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand9,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif         
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif        
      },
   },
  {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      1,             //tx_lo_ind
      0x05,          //tx_lo_capcal_peak_cap
      0x08,          //tx_lo_in_bias_hpm
      0x08,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      15, //cap_tuning_pga_a
      22, //cap_tuning_pga_b
    },
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand11_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand11,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif         
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif        
      },
   },
  {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      1,             //tx_lo_ind
      0x3E,          //tx_lo_capcal_peak_cap
      0x06,          //tx_lo_in_bias_hpm
      0x06,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      36, //cap_tuning_pga_a
      46, //cap_tuning_pga_b
    },
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand18_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand18,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif         
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif        
      },
   },
  {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      1,             //tx_lo_ind
      0x2E,          //tx_lo_capcal_peak_cap
      0x0E,          //tx_lo_in_bias_hpm
      0x0E,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      10, //cap_tuning_pga_a
      10, //cap_tuning_pga_b
    },
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T UMTSBand19_PWRON_CAL_DATA =
{  
#ifndef TK6291_E1EVB
   0, //Verno
#endif
   UMTSBand19,
   {
        {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, HPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       {
         /*MMRFC_RX_IRR_COMP_ROUTE_MAX = 5, LPM*/
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,    
         },
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
            W_Rx_Irr_5Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,
            W_Rx_Irr_7Tap_Comp_Poc_Default,     
         },
#endif         
       },
       /* MMRFC_RX_DC_COMP_ROUTE_MAX = 5 */
       /* RF DC HPM*/
      {
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
          {
            {
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
               {{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0},{0xFFE0,0xFFE0}},
            },
          },
         },
#endif         
      },
      /* RF DC LPM*/
      {
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0xFFE0,0xFFE0
          },
          {
            0xFFE0,0xFFE0
          },
         },
#endif         
      },
      /* DIG DC HPM*/
      {
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
          {
            {
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
               {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}},
            },
          },
         },
#endif
      },
      /* DIG DC LPM*/
      {
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
         {
          {
            0,0
          },
          {
            0,0
          },
         },
#endif         
      },            

       /*MMRFC_RX_IIP2_COMP_ROUTE_MAX = 11 */
      {
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
        W_Rx_Iip2_Comp_Poc_Default,
#ifndef TK6291_E1EVB  //Only available for chip later than TK6291 because TK6291 calibration file has no these items
        W_Rx_Iip2_Comp_Poc_Default,
#endif        
      },
   },
  {
    0, //det_coarse_dcoc_cw807
    0, //det_coarse_dcoc_cw808
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS = 15
    UMTS_DET_DNL_Default,     //det_dnl, MMRFC_DET_GAIN_STEPS = 15
    { /* MMRFC_DET_FE_GAIN_STEPS = 2 */
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,                     
      },
      {
         UMTS_Det_Iq_5Tap_Comp_Default,
         UMTS_Det_Iq_7Tap_Comp_Default,       
      },    
    },
    {{0,0}}, //det_dc , MMRFC_DET_GAIN_STEPS =15
    UMTS_DET_DNL_Default,//det_dnl, MMRFC_DET_GAIN_STEPS = 15    
  },
  
    { 
      0,             //tx_lo: no use
      1,             //tx_lo_ind
      0x2B,          //tx_lo_capcal_peak_cap
      0x0E,          //tx_lo_in_bias_hpm
      0x0E,          //tx_lo_in_bias_lpm				
      0,             //stx_delta_duty_cycle
      {160,128},     //tx_rc_lpf
      21,            //tx_rc_rcf
      {{0,0}},       //tx_iq_lin
      {{0,0}},       //tx_dc_lin
#ifndef TK6291_E1EVB
      {{0,0}},       //tx_iq_dpd
      {{0,0}},       //tx_dc_dpd
#endif
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_a
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //tx_dnl_pga_b
      { /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_1
      {    /*MMRFC_UMTS_TX_CBW_NUM = 2*/
        {  /* MMRFC_TX_PGA_SLICE_NUM+1 = 8 */
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
           UMTS_TX_FD_Iq_5Tap_Comp_Default,
        },
        {
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
           UMTS_TX_FD_Iq_7Tap_Comp_Default,
        },
      }, //tx_fdiq_lin_2
      {
        /*tx_ga_w_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      }, 
      {
        /*tx_ga_wo_ET*/
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
        {
           UMTS_TX_GA_5tap_Comp_Default,
           UMTS_TX_GA_7tap_Comp_Default,
        },
      },
      UMTS_TX_PGA_PHASE_Default,
      UMTS_TX_PGA_AB_Default, //pga_gain_step : MMRFC_TX_PGA_GAIN_STEP_SUBBAND_NUM * MMRFC_TX_PGA_GAIN_STEP_NUM
      9, //cap_tuning_pga_a
      10, //cap_tuning_pga_b
    },
};


UMTS_FE_ROUTE_TABLE_T UMTS_FE_ROUTE_TBL[UMTS_RF_FRONT_END_NUM_MAX] =
{
   /* Single Band FE Route Table */
   UMTS_SB_FE_SETTING(RX_BAND_INDICATOR_0, SetDefault),
   UMTS_SB_FE_SETTING(RX_BAND_INDICATOR_1, SetDefault),
   UMTS_SB_FE_SETTING(RX_BAND_INDICATOR_2, SetDefault),
   UMTS_SB_FE_SETTING(RX_BAND_INDICATOR_3, SetDefault),
   UMTS_SB_FE_SETTING(RX_BAND_INDICATOR_4, SetDefault),

   /* CA Band FE Route Table*/
   UMTS_CA_FE_SETTING(RX_CABAND_IND_00, SetDefault),
   UMTS_CA_FE_SETTING(RX_CABAND_IND_01, SetDefault),
   UMTS_CA_FE_SETTING(RX_CABAND_IND_02, SetDefault),
   UMTS_CA_FE_SETTING(RX_CABAND_IND_03, SetDefault),
   UMTS_CA_FE_SETTING(RX_CABAND_IND_04, SetDefault)};

UMTS_FE_USAGE_T  UMTS_FE_USAGE_TBL[UMTS_RF_FRONT_END_NUM_MAX] = 
{
   {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
   {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
   {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
   {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
   {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
   {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
   {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
   {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
   {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}},
   {{0,{0,0}},{{0,0},{0}},{{0,0},{0}},{{0,0},{0}}}
};

/* P-core Table ============================================================================= */
UMTS_RX_PDATABASE_T UMTS_RX_PDATABASE[UMTS_FE_RXBASE_TBL_SIZE_MAX] = 
{
   M_UMTS_RF_RX_PDATABASE(RX_BAND_INDICATOR_0), 
   M_UMTS_RF_RX_PDATABASE(RX_BAND_INDICATOR_1),
   M_UMTS_RF_RX_PDATABASE(RX_BAND_INDICATOR_2),
   M_UMTS_RF_RX_PDATABASE(RX_BAND_INDICATOR_3),
   M_UMTS_RF_RX_PDATABASE(RX_BAND_INDICATOR_4),
   M_UMTS_RF_RX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_RX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_RX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_RX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_RX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_RX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_RX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_RX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_RX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_RX_PDATABASE(UMTSBandNone),
};

UMTS_TX_PDATABASE_T UMTS_TX_PDATABASE[UMTS_FE_TXBASE_TBL_SIZE_MAX] = 
{
   M_UMTS_RF_TX_PDATABASE(RX_BAND_INDICATOR_0), 
   M_UMTS_RF_TX_PDATABASE(RX_BAND_INDICATOR_1),
   M_UMTS_RF_TX_PDATABASE(RX_BAND_INDICATOR_2),
   M_UMTS_RF_TX_PDATABASE(RX_BAND_INDICATOR_3),
   M_UMTS_RF_TX_PDATABASE(RX_BAND_INDICATOR_4),
   M_UMTS_RF_TX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_TX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_TX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_TX_PDATABASE(UMTSBandNone),
   M_UMTS_RF_TX_PDATABASE(UMTSBandNone),
};

UMTS_RXIOBASE_T UMTS_RF_RXIOBASE[UMTS_FE_RXBASE_TBL_SIZE_MAX] =
{
   M_UMTS_RF_RXIOBASE(RX_BAND_INDICATOR_0 ),
   M_UMTS_RF_RXIOBASE(RX_BAND_INDICATOR_1 ),
   M_UMTS_RF_RXIOBASE(RX_BAND_INDICATOR_2 ),
   M_UMTS_RF_RXIOBASE(RX_BAND_INDICATOR_3 ),
   M_UMTS_RF_RXIOBASE(RX_BAND_INDICATOR_4 ),
   M_UMTS_RF_RXIOBASE(UMTSBandNone),
   M_UMTS_RF_RXIOBASE(UMTSBandNone),
   M_UMTS_RF_RXIOBASE(UMTSBandNone),
   M_UMTS_RF_RXIOBASE(UMTSBandNone),
   M_UMTS_RF_RXIOBASE(UMTSBandNone),
   M_UMTS_RF_RXIOBASE(UMTSBandNone),
   M_UMTS_RF_RXIOBASE(UMTSBandNone),
   M_UMTS_RF_RXIOBASE(UMTSBandNone),
   M_UMTS_RF_RXIOBASE(UMTSBandNone),
   M_UMTS_RF_RXIOBASE(UMTSBandNone),
};

UMTS_TXIOBASE_T UMTS_RF_TXIOBASE[UMTS_FE_TXBASE_TBL_SIZE_MAX] = 
{
   M_UMTS_RF_TXIOBASE(RX_BAND_INDICATOR_0 ),
   M_UMTS_RF_TXIOBASE(RX_BAND_INDICATOR_1 ),
   M_UMTS_RF_TXIOBASE(RX_BAND_INDICATOR_2 ),
   M_UMTS_RF_TXIOBASE(RX_BAND_INDICATOR_3 ),
   M_UMTS_RF_TXIOBASE(RX_BAND_INDICATOR_4 ),
   M_UMTS_RF_TXIOBASE(UMTSBandNone ),
   M_UMTS_RF_TXIOBASE(UMTSBandNone ),
   M_UMTS_RF_TXIOBASE(UMTSBandNone ),
   M_UMTS_RF_TXIOBASE(UMTSBandNone ),
   M_UMTS_RF_TXIOBASE(UMTSBandNone ),
};

const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T* UMTS_PWRON_CAL_DATA_PTR[UL1D_RF_CUSTOM_BAND] =
{
   &UMTS_PWRON_CAL_DATA(UMTSBandNone) ,
   &UMTS_PWRON_CAL_DATA(RX_BAND_INDICATOR_0) ,
   &UMTS_PWRON_CAL_DATA(RX_BAND_INDICATOR_1) ,
   &UMTS_PWRON_CAL_DATA(RX_BAND_INDICATOR_2) ,
   &UMTS_PWRON_CAL_DATA(RX_BAND_INDICATOR_3) ,
   &UMTS_PWRON_CAL_DATA(RX_BAND_INDICATOR_4) ,
};

#if UL1CUSTOM_DRDI_ENABLE
   kal_bool isWcdmaDrdiEnable = KAL_TRUE;
#else
   kal_bool isWcdmaDrdiEnable = KAL_FALSE;
#endif
