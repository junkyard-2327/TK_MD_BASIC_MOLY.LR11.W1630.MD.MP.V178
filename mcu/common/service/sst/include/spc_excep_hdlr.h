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
 *   spc_excep_hdlr.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This file provides typedefs and definiton for PS index trace.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __SPC_EXCEP_HDLR_H__
#define __SPC_EXCEP_HDLR_H__

#if defined(__PCORE__)

#include "kal_general_types.h"
#include "spc_excep_hdlr_format.h"
#include "reg_base.h" // for BASE_MADDR_PS2ARM7_PCCIF
#if defined(__MTK_TARGET__) && defined(__SPEECH_EVS_SUPPORT__) && defined(__HIF_PCCIF_ARM7_SUPPORT__)
#include "pccif_arm7_system.h"
#endif

// ----------------- macro definition ---------------
#define SPC_EX_HANDSHAKE_BASE ((kal_uint32 *)(BASE_MADDR_PS2ARM7_PCCIF + 0x100)) /* Use PCCIF SRAM */
#define SPC_EXCEPTION_SYNC_TIME (0x100000)    // 100 subframes
#if defined(__MTK_TARGET__) && defined(__SPEECH_EVS_SUPPORT__) && defined(__HIF_PCCIF_ARM7_SUPPORT__)
#define SPC_POWERED_ON() is_arm7_turned_on()
#else
#define SPC_POWERED_ON() 0
#endif

// ----------------- data type Definition -------------------

// ----------------- function declaration -------------------

extern kal_bool INT_SyncSPCExceptionInfo(void);

extern void INT_GetSPCExceptionRecord(SPC_EXCEPTION_RECORD_T *record);

extern void INT_DumpSPCExceptionInfo(kal_uint32 trace_type /*0=cadefa*/, kal_char* sys_info_str, kal_uint32 len);

#endif /* __PCORE__  */

#endif /* __SPC_EXCEP_HDLR_H__ */
