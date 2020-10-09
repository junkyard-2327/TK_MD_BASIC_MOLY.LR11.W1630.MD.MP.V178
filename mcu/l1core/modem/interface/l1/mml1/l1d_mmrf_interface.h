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
 *   l1d_mmrf_interface.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   L1D interface to Multi-Mode Multi-RAT RF Central Control
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _L1D_MMRF_INTERFACE_H_
#define  _L1D_MMRF_INTERFACE_H_

/*===============================================================================*/

#include "kal_general_types.h"

#include "mml1_rf_interface.h"
#include "mml1_rf_cal_interface.h"

#include "l1cal.h"

/*===============================================================================*/

#define GSM_MAX_MIPI_PAON_CW_NUMBER_PER_BAND  (48)  //24*2
#define GSM_MAX_MIPI_PAOFF_CW_NUMBER_PER_BAND (24)  //12*2

void L1D_MMRF_PowerOnCalibration(void);
void L1D_MMRF_L1CoreSHMDataInit(void);
void L1D_MMRF_L1coreSHMUpdate2Local(void);
kal_uint32 L1D_MMRF_UpdateRuntimeHandler(kal_uint32 nvram_lid, kal_uint8 *data, kal_uint16 nvram_size);

#if defined(__F32_XOSC_REMOVAL_SUPPORT__)
/* Update CloadFreqOffset before share this value to MMRF */
int L1D_RF_UpdateCLoadFreqOffset( int freq_offset );
#endif

/* SHM reset function*/
void L1_MULTI_RESET_AFC_SHM(void);

//API for 2G MMRFC
kal_uint16 L1D_RF_Get_GsmPocState(void);
kal_uint16 L1D_RF_Cal_Poc_NVRAM_Lid_Total_Num_InUse( void );
kal_uint16 L1D_RF_Get_Rf_Self_Cal_Result_Size(kal_uint16 lid_index);
kal_uint16 L1D_RF_Get_Rf_Self_Cal_Result(kal_uint16 lid_index, kal_uint16 lid_size, kal_uint8 *dst);
kal_uint16 L1D_RF_Set_Rf_Self_Cal_Result(kal_uint16 lid_index, kal_uint16 lid_size, kal_uint8 *src);
kal_uint16 L1D_RF_Get_Rf_Self_Cal_String( kal_uint16 lid_index, kal_char *string_dst );
void L1D_RF_UpdatePocResultToSHM(MMRFC_XL1_BAND_NUM_E band, kal_uint8  band_idx, kal_uint8  subband_idx, kal_uint8  cal_type, MMRFC_GSM_RESULT_PER_BAND_T* cal_result);

/** API for TAS*/
#ifdef __TAS_SUPPORT__
kal_bool L1D_RF_TAS_Support(void);
void     L1D_RF_Force_TAS(kal_bool force_tas_enable, kal_uint8 tas_idx);
#else
#define  L1D_RF_TAS_Support          NULL
#define  L1D_RF_Force_TAS            NULL
#endif

typedef enum
{
   GL1D_LTE_DET_CAL = 0,
   GL1D_GSM_TX_CAL  = 1
} GL1D_POC_STATE_E;

typedef struct
{
   kal_uint16 mipi_data_start;
   kal_uint16 mipi_data_number;
}GL1D_RF_CAL_MIPI_DATA_T;

extern kal_uint32*             grfcalPocBufferTable              [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern kal_uint32              grfcalPocBufferSizeTable          [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern MML1_RF_BSIMM_PORT_T    grfcalPocBufferDataPortSelTable   [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern MML1_MIPI_REG_RW_T      grfcalPocBufferDataMipiCwTypeTable[/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern GL1D_RF_CAL_MIPI_DATA_T GSM_MIPI_PA_ON_DATA               [/*MMPOC_BUFFER_TYPE_NUM_OF*/];
extern GL1D_RF_CAL_MIPI_DATA_T GSM_MIPI_PA_OFF_DATA              [/*MMPOC_BUFFER_TYPE_NUM_OF*/];

#endif /* End of #ifndef _L1D_MMRF_INTERFACE_H_ */
