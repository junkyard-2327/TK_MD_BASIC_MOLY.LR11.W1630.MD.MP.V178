/******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
/* Doxygen Group Header ****************************************************//**
 * @addtogroup EL1D_RF_PUBLIC
 * @{
 ******************************************************************************/
/***************************************************************************//**
 * @file       el1d_rf_public.h
 * @author     LY Chen (MTK04356)
 * @date       2014.12.16
 * @brief      EL1D RF Common
 * @details    provide public/common information in
 ******************************************************************************/

#ifndef __EL1D_RF_PUBLIC_H__
#define __EL1D_RF_PUBLIC_H__

/*******************************************************************************
 * #include
 ******************************************************************************/
#include "el1d_rf_cid.h"               // for Band extension

/*******************************************************************************
 * #define
 ******************************************************************************/
/** CA Category and Spec support version */
#define __36_101_V12_4_0__

#define LTE_BAND_NOT_SUPPORTED                (0xDEAD)
#define LTE_BAND_EXT_SUBBAND_SHIFT            (8)
#define LTE_BAND_EXT_SUBBAND_A                (1 << LTE_BAND_EXT_SUBBAND_SHIFT)
#define LTE_BAND_EXT_SUBBAND_B                (2 << LTE_BAND_EXT_SUBBAND_SHIFT)
#define LTE_BAND_EXT_SUBBAND_C                (3 << LTE_BAND_EXT_SUBBAND_SHIFT)

/** CA Category/Configuration Definition */
//#define LTE_CA_CLAS_A                              (0)
//#define LTE_CA_CLAS_B                              (1)
//#define LTE_CA_CLAS_C                              (2)
//#define LTE_CA_CLAS_D                              (3)
//#define LTE_CA_CLAS_E                              (4)
//#define LTE_CA_CLAS_F                              (5)

/** CA CFG BAND definition */
#define LTE_CA_CFG_BAND_BIT                        (0)
#define LTE_CA_CFG_BAND_LEN                        (6)
#define LTE_CA_CFG_BAND_MASK                       ((1 << LTE_CA_CFG_BAND_LEN) - 1)
#define LTE_CA_CFG_CLAS_BIT                        (LTE_CA_CFG_BAND_BIT + LTE_CA_CFG_BAND_LEN)
#define LTE_CA_CFG_CLAS_LEN                        (3)
#define LTE_CA_CFG_CLAS_MASK                       ((1 << LTE_CA_CFG_CLAS_LEN) - 1)
#define LTE_CA_CFG_SHIFT                           (LTE_CA_CFG_BAND_LEN + LTE_CA_CFG_CLAS_LEN) // 3 is the bit length of CA_BW_CLAS
#define LTE_CA_CFG_LEN                             (LTE_CA_CFG_BAND_LEN + LTE_CA_CFG_CLAS_LEN)
#define LTE_CA_CFG_MASK                            ((1 << LTE_CA_CFG_LEN) - 1)
#define LTE_CA_CFG_1ST_SHIFT                       (0)
#define LTE_CA_CFG_2ND_SHIFT                       (LTE_CA_CFG_SHIFT * 1)
//#define LTE_CA_CFG_3RD_SHIFT                       (LTE_CA_CFG_SHIFT * 2)


#define LTE_CA_NONE  (LTE_BandNone << LTE_CA_CFG_BAND_BIT)
//Class A
#define LTE_CA_1A    ((LTE_Band1  << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_2A    ((LTE_Band2  << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_3A    ((LTE_Band3  << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_4A    ((LTE_Band4  << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_5A    ((LTE_Band5  << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_7A    ((LTE_Band7  << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_8A    ((LTE_Band7  << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_11A   ((LTE_Band11 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_12A   ((LTE_Band12 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_13A   ((LTE_Band13 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_17A   ((LTE_Band17 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_18A   ((LTE_Band18 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_19A   ((LTE_Band19 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_20A   ((LTE_Band20 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_21A   ((LTE_Band21 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_23A   ((LTE_Band23 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_25A   ((LTE_Band25 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_26A   ((LTE_Band26 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_27A   ((LTE_Band27 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_28A   ((LTE_Band28 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_29A   ((LTE_Band29 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_30A   ((LTE_Band30 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_32A   ((LTE_Band32 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_38A   ((LTE_Band38 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_39A   ((LTE_Band39 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_40A   ((LTE_Band40 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_41A   ((LTE_Band41 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_42A   ((LTE_Band42 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_A << LTE_CA_CFG_CLAS_BIT))
// Class B
#define LTE_CA_23B   ((LTE_Band23 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_B << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_27B   ((LTE_Band27 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_B << LTE_CA_CFG_CLAS_BIT))
// Class C
#define LTE_CA_1C    ((LTE_Band1  << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_C << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_3C    ((LTE_Band3  << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_C << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_7C    ((LTE_Band7  << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_C << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_38C   ((LTE_Band38 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_C << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_39C   ((LTE_Band39 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_C << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_40C   ((LTE_Band40 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_C << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_41C   ((LTE_Band41 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_C << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_42C   ((LTE_Band42 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_C << LTE_CA_CFG_CLAS_BIT))
//Class D
#define LTE_CA_40D   ((LTE_Band40 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_D << LTE_CA_CFG_CLAS_BIT))
#define LTE_CA_41D   ((LTE_Band41 << LTE_CA_CFG_BAND_BIT) | (CA_BW_CLAS_D << LTE_CA_CFG_CLAS_BIT))

/** Table index for ROUTE usage */
#define TBL_IDX0         0
#define TBL_IDX1         1
#define TBL_IDX2         2
#define TBL_IDX3         3
#define TBL_IDX4         4
#define TBL_IDX5         5
#define TBL_IDX6         6
#define TBL_IDX7         7
#define TBL_IDX8         8
#define TBL_IDX9         9
#define TBL_IDX10        10
#define TBL_IDX11        11
#define TBL_IDX12        12
#define TBL_IDX13        13
#define TBL_IDX14        14
#define TBL_IDX15        15
#define TBL_IDX16        16
#define TBL_IDX17        17
#define TBL_IDX18        18
#define TBL_IDX19        19
#define TBL_IDX20        20
#define TBL_IDX21        21
#define TBL_IDX22        22
#define TBL_IDX23        23
#define TBL_IDX24        24
#define TBL_IDX25        25
#define TBL_IDX26        26
#define TBL_IDX27        27
#define TBL_IDX28        28
#define TBL_IDX29        29
#define TBL_IDX30        30
#define TBL_IDX31        31
#define TBL_IDX32        32
#define TBL_IDX33        33
#define TBL_IDX34        34
#define TBL_IDX35        35
#define TBL_IDX36        36
#define TBL_IDX37        37
#define TBL_IDX38        38
#define TBL_IDX39        39
#define TBL_IDX40        40
#define TBL_IDX41        41
#define TBL_IDX42        42
#define TBL_IDX43        43
#define TBL_IDX44        44
#define TBL_IDX45        45
#define TBL_IDX46        46
#define TBL_IDX47        47
#define TBL_IDX48        48
#define TBL_IDX49        49
#define TBL_IDX50        50
#define TBL_IDX51        51
#define TBL_IDX52        52
#define TBL_IDX53        53
#define TBL_IDX54        54
#define TBL_IDX55        55
#define TBL_IDX56        56
#define TBL_IDX57        57
#define TBL_IDX58        58
#define TBL_IDX59        59
#define TBL_IDX60        60
#define TBL_IDX61        61
#define TBL_IDX62        62
#define TBL_IDX63        63
#define TBL_IDX64        64
#define TBL_IDX65        65
#define TBL_IDX66        66
#define TBL_IDX67        67
#define TBL_IDX68        68
#define TBL_IDX69        69
#define TBL_IDX70        70
#define TBL_IDX71        71
#define TBL_IDX72        72
#define TBL_IDX73        73
#define TBL_IDX74        74
#define TBL_IDX75        75
#define TBL_IDX76        76
#define TBL_IDX77        77
#define TBL_IDX78        78
#define TBL_IDX79        79
#define TBL_IDX80        80
#define TBL_IDX81        81
#define TBL_IDX82        82
#define TBL_IDX83        83
#define TBL_IDX84        84
#define TBL_IDX85        85
#define TBL_IDX86        86
#define TBL_IDX87        87
#define TBL_IDX88        88
#define TBL_IDX89        89
#define TBL_IDX90        90
#define TBL_IDX91        91
#define TBL_IDX92        92
#define TBL_IDX93        93
#define TBL_IDX94        94
#define TBL_IDX95        95
#define TBL_IDX96        96
#define TBL_IDX97        97
#define TBL_IDX98        98
#define TBL_IDX99        99
#define TBL_IDX100       100
#define TBL_IDX101       101
#define TBL_IDX102       102
#define TBL_IDX103       103
#define TBL_IDX104       104
#define TBL_IDX105       105
#define TBL_IDX106       106
#define TBL_IDX107       107
#define TBL_IDX108       108
#define TBL_IDX109       109
#define TBL_IDX110       110
#define TBL_IDX111       111
#define TBL_IDX112       112
#define TBL_IDX113       113
#define TBL_IDX114       114
#define TBL_IDX115       115
#define TBL_IDX116       116
#define TBL_IDX117       117
#define TBL_IDX118       118
#define TBL_IDX119       119
#define TBL_IDX120       120
#define TBL_IDX121       121
#define TBL_IDX122       122
#define TBL_IDX123       123
#define TBL_IDX124       124
#define TBL_IDX125       125
#define TBL_IDX126       126
#define TBL_IDX127       127
#define TBL_IDX_INVALID  0xFF

#define TBL_IDX_FOR_BAND_INDICATOR0   TBL_IDX0
#define TBL_IDX_FOR_BAND_INDICATOR1   TBL_IDX1
#define TBL_IDX_FOR_BAND_INDICATOR2   TBL_IDX2
#define TBL_IDX_FOR_BAND_INDICATOR3   TBL_IDX3
#define TBL_IDX_FOR_BAND_INDICATOR4   TBL_IDX4
#define TBL_IDX_FOR_BAND_INDICATOR5   TBL_IDX5
#define TBL_IDX_FOR_BAND_INDICATOR6   TBL_IDX6
#define TBL_IDX_FOR_BAND_INDICATOR7   TBL_IDX7
#define TBL_IDX_FOR_BAND_INDICATOR8   TBL_IDX8
#define TBL_IDX_FOR_BAND_INDICATOR9   TBL_IDX9
#define TBL_IDX_FOR_BAND_INDICATOR10  TBL_IDX10
#define TBL_IDX_FOR_BAND_INDICATOR11  TBL_IDX11
#define TBL_IDX_FOR_BAND_INDICATOR12  TBL_IDX12
#define TBL_IDX_FOR_BAND_INDICATOR13  TBL_IDX13
#define TBL_IDX_FOR_BAND_INDICATOR14  TBL_IDX14
#define TBL_IDX_FOR_BAND_INDICATOR15  TBL_IDX15
#define TBL_IDX_FOR_BAND_INDICATOR16  TBL_IDX16
#define TBL_IDX_FOR_BAND_INDICATOR17  TBL_IDX17
#define TBL_IDX_FOR_BAND_INDICATOR18  TBL_IDX18
#define TBL_IDX_FOR_BAND_INDICATOR19  TBL_IDX19
#define TBL_IDX_FOR_BAND_INDICATOR20  TBL_IDX20

#define VPA_SOURCE_NOT_SUPPORTED    0
#define VPA_SOURCE_HW_VAPC          1
#define VPA_SOURCE_HW_PMIC          2
#define VPA_SOURCE_HW_ETM_SW_APT    3
#define VPA_SOURCE_HW_ETM_SW_ET     4
#define VPA_SOURCE_HW_PMIC_ETM_APT  5


/*******************************************************************************
 * Typedef
 ******************************************************************************/

/** LTE Band */
typedef enum
{
   LTE_BandNone = 0,
   LTE_Band1    = 1,
   LTE_Band2    = 2,
   LTE_Band3    = 3,
   LTE_Band4    = 4,
   LTE_Band5    = 5,
   LTE_Band6    = 6,
   LTE_Band7    = 7,
   LTE_Band8    = 8,
   LTE_Band9    = 9,
   LTE_Band10   = 10,
   LTE_Band11   = 11,
   LTE_Band12   = 12,
   LTE_Band13   = 13,
   LTE_Band14   = 14,
   LTE_Band15   = 15, // reserved
   LTE_Band16   = 16, // reserved
   LTE_Band17   = 17,
   LTE_Band18   = 18,
   LTE_Band19   = 19,
   LTE_Band20   = 20,
   LTE_Band21   = 21,
   LTE_Band22   = 22,
   LTE_Band23   = 23,
   LTE_Band24   = 24,
   LTE_Band25   = 25,
   LTE_Band26   = 26,
   LTE_Band27   = 27,
   LTE_Band28   = 28,
   LTE_Band29   = 29, // FDD, only DL
   LTE_Band30   = 30,
   LTE_Band31   = 31,
   LTE_Band32   = 32, // Not defined in 3GPP spec.
   LTE_Band33   = 33, // TDD band
   LTE_Band34   = 34,
   LTE_Band35   = 35,
   LTE_Band36   = 36,
   LTE_Band37   = 37,
   LTE_Band38   = 38,
   LTE_Band39   = 39,
   LTE_Band40   = 40,
   LTE_Band41   = 41,
   LTE_Band42   = 42,
   LTE_Band43   = 43,
   LTE_Band44   = 44,
#if IS_4G_BAND_EXTENSION_SUPPORT
   LTE_Band45   = 45, // reserved
   LTE_Band46   = 46, // reserved
   LTE_Band47   = 47, // reserved
   LTE_Band48   = 48, // reserved
   LTE_Band49   = 49, // reserved
   LTE_Band50   = 50, // reserved
   LTE_Band51   = 51, // reserved
   LTE_Band52   = 52, // reserved
   LTE_Band53   = 53, // reserved
   LTE_Band54   = 54, // reserved
   LTE_Band55   = 55, // reserved
   LTE_Band56   = 56, // reserved
   LTE_Band57   = 57, // reserved
   LTE_Band58   = 58, // reserved
   LTE_Band59   = 59, // reserved
   LTE_Band60   = 60, // reserved
   LTE_Band61   = 61, // reserved
   LTE_Band62   = 62, // reserved
   LTE_Band63   = 63, // reserved
   LTE_Band64   = 64, // reserved
   LTE_Band65   = 65, // reserved
   LTE_Band66   = 66,
#endif
   LTE_BandCount,
   LTE_BandMax  = 0xFFFE
}  LTE_Band;

/** LTE Band Extend for subband usage) */
typedef enum
{
   LTE_EXT_BANDNONE = LTE_BandNone,
   LTE_EXT_BAND1    = LTE_Band1   ,
   LTE_EXT_BAND2    = LTE_Band2   ,
   LTE_EXT_BAND3    = LTE_Band3   ,
   LTE_EXT_BAND4    = LTE_Band4   ,
   LTE_EXT_BAND5    = LTE_Band5   ,
   LTE_EXT_BAND6    = LTE_Band6   ,
   LTE_EXT_BAND7    = LTE_Band7   ,
   LTE_EXT_BAND8    = LTE_Band8   ,
   LTE_EXT_BAND9    = LTE_Band9   ,
   LTE_EXT_BAND10   = LTE_Band10  ,
   LTE_EXT_BAND11   = LTE_Band11  ,
   LTE_EXT_BAND12   = LTE_Band12  ,
   LTE_EXT_BAND13   = LTE_Band13  ,
   LTE_EXT_BAND14   = LTE_Band14  ,
   LTE_EXT_BAND15   = LTE_Band15  , // reserved
   LTE_EXT_BAND16   = LTE_Band16  , // reserved
   LTE_EXT_BAND17   = LTE_Band17  ,
   LTE_EXT_BAND18   = LTE_Band18  ,
   LTE_EXT_BAND19   = LTE_Band19  ,
   LTE_EXT_BAND20   = LTE_Band20  ,
   LTE_EXT_BAND21   = LTE_Band21  ,
   LTE_EXT_BAND22   = LTE_Band22  ,
   LTE_EXT_BAND23   = LTE_Band23  ,
   LTE_EXT_BAND24   = LTE_Band24  ,
   LTE_EXT_BAND25   = LTE_Band25  ,
   LTE_EXT_BAND26   = LTE_Band26  ,
   LTE_EXT_BAND27   = LTE_Band27  ,
   LTE_EXT_BAND28   = LTE_Band28  ,
   LTE_EXT_BAND28A  = LTE_Band28 | LTE_BAND_EXT_SUBBAND_A,
   LTE_EXT_BAND28B  = LTE_Band28 | LTE_BAND_EXT_SUBBAND_B,
   LTE_EXT_BAND28C  = LTE_Band28 | LTE_BAND_EXT_SUBBAND_C,
   LTE_EXT_BAND29   = LTE_Band29  , // FDD, only DL
   LTE_EXT_BAND30   = LTE_Band30  ,
   LTE_EXT_BAND31   = LTE_Band31  ,
   LTE_EXT_BAND32   = LTE_Band32  , // Not defined in 3GPP spec.
   LTE_EXT_BAND33   = LTE_Band33  , // TDD band
   LTE_EXT_BAND34   = LTE_Band34  ,
   LTE_EXT_BAND35   = LTE_Band35  ,
   LTE_EXT_BAND36   = LTE_Band36  ,
   LTE_EXT_BAND37   = LTE_Band37  ,
   LTE_EXT_BAND38   = LTE_Band38  ,
   LTE_EXT_BAND39   = LTE_Band39  ,
   LTE_EXT_BAND40   = LTE_Band40  ,
   LTE_EXT_BAND41   = LTE_Band41  ,
   LTE_EXT_BAND41A  = LTE_Band41 | LTE_BAND_EXT_SUBBAND_A,
   LTE_EXT_BAND41B  = LTE_Band41 | LTE_BAND_EXT_SUBBAND_B,
   LTE_EXT_BAND41C  = LTE_Band41 | LTE_BAND_EXT_SUBBAND_C,
   LTE_EXT_BAND42   = LTE_Band42  ,
   LTE_EXT_BAND43   = LTE_Band43  ,
   LTE_EXT_BAND44   = LTE_Band44  ,
   LTE_EXT_BAND44A  = LTE_Band44 | LTE_BAND_EXT_SUBBAND_A,
   LTE_EXT_BAND44B  = LTE_Band44 | LTE_BAND_EXT_SUBBAND_B,
   LTE_EXT_BAND44C  = LTE_Band44 | LTE_BAND_EXT_SUBBAND_C,
#if IS_4G_BAND_EXTENSION_SUPPORT
   LTE_EXT_BAND45   = LTE_Band45, // reserved
   LTE_EXT_BAND46   = LTE_Band46, // reserved
   LTE_EXT_BAND47   = LTE_Band47, // reserved
   LTE_EXT_BAND48   = LTE_Band48, // reserved
   LTE_EXT_BAND49   = LTE_Band49, // reserved
   LTE_EXT_BAND50   = LTE_Band50, // reserved
   LTE_EXT_BAND51   = LTE_Band51, // reserved
   LTE_EXT_BAND52   = LTE_Band52, // reserved
   LTE_EXT_BAND53   = LTE_Band53, // reserved
   LTE_EXT_BAND54   = LTE_Band54, // reserved
   LTE_EXT_BAND55   = LTE_Band55, // reserved
   LTE_EXT_BAND56   = LTE_Band56, // reserved
   LTE_EXT_BAND57   = LTE_Band57, // reserved
   LTE_EXT_BAND58   = LTE_Band58, // reserved
   LTE_EXT_BAND59   = LTE_Band59, // reserved
   LTE_EXT_BAND60   = LTE_Band60, // reserved
   LTE_EXT_BAND61   = LTE_Band61, // reserved
   LTE_EXT_BAND62   = LTE_Band62, // reserved
   LTE_EXT_BAND63   = LTE_Band63, // reserved
   LTE_EXT_BAND64   = LTE_Band64, // reserved
   LTE_EXT_BAND65   = LTE_Band65, // reserved
   LTE_EXT_BAND66   = LTE_Band66,
#endif
   LTE_EXT_BANDCOUNT,
   LTE_EXT_BANDMAX  = 0xFFFE
}  LTE_BAND_EXT_E;

/** LTE Route index: should be Caps */
typedef enum
{
   LTE_Route0   = TBL_IDX0,
   LTE_Route1   = TBL_IDX1,
   LTE_Route2   = TBL_IDX2,
   LTE_Route3   = TBL_IDX3,
   LTE_Route4   = TBL_IDX4,
   LTE_Route5   = TBL_IDX5,
   LTE_Route6   = TBL_IDX6,
   LTE_Route7   = TBL_IDX7,
   LTE_Route8   = TBL_IDX8,
   LTE_Route9   = TBL_IDX9,
   LTE_Route10  = TBL_IDX10,
   LTE_Route11  = TBL_IDX11,
   LTE_Route12  = TBL_IDX12,
   LTE_Route13  = TBL_IDX13,
   LTE_Route14  = TBL_IDX14,
   LTE_Route15  = TBL_IDX15,
   LTE_Route16  = TBL_IDX16,
   LTE_Route17  = TBL_IDX17,
   LTE_Route18  = TBL_IDX18,
   LTE_Route19  = TBL_IDX19,
   LTE_Route20  = TBL_IDX20,
   LTE_Route21  = TBL_IDX21,
   LTE_Route22  = TBL_IDX22,
   LTE_Route23  = TBL_IDX23,
   LTE_Route24  = TBL_IDX24,
   LTE_Route25  = TBL_IDX25,
   LTE_Route26  = TBL_IDX26,
   LTE_Route27  = TBL_IDX27,
   LTE_Route28  = TBL_IDX28,
   LTE_Route29  = TBL_IDX29,
   LTE_Route30  = TBL_IDX30,
   LTE_Route31  = TBL_IDX31,
   LTE_Route32  = TBL_IDX32,
   LTE_Route33  = TBL_IDX33,
   LTE_Route34  = TBL_IDX34,
   LTE_Route35  = TBL_IDX35,
   LTE_Route36  = TBL_IDX36,
   LTE_Route37  = TBL_IDX37,
   LTE_Route38  = TBL_IDX38,
   LTE_Route39  = TBL_IDX39,
   LTE_Route40  = TBL_IDX40,
   LTE_Route41  = TBL_IDX41,
   LTE_Route42  = TBL_IDX42,
   LTE_Route43  = TBL_IDX43,
   LTE_Route44  = TBL_IDX44,
   LTE_Route45  = TBL_IDX45,
   LTE_Route46  = TBL_IDX46,
   LTE_Route47  = TBL_IDX47,
   LTE_Route48  = TBL_IDX48,
   LTE_Route49  = TBL_IDX49,
   LTE_Route50  = TBL_IDX50,
   LTE_Route51  = TBL_IDX51,
   LTE_Route52  = TBL_IDX52,
   LTE_Route53  = TBL_IDX53,
   LTE_Route54  = TBL_IDX54,
   LTE_Route55  = TBL_IDX55,
   LTE_Route56  = TBL_IDX56,
   LTE_Route57  = TBL_IDX57,
   LTE_Route58  = TBL_IDX58,
   LTE_Route59  = TBL_IDX59,
   LTE_Route60  = TBL_IDX60,
   LTE_Route61  = TBL_IDX61,
   LTE_Route62  = TBL_IDX62,
   LTE_Route63  = TBL_IDX63,
   LTE_Route64  = TBL_IDX64,
   LTE_Route65  = TBL_IDX65,
   LTE_Route66  = TBL_IDX66,
   LTE_Route67  = TBL_IDX67,
   LTE_Route68  = TBL_IDX68,
   LTE_Route69  = TBL_IDX69,
   LTE_Route70  = TBL_IDX70,
   LTE_Route71  = TBL_IDX71,
   LTE_Route72  = TBL_IDX72,
   LTE_Route73  = TBL_IDX73,
   LTE_Route74  = TBL_IDX74,
   LTE_Route75  = TBL_IDX75,
   LTE_Route76  = TBL_IDX76,
   LTE_Route77  = TBL_IDX77,
   LTE_Route78  = TBL_IDX78,
   LTE_Route79  = TBL_IDX79,
   LTE_Route80  = TBL_IDX80,
   LTE_Route81  = TBL_IDX81,
   LTE_Route82  = TBL_IDX82,
   LTE_Route83  = TBL_IDX83,
   LTE_Route84  = TBL_IDX84,
   LTE_Route85  = TBL_IDX85,
   LTE_Route86  = TBL_IDX86,
   LTE_Route87  = TBL_IDX87,
   LTE_Route88  = TBL_IDX88,
   LTE_Route89  = TBL_IDX89,
   LTE_Route90  = TBL_IDX90,
   LTE_Route91  = TBL_IDX91,
   LTE_Route92  = TBL_IDX92,
   LTE_Route93  = TBL_IDX93,
   LTE_Route94  = TBL_IDX94,
   LTE_Route95  = TBL_IDX95,
   LTE_Route96  = TBL_IDX96,
   LTE_Route97  = TBL_IDX97,
   LTE_Route98  = TBL_IDX98,
   LTE_Route99  = TBL_IDX99,
   LTE_Route100 = TBL_IDX100,
   LTE_Route101 = TBL_IDX101,
   LTE_Route102 = TBL_IDX102,
   LTE_Route103 = TBL_IDX103,
   LTE_Route104 = TBL_IDX104,
   LTE_Route105 = TBL_IDX105,
   LTE_Route106 = TBL_IDX106,
   LTE_Route107 = TBL_IDX107,
   LTE_Route108 = TBL_IDX108,
   LTE_Route109 = TBL_IDX109,
   LTE_Route110 = TBL_IDX110,
   LTE_Route111 = TBL_IDX111,
   LTE_Route112 = TBL_IDX112,
   LTE_Route113 = TBL_IDX113,
   LTE_Route114 = TBL_IDX114,
   LTE_Route115 = TBL_IDX115,
   LTE_Route116 = TBL_IDX116,
   LTE_Route117 = TBL_IDX117,
   LTE_Route118 = TBL_IDX118,
   LTE_Route119 = TBL_IDX119,
   LTE_Route120 = TBL_IDX120,
   LTE_Route121 = TBL_IDX121,
   LTE_Route122 = TBL_IDX122,
   LTE_Route123 = TBL_IDX123,
   LTE_Route124 = TBL_IDX124,
   LTE_Route125 = TBL_IDX125,
   LTE_Route126 = TBL_IDX126,
   LTE_Route127 = TBL_IDX127,
   LTE_Routecount,
   LTE_RouteInvalid = TBL_IDX_INVALID,
   LTE_RouteMax     = 0xFFFE,
}  LTE_Route;

/** LTE CA Bandwidth class definition (3 bits) */
typedef enum
{
   CA_BW_CLAS_A   = 0,
   CA_BW_CLAS_B   = 1,
   CA_BW_CLAS_C   = 2,
   CA_BW_CLAS_D   = 3,
   CA_BW_CLAS_E   = 4,
   CA_BW_CLAS_F   = 5,
   CA_BW_CLAS_MAX = 6,
   CA_BW_CLAS_INV = CA_BW_CLAS_MAX, // Invalid BW Class
} LTE_CA_BW_CLAS_E;

/** CA Band definition */
typedef enum
{
    LTE_CACFG_CA_NONE
   /** Single-Band */
   ,LTE_CA_CFG_1A  = LTE_Band1
   ,LTE_CA_CFG_2A  = LTE_Band2
   ,LTE_CA_CFG_3A  = LTE_Band3
   ,LTE_CA_CFG_4A  = LTE_Band4
   ,LTE_CA_CFG_5A  = LTE_Band5
   ,LTE_CA_CFG_6A  = LTE_Band6
   ,LTE_CA_CFG_7A  = LTE_Band7
   ,LTE_CA_CFG_8A  = LTE_Band8
   ,LTE_CA_CFG_9A  = LTE_Band9
   ,LTE_CA_CFG_10A = LTE_Band10
   ,LTE_CA_CFG_11A = LTE_Band11
   ,LTE_CA_CFG_12A = LTE_Band12
   ,LTE_CA_CFG_13A = LTE_Band13
   ,LTE_CA_CFG_14A = LTE_Band14
   ,LTE_CA_CFG_15A = LTE_Band15 // reserved
   ,LTE_CA_CFG_16A = LTE_Band16 // reserved
   ,LTE_CA_CFG_17A = LTE_Band17
   ,LTE_CA_CFG_18A = LTE_Band18
   ,LTE_CA_CFG_19A = LTE_Band19
   ,LTE_CA_CFG_20A = LTE_Band20
   ,LTE_CA_CFG_21A = LTE_Band21
   ,LTE_CA_CFG_22A = LTE_Band22
   ,LTE_CA_CFG_23A = LTE_Band23
   ,LTE_CA_CFG_24A = LTE_Band24
   ,LTE_CA_CFG_25A = LTE_Band25
   ,LTE_CA_CFG_26A = LTE_Band26
   ,LTE_CA_CFG_27A = LTE_Band27
   ,LTE_CA_CFG_28A = LTE_Band28
   ,LTE_CA_CFG_29A = LTE_Band29 // FDD, only DL
   ,LTE_CA_CFG_30A = LTE_Band30
   ,LTE_CA_CFG_31A = LTE_Band31
   ,LTE_CA_CFG_32A = LTE_Band32 // Not defined in 3GPP spec.
   ,LTE_CA_CFG_33A = LTE_Band33 // TDD band
   ,LTE_CA_CFG_34A = LTE_Band34
   ,LTE_CA_CFG_35A = LTE_Band35
   ,LTE_CA_CFG_36A = LTE_Band36
   ,LTE_CA_CFG_37A = LTE_Band37
   ,LTE_CA_CFG_38A = LTE_Band38
   ,LTE_CA_CFG_39A = LTE_Band39
   ,LTE_CA_CFG_40A = LTE_Band40
   ,LTE_CA_CFG_41A = LTE_Band41
   ,LTE_CA_CFG_42A = LTE_Band42
   ,LTE_CA_CFG_43A = LTE_Band43
   ,LTE_CA_CFG_44A = LTE_Band44
#if IS_4G_BAND_EXTENSION_SUPPORT
   ,LTE_CA_CFG_45A = LTE_Band45 // reserved
   ,LTE_CA_CFG_46A = LTE_Band46 // reserved
   ,LTE_CA_CFG_47A = LTE_Band47 // reserved
   ,LTE_CA_CFG_48A = LTE_Band48 // reserved
   ,LTE_CA_CFG_49A = LTE_Band49 // reserved
   ,LTE_CA_CFG_50A = LTE_Band50 // reserved
   ,LTE_CA_CFG_51A = LTE_Band51 // reserved
   ,LTE_CA_CFG_52A = LTE_Band52 // reserved
   ,LTE_CA_CFG_53A = LTE_Band53 // reserved
   ,LTE_CA_CFG_54A = LTE_Band54 // reserved
   ,LTE_CA_CFG_55A = LTE_Band55 // reserved
   ,LTE_CA_CFG_56A = LTE_Band56 // reserved
   ,LTE_CA_CFG_57A = LTE_Band57 // reserved
   ,LTE_CA_CFG_58A = LTE_Band58 // reserved
   ,LTE_CA_CFG_59A = LTE_Band59 // reserved
   ,LTE_CA_CFG_60A = LTE_Band60 // reserved
   ,LTE_CA_CFG_61A = LTE_Band61 // reserved
   ,LTE_CA_CFG_62A = LTE_Band62 // reserved
   ,LTE_CA_CFG_63A = LTE_Band63 // reserved
   ,LTE_CA_CFG_64A = LTE_Band64 // reserved
   ,LTE_CA_CFG_65A = LTE_Band65 // reserved
   ,LTE_CA_CFG_66A = LTE_Band66
#endif
   /** Intra-CCA */
   ,LTE_CACFG_CA_1C
   ,LTE_CACFG_CA_7C
   ,LTE_CACFG_CA_38C
   ,LTE_CACFG_CA_40C
   ,LTE_CACFG_CA_41C
   /** Inter-band CA */
   ,LTE_CACFG_CA_1A_5A
   ,LTE_CACFG_CA_1A_8A
   ,LTE_CACFG_CA_1A_18A
   ,LTE_CACFG_CA_1A_19A
   ,LTE_CACFG_CA_1A_21A
   ,LTE_CACFG_CA_2A_13A
   ,LTE_CACFG_CA_2A_17A  /** Operator supported CA configuration */
   ,LTE_CACFG_CA_2A_29A
   ,LTE_CACFG_CA_3A_5A
   ,LTE_CACFG_CA_3A_7A
   ,LTE_CACFG_CA_3A_8A
   ,LTE_CACFG_CA_3A_19A
   ,LTE_CACFG_CA_3A_20A
   ,LTE_CACFG_CA_3A_26A
   ,LTE_CACFG_CA_3A_28A
   ,LTE_CACFG_CA_4A_5A
   ,LTE_CACFG_CA_4A_7A
   ,LTE_CACFG_CA_4A_12A
   ,LTE_CACFG_CA_4A_13A
   ,LTE_CACFG_CA_4A_17A
   ,LTE_CACFG_CA_4A_29A
   ,LTE_CACFG_CA_5A_12A
   ,LTE_CACFG_CA_5A_17A
   ,LTE_CACFG_CA_7A_20A
   ,LTE_CACFG_CA_8A_20A
   ,LTE_CACFG_CA_11A_18A
   ,LTE_CACFG_CA_19A_21A
   ,LTE_CACFG_CA_23A_29A
   /** Intra-NCCA */
   ,LTE_CACFG_CA_4A_4A
   ,LTE_CACFG_CA_25A_25A
   ,LTE_CACFG_CA_41A_41A
   /** above: 36.101 V12.0.0 (2013-07) */

#ifdef __36_101_V12_4_0__  // for CA in spec. 36.101 V12.4.0 (2014-06)
   /** Intra-CCA */
   ,LTE_CACFG_CA_3C
   ,LTE_CACFG_CA_23B
   ,LTE_CACFG_CA_27B
   ,LTE_CACFG_CA_39C
   ,LTE_CACFG_CA_40D
   ,LTE_CACFG_CA_41D
   ,LTE_CACFG_CA_42C
   /** Inter-band CA */
   ,LTE_CACFG_CA_1A_11A
   ,LTE_CACFG_CA_1A_20A
   ,LTE_CACFG_CA_1A_26A
   ,LTE_CACFG_CA_2A_4A
   ,LTE_CACFG_CA_2A_5A
   ,LTE_CACFG_CA_2A_12A
   ,LTE_CACFG_CA_3A_27A
   ,LTE_CACFG_CA_5A_7A
   ,LTE_CACFG_CA_5A_25A
   ,LTE_CACFG_CA_7A_28A
   ,LTE_CACFG_CA_8A_40A
   ,LTE_CACFG_CA_12A_25A
   ,LTE_CACFG_CA_20A_32A
   ,LTE_CACFG_CA_39A_41A
   /** Intra-NCCA */
   ,LTE_CACFG_CA_2A_2A
   ,LTE_CACFG_CA_3A_3A
   ,LTE_CACFG_CA_7A_7A
   ,LTE_CACFG_CA_23A_23A
   ,LTE_CACFG_CA_41A_41C
   ,LTE_CACFG_CA_41C_41A
   ,LTE_CACFG_CA_42A_42A
   /** above: 36.101 V12.4.0 (2014-06) */
#endif

   /** Operator supported CA configuration */
   //,LTE_CACFG_CA_2A_17A   // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_2A_29A   // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_4A_5A    // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_4A_17A   // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_4A_29A   // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_5A_17A   // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_2A_13A   // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_4A_13A   // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_2A_4A,   // included in 36.101 V12.4.0 (2014-06)
   //,LTE_CACFG_CA_1A_19A   // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_1A_21A   // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_3A_19A   // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_19A_21A  // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_1A_8A    // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_3A_8A    // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_41A_41A  // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_39A_41A  // included in 36.101 V12.4.0 (2014-06)
   //,LTE_CACFG_CA_1A_5A    // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_1A_8A    // included in 36.101 V12.0.0 (2013-07)
   //,LTE_CACFG_CA_1A_11A   // included in 36.101 V12.4.0 (2014-06)
   //,LTE_CACFG_CA_2A_4A
   //,LTE_CACFG_CA_2A_5A    // included in 36.101 V12.4.0 (2014-06)
   
   /** Inter-band CA */
   ,LTE_CACFG_CA_1A_3A
   ,LTE_CACFG_CA_1A_7A
   ,LTE_CACFG_CA_1A_28A
   ,LTE_CACFG_CA_2A_30A
   ,LTE_CACFG_CA_3A_4A
   ,LTE_CACFG_CA_4A_30A
   ,LTE_CACFG_CA_4A_41A
   ,LTE_CACFG_CA_5A_30A
   ,LTE_CACFG_CA_7A_8A
   //,LTE_CACFG_CA_7A_28A   // included in 36.101 V12.4.0 (2014-06)
   ,LTE_CACFG_CA_12A_30A
   ,LTE_CACFG_CA_17A_30A
   ,LTE_CACFG_CA_20A_38A
   ,LTE_CACFG_CA_26A_41A
   ,LTE_CACFG_CA_29A_30A
   ,LTE_CACFG_CA_4A_28A
   ,LTE_CACFG_CA_25A_26A
   ,LTE_CACFG_CA_8A_11A
   ,LTE_CACFG_CA_5A_29A
   /** Intra-NCCA */
   ,LTE_CACFG_CA_5A_5A
   ,LTE_CACFG_CA_40A_40A
#if IS_4G_BAND_EXTENSION_SUPPORT
   ,LTE_CACFG_CA_2A_66A
   ,LTE_CACFG_CA_5A_66A
   ,LTE_CACFG_CA_12A_66A
   ,LTE_CACFG_CA_13A_66A
   ,LTE_CACFG_CA_66A_66A
   ,LTE_CACFG_CA_29A_66A
   ,LTE_CACFG_CA_30A_66A
#endif

/** 2017/3/6 new CA support list */
   ,LTE_CACFG_CA_2A_7A
   ,LTE_CACFG_CA_2A_28A
   ,LTE_CACFG_CA_3A_38A
   ,LTE_CACFG_CA_3A_40A
   ,LTE_CACFG_CA_3A_41A
   ,LTE_CACFG_CA_5A_40A
   ,LTE_CACFG_CA_8A_38A
   ,LTE_CACFG_CA_20A_40A
   ,LTE_CACFG_CA_28A_38A
   ,LTE_CACFG_CA_28A_40A
   
   /** NOTICE: PLEACE ALSO MODIFY the table: LTE_CACFG_BW_CLAS_TABLE */

   ,LTE_CACFG_CA_COUNT
   ,LTE_CACFG_CA_INV = 0xFFFF
} LTE_CA_CFG_E;

typedef enum
{
   VPA_SOURCE_INVALID_T = VPA_SOURCE_NOT_SUPPORTED,
   VPA_SOURCE_VBAT_T    = VPA_SOURCE_HW_VAPC,
   VPA_SOURCE_PMIC_T    = VPA_SOURCE_HW_PMIC,
   VPA_SOURCE_ETM_APT_T = VPA_SOURCE_HW_ETM_SW_APT,
   VPA_SOURCE_ETM_ET_T  = VPA_SOURCE_HW_ETM_SW_ET
} LTE_VPA_SOURCE_CONFIGUATION_TYPE;

/*******************************************************************************
 * Constant
 ******************************************************************************/

/*******************************************************************************
 * Global variables (Extern)
 ******************************************************************************/

/*******************************************************************************
 * Global Functions Prototype (Interface)
 ******************************************************************************/


#endif /*__EL1D_RF_PUBLIC_H__*/

/* Doxygen Group End ***************************************************//**@}*/
