#ifndef __DRV_RSTCTL_H__
#define __DRV_RSTCTL_H__

#include "kal_general_types.h"

#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)

/*Set wdt timeout interval as 4 sec(32768*4/512=0x100)*/
#define WDT_RSTINTERVAL_VALUE	(0x100)







typedef enum
{
	RST_TARGET_MIN=0,
	
	RST_MDGDMA,				//MDPERI:0
    RST_USIM1, 				//MDPERI:1
    RST_USIM2, 				//MDPERI:2
	RST_MDUART0,			//MDPERI:3
	RST_MDGPTM,				//MDPERI:4
	RST_MDMISC,				//MDPERI:5
	RST_MDCIRQ,				//MDPERI:6
	RST_I2C,				//MDPERI:7
	RST_MDDBGSYS,			//MDPERI:8
	RST_MDDBGSIB,			//MDPERI:9
	RST_GPIOMUX,			//MDPERI:10
	RST_MDTOPSM,			//MDPERI:11
	RST_MDOST,				//MDPERI:12
	RST_MDCFGCTL,			//MDPERI:13
	RST_MDECT,				//MDPERI:14  	!!NEW!!
	RST_MDECTDBG,			//MDPERI:15  	!!NEW!!
	RST_MDCLKBUS,			//MDPERI:17  	!!NEW!!
	RST_MDCLK,				//MDPERI:18 	!!NEW!!
	RST_TRACE,				//MDPERI:19   !!NEW!!
	RST_PSLITE_GPT, 		//MDPERI:20   !!NEW!!
	RST_ARM7_PCCIF, 		//MDPERI:21   !!NEW!!
	RST_L1SYS,				//MDPERI:24	!!NEW!!
	RST_ARM7_HRST,			//ARM7:0
	RST_ARM7_SRST,			//ARM7:1
	RST_ARM7_CIRQ,			//ARM7:3
	RST_ARM7SYS,			//= (RST_ARM7_HRST |RST_ARM7_SRST | RST_CIRQ)
	RST_MDINFRA_BUSMON,		//MDINFRA:0
	RST_MDINFRA_BOOTROM,	//MDINFRA:1
	RST_ABM,				//MDINFRA:2
	RST_MDUART1,			//MDINFRA:3
	RST_MDUART2, 			//MDINFRA:4
	RST_PSPERI, 			//MDINFRA:5
	RST_BUS_RECORD,			//MDINFRA:6
	RST_SOE,				//MDINFRA:7 (Security Offload Engine)
	RST_CR4_DBG,			//PSMCU: 0
	RST_CR4_NRESET,			//PSMCU: 1	
	RST_CR4_BUSMON,			//PSMCU: 2
	RST_PF,					//PSMCU: 4
	RST_PCMON_FIFO,			//PSMCU: 6
	RST_PCMON_REG,			//PSMCU: 7

	RST_L2COP, 				//LTEL2: 0 	
	RST_HSPAL2, 			//HSPAL2: 0
	
	RST_APMISC, 			//APPERI: 0
	RST_APGPTM, 			//APPERI: 1
	//RST_APTZCTL,			//APPERI: 2 (NO SW RESET)
	RST_APGPIO, 			//APPERI: 3
	RST_APUART0,			//APPERI: 4
	RST_SDCTL,				//APPERI: 5
	RST_APTOPSM, 			//APPERI: 6
	RST_APOST, 				//APPERI: 7
	RST_APDBGSYS,			//APPERI: 8
	RST_APDBGCV, 			//APPERI: 9
	RST_NLI_ARB, 			//APPERI: 10
	RST_APCFGCTL, 			//APPERI: 11
	RST_NFI_AO, 			//APPERI: 12
	RST_APECT,				//APPERI: 13
	RST_APECTDBG, 			//APPERI: 14
	RST_CLDMA_AO, 			//APPERI: 15
	RST_SEJ,				//APPERI: 16
	RST_APLED,				//APPERI: 17
	RST_PMIC, 				//APPERI: 18
	RST_PMICBUS,			//APPERI: 19
	RST_PTPOD,				//APPERI: 20
	RST_PTPODBUS,			//APPERI: 21 
	RST_SDCTL_CISCC, 		//APPERI: 22

	RST_EFUSE,				//TOPAO: 0
	RST_SSUSB_DIGPHY,		//TOPAO: 1
	RST_SSUSB_PHY,			//TOPAO: 2
	RST_APCLKBUS, 			//TOPAO: 7
	RST_APCLK,				//TOPAO: 8
	RST_AUXADC, 			//TOPAO: 9
	RST_DRAMC_AO,			//TOPAO: 20
	RST_EMI_AO, 			//TOPAO: 21
	RST_MEMMISC_AO, 		//TOPAO: 22

	RST_DRAMC, 				//MEMSYS: 0
	RST_EMI, 				//MEMSYS: 1
	RST_DDRPHY, 			//MEMSYS: 2
	RST_SRAMROM, 			//MEMSYS: 3
	RST_DDRBRIDGE, 			//MEMSYS: 4
	RST_TRFGEN, 			//MEMSYS: 5
	RST_MEMSYS, 			//(RST_DRAMC| RST_EMI| RST_DDRPHY | RST_DRAMC_A0 | RST_EMI_AO);

	RST_SSUSB,				//SSUSB: 0

	RST_NFI,				//APINFRA: 0
	RST_SPI,				//APINFRA: 1
	RST_USB,				//APINFRA: 2
	RST_IPSEC,				//APINFRA: 3
	RST_HIF0,				//APINFRA: 4
	RST_PFC,				//APINFRA: 5
	RST_MSDC0P,				//APINFRA: 6
	RST_APGDMA,				//APINFRA: 7
	RST_APINFRA_BUSMON, 	//APINFRA: 8
	RST_APUART1,			//APINFRA: 10
	RST_APUART2,			//APINFRA: 11
	RST_PCCIF0,				//APINFRA: 12
	RST_PCCIF1,				//APINFRA: 13
	RST_PCCIF2,				//APINFRA: 14
	RST_PCCIF3,				//APINFRA: 15
	RST_CLDMA,				//APINFRA: 16
	RST_RTC,				//APINFRA: 17
	RST_MSDC1P,				//APINFRA: 18
	RST_MSDC_C2K, 			//APINFRA: 19
	RST_TRNG, 				//APINFRA: 20
	RST_L12PS_RCCIF, 		//APINFRA: 21
	RST_PS2L1_RCCIF, 		//APINFRA: 22
	RST_L12MD2_RCCIF,		//APINFRA: 23
	RST_L12MD3_RCCIF,		//APINFRA: 24
	RST_MD22L1_RCCIF,		//APINFRA: 25
	RST_MD32L1_RCCIF,		//APINFRA: 26

	RST_CA7_DBG, 			//APMCU: 0
	RST_CA7_NRESET, 		//APMCU: 1
	RST_CA7_BUSMON, 		//APMCU: 2

	RST_MD1,				//PAR_AP: 2
	RST_AP_MD1, 			//PAR_AP: 3
	RST_MD2,				//PAR_AP: 4
	RST_AP_MD2, 			//PAR_AP: 5
	RST_C2K,				//PAR_AP: 6
	RST_AP_C2K, 			//PAR_AP: 7
	RST_C2K_ARM,			//PAR_AP: 8

	RST_BSI_ALL,
	RST_MDALL,
	RST_APALL,
	RST_MDALL_WO_SPI,
	RST_MDALL_WO_USB,
	RST_MDALL_WO_GPIO,
	RST_TARGET_MAX		/**< Maximum value of reset item : for correctness check */
} rst_target_e;


/*************************************************************************
* FUNCTION
*  drv_rstctl_sw_reset
*
* DESCRIPTION
*  This function is to do software reset 
*
* PARAMETERS
*    targetIP: the target IP that is defined in drv_rstctl.h will be software reset
*
* RETURN VALUES
*	none
*
*************************************************************************/


extern void drv_rstctl_sw_reset(rst_target_e targetIP);


/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_reset
*
* DESCRIPTION
*  This function is to do wdt reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void drv_rstctl_wdt_reset(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_abnReset
*
* DESCRIPTION
*  This function is used to do abnormal reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void drv_rstctl_wdt_abnReset(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableInterrupt
*
* DESCRIPTION
*  This function is used to on/off irq mode
*       reset or trigger interrupt while watchdog timout happening
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void drv_rstctl_wdt_enableInterrupt(kal_bool enable);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to get wd timer interval(uint:512*T(32k))
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
extern kal_uint16 drv_rstctl_wd_getInterval(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*   cntMaskToClear
*   SW_WDCNT_CLR: clear SW WD Cnt
*   HW_WDCNT_CLR: clear HW WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wd_clrCnt(kal_uint32 cntMaskToClear);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_setInterval
*
* DESCRIPTION
*  This function is used to set wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
extern void drv_rstctl_wdt_setInterval(kal_uint32 wdtInterval);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_kick
*
* DESCRIPTION
*  This function is used to retart wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_restartWDT(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_init
*
* DESCRIPTION
*  This function is to initialize the WDT module
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void drv_rstctl_wdt_init(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableDebugMode
*
* DESCRIPTION
*  This function is used to on/off debug mode
*
* PARAMETERS
*   enable
*   0: disable
*   1: enable
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wdt_enableDebugMode(kal_bool enable);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enable
*
* DESCRIPTION
*  This function is used to on/off wd timer
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
extern void drv_rstctl_wdt_enable(kal_bool en);


#else
#error Not support rstctrl in this chip type

#endif /*TK6291*/


kal_uint32 Get_WATCHDOG_BASE(void);

kal_uint32 Get_WATCHDOG_RESTART_CMD(void);

kal_bool Is_WDT_Init(void);

/*nucleus schedule for WDT restart******************************************/
extern const kal_uint32 g_WATCHDOG_RESTART_REG;
extern const kal_uint32 g_WATCHDOG_RESTART_VALUE;
extern const kal_uint32 g_ABNORMAL_RST_REG;
extern const kal_uint32 g_ABNORMAL_RST_VAL;

#endif /* end of __DRV_RSTCLT_H__ */

