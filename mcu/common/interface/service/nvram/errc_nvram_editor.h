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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __ERRC_NVRAM_EDITOR_H__
#define __ERRC_NVRAM_EDITOR_H__

#ifndef NVRAM_NOT_PRESENT
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "global_type.h"
#include "errc_nvram_def.h"
#include "nvram_common.h"

#define NVRAM_EF_ERRC_RCM_CA_ENABLE_LIST_LID_VERNO "000"
#define NVRAM_EF_ERRC_RCM_CA_DISABLE_LIST_LID_VERNO "000"


#ifdef __LTE_RAT__
#define NVRAM_EF_ERRC_STORED_CARRIER_LID_VERNO     "000"
#ifdef __BAND_EXTENSION_SUPPORT__
#define NVRAM_EF_ERRC_PERFORMANCE_PARA_LID_VERNO   "007"
#else
#define NVRAM_EF_ERRC_PERFORMANCE_PARA_LID_VERNO   "005"
#endif


#define NVRAM_EF_ERRC_FINGER_PRINT_LID_VERNO       "000"
#define NVRAM_EF_ERRC_LEARNED_MCC_LID_VERNO       "000"
#define NVRAM_EF_ERRC_STORED_CELL_LID_VERNO       "001"
#define NVRAM_EF_ERRC_AFR_SETTING_LID_VERNO       "000"

#ifdef __BAND_EXTENSION_SUPPORT__
#define NVRAM_EF_LTE_CAP_LID_VERNO                 "004"
#define NVRAM_EF_UE_EUTRA_CAP_CSFB_LID_VERNO            "007"
#define NVRAM_EF_UE_EUTRA_CAP_MMDC_LID_VERNO            "007"
#else
#define NVRAM_EF_LTE_CAP_LID_VERNO                 "003"
#define NVRAM_EF_UE_EUTRA_CAP_CSFB_LID_VERNO       "005"
#define NVRAM_EF_UE_EUTRA_CAP_MMDC_LID_VERNO       "005"
#endif

#define NVRAM_EF_ERRC_VZW_MRU_LID_VERNO           "000"
#define NVRAM_EF_LTE_CAP_CA_COMBIN_MASK_LID_VERNO       "000"
#define NVRAM_EF_LTE_FEATURE_CTRL_LID_VERNO             "004"
#define NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_LID_VERNO    "000"
#define NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_LID_VERNO        "000"

#endif

#ifdef __CHANNEL_LOCK__
#define NVRAM_EF_CH_LOCK_INFO_LID_VERNO                      "000"
#endif /* __CHANNEL_LOCK__ */

#ifdef __LTE_RAT__

typedef struct {
    kal_uint8 band;
    nvram_plmn_id_struct plmn_id;
} nvram_ef_errc_vzw_mru_entry_struct;


typedef struct {
    kal_uint8   hsr_monitor_mode;
    kal_uint16  earfcn;
} nvram_errc_hsr_preload_freq_struct;

typedef struct {
    nvram_plmn_id_struct plmn_id;
    EARFCN earfcn;
} nvram_errc_designated_freq_record_struct;

typedef struct {
    nvram_plmn_id_struct plmn_id;
    EARFCN earfcn;
    kal_uint8 bandwidth;
} nvram_errc_designated_black_freq_record_struct;

#ifdef __BAND_EXTENSION_SUPPORT__
typedef struct {
    nvram_plmn_id_struct plmn_id;
    kal_uint8 band_num;
    kal_uint8 band_list[64];  //B66 support
} nvram_errc_priority_band_record_struct;
#else
typedef struct {
    nvram_plmn_id_struct plmn_id;
    kal_uint8 band_num;
    kal_uint8 band_list[NVRAM_LTE_BAND_NUM];
} nvram_errc_priority_band_record_struct;
#endif

typedef struct {
    kal_uint8 freq_num;
    nvram_errc_designated_freq_record_struct freq_list[NVRAM_DESIGNATED_FREQ_NUM_MAX];

    kal_uint8 black_freq_num;
    nvram_errc_designated_black_freq_record_struct black_freq_list[NVRAM_DESIGNATED_BLACK_FREQ_NUM_MAX];

    kal_uint8 priority_band_inf_num;
    nvram_errc_priority_band_record_struct priority_band_inf[NVRAM_PRIORITY_BAND_INF_NUM_MAX];
} nvram_errc_designated_carrier_inf_struct;

typedef struct
{
	kal_uint8	rohc_profiles[NVRAM_ERRC_CAP_ROHC_PROFILES_NUM];
	kal_uint8	max_num_rohc_sessions;
} nvram_errc_capa_pdcp_param_struct;

typedef struct
{
	kal_uint8	ue_tx_ante_sel_fdd;
    kal_uint8	ue_tx_ante_sel_tdd;
	kal_uint8	ue_specific_ref_sigs;
} nvram_errc_capa_phylayer_param_struct;

typedef struct
{
	kal_uint8   enhancedDualLayerFDD_r9;
	kal_uint8   enhancedDualLayerTDD_r9;
} nvram_errc_capa_phylayer_param_v920_struct;

typedef struct
{
	kal_uint8   dtm_r9;
	kal_uint8   e_RedirectionGERAN_r9;
} nvram_errc_capa_irat_param_geram_v920_struct;

typedef struct
{
	kal_uint8   e_RedirectionUTRA_r9_fdd;
    kal_uint8   e_RedirectionUTRA_r9_tdd;
} nvram_errc_capa_irat_param_utra_v920_struct;

typedef struct
{
	kal_uint8   intraFreqProximityIndication_r9;
	kal_uint8   interFreqProximityIndication_r9;
	kal_uint8   utran_ProximityIndication_r9;
} nvram_errc_capa_csg_prox_ind_param_r9_struct;

typedef struct
{
	kal_uint8   intraFreqSI_AcquisitionForHO_r9_fdd;
    kal_uint8   intraFreqSI_AcquisitionForHO_r9_tdd;
	kal_uint8   interFreqSI_AcquisitionForHO_r9_fdd;
    kal_uint8   interFreqSI_AcquisitionForHO_r9_tdd;
	kal_uint8   utran_SI_AcquisitionForHO_r9_fdd;
    kal_uint8   utran_SI_AcquisitionForHO_r9_tdd;
} nvram_errc_capa_nei_cell_si_acq_r9_struct;

typedef struct
{
	kal_uint8   rach_Report_r9;
} nvram_errc_capa_son_param_r9_struct;

typedef struct
{
	nvram_errc_capa_phylayer_param_struct               phylayer_param_r9;
    kal_uint32                                          feature_group_ind_r9;
    kal_uint32                                          feature_group_ind_add_r9;
    nvram_errc_capa_irat_param_utra_v920_struct         irat_param_utra_r9;
    nvram_errc_capa_nei_cell_si_acq_r9_struct           nei_cell_si_acq_r9;
} nvram_errc_capa_add_ue_eutra_cap_r9_struct;

typedef struct
{
    kal_uint8   voiceOverPS_HS_UTRA_FDD_r9;
    kal_uint8   voiceOverPS_HS_UTRA_TDD128_r9;
    kal_uint8   srvcc_FromUTRA_FDD_ToUTRA_FDD_r9;
    kal_uint8   srvcc_FromUTRA_FDD_ToGERAN_r9;
    kal_uint8   srvcc_FromUTRA_TDD128_ToUTRA_TDD128_r9;
    kal_uint8   srvcc_FromUTRA_TDD128_ToGERAN_r9;
} nvram_errc_capa_irat_param_utra_v9c0_struct;

typedef struct
{
	kal_uint8   tm5_FDD_r9;
	kal_uint8   tm5_TDD_r9;
} nvram_errc_capa_phylayer_param_v9d0_struct;

typedef struct
{
	kal_uint8   e_RedirectionUTRA_TDD_r10_fdd;
    kal_uint8   e_RedirectionUTRA_TDD_r10_tdd;
} nvram_errc_capa_irat_param_utra_tdd_v1020_struct;

typedef struct
{
    kal_uint8   tdd_SpecialSubframe_r11;
    //__LTE_R11__
    kal_uint8   crs_interf_handl_r11;
    kal_uint8   ePDCCH_r11;
    kal_uint8   multi_ACK_CSI_reporting_r11;
    kal_uint8   ss_CCH_interf_Handl_r11;
    kal_uint8   tx_div_PUCCH1b_ch_select_r11;
    kal_uint8   ul_CoMP_r11;
} nvram_errc_capa_phylayer_param_v1130_struct;

//__LTE_R11__
typedef struct
{
    kal_uint8    mfbi_utra_r9;
} nvram_errc_capa_irat_param_utra_v9h0_struct;

typedef struct {
    kal_uint8    otdoa_ue_assisted_r10;
    kal_uint8    inter_freq_rstd_meas_r10;
} nvram_errc_capa_otdoa_pos_cap_r10_struct;

typedef struct {
    kal_uint8    two_antenna_ports_for_puscch_r10;
    kal_uint8    tm9_with_8tx_fdd_r10;
    kal_uint8    pmi_disabling_r10;
    kal_uint8    cross_carrier_scheduling_r10;
    kal_uint8    simultaneous_pucch_pusch_r10;
    kal_uint8    multi_cluster_pusch_within_cc_r10;
    kal_uint8    non_contiguous_ul_ra_with_cc_info_r10;  /* align bandEUTRA elements */
} nvram_errc_capa_phylayer_param_v1020_struct;

typedef struct {
    kal_uint8    logged_measurements_idle_r10;
    kal_uint8    standalone_GNSS_location_r10;
} nvram_errc_capa_ue_based_nw_perf_meas_param_r10_struct;

typedef struct {
    kal_uint8    pmi_disabling_r10;
    kal_uint32   fgi_r10;
} nvram_errc_capa_ue_cap_add_xdd_v1060_struct;

typedef struct {
    kal_uint8    pdcp_SN_extension_r11;
    kal_uint8    support_rohc_context_continue_r11;
} nvram_errc_capa_pdcp_param_v1130_struct;

typedef struct {
    kal_uint8    rsrq_meas_wideband_r11;
} nvram_errc_capa_meas_param_v1130_struct;

typedef struct {
    kal_uint8    in_device_coex_ind_r11;
    kal_uint8    power_pref_ind_r11;
    kal_uint8    ue_rx_tx_time_diff_measurements_r11;
} nvram_errc_capa_other_param_r11_struct;

typedef struct {
    kal_uint8    ePDCCH_r11;
    kal_uint8    multi_ACK_CSI_reporting_r11;
    kal_uint8    ss_CCH_interf_Handl_r11;
    kal_uint8    tx_div_PUCCH1b_ch_select_r11;
    kal_uint8    rsrq_meas_wideband_r11;
    kal_uint8    in_device_coex_ind_r11;
} nvram_errc_capa_ue_cap_add_xdd_v1130_struct;

typedef struct {
    kal_uint8    bit1;   /* indicates UE supports the configuration combination of SCell DL subframes are a subset of PCell and the configuration combination of SCell DL subframes are a superset of PCell by SIB1 configuration */
    kal_uint8    bit2;   /* indicates UE supports the configuration combination of SCell DL subframes are neither superset nor subset of PCell by SIB1 configuration */
} nvram_errc_capa_phylayer_param_v1170_struct;

#ifdef __BAND_EXTENSION_SUPPORT__
typedef struct {
    kal_uint8    simultaneous_Rx_Tx_r11;
    kal_uint8    supported_CSI_Proc_r11_max_num; /* 0 means not supported, value = 1, 3, 4 */
    kal_uint8    multiple_timing_advance_r11;
} nvram_errc_capa_rf_param_v1130_struct;
#else
typedef struct {
    kal_uint8    multiple_Timing_Advance_r11;
    kal_uint8    simultaneous_Rx_Tx_r11;
    kal_uint8    supported_CSI_Proc_r11_max_num; /* 0 means not supported, value = 1, 3, 4 */
} nvram_errc_capa_rf_param_v1130_struct;
#endif

/* cdma2000 */
typedef struct {
    //supportedBandListHRPD
    kal_uint8    tx_Config_HRPD;  /* 1 means single, 2 means dual */
    kal_uint8    rx_Config_HRPD;  /* 1 means single, 2 means dual */
} nvram_errc_capa_irat_param_cdma2000_hrpd_strcut;

typedef struct {
    //supportedBandList1XRTT
    kal_uint8    tx_Config_1XRTT;  /* 1 means single, 2 means dual */
    kal_uint8    rx_Config_1XRTT;  /* 1 means single, 2 means dual */
} nvram_errc_capa_irat_param_cdma2000_1xrtt_struct;

typedef struct {
    kal_uint8    e_CSFB_1XRTT_r9;
    kal_uint8    e_CSFB_ConcPS_Mob1XRTT_r9;
} nvram_errc_capa_irat_param_cdma2000_1xrtt_v920_struct;

typedef struct {
    kal_uint8    e_CSFB_dual_1XRTT_r10;
} nvram_errc_capa_irat_param_cdma2000_1xrtt_v1020_struct;

typedef struct {
    kal_uint8    cdma2000_NW_Sharing_r11;
} nvram_errc_capa_irat_param_cdma2000_v1130_struct;

typedef struct {
    kal_uint8  mbms_scell_r11;
    kal_uint8  mbms_non_serving_cell_r11;
} nvram_errc_capa_mbms_param_r11_struct;

typedef struct {
    kal_uint8  mbms_scell_r11;
    kal_uint8  mbms_non_serving_cell_r11;    
} nvram_errc_capa_ue_cap_add_xdd_v1180_struct;


typedef struct {
    kal_uint8 lwa_r13;
    kal_uint8 lwa_split_bearer_r13;
    kal_uint8 lwa_buffer_size_r13;
} nvram_errc_capa_lwa_param_r13_struct;


typedef struct
{
    //MTK related
    kal_uint8                                           ue_eutra_cap_ver;

    //spec related
	kal_uint8                                           access_stratum_release;
	kal_uint8                                           ue_category;
	nvram_errc_capa_pdcp_param_struct                   pdcp_param;
	nvram_errc_capa_phylayer_param_struct               phylayer_param;
	kal_uint32                                          feature_group_ind_fdd;
    kal_uint32                                          feature_group_ind_tdd;
	nvram_errc_capa_phylayer_param_v920_struct          phylayer_param_v920;
    nvram_errc_capa_irat_param_geram_v920_struct        irat_param_geram_v920;
    nvram_errc_capa_irat_param_utra_v920_struct         irat_param_utra_v920;
	kal_uint8                                           deviceType_r9;
	nvram_errc_capa_csg_prox_ind_param_r9_struct        csg_prox_ind_param_r9;
    nvram_errc_capa_nei_cell_si_acq_r9_struct           nei_cell_si_acq_r9;
    nvram_errc_capa_son_param_r9_struct                 son_param_r9;
    kal_uint32                                          feature_group_ind_add_r9_fdd;
    kal_uint32                                          feature_group_ind_add_r9_tdd;
    nvram_errc_capa_add_ue_eutra_cap_r9_struct          fdd_add_ue_eutra_cap_r9;
    nvram_errc_capa_add_ue_eutra_cap_r9_struct          tdd_add_ue_eutra_cap_r9;
    nvram_errc_capa_irat_param_utra_v9c0_struct         irat_param_utra_v9c0;
    nvram_errc_capa_phylayer_param_v9d0_struct          phylayer_param_v9d0;
    nvram_errc_capa_irat_param_utra_tdd_v1020_struct    irat_param_utra_tdd_v1020;
    nvram_errc_capa_phylayer_param_v1130_struct         phylayer_param_v1130;

    //__LTE_R11__
    nvram_errc_capa_irat_param_utra_v9h0_struct         irat_param_utra_v9h0;
    nvram_errc_capa_otdoa_pos_cap_r10_struct            otdoa_pos_cap_r10;
    nvram_errc_capa_phylayer_param_v1020_struct         phylayer_param_v1020;
    kal_uint32                                          feature_group_ind_r10_fdd;
    kal_uint32                                          feature_group_ind_r10_tdd;

    nvram_errc_capa_ue_based_nw_perf_meas_param_r10_struct    nw_perf_meas_param_r10;
    nvram_errc_capa_ue_cap_add_xdd_v1060_struct         fdd_add_ue_eutra_cap_r10;
    nvram_errc_capa_ue_cap_add_xdd_v1060_struct         tdd_add_ue_eutra_cap_r10;
    nvram_errc_capa_pdcp_param_v1130_struct             pdcp_param_v1130;
    nvram_errc_capa_meas_param_v1130_struct             meas_param_v1130;
    nvram_errc_capa_other_param_r11_struct              other_param_r11;
    nvram_errc_capa_ue_cap_add_xdd_v1130_struct         fdd_add_ue_eutra_cap_r11;
    nvram_errc_capa_ue_cap_add_xdd_v1130_struct         tdd_add_ue_eutra_cap_r11;
    nvram_errc_capa_phylayer_param_v1170_struct         phylayer_param_v1170;
    nvram_errc_capa_rf_param_v1130_struct               rf_param_v1130;

    nvram_errc_capa_irat_param_cdma2000_hrpd_strcut          irat_param_c2k_hrpd;
    nvram_errc_capa_irat_param_cdma2000_1xrtt_struct         irat_param_c2k_1xrtt;
    nvram_errc_capa_irat_param_cdma2000_1xrtt_v920_struct    irat_param_c2k_1xrtt_v920;
    nvram_errc_capa_irat_param_cdma2000_1xrtt_v1020_struct   irat_param_c2k_1xrtt_v1020;
    nvram_errc_capa_irat_param_cdma2000_v1130_struct         irat_param_c2k_v1130;

    nvram_errc_capa_mbms_param_r11_struct                mbms_param_r11;
    nvram_errc_capa_ue_cap_add_xdd_v1180_struct          fdd_add_ue_eutra_cap_v1180;
    nvram_errc_capa_ue_cap_add_xdd_v1180_struct          tdd_add_ue_eutra_cap_v1180;

    kal_uint8                                            freq_band_retrieval_r11;
    kal_uint8                                            freq_band_priority_adjustment_r12;

    nvram_errc_capa_lwa_param_r13_struct                 lwa_param_r13;
    // end __LTE_R11__
} nvram_ef_ue_eutra_cap_struct;

typedef struct {
    kal_uint16     band;
    EARFCN         dl_lower_earfcn;
    EARFCN         dl_upper_earfcn;
    EARFCN         ul_lower_earfcn;
    EARFCN         ul_upper_earfcn;
} nvram_errc_partial_band_list_struct;

typedef struct {
    kal_uint8   valid_num;
    nvram_errc_partial_band_list_struct  band_list[NVRAM_EF_ERRC_PARTIAL_BAND_NUM];	
} nvram_errc_partial_band_inf_struct;

typedef struct {
    kal_uint8 raw_data[NVRAM_EF_LTE_CAP_NUM];
    kal_uint8 disable_bw[NVRAM_LTE_BAND_NUM];
    nvram_errc_partial_band_inf_struct partial_band_info;
} nvram_ef_lte_cap_struct;

typedef struct
{
    nvram_plmn_id_struct plmnid;
    kal_bool csfb_2g_afr; /* KAL_TRUE: enable; KAL_FALSE: disable */
    kal_bool csfb_3g_afr; /* KAL_TRUE: enable; KAL_FALSE: disable */
} nvram_afr_setting_record_struct;

typedef struct
{
    nvram_afr_setting_record_struct hplmn_afr_mapping[NVRAM_MAX_STORED_HPLMN_NUM];
} nvram_ef_errc_afr_setting_struct;

typedef struct 
{
    EARFCN     earfcn;
    kal_uint16 pci;
    kal_uint32 cell_id;
    kal_uint8 is_valid;
    kal_uint8 is_detected_by_latest_search;
    kal_uint8 is_detected_by_cell;
    kal_uint8 is_detected_by_current_search;
} nvram_ef_errc_stored_cell_record_struct;

typedef struct
{
    nvram_ef_errc_stored_cell_record_struct cell[NVRAM_LTE_STORED_CELL_NUM_MAX];
    kal_uint8 cmcc_band_bmp[NVRAM_LTE_BAND_NUM/8];
} nvram_ef_errc_stored_cell_struct;

typedef struct
{
    kal_uint8 band;
    kal_uint8 freq_num;
    kal_uint8 freq_oldest_idx; //init as 0
    EARFCN    earfcn[NVRAM_LTE_LEARNED_FREQ_NUM];
} nvram_ef_errc_learned_band_record_struct;

typedef struct
{
    kal_uint8 mcc[3];
    kal_uint8 is_valid;
    kal_uint8 band_num;
    kal_uint8 band_oldest_idx; //init as 0
    kal_uint32 timestamp;
    nvram_ef_errc_learned_band_record_struct band[NVRAM_LTE_LEARNED_BAND_NUM];
    
    kal_uint8 is_detected_by_latest_search; //copy from is_detected_by_current_search when full band end
    kal_uint8 is_detected_by_cell;
    kal_uint8 is_detected_by_current_search;
} nvram_ef_errc_learned_mcc_record_struct;

typedef enum{
    NV_ERRC_RAT_LTE,
    NV_ERRC_RAT_UMTS,
    NV_ERRC_RAT_GSM,
    NV_ERRC_RAT_NONE
}nvram_errc_cell_rat_enum;

typedef struct
{
    kal_uint32 update_timestamp; /*Increase counter*/
    EARFCN     earfcn;
    kal_uint8  oldest_cell_indx;
    kal_uint8  numElements;
    kal_uint32 cellid[NVRAM_LTE_FINGERPRINT_CELL_ID_NUM];
}nvram_errc_fingerprint_per_freq_struct;

typedef struct
{
    kal_uint32                             update_systick;   /*System tick*/
    kal_uint32                             update_timestamp; /*Increase counter*/
    kal_bool                               is_update_needed;
    EARFCN                                 freq;
    kal_uint16                             pci;
    nvram_plmn_id_struct                   plmn_id;
    kal_uint32                             csg_id;
    kal_uint32                             cell_id;    
    nvram_errc_cell_rat_enum               rat;
    kal_uint8                              numElements;
    nvram_errc_fingerprint_per_freq_struct frq[NVRAM_LTE_FINGERPRINT_FREQ_NUM];
}nvram_ef_errc_fingerprint_record_struct;

typedef struct
{
    EARFCN               earfcn;
    nvram_plmn_id_struct plmnid;
}nvram_carrier_data_struct;

typedef struct
{
    kal_uint8                  stored_carr_num;
    nvram_carrier_data_struct  stored_carr[NVRAM_STORED_CARR_NUM ];
}nvram_ef_errc_stored_carrier_struct;

typedef struct
{
	kal_uint8   interval_k0;
	kal_uint8   interval_k1;
	kal_uint8   interval_k2;
	kal_uint8   interval_k3;
	kal_uint8   interval_k4;
	kal_uint8   interval_k5;
	kal_uint8   interval_k6;
	kal_uint8   interval_k7;
	kal_uint8   interval_k8;
	kal_uint8   interval_k9;
	kal_uint8   interval_k10;
	kal_uint8   interval_k11;
	kal_uint8   interval_k12;
	kal_uint8   interval_k13;
	kal_uint8   interval_k14;
	kal_uint8   interval_k15;
	kal_uint8   interval_k16;
	kal_uint8   interval_k17;
	kal_uint8   interval_k18;
	kal_uint8   interval_k19;
} nvram_filter_coef_interval_struct;

typedef struct
{
	kal_uint8   tband_ind;
   	kal_uint8   tbarred_cell;
   	kal_uint8   tbarred_freq;
   	kal_uint8   tcsg_cell;
	kal_uint8   carrs_interval;
    kal_uint8   list1_used_carr_max;
	kal_int16   skip_bw_rsrp_th;
   	kal_int16   skip_bw_rsrq_th;
	kal_uint8   tsib_ng_rej;
	kal_uint8   nsib_ng_max;
	kal_uint8   tnsib_clear;
	kal_uint8   est_s_rxlev_th;
	kal_uint8   est_s_qual_th;
	kal_uint16  trach;

	nvram_filter_coef_interval_struct filter_coef_interval[NVRAM_FILTER_COEF_INTERVAL_NUM];
	kal_uint8   eutran_neighbour_cellreport_flg;
	kal_uint8   iir_filter_coef_rsrp;
	kal_uint8   iir_filter_coef_rsrq;
	kal_uint16  th0_interval;
	kal_uint16  th1_interval;
	kal_uint16  th2_interval;
	kal_uint16  th3_interval;
    kal_uint16  th4_interval;

	kal_uint8   max_kraerr;
	kal_uint8   traerr;
	kal_uint8   tvalid_raerr;

	kal_uint8   mib_crc_ng_max;
	kal_uint8   sib1_crc_ng_max;
	kal_uint8   si1_crc_ng_max;
	kal_uint8   si_crc_ng_max;
	kal_uint8   sib10_crc_ng_max;
	kal_uint8   sib11_crc_ng_max;
	kal_uint8   sib12_crc_ng_max;
	kal_uint8   mib_sib1_protect_tim_val;
	kal_uint8   sib2_9_protect_tim_val;
	kal_uint8   crc_ng_tim_shift;
	kal_uint8   standby_mib_sib1_protect_tim_val;
	kal_uint8   standby_sib2_9_protect_tim_val;

	kal_uint8   csfb_enhancement_item_status;
	kal_uint8   csfb_enhancement_item_status_in_test_mode;

    kal_uint8   is_eia0_by_sp1;

    kal_uint8   background_search_status_in_test_mode;

    nvram_errc_designated_carrier_inf_struct  designated_carrier_inf;
    kal_uint8   afr_timer;

    kal_uint8   csfb_enhancement_item_status_2;
    kal_uint8   csfb_enhancement_item_status_2_in_test_mode;
    
    kal_uint16  errc_detection_timer;
    kal_uint16  errc_conn_pg_local_rel_timer;

    kal_int16   lte_to_c2k_rsrp_threshold;
    kal_int16   c2k_to_lte_rsrp_delta;

    kal_uint16  hsr_inactive_timer_val;
    kal_uint8   hsr_on_thrs;
    kal_uint8   hsr_off_thrs;
    kal_uint8   hsr_monitor_mode;
    nvram_errc_hsr_preload_freq_struct      hsr_preload_freq_list[NVRAM_HSR_PRELOAD_FREQ_NUM_MAX];
    kal_uint8   hsr_using_8475;

    kal_int16   rsrq_threshold;
    kal_int16   max_rsrp_threshold;
    kal_int16   rsrp_delta;

    kal_int16   q_qualmin_thres_nvram;

    kal_int16   rsrp_serving_low_p_nvram;
    kal_int16   rsrp_gsm_x_low_p_nvram;
    kal_int16   rsrp_umts_x_low_p_nvram;
    kal_int16   rsrp_c2k_x_low_p_nvram;
    kal_int16   rsrq_serving_threshold_nvram;
    nvram_plmn_id_struct    ampr_plmn[NVRAM_AMPR_PLMN_NUM];

    kal_int16   rsrq_threshold_vilte;
    kal_int16   max_rsrp_threshold_vilte;
    kal_int16   rsrp_delta_vilte;
} nvram_ef_errc_performance_para_struct;

typedef struct {
    nvram_ef_errc_vzw_mru_entry_struct entry[NVRAM_LTE_VZW_MRU_NUM_MAX];
} nvram_ef_errc_vzw_mru_struct;

typedef struct
{
    kal_uint32 lte_ca_mask_band_white[NVRAM_LTE_CA_BITMASK_NUM];
    kal_uint32 lte_ca_mask_band_black[NVRAM_LTE_CA_BITMASK_NUM];
} nvram_ef_errc_lte_ca_combin_mask_struct;

typedef struct
{
    /* b0: CA.      1=enable, 0=disable. */
    /* b1: FFS.     1=enable, 0=disable. */
    /* b2: FFS.     1=enable, 0=disable. */
    /* b3: FFS.     1=enable, 0=disable. */
    /* b4: FFS.     1=enable, 0=disable. */
    /* b5: FFS.     1=enable, 0=disable. */
    /* b6: HPUE.    1=enable, 0=disable. */
    /* b7: UL64QAM. 1=enable, 0=disable. */
    kal_uint8 lte_feature_set;
} nvram_ef_errc_lte_feature_ctrl_struct;

typedef struct
{
    kal_uint8    LTE_scan_idle_interval;          /* unit in second, value range [1..120], default: 5 (default = 5 second, range: 1 - 120 sec, increment: 1 second) */
    kal_uint8    LTE_scan_idle_max;               /* unit in integer, value range [1..10], default: 5 (default = 5, range: 1 - 10, increment: 1) */
    kal_uint8    LTE_scan_active_duration_1xRTT;  /* unit in 500 milisecond, value range [1..20], default: 12 (default = 6 seconds, range: 500ms - 10 sec, increment: 500ms) */
    kal_uint8    LTE_scan_active_duration_DO;     /* unit in 100 milisecond, value range [1..10], default: 3 (default = 300ms, range: 100 - 1000 ms, increment: 100ms) */
    kal_uint16   LTE_scan_active_interval_1xRTT;  /* unit in 500 milisecond, value range [1..360], default: 120 (default = 1 minute, range: 1 - 3 minute, increment: 500ms) */
    kal_uint16   LTE_scan_active_interval_DO;     /* unit in 500 milisecond, value range [1..360], default: 120 (default = 1 minute, range: 1 - 3 minute, increment: 500ms) */
} nvram_ef_errc_vzw_lte_scan_enhance_struct;

#endif

#ifdef __UMTS_RAT__

#ifdef __CHANNEL_LOCK__
typedef struct
{
    EARFCN     earfcn;
    kal_uint16 pci;
}nvram_ch_lock_eas_info_struct;

typedef struct
{
    kal_uint16 uarfcn;
    kal_uint16 psc;
}nvram_ch_lock_uas_info_struct;

typedef struct
{
    kal_uint16 arfcn;
    kal_uint8  band_indicator;
}nvram_ch_lock_gas_info_struct;

typedef struct
{
    kal_bool  lock_supported;
    kal_uint8 lock_state;
    nvram_ch_lock_eas_info_struct eas_info;
    nvram_ch_lock_uas_info_struct uas_info;
    nvram_ch_lock_gas_info_struct gas_info;
}nvram_ef_ch_lock_info_struct;
#endif /* __CHANNEL_LOCK__ */

#endif

typedef struct
{
    kal_uint16 band;
    kal_uint8 ca_bw_clas_ul;
    kal_uint8 ca_bw_clas_dl;
}nvram_ef_ca_band_param_struct;

typedef struct
{
    kal_uint8 band_param_num;
    nvram_ef_ca_band_param_struct band_param[2];
    kal_bool is_2d1u_ca_comb;
}nvram_ef_ca_band_comb_struct;

typedef struct
{
    kal_uint32 band_comb_num;
    nvram_ef_ca_band_comb_struct band_comb[20];
}nvram_ef_ca_band_comb_list_struct;


#ifdef GEN_FOR_PC
BEGIN_NVRAM_DATA

#ifdef __LTE_RAT__

LID_BIT VER_LID(NVRAM_EF_ERRC_STORED_CARRIER_LID) nvram_ef_errc_stored_carrier_struct * NVRAM_EF_ERRC_STORED_CARRIER_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID) nvram_ef_errc_performance_para_struct * NVRAM_EF_ERRC_PERFORMANCE_PARA_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_ERRC_FINGER_PRINT_LID) nvram_ef_errc_fingerprint_record_struct * NVRAM_EF_ERRC_FINGER_PRINT_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_ERRC_LEARNED_MCC_LID) nvram_ef_errc_learned_mcc_record_struct * NVRAM_EF_ERRC_LEARNED_MCC_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_ERRC_STORED_CELL_LID) nvram_ef_errc_stored_cell_struct * NVRAM_EF_ERRC_STORED_CELL_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_ERRC_VZW_MRU_LID) nvram_ef_errc_vzw_mru_struct * NVRAM_EF_ERRC_VZW_MRU_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_ERRC_AFR_SETTING_LID) nvram_ef_errc_afr_setting_struct * NVRAM_EF_ERRC_AFR_SETTING_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_LTE_CAP_LID) nvram_ef_lte_cap_struct * NVRAM_EF_LTE_CAP_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID) nvram_ef_ue_eutra_cap_struct * NVRAM_EF_UE_EUTRA_CAP_CSFB_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID) nvram_ef_ue_eutra_cap_struct * NVRAM_EF_UE_EUTRA_CAP_MMDC_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_LTE_CAP_CA_COMBIN_MASK_LID) nvram_ef_errc_lte_ca_combin_mask_struct * NVRAM_EF_LTE_CA_COMBIN_MASK_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_LTE_FEATURE_CTRL_LID) nvram_ef_errc_lte_feature_ctrl_struct * NVRAM_EF_LTE_FEATURE_CTRL_TOTAL{};

LID_BIT VER_LID(NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_LID) nvram_ef_errc_vzw_lte_scan_enhance_struct * NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_TOTAL{};
LID_BIT VER_LID(NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_LID) nvram_ef_errc_vzw_lte_scan_enhance_struct * NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_TOTAL{};


LID_BIT VER_LID(NVRAM_EF_ERRC_RCM_CA_ENABLE_LIST_LID) nvram_ef_ca_band_comb_list_struct * NVRAM_EF_ERRC_RCM_CA_ENABLE_LIST_TOTAL{};
LID_BIT VER_LID(NVRAM_EF_ERRC_RCM_CA_DISABLE_LIST_LID) nvram_ef_ca_band_comb_list_struct * NVRAM_EF_ERRC_RCM_CA_DISABLE_LIST_TOTAL{};




#endif

#ifndef __L1_STANDALONE__

#ifdef __CHANNEL_LOCK__
	LID_BIT VER_LID(NVRAM_EF_CH_LOCK_INFO_LID) nvram_ef_ch_lock_info_struct * NVRAM_EF_CH_LOCK_INFO_TOTAL{};
#endif /* __CHANNEL_LOCK__ */

#endif



END_NVRAM_DATA
#endif	/*GEN FOR PC*/

#ifdef __cplusplus
}
#endif 

#endif  /* !NVRAM_NOT_PRESENT */
#endif
