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
 *   l1d_custom_rf.h
 *
 * Project:
 * --------
 *   MT6176
 *
 * Description:
 * ------------
 *   MT6176 2G RF constance definition
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *******************************************************************************/

#ifndef  _L1D_CUSTOM_RF_H_SetDefault_
#define  _L1D_CUSTOM_RF_H_SetDefault_
/* --------------------------------------------------------------------------- */
#include "l1d_public.h"

#if !defined(MT6176_2G_RF)
   #error "rf files mismatch with compile option!"
#endif

   #if IS_MIPI_SUPPORT
#include "l1d_custom_mipi.h"
   #endif

/*--------------------------------------------------------*/
/*   Event Timing Define                                  */
/*--------------------------------------------------------*/
/*MT6176*/ #define  QB_SR1_SetDefault               173
/*MT6176*/ #define  QB_SR2_SetDefault               58
/*MT6176*/ #define  QB_SR2M_SetDefault              39
/*MT6176*/ #define  QB_SR3_SetDefault               2//5    /* SR3 should be larger than (QB_RX_FSYNC_2_FENA+2QB) */
/*MT6176*/ #define  QB_PR1_SetDefault               175  /* QB_PR1>QB_SR0 to prevent RF conflict among 2/3G    */
/*MT6176*/ #define  QB_PR2_SetDefault               50
/*MT6176*/ #define  QB_PR3_SetDefault               7
/*MT6176*/ #define  QB_ST1_SetDefault               255
/*MT6176*/ #define  QB_ST2B_SetDefault              38   /* ST2B should be larger  than (QB_TX_FENA_2_FSYNC+8QB)*/
/*MT6176*/ #define  QB_ST3_SetDefault               38   /* ST3  should be larger  than (QB_TX_FSYNC_2_FENA+7QB)*/
/*MT6176*/ #define  QB_PT1_SetDefault               257  /* QB_PT1>QB_ST1 to prevent RF conflict among 2/3G     */
/*MT6176*/ #define  QB_PT2_SetDefault               56
/*MT6176*/ #define  QB_PT2B_SetDefault              6
/*MT6176*/ #define  QB_PT3_SetDefault               30
/*MT6176*/ #define  QB_PT3A_SetDefault              40
/*MT6176*/ #define  QB_ST2M_G8_SetDefault           4
/*MT6176*/ #define  QB_ST2M_8G_SetDefault           4
/*MT6176*/ #define  QB_PT2M1_G8_SetDefault          -1
/*MT6176*/ #define  QB_PT2M2_G8_SetDefault          -3
/*MT6176*/ #define  QB_PT2M1_8G_SetDefault          10
/*MT6176*/ #define  QB_PT2M2_8G_SetDefault          4
/*MT6176*/
/*MT6176*/
/*MT6176*/ #define  QB_APCON_SetDefault             13 //OH:11
/*MT6176*/ #define  QB_APCMID_SetDefault            15 //OH:18
/*MT6176*/ #define  QB_APCOFF_SetDefault            12  //56: 6
/*MT6176*/ #if IS_2G_MIPI_ENABLE_SetDefault
/*MT6176*/ #define  QB_APCDACON_SetDefault          25 //0/*MIPI ENABLE*/
/*MT6176*/ #else
/*MT6176*/ #define  QB_APCDACON_SetDefault          18 //0/*MIPI DISABLE*/
/*MT6176*/ #endif
/*MT6176*/ #define  TX_PROPAGATION_DELAY_SetDefault 50 //6169:47 / OH:46
/*MT6176*/
/*MT6176*/ /*--------------------------------------------------*/
/*MT6176*/ /*   define  BPI data for MT6290                    */
/*MT6176*/ /*--------------------------------------------------*/
/*MT6176*/ /*  PRCB : bit   pin                                */
/*MT6176*/ /*         16    ANTENNA_CONFLICT_2G                */
/*MT6176*/ /*         17    SPI_SWITCH_TO_2G                   */
/*MT6176*/ /*         18    GSM_ERR_DET_ID                     */
/*MT6176*/ /*         19    SP3T_V1 TXOUT_B2B39 TXOUT_B7B38    */
/*MT6176*/ /*         20    SP3T_V2 W_PA_B7_EN                 */
/*MT6176*/ /*         21    ASM_VCTRL_A Main_V1                */
/*MT6176*/ /*         22    ASM_VCTRL_B Main_V2                */
/*MT6176*/ /*         23    ASM_VCTRL_C Main_V3                */
/*MT6176*/ /*         24    WG_GGE_PA_ENABLE                   */
/*MT6176*/ /*         29    GSM_ERR_DET_ID(7206_ERR_DETECT_2G) */
/*MT6176*/ /*         30    GSM_ERR_DET_ID(OGT_ERR_DETECT_2G)  */
/*MT6176*/ /*--------------------------------------------------*/
/*MT6176*/
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ /*  GSM_ERR_DET_ID(Pin:31) has no dedicate output pin,  */
/*MT6176*/ /*  and it is mapped to bit "31" for SW control.        */
/*MT6176*/ /*  For accurate RF conflict detection, this value must */
/*MT6176*/ /*  set "31" and is unchangable.                        */
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ #define  PDATA_GSM_ERR_DET_SetDefault      (0x80000000)
/*MT6176*/ #define  PDATA_TAS_DEFAULT_SetDefault      (0x000C0000)
/*MT6176*/ #define  PDATA_GMSK_SetDefault              0x00000000
/*MT6176*/
/*MT6176*/ #if IS_2G_MIPI_ENABLE_SetDefault
/*MT6176*/ #define  PDATA_8PSK_SetDefault              0x00000000                              /*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PR1_SetDefault       (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PR2_SetDefault       (0x00008000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PR3_SetDefault       (0x00000000                                               )/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PR1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PR2_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PR3_SetDefault          (0x00000000                                               )/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PR1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PR2_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PR3_SetDefault          (0x00000000                                               )/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PR1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PR2_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PR3_SetDefault          (0x00000000                                               )/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT1_SetDefault       (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2_SetDefault       (0x00008000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2B_SetDefault      (0x00008000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT3_SetDefault       (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT3A_SetDefault      (0x00000000                                               )/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2M1_G8_SetDefault  (0x00008000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2M2_G8_SetDefault  (0x00008000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2M1_8G_SetDefault  (0x00008000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2M2_8G_SetDefault  (0x00008000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PT1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2B_SetDefault         (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PT3_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PT3A_SetDefault         (0x00000000                                               )/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2M1_G8_SetDefault     (0x00000000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2M2_G8_SetDefault     (0x00000000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2M1_8G_SetDefault     (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2M2_8G_SetDefault     (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PT1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2B_SetDefault         (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PT3_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PT3A_SetDefault         (0x00000000                                               )/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2M1_G8_SetDefault     (0x00000000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2M2_G8_SetDefault     (0x00000000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2M1_8G_SetDefault     (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2M2_8G_SetDefault     (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PT1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2B_SetDefault         (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PT3_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PT3A_SetDefault         (0x00000000                                               )/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2M1_G8_SetDefault     (0x00000000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2M2_G8_SetDefault     (0x00000000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2M1_8G_SetDefault     (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2M2_8G_SetDefault     (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_INIT_SetDefault             (0x00000000                                               )/*MIPI ENABLE*/
/*MT6176*/ #define  PDATA_IDLE_SetDefault             (0x00000000                                               )/*MIPI ENABLE*/
/*MT6176*/ #else
/*MT6176*/ #define  PDATA_8PSK_SetDefault              0x00800000                              /*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PR1_SetDefault       (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PR2_SetDefault       (0x00408000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PR3_SetDefault       (0x00000000                                               )/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PR1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PR2_SetDefault          (0x00A00000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PR3_SetDefault          (0x00000000                                               )/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PR1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PR2_SetDefault          (0x00C00000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PR3_SetDefault         (0x00000000                                               )/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PR1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PR2_SetDefault          (0x00E00000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PR3_SetDefault         (0x00000000                                               )/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT1_SetDefault       (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2_SetDefault       (0x00208000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2B_SetDefault      (0x01208000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT3_SetDefault       (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT3A_SetDefault      (0x00000000                                               )/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2M1_G8_SetDefault  (0x01208000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2M2_G8_SetDefault  (0x01208000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2M1_8G_SetDefault  (0x00208000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM850_PT2M2_8G_SetDefault  (0x01208000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PT1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2_SetDefault          (0x00200000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2B_SetDefault         (0x01200000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PT3_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PT3A_SetDefault         (0x00000000                                               )/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2M1_G8_SetDefault     (0x01200000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2M2_G8_SetDefault     (0x01200000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2M1_8G_SetDefault     (0x00200000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_GSM_PT2M2_8G_SetDefault     (0x01200000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PT1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2_SetDefault          (0x00C00000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2B_SetDefault         (0x01600000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PT3_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PT3A_SetDefault         (0x00000000                                               )/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2M1_G8_SetDefault     (0x01600000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2M2_G8_SetDefault     (0x01600000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2M1_8G_SetDefault     (0x00600000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_DCS_PT2M2_8G_SetDefault     (0x01600000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PT1_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2_SetDefault          (0x00C00000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2B_SetDefault         (0x01600000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PT3_SetDefault          (0x00000000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PT3A_SetDefault         (0x00000000                                               )/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2M1_G8_SetDefault     (0x01600000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2M2_G8_SetDefault     (0x01600000|PDATA_8PSK_SetDefault|PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2M1_8G_SetDefault     (0x00600000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_PCS_PT2M2_8G_SetDefault     (0x01600000           |PDATA_GSM_ERR_DET_SetDefault|PDATA_TAS_DEFAULT_SetDefault)/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_INIT_SetDefault             (0x00000000                                               )/*MIPI DISABLE*/
/*MT6176*/ #define  PDATA_IDLE_SetDefault             (0x00000000                                               )/*MIPI DISABLE*/
/*MT6176*/ #endif
/*MT6176*/
/*MT6176*//*----------------------------------------------*/
/*MT6176*//*   APC Compensate Thresholds                  */
/*MT6176*//*----------------------------------------------*/
/*MT6176*/
/*MT6176*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD_SECOND_SetDefault     180
/*MT6176*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD_SetDefault            SECONDS2FRAME(BAT_VOLTAGE_SAMPLE_PERIOD_SECOND_SetDefault)
/*MT6176*/ #define    BAT_VOLTAGE_AVERAGE_COUNT_SetDefault            1
/*MT6176*/ #define    BAT_LOW_VOLTAGE_TRHESHOLD_SetDefault            (3.5)
/*MT6176*/ #define    BAT_HIGH_VOLTAGE_TRHESHOLD_SetDefault           (4.0)
/*MT6176*/ #define    BAT_LOW_VOLTAGE_SetDefault                      VOLT2UVOLT(BAT_LOW_VOLTAGE_TRHESHOLD_SetDefault)
/*MT6176*/ #define    BAT_HIGH_VOLTAGE_SetDefault                     VOLT2UVOLT(BAT_HIGH_VOLTAGE_TRHESHOLD_SetDefault)
/*MT6176*/
/*MT6176*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND_SetDefault 180
/*MT6176*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD_SetDefault        SECONDS2FRAME(BAT_TEMPERATURE_SAMPLE_PERIOD_SECOND_SetDefault)
/*MT6176*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT_SetDefault        1
/*MT6176*/ #define    BAT_LOW_TEMPERATURE_TRHESHOLD_SetDefault        (0)
/*MT6176*/ #define    BAT_HIGH_TEMPERATURE_TRHESHOLD_SetDefault       (50)
/*MT6176*/ #define    BAT_LOW_TEMPERATURE_SetDefault                  TEMP2MTEMP(BAT_LOW_TEMPERATURE_TRHESHOLD_SetDefault)
/*MT6176*/ #define    BAT_HIGH_TEMPERATURE_SetDefault                 TEMP2MTEMP(BAT_HIGH_TEMPERATURE_TRHESHOLD_SetDefault)
/*MT6176*/
/*MT6176*/ #define    RF_TEMPERATURE_SAMPLE_PERIOD_SECOND_SetDefault  1
/*MT6176*/ #define    RF_TEMPERATURE_SAMPLE_PERIOD_SetDefault         SECONDS2FRAME(RF_TEMPERATURE_SAMPLE_PERIOD_SECOND_SetDefault)
/*MT6176*/ #define    RF_TEMPERATURE_AVERAGE_COUNT_SetDefault         1
/*MT6176*/
/*MT6176*//*----------------------------------------------*/
/*MT6176*//*   Voltage Compensate Parameter               */
/*MT6176*//*----------------------------------------------*/
/*MT6176*/
/*MT6176*/ #define    MINUTES2FRAME_SetDefault(n)                     ((int)((n)*13000))
/*MT6176*/ #define    AP_UPDATE_VOLTINFO_PERIOD_SetDefault            MINUTES2FRAME_SetDefault(5)
/*MT6176*/
/*MT6176*//*----------------------------------------------*/
/*MT6176*//*   Crystal parameter                          */
/*MT6176*//*----------------------------------------------*/
/*MT6176*/ #define Custom_RF_XO_CapID_SetDefault   170 /* RF SOP, Range:0~255 */
/*MT6176*/
/*MT6176*/ /*****************************************/
/*MT6176*/ /*  Define your band mode selection on   */
/*MT6176*/ /*  High Band and Low Band receivers     */
/*MT6176*/ /*****************************************/
/*MT6176*/ /*   Primarary Path:                     */
/*MT6176*/ /*    IORX_PRX1                          */
/*MT6176*/ /*    IORX_PRX2                          */
/*MT6176*/ /*    IORX_PRX3                          */
/*MT6176*/ /*    IORX_PRX4                          */
/*MT6176*/ /*    IORX_PRX5                          */
/*MT6176*/ /*    IORX_PRX6                          */
/*MT6176*/ /*    IORX_PRX7                          */
/*MT6176*/ /*    IORX_PRX8                          */
/*MT6176*/ /*    IORX_PRX9                          */
/*MT6176*/ /*    IORX_PRX10                         */
/*MT6176*/ /*    IORX_PRX11                         */
/*MT6176*/ /*    IORX_PRX12                         */
/*MT6176*/ /*    IORX_PRX13                         */
/*MT6176*/ /*    IORX_PRX14                         */
/*MT6176*/ /*****************************************/
/*MT6176*/
/*MT6176*/ #if IS_2G_MIPI_ENABLE_SetDefault
/*MT6176*/ #define GSM850_PATH_SEL_SetDefault IORX_PRX3/*MIPI ENABLE*/
/*MT6176*/ #define GSM_PATH_SEL_SetDefault    IORX_PRX2/*MIPI ENABLE*/
/*MT6176*/ #define DCS_PATH_SEL_SetDefault    IORX_PRX8/*MIPI ENABLE*/
/*MT6176*/ #define PCS_PATH_SEL_SetDefault    IORX_PRX10/*MIPI ENABLE*/
/*MT6176*/ #else
/*MT6176*/ #define GSM850_PATH_SEL_SetDefault IORX_PRX3/*MIPI DISABLE*/
/*MT6176*/ #define GSM_PATH_SEL_SetDefault    IORX_PRX2/*MIPI DISABLE*/
/*MT6176*/ #define DCS_PATH_SEL_SetDefault    IORX_PRX8/*MIPI DISABLE*/
/*MT6176*/ #define PCS_PATH_SEL_SetDefault    IORX_PRX10/*MIPI DISABLE*/
/*MT6176*/ #endif
/*MT6176*/
/*MT6176*//*======================================================================================== */
/*MT6176*/
/*MT6176*/ /*----------------------------------------------*/
/*MT6176*/ /*   TX Power Control (TXPC) Support            */
/*MT6176*/ /*----------------------------------------------*/
/*MT6176*/ #define IS_BSI_CLOSED_LOOP_TXPC_ON_SetDefault      0
/*MT6176*/
/*MT6176*/ #define TXPC_EPSK_TP_SLOPE_LB_SetDefault          ((24<<8)+23) /* Unit: degree/dB. Temperature increment that causes 1-dB EPSK TX power drop */
/*MT6176*/ #define TXPC_EPSK_TP_SLOPE_HB_SetDefault          ((23<<8)+23) /* Two slope method : [( temp<20:slpoe1)<<8 + (temp>=20:slpoe2)], slope must < 256 */
/*MT6176*/
/*MT6176*/ /*----------------------------------------------*/
/*MT6176*/ /*   DCXO LPM parameter                         */
/*MT6176*/ /*----------------------------------------------*/
/*MT6176*/ #define CUSTOM_CLOAD_FREQ_OFFSET_SetDefault   61557 /*in unit of Hz*/
/*MT6176*/
/*MT6176*/ /*----------------------------------------------*/
/*MT6176*/ /*   TX power rollback parameter                */
/*MT6176*/ /*----------------------------------------------*/
/*MT6176*/ /*Unit: 1/8 dB*/
/*MT6176*/ /*GSM850 GMSK*/
/*MT6176*/ #define GSM850_TX_ROLLBACK_2T_GMSK_SetDefault      8
/*MT6176*/ #define GSM850_TX_ROLLBACK_3T_GMSK_SetDefault     24
/*MT6176*/ #define GSM850_TX_ROLLBACK_4T_GMSK_SetDefault     32
/*MT6176*/ #define GSM850_TX_ROLLBACK_5T_GMSK_SetDefault     40
/*MT6176*/
/*MT6176*/ /*GSM GMSK*/
/*MT6176*/ #define GSM_TX_ROLLBACK_2T_GMSK_SetDefault         8
/*MT6176*/ #define GSM_TX_ROLLBACK_3T_GMSK_SetDefault        24
/*MT6176*/ #define GSM_TX_ROLLBACK_4T_GMSK_SetDefault        32
/*MT6176*/ #define GSM_TX_ROLLBACK_5T_GMSK_SetDefault        40
/*MT6176*/
/*MT6176*/ /*DCS GMSK*/
/*MT6176*/ #define DCS_TX_ROLLBACK_2T_GMSK_SetDefault         8
/*MT6176*/ #define DCS_TX_ROLLBACK_3T_GMSK_SetDefault        24
/*MT6176*/ #define DCS_TX_ROLLBACK_4T_GMSK_SetDefault        32
/*MT6176*/ #define DCS_TX_ROLLBACK_5T_GMSK_SetDefault        40
/*MT6176*/
/*MT6176*/ /*PCS GMSK*/
/*MT6176*/ #define PCS_TX_ROLLBACK_2T_GMSK_SetDefault         8
/*MT6176*/ #define PCS_TX_ROLLBACK_3T_GMSK_SetDefault        24
/*MT6176*/ #define PCS_TX_ROLLBACK_4T_GMSK_SetDefault        32
/*MT6176*/ #define PCS_TX_ROLLBACK_5T_GMSK_SetDefault        40
/*MT6176*/
/*MT6176*/ /*GSM850 EPSK*/
/*MT6176*/ #define GSM850_TX_ROLLBACK_2T_EPSK_SetDefault      8
/*MT6176*/ #define GSM850_TX_ROLLBACK_3T_EPSK_SetDefault     24
/*MT6176*/ #define GSM850_TX_ROLLBACK_4T_EPSK_SetDefault     32
/*MT6176*/ #define GSM850_TX_ROLLBACK_5T_EPSK_SetDefault     40
/*MT6176*/
/*MT6176*/ /*GSM EPSK*/
/*MT6176*/ #define GSM_TX_ROLLBACK_2T_EPSK_SetDefault         8
/*MT6176*/ #define GSM_TX_ROLLBACK_3T_EPSK_SetDefault        24
/*MT6176*/ #define GSM_TX_ROLLBACK_4T_EPSK_SetDefault        32
/*MT6176*/ #define GSM_TX_ROLLBACK_5T_EPSK_SetDefault        40
/*MT6176*/
/*MT6176*/ /*DCS EPSK*/
/*MT6176*/ #define DCS_TX_ROLLBACK_2T_EPSK_SetDefault         8
/*MT6176*/ #define DCS_TX_ROLLBACK_3T_EPSK_SetDefault        24
/*MT6176*/ #define DCS_TX_ROLLBACK_4T_EPSK_SetDefault        32
/*MT6176*/ #define DCS_TX_ROLLBACK_5T_EPSK_SetDefault        40
/*MT6176*/
/*MT6176*/ /*PCS EPSK*/
/*MT6176*/ #define PCS_TX_ROLLBACK_2T_EPSK_SetDefault         8
/*MT6176*/ #define PCS_TX_ROLLBACK_3T_EPSK_SetDefault        24
/*MT6176*/ #define PCS_TX_ROLLBACK_4T_EPSK_SetDefault        32
/*MT6176*/ #define PCS_TX_ROLLBACK_5T_EPSK_SetDefault        40
/*MT6176*/
/*MT6176*/ /*Enable ramping profile rollback to improve switching spectrum depending on PA*/
/*MT6176*/ #define IS_RAMPPROFILE_ROLLBACK_ENABLE_SetDefault  0
/*MT6176*/
/*MT6176*/ /*============================================================================== */
/*MT6176*/
/*MT6176*/ #if (IS_2G_TAS_SUPPORT||IS_2G_TAS_FOR_C2K_ONOFF_SUPPORT)
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/ /*  Definition for the antenna swap                     */
/*MT6176*/ /*------------------------------------------------------*/
/*MT6176*/
/*MT6176*/ #define L1D_FORCE_TX_ANTENNA_ENABLE_SetDefault        0              /* 0: off 1: Don't change antenna                                             */
/*MT6176*/ #define L1D_FORCE_TX_ANTENNA_IDX_SetDefault           0              /* The antenna which user forces to stay                                      */
/*MT6176*/ #if IS_2G_TAS_SUPPORT
/*MT6176*/ #define L1D_EN_TAS_SetDefault                         0              /* 0: off   1: enable TS feature                                              */
/*MT6176*/ #endif
/*MT6176*/ #define L1D_EN_TAS_WITH_TEST_SIM_SetDefault           0              /* 0: off   1: enable TS feature with Test SIM                                */
/*MT6176*/ #define L1D_EN_BAND_SetDefault                        0xF            /* b0:band 850,b1:band 900,b2:band 1800,b3:band 1900                          */
/*MT6176*/ #define L1D_ANT_SEL_INIT_SetDefault                   0              /* Default antenna                                                            */
/*MT6176*/ #define L1D_EN_TAS_FOR_C2K_SetDefault                 0              /* 0: off   1: enable TAS for C2K feature                                     */
/*MT6176*/
/*MT6176*/ #define L1D_TAS_PIN1_SetDefault                       L1D_TAS_PIN_NULL  // the 1st BPI pin number for the antenna swap control
/*MT6176*/ #define L1D_TAS_PIN2_SetDefault                       L1D_TAS_PIN_NULL  // the 2nd BPI pin number for the antenna swap control
/*MT6176*/ #define L1D_TAS_PIN3_SetDefault                       L1D_TAS_PIN_NULL  // the 3rd BPI pin number for the antenna swap control
/*MT6176*/ #if IS_2G_TAS_ANT_IDX_SET_ON_TEST_SIM
/*MT6176*/ #define L1D_TAS_INIT_ANT_GSM850_SetDefault                0
/*MT6176*/ #define L1D_TAS_INIT_ANT_GSM900_SetDefault                0
/*MT6176*/ #define L1D_TAS_INIT_ANT_DCS1800_SetDefault               0
/*MT6176*/ #define L1D_TAS_INIT_ANT_PCS1900_SetDefault               0
/*MT6176*/ #endif
/*MT6176*/
/*MT6176*/ // Do not modify this define
/*MT6176*/ #define L1D_TAS_BPI_PIN_GEN_SetDefault(var1, var2, var3)    ( (L1D_TAS_PIN1_SetDefault==L1D_TAS_PIN_NULL?0:(var1<<L1D_TAS_PIN1_SetDefault)) | \
/*MT6176*/                                                    (L1D_TAS_PIN2_SetDefault==L1D_TAS_PIN_NULL?0:(var2<<L1D_TAS_PIN2_SetDefault)) | \
/*MT6176*/                                                    (L1D_TAS_PIN3_SetDefault==L1D_TAS_PIN_NULL?0:(var3<<L1D_TAS_PIN3_SetDefault)) )
/*MT6176*/ #define PDATA_L1D_TAS_MASK_SetDefault        L1D_TAS_BPI_PIN_GEN_SetDefault(1,1,1)
/*MT6176*/
/*MT6176*/ /* ------------- PDATA_L1D_GSM850_TAS#  --------------*/
/*MT6176*/ #define PDATA_L1D_GSM850_TAS1_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM850_TAS2_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM850_TAS3_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM850_TAS4_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM850_TAS5_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM850_TAS6_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM850_TAS7_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/
/*MT6176*/ /* ------------- PDATA_L1D_GSM900_TAS#  --------------*/
/*MT6176*/ #define PDATA_L1D_GSM900_TAS1_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM900_TAS2_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM900_TAS3_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM900_TAS4_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM900_TAS5_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM900_TAS6_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_GSM900_TAS7_SetDefault     L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/
/*MT6176*/ /* ------------- PDATA_L1D_DCS1800_TAS#  --------------*/
/*MT6176*/ #define PDATA_L1D_DCS1800_TAS1_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_DCS1800_TAS2_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_DCS1800_TAS3_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_DCS1800_TAS4_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_DCS1800_TAS5_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_DCS1800_TAS6_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_DCS1800_TAS7_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/
/*MT6176*/ /* ------------- PDATA_L1D_PCS1900_TAS#  --------------*/
/*MT6176*/ #define PDATA_L1D_PCS1900_TAS1_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_PCS1900_TAS2_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_PCS1900_TAS3_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_PCS1900_TAS4_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_PCS1900_TAS5_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_PCS1900_TAS6_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/ #define PDATA_L1D_PCS1900_TAS7_SetDefault    L1D_TAS_BPI_PIN_GEN_SetDefault(0,0,0)//If not using , must set (0,0,0)
/*MT6176*/
/*MT6176*/ #endif
#endif
