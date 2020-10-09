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
 *   vdm_imsp_enums.h
 *
 * Project:
 * ------------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file defines the enum between VDM and IMS Proxy.
 *
 * Author:
 * -----------
 * -------
 *
 *===========================================================
 * $Log$
 *
 * 09 03 2015 lexel.yu
 * [MOLY00130859] [ViLTE] add AT+ECCP/AT+EIMSCCP in ADS
 * 	.
 *
 * 08 26 2015 ben.chiu
 * [MOLY00138217] [ViLTE] M0 migration ViLTE feature Interface
 * ViLTE interface patch back
 *
 * 12 05 2014 lexel.yu
 * [MOLY00085703] [VDM][MT6291] Sync MOLY to UMOLY
 * 	[MOLY00085717] [VoLTE] Android L release VoLTE refactory for VDM and IMSP
 *****************************************************************************/

#ifndef _VDM_IMSP_ENUMS_H_
#define _VDM_IMSP_ENUMS_H_

typedef enum {
    CODE_NO_CARRIER = 0,
    CODE_ERROR,
    CODE_OK
} vdm_imsp_at_cmd_result_enum;

typedef enum 
{
    VDM_ADS_MODE_AUTOMATIC = 0,
    VDM_ADS_MODE_CS_ONLY,
} vdm_ads_mode_enum;

typedef enum 
{
    VDM_ADS_RESULT_REPORT_DISABLE = 0,
    VDM_ADS_RESULT_REPORT_ENABLE,
} vdm_ads_result_report_mode_enum;

typedef enum 
{
    VDM_ADS_RESULT_CS = 0,
    VDM_ADS_RESULT_IMS_VOLTE,
    VDM_ADS_RESULT_IMS_WIFI,
    VDM_ADS_RESULT_REJECT,
} vdm_ads_result_enum;

typedef enum 
{
    VDM_VIDEO_CAPABILITY_3GVT = 0x01,
    VDM_VIDEO_CAPABILITY_VILTE = 0x02,
    VDM_VIDEO_CAPABILITY_VIWIFI = 0x04,

    VDM_VIDEO_CAPABILITY_MAX = 0xff,
} vdm_video_capability_enum;

#endif // _VDM_IMSP_ENUMS_H_
