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
 * nas_common_utility.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file contains the common utility functions provided by nas to all tasks
 *
 * Author:
 * -------
 * -------
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
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _NAS_COMMON_UTILITY_H_
#define _NAS_COMMON_UTILITY_H_

/* Common files Inclusion */
#include "kal_public_defs.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_enums.h"
#include "mcd_l3_inc_struct.h"
#include "rac2l4c_struct.h"
#include "custom_gmss_config.h"
#include "ps_em_enum.h"


typedef enum {
    NAS_SIGNALLING_PRIORITY                      =     0x80,
    NMO_I_BEHAVIOUR                              =     0x81,
    ATTACH_WITH_IMSI                             =     0x82,
    MINIMUM_PERIODIC_SEARCH_TIMER                =     0x83,
#ifdef __REL11__ // NSLP and EAB
    EXTENDED_ACCESS_BARRING                      =     0x84,
#endif
    TIMER_T3245_BEHAVIOUR                        =     0x85,
    OVERRIDE_NAS_SIGNALLING_LOW_PRIORITY         =     0x86,
    FAST_FIRST_HIGHER_PRIORITY_PLMN_SEARCH       =     0x88 // REL_12
}nasconfig_tag_enum;

typedef enum {
    VZW_THROTTLING_LEVEL_DEFAULT = 1,
    VZW_THROTTLING_LEVEL_1 = 2,    
    VZW_THROTTLING_LEVEL_2 = 3,
    VZW_THROTTLING_LEVEL_3 = 4,
    VZW_THROTTLING_LEVEL_4 = 5,
    VZW_THROTTLING_LEVEL_5 = 6,
    VZW_THROTTLING_LEVEL_6 = 8,
    VZW_THROTTLING_LEVEL_7 = 10
} vzw_throttling_level_enum;

typedef enum
{
    SIM_OP_UNKNOWN    = 0,
    SIM_OP_CT         = 1,
    SIM_OP_VZW        = 2,
    SIM_OP_SMARTFREN  = 3,
    SIM_OP_RJIO       = 4
}sim_operator_enum;


extern kal_bool nasconfig_unpacker(kal_uint16 no_nasconfig_data, kal_uint8 *nasconfig_data , nasconfig_tag_enum tag , kal_uint8* ret);
#ifdef __LTE_RAT__
extern kal_bool nas_is_csfb_ongoing(void);
#endif
extern kal_bool nas_is_hplmn(kal_uint8 simInterface,const plmn_id_struct *plmn);
extern kal_bool nas_is_eq_plmn(kal_uint8 simInterface,const plmn_id_struct *plmn);

extern kal_bool nas_convert_plmn_string_to_struct(const char *plmn_str, plmn_id_struct *plmn_id);
kal_bool nas_convert_mcc_num_to_struct(const kal_uint16 mcc_num, plmn_id_struct *plmn_id);
extern kal_bool nas_is_display_hplmn(kal_uint8 simInterface,const plmn_id_struct *plmn);
extern netw_serv_state_enum nas_em_display_hplmn(kal_uint8 simInterface,const plmn_id_struct *plmn);

#if defined(__GEMINI__) && defined(__PS_SERVICE__)
extern kal_bool nas_is_gemini_ps_attach_allowed(kal_uint8 current_sim_index);
#endif
extern kal_bool nas_check_imsi_validity(kal_uint8 const *ef_imsi);

/* VZW requirements */
kal_uint16 getThrottlingTimerLen(kal_uint8 counter);
kal_uint16 getThrottlingTimerLen_5(kal_uint8 counter);
kal_bool setThrottlingLevel(kal_uint8 throttling_level);

extern kal_bool nas_is_nw_loss_optimize(l4crac_reg_state_ind_struct *last_reg_state_ind, l4crac_reg_state_ind_struct *current_reg_state_ind, sim_interface_enum simInterface, kal_bool is_l4c_rat_chg);
extern kal_bool nas_is_rplmn_hplmn(kal_uint8 simInterface,const plmn_id_struct *plmn);
extern kal_bool nas_is_camped_on_hplmn(kal_uint8 simInterface);

extern network_operator_enum nas_get_camp_network(kal_uint8 simInterface);

extern sim_operator_enum nas_get_sim_operator(kal_uint8 current_sim_index);
extern lai_struct nas_get_reg_lai(kal_uint8 simInterface);

#endif  /*_NAS_COMMON_UTILITY_H_*/
