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
 * Filename:
 * ---------
 *   ratdm_el2_struct.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ******************************************************************************
 * $Log$
 *
 * 10 06 2016 head.hsu
 * [MOLY00206501] [91LWA][MP5][RATDM] rel-13 LWA feature check-in
 *
 * 05 25 2015 head.hsu
 * [MOLY00109855] [TK6291E1][1st AIQ Call][UMOLY][4G][TDD][CA] Assert Fail ccci_debug.c 498
 * RATDM switch regular tick source via EMAC_SCH_STATUS_IND instead of LTE IDLE state
 *
 *
 ******************************************************************************/

#ifndef RATDM_EL2_STRUCT_H
#define RATDM_EL2_STRUCT_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "abs_time.h"
#include "ltm_el2_struct.h"
#include "qmu_bm.h"

#define RATDM_EPDCP_MAX_NUM_DRB 8

/* mapping to the definitions in ltm_el2.h */
typedef drb_ulsdu_info_head_t   drb_ulsdu_info_t;
#define ULSDU_INFO_FLAG_PRIORITY    ULSDU_INFO_HEAD_FLAG_PRIORITY
#define ULSDU_INFO_FLAG_CTRL_PDU    ULSDU_INFO_HEAD_FLAG_CTRL_PDU
#define ULSDU_INFO_FLAG_RETX_WI_SN  ULSDU_INFO_HEAD_FLAG_RETX_WI_SN
#define GET_ULSDU_INFO(_p)          GET_ULSDU_INFO_HEAD(_p)


typedef struct
{
    qbm_gpd *p_head;
    qbm_gpd *p_tail;
    kal_uint32 total_size; /* bytes */
    kal_uint32 gpd_cnt;
}ratdm_lte_dlvr_data_struct;

typedef struct
{
    kal_uint32 rb_idx;
    qbm_gpd *p_head;
    qbm_gpd *p_tail;
}epdcp_dlvr_data_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint32 rb_idx; /* RB Index (2~9) */
    ratdm_lte_dlvr_data_struct data_pri; /* Priority data (e.g: TCP ACK) */
    ratdm_lte_dlvr_data_struct data; /* Normal data */
}ratdm_epdcp_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint32 num;
    epdcp_dlvr_data_struct data[RATDM_EPDCP_MAX_NUM_DRB];
}ratdm_epdcp_data_ind_struct;

typedef ratdm_epdcp_data_ind_struct ratdm_epdcp_rbuf_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR

    epdcp_dlvr_data_struct data;
}ratdm_epdcp_mtch_data_ind_struct;

//#ifdef __LWA_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint32 message;
}wlan_epdcp_ctrl_msg_ind_struct;
//#endif

typedef struct
{
    LOCAL_PARA_HDR

    kal_bool is_sch_open;
}ratdm_emac_sch_status_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR

    ABS_TICK_TIME wakeup_time;
}ratdm_emac_next_drx_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_bool is_ims_data;
}ratdm_emac_leave_drx_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint32 rb_idx;
    kal_uint32 eps_br_id;
    void *p_retx_head; /* TGPD list */
    void *p_retx_tail;
}ratdm_epdcp_ul_data_redir_ind_struct;

#endif /* RATDM_EL2_STRUCT_H */
