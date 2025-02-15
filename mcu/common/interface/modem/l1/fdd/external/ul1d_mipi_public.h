/*******************************************************************************
*  Modification Notice :
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


/*****************************************************************************
 *
 * Filename:
 * ---------
 * ul1d_mipi_public.h
 *
 * Project:
 * --------
 *   3G Project Common File
 *
 * Description:
 * ------------
 *   Definition of some of customization setting not defined in ul1d_custom_rf.h
 *   And the stuff needs to be recognized by UL1D external module (wdata.c)
 *   Also some of data structure, global data, global function prototypes to be used
 *   by inter-category module (e.g. NVRAM)
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
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
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UL1D_MIPI_PUBLIC_H
#define UL1D_MIPI_PUBLIC_H


/*******************************************************************************
** Includes
*******************************************************************************/
#if defined(__PCORE__)
#include "ul1d_custom_rf_ca.h"
#endif
#include "ul1d_rf_public.h"
#include "mml1_mipi_public.h"

#if (IS_3G_MIPI_SUPPORT)
/*******************************************************************************
** Constants
*******************************************************************************/
/////////////////////////
//Should not modify
//(2ASM + 4ATs for RX main & diversity; RX main:2ATs, RX diversity:2ATs)
#define UL1_MIPI_RX_EVENT_NUM    24
#define UL1_MIPI_RX_DATA_NUM     28

#define UL1_MIPI_INIT_DATA_NUM    8

   //(1ASM + 2AT + PA for TX)
#define UL1_MIPI_TX_EVENT_NUM    16
#if (IS_3G_ET_SUPPORT)
#define UL1_MIPI_TX_DATA_NUM     28
#else
#define UL1_MIPI_TX_DATA_NUM     18
#endif

   //(For MIPI PA META UI tuning)
#define UL1_META_MIPI_PA_SECTION_NUM       8
#define UL1_META_MIPI_PA_SECTION_DATA_NUM  4
   
#define UL1_MIPI_TPC_EVENT_NUM   8
#define UL1_MIPI_TPC_DATA_NUM   40
   
   //(PA setting of TPC set)
#define UL1_MIPI_PA_SECTION_NUM       8
#define UL1_MIPI_PA_SECTION_DATA_NUM  5

#if (IS_3G_ET_SUPPORT)
#define UL1_MIPI_ET_CHIP_TYPE  ETM_MTK_MT6300
#define UL1_MIPI_ET_EVENT_NUM   8    /* 2 + 2 + 8 + 8 + 8 = 28 */
#define UL1_MIPI_ET_DATA_NUM   40   /* default 28 */
#define UL1_MIPI_ET_CW_NUM     5
#define UL1_MIPI_ET_SECTION_DATA_NUM  5

#define UL1_ET_MAX_LV_NUM      1

#define UL1_ET_DAC_CW_OFFSET   1
#define UL1_ET_EA_CW_OFFSET    2

#define UL1_ET_DAC_RANGE       8
#endif

#define MIPI_SUBBAND_NUM   5    /*Max subband number is 5*/
   
   //the first band is UMTSBandNone, actually support 5 bands
#define UL1_MIPI_MAX_BAND_NUM   (5+1)
   
#define UL1_MIPI_DATA_NULL      0x0000
   
   //port slectiong
#if defined(TK6291)
#define UL1_MIPI_PORT0          0x0002 /*3G module device C*/
#define UL1_MIPI_PORT1          0x0003 /*3G module device D*/
#define UL1_MIPI_PORT_OFFSET_TO_MML1 (0)
#define UL1_MIPI_PORT_OFFSET_TO_MML1_R (MML1_RF_MIPI0-UL1_MIPI_PORT0)
#else
#define UL1_MIPI_PORT0          0x0000 /*3G module device A*/
#define UL1_MIPI_PORT1          0x0001 /*3G module device B*/
#define UL1_MIPI_PORT2          0x0002 /*3G module device C*/
#define UL1_MIPI_PORT3          0x0003 /*3G module device D*/
#define UL1_MIPI_PORT_OFFSET_TO_MML1 (2) /*MML1 use Port0/1/2/3 with value 2/3/4/5*/
#define UL1_MIPI_PORT_OFFSET_TO_MML1_R (MML1_RF_MIPI0-UL1_MIPI_PORT0) /*MML1 use Port0/1/2/3 with value 2/3/4/5*/
#endif

#define UL1_MIPI_PORT0_MSK      (0x1<<(UL1_MIPI_PORT0))
#define UL1_MIPI_PORT1_MSK      (0x1<<(UL1_MIPI_PORT1))
   
#define MIPI_DATA_IDX(start,stop)  (((stop)<<8)|(start))
   
//event type
#define UL1_MIPI_TRX_ON         0x0001
#define UL1_MIPI_TRX_OFF        0x0002
#define UL1_MIPI_TPC_SET        0x0003 
#if (IS_3G_ET_SUPPORT)
#define UL1_MIPI_ET_SET         0x0004 
#define UL1_MIPI_HPUE_SET       0x0005 
#endif
#define UL1_MIPI_EVENT_NULL     0x0000
   
//element type
#define UL1_MIPI_NULL           0x0000
#define UL1_MIPI_ASM            0x0001
#define UL1_MIPI_ANT            0x0002
#define UL1_MIPI_PA             0x0003
#if (IS_3G_ET_SUPPORT)
#define UL1_MIPI_ET             0x0004
#define UL1_MIPI_HPUE           0x0005
#endif
#if IS_3G_DAT_UL1_CUSTOM_SUPPORT
#define UL1_MIPI_DAT            0x0006
#endif

#define UL1_MIPI_END       0xFFFF
   
//data write seq. format
#define UL1_SEQ_NULL             0x0000
#define UL1_REG_0_W              MML1_REG_0_W
#define UL1_REG_W                MML1_REG_W
#define UL1_REG_W_EXT_1ST        MML1_REG_W_EXT_1ST
#define UL1_REG_W_EXT_BYTE       MML1_REG_W_EXT_BYTE
#define UL1_REG_W_EXT_END        MML1_REG_W_EXT_END
#define UL1_IMM_BSI_WAIT         MML1_IMM_BSI_WAIT
#if IS_3G_MIPI_EXTENDED_READ_ENABLE
#define UL1_REG_EXT_R            MML1_REG_R_EXT_ONLY_ONE_BYTE
#define UL1_REG_R                MML1_REG_R
#endif


//TPC PA SECTION DATA PATTERN
#define UL1_MIPI_PA_SECTION_DATA0   0x10000000
#define UL1_MIPI_PA_SECTION_DATA1   0x10000001
#define UL1_MIPI_PA_SECTION_DATA2   0x10000002
#define UL1_MIPI_PA_SECTION_DATA3   0x10000003
   
#define US2CHIPCNT(us)       ((us)*3.84)
   
#define UL1_MIPI_MAX_INITIAL_CW_NUM   30
   
#define UL1_MIPI_MAX_SLEEP_CW_NUM     20

#define MIPI_MAX_INITIAL_IMM_BSI_CW_NUM   UL1_MIPI_INIT_DATA_NUM

#define MIPI_MAX_SLEEP_IMM_BSI_CW_NUM     20

#define MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM     1

#if IS_3G_ET_SUPPORT
#define ET_MAX_ON_IMM_BSI_CW_NUM   30
#define ET_MAX_OFF_IMM_BSI_CW_NUM  20

#define M_VPA_2_ET_CW_1ST(n,m,d) (((n*m)/d)&0x7F)
#define M_VPA_2_ET_CW_2ND(n,m,d) 0x00
#define M_VPA_2_ET_CW_3RD(n,m,d) 0x00
#endif

#if IS_3G_DAT_UL1_CUSTOM_SUPPORT
#define UL1_MIPI_DAT_EVENT_NUM        (8)
#define UL1_MIPI_DAT_DATA_NUM         (20)
#define UL1_MIPI_DAT_ROUTE_A_NUM      (UMTS_DAT_MAX_CAT_A_ROUTE_NUM)
#define UL1_MIPI_DAT_ROUTE_B_NUM      (UMTS_DAT_MAX_CAT_B_ROUTE_NUM)
#define UL1_DAT_NO_SPLIT_BAND         (0xFF)
#endif

/*******************************************************************************
** Macro define
*******************************************************************************/   
#if defined(__PCORE__)
#define M_UMTS_MIPI_RX_EVENT(x, sET) UMTS_MIPI_RX_EVENT_##x##_##sET
#define M_UMTS_RX_EVENT(x, sET)      M_UMTS_MIPI_RX_EVENT(x, sET)

#define M_UMTS_MIPI_RX_DATA(x,sET)  UMTS_MIPI_RX_DATA_##x##_##sET
#define M_UMTS_RX_DATA(x,sET)       M_UMTS_MIPI_RX_DATA(x,sET)

#define M_UMTS_MIPI_TX_EVENT(x,sET) UMTS_MIPI_TX_EVENT_##x##_##sET
#define M_UMTS_TX_EVENT(x,sET)      M_UMTS_MIPI_TX_EVENT(x,sET)

#define M_UMTS_MIPI_TX_DATA(x,sET)  UMTS_MIPI_TX_DATA_##x##_##sET
#define M_UMTS_TX_DATA(x,sET)       M_UMTS_MIPI_TX_DATA(x,sET)

#define M_UMTS_MIPI_TPC(x,sET)      &UMTS_MIPI_TPC_##x##_##sET
#define M_UMTS_TPC(x,sET)           M_UMTS_MIPI_TPC(x,sET)

#define M_UMTS_MIPI_ASM_ISO(x,sET)   UMTS_MIPI_ASM_ISOLATION_DATA_##x##_##sET
#define M_UMTS_ASM_ISO(x,sET)        M_UMTS_MIPI_ASM_ISO(x,sET)

#if (IS_3G_ET_SUPPORT)
#define M_UMTS_MIPI_ET(x,sET)       &UMTS_MIPI_ET_##x##_##sET
#define M_UMTS_ET(x,sET)            M_UMTS_MIPI_ET(x,sET)

#define M_UMTS_MIPI_ET_EVENT(x,sET) UMTS_MIPI_ET_##x##_##sET.umts_mipi_et_event
#define M_UMTS_ET_EVENT(x,sET)      M_UMTS_MIPI_ET_EVENT(x,sET)

#define M_UMTS_MIPI_ET_DATA(x,sET)  UMTS_MIPI_ET_##x##_##sET.umts_mipi_et_data
#define M_UMTS_ET_DATA(x,sET)       M_UMTS_MIPI_ET_DATA(x,sET)

#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
#define M_UMTS_VPA_SRC_SEL(x,sET)   &UMTS_VPA_SOURCE_##x##_##sET
#define M_UMTS_VPA_SRC(x,sET)       M_UMTS_VPA_SRC_SEL(x,sET)
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#endif/*IS_3G_ET_SUPPORT*/


/*------------------*/
/* Macro Definition */
/*------------------*/
#define M_UMTS_ROUTE_OF_CACFG_IND(i,c,x)   i##_CC##c##_##x##_MIPI_TBL_IDX
#define M_UMTS_ROUTE_OF(i,c,x)             M_UMTS_ROUTE_OF_CACFG_IND(i,c,x)

#define M_CONSTRUCT_ROUTE(r)    (1<<(r&0xF))
#define M_ROUTE_MAP_IND(i,x)    (M_CONSTRUCT_ROUTE(M_UMTS_ROUTE_OF(i,0,x)) | M_CONSTRUCT_ROUTE(M_UMTS_ROUTE_OF(i,1,x)))
#define M_ROUTE_MAP_GROUP(x)    (M_ROUTE_MAP_IND(RX_CABAND_IND_00,x) | M_ROUTE_MAP_IND(RX_CABAND_IND_01,x) | \
                                 M_ROUTE_MAP_IND(RX_CABAND_IND_02,x) | M_ROUTE_MAP_IND(RX_CABAND_IND_03,x) | \
                                 M_ROUTE_MAP_IND(RX_CABAND_IND_04,x))

/*------------------------*/
/* MIPI RX Route Settings */
/*------------------------*/
/*Single Band*/ #if M_ROUTE_MAP_GROUP(RX) & (1<<0)
/*Single Band*/ #define  __UMTS_MIPI_RX_ROUTE0__
/*Single Band*/ #endif
/*Single Band*/
/*Single Band*/ #if M_ROUTE_MAP_GROUP(RX) & (1<<1)
/*Single Band*/ #define  __UMTS_MIPI_RX_ROUTE1__
/*Single Band*/ #endif
/*Single Band*/
/*Single Band*/ #if M_ROUTE_MAP_GROUP(RX) & (1<<2)
/*Single Band*/ #define  __UMTS_MIPI_RX_ROUTE2__
/*Single Band*/ #endif
/*Single Band*/
/*Single Band*/ #if M_ROUTE_MAP_GROUP(RX) & (1<<3)
/*Single Band*/ #define  __UMTS_MIPI_RX_ROUTE3__
/*Single Band*/ #endif
/*Single Band*/
/*Single Band*/ #if M_ROUTE_MAP_GROUP(RX) & (1<<4)
/*Single Band*/ #define  __UMTS_MIPI_RX_ROUTE4__
/*Single Band*/ #endif

/*  CA Band  */ #if M_ROUTE_MAP_GROUP(RX) & (1<<5)
/*  CA Band  */ #define  __UMTS_MIPI_RX_ROUTE5__
/*  CA Band  */ #endif
/*  CA Band  */    
/*  CA Band  */ #if M_ROUTE_MAP_GROUP(RX) & (1<<6)
/*  CA Band  */ #define  __UMTS_MIPI_RX_ROUTE6__
/*  CA Band  */ #endif
/*  CA Band  */   
/*  CA Band  */ #if M_ROUTE_MAP_GROUP(RX) & (1<<7)
/*  CA Band  */ #define  __UMTS_MIPI_RX_ROUTE7__
/*  CA Band  */ #endif
/*  CA Band  */ 
/*  CA Band  */ #if M_ROUTE_MAP_GROUP(RX) & (1<<8)
/*  CA Band  */ #define  __UMTS_MIPI_RX_ROUTE8__
/*  CA Band  */ #endif
/*  CA Band  */   
/*  CA Band  */ #if M_ROUTE_MAP_GROUP(RX) & (1<<9)
/*  CA Band  */ #define  __UMTS_MIPI_RX_ROUTE9__
/*  CA Band  */ #endif
/*  CA Band  */ 
/*  CA Band  */ #if M_ROUTE_MAP_GROUP(RX) & (1<<10)
/*  CA Band  */ #define  __UMTS_MIPI_RX_ROUTE10__
/*  CA Band  */ #endif
/*  CA Band  */   
/*  CA Band  */ #if M_ROUTE_MAP_GROUP(RX) & (1<<11)
/*  CA Band  */ #define  __UMTS_MIPI_RX_ROUTE11__
/*  CA Band  */ #endif
/*  CA Band  */
/*  CA Band  */ #if M_ROUTE_MAP_GROUP(RX) & (1<<12)
/*  CA Band  */ #define  __UMTS_MIPI_RX_ROUTE12__
/*  CA Band  */ #endif
/*  CA Band  */
/*  CA Band  */ #if M_ROUTE_MAP_GROUP(RX) & (1<<13)
/*  CA Band  */ #define  __UMTS_MIPI_RX_ROUTE13__
/*  CA Band  */ #endif
/*  CA Band  */
/*  CA Band  */ #if M_ROUTE_MAP_GROUP(RX) & (1<<14)
/*  CA Band  */ #define  __UMTS_MIPI_RX_ROUTE14__
/*  CA Band  */ #endif


/*-----------------------*/
/* RX CA Common Settings */
/*-----------------------*/
#ifdef __UMTS_MIPI_RX_ROUTE5__
#define MIPI_RX_ROUTE_IND_5         UMTS_Route5
#else
#define MIPI_RX_ROUTE_IND_5         UMTSBandNone
#endif

#ifdef __UMTS_MIPI_RX_ROUTE6__
#define MIPI_RX_ROUTE_IND_6         UMTS_Route6
#else
#define MIPI_RX_ROUTE_IND_6         UMTSBandNone
#endif

#ifdef __UMTS_MIPI_RX_ROUTE7__
#define MIPI_RX_ROUTE_IND_7         UMTS_Route7
#else
#define MIPI_RX_ROUTE_IND_7         UMTSBandNone
#endif

#ifdef __UMTS_MIPI_RX_ROUTE8__
#define MIPI_RX_ROUTE_IND_8         UMTS_Route8
#else
#define MIPI_RX_ROUTE_IND_8         UMTSBandNone
#endif

#ifdef __UMTS_MIPI_RX_ROUTE9__
#define MIPI_RX_ROUTE_IND_9         UMTS_Route9
#else
#define MIPI_RX_ROUTE_IND_9         UMTSBandNone
#endif

#ifdef __UMTS_MIPI_RX_ROUTE10__
#define MIPI_RX_ROUTE_IND_10        UMTS_Route10
#else
#define MIPI_RX_ROUTE_IND_10        UMTSBandNone
#endif

#ifdef __UMTS_MIPI_RX_ROUTE11__
#define MIPI_RX_ROUTE_IND_11        UMTS_Route11
#else
#define MIPI_RX_ROUTE_IND_11        UMTSBandNone
#endif

#ifdef __UMTS_MIPI_RX_ROUTE12__
#define MIPI_RX_ROUTE_IND_12        UMTS_Route12
#else
#define MIPI_RX_ROUTE_IND_12        UMTSBandNone
#endif

#ifdef __UMTS_MIPI_RX_ROUTE13__
#define MIPI_RX_ROUTE_IND_13        UMTS_Route13
#else
#define MIPI_RX_ROUTE_IND_13        UMTSBandNone
#endif

#ifdef __UMTS_MIPI_RX_ROUTE14__
#define MIPI_RX_ROUTE_IND_14        UMTS_Route14
#else
#define MIPI_RX_ROUTE_IND_14        UMTSBandNone
#endif

#endif
/*******************************************************************************
** Typedefs
*******************************************************************************/
typedef struct
{
   kal_uint16 mipi_data_st;//mipi data start index
   kal_uint16 mipi_data_sp;//mipi data stop index
}UL1_MIPI_DATA_STSP;

typedef struct
{
   kal_uint16 addr;
   kal_uint32 data;
}UL1_MIPI_ADDR_DATA_EXPAND_TABLE_T;

typedef struct
{
   kal_uint16 mipi_elm_type;     //mipi element type
   UL1_MIPI_DATA_STSP mipi_data_stsp;
   kal_uint16 mipi_evt_type;     //event type
   kal_uint32 mipi_evt_offset;   //event offset
}UL1_MIPI_EVENT_TABLE_T;

typedef struct
{
   kal_uint16 mipi_subband_freq; // Port where data to send
   UL1_MIPI_ADDR_DATA_EXPAND_TABLE_T mipi_data; // mipi data
}UL1_MIPI_DATA_EXPAND_TABLE_T;       //expanded by sub-freq

typedef struct
{
   kal_uint16 mipi_elm_type;                                     //mipi element type
   kal_uint16 mipi_port_sel;                                     //0:for Port0, 1:for Port1 
   kal_uint16 mipi_data_seq;                                     // data write sequence format
   kal_uint16 mipi_usid;                                         //mipi USID   
   UL1_MIPI_DATA_EXPAND_TABLE_T mipi_subband_data[MIPI_SUBBAND_NUM]; // mipi data
}UL1_MIPI_DATA_SUBBAND_TABLE_T;

typedef struct
{
   kal_uint16 mipi_elm_type;                                     //mipi element type
   kal_uint16 mipi_port_sel;                                     //0:for Port0, 1:for Port1 
   kal_uint16 mipi_data_seq;                                     // data write sequence format
   kal_uint16 mipi_usid;                                         //mipi USID      
   UL1_MIPI_ADDR_DATA_EXPAND_TABLE_T mipi_data;                  // mipi data
}UL1_MIPI_DATA_TABLE_T;

typedef struct
{
   UL1_MIPI_EVENT_TABLE_T         umts_mipi_tpc_event[UL1_MIPI_TPC_EVENT_NUM];
   UL1_MIPI_DATA_SUBBAND_TABLE_T  umts_mipi_tpc_data[UL1_MIPI_TPC_DATA_NUM];    
}UL1_UMTS_MIPI_TPC_T;

typedef struct
{
   kal_uint16 mipi_subband_freq;
   kal_uint32 mipi_pa_tpc_data[UL1_MIPI_PA_SECTION_NUM][UL1_MIPI_PA_SECTION_DATA_NUM];
}UL1_MIPI_PA_TPC_SECTION_TABLE_T;

typedef UL1_UMTS_MIPI_TPC_T ul1mipi_tpcData_T;

#if (IS_3G_ET_SUPPORT)
typedef struct
{
   UL1_MIPI_EVENT_TABLE_T         umts_mipi_et_event[UL1_MIPI_ET_EVENT_NUM];
   UL1_MIPI_DATA_SUBBAND_TABLE_T  umts_mipi_et_data[UL1_MIPI_ET_DATA_NUM];
}UL1_UMTS_MIPI_ET_T;

typedef struct
{
   kal_uint32 multiplier;
   kal_uint32 divisor;
}UL1_VPA_2_ET_CW_COEFF_T;

typedef struct
{
   UL1_VPA_2_ET_CW_COEFF_T vpa2EtCw[UL1_ET_MAX_LV_NUM];                /*Vpa to ET CW coefficient, 3 levels*/
   kal_uint32              etDac2ErrAmpComp_table[UL1_ET_DAC_RANGE];   /*ET DAC to error amp compensation mapping table*/
}UL1_UMTS_MIPI_ET_PARAM_T;

typedef kal_uint32 (*funcptr)(kal_uint8, kal_uint32);

#endif/*IS_3G_ET_SUPPORT*/


#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
typedef struct
{
   UL1_MIPI_DATA_SUBBAND_TABLE_T mipiTxData[UL1_MIPI_TX_DATA_NUM]; 
}ul1mipi_txData_T;

typedef struct
{
   UL1_MIPI_DATA_TABLE_T mipiAsmIsoData[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]; 
}ul1mipi_asmIsoData_T;

typedef struct
{
   UL1_MIPI_EVENT_TABLE_T mipiTxEvent[UL1_MIPI_TX_EVENT_NUM]; 
}ul1mipi_txEvent_T;

typedef struct
{
   UL1_MIPI_DATA_SUBBAND_TABLE_T mipiRxData[UL1_MIPI_RX_DATA_NUM]; 
}ul1mipi_rxData_T;

typedef struct
{
   UL1_MIPI_EVENT_TABLE_T mipiRxEvent[UL1_MIPI_RX_EVENT_NUM]; 
}ul1mipi_rxEvent_T;

typedef struct
{
   UL1_MIPI_DATA_TABLE_T mipiInitData[MIPI_MAX_INITIAL_IMM_BSI_CW_NUM]; 
}ul1mipi_initCwData_T;

typedef struct
{
   UL1_MIPI_DATA_TABLE_T mipiSleepData[MIPI_MAX_SLEEP_IMM_BSI_CW_NUM]; 
}ul1mipi_sleepCwData_T;

#if (IS_3G_ET_NVRAM_SUPPORT)
typedef UL1_UMTS_MIPI_ET_T ul1mipi_etData_T;

typedef struct
{
   UL1_MIPI_DATA_TABLE_T mipiEtOnData[ET_MAX_ON_IMM_BSI_CW_NUM]; 
}ul1mipi_etOnCwData_T;

typedef struct
{
   UL1_MIPI_DATA_TABLE_T mipiEtOffData[ET_MAX_OFF_IMM_BSI_CW_NUM]; 
}ul1mipi_etOffCwData_T;

typedef struct
{
   UL1_UMTS_MIPI_ET_PARAM_T mipiEtParam;
}ul1mipi_etparam_T;


#endif/*IS_3G_ET_NVRAM_SUPPORT*/

#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
#define ET_VPA_SOURCE_NOT_SUPPORTED   0
#define ET_VPA_SOURCE_HW_V_BATTERY    1
#define ET_VPA_SOURCE_HW_PMIC         2
#define ET_VPA_SOURCE_HW_ETM_SW_APT   3
#define ET_VPA_SOURCE_HW_ETM_SW_ET    4
#define ET_VPA_SOURCE_HW_PMIC_ETM_APT 5
#define ET_VPA_SOURCE_HW_HPUE         6


typedef enum
{   
    UMTS_VPA_SOURCE_INVALID_T = ET_VPA_SOURCE_NOT_SUPPORTED,   
    UMTS_VPA_SOURCE_VBAT_T    = ET_VPA_SOURCE_HW_V_BATTERY,   
    UMTS_VPA_SOURCE_PMIC_T    = ET_VPA_SOURCE_HW_PMIC,   
    UMTS_VPA_SOURCE_ETM_APT_T = ET_VPA_SOURCE_HW_ETM_SW_APT,   
    UMTS_VPA_SOURCE_ETM_ET_T       = ET_VPA_SOURCE_HW_ETM_SW_ET,    
    UMTS_VPA_SOURCE_ETM_APT_PMIC_T = ET_VPA_SOURCE_HW_PMIC_ETM_APT,
    UMTS_VPA_SOURCE_HPUE_T = ET_VPA_SOURCE_HW_HPUE
} 
UMTS_VPA_SOURCE_TYPE;

typedef struct
{
   UMTS_VPA_SOURCE_TYPE vpaSel;
}
ul1vpa_sel_T;

#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#endif/*IS_3G_MIPI_NVRAM_FULL_SUPPORT*/

#if (IS_3G_MIPI_SUPPORT)
typedef enum
{
   MIPI_DEFAULT = 0,
   MIPI_DISABLE = 1,
   MIPI_ENABLE  = 2
   #if (IS_3G_ET_SUPPORT)
  ,MIPI_ET_ENABLE  = 3
   #endif
}MIPI_Setting;


#endif

#if IS_3G_DAT_UL1_CUSTOM_SUPPORT
typedef struct
{
   UL1_MIPI_EVENT_TABLE_T mipiDatEvent[UL1_MIPI_DAT_EVENT_NUM];
}ul1mipi_datEvent_T;

typedef struct
{
   ul1mipi_datEvent_T mipiDatEventRoute[UL1_MIPI_DAT_ROUTE_A_NUM];
}ul1mipi_datEvent_CatA_T;

typedef struct
{
   ul1mipi_datEvent_T mipiDatEventRoute[UL1_MIPI_DAT_ROUTE_B_NUM];
}ul1mipi_datEvent_CatB_T;

typedef struct
{
   UL1_MIPI_DATA_SUBBAND_TABLE_T mipiDatData[UL1_MIPI_DAT_DATA_NUM]; 
}ul1mipi_datSubBandData_T;

typedef struct
{
   ul1mipi_datSubBandData_T mipiDatDataRoute[UL1_MIPI_DAT_ROUTE_A_NUM];
}ul1mipi_datData_CatA_T;

typedef struct
{
   ul1mipi_datSubBandData_T mipiDatDataRoute[UL1_MIPI_DAT_ROUTE_B_NUM];
}ul1mipi_datData_CatB_T;
#endif
/*******************************************************************************
** Function Prototype
*******************************************************************************/

#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
void nvram_init_uL1_mipiTxData(void);
void nvram_init_uL1_mipiTxEvent(void);
void nvram_init_uL1_mipiRxData(void);
void nvram_init_uL1_mipiRxEvent(void);
void nvram_init_uL1_mipiInitCw(void);
void nvram_init_uL1_mipiSleepCw(void);
#if (IS_3G_ET_NVRAM_SUPPORT)
void nvram_init_uL1_mipiEtOnCw(void);
void nvram_init_uL1_mipiEtOffCw(void);
void nvram_init_uL1_mipiEtParam(void);
#endif/*IS_3G_ET_NVRAM_SUPPORT*/

#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
void nvram_init_uL1_vpaSrcSel(void);
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#endif/*IS_3G_MIPI_NVRAM_FULL_SUPPORT*/


/*******************************************************************************
** Global Extern Func and Variables
*******************************************************************************/
#if defined(__PCORE__)
extern UL1_MIPI_EVENT_TABLE_T         *UMTS_MIPI_RX_EVENT_TABLE[UMTS_MIPI_RX_TBL_SIZE];
#elif defined(__L1CORE__)
extern UL1_MIPI_EVENT_TABLE_T         *UMTS_MIPI_RX_EVENT_TABLE[UMTS_MIPI_RX_TBL_SIZE];
#endif
extern UL1_MIPI_DATA_SUBBAND_TABLE_T  *UMTS_MIPI_RX_DATA_TABLE[UMTS_MIPI_RX_TBL_SIZE];
extern UL1_MIPI_EVENT_TABLE_T         *UMTS_MIPI_TX_EVENT_TABLE[UL1D_RF_CUSTOM_BAND];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T  *UMTS_MIPI_TX_DATA_TABLE[UL1D_RF_CUSTOM_BAND];
extern UL1_UMTS_MIPI_TPC_T            *UMTS_MIPI_TPC_TABLE[UL1D_RF_CUSTOM_BAND];
extern UL1_MIPI_DATA_TABLE_T          UMTS_MIPI_INITIAL_CW[UL1_MIPI_INIT_DATA_NUM];
extern UL1_MIPI_DATA_TABLE_T          *UMTS_MIPI_ASM_ISOLATION_DATA_TABLE[UL1D_RF_CUSTOM_BAND];
#if (IS_3G_ET_SUPPORT)
extern UL1_UMTS_MIPI_ET_T             *UMTS_MIPI_ET_TABLE[UL1D_RF_CUSTOM_BAND];
//extern UL1_MIPI_DATA_TABLE_T          UMTS_MIPI_ET_ON_STATIC_CW[ET_MAX_ON_IMM_BSI_CW_NUM];
//extern UL1_MIPI_DATA_TABLE_T          UMTS_MIPI_ET_OFF_STATIC_CW[ET_MAX_OFF_IMM_BSI_CW_NUM];
extern UL1_MIPI_DATA_TABLE_T          *UMTS_MIPI_ET_ON_STATIC_CW;
extern UL1_MIPI_DATA_TABLE_T          *UMTS_MIPI_ET_OFF_STATIC_CW;

extern UL1_UMTS_MIPI_ET_PARAM_T       *UL1_ET_PARAM_ptr;
#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
extern UMTS_VPA_SOURCE_TYPE           *UMTS_VPA_SRC_SEL_TABLE[UL1D_RF_CUSTOM_BAND];
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/
#endif/*IS_3G_ET_SUPPORT*/

extern UL1_MIPI_EVENT_TABLE_T         *UMTS_MIPI_RX_EVENT_PCORE_TABLE[UMTS_MIPI_RX_TBL_SIZE];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T  *UMTS_MIPI_RX_DATA_PCORE_TABLE[UMTS_MIPI_RX_TBL_SIZE];
extern UL1_MIPI_EVENT_TABLE_T         *UMTS_MIPI_TX_EVENT_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T  *UMTS_MIPI_TX_DATA_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
extern UL1_UMTS_MIPI_TPC_T            *UMTS_MIPI_TPC_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
extern UL1_MIPI_DATA_TABLE_T          *UMTS_MIPI_INITIAL_CW_PCORE_ptr;
extern UL1_MIPI_DATA_TABLE_T          *UMTS_MIPI_SLEEP_CW_PCORE_ptr;
extern UL1_MIPI_DATA_TABLE_T          *UMTS_MIPI_ASM_ISOLATION_DATA_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
#if (IS_3G_ET_SUPPORT)
extern UL1_UMTS_MIPI_ET_T             *UMTS_MIPI_ET_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
extern UL1_MIPI_DATA_TABLE_T          *UMTS_MIPI_ET_ON_STATIC_CW_PCORE_ptr;
extern UL1_MIPI_DATA_TABLE_T          *UMTS_MIPI_ET_OFF_STATIC_CW_PCORE_ptr;
extern UL1_UMTS_MIPI_ET_PARAM_T       *UL1_ET_PARAM_PCORE_ptr;
#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
extern UMTS_VPA_SOURCE_TYPE           *UMTS_VPA_SRC_SEL_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/
#endif/*IS_3G_ET_SUPPORT*/


#if IS_3G_ET_SUPPORT
extern kal_bool is_3g_et_enable;
extern kal_uint32 etCwValueDumpAllTable[UL1_MIPI_ET_CW_NUM];
extern kal_uint32 etCwAddrDump[UL1_MIPI_ET_CW_NUM];
extern kal_uint32 etCwNum;
//kal_uint32 ul1_mipi_usid_et = MIPI_USID_ETM;
//kal_uint32 ul1_mipi_port_et = MML1_ET_MIPI_PORT;

//kal_uint32 etBsiPort = UL1_MIPI_PORT_ET;
//kal_uint32 etUsid    = MIPI_USID_ETM;
#endif


#ifdef __UMTS_MIPI_RX_ROUTE5__
extern UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTS_Route5[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTS_Route5[];
#endif
#ifdef __UMTS_MIPI_RX_ROUTE6__
extern UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTS_Route6[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTS_Route6[];
#endif
#ifdef __UMTS_MIPI_RX_ROUTE7__
extern UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTS_Route7[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTS_Route7[];
#endif
#ifdef __UMTS_MIPI_RX_ROUTE8__
extern UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTS_Route8[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTS_Route8[];
#endif
#ifdef __UMTS_MIPI_RX_ROUTE9__
extern UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTS_Route9[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTS_Route9[];
#endif
#ifdef __UMTS_MIPI_RX_ROUTE10__
extern UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTS_Route10[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTS_Route10[];
#endif
#ifdef __UMTS_MIPI_RX_ROUTE11__
extern UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTS_Route11[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTS_Route11[];
#endif
#ifdef __UMTS_MIPI_RX_ROUTE12__
extern UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTS_Route12[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTS_Route12[];
#endif
#ifdef __UMTS_MIPI_RX_ROUTE13__
extern UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTS_Route13[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTS_Route13[];
#endif
#ifdef __UMTS_MIPI_RX_ROUTE14__
extern UL1_MIPI_EVENT_TABLE_T UMTS_MIPI_RX_EVENT_UMTS_Route14[];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T UMTS_MIPI_RX_DATA_UMTS_Route14[];
#endif

#if IS_3G_DAT_UL1_CUSTOM_SUPPORT
extern UL1_MIPI_EVENT_TABLE_T         *UMTS_MIPI_DAT_CAT_A_EVENT_TABLE_ptr[UL1_MIPI_DAT_ROUTE_A_NUM];
extern UL1_MIPI_EVENT_TABLE_T         *UMTS_MIPI_DAT_CAT_B_EVENT_TABLE_ptr[UL1_MIPI_DAT_ROUTE_B_NUM];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T  *UMTS_MIPI_DAT_CAT_A_DATA_TABLE_ptr[UL1_MIPI_DAT_ROUTE_A_NUM];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T  *UMTS_MIPI_DAT_CAT_B_DATA_TABLE_ptr[UL1_MIPI_DAT_ROUTE_B_NUM];

extern UL1_MIPI_EVENT_TABLE_T         *UMTS_DAT_CAT_A_MIPI_EVENT_TABLE_PCORE_ptr[UL1_MIPI_DAT_ROUTE_A_NUM];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T  *UMTS_DAT_CAT_A_MIPI_DATA_TABLE_PCORE_ptr[UL1_MIPI_DAT_ROUTE_A_NUM];
extern UL1_MIPI_EVENT_TABLE_T         *UMTS_DAT_CAT_B_MIPI_EVENT_TABLE_PCORE_ptr[UL1_MIPI_DAT_ROUTE_B_NUM];
extern UL1_MIPI_DATA_SUBBAND_TABLE_T  *UMTS_DAT_CAT_B_MIPI_DATA_TABLE_PCORE_ptr[UL1_MIPI_DAT_ROUTE_B_NUM];

extern const UL1_MIPI_EVENT_TABLE_T*         UMTS_DAT_CAT_A_MIPI_EVENT_TABLE_SetDefault[];
extern const UL1_MIPI_DATA_SUBBAND_TABLE_T*  UMTS_DAT_CAT_A_MIPI_DATA_TABLE_SetDefault[];
extern const UL1_MIPI_EVENT_TABLE_T*         UMTS_DAT_CAT_B_MIPI_EVENT_TABLE_SetDefault[];
extern const UL1_MIPI_DATA_SUBBAND_TABLE_T*  UMTS_DAT_CAT_B_MIPI_DATA_TABLE_SetDefault[];
#endif
#endif

#endif /* End of #ifndef UL1D_RF_PUBLIC_H */

