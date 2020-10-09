/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mrs_as_enums.h
 *
 * Project:
 * --------
 *   Multimode
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ----------------------------------------------------------------------------
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
 * removed!
 ******************************************************************************/
#ifndef _MRS_AS_ENUMS_H
#define _MRS_AS_ENUMS_H

#include "global_def.h"
#include "l3_inc_enums.h"
#include "ps_public_enum.h"
#include "c2k_mrs_enums.h"

typedef enum 
{
    INITIAL,
    SHARED,
    OCCUPIED
}lower_layer_availability_enum;

#if defined(__GEMINI__) || defined(__SGLTE__)
#define MAX_GAS_CAPABILITY      MAX_GSM_NUM
#define MAX_UAS_CAPABILITY      MAX_UMTS_NUM
#define MAX_EAS_CAPABILITY      1
#define MAX_MM_CAPABILITY       MAX_GSM_NUM /* assume GSM number > UMTS number */
#define MAX_EMM_CAPABILITY      1
#else
#define MAX_GAS_CAPABILITY      1
#define MAX_UAS_CAPABILITY      1
#define MAX_EAS_CAPABILITY      1
#define MAX_MM_CAPABILITY       1
#define MAX_EMM_CAPABILITY      1
#endif

#define MAX_ASSOCIATION_LAI_CELL_INFO 12
#define MAX_ASSOCIATION_SAME_LAI_CELL_INFO 24

/* For fast resume and Search info. reuse for mode switch. */
#define SI1_RAW_VALID                  0x01 //00000001
#define SI2_RAW_VALID                  0x02 //00000010
#define SI2BIS_RAW_VALID               0x04 //00000100
#define SI3_RAW_VALID                  0x08 //00001000
#define SI4_RAW_VALID                  0x10 //00010000
#define SI13_RAW_VALID                 0x20 //00100000
#define SI1_EXIS                       0x80 //10000000
#define SI2SERIES_RAW_VALiD            0x06 //00000110  si2 & si2bis
#define ALL_SI_RAW_VALID               0xbf //10111111
#ifdef __PS_SERVICE__
#define GAS_FAST_MODE_SWITCH_VALID_SI  0xbf //10111111
#else
#define GAS_FAST_MODE_SWITCH_VALID_SI  0x9f //10011111
#endif
#define GAS_SI_RAW_DATA_LEN 20


#if defined(__GAS_STORED_SI_FEAT__) || defined(__OP01_FDD__) || defined(__GAS_FDD_FAST_IRCR__)
#define RRM_MAX_SI2TER_INSTANCES    8
#define RRM_SI2TER_REST_LEN    4
#define RRM_MAX_SI2QUARTER_INSTANCES    16
#define RRM_SI2QUARTER_REST_LEN    20
#define RRM_MAX_SIZE_OF_GAS_STORED_SI_LIST 8
#define GAS_CANDIDATE_TICK_INIT (0xFFFFFFFF)
#endif

/* Already in l3_inc_enums.h
typedef enum 
{
    DEL_CSG,
    ADD_CSG
}csg_update_type_enum;
*/

typedef enum 
{
    NO_CHANGE,
    ALLOWED_CSG_LIST_CHANGED,
    OPERATOR_CSG_LIST_CHANGED,
    BOTH_CSG_LIST_CHANGED
}white_list_update_type;

/* Already in ps_public_enum.h
typedef enum 
{
    NOT_IN_WHITE_LIST,
    ALLOWED_CSG,
    OPERATOR_CSG,
    UNAUTH_OPERATOR_CSG
}csg_type_enum;
*/

typedef enum 
{
    ALLOWED_CSG_LIST,
    OPERATOR_CSG_LIST
}csg_list_type_enum;

typedef enum 
{
    SIM_NEW_INSERTED,
    SIM_FILE_UPDATED,
    AS_UPDATED
}csg_white_list_update_cause;

typedef enum
{
    CSFB_REDUCE_LAU = 1,
    CSFB_DEFER_SI13,
    CSFB_2G_AFR,
    CSFB_3G_AFR,
    CSFB_2G_FDD_eCSFB,
    CSFB_3G_FDD_eCSFB,
    CSFB_2G_TDD_eCSFB,
    CSFB_3G_TDD_eCSFB,
    CSFB_ENHANCEMENT_ITEM_END
}csfb_enhancement_enum;

typedef enum 
{
    BAND_39_DISABLE,
    BAND_39_ENABLE
}band_39_control_enum;

typedef enum
{
    BAND_DISABLE,
    BAND_ENABLE
}eas_band_control_enum;

typedef enum
{
    BG_SEARCH_2G4_FDD,
    BG_SEARCH_3G4_FDD,
    BG_SEARCH_2G4_TDD,
    BG_SEARCH_3G4_TDD
}background_search_enum;

typedef enum
{
    MRS_GAS_FAST_MODE_SWITCH_NOT_ALLOWED                = 0x00,      //Initial value
    MRS_GAS_FAST_MODE_SWITCH_COLLECTING_ESSENTIAL_SI    = 0x01 << 0, //RATCM_GAS_SYS_INFO not sent or still receiving essential SI
    MRS_GAS_FAST_MODE_SWITCH_ESSENTIAL_SI_COLLECTED     = 0x01 << 1, //RATCM_GAS_SYS_INFO sent
    MRS_GAS_FAST_MODE_SWITCH_NOT_HAPPENED               = 0x01 << 2, // DUPLEX mode change not happened
    MRS_GAS_FAST_MODE_SWITCH_HAPPENED                   = 0x01 << 3, // DUPLEX mode change happened
    MRS_GAS_FAST_MODE_SWITCH_NOT_HAPPENED_WO_SI         = MRS_GAS_FAST_MODE_SWITCH_COLLECTING_ESSENTIAL_SI
                                                        + MRS_GAS_FAST_MODE_SWITCH_NOT_HAPPENED,
    MRS_GAS_FAST_MODE_SWITCH_HAPPENED_BUT_WO_SI         = MRS_GAS_FAST_MODE_SWITCH_COLLECTING_ESSENTIAL_SI
                                                        + MRS_GAS_FAST_MODE_SWITCH_HAPPENED,
    MRS_GAS_FAST_MODE_SWITCH_NOT_HAPPENED_W_SI          = MRS_GAS_FAST_MODE_SWITCH_ESSENTIAL_SI_COLLECTED
                                                        + MRS_GAS_FAST_MODE_SWITCH_NOT_HAPPENED,
    MRS_GAS_FAST_MODE_SWITCH_ALLOWED                    = MRS_GAS_FAST_MODE_SWITCH_ESSENTIAL_SI_COLLECTED
                                                        + MRS_GAS_FAST_MODE_SWITCH_HAPPENED,
} mrs_gas_fast_mode_switch_status_enum;

#endif /* _MRS_AS_ENUMS_H */
