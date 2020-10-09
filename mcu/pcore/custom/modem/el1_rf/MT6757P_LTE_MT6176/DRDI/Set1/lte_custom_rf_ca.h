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
*   lte_custom_rf_ca.h
*
* Project:
* --------
*   MT6291
*
*============================================================================*/

#ifndef  __LTE_CUSTOM_RF_CA_Set1_H__
#define  __LTE_CUSTOM_RF_CA_Set1_H__

#include "lte_custom_rf.h"
#include "el1d_rf_custom_data.h"

/*MT6176*/ /*------------------------------------------------------------*/
/*MT6176*/ /* E-UTRA CA Configuration !!!Please check RF FE placement!!! */
/*MT6176*/ /*------------------------------------------------------------*/
/*MT6176*/ #define LTE_CACFG_IND_00_Set1   LTE_CACFG_CA_2A_2A
/*MT6176*/ #define LTE_CACFG_IND_01_Set1   LTE_CACFG_CA_3A_3A
/*MT6176*/ #define LTE_CACFG_IND_02_Set1   LTE_CACFG_CA_4A_4A
/*MT6176*/ #define LTE_CACFG_IND_03_Set1   LTE_CACFG_CA_7A_7A
/*MT6176*/ #define LTE_CACFG_IND_04_Set1   LTE_CACFG_CA_41A_41A
/*MT6176*/ #define LTE_CACFG_IND_05_Set1   LTE_CACFG_CA_1A_3A
/*MT6176*/ #define LTE_CACFG_IND_06_Set1   LTE_CACFG_CA_1A_5A
/*MT6176*/ #define LTE_CACFG_IND_07_Set1   LTE_CACFG_CA_1A_26A
/*MT6176*/ #define LTE_CACFG_IND_08_Set1   LTE_CACFG_CA_1A_7A
/*MT6176*/ #define LTE_CACFG_IND_09_Set1   LTE_CACFG_CA_1A_8A
/*MT6176*/ #define LTE_CACFG_IND_10_Set1   LTE_CACFG_CA_1A_20A
/*MT6176*/ #define LTE_CACFG_IND_11_Set1   LTE_CACFG_CA_2A_4A
/*MT6176*/ #define LTE_CACFG_IND_12_Set1   LTE_CACFG_CA_2A_5A
/*MT6176*/ #define LTE_CACFG_IND_13_Set1   LTE_CACFG_CA_3A_5A
/*MT6176*/ #define LTE_CACFG_IND_14_Set1   LTE_CACFG_CA_3A_26A
/*MT6176*/ #define LTE_CACFG_IND_15_Set1   LTE_CACFG_CA_3A_7A
/*MT6176*/ #define LTE_CACFG_IND_16_Set1   LTE_CACFG_CA_3A_8A
/*MT6176*/ #define LTE_CACFG_IND_17_Set1   LTE_CACFG_CA_3A_20A
/*MT6176*/ #define LTE_CACFG_IND_18_Set1   LTE_CACFG_CA_3A_28A
/*MT6176*/ #define LTE_CACFG_IND_19_Set1   LTE_CACFG_CA_4A_5A
/*MT6176*/ #define LTE_CACFG_IND_20_Set1   LTE_CACFG_CA_5A_7A
/*MT6176*/ #define LTE_CACFG_IND_21_Set1   LTE_CACFG_CA_7A_20A
/*MT6176*/ #define LTE_CACFG_IND_22_Set1   LTE_CACFG_CA_7A_28A
/*MT6176*/ #define LTE_CACFG_IND_23_Set1   LTE_CACFG_CA_39A_41A
/*MT6176*/ #define LTE_CACFG_IND_24_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_25_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_26_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_27_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_28_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_29_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_30_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_31_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_32_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_33_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_34_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_35_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_36_Set1   LTE_CACFG_CA_NONE
/*MT6176*/ #define LTE_CACFG_IND_37_Set1   LTE_CACFG_CA_NONE
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*------------------*/
/*MT6176*/ /* CA Null Settings */
/*MT6176*/ /*------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_NONE_CCNUM_Set1                 0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC0_Set1                   LTE_BandNone
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC1_Set1                   LTE_BandNone
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC0_RX_IO_SEL_Set1         0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC0_RXD_IO_SEL_Set1        0
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC1_RX_IO_SEL_Set1         0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC1_RXD_IO_SEL_Set1        0
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC0_PDATA_PR1_Set1         0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC0_PDATA_PR2_Set1         0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC0_PDATA_PR3_Set1         0
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC1_PDATA_PR1_Set1         0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC1_PDATA_PR2_Set1         0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC1_PDATA_PR3_Set1         0
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC0_PDATA_PRANT_Set1       0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC1_PDATA_PRANT_Set1       0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC0_PDATA_PTANT_Set1       0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC1_PDATA_PTANT_Set1       0
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC0_RX_MIPI_TBL_IDX_Set1   TBL_IDX0
/*MT6176*/ #define LTE_CACFG_CA_NONE_CC1_RX_MIPI_TBL_IDX_Set1   TBL_IDX0
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_1A_3A */  //ANT=MH
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC0_Set1                   LTE_Band1
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC1_Set1                   LTE_Band3
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_3A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_3A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC0_RX_MIPI_TBL_IDX_Set1   TBL_IDX21
/*MT6176*/ #define LTE_CACFG_CA_1A_3A_CC1_RX_MIPI_TBL_IDX_Set1   TBL_IDX22
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_1A_5A */  //ANT=B5
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC0_Set1                   LTE_Band1
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC1_Set1                   LTE_Band5
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_5A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_5A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_5A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_1A_26A */  //ANT=B26
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC0_Set1                   LTE_Band1
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC1_Set1                   LTE_Band26
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_26A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_26A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_26A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_1A_7A */  //ANT=MH
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC0_Set1                   LTE_Band1
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC1_Set1                   LTE_Band7
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_7A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_7A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_7A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_1A_8A */  //ANT=B8
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC0_Set1                   LTE_Band1
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC1_Set1                   LTE_Band8
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_8A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_8A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_8A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_1A_20A */  //ANT=B20
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC0_Set1                   LTE_Band1
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC1_Set1                   LTE_Band20
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_3_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_3_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_20A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_20A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_20A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_1A_28A */  //ANT=B28
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC0_Set1                   LTE_Band1
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC1_Set1                   LTE_Band28
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_4_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_4_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_28A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_1A_28A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_1A_28A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_2A_4A */  //ANT=MH
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC0_Set1                   LTE_Band2
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC1_Set1                   LTE_Band4
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_2A_4A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_2A_4A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_4A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_2A_5A */  //ANT=B5
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC0_Set1                   LTE_Band2
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC1_Set1                   LTE_Band5
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_2A_5A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_2A_5A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_5A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_3A_5A */  //ANT=B5
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC0_Set1                   LTE_Band3
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC1_Set1                   LTE_Band5
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_5A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_5A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_5A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_3A_26A */  //ANT=B26
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC0_Set1                   LTE_Band3
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC1_Set1                   LTE_Band26
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_26A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_26A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_26A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_3A_7A */  //ANT=MH
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC0_Set1                   LTE_Band3
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC1_Set1                   LTE_Band7
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_7A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_7A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_7A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_3A_8A */  //ANT=B8
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC0_Set1                   LTE_Band3
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC1_Set1                   LTE_Band8
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_8A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_8A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_8A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_3A_20A */  //ANT=B20
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC0_Set1                   LTE_Band3
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC1_Set1                   LTE_Band20
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT  //ANT BPI15 and BPI14 apply B20
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT  //ANT BPI15 and BPI14 apply B20
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT  //ANT=SB
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT  //ANT=SB 
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_3_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_3_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_20A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_20A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_20A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_3A_28A */  //ANT=B28
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC0_Set1                   LTE_Band3
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC1_Set1                   LTE_Band28
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_4_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_4_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_28A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_28A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_28A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_4A_5A */  //ANT=B5
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC0_Set1                   LTE_Band4
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC1_Set1                   LTE_Band5
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_4A_5A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_4A_5A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_4A_5A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_5A_7A */  //ANT=B5
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC0_Set1                   LTE_Band5
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC1_Set1                   LTE_Band7
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT // 0x000C8080   //ANT
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT // 0x000C8080   //ANT
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT // 0x000C8008   //ANT BPI15 and BPI14 apply B5
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT // 0x000C8008   //ANT BPI15 and BPI14 apply B5
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_2_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_5A_7A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_5A_7A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_5A_7A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_7A_20A */  //ANT=B20
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC0_Set1                   LTE_Band7
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC1_Set1                   LTE_Band20
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_3_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_3_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_7A_20A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_7A_20A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_20A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*---------------------------*/
/*MT6176*/ /* CA Settings for CA_7A_28A */  //ANT=B28
/*MT6176*/ /*---------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC0_Set1                   LTE_Band7
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC1_Set1                   LTE_Band28
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_4_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_4_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_7A_28A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_7A_28A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_28A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*----------------------------*/
/*MT6176*/ /* CA Settings for CA_39A_41A */  //ANT=MH
/*MT6176*/ /*----------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC0_Set1                   LTE_Band39
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC1_Set1                   LTE_Band41
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC1_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC1_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC1_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC1_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC1_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC1_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_39A_41A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_39A_41A_CC1_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_39A_41A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_2A_2A */  //ANT=MH
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC0_Set1                   LTE_Band2
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_2A_2A_CC0_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // Do NOT modify settings in the following section
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC1_Set1                   LTE_CACFG_CA_2A_2A_CC0_Set1
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC1_RX_IO_SEL_Set1         LTE_CACFG_CA_2A_2A_CC0_RX_IO_SEL_Set1
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC1_RXD_IO_SEL_Set1        LTE_CACFG_CA_2A_2A_CC0_RXD_IO_SEL_Set1
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC1_PDATA_PR1_Set1         LTE_CACFG_CA_2A_2A_CC0_PDATA_PR1_Set1
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC1_PDATA_PR2_Set1         LTE_CACFG_CA_2A_2A_CC0_PDATA_PR2_Set1
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC1_PDATA_PR3_Set1         LTE_CACFG_CA_2A_2A_CC0_PDATA_PR3_Set1
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC1_PDATA_PRANT_Set1       LTE_CACFG_CA_2A_2A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_2A_2A_CC0_PDATA_PTANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_2A_2A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_CACFG_CA_2A_2A_CC0_RX_MIPI_TBL_IDX_Set1
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_3A_3A */  //ANT=MH
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC0_Set1                   LTE_Band3
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_3A_CC0_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // Do NOT modify settings in the following section
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC1_Set1                   LTE_CACFG_CA_3A_3A_CC0_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC1_RX_IO_SEL_Set1         LTE_CACFG_CA_3A_3A_CC0_RX_IO_SEL_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC1_RXD_IO_SEL_Set1        LTE_CACFG_CA_3A_3A_CC0_RXD_IO_SEL_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC1_PDATA_PR1_Set1         LTE_CACFG_CA_3A_3A_CC0_PDATA_PR1_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC1_PDATA_PR2_Set1         LTE_CACFG_CA_3A_3A_CC0_PDATA_PR2_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC1_PDATA_PR3_Set1         LTE_CACFG_CA_3A_3A_CC0_PDATA_PR3_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC1_PDATA_PRANT_Set1       LTE_CACFG_CA_3A_3A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_3A_3A_CC0_PDATA_PTANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_3A_3A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_CACFG_CA_3A_3A_CC0_RX_MIPI_TBL_IDX_Set1
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_4A_4A */  //ANT=MH
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC0_Set1                   LTE_Band4
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_4A_4A_CC0_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // Do NOT modify settings in the following section
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC1_Set1                   LTE_CACFG_CA_4A_4A_CC0_Set1
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC1_RX_IO_SEL_Set1         LTE_CACFG_CA_4A_4A_CC0_RX_IO_SEL_Set1
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC1_RXD_IO_SEL_Set1        LTE_CACFG_CA_4A_4A_CC0_RXD_IO_SEL_Set1
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC1_PDATA_PR1_Set1         LTE_CACFG_CA_4A_4A_CC0_PDATA_PR1_Set1
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC1_PDATA_PR2_Set1         LTE_CACFG_CA_4A_4A_CC0_PDATA_PR2_Set1
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC1_PDATA_PR3_Set1         LTE_CACFG_CA_4A_4A_CC0_PDATA_PR3_Set1
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC1_PDATA_PRANT_Set1       LTE_CACFG_CA_4A_4A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_4A_4A_CC0_PDATA_PTANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_4A_4A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_CACFG_CA_4A_4A_CC0_RX_MIPI_TBL_IDX_Set1
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*--------------------------*/
/*MT6176*/ /* CA Settings for CA_7A_7A */  //ANT=MH
/*MT6176*/ /*--------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC0_Set1                   LTE_Band7
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_7A_7A_CC0_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // Do NOT modify settings in the following section
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC1_Set1                   LTE_CACFG_CA_7A_7A_CC0_Set1
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC1_RX_IO_SEL_Set1         LTE_CACFG_CA_7A_7A_CC0_RX_IO_SEL_Set1
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC1_RXD_IO_SEL_Set1        LTE_CACFG_CA_7A_7A_CC0_RXD_IO_SEL_Set1
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC1_PDATA_PR1_Set1         LTE_CACFG_CA_7A_7A_CC0_PDATA_PR1_Set1
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC1_PDATA_PR2_Set1         LTE_CACFG_CA_7A_7A_CC0_PDATA_PR2_Set1
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC1_PDATA_PR3_Set1         LTE_CACFG_CA_7A_7A_CC0_PDATA_PR3_Set1
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC1_PDATA_PRANT_Set1       LTE_CACFG_CA_7A_7A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_7A_7A_CC0_PDATA_PTANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_7A_7A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_CACFG_CA_7A_7A_CC0_RX_MIPI_TBL_IDX_Set1
/*MT6176*/
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/
/*MT6176*/
/*MT6176*/ /*----------------------------*/
/*MT6176*/ /* CA Settings for CA_41A_41A */  //ANT=MH
/*MT6176*/ /*----------------------------*/
/*MT6176*/ // Common Settings
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CCNUM_Set1                 2
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC0_Set1                   LTE_Band41
/*MT6176*/
/*MT6176*/ // IO Port Settings
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC0_RX_IO_SEL_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC0_RXD_IO_SEL_Set1        LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // RX BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC0_PDATA_PR1_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC0_PDATA_PR2_Set1         LTE_SB_DEFAULT
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC0_PDATA_PR3_Set1         LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // ANT BPI Settings
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC0_PDATA_PRANT_Set1       PDATA_LTE_ANT_STATUS_1_Set1 //ANT
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC0_PDATA_PTANT_Set1       LTE_CACFG_CA_41A_41A_CC0_PDATA_PRANT_Set1
/*MT6176*/
/*MT6176*/ // RX MIPI Route Settings
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC0_RX_MIPI_TBL_IDX_Set1   LTE_SB_DEFAULT
/*MT6176*/
/*MT6176*/ // Do NOT modify settings in the following section
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC1_Set1                   LTE_CACFG_CA_41A_41A_CC0_Set1
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC1_RX_IO_SEL_Set1         LTE_CACFG_CA_41A_41A_CC0_RX_IO_SEL_Set1
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC1_RXD_IO_SEL_Set1        LTE_CACFG_CA_41A_41A_CC0_RXD_IO_SEL_Set1
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC1_PDATA_PR1_Set1         LTE_CACFG_CA_41A_41A_CC0_PDATA_PR1_Set1
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC1_PDATA_PR2_Set1         LTE_CACFG_CA_41A_41A_CC0_PDATA_PR2_Set1
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC1_PDATA_PR3_Set1         LTE_CACFG_CA_41A_41A_CC0_PDATA_PR3_Set1
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC1_PDATA_PRANT_Set1       LTE_CACFG_CA_41A_41A_CC0_PDATA_PRANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC1_PDATA_PTANT_Set1       LTE_CACFG_CA_41A_41A_CC0_PDATA_PTANT_Set1
/*MT6176*/ #define LTE_CACFG_CA_41A_41A_CC1_RX_MIPI_TBL_IDX_Set1   LTE_CACFG_CA_41A_41A_CC0_RX_MIPI_TBL_IDX_Set1
/*MT6176*/
/*MT6176 (Do NOT Modify!!!*/ #define  LTE_CA_MIPI_TOOL_VER     0
/*MT6176*/ /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*MT6176*/#endif

