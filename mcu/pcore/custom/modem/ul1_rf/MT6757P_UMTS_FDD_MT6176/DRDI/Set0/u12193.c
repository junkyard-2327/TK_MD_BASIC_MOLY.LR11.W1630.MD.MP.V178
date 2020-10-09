/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	u12193.c
 *
 * Project:
 * --------
 *   MT6169+6290
 *
 * Description:
 * ------------
 *   MT6169_6290 Power Ramp Table
 *
 * Author:
 * -------
 *	
 *
 *******************************************************************************/
#if !defined(MT6176_RF)
   #error "rf files mismatch with compile option!"
#endif

/*===============================================================================================*/
#include "kal_public_api.h"
#include "ul1d_rf_public.h"
#include "ul1d_custom_rf.h"

#if defined(L1_SIM)
#include "SymWrap.h"
#endif

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBandNone_Set0 =
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand1_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  10562,  U_GAINLOSS( -4.500 ), U_GAINLOSS( -4.750 ), U_GAINLOSS( -4.500 ), U_GAINLOSS( 0.000 ) },
      {  10631,  U_GAINLOSS( -4.000 ), U_GAINLOSS( -4.000 ), U_GAINLOSS( -4.750 ), U_GAINLOSS( 0.000 ) },
      {  10700,  U_GAINLOSS( -4.250 ), U_GAINLOSS( -4.500 ), U_GAINLOSS( -4.000 ), U_GAINLOSS( 0.000 ) },
      {  10769,  U_GAINLOSS( -4.000 ), U_GAINLOSS( -4.750 ), U_GAINLOSS( -4.500 ), U_GAINLOSS( 0.000 ) },
      {  10838,  U_GAINLOSS( -4.000 ), U_GAINLOSS( -4.000 ), U_GAINLOSS( -4.750 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand2_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {   9662,  U_GAINLOSS( -4.000 ), U_GAINLOSS( -4.250 ), U_GAINLOSS( -4.000 ), U_GAINLOSS( 0.000 ) },
      {   9700,  U_GAINLOSS( -4.250 ), U_GAINLOSS( -4.250 ), U_GAINLOSS( -4.500 ), U_GAINLOSS( 0.000 ) },
      {   9800,  U_GAINLOSS( -4.500 ), U_GAINLOSS( -4.500 ), U_GAINLOSS( -4.250 ), U_GAINLOSS( 0.000 ) },
      {   9869,  U_GAINLOSS( -4.250 ), U_GAINLOSS( -4.000 ), U_GAINLOSS( -4.500 ), U_GAINLOSS( 0.000 ) },
      {   9938,  U_GAINLOSS( -4.250 ), U_GAINLOSS( -4.500 ), U_GAINLOSS( -4.250 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand3_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  1162,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1187,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1212,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1237,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1262,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1287,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1312,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1338,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1363,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1388,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1413,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1438,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1463,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1488,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1513,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand4_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {   1537,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1552,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1567,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1582,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1597,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1612,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1627,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1642,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1657,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1675,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1687,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1702,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1717,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1732,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand5_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {   4357,  U_GAINLOSS( -5.000 ), U_GAINLOSS( -5.750 ), U_GAINLOSS( -5.250 ), U_GAINLOSS( 0.000 ) },
      {   4382,  U_GAINLOSS( -5.500 ), U_GAINLOSS( -5.750 ), U_GAINLOSS( -5.000 ), U_GAINLOSS( 0.000 ) },
      {   4408,  U_GAINLOSS( -5.000 ), U_GAINLOSS( -5.250 ), U_GAINLOSS( -5.750 ), U_GAINLOSS( 0.000 ) },
      {   4433,  U_GAINLOSS( -5.000 ), U_GAINLOSS( -5.500 ), U_GAINLOSS( -5.250 ), U_GAINLOSS( 0.000 ) },
      {   4458,  U_GAINLOSS( -5.250 ), U_GAINLOSS( -5.750 ), U_GAINLOSS( -5.250 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand6_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  4387,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  4394,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  4400,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  4406,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  4413,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand7_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  2237,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  2318,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  2400,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  2482,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  2563,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};


const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand8_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {   2937,  U_GAINLOSS( -5.250 ), U_GAINLOSS( -5.250 ), U_GAINLOSS( -5.000 ), U_GAINLOSS( 0.000 ) },
      {   2975,  U_GAINLOSS( -5.250 ), U_GAINLOSS( -5.500 ), U_GAINLOSS( -5.000 ), U_GAINLOSS( 0.000 ) },
      {   3013,  U_GAINLOSS( -5.750 ), U_GAINLOSS( -5.500 ), U_GAINLOSS( -5.750 ), U_GAINLOSS( 0.000 ) },
      {   3051,  U_GAINLOSS( -5.750 ), U_GAINLOSS( -5.500 ), U_GAINLOSS( -5.000 ), U_GAINLOSS( 0.000 ) },
      {   3088,  U_GAINLOSS( -5.500 ), U_GAINLOSS( -5.500 ), U_GAINLOSS( -5.500 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand9_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  9237,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9248,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9259,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9270,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9281,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9292,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9303,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9312,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9323,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9334,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9345,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9356,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9367,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9378,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9387,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand10_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  3113,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3133,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3153,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3173,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3193,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3213,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3233,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3250,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3270,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3290,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3310,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3330,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3350,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3370,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3387,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand11_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  3712,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3717,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3722,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3728,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3733,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3738,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3742,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3748,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3753,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3758,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3764,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3769,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3775,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3781,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3787,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTSBand19_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  712,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  725,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  738,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  750,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  763,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route5_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route6_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route7_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route8_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route9_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route10_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route11_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route12_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route13_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route14_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route15_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route16_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route17_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route18_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route19_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route20_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route21_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route22_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route23_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_UMTS_Route24_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};


const U_sTEMPAGCOFFSET*  U_AGC_PATHLOSS_TABLE_Set0[] =
{
   M_UMTS_RX_AGC_PATHLOSS(UMTSBandNone, Set0),         /*BandNone*/
   M_UMTS_RX_AGC_PATHLOSS(RX_BAND_INDICATOR_0_Set0, Set0),  /*UMTS_Route0*/
   M_UMTS_RX_AGC_PATHLOSS(RX_BAND_INDICATOR_1_Set0, Set0),  /*UMTS_Route1*/
   M_UMTS_RX_AGC_PATHLOSS(RX_BAND_INDICATOR_2_Set0, Set0),  /*UMTS_Route2*/
   M_UMTS_RX_AGC_PATHLOSS(RX_BAND_INDICATOR_3_Set0, Set0),  /*UMTS_Route3*/
   M_UMTS_RX_AGC_PATHLOSS(RX_BAND_INDICATOR_4_Set0, Set0),  /*UMTS_Route4*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route5, Set0),          /*UMTS_Route5*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route6, Set0),          /*UMTS_Route6*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route7, Set0),          /*UMTS_Route7*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route8, Set0),          /*UMTS_Route8*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route9, Set0),          /*UMTS_Route9*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route10, Set0),         /*UMTS_Route10*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route11, Set0),         /*UMTS_Route11*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route12, Set0),         /*UMTS_Route12*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route13, Set0),         /*UMTS_Route13*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route14, Set0),         /*UMTS_Route14*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route15, Set0),         /*UMTS_Route15*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route16, Set0),         /*UMTS_Route16*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route17, Set0),         /*UMTS_Route17*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route18, Set0),         /*UMTS_Route18*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route19, Set0),         /*UMTS_Route19*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route20, Set0),         /*UMTS_Route20*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route21, Set0),         /*UMTS_Route21*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route22, Set0),         /*UMTS_Route22*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route23, Set0),         /*UMTS_Route23*/
   M_UMTS_RX_AGC_PATHLOSS(UMTS_Route24, Set0)          /*UMTS_Route24*/
};

//temperature dac
#if defined(__L1_TEMPERATURE_RANGE_V2__) 
/*From RIO5 proto 3 measured by SA/Tim*/
const kal_uint16 U_TEMP_DAC_Set0[CAL_TEMP_SECTION] =
{
   320, 362, 411, 457, 522, 570, 631, 664
};
#else
const kal_uint16 U_TEMP_DAC_Set0[CAL_TEMP_SECTION] =
{
   321, 367, 412, 457, 487, 517, 531, 543
};
#endif

/*------------------------------*/
/* RX Diversity Path loss table */
/*------------------------------*/
const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBandNone_Set0 =
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand1_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  10562,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  10631,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  10700,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  10769,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  10838,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand2_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {   9662,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   9700,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   9800,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   9869,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   9938,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand3_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  1162,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1187,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1212,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1237,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1262,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1287,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1312,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1338,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1363,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1388,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1413,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1438,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1463,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1488,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  1513,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand4_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {   1537,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1552,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1567,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1582,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1597,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1612,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1627,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1642,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1657,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1675,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1687,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1702,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1717,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   1732,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand5_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {   4357,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   4382,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   4408,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   4433,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   4458,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand6_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  4387,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  4394,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  4400,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  4406,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  4413,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand7_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  2237,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  2318,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  2400,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  2482,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  2563,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand8_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {   2937,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   2975,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   3013,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   3051,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {   3088,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand9_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  9237,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9248,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9259,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9270,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9281,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9292,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9303,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9312,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9323,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9334,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9345,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9356,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9367,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9378,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  9387,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand10_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  3113,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3133,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3153,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3173,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3193,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3213,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3233,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3250,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3270,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3290,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3310,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3330,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3350,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3370,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3387,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand11_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  3712,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3717,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3722,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3728,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3733,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3738,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3742,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3748,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3753,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3758,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3764,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3769,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3775,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3781,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  3787,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTSBand19_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  712,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  725,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  738,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  750,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  763,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route5_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route6_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route7_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route8_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route9_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route10_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route11_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route12_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route13_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route14_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route15_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route16_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route17_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route18_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route19_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route20_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route21_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route22_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route23_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET AGC_PATHLOSS_RXD_UMTS_Route24_Set0 = 
{
   //8 temperature section compensated offset
   {0, 0, 0, 0, 0, 0, 0, 0},

   {//  uarfcn,       LNA_High_loss,     LNA_Middle_loss,       LNA_Low_loss,       LNA_LPM_offset
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  0,  U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ), U_GAINLOSS( 0.000 ) },
      {  UMTS_TABLE_END }// Use this value at the end of the table. Max. to 15 path loss elements
   }
};

const U_sTEMPAGCOFFSET*  U_AGC_PATHLOSS_RXD_TABLE_Set0[] =
{
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTSBandNone,Set0),         /*BandNone*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(RX_BAND_INDICATOR_0_Set0,Set0),  /*UMTS_Route0*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(RX_BAND_INDICATOR_1_Set0,Set0),  /*UMTS_Route1*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(RX_BAND_INDICATOR_2_Set0,Set0),  /*UMTS_Route2*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(RX_BAND_INDICATOR_3_Set0,Set0),  /*UMTS_Route3*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(RX_BAND_INDICATOR_4_Set0,Set0),  /*UMTS_Route4*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route5,Set0),          /*UMTS_Route5*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route6,Set0),          /*UMTS_Route6*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route7,Set0),          /*UMTS_Route7*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route8,Set0),          /*UMTS_Route8*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route9,Set0),          /*UMTS_Route9*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route10,Set0),         /*UMTS_Route10*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route11,Set0),         /*UMTS_Route11*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route12,Set0),         /*UMTS_Route12*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route13,Set0),         /*UMTS_Route13*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route14,Set0),         /*UMTS_Route14*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route15,Set0),         /*UMTS_Route15*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route16,Set0),         /*UMTS_Route16*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route17,Set0),         /*UMTS_Route17*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route18,Set0),         /*UMTS_Route18*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route19,Set0),         /*UMTS_Route19*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route20,Set0),         /*UMTS_Route20*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route21,Set0),         /*UMTS_Route21*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route22,Set0),         /*UMTS_Route22*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route23,Set0),         /*UMTS_Route23*/
   M_UMTS_RX_AGC_PATHLOSS_RXD(UMTS_Route24,Set0),         /*UMTS_Route24*/
};

/* BAND ANY...................................................................*/
const U_sRAMPDATA  RampData_UMTSBandNone_Set0 =
{
   /* DC2DC data by BAND */
   { 2, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  296,  198 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    0x0000    ,     5      ,     0     },
            {    0x0000    ,     1      ,     0     },
            {    0x0000    ,    -2      ,     0     },
            {    0x0000    ,    -2      ,     0     },
            {    0x0000    ,    -1      ,     0     },
            {    0x0000    ,     0      ,     0     },
            {    0x0000    ,    -2      ,     0     },
            {    0x0000    ,     0      ,     0     },
            {    0x0000    ,     3      ,     0     },
            {    0x0000    ,     7      ,     0     },
            {    0x0000    ,    12      ,     0     },
            {    0x0000    ,    20      ,     0     },
            {    0x0000    ,    25      ,     0     },
            {    0x0000    ,    33      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 550, 1, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  238,   198 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    0x0000    ,     5      ,     0     },
            {    0x0000    ,     1      ,     0     },
            {    0x0000    ,    -2      ,     0     },
            {    0x0000    ,    -2      ,     0     },
            {    0x0000    ,    -1      ,     0     },
            {    0x0000    ,     0      ,     0     },
            {    0x0000    ,    -2      ,     0     },
            {    0x0000    ,     0      ,     0     },
            {    0x0000    ,     3      ,     0     },
            {    0x0000    ,     6      ,     0     },
            {    0x0000    ,    11      ,     0     },
            {    0x0000    ,    19      ,     0     },
            {    0x0000    ,    25      ,     0     },
            {    0x0000    ,    32      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 490, 1, 1},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  161,   198 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    0x0000    ,     2      ,     0     },
            {    0x0000    ,    -1      ,     0     },
            {    0x0000    ,    -3      ,     0     },
            {    0x0000    ,    -4      ,     0     },
            {    0x0000    ,    -3      ,     0     },
            {    0x0000    ,     0      ,     0     },
            {    0x0000    ,    -3      ,     0     },
            {    0x0000    ,     0      ,     0     },
            {    0x0000    ,     3      ,     0     },
            {    0x0000    ,     6      ,     0     },
            {    0x0000    ,    11      ,     0     },
            {    0x0000    ,    19      ,     0     },
            {    0x0000    ,    25      ,     0     },
            {    0x0000    ,    33      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      }     
   },
   
   /* hysteresis start and end idx */
   {
     { 10, 14 },   
     { 20, 24 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
     32,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_offset_db */
        {    0x0000    ,    10      ,     0     },
        {    0x0000    ,    14      ,     0     },
        {    0x0000    ,    17      ,     0     },
        {    0x0000    ,    13      ,     0     },
        {    0x0000    ,    11      ,     0     },
        {    0x0000    ,     8      ,     0     },
        {    0x0000    ,     6      ,     0     },
        {    0x0000    ,     0      ,     0     },
        {    0x0000    ,    -2      ,     0     },
        {    0x0000    ,    -3      ,     0     },
        {    0x0000    ,    -7      ,     0     },
        {    0x0000    ,    -14     ,     0     },
        {    0x0000    ,    -18     ,     0     },
        {    0x0000    ,    -15     ,     0     },
        { UMTS_TABLE_END }
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND1...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand1_Set0 = 
{
   /* DC2DC data by BAND */
   { 2, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  296,  233 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    9612    ,   -14      ,     0     },
            {    9634    ,   -15      ,     0     },
            {    9656    ,   -18      ,     0     },
            {    9678    ,   -16      ,     0     },
            {    9700    ,   -12      ,     0     },
            {    9722    ,    -7      ,     0     },
            {    9750    ,     0      ,     0     },
            {    9766    ,     5      ,     0     },
            {    9788    ,     8      ,     0     },
            {    9810    ,     7      ,     0     },
            {    9832    ,     5      ,     0     },
            {    9854    ,     2      ,     0     },
            {    9876    ,     3      ,     0     },
            {    9888    ,     7      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { -12, 0 },
           { -12, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -18, 0 },
           { -18, 0 },
           { -18, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 550, 1, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  238,   233 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    9612    ,   -14      ,     0     },
            {    9634    ,   -17      ,     0     },
            {    9656    ,   -20      ,     0     },
            {    9678    ,   -21      ,     0     },
            {    9700    ,   -19      ,     0     },
            {    9722    ,   -13      ,     0     },
            {    9750    ,     0      ,     0     },
            {    9766    ,     5      ,     0     },
            {    9788    ,    11      ,     0     },
            {    9810    ,    10      ,     0     },
            {    9832    ,     9      ,     0     },
            {    9854    ,     1      ,     0     },
            {    9876    ,    -5      ,     0     },
            {    9888    ,    -6      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { -12, 0 },
           { -12, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -18, 0 },
           { -18, 0 },
           { -18, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 490, 1, 1},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  161,   233 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    9612    ,    -9      ,     0     },
            {    9634    ,   -10      ,     0     },
            {    9656    ,   -13      ,     0     },
            {    9678    ,   -13      ,     0     },
            {    9700    ,   -12      ,     0     },
            {    9722    ,    -8      ,     0     },
            {    9750    ,     0      ,     0     },
            {    9766    ,     4      ,     0     },
            {    9788    ,     9      ,     0     },
            {    9810    ,     6      ,     0     },
            {    9832    ,     5      ,     0     },
            {    9854    ,     2      ,     0     },
            {    9876    ,     0      ,     0     },
            {    9888    ,     3      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { -12, 0 },
           { -12, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -18, 0 },
           { -18, 0 },
           { -18, 0 },
         }
      }     
   },
   
   /* hysteresis start and end idx */
   {
     { 13, 13 },   
     { 22, 22 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
     32,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_offset_db */
        {    9612    ,     0      ,     0     },
        {    9634    ,     0      ,     0     },
        {    9656    ,    -1      ,     0     },
        {    9678    ,    -2      ,     0     },
        {    9700    ,    -1      ,     0     },
        {    9722    ,    -3      ,     0     },
        {    9750    ,     0      ,     0     },
        {    9766    ,    -4      ,     0     },
        {    9788    ,    -6      ,     0     },
        {    9810    ,    -6      ,     0     },
        {    9832    ,    -7      ,     0     },
        {    9854    ,    -7      ,     0     },
        {    9876    ,    -8     ,     0     },
        {    9888    ,    -8     ,     0     },
        { UMTS_TABLE_END }
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND2...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand2_Set0 = 
{
   /* DC2DC data by BAND */
   { 2, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  296,  233 },
              
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    9262    ,     4      ,     0     },
            {    9284    ,     7      ,     0     },
            {    9306    ,     5      ,     0     },
            {    9328    ,     5      ,     0     },
            {    9350    ,     7      ,     0     },
            {    9372    ,     5      ,     0     },
            {    9400    ,     0      ,     0     },
            {    9416    ,     0      ,     0     },
            {    9438    ,    -3      ,     0     },
            {    9460    ,    -1      ,     0     },
            {    9482    ,     8      ,     0     },
            {    9504    ,    19      ,     0     },
            {    9526    ,    34      ,     0     },
            {    9538    ,    41      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { -3, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -18, 0 },
           { -18, 0 },
           { -18, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 550, 1, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  238,   233 },
 
         /* VGA offset by subband */
         {
            /* max arfcn ,   pwr_offset_db */
            {    9262    ,     2      ,     0     },
            {    9284    ,     3      ,     0     },
            {    9306    ,     1      ,     0     },
            {    9328    ,     2      ,     0     },
            {    9350    ,     4      ,     0     },
            {    9372    ,     2      ,     0     },
            {    9400    ,     0      ,     0     },
            {    9416    ,    -4      ,     0     },
            {    9438    ,   -11      ,     0     },
            {    9460    ,   -12      ,     0     },
            {    9482    ,   -10      ,     0     },
            {    9504    ,     0      ,     0     },
            {    9526    ,    20      ,     0     },
            {    9538    ,    30      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { -3, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -18, 0 },
           { -18, 0 },
           { -18, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 490, 1, 1},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  161,   233 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    9262    ,     7      ,     0     },
            {    9284    ,     8      ,     0     },
            {    9306    ,     6      ,     0     },
            {    9328    ,     6      ,     0     },
            {    9350    ,     7      ,     0     },
            {    9372    ,     4      ,     0     },
            {    9400    ,     0      ,     0     },
            {    9416    ,     0      ,     0     },
            {    9438    ,    -3      ,     0     },
            {    9460    ,    -1      ,     0     },
            {    9482    ,     4      ,     0     },
            {    9504    ,    15      ,     0     },
            {    9526    ,    31      ,     0     },
            {    9538    ,    39      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { -3, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -18, 0 },
           { -18, 0 },
           { -18, 0 },
         }
      }     
   },
   /*-------------------------------------------------------------------------------------------*/
   /* hysteresis start and end idx */
   {
     { 12, 12 },   
     { 24, 24 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
     32,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn ,   pwr_offset_db */
        {    9262    ,     4      ,     0     },
        {    9284    ,     4      ,     0     },
        {    9306    ,     5      ,     0     },
        {    9328    ,     3      ,     0     },
        {    9350    ,     6      ,     0     },
        {    9372    ,     4      ,     0     },
        {    9400    ,     0      ,     0     },
        {    9416    ,     1      ,     0     },
        {    9438    ,     1      ,     0     },
        {    9460    ,     0      ,     0     },
        {    9482    ,    -1      ,     0     },
        {    9504    ,    -3      ,     0     },
        {    9526    ,     0      ,     0     },
        {    9538    ,     1      ,     0     },
        { UMTS_TABLE_END }
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND3...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand3_Set0 = 
{
   /* DC2DC data by BAND */
   { 7, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  225,   176 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    937     ,     0      ,     0     },
            {    962     ,     0      ,     0     },
            {    987     ,     0      ,     0     },
            {    1012    ,     0      ,     0     },
            {    1037    ,     0      ,     0     },
            {    1062    ,     0      ,     0     },
            {    1087    ,     0      ,     0     },
            {    1113    ,     0      ,     0     },
            {    1138    ,     0      ,     0     },
            {    1163    ,     0      ,     0     },
            {    1188    ,     0      ,     0     },
            {    1213    ,     0      ,     0     },
            {    1238    ,     0      ,     0     },
            {    1263    ,     0      ,     0     },
            {    1288    ,     0      ,     0     },
         },      
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 580, 0, 0},
         /* VGA DAC of PA mid  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  191,   172 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    937     ,     0      ,     0     },
            {    962     ,     0      ,     0     },
            {    987     ,     0      ,     0     },
            {    1012    ,     0      ,     0     },
            {    1037    ,     0      ,     0     },
            {    1062    ,     0      ,     0     },
            {    1087    ,     0      ,     0     },
            {    1113    ,     0      ,     0     },
            {    1138    ,     0      ,     0     },
            {    1163    ,     0      ,     0     },
            {    1188    ,     0      ,     0     },
            {    1213    ,     0      ,     0     },
            {    1238    ,     0      ,     0     },
            {    1263    ,     0      ,     0     },
            {    1288    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 520, 0, 0},
         /* VGA DAC of PA low  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  144,   173 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    937     ,     0      ,     0     },
            {    962     ,     0      ,     0     },
            {    987     ,     0      ,     0     },
            {    1012    ,     0      ,     0     },
            {    1037    ,     0      ,     0     },
            {    1062    ,     0      ,     0     },
            {    1087    ,     0      ,     0     },
            {    1113    ,     0      ,     0     },
            {    1138    ,     0      ,     0     },
            {    1163    ,     0      ,     0     },
            {    1188    ,     0      ,     0     },
            {    1213    ,     0      ,     0     },
            {    1238    ,     0      ,     0     },
            {    1263    ,     0      ,     0     },
            {    1288    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      }     
   },
   
   /* hysteresis start and end idx */
   {
     { 10, 14 },   
     { 20, 24 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
     32,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_slope  , pwr_offset*/
        {    937     ,     0      ,     0     },
        {    962     ,     0      ,     0     },
        {    987     ,     0      ,     0     },
        {    1012    ,     0      ,     0     },
        {    1037    ,     0      ,     0     },
        {    1062    ,     0      ,     0     },
        {    1087    ,     0      ,     0     },
        {    1113    ,     0      ,     0     },
        {    1138    ,     0      ,     0     },
        {    1163    ,     0      ,     0     },
        {    1188    ,     0      ,     0     },
        {    1213    ,     0      ,     0     },
        {    1238    ,     0      ,     0     },
        {    1263    ,     0      ,     0     },
        {    1288    ,     0      ,     0     },
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND4...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand4_Set0 = 
{
   /* DC2DC data by BAND */
   { 7, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  246,   176 },
              
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    1312    ,     0      ,     0     },
            {    1327    ,     0      ,     0     },
            {    1342    ,     0      ,     0     },
            {    1357    ,     0      ,     0     },
            {    1372    ,     0      ,     0     },
            {    1387    ,     0      ,     0     },
            {    1402    ,     0      ,     0     },
            {    1417    ,     0      ,     0     },
            {    1432    ,     0      ,     0     },
            {    1450    ,     0      ,     0     },
            {    1465    ,     0      ,     0     },
            {    1480    ,     0      ,     0     },
            {    1495    ,     0      ,     0     },
            {    1510    ,     0      ,     0     },
            {    1513    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 580, 0, 0},
         /* VGA DAC of PA mid  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  212,   172 },
 
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    1312    ,     0      ,     0     },
            {    1327    ,     0      ,     0     },
            {    1342    ,     0      ,     0     },
            {    1357    ,     0      ,     0     },
            {    1372    ,     0      ,     0     },
            {    1387    ,     0      ,     0     },
            {    1402    ,     0      ,     0     },
            {    1417    ,     0      ,     0     },
            {    1432    ,     0      ,     0     },
            {    1450    ,     0      ,     0     },
            {    1465    ,     0      ,     0     },
            {    1480    ,     0      ,     0     },
            {    1495    ,     0      ,     0     },
            {    1510    ,     0      ,     0     },
            {    1513    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 520, 0, 0},
         /* VGA DAC of PA low  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  166,   173 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    1312    ,     0      ,     0     },
            {    1327    ,     0      ,     0     },
            {    1342    ,     0      ,     0     },
            {    1357    ,     0      ,     0     },
            {    1372    ,     0      ,     0     },
            {    1387    ,     0      ,     0     },
            {    1402    ,     0      ,     0     },
            {    1417    ,     0      ,     0     },
            {    1432    ,     0      ,     0     },
            {    1450    ,     0      ,     0     },
            {    1465    ,     0      ,     0     },
            {    1480    ,     0      ,     0     },
            {    1495    ,     0      ,     0     },
            {    1510    ,     0      ,     0     },
            {    1513    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      }     
   },
   /*-------------------------------------------------------------------------------------------*/
   /* hysteresis start and end idx */
   {
     { 10, 14 },   
     { 20, 24 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
     32,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_slope  , pwr_offset*/
        {    1312    ,     0      ,     0     },
        {    1327    ,     0      ,     0     },
        {    1342    ,     0      ,     0     },
        {    1357    ,     0      ,     0     },
        {    1372    ,     0      ,     0     },
        {    1387    ,     0      ,     0     },
        {    1402    ,     0      ,     0     },
        {    1417    ,     0      ,     0     },
        {    1432    ,     0      ,     0     },
        {    1450    ,     0      ,     0     },
        {    1465    ,     0      ,     0     },
        {    1480    ,     0      ,     0     },
        {    1495    ,     0      ,     0     },
        {    1510    ,     0      ,     0     },
        {    1513    ,     0      ,     0     },
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND5...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand5_Set0 = 
{
   /* DC2DC data by BAND */
   { 2, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  296,  264 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    4132    ,     11      ,     0     },
            {    4140    ,      0      ,     0     },
            {    4148    ,     -7      ,     0     },
            {    4156    ,     -9      ,     0     },
            {    4164    ,     -8      ,     0     },
            {    4172    ,     -4      ,     0     },
            {    4183    ,      0      ,     0     },
            {    4188    ,      1      ,     0     },
            {    4195    ,      5      ,     0     },
            {    4203    ,      7      ,     0     },
            {    4210    ,      5      ,     0     },
            {    4218    ,      1      ,     0     },
            {    4226    ,      1      ,     0     },
            {    4233    ,      2      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 12, 0 },
           { 12, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -12, 0 },
           { -12, 0 },
           { -12, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 550, 1, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  238,    264 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    4132    ,      8      ,     0     },
            {    4140    ,     -2      ,     0     },
            {    4148    ,     -9      ,     0     },
            {    4156    ,    -10      ,     0     },
            {    4164    ,    -10      ,     0     },
            {    4172    ,     -7      ,     0     },
            {    4183    ,      0      ,     0     },
            {    4188    ,      0      ,     0     },
            {    4195    ,      5      ,     0     },
            {    4203    ,      8      ,     0     },
            {    4210    ,      7      ,     0     },
            {    4218    ,      6      ,     0     },
            {    4226    ,      6      ,     0     },
            {    4233    ,      8      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 12, 0 },
           { 12, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -12, 0 },
           { -12, 0 },
           { -12, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 490, 1, 1},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  161,    264 },
         
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    4132    ,      2      ,     0     },
            {    4140    ,     -5      ,     0     },
            {    4148    ,     -9      ,     0     },
            {    4156    ,    -11      ,     0     },
            {    4164    ,    -11      ,     0     },
            {    4172    ,     -5      ,     0     },
            {    4183    ,      0      ,     0     },
            {    4188    ,      3      ,     0     },
            {    4195    ,      5      ,     0     },
            {    4203    ,      9      ,     0     },
            {    4210    ,      8      ,     0     },
            {    4218    ,      8      ,     0     },
            {    4226    ,      8      ,     0     },
            {    4233    ,      9      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 12, 0 },
           { 12, 0 },
           {  0, 0 },
           {  0, 0 },
           {  0, 0 },
           {-12, 0 },
           {-12, 0 },
           {-12, 0 },
         }
      }     
   },
   /*-------------------------------------------------------------------------------------------*/
   /* hysteresis start and end idx */
   {
     { 13, 13 },   
     { 22, 22 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
      0,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_offset_db */
        {    4132    ,      0      ,     0     },
        {    4140    ,      0      ,     0     },
        {    4148    ,     -1      ,     0     },
        {    4156    ,     -2      ,     0     },
        {    4164    ,      0      ,     0     },
        {    4172    ,      0      ,     0     },
        {    4183    ,      0      ,     0     },
        {    4188    ,      0      ,     0     },
        {    4195    ,     -1      ,     0     },
        {    4203    ,     -3      ,     0     },
        {    4210    ,     -1      ,     0     },
        {    4218    ,     -2      ,     0     },
        {    4226    ,     -3      ,     0     },
        {    4233    ,     -5      ,     0     },
        { UMTS_TABLE_END }
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND6...................................................................*/
/* Band6 is overlap with Band5 */
const U_sRAMPDATA  RampData_UMTSBand6_Set0 = 
{
   /* DC2DC data by BAND */
   { 0, 
     0 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 0, 0, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    4162    ,     0      ,     0     },
            {    4168    ,     0      ,     0     },
            {    4175    ,     0      ,     0     },
            {    4182    ,     0      ,     0     },
            {    4188    ,     0      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 0, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            /* max arfcn , pwr_offset */
            {    4162    ,     0      ,     0     },
            {    4168    ,     0      ,     0     },
            {    4175    ,     0      ,     0     },
            {    4182    ,     0      ,     0     },
            {    4188    ,     0      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 0, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
         
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            /* max arfcn , pwr_offset */
            {    4162    ,     0      ,     0     },
            {    4168    ,     0      ,     0     },
            {    4175    ,     0      ,     0     },
            {    4182    ,     0      ,     0     },
            {    4188    ,     0      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      }     
   },
   /*-------------------------------------------------------------------------------------------*/
   /* hysteresis start and end idx */
   {
     { 0, 0 },   
     { 0, 0 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     0, 
     /* pwr dt used section */ 
     0,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_slope  , pwr_offset*/
        {    4162    ,     0      ,     0     },
        {    4168    ,     0      ,     0     },
        {    4175    ,     0      ,     0     },
        {    4182    ,     0      ,     0     },
        {    4188    ,     0      ,     0     },
        { UMTS_TABLE_END }
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND7...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand7_Set0 = 
{
   /* DC2DC data by BAND */
   { 0, 
     0 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 0, 0, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset_db */
            {    2012    ,     0      ,     0     },
            {    2037    ,     0      ,     0     },
            {    2062    ,     0      ,     0     },
            {    2087    ,     0      ,     0     },
            {    2112    ,     0      ,     0     },
            {    2137    ,     0      ,     0     },
            {    2162    ,     0      ,     0     },
            {    2187    ,     0      ,     0     },
            {    2112    ,     0      ,     0     },
            {    2237    ,     0      ,     0     },
            {    2262    ,     0      ,     0     },
            {    2287    ,     0      ,     0     },
            {    2312    ,     0      ,     0     },
            {    2338    ,     0      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 0, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            /* max arfcn , pwr_offset */
            {    2012    ,     0      ,     0     },
            {    2037    ,     0      ,     0     },
            {    2062    ,     0      ,     0     },
            {    2087    ,     0      ,     0     },
            {    2112    ,     0      ,     0     },
            {    2137    ,     0      ,     0     },
            {    2162    ,     0      ,     0     },
            {    2187    ,     0      ,     0     },
            {    2112    ,     0      ,     0     },
            {    2237    ,     0      ,     0     },
            {    2262    ,     0      ,     0     },
            {    2287    ,     0      ,     0     },
            {    2312    ,     0      ,     0     },
            {    2338    ,     0      ,     0     },
            { UMTS_TABLE_END }

         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 0, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,    0,    0 },
         
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            /* max arfcn , pwr_offset */
            {    2012    ,     0      ,     0     },
            {    2037    ,     0      ,     0     },
            {    2062    ,     0      ,     0     },
            {    2087    ,     0      ,     0     },
            {    2112    ,     0      ,     0     },
            {    2137    ,     0      ,     0     },
            {    2162    ,     0      ,     0     },
            {    2187    ,     0      ,     0     },
            {    2112    ,     0      ,     0     },
            {    2237    ,     0      ,     0     },
            {    2262    ,     0      ,     0     },
            {    2287    ,     0      ,     0     },
            {    2312    ,     0      ,     0     },
            {    2338    ,     0      ,     0     },
            { UMTS_TABLE_END }

         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      }     
   },
   /*-------------------------------------------------------------------------------------------*/
   /* hysteresis start and end idx */
   {
     { 0, 0 },   
     { 0, 0 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     0, 
     /* pwr dt used section */ 
     0,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_slope  , pwr_offset*/
        {    2012    ,     0      ,     0     },
        {    2037    ,     0      ,     0     },
        {    2062    ,     0      ,     0     },
        {    2087    ,     0      ,     0     },
        {    2112    ,     0      ,     0     },
        {    2137    ,     0      ,     0     },
        {    2162    ,     0      ,     0     },
        {    2187    ,     0      ,     0     },
        {    2112    ,     0      ,     0     },
        {    2237    ,     0      ,     0     },
        {    2262    ,     0      ,     0     },
        {    2287    ,     0      ,     0     },
        {    2312    ,     0      ,     0     },
        {    2338    ,     0      ,     0     },
        { UMTS_TABLE_END }
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND8...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand8_Set0 = 
{
   /* DC2DC data by BAND */
   { 7, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  292,   264 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    2712    ,    14      ,     0     },
            {    2724    ,    18      ,     0     },
            {    2736    ,    19      ,     0     },
            {    2748    ,    16      ,     0     },
            {    2760    ,    10      ,     0     },
            {    2772    ,     6      ,     0     },
            {    2787    ,     0      ,     0     },
            {    2796    ,     0      ,     0     },
            {    2807    ,     2      ,     0     },
            {    2818    ,     7      ,     0     },
            {    2829    ,    14      ,     0     },
            {    2840    ,    18      ,     0     },
            {    2851    ,    23      ,     0     },
            {    2863    ,    31      ,     0     },
            { UMTS_TABLE_END }
         },      
         /* VGA comp by temperature */
         { { 12, 0 },
           { 12, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -12, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 550, 1, 0},
         /* VGA DAC of PA mid  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  238,   264 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    2712    ,    11      ,     0     },
            {    2724    ,    14      ,     0     },
            {    2736    ,    15      ,     0     },
            {    2748    ,    13      ,     0     },
            {    2760    ,     7      ,     0     },
            {    2772    ,     3      ,     0     },
            {    2787    ,     0      ,     0     },
            {    2796    ,    -2      ,     0     },
            {    2807    ,     0      ,     0     },
            {    2818    ,     5      ,     0     },
            {    2829    ,    11      ,     0     },
            {    2840    ,    16      ,     0     },
            {    2851    ,    22      ,     0     },
            {    2863    ,    30      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 12, 0 },
           { 12, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -12, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 490, 1, 1},
         /* VGA DAC of PA low  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  161,   264 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    2712    ,    10      ,     0     },
            {    2724    ,    11      ,     0     },
            {    2736    ,    11      ,     0     },
            {    2748    ,    10      ,     0     },
            {    2760    ,     6      ,     0     },
            {    2772    ,     3      ,     0     },
            {    2787    ,     0      ,     0     },
            {    2796    ,    -1      ,     0     },
            {    2807    ,     0      ,     0     },
            {    2818    ,     3      ,     0     },
            {    2829    ,    10      ,     0     },
            {    2840    ,    15      ,     0     },
            {    2851    ,    20      ,     0     },
            {    2863    ,    29      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 12, 0 },
           { 12, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { -12, 0 },
         }
      }     
   },
   
   /* hysteresis start and end idx */
   {
     { 13, 13 },   
     { 22, 22 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
     32,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_offset */
        {    2712    ,     3      ,     0     },
        {    2724    ,     3      ,     0     },
        {    2736    ,     3      ,     0     },
        {    2748    ,     3      ,     0     },
        {    2760    ,     2      ,     0     },
        {    2772    ,     3      ,     0     },
        {    2787    ,     0      ,     0     },
        {    2796    ,     3      ,     0     },
        {    2807    ,     3      ,     0     },
        {    2818    ,     3      ,     0     },
        {    2829    ,     4      ,     0     },
        {    2840    ,     3      ,     0     },
        {    2851    ,     4      ,     0     },
        {    2863    ,     3      ,     0     },
        { UMTS_TABLE_END }
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND9...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand9_Set0 = 
{
   /* DC2DC data by BAND */
   { 7, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  246,   176 },
              
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    8762    ,     0      ,     0     },
            {    8773    ,     0      ,     0     },
            {    8784    ,     0      ,     0     },
            {    8795    ,     0      ,     0     },
            {    8806    ,     0      ,     0     },
            {    8817    ,     0      ,     0     },
            {    8828    ,     0      ,     0     },
            {    8837    ,     0      ,     0     },
            {    8848    ,     0      ,     0     },
            {    8859    ,     0      ,     0     },
            {    8870    ,     0      ,     0     },
            {    8881    ,     0      ,     0     },
            {    8892    ,     0      ,     0     },
            {    8903    ,     0      ,     0     },
            {    8912    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 580, 0, 0},
         /* VGA DAC of PA mid  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  212,   172 },
 
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    8762    ,     0      ,     0     },
            {    8773    ,     0      ,     0     },
            {    8784    ,     0      ,     0     },
            {    8795    ,     0      ,     0     },
            {    8806    ,     0      ,     0     },
            {    8817    ,     0      ,     0     },
            {    8828    ,     0      ,     0     },
            {    8837    ,     0      ,     0     },
            {    8848    ,     0      ,     0     },
            {    8859    ,     0      ,     0     },
            {    8870    ,     0      ,     0     },
            {    8881    ,     0      ,     0     },
            {    8892    ,     0      ,     0     },
            {    8903    ,     0      ,     0     },
            {    8912    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 520, 0, 0},
         /* VGA DAC of PA low  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  166,   173 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    8762    ,     0      ,     0     },
            {    8773    ,     0      ,     0     },
            {    8784    ,     0      ,     0     },
            {    8795    ,     0      ,     0     },
            {    8806    ,     0      ,     0     },
            {    8817    ,     0      ,     0     },
            {    8828    ,     0      ,     0     },
            {    8837    ,     0      ,     0     },
            {    8848    ,     0      ,     0     },
            {    8859    ,     0      ,     0     },
            {    8870    ,     0      ,     0     },
            {    8881    ,     0      ,     0     },
            {    8892    ,     0      ,     0     },
            {    8903    ,     0      ,     0     },
            {    8912    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      }     
   },
   /*-------------------------------------------------------------------------------------------*/
   /* hysteresis start and end idx */
   {
     { 10, 14 },   
     { 20, 24 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
     32,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_offset */
        {    8762    ,     0      ,     0     },
        {    8773    ,     0      ,     0     },
        {    8784    ,     0      ,     0     },
        {    8795    ,     0      ,     0     },
        {    8806    ,     0      ,     0     },
        {    8817    ,     0      ,     0     },
        {    8828    ,     0      ,     0     },
        {    8837    ,     0      ,     0     },
        {    8848    ,     0      ,     0     },
        {    8859    ,     0      ,     0     },
        {    8870    ,     0      ,     0     },
        {    8881    ,     0      ,     0     },
        {    8892    ,     0      ,     0     },
        {    8903    ,     0      ,     0     },
        {    8912    ,     0      ,     0     },
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND10...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand10_Set0 = 
{
   /* DC2DC data by BAND */
   { 7, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  276,   176 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    2888    ,     0      ,     0     },
            {    2908    ,     0      ,     0     },
            {    2928    ,     0      ,     0     },
            {    2948    ,     0      ,     0     },
            {    2968    ,     0      ,     0     },
            {    2988    ,     0      ,     0     },
            {    3008    ,     0      ,     0     },
            {    3025    ,     0      ,     0     },
            {    3045    ,     0      ,     0     },
            {    3065    ,     0      ,     0     },
            {    3085    ,     0      ,     0     },
            {    3105    ,     0      ,     0     },
            {    3125    ,     0      ,     0     },
            {    3145    ,     0      ,     0     },
            {    3162    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 580, 0, 0},
         /* VGA DAC of PA mid  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  242,   172 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    2888    ,     0      ,     0     },
            {    2908    ,     0      ,     0     },
            {    2928    ,     0      ,     0     },
            {    2948    ,     0      ,     0     },
            {    2968    ,     0      ,     0     },
            {    2988    ,     0      ,     0     },
            {    3008    ,     0      ,     0     },
            {    3025    ,     0      ,     0     },
            {    3045    ,     0      ,     0     },
            {    3065    ,     0      ,     0     },
            {    3085    ,     0      ,     0     },
            {    3105    ,     0      ,     0     },
            {    3125    ,     0      ,     0     },
            {    3145    ,     0      ,     0     },
            {    3162    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 520, 0, 0},
         /* VGA DAC of PA low  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  183,   173 },
         
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    2888    ,     0      ,     0     },
            {    2908    ,     0      ,     0     },
            {    2928    ,     0      ,     0     },
            {    2948    ,     0      ,     0     },
            {    2968    ,     0      ,     0     },
            {    2988    ,     0      ,     0     },
            {    3008    ,     0      ,     0     },
            {    3025    ,     0      ,     0     },
            {    3045    ,     0      ,     0     },
            {    3065    ,     0      ,     0     },
            {    3085    ,     0      ,     0     },
            {    3105    ,     0      ,     0     },
            {    3125    ,     0      ,     0     },
            {    3145    ,     0      ,     0     },
            {    3162    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      }     
   },
   /*-------------------------------------------------------------------------------------------*/
   /* hysteresis start and end idx */
   {
     { 10, 14 },   
     { 20, 24 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
     32,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_slope  , pwr_offset*/
        {    2888    ,     0      ,     0     },
        {    2908    ,     0      ,     0     },
        {    2928    ,     0      ,     0     },
        {    2948    ,     0      ,     0     },
        {    2968    ,     0      ,     0     },
        {    2988    ,     0      ,     0     },
        {    3008    ,     0      ,     0     },
        {    3025    ,     0      ,     0     },
        {    3045    ,     0      ,     0     },
        {    3065    ,     0      ,     0     },
        {    3085    ,     0      ,     0     },
        {    3105    ,     0      ,     0     },
        {    3125    ,     0      ,     0     },
        {    3145    ,     0      ,     0     },
        {    3162    ,     0      ,     0     },
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND11...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand11_Set0 = 
{
   /* DC2DC data by BAND */
   { 7, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  276,   176 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    3487    ,     0      ,     0     },
            {    3493    ,     0      ,     0     },
            {    3498    ,     0      ,     0     },
            {    3504    ,     0      ,     0     },
            {    3510    ,     0      ,     0     },
            {    3515    ,     0      ,     0     },
            {    3520    ,     0      ,     0     },
            {    3526    ,     0      ,     0     },
            {    3531    ,     0      ,     0     },
            {    3536    ,     0      ,     0     },
            {    3541    ,     0      ,     0     },
            {    3547    ,     0      ,     0     },
            {    3552    ,     0      ,     0     },
            {    3557    ,     0      ,     0     },
            {    3562    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 580, 0, 0},
         /* VGA DAC of PA mid  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  242,   172 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    3487    ,     0      ,     0     },
            {    3493    ,     0      ,     0     },
            {    3498    ,     0      ,     0     },
            {    3504    ,     0      ,     0     },
            {    3510    ,     0      ,     0     },
            {    3515    ,     0      ,     0     },
            {    3520    ,     0      ,     0     },
            {    3526    ,     0      ,     0     },
            {    3531    ,     0      ,     0     },
            {    3536    ,     0      ,     0     },
            {    3541    ,     0      ,     0     },
            {    3547    ,     0      ,     0     },
            {    3552    ,     0      ,     0     },
            {    3557    ,     0      ,     0     },
            {    3562    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 520, 0, 0},
         /* VGA DAC of PA low  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  183,   173 },
         
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    3487    ,     0      ,     0     },
            {    3493    ,     0      ,     0     },
            {    3498    ,     0      ,     0     },
            {    3504    ,     0      ,     0     },
            {    3510    ,     0      ,     0     },
            {    3515    ,     0      ,     0     },
            {    3520    ,     0      ,     0     },
            {    3526    ,     0      ,     0     },
            {    3531    ,     0      ,     0     },
            {    3536    ,     0      ,     0     },
            {    3541    ,     0      ,     0     },
            {    3547    ,     0      ,     0     },
            {    3552    ,     0      ,     0     },
            {    3557    ,     0      ,     0     },
            {    3562    ,     0      ,     0     },
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      }     
   },
   /*-------------------------------------------------------------------------------------------*/
   /* hysteresis start and end idx */
   {
     { 10, 14 },   
     { 20, 24 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
     32,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_slope  , pwr_offset*/
        {    3487    ,     0      ,     0     },
        {    3493    ,     0      ,     0     },
        {    3498    ,     0      ,     0     },
        {    3504    ,     0      ,     0     },
        {    3510    ,     0      ,     0     },
        {    3515    ,     0      ,     0     },
        {    3520    ,     0      ,     0     },
        {    3526    ,     0      ,     0     },
        {    3531    ,     0      ,     0     },
        {    3536    ,     0      ,     0     },
        {    3541    ,     0      ,     0     },
        {    3547    ,     0      ,     0     },
        {    3552    ,     0      ,     0     },
        {    3557    ,     0      ,     0     },
        {    3562    ,     0      ,     0     },
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
   
};

/* BAND19...................................................................*/
const U_sRAMPDATA  RampData_UMTSBand19_Set0 = 
{
   /* DC2DC data by BAND */
   { 7, 
     31 
   },
   {
      /* PA high mode */
      {  
         /* PA DAC info */
         { 1, 660, 0, 0},
         /* VGA DAC of PA high  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  276,   176 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    312    ,     0      ,     0     },
            {    324    ,     0      ,     0     },
            {    337    ,     0      ,     0     },
            {    350    ,     0      ,     0     },
            {    363    ,     0      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA mid mode */
      {  
         /* PA DAC info */
         { 0, 580, 0, 0},
         /* VGA DAC of PA mid  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  242,   172 },

         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    312    ,     0      ,     0     },
            {    324    ,     0      ,     0     },
            {    337    ,     0      ,     0     },
            {    350    ,     0      ,     0     },
            {    363    ,     0      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      },
      
      /* PA low DAC */
      {  
         /* PA DAC info */
         { 0, 520, 0, 0},
         /* VGA DAC of PA low  */
         /* 32,   32,   31,   30,   29,   28,   27,   26,   25,   24 */
         {   0,    0,    0,    0,    0,    0,    0,    0,  183,   173 },
         
         /* VGA offset by subband */
         {
            /* max arfcn , pwr_offset */
            {    312    ,     0      ,     0     },
            {    324    ,     0      ,     0     },
            {    337    ,     0      ,     0     },
            {    350    ,     0      ,     0     },
            {    363    ,     0      ,     0     },
            { UMTS_TABLE_END }
         },
         /* VGA comp by temperature */
         { { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
           { 0, 0 },
         }
      }     
   },
   /*-------------------------------------------------------------------------------------------*/
   /* hysteresis start and end idx */
   {
     { 10, 14 },   
     { 20, 24 },
   },
   /*-------------------------------------------------------------------------------------------*/
   /* VGA comp by power detector */
   { 
     /* pwr dt start threshold: dBm */
     16, 
     /* pwr dt used section */ 
     32,
     /* pwr dt dac */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
     /* pwr dt value */
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },  
     /* pwr dt compensate by subband */
     {
        /* max arfcn , pwr_slope  , pwr_offset*/
        {    312    ,     0      ,     0     },
        {    324    ,     0      ,     0     },
        {    337    ,     0      ,     0     },
        {    350    ,     0      ,     0     },
        {    363    ,     0      ,     0     },
        { UMTS_TABLE_END }
     },
     /* pwr dt compensate by temperature */
     { { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
       { 0, 0 },
     }  
   },
};

const U_sRAMPDATA*  UMTS_RampData_Set0[] =
{
   M_UMTS_TX_RAMPDATA(UMTSBandNone,Set0),
   M_UMTS_TX_RAMPDATA(RX_BAND_INDICATOR_0_Set0,Set0),
   M_UMTS_TX_RAMPDATA(RX_BAND_INDICATOR_1_Set0,Set0),
   M_UMTS_TX_RAMPDATA(RX_BAND_INDICATOR_2_Set0,Set0),
   M_UMTS_TX_RAMPDATA(RX_BAND_INDICATOR_3_Set0,Set0),
   M_UMTS_TX_RAMPDATA(RX_BAND_INDICATOR_4_Set0,Set0)
};

/* PA 8-level control (for MT6276, MT6573) */
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBandNone_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          4, // DC2DC level
          1, // Vm0
          1, // Vm1
        490, // Vbias
        190 // PA gain
      },
      {
          1, // PA Mode
          6, // Prf
         14, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        296 // PA gain
      },
      {
          1, // PA Mode
         10, // Prf
         20, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        298 // PA gain
      },
      {
          0, // PA Mode
         15, // Prf
         32, // DC2DC level
          0, // Vm0
          0, // Vm1
        580, // Vbias
        642 // PA gain
      },
      {
          0, // PA Mode
         18, // Prf
         36, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        639 // PA gain
      },
      {
          0, // PA Mode
         20, // Prf
         46, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        648 // PA gain
      },
      {
          0, // PA Mode
         22, // Prf
         50, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        663 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         58, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        680 // PA gain
      },
   }
};

/* BAND1...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand1_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          2, // DC2DC level, 0.6V
          1, // Vm0
          1, // Vm1
        490, // Vbias
        715 // PA gain
      },
      {
          1, // PA Mode
          4, // Prf
         14, // DC2DC level, 1.2V
          1, // Vm0
          0, // Vm1
        580, // Vbias
        761 // PA gain
      },
      {
          1, // PA Mode
         10, // Prf
         16, // DC2DC level, 1.3V
          1, // Vm0
          0, // Vm1
        580, // Vbias
        813 // PA gain
      },
      {
          0, // PA Mode
         14, // Prf
         20, // DC2DC level, 1.5V
          0, // Vm0
          0, // Vm1
        580, // Vbias
        917 // PA gain
      },
      {
          0, // PA Mode
         16, // Prf
         32, // DC2DC level, 2.1V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        915 // PA gain
      },
      {
          0, // PA Mode
         20, // Prf
         36, // DC2DC level, 2.3V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        918 // PA gain
      },
      {
          0, // PA Mode
         22, // Prf
         50, // DC2DC level, 3.0V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        926 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         56, // DC2DC level, 3.3V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        935 // PA gain
      },
   }
};

/* BAND2...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand2_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          2, // DC2DC level, 0.6V
          1, // Vm0
          1, // Vm1
        490, // Vbias
        676 // PA gain
      },
      {
          1, // PA Mode
          4, // Prf
         16, // DC2DC level, 1.3V
          1, // Vm0
          0, // Vm1
        580, // Vbias
        737 // PA gain
      },
      {
          1, // PA Mode
          9, // Prf
         20, // DC2DC level, 1.5V
          1, // Vm0
          0, // Vm1
        580, // Vbias
        779 // PA gain
      },
      {
          0, // PA Mode
         15, // Prf
         24, // DC2DC level, 1.7V
          0, // Vm0
          0, // Vm1
        580, // Vbias
        929 // PA gain
      },
      {
          0, // PA Mode
         18, // Prf
         36, // DC2DC level, 2.3V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        924 // PA gain
      },
      {
          0, // PA Mode
         20, // Prf
         36, // DC2DC level, 2.3V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        922 // PA gain
      },
      {
          0, // PA Mode
         22, // Prf
         50, // DC2DC level, 3.0V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        922 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         54, // DC2DC level, 3.2V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        937 // PA gain
      },
   }
};

/* BAND3...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand3_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          4, // DC2DC level
          1, // Vm0
          1, // Vm1
        490, // Vbias
        172 // PA gain
      },
      {
          2, // PA Mode
          4, // Prf
         14, // DC2DC level
          1, // Vm0
          1, // Vm1
        580, // Vbias
        227 // PA gain
      },
      {
          1, // PA Mode
          4, // Prf
         20, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        403 // PA gain
      },
      {
          1, // PA Mode
          8, // Prf
         32, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        407 // PA gain
      },
      {
          1, // PA Mode
         10, // Prf
         36, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        417 // PA gain
      },
      {
          1, // PA Mode
         12, // Prf
         46, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        418 // PA gain
      },
      {
          0, // PA Mode
         12, // Prf
         50, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        708 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         58, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        725 // PA gain
      },
   }
};

/* BAND4...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand4_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          4, // DC2DC level
          1, // Vm0
          1, // Vm1
        490, // Vbias
        625 // PA gain
      },
      {
          2, // PA Mode
          4, // Prf
          8, // DC2DC level
          1, // Vm0
          1, // Vm1
        580, // Vbias
        743 // PA gain
      },
      {
          1, // PA Mode
          4, // Prf
         14, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        837 // PA gain
      },
      {
          1, // PA Mode
          8, // Prf
         22, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        889 // PA gain
      },
      {
          1, // PA Mode
         10, // Prf
         30, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        924 // PA gain
      },
      {
          1, // PA Mode
         12, // Prf
         38, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        981 // PA gain
      },
      {
          0, // PA Mode
         12, // Prf
         50, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
       1004 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         54, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
       1027 // PA gain
      },
   }
};

/* BAND5...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand5_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          2, // DC2DC level, 0.6V
          1, // Vm0
          1, // Vm1
        490, // Vbias
        832 // PA gain
      },
      {
          1, // PA Mode
          5, // Prf
         10, // DC2DC level, 1V
          1, // Vm0
          0, // Vm1
        580, // Vbias
        925 // PA gain
      },
      {
          1, // PA Mode
         10, // Prf
         16, // DC2DC level, 1.3V
          1, // Vm0
          0, // Vm1
        580, // Vbias
        942// PA gain
      },
      {
          0, // PA Mode
         14, // Prf
         22, // DC2DC level, 1.6V
          0, // Vm0
          0, // Vm1
        580, // Vbias
        1133 // PA gain
      },
      {
          0, // PA Mode
         16, // Prf
         30, // DC2DC level, 2V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        1132 // PA gain
      },
      {
          0, // PA Mode
         20, // Prf
         38, // DC2DC level, 2.4V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        1093 // PA gain
      },
      {
          0, // PA Mode
         22, // Prf
         48, // DC2DC level, 2.9V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        1087 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         50, // DC2DC level, 3V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        1089 // PA gain
      },
   }
};

/* BAND6...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand6_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          4, // DC2DC level
          1, // Vm0
          1, // Vm1
        490, // Vbias
        296 // PA gain
      },
      {
          1, // PA Mode
          6, // Prf
         14, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        399 // PA gain
      },
      {
          1, // PA Mode
         11, // Prf
         20, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        407 // PA gain
      },
      {
          0, // PA Mode
         15, // Prf
         32, // DC2DC level
          0, // Vm0
          0, // Vm1
        580, // Vbias
        724 // PA gain
      },
      {
          0, // PA Mode
         18, // Prf
         36, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        727 // PA gain
      },
      {
          0, // PA Mode
         20, // Prf
         46, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        742 // PA gain
      },
      {
          0, // PA Mode
         22, // Prf
         50, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        759 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         58, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        774 // PA gain
      },
   }
};

/* BAND7...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand7_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          4, // DC2DC level
          1, // Vm0
          1, // Vm1
        490, // Vbias
        296 // PA gain
      },
      {
          1, // PA Mode
          6, // Prf
         14, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        399 // PA gain
      },
      {
          1, // PA Mode
         11, // Prf
         20, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        407 // PA gain
      },
      {
          0, // PA Mode
         15, // Prf
         32, // DC2DC level
          0, // Vm0
          0, // Vm1
        580, // Vbias
        724 // PA gain
      },
      {
          0, // PA Mode
         18, // Prf
         36, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        727 // PA gain
      },
      {
          0, // PA Mode
         20, // Prf
         46, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        742 // PA gain
      },
      {
          0, // PA Mode
         22, // Prf
         50, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        759 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         58, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        774 // PA gain
      },
   }
};

/* BAND8...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand8_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
         -1, // Prf
          2, // DC2DC level, 0.6V
          1, // Vm0
          1, // Vm1
        490, // Vbias
        866 // PA gain
      },
      {
          1, // PA Mode
          5, // Prf
         12, // DC2DC level, 1.1V
          1, // Vm0
          0, // Vm1
        580, // Vbias
        933 // PA gain
      },
      {
          1, // PA Mode
         10, // Prf
         20, // DC2DC level, 1.5V
          1, // Vm0
          0, // Vm1
        580, // Vbias
        978 // PA gain
      },
      {
          0, // PA Mode
         14, // Prf
         24, // DC2DC level, 1.7V
          0, // Vm0
          0, // Vm1
        580, // Vbias
        973 // PA gain
      },
      {
          0, // PA Mode
         16, // Prf
         30, // DC2DC level, 2V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        1041 // PA gain
      },
      {
          0, // PA Mode
         20, // Prf
         42, // DC2DC level, 2.6V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        1044 // PA gain
      },
      {
          0, // PA Mode
         22, // Prf
         46, // DC2DC level, 2.8V
          0, // Vm0
          0, // Vm1
        660, // Vbias
        1091 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         50, // DC2DC level, 3V
          0, // Vm0
          0, // Vm1
        660, // Vbias
       1093 // PA gain
      },
   }
};

/* BAND9...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand9_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          4, // DC2DC level
          1, // Vm0
          1, // Vm1
        490, // Vbias
        172 // PA gain
      },
      {
          2, // PA Mode
          4, // Prf
         14, // DC2DC level
          1, // Vm0
          1, // Vm1
        580, // Vbias
        227 // PA gain
      },
      {
          1, // PA Mode
          4, // Prf
         20, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        403 // PA gain
      },
      {
          1, // PA Mode
          8, // Prf
         32, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        407 // PA gain
      },
      {
          1, // PA Mode
         10, // Prf
         36, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        417 // PA gain
      },
      {
          1, // PA Mode
         12, // Prf
         46, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        418 // PA gain
      },
      {
          0, // PA Mode
         12, // Prf
         50, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        708 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         58, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        725 // PA gain
      },
   }
};

/* BAND10...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand10_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          4, // DC2DC level
          1, // Vm0
          1, // Vm1
        490, // Vbias
        172 // PA gain
      },
      {
          2, // PA Mode
          4, // Prf
         14, // DC2DC level
          1, // Vm0
          1, // Vm1
        580, // Vbias
        227 // PA gain
      },
      {
          1, // PA Mode
          4, // Prf
         20, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        403 // PA gain
      },
      {
          1, // PA Mode
          8, // Prf
         32, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        407 // PA gain
      },
      {
          1, // PA Mode
         10, // Prf
         36, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        417 // PA gain
      },
      {
          1, // PA Mode
         12, // Prf
         46, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        418 // PA gain
      },
      {
          0, // PA Mode
         12, // Prf
         50, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        708 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         58, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        725 // PA gain
      },
   }
};

/* BAND11...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand11_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          4, // DC2DC level
          1, // Vm0
          1, // Vm1
        490, // Vbias
        172 // PA gain
      },
      {
          2, // PA Mode
          4, // Prf
         14, // DC2DC level
          1, // Vm0
          1, // Vm1
        580, // Vbias
        227 // PA gain
      },
      {
          1, // PA Mode
          4, // Prf
         20, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        403 // PA gain
      },
      {
          1, // PA Mode
          8, // Prf
         32, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        407 // PA gain
      },
      {
          1, // PA Mode
         10, // Prf
         36, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        417 // PA gain
      },
      {
          1, // PA Mode
         12, // Prf
         46, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        418 // PA gain
      },
      {
          0, // PA Mode
         12, // Prf
         50, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        708 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         58, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        725 // PA gain
      },
   }
};

/* BAND19...................................................................*/
const U_sPAOCTLVLSETTING  PaOctLevData_UMTSBand19_Set0 =
{
   /* Available PA 8-level sections set by user */
     8
   ,
   /* Reserved byte */
     0
   ,
   /* PA phase compensation */
   {
     0x0,
     0x0,
     0x0
   },
   /* PMU OCT level control table */
   {
      {
          2, // PA Mode
          0, // Prf
          4, // DC2DC level
          1, // Vm0
          1, // Vm1
        490, // Vbias
        172 // PA gain
      },
      {
          2, // PA Mode
          4, // Prf
         14, // DC2DC level
          1, // Vm0
          1, // Vm1
        580, // Vbias
        227 // PA gain
      },
      {
          1, // PA Mode
          4, // Prf
         20, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        403 // PA gain
      },
      {
          1, // PA Mode
          8, // Prf
         32, // DC2DC level
          1, // Vm0
          0, // Vm1
        580, // Vbias
        407 // PA gain
      },
      {
          1, // PA Mode
         10, // Prf
         36, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        417 // PA gain
      },
      {
          1, // PA Mode
         12, // Prf
         46, // DC2DC level
          1, // Vm0
          0, // Vm1
        660, // Vbias
        418 // PA gain
      },
      {
          0, // PA Mode
         12, // Prf
         50, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        708 // PA gain
      },
      {
          0, // PA Mode
         24, // Prf
         58, // DC2DC level
          0, // Vm0
          0, // Vm1
        660, // Vbias
        725 // PA gain
      },
   }
};


/* PA 8-level control */
const U_sPAOCTLVLSETTING*  U_PA_OCTLEV_TABLE_Set0[] =
{
   M_UMTS_TX_PA_OCTLEV_DATA(UMTSBandNone,Set0),
   M_UMTS_TX_PA_OCTLEV_DATA(RX_BAND_INDICATOR_0_Set0,Set0),
   M_UMTS_TX_PA_OCTLEV_DATA(RX_BAND_INDICATOR_1_Set0,Set0),
   M_UMTS_TX_PA_OCTLEV_DATA(RX_BAND_INDICATOR_2_Set0,Set0),
   M_UMTS_TX_PA_OCTLEV_DATA(RX_BAND_INDICATOR_3_Set0,Set0),
   M_UMTS_TX_PA_OCTLEV_DATA(RX_BAND_INDICATOR_4_Set0,Set0)
};
/*===============================================================================================*/
const U_sPADRIFTSETTING  PaDriftCompData_UMTSBandNone_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand1_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand2_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand3_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand4_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand5_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand6_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand7_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand8_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand9_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand10_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand11_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};

const U_sPADRIFTSETTING  PaDriftCompData_UMTSBand19_Set0 =
{
   //pa_drift_comp_w_table
   {    /* (Slot0, Slot1) */
      {  0, 0 } , //  L=>M
      {  0, 0 } , //  L=>H
      {  0, 0 } , //  M=>L
      {  0, 0 } , //  M=>H
      {  0, 0 } , //  H=>L
      {  0, 0 } , //  H=>M
   },

   //pa_drift_comp_h_table
   {    /* (Slot00, Slot01, slot10, slot11) */
      {  0, 0, 0, 0 } , //  L=>M
      {  0, 0, 0, 0 } , //  L=>H
      {  0, 0, 0, 0 } , //  M=>L
      {  0, 0, 0, 0 } , //  M=>H
      {  0, 0, 0, 0 } , //  H=>L
      {  0, 0, 0, 0 } , //  H=>M
  }
};


const U_sPADRIFTSETTING*  U_PA_DRIFT_TABLE_Set0[] =
{
   M_UMTS_TX_PA_DRIFT_COMP_DATA(UMTSBandNone,Set0),
   M_UMTS_TX_PA_DRIFT_COMP_DATA(RX_BAND_INDICATOR_0_Set0,Set0),
   M_UMTS_TX_PA_DRIFT_COMP_DATA(RX_BAND_INDICATOR_1_Set0,Set0),
   M_UMTS_TX_PA_DRIFT_COMP_DATA(RX_BAND_INDICATOR_2_Set0,Set0),
   M_UMTS_TX_PA_DRIFT_COMP_DATA(RX_BAND_INDICATOR_3_Set0,Set0),
   M_UMTS_TX_PA_DRIFT_COMP_DATA(RX_BAND_INDICATOR_4_Set0,Set0)
};


const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBandNone_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand1_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand2_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand3_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand4_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand5_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand6_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand7_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand8_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand9_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand10_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand11_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};

const U_sPARACHTMCOMPDATA RACH_temperature_compensation_UMTSBand19_Set0 =
{
  {
    {
      {
        { -64, 0 } ,
        { -64, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
     }
   },
   {  
     {
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
        { 0, 0 } ,
      }
    }
  }
};


const U_sPARACHTMCOMPDATA*  U_PA_RACH_COMP_TABLE_Set0[] =
{
   M_UMTS_TX_RACH_TEMP_COMP_DATA(UMTSBandNone,Set0),
   M_UMTS_TX_RACH_TEMP_COMP_DATA(RX_BAND_INDICATOR_0_Set0,Set0),
   M_UMTS_TX_RACH_TEMP_COMP_DATA(RX_BAND_INDICATOR_1_Set0,Set0),
   M_UMTS_TX_RACH_TEMP_COMP_DATA(RX_BAND_INDICATOR_2_Set0,Set0),
   M_UMTS_TX_RACH_TEMP_COMP_DATA(RX_BAND_INDICATOR_3_Set0,Set0),
   M_UMTS_TX_RACH_TEMP_COMP_DATA(RX_BAND_INDICATOR_4_Set0,Set0)
};

//AFC dac
const U_sAFCDACDATA U_AFC_DAC_Set0 =
{

/*kal_uint16 initDac*/
4096,
/*kal_uint16 slope*/
1266,

};

//AFC Cap
const U_sAFCCAPDATA U_AFC_CAP_Set0 =
{
/*kal_int32 cap_id*/
128,
};

#if (IS_3G_TX_POWER_OFFSET_SUPPORT)
const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBandNone_Set0 =
{
   {
      {
         /* Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db,  } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},     */
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	0	,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBand1_Set0 =
{
   {
      {
         /* Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBand2_Set0 =
{
   {
      {
         /* Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBand4_Set0 =
{
   {
      {
         /* Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBand5_Set0 =
{
   {
      {
         /* Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBand8_Set0 =
{
   {
      {
         /* Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db, } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA},    */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA*  U_TX_POWER_OFFSET_TABLE_Set0[] =
{
   M_UMTS_TX_PWR_OFFSET(UMTSBandNone, Set0),
   M_UMTS_TX_PWR_OFFSET(RX_BAND_INDICATOR_0_Set0, Set0),
   M_UMTS_TX_PWR_OFFSET(RX_BAND_INDICATOR_1_Set0, Set0),
   M_UMTS_TX_PWR_OFFSET(RX_BAND_INDICATOR_2_Set0, Set0),
   M_UMTS_TX_PWR_OFFSET(RX_BAND_INDICATOR_3_Set0, Set0),
   M_UMTS_TX_PWR_OFFSET(RX_BAND_INDICATOR_4_Set0, Set0)
};
#elif IS_3G_SAR_TX_POWER_BACKOFF_SUPPORT
const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBandNone_Set0 =
{
   {
      {
         /* Default Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,  Diversity antenna pwr_offset_db  } */
            /*            {R99   ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   ,   HSUPA    } */
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,  Diversity antenna pwr_offset_db } */
            /*            {R99   ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   ,   HSUPA}  } */
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 2 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,  Diversity antenna pwr_offset_db } */
            /*            {R99   ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   ,   HSUPA}  } */
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 3 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,  Diversity antenna pwr_offset_db } */
            /*            {R99   ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   ,   HSUPA}  } */
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 4 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,  Diversity antenna pwr_offset_db } */
            /*            {R99   ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   ,   HSUPA}  } */
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 5 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,  Diversity antenna pwr_offset_db } */
            /*            {R99   ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   ,   HSUPA}  } */
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 6 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,  Diversity antenna pwr_offset_db } */
            /*            {R99   ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   ,   HSUPA}  } */
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 7 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,  Diversity antenna pwr_offset_db } */
            /*            {R99   ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   ,   HSUPA}  } */
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 8 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,  Diversity antenna pwr_offset_db } */
            /*            {R99   ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   ,   HSUPA}  } */
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            {  0  ,   {{0   ,   0    ,   0} ,{0     ,   0    ,     0}} },
            { UMTS_TABLE_END },
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBand1_Set0 =
{
   {
      {
         /* Default Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_ } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}} */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_ } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}} */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 2 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_ } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}} */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 3 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_ } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}} */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 4 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_ } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}} */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 5 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_ } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}} */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         },
      },
		{
         /* Table 6 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_ } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}} */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 7 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_ } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}} */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         },
      },
      {
         /* Table 8 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_ } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}} */
            {	9612,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9634,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9656,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9678,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9700,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9722,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9744,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9766,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9788,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9810,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9832,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9854,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9876,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9888,	  {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END },
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBand2_Set0 =
{
   {
      {
         /* Default Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 2 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 3 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 4 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 5*/
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 6*/
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 7*/
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 8*/
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	9262	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9284	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9306	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9328	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9350	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9394	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9416	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9438	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9460	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9482	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9504	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9526	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	9538	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBand4_Set0 =
{
   {
      {
         /* Default Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 2 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 3 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 4 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 5 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 6 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 7 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 8 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	1312	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1327	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1342	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1357	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1372	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1387	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1402	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1417	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1432	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1450	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1465	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1480	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1495	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	1513	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBand5_Set0 =
{
   {
      {
         /* Default Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 2 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 3 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 4 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 5 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 6 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 7 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 8 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	4132	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4140	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4148	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4156	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4164	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4172	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4180	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4188	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4195	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4203	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4210	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4218	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4226	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	4233	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA TxPowerOffsetData_UMTSBand8_Set0 =
{
   {
      {
         /* Default Table 0 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 1 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 2 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 3 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 4 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 5 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 6 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 7 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         },
      },
      {
         /* Table 8 */
         {
            /* max arfcn, { Main antenna pwr_offset_db,    Diversity antenna pwr_offset_db } */
            /*             {R99      ,   HSDPA   , HSUPA} , {R99     ,   HSDPA   , HSUPA}  } */
            {	2712	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2723	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2734	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2745	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2756	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2767	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2778	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2788	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2799	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2810	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2821	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2832	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2843	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            {	2863	, {{0 	 ,	  0 	 ,	  0}, {0 	 ,	  0 	 ,	  0}}},
            { UMTS_TABLE_END }
         }
      }
   }
};

const U_sTXPOWEROFFSETDATA*  U_TX_POWER_OFFSET_TABLE_Set0[] =
{
   M_UMTS_TX_PWR_OFFSET(UMTSBandNone, Set0),
   M_UMTS_TX_PWR_OFFSET(RX_BAND_INDICATOR_0_Set0, Set0),
   M_UMTS_TX_PWR_OFFSET(RX_BAND_INDICATOR_1_Set0, Set0),
   M_UMTS_TX_PWR_OFFSET(RX_BAND_INDICATOR_2_Set0, Set0),
   M_UMTS_TX_PWR_OFFSET(RX_BAND_INDICATOR_3_Set0, Set0),
   M_UMTS_TX_PWR_OFFSET(RX_BAND_INDICATOR_4_Set0, Set0)
};


#endif /* IS_3G_TX_POWER_OFFSET_SUPPORT */


#if (IS_3G_TAS_UL1_CUSTOM_SET)

const UMTS_TAS_Configuration_T UMTS_TAS_Configuration_Table_Set0 =
{
/* umts_tas_enable*/
KAL_FALSE,
/* umts_tas_support_on_test_sim*/
KAL_FALSE,
/* umts_tas_default_main_antenna*/
UL1_ANTENNA_0,
/* umts_tas_default_type*/
TAS_TYPE_1,
/* umts_tas_type_by_band*/
{
/*xBand1_TAS_TYPE */BY_BAND_TAS_TYPE_Default,
/*xBand2_TAS_TYPE */BY_BAND_TAS_TYPE_Default,
/*xBand3_TAS_TYPE */BY_BAND_TAS_TYPE_Default,
/*xBand4_TAS_TYPE */BY_BAND_TAS_TYPE_Default,
/*xBand5_TAS_TYPE */BY_BAND_TAS_TYPE_Default,
/*xBand6_TAS_TYPE */BY_BAND_TAS_TYPE_Default,
/*xBand8_TAS_TYPE */BY_BAND_TAS_TYPE_Default,
/*xBand9_TAS_TYPE */BY_BAND_TAS_TYPE_Default,
/*xBand10_TAS_TYPE*/BY_BAND_TAS_TYPE_Default,
/*xBand11_TAS_TYPE*/BY_BAND_TAS_TYPE_Default,
/*xBand19_TAS_TYPE*/BY_BAND_TAS_TYPE_Default
}
#if IS_3G_FORCE_TX_ANT_SUPPORT
/* umts_tas_force_tx_ant_enable*/
,KAL_FALSE  //ANT
/* umts_tas_force_tx_ant_index*/
,UL1_ANTENNA_0
#endif/* IS_3G_FORCE_TX_ANT_SUPPORT */
};
#endif/*IS_3G_TAS_UL1_CUSTOM_SET*/

