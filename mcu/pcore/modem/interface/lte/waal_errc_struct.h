/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2016
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
 *   waal_errc_struct.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *  Messages and common definitions for WAAL-ERRC interface
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 10 13 2016 helen.hsieh
 * [MOLY00205995] [91LWA][MP5][MOB] rel-13 LWA feature check-in
 * 
 * add is_wlan_resource_available to waal_errc_wlan_measurement_ind_struct interface
 *
 * 08 16 2016 louis.lu
 * [MOLY00197123] [LWA][WAAL][ERRC] Add is_wlan_resource_available into xxx_measurement_ind struct
 * 	
 * 	Revert interface modification on waal_errc_wlan_measurement_ind_struct
 *
 * 08 12 2016 louis.lu
 * [MOLY00197123] [LWA][WAAL][ERRC] Add is_wlan_resource_available into xxx_measurement_ind struct
 * 	
 * 	Interface modification on waal_errc_wlan_measurement_ind_struct
 *
 * 07 13 2016 tc.chang
 * [MOLY00189196] LWA support.
 *
 ****************************************************************************/


#ifndef  _WAAL_ERRC_STRUCT_H_
#define  _WAAL_ERRC_STRUCT_H_

#include "kal_general_types.h"
#include "kal_public_defs.h"

#define WAAL_ERRC_WLAN_MAX_MEAS_OBJ_BAND_NUM 2
#define WAAL_ERRC_WLAN_MAX_WLAN_NUM 32
#define WAAL_ERRC_WLAN_MAX_CARR_INFO_NUM 8
#define WAAL_ERRC_WLAN_MAX_CARR_INFO_CHANNEL_NUM 16
#define WAAL_ERRC_WLAN_MAX_MEAS_OBJECT_NUM 10
#define WAAL_ERRC_WLAN_MAX_MEAS_RESULT_NUM 33

#define WAAL_ERRC_WLAN_RSSI_NEG_INFINITY -128
#define WAAL_ERRC_WLAN_RSSI_POS_INFINITY 127

typedef enum
{
    WAAL_ERRC_WLAN_BAND_2_DOT_4,
    WAAL_ERRC_WLAN_BAND_5
} waal_errc_wlan_band_enum;

typedef enum
{
    WAAL_ERRC_WLAN_LWA_CONNECTION_SUCCESS,
    WAAL_ERRC_WLAN_LWA_CONNECTION_FAILURE
} waal_errc_wlan_lwa_connect_result_enum;

typedef enum
{
    WAAL_ERRC_WLAN_LWA_FAIL_CAUSE_RADIO_LINK_PROBLEM,
    WAAL_ERRC_WLAN_LWA_FAIL_CAUSE_UE_INTERNAL_PROBLEM
} waal_errc_wlan_lwa_failure_cause_enum;

typedef enum
{
    WAAL_ERRC_WLAN_COUNTRY_CODE_USA,
    WAAL_ERRC_WLAN_COUNTRY_CODE_EUROPE,
    WAAL_ERRC_WLAN_COUNTRY_CODE_JAPAN,
    WAAL_ERRC_WLAN_COUNTRY_CODE_GLOBAL,
} waal_errc_wlan_country_code_enum;

typedef struct
{
    /* Length 0 means that ssid is not present. */
    kal_uint8 ssid_len;
    kal_uint8 ssid[32];

    kal_bool bssid_valid;
    kal_uint8 bssid[6];

    kal_bool hessid_valid;
    kal_uint8 hessid[6];
} waal_errc_wlan_id_struct;

typedef struct
{
    kal_bool operating_class_valid;
    kal_uint8 operating_class;

    kal_bool country_code_valid;
    waal_errc_wlan_country_code_enum country_code;

    /* Length 0 means that the list is not present. */
    kal_uint8 wlan_channel_list_len;
    kal_uint8 wlan_channel_list[WAAL_ERRC_WLAN_MAX_CARR_INFO_CHANNEL_NUM];
} waal_errc_wlan_carrier_info_struct;

typedef struct
{
    kal_bool report_carrier_info;
    kal_bool report_available_admission_capacity;
    kal_bool report_backhaul_dl_bw;
    kal_bool report_backhaul_ul_bw;
    kal_bool report_channel_utilization;
    kal_bool report_station_count;
} waal_errc_wlan_report_quantity_struct;

typedef struct
{
    kal_uint8 meas_object_id;

    kal_uint8 wlan_list_len;
    waal_errc_wlan_id_struct wlan_list[WAAL_ERRC_WLAN_MAX_WLAN_NUM];

    /* Length 0 means that the list is not present. */
    kal_uint8 wlan_band_list_len;
    waal_errc_wlan_band_enum wlan_band_list[WAAL_ERRC_WLAN_MAX_MEAS_OBJ_BAND_NUM];

    /* Length 0 means that the list is not present. */
    kal_uint8 carrier_info_list_len;
    waal_errc_wlan_carrier_info_struct carrier_info_list[WAAL_ERRC_WLAN_MAX_CARR_INFO_NUM];

    waal_errc_wlan_report_quantity_struct report_quantities;
} waal_errc_wlan_meas_object_struct;

typedef struct
{
    waal_errc_wlan_id_struct wlan_id;
    /* RSSI has two special values: negative infinity (-128) and positive infinity (127).
       Otherwise value range is [-100, 39] */
    kal_int8 rssi;
    waal_errc_wlan_band_enum band;
    kal_bool connected;

    kal_bool carrier_info_valid;
    waal_errc_wlan_carrier_info_struct carrier_info;

    kal_bool available_admission_capacity_valid;
    kal_uint16 available_admission_capacity;

    kal_bool backhaul_dl_bw_valid;
    kal_uint64 backhaul_dl_bw;

    kal_bool backhaul_ul_bw_valid;
    kal_uint64 backhaul_ul_bw;

    kal_bool channel_utilization_valid;
    kal_uint8 channel_utilization;

    kal_bool station_count_valid;
    kal_uint16 station_count;
} waal_errc_wlan_meas_result_struct;

/* MSG_ID_WAAL_ERRC_WLAN_CAPABILITY_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 wlan_mac_address[6];
    kal_bool band_2_dot_4_supported;
    kal_bool band_5_supported;
} waal_errc_wlan_capability_ind_struct;

/* MSG_ID_WAAL_ERRC_WLAN_LWA_CONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 wlan_mobility_set_list_len;
    waal_errc_wlan_id_struct wlan_mobility_set_list[WAAL_ERRC_WLAN_MAX_WLAN_NUM];

    /* S-Kwt encoding:
         bits 0..7  encoded in s_kwt[0]
         bits 8..15 encoded in s_kwt[1]
          ...
       First bit of S-Kwt is the MSB of s_kwt[0]. */
    kal_bool s_kwt_valid;
    kal_uint8 s_kwt[32];
} waal_errc_wlan_lwa_connect_req_struct;

/* MSG_ID_WAAL_ERRC_WLAN_LWA_CONNECT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    waal_errc_wlan_lwa_connect_result_enum result;
    waal_errc_wlan_lwa_failure_cause_enum failure_cause;
} waal_errc_wlan_lwa_connect_cnf_struct;

/* MSG_ID_WAAL_ERRC_WLAN_LWA_LOST_IND */
typedef struct
{
    LOCAL_PARA_HDR
    waal_errc_wlan_lwa_failure_cause_enum cause;
} waal_errc_wlan_lwa_lost_ind_struct;

/* MSG_ID_WAAL_ERRC_WLAN_MEASUREMENT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 filter_coefficient;

    kal_uint8 meas_object_list_len;
    waal_errc_wlan_meas_object_struct meas_object_list[WAAL_ERRC_WLAN_MAX_MEAS_OBJECT_NUM];
} waal_errc_wlan_measurement_req_struct;

/* MSG_ID_WAAL_ERRC_WLAN_MEASUREMENT_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool  is_wlan_resource_available;
    kal_uint8 meas_object_id;

    kal_uint8 meas_result_list_len;
    waal_errc_wlan_meas_result_struct meas_result_list[WAAL_ERRC_WLAN_MAX_MEAS_RESULT_NUM];

#ifdef UNIT_TEST
    kal_uint32 meas_ind_ms_diff;
#endif /* UNIT_TEST */
} waal_errc_wlan_measurement_ind_struct;

#endif /* _WAAL_ERRC_STRUCT_H_ */
