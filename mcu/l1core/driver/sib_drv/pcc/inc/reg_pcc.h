#ifndef __REG_PCC_H__
#define __REG_PCC_H__

#if defined(TK6291)
#define CHIP_TK6291
#else
#define CHIP_JADE
#endif

/* PPC Register Define */
#define REG_PCC_BASE				        (0xF7EE0000)

#define REG_PCC_CTRL0_START_STOP			(REG_PCC_BASE + 0x0)		//Enable to capture presync data, the last setting for PPC_wtl configuration
#define REG_PCC_CTRL1_CAPTURE_CFG			(REG_PCC_BASE + 0x004)		//Set pcc config for capture settings
																		/* [BIT 3:0]
																		0: LTE_ADC_52MHz_with_cmp
																		1: LTE_ADC_52MHz_bypass_cmp
																		2: LTE_ADC_52MHz_truncate_8b
																		3: LTE_ADC_104MHz_with_cmp
																		4: LTE_ADC_104MHz_bypass_cmp
																		5: LTE_ADC_104MHz_truncate_8b
																		6: LTE_INTP_demod 
																		7: LTE_INTP_CM
																		8: LTE_INTP_CS
																		9: LTE_INTP_demod_CM 
																		10: 3G_TDD_ADC
																		11: 3G_TDD_RXIQ
																		12: 3G_TDD_INTP
																		13: 3G_FDD_ADC
																		14: 3G_FDD_INTP_demod 
																		*/
#define REG_PCC_CTRL2_DATA_SIZE				(REG_PCC_BASE + 0x008)		//setting one data packet length
																		/*
																		CN0,1,3,4,10,13: IQ number = reg_pcc_data_size
																		CN2,5: IQ number = reg_pcc_data_size*2
																		CN 6,7,9: IQ number = reg_pcc_data_size*4
																		CN8: IQ number = reg_pcc_data_size*3
																		CN11,12:IQ number = reg_pcc_data_size (include intp mu)
																		CN14:IQ number = reg_pcc_data_size (three carrier to one path)
																		*/
#define REG_PCC_CTRL3_PN_START			    (REG_PCC_BASE + 0x00C)		//Packet start syncword
#define REG_PCC_CTRL4_PN_STOP				(REG_PCC_BASE + 0x010)		//Packet stop syncword
#define REG_PCC_CTRL5_PN_FULL				(REG_PCC_BASE + 0x014)		//Packet stop syncword in full status
#define REG_PCC_CTRL6_CN_LEN				(REG_PCC_BASE + 0x018)		//PCC compressor CN_Length settings
																		/*
																		[3:0]: Cn_len0
																		[7:4]: Cn_len1
																		[11:8]: Cn_len2
																		*/
#define REG_PCC_CTRL7_VTH					(REG_PCC_BASE + 0x01C)		//PCC compressor Vth settings
																		/*
																		[3:0]: Vth0
																		[7:4]: Vth1
																		*/
#define REG_PCC_CTRL8_COMP_CFG				(REG_PCC_BASE + 0x020)		//PCC comp div enable & divfac setting
#define REG_PCC_CTRL9_ATB_BUSY				(REG_PCC_BASE + 0x024)		//trigger dfe_atb enable for ATB transfer
#define REG_PCC_CTRL12_DBG_LATCH_PERIOD		(REG_PCC_BASE + 0x030)		//setting info presync update period
#define REG_PCC_CTRL13_ATB_VLD_COUNT_LIMIT	(REG_PCC_BASE + 0x034)		//the disable period of the two continuous atb_valid
#define REG_PCC_CTRL14_ATB_REORDER_EN		(REG_PCC_BASE + 0x038)		//[24]re-order at1~at4 valid sequence. FIFO depth is larger, 
																		//valid priority is higher. 
                                                                        /*
                                                                        [20] limit the atb5 avlid region. Disable at5 avlid in
                                                                        packet_start for at1~at4
                                                                        [15:0] the disable period of the two continuous atb_valid.
                                                                        To limit the atb5_busy valid frequency.
                                                                        */

#define REG_PCC_ATB_CTRL0_S0				(REG_PCC_BASE + 0x040)		//s0 atbytes & atid setting
#define REG_PCC_ATB_CTRL1_S1				(REG_PCC_BASE + 0x044)		//s1 atbytes & atid setting
#define REG_PCC_ATB_CTRL2_S2				(REG_PCC_BASE + 0x048)		//s2 atbytes & atid setting
#define REG_PCC_ATB_CTRL3_S3				(REG_PCC_BASE + 0x04C)		//s3 atbytes & atid setting
#define REG_PCC_ATB_CTRL4_S4				(REG_PCC_BASE + 0x050)		//s4 atbytes & atid setting
#define REG_PCC_ATB_CTRL5_S5				(REG_PCC_BASE + 0x054)		//s5 atbytes & atid setting

#define REG_PCC_FIFO_STATUS1				(REG_PCC_BASE + 0x060)		//FIFO status & settings
#define REG_PCC_FIFO_STATUS2				(REG_PCC_BASE + 0x064)		//FIFO depth records

#define REG_PCC_FSM_STATUS0					(REG_PCC_BASE + 0x070)		//PCC FSM Status

#define REG_PCC_THRPT_CTRL0							(REG_PCC_BASE + 0x080)	//measure enable & measure done status
#define REG_PCC_THRPT_CTRL1_WIN_LEN					(REG_PCC_BASE + 0x084)	//set the counting window length, based on 208MHz clock 
#define REG_PCC_THRPT_CTRL2_ATB_RDY0_NUM			(REG_PCC_BASE + 0x088)
#define REG_PCC_THRPT_CTRL3_ATB_RDY1_NUM			(REG_PCC_BASE + 0x08C)
#define REG_PCC_THRPT_CTRL4_ATB_RDY2_NUM			(REG_PCC_BASE + 0x090)
#define REG_PCC_THRPT_CTRL5_ATB_RDY3_NUM			(REG_PCC_BASE + 0x094)
#define REG_PCC_THRPT_CTRL6_ATB_RDY4_NUM			(REG_PCC_BASE + 0x098)
#define REG_PCC_THRPT_CTRL7_ATB_RDY5_NUM			(REG_PCC_BASE + 0x09C)
#define REG_PCC_THRPT_CTRL8_COMP_VLD_NUM0			(REG_PCC_BASE + 0x0A0)
#define REG_PCC_THRPT_CTRL9_COMP_VLD_NUM1			(REG_PCC_BASE + 0x0A4)
#define REG_PCC_THRPT_CTRL10_COMP_VLD_NUM2			(REG_PCC_BASE + 0x0A8)
#define REG_PCC_THRPT_CTRL11_COMP_VLD_NUM3			(REG_PCC_BASE + 0x0AC)
#define REG_PCC_THRPT_CTRL12_IQ_PSYNC_VLD_NUM0		(REG_PCC_BASE + 0x0B0)
#define REG_PCC_THRPT_CTRL13_IQ_PSYNC_VLD_NUM1		(REG_PCC_BASE + 0x0B4)
#define REG_PCC_THRPT_CTRL14_IQ_PSYNC_VLD_NUM2		(REG_PCC_BASE + 0x0B8)
#define REG_PCC_THRPT_CTRL15_IQ_PSYNC_VLD_NUM3		(REG_PCC_BASE + 0x0BC)
#define REG_PCC_THRPT_CTRL16_INFO_VLD_NUM			(REG_PCC_BASE + 0x0C0)
#define REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME		(REG_PCC_BASE + 0x0C4)

#define REG_PCC_PATGEN_CTRL0						(REG_PCC_BASE + 0x0D0)	//pattern gen enable & pattern select
#define REG_PCC_PATGEN_CTRL1_MUX				    (REG_PCC_BASE + 0x0D4)	//data path select
																			/*
																			0: presync input to PCC
																			1: patgen input to PCC
																			*/
#define REG_PCC_PATGEN_CTRL2_ACC_STEP				(REG_PCC_BASE + 0x0D8)
#define REG_PCC_PATGEN_CTRL3_REC_PERIOD				(REG_PCC_BASE + 0x0DC)
#define REG_PCC_PATGEN_CTRL4_REC_AMP				(REG_PCC_BASE + 0x0E0)
#define REG_PCC_PATGEN_CTRL5_VLD_PRD_AT01			(REG_PCC_BASE + 0x0E4)
#define REG_PCC_PATGEN_CTRL6_VLD_PRD_AT23			(REG_PCC_BASE + 0x0E8)

#define REG_PCC_DBG_CTRL							(REG_PCC_BASE + 0x0F0)




/* Define Register Default Values */
#define DEF_REG_PCC_CTRL0_START_STOP			(0x0)		
#define DEF_REG_PCC_CTRL1_CAPTURE_CFG			(0x08421000)

#if 1  //#ifdef CHIP_JADE
#define DEF_REG_PCC_CTRL2_DATA_SIZE             (0x32C80)    //Define to use the same default value no matter on which chip
#else  //CHIP_TK6291
/* under construction !*/
#endif		

#define DEF_REG_PCC_CTRL3_PN_START			    (0xA1B9)		
#define DEF_REG_PCC_CTRL4_PN_STOP				(0xD3C2)
#define DEF_REG_PCC_CTRL5_PN_FULL				(0xFFFF)

#if 1  //#ifdef CHIP_JADE
#define DEF_REG_PCC_CTRL6_CN_LEN				(0x36F)
#define DEF_REG_PCC_CTRL7_VTH					(0x36)
#else  //CHIP_TK6291
/* under construction !*/
/* under construction !*/
#endif

#ifdef CHIP_JADE
#define DEF_REG_PCC_CTRL8_COMP_CFG			    (0x100)
#else
#define DEF_REG_PCC_CTRL8_COMP_CFG			    (0x0)
#endif

#define DEF_REG_PCC_CTRL9_ATB_BUSY			    (0x0)

#if 1  //#ifdef CHIP_JADE  
#define DEF_REG_PCC_CTRL12_DBG_LATCH_PERIOD		(0xE81)    //Define to use the same default value no matter on which chip
#else  //CHIP_TK6291
/* under construction !*/
#endif

#define DEF_REG_PCC_CTRL13_ATB_VLD_COUNT_LIMIT	(0x0)
#define DEF_REG_PCC_CTRL14_ATB_REORDER_EN		(0x3C)
#define DEF_REG_PCC_ATB_CTRL0_S0				(0x03)
#define DEF_REG_PCC_ATB_CTRL1_S1				(0x13)
#define DEF_REG_PCC_ATB_CTRL2_S2				(0x23)
#define DEF_REG_PCC_ATB_CTRL3_S3				(0x33)
#define DEF_REG_PCC_ATB_CTRL4_S4				(0x43)
#define DEF_REG_PCC_ATB_CTRL5_S5				(0x53)
#define DEF_REG_PCC_FIFO_STATUS1				(0x30)
//#define DEF_REG_PCC_FIFO_STATUS2			    (0x0)    //read only
//#define DEF_REG_PCC_FSM_STATUS0				(0x0)    //read only

#define DEF_REG_PCC_THRPT_CTRL0							(0x0)
#define DEF_REG_PCC_THRPT_CTRL1_WIN_LEN					(0x0)
//#define DEF_REG_PCC_THRPT_CTRL2_ATB_RDY0_NUM			(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL3_ATB_RDY1_NUM			(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL4_ATB_RDY2_NUM			(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL5_ATB_RDY3_NUM			(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL6_ATB_RDY4_NUM			(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL7_ATB_RDY5_NUM			(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL8_COMP_VLD_NUM0			(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL9_COMP_VLD_NUM1			(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL10_COMP_VLD_NUM2			(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL11_COMP_VLD_NUM3			(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL12_IQ_PSYNC_VLD_NUM0		(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL13_IQ_PSYNC_VLD_NUM1		(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL14_IQ_PSYNC_VLD_NUM2		(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL15_IQ_PSYNC_VLD_NUM3		(0x0)    //read only
//#define DEF_REG_PCC_THRPT_CTRL16_INFO_VLD_NUM			(0x0)    //read only
#define DEF_REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME		(0x0)

#define DEF_REG_PCC_PATGEN_CTRL0						(0x0)
#define DEF_REG_PCC_PATGEN_CTRL1_MUX					(0x0)
#define DEF_REG_PCC_PATGEN_CTRL2_ACC_STEP				(0x0)
#define DEF_REG_PCC_PATGEN_CTRL3_REC_PERIOD				(0x0)
#define DEF_REG_PCC_PATGEN_CTRL4_REC_AMP				(0x0)
#define DEF_REG_PCC_PATGEN_CTRL5_VLD_PRD_AT01			(0x10001)
#define DEF_REG_PCC_PATGEN_CTRL6_VLD_PRD_AT23			(0x10001)

#define DEF_REG_PCC_DBG_CTRL							(0x0)


/* Control Bit Define */
#define CTRL_PCC_STOP   (0x0)
#define CTRL_PCC_START  (0x1)

#define STAT_PCC_STOP   (0x0)
#define STAT_PCC_START  (0x1)

#define CTRL_PCC_PATH_SEL_AT1   (0x1<<0)
#define CTRL_PCC_PATH_SEL_AT2   (0x1<<1)
#define CTRL_PCC_PATH_SEL_AT3   (0x1<<2)
#define CTRL_PCC_PATH_SEL_AT4   (0x1<<3)
#define CTRL_PCC_PATH_SEL_ADJ   (0x1<<4)
/*
#define CTRL_PCC_ANTENNA1_CARRIER1	(0x1<<0)
#define CTRL_PCC_ANTENNA1_CARRIER2	(0x1<<1)
#define CTRL_PCC_ANTENNA2_CARRIER1	(0x1<<2)
#define CTRL_PCC_ANTENNA2_CARRIER2	(0x1<<3)
*/
#define OFS_PCC_DATA_CAPTURE_NODE		(0)
#define MASK_PCC_DATA_CAPTURE_NODE		(0x0F)
#define OFS_PCC_PATH_SEL				(4)
#define MASK_PCC_PATH_SEL				(0x1F)

#ifdef CHIP_JADE  //new feature on Jade
#define CTRL_PCC_INI_CMP_IGNORE_ENABLE    (0x1<<9)
#define CTRL_PCC_INI_CMP_IGNORE_DISABLE   (~(0x1<<9))
#endif

#define OFS_PCC_ANT_CAR_SEL_P11			  (12)
#define MASK_PCC_ANT_CAR_SEL_P11		  (0x0F)
#define OFS_PCC_ANT_CAR_SEL_P12			  (16)
#define MASK_PCC_ANT_CAR_SEL_P12		  (0x0F)
#define OFS_PCC_ANT_CAR_SEL_P21			  (20)
#define MASK_PCC_ANT_CAR_SEL_P21		  (0x0F)
#define OFS_PCC_ANT_CAR_SEL_P22			  (24)
#define MASK_PCC_ANT_CAR_SEL_P22		  (0x0F)

#define OFS_PCC_ADC_PATH_SEL              (28)
#define MASK_PCC_ADC_PATH_SEL             (0x1)
#define OFS_PCC_MULTI_SIB_INOUT_SEL       (30)
#define MASK_PCC_MULTI_SIB_INOUT_SEL      (0x1)
#define OFS_PCC_MULTI_SIB_EN              (31)
#define MASK_PCC_MULTI_SIB_EN             (0x1)
#define CTRL_PCC_ADC_PATH_SEL_IQ_PRESYNC      (~(0x1<<28))
#define CTRL_PCC_ADC_PATH_SEL_COMP            (0x1<<28)
#define CTRL_PCC_MULTI_SIB_INOUT_SEL_MASTER	  (~(0x1<<30))
#define CTRL_PCC_MULTI_SIB_INOUT_SEL_SLAVE    (0x1<<30)
#define CTRL_PCC_MULTI_SIB_ENABLE		      (0x1<<31)
#define CTRL_PCC_MULTI_SIB_DISABLE            (~(0x1<<31))

#define OFS_PCC_CN_LEN0				(0)
#define OFS_PCC_CN_LEN1				(4)
#define OFS_PCC_CN_LEN2				(8)
#define MASK_PCC_CN_LEN				(0x0F)

#define OFS_PCC_VTH0				(0)
#define OFS_PCC_VTH1				(4)
#define MASK_PCC_VTH				(0x0F)

#define CTRL_PCC_COMP_DIV_DISABLE	(0x0)
#define CTRL_PCC_COMP_DIV_ENABLE	(0x1)
#define OFS_PCC_COMP_DIV_FAC		(4)
#define MASK_PCC_COMP_DIV_FAC		(0x0F)

#ifdef CHIP_JADE  //new feature on Jade
#define CTRL_COMP_RST_ENABLE        (0x1<<8)
#define CTRL_COMP_RST_DISABLE       (~(0x1<<8))
#endif

#define CTRL_PCC_ATB_BUSY_AT0		(0x1<<0)
#define CTRL_PCC_ATB_BUSY_AT1		(0x1<<1)
#define CTRL_PCC_ATB_BUSY_AT2		(0x1<<2)
#define CTRL_PCC_ATB_BUSY_AT3		(0x1<<3)
#define CTRL_PCC_ATB_BUSY_AT4		(0x1<<4)
#define CTRL_PCC_ATB_BUSY_AT5		(0x1<<5)
#define MASK_PCC_ATB_BUSY			(0x3F)

#define OFS_PCC_VLD_COUNT_LIMIT_AT1		(0)
#define OFS_PCC_VLD_COUNT_LIMIT_AT2		(8)
#define OFS_PCC_VLD_COUNT_LIMIT_AT3		(16)
#define OFS_PCC_VLD_COUNT_LIMIT_AT4		(24)
#define OFS_PCC_VLD_COUNT_LIMIT_AT5		(0)
#define BIT_PCC_ATB_REORDER_EN			(0x1<<24)
#define BIT_PCC_LIMIT_AT5_VLD_REGION	(0x1<<20)
#define MASK_PCC_VLD_COUNT_LIMIT_AT1_4	(0xFF)
#define MASK_PCC_VLD_COUNT_LIMIT_AT5	(0xFFFF)

#define MASK_PCC_LATCH_PERIOD		(0x0FFFFF)

#define MASK_PCC_ATB_ATBYTES		(0x03)
#define MASK_PCC_ATB_ATID			(0x7F)
#define OFS_PCC_ATB_ATID			(4)

#define OFS_PCC_ATB_FULL_IRQ_EN         (4)
#define MASK_PCC_ATB_FULL_IRQ_EN        (0x1)
#define OFS_PCC_COMP_FULL_IRQ_EN        (5)
#define MASK_PCC_COMP_FULL_IRQ_EN       (0x1)
#define BIT_PCC_ATB_FIFO_FULL		    (0x1<<0)
#define BIT_PCC_COMP_FIFO_FULL		    (0x1<<1)
#define CTRL_PCC_ATB_FULL_IRQ_ENABLE    (0x1<<4)
#define CTRL_PCC_ATB_FULL_IRQ_DISABLE   (~(0x1<<4))
#define CTRL_PCC_COMP_FULL_IRQ_ENABLE   (0x1<<5)
#define CTRL_PCC_COMP_FULL_IRQ_DISABLE  (~(0x1<<5))
#define CTRL_PCC_ATB_FIFO_DEPTH_RST	(0x1<<8)

#define OFS_PCC_AT1_FIFO_DEPTH		(0)
#define OFS_PCC_AT2_FIFO_DEPTH		(8)
#define OFS_PCC_AT3_FIFO_DEPTH		(16)
#define OFS_PCC_AT4_FIFO_DEPTH		(24)
#define MASK_PCC_ATB_FIFO_DEPTH		(0xFF)

#define OFS_PCC_FSM_STATUS_DATA1	  (0)
#define OFS_PCC_FSM_STATUS_DATA2	  (4)
#define OFS_PCC_FSM_STATUS_DATA3	  (8)
#define OFS_PCC_FSM_STATUS_DATA4	  (12)
#define OFS_PCC_FSM_STATUS_PKSTART	  (16)
#define OFS_PCC_FSM_STATUS_ADJ		  (20)
#define MASK_PCC_FSM_STATUS_DATA	  (0x03)
#define MASK_PCC_FSM_STATUS_PKSTART	  (0x07)
#define MASK_PCC_FSM_STATUS_ADJ		  (0x03)

#define CTRL_PCC_THRPT_MEASURE_ENABLE	(0x1)
#define BIT_PCC_THRPT_MEASURE_DONE		(0x1<<4)

#define MASK_PCC_MEASURE_WINDOW_LENGTH	(0x0FFFFF)

#define CTRL_PCC_VALID_WAIT_TIME_RST	(0x1<<17)
#define CTRL_PCC_VALID_WAIT_TIME_ENABLE	(0x1<<16)
#define MASK_PCC_VALID_WAIT_TIME		(0xffff)

#define CTRL_PCC_PTG_ENABLE			(0x1)
#define OFS_PCC_PTG_SEL				(4)
#define MASK_PCC_PTG_SEL			(0x03)

#define MASK_PCC_PTG_MUX			(0x01)

#define OFS_PCC_PTG_VLD_PERIOD0		(0)
#define OFS_PCC_PTG_PRD_PERIOD0		(8)
#define OFS_PCC_PTG_VLD_PERIOD1		(16)
#define OFS_PCC_PTG_PRD_PERIOD1		(24)
#define MASK_PCC_PTG_VLD_PERIOD		(0xFF)
#define MASK_PCC_PTG_PRD_PERIOD		(0x03)

#define OFS_PCC_PTG_VLD_PERIOD2		(0)
#define OFS_PCC_PTG_PRD_PERIOD2		(8)
#define OFS_PCC_PTG_VLD_PERIOD3		(16)
#define OFS_PCC_PTG_PRD_PERIOD3		(24)

//new add for PCC CLK power down control in DFESYS
//TK6291 is default on, but Jade is default off.
//Need to turn on before PCC_START
#define REG_DFESYS_CFG_PDN_W_CON0   (0xF7E00200)
#define REG_DFESYS_CFG_PDN_T_CON1   (0xF7E00204)
#define REG_DFESYS_CFG_PDN_L_CON2   (0xF7E00208)
#define BIT_PDN_W_TRACE_WTL_PWDOWN  (0x1<<9)
#define BIT_PDN_T_TRACE_WTL_PWDOWN  (0x1<<9)
#define BIT_PDN_L_TRACE_WTL_PWDOWN  (0x1<<9)

#endif //__REG_PCC_H__