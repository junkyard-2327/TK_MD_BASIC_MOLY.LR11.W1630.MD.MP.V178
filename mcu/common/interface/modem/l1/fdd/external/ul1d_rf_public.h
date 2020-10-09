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
 * ul1d_rf_public.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UL1D_RF_PUBLIC_H
#define UL1D_RF_PUBLIC_H


/*******************************************************************************
** Includes
*******************************************************************************/
#include "ul1d_rf_cid.h"
#include "hal_ul1_struct.h" //To use the band/freqToband common query functions
#include "ul1d_rf_cal_poc_data.h"
#include "mmrf_cc_global.h"

/*******************************************************************************
** Setting for specific RF
*******************************************************************************/
#define  RX_CAL_SETTLING_TIME    (125) /*including SRX setting time*/
#define  RX_BURST_SETTLING_TIME  (20)  /*including RX LDO setting time*/
#define  RX_SLEEP_ENTER_TIME     (20)  /*including RX LDO setting time*/
#define  RX_SR1_CW_SEND_TIME     (4)   /*14CWs. 0.26us/CW over 5 wire BSI at 60MHz CLK*/
#define  RX_SR2_CW_SEND_TIME     (2)   /*7CWs.  0.26us/CW over 5 wire BSI at 60MHz CLK*/

#if defined(L1_SIM)
#define  TX_CAL_SETTLING_TIME    (102+10+10) /*including STX setting time, add 10us for xL1sim 0.5us/CW Usim handling*/
#else
#define  TX_CAL_SETTLING_TIME    (102) /*including STX setting time*/
#endif
#define  TX_BURST_SETTLING_TIME  (20)  /*including TX LDO setting time*/
#define  TX_SLEEP_ENTER_TIME     (1)   /*including RX LDO setting time*/
#define  TX_ST1_CW_SEND_TIME     (6)   /*24CWs. 0.26us/CW over 5 wire BSI at 60MHz CLK*/
#define  TX_ST2_CW_SEND_TIME     (1)   /*4CWs.  0.26us/CW over 5 wire BSI at 60MHz CLK*/

#define  UBSI_SEARCH_TIME        (6)   /*3G BSI search time for 472 CW depth at 80MHz CLK*/
#define  UBSI_PENDDING_STR1      (2*(UBSI_SEARCH_TIME + RX_SR1_CW_SEND_TIME)) /*20us*/
#define  UBSI_PENDDING_STR2      (2*(UBSI_SEARCH_TIME + RX_SR2_CW_SEND_TIME) + (UBSI_SEARCH_TIME + TX_ST2_CW_SEND_TIME)) /*23us*/

#define  TC_SR1   MICROSECOND_TO_CHIP( RX_CAL_SETTLING_TIME + RX_BURST_SETTLING_TIME + UBSI_PENDDING_STR1 + UBSI_PENDDING_STR2 )
#define  TC_SR2   MICROSECOND_TO_CHIP( RX_BURST_SETTLING_TIME + UBSI_PENDDING_STR2 )
#define  TC_SR3   MICROSECOND_TO_CHIP( RX_SLEEP_ENTER_TIME )
#define  TC_ST1   MICROSECOND_TO_CHIP( TX_CAL_SETTLING_TIME + TX_BURST_SETTLING_TIME + 2*UBSI_SEARCH_TIME + TX_ST1_CW_SEND_TIME + TX_ST2_CW_SEND_TIME)
#define  TC_ST2   MICROSECOND_TO_CHIP( TX_BURST_SETTLING_TIME + UBSI_SEARCH_TIME + TX_ST2_CW_SEND_TIME)
#define  TC_ST3   MICROSECOND_TO_CHIP( TX_SLEEP_ENTER_TIME )
/*MT6169*/
#define  END_BOUNDARY_OFFSET         (4*256)
/*MT6169*/ /* BSI Event timing RXCAL & TXCAL, [Paul] only use it in ORION_FDD*/  
/*MT6169*/ #define  TC_SR1_CAL           MICROSECOND_TO_CHIP(610) // "RX cal timing"+"BSI send time length"+"reserved timing margin" =550us + 10us +10us + 40us (for RXDFE active wait + IQ settling time)
/*MT6169*/ #define  TC_SR2_CAL           MICROSECOND_TO_CHIP(10)  //"reserved BSI event send time(about for 10 events)" 
/*MT6169*/ #define  TC_ST_CAL            MICROSECOND_TO_CHIP(0)  //"reserved BSI event send time(about for 10 events)"
/*MT6169*/ 
/*MT6169*/ #if MT6169_TO_DO /*to do, check DC, RXD timing*/
/*MT6169*/ /* BSI Event timing for Dual cell & RXD reconfig */               
#define  TC_DC_SR1            (END_BOUNDARY_OFFSET) // Align FEC off time at symbol 1. MUST ahead to TC_DC_SR2.           
/*MT6169*/ #define  TC_DC_SR2            (TC_SR1) //DC RX SRX on timing(SR1).
/*MT6169*/ #define  TC_DC_SR2B           (TC_SR2) //DC RX on timing(SR2).             
/*MT6169*/               
/*MT6169*/ #define  TC_RXD_SR1           MICROSECOND_TO_CHIP(25)  //doesn't matter, no RXD reconfiguration event @ MT6583             
/*MT6169*/ #define  TC_RXD_SR3           MICROSECOND_TO_CHIP(20)  //doesn't matter, No RXD reconfiguration event @ MT6583    
           #endif

/*--------------------------------------------------------*/
/*   TRX IO Setting Define                                */
/*--------------------------------------------------------*/
#define UL1_RX_LNA_PORT_SELECT_SHIFT                 (5)
#define UL1_RX_LNA_PORT_P0                           (0x1 << (UL1_RX_LNA_PORT_SELECT_SHIFT + 0)) /*NonUsed*/
#define UL1_RX_LNA_PORT_P1                           (0x1 << (UL1_RX_LNA_PORT_SELECT_SHIFT + 1))
#define UL1_RX_LNA_PORT_P2                           (0x1 << (UL1_RX_LNA_PORT_SELECT_SHIFT + 2))
#define UL1_RX_LNA_PORT_P3                           (0x1 << (UL1_RX_LNA_PORT_SELECT_SHIFT + 3))
#define UL1_RX_LNA_PORT_P4                           (0x1 << (UL1_RX_LNA_PORT_SELECT_SHIFT + 4))
#define UL1_RX_LNA_GROUP_SELECT_SHIFT                (0)
#define UL1_RX_LNA_GROUP_G1                          (0x1 << (UL1_RX_LNA_GROUP_SELECT_SHIFT + 0))
#define UL1_RX_LNA_GROUP_G2                          (0x1 << (UL1_RX_LNA_GROUP_SELECT_SHIFT + 1))
#define UL1_RX_LNA_GROUP_G3                          (0x1 << (UL1_RX_LNA_GROUP_SELECT_SHIFT + 2))
#define UL1_RX_LNA_GROUP_G4                          (0x1 << (UL1_RX_LNA_GROUP_SELECT_SHIFT + 3))

/** Tx Port selection */
#define UL1_TX_BSEL_LB_SHIFT                         (0)
#define UL1_TX_BSEL_MB_SHIFT                         (5)
#define UL1_TX_BSEL_HB_SHIFT                         (10)

#define M_UNPACK_LNA_PORT_VALUE(x)                   ((x >> UL1_RX_LNA_PORT_SELECT_SHIFT) & 0x3F)
#define M_UNPACK_LNA_GROUP_VALUE(x)                  ((x >> UL1_RX_LNA_GROUP_SELECT_SHIFT) & 0xF)

#define NON_USED_BAND                                (0xFF)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/** RF RX/RXD port setting */
typedef enum
{
   LNA_PRX1  = (UL1_RX_LNA_GROUP_G4 | UL1_RX_LNA_PORT_P1),
   LNA_PRX2  = (UL1_RX_LNA_GROUP_G4 | UL1_RX_LNA_PORT_P2),
   LNA_PRX3  = (UL1_RX_LNA_GROUP_G4 | UL1_RX_LNA_PORT_P3),

   LNA_PRX4  = (UL1_RX_LNA_GROUP_G3 | UL1_RX_LNA_PORT_P1),
   LNA_PRX5  = (UL1_RX_LNA_GROUP_G3 | UL1_RX_LNA_PORT_P2),
   LNA_PRX6  = (UL1_RX_LNA_GROUP_G3 | UL1_RX_LNA_PORT_P3),
   LNA_PRX7  = (UL1_RX_LNA_GROUP_G3 | UL1_RX_LNA_PORT_P4),

   LNA_PRX8  = (UL1_RX_LNA_GROUP_G2 | UL1_RX_LNA_PORT_P1),
   LNA_PRX9  = (UL1_RX_LNA_GROUP_G2 | UL1_RX_LNA_PORT_P2),
   LNA_PRX10 = (UL1_RX_LNA_GROUP_G2 | UL1_RX_LNA_PORT_P3),
   LNA_PRX11 = (UL1_RX_LNA_GROUP_G2 | UL1_RX_LNA_PORT_P4),

   LNA_PRX12 = (UL1_RX_LNA_GROUP_G1 | UL1_RX_LNA_PORT_P1),
   LNA_PRX13 = (UL1_RX_LNA_GROUP_G1 | UL1_RX_LNA_PORT_P2),
   LNA_PRX14 = (UL1_RX_LNA_GROUP_G1 | UL1_RX_LNA_PORT_P3),

   LNA_MAIN_NONUSED = NON_USED_BAND,
}UL1_RF_RX_IO_E;

typedef enum
{
   LNA_DRX1  = LNA_PRX1 ,
   LNA_DRX2  = LNA_PRX2 ,
   LNA_DRX3  = LNA_PRX3 ,

   LNA_DRX4  = LNA_PRX4 ,
   LNA_DRX5  = LNA_PRX5,
   LNA_DRX6  = LNA_PRX6 ,
   LNA_DRX7  = LNA_PRX7 ,

   LNA_DRX8  = LNA_PRX8 ,
   LNA_DRX9  = LNA_PRX9 ,
   LNA_DRX10 = LNA_PRX10,
   LNA_DRX11 = LNA_PRX11,

   LNA_DRX12 = LNA_PRX12,
   LNA_DRX13 = LNA_PRX13,
   LNA_DRX14 = LNA_PRX14,

   LNA_RXD_NONUSED = NON_USED_BAND,
}UL1_RF_RXD_IO_E;

/** Tx Port selection */
typedef enum
{
   TX_HB1 = (0x1 << (UL1_TX_BSEL_HB_SHIFT + 0)),
   TX_HB2 = (0x1 << (UL1_TX_BSEL_HB_SHIFT + 1)),

   TX_MB1 = (0x1 << (UL1_TX_BSEL_MB_SHIFT + 0)),
   TX_MB2 = (0x1 << (UL1_TX_BSEL_MB_SHIFT + 1)),
   TX_MB3 = (0x1 << (UL1_TX_BSEL_MB_SHIFT + 2)),
   TX_MB4 = (0x1 << (UL1_TX_BSEL_MB_SHIFT + 3)),

   TX_LB1 = (0x1 << (UL1_TX_BSEL_LB_SHIFT + 0)),
   TX_LB2 = (0x1 << (UL1_TX_BSEL_LB_SHIFT + 1)),
   TX_LB3 = (0x1 << (UL1_TX_BSEL_LB_SHIFT + 2)),
   TX_LB4 = (0x1 << (UL1_TX_BSEL_LB_SHIFT + 3)),

   TX_IO_NONUSED = NON_USED_BAND,
}UL1_RF_TX_IO_E;

/** Tx DET Port selection */
typedef enum
{
   TX_DET_IO_PORT1 = 0,
   TX_DET_IO_PORT2 = 1,
   TX_DET_IO_NON_USED_PORT = 0xFFFF,
}UL1_RF_TX_DET_IO_E;
           
/*MT6169*/ /*For RX LNA path mapping*/ 
/*MT6169*/ #define LNA_HB_1 (0)
/*MT6169*/ #define LNA_HB_2 (1)
/*MT6169*/ #define LNA_HB_3 (2)
/*MT6169*/ #define LNA_MB_1 (3)
/*MT6169*/ #define LNA_MB_2 (4)
/*MT6169*/ #define LNA_LB_1 (5)
/*MT6169*/ #define LNA_LB_2 (6)
/*MT6169*/ #define LNA_LB_3 (7)
/*MT6169*/ /*Start from MT6169, use 0xFF(max) to make all projects in the future aligned with the same value, for customer's comprehension*/
/*MT6169*/                                      
/*MT6169*/ /*For RXD LNA path mapping*/                 
/*MT6169*/ #define LNA_RXD_HB_1 (0)
/*MT6169*/ #define LNA_RXD_HB_2 (1)
/*MT6169*/ #define LNA_RXD_HB_3 (2)
/*MT6169*/ #define LNA_RXD_MB_1 (3)
/*MT6169*/ #define LNA_RXD_MB_2 (4)
/*MT6169*/ #define LNA_RXD_LB_1 (5)
/*MT6169*/ #define LNA_RXD_LB_2 (6)
/*MT6169*/ #define LNA_RXD_LB_3 (7)
/*MT6169*/ #define LNA_RXD_NON_USED_BAND (NON_USED_BAND)
/*MT6169*/
 /*CW68: IOTX Table 11-5*/
#define TX_HB_1 (0)
#define TX_HB_2 (1)
#define TX_MB_1 (2)
#define TX_MB_2 (3)
#define TX_MB_3 (4)
#define TX_MB_4 (5)
#define TX_LB_1 (6)
#define TX_LB_2 (7)
#define TX_LB_3 (8)
#define TX_LB_4 (9)

/*MT6169*/ 
/*MT6169*/ /* Path mapping for Transmitter sections */
/*MT6169*/ #define TX_HIGH_BAND2                TX_HB_2
/*MT6169*/ #define TX_HIGH_BAND3                TX_MB_1
/*MT6169*/ #define TX_LOW_BAND1                 TX_LB_1
/*MT6169*/ #define TX_NULL_BAND                 NON_USED_BAND
/*MT6169*/
/*MT6169*/ /* PA mode Setting */ /*MT6166 PORTING NOT READY*///(start) 
/*MT6169*/ #define  NUMBER_OF_VGA_DAC           10
/*MT6169*/ #define  VM_H                        0
/*MT6169*/ #define  VM_M                        1
/*MT6169*/ #define  VM_L                        3
/*MT6169*/ #define  DC2DC_H                     1
/*MT6169*/ #define  DC2DC_M                     1
/*MT6169*/ #define  DC2DC_L                     0
/*MT6169*/ #define  NUMBER_OF_CALI_DATA_ELEMENT 4
/*MT6169*/  /*MT6167 PORTING NOT READY*///(End) 
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ /* Crystal solution parameter definition                  */
/*MT6169*/ /*--------------------------------------------------------*/
/*MT6169*/ #define  CRYSTAL_CAPID_MAX           255
/*MT6169*/
////////////////////////////////////////////////////////////////////////////////

/*===============================================================================================*/


/*******************************************************************************
** New BPI data type 
*******************************************************************************/
typedef kal_uint32     BPI_data_type; 

/*******************************************************************************
** META Factory Calibration and 3G RF tool usage
*******************************************************************************/
#if !defined(IS_R6_DCXO_SUPPORT)
#define IS_R6_DCXO_SUPPORT          0
#endif


/*******************************************************************************
** Constants
*******************************************************************************/
#define  CAL_TEMP_SECTION            8
#define  CAL_UARFCN_SECTION         15
#define  CAL_PWR_DETECTOR_SECTION   32

#define  UL1D_RF_CUSTOM_BAND (1+5)

#if !defined(NUMBER_OF_VGA_DAC)
#define  NUMBER_OF_VGA_DAC          96
#endif

#define UMTS_RF_CA_BAND_ROUTE_LUT_IDX_MAX   5
#define UMTS_RF_CA_BAND_ROUTE_LUT_IDX_NONE  0xFF
#define UMTS_RF_CA_OPT_FE_SET_LUT_IDX_MAX   5

#define MAX_SUPPORTED_BAND_INDEX (5)

#define  MAX_NUMBER_OF_RX_SUBBLOCK              (2) // for 3C-HSDPA case
#define  MAX_NUMBER_CARRIER_OF_A_RX_SUBBLOCK    (3) // for 3C-HSDPA case
#define  MAX_NUMBER_OF_TX_SUBBLOCK              (1) // for DC-HSUPA case
#define  MAX_NUMBER_CARRIER_OF_A_TX_SUBBLOCK    (2) // for DC-HSUPA case
   
#define  MAX_NUMBER_OF_RX_SYNTH                 (MAX_NUMBER_OF_RX_SUBBLOCK) //for DB-HSDPA case
#define  MAX_NUMBER_OF_TX_SYNTH                 (MAX_NUMBER_OF_TX_SUBBLOCK) //for DB-HSDPA case

#define UMTS_CA_1ST_SHIFT      (8)
#define UMTS_CA_BAND_MASK      (0xFF)
#define UMTS_CA_2ND_SHIFT      (0)

#define UMTS_RF_CA_FE_NUM_MAX        5
#define UMTS_RF_CA_BAND_NUM_MAX      (UMTS_RF_CA_FE_NUM_MAX * 2) /* 10 */
#define UMTS_RF_FRONT_END_NUM_MAX    (MAX_SUPPORTED_BAND_INDEX + UMTS_RF_CA_FE_NUM_MAX) /* 10 */

#define UMTS_USAGE_TBL_SIZE_MAX      (MAX_SUPPORTED_BAND_INDEX + UMTS_RF_CA_BAND_NUM_MAX) /* 15 */
#define UMTS_ROUTE_TBL_SIZE_MAX      (MAX_SUPPORTED_BAND_INDEX + 2*UMTS_RF_CA_BAND_NUM_MAX) /* 25 */

#define UMTS_RF_DC_TBL_SIZE          (UMTS_ROUTE_TBL_SIZE_MAX + 1)
#define UMTS_AGC_PATHLOSS_TBL_SIZE   (UMTS_ROUTE_TBL_SIZE_MAX + 1)
#define UMTS_MIPI_RX_TBL_SIZE        (UMTS_USAGE_TBL_SIZE_MAX + 1)

#define UMTS_FE_RXBASE_TBL_SIZE_MAX  (UMTS_USAGE_TBL_SIZE_MAX) 
#define UMTS_FE_TXBASE_TBL_SIZE_MAX  (UMTS_RF_FRONT_END_NUM_MAX)

#define TBL_IDX_MIPI_DEFAULT   0xFFFF

#define TBL_IDX_FOR_RX_BAND_INDICATOR_0   0
#define TBL_IDX_FOR_RX_BAND_INDICATOR_1   1
#define TBL_IDX_FOR_RX_BAND_INDICATOR_2   2
#define TBL_IDX_FOR_RX_BAND_INDICATOR_3   3
#define TBL_IDX_FOR_RX_BAND_INDICATOR_4   4

/*******************************************************************************
 * CA related
 ******************************************************************************/
#define UMTS_RF_CA_MAX_CC_NUM        3
#define UMTS_RF_CA_VCO_DIV_SET_NUM   3 // [0]: RxPCC; [1]: RxSCC [2]: TxPCC
#define UMTS_RF_CA_VCO_SET_RXPCC     0 
#define UMTS_RF_CA_VCO_SET_RXSCC     1 
#define UMTS_RF_CA_VCO_SET_TXPCC     2 

#define UMTS_RF_RX_VCO_DIV_SET_NUM   3
#define UMTS_RF_RX_VCO_DIV_SET_1ST   0
#define UMTS_RF_RX_VCO_DIV_SET_2ND   1
#define UMTS_RF_RX_VCO_DIV_SET_3RD   2

#define UMTS_RF_TX_VCO_DIV_SET_NUM   2
#define UMTS_RF_TX_VCO_DIV_SET_1ST   0
#define UMTS_RF_TX_VCO_DIV_SET_2ND   1

#define UMTS_RF_BAND_NUM_MAX         UMTSBandcount

#if IS_3G_DAT_UL1_CUSTOM_SUPPORT
/*******************************************************************************
 * TAS definition
 ******************************************************************************/
#define UMTS_DAT_SCENARIO_DEFAULT         (-1)
#define UMTS_DAT_MAX_STATE_NUM            8
#define UMTS_DAT_MAX_CAT_A_ROUTE_NUM      10
#define UMTS_DAT_MAX_CAT_B_ROUTE_NUM      40
#define UMTS_DAT_MAX_FE_ROUTE_NUM         MAX_SUPPORTED_BAND_INDEX
#define UMTS_DAT_MIPI_TABLE_NULL          (0xFF)
#define UMTS_DAT_FE_NULL                  (0xFF)

#define UMTS_DAT_FEATURE_ENABLE(s)                  UMTS_DAT_FEATURE_ENABLE_##s

#define UMTS_MIPI_DAT_EVENT(rt,s)                   UMTS_##rt##_MIPI_EVENT_##s
#define UMTS_MIPI_DAT_DATA(rt,s)                    UMTS_##rt##_MIPI_DATA_##s

#define M_UMTS_SB_FE_DAT_SETTING(b,s)                                                                                                     \
{                                                                                                                                         \
   b/*usage*/,                                                                                                                            \
   { /*split part1*/                                                                                                                         \
      { /*tas route state 0*/ b##_##DAT_STATE0_CAT_A_CONFIG##_##s, b##_##DAT_STATE0_CAT_B_CONFIG##_##s},  \
      { /*tas route state 1*/ b##_##DAT_STATE1_CAT_A_CONFIG##_##s, b##_##DAT_STATE1_CAT_B_CONFIG##_##s},  \
      { /*tas route state 2*/ b##_##DAT_STATE2_CAT_A_CONFIG##_##s, b##_##DAT_STATE2_CAT_B_CONFIG##_##s},  \
      { /*tas route state 3*/ b##_##DAT_STATE3_CAT_A_CONFIG##_##s, b##_##DAT_STATE3_CAT_B_CONFIG##_##s},  \
      { /*tas route state 4*/ b##_##DAT_STATE4_CAT_A_CONFIG##_##s, b##_##DAT_STATE4_CAT_B_CONFIG##_##s},  \
      { /*tas route state 5*/ b##_##DAT_STATE5_CAT_A_CONFIG##_##s, b##_##DAT_STATE5_CAT_B_CONFIG##_##s},  \
      { /*tas route state 6*/ b##_##DAT_STATE6_CAT_A_CONFIG##_##s, b##_##DAT_STATE6_CAT_B_CONFIG##_##s},  \
      { /*tas route state 7*/ b##_##DAT_STATE7_CAT_A_CONFIG##_##s, b##_##DAT_STATE7_CAT_B_CONFIG##_##s},  \
   },                                                                                                                                      \
}

#define UMTS_SB_DAT_CONFIGURE(band_ind,s)               M_UMTS_SB_FE_DAT_SETTING(band_ind,s)
#endif
/*******************************************************************************
** Macro define
*******************************************************************************/
#define M_UMTS_AGC_PATHLOSS(x, sET)       &AGC_PATHLOSS_##x##_##sET
#define M_UMTS_RX_AGC_PATHLOSS(x, sET)    M_UMTS_AGC_PATHLOSS(x, sET)

#define M_UMTS_AGC_PATHLOSS_RXD(x,sET)        &AGC_PATHLOSS_RXD_##x##_##sET
#define M_UMTS_RX_AGC_PATHLOSS_RXD(x,sET)     M_UMTS_AGC_PATHLOSS_RXD(x,sET)

#define M_UMTS_RAMPDATA(x,sET)                &RampData_##x##_##sET
#define M_UMTS_TX_RAMPDATA(x,sET)             M_UMTS_RAMPDATA(x,sET)

#define M_UMTS_PA_OCTLEV_DATA(x,sET)          &PaOctLevData_##x##_##sET
#define M_UMTS_TX_PA_OCTLEV_DATA(x,sET)       M_UMTS_PA_OCTLEV_DATA(x,sET)

#define M_UMTS_PA_DRIFT_COMP_DATA(x,sET)      &PaDriftCompData_##x##_##sET
#define M_UMTS_TX_PA_DRIFT_COMP_DATA(x,sET)   M_UMTS_PA_DRIFT_COMP_DATA(x,sET)

#define M_UMTS_RACH_TEMP_COMP_DATA(x,sET)     &RACH_temperature_compensation_##x##_##sET
#define M_UMTS_TX_RACH_TEMP_COMP_DATA(x,sET)  M_UMTS_RACH_TEMP_COMP_DATA(x,sET)

#define UMTS_SB_DEFAULT      (0xFFFF)

#define M_UMTS_CA_BAND(x, y) ((x << UMTS_CA_1ST_SHIFT) | (y << UMTS_CA_2ND_SHIFT))

/*===============================================================================*/

#define M_UMTS_Band_PDATA_PR1(b)                    PDATA_##b##_PR1_##SetDefault
#define M_UMTS_PDATA_PR1(b)                         M_UMTS_Band_PDATA_PR1(b)

#define M_UMTS_Band_PDATA_PR2(b)                    PDATA_##b##_PR2_##SetDefault
#define M_UMTS_PDATA_PR2(b)                         M_UMTS_Band_PDATA_PR2(b)

#define M_UMTS_Band_PDATA_PR3(b)                    PDATA_##b##_PR3_##SetDefault
#define M_UMTS_PDATA_PR3(b)                         M_UMTS_Band_PDATA_PR3(b)

#define M_UMTS_Band_PDATA_PT1(b)                    PDATA_##b##_PT1_##SetDefault
#define M_UMTS_PDATA_PT1(b)                         M_UMTS_Band_PDATA_PT1(b)

#define M_UMTS_Band_PDATA_PT2(b)                    PDATA_##b##_PT2_##SetDefault
#define M_UMTS_PDATA_PT2(b)                         M_UMTS_Band_PDATA_PT2(b)

#define M_UMTS_Band_PDATA_PT3(b)                    PDATA_##b##_PT3_##SetDefault
#define M_UMTS_PDATA_PT3(b)                         M_UMTS_Band_PDATA_PT3(b)

#define M_UMTS_Band_RX_IO(b)                        b##_CHANNEL_SEL_##SetDefault
#define M_UMTS_RX_IO(b)                             M_UMTS_Band_RX_IO(b)

#define M_UMTS_Band_RXD_IO(b)                       b##_CHANNEL2_SEL_##SetDefault
#define M_UMTS_RXD_IO(b)                            M_UMTS_Band_RXD_IO(b)

#define M_UMTS_Band_TX_IO(b)                        b##_OUTPUT_SEL_##SetDefault
#define M_UMTS_TX_IO(b)                             M_UMTS_Band_TX_IO(b)

#define M_UMTS_Band_TX_DET_IO(b)                    b##_OUTPUT_DET_SEL_##SetDefault
#define M_UMTS_TX_DET_IO(b)                         M_UMTS_Band_TX_DET_IO(b)
/*===============================================================================*/

#define M_UMTS_RF_RX_PDATABASE(b)                              \
{  b,                                                        \
   {M_UMTS_PDATA_PR1(b), M_UMTS_PDATA_PR2(b), M_UMTS_PDATA_PR2(b), M_UMTS_PDATA_PR3(b), M_UMTS_PDATA_PR3(b)\
   }                                                         \
}

#define M_UMTS_RF_TX_PDATABASE(b)                              \
{  b,                                                        \
   {M_UMTS_PDATA_PT1(b), M_UMTS_PDATA_PT2(b), M_UMTS_PDATA_PT2(b), M_UMTS_PDATA_PT3(b), M_UMTS_PDATA_PT3(b)\
   }                                                         \
}

#define M_UMTS_RF_RXIOBASE(b)                                  \
{ b, {(M_UMTS_RX_IO(b)), (M_UMTS_RXD_IO(b))}                      \
}

#define M_UMTS_RF_TXIOBASE(b)                                  \
{ b, {(M_UMTS_TX_IO(b)), (M_UMTS_TX_DET_IO(b))}                   \
}

/*===============================================================================*/
#define UMTS_SB_FE_ROUTE_SETTING(x, y, z)                                           \
{  x, 1,                                                                         \
   {  { x,                                                                       \
         {                                                                       \
/*RX IO  */ {  x##_CHANNEL_SEL_##z, x##_CHANNEL2_SEL_##z  },                              \
/*RX BPI */ {  PDATA_##x##_PR1_##z, PDATA_##x##_PR2_##z, PDATA_##x##_PR2_##z, PDATA_##x##_PR3_##z, PDATA_##x##_PR3_##z }, \
/*RX MIPI*/    y                                                                  \
         },                                                                       \
         {                                                                        \
/*TX IO  */ {  x##_OUTPUT_SEL_##z, x##_OUTPUT_DET_SEL_##z  },                                                  \
/*TX BPI */ {  PDATA_##x##_PT1_##z, PDATA_##x##_PT2_##z, PDATA_##x##_PT2_##z, PDATA_##x##_PT3_##z, PDATA_##x##_PT3_##z }, \
/*TX MIPI*/    y                                                                  \
         },                                                                       \
      },                                                                          \
      { UMTSBandNone, { {0,0}, {0,0,0}, 0 },                                      \
                      { {0  }, {0,0,0}, 0 }                                       \
      }                                                                           \
   }                                                                              \
}

#define UMTS_SB_FE_PRE_SETTING(x, y, z)                                              \
        UMTS_SB_FE_ROUTE_SETTING(x, y, z)
#define UMTS_SB_FE_SETTING(band_ind, sET)                                              \
        UMTS_SB_FE_PRE_SETTING(band_ind##_##sET, TBL_IDX_FOR_##band_ind, sET )

#define UMTS_CA_FE_ROUTE_SETTING(x, z)                                               \
{                                                                                 \
   x, x##_CCNUM_##z,                                                                  \
   {  {  x##_CC0_##z,                                                                 \
         {                                                                        \
/*RX IO  */ {  x##_CC0_CHANNEL_SEL_##z, x##_CC0_CHANNEL2_SEL_##z  },                       \
/*RX BPI */ {  x##_CC0_PDATA_PR1_##z, x##_CC0_PDATA_PR2_##z, x##_CC0_PDATA_PR2_##z, x##_CC0_PDATA_PR3_##z, x##_CC0_PDATA_PR3_##z }, \
/*RX MIPI*/   x##_CC0_RX_MIPI_TBL_IDX_##z                                            \
         },                                                                       \
         {                                                                        \
/*TX IO  */ {  x##_CC0_OUTPUT_SEL_##z, x##_CC0_OUTPUT_DET_SEL_##z  },                                              \
/*TX BPI */ {  x##_CC0_PDATA_PT1_##z, x##_CC0_PDATA_PT2_##z, x##_CC0_PDATA_PT2_##z, x##_CC0_PDATA_PT3_##z, x##_CC0_PDATA_PT3_##z }, \
/*TX MIPI*/   x##_CC0_TX_MIPI_TBL_IDX_##z                                            \
         }                                                                        \
      },                                                                          \
      {  x##_CC1_##z,                                                                 \
         {                                                                        \
/*RX IO  */ {  x##_CC1_CHANNEL_SEL_##z, x##_CC1_CHANNEL2_SEL_##z  },                       \
/*RX BPI */ {  x##_CC1_PDATA_PR1_##z, x##_CC1_PDATA_PR2_##z, x##_CC1_PDATA_PR2_##z, x##_CC1_PDATA_PR3_##z, x##_CC1_PDATA_PR3_##z }, \
/*RX MIPI*/   x##_CC1_RX_MIPI_TBL_IDX_##z                                             \
         },                                                                       \
         {                                                                        \
/*TX IO  */ {  x##_CC1_OUTPUT_SEL_##z, x##_CC1_OUTPUT_DET_SEL_##z  },                                              \
/*TX BPI */ {  x##_CC1_PDATA_PT1_##z,  x##_CC1_PDATA_PT2_##z, x##_CC1_PDATA_PT2_##z, x##_CC1_PDATA_PT3_##z, x##_CC1_PDATA_PT3_##z}, \
/*TX MIPI*/   x##_CC1_TX_MIPI_TBL_IDX_##z                                            \
         }                                                                        \
      }                                                                           \
   }                                                                              \
}

#define UMTS_CA_FE_PRE_SETTING(x, z)                                              \
        UMTS_CA_FE_ROUTE_SETTING(x, z)
#define UMTS_CA_FE_SETTING(ca_band_ind, sET)                                              \
        UMTS_CA_FE_PRE_SETTING(ca_band_ind##_##sET, sET )

#define UMTS_CA_COMPARE_RX_FE_SETTING( src, dst )                                  \
   src->rx_cfg.rxIodata.rxio     == dst->rx_cfg.rxIodata.rxio     &&              \
   src->rx_cfg.rxIodata.rxdio    == dst->rx_cfg.rxIodata.rxdio    &&              \
   src->rx_cfg.rxPdata.pr1       == dst->rx_cfg.rxPdata.pr1       &&              \
   src->rx_cfg.rxPdata.pr2       == dst->rx_cfg.rxPdata.pr2       &&              \
   src->rx_cfg.rxPdata.pr2b      == dst->rx_cfg.rxPdata.pr2b      &&              \
   src->rx_cfg.rxPdata.pr3       == dst->rx_cfg.rxPdata.pr3       &&              \
   src->rx_cfg.rxPdata.pr3a      == dst->rx_cfg.rxPdata.pr3a      &&              \
   src->rx_cfg.rxMipiTblIdx      == dst->rx_cfg.rxMipiTblIdx

#define UMTS_CA_COMPARE_TX_FE_SETTING( src, dst )                                  \
   src->tx_cfg.txIodata.txio    == dst->tx_cfg.txIodata.txio    &&                \
   src->tx_cfg.txPdata.pt1      == dst->tx_cfg.txPdata.pt1      &&                \
   src->tx_cfg.txPdata.pt2      == dst->tx_cfg.txPdata.pt2      &&                \
   src->tx_cfg.txPdata.pt2b     == dst->tx_cfg.txPdata.pt2b     &&                \
   src->tx_cfg.txPdata.pt3      == dst->tx_cfg.txPdata.pt3      &&                \
   src->tx_cfg.txPdata.pt3a     == dst->tx_cfg.txPdata.pt3a     &&                \
   src->tx_cfg.txMipiTblIdx     == dst->tx_cfg.txMipiTblIdx

#if (IS_3G_TAS_SUPPORT)
#define M_UMTS_TAS_BPI(value, mask, bpiData) (((value)&(mask))|(bpiData))

#define UL1D_TAS_BPI_PIN_GEN(var1, var2, var3, sET)   ( ((UMTS_TAS_BPI_PIN_1_##sET==UMTS_TAS_BPI_PIN_NULL_##sET)?0:((var1)<< UMTS_TAS_BPI_PIN_1_##sET))|\
                                                   ((UMTS_TAS_BPI_PIN_2_##sET==UMTS_TAS_BPI_PIN_NULL_##sET)?0:((var2)<< UMTS_TAS_BPI_PIN_2_##sET))|\
                                                   ((UMTS_TAS_BPI_PIN_3_##sET==UMTS_TAS_BPI_PIN_NULL_##sET)?0:((var3)<< UMTS_TAS_BPI_PIN_3_##sET)) )

#endif/*IS_3G_TAS_SUPPORT*/

// Power on CAL
#define UMTS_Band_PWRON_CAL_DATA(b)        b##_PWRON_CAL_DATA
#define UMTS_PWRON_CAL_DATA(b)             UMTS_Band_PWRON_CAL_DATA(b)

#if (IS_3G_TX_POWER_OFFSET_SUPPORT || IS_3G_SAR_TX_POWER_BACKOFF_SUPPORT)
#define TPO_3G_TABLE_NUM  TPO_MML1_TABLE_NUM 
#define UMTS_Band_TX_PWR_OFFSET(b, sET)     &TxPowerOffsetData_##b##_##sET
#define M_UMTS_TX_PWR_OFFSET(b, sET)        UMTS_Band_TX_PWR_OFFSET(b, sET)          
#endif

/*******************************************************************************
** Typedefs
*******************************************************************************/
typedef enum
{
   UMTSBandNone = 0,
   UMTSBand1    = 1,
   UMTSBand2    = 2,
   UMTSBand3    = 3,
   UMTSBand4    = 4,
   UMTSBand5    = 5,
   UMTSBand6    = 6,
   UMTSBand7    = 7,
   UMTSBand8    = 8,
   UMTSBand9    = 9,
   UMTSBand10   = 10,
   UMTSBand11   = 11,
   UMTSBand12   = 12,
   UMTSBand13   = 13,
   UMTSBand14   = 14,
   UMTSBand15   = 15,
   UMTSBand16   = 16,
   UMTSBand17   = 17,
   UMTSBand18   = 18,
   UMTSBand19   = 19,
   UMTSBand20   = 20,
   UMTSBand21   = 21,
   UMTSBand22   = 22,
   UMTSBandcount
}  UMTSBand;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct {
   kal_uint32      capability;
   kal_uint32      band_support;
   kal_uint32      rxd_band_support;
   kal_uint32      padrift_band_support;
} UMTS_MsCapabilityEx;

typedef  struct
{
   kal_uint16 max_uarfcn;
   kal_int8   path_loss_H;
   kal_int8   path_loss_M;
   kal_int8   path_loss_L;
   kal_int8   path_loss_LPM_offset;
}  U_sAGCGAINOFFSET;

typedef  struct
{
   kal_int8          temper_offset[CAL_TEMP_SECTION];
   U_sAGCGAINOFFSET  gain_of_uarfcn[CAL_UARFCN_SECTION];
}  U_sTEMPAGCOFFSET;

typedef  struct
{
   kal_uint16 level_0;
   kal_uint16 level_1;
} U_sDC2DC;

typedef  struct
{
   kal_uint16 start;
   kal_uint16 end;
} U_sHYSTERESISDATA;

typedef  struct
{
   kal_uint16 max_uarfcn;
   kal_int16  pwr_offset_dB; /* unit: 1/32 dB, range: -8 ~ +7 dB */ 
   kal_int16  pwr_offset_txdac;
}  U_sARFCN_SECTION;

#if IS_3G_FDD_RX_PATH_SELECTION_SUPPORT
typedef enum
{
   ANT_RX_MAIN_ONLY   = 0,
   ANT_RX_RXD_ONLY    = 1,
   ANT_RX_BOTH        = 2,
   ANT_RESUME_DEFAULT = 3
}ANT_SEL_TYPE;

typedef struct
{
   kal_bool       rx_path_selection_enable;
   ANT_SEL_TYPE   rx_path_type;
} U_sRxPathSelection;
#endif

typedef  struct
{
   kal_uint8  pwr_dt_thr;
   kal_uint8  pwr_dt_section;
   kal_uint16 pwr_dt_dac[ CAL_PWR_DETECTOR_SECTION ];
   kal_int16  pwr_dt_value[ CAL_PWR_DETECTOR_SECTION ]; //bit0~4 is used for fractions
   U_sARFCN_SECTION  pwr_dt_comp_by_subband[ CAL_UARFCN_SECTION ];
   kal_int16  pwr_dt_comp_by_temperature[8][2];  //[0]:slope, [1]:offset
}  U_sPWTDTDATA;

typedef  struct
{
   kal_uint16 dc2dc_level;
   kal_uint16 vbias_dac;
   kal_uint8  vm1;
   kal_uint8  vm2;
}  U_sPADATA;

typedef  struct
{
   U_sPADATA   pa_data; 
   kal_uint16  vga_dac[NUMBER_OF_VGA_DAC];
   U_sARFCN_SECTION  vga_comp_by_subband[ CAL_UARFCN_SECTION ];
   kal_int16  vga_comp_by_temperature[8][2];  //[0]:slope, [1]:offset
} U_sTXPOWERDATA;

typedef struct 
{
   kal_int16  vga_comp_by_temperature[8][2];  //[0]:slope, [1]:offset
} U_sRACHCOMP;


typedef struct 
{
   U_sRACHCOMP  power_dac[3];
} U_sPARACHTMCOMPDATA;


typedef struct 
{
   kal_uint16 initDac;
   kal_int32 slope;
} U_sAFCDACDATA;

typedef struct 
{
   kal_int32 cap_id; 
} U_sAFCCAPDATA;


typedef  struct
{
   U_sDC2DC pa_dc2dc;
   U_sTXPOWERDATA  power_dac[3];  //0:PA high mode, 1:PA mid mode, 2:PA low mode (use 0&1 if only 2 mode)
   U_sHYSTERESISDATA tx_hysteresis[2];
   U_sPWTDTDATA    pwr_dt_data;
} U_sRAMPDATA;

typedef  struct
{
   kal_uint8  pa_mode;   //  2 bits
   kal_int8   prf;       //  8 bits
   kal_uint8  dc2dc_lvl; //  5 bits // MT6589, MT6582: 6 bits
   kal_uint8  vm1;       //  1 bit
   kal_uint8  vm2;       //  1 bit
   kal_uint16 vbias_dac; // 10 bits
   kal_uint16 pa_gain;   //  9 bits
} U_sPMULEVHANDLE;

typedef  struct
{
   /* octlev_num_section accounts for recording the number of sections that defined by user
    * To keep the design simple, we only allow user to use consecutive regions
    *
    * The two control parameters pa_phase_compensation[] and pmu_level_handle[] belong to BB TX HW
    * funtionality and all relates to PA, though PA phase compensation only has three modes
    * PD coupler loss by PA modes stored in power_dac[]->vga_dac[9]
    */
   kal_uint8         octlev_num_section;
   kal_uint8         reserved_byte; // Use ARM compiler padding byte to store power backoff value configured by META user in Factory Mode calibration
   kal_uint32        pa_phase_compensation[3]; // 0: PA high mode, 1: PA mid mode
   U_sPMULEVHANDLE   pmu_level_handle[8];
} U_sPAOCTLVLSETTING;

// Start for ADAPT IOT AMR workaround
typedef struct
{
   kal_bool ADAPT_Customized;
   kal_bool reserved1;
   kal_bool reserved2;
   kal_bool reserved3;
} U_sUl1IotCustomSupportStruct;
// End for ADAPT IOT AMR workaround

#if IS_HSPA_HWTPC
   #ifdef __HSDPA_SUPPORT__
typedef struct 
{
   kal_uint8  pseudo_hscch[5];
   kal_uint8  pseudo_hdsch[5];
   kal_uint16 beta_hs_p[15];
   kal_uint16 beta_hs_q[15];
} META_HWTPC_HSDPA_FRAME_INFO;
   #endif

   #ifdef __HSUPA_SUPPORT__
typedef struct 
{
   kal_uint8  edch_enable[5];
   kal_uint8  is_new_tx[5];
   kal_uint8  etfci[5];
   kal_uint8  beta_ed_num[5];
   kal_uint16 beta_ed0_sf[5];
   kal_uint16 beta_ed1_sf[5];
   kal_uint16 beta_ed2_sf[5];
   kal_uint16 beta_ed3_sf[5];
   kal_uint16 beta_ec[5];
   kal_uint16 beta_ed_x_beta_c_0[5];
   kal_uint16 beta_ed_x_beta_c_1[5];
   kal_uint16 beta_ed_x_beta_c_2[5];
   kal_uint16 beta_ed_x_beta_c_3[5];
   kal_uint8  delta_harq[5];
} META_HWTPC_HSUPA_FRAME_INFO;
   #endif
#endif // #if IS_HSPA_HWTPC

typedef struct 
{
   /*input*/
   kal_uint8 tpc_step;
   kal_uint8 itp;
   kal_uint8 rpp;
   kal_uint8 fmt_idx;
   kal_uint8 dl_frame_type;
   kal_uint16 slot_mask;
   kal_int8   tpc_cmd[15];
   kal_uint8  beta_c;
   kal_uint8  beta_d;
#if IS_HSPA_HWTPC
   // Above is R99 original used
   kal_uint32 normcon;
   kal_int16  net_maxpow;
   kal_int16  net_minpow;
   
   #ifdef __HSDPA_SUPPORT__
   META_HWTPC_HSDPA_FRAME_INFO hsdpa;
   #endif
   #ifdef __HSUPA_SUPPORT__
   META_HWTPC_HSUPA_FRAME_INFO hsupa;
   #endif
#endif // #if IS_HSPA_HWTPC
}  META_HWTPC_FRAME_INFO;

typedef  struct
{ 
   kal_int16 pa_drift_comp_w_table[6][2];
   kal_int16 pa_drift_comp_h_table[6][4];
} U_sPADRIFTSETTING;

typedef enum
{
   MPRSetting0 = 0,
   MPRSetting1 = 1,
   MPRSetting2 = 2,
   MPRSetting3 = 3,
   MPRSetting4 = 4,
   MPRSettingCount
}  MPR_Setting;

typedef enum
{
   UL1D_DATABASE_RXIO     = 0,
   UL1D_DATABASE_TXIO     = 1,
   UL1D_DATABASE_RX_PDATA = 2,
   UL1D_DATABASE_TX_PDATA = 3,
   UL1D_DATABASE_CONUT,
   UL1D_DATABASE_INVALID = 0xFFFE,
} UL1D_DATABASE_TYPE_E;

/* CA Band definition */
typedef enum
{
   UMTS_CA_BANDNONE =  M_UMTS_CA_BAND(UMTSBandNone, UMTSBandNone),
   UMTS_CA_B1_B5    =  M_UMTS_CA_BAND(UMTSBand1, UMTSBand5),
   UMTS_CA_B1_B8    =  M_UMTS_CA_BAND(UMTSBand1, UMTSBand8),
   UMTS_CA_B1_B11   =  M_UMTS_CA_BAND(UMTSBand1, UMTSBand11),
   UMTS_CA_B2_B4    =  M_UMTS_CA_BAND(UMTSBand2, UMTSBand4),
   UMTS_CA_B2_B5    =  M_UMTS_CA_BAND(UMTSBand2, UMTSBand5),
   /* Switch PCC and SCC*/
   UMTS_CA_B5_B1    =  M_UMTS_CA_BAND(UMTSBand5, UMTSBand1),
   UMTS_CA_B8_B1    =  M_UMTS_CA_BAND(UMTSBand8, UMTSBand1),
   UMTS_CA_B11_B1   =  M_UMTS_CA_BAND(UMTSBand11, UMTSBand1),
   UMTS_CA_B4_B2    =  M_UMTS_CA_BAND(UMTSBand4, UMTSBand2),
   UMTS_CA_B5_B2    =  M_UMTS_CA_BAND(UMTSBand5, UMTSBand2),
}UMTSCaBand;

typedef enum
{
   UMTS_Route0    = 0,
   UMTS_Route1    = 1,
   UMTS_Route2    = 2,
   UMTS_Route3    = 3,
   UMTS_Route4    = 4,
   UMTS_Route5    = 5,
   UMTS_Route6    = 6,
   UMTS_Route7    = 7,
   UMTS_Route8    = 8,
   UMTS_Route9    = 9,
   UMTS_Route10   = 10,
   UMTS_Route11   = 11,
   UMTS_Route12   = 12,
   UMTS_Route13   = 13,
   UMTS_Route14   = 14,
   UMTS_Route15   = 15,
   UMTS_Route16   = 16,
   UMTS_Route17   = 17,
   UMTS_Route18   = 18,
   UMTS_Route19   = 19,
   UMTS_Route20   = 20,
   UMTS_Route21   = 21,
   UMTS_Route22   = 22,
   UMTS_Route23   = 23,
   UMTS_Route24   = 24,
   UMTS_Routecount,
   UMTS_RouteMax  = 0xFF,
}  UMTS_Route;

typedef struct
{
   kal_uint32 single_band_ca_list;
   kal_uint32 dual_band_ca_list;
} CA_RF_BAND_CAPABILITY_T;

#if (IS_3G_TX_POWER_OFFSET_SUPPORT || IS_3G_SAR_TX_POWER_BACKOFF_SUPPORT)
typedef  struct
{
   kal_uint16 max_uarfcn;
   kal_int16  pwr_offset_dB[2][3];    /* [Ant 0/1 Main/Div][Mode 0/1/2 R99/HSDPA/HSUPA] ; unit: 1/8 dB, range: -8 ~ +7 dB */ 
}  U_sSUBBAND_SECTION;

typedef struct 
{
   U_sSUBBAND_SECTION  subband_power_offset[CAL_UARFCN_SECTION];
} U_sTXPOWEROFFSETTABLE;

typedef struct 
{
   U_sTXPOWEROFFSETTABLE  table[TPO_3G_TABLE_NUM];
} U_sTXPOWEROFFSETDATA;
#endif /* IS_3G_TX_POWER_OFFSET_SUPPORT */

#if IS_3G_ELNA_SUPPORT
typedef enum
{
   UMTS_ELNA_OFF,
   UMTS_ELNA_ON
}  ELNA_Setting_E;
#endif

/*******************************************************************************
** RF Customization usage
*******************************************************************************/

/*******************************************************************************
** Macros and constants
*******************************************************************************/
#if defined(__UMTS_R8__)
   //For R8 project use internal definition.
#else
#define CAL_RX_ACT_DLY                5 //CAL_RX_ACT_DLY*64 samples = CAL_RX_ACT_DLY*38 chips
#define CAL_RX_DC_LEN                 4 //0~7, 1<<(4+CAL_RX_DC_LEN) samples = (1<<(4+CAL_RX_DC_LEN))*0.6 chips
#define CAL_RX_DC_STL_TIME            30 //CAL_RX_DC_STL_TIME asmples = CAL_RX_DC_STL_TIME/2 chips
#define CAL_RX_IQ_LEN                 7 //0~8, 1<<(4+CAL_RX_IQ_LEN) samples = 1<<(3+CAL_RX_IQ_LEN) chips

//Sample to Chip = Samples * (3.84MHz/6.5MHz=0.59077)
#define CAL_RX_IDLE_IN_CHIP           1      //chips
#define CAL_RX_ACT_DLY_IN_CHIP        190    //CAL_RX_ACT_DLY*(64)*0.59077 chips
#define CAL_RX_DC_LEN_IN_CHIP         152    //(1<<(4+CAL_RX_DC_LEN))*0.59077 chips
#define CAL_RX_DC_STL_TIME_IN_CHIP    18     //CAL_RX_DC_STL_TIME*0.59077 chips
#define CAL_RX_IQ_LEN_IN_CHIP         1210   //(1<<(4+CAL_RX_IQ_LEN))*0.59077 chips

#define RXCAL_TTG_DIS_GUARD_TIME      30 //Chips ~=7.8us
#define RXCAL_MODE_CHANGE_GUARD_TIME  20 //Chips ~=5.2us
#define RXCAL_TOTAL_TIME              (CAL_RX_IDLE_IN_CHIP + CAL_RX_ACT_DLY_IN_CHIP + CAL_RX_DC_LEN_IN_CHIP + CAL_RX_DC_STL_TIME_IN_CHIP + CAL_RX_IQ_LEN_IN_CHIP + RXCAL_TTG_DIS_GUARD_TIME)
#define RXCAL_EVENT_SHIFT_TIME0       (RXCAL_TOTAL_TIME+RXCAL_MODE_CHANGE_GUARD_TIME+RXCAL_TOTAL_TIME+TC_SR2B)
#define RXCAL_EVENT_SHIFT_TIME1       (RXCAL_TOTAL_TIME+TC_SR2B)

#define RXCAL_EVENT_SHIFT_TIME       (RXCAL_TOTAL_TIME+RXCAL_MODE_CHANGE_GUARD_TIME+RXCAL_TOTAL_TIME+TC_SR2B)
#endif //__UMTS_R8__

#define  U_PWRRES                   4 // resolution 0.25dB
#define  U_GAINLOSS( n )           ((kal_int8)((n)*U_PWRRES))
#define  UMTS_TABLE_END             0 // Use this value ater the end of UARFCN weight
#define  MICROSECOND_TO_CHIP(x)    ((kal_int32)((x)*3.84))

#if !defined(UMTS_RF_TYPE)
#define  UMTS_RF_TYPE  2
#endif

#if defined(__UMTS_R8__)
#define UMTS_RF_MAX_PA_SECTIONS                (3)
#define UMTS_RF_RX_START_TIMING_ARRAY_LENGTH   (6)
#define UMTS_RF_RX_END_TIMING_ARRAY_LENGTH     (3)
#define UMTS_RF_TX_START_TIMING_ARRAY_LENGTH   (7)
#define UMTS_RF_TX_END_TIMING_ARRAY_LENGTH     (3)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_BANDS   (11)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_WINDOWS  (2)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_EVENTS   (5)
#define UMTS_RF_BPI_DATA2_TABLE_NUM_OF_EVENTS  (5)
#else
#define UMTS_RF_MAX_PA_SECTIONS                (3)
#define UMTS_RF_RX_START_TIMING_ARRAY_LENGTH   (6)
#define UMTS_RF_RX_END_TIMING_ARRAY_LENGTH     (3)
#define UMTS_RF_TX_START_TIMING_ARRAY_LENGTH   (8)
#define UMTS_RF_TX_END_TIMING_ARRAY_LENGTH     (5)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_BANDS   (11)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_WINDOWS  (2)
#define UMTS_RF_BPI_DATA_TABLE_NUM_OF_EVENTS   (5)
#endif

/*******************************************************************************
** Typedefs
*******************************************************************************/
typedef struct
{
   kal_uint16 maxOffset;
   kal_uint16 vmOffset;
   kal_uint16 vbiasOffset;
   kal_uint16 dc2dcOffset;
   kal_uint16 vgaOffset;
}U_sUl1dRfPaControlTiming;

typedef struct
{
   /* RX window start timing */
   kal_int16 xTC_PR1;
   kal_int16 xTC_PR2;
   kal_int16 xTC_PR2B;

   /* RX window end timing */
   kal_int16 xTC_PR3;
   kal_int16 xTC_PR3A;

   /* TX window start timing */
   kal_int16 xTC_PT1;
   kal_int16 xTC_PT2;
   kal_int16 xTC_PT2B;

   /* TX window end timing */
   kal_int16 xTC_PT3;
   kal_int16 xTC_PT3A;
}U_sUl1dRfBsiBpiTiming;

typedef struct
{
   UL1_RF_RX_IO_E  rxio;
   UL1_RF_RXD_IO_E rxdio;
}UMTS_RX_IODATA_T;

typedef struct
{
   BPI_data_type pr1;
   BPI_data_type pr2;
   BPI_data_type pr2b;
   BPI_data_type pr3;
   BPI_data_type pr3a;
}UMTS_RX_PDATA_T;

typedef struct
{
   UL1_RF_TX_IO_E txio;
   UL1_RF_TX_DET_IO_E txdetio;
}UMTS_TX_IODATA_T;

typedef struct
{
   BPI_data_type pt1;
   BPI_data_type pt2;
   BPI_data_type pt2b;
   BPI_data_type pt3;
   BPI_data_type pt3a;
}UMTS_TX_PDATA_T;

typedef struct
{
   UMTSBand bandIdx;
   UMTS_RX_PDATA_T rxPdata;
}UMTS_RX_PDATABASE_T;

typedef struct
{
   UMTSBand bandIdx;
   UMTS_TX_PDATA_T txPdata;
}UMTS_TX_PDATABASE_T;

typedef struct
{
   UMTSBand bandIdx;
   UMTS_RX_IODATA_T rxIodata;
}UMTS_RXIOBASE_T;

typedef struct
{
   UMTSBand bandIdx;
   UMTS_TX_IODATA_T txIodata;
}UMTS_TXIOBASE_T;

typedef struct
{
   UMTS_RX_PDATABASE_T rxBpi[UMTS_FE_RXBASE_TBL_SIZE_MAX];
   UMTS_TX_PDATABASE_T txBpi[UMTS_FE_TXBASE_TBL_SIZE_MAX];
}U_sUl1dRfBpiData;

#if IS_3G_DAT_UL1_CUSTOM_SUPPORT
typedef enum
{
   UMTS_DAT_CAT_A_MIPI_TABLE_CONFIG_IDX0,
   UMTS_DAT_CAT_A_MIPI_TABLE_CONFIG_IDX1,
   UMTS_DAT_CAT_A_MIPI_TABLE_CONFIG_IDX2,
   UMTS_DAT_CAT_A_MIPI_TABLE_CONFIG_IDX3,
   UMTS_DAT_CAT_A_MIPI_TABLE_CONFIG_IDX4,
   UMTS_DAT_CAT_A_MIPI_TABLE_CONFIG_IDX5,
   UMTS_DAT_CAT_A_MIPI_TABLE_CONFIG_IDX6,
   UMTS_DAT_CAT_A_MIPI_TABLE_CONFIG_IDX7,
   UMTS_DAT_CAT_A_MIPI_TABLE_CONFIG_IDX8,
   UMTS_DAT_CAT_A_MIPI_TABLE_CONFIG_IDX9,
   UMTS_DAT_CAT_A_MIPI_TABLE_NULL = UMTS_DAT_MIPI_TABLE_NULL,
}UMTS_CUSTOM_DAT_CAT_A_MIPI_TBL_IDX_E;


typedef enum
{
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX0,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX1,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX2,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX3,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX4,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX5,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX6,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX7,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX8,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX9,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX10,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX11,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX12,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX13,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX14,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX15,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX16,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX17,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX18,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX19,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX20,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX21,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX22,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX23,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX24,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX25,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX26,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX27,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX28,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX29,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX30,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX31,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX32,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX33,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX34,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX35,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX36,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX37,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX38,
   UMTS_DAT_CAT_B_MIPI_TABLE_CONFIG_IDX39,
   UMTS_DAT_CAT_B_MIPI_TABLE_NULL = UMTS_DAT_MIPI_TABLE_NULL,
}UMTS_CUSTOM_DAT_CAT_B_MIPI_TBL_IDX_E;

typedef enum
{
   UMTS_DAT_CAT_A_CONFIG_IDX0,
   UMTS_DAT_CAT_A_CONFIG_IDX1,
   UMTS_DAT_CAT_A_CONFIG_IDX2,
   UMTS_DAT_CAT_A_CONFIG_IDX3,
   UMTS_DAT_CAT_A_CONFIG_IDX4,
   UMTS_DAT_CAT_A_CONFIG_IDX5,
   UMTS_DAT_CAT_A_CONFIG_IDX6,
   UMTS_DAT_CAT_A_CONFIG_IDX7,
   UMTS_DAT_CAT_A_CONFIG_IDX8,
   UMTS_DAT_CAT_A_CONFIG_IDX9,
   UMTS_DAT_CAT_A_NULL = UMTS_DAT_FE_NULL,
}UMTS_CUSTOM_DAT_CAT_A_IDX_E;

typedef enum
{
   UMTS_DAT_CAT_B_CONFIG_IDX0,
   UMTS_DAT_CAT_B_CONFIG_IDX1,
   UMTS_DAT_CAT_B_CONFIG_IDX2,
   UMTS_DAT_CAT_B_CONFIG_IDX3,
   UMTS_DAT_CAT_B_CONFIG_IDX4,
   UMTS_DAT_CAT_B_CONFIG_IDX5,
   UMTS_DAT_CAT_B_CONFIG_IDX6,
   UMTS_DAT_CAT_B_CONFIG_IDX7,
   UMTS_DAT_CAT_B_CONFIG_IDX8,
   UMTS_DAT_CAT_B_CONFIG_IDX9,
   UMTS_DAT_CAT_B_CONFIG_IDX10,
   UMTS_DAT_CAT_B_CONFIG_IDX11,
   UMTS_DAT_CAT_B_CONFIG_IDX12,
   UMTS_DAT_CAT_B_CONFIG_IDX13,
   UMTS_DAT_CAT_B_CONFIG_IDX14,
   UMTS_DAT_CAT_B_CONFIG_IDX15,
   UMTS_DAT_CAT_B_CONFIG_IDX16,
   UMTS_DAT_CAT_B_CONFIG_IDX17,
   UMTS_DAT_CAT_B_CONFIG_IDX18,
   UMTS_DAT_CAT_B_CONFIG_IDX19,
   UMTS_DAT_CAT_B_CONFIG_IDX20,
   UMTS_DAT_CAT_B_CONFIG_IDX21,
   UMTS_DAT_CAT_B_CONFIG_IDX22,
   UMTS_DAT_CAT_B_CONFIG_IDX23,
   UMTS_DAT_CAT_B_CONFIG_IDX24,
   UMTS_DAT_CAT_B_CONFIG_IDX25,
   UMTS_DAT_CAT_B_CONFIG_IDX26,
   UMTS_DAT_CAT_B_CONFIG_IDX27,
   UMTS_DAT_CAT_B_CONFIG_IDX28,
   UMTS_DAT_CAT_B_CONFIG_IDX29,
   UMTS_DAT_CAT_B_CONFIG_IDX30,
   UMTS_DAT_CAT_B_CONFIG_IDX31,
   UMTS_DAT_CAT_B_CONFIG_IDX32,
   UMTS_DAT_CAT_B_CONFIG_IDX33,
   UMTS_DAT_CAT_B_CONFIG_IDX34,
   UMTS_DAT_CAT_B_CONFIG_IDX35,
   UMTS_DAT_CAT_B_CONFIG_IDX36,
   UMTS_DAT_CAT_B_CONFIG_IDX37,
   UMTS_DAT_CAT_B_CONFIG_IDX38,
   UMTS_DAT_CAT_B_CONFIG_IDX39,
   UMTS_DAT_CAT_B_NULL = UMTS_DAT_FE_NULL,
}UMTS_CUSTOM_DAT_CAT_B_IDX_E;


typedef enum
{
   UMTS_DAT_STATE0,
   UMTS_DAT_STATE1,
   UMTS_DAT_STATE2,
   UMTS_DAT_STATE3,
   UMTS_DAT_STATE4,
   UMTS_DAT_STATE5,
   UMTS_DAT_STATE6,
   UMTS_DAT_STATE7,
   UMTS_DAT_STATE_NULL,
}UMTS_CUSTOM_DAT_STATE_E;
   
typedef struct
{
   kal_uint32   cat_a_route_num;
   kal_uint32   cat_b_route_num;
}UMTS_CUSTOM_DAT_FE_ROUTE_MAP_T;

typedef struct
{  
   kal_bool   feature_enable;
   kal_int16  ap_scenario;
}UMTS_CUSTOM_DAT_FEATURE_BY_RAT_T;

typedef struct
{
   UMTSBand                           usage;
   UMTS_CUSTOM_DAT_FE_ROUTE_MAP_T     dat_fe_setting[UMTS_DAT_MAX_STATE_NUM];
}UMTS_CUSTOM_DAT_ROUTE_SETTING_T;   

typedef struct
{
   UMTS_CUSTOM_DAT_ROUTE_SETTING_T    UMTS_dat_fe_route_db[UMTS_DAT_MAX_FE_ROUTE_NUM];
}UMTS_CUSTOM_DAT_FE_ROUTE_DATABASE_T;   

typedef struct
{
   kal_uint32                     bpi_mask;
   kal_uint32                     bpi_value;
   UMTS_CUSTOM_DAT_CAT_A_MIPI_TBL_IDX_E dat_mipi_table_index;
}UMTS_CUSTOM_DAT_CAT_A_FE_SETTING_T;

typedef struct
{
   kal_uint32                     bpi_mask;
   kal_uint32                     bpi_value;
   UMTS_CUSTOM_DAT_CAT_B_MIPI_TBL_IDX_E dat_mipi_table_index;
}UMTS_CUSTOM_DAT_CAT_B_FE_SETTING_T;

typedef struct
{
   UMTS_CUSTOM_DAT_CAT_A_FE_SETTING_T   dat_cat_a_fe_route[UMTS_DAT_MAX_CAT_A_ROUTE_NUM];
}UMTS_CUSTOM_DAT_FE_CAT_A_T;

typedef struct
{
   UMTS_CUSTOM_DAT_CAT_B_FE_SETTING_T   dat_cat_b_fe_route[UMTS_DAT_MAX_CAT_B_ROUTE_NUM];
}UMTS_CUSTOM_DAT_FE_CAT_B_T;


typedef struct
{
   UMTS_CUSTOM_DAT_FE_CAT_A_T   dat_cat_a_fe_db;
   UMTS_CUSTOM_DAT_FE_CAT_B_T   dat_cat_b_fe_db;
}UMTS_CUSTOM_DAT_FE_DATABASE_T;
#endif

typedef enum
{
   UL1_ANTENNA_0,     /* Main antenna */
   UL1_ANTENNA_1,     /* Diversity antenna */
   UL1_ANTENNA_2,     /* Auxiliary antenna */
   UL1_ANTENNA_NUM
}
ul1_antenna_idx_E;

#if IS_3G_TAS_SUPPORT
typedef struct
{
   /* Band 1 TAS BPI data */
   BPI_data_type xPDATA_BAND1_TAS1;
   BPI_data_type xPDATA_BAND1_TAS2;
   BPI_data_type xPDATA_BAND1_TAS3;

   /* Band 2 TAS BPI data */
   BPI_data_type xPDATA_BAND2_TAS1;
   BPI_data_type xPDATA_BAND2_TAS2;
   BPI_data_type xPDATA_BAND2_TAS3;

   /* Band 3 TAS BPI data */
   BPI_data_type xPDATA_BAND3_TAS1;
   BPI_data_type xPDATA_BAND3_TAS2;
   BPI_data_type xPDATA_BAND3_TAS3;

   /* Band 4 TAS BPI data */
   BPI_data_type xPDATA_BAND4_TAS1;
   BPI_data_type xPDATA_BAND4_TAS2;
   BPI_data_type xPDATA_BAND4_TAS3;

   /* Band 5 TAS BPI data */
   BPI_data_type xPDATA_BAND5_TAS1;
   BPI_data_type xPDATA_BAND5_TAS2;
   BPI_data_type xPDATA_BAND5_TAS3;

   /* Band 6 TAS BPI data */
   BPI_data_type xPDATA_BAND6_TAS1;
   BPI_data_type xPDATA_BAND6_TAS2;
   BPI_data_type xPDATA_BAND6_TAS3;

   /* Band 7 TAS BPI data */
   BPI_data_type xPDATA_BAND7_TAS1;
   BPI_data_type xPDATA_BAND7_TAS2;
   BPI_data_type xPDATA_BAND7_TAS3;

   /* Band 8 TAS BPI data */
   BPI_data_type xPDATA_BAND8_TAS1;
   BPI_data_type xPDATA_BAND8_TAS2;
   BPI_data_type xPDATA_BAND8_TAS3;

   /* Band 9 TAS BPI data */
   BPI_data_type xPDATA_BAND9_TAS1;
   BPI_data_type xPDATA_BAND9_TAS2;
   BPI_data_type xPDATA_BAND9_TAS3;

   /* Band 10 TAS BPI data */
   BPI_data_type xPDATA_BAND10_TAS1;
   BPI_data_type xPDATA_BAND10_TAS2;
   BPI_data_type xPDATA_BAND10_TAS3;

   /* Band 11 TAS BPI data */
   BPI_data_type xPDATA_BAND11_TAS1;
   BPI_data_type xPDATA_BAND11_TAS2;
   BPI_data_type xPDATA_BAND11_TAS3;

   /* Band 19 TAS BPI data */
   BPI_data_type xPDATA_BAND19_TAS1;
   BPI_data_type xPDATA_BAND19_TAS2;
   BPI_data_type xPDATA_BAND19_TAS3;
}U_sUl1dRfTasBpiData;

typedef struct
{
   BPI_data_type       umtsTasMask;
   U_sUl1dRfTasBpiData umtsTasPdata;
}U_sUl1dRfTasData;


#if (IS_3G_TAS_UL1_CUSTOM_SET)

typedef enum
{
   TAS_TYPE_0,    /* TAS Disable */
   TAS_TYPE_1,    /* TAS with Rx Diversity support */
   TAS_TYPE_2,    /* TAS WITHOUT Rx Diversity support */
} ul1_tas_type_E;

typedef enum
{
   BY_BAND_TAS_TYPE_0 = TAS_TYPE_0,/* TAS Disable */
   BY_BAND_TAS_TYPE_1 = TAS_TYPE_1,/* TAS with Rx Diversity support */
   BY_BAND_TAS_TYPE_2 = TAS_TYPE_2,/* TAS WITHOUT Rx Diversity support */
   BY_BAND_TAS_TYPE_Default        /* Set TAS type as tas_default_type for each band */
} ul1_tas_type_by_band_E;

typedef struct
{
   kal_int16           rscp_diff_thd_po;           /* RSCP difference threshold */
   kal_int16           rscp_cb_thd;                /* RSCP drop threshold */
   kal_int8            txp_cb_thd;                 /* Transmit power increase threshold during check-back */
   kal_uint8           n_ms_cb;                    /* Check-back period for RSCP, TXP (in measurement slots, MS) */
   kal_int8            u_htp;                      /* High transmit power offset */
   kal_uint8           htp_thd;                    /* High transmit power ratio threshold (in percentage, %) */
   kal_int8            tpc_inc_thd1;               /* Transmit power increase threshold */
   kal_uint8           n_ms_sb;                    /* Monitoring duration for switch-back check (in measurement slots, MS) */
} UMTS_TAS_Type1_Params_T;

typedef struct
{
   //kal_uint16          t_thd1_j;                   /* Periodic check timer threshold (in frames) */
   kal_int16           rscp_thd_po;                /* RSCP threshold */
   kal_int16           rscp_cb_thd;                /* RSCP drop threshold */
   kal_int8            txp_cb_thd;                 /* Transmit power increase threshold during check-back */
   kal_uint8           n_ms_cb;                    /* Check-back period for RSCP, TXP (in measurement slots, MS) */
   kal_int8            u_htp;                      /* High transmit power offset */
   kal_uint8           htp_thd;                    /* High transmit power ratio threshold (in percentage, %) */
   kal_int16           rscp_drop_thd_po;           /* RSCP drop threshold */
   kal_int8            tpc_inc_thd;                /* Transmit power increase threshold */
   kal_uint8           n_ms_sb;                    /* Monitoring duration for switch-back check (in measurement slots, MS) */
   kal_int16           rscp_thd_idle;              /* RSCP threshold for IDLE mode */
   kal_int16           rscp_drop_thd_idle;         /* RSCP drop threshold for IDLE mode */
   kal_uint8           n_ms_sb_idle;               /* Monitoring duration for switch-back check in IDLE mode (in DRX cycles) */
   kal_int16           ecno_thd;                   /* EcNo threshold */
} UMTS_TAS_Type2_Params_T;

typedef struct {
   ul1_tas_type_by_band_E      xBand1_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand2_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand3_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand4_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand5_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand6_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand8_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand9_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand10_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand11_TAS_TYPE;
   ul1_tas_type_by_band_E      xBand19_TAS_TYPE;
} UMTS_TAS_Type_By_Band_T;

typedef struct
{
   kal_bool                   umts_tas_enable;
   kal_bool                   umts_tas_support_on_test_sim;
   ul1_antenna_idx_E          umts_tas_default_main_antenna;
   ul1_tas_type_E             umts_tas_default_type;
   UMTS_TAS_Type_By_Band_T    umts_tas_type_by_band;
#if IS_3G_FORCE_TX_ANT_SUPPORT
   kal_bool                   umts_tas_force_tx_ant_enable;
   ul1_antenna_idx_E          umts_tas_force_tx_ant_index;
#endif/* IS_3G_FORCE_TX_ANT_SUPPORT */
} UMTS_TAS_Configuration_T;

#endif/*IS_3G_TAS_UL1_CUSTOM_SET*/

#endif/*IS_3G_TAS_SUPPORT*/

#if (IS_3G_TAS_ANTENNA_IDX_ON_TEST_SIM)
typedef struct {
   ul1_antenna_idx_E         xBand1_TAS_ANT_IDX;
   ul1_antenna_idx_E         xBand2_TAS_ANT_IDX;
   ul1_antenna_idx_E         xBand3_TAS_ANT_IDX;
   ul1_antenna_idx_E         xBand4_TAS_ANT_IDX;
   ul1_antenna_idx_E         xBand5_TAS_ANT_IDX;
   ul1_antenna_idx_E         xBand6_TAS_ANT_IDX;
   ul1_antenna_idx_E         xBand8_TAS_ANT_IDX;
   ul1_antenna_idx_E         xBand9_TAS_ANT_IDX;
   ul1_antenna_idx_E         xBand10_TAS_ANT_IDX;
   ul1_antenna_idx_E         xBand11_TAS_ANT_IDX;
   ul1_antenna_idx_E         xBand19_TAS_ANT_IDX;
} UMTS_TAS_ANT_IDX_T;
#endif

typedef struct
{
   UMTSBand HB1;
   UMTSBand HB2;
   UMTSBand HB3;
   UMTSBand LB1;
   UMTSBand LB2;
}U_sUl1dRfBandIndicator;

typedef struct
{
   UMTS_RXIOBASE_T rxLnaSel[UMTS_FE_RXBASE_TBL_SIZE_MAX];
}U_sUl1dRfRxLnaPortSel;

typedef struct
{
   UMTS_TXIOBASE_T txPathSel[UMTS_FE_TXBASE_TBL_SIZE_MAX];
}U_sUl1dRfTxPathSel;

typedef struct
{
   kal_uint32 Rx_Main_Path_Onoff;
   kal_uint32 Rx_Diversity_Path_Onoff;
}U_sUl1dRxdPathSetting;

#if defined (__UL1_HS_PLUS_PLATFORM__)
typedef struct
{
   MPR_Setting HSDPA_MprBackOff[20];
   MPR_Setting HSUPA_MprBackOff[20];
}U_sUl1dMprBackOff;
#endif

#if IS_3G_MIPI_SUPPORT
typedef struct
{
   kal_bool   is3gMipiEn;
   kal_uint16 mipiOffset;
   #if IS_3G_ET_SUPPORT
   kal_bool   is3gEtEn;
   #endif
}U_sUl1dRfMipiSetting;
#endif

#if IS_3G_ELNA_SUPPORT
typedef struct
{
   ELNA_Setting_E isRxElnaOn[20];
   ELNA_Setting_E isRxDElnaOn[20];
}U_sUl1DElnaSetting;
#endif

/********************************************************************
**       CA structure declaration
*********************************************************************/

typedef struct
{
   UMTSCaBand CA_IND_0;
   UMTSCaBand CA_IND_1;
   UMTSCaBand CA_IND_2;
   UMTSCaBand CA_IND_3;
   UMTSCaBand CA_IND_4;
}U_sUl1dRfCaBandIndicator;

typedef struct
{
   kal_uint16           cc_cnt;
   UMTSBand             cc_band[MAX_NUMBER_OF_RX_SUBBLOCK];
}UMTS_CA_CFG_T;

typedef struct
{
   UMTS_RX_IODATA_T    rxIodata;
   UMTS_RX_PDATA_T     rxPdata;
   UMTS_Route          rxMipiTblIdx;
}UMTS_FE_RX_ROUTE_T;

typedef struct
{
   UMTS_TX_IODATA_T     txIodata;
   UMTS_TX_PDATA_T      txPdata;
   UMTS_Route           txMipiTblIdx;
}UMTS_FE_TX_ROUTE_T;

typedef struct
{
   UMTSBand            band;
   UMTS_FE_RX_ROUTE_T  rx_cfg;
   UMTS_FE_TX_ROUTE_T  tx_cfg;
}U_sUl1dRfFeRouteSetting;

typedef struct
{
   kal_uint32 band; //TBD: how about CA_BAND_IND?
   kal_uint8  cc_cnt;
   U_sUl1dRfFeRouteSetting  cc_fe_route[MAX_NUMBER_OF_RX_SUBBLOCK];
}UMTS_FE_ROUTE_TABLE_T;

typedef struct
{
   UMTS_Route         rx_tbl_idx[MAX_NUMBER_OF_RX_SUBBLOCK];
   UMTS_Route         tx_tbl_idx[MAX_NUMBER_OF_TX_SUBBLOCK];
}UMTS_USAGE_ELM_T;

typedef union
{
   UMTS_RXIOBASE_T  rxio;
   UMTS_TXIOBASE_T  txio;
   UMTS_RX_PDATABASE_T  rxbpi;
   UMTS_TX_PDATABASE_T  txbpi;
}UMTS_DATABASE_U;

typedef struct
{
   UMTS_CA_CFG_T      usage;
   UMTS_USAGE_ELM_T   iobase;
   UMTS_USAGE_ELM_T   pdatabase;
   UMTS_USAGE_ELM_T   mipibase;
}UMTS_FE_USAGE_T;

typedef struct
{
   void        *database_ptr;
   kal_uint16   database_elm_size;
   kal_uint16   database_ttl_size;
   kal_uint16 (*database_handler)( kal_uint16 handle, void *src, void *dst );
} UL1D_DATABASE_HANDLER_T;

typedef struct
{
   /* Start pattern to be recognized by Modem Bin Update Tool */
   kal_uint32 startPattern;

   /* RF and parameter structure version */
   kal_uint8 structVersion; // record structure version for tool once we add more parameters to be customized in the future
   kal_uint8 rfType; // needed? To distinguish O3, OH and furhter 3G RF chips
   kal_uint8 isDataUpdate; // default FALSE, will be update to be TRUE after tool update parameters
   #if defined (__UL1_HS_PLUS_PLATFORM__)
   kal_bool  umtsRfSettingByNVRAM; // default True. if the value is False, than Single SW for Multiple HW scheme will be applied.
   #endif

   /* Timing of PA control */
   U_sUl1dRfPaControlTiming umtsRfPaControlTimingOffset;

   /* RF T/RX timing offset */
   U_sUl1dRfBsiBpiTiming umtsBsiBpiTiming;

   /* BPI data allocation */
   U_sUl1dRfBpiData umtsPdata;

   /* RF Hign-band and Low-band indicator */
   U_sUl1dRfBandIndicator umtsBandIndicator;

   /* RX LNA port selection */
   U_sUl1dRfRxLnaPortSel umtsRxLnaPortSel;

   /* TX output path selection */
   U_sUl1dRfTxPathSel umtsTxPathSel;

   /* PMU VPA control disable/enable */
   kal_bool xPMU_PA_CONTROL;

#if defined (__UL1_HS_PLUS_PLATFORM__)
   /* PMU VPA control disable/enable */
   U_sUl1dMprBackOff umtsMprBackOff;
#endif
   
   /* RxD support bit map*/
   kal_bool umtsRxDAlwaysOn;
   
   /* Tx PA dirft compensation bit map*/
   kal_uint32 umtsPADriftCompensation;

   /*MT6320, Vrf18 Bulk=>LOD solution*/
   kal_bool ultra_low_cost_solution;

   /*MT6167, temperature measurement enable*/
   kal_bool customer_TM_enable;

   /* Baseband Idle Mode RXD Feature enable */
   kal_bool umtsIdleModeRxDOn;   
   
   /* End pattern to be recognized by Modem Bin Update Tool */

   /* VPA Mode Setting */
   kal_bool vpa_fpwm_mode;

   /* PA Section */
   kal_uint8 pa_section;

#if IS_3G_MIPI_SUPPORT
   U_sUl1dRfMipiSetting umtsRfMipiSetting;
#endif

   /* RF CA Band indicator */
   U_sUl1dRfCaBandIndicator umtsCaBandIndicator;

   /* CA RF FE usage table */
   UMTS_FE_USAGE_T umtsCaFrontEndUsageLut[UMTS_RF_FRONT_END_NUM_MAX];

#if IS_3G_FDD_RX_PATH_SELECTION_SUPPORT
   U_sRxPathSelection umtsRxPathSelection;
#endif

#if IS_3G_BAND5_AND_BAND6_INDICATOR_SUPPORT
   kal_bool band5_and_band6_indicator;
#endif

   /* End pattern to be recognized by Modem Bin Update Tool */
   kal_uint32 endPattern;
   
}U_sUl1dRfCustomInputData;

/*=========================================================*/
//   
//   CA Route Table SETTING
//
/*=========================================================*/
/** UMTS RF Rx VCO-Divider set element template */
typedef struct
{
   kal_uint8 vco;          ///< VCO index: 1: VCO1; 2: VCO2; 3: VCO31 or VCO32, and NULL (0xFF)
   kal_uint8 div;          ///< Divider: 2, 4, 6, 8, 10, 3, and NULL (0xFF)
} UMTS_RF_VCO_DIV_SEL_T;

/** UMTS RF Rx VCO-Divider selection table */
typedef struct
{
   UMTSBand                band;
   UMTS_RF_VCO_DIV_SEL_T   vco_div_set[UMTS_RF_RX_VCO_DIV_SET_NUM];
} UMTS_RF_RX_VCO_DIV_TABLE_T;

/** UMTS RF Tx VCO-Divider selection table
 */
typedef struct
{
   UMTSBand                band;
   UMTS_RF_VCO_DIV_SEL_T   vco_div_set[UMTS_RF_TX_VCO_DIV_SET_NUM];
} UMTS_RF_TX_VCO_DIV_TABLE_T;

/** UMTS RF CA VCO-Divider selection table
 */
typedef struct
{
   UMTSBand                band[UMTS_RF_CA_MAX_CC_NUM];              // 0:   PCC, 1: SCC
   UMTS_RF_VCO_DIV_SEL_T   vco_div_set[UMTS_RF_CA_VCO_DIV_SET_NUM];  // 0: RxPCC, 1: RxSCC, 2: TxPCC
} UMTS_RF_CA_VCO_DIV_TABLE_T;

typedef struct
{
   UMTSBand              band;
   UMTS_FE_RX_ROUTE_T    rx_cfg;
   UMTS_RF_VCO_DIV_SEL_T rx_vco_div;
   kal_uint8             srx;
   UMTS_Route            comp_rroute;
   kal_uint8             rx_irr_comp_idx;
   kal_uint8             rx_dc_comp_idx;
}UMTS_RX_ROUTE_TABLE_T;

typedef struct
{
   UMTSBand              band;
   UMTS_FE_TX_ROUTE_T    tx_cfg;
   UMTS_RF_VCO_DIV_SEL_T tx_vco_div;
   kal_uint8             stx;
   UMTS_Route            comp_troute;
}UMTS_TX_ROUTE_TABLE_T;

typedef struct
{
   UMTS_CA_CFG_T        usage;
   UMTS_Route           rx_cc_route_idx[MAX_NUMBER_OF_RX_SUBBLOCK];
   UMTS_Route           tx_cc_route_idx;
   kal_uint8            rx_iip2_comp_idx[MAX_NUMBER_OF_RX_SUBBLOCK];
}UMTS_USAGE_DES_T;

typedef  UMTS_Route     UMTS_RX_COMP_ROUTE_TABLE_T;
typedef  UMTS_Route     UMTS_TX_COMP_ROUTE_TABLE_T;

typedef struct
{
   UMTS_FE_ROUTE_TABLE_T       *fe_rt;
   UMTS_RX_ROUTE_TABLE_T       *rx_rt;
   UMTS_TX_ROUTE_TABLE_T       *tx_rt;
   UMTS_RX_COMP_ROUTE_TABLE_T  *rcmp_rt;
   UMTS_TX_COMP_ROUTE_TABLE_T  *tcmp_rt;
   UMTS_USAGE_DES_T            *ug_rt;
}UMTS_TBL_MAP_T;

/******************************
* R/Tx/DET POC cal data
*******************************/
typedef struct
{
   UMTS_RF_POC_RX_COMP_DATA_T   umts_rx_comp[MAX_SUPPORTED_BAND_INDEX];
   UMTS_RF_POC_DET_COMP_DATA_T  umts_det_comp[MAX_SUPPORTED_BAND_INDEX];
   UMTS_RF_POC_TX_COMP_DATA_T   umts_tx_comp[MAX_SUPPORTED_BAND_INDEX];
} UMTS_RF_POWER_ON_CAL_DATA_T;

typedef struct
{
#ifndef TK6291_E1EVB
   kal_uint32 verno;
#endif
   UMTSBand band;
   UMTS_RF_POC_RX_COMP_DATA_T  umts_rx_comp;
   UMTS_RF_POC_DET_COMP_DATA_T umts_det_comp;
   UMTS_RF_POC_TX_COMP_DATA_T  umts_tx_comp;
} UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T;

/** FEC AGC DC Table
 */
#define SRAM_BYTE_128_ALIGN                    (128)  
#define SRAM_PADDIND_TO_128_ALIGN(x)           ((((x)%SRAM_BYTE_128_ALIGN)==0)?SRAM_BYTE_128_ALIGN:(SRAM_BYTE_128_ALIGN - ((x)%SRAM_BYTE_128_ALIGN)))

typedef struct
{
  UMTS_RF_POC_RX_DC_HPM_COMP_T  rx_rf_dc_hpm[MMRFC_ANT_NUM]; //RF DC for HPM
  UMTS_RF_POC_RX_DC_COMP_T      rx_rf_dc_lpm[MMRFC_ANT_NUM]; //RF DC for LPM
  UMTS_RF_POC_RX_DC_HPM_COMP_T  rx_dig_dc_hpm[MMRFC_ANT_NUM]; //Digital DC for HPM
  UMTS_RF_POC_RX_DC_COMP_T      rx_dig_dc_lpm[MMRFC_ANT_NUM]; //Digital DC for LPM
}UL1D_RXAGC_RF_POC_RX_DC_COMP_PER_ROUTE_T;

typedef struct
{
   UL1D_RXAGC_RF_POC_RX_DC_COMP_PER_ROUTE_T dc_part;
   kal_uint8 ready_bit; // for FEC/L1core do checksum
}UL1D_RF_RXAGC_DC_TABLE_T;

//calibration data for a CC
typedef struct
{
   UL1D_RF_RXAGC_DC_TABLE_T dc_table; 
   kal_uint8 padding_to_128_bytes[SRAM_PADDIND_TO_128_ALIGN(sizeof(UL1D_RF_RXAGC_DC_TABLE_T))];   
}UL1D_RF_RXAGC_DC_TABLE_L1_EMI_T;

/*******************************************************************************
** Global data for RF customization and META Factory Calibration
*******************************************************************************/
#if defined(__L1CORE__)
extern kal_uint8 ul1d_BandInfo[MAX_SUPPORTED_BAND_INDEX];
extern kal_uint32 ul1d_CaBandInfo[UMTS_RF_CA_FE_NUM_MAX];
extern UMTS_FE_ROUTE_TABLE_T UMTS_FE_ROUTE_TBL[UMTS_RF_FRONT_END_NUM_MAX];

extern U_sUl1dRfCustomInputData* UMTS_RF_CUSTOM_INPUT_DATA_ptr;

#if (IS_3G_TAS_NVRAM_SUPPORT)
extern U_sUl1dRfTasData               UMTS_TAS_RF_TABLE;
extern UMTS_TAS_Configuration_T       UMTS_TAS_Configuration_Table;

extern U_sUl1dRfTasData*          UMTS_TAS_RF_TABLE_ptr;
extern UMTS_TAS_Configuration_T*  UMTS_TAS_Configuration_Table_ptr;
#endif/*IS_3G_TAS_NVRAM_SUPPORT*/
#if IS_3G_TAS_SUPPORT
extern BPI_data_type  UMTS_TAS_PDATA_TABLE[UL1D_RF_CUSTOM_BAND][UL1_ANTENNA_NUM+1];
#endif/*IS_3G_TAS_SUPPORT*/

#if (IS_3G_TAS_ANTENNA_IDX_ON_TEST_SIM)
extern UMTS_TAS_ANT_IDX_T* UMTS_TAS_ANT_IDX_ptr;
extern UMTS_TAS_ANT_IDX_T  UMTS_TAS_ANT_IDX_by_band;
#endif

#if (IS_3G_TX_POWER_OFFSET_SUPPORT || IS_3G_SAR_TX_POWER_BACKOFF_SUPPORT)
extern U_sTXPOWEROFFSETDATA* UMTS_TX_POWER_OFFSET_TABLE[UL1D_RF_CUSTOM_BAND];
#endif

#if IS_3G_ELNA_SUPPORT
extern U_sUl1DElnaSetting*   UMTS_ELNA_DATA_ptr;
#endif


extern U_sTEMPAGCOFFSET    *U_AGC_PATHLOSS_TABLE[UMTS_AGC_PATHLOSS_TBL_SIZE];
extern U_sRAMPDATA         *UMTS_RampData[UL1D_RF_CUSTOM_BAND];
extern U_sPAOCTLVLSETTING  *U_PA_OCTLEV_TABLE[UL1D_RF_CUSTOM_BAND];
extern U_sPARACHTMCOMPDATA *U_PA_RACH_COMP_TABLE[UL1D_RF_CUSTOM_BAND];
extern U_sTEMPAGCOFFSET    *U_AGC_PATHLOSS_RXD_TABLE[UMTS_AGC_PATHLOSS_TBL_SIZE]; //RXD path loss
extern U_sPADRIFTSETTING   *U_PA_DRIFT_TABLE[];
extern U_sAFCDACDATA       *U_AFC_DAC_ptr;
extern U_sAFCCAPDATA       *U_AFC_CAP_ptr;
extern kal_uint16          *U_TEMP_DAC_ptr;
extern UMTS_RF_POWER_ON_CAL_DATA_T   *U_POC_CAL_DATA_ptr;
extern UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T *UMTS_PWRON_CAL_DATA_PTR[UL1D_RF_CUSTOM_BAND];

extern kal_uint8  DC2DC[UMTS_RF_MAX_PA_SECTIONS];
extern kal_uint8  VM_data[UMTS_RF_MAX_PA_SECTIONS];
extern kal_int16  UMTS_RX_START_TQ_TABLE[UMTS_RF_RX_START_TIMING_ARRAY_LENGTH];
extern kal_int16  UMTS_RX_END_TQ_TABLE[UMTS_RF_RX_END_TIMING_ARRAY_LENGTH];

extern kal_int16  UMTS_TX_START_TQ_TABLE[UMTS_RF_TX_START_TIMING_ARRAY_LENGTH];
extern kal_int16  UMTS_TX_END_TQ_TABLE[UMTS_RF_TX_END_TIMING_ARRAY_LENGTH];

extern BPI_data_type  UMTS_PDATA_TABLE[][UMTS_RF_BPI_DATA_TABLE_NUM_OF_WINDOWS][UMTS_RF_BPI_DATA_TABLE_NUM_OF_EVENTS];
extern BPI_data_type  UMTS_PDATA_TABLE_H[][UMTS_RF_BPI_DATA_TABLE_NUM_OF_WINDOWS][UMTS_RF_BPI_DATA_TABLE_NUM_OF_EVENTS];


extern BPI_data_type  UMTS_PDATA2_RX_TABLE[][UMTS_RF_BPI_DATA2_TABLE_NUM_OF_EVENTS];
extern BPI_data_type  UMTS_PDATA2_RX_TABLE_H[][UMTS_RF_BPI_DATA2_TABLE_NUM_OF_EVENTS];

extern kal_int16 max_rx_start_offset;
extern kal_int16 max_tx_start_offset;
extern kal_int16 min_rx_end_offset;
extern kal_int16 min_tx_end_offset;
extern kal_uint16 max_offset;
extern kal_uint16 vm_offset;
extern kal_uint16 vbias_offset;
extern kal_uint16 dc2dc_offset;
extern kal_uint16 vga_offset;
#if IS_3G_MIPI_SUPPORT
extern kal_bool   is_3g_mipi_enable;
extern kal_uint16 ul1_mipi_offset;
#endif
extern kal_uint8  pa_section;
extern kal_bool VPA_mode_setting;
#endif //define (__L1CORE__)

#if defined(__PCORE__)
extern kal_uint8 ul1d_BandInfo[MAX_SUPPORTED_BAND_INDEX];
extern kal_uint32 ul1d_CaBandInfo[UMTS_RF_CA_FE_NUM_MAX];
extern UMTS_FE_ROUTE_TABLE_T UMTS_FE_ROUTE_TBL[UMTS_RF_FRONT_END_NUM_MAX];

/*this may move to Pcore interface head file*/
extern U_sUl1dRfCustomInputData *UMTS_RF_CUSTOM_INPUT_DATA_PCORE_ptr;
extern U_sUl1dRfCustomInputData UMTS_RF_CUSTOM_INPUT_DATA_PCORE;

#if (IS_3G_TAS_NVRAM_SUPPORT)
extern U_sUl1dRfTasData               *UMTS_TAS_RF_PCORE_ptr;
extern U_sUl1dRfTasData               UMTS_TAS_RF_TABLE_PCORE;

extern UMTS_TAS_Configuration_T       *UMTS_TAS_Configuration_PCORE_ptr;
#endif/*IS_3G_TAS_NVRAM_SUPPORT*/


/* const variable as default calibration data in Pcore */
extern const U_sTEMPAGCOFFSET*    U_AGC_PATHLOSS_TABLE_SetDefault[UMTS_AGC_PATHLOSS_TBL_SIZE];
extern const U_sRAMPDATA*         UMTS_RampData_SetDefault[UL1D_RF_CUSTOM_BAND];
extern const U_sPAOCTLVLSETTING*  U_PA_OCTLEV_TABLE_SetDefault[UL1D_RF_CUSTOM_BAND];
extern const U_sPARACHTMCOMPDATA* U_PA_RACH_COMP_TABLE_SetDefault[UL1D_RF_CUSTOM_BAND];
extern const U_sTEMPAGCOFFSET*    U_AGC_PATHLOSS_RXD_TABLE_SetDefault[UMTS_AGC_PATHLOSS_TBL_SIZE]; //RXD path loss
extern const U_sPADRIFTSETTING*   U_PA_DRIFT_TABLE_SetDefault[];
extern const U_sAFCDACDATA        U_AFC_DAC_SetDefault;
extern const U_sAFCCAPDATA        U_AFC_CAP_SetDefault;
extern const kal_uint16           U_TEMP_DAC_SetDefault[CAL_TEMP_SECTION];
extern UMTS_FE_ROUTE_TABLE_T      UMTS_FE_ROUTE_TBL_SetDefault[UMTS_RF_FRONT_END_NUM_MAX];
#if IS_3G_TAS_SUPPORT
extern const UMTS_TAS_Configuration_T UMTS_TAS_Configuration_Table_SetDefault;
#endif/*IS_3G_TAS_SUPPORT*/

#if (IS_3G_TAS_ANTENNA_IDX_ON_TEST_SIM)
extern UMTS_TAS_ANT_IDX_T       *UMTS_TAS_ANT_IDX_PCORE_ptr;
#endif

#if (IS_3G_TX_POWER_OFFSET_SUPPORT || IS_3G_SAR_TX_POWER_BACKOFF_SUPPORT)
extern const U_sTXPOWEROFFSETDATA*  U_TX_POWER_OFFSET_TABLE_SetDefault[];
extern U_sTXPOWEROFFSETDATA* UMTS_TX_POWER_OFFSET_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
#endif

#if IS_3G_ELNA_SUPPORT
extern U_sUl1DElnaSetting*   UMTS_ELNA_DATA_PCORE_ptr;
#endif

/* Pcore global table pointer extern */
extern U_sTEMPAGCOFFSET    *U_AGC_PATHLOSS_PCORE_TABLE[UMTS_AGC_PATHLOSS_TBL_SIZE];
extern U_sTEMPAGCOFFSET    *U_AGC_PATHLOSS_RXD_PCORE_TABLE[UMTS_AGC_PATHLOSS_TBL_SIZE];
extern U_sRAMPDATA         *UMTS_RampData_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
extern U_sPAOCTLVLSETTING  *U_PA_OCTLEV_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
extern U_sPARACHTMCOMPDATA *U_PA_RACH_COMP_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
extern U_sPADRIFTSETTING   *U_PA_DRIFT_PCORE_TABLE[UL1D_RF_CUSTOM_BAND];
extern U_sAFCDACDATA       *U_AFC_DAC_PCORE_ptr;
extern U_sAFCCAPDATA       *U_AFC_CAP_PCORE_ptr;
extern kal_uint16          *U_TEMP_DAC_PCORE_TABLE;
extern UMTS_RF_POWER_ON_CAL_DATA_T  *U_POC_CAL_DATA_PCORE_ptr;
extern const UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T *UMTS_PWRON_CAL_DATA_PTR[UL1D_RF_CUSTOM_BAND];
#endif //define (__PCORE__)

// Start for ADAPT IOT AMR workaround
//extern kal_bool UL1_IS_ADAPT_IOT_CUSTOMIZATION; //remove for gcc build error
// End for ADAPT IOT AMR workaround
extern kal_uint32 UL1D_DCXO_CAPID;
extern kal_bool   UL1D_Set_CAPID;

/*******************************************************************************
** Global Function Prototypes for RF customization and META Factory Calibration
*******************************************************************************/
// for RAC and L4 to recognize this FDD HW band support query API
extern void UL1D_UeBandCapability(kal_uint16 *ue_cap);
extern void UL1D_UeBandCapabilityEx(kal_uint32 *ue_cap);
extern void UL1D_UeCaBandCapability(CA_RF_BAND_CAPABILITY_T *ue_cap, kal_uint8 report_index);
extern void UL1TST_MsCapability(UMTS_MsCapabilityEx *ms_cap);
extern void UL1D_RF_SetTempDac(void* table);
extern void UL1D_RF_SetPathLossTable(UMTSBand rf_band, void* table);
extern void UL1D_RF_SetTxDacData(UMTSBand rf_band, void* table );
extern void UL1D_RF_SetPaApcDac(UMTSBand rf_band, kal_uint16 idx, kal_uint8 pa_mode, kal_uint8 vm1, kal_uint8 vm2, kal_uint16 dc2dc_level, kal_uint16 vbias_dac, kal_uint16 apc_dac);
extern void UL1D_RF_SetImmediateBSI(kal_uint32 bsidata);
extern void UL1D_RF_GetImmediateBSI(kal_uint32 bsi_addr, kal_uint32 *bsi_data);
extern void UL1D_RF_SetTxPaOctLevData(UMTSBand rf_band, void* table);
extern void UL1D_RF_GetPwrDetMeas(kal_uint16 txpwr_set_idx, kal_uint16 *txpwr_meas);
extern void UL1D_RF_SetTxPrachTmCompData(UMTSBand rf_band, void* table);
extern void UL1D_RF_SetAfcDac(void* table);
extern void UL1D_RF_SetAfcCap(void* table);
extern UMTSBand L1_RxUARFCNToFrequencyBand( kal_uint16 uarfcn, kal_bool is_band6_considered );
extern kal_bool FDD_UL1D_RxMultiCarrier_Check(kal_uint16 *uarfcn_list, kal_uint8 num_uarfcn);
extern kal_bool FDD_UL1D_TxMultiCarrier_Check(kal_uint16 *uarfcn_list, kal_uint8 num_uarfcn);
extern kal_uint8 UL1D_RF_CalDataGetBand(UMTSBand rf_band_in_question, kal_bool nvram_init);
extern kal_uint8 UL1D_RF_UMTSBandToHLB(UMTSBand rf_band);
#if defined(__UMTS_R8__)

extern void UL1D_RF_SetPathLossRxdTable( UMTSBand rf_band, void* table );
extern kal_uint8 UL1D_RF_GetCurrRxDLnaStatus(void);
extern void UL1D_RF_SetTxPaDriftData(UMTSBand rf_band, void* table);
extern void UL1D_RF_SetRxBandwidth(kal_bool is_5mhz);

//just for META link, UL1 define this function as dummy macro
#define UL1D_RF_SetPwrCtrlMode(x)
#else
extern void UL1D_RF_SetPwrCtrlMode(kal_uint8 mode);
#endif

#if !IS_HSPA_HWTPC
extern void UL1D_Meta_HWTPC_Config(kal_uint8 pc_algo, kal_uint8 tpc_used_frame, kal_int16 pini, META_HWTPC_FRAME_INFO* info);
#else
extern void UL1D_Meta_HWTPC_Config(META_HWTPC_INFO *info, META_HWTPC_FRAME_INFO* f_info);
#endif
extern kal_bool UL1TST_GET_BIT_COUNT(kal_uint32* total_bits, kal_uint32* error_bits);
extern kal_int8 UL1D_RF_Replace_Gain_Table_for_Cal(kal_uint32 action);
extern kal_uint8 UL1D_RF_GetCurrRxLnaStatus(void);
extern kal_uint32 UL1D_RF_GetID(void);
extern kal_uint32 UL1TST_CAPID_MAX(void);
extern void UL1D_RF_SetCrystalCap(kal_uint32 cap_no);

extern void UL1T_InitCustomInputData(void);
extern void UL1T_InitPowerOnCalData(void);
extern unsigned long UL1D_RF_GetRxDCOC_CW151(void);

extern void UL1D_RF_UpdateNVRAMToSHM(UMTS_RF_POWER_ON_CAL_DATA_T* p_poc_shm,kal_uint8 band_idx,UMTS_RF_POWER_ON_CAL_DATA_PER_BAND_T* table);

extern void UL1D_RF_CA_CustomData_Update( U_sUl1dRfCustomInputData *dst );
extern void UL1D_RF_DynamicSetRfBandSupport( U_sUl1dRfCustomInputData *dst );
extern void UL1D_RF_UpdateDatabaseTable( void );
extern void UL1T_InitCalibrationData( void );
extern void nvram_init_uL1_mipiData(void);
extern void nvram_init_uL1_tasCustom(void);
extern void nvram_init_uL1_tasRf(void);
#if IS_3G_ET_SUPPORT
extern void nvram_init_uL1_etData(void);
#endif

#if IS_3G_FDD_RX_PATH_SELECTION_SUPPORT
extern U_sUl1dRfCustomInputData* UL1D_RF_ANT_SEL(ANT_SEL_TYPE antsel );
extern ANT_SEL_TYPE UL1D_RF_ANT_QUERY(void);
#endif

#if (IS_3G_TAS_ANTENNA_IDX_ON_TEST_SIM)
extern void nvram_init_uL1_tasAntIdxByBand(void);
#endif

#if IS_3G_TX_POWER_OFFSET_SUPPORT || IS_3G_SAR_TX_POWER_BACKOFF_SUPPORT
extern void UL1D_RF_SetTpoData(kal_uint32 LID, kal_uint8 *buffer );
extern void nvram_init_uL1_TpoData(void);
#endif

#if IS_3G_DAT_UL1_CUSTOM_SUPPORT
extern void nvram_init_uL1_datFeatureByRat(void);
extern void nvram_init_uL1_datFeatureByRoute(void);
extern void nvram_init_uL1_datFeDb(void);
extern void nvram_init_uL1_mipiDatAEvent(void);
extern void nvram_init_uL1_mipiDatAData(void);
extern void nvram_init_uL1_mipiDatBEvent(void);
extern void nvram_init_uL1_mipiDatBData(void);

#ifndef L1_SIM
extern const UMTS_CUSTOM_DAT_FE_CAT_A_T UMTS_DAT_CAT_A_DATABASE_SetDefault;
extern const UMTS_CUSTOM_DAT_FE_CAT_B_T UMTS_DAT_CAT_B_DATABASE_SetDefault;
extern UMTS_CUSTOM_DAT_FE_DATABASE_T UMTS_DAT_FE_DATABASE_SetDefault;
extern const UMTS_CUSTOM_DAT_FE_ROUTE_DATABASE_T UMTS_DAT_FE_ROUTE_DATABASE_SetDefault;
extern UMTS_CUSTOM_DAT_FEATURE_BY_RAT_T UMTS_DAT_FEATURE_BY_RAT_SetDefault;
#endif

extern UMTS_CUSTOM_DAT_FE_DATABASE_T       *UMTS_DAT_FE_DATABASE_TABLE_ptr;
extern UMTS_CUSTOM_DAT_FE_ROUTE_DATABASE_T *UMTS_DAT_FE_ROUTE_TABLE_ptr;
extern UMTS_CUSTOM_DAT_FEATURE_BY_RAT_T    *UMTS_DAT_FEATURE_BY_RAT_ptr;

extern UMTS_CUSTOM_DAT_FE_DATABASE_T       *UMTS_DAT_FE_DATABASE_PCORE_ptr;
extern UMTS_CUSTOM_DAT_FE_ROUTE_DATABASE_T *UMTS_DAT_FE_ROUTE_DATABASE_PCORE_ptr;
extern UMTS_CUSTOM_DAT_FEATURE_BY_RAT_T    *UMTS_DAT_FEATURE_BY_RAT_PCORE_ptr;
#endif

#if IS_3G_ELNA_SUPPORT
extern void ul1d_update_elna_from_custom(void);
#endif

#endif /* End of #ifndef UL1D_RF_PUBLIC_H */

