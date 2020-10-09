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
 * 
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __ERRC_NVRAM_DEF_H__
#define __ERRC_NVRAM_DEF_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "ps_public_enum.h"

#define NVRAM_LTE_FINGERPRINT_CELL_ID_NUM      60
#define NVRAM_LTE_FINGERPRINT_RECORD_NUM       8
#define NVRAM_LTE_LEARNED_MCC_RECORD_NUM 6
#define NVRAM_ERRC_CAP_ROHC_PROFILES_NUM		 (0x09)
#define NVRAM_EF_ERRC_PARTIAL_BAND_NUM           10
#define NVRAM_EF_LTE_CAP_NUM                     (4)
#ifdef __BAND_EXTENSION_SUPPORT__
#define NVRAM_LTE_BAND_NUM                          (0x0100)
#else
#define NVRAM_LTE_BAND_NUM                          (64)
#endif
#define NVRAM_MAX_STORED_HPLMN_NUM 8
#define NVRAM_LTE_STORED_CELL_NUM_MAX 32
#define NVRAM_LTE_LEARNED_FREQ_NUM 16
#define NVRAM_LTE_LEARNED_BAND_NUM 8
#define NVRAM_LTE_FINGERPRINT_FREQ_NUM         4
#define NVRAM_STORED_CARR_NUM                      (0x30)
#define NVRAM_FILTER_COEF_INTERVAL_NUM             (0x04)
#define NVRAM_HSR_PRELOAD_FREQ_NUM_MAX              (10)
#define NVRAM_AMPR_PLMN_NUM                         (12)
#define NVRAM_LTE_VZW_MRU_NUM_MAX 10
#define NVRAM_LTE_CA_BITMASK_NUM                            (NVRAM_LTE_CA_BITMASK_INTER_NUM + NVRAM_LTE_CA_BITMASK_INTRA_NCCA_NUM + NVRAM_LTE_CA_BITMASK_INTRA_CCA_NUM)
#define NVRAM_EF_ERRC_PERFORMANCE_MAX_KRAERR	 (0x0A)
#define NVRAM_EF_ERRC_PERFORMANCE_TRAERR		 (0x02)
#define NVRAM_EF_ERRC_PERFORMANCE_TVALID_RAERR	 (0x05)
#define NVRAM_ERRC_CAP_ROHCV1_PROFILE_RTP        (0x01)
#define NVRAM_ERRC_CAP_ROHCV1_PROFILE_UDP        (0x01)
#define NVRAM_ERRC_CAP_ROHCV1_PROFILE_ESP        (0x00)
#define NVRAM_ERRC_CAP_ROHCV1_PROFILE_IP         (0x01)
#define NVRAM_ERRC_CAP_ROHCV1_PROFILE_TCP        (0x00)
#define NVRAM_ERRC_CAP_ROHCV2_PROFILE_RTP        (0x01)
#define NVRAM_ERRC_CAP_ROHCV2_PROFILE_UDP        (0x01)
#define NVRAM_ERRC_CAP_ROHCV2_PROFILE_ESP        (0x00)
#define NVRAM_DESIGNATED_FREQ_NUM_MAX               (0x14)
#define NVRAM_DESIGNATED_BLACK_FREQ_NUM_MAX         (0x10)
#define NVRAM_PRIORITY_BAND_INF_NUM_MAX             (0x10)
#define NVRAM_LTE_CA_BITMASK_INTER_NUM                      3
#define NVRAM_LTE_CA_BITMASK_INTRA_NCCA_NUM                 1
#define NVRAM_LTE_CA_BITMASK_INTRA_CCA_NUM                  2
#define NVRAM_ERRC_CAP_ROHCV2_PROFILE_IP         (0x01)
#define NVRAM_EF_ERRC_PERFORMANCE_TRACH			 (0x003C)

typedef enum
{
		/*ERRC mtk03651*/
        NVRAM_EF_ERRC_STORED_CARRIER_LID          = NVRAM_LID_GRP_ERRC(0),
		NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
		NVRAM_EF_ERRC_FINGER_PRINT_LID,
		NVRAM_EF_ERRC_LEARNED_MCC_LID,
		NVRAM_EF_ERRC_STORED_CELL_LID,
		NVRAM_EF_ERRC_VZW_MRU_LID,
		NVRAM_EF_ERRC_AFR_SETTING_LID,
		NVRAM_EF_LTE_CAP_LID,
		NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
		NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
		NVRAM_EF_LTE_CAP_CA_COMBIN_MASK_LID,
		NVRAM_EF_LTE_FEATURE_CTRL_LID,
		NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_LID,
		/* Cell/frequency lock */
		NVRAM_EF_CH_LOCK_INFO_LID,
	  /* CA enable/disable list */
		NVRAM_EF_ERRC_RCM_CA_ENABLE_LIST_LID,
		NVRAM_EF_ERRC_RCM_CA_DISABLE_LIST_LID,
		NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_LID,

		/*Add LID must before NVRAM_EF_ERRC_LAST_LID*/
        NVRAM_EF_ERRC_LAST_LID          = NVRAM_LID_GRP_ERRC(63)
}nvram_lid_errc_enum;

#define NVRAM_EF_ERRC_STORED_CARRIER_SIZE        (sizeof(nvram_ef_errc_stored_carrier_struct))
#define NVRAM_EF_ERRC_STORED_CARRIER_TOTAL       (1)

#define NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE      (sizeof(nvram_ef_errc_performance_para_struct))
#define NVRAM_EF_ERRC_PERFORMANCE_PARA_TOTAL     (1)

#define NVRAM_EF_ERRC_FINGER_PRINT_SIZE          (sizeof(nvram_ef_errc_fingerprint_record_struct))
#define NVRAM_EF_ERRC_FINGER_PRINT_TOTAL         (NVRAM_LTE_FINGERPRINT_RECORD_NUM)

#define NVRAM_EF_ERRC_LEARNED_MCC_SIZE          (sizeof(nvram_ef_errc_learned_mcc_record_struct))
#define NVRAM_EF_ERRC_LEARNED_MCC_TOTAL         (NVRAM_LTE_LEARNED_MCC_RECORD_NUM)

#define NVRAM_EF_ERRC_STORED_CELL_SIZE                    (sizeof(nvram_ef_errc_stored_cell_struct))
#define NVRAM_EF_ERRC_STORED_CELL_TOTAL                   (1)

#define NVRAM_EF_ERRC_AFR_SETTING_SIZE                    (sizeof(nvram_ef_errc_afr_setting_struct))
#define NVRAM_EF_ERRC_AFR_SETTING_TOTAL                   (1)

#define NVRAM_EF_LTE_CAP_SIZE                    (sizeof(nvram_ef_lte_cap_struct))
#define NVRAM_EF_LTE_CAP_TOTAL                   (1)

#define NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE                    (sizeof(nvram_ef_ue_eutra_cap_struct))
#define NVRAM_EF_UE_EUTRA_CAP_CSFB_TOTAL                   (1)

#define NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE                    (sizeof(nvram_ef_ue_eutra_cap_struct))
#define NVRAM_EF_UE_EUTRA_CAP_MMDC_TOTAL                   (1)

#define NVRAM_EF_ERRC_VZW_MRU_SIZE                    (sizeof(nvram_ef_errc_vzw_mru_struct))
#define NVRAM_EF_ERRC_VZW_MRU_TOTAL                   (1)

#define NVRAM_EF_LTE_CA_COMBIN_MASK_SIZE                    (sizeof(nvram_ef_errc_lte_ca_combin_mask_struct))
#define NVRAM_EF_LTE_CA_COMBIN_MASK_TOTAL                   (1)

#define NVRAM_EF_LTE_FEATURE_CTRL_SIZE                      (sizeof(nvram_ef_errc_lte_feature_ctrl_struct))
#define NVRAM_EF_LTE_FEATURE_CTRL_TOTAL                     (1)

#define NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_SIZE             (sizeof(nvram_ef_errc_vzw_lte_scan_enhance_struct))
#define NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_TOTAL            (1)

#define NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_SIZE             (sizeof(nvram_ef_errc_vzw_lte_scan_enhance_struct))
#define NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_TOTAL            (1)

#define NVRAM_EF_ERRC_RCM_CA_ENABLE_LIST_SIZE              (sizeof(nvram_ef_ca_band_comb_list_struct))
#define NVRAM_EF_ERRC_RCM_CA_ENABLE_LIST_TOTAL             (1)
#define NVRAM_EF_ERRC_RCM_CA_DISABLE_LIST_SIZE             (sizeof(nvram_ef_ca_band_comb_list_struct))
#define NVRAM_EF_ERRC_RCM_CA_DISABLE_LIST_TOTAL            (1)


#ifdef __CHANNEL_LOCK__
/*
 * Cell/frequency lock
 */
#define NVRAM_EF_CH_LOCK_INFO_SIZE     (sizeof(nvram_ef_ch_lock_info_struct))
#define NVRAM_EF_CH_LOCK_INFO_TOTAL    1
#endif /* __CHANNEL_LOCK__ */


#ifdef __cplusplus
}
#endif 

#endif
