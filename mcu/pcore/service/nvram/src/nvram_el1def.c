/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * nvram_el1def.c
 *
 * Project:
 * --------
 *   MT7206RF
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *
 *
 *******************************************************************************/
/*===============================================================================================*/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "nvram_data_items.h"

#if defined(__LTE_RAT__)
#include "el1d_rf_custom_data.h"
#include "el1d_rf_drdi.h"
#include "el1d_rf_cid.h"

#if IS_MIPI_ANT_TUNER_SUPPORT
#include "el1_custom_nvram_def.h"
#endif
/*static*/ kal_uint8 lte_band_to_bandInd_mapping(nvram_lid_core_enum lid)
{
   kal_uint8 i = 0xDE;
   LTE_Band eband;

   if((lid >= NVRAM_EF_EL1_TXDAC_START) && (lid <= NVRAM_EF_EL1_TXDAC_END))
   {
      eband = lteBandIndArray[lid - NVRAM_EF_EL1_TXDAC_START];
      for(i = 0; i < LTE_TARGET_MAX_SUPPORT_BAND_NUM; i++)
      {
         if (LTE_RampData_SetDefault[i] != NULL)
         {
            if(LTE_RampData_SetDefault[i]->band_ind == eband)
            {
               break;
            }
         }
      }
   }
   else if((lid >= NVRAM_EF_EL1_TXPAOCTLEV_START) && (lid <= NVRAM_EF_EL1_TXPAOCTLEV_END))
   {
      eband = lteBandIndArray[lid - NVRAM_EF_EL1_TXPAOCTLEV_START];
      for(i = 0; i < LTE_TARGET_MAX_SUPPORT_BAND_NUM; i++)
      {
         if (LTE_PaOctLevTable_SetDefault[i] != NULL)
         {
            if(LTE_PaOctLevTable_SetDefault[i]->band_ind == eband)
            {
               break;
            }
         }
      }
   }
   else if((lid >= NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_START) && (lid <= NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_SINGLE_BAND_END))
   {
      eband = lteBandIndArray[lid - NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_START];
      for(i = 0; i < LTE_TARGET_MAX_SUPPORT_BAND_NUM; i++)
      {
         if (LTE_RSSIGainTblType1_SetDefault[i] != NULL)
         {
            if(LTE_RSSIGainTblType1_SetDefault[i]->bandIndex == eband)
            {
               break;
            }
         }
      }
   }
   else if((lid >= NVRAM_EF_EL1_PWRONCAL_START) && (lid <= NVRAM_EF_EL1_PWRONCAL_END))
   {
      eband = lteBandIndArray[lid - NVRAM_EF_EL1_PWRONCAL_START];
      for(i = 0; i < LTE_TARGET_MAX_SUPPORT_BAND_NUM; i++)
      {
         if (LTE_PWRON_CAL_DATA_PTR[i] != NULL)
         {
            if(LTE_PWRON_CAL_DATA_PTR[i]->band == eband)
            {
               break;
            }
         }
      }
   }
#if IS_4G_TX_POWER_OFFSET_SUPPORT || IS_4G_SAR_TX_POWER_OFFSET_SUPPORT
   else if((lid >= NVRAM_EF_EL1_TX_POWER_OFFSET_START) && (lid <= NVRAM_EF_EL1_TX_POWER_OFFSET_END))
   {
      eband = lteBandIndArray[lid - NVRAM_EF_EL1_TX_POWER_OFFSET_START];
      for(i = 0; i < LTE_TARGET_MAX_SUPPORT_BAND_NUM; i++)
      {
         if(LTE_TX_POWER_OFFSET_TABLE[i] != NULL)
         {
            if(LTE_TX_POWER_OFFSET_TABLE[i]->band_ind == eband)
            {
               break;
            }
         }
      }
   }
#endif
   else
   {
      /* Input LID out of range */
      ASSERT(0);
   }

   /* To trap that no calibration data default value defined for the band in question */
   ASSERT(i < LTE_TARGET_MAX_SUPPORT_BAND_NUM);

   return i;
}

void nvram_get_eL1_default_value_to_write(nvram_lid_core_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size)
{
   kal_uint8 index_select;

   /** DRDI */
   EL1D_RF_CUSTOM_DynamicInit();
   EL1D_RF_CUSTOM_DynamicInitMipi();

   EL1D_RF_UpdateDatabaseTable();

   switch (lid)
   {
      /** EL1 RF Calibration */
      case NVRAM_EF_EL1_FREQADJTBL_LID:
      {
         kal_mem_cpy(buffer, LTE_FreqAdjustTbl[0], sizeof(LTE_FreqAdjustTable));
      }
      break;

      /** EL1D RF RX RSSI Table */
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_0THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_1STBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_2NDBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_3RDBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_4THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_5THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_6THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_7THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_8THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_9THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_10THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_11THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_12THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_13THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_14THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_15THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_16THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_17THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_18THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_19THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_20THBAND_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_21THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_22THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_23THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_24THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_25THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_26THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_27THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_28THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_29THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_30THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_31THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_32THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_33THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_34THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_35THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_36THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_37THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_38THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_39THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_40THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_41THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_42THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_43THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_44THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_45THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_46THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_47THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_48THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_49THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_50THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_51THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_52THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_53THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_54THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_55THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_56THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_57THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_58THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_59THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_60THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_61THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_62THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_63THROUTE_LID :
      {
         index_select = lid-NVRAM_EF_EL1_RSSIGAINTBL_TYPE1_START;
         if (LTE_RSSIGainTblType1_SetDefault[index_select] != 0)
         {
            kal_mem_cpy(buffer, LTE_RSSIGainTblType1_SetDefault[index_select], sizeof(LTE_RX_PL_ROUTE_TYPE1_T));
         }
      }
      break;

      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE2_96THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE2_97THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE2_98THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE2_99THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE2_100THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE2_101THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE2_102THROUTE_LID :
      case NVRAM_EF_EL1_RSSIGAINTBL_TYPE2_103THROUTE_LID :
      {
         index_select = lid-NVRAM_EF_EL1_RSSIGAINTBL_TYPE2_START;
         if (LTE_RSSIGainTblType2_SetDefault[index_select] != 0)
         {
            kal_mem_cpy(buffer, LTE_RSSIGainTblType2_SetDefault[index_select], sizeof(LTE_RX_PL_ROUTE_TYPE2_T));
         }
      }
      break;

      /** EL1D RF Tx DAC */
      case NVRAM_EF_EL1_TXDAC_0THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_1STBAND_LID:
      case NVRAM_EF_EL1_TXDAC_2NDBAND_LID:
      case NVRAM_EF_EL1_TXDAC_3RDBAND_LID:
      case NVRAM_EF_EL1_TXDAC_4THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_5THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_6THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_7THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_8THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_9THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_10THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_11THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_12THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_13THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_14THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_15THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_16THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_17THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_18THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_19THBAND_LID:
      case NVRAM_EF_EL1_TXDAC_20THBAND_LID:
      {
         index_select = lte_band_to_bandInd_mapping(lid);
         if (LTE_RampData_SetDefault[index_select] != 0)
         {
            kal_mem_cpy(buffer, LTE_RampData_SetDefault[index_select], sizeof(LTE_sRAMPDATA));
         }
      }
      break;

      /** EL1D RF Tx PA OCT level */
      case NVRAM_EF_EL1_TXPAOCTLEV_0THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_1STBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_2NDBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_3RDBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_4THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_5THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_6THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_7THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_8THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_9THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_10THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_11THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_12THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_13THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_14THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_15THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_16THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_17THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_18THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_19THBAND_LID:
      case NVRAM_EF_EL1_TXPAOCTLEV_20THBAND_LID:
      {
         index_select = lte_band_to_bandInd_mapping(lid);
         if (LTE_PaOctLevTable_SetDefault[index_select] != 0)
         {
            kal_mem_cpy(buffer, LTE_PaOctLevTable_SetDefault[index_select], sizeof(LTE_sPAOCTLVLSETTING));
         }
      }
      break;

      /** EL1D RF Tx ET */
      case NVRAM_EF_EL1_ETVINLUTDATA_0THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_1STBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_2NDBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_3RDBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_4THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_5THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_6THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_7THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_8THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_9THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_10THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_11THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_12THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_13THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_14THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_15THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_16THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_17THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_18THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_19THBAND_LID:
      case NVRAM_EF_EL1_ETVINLUTDATA_20THBAND_LID:
      {
		 kal_mem_set( buffer, 0, sizeof(LTE_RfcEtVinLutPerBand_T));
      }
      break;

      /** EL1D RF General Parammeters */
      case NVRAM_EF_EL1_ETCOMPPARAM_LID:
      {
         kal_mem_set( buffer, 0, sizeof(LTE_RfcEtCompParam_T));
      }
      break;

      case NVRAM_EF_EL1_TEMPERATUREDAC_LID:
      {
         kal_mem_cpy(buffer, LTE_TEMP_DAC_SetDefault, sizeof(LTE_TemperatureDac_T));
      }
      break;

      case NVRAM_EF_EL1_MPRADJTBL_LID:
      {
         kal_mem_cpy(buffer, LTE_MPRAdjustTbl, NVRAM_EF_EL1_MPRADJTBL_SIZE);
      }
      break;

#if IS_MPR_64QAM_SUPPORT
      case NVRAM_EF_EL1_MPRADJTBL_64QAM_LID:
      {
         kal_mem_cpy(buffer, LTE_MPRAdjustTbl_64QAM, NVRAM_EF_EL1_MPRADJTBL_64QAM_SIZE);
      }
      break;
#endif  // End of IS_MPR_64QAM_SUPPORT

      case NVRAM_EF_EL1_AMPRADJTBL_LID:
      {
         kal_mem_cpy(buffer, LTE_AMPRAdjustTbl, NVRAM_EF_EL1_AMPRADJTBL_SIZE);
      }
      break;

      /** EL1D RF Customization data */
      case NVRAM_EF_EL1_BAND_INDICATOR_LID:
      {
         kal_mem_cpy(buffer, lteBandIndArray, NVRAM_EF_EL1_BAND_INDICATOR_SIZE);
      }
      break;

      case NVRAM_EF_EL1_CA_BAND_INDICATOR_LID:
      {
         kal_mem_cpy(buffer, LTE_CA_CFG_IND, NVRAM_EF_EL1_CA_BAND_INDICATOR_SIZE);
      }
      break;

      case NVRAM_EF_EL1_RX_PDATABASE_LID:
      {
         kal_mem_cpy(buffer, ERF_RX_PDATABASE, NVRAM_EF_EL1_RX_PDATABASE_SIZE);
      }
      break;

      case NVRAM_EF_EL1_TX_PDATABASE_LID:
      {
         kal_mem_cpy(buffer, ERF_TX_PDATABASE, NVRAM_EF_EL1_TX_PDATABASE_SIZE);
      }
      break;

      case NVRAM_EF_EL1_RF_RXIO_LID:
      {
         kal_mem_cpy(buffer, ERF_RF_RXIOBASE, NVRAM_EF_EL1_RF_RXIO_SIZE);
      }
      break;

      case NVRAM_EF_EL1_RF_TXIO_LID:
      {
         kal_mem_cpy(buffer, ERF_RF_TXIOBASE, NVRAM_EF_EL1_RF_TXIO_SIZE);
      }
      break;

      case NVRAM_EF_EL1_RF_FRONT_END_USAGE_TABLE_LID:
      {
         kal_mem_cpy(buffer, ERF_RF_FRONT_END_USAGE_TBL, NVRAM_EF_EL1_RF_FRONT_END_USAGE_TABLE_SIZE);
      }
      break;

      case NVRAM_EF_EL1_ANT_PDATABASE_LID:
      {
         kal_mem_cpy(buffer, &(LTE_ANT_ROUTE_DATABASE), NVRAM_EF_EL1_ANT_PDATABASE_SIZE);
      }
      break;

      case NVRAM_EF_EL1_VPA_CONFIG_DATABASE_LID:
      {
         kal_mem_cpy(buffer, &(LTE_VPA_SOURCE_CONFIG_DATABASE), NVRAM_EF_EL1_VPA_CONFIG_DATABASE_SIZE);
      }
      break;

      /* RF BPI event offset */
      case NVRAM_EF_EL1_RXON_BPIOFFSET_LID:
      {
         kal_mem_cpy(buffer, &(ERF_EVT_TIME_OFST_TABLE.lteBpiOfstRxOn), NVRAM_EF_EL1_RXON_BPIOFFSET_SIZE);
      }
      break;

      case NVRAM_EF_EL1_TXON_BPIOFFSET_LID:
      {
         kal_mem_cpy(buffer, &(ERF_EVT_TIME_OFST_TABLE.lteBpiOfstTxOn), NVRAM_EF_EL1_TXON_BPIOFFSET_SIZE);
      }
      break;

      case NVRAM_EF_EL1_RXOFF_BPIOFFSET_LID:
      {
         kal_mem_cpy(buffer, &(ERF_EVT_TIME_OFST_TABLE.lteBpiOfstRxOff), NVRAM_EF_EL1_RXOFF_BPIOFFSET_SIZE);
      }
      break;

      case NVRAM_EF_EL1_TXOFF_BPIOFFSET_LID:
      {
         kal_mem_cpy(buffer, &(ERF_EVT_TIME_OFST_TABLE.lteBpiOfstTxOff), NVRAM_EF_EL1_TXOFF_BPIOFFSET_SIZE);
      }
      break;

      //#if defined(__TAS_SUPPORT__)
      case NVRAM_EF_EL1_TAS_PARAMETER_LID:
      {
         kal_mem_cpy(buffer, &(ERF_TAS_PARAMETER), NVRAM_EF_EL1_TAS_PARAMETER_SIZE);
      }
      break;

         #if defined(__TAS_INTERNAL_NVRAM_VISIBLE__)
      case NVRAM_EF_EL1_TAS_OTHER_LID:
      {
         kal_mem_cpy(buffer, &(ERF_TAS_OTHER_PARAMETER), NVRAM_EF_EL1_TAS_OTHER_SIZE);
      }
      break;
         #endif

         #if defined (__TAS_ANTENNA_IDX_ON_TEST_SIM__)
      case NVRAM_EF_EL1_TAS_INIT_IND_LID:
      {
         kal_mem_cpy(buffer, ERF_TAS_INIT_IND, NVRAM_EF_EL1_TAS_INIT_IND_SIZE);
      }
      break;
         #endif
      //#endif
         #if IS_4G_HPUE_FEATURE_SUPPORT
     case NVRAM_EF_EL1_AMPR_NS04_HPUE_LID:
     {
        kal_mem_cpy(buffer, &(ERF_AMPR_NS04_HPUE_PARAMETER), NVRAM_EF_EL1_AMPR_NS04_HPUE_SIZE);
     }
     break;
         #endif
      /* DAT Feature */
         #if defined(__DYNAMIC_ANTENNA_TUNING__)
      case NVRAM_EF_EL1_DAT_FEATURE_ENABLE_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_DAT_FEATURE_ENABLE_SIZE);
         kal_mem_cpy(buffer, &(LTE_DAT_FEATURE_ENABLE), NVRAM_EF_EL1_DAT_FEATURE_ENABLE_SIZE);
      }
      break;

      case NVRAM_EF_EL1_DAT_ROUTE_DATABASE_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_DAT_ROUTE_DATABASE_SIZE);
         kal_mem_cpy(buffer, &(LTE_DAT_FE_ROUTE_DATABASE_SetDefault), NVRAM_EF_EL1_DAT_ROUTE_DATABASE_SIZE);
      }
      break;

      case NVRAM_EF_EL1_DAT_LINKAGE_DATABASE_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_DAT_LINKAGE_DATABASE_SIZE);
         kal_mem_cpy(buffer, &(LTE_DAT_CA_LINKAGE_DATABASE_SetDefault), NVRAM_EF_EL1_DAT_LINKAGE_DATABASE_SIZE);
      }
      break;
         #endif

      /* Dynamic Radio-setting Dedicated Image (DRDI) */
      case NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_DEBUG_LID:
      {
         kal_mem_cpy(buffer, &LTE_DRDI_DEBUG_INFO, NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_DEBUG_SIZE);
      }
      break;

      /* Single ANT Feature */
      case NVRAM_EF_EL1_RF_RX_PATH_CONFIG_LID:
      {
         kal_mem_cpy(buffer, &LTE_RF_RX_PATH_CONFIG_DEFAULT, NVRAM_EF_EL1_RF_RX_PATH_CONFIG_SIZE);
      }
      break;
      
      /*Single ANT Feature for SCC*/
      case NVRAM_EF_EL1_RF_RX_PATH_S_CONFIG_LID:
      {
         kal_mem_cpy(buffer, &LTE_RF_RX_PATH_CONFIG_SCC_DEFAULT, NVRAM_EF_EL1_RF_RX_PATH_S_CONFIG_SIZE);
      }
      break;

      /* AMPR Special handle case Feature */
      case NVRAM_EF_EL1_AMPR_VZW_FEATURE_LID:
      {
         kal_mem_cpy(buffer, &LTE_AMPR_VZW_SUPPORT, NVRAM_EF_EL1_AMPR_VZW_FEATURE_SIZE);
      }
      break;

      /* MIPI Feature */
      case NVRAM_EF_EL1_MIPI_FEATURE_LID:
      {
         kal_mem_cpy(buffer, &LTE_MIPI_ENABLE, NVRAM_EF_EL1_MIPI_FEATURE_SIZE);
      }
      break;

      case NVRAM_EF_EL1_MIPI_RX_EVENT_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_4THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_5THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_6THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_7THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_8THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_9THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_10THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_11THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_12THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_13THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_14THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_15THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_16THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_17THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_18THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_19THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_EVENT_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE);
            kal_mem_cpy(buffer,
            LTE_MIPI_RX_EVENT_TABLE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_RX_EVENT_START)],
            LTE_MIPI_RX_EVENT_SIZE_TABLE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_RX_EVENT_START)]);
         }
      }
      break;

      case NVRAM_EF_EL1_MIPI_TX_EVENT_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_4THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_5THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_6THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_7THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_8THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_9THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_10THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_11THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_12THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_13THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_14THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_15THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_16THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_17THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_18THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_19THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_EVENT_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE);
            kal_mem_cpy(buffer,
            LTE_MIPI_TX_EVENT_TABLE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_TX_EVENT_START)],
            LTE_MIPI_TX_EVENT_SIZE_TABLE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_TX_EVENT_START)]);
         }
      }
      break;

      case NVRAM_EF_EL1_MIPI_TPC_EVENT_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_4THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_5THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_6THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_7THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_8THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_9THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_10THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_11THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_12THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_13THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_14THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_15THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_16THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_17THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_18THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_19THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TPC_EVENT_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE);
            kal_mem_cpy(buffer,
            LTE_MIPI_TPC_EVENT_TABLE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_TPC_EVENT_START)],
            LTE_MIPI_TPC_EVENT_SIZE_TABLE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_TPC_EVENT_START)]);
         }
      }
      break;

      case NVRAM_EF_EL1_MIPI_RX_DATA_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_4THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_5THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_6THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_7THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_8THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_9THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_10THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_11THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_12THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_13THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_14THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_15THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_16THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_17THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_18THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_19THBAND_LID:
      case NVRAM_EF_EL1_MIPI_RX_DATA_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_RX_DATA_SIZE);
            kal_mem_cpy(buffer,
            LTE_MIPI_RX_DATA_TABLE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_RX_DATA_START)],
            LTE_MIPI_RX_DATA_SIZE_TABLE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_RX_DATA_START)]);
         }
      }
      break;

      case NVRAM_EF_EL1_MIPI_TX_DATA_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_4THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_5THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_6THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_7THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_8THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_9THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_10THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_11THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_12THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_13THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_14THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_15THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_16THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_17THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_18THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_19THBAND_LID:
      case NVRAM_EF_EL1_MIPI_TX_DATA_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_TX_DATA_SIZE);
            kal_mem_cpy(buffer,
            LTE_MIPI_TX_DATA_TABLE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_TX_DATA_START)],
            LTE_MIPI_TX_DATA_SIZE_TABLE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_TX_DATA_START)]);
         }
      }
      break;

      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_4THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_5THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_6THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_7THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_8THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_9THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_10THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_11THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_12THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_13THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_14THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_15THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_16THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_17THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_18THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_19THBAND_LID:
      case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE);
            kal_mem_cpy(buffer,
            LTE_MIPI_PA_TPC_SECTION_DATA_SetDefault[(lid-NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_START)],
            LTE_MIPI_PA_TPC_SECTION_DATA_SIZE_SetDefault[(lid-NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_START)]);
         }
      }
      break;

      /*** MIPI BYPASS Feature ***/
      case NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_SIZE);
         kal_mem_cpy(buffer,
         LTE_MIPI_BYPASS_TX_DATA_TABLE_SetDefault[lid-NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_START],
         LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE_SetDefault[lid-NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_START]);
      }
      break;

      case NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_SIZE);
         kal_mem_cpy(buffer,
         LTE_MIPI_BYPASS_TX_EVENT_TABLE_SetDefault[lid-NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_START],
         LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE_SetDefault[lid-NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_START]);
      }
      break;

      case NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_SIZE);
         kal_mem_cpy(buffer,
         LTE_MIPI_BYPASS_TPC_EVENT_TABLE_SetDefault[lid-NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_START],
         LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE_SetDefault[lid-NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_START]);
      }
      break;

      case NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_4THBAND_LID:
      {
          kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE);
          kal_mem_cpy(buffer,
          LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SetDefault[lid-NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_START],
          LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE_SetDefault[lid-NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_START]);
      }
      break;

      /** POWER CAL Related NVRAM Lid */        
      case NVRAM_EF_EL1_PWRONCAL_0THBAND_LID: 
      case NVRAM_EF_EL1_PWRONCAL_1STBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_2NDBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_3RDBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_4THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_5THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_6THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_7THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_8THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_9THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_10THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_11THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_12THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_13THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_14THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_15THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_16THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_17THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_18THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_19THBAND_LID:
      case NVRAM_EF_EL1_PWRONCAL_20THBAND_LID:
      {
         index_select = lte_band_to_bandInd_mapping(lid);         
         if(LTE_PWRON_CAL_DATA_PTR[index_select] != 0)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_PWRONCAL_SIZE);
            kal_mem_cpy(buffer,
                        LTE_PWRON_CAL_DATA_PTR[index_select],
                        NVRAM_EF_EL1_PWRONCAL_SIZE
                        );
         }
         
      }
      break;

      case NVRAM_EF_EL1_PWRONCAL_LTE_B40_TX_SUBBAND_LID:
      {

         kal_mem_set(buffer, 0, NVRAM_EF_EL1_PWRONCAL_TX_SUBBAND_SIZE);
         kal_mem_cpy(buffer,
                     &LTE_Band40_PWRON_CAL_TX_2ND_3RD_SUBBAND_DATA,
                     NVRAM_EF_EL1_PWRONCAL_TX_SUBBAND_SIZE
                     );
         
      }
      break;

      case NVRAM_EF_EL1_PWRONCAL_LTE_B41_TX_SUBBAND_LID:
      {

         kal_mem_set(buffer, 0, NVRAM_EF_EL1_PWRONCAL_TX_SUBBAND_SIZE);
         kal_mem_cpy(buffer,
                     &LTE_Band41_PWRON_CAL_TX_2ND_3RD_SUBBAND_DATA,
                     NVRAM_EF_EL1_PWRONCAL_TX_SUBBAND_SIZE
                     );
         
      }
      break;
      
      /** POWER CAL Related NVRAM Lid */        
      case NVRAM_EF_EL1_2ND_PWRONCAL_0THBAND_LID: 
      case NVRAM_EF_EL1_2ND_PWRONCAL_1STBAND_LID:
      case NVRAM_EF_EL1_2ND_PWRONCAL_2NDBAND_LID:
      case NVRAM_EF_EL1_2ND_PWRONCAL_3RDBAND_LID:
      case NVRAM_EF_EL1_2ND_PWRONCAL_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_2ND_PWRONCAL_SIZE);
         kal_mem_cpy(buffer, LTE_2ND_PWRON_CAL_DATA_PTR[lid - NVRAM_EF_EL1_2ND_PWRONCAL_START], NVRAM_EF_EL1_2ND_PWRONCAL_SIZE);        
      }
      break;

#if IS_4G_TX_POWER_OFFSET_SUPPORT || IS_4G_SAR_TX_POWER_OFFSET_SUPPORT
      case NVRAM_EF_EL1_TX_POWER_OFFSET_0THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_1STBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_2NDBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_3RDBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_4THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_5THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_6THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_7THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_8THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_9THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_10THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_11THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_12THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_13THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_14THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_15THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_16THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_17THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_18THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_19THBAND_LID:
      case NVRAM_EF_EL1_TX_POWER_OFFSET_20THBAND_LID:
      {
         index_select = lte_band_to_bandInd_mapping(lid);
         if (LTE_TX_POWER_OFFSET_TABLE[index_select] != 0)
         {
            kal_mem_cpy(buffer, LTE_TX_POWER_OFFSET_TABLE[index_select], NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE);
         }
      }
      break;
#endif

      case NVRAM_EF_EL1_TX_POWER_BACKOFF_LID:
      {
         kal_mem_cpy(buffer, ERF_TX_POWER_BACKOFF, sizeof(ERF_TX_POWER_BACKOFF_PARAM_T)*LTE_TARGET_MAX_SUPPORT_BAND_NUM);
      }
      break;

      /*** EL1D RF TX DAC (Ramp) bypass feature ***/
      case NVRAM_EF_EL1_BYPASS_TXDAC_0THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDAC_1STBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDAC_2NDBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDAC_3RDBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDAC_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_BYPASS_TXDAC_BAND_SIZE);
         kal_mem_cpy(buffer, LTE_BYPASS_RampData[lid - NVRAM_EF_EL1_BYPASS_TXDAC_START], NVRAM_EF_EL1_BYPASS_TXDAC_BAND_SIZE);
      }
      break;

      /*** EL1D RF Tx PA OCT level bypass feature ***/
      case NVRAM_EF_EL1_BYPASS_TXPAOCTLEV_0THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXPAOCTLEV_1STBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXPAOCTLEV_2NDBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXPAOCTLEV_3RDBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXPAOCTLEV_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_BYPASS_TXPAOCTLEV_BAND_SIZE);
         kal_mem_cpy(buffer, LTE_BYPASS_PaOctLevTable[lid - NVRAM_EF_EL1_BYPASS_TXPAOCTLEV_START], NVRAM_EF_EL1_BYPASS_TXPAOCTLEV_BAND_SIZE);
      }
      break;

      /* Split Band Feature */
      case NVRAM_EF_EL1_SPLIT_BAND_IND_LID:
      {
         kal_mem_cpy(buffer, &ERF_RF_SPLIT_BAND_IND, NVRAM_EF_EL1_SPLIT_BAND_IND_SIZE);
      }
      break;

      case NVRAM_EF_EL1_SPLIT_RFDATABASE_LID:
      {
         kal_mem_cpy(buffer, &ERF_RF_SPLIT_RFDATABASE, NVRAM_EF_EL1_SPLIT_RFDATABASE_SIZE);
      }
      break;

	  /*Partial Band Feature */
      case NVRAM_EF_EL1_PARTIAL_BAND_IND_LID:
      {
         kal_mem_cpy(buffer, &ERF_RF_PARTIAL_BAND_IND, NVRAM_EF_EL1_PARTIAL_BAND_IND_SIZE);
      }
      break;

      /* Bypass Mode Feature */
      case NVRAM_EF_EL1_BYPASS_BAND_IND_LID:
      {
         kal_mem_cpy(buffer, &ERF_RF_BYPASS_BAND_IND, NVRAM_EF_EL1_BYPASS_BAND_IND_SIZE);
      }
      break;

      case NVRAM_EF_EL1_BYPASS_RFDATABASE_LID:
      {
         kal_mem_cpy(buffer, &ERF_RF_BYPASS_RFDATABASE, NVRAM_EF_EL1_BYPASS_RFDATABASE_SIZE);
      }
      break;

      /* HRM Mode Feature */
      case NVRAM_EF_EL1_TX_HRM_BAND_IND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_TX_HRM_BAND_IND_SIZE);
         kal_mem_cpy(buffer, LTE_TX_HRM_BANDIND_ARRAY, NVRAM_EF_EL1_TX_HRM_BAND_IND_SIZE);
      }
      break;

      case NVRAM_EF_EL1_TX_HRM_TXDAC_0THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDAC_1STBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDAC_2NDBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDAC_3RDBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDAC_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_TX_HRM_TXDAC_BAND_SIZE);
         kal_mem_cpy(buffer, LTE_TX_HRM_RampData[lid - NVRAM_EF_EL1_TX_HRM_TXDAC_START], NVRAM_EF_EL1_TX_HRM_TXDAC_BAND_SIZE);
      }
      break;

      case NVRAM_EF_EL1_TX_HRM_TXPAOCTLEV_0THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXPAOCTLEV_1STBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXPAOCTLEV_2NDBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXPAOCTLEV_3RDBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXPAOCTLEV_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_TX_HRM_TXPAOCTLEV_BAND_SIZE);
         kal_mem_cpy(buffer, LTE_TX_HRM_PaOctLevTable[lid - NVRAM_EF_EL1_TX_HRM_TXPAOCTLEV_START], NVRAM_EF_EL1_TX_HRM_TXPAOCTLEV_BAND_SIZE);
      }
      break;

      #if (IS_4G_DPD_SUPPORT || IS_4G_CIM3_SUPPORT)
      //DPD Feature
      case NVRAM_EF_EL1_DPD_FEATURE_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FEATURE_SIZE);
      }
      break;

      /** EL1D RF Tx DPD DAC */
      case NVRAM_EF_EL1_TXDPDDAC_0THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_1STBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_2NDBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_3RDBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_4THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_5THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_6THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_7THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_8THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_9THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_10THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_11THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_12THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_13THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_14THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_15THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_16THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_17THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_18THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_19THBAND_LID:
      case NVRAM_EF_EL1_TXDPDDAC_20THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_TXDPDDAC_BAND_SIZE);
         kal_mem_cpy(buffer, LTE_DPD_RampData_SetDefault[lid - NVRAM_EF_EL1_TXDPDDAC_START], NVRAM_EF_EL1_TXDPDDAC_BAND_SIZE);
      }
      break;

      /** EL1D RF Tx DPD PA OCT level */
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_0THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_1STBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_2NDBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_3RDBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_4THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_5THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_6THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_7THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_8THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_9THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_10THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_11THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_12THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_13THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_14THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_15THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_16THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_17THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_18THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_19THBAND_LID:
      case NVRAM_EF_EL1_TXDPDPAOCTLEV_20THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_TXDPDPAOCTLEV_BAND_SIZE);
         kal_mem_cpy(buffer, LTE_DPD_PaOctLevTable_SetDefault[lid - NVRAM_EF_EL1_TXDPDPAOCTLEV_START], NVRAM_EF_EL1_TXDPDPAOCTLEV_BAND_SIZE);
      }
      break;
	  
      case NVRAM_EF_EL1_DPD_TPC_EVENT_0THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_1STBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_2NDBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_3RDBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_4THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_5THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_6THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_7THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_8THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_9THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_10THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_11THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_12THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_13THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_14THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_15THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_16THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_17THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_18THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_19THBAND_LID:
      case NVRAM_EF_EL1_DPD_TPC_EVENT_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_TPC_EVENT_SIZE);
            kal_mem_cpy(buffer,
            LTE_MIPI_DPD_TPC_EVENT_TABLE_SetDefault[(lid-NVRAM_EF_EL1_DPD_TPC_EVENT_START)],
            LTE_MIPI_DPD_TPC_EVENT_SIZE_TABLE_SetDefault[(lid-NVRAM_EF_EL1_DPD_TPC_EVENT_START)]);
         }
      }
      break;

      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_0THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_1STBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_2NDBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_3RDBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_4THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_5THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_6THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_7THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_8THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_9THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_10THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_11THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_12THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_13THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_14THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_15THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_16THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_17THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_18THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_19THBAND_LID:
      case NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_SIZE);
            kal_mem_cpy(buffer,
            LTE_MIPI_DPD_PA_TPC_SECTION_DATA_SetDefault[(lid-NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_START)],
            LTE_MIPI_DPD_PA_TPC_SECTION_DATA_SIZE_SetDefault[(lid-NVRAM_EF_EL1_DPD_PA_TPC_SECTION_DATA_START)]);
         }
      }
      break;

      case NVRAM_EF_EL1_BYPASS_TXDPDDAC_0THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDPDDAC_1STBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDPDDAC_2NDBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDPDDAC_3RDBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDPDDAC_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_TXDPDDAC_BAND_SIZE);
         kal_mem_cpy(buffer, LTE_BYPASS_DPD_RampData_SetDefault[lid - NVRAM_EF_EL1_BYPASS_TXDPDDAC_START], NVRAM_EF_EL1_TXDPDDAC_BAND_SIZE);
      }
      break;

      /*** EL1D RF Tx PA OCT level bypass feature ***/
      case NVRAM_EF_EL1_BYPASS_TXDPDPAOCTLEV_0THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDPDPAOCTLEV_1STBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDPDPAOCTLEV_2NDBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDPDPAOCTLEV_3RDBAND_LID:
      case NVRAM_EF_EL1_BYPASS_TXDPDPAOCTLEV_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_TXDPDPAOCTLEV_BAND_SIZE);
         kal_mem_cpy(buffer, LTE_BYPASS_DPD_PaOctLevTable_SetDefault[lid - NVRAM_EF_EL1_BYPASS_TXDPDPAOCTLEV_START], NVRAM_EF_EL1_TXDPDPAOCTLEV_BAND_SIZE);
      }
      break;
      
      case NVRAM_EF_EL1_DPD_BYPASS_TPC_EVENT_0THBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_TPC_EVENT_1STBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_TPC_EVENT_2NDBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_TPC_EVENT_3RDBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_TPC_EVENT_4THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_BYPASS_TPC_EVENT_SIZE);
            kal_mem_cpy(buffer,
            LTE_MIPI_DPD_BYPASS_TPC_EVENT_TABLE_SetDefault[lid-NVRAM_EF_EL1_DPD_BYPASS_TPC_EVENT_START],
            LTE_MIPI_DPD_BYPASS_TPC_EVENT_SIZE_TABLE_SetDefault[lid-NVRAM_EF_EL1_DPD_BYPASS_TPC_EVENT_START]);
         }
      }
      break;

      case NVRAM_EF_EL1_DPD_BYPASS_PA_TPC_SECTION_DATA_0THBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_PA_TPC_SECTION_DATA_1STBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_PA_TPC_SECTION_DATA_2NDBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_PA_TPC_SECTION_DATA_3RDBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_PA_TPC_SECTION_DATA_4THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_BYPASS_PA_TPC_SECTION_DATA_SIZE);
            kal_mem_cpy(buffer,
            LTE_MIPI_DPD_BYPASS_PA_TPC_SECTION_DATA_SetDefault[lid-NVRAM_EF_EL1_DPD_BYPASS_PA_TPC_SECTION_DATA_START],
            LTE_MIPI_DPD_BYPASS_PA_TPC_SECTION_DATA_SIZE_SetDefault[lid-NVRAM_EF_EL1_DPD_BYPASS_PA_TPC_SECTION_DATA_START]);
         }
      }
      break;

      case NVRAM_EF_EL1_TX_HRM_TXDPDDAC_0THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDPDDAC_1STBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDPDDAC_2NDBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDPDDAC_3RDBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDPDDAC_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_TX_HRM_TXDPDDAC_BAND_SIZE);
         kal_mem_cpy(buffer, LTE_TX_HRM_DPD_RampData[lid - NVRAM_EF_EL1_TX_HRM_TXDPDDAC_START], NVRAM_EF_EL1_TX_HRM_TXDPDDAC_BAND_SIZE);
      }
      break;

      case NVRAM_EF_EL1_TX_HRM_TXDPDPAOCTLEV_0THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDPDPAOCTLEV_1STBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDPDPAOCTLEV_2NDBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDPDPAOCTLEV_3RDBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_TXDPDPAOCTLEV_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_TX_HRM_TXDPDPAOCTLEV_BAND_SIZE);
         kal_mem_cpy(buffer, LTE_TX_HRM_DPD_PaOctLevTable[lid - NVRAM_EF_EL1_TX_HRM_TXDPDPAOCTLEV_START], NVRAM_EF_EL1_TX_HRM_TXDPDPAOCTLEV_BAND_SIZE);
      }
      break;
      #endif

      #if IS_4G_DPD_SUPPORT

      case NVRAM_EF_EL1_DPD_BAND_INDICATOR_LID:
      {
         kal_mem_cpy(buffer, dpdBandIndArray, NVRAM_EF_EL1_DPD_BAND_INDICATOR_SIZE);
      }
      break;
	  
      /* DPD factory cal common setting and algo parameters */
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_0THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_1THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_2THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_3THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_4THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_5THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_6THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_7THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_8THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_9THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_10THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_11THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_12THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_13THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_14THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_15THBAND_LID:	  	
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_16THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_17THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_18THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_19THBAND_LID:
      case NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_20THBAND_LID:	  	
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_SIZE);
         kal_mem_cpy(buffer, LTE_DPD_FAC_COMMON_ALGO_PARAM_TABLE_SetDefault[(lid-NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_START)], NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_SIZE);                        

      }
      break;

      #if IS_DPD_LUT_SIZE_GAIN_NUM_40
         /* DPD AM LUT */
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_0THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_1THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_2THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_3THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_4THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_5THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_6THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_7THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_8THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_9THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_10THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_11THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_12THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_13THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_14THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_15THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_16THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_17THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_18THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_19THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_20THBAND_GROUP_A_LID:    	
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_0THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_1THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_2THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_3THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_4THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_0THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_1THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_2THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_3THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_4THBAND_GROUP_A_LID:
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_AM_LUT_GROUP_A_SIZE);
         }
         break;
         
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_0THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_1THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_2THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_3THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_4THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_5THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_6THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_7THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_8THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_9THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_10THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_11THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_12THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_13THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_14THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_15THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_16THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_17THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_18THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_19THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_20THBAND_GROUP_B_LID:    	  	
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_0THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_1THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_2THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_3THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_4THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_0THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_1THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_2THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_3THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_4THBAND_GROUP_B_LID:
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_AM_LUT_GROUP_B_SIZE);
         }
         break;
         
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_0THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_1THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_2THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_3THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_4THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_5THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_6THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_7THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_8THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_9THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_10THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_11THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_12THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_13THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_14THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_15THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_16THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_17THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_18THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_19THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_20THBAND_GROUP_C_LID:    	  	
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_0THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_1THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_2THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_3THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_4THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_0THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_1THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_2THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_3THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_4THBAND_GROUP_C_LID:
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_AM_LUT_GROUP_C_SIZE);
         }
         break;

         /* DPD PM LUT */
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_0THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_1THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_2THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_3THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_4THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_5THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_6THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_7THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_8THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_9THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_10THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_11THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_12THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_13THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_14THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_15THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_16THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_17THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_18THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_19THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_20THBAND_GROUP_A_LID:    	  	
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_0THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_1THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_2THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_3THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_4THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_0THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_1THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_2THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_3THBAND_GROUP_A_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_4THBAND_GROUP_A_LID:
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_PM_LUT_GROUP_A_SIZE);
         }
         break;
         
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_0THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_1THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_2THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_3THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_4THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_5THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_6THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_7THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_8THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_9THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_10THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_11THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_12THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_13THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_14THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_15THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_16THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_17THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_18THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_19THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_20THBAND_GROUP_B_LID:    	  	
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_0THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_1THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_2THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_3THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_4THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_0THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_1THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_2THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_3THBAND_GROUP_B_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_4THBAND_GROUP_B_LID:
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_PM_LUT_GROUP_B_SIZE);
         }
         break;
         
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_0THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_1THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_2THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_3THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_4THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_5THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_6THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_7THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_8THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_9THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_10THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_11THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_12THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_13THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_14THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_15THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_16THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_17THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_18THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_19THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_20THBAND_GROUP_C_LID:    	  	
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_0THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_1THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_2THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_3THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_4THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_0THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_1THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_2THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_3THBAND_GROUP_C_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_4THBAND_GROUP_C_LID:
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_PM_LUT_GROUP_C_SIZE);
         }
         break;
         
      #elif IS_DPD_LUT_SIZE_GAIN_NUM_8_OR_16

         /* DPD AM LUT */
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_0THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_1THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_2THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_3THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_4THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_5THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_6THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_7THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_8THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_9THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_10THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_11THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_12THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_13THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_14THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_15THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_16THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_17THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_18THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_19THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_AM_LUT_20THBAND_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_0THBAND_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_1THBAND_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_2THBAND_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_3THBAND_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_AM_LUT_4THBAND_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_0THBAND_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_1THBAND_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_2THBAND_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_3THBAND_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_AM_LUT_4THBAND_LID:		 	
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_AM_LUT_SIZE);
         }
         break;

         /* DPD PM LUT */
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_0THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_1THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_2THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_3THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_4THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_5THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_6THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_7THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_8THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_9THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_10THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_11THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_12THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_13THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_14THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_15THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_16THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_17THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_18THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_19THBAND_LID:
         case NVRAM_EF_EL1_DPD_FAC_PM_LUT_20THBAND_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_0THBAND_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_1THBAND_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_2THBAND_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_3THBAND_LID:
         case NVRAM_EF_EL1_DPD_BYPASS_FAC_PM_LUT_4THBAND_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_0THBAND_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_1THBAND_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_2THBAND_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_3THBAND_LID:
         case NVRAM_EF_EL1_DPD_TX_HRM_FAC_PM_LUT_4THBAND_LID:		 	
         {
            kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_PM_LUT_SIZE);
         }
         break;
	  
      #endif	  

      /* DPD BYPASS factory cal common setting and algo parameters */
      case NVRAM_EF_EL1_DPD_BYPASS_FAC_COMMON_ALGO_PARAM_0THBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_FAC_COMMON_ALGO_PARAM_1THBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_FAC_COMMON_ALGO_PARAM_2THBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_FAC_COMMON_ALGO_PARAM_3THBAND_LID:
      case NVRAM_EF_EL1_DPD_BYPASS_FAC_COMMON_ALGO_PARAM_4THBAND_LID:  	
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_SIZE);
         kal_mem_cpy(buffer, LTE_BYPASS_DPD_FAC_COMMON_ALGO_PARAM_TABLE_SetDefault[(lid-NVRAM_EF_EL1_DPD_BYPASS_FAC_COMMON_ALGO_PARAM_START)], NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_SIZE);                         
      }
      break;

      /* DPD TX_HRM factory cal common setting and algo parameters */
      case NVRAM_EF_EL1_DPD_TX_HRM_FAC_COMMON_ALGO_PARAM_0THBAND_LID:
      case NVRAM_EF_EL1_DPD_TX_HRM_FAC_COMMON_ALGO_PARAM_1THBAND_LID:
      case NVRAM_EF_EL1_DPD_TX_HRM_FAC_COMMON_ALGO_PARAM_2THBAND_LID:
      case NVRAM_EF_EL1_DPD_TX_HRM_FAC_COMMON_ALGO_PARAM_3THBAND_LID:
      case NVRAM_EF_EL1_DPD_TX_HRM_FAC_COMMON_ALGO_PARAM_4THBAND_LID:  	
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_SIZE);
         kal_mem_cpy(buffer, LTE_TX_HRM_DPD_FAC_COMMON_ALGO_PARAM_TABLE[(lid-NVRAM_EF_EL1_DPD_TX_HRM_FAC_COMMON_ALGO_PARAM_START)], NVRAM_EF_EL1_DPD_FAC_COMMON_ALGO_PARAM_SIZE);                        
      }
      break;
      #endif

      #if IS_4G_CIM3_SUPPORT
      /* CIM3 feature */
      case NVRAM_EF_EL1_CIM3_FEATURE_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_CIM3_FEATURE_SIZE);
      }
      break;

      case NVRAM_EF_EL1_CIM3_BAND_INDICATOR_LID:
      {
         kal_mem_cpy(buffer, cim3BandIndArray, NVRAM_EF_EL1_CIM3_BAND_INDICATOR_SIZE);
      }
      break;

      /* CIM3 factory cal common setting */
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_0THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_1THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_2THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_3THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_4THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_5THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_6THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_7THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_8THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_9THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_10THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_11THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_12THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_13THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_14THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_15THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_16THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_17THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_18THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_19THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_20THBAND_LID:	  	
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_SIZE);
         kal_mem_cpy(buffer, LTE_CIM3_FAC_COMMON_ALGO_PARAM_TABLE_SetDefault[(lid-NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_START)], NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_SIZE);      
      }
      break;
 
      /* CIM3 LUT */
      case NVRAM_EF_EL1_CIM3_FAC_LUT_0THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_1THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_2THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_3THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_4THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_5THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_6THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_7THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_8THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_9THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_10THBAND_LID:	  	
      case NVRAM_EF_EL1_CIM3_FAC_LUT_11THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_12THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_13THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_14THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_15THBAND_LID:	  	
      case NVRAM_EF_EL1_CIM3_FAC_LUT_16THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_17THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_18THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_19THBAND_LID:
      case NVRAM_EF_EL1_CIM3_FAC_LUT_20THBAND_LID:	  	
      case NVRAM_EF_EL1_CIM3_BYPASS_FAC_LUT_0THBAND_LID:
      case NVRAM_EF_EL1_CIM3_BYPASS_FAC_LUT_1THBAND_LID:
      case NVRAM_EF_EL1_CIM3_BYPASS_FAC_LUT_2THBAND_LID:
      case NVRAM_EF_EL1_CIM3_BYPASS_FAC_LUT_3THBAND_LID:
      case NVRAM_EF_EL1_CIM3_BYPASS_FAC_LUT_4THBAND_LID:
      case NVRAM_EF_EL1_CIM3_TX_HRM_FAC_LUT_0THBAND_LID:
      case NVRAM_EF_EL1_CIM3_TX_HRM_FAC_LUT_1THBAND_LID:
      case NVRAM_EF_EL1_CIM3_TX_HRM_FAC_LUT_2THBAND_LID:
      case NVRAM_EF_EL1_CIM3_TX_HRM_FAC_LUT_3THBAND_LID:
      case NVRAM_EF_EL1_CIM3_TX_HRM_FAC_LUT_4THBAND_LID:
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_CIM3_FAC_LUT_SIZE);
      }
      break;

      /* CIM3 BYPASS factory cal common setting */
      case NVRAM_EF_EL1_CIM3_BYPASS_FAC_COMMON_ALGO_PARAM_0THBAND_LID:
      case NVRAM_EF_EL1_CIM3_BYPASS_FAC_COMMON_ALGO_PARAM_1THBAND_LID:
      case NVRAM_EF_EL1_CIM3_BYPASS_FAC_COMMON_ALGO_PARAM_2THBAND_LID:
      case NVRAM_EF_EL1_CIM3_BYPASS_FAC_COMMON_ALGO_PARAM_3THBAND_LID:
      case NVRAM_EF_EL1_CIM3_BYPASS_FAC_COMMON_ALGO_PARAM_4THBAND_LID:  	
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_SIZE);
         kal_mem_cpy(buffer, LTE_BYPASS_CIM3_FAC_COMMON_ALGO_PARAM_TABLE_SetDefault[(lid-NVRAM_EF_EL1_CIM3_BYPASS_FAC_COMMON_ALGO_PARAM_START)], NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_SIZE);
      }
      break;

      /* CIM3 TX_HRM factory cal common setting */
      case NVRAM_EF_EL1_CIM3_TX_HRM_FAC_COMMON_ALGO_PARAM_0THBAND_LID:
      case NVRAM_EF_EL1_CIM3_TX_HRM_FAC_COMMON_ALGO_PARAM_1THBAND_LID:
      case NVRAM_EF_EL1_CIM3_TX_HRM_FAC_COMMON_ALGO_PARAM_2THBAND_LID:
      case NVRAM_EF_EL1_CIM3_TX_HRM_FAC_COMMON_ALGO_PARAM_3THBAND_LID:
      case NVRAM_EF_EL1_CIM3_TX_HRM_FAC_COMMON_ALGO_PARAM_4THBAND_LID:  	
      {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_SIZE);
         kal_mem_cpy(buffer, LTE_TX_HRM_CIM3_FAC_COMMON_ALGO_PARAM_TABLE[(lid-NVRAM_EF_EL1_CIM3_TX_HRM_FAC_COMMON_ALGO_PARAM_START)], NVRAM_EF_EL1_CIM3_FAC_COMMON_ALGO_PARAM_SIZE);
      }
      break;
 
      #endif

#if   IS_4G_PCFE_SA_TUNE_PARA_SUPPORT || IS_4G_DPD_SUPPORT     
      case NVRAM_EF_EL1_PCFE_SA_TUNE_CUSTOM_PARA_LID:
         kal_mem_cpy(buffer, LTE_PCFE_SA_Tune_Param_Custom_SetDefault, NVRAM_EF_EL1_PCFE_SA_TUNE_CUSTOM_PARA_SIZE);
      break;  
      
      case NVRAM_EF_EL1_PCFE_DPD_CIM3_OTFC_TUNE_PARA_LID:
         kal_mem_cpy(buffer, p_LTE_PCFE_DPD_CIM3_OTFC_Tune_Para, NVRAM_EF_EL1_PCFE_DPD_CIM3_OTFC_TUNE_PARA_SIZE);
      break;        
#endif

      /* ET feature */
      case NVRAM_EF_EL1_ET_COMP_PARAM_0THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_1THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_2THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_3THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_4THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_5THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_6THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_7THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_8THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_9THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_10THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_11THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_12THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_13THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_14THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_15THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_16THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_17THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_18THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_19THBAND_LID:
      case NVRAM_EF_EL1_ET_COMP_PARAM_20THBAND_LID:
      {
#if IS_4G_ET_FEATURE_SUPPORT
         kal_mem_cpy(buffer,
         LTE_EtCompParamPerBand_SetDefault[(lid-NVRAM_EF_EL1_ET_COMP_PARAM_START)],
         sizeof(LTE_RfcEtCompParamPerBand_T));
#else
         kal_mem_set(buffer, 0, sizeof(LTE_RfcEtCompParamPerBand_T));
#endif   // #if IS_4G_ET_FEATURE_SUPPORT
      }
      break;

      case NVRAM_EF_EL1_BYPASS_ET_COMP_PARAM_0THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_ET_COMP_PARAM_1THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_ET_COMP_PARAM_2THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_ET_COMP_PARAM_3THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_ET_COMP_PARAM_4THBAND_LID:
      {
#if IS_4G_ET_FEATURE_SUPPORT
         kal_mem_cpy(buffer,
         LTE_BYPASS_EtCompParamPerBand_SetDefault[(lid-NVRAM_EF_EL1_BYPASS_ET_COMP_PARAM_START)],
         sizeof(LTE_RfcEtCompParamPerBand_T));
#else
         kal_mem_set(buffer, 0, sizeof(LTE_RfcEtCompParamPerBand_T));
#endif   // #if IS_4G_ET_FEATURE_SUPPORT
      }
      break;

      case NVRAM_EF_EL1_TX_HRM_ET_COMP_PARAM_0THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_ET_COMP_PARAM_1THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_ET_COMP_PARAM_2THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_ET_COMP_PARAM_3THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_ET_COMP_PARAM_4THBAND_LID:
      {
#if IS_4G_ET_FEATURE_SUPPORT
         kal_mem_cpy(buffer,
         LTE_EtCompParamPerBand_SetDefault[(lid-NVRAM_EF_EL1_TX_HRM_ET_COMP_PARAM_START)],
         sizeof(LTE_RfcEtCompParamPerBand_T));
#else
         kal_mem_set(buffer, 0, sizeof(LTE_RfcEtCompParamPerBand_T));
#endif   // #if IS_4G_ET_FEATURE_SUPPORT
      }
      break;

      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_0THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_1THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_2THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_3THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_4THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_5THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_6THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_7THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_8THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_9THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_10THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_11THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_12THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_13THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_14THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_15THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_16THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_17THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_18THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_19THBAND_LID:
      case NVRAM_EF_EL1_ET_VIN_LUT_TBL_20THBAND_LID:
      {
#if IS_4G_ET_FEATURE_SUPPORT
         kal_mem_cpy(buffer,
         LTE_EtVinLutTblPerBand_SetDefault[(lid-NVRAM_EF_EL1_ET_VIN_LUT_TBL_START)],
         sizeof(LTE_RfcEtVpaPmAmLutPerBand_T));
#else
         kal_mem_set(buffer, 0, sizeof(LTE_RfcEtVpaPmAmLutPerBand_T));
#endif   // #if IS_4G_ET_FEATURE_SUPPORT
      }
      break;

      case NVRAM_EF_EL1_BYPASS_ET_VIN_LUT_TBL_0THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_ET_VIN_LUT_TBL_1THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_ET_VIN_LUT_TBL_2THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_ET_VIN_LUT_TBL_3THBAND_LID:
      case NVRAM_EF_EL1_BYPASS_ET_VIN_LUT_TBL_4THBAND_LID:
      {
#if IS_4G_ET_FEATURE_SUPPORT
         kal_mem_cpy(buffer,
         LTE_BYPASS_EtVinLutTblPerBand_SetDefault[(lid-NVRAM_EF_EL1_BYPASS_ET_VIN_LUT_TBL_START)],
         sizeof(LTE_RfcEtVpaPmAmLutPerBand_T));
#else
         kal_mem_set(buffer, 0, sizeof(LTE_RfcEtVpaPmAmLutPerBand_T));
#endif   // #if IS_4G_ET_FEATURE_SUPPORT
      }
      break;

      case NVRAM_EF_EL1_TX_HRM_ET_VIN_LUT_TBL_0THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_ET_VIN_LUT_TBL_1THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_ET_VIN_LUT_TBL_2THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_ET_VIN_LUT_TBL_3THBAND_LID:
      case NVRAM_EF_EL1_TX_HRM_ET_VIN_LUT_TBL_4THBAND_LID:
      {
#if IS_4G_ET_FEATURE_SUPPORT
         kal_mem_cpy(buffer,
         LTE_EtVinLutTblPerBand_SetDefault[(lid-NVRAM_EF_EL1_TX_HRM_ET_VIN_LUT_TBL_START)],
         sizeof(LTE_RfcEtVpaPmAmLutPerBand_T));
#else
         kal_mem_set(buffer, 0, sizeof(LTE_RfcEtVpaPmAmLutPerBand_T));
#endif   // #if IS_4G_ET_FEATURE_SUPPORT
      }
      break;

      default:
         ASSERT(KAL_FALSE);
      break;
   }
}
/* default value of MIPI ANT tuner*/
#if IS_MIPI_ANT_TUNER_SUPPORT
void nvram_get_eL1_mipi_ant_value_to_write(nvram_lid_el1_custom_enum lid_el1_custom, kal_uint8 *buffer_el1_custom, kal_uint16 buffer_size_el1_custom)
{
   //DRDI 
   EL1D_RF_CUSTOM_DynamicInit();
   EL1D_RF_CUSTOM_DynamicInitMipi();

   switch (lid_el1_custom)
   {
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_4THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_5THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_6THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_7THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_8THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_9THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_10THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_11THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_12THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_13THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_14THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_15THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_16THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_17THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_18THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_19THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_EVENT_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer_el1_custom, 0, NVRAM_EF_EL1_MIPI_ANTRX_EVENT_SIZE);
            kal_mem_cpy(buffer_el1_custom,
            LTE_MIPI_ANTRX_EVENT_TABLE_SetDefault[(lid_el1_custom-NVRAM_EF_EL1_MIPI_ANTRX_EVENT_START)],
            LTE_MIPI_ANTRX_EVENT_SIZE_TABLE_SetDefault[(lid_el1_custom-NVRAM_EF_EL1_MIPI_ANTRX_EVENT_START)]);
         }
      }
      break;

      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_4THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_5THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_6THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_7THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_8THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_9THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_10THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_11THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_12THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_13THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_14THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_15THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_16THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_17THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_18THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_19THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_EVENT_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer_el1_custom, 0, NVRAM_EF_EL1_MIPI_ANTTX_EVENT_SIZE);
            kal_mem_cpy(buffer_el1_custom,
            LTE_MIPI_ANTTX_EVENT_TABLE_SetDefault[(lid_el1_custom-NVRAM_EF_EL1_MIPI_ANTTX_EVENT_START)],
            LTE_MIPI_ANTTX_EVENT_SIZE_TABLE_SetDefault[(lid_el1_custom-NVRAM_EF_EL1_MIPI_ANTTX_EVENT_START)]);
         }
      }
      break;
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_4THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_5THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_6THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_7THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_8THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_9THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_10THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_11THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_12THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_13THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_14THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_15THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_16THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_17THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_18THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_19THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTRX_DATA_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer_el1_custom, 0, NVRAM_EF_EL1_MIPI_ANTRX_DATA_SIZE);
            kal_mem_cpy(buffer_el1_custom,
            LTE_MIPI_ANTRX_DATA_TABLE_SetDefault[(lid_el1_custom-NVRAM_EF_EL1_MIPI_ANTRX_DATA_START)],
            LTE_MIPI_ANTRX_DATA_SIZE_TABLE_SetDefault[(lid_el1_custom-NVRAM_EF_EL1_MIPI_ANTRX_DATA_START)]);
         }
      }
      break;

      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_0THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_1STBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_2NDBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_3RDBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_4THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_5THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_6THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_7THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_8THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_9THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_10THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_11THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_12THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_13THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_14THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_15THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_16THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_17THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_18THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_19THBAND_LID:
      case NVRAM_EF_EL1_MIPI_ANTTX_DATA_20THBAND_LID:
      {
         if(LTE_MIPI_ENABLE == 1)
         {
            kal_mem_set(buffer_el1_custom, 0, NVRAM_EF_EL1_MIPI_ANTTX_DATA_SIZE);
            kal_mem_cpy(buffer_el1_custom,
            LTE_MIPI_ANTTX_DATA_TABLE_SetDefault[(lid_el1_custom-NVRAM_EF_EL1_MIPI_ANTTX_DATA_START)],
            LTE_MIPI_ANTTX_DATA_SIZE_TABLE_SetDefault[(lid_el1_custom-NVRAM_EF_EL1_MIPI_ANTTX_DATA_START)]);
         }
      }
      break;
       
      default:
         ASSERT(KAL_FALSE);
      break;
   }
   
}
#endif   //end of IS_MIPI_ANT_TUNER_SUPPORT

#endif  // end of #if defined(__LTE_RAT__)
