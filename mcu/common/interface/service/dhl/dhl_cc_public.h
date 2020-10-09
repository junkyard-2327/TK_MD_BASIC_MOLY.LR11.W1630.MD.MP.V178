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
 *   dhl_cc_public.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   DHL Cross-core public include header
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 07 22 2015 eason.lai
 * [MOLY00130157] [TK6291][DHL] smart logging migration
 * 	.
 *
 *
 ****************************************************************************/
#ifndef __DHL_CC_PUBLIC__
#define __DHL_CC_PUBLIC__

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"

#if !defined(GEN_FOR_PC)
    typedef enum{
        E_DHL_CC_DO_NOTHING,
        E_DHL_CC_REAPPEAR_EX_LOG,
        E_DHL_CC_PUBLIC_CTRL_END,
    } E_DHL_CC_PUBLIC_CTRL;
    /**
     * DHL -> SST reappear L1CORE exception log
     *   Flag == TRUE: SST will redump cadafa again. PCORE DHL must handle output flow.
     *   Flag == KALSE: SST finished redump cadafa and PCORE DHL should back to wait for ELT command.
     */
    DECLARE_SHARED_VAR(kal_uint32, cc_dhl_sst_reappear_ex_log_flag_var)
    #define cc_dhl_sst_reappear_ex_log_flag  SHARED_VAR(cc_dhl_sst_reappear_ex_log_flag_var)        

    // meta mode flag 
    DECLARE_SHARED_VAR(kal_uint8, tst_meta_mode_trace_nvram_enable_flag_var);
    #define tst_meta_mode_trace_nvram_enable_flag   SHARED_VAR(tst_meta_mode_trace_nvram_enable_flag_var)

    // check the reappear log is done or not
    kal_bool dhl_slave_reappear_ex_log_done();
#endif  /* !GEN_FOR_PC */

#endif /* __DHL_CC_PUBLIC__ */


