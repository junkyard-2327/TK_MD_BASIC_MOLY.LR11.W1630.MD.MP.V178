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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ccci_ipc_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   CCCI_IPC msgid define.
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * 10 06 2016 ap.wang
 * [MOLY00187298] [CCCI] LWA related check in
 * 	
 * 	.
 *
 * 09 08 2016 ap.wang
 * CCCI SYSMSG IPC MISCINFO for LWA
 *
 * 07 07 2016 ap.wang
 * [MOLY00187298] [CCCI] LWA related check in
 * ccci_ipc for control path
 *
 * 07 07 2016 ap.wang
 * [MOLY00187298] [CCCI] LWA related check in
 * 	
 * 	ccci_ipc for control path
 *
 * 07 05 2016 cs.huang
 * [MOLY00187383] [MDT] MD direct tethering porting to UMOLY
 * [CCCI] MDT support
 *
 * 12 08 2015 hsin-jun.tang
 * [MOLY00152004] [CCCI/CCMNI] MDDT -  Merge from MOLY to UMOLY
 * [CCCI] MDDT dev - patch CCCI IPC MSG ID
 *
 * 12 07 2015 hsin-jun.tang
 * [MOLY00152004] [CCCI/CCMNI] Merge from MOLY to UMOLY
 * [CCCI]  MDDT dev
 *
 * 06 08 2015 hsin-jun.tang
 * [MOLY00117873] [CCCI IPC] L4 msg id reduction
 * [CCCI IPC] L4 msg id reduction
 *
 * 11 25 2014 cs.huang
 * [MOLY00084258] [MT6795][Modem][Feature]Please support Garbage filter from network
 * [CCCI IPC] Add CCCI IPC msgid for garbage filter
 *
 * [MOLY00084258] [MT6795][Modem][Feature]Please support Garbage filter from network
 * [CCCI IPC] Add CCCI IPC msgid for garbage filter
 *
 * 11 12 2014 cs.huang
 * [MOLY00084091] [MT6795] [SYSTEM SERVICE] [CLIB] porting C time function to MD
 * [CCCI IPC] Support Clibtime feature
 *
 * 11 01 2013 ap.wang
 * [MOLY00044721] [CCCI_IPC] Modify msg_id for IDC integration
 * 	ccci_ipc msg_id for IDC
 ****************************************************************************/


#ifndef __CCCI_IPC_MSGID_H__
#define __CCCI_IPC_MSGID_H__

#include "module_msg_range.h"

typedef enum
{
    IPC_MSG_ID_SYS_BEGIN = MSG_ID_CCCI_MSG_CODE_BEGIN,
    IPC_L4C_MSG_ID_BEGIN = IPC_MSG_ID_SYS_BEGIN,
    IPC_MSG_ID_INVALID_TYPE = MSG_ID_CCCI_MSG_CODE_BEGIN,
    IPC_L4C_MSG_ID_RANGE = 0x40,
    IPC_EL1_MSG_ID_BEGIN = IPC_L4C_MSG_ID_BEGIN + IPC_L4C_MSG_ID_RANGE,
    IPC_EL1_MSG_ID_RANGE = 0x20,
    IPC_CCCIIPC_MSG_ID_BEGIN = IPC_EL1_MSG_ID_BEGIN + IPC_EL1_MSG_ID_RANGE,
    IPC_CCCIIPC_MSG_ID_RANGE = 0x10,
    IPC_IPCORE_MSG_ID_BEGIN = IPC_CCCIIPC_MSG_ID_BEGIN + IPC_CCCIIPC_MSG_ID_RANGE,
    IPC_IPCORE_MSG_ID_RANGE = 0x8,
    IPC_MDT_MSG_ID_BEGIN = IPC_IPCORE_MSG_ID_BEGIN + IPC_IPCORE_MSG_ID_RANGE,
    IPC_MDT_MSG_ID_RANGE = 0x8,
    IPC_UFPM_MSG_ID_BEGIN = IPC_MDT_MSG_ID_BEGIN + IPC_MDT_MSG_ID_RANGE,
    IPC_UFPM_MSG_ID_RANGE = 0x18,
    IPC_WAAL_MSG_ID_BEGIN = IPC_UFPM_MSG_ID_BEGIN + IPC_UFPM_MSG_ID_RANGE,
    IPC_WAAL_MSG_ID_RANGE = 0x10,
    IPC_MSG_ID_SYS_RANGE = MSG_ID_CCCI_MSG_CODE_TAIL - MSG_ID_CCCI_MSG_CODE_BEGIN,
}IPC_MSG_ID_CODE_BEGIN;


MODULE_MSG_BEGIN(MSG_ID_CCCI_MSG_CODE_BEGIN) 
    MSG_ID_IPC_INVALID_TYPE = MSG_ID_CCCI_MSG_CODE_BEGIN,
    MSG_ID_IPC_L4C_INVALID = IPC_L4C_MSG_ID_BEGIN,
    #include "l4_ipc_msgid.h"
    MSG_ID_IPC_L4C_END,
    MSG_ID_IPC_EL1_INVALID = IPC_EL1_MSG_ID_BEGIN,
    #include "el1_ipc_msgid.h"
    MSG_ID_IPC_EL1_END,
    MSG_ID_IPC_CCCIIPC_INVALID = IPC_CCCIIPC_MSG_ID_BEGIN,
    MSG_ID_CCCIIPC_CLIB_TIME_REQ, // for clib time msg id
    MSG_ID_CCCIIPC_AP_MD_UT_MSG,
    MSG_ID_IPC_CCCIIPC_END,
    MSG_ID_IPC_IPCORE_INVALID = IPC_IPCORE_MSG_ID_BEGIN,
    #include "pfm_msgid.h"
    MSG_ID_IPC_IPCORE_END,
    MSG_ID_IPC_MDT_INVALID = IPC_MDT_MSG_ID_BEGIN,
//    #include "mdt_msgid.h"
    MSG_ID_IPC_MDT_END,

    MSG_ID_IPC_UFPM_INVALID = IPC_UFPM_MSG_ID_BEGIN,
//    #include "ufpm_msgid.h"
    MSG_ID_IPC_UFPM_END,

    MSG_ID_IPC_WAAL_INVALID = IPC_WAAL_MSG_ID_BEGIN,
    #include "waal_ipc_msgid.h"
    MSG_ID_IPC_WAAL_END,
    MSG_ID_IPC_END,
MODULE_MSG_END(MSG_ID_CCCI_MSG_CODE_TAIL)

#endif  /* !__CCCI_IPC_MSGID_H__ */
