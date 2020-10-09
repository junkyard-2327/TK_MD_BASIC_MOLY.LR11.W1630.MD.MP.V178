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
*    lte_custom_mipi_ant.c
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
#include "lte_custom_rf.h"
#include "lte_custom_mipi.h"
#include "lte_custom_mipi_antca.c"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */



#if IS_MIPI_ANT_TUNER_SUPPORT
//ANT RX
LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band2_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band4_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band5_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 4    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band12_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band13_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band20_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band26_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band29_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band30_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 4    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 3    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 3    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 3    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_ANTRX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ANT_RX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 3    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ANT_RX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */



//ANT TX
LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                       },
};


LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band2_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band4_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band5_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 4    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band12_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band13_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band20_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band26_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 5    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band30_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 4    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 3  */ LTE_MIPI_NULL , { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 4    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 4    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 4    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_ANTTX_EVENT_Set0[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   //{ /* 0  */ LTE_MIPI_ANT  , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ANT_TX_ON0_Set0  },  
   //{ /* 1  */ LTE_MIPI_ANT  , { 4    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ANT_TX_OFF0_Set0 },  
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
kal_uint32  LTE_MIPI_ANTRX_EVENT_SIZE_TABLE_Set0[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR0,  Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR1,  Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR2,  Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR3,  Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR4,  Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR5,  Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR6,  Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR7,  Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR8,  Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR9,  Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR10, Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR11, Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR12, Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR13, Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR14, Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR15, Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR16, Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR17, Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR18, Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR19, Set0)),
   sizeof(LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR20, Set0)),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_ANTRX_EVENT_TABLE_Set0[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR0,  Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR1,  Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR2,  Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR3,  Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR4,  Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR5,  Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR6,  Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR7,  Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR8,  Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR9,  Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR10, Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR11, Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR12, Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR13, Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR14, Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR15, Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR16, Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR17, Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR18, Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR19, Set0),
   LTE_MIPI_ANTRX_EVENT(BAND_INDICATOR20, Set0),
};

kal_uint32  LTE_MIPI_ANTTX_EVENT_SIZE_TABLE_Set0[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR0,  Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR1,  Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR2,  Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR3,  Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR4,  Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR5,  Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR6,  Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR7,  Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR8,  Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR9,  Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR10, Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR11, Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR12, Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR13, Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR14, Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR15, Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR16, Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR17, Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR18, Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR19, Set0)),
   sizeof(LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR20, Set0)),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_ANTTX_EVENT_TABLE_Set0[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR0,  Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR1,  Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR2,  Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR3,  Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR4,  Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR5,  Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR6,  Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR7,  Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR8,  Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR9,  Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR10, Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR11, Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR12, Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR13, Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR14, Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR15, Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR16, Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR17, Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR18, Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR19, Set0),
   LTE_MIPI_ANTTX_EVENT(BAND_INDICATOR20, Set0),
};

//Data start
//ANT Rx start

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band1_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ { 21100 /*100 kHz*/ ,0x01 ,0x01 }, { 21250 /*100 kHz*/ ,0x01 ,0x01 }, { 21400 /*100 kHz*/ ,0x01 ,0x01 }, { 21550 /*100 kHz*/ ,0x01 ,0x01 }, { 21700 /*100 kHz*/ ,0x01 ,0x01 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band2_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ { 19300 /*100 kHz*/ ,0x1C ,0x38 }, { 19450 /*100 kHz*/ ,0x1C ,0x38 }, { 19600 /*100 kHz*/ ,0x1C ,0x38 }, { 19750 /*100 kHz*/ ,0x1C ,0x38 }, { 19900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band3_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band4_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21212 /*100 kHz*/ ,0x1C ,0x38 }, { 21325 /*100 kHz*/ ,0x1C ,0x38 }, { 21437 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band5_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ {  8690 /*100 kHz*/ ,0x1C ,0x38 }, {  8753 /*100 kHz*/ ,0x1C ,0x38 }, {  8816 /*100 kHz*/ ,0x1C ,0x38 }, {  8879 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band7_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ { 26200 /*100 kHz*/ ,0x1C ,0x38 }, { 26375 /*100 kHz*/ ,0x1C ,0x38 }, { 26550 /*100 kHz*/ ,0x1C ,0x38 }, { 26725 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band8_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ {  9250 /*100 kHz*/ ,0x1C ,0x38 }, {  9337 /*100 kHz*/ ,0x1C ,0x38 }, {  9425 /*100 kHz*/ ,0x1C ,0x38 }, {  9512 /*100 kHz*/ ,0x1C ,0x38 }, {  9600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band12_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ {  7290 /*100 kHz*/ ,0x1C ,0x38 }, {  7332 /*100 kHz*/ ,0x1C ,0x38 }, {  7375 /*100 kHz*/ ,0x1C ,0x38 }, {  7417 /*100 kHz*/ ,0x1C ,0x38 }, {  7460 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band13_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ {  7460 /*100 kHz*/ ,0x1C ,0x38 }, {  7485 /*100 kHz*/ ,0x1C ,0x38 }, {  7510 /*100 kHz*/ ,0x1C ,0x38 }, {  7535 /*100 kHz*/ ,0x1C ,0x38 }, {  7560 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band17_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ {  7340 /*100 kHz*/ ,0x1C ,0x38 }, {  7370 /*100 kHz*/ ,0x1C ,0x38 }, {  7400 /*100 kHz*/ ,0x1C ,0x38 }, {  7430 /*100 kHz*/ ,0x1C ,0x38 }, {  7460 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band20_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ {  7910 /*100 kHz*/ ,0x1C ,0x38 }, {  7985 /*100 kHz*/ ,0x1C ,0x38 }, {  8060 /*100 kHz*/ ,0x1C ,0x38 }, {  8135 /*100 kHz*/ ,0x1C ,0x38 }, {  8210 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band26_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ {  8590 /*100 kHz*/ ,0x1C ,0x38 }, {  8677 /*100 kHz*/ ,0x1C ,0x38 }, {  8765 /*100 kHz*/ ,0x1C ,0x38 }, {  8852 /*100 kHz*/ ,0x1C ,0x38 }, {  8940 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band28_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ {  7580 /*100 kHz*/ ,0x1C ,0x38 }, {  7692 /*100 kHz*/ ,0x1C ,0x38 }, {  7805 /*100 kHz*/ ,0x1C ,0x38 }, {  7917 /*100 kHz*/ ,0x1C ,0x38 }, {  8030 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band29_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ {  7170 /*100 kHz*/ ,0x1C ,0x38 }, {  7197 /*100 kHz*/ ,0x1C ,0x38 }, {  7225 /*100 kHz*/ ,0x1C ,0x38 }, {  7252 /*100 kHz*/ ,0x1C ,0x38 }, {  7280 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};


LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band30_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23525 /*100 kHz*/ ,0x1C ,0x38 }, { 23550 /*100 kHz*/ ,0x1C ,0x38 }, { 23575 /*100 kHz*/ ,0x1C ,0x38 }, { 23600 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ { 25700 /*100 kHz*/ ,0x03 ,0x03 }, { 25825 /*100 kHz*/ ,0x03 ,0x03 }, { 25950 /*100 kHz*/ ,0x03 ,0x03 }, { 26075 /*100 kHz*/ ,0x03 ,0x03 }, { 26200 /*100 kHz*/ ,0x03 ,0x03 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band39_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_ANTRX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ANT0   ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};



//ANT TX start
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    , 0   }, {     0 /*100 kHz*/ ,0    , 0   }, {     0 /*100 kHz*/ ,0    , 0   }, {     0 /*100 kHz*/ ,0    , 0   }, {     0 /*100 kHz*/ ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band1_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ { 19200 /*100 kHz*/ ,0x02 ,0x02 }, { 19350 /*100 kHz*/ ,0x02 ,0x02 }, { 19500 /*100 kHz*/ ,0x02 ,0x02 }, { 19650 /*100 kHz*/ ,0x02 ,0x02 }, { 19800 /*100 kHz*/ ,0x02 ,0x02 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band2_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ { 18500 /*100 kHz*/ ,0x1C ,0x38 }, { 18650 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18950 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band3_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17287 /*100 kHz*/ ,0x1C ,0x38 }, { 17475 /*100 kHz*/ ,0x1C ,0x38 }, { 17662 /*100 kHz*/ ,0x1C ,0x38 }, { 17850 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band4_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ { 17100 /*100 kHz*/ ,0x1C ,0x38 }, { 17212 /*100 kHz*/ ,0x1C ,0x38 }, { 17325 /*100 kHz*/ ,0x1C ,0x38 }, { 17437 /*100 kHz*/ ,0x1C ,0x38 }, { 17550 /*100 kHz*/ ,0x1C ,0x38},} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band5_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ {  8240 /*100 kHz*/ ,0x1C ,0x38 }, {  8302 /*100 kHz*/ ,0x1C ,0x38 }, {  8365 /*100 kHz*/ ,0x1C ,0x38 }, {  8427 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band6_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ {  8300 /*100 kHz*/ ,0x1C ,0x38 }, {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8340 /*100 kHz*/ ,0x1C ,0x38 }, {  8360 /*100 kHz*/ ,0x1C ,0x38 }, {  8400 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band7_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/ ,0x1C ,0x38 }, { 25175 /*100 kHz*/ ,0x1C ,0x38 }, { 25350 /*100 kHz*/ ,0x1C ,0x38 }, { 25525 /*100 kHz*/ ,0x1C ,0x38 }, { 25700 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 6  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band8_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ {  8800 /*100 kHz*/ ,0x1C ,0x38 }, {  8887 /*100 kHz*/ ,0x1C ,0x38 }, {  8975 /*100 kHz*/ ,0x1C ,0x38 }, {  9062 /*100 kHz*/ ,0x1C ,0x38 }, {  9150 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band12_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ {  6990 /*100 kHz*/ ,0x1C ,0x38 }, {  7032 /*100 kHz*/ ,0x1C ,0x38 }, {  7075 /*100 kHz*/ ,0x1C ,0x38 }, {  7117 /*100 kHz*/ ,0x1C ,0x38 }, {  7160 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band13_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ {  7770 /*100 kHz*/ ,0x1C ,0x38 }, {  7795 /*100 kHz*/ ,0x1C ,0x38 }, {  7820 /*100 kHz*/ ,0x1C ,0x38 }, {  7845 /*100 kHz*/ ,0x1C ,0x38 }, {  7870 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band17_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ {  7040 /*100 kHz*/ ,0x1C ,0x38 }, {  7070 /*100 kHz*/ ,0x1C ,0x38 }, {  7100 /*100 kHz*/ ,0x1C ,0x38 }, {  7130 /*100 kHz*/ ,0x1C ,0x38 }, {  7160 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

//pcore do not have band 19

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band20_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ {  8320 /*100 kHz*/ ,0x1C ,0x38 }, {  8395 /*100 kHz*/ ,0x1C ,0x38 }, {  8470 /*100 kHz*/ ,0x1C ,0x38 }, {  8545 /*100 kHz*/ ,0x1C ,0x38 }, {  8620 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band26_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ {  8140 /*100 kHz*/ ,0x1C ,0x38 }, {  8227 /*100 kHz*/ ,0x1C ,0x38 }, {  8315 /*100 kHz*/ ,0x1C ,0x38 }, {  8402 /*100 kHz*/ ,0x1C ,0x38 }, {  8490 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band28_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ {  7030 /*100 kHz*/ ,0x1C ,0x38 }, {  7142 /*100 kHz*/ ,0x1C ,0x38 }, {  7255 /*100 kHz*/ ,0x1C ,0x38 }, {  7367 /*100 kHz*/ ,0x1C ,0x38 }, {  7480 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band30_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0,{ { 23050 /*100 kHz*/ ,0x1C ,0x38 }, { 23075 /*100 kHz*/ ,0x1C ,0x38 }, { 23100 /*100 kHz*/ ,0x1C ,0x38 }, { 23125 /*100 kHz*/ ,0x1C ,0x38 }, { 23150 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 6  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ { 25700 /*100 kHz*/ ,0x04 ,0x04 }, { 25825 /*100 kHz*/ ,0x04 ,0x04 }, { 25950 /*100 kHz*/ ,0x04 ,0x04 }, { 26075 /*100 kHz*/ ,0x04 ,0x04 }, { 26200 /*100 kHz*/ ,0x04 ,0x04 },} },  
   { /* 6  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band39_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ { 18800 /*100 kHz*/ ,0x1C ,0x38 }, { 18900 /*100 kHz*/ ,0x1C ,0x38 }, { 19000 /*100 kHz*/ ,0x1C ,0x38 }, { 19100 /*100 kHz*/ ,0x1C ,0x38 }, { 19200 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ { 23000 /*100 kHz*/ ,0x1C ,0x38 }, { 23250 /*100 kHz*/ ,0x1C ,0x38 }, { 23500 /*100 kHz*/ ,0x1C ,0x38 }, { 23750 /*100 kHz*/ ,0x1C ,0x38 }, { 24000 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 6  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_ANTTX_DATA_Set0[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq    ,addr ,data }, { subband-1 freq    ,addr ,data }, { subband-2 freq    ,addr ,data }, { subband-3 freq    ,addr ,data }, { subband-4 freq    ,addr ,data },
   //{ /* 0  */ LTE_MIPI_ANT  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ANT0    ,{ { 24960 /*100 kHz*/ ,0x1C ,0x38 }, { 25445 /*100 kHz*/ ,0x1C ,0x38 }, { 25930 /*100 kHz*/ ,0x1C ,0x38 }, { 26415 /*100 kHz*/ ,0x1C ,0x38 }, { 26900 /*100 kHz*/ ,0x1C ,0x38 },} },  
   { /* 6  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    }, {     0 /*100 kHz*/ ,0    ,0    },} },
};

//ANT RX
kal_uint32  LTE_MIPI_ANTRX_DATA_SIZE_TABLE_Set0[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR0,  Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR1,  Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR2,  Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR3,  Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR4,  Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR5,  Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR6,  Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR7,  Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR8,  Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR9,  Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR10, Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR11, Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR12, Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR13, Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR14, Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR15, Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR16, Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR17, Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR18, Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR19, Set0)),
   sizeof(LTE_MIPI_ANTRX_DATA(BAND_INDICATOR20, Set0)),
};


LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_ANTRX_DATA_TABLE_Set0[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR0,  Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR1,  Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR2,  Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR3,  Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR4,  Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR5,  Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR6,  Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR7,  Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR8,  Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR9,  Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR10, Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR11, Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR12, Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR13, Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR14, Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR15, Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR16, Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR17, Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR18, Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR19, Set0),
   LTE_MIPI_ANTRX_DATA(BAND_INDICATOR20, Set0),
};

//ANT TX
kal_uint32  LTE_MIPI_ANTTX_DATA_SIZE_TABLE_Set0[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR0,  Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR1,  Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR2,  Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR3,  Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR4,  Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR5,  Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR6,  Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR7,  Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR8,  Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR9,  Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR10, Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR11, Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR12, Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR13, Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR14, Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR15, Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR16, Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR17, Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR18, Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR19, Set0)),
   sizeof(LTE_MIPI_ANTTX_DATA(BAND_INDICATOR20, Set0)),
};


LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_ANTTX_DATA_TABLE_Set0[LTE_TARGET_MAX_SUPPORT_BAND_NUM] =
{
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR0,  Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR1,  Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR2,  Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR3,  Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR4,  Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR5,  Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR6,  Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR7,  Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR8,  Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR9,  Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR10, Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR11, Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR12, Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR13, Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR14, Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR15, Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR16, Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR17, Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR18, Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR19, Set0),
   LTE_MIPI_ANTTX_DATA(BAND_INDICATOR20, Set0),
};

#endif
//end
