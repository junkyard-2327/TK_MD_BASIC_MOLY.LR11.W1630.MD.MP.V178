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
 *   proxy_atci_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef _PROXY_ATCI_STRUCT_H
#define _PROXY_ATCI_STRUCT_H

#include "ps_public_struct.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"


/*
MSG_ID_PROXY_ATCI_CMD_IND
MSG_ID_PROXY_ATCI_CMD_RSP
MSG_ID_PROXY_ATCI_CMD_REQ
MSG_ID_PROXY_ATCI_CMD_CNF
MSG_ID_PROXY_ATCI_URC_IND
MSG_ID_PROXY_ATCI_URC_REQ

Put command/urc data to peer buff

*/




typedef enum
{
  PROXY_CMD_FAIL,
  PROXY_CMD_SUCCESS,
  PROXY_CMD_INTERMEDIATE_RSP,
  PROXY_CMD_NO_CARRIER,
  PROXY_CMD_BUSY,
  PROXY_CMD_CONNECT,
  PROXY_CMD_CONNECT_PS
} proxy_cmd_result_enum;

typedef enum 
{
  URC_ON_NONIMS_CHANNEL,	
  URC_ON_IMS_CHANNEL  
}proxy_urc_channel_enum;


typedef struct {

    LOCAL_PARA_HDR
    kal_uint16    ref;      /* reference number which is used to map cmd_rsp to cmd_ind*/

} proxy_atci_cmd_ind_struct;


typedef struct {

    LOCAL_PARA_HDR
	kal_uint16     ref;     /*respond the same ref as in cmd_ind.*/
    proxy_cmd_result_enum result;
    kal_bool stuff;
} proxy_atci_cmd_rsp_struct;

typedef struct{
	
    LOCAL_PARA_HDR
    kal_bool stuff;
	#ifdef __TC01_IMS_SUPPORT__
	proxy_urc_channel_enum urc_channel;
	#endif //__TC01_IMS_SUPPORT__ RICKY
}proxy_atci_urc_req_struct;


typedef struct {
	
    LOCAL_PARA_HDR
    module_type    src_mod_id;   /*original module that requests this cmd*/
    kal_uint16      ref;          /* reference number which is used to map cmd_cnf to cmd_req*/

} proxy_atci_cmd_req_struct;


typedef struct{
	
    LOCAL_PARA_HDR
    module_type    src_mod_id; /*respond the same value as in cmd_req*/
    kal_uint16      ref;        /*respond the same ref as in cmd_req.*/
	proxy_cmd_result_enum result;
    kal_bool stuff;
}proxy_atci_cmd_cnf_struct;

typedef struct{
	
    LOCAL_PARA_HDR
    kal_bool stuff;
}proxy_atci_urc_ind_struct;

#endif 


