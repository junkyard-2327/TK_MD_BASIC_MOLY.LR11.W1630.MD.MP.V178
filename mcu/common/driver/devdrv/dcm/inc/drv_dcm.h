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
 *   drv_dcm.h
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *   dcm driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 11 25 2015 chin-chieh.hung
 * [MOLY00145065] Update 6291 series DCM flow
 * roolback modemL1 bus DCM function
 *
 * 09 09 2015 chin-chieh.hung
 * [MOLY00141079] [WW FT][MT6755][Jade-L1][MP1][Italy-Rome][TRE][TIM][ASSERT] file:pcore/service/hif/ccci/src/ccci_debug.c line:533
 * update DCM setting and add IRQ mask for shared register access
 *
 * 07 22 2015 chin-chieh.hung
 * [MOLY00121469] Update for Jade/TK6291 platform driver
 * update dcm driver for Jade
 *
 * 01 14 2014 chin-chieh.hung
 * [MOLY00053645] Add MT6595 DCM driver
 * Merging
 *  	
 * 	//MOLY_CBr/chin-chieh.hung/MT6595E1_BRING_UP_DEV_W1402p7/mcu/driver/devdrv/dcm/inc/drv_dcm.h
 *  	
 * 	to //MOLY/TRUNK/MOLY/mcu/driver/devdrv/dcm/inc/drv_dcm.h
 *
 * 12 12 2013 chin-chieh.hung
 * [MOLY00045704] Init MT6595 common driver
 * Add DCM flow
 *
 * 12 06 2013 chin-chieh.hung
 * [MOLY00045704] Init MT6595 common driver
 * ROME Porting
 *
 * 11 12 2013 chin-chieh.hung
 * [MOLY00045704] Init MT6595 common driver
 * fix error setting
 *
 * 03 08 2013 barry.hong
 * [MOLY00011608] MT6290 MOLY fake API remove
 * .remove fakeAPI
 ****************************************************************************/

#ifndef __DCM_REG_H__
#define __DCM_REG_H__

#include <reg_base.h>
#include <intrCtrl.h>

#if defined(DCM_ENABLE)
//#include "pll.h"

/* DCM */
#define   GLOBAL_DCM_BASE BASE_MADDR_GLBCON_CLKCTL
#define MDGLOBAL_DCM_BASE BASE_MADDR_MDTOP_GLBCON /* BASE_MADDR_MD_GLBCON_TOP_DCM */
#define MDSYS_L2DCM_BASE  BASE_MADDR_MDSYS_CLKCTL
#define MDL1_L2DCM_BASE   L1_BASE_MADDR_MDL1_CONF

/* Global DCM definition */
#define GLOBAL_DCM_CODA          (GLOBAL_DCM_BASE + 0x0000UL)
#define GLOBAL_DCM_APMCU_CTRL0   (GLOBAL_DCM_BASE + 0x0010UL)
#define GLOBAL_DCM_APMCU_CTRL1   (GLOBAL_DCM_BASE + 0x0014UL)

#define GLOBAL_DCM_TOPBUS_CTRL0  (GLOBAL_DCM_BASE + 0x0018UL)
#define GLOBAL_DCM_TOPBUS_CTRL1  (GLOBAL_DCM_BASE + 0x001CUL)
#define GLOBAL_DCM_TOP_STATUS    (GLOBAL_DCM_BASE + 0x0100UL)
#define GLOBAL_DCM_CHIP_CONFIG0  (GLOBAL_DCM_BASE + 0x0800UL)
#define GLOBAL_DCM_CHIP_CONFIG1  (GLOBAL_DCM_BASE + 0x0804UL)
#define GLOBAL_DCM_AP_TOP_DUMMY  (GLOBAL_DCM_BASE + 0x1000UL)
#define GLOBAL_DCM_AP_TOP_STATUS (GLOBAL_DCM_BASE + 0x1004UL)

/* MD Global DCM definition */
#define MDGB_DCM_CODA            (MDGLOBAL_DCM_BASE + 0x0000UL)
#define PSMCU_DCM_CTRL0          (MDGLOBAL_DCM_BASE + 0x0010UL)
    #define PSMCU_DCM_FORCE_OFF         (1UL<<31) //force DCM clock_out = off
    #define PSMCU_DCM_PLL_SWICH_CKEN    (1UL<<28)
    #define PSMCU_DCM_DBC_CNT(x)        (((x)&0x7F)<<20)
    #define PSMCU_DCM_IDLE_FSEL(x)      (((x)&0x1F)<<12)
    #define PSMCU_DCM_NORMAL_FSEL(x)    (((x)&0x1F)<<4)
    #define PSMCU_DCM_DBC_EN            (1UL<<2)
    #define PSMCU_DCM_EN                (1UL<<1)
    #define PSMCU_DCM_FORCE_ON          (1UL<<0) //force DCM clock_out == DCM clock_in
#define PSMCU_DCM_CTRL1          (MDGLOBAL_DCM_BASE + 0x0014UL)
    #define PSMCU_DCM_SYNC_SETTING      (1UL<<5) 
    #define PSMCU_DCM_SYNC_IDLE_FSEL    (1UL<<4) 
    #define PSMCU_DCM_SYNC_NORMAL_SEL   (1UL<<3) 
    #define PSMCU_DCM_SYNC_DBC_EN       (1UL<<2) 
    #define PSMCU_DCM_SYNC_DCM_EN       (1UL<<1) 
    #define PSMCU_DCM_SYNC_FORCE_ON     (1UL<<1) 
#define L1BUS_DCM_CTRL0          (MDGLOBAL_DCM_BASE + 0x0018UL)
    #define L1BUS_DCM_FORCE_OFF         (1UL<<31) //force DCM clock_out = off
    #define L1BUS_DCM_PLL_SWICH_CKEN    (1UL<<28)
    #define L1BUS_DCM_DBC_CNT(x)        (((x)&0x7F)<<20)
    #define L1BUS_DCM_IDLE_FSEL(x)      (((x)&0x1F)<<12)
    #define L1BUS_DCM_NORMAL_FSEL(x)    (((x)&0x1F)<<4)
    #define L1BUS_DCM_DBC_EN            (1UL<<2)
    #define L1BUS_DCM_EN                (1UL<<1)
    #define L1BUS_DCM_FORCE_ON          (1UL<<0) //force DCM clock_out == DCM clock_in
#define L1BUS_DCM_CTRL1          (MDGLOBAL_DCM_BASE + 0x001CUL)
    #define L1BUS_DCM_SYNC_SETTING      (1UL<<5) 
    #define L1BUS_DCM_SYNC_IDLE_FSEL    (1UL<<4) 
    #define L1BUS_DCM_SYNC_NORMAL_SEL   (1UL<<3) 
    #define L1BUS_DCM_SYNC_DBC_EN       (1UL<<2) 
    #define L1BUS_DCM_SYNC_DCM_EN       (1UL<<1) 
    #define L1BUS_DCM_SYNC_FORCE_ON     (1UL<<0) 
#define ARM7_DCM_CTRL0           (MDGLOBAL_DCM_BASE + 0x0020UL)
#define ARM7_DCM_CTRL1           (MDGLOBAL_DCM_BASE + 0x0024UL)
#define L1MCU_DCM_CTRL0          (MDGLOBAL_DCM_BASE + 0x0028UL)
    #define L1MCU_DCM_FORCE_OFF         (1UL<<31) //force DCM clock_out = off
    #define L1MCU_DCM_PLL_SWICH_CKEN    (1UL<<28)
    #define L1MCU_DCM_DBC_CNT(x)        (((x)&0x7F)<<20)
    #define L1MCU_DCM_IDLE_FSEL(x)      (((x)&0x1F)<<12)
    #define L1MCU_DCM_NORMAL_FSEL(x)    (((x)&0x1F)<<4)
    #define L1MCU_DCM_DBC_EN            (1UL<<2)
    #define L1MCU_DCM_EN                (1UL<<1)
    #define L1MCU_DCM_FORCE_ON          (1UL<<0) //force DCM clock_out == DCM clock_in
#define L1MCU_DCM_CTRL1          (MDGLOBAL_DCM_BASE + 0x002CUL)
    #define L1MCU_DCM_SYNC_SETTING      (1UL<<5) 
    #define L1MCU_DCM_SYNC_IDLE_FSEL    (1UL<<4) 
    #define L1MCU_DCM_SYNC_NORMAL_SEL   (1UL<<3) 
    #define L1MCU_DCM_SYNC_DBC_EN       (1UL<<2) 
    #define L1MCU_DCM_SYNC_DCM_EN       (1UL<<1) 
    #define L1MCU_DCM_SYNC_FORCE_ON     (1UL<<1) 

#define PSMCU_DCM_MASK           (MDGLOBAL_DCM_BASE + 0x0040UL)
#define L1BUS_DCM_MASK           (MDGLOBAL_DCM_BASE + 0x0044UL)
#define ARM7_DCM_MASK            (MDGLOBAL_DCM_BASE + 0x0048UL)
#define L1MCU_DCM_MASK           (MDGLOBAL_DCM_BASE + 0x004CUL)

/* L1 LPM: Low Power Monitor for SM/DCM */
#define L1DCM_LPM_CTRL           (MDGLOBAL_DCM_BASE + 0x0080UL)
#define L1DCM_LPM_STS0           (MDGLOBAL_DCM_BASE + 0x0088UL)
#define L1DCM_LPM_STS1           (MDGLOBAL_DCM_BASE + 0x008CUL)
#define L1DCM_LPM_STS2           (MDGLOBAL_DCM_BASE + 0x0090UL)
#define L1DCM_LPM_STS3           (MDGLOBAL_DCM_BASE + 0x0094UL)
#define L1DCM_LPM_STS4           (MDGLOBAL_DCM_BASE + 0x0098UL)
#define L1DCM_LPM_STS5           (MDGLOBAL_DCM_BASE + 0x009CUL)

/* LPM: Read status via register */
#define DCM_STS0                 (MDGLOBAL_DCM_BASE + 0x0100UL)
#define DCM_STS1                 (MDGLOBAL_DCM_BASE + 0x0104UL)
#define DCM_STS2                 (MDGLOBAL_DCM_BASE + 0x0108UL)
#define DCM_STS3                 (MDGLOBAL_DCM_BASE + 0x010CUL)

/* CHIP Config, for AP status check, TK6291 Only */
#define DCM_CHIP_CONFIG0         (MDGLOBAL_DCM_BASE + 0x0800UL)
#define DCM_CHIP_CONFIG1         (MDGLOBAL_DCM_BASE + 0x0804UL)

/* OTHERS */
#define DCM_MDTOP_DUMMY          (MDGLOBAL_DCM_BASE + 0x1000UL)
#define DCM_MDTOP_STATUS         (MDGLOBAL_DCM_BASE + 0x1004UL)

/* MD SYS L2DCM definition */
#define MDSYS_L2DCM_CODA         (MDSYS_L2DCM_BASE + 0x0000UL)
#define MDSYS_L2DCM_SHR_SETCTL   (MDSYS_L2DCM_BASE + 0x0004UL)
    #define MDSYS_L2DCM_BUS_PLL_SWITCH         (1UL<<16) /* (Notify bit) 1:clock source from PLL, 0:clock source from 26Mhz */
    #define MDSYS_L2DCM_HSBUS_FREQ_SEL_HALF    (0UL<<15)
    #define MDSYS_L2DCM_HSBUS_FREQ_SEL_QUARTER (1UL<<15)
    #define MDSYS_L2DCM_SAME_SLOW_FREQ         (1UL<<14)
    #define MDSYS_L2DCM_HFBUS_SLOW_FSEL(x)     (((x)&0x1F)<<8)
    #define MDSYS_L2DCM_HFBUS_NORMAL_FSEL(x)   (((x)&0x1F)<<0)
#define MDSYS_L2DCM_LTEL2_BUS    (MDSYS_L2DCM_BASE + 0x0010UL)
#define MDSYS_L2DCM_MDDMA_BUS    (MDSYS_L2DCM_BASE + 0x0014UL)
#define MDSYS_L2DCM_MDREG_BUS    (MDSYS_L2DCM_BASE + 0x0018UL)
#define MDSYS_L2DCM_MODULE_BUS2X (MDSYS_L2DCM_BASE + 0x001CUL)
#define MDSYS_L2DCM_MODULE_BUS1X (MDSYS_L2DCM_BASE + 0x0020UL)

#define MDSYS_HSPAL2_CKEN        (MDSYS_L2DCM_BASE + 0x0040UL)
#define MDSYS_MDINFRA_CKEN       (MDSYS_L2DCM_BASE + 0x0044UL)
    #define MDSYS_MDINFRA_DCM_AHBM_EN         (1UL<<31)
    #define MDSYS_MDINFRA_DCM_AHBS_EN         (1UL<<30)
    #define MDSYS_MDINFRA_SOE_CKEN            (1UL<<4)
    #define MDSYS_MDINFRA_BUS_REC_CKEN        (1UL<<3)
    #define MDSYS_MDINFRA_BUS_MON_CKEN        (1UL<<2)
    #define MDSYS_MDINFRA_BUS_UART2_CKEN      (1UL<<1)
    #define MDSYS_MDINFRA_BUS_UART1_CKEN      (1UL<<0)

#define MDSYS_MDPERI_CKEN        (MDSYS_L2DCM_BASE + 0x0048UL)
    #define MDSYS_MDPERI_DCM_DBGSYS_EN        (1UL<<31)
    #define MDSYS_MDPERI_TRACE_CKEN           (1UL<<17)
    #define MDSYS_MDPERI_MISCREG_CKEN         (1UL<<16)
    #define MDSYS_MDPERI_PCCIF_CKEN           (1UL<<15)
    #define MDSYS_MDPERI_MDEINT_CKEN          (1UL<<14)
    #define MDSYS_MDPERI_MDCFGCTL_CKEN        (1UL<<13)
    #define MDSYS_MDPERI_MDREG_CKEN           (1UL<<12)
    #define MDSYS_MDPERI_A7OST_CKEN           (1UL<<11)
    #define MDSYS_MDPERI_MDOST_CKEN           (1UL<<10)
    #define MDSYS_MDPERI_MDTOPSM_CKEN         (1UL<<9)
    #define MDSYS_MDPERI_MDCIRQ_CKEN          (1UL<<8)
    #define MDSYS_MDPERI_MDECT_CKEN           (1UL<<7)
    #define MDSYS_MDPERI_USIM2_CKEN           (1UL<<6)
    #define MDSYS_MDPERI_USIM1_CKEN           (1UL<<5)
    #define MDSYS_MDPERI_GPTLITE_CKEN         (1UL<<4)
    #define MDSYS_MDPERI_MDGPTM_CKEN          (1UL<<3)
    #define MDSYS_MDPERI_I2C_CKEN             (1UL<<2)
    #define MDSYS_MDPERI_GDMA_CKEN            (1UL<<1)
    #define MDSYS_MDPERI_UART0_CKEN           (1UL<<0)
#define MDSYS_ARM7_CKEN          (MDSYS_L2DCM_BASE + 0x004CUL)

#define MDSYS_L2DCM_HSPAL2_MASK  (MDSYS_L2DCM_BASE + 0x0060UL)
#define MDSYS_L2DCM_MDINFRA_MASK (MDSYS_L2DCM_BASE + 0x0064UL)
#define MDSYS_L2DCM_MDPERI_MASK  (MDSYS_L2DCM_BASE + 0x0068UL)
    #define MDSYS_L2DCM_MDPERIM_MDDBGSYS      (1UL<<31)
    #define MDSYS_L2DCM_MDPERIM_TRACE         (1UL<<17)
    #define MDSYS_L2DCM_MDPERIM_MISCREG       (1UL<<16)
    #define MDSYS_L2DCM_MDPERIM_MDPCCIF       (1UL<<15)
    #define MDSYS_L2DCM_MDPERIM_MDPCCIF       (1UL<<15)
    #define MDSYS_L2DCM_MDPERIM_MDEINT        (1UL<<14)
    #define MDSYS_L2DCM_MDPERIM_MDCFG         (1UL<<13)
    #define MDSYS_L2DCM_MDPERIM_MDRGU         (1UL<<12)
    #define MDSYS_L2DCM_MDPERIM_ARM7OST       (1UL<<11)
    #define MDSYS_L2DCM_MDPERIM_MDOST         (1UL<<10)
    #define MDSYS_L2DCM_MDPERIM_TOPSM         (1UL<< 9)
    #define MDSYS_L2DCM_MDPERIM_USIM2         (1UL<< 6)
    #define MDSYS_L2DCM_MDPERIM_USIM1         (1UL<< 5)
    #define MDSYS_L2DCM_MDPERIM_GPTLITE       (1UL<< 4)
    #define MDSYS_L2DCM_MDPERIM_GPT           (1UL<< 3)
    #define MDSYS_L2DCM_MDPERIM_I2C           (1UL<< 2)
    #define MDSYS_L2DCM_MDPERIM_MDGDMA        (1UL<< 1)
    #define MDSYS_L2DCM_MDPERIM_UART0           (1UL<< 0)

#define MDSYS_CLKCTL_DUMMY   (MDSYS_L2DCM_BASE + 0x1000UL)
#define MDSYS_CLKCTL_STATUS  (MDSYS_L2DCM_BASE + 0x1004UL)

/* MDL1, L2DCM */
#define MDL1AO_CR4_INIT        (MDL1_L2DCM_BASE + 0x0108)
#define MDL1_L1MCU_L2DCM_CON   (MDL1_L2DCM_BASE + 0x0180)
#define MDL1_L1MCU_L2DCM_CON2  (MDL1_L2DCM_BASE + 0x0184)
#define MDL1_L1BUS_L2DCM_CON   (MDL1_L2DCM_BASE + 0x0188)
#define MDL1_L1BUS_L2DCM_CON3  (MDL1_L2DCM_BASE + 0x0198)
#define MDL1_L1MCU_PWR_AWARE   (MDL1_L2DCM_BASE + 0x0190)
#define MDL1_L1AO_PWR_AWARE    (MDL1_L2DCM_BASE + 0x0194)

/* L2 LPM: Low Power Monitor for L2 DCM */
#define L2DCM_LPM_CTRL           (MDSYS_L2DCM_BASE + 0x0080UL)
#define L2DCM_LPM_STS0           (MDSYS_L2DCM_BASE + 0x0088UL)
#define L2DCM_LPM_STS1           (MDSYS_L2DCM_BASE + 0x008CUL)
#define L2DCM_LPM_STS2           (MDSYS_L2DCM_BASE + 0x0090UL)
#define L2DCM_LPM_STS3           (MDSYS_L2DCM_BASE + 0x0094UL)
#define L2DCM_LPM_STS4           (MDSYS_L2DCM_BASE + 0x0098UL)
#define L2DCM_LPM_STS5           (MDSYS_L2DCM_BASE + 0x009CUL)

#define DCM_LPM_ENABLE 1
#undef  DCM_LPM_ENABLE

#endif /* DCM_ENABLE */

typedef enum {
    PLL_2G_TALKING = 0xFD00,
    PLL_3G_TALKING,
    PLL_VIDEO_PLAY
} pll_use_scenario_t;

extern kal_int32 arm_enter_standby_mode(kal_int32);

#endif /* end of __PCM_REG_H__ */
