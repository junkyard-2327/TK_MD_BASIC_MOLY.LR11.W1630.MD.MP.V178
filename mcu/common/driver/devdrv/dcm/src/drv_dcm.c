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
 *   drv_dcm.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * Barry Hong
 *
 *
 * ==========================================================================
 * $Log$
 *
 * 09 26 2016 linson.du
 * [MOLY00204576] [1630MP] MD PTP feature
 * 	
 * 	Porting for PTP.
 *
 * 04 08 2016 chao-kai.yu
 * [MOLY00169528] [1603MP][Olympus] PTP build error fix
 * .turn off ptp in MT6757 and update PCore garbage solution
 *
 * 03 16 2016 chao-kai.yu
 * [MOLY00169528] [1603MP][Olympus] PTP build error fix
 * .ptp build error fix
 *
 * 11 25 2015 chin-chieh.hung
 * [MOLY00145065] Update 6291 series DCM flow
 * roolback modemL1 bus DCM function
 *
 * 10 29 2015 chin-chieh.hung
 * [MOLY00145065] Update 6291 series DCM flow
 * add ASM enable/disable in WFI/DCM flow
 *
 * 10 23 2015 chin-chieh.hung
 * [MOLY00146481] [MT6755][Jade-L1][MP1][MTBF][Lab][HQ][Ericsson] (MCU_PCORE)[ASSERT] file:common/driver/devdrv/dcm/src/drv_dcm.c line:674
 * move OSTD_CheckSleep function out of timing check period
 *
 * 10 15 2015 chin-chieh.hung
 * [MOLY00145078] [System Service] domain setting for everest on L1MCU
 * fix special load build failed
 *
 * 10 15 2015 chin-chieh.hung
 * [MOLY00145065] Update 6291 series DCM flow
 * add sw spin lock flow for ARM7 DCM
 *
 * 10 14 2015 chin-chieh.hung
 * [MOLY00145065] Update 6291 series DCM flow
 * fix basic load build failed
 *
 * 10 14 2015 chin-chieh.hung
 * [MOLY00145065] Update 6291 series DCM flow
 * add OSTD check API without IRQ mask; set L1MCU DCM by l1core
 *
 * 10 12 2015 chin-chieh.hung
 * [MOLY00144627] ELT trace for TPPA+MET
 * add TPPA support
 *
 * 09 17 2015 chin-chieh.hung
 * [MOLY00142187] [Need Patch] LR11 build error for MT6797_SP(LWCTG_FULL_VER) [L1CORE]
 * fix everest build error
 *
 * 09 11 2015 chin-chieh.hung
 * [MOLY00141489] [Jade][Driver][DCM/Dormant] Add DDRen SW force on control and related debug info
 * add dormant/dcm debug log
 *
 * 09 11 2015 chin-chieh.hung
 * [MOLY00141489] [Jade][Driver][DCM/Dormant] Add DDRen SW force on control and related debug info
 * add dormant dcm debug log
 *
 * 09 09 2015 chin-chieh.hung
 * [MOLY00141079] [WW FT][MT6755][Jade-L1][MP1][Italy-Rome][TRE][TIM][ASSERT] file:pcore/service/hif/ccci/src/ccci_debug.c line:533
 * update DCM setting and add IRQ mask for shared register access
 *
 * 08 25 2015 chin-chieh.hung
 * [MOLY00137586] [Jade] PTP driver IT Porting
 * add ptpot funciton call
 *
 * 08 19 2015 chin-chieh.hung
 * [MOLY00138002] [Jade] Update sleepLock/enterWFI flow
 * update enter WFI flow
 *
 * 07 22 2015 chin-chieh.hung
 * [MOLY00121469] Update for Jade/TK6291 platform driver
 * add EMM log
 *
 * 07 22 2015 chin-chieh.hung
 * [MOLY00121469] Update for Jade/TK6291 platform driver
 * update dcm driver for Jade
 *
 * 02 11 2014 chin-chieh.hung
 * [MOLY00053645] Add MT6595 DCM driver
 * remove static attribute for drvtest
 *
 * 02 10 2014 chin-chieh.hung
 * [MOLY00053645] Add MT6595 DCM driver
 * add dcm/dormant debug information in CCCI mechanism
 *
 * 01 15 2014 chin-chieh.hung
 * [MOLY00053874] Add ROME dormant function
 * Add ROME dormant function
 *
 * 01 14 2014 chin-chieh.hung
 * [MOLY00053645] Add MT6595 DCM driver
 * Merging
 *      
 *     //MOLY_CBr/chin-chieh.hung/MT6595E1_BRING_UP_DEV_W1402p7/mcu/driver/devdrv/dcm/inc/drv_dcm.h
 *      
 *     to //MOLY/TRUNK/MOLY/mcu/driver/devdrv/dcm/inc/drv_dcm.h
 *
 * 12 27 2013 chin-chieh.hung
 * [MOLY00051700] [Driver] MT6290E2 EMI HW issue workaround
 * Fix MT6290E2 EMI HW issue
 *
 * 12 12 2013 chin-chieh.hung
 * [MOLY00045704] Init MT6595 common driver
 * Add DCM flow
 *
 * 11 25 2013 chin-chieh.hung
 * [MOLY00047490] [Driver] DCM and Dormant Driver Maintain
 * DCM code re-arch
 *
 * 11 13 2013 barry.hong
 * [MOLY00036412] [MT6290][Driver] Remove dummy dma include
 * .
 *
 * 11 07 2013 alvin.chen
 * [MOLY00043940] [MT6290E1][WWFT][HK][MM][CMHK][Sleep Enable][Clock Control][Assert] errc_comm.c 1906 assert in sleep mode overnight test
 * Patch for OSTD interrupt disabpear issue
 *
 * 10 25 2013 alvin.chen
 * [MOLY00043719] [MT6290][MDTOPSM] Patch for Phone Field trial activity
 * Integration change.
 *
 * 09 16 2013 barry.hong
 * [MOLY00036412] [MT6290][Driver] Remove dummy dma include
 * .
 *
 * 08 27 2013 barry.hong
 * [MOLY00035415] 6290 DCM driver remove unused variable
 * remove unused variable
 *
 * 08 02 2013 barry.hong
 * [MOLY00032203] update dummy_fdma for GDMA sleep ack issue
 * user updated dummy_fdma API (need CL:219427)
 *
 * 07 26 2013 barry.hong
 * [MOLY00030921] [MT6290]Low Power Feature patch back from CBr
 * Low Power Feature patch back from CBr
 *
 * 07 22 2013 barry.hong
 * [MOLY00027330] [ARM7toMOLY] ARM7 Build/SYSGEN/Functions Update to TRUNK
 * .update DCM driver
 *
 * 03 28 2013 barry.hong
 * [MOLY00012680] 6290 DCM driver for sleep mode porting
 * .add fakeAPI enter_PLL_save_mode/leave_PLL_save_mode
 *
 * 03 28 2013 barry.hong
 * [MOLY00012680] 6290 DCM driver for sleep mode porting
 * .remove unused code and modify TCM section declare
 *
 * 03 28 2013 barry.hong
 * [MOLY00012680] 6290 DCM driver for sleep mode porting
 * .Sync DCM function to MOLY 6290 for sleep flow
 *
 * 03 08 2013 barry.hong
 * [MOLY00011608] MT6290 MOLY fake API remove
 * .remove fakeAPI
 ****************************************************************************/
#ifdef __MTK_TARGET__

#include "kal_public_api.h"
#include "kal_internal_api.h" /* Sleep_Time structure definition, kal sleep check related function */
#include "reg_base.h"
#include "intrCtrl.h"         /* IRQ Mask/Unmask */
#include "drv_dcm.h"
#include "devdrv_ls.h"
#include "peterson_lock.h"


#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
#include "ostd_public.h"
#endif

#include "SST_sla.h"
#include "SST_intrCtrl.h"
#include "system_trc.h"
#include "sleepdrv_interface.h"
#include "drv_asm.h" 

#include "ex_mem_manager.h"

#if defined(__L1CORE__) && defined(__MTK_TARGET__)
#include "ptp_public.h"
#endif

/* DCM Debug */
#define L1_LOCKSLEEP 0 /* disable sleep/dormant */
#define PS_LOCKSLEEP 0
#define L1_LOCKWFI 0   /* not call WFI, all dormant/DCM are disabled */
#define PS_LOCKWFI 0
#define L1_LOCKDCM 0   /* DCM disabled */
#define PS_LOCKDCM 0

/*
 * NoteXXX: SaveAndSetIRQMask()/RestoreIRQMask() are APIs for appilcations to disable/restore
 *          IRQ. They will restrict the disable duration. But idle task disables IRQ for a
 *          time due to DCM. Thus LockIRQ()/RestoreIRQ() are used here. Only the idle task
 *          can use them!! Other applications are not allowed to use LockIRQ()/RestoreIRQ().
 */
extern kal_uint32 LockIRQ(void);
extern void RestoreIRQ(kal_uint32);
extern void dormant_mode_activate(void);
extern void dormant_mode_init(void);
DEVDRV_LS_INTSRAM_RW volatile static kal_bool OST_ReadyToSlept = KAL_FALSE;
DEVDRV_LS_INTSRAM_RW volatile kal_uint32 standby_acc_usc = 0;
kal_bool enterWFI = KAL_FALSE; //TBC

#if defined(__HIF_PCCIF_ARM7_SUPPORT__)
static petersonslock_t *p_lock;
extern kal_uint32 pccif_dcm_memory(void);
#endif /* __HIF_PCCIF_ARM7_SUPPORT__ */

//#if defined(__PCORE__)
//DEVDRV_LS_INTSRAM_ZI volatile kal_uint32 dcm_swEnableDDRenOn_start_frc;
//DEVDRV_LS_INTSRAM_ZI volatile kal_uint32 dcm_swEnableDDRenOn_end_frc;
//DEVDRV_LS_INTSRAM_ZI volatile kal_uint32 dcm_swEnableDDRenOff_start_frc;
//DEVDRV_LS_INTSRAM_ZI volatile kal_uint32 dcm_swEnableDDRenOff_end_frc;
//#endif /* __PCORE__ */
DEVDRV_LS_INTSRAM_ZI volatile kal_uint32 dcm_asmSave_start_frc;
DEVDRV_LS_INTSRAM_ZI volatile kal_uint32 dcm_asmSave_end_frc;
DEVDRV_LS_INTSRAM_ZI volatile kal_uint32 dcm_asmRestore_start_frc;
DEVDRV_LS_INTSRAM_ZI volatile kal_uint32 dcm_asmRestore_end_frc;

#if 1 /* Remove old series macro definition for SW workaround */
    #define LP_HWBUG_PATCH_START()
    #define LP_HWBUG_PATCH_END()
#endif /* 1 */

#if defined(__MCU_DORMANT_MODE__)
    #define IFDEF_DORMANT(def_statement, undef_statement) def_statement
#else  /* __MCU_DORMANT_MODE__ */
    #define IFDEF_DORMANT(def_statement, undef_statement) undef_statement
#endif /* __MCU_DORMANT_MODE__ */

#if defined(__L1CORE__)
    #define IFDEF_L1CORE(def_statement, undef_statement) def_statement
#else /* !__L1CORE__ ==PCORE */
    #define IFDEF_L1CORE(def_statement, undef_statement) undef_statement
#endif /* __L1CORE__ */

#if defined( DCM_ENABLE )
    #define IFDEF_DCM(def_statement, undef_statement) def_statement
#else  /* DCM_ENABLE */
    #define IFDEF_DCM(def_statement, undef_statement) undef_statement
#endif /* DCM_ENABLE */

#if defined( __HIF_PCCIF_ARM7_SUPPORT__ )
    #define IFDEF_PCCIF_ARM7(def_statement, undef_statement) def_statement
#else  /* __HIF_PCCIF_ARM7_SUPPORT__ */
    #define IFDEF_PCCIF_ARM7(def_statement, undef_statement) undef_statement
#endif /* __HIF_PCCIF_ARM7_SUPPORT__ */

#if defined(MT6290) && defined(__ARM7EJ_S__)
    #define IFDEF_MDCOPRO(def_statement, undef_statement) def_statement
#else  /* MT6290 && __ARM7EJ_S__ */
    #define IFDEF_MDCOPRO(def_statement, undef_statement) undef_statement
#endif /* MT6290 && __ARM7EJ_S__ */

#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
    #define LOWPWER_ENTER_PAUSE_MODE
#endif

#if defined(__PRODUCTION_RELEASE__)
    #define IFDEF_PRODUCTION(x)
#else  /* __PRODUCTION_RELEASE__ */
/* under construction !*/
#endif /* __PRODUCTION_RELEASE__ */

#define PCORE_LOCK_ID 0

#if defined( DCM_ENABLE )

extern void lpm_init(void);

static struct 
{
    kal_uint32 enterWFI;
    kal_uint32 enterDCM;
    kal_uint32 enterSleep;
    kal_uint32 dcmDisable;                    /* Default not disable DCM */
    kal_uint32 stepFRC[8];
    kal_uint8  dcmHandleCount;
   
    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    kal_bool OST_ReadyToSlept;
    Sleep_Time allow_sleep_dur;
    #endif
} dcm_cb DEVDRV_LS_INTSRAM_ZI; 
 
static void _dcm_allon(void);
static void _dcm_alloff(void);
void _dcm_hw_top_mcu_dcm(int on);

//volatile static kal_bool dcm_executed DEVDRV_LS_INTSRAM_RW = KAL_FALSE;

/* Query the MDMCU DCM Status
 * When the MDMCU is running, the DCM is off.
 * If the MDMCU is enter DCM mode, the MDMCU clock is gated.
 */
kal_bool DCM_Query_Status(void)
{
//   kal_bool status = dcm_executed;
//   dcm_executed = KAL_FALSE;/* Restored to default state */
//   return status;
    IFDEF_DCM(return KAL_TRUE, return KAL_FALSE);
} 

kal_uint32 dcm_disable_caller[32];

kal_uint8 DCM_GetHandle( void )
{    
   ASSERT(dcm_cb.dcmHandleCount<32);
   return dcm_cb.dcmHandleCount++;   /* Using handle number from 0, not 1 */
}



void DCM_Enable( kal_uint8 handle )
{   
   kal_uint32 _savedMask;
   
   ASSERT(handle < 32);
   _savedMask = SaveAndSetIRQMask();
   dcm_cb.dcmDisable &= ~(1 << handle);   

   if(0 == dcm_cb.dcmDisable)
   {
       dcm_disable_caller[handle] = 0;
       _dcm_allon();
   }
   RestoreIRQMask(_savedMask);
}

void DCM_Disable( kal_uint8 handle )
{
   kal_uint32 _savedMask;
   kal_uint32 caller;
   GET_RETURN_ADDRESS(caller);

   ASSERT(handle < 32);
   dcm_disable_caller[handle] = caller;
   
   _savedMask = SaveAndSetIRQMask();
   dcm_cb.dcmDisable |= (1 << handle);

   _dcm_alloff();

   RestoreIRQMask(_savedMask);
}

static void _dcm_allon(void)
{
    kal_uint32 _savedMask;

  if(dcm_cb.enterDCM){
  #if defined(__L1CORE__)
    //set by AP @ 26Mhz
    //MDL1_L1MCU_PWR_AWARE |= 1<<16
    //MDL1_L1AO_PWR_AWARE |= 1<<16;
    //MDL1_L1BUS_L2DCM_CON3 = 0x0000_FDE7 //L2DCM L1BUS
    //MDL1_L1BUS_L2DCM_CON3 = 0x1000_FDE7 //L2DCM L1BUS

    //MDL1_L1MCU_L2DCM_CON  = 0x0001_FDE7 //L2DCM L1MCU
    //MDL1_L1MCU_L2DCM_CON2 = 0x0000_0000
    //MDL1_L1MCU_L2DCM_CON2 = 0x8000_0000


    #if (PS_LOCKDCM == 0)
    while( (DRV_Reg32(MDSYS_L2DCM_MODULE_BUS1X) & 1) == 0 )    {;}
    #endif /* end of PS_LOCKDCM == 0*/

    /* For modemL1 bus DCM */
    _savedMask = SaveAndSetIRQMask();
    //DRV_ClrReg32(MDL1_L1MCU_PWR_AWARE, 1UL<<16); //0xF60F0190
    //DRV_ClrReg32(MDL1_L1AO_PWR_AWARE, 1UL<<16);  //0xF60F0194

    /* For L1MCU DCM */
    DRV_SetReg32(MDL1AO_CR4_INIT, 1UL<<31);      //0xF60F0108, cr4_init_confg_ao
    DRV_SetReg32(MDL1_L1MCU_PWR_AWARE, 1UL<<8);  //0xF60F0190
    RestoreIRQMask(_savedMask);

    //Toggle L1MCU DCM Setting
    DRV_WriteReg32(MDL1_L1MCU_L2DCM_CON, 0x0001FDE7); //0xF60F0180
    DRV_ClrReg32(MDL1_L1MCU_L2DCM_CON2, 1UL<<31); //0xF60F0184
    DRV_SetReg32(MDL1_L1MCU_L2DCM_CON2, 1UL<<31); //0xF60F0184

  #else /* __L1CORE__ */
    kal_uint32 toggle_temp;

    /* PSMCU init setting */
    DRV_WriteReg32(PSMCU_DCM_CTRL0, PSMCU_DCM_DBC_CNT(0xF)     | \
                                    PSMCU_DCM_IDLE_FSEL(0x1F)  | /* Divisor = 0x## + 1 = 32 */ \
                                    PSMCU_DCM_NORMAL_FSEL(0x0) | \
                                    PSMCU_DCM_DBC_EN           | \
                                    PSMCU_DCM_EN               );
    /* Apply PSMCU setting */
    toggle_temp = (DRV_Reg32(PSMCU_DCM_CTRL1)&PSMCU_DCM_SYNC_SETTING) ^ PSMCU_DCM_SYNC_SETTING;
    DRV_WriteReg32(PSMCU_DCM_CTRL1, toggle_temp               | \
                                    PSMCU_DCM_SYNC_IDLE_FSEL  | \
                                    PSMCU_DCM_SYNC_NORMAL_SEL | \
                                    PSMCU_DCM_SYNC_DBC_EN     | \
                                    PSMCU_DCM_SYNC_DCM_EN     | \
                                    PSMCU_DCM_SYNC_FORCE_ON   );

    /* L1MCU init setting */
    DRV_WriteReg32(L1MCU_DCM_CTRL0, L1MCU_DCM_DBC_CNT(0xF)     | \
                                    L1MCU_DCM_IDLE_FSEL(0x3)   | /* Divisor = 0x## + 1 = 4 */ \
                                    L1MCU_DCM_NORMAL_FSEL(0x0) | \
                                    L1MCU_DCM_DBC_EN           | \
                                    L1MCU_DCM_EN               );
    /* Apply L1MCU setting */
    toggle_temp = (DRV_Reg32(L1MCU_DCM_CTRL1)&L1MCU_DCM_SYNC_SETTING) ^ L1MCU_DCM_SYNC_SETTING;
    DRV_WriteReg32(L1MCU_DCM_CTRL1, toggle_temp               | \
                                    L1MCU_DCM_SYNC_IDLE_FSEL  | \
                                    L1MCU_DCM_SYNC_NORMAL_SEL | \
                                    L1MCU_DCM_SYNC_DBC_EN     | \
                                    L1MCU_DCM_SYNC_DCM_EN     | \
                                    L1MCU_DCM_SYNC_FORCE_ON   );


    /* L1BUS init setting */
    DRV_WriteReg32(L1BUS_DCM_CTRL0, L1BUS_DCM_DBC_CNT(0xF)     | \
                                    L1BUS_DCM_IDLE_FSEL(0x0)  | \
                                    L1BUS_DCM_NORMAL_FSEL(0x0) | \
                                    L1BUS_DCM_DBC_EN/*         | \
                                    L1BUS_DCM_EN */            );
    /* L1BUS enable */
    toggle_temp = (DRV_Reg32(L1BUS_DCM_CTRL1)&L1BUS_DCM_SYNC_SETTING) ^ L1BUS_DCM_SYNC_SETTING;
    DRV_WriteReg32(L1BUS_DCM_CTRL1, toggle_temp               | \
                                    L1BUS_DCM_SYNC_IDLE_FSEL  | \
                                    L1BUS_DCM_SYNC_NORMAL_SEL | \
                                    L1BUS_DCM_SYNC_DBC_EN     | \
                                    L1BUS_DCM_SYNC_DCM_EN     | \
                                    L1BUS_DCM_SYNC_FORCE_ON   );

    /* L2 DCM Control */
    /* shared L2DCM setting, limited: TOPSM clock should higher than 26Mhz */
    DRV_WriteReg32(MDSYS_L2DCM_SHR_SETCTL, MDSYS_L2DCM_BUS_PLL_SWITCH         | \
                                           MDSYS_L2DCM_SAME_SLOW_FREQ         |  \
                                           MDSYS_L2DCM_HFBUS_SLOW_FSEL(0x4)   | /* 0x4 for divide 4 */ \
                                           MDSYS_L2DCM_HFBUS_NORMAL_FSEL(0x10)    /* 0x10 for divide 1 */);
    _savedMask = SaveAndSetIRQMask();
    DRV_SetReg32(MDSYS_MDINFRA_CKEN, MDSYS_MDINFRA_DCM_AHBM_EN | MDSYS_MDINFRA_DCM_AHBS_EN);
    DRV_SetReg32(MDSYS_MDPERI_CKEN, MDSYS_MDPERI_DCM_DBGSYS_EN);
    RestoreIRQMask(_savedMask);


#if 0 /* do not mask the setting */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /** L2 DCM Enable **/
    DRV_SetReg32(MDSYS_L2DCM_LTEL2_BUS, 1);
    DRV_SetReg32(MDSYS_L2DCM_MDDMA_BUS, 1);
    DRV_SetReg32(MDSYS_L2DCM_MDREG_BUS, 1);
    DRV_SetReg32(MDSYS_L2DCM_MODULE_BUS2X, 3);
    DRV_ClrReg32(MDSYS_CLKCTL_DUMMY, 0x18); //clear bit3, bit4
    DRV_SetReg32(MDSYS_L2DCM_MODULE_BUS1X, 3);
  #endif /* __L1CORE__ */
  } /* end of dcm_cb.enterDCM */
}

static void _dcm_alloff(void)
{
  #if defined(__L1CORE__)
    /* modemL1 bus DCM */
    DRV_SetReg32(MDL1_L1MCU_PWR_AWARE, 1UL<<16);
    DRV_SetReg32(MDL1_L1AO_PWR_AWARE, 1UL<<16);

    /* L1MCU DCM */
    DRV_WriteReg32(MDL1_L1MCU_L2DCM_CON, 0x000FF927); //L2DCM L1MCU, offset:0x180

    //Toggle L1MCU DCM Setting
    DRV_ClrReg32(MDL1_L1MCU_L2DCM_CON2, 1UL<<31); //0xF60F0184
    DRV_SetReg32(MDL1_L1MCU_L2DCM_CON2, 1UL<<31); //0xF60F0184

  #else /* __L1CORE__ */
    kal_uint32 toggle_temp;
    /* PSMCU init setting */
    DRV_WriteReg32(PSMCU_DCM_CTRL0, PSMCU_DCM_DBC_CNT(0xF)     | \
                                    PSMCU_DCM_IDLE_FSEL(0x1F)  | \
                                    PSMCU_DCM_NORMAL_FSEL(0x0) | \
                                    PSMCU_DCM_DBC_EN/*           | \
                                    PSMCU_DCM_EN               */);
    /* Apply PSMCU setting */
    toggle_temp = (DRV_Reg32(PSMCU_DCM_CTRL1)&PSMCU_DCM_SYNC_SETTING) ^ PSMCU_DCM_SYNC_SETTING;
    DRV_WriteReg32(PSMCU_DCM_CTRL1, toggle_temp               | \
                                    PSMCU_DCM_SYNC_IDLE_FSEL  | \
                                    PSMCU_DCM_SYNC_NORMAL_SEL | \
                                    PSMCU_DCM_SYNC_DBC_EN     | \
                                    PSMCU_DCM_SYNC_DCM_EN     | \
                                    PSMCU_DCM_SYNC_FORCE_ON   );

    /* L1BUS init setting */
    DRV_WriteReg32(L1BUS_DCM_CTRL0, L1BUS_DCM_DBC_CNT(0xF)     | \
                                    L1BUS_DCM_IDLE_FSEL(0x1F)  | \
                                    L1BUS_DCM_NORMAL_FSEL(0x0) | \
                                    L1BUS_DCM_DBC_EN/*           | \
                                    L1BUS_DCM_EN               */);
    /* L1BUS enable */
    toggle_temp = (DRV_Reg32(L1BUS_DCM_CTRL1)&L1BUS_DCM_SYNC_SETTING) ^ L1BUS_DCM_SYNC_SETTING;
    DRV_WriteReg32(L1BUS_DCM_CTRL1, toggle_temp               | \
                                    L1BUS_DCM_SYNC_IDLE_FSEL  | \
                                    L1BUS_DCM_SYNC_NORMAL_SEL | \
                                    L1BUS_DCM_SYNC_DBC_EN     | \
                                    L1BUS_DCM_SYNC_DCM_EN     | \
                                    L1BUS_DCM_SYNC_FORCE_ON   );

    /* L2 DCM Control */
    /* shared L2DCM setting */
    DRV_WriteReg32(MDSYS_L2DCM_SHR_SETCTL, MDSYS_L2DCM_BUS_PLL_SWITCH         | \
                                           MDSYS_L2DCM_HSBUS_FREQ_SEL_HALF    | \
                                           MDSYS_L2DCM_SAME_SLOW_FREQ         | \
                                           MDSYS_L2DCM_HFBUS_SLOW_FSEL(0x10)   | /* 0x0 for divide 32 */ \
                                           MDSYS_L2DCM_HFBUS_NORMAL_FSEL(0x10)    /* 0x10 for divide 1 */);
    DRV_ClrReg32(MDSYS_MDINFRA_CKEN, MDSYS_MDINFRA_DCM_AHBM_EN | MDSYS_MDINFRA_DCM_AHBS_EN);
    DRV_ClrReg32(MDSYS_MDPERI_CKEN, MDSYS_MDPERI_DCM_DBGSYS_EN);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /** L2 DCM Disable **/
    DRV_ClrReg32(MDSYS_L2DCM_LTEL2_BUS, 1);
    DRV_ClrReg32(MDSYS_L2DCM_MDDMA_BUS, 1);
    DRV_ClrReg32(MDSYS_L2DCM_MDREG_BUS, 1);
    DRV_ClrReg32(MDSYS_L2DCM_MODULE_BUS2X, 1);
    DRV_ClrReg32(MDSYS_L2DCM_MODULE_BUS1X, 3);
  #endif /* __L1CORE__ */
}

#else /*!defined(DCM_ENABLE)*/

kal_bool DCM_Query_Status(void)
{
    return KAL_FALSE;
}
kal_uint8 DCM_GetHandle( void )
{
    return 0;
}

void DCM_Enable( kal_uint8 handle ) {}
void DCM_Disable( kal_uint8 handle ) {}

#endif /*!defined(DCM_ENABLE)*/

void DCM_Init( void )
{
    IFDEF_DORMANT(dormant_mode_init(), );

#if defined( DCM_ENABLE )
    #if (defined(__L1CORE__)&&L1_LOCKWFI==1) || (defined(__PCORE__)&&PS_LOCKWFI==1)
    dcm_cb.enterWFI = 0;
    #else
    dcm_cb.enterWFI = 1;
    #endif
    
    #if (defined(__L1CORE__)&&L1_LOCKSLEEP==1) || (defined(__PCORE__)&&PS_LOCKSLEEP==1)
    dcm_cb.enterSleep = 0;
    #else
    dcm_cb.enterSleep = 1;
    #endif
    
    #if (defined(__L1CORE__)&&L1_LOCKDCM==1) || (defined(__PCORE__)&&PS_LOCKDCM==1)
    dcm_cb.enterDCM = 0;
    #else
    dcm_cb.enterDCM = 1;
    #endif

    _dcm_allon();
    #if defined(__MTK_INTERNAL__) && defined (DCM_LPM_ENABLE)
    lpm_init();
    #endif //__MTK_INTERNAL__
#else

#endif /* DCM_ENABLE */
}

void DCM_PreInit(void)
{
#if defined(__HIF_PCCIF_ARM7_SUPPORT__)
    p_lock = (petersonslock_t *)pccif_dcm_memory();//SO type memory
    p_lock_init(p_lock);
#endif /* __HIF_PCCIF_ARM7_SUPPORT__ */
}

#if defined( DCM_ENABLE )
#if defined(__PCORE__)
static void drv_dcm_psmcu(int on)
{
    kal_uint32 _savedMask, toggle_temp;
    _savedMask = SaveAndSetIRQMask();
    if(0 == on)
    {
        /* PSMCU init setting */
        DRV_WriteReg32(PSMCU_DCM_CTRL0, PSMCU_DCM_DBC_CNT(0xF)     | \
                                        PSMCU_DCM_IDLE_FSEL(0x1F)  | \
                                        PSMCU_DCM_NORMAL_FSEL(0x0) | \
                                        PSMCU_DCM_DBC_EN/*           | \
                                        PSMCU_DCM_EN               */);
    }
    else
    {
        /* PSMCU init setting */
        DRV_WriteReg32(PSMCU_DCM_CTRL0, PSMCU_DCM_DBC_CNT(0xF)     | \
                                        PSMCU_DCM_IDLE_FSEL(0x1F)  | \
                                        PSMCU_DCM_NORMAL_FSEL(0x0) | \
                                        PSMCU_DCM_DBC_EN           | \
                                        PSMCU_DCM_EN               );
    }
    /* Apply PSMCU setting */
    toggle_temp = (DRV_Reg32(PSMCU_DCM_CTRL1)&PSMCU_DCM_SYNC_SETTING) ^ PSMCU_DCM_SYNC_SETTING;
    DRV_WriteReg32(PSMCU_DCM_CTRL1, toggle_temp               | \
                                    PSMCU_DCM_SYNC_IDLE_FSEL  | \
                                    PSMCU_DCM_SYNC_NORMAL_SEL | \
                                    PSMCU_DCM_SYNC_DBC_EN     | \
                                    PSMCU_DCM_SYNC_DCM_EN     | \
                                    PSMCU_DCM_SYNC_FORCE_ON   );
    RestoreIRQMask(_savedMask);
}
static kal_bool drv_dcm_mask4modulel1(int mask)
{
    kal_uint32 _savedMask;
    kal_bool result = KAL_TRUE;
    _savedMask = SaveAndSetIRQMask();
#if defined(__HIF_PCCIF_ARM7_SUPPORT__)
    result = p_lock_acquire(p_lock, PCORE_LOCK_ID, 20);
#endif /* IFDEF_PCCIF_ARM7 */

    if(KAL_TRUE == result)
    {
        if(0 != mask)
        {
            DRV_SetReg32_NPW(MDSYS_L2DCM_MDPERI_MASK,  \
                MDSYS_L2DCM_MDPERIM_MDRGU | \
                /*MDSYS_L2DCM_MDPERIM_ARM7OST | this should be lock by ARM7 */
                MDSYS_L2DCM_MDPERIM_MDOST |\
                MDSYS_L2DCM_MDPERIM_TOPSM);
        }
        else
        {
            DRV_ClrReg32_NPW(MDSYS_L2DCM_MDPERI_MASK,  \
                MDSYS_L2DCM_MDPERIM_MDRGU | \
                /*MDSYS_L2DCM_MDPERIM_ARM7OST | this should be lock by ARM7 */
                MDSYS_L2DCM_MDPERIM_MDOST |\
                MDSYS_L2DCM_MDPERIM_TOPSM);
        }
#if defined(__HIF_PCCIF_ARM7_SUPPORT__)
        p_lock_release(p_lock, PCORE_LOCK_ID);
#endif /* IFDEF_PCCIF_ARM7 */
    }

    RestoreIRQMask(_savedMask);
    return result;
}
#else /* __PCORE__ */
static kal_bool drv_dcm_mask4modulel1(int mask)
{
    return KAL_FALSE;
}
#endif /* __PCORE__ */

void _dcm_hw_top_mcu_dcm(int on)
{    
#if defined(__PCORE__)
    drv_dcm_psmcu(on);
#else  /* __PCORE__ */
#endif /* __PCORE__ */
}
#endif /* DCM_ENABLE */


IFDEF_MDCOPRO(DEVDRV_LS_COPRO_INTSRAM_ROCODE, DEVDRV_LS_INTSRAM_ROCODE)
void DCM_Handler( void )
{
    kal_uint32 _savedMask;
    kal_uint32 standby_start_usc = 0, standby_end_usc = 0;
    /* Partial sleep mode for MCU and AVB block.
       To force MCU and AVB bus CLK stopped when system is in idle task.
       System will run again and CLK resume automatically only when IRQ comes.
    */

#if defined( DCM_ENABLE )
    volatile kal_uint32 usc;
    IFDEF_PRODUCTION(register kal_uint32 start);
    IFDEF_PRODUCTION(register kal_uint32 end);
    IFDEF_PRODUCTION(register kal_uint32 duration);
    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    kal_uint32 swLockSleep, validSleepTime;
    kal_get_sleep_time(&dcm_cb.allow_sleep_dur);
    #endif /* LOWPWER_ENTER_PAUSE_MODE */
    kal_bool result;

    IFDEF_L1CORE(OSTD_CheckSleepWithInterruptEn(), );
    _savedMask = LockIRQ();
    IFDEF_PRODUCTION(start = ust_get_current_time());

    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    /* Enable nIRQ wake-up event after I-Bit OFF. */
    dcm_cb.stepFRC[0] = ust_get_current_time();
    IFDEF_MDCOPRO(, OSTD_EnableNIRQ());
    dcm_cb.stepFRC[1] = ust_get_current_time();
    swLockSleep = OSTD_CheckIsSleepLock(); /* If the sleep is lock, try pure WFI directly to avoid the FRC/Frame Counter Mismatch Error */
    dcm_cb.stepFRC[2] = ust_get_current_time();
    validSleepTime = kal_is_valid_sleep_time( &dcm_cb.allow_sleep_dur );
    dcm_cb.stepFRC[3] = ust_get_current_time();


    if ( (dcm_cb.enterSleep==0) /* Force disable sleep */ || ( swLockSleep ) || (validSleepTime  == 0 ) )
    {
        dcm_cb.OST_ReadyToSlept = OST_ReadyToSlept = KAL_FALSE;
    }
    else
    {
        /* check if IRQ is disabled for more than 60 qbits */
        #if !defined(__PRODUCTION_RELEASE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* !__PRODUCTION_RELEASE__ */
        /* Check & Trigger OST Pause Mode:
             MUST be called inside of I-Bit protection:
             No need to check return value while DCM disabled. */
        dcm_cb.stepFRC[4] = ust_get_current_time();
        dcm_cb.OST_ReadyToSlept = OST_ReadyToSlept = OSTD_CheckSleep();
        dcm_cb.stepFRC[5] = ust_get_current_time();
    }
    #endif /* LOWPWER_ENTER_PAUSE_MODE */
    if ( (OST_ReadyToSlept == KAL_FALSE) && (dcm_cb.dcmDisable == 0) )
    {
        /* System will not enter pause mode, 
           CPU enter pure WFI mode, dormant is not necessary 
           Only DCM enabled, CPU clock is gated */

        usc = ust_get_current_time();
        EMM_WriteDbgInfo(EMM_IDLE_TASK_DCM_ENTER, (void*)&usc);
        standby_start_usc = ust_get_current_time();

        if( dcm_cb.enterWFI )
        {

            dcm_asmSave_start_frc = ust_get_current_time();
            MALMO_ASM_DcmSave();
            dcm_asmSave_end_frc = ust_get_current_time();
            
//#if defined(__PCORE__)
//            dcm_swEnableDDRenOn_start_frc = ust_get_current_time();
//            DRV_ClrReg32(0xF0060404, 1UL<<17); //ToBeRemoved, for debugging
//            dcm_swEnableDDRenOn_end_frc = ust_get_current_time();
//#endif /* __PCORE__ */
            result = drv_dcm_mask4modulel1(1);
            arm_enter_standby_mode(0);
            if(KAL_TRUE == result)
            {
                result = drv_dcm_mask4modulel1(0);
                ASSERT(KAL_TRUE == result);
            }
//#if defined(__PCORE__)
//            dcm_swEnableDDRenOff_start_frc = ust_get_current_time_source();
//            DRV_SetReg32(0xF0060404, 1UL<<17); //ToBeRemoved, for debugging
//            dcm_swEnableDDRenOff_end_frc = ust_get_current_time_source();
//#endif /* __PCORE__ */

            dcm_asmRestore_start_frc = ust_get_current_time();
            MALMO_ASM_DcmRestore();
            dcm_asmRestore_end_frc = ust_get_current_time();

        }
                // read from TOPSM FRC because FMA need 2T 26M to sync FRC value if enabling DCM.
        standby_end_usc = usc = ust_get_current_time_source();
        EMM_WriteDbgInfo(EMM_IDLE_TASK_DCM_LEAVE, (void*)&usc);
    }
    else
    {
        volatile kal_uint32 usc, type, OST_InfiniteSlept;
        OST_InfiniteSlept = OSTD_Infinite_Sleep_Query();
        type = (KAL_TRUE == OST_ReadyToSlept) ? EMM_IDLE_TASK_SLEEP_ENTER : EMM_IDLE_TASK_WFI_ENTER;
        usc = ust_get_current_time();
        if (KAL_TRUE == OST_InfiniteSlept)
            EMM_WriteDbgInfo(EMM_INFINITESLEEP_WFI, (void*)&usc);
        else
            EMM_WriteDbgInfo(type, (void*)&usc);
        if(KAL_TRUE == OST_ReadyToSlept)
        {

            #if defined(__L1CORE__) && defined(__MTK_TARGET__)
            ptp_sleep();
            #endif
            /* workaround: to disable TOP MDMCU DCM to push "axi_sleep_protect ready".
             * TOP MDMCU DCM will gating mcu_clock that are referenced by AXI_Sleep_Protect, 
             * which will lost protect ready while WFI for entering sleep.
             */
            _dcm_hw_top_mcu_dcm(0);
            standby_start_usc = ust_get_current_time();
            IFDEF_DORMANT(dormant_mode_activate(), arm_enter_standby_mode(0));
            standby_end_usc = ust_get_current_time();
            _dcm_hw_top_mcu_dcm(1);

            #if defined(__L1CORE__) && defined(__MTK_TARGET__)
            ptp_wake();
            #endif
            #if defined(LOWPWER_ENTER_PAUSE_MODE) && defined(__PCORE__)
            OSTD_CheckAfnUfn2TriggerISR();
            #endif /* MT6290 && LOWPWER_ENTER_PAUSE_MODE */
        }
        else
        {
            standby_start_usc = ust_get_current_time();
            result = drv_dcm_mask4modulel1(1);
            arm_enter_standby_mode(0);
            if(KAL_TRUE == result)
            {
                result = drv_dcm_mask4modulel1(0);
                ASSERT(KAL_TRUE == result);
            }
            standby_end_usc = ust_get_current_time();
        }
        usc = ust_get_current_time();
        type = (type == EMM_IDLE_TASK_SLEEP_ENTER) ? EMM_IDLE_TASK_SLEEP_LEAVE : EMM_IDLE_TASK_WFI_LEAVE;
        EMM_WriteDbgInfo(type, (void*)&usc);
    }

    standby_acc_usc += ust_us_duration(standby_start_usc, standby_end_usc);


    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    /* Disable nIRQ wake-up event before I-Bit ON. */
    IFDEF_MDCOPRO(, OSTD_DisableNIRQ());
    #endif /* LOWPWER_ENTER_PAUSE_MODE */
    RestoreIRQ(_savedMask);

#else //DCM_ENABLE
    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    Sleep_Time allow_sleep_dur;

    kal_get_sleep_time(&allow_sleep_dur);
    IFDEF_L1CORE(OSTD_CheckSleepWithInterruptEn(), );
    #endif /* LOWPWER_ENTER_PAUSE_MODE */

    _savedMask = LockIRQ();

    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    /* Enable nIRQ wake-up event after I-Bit OFF. */
    IFDEF_MDCOPRO(, OSTD_EnableNIRQ());
    /* Get confirm */
    if( kal_is_valid_sleep_time( &allow_sleep_dur ) == 0 )
    {
        /* Disable nIRQ wake-up event before I-Bit ON. */
        IFDEF_MDCOPRO(, OSTD_DisableNIRQ());
        RestoreIRQ(_savedMask);
        return;
    }
    /* Check & Trigger OST Pause Mode:
         MUST be called inside of I-Bit protection:
         No need to check return value while DCM disabled. */
    OST_ReadyToSlept = OSTD_CheckSleep();
    #endif /* LOWPWER_ENTER_PAUSE_MODE */

//    if(WFI_Handle_Count == 0 )
    {

        if( (KAL_TRUE == OST_ReadyToSlept))
        {
            #if defined(__L1CORE__) && defined(__MTK_TARGET__)
            ptp_sleep();
            #endif 
            /* System will enter pause mode, 
               CPU enter dormant if dormant feature is turn on.
               Otherwise, just call WFI.
             */
            LP_HWBUG_PATCH_START();
            standby_start_usc = ust_get_current_time();
            IFDEF_DORMANT(dormant_mode_activate(), arm_enter_standby_mode(0));
            standby_end_usc = ust_get_current_time_source();
            LP_HWBUG_PATCH_END();
            
            #if defined(__L1CORE__) && defined(__MTK_TARGET__)
            ptp_wake();
            #endif              
            #if defined(LOWPWER_ENTER_PAUSE_MODE) && defined(__PCORE__)
            OSTD_CheckAfnUfn2TriggerISR();
            #endif /* MT6290 && LOWPWER_ENTER_PAUSE_MODE */
        }
        else
        {
            /* System will not enter pause mode, 
               CPU enter pure WFI mode, dormant is not necessary */
            LP_HWBUG_PATCH_START();

            dcm_asmSave_start_frc = ust_get_current_time();
            MALMO_ASM_DcmSave();
            dcm_asmSave_end_frc = ust_get_current_time();

//#if defined(__PCORE__)
//            dcm_swEnableDDRenOn_start_frc = ust_get_current_time();
//            DRV_ClrReg32(0xF0060404, 1UL<<17); //ToBeRemoved, for debugging
//            dcm_swEnableDDRenOn_end_frc = ust_get_current_time();
//#endif /* __PCORE__ */
            standby_start_usc = ust_get_current_time();
            arm_enter_standby_mode(0);
            standby_end_usc = ust_get_current_time_source();
//#if defined(__PCORE__)
//            dcm_swEnableDDRenOff_start_frc = ust_get_current_time_source();
//            DRV_SetReg32(0xF0060404, 1UL<<17); //ToBeRemoved, for debugging
//            dcm_swEnableDDRenOff_end_frc = ust_get_current_time_source();
//#endif /* __PCORE__ */

            dcm_asmRestore_start_frc = ust_get_current_time();
          	MALMO_ASM_DcmRestore();
            dcm_asmRestore_end_frc = ust_get_current_time();

            LP_HWBUG_PATCH_END();
        }

    }

    standby_acc_usc += ust_us_duration(standby_start_usc, standby_end_usc);
    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    /* Disable nIRQ wake-up event before I-Bit ON. */
    IFDEF_MDCOPRO(, OSTD_DisableNIRQ());
    #endif /* LOWPWER_ENTER_PAUSE_MODE */
    RestoreIRQ(_savedMask);

#endif /* defined(DCM_ENABLE)*/
}


#endif /* __MTK_TARGET__ */ 
