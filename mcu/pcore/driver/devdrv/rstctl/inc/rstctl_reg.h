#ifndef __RSTCTL_REG_H__
#define __RSTCTL_REG_H__

#include <reg_base.h>
#include <irqid.h>

#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)

/* Register Address Definition */
//1 MDRGU Registers
#define BASE_ADDR_MDRSTCTL	            (BASE_MADDR_MDRGU)

#define REG_MDRSTCTL_WDTCR              (BASE_ADDR_MDRSTCTL+0x0100)
#define REG_MDRSTCTL_WDTCR_L1           (BASE_ADDR_MDRSTCTL+0x0104)
#define REG_MDRSTCTL_WDTCR_ARM7         (BASE_ADDR_MDRSTCTL+0x0108)
#define REG_MDRSTCTL_WDTRR              (BASE_ADDR_MDRSTCTL+0x0110)
#define REG_MDRSTCTL_WDTER_MDPERI       (BASE_ADDR_MDRSTCTL+0x0114)
#define REG_MDRSTCTL_WDTER_PSMCU		(BASE_ADDR_MDRSTCTL+0x0118)
#define REG_MDRSTCTL_WDTER_MDINFRA		(BASE_ADDR_MDRSTCTL+0x011C)
#define REG_MDRSTCTL_WDTER_LTEL2		(BASE_ADDR_MDRSTCTL+0x0120)
#define REG_MDRSTCTL_WDTER_HSPAL2		(BASE_ADDR_MDRSTCTL+0x0124)
#define REG_MDRSTCTL_WDTER_ARM7			(BASE_ADDR_MDRSTCTL+0x0128)
#define REG_MDRSTCTL_WDTSR				(BASE_ADDR_MDRSTCTL+0x0134)
#define REG_MDRSTCTL_WDTSR_L1           (BASE_ADDR_MDRSTCTL+0x0138)
#define REG_MDRSTCTL_WDTSR_ARM7			(BASE_ADDR_MDRSTCTL+0x0140)
#define REG_MDRSTCTL_SRSTR_MDPERI       (BASE_ADDR_MDRSTCTL+0x0144)
#define REG_MDRSTCTL_SRSTR_PSMCU        (BASE_ADDR_MDRSTCTL+0x0148)
#define REG_MDRSTCTL_SRSTR_MDINFRA      (BASE_ADDR_MDRSTCTL+0x014C)
#define REG_MDRSTCTL_SRSTR_LTEL2        (BASE_ADDR_MDRSTCTL+0x0150)
#define REG_MDRSTCTL_SRSTR_HSPAL2       (BASE_ADDR_MDRSTCTL+0x0154)
#define REG_MDRSTCTL_SRSTR_ARM7         (BASE_ADDR_MDRSTCTL+0x0158)
#define REG_MDRSTCTL_RESET_UNLOCK       (BASE_ADDR_MDRSTCTL+0x0168)
#define REG_MDRSTCTL_DUMMY              (BASE_ADDR_MDRSTCTL+0x016C)
#define REG_MDRSTCTL_APWDTER_MDPERI		(BASE_ADDR_MDRSTCTL+0x0170)		//AP software reset MD
#define REG_MDRSTCTL_APWDTER_PSMCU		(BASE_ADDR_MDRSTCTL+0x0174)		//AP software reset MD
#define REG_MDRSTCTL_APWDTER_MDINFRA	(BASE_ADDR_MDRSTCTL+0x0178)		//AP software reset MD
#define REG_MDRSTCTL_APWDTER_LTEL2		(BASE_ADDR_MDRSTCTL+0x017C)		//AP software reset MD
#define REG_MDRSTCTL_APWDTER_HSPAL2		(BASE_ADDR_MDRSTCTL+0x0180)		//AP software reset MD
#define REG_MDRSTCTL_APWDTER_ARM7		(BASE_ADDR_MDRSTCTL+0x0184)		//AP software reset MD

#define REG_MDRSTCTL_SRCMR              (BASE_ADDR_MDRSTCTL+0x0300)
#define REG_MDRSTCTL_SRCMR_SWDT    		(BASE_ADDR_MDRSTCTL+0x0304)
#define REG_MDRSTCTL_SRBER_MDPERI       (BASE_ADDR_MDRSTCTL+0x0308)
#define REG_MDRSTCTL_SRBER_PSMCU        (BASE_ADDR_MDRSTCTL+0x030C)
#define REG_MDRSTCTL_SRBER_MDINFRA      (BASE_ADDR_MDRSTCTL+0x0310)
#define REG_MDRSTCTL_SRBER_LTEL2        (BASE_ADDR_MDRSTCTL+0x0314)
#define REG_MDRSTCTL_SRBER_HSPAL2       (BASE_ADDR_MDRSTCTL+0x0318)
#define REG_MDRSTCTL_SRBER_ARM7         (BASE_ADDR_MDRSTCTL+0x031C)
#define REG_MDRSTCTL_WDTCFG_L1          (BASE_ADDR_MDRSTCTL+0x0330)
#define REG_MDRSTCTL_WDTCFG_ARM7        (BASE_ADDR_MDRSTCTL+0x0334)
#define REG_MDRSTCTL_WDTIR              (BASE_ADDR_MDRSTCTL+0x033C) 
#define REG_MDRSTCTL_WDT_DUMMY      	(BASE_ADDR_MDRSTCTL+0x0358)

#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
//1 TOPRGU Registers
#define TOP_RGU_NONRST_REG2 			(BASE_MADDR_TOP_RGU+0x0024)
#define TOP_RGU_NONRST_REG 				(BASE_MADDR_TOP_RGU+0x0020)
#define REG_TOPRGU_MODE					(BASE_MADDR_TOP_RGU+0x0000)
#define REG_TOPRGU_LENGTH				(BASE_MADDR_TOP_RGU+0x0004)
#define REG_TOPRGU_RESTART 				(BASE_MADDR_TOP_RGU+0x0008)
#define REG_TOPRGU_SWRST				(BASE_MADDR_TOP_RGU+0x0014)
#endif

#if defined(TK6291)
//1 APRGU Registers
#define BASE_ADDR_APRSTCTL	            (BASE_MADDR_APRGU)

#define REG_APRSTCTL_WDTCR              (BASE_ADDR_APRSTCTL+0x0100)
#define REG_APRSTCTL_WDTCR_MD1 			(BASE_ADDR_APRSTCTL+0x0104)  			 
#define REG_APRSTCTL_WDTCR_MD2  		(BASE_ADDR_APRSTCTL+0x0108)   	
#define REG_APRSTCTL_WDTCR_MD3		    (BASE_ADDR_APRSTCTL+0x010C)		   

#define REG_APRSTCTL_WDTIR              (BASE_ADDR_APRSTCTL+0x0110)  			
#define REG_APRSTCTL_WDTRR              (BASE_ADDR_APRSTCTL+0x0114)  			


#define REG_APRSTCTL_WDTER_MEMSYS       (BASE_ADDR_APRSTCTL+0x0118) 			
#define REG_APRSTCTL_WDTER_APMCU       	(BASE_ADDR_APRSTCTL+0x011C)			
#define REG_APRSTCTL_WDTER_APPERI		(BASE_ADDR_APRSTCTL+0x0120)   		
#define REG_APRSTCTL_WDTER_SSUSB		(BASE_ADDR_APRSTCTL+0x0124)   		
#define REG_APRSTCTL_WDTER_APINFRA		(BASE_ADDR_APRSTCTL+0x0128)	
#define REG_APRSTCTL_WDTER_TOPAO		(BASE_ADDR_APRSTCTL+0x012C)	
																			 
#define REG_APRSTCTL_WDTSR				(BASE_ADDR_APRSTCTL+0x0130)			
#define REG_APRSTCTL_WDTSR_MD1			(BASE_ADDR_APRSTCTL+0x0134)			
#define REG_APRSTCTL_WDTSR_MD2			(BASE_ADDR_APRSTCTL+0x0138)			
#define REG_APRSTCTL_WDTSR_MD3			(BASE_ADDR_APRSTCTL+0x013C)			

#define REG_APRSTCTL_WDTHR_CTL			(BASE_ADDR_APRSTCTL+0x0140)				
#define REG_APRSTCTL_WDTHR_L			(BASE_ADDR_APRSTCTL+0x0144)
#define REG_APRSTCTL_WDTHR_H			(BASE_ADDR_APRSTCTL+0x0148)


#define REG_APRSTCTL_SRSTR_MEMSYS       (BASE_ADDR_APRSTCTL+0x0150)			
#define REG_APRSTCTL_SRSTR_APMCU       	(BASE_ADDR_APRSTCTL+0x0154)			
#define REG_APRSTCTL_SRSTR_APPERI       (BASE_ADDR_APRSTCTL+0x0158)			
#define REG_APRSTCTL_SRSTR_SSUSB        (BASE_ADDR_APRSTCTL+0x015C)			
#define REG_APRSTCTL_SRSTR_APINFRA      (BASE_ADDR_APRSTCTL+0x0160)			
#define REG_APRSTCTL_SRSTR_TOPAO        (BASE_ADDR_APRSTCTL+0x0164)			

	
#define REG_APRSTCTL_WDTER_PAR_AP       (BASE_ADDR_APRSTCTL+0x0168)			
#define REG_APRSTCTL_SRSTR_PAR     		(BASE_ADDR_APRSTCTL+0x016C)


#define REG_APRSTCTL_EXTRST             (BASE_ADDR_APRSTCTL+0x0170)			
#define REG_APRSTCTL_EXTRST_MD1    		(BASE_ADDR_APRSTCTL+0x0174)			
#define REG_APRSTCTL_EXTRST_MD2 		(BASE_ADDR_APRSTCTL+0x0178)
#define REG_APRSTCTL_EXTRST_MD3 		(BASE_ADDR_APRSTCTL+0x017C)
#define REG_APRSTCTL_OTHER_RSTSTS       (BASE_ADDR_APRSTCTL+0x0180)			
#define REG_APRSTCTL_RESET_UNLOCK       (BASE_ADDR_APRSTCTL+0x0184)			
#define REG_APRSTCTL_MAGIC_KEY          (BASE_ADDR_APRSTCTL+0x0188)			
#define REG_APRSTCTL_DUMMY              (BASE_ADDR_APRSTCTL+0x0190)			


#define REG_APRSTCTL_SRCMR	         	(BASE_ADDR_APRSTCTL+0x0300)			
#define REG_APRSTCTL_SRCMR_SWDT       	(BASE_ADDR_APRSTCTL+0x0304)			
#define REG_APRSTCTL_SRBER_MEMSYS      	(BASE_ADDR_APRSTCTL+0x0308)			
#define REG_APRSTCTL_SRBER_APMCU      	(BASE_ADDR_APRSTCTL+0x030C)			
#define REG_APRSTCTL_SRBER_APPERI      	(BASE_ADDR_APRSTCTL+0x0310)			
#define REG_APRSTCTL_SRBER_SSUSB      	(BASE_ADDR_APRSTCTL+0x0314)			
#define REG_APRSTCTL_SRBER_APINFRA     	(BASE_ADDR_APRSTCTL+0x031C)			
#define REG_APRSTCTL_SRBER_PAR      	(BASE_ADDR_APRSTCTL+0x0320)			
#define REG_APRSTCTL_SRBER_TOPAO      	(BASE_ADDR_APRSTCTL+0x0324)			


#define REG_APRSTCTL_MDWDTCFG_MD1      	(BASE_ADDR_APRSTCTL+0x0330)			
#define REG_APRSTCTL_MDWDTCFG_MD2      	(BASE_ADDR_APRSTCTL+0x0334)			
#define REG_APRSTCTL_MDWDTCFG_MD3      	(BASE_ADDR_APRSTCTL+0x0338)			
#define REG_APRSTCTL_WDT_DUMMY      	(BASE_ADDR_APRSTCTL+0x0358)  
#endif 

//L1RGU Registers
#define L1_BASE_ADDR_L1RGU 				(0XF6010000)
#define REG_L1RSTCTL_WDT_MODE			(L1_BASE_ADDR_L1RGU+0x0000)
#define REG_L1RSTCTL_WDT_LENGTH			(L1_BASE_ADDR_L1RGU+0x0004)
#define REG_L1RSTCTL_WDT_RESTART		(L1_BASE_ADDR_L1RGU+0x0008)
#define REG_L1RSTCTL_WDT_STA			(L1_BASE_ADDR_L1RGU+0x000C)
#define REG_L1RSTCTL_WDT_SWRST			(L1_BASE_ADDR_L1RGU+0x0018)


//ARM7 
#define BASE_ADDR_ARM7WDT_TEMP			(0XF0400000)			
#define REG_ARM7RSTCTL_WDTCR			(BASE_ADDR_ARM7WDT_TEMP+0x0100)
#define REG_ARM7RSTCTL_WDTIR			(BASE_ADDR_ARM7WDT_TEMP+0x0110)
#define REG_ARM7RSTCTL_WDTRR			(BASE_ADDR_ARM7WDT_TEMP+0x0114)
#define REG_ARM7RSTCTL_WDTSR			(BASE_ADDR_ARM7WDT_TEMP+0X0130)
#define REG_ARM7RSTCTL_DUMMY			(BASE_ADDR_ARM7WDT_TEMP+0X0190)
//#define REG_ARM7RSTCTL_WDT_DUMMY		(BASE_ADDR_ARM7WDT+0X0190) //ADDRESS CONFLICT!!!
#define REG_ARM7RSTCTL_SRCMR_SWDT		(BASE_ADDR_ARM7WDT_TEMP+0X0304)






#define _RST_DURATION_LOOP_DEFAULT_VALUE	    (100)		/* Just a magic number for reset duration */

/**< REG_APRGU/MDRGU_SRCMR */
#define RSTCTL_SRCMR_KEY_SWDT_MASK				(0xffff)		/* Key of reset command */
#define RSTCTL_SRCMR_KEY_SWDT_OFFSET		    (16)
#define RSTCTL_SRCMR_KEY_SWDT				    ((0x1688 << RSTCTL_SRCMR_KEY_SWDT_OFFSET) | 0x1)	/* Key to enable software watch dog reset */
#define RSTCTL_SRCMR_KEY_SWRST					((0x2593 << RSTCTL_SRCMR_KEY_SWDT_OFFSET) | 0x1)	/* Key to enable software reset */

/**< REG_MDRSTCTL_SRBER_MDPERI */
#define RSTCTL_MDSRBER_MDGDMA_RST				(1 << 0)		/**< Soft reset of MDGDMA      */
#define RSTCTL_MDSRBER_USIM1_RST				(1 << 1)		/**< Soft reset of USIM1      */
#define RSTCTL_MDSRBER_USIM2_RST				(1 << 2)		/**< Soft reset of USIM2      */
#define RSTCTL_MDSRBER_MDUART0_RST			    (1 << 3)		/**< Soft reset of MDUART0      */
#define RSTCTL_MDSRBER_MDGPTM_RST				(1 << 4)		/**< Soft reset of MDGPTM      */
#define RSTCTL_MDSRBER_MDMISC_RST				(1 << 5)		/**< Soft reset of MDMISC      */
#define RSTCTL_MDSRBER_MDCIRQ_RST				(1 << 6)		/**< Soft reset of MDCIRQ      */
#define RSTCTL_MDSRBER_I2C_RST				    (1 << 7)		/**< Soft reset of I2C       */
#define RSTCTL_MDSRBER_MDDBGSYS_RST				(1 << 8)		/**< Soft reset of MDDBGSYS    */
#define RSTCTL_MDSRBER_MDDBGSIB_RST				(1 << 9)		/**< Soft reset of MDDBGSIB    */
#define RSTCTL_MDSRBER_GPIOMUX_RST			    (1 << 10)		/**< Soft reset of GPIOMUX   */
#define RSTCTL_MDSRBER_MDTOPSM_RST			    (1 << 11)		/**< Soft reset of MDTOPSM     */
#define RSTCTL_MDSRBER_MDOST_RST				(1 << 12)		/**< Soft reset of MDOST       */
#define RSTCTL_MDSRBER_MDCFGCTL_RST			    (1 << 13)		/**< Soft reset of MDCFGCTL  */
#define RSTCTL_MDSRBER_MDECT_RST				(1 << 14)		/**< Soft reset of MDECT     */
#define RSTCTL_MDSRBER_MDECTDBG_RST			    (1 << 15)		/**< Soft reset of MDECTDBG  */
#define RSTCTL_MDSRBER_MDCLKBUS_RST			    (1 << 17)		/**< Soft reset of MDCLKBUS  */
#define RSTCTL_MDSRBER_MDCLK_RST			    (1 << 18)		/**< Soft reset of MDCLK  */
#define RSTCTL_MDSRBER_TRACE_RST				(1 << 19)       /**< Soft reset of TRACE 			 */											
#define RSTCTL_MDSRBER_PSLITE_GPT_RST			(1 << 20)       /**< Soft reset of PSLITE_GPT		 */											
#define RSTCTL_MDSRBER_ARM7_PCCIF_RST			(1 << 21)       /**< Soft reset of ARM7_PCCIF 			 */											
#define RSTCTL_MDSRBER_L1SYS_RST				(1 << 24)		/**< Soft reset of L1SYS 			: only valid for MDARM */											


/**< REG_MDRSTCTL_SRBER_ARM7 */
#define RSTCTL_MDSRBER_ARM7_HRST_RST			(1 << 0)		/**< Soft reset of ARM7 HRST */
#define RSTCTL_MDSRBER_ARM7_SRST_RST			(1 << 1)		/**< Soft reset of ARM7 SRST */
#define RSTCTL_MDSRBER_ARM7_CIRQ_RST				    (1 << 2)		/**< Soft reset of ARM7 CIRQ */
#define RSTCTL_MDSRBER_ARM7SYS_RST              (RSTCTL_MDSRBER_ARM7_HRST_RST|RSTCTL_MDSRBER_ARM7_SRST_RST|RSTCTL_MDSRBER_ARM7_CIRQ_RST)

/**< REG_MDRSTCTL_SRBER_LTEL2 */
#define RSTCTL_MDSRBER_LTEL2_RST				(1 << 0)		/**< Soft reset of LTEL2  */

/**< REG_MDRSTCTL_SRBER_HSPAL2 */
#define RSTCTL_MDSRBER_HSPAL2_RST				(1 << 0)		/**< Soft reset of HSPAL2  */

/**< REG_MDRSTCTL_SRBER_MDINFRA */
#define RSTCTL_MDSRBER_MDINFRA_BUSMON_RST		(1 << 0)		/**< Soft reset of MDINFRA_BUSMON  */
#define RSTCTL_MDSRBER_MDINFRA_BOOTROM_RST		        (1 << 1)		/**< Soft reset of BOOTROM */
#define RSTCTL_MDSRBER_ABM_RST				    (1 << 2)		/**< Soft reset of ABM     */
#define RSTCTL_MDSRBER_MDUART1_RST		        (1 << 3)		/**< Soft reset of MDUART1 */
#define RSTCTL_MDSRBER_MDUART2_RST		        (1 << 4)		/**< Soft reset of MDUART2 */
#define RSTCTL_MDSRBER_PSPERI_RST			    (1 << 5)		/**< Soft reset of PSPERI  */
#define RSTCTL_MDSRBER_BUS_RECORD_RST		 	(1 << 6)		/**< Soft reset of BUS_RECORD    */	
#define RSTCTL_MDSRBER_SOE_RST					(1 << 7)		/**< Soft reset of SOE (security offload engine)    */	


/**< REG_MDRSTCTL_SRBER_MDMCU */
#define RSTCTL_MDSRBER_CR4_DBG_RST			    (1 << 0)		/**< Soft reset of CR4_DBG     */
#define RSTCTL_MDSRBER_CR4_NRESET_RST			(1 << 1)		/**< Soft reset of CR4_NRESET  */
#define RSTCTL_MDSRBER_CR4_BUSMON_RST			(1 << 2)		/**< Soft reset of CR4_BUSMON  */
#define RSTCTL_MDSRBER_PF_RST					(1 << 4)		/**< Soft reset of PF          */
#define RSTCTL_MDSRBER_PCMON_FIFO_RST			(1 << 6)		/**< Soft reset of PCMON_FIFO  */
#define RSTCTL_MDSRBER_PCMON_REG_RST			(1 << 7)		/**< Soft reset of PCMON_REG   */


/**< REG_APRSTCTL_SRBER */

/*   SRBER TOPAO*/
#define RSTCTL_APSRBER_EFUSE_RST				(1 << 0)		/**< Soft reset of EFUSE		 */
#define RSTCTL_APSRBER_SSUSB_DIGPHY_RST			(1 << 1)		/**< Soft reset of SSUSB_DIGPHY*/
#define RSTCTL_APSRBER_SSUSB_PHY_RST			(1 << 2)		/**< Soft reset of SSUSB_PHY	 */
#define RSTCTL_APSRBER_APCLKBUS_RST				(1 << 7)		/**< Soft reset of APCLKBUS	 */
#define RSTCTL_APSRBER_APCLK_RST				(1 << 8)		/**< Soft reset of APCLK 		 */
#define RSTCTL_APSRBER_AUXADC_RST				(1 << 9)		/**< Soft reset of AUXADC 		 */
#define RSTCTL_APSRBER_DRAMC_AO_RST				(1 << 20)		/**< Soft reset of DRAMC_AO 	 */
#define RSTCTL_APSRBER_EMI_AO_RST				(1 << 21)		/**< Soft reset of EMI_AO 		 */
#define RSTCTL_APSRBER_MEMMISC_AO_RST		    (1 << 22)		/**< Soft reset of MEMMISC_AO  */


/*   SRBER APPERI  */
#define RSTCTL_APSRBER_APPERI_MASK			(0xC07FFFFF)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_APSRBER_APMISC_RST				(1 << 0)		/**< Soft reset of APMISC 		 */
#define RSTCTL_APSRBER_APGPTM_RST				(1 << 1)		/**< Soft reset of APGPTM 		 */
//#define RSTCTL_SRBER_APTZCTL_RST			(1 <<  2)		/**< Soft reset of APTZCTL 	 */
#define RSTCTL_APSRBER_APGPIO_RST				(1 << 3)		/**< Soft reset of APGPIO 		 */
#define RSTCTL_APSRBER_APUART0_RST				(1 << 4)		/**< Soft reset of APUART0		 */
#define RSTCTL_APSRBER_SDCTL_RST				(1 << 5)		/**< Soft reset of SDCTL 		 */
#define RSTCTL_APSRBER_APTOPSM_RST				(1 << 6)		/**< Soft reset of APTOPSM 	 */
#define RSTCTL_APSRBER_APOST_RST				(1 << 7)		/**< Soft reset of APOST 		 */
#define RSTCTL_APSRBER_APDBGSYS_RST				(1 << 8)		/**< Soft reset of APDBGSYS 	 */
#define RSTCTL_APSRBER_APDBGCV_RST				(1 << 9)		/**< Soft reset of APDBGCV 	 */
#define RSTCTL_APSRBER_NLI_ARB_RST				(1 << 10)		/**< Soft reset of NLI_ARB 		 */
#define RSTCTL_APSRBER_APCFGCTL_RST				(1 << 11)		/**< Soft reset of APCFGCTL 	 */
#define RSTCTL_APSRBER_NFI_AO_RST				(1 << 12)		/**< Soft reset of NFI_AO 		 */
#define RSTCTL_APSRBER_APECT_RST				(1 << 13)		/**< Soft reset of APECT 		 */
#define RSTCTL_APSRBER_APECTDBG_RST				(1 << 14)		/**< Soft reset of APECTDBG 	 */
#define RSTCTL_APSRBER_CLDMA_AO_RST				(1 << 15)		/**< Soft reset of CLDMA_AO	 */
#define RSTCTL_APSRBER_SEJ_RST					(1 << 16)		/**< Soft reset of SEJ	 		 */
#define RSTCTL_APSRBER_APLED_RST				(1 << 17)		/**< Soft reset of APLED 		 */
#define RSTCTL_APSRBER_PMIC_RST					(1 << 18)		/**< Soft reset of PMIC 		 */
#define RSTCTL_APSRBER_PMICBUS_RST				(1 << 19)		/**< Soft reset of PMICBUS		 */
#define RSTCTL_APSRBER_PTPOD_RST				(1 << 20)		/**< Soft reset of PTPOD 		 */
#define RSTCTL_APSRBER_PTPODBUS_RST				(1 << 21)		/**< Soft reset of PTPODBUS	 */
#define RSTCTL_APSRBER_SDCTL_CISCC_RST			(1 << 22)		/**< Soft reset of SDCTL_CISCC */



/*   SRBER MEMSYS  */
#define RSTCTL_APSRBER_MEMSYS_MASK				(0xC000003F)	/**< Mask of software reset modules for RSTCTL_SSRR control */		
#define RSTCTL_APSRBER_DRAMC_RST				(1 << 0)		/**< Soft reset of DRAMC 	 */								
#define RSTCTL_APSRBER_EMI_RST					(1 << 1)		/**< Soft reset of EMI 		 */									
#define RSTCTL_APSRBER_DDRPHY_RST				(1 << 2)		/**< Soft reset of DDRPHY 	 */
#define RSTCTL_APSRBER_SRAMROM_RST				(1 << 3)		/**< Soft reset of SRAMROM*/
#define RSTCTL_APSRBER_DDRBRIDGE_RST			(1 << 4)		/**< Soft reset of DDRBRIDGE */
#define RSTCTL_APSRBER_TRFGEN_RST				(1 << 5)		/**< Soft reset of TRFGEN 	 */
#define RSTCTL_APSRBER_MEMSYS_BUS_RST			(1 << 31)		/**< Soft reset of MEMSYS_BUS */ //Workaround TK6291 incorrect wiring. 

/*   SRBER SSUSB  */
#define RSTCTL_APSRBER_SSUSB_MASK				(0xC0000001)	/**< Mask of software reset modules for RSTCTL_SSRR control */.
#define RSTCTL_APSRBER_SSUSB_RST				(1 << 0)		/**< Soft reset of SSUSB 	  */
/*   SRBER APINFRA  */
#define RSTCTL_APSRBER_APINFRA_MASK				(0xC01FFDFF)	/**< Mask of software reset modules for APINFRA control */		
#define RSTCTL_APSRBER_NFI_RST					(1 << 0)		/**< Soft reset of NFI 			 */			
#define RSTCTL_APSRBER_SPI_RST					(1 << 1)		/**< Soft reset of SPI 			 */		
#define RSTCTL_APSRBER_USB_RST					(1 << 2)		/**< Soft reset of USB 		 */			
#define RSTCTL_APSRBER_IPSEC_RST				(1 << 3)		/**< Soft reset of IPSEC 		 */			
#define RSTCTL_APSRBER_HIF0_RST					(1 << 4)		/**< Soft reset of HIFO 		 */			
#define RSTCTL_APSRBER_PFC_RST					(1 << 5)		/**< Soft reset of PFC 		 */			
#define RSTCTL_APSRBER_MSDC0P_RST				(1 << 6)		/**< Soft reset of MSDC0P 		 */	
#define RSTCTL_APSRBER_APGDMA_RST				(1 << 7)		/**< Soft reset of APGDMA 		 */	
#define RSTCTL_APSRBER_APINFRA_BUSMON_RST		(1 << 8)		/**< Soft reset of APINFRA_BUSMON  */	
#define RSTCTL_APSRBER_APUART1_RST				(1 << 10)		/**< Soft reset of APUART1		 */	
#define RSTCTL_APSRBER_APUART2_RST				(1 << 11)		/**< Soft reset of APUART2		 */	
#define RSTCTL_APSRBER_PCCIF0_RST				(1 << 12)		/**< Soft reset of PCCIF0 		 */	
#define RSTCTL_APSRBER_PCCIF1_RST				(1 << 13)		/**< Soft reset of PCCIF0 		 */		
#define RSTCTL_APSRBER_PCCIF2_RST				(1 << 14)		/**< Soft reset of PCCIF0 		 */		
#define RSTCTL_APSRBER_PCCIF3_RST				(1 << 15)		/**< Soft reset of PCCIF0 		 */		
#define RSTCTL_APSRBER_CLDMA_RST				(1 << 16)		/**< Soft reset of CLDMA 		 */	
#define RSTCTL_APSRBER_RTC_RST					(1 << 17)		/**< Soft reset of RTC 		 */	
#define RSTCTL_APSRBER_MSDC1P_RST				(1 << 18)		/**< Soft reset of MSDC1P 		 */	
#define RSTCTL_APSRBER_MSDC_C2K_RST				(1 << 19)		/**< Soft reset of MSDC_C2K 	 */	
#define RSTCTL_APSRBER_TRNG_RST					(1 << 20)		/**< Soft reset of TRNG 		 */	
#define RSTCTL_APSRBER_L12PS_RCCIF_RST			(1 << 20)		/**< Soft reset of L12PS_RCCIF */	
#define RSTCTL_APSRBER_PS2L1_RCCIF_RST			(1 << 20)		/**< Soft reset of PS2L1_RCCIF */	
#define RSTCTL_APSRBER_L12MD2_RCCIF_RST			(1 << 20)		/**< Soft reset of L12MD2_RCCIF */	
#define RSTCTL_APSRBER_L12MD3_RCCIF_RST			(1 << 20)		/**< Soft reset of L12MD3_RCCIF */	
#define RSTCTL_APSRBER_MD22L1_RCCIF_RST			(1 << 20)		/**< Soft reset of MD22L1_RCCIF */	
#define RSTCTL_APSRBER_MD32L1_RCCIF_RST			(1 << 20)		/**< Soft reset of MD32L1_RCCIF */	




/*   SRBER APMCU  */
#define RSTCTL_APSRBER_APMCU_MASK					(0xC0000007)	/**< Mask of software reset modules for APINFRA control */		
#define RSTCTL_APSRBER_CA7_DBG_RST				(1 << 0)		/**< Soft reset of CA7_DBG 	 */							
#define RSTCTL_APSRBER_CA7_NRESET_RST				(1 << 1)		/**< Soft reset of CA7_NRESET 	 */		
#define RSTCTL_APSRBER_CA7_BUSMON_RST				(1 << 2)		/**< Soft reset of CA7_BUSMON  */		

/*   SRBER PAR_AP  */
#define RSTCTL_APSRBER_APMCU_MASK					(0xC0000007)	/**< Mask of software reset modules for APINFRA control */		
#define RSTCTL_APSRBER_MD1_RST					(1 << 2)		/**< Soft reset of MD1 	 */							
#define RSTCTL_APSRBER_AP_MD1_RST					(1 << 3)		/**< Soft reset of AP_MD1 	 */			
#define RSTCTL_APSRBER_MD2_RST					(1 << 4)		/**< Soft reset of MD2 	 */	
#define RSTCTL_APSRBER_AP_MD2_RST					(1 << 5)		/**< Soft reset of AP_MD2 	 */	
#define RSTCTL_APSRBER_C2K_RST					(1 << 6)		/**< Soft reset of C2K	   	 */		
#define RSTCTL_APSRBER_AP_C2K_RST					(1 << 7)		/**< Soft reset of AP_C2K 	 */		
#define RSTCTL_APSRBER_C2K_ARM_RST				(1 << 8)		/**< Soft reset of C2K_ARM	 */		




/**< REG_MDRGU/APRGU_WDTCR */
#define RSTCTL_WDTCR_KEY_CONTROL_OFFSET		    (24)
#define RSTCTL_WDTCR_KEY					    (0x55 << RSTCTL_WDTCR_KEY_CONTROL_OFFSET)
#define RSTCTL_WDTCR_WDT_SPD_UP       		    (1 << 15)       /* watch dog timer speed up mode (timer will decrease by 256 per cycle if enable)*/
#define RSTCTL_WDTCR_WDT_IRQEN				    (1 << 3)		/* watch dog timer interrupt enable (select "intterrupt" or "reset" when watch dog timeout) */
#define RSTCTL_WDTCR_WDT_EN					    (1 << 0)		/* watch dog timer enable */

/**< REG_MDRSTCTL_WDTCR_L1 */
#define RSTCTL_WDTCR_WDT_L1_KEY_CONTROL_OFFSET	(24)
#define RSTCTL_WDTCR_WDT_L1_KEY					(0x56 << RSTCTL_WDTCR_WDT_L1_KEY_CONTROL_OFFSET)
#define RSTCTL_WDTCR_WDT_L1_IRQ_BYPASS			(1 << 0)		/* Bypass L1 IRQ to AP RGU */

/**< REG_MDRSTCTL_WDTCR_ARM7 */
#define RSTCTL_WDTCR_WDT_ARM7_KEY_CONTROL_OFFSET	(24)
#define RSTCTL_WDTCR_WDT_ARM7_KEY					(0x56 << RSTCTL_WDTCR_WDT_ARM7_KEY_CONTROL_OFFSET)
#define RSTCTL_WDTCR_WDT_ARM7_IRQ_BYPASS			(1 << 0)		/* Bypass ARM7 IRQ to AP RGU */


/**< REG_APRSTCTL_WDTCR_MD1 */
#define RSTCTL_WDTCR_MD1_KEY_CONTROL_MASK		(0xff)
#define RSTCTL_WDTCR_MD1_KEY_CONTROL_OFFSET		(24)
#define RSTCTL_WDTCR_MD1_KEY					(0x56 << RSTCTL_WDTCR_WDT_L1_KEY_CONTROL_OFFSET)
#define RSTCTL_WDTCR_MD1_IRQ_BYPASS				(1 << 0)		/* 	1: WDT IRQ will trigger external reset 
																	0: WDT IRQ will not trigger extern reset. */
#define RSTCTL_WDTCR_MD1_AP_AUTO_RST			(1 << 1)		/* 	1: AP RGU will reset whole system upon receiving md1_wdt_irq; 
																    	0: AP RGU will software reset upong receiving md1_wdit_irq.*/
#define RSTCTL_WDTCR_MD2_KEY_CONTROL_MASK		(0xff)
#define RSTCTL_WDTCR_MD2_KEY_CONTROL_OFFSET		(24)
#define RSTCTL_WDTCR_MD2_KEY					(0x57 << RSTCTL_WDTCR_WDT_L1_KEY_CONTROL_OFFSET)
#define RSTCTL_WDTCR_MD2_IRQ_BYPASS				(1 << 0)		/* 	1: WDT IRQ will trigger external reset 
																	0: WDT IRQ will not trigger extern reset. */
#define RSTCTL_WDTCR_MD2_AP_AUTO_RST			(1 << 1)		/* 	1: AP RGU will reset whole system upon receiving md2_wdt_irq; 
																	0: AP RGU will software reset upong receiving md2_wdit_irq.*/
	
#define RSTCTL_WDTCR_MD3_KEY_CONTROL_MASK		(0xff)
#define RSTCTL_WDTCR_MD3_KEY_CONTROL_OFFSET		(24)
#define RSTCTL_WDTCR_MD3_KEY					(0x58 << RSTCTL_WDTCR_WDT_L1_KEY_CONTROL_OFFSET)
#define RSTCTL_WDTCR_MD3_IRQ_BYPASS				(1 << 0)		/* 	1: WDT IRQ will trigger external reset 
																	0: WDT IRQ will not trigger extern reset. */
#define RSTCTL_WDTCR_MD3_AP_AUTO_RST			(1 << 1)		/* 	1: AP RGU will reset whole system upon receiving md3_wdt_irq; 
																	0: AP RGU will software reset upong receiving md3_wdit_irq.*/



/**< REG_MDRSTCTL_WDTIR */
#define RSTCTL_WDTIR_KEY_INTV_OFFSET		    (24)
#define RSTCTL_WDTIR_KEY					    (0x67 << RSTCTL_WDTIR_KEY_INTV_OFFSET)
#define RSTCTL_WDTIR_INTERVAL_MASK			    (0x3FFFFF)		/* Watch dog timer down count interval (the real interval is 1/32.768k */
#define RSTCTL_WDTIR_INTERVAL_OFFSET		    (0)

/**< REG_MDRSTCTL_WDTRR */
#define RSTCTL_WDTRR_KEY_RESTART_OFFSET		    (16)
#define RSTCTL_WDTRR_KEY					    (0x7208 << RSTCTL_WDTRR_KEY_RESTART_OFFSET)
#define RSTCTL_WDTRR_WDT_RESTART				(1 << 0)


#define RSTCTL_CR4_RESET_UNLOCK_STS			(1 << 17)
#define RSTCTL_ARM7_RESET_UNLOCK_STS		(1 << 16)
#define RSTCTL_CR4_RESET_UNLOCK_CMD			(1 << 1)
#define RSTCTL_ARM7_RESET_UNLOCK_CMD		(1 << 0)



/**< REG_MDRSTCTL_WDTSR */
#define RSTCTL_WDTSR_KEY_OFFSET				(16)
#define RSTCTL_WDTSR_KEY					    (0x7662 << RSTCTL_WDTSR_KEY_OFFSET)
#define RSTCTL_WDTSR_STATUS_MASK			    (0x7)		/* Watchdog status */
#define RSTCTL_WDTSR_STATUS_OFFSET            (0)
#define RSTCTL_WDTSR_STS_CLR_OFFSET           (3)
#define RSTCTL_WDTSR_MD_HWDT                  (1 << 0)
#define RSTCTL_WDTSR_MD_SWDT		            (1 << 1)
#define RSTCTL_WDTSR_OST_TIMEOUT              (1 << 2)

/**< REG_MDRSTCTL_WDTSR_L1 */
#define RSTCTL_WDTSR_L1_KEY_OFFSET			(16)
#define RSTCTL_WDTSR_L1_KEY					(0x7663 << RSTCTL_WDTSR_L1_KEY_OFFSET)
#define RSTCTL_WDTSR_L1_CLR_L1_SWDT_STS			(1 << 3)
#define RSTCTL_WDTSR_L1_CLR_L1_HWDT_STS			(1 << 2)
#define RSTCTL_WDTSR_L1_SWDT_STS				(1 << 1)
#define RSTCTL_WDTSR_L1_HWDT_STS				(1 << 0)

/**< REG_MDRSTCTL_WDTSR_ARM7 */
#define RSTCTL_WDTSR_ARM7_KEY_OFFSET			(16)
#define RSTCTL_WDTSR_ARM7_KEY					(0x7664 << RSTCTL_WDTSR_ARM7_KEY_OFFSET)
#define RSTCTL_WDTSR_ARM7_WDT_CNT_MASK			(0xff << 8)
#define RSTCTL_WDTSR_ARM7_CLR_ARM7_CNT			(1 << 4)
#define RSTCTL_WDTSR_ARM7_CLR_ARM7_STS			(1 << 2)
#define RSTCTL_WDTSR_ARM7_WDT_STS				(1 << 0)

/**< REG_APRGU_EXTRST >**/									
#define RSTCTL_EXTRST_KEY						(0x7766 << 16)		
#define RSTCTL_EXTRST_WDT_STS                   (1 << 15)	/* 	STATUS: EXTRST generated by AP WDT status (HW WDT + SW wdt).
															It represents the external reset value. 1: asserted. 0: de-asserted*/					
#define RSTCTL_EXTRST_CLR_EXT_AP_WDT			(1 << 4)	/* 	Clear external reset. */
#define RSTCTL_EXTRST_AP_WDT_EN					(1 << 2)	/*  	Enable EXTRST generated by AP WDT (AP HW WDT + AP SW WDT)*/
#define RSTCTL_EXTRST_OE                        (1 << 1)	/*   Output enable control of EXTRST*/						
#define RSTCTL_EXTRST_POLARITY_HIGH				(1 << 0)    /*	Active high*/                  							
#define RSTCTL_EXTRST_POLARITY_LOW				(0 << 0)	/*	Active low*/


/**< REG_APRGU_EXTRST_MD1 >**/									
#define RSTCTL_EXTRST_MD1_KEY				    (0x7767 << 16)		
#define RSTCTL_EXTRST_MD1_WDT_STS               (1 << 15)	/* 	STATUS: EXTRST generated by MD1 WDT status.
															It represents the external reset value. 1: asserted. 0: de-asserted*/					
#define RSTCTL_EXTRST_CLR_EXT_MD1_WDT			(1 << 4)	/* 	Clear external reset. */
#define RSTCTL_EXTRST_MD1_WDT_EN				(1 << 0)	/*  	Enable EXTRST generated by MD1 WDT (MD1WDT irq ASSERT &&  IRQ_BYPASS)*/

/**< REG_APRGU_EXTRST_MD2 >**/									
#define RSTCTL_EXTRST_MD2_KEY					(0x7768 << 16)		
#define RSTCTL_EXTRST_MD2_WDT_STS               (1 << 15)	/* 	STATUS: EXTRST generated by MD2 WDT status.
															It represents the external reset value. 1: asserted. 0: de-asserted*/					
#define RSTCTL_EXTRST_CLR_EXT_MD2_WDT			(1 << 4)	/* 	Clear external reset. */
#define RSTCTL_EXTRST_MD2_WDT_EN				(1 << 0)	/*  	Enable EXTRST generated by MD2 WDT (MD2WDT irq ASSERT &&  IRQ_BYPASS)*/

/**< REG_APRGU_EXTRST_MD3 >**/									
#define RSTCTL_EXTRST_MD3_KEY					(0x7769 << 16)		
#define RSTCTL_EXTRST_MD3_WDT_STS               (1 << 15)	/* 	STATUS: EXTRST generated by MD3 WDT status.
															It represents the external reset value. 1: asserted. 0: de-asserted*/					
#define RSTCTL_EXTRST_CLR_EXT_MD3_WDT			(1 << 4)	/* 	Clear external reset. */
#define RSTCTL_EXTRST_MD3_WDT_EN				(1 << 0)	/*  	Enable EXTRST generated by MD3 WDT (MD3WDT irq ASSERT &&  IRQ_BYPASS)*/



/**< REG_MDRSTCTL_RESET_UNLOCK */
#define RSTCTL_RESET_UNLOCK_CR4_STS           (1 << 17)
#define RSTCTL_RESET_UNLOCK_ARM7_STS          (1 << 16)
#define RSTCTL_RESET_UNLOCK_CR4_CMD           (1 << 1)
#define RSTCTL_RESET_UNLOCK_ARM7_CMD          (1 << 0)


/**< REG_MDRSTCTL_SRCMR_SWDT */
#define RSTCTL_MDSRCMR_SWDT_KEY_OFFSET          (16)
#define RSTCTL_MDSRCMR_SWDT_KEY                 (0x1688 <<  RSTCTL_MDSRCMR_SWDT_KEY_OFFSET)
#define RSTCTL_MDSRCMR_SWDT_RST                 (1 << 0)



#define RSTCTL_WDTSR_STS_CLR_MASK			(0X07)		/* CLR_AP_OSTT_STS(bit5), CLR_AP_SWDT_STS(bit4), CLR_AP_HWDT_STS(bit3) */
#define RSTCTL_WDTSR_STS_CLR_OFFSET			(3)
#define RSTCTL_WDTSR_CNT_CLR_MASK		    (0x03)		/* CLR_AP_SW_WDT_CNT (bit7), CLR_AP_HW_WDT_CNT (bit6)*/
#define RSTCTL_WDTSR_CNT_CLR_OFFSET		    (6)
#define RSTCTL_WDTSR_SW_WDT_CNT_MASK		(0XFF)
#define RSTCTL_WDTSR_SW_WDT_CNT_OFFSET		(16)
#define RSTCTL_WDTSR_HW_WDT_CNT_MASK		(0XFF)
#define RSTCTL_WDTSR_HW_WDT_CNT_OFFSET		(8)
#define RSTCTL_WDTSR_HWDT_STS					(1 << 0)
#define RSTCTL_WDTSR_SWDT_STS					(1 << 1)
#define RSTCTL_WDTSR_OSTT_STS					(1 << 2)



/**< REG_APRGU_WDTSR_MD1 >**/
#define RSTCTL_WDTSR_MD1_KEY_MASK				0xffff		/* Key of status clear */
#define RSTCTL_WDTSR_MD1_KEY_OFFSET				16
#define RSTCTL_WDTSR_MD1_KEY					(0x7663 << RSTCTL_WDTSR_MD1_KEY_OFFSET)
#define RSTCTL_WDTSR_MD1_STATUS_MASK			(0x01)		/* MD1_WDT_STS(bit0): WDT_IRQ fired && ! AP_AUTO_RST */
#define RSTCTL_WDTSR_MD1_STATUS_OFFSET			(0)
#define RSTCTL_WDTSR_MD1_STS_CLR_MASK			(0X01)		/* CLR_MD1_WDT_STS(bit1) */
#define RSTCTL_WDTSR_MD1_STS_CLR_OFFSET			(1)
#define RSTCTL_WDTSR_MD1_CNT_CLR_MASK		    (0x01)		/* CLR_MD1_WDT_CNT(bit4) */
#define RSTCTL_WDTSR_MD1_CNT_CLR_OFFSET		    (4)
#define RSTCTL_WDTSR_MD1_WDT_CNT_MASK			(0XFF)		/* MD1_WDT_CNT(bit15:8) */
#define RSTCTL_WDTSR_MD1_SW_WDT_CNT_OFFSET		(8)



#define RSTCTL_MDWDTCFG_MD1_KEY					(0X2555 << 16)
#define RSTCTL_MDWDTCFG_MD1_WDT_LV_EN_MD1		(1 << 0)

#define RSTCTL_MDWDTCFG_MD2_KEY					(0X2556 << 16)
#define RSTCTL_MDWDTCFG_MD2_WDT_LV_EN_MD2		(1 << 0)

#define RSTCTL_MDWDTCFG_MD3_KEY					(0X2557 << 16)
#define RSTCTL_MDWDTCFG_MD3_WDT_LV_EN_MD3		(1 << 0)


/**< REG_MDRSTCTL_WDTCFG_L1 */
#define RSTCTL_WDTCFG_L1_KEY            (0x2555 <<  16)
#define RSTCTL_WDTCFG_L1_LV_EN         (1 << 0)

/**< REG_MDRSTCTL_WDTCFG_ARM7 */
#define RSTCTL_WDTCFG_ARM7_KEY            (0x2556 <<  16)
#define RSTCTL_WDTCFG_ARM7_LV_EN         (1 << 0)


//#if defined (L1CORE)
#define RSTCTL_L1WDT_MODE_WDTEN				(1<<0)
#define RSTCTL_L1WDT_MODE_KEY				(0x22 << 8)
#define RSTCTL_L1WDT_LENGTH_MASK			(0xFFE0)
#define RSTCTL_L1WDT_LENGTH_OFFSET			(5)
#define RSTCTL_L1WDT_LENGTH_KEY				(0x08)
#define RSTCTL_L1WDT_RESTART_KEY			(0x1971)
#define RSTCTL_L1WDT_STA_WDT				(1<<15)
#define RSTCTL_L1WDT_STA_SWDT				(1<<14)

#define RSTCTL_L1WDT_SWRST_KEY				(0x1209)




//#if 0 /*Remove for not using*/
#elif defined(MT6290)

#define BASE_ADDR_RSTCTL	BASE_ADDR_MDRSTCTL

#define REG_MDRSTCTL_WDTCR              (BASE_ADDR_RSTCTL+0x0100)
#define REG_MDRSTCTL_WDTIR              (BASE_ADDR_RSTCTL+0x0104)
#define REG_MDRSTCTL_WDTRR              (BASE_ADDR_RSTCTL+0x0108)
#define REG_MDRSTCTL_WDTSR              (BASE_ADDR_RSTCTL+0x0134)
#define REG_MDRSTCTL_WDTER_MDON			(BASE_ADDR_RSTCTL+0x010C)
#define REG_MDRSTCTL_WDTER_MDMCU		(BASE_ADDR_RSTCTL+0x0110)
#define REG_MDRSTCTL_WDTER_MDINFRA		(BASE_ADDR_RSTCTL+0x0114)
#define REG_MDRSTCTL_WDTER_LTEL2		(BASE_ADDR_RSTCTL+0x0118)
#define REG_MDRSTCTL_WDTER_MEMSYS		(BASE_ADDR_RSTCTL+0x011C)
#define REG_MDRSTCTL_WDTER_ARM7			(BASE_ADDR_RSTCTL+0x0120)
#define REG_MDRSTCTL_WDTER_APMCU		(BASE_ADDR_RSTCTL+0x0124)
#define REG_MDRSTCTL_WDTER_APPERI		(BASE_ADDR_RSTCTL+0x0128)
#define REG_MDRSTCTL_WDTER_SSUSB		(BASE_ADDR_RSTCTL+0x012C)
#define REG_MDRSTCTL_WDTER_APON			(BASE_ADDR_RSTCTL+0x0130)
#define REG_MDRSTCTL_WDTSR				(BASE_ADDR_RSTCTL+0x0134)

#define REG_MDRSTCTL_SRSTR_MDON         (BASE_ADDR_RSTCTL+0x013C)
#define REG_MDRSTCTL_SRSTR_MDMCU        (BASE_ADDR_RSTCTL+0x0140)
#define REG_MDRSTCTL_SRSTR_MDINFRA      (BASE_ADDR_RSTCTL+0x0144)
#define REG_MDRSTCTL_SRSTR_LTEL2        (BASE_ADDR_RSTCTL+0x0148)
#define REG_MDRSTCTL_SRSTR_MEMSYS       (BASE_ADDR_RSTCTL+0x014C)
#define REG_MDRSTCTL_SRSTR_ARM7         (BASE_ADDR_RSTCTL+0x0150)
#define REG_MDRSTCTL_SRSTR_APMCU        (BASE_ADDR_RSTCTL+0x0154)
#define REG_MDRSTCTL_SRSTR_APPERI       (BASE_ADDR_RSTCTL+0x0158)
#define REG_MDRSTCTL_SRSTR_SSUSB        (BASE_ADDR_RSTCTL+0x015C)
#define REG_MDRSTCTL_SRSTR_APON         (BASE_ADDR_RSTCTL+0x0160)
#define REG_MDRSTCTL_EXTRST		        (BASE_ADDR_RSTCTL+0x0164)
#define REG_MDRSTCTL_RESET_UNLOCK       (BASE_ADDR_RSTCTL+0x0168)


#define REG_MDRSTCTL_SRCMR              (BASE_ADDR_RSTCTL+0x0300)
#define REG_MDRSTCTL_SRCMR_SWDT    		(BASE_ADDR_RSTCTL+0x0304)
#define REG_MDRSTCTL_SRBER_MDON         (BASE_ADDR_RSTCTL+0x0308)
#define REG_MDRSTCTL_SRBER_MDMCU        (BASE_ADDR_RSTCTL+0x030C)
#define REG_MDRSTCTL_SRBER_MDINFRA      (BASE_ADDR_RSTCTL+0x0310)
#define REG_MDRSTCTL_SRBER_LTEL2        (BASE_ADDR_RSTCTL+0x0314)
#define REG_MDRSTCTL_SRBER_MEMSYS       (BASE_ADDR_RSTCTL+0x0318)
#define REG_MDRSTCTL_SRBER_ARM7         (BASE_ADDR_RSTCTL+0x031C)
#define REG_MDRSTCTL_SRBER_APMCU        (BASE_ADDR_RSTCTL+0x0320)
#define REG_MDRSTCTL_SRBER_APPERI       (BASE_ADDR_RSTCTL+0x0324)
#define REG_MDRSTCTL_SRBER_SSUSB        (BASE_ADDR_RSTCTL+0x0328)
#define REG_MDRSTCTL_SRBER_APON         (BASE_ADDR_RSTCTL+0x032C)


#define REG_MDRSTCTL_DUMMY      (BASE_ADDR_MDRSTCTL+0x0040)

#define _RST_DURATION_LOOP_DEFAULT_VALUE	(100)		/* Just a magic number for reset duration */
/**< REG_MDRSTCTL_SRCMR */
#define RSTCTL_SRCMR_KEY_SWDT_MASK			(0xffff)		/* Key of reset command */
#define RSTCTL_SRCMR_KEY_SWDT_OFFSET		(16)
#define RSTCTL_SRCMR_KEY_SWDT				((0x1688 << RSTCTL_SRCMR_KEY_SWDT_OFFSET) | 0x1)	/* Key to enable software watch dog reset */
#define RSTCTL_SRCMR_KEY_SWRST				((0x2593 << RSTCTL_SRCMR_KEY_SWDT_OFFSET) | 0x1)	/* Key to enable software reset */
/**< REG_MDRSTCTL_SRBER */
#define RSTCTL_SRBER_MDON_MASK			(0xFFFFFFFF)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_SDCTL_RST				(1 << 0)		/**< Soft reset of SDCLT :  */
#define RSTCTL_SRBER_MDGDMA_RST				(1 << 1)		/**< Soft reset of L2COP : only valid for MDARM */
#define RSTCTL_SRBER_USIM0_RST				(1 << 2)		/**< Soft reset of USIM0 : only valid for MDARM */
#define RSTCTL_SRBER_USIM1_RST				(1 << 3)		/**< Soft reset of USIM1 : only valid for MDARM */
#define RSTCTL_SRBER_MDUART_RST				(1 << 4)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_SUART0_RST				(1 << 5)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_SUART1_RST				(1 << 6)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_MDGPTM_RST				(1 << 7)		/**< Soft reset of UART : only valid for MDARM */
//#define RSTCTL_SRBER_MDGPIO_RST				(1 << 8)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_MDMISC_RST				(1 << 9)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDCIRQ_RST				(1 << 10)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_LED_RST				(1 << 11)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_I2C_RST				(1 << 12)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_SDCTL_CIS_RST			(1 << 13)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_DBGSYS_RST				(1 << 14)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_DBGCV_RST				(1 << 15)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_DBGSIB_RST				(1 << 16)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_GPIOMUX_RST			(1 << 17)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APTOPSM_RST			(1 << 18)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDTOPSM_RST			(1 << 19)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APOST_RST				(1 << 20)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDOST_RST				(1 << 21)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDCFGCTL_RST			(1 << 22)		/**< FPGA0827 add  */
#define RSTCTL_SRBER_DRAMC_AO_RST			(1 << 23)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_EMI_AO_RST				(1 << 24)		/**< Soft reset of MISC :  */

//#define RSTCTL_SRBER_NLIPAD_RST				(1 << 22)		/**< Soft reset of MISC :  */

#define RSTCTL_SRBER_ARM7_MASK			(0xC0000003)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_ARM7_HRST_RST			(1 << 0)		/**< Soft reset of ARM7_HRST  */
#define RSTCTL_SRBER_ARM7_SRST_RST			(1 << 1)		/**< Soft reset of ARM7_SRST  */
#define RSTCTL_SRBER_CAIF_RST			(1 << 3)		/**< Soft reset of ARM7_CIRQ  */
#define RSTCTL_SRBER_ARM7SYS_RST            (RSTCTL_SRBER_ARM7_HRST_RST|RSTCTL_SRBER_ARM7_SRST_RST|RSTCTL_SRBER_CAIF_RST)


#define RSTCTL_SRBER_LTEL2_MASK			(0xC0000001)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_LTEL2_RST				(1 << 0)		/**< Soft reset of MISC :  */

#define RSTCTL_SRBER_MEMSYS_MASK		(0xC000003F)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_DRAMC_RST				(1 << 0)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_EMI_RST				(1 << 1)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_CPHY_RST				(1 << 2)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_DDRPHY_COMB0_RST		(1 << 3)		/**< Soft reset of MISC :  */


#define RSTCTL_SRBER_MDINFRA_MASK		(0xC0000003)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_MDINFRA_MISC_RST		(1 << 0)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDINFRA_BUSMON_RST		(1 << 1)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_BOOTROM_RST			(1 << 2)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_ABM_RST				(1 << 3)		/**< Soft reset of MISC :  */


#define RSTCTL_SRBER_MDMCU_MASK			(0xC00000FF)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_CR4_DBG_RST			(1 << 0)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_CR4_NRESET_RST			(1 << 1)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_CR4_BUSMON_RST			(1 << 2)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_ALC_RST				(1 << 3)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_PF_RST					(1 << 4)		/**< Soft reset of MISC :  */
//#define RSTCTL_SRBER_MDMCU_MISC_RST			(1 << 5)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_PCMON_FIFO_RST			(1 << 6)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_PCMON_REG_RST			(1 << 7)		/**< Soft reset of MISC :  */



#define RSTCTL_SRBER_APON_MASK			(0xC000000F)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_AP_RSTMD_RST			(1 << 1)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MDCLK_RST				(1 << 2)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APCLK_RST				(1 << 3)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_EFUSE_RST				(1 << 4)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MML1_RST				(1 << 5)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MML1OFF_RST			(1 << 6)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_TDD_RST				(1 << 7)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_2G3G_RST				(1 << 8)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_2G3G_DSP_RST			(1 << 9)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_EXT_RST_RST			(1 << 10)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_BSICTL					(1 << 11)
#define RSTCTL_SRBER_RFIC1_BSISPI			(1 << 12)
#define RSTCTL_SRBER_RFIC2_BSISPI			(1 << 13)
#define RSTCTL_SRBER_PMIC_BSISPI			(1 << 14)
#define RSTCTL_SRBER_MIPI0_BSISPI			(1 << 15)
#define RSTCTL_SRBER_MIPI1_BSISPI			(1 << 16)
#define RSTCTL_SRBER_IDC					(1 << 17)
#define RSTCTL_SRBER_MML1_BPICTRL			(1 << 18)
#define RSTCTL_SRBER_MML1_PERISYS_MISC		(1 << 19)
#define RSTCTL_SRBER_MML1_PERI_MBIST_CONFIG	(1 << 20)
#define RSTCTL_SRBER_AUXADC					(1 << 21)
#define RSTCTL_SRBER_MML1_PERISYS11			(1 << 22)
#define RSTCTL_SRBER_MML1_PERISYS12			(1 << 23)
#define RSTCTL_SRBER_MML1_PERISYS13			(1 << 24)
#define RSTCTL_SRBER_MML1_PERISYS14			(1 << 25)
#define RSTCTL_SRBER_MML1_PERISYS_XRESET	(1 << 26)
#define RSTCTL_SRBER_MIXEDSYS				(1 << 27)



#define RSTCTL_SRBER_SSUSB_MASK			(0xC0000001)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_SSUSB_RST				(1 << 0)		/**< Soft reset of MISC :  */

#define RSTCTL_SRBER_APPERI_MASK		(0xC00DDFFF)		/**< Mask of software reset modules for RSTCTL_SSRR control */
#define RSTCTL_SRBER_APUART_RST				(1 << 0)		/**< Soft reset of SDCLT :  */
#define RSTCTL_SRBER_APCCIF_RST				(1 << 1)		/**< Soft reset of L2COP : only valid for MDARM */
#define RSTCTL_SRBER_CLDMA_RST				(1 << 2)		/**< Soft reset of USIM0 : only valid for MDARM */
#define RSTCTL_SRBER_NFI_RST				(1 << 3)		/**< Soft reset of USIM1 : only valid for MDARM */
#define RSTCTL_SRBER_SF_RST					(1 << 4)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_USB_RST				(1 << 5)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_IPSEC_RST				(1 << 6)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_HIF0_RST				(1 << 7)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_PFC_RST				(1 << 8)		/**< Soft reset of UART : only valid for MDARM */
#define RSTCTL_SRBER_NLI_RST				(1 << 9)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MSDC0P_RST				(1 << 10)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_MSDC1P_RST				(1 << 11)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APGPTM_RST				(1 << 12)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APEHPI_RST				(1 << 13)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APGDMA_RST				(1 << 14)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_AP_BUSMON_RST			(1 << 15)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_AP_MISC_RST			(1 << 16)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_APTZCTL_RST			(1 << 17)		/**< FPGA0827 remove  */
#define RSTCTL_SRBER_ETHER_NIC_RST			(1 << 18)		/**< Soft reset of MISC :  */
#define RSTCTL_SRBER_TRACE_RST				(1 << 19)		/**< Soft reset of MISC :  */


#define RSTCTL_SRBER_CA7_DBG_RST			(1 << 0)		/**< Soft reset of SDCLT :  */
#define RSTCTL_SRBER_CA7_NRESET_RST			(1 << 1)		/**< Soft reset of L2COP : only valid for MDARM */
#define RSTCTL_SRBER_CA7_BUSMON_RST			(1 << 2)		/**< Soft reset of USIM0 : only valid for MDARM */


#define RSTCTL_SRSTR_MASK					(0x3f0fffff)
/**< REG_MDRSTCTL_WDTCR */
#define RSTCTL_WDTCR_KEY_CONTROL_MASK		(0xff)		/* Key of control setting */
#define RSTCTL_WDTCR_KEY_CONTROL_OFFSET		(24)
#define RSTCTL_WDTCR_KEY					(0x55 << RSTCTL_WDTCR_KEY_CONTROL_OFFSET)
#define RSTCTL_WDTCR_HF_RSTQMU				(1 << 15)	/* Reset QMU or not for host-functional-reset (Only valid in modem configuration) */
#define RSTCTL_WDTCR_WDT_RSTNTY				(1 << 14)	/* Notify HIF or not when watchdog-reset occurs (Only valid in modem configuration) */
#define RSTCTL_WDTCR_RST_TARGET_MASK		(0x1fff)		/* Target mask of watchdog reset (detail definition is in rst_ioctl_wdt_MD_target_e) */
#define RSTCTL_WDTCR_RST_TARGET_OFFSET		(3)
#define RSTCTL_WDTCR_WDT_IRQEN				(1 << 3)		/* Watch dog timer interrupt enable (select "intterrupt" or "reset" when watch dog timeout) */
#define RSTCTL_WDTCR_WDT_EN					(1<< 0)		/* watch dog timer enable */
/**< REG_MDRSTCTL_WDTSR */
#define RSTCTL_WDTSR_KEY_MASK				0xffff		/* Key of status clear */
#define RSTCTL_WDTSR_KEY_OFFSET				16
#define RSTCTL_WDTSR_KEY					(0x7662 << RSTCTL_WDTSR_KEY_OFFSET)
#define RSTCTL_WDTSR_STATUS_MASK			0x1F		/* Watchdog status (detail definition is in rst_ioctl_wdt_status_e) */
#define RSTCTL_WDTSR_STATUS_OFFSET			0
#define RSTCTL_WDTSR_STS_CLR_MASK			0X07		/* CLR_AP_OSTT_STS(bit5), CLR_AP_SWDT_STS(bit4), CLR_AP_HWDT_STS(bit3) */
#define RSTCTL_WDTSR_STS_CLR_OFFSET			3
#define RSTCTL_WDTSR_CNT_CLR_MASK		    0x3
#define RSTCTL_WDTSR_CNT_CLR_OFFSET		    6
/**< REG_MDRSTCTL_WDTIR */
#define RSTCTL_WDTIR_KEY_INTV_MASK			0xff		/* Key of interval setting */
#define RSTCTL_WDTIR_KEY_INTV_OFFSET		24
#define RSTCTL_WDTIR_KEY					(0x67 << RSTCTL_WDTIR_KEY_INTV_OFFSET)
#define RSTCTL_WDTIR_INTERVAL_MASK			0x3FFFFF		/* Watch dog timer down count interval (the real interval is 1/32.768k */
#define RSTCTL_WDTIR_INTERVAL_OFFSET		0
/**< REG_MDRSTCTL_WDTRR */
#define RSTCTL_WDTRR_KEY_RESTART_MASK		0xffff		/* Key of watchdog couter restarting */
#define RSTCTL_WDTRR_KEY_RESTART_OFFSET		16
#define RSTCTL_WDTRR_KEY					(0x7208 << RSTCTL_WDTRR_KEY_RESTART_OFFSET)
/**< REG_MDRSTCTL_EXTRST */
#define RSTCTL_EXTRST_KEY					(0x7766 << 16)
#define EXT_WDT_STS                         (1 << 15)
#define EXTRST_OE                           (1 << 1)
#define POLARITY_OFFSET                     0


#elif defined(MT6595)

#define SW_RST_READ_STATUS_SHITF_8
#define BASE_MADDR_RSTCTL	(MD_RGU_BASE)


#define REG_WDT_MD_MODE              (BASE_MADDR_RSTCTL+0x0000)
#define REG_WDT_MD_LENGTH            (BASE_MADDR_RSTCTL+0x0004)
#define REG_WDT_MD_RESTART           (BASE_MADDR_RSTCTL+0x0008)
#define REG_WDT_MD_STA               (BASE_MADDR_RSTCTL+0x000C)
#define REG_WDT_SW_DSP_RSTN          (BASE_MADDR_RSTCTL+0x0014)
#define REG_WDT_MD_SWRST             (BASE_MADDR_RSTCTL+0x001C)
#define REG_WDT_SW_GRP0_RST          (BASE_MADDR_RSTCTL+0x0020)
#define REG_WDT_SW_GRP1_RST          (BASE_MADDR_RSTCTL+0x0024)

#define REG_WDT_RETN_FLAG            (BASE_MADDR_RSTCTL+0x0800)
#define REG_WDT_RETN_SET             (BASE_MADDR_RSTCTL+0x0804)
#define REG_WDT_RETN_CLR             (BASE_MADDR_RSTCTL+0x0808)
#define REG_WDT_RETN_DAT0            (BASE_MADDR_RSTCTL+0x0814)


#define RSTCTL_MAX_PERIOD_NUM              (0x7FF)

#define RSTCTL_MD_MODE_KEY             (0x22 << 8)
#define RSTCTL_MD_LENGTH_KEY           (0x8)
#define RSTCTL_RESTART_TIMER_KEY       (0x1971)
#define RSTCTL_MDSYS_SWRST_KEY         (0x1209)
#define RSTCTL_DSP_RST_KEY             (0x22)
#define RSTCTL_GRP0_RST_KEY            (0x5A << 24)
#define RSTCTL_GRP1_RST_KEY            (0x5A << 24)
#define RSTCTL_RETN_FLAG_SET_KEY       (0x4e << 24)

/*REG_WDT_MD_MODE*/
#define	RSTCTL_IRQ_MODE_BIT            (3)
#define	RSTCTL_SEL_32K_BIT             (1)
#define	RSTCTL_WDT_EN_BIT              (0)

/*REG_WDT_MD_LENGTH*/
#define RSTCTL_TIMEOUT_BIT             (5)

/*For easy implementation, move these two definition to drv_rstctl.h*/
/*REG_WDT_MD_STA*/
//#define RSTCTL_STA_WDT_BIT             (15)
//#define RSTCTL_STA_SW_WDT_BIT          (14)

/*REG_WDT_SW_DSP_RSTN*/
#define	RSTCTL_2GDSP_BIT               (15)
/*REG_WDT_SW_GRP0_RST*/
#define	RSTCTL_CLDMA_BIT               (6)
#define	RSTCTL_PCMON_REG_BIT           (5)
#define	RSTCTL_PCMON_FIFO_BIT          (4)
#define	RSTCTL_LTEL2_BIT               (3)
#define	RSTCTL_A7_CCIF_BIT             (2)
#define	RSTCTL_A7_SRST_BIT             (1)
#define	RSTCTL_A7_RSTUNLOCK_BIT        (15)
#define	RSTCTL_A7_HRST_BIT             (0)
/*REG_WDT_SW_GRP1_RST*/
#define	RSTCTL_MML1STS_BIT             (16)
#define	RSTCTL_XRESET_BIT              (15)
#define	RSTCTL_MML1_PERI_MBIST_BIT     (9)
#define	RSTCTL_MML1_PERI_MISC_BIT      (8)
#define	RSTCTL_MML1_BPICTRL_BIT        (7)
#define	RSTCTL_IDC_BIT                 (6)
#define	RSTCTL_MIPI1_BSISPI_BIT        (5)
#define	RSTCTL_MIPI0_BSISPI_BIT        (4)
#define	RSTCTL_PMIC_BSISPI_BIT         (3)
#define RSTCTL_RFIC2_BSISPI_BIT        (2)
#define	RSTCTL_RFIC1_BSISPI_BIT        (1)
#define	RSTCTL_PF_BSICTRL_BIT          (0)

//#endif /*Remove for not using*/
/*TMD*/
#else
#error Not support rstctrl in this chip type
#endif /*MT6290*/

#endif /* end of __GPT_REG_H__ */

