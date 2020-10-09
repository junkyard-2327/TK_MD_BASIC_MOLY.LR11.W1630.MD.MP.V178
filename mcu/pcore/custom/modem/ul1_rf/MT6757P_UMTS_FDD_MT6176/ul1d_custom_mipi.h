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
 *	ul1d_custom_mipi.h
 *
 * Project:
 * --------
 * TK6291
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifndef  _UL1D_MIPI_DATA_SetDefault_H_
#define  _UL1D_MIPI_DATA_SetDefault_H_

/*===============================================================================*/
#include "kal_general_types.h"
#include "ul1d_rf_cid.h"
#include "ul1d_mipi_public.h"
#include "mml1_custom_mipi.h"

/*===============================================================================*/
#if (IS_3G_MIPI_SUPPORT)
#define MIPI_OFFSET_SetDefault         (77)   //~20us, 77 chips

/*Enable/Disable 3G FDD MIPI function*/
#define IS_3G_MIPI_ENABLE_SetDefault  1

#if (IS_3G_ET_SUPPORT)

/*Enable/Disable 3G FDD ET function*/
#define IS_3G_ET_ENABLE_SetDefault    0

#if (IS_3G_ET_ENABLE_SetDefault)
   #if (IS_3G_MIPI_ENABLE_SetDefault)
   #else
#error "IS_3G_MIPI_ENABLE should be 1 if want to enable ET !!!"
   #endif    
#endif

#define UNUSE                (0x00)
#define LEV_ADDR             (0x08)/*ET APT LEV ADDR*/

#if ( defined( ETM_MTK_MT6300_VERSION ) && ( ETM_MTK_MT6300_VERSION == ETM_MTK_MT6300_E1 ) )
#define HFP_EN               (0x02)/*CW09*/
#elif ( defined( ETM_MTK_MT6300_VERSION ) && ( ETM_MTK_MT6300_VERSION == ETM_MTK_MT6300_E2 ) )
#define HFP_EN               (0x42)/*CW09*/
#else
#define HFP_EN               (0x42)/*CW09*/
#endif

#define B1_ET_MOD_ST2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B1_ET_MOD_ST2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B1_ET_MOD_FD2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B1_ET_MOD_FD2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B1_ET_LEV_1ST_EVT_OFFSET     US2CHIPCNT(10)
#define B1_ET_LEV_2ND_EVT_OFFSET     US2CHIPCNT(14)
#define B1_ET_LEV_3RD_EVT_OFFSET     US2CHIPCNT(16)

#define B2_ET_MOD_ST2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B2_ET_MOD_ST2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B2_ET_MOD_FD2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B2_ET_MOD_FD2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B2_ET_LEV_1ST_EVT_OFFSET     US2CHIPCNT(10)
#define B2_ET_LEV_2ND_EVT_OFFSET     US2CHIPCNT(14)
#define B2_ET_LEV_3RD_EVT_OFFSET     US2CHIPCNT(16)

#define B4_ET_MOD_ST2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B4_ET_MOD_ST2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B4_ET_MOD_FD2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B4_ET_MOD_FD2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B4_ET_LEV_1ST_EVT_OFFSET     US2CHIPCNT(10)
#define B4_ET_LEV_2ND_EVT_OFFSET     US2CHIPCNT(14)
#define B4_ET_LEV_3RD_EVT_OFFSET     US2CHIPCNT(16)

#define B5_ET_MOD_ST2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B5_ET_MOD_ST2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B5_ET_MOD_FD2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B5_ET_MOD_FD2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B5_ET_LEV_1ST_EVT_OFFSET     US2CHIPCNT(10)
#define B5_ET_LEV_2ND_EVT_OFFSET     US2CHIPCNT(14)
#define B5_ET_LEV_3RD_EVT_OFFSET     US2CHIPCNT(16)

#define B8_ET_MOD_ST2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B8_ET_MOD_ST2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B8_ET_MOD_FD2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B8_ET_MOD_FD2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B8_ET_LEV_1ST_EVT_OFFSET     US2CHIPCNT(10)
#define B8_ET_LEV_2ND_EVT_OFFSET     US2CHIPCNT(14)
#define B8_ET_LEV_3RD_EVT_OFFSET     US2CHIPCNT(16)

#define B11_ET_MOD_ST2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B11_ET_MOD_ST2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B11_ET_MOD_FD2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B11_ET_MOD_FD2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B11_ET_LEV_1ST_EVT_OFFSET     US2CHIPCNT(10)
#define B11_ET_LEV_2ND_EVT_OFFSET     US2CHIPCNT(14)
#define B11_ET_LEV_3RD_EVT_OFFSET     US2CHIPCNT(16)

#define B19_ET_MOD_ST2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B19_ET_MOD_ST2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B19_ET_MOD_FD2FD_1_EVT_OFFSET US2CHIPCNT(8)
#define B19_ET_MOD_FD2FD_2_EVT_OFFSET US2CHIPCNT(10)
#define B19_ET_LEV_1ST_EVT_OFFSET     US2CHIPCNT(10)
#define B19_ET_LEV_2ND_EVT_OFFSET     US2CHIPCNT(14)
#define B19_ET_LEV_3RD_EVT_OFFSET     US2CHIPCNT(16)


/*Subband frequency in 100KHz unit*/
/*Band 1: [Center_Freq(100KHz)/10] x 5 = UARFCN*/
#define UMTS_B1_TX_SUB_0 19224
#define UMTS_B1_TX_SUB_1 19362
#define UMTS_B1_TX_SUB_2 19500
#define UMTS_B1_TX_SUB_3 19638
#define UMTS_B1_TX_SUB_4 19776

/*Band 2: [Center_Freq(100KHz)/10] x 5 = UARFCN*/
/*Band 2 add: [[Center_Freq(100KHz)/10]-1850.1] x 5 = UARFCN*/
#define UMTS_B2_TX_SUB_0 18524
#define UMTS_B2_TX_SUB_1 18662
#define UMTS_B2_TX_SUB_2 18800
#define UMTS_B2_TX_SUB_3 18938
#define UMTS_B2_TX_SUB_4 19076

/*Band 4: [[Center_Freq(100KHz)/10]-1805] x 5 = UARFCN*/
/*Band 4 add: [[Center_Freq(100KHz)/10]-1735.1] x 5 = UARFCN*/
#define UMTS_B4_TX_SUB_0 17124
#define UMTS_B4_TX_SUB_1 17224
#define UMTS_B4_TX_SUB_2 17324
#define UMTS_B4_TX_SUB_3 17425
#define UMTS_B4_TX_SUB_4 17526

/*Band 5: [Center_Freq(100KHz)/10] x 5 = UARFCN*/
/*Band 5 add: [[Center_Freq(100KHz)/10]-670.1] x 5 = UARFCN*/
#define UMTS_B5_TX_SUB_0 8264
#define UMTS_B5_TX_SUB_1 8314
#define UMTS_B5_TX_SUB_2 8365
#define UMTS_B5_TX_SUB_3 8415
#define UMTS_B5_TX_SUB_4 8466

/*Band 8: [[Center_Freq(100KHz)/10]-340] x 5 = UARFCN*/
#define UMTS_B8_TX_SUB_0 8824
#define UMTS_B8_TX_SUB_1 8899
#define UMTS_B8_TX_SUB_2 8975
#define UMTS_B8_TX_SUB_3 9050
#define UMTS_B8_TX_SUB_4 9126

#define UMTS_B3_TX_SUB_0 0//TBD
#define UMTS_B3_TX_SUB_1 0//TBD
#define UMTS_B3_TX_SUB_2 0//TBD
#define UMTS_B3_TX_SUB_3 0//TBD
#define UMTS_B3_TX_SUB_4 0//TBD

#define UMTS_B6_TX_SUB_0 0//TBD
#define UMTS_B6_TX_SUB_1 0//TBD
#define UMTS_B6_TX_SUB_2 0//TBD
#define UMTS_B6_TX_SUB_3 0//TBD
#define UMTS_B6_TX_SUB_4 0//TBD

#define UMTS_B9_TX_SUB_0 0//TBD 
#define UMTS_B9_TX_SUB_1 0//TBD
#define UMTS_B9_TX_SUB_2 0//TBD
#define UMTS_B9_TX_SUB_3 0//TBD
#define UMTS_B9_TX_SUB_4 0//TBD

#define UMTS_B10_TX_SUB_0 0//TBD
#define UMTS_B10_TX_SUB_1 0//TBD
#define UMTS_B10_TX_SUB_2 0//TBD
#define UMTS_B10_TX_SUB_3 0//TBD
#define UMTS_B10_TX_SUB_4 0//TBD

#define UMTS_B11_TX_SUB_0 14304
#define UMTS_B11_TX_SUB_1 14344
#define UMTS_B11_TX_SUB_2 14370
#define UMTS_B11_TX_SUB_3 14414
#define UMTS_B11_TX_SUB_4 14454

#define UMTS_B19_TX_SUB_0 8324
#define UMTS_B19_TX_SUB_1 8350
#define UMTS_B19_TX_SUB_2 8370
#define UMTS_B19_TX_SUB_3 8402
#define UMTS_B19_TX_SUB_4 8426

#define M_BAND1_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B1_TX_SUB_0, {sub0_addr, sub0_data}}, {UMTS_B1_TX_SUB_1, {sub1_addr, sub1_data}}, {UMTS_B1_TX_SUB_2, {sub2_addr, sub2_data}}, {UMTS_B1_TX_SUB_3, {sub3_addr, sub3_data}}, {UMTS_B1_TX_SUB_4, {sub4_addr, sub4_data}}}
#define M_BAND2_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B2_TX_SUB_0, {sub0_addr, sub0_data}}, {UMTS_B2_TX_SUB_1, {sub1_addr, sub1_data}}, {UMTS_B2_TX_SUB_2, {sub2_addr, sub2_data}}, {UMTS_B2_TX_SUB_3, {sub3_addr, sub3_data}}, {UMTS_B2_TX_SUB_4, {sub4_addr, sub4_data}}}
#define M_BAND3_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B3_TX_SUB_0, {sub0_addr, sub0_data}}, {UMTS_B3_TX_SUB_1, {sub1_addr, sub1_data}}, {UMTS_B3_TX_SUB_2, {sub2_addr, sub2_data}}, {UMTS_B3_TX_SUB_3, {sub3_addr, sub3_data}}, {UMTS_B3_TX_SUB_4, {sub4_addr, sub4_data}}}
#define M_BAND4_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B4_TX_SUB_0, {sub0_addr, sub0_data}}, {UMTS_B4_TX_SUB_1, {sub1_addr, sub1_data}}, {UMTS_B4_TX_SUB_2, {sub2_addr, sub2_data}}, {UMTS_B4_TX_SUB_3, {sub3_addr, sub3_data}}, {UMTS_B4_TX_SUB_4, {sub4_addr, sub4_data}}}
#define M_BAND5_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B5_TX_SUB_0, {sub0_addr, sub0_data}}, {UMTS_B5_TX_SUB_1, {sub1_addr, sub1_data}}, {UMTS_B5_TX_SUB_2, {sub2_addr, sub2_data}}, {UMTS_B5_TX_SUB_3, {sub3_addr, sub3_data}}, {UMTS_B5_TX_SUB_4, {sub4_addr, sub4_data}}}
#define M_BAND6_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B6_TX_SUB_0, {sub0_addr, sub0_data}}, {UMTS_B6_TX_SUB_1, {sub1_addr, sub1_data}}, {UMTS_B6_TX_SUB_2, {sub2_addr, sub2_data}}, {UMTS_B6_TX_SUB_3, {sub3_addr, sub3_data}}, {UMTS_B6_TX_SUB_4, {sub4_addr, sub4_data}}}
#define M_BAND8_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B8_TX_SUB_0, {sub0_addr, sub0_data}}, {UMTS_B8_TX_SUB_1, {sub1_addr, sub1_data}}, {UMTS_B8_TX_SUB_2, {sub2_addr, sub2_data}}, {UMTS_B8_TX_SUB_3, {sub3_addr, sub3_data}}, {UMTS_B8_TX_SUB_4, {sub4_addr, sub4_data}}}
#define M_BAND9_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B9_TX_SUB_0, {sub0_addr, sub0_data}}, {UMTS_B9_TX_SUB_1, {sub1_addr, sub1_data}}, {UMTS_B9_TX_SUB_2, {sub2_addr, sub2_data}}, {UMTS_B9_TX_SUB_3, {sub3_addr, sub3_data}}, {UMTS_B9_TX_SUB_4, {sub4_addr, sub4_data}}}
#define M_BAND10_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B10_TX_SUB_0,{sub0_addr, sub0_data}}, {UMTS_B10_TX_SUB_1,{sub1_addr, sub1_data}}, {UMTS_B10_TX_SUB_2,{sub2_addr, sub2_data}}, {UMTS_B10_TX_SUB_3,{sub3_addr, sub3_data}}, {UMTS_B10_TX_SUB_4,{sub4_addr, sub4_data}}}
#define M_BAND11_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B11_TX_SUB_0,{sub0_addr, sub0_data}}, {UMTS_B11_TX_SUB_1,{sub1_addr, sub1_data}}, {UMTS_B11_TX_SUB_2,{sub2_addr, sub2_data}}, {UMTS_B11_TX_SUB_3,{sub3_addr, sub3_data}}, {UMTS_B11_TX_SUB_4,{sub4_addr, sub4_data}}}
#define M_BAND19_SUB(sub0_addr, sub0_data, sub1_addr, sub1_data, sub2_addr, sub2_data, sub3_addr, sub3_data, sub4_addr, sub4_data) {{UMTS_B19_TX_SUB_0,{sub0_addr, sub0_data}}, {UMTS_B19_TX_SUB_1,{sub1_addr, sub1_data}}, {UMTS_B19_TX_SUB_2,{sub2_addr, sub2_data}}, {UMTS_B19_TX_SUB_3,{sub3_addr, sub3_data}}, {UMTS_B19_TX_SUB_4,{sub4_addr, sub4_data}}}


#endif /* IS_3G_ET_SUPPORT */

extern UL1_MIPI_DATA_TABLE_T          UMTS_MIPI_INITIAL_CW_SetDefault[UL1_MIPI_INIT_DATA_NUM];
extern UL1_MIPI_DATA_TABLE_T          UMTS_MIPI_SLEEP_CW_SetDefault[];
extern UL1_MIPI_EVENT_TABLE_T*        UMTS_MIPI_RX_EVENT_TABLE_SetDefault[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_RX_DATA_TABLE_SetDefault[];
extern UL1_MIPI_EVENT_TABLE_T*        UMTS_MIPI_TX_EVENT_TABLE_SetDefault[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_TX_DATA_TABLE_SetDefault[];
extern UL1_MIPI_DATA_TABLE_T*         UMTS_MIPI_ASM_ISOLATION_DATA_TABLE_SetDefault[];

extern UL1_UMTS_MIPI_TPC_T*           UMTS_MIPI_TPC_TABLE_SetDefault[];

#if (IS_3G_ET_SUPPORT)
extern UL1_MIPI_DATA_TABLE_T          UMTS_MIPI_ET_ON_STATIC_CW_SetDefault[];
extern UL1_MIPI_DATA_TABLE_T          UMTS_MIPI_ET_OFF_STATIC_CW_SetDefault[];
extern UL1_MIPI_EVENT_TABLE_T*        UMTS_MIPI_ET_EVENT_TABLE_SetDefault[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_ET_DATA_TABLE_SetDefault[];
extern UL1_UMTS_MIPI_ET_T*            UMTS_MIPI_ET_TABLE_SetDefault[];
extern UL1_UMTS_MIPI_ET_PARAM_T       UL1_ET_PARAM_SetDefault;

#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
extern UMTS_VPA_SOURCE_TYPE*          UMTS_VPA_SRC_SEL_TABLE_SetDefault[];
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#endif/*IS_3G_ET_SUPPORT*/



#endif/*IS_3G_MIPI_SUPPORT*/

#endif /* End of #ifndef _UL1D_MIPI_DATA_H_ */
