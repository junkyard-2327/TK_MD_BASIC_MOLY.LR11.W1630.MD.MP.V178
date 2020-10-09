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
 *	ul1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6176
 *
 * Description:
 * ------------
 *   MT6176 UMTS FDD RF with ES1B
 *
 * Author:
 * -------
 * -------
 *

 *******************************************************************************/
#ifndef  _UL1D_CUSTOM_RF_Set1_H_
#define  _UL1D_CUSTOM_RF_Set1_H_
/* ------------------------------------------------------------------------- */
#if !defined(MT6176_RF)
   #error "rf files mismatch with compile option!"
#endif

#include "ul1d_custom_mipi.h"

/*MT6176*/
/*MT6176*/ #define  PA_SECTION_Set1   3
/*MT6176*/
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ /*   Event Timing Define                                  */
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ #define  TC_PR1_Set1               MICROSECOND_TO_CHIP(200)
/*MT6176*/ #define  TC_PR2_Set1               MICROSECOND_TO_CHIP(100)
/*MT6176*/ #define  TC_PR2B_Set1              MICROSECOND_TO_CHIP( 50)
/*MT6176*/ #define  TC_PR3_Set1               MICROSECOND_TO_CHIP( 20)
/*MT6176*/
/*MT6176*/ #define  TC_PT1_Set1               MICROSECOND_TO_CHIP(200)
/*MT6176*/ #define  TC_PT2_Set1               MICROSECOND_TO_CHIP(100)
/*MT6176*/ #define  TC_PT2B_Set1              MICROSECOND_TO_CHIP( 50)
/*MT6176*/ #define  TC_PT3_Set1               MICROSECOND_TO_CHIP( 10)
/*MT6176*/
/*MT6176*/
/*MT6176*/ /* the following parameter is chip resolution */
/*MT6176*/ #define MAX_OFFSET_Set1        (24*4) //this value must be equal to max of the following 4 offset value
/*MT6176*/ /* Set VM timing same as PGABSI_OFFSET1 */
/*MT6176*/ // Rich modification for the vm_offset as 37
/*MT6176*/ #define VM_OFFSET_Set1         (42)//(33)   //54 //63 chips
/*MT6176*/ #define VBIAS_OFFSET_Set1      (59)   //59 chips
/*MT6176*/ #define DC2DC_OFFSET_Set1      (24*4)
/*MT6176*/ #define VGA_OFFSET_Set1        (24*4)
/*MT6176*/
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ /*   define  BPI data for MT6176                        */
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ /*    PRCB : bit  BPI   pin function                    */
/*MT6176*/ /*            0    0    Reserved                        */
/*MT6176*/ /*            1    1    Reserved                        */
/*MT6176*/ /*            2    2    Reserved                        */
/*MT6176*/ /*            3    3    Reserved                        */
/*MT6176*/ /*            4    4    Reserved                        */
/*MT6176*/ /*            5    5    Reserved                        */
/*MT6176*/ /*            6    6    W_PA_B5_EN                      */
/*MT6176*/ /*            7    7    W_PA_B13_EN                     */
/*MT6176*/ /*            8    8    W_PA_B40_EN                     */
/*MT6176*/ /*            9    9    W_PA_B1_EN                      */
/*MT6176*/ /*            10   10   Reserved                        */
/*MT6176*/ /*            11   11   Reserved                        */
/*MT6176*/ /*            12   12   Reserved                        */
/*MT6176*/ /*            13   13   Reserved                        */
/*MT6176*/ /*            14   14   Reserved                        */
/*MT6176*/ /*            15   15   DRX_V1                          */
/*MT6176*/ /*            16   16   DRX_V2                          */
/*MT6176*/ /*            17   17   DRX_V3                          */
/*MT6176*/ /*            18   18   W_PA_B2_EN                      */
/*MT6176*/ /*            19   19   SP3T_V1                         */
/*MT6176*/ /*            20   20   SP3T_V2                         */
/*MT6176*/ /*            21   21   ASM_VCTRL_B/Main_V2             */
/*MT6176*/ /*            22   22   ASM_VCTRL_A/Main_V1             */
/*MT6176*/ /*            23   23   ASM_VCTRL_C/Main_V3             */
/*MT6176*/ /*            24   24   WG_GGE_PA_ENABLE                */
/*MT6176*/ /*            25   25   LTE_RX                          */
/*MT6176*/ /*            26   26   LTE_RX                          */
/*MT6176*/ /*            27   27   LTE_RX                          */
/*MT6176*/ /*            28   28   LTE_RX                          */
/*MT6176*/ /*            29   29   LTE_RX                          */
/*MT6176*/ /*            30   30   LTE_RX                          */
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ //* --------------------- PDATA_BANDNone Start ---------------------------*/
/*MT6176*/ #define    PDATA_UMTSBandNone_PR1_Set1    0x00000000
/*MT6176*/ #define    PDATA_UMTSBandNone_PR2_Set1    0x00000000
/*MT6176*/ #define    PDATA_UMTSBandNone_PR2B_Set1   0x00000000
/*MT6176*/ #define    PDATA_UMTSBandNone_PR3_Set1    0x00000000
/*MT6176*/ #define    PDATA_UMTSBandNone_PT1_Set1    0x00000000
/*MT6176*/ #define    PDATA_UMTSBandNone_PT2_Set1    0x00000000
/*MT6176*/ #define    PDATA_UMTSBandNone_PT2B_Set1   0x00000000
/*MT6176*/ #define    PDATA_UMTSBandNone_PT3_Set1    0x00000000
/*MT6176*/ /* --------------------- PDATA_BANDNone End ------------------------------*/
/*MT6176*/ //* --------------------- PDATA_BAND1 Start ---------------------------*/
/*MT6176*/ #define    PDATA_UMTSBand1_PR1_Set1      0x000C0000     
/*MT6176*/ #define    PDATA_UMTSBand1_PR2_Set1      0x000C0000     
/*MT6176*/ #define    PDATA_UMTSBand1_PR2B_Set1     0x000C0000 
/*MT6176*/ #define    PDATA_UMTSBand1_PR3_Set1      0x00000000     
/*MT6176*/ #define    PDATA_UMTSBand1_PT1_Set1      PDATA_UMTSBand1_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand1_PT2_Set1      PDATA_UMTSBand1_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand1_PT2B_Set1     PDATA_UMTSBand1_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand1_PT3_Set1      0x00000000     
/*MT6176*/ /* --------------------- PDATA_BAND1 End ------------------------------*/
/*MT6176*/ /* --------------------- PDATA_BAND2 Start ----------------------------*/
/*MT6176*/ #define    PDATA_UMTSBand2_PR1_Set1      0x000C0000     
/*MT6176*/ #define    PDATA_UMTSBand2_PR2_Set1      0x000C0000     
/*MT6176*/ #define    PDATA_UMTSBand2_PR2B_Set1     0x000C0000
/*MT6176*/ #define    PDATA_UMTSBand2_PR3_Set1      0x00000000     
/*MT6176*/ #define    PDATA_UMTSBand2_PT1_Set1      PDATA_UMTSBand2_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand2_PT2_Set1      PDATA_UMTSBand2_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand2_PT2B_Set1     PDATA_UMTSBand2_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand2_PT3_Set1      0x00000000     
/*MT6176*/ /* --------------------- PDATA_BAND2 End ------------------------------*/
/*MT6176*/ /* --------------------- PDATA_BAND4 Start ---------------------------*/
/*MT6176*/ #define    PDATA_UMTSBand4_PR1_Set1      0x000C0000     
/*MT6176*/ #define    PDATA_UMTSBand4_PR2_Set1      0x000C0000     
/*MT6176*/ #define    PDATA_UMTSBand4_PR2B_Set1     0x000C0000
/*MT6176*/ #define    PDATA_UMTSBand4_PR3_Set1      0x00000000     
/*MT6176*/ #define    PDATA_UMTSBand4_PT1_Set1      PDATA_UMTSBand4_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand4_PT2_Set1      PDATA_UMTSBand4_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand4_PT2B_Set1     PDATA_UMTSBand4_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand4_PT3_Set1      0x00000000 
/*MT6176*/ /* --------------------- PDATA_BAND4 End ------------------------------*/
/*MT6176*/ /* --------------------- PDATA_BAND5 Start ----------------------------*/
/*MT6176*/ #define    PDATA_UMTSBand5_PR1_Set1      0x000C8000     
/*MT6176*/ #define    PDATA_UMTSBand5_PR2_Set1      0x000C8000     
/*MT6176*/ #define    PDATA_UMTSBand5_PR2B_Set1     0x000C8000
/*MT6176*/ #define    PDATA_UMTSBand5_PR3_Set1      0x00000000     
/*MT6176*/ #define    PDATA_UMTSBand5_PT1_Set1      PDATA_UMTSBand5_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand5_PT2_Set1      PDATA_UMTSBand5_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand5_PT2B_Set1     PDATA_UMTSBand5_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand5_PT3_Set1      0x00000000     
/*MT6176*/ /* --------------------- PDATA_BAND5 End ------------------------------*/
/*MT6176*/ /* --------------------- PDATA_BAND6 Start ----------------------------*/
/*MT6176*/ #define    PDATA_UMTSBand6_PR1_Set1      PDATA_UMTSBand5_PR1_Set1 
/*MT6176*/ #define    PDATA_UMTSBand6_PR2_Set1      PDATA_UMTSBand5_PR2_Set1 
/*MT6176*/ #define    PDATA_UMTSBand6_PR2B_Set1     PDATA_UMTSBand5_PR2B_Set1
/*MT6176*/ #define    PDATA_UMTSBand6_PR3_Set1      PDATA_UMTSBand5_PR3_Set1 
/*MT6176*/ #define    PDATA_UMTSBand6_PT1_Set1      PDATA_UMTSBand5_PT1_Set1 
/*MT6176*/ #define    PDATA_UMTSBand6_PT2_Set1      PDATA_UMTSBand5_PT2_Set1 
/*MT6176*/ #define    PDATA_UMTSBand6_PT2B_Set1     PDATA_UMTSBand5_PT2B_Set1
/*MT6176*/ #define    PDATA_UMTSBand6_PT3_Set1      PDATA_UMTSBand5_PT3_Set1 
/*MT6176*/ /* --------------------- PDATA_BAND6 End ------------------------------*/
/*MT6176*/ /* --------------------- PDATA_BAND8 Start ----------------------------*/
/*MT6176*/ #define    PDATA_UMTSBand8_PR1_Set1      0x000C0000     
/*MT6176*/ #define    PDATA_UMTSBand8_PR2_Set1      0x000C0000     
/*MT6176*/ #define    PDATA_UMTSBand8_PR2B_Set1     0x000C0000
/*MT6176*/ #define    PDATA_UMTSBand8_PR3_Set1      0x00000000     
/*MT6176*/ #define    PDATA_UMTSBand8_PT1_Set1      PDATA_UMTSBand8_PR1_Set1
/*MT6176*/ #define    PDATA_UMTSBand8_PT2_Set1      PDATA_UMTSBand8_PR1_Set1
/*MT6176*/ #define    PDATA_UMTSBand8_PT2B_Set1     PDATA_UMTSBand8_PR1_Set1
/*MT6176*/ #define    PDATA_UMTSBand8_PT3_Set1      0x00000000     
/*MT6176*/ /* --------------------- PDATA_BAND8 End ------------------------------*/
/*MT6176*/ /* --------------------- PDATA_BAND19 Start ----------------------------*/
/*MT6176*/ #define    PDATA_UMTSBand19_PR1_Set1      PDATA_UMTSBand5_PR1_Set1
/*MT6176*/ #define    PDATA_UMTSBand19_PR2_Set1      PDATA_UMTSBand5_PR2_Set1
/*MT6176*/ #define    PDATA_UMTSBand19_PR2B_Set1     PDATA_UMTSBand5_PR2B_Set1
/*MT6176*/ #define    PDATA_UMTSBand19_PR3_Set1      PDATA_UMTSBand5_PR3_Set1
/*MT6176*/ #define    PDATA_UMTSBand19_PT1_Set1      PDATA_UMTSBand5_PT1_Set1
/*MT6176*/ #define    PDATA_UMTSBand19_PT2_Set1      PDATA_UMTSBand5_PT2_Set1
/*MT6176*/ #define    PDATA_UMTSBand19_PT2B_Set1     PDATA_UMTSBand5_PT2B_Set1
/*MT6176*/ #define    PDATA_UMTSBand19_PT3_Set1      PDATA_UMTSBand5_PT3_Set1
/*MT6176*/ /* --------------------- PDATA_BAND19 End ------------------------------*/
/*MT6176*/ 
/*MT6176*/ /***************************************************/
/*MT6176*/ /*  RX & RXD IO Port Definition & supported freq range  */
/*MT6176*/ /*  HB1-HB3 => freq: 1805MHz ~ 2690MHz                  */
/*MT6176*/ /*  MB1,MB2 => freq: 1475MHz ~ 2170MHz                  */
/*MT6176*/ /*  LB1-LB3 => freq: 734MHz ~ 960MHz                    */
/*MT6176*/ /***************************************************/
/*MT6176*/ /*-----------------------------------------------------------------------*/
/*MT6176*/ /* RX. LNA_PRX1 ~ LNA_PRX14 is configurable, depending on front-end circuits layout  */
/*MT6176*/ /*-----------------------------------------------------------------------*/
/*MT6176*/ #define    UMTSBandNone_CHANNEL_SEL_Set1    NON_USED_BAND
/*MT6176*/ #define    UMTSBand1_CHANNEL_SEL_Set1       LNA_PRX7
/*MT6176*/ #define    UMTSBand2_CHANNEL_SEL_Set1       LNA_PRX10
/*MT6176*/ #define    UMTSBand3_CHANNEL_SEL_Set1       NON_USED_BAND
/*MT6176*/ #define    UMTSBand4_CHANNEL_SEL_Set1       LNA_PRX12
/*MT6176*/ #define    UMTSBand5_CHANNEL_SEL_Set1       LNA_PRX3
/*MT6176*/ #define    UMTSBand6_CHANNEL_SEL_Set1       NON_USED_BAND
/*MT6176*/ #define    UMTSBand8_CHANNEL_SEL_Set1       LNA_PRX2
/*MT6176*/ #define    UMTSBand9_CHANNEL_SEL_Set1       NON_USED_BAND
/*MT6176*/ #define    UMTSBand10_CHANNEL_SEL_Set1      NON_USED_BAND
/*MT6176*/ #define    UMTSBand11_CHANNEL_SEL_Set1      NON_USED_BAND
/*MT6176*/ #define    UMTSBand19_CHANNEL_SEL_Set1      NON_USED_BAND
/*MT6176*/
/*MT6176*/ /*------------------------------------------------------------------------*/
/*MT6176*/ /* RXD. LNA_DRX1 ~ LNA_DRX14 is configurable, depending on front-end circuits layout */
/*MT6176*/ /*------------------------------------------------------------------------*/
/*MT6176*/ #define    UMTSBandNone_CHANNEL2_SEL_Set1   NON_USED_BAND
/*MT6176*/ #define    UMTSBand1_CHANNEL2_SEL_Set1      LNA_DRX6  
/*MT6176*/ #define    UMTSBand2_CHANNEL2_SEL_Set1      LNA_DRX13  
/*MT6176*/ #define    UMTSBand3_CHANNEL2_SEL_Set1      NON_USED_BAND
/*MT6176*/ #define    UMTSBand4_CHANNEL2_SEL_Set1      LNA_DRX10 
/*MT6176*/ #define    UMTSBand5_CHANNEL2_SEL_Set1      LNA_DRX3  
/*MT6176*/ #define    UMTSBand6_CHANNEL2_SEL_Set1      NON_USED_BAND
/*MT6176*/ #define    UMTSBand8_CHANNEL2_SEL_Set1      LNA_DRX2 
/*MT6176*/ #define    UMTSBand9_CHANNEL2_SEL_Set1      NON_USED_BAND
/*MT6176*/ #define    UMTSBand10_CHANNEL2_SEL_Set1     NON_USED_BAND
/*MT6176*/ #define    UMTSBand11_CHANNEL2_SEL_Set1     NON_USED_BAND
/*MT6176*/ #define    UMTSBand19_CHANNEL2_SEL_Set1     NON_USED_BAND
/*MT6176*/
/*MT6176*/ /****************************************************/
/*MT6176*/ /*  TX IO Port Definition & supported freq range        */
/*MT6176*/ /*  TX_HB1~HB2 => freq: 1710MHz ~ 2690MHz                  */
/*MT6176*/ /*  TX_MB1~MB4 => freq: 1400MHz ~ 2025MHz                  */
/*MT6176*/ /*  TX_LB1~LB4 => freq: 699MHz ~ 915MHz                    */
/*MT6176*/ /****************************************************/
/*MT6176*/ #define    UMTSBandNone_OUTPUT_SEL_Set1     NON_USED_BAND
/*MT6176*/ #define    UMTSBand1_OUTPUT_SEL_Set1        TX_MB2
/*MT6176*/ #define    UMTSBand2_OUTPUT_SEL_Set1        TX_MB2
/*MT6176*/ #define    UMTSBand3_OUTPUT_SEL_Set1        NON_USED_BAND
/*MT6176*/ #define    UMTSBand4_OUTPUT_SEL_Set1        TX_MB2
/*MT6176*/ #define    UMTSBand5_OUTPUT_SEL_Set1        TX_LB4
/*MT6176*/ #define    UMTSBand6_OUTPUT_SEL_Set1        NON_USED_BAND
/*MT6176*/ #define    UMTSBand8_OUTPUT_SEL_Set1        TX_LB4
/*MT6176*/ #define    UMTSBand9_OUTPUT_SEL_Set1        NON_USED_BAND
/*MT6176*/ #define    UMTSBand10_OUTPUT_SEL_Set1       NON_USED_BAND
/*MT6176*/ #define    UMTSBand11_OUTPUT_SEL_Set1       NON_USED_BAND
/*MT6176*/ #define    UMTSBand19_OUTPUT_SEL_Set1       NON_USED_BAND
/*MT6176*/
/*MT6176*/ /****************************************************/
/*MT6176*/ /*  TX IO DET Port Definition                                                       */
/*MT6176*/ /*  TX split antenna with different DET pin setting, by HW layout       */
/*MT6176*/ /****************************************************/
/*MT6176*/ #define    UMTSBandNone_OUTPUT_DET_SEL_Set1     TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand1_OUTPUT_DET_SEL_Set1        TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand2_OUTPUT_DET_SEL_Set1        TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand3_OUTPUT_DET_SEL_Set1        TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand4_OUTPUT_DET_SEL_Set1        TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand5_OUTPUT_DET_SEL_Set1        TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand6_OUTPUT_DET_SEL_Set1        TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand8_OUTPUT_DET_SEL_Set1        TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand9_OUTPUT_DET_SEL_Set1        TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand10_OUTPUT_DET_SEL_Set1       TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand11_OUTPUT_DET_SEL_Set1       TX_DET_IO_PORT1
/*MT6176*/ #define    UMTSBand19_OUTPUT_DET_SEL_Set1       TX_DET_IO_PORT1
/*MT6176*/ /************************************************************/
/*MT6176*/ /* For using the V-battery as instead setting               */
/*MT6176*/ /************************************************************/
/*MT6176*/ #define    PMU_PASETTING_Set1         KAL_TRUE
/*MT6176*/ /************************************************************/
/*MT6176*/ /* For RXD single test, customer may use the RXD only,      */
/*MT6176*/ /* need to write RX_MAIN_PATH_ON & RX_DIVERSITY_PATH_ON to  */
/*MT6176*/ /* 0xFFFFFFFF after test                               */
/*MT6176*/ /************************************************************/
/*MT6176*/ #define    RX_DIVERSITY_ALWAYS_ON_Set1 KAL_FALSE
/*MT6176*/ /************************************************************/
/*MT6176*/ /* For PA drift compensation by different band's PA         */
/*MT6176*/ /************************************************************/
/*MT6176*/ #define    PA_DIRFT_COMPENSATION_Set1 0x00000000
/*MT6176*/
/*MT6176*/ /************************************************************/
/*MT6176*/ /* For MPR back off for SAR& lowering PA temerature& UPA/DPA*/
/*MT6176*/ /* PAPR concern                                             */
/*MT6176*/ /************************************************************/
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND1_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND2_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND3_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND4_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND5_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND6_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND8_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND9_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND10_Set1  MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND11_Set1  MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSDPA_BAND19_Set1  MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND1_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND2_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND3_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND4_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND5_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND6_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND8_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND9_Set1   MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND10_Set1  MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND11_Set1  MPRSetting2
/*MT6176*/ #define    MPR_BACK_OFF_HSUPA_BAND19_Set1  MPRSetting2
/*MT6176*/
/*MT6176*/ /************************************************************/
/*MT6176*/ /* At MT6589+MT6320PMIC, Vrf18_1(MD1) can use bulk/LDO mode */
/*MT6176*/ /* take bulk mode as default value*/
/*MT6176*/ /************************************************************/
/*MT6176*/ #define    ULTRA_LOW_COST_EN_Set1 0
/*MT6176*/
/*MT6176*/ #if IS_3G_BAND5_AND_BAND6_INDICATOR_SUPPORT
/*MT6176*/ /************************************************************/
/*MT6176*/ /* Band5 & Band6 support simultaneously flag,*/
/*MT6176*/ /* If flag enable then RX_BAND_INDICATOR just fill in Band5*/
/*MT6176*/ /************************************************************/
/*MT6176*/ #define    BAND5_AND_BAND6_INDICATOR_Set1 0
/*MT6176*/ #endif
/*MT6176*/ 
#if (IS_3G_TAS_SUPPORT)
/************************************************************/
/* For 3G Transmit Antenna Switch feature (TAS)             */
/************************************************************/
#define UMTS_TAS_BPI_PIN_NULL_Set1    -1/* Do NOT modify */

#define UMTS_TAS_BPI_PIN_1_Set1       18                   /* the 1st BPI pin number for TAS*/
#define UMTS_TAS_BPI_PIN_2_Set1       UMTS_TAS_BPI_PIN_NULL_Set1/* the 2nd BPI pin number for TAS*/
#define UMTS_TAS_BPI_PIN_3_Set1       UMTS_TAS_BPI_PIN_NULL_Set1/* the 3rd BPI pin number for TAS*/

#define UMTS_TAS_BPI_PIN_MASK_Set1    UL1D_TAS_BPI_PIN_GEN(1/*PIN_1 EN*/, 1/*PIN_2 EN*/, 1/*PIN_3 EN*/, Set1)

/* ------------- PDATA_TAS0~7 --------------*/
#define PDATA_TAS0_Set1               UL1D_TAS_BPI_PIN_GEN(1/*PIN_1 EN*/, 0/*PIN_2 EN*/, 0/*PIN_3 EN*/, Set1)
#define PDATA_TAS1_Set1               UL1D_TAS_BPI_PIN_GEN(0/*PIN_1 EN*/, 0/*PIN_2 EN*/, 0/*PIN_3 EN*/, Set1)
#define PDATA_TAS2_Set1               PDATA_TAS0_Set1
#define PDATA_TAS3_Set1               PDATA_TAS0_Set1
#define PDATA_TAS4_Set1               PDATA_TAS0_Set1
#define PDATA_TAS5_Set1               PDATA_TAS0_Set1
#define PDATA_TAS6_Set1               PDATA_TAS0_Set1
#define PDATA_TAS7_Set1               PDATA_TAS0_Set1


/************************************************************/
/* TAS BPI and Antenna Mapping                              */
/* PDATA_Band1_TAS1 --> Antenna RXD                         */
/* PDATA_Band1_TAS2 --> Antenna AUX                         */
/* PDATA_Band1_TAS3 --> Spare                               */
/*                                                          */
/************************************************************/

/* ------------- PDATA_BAND1_TAS1/2/3 Start --------------*/
#define PDATA_Band1_TAS1_Set1         PDATA_TAS1_Set1
#define PDATA_Band1_TAS2_Set1         PDATA_TAS2_Set1
#define PDATA_Band1_TAS3_Set1         PDATA_TAS3_Set1

/* ------------- PDATA_BAND2_TAS1/2/3 Start --------------*/
#define PDATA_Band2_TAS1_Set1         PDATA_TAS1_Set1
#define PDATA_Band2_TAS2_Set1         PDATA_TAS2_Set1
#define PDATA_Band2_TAS3_Set1         PDATA_TAS3_Set1

/* ------------- PDATA_BAND3_TAS1/2/3 Start --------------*/
#define PDATA_Band3_TAS1_Set1         PDATA_TAS1_Set1
#define PDATA_Band3_TAS2_Set1         PDATA_TAS2_Set1
#define PDATA_Band3_TAS3_Set1         PDATA_TAS3_Set1

/* ------------- PDATA_BAND4_TAS1/2/3 Start --------------*/
#define PDATA_Band4_TAS1_Set1         PDATA_TAS1_Set1
#define PDATA_Band4_TAS2_Set1         PDATA_TAS2_Set1
#define PDATA_Band4_TAS3_Set1         PDATA_TAS3_Set1

/* ------------- PDATA_BAND5_TAS1/2/3 Start --------------*/
#define PDATA_Band5_TAS1_Set1         PDATA_TAS1_Set1
#define PDATA_Band5_TAS2_Set1         PDATA_TAS2_Set1
#define PDATA_Band5_TAS3_Set1         PDATA_TAS3_Set1

/* ------------- PDATA_BAND6_TAS1/2/3 Start --------------*/
#define PDATA_Band6_TAS1_Set1         PDATA_TAS1_Set1
#define PDATA_Band6_TAS2_Set1         PDATA_TAS2_Set1
#define PDATA_Band6_TAS3_Set1         PDATA_TAS3_Set1

/* ------------- PDATA_BAND7_TAS1/2/3 Start --------------*/
#define PDATA_Band7_TAS1_Set1         PDATA_TAS1_Set1
#define PDATA_Band7_TAS2_Set1         PDATA_TAS2_Set1
#define PDATA_Band7_TAS3_Set1         PDATA_TAS3_Set1

//* ------------- PDATA_BAND8_TAS1/2/3 Start --------------*/
#define PDATA_Band8_TAS1_Set1         PDATA_TAS1_Set1
#define PDATA_Band8_TAS2_Set1         PDATA_TAS2_Set1
#define PDATA_Band8_TAS3_Set1         PDATA_TAS3_Set1

/* ------------- PDATA_BAND9_TAS1/2/3 Start --------------*/
#define PDATA_Band9_TAS1_Set1         PDATA_TAS1_Set1
#define PDATA_Band9_TAS2_Set1         PDATA_TAS2_Set1
#define PDATA_Band9_TAS3_Set1         PDATA_TAS3_Set1

/* ------------- PDATA_BAND10_TAS1/2/3 Start --------------*/
#define PDATA_Band10_TAS1_Set1        PDATA_TAS1_Set1
#define PDATA_Band10_TAS2_Set1        PDATA_TAS2_Set1
#define PDATA_Band10_TAS3_Set1        PDATA_TAS3_Set1

/* ------------- PDATA_BAND11_TAS1/2/3 Start --------------*/
#define PDATA_Band11_TAS1_Set1        PDATA_TAS1_Set1
#define PDATA_Band11_TAS2_Set1        PDATA_TAS2_Set1
#define PDATA_Band11_TAS3_Set1        PDATA_TAS3_Set1

/* ------------- PDATA_BAND19_TAS1/2/3 Start --------------*/
#define PDATA_Band19_TAS1_Set1        PDATA_TAS1_Set1
#define PDATA_Band19_TAS2_Set1        PDATA_TAS2_Set1
#define PDATA_Band19_TAS3_Set1        PDATA_TAS3_Set1


#endif/*IS_3G_TAS_SUPPORT*/
#if (IS_3G_TAS_ANTENNA_IDX_ON_TEST_SIM)
#define UMTS_TAS_INIT_ANT_Band1_Set1   UL1_ANTENNA_0
#define UMTS_TAS_INIT_ANT_Band2_Set1   UL1_ANTENNA_0
#define UMTS_TAS_INIT_ANT_Band3_Set1   UL1_ANTENNA_0
#define UMTS_TAS_INIT_ANT_Band4_Set1   UL1_ANTENNA_0
#define UMTS_TAS_INIT_ANT_Band5_Set1   UL1_ANTENNA_0
#define UMTS_TAS_INIT_ANT_Band6_Set1   UL1_ANTENNA_0
#define UMTS_TAS_INIT_ANT_Band8_Set1   UL1_ANTENNA_0
#define UMTS_TAS_INIT_ANT_Band9_Set1   UL1_ANTENNA_0
#define UMTS_TAS_INIT_ANT_Band10_Set1  UL1_ANTENNA_0
#define UMTS_TAS_INIT_ANT_Band11_Set1  UL1_ANTENNA_0
#define UMTS_TAS_INIT_ANT_Band19_Set1  UL1_ANTENNA_0
#endif

/*MT6176*/ #define    RX_BAND_INDICATOR_0_Set1 UMTSBand1
/*MT6176*/ #define    RX_BAND_INDICATOR_1_Set1 UMTSBand2
/*MT6176*/ #define    RX_BAND_INDICATOR_2_Set1 UMTSBand4
/*MT6176*/ #define    RX_BAND_INDICATOR_3_Set1 UMTSBand5
/*MT6176*/ #define    RX_BAND_INDICATOR_4_Set1 UMTSBand8
/*============================================================================== */

#endif

