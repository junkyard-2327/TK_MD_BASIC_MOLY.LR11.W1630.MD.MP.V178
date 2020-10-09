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
 *   upcm_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   UPCM and Protocol Stack related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 08 07 2017 andrew.wu
 * [MOLY00268789] IPv6 Stateless Auto Address Configuration Stability Improvement - Add new Interface
 * 	
 * 	UPCM interface for PDN info to IPCORE
 * 	- add for RS/RA
 *
 * 08 07 2017 andrew.wu
 * [MOLY00268789] IPv6 Stateless Auto Address Configuration Stability Improvement - Add new Interface
 * UPCM interface for PDN info to IPCORE
 * - add for RS/RA
 *
 * 08 07 2017 andrew.wu
 * [MOLY00268789] IPv6 Stateless Auto Address Configuration Stability Improvement - Add new Interface
 * UPCM interface for PDN info to IPCORE
 * - add for RS/RA
 *
 * 08 07 2017 andrew.wu
 * [MOLY00268789] IPv6 Stateless Auto Address Configuration Stability Improvement - Add new Interface
 * .
 *
 * 04 08 2016 andrew.wu
 * [MOLY00173139] [K7][UPlus] Upload Data Throughput Test FAIL whole devices at LGU+ real networks
 * .
 *
 * 06 11 2015 ariel.lin
 * [MOLY00120396] [UMOLY] VoLTE patch back from MP7
 * Merge from CL1353395.
 *
 * 06 05 2015 ariel.lin
 * MP7 to UMOLY.
 *
 * 04 27 2015 ben.chiu
 * [MOLY00109234] [VoLTE][Volunteer Patch] MP7.CMCCVOLTE.FPB merge back to MP7/MP7.CMCC
 * MP7.CMCCVOLTE.FPB merge back to MP7
 *
 * 04 27 2015 ben.chiu
 * [MOLY00109234] [VoLTE][Volunteer Patch] MP7.CMCCVOLTE.FPB merge back to MP7/MP7.CMCC
 * MP7.CMCCVOLTE.FPB merge back to MP7
 *
 * 02 05 2015 stan.chen
 * [MOLY00094939] MASE UMOLY check in
 * MASE/4GESL code checkin.
 *
 * 01 07 2015 stan.chen
 * [MOLY00081925] [TK6291_DEV] EMBMS Support
 * Restore UPCM MBMSAL msg ids.
 *
 * 11 07 2014 kun-lin.wu
 * [MOLY00082366] Loop back mode 4 support
 *
 * 08 29 2014 stan.chen
 * [MOLY00077591] [TK6291] MBMSAL for eMBMS
 * Summit MBMSAL ERRC interfaces.
 *
 * 07 25 2013 jeffery.chen
 * [MOLY00031206] [MOLY][L4C PS] Add AT+EGLD to leave data mode
 * .
 *
 * 07 05 2013 danny.kuo
 * [MOLY00028800] [MMDC] PS Domain Switch Manager (PSDM) development
 * Interface Check-in
 *
 * 06 04 2013 moja.hsu
 * [MOLY00024881] Network Interface Bind Confirm
 * add PDN Bind related structure and enum.
 *
 * 01 22 2013 carlson.lin
 * [MOLY00009161] LTE Multimode Merge to MOLY
 * interface - sap part
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef _UPCM_MSGID_H
#define _UPCM_MSGID_H


MODULE_MSG_BEGIN( MSG_ID_UPCM_CODE_BEGIN )

MSG_ID_TCM_UPCM_BEARER_ACT_REQ = MSG_ID_UPCM_CODE_BEGIN,
MSG_ID_TCM_UPCM_BEARER_DEACT_REQ,
MSG_ID_TCM_UPCM_PDN_BIND_REQ,
MSG_ID_TCM_UPCM_PDN_BIND_CNF,
MSG_ID_TCM_UPCM_PDN_UNBIND_REQ,
MSG_ID_TCM_UPCM_PDN_UNBIND_CNF,
MSG_ID_TCM_UPCM_PF_UPDATE_REQ,
MSG_ID_RAT_TCM_UPCM_SUSPEND_REQ,
MSG_ID_RAT_TCM_UPCM_RESUME_REQ,

MSG_ID_IPCORE_UPCM_PDN_BIND_IND,
MSG_ID_IPCORE_UPCM_PDN_BIND_RSP,
MSG_ID_IPCORE_UPCM_PDN_DEACT_IND,
MSG_ID_IPCORE_UPCM_ESL_PDN_BIND_REQ,

MSG_ID_UPCM_RATCM_TEST_MODE_IND,

MSG_ID_MNY_UPCM_SUSPEND_REQ,
MSG_ID_MNY_UPCM_RESUME_REQ,

MSG_ID_IMC_UPCM_START_EBI_FILTER_REQ,
MSG_ID_IMC_UPCM_STOP_EBI_FILTER_REQ,
MSG_ID_MBMSAL_UPCM_PDN_BIND_REQ,
MSG_ID_MBMSAL_UPCM_PDN_BIND_CNF,
MSG_ID_MBMSAL_UPCM_PDN_UNBIND_REQ,
MSG_ID_MBMSAL_UPCM_PDN_UNBIND_CNF,

/* UPCM <--> EL2 */
MSG_ID_UPCM_EPDCP_IMS_EPSB_BMP_SET_REQ,
MSG_ID_UPCM_EPDCP_IMS_EPSB_BMP_CLR_REQ,

MSG_ID_IPCORE_UPCM_PDN_INFO_IND,

MODULE_MSG_END( MSG_ID_UPCM_CODE_TAIL )

#endif /* _UPCM_MSGID_H */
