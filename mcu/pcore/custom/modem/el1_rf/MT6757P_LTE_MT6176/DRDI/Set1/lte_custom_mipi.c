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
*    el1_rf_custom.c
*
* Project:
* --------
*    MT6291
*
* Description:
* ------------
*
*
* Author:
* -------
 * -------
*
*============================================================================*/

/*===========================================================================*/

#include "kal_general_types.h"
#include "lte_custom_rf.h"
#include "lte_custom_mipi.h"

#include "lte_custom_rf_ca.h"
#include "lte_custom_mipi_ca.c"
#include "lte_custom_mipi_ant.c"
/*===========================================================================*/

LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_INITIAL_CW_Set1[LTE_MIPI_INITIAL_CW_SIZE_Set1] =
{
   // elm type   , port_sel      , data_seq ,    USID          , addr , data  , wait_time(us)
   {LTE_MIPI_ASM , LTE_MIPI_PORT0, LTE_REG_W, MIPI_USID_INIT0_P3  , {0x1C, 0x38} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_ASM , LTE_MIPI_PORT1, LTE_REG_W, MIPI_USID_INIT0_P3  , {0x1C, 0x38} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_SLEEP_CW_Set1[LTE_MIPI_SLEEP_CW_SIZE_Set1] =
{
   // elm type   , port_sel      , data_seq ,    USID          , addr , data  , wait_time(us)
   {LTE_MIPI_ASM , LTE_MIPI_PORT0, LTE_REG_W, MIPI_USID_INIT0_P3  , {0x1C, 0xB8} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = low power mode
   {LTE_MIPI_ASM , LTE_MIPI_PORT1, LTE_REG_W, MIPI_USID_INIT0_P3  , {0x1C, 0xB8} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = low power mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band2_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band4_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band5_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 5    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 6    , 14    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band12_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 4    , 8    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band13_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band20_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band26_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band29_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 4    , 8    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band30_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 4    , 8    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0_Set1  }, //
   { /* 1  */ LTE_MIPI_PA  , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0_Set1 }, //3P4T Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_Set1 },
   { /* 1  */ LTE_MIPI_ASM , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_Set1},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0_Set1  },//
   { /* 1  */ LTE_MIPI_PA  , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0_Set1 },//3P4T Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 6    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0_Set1  }, //
   { /* 1  */ LTE_MIPI_PA  , { 7    , 18    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0_Set1 }, //3P4T Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

kal_uint32 LTE_MIPI_RX_EVENT_SIZE_TABLE_Set1[] =
{
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR0,     Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR1,     Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR2,     Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR3,     Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR4,     Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR5,     Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR6,     Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR7,     Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR8,     Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR9,     Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR10,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR11,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR12,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR13,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR14,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR15,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR16,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR17,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR18,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR19,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT(      BAND_INDICATOR20,    Set1)),
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND21, Set1)),     /*Index 0*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND22, Set1)),     /*Index 1*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND23, Set1)),     /*Index 2*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND24, Set1)),     /*Index 3*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND25, Set1)),     /*Index 4*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND26, Set1)),     /*Index 5*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND27, Set1)),     /*Index 6*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND28, Set1)),     /*Index 7*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND29, Set1)),     /*Index 8*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND30, Set1)),     /*Index 9*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND31, Set1)),     /*Index10*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND32, Set1)),     /*Index11*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND33, Set1)),     /*Index12*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND34, Set1)),     /*Index13*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND35, Set1)),     /*Index14*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND36, Set1)),     /*Index15*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND37, Set1)),     /*Index16*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND38, Set1)),     /*Index17*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND39, Set1)),     /*Index18*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND40, Set1)),     /*Index19*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND41, Set1)),     /*Index20*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND42, Set1)),     /*Index21*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND43, Set1)),     /*Index22*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND44, Set1)),     /*Index23*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND45, Set1)),     /*Index24*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND46, Set1)),     /*Index25*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND47, Set1)),     /*Index26*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND48, Set1)),     /*Index27*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND49, Set1)),     /*Index28*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND50, Set1)),     /*Index29*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND51, Set1)),     /*Index30*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND52, Set1)),     /*Index31*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND53, Set1)),     /*Index32*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND54, Set1)),     /*Index33*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND55, Set1)),     /*Index34*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND56, Set1)),     /*Index35*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND57, Set1)),     /*Index36*/
   sizeof(LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND58, Set1)),     /*Index37*/
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_RX_EVENT_TABLE_Set1[LTE_MAX_SUPPORT_FE_ROUTE_NUM] =
{
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR0,     Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR1,     Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR2,     Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR3,     Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR4,     Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR5,     Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR6,     Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR7,     Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR8,     Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR9,     Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR10,    Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR11,    Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR12,    Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR13,    Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR14,    Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR15,    Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR16,    Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR17,    Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR18,    Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR19,    Set1),
   LTE_MIPI_RX_EVENT(      BAND_INDICATOR20,    Set1),
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND21, Set1),     /*Index 0*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND22, Set1),     /*Index 1*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND23, Set1),     /*Index 2*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND24, Set1),     /*Index 3*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND25, Set1),     /*Index 4*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND26, Set1),     /*Index 5*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND27, Set1),     /*Index 6*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND28, Set1),     /*Index 7*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND29, Set1),     /*Index 8*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND30, Set1),     /*Index 9*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND31, Set1),     /*Index10*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND32, Set1),     /*Index11*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND33, Set1),     /*Index12*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND34, Set1),     /*Index13*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND35, Set1),     /*Index14*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND36, Set1),     /*Index15*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND37, Set1),     /*Index16*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND38, Set1),     /*Index17*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND39, Set1),     /*Index18*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND40, Set1),     /*Index19*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND41, Set1),     /*Index20*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND42, Set1),     /*Index21*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND43, Set1),     /*Index22*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND44, Set1),     /*Index23*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND45, Set1),     /*Index24*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND46, Set1),     /*Index25*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND47, Set1),     /*Index26*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND48, Set1),     /*Index27*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND49, Set1),     /*Index28*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND50, Set1),     /*Index29*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND51, Set1),     /*Index30*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND52, Set1),     /*Index31*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND53, Set1),     /*Index32*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND54, Set1),     /*Index33*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND55, Set1),     /*Index34*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND56, Set1),     /*Index35*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND57, Set1),     /*Index36*/
   LTE_MIPI_RX_EVENT_ROUTE(MIPI_RX_ROUTE_IND58, Set1),     /*Index37*/
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band1_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x05 ,0x03 }, { 21250 /*100 kHz*/ ,0x05 ,0x03 }, { 21400 /*100 kHz*/ ,0x05 ,0x03 }, { 21550 /*100 kHz*/ ,0x05 ,0x03 }, { 21700 /*100 kHz*/ ,0x05 ,0x03 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x01 ,0x02 }, { 21250 /*100 kHz*/ ,0x01 ,0x02 }, { 21400 /*100 kHz*/ ,0x01 ,0x02 }, { 21550 /*100 kHz*/ ,0x01 ,0x02 }, { 21700 /*100 kHz*/ ,0x01 ,0x02 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x05 ,0x00 }, { 21250 /*100 kHz*/ ,0x05 ,0x00 }, { 21400 /*100 kHz*/ ,0x05 ,0x00 }, { 21550 /*100 kHz*/ ,0x05 ,0x00 }, { 21700 /*100 kHz*/ ,0x05 ,0x00 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x04 ,0x00 }, { 21250 /*100 kHz*/ ,0x04 ,0x00 }, { 21400 /*100 kHz*/ ,0x04 ,0x00 }, { 21550 /*100 kHz*/ ,0x04 ,0x00 }, { 21700 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 16  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 17  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x01 ,0x00 }, { 21250 /*100 kHz*/ ,0x01 ,0x00 }, { 21400 /*100 kHz*/ ,0x01 ,0x00 }, { 21550 /*100 kHz*/ ,0x01 ,0x00 }, { 21700 /*100 kHz*/ ,0x01 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band2_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x05 ,0x05 }, { 19450 /*100 kHz*/ ,0x05 ,0x05 }, { 19600 /*100 kHz*/ ,0x05 ,0x05 }, { 19750 /*100 kHz*/ ,0x05 ,0x05 }, { 19900 /*100 kHz*/ ,0x05 ,0x05 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },    
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 19300 /*100 kHz*/ ,0x01 ,0x04 }, { 19450 /*100 kHz*/ ,0x01 ,0x04 }, { 19600 /*100 kHz*/ ,0x01 ,0x04 }, { 19750 /*100 kHz*/ ,0x01 ,0x04 }, { 19900 /*100 kHz*/ ,0x01 ,0x04 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x05 ,0x00 }, { 19450 /*100 kHz*/ ,0x05 ,0x00 }, { 19600 /*100 kHz*/ ,0x05 ,0x00 }, { 19750 /*100 kHz*/ ,0x05 ,0x00 }, { 19900 /*100 kHz*/ ,0x05 ,0x00 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x04 ,0x00 }, { 19450 /*100 kHz*/ ,0x04 ,0x00 }, { 19600 /*100 kHz*/ ,0x04 ,0x00 }, { 19750 /*100 kHz*/ ,0x04 ,0x00 }, { 19900 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 19300 /*100 kHz*/ ,0x01 ,0x00 }, { 19450 /*100 kHz*/ ,0x01 ,0x00 }, { 19600 /*100 kHz*/ ,0x01 ,0x00 }, { 19750 /*100 kHz*/ ,0x01 ,0x00 }, { 19900 /*100 kHz*/ ,0x01 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band3_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x05 ,0x03 }, { 18238 /*100 kHz*/ ,0x05 ,0x03 }, { 18425 /*100 kHz*/ ,0x05 ,0x03 }, { 18612 /*100 kHz*/ ,0x05 ,0x03 }, { 18800 /*100 kHz*/ ,0x05 ,0x03 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18050 /*100 kHz*/ ,0x01 ,0x02 }, { 18238 /*100 kHz*/ ,0x01 ,0x02 }, { 18425 /*100 kHz*/ ,0x01 ,0x02 }, { 18612 /*100 kHz*/ ,0x01 ,0x02 }, { 18800 /*100 kHz*/ ,0x01 ,0x02 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x05 ,0x00 }, { 18238 /*100 kHz*/ ,0x05 ,0x00 }, { 18425 /*100 kHz*/ ,0x05 ,0x00 }, { 18612 /*100 kHz*/ ,0x05 ,0x00 }, { 18800 /*100 kHz*/ ,0x05 ,0x00 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },   
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x04 ,0x00 }, { 18238 /*100 kHz*/ ,0x04 ,0x00 }, { 18425 /*100 kHz*/ ,0x04 ,0x00 }, { 18612 /*100 kHz*/ ,0x04 ,0x00 }, { 18800 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18050 /*100 kHz*/ ,0x01 ,0x00 }, { 18238 /*100 kHz*/ ,0x01 ,0x00 }, { 18425 /*100 kHz*/ ,0x01 ,0x00 }, { 18612 /*100 kHz*/ ,0x01 ,0x00 }, { 18800 /*100 kHz*/ ,0x01 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band4_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x05 ,0x05 }, { 21212 /*100 kHz*/ ,0x05 ,0x05 }, { 21325 /*100 kHz*/ ,0x05 ,0x05 }, { 21437 /*100 kHz*/ ,0x05 ,0x05 }, { 21550 /*100 kHz*/ ,0x05 ,0x05 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x01 ,0x04 }, { 21212 /*100 kHz*/ ,0x01 ,0x04 }, { 21325 /*100 kHz*/ ,0x01 ,0x04 }, { 21437 /*100 kHz*/ ,0x01 ,0x04 }, { 21550 /*100 kHz*/ ,0x01 ,0x04 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x05 ,0x00 }, { 21212 /*100 kHz*/ ,0x05 ,0x00 }, { 21325 /*100 kHz*/ ,0x05 ,0x00 }, { 21437 /*100 kHz*/ ,0x05 ,0x00 }, { 21550 /*100 kHz*/ ,0x05 ,0x00 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x04 ,0x00 }, { 21212 /*100 kHz*/ ,0x04 ,0x00 }, { 21325 /*100 kHz*/ ,0x04 ,0x00 }, { 21437 /*100 kHz*/ ,0x04 ,0x00 }, { 21550 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x01 ,0x00 }, { 21212 /*100 kHz*/ ,0x01 ,0x00 }, { 21325 /*100 kHz*/ ,0x01 ,0x00 }, { 21437 /*100 kHz*/ ,0x01 ,0x00 }, { 21550 /*100 kHz*/ ,0x01 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band5_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x02 ,0x04 }, {  8753 /*100 kHz*/ ,0x02 ,0x04 }, {  8816 /*100 kHz*/ ,0x02 ,0x04 }, {  8879 /*100 kHz*/ ,0x02 ,0x04 }, {  8940 /*100 kHz*/ ,0x02 ,0x04 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  8690 /*100 kHz*/ ,0x00 ,0x04 }, {  8753 /*100 kHz*/ ,0x00 ,0x04 }, {  8816 /*100 kHz*/ ,0x00 ,0x04 }, {  8879 /*100 kHz*/ ,0x00 ,0x04 }, {  8940 /*100 kHz*/ ,0x00 ,0x04 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x02 ,0x00 }, {  8753 /*100 kHz*/ ,0x02 ,0x00 }, {  8816 /*100 kHz*/ ,0x02 ,0x00 }, {  8879 /*100 kHz*/ ,0x02 ,0x00 }, {  8940 /*100 kHz*/ ,0x02 ,0x00 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x04 ,0x00 }, {  8753 /*100 kHz*/ ,0x04 ,0x00 }, {  8816 /*100 kHz*/ ,0x04 ,0x00 }, {  8879 /*100 kHz*/ ,0x04 ,0x00 }, {  8940 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  8690 /*100 kHz*/ ,0x00 ,0x00 }, {  8753 /*100 kHz*/ ,0x00 ,0x00 }, {  8816 /*100 kHz*/ ,0x00 ,0x00 }, {  8879 /*100 kHz*/ ,0x00 ,0x00 }, {  8940 /*100 kHz*/ ,0x00 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band7_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x03 , 0x80}, { 26375 /*100 kHz*/ ,0x03 , 0x80}, { 26550 /*100 kHz*/ ,0x03 , 0x80}, { 26725 /*100 kHz*/ ,0x03 , 0x80}, { 26900 /*100 kHz*/ ,0x03 , 0x80},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} },  
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x03 , 0x00}, { 26375 /*100 kHz*/ ,0x03 , 0x00}, { 26550 /*100 kHz*/ ,0x03 , 0x00}, { 26725 /*100 kHz*/ ,0x03 , 0x00}, { 26900 /*100 kHz*/ ,0x03 , 0x00},} }, 
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x04 , 0x00}, { 26375 /*100 kHz*/ ,0x04 , 0x00}, { 26550 /*100 kHz*/ ,0x04 , 0x00}, { 26725 /*100 kHz*/ ,0x04 , 0x00}, { 26900 /*100 kHz*/ ,0x04 , 0x00},} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 26200 /*100 kHz*/ ,0x1C , 0x38}, { 26375 /*100 kHz*/ ,0x1C , 0x38}, { 26550 /*100 kHz*/ ,0x1C , 0x38}, { 26725 /*100 kHz*/ ,0x1C , 0x38}, { 26900 /*100 kHz*/ ,0x1C , 0x38},} }, 
   { /* 15  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band8_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x02 ,0x02 }, {  9337 /*100 kHz*/ ,0x02 ,0x02 }, {  9425 /*100 kHz*/ ,0x02 ,0x02 }, {  9512 /*100 kHz*/ ,0x02 ,0x02 }, {  9600 /*100 kHz*/ ,0x02 ,0x02 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  9250 /*100 kHz*/ ,0x00 ,0x03 }, {  9337 /*100 kHz*/ ,0x00 ,0x03 }, {  9425 /*100 kHz*/ ,0x00 ,0x03 }, {  9512 /*100 kHz*/ ,0x00 ,0x03 }, {  9600 /*100 kHz*/ ,0x00 ,0x03 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x02 ,0x00 }, {  9337 /*100 kHz*/ ,0x02 ,0x00 }, {  9425 /*100 kHz*/ ,0x02 ,0x00 }, {  9512 /*100 kHz*/ ,0x02 ,0x00 }, {  9600 /*100 kHz*/ ,0x02 ,0x00 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x04 ,0x00 }, {  9337 /*100 kHz*/ ,0x04 ,0x00 }, {  9425 /*100 kHz*/ ,0x04 ,0x00 }, {  9512 /*100 kHz*/ ,0x04 ,0x00 }, {  9600 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  9250 /*100 kHz*/ ,0x00 ,0x00 }, {  9337 /*100 kHz*/ ,0x00 ,0x00 }, {  9425 /*100 kHz*/ ,0x00 ,0x00 }, {  9512 /*100 kHz*/ ,0x00 ,0x00 }, {  9600 /*100 kHz*/ ,0x00 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band12_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7290 /*100 kHz*/ ,0x1C ,0x38 }, {  7332 /*100 kHz*/ ,0x1C ,0x38 }, {  7375 /*100 kHz*/ ,0x1C ,0x38 }, {  7417 /*100 kHz*/ ,0x1C ,0x38 }, {  7460 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7290 /*100 kHz*/ ,0x02 ,0x07 }, {  7332 /*100 kHz*/ ,0x02 ,0x07 }, {  7375 /*100 kHz*/ ,0x02 ,0x07 }, {  7417 /*100 kHz*/ ,0x02 ,0x07 }, {  7460 /*100 kHz*/ ,0x02 ,0x07 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7290 /*100 kHz*/ ,0x1C ,0x38 }, {  7332 /*100 kHz*/ ,0x1C ,0x38 }, {  7375 /*100 kHz*/ ,0x1C ,0x38 }, {  7417 /*100 kHz*/ ,0x1C ,0x38 }, {  7460 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7290 /*100 kHz*/ ,0x00 ,0x06 }, {  7332 /*100 kHz*/ ,0x00 ,0x06 }, {  7375 /*100 kHz*/ ,0x00 ,0x06 }, {  7417 /*100 kHz*/ ,0x00 ,0x06 }, {  7460 /*100 kHz*/ ,0x00 ,0x06 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7290 /*100 kHz*/ ,0x1C ,0x38 }, {  7332 /*100 kHz*/ ,0x1C ,0x38 }, {  7375 /*100 kHz*/ ,0x1C ,0x38 }, {  7417 /*100 kHz*/ ,0x1C ,0x38 }, {  7460 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7290 /*100 kHz*/ ,0x02 ,0x00 }, {  7332 /*100 kHz*/ ,0x02 ,0x00 }, {  7375 /*100 kHz*/ ,0x02 ,0x00 }, {  7417 /*100 kHz*/ ,0x02 ,0x00 }, {  7460 /*100 kHz*/ ,0x02 ,0x00 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7290 /*100 kHz*/ ,0x04 ,0x00 }, {  7332 /*100 kHz*/ ,0x04 ,0x00 }, {  7375 /*100 kHz*/ ,0x04 ,0x00 }, {  7417 /*100 kHz*/ ,0x04 ,0x00 }, {  7460 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7290 /*100 kHz*/ ,0x1C ,0x38 }, {  7332 /*100 kHz*/ ,0x1C ,0x38 }, {  7375 /*100 kHz*/ ,0x1C ,0x38 }, {  7417 /*100 kHz*/ ,0x1C ,0x38 }, {  7460 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7290 /*100 kHz*/ ,0x00 ,0x00 }, {  7332 /*100 kHz*/ ,0x00 ,0x00 }, {  7375 /*100 kHz*/ ,0x00 ,0x00 }, {  7417 /*100 kHz*/ ,0x00 ,0x00 }, {  7460 /*100 kHz*/ ,0x00 ,0x00 },} },
   { /* 9  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band13_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7460 /*100 kHz*/ ,0x1C ,0x38 }, {  7485 /*100 kHz*/ ,0x1C ,0x38 }, {  7510 /*100 kHz*/ ,0x1C ,0x38 }, {  7535 /*100 kHz*/ ,0x1C ,0x38 }, {  7560 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7460 /*100 kHz*/ ,0x01 ,0x06 }, {  7485 /*100 kHz*/ ,0x01 ,0x06 }, {  7510 /*100 kHz*/ ,0x01 ,0x06 }, {  7535 /*100 kHz*/ ,0x01 ,0x06 }, {  7560 /*100 kHz*/ ,0x01 ,0x06 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7460 /*100 kHz*/ ,0x1C ,0x38 }, {  7485 /*100 kHz*/ ,0x1C ,0x38 }, {  7510 /*100 kHz*/ ,0x1C ,0x38 }, {  7535 /*100 kHz*/ ,0x1C ,0x38 }, {  7560 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7460 /*100 kHz*/ ,0x01 ,0x04 }, {  7485 /*100 kHz*/ ,0x01 ,0x04 }, {  7510 /*100 kHz*/ ,0x01 ,0x04 }, {  7535 /*100 kHz*/ ,0x01 ,0x04 }, {  7560 /*100 kHz*/ ,0x01 ,0x04 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7460 /*100 kHz*/ ,0x04 ,0x00 }, {  7485 /*100 kHz*/ ,0x04 ,0x00 }, {  7510 /*100 kHz*/ ,0x04 ,0x00 }, {  7535 /*100 kHz*/ ,0x04 ,0x00 }, {  7560 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 5  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band17_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7340 /*100 kHz*/ ,0x1C ,0x38 }, {  7370 /*100 kHz*/ ,0x1C ,0x38 }, {  7400 /*100 kHz*/ ,0x1C ,0x38 }, {  7430 /*100 kHz*/ ,0x1C ,0x38 }, {  7460 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7340 /*100 kHz*/ ,0x01 ,0x01 }, {  7370 /*100 kHz*/ ,0x01 ,0x01 }, {  7400 /*100 kHz*/ ,0x01 ,0x01 }, {  7430 /*100 kHz*/ ,0x01 ,0x01 }, {  7460 /*100 kHz*/ ,0x01 ,0x01 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7340 /*100 kHz*/ ,0x1C ,0x38 }, {  7370 /*100 kHz*/ ,0x1C ,0x38 }, {  7400 /*100 kHz*/ ,0x1C ,0x38 }, {  7430 /*100 kHz*/ ,0x1C ,0x38 }, {  7460 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7340 /*100 kHz*/ ,0x01 ,0x07 }, {  7370 /*100 kHz*/ ,0x01 ,0x07 }, {  7400 /*100 kHz*/ ,0x01 ,0x07 }, {  7430 /*100 kHz*/ ,0x01 ,0x07 }, {  7460 /*100 kHz*/ ,0x01 ,0x07 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7340 /*100 kHz*/ ,0x04 ,0x00 }, {  7370 /*100 kHz*/ ,0x04 ,0x00 }, {  7400 /*100 kHz*/ ,0x04 ,0x00 }, {  7430 /*100 kHz*/ ,0x04 ,0x00 }, {  7460 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 5  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band20_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x02 ,0x01 }, {  7985 /*100 kHz*/ ,0x02 ,0x01 }, {  8060 /*100 kHz*/ ,0x02 ,0x01 }, {  8135 /*100 kHz*/ ,0x02 ,0x01 }, {  8210 /*100 kHz*/ ,0x02 ,0x01 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7910 /*100 kHz*/ ,0x00 ,0x02 }, {  7985 /*100 kHz*/ ,0x00 ,0x02 }, {  8060 /*100 kHz*/ ,0x00 ,0x02 }, {  8135 /*100 kHz*/ ,0x00 ,0x02 }, {  8210 /*100 kHz*/ ,0x00 ,0x02 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x02 ,0x00 }, {  7985 /*100 kHz*/ ,0x02 ,0x00 }, {  8060 /*100 kHz*/ ,0x02 ,0x00 }, {  8135 /*100 kHz*/ ,0x02 ,0x00 }, {  8210 /*100 kHz*/ ,0x02 ,0x00 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x04 ,0x00 }, {  7985 /*100 kHz*/ ,0x04 ,0x00 }, {  8060 /*100 kHz*/ ,0x04 ,0x00 }, {  8135 /*100 kHz*/ ,0x04 ,0x00 }, {  8210 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7910 /*100 kHz*/ ,0x00 ,0x00 }, {  7985 /*100 kHz*/ ,0x00 ,0x00 }, {  8060 /*100 kHz*/ ,0x00 ,0x00 }, {  8135 /*100 kHz*/ ,0x00 ,0x00 }, {  8210 /*100 kHz*/ ,0x00 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band26_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x02 ,0x04 }, {  8677 /*100 kHz*/ ,0x02 ,0x04 }, {  8765 /*100 kHz*/ ,0x02 ,0x04 }, {  8852 /*100 kHz*/ ,0x02 ,0x04 }, {  8940 /*100 kHz*/ ,0x02 ,0x04 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  8590 /*100 kHz*/ ,0x00 ,0x04 }, {  8677 /*100 kHz*/ ,0x00 ,0x04 }, {  8765 /*100 kHz*/ ,0x00 ,0x04 }, {  8852 /*100 kHz*/ ,0x00 ,0x04 }, {  8940 /*100 kHz*/ ,0x00 ,0x04 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x02 ,0x00 }, {  8677 /*100 kHz*/ ,0x02 ,0x00 }, {  8765 /*100 kHz*/ ,0x02 ,0x00 }, {  8852 /*100 kHz*/ ,0x02 ,0x00 }, {  8940 /*100 kHz*/ ,0x02 ,0x00 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x04 ,0x00 }, {  8677 /*100 kHz*/ ,0x04 ,0x00 }, {  8765 /*100 kHz*/ ,0x04 ,0x00 }, {  8852 /*100 kHz*/ ,0x04 ,0x00 }, {  8940 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  8590 /*100 kHz*/ ,0x00 ,0x00 }, {  8677 /*100 kHz*/ ,0x00 ,0x00 }, {  8765 /*100 kHz*/ ,0x00 ,0x00 }, {  8852 /*100 kHz*/ ,0x00 ,0x00 }, {  8940 /*100 kHz*/ ,0x00 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band28_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x02 ,0x03 }, {  7692 /*100 kHz*/ ,0x02 ,0x03 }, {  7805 /*100 kHz*/ ,0x02 ,0x05 }, {  7917 /*100 kHz*/ ,0x02 ,0x05 }, {  8030 /*100 kHz*/ ,0x02 ,0x05 },} },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7580 /*100 kHz*/ ,0x00 ,0x05 }, {  7692 /*100 kHz*/ ,0x00 ,0x05 }, {  7805 /*100 kHz*/ ,0x00 ,0x06 }, {  7917 /*100 kHz*/ ,0x00 ,0x06 }, {  8030 /*100 kHz*/ ,0x00 ,0x06 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x02 ,0x00 }, {  7692 /*100 kHz*/ ,0x02 ,0x00 }, {  7805 /*100 kHz*/ ,0x02 ,0x00 }, {  7917 /*100 kHz*/ ,0x02 ,0x00 }, {  8030 /*100 kHz*/ ,0x02 ,0x00 },} },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x04 ,0x00 }, {  7692 /*100 kHz*/ ,0x04 ,0x00 }, {  7805 /*100 kHz*/ ,0x04 ,0x00 }, {  7917 /*100 kHz*/ ,0x04 ,0x00 }, {  8030 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7580 /*100 kHz*/ ,0x00 ,0x00 }, {  7692 /*100 kHz*/ ,0x00 ,0x00 }, {  7805 /*100 kHz*/ ,0x00 ,0x00 }, {  7917 /*100 kHz*/ ,0x00 ,0x00 }, {  8030 /*100 kHz*/ ,0x00 ,0x00 },} },
   { /* 9  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band29_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7170 /*100 kHz*/ ,0x1C ,0x38 }, {  7197 /*100 kHz*/ ,0x1C ,0x38 }, {  7225 /*100 kHz*/ ,0x1C ,0x38 }, {  7252 /*100 kHz*/ ,0x1C ,0x38 }, {  7280 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7170 /*100 kHz*/ ,0x02 ,0x01 }, {  7197 /*100 kHz*/ ,0x02 ,0x01 }, {  7225 /*100 kHz*/ ,0x02 ,0x01 }, {  7252 /*100 kHz*/ ,0x02 ,0x01 }, {  7280 /*100 kHz*/ ,0x02 ,0x01 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7170 /*100 kHz*/ ,0x1C ,0x38 }, {  7197 /*100 kHz*/ ,0x1C ,0x38 }, {  7225 /*100 kHz*/ ,0x1C ,0x38 }, {  7252 /*100 kHz*/ ,0x1C ,0x38 }, {  7280 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7170 /*100 kHz*/ ,0x00 ,0x04 }, {  7197 /*100 kHz*/ ,0x00 ,0x04 }, {  7225 /*100 kHz*/ ,0x00 ,0x04 }, {  7252 /*100 kHz*/ ,0x00 ,0x04 }, {  7280 /*100 kHz*/ ,0x00 ,0x04 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7170 /*100 kHz*/ ,0x1C ,0x38 }, {  7197 /*100 kHz*/ ,0x1C ,0x38 }, {  7225 /*100 kHz*/ ,0x1C ,0x38 }, {  7252 /*100 kHz*/ ,0x1C ,0x38 }, {  7280 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7170 /*100 kHz*/ ,0x02 ,0x00 }, {  7197 /*100 kHz*/ ,0x02 ,0x00 }, {  7225 /*100 kHz*/ ,0x02 ,0x00 }, {  7252 /*100 kHz*/ ,0x02 ,0x00 }, {  7280 /*100 kHz*/ ,0x02 ,0x00 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7170 /*100 kHz*/ ,0x04 ,0x00 }, {  7197 /*100 kHz*/ ,0x04 ,0x00 }, {  7225 /*100 kHz*/ ,0x04 ,0x00 }, {  7252 /*100 kHz*/ ,0x04 ,0x00 }, {  7280 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7170 /*100 kHz*/ ,0x1C ,0x38 }, {  7197 /*100 kHz*/ ,0x1C ,0x38 }, {  7225 /*100 kHz*/ ,0x1C ,0x38 }, {  7252 /*100 kHz*/ ,0x1C ,0x38 }, {  7280 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ {  7170 /*100 kHz*/ ,0x00 ,0x00 }, {  7197 /*100 kHz*/ ,0x00 ,0x00 }, {  7225 /*100 kHz*/ ,0x00 ,0x00 }, {  7252 /*100 kHz*/ ,0x00 ,0x00 }, {  7280 /*100 kHz*/ ,0x00 ,0x00 },} },
   { /* 9  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band30_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23525 /*100 kHz*/ ,0x1C ,0x38 }, { 23550 /*100 kHz*/ ,0x1C ,0x38 }, { 23575 /*100 kHz*/ ,0x1C ,0x38 }, { 23600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23500 /*100 kHz*/ ,0x02 ,0x80 }, { 23525 /*100 kHz*/ ,0x02 ,0x80 }, { 23550 /*100 kHz*/ ,0x02 ,0x80 }, { 23575 /*100 kHz*/ ,0x02 ,0x80 }, { 23600 /*100 kHz*/ ,0x02 ,0x80 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23525 /*100 kHz*/ ,0x1C ,0x38 }, { 23550 /*100 kHz*/ ,0x1C ,0x38 }, { 23575 /*100 kHz*/ ,0x1C ,0x38 }, { 23600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 23500 /*100 kHz*/ ,0x01 ,0x05 }, { 23525 /*100 kHz*/ ,0x01 ,0x05 }, { 23550 /*100 kHz*/ ,0x01 ,0x05 }, { 23575 /*100 kHz*/ ,0x01 ,0x05 }, { 23600 /*100 kHz*/ ,0x01 ,0x05 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23525 /*100 kHz*/ ,0x1C ,0x38 }, { 23550 /*100 kHz*/ ,0x1C ,0x38 }, { 23575 /*100 kHz*/ ,0x1C ,0x38 }, { 23600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23500 /*100 kHz*/ ,0x02 ,0x00 }, { 23525 /*100 kHz*/ ,0x02 ,0x00 }, { 23550 /*100 kHz*/ ,0x02 ,0x00 }, { 23575 /*100 kHz*/ ,0x02 ,0x00 }, { 23600 /*100 kHz*/ ,0x02 ,0x00 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23500 /*100 kHz*/ ,0x04 ,0x00 }, { 23525 /*100 kHz*/ ,0x04 ,0x00 }, { 23550 /*100 kHz*/ ,0x04 ,0x00 }, { 23575 /*100 kHz*/ ,0x04 ,0x00 }, { 23600 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23525 /*100 kHz*/ ,0x1C ,0x38 }, { 23550 /*100 kHz*/ ,0x1C ,0x38 }, { 23575 /*100 kHz*/ ,0x1C ,0x38 }, { 23600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 23500 /*100 kHz*/ ,0x01 ,0x00 }, { 23525 /*100 kHz*/ ,0x01 ,0x00 }, { 23550 /*100 kHz*/ ,0x01 ,0x00 }, { 23575 /*100 kHz*/ ,0x01 ,0x00 }, { 23600 /*100 kHz*/ ,0x01 ,0x00 },} },
   { /* 9  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x03 ,0x40 }, { 25825 /*100 kHz*/ ,0x03 ,0x40 }, { 25950 /*100 kHz*/ ,0x03 ,0x40 }, { 26075 /*100 kHz*/ ,0x03 ,0x40 }, { 26200 /*100 kHz*/ ,0x03 ,0x40 },} },
   { /* 2  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 4  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_PA , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_PA , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 25700 /*100 kHz*/ ,0x02 ,0x03 }, { 25825 /*100 kHz*/ ,0x02 ,0x03 }, { 25950 /*100 kHz*/ ,0x02 ,0x03 }, { 26075 /*100 kHz*/ ,0x02 ,0x03 }, { 26200 /*100 kHz*/ ,0x02 ,0x03 },} },   
   { /* 7  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x03 ,0x00 }, { 25825 /*100 kHz*/ ,0x03 ,0x00 }, { 25950 /*100 kHz*/ ,0x03 ,0x00 }, { 26075 /*100 kHz*/ ,0x03 ,0x00 }, { 26200 /*100 kHz*/ ,0x03 ,0x00 },} },
   { /* 9  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x04 ,0x00 }, { 25825 /*100 kHz*/ ,0x04 ,0x00 }, { 25950 /*100 kHz*/ ,0x04 ,0x00 }, { 26075 /*100 kHz*/ ,0x04 ,0x00 }, { 26200 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_PA , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 25700 /*100 kHz*/ ,0x1C ,0x38 }, { 25825 /*100 kHz*/ ,0x1C ,0x38 }, { 25950 /*100 kHz*/ ,0x1C ,0x38 }, { 26075 /*100 kHz*/ ,0x1C ,0x38 }, { 26200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_PA , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 25700 /*100 kHz*/ ,0x02 ,0x00 }, { 25825 /*100 kHz*/ ,0x02 ,0x00 }, { 25950 /*100 kHz*/ ,0x02 ,0x00 }, { 26075 /*100 kHz*/ ,0x02 ,0x00 }, { 26200 /*100 kHz*/ ,0x02 ,0x00 },} },  
   { /* 19  */ LTE_MIPI_NULL, 0                , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band39_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x05 ,0x02 }, { 18900 /*100 kHz*/ ,0x05 ,0x02 }, { 19000 /*100 kHz*/ ,0x05 ,0x02 }, { 19100 /*100 kHz*/ ,0x05 ,0x02 }, { 19200 /*100 kHz*/ ,0x05 ,0x02 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18800 /*100 kHz*/ ,0x01 ,0x03 }, { 18900 /*100 kHz*/ ,0x01 ,0x03 }, { 19000 /*100 kHz*/ ,0x01 ,0x03 }, { 19100 /*100 kHz*/ ,0x01 ,0x03 }, { 19200 /*100 kHz*/ ,0x01 ,0x03 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x05 ,0x00 }, { 18900 /*100 kHz*/ ,0x05 ,0x00 }, { 19000 /*100 kHz*/ ,0x05 ,0x00 }, { 19100 /*100 kHz*/ ,0x05 ,0x00 }, { 19200 /*100 kHz*/ ,0x05 ,0x00 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x04 ,0x00 }, { 18900 /*100 kHz*/ ,0x04 ,0x00 }, { 19000 /*100 kHz*/ ,0x04 ,0x00 }, { 19100 /*100 kHz*/ ,0x04 ,0x00 }, { 19200 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18800 /*100 kHz*/ ,0x01 ,0x00 }, { 18900 /*100 kHz*/ ,0x01 ,0x00 }, { 19000 /*100 kHz*/ ,0x01 ,0x00 }, { 19100 /*100 kHz*/ ,0x01 ,0x00 }, { 19200 /*100 kHz*/ ,0x01 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x03 ,0x60 }, { 23250 /*100 kHz*/ ,0x03 ,0x60 }, { 23500 /*100 kHz*/ ,0x03 ,0x60 }, { 23750 /*100 kHz*/ ,0x03 ,0x60 }, { 24000 /*100 kHz*/ ,0x03 ,0x60 },} },
   { /* 2  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },     
   { /* 4  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_PA , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_PA , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 23000 /*100 kHz*/ ,0x02 ,0x02 }, { 23250 /*100 kHz*/ ,0x02 ,0x02 }, { 23500 /*100 kHz*/ ,0x02 ,0x02 }, { 23750 /*100 kHz*/ ,0x02 ,0x02 }, { 24000 /*100 kHz*/ ,0x02 ,0x02 },} },
   { /* 7  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x03 ,0x00 }, { 23250 /*100 kHz*/ ,0x03 ,0x00 }, { 23500 /*100 kHz*/ ,0x03 ,0x00 }, { 23750 /*100 kHz*/ ,0x03 ,0x00 }, { 24000 /*100 kHz*/ ,0x03 ,0x00 },} },
   { /* 9  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x04 ,0x00 }, { 23250 /*100 kHz*/ ,0x04 ,0x00 }, { 23500 /*100 kHz*/ ,0x04 ,0x00 }, { 23750 /*100 kHz*/ ,0x04 ,0x00 }, { 24000 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_PA , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_PA , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 23000 /*100 kHz*/ ,0x02 ,0x00 }, { 23250 /*100 kHz*/ ,0x02 ,0x00 }, { 23500 /*100 kHz*/ ,0x02 ,0x00 }, { 23750 /*100 kHz*/ ,0x02 ,0x00 }, { 24000 /*100 kHz*/ ,0x02 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x03 ,0x40 }, { 25445 /*100 kHz*/ ,0x03 ,0x40 }, { 25930 /*100 kHz*/ ,0x03 ,0x40 }, { 26415 /*100 kHz*/ ,0x03 ,0x40 }, { 26900 /*100 kHz*/ ,0x03 ,0x40 },} },
   { /* 2  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 4  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W    , MIPI_USID_PA0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 6  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W    , MIPI_USID_PA0_P3    ,{ { 24960 /*100 kHz*/ ,0x02 ,0x03 }, { 25445 /*100 kHz*/ ,0x02 ,0x03 }, { 25930 /*100 kHz*/ ,0x02 ,0x03 }, { 26415 /*100 kHz*/ ,0x02 ,0x03 }, { 26900 /*100 kHz*/ ,0x02 ,0x03 },} },
   { /* 7  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x03 ,0x00 }, { 25445 /*100 kHz*/ ,0x03 ,0x00 }, { 25930 /*100 kHz*/ ,0x03 ,0x00 }, { 26415 /*100 kHz*/ ,0x03 ,0x00 }, { 26900 /*100 kHz*/ ,0x03 ,0x00 },} },
   { /* 9  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 13  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W     ,MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x04 ,0x00 }, { 25445 /*100 kHz*/ ,0x04 ,0x00 }, { 25930 /*100 kHz*/ ,0x04 ,0x00 }, { 26415 /*100 kHz*/ ,0x04 ,0x00 }, { 26900 /*100 kHz*/ ,0x04 ,0x00 },} },
   { /* 14  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_PA , LTE_MIPI_PORT0    , LTE_REG_W    , MIPI_USID_ASM0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 17  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W    , MIPI_USID_PA0_P3    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 18  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W    , MIPI_USID_PA0_P3    ,{ { 24960 /*100 kHz*/ ,0x02 ,0x00 }, { 25445 /*100 kHz*/ ,0x02 ,0x00 }, { 25930 /*100 kHz*/ ,0x02 ,0x00 }, { 26415 /*100 kHz*/ ,0x02 ,0x00 }, { 26900 /*100 kHz*/ ,0x02 ,0x00 },} },
   { /* 19  */ LTE_MIPI_NULL, 0                 , 0             , 0               ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

kal_uint32  LTE_MIPI_RX_DATA_SIZE_TABLE_Set1[LTE_MAX_SUPPORT_FE_ROUTE_NUM] =
{
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR0,     Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR1,     Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR2,     Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR3,     Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR4,     Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR5,     Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR6,     Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR7,     Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR8,     Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR9,     Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR10,    Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR11,    Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR12,    Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR13,    Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR14,    Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR15,    Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR16,    Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR17,    Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR18,    Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR19,    Set1)),
   sizeof(LTE_MIPI_RX_DATA(      BAND_INDICATOR20,    Set1)),
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND21, Set1)),     /*Index 0*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND22, Set1)),     /*Index 1*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND23, Set1)),     /*Index 2*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND24, Set1)),     /*Index 3*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND25, Set1)),     /*Index 4*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND26, Set1)),     /*Index 5*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND27, Set1)),     /*Index 6*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND28, Set1)),     /*Index 7*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND29, Set1)),     /*Index 8*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND30, Set1)),     /*Index 9*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND31, Set1)),     /*Index10*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND32, Set1)),     /*Index11*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND33, Set1)),     /*Index12*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND34, Set1)),     /*Index13*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND35, Set1)),     /*Index14*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND36, Set1)),     /*Index15*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND37, Set1)),     /*Index16*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND38, Set1)),     /*Index17*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND39, Set1)),     /*Index18*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND40, Set1)),     /*Index19*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND41, Set1)),     /*Index20*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND42, Set1)),     /*Index21*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND43, Set1)),     /*Index22*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND44, Set1)),     /*Index23*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND45, Set1)),     /*Index24*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND46, Set1)),     /*Index25*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND47, Set1)),     /*Index26*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND48, Set1)),     /*Index27*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND49, Set1)),     /*Index28*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND50, Set1)),     /*Index29*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND51, Set1)),     /*Index30*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND52, Set1)),     /*Index31*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND53, Set1)),     /*Index32*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND54, Set1)),     /*Index33*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND55, Set1)),     /*Index34*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND56, Set1)),     /*Index35*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND57, Set1)),     /*Index36*/
   sizeof(LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND58, Set1)),     /*Index37*/
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_RX_DATA_TABLE_Set1[LTE_MAX_SUPPORT_FE_ROUTE_NUM] =
{
   LTE_MIPI_RX_DATA(      BAND_INDICATOR0,     Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR1,     Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR2,     Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR3,     Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR4,     Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR5,     Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR6,     Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR7,     Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR8,     Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR9,     Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR10,    Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR11,    Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR12,    Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR13,    Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR14,    Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR15,    Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR16,    Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR17,    Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR18,    Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR19,    Set1),
   LTE_MIPI_RX_DATA(      BAND_INDICATOR20,    Set1),
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND21, Set1),     /*Index 0*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND22, Set1),     /*Index 1*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND23, Set1),     /*Index 2*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND24, Set1),     /*Index 3*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND25, Set1),     /*Index 4*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND26, Set1),     /*Index 5*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND27, Set1),     /*Index 6*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND28, Set1),     /*Index 7*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND29, Set1),     /*Index 8*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND30, Set1),     /*Index 9*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND31, Set1),     /*Index10*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND32, Set1),     /*Index11*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND33, Set1),     /*Index12*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND34, Set1),     /*Index13*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND35, Set1),     /*Index14*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND36, Set1),     /*Index15*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND37, Set1),     /*Index16*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND38, Set1),     /*Index17*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND39, Set1),     /*Index18*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND40, Set1),     /*Index19*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND41, Set1),     /*Index20*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND42, Set1),     /*Index21*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND43, Set1),     /*Index22*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND44, Set1),     /*Index23*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND45, Set1),     /*Index24*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND46, Set1),     /*Index25*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND47, Set1),     /*Index26*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND48, Set1),     /*Index27*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND49, Set1),     /*Index28*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND50, Set1),     /*Index29*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND51, Set1),     /*Index30*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND52, Set1),     /*Index31*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND53, Set1),     /*Index32*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND54, Set1),     /*Index33*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND55, Set1),     /*Index34*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND56, Set1),     /*Index35*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND57, Set1),     /*Index36*/
   LTE_MIPI_RX_DATA_ROUTE(MIPI_RX_ROUTE_IND58, Set1),     /*Index37*/
};
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band2_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band4_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band5_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band12_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 8    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band13_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 8    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 8    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band20_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band26_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band30_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 8    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM  , { 0    , 11    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_ASM  , { 12    , 12    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

kal_uint32  LTE_MIPI_TX_EVENT_SIZE_TABLE_Set1[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR0,  Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR1,  Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR2,  Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR3,  Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR4,  Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR5,  Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR6,  Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR7,  Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR8,  Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR9,  Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR10, Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR11, Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR12, Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR13, Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR14, Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR15, Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR16, Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR17, Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR18, Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR19, Set1)),
   sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR20, Set1)),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TX_EVENT_TABLE_Set1[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   LTE_MIPI_TX_EVENT(BAND_INDICATOR0,  Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR1,  Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR2,  Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR3,  Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR4,  Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR5,  Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR6,  Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR7,  Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR8,  Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR9,  Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR10, Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR11, Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR12, Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR13, Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR14, Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR15, Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR16, Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR17, Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR18, Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR19, Set1),
   LTE_MIPI_TX_EVENT(BAND_INDICATOR20, Set1),
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    , 0   }, {     0 /*100 kHz*/ ,0    , 0   }, {     0 /*100 kHz*/ ,0    , 0   }, {     0 /*100 kHz*/ ,0    , 0   }, {     0 /*100 kHz*/ ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band1_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0   */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1   */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 19200 /*100 kHz*/    ,0x00 , 0x2C}, { 19350 /*100 kHz*/    ,0x00 , 0x2C}, { 19500 /*100 kHz*/    ,0x00 , 0x2C}, { 19650 /*100 kHz*/    ,0x00 , 0x2C}, { 19800 /*100 kHz*/    ,0x00 , 0x2C},} }, // PA path sel
   { /* 2   */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 19200 /*100 kHz*/    ,0x01 , 0x00}, { 19350 /*100 kHz*/    ,0x01 , 0x00}, { 19500 /*100 kHz*/    ,0x01 , 0x00}, { 19650 /*100 kHz*/    ,0x01 , 0x00}, { 19800 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable
   { /* 3   */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 19200 /*100 kHz*/    ,0x02 , 0x00}, { 19350 /*100 kHz*/    ,0x02 , 0x00}, { 19500 /*100 kHz*/    ,0x02 , 0x00}, { 19650 /*100 kHz*/    ,0x02 , 0x00}, { 19800 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4   */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 19200 /*100 kHz*/    ,0x03 , 0x00}, { 19350 /*100 kHz*/    ,0x03 , 0x00}, { 19500 /*100 kHz*/    ,0x03 , 0x00}, { 19650 /*100 kHz*/    ,0x03 , 0x00}, { 19800 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5   */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 19200 /*100 kHz*/    ,0x00 , 0x00}, { 19350 /*100 kHz*/    ,0x00 , 0x00}, { 19500 /*100 kHz*/    ,0x00 , 0x00}, { 19650 /*100 kHz*/    ,0x01 , 0x00}, { 19800 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable
   { /* 6   */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7   */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19200 /*100 kHz*/    ,0x04 , 0x13}, { 19350 /*100 kHz*/    ,0x04 , 0x13}, { 19500 /*100 kHz*/    ,0x04 , 0x13}, { 19650 /*100 kHz*/    ,0x04 , 0x13}, { 19800 /*100 kHz*/    ,0x04 , 0x13},} }, // ASM PM_Trig: normal mode
   { /* 8   */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} },   
   { /* 9   */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} },   
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} },  
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} },   
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19200 /*100 kHz*/    ,0x05 , 0x03}, { 19350 /*100 kHz*/    ,0x05 , 0x03}, { 19500 /*100 kHz*/    ,0x05 , 0x03}, { 19650 /*100 kHz*/    ,0x05 , 0x03}, { 19800 /*100 kHz*/    ,0x05 , 0x03},} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} },        
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band2_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 18500 /*100 kHz*/ ,0x1C ,0x38 }, { 18650 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18950 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 },} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 18500 /*100 kHz*/ ,0x00 ,0x2C }, { 18650 /*100 kHz*/ ,0x00 ,0x2C }, { 18800 /*100 kHz*/ ,0x00 ,0x2C }, { 18950 /*100 kHz*/ ,0x00 ,0x2C }, { 19100 /*100 kHz*/ ,0x00 ,0x2C },} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 18500 /*100 kHz*/ ,0x01 ,0x00 }, { 18650 /*100 kHz*/ ,0x01 ,0x00 }, { 18800 /*100 kHz*/ ,0x01 ,0x00 }, { 18950 /*100 kHz*/ ,0x01 ,0x00 }, { 19100 /*100 kHz*/ ,0x01 ,0x00 },} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 18500 /*100 kHz*/ ,0x02 ,0x00 }, { 18650 /*100 kHz*/ ,0x02 ,0x00 }, { 18800 /*100 kHz*/ ,0x02 ,0x00 }, { 18950 /*100 kHz*/ ,0x02 ,0x00 }, { 19100 /*100 kHz*/ ,0x02 ,0x00 },} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 18500 /*100 kHz*/ ,0x03 ,0x00 }, { 18650 /*100 kHz*/ ,0x03 ,0x00 }, { 18800 /*100 kHz*/ ,0x03 ,0x00 }, { 18950 /*100 kHz*/ ,0x03 ,0x00 }, { 19100 /*100 kHz*/ ,0x03 ,0x00 },} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 18500 /*100 kHz*/ ,0x00 ,0x00 }, { 18650 /*100 kHz*/ ,0x00 ,0x00 }, { 18800 /*100 kHz*/ ,0x00 ,0x00 }, { 18950 /*100 kHz*/ ,0x00 ,0x00 }, { 19100 /*100 kHz*/ ,0x00 ,0x00 },} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18500 /*100 kHz*/ ,0x1C ,0x38 }, { 18650 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18950 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 },} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18500 /*100 kHz*/ ,0x04 ,0x13 }, { 18650 /*100 kHz*/ ,0x04 ,0x13 }, { 18800 /*100 kHz*/ ,0x04 ,0x13 }, { 18950 /*100 kHz*/ ,0x04 ,0x13 }, { 19100 /*100 kHz*/ ,0x04 ,0x13 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18500 /*100 kHz*/ ,0x1C ,0x38 }, { 18650 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18950 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18500 /*100 kHz*/ ,0x1C ,0x38 }, { 18650 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18950 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18500 /*100 kHz*/ ,0x1C ,0x38 }, { 18650 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18950 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18500 /*100 kHz*/ ,0x1C ,0x38 }, { 18650 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18950 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18500 /*100 kHz*/ ,0x05 ,0x05 }, { 18650 /*100 kHz*/ ,0x05 ,0x05 }, { 18800 /*100 kHz*/ ,0x05 ,0x05 }, { 18950 /*100 kHz*/ ,0x05 ,0x05 }, { 19100 /*100 kHz*/ ,0x05 ,0x05 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18500 /*100 kHz*/ ,0x1C ,0x38 }, { 18650 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18950 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18500 /*100 kHz*/ ,0x1C ,0x38 }, { 18650 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18950 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18500 /*100 kHz*/ ,0x1C ,0x38 }, { 18650 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18950 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band3_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/    ,0x00 , 0x24}, { 17287 /*100 kHz*/    ,0x00 , 0x24}, { 17475 /*100 kHz*/    ,0x00 , 0x24}, { 17662 /*100 kHz*/    ,0x00 , 0x24}, { 17850 /*100 kHz*/    ,0x00 , 0x24},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/    ,0x01 , 0x00}, { 17287 /*100 kHz*/    ,0x01 , 0x00}, { 17475 /*100 kHz*/    ,0x01 , 0x00}, { 17662 /*100 kHz*/    ,0x01 , 0x00}, { 17850 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/    ,0x02 , 0x00}, { 17287 /*100 kHz*/    ,0x02 , 0x00}, { 17475 /*100 kHz*/    ,0x02 , 0x00}, { 17662 /*100 kHz*/    ,0x02 , 0x00}, { 17850 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/    ,0x03 , 0x00}, { 17287 /*100 kHz*/    ,0x03 , 0x00}, { 17475 /*100 kHz*/    ,0x03 , 0x00}, { 17662 /*100 kHz*/    ,0x03 , 0x00}, { 17850 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/    ,0x00 , 0x00}, { 17287 /*100 kHz*/    ,0x00 , 0x00}, { 17475 /*100 kHz*/    ,0x00 , 0x00}, { 17662 /*100 kHz*/    ,0x00 , 0x00}, { 17850 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/    ,0x04 , 0x13}, { 17287 /*100 kHz*/    ,0x04 , 0x13}, { 17475 /*100 kHz*/    ,0x04 , 0x13}, { 17662 /*100 kHz*/    ,0x04 , 0x13}, { 17850 /*100 kHz*/    ,0x04 , 0x13},} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/    ,0x05 , 0x03}, { 17287 /*100 kHz*/    ,0x05 , 0x03}, { 17475 /*100 kHz*/    ,0x05 , 0x03}, { 17662 /*100 kHz*/    ,0x05 , 0x03}, { 17850 /*100 kHz*/    ,0x05 , 0x03},} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band4_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17212 /*100 kHz*/ ,0x1C ,0x38 }, { 17325 /*100 kHz*/ ,0x1C ,0x38 }, { 17437 /*100 kHz*/ ,0x1C ,0x38 }, { 17550 /*100 kHz*/ ,0x1C ,0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/ ,0x00 ,0x2C }, { 17212 /*100 kHz*/ ,0x00 ,0x2C }, { 17325 /*100 kHz*/ ,0x00 ,0x2C }, { 17437 /*100 kHz*/ ,0x00 ,0x2C }, { 17550 /*100 kHz*/ ,0x00 ,0x2C},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/ ,0x01 ,0x00 }, { 17212 /*100 kHz*/ ,0x01 ,0x00 }, { 17325 /*100 kHz*/ ,0x01 ,0x00 }, { 17437 /*100 kHz*/ ,0x01 ,0x00 }, { 17550 /*100 kHz*/ ,0x01 ,0x00},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/ ,0x02 ,0x00 }, { 17212 /*100 kHz*/ ,0x02 ,0x00 }, { 17325 /*100 kHz*/ ,0x02 ,0x00 }, { 17437 /*100 kHz*/ ,0x02 ,0x00 }, { 17550 /*100 kHz*/ ,0x02 ,0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/ ,0x03 ,0x00 }, { 17212 /*100 kHz*/ ,0x03 ,0x00 }, { 17325 /*100 kHz*/ ,0x03 ,0x00 }, { 17437 /*100 kHz*/ ,0x03 ,0x00 }, { 17550 /*100 kHz*/ ,0x03 ,0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 17100 /*100 kHz*/ ,0x00 ,0x00 }, { 17212 /*100 kHz*/ ,0x00 ,0x00 }, { 17325 /*100 kHz*/ ,0x00 ,0x00 }, { 17437 /*100 kHz*/ ,0x00 ,0x00 }, { 17550 /*100 kHz*/ ,0x00 ,0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17212 /*100 kHz*/ ,0x1C ,0x38 }, { 17325 /*100 kHz*/ ,0x1C ,0x38 }, { 17437 /*100 kHz*/ ,0x1C ,0x38 }, { 17550 /*100 kHz*/ ,0x1C ,0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/ ,0x04 ,0x13 }, { 17212 /*100 kHz*/ ,0x04 ,0x13 }, { 17325 /*100 kHz*/ ,0x04 ,0x13 }, { 17437 /*100 kHz*/ ,0x04 ,0x13 }, { 17550 /*100 kHz*/ ,0x04 ,0x13},} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17212 /*100 kHz*/ ,0x1C ,0x38 }, { 17325 /*100 kHz*/ ,0x1C ,0x38 }, { 17437 /*100 kHz*/ ,0x1C ,0x38 }, { 17550 /*100 kHz*/ ,0x1C ,0x38},} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17212 /*100 kHz*/ ,0x1C ,0x38 }, { 17325 /*100 kHz*/ ,0x1C ,0x38 }, { 17437 /*100 kHz*/ ,0x1C ,0x38 }, { 17550 /*100 kHz*/ ,0x1C ,0x38},} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17212 /*100 kHz*/ ,0x1C ,0x38 }, { 17325 /*100 kHz*/ ,0x1C ,0x38 }, { 17437 /*100 kHz*/ ,0x1C ,0x38 }, { 17550 /*100 kHz*/ ,0x1C ,0x38},} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17212 /*100 kHz*/ ,0x1C ,0x38 }, { 17325 /*100 kHz*/ ,0x1C ,0x38 }, { 17437 /*100 kHz*/ ,0x1C ,0x38 }, { 17550 /*100 kHz*/ ,0x1C ,0x38},} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/ ,0x05 ,0x05 }, { 17212 /*100 kHz*/ ,0x05 ,0x05 }, { 17325 /*100 kHz*/ ,0x05 ,0x05 }, { 17437 /*100 kHz*/ ,0x05 ,0x05 }, { 17550 /*100 kHz*/ ,0x05 ,0x05},} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17212 /*100 kHz*/ ,0x1C ,0x38 }, { 17325 /*100 kHz*/ ,0x1C ,0x38 }, { 17437 /*100 kHz*/ ,0x1C ,0x38 }, { 17550 /*100 kHz*/ ,0x1C ,0x38},} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17212 /*100 kHz*/ ,0x1C ,0x38 }, { 17325 /*100 kHz*/ ,0x1C ,0x38 }, { 17437 /*100 kHz*/ ,0x1C ,0x38 }, { 17550 /*100 kHz*/ ,0x1C ,0x38},} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17212 /*100 kHz*/ ,0x1C ,0x38 }, { 17325 /*100 kHz*/ ,0x1C ,0x38 }, { 17437 /*100 kHz*/ ,0x1C ,0x38 }, { 17550 /*100 kHz*/ ,0x1C ,0x38},} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band5_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ { 8240  /*100 kHz*/    ,0x1C , 0x38}, { 8302  /*100 kHz*/    ,0x1C , 0x38}, { 8365  /*100 kHz*/    ,0x1C , 0x38}, { 8427  /*100 kHz*/    ,0x1C , 0x38}, { 8490  /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ { 8240  /*100 kHz*/    ,0x00 , 0x94}, { 8302  /*100 kHz*/    ,0x00 , 0x94}, { 8365  /*100 kHz*/    ,0x00 , 0x94}, { 8427  /*100 kHz*/    ,0x00 , 0x94}, { 8490  /*100 kHz*/    ,0x00 , 0x94},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ { 8240  /*100 kHz*/    ,0x01 , 0x00}, { 8302  /*100 kHz*/    ,0x01 , 0x00}, { 8365  /*100 kHz*/    ,0x01 , 0x00}, { 8427  /*100 kHz*/    ,0x01 , 0x00}, { 8490  /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ { 8240  /*100 kHz*/    ,0x02 , 0x00}, { 8302  /*100 kHz*/    ,0x02 , 0x00}, { 8365  /*100 kHz*/    ,0x02 , 0x00}, { 8427  /*100 kHz*/    ,0x02 , 0x00}, { 8490  /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ { 8240  /*100 kHz*/    ,0x03 , 0x00}, { 8302  /*100 kHz*/    ,0x03 , 0x00}, { 8365  /*100 kHz*/    ,0x03 , 0x00}, { 8427  /*100 kHz*/    ,0x03 , 0x00}, { 8490  /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ { 8240  /*100 kHz*/    ,0x00 , 0x00}, { 8302  /*100 kHz*/    ,0x00 , 0x00}, { 8365  /*100 kHz*/    ,0x00 , 0x00}, { 8427  /*100 kHz*/    ,0x00 , 0x00}, { 8490  /*100 kHz*/    ,0x00 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 8240  /*100 kHz*/    ,0x1C , 0x38}, { 8302  /*100 kHz*/    ,0x1C , 0x38}, { 8365  /*100 kHz*/    ,0x1C , 0x38}, { 8427  /*100 kHz*/    ,0x1C , 0x38}, { 8490  /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 8240  /*100 kHz*/    ,0x04 , 0x0B}, { 8302  /*100 kHz*/    ,0x04 , 0x0B}, { 8365  /*100 kHz*/    ,0x04 , 0x0B}, { 8427  /*100 kHz*/    ,0x04 , 0x0B}, { 8490  /*100 kHz*/    ,0x04 , 0x0B},} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 8240  /*100 kHz*/    ,0x1C , 0x38}, { 8302  /*100 kHz*/    ,0x1C , 0x38}, { 8365  /*100 kHz*/    ,0x1C , 0x38}, { 8427  /*100 kHz*/    ,0x1C , 0x38}, { 8490  /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 8240  /*100 kHz*/    ,0x1C , 0x38}, { 8302  /*100 kHz*/    ,0x1C , 0x38}, { 8365  /*100 kHz*/    ,0x1C , 0x38}, { 8427  /*100 kHz*/    ,0x1C , 0x38}, { 8490  /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 8240  /*100 kHz*/    ,0x1C , 0x38}, { 8302  /*100 kHz*/    ,0x1C , 0x38}, { 8365  /*100 kHz*/    ,0x1C , 0x38}, { 8427  /*100 kHz*/    ,0x1C , 0x38}, { 8490  /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 8240  /*100 kHz*/    ,0x1C , 0x38}, { 8302  /*100 kHz*/    ,0x1C , 0x38}, { 8365  /*100 kHz*/    ,0x1C , 0x38}, { 8427  /*100 kHz*/    ,0x1C , 0x38}, { 8490  /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 8240  /*100 kHz*/    ,0x02 , 0x04}, { 8302  /*100 kHz*/    ,0x02 , 0x04}, { 8365  /*100 kHz*/    ,0x02 , 0x04}, { 8427  /*100 kHz*/    ,0x02 , 0x04}, { 8490  /*100 kHz*/    ,0x02 , 0x04},} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 8240  /*100 kHz*/    ,0x1C , 0x38}, { 8302  /*100 kHz*/    ,0x1C , 0x38}, { 8365  /*100 kHz*/    ,0x1C , 0x38}, { 8427  /*100 kHz*/    ,0x1C , 0x38}, { 8490  /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 8240  /*100 kHz*/    ,0x1C , 0x38}, { 8302  /*100 kHz*/    ,0x1C , 0x38}, { 8365  /*100 kHz*/    ,0x1C , 0x38}, { 8427  /*100 kHz*/    ,0x1C , 0x38}, { 8490  /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 8240  /*100 kHz*/    ,0x1C , 0x38}, { 8302  /*100 kHz*/    ,0x1C , 0x38}, { 8365  /*100 kHz*/    ,0x1C , 0x38}, { 8427  /*100 kHz*/    ,0x1C , 0x38}, { 8490  /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band7_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25000 /*100 kHz*/    ,0x00 , 0x4C}, { 25175 /*100 kHz*/    ,0x00 , 0x4C}, { 25350 /*100 kHz*/    ,0x00 , 0x4C}, { 25525 /*100 kHz*/    ,0x00 , 0x4C}, { 25700 /*100 kHz*/    ,0x00 , 0x4C},} }, // PA band,PA Enable,PA Mode               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25000 /*100 kHz*/    ,0x01 , 0x00}, { 25175 /*100 kHz*/    ,0x01 , 0x00}, { 25350 /*100 kHz*/    ,0x01 , 0x00}, { 25525 /*100 kHz*/    ,0x01 , 0x00}, { 25700 /*100 kHz*/    ,0x01 , 0x00},} }, // PA bias current,stage2,1                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25000 /*100 kHz*/    ,0x02 , 0x00}, { 25175 /*100 kHz*/    ,0x02 , 0x00}, { 25350 /*100 kHz*/    ,0x02 , 0x00}, { 25525 /*100 kHz*/    ,0x02 , 0x00}, { 25700 /*100 kHz*/    ,0x02 , 0x00},} }, // PA switch                 
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25000 /*100 kHz*/    ,0x03 , 0x00}, { 25175 /*100 kHz*/    ,0x03 , 0x00}, { 25350 /*100 kHz*/    ,0x03 , 0x00}, { 25525 /*100 kHz*/    ,0x03 , 0x00}, { 25700 /*100 kHz*/    ,0x03 , 0x00},} }, // PA boost bias                 
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25000 /*100 kHz*/    ,0x00 , 0x00}, { 25175 /*100 kHz*/    ,0x00 , 0x00}, { 25350 /*100 kHz*/    ,0x00 , 0x00}, { 25525 /*100 kHz*/    ,0x00 , 0x00}, { 25700 /*100 kHz*/    ,0x00 , 0x00},} }, // PA disable                 
   { /* 6  */ LTE_MIPI_ASM  , LTE_MIPI_PORT0   , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM Initial                 
   { /* 7  */ LTE_MIPI_ASM  , LTE_MIPI_PORT0   , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25000 /*100 kHz*/    ,0x04 , 0x19}, { 25175 /*100 kHz*/    ,0x04 , 0x19}, { 25350 /*100 kHz*/    ,0x04 , 0x19}, { 25525 /*100 kHz*/    ,0x04 , 0x19}, { 25700 /*100 kHz*/    ,0x04 , 0x19},} }, // ASM Path select     
   { /* 8  */ LTE_MIPI_ASM  , LTE_MIPI_PORT0   , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 9  */ LTE_MIPI_ASM  , LTE_MIPI_PORT0   , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 10  */ LTE_MIPI_ASM  , LTE_MIPI_PORT0   , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 11  */ LTE_MIPI_ASM  , LTE_MIPI_PORT0   , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} },            
   { /* 12  */ LTE_MIPI_ASM  , LTE_MIPI_PORT0   , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25000 /*100 kHz*/    ,0x03 , 0x80}, { 25175 /*100 kHz*/    ,0x03 , 0x80}, { 25350 /*100 kHz*/    ,0x03 , 0x80}, { 25525 /*100 kHz*/    ,0x03 , 0x80}, { 25700 /*100 kHz*/    ,0x03 , 0x80},} },
   { /* 13  */ LTE_MIPI_ASM  , LTE_MIPI_PORT0   , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 14  */ LTE_MIPI_ASM  , LTE_MIPI_PORT0   , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 15  */ LTE_MIPI_ASM  , LTE_MIPI_PORT0   , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0               ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band8_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8800 /*100 kHz*/ ,0x1C ,0x38 }, {  8887 /*100 kHz*/ ,0x1C ,0x38 }, {  8975 /*100 kHz*/ ,0x1C ,0x38 }, {  9062 /*100 kHz*/ ,0x1C ,0x38 }, {  9150 /*100 kHz*/ ,0x1C ,0x38 },} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8800 /*100 kHz*/ ,0x00 ,0x94 }, {  8887 /*100 kHz*/ ,0x00 ,0x94 }, {  8975 /*100 kHz*/ ,0x00 ,0x94 }, {  9062 /*100 kHz*/ ,0x00 ,0x94 }, {  9150 /*100 kHz*/ ,0x00 ,0x94 },} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8800 /*100 kHz*/ ,0x01 ,0x00 }, {  8887 /*100 kHz*/ ,0x01 ,0x00 }, {  8975 /*100 kHz*/ ,0x01 ,0x00 }, {  9062 /*100 kHz*/ ,0x01 ,0x00 }, {  9150 /*100 kHz*/ ,0x01 ,0x00 },} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8800 /*100 kHz*/ ,0x02 ,0x00 }, {  8887 /*100 kHz*/ ,0x02 ,0x00 }, {  8975 /*100 kHz*/ ,0x02 ,0x00 }, {  9062 /*100 kHz*/ ,0x02 ,0x00 }, {  9150 /*100 kHz*/ ,0x02 ,0x00 },} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8800 /*100 kHz*/ ,0x03 ,0x00 }, {  8887 /*100 kHz*/ ,0x03 ,0x00 }, {  8975 /*100 kHz*/ ,0x03 ,0x00 }, {  9062 /*100 kHz*/ ,0x03 ,0x00 }, {  9150 /*100 kHz*/ ,0x03 ,0x00 },} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8800 /*100 kHz*/ ,0x00 ,0x00 }, {  8887 /*100 kHz*/ ,0x00 ,0x00 }, {  8975 /*100 kHz*/ ,0x00 ,0x00 }, {  9062 /*100 kHz*/ ,0x00 ,0x00 }, {  9150 /*100 kHz*/ ,0x00 ,0x00 },} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8800 /*100 kHz*/ ,0x1C ,0x38 }, {  8887 /*100 kHz*/ ,0x1C ,0x38 }, {  8975 /*100 kHz*/ ,0x1C ,0x38 }, {  9062 /*100 kHz*/ ,0x1C ,0x38 }, {  9150 /*100 kHz*/ ,0x1C ,0x38 },} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8800 /*100 kHz*/ ,0x04 ,0x0B }, {  8887 /*100 kHz*/ ,0x04 ,0x0B }, {  8975 /*100 kHz*/ ,0x04 ,0x0B }, {  9062 /*100 kHz*/ ,0x04 ,0x0B }, {  9150 /*100 kHz*/ ,0x04 ,0x0B },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8800 /*100 kHz*/ ,0x1C ,0x38 }, {  8887 /*100 kHz*/ ,0x1C ,0x38 }, {  8975 /*100 kHz*/ ,0x1C ,0x38 }, {  9062 /*100 kHz*/ ,0x1C ,0x38 }, {  9150 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8800 /*100 kHz*/ ,0x1C ,0x38 }, {  8887 /*100 kHz*/ ,0x1C ,0x38 }, {  8975 /*100 kHz*/ ,0x1C ,0x38 }, {  9062 /*100 kHz*/ ,0x1C ,0x38 }, {  9150 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8800 /*100 kHz*/ ,0x1C ,0x38 }, {  8887 /*100 kHz*/ ,0x1C ,0x38 }, {  8975 /*100 kHz*/ ,0x1C ,0x38 }, {  9062 /*100 kHz*/ ,0x1C ,0x38 }, {  9150 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8800 /*100 kHz*/ ,0x1C ,0x38 }, {  8887 /*100 kHz*/ ,0x1C ,0x38 }, {  8975 /*100 kHz*/ ,0x1C ,0x38 }, {  9062 /*100 kHz*/ ,0x1C ,0x38 }, {  9150 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8800 /*100 kHz*/ ,0x02 ,0x02 }, {  8887 /*100 kHz*/ ,0x02 ,0x02 }, {  8975 /*100 kHz*/ ,0x02 ,0x02 }, {  9062 /*100 kHz*/ ,0x02 ,0x02 }, {  9150 /*100 kHz*/ ,0x02 ,0x02 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8800 /*100 kHz*/ ,0x1C ,0x38 }, {  8887 /*100 kHz*/ ,0x1C ,0x38 }, {  8975 /*100 kHz*/ ,0x1C ,0x38 }, {  9062 /*100 kHz*/ ,0x1C ,0x38 }, {  9150 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8800 /*100 kHz*/ ,0x1C ,0x38 }, {  8887 /*100 kHz*/ ,0x1C ,0x38 }, {  8975 /*100 kHz*/ ,0x1C ,0x38 }, {  9062 /*100 kHz*/ ,0x1C ,0x38 }, {  9150 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8800 /*100 kHz*/ ,0x1C ,0x38 }, {  8887 /*100 kHz*/ ,0x1C ,0x38 }, {  8975 /*100 kHz*/ ,0x1C ,0x38 }, {  9062 /*100 kHz*/ ,0x1C ,0x38 }, {  9150 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band12_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  6990 /*100 kHz*/ ,0x1C ,0x38 }, {  7032 /*100 kHz*/ ,0x1C ,0x38 }, {  7075 /*100 kHz*/ ,0x1C ,0x38 }, {  7117 /*100 kHz*/ ,0x1C ,0x38 }, {  7160 /*100 kHz*/ ,0x1C ,0x38 },} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  6990 /*100 kHz*/ ,0x00 ,0x76 }, {  7032 /*100 kHz*/ ,0x00 ,0x76 }, {  7075 /*100 kHz*/ ,0x00 ,0x76 }, {  7117 /*100 kHz*/ ,0x00 ,0x76 }, {  7160 /*100 kHz*/ ,0x00 ,0x76 },} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  6990 /*100 kHz*/ ,0x01 ,0x00 }, {  7032 /*100 kHz*/ ,0x01 ,0x00 }, {  7075 /*100 kHz*/ ,0x01 ,0x00 }, {  7117 /*100 kHz*/ ,0x01 ,0x00 }, {  7160 /*100 kHz*/ ,0x01 ,0x00 },} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  6990 /*100 kHz*/ ,0x02 ,0x60 }, {  7032 /*100 kHz*/ ,0x02 ,0x60 }, {  7075 /*100 kHz*/ ,0x02 ,0x60 }, {  7117 /*100 kHz*/ ,0x02 ,0x60 }, {  7160 /*100 kHz*/ ,0x02 ,0x60 },} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  6990 /*100 kHz*/ ,0x03 ,0x00 }, {  7032 /*100 kHz*/ ,0x03 ,0x00 }, {  7075 /*100 kHz*/ ,0x03 ,0x00 }, {  7117 /*100 kHz*/ ,0x03 ,0x00 }, {  7160 /*100 kHz*/ ,0x03 ,0x00 },} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  6990 /*100 kHz*/ ,0x00 ,0x00 }, {  7032 /*100 kHz*/ ,0x00 ,0x00 }, {  7075 /*100 kHz*/ ,0x00 ,0x00 }, {  7117 /*100 kHz*/ ,0x00 ,0x00 }, {  7160 /*100 kHz*/ ,0x00 ,0x00 },} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  6990 /*100 kHz*/ ,0x1C ,0x38 }, {  7032 /*100 kHz*/ ,0x1C ,0x38 }, {  7075 /*100 kHz*/ ,0x1C ,0x38 }, {  7117 /*100 kHz*/ ,0x1C ,0x38 }, {  7160 /*100 kHz*/ ,0x1C ,0x38 },} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  6990 /*100 kHz*/ ,0x02 ,0x07 }, {  7032 /*100 kHz*/ ,0x02 ,0x07 }, {  7075 /*100 kHz*/ ,0x02 ,0x07 }, {  7117 /*100 kHz*/ ,0x02 ,0x07 }, {  7160 /*100 kHz*/ ,0x02 ,0x07 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  6990 /*100 kHz*/ ,0x04 ,0x0B }, {  7032 /*100 kHz*/ ,0x04 ,0x0B }, {  7075 /*100 kHz*/ ,0x04 ,0x0B }, {  7117 /*100 kHz*/ ,0x04 ,0x0B }, {  7160 /*100 kHz*/ ,0x04 ,0x0B },} },
   { /* 9  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band13_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7770 /*100 kHz*/ ,0x1C ,0x38 }, {  7795 /*100 kHz*/ ,0x1C ,0x38 }, {  7820 /*100 kHz*/ ,0x1C ,0x38 }, {  7845 /*100 kHz*/ ,0x1C ,0x38 }, {  7870 /*100 kHz*/ ,0x1C ,0x38 },} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7770 /*100 kHz*/ ,0x00 ,0x04 }, {  7795 /*100 kHz*/ ,0x00 ,0x04 }, {  7820 /*100 kHz*/ ,0x00 ,0x04 }, {  7845 /*100 kHz*/ ,0x00 ,0x04 }, {  7870 /*100 kHz*/ ,0x00 ,0x04 },} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7770 /*100 kHz*/ ,0x01 ,0x0F }, {  7795 /*100 kHz*/ ,0x01 ,0x0F }, {  7820 /*100 kHz*/ ,0x01 ,0x0F }, {  7845 /*100 kHz*/ ,0x01 ,0x0F }, {  7870 /*100 kHz*/ ,0x01 ,0x0F },} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7770 /*100 kHz*/ ,0x02 ,0x57 }, {  7795 /*100 kHz*/ ,0x02 ,0x57 }, {  7820 /*100 kHz*/ ,0x02 ,0x57 }, {  7845 /*100 kHz*/ ,0x02 ,0x57 }, {  7870 /*100 kHz*/ ,0x02 ,0x57 },} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7770 /*100 kHz*/ ,0x03 ,0x14 }, {  7795 /*100 kHz*/ ,0x03 ,0x14 }, {  7820 /*100 kHz*/ ,0x03 ,0x14 }, {  7845 /*100 kHz*/ ,0x03 ,0x14 }, {  7870 /*100 kHz*/ ,0x03 ,0x14 },} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7770 /*100 kHz*/ ,0x01 ,0x00 }, {  7795 /*100 kHz*/ ,0x01 ,0x00 }, {  7820 /*100 kHz*/ ,0x01 ,0x00 }, {  7845 /*100 kHz*/ ,0x01 ,0x00 }, {  7870 /*100 kHz*/ ,0x01 ,0x00 },} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7770 /*100 kHz*/ ,0x1C ,0x38 }, {  7795 /*100 kHz*/ ,0x1C ,0x38 }, {  7820 /*100 kHz*/ ,0x1C ,0x38 }, {  7845 /*100 kHz*/ ,0x1C ,0x38 }, {  7870 /*100 kHz*/ ,0x1C ,0x38 },} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7770 /*100 kHz*/ ,0x04 ,0x0B }, {  7795 /*100 kHz*/ ,0x04 ,0x0B }, {  7820 /*100 kHz*/ ,0x04 ,0x0B }, {  7845 /*100 kHz*/ ,0x04 ,0x0B }, {  7870 /*100 kHz*/ ,0x04 ,0x0B },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band17_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7040 /*100 kHz*/ ,0x1C ,0x38 }, {  7070 /*100 kHz*/ ,0x1C ,0x38 }, {  7100 /*100 kHz*/ ,0x1C ,0x38 }, {  7130 /*100 kHz*/ ,0x1C ,0x38 }, {  7160 /*100 kHz*/ ,0x1C ,0x38 },} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7040 /*100 kHz*/ ,0x00 ,0x04 }, {  7070 /*100 kHz*/ ,0x00 ,0x04 }, {  7100 /*100 kHz*/ ,0x00 ,0x04 }, {  7130 /*100 kHz*/ ,0x00 ,0x04 }, {  7160 /*100 kHz*/ ,0x00 ,0x04 },} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7040 /*100 kHz*/ ,0x01 ,0x0F }, {  7070 /*100 kHz*/ ,0x01 ,0x0F }, {  7100 /*100 kHz*/ ,0x01 ,0x0F }, {  7130 /*100 kHz*/ ,0x01 ,0x0F }, {  7160 /*100 kHz*/ ,0x01 ,0x0F },} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7040 /*100 kHz*/ ,0x02 ,0x53 }, {  7070 /*100 kHz*/ ,0x02 ,0x53 }, {  7100 /*100 kHz*/ ,0x02 ,0x53 }, {  7130 /*100 kHz*/ ,0x02 ,0x53 }, {  7160 /*100 kHz*/ ,0x02 ,0x53 },} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7040 /*100 kHz*/ ,0x03 ,0x15 }, {  7070 /*100 kHz*/ ,0x03 ,0x15 }, {  7100 /*100 kHz*/ ,0x03 ,0x15 }, {  7130 /*100 kHz*/ ,0x03 ,0x15 }, {  7160 /*100 kHz*/ ,0x03 ,0x15 },} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7040 /*100 kHz*/ ,0x01 ,0x00 }, {  7070 /*100 kHz*/ ,0x01 ,0x00 }, {  7100 /*100 kHz*/ ,0x01 ,0x00 }, {  7130 /*100 kHz*/ ,0x01 ,0x00 }, {  7160 /*100 kHz*/ ,0x01 ,0x00 },} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7040 /*100 kHz*/ ,0x1C ,0x38 }, {  7070 /*100 kHz*/ ,0x1C ,0x38 }, {  7100 /*100 kHz*/ ,0x1C ,0x38 }, {  7130 /*100 kHz*/ ,0x1C ,0x38 }, {  7160 /*100 kHz*/ ,0x1C ,0x38 },} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7040 /*100 kHz*/ ,0x04 ,0x0B }, {  7070 /*100 kHz*/ ,0x04 ,0x0B }, {  7100 /*100 kHz*/ ,0x04 ,0x0B }, {  7130 /*100 kHz*/ ,0x04 ,0x0B }, {  7160 /*100 kHz*/ ,0x04 ,0x0B },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band20_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8395 /*100 kHz*/ ,0x1C ,0x38 }, {  8470 /*100 kHz*/ ,0x1C ,0x38 }, {  8545 /*100 kHz*/ ,0x1C ,0x38 }, {  8620 /*100 kHz*/ ,0x1C ,0x38 },} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8320 /*100 kHz*/ ,0x00 ,0x94 }, {  8395 /*100 kHz*/ ,0x00 ,0x94 }, {  8470 /*100 kHz*/ ,0x00 ,0x94 }, {  8545 /*100 kHz*/ ,0x00 ,0x94 }, {  8620 /*100 kHz*/ ,0x00 ,0x94 },} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8320 /*100 kHz*/ ,0x01 ,0x00 }, {  8395 /*100 kHz*/ ,0x01 ,0x00 }, {  8470 /*100 kHz*/ ,0x01 ,0x00 }, {  8545 /*100 kHz*/ ,0x01 ,0x00 }, {  8620 /*100 kHz*/ ,0x01 ,0x00 },} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8320 /*100 kHz*/ ,0x02 ,0x00 }, {  8395 /*100 kHz*/ ,0x02 ,0x00 }, {  8470 /*100 kHz*/ ,0x02 ,0x00 }, {  8545 /*100 kHz*/ ,0x02 ,0x00 }, {  8620 /*100 kHz*/ ,0x02 ,0x00 },} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8320 /*100 kHz*/ ,0x03 ,0x00 }, {  8395 /*100 kHz*/ ,0x03 ,0x00 }, {  8470 /*100 kHz*/ ,0x03 ,0x00 }, {  8545 /*100 kHz*/ ,0x03 ,0x00 }, {  8620 /*100 kHz*/ ,0x03 ,0x00 },} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8320 /*100 kHz*/ ,0x00 ,0x00 }, {  8395 /*100 kHz*/ ,0x00 ,0x00 }, {  8470 /*100 kHz*/ ,0x00 ,0x00 }, {  8545 /*100 kHz*/ ,0x00 ,0x00 }, {  8620 /*100 kHz*/ ,0x00 ,0x00 },} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8395 /*100 kHz*/ ,0x1C ,0x38 }, {  8470 /*100 kHz*/ ,0x1C ,0x38 }, {  8545 /*100 kHz*/ ,0x1C ,0x38 }, {  8620 /*100 kHz*/ ,0x1C ,0x38 },} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8320 /*100 kHz*/ ,0x04 ,0x0B }, {  8395 /*100 kHz*/ ,0x04 ,0x0B }, {  8470 /*100 kHz*/ ,0x04 ,0x0B }, {  8545 /*100 kHz*/ ,0x04 ,0x0B }, {  8620 /*100 kHz*/ ,0x04 ,0x0B },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8395 /*100 kHz*/ ,0x1C ,0x38 }, {  8470 /*100 kHz*/ ,0x1C ,0x38 }, {  8545 /*100 kHz*/ ,0x1C ,0x38 }, {  8620 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8395 /*100 kHz*/ ,0x1C ,0x38 }, {  8470 /*100 kHz*/ ,0x1C ,0x38 }, {  8545 /*100 kHz*/ ,0x1C ,0x38 }, {  8620 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8395 /*100 kHz*/ ,0x1C ,0x38 }, {  8470 /*100 kHz*/ ,0x1C ,0x38 }, {  8545 /*100 kHz*/ ,0x1C ,0x38 }, {  8620 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8395 /*100 kHz*/ ,0x1C ,0x38 }, {  8470 /*100 kHz*/ ,0x1C ,0x38 }, {  8545 /*100 kHz*/ ,0x1C ,0x38 }, {  8620 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8320 /*100 kHz*/ ,0x02 ,0x01 }, {  8395 /*100 kHz*/ ,0x02 ,0x01 }, {  8470 /*100 kHz*/ ,0x02 ,0x01 }, {  8545 /*100 kHz*/ ,0x02 ,0x01 }, {  8620 /*100 kHz*/ ,0x02 ,0x01 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8395 /*100 kHz*/ ,0x1C ,0x38 }, {  8470 /*100 kHz*/ ,0x1C ,0x38 }, {  8545 /*100 kHz*/ ,0x1C ,0x38 }, {  8620 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8395 /*100 kHz*/ ,0x1C ,0x38 }, {  8470 /*100 kHz*/ ,0x1C ,0x38 }, {  8545 /*100 kHz*/ ,0x1C ,0x38 }, {  8620 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8395 /*100 kHz*/ ,0x1C ,0x38 }, {  8470 /*100 kHz*/ ,0x1C ,0x38 }, {  8545 /*100 kHz*/ ,0x1C ,0x38 }, {  8620 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band26_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8140 /*100 kHz*/ ,0x1C ,0x38 }, {  8227 /*100 kHz*/ ,0x1C ,0x38 }, {  8315 /*100 kHz*/ ,0x1C ,0x38 }, {  8402 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8140 /*100 kHz*/ ,0x00 ,0x94 }, {  8227 /*100 kHz*/ ,0x00 ,0x94 }, {  8315 /*100 kHz*/ ,0x00 ,0x94 }, {  8402 /*100 kHz*/ ,0x00 ,0x94 }, {  8490 /*100 kHz*/ ,0x00 ,0x94 },} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8140 /*100 kHz*/ ,0x01 ,0x00 }, {  8227 /*100 kHz*/ ,0x01 ,0x00 }, {  8315 /*100 kHz*/ ,0x01 ,0x00 }, {  8402 /*100 kHz*/ ,0x01 ,0x00 }, {  8490 /*100 kHz*/ ,0x01 ,0x00 },} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8140 /*100 kHz*/ ,0x02 ,0x00 }, {  8227 /*100 kHz*/ ,0x02 ,0x00 }, {  8315 /*100 kHz*/ ,0x02 ,0x00 }, {  8402 /*100 kHz*/ ,0x02 ,0x00 }, {  8490 /*100 kHz*/ ,0x02 ,0x00 },} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8140 /*100 kHz*/ ,0x03 ,0x00 }, {  8227 /*100 kHz*/ ,0x03 ,0x00 }, {  8315 /*100 kHz*/ ,0x03 ,0x00 }, {  8402 /*100 kHz*/ ,0x03 ,0x00 }, {  8490 /*100 kHz*/ ,0x03 ,0x00 },} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  8140 /*100 kHz*/ ,0x00 ,0x00 }, {  8227 /*100 kHz*/ ,0x00 ,0x00 }, {  8315 /*100 kHz*/ ,0x00 ,0x00 }, {  8402 /*100 kHz*/ ,0x00 ,0x00 }, {  8490 /*100 kHz*/ ,0x00 ,0x00 },} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8140 /*100 kHz*/ ,0x1C ,0x38 }, {  8227 /*100 kHz*/ ,0x1C ,0x38 }, {  8315 /*100 kHz*/ ,0x1C ,0x38 }, {  8402 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8140 /*100 kHz*/ ,0x04 ,0x0B }, {  8227 /*100 kHz*/ ,0x04 ,0x0B }, {  8315 /*100 kHz*/ ,0x04 ,0x0B }, {  8402 /*100 kHz*/ ,0x04 ,0x0B }, {  8490 /*100 kHz*/ ,0x04 ,0x0B },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8140 /*100 kHz*/ ,0x1C ,0x38 }, {  8227 /*100 kHz*/ ,0x1C ,0x38 }, {  8315 /*100 kHz*/ ,0x1C ,0x38 }, {  8402 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8140 /*100 kHz*/ ,0x1C ,0x38 }, {  8227 /*100 kHz*/ ,0x1C ,0x38 }, {  8315 /*100 kHz*/ ,0x1C ,0x38 }, {  8402 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8140 /*100 kHz*/ ,0x1C ,0x38 }, {  8227 /*100 kHz*/ ,0x1C ,0x38 }, {  8315 /*100 kHz*/ ,0x1C ,0x38 }, {  8402 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8140 /*100 kHz*/ ,0x1C ,0x38 }, {  8227 /*100 kHz*/ ,0x1C ,0x38 }, {  8315 /*100 kHz*/ ,0x1C ,0x38 }, {  8402 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8140 /*100 kHz*/ ,0x02 ,0x04 }, {  8227 /*100 kHz*/ ,0x02 ,0x04 }, {  8315 /*100 kHz*/ ,0x02 ,0x04 }, {  8402 /*100 kHz*/ ,0x02 ,0x04 }, {  8490 /*100 kHz*/ ,0x02 ,0x04 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8140 /*100 kHz*/ ,0x1C ,0x38 }, {  8227 /*100 kHz*/ ,0x1C ,0x38 }, {  8315 /*100 kHz*/ ,0x1C ,0x38 }, {  8402 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8140 /*100 kHz*/ ,0x1C ,0x38 }, {  8227 /*100 kHz*/ ,0x1C ,0x38 }, {  8315 /*100 kHz*/ ,0x1C ,0x38 }, {  8402 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  8140 /*100 kHz*/ ,0x1C ,0x38 }, {  8227 /*100 kHz*/ ,0x1C ,0x38 }, {  8315 /*100 kHz*/ ,0x1C ,0x38 }, {  8402 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band28_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7030 /*100 kHz*/ ,0x1C ,0x38 }, {  7142 /*100 kHz*/ ,0x1C ,0x38 }, {  7255 /*100 kHz*/ ,0x1C ,0x38 }, {  7367 /*100 kHz*/ ,0x1C ,0x38 }, {  7480 /*100 kHz*/ ,0x1C ,0x38 },} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7030 /*100 kHz*/ ,0x00 ,0x94 }, {  7142 /*100 kHz*/ ,0x00 ,0x94 }, {  7255 /*100 kHz*/ ,0x00 ,0x94 }, {  7367 /*100 kHz*/ ,0x00 ,0x94 }, {  7480 /*100 kHz*/ ,0x00 ,0x94 },} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7030 /*100 kHz*/ ,0x01 ,0x00 }, {  7142 /*100 kHz*/ ,0x01 ,0x00 }, {  7255 /*100 kHz*/ ,0x01 ,0x00 }, {  7367 /*100 kHz*/ ,0x01 ,0x00 }, {  7480 /*100 kHz*/ ,0x01 ,0x00 },} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7030 /*100 kHz*/ ,0x02 ,0x00 }, {  7142 /*100 kHz*/ ,0x02 ,0x00 }, {  7255 /*100 kHz*/ ,0x02 ,0x00 }, {  7367 /*100 kHz*/ ,0x02 ,0x00 }, {  7480 /*100 kHz*/ ,0x02 ,0x00 },} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7030 /*100 kHz*/ ,0x03 ,0x00 }, {  7142 /*100 kHz*/ ,0x03 ,0x00 }, {  7255 /*100 kHz*/ ,0x03 ,0x00 }, {  7367 /*100 kHz*/ ,0x03 ,0x00 }, {  7480 /*100 kHz*/ ,0x03 ,0x00 },} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA1_P3    ,{ {  7030 /*100 kHz*/ ,0x00 ,0x00 }, {  7142 /*100 kHz*/ ,0x00 ,0x00 }, {  7255 /*100 kHz*/ ,0x00 ,0x00 }, {  7367 /*100 kHz*/ ,0x00 ,0x00 }, {  7480 /*100 kHz*/ ,0x00 ,0x00 },} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7030 /*100 kHz*/ ,0x1C ,0x38 }, {  7142 /*100 kHz*/ ,0x1C ,0x38 }, {  7255 /*100 kHz*/ ,0x1C ,0x38 }, {  7367 /*100 kHz*/ ,0x1C ,0x38 }, {  7480 /*100 kHz*/ ,0x1C ,0x38 },} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7030 /*100 kHz*/ ,0x04 ,0x0B }, {  7142 /*100 kHz*/ ,0x04 ,0x0B }, {  7255 /*100 kHz*/ ,0x04 ,0x0B }, {  7367 /*100 kHz*/ ,0x04 ,0x0B }, {  7480 /*100 kHz*/ ,0x04 ,0x0B },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7030 /*100 kHz*/ ,0x1C ,0x38 }, {  7142 /*100 kHz*/ ,0x1C ,0x38 }, {  7255 /*100 kHz*/ ,0x1C ,0x38 }, {  7367 /*100 kHz*/ ,0x1C ,0x38 }, {  7480 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7030 /*100 kHz*/ ,0x1C ,0x38 }, {  7142 /*100 kHz*/ ,0x1C ,0x38 }, {  7255 /*100 kHz*/ ,0x1C ,0x38 }, {  7367 /*100 kHz*/ ,0x1C ,0x38 }, {  7480 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7030 /*100 kHz*/ ,0x1C ,0x38 }, {  7142 /*100 kHz*/ ,0x1C ,0x38 }, {  7255 /*100 kHz*/ ,0x1C ,0x38 }, {  7367 /*100 kHz*/ ,0x1C ,0x38 }, {  7480 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7030 /*100 kHz*/ ,0x1C ,0x38 }, {  7142 /*100 kHz*/ ,0x1C ,0x38 }, {  7255 /*100 kHz*/ ,0x1C ,0x38 }, {  7367 /*100 kHz*/ ,0x1C ,0x38 }, {  7480 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7030 /*100 kHz*/ ,0x02 ,0x03 }, {  7142 /*100 kHz*/ ,0x02 ,0x03 }, {  7255 /*100 kHz*/ ,0x02 ,0x05 }, {  7367 /*100 kHz*/ ,0x02 ,0x05 }, {  7480 /*100 kHz*/ ,0x02 ,0x05 },} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7030 /*100 kHz*/ ,0x1C ,0x38 }, {  7142 /*100 kHz*/ ,0x1C ,0x38 }, {  7255 /*100 kHz*/ ,0x1C ,0x38 }, {  7367 /*100 kHz*/ ,0x1C ,0x38 }, {  7480 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7030 /*100 kHz*/ ,0x1C ,0x38 }, {  7142 /*100 kHz*/ ,0x1C ,0x38 }, {  7255 /*100 kHz*/ ,0x1C ,0x38 }, {  7367 /*100 kHz*/ ,0x1C ,0x38 }, {  7480 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ {  7030 /*100 kHz*/ ,0x1C ,0x38 }, {  7142 /*100 kHz*/ ,0x1C ,0x38 }, {  7255 /*100 kHz*/ ,0x1C ,0x38 }, {  7367 /*100 kHz*/ ,0x1C ,0x38 }, {  7480 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band30_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 23050 /*100 kHz*/ ,0x1C ,0x38 }, { 23075 /*100 kHz*/ ,0x1C ,0x38 }, { 23100 /*100 kHz*/ ,0x1C ,0x38 }, { 23125 /*100 kHz*/ ,0x1C ,0x38 }, { 23150 /*100 kHz*/ ,0x1C ,0x38 },} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 23050 /*100 kHz*/ ,0x00 ,0x16 }, { 23075 /*100 kHz*/ ,0x00 ,0x16 }, { 23100 /*100 kHz*/ ,0x00 ,0x16 }, { 23125 /*100 kHz*/ ,0x00 ,0x16 }, { 23150 /*100 kHz*/ ,0x00 ,0x16 },} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 23050 /*100 kHz*/ ,0x01 ,0x00 }, { 23075 /*100 kHz*/ ,0x01 ,0x00 }, { 23100 /*100 kHz*/ ,0x01 ,0x00 }, { 23125 /*100 kHz*/ ,0x01 ,0x00 }, { 23150 /*100 kHz*/ ,0x01 ,0x00 },} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 23050 /*100 kHz*/ ,0x02 ,0x09 }, { 23075 /*100 kHz*/ ,0x02 ,0x09 }, { 23100 /*100 kHz*/ ,0x02 ,0x09 }, { 23125 /*100 kHz*/ ,0x02 ,0x09 }, { 23150 /*100 kHz*/ ,0x02 ,0x09 },} }, // PA path sel
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 23050 /*100 kHz*/ ,0x03 ,0x00 }, { 23075 /*100 kHz*/ ,0x03 ,0x00 }, { 23100 /*100 kHz*/ ,0x03 ,0x00 }, { 23125 /*100 kHz*/ ,0x03 ,0x00 }, { 23150 /*100 kHz*/ ,0x03 ,0x00 },} }, // PA enable
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3    ,{ { 23050 /*100 kHz*/ ,0x00 ,0x00 }, { 23075 /*100 kHz*/ ,0x00 ,0x00 }, { 23100 /*100 kHz*/ ,0x00 ,0x00 }, { 23125 /*100 kHz*/ ,0x00 ,0x00 }, { 23150 /*100 kHz*/ ,0x00 ,0x00 },} }, // Iref
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23050 /*100 kHz*/ ,0x1C ,0x38 }, { 23075 /*100 kHz*/ ,0x1C ,0x38 }, { 23100 /*100 kHz*/ ,0x1C ,0x38 }, { 23125 /*100 kHz*/ ,0x1C ,0x38 }, { 23150 /*100 kHz*/ ,0x1C ,0x38 },} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23050 /*100 kHz*/ ,0x02 ,0x80 }, { 23075 /*100 kHz*/ ,0x02 ,0x80 }, { 23100 /*100 kHz*/ ,0x02 ,0x80 }, { 23125 /*100 kHz*/ ,0x02 ,0x80 }, { 23150 /*100 kHz*/ ,0x02 ,0x80 },} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 23050 /*100 kHz*/ ,0x04 ,0x10 }, { 23075 /*100 kHz*/ ,0x04 ,0x10 }, { 23100 /*100 kHz*/ ,0x04 ,0x10 }, { 23125 /*100 kHz*/ ,0x04 ,0x10 }, { 23150 /*100 kHz*/ ,0x04 ,0x10 },} },
   { /* 9  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID            ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x00 , 0x4C}, { 25825 /*100 kHz*/    ,0x00 , 0x4C}, { 25950 /*100 kHz*/    ,0x00 , 0x4C}, { 26075 /*100 kHz*/    ,0x00 , 0x4C}, { 26200 /*100 kHz*/    ,0x00 , 0x4C},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x01 , 0x00}, { 25825 /*100 kHz*/    ,0x01 , 0x00}, { 25950 /*100 kHz*/    ,0x01 , 0x00}, { 26075 /*100 kHz*/    ,0x01 , 0x00}, { 26200 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x02 , 0x00}, { 25825 /*100 kHz*/    ,0x02 , 0x00}, { 25950 /*100 kHz*/    ,0x02 , 0x00}, { 26075 /*100 kHz*/    ,0x02 , 0x00}, { 26200 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x03 , 0x00}, { 25825 /*100 kHz*/    ,0x03 , 0x00}, { 25950 /*100 kHz*/    ,0x03 , 0x00}, { 26075 /*100 kHz*/    ,0x03 , 0x00}, { 26200 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x00 , 0x00}, { 25825 /*100 kHz*/    ,0x00 , 0x00}, { 25950 /*100 kHz*/    ,0x00 , 0x00}, { 26075 /*100 kHz*/    ,0x00 , 0x00}, { 26200 /*100 kHz*/    ,0x00 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x04 , 0x18}, { 25825 /*100 kHz*/    ,0x04 , 0x18}, { 25950 /*100 kHz*/    ,0x04 , 0x18}, { 26075 /*100 kHz*/    ,0x04 , 0x18}, { 26200 /*100 kHz*/    ,0x04 , 0x18},} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x03 , 0x40}, { 25825 /*100 kHz*/    ,0x03 , 0x40}, { 25950 /*100 kHz*/    ,0x03 , 0x40}, { 26075 /*100 kHz*/    ,0x03 , 0x40}, { 26200 /*100 kHz*/    ,0x03 , 0x40},} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0               ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band39_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x00 , 0xAF}, { 18900 /*100 kHz*/    ,0x00 , 0xAF}, { 19000 /*100 kHz*/    ,0x00 , 0xAF}, { 19100 /*100 kHz*/    ,0x00 , 0xAF}, { 19200 /*100 kHz*/    ,0x00 , 0xAF},} }, // PA HB/EDGE linear mode
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x01 , 0x28}, { 18900 /*100 kHz*/    ,0x01 , 0x28}, { 19000 /*100 kHz*/    ,0x01 , 0x28}, { 19100 /*100 kHz*/    ,0x01 , 0x28}, { 19200 /*100 kHz*/    ,0x01 , 0x28},} }, // PA bias control
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x04 , 0x13}, { 18900 /*100 kHz*/    ,0x04 , 0x13}, { 19000 /*100 kHz*/    ,0x04 , 0x13}, { 19100 /*100 kHz*/    ,0x04 , 0x13}, { 19200 /*100 kHz*/    ,0x04 , 0x13},} }, // coupler turn on
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x05 , 0x06}, { 18900 /*100 kHz*/    ,0x05 , 0x06}, { 19000 /*100 kHz*/    ,0x05 , 0x06}, { 19100 /*100 kHz*/    ,0x05 , 0x06}, { 19200 /*100 kHz*/    ,0x05 , 0x06},} }, // TXM switch isolation mode for time mask
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18800 /*100 kHz*/    ,0x00 , 0x00}, { 18900 /*100 kHz*/    ,0x00 , 0x00}, { 19000 /*100 kHz*/    ,0x00 , 0x00}, { 19100 /*100 kHz*/    ,0x00 , 0x00}, { 19200 /*100 kHz*/    ,0x00 , 0x00},} }, // PA(TXM re-use) disable
   { /* 13  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x00 , 0x44}, { 23250 /*100 kHz*/    ,0x00 , 0x44}, { 23500 /*100 kHz*/    ,0x00 , 0x44}, { 23750 /*100 kHz*/    ,0x00 , 0x44}, { 24000 /*100 kHz*/    ,0x00 , 0x44},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x01 , 0x00}, { 23250 /*100 kHz*/    ,0x01 , 0x00}, { 23500 /*100 kHz*/    ,0x01 , 0x00}, { 23750 /*100 kHz*/    ,0x01 , 0x00}, { 24000 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x02 , 0x00}, { 23250 /*100 kHz*/    ,0x02 , 0x00}, { 23500 /*100 kHz*/    ,0x02 , 0x00}, { 23750 /*100 kHz*/    ,0x02 , 0x00}, { 24000 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x03 , 0x00}, { 23250 /*100 kHz*/    ,0x03 , 0x00}, { 23500 /*100 kHz*/    ,0x03 , 0x00}, { 23750 /*100 kHz*/    ,0x03 , 0x00}, { 24000 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x00 , 0x00}, { 23250 /*100 kHz*/    ,0x00 , 0x00}, { 23500 /*100 kHz*/    ,0x00 , 0x00}, { 23750 /*100 kHz*/    ,0x00 , 0x00}, { 24000 /*100 kHz*/    ,0x00 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x04 , 0x18}, { 23250 /*100 kHz*/    ,0x03 , 0x60}, { 23500 /*100 kHz*/    ,0x03 , 0x60}, { 23750 /*100 kHz*/    ,0x03 , 0x60}, { 24000 /*100 kHz*/    ,0x03 , 0x60},} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x03 , 0x60}, { 23250 /*100 kHz*/    ,0x04 , 0x18}, { 23500 /*100 kHz*/    ,0x04 , 0x18}, { 23750 /*100 kHz*/    ,0x04 , 0x18}, { 24000 /*100 kHz*/    ,0x04 , 0x18},} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0               ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x00 , 0x4C}, { 25445 /*100 kHz*/    ,0x00 , 0x4C}, { 25930 /*100 kHz*/    ,0x00 , 0x4C}, { 26415 /*100 kHz*/    ,0x00 , 0x4C}, { 26900 /*100 kHz*/    ,0x00 , 0x4C},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x01 , 0x00}, { 25445 /*100 kHz*/    ,0x01 , 0x00}, { 25930 /*100 kHz*/    ,0x01 , 0x00}, { 26415 /*100 kHz*/    ,0x01 , 0x00}, { 26900 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x02 , 0x00}, { 25445 /*100 kHz*/    ,0x02 , 0x00}, { 25930 /*100 kHz*/    ,0x02 , 0x00}, { 26415 /*100 kHz*/    ,0x02 , 0x00}, { 26900 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x03 , 0x00}, { 25445 /*100 kHz*/    ,0x03 , 0x00}, { 25930 /*100 kHz*/    ,0x03 , 0x00}, { 26415 /*100 kHz*/    ,0x03 , 0x00}, { 26900 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x00 , 0x00}, { 25445 /*100 kHz*/    ,0x00 , 0x00}, { 25930 /*100 kHz*/    ,0x00 , 0x00}, { 26415 /*100 kHz*/    ,0x00 , 0x00}, { 26900 /*100 kHz*/    ,0x00 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x04 , 0x18}, { 25445 /*100 kHz*/    ,0x04 , 0x18}, { 25930 /*100 kHz*/    ,0x04 , 0x18}, { 26415 /*100 kHz*/    ,0x04 , 0x18}, { 26900 /*100 kHz*/    ,0x04 , 0x18},} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x03 , 0x40}, { 25445 /*100 kHz*/    ,0x03 , 0x40}, { 25930 /*100 kHz*/    ,0x03 , 0x40}, { 26415 /*100 kHz*/    ,0x03 , 0x40}, { 26900 /*100 kHz*/    ,0x03 , 0x40},} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0               ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

kal_uint32  LTE_MIPI_TX_DATA_SIZE_TABLE_Set1[] =
{
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR0,  Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR1,  Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR2,  Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR3,  Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR4,  Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR5,  Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR6,  Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR7,  Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR8,  Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR9,  Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR10, Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR11, Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR12, Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR13, Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR14, Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR15, Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR16, Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR17, Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR18, Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR19, Set1)),
   sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR20, Set1)),
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_TX_DATA_TABLE_Set1[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   LTE_MIPI_TX_DATA(BAND_INDICATOR0,  Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR1,  Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR2,  Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR3,  Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR4,  Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR5,  Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR6,  Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR7,  Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR8,  Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR9,  Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR10, Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR11, Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR12, Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR13, Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR14, Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR15, Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR16, Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR17, Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR18, Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR19, Set1),
   LTE_MIPI_TX_DATA(BAND_INDICATOR20, Set1),
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band2_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band4_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band5_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band12_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band13_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band20_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band26_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band30_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(8.5)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(8.5)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                      ( us )        */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(8.5)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

kal_uint32  LTE_MIPI_TPC_EVENT_SIZE_TABLE_Set1[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR0,  Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR1,  Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR2,  Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR3,  Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR4,  Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR5,  Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR6,  Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR7,  Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR8,  Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR9,  Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR10, Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR11, Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR12, Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR13, Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR14, Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR15, Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR16, Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR17, Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR18, Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR19, Set1)),
   sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR20, Set1)),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TPC_EVENT_TABLE_Set1[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR0,  Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR1,  Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR2,  Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR3,  Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR4,  Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR5,  Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR6,  Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR7,  Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR8,  Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR9,  Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR10, Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR11, Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR12, Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR13, Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR14, Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR15, Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR16, Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR17, Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR18, Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR19, Set1),
   LTE_MIPI_TPC_EVENT(BAND_INDICATOR20, Set1),
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_DATA_TABLE_T LTE_BandNone_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band1_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band2_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band3_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band4_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band5_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band7_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band8_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band12_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band13_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band17_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band20_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band26_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band27_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band28_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band30_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band38_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band39_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band40_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band41_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_TPC_DATA_TABLE_Set1[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   LTE_MIPI_TPC_DATA(BAND_INDICATOR0,  Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR1,  Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR2,  Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR3,  Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR4,  Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR5,  Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR6,  Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR7,  Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR8,  Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR9,  Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR10, Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR11, Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR12, Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR13, Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR14, Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR15, Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR16, Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR17, Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR18, Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR19, Set1),
   LTE_MIPI_TPC_DATA(BAND_INDICATOR20, Set1),
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_TPC_SECTION_TABLE_T LTE_BandNone_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      0, /*100kHz*/
      MIPI_USID_INIT0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},//SRS
      }
   },
   {
      0, /*100kHz*/
      MIPI_USID_INIT0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},//SRS
      }
   },
   {
      0, /*100kHz*/
      MIPI_USID_INIT0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},//SRS
      }
   },
   {
      0, /*100kHz*/
      MIPI_USID_INIT0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},//SRS
      }
   },
   {
      0, /*100kHz*/
      MIPI_USID_INIT0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},
         {{ { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 } }},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band1_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      19200, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1 , 0x13}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x14}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x25}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x35}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x45}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x58}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x9B}, { 0x3 , 0x8B}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x9B}, { 0x3 , 0x8B}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}, { 0x3 , 0x00}, { 0x0 , 0x00}, { 0x0 , 0x0}, { 0x0 , 0x0}}},//SRS
      }
   },
   {
      19350, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1 , 0x13}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x14}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x25}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x35}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x45}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x58}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0xAB}, { 0x3 , 0x8B}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0xAB}, { 0x3 , 0x8B}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}, { 0x3 , 0x00}, { 0x0 , 0x00}, { 0x0 , 0x0}, { 0x0 , 0x0}}},//SRS
      }
   },
   {
      19500, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1 , 0x13}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x14}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x25}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x35}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x45}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x58}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0xAB}, { 0x3 , 0x8B}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0xAB}, { 0x3 , 0x8B}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}, { 0x3 , 0x00}, { 0x0 , 0x00}, { 0x0 , 0x0}, { 0x0 , 0x0}}},//SRS
      }
   },
   {
      19650, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1 , 0x13}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x14}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x25}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x35}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x45}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x58}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0xAB}, { 0x3 , 0x89}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0xAB}, { 0x3 , 0x89}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}, { 0x3 , 0x00}, { 0x0 , 0x00}, { 0x0 , 0x0}, { 0x0 , 0x0}}},//SRS
      }
   },
   {
      19800, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1 , 0x13}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x14}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x25}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x35}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x45}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x58}, { 0x3 , 0x86}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0xAB}, { 0x3 , 0x89}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0xAB}, { 0x3 , 0x89}, { 0x0 , 0x24}, { 0x0 , 0x0}, { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}, { 0x3 , 0x00}, { 0x0 , 0x00}, { 0x0 , 0x0}, { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band2_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      18500, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x53}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x93}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x75}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x77}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x77}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xB9}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xB9}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      18650, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x53}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x93}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x75}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x77}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x77}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xBA}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xBA}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      18800, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x53}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x93}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x75}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x77}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x77}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xBA}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xBA}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      18950, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x53}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x93}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x75}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x77}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x77}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xBA}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xBA}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      19100, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x53}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x93}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x75}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x77}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x77}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xBA}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xBA}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band3_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      17100, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x23}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x44}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x99}, { 0x3, 0x8B}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x99}, { 0x3, 0x8B}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      17287, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x23}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x44}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xB8}, { 0x3, 0x8C}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xB8}, { 0x3, 0x8C}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      17475, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x23}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x44}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xB8}, { 0x3, 0x8C}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xB8}, { 0x3, 0x8C}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      17662, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x23}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x44}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE8}, { 0x3, 0x89}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE8}, { 0x3, 0x89}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      17850, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x23}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x44}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x86}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE8}, { 0x3, 0x89}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE8}, { 0x3, 0x89}, { 0x0, 0x2C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band4_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      17100, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x66}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0xB8}, { 0x3, 0x8C}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0xB8}, { 0x3, 0x8C}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      17212, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x66}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0xB8}, { 0x3, 0x8B}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0xB8}, { 0x3, 0x8B}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS      
      }
   },
   {
      17325, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x66}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0xB8}, { 0x3, 0x8B}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0xB8}, { 0x3, 0x8B}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},   
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS     
      }
   },
   {
      17437, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x66}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0xD8}, { 0x3, 0x8B}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0xD8}, { 0x3, 0x8B}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},    
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS    
      }
   },
   {
      17550, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x45}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0x66}, { 0x3, 0x86}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0xD8}, { 0x3, 0x8B}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},     
         {{ { 0x1, 0xD8}, { 0x3, 0x8B}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},      
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS      
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band5_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
       8240, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8302, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8365, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8427, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8490, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band7_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      25000, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x14}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x66}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x67}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x88}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      25175, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x14}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x66}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x67}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x88}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      25350, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x14}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x66}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x67}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x88}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      25525, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x14}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x66}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x67}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x88}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      25700, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x14}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x66}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x67}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x88}, { 0x3, 0x85}, { 0x0, 0x44}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band8_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
       8800, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x6A}, { 0x3, 0x8A}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x6A}, { 0x3, 0x8A}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8887, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x89}, { 0x3, 0x8B}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x89}, { 0x3, 0x8B}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8975, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x89}, { 0x3, 0x8B}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x89}, { 0x3, 0x8B}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       9062, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x89}, { 0x3, 0x8B}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x89}, { 0x3, 0x8B}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       9150, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x80}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x89}, { 0x3, 0x8B}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x89}, { 0x3, 0x8B}, { 0x0, 0x1C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band12_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
       6990, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x14}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x15}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x47}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x47}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x59}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x59}, { 0x3, 0x85}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7032, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x14}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x15}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x47}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x47}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x59}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x59}, { 0x3, 0x85}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7075, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x14}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x15}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x47}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x47}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x59}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x59}, { 0x3, 0x85}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7117, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x14}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x15}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x47}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x47}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x59}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x59}, { 0x3, 0x85}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7160, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x14}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x15}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x47}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x47}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x59}, { 0x3, 0x89}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x59}, { 0x3, 0x85}, { 0x0, 0x74}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band13_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
       7770, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x0F}, { 0x2, 0x57}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x79}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC9}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC7}, { 0x3, 0x11}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xDB}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x99}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x9B}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x9D}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x2, 0x00}, { 0x3, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7795, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x0F}, { 0x2, 0x57}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x79}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC9}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC7}, { 0x3, 0x11}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xDB}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x99}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x9B}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x9D}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x2, 0x00}, { 0x3, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7820, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x0F}, { 0x2, 0x57}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x79}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC9}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC7}, { 0x3, 0x11}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xDB}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x99}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x9B}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x9D}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x2, 0x00}, { 0x3, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7845, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x0F}, { 0x2, 0x57}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x79}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC9}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC7}, { 0x3, 0x11}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xDB}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x99}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x9B}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x9D}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x2, 0x00}, { 0x3, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7870, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x0F}, { 0x2, 0x57}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x79}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC9}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC7}, { 0x3, 0x11}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xDB}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x99}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x9B}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x9D}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x2, 0x00}, { 0x3, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band17_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
       7040, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x0F}, { 0x2, 0x53}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xD7}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xB8}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC9}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xBB}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xCC}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xCF}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x8D}, { 0x3, 0x19}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x2, 0x00}, { 0x3, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7070, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x0F}, { 0x2, 0x53}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xD7}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xB8}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC9}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xBB}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xCC}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xCF}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x8D}, { 0x3, 0x19}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x2, 0x00}, { 0x3, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7100, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x0F}, { 0x2, 0x53}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xD7}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xB8}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC9}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xBB}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xCC}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xCF}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x8D}, { 0x3, 0x19}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x2, 0x00}, { 0x3, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7130, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x0F}, { 0x2, 0x53}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xD7}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xB8}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC9}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xBB}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xCC}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xCF}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x8D}, { 0x3, 0x19}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x2, 0x00}, { 0x3, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7160, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x0F}, { 0x2, 0x53}, { 0x3, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xD7}, { 0x3, 0x10}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xB8}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xC9}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xBB}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xCC}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0xCF}, { 0x3, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x0F}, { 0x2, 0x8D}, { 0x3, 0x19}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x2, 0x00}, { 0x3, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band20_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
       8320, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8395, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8470, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8545, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8620, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x80}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x89}, { 0x0, 0x1D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band26_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
       8140, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8227, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8315, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8402, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       8490, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x25}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x78}, { 0x3, 0x89}, { 0x0, 0x0D}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band28_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
       7030, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x80}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x80}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x65}, { 0x3, 0x8A}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x76}, { 0x3, 0x8A}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x87}, { 0x3, 0x8A}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7142, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x80}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x80}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x65}, { 0x3, 0x8A}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x76}, { 0x3, 0x8A}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x87}, { 0x3, 0x8A}, { 0x0, 0x15}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7255, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x65}, { 0x3, 0x8A}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x76}, { 0x3, 0x8A}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x87}, { 0x3, 0x8A}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7367, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x65}, { 0x3, 0x8A}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x76}, { 0x3, 0x8A}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x87}, { 0x3, 0x8A}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
       7480, /*100kHz*/
      MIPI_USID_PA1_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x13}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x23}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x80}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x65}, { 0x3, 0x8A}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x76}, { 0x3, 0x8A}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x87}, { 0x3, 0x8A}, { 0x0, 0x0C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band30_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      23050, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x24}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x67}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x7A}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xF8}, { 0x3, 0x88}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      23075, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x24}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x67}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x7A}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xF8}, { 0x3, 0x88}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      23100, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x24}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x67}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x7A}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xF8}, { 0x3, 0x88}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      23125, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x24}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x67}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x7A}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xF8}, { 0x3, 0x88}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      23150, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x24}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x34}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x90}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x36}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x56}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x67}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x7A}, { 0x3, 0x95}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xF8}, { 0x3, 0x88}, { 0x0, 0x14}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band38_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      25700, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      25825, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      25950, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      26075, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      26200, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band39_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      18800, /*100kHz*/
      MIPI_USID_ASM0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28},  { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28},  { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28},  { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28},  { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E},  { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E},  { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E},  { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E},  { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x02}, { 0x0, 0xAF}, { 0x1, 0x00},  { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      18900, /*100kHz*/
      MIPI_USID_ASM0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x02}, { 0x0, 0xAF}, { 0x1, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      19000, /*100kHz*/
      MIPI_USID_ASM0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x02}, { 0x0, 0xAF}, { 0x1, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      19100, /*100kHz*/
      MIPI_USID_ASM0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x02}, { 0x0, 0xAF}, { 0x1, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      19200, /*100kHz*/
      MIPI_USID_ASM0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0xAF}, { 0x1, 0x28}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x0F}, { 0x0, 0x8F}, { 0x1, 0x5E}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x5, 0x02}, { 0x0, 0xAF}, { 0x1, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band40_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      23000, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x22}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x54}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x74}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x84}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xA5}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC6}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE7}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      23250, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x22}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x54}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x74}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x84}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xA5}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC6}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE7}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      23500, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x22}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x54}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x74}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x84}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xA5}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC6}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE7}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      23750, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x22}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x54}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x74}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x84}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xA5}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC6}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE7}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      24000, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x22}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x54}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x74}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x84}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xA5}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC6}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE7}, { 0x3, 0x89}, { 0x0, 0x4C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band41_MIPI_PA_SECTION_DATA_Set1[] =
{
   {
      24960, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      25445, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      25930, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      26415, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
   {
      26900, /*100kHz*/
      MIPI_USID_PA0_P3, /*USID*/
      {
         // PAEn=1
         // PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2, PA_SEC_DATA3, PA_SEC_DATA4
         // {addr, data}, {addr, data}, {addr, data}, {addr, data}, {addr, data}
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x3C}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

kal_uint32  LTE_MIPI_PA_TPC_SECTION_DATA_SIZE_Set1[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR0,  Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR1,  Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR2,  Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR3,  Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR4,  Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR5,  Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR6,  Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR7,  Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR8,  Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR9,  Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR10, Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR11, Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR12, Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR13, Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR14, Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR15, Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR16, Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR17, Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR18, Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR19, Set1)),
   sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR20, Set1)),
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_PA_TPC_SECTION_DATA_Set1[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR0,  Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR1,  Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR2,  Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR3,  Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR4,  Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR5,  Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR6,  Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR7,  Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR8,  Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR9,  Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR10, Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR11, Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR12, Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR13, Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR14, Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR15, Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR16, Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR17, Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR18, Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR19, Set1),
   LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR20, Set1),
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*special handle for T/Rx calibration, we should force ASM to isolation mode */
/*Users just need to provide the ASM isolation CW, DSP may use immediate mode*/
/*to control the MIPI ASM                                                    */
LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_ASM_ISOLATION_DATA_Set1[LTE_MIPI_ASM_ISOLATION_DATA_SIZE_Set1] =
{
   //No.      elm type     , port_sel       , data_seq  ,      USID      , addr  , data , wait_time(us)
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0 , LTE_REG_W , MIPI_USID_ASM0_P3 , {0x0  , 0x0} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {  LTE_MIPI_END_PATTERN ,              0 ,         0 ,              0 , {0x0  , 0x0} ,           0  },
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ------------------- *\
|* MIPI BYPASS Feature *|
\* ------------------- */

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_BYPASS_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_BYPASS_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset              */
   /*                        { start, stop },                      ( us )                  */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_BYPASS_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset              */
   /*                        { start, stop },                      ( us )                  */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_BYPASS_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset              */
   /*                        { start, stop },                      ( us )                  */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0_Set1  }, //PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0_Set1 }, //PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 15    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_TX_ON0_Set1 },
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

kal_uint32  LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE_Set1[] =
{
   sizeof(LTE_MIPI_BYPASS_TX_EVENT(BAND_BYPASS_INDICATOR0, Set1)),
   sizeof(LTE_MIPI_BYPASS_TX_EVENT(BAND_BYPASS_INDICATOR1, Set1)),
   sizeof(LTE_MIPI_BYPASS_TX_EVENT(BAND_BYPASS_INDICATOR2, Set1)),
   sizeof(LTE_MIPI_BYPASS_TX_EVENT(BAND_BYPASS_INDICATOR3, Set1)),
   sizeof(LTE_MIPI_BYPASS_TX_EVENT(BAND_BYPASS_INDICATOR4, Set1)),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TX_EVENT_TABLE_Set1[] =
{
   LTE_MIPI_BYPASS_TX_EVENT(BAND_BYPASS_INDICATOR0, Set1),
   LTE_MIPI_BYPASS_TX_EVENT(BAND_BYPASS_INDICATOR1, Set1),
   LTE_MIPI_BYPASS_TX_EVENT(BAND_BYPASS_INDICATOR2, Set1),
   LTE_MIPI_BYPASS_TX_EVENT(BAND_BYPASS_INDICATOR3, Set1),
   LTE_MIPI_BYPASS_TX_EVENT(BAND_BYPASS_INDICATOR4, Set1),
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_BYPASS_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, // ASM PM_Trig: normal mode
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_BYPASS_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x00 , 0x44}, { 25825 /*100 kHz*/    ,0x00 , 0x44}, { 25950 /*100 kHz*/    ,0x00 , 0x44}, { 26075 /*100 kHz*/    ,0x00 , 0x44}, { 26200 /*100 kHz*/    ,0x00 , 0x44},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x01 , 0x00}, { 25825 /*100 kHz*/    ,0x01 , 0x00}, { 25950 /*100 kHz*/    ,0x01 , 0x00}, { 26075 /*100 kHz*/    ,0x01 , 0x00}, { 26200 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x02 , 0x00}, { 25825 /*100 kHz*/    ,0x02 , 0x00}, { 25950 /*100 kHz*/    ,0x02 , 0x00}, { 26075 /*100 kHz*/    ,0x02 , 0x00}, { 26200 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x03 , 0x00}, { 25825 /*100 kHz*/    ,0x03 , 0x00}, { 25950 /*100 kHz*/    ,0x03 , 0x00}, { 26075 /*100 kHz*/    ,0x03 , 0x00}, { 26200 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 25700 /*100 kHz*/    ,0x00 , 0x00}, { 25825 /*100 kHz*/    ,0x00 , 0x00}, { 25950 /*100 kHz*/    ,0x00 , 0x00}, { 26075 /*100 kHz*/    ,0x00 , 0x00}, { 26200 /*100 kHz*/    ,0x00 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x00 , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x03 , 0x20}, { 25825 /*100 kHz*/    ,0x03 , 0x20}, { 25950 /*100 kHz*/    ,0x03 , 0x20}, { 26075 /*100 kHz*/    ,0x03 , 0x20}, { 26200 /*100 kHz*/    ,0x03 , 0x20},} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x04 , 0x18}, { 25825 /*100 kHz*/    ,0x04 , 0x18}, { 25950 /*100 kHz*/    ,0x04 , 0x18}, { 26075 /*100 kHz*/    ,0x04 , 0x18}, { 26200 /*100 kHz*/    ,0x04 , 0x18},} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0               ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_BYPASS_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x00 , 0x44}, { 23250 /*100 kHz*/    ,0x00 , 0x44}, { 23500 /*100 kHz*/    ,0x00 , 0x44}, { 23750 /*100 kHz*/    ,0x00 , 0x44}, { 24000 /*100 kHz*/    ,0x00 , 0x44},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x01 , 0x00}, { 23250 /*100 kHz*/    ,0x01 , 0x00}, { 23500 /*100 kHz*/    ,0x01 , 0x00}, { 23750 /*100 kHz*/    ,0x01 , 0x00}, { 24000 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x02 , 0x00}, { 23250 /*100 kHz*/    ,0x02 , 0x00}, { 23500 /*100 kHz*/    ,0x02 , 0x00}, { 23750 /*100 kHz*/    ,0x02 , 0x00}, { 24000 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x03 , 0x00}, { 23250 /*100 kHz*/    ,0x03 , 0x00}, { 23500 /*100 kHz*/    ,0x03 , 0x00}, { 23750 /*100 kHz*/    ,0x03 , 0x00}, { 24000 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 23000 /*100 kHz*/    ,0x00 , 0x00}, { 23250 /*100 kHz*/    ,0x00 , 0x00}, { 23500 /*100 kHz*/    ,0x00 , 0x00}, { 23750 /*100 kHz*/    ,0x00 , 0x00}, { 24000 /*100 kHz*/    ,0x00 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x00 , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x03 , 0x20}, { 23250 /*100 kHz*/    ,0x03 , 0x20}, { 23500 /*100 kHz*/    ,0x03 , 0x20}, { 23750 /*100 kHz*/    ,0x03 , 0x20}, { 24000 /*100 kHz*/    ,0x03 , 0x20},} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x04 , 0x18}, { 23250 /*100 kHz*/    ,0x04 , 0x18}, { 23500 /*100 kHz*/    ,0x04 , 0x18}, { 23750 /*100 kHz*/    ,0x04 , 0x18}, { 24000 /*100 kHz*/    ,0x04 , 0x18},} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0               ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_BYPASS_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x00 , 0x44}, { 25445 /*100 kHz*/    ,0x00 , 0x44}, { 25930 /*100 kHz*/    ,0x00 , 0x44}, { 26415 /*100 kHz*/    ,0x00 , 0x44}, { 26900 /*100 kHz*/    ,0x00 , 0x44},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x01 , 0x00}, { 25445 /*100 kHz*/    ,0x01 , 0x00}, { 25930 /*100 kHz*/    ,0x01 , 0x00}, { 26415 /*100 kHz*/    ,0x01 , 0x00}, { 26900 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x02 , 0x00}, { 25445 /*100 kHz*/    ,0x02 , 0x00}, { 25930 /*100 kHz*/    ,0x02 , 0x00}, { 26415 /*100 kHz*/    ,0x02 , 0x00}, { 26900 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x03 , 0x00}, { 25445 /*100 kHz*/    ,0x03 , 0x00}, { 25930 /*100 kHz*/    ,0x03 , 0x00}, { 26415 /*100 kHz*/    ,0x03 , 0x00}, { 26900 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_PA0_P3   ,{ { 24960 /*100 kHz*/    ,0x00 , 0x00}, { 25445 /*100 kHz*/    ,0x00 , 0x00}, { 25930 /*100 kHz*/    ,0x00 , 0x00}, { 26415 /*100 kHz*/    ,0x00 , 0x00}, { 26900 /*100 kHz*/    ,0x00 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x00 , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x03 , 0x20}, { 25445 /*100 kHz*/    ,0x03 , 0x20}, { 25930 /*100 kHz*/    ,0x03 , 0x20}, { 26415 /*100 kHz*/    ,0x03 , 0x20}, { 26900 /*100 kHz*/    ,0x03 , 0x20},} },
   { /* 8  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 9  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 10  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 11  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 12  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x04 , 0x18}, { 25445 /*100 kHz*/    ,0x04 , 0x18}, { 25930 /*100 kHz*/    ,0x04 , 0x18}, { 26415 /*100 kHz*/    ,0x04 , 0x18}, { 26900 /*100 kHz*/    ,0x04 , 0x18},} },
   { /* 13  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 14  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 15  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3  ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x00 , 0x38},} },
   { /* 16  */ LTE_MIPI_NULL, 0                 , 0             , 0               ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

kal_uint32  LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE_Set1[] =
{
   sizeof(LTE_MIPI_BYPASS_TX_DATA(BAND_BYPASS_INDICATOR0, Set1)),
   sizeof(LTE_MIPI_BYPASS_TX_DATA(BAND_BYPASS_INDICATOR1, Set1)),
   sizeof(LTE_MIPI_BYPASS_TX_DATA(BAND_BYPASS_INDICATOR2, Set1)),
   sizeof(LTE_MIPI_BYPASS_TX_DATA(BAND_BYPASS_INDICATOR3, Set1)),
   sizeof(LTE_MIPI_BYPASS_TX_DATA(BAND_BYPASS_INDICATOR4, Set1)),
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_BYPASS_TX_DATA_TABLE_Set1[] =
{
   LTE_MIPI_BYPASS_TX_DATA(BAND_BYPASS_INDICATOR0, Set1),
   LTE_MIPI_BYPASS_TX_DATA(BAND_BYPASS_INDICATOR1, Set1),
   LTE_MIPI_BYPASS_TX_DATA(BAND_BYPASS_INDICATOR2, Set1),
   LTE_MIPI_BYPASS_TX_DATA(BAND_BYPASS_INDICATOR3, Set1),
   LTE_MIPI_BYPASS_TX_DATA(BAND_BYPASS_INDICATOR4, Set1),
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_BYPASS_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_BYPASS_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)   },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_BYPASS_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)   },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_BYPASS_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(9)   },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE_Set1[] =
{
   sizeof(LTE_MIPI_BYPASS_TPC_EVENT(BAND_BYPASS_INDICATOR0, Set1)),
   sizeof(LTE_MIPI_BYPASS_TPC_EVENT(BAND_BYPASS_INDICATOR1, Set1)),
   sizeof(LTE_MIPI_BYPASS_TPC_EVENT(BAND_BYPASS_INDICATOR2, Set1)),
   sizeof(LTE_MIPI_BYPASS_TPC_EVENT(BAND_BYPASS_INDICATOR3, Set1)),
   sizeof(LTE_MIPI_BYPASS_TPC_EVENT(BAND_BYPASS_INDICATOR4, Set1)),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TPC_EVENT_TABLE_Set1[] =
{
   LTE_MIPI_BYPASS_TPC_EVENT(BAND_BYPASS_INDICATOR0, Set1),
   LTE_MIPI_BYPASS_TPC_EVENT(BAND_BYPASS_INDICATOR1, Set1),
   LTE_MIPI_BYPASS_TPC_EVENT(BAND_BYPASS_INDICATOR2, Set1),
   LTE_MIPI_BYPASS_TPC_EVENT(BAND_BYPASS_INDICATOR3, Set1),
   LTE_MIPI_BYPASS_TPC_EVENT(BAND_BYPASS_INDICATOR4, Set1),
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_DATA_TABLE_T LTE_BandNone_MIPI_BYPASS_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band38_MIPI_BYPASS_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band40_MIPI_BYPASS_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

LTE_MIPI_DATA_TABLE_T LTE_Band41_MIPI_BYPASS_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT1   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0                        },
};

kal_uint32  LTE_MIPI_BYPASS_TPC_DATA_SIZE_TABLE_Set1[] =
{
   sizeof(LTE_MIPI_BYPASS_TPC_DATA(BAND_BYPASS_INDICATOR0, Set1)),
   sizeof(LTE_MIPI_BYPASS_TPC_DATA(BAND_BYPASS_INDICATOR1, Set1)),
   sizeof(LTE_MIPI_BYPASS_TPC_DATA(BAND_BYPASS_INDICATOR2, Set1)),
   sizeof(LTE_MIPI_BYPASS_TPC_DATA(BAND_BYPASS_INDICATOR3, Set1)),
   sizeof(LTE_MIPI_BYPASS_TPC_DATA(BAND_BYPASS_INDICATOR4, Set1)),
};

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_BYPASS_TPC_DATA_TABLE_Set1[] =
{
   LTE_MIPI_BYPASS_TPC_DATA(BAND_BYPASS_INDICATOR0, Set1),
   LTE_MIPI_BYPASS_TPC_DATA(BAND_BYPASS_INDICATOR1, Set1),
   LTE_MIPI_BYPASS_TPC_DATA(BAND_BYPASS_INDICATOR2, Set1),
   LTE_MIPI_BYPASS_TPC_DATA(BAND_BYPASS_INDICATOR3, Set1),
   LTE_MIPI_BYPASS_TPC_DATA(BAND_BYPASS_INDICATOR4, Set1),
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

LTE_MIPI_TPC_SECTION_TABLE_T LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA_Set1[] =
{
   /*8714 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band38_MIPI_BYPASS_PA_SECTION_DATA_Set1[] =
{
   /*8714 KHz*/
   {
      25700,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25825,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25950,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26075,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26200,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band40_MIPI_BYPASS_PA_SECTION_DATA_Set1[] =
{
   /*8714 KHz*/
   {
      23000,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x22}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x54}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x74}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x84}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xA5}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC6}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE7}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8764 KHz*/
   {
      23250,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x22}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x54}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x74}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x84}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xA5}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC6}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE7}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8784 KHz*/
   {
      23500,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x22}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x54}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x74}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x84}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xA5}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC6}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE7}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8804 KHz*/
   {
      23750,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x22}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x54}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x74}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x84}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xA5}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC6}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE7}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8916 KHz*/
   {
      24000,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x22}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x33}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x54}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x74}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x84}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xA5}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC6}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xE7}, { 0x3, 0x89}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band41_MIPI_BYPASS_PA_SECTION_DATA_Set1[] =
{
   /*8714 KHz*/
   {
      24960,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25445,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25930,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26415,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26900,/*100kHz*/
      MIPI_USID_PA0_P3,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1, 0x23}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x24}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x35}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x45}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x55}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x57}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x68}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0xC9}, { 0x3, 0x87}, { 0x0, 0x34}, { 0x0, 0x0 }, { 0x0, 0x0 }}},
         {{ { 0x1, 0x00}, { 0x3, 0x00}, { 0x0, 0x00}, { 0x0, 0x0 }, { 0x0, 0x0 }}},//SRS
      }
   },
};

kal_uint32  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE_Set1[] =
{
   sizeof(LTE_MIPI_BYPASS_PA_SECTION_DATA(BAND_BYPASS_INDICATOR0, Set1)),
   sizeof(LTE_MIPI_BYPASS_PA_SECTION_DATA(BAND_BYPASS_INDICATOR1, Set1)),
   sizeof(LTE_MIPI_BYPASS_PA_SECTION_DATA(BAND_BYPASS_INDICATOR2, Set1)),
   sizeof(LTE_MIPI_BYPASS_PA_SECTION_DATA(BAND_BYPASS_INDICATOR3, Set1)),
   sizeof(LTE_MIPI_BYPASS_PA_SECTION_DATA(BAND_BYPASS_INDICATOR4, Set1)),
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_Set1[] =
{
   LTE_MIPI_BYPASS_PA_SECTION_DATA(BAND_BYPASS_INDICATOR0, Set1),
   LTE_MIPI_BYPASS_PA_SECTION_DATA(BAND_BYPASS_INDICATOR1, Set1),
   LTE_MIPI_BYPASS_PA_SECTION_DATA(BAND_BYPASS_INDICATOR2, Set1),
   LTE_MIPI_BYPASS_PA_SECTION_DATA(BAND_BYPASS_INDICATOR3, Set1),
   LTE_MIPI_BYPASS_PA_SECTION_DATA(BAND_BYPASS_INDICATOR4, Set1),
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

