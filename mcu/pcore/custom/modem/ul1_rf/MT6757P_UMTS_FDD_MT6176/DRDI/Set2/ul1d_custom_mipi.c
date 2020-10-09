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
 * u1ld_custom_mipi.c
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

===============================================================================*/

#include "kal_general_types.h"
#include "ul1d_custom_mipi.h"
#include "ul1d_custom_rf.h"
#include "mml1_custom_mipi.h"
#include "ul1d_mipi_public.h"

#if defined(L1_SIM)
#include "SymWrap.h"
#endif
/*===============================================================================*/

//#define MIPI_INITIAL_CW_NUM 0
#if (IS_3G_MIPI_SUPPORT)

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBandNone_Set2[UL1_MIPI_RX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_NULL ,{ 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 1  */ UL1_MIPI_NULL ,{ 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 2  */ UL1_MIPI_NULL ,{ 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 3  */ UL1_MIPI_NULL ,{ 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 4  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 5  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 6  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 7  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 8  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 9  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 10 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 11 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 12 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 13 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 14 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 15 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 16 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 17 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 18 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 19 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 20 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 21 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 22 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 23 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};


UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand1_Set2[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_ASM,  { 0    , 6    }, UL1_MIPI_TRX_ON, US2CHIPCNT(200)     },
   { /* 1  */ UL1_MIPI_ASM,  { 7    , 18    }, UL1_MIPI_TRX_OFF,US2CHIPCNT(10)     },
   { /* 2  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 3  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 4  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 5  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 6  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 7  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 8  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 9  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 10 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 11 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 12 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 13 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 14 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 15 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 16 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 17 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 18 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 19 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 20 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 21 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 22 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 23 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};


UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand5_Set2[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_ASM,  { 0    , 6    }, UL1_MIPI_TRX_ON, US2CHIPCNT(200)     },
   { /* 1  */ UL1_MIPI_ASM,  { 7    , 18    }, UL1_MIPI_TRX_OFF,US2CHIPCNT(10)     },
   { /* 2  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 3  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 4  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 5  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 6  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 7  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 8  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 9  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 10 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 11 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 12 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 13 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 14 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 15 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 16 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 17 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 18 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 19 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 20 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 21 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 22 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 23 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand8_Set2[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_ASM,  { 0    , 6    }, UL1_MIPI_TRX_ON, US2CHIPCNT(200)     },
   { /* 1  */ UL1_MIPI_ASM,  { 7    , 18    }, UL1_MIPI_TRX_OFF,US2CHIPCNT(10)     },
   { /* 2  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 3  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 4  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 5  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 6  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 7  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 8  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 9  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 10 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 11 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 12 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 13 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 14 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 15 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 16 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 17 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 18 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 19 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 20 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 21 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 22 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 23 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand19_Set2[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_ASM,  { 0    , 6    }, UL1_MIPI_TRX_ON, US2CHIPCNT(200)     },
   { /* 1  */ UL1_MIPI_ASM,  { 7    , 18    }, UL1_MIPI_TRX_OFF,US2CHIPCNT(10)     },
   { /* 2  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 3  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 4  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 5  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 6  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 7  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 8  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 9  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 10 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 11 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 12 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 13 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 14 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 15 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 16 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 17 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 18 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 19 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 20 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 21 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 22 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 23 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand2_Set2[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand4_Set2[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand3_Set2[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand6_Set2[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand9_Set2[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand11_Set2[] = {{0}};


UL1_MIPI_EVENT_TABLE_T*  UMTS_MIPI_RX_EVENT_TABLE_Set2[] =
{
   M_UMTS_RX_EVENT(UMTSBandNone, Set2),          /*UMTSBandNone*/          
   M_UMTS_RX_EVENT(RX_BAND_INDICATOR_0_Set2, Set2),   /*UMTS_Route0*/
   M_UMTS_RX_EVENT(RX_BAND_INDICATOR_1_Set2, Set2),   /*UMTS_Route1*/
   M_UMTS_RX_EVENT(RX_BAND_INDICATOR_2_Set2, Set2),   /*UMTS_Route2*/   
   M_UMTS_RX_EVENT(RX_BAND_INDICATOR_3_Set2, Set2),   /*UMTS_Route3*/   
   M_UMTS_RX_EVENT(RX_BAND_INDICATOR_4_Set2, Set2),   /*UMTS_Route4*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_5, Set2),   /*UMTS_Route5*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_6, Set2),   /*UMTS_Route6*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_7, Set2),   /*UMTS_Route7*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_8, Set2),   /*UMTS_Route8*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_9, Set2),   /*UMTS_Route9*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_10, Set2),  /*UMTS_Route10*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_11, Set2),  /*UMTS_Route11*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_12, Set2),  /*UMTS_Route12*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_13, Set2),  /*UMTS_Route13*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_14, Set2),  /*UMTS_Route14*/
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBandNone_Set2[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data },{ sub 1 ,addr, data },{ sub 2 ,addr, data}, { sub 3, addr, data  }, { sub 4, addr data  } },
   { /* 0  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 1  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 2  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 3  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 4  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 5  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 6  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 18 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 19 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 20 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 21 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 22 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 23 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 24 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 25 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 26 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
   { /* 27 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}}} },
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand1_Set2[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 1  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x05, 0x03}}, { 21262 ,{0x05, 0x03}}, { 21400 ,{0x05, 0x03}}, { 21538  ,{0x05, 0x03}}, { 21676 ,{0x05, 0x03}}} },
   { /* 2  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 3  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 4  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },         
   { /* 5  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 6  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3, { { 21124 ,{0x01, 0x02}}, { 21262 ,{0x01, 0x02}}, { 21400 ,{0x01, 0x02}}, { 21538  ,{0x01, 0x02}}, { 21676 ,{0x01, 0x02}}} },
   { /* 7  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 8  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x05, 0x00}}, { 21262 ,{0x05, 0x00}}, { 21400 ,{0x05, 0x00}}, { 21538  ,{0x05, 0x00}}, { 21676 ,{0x05, 0x00}}} },
   { /* 9  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 10  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 11  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 12  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 13  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x04, 0x00}}, { 21262 ,{0x04, 0x00}}, { 21400 ,{0x04, 0x00}}, { 21538  ,{0x04, 0x00}}, { 21676 ,{0x04, 0x00}}} },
   { /* 14  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 15  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 16  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 17  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 18  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3, { { 21124 ,{0x01, 0x00}}, { 21262 ,{0x01, 0x00}}, { 21400 ,{0x01, 0x00}}, { 21538  ,{0x01, 0x00}}, { 21676 ,{0x01, 0x00}}} },
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 18 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 19 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 20 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 21 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 22 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 23 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 24 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 25 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 26 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 27 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },

};



UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand5_Set2[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x02, 0x04}}, { 8764 ,{0x02, 0x04}},   { 8815 ,{0x02, 0x04}},  { 8865  ,{0x02, 0x04}},   { 8916 ,{0x02, 0x04}} }},
   { /* 2  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}} }},
   { /* 3  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}} }},
   { /* 4  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}} }},
   { /* 5  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}} }},
   { /* 6  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 8714 ,{0x00, 0x04}}, { 8764 ,{0x00, 0x04}},   { 8815 ,{0x00, 0x04}},  { 8865  ,{0x00, 0x04}},   { 8916 ,{0x00, 0x04}} }},
   { /* 7  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}}} },
   { /* 8  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x02, 0x00}}, { 8764 ,{0x02, 0x00}},   { 8815 ,{0x02, 0x00}},  { 8865  ,{0x02, 0x00}},   { 8916 ,{0x02, 0x00}}} },
   { /* 9  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}}} },
   { /* 10  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}}} },
   { /* 11  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}}} },
   { /* 12  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}}} },
   { /* 13  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x04, 0x00}}, { 8764 ,{0x04, 0x00}},   { 8815 ,{0x04, 0x00}},  { 8865  ,{0x04, 0x00}},   { 8916 ,{0x04, 0x00}}} },
   { /* 14  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}}} },
   { /* 15  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}}} },
   { /* 16  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}}} },
   { /* 17  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}}} },
   { /* 18  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 8714 ,{0x00, 0x00}}, { 8764 ,{0x00, 0x00}},   { 8815 ,{0x00, 0x00}},  { 8865  ,{0x00, 0x00}},   { 8916 ,{0x00, 0x00}}} },
   { /* 19  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 20  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 10  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 18 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 19 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 20 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 21 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 22 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 23 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 24 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 25 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 26 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 27 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
};


UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand8_Set2[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x02, 0x02}}, { 9349 ,{0x02, 0x02}},   { 9425 ,{0x02, 0x02}},  { 9500  ,{0x02, 0x02}},   { 9576 ,{0x02, 0x02}} }},
   { /* 2  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}} }},
   { /* 3  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}} }},
   { /* 4  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}} }},
   { /* 5  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}} }},
   { /* 6  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 9274 ,{0x00, 0x03}}, { 9349 ,{0x00, 0x03}},   { 9425 ,{0x00, 0x03}},  { 9500  ,{0x00, 0x03}},   { 9576 ,{0x00, 0x03}} }},
   { /* 7  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}}} },
   { /* 8  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x02, 0x00}}, { 9349 ,{0x02, 0x00}},   { 9425 ,{0x02, 0x00}},  { 9500  ,{0x02, 0x00}},   { 9576 ,{0x02, 0x00}}} },
   { /* 9  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}}} },
   { /* 10  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}}} },
   { /* 11  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}}} },
   { /* 12  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}}} },
   { /* 13  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x04, 0x00}}, { 9349 ,{0x04, 0x00}},   { 9425 ,{0x04, 0x00}},  { 9500  ,{0x04, 0x00}},   { 9576 ,{0x04, 0x00}}} },
   { /* 14  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}}} },
   { /* 15  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}}} },
   { /* 16  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}}} },
   { /* 17  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}}} },
   { /* 18  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 9274 ,{0x00, 0x00}}, { 9349 ,{0x00, 0x00}},   { 9425 ,{0x00, 0x00}},  { 9500  ,{0x00, 0x00}},   { 9576 ,{0x00, 0x00}}} },
   { /* 19  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 20  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 14  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 15  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 17  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 18 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 19 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 20 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 21 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 22 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 23 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 24 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 25 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 26 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 27 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand19_Set2[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x02, 0x04}}, { 8804 ,{0x02, 0x04}},   { 8834 ,{0x02, 0x04}},  { 8864  ,{0x02, 0x04}},   { 8876 ,{0x02, 0x04}} }},
   { /* 2  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}} }},
   { /* 3  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}} }},
   { /* 4  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}} }},
   { /* 5  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}} }},
   { /* 6  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 8774 ,{0x00, 0x04}}, { 8804 ,{0x00, 0x04}},   { 8834 ,{0x00, 0x04}},  { 8864  ,{0x00, 0x04}},   { 8876 ,{0x00, 0x04}} }},
   { /* 7  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}}} },
   { /* 8  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x02, 0x00}}, { 8804 ,{0x02, 0x00}},   { 8834 ,{0x02, 0x00}},  { 8864  ,{0x02, 0x00}},   { 8876 ,{0x02, 0x00}}} },
   { /* 9  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}}} },
   { /* 10  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}}} },
   { /* 11  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}}} },
   { /* 12  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}}} },
   { /* 13  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x04, 0x00}}, { 8804 ,{0x04, 0x00}},   { 8834 ,{0x04, 0x00}},  { 8864  ,{0x04, 0x00}},   { 8876 ,{0x04, 0x00}}} },
   { /* 14  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}}} },
   { /* 15  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}}} },
   { /* 16  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM0_P3,  { { 8774 ,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}}} },
   { /* 17  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 8774,{0x1C, 0x38}}, { 8804 ,{0x1C, 0x38}},   { 8834 ,{0x1C, 0x38}},  { 8864  ,{0x1C, 0x38}},   { 8876 ,{0x1C, 0x38}}} },
   { /* 18  */ UL1_MIPI_ASM,  UL1_MIPI_PORT0,  UL1_REG_W     , MIPI_USID_ASM1_P3,  { { 8774 ,{0x00, 0x00}}, { 8804 ,{0x00, 0x00}},   { 8834 ,{0x00, 0x00}},  { 8864  ,{0x00, 0x00}},   { 8876 ,{0x00, 0x00}}} },
   { /* 19  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 20  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 21  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 22  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 23  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 24  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 25  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 26  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 27  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 28  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 29  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 30  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 31  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 32  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 33  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 34  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 35  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 36  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 37  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 38  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 39  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 40  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 41  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
   { /* 42  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8774 ,{0x0, 0x0}},   { 8804 ,{0x0, 0x0}},     { 8834 ,{0x0, 0x0}},    { 8864  ,{0x0, 0x0}},     { 8876 ,{0x0,   0x0}} }},
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand2_Set2[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand4_Set2[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand3_Set2[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand6_Set2[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand9_Set2[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand11_Set2[] = {{0}};


UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_RX_DATA_TABLE_Set2[] = 
{
   M_UMTS_RX_DATA(UMTSBandNone,Set2),          /*UMTSBandNone*/          
   M_UMTS_RX_DATA(RX_BAND_INDICATOR_0_Set2,Set2),   /*UMTS_Route0*/
   M_UMTS_RX_DATA(RX_BAND_INDICATOR_1_Set2,Set2),   /*UMTS_Route1*/
   M_UMTS_RX_DATA(RX_BAND_INDICATOR_2_Set2,Set2),   /*UMTS_Route2*/
   M_UMTS_RX_DATA(RX_BAND_INDICATOR_3_Set2,Set2),   /*UMTS_Route3*/ 
   M_UMTS_RX_DATA(RX_BAND_INDICATOR_4_Set2,Set2),   /*UMTS_Route4*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_5,Set2),   /*UMTS_Route5*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_6,Set2),   /*UMTS_Route6*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_7,Set2),   /*UMTS_Route7*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_8,Set2),   /*UMTS_Route8*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_9,Set2),   /*UMTS_Route9*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_10,Set2),  /*UMTS_Route10*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_11,Set2),  /*UMTS_Route11*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_12,Set2),  /*UMTS_Route12*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_13,Set2),  /*UMTS_Route13*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_14,Set2),  /*UMTS_Route14*/
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBandNone_Set2[UL1_MIPI_TX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 1  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 2  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 3  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 4  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 5  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 6  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 7  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 8  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 9  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 10 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 11 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 12 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 13 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 14 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 15 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand1_Set2[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_PA,   { 0    , 0   }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ UL1_MIPI_PA,   { 1    , 4   }, UL1_MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ UL1_MIPI_ASM,  { 5    , 15    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200) },
   { /* 3  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 4  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 5  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 6  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 7  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 8  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 9  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 10 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 11 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 12 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 13 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 14 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 15 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};


UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand5_Set2[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_PA,   { 0    , 0    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ UL1_MIPI_PA,   { 1    , 4    }, UL1_MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ UL1_MIPI_ASM,  { 5    , 15    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200) },
   { /* 3  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 4  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 5  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 6  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 7  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 8  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 9  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 10 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 11 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 12 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 13 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 14 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 15 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand8_Set2[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_PA,   { 0    , 0    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ UL1_MIPI_PA,   { 1    , 4    }, UL1_MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ UL1_MIPI_ASM,  { 5    , 15    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200) },
   { /* 3  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 4  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 5  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 6  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 7  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 8  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 9  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 10 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 11 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 12 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 13 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 14 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 15 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand19_Set2[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_PA,   { 0    , 0    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ UL1_MIPI_PA,   { 1    , 4    }, UL1_MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ UL1_MIPI_ASM,  { 5    , 15    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200) },
   { /* 3  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 4  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 5  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 6  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 7  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 8  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 9  */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 10 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 11 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 12 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 13 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 14 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 15 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand2_Set2[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand4_Set2[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand3_Set2[]  = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand6_Set2[]  = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand9_Set2[]  = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand11_Set2[] = {{0}};


UL1_MIPI_EVENT_TABLE_T*  UMTS_MIPI_TX_EVENT_TABLE_Set2[] =
{
   M_UMTS_TX_EVENT(UMTSBandNone,Set2),                       /*UMTSUMTSBandNone*/          
   M_UMTS_TX_EVENT(RX_BAND_INDICATOR_0_Set2,Set2),     /*RX_BAND_INDICATOR_0_Set2*/
   M_UMTS_TX_EVENT(RX_BAND_INDICATOR_1_Set2,Set2),     /*RX_BAND_INDICATOR_1_Set2*/
   M_UMTS_TX_EVENT(RX_BAND_INDICATOR_2_Set2,Set2),     /*RX_BAND_INDICATOR_2_Set2*/
   M_UMTS_TX_EVENT(RX_BAND_INDICATOR_3_Set2,Set2),     /*RX_BAND_INDICATOR_3_Set2*/ 
   M_UMTS_TX_EVENT(RX_BAND_INDICATOR_4_Set2,Set2),     /*RX_BAND_INDICATOR_4_Set2*/ 
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBandNone_Set2[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 1  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 2  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 3  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 4  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 5  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 6  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL , MIPI_USID_INIT0 , { { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},     { 0x0 ,{0x0, 0x0}},       { 0x0 ,{0x0, 0x0}} }},
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand1_Set2[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA0_P3   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},
   { /* 1  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA0_P3   , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 2  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA0_P3   , { { 19224 ,{0x01, 0x00}}, { 19362 ,{0x01, 0x00}}, { 19500 ,{0x01, 0x00}}, { 19638 ,{0x01, 0x00}}, { 19776 ,{0x01, 0x00}}}},
   { /* 3  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA0_P3   , { { 19224 ,{0x02, 0x00}}, { 19362 ,{0x02, 0x00}}, { 19500 ,{0x02, 0x00}}, { 19638 ,{0x02, 0x00}}, { 19776 ,{0x02, 0x00}}}},
   { /* 4  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA0_P3   , { { 19224 ,{0x03, 0x00}}, { 19362 ,{0x03, 0x00}}, { 19500 ,{0x03, 0x00}}, { 19638 ,{0x03, 0x00}}, { 19776 ,{0x03, 0x00}}}},
   { /* 5  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},
   { /* 6  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x00, 0x80}}, { 19362 ,{0x00, 0x80}}, { 19500 ,{0x00, 0x80}}, { 19638 ,{0x00, 0x80}}, { 19776 ,{0x00, 0x80}}}},
   { /* 7  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x05, 0x03}}, { 19362 ,{0x05, 0x03}}, { 19500 ,{0x05, 0x03}}, { 19638 ,{0x05, 0x03}}, { 19776 ,{0x05, 0x03}}}},
   { /* 8  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},
   { /* 9  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},   
   { /* 10  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},   
   { /* 11  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},
   { /* 12  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x04, 0x13}}, { 19362 ,{0x04, 0x13}}, { 19500 ,{0x04, 0x13}}, { 19638 ,{0x04, 0x13}}, { 19776 ,{0x04, 0x13}}}},
   { /* 13  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},
   { /* 14  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},
   { /* 15  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},         
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
};



UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand5_Set2[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 2  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8264 ,{0x01, 0x00}}, { 8314 ,{0x01, 0x00}}, { 8365 ,{0x01, 0x00}}, { 8415 ,{0x01, 0x00}}, { 8466 ,{0x01, 0x00}} }},
   { /* 3  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8264 ,{0x02, 0x00}}, { 8314 ,{0x02, 0x00}}, { 8365 ,{0x02, 0x00}}, { 8415 ,{0x02, 0x00}}, { 8466 ,{0x02, 0x00}} }},
   { /* 4  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8264 ,{0x03, 0x00}}, { 8314 ,{0x03, 0x00}}, { 8365 ,{0x03, 0x00}}, { 8415 ,{0x03, 0x00}}, { 8466 ,{0x03, 0x00}} }},
   { /* 5  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 6  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x00, 0x80}}, { 8314 ,{0x00, 0x80}}, { 8365 ,{0x00, 0x80}}, { 8415 ,{0x00, 0x80}}, { 8466 ,{0x00, 0x80}} }},
   { /* 7  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x02, 0x04}}, { 8314 ,{0x02, 0x04}}, { 8365 ,{0x02, 0x04}}, { 8415 ,{0x02, 0x04}}, { 8466 ,{0x02, 0x04}} }},
   { /* 8  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 9  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 10  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 11  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 12  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x04, 0x0B}}, { 8314 ,{0x04, 0x0B}}, { 8365 ,{0x04, 0x0B}}, { 8415 ,{0x04, 0x0B}}, { 8466 ,{0x04, 0x0B}} }},
   { /* 13  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 14  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 15  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
};


UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand8_Set2[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 2  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8824 ,{0x01, 0x00}}, { 8899 ,{0x01, 0x00}}, { 8975 ,{0x01, 0x00}}, { 9050 ,{0x01, 0x00}}, { 9126 ,{0x01, 0x00}} }},
   { /* 3  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8824 ,{0x02, 0x00}}, { 8899 ,{0x02, 0x00}}, { 8975 ,{0x02, 0x00}}, { 9050 ,{0x02, 0x00}}, { 9126 ,{0x02, 0x00}} }},
   { /* 4  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8824 ,{0x03, 0x00}}, { 8899 ,{0x03, 0x00}}, { 8975 ,{0x03, 0x00}}, { 9050 ,{0x03, 0x00}}, { 9126 ,{0x03, 0x00}} }},
   { /* 5  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 6  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x00, 0x80}}, { 8899 ,{0x00, 0x80}}, { 8975 ,{0x00, 0x80}}, { 9050 ,{0x00, 0x80}}, { 9126 ,{0x00, 0x80}} }},
   { /* 7  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x02, 0x02}}, { 8899 ,{0x02, 0x02}}, { 8975 ,{0x02, 0x02}}, { 9050 ,{0x02, 0x02}}, { 9126 ,{0x02, 0x02}} }},
   { /* 8  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 9  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 10  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 11  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 12  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x04, 0x0B}}, { 8899 ,{0x04, 0x0B}}, { 8975 ,{0x04, 0x0B}}, { 9050 ,{0x04, 0x0B}}, { 9126 ,{0x04, 0x0B}} }},
   { /* 13  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 14  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 15  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
};


UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand19_Set2[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8324 ,{0x1C, 0x38}}, { 8354 ,{0x1C, 0x38}}, { 8384 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8426 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8324,{0x00, 0x00}}, { 8354 ,{0x00, 0x00}}, { 8384 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8426 ,{0x00, 0x00}} }},
   { /* 2  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8324 ,{0x01, 0x00}}, { 8354 ,{0x01, 0x00}}, { 8384 ,{0x01, 0x00}}, { 8415 ,{0x01, 0x00}}, { 8426 ,{0x01, 0x00}} }},
   { /* 3  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8324 ,{0x02, 0x00}}, { 8354 ,{0x02, 0x00}}, { 8384 ,{0x02, 0x00}}, { 8415 ,{0x02, 0x00}}, { 8426 ,{0x02, 0x00}} }},
   { /* 4  */ UL1_MIPI_PA  , UL1_MIPI_PORT1, UL1_REG_W  ,    MIPI_USID_PA1_P3   , { { 8324 ,{0x03, 0x00}}, { 8354 ,{0x03, 0x00}}, { 8384 ,{0x03, 0x00}}, { 8415 ,{0x03, 0x00}}, { 8426 ,{0x03, 0x00}} }},
   { /* 5  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x1C, 0x38}}, { 8354 ,{0x1C, 0x38}}, { 8384 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8426 ,{0x1C, 0x38}} }},
   { /* 6  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x00, 0x80}}, { 8354 ,{0x00, 0x80}}, { 8384 ,{0x00, 0x80}}, { 8415 ,{0x00, 0x80}}, { 8426 ,{0x00, 0x80}} }},
   { /* 7  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x02, 0x04}}, { 8354 ,{0x02, 0x04}}, { 8384 ,{0x02, 0x04}}, { 8415 ,{0x02, 0x04}}, { 8426 ,{0x02, 0x04}} }},
   { /* 8  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x1C, 0x38}}, { 8354 ,{0x1C, 0x38}}, { 8384 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8426 ,{0x1C, 0x38}} }},
   { /* 9  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x1C, 0x38}}, { 8354 ,{0x1C, 0x38}}, { 8384 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8426 ,{0x1C, 0x38}} }},
   { /* 10  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x1C, 0x38}}, { 8354 ,{0x1C, 0x38}}, { 8384 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8426 ,{0x1C, 0x38}} }},
   { /* 11  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x1C, 0x38}}, { 8354 ,{0x1C, 0x38}}, { 8384 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8426 ,{0x1C, 0x38}} }},
   { /* 12  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x04, 0x0B}}, { 8354 ,{0x04, 0x0B}}, { 8384 ,{0x04, 0x0B}}, { 8415 ,{0x04, 0x0B}}, { 8426 ,{0x04, 0x0B}} }},
   { /* 13  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x1C, 0x38}}, { 8354 ,{0x1C, 0x38}}, { 8384 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8426 ,{0x1C, 0x38}} }},
   { /* 14  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x1C, 0x38}}, { 8354 ,{0x1C, 0x38}}, { 8384 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8426 ,{0x1C, 0x38}} }},
   { /* 15  */ UL1_MIPI_ASM  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0_P3    , { { 8324 ,{0x1C, 0x38}}, { 8354 ,{0x1C, 0x38}}, { 8384 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8426 ,{0x1C, 0x38}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8324 ,{0x00, 0x00}}, { 8354 ,{0x00, 0x00}}, { 8384 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8426 ,{0x00, 0x00}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8324 ,{0x00, 0x00}}, { 8354 ,{0x00, 0x00}}, { 8384 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8426 ,{0x00, 0x00}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8324 ,{0x00, 0x00}}, { 8354 ,{0x00, 0x00}}, { 8384 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8426 ,{0x00, 0x00}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8324 ,{0x00, 0x00}}, { 8354 ,{0x00, 0x00}}, { 8384 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8426 ,{0x00, 0x00}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8324 ,{0x00, 0x00}}, { 8354 ,{0x00, 0x00}}, { 8384 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8426 ,{0x00, 0x00}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8324 ,{0x00, 0x00}}, { 8354 ,{0x00, 0x00}}, { 8384 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8426 ,{0x00, 0x00}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8324 ,{0x00, 0x00}}, { 8354 ,{0x00, 0x00}}, { 8384 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8426 ,{0x00, 0x00}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8324 ,{0x00, 0x00}}, { 8354 ,{0x00, 0x00}}, { 8384 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8426 ,{0x00, 0x00}} }},
   { /* 16  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8324 ,{0x00, 0x00}}, { 8354 ,{0x00, 0x00}}, { 8384 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8426 ,{0x00, 0x00}} }},
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand2_Set2[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand4_Set2[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand3_Set2[]  = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand6_Set2[]  = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand9_Set2[]  = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand11_Set2[] = {{0}};


UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_TX_DATA_TABLE_Set2[] = 
{
   M_UMTS_TX_DATA(UMTSBandNone,Set2),                     /*UMTSUMTSBandNone*/
   M_UMTS_TX_DATA(RX_BAND_INDICATOR_0_Set2,Set2),   /*RX_BAND_INDICATOR_0_Set2*/
   M_UMTS_TX_DATA(RX_BAND_INDICATOR_1_Set2,Set2),   /*RX_BAND_INDICATOR_1_Set2*/
   M_UMTS_TX_DATA(RX_BAND_INDICATOR_2_Set2,Set2),   /*RX_BAND_INDICATOR_2_Set2*/
   M_UMTS_TX_DATA(RX_BAND_INDICATOR_3_Set2,Set2),   /*RX_BAND_INDICATOR_3_Set2*/
   M_UMTS_TX_DATA(RX_BAND_INDICATOR_4_Set2,Set2),   /*RX_BAND_INDICATOR_4_Set2*/
};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBandNone_Set2 = {{{0}}};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand1_Set2 = 
{
   /* Event */
  {
   /* No.           elm type , data idx       , evt_type       , evt_offset     */
   /*                           { start, stop },                  ( us )         */
    { /* 0, Prf_7  */ UL1_MIPI_PA, { 0    , 3     }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*highest power*/
    { /* 1, Prf_6  */ UL1_MIPI_PA, { 4    , 7     }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 2, Prf_5  */ UL1_MIPI_PA, { 8    , 11    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 3, Prf_4  */ UL1_MIPI_PA, { 12   , 15    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 4, Prf_3  */ UL1_MIPI_PA, { 16   , 19    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 5, Prf_2  */ UL1_MIPI_PA, { 20   , 23    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 6, Prf_1  */ UL1_MIPI_PA, { 24   , 27    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
    { /* 7, Prf_0  */ UL1_MIPI_PA, { 28   , 31    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*lowest power*/
  },

  /* Data */
  {
   //elm type  , port_sel       , data_seq, user id,         {{sub 0, addr, data}}, {{sub 1, addr, data}}, {{sub 2, addr, data} , {{sub 3, addr, data}}, {{sub 4, addr, data}
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x00, 0x24}}, {19362, {0x00, 0x24}}, {19500, {0x00, 0x24}}, {19638, {0x00, 0x24}}, {19776, {0x00, 0x24}}}},  /*L7, TPC IDX 0*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x01, 0xAC}}, {19362, {0x01, 0xAC}}, {19500, {0x01, 0xAC}}, {19638, {0x01, 0xAC}}, {19776, {0x01, 0xAC}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x02, 0x20}}, {19362, {0x02, 0x20}}, {19500, {0x02, 0x20}}, {19638, {0x02, 0x20}}, {19776, {0x02, 0x20}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x03, 0x8A}}, {19362, {0x03, 0x8A}}, {19500, {0x03, 0x8A}}, {19638, {0x03, 0x8A}}, {19776, {0x03, 0x8A}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x00, 0x24}}, {19362, {0x00, 0x24}}, {19500, {0x00, 0x24}}, {19638, {0x00, 0x24}}, {19776, {0x00, 0x24}}}},  /*L6, TPC IDX 2*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x01, 0xAC}}, {19362, {0x01, 0xAC}}, {19500, {0x01, 0xAC}}, {19638, {0x01, 0xAC}}, {19776, {0x01, 0xAC}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x02, 0x20}}, {19362, {0x02, 0x20}}, {19500, {0x02, 0x20}}, {19638, {0x02, 0x20}}, {19776, {0x02, 0x20}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x03, 0x8A}}, {19362, {0x03, 0x8A}}, {19500, {0x03, 0x8A}}, {19638, {0x03, 0x8A}}, {19776, {0x03, 0x8A}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x00, 0x24}}, {19362, {0x00, 0x24}}, {19500, {0x00, 0x24}}, {19638, {0x00, 0x24}}, {19776, {0x00, 0x24}}}},  /*L5, TPC IDX 4*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x01, 0xAC}}, {19362, {0x01, 0xAC}}, {19500, {0x01, 0xAC}}, {19638, {0x01, 0xAC}}, {19776, {0x01, 0xAC}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x02, 0x20}}, {19362, {0x02, 0x20}}, {19500, {0x02, 0x20}}, {19638, {0x02, 0x20}}, {19776, {0x02, 0x20}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x03, 0x8A}}, {19362, {0x03, 0x8A}}, {19500, {0x03, 0x8A}}, {19638, {0x03, 0x8A}}, {19776, {0x03, 0x8A}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x00, 0x24}}, {19362, {0x00, 0x24}}, {19500, {0x00, 0x24}}, {19638, {0x00, 0x24}}, {19776, {0x00, 0x24}}}},  /*L4, TPC IDX 6*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x01, 0x35}}, {19362, {0x01, 0x35}}, {19500, {0x01, 0x35}}, {19638, {0x01, 0x35}}, {19776, {0x01, 0x35}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x02, 0x20}}, {19362, {0x02, 0x20}}, {19500, {0x02, 0x20}}, {19638, {0x02, 0x20}}, {19776, {0x02, 0x20}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x03, 0x86}}, {19362, {0x03, 0x86}}, {19500, {0x03, 0x86}}, {19638, {0x03, 0x86}}, {19776, {0x03, 0x86}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x00, 0x24}}, {19362, {0x00, 0x24}}, {19500, {0x00, 0x24}}, {19638, {0x00, 0x24}}, {19776, {0x00, 0x24}}}},  /*L3, TPC IDX 9*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x01, 0x35}}, {19362, {0x01, 0x35}}, {19500, {0x01, 0x35}}, {19638, {0x01, 0x35}}, {19776, {0x01, 0x35}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x02, 0x20}}, {19362, {0x02, 0x20}}, {19500, {0x02, 0x20}}, {19638, {0x02, 0x20}}, {19776, {0x02, 0x20}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x03, 0x86}}, {19362, {0x03, 0x86}}, {19500, {0x03, 0x86}}, {19638, {0x03, 0x86}}, {19776, {0x03, 0x86}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x00, 0x24}}, {19362, {0x00, 0x24}}, {19500, {0x00, 0x24}}, {19638, {0x00, 0x24}}, {19776, {0x00, 0x24}}}},  /*L2, TPC IDX 15, Hyst1*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x01, 0x24}}, {19362, {0x01, 0x24}}, {19500, {0x01, 0x24}}, {19638, {0x01, 0x24}}, {19776, {0x01, 0x24}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x02, 0x20}}, {19362, {0x02, 0x20}}, {19500, {0x02, 0x20}}, {19638, {0x02, 0x20}}, {19776, {0x02, 0x20}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x03, 0x86}}, {19362, {0x03, 0x86}}, {19500, {0x03, 0x86}}, {19638, {0x03, 0x86}}, {19776, {0x03, 0x86}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x00, 0x24}}, {19362, {0x00, 0x24}}, {19500, {0x00, 0x24}}, {19638, {0x00, 0x24}}, {19776, {0x00, 0x24}}}},  /*L1, TPC IDX 18*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x01, 0x14}}, {19362, {0x01, 0x14}}, {19500, {0x01, 0x14}}, {19638, {0x01, 0x14}}, {19776, {0x01, 0x14}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x02, 0x20}}, {19362, {0x02, 0x20}}, {19500, {0x02, 0x20}}, {19638, {0x02, 0x20}}, {19776, {0x02, 0x20}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x03, 0x86}}, {19362, {0x03, 0x86}}, {19500, {0x03, 0x86}}, {19638, {0x03, 0x86}}, {19776, {0x03, 0x86}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x00, 0x24}}, {19362, {0x00, 0x24}}, {19500, {0x00, 0x24}}, {19638, {0x00, 0x24}}, {19776, {0x00, 0x24}}}},  /*L0, TPC IDX 25, Hyst2*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x01, 0x13}}, {19362, {0x01, 0x13}}, {19500, {0x01, 0x13}}, {19638, {0x01, 0x13}}, {19776, {0x01, 0x13}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x02, 0x20}}, {19362, {0x02, 0x20}}, {19500, {0x02, 0x20}}, {19638, {0x02, 0x20}}, {19776, {0x02, 0x20}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA0_P3,   {{19224, {0x03, 0x86}}, {19362, {0x03, 0x86}}, {19500, {0x03, 0x86}}, {19638, {0x03, 0x86}}, {19776, {0x03, 0x86}}}},
    {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}},
    {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{19224, {0x00, 0x00}}, {19362, {0x00, 0x00}}, {19500, {0x00, 0x00}}, {19638, {0x00, 0x00}}, {19776, {0x00, 0x00}}}} 
  }
};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand5_Set2 = 
{
   /* Event */
   {
    /* No.           elm type , data idx       , evt_type       , evt_offset     */
    /*                           { start, stop },                  ( us )         */
     { /* 0, Prf_7  */ UL1_MIPI_PA, { 0    , 3     }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*highest power*/
     { /* 1, Prf_6  */ UL1_MIPI_PA, { 4    , 7     }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 2, Prf_5  */ UL1_MIPI_PA, { 8    , 11    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 3, Prf_4  */ UL1_MIPI_PA, { 12   , 15    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 4, Prf_3  */ UL1_MIPI_PA, { 16   , 19    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 5, Prf_2  */ UL1_MIPI_PA, { 20   , 23    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 6, Prf_1  */ UL1_MIPI_PA, { 24   , 27    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 7, Prf_0  */ UL1_MIPI_PA, { 28   , 31    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*lowest power*/
   },
   
   /* Data */
   {                                                                                                                                                                               
      //elm type  , port_sel     , data_seq, user id,         {{sub 0, addr, data}}, {{sub 1, addr, data}}, {{sub 2, addr, data} , {{sub 3, addr, data}}, {{sub 4, addr, data}     
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x00, 0x8D}}, {8314, {0x00, 0x8D}}, {8365, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8466, {0x00, 0x8D}} }},  /*L7, TPC IDX 0*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x01, 0x77}}, {8314, {0x01, 0x77}}, {8365, {0x01, 0x77}}, {8415, {0x01, 0x77}}, {8466, {0x01, 0x77}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x02, 0x00}}, {8314, {0x02, 0x00}}, {8365, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8466, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x03, 0x89}}, {8314, {0x03, 0x89}}, {8365, {0x03, 0x89}}, {8415, {0x03, 0x89}}, {8466, {0x03, 0x89}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x00, 0x8D}}, {8314, {0x00, 0x8D}}, {8365, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8466, {0x00, 0x8D}} }},  /*L6, TPC IDX 2*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x01, 0x77}}, {8314, {0x01, 0x77}}, {8365, {0x01, 0x77}}, {8415, {0x01, 0x77}}, {8466, {0x01, 0x77}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x02, 0x00}}, {8314, {0x02, 0x00}}, {8365, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8466, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x03, 0x89}}, {8314, {0x03, 0x89}}, {8365, {0x03, 0x89}}, {8415, {0x03, 0x89}}, {8466, {0x03, 0x89}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x00, 0x8D}}, {8314, {0x00, 0x8D}}, {8365, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8466, {0x00, 0x8D}} }},  /*L5, TPC IDX 4*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x01, 0x77}}, {8314, {0x01, 0x77}}, {8365, {0x01, 0x77}}, {8415, {0x01, 0x77}}, {8466, {0x01, 0x77}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x02, 0x00}}, {8314, {0x02, 0x00}}, {8365, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8466, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x03, 0x89}}, {8314, {0x03, 0x89}}, {8365, {0x03, 0x89}}, {8415, {0x03, 0x89}}, {8466, {0x03, 0x89}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x00, 0x8D}}, {8314, {0x00, 0x8D}}, {8365, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8466, {0x00, 0x8D}} }},  /*L4, TPC IDX 6*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x01, 0x44}}, {8314, {0x01, 0x44}}, {8365, {0x01, 0x44}}, {8415, {0x01, 0x44}}, {8466, {0x01, 0x44}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x02, 0x00}}, {8314, {0x02, 0x00}}, {8365, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8466, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x03, 0x80}}, {8314, {0x03, 0x80}}, {8365, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8466, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x00, 0x8D}}, {8314, {0x00, 0x8D}}, {8365, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8466, {0x00, 0x8D}} }},  /*L3, TPC IDX 9*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x01, 0x34}}, {8314, {0x01, 0x34}}, {8365, {0x01, 0x34}}, {8415, {0x01, 0x34}}, {8466, {0x01, 0x34}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x02, 0x00}}, {8314, {0x02, 0x00}}, {8365, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8466, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x03, 0x80}}, {8314, {0x03, 0x80}}, {8365, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8466, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x00, 0x8D}}, {8314, {0x00, 0x8D}}, {8365, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8466, {0x00, 0x8D}} }},  /*L2, TPC IDX 15, Hyst1*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x01, 0x24}}, {8314, {0x01, 0x24}}, {8365, {0x01, 0x24}}, {8415, {0x01, 0x24}}, {8466, {0x01, 0x24}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x02, 0x00}}, {8314, {0x02, 0x00}}, {8365, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8466, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x03, 0x80}}, {8314, {0x03, 0x80}}, {8365, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8466, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x00, 0x8D}}, {8314, {0x00, 0x8D}}, {8365, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8466, {0x00, 0x8D}} }},  /*L1, TPC IDX 18*/       
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x01, 0x23}}, {8314, {0x01, 0x23}}, {8365, {0x01, 0x23}}, {8415, {0x01, 0x23}}, {8466, {0x01, 0x23}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x02, 0x00}}, {8314, {0x02, 0x00}}, {8365, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8466, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x03, 0x80}}, {8314, {0x03, 0x80}}, {8365, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8466, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x00, 0x8D}}, {8314, {0x00, 0x8D}}, {8365, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8466, {0x00, 0x8D}} }},  /*L0, TPC IDX 25, Hyst2*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x01, 0x22}}, {8314, {0x01, 0x22}}, {8365, {0x01, 0x22}}, {8415, {0x01, 0x22}}, {8466, {0x01, 0x22}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x02, 0x00}}, {8314, {0x02, 0x00}}, {8365, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8466, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8264, {0x03, 0x80}}, {8314, {0x03, 0x80}}, {8365, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8466, {0x03, 0x80}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8264, {0x00, 0x00}}, {8314, {0x00, 0x00}}, {8365, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8466, {0x00, 0x00}} }}                            
   }                                                                            
};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand8_Set2 = 
{
   /* Event */
   {
    /* No.           elm type , data idx       , evt_type       , evt_offset     */
    /*                           { start, stop },                  ( us )         */
     { /* 0, Prf_7  */ UL1_MIPI_PA, { 0    , 3     }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*highest power*/
     { /* 1, Prf_6  */ UL1_MIPI_PA, { 4    , 7     }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 2, Prf_5  */ UL1_MIPI_PA, { 8    , 11    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 3, Prf_4  */ UL1_MIPI_PA, { 12   , 15    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 4, Prf_3  */ UL1_MIPI_PA, { 16   , 19    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 5, Prf_2  */ UL1_MIPI_PA, { 20   , 23    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 6, Prf_1  */ UL1_MIPI_PA, { 24   , 27    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 7, Prf_0  */ UL1_MIPI_PA, { 28   , 31    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*lowest power*/
   },
   
   /* Data */
   {                                                                                                                                                                               
      //elm type  , port_sel     , data_seq, user id,         {{sub 0, addr, data}}, {{sub 1, addr, data}}, {{sub 2, addr, data} , {{sub 3, addr, data}}, {{sub 4, addr, data}     
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x00, 0x9C}}, {8899, {0x00, 0x9C}}, {8975, {0x00, 0x9C}}, {9050, {0x00, 0x9C}}, {9126, {0x00, 0x9C}} }},  /*L7, TPC IDX 0*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x01, 0x58}}, {8899, {0x01, 0x58}}, {8975, {0x01, 0x58}}, {9050, {0x01, 0x58}}, {9126, {0x01, 0x58}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x02, 0x00}}, {8899, {0x02, 0x00}}, {8975, {0x02, 0x00}}, {9050, {0x02, 0x00}}, {9126, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x03, 0x89}}, {8899, {0x03, 0x89}}, {8975, {0x03, 0x89}}, {9050, {0x03, 0x89}}, {9126, {0x03, 0x89}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x00, 0x9C}}, {8899, {0x00, 0x9C}}, {8975, {0x00, 0x9C}}, {9050, {0x00, 0x9C}}, {9126, {0x00, 0x9C}} }},  /*L6, TPC IDX 2*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x01, 0x58}}, {8899, {0x01, 0x58}}, {8975, {0x01, 0x58}}, {9050, {0x01, 0x58}}, {9126, {0x01, 0x58}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x02, 0x00}}, {8899, {0x02, 0x00}}, {8975, {0x02, 0x00}}, {9050, {0x02, 0x00}}, {9126, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x03, 0x89}}, {8899, {0x03, 0x89}}, {8975, {0x03, 0x89}}, {9050, {0x03, 0x89}}, {9126, {0x03, 0x89}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x00, 0x9C}}, {8899, {0x00, 0x9C}}, {8975, {0x00, 0x9C}}, {9050, {0x00, 0x9C}}, {9126, {0x00, 0x9C}} }},  /*L5, TPC IDX 4*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x01, 0x58}}, {8899, {0x01, 0x58}}, {8975, {0x01, 0x58}}, {9050, {0x01, 0x58}}, {9126, {0x01, 0x58}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x02, 0x00}}, {8899, {0x02, 0x00}}, {8975, {0x02, 0x00}}, {9050, {0x02, 0x00}}, {9126, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x03, 0x89}}, {8899, {0x03, 0x89}}, {8975, {0x03, 0x89}}, {9050, {0x03, 0x89}}, {9126, {0x03, 0x89}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x00, 0x9C}}, {8899, {0x00, 0x9C}}, {8975, {0x00, 0x9C}}, {9050, {0x00, 0x9C}}, {9126, {0x00, 0x9C}} }},  /*L4, TPC IDX 6*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x01, 0x35}}, {8899, {0x01, 0x35}}, {8975, {0x01, 0x35}}, {9050, {0x01, 0x35}}, {9126, {0x01, 0x35}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x02, 0x00}}, {8899, {0x02, 0x00}}, {8975, {0x02, 0x00}}, {9050, {0x02, 0x00}}, {9126, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x03, 0x80}}, {8899, {0x03, 0x80}}, {8975, {0x03, 0x80}}, {9050, {0x03, 0x80}}, {9126, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x00, 0x9C}}, {8899, {0x00, 0x9C}}, {8975, {0x00, 0x9C}}, {9050, {0x00, 0x9C}}, {9126, {0x00, 0x9C}} }},  /*L3, TPC IDX 9*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x01, 0x35}}, {8899, {0x01, 0x35}}, {8975, {0x01, 0x35}}, {9050, {0x01, 0x35}}, {9126, {0x01, 0x35}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x02, 0x00}}, {8899, {0x02, 0x00}}, {8975, {0x02, 0x00}}, {9050, {0x02, 0x00}}, {9126, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x03, 0x80}}, {8899, {0x03, 0x80}}, {8975, {0x03, 0x80}}, {9050, {0x03, 0x80}}, {9126, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x00, 0x9C}}, {8899, {0x00, 0x9C}}, {8975, {0x00, 0x9C}}, {9050, {0x00, 0x9C}}, {9126, {0x00, 0x9C}} }},  /*L2, TPC IDX 15, Hyst1*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x01, 0x25}}, {8899, {0x01, 0x25}}, {8975, {0x01, 0x25}}, {9050, {0x01, 0x25}}, {9126, {0x01, 0x25}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x02, 0x00}}, {8899, {0x02, 0x00}}, {8975, {0x02, 0x00}}, {9050, {0x02, 0x00}}, {9126, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x03, 0x80}}, {8899, {0x03, 0x80}}, {8975, {0x03, 0x80}}, {9050, {0x03, 0x80}}, {9126, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x00, 0x9C}}, {8899, {0x00, 0x9C}}, {8975, {0x00, 0x9C}}, {9050, {0x00, 0x9C}}, {9126, {0x00, 0x9C}} }},  /*L1, TPC IDX 18*/       
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x01, 0x33}}, {8899, {0x01, 0x33}}, {8975, {0x01, 0x33}}, {9050, {0x01, 0x33}}, {9126, {0x01, 0x33}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x02, 0x00}}, {8899, {0x02, 0x00}}, {8975, {0x02, 0x00}}, {9050, {0x02, 0x00}}, {9126, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x03, 0x80}}, {8899, {0x03, 0x80}}, {8975, {0x03, 0x80}}, {9050, {0x03, 0x80}}, {9126, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x00, 0x9C}}, {8899, {0x00, 0x9C}}, {8975, {0x00, 0x9C}}, {9050, {0x00, 0x9C}}, {9126, {0x00, 0x9C}} }},  /*L0, TPC IDX 25, Hyst2*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x01, 0x13}}, {8899, {0x01, 0x13}}, {8975, {0x01, 0x13}}, {9050, {0x01, 0x13}}, {9126, {0x01, 0x13}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x02, 0x00}}, {8899, {0x02, 0x00}}, {8975, {0x02, 0x00}}, {9050, {0x02, 0x00}}, {9126, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8824, {0x03, 0x80}}, {8899, {0x03, 0x80}}, {8975, {0x03, 0x80}}, {9050, {0x03, 0x80}}, {9126, {0x03, 0x80}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8824, {0x00, 0x00}}, {8899, {0x00, 0x00}}, {8975, {0x00, 0x00}}, {9050, {0x00, 0x00}}, {9126, {0x00, 0x00}} }}                            
   }                                                                          
};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand19_Set2 = 
{
   /* Event */
   {
    /* No.           elm type , data idx       , evt_type       , evt_offset     */
    /*                           { start, stop },                  ( us )         */
     { /* 0, Prf_7  */ UL1_MIPI_PA, { 0    , 3     }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*highest power*/
     { /* 1, Prf_6  */ UL1_MIPI_PA, { 4    , 7     }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 2, Prf_5  */ UL1_MIPI_PA, { 8    , 11    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 3, Prf_4  */ UL1_MIPI_PA, { 12   , 15    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 4, Prf_3  */ UL1_MIPI_PA, { 16   , 19    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 5, Prf_2  */ UL1_MIPI_PA, { 20   , 23    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 6, Prf_1  */ UL1_MIPI_PA, { 24   , 27    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },
     { /* 7, Prf_0  */ UL1_MIPI_PA, { 28   , 31    }, UL1_MIPI_TPC_SET   , US2CHIPCNT(20)  },  /*lowest power*/
   },
   
   /* Data */
   {                                                                                                                                                                               
      //elm type  , port_sel     , data_seq, user id,         {{sub 0, addr, data}}, {{sub 1, addr, data}}, {{sub 2, addr, data} , {{sub 3, addr, data}}, {{sub 4, addr, data}     
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x00, 0x8D}}, {8354, {0x00, 0x8D}}, {8384, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8426, {0x00, 0x8D}} }},  /*L7, TPC IDX 0*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x01, 0x77}}, {8354, {0x01, 0x77}}, {8384, {0x01, 0x77}}, {8415, {0x01, 0x77}}, {8426, {0x01, 0x77}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x02, 0x00}}, {8354, {0x02, 0x00}}, {8384, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8426, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x03, 0x89}}, {8354, {0x03, 0x89}}, {8384, {0x03, 0x89}}, {8415, {0x03, 0x89}}, {8426, {0x03, 0x89}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x00, 0x8D}}, {8354, {0x00, 0x8D}}, {8384, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8426, {0x00, 0x8D}} }},  /*L6, TPC IDX 2*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x01, 0x66}}, {8354, {0x01, 0x66}}, {8384, {0x01, 0x66}}, {8415, {0x01, 0x66}}, {8426, {0x01, 0x66}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x02, 0x00}}, {8354, {0x02, 0x00}}, {8384, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8426, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x03, 0x89}}, {8354, {0x03, 0x89}}, {8384, {0x03, 0x89}}, {8415, {0x03, 0x89}}, {8426, {0x03, 0x89}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x00, 0x8D}}, {8354, {0x00, 0x8D}}, {8384, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8426, {0x00, 0x8D}} }},  /*L5, TPC IDX 4*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x01, 0x55}}, {8354, {0x01, 0x55}}, {8384, {0x01, 0x55}}, {8415, {0x01, 0x55}}, {8426, {0x01, 0x55}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x02, 0x00}}, {8354, {0x02, 0x00}}, {8384, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8426, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x03, 0x89}}, {8354, {0x03, 0x89}}, {8384, {0x03, 0x89}}, {8415, {0x03, 0x89}}, {8426, {0x03, 0x89}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x00, 0x8D}}, {8354, {0x00, 0x8D}}, {8384, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8426, {0x00, 0x8D}} }},  /*L4, TPC IDX 6*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x01, 0x44}}, {8354, {0x01, 0x44}}, {8384, {0x01, 0x44}}, {8415, {0x01, 0x44}}, {8426, {0x01, 0x44}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x02, 0x00}}, {8354, {0x02, 0x00}}, {8384, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8426, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x03, 0x80}}, {8354, {0x03, 0x80}}, {8384, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8426, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x00, 0x8D}}, {8354, {0x00, 0x8D}}, {8384, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8426, {0x00, 0x8D}} }},  /*L3, TPC IDX 9*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x01, 0x34}}, {8354, {0x01, 0x34}}, {8384, {0x01, 0x34}}, {8415, {0x01, 0x34}}, {8426, {0x01, 0x34}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x02, 0x00}}, {8354, {0x02, 0x00}}, {8384, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8426, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x03, 0x80}}, {8354, {0x03, 0x80}}, {8384, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8426, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x00, 0x8D}}, {8354, {0x00, 0x8D}}, {8384, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8426, {0x00, 0x8D}} }},  /*L2, TPC IDX 15, Hyst1*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x01, 0x24}}, {8354, {0x01, 0x24}}, {8384, {0x01, 0x24}}, {8415, {0x01, 0x24}}, {8426, {0x01, 0x24}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x02, 0x00}}, {8354, {0x02, 0x00}}, {8384, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8426, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x03, 0x80}}, {8354, {0x03, 0x80}}, {8384, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8426, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x00, 0x8D}}, {8354, {0x00, 0x8D}}, {8384, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8426, {0x00, 0x8D}} }},  /*L1, TPC IDX 18*/       
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x01, 0x23}}, {8354, {0x01, 0x23}}, {8384, {0x01, 0x23}}, {8415, {0x01, 0x23}}, {8426, {0x01, 0x23}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x02, 0x00}}, {8354, {0x02, 0x00}}, {8384, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8426, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x03, 0x80}}, {8354, {0x03, 0x80}}, {8384, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8426, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x00, 0x8D}}, {8354, {0x00, 0x8D}}, {8384, {0x00, 0x8D}}, {8415, {0x00, 0x8D}}, {8426, {0x00, 0x8D}} }},  /*L0, TPC IDX 25, Hyst2*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x01, 0x22}}, {8354, {0x01, 0x22}}, {8384, {0x01, 0x22}}, {8415, {0x01, 0x22}}, {8426, {0x01, 0x22}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x02, 0x00}}, {8354, {0x02, 0x00}}, {8384, {0x02, 0x00}}, {8415, {0x02, 0x00}}, {8426, {0x02, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT1 , UL1_REG_W ,   MIPI_USID_PA1_P3,   {{8324, {0x03, 0x80}}, {8354, {0x03, 0x80}}, {8384, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8426, {0x03, 0x80}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8324, {0x00, 0x00}}, {8354, {0x00, 0x00}}, {8384, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8426, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8324, {0x00, 0x00}}, {8354, {0x00, 0x00}}, {8384, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8426, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8324, {0x00, 0x00}}, {8354, {0x00, 0x00}}, {8384, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8426, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8324, {0x00, 0x00}}, {8354, {0x00, 0x00}}, {8384, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8426, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8324, {0x00, 0x00}}, {8354, {0x00, 0x00}}, {8384, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8426, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8324, {0x00, 0x00}}, {8354, {0x00, 0x00}}, {8384, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8426, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8324, {0x00, 0x00}}, {8354, {0x00, 0x00}}, {8384, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8426, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{8324, {0x00, 0x00}}, {8354, {0x00, 0x00}}, {8384, {0x00, 0x00}}, {8415, {0x00, 0x00}}, {8426, {0x00, 0x00}} }}                            
   }                                                                            
};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand2_Set2 = {{{0}}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand4_Set2 = {{{0}}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand3_Set2  = {{{0}}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand6_Set2  = {{{0}}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand9_Set2  = {{{0}}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand11_Set2 = {{{0}}};


UL1_UMTS_MIPI_TPC_T* UMTS_MIPI_TPC_TABLE_Set2[] =
{
   M_UMTS_TPC(UMTSBandNone,Set2),                     /*UMTSUMTSBandNone*/          
   M_UMTS_TPC(RX_BAND_INDICATOR_0_Set2,Set2),   /*RX_BAND_INDICATOR_0_Set2*/
   M_UMTS_TPC(RX_BAND_INDICATOR_1_Set2,Set2),   /*RX_BAND_INDICATOR_1_Set2*/
   M_UMTS_TPC(RX_BAND_INDICATOR_2_Set2,Set2),   /*RX_BAND_INDICATOR_2_Set2*/
   M_UMTS_TPC(RX_BAND_INDICATOR_3_Set2,Set2),   /*RX_BAND_INDICATOR_3_Set2 */ 
   M_UMTS_TPC(RX_BAND_INDICATOR_4_Set2,Set2),   /*RX_BAND_INDICATOR_4_Set2 */ 
};

#if (IS_3G_ET_SUPPORT)
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ET_ON_STATIC_CW_Set2[ET_MAX_ON_IMM_BSI_CW_NUM] =
{
   //elm type, port_sel        , data_seq, usid        , {addr, data}
   {UL1_MIPI_END, 0, 0, 0,{0,0}}
};

UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ET_OFF_STATIC_CW_Set2[ET_MAX_OFF_IMM_BSI_CW_NUM] =
{
   //elm type, port_sel        , data_seq, usid        , {addr, data}
   {UL1_MIPI_END, 0, 0, 0,{0,0}}
};


UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBandNone_Set2 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand1_Set2 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand2_Set2 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand4_Set2 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand5_Set2 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand8_Set2 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand3_Set2  =  {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand6_Set2  =  {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand9_Set2  =  {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand11_Set2 =  {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand19_Set2 =  {{{0}}};

UL1_MIPI_EVENT_TABLE_T*  UMTS_MIPI_ET_EVENT_TABLE_Set2[] =
{
   M_UMTS_ET_EVENT(UMTSBandNone,Set2),                     /*UMTSUMTSBandNone*/
   M_UMTS_ET_EVENT(RX_BAND_INDICATOR_0_Set2,Set2),   /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_ET_EVENT(RX_BAND_INDICATOR_1_Set2,Set2),   /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_ET_EVENT(RX_BAND_INDICATOR_2_Set2,Set2),   /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_ET_EVENT(RX_BAND_INDICATOR_3_Set2,Set2),   /*RX_LOWBAND1_INDICATOR */
   M_UMTS_ET_EVENT(RX_BAND_INDICATOR_4_Set2,Set2),   /*RX_LOWBAND2_INDICATOR */
};

UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_ET_DATA_TABLE_Set2[] =
{
   M_UMTS_ET_DATA(UMTSBandNone,Set2),                      /*UMTSUMTSBandNone*/
   M_UMTS_ET_DATA(RX_BAND_INDICATOR_0_Set2,Set2),    /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_ET_DATA(RX_BAND_INDICATOR_1_Set2,Set2),    /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_ET_DATA(RX_BAND_INDICATOR_2_Set2,Set2),    /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_ET_DATA(RX_BAND_INDICATOR_3_Set2,Set2),    /*RX_LOWBAND1_INDICATOR */
   M_UMTS_ET_DATA(RX_BAND_INDICATOR_4_Set2,Set2),    /*RX_LOWBAND2_INDICATOR */
};

UL1_UMTS_MIPI_ET_T* UMTS_MIPI_ET_TABLE_Set2[] =
{
   M_UMTS_ET(UMTSBandNone,Set2),                           /*UMTSUMTSBandNone*/
   M_UMTS_ET(RX_BAND_INDICATOR_0_Set2,Set2),         /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_ET(RX_BAND_INDICATOR_1_Set2,Set2),         /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_ET(RX_BAND_INDICATOR_2_Set2,Set2),         /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_ET(RX_BAND_INDICATOR_3_Set2,Set2),         /*RX_LOWBAND1_INDICATOR */
   M_UMTS_ET(RX_BAND_INDICATOR_4_Set2,Set2),         /*RX_LOWBAND2_INDICATOR */
};


#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBandNone_Set2 = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand1_Set2    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand2_Set2    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand3_Set2    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand4_Set2    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand5_Set2    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand6_Set2    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand8_Set2    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand9_Set2    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand11_Set2   = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand19_Set2   = ET_VPA_SOURCE_NOT_SUPPORTED;

UMTS_VPA_SOURCE_TYPE* UMTS_VPA_SRC_SEL_TABLE_Set2[] =
{
   M_UMTS_VPA_SRC(UMTSBandNone,Set2),                    /*UMTSUMTSBandNone*/
   M_UMTS_VPA_SRC(RX_BAND_INDICATOR_0_Set2,Set2),  /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_VPA_SRC(RX_BAND_INDICATOR_1_Set2,Set2),  /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_VPA_SRC(RX_BAND_INDICATOR_2_Set2,Set2),  /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_VPA_SRC(RX_BAND_INDICATOR_3_Set2,Set2),  /*RX_LOWBAND1_INDICATOR*/
   M_UMTS_VPA_SRC(RX_BAND_INDICATOR_4_Set2,Set2),  /*RX_LOWBAND2_INDICATOR*/
};

#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

UL1_UMTS_MIPI_ET_PARAM_T UL1_ET_PARAM_Set2 = 
{
   { /*mult, div*/
      {10, 409},  //LV1
   },

   {/* DAC2=3b'000,  001,  010,  011,  100,  101,  110,  111 */
              0x0B, 0x0B, 0x0B, 0x0B, 0x0A, 0x0A, 0x0B, 0x0B
   },

};


#endif/*IS_3G_ET_SUPPORT*/


/*special handle for T/Rx calibration, we should force ASM to isolation mode */
/*Users just need to provide the ASM isolation CW, DSP may use immediate mode*/
/*to control the MIPI ASM                                                    */
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBandNone_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand1_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand2_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand4_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand5_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand8_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand3_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand6_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand9_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand11_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand19_Set2[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};

UL1_MIPI_DATA_TABLE_T* UMTS_MIPI_ASM_ISOLATION_DATA_TABLE_Set2[] = 
{
   M_UMTS_ASM_ISO(UMTSBandNone,Set2),                        /*UMTSUMTSBandNone*/          
   M_UMTS_ASM_ISO(RX_BAND_INDICATOR_0_Set2,Set2),      /*RX_BAND_INDICATOR_0_Set2*/  
   M_UMTS_ASM_ISO(RX_BAND_INDICATOR_1_Set2,Set2),      /*RX_BAND_INDICATOR_1_Set2*/  
   M_UMTS_ASM_ISO(RX_BAND_INDICATOR_2_Set2,Set2),      /*RX_BAND_INDICATOR_2_Set2*/  
   M_UMTS_ASM_ISO(RX_BAND_INDICATOR_3_Set2,Set2),      /*RX_BAND_INDICATOR_3_Set2*/   
   M_UMTS_ASM_ISO(RX_BAND_INDICATOR_4_Set2,Set2),      /*RX_BAND_INDICATOR_4_Set2*/   
};

/////////////////////////////////////////////

#endif

