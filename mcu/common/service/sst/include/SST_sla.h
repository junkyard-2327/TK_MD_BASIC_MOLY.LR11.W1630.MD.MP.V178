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
 *   SST_sla.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the necessary API needed by software LA.
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
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _SST_SLA_
#define _SST_SLA_

#include "us_timer.h"
#include "SST_Concurrent_utility.h"
#include "kal_general_types.h"
#include "swla_public.h"

//#define __LOW_RAM_SWLA__ //wrap with compile option to save overhead in official load

/* Type Definition */
typedef struct SA_LoggingNode_T
{
   /* Manadatory information structure member */

#if defined(__HW_US_TIMER_SUPPORT__)
   kal_uint32   jobID;
   kal_uint32   USCNT;
   kal_uint32   frameNo;
#else /* __HW_US_TIMER_SUPPORT__ */
   kal_uint32   jobID;
   kal_uint16   TQCNT;
   kal_uint16   TQWRAP;
   kal_uint32   frameNo;
#endif /* __HW_US_TIMER_SUPPORT__ */   

} SA_LoggingNode;

/* Type Definition */
typedef struct SA_LoggingThread_T
{
   kal_uint32   ThreadID;
   kal_uint32   time;
} SA_LoggingThread;

typedef struct SA_MainDescHeader_T
{
  SA_HEADER_ID_T desc_id;
  kal_uint32     log_sz;
}
SA_MainDescHeader;

typedef struct SA_AddonHeader_T
{
  SA_HEADER_ID_T desc_id;
  kal_uint32     log_sz;
  kal_char       ext_name[8];  
} SA_AddonHeader;

typedef struct _ELM_ASM_LOG_T
{
    kal_uint32 start_timestamp;
    kal_uint32 start_frc;
    kal_uint32 frc_duration;
    kal_uint32 r_trans;
    kal_uint32 w_trans;
    kal_uint32 r_latency;
    kal_uint32 w_latency;
    kal_uint32 r_avg_latency;
    kal_uint32 w_avg_latency;
} ELM_ASM_LOG_T;
/* 
 * IF extra add-on parts are required, please modify this following number
 */
#define SA_MAX_ADDON_INFO_NUM 24

typedef struct SA_LoggingHeader_T
{   
   SA_MainDescHeader main_desc;
   SA_AddonHeader    addon_info[SA_MAX_ADDON_INFO_NUM];    
} SA_LoggingHeader;

typedef struct SA_AddonInfo_T
{   
  SA_HEADER_ID_T desc_id;
  kal_uint32 log_sz;
  kal_char ext_name[8];
  void (*SLA_AddonInfoInitFunc)(void);
  kal_bool SA_SwapOutLogging;
  kal_uint8 *(*SLA_AddonInfoLoggingFunc)(void);
  void (*SLA_AddonInfoDllDataInitFunc)(kal_uint8 **ARef, kal_uint32 *szARef);
} SA_AddonInfo;

/* Prototypes */
void SLA_RAMLogging(kal_uint32 jobID);
kal_bool SST_Get_CustPara_Addr_Len(kal_uint32 *p_addr, kal_uint32 *p_len);
kal_bool SLA_Check_Unused_RAM_Availability(kal_uint32 idx);
kal_int32 SLA_Register(SA_HEADER_ID_T desc_id, kal_uint32 log_sz, kal_char ext_name[], void (*SLA_AddonInfoInitFunc)(void), kal_uint8 *(*SLA_AddonInfoLoggingFunc)(void), kal_bool SA_SwapOutLogging, void (*SLA_AddonInfoDllDataInitFunc)(kal_uint8 **ARef, kal_uint32 *szARef) );
kal_int32 SLA_MALMO_ASM_Register(MALMO_ASM_MONITORED_REGISTERS reg);

void SLA_Disable_low_RAM_SWLA(void);
void SLA_Enable_low_RAM_SWLA(void);
void SLA_Print_low_RAM_SWLA(void);

/*************************************************************************
* FUNCTION
*  SLA_RetreiveNode(SA_LoggingNode *NodePtr, kal_uint32 NodeAmount)
*
* DESCRIPTION
*  This function is used to get the last NodeAmount Node
*
* PARAMETERS 
*  NodePtr: use to fill last NodeAmount Node
*               , user has to prepare memory with sizeof(SA_LoggingNode)*NodeAmount
*
*  NodeAmount: amount of Node user wanted
*  
*  DummyFilterOn: whether to return record 0xAAAAAAAA and 0xBBBBBBBB case
*
* RETURNS
*
*************************************************************************/
void SLA_RetreiveNode (SA_LoggingNode *NodePtr, kal_uint32 NodeAmount, kal_bool DummyFilterOn);

kal_bool SLA_SyncSWLAInfoToOtherCore(void);
kal_uint32 SLA_RetreiveOtherCoreNode(SA_LoggingNode *NodePtr, kal_uint32 NodeAmount, kal_bool DummyFilterOn);

#if defined(__PCORE__) && defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)		
void SLA_RetrieveASMELMInfo(void);
#endif
void SLA_PauseELMandGetTime(void);
void SLA_ExceptionLogging(void);

#endif /* _SST_SLA_ */
