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
 *   global_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  global parameters definition
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _GLBOAL_DEF_H
#define _GLBOAL_DEF_H

#include "kal_public_defs.h"





#if !(defined(DUMMY_PROTOCOL) && defined(__GSM_RAT__))
extern module_type MOD_RRM;
extern module_type MOD_RLC;
extern module_type MOD_MPAL;
extern module_type MOD_MAC;
extern module_type MOD_LAPDM;
extern module_type MOD_AS;
extern module_type MOD_GAS;
extern module_type MOD_RMPC;
extern module_type MOD_REASM;

#if defined(__GEMINI__) || defined(__SGLTE__)
extern module_type MOD_RRM_2;
extern module_type MOD_RLC_2;
extern module_type MOD_MPAL_2;
extern module_type MOD_MAC_2;
extern module_type MOD_LAPDM_2;
extern module_type MOD_AS_2;
extern module_type MOD_GAS_2;
extern module_type MOD_RMPC_2;
extern module_type MOD_REASM_2;

#if (GEMINI_PLUS >= 3)
extern module_type MOD_RRM_3;
extern module_type MOD_RLC_3;
extern module_type MOD_MPAL_3;
extern module_type MOD_MAC_3;
extern module_type MOD_LAPDM_3;
extern module_type MOD_AS_3;
extern module_type MOD_GAS_3;
extern module_type MOD_RMPC_3;
extern module_type MOD_REASM_3;

#if (GEMINI_PLUS >= 4)
extern module_type MOD_RRM_4;
extern module_type MOD_RLC_4;
extern module_type MOD_MPAL_4;
extern module_type MOD_MAC_4;
extern module_type MOD_LAPDM_4;
extern module_type MOD_AS_4;
extern module_type MOD_GAS_4;
extern module_type MOD_RMPC_4;
extern module_type MOD_REASM_4;
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */

#endif /* __GEMINI__ || __SGLTE__ */
#endif

#ifdef  __UMTS_RAT__

/*dummy mod is specified to get task id by mod id, use mod_task_g*/
extern module_type  MOD_DUMMY_UL2;
/* module_type and mod_task_g*/

#ifndef DUMMY_PROTOCOL

extern module_type  MOD_URLC;
extern module_type  MOD_UMAC;
extern module_type  MOD_UL2;
#ifdef __GEMINI_WCDMA__
extern module_type  MOD_URLC_2;
extern module_type  MOD_UMAC_2;
extern module_type  MOD_UL2_2;
#if (GEMINI_PLUS_WCDMA >= 3)
extern module_type  MOD_URLC_3;
extern module_type  MOD_UMAC_3;
extern module_type  MOD_UL2_3;
#if (GEMINI_PLUS_WCDMA >= 4)
extern module_type  MOD_URLC_4;
extern module_type  MOD_UMAC_4;
extern module_type  MOD_UL2_4;
#endif /* GEMINI_PLUS_WCDMA >= 4 */
#endif /* GEMINI_PLUS_WCDMA >= 3 */
#endif /* __GEMINI_WCDMA__ */

#else

extern module_type  MOD_URLC;
extern module_type  MOD_UMAC;
extern module_type  MOD_UL2;
#ifdef __GEMINI_WCDMA__
extern module_type  MOD_URLC_2;
extern module_type  MOD_UMAC_2;
extern module_type  MOD_UL2_2;
#if (GEMINI_PLUS_WCDMA >= 3)
extern module_type  MOD_URLC_3;
extern module_type  MOD_UMAC_3;
extern module_type  MOD_UL2_3;
#if (GEMINI_PLUS_WCDMA >= 4)
extern module_type  MOD_URLC_4;
extern module_type  MOD_UMAC_4;
extern module_type  MOD_UL2_4;
#endif /* GEMINI_PLUS_WCDMA >= 4 */
#endif /* GEMINI_PLUS_WCDMA >= 3 */
#endif /* __GEMINI_WCDMA__ */

#endif /* DUMMY_PROTOCOL */

extern module_type  MOD_DUMMY_UL2D;

extern module_type  MOD_DRLC;
extern module_type  MOD_BMC;
extern module_type  MOD_UL2D;
extern module_type  MOD_PDCP;
extern module_type  MOD_RABM;
extern module_type  MOD_CSR;
#ifdef __GEMINI_WCDMA__
extern module_type  MOD_DRLC_2;
extern module_type  MOD_BMC_2;
extern module_type  MOD_UL2D_2;
extern module_type  MOD_PDCP_2;
extern module_type  MOD_RABM_2;
extern module_type  MOD_CSR_2;
#if (GEMINI_PLUS_WCDMA >= 3)
extern module_type  MOD_DRLC_3;
extern module_type  MOD_BMC_3;
extern module_type  MOD_UL2D_3;
extern module_type  MOD_PDCP_3;
extern module_type  MOD_RABM_3;
extern module_type  MOD_CSR_3;
#if (GEMINI_PLUS_WCDMA >= 4)
extern module_type  MOD_DRLC_4;
extern module_type  MOD_BMC_4;
extern module_type  MOD_UL2D_4;
extern module_type  MOD_PDCP_4;
extern module_type  MOD_RABM_4;
extern module_type  MOD_CSR_4;
#endif /* GEMINI_PLUS_WCDMA >= 4 */
#endif /* GEMINI_PLUS_WCDMA >= 3 */
#endif /* __GEMINI_WCDMA__ */


// MOD_ID for FDD UAS URR: start
/*dummy mod is specified to get task id by mod id, use mod_task_g*/
extern module_type MOD_DUMMY_URR;
/*extern module_type and mod_task_g*/

#ifndef DUMMY_PROTOCOL

extern module_type MOD_MEME;
extern module_type MOD_CSE;
extern module_type MOD_CSCE;
extern module_type MOD_SIBE;
extern module_type MOD_USIME;
extern module_type MOD_RRCE;
extern module_type MOD_SLCE;
extern module_type MOD_ADR;
extern module_type MOD_URR;
extern module_type MOD_DB;
#ifdef __GEMINI_WCDMA__
extern module_type MOD_MEME_2;
extern module_type MOD_CSE_2;
extern module_type MOD_CSCE_2;
extern module_type MOD_SIBE_2;
extern module_type MOD_USIME_2;
extern module_type MOD_RRCE_2;
extern module_type MOD_SLCE_2;
extern module_type MOD_ADR_2;
extern module_type MOD_URR_2;
extern module_type MOD_DB_2;
#if (GEMINI_PLUS_WCDMA >= 3)
extern module_type MOD_MEME_3;
extern module_type MOD_CSE_3;
extern module_type MOD_CSCE_3;
extern module_type MOD_SIBE_3;
extern module_type MOD_USIME_3;
extern module_type MOD_RRCE_3;
extern module_type MOD_SLCE_3;
extern module_type MOD_ADR_3;
extern module_type MOD_URR_3;
extern module_type MOD_DB_3;
#if (GEMINI_PLUS_WCDMA >= 4)
extern module_type MOD_MEME_4;
extern module_type MOD_CSE_4;
extern module_type MOD_CSCE_4;
extern module_type MOD_SIBE_4;
extern module_type MOD_USIME_4;
extern module_type MOD_RRCE_4;
extern module_type MOD_SLCE_4;
extern module_type MOD_ADR_4;
extern module_type MOD_URR_4;
extern module_type MOD_DB_4;
#endif /* GEMINI_PLUS_WCDMA >= 4 */
#endif /* GEMINI_PLUS_WCDMA >= 3 */
#endif /* __GEMINI_WCDMA__ */

#else

extern module_type MOD_MEME;
extern module_type MOD_CSE;
extern module_type MOD_CSCE;
extern module_type MOD_SIBE;
extern module_type MOD_USIME;
extern module_type MOD_RRCE;
extern module_type MOD_SLCE;
extern module_type MOD_ADR;
extern module_type MOD_URR;
extern module_type MOD_DB;
#ifdef __GEMINI_WCDMA__
extern module_type MOD_MEME_2;
extern module_type MOD_CSE_2;
extern module_type MOD_CSCE_2;
extern module_type MOD_SIBE_2;
extern module_type MOD_USIME_2;
extern module_type MOD_RRCE_2;
extern module_type MOD_SLCE_2;
extern module_type MOD_ADR_2;
extern module_type MOD_URR_2;
extern module_type MOD_DB_2;
#if (GEMINI_PLUS_WCDMA >= 3)
extern module_type MOD_MEME_3;
extern module_type MOD_CSE_3;
extern module_type MOD_CSCE_3;
extern module_type MOD_SIBE_3;
extern module_type MOD_USIME_3;
extern module_type MOD_RRCE_3;
extern module_type MOD_SLCE_3;
extern module_type MOD_ADR_3;
extern module_type MOD_URR_3;
extern module_type MOD_DB_3;
#if (GEMINI_PLUS_WCDMA >= 4)
extern module_type MOD_MEME_4;
extern module_type MOD_CSE_4;
extern module_type MOD_CSCE_4;
extern module_type MOD_SIBE_4;
extern module_type MOD_USIME_4;
extern module_type MOD_RRCE_4;
extern module_type MOD_SLCE_4;
extern module_type MOD_ADR_4;
extern module_type MOD_URR_4;
extern module_type MOD_DB_4;
#endif /* GEMINI_PLUS_WCDMA >= 4 */
#endif /* GEMINI_PLUS_WCDMA >= 3 */
#endif /* __GEMINI_WCDMA__ */

#endif /* DUMMY_PROTOCOL */
// MOD_ID for FDD UAS URR: end

    
#endif /* __UMTS_RAT__ */

#ifdef  __UMTS_RAT__
extern module_type  MOD_LMEME;
extern module_type  MOD_LCSCE;
extern module_type  MOD_LURR;
extern module_type  MOD_LRRCE;
extern module_type  MOD_LURLC;
extern module_type  MOD_LUMAC;
#ifdef __GEMINI_WCDMA__
extern module_type  MOD_LMEME_2;
extern module_type  MOD_LCSCE_2;
extern module_type  MOD_LURR_2;
#if (GEMINI_PLUS_WCDMA >= 3)
extern module_type  MOD_LMEME_3;
extern module_type  MOD_LCSCE_3;
extern module_type  MOD_LURR_3;
#if (GEMINI_PLUS_WCDMA >= 4)
extern module_type  MOD_LMEME_4;
extern module_type  MOD_LCSCE_4;
extern module_type  MOD_LURR_4;
#endif /* GEMINI_PLUS_WCDMA >= 4 */
#endif /* GEMINI_PLUS_WCDMA >= 3 */
#endif /* __GEMINI_WCDMA__ */    
#endif /* __UMTS_RAT__ */

#ifdef  __GSM_RAT__
extern module_type MOD_GISE;
#if defined(__GEMINI__) || defined(__SGLTE__)
extern module_type MOD_GISE_2;
#if (GEMINI_PLUS >= 3)
extern module_type MOD_GISE_3;
#if (GEMINI_PLUS >= 4)
extern module_type MOD_GISE_4;
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ || __SGLTE__ */
#endif /*__GSM_RAT__*/

/***** global constant *****/

/* MAX_SIM_NUM */
#ifdef __GEMINI__
#ifdef GEMINI_PLUS
#define MAX_SIM_NUM (GEMINI_PLUS)
#else
#define MAX_SIM_NUM (2)
#endif /* GEMINI_PLUS */
#else
#ifdef __SGLTE__
#define MAX_SIM_NUM (2)
#else /* __SGLTE__ */
#define MAX_SIM_NUM (1)
#endif /* __SGLTE__ */
#endif /* __GEMINI__ */

/* MAX_GSM_NUM */
#ifdef __GEMINI_GSM__
#ifdef GEMINI_PLUS_GSM
#define MAX_GSM_NUM (GEMINI_PLUS_GSM)
#else
#define MAX_GSM_NUM (2)
#endif /* GEMINI_PLUS_GSM */
#else
#ifdef __SGLTE__
#define MAX_GSM_NUM (2)
#else
#define MAX_GSM_NUM (1)
#endif /* __SGLTE__ */
#endif /* __GEMINI_GSM__ */

/* MAX_UMTS_NUM */
#ifdef __GEMINI_WCDMA__
#ifdef GEMINI_PLUS_WCDMA
#define MAX_UMTS_NUM (GEMINI_PLUS_WCDMA)
#else
#define MAX_UMTS_NUM (2)
#endif /* GEMINI_PLUS_WCDMA */
#else
#define MAX_UMTS_NUM (1)
#endif /* __GEMINI_WCDMA__ */

/* MAX_LTE_NUM */
#ifdef __LTE_RAT__
#define MAX_LTE_NUM (1)
#endif /* __LTE_RAT__ */

// TDD only support max 3 GSM
#if MAX_GSM_NUM > 3
#define MAX_GSM_TDD_NUM 3
#else
#define MAX_GSM_TDD_NUM (MAX_GSM_NUM)
#endif

// TDD only support max 1 UMTS
#ifdef __UMTS_RAT__
#define MAX_UMTS_TDD_NUM 1
#endif

// The following macros are for general handling of tdd/fdd module count in compile time
// TDD only support max 2 GSM
#define get_max_gsm_num(is_fdd_mode) ((KAL_TRUE == is_fdd_mode)? (MAX_GSM_NUM):(MAX_GSM_TDD_NUM))

// TDD only support max 1 UMTS
#ifdef __UMTS_RAT__
#define get_max_umts_num(is_fdd_mode) ((KAL_TRUE == is_fdd_mode)? (MAX_UMTS_NUM):(MAX_UMTS_TDD_NUM))
#endif

#ifdef __LTE_RAT
#define get_max_lte_num MAX_LTE_NUM
#endif


/*weitang:only for SIM editor requested by moja*/
#ifdef __SGLTE_DSDS__
typedef enum{
	SIM_CARD_NUM = 2,
	SIM_CARD_1 = 1,
	SIM_CARD_2 = 3,
}sim_card_module_mapping;
#endif

/***** global structure *****/


#endif

