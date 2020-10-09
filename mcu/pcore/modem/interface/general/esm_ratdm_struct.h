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
 *   esm_ratdm_struct.h
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
 * 05 05 2016 andrew.wu
 * [MOLY00177477] [Interface] check-in interface code for MOLY00174746
 * .
 *
 * 04 28 2016 head.hsu
 * [MOLY00175408] Multiple-PS/Remote-SIM interfaces phase2
 * 	[RATDM] external interface with __MULTIPLE_PS__ check-in
 * 	1. ESM-RATDM interface
 * 	2. SHAQ api interface
 * 	3. UPCM-RATDM interface
 *
 * 04 16 2015 carlson.lin
 * [MOLY00091769] [GEMINI] Trigger TAU/SR after GEMINI resume
 * Add iterface (OA Domain)
 *
 * 
 ******************************************************************************/

#ifndef ESM_RATDM_STRUCT_H
#define ESM_RATDM_STRUCT_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "qmu_bm.h"

/* the available EBI range is 5~15. The maximum number of EPS bearer is eleven. */
#define MAX_EPSB_NUMBER 11

typedef enum
{
    ESM_QCI_RESERVED_VALUE_0 = 0, // Reserved
    ESM_QCI_1 = 1, // QCI_1, Conversational Vocie
    ESM_QCI_2 = 2, // QCI_2, Conversational Video (Live Streaming)
    ESM_QCI_3 = 3, // QCI_3, Real Time Gaming
    ESM_QCI_4 = 4, // QCI_4, Non-Conversational Video (Buffered Streaming)
    ESM_QCI_5 = 5, // QCI_5, IMS Signaling
    ESM_QCI_6 = 6, // QCI_6, Video (Buffered Streaming), TCP-based (e.g., www, e-mail, chat, ftp, p2p file sharing, progressive video, etc)
    ESM_QCI_7 = 7, // QCI_7, Voice, Video (Live Streaming), Interactive Gaming
    ESM_QCI_8 = 8, // QCI_8, Video (Buffered Streaming), TCP-based (e.g., www, e-mail, chat, ftp, p2p file sharing, progressive video, etc)
    ESM_QCI_9 = 9, // QCI_9, Video (Buffered Streaming), TCP-based (e.g., www, e-mail, chat, ftp, p2p file sharing, progressive video, etc)
    ESM_QCI_RESERVED_VALUE_10 = 10, // Reserved (10~127)
    ESM_QCI_RESERVED_VALUE_127 = 127, // Reserved (10~127)
    ESM_QCI_OPERATOR_SPECIFIC_QCI_MIN_VALUE = 128, // Operator-specific QCIs 128~254
    ESM_QCI_OPERATOR_SPECIFIC_QCI_MAX_VALUE = 254, // Operator-specific QCIs 128~254
    ESM_QCI_RESERVED_VALUE_255 = 255 // Reserved
} esm_qci_enum;

typedef enum
{
    ESM_IDLE_LEAVE_REJ_UNSPEFICIFIED  = 0x01,
    ESM_IDLE_LEAVE_REJ_DETACH         = 0x02,
    ESM_IDLE_LEAVE_REJ_COVERAGE_OUT   = 0x10,
    ESM_IDLE_LEAVE_REJ_AC_BARRED      = 0x11,
    ESM_IDLE_LEAVE_REJ_NW_REJECT      = 0x12,
    ESM_IDLE_LEAVE_REJ_GEMINI_SUSPEND = 0x13,
    ESM_IDLE_LEAVE_REJ_T3346_RUNNING  = 0x14,
    ESM_IDLE_LEAVE_REJ_T3417TO        = 0x15,
    ESM_IDLE_LEAVE_REJ_OTHERS         = 0x20,
}idle_leave_rej_cause_enum;

typedef struct
{
    kal_uint8 ebi;
    kal_uint8 rb_idx;
}ebi_rbidx_map_struct;

typedef struct
{
    LOCAL_PARA_HDR

    /* EPS bearer identity which ESM wants to initialize */
    kal_uint8 ebi;

    /*
    * Default EPS bearer identity
    * If the EPS bearer ESM wants to activate is a default EPS bearer,
    * linked_ebi will be set to the same as ebi
    */
    kal_uint8 linked_ebi;

    /* Hardware channel id (choose by ERRC) */
    kal_uint8 rb_idx;

    esm_qci_enum qci;
    
    /* 23G ralated parameters */
    kal_bool is_llc_sapi_present;
    kal_uint8 llc_sapi;

    kal_bool is_ug_qos_present;
    qos_struct ug_qos;

    kal_bool is_radio_priority_present;
    kal_uint8 radio_priority;

    kal_bool is_pfi_present;
    kal_uint8 pfi;   
}esm_ratdm_epsb_init_req_struct;

typedef struct
{
    LOCAL_PARA_HDR

    /* EPS bearer identity which ESM wants to activate */
    kal_uint8 ebi;
}esm_ratdm_epsb_act_req_struct;


typedef struct
{
    LOCAL_PARA_HDR

    /* EPS bearer identity which ESM wants to deactivate */
    kal_uint8 ebi;
}esm_ratdm_epsb_deact_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ebi;
    /* 4G ralated parameters */ 
    esm_qci_enum qci;
    /* 23G ralated parameters */
    kal_bool is_llc_sapi_present;
    kal_uint8 llc_sapi;

    kal_bool is_ug_qos_present;
    qos_struct ug_qos;

    kal_bool is_radio_priority_present;
    kal_uint8 radio_priority;

    kal_bool is_pfi_present;
    kal_uint8 pfi;
} esm_ratdm_epsb_modify_req_struct;

typedef struct
{
    LOCAL_PARA_HDR

    /* The total number of EPS bearer with DRB established after UE enter connected mode */
    kal_uint8 epsb_num;

    /* Mapping between EBI & RB index */
    ebi_rbidx_map_struct ebi_rbidx_map[MAX_EPSB_NUMBER];
}esm_ratdm_idle_leave_req_struct;

typedef struct
{
    LOCAL_PARA_HDR

    /* The failure cause of leave idle */
    idle_leave_rej_cause_enum idle_leave_rej_cause;
}esm_ratdm_idle_leave_rej_struct;

typedef struct
{
    LOCAL_PARA_HDR

#ifdef __MULTIPLE_PS__
    /* Which EPS bearers has data */
    kal_uint16 ebi_btmp;
#else
    /* Which EPS bearer has data */
    kal_uint8 ebi;
#endif // ~ #ifdef __MULTIPLE_PS__
}esm_ratdm_idle_leave_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR

    /* Whether UL data is coming */
    kal_bool is_ul_data_coming;
}esm_ratdm_query_ul_data_status_cnf_struct;

/* Adaptation between ESM and LTM */
typedef esm_ratdm_epsb_init_req_struct esm_ltm_epsb_init_req_struct;
typedef esm_ratdm_epsb_act_req_struct esm_ltm_epsb_act_req_struct;
typedef esm_ratdm_epsb_deact_req_struct esm_ltm_epsb_deact_req_struct;
typedef esm_ratdm_epsb_modify_req_struct esm_ltm_epsb_modify_req_struct;
typedef esm_ratdm_idle_leave_req_struct esm_ltm_idle_leave_req_struct;
typedef esm_ratdm_idle_leave_rej_struct esm_ltm_idle_leave_rej_struct;
typedef esm_ratdm_idle_leave_ind_struct esm_ltm_idle_leave_ind_struct;
typedef esm_ratdm_query_ul_data_status_cnf_struct esm_ltm_query_ul_data_status_cnf_struct;
#endif /* ESM_RATDM_STRUCT_H */
