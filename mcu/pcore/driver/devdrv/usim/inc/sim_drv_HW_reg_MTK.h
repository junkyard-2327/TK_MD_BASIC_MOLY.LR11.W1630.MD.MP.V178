#ifndef __SIM_DRV_HW_REG_MTK_H__
#define __SIM_DRV_HW_REG_MTK_H__

#include "reg_base.h"

//#if ( (!defined(MT6208)) && (!defined(FPGA)) && (!defined(MT6205)) && (!defined(MT6205B)) && (!defined(MT6218)) )
#if !defined(DRV_SIM_REG_6208_SERIES) && !defined(DRV_SIM_REG_6205B_SERIES)
/*MT6218B || MT6219 || MT6217 || MT6226 || MT6227 || MT6228 || MT6229*/
	#ifdef SIM_NAMING_FROM_0_ADDRESS

	#ifdef SIM_base
  #undef SIM_base
	#endif
  #define SIM_base SIM0_base

	#ifdef SIM2_base
  #undef SIM2_base
	#endif
  #define SIM2_base SIM1_base

	#endif //SIM_NAMING_FROM_0_ADDRESS


   #define 	ACK_NULL_CHAR		0x60
   
   #define 	SIM_CTRL		   (SIM_base+0x0)
   #define 	SIM_CONF		   (SIM_base+0x4)
   #define 	SIM_BRR			(SIM_base+0x8)
   #define 	SIM_IRQEN		(SIM_base+0x10)
   #define 	SIM_STS			(SIM_base+0x14)
   
   #define 	SIM_RETRY		(SIM_base+0x20)
   #define 	SIM_TIDE	   	(SIM_base+0x24)
  
   #define 	SIM_DATA		   (SIM_base+0x30)
   #define 	SIM_COUNT		(SIM_base+0x34)
   
   #define 	SIM_ATIME		(SIM_base+0x40)
   #define 	SIM_DTIME		(SIM_base+0x44)
   #define 	SIM_TOUT		   (SIM_base+0x48)
   
   #define 	SIM_INS  		(SIM_base+0x60)
   #define 	SIM_IMP3  		(SIM_base+0x64)
   #define 	SIM_SW1  		(SIM_base+0x68)
   #define 	SIM_SW2  		(SIM_base+0x6c)
   #define 	SIM_REG_STATUS		(SIM_base+0x74)


   /*
   	This is the most important define to combine single SIM and multiple SIM macro.
   	In DRV_SIM_ALL_SOLUTION_BUILT, single SIM driver's macro will use this variable, too.
   	DRV_SIM_BUILD_SINGLE_SIM is only defined in simd.c and usim_drv.c before including this header file.
   */
extern kal_uint32 simBaseAddr, simBaseAddrSpace;
#ifdef DRV_SIM_BUILD_SINGLE_SIM
#define	SIM0_BASE_ADDR_MTK	(simBaseAddr )
#else
   /*in DRV_SIM_ALL_SOLUTION_BUILT, we use two variables, starting address and adress space, to calculate the actual address*/
   //#define	SIM0_BASE_ADDR_MTK	(simBaseAddr + (simBaseAddrSpace * simInterface))
   #define	SIM0_BASE_ADDR_MTK	(hw_cb->mtk_baseAddr)
#endif

   // MTK04122: updated for MT6290
   #define 	SIM_VERSION_MTK		   	0x0
   #define 	SIM_CTRL_MTK		   	0x10
   #define 	SIM_CONF_MTK		   	0x14
   #define  SIM_CONFSTA_MTK         0x18
   #define 	SIM_BRR_MTK			    0x1C
   #define 	SIM_IRQEN_MTK			0x20
   #define 	SIM_STS_MTK			    0x24
   
   #define 	SIM_RETRY_MTK			0x30
   #define 	SIM_TIDE_MTK	   		0x34
  
   #define 	SIM_DATA_MTK		   	0x40
   #define 	SIM_COUNT_MTK			0x44
   
   #define 	SIM_ATIME_MTK			0x50
   #define 	SIM_DTIME_MTK			0x54
   #define 	SIM_TOUT_MTK		   	0x58

   #define  SIM_GTIME_MTK           0x5C
   #define  SIM_ETIME_MTK           0x60
   #define  SIM_EXT_TIME_MTK        0x64
   #define  SIM_CGTIME_MTK          0x68
   
   
   /********************/
   //MTK04122: be removed in mt6290
   #define 	SIM_INS_MTK  			0x60
   #define 	SIM_IMP3_MTK  			0x64
   /********************/

   #define  SIM_COMDCTRL_MTK        0x70
   #define  SIM_COMDLEN_MTK         0x74
   #define  SIM_LEFTLEN_MTK         0x78
   
   #define 	SIM_SW1_MTK  			0x7C
   #define 	SIM_SW2_MTK  			0x80

   #define  SIM_ATRSTA_MTK          0x90
   #define 	SIM_STATUS_MTK		    0x94
   #define	SIM_DBG_MTK		0x98

   
   //SIM_CTRL
   #define 	SIM_CTRL_SIMON		   0x0001
   #define 	SIM_CTRL_HALT		   0x0002   /* Enable Clk stop mode or disable */
   #define	SIM_CTRL_WRST		   0x0004	/* Trigger a warm reset */
   #define  SIM_CTRL_RSTLV         0x0008 
   #define  SIM_CTRL_RSTCTRL       0x0010
   #define  SIM_CTRL_IFCLR         0x0020

   //SIM_CONF
   #define 	SIM_CONF_RXHSK		   0x0001
   #define 	SIM_CONF_TXHSK		   0x0002
   #define 	SIM_CONF_CLKPO		   0x0004
   
   /********************/
   //MTK04122: be removed in mt6290
   #define 	SIM_CONF_SINV		   0x0008
   #define 	SIM_CONF_SDIR		   0x0010
   #define 	SIM_CONF_ODDPARITY	   0x0020
   
   #define  SIM_CONF_Direct		   0x0000
   #define  SIM_CONF_InDirect	   0x0038
   /********************/
   #define 	SIM_CONF_CONV          0x0008
   
   #define 	SIM_CONF_SIMSEL		   0x0010
   #define 	SIM_CONF_TOUTEN		   0x0020
   #define 	SIM_CONF_T1EN		   0x0040
   #define 	SIM_CONF_T0EN		   0x0080
   #define 	SIM_CONF_HFEN		   0x0100
   #define  SIM_CONF_RXRDIS        0x0200
   #define  SIM_CONF_TXRDIS        0x0400
   #define  SIM_CONF_T1TX2RXEN     0x0800
   
   //SIM_CONFSTA
   #define  SIM_CONFSTA_IFCLR_ON   0x0001
   #define  SIM_CONFSTA_TXRDIS_S   0x0400  
   
   //SIM_BRR
   #define 	SIM_BRR_CLKMSK		      0x0003
   
   /********************/
   //MTK04122: be removed in mt6290
   #define 	SIM_BRR_CLK_Div2	      0x0000
   /********************/
   
   #define 	SIM_BRR_CLK_Div4	      0x0001
   #define 	SIM_BRR_CLK_Div8	      0x0002
   #define 	SIM_BRR_CLK_Div12	      0x0003
   
   #define 	SIM_BRR_ETUMSK		      0x07FC
   
   //MTK04122:need to clarify
   #define 	SIM_BRR_BAUDMSK			  0x000C     
   
//#if ( (defined(MT6218B)) || (defined(MT6219)))
#if defined(DRV_SIM_REG_BAUD_6218B_SERIES)
   #define 	SIM_BRR_BAUD_Div372		(0x16<<2)		//F=372, D=1
   #define 	SIM_BRR_BAUD_Div64		(0x03<<2)		//F=512, D=8
   #define 	SIM_BRR_BAUD_Div32		(0x01<<2)		//F=512, D=16
#else /*!Mt6218B,MT6219, MT6290*/
   #define 	SIM_BRR_BAUD_Div372		(372<<2)		//F=372, D=1
   #define 	SIM_BRR_BAUD_Div64		(64<<2)		    //F=512, D=8
   #define 	SIM_BRR_BAUD_Div32		(32<<2)		    //F=512, D=16
   #define	SIM_BRR_BAUD_Div16		(16<<2)		    //F=512,D=32
   #define	SIM_BRR_BAUD_Div8		(8<<2)		    //F=512,D=64
#endif   /*MT6218B,MT6219*/

   //SIM_IRQEN
   #define 	SIM_IRQEN_TX		      0x0001
   #define 	SIM_IRQEN_RX		      0x0002
   #define 	SIM_IRQEN_OV		      0x0004
   #define 	SIM_IRQEN_TOUT		      0x0008
   #define 	SIM_IRQEN_TXERR		      0x0010
   #define 	SIM_IRQEN_NATR		      0x0020
   #define 	SIM_IRQEN_SIMOFF          0x0040
   #define 	SIM_IRQEN_T0END           0x0080
   #define 	SIM_IRQEN_RXERR           0x0100
   #define  SIM_IRQEN_T1END           0x0200
   #define  SIM_IRQEN_EDCERR          0x0400
   #define  SIM_IRQEN_UDRUN           0x0800

   /*TX, RX ,OV, TOUT, TXER, NATR, SIMOFF, RXER*/
   #define 	SIM_IRQEN_ALL		      0x01bf    
   #define 	SIM_IRQEN_ALLOFF	      0x0000
   
   /* SIM_IRQEN_RXErr, SIM_IRQEN_TXErr, SIM_IRQEN_NATR, SIM_IRQEN_TOUT, SIM_IRQEN_OV, SIM_IRQEN_RX*/
   #define 	SIM_IRQEN_Normal	      0x013e
   
   /*SIM_IRQEN_RXERR, SIM_IRQEN_T0END,SIM_IRQEN_TXErr, SIM_IRQEN_TOUT, SIM_IRQEN_OV, SIM_IRQEN_RX*/		
   #define 	SIM_IRQEN_CMDNormal	   0x019e
   /*#define 	SIM_IRQEN_CMDNormal	   0x019c*/

   /*SIM_IRQEN_RXERR, SIM_IRQEN_T0END,SIM_IRQEN_TXErr, SIM_IRQEN_TOUT, SIM_IRQEN_OV*/
   #define 	SIM_IRQEN_CMDDMANormal	   0x019c
   
   #define	USIM_IRQEN_ATR				(SIM_IRQEN_RX|SIM_IRQEN_NATR)
   #define 	USIM_IRQEN_NORMAL			(SIM_STS_RX|SIM_STS_OV|SIM_STS_TOUT|SIM_STS_TXERR|SIM_STS_RXERR)
   #define 	USIM_IRQEN_CMD_T1			(SIM_STS_EDCERR|SIM_STS_T1END|SIM_STS_RXERR| \
   											SIM_STS_OV|SIM_STS_TOUT)
   #define 	USIM_IRQEN_CMD_T1_RX		(SIM_STS_EDCERR|SIM_STS_T1END|SIM_STS_OV|SIM_STS_TOUT|SIM_STS_RX)   
   #define 	USIM_IRQEN_CMD_T1_TX		(SIM_STS_T1END)
   
   //SIM_STS
   #define 	SIM_STS_TX		         0x0001
   #define 	SIM_STS_RX		         0x0002
   #define 	SIM_STS_OV		         0x0004
   #define 	SIM_STS_TOUT		     0x0008
   #define 	SIM_STS_TXERR		     0x0010
   #define 	SIM_STS_NATR		     0x0020
   #define 	SIM_STS_SIMOFF		     0x0040
   #define 	SIM_STS_T0END            0x0080
   #define 	SIM_STS_RXERR            0x0100
   #define 	SIM_STS_T1END			 0x0200
   #define	SIM_STS_EDCERR			 0x0400
   #define  SIM_STS_UDRUN            0x0800
   
   //SIM_TOUT
   #define 	SIM_TOUT_MSK		      0x3fff //??
   
   //SIM_RETRY
   #define 	SIM_RETRY_RXMASK	      0x0007
   #define 	SIM_RETRY_TXMASK	      0x0700
   
   //SIM_TIDE
   #define 	SIM_TIDE_RXMASK		   0x000f
   #define 	SIM_TIDE_TXMASK		   0x0f00
   
   //SIM_COUNT
   #define 	SIM_COUNT_MASK		      0x001f
   
   //SIM_COMDCTRL: shall be re-named
   #define 	SIM_INS_MASK  		      0x00ff
   #define 	SIM_INS_INSD  		      0x0100
   #define 	SIM_INS_START  		      0x8000
   
   //SIM_COMDLEN
   #define  SIM_IMP3_MASK           0x00ff

   //SIM_ATRSTA
   #define  SIM_ATRSTA_OFF		0x0001
   #define  SIM_ATRSTA_IR		0x0080
   #define  SIM_ATRSTA_AL		0x0100
   
   /*MTK04122: to be update for mt6290 (TBC)*/
   // SIM_STATUS 
   #define	SIM_STATUS_EDC				0x40
   #define	SIM_STATUS_ACK				0x20
   #define 	SIM_STATUS_NACK			    0x10
   #define	SIM_STATUS_IDLE			    0x01
   #define	SIM_STATUS_INS				0x02
   #define	SIM_STATUS_SW1				0x04
   #define	SIM_STATUS_SW2				0x08

   #define SIM_TX_DELAY_LEN			0x4
   #define SIM_TX_DELAY_LOOP			4000

  /*
    *  HDMA Register Definitions
    */
   #define BASE_HDMA BASE_ADDR_MDGDMA  
   #define REG_HDMA_HDCSR0        (BASE_HDMA + 0x0100) 
     #define HDMA_MODE_0             (1 << 9)        //channel 0
     #define HDMA_MODE_1             (1 << 25)       //channel 1
   #define REG_HDMA_HDSR          (BASE_HDMA + 0x0120) // shared
     #define HDMA_STAT0_0            (1 << 0)   // buffer 0, channel 0
     #define HDMA_STAT0_1            (1 << 1)   // buffer 0, channel 1
     #define HDMA_STAT1_0            (1 << 16)  // buffer 1, channel 0
     #define HDMA_STAT1_1            (1 << 17)  // buffer 1, channel 1
   #define REG_HDMA_HDCPR         (BASE_HDMA + 0x0124) // shared
     #define HDMA_HCURR_PTR_0        (1 << 0)   // channel 0
     #define HDMA_HCURR_PTR_1        (1 << 1)   // channel 1
   #define REG_HDMA_HDCTRR0       (BASE_HDMA + 0x0140) // channel 0
   #define REG_HDMA_HDCTRR1       (BASE_HDMA + 0x0160) // channel 1
     #define HDCTRR_STOP             (1 << 2)
     #define HDCTRR_MEM_BUS_WIDTH(n) ((n) << 4)
     #define HDCTRR_DEV_BUS_WIDTH(n) ((n) << 6)
        #define HDCTRR_BUS_WIDTH_8          0
        #define HDCTRR_BUS_WIDTH_16         1
        #define HDCTRR_BUS_WIDTH_32         2
     #define HDCTRR_BST_SIZE(n)      ((n) << 13)
        #define HDCTRR_BST_SIZE_4           2
        #define HDCTRR_BST_SIZE_8           3
        #define HDCTRR_BST_SIZE_16          4
        #define HDCTRR_BST_SIZE_32          5 // reserved
        #define HDCTRR_BST_SIZE_64          6 // reserved
        #define HDCTRR_BST_SIZE_128         7 // reserved
     #define HDCTRR_RX_SEL0(n)       ((n) << 30)
     #define HDCTRR_RX_SEL1(n)       ((n) << 31)
   #define REG_HDMA_HDC0R0        (BASE_HDMA + 0x0144) // channel 0
   #define REG_HDMA_HDC0R1        (BASE_HDMA + 0x0164) // channel 1
     #define HDCR_XFER_SIZE0(n)      ((n) << 16)
     #define HDCR_START0             (1 << 0)
   #define REG_HDMA_HDC1R0        (BASE_HDMA + 0x0148) // channel 0
   #define REG_HDMA_HDC1R1        (BASE_HDMA + 0x0168) // channel 1
     #define HDCR_XFER_SIZE1(n)      ((n) << 16)
     #define HDCR_START1             (1 << 0)
   #define REG_HDMA_HPRGA0R0      (BASE_HDMA + 0x014C) // channel 0
   #define REG_HDMA_HPRGA0R1      (BASE_HDMA + 0x016C) // channel 1
   #define REG_HDMA_HPRGA1R0      (BASE_HDMA + 0x0150) // channel 0
   #define REG_HDMA_HPRGA1R1      (BASE_HDMA + 0x0170) // channel 1
   #define REG_HDMA_HCCR0         (BASE_HDMA + 0x0154) // channel 0
   #define REG_HDMA_HCCR1         (BASE_HDMA + 0x0174) // channel 1
     #define HDMA_HCURR_CNT0         0x0000FFFF
     #define HDMA_HCURR_CNT1         0xFFFF0000
   #define REG_HDMA_HDCPR0        (BASE_HDMA + 0x0158) // channel 0
   #define REG_HDMA_HDCPR1        (BASE_HDMA + 0x0178) // channel 1
   
#endif   /*MT6218B*/

#if defined(MT6595)
#define REG_SIM1_PU_PD_SEL	(GPIO_base + 0xE40)
#define REG_SIM2_PU_PD_SEL	(GPIO_base + 0xE50)
	#define	SIMx_PU_PD_HZ	0x0
	#define	SIMx_PU_PD_10K	0x1
	#define	SIMx_PU_PD_50K	0x2
	#define	SIMx_PU_PD_8_3K	0x3
	#define	SIMx_PD_SEL	0x4
	#define	SIMx_INS	0x888
	#define	SIMx_CLK	0x0
	#define	SIMx_DAT	0x4
	#define	SIMx_RST	0x8

#define ENABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_SIM2_PU_PD_SEL, (DRV_Reg32(REG_SIM2_PU_PD_SEL) | SIMx_INS));} \
	else{DRV_WriteReg32(REG_SIM1_PU_PD_SEL, (DRV_Reg32(REG_SIM1_PU_PD_SEL) | SIMx_INS));}

#define DISABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_SIM2_PU_PD_SEL, (DRV_Reg32(REG_SIM2_PU_PD_SEL) & ~(SIMx_INS)));} \
	else{DRV_WriteReg32(REG_SIM1_PU_PD_SEL, (DRV_Reg32(REG_SIM1_PU_PD_SEL) & ~(SIMx_INS)));}
#elif defined(MT6752) && defined(__MD1__)
#define IOCFG_T_base		0xA0002C00
#define IOCFG_R_base		0xA0002800

#define REG_SR_CFG0		(IOCFG_T_base + 0x010)
	#define SR_CFG_SIM1_MASK	0x6
#define REG_PULLEN_CFG0		(IOCFG_T_base + 0x050)
	#define PULLEN_CFG_SIM1_SCLK_R0	0x01000
	#define PULLEN_CFG_SIM1_SRST_R0	0x02000
	#define PULLEN_CFG_SIM1_SIO_R0	0x04000
	#define PULLEN_CFG_SIM1_SCLK_R1	0x08000
	#define PULLEN_CFG_SIM1_SRST_R1	0x10000
	#define PULLEN_CFG_SIM1_SIO_R1	0x20000
	#define PULLEN_CFG_SIM1_MASK	0x3F000
#define REG_T_INS_CFG0		(IOCFG_T_base + 0x080)
	#define INS_CFG_SIMx		0x7

#define SET_SIM1_SR(_n) \
DRV_WriteReg32(REG_SR_CFG0, ((DRV_Reg32(REG_SR_CFG0) & (~SR_CFG_SIM1_MASK)) | (_n << 1)));

#define REG_SR_CFG1		(IOCFG_R_base + 0x030)
	#define SR_CFG_SIM2_MASK	0x300
#define REG_PULLEN_CFG2		(IOCFG_R_base + 0x0A0)
	#define PULLEN_CFG_SIM2_SCLK_R0	0x010
	#define PULLEN_CFG_SIM2_SRST_R0	0x020
	#define PULLEN_CFG_SIM2_SIO_R0	0x040
	#define PULLEN_CFG_SIM2_SCLK_R1	0x080
	#define PULLEN_CFG_SIM2_SRST_R1	0x100
	#define PULLEN_CFG_SIM2_SIO_R1	0x200
	#define PULLEN_CFG_SIM2_MASK	0x3F0
#define REG_R_INS_CFG0		(IOCFG_R_base + 0x100)

#define SET_SIM2_SR(_n) \
DRV_WriteReg32(REG_SR_CFG1, ((DRV_Reg32(REG_SR_CFG1) & (~SR_CFG_SIM2_MASK)) | (_n << 8)));

#define ENABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_R_INS_CFG0, (DRV_Reg32(REG_R_INS_CFG0) | INS_CFG_SIMx));} \
	else{DRV_WriteReg32(REG_T_INS_CFG0, (DRV_Reg32(REG_T_INS_CFG0) | INS_CFG_SIMx));}

#define DISABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_R_INS_CFG0, (DRV_Reg32(REG_R_INS_CFG0) & ~(INS_CFG_SIMx)));} \
	else{DRV_WriteReg32(REG_T_INS_CFG0, (DRV_Reg32(REG_T_INS_CFG0) & ~(INS_CFG_SIMx)));}

#elif defined(MT6735) && defined(__MD1__)
#define REG_GPIO_MODE17		(GPIO_base + 0x400)
	#define GPIO_160_MODE_MD_SIM2		0x00000049
	#define GPIO_160_MODE_MD_SIM1		0x00000092
	#define GPIO_160_MODE_MD_SIMx_MASK	0x000001FF
	#define GPIO_163_MODE_MD_SIM1		0x00011200
	#define GPIO_163_MODE_MD_SIM2		0x00022400
	#define GPIO_163_MODE_MD_SIMx_MASK	0x00077E00
#define REG_GPIO_PUPD1_G4	(GPIO_base + 0xC90)
	#define	SIM1_INS	0x08880000
	#define	SIM2_INS	0x00000888

#define ENABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_GPIO_PUPD1_G4, (DRV_Reg32(REG_GPIO_PUPD1_G4) | SIM2_INS));} \
	else{DRV_WriteReg32(REG_GPIO_PUPD1_G4, (DRV_Reg32(REG_GPIO_PUPD1_G4) | SIM1_INS));}

#define DISABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_GPIO_PUPD1_G4, (DRV_Reg32(REG_GPIO_PUPD1_G4) & ~(SIM2_INS)));} \
	else{DRV_WriteReg32(REG_GPIO_PUPD1_G4, (DRV_Reg32(REG_GPIO_PUPD1_G4) & ~(SIM1_INS)));}

#elif defined(TK6291)
#define REG_IOMUX_CFG_USIM1			(BASE_MADDR_IOMUX2 + 0x190)
#define REG_IOMUX_CFG_USIM2			(BASE_MADDR_IOMUX2 + 0x194)
	#define IOMUX_CFG_USIM_INS		0x00010000
	#define IOMUX_CFG_USIM_R1R0_MASK	0x0000C000
	#define IOMUX_CFG_USIM_R1		0x00008000
	#define IOMUX_CFG_USIM_R0		0x00004000
	#define IOMUX_CFG_USIM_SR_MASK		0x00003000
	#define IOMUX_CFG_USIM_SR_11		0x00003000
	#define IOMUX_CFG_USIM_SR_10		0x00002000

#define ENABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_IOMUX_CFG_USIM2, (DRV_Reg32(REG_IOMUX_CFG_USIM2) | IOMUX_CFG_USIM_INS));} \
	else{DRV_WriteReg32(REG_IOMUX_CFG_USIM1, (DRV_Reg32(REG_IOMUX_CFG_USIM1) | IOMUX_CFG_USIM_INS));}

#define DISABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_IOMUX_CFG_USIM2, (DRV_Reg32(REG_IOMUX_CFG_USIM2) & ~(IOMUX_CFG_USIM_INS)));} \
	else{DRV_WriteReg32(REG_IOMUX_CFG_USIM1, (DRV_Reg32(REG_IOMUX_CFG_USIM1) & ~(IOMUX_CFG_USIM_INS)));}

#define REG_GPIO_MODE_0_FOR_SIM		(BASE_MADDR_IOMUX2 + 0x114)
#define REG_GPIO_MODE_1_FOR_SIM		(BASE_MADDR_IOMUX2 + 0x114) // same
#define REG_GPIO_IES_0_FOR_SIM		(BASE_MADDR_IOMUX2 + 0x000) // N/A
#define REG_GPIO_IES_1_FOR_SIM		(BASE_MADDR_IOMUX2 + 0x000) // N/A
#define REG_GPIO_SMT_0_FOR_SIM		(BASE_MADDR_IOMUX2 + 0x000) // N/A
#define REG_GPIO_SMT_1_FOR_SIM		(BASE_MADDR_IOMUX2 + 0x000) // N/A
#define REG_GPIO_TDSEL_0_FOR_SIM	(BASE_MADDR_IOMUX2 + 0x190) // [9:6]
#define REG_GPIO_TDSEL_1_FOR_SIM	(BASE_MADDR_IOMUX2 + 0x194)
#define REG_GPIO_RDSEL_0_FOR_SIM	(BASE_MADDR_IOMUX2 + 0x190) // [5:0]
#define REG_GPIO_RDSEL_1_FOR_SIM	(BASE_MADDR_IOMUX2 + 0x194)
#define REG_GPIO_DRV_0_FOR_SIM		(BASE_MADDR_IOMUX2 + 0x190) // [11:10]
#define REG_GPIO_DRV_1_FOR_SIM		(BASE_MADDR_IOMUX2 + 0x194)
#define REG_GPIO_PUPD_0_FOR_SIM		(BASE_MADDR_IOMUX2 + 0x190) // [15:14}
#define REG_GPIO_PUPD_1_FOR_SIM		(BASE_MADDR_IOMUX2 + 0x194)

#elif defined(MT6755) || defined(MT6750S) // shall use this format afterall
#define GPIO_base 			0xC0005000
#define REG_GPIO_MODE_0_FOR_SIM		(GPIO_base + 0x330)
#define REG_GPIO_MODE_1_FOR_SIM		(GPIO_base + 0x340)
#define IOCFG_0_BASE			0xC0002000
#define REG_GPIO_IES_0_FOR_SIM		(IOCFG_0_BASE + 0x000)
#define REG_GPIO_IES_1_FOR_SIM		(IOCFG_0_BASE + 0x000) // same
#define REG_GPIO_SMT_0_FOR_SIM		(IOCFG_0_BASE + 0x010)
#define REG_GPIO_SMT_1_FOR_SIM		(IOCFG_0_BASE + 0x010) // same
#define REG_GPIO_TDSEL_0_FOR_SIM	(IOCFG_0_BASE + 0x030)
#define REG_GPIO_TDSEL_1_FOR_SIM	(IOCFG_0_BASE + 0x030) // same
#define REG_GPIO_RDSEL_0_FOR_SIM	(IOCFG_0_BASE + 0x050)
#define REG_GPIO_RDSEL_1_FOR_SIM	(IOCFG_0_BASE + 0x050) // same
#define REG_GPIO_DRV_0_FOR_SIM		(IOCFG_0_BASE + 0x0B0)
#define REG_GPIO_DRV_1_FOR_SIM		(IOCFG_0_BASE + 0x0B0) // same
#define REG_GPIO_PUPD_0_FOR_SIM		(IOCFG_0_BASE + 0x0D0)
#define REG_GPIO_PUPD_1_FOR_SIM		(IOCFG_0_BASE + 0x0D0) // same
	#define	SIM1_INS	0x00888000
	#define	SIM2_INS	0x00000888

#define ENABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_GPIO_PUPD_0_FOR_SIM, (DRV_Reg32(REG_GPIO_PUPD_0_FOR_SIM) | SIM2_INS));} \
	else{DRV_WriteReg32(REG_GPIO_PUPD_0_FOR_SIM, (DRV_Reg32(REG_GPIO_PUPD_0_FOR_SIM) | SIM1_INS));}

#define DISABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_GPIO_PUPD_0_FOR_SIM, (DRV_Reg32(REG_GPIO_PUPD_0_FOR_SIM) & ~(SIM2_INS)));} \
	else{DRV_WriteReg32(REG_GPIO_PUPD_0_FOR_SIM, (DRV_Reg32(REG_GPIO_PUPD_0_FOR_SIM) & ~(SIM1_INS)));}

#if defined(__SIM_ACTIVATION_V2__)
#if defined(__SIM_SAME_GPIO_MODE__)
#define GPIO_SIM1_SIMIO 41
#define GPIO_SIM2_SIMIO 36
#else
#define GPIO_SIM1_SIMIO 36
#define GPIO_SIM2_SIMIO 41
#endif
#endif
#elif defined(MT6797)

/* 
    GPIO mode of SIMIO

    GPIO_MODE15_MOD : SIM1_SCLK[26:24], SIM1_SRST[30:28]
    GPIO_MODE16_MOD : SIM1_SIO[0:2]
    GPIO_MODE19_MOD : SIM1_SCLK[14:12], SIM1_SRST[18:16], SIM1_SIO[22:20]
*/
#define GPIO_MODE15_MOD     (BASE_MADDR_GPIO+0x3F0)
#define GPIO_MODE16_MOD     (BASE_MADDR_GPIO+0x400)
#define GPIO_MODE19_MOD     (BASE_MADDR_GPIO+0x430)

#define GPIO_MODE15_SIMx_MASK   0x77000000
#define GPIO_MODE19_SIMx_MASK   0x00777000

#define GPIO_MODE15_MD1_SIM1    0x11000000
#define GPIO_MODE15_MD1_SIM2    0x22000000

#define GPIO_MODE19_MD1_SIM1    0x00222000
#define GPIO_MODE19_MD1_SIM2    0x00111000

/* 
    Pull-up control of SIMIO 
    SIM1[26:24], SIM2[29:27]
    
    PUPD/R1/R0
    0/0/0 : High-Z
    0/0/1 : Pull-up with 20Kohm
    0/1/0 : Pull-up with 5Kohm
    0/1/1 : Pull-up with 5Kohm
    1/0/0 : High-Z
    1/0/1 : Pull-down with 75Kohm
    1/1/0 : Pull-down with 75Kohm
    1/1/1 : Pull-down with 75Kohm
*/
#define GPIO_PUPD_CFG0_CLR  (BASE_MADDR_IOCFG_CONTROL_REG+0x508)
#define GPIO_PUPD_CFG0_SET  (BASE_MADDR_IOCFG_CONTROL_REG+0x504)
#define GPIO_PUPD_CFG0      (BASE_MADDR_IOCFG_CONTROL_REG+0x500)
#define GPIO_R0_CFG0_CLR    (BASE_MADDR_IOCFG_CONTROL_REG+0x518)
#define GPIO_R0_CFG0_SET    (BASE_MADDR_IOCFG_CONTROL_REG+0x514)
#define GPIO_R0_CFG0        (BASE_MADDR_IOCFG_CONTROL_REG+0x510)
#define GPIO_R1_CFG0_CLR    (BASE_MADDR_IOCFG_CONTROL_REG+0x528)
#define GPIO_R1_CFG0_SET    (BASE_MADDR_IOCFG_CONTROL_REG+0x524)
#define GPIO_R1_CFG0        (BASE_MADDR_IOCFG_CONTROL_REG+0x520)

/* 
    INS of SIMx IO, Pull-up control of INT_SIMx

    SIM1[0:3], SIM2[4:7]
    SIMx_SCLK [0], 0: normal / 1: special
    SIMx_SRST [1]
    SIMx_SIO  [2]
    INT_SIMx  [3]
 */
#define GPIO_PU_CFG2_CLR    (BASE_MADDR_IOCFG_CONTROL_REG+0x588)
#define GPIO_PU_CFG2_SET    (BASE_MADDR_IOCFG_CONTROL_REG+0x584)
#define GPIO_PU_CFG2        (BASE_MADDR_IOCFG_CONTROL_REG+0x580)

/* 
    Pull-up control of INT_SIMx

    INT_SIM1[0] and INT_SIM2[1]
    PU/PD
    0/0 : N/A
    1/0 : pull up
    0/1 : pull down
    1/1 : N/A
*/
#define GPIO_PD_CFG2_CLR    (BASE_MADDR_IOCFG_CONTROL_REG+0x558)
#define GPIO_PD_CFG2_SET    (BASE_MADDR_IOCFG_CONTROL_REG+0x554)
#define GPIO_PD_CFG2        (BASE_MADDR_IOCFG_CONTROL_REG+0x550)

/* 
    SIM2_D
    SIM2_CLK[27:26] : 00/4mA, 01/8mA, 10/12mA, 11/16mA
    SIM2_SRST/SIO/INT_SIM2[29:28]
    
    SIM2B_D[25:21]
    BIAS Tune of SIM2 IOs, suggestted value is 0x5, 

    SIM1_D
    SIM1_CLK[18:17] : 00/4mA, 01/8mA, 10/12mA, 11/16mA
    SIM1_SRST/SIO/INT_SIM1[20:19]

    SIM1B_D[16:12]
    BIAS Tune of SIM1 IOs, suggestted value is 0x5, 
*/
#define GPIO_DRV_CFG1_CLR   (BASE_MADDR_IOCFG_CONTROL_REG+0x5A8)
#define GPIO_DRV_CFG1_SET   (BASE_MADDR_IOCFG_CONTROL_REG+0x5A4)
#define GPIO_DRV_CFG1       (BASE_MADDR_IOCFG_CONTROL_REG+0x5A0)

/* SIM1[20:17], SIM2[24:21]*/
#define GPIO_IES_CFG2_CLR   (BASE_MADDR_IOCFG_CONTROL_REG+0x428)
#define GPIO_IES_CFG2_SET   (BASE_MADDR_IOCFG_CONTROL_REG+0x424)
#define GPIO_IES_CFG2       (BASE_MADDR_IOCFG_CONTROL_REG+0x420)

/* SIM1[12:7], SIM2[18:13]*/
#define GPIO_SR_CFG1_CLR    (BASE_MADDR_IOCFG_CONTROL_REG+0x448)
#define GPIO_SR_CFG1_SET    (BASE_MADDR_IOCFG_CONTROL_REG+0x444)
#define GPIO_SR_CFG1        (BASE_MADDR_IOCFG_CONTROL_REG+0x440)

/* SIM1[13:11], SIM2[16:14]*/
#define GPIO_SMT_CFG1_CLR   (BASE_MADDR_IOCFG_CONTROL_REG+0x468)
#define GPIO_SMT_CFG1_SET   (BASE_MADDR_IOCFG_CONTROL_REG+0x464)
#define GPIO_SMT_CFG1       (BASE_MADDR_IOCFG_CONTROL_REG+0x460)

/* SIM1[29:18]*/
#define GPIO_RDSEL_CFG1_CLR (BASE_MADDR_IOCFG_CONTROL_REG+0x488)
#define GPIO_RDSEL_CFG1_SET (BASE_MADDR_IOCFG_CONTROL_REG+0x484)
#define GPIO_RDSEL_CFG1     (BASE_MADDR_IOCFG_CONTROL_REG+0x480)

/* SIM2[27:16]*/
#define GPIO_RDSEL_CFG2_CLR (BASE_MADDR_IOCFG_CONTROL_REG+0x498)
#define GPIO_RDSEL_CFG2_SET (BASE_MADDR_IOCFG_CONTROL_REG+0x494)
#define GPIO_RDSEL_CFG2     (BASE_MADDR_IOCFG_CONTROL_REG+0x490)

/* SIM1[23:16], SIM2[31:24]*/
#define GPIO_TDSEL_CFG2_CLR (BASE_MADDR_IOCFG_CONTROL_REG+0x4D8)
#define GPIO_TDSEL_CFG2_SET (BASE_MADDR_IOCFG_CONTROL_REG+0x4D4)
#define GPIO_TDSEL_CFG2     (BASE_MADDR_IOCFG_CONTROL_REG+0x4D0)

#define REG_GPIO_MODE_0_FOR_SIM		GPIO_MODE15_MOD
#define REG_GPIO_MODE_1_FOR_SIM		GPIO_MODE16_MOD
#define REG_GPIO_MODE_2_FOR_SIM		GPIO_MODE19_MOD

#define REG_GPIO_IES_0_FOR_SIM		GPIO_IES_CFG2
#define REG_GPIO_IES_1_FOR_SIM		GPIO_IES_CFG2
#define REG_GPIO_SMT_0_FOR_SIM		GPIO_SMT_CFG1
#define REG_GPIO_SMT_1_FOR_SIM		GPIO_SMT_CFG1
#define REG_GPIO_TDSEL_0_FOR_SIM	GPIO_TDSEL_CFG2
#define REG_GPIO_TDSEL_1_FOR_SIM	GPIO_TDSEL_CFG2
#define REG_GPIO_RDSEL_0_FOR_SIM	GPIO_RDSEL_CFG1
#define REG_GPIO_RDSEL_1_FOR_SIM	GPIO_RDSEL_CFG2
#define REG_GPIO_DRV_0_FOR_SIM		GPIO_DRV_CFG1
#define REG_GPIO_DRV_1_FOR_SIM		GPIO_DRV_CFG1
#define REG_GPIO_PUPD_0_FOR_SIM		GPIO_PU_CFG2
#define REG_GPIO_PUPD_1_FOR_SIM		GPIO_PD_CFG2

#define ENABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(GPIO_PU_CFG2_SET, (0x7 << 4));} \
	else{DRV_WriteReg32(GPIO_PU_CFG2_SET, (0x7 << 0));}

#define DISABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(GPIO_PU_CFG2_CLR, (0x7 << 4));} \
	else{DRV_WriteReg32(GPIO_PU_CFG2_CLR, (0x7 << 0));}

#define SET_SIM1_SR(_n)
#define SET_SIM2_SR(_n)


#if defined(__SIM_ACTIVATION_V2__)
#if defined(__SIM_SAME_GPIO_MODE__)
#define GPIO_SIM1_SIMIO 128
#define GPIO_SIM2_SIMIO 157
#else
#define GPIO_SIM1_SIMIO 157
#define GPIO_SIM2_SIMIO 128
#endif
#endif

#elif defined(MT6757)

#define GPIO_base 			0xC0005000
#define REG_GPIO_MODE_0_FOR_SIM		(GPIO_base + 0x340)
#define REG_GPIO_MODE_1_FOR_SIM		(GPIO_base + 0x350)

#define IOCFG_0_BASE			0xC0002000
#define REG_GPIO_IES_0_FOR_SIM		(IOCFG_0_BASE + 0x000)
#define REG_GPIO_IES_1_FOR_SIM		(IOCFG_0_BASE + 0x000) // same
#define REG_GPIO_SMT_0_FOR_SIM		(IOCFG_0_BASE + 0x010)
#define REG_GPIO_SMT_1_FOR_SIM		(IOCFG_0_BASE + 0x010) // same
#define REG_GPIO_TDSEL_0_FOR_SIM	(IOCFG_0_BASE + 0x030)
#define REG_GPIO_TDSEL_1_FOR_SIM	(IOCFG_0_BASE + 0x030) // same
#define REG_GPIO_RDSEL_0_FOR_SIM	(IOCFG_0_BASE + 0x050)
#define REG_GPIO_RDSEL_1_FOR_SIM	(IOCFG_0_BASE + 0x050) // same
#define REG_GPIO_DRV_0_FOR_SIM		(IOCFG_0_BASE + 0x0B0)
#define REG_GPIO_DRV_1_FOR_SIM		(IOCFG_0_BASE + 0x0B0) // same
#define REG_GPIO_PUPD_0_FOR_SIM		(IOCFG_0_BASE + 0x0D0)
#define REG_GPIO_PUPD_1_FOR_SIM		(IOCFG_0_BASE + 0x0D0) // same
	#define	SIM1_INS	0x00888000
	#define	SIM2_INS	0x00000888

#define ENABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_GPIO_PUPD_0_FOR_SIM, (DRV_Reg32(REG_GPIO_PUPD_0_FOR_SIM) | SIM2_INS));} \
	else{DRV_WriteReg32(REG_GPIO_PUPD_0_FOR_SIM, (DRV_Reg32(REG_GPIO_PUPD_0_FOR_SIM) | SIM1_INS));}

#define DISABLE_ABNORMAL_SIM(_n) \
	if(_n){DRV_WriteReg32(REG_GPIO_PUPD_0_FOR_SIM, (DRV_Reg32(REG_GPIO_PUPD_0_FOR_SIM) & ~(SIM2_INS)));} \
	else{DRV_WriteReg32(REG_GPIO_PUPD_0_FOR_SIM, (DRV_Reg32(REG_GPIO_PUPD_0_FOR_SIM) & ~(SIM1_INS)));}

#if defined(__SIM_ACTIVATION_V2__)
#if defined(__SIM_SAME_GPIO_MODE__)
#define GPIO_SIM1_SIMIO 41
#define GPIO_SIM2_SIMIO 36
#else
#define GPIO_SIM1_SIMIO 36
#define GPIO_SIM2_SIMIO 41
#endif
#endif
#else
#define ENABLE_ABNORMAL_SIM(_n)
#define DISABLE_ABNORMAL_SIM(_n)
#define SET_SIM1_SR(_n)
#define SET_SIM2_SR(_n)
#endif

#endif /*__SIM_DRV_HW_REG_MTK_H__*/
