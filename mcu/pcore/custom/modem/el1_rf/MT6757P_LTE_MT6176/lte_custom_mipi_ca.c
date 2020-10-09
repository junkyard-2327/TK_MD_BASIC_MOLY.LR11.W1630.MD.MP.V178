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
*   lte_custom_mipi_ca.c
*
* Project:
* --------
*   MT6291
*
*============================================================================*/

#include "el1d_rf_ca.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifdef  __MIPI_RX_ROUTE21__
LTE_MIPI_EVENT_TABLE_T LTE_Route21_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 4    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_SetDefault},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE22__
LTE_MIPI_EVENT_TABLE_T LTE_Route22_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 4    , 7    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0_SetDefault},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE23__
LTE_MIPI_EVENT_TABLE_T LTE_Route23_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE24__
LTE_MIPI_EVENT_TABLE_T LTE_Route24_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE25__
LTE_MIPI_EVENT_TABLE_T LTE_Route25_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE26__
LTE_MIPI_EVENT_TABLE_T LTE_Route26_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE27__
LTE_MIPI_EVENT_TABLE_T LTE_Route27_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE28__
LTE_MIPI_EVENT_TABLE_T LTE_Route28_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE29__
LTE_MIPI_EVENT_TABLE_T LTE_Route29_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE30__
LTE_MIPI_EVENT_TABLE_T LTE_Route30_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE31__
LTE_MIPI_EVENT_TABLE_T LTE_Route31_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE32__
LTE_MIPI_EVENT_TABLE_T LTE_Route32_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE33__
LTE_MIPI_EVENT_TABLE_T LTE_Route33_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE34__
LTE_MIPI_EVENT_TABLE_T LTE_Route34_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE35__
LTE_MIPI_EVENT_TABLE_T LTE_Route35_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE36__
LTE_MIPI_EVENT_TABLE_T LTE_Route36_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE37__
LTE_MIPI_EVENT_TABLE_T LTE_Route37_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE38__
LTE_MIPI_EVENT_TABLE_T LTE_Route38_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE39__
LTE_MIPI_EVENT_TABLE_T LTE_Route39_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE40__
LTE_MIPI_EVENT_TABLE_T LTE_Route40_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE41__
LTE_MIPI_EVENT_TABLE_T LTE_Route41_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE42__
LTE_MIPI_EVENT_TABLE_T LTE_Route42_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE43__
LTE_MIPI_EVENT_TABLE_T LTE_Route43_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE44__
LTE_MIPI_EVENT_TABLE_T LTE_Route44_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE45__
LTE_MIPI_EVENT_TABLE_T LTE_Route45_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE46__
LTE_MIPI_EVENT_TABLE_T LTE_Route46_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE47__
LTE_MIPI_EVENT_TABLE_T LTE_Route47_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE48__
LTE_MIPI_EVENT_TABLE_T LTE_Route48_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE49__
LTE_MIPI_EVENT_TABLE_T LTE_Route49_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE50__
LTE_MIPI_EVENT_TABLE_T LTE_Route50_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE51__
LTE_MIPI_EVENT_TABLE_T LTE_Route51_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE52__
LTE_MIPI_EVENT_TABLE_T LTE_Route52_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE53__
LTE_MIPI_EVENT_TABLE_T LTE_Route53_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE54__
LTE_MIPI_EVENT_TABLE_T LTE_Route54_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE55__
LTE_MIPI_EVENT_TABLE_T LTE_Route55_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE56__
LTE_MIPI_EVENT_TABLE_T LTE_Route56_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE57__
LTE_MIPI_EVENT_TABLE_T LTE_Route57_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

#ifdef  __MIPI_RX_ROUTE58__
LTE_MIPI_EVENT_TABLE_T LTE_Route58_MIPI_RX_EVENT_SetDefault[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset             */
   /*                        { start, stop },                      ( us )                 */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0_SetDefault },
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0                                  },
};
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifdef  __MIPI_RX_ROUTE21__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route21_MIPI_RX_DATA_SetDefault[] =
{
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x05 ,0x03 }, { 21250 /*100 kHz*/ ,0x05 ,0x03 }, { 21400 /*100 kHz*/ ,0x05 ,0x03 }, { 21550 /*100 kHz*/ ,0x05 ,0x03 }, { 21700 /*100 kHz*/ ,0x05 ,0x03 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x01 ,0x02 }, { 21250 /*100 kHz*/ ,0x01 ,0x02 }, { 21400 /*100 kHz*/ ,0x01 ,0x02 }, { 21550 /*100 kHz*/ ,0x01 ,0x02 }, { 21700 /*100 kHz*/ ,0x01 ,0x02 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 21100 /*100 kHz*/ ,0x05 ,0x00 }, { 21250 /*100 kHz*/ ,0x05 ,0x00 }, { 21400 /*100 kHz*/ ,0x05 ,0x00 }, { 21550 /*100 kHz*/ ,0x05 ,0x00 }, { 21700 /*100 kHz*/ ,0x05 ,0x00 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x1C ,0x38 }, { 21250 /*100 kHz*/ ,0x1C ,0x38 }, { 21400 /*100 kHz*/ ,0x1C ,0x38 }, { 21550 /*100 kHz*/ ,0x1C ,0x38 }, { 21700 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 21100 /*100 kHz*/ ,0x01 ,0x00 }, { 21250 /*100 kHz*/ ,0x01 ,0x00 }, { 21400 /*100 kHz*/ ,0x01 ,0x00 }, { 21550 /*100 kHz*/ ,0x01 ,0x00 }, { 21700 /*100 kHz*/ ,0x01 ,0x00 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                   ,{ { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE22__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route22_MIPI_RX_DATA_SetDefault[] =
{
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x05 ,0x03 }, { 18238 /*100 kHz*/ ,0x05 ,0x03 }, { 18425 /*100 kHz*/ ,0x05 ,0x03 }, { 18612 /*100 kHz*/ ,0x05 ,0x03 }, { 18800 /*100 kHz*/ ,0x05 ,0x03 },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18050 /*100 kHz*/ ,0x01 ,0x02 }, { 18238 /*100 kHz*/ ,0x01 ,0x02 }, { 18425 /*100 kHz*/ ,0x01 ,0x02 }, { 18612 /*100 kHz*/ ,0x01 ,0x02 }, { 18800 /*100 kHz*/ ,0x01 ,0x02 },} },
   { /* 4  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 5  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0_P3   ,{ { 18050 /*100 kHz*/ ,0x05 ,0x00 }, { 18238 /*100 kHz*/ ,0x05 ,0x00 }, { 18425 /*100 kHz*/ ,0x05 ,0x00 }, { 18612 /*100 kHz*/ ,0x05 ,0x00 }, { 18800 /*100 kHz*/ ,0x05 ,0x00 },} },
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18050 /*100 kHz*/ ,0x1C ,0x38 }, { 18238 /*100 kHz*/ ,0x1C ,0x38 }, { 18425 /*100 kHz*/ ,0x1C ,0x38 }, { 18612 /*100 kHz*/ ,0x1C ,0x38 }, { 18800 /*100 kHz*/ ,0x1C ,0x38 },} },
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM1_P3   ,{ { 18050 /*100 kHz*/ ,0x00 ,0x00 }, { 18238 /*100 kHz*/ ,0x01 ,0x00 }, { 18425 /*100 kHz*/ ,0x01 ,0x00 }, { 18612 /*100 kHz*/ ,0x01 ,0x00 }, { 18800 /*100 kHz*/ ,0x01 ,0x00 },} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                   ,{ { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    }, { 0     /*100 kHz*/ ,0    ,0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE23__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route23_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE24__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route24_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE25__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route25_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE26__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route26_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE27__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route27_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE28__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route28_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE29__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route29_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE30__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route30_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE31__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route31_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE32__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route32_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE33__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route33_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE34__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route34_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE35__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route35_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE36__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route36_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE37__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route37_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE38__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route38_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE39__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route39_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE40__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route40_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE41__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route41_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE42__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route42_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE43__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route43_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE44__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route44_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE45__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route45_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE46__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route46_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE47__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route47_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE48__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route48_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE49__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route49_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE50__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route50_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE51__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route51_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE52__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route52_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE53__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route53_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE54__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route54_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE55__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route55_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE56__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route56_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE57__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route57_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

#ifdef  __MIPI_RX_ROUTE58__
LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Route58_MIPI_RX_DATA_SetDefault[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband-0 freq, addr, data }, { subband-1 freq, addr, data }, { subband-2 freq, addr, data }, { subband-3 freq, addr, data }, { subband-4 freq, addr, data },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_ASM0   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM1   ,{ {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF }, {              0, 0xFF, 0xFF },} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    }, {              0, 0   , 0    },} },
};
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

