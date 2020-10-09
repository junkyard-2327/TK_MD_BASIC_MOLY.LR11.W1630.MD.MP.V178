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
 *   mml1_rf_interface.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *   Multi-Mode Multi-RAT Layer1 RF interface to each RAT
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

#ifndef  _MML1_RF_INTERFACE_H_
#define  _MML1_RF_INTERFACE_H_

/*===============================================================================*/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"

#include "mml1_rf_global.h"
#include "mml1_mipi_public.h"
#include "mml1_rf_cc_interface.h"

/*===============================================================================*/

#define  MMRF_NVSRV_NVW_BACKUP_DATA     (0)
#define  MMRF_NVSRV_NVW_BACKUP_PTR      (1)

/*===============================================================================*/

typedef enum
{
   MML1_RF_IS_E1   = 0x0001,
   MML1_RF_IS_E2   = 0x0002,
   MML1_RF_IS_E3   = 0x0003,
}MML1_RF_RFECO_E;

typedef enum
{
   MML1_RF_IS_RFIC1   = 0x0001,
   MML1_RF_IS_RFIC2   = 0x0002,
}MML1_RF_RFIC_INFO_T;

typedef enum
{
   MML1_RF_MD1     = 0x0000,
   MML1_RF_MD2     = 0x0001,
   MML1_RF_MD3     = 0x0002,
   MML1_RF_MD_CNT,
}MML1_RF_MD_T;

typedef enum
{  /* following number are according to HWPOR port select */
   MML1_RF_RFIC1   = 0x0000,
   MML1_RF_RFIC2   = 0x0001,
   MML1_RF_PMIC    = 0x0002,
   MML1_RF_MIPI0   = 0x0003,
   MML1_RF_MIPI1   = 0x0004,
   MML1_RF_MIPI2   = 0x0005,
   MML1_RF_MIPI3   = 0x0006,
   MML1_RF_MIPI4   = 0x0007,
   MML1_RF_PORT_CNT,
}MML1_RF_BSIMM_PORT_T;

typedef enum
{
   MML1_MIPI_RW          = 0x0000,
   MML1_MIPI_EXTRW_1BYTE = 0x0001,
   MML1_MIPI_EXTRW_2BYTE = 0x0002,
   MML1_MIPI_EXTRW_3BYTE = 0x0003,
   MML1_MIPI_EXTRW_4BYTE = 0x0004,
   MML1_MIPI_SUPPORT_RW_CNT,
}MML1_MIPI_REG_RW_T;

typedef enum
{
   MML1_ABB_RATE_4P33M  = 0x001,
   MML1_ABB_RATE_8P66M  = 0x002,
   MML1_ABB_RATE_17P33M = 0x004,
   MML1_ABB_RATE_3P25M  = 0x008,
   MML1_ABB_RATE_6P5M   = 0x010,
   MML1_ABB_RATE_13M    = 0x020,
   MML1_ABB_RATE_26M    = 0x040,
   MML1_ABB_RATE_52M    = 0x080,
   MML1_ABB_RATE_104M   = 0x100,
   MML1_ABB_RATE_208M   = 0x200,
   MML1_ABB_RATE_416M   = 0x400,
   MML1_ABB_RATE_832M   = 0x800,
   MML1_ABB_RATE_NUM    = 0xFFF,
}MML1_ABB_DATA_RATE_E;

typedef enum
{
   MML1_ABB_MODE_FDD    = 0x000,
   MML1_ABB_MODE_TDD    = 0x001,
   MML1_ABB_MODE_LTE    = 0x002,
}MML1_ABB_DATA_MODE_E;

typedef struct
{
   MML1_RF_RAT_T        rat;
   MML1_ABB_DATA_MODE_E mode;      //mode sel : FDD/TDD/LTE
   MML1_ABB_DATA_RATE_E adc_rate;
   MML1_ABB_DATA_RATE_E cic_rate;
   kal_uint16           set;       //s_idx : group0/group1/group2
   kal_uint16           ant;       //a_idx : main/diversity
   kal_uint16           path;      //p_idx : cc0/cc1
   kal_uint16           fdd_r;     //rounding
   kal_uint16           fdd_c;     //clipping
   kal_uint16           lte_zp;    //zero padding
}MMRF_ABB_BBRX_CTRL_T;

typedef enum
{
   WIN_RX1 = 0,
   WIN_RX2 = 1,
   WIN_TX  = 2,
   WIN_RX1_TX = 3,
   WIN_RX2_TX = 4,
   WIN_TYPE_CNT,
}MML1_RF_WIN_TYPE_E;

typedef enum
{
   WIN_OFF  = 0,
   WIN_ON   = 1,
   WIN_OP_CNT,
}MML1_RF_WIN_OP_E;

typedef struct
{  
   MML1_RF_RAT_T        rat_type;
   MML1_RF_WIN_TYPE_E   win_type;
   MML1_RF_WIN_OP_E     win_op;             
   kal_uint32           pmic_vs1_cw;
}MML1_RF_VS1_CTRL_T;

#if defined(__TX_POWER_OFFSET_SUPPORT__) || defined(__SAR_TX_POWER_BACKOFF_SUPPORT__)
typedef enum
{
   SWTP_GSM = 0,
   SWTP_WCDMA,
   SWTP_TDSCDMA,
   SWTP_LTE,
   SWTP_C2K,
   SWTP_RAT_NUM
}SWTP_RAT;

typedef struct
{
   SWTP_RAT     rat;
   kal_uint16   table_idx;
}sSWTP_GetTableIdx;
#endif

typedef enum
{
   DCXO_FPM   = 0,
   DCXO_LPM   = 1,
   DCXO_BBLPM = 2,
}MMRF_DCXO_MODE_E;

typedef enum
{
   MMRF_AP_SENSOR_RELATIVE_GSM = 0,
   MMRF_AP_SENSOR_RELATIVE_WCDMA,
   MMRF_AP_SENSOR_RELATIVE_LTE,
   MMRF_AP_SENSOR_RELATIVE_TDSCDMA,
   MMRF_AP_SENSOR_RELATIVE_C2K,
   MMRF_AP_SENSOR_RELATIVE_RAT_NUM
}MMRF_AP_SENSOR_RELATIVE_RAT_E;

typedef enum
{
   OP_CODE_DAT = 0,
   OP_CODE_SAR = 1,
   OP_CODE_NUM
}MMRF_AP_SENSOR_RELATIVE_OP_CODE_E;

typedef struct
{
   kal_int16     OPcode_0_scenario;
   kal_uint16    OPcode_1_scenario;
}MMRF_AP_SENSOR_RELATIVE_RECORD_T;

typedef struct
{
   kal_uint32  lid;
   kal_uint32  recordIdx;
   kal_uint8  *srcBufPtr;
   kal_uint32  nvSize;
   kal_uint32  opType;
   void       *opParam;
   void      (*callback)(void *);
}MMRF_WRITE_NVRAM_SERVICE_T;

//Refine init flow for Ubin TCM optimized
void MML1_TL1D_L1CoreSHMUpdate2Local(void);
void MML1_UL1D_L1CoreSHMUpdate2Local(void);

//BSI TOP Immediate Mode API for All RAT
void MML1_RF_IMM_SEND_BSI(MML1_RF_BSIMM_PORT_T port, kal_uint32 bsidata);
void MML1_RF_IMM_READ_BSI(MML1_RF_BSIMM_PORT_T port, kal_uint32 bsiaddr, kal_uint32 *bsidata);
void MML1_MIPI_IMM_SEND_BSI(MML1_RF_BSIMM_PORT_T port, MML1_MIPI_REG_RW_T rw_type, kal_uint32 bsidata1, kal_uint32 bsidata2);
void MML1_MIPI_IMM_READ_BSI(MML1_RF_BSIMM_PORT_T port, MML1_MIPI_REG_RW_T rw_type, kal_uint32 bsiaddr, kal_uint32 *bsidata1, kal_uint32 *bsidata2);

//BPI TOP Immediate Mode API for All RAT
void MML1_RF_IMM_SEND_BPI(kal_uint32 bpidata1, kal_uint32 bpidata2);
void MML1_RF_IMM_READ_BPI(MML1_RF_MD_T md, MML1_RF_RAT_T rat, kal_uint32 *bpidata1, kal_uint32 *bpidata2);
void MML1_RF_IMM_READ_BPI_OUT(kal_uint32 *bpidata1, kal_uint32 *bpidata2);
void MML1_RF_IMM_READ_BPI_CONFLICT(MML1_RF_MD_T md, MML1_RF_RAT_T rat, kal_uint32 *bpidata1, kal_uint32 *bpidata2);
void MML1_RF_IMM_SEND_BPI_MASK(MML1_RF_MD_T md, MML1_RF_RAT_T rat, kal_uint32 bpimask1, kal_uint32 bpimask2);
void MML1_RF_IMM_READ_BPI_MASK(MML1_RF_MD_T md, MML1_RF_RAT_T rat, kal_uint32 *bpimask1, kal_uint32 *bpimask2);
kal_uint32 MML1_RF_BPI_CONFLICT_RAT_CHECK(MML1_RF_MD_T md);
kal_bool MML1_RF_BPI_CONFLICT_CHECK(MML1_RF_MD_T md,  MML1_RF_RAT_T rat);

//RF
void MML1_RF_POWER_ON(kal_uint32 is_wake_up, MML1_RF_RAT_T rat_type);
void MML1_RF_POWER_OFF(MML1_RF_RAT_T rat_type);
void MML1_RF_NOTIFY_POC_DONE(MML1_RF_RAT_T rat_type);
kal_uint32 MML1_RF_QUERY_POC_PENDING_LIST(MML1_RF_RAT_T rat_type);
void MML1_RF_SET_SHM_UPDATE_EG(MML1_RF_RAT_T rat_type);
kal_uint32 MML1_RF_RETRIEVE_SHM_UPDATE_EG(MML1_RF_RAT_T rat_type);
kal_uint32 MML1_RF_QUERY_CHIP_VERSION(void);
void MML1_RF_ENTER_FLIGHTMODE_ENTRYPOINT(void);

//PMIC API for all RAT
void MML1_RFC_PMIC_Init(void);
void MML1_RFC_PMIC_Sleep(void);
void MML1_RF_MISC_Set_Register(MML1_RF_RAT_T rat_type, kal_uint32 addr, kal_uint16 data);
void MML1_RF_MISC_Get_Register(MML1_RF_RAT_T rat_type, kal_uint32 addr, kal_uint16* data);
void MML1_RF_PMIC_VPA_Status_Check(void);
//VRF18
void MML1_RF_VRF18_ModeSet(kal_bool isHWMode);
void MML1_RF_VRF18_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VRF18_Enable(kal_bool vrf18_en);
void MML1_RF_VRF18_FPWM_STATUS(kal_uint32 *bitmap);
void MML1_RF_VRF18_FPWMSwitch(kal_bool isFPWM);
void MML1_RF_VRF18_FPWMSwitched_ByRAT(MML1_RF_RAT_T rat_type, kal_bool isFPWM);
void MML1_RF_VRF18_LPM_ModeSet(kal_bool isLPMHWMode);
void MML1_RF_VRF18_LPM_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VRF18_LPM_Enable(kal_bool vrf18_lpm_en);
//VRF12
void MML1_RF_VRF12_ModeSet(kal_bool isHWMode);
void MML1_RF_VRF12_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VRF12_Enable(kal_bool vrf12_en);
void MML1_RF_VRF12_FPWMSwitch(kal_bool isFPWM);
void MML1_RF_VRF12_FPWM_STATUS(kal_uint32 *bitmap);
void MML1_RF_VRF12_FPWMSwitched_ByRAT(MML1_RF_RAT_T rat_type, kal_bool isFPWM);
void MML1_RF_VRF12_LPM_ModeSet(kal_bool isLPMHWMode);
void MML1_RF_VRF12_LPM_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VRF12_LPM_Enable(kal_bool vrf12_lpm_en);
//VTCXO24
void MML1_RF_VTCXO24_ModeSet(kal_bool isHWMode);
void MML1_RF_VTCXO24_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VTCXO24_Enable(kal_bool VTCXO24_en);
void MML1_RF_VTCXO24_FPWMSwitch(kal_bool isFPWM);
void MML1_RF_VTCXO24_FPWM_STATUS(kal_uint32 *bitmap);
void MML1_RF_VTCXO24_FPWMSwitched_ByRAT(MML1_RF_RAT_T rat_type, kal_bool isFPWM);
void MML1_RF_VTCXO24_LPM_ModeSet(kal_bool isLPMHWMode);
void MML1_RF_VTCXO24_LPM_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VTCXO24_LPM_Enable(kal_bool VTCXO24_lpm_en);
void MML1_RF_VTCXO24_Switch_Enable(kal_bool VTCXO24_switch_en);
//VTCXO28
void MML1_RF_VTCXO28_ModeSet(kal_bool isHWMode);
void MML1_RF_VTCXO28_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VTCXO28_Enable(kal_bool VTCXO28_en);
void MML1_RF_VTCXO28_FPWMSwitch(kal_bool isFPWM);
void MML1_RF_VTCXO28_FPWM_STATUS(kal_uint32 *bitmap);
void MML1_RF_VTCXO28_FPWMSwitched_ByRAT(MML1_RF_RAT_T rat_type, kal_bool isFPWM);
void MML1_RF_VTCXO28_LPM_ModeSet(kal_bool isLPMHWMode);
void MML1_RF_VTCXO28_LPM_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VTCXO28_LPM_Enable(kal_bool VTCXO28_lpm_en);
//VPA
void MML1_RF_VPA_VOSEL_CWGen( kal_uint8 dc2dc_lvl, kal_uint32 *dc2dc_cw );
void MML1_RF_VPA_VOSEL(kal_uint32 volt);
void MML1_RF_VPA_FPWMSwitch(kal_bool isFPWM);
void MML1_RF_VPA_Enable(MML1_RF_RAT_T rat_type, kal_bool vpa_en);
//VMIPI
void MML1_RF_VMIPI_ModeSet(kal_bool isHWMode);
void MML1_RF_VMIPI_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VMIPI_Enable(kal_bool vmipi_en);
void MML1_RF_VMIPI_LPM_ModeSet(kal_bool isLPMHWMode);
void MML1_RF_VMIPI_LPM_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VMIPI_LPM_Enable(kal_bool vmipi_lpm_en);

//MIPI
void MML1_MIPI_POWER_ON(MML1_RF_RAT_T rat_type);
void MML1_MIPI_POWER_OFF(MML1_RF_RAT_T rat_type);

//Debug Trace
void MML1_RF_DUMP_BSILOGGER(MML1_RF_RAT_T rat_type);
void MML1_RF_DUMP_RFCW(MML1_RF_RAT_T rat_type);

//MMRF-TST
#ifdef __MTK_TARGET__
void MMRFTST_Handler(ilm_struct *ilm_ptr);
kal_uint8 MMRFTST_Trc_Debug(kal_char *info);
#else
#define MMRFTST_Handler()
#define MMRFTST_Trc_Debug()       (0)
#endif

//API for MMRFC
void MML1_RF_Mixedsys_BBRX_Setting(MMRF_ABB_BBRX_CTRL_T bbrx_ctrl);
void MML1_RF_Mixedsys_DPDADC_26MCLK_Enable(MML1_RF_RAT_T rat_type, kal_bool dpdadc_26m_en);
void MML1_RF_Mixedsys_ADCOnOff_Random_Fail_Check(MML1_RF_RAT_T rat_type);
void MML1_RF_Query_IQ_Swap_Info(sMML1_RF_IQ_SWAP_VARIABLE *iq_swap_info);
void MML1_RF_Query_IQ_Inverse_Info(sMML1_RF_IQ_INV_VARIABLE *iq_inv_info);
kal_bool MML1_RF_Is_RFBB_IQ_Swap_InDesign(void);

//fix AFC related API
void MML1_RF_SetDCXOFreqLPM(kal_uint32 lpm_div);
void MML1_RF_SetDCXOFreqFPM(MML1_RF_RAT_T rat_type, kal_uint32 fpm_div);
kal_int8 MML1_RF_Get_FixAFC_Status(MML1_RF_RAT_T rat_type);

/*  API for return Crystal on PMIC enable or disable flag */
/*  TRUE:  Crystal on PMIC is enable                      */
/*  FALSE: Crystal on PMIC is disable                     */
kal_bool MML1_RF_Is_Crystal_On_PMIC_Enable(MML1_RF_RAT_T rat_type);
MML1_RF_VCXO_TYPE_E MML1_RF_Get_VCXO_Type(MML1_RF_RAT_T rat_type);
kal_bool MML1_RF_Is_CoTMS_OnPMIC_Platform_Check(MML1_RF_RAT_T rat_type);
void MML1_RF_Get_CoTMS_Config(MML1_RF_RAT_T rat_type, MML1_CO_TMS_CONFIG_T* cotms_config);
void MML1_RF_Set_CoTMS_Config(MML1_RF_RAT_T rat_type, MML1_CO_TMS_CONFIG_T* cotms_config);
kal_uint16 MML1_RF_Get_AFCDAC(MML1_RF_RAT_T rat_type);

//Query RF temperature API
kal_uint32 MML1_RF_MEASURE_TEMPER_DAC(void);

//AFCDAC & CapID API
void MML1_RF_SetCapID(kal_uint32 capid);
void MML1_RF_SetAFCDAC(kal_uint32 afcdac);

// For speech qury RF path
kal_uint16 MML1_RF_Get_RFIC_Info(MML1_RF_RAT_T rat_type);

//Check Calibration Data Download
kal_bool MML1_RF_REPORT_CALDATA_DOWNLOAD_STATUS(void);

// NVRAM API

/*===============================================================================*/
/*   MMRF_L1CORE_ReadNvram                                                     */
/*   For Meta mode NVRAM read in L1core, as NVRAM run time activate, read/write factory/POC data.*/
/*===============================================================================*/
kal_bool MMRF_L1CORE_ReadNvram(kal_uint32 lid, kal_uint16 recordIdx, kal_uint8* dstBuf_p, kal_uint32 nvSize);

/*===============================================================================*/
/*   MMRF_L1CORE_WriteNvram                                                     */
/*   For Meta mode NVRAM write in L1core, as NVRAM run time activate, read/write factory/POC data.*/
/*===============================================================================*/
kal_bool MMRF_L1CORE_WriteNvram(kal_uint32 lid, kal_uint16 recordIdx, kal_uint8* srcBuf_p, kal_uint32 nvSize);

/*===============================================================================*/
/*   MMRF_L1CORE_SendNvReadMsg                                                     */
/*   For Normal mode NVRAM read in L1core, send NVRAM read request to NVRAM task in Pcore*/
/*===============================================================================*/
void MMRF_L1CORE_SendNvReadMsg(kal_uint32 LID, kal_uint16 recordIdx, module_type src_mod_id);

/*===============================================================================*/
/*   MMRF_L1CORE_SendNvWriteMsg                                                     */
/*   For Normal mode NVRAM write in L1core, send NVRAM write request to NVRAM task in Pcore*/
/*===============================================================================*/
void MMRF_L1CORE_SendNvWriteMsg(kal_uint32 LID, kal_uint16 recordIdx, kal_uint32 size, kal_uint8* nvData_ptr, module_type src_mod_id);

/*===============================================================================*/
/*   MMRF_L1CORE_ReadNvCnfHandler                                                     */
/*   For Normal mode NVRAM read in L1core, handle NVRAM read confirm from NVRAM task in Pcore*/
/*===============================================================================*/
kal_bool MMRF_L1CORE_ReadNvCnfHandler(kal_uint32 lid, local_para_struct *local_para_ptr
                                      , peer_buff_struct *peer_buff_ptr, kal_uint8 *dst_ptr, kal_uint32 bufSize);
/*===============================================================================*/
/*   MMRF_L1CORE_WriteNvCnfHandler                                                     */
/*   For Normal mode NVRAM write in L1core, handle NVRAM write confirm from NVRAM task in Pcore*/
/*===============================================================================*/
kal_bool MMRF_L1CORE_WriteNvCnfHandler(kal_uint32 lid, local_para_struct *local_para_ptr);

/*===============================================================================*/
/*   MMRF_L1CORE_SetNvramServiceRwCallback                                       */
/*      For Meta mode NVRAM write in L1core by MMRF task itself, as NVRAM run    */
/*   time activate, read/write factory/POC data.                                 */
/*===============================================================================*/
kal_bool MMRF_L1CORE_WriteNvram_DirectSendMsg(kal_uint32 lid, kal_uint16 recordIdx, kal_uint8* srcBuf_p, kal_uint32 nvSize);
kal_bool MMRF_L1CORE_WriteNvram_DirectSendMsgWithBackupType(kal_uint32 lid, kal_uint16 recordIdx, kal_uint8* srcBuf_p, kal_uint32 nvSize, kal_uint16 backup_type);
kal_bool MMRF_L1CORE_CheckIfWaitNvramCnf( void );
void MMRF_L1CORE_SetNvramServiceRwCallback(void (*code)(void*), void* data);

kal_bool MML1_RF_IsRecordTxPowerEnable(void);
void MML1_RF_RecordTxPower(MMRF_TxPowerRecord_RAT_T rat, kal_int8 txPower);

// VS1
void MML1_RF_VS1_VOSEL_MODESET_CWGen(MML1_RF_VS1_CTRL_T *mml1_rf_vs1_ctrl);
void MML1_RF_VS1_SW_MODE_VOSEL(kal_uint16 volt);
void MML1_RF_VS1_HW_MODE_VOSEL(kal_uint16 volt);

#if defined(__TX_POWER_OFFSET_SUPPORT__) || defined(__SAR_TX_POWER_BACKOFF_SUPPORT__)
void MML1_SWTP_GetTableIdx(sSWTP_GetTableIdx *swtp_param);
void MML1_RF_Update_TxPowerOffsetTableIdxToC2K( kal_uint32 tableIdx );
void MML1_RF_SWTP_Init(void);
#endif

#if IS_MMRF_MIPI_HW_CHECK_SUPPORT
void MML1_MIPI_check_HW_device(ilm_struct *ilm_ptr);
#endif

//switch DCXO operating mode
void MML1_DCXO_Operating_Mode_Switch( MMRF_DCXO_MODE_E mode );

kal_uint32 MML1_RF_Convert_MML1_BSI_Port_To_MIPI( kal_uint32 portIndex );

kal_int16  MMRF_AP_Sensor_Relative_Feature_Query_Status(MMRF_AP_SENSOR_RELATIVE_OP_CODE_E OP_code, MMRF_AP_SENSOR_RELATIVE_RAT_E rat);
kal_bool   MMRF_AP_Sensor_Relative_Feature_IS_Need_L1C_GAP(MMRF_AP_SENSOR_RELATIVE_OP_CODE_E OP_code, kal_int16 scenario, MMRF_AP_SENSOR_RELATIVE_RAT_E rat);
   #ifdef __MTK_TARGET__
void       MMRF_AP_Sensor_Relative_Feature_Handler(ilm_struct *ilm_ptr);
   #else
#define MMRF_AP_Sensor_Relative_Feature_Handler()
   #endif

#endif /* End of #ifndef _MML1_RF_INTERFACE_H_ */

