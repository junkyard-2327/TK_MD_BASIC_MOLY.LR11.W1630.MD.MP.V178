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
 * lte_custom_mipi_et.h
 *
 * Project:
 * --------
 * MT6291
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *
 *
 *============================================================================*/

#ifndef  _LTE_CUSTOM_MIPI_ET_SetDefault_H_
#define  _LTE_CUSTOM_MIPI_ET_SetDefault_H_

/*===============================================================================*/

#include "el1d_rf_et_custom_data.h"
#include "lte_custom_mipi.h"

/*===============================================================================*/

/* ================================================================================================== */
/*   LTE ET feature enable control flag                                                                                                                                                                           */
/* ================================================================================================== */

#define IS_LTE_ET_FRONT_END_ENABLE_SetDefault                                  0   // 0: Disable ET feature; 1:Enable ET feature.

#define LTE_BandNone_ET_OUTER_LOOP_GAIN_SETTING_SetDefault                     0x0
#define LTE_BandNone_BYPASS_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              0x0

#define LTE_BandNone_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault                  1000
#define LTE_BandNone_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000

#define LTE_BandNone_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault              0
#define LTE_BandNone_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault       0

#define LTE_BandNone_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault              0
#define LTE_BandNone_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault       0



/* ================================================================================================== */
/*   LTE ET MIPI port selection                                                                                                                                                                                      */
/* ================================================================================================== */

#if( defined( MML1_ET_MIPI_PORT ) )

#if( MML1_ET_MIPI_PORT == 0 )

#define MIPI_PORT_ET                          LTE_MIPI_PORT0   // DO NOT MODIFY! Just apply MML1 setting

#elif( MML1_ET_MIPI_PORT == 1 )

#define MIPI_PORT_ET                          LTE_MIPI_PORT1   // DO NOT MODIFY! Just apply MML1 setting

#elif( MML1_ET_MIPI_PORT == 2 )

#define MIPI_PORT_ET                          LTE_MIPI_PORT2   // DO NOT MODIFY! Just apply MML1 setting

#elif( MML1_ET_MIPI_PORT == 3 )

#define MIPI_PORT_ET                          LTE_MIPI_PORT3   // DO NOT MODIFY! Just apply MML1 setting

#endif   // #if( MML1_ET_MIPI_PORT == 0 )

#endif   // #if( defined( MML1_ET_MIPI_PORT )



#if IS_LTE_ET_FRONT_END_ENABLE_SetDefault

/* ================================================================================================== */
/*   LTE ETM Gain Settings                                                                                                                                                                                           */
/* ================================================================================================== */

#if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define ET_OUTER_LOOP_GAIN_1dot5x                                    ET_MT6300_OUTER_LOOP_GAIN_1dot5x
#define ET_OUTER_LOOP_GAIN_2dot0x                                    ET_MT6300_OUTER_LOOP_GAIN_2dot0x
#define ET_OUTER_LOOP_GAIN_2dot5x                                    ET_MT6300_OUTER_LOOP_GAIN_2dot5x
#define ET_OUTER_LOOP_GAIN_3dot0x                                    ET_MT6300_OUTER_LOOP_GAIN_3dot0x

#else

#error "ETM chip type is not defined or defined as one unknown chip!"

#endif   // #if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define LTE_Band1_ET_OUTER_LOOP_GAIN_SETTING_SetDefault               ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band2_ET_OUTER_LOOP_GAIN_SETTING_SetDefault               ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band3_ET_OUTER_LOOP_GAIN_SETTING_SetDefault               ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band4_ET_OUTER_LOOP_GAIN_SETTING_SetDefault               ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band5_ET_OUTER_LOOP_GAIN_SETTING_SetDefault               ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band7_ET_OUTER_LOOP_GAIN_SETTING_SetDefault               ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band8_ET_OUTER_LOOP_GAIN_SETTING_SetDefault               ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band12_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band13_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band17_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band20_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band25_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band26_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band28_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band29_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              LTE_BandNone_ET_OUTER_LOOP_GAIN_SETTING_SetDefault
#define LTE_Band30_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band38_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band39_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band40_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band41_ET_OUTER_LOOP_GAIN_SETTING_SetDefault              ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band38_BYPASS_ET_OUTER_LOOP_GAIN_SETTING_SetDefault       ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band39_BYPASS_ET_OUTER_LOOP_GAIN_SETTING_SetDefault       ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band40_BYPASS_ET_OUTER_LOOP_GAIN_SETTING_SetDefault       ET_OUTER_LOOP_GAIN_3dot0x
#define LTE_Band41_BYPASS_ET_OUTER_LOOP_GAIN_SETTING_SetDefault       ET_OUTER_LOOP_GAIN_3dot0x

/* ================================================================================================== */
/*   LTE ETM VPA Offset Voltage Settings                                                                                                                                                                       */
/* ================================================================================================== */

#if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define ET_VPA_OFFSET_VOLTAGE_RESOLUTION                             ET_MT6300_VPA_DAC_RESOLUTION

#else

#error "ETM chip type is not defined or defined as one unknown chip!"

#endif   // #if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define LTE_Band1_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault            1000
#define LTE_Band2_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault            1000
#define LTE_Band3_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault            1000
#define LTE_Band4_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault            1000
#define LTE_Band5_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault            1000
#define LTE_Band7_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault            1000
#define LTE_Band8_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault            1000
#define LTE_Band12_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band13_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band17_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band20_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band25_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band26_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band28_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band29_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           LTE_BandNone_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault
#define LTE_Band30_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band38_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band39_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band40_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band41_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault           1000
#define LTE_Band38_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault    1000
#define LTE_Band39_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault    1000
#define LTE_Band40_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault    1000
#define LTE_Band41_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault    1000

/* ================================================================================================== */
/*   LTE ET Sub-Band Frequency Settings                                                                                                                                                                      */
/*                                                                       Unit: 100kHz                                                                                                                                     */
/* ================================================================================================== */
// ET Band 1 Sub-frequency
#define ET_LTE_Band1_SUB_0_Freq           19225
#define ET_LTE_Band1_SUB_1_Freq           19305
#define ET_LTE_Band1_SUB_2_Freq           19385
#define ET_LTE_Band1_SUB_3_Freq           19465
#define ET_LTE_Band1_SUB_4_Freq           19535
#define ET_LTE_Band1_SUB_5_Freq           19615
#define ET_LTE_Band1_SUB_6_Freq           19695
#define ET_LTE_Band1_SUB_7_Freq           19775

// ET Band 2 Sub-frequency
#define ET_LTE_Band2_SUB_0_Freq           18525
#define ET_LTE_Band2_SUB_1_Freq           18605
#define ET_LTE_Band2_SUB_2_Freq           18685
#define ET_LTE_Band2_SUB_3_Freq           18765
#define ET_LTE_Band2_SUB_4_Freq           18835
#define ET_LTE_Band2_SUB_5_Freq           18915
#define ET_LTE_Band2_SUB_6_Freq           18995
#define ET_LTE_Band2_SUB_7_Freq           19075

// ET Band 3 Sub-frequency
#define ET_LTE_Band3_SUB_0_Freq           17125
#define ET_LTE_Band3_SUB_1_Freq           17225
#define ET_LTE_Band3_SUB_2_Freq           17325
#define ET_LTE_Band3_SUB_3_Freq           17425
#define ET_LTE_Band3_SUB_4_Freq           17525
#define ET_LTE_Band3_SUB_5_Freq           17625
#define ET_LTE_Band3_SUB_6_Freq           17725
#define ET_LTE_Band3_SUB_7_Freq           17825

// ET Band 4 Sub-frequency
#define ET_LTE_Band4_SUB_0_Freq           17125
#define ET_LTE_Band4_SUB_1_Freq           17225
#define ET_LTE_Band4_SUB_2_Freq           17325
#define ET_LTE_Band4_SUB_3_Freq           17425
#define ET_LTE_Band4_SUB_4_Freq           17525
#define ET_LTE_Band4_SUB_5_Freq           0
#define ET_LTE_Band4_SUB_6_Freq           0
#define ET_LTE_Band4_SUB_7_Freq           0

// ET Band 5 Sub-frequency
#define ET_LTE_Band5_SUB_0_Freq           8265
#define ET_LTE_Band5_SUB_1_Freq           8315
#define ET_LTE_Band5_SUB_2_Freq           8365
#define ET_LTE_Band5_SUB_3_Freq           8415
#define ET_LTE_Band5_SUB_4_Freq           8465
#define ET_LTE_Band5_SUB_5_Freq           0
#define ET_LTE_Band5_SUB_6_Freq           0
#define ET_LTE_Band5_SUB_7_Freq           0

// ET Band 6 Sub-frequency
#define ET_LTE_Band6_SUB_0_Freq           8325
#define ET_LTE_Band6_SUB_1_Freq           8340
#define ET_LTE_Band6_SUB_2_Freq           8350
#define ET_LTE_Band6_SUB_3_Freq           8360
#define ET_LTE_Band6_SUB_4_Freq           8375
#define ET_LTE_Band6_SUB_5_Freq           0
#define ET_LTE_Band6_SUB_6_Freq           0
#define ET_LTE_Band6_SUB_7_Freq           0

// ET Band 7 Sub-frequency
#define ET_LTE_Band7_SUB_0_Freq           25025
#define ET_LTE_Band7_SUB_1_Freq           25110
#define ET_LTE_Band7_SUB_2_Freq           25210
#define ET_LTE_Band7_SUB_3_Freq           25300
#define ET_LTE_Band7_SUB_4_Freq           25400
#define ET_LTE_Band7_SUB_5_Freq           25490
#define ET_LTE_Band7_SUB_6_Freq           25590
#define ET_LTE_Band7_SUB_7_Freq           25675

// ET Band 8 Sub-frequency
#define ET_LTE_Band8_SUB_0_Freq           8825
#define ET_LTE_Band8_SUB_1_Freq           8860
#define ET_LTE_Band8_SUB_2_Freq           8900
#define ET_LTE_Band8_SUB_3_Freq           8950
#define ET_LTE_Band8_SUB_4_Freq           9000
#define ET_LTE_Band8_SUB_5_Freq           9050
#define ET_LTE_Band8_SUB_6_Freq           9090
#define ET_LTE_Band8_SUB_7_Freq           9125

// ET Band 12 Sub-frequency
#define ET_LTE_Band12_SUB_0_Freq          7015
#define ET_LTE_Band12_SUB_1_Freq          7045
#define ET_LTE_Band12_SUB_2_Freq          7075
#define ET_LTE_Band12_SUB_3_Freq          7105
#define ET_LTE_Band12_SUB_4_Freq          7135
#define ET_LTE_Band12_SUB_5_Freq          0
#define ET_LTE_Band12_SUB_6_Freq          0
#define ET_LTE_Band12_SUB_7_Freq          0

// ET Band 13 Sub-frequency
#define ET_LTE_Band13_SUB_0_Freq          7795
#define ET_LTE_Band13_SUB_1_Freq          7810
#define ET_LTE_Band13_SUB_2_Freq          7820
#define ET_LTE_Band13_SUB_3_Freq          7830
#define ET_LTE_Band13_SUB_4_Freq          7845
#define ET_LTE_Band13_SUB_5_Freq          0
#define ET_LTE_Band13_SUB_6_Freq          0
#define ET_LTE_Band13_SUB_7_Freq          0

// ET Band 17 Sub-frequency
#define ET_LTE_Band17_SUB_0_Freq          7065
#define ET_LTE_Band17_SUB_1_Freq          7090
#define ET_LTE_Band17_SUB_2_Freq          7100
#define ET_LTE_Band17_SUB_3_Freq          7110
#define ET_LTE_Band17_SUB_4_Freq          7135
#define ET_LTE_Band17_SUB_5_Freq          0
#define ET_LTE_Band17_SUB_6_Freq          0
#define ET_LTE_Band17_SUB_7_Freq          0

// ET Band 19 Sub-frequency
#define ET_LTE_Band19_SUB_0_Freq          8325
#define ET_LTE_Band19_SUB_1_Freq          8350
#define ET_LTE_Band19_SUB_2_Freq          8375
#define ET_LTE_Band19_SUB_3_Freq          8400
#define ET_LTE_Band19_SUB_4_Freq          8425
#define ET_LTE_Band19_SUB_5_Freq          0
#define ET_LTE_Band19_SUB_6_Freq          0
#define ET_LTE_Band19_SUB_7_Freq          0

// ET Band 20 Sub-frequency
#define ET_LTE_Band20_SUB_0_Freq          8345
#define ET_LTE_Band20_SUB_1_Freq          8380
#define ET_LTE_Band20_SUB_2_Freq          8415
#define ET_LTE_Band20_SUB_3_Freq          8450
#define ET_LTE_Band20_SUB_4_Freq          8490
#define ET_LTE_Band20_SUB_5_Freq          8525
#define ET_LTE_Band20_SUB_6_Freq          8560
#define ET_LTE_Band20_SUB_7_Freq          8595

// ET Band 26 Sub-frequency
#define ET_LTE_Band26_SUB_0_Freq          8165
#define ET_LTE_Band26_SUB_1_Freq          8190
#define ET_LTE_Band26_SUB_2_Freq          8240
#define ET_LTE_Band26_SUB_3_Freq          8290
#define ET_LTE_Band26_SUB_4_Freq          8340
#define ET_LTE_Band26_SUB_5_Freq          8390
#define ET_LTE_Band26_SUB_6_Freq          8440
#define ET_LTE_Band26_SUB_7_Freq          8465

// ET Band 28 Sub-frequency
#define ET_LTE_Band28_SUB_0_Freq          7055
#define ET_LTE_Band28_SUB_1_Freq          7110
#define ET_LTE_Band28_SUB_2_Freq          7160
#define ET_LTE_Band28_SUB_3_Freq          7220
#define ET_LTE_Band28_SUB_4_Freq          7290
#define ET_LTE_Band28_SUB_5_Freq          7350
#define ET_LTE_Band28_SUB_6_Freq          7400
#define ET_LTE_Band28_SUB_7_Freq          7455

// ET Band 29 Sub-frequency
#define ET_LTE_Band29_SUB_0_Freq          0
#define ET_LTE_Band29_SUB_1_Freq          0
#define ET_LTE_Band29_SUB_2_Freq          0
#define ET_LTE_Band29_SUB_3_Freq          0
#define ET_LTE_Band29_SUB_4_Freq          0
#define ET_LTE_Band29_SUB_5_Freq          0
#define ET_LTE_Band29_SUB_6_Freq          0
#define ET_LTE_Band29_SUB_7_Freq          0

// ET Band 30 Sub-frequency
#define ET_LTE_Band30_SUB_0_Freq          23075
#define ET_LTE_Band30_SUB_1_Freq          23090
#define ET_LTE_Band30_SUB_2_Freq          23100
#define ET_LTE_Band30_SUB_3_Freq          23110
#define ET_LTE_Band30_SUB_4_Freq          23125
#define ET_LTE_Band30_SUB_5_Freq          0
#define ET_LTE_Band30_SUB_6_Freq          0
#define ET_LTE_Band30_SUB_7_Freq          0

// ET Band 38 Sub-frequency
#define ET_LTE_Band38_SUB_0_Freq          25725
#define ET_LTE_Band38_SUB_1_Freq          25800
#define ET_LTE_Band38_SUB_2_Freq          25860
#define ET_LTE_Band38_SUB_3_Freq          25920
#define ET_LTE_Band38_SUB_4_Freq          25980
#define ET_LTE_Band38_SUB_5_Freq          26040
#define ET_LTE_Band38_SUB_6_Freq          26100
#define ET_LTE_Band38_SUB_7_Freq          26175

// ET Band 39 Sub-frequency
#define ET_LTE_Band39_SUB_0_Freq          18825
#define ET_LTE_Band39_SUB_1_Freq          18875
#define ET_LTE_Band39_SUB_2_Freq          18925
#define ET_LTE_Band39_SUB_3_Freq          18975
#define ET_LTE_Band39_SUB_4_Freq          19025
#define ET_LTE_Band39_SUB_5_Freq          19075
#define ET_LTE_Band39_SUB_6_Freq          19125
#define ET_LTE_Band39_SUB_7_Freq          19175

// ET Band 40 Sub-frequency
#define ET_LTE_Band40_SUB_0_Freq          23025
#define ET_LTE_Band40_SUB_1_Freq          23160
#define ET_LTE_Band40_SUB_2_Freq          23295
#define ET_LTE_Band40_SUB_3_Freq          23430
#define ET_LTE_Band40_SUB_4_Freq          23570
#define ET_LTE_Band40_SUB_5_Freq          23705
#define ET_LTE_Band40_SUB_6_Freq          23840
#define ET_LTE_Band40_SUB_7_Freq          23975

// ET Band 41 Sub-frequency
#define ET_LTE_Band41_SUB_0_Freq          25575
#define ET_LTE_Band41_SUB_1_Freq          25715
#define ET_LTE_Band41_SUB_2_Freq          25855
#define ET_LTE_Band41_SUB_3_Freq          25995
#define ET_LTE_Band41_SUB_4_Freq          26105
#define ET_LTE_Band41_SUB_5_Freq          26245
#define ET_LTE_Band41_SUB_6_Freq          26385
#define ET_LTE_Band41_SUB_7_Freq          26525

/* ================================================================================================== */
/*   LTE ET Calibration Maximum Output  Voltage Settings                                                                                                                                               */
/* ================================================================================================== */
#define LTE_Band1_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             3400
#define LTE_Band2_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             3400
#define LTE_Band3_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             3400
#define LTE_Band4_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             3400
#define LTE_Band5_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             3400
#define LTE_Band7_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             3400
#define LTE_Band8_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             3400
#define LTE_Band12_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band13_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band17_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band20_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band25_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band26_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band28_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band29_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            LTE_BandNone_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault
#define LTE_Band30_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band38_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band39_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band40_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band41_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            3400
#define LTE_Band38_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault     3400
#define LTE_Band39_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault     3400
#define LTE_Band40_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault     3400
#define LTE_Band41_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault     3400       

/* ================================================================================================== */
/*   LTE ET Calibration Minimum Output  Voltage Settings                                                                                                                                               */
/* ================================================================================================== */
#define LTE_Band1_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             1187
#define LTE_Band2_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             1187
#define LTE_Band3_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             1187
#define LTE_Band4_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             1187
#define LTE_Band5_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             1187
#define LTE_Band7_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             1187
#define LTE_Band8_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault             1187
#define LTE_Band12_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band13_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band17_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band20_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band25_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band26_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band28_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band29_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            LTE_BandNone_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault
#define LTE_Band30_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band38_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band39_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band40_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band41_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault            1187
#define LTE_Band38_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault     1187
#define LTE_Band39_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault     1187
#define LTE_Band40_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault     1187
#define LTE_Band41_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault     1187

/* ================================================================================================== */
/*   LTE ET TX_ON / TX_OFF / TPC Event Timing Offset Settings                                                                                                                                     */
/* ================================================================================================== */

#if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define TIME_DURATION_BETWEEN_BIAS_EN_AND_BANK_EN                    US2OFFCNT( 25 )   // MT6300 needs 20us between BIAS_EN and BANK_EN, make sure that there is 20us difference between TX_ON0 and TX_ON1.
#define TIME_DURATION_BETWEEN_WARM_UP_AND_DISABLE_HFP_FPFM           US2OFFCNT( 20 )   // 18us after warm-up voltage rising, disable HFP forced PFM.
#define TIME_DURATION_BETWEEN_DISABLE_HFP_FPFM_AND_DISABLE_OCP       US2OFFCNT( 60 )   // 50us after disabling HFP force PFM and enabling OCP, disable OCP.
#define TX_ON_SEQUENCE_END_TIMING                                    US2OFFCNT( 70 )   // The end point of TX_ON sequence.

#define LTE_ET_TX_ON3                                                ( TX_ON_SEQUENCE_END_TIMING )                                                //  70
#define LTE_ET_TX_ON2                                                ( LTE_ET_TX_ON3 + TIME_DURATION_BETWEEN_DISABLE_HFP_FPFM_AND_DISABLE_OCP )   // 130
#define LTE_ET_TX_ON1                                                ( LTE_ET_TX_ON2 + TIME_DURATION_BETWEEN_WARM_UP_AND_DISABLE_HFP_FPFM     )   // 150
#define LTE_ET_TX_ON0                                                ( LTE_ET_TX_ON1 + TIME_DURATION_BETWEEN_BIAS_EN_AND_BANK_EN              )   // 175

#define LTE_ET_TX_OFF0                                               US2OFFCNT(  0 )

#define LTE_ETM_TPC_E1_SPENT_TIME                                    US2OFFCNT(  5 )
#define LTE_ETM_TPC_E2_SPENT_TIME                                    US2OFFCNT(  5 )
#define LTE_ETM_TPC_SEQUENCE_END_TIMING                              US2OFFCNT( 28 )

#define LTE_ET_TPC_OFFSET                                            ( LTE_ETM_TPC_SEQUENCE_END_TIMING )
#define LTE_ET_BANK_PRELOAD_OFFSET_2                                 ( LTE_ET_TPC_OFFSET + LTE_ETM_TPC_E2_SPENT_TIME )
#define LTE_ET_BANK_PRELOAD_OFFSET_1                                 ( LTE_ET_BANK_PRELOAD_OFFSET_2 + LTE_ETM_TPC_E1_SPENT_TIME )

#else

#error "ETM chip type is not defined or defined as one unknown chip!"

#endif   // #if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )



/* ================================================================================================== */
/*   LTE ET TX_ON / TX_OFF / TPC Data Start and End Settings                                                                                                                                     */
/* ================================================================================================== */

#if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define LTE_ET_TX_ON_DATA_START_ADDRESS_0                            (  0 )
#define LTE_ET_TX_ON_DATA_STOP_ADDRESS_0                             (  4 )

#define LTE_ET_TX_ON_DATA_START_ADDRESS_1                            (  5 )
#define LTE_ET_TX_ON_DATA_STOP_ADDRESS_1                             (  6 )

#define LTE_ET_TX_ON_DATA_START_ADDRESS_2                            (  7 )
#define LTE_ET_TX_ON_DATA_STOP_ADDRESS_2                             (  8 )

#define LTE_ET_TX_ON_DATA_START_ADDRESS_3                            (  9 )
#define LTE_ET_TX_ON_DATA_STOP_ADDRESS_3                             (  9 )

#define LTE_ET_TX_OFF_DATA_START_ADDRESS                             ( 10 )
#define LTE_ET_TX_OFF_DATA_STOP_ADDRESS                              ( 13 )

#define LTE_ET_TPC_BANK_PRELOAD_START_ADDRESS_1                      (  0 )
#define LTE_ET_TPC_BANK_PRELOAD_STOP_ADDRESS_1                       (  4 )

#define LTE_ET_TPC_BANK_PRELOAD_START_ADDRESS_2                      (  5 )
#define LTE_ET_TPC_BANK_PRELOAD_STOP_ADDRESS_2                       (  8 )

#define LTE_ET_TPC_BANK_SWITCH_START_ADDRESS                         (  9 )
#define LTE_ET_TPC_BANK_SWITCH_STOP_ADDRESS                          (  9 )

#else

#error "ETM chip type is not defined or defined as one unknown chip!"

#endif   // #if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )



/* ================================================================================================== */
/*   LTE ET Global Register Settings                                                                                                                                                                               */
/* ================================================================================================== */

#if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define LTE_ET_HFP_DAC_THRESHOLD1                                    LTE_ET_MT6300_HFP_DAC_THRESHOLD1
#define LTE_ET_HFP_DAC_THRESHOLD2                                    LTE_ET_MT6300_HFP_DAC_THRESHOLD2
#define LTE_ET_HFP_DAC_THRESHOLD3                                    LTE_ET_MT6300_HFP_DAC_THRESHOLD3

#define LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault                          LTE_ET_MT6300_HFP_EA_RSS_LEVEL0
#define LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault                          LTE_ET_MT6300_HFP_EA_RSS_LEVEL1
#define LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault                          LTE_ET_MT6300_HFP_EA_RSS_LEVEL2
#define LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault                          LTE_ET_MT6300_HFP_EA_RSS_LEVEL3



#define LTE_ET_RG_HFP_BYPASS_EN_SETTING_ET_MODE                      ET_MT6300_RG_HFP_BYPASS_DISABLE
#define LTE_ET_RG_HFP_AUTO_BYPASS_EN_SETTING_ET_MODE                 ET_MT6300_RG_HFP_AUTO_BYPASS_DISABLE
#define LTE_ET_RG_HFP_FPWM_SETTING_ET_MODE                           ET_MT6300_RG_HFP_FPWM_ENABLE
#define LTE_ET_RG_LFP_FPWM_SETTING_ET_MODE                           ET_MT6300_RG_LFP_FPWM_ENABLE
#define LTE_ET_RG_LFP_EN_SETTING_ET_MODE                             ET_MT6300_RG_LFP_ENABLE
#define LTE_ET_RG_HFP_EN_SETTING_ET_MODE                             ET_MT6300_RG_HFP_ENABLE
#define LTE_ET_RG_ET_MODE_SETTING_ET_MODE                            ET_MT6300_RG_ET_MODE_ENABLE



#define LTE_ET_RG_HFP_BYPASS_EN_SETTING_APT_MODE                     ET_MT6300_RG_HFP_BYPASS_DISABLE
#define LTE_ET_RG_HFP_AUTO_BYPASS_EN_SETTING_APT_MODE                ET_MT6300_RG_HFP_AUTO_BYPASS_DISABLE
#define LTE_ET_RG_HFP_FPWM_SETTING_APT_MODE                          ET_MT6300_RG_HFP_FPWM_ENABLE
#define LTE_ET_RG_LFP_FPWM_SETTING_APT_MODE                          ET_MT6300_RG_LFP_FPWM_DISABLE
#define LTE_ET_RG_LFP_EN_SETTING_APT_MODE                            ET_MT6300_RG_LFP_DISABLE
#define LTE_ET_RG_HFP_EN_SETTING_APT_MODE                            ET_MT6300_RG_HFP_ENABLE
#define LTE_ET_RG_ET_MODE_SETTING_APT_MODE                           ET_MT6300_RG_ET_MODE_DISABLE

#define LTE_ET_RG09_SETTING_DISABLE                                  ( 0x00 )

#define LTE_ET_LFP_PWRSEL_MODE_APT_MODE                              ET_MT6300_LFP_PWRSEL_MODE_FROM_BATTERY
#define LTE_ET_LFP_PWRSEL_MODE_ET_MODE                               ET_MT6300_LFP_PWRSEL_MODE_FROM_BATTERY

#else

#error "ETM chip type is not defined or defined as one unknown chip!"

#endif   // #if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )



/* ================================================================================================== */
/*   LTE ET TX_ON / TX_OFF Data Table Settings                                                                                                                                                           */
/* ================================================================================================== */

#define LTE_ET_TX_ON_BIAS_ENABLE_DATA                                ( 0x70 )
#define LTE_ET_TX_ON_REG_BANK_WRITE_SELECTION                        ( 0x00 )

#define LTE_ETM_WARM_UP_VOLTAGE_REGISTER_VALUE                       ( 0x0C )   // LTE ETM Warm-Up Voltage Settings

#define LTE_ET_TX_ON_BANK_ENABLE_DATA                                ( 0x74 )
#define LTE_ET_TX_OFF_BIAS_DISABLE_DATA                              ( 0x00 )



/* ================================================================================================== */
/*   LTE ET TPC Data Table Settings                                                                                                                                                                              */
/* ================================================================================================== */

#if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define LTE_ET_TPC_RG_BK_WR_SEL_DEFAULT_SETTING                      ( 0x00 )

#else

#error "ETM chip type is not defined or defined as one unknown chip!"

#endif   // #if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define LTE_ET_TPC_SECTION_DATA1_LEVEL0_SetDefault                              ( 0x14 )
#define LTE_ET_TPC_SECTION_DATA1_LEVEL1_SetDefault                              ( 0x1E )
#define LTE_ET_TPC_SECTION_DATA1_LEVEL2_SetDefault                              ( 0x23 )
#define LTE_ET_TPC_SECTION_DATA1_LEVEL3_SetDefault                              ( 0x28 )
#define LTE_ET_TPC_SECTION_DATA1_LEVEL4_SetDefault                              ( 0x32 )
#define LTE_ET_TPC_SECTION_DATA1_LEVEL5_SetDefault                              ( 0x3C )
#define LTE_ET_TPC_SECTION_DATA1_LEVEL6_SetDefault                              ( 0x46 )
#define LTE_ET_TPC_SECTION_DATA1_LEVEL7_SetDefault                              ( 0x55 )
#define LTE_ET_TPC_SECTION_DATA1_LEVEL8_SetDefault                              ( LTE_ETM_WARM_UP_VOLTAGE_REGISTER_VALUE )   // SRS Blanking



/* ================================================================================================== */
/*   LTE ET VPA LUT  Data Table Settings                                                                                                                                                                       */
/* ================================================================================================== */

#if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL0_SetDefault                          0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL1_SetDefault                          0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL2_SetDefault                          0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL3_SetDefault                          0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL4_SetDefault                          0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL5_SetDefault                          0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL6_SetDefault                          0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL7_SetDefault                          0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL8_SetDefault                          0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL9_SetDefault                          0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL10_SetDefault                         0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL11_SetDefault                         0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL12_SetDefault                         0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL13_SetDefault                         0x00
#define LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL14_SetDefault                         0x00

#else

#error "ETM chip type is not defined or defined as one unknown chip!"

#endif   // #if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )


#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL0_SetDefault               0x22
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL1_SetDefault               0x21
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL2_SetDefault               0x20
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL3_SetDefault               0x1F
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL4_SetDefault               0x1E
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL5_SetDefault               0x1D
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL6_SetDefault               0x1C
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL7_SetDefault               0x1B
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL8_SetDefault               0x1B
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL9_SetDefault               0x1A
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL10_SetDefault              0x19
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL11_SetDefault              0x19
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL12_SetDefault              0x18
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL13_SetDefault              0x18
#define LTE_ET_LOOKUP_VPA_SECTION_DATA0_LEVEL14_SetDefault              0x17

#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL0_SetDefault               0x57
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL1_SetDefault               0x58
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL2_SetDefault               0x59
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL3_SetDefault               0x5A
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL4_SetDefault               0x5B
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL5_SetDefault               0x56
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL6_SetDefault               0x52
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL7_SetDefault               0x4D
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL8_SetDefault               0x4A
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL9_SetDefault               0x46
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL10_SetDefault              0x43
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL11_SetDefault              0x40
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL12_SetDefault              0x3E
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL13_SetDefault              0x3B
#define LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL14_SetDefault              0x39



/* ================================================================================================== */
/*   LTE ET BW Data Table Settings                                                                                                                                                                               */
/* ================================================================================================== */

#if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#define LTE_ET_BAND1_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND1_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND1_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND1_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND1_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND1_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND1_RG_LA_INBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND1_RG_LA_INBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND1_RG_LA_INBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND1_RG_LA_INBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND1_RG_LA_INBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND1_RG_LA_INBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND1_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND1_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND1_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND1_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND1_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND1_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND1_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND1_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND1_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND1_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND1_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND1_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND1_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND1_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND1_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND1_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND1_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND1_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND1_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND1_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND1_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND1_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND1_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND1_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND1_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND1_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND1_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND1_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND1_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND1_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND1_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND1_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND1_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND1_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND1_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND1_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND1_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND1_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND1_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND1_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND1_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND1_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND2_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND2_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND2_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND2_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND2_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND2_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND2_RG_LA_INBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND2_RG_LA_INBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND2_RG_LA_INBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND2_RG_LA_INBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND2_RG_LA_INBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND2_RG_LA_INBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND2_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND2_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND2_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND2_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND2_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND2_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND2_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND2_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND2_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND2_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND2_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND2_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND2_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND2_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND2_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND2_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND2_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND2_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND2_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND2_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND2_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND2_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND2_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND2_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND2_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND2_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND2_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND2_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND2_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND2_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND2_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND2_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND2_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND2_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND2_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND2_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND2_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND2_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND2_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND2_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND2_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND2_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND3_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND3_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND3_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND3_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND3_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND3_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND3_RG_LA_INBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND3_RG_LA_INBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND3_RG_LA_INBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND3_RG_LA_INBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND3_RG_LA_INBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND3_RG_LA_INBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND3_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND3_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND3_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND3_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND3_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND3_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND3_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND3_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND3_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND3_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND3_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND3_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND3_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND3_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND3_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND3_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND3_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND3_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND3_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND3_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND3_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND3_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND3_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND3_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND3_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND3_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND3_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND3_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND3_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND3_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND3_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND3_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND3_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND3_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND3_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND3_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND3_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND3_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND3_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND3_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND3_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND3_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND4_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND4_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND4_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND4_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND4_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND4_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND4_RG_LA_INBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND4_RG_LA_INBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND4_RG_LA_INBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND4_RG_LA_INBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND4_RG_LA_INBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND4_RG_LA_INBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND4_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND4_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND4_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND4_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND4_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND4_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND4_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND4_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND4_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND4_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND4_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND4_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND4_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND4_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND4_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND4_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND4_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND4_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND4_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND4_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND4_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND4_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND4_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND4_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND4_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND4_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND4_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND4_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND4_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND4_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND4_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND4_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND4_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND4_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND4_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND4_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND4_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND4_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND4_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND4_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND4_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND4_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND5_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND5_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND5_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND5_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND5_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND5_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND5_RG_LA_INBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND5_RG_LA_INBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND5_RG_LA_INBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND5_RG_LA_INBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND5_RG_LA_INBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND5_RG_LA_INBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND5_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND5_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND5_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND5_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND5_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND5_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND5_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND5_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND5_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_2
#define LTE_ET_BAND5_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND5_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND5_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND5_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND5_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND5_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND5_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND5_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND5_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND5_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND5_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND5_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL7
#define LTE_ET_BAND5_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND5_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND5_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND5_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND5_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND5_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND5_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND5_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND5_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND5_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND5_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND5_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND5_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND5_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND5_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND5_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND5_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND5_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND5_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND5_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND5_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND7_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND7_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND7_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND7_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND7_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND7_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND7_RG_LA_INBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND7_RG_LA_INBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND7_RG_LA_INBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND7_RG_LA_INBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND7_RG_LA_INBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND7_RG_LA_INBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND7_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND7_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND7_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND7_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND7_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND7_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND7_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND7_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND7_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND7_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND7_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND7_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND7_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND7_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND7_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND7_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND7_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND7_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND7_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND7_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND7_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND7_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND7_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND7_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4_SetDefault

#define LTE_ET_BAND7_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND7_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND7_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND7_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND7_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND7_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND7_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND7_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND7_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND7_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND7_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND7_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND7_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND7_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND7_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND7_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND7_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND7_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND8_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND8_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND8_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND8_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND8_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND8_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault               ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND8_RG_LA_INBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND8_RG_LA_INBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND8_RG_LA_INBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND8_RG_LA_INBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND8_RG_LA_INBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND8_RG_LA_INBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND8_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND8_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND8_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND8_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND8_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND8_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                 ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND8_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND8_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND8_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_2
#define LTE_ET_BAND8_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND8_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND8_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND8_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND8_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND8_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND8_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND8_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND8_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND8_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND8_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND8_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL7
#define LTE_ET_BAND8_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND8_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND8_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND8_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND8_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND8_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND8_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND8_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND8_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND8_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND8_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND8_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND8_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND8_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                       ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND8_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                       ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND8_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND8_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND8_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND8_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND8_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND8_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                     ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND12_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND12_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND12_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND12_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND12_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND12_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND12_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND12_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND12_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND12_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND12_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND12_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND12_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND12_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND12_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND12_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND12_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND12_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND12_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND12_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND12_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND12_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND12_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND12_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND12_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND12_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND12_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND12_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND12_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND12_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND12_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND12_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND12_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND12_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND12_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND12_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND12_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND12_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND12_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND12_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND12_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND12_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND12_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND12_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND12_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND12_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND12_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND12_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND12_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND12_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND12_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND12_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND12_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND12_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND13_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND13_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND13_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND13_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND13_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND13_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND13_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND13_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND13_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND13_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND13_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND13_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND13_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND13_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND13_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND13_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND13_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND13_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND13_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND13_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND13_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND13_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND13_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND13_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND13_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND13_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND13_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND13_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND13_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND13_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND13_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND13_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND13_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND13_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND13_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND13_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND13_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND13_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND13_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND13_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND13_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND13_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND13_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND13_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND13_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND13_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND13_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND13_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND13_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND13_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND13_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND13_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND13_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND13_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND17_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND17_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND17_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND17_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND17_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND17_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND17_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND17_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND17_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND17_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND17_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND17_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND17_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND17_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND17_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND17_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND17_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND17_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND17_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND17_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND17_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND17_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND17_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND17_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND17_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND17_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND17_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND17_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND17_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND17_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND17_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND17_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND17_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND17_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND17_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND17_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND17_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND17_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND17_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND17_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND17_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND17_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND17_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND17_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND17_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND17_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND17_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND17_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND17_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND17_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND17_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND17_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND17_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND17_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND20_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND20_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND20_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND20_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND20_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND20_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND20_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND20_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND20_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND20_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND20_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND20_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND20_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND20_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND20_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND20_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND20_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND20_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND20_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND20_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND20_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND20_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND20_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND20_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND20_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND20_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND20_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND20_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND20_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND20_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND20_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND20_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND20_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND20_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND20_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND20_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND20_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND20_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND20_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND20_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND20_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND20_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND20_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND20_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND20_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND20_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND20_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND20_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND20_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND20_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND20_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND20_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND20_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND20_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND26_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND26_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND26_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND26_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND26_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND26_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND26_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND26_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND26_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND26_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND26_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND26_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND26_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND26_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND26_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND26_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND26_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND26_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND26_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND26_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND26_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND26_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND26_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND26_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND26_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND26_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND26_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND26_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND26_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND26_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND26_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND26_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND26_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND26_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND26_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND26_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND26_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND26_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND26_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND26_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND26_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND26_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND26_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND26_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND26_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND26_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND26_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND26_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND26_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND26_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND26_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND26_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND26_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND26_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND28_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND28_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND28_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND28_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND28_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND28_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND28_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND28_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND28_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND28_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND28_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND28_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND28_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND28_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND28_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND28_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND28_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND28_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND28_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND28_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND28_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND28_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND28_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND28_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND28_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND28_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND28_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND28_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND28_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND28_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND28_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND28_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND28_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND28_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND28_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND28_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND28_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND28_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND28_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND28_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND28_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND28_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND28_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND28_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND28_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND28_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND28_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND28_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND28_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND28_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND28_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND28_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND28_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND28_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND30_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND30_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND30_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND30_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND30_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND30_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND30_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND30_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND30_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND30_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND30_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND30_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND30_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND30_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND30_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND30_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND30_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND30_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND30_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND30_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND30_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND30_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND30_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND30_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND30_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND30_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND30_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND30_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND30_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND30_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND30_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND30_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND30_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND30_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND30_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND30_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND30_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND30_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND30_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND30_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND30_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND30_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND30_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND30_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND30_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND30_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND30_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND30_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND30_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND30_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND30_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND30_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND30_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND30_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND38_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND38_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND38_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND38_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND38_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND38_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND38_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND38_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND38_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND38_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND38_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND38_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND38_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND38_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND38_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND38_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND38_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND38_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND38_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND38_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND38_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND38_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND38_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND38_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND38_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND38_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND38_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND38_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND38_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND38_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND38_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND38_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND38_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND38_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND38_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND38_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND38_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND38_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND38_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND38_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND38_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND38_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND38_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND38_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND38_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND38_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND38_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND38_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND38_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND38_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND38_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND38_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND38_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND38_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND39_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND39_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND39_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND39_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND39_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND39_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND39_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND39_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND39_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND39_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND39_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND39_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND39_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND39_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND39_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND39_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND39_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND39_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND39_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND39_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND39_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND39_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND39_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND39_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND39_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND39_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND39_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND39_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND39_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND39_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND39_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND39_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND39_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND39_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND39_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND39_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND39_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND39_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND39_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND39_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND39_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND39_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND39_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND39_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND39_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND39_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND39_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND39_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND39_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND39_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND39_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND39_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND39_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND39_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND40_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND40_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND40_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND40_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND40_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND40_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND40_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND40_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND40_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND40_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND40_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND40_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND40_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND40_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND40_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND40_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND40_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND40_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND40_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND40_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND40_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND40_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND40_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND40_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND40_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND40_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND40_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND40_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND40_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND40_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND40_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5_SetDefault
#define LTE_ET_BAND40_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4_SetDefault
#define LTE_ET_BAND40_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4_SetDefault
#define LTE_ET_BAND40_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5_SetDefault
#define LTE_ET_BAND40_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6_SetDefault
#define LTE_ET_BAND40_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4_SetDefault

#define LTE_ET_BAND40_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND40_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND40_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND40_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND40_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND40_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND40_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND40_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND40_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND40_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND40_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND40_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND40_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND40_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND40_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND40_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND40_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND40_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#define LTE_ET_BAND41_RG_LA_LOW_POWER_EN_SETTING_LEVEL0_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND41_RG_LA_LOW_POWER_EN_SETTING_LEVEL1_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND41_RG_LA_LOW_POWER_EN_SETTING_LEVEL2_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_ON
#define LTE_ET_BAND41_RG_LA_LOW_POWER_EN_SETTING_LEVEL3_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND41_RG_LA_LOW_POWER_EN_SETTING_LEVEL4_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF
#define LTE_ET_BAND41_RG_LA_LOW_POWER_EN_SETTING_LEVEL5_SetDefault              ET_MT6300_RG_LA_LOW_POWER_EN_OFF

#define LTE_ET_BAND41_RG_LA_INBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND41_RG_LA_INBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_2
#define LTE_ET_BAND41_RG_LA_INBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_INBW_10_50MHZ_1
#define LTE_ET_BAND41_RG_LA_INBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_INBW_14_20MHZ
#define LTE_ET_BAND41_RG_LA_INBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_INBW_22_20MHZ
#define LTE_ET_BAND41_RG_LA_INBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_INBW_50_00MHZ

#define LTE_ET_BAND41_RG_LA_INBUF_BIAS_SETTING_LEVEL0_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND41_RG_LA_INBUF_BIAS_SETTING_LEVEL1_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND41_RG_LA_INBUF_BIAS_SETTING_LEVEL2_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND41_RG_LA_INBUF_BIAS_SETTING_LEVEL3_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND41_RG_LA_INBUF_BIAS_SETTING_LEVEL4_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00
#define LTE_ET_BAND41_RG_LA_INBUF_BIAS_SETTING_LEVEL5_SetDefault                ET_MT6300_RG_LA_INBUF_BIAS_X_1_00

#define LTE_ET_BAND41_RG_LA_BIAS_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND41_RG_LA_BIAS_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND41_RG_LA_BIAS_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_4
#define LTE_ET_BAND41_RG_LA_BIAS_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND41_RG_LA_BIAS_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_0
#define LTE_ET_BAND41_RG_LA_BIAS_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_BIAS_X_1_2

#define LTE_ET_BAND41_RG_LA_HIGH4V_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND41_RG_LA_HIGH4V_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND41_RG_LA_HIGH4V_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND41_RG_LA_HIGH4V_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND41_RG_LA_HIGH4V_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE
#define LTE_ET_BAND41_RG_LA_HIGH4V_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_HIGH4V_FALSE

#define LTE_ET_BAND41_RG_LA_OUTBIAS_SETTING_LEVEL0_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND41_RG_LA_OUTBIAS_SETTING_LEVEL1_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND41_RG_LA_OUTBIAS_SETTING_LEVEL2_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4
#define LTE_ET_BAND41_RG_LA_OUTBIAS_SETTING_LEVEL3_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL5
#define LTE_ET_BAND41_RG_LA_OUTBIAS_SETTING_LEVEL4_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL6
#define LTE_ET_BAND41_RG_LA_OUTBIAS_SETTING_LEVEL5_SetDefault                   ET_MT6300_RG_LA_OUTBIAS_LEVEL4

#define LTE_ET_BAND41_RG_LA_OPBW_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND41_RG_LA_OPBW_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND41_RG_LA_OPBW_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPBW_002P
#define LTE_ET_BAND41_RG_LA_OPBW_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPBW_001P
#define LTE_ET_BAND41_RG_LA_OPBW_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPBW_200F
#define LTE_ET_BAND41_RG_LA_OPBW_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPBW_200F

#define LTE_ET_BAND41_RG_LA_OPFF_SETTING_LEVEL0_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND41_RG_LA_OPFF_SETTING_LEVEL1_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND41_RG_LA_OPFF_SETTING_LEVEL2_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND41_RG_LA_OPFF_SETTING_LEVEL3_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND41_RG_LA_OPFF_SETTING_LEVEL4_SetDefault                      ET_MT6300_RG_LA_OPFF_ON
#define LTE_ET_BAND41_RG_LA_OPFF_SETTING_LEVEL5_SetDefault                      ET_MT6300_RG_LA_OPFF_ON

#define LTE_ET_BAND41_RG_LA_OPLOAD_SETTING_LEVEL0_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND41_RG_LA_OPLOAD_SETTING_LEVEL1_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND41_RG_LA_OPLOAD_SETTING_LEVEL2_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND41_RG_LA_OPLOAD_SETTING_LEVEL3_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND41_RG_LA_OPLOAD_SETTING_LEVEL4_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE
#define LTE_ET_BAND41_RG_LA_OPLOAD_SETTING_LEVEL5_SetDefault                    ET_MT6300_RG_LA_OPLOAD_3_STAGE

#else

#error "ETM chip type is not defined or defined as one unknown chip!"

#endif   // #if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )



/* ================================================================================================== */
/*   LTE ET Mode Setting Data Table Definition                                                                                                                                                               */
/* ================================================================================================== */

#if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )

#elif( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_A60935B ) )

// SW2 Auto Bypass Enable Flag Setting. "1" means "Enable Auto-Bypass Function"; "0" means "Disable Auto-Bypass Function".
#define LTE_ET_SW2_AUTO_BYPASS_ENABLE_FLAG                   0

#define LTE_ET_TPC_SECTION_DATA0_ET_MODE_W_AUTO_BYPASS       0x57
#define LTE_ET_TPC_SECTION_DATA0_ET_MODE_WO_AUTO_BYPASS      0x17

#if LTE_ET_SW2_AUTO_BYPASS_ENABLE_FLAG

#define LTE_ET_TPC_ET_MODE_SETTING                           LTE_ET_TPC_SECTION_DATA0_ET_MODE_W_AUTO_BYPASS

#else

#define LTE_ET_TPC_ET_MODE_SETTING                           LTE_ET_TPC_SECTION_DATA0_ET_MODE_WO_AUTO_BYPASS

#endif   // #if LTE_ET_SW2_AUTO_BYPASS_ENABLE_FLAG

#define LTE_ET_TPC_LFP_POWER_SELECTION_ET_MODE_SETTING       0x20

#else

#error "ETM chip type is not defined or defined as one unknown chip!"

#endif   // #if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )



/* =================================================================================================================================================== */
/*   DO NOT MODIFY THE BELOW DATA!   DO NOT MODIFY THE BELOW DATA!   DO NOT MODIFY THE BELOW DATA!   DO NOT MODIFY THE BELOW DATA!   DO NOT MODIFY THE BELOW DATA!   DO NOT MODIFY THE BELOW DATA! */
/* =================================================================================================================================================== */

#if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )



#define LTE_ET_RG_HFP_BYPASS_EN_PART_ET_MODE                         ( ( ( LTE_ET_RG_HFP_BYPASS_EN_SETTING_ET_MODE       ) << ET_MT6300_RG_HFP_BYPASS_EN_SHIFT      ) & ET_MT6300_RG_HFP_BYPASS_EN_MASK      )
#define LTE_ET_RG_HFP_BYPASS_EN_PART_APT_MODE                        ( ( ( LTE_ET_RG_HFP_BYPASS_EN_SETTING_APT_MODE      ) << ET_MT6300_RG_HFP_BYPASS_EN_SHIFT      ) & ET_MT6300_RG_HFP_BYPASS_EN_MASK      )

#define LTE_ET_RG_HFP_AUTO_BYPASS_EN_PART_ET_MODE                    ( ( ( LTE_ET_RG_HFP_AUTO_BYPASS_EN_SETTING_ET_MODE  ) << ET_MT6300_RG_HFP_AUTO_BYPASS_EN_SHIFT ) & ET_MT6300_RG_HFP_AUTO_BYPASS_EN_MASK )
#define LTE_ET_RG_HFP_AUTO_BYPASS_EN_PART_APT_MODE                   ( ( ( LTE_ET_RG_HFP_AUTO_BYPASS_EN_SETTING_APT_MODE ) << ET_MT6300_RG_HFP_AUTO_BYPASS_EN_SHIFT ) & ET_MT6300_RG_HFP_AUTO_BYPASS_EN_MASK )

#define LTE_ET_RG_HFP_FPWM_PART_ET_MODE                              ( ( ( LTE_ET_RG_HFP_FPWM_SETTING_ET_MODE            ) << ET_MT6300_RG_HFP_FPWM_SHIFT           ) & ET_MT6300_RG_HFP_FPWM_MASK           )
#define LTE_ET_RG_HFP_FPWM_PART_APT_MODE                             ( ( ( LTE_ET_RG_HFP_FPWM_SETTING_APT_MODE           ) << ET_MT6300_RG_HFP_FPWM_SHIFT           ) & ET_MT6300_RG_HFP_FPWM_MASK           )

#define LTE_ET_RG_LFP_FPWM_PART_ET_MODE                              ( ( ( LTE_ET_RG_LFP_FPWM_SETTING_ET_MODE            ) << ET_MT6300_RG_LFP_FPWM_SHIFT           ) & ET_MT6300_RG_LFP_FPWM_MASK           )
#define LTE_ET_RG_LFP_FPWM_PART_APT_MODE                             ( ( ( LTE_ET_RG_LFP_FPWM_SETTING_APT_MODE           ) << ET_MT6300_RG_LFP_FPWM_SHIFT           ) & ET_MT6300_RG_LFP_FPWM_MASK           )

#define LTE_ET_RG_LFP_EN_PART_ET_MODE                                ( ( ( LTE_ET_RG_LFP_EN_SETTING_ET_MODE              ) << ET_MT6300_RG_LFP_EN_SHIFT             ) & ET_MT6300_RG_LFP_EN_MASK             )
#define LTE_ET_RG_LFP_EN_PART_APT_MODE                               ( ( ( LTE_ET_RG_LFP_EN_SETTING_APT_MODE             ) << ET_MT6300_RG_LFP_EN_SHIFT             ) & ET_MT6300_RG_LFP_EN_MASK             )

#define LTE_ET_RG_HFP_EN_PART_ET_MODE                                ( ( ( LTE_ET_RG_HFP_EN_SETTING_ET_MODE              ) << ET_MT6300_RG_HFP_EN_SHIFT             ) & ET_MT6300_RG_HFP_EN_MASK             )
#define LTE_ET_RG_HFP_EN_PART_APT_MODE                               ( ( ( LTE_ET_RG_HFP_EN_SETTING_APT_MODE             ) << ET_MT6300_RG_HFP_EN_SHIFT             ) & ET_MT6300_RG_HFP_EN_MASK             )

#define LTE_ET_RG_ET_MODE_PART_ET_MODE                               ( ( ( LTE_ET_RG_ET_MODE_SETTING_ET_MODE             ) << ET_MT6300_RG_ET_MODE_SHIFT            ) & ET_MT6300_RG_ET_MODE_MASK            )
#define LTE_ET_RG_ET_MODE_PART_APT_MODE                              ( ( ( LTE_ET_RG_ET_MODE_SETTING_APT_MODE            ) << ET_MT6300_RG_ET_MODE_SHIFT            ) & ET_MT6300_RG_ET_MODE_MASK            )



#define LTE_ET_RG09_SETTING_APT_MODE_E1_VER_SetDefault                          ( 0x02 )
#define LTE_ET_RG09_SETTING_APT_MODE_E2_VER_SetDefault                          ( 0x42 )

#if ( defined( ETM_MTK_MT6300_VERSION ) && ( ETM_MTK_MT6300_VERSION == ETM_MTK_MT6300_E1 ) )

#define LTE_ET_RG09_SETTING_APT_MODE_SetDefault                                 LTE_ET_RG09_SETTING_APT_MODE_E1_VER_SetDefault

#elif ( defined( ETM_MTK_MT6300_VERSION ) && ( ETM_MTK_MT6300_VERSION == ETM_MTK_MT6300_E2 ) )

#define LTE_ET_RG09_SETTING_APT_MODE_SetDefault                                 LTE_ET_RG09_SETTING_APT_MODE_E2_VER_SetDefault

#endif



#define LTE_ET_RG09_SETTING_ET_MODE_E1_VER_SetDefault                           ( 0x17 )
#define LTE_ET_RG09_SETTING_ET_MODE_E2_VER_SetDefault                           ( 0x47 )

#if ( defined( ETM_MTK_MT6300_VERSION ) && ( ETM_MTK_MT6300_VERSION == ETM_MTK_MT6300_E1 ) )

#define LTE_ET_RG09_SETTING_ET_MODE_SetDefault                                  LTE_ET_RG09_SETTING_ET_MODE_E1_VER_SetDefault

#elif ( defined( ETM_MTK_MT6300_VERSION ) && ( ETM_MTK_MT6300_VERSION == ETM_MTK_MT6300_E2 ) )

#define LTE_ET_RG09_SETTING_ET_MODE_SetDefault                                  LTE_ET_RG09_SETTING_ET_MODE_E2_VER_SetDefault

#endif



#define LTE_ET_RG6D_SETTING_HFP_WITH_PFM                             ( 0x0B )
#define LTE_ET_RG6D_SETTING_HFP_NO_PFM                               ( 0x07 )

#define LTE_ET_RG83_SETTING_OTP_EN_OCP_EN                            ( 0x03 )
#define LTE_ET_RG83_SETTING_OTP_EN_OCP_DIS                           ( 0x00 )

#define LTE_ET_RG8E_SETTING_RESET_OCP_OTP                            ( 0x03 )

#define LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING                   ( ( ( LTE_ET_LFP_PWRSEL_MODE_APT_MODE ) << ET_MT6300_LFP_PWRSEL_MODE_SHIFT ) & ET_MT6300_LFP_PWRSEL_MODE_MASK )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_MODE                            ( ( ( LTE_ET_LFP_PWRSEL_MODE_ET_MODE  ) << ET_MT6300_LFP_PWRSEL_MODE_SHIFT ) & ET_MT6300_LFP_PWRSEL_MODE_MASK )

#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault                       ( ( ( LTE_Band1_ET_OUTER_LOOP_GAIN_SETTING_SetDefault  ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault                       ( ( ( LTE_Band2_ET_OUTER_LOOP_GAIN_SETTING_SetDefault  ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault                       ( ( ( LTE_Band3_ET_OUTER_LOOP_GAIN_SETTING_SetDefault  ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault                       ( ( ( LTE_Band4_ET_OUTER_LOOP_GAIN_SETTING_SetDefault  ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault                       ( ( ( LTE_Band5_ET_OUTER_LOOP_GAIN_SETTING_SetDefault  ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault                       ( ( ( LTE_Band7_ET_OUTER_LOOP_GAIN_SETTING_SetDefault  ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault                       ( ( ( LTE_Band8_ET_OUTER_LOOP_GAIN_SETTING_SetDefault  ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band12_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band13_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band17_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band20_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band26_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band28_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band29_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band30_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band38_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band39_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band40_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault                      ( ( ( LTE_Band41_ET_OUTER_LOOP_GAIN_SETTING_SetDefault ) << ET_MT6300_OUTER_LOOP_GAIN_SHIFT ) & ET_MT6300_OUTER_LOOP_GAIN_MASK )

#define LTE_ET_TX_ON_BAND1_RG0A_APT_SETTING_SetDefault                         ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND2_RG0A_APT_SETTING_SetDefault                         ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND3_RG0A_APT_SETTING_SetDefault                         ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND4_RG0A_APT_SETTING_SetDefault                         ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND5_RG0A_APT_SETTING_SetDefault                         ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND7_RG0A_APT_SETTING_SetDefault                         ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND8_RG0A_APT_SETTING_SetDefault                         ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND12_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND13_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND17_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND20_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND26_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND28_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND30_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND38_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND39_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND40_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )
#define LTE_ET_TX_ON_BAND41_RG0A_APT_SETTING_SetDefault                        ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_RG_LFP_PWRSEL_MODE_PART_APT_SETTING ) )

#if( LTE_ETM_WARM_UP_VOLTAGE_REGISTER_VALUE > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TX_ON_HFP_EA_RSS_SETTING_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ETM_WARM_UP_VOLTAGE_REGISTER_VALUE > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_TX_ON_HFP_EA_RSS_SETTING_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ETM_WARM_UP_VOLTAGE_REGISTER_VALUE > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_TX_ON_HFP_EA_RSS_SETTING_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_TX_ON_HFP_EA_RSS_SETTING_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ETM_WARM_UP_VOLTAGE_REGISTER_VALUE > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TPC_SECTION_DATA0_APT_MODE_SetDefault                            LTE_ET_RG09_SETTING_APT_MODE_SetDefault

#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault                      ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL0_SetDefault              ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault                      ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL1_SetDefault              ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault                      ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL2_SetDefault              ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault                      ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL3_SetDefault              ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault                      ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL4_SetDefault              ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault                      ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL5_SetDefault              ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault                      ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL6_SetDefault              ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault                      ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL7_SetDefault              ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault                      ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL8_SetDefault              ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault                      ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL9_SetDefault              ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault                     ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL10_SetDefault             ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault                     ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL11_SetDefault             ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault                     ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL12_SetDefault             ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault                     ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL13_SetDefault             ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )
#define LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault                     ( ( ( LTE_ET_VPA_RG_LFP_PWRSEL_VTH_LEVEL14_SetDefault             ) << ET_MT6300_LFP_PWRSEL_VTH_SHIFT  ) & ET_MT6300_LFP_PWRSEL_VTH_MASK  )

#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL0_SetDefault                      ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL1_SetDefault                      ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL2_SetDefault                      ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL3_SetDefault                      ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL4_SetDefault                      ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL5_SetDefault                      ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL6_SetDefault                      ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL7_SetDefault                      ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL8_SetDefault                      ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL9_SetDefault                      ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL10_SetDefault                     ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL11_SetDefault                     ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL12_SetDefault                     ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL13_SetDefault                     ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND1_RG0A_ET_SETTING_LEVEL14_SetDefault                     ( ( LTE_ET_VPA_BAND1_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL0_SetDefault                      ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL1_SetDefault                      ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL2_SetDefault                      ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL3_SetDefault                      ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL4_SetDefault                      ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL5_SetDefault                      ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL6_SetDefault                      ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL7_SetDefault                      ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL8_SetDefault                      ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL9_SetDefault                      ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL10_SetDefault                     ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL11_SetDefault                     ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL12_SetDefault                     ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL13_SetDefault                     ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND2_RG0A_ET_SETTING_LEVEL14_SetDefault                     ( ( LTE_ET_VPA_BAND2_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL0_SetDefault                      ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL1_SetDefault                      ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL2_SetDefault                      ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL3_SetDefault                      ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL4_SetDefault                      ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL5_SetDefault                      ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL6_SetDefault                      ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL7_SetDefault                      ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL8_SetDefault                      ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL9_SetDefault                      ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL10_SetDefault                     ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL11_SetDefault                     ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL12_SetDefault                     ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL13_SetDefault                     ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND3_RG0A_ET_SETTING_LEVEL14_SetDefault                     ( ( LTE_ET_VPA_BAND3_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL0_SetDefault                      ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL1_SetDefault                      ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL2_SetDefault                      ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL3_SetDefault                      ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL4_SetDefault                      ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL5_SetDefault                      ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL6_SetDefault                      ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL7_SetDefault                      ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL8_SetDefault                      ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL9_SetDefault                      ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL10_SetDefault                     ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL11_SetDefault                     ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL12_SetDefault                     ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL13_SetDefault                     ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND4_RG0A_ET_SETTING_LEVEL14_SetDefault                     ( ( LTE_ET_VPA_BAND4_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL0_SetDefault                      ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL1_SetDefault                      ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL2_SetDefault                      ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL3_SetDefault                      ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL4_SetDefault                      ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL5_SetDefault                      ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL6_SetDefault                      ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL7_SetDefault                      ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL8_SetDefault                      ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL9_SetDefault                      ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL10_SetDefault                     ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL11_SetDefault                     ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL12_SetDefault                     ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL13_SetDefault                     ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND5_RG0A_ET_SETTING_LEVEL14_SetDefault                     ( ( LTE_ET_VPA_BAND5_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL0_SetDefault                      ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL1_SetDefault                      ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL2_SetDefault                      ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL3_SetDefault                      ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL4_SetDefault                      ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL5_SetDefault                      ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL6_SetDefault                      ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL7_SetDefault                      ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL8_SetDefault                      ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL9_SetDefault                      ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL10_SetDefault                     ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL11_SetDefault                     ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL12_SetDefault                     ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL13_SetDefault                     ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND7_RG0A_ET_SETTING_LEVEL14_SetDefault                     ( ( LTE_ET_VPA_BAND7_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL0_SetDefault                      ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL1_SetDefault                      ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL2_SetDefault                      ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL3_SetDefault                      ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL4_SetDefault                      ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL5_SetDefault                      ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL6_SetDefault                      ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL7_SetDefault                      ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL8_SetDefault                      ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL9_SetDefault                      ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL10_SetDefault                     ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL11_SetDefault                     ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL12_SetDefault                     ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL13_SetDefault                     ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND8_RG0A_ET_SETTING_LEVEL14_SetDefault                     ( ( LTE_ET_VPA_BAND8_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND12_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND12_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND13_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND13_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND17_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND17_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND20_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND20_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND26_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND26_RG0A_ET_SETTING_GAIN_SetDefault ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND28_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND28_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND29_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND29_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND30_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND30_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND38_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND38_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND39_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND39_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND40_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND40_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )

#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL0_SetDefault                     ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL0_SetDefault  ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL1_SetDefault                     ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL1_SetDefault  ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL2_SetDefault                     ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL2_SetDefault  ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL3_SetDefault                     ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL3_SetDefault  ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL4_SetDefault                     ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL4_SetDefault  ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL5_SetDefault                     ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL5_SetDefault  ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL6_SetDefault                     ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL6_SetDefault  ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL7_SetDefault                     ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL7_SetDefault  ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL8_SetDefault                     ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL8_SetDefault  ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL9_SetDefault                     ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL9_SetDefault  ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL10_SetDefault                    ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL10_SetDefault ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL11_SetDefault                    ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL11_SetDefault ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL12_SetDefault                    ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL12_SetDefault ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL13_SetDefault                    ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL13_SetDefault ) )
#define LTE_ET_VPA_BAND41_RG0A_ET_SETTING_LEVEL14_SetDefault                    ( ( LTE_ET_VPA_BAND41_RG0A_ET_SETTING_GAIN_SetDefault) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_MODE ) | ( LTE_ET_VPA_ET_SETTING_PWRSEL_VTH_LEVEL14_SetDefault ) )



#define LTE_ET_BAND1_RG0D_SETTING_LEVEL0_SetDefault                             ( 0x8E )
#define LTE_ET_BAND1_RG0D_SETTING_LEVEL1_SetDefault                             ( 0x8E )
#define LTE_ET_BAND1_RG0D_SETTING_LEVEL2_SetDefault                             ( 0x8E )
#define LTE_ET_BAND1_RG0D_SETTING_LEVEL3_SetDefault                             ( 0x08 )
#define LTE_ET_BAND1_RG0D_SETTING_LEVEL4_SetDefault                             ( 0x09 )
#define LTE_ET_BAND1_RG0D_SETTING_LEVEL5_SetDefault                             ( 0x0A )
#define LTE_ET_BAND1_RG0E_SETTING_LEVEL0_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND1_RG0E_SETTING_LEVEL1_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND1_RG0E_SETTING_LEVEL2_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND1_RG0E_SETTING_LEVEL3_SetDefault                             ( 0xFB )
#define LTE_ET_BAND1_RG0E_SETTING_LEVEL4_SetDefault                             ( 0xC2 )
#define LTE_ET_BAND1_RG0E_SETTING_LEVEL5_SetDefault                             ( 0xC2 )                            

#define LTE_ET_BAND2_RG0D_SETTING_LEVEL0_SetDefault                             ( 0x8E )
#define LTE_ET_BAND2_RG0D_SETTING_LEVEL1_SetDefault                             ( 0x8E )
#define LTE_ET_BAND2_RG0D_SETTING_LEVEL2_SetDefault                             ( 0x8E )
#define LTE_ET_BAND2_RG0D_SETTING_LEVEL3_SetDefault                             ( 0x08 )
#define LTE_ET_BAND2_RG0D_SETTING_LEVEL4_SetDefault                             ( 0x09 )
#define LTE_ET_BAND2_RG0D_SETTING_LEVEL5_SetDefault                             ( 0x0A )
#define LTE_ET_BAND2_RG0E_SETTING_LEVEL0_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND2_RG0E_SETTING_LEVEL1_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND2_RG0E_SETTING_LEVEL2_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND2_RG0E_SETTING_LEVEL3_SetDefault                             ( 0xFB )
#define LTE_ET_BAND2_RG0E_SETTING_LEVEL4_SetDefault                             ( 0xC2 )
#define LTE_ET_BAND2_RG0E_SETTING_LEVEL5_SetDefault                             ( 0xC2 )

#define LTE_ET_BAND3_RG0D_SETTING_LEVEL0_SetDefault                             ( 0x8E )
#define LTE_ET_BAND3_RG0D_SETTING_LEVEL1_SetDefault                             ( 0x8E )
#define LTE_ET_BAND3_RG0D_SETTING_LEVEL2_SetDefault                             ( 0x8E )
#define LTE_ET_BAND3_RG0D_SETTING_LEVEL3_SetDefault                             ( 0x08 )
#define LTE_ET_BAND3_RG0D_SETTING_LEVEL4_SetDefault                             ( 0x09 )
#define LTE_ET_BAND3_RG0D_SETTING_LEVEL5_SetDefault                             ( 0x0A )
#define LTE_ET_BAND3_RG0E_SETTING_LEVEL0_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND3_RG0E_SETTING_LEVEL1_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND3_RG0E_SETTING_LEVEL2_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND3_RG0E_SETTING_LEVEL3_SetDefault                             ( 0xFB )
#define LTE_ET_BAND3_RG0E_SETTING_LEVEL4_SetDefault                             ( 0xC2 )
#define LTE_ET_BAND3_RG0E_SETTING_LEVEL5_SetDefault                             ( 0xC2 )

#define LTE_ET_BAND4_RG0D_SETTING_LEVEL0_SetDefault                             ( 0x8E )
#define LTE_ET_BAND4_RG0D_SETTING_LEVEL1_SetDefault                             ( 0x8E )
#define LTE_ET_BAND4_RG0D_SETTING_LEVEL2_SetDefault                             ( 0x8E )
#define LTE_ET_BAND4_RG0D_SETTING_LEVEL3_SetDefault                             ( 0x08 )
#define LTE_ET_BAND4_RG0D_SETTING_LEVEL4_SetDefault                             ( 0x09 )
#define LTE_ET_BAND4_RG0D_SETTING_LEVEL5_SetDefault                             ( 0x0A )
#define LTE_ET_BAND4_RG0E_SETTING_LEVEL0_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND4_RG0E_SETTING_LEVEL1_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND4_RG0E_SETTING_LEVEL2_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND4_RG0E_SETTING_LEVEL3_SetDefault                             ( 0xFB )
#define LTE_ET_BAND4_RG0E_SETTING_LEVEL4_SetDefault                             ( 0xC2 )
#define LTE_ET_BAND4_RG0E_SETTING_LEVEL5_SetDefault                             ( 0xC2 )

#define LTE_ET_BAND5_RG0D_SETTING_LEVEL0_SetDefault                             ( 0x8E )
#define LTE_ET_BAND5_RG0D_SETTING_LEVEL1_SetDefault                             ( 0x8E )
#define LTE_ET_BAND5_RG0D_SETTING_LEVEL2_SetDefault                             ( 0x8E )
#define LTE_ET_BAND5_RG0D_SETTING_LEVEL3_SetDefault                             ( 0x08 )
#define LTE_ET_BAND5_RG0D_SETTING_LEVEL4_SetDefault                             ( 0x09 )
#define LTE_ET_BAND5_RG0D_SETTING_LEVEL5_SetDefault                             ( 0x0A )
#define LTE_ET_BAND5_RG0E_SETTING_LEVEL0_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND5_RG0E_SETTING_LEVEL1_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND5_RG0E_SETTING_LEVEL2_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND5_RG0E_SETTING_LEVEL3_SetDefault                             ( 0xFB )
#define LTE_ET_BAND5_RG0E_SETTING_LEVEL4_SetDefault                             ( 0xC2 )
#define LTE_ET_BAND5_RG0E_SETTING_LEVEL5_SetDefault                             ( 0xC2 )

#define LTE_ET_BAND6_RG0D_SETTING_LEVEL0_SetDefault                             ( 0x8E )
#define LTE_ET_BAND6_RG0D_SETTING_LEVEL1_SetDefault                             ( 0x8E )
#define LTE_ET_BAND6_RG0D_SETTING_LEVEL2_SetDefault                             ( 0x8E )
#define LTE_ET_BAND6_RG0D_SETTING_LEVEL3_SetDefault                             ( 0x08 )
#define LTE_ET_BAND6_RG0D_SETTING_LEVEL4_SetDefault                             ( 0x09 )
#define LTE_ET_BAND6_RG0D_SETTING_LEVEL5_SetDefault                             ( 0x0A )
#define LTE_ET_BAND6_RG0E_SETTING_LEVEL0_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND6_RG0E_SETTING_LEVEL1_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND6_RG0E_SETTING_LEVEL2_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND6_RG0E_SETTING_LEVEL3_SetDefault                             ( 0xFB )
#define LTE_ET_BAND6_RG0E_SETTING_LEVEL4_SetDefault                             ( 0xC2 )
#define LTE_ET_BAND6_RG0E_SETTING_LEVEL5_SetDefault                             ( 0xC2 )

#define LTE_ET_BAND7_RG0D_SETTING_LEVEL0_SetDefault                             ( 0x8E )
#define LTE_ET_BAND7_RG0D_SETTING_LEVEL1_SetDefault                             ( 0x8E )
#define LTE_ET_BAND7_RG0D_SETTING_LEVEL2_SetDefault                             ( 0x8E )
#define LTE_ET_BAND7_RG0D_SETTING_LEVEL3_SetDefault                             ( 0x08 )
#define LTE_ET_BAND7_RG0D_SETTING_LEVEL4_SetDefault                             ( 0x09 )
#define LTE_ET_BAND7_RG0D_SETTING_LEVEL5_SetDefault                             ( 0x0A )
#define LTE_ET_BAND7_RG0E_SETTING_LEVEL0_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND7_RG0E_SETTING_LEVEL1_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND7_RG0E_SETTING_LEVEL2_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND7_RG0E_SETTING_LEVEL3_SetDefault                             ( 0xFB )
#define LTE_ET_BAND7_RG0E_SETTING_LEVEL4_SetDefault                             ( 0xC2 )
#define LTE_ET_BAND7_RG0E_SETTING_LEVEL5_SetDefault                             ( 0xC2 )

#define LTE_ET_BAND8_RG0D_SETTING_LEVEL0_SetDefault                             ( 0x8E )
#define LTE_ET_BAND8_RG0D_SETTING_LEVEL1_SetDefault                             ( 0x8E )
#define LTE_ET_BAND8_RG0D_SETTING_LEVEL2_SetDefault                             ( 0x8E )
#define LTE_ET_BAND8_RG0D_SETTING_LEVEL3_SetDefault                             ( 0x08 )
#define LTE_ET_BAND8_RG0D_SETTING_LEVEL4_SetDefault                             ( 0x09 )
#define LTE_ET_BAND8_RG0D_SETTING_LEVEL5_SetDefault                             ( 0x0A )
#define LTE_ET_BAND8_RG0E_SETTING_LEVEL0_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND8_RG0E_SETTING_LEVEL1_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND8_RG0E_SETTING_LEVEL2_SetDefault                             ( 0xF7 )
#define LTE_ET_BAND8_RG0E_SETTING_LEVEL3_SetDefault                             ( 0xFB )
#define LTE_ET_BAND8_RG0E_SETTING_LEVEL4_SetDefault                             ( 0xC2 )
#define LTE_ET_BAND8_RG0E_SETTING_LEVEL5_SetDefault                             ( 0xC2 )

#define LTE_ET_BAND12_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND12_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND12_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND12_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND12_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND12_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND12_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND12_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND12_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND12_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND12_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND12_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND13_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND13_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND13_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND13_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND13_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND13_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND13_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND13_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND13_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND13_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND13_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND13_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND17_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND17_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND17_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND17_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND17_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND17_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND17_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND17_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND17_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND17_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND17_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND17_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND19_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND19_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND19_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND19_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND19_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND19_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND19_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND19_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND19_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND19_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND19_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND19_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND20_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND20_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND20_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND20_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND20_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND20_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND20_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND20_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND20_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND20_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND20_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND20_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND26_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND26_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND26_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND26_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND26_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND26_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND26_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND26_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND26_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND26_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND26_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND26_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND28_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND28_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND28_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND28_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND28_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND28_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND28_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND28_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND28_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND28_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND28_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND28_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND30_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND30_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND30_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND30_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND30_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND30_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND30_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND30_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND30_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND30_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND30_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND30_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND38_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND38_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND38_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND38_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND38_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND38_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND38_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND38_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND38_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND38_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND38_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND38_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND39_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND39_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND39_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND39_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND39_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND39_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND39_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND39_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND39_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND39_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND39_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND39_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND40_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND40_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND40_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND40_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND40_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND40_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND40_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND40_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND40_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND40_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND40_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND40_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#define LTE_ET_BAND41_RG0D_SETTING_LEVEL0_SetDefault                            ( 0x8E )
#define LTE_ET_BAND41_RG0D_SETTING_LEVEL1_SetDefault                            ( 0x8E )
#define LTE_ET_BAND41_RG0D_SETTING_LEVEL2_SetDefault                            ( 0x8E )
#define LTE_ET_BAND41_RG0D_SETTING_LEVEL3_SetDefault                            ( 0x08 )
#define LTE_ET_BAND41_RG0D_SETTING_LEVEL4_SetDefault                            ( 0x09 )
#define LTE_ET_BAND41_RG0D_SETTING_LEVEL5_SetDefault                            ( 0x0A )
#define LTE_ET_BAND41_RG0E_SETTING_LEVEL0_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND41_RG0E_SETTING_LEVEL1_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND41_RG0E_SETTING_LEVEL2_SetDefault                            ( 0xF7 )
#define LTE_ET_BAND41_RG0E_SETTING_LEVEL3_SetDefault                            ( 0xFB )
#define LTE_ET_BAND41_RG0E_SETTING_LEVEL4_SetDefault                            ( 0xC2 )
#define LTE_ET_BAND41_RG0E_SETTING_LEVEL5_SetDefault                            ( 0xC2 )

#else

#error "ETM chip type is not defined or defined as one unknown chip!"

#endif   // #if ( defined( ETM_CHIP_TYPE ) && ( ETM_CHIP_TYPE == ETM_MTK_MT6300 ) )



#define LTE_BandNone_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault           0
#define LTE_Band1_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault      ( ( ( ( LTE_Band1_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault  - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band2_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault      ( ( ( ( LTE_Band2_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault  - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band3_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault      ( ( ( ( LTE_Band3_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault  - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band4_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault      ( ( ( ( LTE_Band4_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault  - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band5_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault      ( ( ( ( LTE_Band5_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault  - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band7_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault      ( ( ( ( LTE_Band7_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault  - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band8_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault      ( ( ( ( LTE_Band8_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault  - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band12_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band12_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band13_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band13_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band17_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band17_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band20_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band20_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band26_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band26_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band28_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band28_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band29_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band29_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band30_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band30_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band38_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band38_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band39_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band39_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band40_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band40_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )
#define LTE_Band41_ET_VPA_OFFSET_VOLTAGE_REGISTER_VALUE_SetDefault     ( ( ( ( LTE_Band41_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault - ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE )*ET_VPA_NORMALIZATION_FACTOR ) / ET_VPA_OFFSET_VOLTAGE_RESOLUTION ) * ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT )



#if( LTE_ET_TPC_SECTION_DATA1_LEVEL0_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL0_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL0_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL0_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL0_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL0_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_TPC_SECTION_DATA2_LEVEL0_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_TPC_SECTION_DATA1_LEVEL0_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_TPC_SECTION_DATA1_LEVEL1_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL1_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL1_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL1_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL1_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL1_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_TPC_SECTION_DATA2_LEVEL1_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_TPC_SECTION_DATA1_LEVEL1_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_TPC_SECTION_DATA1_LEVEL2_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL2_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL2_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL2_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL2_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL2_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_TPC_SECTION_DATA2_LEVEL2_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_TPC_SECTION_DATA1_LEVEL2_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_TPC_SECTION_DATA1_LEVEL3_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL3_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL3_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL3_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL3_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL3_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_TPC_SECTION_DATA2_LEVEL3_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_TPC_SECTION_DATA1_LEVEL3_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_TPC_SECTION_DATA1_LEVEL4_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL4_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL4_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL4_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL4_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL4_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_TPC_SECTION_DATA2_LEVEL4_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_TPC_SECTION_DATA1_LEVEL4_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_TPC_SECTION_DATA1_LEVEL5_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL5_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL5_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL5_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL5_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL5_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_TPC_SECTION_DATA2_LEVEL5_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_TPC_SECTION_DATA1_LEVEL5_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_TPC_SECTION_DATA1_LEVEL6_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL6_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL6_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL6_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL6_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL6_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_TPC_SECTION_DATA2_LEVEL6_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_TPC_SECTION_DATA1_LEVEL6_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_TPC_SECTION_DATA1_LEVEL7_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL7_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL7_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL7_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL7_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL7_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_TPC_SECTION_DATA2_LEVEL7_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_TPC_SECTION_DATA1_LEVEL7_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_TPC_SECTION_DATA1_LEVEL8_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL8_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL8_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL8_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_TPC_SECTION_DATA1_LEVEL8_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_TPC_SECTION_DATA2_LEVEL8_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_TPC_SECTION_DATA2_LEVEL8_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_TPC_SECTION_DATA1_LEVEL8_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL0_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL0_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL0_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL0_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL0_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL0_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL0_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL0_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL1_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL1_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL1_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL1_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL1_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL1_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL1_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL1_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL2_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL2_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL2_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL2_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL2_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL2_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL2_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL2_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL3_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL3_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL3_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL3_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL3_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL3_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL3_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL3_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL4_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL4_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL4_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL4_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL4_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL4_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL4_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL4_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL5_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL5_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL5_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL5_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL5_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL5_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL5_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL5_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL6_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL6_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL6_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL6_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL6_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL6_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL6_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL6_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL7_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL7_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL7_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL7_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL7_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL7_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL7_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL7_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL8_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL8_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL8_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL8_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL8_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL8_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL8_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL8_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL9_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL9_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL9_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL9_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL0_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL9_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL9_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL9_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL10_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL10_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL10_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL10_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL10_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL10_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL10_SetDefault                     LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL10_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL11_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL11_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL11_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL11_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL11_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL11_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL11_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL11_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL12_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL12_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL12_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL12_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL12_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL12_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL12_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL12_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL13_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL13_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL13_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL13_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL13_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL13_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL13_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL13_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL14_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL14_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL0_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL14_SetDefault > LTE_ET_HFP_DAC_THRESHOLD2 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL14_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL1_SetDefault

#elif( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL14_SetDefault > LTE_ET_HFP_DAC_THRESHOLD3 )

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL14_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL2_SetDefault

#else

#define LTE_ET_LOOKUP_VPA_SECTION_DATA2_LEVEL14_SetDefault                      LTE_ET_HFP_EA_RSS_LEVEL3_SetDefault

#endif   // #if( LTE_ET_LOOKUP_VPA_SECTION_DATA1_LEVEL14_SetDefault > LTE_ET_HFP_DAC_THRESHOLD1 )

#endif   // #if IS_LTE_ET_FRONT_END_ENABLE_SetDefault

extern LTE_ET_EVENT_TABLE_T*              LTE_ET_TX_EVENT_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern LTE_ET_DATA_SUBBAND_TABLE_T*       LTE_ET_TX_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern LTE_ET_EVENT_TABLE_T*              LTE_ET_TPC_EVENT_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern LTE_ET_DATA_TABLE_T*               LTE_ET_TPC_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern LTE_ET_TPC_SECTION_TABLE_T*        LTE_ET_TPC_SECTION_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern LTE_ET_DATA_TABLE_T*               LTE_ET_LOOKUP_VPA_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern LTE_ET_LOOKUP_VPA_SECTION_TABLE_T* LTE_ET_LOOKUP_VPA_SECTION_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern LTE_ET_DATA_TABLE_T*               LTE_ET_BW_SWITCH_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern LTE_ET_BW_SWITCH_SECTION_DATA_T*   LTE_ET_BW_SWITCH_SECTION_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern LTE_ET_DATA_TABLE_T*               LTE_ETM_MODE_SETTING_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern kal_uint16                         LTE_ET_OUTER_LOOP_GAIN_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern kal_uint16                         LTE_ET_VPA_OFFSET_VOLTAGE_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern kal_uint16                         LTE_ET_MINIMUM_OUTPUT_VOLTAGE_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];
extern kal_uint16                         LTE_ET_MAXIMUM_OUTPUT_VOLTAGE_DATA_TABLE_SetDefault[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];

/////////////////////////

#endif /* End of #ifndef _LTE_CUSTOM_MIPI_ET_SETDEFAULT_H_ */

