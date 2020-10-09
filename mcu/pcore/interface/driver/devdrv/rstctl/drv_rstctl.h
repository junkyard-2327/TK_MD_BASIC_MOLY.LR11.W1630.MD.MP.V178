#ifndef __DRV_RSTCTL_H__
#define __DRV_RSTCTL_H__

#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)

/*Set wdt timeout interval as 4 sec(32768*4=0x20000)*/
/*System default value is 16 secs (32768*16) = 0x80000*/
/*Reason to change this vlaue: to distinguish system is WDT reset or simply reboot*/
#define WDT_RSTINTERVAL_VALUE	(0x20000)


/*For RGU framework purpose. */

typedef enum{
    UT_REPORT_FAIL = -1,
    UT_REPORT_PASS = 0,
    UT_REPORT_NA
}UT_REPORT_STATUS;


typedef UT_REPORT_STATUS (*ut_testcase_fn_ptr)(kal_uint32 flags, void *param);


typedef struct
{
    ut_testcase_fn_ptr _main_fn;
    kal_uint32         flags;
    void               *para;
	kal_char           *description;
	kal_char           *testplan_section;
}ut_testcase_struct;





typedef enum
{
 	APSYS = 8, 
	MD1SYS = 4, 
	ARM7SYS = 2, 
	L1SYS = 1
}subsystem_e; 

/*For software  reset purpose. */
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
	RST_TARGET_MAX,		/**< Maximum value of reset item : for correctness check */
	RST_NULL				//Used in drv_UT_within_RGU_framework. Some IPs do not tolerate software while programe is running. 
} rst_target_e;

typedef enum
{
	WDT_RESET,
	WDT_IRQ_ONLY,
} wdt_irq_e;

typedef struct rstctl_ext_cfg_s {
	kal_bool	EXT_RST_EA;
	kal_bool	MD_POL;
	kal_bool	PAD_OUT_EA;
} rstctl_ext_cfg_t;


typedef enum
{
    RST_A7_LOCK = 0,
    RST_A7_UNLOCK = 1,
}rst_a7_lock_e;


/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/
void drv_rstctl_sw_wd_reset(kal_uint32 wdTarget);

void drv_rstctl_sw_reset(rst_target_e targetIP);


/*************************************************************************
* FUNCTION
*  pcore_isr_l1wdt_handler
*
* DESCRIPTION
*  This function is used to handle L1WDT. Called by dcl_wdt_hisr
*  
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void pcore_isr_l1wdt_handler(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_init_l1wdt_status
*
* DESCRIPTION
*  Because L1WDT interval is not long enough, some cases might encounter unexpected 
*  L1WDT IRQ ISR after long loding time. To prevent long loading time that triggers unexptected L1WDt IRQ. 
*  We add this function to clear L1WDT STS and clear This function is only used for dcl_wdt_register_lisr. 
*  NOTE:L1_LV_EN is enabled @ drv_rstctl_wdt_init as well. 
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern void drv_rstctl_init_l1wdt_status(void);

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
extern kal_uint32 drv_rstctl_wd_getInterval(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
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
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wdt_enableDebugMode(kal_bool enable);

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



/*************************************************************************
* FUNCTION
*  drv_rstctl_A7_unlock
*
* DESCRIPTION
*  This function is used to unlock ARM7 hrst
*
* PARAMETERS
*	lock:   RST_A7_LOCK:
*            RST_A7_UNLOCK:
*
* RETURN VALUES
*	none
*
*************************************************************************/

extern void drv_rstctl_A7_unlock(rst_a7_lock_e lock);

/*************************************************************************
* FUNCTION
*  drv_rstctl_whole_system_reset
*
* DESCRIPTION
*  This function is used to trigger whole system reset. 
*
* PARAMETERS
*	delay_cycles:  the number 1T32K cycles
*
* RETURN VALUES
*	none
*
*************************************************************************/
extern	void drv_rstctl_whole_system_reset(kal_uint32 delay_cycles);


/*************************************************************************
* FUNCTION
*  drv_rstctl_disable_all_WDTs
*
* DESCRIPTION
*  This function is used to disable all WDTs (APRGU, MDRGU, L1RGU, ARM7RGU)
* 
*
* PARAMETERS
*   None. 
*
* RETURN VALUES
*	KAL_TRUE: SUCCESSFULY disable all WDTs. 
*	KAL_FALSE: FAIL to disable all WDTs.  
*
* NOTE
*************************************************************************/
extern kal_bool drv_rstctl_disable_all_WDTs(void); 


/*************************************************************************
* FUNCTION
*  drv_UT_within_RGU_framework
*
* DESCRIPTION
*  This function is used to offer a framework to call UTs after creating scenarios of different reset scopes. 
* 
*
* PARAMETERS
*    rst_target_e  targetIP: IP name defined in the header file: drv_rstctl.h
*	subsystem_e target_system: Indicate the system that will run the UTs. (APSYS, MD1SYS, L1SYS, ARM7SYS)
*	subsystem_e system_coverage: Indicate the system coverage you expect to create the secenarios for test. 
*	ut_testcase_struct *testcase_ptr: This is a functional pointer array including the pointers to the UTs. 
*	kal_uint32 test_items: Tell the framework the number of UTs you expect this framework to call. 
*	kal_uint32 delay_cycles: Tell the  framework the number of 32K cycles framework to proceed the reset. 
*
* RETURN VALUES
*	UT_REPROT_PASS: If all the UT test results are pass. 
*	UT_REPORT_FAIL: If on of the UT test result is fail. 
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
extern UT_REPORT_STATUS drv_UT_within_RGU_framework(rst_target_e targetIP, subsystem_e target_system, subsystem_e system_coverage,
													   ut_testcase_struct *testcase_ptr, kal_uint32 test_items, kal_uint32 delay_cycles);

/*************************************************************************
* FUNCTION
*  drv_rstctl_apwd_clrCnt used in drvtest for USB whole system reset. 
*
* DESCRIPTION
*  This function is used to clear both SW WD Cnt and HW WD Cnt 
*
* PARAMETERS
*	void 
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_apwd_clrCnt(void);




//#if 0 /*Remove for not using*/
//#elif (defined(MT6290)||defined(TK6291))
#elif defined(MT6290)

#if defined(MT6290)
/*Set wdt timeout interval as 4 sec(32768*4=0x20000)*/
#define WDT_RSTINTERVAL_VALUE	(0x20000)
#endif

typedef enum
{
	RST_TARGET_MIN=0,
	RST_SDCTL,
	RST_MDGDMA,
	RST_USIM0,
	RST_USIM1,
	RST_MDUART,
	RST_SUART0,
	RST_SUART1,
	RST_MDGPTM,
	RST_MDMISC,
	RST_MDCIRQ,
	RST_LED,
	RST_I2C,
	RST_SDCTL_CIS,
	RST_DBGSYS,
	RST_DBGCV,
	RST_DBGSIB,
	RST_GPIOMUX,
	RST_APTOPSM,
	RST_MDTOPSM,
	RST_APOST,
	RST_MDOST,
	RST_MDCFGCTL,
	RST_DRAMC_AO,
	RST_EMI_AO,
	RST_ARM7_HRST,
	RST_ARM7_SRST,
	RST_ARM7SYS,
	RST_CAIF,
	RST_L2COP,
	RST_MEMSYS,
	RST_MDINFRA_MISC,
	RST_MDINFRA_BUSMON,
	RST_MDINFRA_BOOTROM,
	RST_ABM,
	RST_CR4,
	RST_CR4_NRESET,
	RST_CR4_BUSMON,
	RST_ALC,
	RST_PF,
	RST_PCMON_FIFO,
	RST_PCMON_REG,
	RST_AP_RSTMD,
	RST_MDCLK,
	RST_APCLK,
	RST_EFUSE,
	RST_MML1,
	RST_MML1OFF,
	RST_TDD,
	RST_2G3G,
	RST_2G3G_DSP,
	RST_EXT_RST,
	RST_BSICTL,
	RST_RFIC1_BSISPI,
	RST_RFIC2_BSISPI,
	RST_PMIC_BSISPI,
	RST_MIPI0_BSISPI,
	RST_MIPI1_BSISPI,
	RST_BSI_ALL,
	RST_IDC,
	RST_MML1_BPICTRL,
	RST_MML1_PERISYS_MISC,
	RST_MML1_PERI_MBIST_CONFIG,
	RST_AUXADC,
	RST_MML1_PERISYS_XRESET,
	RST_MIXEDSYS,
	RST_SSUSB,
	RST_APUART,
	RST_APCCIF,
	RST_CLDMA,
	RST_NFI,
	RST_SPI,
	RST_USB,
	RST_IPSEC,
	RST_HIF0,
	RST_PFC,
	RST_NLI,
	RST_MSDC0P,
	RST_MSDC1P,
	RST_APGPTM,
	RST_APGDMA,
	RST_APINFRA_BUSMON,
	RST_AP_MISC,
	RST_APTZCTL,
	RST_ETHER_NIC,
	RST_TRACE,
	RST_CA7_DBG,
	RST_CA7_NRESET,
	RST_CA7_BUSMON,
	RST_MDALL,
	RST_APALL,
	RST_MDALL_WO_SPI,
	RST_MDALL_WO_USB,
	RST_TARGET_MAX		/**< Maximum value of reset item : for correctness check */
} rst_target_e;

typedef enum
{
	WDT_RESET,
	WDT_IRQ_ONLY,
} wdt_irq_e;


//definition for WDT status
#define MD_HWDT		(1 << 0)
#define MD_SWDT		(1 << 1)
#define AP_HWDT		(1 << 2)
#define AP_SWDT 	(1 << 3)
#define AP_SWR		(1 << 4)
#define MD_WDT_CNT_MASK		(0xF << 8)
#define AP_WDT_CNT_MASK		(0xF << 12)

typedef struct rstctl_ext_cfg_s {
	kal_bool	EXT_RST_EA;
	kal_bool	MD_POL;
	kal_bool	PAD_OUT_EA;
} rstctl_ext_cfg_t;

/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/
void drv_rstctl_sw_wd_reset(kal_uint32 wdTarget);
void drv_rstctl_wd_reset(wdt_irq_e irq_en, rst_target_e wdTarget, kal_uint32 wdtInterval);
void drv_rstctl_wd_disable(void);
void drv_rstctl_sw_reset(rst_target_e targetIP);

#if defined(MT6290)
kal_uint16 drv_rstctl_wd_getInterval(void);
#endif

void drv_rstctl_restartWDT(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_getSta
*
* DESCRIPTION
*  This function is used to get wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*  bit[15:12]:AP WDT CNT : AP wd reset increase one. can be reset by disable WDT
*  bit[11:8]:MD WDT CNT : MD wd reset increase one. can be reset by disable WDT
*  bit[4]:AP reset MD indicator
*  bit[3]:AP sw WD reset indicator
*  bit[2]:AP hw WD reset indicator
*  bit[1]:MD sw WD reset indicator
*  bit[0]:MD hw WD reset indicator
*************************************************************************/
#if defined(MT6290)
kal_uint32 drv_rstctl_wd_getSta(void);
#endif
/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrCnt(kal_uint32 cntMaskToClear);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to clear wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrSta(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_extrst_setCfg
*
* DESCRIPTION
*  This function is used to config EXT_RST
*
* PARAMETERS
*	rstctl_ext_cfg_t ext_cfg
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_extrst_setCfg(rstctl_ext_cfg_t ext_cfg);

/*************************************************************************
* FUNCTION
*  drv_rstctl_extrst_getSta
*
* DESCRIPTION
*  This function is used to get EXT_RST status
*
* PARAMETERS
*	none
* RETURN VALUES
*	1: ext rst assert
*	0: ext rst de-assert

*************************************************************************/
kal_bool drv_rstctl_extrst_getSta(void);


//for DCL driver
void drv_rstctl_wdt_setInterval(kal_uint32 wdtInterval);
void drv_rstctl_wdt_enable(kal_bool en);
void drv_rstctl_wdt_enableInterrupt(kal_bool enable);
void drv_rstctl_wdt_enableDebugMode(kal_bool enable);
void drv_rstctl_wdt_init(void);
void drv_rstctl_wdt_reset(void);
void drv_rstctl_wdt_abnReset(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_rst_set_bitmap
*
* DESCRIPTION
*  This function is used to set WD reset bit map for USB suspend
*
* PARAMETERS
*	none
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_rst_set_bitmap(kal_uint8 type);


/*******************************************/
#elif defined(MT6595)

/*Set wdt timeout interval as 4 sec(32768*4/512=0x100)*/
#define WDT_RSTINTERVAL_VALUE	(0x100)

typedef enum
{
	WDT_RESET,
	WDT_IRQ_ONLY,
} wdt_irq_e;

typedef enum
{
    RST_A7_DEASSERT = 0,
    RST_A7_ASSERT = 1,
}rst_a7_asrt_e;

typedef enum
{
    RST_A7_LOCK = 0,
    RST_A7_UNLOCK = 1,
}rst_a7_lock_e;

/*For easy implementation, move these two definition from rstctl_reg.h*/
/*REG_WDT_MD_STA*/
#define RSTCTL_STA_WDT_BIT             (15)
#define RSTCTL_STA_SW_WDT_BIT          (14)

#define MD_HWDT		(0x1 << RSTCTL_STA_WDT_BIT)
#define MD_SWDT		(0x1 << RSTCTL_STA_SW_WDT_BIT)

typedef enum
{
	RST_MD_SWRST = 0,
	RST_2GDSP,
	RST_CLDMA,
	RST_PCMON_REG,
	RST_PCMON_FIFO,
	RST_L2COP,
	RST_CAIF,
	RST_ARM7_SRST,
	RST_ARM7_HRST,
	RST_ARM7SYS,
	RST_MML1STS,
	RST_MML1_PERISYS_XRESET,
	RST_MML1_PERI_MBIST_CONFIG,
	RST_MML1_PERISYS_MISC,
	RST_MML1_BPICTRL,
	RST_IDC,
	RST_MIPI1_BSISPI,
	RST_MIPI0_BSISPI,
	RST_PMIC_BSISPI,
    RST_RFIC2_BSISPI,
	RST_RFIC1_BSISPI,
	RST_PF_BSICTRL,
	RST_TARGET_MAX,		/**< Maximum value of reset item : for correctness check */

    /*Following is for backward compatible*/
    RST_MDALL,

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}rst_target_e;


typedef enum
{
    WDT_RETN_FLAG_0 = (0x1 << 0),
    WDT_RETN_FLAG_1 = (0x1 << 1),
    WDT_RETN_FLAG_2 = (0x1 << 2),
    WDT_RETN_FLAG_3 = (0x1 << 3),
    WDT_RETN_FLAG_4 = (0x1 << 4),
    WDT_RETN_FLAG_5 = (0x1 << 5),
    WDT_RETN_FLAG_6 = (0x1 << 6),
    WDT_RETN_FLAG_7 = (0x1 << 7),
    WDT_RETN_FLAG_ALL = 0xFF,
}rst_retn_flag_e;

/*************************************************************************
* FUNCTION
*  drv_rstctl_ws_wdReset
*
* DESCRIPTION
*  This function is used to control top rgu to make whole system reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_ws_wdReset(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_top_retn_data
*
* DESCRIPTION
*  This function is used to read/write retention data
*
* PARAMETERS
*	bRead: 1: read data
*           0: write data
*    pData:
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_top_retn_data(kal_bool bRead, kal_uint32 *pData);

/*************************************************************************
* FUNCTION
*  drv_rstctl_A7_unlock
*
* DESCRIPTION
*  This function is used to unlock ARM7 hrst
*
* PARAMETERS
*	lock:   RST_A7_LOCK:
*            RST_A7_UNLOCK:
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_A7_unlock(rst_a7_lock_e lock);

/*************************************************************************
* FUNCTION
*  drv_rstctl_sw_reset
*
* DESCRIPTION
*  This function is used to do SW ARM7 reset
*
* PARAMETERS
*	assert: 1: set reset assert
*            0: set reset de-assert
*    targetIP: only support RST_A7_CCIF/RST_A7_SRST/RST_A7_HRST/RST_A7_SYS
*
* RETURN VALUES
*	none
*
* NOTE: Please set assert at least one 32K cycle
*************************************************************************/
extern void drv_rstctl_sw_A7_reset(rst_a7_asrt_e asrt, rst_target_e targetIP);

/*************************************************************************
* FUNCTION
*  drv_rstctl_sw_reset
*
* DESCRIPTION
*  This function is used to do SW reset
*
* PARAMETERS
*	targetIP: sw module defined in RGU
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_sw_reset(rst_target_e targetIP);


/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_reset
*
* DESCRIPTION
*  This function is used to config wd timer and start
*
* PARAMETERS
*    irq_en: wd reset issued irq istead of reset
*    wdtInterval: watchdog timerout period, unit as 512*T32K=15.6ms
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wd_reset(wdt_irq_e irq_en, rst_target_e wdTarget, kal_uint32 wdtInterval);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_getSta
*
* DESCRIPTION
*  This function is used to get wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*    wdt_sta_e: no reset, sw reset, wd timer reset, sw and wd timer reset
*
*************************************************************************/
extern kal_uint32 drv_rstctl_wd_getSta(void);

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
extern void drv_rstctl_wd_kick(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to set retention flag
*
* PARAMETERS
*	flag: rst_retn_flag_e
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_retn_flag_set(rst_retn_flag_e flag);

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to get retention flag
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	retetion flag value
*************************************************************************/
extern kal_uint16 drv_rstctl_retn_flag_get(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to clear retention flag
*
* PARAMETERS
*	flag: rst_retn_flag_e
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_retn_flag_clr(rst_retn_flag_e flag);


/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_data
*
* DESCRIPTION
*  This function is used to read/write retention data
*
* PARAMETERS
*	bRead: 1: read data
*           0: write data
*    pData:
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_retn_data(kal_bool bRead, kal_uint32 *pData);

/*************************************************************************
*              Following is used by WDT DCL (Driver Common Layer)        *
*************************************************************************/

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_disable
*
* DESCRIPTION
*  This function is used to disable wd timer
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wd_disable(void);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to clear wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wd_clrSta(void);

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

/*Legacy part for DCL*/
/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wd_clrCnt(kal_uint32 cntMaskToClear);

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableDebugMode
*
* DESCRIPTION
*  This function is used to on/off debug mode
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
extern void drv_rstctl_wdt_enableDebugMode(kal_bool enable);

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

//#endif

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

