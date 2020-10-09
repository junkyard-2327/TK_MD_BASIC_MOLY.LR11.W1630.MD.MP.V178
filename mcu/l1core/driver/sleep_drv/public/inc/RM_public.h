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
 *
 * Filename:
 * ---------
 *    RM_public.h
 *
 * Project:
 * --------
 *    MT6280
 *
 * Description:
 * ------------
 *    Resource Management configuration
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#ifdef __CENTRALIZED_SLEEP_MANAGER__

#ifndef RM_PUBLIC_H
#define RM_PUBLIC_H

#include "kal_general_types.h"

typedef enum
{
   /* Resource on MCU RM */
   //RM_MCU_BASE = 0,
   /* Resource on MODEM RM */
   MODEM_SLV_START = 0,
   RM_MD2G_SPEECH  = 0,
   RM_C2K_TRIGGER  = 4,
   RM_LTE_CS       = 5,
   RM_FDD_TD       = 6,/* talking & datalink */
   RM_FDD_DL       = 7, /* datalink */
   MODEM_SLV_END   = 7,
   MODEM_DBG_START = 8,
   RM_MODEM_CTI    = 9,
   RM_TDD_TD       = 11,
   RM_TDD_DL       = 12,
   MODEM_DBG_END   = 12,
   NUMBER_OF_RESOURCE
} RM_Module;

#if defined(MT6290) || defined(MT6595) || defined(TK6291)
typedef enum
{
    MD2AP,
    MD2DSP,
} MDTOPSM_PeerWakeup_Target;

typedef enum
{
	PWR_OFF,
	PWR_ON,
	PWR_CHANGE,		
} sm_pwrstate_e;

typedef enum
{
    PLL_MSDC
} PLL_RQST;

typedef enum
{
    LTEL2,
    APPERI,
#ifdef TK6291    
    HSPAL2SYS,
#endif    
} MDTOPSM_Power_Domain;

#endif

typedef enum
{
   MODEM_TOPSM_EMI_REQ_GSM = 0x0,
   MODEM_TOPSM_EMI_REQ_UMTS = 0x1,
   MODEM_TOPSM_EMI_REQ_LTE = 0x2
} MODEM_TOPSM_EMI_REQ_MODULE;

typedef enum
{
  TIMER_OSTD = 0,
  TIMER_2G,
  TIMER_3G_FDD,
  TIMER_3G_TDD,
  TIMER_SSTA0_END = TIMER_3G_TDD,
  TIMER_4G,
  TIMER_C2K,
  TIMER_NUM
} MODEM_TOPSM_TIMER_MODULE;

typedef enum
{
  NORMAL           =  0x1,
  MTOFF            =  0x2,
  PAUSE            =  0x4,
  PRE_PAUSE        =  0x8,
  SYSCLK_SETTLE    = 0x10,
  CCP_SETTLE       = 0x20,
  MTON             = 0x40
} MODEM_TOPSM_TIMER_STATUS;

#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
typedef enum
{
   MODEM_TOPSM_PWR_ENUM_L1MCUSYS,
   MODEM_TOPSM_PWR_ENUM_TRX_DIG_MACRO,
   MODEM_TOPSM_PWR_ENUM_MD2GSYS,
   MODEM_TOPSM_PWR_ENUM_DFESYS,
   MODEM_TOPSM_PWR_ENUM_RXBRPSYS,
   MODEM_TOPSM_PWR_ENUM_MMUSYS,
   MODEM_TOPSM_PWR_ENUM_CSTXBSYS,
   MODEM_TOPSM_PWR_ENUM_RAKESYS,
   MODEM_TOPSM_PWR_ENUM_EQSYS1,
   MODEM_TOPSM_PWR_ENUM_EQSYS2,
   MODEM_TOPSM_PWR_ENUM_EQSYS3,
   MODEM_TOPSM_PWR_ENUM_TDINRSYS1,
   MODEM_TOPSM_PWR_ENUM_TDINRSYS2,
   MODEM_TOPSM_PWR_ENUM_LTXBSYS,
   MODEM_TOPSM_PWR_ENUM_MIMOSYS,
   MODEM_TOPSM_PWR_ENUM_IMCSYS,
   MODEM_TOPSM_PWR_ENUM_CSSYS,
   MODEM_TOPSM_PWR_ENUM_MPCSYS,
   MODEM_TOPSM_PWR_ENUM_ICCSYS,
   MODEM_TOPSM_PWR_ENUM_L1INFRASYS,
   MODEM_TOPSM_PWR_ENUM_NUM
} MODEM_TOPSM_PWR_ENUM;

typedef enum
{
   MODEM_TOPSM_PLL_ENUM_L1MCU,
   MODEM_TOPSM_PLL_ENUM_BUS2X,
   MODEM_TOPSM_PLL_ENUM_RF1,
   MODEM_TOPSM_PLL_ENUM_EQ,
   MODEM_TOPSM_PLL_ENUM_BRP,
   MODEM_TOPSM_PLL_ENUM_IMC,
   MODEM_TOPSM_PLL_ENUM_ICC,
   MODEM_TOPSM_PLL_ENUM_CMP,
   MODEM_TOPSM_PLL_ENUM_DFE,
   MODEM_TOPSM_PLL_ENUM_MD2G,
   MODEM_TOPSM_PLL_ENUM_INTF,
   MODEM_TOPSM_PLL_ENUM_NUM
} MODEM_TOPSM_PLL_ENUM;

typedef enum
{
   MODEM_TOPSM_SYSCLK_ENUM_RF1_SYSCLK,
   MODEM_TOPSM_SYSCLK_ENUM_RF2_SYSCLK,
   MODEM_TOPSM_SYSCLK_ENUM_RF1_VRF18,
   MODEM_TOPSM_SYSCLK_ENUM_RF2_VRF18,
   MODEM_TOPSM_SYSCLK_ENUM_NUM
} MODEM_TOPSM_SYSCLK_ENUM;
#endif

/* TK6291 power domain mask define start */
#define PWR_L1MCUSYS            (0x1)
#define PWR_TRX_DIG_MACRO       (0x2)
#define PWR_MD2GSYS             (0x4)
#define PWR_DFESYS              (0x8)
#define PWR_RXBRPSYS           (0x10)
#define PWR_MMUSYS             (0x20)
#define PWR_CSTXBSYS           (0x40)
#define PWR_RAKESYS            (0x80)
#define PWR_EQSYS1            (0x100)
#define PWR_EQSYS2            (0x200)
#define PWR_EQSYS3            (0x400)
#define PWR_TDINRSYS1         (0x800)
#define PWR_TDINRSYS2        (0x1000)
#define PWR_LTXBSYS          (0x2000)
#define PWR_MIMOSYS          (0x4000)
#define PWR_IMCSYS           (0x8000)
#define PWR_CSSYS           (0x10000)
#define PWR_MPCSYS          (0x20000)
#define PWR_ICCSYS          (0x40000)
#define PWR_L1INFRASYS      (0x80000)
/* power domain mask define end */

void RM_Init( void );
void RM_Resource_Control( RM_Module module, kal_bool resource_on );
kal_bool RM_Resource_CheckReady( RM_Module module );

#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
extern kal_uint32 MODEM_TOPSM_GetF32k(void);
#define RM_GetF32k()  MODEM_TOPSM_GetF32k()
#endif

#if defined(MT6290) || defined(MT6595) || defined(TK6291)
extern void MD_TOPSM_PeerWakeup(MDTOPSM_PeerWakeup_Target target, kal_bool set);
extern void MD_TOPSM_PWR_SW_Control(MDTOPSM_Power_Domain pwr_dom, kal_bool enable);
#endif
kal_bool MODEM4G_TOPSM_WaitTimerAwake( void );

extern kal_uint32 MODEM_TOPSM_PollingTimingSyncSta(MODEM_TOPSM_TIMER_MODULE timer);
extern kal_uint32 MODEM_TOPSM_GetSync26M(MODEM_TOPSM_TIMER_MODULE timer);
extern void MODEM_TOPSM_ClearTimingSyncSta(MODEM_TOPSM_TIMER_MODULE timer);
extern void MODEM_TOPSM_SW_PowerControl(MODEM_TOPSM_TIMER_MODULE timer, kal_uint32 mask, kal_bool on);
extern kal_bool MODEM_TOPSM_CheckPowerRdy(kal_uint32 mask);
extern kal_uint32 MODEM_TOPSM_GetPowerRdy(void);
extern void MODEM_TOPSM_ClearPowerRdyReg(kal_uint32 mask);
extern kal_bool MODEM_TOPSM_CheckPowerRdyReg(kal_uint32 mask);
extern void MODEM_TOPSM_BypassBRP4GHWMode(void);
extern void MODEM_TOPSM_ResumeBRP4GHWMode(void);
extern MODEM_TOPSM_TIMER_STATUS MODEM_TOPSM_GetTimerStatus(MODEM_TOPSM_TIMER_MODULE timer);
extern void MODEM_TOPSM_ForceOnMTCMOS(kal_uint32 mask);
extern void MODEM_TOPSM_NonForceOnMTCMOS(kal_uint32 mask);
extern kal_bool MODEM_TOPSM_ForceOnDBGCK(void);
extern void MODEM_TOPSM_DisableForceOnDBGCK(void);
extern void MODEM_TOPSM_SW_TRIG_CSYS(kal_bool enable);
extern void MODEM_TOPSM_SetGPSSyncCon0(kal_uint32 value);
extern void MODEM_TOPSM_SetGPSSyncCon1(kal_uint32 value);
extern void MODEM_TOPSM_EMI_RequestCheck( MODEM_TOPSM_EMI_REQ_MODULE mod );
extern void MODEM_TOPSM_ForceOnVRF18(kal_bool enable);
extern kal_bool MODEM_TOPSM_TPPA_Dump_Current_Info(void);

#endif /* !RM_PUBLIC_H */
//#endif /*__CENTRALIZED_SLEEP_MANAGER__*/
