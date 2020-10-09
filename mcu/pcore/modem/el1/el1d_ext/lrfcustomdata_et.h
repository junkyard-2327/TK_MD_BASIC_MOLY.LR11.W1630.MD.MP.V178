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
 * @file       lrfcustomdata_et.h
 * @author     Arthur Hung (MTK06691)
 * @date       2015.5.18
 * @brief      EL1D RF ET Custom data header file
 * @details
 ******************************************************************************/

#ifndef  __LRFCUSTOMDATA_ET_H__
#define  __LRFCUSTOMDATA_ET_H__

/*******************************************************************************
 * #include
 ******************************************************************************/
#include "lte_custom_rf.h"
#include "lte_custom_mipi_et.h"
#include "el1d_rf_custom_data.h"  //RF custom data structure definition
#include "el1d_rf_et_custom_data.h"
#include "el1d_rf_common.h"

/*******************************************************************************
 * #define
 ******************************************************************************/

/*******************************************************************************
 * Global variables (Extern)
 ******************************************************************************/

/*******************************************************************************
 * Global Functions Prototype (Interface)
 ******************************************************************************/
kal_uint16 EL1D_RF_ET_get_ET_enable_flag_From_Custom( void );

#ifndef __LTE_L1D_RF_SM_SUPPORT__

LTE_ET_EVENT_TABLE_T**        EL1D_RF_ET_get_TxEventTablePtr( void );
LTE_ET_EVENT_TABLE_T*         EL1D_RF_ET_get_TxEventTableBandPtr( kal_uint32 band_indicator );

LTE_ET_DATA_SUBBAND_TABLE_T** EL1D_RF_ET_get_TxDataTablePtr( void );
LTE_ET_DATA_SUBBAND_TABLE_T*  EL1D_RF_ET_get_TxDataTableBandPtr( kal_uint32 band_indicator );

LTE_ET_EVENT_TABLE_T**        EL1D_RF_ET_get_TpcEventTablePtr( void );
LTE_ET_EVENT_TABLE_T*         EL1D_RF_ET_get_TpcEventTableBandPtr( kal_uint32 band_indicator );

LTE_ET_DATA_TABLE_T**         EL1D_RF_ET_get_TpcDataTablePtr( void );
LTE_ET_DATA_TABLE_T*          EL1D_RF_ET_get_TpcDataTableBandPtr( kal_uint32 band_indicator );

LTE_ET_TPC_SECTION_TABLE_T**  EL1D_RF_ET_get_TpcSectionDataTablePtr( void );
LTE_ET_TPC_SECTION_TABLE_T*   EL1D_RF_ET_get_TpcSectionDataTableBandPtr( kal_uint32 band_indicator );

LTE_ET_DATA_TABLE_T**                  EL1D_RF_ET_get_VpaLutDataTablePtr( void );
LTE_ET_LOOKUP_VPA_SECTION_TABLE_T**    EL1D_RF_ET_get_VpaLutSectionDataTablePtr( void );
LTE_ET_LOOKUP_VPA_SECTION_TABLE_T*     EL1D_RF_ET_get_VpaLutSectionDataTablePtr_ByBand( kal_uint16 bandIndex );
LTE_ET_LOOKUP_VPA_SECTION_TABLE_T*     EL1D_RF_ET_get_VpaLutSectionDataTablePtr_BySubBand( kal_uint16 bandIndex, kal_uint16 subBandIndex );

LTE_ET_DATA_TABLE_T**                  EL1D_RF_ET_get_BwDataTablePtr( void );
LTE_ET_BW_SWITCH_SECTION_DATA_T**      EL1D_RF_ET_get_BwSectionDataTablePtr( void );

LTE_ET_DATA_TABLE_T**                  EL1D_RF_ET_get_ModeSettingDataTablePtr( void );
LTE_VPA_SOURCE_CONFIGUATION_TYPE       EL1D_RF_ET_get_VpaSourceConfiguration( kal_uint32 bandIndex, LTE_RF_COMMON_DATA_T *rf_common_data_p );
kal_uint16                             EL1D_RF_ET_get_GainSetting( kal_uint32 bandIndex );
kal_uint16                             EL1D_RF_ET_get_AnaGainValue( kal_uint16 bandIndex );
kal_uint16                             EL1D_RF_ET_get_VpaOffsetVoltageValue( kal_uint32 bandIndex );
kal_uint32                             EL1D_RF_ET_get_AnaVpaOffsetVoltageValue( kal_uint32 bandIndex );
kal_uint16                             EL1D_RF_ET_get_MaximumVoltageValue( kal_uint32 bandIndex );
kal_uint16                             EL1D_RF_ET_get_MinimumVoltageValue( kal_uint32 bandIndex );
LTE_RfcEtVpaPmAmLutPerBand_T*          EL1D_RF_ET_get_CalibrationResultPtr_ByBand( kal_uint16 bandIndex );
kal_uint16                             EL1D_RF_ET_get_Valid_SubBand_Frequency_Count( kal_uint16 bandIndex );
kal_uint16                             EL1D_RF_ET_get_SubBand_Frequency_Value( kal_uint16 bandIndex, kal_uint16 subBandIndex );
kal_uint16                             EL1D_RF_ET_get_HFP_DAC_Threshold_From_Custom( kal_uint16 thresholdIndex );
kal_uint16                             EL1D_RF_ET_get_HFP_DAC_Value_From_Custom( kal_uint16 levelIndex );
kal_uint16                             EL1D_RF_ET_get_ETM_Chip_Type_From_Custom( void );
kal_uint16                             EL1D_RF_ET_get_ETM_USID_Number_From_Custom( void );
kal_uint16                             EL1D_RF_ET_get_ETM_MIPI_Port_Number_From_Custom( void );

#endif   // #ifndef __LTE_L1D_RF_SM_SUPPORT__

#endif //__LRFCUSTOMDATA_ET_H__

