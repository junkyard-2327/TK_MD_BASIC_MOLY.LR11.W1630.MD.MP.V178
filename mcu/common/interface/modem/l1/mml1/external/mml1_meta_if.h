/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*******************************************************************************
 * Filename:
 * ---------
 *   mml1_meta_if.h
 *
 * Project:
 * --------
 *   TK6291
 *
 * Description:
 * ------------
 *  MMRF test mode specific definitions for synchronizing with HOST tool
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 02 18 2016 arthur.hung
 * [MOLY00133503] [UMOLY][DPD] DPD code update
 * [ET and DPD and SP3] Code changes with ET feature is enabled on Everest Set-1.
 *
 * 02 02 2016 wei-shou.yang
 * [MOLY00133503] [UMOLY][DPD] DPD code update
 * DPD + ET code update to MP3
 *
 * 01 04 2016 kirk.chao
 * [MOLY00133503] [UMOLY][DPD] DPD code update
 * [DPD] 20150104 dpd code update
 *
 * 11 30 2015 kai-wei.chou
 * [MOLY00133503] [UMOLY][DPD] DPD code update
 * 	
 * 	dpd check in LR11
 *
 * 10 21 2015 yu-hsuan.sung
 * [MOLY00146002] [MML1TST]add world mode id capability
 *
 * 10 14 2015 wei-shou.yang
 * [MOLY00133503] [UMOLY][DPD] DPD code update
 * Fix build warning
 *
 * 10 12 2015 wei-shou.yang
 * [MOLY00133503] [UMOLY][DPD] DPD code update
 * 2th code merge from test CBR to LR11
 *
 * 09 15 2015 mars.chang
 * [MOLY00141939] [MT6755_SP] TAS feature
 * .
 *
 * 08 03 2015 wei-shou.yang
 * [MOLY00133503] [UMOLY][DPD] DPD code update
 * DPD code update
 *
 * 07 06 2015 samuel.yang
 * [MOLY00126228] [MMRF] Add mechanism for RF self-K to print debug info during factory calibration
 * .
 *
 * 07 03 2015 samuel.yang
 * [MOLY00122885] [TK6291] Modify comment and remove redundant DPD/CIM3 capability from LTE
 * .
 *
 * 05 17 2015 samuel.yang
 * [MOLY00114080] [TK6291] Add mechanism for delivering string of self-cal to FT
 * .
 *
 * 05 13 2015 samuel.yang
 * [MOLY00113424] [TK6291] To prevent xL1sim from building error
 * .
 *
 * 05 07 2015 samuel.yang
 * [MOLY00111833] [TK6291] Phase in MMRF TST related modifications
 * .
 *
 ****************************************************************************/

#ifndef __MML1_META_IF_H__
#define __MML1_META_IF_H__

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "kal_general_types.h"
#ifndef __LTE_L1SIM__
#include "ft_msg_common.h"
#endif
#include "el1d_meta_if.h"
#include "el1d_rf_custom_data.h"
#include "el1d_rf_et_custom_data.h"

/*******************************************************************************
 * Constant
 ******************************************************************************/
#define MMRF_MAX_BAND_NUM                         (21)

// FMC is the abbreviation of "Factory Mode Capability"
#define MMRF_FMC_NULL_SETTING                     (0x0)  // default
#define MMRF_FMC_CAPABLE                          (0x1)  // item capable
#define MMRF_FMC_MANDATORY                        (0x1)  // item mandatory

#define MMRF_MAX_RF_SELF_K_LID_COUNT              (64)
#define MMRF_MAX_RF_SELF_K_STRING_LENGTH          (64)
#define MMRF_MAX_RF_SELF_K_DBG_INFO_COUNT         (128)

#define MAX_MMRF_ET_NUM_BAND                      (31)
#define MAX_MMRF_ET_NUM_SUBBAND                   (8)
#define MAX_MMRF_ET_NUM_RB_IDX                    (16)
#define MAX_MMRF_ET_LUT_PWR_NUM                   (32)
#define MAX_MMRF_ET_NUM_CBW                       (6)
#define MAX_MMRF_ET_NUM_TEMP                      (8)

/*******************************************************************************
 * Enumeration
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_CMD_CHECK_IF_FUNC_EXIST             = 0,
   MMRF_TEST_CMD_GET_RF_CAPABILITY               = 1,
   MMRF_TEST_CMD_START_DPD_FAC_CAL               = 2,
   MMRF_TEST_CMD_GET_DPD_FAC_RESULT              = 3,
   MMRF_TEST_CMD_SET_DPD_FAC_RESULT              = 4,
   MMRF_TEST_CMD_DPD_FAC_EN_DIS                  = 5,
   MMRF_TEST_CMD_START_CIM3_FAC_CAL              = 6,
   MMRF_TEST_CMD_GET_CIM3_FAC_RESULT             = 7,
   MMRF_TEST_CMD_SET_CIM3_FAC_RESULT             = 8,
   MMRF_TEST_CMD_CIM3_FAC_EN_DIS                 = 9,
   MMRF_TEST_CMD_START_RF_SELF_CAL               = 10,
   MMRF_TEST_CMD_GET_RF_SELF_CAL_RESULT          = 11,
   MMRF_TEST_CMD_SET_RF_SELF_CAL_RESULT          = 12,
   MMRF_TEST_CMD_GET_RF_SELF_CAL_RESULT_LEN      = 13,
   MMRF_TEST_CMD_START_POST_RF_SELF_CAL          = 14,
   MMRF_TEST_CMD_GET_POST_RF_SELF_CAL_RESULT     = 15,
   MMRF_TEST_CMD_SET_POST_RF_SELF_CAL_RESULT     = 16,
   MMRF_TEST_CMD_GET_POST_RF_SELF_CAL_RESULT_LEN = 17,
   MMRF_TEST_CMD_GET_RF_SELF_CAL_DBG_INFO        = 18,
   MMRF_TEST_CMD_GET_RF_SELF_CAL_RESULT_KEY      = 19,
   MMRF_TEST_CMD_GET_POST_RF_SELF_CAL_RESULT_KEY = 20,
   MMRF_TEST_CMD_START_DPD_PA_PROFILE_FAC_CAL    = 21,
   MMRF_TEST_CMD_GET_DPD_PA_PROFILE_FAC_RESULT   = 22,
   MMRF_TEST_CMD_SET_DPD_PA_PROFILE_FAC_RESULT   = 23,
   MMRF_TEST_CMD_GET_DPD_CIM3_LUT_CONFIG         = 24,
   MMRF_TEST_CMD_FORCE_TAS                       = 25,
   MMRF_TEST_CMD_START_ETCAL                     = 26,
   MMRF_TEST_CMD_GET_ETCAL_SETTING               = 27,
   MMRF_TEST_CMD_SET_ETCAL_SETTING               = 28,
   MMRF_TEST_CMD_CHECK_ET_PATH_DELAY_SEARCH      = 29,
   MMRF_TEST_CMD_START_ET_PATH_DELAY_SEARCH      = 30,
   MMRF_TEST_CMD_ET_MODE_SETTING                 = 31,
   MMRF_TEST_CMD_SET_TOOL_USAGE_TO_L1            = 32,
   MMRF_TEST_CMD_CHECK_DPD_PATH_DELAY_SEARCH     = 33,
   MMRF_TEST_CMD_START_DPD_PATH_DELAY_SEARCH     = 34,
   MMRF_TEST_CMD_END,
   MMRF_TEST_CMD_MAX                             = 0x7FFFFFFF

} MMRfTestCmdType;


/*******************************************************************************
 * DPD PA Gain Calibration Start Command
 ******************************************************************************/
 typedef enum
{
   MMRF_TEST_DPD_PA_PROFILE_ERROR   = 0,
   MMRF_TEST_DPD_PA_PROFILE_SUCCESS = 1

} MMRfTestDPDPaProfileFacStatusType; /* The enum for dpd_pa_status */

typedef enum
{
   /* */
   MMRF_TEST_DPD_PA_PROFILE_OUT_RANGE = 0

} MMRfTestDPDPaProfileFacErrType; /* The enum for dpd_pa_error_code */

typedef struct
{
   kal_uint16  rat_idx;
   /* Tool will send DPD factory start command by band, rf_band_idx = 1 means band 1, rf_band_idx = 3  means band 3 and etc. */
   kal_uint16  rf_band_idx;
   /* Since DPD PA gain will reuse the temperature and subband PA gain compensation value calibrated by APT mode, so we need to
      know which channel(frequency) is the APT mode PA gain reference and calibrate the DPD PA gain with that channel */
   kal_uint16 apt_ref_channel;

}MMRfTestCmdDPDPaProfileFacStartDim;

typedef struct
{
   /* The value will be one of the element in MMRfTestDPDPaProfileFacStatusType */
   kal_uint16  dpd_pa_status;

   /* The value will be one of the element in MMRfTestDPDPaProfileFacErrType */
   kal_uint16  dpd_pa_error_code;

   /* Return MMRfTestCmdDPDPaProfileFacStartDim for tool debug */
   MMRfTestCmdDPDPaProfileFacStartDim  dpd_pa_start_dim;

} MMRfTestResultDPDPaProfileStartFacRpt;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestCmdDPDPaProfileFacStartDim     *p_cmd; 
   MMRfTestResultDPDPaProfileStartFacRpt  *p_rpt;
   
} MMRfTestDPDPaProfileStartFacCmdRptMix;

/*******************************************************************************
 * DPD PA Gain Calibration Get/Set Command (MMRF_TEST_CMD_GET/SET_DPD_FAC_RESULT)
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_DPD_PA_PROFILE           = 0,
   MMRF_TEST_DPD_PA_ALGO_PARAM_RESULT = 1
}MMRfTestDPDPaProfileFacCmdType;

typedef struct
{
   kal_uint16  rat_idx;

   /* Tool will send DPD PA gain factory set/get command by band, rf_band_idx = 1 means band 1, rf_band_idx = 3 means band 3 and etc. */
   kal_uint16  rf_band_idx;

   kal_uint16  pa_param_type;

   kal_uint16  signal_path/*default =0, hrm mode =1, filter mode =2*/;
}MMRfTestDPDPaProfileFacSetGetDim;

typedef struct
{
   /* The value will be one of the element in MMRfTestDPDPaProfileFacStatusType */
   kal_uint16  dpd_pa_status;

   /* The value will be one of the element in MMRfTestDPDPaProfileFacErrType */
   kal_uint16  dpd_pa_error_code;
   
   MMRfTestDPDPaProfileFacSetGetDim  dpd_pa_set_get_dim;
   
} MMRfTestResultDPDPaProfileGetFacRpt;

typedef struct
{
   /* The value will be one of the element in MMRfTestDPDPaProfileFacStatusType */
   kal_uint16  dpd_pa_status;

   /* The value will be one of the element in MMRfTestDPDPaProfileFacErrType */
   kal_uint16  dpd_pa_error_code;

   /* Return MMRfTestDPDPaProfileFacSetGetDim for tool debug */
   MMRfTestDPDPaProfileFacSetGetDim  dpd_pa_set_get_dim;

} MMRfTestResultDPDPaProfileSetFacRpt;

typedef struct
{
   /* PA Control */
   kal_uint8 paControlLevel; /* 2~8 */
   kal_uint8 calRoomTempIdx;
   kal_int16 hysteresisStart0;
   kal_int16 hysteresisEnd0;
   kal_int16 hysteresisStart1;
   kal_int16 hysteresisEnd1;
   kal_uint8 paMode[MAX_DPD_PA_GAIN_NUM]; /* 0:high, 1:middle, 2:low */
   kal_int16 pRf[MAX_DPD_PA_GAIN_NUM];
   kal_uint16 paGain[MAX_DPD_PA_GAIN_NUM];
   kal_uint8 dc2dcLevel[MAX_DPD_PA_GAIN_NUM]; /* voltage map by chip, TODO */
   kal_uint16 vBiasDac[MAX_DPD_PA_GAIN_NUM];
   kal_uint8 vm0[MAX_DPD_PA_GAIN_NUM];
   kal_uint8 vm1[MAX_DPD_PA_GAIN_NUM];
   /* TX Compensation */
   kal_uint16 ulFrequency[CAL_EARFCN_SECTION_LTE];//100kHz unit
   kal_int16 paGainHigh[MAX_DPD_PA_CAL_TEMP_SECTION][CAL_EARFCN_SECTION_LTE];
   kal_int16 paGainMiddle[MAX_DPD_PA_CAL_TEMP_SECTION][CAL_EARFCN_SECTION_LTE];
   kal_int16 paGainLow[MAX_DPD_PA_CAL_TEMP_SECTION][CAL_EARFCN_SECTION_LTE];
   kal_int16 couplerLossHigh;
   kal_int16 couplerLossMiddle;
   kal_int16 couplerLossLow;
   kal_int16 powerDetectorHigh[MAX_DPD_PA_CAL_TEMP_SECTION][CAL_EARFCN_SECTION_LTE];
   kal_int16 powerDetectorMiddle[MAX_DPD_PA_CAL_TEMP_SECTION][CAL_EARFCN_SECTION_LTE];
   kal_int16 powerDetectorLow[MAX_DPD_PA_CAL_TEMP_SECTION][CAL_EARFCN_SECTION_LTE];
   /* Only band28 has split band, but for the consistency of the element [LTE BANDx DPD PA] in ini file
   , we let all band have the split band struct, dpd_tr[0] and dpd_tr[1] are both valid for band28
   , for the other band, only dpd_tr[0] is valid */
   MMRfTestDpdTrAbsolute dpd_tr[MAX_DPD_DELAY_K_B28_SPLIT_BAND_NUM];

}MMRfTestDPDPaProfileFacParam;

typedef struct
{
   /* This flag will be 1 after DPD PA factory cal done(this flag is by band) */
   kal_uint16 dpd_pa_cal_done;
   
   kal_int16 dpdPaImplicitArray[DPD_PA_IMPLICIT_NUM]; 
   
} MMRfTestDPDPaFacParamResult;

typedef union
{  
   MMRfTestDPDPaProfileFacParam dpd_pa_fac_param;
   MMRfTestDPDPaFacParamResult  dpd_pa_fac_tool_result;
} MMRfTestDPDPaProfileFacIO;

typedef struct
{
   MMRfTestDPDPaProfileFacSetGetDim  dpd_pa_fac_set_get_dim;
   MMRfTestDPDPaProfileFacIO         *p_dpd_pa_fac_io;

}MMRfTestDPDPAProfileFacSetInfo;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestDPDPAProfileFacSetInfo       cmd;
   MMRfTestResultDPDPaProfileSetFacRpt  *p_rpt;

}MMRfTestDPDPaProfileSetFacCmdRptMix;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestDPDPAProfileFacSetInfo       cmd;
   MMRfTestResultDPDPaProfileGetFacRpt  *p_rpt;

}MMRfTestDPDPaProfileGetFacCmdRptMix;

/*******************************************************************************
 * DPD Start Command (MMRF_TEST_CMD_START_DPD_FAC_CAL)
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_DPD_ERROR   = 0,
   MMRF_TEST_DPD_SUCCESS = 1

} MMRfTestDPDFacStatusType; /* The enum for dpd_status */

typedef enum
{
   /* Inform tool the LUT value from set command is out of FXP range */
   MMRF_TEST_DPD_OUT_RANGE = 0

} MMRfTestDPDFacErrType; /* The enum for dpd_error_code */

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   kal_uint16  rat_idx;

   /* Tool will send DPD factory start command by band, rf_band_idx = 1 means band 1, rf_band_idx = 1 means band 3 and etc. */
   kal_uint16  rf_band_idx;

} MMRfTestCmdDPDFacStartDim;

typedef struct
{
   /* The value will be one of the element in MMRfTestDPDFacStatusType */
   kal_uint16  dpd_status;

   /* The value will be one of the element in MMRfTestDPDFacErrType */
   kal_uint16  dpd_error_code;

   /* Return MMRfTestCmdDPDFacStartDim for tool debug */
   MMRfTestCmdDPDFacStartDim  dpd_start_dim; 

} MMRfTestResultDPDStartFacRpt;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestCmdDPDFacStartDim     *p_cmd;
   MMRfTestResultDPDStartFacRpt  *p_rpt;      

} MMRfTestDPDStartFacCmdRptMix;

/*******************************************************************************
 * DPD Get/Set Command (MMRF_TEST_CMD_GET/SET_DPD_FAC_RESULT)
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_DPD_ALGO_PARAM        = 0,
   MMRF_TEST_DPD_AM                = 1,
   MMRF_TEST_DPD_PM                = 2,
   MMRF_TEST_DPD_ALGO_PARAM_RESULT = 3
} MMRfTestDPDFacCmdType;

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   kal_uint16  rat_idx;

   /* Tool will send DPD factory set/get command by band, rf_band_idx = 1 means band 1, rf_band_idx = 1 means band 3 and etc. */
   kal_uint16  rf_band_idx;

   /* Tool will use this variable to tell modem what the type of information it want,
      for instance, am_pm_param_type = ERF_TEST_DPD_ALGO_PARAM means the command to set/get
      dpd_fac_tool_set in ERfTestDPDFacIO */
   kal_uint16  am_pm_param_type;

   kal_uint16  signal_path/*default =0, hrm mode =1, filter mode =2*/;
} MMRfTestDPDFacSetGetDim;

typedef struct
{
   /* DPD AM LUT for 1 band */
   MMRfTestDPDAMLutSubBand  am_lut_subband[MAX_FHC_TX_FREQ_NUM_EX];

   /* DPD PM LUT for 1 band */
   MMRfTestDPDPMLutSubBand  pm_lut_subband[MAX_FHC_TX_FREQ_NUM_EX];

}MMRfTestDPDLutPerBand;

typedef struct
{
   /* This flag will be 1 after DPD factory cal done */
   kal_uint16 dpd_cal_done;

   kal_int16 dpdImplicitArray[DPD_IMPLICIT_NUM];

}MMRfTestDPDFacParamResult;

/* union for meta tool to send one type of parameters at one time (too large to send all type at one time) */
typedef union
{
   /* DPD_TODO: The algorithm related parameters to be set/got */
   MMRfTestDPDFacParamToolSet  dpd_fac_tool_set;

   /* The 1 band AM LUT to be set/got */
   MMRfTestDPDAMLutSubBand     am_lut_subband[MAX_FHC_TX_FREQ_NUM_EX];

   /* The 1 band PM LUT to be set/got */
   MMRfTestDPDPMLutSubBand     pm_lut_subband[MAX_FHC_TX_FREQ_NUM_EX];

   MMRfTestDPDFacParamResult   dpd_fac_tool_result;

} MMRfTestDPDFacIO;

typedef struct
{
   MMRfTestDPDFacSetGetDim  dpd_fac_set_get_dim;
   MMRfTestDPDFacIO        *p_dpd_fac_io;

}MMRfTestDPDFacSetInfo;

typedef struct
{
   /* The value will be one of the element in MMRfTestDPDFacStatusType */
   kal_uint16  dpd_status;

   /* The value will be one of the element in MMRfTestDPDFacErrType */
   kal_uint16  dpd_error_code;

   /* Return MMRfTestDPDFacSetGetDim for tool debug */
   MMRfTestDPDFacSetGetDim  dpd_set_get_dim;

} MMRfTestResultDPDGetFacRpt;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestDPDFacSetInfo        cmd;
   MMRfTestResultDPDGetFacRpt  *p_rpt;

} MMRfTestDPDGetFacCmdRptMix;

typedef struct
{
   /* The value will be one of the element in MMRfTestDPDFacStatusType */
   kal_uint16  dpd_status;

   /* The value will be one of the element in MMRfTestDPDFacErrType */
   kal_uint16  dpd_error_code;

   /* Return MMRfTestDPDFacSetGetDim for tool debug */
   MMRfTestDPDFacSetGetDim  dpd_set_get_dim;

} MMRfTestResultDPDSetFacRpt;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestDPDFacSetInfo        cmd;
   MMRfTestResultDPDSetFacRpt  *p_rpt;

} MMRfTestDPDSetFacCmdRptMix;

typedef struct
{
   /* Algorithm parameter */
   kal_uint16  dpd_meas_ofst_reg; /* U8.0 */
   kal_uint16  n_iter_am;
   kal_uint16  am_avg_num_lg2;
   kal_uint16  pm_avg_num_lg2; /* U3.0 */
   kal_uint16  am_delta; /* U3.11 */
   kal_uint16  update_algo; /* 0: lonely update, 1: predictive update */
   kal_int16   ppa_i_peak_dbm[MAX_FHC_TX_FREQ_NUM_EX];   
   kal_int16   gbb_db[MAX_FHC_TX_FREQ_NUM_EX]; /* S7.5 */
   kal_int16   gvga_rf_db[MAX_FHC_TX_FREQ_NUM_EX]; /* S7.5 */
   kal_int16   g_dpd_bb_db[MAX_FHC_TX_FREQ_NUM_EX]; /* S7.5 */
   kal_int16   g_pa_cal_db[MAX_FHC_TX_FREQ_NUM_EX];   
   kal_uint16  am_dpd_max[MAX_FHC_TX_FREQ_NUM_EX]; /* U1.15 */
   kal_uint16  am_tar_idx_a[MAX_FHC_TX_FREQ_NUM_EX]; /* range:0~31 */
   kal_uint16  am_tar_idx_b[MAX_FHC_TX_FREQ_NUM_EX]; /* range:0~31 */
   kal_uint16  am_tar_idx_c[MAX_FHC_TX_FREQ_NUM_EX]; /* range:0~31 */
   kal_uint16  pm_ref_idx_k[MAX_FHC_TX_FREQ_NUM_EX]; /* range:0~31 */
   kal_int16   gain_var_threshold[MAX_FHC_TX_FREQ_NUM_EX]; /* S0.10 */

}MMRfTestDPDFacAlgoParamNVRAM;

/*******************************************************************************
 * DPD En/Dis Command (MMRF_TEST_CMD_DPD_FAC_EN_DIS)
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_DPD_DIS = 0,
   MMRF_TEST_DPD_EN  = 1

}MMRfTestDPDFacEnDisType; /* The enum for dpd_switch */

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   kal_uint16  rat_idx;

   /* The value will be one of the element in MMRfTestDPDFacEnDisType */
   kal_uint16  dpd_switch;

}MMRfTestCmdDPDFacEnDis;

typedef struct
{
   /* The value will be one of the element in MMRfTestDPDFacStatusType */
   kal_uint16  dpd_switch_status;

   /* The value will be one of the element in MMRfTestDPDFacErrType */
   kal_uint16  dpd_switch_error_code;

   /* Return MMRfTestCmdDPDFacEnDis for tool debug */
   MMRfTestCmdDPDFacEnDis  dpd_switch_cmd;

} MMRfTestResultDPDFacEnDisRpt;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestCmdDPDFacEnDis        *p_cmd;      
   MMRfTestResultDPDFacEnDisRpt  *p_rpt;

} MMRfTestDPDFacSwitchCmdRptMix;

/*******************************************************************************
 * CIM3 Start Command (MMRF_TEST_CMD_START_CIM3_FAC_CAL)
 ******************************************************************************/
typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   kal_uint16  rat_idx;

   /* Tool will send CIM3 factory start command by band, rf_band_idx = 1 means band 1, rf_band_idx = 1 means band 3 and etc. */
   kal_uint16  rf_band_idx;

} MMRfTestCmdCIM3FacStartDim;

typedef enum
{
   MMRF_TEST_CIM3_ERROR   = 0,
   MMRF_TEST_CIM3_SUCCESS = 1

}MMRfTestCIM3FacStatusType; /* The enum for cim3_status */

typedef enum
{
   MMRF_TEST_CIM3_OUT_RANGE = 0

}MMRfTestCIM3FacErrType; /* The enum for cim3_error_code */

typedef struct
{
   /* The value will be one of the element in MMRfTestCIM3FacStatusType */
   kal_uint16  cim3_status;

   /* The value will be one of the element in ERfTestCIM3FacErrType */
   kal_uint16  cim3_error_code;

   /* Return MMRfTestCmdCIM3FacStartDim for tool debug */
   MMRfTestCmdCIM3FacStartDim  cim3_start_dim;

}MMRfTestResultCIM3StartFacRpt;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestCmdCIM3FacStartDim     *p_cmd;   
   MMRfTestResultCIM3StartFacRpt  *p_rpt;   

}MMRfTestCIM3StartFacCmdRptMix;

/*******************************************************************************
 * CIM3 Get/Set Command (MMRF_TEST_CMD_GET/SET_CIM3_FAC_RESULT)
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_CIM3_ALGO_PARAM = 0,
   MMRF_TEST_CIM3_LUT        = 1

}MMRfTestCIM3FacCmdType;

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   kal_uint16  rat_idx;

   /* Tool will send CIM3 factory set/get command by band, rf_band_idx = 1 means band 1, rf_band_idx = 1 means band 3 and etc. */
   kal_uint16  rf_band_idx;

   /* Tool will use this variable to tell modem what the type of information it want,
      for instance, am_pm_param_type = MMRF_TEST_CIM3_ALGO_PARAM means the command to set/get
      cim3_fac_set in ERfTestCIM3FacIO */
   kal_uint16  lut_param_type;

   kal_uint16  signal_path/*default =0, hrm mode =1, filter mode =2*/;
} MMRfTestCIM3FacSetGetDim;

typedef struct
{
   /* CIM3 LUT for full band */
   MMRfTestCIM3LutPerBand  cim3_lut_per_band[MMRF_MAX_BAND_NUM];

} MMRfTestCIM3LutFullBand;

/* union for meta tool to send one type of parameters at one time (too large to send all type at one time) */
typedef union
{
   /* CIM3_TODO: The algorithm related parameters to be set/got */
   MMRfTestCIM3FacParamSet  cim3_fac_set;

   /* The 1 band CIM3 LUT to be set/got */
   MMRfTestCIM3LutPerBand   cim3_lut_per_band;

} MMRfTestCIM3FacIO;

typedef struct
{
   MMRfTestCIM3FacSetGetDim  cim3_fac_set_get_dim;
   MMRfTestCIM3FacIO        *p_cim3_fac_io;

}MMRfTestCIM3FacSetInfo;

typedef struct
{
   /* The value will be one of the element in MMRfTestCIM3FacStatusType */
   kal_uint16  cim3_status;

   /* The value will be one of the element in ERfTestCIM3FacErrType */
   kal_uint16  cim3_error_code;

   /* Return MMRfTestCIM3FacSetGetDim for tool debug */
   MMRfTestCIM3FacSetGetDim  cim3_set_get_dim; 

} MMRfTestResultCIM3GetFacRpt;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestCIM3FacSetInfo        cmd;
   MMRfTestResultCIM3GetFacRpt  *p_rpt;

} MMRfTestCIM3GetFacCmdRptMix;

typedef struct
{
   /* The value will be one of the element in MMRfTestCIM3FacStatusType */
   kal_uint16  cim3_status;

   /* The value will be one of the element in ERfTestCIM3FacErrType */
   kal_uint16  cim3_error_code;

   /* Return MMRfTestCIM3FacSetGetDim for tool debug */
   MMRfTestCIM3FacSetGetDim  cim3_set_get_dim;

} MMRfTestResultCIM3SetFacRpt;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestCIM3FacSetInfo        cmd;
   MMRfTestResultCIM3SetFacRpt  *p_rpt;

} MMRfTestCIM3SetFacCmdRptMix;

typedef struct
{
   /* Algorithm parameters */
   kal_int16  cim3_meas_ofst_reg;
   kal_int16  cim3_meas_sample_reg;
   kal_int16  n_iter_cim3_gain;
   kal_int16  n_iter_cim3_phase[MAX_FHC_TX_FREQ_NUM_EX];
   kal_int16  cim3_alpha_delta[MAX_FHC_TX_FREQ_NUM_EX];
   kal_int16  cim3_phase_delta[MAX_FHC_TX_FREQ_NUM_EX];
   kal_int16  cim3_phase_ini[MAX_FHC_TX_FREQ_NUM_EX];
   kal_int32  cim3_tone_nco_rot[MAX_FHC_TX_FREQ_NUM_EX];
   
}MMRfTestCIM3FacAlgoParamNVRAM;

/*******************************************************************************
 * CIM3 En/Dis Command (MMRF_TEST_CMD_CIM3_FAC_EN_DIS)
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_CIM3_DIS = 0,
   MMRF_TEST_CIM3_EN  = 1

}MMRfTestCIM3FacEnDisType; /* The enum for cim3_switch */

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   kal_uint16  rat_idx;

   /* The value will be one of the element in MMRfTestCIM3FacEnDisType */
   kal_uint16  cim3_switch;

}MMRfTestCmdCIM3FacEnDis;

typedef struct
{
   /* The value will be one of the element in MMRfTestCIM3FacStatusType */
   kal_uint16  cim3_switch_status;

   /* The value will be one of the element in ERfTestCIM3FacErrType */
   kal_uint16  cim3_switch_error_code;

   /* Return MMRfTestCmdCIM3FacEnDis for tool debug */
   MMRfTestCmdCIM3FacEnDis  cim3_switch_cmd;   

}MMRfTestResultCIM3FacEnDisRpt;

/* There is only one function argument in xL1sim, so we need to merge the command and report into one structure */
typedef struct
{
   MMRfTestCmdCIM3FacEnDis        *p_cmd;
   MMRfTestResultCIM3FacEnDisRpt  *p_rpt;    

}MMRfTestCIM3FacSwitchCmdRpt;

/*******************************************************************************
 * DPD and CIM3 RF tool capability common part
 ******************************************************************************/
typedef struct
{
   /* rf_band_idx = 1 means band 1, rf_band_idx = 1 means band 3 and etc. */
   kal_uint16  rf_band_idx;

   /* Report how many subband does the band rf_band_idx has */
   kal_uint16  support_subband_num;

} MMRfSubBandInfo;

typedef struct
{
   /* There are 40 and 60 gain combinations for DPD and CIM3 respectively, 
      pa_idx and pga_idx indicates the PA and PGA index of each gain combination */
   kal_uint16  pa_idx;
   
   kal_uint16  pga_idx;   

} MMRfEachLutIdxMapInfo;

/*******************************************************************************
 * DPD RF tool capability
 ******************************************************************************/
typedef struct
{
   /* The maximum of the even/odd of the register TXDFE_DPD_AM_LUT_x in TXDFE */
   kal_uint16  dpd_am_value_check_max;

   /* The minimum of the even/odd of the register TXDFE_DPD_AM_LUT_x in TXDFE */
   kal_uint16  dpd_am_value_check_min;

   /* The maximum of the even/odd of the register TXDFE_DPD_PM_LUT_x in TXDFE */
   kal_int16   dpd_pm_value_check_max;

   /* The minimum of the even/odd of the register TXDFE_DPD_PM_LUT_x in TXDFE */
   kal_int16   dpd_pm_value_check_min;

} MMRfDPDValueRangeCheck;

typedef struct
{
   /* The number of DPD factory gain combination(default:40) */
   kal_uint16  support_gain_num;

   /* The number of PA setting for DPD(default:8) */
   kal_uint16  support_pa_setting_num;

   /* There is a PGA and a PA setting for each one of support_gain_num. EX: support_gain_num is 40
      , support_pa_setting_num is 8, pga_max_num_for_each_pa[] is 5 */
   kal_uint16  pga_max_num_for_each_pa[MAX_DPD_PA_GAIN_NUM];

   /* The number of subband for each support band */
   MMRfSubBandInfo  subband_info[MMRF_MAX_BAND_NUM];

   /* The range of some parameters used for checking the input from user */
   MMRfDPDValueRangeCheck  value_range_check;

   /* Indicates the PA and PGA index of each DPD gain combination(one of MAX_DPD_AM_LUT_GAIN_NUM)*/
   MMRfEachLutIdxMapInfo  each_lut_idx_info[MAX_DPD_AM_LUT_GAIN_NUM];

} MMRfDPDLutConfig;

/*******************************************************************************
 * CIM3 RF tool capability
 ******************************************************************************/
typedef struct
{
   /* The maximum of the A1/A2 of the register TXDFE_DPD_PM_LUT_x in TXDFE */
   kal_int16  cim3_value_check_max;
	
   /* The minimum of the A1/A2 of the register TXDFE_DPD_PM_LUT_x in TXDFE */
   kal_int16  cim3_value_check_min;

} MMRfCIM3ValueRangeCheck;

typedef struct
{
   /* The number of CIM3 factory gain combination(default:60) */
   kal_uint16  support_gain_num;

   /* The number of PA setting for CIM3(default:8) */
   kal_uint16  support_pa_setting_num;

   /* There is a PGA and a PA setting for each one of support_gain_num. EX: support_gain_num is 60
      , support_pa_setting_num is 8, pga_max_num_for_each_pa[] is 8(some PA with more PGA) */
   kal_uint16  pga_max_num_for_each_pa[MAX_CIM3_PA_GAIN_NUM];

   /* The number of subband for each support band */
   MMRfSubBandInfo  subband_info[MMRF_MAX_BAND_NUM];

   /* The range of some parameters used for checking the input from user */
   MMRfCIM3ValueRangeCheck  value_range_check;

   /* Indicates the PA and PGA index of each CIM3 gain combination(one of MAX_CIM3_LUT_GAIN_NUM)*/
   MMRfEachLutIdxMapInfo  each_lut_idx_info[MAX_CIM3_LUT_GAIN_NUM];   

} MMRfCIM3LutConfig;

/*******************************************************************************
 * DPD and CIM3 RF tool get capability interface
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_GET_CONFIG_ERROR   = 0,
   MMRF_TEST_GET_CONFIG_SUCCESS = 1

}MMRfTestDPDCIM3GetLutConfigStatusType; /* The enum for cim3_status */

typedef enum
{
   DPD_LUT  = 0,
   CIM3_LUT = 1   	

} MMRfLutConfigType;

typedef struct
{
   /* bitmap:(0|0|Lf|Lt|W|C|T|G) */
   kal_uint16  rat_idx;   

   /* lut_type will be one of the value in MMRfLutConfigType */
   kal_uint16  lut_type;

} MMRfTestCmdGetLutConfig;

typedef union
{
   MMRfDPDLutConfig   dpd_lut_config;
   
   MMRfCIM3LutConfig  cim3_lut_config;

}MMRfDPDCIM3LutConfig;

typedef struct
{
   MMRfTestCmdGetLutConfig  config;
   MMRfDPDCIM3LutConfig    *p_lut_config;

} MMRfTestDPDCIM3GetLutConfigInfo;

typedef struct
{
   /* The value will be one of the element in MMRfTestCIM3FacStatusType */
   kal_uint16  get_config_status;

   /* The value will be one of the element in ERfTestCIM3FacErrType */
   kal_uint16  get_config_error_code; 

   /* Parameters for showing DPD/CIM3 LUT on RF tool */
   MMRfTestCmdGetLutConfig  config;

} MMRfTestResultLutConfigRpt;

typedef struct
{
   MMRfTestDPDCIM3GetLutConfigInfo  cmd;
   MMRfTestResultLutConfigRpt      *p_rpt;

} MMRfTestLutConfigCmdRptMix;

/*******************************************************************************
 * DPD PATH DELAY CHECK GET Command
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_DPD_PATH_DELAY_CHECK_ERROR   = 0,
   MMRF_TEST_DPD_PATH_DELAY_CHECK_SUCCESS = 1

} MMRfTestDpdPathDelayCheckStatusType;

typedef enum
{

   MMRF_TEST_DPD_PATH_DELAY_CHECK_OUT_RANGE = 0

} MMRfTestDpdPathDelayCheckErrType;

typedef struct
{
   kal_uint16 rat_idx;

} MMRfTestCmdDpdPathDelayCheck;

typedef struct
{
   kal_uint16 freq[MAX_DPD_DELAY_K_SUBBAND_NUM][MMRF_MAX_LTE_CBW_NUM];

} MMRfTestDpdPathDelaySubbandFreq;

typedef struct
{
   /* to check if DPD done already */
   kal_uint32                      dpd_cal_done_flag[LTE_MAX_TX_COMP_ROUTE_NUM+LTE_BYPASS_MAX_SUPPORT_BAND_NUM+LTE_TX_HRM_MAX_SUPPORT_BAND_NUM];
   
   /* band indicator */
   kal_uint16                      band[LTE_MAX_TX_COMP_ROUTE_NUM+LTE_BYPASS_MAX_SUPPORT_BAND_NUM+LTE_TX_HRM_MAX_SUPPORT_BAND_NUM];
   
   /* tr_init value from SA, tr_init[][0] and tr_init[][1] are both valid for band28, for the other band, only tr_init[][0] is valid, request by tool team */
   MMRfTestDpdTrAbsolute           tr_init[LTE_MAX_TX_COMP_ROUTE_NUM+LTE_BYPASS_MAX_SUPPORT_BAND_NUM+LTE_TX_HRM_MAX_SUPPORT_BAND_NUM][MAX_DPD_DELAY_K_B28_SPLIT_BAND_NUM];
   
   /* subband frequency for DPD delay k, subband_freq[][0] and subband_freq[][1] are both valid for band28, for the other band, only subband_freq[][0] is valid, request by tool team */
   MMRfTestDpdPathDelaySubbandFreq subband_freq[LTE_MAX_TX_COMP_ROUTE_NUM+LTE_BYPASS_MAX_SUPPORT_BAND_NUM+LTE_TX_HRM_MAX_SUPPORT_BAND_NUM][MAX_DPD_DELAY_K_B28_SPLIT_BAND_NUM];
   
} MMRfTestCmdDpdPathDelayCheckResult;

typedef struct
{
   MMRfTestCmdDpdPathDelayCheck       *p_dpd_path_delay_check_dim;   
   MMRfTestCmdDpdPathDelayCheckResult *p_dpd_path_delay_check_result;
   
} MMRfTestDpdPathDelayCheckInfo;

typedef struct
{

   kal_uint16 dpd_path_delay_check_status;

   kal_uint16 dpd_path_delay_check_error_code;

   MMRfTestCmdDpdPathDelayCheck dpd_path_delay_check_dim;

} MMRfTestDpdPathDelayCheckRpt;

typedef struct
{
   MMRfTestDpdPathDelayCheckInfo cmd;
   MMRfTestDpdPathDelayCheckRpt  *p_rpt;

} MMRfTestDpdPathDelayCheckCmdRptMix;

/*******************************************************************************
 * DPD PATH DELAY START Command
 ******************************************************************************/

typedef enum
{
   MMRF_TEST_DPD_PATH_DELAY_START_ERROR   = 0,
   MMRF_TEST_DPD_PATH_DELAY_START_SUCCESS = 1

} MMRfTestDPDPathDelayStartStatusType;

typedef enum
{

   MMRF_TEST_DPD_PATH_DELAY_START_OUT_RANGE = 0

} MMRfTestDPDPathDelayStartErrType;

typedef struct
{
   kal_uint16 rat_idx;
   kal_uint16 band;
   kal_uint16 subband_freq;
   kal_uint16 cbw_idx;
   kal_int16  tr_value;
   kal_uint16 signal_path; /*signal path: 0 (default), 1 (HRM), 2(filter)*/
} MMRfTestCmdDpdPathDelayStart;

typedef struct
{

   kal_uint16 dpd_path_delay_start_status;

   kal_uint16 dpd_path_delay_start_error_code;
   
   MMRfTestCmdDpdPathDelayStart dpd_path_delay_start_dim;
   
} MMRfTestDpdPathDelayStartRpt;

typedef struct
{
   MMRfTestCmdDpdPathDelayStart *p_cmd;
   MMRfTestDpdPathDelayStartRpt *p_rpt;

} MMRfTestDpdPathDelayStartCmdRptMix;

/*******************************************************************************
 * RF self-K Start Command (MMRF_TEST_CMD_START_RF_SELF_CAL)
 ******************************************************************************/
// Payload of local parameter within request ILM message  (FT task --> MMRF task)
typedef struct
{
   kal_uint16  rat_idx;       // bitmap: (0|0|Lf|Lt|W|C|T|G)
   kal_uint16  do_self_k;     // 0: get total LID num, bypass cal; 1: get total LID num and do cal

}MMRfTestCmdStartRfSelfK;

// Payload of local parameter within confirm ILM message  (MMRF task --> FT task)
typedef struct
{
   kal_uint16  rat_idx;       // bitmap: (0|0|Lf|Lt|W|C|T|G)
   kal_uint16  lid_total_num;
   kal_uint16  is_error_occur;

}MMRfTestResultStartRfSelfK;


/*******************************************************************************
 * RF self-K Get/Set Command (MMRF_TEST_CMD_GET/SET_RF_SELF_CAL_RESULT)
 ******************************************************************************/
// Payload of local parameter within request ILM message  (FT task --> MMRF task)
typedef struct
{
   kal_uint16  rat_idx;       // bitmap: (0|0|Lf|Lt|W|C|T|G)
   kal_uint16  lid_index;

}MMRfTestCmdGetRfSelfK;

typedef struct
{
   kal_uint16  rat_idx;       // bitmap: (0|0|Lf|Lt|W|C|T|G)
   kal_uint16  lid_index;
   kal_uint16  lid_size;

}MMRfTestCmdSetRfSelfK;

// Payload of local parameter within confirm ILM message  (MMRF task --> FT task)
typedef struct
{
   kal_uint16  rat_idx;       // bitmap: (0|0|Lf|Lt|W|C|T|G)
   kal_uint16  lid_index;
   kal_uint16  lid_size;

}MMRfTestResultGetRfSelfK;

typedef struct
{
   kal_uint16  rat_idx;       // bitmap: (0|0|Lf|Lt|W|C|T|G)
   kal_uint16  lid_index;

}MMRfTestResultSetRfSelfK;


/*******************************************************************************
 * RF self-K Get String Command (MMRF_TEST_CMD_GET_RF_SELF_CAL_RESULT_KEY)
 ******************************************************************************/
// Payload of local parameter within request ILM message  (FT task --> MMRF task)
typedef struct
{
   kal_uint16  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)

}MMRfTestCmdGetRfSelfKStr;

// Payload of local parameter within confirm ILM message  (MMRF task --> FT task)
typedef struct
{
   kal_uint16  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
   kal_uint16  lid_total_num;

}MMRfTestResultGetRfSelfKStr;

// Payload of peer buffer within confirm ILM message  (MMRF task --> FT task)
typedef struct
{
   kal_char    key[MMRF_MAX_RF_SELF_K_LID_COUNT][MMRF_MAX_RF_SELF_K_STRING_LENGTH];
}MMRfTestRfSelfKStr;


/*******************************************************************************
 * RF self-K Get Debug Info Command (MMRF_TEST_CMD_GET_RF_SELF_CAL_DBG_INFO)
 ******************************************************************************/
// Payload of local parameter within request ILM message  (FT task --> MMRF task)
typedef struct
{
   kal_uint16  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)

}MMRfTestCmdGetRfSelfKDbgInfo;

// Payload of local parameter within confirm ILM message  (MMRF task --> FT task)
typedef struct
{
   kal_uint16  rat_idx;        // bitmap: (0|0|Lf|Lt|W|C|T|G)
   kal_uint16  dbg_info_entry_num;

}MMRfTestResultGetRfSelfKDbgInfo;

// Payload of peer buffer within confirm ILM message  (MMRF task --> FT task)
typedef struct
{
   kal_char    dbg_info[MMRF_MAX_RF_SELF_K_DBG_INFO_COUNT][MMRF_MAX_RF_SELF_K_STRING_LENGTH];
}MMRfTestRfSelfKDbgInfo;


/*******************************************************************************
 * TAS Command (MMRF_TEST_CMD_)
 ******************************************************************************/
// Payload of local parameter within request ILM message  (FT task --> MMRF task)
typedef struct
{
   kal_uint16  rat_idx;       // bitmap: (0|0|Lf|Lt|W|C|T|G)
   kal_uint8   tas_cfg;       // 0: disable tas
                              // 1: enable tas and set tas_index=0

}MMRfTestCmdCfgTas;

// Payload of local parameter within confirm ILM message  (MMRF task --> FT task)
typedef struct
{
   kal_uint16  rat_idx;       // bitmap: (0|0|Lf|Lt|W|C|T|G)

}MMRfTestResultCfgTas;

/*******************************************************************************
 * ET CAL STRAT Command
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_ET_CAL_START_ERROR   = 0,
   MMRF_TEST_ET_CAL_START_SUCCESS = 1

} MMRfTestETCalStartStatusType;

typedef enum
{

   MMRF_TEST_ET_CAL_START_OUT_RANGE = 0

} MMRfTestETCalStartErrType;

typedef struct
{
   kal_uint16 rat_idx;

}MMRfTestCmdEtCalStartDim;

typedef struct
{

   kal_uint16 GainComp_dB_0[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND];
   kal_uint16 GainComp_dB_1[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND];
   kal_int16  pa_gain_adjustment[MAX_MMRF_ET_NUM_BAND];
   kal_int16  GrpDelayoffset_0[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX];
   kal_int16  GrpDelayoffset_1[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX];
   kal_uint16 ETKStep2VpaTarget[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND];
   kal_uint16 ETKStep2Gain[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND];
   kal_uint16 ETKStep2DC[MAX_MMRF_ET_NUM_BAND][MAX_MMRF_ET_NUM_SUBBAND];   
   kal_uint16 ETKFlag;

} MMRfTestCmdETCalStartParam;

typedef struct
{
   MMRfTestCmdEtCalStartDim   *p_et_cal_start_dim;   
   MMRfTestCmdETCalStartParam *p_et_cal_start_param;
   
} MMRfTestETCalStartInfo;

typedef struct
{

   kal_uint16 et_cal_start_status;

   kal_uint16 et_cal_start_error_code;

   MMRfTestCmdEtCalStartDim et_cal_start_dim;
   
} MMRfTestETCalStartRpt;

typedef struct
{
   MMRfTestETCalStartInfo   cmd;
   MMRfTestETCalStartRpt    *p_rpt;

}MMRfTestETCalStartCmdRptMix;

/*******************************************************************************
 * ET CAL SET/GET Command
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_ET_CAL_GET_ERROR   = 0,
   MMRF_TEST_ET_CAL_GET_SUCCESS = 1

} MMRfTestETCalGetStatusType;

typedef enum
{

   MMRF_TEST_ET_CAL_GET_OUT_RANGE = 0

} MMRfTestETCalGetErrType;

typedef enum
{
   MMRF_TEST_ET_CAL_SET_ERROR   = 0,
   MMRF_TEST_ET_CAL_SET_SUCCESS = 1

} MMRfTestETCalSetStatusType;

typedef enum
{

   MMRF_TEST_ET_CAL_SET_OUT_RANGE = 0

} MMRfTestETCalSetErrType;

typedef struct
{
   kal_uint16 rat_idx;
   kal_uint16 rf_band;
   kal_uint16 signal_path; /*signal path: 0 (default), 1 (HRM), 2(filter)*/

}MMRfTestCmdEtCalSetGetDim;

typedef struct
{
   /* all entries in this struct are "per band" */
   kal_uint16 VinVpaLut[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
   kal_int16  VinPmLut [MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
   kal_uint16 VinAmLut [MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
   kal_int16  PathDelay[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_CBW];     /* by subband, by number of CBWs */
   kal_int16  Pout_max [MAX_MMRF_ET_NUM_SUBBAND];
   kal_int16  Pout_gain_offset[MAX_MMRF_ET_NUM_SUBBAND];
   kal_uint16 GainComp_dB[MAX_MMRF_ET_NUM_SUBBAND];
   kal_uint16 GainComp_dB_delta[MAX_MMRF_ET_NUM_SUBBAND];
   kal_int16  PathDelayOffsetByTemp[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_CBW][MAX_MMRF_ET_NUM_TEMP];
   kal_int16  GrpDlyOfstBySubband  [MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX];
   kal_int16  PaGainAdjustStep1;
   kal_int16  PaGainFineTuneStep1[MAX_MMRF_ET_NUM_SUBBAND];
   kal_uint16 TwoLUTPwrThreshold[MAX_MMRF_ET_NUM_SUBBAND];
   kal_uint32 EtCalDoneFlag;
}MMRfTestCmdEtCalResult_0;

typedef struct
{
   /* all entries in this struct are "per band" */
   kal_uint16 VinVpaLut[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
   kal_int16  VinPmLut [MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
   kal_uint16 VinAmLut [MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_LUT_PWR_NUM]; /* by subband, by number of Pin */
   kal_int16  PathDelay[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_CBW];     /* by subband, by number of CBWs */
   kal_int16  Pout_max [MAX_MMRF_ET_NUM_SUBBAND];
   kal_int16  Pout_gain_offset[MAX_MMRF_ET_NUM_SUBBAND];
   kal_uint16 GainComp_dB[MAX_MMRF_ET_NUM_SUBBAND];
   kal_uint16 GainComp_dB_delta[MAX_MMRF_ET_NUM_SUBBAND];
   kal_int16  GrpDlyOfstBySubband[MAX_MMRF_ET_NUM_SUBBAND][MAX_MMRF_ET_NUM_RB_IDX];
}MMRfTestCmdEtCalResult_1;

typedef struct
{
   MMRfTestCmdEtCalResult_0 et_cal_fac_param_0;   
   MMRfTestCmdEtCalResult_1 et_cal_fac_param_1;
   
} MMRfTestCmdEtCalResult;

typedef struct
{
   MMRfTestCmdEtCalSetGetDim *p_et_cal_set_get_dim;   
   MMRfTestCmdEtCalResult    *p_et_cal_fac_param;
   
} MMRfTestETCalSetGetInfo;

typedef struct
{

   kal_uint16 et_cal_set_status;

   kal_uint16 et_cal_set_error_code;
   
   MMRfTestCmdEtCalSetGetDim et_cal_set_get_dim;
   
} MMRfTestETCalSetRpt;

typedef struct
{

   kal_uint16 et_cal_get_status;

   kal_uint16 et_cal_get_error_code;
   
   MMRfTestCmdEtCalSetGetDim et_cal_set_get_dim;
   
} MMRfTestETCalGetRpt;

typedef struct
{
   MMRfTestETCalSetGetInfo cmd;
   MMRfTestETCalSetRpt     *p_rpt;

}MMRfTestETCalSetCmdRptMix;

typedef struct
{
   MMRfTestETCalSetGetInfo cmd;
   MMRfTestETCalGetRpt     *p_rpt;

}MMRfTestETCalGetCmdRptMix;

/*******************************************************************************
 * ET PATH DELAY CHECK GET Command
 ******************************************************************************/
typedef enum
{
   MMRF_TEST_ET_PATH_DELAY_CHECK_ERROR   = 0,
   MMRF_TEST_ET_PATH_DELAY_CHECK_SUCCESS = 1

} MMRfTestETPathDelayCheckStatusType;

typedef enum
{

   MMRF_TEST_ET_PATH_DELAY_CHECK_OUT_RANGE = 0

} MMRfTestETPathDelayCheckErrType;

typedef struct
{
   kal_uint16 rat_idx;

} MMRfTestCmdEtPathDelayCheck;

typedef struct
{
   kal_uint32 IsPoweredByETM  [ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];                                /*to check if FHC/ETK done already*/
   kal_uint16 Band            [ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ];                                /*band indicator*/
   kal_uint16 SubbandFreq     [ LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM ][ LTE_ET_SUBBAND_NUM_PER_DATA ]; /*subband frequency*/
}MMRfTestCmdEtPathDelayCheckResult;

typedef struct
{
   MMRfTestCmdEtPathDelayCheck       *p_et_path_delay_check_dim;   
   MMRfTestCmdEtPathDelayCheckResult *p_et_path_delay_check_result;
   
} MMRfTestETPathDelayCheckInfo;

typedef struct
{

   kal_uint16 et_path_delay_check_status;

   kal_uint16 et_path_delay_check_error_code;

   MMRfTestCmdEtPathDelayCheck et_path_delay_check_dim;

} MMRfTestETPathDelayCheckRpt;

typedef struct
{
   MMRfTestETPathDelayCheckInfo cmd;
   MMRfTestETPathDelayCheckRpt  *p_rpt;

}MMRfTestETPathDelayCheckCmdRptMix;

 /*******************************************************************************
  * ET PATH DELAY START Command
  ******************************************************************************/

typedef enum
{
   MMRF_TEST_ET_PATH_DELAY_START_ERROR   = 0,
   MMRF_TEST_ET_PATH_DELAY_START_SUCCESS = 1

} MMRfTestETPathDelayStartStatusType;

typedef enum
{

   MMRF_TEST_ET_PATH_DELAY_START_OUT_RANGE = 0

} MMRfTestETPathDelayStartErrType;

typedef struct
{
   kal_uint16 rat_idx;
   kal_uint16 Band;
   kal_uint16 SubbandFreq;
   kal_uint16 RbIdx;
   kal_int16  Offset;
   kal_uint16 signal_path; /*signal path: 0 (default), 1 (HRM), 2(filter)*/
}MMRfTestCmdEtPathDelayStart;

typedef struct
{

   kal_uint16 et_path_delay_start_status;

   kal_uint16 et_path_delay_start_error_code;
   
   MMRfTestCmdEtPathDelayStart et_path_delay_start_dim;
   
} MMRfTestETPathDelayStartRpt;

typedef struct
{
   MMRfTestCmdEtPathDelayStart *p_cmd;
   MMRfTestETPathDelayStartRpt *p_rpt;

}MMRfTestETPathDelayStartCmdRptMix;

 /*******************************************************************************
  * ET MODE SETTING Command
  ******************************************************************************/
typedef enum
{
   MMRF_TEST_ET_MODE_SETTING_ERROR   = 0,
   MMRF_TEST_ET_MODE_SETTING_SUCCESS = 1

} MMRfTestETModeSettingStatusType;

typedef enum
{

   MMRF_TEST_ET_MODE_SETTING_OUT_RANGE = 0

} MMRfTestETModeSettingErrType;

typedef struct
{
   kal_int16 la_gain;
   kal_int16 la_dac;
   kal_int16 lfp_dac;
   kal_int16 hfp_dac;
}MMRfForceEtSetting;

typedef union 
{
   MMRfForceEtSetting  force_et_setting;
}MMRfEtSetting;

typedef struct
{
   kal_uint16    rat_idx;
   kal_uint16    et_mode;
   MMRfEtSetting et_setting;
}MMRfTestCmdEtModeSetting;

typedef struct 
{
   kal_uint16	et_status;
   kal_uint16	et_error_code;
}MMRfTestResultETModeSettingRpt;

typedef struct
{
   MMRfTestCmdEtModeSetting       *p_cmd;
   MMRfTestResultETModeSettingRpt *p_rpt;

}MMRfTestETModeSettingCmdRptMix;

 /*******************************************************************************
  * SET TOOL USAGE TO L1 Command
  ******************************************************************************/
typedef enum
{
   MMRF_TEST_TOOL_USAGE_NORMAL      = 0,
   MMRF_TEST_TOOL_USAGE_K           = 1,
   MMRF_TEST_TOOL_USAGE_ET_K        = 2,
   MMRF_TEST_TOOL_USAGE_DPD_START   = 3,
   MMRF_TEST_TOOL_USAGE_DPD_DEFAULT = 4
   
} MMRfTestSetToolUsageToL1ModeType;
 
typedef enum
{
   MMRF_TEST_SET_TOOL_USAGE_TO_L1_ERROR   = 0,
   MMRF_TEST_SET_TOOL_USAGE_TO_L1_SUCCESS = 1

} MMRfTestSetToolUsageToL1StatusType;

typedef enum
{

   MMRF_TEST_SET_TOOL_USAGE_TO_L1_OUT_RANGE = 0

} MMRfTestSetToolUsageToL1ErrType;

typedef struct
{
   kal_uint16 rat_idx;
   kal_uint16 toolUsage; /*0:Normal; 1:Calibration; 2:ET calibration mode*/

}MMRfTestCmdSetToolUsageToL1Dim;

typedef struct 
{
   kal_uint16                     set_tool_usage_to_l1_status;
   kal_uint16                     set_tool_usage_to_l1_error_code;
   MMRfTestCmdSetToolUsageToL1Dim set_tool_usage_to_l1_dim;

}MMRfTestResultSetToolUsageToL1Rpt;

typedef struct
{
   MMRfTestCmdSetToolUsageToL1Dim    *p_cmd;
   MMRfTestResultSetToolUsageToL1Rpt *p_rpt;

}MMRfTestSetToolUsageToL1CmdRptMix;

/*******************************************************************************
 * MMRFTST Capability
 ******************************************************************************/
/* the strict ordering MUST be kept */
typedef struct
{
   /*Struct should be 4 bytes alignment*/
   kal_uint32 reserved;

}MMRfTestCapabilityItemSet;

/* DO NOT modify this structure */
typedef struct
{
   kal_uint32 is_capable  : 1;
   kal_uint32 is_mandatory: 1;
   kal_uint32 parameter   :30;

}MMRfTestCalibrationItem;

/* the strict ordering MUST be kept */
typedef struct
{
   /*Struct should be 4 bytes alignment*/
   MMRfTestCalibrationItem ratmap_cal_result_share_tadc;   // bitmap for Multi-RAT to share TADC calibration result
   MMRfTestCalibrationItem ratmap_cal_result_share_afc;    // bitmap for Multi-RAT to share AFC calibration result
   MMRfTestCalibrationItem ratmap_support_RfSelf_cal;      // bitmap for Multi-RAT to support Rf-Self cal.      (0|0|Lf|Lt|W|C|T|G)
   MMRfTestCalibrationItem ratmap_support_postRfSelf_cal;  // bitmap for Multi-RAT to support post Rf-Self cal. (0|0|Lf|Lt|W|C|T|G)
   MMRfTestCalibrationItem ratmap_support_dpd_cal;         // bitmap for Multi-RAT to support DPD cal.          (0|0|Lf|Lt|W|C|T|G)
   MMRfTestCalibrationItem ratmap_support_cim3_cal;        // bitmap for Multi-RAT to support CIM3 cal.         (0|0|Lf|Lt|W|C|T|G)
   MMRfTestCalibrationItem ratmap_support_et_cal;          // bitmap for Multi-RAT to support ET cal.           (0|0|Lf|Lt|W|C|T|G)
   MMRfTestCalibrationItem ratmap_support_TAS;             // bitmap for Multi-RAT to support TAS               (0|0|Lf|Lt|W|C|T|G)
   MMRfTestCalibrationItem ratmap_support_WM;              // bitmap for Multi-RAT to support WMID              (0|0|Lf|Lt|W|C|T|G)
   MMRfTestCalibrationItem ratmap_support_tool_usage;      // bitmap for Multi-RAT to support Tool usage        (0|0|Lf|Lt|W|C|T|G)
}MMRfTestCalibrationItemSet;

/* the strict ordering MUST be kept calibrationItems & capabilityItems are variable part*/
typedef struct
{
   /*Struct should be 4 bytes alignment*/
   kal_uint32 mmrf_capability_verno;                       // version number of MMRF capability field
   kal_uint32 capability_item_offset;                      // capability item offset (byte unit) from structure begin
   kal_uint32 calibration_item_offset;                     // calibration item offset (byte unit) from structure begin
   MMRfTestCapabilityItemSet  capabilityItems;
   MMRfTestCalibrationItemSet calibrationItems;

}MMRfTestResultRfCapability;


/*******************************************************************************
 * MMRFTST request/confirm command (local parameters of ILM message)
 ******************************************************************************/
typedef struct
{
   kal_uint16 token;
   kal_uint32 type;

}MMRfTestFtCmdType;

typedef struct
{
   kal_uint32 curr_idx;
   MMRfTestFtCmdType queue[4];

}MMRfTestFtCmdBackup;

typedef struct
{
   void        (*calInvoked)( void );
   kal_uint16  (*getCalTotalLidNum)( void );
   kal_uint16  (*getCalResultSize)( kal_uint16 lid_index );
   kal_uint16  (*getCalResult)( kal_uint16 lid_index, kal_uint16 lid_size, kal_uint8 *dst );
   kal_uint16  (*setCalResult)( kal_uint16 lid_index, kal_uint16 lid_size, kal_uint8 *src );
   kal_uint16  (*getCalString)( kal_uint16 lid_index, kal_char *string_dst );

}MMRfTestRfSelfCalFuncPtr;

typedef struct
{
   kal_uint16    gmss_wm_id;
   kal_bool    (*queryTasSupport)( void );
   void        (*cfgTasSetting)( kal_bool force_tas_enable, kal_uint8 tas_index );

}MMRfTestAntennaSwitchFuncPtr;

typedef union
{
   kal_uint8                          isLocalParamBeUsed;     // for MMRF_TEST_CMD_GET_RF_CAPABILITY               = 1
   MMRfTestDPDFacSetGetDim            dpd_fac_set_get_dim;    // for MMRF_TEST_CMD_GET_DPD_FAC_RESULT              = 3
                                                              // for MMRF_TEST_CMD_SET_DPD_FAC_RESULT              = 4
   MMRfTestCIM3FacSetGetDim           cim3_fac_set_get_dim;   // for MMRF_TEST_CMD_GET_CIM3_FAC_RESULT             = 7
                                                              // for MMRF_TEST_CMD_SET_CIM3_FAC_RESULT             = 8
   MMRfTestCmdType                    query_op_code;          // for MMRF_TEST_CMD_CHECK_IF_FUNC_EXIST             = 0
   MMRfTestCmdDPDFacStartDim          dpd_fac_start_dim;      // for MMRF_TEST_CMD_START_DPD_FAC_CAL               = 2
   MMRfTestCmdDPDFacEnDis             dpd_fac_en_dis;         // for MMRF_TEST_CMD_DPD_FAC_EN_DIS                  = 5
   MMRfTestCmdCIM3FacStartDim         cim3_fac_start_dim;     // for MMRF_TEST_CMD_START_CIM3_FAC_CAL              = 6
   MMRfTestCmdCIM3FacEnDis            cim3_fac_en_dis;        // for MMRF_TEST_CMD_CIM3_FAC_EN_DIS                 = 9
   MMRfTestCmdStartRfSelfK            startRfSelfKparam;      // for MMRF_TEST_CMD_START_RF_SELF_CAL               = 10
                                                              // for MMRF_TEST_CMD_START_POST_RF_SELF_CAL          = 14
   MMRfTestCmdGetRfSelfK              getRfSelfKResult;       // for MMRF_TEST_CMD_GET_RF_SELF_CAL_RESULT          = 11
                                                              // for MMRF_TEST_CMD_GET_POST_RF_SELF_CAL_RESULT     = 15
                                                              // for MMRF_TEST_CMD_GET_RF_SELF_CAL_RESULT_LEN      = 13
                                                              // for MMRF_TEST_CMD_GET_POST_RF_SELF_CAL_RESULT_LEN = 17
   MMRfTestCmdGetRfSelfKStr           getRfSelfKResultStr;    // for MMRF_TEST_CMD_GET_RF_SELF_CAL_RESULT_KEY      = 19
                                                              // for MMRF_TEST_CMD_SET_POST_RF_SELF_CAL_RESULT_KEY = 20
   MMRfTestCmdSetRfSelfK              setRfSelfKResult;       // for MMRF_TEST_CMD_SET_RF_SELF_CAL_RESULT          = 12
                                                              // for MMRF_TEST_CMD_SET_POST_RF_SELF_CAL_RESULT     = 16
   MMRfTestCmdGetRfSelfKDbgInfo       getRfSelfKDbgInfo;      // for MMRF_TEST_CMD_GET_RF_SELF_CAL_DBG_INFO        = 18
   MMRfTestCmdDPDPaProfileFacStartDim dpd_pa_fac_start_dim;   // for MMRF_TEST_CMD_START_DPD_PA_PROFILE_FAC_CAL    = 21
   MMRfTestDPDPaProfileFacSetGetDim   dpd_pa_fac_set_get_dim; // for MMRF_TEST_CMD_GET_DPD_PA_PROFILE_FAC_RESULT   = 22
                                                              // for MMRF_TEST_CMD_SET_DPD_PA_PROFILE_FAC_RESULT   = 23
   MMRfTestCmdGetLutConfig            get_lut_config;         // for MMRF_TEST_CMD_GET_DPD_CIM3_LUT_CONFIG         = 24
   MMRfTestCmdCfgTas                  cfg_tas;                // for MMRF_TEST_CMD_FORCE_TAS                       = 25
   MMRfTestCmdEtCalStartDim           et_cal_start_dim;
   MMRfTestCmdEtCalSetGetDim          et_cal_set_get_dim;
   MMRfTestCmdEtPathDelayCheck        et_path_delay_check_dim;
   MMRfTestCmdEtPathDelayStart        et_path_delay_start_dim;
   MMRfTestCmdEtModeSetting           et_mode_setting_dim;
   MMRfTestCmdSetToolUsageToL1Dim     set_tool_usage_to_l1_dim;
   MMRfTestCmdDpdPathDelayCheck       dpd_path_delay_check_dim;
   MMRfTestCmdDpdPathDelayStart       dpd_path_delay_start_dim;

}MMRfTestCmdParam;

typedef union
{
   kal_uint8                             isLocalParamBeUsed;    // for MMRF_TEST_CMD_GET_RF_CAPABILITY               = 1
   MMRfTestResultDPDFacEnDisRpt          dpd_fac_en_dis_rpt;    // for MMRF_TEST_CMD_DPD_FAC_EN_DIS                  = 5
   MMRfTestResultCIM3FacEnDisRpt         cim3_fac_en_dis_rpt;   // for MMRF_TEST_CMD_CIM3_FAC_EN_DIS                 = 9
   MMRfTestCmdType                       query_op_code;         // for MMRF_TEST_CMD_CHECK_IF_FUNC_EXIST             = 0
                                         
   MMRfTestResultDPDStartFacRpt          dpd_start_fac_rpt;     // for MMRF_TEST_CMD_START_DPD_FAC_CAL               = 2
   MMRfTestResultDPDGetFacRpt            dpd_get_fac_rpt;       // for MMRF_TEST_CMD_GET_DPD_FAC_RESULT              = 3
   MMRfTestResultDPDSetFacRpt            dpd_set_fac_rpt;       // for MMRF_TEST_CMD_SET_DPD_FAC_RESULT              = 4
   MMRfTestResultCIM3StartFacRpt         cim3_start_fac_rpt;    // for MMRF_TEST_CMD_START_CIM3_FAC_CAL              = 6
   MMRfTestResultCIM3GetFacRpt           cim3_get_fac_rpt;      // for MMRF_TEST_CMD_GET_CIM3_FAC_RESULT             = 7
   MMRfTestResultCIM3SetFacRpt           cim3_set_fac_rpt;      // for MMRF_TEST_CMD_SET_CIM3_FAC_RESULT             = 8
                                         
   MMRfTestResultStartRfSelfK            rfSelfKStatus;         // for MMRF_TEST_CMD_START_RF_SELF_CAL               = 10
                                                                // for MMRF_TEST_CMD_START_POST_RF_SELF_CAL          = 14
   MMRfTestResultGetRfSelfK              getRfSelfKResult;      // for MMRF_TEST_CMD_GET_RF_SELF_CAL_RESULT          = 11
                                                                // for MMRF_TEST_CMD_GET_POST_RF_SELF_CAL_RESULT     = 15
                                                                // for MMRF_TEST_CMD_GET_RF_SELF_CAL_RESULT_LEN      = 13
                                                                // for MMRF_TEST_CMD_GET_POST_RF_SELF_CAL_RESULT_LEN = 17
   MMRfTestResultGetRfSelfKStr           getRfSelfKResultStr;   // for MMRF_TEST_CMD_GET_RF_SELF_CAL_RESULT_KEY      = 19
                                                                // for MMRF_TEST_CMD_SET_POST_RF_SELF_CAL_RESULT_KEY = 20
   MMRfTestResultSetRfSelfK              setRfSelfKResult;      // for MMRF_TEST_CMD_SET_RF_SELF_CAL_RESULT          = 12
                                                                // for MMRF_TEST_CMD_SET_POST_RF_SELF_CAL_RESULT     = 16
   MMRfTestResultGetRfSelfKDbgInfo       getRfSelfKDbgInfo;     // for MMRF_TEST_CMD_GET_RF_SELF_CAL_DBG_INFO        = 18
   MMRfTestResultDPDPaProfileStartFacRpt dpd_pa_start_fac_rpt;  // for MMRF_TEST_CMD_START_DPD_PA_PROFILE_FAC_CAL    = 21
   MMRfTestResultDPDPaProfileGetFacRpt   dpd_pa_get_fac_rpt;    // for MMRF_TEST_CMD_GET_DPD_PA_PROFILE_FAC_RESULT   = 22
   MMRfTestResultDPDPaProfileSetFacRpt   dpd_pa_set_fac_rpt;    // for MMRF_TEST_CMD_SET_DPD_PA_PROFILE_FAC_RESULT   = 23
   MMRfTestResultLutConfigRpt            get_lut_config_rpt;    // for MMRF_TEST_CMD_GET_DPD_CIM3_LUT_CONFIG         = 24
   MMRfTestResultCfgTas                  cfg_tas;               // for MMRF_TEST_CMD_FORCE_TAS                       = 25
   MMRfTestETCalStartRpt                 et_start_fac_rpt;
   MMRfTestETCalGetRpt                   et_get_fac_rpt;
   MMRfTestETCalSetRpt                   et_set_fac_rpt;
   MMRfTestETPathDelayCheckRpt           et_path_delay_check_rpt;
   MMRfTestETPathDelayStartRpt           et_path_delay_start_rpt;
   MMRfTestResultETModeSettingRpt        et_mode_setting_rpt;
   MMRfTestResultSetToolUsageToL1Rpt     set_tool_usage_to_l1_rpt;
   MMRfTestDpdPathDelayCheckRpt          dpd_path_delay_check_rpt;
   MMRfTestDpdPathDelayStartRpt          dpd_path_delay_start_rpt;

}MMRfTestResultParam;

#ifndef __LTE_L1SIM__
// Local parameter of request ILM message  (FT task --> MMRF task)
typedef struct
{
   FT_HDR
   MMRfTestCmdType   type;
   MMRfTestCmdParam  param;
}mmrftst_req_struct;

// Local parameter of confirm ILM message  (MMRF task --> FT task)
typedef struct
{
   FT_HDR
   MMRfTestCmdType      type;
   kal_uint32           result;      // 0: confirm fail; 1: confirm ok
   MMRfTestResultParam  param;
}mmrftst_cnf_struct;

typedef mmrftst_req_struct ft_to_mmrf_struct;
#endif

#endif
