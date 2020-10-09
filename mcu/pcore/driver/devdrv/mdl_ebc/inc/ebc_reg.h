/*
 * ebc_reg.h
 *
 *  Created on: 2014/6/5
 *      Author: MTK07117
 */

#ifndef EBC_REG_H_
#define EBC_REG_H_
// =================== TEC register address =======================
#define TEC_BASEADDR		(0xF6100000)
// TEC controller
#define TEC_EMI_BUF_FULL_IRQ_STA	(TEC_BASEADDR + 0x0000)
#define TEC_EMI_BUF_FULL_IRQ_CLR	(TEC_BASEADDR + 0x0004)
#define TEC_EMI_BUF_FULL_STA		(TEC_BASEADDR + 0x0008)
#define TEC_EMI_BUF_RES_CON			(TEC_BASEADDR + 0x000C)
#define TEC_CON						(TEC_BASEADDR + 0x0010)
// ================================================================

// TEC EMI Related Macro
#define TEC_GET_EMI_BUF_FULL_IRQ		DRV_Reg32(TEC_EMI_BUF_FULL_IRQ_STA)
#define TEC_CLR_EMI_BUF_FULL_IRQ(BMap)	DRV_WriteReg32(TEC_EMI_BUF_FULL_IRQ_CLR, BMap)
#define TEC_GET_EMI_BUF_FULL_STA		DRV_Reg32(TEC_EMI_BUF_FULL_STA)
#define TEC_GET_EMI_BUF_FULL_ASYNC		DRV_Reg32(TEC_EMI_BUF_RES_CON)
#define TEC_CLR_EMI_BUF_FULL_STA(BMap)	DRV_WriteReg32(TEC_EMI_BUF_RES_CON, BMap)
// TEC_CON
#define TEC_CLK_EN						(DRV_Reg32(TEC_CON) &= (~0x00000001))
#define TEC_CLK_DIS	  					(DRV_Reg32(TEC_CON) |= ( 0x00000001))
#define TEC_BUF_FULL_INT_EN				(DRV_Reg32(TEC_CON) &= (~0x00000002))
#define TEC_BUF_FULL_INT_DIS	  		(DRV_Reg32(TEC_CON) |= ( 0x00000002))
#define TEC_SET_TEC_RESET				(DRV_Reg32(TEC_CON) |= ( 0x00000004))
#endif /* EBC_REG_H_ */
