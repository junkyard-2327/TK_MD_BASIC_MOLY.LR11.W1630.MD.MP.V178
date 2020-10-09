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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * waal_ipc_msg_struct.h
 *
 * Project:
 * --------
 * UMOLY
 *
 * Description:
 * ------------
 * Data structure definition of WAAL IPC message.
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _WAAL_IPC_MSG_STRUCT_H
#define _WAAL_IPC_MSG_STRUCT_H
/****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"

#include "waal_errc_struct.h"

/****************************************************************************/

#define LWAD_WAAL_WLAN_MAX_MEAS_RESULT_NUM      20

/****************************************************************************/

// MSG_ID_LWAD_WAAL_WLAN_CAPABILITY_REQ
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 version;     // Interface version. First version is 1.
} lwad_waal_wlan_capability_req_struct;

/* MSG_ID_LWAD_WAAL_WLAN_MEASUREMENT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 filter_coefficient;

    kal_uint8 meas_object_list_index;
    kal_uint8 meas_object_list_len;
    waal_errc_wlan_meas_object_struct meas_object;
} lwad_waal_wlan_measurement_req_struct;

/* MSG_ID_LWAD_WAAL_WLAN_MEASUREMENT_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_wlan_resource_available;
    kal_uint8 meas_object_id;
    kal_uint8 meas_result_list_total;

    kal_uint8 meas_result_list_start_index;
    kal_uint8 meas_result_list_len;
    waal_errc_wlan_meas_result_struct meas_result_list[LWAD_WAAL_WLAN_MAX_MEAS_RESULT_NUM];
} lwad_waal_wlan_measurement_ind_struct;

/****************************************************************************/
/* Other interfaces are same as WAAL - ERRC interfaces */

/* MSG_ID_LWAD_WAAL_WLAN_CAPABILITY_IND */
typedef waal_errc_wlan_capability_ind_struct lwad_waal_wlan_capability_ind_struct;

/* MSG_ID_WAAL_ERRC_WLAN_LWA_CONNECT_REQ */
typedef waal_errc_wlan_lwa_connect_req_struct lwad_waal_wlan_lwa_connect_req_struct;

/* MSG_ID_WAAL_ERRC_WLAN_LWA_CONNECT_CNF */
typedef waal_errc_wlan_lwa_connect_cnf_struct lwad_waal_wlan_lwa_connect_cnf_struct;

/* MSG_ID_WAAL_ERRC_WLAN_LWA_LOST_IND */
typedef waal_errc_wlan_lwa_lost_ind_struct lwad_waal_wlan_lwa_lost_ind_struct;

/****************************************************************************/
#endif /* _WAAL_IPC_MSG_STRUCT_H */
