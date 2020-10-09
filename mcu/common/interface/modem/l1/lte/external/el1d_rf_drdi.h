/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   el1_drdi.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Dynamic Radio-setting Dedicated Image.
 *   The structure definition of EL1 DRDI data
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/
#ifndef _EL1_DRDI_H_
#define _EL1_DRDI_H_

/*============================================================================*/

#include "kal_general_types.h"
#include "el1d_rf_custom_data.h"
#include "dcl.h"        //SmartPhone Project's CommonModemImage need this
#include "el1d_rf_et_custom_data.h"

/*============================================================================*/


/*****************************************************************************
* Constant    : EL1_CUSTOM_MAX_RF_BPI_EVENT_NUM
* Group       : Real target, Internal, EL1D common operation
* Description : Constant to be used for record the maximum 4G BPI event
*               support numbers currently in use
*****************************************************************************/
#define EL1_CUSTOM_MAX_RF_BPI_EVENT_NUM      (6)

/*****************************************************************************
* Constant    : EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM
* Group       : Real target, Internal, EL1D common operation
* Description : Constant to be used for record the maximum 4G RF band
*               support numbers currently in use
*****************************************************************************/
#define EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM      LTE_TARGET_MAX_SUPPORT_BAND_NUM
#define EL1_CUSTOM_MAX_RF_SUPPORT_CA_BAND_NUM   LTE_TARGET_MAX_SUPPORT_CA_BAND_NUM
#define EL1_CUSTOM_MAX_RX_TYPE1_COMP_ROUTE_NUM  LTE_MAX_RX_TYPE1_COMP_ROUTE_NUM
#define EL1_CUSTOM_MAX_RX_TYPE2_COMP_ROUTE_NUM  LTE_MAX_RX_TYPE2_COMP_ROUTE_NUM
#define EL1_CUSTOM_MAX_TX_COMP_ROUTE_NUM        LTE_MAX_TX_COMP_ROUTE_NUM
#define EL1_CUSTOM_MAX_RF_SUPPORT_FE_ROUTE_NUM  LTE_MAX_SUPPORT_FE_ROUTE_NUM
#define EL1_CUSTOM_ERF_SPLIT_BAND               LTE_ERF_SPLIT_BAND
#define EL1_CUSTOM_ERF_MAX_SPLIT_PART           LTE_ERF_MAX_SPLIT_PART
#define EL1_ERF_SPLIT_PART_NUM                  LTE_ERF_SPLIT_PART_NUM
#define EL1_CUSTOM_ERF_PARTIAL_BAND             LTE_PARTIAL_BAND_SUPPORT_NUM
#define EL1_CUSTOM_BYPASS_MAX_SUPPORT_BAND_NUM  LTE_BYPASS_MAX_SUPPORT_BAND_NUM
#define EL1_CUSTOM_TX_HRM_MAX_SUPPORT_BAND_NUM  LTE_TX_HRM_MAX_SUPPORT_BAND_NUM
#define EL1_CUSTOM_ERF_TAS_TOTAL_NUM            LTE_ERF_TAS_TOTAL_NUM
#define EL1_CUSTOM_ERF_TAS_BAND_NUM             LTE_ERF_TAS_BAND_NUM
#define EL1_CUSTOM_AMPR_TABLE_ALL_SIZE          LTE_AMPR_TABLE_ALL_SIZE
#define EL1_CUSTOM_AMPR_TABLE_SIZE              LTE_AMPR_TABLE_SIZE
#if IS_4G_HPUE_FEATURE_SUPPORT
#define EL1_CUSTOM_HPUE_BAND_NUM                LTE_HPUE_BAND_NUM
#endif

/*****************************************************************************
* Constant    : EL1_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME
* Group       : Real target, Internals, UL1D common operation
* Description : Constant to be used to determine the max number of GPIO
*               detection pin names defined so far at AP side GPIO driver
*****************************************************************************/
#define EL1_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME  (3)


/*****************************************************************************
* Constant    : EL1_CUSTOM_NULL_ACTION_ID
*               EL1_CUSTOM_GPIO_DETECTION_ID
*               EL1_CUSTOM_ADC_DETECTION_ID
*               EL1_CUSTOM_BARCODE_DETECTION_ID
* Group       : Real target, Internals, EL1D common operation
* Description : Constant to be used to define the value to be used in
*               enumeration Ul1CustomActionId
*****************************************************************************/
#define EL1_CUSTOM_NULL_ACTION_ID         (0)
#define EL1_CUSTOM_GPIO_DETECTION_ID      (1)
#define EL1_CUSTOM_ADC_DETECTION_ID       (2)
#define EL1_CUSTOM_BARCODE_DETECTION_ID   (3)


/*****************************************************************************
* Typedef     : El1CustomDynamicInitUmtsBpiData
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               4G BPI data
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   LTE_Band   bandToModify;

   /* ASM logics */
   kal_uint32 asmLogics[EL1_CUSTOM_MAX_RF_BPI_EVENT_NUM];

} El1CustomDynamicInitLteBpiData;


/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteRxLnaPortTxPath
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               for Rx LNA port and Tx path setting
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   LTE_Band   bandToModify;

   /* LNA port selection */
   kal_uint8  lnaPortNum;

   /* RXD LNA port selection */
   kal_uint8  lnaPortNum2;

   /* TX output path selection */
   kal_uint8  txOutputSel; 

} El1CustomDynamicInitLteRxLnaPortTxPath;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteFeRouteData
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               for LTE Front-End Custom data definition, including BPI and RTX IO port
*****************************************************************************/
typedef struct
{
  LTE_FE_ROUTE_TABLE_T FeRouteData[EL1_CUSTOM_MAX_RF_SUPPORT_FE_ROUTE_NUM];
} El1CustomDynamicInitLteFeRouteData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTxRampData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Tx Ramp data
*****************************************************************************/
typedef struct
{
   /* LTE TX Ramp data array */
   LTE_sRAMPDATA *TxRampData[EL1_CUSTOM_MAX_TX_COMP_ROUTE_NUM];

} El1CustomDynamicInitLteTxRampData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTxPaOctLvlData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Tx PA oct-level data
*****************************************************************************/
typedef struct
{
   /* LTE TX oct-level data array */
   LTE_sPAOCTLVLSETTING *TxPaOctLvl[EL1_CUSTOM_MAX_TX_COMP_ROUTE_NUM];

} El1CustomDynamicInitLteTxPaOctLvlData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteBypassTxRampData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Bypass Tx Ramp data
*****************************************************************************/
typedef struct
{
   /* LTE Bypass TX Ramp data array */
   LTE_sRAMPDATA *BypassTxRampData[EL1_CUSTOM_BYPASS_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteBypassTxRampData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteBypassTxPaOctLvlData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Bypass Tx PA oct-level data
*****************************************************************************/
typedef struct
{
   /* LTE Bypass TX oct-level data array */
   LTE_sPAOCTLVLSETTING *BypassTxPaOctLvl[EL1_CUSTOM_BYPASS_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteBypassTxPaOctLvlData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteHRMTxRampData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE HRM Tx Ramp data
*****************************************************************************/
typedef struct
{
   /* LTE HRM TX Ramp data array */
   LTE_sRAMPDATA *HRMTxRampData[EL1_CUSTOM_TX_HRM_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteHRMTxRampData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteHRMTxPaOctLvlData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Bypass Tx PA oct-level data
*****************************************************************************/
typedef struct
{
   /* LTE HRM TX oct-level data array */
   LTE_sPAOCTLVLSETTING *HRMTxPaOctLvl[EL1_CUSTOM_TX_HRM_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteHRMTxPaOctLvlData;
/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteDpdTxRampData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE DPD Tx Ramp data
*****************************************************************************/
typedef struct
{
   /* LTE TX Ramp data array */
   LTE_sRAMPDATA *DpdTxRampData[EL1_CUSTOM_MAX_TX_COMP_ROUTE_NUM];

} El1CustomDynamicInitLteDpdTxRampData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteDpdTxPaOctLvlData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE DPD Tx PA oct-level data
*****************************************************************************/
typedef struct
{
   /* LTE TX oct-level data array */
   LTE_DPD_sPAOCTLVLSETTING *DpdTxPaOctLvl[EL1_CUSTOM_MAX_TX_COMP_ROUTE_NUM];

} El1CustomDynamicInitLteDpdTxPaOctLvlData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteDpdBypassTxRampData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE DPD Bypass Tx Ramp data
*****************************************************************************/
typedef struct
{
   /* LTE Bypass TX Ramp data array */
   LTE_sRAMPDATA *DpdBypassTxRampData[EL1_CUSTOM_BYPASS_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteDpdBypassTxRampData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteDpdBypassTxPaOctLvlData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE DPD Bypass Tx PA oct-level data
*****************************************************************************/
typedef struct
{
   /* LTE Bypass TX oct-level data array */
   LTE_DPD_sPAOCTLVLSETTING *DpdBypassTxPaOctLvl[EL1_CUSTOM_BYPASS_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteDpdBypassTxPaOctLvlData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteDpdHrmTxRampData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE DPD Hrm Tx Ramp data
*****************************************************************************/
typedef struct
{
   /* LTE Hrm TX Ramp data array */
   LTE_sRAMPDATA *DpdHrmTxRampData[EL1_CUSTOM_TX_HRM_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteDpdHrmTxRampData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteDpdHrmTxPaOctLvlData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE DPD Hrm Tx PA oct-level data
*****************************************************************************/
typedef struct
{
   /* LTE Hrm TX oct-level data array */
   LTE_DPD_sPAOCTLVLSETTING *DpdHrmTxPaOctLvl[EL1_CUSTOM_TX_HRM_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteDpdHrmTxPaOctLvlData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteDpdFacCommonAlgoParamTable
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               DPD factory common algorithm paramter table data
*****************************************************************************/
typedef struct
{
   /* DPD factory common algorithm paramter table array */
   MMRfTestDPDFacParamSet *DpdFacCommonAlgoParamTable[EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteDpdFacCommonAlgoParamTable;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteCim3FacCommonAlgoParamTable
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               CIM3 factory common algorithm paramter table data
*****************************************************************************/
typedef struct
{
   /* CIM3 factory common algorithm paramter table array */
   MMRfTestCIM3FacParamSet *Cim3FacCommonAlgoParamTable[EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteCim3FacCommonAlgoParamTable;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteDpdBypassFacCommonAlgoParamTable
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               DPD bypass factory common algorithm paramter table data
*****************************************************************************/
typedef struct
{
   /* DPD factory common algorithm paramter table array */
   MMRfTestDPDFacParamSet *DpdBypassFacCommonAlgoParamTable[EL1_CUSTOM_BYPASS_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteDpdBypassFacCommonAlgoParamTable;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteCim3BypassFacCommonAlgoParamTable
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               CIM3 bypass factory common algorithm paramter table data
*****************************************************************************/
typedef struct
{
   /* CIM3 factory common algorithm paramter table array */
   MMRfTestCIM3FacParamSet *Cim3BypassFacCommonAlgoParamTable[EL1_CUSTOM_BYPASS_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteCim3BypassFacCommonAlgoParamTable;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteDpdHrmFacCommonAlgoParamTable
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               DPD Hrm factory common algorithm paramter table data
*****************************************************************************/
typedef struct
{
   /* DPD factory common algorithm paramter table array */
   MMRfTestDPDFacParamSet *DpdHrmFacCommonAlgoParamTable[EL1_CUSTOM_TX_HRM_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteDpdHrmFacCommonAlgoParamTable;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteCim3HrmFacCommonAlgoParamTable
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               CIM3 Hrm factory common algorithm paramter table data
*****************************************************************************/
typedef struct
{
   /* CIM3 factory common algorithm paramter table array */
   MMRfTestCIM3FacParamSet *Cim3HrmFacCommonAlgoParamTable[EL1_CUSTOM_TX_HRM_MAX_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteCim3HrmFacCommonAlgoParamTable;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLtePcfeSaTuneParamData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               PCFE SA tune paramter paramter table data
*****************************************************************************/
typedef struct
{
   /* PCFE SA tune paramter table array */
   PCFESATuneParaCustomLID *PcfeSaTuneParamCustomData;

} El1CustomDynamicInitLtePcfeSaTuneParamCustomData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteRxPathLossData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Rx path loss data
*****************************************************************************/
typedef struct
{
   /* LTE Rx path loss data array */
   LTE_RX_PL_ROUTE_TYPE1_T  *RxPathLossType1[EL1_CUSTOM_MAX_RX_TYPE1_COMP_ROUTE_NUM];
   LTE_RX_PL_ROUTE_TYPE2_T  *RxPathLossType2[EL1_CUSTOM_MAX_RX_TYPE2_COMP_ROUTE_NUM];
} El1CustomDynamicInitLteRxPathLossData;


/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTempDac
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE temperature DAC data
*****************************************************************************/
typedef struct
{
   /* LTE Temperature DAC */
   LTE_TemperatureDac_T *TempDac;

} El1CustomDynamicInitLteTempDac;


/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTxPrachTmCompData
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Tx PRACH TM comp. data
*****************************************************************************/
//// LTE didn't support PRACM TM compensation
//typedef struct
//{
//   /* LTE TX PRACH TM comp data array */
//   U_sPARACHTMCOMPDATA *TxPrachTmComp[EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM];
//
//} El1CustomDynamicInitLteTxPrachTmCompData;


/*****************************************************************************
* Typedef     : El1CustomFunction
* Group       : Real target, Internals, EL1 common operation
* Type        : Function pointer
* Description : Internal typedef used by EL1 Custom action function prototype
*****************************************************************************/
typedef void (*El1CustomFunction)(void *usrDataPtr);

/*****************************************************************************
* Typedef     : El1CustomActionId
* Group       : Real target, Internals, EL1 common operation
* Type        : Enumeration
* Description : Internal typedef used by EL1 Custom action ID constant value
*****************************************************************************/
typedef enum
{
   EL1_CUSTOM_NULL_ACTION       = EL1_CUSTOM_NULL_ACTION_ID,
   EL1_CUSTOM_BASE_PROC_ACTION  = EL1_CUSTOM_NULL_ACTION_ID,
   EL1_CUSTOM_GPIO_DETECTION    = EL1_CUSTOM_GPIO_DETECTION_ID,
   EL1_CUSTOM_ADC_DETECTION     = EL1_CUSTOM_ADC_DETECTION_ID,
   EL1_CUSTOM_BARCODE_DETECTION = EL1_CUSTOM_BARCODE_DETECTION_ID,
   EL1_CUSTOM_MAX_PROC_ACTIONS
} El1CustomActionId;

/*******************************************************************************
** DRDI for MIPI Custom Setting
*******************************************************************************/
#if IS_4G_DPD_SUPPORT || IS_4G_CIM3_SUPPORT
//Structure to save DRDI of MIPI custom setting
typedef struct
{
   LTE_MIPI_EVENT_TABLE_T          **RxEventTable;   /* LTE MIPI Rx EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **RxDataTable;    /* LTE MIPI Rx DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **TxEventTable;   /* LTE MIPI Tx EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **TxDataTable;    /* LTE MIPI Tx DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **TpcEventTable;  /* LTE MIPI Tpc EVENT Table                */
   LTE_MIPI_DATA_TABLE_T           **TpcDataTable;   /* LTE MIPI Tpc DATA Table                 */
   LTE_MIPI_TPC_SECTION_TABLE_T    **PaTpcSecData;   /* LTE MIPI PA Tpc Section DATA Table      */
   LTE_MIPI_EVENT_TABLE_T          **DpdTpcEventTable;  /* LTE MIPI Tpc EVENT Table                */
   LTE_MIPI_DATA_TABLE_T           **DpdTpcDataTable;   /* LTE MIPI Tpc DATA Table                 */
   LTE_MIPI_TPC_SECTION_TABLE_T    **DpdPaTpcSecData;   /* LTE MIPI PA Tpc Section DATA Table      */
   LTE_MIPI_IMM_DATA_TABLE_T        *InitialCW;      /* LTE MIPI Initial CW                     */
   LTE_MIPI_IMM_DATA_TABLE_T        *SleepCW;        /* LTE MIPI Sleep CW                       */
   LTE_MIPI_IMM_DATA_TABLE_T        *AsmIsolateCW;   /* LTE MIPI AsmIsolate CW                  */
   kal_uint32                       *RxEventSize;    /* LTE MIPI Rx EVENT Size Table            */
   kal_uint32                       *RxDataSize;     /* LTE MIPI Rx DATA Size Table             */
   kal_uint32                       *TxEventSize;    /* LTE MIPI Tx EVENT Size Table            */
   kal_uint32                       *TxDataSize;     /* LTE MIPI Tx DATA Size Table             */
   kal_uint32                       *TpcEventSize;   /* LTE MIPI Tpc EVENT Size Table           */
   kal_uint32                       *PaTpcSecSize;   /* LTE MIPI PA Tpc Section DATA Size Table */
   kal_uint32                       *DpdTpcEventSize;   /* LTE MIPI Tpc EVENT Size Table           */
   kal_uint32                       *DpdPaTpcSecSize;   /* LTE MIPI PA Tpc Section DATA Size Table */

   #if IS_MIPI_ANT_TUNER_SUPPORT
   LTE_MIPI_EVENT_TABLE_T          **AntRxEventTable;      /* LTE MIPI Rx ant EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **AntRxDataTable;       /* LTE MIPI Rx ant DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **AntTxEventTable;      /* LTE MIPI Tx ant EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **AntTxDataTable;       /* LTE MIPI Tx ant DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **AntCaEventTable;      /* LTE MIPI CA ant EVENT Table                 */
   LTE_MIPI_DATA_TABLE_T           **AntCaDataTable;       /* LTE MIPI CA ant DATA Table                  */
   
   kal_uint32                       *AntRxEventSize;       /* LTE MIPI Rx ant EVENT Size Table            */
   kal_uint32                       *AntRxDataSize;        /* LTE MIPI Rx ant DATA Size Table             */
   kal_uint32                       *AntTxEventSize;       /* LTE MIPI Tx ant EVENT Size Table            */
   kal_uint32                       *AntTxDataSize;        /* LTE MIPI Tx ant DATA Size Table             */
   kal_uint32                       *AntCaEventSize;       /* LTE MIPI CA ant DATA Size Table             */   
   kal_uint32                       *AntCaDataSize;        /* LTE MIPI CA ant DATA Size Table             */
   #endif
 
} El1CustomDynamicInitLteMipiEventData;

//Structure to save DRDI of MIPI bypass setting, MIPI bypass feature DRDI
typedef struct
{
   LTE_MIPI_EVENT_TABLE_T          **BypassTxEventTable;   /* LTE MIPI Bypass Tx EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **BypassTxDataTable;    /* LTE MIPI Bypass Tx DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **BypassTpcEventTable;  /* LTE MIPI Bypass Tpc EVENT Table                */
   LTE_MIPI_DATA_TABLE_T           **BypassTpcDataTable;   /* LTE MIPI Bypass Tpc DATA Table                 */
   LTE_MIPI_TPC_SECTION_TABLE_T    **BypassPaTpcSecData;   /* LTE MIPI Bypass PA Tpc Section DATA Table      */
   LTE_MIPI_EVENT_TABLE_T          **DpdBypassTpcEventTable;  /* LTE MIPI Bypass Tpc EVENT Table                */
   LTE_MIPI_DATA_TABLE_T           **DpdBypassTpcDataTable;   /* LTE MIPI Bypass Tpc DATA Table                 */
   LTE_MIPI_TPC_SECTION_TABLE_T    **DpdBypassPaTpcSecData;   /* LTE MIPI Bypass PA Tpc Section DATA Table      */
   kal_uint32                       *BypassTxEventSize;    /* LTE MIPI Bypass Tx EVENT Size Table            */
   kal_uint32                       *BypassTxDataSize;     /* LTE MIPI Bypass Tx DATA Size Table             */
   kal_uint32                       *BypassTpcEventSize;   /* LTE MIPI Bypass Tpc EVENT Size Table           */
   kal_uint32                       *BypassPaTpcSecSize;   /* LTE MIPI Bypass PA Tpc Section DATA Size Table */
   kal_uint32                       *DpdBypassTpcEventSize;   /* LTE MIPI Bypass Tpc EVENT Size Table           */
   kal_uint32                       *DpdBypassPaTpcSecSize;   /* LTE MIPI Bypass PA Tpc Section DATA Size Table */
} El1CustomDynamicInitLteMipiBypassEventData;

#else

//Structure to save DRDI of MIPI custom setting
typedef struct
{
   LTE_MIPI_EVENT_TABLE_T          **RxEventTable;      /* LTE MIPI Rx EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **RxDataTable;       /* LTE MIPI Rx DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **TxEventTable;      /* LTE MIPI Tx EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **TxDataTable;       /* LTE MIPI Tx DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **TpcEventTable;     /* LTE MIPI Tpc EVENT Table                */
   LTE_MIPI_DATA_TABLE_T           **TpcDataTable;      /* LTE MIPI Tpc DATA Table                 */
   LTE_MIPI_TPC_SECTION_TABLE_T    **PaTpcSecData;      /* LTE MIPI PA Tpc Section DATA Table      */
   LTE_MIPI_IMM_DATA_TABLE_T        *InitialCW;         /* LTE MIPI Initial CW                     */
   LTE_MIPI_IMM_DATA_TABLE_T        *SleepCW;           /* LTE MIPI Sleep CW                       */
   LTE_MIPI_IMM_DATA_TABLE_T        *AsmIsolateCW;      /* LTE MIPI AsmIsolate CW                  */
   kal_uint32                       *RxEventSize;       /* LTE MIPI Rx EVENT Size Table            */
   kal_uint32                       *RxDataSize;        /* LTE MIPI Rx DATA Size Table             */
   kal_uint32                       *TxEventSize;       /* LTE MIPI Tx EVENT Size Table            */
   kal_uint32                       *TxDataSize;        /* LTE MIPI Tx DATA Size Table             */
   kal_uint32                       *TpcEventSize;      /* LTE MIPI Tpc EVENT Size Table           */
   kal_uint32                       *PaTpcSecSize;      /* LTE MIPI PA Tpc Section DATA Size Table */

   #if IS_MIPI_ANT_TUNER_SUPPORT
   LTE_MIPI_EVENT_TABLE_T          **AntRxEventTable;      /* LTE MIPI Rx ant EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **AntRxDataTable;       /* LTE MIPI Rx ant DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **AntTxEventTable;      /* LTE MIPI Tx ant EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **AntTxDataTable;       /* LTE MIPI Tx ant DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **AntCaEventTable;      /* LTE MIPI CA ant EVENT Table                 */
   LTE_MIPI_DATA_TABLE_T           **AntCaDataTable;       /* LTE MIPI CA ant DATA Table                  */
   
   kal_uint32                       *AntRxEventSize;       /* LTE MIPI Rx ant EVENT Size Table            */
   kal_uint32                       *AntRxDataSize;        /* LTE MIPI Rx ant DATA Size Table             */
   kal_uint32                       *AntTxEventSize;       /* LTE MIPI Tx ant EVENT Size Table            */
   kal_uint32                       *AntTxDataSize;        /* LTE MIPI Tx ant DATA Size Table             */
   kal_uint32                       *AntCaEventSize;       /* LTE MIPI CA ant EVENT Size Table            */   
   kal_uint32                       *AntCaDataSize;        /* LTE MIPI CA ant DATA Size Table             */
   #endif

} El1CustomDynamicInitLteMipiEventData;

//Structure to save DRDI of MIPI bypass setting, MIPI bypass feature DRDI
typedef struct
{
   LTE_MIPI_EVENT_TABLE_T          **BypassTxEventTable;      /* LTE MIPI Bypass Tx EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **BypassTxDataTable;       /* LTE MIPI Bypass Tx DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **BypassTpcEventTable;     /* LTE MIPI Bypass Tpc EVENT Table                */
   LTE_MIPI_DATA_TABLE_T           **BypassTpcDataTable;      /* LTE MIPI Bypass Tpc DATA Table                 */
   LTE_MIPI_TPC_SECTION_TABLE_T    **BypassPaTpcSecData;      /* LTE MIPI Bypass PA Tpc Section DATA Table      */
   kal_uint32                       *BypassTxEventSize;       /* LTE MIPI Bypass Tx EVENT Size Table            */
   kal_uint32                       *BypassTxDataSize;        /* LTE MIPI Bypass Tx DATA Size Table             */
   kal_uint32                       *BypassTpcEventSize;      /* LTE MIPI Bypass Tpc EVENT Size Table           */
   kal_uint32                       *BypassPaTpcSecSize;      /* LTE MIPI Bypass PA Tpc Section DATA Size Table */
} El1CustomDynamicInitLteMipiBypassEventData;

#endif

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtTxEvent
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE ET Event Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_ET_EVENT_TABLE_T **EtTxEvent;
   
} El1CustomDynamicInitLteEtTxEvent;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtTxData
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE ET Data Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_ET_DATA_SUBBAND_TABLE_T **EtTxData;
   
} El1CustomDynamicInitLteEtTxData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtTpcEvent
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE ET TPC Event Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_ET_EVENT_TABLE_T **EtTpcEvent;
   
} El1CustomDynamicInitLteEtTpcEvent;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtTpcData
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE ET Tpc Data Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_ET_DATA_TABLE_T **EtTpcData;
   
} El1CustomDynamicInitLteEtTpcData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTpcSectionData
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE ET TPC Section Data Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_ET_TPC_SECTION_TABLE_T **EtTpcSectionData;
   
} El1CustomDynamicInitLteEtTpcSectionData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtLookupVpaData
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE ET Lookup Vpa Data Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_ET_DATA_TABLE_T **EtLookupVpaData;
   
} El1CustomDynamicInitLteEtLookupVpaData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtLookupVpaSectionData
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE ET Lookup Vpa Section Data Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_ET_LOOKUP_VPA_SECTION_TABLE_T **EtLookupVpaSectionData;
   
} El1CustomDynamicInitLteEtLookupVpaSectionData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtBwSwitchData
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE ET BW Switch Data Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_ET_DATA_TABLE_T **EtBwSwitchData;
   
} El1CustomDynamicInitLteEtBwSwitchData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtBwSwitchSectionData
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE ET BW Switch Section Data Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_ET_BW_SWITCH_SECTION_DATA_T **EtBwSwitchSectionData;
   
} El1CustomDynamicInitLteEtBwSwitchSectionData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtModeSettingData
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE Et Mode Setting Data Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_ET_DATA_TABLE_T **EtModeSettingData;
   
} El1CustomDynamicInitLteEtModeSettingData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtCompParamPerBand
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE Et Comp Param Per Band Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_RfcEtCompParamPerBand_T **EtCompParamPerBand;
   
} El1CustomDynamicInitLteEtCompParamPerBand;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtVinLutDataPerBand
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE Et VinLut Data Per Band Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_RfcEtVpaPmAmLutPerBand_T **EtVinLutDataPerBand;
   
} El1CustomDynamicInitLteEtVinLutDataPerBand;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteBypassEtCompParamPerBand
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE Bypass Et Comp Param Per Band Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_RfcEtCompParamPerBand_T **BypassEtCompParamPerBand;
   
} El1CustomDynamicInitLteBypassEtCompParamPerBand;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtVinLutDataPerBand
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE Et VinLut Data Per Band Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	LTE_RfcEtVpaPmAmLutPerBand_T **BypassEtVinLutDataPerBand;
   
} El1CustomDynamicInitLteBypassEtVinLutDataPerBand;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtOuterLoopGainSetting
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE Et OuterLoop Gain Setting Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	kal_uint16 *EtOuterLoopGainSetting;
   
} El1CustomDynamicInitLteEtOuterLoopGainSetting;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtVpaOffsetVoltageSetting
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE Et Vpa Offset Voltage Setting Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	kal_uint16 *EtVpaOffsetVoltageSetting;
   
} El1CustomDynamicInitLteEtVpaOffsetVoltageSetting;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtMinimumOutputVoltageSetting
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE Et Minimum Output Voltage Setting Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	kal_uint16 *EtMinimumOutputVoltageSetting;
   
} El1CustomDynamicInitLteEtMinimumOutputVoltageSetting;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteEtMaximumOutputVoltageSetting
* Group       : Real target, Internals, EL1 common operation
* Type        : Pointer
* Description : LTE Et Maximum Output Voltage Setting Table Pointer used by EL1 Custom 
*****************************************************************************/
typedef struct
{
	kal_uint16 *EtMaximumOutputVoltageSetting;
   
} El1CustomDynamicInitLteEtMaximumOutputVoltageSetting;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTxPowerOffsetData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Tx Power Offset data
*****************************************************************************/
#if IS_4G_TX_POWER_OFFSET_SUPPORT || IS_4G_SAR_TX_POWER_OFFSET_SUPPORT
typedef struct
{
   /* LTE TX Power Offset data table */
   LTE_TXPOWEROFFSETDATA *TxPowerOffsetData[EL1_CUSTOM_MAX_TX_COMP_ROUTE_NUM];

} El1CustomDynamicInitLteTxPowerOffsetData;
#endif

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteDatFeatureData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Tx Power Offset data
*****************************************************************************/
#if __IS_LTE_RF_DAT_SUPPORT__
typedef struct
{
   /* LTE DAT feature data table */
   LTE_DAT_FEATURE_ENABLE_T              DatFeatureEnable;
   LTE_CUSTOM_DAT_FE_ROUTE_DATABASE_T    *DatFeRouteDatabase;
   LTE_CUSTOM_CA_DAT_LINKAGE_DATABASE_T  *DatCALinkageDatabase;
   LTE_CUSTOM_DAT_FE_CAT_A_T             *DatCatAConfigDatabase;
   LTE_CUSTOM_DAT_FE_CAT_B_T             *DatCatBConfigDatabase;

   LTE_MIPI_EVENT_TABLE_T          **DatCatAEventTable;      /* LTE MIPI DAT CatA EVENT Table               */
   LTE_MIPI_DATA_TABLE_T           **DatCatADataTable;       /* LTE MIPI DAT CatA DATA  Table               */   
   LTE_MIPI_EVENT_TABLE_T          **DatCatBEventTable;      /* LTE MIPI DAT CatB EVENT Table               */
   LTE_MIPI_DATA_TABLE_T           **DatCatBDataTable;       /* LTE MIPI DAT CatB DATA  Table               */ 
   
   kal_uint32                       *DatCatAEventSize;       /* LTE MIPI Dat CatA EVENT Size Table          */
   kal_uint32                       *DatCatADataSize;        /* LTE MIPI Dat CatA DATA  Size Table          */
   kal_uint32                       *DatCatBEventSize;       /* LTE MIPI Dat CatB EVENT Size Table          */
   kal_uint32                       *DatCatBDataSize;        /* LTE MIPI Dat CatB DATA  Size Table          */

} El1CustomDynamicInitLteDatFeatureData;

#endif

#endif 	/* _EL1_DRDI_H_ */
