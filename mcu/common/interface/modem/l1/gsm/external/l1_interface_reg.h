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
 *   l1_interface_reg.h
 *
 * Project:
 * --------
 *   MT6280
 *
 * Description:
 * ------------
 *   Registers and constants definitions for interface
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime:  $
 * $Log:      $
 *
 * 07 08 2015 th.yeh
 * [MOLY00127028] [L1D][Modify] Refine TK6291 BB driver
 * .
 *
 * 06 18 2015 prakash.chaudhary
 * [MOLY00122406] [L1D][modify]Check in BB driver for Jade BB porting
 * 	.
 *
 * 03 26 2015 th.yeh
 * [MOLY00097507] [L1D][Modify] Bypass TK6291 1st phone call error
 * .
 *
 * 03 10 2015 th.yeh
 * [MOLY00097507] [L1D][Modify] Bypass TK6291 1st phone call error
 * .
 *
 * 02 26 2015 th.yeh
 * [MOLY00096996] [L1D][Modify] Apply MD2G HW clock gating setting for TK6291.
 * .
 *
 * 01 28 2015 th.yeh
 * [MOLY00085815] [L1D][Modify] TK6291 BB driver porting
 * .
 *
 * 12 01 2014 th.yeh
 * [MOLY00085815] [L1D][Modify] TK6291 BB driver porting
 * .
 *
 * 12 01 2014 th.yeh
 * [MOLY00085815] [L1D][Modify] TK6291 BB driver porting
 * .
 *
 * 11 26 2014 th.yeh
 * [MOLY00085814] [L1D][Modify] GL1D l1core call pcore API elimination
 * .
 *
 * 11 06 2014 hosen.chen
 * [MOLY00080383] [L1D][Modify] Check in 2G modem sim related file
 * 	.
 *
 * 11 04 2014 th.yeh
 * [MOLY00083271] [L1D][Modify] Sync GL1D driver code from MOLY trunk
 * .
 *
 * 05 29 2014 yi-ying.lin
 * [MOLY00067365] [L1D][Modify] MT6752 L1D driver developement.
 *
 * 05 29 2014 yi-ying.lin
 * [MOLY00067365] [L1D][Modify] MT6752 L1D driver developement
 * 	.
 *
 * 05 19 2014 yi-ying.lin
 * [MOLY00065703] [L1D] Add MT6752(K2) Chip option to avoid build error
 * 	.
 *
 * 12 25 2013 hosen.chen
 * [MOLY00046159] [L1D][Modify] Check in code of MT6595 2G modem driver modification
 * 	.
 *
 * 12 24 2013 hosen.chen
 * [MOLY00046159] [L1D][Modify] Check in code of MT6595 2G modem driver modification
 * 	.
 *
 * 12 17 2013 hosen.chen
 * [MOLY00046159] [L1D][Modify] Check in code of MT6595 2G modem driver modification
 * 	.
 *
 * 12 16 2013 hosen.chen
 * [MOLY00046159] [L1D][Modify] Check in code of MT6595 2G modem driver modification
 * 	.
 *
 * 11 19 2013 hosen.chen
 * [MOLY00046984] [MT6571 GB][Shanghai][EE] DUT Externel (EE),0,0,99,/data/core/,1,modem,md1: [Fatal error (task)] err_code1:773 err_code2:-2004352968
 * 	.
 *
 * 05 07 2013 sean.yang
 * [MOLY00020786] [MT6290 PO admit] Modify the MM timing sync register definition
 * .
 *
 * 04 22 2013 hosen.chen
 * [MOLY00020463] [L1D][Modify] Check in code of MT6290 phone call modification
 * .
 *
 * 04 03 2013 hosen.chen
 * [MOLY00012945] [MT6290 Bring-up] Check in code of MT6290
 * .
 *
 * 03 28 2013 hosen.chen
 * [MOLY00012945] [L1D][Modify] Check in code of MT6290
 * .
 *
 * 03 28 2013 hosen.chen
 * [MOLY00012945] [L1D][Modify] Check in code of MT6290
 * .
 *
 * 02 19 2013 yi-ying.lin
 * [MOLY00010333] [L1D][Modify] fixed MT6290 build error
 * .
 * 
 * 10 03 2012 sean.yang
 * [MOLY00002708] [MT6583] TOP SM, OS timer, and modem sleep mode modification
 * .
 * 
 * 08 28 2012 samuel.yang
 * [MOLY00002781] [L1D][Modify] Revise MSBB2 coding
 * .
 * 
 * 08 24 2012 samuel.yang
 * [MOLY00002639] [L1D][Modify] Separate l1d_reg.h into two parts of "for l1 internal use" and "for other module use"
 * .
 * 
 *******************************************************************************/

#ifndef  _L1_INTERFACE_REG_H_
#define  _L1_INTERFACE_REG_H_

#include "reg_base.h"
#include "l1_option.h"

#ifndef _COMMON_REG_H_
typedef volatile unsigned short* APBADDR;          /* APB addr is 32 bits   */
typedef volatile unsigned long*  APBADDR32;        /* APB addr is 32 bits   */
#endif

#if defined(L1_SIM)
  #if IS_CHIP_TK6291 || IS_CHIP_MT6755
/* Here are new and old regbase nameing remapping since xL1SIM HW simu code still uses old regbase naming. */
#define  TDMA_base       L1_BASE_MADDR_TDMA_BASE
#define  TDMA_SLP_base   L1_BASE_MADDR_TDMA_SLP
#define  IDMA_LONG       L1_BASE_MADDR_SHORTMODE_IDMA
#define  IDMA_SHORT      L1_BASE_MADDR_SHORTMODE_IDMA
#define  IDMA_CM0        L1_BASE_MADDR_CM_IDMA
#define  IDMA_PM0        L1_BASE_MADDR_PM_IDMA
#define  IDMA_DM0        L1_BASE_MADDR_DM_IDMA
#define  MD2GCONFG_base  L1_BASE_MADDR_MD2G_CONFG
  #endif
#endif

/***************************************************************************************************************************
 * Rigister definition for other modules                                                                                   *
 ***************************************************************************************************************************/

/*====================*\
|* TDMA               *|
\*====================*/
#if MD_DRV_IS_CHIP_TK6291 || MD_DRV_IS_CHIP_MT6755
/*TK6291~*/ #define EVENT_ENA_OFFSET(n)      (((n)>7)?2176:0)
/*TK6291~*/
/*TK6291~*/ /* TDMA timer */
/*TK6291~*/ #define TQ_CURRENT_COUNT         ((APBADDR  )(L1_BASE_MADDR_TDMA_BASE+0x0000))          /*                read quater bit counter [13:0] */
/*TK6291~*/ #define TQ_EVENT_VALID           ((APBADDR  )(L1_BASE_MADDR_TDMA_BASE+0x000C))          /*                   event latch position [13:0] */
/*TK6291~*/ #define CTIRQ1                   ((APBADDR  )(L1_BASE_MADDR_TDMA_BASE+0x0014))          /*                   CPU tdma interrupt 1 [13:0] */
/*TK6291~*/ #define EVENT_ENA(n)             ((APBADDR32)(L1_BASE_MADDR_TDMA_BASE+0x0150+((n)*4)+EVENT_ENA_OFFSET(n)))  /* event enable control n    */
/*TK6291~*/ #define TQ_BIAS_CONT             ((APBADDR  )(L1_BASE_MADDR_TDMA_BASE+0x0174))          /* Qbit Timer Biasing Control Register           */
/*TK6291~*/ #define TDMA_AUXEV0              ((APBADDR  )(L1_BASE_MADDR_TDMA_BASE+0x0400))          /* Auxiliary ADC event 0                         */
/*TK6291~*/ #define TDMA_AUXEV1              ((APBADDR  )(L1_BASE_MADDR_TDMA_BASE+0x0404))          /* Auxiliary ADC event 1                         */
/*TK6291~*/ #define TDMA_AUXEVENA            EVENT_ENA(7)                                           /* Auxiliary ADC event enable register           */
/*TK6291~*/ /* TDMA sleep */
/*TK6291~*/ #define TQ_WRAP                  ((APBADDR  )(L1_BASE_MADDR_TDMA_SLP +0x0004))          /*    latched Qbit counter reset position [13:0] */
#else
/*else   */ #error "Please check TDMA related settings"
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Sleep mode */
#if defined(L1_SIM)
   #if MD_DRV_IS_CENTRALIZED_SMM_CHIP
#define SleepMode_base           TOPSM_base
   #else
#define SleepMode_base           SM_base
   #endif
   
   #if MD_DRV_IS_CENTRALIZED_SMM_CHIP
#define RTCCOUNT                 ((APBADDR32)(SleepMode_base+0x0104))     /* 32K count                                     */
   #else
#define RTCCOUNT                 ((APBADDR32)(SleepMode_base+0x0030))     /* 32K count                                     */
   #endif

   #if MD_DRV_IS_CENTRALIZED_SMM_CHIP
#define SM_FRC_CON               ((APBADDR32)(SleepMode_base+0x0080))     /* Free Running Counter Control Register         */
#define SM_FM_CAL                ((APBADDR32)(SleepMode_base+0x00B4))     /* Frequency Measurement Calibration Control     */
#define SM_FM_T0                 ((APBADDR32)(SleepMode_base+0x00B8))     /* Frequency Measurement Start Time              */
#define SM_FM_T1                 ((APBADDR32)(SleepMode_base+0x00BC))     /* Frequency Measurement End   Time              */
#define SM_FM_CON                ((APBADDR32)(SleepMode_base+0x00B0))     /* Frequency Measurement Control Register        */
  #endif
#endif /* defined(L1_SIM) */

/*====================*\
|* IDMA               *|
\*====================*/
#if MD_DRV_IS_CHIP_TK6291 || MD_DRV_IS_CHIP_MT6755
/*TK6291~*/ #define IDMA_LONG                (L1_BASE_MADDR_SHORTMODE_IDMA)
/*TK6291~*/ #define IDMA_SHORT               (L1_BASE_MADDR_SHORTMODE_IDMA)
/*TK6291~*/ #define IDMA_CM0                 (L1_BASE_MADDR_CM_IDMA)
/*TK6291~*/ #define IDMA_PM0                 (L1_BASE_MADDR_PM_IDMA)
/*TK6291~*/ #define IDMA_DM0                 (L1_BASE_MADDR_DM_IDMA)
#else
/*else   */ #error "Please check IDMA related settings"
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*====================*\
|* MCU PDN            *|
\*====================*/
#if MD_DRV_IS_CHIP_TK6291 || MD_DRV_IS_CHIP_MT6755
/*TK6291~*/ #define TDMA_CLK_MUX             ((APBADDR32)(L1_BASE_MADDR_MDL1_CONF+0x0080)) /* Qbit Timer Biasing Control Register  */
/*TK6291~*/ #define MDL1AO_PERI_CG_CON       ((APBADDR32)(L1_BASE_MADDR_MDL1_CONF+0x0000)) /* MDL1AO_PERI_CG_CON_REG               */
/*TK6291~*/ #define MDL1AO_PERI_CG_SET       ((APBADDR32)(L1_BASE_MADDR_MDL1_CONF+0x0004)) /* MDL1AO_PERI_CG_CON WRITE 1 SET REG   */
/*TK6291~*/ #define MDL1AO_PERI_CG_CLR       ((APBADDR32)(L1_BASE_MADDR_MDL1_CONF+0x0008)) /* MDL1AO_PERI_CG_CON WRITE 1 CLEAR REG */
/*TK6291~*/
/*TK6291~*/ #define MODEM_PDNCON_TDMA_SLP    0x0004
#else
/*else   */ #error "Please check MCU PDN related settings"
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*====================*\
|* MD2G PDN           *|
\*====================*/
#if MD_DRV_IS_CHIP_TK6291 || MD_DRV_IS_CHIP_MT6755
/*TK6291~*/ #define MD2GSYS_CG_CON0         ((APBADDR)(L1_BASE_MADDR_MD2G_CONFG+0x000))      /* Power Down Control 0 Register        */
/*TK6291~*/ #define MD2GSYS_CG_CON2         ((APBADDR)(L1_BASE_MADDR_MD2G_CONFG+0x008))      /* Power Down Control 2 Register        */
/*TK6291~*/ #define MD2GSYS_CG_CON4         ((APBADDR)(L1_BASE_MADDR_MD2G_CONFG+0x030))      /* Power Down Control 4 Register        */
/*TK6291~*/ #define MD2GSYS_CG_SET0         ((APBADDR)(L1_BASE_MADDR_MD2G_CONFG+0x010))      /* Power Down Disable 0 Register        */
/*TK6291~*/ #define MD2GSYS_CG_SET2         ((APBADDR)(L1_BASE_MADDR_MD2G_CONFG+0x018))      /* Power Down Disable 2 Register        */
/*TK6291~*/ #define MD2GSYS_CG_SET4         ((APBADDR)(L1_BASE_MADDR_MD2G_CONFG+0x034))      /* Power Down Disable 4 Register        */
/*TK6291~*/ #define MD2GSYS_CG_CLR0         ((APBADDR)(L1_BASE_MADDR_MD2G_CONFG+0x020))      /* Power Down Enable  0 Register        */
/*TK6291~*/ #define MD2GSYS_CG_CLR2         ((APBADDR)(L1_BASE_MADDR_MD2G_CONFG+0x028))      /* Power Down Enable  2 Register        */
/*TK6291~*/ #define MD2GSYS_CG_CLR4         ((APBADDR)(L1_BASE_MADDR_MD2G_CONFG+0x038))      /* Power Down Enable  4 Register        */
/*TK6291~*/ #define MD2G_PDN_CON0           MD2GSYS_CG_CON0                        /* not used                             */
/*TK6291~*/ #define MD2G_PDN_CON2           MD2GSYS_CG_CON2                        /* not used                             */
/*TK6291~*/ #define MD2G_PDN_CON4           MD2GSYS_CG_CON4                        /* not used                             */
/*TK6291~*/ #define MD2G_PDN_SET0           MD2GSYS_CG_SET0
/*TK6291~*/ #define MD2G_PDN_SET2           MD2GSYS_CG_SET2
/*TK6291~*/ #define MD2G_PDN_SET4           MD2GSYS_CG_SET4
/*TK6291~*/ #define MD2G_PDN_CLR0           MD2GSYS_CG_CLR0
/*TK6291~*/ #define MD2G_PDN_CLR2           MD2GSYS_CG_CLR2
/*TK6291~*/ #define MD2G_PDN_CLR4           MD2GSYS_CG_CLR4
/*TK6291~*/
/*TK6291~*/ #define MD2G_PDNCON_TDMA_TMR    0x0001
/*TK6291~*/ #define MD2G_PDNCON_BSI_G       0x0004
/*TK6291~*/ #define MD2G_PDNCON_BPI_G       0x0008
/*TK6291~*/ #define MD2G_PDNCON_APC         0x0020
/*TK6291~*/ #define MD2G_PDNCON_BFE         0x0200
#else
/*else   */ #error "Please check MD2G PDN related settings"
#endif
/* ======================================================================================================================= */

/***************************************************************************************************************************
 * Power Down Managerment                                                                                                  *
 ***************************************************************************************************************************/
#if MD_DRV_IS_CHIP_TK6291 || MD_DRV_IS_CHIP_MT6755
/*TK6291~*/ #define HW_IRDBG_CLK_ON()
/*TK6291~*/ #define HW_IRDBG_CLK_OFF()
/*TK6291~*/ #define HW_IRDMA_CLK_ON()        HW_WRITE(MD2G_PDN_CLR0,0x0040)
/*TK6291~*/ #define HW_IRDMA_CLK_OFF()       HW_WRITE(MD2G_PDN_SET0,0x0040)
/*TK6291~*/ #define HW_DIVIDER_CLK_ON()
/*TK6291~*/ #define HW_DIVIDER_CLK_OFF()
/*TK6291~*/ #define HW_FCS_CLK_ON()
/*TK6291~*/ #define HW_FCS_CLK_OFF()
#else
/*Else   */ #define HW_IRDBG_CLK_ON()
/*Else   */ #define HW_IRDBG_CLK_OFF()
/*Else   */ #define HW_IRDMA_CLK_ON()        HW_WRITE(MD2G_PDN_CLR0,0x0040)
/*Else   */ #define HW_IRDMA_CLK_OFF()       HW_WRITE(MD2G_PDN_SET0,0x0040)
/*Else   */ #define HW_DIVIDER_CLK_ON()      HW_WRITE(PDN_CLR2     ,0x0800)
/*Else   */ #define HW_DIVIDER_CLK_OFF()     HW_WRITE(PDN_SET2     ,0x0800)
/*Else   */ #define HW_FCS_CLK_ON()          HW_WRITE(PDN_CLR2     ,0x1000)
/*Else   */ #define HW_FCS_CLK_OFF()         HW_WRITE(PDN_SET2     ,0x1000)
#endif
/* ======================================================================================================================= */

/***************************************************************************************************************************
 * Global constant and data definition for other modules                                                                   *
 ***************************************************************************************************************************/

/* PDN mask and sleep mode settings */
#if MD_DRV_IS_CHIP_TK6291 || MD_DRV_IS_CHIP_MT6755
/*TK6291~*/ #define MODEMSYS_MASK           0x0004  // ModemSYS(CLR):  TDMA_SLP
/*TK6291~*/ #define MODEM_SLPON             0x0004  // Clock on  module in sleep mode: TDMA_SLP
/*TK6291~*/ #define MODEM_SLPOFF            0x0000  // Clock off module in sleep mode: none
/*TK6291~*/
/*TK6291~*/ #define MD2G_MASK1              0x0002  // MD2G(CLR0):     GCC
/*TK6291~*/ #define MD2G_MASK2              0x022D  // MD2G(CLR2):     BFE, APC, BPI_G, BSI_G, TDMA_TMR
   #if IS_TK6291_HW_BUG_SW_WORKAROUND_SUPPORT
/*TK6291~*/ #define MD2G_SLPON              0x000D  // Clock on  module in sleep mode: TDMA_TMR,BPI_G,BSI_G
/*TK6291~*/ #define MD2G_SLPOFF             0x0222  // Clock off module in sleep mode: BFE,APC,GCC
   #else
/*TK6291~*/ #define MD2G_SLPON              0x0001  // Clock on  module in sleep mode: TDMA_TMR
/*TK6291~*/ #define MD2G_SLPOFF             0x022E  // Clock off module in sleep mode: BFE,APC,BPI_G,BSI_G,GCC
   #endif
#else
/*else   */ #error "Please check PDN mask and sleep mode settings"
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if MD_DRV_IS_CHIP_TK6291 || MD_DRV_IS_CHIP_MT6755
   #if (defined L1D_TEST)
/*TK6291~*/ #define PWR_ON_SETTLE           4
   #else
/*TK6291~*/ #define PWR_ON_SETTLE           2
   #endif
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* TDMA timing */
#if MD_DRV_IS_AST_B2S_SUPPORT
#define MD_DRV_TQ_AFC_READY                 245
#else
#define MD_DRV_TQ_AFC_READY                 256
#endif

#if MD_DRV_IS_CHIP_TK6291 || MD_DRV_IS_CHIP_MT6755
#define MD_DRV_TQ_MAXIMUM                   16383                                        /*16383: 0x3FFF*/
#endif
#define MD_DRV_TQ_SLOT_LEN                  (156*4)
#define MD_DRV_TQ_WRAP_COUNT                5000
#define MD_DRV_TQ_VALIDATE_COUNT            4939
#define MD_DRV_TQ_CTIRQ1                    (MD_DRV_TQ_AFC_READY+625*5)
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#define MD_DRV_EVTENA0_SLOW_EN_SEL          (0)
/*=========================================================================================================================*/

#endif
