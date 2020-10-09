/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 * Filename:
 * ------------
 *   sdm_imcsms_enums.h
 *
 * Project:
 * ------------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file defines the enums between SDM and IMC SMS.
 *
 * Author:
 * -----------
 * -------
 *
 *===========================================================
 * $Log$
 *
 * 08 11 2016 ian-yw.chen
 * [MOLY00196139] [VzW][phone mode CCP] support 3GPP2 UTK SMS and PP download over IMS
 *  UTK SMS part
 *  interface part (CL 2688667 2688893 2690322 2693165)
 *
 * 03 11 2016 ian-yw.chen
 * [MOLY00166564] [MT6755][VzW][chipset][LC1][InHouse][MTK-HQ][RnS][LTE][SMS][2.30] MO 3GPP SMS RETRY BEHAVIOR-DEFAULT SIP T1, TIMER F AND T2 TIMERS
 *  revise MOLY00135505 (add SBP_SDM_RETRY_TIMER)
 *  VzW retry IMS domain after 30 Sec if SIP error occurs.
 *
 * 02 05 2016 ian-yw.chen
 * [MOLY00163894] [SMS][TC01] 3GPP2 SMS over IMS
 *  interfaces
 *
 * 11 16 2015 edwin.liu
 * [MOLY00147454] VZW 3GPP2 SMS over IMS
 * 	
 * 	.
 *
 * 11 16 2015 edwin.liu
 * Merge 3GPP2 SMS.
 *****************************************************************************/

#ifndef SDM_IMCSMS_ENUMS_H
#define SDM_IMCSMS_ENUMS_H

typedef enum
{
    IMCSMS_SMMA_REQ,        // 0
    IMCSMS_SMMA_ABORT     // 1
}imcsms_smma_req_type_enum;

typedef enum
{
    C2K_SMS_NO_ERROR = 0,
    C2K_SMS_TEMPORARY_ERROR = 2,
    C2K_SMS_PERMANENT_ERROR = 3,
    C2K_SMS_LIMIED_SERVICE = 4  //ONLY in __TC01_IMS_SUPPORT__
}c2k_sms_error_class_enum;

typedef enum
{
    C2K_SMS_USER_DATA_SIZE_ERROR = 106,
    C2K_SMS_CAUSE_OTHER_GENERAL_PROBLEM = 107,
    C2K_SMS_CAUSE_OK = 32768,
    C2K_SMS_CAUSE_NETWORK_NOT_READY = 32773
}c2k_sms_cause_code_enum;

typedef enum
{
    RP_MESSAGE = 0,
    MO_STATUS = 1,
    C2K_MT_MESSAGE = 2,
    C2K_MT_PP_DOWNLOAD = 3
}esmsoims_type_enum;

typedef enum
{
   IMCSMS_ERR_TYPE_MS_ERROR,
   IMCSMS_ERR_TYPE_CP_ERROR,
   IMCSMS_ERR_TYPE_RP_ERROR,
   IMCSMS_ERR_TYPE_NW_ERROR
} imcsms_error_type_enum;

#endif // SDM_IMCSMS_ENUMS_H

