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

/*******************************************************************************
 * Filename:
 * ---------
 *   tcm_ratdm_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 * 
 * -------
 * $Log$
 *
 * 04 11 2016 janani.murthy
 * [MOLY00172045][Multiple_PS (23G NAS -AS -L4 interface)  - PS9]
 *
 * 01 24 2013 poying.chuang
 * [MOLY00009298] [TCM][UGTCM] Merge from JEFF_CBR to MOLY
 * TCM: Merge from JEFF_CBR to MOLY (non-TCM files) .
 *
 * 12 07 2012 andrew.wu
 * [MOLY00007098] LOCAL_PARA_HDR/PEER_BUF_HDR modification
 * LOCAL_PARA_HDR/PEER_BUF_HDR modification
 * 
 * 08 07 2012 andrew.wu
 * [MOLY00001588] [MT6575_ADAPT][LTE-BTR-1-7302] Bad audio qualilty in 12.2Kbps Uplink
 * [uas]URLC TM queue switchable modification
 *
 * 05 04 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 04 24 2012 wcpuser_integrator
 * removed!
 * .
 *
 * 04 02 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 01 30 2012 poying.chuang
 * removed!
 * .
 *
 * 01 11 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 01 11 2012 carlson.lin
 * removed!
 * <saved by Perforce>
 *
 * 12 24 2010 max.yin
 * removed!
 * .
 *
 * 12 22 2010 max.yin
 * removed!
 * .
 *
 * 12 14 2010 max.yin
 * removed!
 * .
 *
 * 10 18 2010 max.yin
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 ******************************************************************************/

#ifndef TCM_RATDM_STRUCT_H
#define TCM_RATDM_STRUCT_H

#include "kal_general_types.h"
#include "kal_public_defs.h"

#include "ps_public_enum.h"

/* __HSDPA_SUPPORT__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 no_of_nsapis;
    kal_uint8 nsapi_list[11];
    data_speed_activate_enum capability[11];
} tcm_ratdm_ps_bearer_capability_ind_struct; 

#ifdef __MULTIPLE_PS__
typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_main_ps;
} tcm_ratdm_data_allow_req_struct;
#endif

#endif /* TCM_RATDM_STRUCT_H */
