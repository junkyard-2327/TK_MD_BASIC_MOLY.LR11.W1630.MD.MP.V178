/******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   ratdm_export_api.h
 *
 * Project:
 * --------------------------------------------------------
 *
 *
 * Description:
 * --------------------------------------------------------
 *
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * 10 06 2016 head.hsu
 * [MOLY00206501] [91LWA][MP5][RATDM] rel-13 LWA feature check-in
 *
 * 06 17 2016 head.hsu
 * [MOLY00184273] Multiple-PS - RATDM part
 * 	[RATDM]
 * 	01. External function (sim_interface)
 * 	02. L+L RATDM_LTE revision (duplicate, UL sim_interface, send primitive)
 * 	03. multi-PS internal change for DSDS (gemini guard, main-PS, RATDM macro define)
 * 	04. set CURRENT_SIM early
 * 	05. sub-frame tick source bitmap for L+L
 * 	06. MD2AP 23G scenario bitmap
 * 	07. ESM IDLE_LEAVE_IND ebi bitmap, IDLE_LEAVE_REJ handling
 * 	08. DATA-ALLOW-REQ/main-PS switch
 * 	09. tcm_get_ims_flag_by_nsapi query time refine
 * 	10. re-factor get knowing ims bearer funciton
 * 	11. leave drx for ims refine
 * 	12. auto switch FLC profile before 1st DATA-ALLOW-REQ
 *
 * 04 28 2016 head.hsu
 * [MOLY00175408] Multiple-PS/Remote-SIM interfaces phase2
 * 	[RATDM] external interface with __MULTIPLE_PS__ check-in
 * 	1. ESM-RATDM interface
 * 	2. SHAQ api interface
 * 	3. UPCM-RATDM interface
 *
 * 05 20 2015 head.hsu
 * [MOLY00089131] [MT6291 Gemini] L+W+W+W code revision check in
 * 	;RATDM/RABM/PDCP/CSR part check-in
 *
 * 02 13 2015 yungfu.chen
 * [MOLY00091822] RATDM reorganization
 *
 * 12 23 2013 yungfu.chen
 * [MOLY00047398] [MT6582LTE][WWFT][UK][Vodafone][EE] CSFB performance anlysis [only for UKFT]
 *
 ******************************************************************************/
#ifndef _RATDM_EXPORT_API_H
#define _RATDM_EXPORT_API_H

/* KAL - RTOS Abstraction Layer */
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "qmu_bm.h"

typedef struct
{
	qbm_gpd *p_pri_head; // priority SDU head.
    qbm_gpd *p_pri_tail; // priority SDU tail.
    qbm_gpd *p_head; // normal SDU head.
    qbm_gpd *p_tail; // normal SDU tail.
} ratcmn_ul_sdu_t;
typedef ratcmn_ul_sdu_t ratdm_lte_ul_sdu_t;

/* MACRO DEFINITION */
/*! @brief define predefined bearer id for EMBMS data plane.
 *  Data plane uses this virtual bearer id (4) on EMBMS packets. */
#define MBMS_DEFAULT_EBI (4)

#ifndef __MULTIPLE_PS__
#undef RATDM_EXPAND
#define RATDM_EXPAND(x) x
/* ratdm_autogen_sim_idx(), only TDD PDCP/RABM will use autogen, TDD 3G only on SIM 1 */
#define ratdm_rabm_callback_increment_rx_data_octets(...) RATDM_EXPAND(_ratdm_rabm_callback_increment_rx_data_octets(__VA_ARGS__, ratdm_autogen_sim_idx(), NULL))
#define _ratdm_rabm_callback_increment_rx_data_octets(tcm_cid, increment_value, sim_interface, ...) ratdm_rabm_callback_increment_rx_data_octets(tcm_cid, increment_value, sim_interface)

#define ratdm_rabm_callback_reset_rx_data_octets(...) RATDM_EXPAND(_ratdm_rabm_callback_reset_rx_data_octets(__VA_ARGS__, ratdm_autogen_sim_idx(), NULL))
#define _ratdm_rabm_callback_reset_rx_data_octets(tcm_cid, sim_interface, ...) ratdm_rabm_callback_reset_rx_data_octets(tcm_cid, sim_interface)

#define ratdm_rabm_callback_set_new_vr_value(...) RATDM_EXPAND(_ratdm_rabm_callback_set_new_vr_value(__VA_ARGS__, ratdm_autogen_sim_idx(), NULL))
#define _ratdm_rabm_callback_set_new_vr_value(nsapi, new_vr_value, sim_interface, ...) ratdm_rabm_callback_set_new_vr_value(nsapi, new_vr_value, sim_interface)

#define ratdm_ratadp_rcv_ul_sdu(...) RATDM_EXPAND(_ratdm_ratadp_rcv_ul_sdu(__VA_ARGS__, ratdm_autogen_sim_idx(), NULL))
#define _ratdm_ratadp_rcv_ul_sdu(ebi, p_sdus, sim_interface, ...) ratdm_ratadp_rcv_ul_sdu(ebi, p_sdus, sim_interface)
#endif // ~ #ifndef __MULTIPLE_PS__

/* EXPORT FUNCTIONS */
/* RABM/PDCP/RATDM */
extern void ratdm_rabm_callback_increment_rx_data_octets(kal_uint8 tcm_cid, kal_uint64 increment_value, kal_uint8 sim_interface);
extern void ratdm_rabm_callback_reset_rx_data_octets(kal_uint8 tcm_cid, kal_uint8 sim_interface);
extern void ratdm_rabm_callback_set_new_vr_value(kal_uint8 nsapi, kal_uint16 new_vr_value, kal_uint8 sim_interface);

/* UPCM */
/* Multimode Callback Function */
#ifdef __MULTIPLE_PS__
typedef void (*ratdm_lte_dlvr_dl_sdu_f)(kal_uint32 ebi, qbm_gpd *p_head, qbm_gpd *p_tail, kal_uint8 sim_interface);
typedef void (*ratdm_lte_rollback_sdu_f)(kal_uint32 ebi, qbm_gpd *p_head, qbm_gpd *p_tail, kal_uint8 sim_interface);
#else
typedef void (*ratdm_lte_dlvr_dl_sdu_f)(kal_uint32 ebi, qbm_gpd *p_head, qbm_gpd *p_tail);
typedef void (*ratdm_lte_rollback_sdu_f)(kal_uint32 ebi, qbm_gpd *p_head, qbm_gpd *p_tail);
#endif // ~ #ifdef __MULTIPLE_PS__
typedef void (*ratdm_notify_lte_tick_f)(kal_bool is_lte_tick);

extern void ratdm_ratadp_init(void);
extern void ratdm_ratadp_rcv_ul_sdu(kal_uint32 ebi, ratdm_lte_ul_sdu_t *p_sdus, kal_uint8 sim_interface);
extern void ratdm_ratadp_reg_cbk_rollback_sdu(ratdm_lte_rollback_sdu_f pf_rollback_sdu);
extern void ratdm_ratadp_reg_cbk_dlvr_dl_sdu(ratdm_lte_dlvr_dl_sdu_f pf_dlvr_dl_sdu);
extern void ratdm_reg_cbk_notify_lte_tick(ratdm_notify_lte_tick_f pf_notify);
//#ifdef __LWA_SUPPORT__
extern void ratdm_reg_cbk_notify_lte_tick_stat_to_epdcp(ratdm_notify_lte_tick_f pf_notify);
//#endif
extern kal_uint8 ratdm_autogen_sim_idx();

#endif /* _RATDM_EXPORT_API_H */
