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

/***************************************************************************//**
 * @file       lrfcustomdata_et.c
 * @author     Arthur Hung (MTK06691)
 * @date       2015.5.18
 * @brief      EL1D RF ET custom data
 * @details    RF ET custom data definition. It can be re-build by custom
 ******************************************************************************/

/*******************************************************************************
 * #include
 ******************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"

/* Custom folder setting */
#include "lrfcustomdata_et.h"

/*******************************************************************************
 * #define
 ******************************************************************************/

/*******************************************************************************
 * typedef
 ******************************************************************************/

/*******************************************************************************
 * Constant
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

kal_uint16  LTE_ET_ENABLE = IS_LTE_ET_FRONT_END_ENABLE_SetDefault;

kal_uint16 LTE_ETM_chip_type = ETM_CHIP_TYPE;

kal_uint8 LTE_ET_MIPI_USID = MIPI_USID_ETM;

kal_uint8 LTE_ETM_MIPI_port_number = MIPI_PORT_ET;

#else

kal_uint16 LTE_ET_ENABLE = 0;

#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

#ifndef __LTE_L1D_RF_SM_SUPPORT__

ET_MIPI_SUBFREQ_GROUP_T et_mipi_tx_subfreq_group[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM/*band_indicator*/ ];
ET_MIPI_SUBFREQ_GROUP_T et_mipi_tpc_subfreq_group[ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM/*band_indicator*/ ];

#endif   // #ifndef __LTE_L1D_RF_SM_SUPPORT__

/*******************************************************************************
 * Fuction Definitions
 ******************************************************************************/

#ifndef __LTE_L1D_RF_SM_SUPPORT__

kal_uint16 EL1D_RF_ET_get_ET_enable_flag_From_Custom( void )
{
   return ( ( kal_uint16 )( LTE_ET_ENABLE ) );
}

LTE_ET_EVENT_TABLE_T** EL1D_RF_ET_get_TxEventTablePtr( void )
{
   LTE_ET_EVENT_TABLE_T** retPtr;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_TX_EVENT_TABLE_SetDefault;
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_EVENT_TABLE_T* EL1D_RF_ET_get_TxEventTableBandPtr( kal_uint32 band_indicator )
{
   LTE_ET_EVENT_TABLE_T* retPtr;

   EXT_ASSERT( ( band_indicator <= LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ), 0, 0, 0 );

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_TX_EVENT_TABLE_SetDefault[ band_indicator ];
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_DATA_SUBBAND_TABLE_T** EL1D_RF_ET_get_TxDataTablePtr( void )
{
   LTE_ET_DATA_SUBBAND_TABLE_T** retPtr;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_TX_DATA_TABLE_SetDefault;
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_DATA_SUBBAND_TABLE_T* EL1D_RF_ET_get_TxDataTableBandPtr( kal_uint32 band_indicator )
{
   LTE_ET_DATA_SUBBAND_TABLE_T* retPtr;

   EXT_ASSERT( ( band_indicator <= LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ), 0, 0, 0 );

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_TX_DATA_TABLE_SetDefault[ band_indicator ];
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   
   return retPtr;
}

LTE_ET_EVENT_TABLE_T** EL1D_RF_ET_get_TpcEventTablePtr( void )
{
   LTE_ET_EVENT_TABLE_T** retPtr;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_TPC_EVENT_TABLE_SetDefault;
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_EVENT_TABLE_T* EL1D_RF_ET_get_TpcEventTableBandPtr( kal_uint32 band_indicator )
{
   LTE_ET_EVENT_TABLE_T* retPtr;

   EXT_ASSERT( ( band_indicator <= LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ), 0, 0, 0 );

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_TPC_EVENT_TABLE_SetDefault[ band_indicator ];
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_DATA_TABLE_T** EL1D_RF_ET_get_TpcDataTablePtr( void )
{
   LTE_ET_DATA_TABLE_T** retPtr;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_TPC_DATA_TABLE_SetDefault;
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_DATA_TABLE_T* EL1D_RF_ET_get_TpcDataTableBandPtr( kal_uint32 band_indicator )
{
   LTE_ET_DATA_TABLE_T* retPtr;

   EXT_ASSERT( ( band_indicator <= LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ), 0, 0, 0 );

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_TPC_DATA_TABLE_SetDefault[ band_indicator ];
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   
   return retPtr;
}

LTE_ET_TPC_SECTION_TABLE_T** EL1D_RF_ET_get_TpcSectionDataTablePtr( void )
{
   LTE_ET_TPC_SECTION_TABLE_T** retPtr;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_TPC_SECTION_DATA_TABLE_SetDefault;
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_TPC_SECTION_TABLE_T* EL1D_RF_ET_get_TpcSectionDataTableBandPtr( kal_uint32 band_indicator )
{
   LTE_ET_TPC_SECTION_TABLE_T* retPtr;

   EXT_ASSERT( ( band_indicator < LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ), 0, 0, 0 );

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_TPC_SECTION_DATA_TABLE_SetDefault[ band_indicator ];
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   
   return retPtr;
}

LTE_ET_DATA_TABLE_T** EL1D_RF_ET_get_VpaLutDataTablePtr( void )
{
   LTE_ET_DATA_TABLE_T** retPtr;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_LOOKUP_VPA_DATA_TABLE_SetDefault;
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_LOOKUP_VPA_SECTION_TABLE_T** EL1D_RF_ET_get_VpaLutSectionDataTablePtr( void )
{
   LTE_ET_LOOKUP_VPA_SECTION_TABLE_T** retPtr;
	   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_LOOKUP_VPA_SECTION_DATA_TABLE_SetDefault;
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_LOOKUP_VPA_SECTION_TABLE_T* EL1D_RF_ET_get_VpaLutSectionDataTablePtr_ByBand( kal_uint16 bandIndex )
{
   LTE_ET_LOOKUP_VPA_SECTION_TABLE_T* retPtr;
		   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_LOOKUP_VPA_SECTION_DATA_TABLE_SetDefault[ bandIndex ];
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_LOOKUP_VPA_SECTION_TABLE_T* EL1D_RF_ET_get_VpaLutSectionDataTablePtr_BySubBand( kal_uint16 bandIndex, kal_uint16 subBandIndex )
{
   LTE_ET_LOOKUP_VPA_SECTION_TABLE_T* retPtr;
		   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_LOOKUP_VPA_SECTION_DATA_TABLE_SetDefault[ bandIndex ];

   retPtr = &( retPtr[ subBandIndex ] );
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_DATA_TABLE_T** EL1D_RF_ET_get_BwDataTablePtr( void )
{
   LTE_ET_DATA_TABLE_T** retPtr;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_BW_SWITCH_DATA_TABLE_SetDefault;
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_BW_SWITCH_SECTION_DATA_T** EL1D_RF_ET_get_BwSectionDataTablePtr( void )
{
   LTE_ET_BW_SWITCH_SECTION_DATA_T** retPtr;
	   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ET_BW_SWITCH_SECTION_DATA_TABLE_SetDefault;
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_ET_DATA_TABLE_T** EL1D_RF_ET_get_ModeSettingDataTablePtr( void )
{
   LTE_ET_DATA_TABLE_T** retPtr;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_ETM_MODE_SETTING_DATA_TABLE_SetDefault;
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

LTE_VPA_SOURCE_CONFIGUATION_TYPE EL1D_RF_ET_get_VpaSourceConfiguration( kal_uint32 bandIndex, LTE_RF_COMMON_DATA_T *rf_common_data_p )
{
   LTE_VPA_SOURCE_CONFIGUATION_TYPE retValue;

   EXT_ASSERT( ( bandIndex < LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ), bandIndex, 0, 0 );
 
   retValue = rf_common_data_p->lte_vpa_source_config.lte_vpa_source_table[ bandIndex ];

   return retValue;
}

kal_uint16 EL1D_RF_ET_get_GainSetting( kal_uint32 bandIndex )
{
   kal_uint16 retValue;

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retValue = LTE_ET_OUTER_LOOP_GAIN_DATA_TABLE_SetDefault[ bandIndex ];
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retValue;
}

kal_uint16 EL1D_RF_ET_get_AnaGainValue( kal_uint16 bandIndex )
{
   kal_uint16 retValue;
	
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   kal_uint16 gainSetting;
   gainSetting =  EL1D_RF_ET_get_GainSetting( bandIndex );

   if( gainSetting == ET_MT6300_OUTER_LOOP_GAIN_1dot5x )
   {
      retValue = 3;
   }
   else if( gainSetting == ET_MT6300_OUTER_LOOP_GAIN_2dot0x )
   {
      retValue = 4;
   }
   else if( gainSetting == ET_MT6300_OUTER_LOOP_GAIN_2dot5x )
   {
      retValue = 5;
   }
   else if( gainSetting == ET_MT6300_OUTER_LOOP_GAIN_3dot0x )
   {
      retValue = 6;
   }
   else
   {
      retValue = 0;
	  EXT_ASSERT( 0, bandIndex, gainSetting, 0 );
   }
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
	
   return retValue;
}

kal_uint16 EL1D_RF_ET_get_VpaOffsetVoltageValue( kal_uint32 bandIndex )
{
   kal_uint16 retValue;

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retValue = LTE_ET_VPA_OFFSET_VOLTAGE_DATA_TABLE_SetDefault[ bandIndex ];
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retValue;
}

kal_uint32 EL1D_RF_ET_get_AnaVpaOffsetVoltageValue( kal_uint32 bandIndex )
{
   kal_uint32 retValue;

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   kal_uint32 vpaOffsetValue;
   vpaOffsetValue = EL1D_RF_ET_get_VpaOffsetVoltageValue( bandIndex );
   retValue = ( ( vpaOffsetValue * 512 ) / 1000 );
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retValue;
}

kal_uint16 EL1D_RF_ET_get_MaximumVoltageValue( kal_uint32 bandIndex )
{
   kal_uint16 retValue;

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retValue = LTE_ET_MAXIMUM_OUTPUT_VOLTAGE_DATA_TABLE_SetDefault[ bandIndex ];
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retValue;
}

kal_uint16 EL1D_RF_ET_get_MinimumVoltageValue( kal_uint32 bandIndex )
{
   kal_uint16 retValue;

#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retValue = LTE_ET_MINIMUM_OUTPUT_VOLTAGE_DATA_TABLE_SetDefault[ bandIndex ];
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retValue;
}

LTE_RfcEtVpaPmAmLutPerBand_T* EL1D_RF_ET_get_CalibrationResultPtr_ByBand( kal_uint16 bandIndex )
{
   LTE_RfcEtVpaPmAmLutPerBand_T* retPtr;
		   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retPtr = LTE_EtVinLutTblPerBand_SetDefault[ bandIndex ];
#else
   retPtr = NULL;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retPtr;
}

kal_uint16 EL1D_RF_ET_get_Valid_SubBand_Frequency_Count( kal_uint16 bandIndex )
{
   kal_uint16 retValue;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retValue = et_mipi_tx_subfreq_group[ bandIndex ].numValidSubband;
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retValue;
}

kal_uint16 EL1D_RF_ET_get_SubBand_Frequency_Value( kal_uint16 bandIndex, kal_uint16 subBandIndex )
{
   kal_uint16 retValue;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retValue = et_mipi_tx_subfreq_group[ bandIndex ].sub_freq[ subBandIndex ];
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retValue;
}

kal_uint16 EL1D_RF_ET_get_HFP_DAC_Threshold_From_Custom( kal_uint16 thresholdIndex )
{
   kal_uint16 retValue;
	   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   if( thresholdIndex == 1 )
   {
      retValue = LTE_ET_MT6300_HFP_DAC_THRESHOLD1;
   }
   else if( thresholdIndex == 2 )
   {
      retValue = LTE_ET_MT6300_HFP_DAC_THRESHOLD2;
   }
   else if( thresholdIndex == 3 )
   {
      retValue = LTE_ET_MT6300_HFP_DAC_THRESHOLD3;
   }
   else
   {
      EXT_ASSERT( 0, thresholdIndex, 0, 0 );
	  retValue = 0;
   }
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
	
   return retValue;
}

kal_uint16 EL1D_RF_ET_get_HFP_DAC_Value_From_Custom( kal_uint16 levelIndex )
{
   kal_uint16 retValue;
		   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   if( levelIndex == 0 )
   {
      retValue = LTE_ET_MT6300_HFP_EA_RSS_LEVEL0;
   }
   else if( levelIndex == 1 )
   {
      retValue = LTE_ET_MT6300_HFP_EA_RSS_LEVEL1;
   }
   else if( levelIndex == 2 )
   {
      retValue = LTE_ET_MT6300_HFP_EA_RSS_LEVEL2;
   }
   else if( levelIndex == 3 )
   {
      retValue = LTE_ET_MT6300_HFP_EA_RSS_LEVEL3;
   }
   else
   {
      EXT_ASSERT( 0, levelIndex, 0, 0 );
      retValue = 0;
   }
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
		
   return retValue;
}

kal_uint16 EL1D_RF_ET_get_ETM_Chip_Type_From_Custom( void )
{
   kal_uint16 retValue;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retValue =  LTE_ETM_chip_type;
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retValue;
}

kal_uint16 EL1D_RF_ET_get_ETM_USID_Number_From_Custom( void )
{
   kal_uint16 retValue;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retValue =  LTE_ET_MIPI_USID;
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retValue;
}

kal_uint16 EL1D_RF_ET_get_ETM_MIPI_Port_Number_From_Custom( void )
{
   kal_uint16 retValue;
   
#if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )
   retValue =  LTE_ETM_MIPI_port_number;
#else
   retValue = 0;
#endif   // #if( defined( IS_MML1_ET_FRONT_END_ENABLE ) && ( IS_MML1_ET_FRONT_END_ENABLE == 1 ) )

   return retValue;
}

#endif   // #ifndef __LTE_L1D_RF_SM_SUPPORT__

