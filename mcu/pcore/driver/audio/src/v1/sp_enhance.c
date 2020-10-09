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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * sp_enhance.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   speech enhancement functions (moved from am.c)  
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "kal_general_types.h"

#include "reg_base.h"

#include "l1audio.h"

#include "kal_trace.h"
#include "l1sp_trc.h"

#include "sp_enhance.h"
#include "sp_drv.h"
#include "am.h"
#include "media.h"
#include "afe.h"
#include "sidetone.h"

#include "ddload.h"



#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#endif

#include "sal_def.h"
#include "sal_exp.h"

#if defined(__HQA_AUDIO__) && !(__HQA_AUDIO_SPEECH_ENHANCEMENT_COMMON__)
const unsigned short Speech_Common_Para[12] = 
{ 
     0,     0,     0,     0,    1,     0,     0,     0,     0,     0, 
     0,     0 
};
#else
#if defined(MT6280)
const unsigned short Speech_Common_Para[12] = 
{ 
     0,     0, 31000, 10752, 32769,     0,     0,     0,     0,     0, 
     0,     0 
};
#elif defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 10752, 32769,     0,     0,     0,     0,     0, 
     0,     0 
};
#else
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 10752,     0,     0,     0,     0,     0,     0, 
     0,     0 
};
#endif
#endif
short Speech_All_Pass_MAG_CLARITY[32] =
   { /* All pass filter */
    32767,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0
   };
#define    Par_Speech_Common  0 //Volume Dependent ,speech unit : ModePar,FIR in,Fir out
#define    Par_GSM_NB_SpeechUnit 1
#define    Par_GSM_WB_SpeechUnit 2
#define    Par_WCDMA_NB_SpeechUnit 3
#define    Par_WCDMA_WB_SpeechUnit 4
#define    Par_CDMA_NB_SpeechUnit 5
#define    Par_CDMA_WB_SpeechUnit 6
#define    Par_VOLTE_NB_SpeechUnit 7
#define    Par_VOLTE_WB_SpeechUnit 8



#define SPE_ALL_FLAG  (SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG)

uint16 spe_table[SPH_MODE_UNDEFINED] = {

// #if defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6290) || defined(MT6595) || defined(MT6752) || defined(MT6735) || defined(TK6291) || defined(MT6755) || defined(ELBRUS) || defined(MT6799) 


	/* SPH_MODE_NORMAL */      SPE_ALL_FLAG + /*SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG */ + SPE_DMNR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
		
	/* SPH_MODE_EARPHONE */    SPE_ALL_FLAG + /*SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG */ + SPE_DMNR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE,


#if SPE_LOUDSPK_DMNR // by chip patch       
	/* SPH_MODE_LOUDSPK */     SPE_ALL_FLAG + /*SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG */ + SPE_DMNR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, 
#else 
	/* SPH_MODE_LOUDSPK */     SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, 
#endif
      

	/* SPH_MODE_BT_EARPHONE */ SPE_ALL_FLAG + SPE_AGC_FLAG /* SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG */,
	/* SPH_MODE_BT_CORDLESS */ 0,
    /* SPH_MODE_BT_CARKIT */   SPE_ALL_FLAG /* SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG */,

	/* SPH_MODE_AUX1 */        SPE_ALL_FLAG + /* SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + */ SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER,
      
	/* SPH_MODE_AUX2 */        0, 


	/* HAC */                  SPE_ALL_FLAG + /* SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + */ SPE_DMNR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
	
	/* USB */                  SPE_ALL_FLAG + SPE_AGC_FLAG, // TDDNC v.s. DMNR is excluded, 

	/* Line-in Cordless */        0 
};   

typedef enum{
	L1SP_SPE_SUBMASK_BYMASK = 0,
	L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, // default true
	L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, // default true
	L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON,
	L1SP_SPE_SUBMASK_SKIP,
	L1SP_SPE_SUBMASK_BYMASK_SP1,
}L1SP_SPE_SUBMASK_VALUES; // for NvramValuesFlag

#define L1SP_ENH_DYNAMIC_NUM (10) //should equal to SAL_ENH_DYNAMIC_NUM// double check the consistence between sp_drv, and sal

L1SP_SPE_SUBMASK_VALUES spe_subMask_table[SPH_MODE_UNDEFINED][L1SP_ENH_DYNAMIC_NUM] = {
	/* SPH_MODE_NORMAL */  
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK },
	/* SPH_MODE_EARPHONE */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK },
	/* SPH_MODE_LOUDSPK */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_BYMASK_SP1,  // loudspeaker mode dmnr
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK },
	/* SPH_MODE_BT_EARPHONE */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_BT_CORDLESS */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_BT_CARKIT */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_AUX1 --> use for magic con-call Lx*/ 
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_AUX2 */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE},
	/* SPH_MODE_HAC like normal */  
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_USB like earphone */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK },
	/* LINEIN ?  */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK}
	//
};

/* ========================================================================= */
typedef enum{
	SPE_NVRAM_VALUES_FLAG_MODE = 0x1,
	SPE_NVRAM_VALUES_FLAG_IN_FIR = 0x2,
	SPE_NVRAM_VALUES_FLAG_OUT_FIR = 0x4,
	SPE_NVRAM_VALUES_FLAG_WB_MODE = 0x8,
	SPE_NVRAM_VALUES_FLAG_WB_IN_FIR = 0x10,
	SPE_NVRAM_VALUES_FLAG_WB_OUT_FIR = 0x20,
}SPE_INTERNAL_NVRAM_VALUES_FLAG; // for NvramValuesFlag

#define TOTAL_NUM_SPH_MODE (NUM_SPH_MODE+2) // new 1 for HAC, 1 for USB
#define TOTAL_NUM_SPH_INPUT_FIR (NUM_SPH_INPUT_FIR+2) // new 1 for HAC, 1 for USB
#define TOTAL_NUM_SPH_OUTPUT_FIR (NUM_SPH_OUTPUT_FIR+2)  // new 1 for HAC, 1 for USB
typedef struct 
{
	uint8    sph_mode; 	
	bool		spe_flag; 
	bool     spe_isFweOn;
	
	uint8    sph_SPE_path; // ul_only=0,dl_only=1,ul+dl=2 	  
	uint16	 spe_skipcheck_sphmode; 	  
	uint16   spe_state; // record which enhancement is open 
	
   uint16   spe_app_mask;   //record the usage every application should have. Ex. phonecall should be turned on DMNR. please do not update the mask directly, please use function l1sp_updateSpeAppMask() to update
   uint16   spe_usr_mask;   //record the usage user choose. Size is NUM_OF_SPH_FLAG. Please use function l1sp_updateSpeUsrMaskWithWholeValue() to update
   uint16   spe_usr_sub_mask; // record the usage of enhancement sub feature. Sync with Sal_Enh_Dynamic_t definition.  Ex. phonecall should be turned on DMNR, but users can decide whether turn on or not.please do not update the mask directly, please use function l1sp_updateUsrSubMask() to update 

	//record the value from nvram whether is get or not, refer to SPE_INTERNAL_NVRAM_VALUES_FLAG
   uint16   setNvramValuesFlag; //bit 0 for sph_allModePara, bit 1 for sph_allInFirCoeff, bit 2 for sph_allOutFirCoeff, 
                                //bit 3 for sph_allWbModePara, bit 4 for sph_allWbInFirCoeff, bit 5 for sph_allWbOutFirCoeff
                                //bit 6 for recordModePara, bit 7 for recordInFirCoeff
                                //bit 8 for sph_allVolumePara is uesless now (phase out)
	// enhancement parameters 
	// --NB--
	uint16   sph_allModePara[TOTAL_NUM_SPH_MODE][NUM_MODE_PARAS];   
   int16    sph_allInFirCoeff[TOTAL_NUM_SPH_INPUT_FIR][NUM_FIR_COEFFS];
   int16    sph_allOutFirCoeff[TOTAL_NUM_SPH_OUTPUT_FIR][NUM_FIR_COEFFS];
	// --WB--
   uint16   sph_allWbModePara[TOTAL_NUM_SPH_MODE][NUM_MODE_PARAS];
   int16    sph_allWbInFirCoeff[TOTAL_NUM_SPH_INPUT_FIR][NUM_WB_FIR_COEFFS];
   int16    sph_allWbOutFirCoeff[TOTAL_NUM_SPH_OUTPUT_FIR][NUM_WB_FIR_COEFFS];
	// --DMNR--
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	int16 	sph_dmnr_para[NUM_DMNR_PARAM];
	int16 	sph_wb_dmnr_para[NUM_WB_DMNR_PARAM];
	int16 	sph_lspk_dmnr_para[NUM_DMNR_PARAM];
	int16 	sph_lspk_wb_dmnr_para[NUM_WB_DMNR_PARAM];
#endif 
    short sph_magi_clarity_para[NUM_MAGI_CLARITY_PARAM];
	uint16 sph_magicConParam[NUM_MODE_PARAS];
	uint16 sph_magicConWbParam[NUM_MODE_PARAS];

	bool     isEnableNotchFilter; 
	bool     is2In1Spk; // the variable only meaning for under isEnableNotchFilter==true. Ture for is 2-in-1 speaker; False for 3-in-1 speaker
	bool     isMagiConOn;

	bool     isHacModeNeeded; // if AP send Hac paramters and FIRs to MD, the flag will be set. 
	bool isSPE_Enable;	// check SPE already enable or not 
	uint8 spe_Path;
	bool isReDDL;
	// --NB--
	uint16	 sph_ModePara[TOTAL_NETWORK_NUMBER][NUM_MODE_PARAS]; 
	int16	 sph_InFirCoeff[TOTAL_NETWORK_NUMBER][NUM_FIR_COEFFS];
	int16	 sph_OutFirCoeff[TOTAL_NETWORK_NUMBER][NUM_FIR_COEFFS];
	// --WB--
	uint16	 sph_WbModePara[TOTAL_NETWORK_NUMBER][NUM_MODE_PARAS];
	int16	 sph_WbInFirCoeff[TOTAL_NETWORK_NUMBER][NUM_WB_FIR_COEFFS];
	int16	 sph_WbOutFirCoeff[TOTAL_NETWORK_NUMBER][NUM_WB_FIR_COEFFS];
	
		bool ctm_spe_status;
} _SPE_T;

static _SPE_T gSpe;

void l1sp_setCtmSpeStatus(bool s){
    gSpe.ctm_spe_status = s;
}

bool l1sp_getCtmSpeStatus(){
    return (gSpe.ctm_spe_status);
}


/* ========================================================================= */
void l1sp_setAllSpeechModePara(kal_uint16 * speech_mode_para, kal_int16 length)
{
	ASSERT((TOTAL_NETWORK_NUMBER*NUM_MODE_PARAS) == length);
	memcpy(gSpe.sph_ModePara, speech_mode_para, 
		TOTAL_NETWORK_NUMBER*NUM_MODE_PARAS*sizeof(uint16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_MODE;
}





void l1sp_setAllSpeechFirCoeff_InputOnly(kal_int16 *speech_input_FIR_coeffs, kal_int16 length)
{
	ASSERT((TOTAL_NETWORK_NUMBER*NUM_FIR_COEFFS) == length);
	memcpy(gSpe.sph_InFirCoeff, speech_input_FIR_coeffs, 
		TOTAL_NETWORK_NUMBER*NUM_FIR_COEFFS*sizeof(int16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_IN_FIR;

}




void l1sp_setAllSpeechFirCoeff_OutputOnly(kal_int16 *speech_output_FIR_coeffs, kal_int16 length)
{
	ASSERT((TOTAL_NETWORK_NUMBER*NUM_FIR_COEFFS) == length);
	memcpy(gSpe.sph_OutFirCoeff, speech_output_FIR_coeffs,
		TOTAL_NETWORK_NUMBER*NUM_FIR_COEFFS*sizeof(int16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_OUT_FIR;
}




//--------------- WB ----------------
void l1sp_setAllWbSpeechModePara(kal_uint16 * speech_mode_para, kal_int16 length)
{
	ASSERT((TOTAL_NETWORK_NUMBER*NUM_MODE_PARAS) == length);
	
	memcpy(gSpe.sph_WbModePara, speech_mode_para, 
		TOTAL_NETWORK_NUMBER*NUM_MODE_PARAS*sizeof(uint16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_WB_MODE; // (1<<3) bit [3]

}
void spe_setMagiCon(void)
{

	gSpe.isMagiConOn = true;
	gSpe.spe_isFweOn = true;
}

void spe_DisableMagiCon(void)
{
	gSpe.isMagiConOn = false;
	gSpe.spe_isFweOn = false;
}




kal_uint16 *SPE_getAllWbSpeechModePara(void)
{
	return (uint16 *)(gSpe.sph_allWbModePara);
}

void l1sp_setAllWbSpeechFirCoeff_InputOnly(
		kal_int16 *speech_input_FIR_coeffs, kal_int16 length)
{
	ASSERT((TOTAL_NETWORK_NUMBER*NUM_WB_FIR_COEFFS) == length);
	memcpy(gSpe.sph_WbInFirCoeff, speech_input_FIR_coeffs, 
		length*sizeof(int16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_WB_IN_FIR; // (1<<4) bit [4]
}




kal_int16 *SPE_getAllWbSpeechFirCoeff_InputOnly(void)
{
	return (int16 *)gSpe.sph_allWbInFirCoeff;
}


void l1sp_setAllWbSpeechFirCoeff_OutputOnly(
		kal_int16 *speech_output_FIR_coeffs, kal_int16 length)
{
	ASSERT((TOTAL_NETWORK_NUMBER*NUM_WB_FIR_COEFFS) == length);
	memcpy(gSpe.sph_WbOutFirCoeff, speech_output_FIR_coeffs,
		length*sizeof(int16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_WB_OUT_FIR; // (1<<4) bit [4]
}



kal_int16 *SPE_getAllWbSpeechFirCoeff_OutputOnly(void)
{
	return (int16 *)gSpe.sph_allWbOutFirCoeff;
}

//--------------- DMNR ----------------


#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	

/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetDMNRPara( const kal_int16 DMNR_para[NUM_DMNR_PARAM] )
{
	
	memcpy(&gSpe.sph_dmnr_para, DMNR_para, NUM_DMNR_PARAM*sizeof(uint16));
}

#if 1//#if defined(__AMRWB_LINK_SUPPORT__)
/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetWbDMNRPara( const kal_int16 WB_DMNR_para[NUM_WB_DMNR_PARAM] )
{
	memcpy(&gSpe.sph_wb_dmnr_para, WB_DMNR_para, NUM_WB_DMNR_PARAM*sizeof(uint16));
}
#endif //__AMRWB_LINK_SUPPORT__

/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetLSpkDMNRPara( const kal_int16 LSpk_DMNR_para[NUM_DMNR_PARAM] )
{	
	memcpy(&gSpe.sph_lspk_dmnr_para, LSpk_DMNR_para, NUM_DMNR_PARAM*sizeof(uint16));
}

#if 1//#if defined(__AMRWB_LINK_SUPPORT__)

/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetLSpkWbDMNRPara( const kal_int16 LSpk_Wb_DMNR_para[NUM_WB_DMNR_PARAM] )
{
	memcpy(&gSpe.sph_lspk_wb_dmnr_para, LSpk_Wb_DMNR_para, NUM_WB_DMNR_PARAM*sizeof(uint16));
}
#endif //__AMRWB_LINK_SUPPORT__

#endif //__DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	


//--------------- MagiCon (Loudspeaker mode)  ---------------------

bool spe_isSpeFweOn(void)
{
	return gSpe.spe_isFweOn;
}


//--------------- New Modes ---------------------

void spe_setHacModeNeeded(bool isNeed)
{
	gSpe.isHacModeNeeded = isNeed;
}

//--------------- viberation speaker ----------------

void spe_setNotchFilterParam(int16 *param, bool is2In1Spk)
{
	AM_SetNotchFilterParam(param);
	gSpe.isEnableNotchFilter = true;
	gSpe.is2In1Spk = is2In1Spk;
}


/* ========================================================================= */

uint16 l1sp_GetSpeState(void)
{
	return gSpe.spe_state;
}

uint8 SPE_GetSpeechMode(void)
{
	return gSpe.sph_mode;
}
void L1SP_MagiClarityData(const short MAGI_CLARITY_PAR[NUM_MAGI_CLARITY_PARAM])
{
	memcpy(&gSpe.sph_magi_clarity_para, MAGI_CLARITY_PAR, NUM_MAGI_CLARITY_PARAM*sizeof(short));
}
void L1SP_Reload_MagiClarity_Para( void )
{
	SPE_MagiClarityData(gSpe.sph_magi_clarity_para);  
}

/**
	Use currect information inside gSpe to decide the mode paramters. 
	@m_para: nb para result
	@m_para_wb: wb para result
*/



void spe_setSpeechMode( uint8 afterSalDevMode, uint8 after_sph_mode)
{   
	kal_bool preIsBt;
	kal_bool afterIsBt;
	kal_bool isSpeechOn; 
	kal_bool isPcmRoutOn;
	kal_bool isAmInSpeechState;

	kal_bool preIsLSP;
	kal_bool afterIsLsp;
	
	uint8 prev_sph_mode = gSpe.sph_mode;
	
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   // kal_uint16 aud_id = L1SP_GetAudID();
   kal_uint16 aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( aud_id );
#endif   

	//------------------------------------------------------
	// DEV and SPH mode choice / fix for special cases
	//------------------------------------------------------
#ifdef SPH_CHIP_BACK_MODE_FIX_TO_NORMAL
	afterSalDevMode = SAL_DEV_NORMAL;
   after_sph_mode = SPH_MODE_NORMAL; // force setting to normal mode
#endif

#if defined(__ENABLE_SPEECH_DVT__)
    extern kal_bool Is_Sph_DVT_BT_Mode_NB(void);
    extern kal_bool Is_Sph_DVT_BT_Mode_WB(void);
    if (Is_Sph_DVT_BT_Mode_NB())
    {
        AFE_SetVoice8KMode(0);
        afterSalDevMode = SAL_DEV_BT_EARPHONE_NB;
        after_sph_mode = SPH_MODE_BT_EARPHONE;
    }
    else if (Is_Sph_DVT_BT_Mode_WB())
    {
        AFE_SetVoice8KMode(1);
        afterSalDevMode = SAL_DEV_BT_EARPHONE_WB;
        after_sph_mode = SPH_MODE_BT_EARPHONE;
    }
#endif // defined(__ENABLE_SPEECH_DVT__)

   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 4, prev_sph_mode, afterSalDevMode);
	kal_trace( TRACE_INFO, L1SP_CHANGE_ENH_MODE, prev_sph_mode, after_sph_mode, gSpe.sph_mode); 

	//------------------------------------------------------
	// Turn off process
	//------------------------------------------------------
	preIsBt = ( (SPH_MODE_BT_EARPHONE==prev_sph_mode) || 
		(SPH_MODE_BT_CORDLESS==prev_sph_mode) ||
		(SPH_MODE_BT_CARKIT==prev_sph_mode) );
	afterIsBt = ( (SPH_MODE_BT_EARPHONE==after_sph_mode) || 
		(SPH_MODE_BT_CORDLESS==after_sph_mode) ||	
		(SPH_MODE_BT_CARKIT==after_sph_mode) );
	isSpeechOn = AM_IsSpeechOn();
	isPcmRoutOn = AM_IsVoIPOn();
	isAmInSpeechState = AM_IsAmInSpeechState();

	// check re dl or not
	preIsLSP = (SPH_MODE_LOUDSPK==prev_sph_mode) ;
	//afterIsLsp = (SPH_MODE_LOUDSPK==prev_sph_mode) ;
	afterIsLsp = (SPH_MODE_LOUDSPK==after_sph_mode) ;
	if(preIsLSP != afterIsLsp) // need re DDL
	{
		gSpe.isReDDL = true;
	}
#if defined(__CVSD_CODEC_SUPPORT__) 
   if( (prev_sph_mode != after_sph_mode) && BT_SCO_IS_SPEECH_ON() )
   {
      BT_SCO_SPEECH_OFF();
   }
#endif
	

   if(preIsBt != afterIsBt){ // need off on speech , due to speech buffer changes between VBI and DAI
   	// Always turn off the enhancement first in order to feed the parameter to DSP in the run time(under call)
	// beacuse enhancement only get the parameter under enable state machine
	//only change bt mode need reset SPE
	SetSpeechEnhancement( false );
	
   	// turn off DSP app
   	if(true == isAmInSpeechState){
			if(true == isSpeechOn) {
				AM_SpeechOff(1); // turn off 8k and speech off

			} else if (true == isPcmRoutOn){
				AM_PcmRouter_Off();
			} else { // cordless mode / speech 
				
				// if( prev_sph_mode == SPH_MODE_BT_CORDLESS ) {
			  	// 	AM_BTCordlessOff();
		   	// } else {		   		
					ASSERT(0); // Do not handle here. Please handle it on application
					// AM_PCM_EX_Off(AM_PCMEX_TYPE type,uint32 p2exData)
		   	// }
				
			}
   	}
			
		if(sp_getIsBtOn()) // if(l1sp.bt_on)
		{
			AM_BluetoothOff();
			sp_setBtOn(false);//l1sp.bt_on = false;
		}
   }

	//------------------------------------------------------
	// Changing
	//------------------------------------------------------
	
	// Begin apply the new device and enhancement parameter
	if((SPH_MODE_BT_EARPHONE==after_sph_mode) || 
		(SPH_MODE_BT_CARKIT==after_sph_mode)) {
		// get sampling rate information from AFE information
		if(0== AFE_GetVoice8KMode()) { // NB
			SAL_Set_Device(SAL_DEV_BT_EARPHONE_NB);
		} else { //WB
			SAL_Set_Device(SAL_DEV_BT_EARPHONE_WB);
		}
	} else {
		SAL_Set_Device(afterSalDevMode);
	}
	
	gSpe.sph_mode = after_sph_mode;		
  if(0 == gSpe.spe_skipcheck_sphmode)
		(gSpe.spe_skipcheck_sphmode)++;
		
	// decide where echo reference comes from.
#if defined(__OPEN_DSP_SPEECH_SUPPORT__)		
	if(SPH_MODE_LOUDSPK == gSpe.sph_mode) {
		SAL_OpenDSP_NXP_Echo_Ref_Switch (SPE_AgcInfo_IsNxpPaOn());
	} else {
		SAL_OpenDSP_NXP_Echo_Ref_Switch (false); 
	}
#endif

	//------------------------------------------------------
	// Turn on
	//------------------------------------------------------
	if(preIsBt != afterIsBt){ // need off on speech, due to speech buffer changes between VBI and DAI
		
		if(afterIsBt)
		{
			if ((after_sph_mode==SPH_MODE_BT_CORDLESS || after_sph_mode==SPH_MODE_LINEIN_VIA_BT_CORDLESS)) 
         {
         	AM_BluetoothOn(1);
			} else {
				AM_BluetoothOn(2);
			}
			
			sp_setBtOn(true); // l1sp.bt_on = true;
		}

		if(true == isAmInSpeechState){
			if(true == isSpeechOn) {				
			   uint32 rat = AM_GetNetworkRate();			
				// [REMIND]L1SP_STATE_xx can mapping to RAT_2G_MODE using "index -1"
				ASSERT(L1SP_STATE_IDLE != L1SP_GetState());
				ASSERT( 
#if defined(__VOLTE_SUPPORT__) 
  				       RAT_4G_MODE == rat || 
#endif  				 
                   RAT_3G_MODE == rat || RAT_2G_MODE == rat            
  				       );
				AM_SpeechOn(rat, 1); 
				
			} else if (true == isPcmRoutOn){
				AM_PcmRouter_On();
			} else { // cordless mode / speech 
				
				// if( after_sph_mode == SPH_MODE_BT_CORDLESS ) {
			  	// 	AM_BTCordlessOn();
		   	// } else {		   		
					ASSERT(0); // Do not handle here. Please handle it on application
					// AM_PCM_EX_Off(AM_PCMEX_TYPE type,uint32 p2exData)
		   	// }
				
			}
   	}
   }
	
   kal_trace( TRACE_INFO, L1SP_SET_MODE, gSpe.sph_mode, -1, 0 );
   SetSpeechEnhancement( true );

#if defined(__CVSD_CODEC_SUPPORT__) 
   if( (SPH_MODE_BT_EARPHONE==after_sph_mode) || (SPH_MODE_BT_CARKIT==after_sph_mode) )
   {
      if(isSpeechOn && !BT_SCO_IS_SPEECH_ON())
      {
         kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
         BT_SCO_SPEECH_ON(is_WB);
      }
   }
#endif

	//------------------------------------------------------
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1Audio_ClearFlag( aud_id );
   L1Audio_FreeAudioID( aud_id );
#endif   	

}


void SetSpeechEnhancement( bool ec )
{

	// For hosted dongle, speech enhancment is not existing by default. 
	// For RNDIS, speech is useless, so don't care.
	// For super dongle, speech is useful. 
	// As the result, condition is: (chip list) && (data card case without spe enable)
#if (defined(MT6280) || defined(MT6290)) && (defined(__DATA_CARD_SPEECH__) && !defined(DACA_SPE_ENABLE_INTERNAL))
   return; 
#endif // (defined(MT6280)) && (defined(__DATA_CARD_SPEECH__) && !defined(DACA_SPE_ENABLE_INTERNAL))

#if (defined(SPH_CHIP_BACK_PHONECALL_USE)||defined(__OPEN_DSP_SPEECH_SUPPORT__))
	return;
#endif // SPH_CHIP_BACK_PHONECALL_USE

	 kal_prompt_trace(MOD_L1SP, "[CTM][SPE] l1sp_getCtmSpeStatus() = %d",l1sp_getCtmSpeStatus());
	// speech is not working. 
	 if ((!AM_IsAmInSpeechState()) || (!gSpe.spe_flag) || (!l1sp_getCtmSpeStatus()))
      return;

	 //speech mode is not in definition.
   if(gSpe.spe_skipcheck_sphmode != 0)
      ASSERT(gSpe.sph_mode<SPH_MODE_UNDEFINED); 
   else {
      gSpe.sph_mode = SPH_MODE_NORMAL;		
      kal_trace( TRACE_INFO, L1SP_SKIP_FIRST_SPHMODE_CHECK, gSpe.spe_skipcheck_sphmode);
      (gSpe.spe_skipcheck_sphmode)++;
   }	
   
   kal_trace( TRACE_INFO, L1SP_APPLY_MODE, (ec)?1:0, gSpe.sph_mode, -1, 0 ); 
   if( ec ) {
      uint16 next_state, keep_on_state, on_state, off_state;  
		uint8 i;
		
		// Update Usr Sub Mask to DSP ENH Dynamic control, 
		// [Remind] 1. ignore SAL_ENH_DYNAMIC_MUTE_UL, because DSP using same sherif to control
		// [Remind] 2. SAL_ENH_DYNAMIC_DMNR_HF_MUX(bit6)'s definition is different from AP and DSP, so driver skip it. 
		ASSERT(SAL_ENH_DYNAMIC_NUM<=L1SP_ENH_DYNAMIC_NUM);
		for(i=SAL_ENH_DYNAMIC_DMNR_MUX; i<SAL_ENH_DYNAMIC_NUM ; i++){
			L1SP_SPE_SUBMASK_VALUES subMask = spe_subMask_table[gSpe.sph_mode][i]; 

			// bit wise update the sub mask (dynamic control for SPE)
			switch(subMask){
				case L1SP_SPE_SUBMASK_BYMASK:
					SAL_ENH_Dynamic_Ctrl(((gSpe.spe_usr_sub_mask & (1<<i))!=0), i);
					break;
				case L1SP_SPE_SUBMASK_BYMASK_SP1: // only for loud speaker DMNR
					if(true == gSpe.isMagiConOn) {
						SAL_ENH_Dynamic_Ctrl( ((gSpe.spe_usr_sub_mask & (1<<SAL_ENH_DYNAMIC_DMNR_HF_MUX))!=0) ,i);
					} else {
						SAL_ENH_Dynamic_Ctrl(false ,i);
					}
					break;
				case L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE: // default true
				case L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE:
				case L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON:
					SAL_ENH_Dynamic_Ctrl(true, i);
					break;
				case L1SP_SPE_SUBMASK_SKIP:
					break;
			}
			kal_trace( TRACE_INFO, L1SP_SET_ENHANCEMENT_SUB_MASK, i, subMask);
			//SAL_ENH_Dynamic_Ctrl(((gSpe.spe_usr_sub_mask & (1<<i))!=0), i);
		}

		if(true == gSpe.spe_isFweOn) {
			SAL_ENH_Dynamic_Ctrl(true, SAL_ENH_DYNAMIC_DMNR_MUX);
			SAL_ENH_Dynamic_Ctrl(true, SAL_ENH_DYNAMIC_DMNR_HF_MUX); 
		} else {
			SAL_ENH_Dynamic_Ctrl(false, SAL_ENH_DYNAMIC_DMNR_HF_MUX); 
		}

		//====================================
		// Choose all the enhancement need to used in the devices 
		next_state = spe_table[gSpe.sph_mode];
		
		// using gSpe.spe_mask to control the open/close of speech enhancment. 
		for(i=0; i< NUM_OF_SPH_FLAG; i++) {
			uint16 tempMaskBit = (1<<i);
	     	if((
	        	((gSpe.spe_app_mask & tempMaskBit) == 0 ) || 
		        ((gSpe.spe_usr_mask & tempMaskBit) == 0 ) 
		        )&& (next_state & tempMaskBit))
	         {
    	        next_state -=tempMaskBit;
        	 }
	  	}

		switch( gSpe.sph_mode ) {
			case SPH_MODE_NORMAL:
			case SPH_MODE_HAC:
				if(true == gSpe.isEnableNotchFilter){ // when ap turn ON notch filter
					if(true == gSpe.is2In1Spk) { // check speaker choise on NORMAL mode
						next_state &= (~SPH_ENH_MASK_NOTCH_FILTER);
					}
				}
			case SPH_MODE_LOUDSPK:
				if(false == gSpe.isEnableNotchFilter){ // when ap do NOT turn on notch filter under normal mode & loud speaker mode
					next_state &= (~SPH_ENH_MASK_NOTCH_FILTER);
				}
				
				if(SPH_MODE_LOUDSPK == gSpe.sph_mode) {
					if(true == SPE_AgcInfo_IsNxpPaOn()) { // when NXP is On, turn DMNR off and support TDDNC(in next expression). 
						next_state |= SPH_ENH_MASK_ECHO_REF; 
#ifdef MDAFE_2IN_1OUT
						next_state &= (~SPE_DMNR_FLAG);
#endif 
					}					
				}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
				break;

			case SPH_MODE_USB:
				if(true == SPE_AgcInfo_IsUSBEchoRefOn()) { // when NXP is On, turn DMNR off and support TDDNC(in next expression). 
						next_state |= SPH_ENH_MASK_ECHO_REF; 
#ifdef MDAFE_2IN_1OUT
						next_state &= (~SPE_DMNR_FLAG);
#endif 
					}
				break; 
			case SPH_MODE_BT_EARPHONE:
			case SPH_MODE_BT_CORDLESS:
			case SPH_MODE_BT_CARKIT:
            	ASSERT( AM_IsBluetoothOn() );
	            break;

			default:
            	break;         	
		}

		// Use ul/dl information to modify the enhancement need to use 
		if(gSpe.sph_SPE_path == SpeechEnh_UL){	  
			next_state &=(~SPE_DL_NR_FLAG);
		}else if(gSpe.sph_SPE_path == SpeechEnh_DL){
			next_state &= (~(SPE_AEC_FLAG|SPE_UL_NR_FLAG|SPE_TDDNC_FLAG|SPE_DMNR_FLAG))  ;
		}

		//====================================
		// dynamic download when turn on speech enhancement
		if(0 == gSpe.spe_state){
	 
#if defined(AEC_ENABLE)
#if defined(SPH_CHIP_BACK_PHONECALL_USE)
			// do not download speech enhancment
#else 

		if(gSpe.isSPE_Enable == false)
		{		
#if SPE_LOUDSPK_DMNR
			if(gSpe.sph_mode == SPH_MODE_LOUDSPK){
				DSP_DynamicDownload( DDID_SPH_TCH_2 );   
			} else {
				DSP_DynamicDownload( DDID_SPH_TCH_1 );   
			}
#else
			DSP_DynamicDownload( DDID_NOISE_REDUCTION );   
#endif // SPE_LOUDSPK_DMNR
		}
		
#endif // SPH_CHIP_BACK_PHONECALL_USE
#endif //  defined(AEC_ENABLE)

		}
		
		
		//====================================
		keep_on_state = next_state & gSpe.spe_state; 
		on_state = next_state - keep_on_state; 
		off_state = gSpe.spe_state - keep_on_state;

      	kal_trace( TRACE_INFO, L1SP_SET_ENHANCEMENT, keep_on_state, on_state, off_state);

   		//====================================
		if(off_state != 0) 
			SPE_TurnOffProcess(off_state);   

		
    	//====================================
		if(next_state != 0)
	  	{
		
			uint16 *c_param ;
			uint16 *m_param ;		 
			uint16 *m_param_wb ;

			// ====================================
			// write the parameters to DSP
        	if(AM_GetNetworkRate() == RAT_2G_MODE)
      		{
      		     Set2GDynPar();
	  		}
			else if(AM_GetNetworkRate()== RAT_3G_MODE || AM_GetNetworkRate()==RAT_3G324M_MODE )
			{
			    Set3GDynPar();
			}
			else if(AM_GetNetworkRate()== RAT_4G_MODE )
			{
				Set4GDynPar();
			}
			else
			{
				Set2GDynPar();  
			}
		
        
		  c_param = Sp_GetCommonSpeechPara();
		  m_param = Sp_GetSpeechPara();
		  m_param_wb = Sp_GetWbSpeechPara();
		  if(gSpe.isSPE_Enable == false)
		  {
		  	SPE_LoadSpeechPara(c_param, NULL, NULL, NULL); 
		  }
		  	
		 	kal_trace( TRACE_INFO, L1SP_SPEECH_ENHANCEMENT, next_state, *m_param, *(m_param+1), *c_param, *(c_param+11));
			kal_trace( TRACE_FUNC,SPE_SETSPEECHENHANCEMENT_C_PARAM);
			kal_trace(TRACE_INFO, L1SP_MODE_VALUE, c_param[0], c_param[1], c_param[2], c_param[3], c_param[4], c_param[5], c_param[6], c_param[7], c_param[8], c_param[9], c_param[10], c_param[11], c_param[12], c_param[13], c_param[14], c_param[15]);	
			kal_trace( TRACE_FUNC,SPE_SETSPEECHENHANCEMENT_M_PARAM);
			kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_param[0], m_param[1], m_param[2], m_param[3], m_param[4], m_param[5], m_param[6], m_param[7], m_param[8], m_param[9], m_param[10], m_param[11], m_param[12], m_param[13], m_param[14], m_param[15]);
			kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_param[16], m_param[17], m_param[18], m_param[19], m_param[20], m_param[21], m_param[22], m_param[23], m_param[24], m_param[25], m_param[26], m_param[27], m_param[28], m_param[29], m_param[30], m_param[31]);
			kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_param[32], m_param[33], m_param[34], m_param[35], m_param[36], m_param[37], m_param[38], m_param[39], m_param[40], m_param[41], m_param[42], m_param[43], m_param[44], m_param[45], m_param[46], m_param[47]);
			kal_trace( TRACE_FUNC,SPE_SETSPEECHENHANCEMENT_M_PARAM_WB);
			kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_param_wb[0], m_param_wb[1], m_param_wb[2], m_param_wb[3], m_param_wb[4], m_param_wb[5], m_param_wb[6], m_param_wb[7], m_param_wb[8], m_param_wb[9], m_param_wb[10], m_param_wb[11], m_param_wb[12], m_param_wb[13], m_param_wb[14], m_param_wb[15]);
			kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_param_wb[16], m_param_wb[17], m_param_wb[18], m_param_wb[19], m_param_wb[20], m_param_wb[21], m_param_wb[22], m_param_wb[23], m_param_wb[24], m_param_wb[25], m_param_wb[26], m_param_wb[27], m_param_wb[28], m_param_wb[29], m_param_wb[30], m_param_wb[31]);
			kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_param_wb[32], m_param_wb[33], m_param_wb[34], m_param_wb[35], m_param_wb[36], m_param_wb[37], m_param_wb[38], m_param_wb[39], m_param_wb[40], m_param_wb[41], m_param_wb[42], m_param_wb[43], m_param_wb[44], m_param_wb[45], m_param_wb[46], m_param_wb[47]);

			SPE_SetActiveEchoRefInfo(gSpe.sph_mode); 
			SPE_MagiClarityData(gSpe.sph_magi_clarity_para);
//  check support DMNR par .		
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
		if(next_state & SPE_DMNR_FLAG)
		{							
			SPE_LoadDmnrCoeffs(gSpe.sph_dmnr_para); 
			SPE_LoadDmnrLspCoeffs(gSpe.sph_lspk_dmnr_para);
			SPE_LoadWbDmnrCoeffs(gSpe.sph_wb_dmnr_para);
			SPE_LoadWbDmnrLspCoeffs(gSpe.sph_lspk_wb_dmnr_para);
				
							
		}
#endif //__DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	
			
			// reconfig AGC depends on ECHO_REF status
			if( keep_on_state & SPE_AGC_FLAG) {
				spe_AGC_config(true, 0 != (next_state & SPH_ENH_MASK_ECHO_REF));
			}
			
		 	// first time enable SPE ,need Enable UL/DL path 
		 	/* if(gSpe.isSPE_Enable == false) // TODO: move to dynamic download end is ok.  
		 	{
		 	 	SPE_Enable_DLL_Entry(on_state,gSpe.spe_Path);
		 	} */
      

		 	// Dynamic change mode,maybe need RE DDL 
		 	if(gSpe.isSPE_Enable == true)
		 	{
		 	
				//curr_frc = ust_get_current_time();
	            // enable DDL state machine 
	            // wait DSP ack
				//  DDL 		
		 		if(gSpe.isReDDL)
		 		{
			
					SAL_ENH_Dynamic_State_Set(SAL_ENH_DYN_DDL_SET);
					kal_trace( TRACE_FUNC,SPE_SETSPEECHENHANCEMENT1);
				
					SPE_WaitSPEDynready(SAL_ENH_DYN_DDL_SET);
					kal_trace( TRACE_FUNC,SPE_SETSPEECHENHANCEMENT2);
			
#if SPE_LOUDSPK_DMNR
					if(gSpe.sph_mode == SPH_MODE_LOUDSPK){
						DSP_DynamicDownload( DDID_SPH_TCH_2 );	 
					} else {
						DSP_DynamicDownload( DDID_SPH_TCH_1 );	 
					}
#else
					DSP_DynamicDownload( DDID_NOISE_REDUCTION );   
#endif                
					kal_trace( TRACE_FUNC,SPE_SETSPEECHENHANCEMENT3);
					SAL_ENH_Dynamic_State_Set(SAL_ENH_DYN_DDL_DONE);
					kal_trace( TRACE_FUNC,SPE_SETSPEECHENHANCEMENT4);
					SPE_WaitSPEDynready(SAL_ENH_DYN_DDL_DONE);
					kal_trace( TRACE_FUNC,SPE_SETSPEECHENHANCEMENT_SPE_WAITSPEDYNREADY_DONE);			
				}
				gSpe.isReDDL = false;

				
			}

			// =====================================
			// Turn on if 
			if(on_state != 0) {
				SPE_Enable_DLL_Entry(on_state,gSpe.spe_Path);
				SPE_TurnOnProcess(on_state);
			}

#if defined(__SMART_PHONE_MODEM__) // using software sidetone
			if(SPH_ENH_MASK_SIDETONE & on_state) {
				SIDETONE_TurnSwSidetoneOn(true);
			}
#endif // !defined(SMART_PHONE_HW_SIDETONE_SUPPORT)

			// notch filter for 3-in 1 speaker
			if( SPH_ENH_MASK_NOTCH_FILTER& on_state ) {
				//reload the coefficient
				AM_DSP_WriteNotchFilterParam();
				
				// turn on 
				SAL_NotchFilter_Enable(true , false);
			}
			
		}
     
		if(gSpe.isSPE_Enable == true) // reload the parameters. pre-condition is that NR&EC is state mahcine on
		{
			SPE_SetDynamicStatemachine();
		}
		gSpe.isSPE_Enable = true;	
		gSpe.spe_state = next_state;
	     //SPE_Clear_DLL_Entry(gSpe.spe_state);
   }
   else {
      if(gSpe.spe_state != 0)
      {
         SPE_TurnOffProcess(gSpe.spe_state);  

#if defined(__SMART_PHONE_MODEM__) // using software sidetone			
			if(SPH_ENH_MASK_SIDETONE & gSpe.spe_state) {
				SIDETONE_TurnSwSidetoneOn(false);
			}
#endif // !defined(SMART_PHONE_HW_SIDETONE_SUPPORT)		

			if(SPH_ENH_MASK_NOTCH_FILTER& gSpe.spe_state) {
				// turn off 
				SAL_NotchFilter_Enable(false , false);
			}
	     gSpe.isSPE_Enable = false;			
         gSpe.spe_state = 0;
         SPE_Clear_DLL_Entry(0);
      }

#if defined(__TC01_VOICE_ENGINE__)
      VC_Stop();
      VS_Stop();
#endif
   }

#if 0
/* under construction !*/
/* under construction !*/
#if !USE_AEC
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
}




static void spe_getFirMappingByScene(const uint32 scene, 
	uint8 *devMode, uint8 *enhMode,
	uint8 *inFir, uint8 *outFir)
{
	uint8 tempDevMode = 0xff; 
	uint8 tempEnhMode = 0xff;
	uint8 tempInFir = 0xff; 
	uint8 tempOutFir = 0xff;
	
	switch(scene) {
	case SPH_ENH_AND_FIR_SCENE_NORMAL:
		tempDevMode = SAL_DEV_NORMAL; // SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_NORMAL;
		tempInFir = SPH_FIR_COEFF_NORMAL;
		tempOutFir = SPH_FIR_COEFF_NORMAL;
		
		break;
	case SPH_ENH_AND_FIR_SCENE_EARPHONE:
	case SPH_ENH_AND_FIR_SCENE_LOUDSPK:
		tempDevMode = scene; // SAL_DEV_EARPHONE or SAL_DEV_LOUDSPK
		tempEnhMode = scene;
		tempInFir = scene;
		tempOutFir = scene;
		break;	
// #if defined(__BT_SUPPORT__)		
	case SPH_ENH_AND_FIR_SCENE_BT_EARPHONE:	
	case SPH_ENH_AND_FIR_SCENE_BT_CARKIT:
		tempDevMode = SAL_DEV_BT_EARPHONE_NB; //scene;
		tempEnhMode = scene;
		tempInFir = SPH_FIR_COEFF_BT; 
		tempOutFir = SPH_FIR_COEFF_BT;
		break;

	case SPH_ENH_AND_FIR_SCENE_BT_CORDLESS:		
#if defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752) || defined(MT6735)// hw did not support
		ASSERT(0);
#else 
		tempDevMode = SAL_DEV_BT_CORDLESS; //scene;
		tempEnhMode = scene;
		tempInFir = SPH_FIR_COEFF_BT; 
		tempOutFir = SPH_FIR_COEFF_BT;
#endif		
		break;
//#endif
	case SPH_ENH_AND_FIR_SCENE_AUX1: // AUX is use to  loud speaker mode
		tempDevMode = SAL_DEV_LOUDSPK; //scene
		tempEnhMode = SPH_MODE_AUX1; //scene
		tempInFir = SPH_FIR_COEFF_HANDFREE;
		tempOutFir = SPH_FIR_COEFF_HANDFREE;
		break;
	case SPH_ENH_AND_FIR_SCENE_AUX2:
		tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_AUX2;
		tempInFir = SPH_FIR_COEFF_NORMAL;
		tempOutFir = SPH_FIR_COEFF_NORMAL;
		break;
		
	case SPH_ENH_AND_FIR_SCENE_HAC:
		ASSERT(true == gSpe.isHacModeNeeded); // is AP did not set the mode parameter. assert it directly! 
		
		tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_HAC;
		tempInFir = SPH_FIR_COEFF_HAC;
		tempOutFir = SPH_FIR_COEFF_HAC;
		break;
	case SPH_ENH_AND_FIR_SCENE_USB: // similar to earphone
		tempDevMode = SPH_MODE_EARPHONE;
		tempEnhMode = SPH_MODE_USB;
		tempInFir = SPH_FIR_COEFF_USB;
		tempOutFir = SPH_FIR_COEFF_USB;
		break;
	default:
		{
			ASSERT(0);
		}

	}
	
	*devMode = tempDevMode;
	*enhMode = tempEnhMode;
	*inFir = tempInFir;
	*outFir = tempOutFir;
	
}

/**
	new interface to replace L1SP_SetSpeechMode(), L1SP_Write_Audio_Coefficients(), 
	L1SP_Write_WB_Audio_Coefficients() in the same time. 

	if you want to use personal configuration, you can use original interfaces. 

	@scene: [Input] scenario for different enhancement and fir combination. 
*/
void L1SP_SetSpeechEnhanceAndFir(uint32 scene, uint32 updatedCoeff)

{
	uint8 modeIndex = 0;
	uint8 inFirIndex = 0;
	uint8 outFirIndex = 0;
	uint8 devModeIndex = 0; 


	//speech mode
//----------------- original scenario ---------------
	if(scene <SPH_MODE_UNDEFINED)
	{ //keeping the original scenario

		spe_getFirMappingByScene(scene, &devModeIndex, &modeIndex, 
			&inFirIndex, &outFirIndex);

		if((updatedCoeff == 0) 
			|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE)!=0
			|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE)!=0)
			spe_setSpeechMode(devModeIndex, modeIndex); // spe_setSpeechMode(devModeIndex, modeIndex, gSpe.sph_allModePara[modeIndex]);
	

	}
//---------------------- undefined cases --------------------
	else { // undefined cases. 
		kal_trace ( TRACE_INFO, L1SP_USELESS_SET, scene, 0, 0);
	}
	
	//kal_trace( TRACE_INFO, L1SP_SET_ENH_FIR, scene, modeIndex, inFirIndex, outFirIndex, l1sp.spe_usr_mask, l1sp.spe_app_mask);
	kal_trace( TRACE_INFO, L1SP_SET_ENH_FIR, scene, modeIndex, inFirIndex, outFirIndex, 0,0);
	
}

// ----------------------------------------------------------------------------
// speech parameter loading
// ----------------------------------------------------------------------------
extern kal_bool setCommonPara;
extern uint16 commonPara_0;

void SPE_LoadSpeechPara( uint16 c_para[NUM_COMMON_PARAS], uint16 m_para[NUM_MODE_PARAS],uint16 v_para[NUM_VOL_PARAS],
	uint16 m_paraWb[NUM_MODE_PARAS])
{
   uint16 *para;
   volatile uint16* dsp_ptr;
   int I;

   if(c_para)
   {
      para = c_para;      
      dsp_ptr = SAL_CommonPar_GetBuf();
      for(I = SAL_PARAMETERLEN_COMMON; --I >= 0 ; )
         *dsp_ptr++ = *para++;
   }

   if(setCommonPara)
   {
      dsp_ptr = SAL_CommonPar_GetBuf();
      *dsp_ptr = commonPara_0;
   } 

   if(m_para)
   {
      para = m_para;      
      dsp_ptr = SAL_ModePar_GetBuf_NB();       
      for(I = SAL_PARAMETERLEN_MODE_NB; --I >= 0 ; )
      {
         *dsp_ptr++ = *para++;
      } 

      //NB Mode par. 16~31
      dsp_ptr = SAL_ModePar_GetBuf2_NB();	  
      for(I = SAL_PARAMETERLEN_MODE_NB; --I >= 0 ; )
         *dsp_ptr++ = *para++;
      //NB Mode par. 32~47
      dsp_ptr = SAL_ModePar_GetBuf3_NB();	  
      for(I = SAL_PARAMETERLEN_MODE_NB; --I >= 0 ; )
         *dsp_ptr++ = *para++;
   }
	
   if(m_paraWb)
   {
      para = m_paraWb;      
      dsp_ptr = SAL_ModePar_GetBuf_WB();       
      for(I = SAL_PARAMETERLEN_MODE_WB; --I >= 0 ; )
         *dsp_ptr++ = *para++; 

      //WB Mode par. 16~31
      dsp_ptr = SAL_ModePar_GetBuf2_WB();	 

      for(I = SAL_PARAMETERLEN_MODE_WB; --I >= 0 ; )
         *dsp_ptr++ = *para++;
      //WB Mode par. 32~47
      dsp_ptr = SAL_ModePar_GetBuf3_WB();	 
      for(I = SAL_PARAMETERLEN_MODE_WB; --I >= 0 ; )
         *dsp_ptr++ = *para++;
   }


}


void SPE_MagiClarityData(short MagiClarityData[32])
{
 
	int i;
	volatile uint16* dsp_ptr;
	dsp_ptr = SAL_FS_GetFltCoefAddr();
	for( i = 0; i<32; i++) {
		*dsp_ptr++ = MagiClarityData[i];
	}

 
}
/**
	The whole function is workable when "defined(__DUAL_MIC_SUPPORT__)"
*/
void SPE_LoadDmnrCoeffs(kal_int16 dmnr_para[NUM_DMNR_PARAM])
{
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	

	int i;
	volatile uint16* dsp_ptr;

	dsp_ptr = SAL_DMNR_GetFltCoefAddr_NB();


	for( i = 0; i<SAL_FLTCOEFLEN_DMNR_NB; i++) {
		*dsp_ptr++ = dmnr_para[i];
	}

#endif //__DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	
}

void SPE_LoadDmnrLspCoeffs(kal_int16 dmnr_lsp_para[NUM_DMNR_PARAM])
{
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	

	int i;
	volatile uint16* dsp_ptr;

	dsp_ptr = SAL_DMNR_LSPK_GetFltCoefAddr_NB();


	for( i = 0; i<SAL_FLTCOEFLEN_DMNR_NB; i++) {
		*dsp_ptr++ = dmnr_lsp_para[i];
	}

#endif //__DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	
}
/**
	The whole function is workable when "defined(__DUAL_MIC_SUPPORT__) &&  defined(__AMRWB_LINK_SUPPORT__)"
*/
void SPE_LoadWbDmnrCoeffs(kal_int16 wb_dmnr_para[NUM_WB_DMNR_PARAM])
{
//#if (defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	) &&  defined(__AMRWB_LINK_SUPPORT__)
#if (defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	)

	int i;
	volatile uint16* dsp_ptr;
		
	dsp_ptr = SAL_DMNR_GetFltCoefAddr_WB();
	
	for( i = 0; i<SAL_FLTCOEFLEN_DMNR_WB; i++) {
		*dsp_ptr++ = wb_dmnr_para[i];
	}

	
#endif //(__DUAL_MIC_SUPPORT__|| defined(__SMART_PHONE_MODEM__)	) &&  __AMRWB_LINK_SUPPORT__
}

void SPE_LoadWbDmnrLspCoeffs(kal_int16 wb_dmnr_lsp_para[NUM_WB_DMNR_PARAM])
{
//#if (defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	) &&  defined(__AMRWB_LINK_SUPPORT__)
#if (defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	)

	int i;
	volatile uint16* dsp_ptr;
		
	dsp_ptr = SAL_DMNR_LSPK_GetFltCoefAddr_WB();
	
	for( i = 0; i<SAL_FLTCOEFLEN_DMNR_WB; i++) {
		*dsp_ptr++ = wb_dmnr_lsp_para[i];
	}

	
#endif //(__DUAL_MIC_SUPPORT__|| defined(__SMART_PHONE_MODEM__)	) &&  __AMRWB_LINK_SUPPORT__
}

// ----------------------------------------------------------------------------
// enhancement control
// ----------------------------------------------------------------------------

void spe_updateSpeAppMask(uint8 updateFlags, bool enable)
{
	if(enable)
		gSpe.spe_app_mask |= (updateFlags);
	else
		gSpe.spe_app_mask &= ~(updateFlags);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 2, gSpe.spe_app_mask, gSpe.spe_usr_mask, gSpe.spe_usr_sub_mask, updateFlags, enable);	
}

/*
void l1sp_updateSpeUsrMask(uint8 updateFlags, bool enable)
{
	if(enable)
		gSpe.spe_usr_mask |= (updateFlags);
	else
		gSpe.spe_usr_mask &= ~(updateFlags);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 2, gSpe.spe_app_mask, gSpe.spe_usr_mask, gSpe.spe_usr_sub_mask, updateFlags, enable);	
}
*/
void spe_updateSpeUsrMaskWithWholeValue(uint16 newValue)
{
	kal_uint16 orgValue = gSpe.spe_usr_mask;

	gSpe.spe_usr_mask  = newValue;
	
	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 3, gSpe.spe_app_mask, gSpe.spe_usr_mask, gSpe.spe_usr_sub_mask, newValue, orgValue);	
	
	if(gSpe.spe_state) {// already turn on speech enhancement
      SetSpeechEnhancement(KAL_TRUE);
	}
		
}

/**
	@newValue: 
	typedef enum{
                // ==> SAL_ENH_DYNAMIC_MUTE_UL, bit 0. Please DO NOT use it
		SPE_DYNAMIC_MASK_DMNR = 0x1, // ==> SAL_ENH_DYNAMIC_DMNR_MUX, bit 1
		SPE_DYNAMIC_MASK_VCE  = 0x2, // ==> SAL_ENH_DYNAMIC_VCE_MUX, bit 2
		SPE_DYNAMIC_MASK_BWE  = 0x4, // ==> SAL_ENH_DYNAMIC_BWE_MUX, bit 3
		SPE_DYNAMIC_MASK_DLNR  = 0x8, // ==> SAL_ENH_DYNAMIC_DLNR_MUX, bit 4  
		SPE_DYNAMIC_MASK_ULNR  = 0x10, // ==> SAL_ENH_DYNAMIC_DLNR_MUX, bit 5
		SPE_DYNAMIC_MASK_LSPK_DMNR  = 0x20, // ==> SAL_ENH_DYNAMIC_SIDEKEYCTRL_DGAIN_MUX, bit 6
		SPE_DYNAMIC_MASK_SIDEKEYCTRL_DGAIN = 0x40, // ==> SAL_ENH_DYNAMIC_SIDEKEYCTRL_DGAIN_MUX, bit 7
		SPE_DYNAMIC_MASK_DLNR_INIT_CTRL = 0x80, // ==> SAL_ENH_DYNAMIC_DL_NR_INIT_CTRL_MUX, bit 8
		SPE_DYNAMIC_MASK_AEC = 0x100, // ==> SAL_ENH_DYNAMIC_AEC_MUX, bit 9
	}SPE_SUB_MASK_T;
	
*/
void spe_updateSpeUsrSubMaskWithWholeValue(uint16 newValue)
{
	kal_uint16 orgValue = gSpe.spe_usr_sub_mask;

	gSpe.spe_usr_sub_mask  = (newValue<<1);
	
	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 4, gSpe.spe_app_mask, gSpe.spe_usr_mask, gSpe.spe_usr_sub_mask, newValue, orgValue);	
	
	if(gSpe.spe_state) {// already turn on speech enhancement
		
      SetSpeechEnhancement(KAL_TRUE);
	}
}

void L1SP_EnableSpeechEnhancement( bool enable )
{
   if(enable)
   {
      gSpe.spe_flag = true;
      SetSpeechEnhancement(true);
   }
   else 
   {
      SetSpeechEnhancement(false);
      gSpe.spe_flag = false;
   }    
}


/* ========================================================================= */
#define SPE_INTERNALPAR_INDEX_AGC   0 
#define SPE_INTERNALPAR_INDEX_MAX   SAL_PARAMETERLEN_INTERNAL  // 16

#define _write_enh_internalPar_( enhIndex, value )  \
{  \
   volatile uint16 *addr;  \
   addr = SAL_ENH_GetInternalParAddr(); \
   *(addr+enhIndex) = value; \
}

typedef struct 
{
	uint16    activeDelayAndSwitch4Dsp; 
	uint16    activeMicIndex; // (bit wise operation) 0x1=Mic1, 0x2=Mic2, 0x4=Mic3, 0x8=Mic4
	
	uint16    delayAndSwitch4Dsp[SPH_MODE_UNDEFINED];
	uint16    echoRefMicIndex[SPH_MODE_UNDEFINED]; 
	uint16    isEchoRefOn; // indicate which mode needs echo ref ( bit wise operation) 
	
	
} _SPE_AGC_INFO_T;

static _SPE_AGC_INFO_T speAgcInfo;

void SPE_SetActiveEchoRefInfo(uint16 sphMode)
{
	speAgcInfo.activeDelayAndSwitch4Dsp = speAgcInfo.delayAndSwitch4Dsp[sphMode];
	speAgcInfo.activeMicIndex = speAgcInfo.echoRefMicIndex[sphMode];

	_write_enh_internalPar_(SPE_INTERNALPAR_INDEX_AGC, speAgcInfo.activeDelayAndSwitch4Dsp); //TDDNC also refernce the value, but we do not know why

	kal_trace(TRACE_INFO, SPE_AGC_CONFIG_INFO, 2, AM_DSP_GetSpeechUplinkDigitalGain(), 
		speAgcInfo.isEchoRefOn, speAgcInfo.activeMicIndex, speAgcInfo.activeDelayAndSwitch4Dsp,
		2);
}

void SPE_SetEchoRefInfo(bool isEchoRefOn, uint16 echoRefMicIndex, uint16 delayAndSwitch4Dsp, uint16 sphMode)
{	
	ASSERT(sphMode<SPH_MODE_UNDEFINED); 
	
	if(isEchoRefOn) {
		speAgcInfo.isEchoRefOn |= (1<<sphMode);
		
		speAgcInfo.echoRefMicIndex[sphMode] = echoRefMicIndex;
		speAgcInfo.delayAndSwitch4Dsp[sphMode] = delayAndSwitch4Dsp;
	} else {
		speAgcInfo.isEchoRefOn &= (~(1<<sphMode));
		
		speAgcInfo.echoRefMicIndex[sphMode] = 0;
		speAgcInfo.delayAndSwitch4Dsp[sphMode] = 0;
	}	
}

bool SPE_AgcInfo_IsNxpPaOn(void)
{
	return (speAgcInfo.isEchoRefOn & (1<<SPH_MODE_LOUDSPK))!=0;
}

bool SPE_AgcInfo_IsUSBEchoRefOn(void)
{
	return (speAgcInfo.isEchoRefOn & (1<<SPH_MODE_USB))!=0;
}


void spe_AGC_config_dc(bool isOn, bool isEchoRefOn)
{
	
	Sal_AGC_Config_t cfg;
	memset(&cfg, 0, sizeof(Sal_AGC_Config_t));

	kal_trace(TRACE_INFO, SPE_AGC_CONFIG_INFO, isOn, AM_DSP_GetSpeechUplinkDigitalGain(), 
		speAgcInfo.isEchoRefOn, speAgcInfo.activeMicIndex, speAgcInfo.activeDelayAndSwitch4Dsp,
		isEchoRefOn);		
	
	if(isOn) { // turn on 		
		
		cfg.main_switch = true;
		cfg.gain_switch = false;
		cfg.hpiir_switch = true;
		cfg.vad_switch = false;
		cfg.init_req = true;

		cfg.cosim = false;
		
		SAL_AGC1_Config(&cfg);
		SAL_AGC2_Config(&cfg);
		SAL_AGC3_Config(&cfg);
		SAL_AGC4_Config(&cfg);
		
		if(0!=speAgcInfo.isEchoRefOn && isEchoRefOn){
			cfg.main_switch = false;
			cfg.gain_switch = false;
			cfg.hpiir_switch = false;
			cfg.vad_switch = false;
			cfg.init_req = false;

			cfg.cosim = false;

			switch(speAgcInfo.activeMicIndex){
				case 0x1: 
					SAL_AGC1_Config(&cfg);
					break;
				case 0x2:
					SAL_AGC2_Config(&cfg);
					break;					
				case 0x4:
					SAL_AGC3_Config(&cfg);
					break;					
				case 0x8:
					SAL_AGC4_Config(&cfg);
					break;
				default:
					
					ASSERT(0);
			}
			
		}
	} else { // turn off
		
		cfg.main_switch = false;
		cfg.gain_switch = false;
		cfg.hpiir_switch = false;
		cfg.vad_switch = false;
		cfg.init_req = false;

		cfg.cosim = false;
		
		SAL_AGC1_Config(&cfg);
		SAL_AGC2_Config(&cfg);
		SAL_AGC3_Config(&cfg);
		SAL_AGC4_Config(&cfg);
	}
}
void spe_AGC_config(bool isOn, bool isEchoRefOn)
{
	
	Sal_AGC_Config_t cfg;
	memset(&cfg, 0, sizeof(Sal_AGC_Config_t));

	kal_trace(TRACE_INFO, SPE_AGC_CONFIG_INFO, isOn, AM_DSP_GetSpeechUplinkDigitalGain(), 
		speAgcInfo.isEchoRefOn, speAgcInfo.activeMicIndex, speAgcInfo.activeDelayAndSwitch4Dsp,
		isEchoRefOn);

	if(isOn) { // turn on 
		
		cfg.main_switch = true;
		cfg.gain_switch = true;
		cfg.hpiir_switch = true;
		cfg.vad_switch = true;
		cfg.init_req = true;

		cfg.cosim = false;
		
		SAL_AGC1_Config(&cfg);
		SAL_AGC2_Config(&cfg);
		SAL_AGC3_Config(&cfg);
		SAL_AGC4_Config(&cfg);
		
		if(0!=speAgcInfo.isEchoRefOn && isEchoRefOn){
			cfg.main_switch = false;
			cfg.gain_switch = false;
			cfg.hpiir_switch = false;
			cfg.vad_switch = false;
			cfg.init_req = false;

			cfg.cosim = false;

			switch(speAgcInfo.activeMicIndex){
				case 0x1: 
					SAL_AGC1_Config(&cfg);
					break;
				case 0x2:
					SAL_AGC2_Config(&cfg);
					break;					
				case 0x4:
					SAL_AGC3_Config(&cfg);
					break;					
				case 0x8:
					SAL_AGC4_Config(&cfg);
					break;
				default:
					
					ASSERT(0);
			}
			
		}
	} else { // turn off
		
		cfg.main_switch = false;
		cfg.gain_switch = false;
		cfg.hpiir_switch = false;
		cfg.vad_switch = false;
		cfg.init_req = false;

		cfg.cosim = false;
		
		SAL_AGC1_Config(&cfg);
		SAL_AGC2_Config(&cfg);
		SAL_AGC3_Config(&cfg);
		SAL_AGC4_Config(&cfg);
	}
}

/* ========================================================================= */
extern const unsigned short Speech_Normal_Mode_Para[16];
extern const unsigned short WB_Speech_Normal_Mode_Para[16];

extern const unsigned short Speech_Vol_Para[4];

void SPE_Init( void )
{
#ifdef SPH_CHIP_BACK_PHONECALL_USE
	gSpe.sph_mode = SPH_MODE_NORMAL;
#else
   gSpe.sph_mode = SPH_MODE_UNDEFINED;
#endif
	gSpe.spe_flag = true;
	gSpe.isSPE_Enable = false;	
	gSpe.isReDDL = false;
  gSpe.sph_SPE_path=SpeechEnh_All;


	gSpe.spe_isFweOn = false;

	gSpe.spe_state = 0;

	//default set the DMNR on
   gSpe.spe_app_mask = 0xffff;
   gSpe.spe_usr_mask = 0xffBf; // default turn dual mic off 
	gSpe.spe_usr_sub_mask = 0x023E; // default value to turn on , [bit6]HF DMNR is default off. [bit7] DRC2.0 is default off. sync with Sal_Enh_Dynamic_t bit wise definition

	gSpe.setNvramValuesFlag = 0;
   memset(gSpe.sph_allModePara, 0, TOTAL_NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
   memset(gSpe.sph_allInFirCoeff, 0, TOTAL_NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
   memset(gSpe.sph_allOutFirCoeff, 0, TOTAL_NUM_SPH_OUTPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));

   memset(gSpe.sph_ModePara, 0, TOTAL_NETWORK_NUMBER*NUM_MODE_PARAS*sizeof(uint16));
   memset(gSpe.sph_InFirCoeff, 0, TOTAL_NETWORK_NUMBER*NUM_FIR_COEFFS*sizeof(int16));
   memset(gSpe.sph_OutFirCoeff, 0, TOTAL_NETWORK_NUMBER*NUM_FIR_COEFFS*sizeof(int16));
   
   memset(gSpe.sph_WbModePara, 0, TOTAL_NETWORK_NUMBER*NUM_MODE_PARAS*sizeof(uint16));
   memset(gSpe.sph_WbInFirCoeff, 0, TOTAL_NETWORK_NUMBER*NUM_WB_FIR_COEFFS*sizeof(int16));
   memset(gSpe.sph_WbOutFirCoeff, 0, TOTAL_NETWORK_NUMBER*NUM_WB_FIR_COEFFS*sizeof(int16));
   
  
   L1SP_MagiClarityData(Speech_All_Pass_MAG_CLARITY);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	memset(&gSpe.sph_dmnr_para, 0, NUM_DMNR_PARAM*sizeof(uint16));
	memset(&gSpe.sph_lspk_dmnr_para, 0, NUM_DMNR_PARAM*sizeof(uint16));

#if 1//#ifdef __AMRWB_LINK_SUPPORT__   
	memset(&gSpe.sph_wb_dmnr_para, 0, NUM_WB_DMNR_PARAM*sizeof(uint16));
	memset(&gSpe.sph_lspk_wb_dmnr_para, 0, NUM_WB_DMNR_PARAM*sizeof(uint16));
#endif
#endif 

	gSpe.isMagiConOn = false;
	memset(gSpe.sph_magicConParam, 0, NUM_MODE_PARAS*sizeof(uint16));
	memset(gSpe.sph_magicConWbParam, 0, NUM_MODE_PARAS*sizeof(uint16));


	// viberation speaker
	gSpe.isEnableNotchFilter = false;
	gSpe.is2In1Spk = false;


	// init the AGC as off in every channal
	_write_enh_internalPar_(SPE_INTERNALPAR_INDEX_AGC, 0)
	spe_AGC_config(false, false); 
	
#if 1//#ifdef __AMRWB_LINK_SUPPORT__
	SPE_LoadSpeechPara((uint16 *)Speech_Common_Para, (uint16 *)Speech_Normal_Mode_Para, (uint16 *)Speech_Vol_Para, (uint16 *)WB_Speech_Normal_Mode_Para );
#else
/* under construction !*/
#endif
   gSpe.ctm_spe_status = true;
}


/* ========================================================================= */
/* ========================================================================= */
/*   EC/AEC/EES control Functions                                            */
/* ========================================================================= */
#define  FLAG_EC_SUPP         1
#define  FLAG_DDL_UL_ENTRY    2
#define  FLAG_DDL_DL_ENTRY    4

#define  SPE_IDLE_STATE       0  /* MCU: 0 -> 1 */ 
#define  SPE_READY_STATE      1  /* DSP: 1 -> 2 */    
#define  SPE_WORKING_STATE    2  /* MCU: 2 -> 3 */ 
#define  SPE_STOP_STATE       3  /* DSP: 3 -> 0 */  


#define _wait_for_ready_( enh_mod )  \
{  \
   uint32 I;  \
   for( I = 0; ; I++ ) {  \
      if( SAL_ENH_IsReady(enh_mod))  \
         break;  \
      ASSERT_REBOOT( I < 20 );  \
      kal_sleep_task( AUD_1TICK(2) );  \
   }  \
}

#define _wait_for_idle_( enh_mod )  \
{  \
   uint32 I;  \
   for( I = 0; ; I++ ) {  \
      if( SAL_ENH_IsIdle(enh_mod))  \
         break;  \
      ASSERT_REBOOT( I < 20 );  \
      kal_sleep_task( AUD_1TICK(2) );  \
   }  \
}


void SPE_TurnOnProcess(uint16 on_state)
{
	kal_trace( TRACE_INFO, L1SP_ENHANCE_ON_OFF, 1, on_state);

	
	if(on_state & (SPE_AGC_FLAG)){ 
		// [REMIND], DMNR Calibration need AGC. When following setting modify, please don't forget the code in am.c
		spe_AGC_config(true, 0!=(on_state & SPH_ENH_MASK_ECHO_REF));
	}

   if(on_state & SPE_UL_NR_FLAG)
   		SAL_ENH_SetInit(SAL_ENH_NR_UL);
   if(on_state & SPE_DL_NR_FLAG)
   		SAL_ENH_SetInit(SAL_ENH_NR_DL);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	//REMIND: DMNR should enable before AEC, because it's part of AEC, 
	//AEC will do DMNR initialization when DMNR control is set	
	//DMNR will run, base on AEC is running!!!
	if(on_state & SPE_DMNR_FLAG){ 
		SAL_ENH_SetInit(SAL_ENH_DMNR);
	}
#endif

   if(on_state & (SPE_AEC_FLAG))
   {
		SAL_ENH_SetInit(SAL_ENH_AEC);
		_wait_for_ready_(SAL_ENH_AEC);          
   }

   if(on_state & SPE_TDDNC_FLAG){
   	SAL_ENH_SetInit(SAL_ENH_TDNC);
    _wait_for_ready_(SAL_ENH_TDNC);
   }

   
   if(on_state & SPE_UL_NR_FLAG)
   	_wait_for_ready_(SAL_ENH_NR_UL);
   if(on_state & SPE_DL_NR_FLAG)
   	_wait_for_ready_(SAL_ENH_NR_DL);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	   //REMIND: DMNR depends on the running of AEC
	   if(on_state & SPE_DMNR_FLAG){ 
   	_wait_for_ready_(SAL_ENH_DMNR);
	   }
#endif
     
}


void SPE_TurnOffProcess(uint16 off_state)
{
   kal_trace( TRACE_INFO, L1SP_ENHANCE_ON_OFF, 0, off_state);
   if(off_state & SPE_UL_NR_FLAG)
   	SAL_ENH_SetOff(SAL_ENH_NR_UL);
   if(off_state & SPE_DL_NR_FLAG)
   	SAL_ENH_SetOff(SAL_ENH_NR_DL);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	//REMIND: DMNR should disable before AEC, because it's part of AEC
	if(off_state & SPE_DMNR_FLAG){
	SAL_ENH_SetOff(SAL_ENH_DMNR);
	}
#endif

   if(off_state & SPE_AEC_FLAG)
   { 
		SAL_ENH_SetOff(SAL_ENH_AEC);
		_wait_for_idle_(SAL_ENH_AEC);
   }                      
       
   if(off_state & SPE_TDDNC_FLAG){
	  SAL_ENH_SetOff(SAL_ENH_TDNC);
      _wait_for_idle_(SAL_ENH_TDNC);
   }
                                             
   if(off_state & SPE_UL_NR_FLAG)
	_wait_for_idle_(SAL_ENH_NR_UL);
   if(off_state & SPE_DL_NR_FLAG)
	_wait_for_idle_(SAL_ENH_NR_DL);
   
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	if(off_state & SPE_DMNR_FLAG){
	_wait_for_idle_(SAL_ENH_DMNR);
	}
#endif

	if(off_state & SPE_AGC_FLAG){
		spe_AGC_config(false, false);
	}
	
}

void SPE_Clear_DLL_Entry(uint16 cur_state)
{
   //if(!(cur_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_TDDNC_FLAG)))
   	SAL_ENH_SetULPath(false);
   
   //if(!(cur_state & (SPE_DL_NR_FLAG + SPE_AEC_FLAG)))
   	SAL_ENH_SetDLPath(false);
}


void SPE_Enable_DLL_Entry(uint16 cur_state,uint16 path)
{

   //if(cur_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG))
   	  SAL_ENH_SetULPath(true);
   
   //if(cur_state & (SPE_DL_NR_FLAG + SPE_AEC_FLAG))
   	 SAL_ENH_SetDLPath(true);
}

void SPE_SetDynamicStatemachine(void)
{
	kal_trace( TRACE_FUNC,SPE_SETDYNAMIC_SM, 0);
	if (!AM_IsAmInSpeechState())
    {  //return;
		//ASSERT(0); // need check speech on
	}
	SAL_ENH_Dynamic_State_Set(SAL_ENH_DYN_PAR);
	SPE_WaitSPEDynready(SAL_ENH_DYN_PAR);
	SAL_ENH_Dynamic_State_Par_Init();

	kal_trace( TRACE_FUNC,SPE_SETDYNAMIC_SM, 1);
	
}

void SPE_WaitSPEDynready( Sal_Enh_Dyn_Sta_t DYN_Sta )  
{  

   uint32 I;  
   for( I = 0; ; I++ ) {  
      if( SAL_ENH_Dynamic_State_Check(DYN_Sta))  
         break;  
      //ASSERT_REBOOT( I < 20 );
	  if(I>30)
	  {
		ASSERT(0);
	  }
       kal_sleep_task(AUD_1TICK(2)); //kal_sleep_task( 2 );  

   }  
}


bool isSPEEnable()
{
   if(gSpe.isSPE_Enable == true)
   {
		return true;
   }
   else
   {
		return false;
   }
}

void SPE_SetSALEnhNBFlag(void)
{

	SAL_ENH_Flag_Par_Set(SAL_ENH_FLAG_PAR_SET_NB_BKF_UL);
	SAL_ENH_Flag_Par_Set(SAL_ENH_FLAG_PAR_SET_NB_BKF_DL);
	SAL_ENH_Flag_Par_Set(SAL_ENH_FLAG_PAR_SET_NB_MOD);

}

void SPE_SetSALEnhWBFlag(void)
{	
	SAL_ENH_Flag_Par_Set(SAL_ENH_FLAG_PAR_SET_WB_BKF_UL);
	SAL_ENH_Flag_Par_Set(SAL_ENH_FLAG_PAR_SET_WB_BKF_DL);
	SAL_ENH_Flag_Par_Set(SAL_ENH_FLAG_PAR_SET_WB_MOD);
	

}


void SetDynamicParToDSP(uint32 IDnumber)
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
	   kal_uint16 aud_id = L1SP_GetAudID();
#endif    
	
		switch (IDnumber) {
      	
		case Par_GSM_NB_SpeechUnit:
      	{	 
			//if(AM_GetNetworkRate() == RAT_2G_MODE)
			{			
				SP_SetSpeechPara(gSpe.sph_ModePara[0]);
				SPE_LoadSpeechPara(NULL, gSpe.sph_ModePara[0], NULL, NULL); // l1sp.sph_v_para no one use it.	
				AM_WriteFirCoeffs( gSpe.sph_InFirCoeff[0], gSpe.sph_OutFirCoeff[0] );
				
				if(isSPEEnable() == true)
				{
					SPE_SetSALEnhNBFlag();					
					//set speech nb mode flag,  fir nb in flag,fir out nb flag 
				}
			}
			
				
		}
      	break;  		
		case Par_GSM_WB_SpeechUnit:
		{
			//if(AM_GetNetworkRate() == RAT_2G_MODE)
			{
				SP_SetWbSpeechPara(gSpe.sph_WbModePara[0]);
				SPE_LoadSpeechPara(NULL, NULL, NULL,gSpe.sph_WbModePara[0] ); // l1sp.sph_v_para no one use it. 
				AM_WriteWbFirCoeffs(gSpe.sph_WbInFirCoeff[0],gSpe.sph_WbOutFirCoeff[0]);

                if(isSPEEnable() == true)
                {
                	SPE_SetSALEnhWBFlag();	
					//set speech nb mode flag,  fir nb in flag,fir out nb flag
				}
					 
			}
		}
		break;
		
#if !defined( __UMTS_TDD128_MODE__ ) 
		case Par_WCDMA_NB_SpeechUnit:
      	{	  
			if(AM_GetNetworkRate() == RAT_3G_MODE ||AM_GetNetworkRate() == RAT_3G324M_MODE)
			{
				SP_SetSpeechPara(gSpe.sph_ModePara[1]);
				SPE_LoadSpeechPara(NULL, gSpe.sph_ModePara[1], NULL, NULL); // l1sp.sph_v_para no one use it.	
				AM_WriteFirCoeffs( gSpe.sph_InFirCoeff[1], gSpe.sph_OutFirCoeff[1] );

				if(isSPEEnable() == true)
				{
					SPE_SetSALEnhNBFlag();	
 				//set speech nb mode flag,  fir nb in flag,fir out nb flag
				}
			}
			//set speech nb mode flag,  fir nb in flag,fir out nb flag 	
		}
      	break; 
		case Par_WCDMA_WB_SpeechUnit:
		{
			if(AM_GetNetworkRate() == RAT_3G_MODE ||AM_GetNetworkRate() == RAT_3G324M_MODE)
			{

				SP_SetWbSpeechPara(gSpe.sph_WbModePara[1]);
				SPE_LoadSpeechPara(NULL, NULL, NULL,gSpe.sph_WbModePara[1] ); // l1sp.sph_v_para no one use it. 
				AM_WriteWbFirCoeffs(gSpe.sph_WbInFirCoeff[1],gSpe.sph_WbOutFirCoeff[1]);

			if(isSPEEnable() == true)
			{
				SPE_SetSALEnhWBFlag();	
 			//set speech nb mode flag,  fir nb in flag,fir out nb flag
			}
			}
		}
		break;
#else //CDMA 
		case Par_CDMA_NB_SpeechUnit:
      	{	  	
			if(AM_GetNetworkRate() == RAT_3G_MODE ||AM_GetNetworkRate() == RAT_3G324M_MODE)
			{

				SP_SetSpeechPara(gSpe.sph_ModePara[2]);
				SPE_LoadSpeechPara(NULL, gSpe.sph_ModePara[2], NULL, NULL); // l1sp.sph_v_para no one use it.	
				AM_WriteFirCoeffs( gSpe.sph_InFirCoeff[2], gSpe.sph_OutFirCoeff[2] );

			if(isSPEEnable() == true)
			{
				SPE_SetSALEnhNBFlag();	
 			//set speech nb mode flag,  fir nb in flag,fir out nb flag
			}
			}
			//set speech nb mode flag,  fir nb in flag,fir out nb flag 	
		}
      	break; 
		case Par_CDMA_WB_SpeechUnit:
		{
			if(AM_GetNetworkRate() == RAT_3G_MODE ||AM_GetNetworkRate() == RAT_3G324M_MODE)
			{

				SP_SetWbSpeechPara((kal_uint16*)gSpe.sph_WbInFirCoeff[2]);
				SPE_LoadSpeechPara(NULL, NULL, NULL,gSpe.sph_WbModePara[2] ); // l1sp.sph_v_para no one use it. 
				AM_WriteWbFirCoeffs(gSpe.sph_WbInFirCoeff[2],gSpe.sph_WbOutFirCoeff[2]);

			if(isSPEEnable() == true)
			{
				SPE_SetSALEnhWBFlag();	
 			//set speech nb mode flag,  fir nb in flag,fir out nb flag
			}

			}
		}
		break;
		
#endif
		case Par_VOLTE_NB_SpeechUnit:
      	{	  	
			if(AM_GetNetworkRate() == RAT_4G_MODE)
			{

				SP_SetSpeechPara(gSpe.sph_ModePara[3]);
				SPE_LoadSpeechPara(NULL, gSpe.sph_ModePara[3], NULL, NULL); // l1sp.sph_v_para no one use it.	
				AM_WriteFirCoeffs( gSpe.sph_InFirCoeff[3], gSpe.sph_OutFirCoeff[3] );

			if(isSPEEnable() == true)
			{
				SPE_SetSALEnhNBFlag();	
 			//set speech nb mode flag,  fir nb in flag,fir out nb flag
			}

			}
			//set speech nb mode flag,  fir nb in flag,fir out nb flag 	
		}
      	break; 
		case Par_VOLTE_WB_SpeechUnit:
		{
			if(AM_GetNetworkRate() == RAT_4G_MODE)
			{

				SP_SetWbSpeechPara(gSpe.sph_WbModePara[3]);
				SPE_LoadSpeechPara(NULL, NULL, NULL,gSpe.sph_WbModePara[3] ); // l1sp.sph_v_para no one use it. 
				AM_WriteWbFirCoeffs(gSpe.sph_WbInFirCoeff[3],gSpe.sph_WbOutFirCoeff[3]);

			if(isSPEEnable() == true)
			{
				SPE_SetSALEnhWBFlag();	
 			//set speech nb mode flag,  fir nb in flag,fir out nb flag
			}

			}
		}
		break;
		
	  
	  
	  	default:
      	{
        	kal_trace( TRACE_FUNC,SPE_SETDYNAMICPARTOMD_NOT_FIND, IDnumber);
         	break;
      	}
	}
	
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif	  

}
void Set2GDynPar(void)
{
	SetDynamicParToDSP(Par_GSM_NB_SpeechUnit);
	SetDynamicParToDSP(Par_GSM_WB_SpeechUnit);

}

void Set3GDynPar(void)
{
#if !defined( __UMTS_TDD128_MODE__ ) 

	SetDynamicParToDSP(Par_WCDMA_NB_SpeechUnit);
	SetDynamicParToDSP(Par_WCDMA_WB_SpeechUnit);
#else
	SetDynamicParToDSP(Par_CDMA_NB_SpeechUnit);
	SetDynamicParToDSP(Par_CDMA_WB_SpeechUnit);

#endif

}

void Set4GDynPar(void)
{
	SetDynamicParToDSP(Par_VOLTE_NB_SpeechUnit);
	SetDynamicParToDSP(Par_VOLTE_WB_SpeechUnit);

}

void SetSPEnhancePath(uint8 path)
{
	if(path == SpeechEnh_All)
	{
		gSpe.sph_SPE_path=SpeechEnh_All;
	}
	else if(path == SpeechEnh_UL)
	{
		gSpe.sph_SPE_path=SpeechEnh_UL;
	}
	else if(path == SpeechEnh_DL)
	{
		gSpe.sph_SPE_path=SpeechEnh_DL;
	}
	else
	{
		ASSERT(0);
	}
	
	SetSpeechEnhancement(true);

}
