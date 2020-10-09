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
 *   mmrf_cc_global.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   Cross-Core Multi-Mode RF Central Global Define
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _MMRF_CC_GLOBAL_H_
#define  _MMRF_CC_GLOBAL_H_

/*===============================================================================*/

#include "kal_general_types.h"

#if   defined(TK6291)
#define MMRF_TYPE                             0x6291
#elif defined(MT6755)
#define MMRF_TYPE                             0x6755
#elif defined(MT6797)
#define MMRF_TYPE                             0x6797
#else
#define MMRF_TYPE                                  0
#endif

#define MMRF_CA_SUPPORT_NUM                        2

#if defined(__TX_POWER_OFFSET_SUPPORT__)
#define TPO_MML1_TABLE_NUM    2
#elif defined(__SAR_TX_POWER_BACKOFF_SUPPORT__)
#define TPO_MML1_TABLE_NUM    9
#endif

#if defined(__MTK_TARGET__) && !defined(__L1_STANDALONE__)
#define IS_MMRF_MIPI_HW_CHECK_SUPPORT          1
#else
#define IS_MMRF_MIPI_HW_CHECK_SUPPORT          0
#endif

#if defined(__SAR_TX_POWER_BACKOFF_SUPPORT__)
#define MAX_SAR_SENSOR_NUM  16
#endif

typedef enum
{
   MML1_RF_2G      = 0x0001,
   MML1_RF_3G_FDD  = 0x0002,
   MML1_RF_3G_TDD  = 0x0004,
   MML1_RF_LTE     = 0x0008,
   MML1_RF_C2K     = 0x0010,
   MML1_RF_MMRF    = 0x0020,
   /* !!Important: If add new rat type here, please check BITMAP2IDX[] array size!! */
   MML1_RF_RAT_CNT,
}MML1_RF_RAT_T;

typedef enum
{
   MML1_RF_VCXO    = 0x0001,
   MML1_RF_VCTCXO  = 0x0002,
}MML1_RF_VCXO_TYPE_E;

typedef struct
{
   kal_uint16  xCLK1_EN;
   kal_uint16  xCLK2_EN;
   kal_uint16  xCLK3_EN;
   kal_uint16  xCLK4_EN;
}sMML1_RF_CLK_BUF_VARIABLE;

typedef struct
{
   kal_uint16  xCLK1_Driving;
   kal_uint16  xCLK2_Driving;
   kal_uint16  xCLK3_Driving;
   kal_uint16  xCLK4_Driving;
}sMML1_RF_CLK_BUF_DRIVING_VARIABLE;

typedef struct
{
   kal_uint16  xPRX_IQ_Swap_EN[MMRF_CA_SUPPORT_NUM];
   kal_uint16  xDRX_IQ_Swap_EN[MMRF_CA_SUPPORT_NUM];
}sMML1_RF_IQ_SWAP_VARIABLE;

typedef struct
{
   kal_uint16  xPRX_I_Inv_EN[MMRF_CA_SUPPORT_NUM];
   kal_uint16  xPRX_Q_Inv_EN[MMRF_CA_SUPPORT_NUM];
   kal_uint16  xDRX_I_Inv_EN[MMRF_CA_SUPPORT_NUM];
   kal_uint16  xDRX_Q_Inv_EN[MMRF_CA_SUPPORT_NUM];
}sMML1_RF_IQ_INV_VARIABLE;

typedef struct
{
   int start;                      // the special pattern of start position
   int version;                    // Struct Version ID
   int MMRF_Type;                  // MMRF type
   char is_data_update;            // default is false, and will be changed  as true after tool update
   
   sMML1_RF_CLK_BUF_VARIABLE         MML1_RF_CLK_Buf_Variable;
   sMML1_RF_CLK_BUF_DRIVING_VARIABLE MML1_RF_CLK_Buf_Driving_Variable;
   sMML1_RF_IQ_SWAP_VARIABLE         MML1_RF_IQ_Swap_Variable;
   sMML1_RF_IQ_INV_VARIABLE          MML1_RF_IQ_Inv_Variable;
   
   int end;                        // the special pattern of end1 position
}sMML1_RF_CUSTOM_INPUT_DATA;

typedef sMML1_RF_CUSTOM_INPUT_DATA mml1_rf_custom_input_data_T;

typedef struct
{
   kal_int8             fixafc_en;
   MML1_RF_VCXO_TYPE_E  vcxo_type;
   kal_uint8            crystal_on_pmic_en;
}MML1_CRYSTAL_T;

typedef struct
{
   kal_uint32     c0;
   kal_uint32     c1;
   kal_uint32     c2;
   kal_uint32     c3; 
}MML1_CO_TMS_CONFIG_T;

typedef struct
{
   float     float_c0;
   float     float_c1;
   float     float_c2;
   float     float_c3; 
}MML1_CO_TMS_CONFIG_FLOAT_T;

typedef enum
{
   MMRF_TX_POWER_RECORD_2G      = 0,
   MMRF_TX_POWER_RECORD_3G_FDD  = 1,
   MMRF_TX_POWER_RECORD_3G_TDD  = 2,
   MMRF_TX_POWER_RECORD_4G      = 3,
   MMRF_TX_POWER_RECORD_RAT_NUM
}MMRF_TxPowerRecord_RAT_T;

typedef struct
{
   kal_uint16           AfcDac;
   kal_int32            SlopeInv;
}MMRF_RfAfcParam_T;

typedef struct
{
   kal_uint16           CombinedIndex;
   kal_bool             DrdiEnable;
   kal_uint32           TotalSetNum;
}MMRF_DrdiParam_T;

typedef struct
{
   kal_bool             IncreaseVS1VoltEn;
}MMRF_Vs1Param_T;

#if defined(__ABB_TXDAC_CAL_ONLY_IN_FIRST_BOOT__)
typedef struct
{
   kal_bool             AbbTxDacCalFlag;
   kal_uint32           AbbTxDacCalVal_I[16];
   kal_uint32           AbbTxDacCalVal_Q[16];
}MMRF_AbbTxDacCal_T;
#endif

typedef struct
{
   MMRF_RfAfcParam_T    afcParam;
   MMRF_DrdiParam_T     drdiParam;
   MMRF_Vs1Param_T      Vs1Param;
#if defined(__ABB_TXDAC_CAL_ONLY_IN_FIRST_BOOT__)
   MMRF_AbbTxDacCal_T   AbbTxDacCalParam;
#endif
}MMRF_CcRfParamNotInNvram_T;

typedef enum
{
   MMRF_BSI_RF_IMM_W       = 0,
   MMRF_BSI_RF_IMM_R       = 1,
   MMRF_BSI_RF_IMM_R_RDY   = 2,
   MMRF_BSI_MIPI_IMM_W     = 3,
   MMRF_BSI_MIPI_IMM_R     = 4,
   MMRF_BSI_MIPI_IMM_R_RDY = 5,
}MMRF_WHILE_LOOP_STATE_E;

#if defined(__TX_POWER_OFFSET_SUPPORT__) || defined(__SAR_TX_POWER_BACKOFF_SUPPORT__)
typedef struct
{
   kal_uint16 GSM_tableIdx;
   kal_uint16 WCDMA_tableIdx;
   kal_uint16 TDSCDMA_tableIdx;
   kal_uint16 LTE_tableIdx;
   kal_uint16 C2K_tableIdx;
}MML1_RF_MANUAL_MOD_TABLE_T;

typedef struct
{
   kal_bool                     manual_mod_enable;
   MML1_RF_MANUAL_MOD_TABLE_T   manual_mod_tableidx;
   kal_bool                     TPO_enable;
   kal_bool                     TPO_table_swap;
}MML1_RF_TX_PWR_OFFSET_T;
#endif

   #if defined(__SAR_TX_POWER_BACKOFF_SUPPORT__)
typedef enum
{
   MML1_RF_GRIP_SENSOR            = 0x0001,
   MML1_RF_PROXIMITY              = 0x0002,
   MML1_RF_WIFI_HOTSPOT           = 0x0004,
   MML1_RF_FLAT_MOTION            = 0x0008,
   MML1_RF_REVERSED_FLAT_MOTION   = 0x0010,
   MML1_RF_2_TOUCH_KEY            = 0x0020,
   MML1_RF_ACCELERATION_FLAT_FLAT = 0x0040,
   MML1_RF_VERTICAL_MOTION        = 0x0080,
   MML1_RF_VT_OVERHEAT            = 0x0100,
   MML1_RF_EARJACK                = 0x0200,
   MML1_RF_TA                     = 0x0400,
   MML1_RF_USB_OTG                = 0x0800,
   MML1_RF_COVER                  = 0x1000,
   MML1_RF_SUB_GRIP_SENSOR        = 0x2000,
   MML1_RF_COVER_TYPE_2           = 0x4000,
   MML1_RF_SAR_NOT_SUPPORT        = 0X8000,
   MML1_RF_END_PATTERN            = 0xFFFF,
}MML1_SAR_DEVICE_TYPE_E;

typedef struct
{
   MML1_SAR_DEVICE_TYPE_E id;
}MML1_SENSOR_INFO_T;
   #endif

#endif /* End of #ifndef _MMRF_CC_GLOBAL_H_ */

