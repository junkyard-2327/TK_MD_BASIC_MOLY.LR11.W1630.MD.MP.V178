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
 * 
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __NWSEL_NVRAM_DEF_H__
#define __NWSEL_NVRAM_DEF_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "ps_public_enum.h"

typedef enum
{
        NVRAM_EF_NWSEL_DATA_LID          = NVRAM_LID_GRP_NWSEL(0),
		NVRAM_EF_STATIC_APPLMN_LID,
		NVRAM_EF_DYNAMIC_APPLMN_LID,
		NVRAM_EF_AUX_PLMN_LID,

		/*Add LID must before NVRAM_EF_NWSEL_LAST_LID*/
        NVRAM_EF_NWSEL_LAST_LID          = NVRAM_LID_GRP_NWSEL(63)
}nvram_lid_nwsel_enum;

#ifdef __REL6__
#define EF_MAX_NUM_EQ_PLMN      16 
#else
#define EF_MAX_NUM_EQ_PLMN       6
#endif

#define GMSS_TELE_MPSR_TABLE_SIZE 10
#define GMSS_NV_ITEM_LTE_AVAIL_MAX 20

/**
 * NWSEL
 */
#define MAX_UE_OPLMN_ENTRY_PER_SET 100
#define MAX_UE_OPLMN_SET 3
#define MAX_UE_OPLMN_ENTRY (MAX_UE_OPLMN_ENTRY_PER_SET*MAX_UE_OPLMN_SET) //300
#define MAX_CUSTOM_FPLMN_ENTRY_PER_SET 64
#define MAX_CUSTOM_FPLMN_SET 3
#define MAX_CUSTOM_FPLMN_ENTRY (MAX_CUSTOM_FPLMN_SET*MAX_CUSTOM_FPLMN_ENTRY_PER_SET)



#define NVRAM_EF_NWSEL_DATA_SIZE (sizeof(nvram_ef_nwsel_data_struct))
#if defined(__SGLTE_DSDS__) || defined(__DUAL_SIM_PROJECT_SUPPORT_SGLTE_WORLD_PHONE_NVRAM__)
#define NVRAM_EF_NWSEL_DATA_TOTAL 4
#else
#define NVRAM_EF_NWSEL_DATA_TOTAL (1 * NVRAM_DUAL_RECORD)
#endif

/**
 * Static  APPLMN List 
 **/
typedef  struct 
{ 
    kal_uint8 data[640];
} nvram_ef_static_applmn_struct;

#define NVRAM_EF_STATIC_APPLMN_TOTAL   (1 * NVRAM_DUAL_RECORD)
#define NVRAM_EF_STATIC_APPLMN_SIZE    sizeof(nvram_ef_static_applmn_struct)

/**
 * Dynamic  APPLMN List 
 **/
typedef  struct 
{ 
    kal_uint8 data[160];
} nvram_ef_dynamic_applmn_struct;

#define NVRAM_EF_DYNAMIC_APPLMN_TOTAL   (1 * NVRAM_DUAL_RECORD)
#define NVRAM_EF_DYNAMIC_APPLMN_SIZE    sizeof(nvram_ef_dynamic_applmn_struct)
/* --------------------------
 * End of APPLMN list
 * --------------------------- */

/**
 * AUX PLMN 
 **/
typedef  struct 
{ 
    kal_uint8 data[7];
} nvram_ef_aux_plmn_struct;

#define NVRAM_EF_AUX_PLMN_TOTAL   (1 * NVRAM_DUAL_RECORD)
#define NVRAM_EF_AUX_PLMN_SIZE    sizeof(nvram_ef_aux_plmn_struct)


#ifdef __cplusplus
}
#endif 

#endif
