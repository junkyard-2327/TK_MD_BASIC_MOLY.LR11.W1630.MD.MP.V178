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
 *   secure_maui_GFH_body.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain the GFH definition
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MAUI_GFH_BODY_H__
#define __MAUI_GFH_BODY_H__

#include "br_GFH_file_info.h"
#include "br_GFH_maui_info.h"
#include "br_GFH_anti_clone.h"
#include "br_GFH_maui_sec.h"
#include "br_GFH_secure_ro_info.h"
#include "br_GFH_flash_info.h"
#include "br_GFH_fota_info.h"
#include "br_GFH_cbr_record_info.h"
#include "br_GFH_cbr_info.h"
#include "br_GFH_binary_location.h"
#include "br_GFH_vec_info.h"
#include "GFH_defs.h"

//==============================================================================
// Primary MAUI GFH structure
//==============================================================================

typedef struct 
{
   GFH_FILE_INFO_v1          gfh_file_info;
   GFH_MAUI_INFO_v2          gfh_maui_info;
   GFH_FLASH_INFO_v1         gfh_flash_info;
   GFH_CBR_INFO_v2           gfh_cbr_info;
   
#ifdef __MTK_SECURE_PLATFORM__   
   GFH_MAUI_SEC_v1           gfh_maui_sec;
#endif /* __MTK_SECURE_PLATFORM__ */
   GFH_MAUI_CODE_KEY_v1      gfh_maui_sec_key_maui;             //The key to verify SecondaryMAUI
   //GFH_MAUI_SECURE_RO_KEY_v1 gfh_maui_sec_key_secro;            //The key to verify SecureRO

#ifdef __FOTA_DM__
   GFH_FOTA_INFO_v1          gfh_fota_info;
#endif /* __FOTA_DM__ */

#ifdef __XIP_SHADOWING__
   GFH_BINARY_LOCATION_v1    gfh_binary_location;
#endif /* __XIP_SHADOWING__ */
   GFH_VEC_INFO_v1           gfh_vec_info;

} MAUI_GFH;

//==============================================================================
// Export symbols
//==============================================================================

extern const MAUI_GFH      g_maui_gfh;

#endif /*  __MAUI_GFH_BODY_H__ */

