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
 *   qmu_bm_flc.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *  FLC related header file. used for 2/3G RAT.
 *
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  QMU_BM_FLC_INC
#define  QMU_BM_FLC_INC
/****************************************************************************/

#include "qmu_bm.h"

#ifdef __QBM_USE_FLC__
/****************************************************************************/

#include "flc2_config.h"

/****************************************************************************
 * Type Definitions
 ****************************************************************************/

#define QBM_FLC_UL_POOL_ID_HIF_UL      FLC2_POOL_ID_NPDU_UL
#define QBM_FLC_UL_POOL_ID_HIF_UL_01   FLC2_POOL_ID_NPDU_UL_01
#define QBM_FLC_UL_POOL_ID_HIF_UL_02   FLC2_POOL_ID_HIF_UL_02
#define QBM_FLC_UL_POOL_ID_HIF_UL_S    FLC2_POOL_ID_HIFSMALL_UL
#define QBM_FLC_UL_POOL_ID_NET_UL      FLC2_POOL_ID_INTERNAL_UL
#define QBM_FLC_UL_POOL_ID_NET_UL_SHRD FLC2_POOL_ID_NET_UL_SHARED
#define QBM_FLC_UL_POOL_ID_HIF_UL_SPD  FLC2_POOL_ID_HIF_UL_SPD

/****************************************************************************
 * Exported Macros
 ****************************************************************************/

/*
 * Used to get FLC used pointer, used to dispatch buffer to 2/3G 
 */
#define QBM_FLC_UL_GET_FLC_PTR(_p) ((kal_uint8*)(_p) - QBM_FLC_UL_PD_OFFSET)
/*
 * Used to get PD pointer from FLC pointer ,used to dispatch buffer to non-2/3G (e.g LTE)
 */
#define QBM_FLC_UL_GET_PD_PTR(_p) ((kal_uint8*)(_p) + QBM_FLC_UL_PD_OFFSET)

/*
 * Store FLC POOL ID in QBM Header.
 */
#define QBM_SET_FLC_POOL_ID(_p, _pool_id) \
	(GET_BM_HDR_PTR(_p)->flc_pool_id = _pool_id)

/*
 * Get FLC POOL ID from QBM Header.
 */
#define QBM_GET_FLC_POOL_ID(_p) \
	(GET_BM_HDR_PTR(_p)->flc_pool_id)

/****************************************************************************
 * Exported Function Prototypes
 ****************************************************************************/

/**
 * @brief qbm_release_to_flc
 * Trigger QBM to release all buffers which are from FLC to FLC.
 * Because for 2/3G, the buffer number should be restrict by FLC pool.
 * If QBM hold all buffers, the restrict meachinasm won't be worked.
 */
void qbm_release_to_flc(void);

/**
 * @brief qbm_reload_all_from_flc 
 * Reload all buffers from FLC.
 * When leave23g some buffers may stay at FLC pool.
 * But FLC won't have API to query remain pool size.
 * For qbm_get_buff_remain_num works, we need to get all buffers from FLC.
 */
void qbm_reload_all_from_flc(void);

/****************************************************************************/
/*! @brief Free RXSPD from FLC2 to qbm

    This function is only invoked by MOD_FLC2. QBM_FLC_UL_POOL_ID_HIF_UL_SPD
 
    @param[in] buff_ptr a pointer to a peer_buff struct
    
    @since UMOLY
*/
/****************************************************************************/
extern void qbm_flc2_free_rxspd(peer_buff_struct *buff_ptr);

/****************************************************************************/
#endif/*__QBM_USE_FLC__*/

/****************************************************************************/
#endif   /* ----- #ifndef QMU_BM_FLC_INC  ----- */

