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

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBandNone_Set0[UL1_MIPI_RX_EVENT_NUM] = 
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


UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand1_Set0[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_ASM,  { 0    , 1    }, UL1_MIPI_TRX_ON, US2CHIPCNT(200)     },
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
   { /* 16 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 17 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 18 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 19 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 20 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 21 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 22 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 23 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};


UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand2_Set0[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_ASM,  { 0    , 1    }, UL1_MIPI_TRX_ON, US2CHIPCNT(200)     },
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
   { /* 16 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 17 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 18 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 19 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 20 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 21 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 22 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 23 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand4_Set0[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_ASM,  { 0    , 1    }, UL1_MIPI_TRX_ON, US2CHIPCNT(200)     },
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
   { /* 16 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 17 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 18 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 19 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 20 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 21 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 22 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 23 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};


UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand5_Set0[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_ASM,  { 0    , 1    }, UL1_MIPI_TRX_ON, US2CHIPCNT(200)     },
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
   { /* 16 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 17 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 18 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 19 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 20 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 21 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 22 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 23 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand8_Set0[UL1_MIPI_RX_EVENT_NUM] = 
{
   /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                    { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_ASM,  { 0    , 1    }, UL1_MIPI_TRX_ON, US2CHIPCNT(200)     },
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
   { /* 16 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 17 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 18 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 19 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 20 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 21 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 22 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
   { /* 23 */ UL1_MIPI_NULL, { 0    , 0    }, UL1_MIPI_EVENT_NULL, 0              },
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand3_Set0[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand6_Set0[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand9_Set0[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand11_Set0[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTSBand19_Set0[] = {{0}};

UL1_MIPI_EVENT_TABLE_T*  UMTS_MIPI_RX_EVENT_TABLE_Set0[] =
{
   M_UMTS_RX_EVENT(UMTSBandNone, Set0),          /*UMTSBandNone*/          
   M_UMTS_RX_EVENT(RX_BAND_INDICATOR_0_Set0, Set0),   /*UMTS_Route0*/
   M_UMTS_RX_EVENT(RX_BAND_INDICATOR_1_Set0, Set0),   /*UMTS_Route1*/
   M_UMTS_RX_EVENT(RX_BAND_INDICATOR_2_Set0, Set0),   /*UMTS_Route2*/   
   M_UMTS_RX_EVENT(RX_BAND_INDICATOR_3_Set0, Set0),   /*UMTS_Route3*/   
   M_UMTS_RX_EVENT(RX_BAND_INDICATOR_4_Set0, Set0),   /*UMTS_Route4*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_5, Set0),   /*UMTS_Route5*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_6, Set0),   /*UMTS_Route6*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_7, Set0),   /*UMTS_Route7*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_8, Set0),   /*UMTS_Route8*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_9, Set0),   /*UMTS_Route9*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_10, Set0),  /*UMTS_Route10*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_11, Set0),  /*UMTS_Route11*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_12, Set0),  /*UMTS_Route12*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_13, Set0),  /*UMTS_Route13*/
   M_UMTS_RX_EVENT(MIPI_RX_ROUTE_IND_14, Set0),  /*UMTS_Route14*/
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBandNone_Set0[UL1_MIPI_RX_DATA_NUM] = 
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

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand1_Set0[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM0, { { 21124 ,{0x1C, 0x38}}, { 21262 ,{0x1C, 0x38}}, { 21400 ,{0x1C, 0x38}}, { 21538  ,{0x1C, 0x38}}, { 21676 ,{0x1C, 0x38}}} },
   { /* 1  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM0, { { 21124 ,{0x00, 0x01}}, { 21262 ,{0x00, 0x01}}, { 21400 ,{0x00, 0x01}}, { 21538  ,{0x00, 0x01}}, { 21676 ,{0x00, 0x01}}} },
   { /* 2  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 3  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 4  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 5  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 6  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0,{ { 21124 ,{0x0,  0x0}},  { 21262 ,{0x0,  0x0}},   { 21400 ,{0x0, 0x0}},   { 21538  ,{0x0, 0x0}},   { 21676 ,{0x0,  0x0}}} },
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

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand2_Set0[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM0,  { { 19324 ,{0x1C, 0x38}}, { 19462 ,{0x1C, 0x38}}, { 19600 ,{0x1C, 0x38}}, { 19738  ,{0x1C, 0x38}}, { 19876 ,{0x1C, 0x38}}} },
   { /* 1  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM0,  { { 19324 ,{0x00, 0x04}}, { 19462 ,{0x00, 0x04}}, { 19600 ,{0x00, 0x04}}, { 19738  ,{0x00, 0x04}}, { 19876 ,{0x00, 0x04}}} },
   { /* 2  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 3  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 4  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 5  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 6  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 18 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 19 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 20 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 21 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 22 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 23 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 24 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 25 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 26 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
   { /* 27 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 19324 ,{0x0, 0x0}},   { 19462 ,{0x0, 0x0}},   { 19600 ,{0x0, 0x0}},   { 19738  ,{0x0, 0x0}},   { 19876 ,{0x0,  0x0}} } },
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand4_Set0[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM0,  { { 21124 ,{0x1C, 0x38}}, { 21227 ,{0x1C, 0x38}}, { 21330 ,{0x1C, 0x38}}, { 21428  ,{0x1C, 0x38}}, { 21526 ,{0x1C, 0x38}}} },
   { /* 1  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM0,  { { 21124 ,{0x00, 0x01}}, { 21227 ,{0x00, 0x01}}, { 21330 ,{0x00, 0x01}}, { 21428  ,{0x00, 0x01}}, { 21526 ,{0x00, 0x01}}} },
   { /* 2  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM2,  { { 21124 ,{0x1C, 0x38}}, { 21227 ,{0x1C, 0x38}}, { 21330 ,{0x1C, 0x38}}, { 21428  ,{0x1C, 0x38}}, { 21526 ,{0x1C, 0x38}}} },
   { /* 3  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM2,  { { 21124 ,{0x00, 0x02}}, { 21227 ,{0x00, 0x02}}, { 21330 ,{0x00, 0x02}}, { 21428  ,{0x00, 0x02}}, { 21526 ,{0x00, 0x02}}} },
   { /* 4  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 5  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 6  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 18 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 19 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 20 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 21 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 22 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 23 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 24 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 25 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 26 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },
   { /* 27 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 21124 ,{0x0, 0x0}},   { 21227 ,{0x0, 0x0}},   { 21330 ,{0x0, 0x0}},   { 21428  ,{0x0, 0x0}},   { 21526 ,{0x0,   0x0}}} },

};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand5_Set0[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM0,  { { 8714 ,{0x1C, 0x38}}, { 8764 ,{0x1C, 0x38}},   { 8815 ,{0x1C, 0x38}},  { 8865  ,{0x1C, 0x38}},   { 8916 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM0,  { { 8714 ,{0x00, 0x03}}, { 8764 ,{0x00, 0x03}},   { 8815 ,{0x00, 0x03}},  { 8865  ,{0x00, 0x03}},   { 8916 ,{0x00, 0x03}} }},
   { /* 2  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 3  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 4  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 5  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 6  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 8714 ,{0x0, 0x0}},   { 8764 ,{0x0, 0x0}},     { 8815 ,{0x0, 0x0}},    { 8865  ,{0x0, 0x0}},     { 8916 ,{0x0,   0x0}} }},
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


UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand8_Set0[UL1_MIPI_RX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data  }}, { sub 4, addr data  } }},
   { /* 0  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM0,  { { 9274 ,{0x1C, 0x38}}, { 9349 ,{0x1C, 0x38}},   { 9425 ,{0x1C, 0x38}},  { 9500  ,{0x1C, 0x38}},   { 9576 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_ASM,  UL1_MIPI_PORT3,  UL1_REG_W     , MIPI_USID_ASM0,  { { 9274 ,{0x00, 0x10}}, { 9349 ,{0x00, 0x10}},   { 9425 ,{0x00, 0x10}},  { 9500  ,{0x00, 0x10}},   { 9576 ,{0x00, 0x10}} }},
   { /* 2  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 3  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 4  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 5  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 6  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL,  UL1_SEQ_NULL  , MIPI_USID_INIT0, { { 9274 ,{0x0, 0x0}},   { 9349 ,{0x0, 0x0}},     { 9425 ,{0x0, 0x0}},    { 9500  ,{0x0, 0x0}},     { 9576 ,{0x0,   0x0}} }},
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

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand3_Set0[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand6_Set0[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand9_Set0[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand11_Set0[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTSBand19_Set0[] = {{0}};

UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_RX_DATA_TABLE_Set0[] = 
{
   M_UMTS_RX_DATA(UMTSBandNone,Set0),          /*UMTSBandNone*/          
   M_UMTS_RX_DATA(RX_BAND_INDICATOR_0_Set0,Set0),   /*UMTS_Route0*/
   M_UMTS_RX_DATA(RX_BAND_INDICATOR_1_Set0,Set0),   /*UMTS_Route1*/
   M_UMTS_RX_DATA(RX_BAND_INDICATOR_2_Set0,Set0),   /*UMTS_Route2*/
   M_UMTS_RX_DATA(RX_BAND_INDICATOR_3_Set0,Set0),   /*UMTS_Route3*/ 
   M_UMTS_RX_DATA(RX_BAND_INDICATOR_4_Set0,Set0),   /*UMTS_Route4*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_5,Set0),   /*UMTS_Route5*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_6,Set0),   /*UMTS_Route6*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_7,Set0),   /*UMTS_Route7*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_8,Set0),   /*UMTS_Route8*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_9,Set0),   /*UMTS_Route9*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_10,Set0),  /*UMTS_Route10*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_11,Set0),  /*UMTS_Route11*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_12,Set0),  /*UMTS_Route12*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_13,Set0),  /*UMTS_Route13*/
   M_UMTS_RX_DATA(MIPI_RX_ROUTE_IND_14,Set0),  /*UMTS_Route14*/
};

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBandNone_Set0[UL1_MIPI_TX_EVENT_NUM] = 
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

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand1_Set0[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_PA,   { 0    , 0   }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ UL1_MIPI_PA,   { 1    , 4   }, UL1_MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ UL1_MIPI_ASM,  { 5    , 6    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200) },
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

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand2_Set0[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_PA,   { 0    , 0    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ UL1_MIPI_PA,   { 1    , 4    }, UL1_MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ UL1_MIPI_ASM,  { 5    , 6    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200) },
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

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand4_Set0[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_PA,   { 0    , 0   }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ UL1_MIPI_PA,   { 1    , 4   }, UL1_MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ UL1_MIPI_ASM,  { 5    , 6   }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200) },
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


UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand5_Set0[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_PA,   { 0    , 0    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ UL1_MIPI_PA,   { 1    , 4    }, UL1_MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ UL1_MIPI_ASM,  { 5    , 6    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200) },
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

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand8_Set0[UL1_MIPI_TX_EVENT_NUM] = 
{
	 /* No.     elm type , data idx       , evt_type       , evt_offset     */
   /*                     { start, stop },                  ( us )         */
   { /* 0  */ UL1_MIPI_PA,   { 0    , 0    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200)  },
   { /* 1  */ UL1_MIPI_PA,   { 1    , 4    }, UL1_MIPI_TRX_OFF,    US2CHIPCNT(10)  },
   { /* 2  */ UL1_MIPI_ASM,  { 5    , 6    }, UL1_MIPI_TRX_ON,     US2CHIPCNT(200) },
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

UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand3_Set0[]  = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand6_Set0[]  = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand9_Set0[]  = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand11_Set0[] = {{0}};
UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_TX_EVENT_UMTSBand19_Set0[] = {{0}};

UL1_MIPI_EVENT_TABLE_T*  UMTS_MIPI_TX_EVENT_TABLE_Set0[] =
{
   M_UMTS_TX_EVENT(UMTSBandNone,Set0),                       /*UMTSUMTSBandNone*/          
   M_UMTS_TX_EVENT(RX_BAND_INDICATOR_0_Set0,Set0),     /*RX_BAND_INDICATOR_0_Set0*/
   M_UMTS_TX_EVENT(RX_BAND_INDICATOR_1_Set0,Set0),     /*RX_BAND_INDICATOR_1_Set0*/
   M_UMTS_TX_EVENT(RX_BAND_INDICATOR_2_Set0,Set0),     /*RX_BAND_INDICATOR_2_Set0*/
   M_UMTS_TX_EVENT(RX_BAND_INDICATOR_3_Set0,Set0),     /*RX_BAND_INDICATOR_3_Set0*/ 
   M_UMTS_TX_EVENT(RX_BAND_INDICATOR_4_Set0,Set0),     /*RX_BAND_INDICATOR_4_Set0*/ 
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBandNone_Set0[UL1_MIPI_TX_DATA_NUM] = 
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

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand1_Set0[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},
   { /* 1  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 2  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 19224 ,{0x01, 0x00}}, { 19362 ,{0x01, 0x00}}, { 19500 ,{0x01, 0x00}}, { 19638 ,{0x01, 0x00}}, { 19776 ,{0x01, 0x00}}}},
   { /* 3  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 19224 ,{0x02, 0x00}}, { 19362 ,{0x02, 0x00}}, { 19500 ,{0x02, 0x00}}, { 19638 ,{0x02, 0x00}}, { 19776 ,{0x02, 0x00}}}},
   { /* 4  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 19224 ,{0x03, 0x00}}, { 19362 ,{0x03, 0x00}}, { 19500 ,{0x03, 0x00}}, { 19638 ,{0x03, 0x00}}, { 19776 ,{0x03, 0x00}}}},
   { /* 5  */ UL1_MIPI_ASM , UL1_MIPI_PORT3, UL1_REG_W  ,    MIPI_USID_ASM0   , { { 19224 ,{0x1C, 0x38}}, { 19362 ,{0x1C, 0x38}}, { 19500 ,{0x1C, 0x38}}, { 19638 ,{0x1C, 0x38}}, { 19776 ,{0x1C, 0x38}}}},
   { /* 6  */ UL1_MIPI_ASM , UL1_MIPI_PORT3, UL1_REG_W  ,    MIPI_USID_ASM0   , { { 19224 ,{0x00, 0x01}}, { 19362 ,{0x00, 0x01}}, { 19500 ,{0x00, 0x01}}, { 19638 ,{0x00, 0x01}}, { 19776 ,{0x00, 0x01}}}},
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 19224 ,{0x00, 0x00}}, { 19362 ,{0x00, 0x00}}, { 19500 ,{0x00, 0x00}}, { 19638 ,{0x00, 0x00}}, { 19776 ,{0x00, 0x00}}}},
};


UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand2_Set0[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 18524 ,{0x1C, 0x38}}, { 18662 ,{0x1C, 0x38}}, { 18800 ,{0x1C, 0x38}}, { 18938 ,{0x1C, 0x38}}, { 19076 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 2  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 18524 ,{0x01, 0x00}}, { 18662 ,{0x01, 0x00}}, { 18800 ,{0x01, 0x00}}, { 18938 ,{0x01, 0x00}}, { 19076 ,{0x01, 0x00}} }},
   { /* 3  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 18524 ,{0x02, 0x00}}, { 18662 ,{0x02, 0x00}}, { 18800 ,{0x02, 0x00}}, { 18938 ,{0x02, 0x00}}, { 19076 ,{0x02, 0x00}} }},
   { /* 4  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 18524 ,{0x03, 0x00}}, { 18662 ,{0x03, 0x00}}, { 18800 ,{0x03, 0x00}}, { 18938 ,{0x03, 0x00}}, { 19076 ,{0x03, 0x00}} }},
   { /* 5  */ UL1_MIPI_ASM , UL1_MIPI_PORT3, UL1_REG_W  ,    MIPI_USID_ASM0   , { { 18524 ,{0x1C, 0x38}}, { 18662 ,{0x1C, 0x38}}, { 18800 ,{0x1C, 0x38}}, { 18938 ,{0x1C, 0x38}}, { 19076 ,{0x1C, 0x38}} }},
   { /* 6  */ UL1_MIPI_ASM , UL1_MIPI_PORT3, UL1_REG_W  ,    MIPI_USID_ASM0   , { { 18524 ,{0x00, 0x04}}, { 18662 ,{0x00, 0x04}}, { 18800 ,{0x00, 0x04}}, { 18938 ,{0x00, 0x04}}, { 19076 ,{0x00, 0x04}} }},
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,    MIPI_USID_INIT0, { { 18524 ,{0x010, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 18524 ,{0x00, 0x00}}, { 18662 ,{0x00, 0x00}}, { 18800 ,{0x00, 0x00}}, { 18938 ,{0x00, 0x00}}, { 19076 ,{0x00, 0x00}} }},
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand4_Set0[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 17124 ,{0x1C, 0x38}}, { 17224 ,{0x1C, 0x38}}, { 17324 ,{0x1C, 0x38}}, { 17425 ,{0x1C, 0x38}}, { 17526 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 2  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 3  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 4  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 5  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0   , { { 17124 ,{0x1C, 0x38}}, { 17224 ,{0x1C, 0x38}}, { 17324 ,{0x1C, 0x38}}, { 17425 ,{0x1C, 0x38}}, { 17526 ,{0x1C, 0x38}} }},
   { /* 6  */ UL1_MIPI_ASM , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_ASM0   , { { 17124 ,{0x00, 0x04}}, { 17224 ,{0x00, 0x04}}, { 17324 ,{0x00, 0x04}}, { 17425 ,{0x00, 0x04}}, { 17526 ,{0x00, 0x04}} }},
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 17124 ,{0x00, 0x00}}, { 17224 ,{0x00, 0x00}}, { 17324 ,{0x00, 0x00}}, { 17425 ,{0x00, 0x00}}, { 17526 ,{0x00, 0x00}} }},
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand5_Set0[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 2  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 8264 ,{0x01, 0x00}}, { 8314 ,{0x01, 0x00}}, { 8365 ,{0x01, 0x00}}, { 8415 ,{0x01, 0x00}}, { 8466 ,{0x01, 0x00}} }},
   { /* 3  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 8264 ,{0x02, 0x00}}, { 8314 ,{0x02, 0x00}}, { 8365 ,{0x02, 0x00}}, { 8415 ,{0x02, 0x00}}, { 8466 ,{0x02, 0x00}} }},
   { /* 4  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 8264 ,{0x03, 0x00}}, { 8314 ,{0x03, 0x00}}, { 8365 ,{0x03, 0x00}}, { 8415 ,{0x03, 0x00}}, { 8466 ,{0x03, 0x00}} }},
   { /* 5  */ UL1_MIPI_ASM , UL1_MIPI_PORT3, UL1_REG_W  ,    MIPI_USID_ASM0    , { { 8264 ,{0x1C, 0x38}}, { 8314 ,{0x1C, 0x38}}, { 8365 ,{0x1C, 0x38}}, { 8415 ,{0x1C, 0x38}}, { 8466 ,{0x1C, 0x38}} }},
   { /* 6  */ UL1_MIPI_ASM , UL1_MIPI_PORT3, UL1_REG_W  ,    MIPI_USID_ASM0    , { { 8264 ,{0x00, 0x03}}, { 8314 ,{0x00, 0x03}}, { 8365 ,{0x00, 0x03}}, { 8415 ,{0x00, 0x03}}, { 8466 ,{0x00, 0x03}} }},
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8264 ,{0x00, 0x00}}, { 8314 ,{0x00, 0x00}}, { 8365 ,{0x00, 0x00}}, { 8415 ,{0x00, 0x00}}, { 8466 ,{0x00, 0x00}} }},
};


UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand8_Set0[UL1_MIPI_TX_DATA_NUM] = 
{
   //No.      elm type , port_sel      ,  data_seq  , user id,         { { sub 0 ,addr, data }},{ sub 1 ,addr, data }},{ sub 2 ,addr, data}}, { sub 3, addr, data}}, { sub 4, addr data  } }},   
   { /* 0  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 1  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 2  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 8824 ,{0x01, 0x00}}, { 8899 ,{0x01, 0x00}}, { 8975 ,{0x01, 0x00}}, { 9050 ,{0x01, 0x00}}, { 9126 ,{0x01, 0x00}} }},
   { /* 3  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 8824 ,{0x02, 0x00}}, { 8899 ,{0x02, 0x00}}, { 8975 ,{0x02, 0x00}}, { 9050 ,{0x02, 0x00}}, { 9126 ,{0x02, 0x00}} }},
   { /* 4  */ UL1_MIPI_PA  , UL1_MIPI_PORT0, UL1_REG_W  ,    MIPI_USID_PA0   , { { 8824 ,{0x03, 0x00}}, { 8899 ,{0x03, 0x00}}, { 8975 ,{0x03, 0x00}}, { 9050 ,{0x03, 0x00}}, { 9126 ,{0x03, 0x00}} }},
   { /* 5  */ UL1_MIPI_ASM , UL1_MIPI_PORT3, UL1_REG_W  ,    MIPI_USID_ASM0    , { { 8824 ,{0x1C, 0x38}}, { 8899 ,{0x1C, 0x38}}, { 8975 ,{0x1C, 0x38}}, { 9050 ,{0x1C, 0x38}}, { 9126 ,{0x1C, 0x38}} }},
   { /* 6  */ UL1_MIPI_ASM , UL1_MIPI_PORT3, UL1_REG_W  ,    MIPI_USID_ASM0    , { { 8824 ,{0x00, 0x10}}, { 8899 ,{0x00, 0x10}}, { 8975 ,{0x00, 0x10}}, { 9050 ,{0x00, 0x10}}, { 9126 ,{0x00, 0x10}} }},
   { /* 7  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 8  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 9  */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 10 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 11 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 12 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 13 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 14 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 15 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 16 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
   { /* 17 */ UL1_MIPI_NULL, UL1_MIPI_DATA_NULL, UL1_SEQ_NULL,   MIPI_USID_INIT0 , { { 8824 ,{0x00, 0x00}}, { 8899 ,{0x00, 0x00}}, { 8975 ,{0x00, 0x00}}, { 9050 ,{0x00, 0x00}}, { 9126 ,{0x00, 0x00}} }},
};

UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand3_Set0[]  = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand6_Set0[]  = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand9_Set0[]  = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand11_Set0[] = {{0}};
UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_TX_DATA_UMTSBand19_Set0[] = {{0}};

UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_TX_DATA_TABLE_Set0[] = 
{
   M_UMTS_TX_DATA(UMTSBandNone,Set0),                     /*UMTSUMTSBandNone*/
   M_UMTS_TX_DATA(RX_BAND_INDICATOR_0_Set0,Set0),   /*RX_BAND_INDICATOR_0_Set0*/
   M_UMTS_TX_DATA(RX_BAND_INDICATOR_1_Set0,Set0),   /*RX_BAND_INDICATOR_1_Set0*/
   M_UMTS_TX_DATA(RX_BAND_INDICATOR_2_Set0,Set0),   /*RX_BAND_INDICATOR_2_Set0*/
   M_UMTS_TX_DATA(RX_BAND_INDICATOR_3_Set0,Set0),   /*RX_BAND_INDICATOR_3_Set0*/
   M_UMTS_TX_DATA(RX_BAND_INDICATOR_4_Set0,Set0),   /*RX_BAND_INDICATOR_4_Set0*/
};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBandNone_Set0 = {{{0}}};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand1_Set0 = 
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
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x5C}}, {19362, {0x00, 0x5C}}, {19500, {0x00, 0x5C}}, {19638, {0x00, 0x5C}}, {19776, {0x00, 0x5C}}}},  /*L7, TPC IDX 0*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x77}}, {19362, {0x01, 0x77}}, {19500, {0x01, 0x77}}, {19638, {0x01, 0x77}}, {19776, {0x01, 0x77}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xC0}}, {19362, {0x02, 0xC0}}, {19500, {0x02, 0xC0}}, {19638, {0x02, 0xC0}}, {19776, {0x02, 0xC0}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x88}}, {19362, {0x03, 0x88}}, {19500, {0x03, 0x88}}, {19638, {0x03, 0x88}}, {19776, {0x03, 0x88}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x5C}}, {19362, {0x00, 0x5C}}, {19500, {0x00, 0x5C}}, {19638, {0x00, 0x5C}}, {19776, {0x00, 0x5C}}}},  /*L6, TPC IDX 2*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x77}}, {19362, {0x01, 0x77}}, {19500, {0x01, 0x77}}, {19638, {0x01, 0x77}}, {19776, {0x01, 0x77}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xC0}}, {19362, {0x02, 0xC0}}, {19500, {0x02, 0xC0}}, {19638, {0x02, 0xC0}}, {19776, {0x02, 0xC0}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x88}}, {19362, {0x03, 0x88}}, {19500, {0x03, 0x88}}, {19638, {0x03, 0x88}}, {19776, {0x03, 0x88}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x5C}}, {19362, {0x00, 0x5C}}, {19500, {0x00, 0x5C}}, {19638, {0x00, 0x5C}}, {19776, {0x00, 0x5C}}}},  /*L5, TPC IDX 4*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x65}}, {19362, {0x01, 0x65}}, {19500, {0x01, 0x65}}, {19638, {0x01, 0x65}}, {19776, {0x01, 0x65}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xC0}}, {19362, {0x02, 0xC0}}, {19500, {0x02, 0xC0}}, {19638, {0x02, 0xC0}}, {19776, {0x02, 0xC0}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x88}}, {19362, {0x03, 0x88}}, {19500, {0x03, 0x88}}, {19638, {0x03, 0x88}}, {19776, {0x03, 0x88}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x5C}}, {19362, {0x00, 0x5C}}, {19500, {0x00, 0x5C}}, {19638, {0x00, 0x5C}}, {19776, {0x00, 0x5C}}}},  /*L4, TPC IDX 6*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x65}}, {19362, {0x01, 0x65}}, {19500, {0x01, 0x65}}, {19638, {0x01, 0x65}}, {19776, {0x01, 0x65}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xC0}}, {19362, {0x02, 0xC0}}, {19500, {0x02, 0xC0}}, {19638, {0x02, 0xC0}}, {19776, {0x02, 0xC0}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x88}}, {19362, {0x03, 0x88}}, {19500, {0x03, 0x88}}, {19638, {0x03, 0x88}}, {19776, {0x03, 0x88}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x5C}}, {19362, {0x00, 0x5C}}, {19500, {0x00, 0x5C}}, {19638, {0x00, 0x5C}}, {19776, {0x00, 0x5C}}}},  /*L3, TPC IDX 9*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x34}}, {19362, {0x01, 0x34}}, {19500, {0x01, 0x34}}, {19638, {0x01, 0x34}}, {19776, {0x01, 0x34}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xC0}}, {19362, {0x02, 0xC0}}, {19500, {0x02, 0xC0}}, {19638, {0x02, 0xC0}}, {19776, {0x02, 0xC0}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x88}}, {19362, {0x03, 0x88}}, {19500, {0x03, 0x88}}, {19638, {0x03, 0x88}}, {19776, {0x03, 0x88}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x5C}}, {19362, {0x00, 0x5C}}, {19500, {0x00, 0x5C}}, {19638, {0x00, 0x5C}}, {19776, {0x00, 0x5C}}}},  /*L2, TPC IDX 15, Hyst1*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x34}}, {19362, {0x01, 0x34}}, {19500, {0x01, 0x34}}, {19638, {0x01, 0x34}}, {19776, {0x01, 0x34}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xC0}}, {19362, {0x02, 0xC0}}, {19500, {0x02, 0xC0}}, {19638, {0x02, 0xC0}}, {19776, {0x02, 0xC0}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x88}}, {19362, {0x03, 0x88}}, {19500, {0x03, 0x88}}, {19638, {0x03, 0x88}}, {19776, {0x03, 0x88}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x5C}}, {19362, {0x00, 0x5C}}, {19500, {0x00, 0x5C}}, {19638, {0x00, 0x5C}}, {19776, {0x00, 0x5C}}}},  /*L1, TPC IDX 18*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x24}}, {19362, {0x01, 0x24}}, {19500, {0x01, 0x24}}, {19638, {0x01, 0x24}}, {19776, {0x01, 0x24}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xC0}}, {19362, {0x02, 0xC0}}, {19500, {0x02, 0xC0}}, {19638, {0x02, 0xC0}}, {19776, {0x02, 0xC0}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x80}}, {19362, {0x03, 0x80}}, {19500, {0x03, 0x80}}, {19638, {0x03, 0x80}}, {19776, {0x03, 0x80}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x00, 0x5C}}, {19362, {0x00, 0x5C}}, {19500, {0x00, 0x5C}}, {19638, {0x00, 0x5C}}, {19776, {0x00, 0x5C}}}},  /*L0, TPC IDX 25, Hyst2*/
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x01, 0x14}}, {19362, {0x01, 0x14}}, {19500, {0x01, 0x14}}, {19638, {0x01, 0x14}}, {19776, {0x01, 0x14}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x02, 0xC0}}, {19362, {0x02, 0xC0}}, {19500, {0x02, 0xC0}}, {19638, {0x02, 0xC0}}, {19776, {0x02, 0xC0}}}},
    {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{19224, {0x03, 0x80}}, {19362, {0x03, 0x80}}, {19500, {0x03, 0x80}}, {19638, {0x03, 0x80}}, {19776, {0x03, 0x80}}}},
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


UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand2_Set0 = 
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
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x54}}, {18662, {0x00, 0x54}}, {18800, {0x00, 0x54}}, {18938, {0x00, 0x54}}, {19076, {0x00, 0x54}} }},  /*L7, TPC IDX 0*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0xA6}}, {18662, {0x01, 0xA6}}, {18800, {0x01, 0xA6}}, {18938, {0x01, 0xA6}}, {19076, {0x01, 0xA6}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xB0}}, {18662, {0x02, 0xB0}}, {18800, {0x02, 0xB0}}, {18938, {0x02, 0xB0}}, {19076, {0x02, 0xB0}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x86}}, {18662, {0x03, 0x86}}, {18800, {0x03, 0x86}}, {18938, {0x03, 0x86}}, {19076, {0x03, 0x86}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x54}}, {18662, {0x00, 0x54}}, {18800, {0x00, 0x54}}, {18938, {0x00, 0x54}}, {19076, {0x00, 0x54}} }},  /*L6, TPC IDX 2*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0xA6}}, {18662, {0x01, 0xA6}}, {18800, {0x01, 0xA6}}, {18938, {0x01, 0xA6}}, {19076, {0x01, 0xA6}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xB0}}, {18662, {0x02, 0xB0}}, {18800, {0x02, 0xB0}}, {18938, {0x02, 0xB0}}, {19076, {0x02, 0xB0}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x86}}, {18662, {0x03, 0x86}}, {18800, {0x03, 0x86}}, {18938, {0x03, 0x86}}, {19076, {0x03, 0x86}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x54}}, {18662, {0x00, 0x54}}, {18800, {0x00, 0x54}}, {18938, {0x00, 0x54}}, {19076, {0x00, 0x54}} }},  /*L5, TPC IDX 4*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x84}}, {18662, {0x01, 0x84}}, {18800, {0x01, 0x84}}, {18938, {0x01, 0x84}}, {19076, {0x01, 0x84}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xB0}}, {18662, {0x02, 0xB0}}, {18800, {0x02, 0xB0}}, {18938, {0x02, 0xB0}}, {19076, {0x02, 0xB0}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x86}}, {18662, {0x03, 0x86}}, {18800, {0x03, 0x86}}, {18938, {0x03, 0x86}}, {19076, {0x03, 0x86}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x54}}, {18662, {0x00, 0x54}}, {18800, {0x00, 0x54}}, {18938, {0x00, 0x54}}, {19076, {0x00, 0x54}} }},  /*L4, TPC IDX 6*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x84}}, {18662, {0x01, 0x84}}, {18800, {0x01, 0x84}}, {18938, {0x01, 0x84}}, {19076, {0x01, 0x84}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xB0}}, {18662, {0x02, 0xB0}}, {18800, {0x02, 0xB0}}, {18938, {0x02, 0xB0}}, {19076, {0x02, 0xB0}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x86}}, {18662, {0x03, 0x86}}, {18800, {0x03, 0x86}}, {18938, {0x03, 0x86}}, {19076, {0x03, 0x86}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x54}}, {18662, {0x00, 0x54}}, {18800, {0x00, 0x54}}, {18938, {0x00, 0x54}}, {19076, {0x00, 0x54}} }},  /*L3, TPC IDX 9*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x73}}, {18662, {0x01, 0x73}}, {18800, {0x01, 0x73}}, {18938, {0x01, 0x73}}, {19076, {0x01, 0x73}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xB0}}, {18662, {0x02, 0xB0}}, {18800, {0x02, 0xB0}}, {18938, {0x02, 0xB0}}, {19076, {0x02, 0xB0}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x86}}, {18662, {0x03, 0x86}}, {18800, {0x03, 0x86}}, {18938, {0x03, 0x86}}, {19076, {0x03, 0x86}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x54}}, {18662, {0x00, 0x54}}, {18800, {0x00, 0x54}}, {18938, {0x00, 0x54}}, {19076, {0x00, 0x54}} }},  /*L2, TPC IDX 15, Hyst1*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x53}}, {18662, {0x01, 0x53}}, {18800, {0x01, 0x53}}, {18938, {0x01, 0x53}}, {19076, {0x01, 0x53}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xB0}}, {18662, {0x02, 0xB0}}, {18800, {0x02, 0xB0}}, {18938, {0x02, 0xB0}}, {19076, {0x02, 0xB0}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x86}}, {18662, {0x03, 0x86}}, {18800, {0x03, 0x86}}, {18938, {0x03, 0x86}}, {19076, {0x03, 0x86}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x54}}, {18662, {0x00, 0x54}}, {18800, {0x00, 0x54}}, {18938, {0x00, 0x54}}, {19076, {0x00, 0x54}} }},  /*L1, TPC IDX 18*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x53}}, {18662, {0x01, 0x53}}, {18800, {0x01, 0x53}}, {18938, {0x01, 0x53}}, {19076, {0x01, 0x53}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xB0}}, {18662, {0x02, 0xB0}}, {18800, {0x02, 0xB0}}, {18938, {0x02, 0xB0}}, {19076, {0x02, 0xB0}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x86}}, {18662, {0x03, 0x86}}, {18800, {0x03, 0x86}}, {18938, {0x03, 0x86}}, {19076, {0x03, 0x86}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x00, 0x54}}, {18662, {0x00, 0x54}}, {18800, {0x00, 0x54}}, {18938, {0x00, 0x54}}, {19076, {0x00, 0x54}} }},  /*L0, TPC IDX 25, Hyst2*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x01, 0x13}}, {18662, {0x01, 0x13}}, {18800, {0x01, 0x13}}, {18938, {0x01, 0x13}}, {19076, {0x01, 0x13}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x02, 0xB0}}, {18662, {0x02, 0xB0}}, {18800, {0x02, 0xB0}}, {18938, {0x02, 0xB0}}, {19076, {0x02, 0xB0}} }},
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{18524, {0x03, 0x80}}, {18662, {0x03, 0x80}}, {18800, {0x03, 0x80}}, {18938, {0x03, 0x80}}, {19076, {0x03, 0x80}} }},
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }},
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL, MIPI_USID_INIT0, {{18524, {0x00, 0x00}}, {18662, {0x00, 0x00}}, {18800, {0x00, 0x00}}, {18938, {0x00, 0x00}}, {19076, {0x00, 0x00}} }}
   }
};

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand4_Set0 = 
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
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L7, TPC IDX 0*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8E}}, {17224, {0x02, 0x8E}}, {17324, {0x02, 0x8E}}, {17425, {0x02, 0x8E}}, {17526, {0x02, 0x8E}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x00}}, {17224, {0x03, 0x00}}, {17324, {0x03, 0x00}}, {17425, {0x03, 0x00}}, {17526, {0x03, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L6, TPC IDX 2*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8E}}, {17224, {0x02, 0x8E}}, {17324, {0x02, 0x8E}}, {17425, {0x02, 0x8E}}, {17526, {0x02, 0x8E}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x00}}, {17224, {0x03, 0x00}}, {17324, {0x03, 0x00}}, {17425, {0x03, 0x00}}, {17526, {0x03, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L5, TPC IDX 4*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8E}}, {17224, {0x02, 0x8E}}, {17324, {0x02, 0x8E}}, {17425, {0x02, 0x8E}}, {17526, {0x02, 0x8E}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x00}}, {17224, {0x03, 0x00}}, {17324, {0x03, 0x00}}, {17425, {0x03, 0x00}}, {17526, {0x03, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L4, TPC IDX 6*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8E}}, {17224, {0x02, 0x8E}}, {17324, {0x02, 0x8E}}, {17425, {0x02, 0x8E}}, {17526, {0x02, 0x8E}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x00}}, {17224, {0x03, 0x00}}, {17324, {0x03, 0x00}}, {17425, {0x03, 0x00}}, {17526, {0x03, 0x00}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L3, TPC IDX 9*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8A}}, {17224, {0x02, 0x8A}}, {17324, {0x02, 0x8A}}, {17425, {0x02, 0x8A}}, {17526, {0x02, 0x8A}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x10}}, {17224, {0x03, 0x10}}, {17324, {0x03, 0x10}}, {17425, {0x03, 0x10}}, {17526, {0x03, 0x10}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L2, TPC IDX 15, Hyst1*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8A}}, {17224, {0x02, 0x8A}}, {17324, {0x02, 0x8A}}, {17425, {0x02, 0x8A}}, {17526, {0x02, 0x8A}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x10}}, {17224, {0x03, 0x10}}, {17324, {0x03, 0x10}}, {17425, {0x03, 0x10}}, {17526, {0x03, 0x10}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L1, TPC IDX 18*/       
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x8A}}, {17224, {0x02, 0x8A}}, {17324, {0x02, 0x8A}}, {17425, {0x02, 0x8A}}, {17526, {0x02, 0x8A}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x10}}, {17224, {0x03, 0x10}}, {17324, {0x03, 0x10}}, {17425, {0x03, 0x10}}, {17526, {0x03, 0x10}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x00, 0x08}}, {17224, {0x00, 0x08}}, {17324, {0x00, 0x08}}, {17425, {0x00, 0x08}}, {17526, {0x00, 0x08}} }},  /*L0, TPC IDX 25, Hyst2*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x01, 0x1F}}, {17224, {0x01, 0x1F}}, {17324, {0x01, 0x1F}}, {17425, {0x01, 0x1F}}, {17526, {0x01, 0x1F}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x02, 0x66}}, {17224, {0x02, 0x66}}, {17324, {0x02, 0x66}}, {17425, {0x02, 0x66}}, {17526, {0x02, 0x66}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{17124, {0x03, 0x00}}, {17224, {0x03, 0x00}}, {17324, {0x03, 0x00}}, {17425, {0x03, 0x00}}, {17526, {0x03, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }},                           
     {UL1_MIPI_NULL , UL1_MIPI_DATA_NULL , UL1_SEQ_NULL ,MIPI_USID_INIT0, {{17124, {0x00, 0x00}}, {17224, {0x00, 0x00}}, {17324, {0x00, 0x00}}, {17425, {0x00, 0x00}}, {17526, {0x00, 0x00}} }}                            
   }                                                                            
};


UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand5_Set0 = 
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
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x2C}}, {8314, {0x00, 0x2C}}, {8365, {0x00, 0x2C}}, {8415, {0x00, 0x2C}}, {8466, {0x00, 0x2C}} }},  /*L7, TPC IDX 0*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x69}}, {8314, {0x01, 0x69}}, {8365, {0x01, 0x69}}, {8415, {0x01, 0x69}}, {8466, {0x01, 0x69}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x30}}, {8314, {0x02, 0x30}}, {8365, {0x02, 0x30}}, {8415, {0x02, 0x30}}, {8466, {0x02, 0x30}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x8B}}, {8314, {0x03, 0x8B}}, {8365, {0x03, 0x8B}}, {8415, {0x03, 0x8B}}, {8466, {0x03, 0x8B}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x2C}}, {8314, {0x00, 0x2C}}, {8365, {0x00, 0x2C}}, {8415, {0x00, 0x2C}}, {8466, {0x00, 0x2C}} }},  /*L6, TPC IDX 2*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x69}}, {8314, {0x01, 0x69}}, {8365, {0x01, 0x69}}, {8415, {0x01, 0x69}}, {8466, {0x01, 0x69}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x30}}, {8314, {0x02, 0x30}}, {8365, {0x02, 0x30}}, {8415, {0x02, 0x30}}, {8466, {0x02, 0x30}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x8B}}, {8314, {0x03, 0x8B}}, {8365, {0x03, 0x8B}}, {8415, {0x03, 0x8B}}, {8466, {0x03, 0x8B}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x2C}}, {8314, {0x00, 0x2C}}, {8365, {0x00, 0x2C}}, {8415, {0x00, 0x2C}}, {8466, {0x00, 0x2C}} }},  /*L5, TPC IDX 4*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x57}}, {8314, {0x01, 0x57}}, {8365, {0x01, 0x57}}, {8415, {0x01, 0x57}}, {8466, {0x01, 0x57}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x30}}, {8314, {0x02, 0x30}}, {8365, {0x02, 0x30}}, {8415, {0x02, 0x30}}, {8466, {0x02, 0x30}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x8B}}, {8314, {0x03, 0x8B}}, {8365, {0x03, 0x8B}}, {8415, {0x03, 0x8B}}, {8466, {0x03, 0x8B}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x2C}}, {8314, {0x00, 0x2C}}, {8365, {0x00, 0x2C}}, {8415, {0x00, 0x2C}}, {8466, {0x00, 0x2C}} }},  /*L4, TPC IDX 6*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x55}}, {8314, {0x01, 0x55}}, {8365, {0x01, 0x55}}, {8415, {0x01, 0x55}}, {8466, {0x01, 0x55}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x30}}, {8314, {0x02, 0x30}}, {8365, {0x02, 0x30}}, {8415, {0x02, 0x30}}, {8466, {0x02, 0x30}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x8B}}, {8314, {0x03, 0x8B}}, {8365, {0x03, 0x8B}}, {8415, {0x03, 0x8B}}, {8466, {0x03, 0x8B}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x2C}}, {8314, {0x00, 0x2C}}, {8365, {0x00, 0x2C}}, {8415, {0x00, 0x2C}}, {8466, {0x00, 0x2C}} }},  /*L3, TPC IDX 9*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x44}}, {8314, {0x01, 0x44}}, {8365, {0x01, 0x44}}, {8415, {0x01, 0x44}}, {8466, {0x01, 0x44}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x30}}, {8314, {0x02, 0x30}}, {8365, {0x02, 0x30}}, {8415, {0x02, 0x30}}, {8466, {0x02, 0x30}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x8B}}, {8314, {0x03, 0x8B}}, {8365, {0x03, 0x8B}}, {8415, {0x03, 0x8B}}, {8466, {0x03, 0x8B}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x2C}}, {8314, {0x00, 0x2C}}, {8365, {0x00, 0x2C}}, {8415, {0x00, 0x2C}}, {8466, {0x00, 0x2C}} }},  /*L2, TPC IDX 15, Hyst1*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x44}}, {8314, {0x01, 0x44}}, {8365, {0x01, 0x44}}, {8415, {0x01, 0x44}}, {8466, {0x01, 0x44}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x30}}, {8314, {0x02, 0x30}}, {8365, {0x02, 0x30}}, {8415, {0x02, 0x30}}, {8466, {0x02, 0x30}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x8B}}, {8314, {0x03, 0x8B}}, {8365, {0x03, 0x8B}}, {8415, {0x03, 0x8B}}, {8466, {0x03, 0x8B}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x2C}}, {8314, {0x00, 0x2C}}, {8365, {0x00, 0x2C}}, {8415, {0x00, 0x2C}}, {8466, {0x00, 0x2C}} }},  /*L1, TPC IDX 18*/       
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x24}}, {8314, {0x01, 0x24}}, {8365, {0x01, 0x24}}, {8415, {0x01, 0x24}}, {8466, {0x01, 0x24}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x30}}, {8314, {0x02, 0x30}}, {8365, {0x02, 0x30}}, {8415, {0x02, 0x30}}, {8466, {0x02, 0x30}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x80}}, {8314, {0x03, 0x80}}, {8365, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8466, {0x03, 0x80}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x00, 0x2C}}, {8314, {0x00, 0x2C}}, {8365, {0x00, 0x2C}}, {8415, {0x00, 0x2C}}, {8466, {0x00, 0x2C}} }},  /*L0, TPC IDX 25, Hyst2*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x01, 0x14}}, {8314, {0x01, 0x14}}, {8365, {0x01, 0x14}}, {8415, {0x01, 0x14}}, {8466, {0x01, 0x14}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x02, 0x30}}, {8314, {0x02, 0x30}}, {8365, {0x02, 0x30}}, {8415, {0x02, 0x30}}, {8466, {0x02, 0x30}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8264, {0x03, 0x80}}, {8314, {0x03, 0x80}}, {8365, {0x03, 0x80}}, {8415, {0x03, 0x80}}, {8466, {0x03, 0x80}} }},                           
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

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand8_Set0 = 
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
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x24}}, {8899, {0x00, 0x24}}, {8975, {0x00, 0x24}}, {9050, {0x00, 0x24}}, {9126, {0x00, 0x24}} }},  /*L7, TPC IDX 0*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x59}}, {8899, {0x01, 0x59}}, {8975, {0x01, 0x59}}, {9050, {0x01, 0x59}}, {9126, {0x01, 0x59}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0x20}}, {8899, {0x02, 0x20}}, {8975, {0x02, 0x20}}, {9050, {0x02, 0x20}}, {9126, {0x02, 0x20}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x87}}, {8899, {0x03, 0x87}}, {8975, {0x03, 0x87}}, {9050, {0x03, 0x87}}, {9126, {0x03, 0x87}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x24}}, {8899, {0x00, 0x24}}, {8975, {0x00, 0x24}}, {9050, {0x00, 0x24}}, {9126, {0x00, 0x24}} }},  /*L6, TPC IDX 2*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x59}}, {8899, {0x01, 0x59}}, {8975, {0x01, 0x59}}, {9050, {0x01, 0x59}}, {9126, {0x01, 0x59}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0x20}}, {8899, {0x02, 0x20}}, {8975, {0x02, 0x20}}, {9050, {0x02, 0x20}}, {9126, {0x02, 0x20}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x87}}, {8899, {0x03, 0x87}}, {8975, {0x03, 0x87}}, {9050, {0x03, 0x87}}, {9126, {0x03, 0x87}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x24}}, {8899, {0x00, 0x24}}, {8975, {0x00, 0x24}}, {9050, {0x00, 0x24}}, {9126, {0x00, 0x24}} }},  /*L5, TPC IDX 4*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x59}}, {8899, {0x01, 0x59}}, {8975, {0x01, 0x59}}, {9050, {0x01, 0x59}}, {9126, {0x01, 0x59}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0x20}}, {8899, {0x02, 0x20}}, {8975, {0x02, 0x20}}, {9050, {0x02, 0x20}}, {9126, {0x02, 0x20}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x87}}, {8899, {0x03, 0x87}}, {8975, {0x03, 0x87}}, {9050, {0x03, 0x87}}, {9126, {0x03, 0x87}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x24}}, {8899, {0x00, 0x24}}, {8975, {0x00, 0x24}}, {9050, {0x00, 0x24}}, {9126, {0x00, 0x24}} }},  /*L4, TPC IDX 6*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x37}}, {8899, {0x01, 0x37}}, {8975, {0x01, 0x37}}, {9050, {0x01, 0x37}}, {9126, {0x01, 0x37}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0x20}}, {8899, {0x02, 0x20}}, {8975, {0x02, 0x20}}, {9050, {0x02, 0x20}}, {9126, {0x02, 0x20}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x87}}, {8899, {0x03, 0x87}}, {8975, {0x03, 0x87}}, {9050, {0x03, 0x87}}, {9126, {0x03, 0x87}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x24}}, {8899, {0x00, 0x24}}, {8975, {0x00, 0x24}}, {9050, {0x00, 0x24}}, {9126, {0x00, 0x24}} }},  /*L3, TPC IDX 9*/        
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x36}}, {8899, {0x01, 0x36}}, {8975, {0x01, 0x36}}, {9050, {0x01, 0x36}}, {9126, {0x01, 0x36}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0x20}}, {8899, {0x02, 0x20}}, {8975, {0x02, 0x20}}, {9050, {0x02, 0x20}}, {9126, {0x02, 0x20}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x87}}, {8899, {0x03, 0x87}}, {8975, {0x03, 0x87}}, {9050, {0x03, 0x87}}, {9126, {0x03, 0x87}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x24}}, {8899, {0x00, 0x24}}, {8975, {0x00, 0x24}}, {9050, {0x00, 0x24}}, {9126, {0x00, 0x24}} }},  /*L2, TPC IDX 15, Hyst1*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x35}}, {8899, {0x01, 0x35}}, {8975, {0x01, 0x35}}, {9050, {0x01, 0x35}}, {9126, {0x01, 0x35}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0x20}}, {8899, {0x02, 0x20}}, {8975, {0x02, 0x20}}, {9050, {0x02, 0x20}}, {9126, {0x02, 0x20}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x87}}, {8899, {0x03, 0x87}}, {8975, {0x03, 0x87}}, {9050, {0x03, 0x87}}, {9126, {0x03, 0x87}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x24}}, {8899, {0x00, 0x24}}, {8975, {0x00, 0x24}}, {9050, {0x00, 0x24}}, {9126, {0x00, 0x24}} }},  /*L1, TPC IDX 18*/       
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x25}}, {8899, {0x01, 0x25}}, {8975, {0x01, 0x25}}, {9050, {0x01, 0x25}}, {9126, {0x01, 0x25}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0x20}}, {8899, {0x02, 0x20}}, {8975, {0x02, 0x20}}, {9050, {0x02, 0x20}}, {9126, {0x02, 0x20}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x87}}, {8899, {0x03, 0x87}}, {8975, {0x03, 0x87}}, {9050, {0x03, 0x87}}, {9126, {0x03, 0x87}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x00, 0x24}}, {8899, {0x00, 0x24}}, {8975, {0x00, 0x24}}, {9050, {0x00, 0x24}}, {9126, {0x00, 0x24}} }},  /*L0, TPC IDX 25, Hyst2*/
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x01, 0x13}}, {8899, {0x01, 0x13}}, {8975, {0x01, 0x13}}, {9050, {0x01, 0x13}}, {9126, {0x01, 0x13}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x02, 0x20}}, {8899, {0x02, 0x20}}, {8975, {0x02, 0x20}}, {9050, {0x02, 0x20}}, {9126, {0x02, 0x20}} }},                           
     {UL1_MIPI_PA   , UL1_MIPI_PORT0 , UL1_REG_W ,   MIPI_USID_PA0,   {{8824, {0x03, 0x80}}, {8899, {0x03, 0x80}}, {8975, {0x03, 0x80}}, {9050, {0x03, 0x80}}, {9126, {0x03, 0x80}} }},                           
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

UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand3_Set0  = {{{0}}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand6_Set0  = {{{0}}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand9_Set0  = {{{0}}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand11_Set0 = {{{0}}};
UL1_UMTS_MIPI_TPC_T UMTS_MIPI_TPC_UMTSBand19_Set0 = {{{0}}};

UL1_UMTS_MIPI_TPC_T* UMTS_MIPI_TPC_TABLE_Set0[] =
{
   M_UMTS_TPC(UMTSBandNone,Set0),                     /*UMTSUMTSBandNone*/          
   M_UMTS_TPC(RX_BAND_INDICATOR_0_Set0,Set0),   /*RX_BAND_INDICATOR_0_Set0*/
   M_UMTS_TPC(RX_BAND_INDICATOR_1_Set0,Set0),   /*RX_BAND_INDICATOR_1_Set0*/
   M_UMTS_TPC(RX_BAND_INDICATOR_2_Set0,Set0),   /*RX_BAND_INDICATOR_2_Set0*/
   M_UMTS_TPC(RX_BAND_INDICATOR_3_Set0,Set0),   /*RX_BAND_INDICATOR_3_Set0 */ 
   M_UMTS_TPC(RX_BAND_INDICATOR_4_Set0,Set0),   /*RX_BAND_INDICATOR_4_Set0 */ 
};

#if (IS_3G_ET_SUPPORT)
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ET_ON_STATIC_CW_Set0[ET_MAX_ON_IMM_BSI_CW_NUM] =
{
   //elm type, port_sel        , data_seq, usid        , {addr, data}
   {UL1_MIPI_END, 0, 0, 0,{0,0}}
};

UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ET_OFF_STATIC_CW_Set0[ET_MAX_OFF_IMM_BSI_CW_NUM] =
{
   //elm type, port_sel        , data_seq, usid        , {addr, data}
   {UL1_MIPI_END, 0, 0, 0,{0,0}}
};


UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBandNone_Set0 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand1_Set0 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand2_Set0 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand4_Set0 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand5_Set0 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand8_Set0 = {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand3_Set0  =  {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand6_Set0  =  {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand9_Set0  =  {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand11_Set0 =  {{{0}}};
UL1_UMTS_MIPI_ET_T UMTS_MIPI_ET_UMTSBand19_Set0 =  {{{0}}};

UL1_MIPI_EVENT_TABLE_T*  UMTS_MIPI_ET_EVENT_TABLE_Set0[] =
{
   M_UMTS_ET_EVENT(UMTSBandNone,Set0),                     /*UMTSUMTSBandNone*/
   M_UMTS_ET_EVENT(RX_BAND_INDICATOR_0_Set0,Set0),   /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_ET_EVENT(RX_BAND_INDICATOR_1_Set0,Set0),   /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_ET_EVENT(RX_BAND_INDICATOR_2_Set0,Set0),   /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_ET_EVENT(RX_BAND_INDICATOR_3_Set0,Set0),   /*RX_LOWBAND1_INDICATOR */
   M_UMTS_ET_EVENT(RX_BAND_INDICATOR_4_Set0,Set0),   /*RX_LOWBAND2_INDICATOR */
};

UL1_MIPI_DATA_SUBBAND_TABLE_T* UMTS_MIPI_ET_DATA_TABLE_Set0[] =
{
   M_UMTS_ET_DATA(UMTSBandNone,Set0),                      /*UMTSUMTSBandNone*/
   M_UMTS_ET_DATA(RX_BAND_INDICATOR_0_Set0,Set0),    /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_ET_DATA(RX_BAND_INDICATOR_1_Set0,Set0),    /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_ET_DATA(RX_BAND_INDICATOR_2_Set0,Set0),    /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_ET_DATA(RX_BAND_INDICATOR_3_Set0,Set0),    /*RX_LOWBAND1_INDICATOR */
   M_UMTS_ET_DATA(RX_BAND_INDICATOR_4_Set0,Set0),    /*RX_LOWBAND2_INDICATOR */
};

UL1_UMTS_MIPI_ET_T* UMTS_MIPI_ET_TABLE_Set0[] =
{
   M_UMTS_ET(UMTSBandNone,Set0),                           /*UMTSUMTSBandNone*/
   M_UMTS_ET(RX_BAND_INDICATOR_0_Set0,Set0),         /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_ET(RX_BAND_INDICATOR_1_Set0,Set0),         /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_ET(RX_BAND_INDICATOR_2_Set0,Set0),         /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_ET(RX_BAND_INDICATOR_3_Set0,Set0),         /*RX_LOWBAND1_INDICATOR */
   M_UMTS_ET(RX_BAND_INDICATOR_4_Set0,Set0),         /*RX_LOWBAND2_INDICATOR */
};


#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBandNone_Set0 = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand1_Set0    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand2_Set0    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand3_Set0    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand4_Set0    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand5_Set0    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand6_Set0    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand8_Set0    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand9_Set0    = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand11_Set0   = ET_VPA_SOURCE_NOT_SUPPORTED;
UMTS_VPA_SOURCE_TYPE UMTS_VPA_SOURCE_UMTSBand19_Set0   = ET_VPA_SOURCE_NOT_SUPPORTED;

UMTS_VPA_SOURCE_TYPE* UMTS_VPA_SRC_SEL_TABLE_Set0[] =
{
   M_UMTS_VPA_SRC(UMTSBandNone,Set0),                    /*UMTSUMTSBandNone*/
   M_UMTS_VPA_SRC(RX_BAND_INDICATOR_0_Set0,Set0),  /*RX_HIGHBAND1_INDICATOR*/
   M_UMTS_VPA_SRC(RX_BAND_INDICATOR_1_Set0,Set0),  /*RX_HIGHBAND2_INDICATOR*/
   M_UMTS_VPA_SRC(RX_BAND_INDICATOR_2_Set0,Set0),  /*RX_HIGHBAND3_INDICATOR*/
   M_UMTS_VPA_SRC(RX_BAND_INDICATOR_3_Set0,Set0),  /*RX_LOWBAND1_INDICATOR*/
   M_UMTS_VPA_SRC(RX_BAND_INDICATOR_4_Set0,Set0),  /*RX_LOWBAND2_INDICATOR*/
};

#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

UL1_UMTS_MIPI_ET_PARAM_T UL1_ET_PARAM_Set0 = 
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
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBandNone_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand1_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand2_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand4_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand5_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand8_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand3_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand6_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand9_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand11_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};
UL1_MIPI_DATA_TABLE_T UMTS_MIPI_ASM_ISOLATION_DATA_UMTSBand19_Set0[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM] = {{0}};

UL1_MIPI_DATA_TABLE_T* UMTS_MIPI_ASM_ISOLATION_DATA_TABLE_Set0[] = 
{
   M_UMTS_ASM_ISO(UMTSBandNone,Set0),                        /*UMTSUMTSBandNone*/          
   M_UMTS_ASM_ISO(RX_BAND_INDICATOR_0_Set0,Set0),      /*RX_BAND_INDICATOR_0_Set0*/  
   M_UMTS_ASM_ISO(RX_BAND_INDICATOR_1_Set0,Set0),      /*RX_BAND_INDICATOR_1_Set0*/  
   M_UMTS_ASM_ISO(RX_BAND_INDICATOR_2_Set0,Set0),      /*RX_BAND_INDICATOR_2_Set0*/  
   M_UMTS_ASM_ISO(RX_BAND_INDICATOR_3_Set0,Set0),      /*RX_BAND_INDICATOR_3_Set0*/   
   M_UMTS_ASM_ISO(RX_BAND_INDICATOR_4_Set0,Set0),      /*RX_BAND_INDICATOR_4_Set0*/   
};

/////////////////////////////////////////////

#endif

