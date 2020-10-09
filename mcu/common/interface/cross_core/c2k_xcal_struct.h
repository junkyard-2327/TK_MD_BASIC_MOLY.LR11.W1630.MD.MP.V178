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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   c2k_xcal_struct.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   EM for C2K XCAL.
 *
 * Author:
 * -------
 *   
 * 
 *******************************************************************************/
#ifndef C2K_XCAL_STRUCT_H
#define C2K_XCAL_STRUCT_H

#define C2K_EM_INFO_MAX_LEN  2048

#define C2K_DATA_BURST_MAX_FIELDS   255

#define C2K_XCAL_EM_NUM     (EM_C2K_XCAL_INFO_LAST - EM_C2K_XCAL_INFO_BEGIN + 1)

typedef enum
{
   C2K_OTA_ORIGINATION_MESSAGE,
   C2K_OTA_ALERT_WITH_INFO_MESSAGE,
   C2K_OTA_SERVICE_COON_COMP_MESSAGE,
   C2K_OTA_PAGE_RESPONSE_MESSAGE
}c2k_xcal_ota_msg_type_enum;

typedef struct
{
  LOCAL_PARA_HDR
  c2k_xcal_ota_msg_type_enum event;
} em_c2k_xcal_ota_event_info_ind_struct;

/* Data burst message of  F-DSCH and R-DSCH.*/
typedef struct
{
  LOCAL_PARA_HDR
  kal_uint8     msg_number;
  kal_uint8     burst_type;
  kal_uint8     num_msgs;
  kal_uint8     num_fields;
  kal_uint8     chari[C2K_DATA_BURST_MAX_FIELDS];
} em_c2k_xcal_ota_fdsch_info_ind_struct,
  em_c2k_xcal_ota_rdsch_info_ind_struct;


/* For C2K_L4CPS_EM_UPDATE_REQ */
typedef struct
{
  LOCAL_PARA_HDR
  em_info_status_enum  info_request[C2K_XCAL_EM_NUM];
} c2k_l4cps_em_update_req_struct; //with prefix of "c2k_", otherwise, MD1 build error.

/* For C2K_L4CPS_EM_UPDATE_CNF */
typedef struct
{
  LOCAL_PARA_HDR
} c2k_l4cps_em_update_cnf_struct; //with prefix of "c2k_", otherwise, MD1 build error.

/* For DHL_C2K_EM_LOGGING_REQ */
typedef struct
{
  LOCAL_PARA_HDR
  kal_uint32    sequence;
  kal_uint32    data_length;
  kal_uint8     data[C2K_EM_INFO_MAX_LEN];  
  kal_uint32    em_info_offset; //Offset of current EM ID to EM_C2K_XCAL_OTA_EVENT_INFO = EM_C2K_XCAL_INFO_BEGIN.
} dhl_c2k_em_logging_req_struct;


/* For DHL_C2K_EM_LOGGING_CNF */
typedef struct
{
  LOCAL_PARA_HDR
  kal_uint32    sequence; //The value should be set to the same value as in the corresponding Req ilm.
  kal_bool      result;
  kal_uint8     reserved; //Reserved for future use.
} dhl_c2k_em_logging_cnf_struct;


#endif

