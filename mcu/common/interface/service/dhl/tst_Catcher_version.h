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
 *   tst_Catcher_version.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Version info used by host tool (ELT/Catcher)
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 02 05 2016 jean.tsao
 * [MOLY00164522] [LR11][MP3] Add enum to decide whether peer buffer header exists or not
 * [LR11] [MP3] Add enum to decide whether peer buffer header exists or not
 *
 * 07 22 2015 eason.lai
 * [MOLY00130157] [TK6291][DHL] smart logging migration
 * 	.
 *
 * 05 21 2015 eason.lai
 * [MOLY00115364] [TK6291][DHL] trigger flush depended on log threshold
 * 	1. add log flush threshold
 *                       2. remove unnecessary ELT db info
 *                       3. fixed meta mode enable trace event trigger fail case
 *
 * 04 27 2015 eason.lai
 * [MOLY00109573] [TK6291] [DHL] force user update ELT to v2.1515
 * 	.
 *
 * 04 01 2015 cynthia.sun
 * [MOLY00105635] [TK6291][DHL] L1CORE ASM
 * .
 *
 * 11 24 2014 eason.lai
 * [MOLY00084440] [MT6291][DHL] Patch back UMOLY trunk from MT6291_DEV
 * FMA global timer
 *
 * 11 14 2014 eason.lai
 * [MOLY00084440] [MT6291][DHL] Patch back UMOLY trunk from MT6291_DEV
 *  first time patch back
 *
 * 08 07 2014 hk.yang
 * [MOLY00074542] [K2 MD2] make swtr work well on K2 MD2
 * 	Enable SWTR
 *
 * 05 07 2014 eason.lai
 * [MOLY00064969] [DHL]expand tab to 4 spaces to have better typesettings
 * .
 *
 * 03 04 2014 mojo.lai
 * [MOLY00058206] Add Sim information to database
 *  .
 *
 * 01 21 2014 wcpuser_integrator
 * [MOLY00054475] SGLTE option rename
 * .
 *
 * 11 08 2013 mojo.lai
 * [MOLY00043724] Fix klockwork warning
 *  .
 *
 * 10 18 2013 mojo.lai
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 *  .
 *
 * 10 18 2013 mojo.lai
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 *  .
 *
 * 04 03 2013 mojo.lai
 * [MOLY00009210] TATAKA merge to MOLY
 * SWTR merge
 *
 * 02 04 2013 ken.liu
 * [MOLY00009212] LTE Multimode merge back to MOLY
 * rename MT7208 to MT6290.
 *
 * 11 07 2012 ken.liu
 * [MOLY00005322] TATAKA merge to MOLY
 * dhl module check-in.
 ****************************************************************************/

#ifndef __TST_CATCHER_VERSION_H__
#define __TST_CATCHER_VERSION_H__

#if defined (L1_SIM)
#if (defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__))
#define __MAUI_SOFTWARE_TRACER__
#endif
#else
#include "swtr.h"   // for __MAUI_SOFTWARE_TRACER__ definition
#endif
#include "us_timer.h"   // for __HW_US_TIMER_SUPPORT__ definition
 
#if defined(GEN_FOR_PC)

//This structure is for Catcher usage only
//Catcher owners should update these enum if they would like keep some information into the database.

#include "global_def.h"

typedef enum
{
 Catcher_Info_Enum_Begin,
 //Please add content here
 
 //Common indications
 CATCHER_NEW_DESCR_INFO_STRUCT,
 CATCHER_TST_END_REDUMP_TRACE,
 CATCHER_DB_ON_MD_ARM,

 //General Optional indications
#if defined(__UMTS_RAT__) 
 CATCHER_L1_TIMESTAMP,                  // support timestamp packed in all L1 frames 
#endif  //#if defined(__UMTS_RAT__)

#ifndef LOW_COST_SUPPORT 
 CATCHER_STATISTICS_STRING_REPLACING,   // support Statistics and FLC string replacing
#endif  //#ifndef LOW_COST_SUPPORT 

#ifdef __EM_MODE__
 CATCHER_ENGINEERING_MODE_INDEPENDENT_UPDATE,
#endif  //#ifdef __EM_MODE__


#if defined(MTK_SLEEP_ENABLE) 
#if defined(__EGPRS_MODE__)||defined(__SMART_PHONE_MODEM__)||defined(__UMTS_RAT__)
 FORCE_CATCHER_XON,
#endif  //#if defined(__EGPRS_MODE__)||defined(__SMART_PHONE_MODEM__)||defined(__UMTS_RAT__)
#endif  //#if defined(MTK_SLEEP_ENABLE)  

#if defined(__UMTS_RAT__)
 CATCHER_UL1_TIMESTAMP,                  // support RTOS_TimeStamp in UL1 Time Trace 
#else 
 CATCHER_L1_TIMESTAMP_SIM1, 
#endif  //#if defined(__UMTS_RAT__)  


#if defined(__MAUI_SOFTWARE_TRACER__)
 CATCHER_SW_TRACER_ENABLE,
#else   //#if defined(__MAUI_SOFTWARE_TRACER__)
 CATCHER_SW_TRACER_DISABLE,
#endif  //#if defined(__MAUI_SOFTWARE_TRACER__)

 //MTK Internal Optional indications
#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)
 CATCHER_SWLA_SWTR_DYNAMIC_ENABLE,

#if defined(__HW_US_TIMER_SUPPORT__)
 CATCHER_SWLA_NEW_CLOCK_ENABLE,
#endif  //#if defined(__HW_US_TIMER_SUPPORT__)
 CATCHER_SWLA_SWTR_DYNAMIC_DISABLE,
 CATCHER_SWLA_EMI_QUERY_ENABLE,

#endif  //#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)
#if defined(__DSP_FCORE4__) && !defined(UNIT_TEST)
  CATCHER_FCORE_MEMORY_DUMP_ENABLE,
#endif  //#if defined(MT6270A) || defined(MT6276) || defined(MT6573)
 CATCHER_R5R6_CPHY_CONTAINER_STRUCT, 
 CATCHER_GDI_LAYER_BYTES_PER_PIXEL_INFO,
#if defined(__AST_TL1_TDD__) && !defined(UNIT_TEST)
 CATCHER_AST_MEMORY_DUMP_ENABLE,
#endif  //#if defined(__AST_TL1_TDD__) && !defined(UNIT_TEST) 

#if defined( __UMTS_TDD128_MODE__)
 CATCHER_DB_FOR_TDD,
#endif  //#if defined( __UMTS_TDD128_MODE__)

#if defined(__AST_TL1_TDD__)
 CATCHER_AST_FAST_MEMORY_DUMP,
#endif  //#if defined(__AST_TL1_TDD__)

 CATCHER_EM_MULTIPLE_SIM_ENABLE,
 CATCHER_SIM_READ_MULTIPLE_SIM_ENABLE,
 CATCHER_PS_NO_FN, //Indicate PS log won't send out FNs.
 
#if defined(__SMART_PHONE_MODEM__)
 CATCHER_PS_NO_CHECK_SUM_ENABLED, //Support 0x58 and 0x59
 CATCHER_L1_NO_CHECK_SUM_ENABLED, //Support 0xA6
#endif 
 
#if defined(__LTE_RAT__)
  #if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
    LTE_MM,
  #else
    LTE_SM,
  #endif
#else
    GSM_UMTS,
#endif

#if !defined(__UE_SIMULATOR__) && !defined(UNIT_TEST) 
#ifdef __MALMO_ASM_SWTR__
 CATCHER_MALMO_SWTR_HEADER,
#endif
#endif

#if defined(__SGLTE__)
 MMDS_DC,
#endif 
 
#if defined (__MAUI_SOFTWARE_TRACER__)
 CATCHER_SWTR_NEW_TIME_SCALE,  // change SWTR time scale from 1/16 to 1/1024
#endif 

 Catcher_Info_Enum_End
}Catcher_Version_Info_Enum;

typedef enum
{
  SWLA_Clock_Origin_Wrap = 5000,
  SWLA_Clock_Origin_Rate = 1083000,   //1.083MHZ  
#ifdef MT6268  
  SWLA_Clock_Rate = 3250000,   //3.25MHZ
  SWLA_Clock_Wrap = 0x0FFFFFFF,  
#else
  SWLA_Clock_Rate = 1000000,   //1MHZ
  SWLA_Clock_Wrap = 0xFFFFFFFF,    
#endif  
#if defined(OS_TICK_PERIOD_US)
  SWLA_TimeStamp_Ratio = OS_TICK_PERIOD_US, 
#else
  SWLA_TimeStamp_Ratio = 4615,  // For LMU-based SWLA to convert us to frame
#endif
  SWLA_CLOCK_END 
}Catcher_SWLA_Clock;

#ifdef NUM_OF_SIM
  #define CATCHER_NUM_OF_SIM NUM_OF_SIM
  #undef NUM_OF_SIM
#endif  //NUM_OF_SIM

//workaround
#if (defined(__GEMINI__) || defined(__SGLTE__)) && !defined(GEMINI_PLUS)
  #define GEMINI_PLUS 2
#endif  //GEMINI_PLUS

typedef enum
{
  NUM_OF_GSM_SIM = MAX_GSM_NUM,
#if defined(__UMTS_RAT__)
  NUM_OF_UMTS_SIM = MAX_UMTS_NUM,
#else
  NUM_OF_UMTS_SIM = 0,
#endif  
#if defined(__LTE_RAT__)
  NUM_OF_LTE_SIM = MAX_LTE_NUM,
#else
  NUM_OF_LTE_SIM = 0,
#endif    
  NUM_OF_SIM = MAX_SIM_NUM,
}
sim_info_enum;

#ifdef CATCHER_NUM_OF_SIM
  #define NUM_OF_SIM CATCHER_NUM_OF_SIM
#endif  //NUM_OF_SIM

//Catcher version checking
typedef enum
{
  v3_1105_00 
}
catcher_min_version;

typedef enum
{
    TIMESTAMP_PRECISION = 64 * KAL_CLOCK_RATIO_REAL
}ETimeStampPrecisionUS;


typedef enum
{
  PS_11A  
#if defined(__AST_TL1_TDD__) || defined(__UMTS_TDD128_MODE__)
  ,TDD_11A
#endif  
}
catcher_default_filter_info;

//For ELT version checking
typedef enum {
  V2_1519_0
} elt_min_version;

#define MULTI_DB_MASTER_ID (0)
#define MULTI_DB_SLAVE_ID (1)
#if defined(__PCORE__)

typedef enum {
	MULTI_DB_MASTER = MULTI_DB_MASTER_ID,
} dhl_multiple_db_type;

typedef enum {
	PCORE_DATABASE
} dhl_multiple_db_desc;

#else

typedef enum {
	MULTI_DB_SLAVE = MULTI_DB_SLAVE_ID,
} dhl_multiple_db_type;

typedef enum {
	L1CORE_DATABASE
} dhl_multiple_db_desc;

#endif

typedef enum{
      DHL_MDB_VIEW_TYPE_LTE_ADVANCED   //add L1 Trace(PCORE), Sys trace(L1CORE), PS Integrated (L1CORE)
} dhl_multiple_db_view_mapping_type;

typedef enum
{
  NO_PH_MSG_ID_TST_R8_DL_PKT_SINGLE_GPD_IND,
  NO_PH_MSG_ID_DHL_L2COPRO_DL_IP_HEADER_LOG,
  NO_PH_MSG_ID_DHL_L2COPRO_UL_IP_HEADER_LOG
}
dhl_no_peer_header_msg_id_enum;

#endif //#if defined(GEN_FOR_PC) 

#endif //__TST_CATCHER_VERSION_H__
