/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * custom_mm_config.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the MM configuration.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _CUSTOM_RRCE_CONFIG_H
#define _CUSTOM_RRCE_CONFIG_H

#include "kal_general_types.h"

typedef kal_uint8 RRC_Digit1;


typedef struct RRC_MCC1
{
   kal_uint8 numElements;

   RRC_Digit1 element[3];
}
RRC_MCC1;

/* SEQUENCE OF MNC */
typedef struct RRC_MNC1
{
   kal_uint8 numElements;

   RRC_Digit1 element[3];
}
RRC_MNC1;


/* SEQUENCE PLMN-Identity */
typedef struct CUSTOM_RRC_PLMN_Identity
{
   RRC_MCC1 mcc; /* MANDATORY */
   RRC_MNC1 mnc; /* MANDATORY */
}
CUSTOM_RRC_PLMN_Identity;

typedef struct
{
    /* PLMN identity */
    kal_uint32 mccMnc;
    kal_uint8  r7_cap1;
    kal_uint8  r7_cap2;
    kal_uint8  r8_cap1;
    kal_uint8  r8_cap2;
} custom_plmn_r7_r8_capa_list;

/*************************************************************************
* Function
*************************************************************************/

extern kal_bool rrce_is_support_HSUPA(void);
extern kal_bool is_plmn_available_for_r7r8_caps_in_custom_config(void* plmn_id, kal_uint8* r7_cap1, kal_uint8* r7_cap2, kal_uint8* r8_cap1, kal_uint8* r8_cap2);

#endif /* _CUSTOM_RRCE_CONFIG_H */

