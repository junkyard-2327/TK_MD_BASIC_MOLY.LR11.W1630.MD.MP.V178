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
 *   lte_custom_rf.h
 *
 * Project:
 * --------
 *   MT6176
 *
 * Description:
 * ------------
 *   MT6176 LTE FDD/TDD RF
 *
 * Author:
 * -------
 *
 *
 *******************************************************************************/

#ifndef  _LTE_CUSTOM_RF_SetDefault_H_
#define  _LTE_CUSTOM_RF_SetDefault_H_
/* ------------------------------------------------------------------------- */
#if !defined(MT6176_LTE_RF)
   #error "rf files mismatch with compile option!"
#endif

#include "el1d_rf_custom_data.h"

/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ /*   FDD Mode Event Timing Define                         */
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ #define  TC_FPR1_SetDefault  MICROSECOND_TO_26M(105)
/*MT6176*/ #define  TC_FPR2_SetDefault  MICROSECOND_TO_26M(26)
/*MT6176*/ #define  TC_FPR3_SetDefault  MICROSECOND_TO_26M(5)//(15)
/*MT6176*/
/*MT6176*/ #define  TC_FPT1_SetDefault  MICROSECOND_TO_26M(9)
/*MT6176*/ #define  TC_FPT2_SetDefault  MICROSECOND_TO_26M(8)
/*MT6176*/ #define  TC_FPT3_SetDefault  MICROSECOND_TO_26M(5)
/*MT6176*/
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ /*   TDD Mode Event Timing Define                         */
/*MT6176*/ /*--------------------------------------------------------*/
/*MT6176*/ #define  TC_TPR1_SetDefault  MICROSECOND_TO_26M(21)
/*MT6176*/ #define  TC_TPR2_SetDefault  MICROSECOND_TO_26M(20)
/*MT6176*/ #define  TC_TPR3_SetDefault  MICROSECOND_TO_26M(1)//(1)
/*MT6176*/
/*MT6176*/ #define  TC_TPT1_SetDefault  MICROSECOND_TO_26M(9)
/*MT6176*/ #define  TC_TPT2_SetDefault  MICROSECOND_TO_26M(6)
/*MT6176*/ #define  TC_TPT3_SetDefault  MICROSECOND_TO_26M(1)
/*MT6176*/
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
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_LTE_ANT_STATUS -----------------*/
/*MT6176*/ #define  PDATA_LTE_ANT_STATUS_1_SetDefault  0x000C0000
/*MT6176*/ #define  PDATA_LTE_ANT_STATUS_2_SetDefault  0x000C8000
/*MT6176*/ #define  PDATA_LTE_ANT_STATUS_3_SetDefault  0x000C4000
/*MT6176*/ #define  PDATA_LTE_ANT_STATUS_4_SetDefault  0x000CC000
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND1 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band1_PR1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band1_PR2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band1_PR3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band1_PT1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band1_PT2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band1_PT3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band1_PRANT_SetDefault   PDATA_LTE_ANT_STATUS_1_SetDefault  //ANT
/*MT6176*/ #define  PDATA_LTE_Band1_PTANT_SetDefault   PDATA_LTE_Band1_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND2 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band2_PR1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band2_PR2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band2_PR3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band2_PT1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band2_PT2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band2_PT3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band2_PRANT_SetDefault   PDATA_LTE_ANT_STATUS_1_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band2_PTANT_SetDefault   PDATA_LTE_Band2_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND3 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band3_PR1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band3_PR2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band3_PR3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band3_PT1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band3_PT2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band3_PT3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band3_PRANT_SetDefault   PDATA_LTE_ANT_STATUS_1_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band3_PTANT_SetDefault   PDATA_LTE_Band3_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND4 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band4_PR1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band4_PR2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band4_PR3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band4_PT1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band4_PT2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band4_PT3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band4_PRANT_SetDefault   PDATA_LTE_ANT_STATUS_1_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band4_PTANT_SetDefault   PDATA_LTE_Band4_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND5 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band5_PR1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band5_PR2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band5_PR3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band5_PT1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band5_PT2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band5_PT3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band5_PRANT_SetDefault   PDATA_LTE_ANT_STATUS_2_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band5_PTANT_SetDefault   PDATA_LTE_Band5_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND7 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band7_PR1_SetDefault     0x00000004
/*MT6176*/ #define  PDATA_LTE_Band7_PR2_SetDefault     0x00000004
/*MT6176*/ #define  PDATA_LTE_Band7_PR3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band7_PT1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band7_PT2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band7_PT3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band7_PRANT_SetDefault   PDATA_LTE_ANT_STATUS_1_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band7_PTANT_SetDefault   PDATA_LTE_Band7_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND8 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band8_PR1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band8_PR2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band8_PR3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band8_PT1_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band8_PT2_SetDefault     0x00000000
/*MT6176*/ #define  PDATA_LTE_Band8_PT3_SetDefault     LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band8_PRANT_SetDefault   PDATA_LTE_ANT_STATUS_1_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band8_PTANT_SetDefault   PDATA_LTE_Band8_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND12 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band12_PR1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band12_PR2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band12_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band12_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band12_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band12_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band12_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_4_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band12_PTANT_SetDefault  PDATA_LTE_Band12_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND13 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band13_PR1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band13_PR2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band13_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band13_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band13_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band13_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band13_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_4_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band13_PTANT_SetDefault  PDATA_LTE_Band13_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND17 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band17_PR1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band17_PR2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band17_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band17_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band17_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band17_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band17_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_4_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band17_PTANT_SetDefault  PDATA_LTE_Band17_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND20 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band20_PR1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band20_PR2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band20_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band20_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band20_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band20_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band20_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_3_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band20_PTANT_SetDefault  PDATA_LTE_Band20_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND26 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band26_PR1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band26_PR2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band26_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band26_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band26_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band26_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band26_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_2_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band26_PTANT_SetDefault  PDATA_LTE_Band26_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND28 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band28_PR1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band28_PR2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band28_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band28_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band28_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band28_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band28_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_4_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band28_PTANT_SetDefault  PDATA_LTE_Band28_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND29 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band29_PR1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band29_PR2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band29_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band29_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band29_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band29_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band29_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_4_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band29_PTANT_SetDefault  PDATA_LTE_Band29_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND30 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band30_PR1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band30_PR2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band30_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band30_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band30_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band30_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band30_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_1_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band30_PTANT_SetDefault  PDATA_LTE_Band30_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND38 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band38_PR1_SetDefault    0x00000002
/*MT6176*/ #define  PDATA_LTE_Band38_PR2_SetDefault    0x00000002
/*MT6176*/ #define  PDATA_LTE_Band38_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band38_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band38_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band38_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band38_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_1_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band38_PTANT_SetDefault  PDATA_LTE_Band38_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND39 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band39_PR1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band39_PR2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band39_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band39_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band39_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band39_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band39_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_1_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band39_PTANT_SetDefault  PDATA_LTE_Band39_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND40 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band40_PR1_SetDefault    0x00000006
/*MT6176*/ #define  PDATA_LTE_Band40_PR2_SetDefault    0x00000006
/*MT6176*/ #define  PDATA_LTE_Band40_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band40_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band40_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band40_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band40_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_1_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band40_PTANT_SetDefault  PDATA_LTE_Band40_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ //* ------------- PDATA_BAND41 Start --------------------*/
/*MT6176*/ #define  PDATA_LTE_Band41_PR1_SetDefault    0x00000002
/*MT6176*/ #define  PDATA_LTE_Band41_PR2_SetDefault    0x00000002
/*MT6176*/ #define  PDATA_LTE_Band41_PR3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band41_PT1_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band41_PT2_SetDefault    0x00000000
/*MT6176*/ #define  PDATA_LTE_Band41_PT3_SetDefault    LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ #define  PDATA_LTE_Band41_PRANT_SetDefault  PDATA_LTE_ANT_STATUS_1_SetDefault
/*MT6176*/ #define  PDATA_LTE_Band41_PTANT_SetDefault  PDATA_LTE_Band41_PRANT_SetDefault
/*MT6176*/
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ /*  RX & RXD IO Port Definition & supported freq range  */
/*MT6176*/ /*  HB1-HB3 => freq: 1805MHz ~ 2690MHz                  */
/*MT6176*/ /*  MB1,MB2 => freq: 1475MHz ~ 2170MHz                  */
/*MT6176*/ /*  LB1-LB3 => freq: 734MHz ~ 960MHz                    */
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ #define  LTE_Band1_RX_IO_SEL_SetDefault       RX_IO_PRX7
/*MT6176*/ #define  LTE_Band2_RX_IO_SEL_SetDefault       RX_IO_PRX10
/*MT6176*/ #define  LTE_Band3_RX_IO_SEL_SetDefault       RX_IO_PRX8
/*MT6176*/ #define  LTE_Band4_RX_IO_SEL_SetDefault       RX_IO_PRX12
/*MT6176*/ #define  LTE_Band5_RX_IO_SEL_SetDefault       RX_IO_PRX3
/*MT6176*/ #define  LTE_Band7_RX_IO_SEL_SetDefault       RX_IO_PRX14
/*MT6176*/ #define  LTE_Band8_RX_IO_SEL_SetDefault       RX_IO_PRX2
/*MT6176*/ #define  LTE_Band12_RX_IO_SEL_SetDefault      RX_IO_PRX5
/*MT6176*/ #define  LTE_Band13_RX_IO_SEL_SetDefault      RX_IO_PRX5
/*MT6176*/ #define  LTE_Band17_RX_IO_SEL_SetDefault      RX_IO_PRX5
/*MT6176*/ #define  LTE_Band20_RX_IO_SEL_SetDefault      RX_IO_PRX1
/*MT6176*/ #define  LTE_Band26_RX_IO_SEL_SetDefault      RX_IO_PRX3
/*MT6176*/ #define  LTE_Band28_RX_IO_SEL_SetDefault      RX_IO_PRX4
/*MT6176*/ #define  LTE_Band29_RX_IO_SEL_SetDefault      RX_IO_PRX1
/*MT6176*/ #define  LTE_Band30_RX_IO_SEL_SetDefault      RX_IO_PRX13
/*MT6176*/ #define  LTE_Band38_RX_IO_SEL_SetDefault      RX_IO_PRX11
/*MT6176*/ #define  LTE_Band39_RX_IO_SEL_SetDefault      RX_IO_PRX6
/*MT6176*/ #define  LTE_Band40_RX_IO_SEL_SetDefault      RX_IO_PRX13
/*MT6176*/ #define  LTE_Band41_RX_IO_SEL_SetDefault      RX_IO_PRX11
/*MT6176*/
/*MT6176*/ #define  LTE_Band1_RXD_IO_SEL_SetDefault      RX_IO_DRX6
/*MT6176*/ #define  LTE_Band2_RXD_IO_SEL_SetDefault      RX_IO_DRX13
/*MT6176*/ #define  LTE_Band3_RXD_IO_SEL_SetDefault      RX_IO_DRX14
/*MT6176*/ #define  LTE_Band4_RXD_IO_SEL_SetDefault      RX_IO_DRX10
/*MT6176*/ #define  LTE_Band5_RXD_IO_SEL_SetDefault      RX_IO_DRX3
/*MT6176*/ #define  LTE_Band7_RXD_IO_SEL_SetDefault      RX_IO_DRX8
/*MT6176*/ #define  LTE_Band8_RXD_IO_SEL_SetDefault      RX_IO_DRX2
/*MT6176*/ #define  LTE_Band12_RXD_IO_SEL_SetDefault     RX_IO_DRX5
/*MT6176*/ #define  LTE_Band13_RXD_IO_SEL_SetDefault     RX_IO_DRX5
/*MT6176*/ #define  LTE_Band17_RXD_IO_SEL_SetDefault     RX_IO_DRX5
/*MT6176*/ #define  LTE_Band20_RXD_IO_SEL_SetDefault     RX_IO_DRX1
/*MT6176*/ #define  LTE_Band26_RXD_IO_SEL_SetDefault     RX_IO_DRX3
/*MT6176*/ #define  LTE_Band28_RXD_IO_SEL_SetDefault     RX_IO_DRX7
/*MT6176*/ #define  LTE_Band29_RXD_IO_SEL_SetDefault     RX_IO_DRX1
/*MT6176*/ #define  LTE_Band30_RXD_IO_SEL_SetDefault     RX_IO_DRX8
/*MT6176*/ #define  LTE_Band38_RXD_IO_SEL_SetDefault     RX_IO_DRX11
/*MT6176*/ #define  LTE_Band39_RXD_IO_SEL_SetDefault     RX_IO_DRX5
/*MT6176*/ #define  LTE_Band40_RXD_IO_SEL_SetDefault     RX_IO_DRX9
/*MT6176*/ #define  LTE_Band41_RXD_IO_SEL_SetDefault     RX_IO_DRX11
/*MT6176*/
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ /*  TX IO Port Definition & supported freq range        */
/*MT6176*/ /*  HB1,HB2 => freq: 1710MHz ~ 2690MHz                  */
/*MT6176*/ /*  MB1,MB2 => freq: 1400MHz ~ 2025MHz                  */
/*MT6176*/ /*  LB1-LB4 => freq: 699MHz ~ 915MHz                    */
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ #define  LTE_Band1_TX_IO_SEL_SetDefault       TX_IO_MB2
/*MT6176*/ #define  LTE_Band2_TX_IO_SEL_SetDefault       TX_IO_MB2
/*MT6176*/ #define  LTE_Band3_TX_IO_SEL_SetDefault       TX_IO_MB2
/*MT6176*/ #define  LTE_Band4_TX_IO_SEL_SetDefault       TX_IO_MB2
/*MT6176*/ #define  LTE_Band5_TX_IO_SEL_SetDefault       TX_IO_LB4
/*MT6176*/ #define  LTE_Band7_TX_IO_SEL_SetDefault       TX_IO_HB2
/*MT6176*/ #define  LTE_Band8_TX_IO_SEL_SetDefault       TX_IO_LB4
/*MT6176*/ #define  LTE_Band12_TX_IO_SEL_SetDefault      TX_IO_LB4
/*MT6176*/ #define  LTE_Band13_TX_IO_SEL_SetDefault      TX_IO_LB4
/*MT6176*/ #define  LTE_Band17_TX_IO_SEL_SetDefault      TX_IO_LB4
/*MT6176*/ #define  LTE_Band20_TX_IO_SEL_SetDefault      TX_IO_LB4
/*MT6176*/ #define  LTE_Band26_TX_IO_SEL_SetDefault      TX_IO_LB4
/*MT6176*/ #define  LTE_Band28_TX_IO_SEL_SetDefault      TX_IO_LB4
/*MT6176*/ #define  LTE_Band29_TX_IO_SEL_SetDefault      TX_IO_NON_USED
/*MT6176*/ #define  LTE_Band30_TX_IO_SEL_SetDefault      TX_IO_HB2
/*MT6176*/ #define  LTE_Band38_TX_IO_SEL_SetDefault      TX_IO_HB2
/*MT6176*/ #define  LTE_Band39_TX_IO_SEL_SetDefault      TX_IO_MB3
/*MT6176*/ #define  LTE_Band40_TX_IO_SEL_SetDefault      TX_IO_HB2
/*MT6176*/ #define  LTE_Band41_TX_IO_SEL_SetDefault      TX_IO_HB2
/*MT6176*/
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ /*  TX IO Port Definition & supported freq range        */
/*MT6176*/ /*  HB1,HB2 => freq: 1710MHz ~ 2690MHz                  */
/*MT6176*/ /*  MB1,MB2 => freq: 1400MHz ~ 2025MHz                  */
/*MT6176*/ /*  LB1-LB4 => freq: 699MHz ~ 915MHz                    */
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ #define  LTE_Band1_TX_DET_IO_SEL_SetDefault   TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band2_TX_DET_IO_SEL_SetDefault   TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band3_TX_DET_IO_SEL_SetDefault   TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band4_TX_DET_IO_SEL_SetDefault   TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band5_TX_DET_IO_SEL_SetDefault   TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band7_TX_DET_IO_SEL_SetDefault   TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band8_TX_DET_IO_SEL_SetDefault   TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band12_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band13_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band17_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band20_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band26_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band28_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band29_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band30_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band38_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band39_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band40_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/ #define  LTE_Band41_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ /*------------------------------------------------------------*/
/*MT6176*/ /*  BAND_INDICATOR0_SetDefault ~ BAND_INDICATOR20_SetDefault  */
/*MT6176*/ /*------------------------------------------------------------*/
/*MT6176*/ #define  BAND_INDICATOR0_SetDefault        LTE_Band1
/*MT6176*/ #define  BAND_INDICATOR1_SetDefault        LTE_Band2
/*MT6176*/ #define  BAND_INDICATOR2_SetDefault        LTE_Band3
/*MT6176*/ #define  BAND_INDICATOR3_SetDefault        LTE_Band4
/*MT6176*/ #define  BAND_INDICATOR4_SetDefault        LTE_Band5
/*MT6176*/ #define  BAND_INDICATOR5_SetDefault        LTE_Band7
/*MT6176*/ #define  BAND_INDICATOR6_SetDefault        LTE_Band8
/*MT6176*/ #define  BAND_INDICATOR7_SetDefault        LTE_Band20
/*MT6176*/ #define  BAND_INDICATOR8_SetDefault        LTE_Band26
/*MT6176*/ #define  BAND_INDICATOR9_SetDefault        LTE_Band28
/*MT6176*/ #define  BAND_INDICATOR10_SetDefault       LTE_Band38
/*MT6176*/ #define  BAND_INDICATOR11_SetDefault       LTE_Band39
/*MT6176*/ #define  BAND_INDICATOR12_SetDefault       LTE_Band40
/*MT6176*/ #define  BAND_INDICATOR13_SetDefault       LTE_Band41
/*MT6176*/ #define  BAND_INDICATOR14_SetDefault       LTE_BandNone
/*MT6176*/ #define  BAND_INDICATOR15_SetDefault       LTE_BandNone
/*MT6176*/ #define  BAND_INDICATOR16_SetDefault       LTE_BandNone
/*MT6176*/ #define  BAND_INDICATOR17_SetDefault       LTE_BandNone
/*MT6176*/ #define  BAND_INDICATOR18_SetDefault       LTE_BandNone
/*MT6176*/ #define  BAND_INDICATOR19_SetDefault       LTE_BandNone
/*MT6176*/ #define  BAND_INDICATOR20_SetDefault       LTE_BandNone
/*MT6176*/
/*MT6176*/ /*--------------------------------------------------------------*/
/*MT6176*/ /*                VPA_source_define_SetDefault                  */
/*MT6176*/ /*--------------------------------------------------------------*/
/*MT6176*/ #define  LTE_Band1_VPA_SOURCE_SetDefault    VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band2_VPA_SOURCE_SetDefault    VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band3_VPA_SOURCE_SetDefault    VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band4_VPA_SOURCE_SetDefault    VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band5_VPA_SOURCE_SetDefault    VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band7_VPA_SOURCE_SetDefault    VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band8_VPA_SOURCE_SetDefault    VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band20_VPA_SOURCE_SetDefault   VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band26_VPA_SOURCE_SetDefault   VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band28_VPA_SOURCE_SetDefault   VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band38_VPA_SOURCE_SetDefault   VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band39_VPA_SOURCE_SetDefault   VPA_SOURCE_HW_VAPC
/*MT6176*/ #define  LTE_Band40_VPA_SOURCE_SetDefault   VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band41_VPA_SOURCE_SetDefault   VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_BandNone_BYPASS_VPA_SOURCE_SetDefault   VPA_SOURCE_NOT_SUPPORTED
/*MT6176*/ #define  LTE_Band38_BYPASS_VPA_SOURCE_SetDefault   VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band40_BYPASS_VPA_SOURCE_SetDefault   VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_Band41_BYPASS_VPA_SOURCE_SetDefault   VPA_SOURCE_HW_PMIC
/*MT6176*/ #define  LTE_BandNone_HRM_VPA_SOURCE_SetDefault    VPA_SOURCE_NOT_SUPPORTED
/*MT6176*/ #define  LTE_Band12_HRM_VPA_SOURCE_SetDefault      VPA_SOURCE_NOT_SUPPORTED
/*MT6176*/ #define  LTE_Band17_HRM_VPA_SOURCE_SetDefault      VPA_SOURCE_NOT_SUPPORTED
/*MT6176*/ #define  LTE_Band28_HRM_VPA_SOURCE_SetDefault      VPA_SOURCE_HW_PMIC
/*MT6176*/
/*MT6176*/ /*-------------------------------------*/
/*MT6176*/ /*         PA Related Config           */
/*MT6176*/ /*         (No DRDI)                   */
/*MT6176*/ /*-------------------------------------*/
/*MT6176*/ #define  NUM_PA_MODE_SetDefault     3
/*MT6176*/ #define  NUM_HYSTERESIS_SetDefault  2
/*MT6176*/
/*MT6176*/ /*-------------------------------------------------------------------*/
/*MT6176*/ /*  MPR value for each band setting: 36.101 6.2.3 6.2.5 with S(8.8)  */
/*MT6176*/ /*  (No DRDI)                                                        */
/*MT6176*/ /*-------------------------------------------------------------------*/
/*MT6176*/ //* ------------- MPR_BAND1 Start --------------------*/
/*MT6176*/ #define  LTE_Band1_MPR_QPSK1_SetDefault    0x0100
/*MT6176*/ #define  LTE_Band1_MPR_16QAM0_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band1_MPR_16QAM1_SetDefault   0x0200
/*MT6176*/ #define  LTE_Band1_MPR_64QAM0_SetDefault   0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band1_MPR_64QAM1_SetDefault   0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band1_DELTA_TC0_SetDefault    0x0000
/*MT6176*/ #define  LTE_Band1_DELTA_TC1_SetDefault    0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND2 Start --------------------*/
/*MT6176*/ #define  LTE_Band2_MPR_QPSK1_SetDefault    0x0100
/*MT6176*/ #define  LTE_Band2_MPR_16QAM0_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band2_MPR_16QAM1_SetDefault   0x0200
/*MT6176*/ #define  LTE_Band2_MPR_64QAM0_SetDefault   0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band2_MPR_64QAM1_SetDefault   0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band2_DELTA_TC0_SetDefault    0x0000
/*MT6176*/ #define  LTE_Band2_DELTA_TC1_SetDefault    0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND3 Start --------------------*/
/*MT6176*/ #define  LTE_Band3_MPR_QPSK1_SetDefault    0x0100
/*MT6176*/ #define  LTE_Band3_MPR_16QAM0_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band3_MPR_16QAM1_SetDefault   0x0200
/*MT6176*/ #define  LTE_Band3_MPR_64QAM0_SetDefault   0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band3_MPR_64QAM1_SetDefault   0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band3_DELTA_TC0_SetDefault    0x0000
/*MT6176*/ #define  LTE_Band3_DELTA_TC1_SetDefault    0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND4 Start --------------------*/
/*MT6176*/ #define  LTE_Band4_MPR_QPSK1_SetDefault    0x0100
/*MT6176*/ #define  LTE_Band4_MPR_16QAM0_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band4_MPR_16QAM1_SetDefault   0x0200
/*MT6176*/ #define  LTE_Band4_MPR_64QAM0_SetDefault   0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band4_MPR_64QAM1_SetDefault   0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band4_DELTA_TC0_SetDefault    0x0000
/*MT6176*/ #define  LTE_Band4_DELTA_TC1_SetDefault    0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND5 Start --------------------*/
/*MT6176*/ #define  LTE_Band5_MPR_QPSK1_SetDefault    0x0100
/*MT6176*/ #define  LTE_Band5_MPR_16QAM0_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band5_MPR_16QAM1_SetDefault   0x0200
/*MT6176*/ #define  LTE_Band5_MPR_64QAM0_SetDefault   0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band5_MPR_64QAM1_SetDefault   0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band5_DELTA_TC0_SetDefault    0x0000
/*MT6176*/ #define  LTE_Band5_DELTA_TC1_SetDefault    0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND6 Start --------------------*/
/*MT6176*/ #define  LTE_Band6_MPR_QPSK1_SetDefault    0x0100
/*MT6176*/ #define  LTE_Band6_MPR_16QAM0_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band6_MPR_16QAM1_SetDefault   0x0200
/*MT6176*/ #define  LTE_Band6_MPR_64QAM0_SetDefault   0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band6_MPR_64QAM1_SetDefault   0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band6_DELTA_TC0_SetDefault    0x0000
/*MT6176*/ #define  LTE_Band6_DELTA_TC1_SetDefault    0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND7 Start --------------------*/
/*MT6176*/ #define  LTE_Band7_MPR_QPSK1_SetDefault    0x0100
/*MT6176*/ #define  LTE_Band7_MPR_16QAM0_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band7_MPR_16QAM1_SetDefault   0x0200
/*MT6176*/ #define  LTE_Band7_MPR_64QAM0_SetDefault   0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band7_MPR_64QAM1_SetDefault   0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band7_DELTA_TC0_SetDefault    0x0000
/*MT6176*/ #define  LTE_Band7_DELTA_TC1_SetDefault    0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND8 Start --------------------*/
/*MT6176*/ #define  LTE_Band8_MPR_QPSK1_SetDefault    0x0100
/*MT6176*/ #define  LTE_Band8_MPR_16QAM0_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band8_MPR_16QAM1_SetDefault   0x0200
/*MT6176*/ #define  LTE_Band8_MPR_64QAM0_SetDefault   0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band8_MPR_64QAM1_SetDefault   0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band8_DELTA_TC0_SetDefault    0x0000
/*MT6176*/ #define  LTE_Band8_DELTA_TC1_SetDefault    0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND12 Start -------------------*/
/*MT6176*/ #define  LTE_Band12_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band12_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band12_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band12_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band12_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band12_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band12_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND13 Start -------------------*/
/*MT6176*/ #define  LTE_Band13_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band13_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band13_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band13_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band13_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band13_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band13_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND17 Start -------------------*/
/*MT6176*/ #define  LTE_Band17_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band17_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band17_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band17_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band17_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band17_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band17_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND20 Start -------------------*/
/*MT6176*/ #define  LTE_Band20_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band20_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band20_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band20_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band20_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band20_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band20_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND25 Start -------------------*/
/*MT6176*/ #define  LTE_Band25_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band25_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band25_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band25_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band25_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band25_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band25_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND26 Start -------------------*/
/*MT6176*/ #define  LTE_Band26_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band26_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band26_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band26_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band26_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band26_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band26_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND28 Start -------------------*/
/*MT6176*/ #define  LTE_Band28_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band28_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band28_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band28_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band28_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band28_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band28_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND29 Start -------------------*/
/*MT6176*/ #define  LTE_Band29_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band29_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band29_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band29_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band29_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band29_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band29_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND30 Start -------------------*/
/*MT6176*/ #define  LTE_Band30_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band30_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band30_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band30_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band30_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band30_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band30_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND34 Start -------------------*/
/*MT6176*/ #define  LTE_Band34_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band34_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band34_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band34_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band34_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band34_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band34_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND38 Start -------------------*/
/*MT6176*/ #define  LTE_Band38_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band38_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band38_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band38_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band38_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band38_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band38_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND39 Start -------------------*/
/*MT6176*/ #define  LTE_Band39_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band39_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band39_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band39_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band39_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band39_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band39_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND40 Start -------------------*/
/*MT6176*/ #define  LTE_Band40_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band40_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band40_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band40_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band40_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band40_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band40_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND41 Start -------------------*/
/*MT6176*/ #define  LTE_Band41_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band41_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band41_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band41_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band41_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band41_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band41_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/ //* ------------- MPR_BAND66 Start -------------------*/
/*MT6176*/ #define  LTE_Band66_MPR_QPSK1_SetDefault   0x0100
/*MT6176*/ #define  LTE_Band66_MPR_16QAM0_SetDefault  0x0100
/*MT6176*/ #define  LTE_Band66_MPR_16QAM1_SetDefault  0x0200
/*MT6176*/ #define  LTE_Band66_MPR_64QAM0_SetDefault  0x0200          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band66_MPR_64QAM1_SetDefault  0x0300          // Modify this setting when MPR 64QAM is supported. Otherwise, leave it unchanged.
/*MT6176*/ #define  LTE_Band66_DELTA_TC0_SetDefault   0x0000
/*MT6176*/ #define  LTE_Band66_DELTA_TC1_SetDefault   0x0000
/*MT6176*/
/*MT6176*/
/*MT6176*//* ------------- AMPR Value -------------------*/
/*MT6176*//* --------------(No DRDI) --------------------*/
/*MT6176*/#define LTE_Band1_NS5_SetDefault                                                                                                        \
/*MT6176*//*NS5_101520*/                                                                                                               \
/*MT6176*/{    0x0200,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band2_NS3_SetDefault                                                                                                        \
/*MT6176*//* NS3_03  ,    NS3_05,    NS3_10,    NS3_15,    NS3_20*/                                                                    \
/*MT6176*/{    0x0100,    0x0100,    0x0100,    0x0100,    0x0100,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band4_NS3_SetDefault                                                                                                        \
/*MT6176*//* NS3_03  ,    NS3_05,    NS3_10,    NS3_15,    NS3_20*/                                                                    \
/*MT6176*/{    0x0100,    0x0100,    0x0100,    0x0100,    0x0100,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band10_NS3_SetDefault                                                                                                       \
/*MT6176*//* NS3_03  ,    NS3_05,    NS3_10,    NS3_15,    NS3_20*/                                                                    \
/*MT6176*/{    0x0100,    0x0100,    0x0100,    0x0100,    0x0100,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band13_NS7_SetDefault                                                                                                       \
/*MT6176*//*NS7_10_A0, NS7_10_A1, NS7_10_B0, NS7_10_B1, NS7_10_C*/                                                                     \
/*MT6176*/{    0x0800,    0x0C00,    0x0C00,    0x0600,    0x0300,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band19_NS8_SetDefault                                                                                                       \
/*MT6176*//*  NS8_1015*/                                                                                                               \
/*MT6176*/{    0x0300,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band20_NS10_SetDefault                                                                                                      \
/*MT6176*//*  NS10_15A, NS10_20A*/                                                                                                 \
/*MT6176*/{    0x0200,    0x0500,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band21_NS9_SetDefault                                                                                                       \
/*MT6176*//*NS9_10150, NS9_10151*/                                                                                                  \
/*MT6176*/{    0x0100,    0x0200,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band23_NS3_SetDefault                                                                                                       \
/*MT6176*//* NS3_03  ,    NS3_05,    NS3_10,    NS3_15,    NS3_20*/                                                                    \
/*MT6176*/{    0x0100,    0x0100,    0x0100,    0x0100,    0x0100,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band23_NS11_SetDefault                                                                                                      \
/*MT6176*//*  NS11_3A,   NS11_3B,   NS11_5A,  NS11_5B0,   NS11_5C,  NS11_10A, NS11_15A0,NS11_15A10,NS11_15A11,NS11_15A21,NS11_15A3 ,*/ \
/*MT6176*/{    0x0500,    0x0100,    0x0700,    0x0400,    0x0100,    0x0C00,    0x0F00,    0x0700,    0x0A00,    0x0600,    0x0F00,   \
/*MT6176*//*NS11_15B0,NS11_15B10,NS11_15B2 , NS11_15B3, NS11_20A0,NS11_20A10,NS11_20A11,NS11_20A21,NS11_20A3*/                         \
/*MT6176*/     0x0A00,    0x0600,    0x0200,    0x0680,    0x0F00,    0x0700,    0x0A00,    0x0700,    0x0F00,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band23_NS20_SetDefault                                                                                                      \
/*MT6176*//*  NS20_5A, NS20_5B00, NS20_5B01,  NS20_5B1, NS20_10A0,NS20_10A10,NS20_10A11, NS20_10A2, NS20_10B0, NS20_10B1,NS20_15A00,*/ \
/*MT6176*/{    0x1100,    0x0100,    0x0400,    0x0200,    0x1000,    0x0200,    0x0500,    0x0600,    0x0400,    0x0200,    0x0B00,   \
/*MT6176*//*NS20_15A01,NS20_15A10,NS20_15A11, NS20_15A2, NS20_15A3, NS20_20A0,NS20_20A10,NS20_20A11, NS20_20A2, NS20_20A3, NS20_20A4,*/\
/*MT6176*/     0x0600,    0x0100,    0x0700,    0x0500,    0x0600,    0x1100,    0x0C00,    0x0600,    0x0900,    0x0700,    0x0500,   \
/*MT6176*//*NS20_20A5,*/                                                                                                               \
/*MT6176*/     0x1000,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band25_NS3_SetDefault                                                                                                       \
/*MT6176*//* NS3_03  ,    NS3_05,    NS3_10,    NS3_15,    NS3_20*/                                                                    \
/*MT6176*/{    0x0100,    0x0100,    0x0100,    0x0100,    0x0100,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band26_NS121314_SetDefault                                                                                                  \
/*MT6176*//* NS12_1A0,  NS12_1A1,   NS12_1B,  NS12_3A0,  NS12_3A1,   NS12_3B,  NS12_5A0,  NS12_5A1,   NS12_5B,  NS13_5A0,  NS13_5A1,*/ \
/*MT6176*/{    0x0300,    0x0600,    0x0300,    0x0400,    0x0300,    0x0300,    0x0500,    0x0300,    0x0300,    0x0300,    0x0200,   \
/*MT6176*//*NS14_10A0, NS14_10A1, NS14_15A0, NS14_15A1*/                                                                               \
/*MT6176*/     0x0300,    0x0100,    0x0300,    0x0100,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band26_NS15_SetDefault                                                                                                      \
/*MT6176*//* NS150_1C,  NS150_3A,  NS150_3B,  NS150_3C,  NS150_5A,  NS150_5B,  NS150_5C, NS150_10A, NS150_10B, NS150_10C, NS150_15A,*/ \
/*MT6176*/{    0x0300,    0x0400,    0x0400,    0x0900,    0x0400,    0x0500,    0x0900,    0x0400,    0x0600,    0x0900,    0x0400,   \
/*MT6176*//*NS150_15B, NS150_15C,  NS151_5C, NS151_10A, NS151_10B, NS151_10C, NS151_15A, NS151_15B, NS151_15C*/                        \
/*MT6176*/     0x0500,    0x0900,    0x0200,    0x0400,    0x0400,    0x0900,    0x0400,    0x0500,    0x0900,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band27_NS16_SetDefault                                                                                                      \
/*MT6176*//* NS160_3A,  NS160_3B,  NS160_5A,  NS160_5B,  NS160_5C,  NS160_5D, NS160_10A,NS160_10B0,NS160_10B1, NS160_10D, NS160_10E,*/ \
/*MT6176*/{    0x0200,    0x0100,    0x0500,    0x0100,    0x0200,    0x0300,    0x0500,    0x0300,    0x0700,    0x0300,    0x0100,   \
/*MT6176*//* NS161_5A,  NS161_5B,  NS161_5C,NS161_10A0,NS161_10A1,NS161_10C,  NS161_10D, NS161_10E, NS162_10A, NS162_10B, NS162_10C,*/ \
/*MT6176*/     0x0200,    0x0300,    0x0100,    0x0500,    0x0200,    0x0400,    0x0500,    0x0100,    0x0100,    0x0200,    0x0100,   \
/*MT6176*//*NS162_10D*/                                                                                                                \
/*MT6176*/     0x0300,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band28_NS18_SetDefault                                                                                                      \
/*MT6176*//*  NS18_5 , NS18_101520*/                                                                                                   \
/*MT6176*/{    0x0100,    0x0400,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band35_NS3_SetDefault                                                                                                       \
/*MT6176*//* NS3_03  ,    NS3_05,    NS3_10,    NS3_15,    NS3_20*/                                                                    \
/*MT6176*/{    0x0100,    0x0100,    0x0100,    0x0100,    0x0100,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band36_NS3_SetDefault                                                                                                       \
/*MT6176*//* NS3_03  ,    NS3_05,    NS3_10,    NS3_15,    NS3_20*/                                                                    \
/*MT6176*/{    0x0100,    0x0100,    0x0100,    0x0100,    0x0100,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/
/*MT6176*/#define LTE_Band41_NS4_SetDefault                                                                                                       \
/*MT6176*//*    NS4_5,  NS4_10_A,  NS4_10_B,  NS4_10_C,  NS4_15_A,  NS4_15_B,  NS4_15_C,  NS4_20_A,  NS4_20_B,  NS4_20_C*/             \
/*MT6176*/{    0x0100,    0x0300,    0x0200,    0x0300,    0x0300,    0x0200,    0x0300,    0x0300,    0x0200,    0x0300,         0,   \
/*MT6176*/          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,         0,   \
/*MT6176*/          0,         0}
/*MT6176*/#if IS_4G_HPUE_FEATURE_SUPPORT
/*MT6176*/#define LTE_AMPR_NS4_HPUE_SetDefault                                                                                                       \
/*MT6176*//* NS4_hpue_5_A0,    NS4_hpue_5_A1,     NS4_hpue_5_B, NS4_hpue_10_A0_0, NS4_hpue_10_A0_1, NS4_hpue_10_A0_2,  NS4_hpue_10_A1,*/       \
/*MT6176*/{              0,                0,                0,                0,                0,                0,               0,         \
/*MT6176*//*NS4_hpue_10_A2,    NS4_hpue_10_B, NS4_hpue_15_A0_0, NS4_hpue_15_A0_1, NS4_hpue_15_A0_2,   NS4_hpue_15_A1,  NS4_hpue_15_A2,*/       \
/*MT6176*/               0,                0,                0,              0x0,                0,                0,               0,         \
/*MT6176*//* NS4_hpue_15_B, NS4_hpue_20_A0_0, NS4_hpue_20_A0_1, NS4_hpue_20_A0_2,   NS4_hpue_20_A1,   NS4_hpue_20_A2,   NS4_hpue_20_B,*/       \
/*MT6176*/               0,                0,                0,                0,                0,                0,               0,         \
/*MT6176*//*          rsv0,             rsv1,             rsv2,             rsv3,             rsv4,             rsv5,            rsv6,*/       \
/*MT6176*/               0,                0,                0,                0,                0,                0,               0,         \
/*MT6176*//*          rsv7,             rsv8,             rsv9,*/                                                                              \
/*MT6176*/               0,                0,                0}
/*MT6176*/#endif
/*MT6176*/ /*--------------------------------*/
/*MT6176*/ /* Temperature Compensation Param */
/*MT6176*/ /*--------------------------------*/
/*MT6176*/
/*MT6176*/ //* ------------- BAND None Start --------------------*/
/*MT6176*/ #define  LTE_BandNone_TPBF_TEMP_THRES_SetDefault  0        // deg-C
/*MT6176*/ #define  LTE_BandNone_TPBF_PWR_THRES_SetDefault   0        // 1/32dB
/*MT6176*/ #define  LTE_BandNone_TPBF_APT_MODE_SetDefault    0        // 1/32dB
/*MT6176*/ #define  LTE_BandNone_TPBF_ET_MODE_SetDefault     0        // 1/32dB
/*MT6176*/ #define  LTE_BandNone_TPBF_DPD_MODE_SetDefault    0        // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND1 Start ----------------------*/
/*MT6176*/ #define  LTE_Band1_TPBF_TEMP_THRES_SetDefault     65       // deg-C
/*MT6176*/ #define  LTE_Band1_TPBF_PWR_THRES_SetDefault     (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band1_TPBF_APT_MODE_SetDefault       32       // 1/32dB
/*MT6176*/ #define  LTE_Band1_TPBF_ET_MODE_SetDefault        16       // 1/32dB
/*MT6176*/ #define  LTE_Band1_TPBF_DPD_MODE_SetDefault       16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND2 Start ----------------------*/
/*MT6176*/ #define  LTE_Band2_TPBF_TEMP_THRES_SetDefault     65       // deg-C
/*MT6176*/ #define  LTE_Band2_TPBF_PWR_THRES_SetDefault     (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band2_TPBF_APT_MODE_SetDefault       32       // 1/32dB
/*MT6176*/ #define  LTE_Band2_TPBF_ET_MODE_SetDefault        16       // 1/32dB
/*MT6176*/ #define  LTE_Band2_TPBF_DPD_MODE_SetDefault       16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND3 Start ----------------------*/
/*MT6176*/ #define  LTE_Band3_TPBF_TEMP_THRES_SetDefault     65       // deg-C
/*MT6176*/ #define  LTE_Band3_TPBF_PWR_THRES_SetDefault     (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band3_TPBF_APT_MODE_SetDefault       32       // 1/32dB
/*MT6176*/ #define  LTE_Band3_TPBF_ET_MODE_SetDefault        16       // 1/32dB
/*MT6176*/ #define  LTE_Band3_TPBF_DPD_MODE_SetDefault       16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND4 Start ----------------------*/
/*MT6176*/ #define  LTE_Band4_TPBF_TEMP_THRES_SetDefault     65       // deg-C
/*MT6176*/ #define  LTE_Band4_TPBF_PWR_THRES_SetDefault     (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band4_TPBF_APT_MODE_SetDefault       32       // 1/32dB
/*MT6176*/ #define  LTE_Band4_TPBF_ET_MODE_SetDefault        16       // 1/32dB
/*MT6176*/ #define  LTE_Band4_TPBF_DPD_MODE_SetDefault       16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND5 Start ----------------------*/
/*MT6176*/ #define  LTE_Band5_TPBF_TEMP_THRES_SetDefault     65       // deg-C
/*MT6176*/ #define  LTE_Band5_TPBF_PWR_THRES_SetDefault     (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band5_TPBF_APT_MODE_SetDefault       32       // 1/32dB
/*MT6176*/ #define  LTE_Band5_TPBF_ET_MODE_SetDefault        16       // 1/32dB
/*MT6176*/ #define  LTE_Band5_TPBF_DPD_MODE_SetDefault       16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND6 Start ----------------------*/
/*MT6176*/ #define  LTE_Band6_TPBF_TEMP_THRES_SetDefault     65       // deg-C
/*MT6176*/ #define  LTE_Band6_TPBF_PWR_THRES_SetDefault     (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band6_TPBF_APT_MODE_SetDefault       32       // 1/32dB
/*MT6176*/ #define  LTE_Band6_TPBF_ET_MODE_SetDefault        16       // 1/32dB
/*MT6176*/ #define  LTE_Band6_TPBF_DPD_MODE_SetDefault       16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND7 Start ----------------------*/
/*MT6176*/ #define  LTE_Band7_TPBF_TEMP_THRES_SetDefault     65       // deg-C
/*MT6176*/ #define  LTE_Band7_TPBF_PWR_THRES_SetDefault     (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band7_TPBF_APT_MODE_SetDefault       32       // 1/32dB
/*MT6176*/ #define  LTE_Band7_TPBF_ET_MODE_SetDefault        16       // 1/32dB
/*MT6176*/ #define  LTE_Band7_TPBF_DPD_MODE_SetDefault       16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND8 Start ----------------------*/
/*MT6176*/ #define  LTE_Band8_TPBF_TEMP_THRES_SetDefault     65       // deg-C
/*MT6176*/ #define  LTE_Band8_TPBF_PWR_THRES_SetDefault     (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band8_TPBF_APT_MODE_SetDefault       32       // 1/32dB
/*MT6176*/ #define  LTE_Band8_TPBF_ET_MODE_SetDefault        16       // 1/32dB
/*MT6176*/ #define  LTE_Band8_TPBF_DPD_MODE_SetDefault       16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND12 Start ---------------------*/
/*MT6176*/ #define  LTE_Band12_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band12_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band12_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band12_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band12_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND13 Start ---------------------*/
/*MT6176*/ #define  LTE_Band13_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band13_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band13_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band13_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band13_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND17 Start ---------------------*/
/*MT6176*/ #define  LTE_Band17_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band17_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band17_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band17_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band17_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND20 Start ---------------------*/
/*MT6176*/ #define  LTE_Band20_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band20_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band20_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band20_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band20_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND26 Start ---------------------*/
/*MT6176*/ #define  LTE_Band26_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band26_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band26_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band26_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band26_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND28 Start ---------------------*/
/*MT6176*/ #define  LTE_Band28_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band28_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band28_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band28_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band28_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND29 Start ---------------------*/
/*MT6176*/ #define  LTE_Band29_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band29_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band29_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band29_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band29_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND30 Start ---------------------*/
/*MT6176*/ #define  LTE_Band30_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band30_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band30_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band30_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band30_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND38 Start ---------------------*/
/*MT6176*/ #define  LTE_Band38_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band38_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band38_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band38_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band38_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND39 Start ---------------------*/
/*MT6176*/ #define  LTE_Band39_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band39_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band39_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band39_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band39_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND40 Start ---------------------*/
/*MT6176*/ #define  LTE_Band40_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band40_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band40_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band40_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band40_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/ //* --------------- BAND41 Start ---------------------*/
/*MT6176*/ #define  LTE_Band41_TPBF_TEMP_THRES_SetDefault    65       // deg-C
/*MT6176*/ #define  LTE_Band41_TPBF_PWR_THRES_SetDefault    (19*32)   // 1/32dB
/*MT6176*/ #define  LTE_Band41_TPBF_APT_MODE_SetDefault      32       // 1/32dB
/*MT6176*/ #define  LTE_Band41_TPBF_ET_MODE_SetDefault       16       // 1/32dB
/*MT6176*/ #define  LTE_Band41_TPBF_DPD_MODE_SetDefault      16       // 1/32dB
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*-----------------------------------*/
/*MT6176*/ /* Definition for the band splitting */
/*MT6176*/ /*-----------------------------------*/
/*MT6176*/
/*MT6176*/ // How to set the band-splitting frequency?
/*MT6176*/ // For example, the DL frequencies of the 1st and 2nd sub-bands are 758~780.4MHz and 780.5~802.9MHz, so we define
/*MT6176*/ // BAND_SPLIT_INDICATOR1_DL_END1 as 7805 [ = (780.4+0.1)*10 ]
/*MT6176*/ // BAND_SPLIT_INDICATOR1_DL_END2 as 8030 [ = (802.9+0.1)*10 ]
/*MT6176*/
/*MT6176*/ // [Note]
/*MT6176*/ // 1. The unit for the frequency definition is 100kHz
/*MT6176*/ // 2. BAND_SPLIT_INDICATOR1_DL_ENDn defines the end DL frequency of each part of splitting band PLUS 0.1 MHz
/*MT6176*/ // 3. Since there are only TWO sub-bands, BAND_SPLIT_INDICATOR1_DL_END3 should be 0
/*MT6176*/ // 4. The way to define the UL frequency is the same as the way DL does
/*MT6176*/
/*MT6176*/ /*-------------------------*/
/*MT6176*/ /* 0th Split Band Settings */
/*MT6176*/ /*-------------------------*/
/*MT6176*/ #define  BAND_SPLIT_INDICATOR0_SetDefault          LTE_Band28
/*MT6176*/ #define  BAND_SPLIT_INDICATOR0_NUM_SetDefault      2   // the num of part of splitting band
/*MT6176*/ #define  BAND_SPLIT_INDICATOR0_DL_END1_SetDefault  7805   // the end DL frequency of the 1st part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR0_DL_END2_SetDefault  8030   // the end DL frequency of the 2nd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR0_DL_END3_SetDefault  0   // the end DL frequency of the 3rd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split or only two parts are split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR0_UL_END1_SetDefault  7255   // the end UL frequency of the 1st part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR0_UL_END2_SetDefault  7480   // the end UL frequency of the 2nd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR0_UL_END3_SetDefault  0   // the end UL frequency of the 3rd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split or only two parts are split
/*MT6176*/
/*MT6176*/ /*-------------------------*/
/*MT6176*/ /* 1st Split Band Settings */
/*MT6176*/ /*-------------------------*/
/*MT6176*/ #define  BAND_SPLIT_INDICATOR1_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_SPLIT_INDICATOR1_NUM_SetDefault      0   // the num of part of splitting band
/*MT6176*/ #define  BAND_SPLIT_INDICATOR1_DL_END1_SetDefault  0   // the end DL frequency of the 1st part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR1_DL_END2_SetDefault  0   // the end DL frequency of the 2nd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR1_DL_END3_SetDefault  0   // the end DL frequency of the 3rd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split or only two parts are split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR1_UL_END1_SetDefault  0   // the end UL frequency of the 1st part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR1_UL_END2_SetDefault  0   // the end UL frequency of the 2nd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR1_UL_END3_SetDefault  0   // the end UL frequency of the 3rd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split or only two parts are split
/*MT6176*/
/*MT6176*/ /*-------------------------*/
/*MT6176*/ /* 2nd Split Band Settings */
/*MT6176*/ /*-------------------------*/
/*MT6176*/ #define  BAND_SPLIT_INDICATOR2_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_SPLIT_INDICATOR2_NUM_SetDefault      0   // the num of part of splitting band
/*MT6176*/ #define  BAND_SPLIT_INDICATOR2_DL_END1_SetDefault  0   // the end DL frequency of the 1st part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR2_DL_END2_SetDefault  0   // the end DL frequency of the 2nd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR2_DL_END3_SetDefault  0   // the end DL frequency of the 3rd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split or only two parts are split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR2_UL_END1_SetDefault  0   // the end UL frequency of the 1st part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR2_UL_END2_SetDefault  0   // the end UL frequency of the 2nd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR2_UL_END3_SetDefault  0   // the end UL frequency of the 3rd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split or only two parts are split
/*MT6176*/
/*MT6176*/ /*-------------------------*/
/*MT6176*/ /* 3rd Split Band Settings */
/*MT6176*/ /*-------------------------*/
/*MT6176*/ #define  BAND_SPLIT_INDICATOR3_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_SPLIT_INDICATOR3_NUM_SetDefault      0   // the num of part of splitting band
/*MT6176*/ #define  BAND_SPLIT_INDICATOR3_DL_END1_SetDefault  0   // the end DL frequency of the 1st part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR3_DL_END2_SetDefault  0   // the end DL frequency of the 2nd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR3_DL_END3_SetDefault  0   // the end DL frequency of the 3rd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split or only two parts are split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR3_UL_END1_SetDefault  0   // the end UL frequency of the 1st part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR3_UL_END2_SetDefault  0   // the end UL frequency of the 2nd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR3_UL_END3_SetDefault  0   // the end UL frequency of the 3rd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split or only two parts are split
/*MT6176*/
/*MT6176*/ /*-------------------------*/
/*MT6176*/ /* 4th Split Band Settings */
/*MT6176*/ /*-------------------------*/
/*MT6176*/ #define  BAND_SPLIT_INDICATOR4_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_SPLIT_INDICATOR4_NUM_SetDefault      0 // the num of part of splitting band
/*MT6176*/ #define  BAND_SPLIT_INDICATOR4_DL_END1_SetDefault  0 // the end DL frequency of the 1st part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR4_DL_END2_SetDefault  0 // the end DL frequency of the 2nd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR4_DL_END3_SetDefault  0 // the end DL frequency of the 3rd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split or only two parts are split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR4_UL_END1_SetDefault  0 // the end UL frequency of the 1st part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR4_UL_END2_SetDefault  0 // the end UL frequency of the 2nd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split
/*MT6176*/ #define  BAND_SPLIT_INDICATOR4_UL_END3_SetDefault  0 // the end UL frequency of the 3rd part of splitting band PLUS 0.1MHz, unit: 100KHz, set to 0 if no part is split or only two parts are split
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* B28-2 Split Band Settings */
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band28_2_RX_IO_SEL_SetDefault      RX_IO_PRX5
/*MT6176*/ #define  LTE_Band28_2_RXD_IO_SEL_SetDefault     RX_IO_DRX4
/*MT6176*/ #define  LTE_Band28_2_TX_IO_SEL_SetDefault      TX_IO_LB4
/*MT6176*/ #define  LTE_Band28_2_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band28_2_PR1_SetDefault      0x000CC000 //ANT
/*MT6176*/ #define  PDATA_LTE_Band28_2_PR2_SetDefault      0x000CC000 //ANT
/*MT6176*/ #define  PDATA_LTE_Band28_2_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band28_2_PT1_SetDefault      0x000CC000 //ANT
/*MT6176*/ #define  PDATA_LTE_Band28_2_PT2_SetDefault      0x000CC000 //ANT
/*MT6176*/ #define  PDATA_LTE_Band28_2_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* B28-3 Split Band Settings */
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band28_3_RX_IO_SEL_SetDefault      RX_IO_NON_USED
/*MT6176*/ #define  LTE_Band28_3_RXD_IO_SEL_SetDefault     RXD_IO_NON_USED
/*MT6176*/ #define  LTE_Band28_3_TX_IO_SEL_SetDefault      TX_IO_NON_USED
/*MT6176*/ #define  LTE_Band28_3_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band28_3_PR1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band28_3_PR2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band28_3_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band28_3_PT1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band28_3_PT2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band28_3_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* B38-2 Split Band Settings */
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band38_2_RX_IO_SEL_SetDefault      RX_IO_NON_USED
/*MT6176*/ #define  LTE_Band38_2_RXD_IO_SEL_SetDefault     RXD_IO_NON_USED
/*MT6176*/ #define  LTE_Band38_2_TX_IO_SEL_SetDefault      TX_IO_NON_USED
/*MT6176*/ #define  LTE_Band38_2_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band38_2_PR1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band38_2_PR2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band38_2_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band38_2_PT1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band38_2_PT2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band38_2_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* B38-3 Split Band Settings */
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band38_3_RX_IO_SEL_SetDefault      RX_IO_NON_USED
/*MT6176*/ #define  LTE_Band38_3_RXD_IO_SEL_SetDefault     RXD_IO_NON_USED
/*MT6176*/ #define  LTE_Band38_3_TX_IO_SEL_SetDefault      TX_IO_NON_USED
/*MT6176*/ #define  LTE_Band38_3_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band38_3_PR1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band38_3_PR2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band38_3_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band38_3_PT1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band38_3_PT2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band38_3_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* B40-2 Split Band Settings */
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band40_2_RX_IO_SEL_SetDefault      RX_IO_NON_USED
/*MT6176*/ #define  LTE_Band40_2_RXD_IO_SEL_SetDefault     RXD_IO_NON_USED
/*MT6176*/ #define  LTE_Band40_2_TX_IO_SEL_SetDefault      TX_IO_NON_USED
/*MT6176*/ #define  LTE_Band40_2_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band40_2_PR1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band40_2_PR2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band40_2_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band40_2_PT1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band40_2_PT2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band40_2_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* B40-3 Split Band Settings */
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band40_3_RX_IO_SEL_SetDefault      RX_IO_NON_USED
/*MT6176*/ #define  LTE_Band40_3_RXD_IO_SEL_SetDefault     RXD_IO_NON_USED
/*MT6176*/ #define  LTE_Band40_3_TX_IO_SEL_SetDefault      TX_IO_NON_USED
/*MT6176*/ #define  LTE_Band40_3_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band40_3_PR1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band40_3_PR2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band40_3_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band40_3_PT1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band40_3_PT2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band40_3_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* B41-2 Split Band Settings */
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band41_2_RX_IO_SEL_SetDefault      RX_IO_NON_USED
/*MT6176*/ #define  LTE_Band41_2_RXD_IO_SEL_SetDefault     RXD_IO_NON_USED
/*MT6176*/ #define  LTE_Band41_2_TX_IO_SEL_SetDefault      TX_IO_NON_USED
/*MT6176*/ #define  LTE_Band41_2_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band41_2_PR1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band41_2_PR2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band41_2_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band41_2_PT1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band41_2_PT2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band41_2_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* B41-3 Split Band Settings */
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band41_3_RX_IO_SEL_SetDefault      RX_IO_NON_USED
/*MT6176*/ #define  LTE_Band41_3_RXD_IO_SEL_SetDefault     RXD_IO_NON_USED
/*MT6176*/ #define  LTE_Band41_3_TX_IO_SEL_SetDefault      TX_IO_NON_USED
/*MT6176*/ #define  LTE_Band41_3_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band41_3_PR1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band41_3_PR2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band41_3_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band41_3_PT1_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band41_3_PT2_SetDefault      0
/*MT6176*/ #define  PDATA_LTE_Band41_3_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*----------------------------*/
/*MT6176*/ /* Definition for bypass mode */
/*MT6176*/ /*----------------------------*/
/*MT6176*/
/*MT6176*/ /*----------------------------------*/
/*MT6176*/ /* 0th Band Setting for bypass mode */
/*MT6176*/ /*----------------------------------*/
/*MT6176*/ #define  BAND_BYPASS_INDICATOR0_SetDefault               LTE_Band38
/*MT6176*/ #define  BAND_BYPASS_INDICATOR0_POWER_COMP_SetDefault    512 // It is the real HW power difference between bypass path and filter path, Unit: S(6,8) dB
/*MT6176*/                                                              // If bypass > filter by 1.5dB, the value is  384 (= 1.5*256)
/*MT6176*/                                                              // If bypass < filter by 0.5dB, the value is -128 (=-0.5*256)
/*MT6176*/ #define  BAND_BYPASS_INDICATOR0_COUPLER_COMP_SetDefault  512 // It is the expected power difference between bypass path and filter path, Unit: S(6,8) dB
/*MT6176*/                                                              // If bypass > filter by 0.5dB, the value is  128 (= 0.5*256)
/*MT6176*/                                                              // If bypass < filter by 1.5dB, the value is -384 (=-1.5*256)
/*MT6176*/
/*MT6176*/ /*----------------------------------*/
/*MT6176*/ /* 1st Band Setting for bypass mode */
/*MT6176*/ /*----------------------------------*/
/*MT6176*/ #define  BAND_BYPASS_INDICATOR1_SetDefault               LTE_Band40
/*MT6176*/ #define  BAND_BYPASS_INDICATOR1_POWER_COMP_SetDefault    512 // It is the real HW power difference between bypass path and filter path, Unit: S(6,8) dB
/*MT6176*/                                                              // If bypass > filter by 1.5dB, the value is  384 (= 1.5*256)
/*MT6176*/                                                              // If bypass < filter by 0.5dB, the value is -128 (=-0.5*256)
/*MT6176*/ #define  BAND_BYPASS_INDICATOR1_COUPLER_COMP_SetDefault  512 // It is the expected power difference between bypass path and filter path, Unit: S(6,8) dB
/*MT6176*/                                                              // If bypass > filter by 0.5dB, the value is  128 (= 0.5*256)
/*MT6176*/                                                              // If bypass < filter by 1.5dB, the value is -384 (=-1.5*256)
/*MT6176*/
/*MT6176*/ /*----------------------------------*/
/*MT6176*/ /* 2nd Band Setting for bypass mode */
/*MT6176*/ /*----------------------------------*/
/*MT6176*/ #define  BAND_BYPASS_INDICATOR2_SetDefault               LTE_Band41
/*MT6176*/ #define  BAND_BYPASS_INDICATOR2_POWER_COMP_SetDefault    512 // It is the real HW power difference between bypass path and filter path, Unit: S(6,8) dB
/*MT6176*/                                                              // If bypass > filter by 1.5dB, the value is  384 (= 1.5*256)
/*MT6176*/                                                              // If bypass < filter by 0.5dB, the value is -128 (=-0.5*256)
/*MT6176*/ #define  BAND_BYPASS_INDICATOR2_COUPLER_COMP_SetDefault  512 // It is the expected power difference between bypass path and filter path, Unit: S(6,8) dB
/*MT6176*/                                                              // If bypass > filter by 0.5dB, the value is  128 (= 0.5*256)
/*MT6176*/                                                              // If bypass < filter by 1.5dB, the value is -384 (=-1.5*256)
/*MT6176*/
/*MT6176*/ /*----------------------------------*/
/*MT6176*/ /* 3rd Band Setting for bypass mode */
/*MT6176*/ /*----------------------------------*/
/*MT6176*/ #define  BAND_BYPASS_INDICATOR3_SetDefault               LTE_BandNone
/*MT6176*/ #define  BAND_BYPASS_INDICATOR3_POWER_COMP_SetDefault    0 // It is the real HW power difference between bypass path and filter path, Unit: S(6,8) dB
/*MT6176*/                                                            // If bypass > filter by 1.5dB, the value is  384 (= 1.5*256)
/*MT6176*/                                                            // If bypass < filter by 0.5dB, the value is -128 (=-0.5*256)
/*MT6176*/ #define  BAND_BYPASS_INDICATOR3_COUPLER_COMP_SetDefault  0 // It is the expected power difference between bypass path and filter path, Unit: S(6,8) dB
/*MT6176*/                                                            // If bypass > filter by 0.5dB, the value is  128 (= 0.5*256)
/*MT6176*/                                                            // If bypass < filter by 1.5dB, the value is -384 (=-1.5*256)
/*MT6176*/
/*MT6176*/ /*----------------------------------*/
/*MT6176*/ /* 4th Band Setting for bypass mode */
/*MT6176*/ /*----------------------------------*/
/*MT6176*/ #define  BAND_BYPASS_INDICATOR4_SetDefault               LTE_BandNone
/*MT6176*/ #define  BAND_BYPASS_INDICATOR4_POWER_COMP_SetDefault    0 // It is the real HW power difference between bypass path and filter path, Unit: S(6,8) dB
/*MT6176*/                                                            // If bypass > filter by 1.5dB, the value is  384 (= 1.5*256)
/*MT6176*/                                                            // If bypass < filter by 0.5dB, the value is -128 (=-0.5*256)
/*MT6176*/ #define  BAND_BYPASS_INDICATOR4_COUPLER_COMP_SetDefault  0 // It is the expected power difference between bypass path and filter path, Unit: S(6,8) dB
/*MT6176*/                                                            // If bypass > filter by 0.5dB, the value is  128 (= 0.5*256)
/*MT6176*/                                                            // If bypass < filter by 1.5dB, the value is -384 (=-1.5*256)
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* B38 Bypass Mode Settings */
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band38_BYPASS_RX_IO_SEL_SetDefault      RX_IO_PRX11
/*MT6176*/ #define  LTE_Band38_BYPASS_RXD_IO_SEL_SetDefault     RX_IO_DRX11
/*MT6176*/ #define  LTE_Band38_BYPASS_TX_IO_SEL_SetDefault      TX_IO_HB2
/*MT6176*/ #define  LTE_Band38_BYPASS_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band38_BYPASS_PR1_SetDefault      0x000C0000  //ANT Note: Don't care Rx on Bypass Mode
/*MT6176*/ #define  PDATA_LTE_Band38_BYPASS_PR2_SetDefault      0x000C0000  //ANT Note: Don't care Rx on Bypass Mode
/*MT6176*/ #define  PDATA_LTE_Band38_BYPASS_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band38_BYPASS_PT1_SetDefault      0x000C0000   //LPF path //ANT
/*MT6176*/ #define  PDATA_LTE_Band38_BYPASS_PT2_SetDefault      0x000C0000   //LPF path //ANT
/*MT6176*/ #define  PDATA_LTE_Band38_BYPASS_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* B40 Bypass Mode Settings */
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band40_BYPASS_RX_IO_SEL_SetDefault      RX_IO_PRX14
/*MT6176*/ #define  LTE_Band40_BYPASS_RXD_IO_SEL_SetDefault     RX_IO_DRX14
/*MT6176*/ #define  LTE_Band40_BYPASS_TX_IO_SEL_SetDefault      TX_IO_HB2
/*MT6176*/ #define  LTE_Band40_BYPASS_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band40_BYPASS_PR1_SetDefault      0x000C0000  //ANT Note: Don't care Rx on Bypass Mode
/*MT6176*/ #define  PDATA_LTE_Band40_BYPASS_PR2_SetDefault      0x000C0000  //ANT Note: Don't care Rx on Bypass Mode
/*MT6176*/ #define  PDATA_LTE_Band40_BYPASS_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band40_BYPASS_PT1_SetDefault      0x000C0000   //LPF path, switch to B41 PRX at B40 TX for B40 TX pulling issue //ANT
/*MT6176*/ #define  PDATA_LTE_Band40_BYPASS_PT2_SetDefault      0x000C0000   //LPF path, switch to B41 PRX at B40 TX for B40 TX pulling issue //ANT
/*MT6176*/ #define  PDATA_LTE_Band40_BYPASS_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* B41 Bypass Mode Settings */
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define  LTE_Band41_BYPASS_RX_IO_SEL_SetDefault      RX_IO_PRX11
/*MT6176*/ #define  LTE_Band41_BYPASS_RXD_IO_SEL_SetDefault     RX_IO_DRX11
/*MT6176*/ #define  LTE_Band41_BYPASS_TX_IO_SEL_SetDefault      TX_IO_HB2
/*MT6176*/ #define  LTE_Band41_BYPASS_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band41_BYPASS_PR1_SetDefault      0x000C0000  //ANT Note: Don't care Rx on Bypass Mode
/*MT6176*/ #define  PDATA_LTE_Band41_BYPASS_PR2_SetDefault      0x000C0000  //ANT Note: Don't care Rx on Bypass Mode
/*MT6176*/ #define  PDATA_LTE_Band41_BYPASS_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ // TX BPI Settings
/*MT6176*/ #define  PDATA_LTE_Band41_BYPASS_PT1_SetDefault      0x000C0000   //LPF path, switch to B41 PRX at B40 TX for B40 TX pulling issue //ANT
/*MT6176*/ #define  PDATA_LTE_Band41_BYPASS_PT2_SetDefault      0x000C0000   //LPF path, switch to B41 PRX at B40 TX for B40 TX pulling issue //ANT
/*MT6176*/ #define  PDATA_LTE_Band41_BYPASS_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176*/
/*MT6176*/ /*----------------------------------------------------------------------*/
/*MT6176*/ /*  BAND_PARTIAL_INDICATOR_SetDefault*/
/*MT6176*/ /*----------------------------------------------------------------------*/
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR0_SetDefault   LTE_BandNone
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR1_SetDefault   LTE_BandNone
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR2_SetDefault   LTE_BandNone
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR3_SetDefault   LTE_BandNone
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR4_SetDefault   LTE_BandNone
/*MT6176*/
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ /*  Define frequency range for partial band             */
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/
/*MT6176*/ //  Supported freq range for 0th partial band  
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR0_START_SetDefault   BAND_PARTIAL_START_INV  /*100 kHz*/
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR0_END_SetDefault     BAND_PARTIAL_END_INV    /*100 kHz*/
/*MT6176*/
/*MT6176*/ //  Supported freq range for 1th partial band  
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR1_START_SetDefault   BAND_PARTIAL_START_INV
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR1_END_SetDefault     BAND_PARTIAL_END_INV
/*MT6176*/
/*MT6176*/ //  Supported freq range for 2th partial band  
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR2_START_SetDefault   BAND_PARTIAL_START_INV
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR2_END_SetDefault     BAND_PARTIAL_END_INV
/*MT6176*/
/*MT6176*/ //  Supported freq range for 3th partial band  
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR3_START_SetDefault   BAND_PARTIAL_START_INV
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR3_END_SetDefault     BAND_PARTIAL_END_INV
/*MT6176*/
/*MT6176*/ //  Supported freq range for 4th partial band  
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR4_START_SetDefault   BAND_PARTIAL_START_INV
/*MT6176*/ #define  BAND_PARTIAL_INDICATOR4_END_SetDefault     BAND_PARTIAL_END_INV
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/#if defined(__TAS_SUPPORT__)
/*MT6176*/ #define  LTE_TAS_ENA_SetDefault                  0  //1/0: enable/disable the transmit antenna selection control
/*MT6176*/#else
/*MT6176*/ #define  LTE_TAS_ENA_SetDefault                  0  //1/0: enable/disable the transmit antenna selection control
/*MT6176*/#endif
/*MT6176*/ #define  LTE_TAS_WITH_TEST_SIM_ENA_SetDefault    0  //1/0: enable/disable the transmit antenna selection control when the test sim is inserted
/*MT6176*/
/*MT6176*/ #define  LTE_TAS_PIN1_SetDefault                 LTE_TAS_PIN_NULL //the 1st BPI pin number for the transmit antenna selection control
/*MT6176*/ #define  LTE_TAS_PIN2_SetDefault                 LTE_TAS_PIN_NULL //the 2nd BPI pin number for the transmit antenna selection control
/*MT6176*/ #define  LTE_TAS_PIN3_SetDefault                 LTE_TAS_PIN_NULL //the 3rd BPI pin number for the transmit antenna selection control
/*MT6176*/ #define  LTE_TAS_PIN4_SetDefault                 LTE_TAS_PIN_NULL //the 4th BPI pin number for the transmit antenna selection control
/*MT6176*/
/*MT6176*/ #define  LTE_TAS_MASK_SetDefault                 LTE_TAS_BPI_PIN_GEN(1,1,1,1,SetDefault)
/*MT6176*/ #define  LTE_TAS_INIT_ANT_SetDefault             0  //the initial TAS index, 0   : the settings of PDATA_LTE_Bandx_Pxx (the original ones)
/*MT6176*/                                                     //                       1~15: the settings of PDATA_LTE_Bandx_TAS1~7
/*MT6176*/ #define  LTE_FORCE_TX_ANTENNA_ENABLE_SetDefault  0  //Force the antenna index or not
/*MT6176*/ #define  LTE_FORCE_TX_ANTENNA_IDX_SetDefault     0  //Force to which antenna index
/*MT6176*/
/*MT6176*//*--------------------------------------------------------------------*/
/*MT6176*//*  BAND_TAS_INDICATOR0_SetDefault ~ BAND_TAS_INDICATOR20_SetDefault  */
/*MT6176*//*--------------------------------------------------------------------*/
/*MT6176*/ #define  BAND_TAS_INDICATOR0_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR1_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR2_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR3_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR4_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR5_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR6_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR7_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR8_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR9_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR10_SetDefault         LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR11_SetDefault         LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR12_SetDefault         LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR13_SetDefault         LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR14_SetDefault         LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR15_SetDefault         LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR16_SetDefault         LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR17_SetDefault         LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR18_SetDefault         LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR19_SetDefault         LTE_BandNone
/*MT6176*/ #define  BAND_TAS_INDICATOR20_SetDefault         LTE_BandNone
/*MT6176*/
/*MT6176*///LTE_TAS_BPI_PIN_GEN(var1, var2, var3, var4, SetX) => use to generate the transmit antenna selection BPI control logic
/*MT6176*///                                                     var1: the value (1 or 0) for the 1st transmit antenna selection BPI pin (LTE_TAS_PIN1)
/*MT6176*///                                                     var2: the value (1 or 0) for the 2nd transmit antenna selection BPI pin (LTE_TAS_PIN2)
/*MT6176*///                                                     var3: the value (1 or 0) for the 3rd transmit antenna selection BPI pin (LTE_TAS_PIN3)
/*MT6176*///                                                     var4: the value (1 or 0) for the 3rd transmit antenna selection BPI pin (LTE_TAS_PIN4)
/*MT6176*///                                                     SetX: the DRDI set index
/*MT6176*/
/*MT6176*///* ------------- PDATA_BAND1_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band1_TAS1_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS2_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS3_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS4_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS5_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS6_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS7_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS8_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS9_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS10_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS11_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS12_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS13_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS14_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band1_TAS15_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND2_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band2_TAS1_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS2_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS3_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS4_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS5_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS6_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS7_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS8_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS9_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS10_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS11_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS12_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS13_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS14_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band2_TAS15_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND3_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band3_TAS1_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS2_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS3_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS4_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS5_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS6_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS7_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS8_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS9_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS10_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS11_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS12_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS13_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS14_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band3_TAS15_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND4_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band4_TAS1_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS2_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS3_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS4_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS5_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS6_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS7_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS8_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS9_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS10_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS11_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS12_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS13_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS14_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band4_TAS15_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND5_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band5_TAS1_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS2_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS3_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS4_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS5_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS6_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS7_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS8_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS9_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS10_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS11_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS12_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS13_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS14_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band5_TAS15_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND7_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band7_TAS1_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS2_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS3_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS4_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS5_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS6_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS7_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS8_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS9_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS10_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS11_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS12_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS13_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS14_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band7_TAS15_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND8_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band8_TAS1_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS2_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS3_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS4_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS5_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS6_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS7_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS8_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS9_SetDefault         LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS10_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS11_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS12_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS13_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS14_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band8_TAS15_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND20_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band20_TAS1_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS2_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS3_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS4_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS5_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS6_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS7_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS8_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS9_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS10_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS11_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS12_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS13_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS14_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band20_TAS15_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND26_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band26_TAS1_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS2_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS3_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS4_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS5_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS6_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS7_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS8_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS9_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS10_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS11_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS12_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS13_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS14_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band26_TAS15_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND28_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band28_TAS1_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS2_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS3_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS4_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS5_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS6_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS7_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS8_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS9_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS10_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS11_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS12_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS13_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS14_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band28_TAS15_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND38_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band38_TAS1_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS2_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS3_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS4_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS5_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS6_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS7_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS8_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS9_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS10_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS11_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS12_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS13_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS14_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band38_TAS15_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND39_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band39_TAS1_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS2_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS3_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS4_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS5_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS6_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS7_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS8_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS9_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS10_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS11_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS12_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS13_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS14_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band39_TAS15_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND40_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band40_TAS1_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS2_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS3_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS4_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS5_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS6_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS7_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS8_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS9_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS10_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS11_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS12_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS13_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS14_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band40_TAS15_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*///* ------------- PDATA_BAND41_TAS_SetDefault Start ----------------*/
/*MT6176*/ #define  PDATA_LTE_Band41_TAS1_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS2_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS3_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS4_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS5_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS6_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS7_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS8_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS9_SetDefault        LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS10_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS11_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS12_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS13_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS14_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*MT6176*/ #define  PDATA_LTE_Band41_TAS15_SetDefault       LTE_TAS_BPI_PIN_GEN(0, 0, 0, 0, SetDefault)
/*============================================================================== */
/*MT6176*/#if IS_4G_HPUE_FEATURE_SUPPORT
/*MT6176*/ #define  LTE_HPUE_ENA_SetDefault                  0  //1/0: enable/disable HPUE FEATURE
/*MT6176*/#else
/*MT6176*/ #define  LTE_HPUE_ENA_SetDefault                  0  //1/0: enable/disable HPUE FEATURE
/*MT6176*/#endif
/*MT6176*//*--------------------------------------------------------------------*/
/*MT6176*//*  BAND_HPUE_INDICATOR0_SetDefault ~ BAND_HPUE_INDICATOR2_SetDefault  */
/*MT6176*//*--------------------------------------------------------------------*/
/*MT6176*/ #define  BAND_HPUE_INDICATOR0_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_HPUE_INDICATOR1_SetDefault          LTE_BandNone
/*MT6176*/ #define  BAND_HPUE_INDICATOR2_SetDefault          LTE_BandNone

/*---------------------------------------------------------------------------------------------*/
/* This following part serves as default value of undefined macro constants in lte_custom_rf.h */
/* DO NOT MODIFY!!!                                                                            */
/*---------------------------------------------------------------------------------------------*/
/*MT6176 (Do NOT Modify!!!*/
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_PR1_SetDefault             LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_PR2_SetDefault             LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_PR3_SetDefault             LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_PT1_SetDefault             LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_PT2_SetDefault             LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_PT3_SetDefault             LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_PRANT_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_PTANT_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_2_PR1_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_2_PR2_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_2_PR3_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_2_PT1_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_2_PT2_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_2_PT3_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_3_PR1_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_3_PR2_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_3_PR3_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_3_PT1_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_3_PT2_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_3_PT3_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_BYPASS_PR1_SetDefault      LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_BYPASS_PR2_SetDefault      LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_BYPASS_PR3_SetDefault      LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_BYPASS_PT1_SetDefault      LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_BYPASS_PT2_SetDefault      LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_BYPASS_PT3_SetDefault      LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ 
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS1_SetDefault            LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS2_SetDefault            LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS3_SetDefault            LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS4_SetDefault            LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS5_SetDefault            LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS6_SetDefault            LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS7_SetDefault            LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS8_SetDefault            LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS9_SetDefault            LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS10_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS11_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS12_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS13_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS14_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ #define  PDATA_LTE_BandNone_TAS15_SetDefault           LTE_PDATA_OFF
/*MT6176 (Do NOT Modify!!!*/ 
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_RX_IO_SEL_SetDefault             RX_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_RXD_IO_SEL_SetDefault            RXD_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_TX_IO_SEL_SetDefault             TX_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_TX_DET_IO_SEL_SetDefault         TX_DET_IO_DET1
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_2_RX_IO_SEL_SetDefault           RX_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_2_RXD_IO_SEL_SetDefault          RXD_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_2_TX_IO_SEL_SetDefault           TX_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_2_TX_DET_IO_SEL_SetDefault       TX_DET_IO_DET1
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_3_RX_IO_SEL_SetDefault           RX_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_3_RXD_IO_SEL_SetDefault          RXD_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_3_TX_IO_SEL_SetDefault           TX_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_3_TX_DET_IO_SEL_SetDefault       TX_DET_IO_DET1
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_BYPASS_RX_IO_SEL_SetDefault      RX_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_BYPASS_RXD_IO_SEL_SetDefault     RXD_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_BYPASS_TX_IO_SEL_SetDefault      TX_IO_NON_USED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_BYPASS_TX_DET_IO_SEL_SetDefault  TX_DET_IO_DET1
/*MT6176 (Do NOT Modify!!!*/ 
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_MPR_QPSK1_SetDefault             0
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_MPR_16QAM0_SetDefault            0
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_MPR_16QAM1_SetDefault            0
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_MPR_64QAM0_SetDefault            0
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_MPR_64QAM1_SetDefault            0
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_DELTA_TC0_SetDefault             0
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_DELTA_TC1_SetDefault             0
/*MT6176 (Do NOT Modify!!!*/ 
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_BandNone_VPA_SOURCE_SetDefault            VPA_SOURCE_NOT_SUPPORTED
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_MIPI_TOOL_VER     0

#endif /* _LTE_CUSTOM_RF_SetDefault_H_ */
