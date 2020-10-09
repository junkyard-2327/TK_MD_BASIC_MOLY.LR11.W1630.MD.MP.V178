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
 *   mml1_custom_rf.h
 *
 * Project:
 * --------
 *   MT6755
 *
 * Description:
 * ------------
 *   MT6755 Multi-Mode Multi-RAT L1 constance definition
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *******************************************************************************/

#ifndef  _MML1_CUSTOM_RF_H_Set0_
#define  _MML1_CUSTOM_RF_H_Set0_

/* --------------------------------------------------------------------------- */
/*MT6755*/
/*MT6755*/ /*----------------------------------------------------*/
/*MT6755*/ /*  Enable or disable the clock1, 2, 3, and 4 output  */
/*MT6755*/ /*  1 : Enable                                        */
/*MT6755*/ /*  0 : Disable                                       */
/*MT6755*/ /*----------------------------------------------------*/
/*MT6755*/ #define MML1_CLK1_EN_Set0                         1 /* CLK1 is enabled for BB */
/*MT6755*/ #define MML1_CLK2_EN_Set0                         0
/*MT6755*/ #define MML1_CLK3_EN_Set0                         1
/*MT6755*/ #define MML1_CLK4_EN_Set0                         1
/*MT6755*/
/*MT6755*/ /*----------------------------------------------------*/
/*MT6755*/ /*  Config the clock buffer driving for XO1,2,3,4     */
/*MT6755*/ /*  0 : 0.4mA (loading :  <10pF)                      */
/*MT6755*/ /*  1 : 0.9mA (loading :10~20pF)                      */
/*MT6755*/ /*  2 : 1.4mA (loading :20~30pF) (default)            */
/*MT6755*/ /*  3 : 1.9mA (loading :  >30pF)                      */
/*MT6755*/ /*----------------------------------------------------*/
/*MT6755*/ #define MML1_CLK1_DRIVING_Set0                    2
/*MT6755*/ #define MML1_CLK2_DRIVING_Set0                    2
/*MT6755*/ #define MML1_CLK3_DRIVING_Set0                    2
/*MT6755*/ #define MML1_CLK4_DRIVING_Set0                    2
/*MT6755*/
/*MT6755*/ /*----------------------------------------------------*/
/*MT6755*/ /*  RX IQ Swap Option :                               */
/*MT6755*/ /*  1 : Enable                                        */
/*MT6755*/ /*  0 : Disable                                       */
/*MT6755*/ /*----------------------------------------------------*/
/*MT6755*/ /*  Naming Rule for PRX (Main), DRX (Diversity)       */
/*MT6755*/ /*              for  RX1(Primary CC)                  */
/*MT6755*/ /*                   RX2(Secondary CC)                */
/*MT6755*/ /*                   RXn(n-th CC)                     */ 
/*MT6755*/ /*----------------------------------------------------*/
/*MT6755*/ #define PRX1_IQ_SWAP_EN_Set0                      0
/*MT6755*/ #define DRX1_IQ_SWAP_EN_Set0                      0
/*MT6755*/
/*MT6755*/ #define PRX2_IQ_SWAP_EN_Set0                      0
/*MT6755*/ #define DRX2_IQ_SWAP_EN_Set0                      0
/*MT6755*/
/*MT6755*/ /*----------------------------------------------------*/
/*MT6755*/ /*  RX IQ Inverse Option :                            */
/*MT6755*/ /*  1 : Enable                                        */
/*MT6755*/ /*  0 : Disable                                       */
/*MT6755*/ /*----------------------------------------------------*/
/*MT6755*/ /*  Naming Rule for PRX (Main), DRX (Diversity)       */
/*MT6755*/ /*              for  RX1(Primary CC)                  */
/*MT6755*/ /*                   RX2(Secondary CC)                */
/*MT6755*/ /*                   RXn(n-th CC)                     */ 
/*MT6755*/ /*----------------------------------------------------*/
/*MT6755*/ #define PRX1_I_INV_EN_Set0                        0
/*MT6755*/ #define PRX1_Q_INV_EN_Set0                        0
/*MT6755*/ #define DRX1_I_INV_EN_Set0                        0
/*MT6755*/ #define DRX1_Q_INV_EN_Set0                        0
/*MT6755*/
/*MT6755*/ #define PRX2_I_INV_EN_Set0                        0
/*MT6755*/ #define PRX2_Q_INV_EN_Set0                        0
/*MT6755*/ #define DRX2_I_INV_EN_Set0                        0
/*MT6755*/ #define DRX2_Q_INV_EN_Set0                        0
/*MT6755*/
/*MT6755*/ /*-----------------------------------------------------------------------*/
/*MT6755*/ /*  Enable or disable the Crystal on PMIC feature                        */
/*MT6755*/ /*  It shall only for MT6176 RF, the following RF shall be always Enable */
/*MT6755*/ /*  1 : Enable                                                           */
/*MT6755*/ /*  0 : Disable (default)                                                */
/*MT6755*/ /*-----------------------------------------------------------------------*/
/*MT6755*/ #define MML1_CRYSTAL_ON_PMIC_EN              0
/*MT6755*/
/*MT6755*/ /*SWTP feature*/
/*MT6755*/ #define MML1_MANUAL_EN_Set0                0
/*MT6755*/ #define MML1_SWTP_EN_Set0                  0
/*MT6755*/ #define GSM_TABLE_IDX_Set0                 0
/*MT6755*/ #define WCDMA_TABLE_IDX_Set0               0
/*MT6755*/ #define TDSCDMA_TABLE_IDX_Set0             0
/*MT6755*/ #define LTE_TABLE_IDX_Set0                 0
/*MT6755*/ #define C2K_TABLE_IDX_Set0                 0
/* --------------------------------------------------------------------------- */
#endif

