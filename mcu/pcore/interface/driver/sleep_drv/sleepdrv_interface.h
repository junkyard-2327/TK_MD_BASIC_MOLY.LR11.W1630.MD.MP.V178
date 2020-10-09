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
 *   sleepdrv_interface.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the public access for sleep mode operation.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 23 2016 che-wei.chang
 * [MOLY00214591] add compiler option MT6750S for TOPSM/OST driver
 *
 * 08 11 2016 che-wei.chang
 * [MOLY00196533] [IRONMAN] implement sleep log function
 *
 * 03 07 2016 guo-huei.chang
 * [MOLY00167789] [MT6757] sleep driver update
 * 	
 * 	update sleep driver for Olympus
 *
 * 10 12 2015 guo-huei.chang
 * [MOLY00144627] ELT trace for TPPA+MET
 * 	TPPA Trace for Pcore Sleep
 *
 * 08 07 2015 guo-huei.chang
 * [MOLY00133506] [MT6797] sleep drivder update
 * 	add at command for PCORE sleep LOCK and UNLOCK
 *
 * 08 04 2015 guo-huei.chang
 * [MOLY00133506] [MT6797] sleep drivder update
 * 	fix sleep driver build error for EVEREST
 *
 * 07 29 2015 vmick.lin
 * [MOLY00133112] [Jade][Sleep Mode IT][OSTD] pcore can not leave sleep causing OST stay in SETTLE state
 * 	Resolve OST lock in settle state
 *
 * 07 29 2015 guo-huei.chang
 * [MOLY00131103] Sleep Mode Debug Shared Memory Mechanism Improvement
 * 	1. add CCIRQ CMD for L1core querying shared memory address
 * 	2. add fix pat API for PScore and L1core and ring buffer API for L1core
 * 	3. add fix pat in CheckSleep function
 * 	4. add declarion for DBM and PTPOD shared memory
 *
 * 07 23 2015 guo-huei.chang
 * [MOLY00131103] Sleep Mode Debug Shared Memory Mechanism Improvement
 * 	1. add CCIRQ CMD for L1core querying shared memory address
 * 	2. add fix pat API for PScore and L1core and ring buffer API for L1core
 * 	3. add fix pat in CheckSleep function
 * 	4. add declarion for DBM and PTPOD shared memory
 *
 * 06 11 2015 che-wei.chang
 * [MOLY00089700] [TK6291][UMOLY]
 * 1.add MT6755 flag for Jade 
 * 2.update ostd elt log 
 * 3.update SleepDrv_GetHandle return value for assert
 *
 * 05 05 2015 che-wei.chang
 * [MOLY00089700] [TK6291][UMOLY] add enum PS_PLL_FORCEON_USER_SIB to PS_PLL_FORCEON_USER for SIB
 *
 * 04 29 2015 che-wei.chang
 * [MOLY00089700] [TK6291][UMOLY] add a new API MD_TOPSM_PLL_SW_Control for force on PS side PLLs
 *
 * 04 29 2015 che-wei.chang
 * [MOLY00089700] [TK6291][UMOLY] Sync vmick Cbr (Ccirq)
 *
 * 02 26 2015 che-wei.chang
 * [MOLY00089700] [TK6291][UMOLY] Sync MT6291_DEV branch
 *
 * 02 10 2015 yu-hung.huang
 * [MOLY00095165] [TK6291] Check in LITE GPT Driver and New Sleep API
 * [UMOLY] 2-leve GPT solution: refine SRCLK (26M) force on/off API interface for multiple user
 *
 * 09 05 2014 yu-hung.huang
 * [MOLY00078094] [UMOLY] Sleep Codes Sync from MOLY TRUNK to UMOLY TK6291_DEV
 * [TK6291_DEV] Sync SD3 Sleep Driver Codes from MOLY TRUNK to UMOLY (Changelists before 2014/9/4 in MOLY TRUNK)
 *
 * 08 27 2014 vmick.lin
 * [MOLY00075930] [MT6582LTE][CSFB DSDS][HQ][Ericsson][lwg bin] [ASSERT] file:rf_conflict_check.c line:97
 * 	.
 *
 * 08 27 2014 vmick.lin
 * [MOLY00075930] [MT6582LTE][CSFB DSDS][HQ][Ericsson][lwg bin] [ASSERT] file:rf_conflict_check.c line:97
 * 	.
 *
 * 08 26 2014 vmick.lin
 * [MOLY00075930] [MT6582LTE][CSFB DSDS][HQ][Ericsson][lwg bin] [ASSERT] file:rf_conflict_check.c line:97
 * 	.
 * 	Add 99T 32K period while OST struggle in SETTLE state
 *
 * 10 25 2013 alvin.chen
 * [MOLY00043719] [MT6290][MDTOPSM] Patch for Phone Field trial activity
 * Integration change.
 *
 * 10 03 2013 alvin.chen
 * [MOLY00040177] [MT6290][MD_TOPSM] Add FRC enable API for Early Stage Debug
 * <saved by Perforce>
 *
 * 07 26 2013 barry.hong
 * [MOLY00030921] [MT6290]Low Power Feature patch back from CBr
 * Low Power Feature patch back from CBr
 *
 * 02 26 2013 jeff.lee
 * reorg. header file.
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __SLEEPDRV_INTERFACE_H__
#define __SLEEPDRV_INTERFACE_H__

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
#include "sleepdrv_common.h"
#endif /* defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S) */

#if defined(__SMART_PHONE_MODEM__) && defined(__MODEM_CCCI_EXIST__) && defined(__HIF_SDIO_SUPPORT__)
#define PHONE_TYPE_FOR_HQA
#endif

#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
typedef void (*SleepDrv_CCIRQ_CALLBACK_P)(kal_uint32 data1, kal_uint32 data2);

typedef enum
{
   PS_PLL_FORCEON_USER_CTI = 0,
   PS_PLL_FORCEON_USER_SIB,	
   NUM_OF_PLL_FORCEON_USER
} PS_PLL_FORCEON_USER;

typedef enum
{
   PS_TOPSM_PSMCU_PLL = 0,
   PS_TOPSM_ARM7_PLL,
   PS_TOPSM_BUS2X_PLL,
   PS_TOPSM_DBG_PLL,
   NUM_OF_PS_TOPSM_PLL
} PS_TOPSM_PLL;
#endif /* defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S) */

kal_uint8 SleepDrv_GetHandle( void );
void SleepDrv_SleepDisable( kal_uint8 handleCount );
void SleepDrv_SleepEnable( kal_uint8 handleCount );
#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
void SleepDrv_RegisterCcirqCallback(SleepDrv_CCIRQ_CMD_E cmd, SleepDrv_CCIRQ_CALLBACK_P funcp);
void SleepDrv_TriggerCcirqInterrupt(SleepDrv_CCIRQ_CMD_E cmd, kal_uint32 data1, kal_uint32 data2);
void SleepDrv_UpdatePSSlpDbgShmFixBuf(SLP_DBG_SHM_FIX_REG_INDEX index, kal_uint32 value);
void SleepDrv_UpdateSlpCntToShm(kal_uint32 cnt,kal_uint32 time,kal_uint32 acc_time);
#endif /* defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S) */

/* MDTOPSM Public API */
extern void MD_TOPSM_EnableFRC(void); /* Enable FRC API for exception handling */
extern kal_uint32 MD_TOPSM_GetRMResourceSettleTime(void); /* Get RM_RESOURCE_SETTLE in 32K unit for 2-level GPT solution */
#if defined(MT6290) || defined(MT6595) || ( defined(MT6752) && defined(__MD1__) ) || defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
extern kal_uint8 MD_TOPSM_SRCLK_SW_Control_GetHandle( kal_char* module_name ); /* Register the module as a SRCLK force on user */
extern void MD_TOPSM_SRCLK_SW_Control( kal_uint8 handleNum, kal_bool fOn ); /* SW lock or unlock 26M */
extern void MD_TOPSM_Get_SRCLK_SW_Control_State( kal_uint32 *srclk_forceOn_enable ); /* Get SW lock or unlock 26M state */
extern void MD_TOPSM_PLL_SW_Control(PS_PLL_FORCEON_USER USER,PS_TOPSM_PLL PLL, kal_bool fOn);
#endif
extern kal_bool MD_TOPSM_SleepEnable( void );
extern kal_bool MD_TOPSM_SleepDisable( void );
extern kal_bool MD_TOPSM_TPPA_Dump_Current_Info(void);

#ifdef __CENTRALIZED_SLEEP_MANAGER__
#include "reg_base.h"
#if defined(MT6290) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
extern volatile kal_uint32 ostd_patch_us_timer_period;
#define GET_TOPSM_FRC_VAL_R()             (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x88)+ostd_patch_us_timer_period)
#define GET_TOPSM_FRC_SYNC_VAL_2G_US()    (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x90)+ostd_patch_us_timer_period)
#define GET_TOPSM_FRC_SYNC_VAL_2G_26M()   (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x94))
#define GET_TOPSM_FRC_SYNC_VAL_3G_US()    (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x98)+ostd_patch_us_timer_period)
#define GET_TOPSM_FRC_SYNC_VAL_3G_26M()   (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x9C))
#define GET_TOPSM_FRC_SYNC_VAL_TDD_US()   (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0xA0)+ostd_patch_us_timer_period)
#define GET_TOPSM_FRC_SYNC_VAL_TDD_26M()  (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0xA4))
#define SET_GPS_SYNC_TIME(_val)           (*(volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0xC4))=(_val - ostd_patch_us_timer_period)
#else /*not MT6290*/
#define GET_TOPSM_FRC_VAL_R()             (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x88))
#define GET_TOPSM_FRC_SYNC_VAL_2G_US()    (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x94))
#define GET_TOPSM_FRC_SYNC_VAL_2G_26M()   (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x90))
#define GET_TOPSM_FRC_SYNC_VAL_3G_US()    (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x9C))
#define GET_TOPSM_FRC_SYNC_VAL_3G_26M()   (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x98))
#define GET_TOPSM_FRC_SYNC_VAL_TDD_US()   (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x9C))
#define GET_TOPSM_FRC_SYNC_VAL_TDD_26M()  (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x98))
#define SET_GPS_SYNC_TIME(_val)           (*(volatile kal_uint32 *)(MD_TOPSM_BASE+0x300))=(_val)
#endif /*MT6290*/

#else /*__CENTRALIZED_SLEEP_MANAGER__*/
#define GET_TOPSM_FRC_VAL_R()
#define GET_TOPSM_FRC_SYNC_VAL_2G_US()
#define GET_TOPSM_FRC_SYNC_VAL_2G_26M()
#define GET_TOPSM_FRC_SYNC_VAL_3G_US()
#define GET_TOPSM_FRC_SYNC_VAL_3G_26M()
#define GET_TOPSM_FRC_SYNC_VAL_TDD_US()
#define GET_TOPSM_FRC_SYNC_VAL_TDD_26M()
#define SET_GPS_SYNC_TIME(_val)

#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

#endif
