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
 * mml1_rf_pcore_custom_data.c
 *
 * Project:
 * --------
 * MT6290
 *
 * Description:
 * ------------
 * MML1 RF Custom Data
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

/*===============================================================================*/

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "mml1_rf_global.h"
#include "mml1_custom_rf.h"

#include "mml1_rf_pcore_custom_data.h"
#if defined(__MTK_TARGET__)
#include "mml1_custom_drdi.h"
#endif

const sMML1_RF_CUSTOM_INPUT_DATA MML1_RF_CUSTOM_INPUT_DATA =
{
   0x12345678,                                                            // the special pattern of start position
   1,                                                                     // Struct Version ID
   MMRF_TYPE,                                                             // MMRF Type
   1,                                                                     // default is false, and will be changed  as true after tool update
   {
      MML1_CLK1_EN_SetDefault,
      MML1_CLK2_EN_SetDefault,
      MML1_CLK3_EN_SetDefault,
      MML1_CLK4_EN_SetDefault
   },
   {
      MML1_CLK1_DRIVING_SetDefault,
      MML1_CLK2_DRIVING_SetDefault,
      MML1_CLK3_DRIVING_SetDefault,
      MML1_CLK4_DRIVING_SetDefault
   },
   {
      {  PRX1_IQ_SWAP_EN_SetDefault, PRX2_IQ_SWAP_EN_SetDefault  },
      {  DRX1_IQ_SWAP_EN_SetDefault, DRX2_IQ_SWAP_EN_SetDefault  },
   },
   {
      {  PRX1_I_INV_EN_SetDefault, PRX2_I_INV_EN_SetDefault  },
      {  PRX1_Q_INV_EN_SetDefault, PRX2_Q_INV_EN_SetDefault  },
      {  DRX1_I_INV_EN_SetDefault, DRX2_I_INV_EN_SetDefault  },
      {  DRX1_Q_INV_EN_SetDefault, DRX2_Q_INV_EN_SetDefault  },
   },
   0x87654321,                                                            //the special pattern of end2 position
};

#if defined(__ABB_TXDAC_CAL_ONLY_IN_FIRST_BOOT__)
const MMRF_AbbTxDacCal_T MMRF_ABB_TXDAC_CAL_DATA =
{
   KAL_FALSE,
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
#endif

const MML1_CRYSTAL_T MML1_CRYSTAL_CTRL =
{
   FIXAFC_EN,
   VCXO_TYPE,
   MML1_CRYSTAL_ON_PMIC_EN,
};

#if defined(__MTK_TARGET__)
kal_bool   mml1_custom_drdiEnable         = IS_MML1_DRDI_ENABLE;
kal_uint16 mml1_custom_total_set_nums     = MML1_CUSTOM_TOTAL_SET_NUMS;
kal_uint16 mml1_custom_mmrf_real_set_nums = MML1_DRDI_REMAP_MMRF_REAL_SET_NUMS;
kal_uint16 mml1_custom_gge_real_set_nums  = MML1_DRDI_REMAP_GGE_REAL_SET_NUMS;
kal_uint16 mml1_custom_umts_real_set_nums = MML1_DRDI_REMAP_UMTS_REAL_SET_NUMS;
kal_uint16 mml1_custom_tds_real_set_nums  = MML1_DRDI_REMAP_TDS_REAL_SET_NUMS;
kal_uint16 mml1_custom_lte_real_set_nums  = MML1_DRDI_REMAP_LTE_REAL_SET_NUMS;
kal_bool   mml1_custom_incr_vs1_volt_en   = MML1_CUSTOM_INCREASE_VS1_VOLT_EN;
#else
kal_bool   mml1_custom_drdiEnable         = (0);
kal_uint16 mml1_custom_total_set_nums     = (0);
kal_uint16 mml1_custom_mmrf_real_set_nums = (0);
kal_uint16 mml1_custom_gge_real_set_nums  = (0);
kal_uint16 mml1_custom_umts_real_set_nums = (0);
kal_uint16 mml1_custom_tds_real_set_nums  = (0);
kal_uint16 mml1_custom_lte_real_set_nums  = (0);
kal_bool   mml1_custom_incr_vs1_volt_en   = (0);
#endif

#if defined(__SAR_TX_POWER_BACKOFF_SUPPORT__)
MML1_SENSOR_INFO_T mml1_sar_sensor_info_localparam[MAX_SAR_SENSOR_NUM] = {0};
#endif

#if (IS_MML1_CUSTOM_MEMORY_DATA_SUPPORT)
/*===============================================================================*/
/* this function can be modified by customer,they can set the mapping rule whatever they want;*/
kal_uint16 mml_rf_drdi_DynamicMappingSettingForCustom(kal_uint32 result_idx)
{
   kal_uint16 MappingRFSettingValue=0;
   MappingRFSettingValue=MML1_DRDI_CUSTOM_ReMapTable[result_idx];
   return MappingRFSettingValue;
}
#endif
/*===============================================================================*/

