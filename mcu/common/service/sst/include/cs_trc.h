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
 *   cs_trc.h
 *
 * Project:
 * --------
 *   UMOLY_Software
 *
 * Description:
 * ------------
 *   This file contains definitions for trace on target.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _CS_TRC_H
#define _CS_TRC_H  

    TRC_MSG(CS_EX_LOG_ASSERT,             "[SONIC(%s)] Assert fail: %s -%d 0x%x, 0x%x, 0x%x")
    TRC_MSG(CS_EX_LOG_FATAL,              "[SONIC(%s)] Fatal error : code1:0x%x  code2:0x%x ,Caller Address: 0x%x Product: %s Version: %s BuildTime: %s")
    TRC_MSG(CS_EX_LOG_EXC,                "[SONIC(%s)] EXCEPTION : Error_type: %s  pc:0x%x  lr:0x%x  addr:0x%x  status:0x%x")
    
    TRC_MSG(CS_EX_LOG_PAS_DETAIL_FATAL,   "[SONIC(%s)] Fatal error Detail : [Passive] error_type: %s  code1:0x%x  code2:0x%x  pc:0x%x  address:0x%x  status:0x%x")
    TRC_MSG(CS_EX_LOG_POS_DETAIL_FATAL,   "[SONIC(%s)] Fatal error Detail : [Positive] code1:0x%x  code2:0x%x  File: %s  Line: %d  Para: 0x%x")
    
    TRC_MSG(CS_EX_LOG_DEFAULT,            "[SONIC(%s)] Fatal error: CTI!! (0x%x)")
	TRC_MSG(CS_EX_LOG_BIN_BUILD_INFO,     "[SONIC(%s)] Project: %s Flavor: %s BuildTime: %s Label: %s")
	
    TRC_MSG(CS_EX_LOG_REQEMI_SYNC_FAIL,   "[DSP-Coresonic] [RequestEMIFlush] SYNC flow is not finished!!! (0x%x, 0x%x, 0x%x, 0x%x)")
    TRC_MSG(CS_EX_LOG_ACTEMI_SYNC_FAIL,   "[DSP-Coresonic] [AckEMIFlushFinish] SYNC flow is not finished!!! (0x%x, 0x%x, 0x%x, 0x%x)")
    TRC_MSG(CS_EX_LOG_DUMP_SYNC_FAIL,     "[DSP-Coresonic] [INT_DumpSonicExceptionInfo] SYNC flow is not finished!!! (0x%x, 0x%x, 0x%x, 0x%x)")
    
    TRC_MSG(CS_EX_LOG_SYNC_HS_STATUS,     "[DSP-Coresonic] [INT_SyncSonicExceptionInfo] CSIF HS result: booted: 0x%x, csif_rdy: 0x%x, hs time : 0x%x")
	TRC_MSG(CS_EX_LOG_REQEMI_HS_STATUS,   "[DSP-Coresonic] [RequestEMIFlush] CSIF HS result: booted: 0x%x, csif_rdy: 0x%x, hs time : 0x%x")
	TRC_MSG(CS_EX_LOG_ACTEMI_HS_STATUS,   "[DSP-Coresonic] [AckEMIFlushFinish] CSIF HS result: booted: 0x%x, pm_wait: 0x%x, hs time : 0x%x")
	TRC_MSG(CS_EX_LOG_REQEMI_HS_FAIL,     "[SONIC(%s)] [RequestEMIFlush] CSIF HS fail (0x%x), and log may be lost")
	TRC_MSG(CS_EX_LOG_ACTEMI_HS_FAIL,     "[SONIC(%s)] [AckEMIFlushFinish] CSIF HS fail (0x%x), and log may be lost, sleep_cmd: 0x%x")
	
    TRC_MSG(CS_EX_LOG_SYNC_FAIL_WARNING,  "Modem Warning: [DSP-Coresonic] WARNING: SYNC flow is not finished!!! (0x%x, 0x%x, 0x%x)")
#endif //_CS_TRC_H

