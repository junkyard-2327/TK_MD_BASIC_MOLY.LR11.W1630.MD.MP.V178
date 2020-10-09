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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    idc_reg.h
 *
 * Project:
 * --------
 *   MOLY_Software
 *
 * Description:
 * ------------
 *   This file is intends for UART driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __IDC_REG_H__
#define __IDC_REG_H__

#define IDC_CTRL_BASE			(L1_BASE_MADDR_IDC_CTRL)
#define IDC_CTRL_BASE_D			((L1_BASE_MADDR_IDC_CTRL & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define IDC_UART_BASE			(L1_BASE_MADDR_IDC_UART)
#define IDC_CTRL_IND_CR_BASE		(0)

// IDC_CTRL (Strongly Order)
#define IDC_CTRL_SCH_CTRL		(IDC_CTRL_BASE + 0x00)
#define IDC_CTRL_TIMER0_GLO_OS		(IDC_CTRL_BASE + 0x04)
#define	IDC_CTRL_TIMER_GLO_OS(_n)	(IDC_CTRL_TIMER0_GLO_OS + ((_n) << 2))
#define IDC_CTRL_TIMER0_STA_ADDR	(IDC_CTRL_BASE + 0x0C)
#define IDC_CTRL_TIMER1_STA_ADDR	(IDC_CTRL_BASE + 0x10)
#define IDC_CTRL_SCH_START_1500		(IDC_CTRL_BASE + 0x14)
#define IDC_CTRL_SCH_STOP_1500		(IDC_CTRL_BASE + 0x18)
#define IDC_CTRL_SCH_STATUS_1500	(IDC_CTRL_BASE + 0x1C)
#define IDC_CTRL_IND_ADDR		(IDC_CTRL_BASE + 0x20)
#define IDC_CTRL_IND_DATA		(IDC_CTRL_BASE + 0x24)
#define IDC_CTRL_IND_RD			(IDC_CTRL_BASE + 0x28)
#define IDC_CTRL_DATA_CNT_CTRL		(IDC_CTRL_BASE + 0x2C)
#define IDC_CTRL_DATA_CNT		(IDC_CTRL_BASE + 0x30)
#define IDC_CTRL_DUMMY			(IDC_CTRL_BASE + 0x34)
#define IDC_CTRL_RSV0			(IDC_CTRL_BASE + 0x38)
#define IDC_CTRL_RSV1			(IDC_CTRL_BASE + 0x3C)

#define	IDC_BSI_SCH_EVT_CON(_n)		(IDC_CTRL_IND_CR_BASE + 0x000 + (_n) + ((_n) << 1))
#define	IDC_BSI_SCH_EVT_CON2(_n)	(IDC_CTRL_IND_CR_BASE + 0x001 + (_n) + ((_n) << 1))
#define	IDC_BSI_SCH_EVT_OFFSET(_n)	(IDC_CTRL_IND_CR_BASE + 0x002 + (_n) + ((_n) << 1))
#define	IDC_BSI_SCH_DATA(_n)		(IDC_CTRL_IND_CR_BASE + 0x200 + (_n))
#define IDC_BSI_SCH_EVT_CON_STP_STA_ADDR(_STP, _STA)	(((_STP) << 8) | (_STA))

// IDC_CTRL (Device Type)
#define IDC_CTRL_SCH_CTRL_D		(IDC_CTRL_BASE_D + 0x00)
#define IDC_CTRL_TIMER0_GLO_OS_D	(IDC_CTRL_BASE_D + 0x04)
#define	IDC_CTRL_TIMER_GLO_OS_D(_n)	(IDC_CTRL_TIMER0_GLO_OS_D + ((_n) << 2))
#define IDC_CTRL_TIMER0_STA_ADDR_D	(IDC_CTRL_BASE_D + 0x0C)
#define IDC_CTRL_TIMER1_STA_ADDR_D	(IDC_CTRL_BASE_D + 0x10)
#define IDC_CTRL_SCH_START_1500_D	(IDC_CTRL_BASE_D + 0x14)
#define IDC_CTRL_SCH_STOP_1500_D	(IDC_CTRL_BASE_D + 0x18)
#define IDC_CTRL_SCH_STATUS_1500_D	(IDC_CTRL_BASE_D + 0x1C)
#define IDC_CTRL_IND_ADDR_D		(IDC_CTRL_BASE_D + 0x20)
#define IDC_CTRL_IND_DATA_D		(IDC_CTRL_BASE_D + 0x24)
#define IDC_CTRL_IND_RD_D		(IDC_CTRL_BASE_D + 0x28)
#define IDC_CTRL_DATA_CNT_CTRL_D	(IDC_CTRL_BASE_D + 0x2C)
#define IDC_CTRL_DATA_CNT_D		(IDC_CTRL_BASE_D + 0x30)
#define IDC_CTRL_DUMMY_D		(IDC_CTRL_BASE_D + 0x34)
#define IDC_CTRL_RSV0_D			(IDC_CTRL_BASE_D + 0x38)
#define IDC_CTRL_RSV1_D			(IDC_CTRL_BASE_D + 0x3C)

// IDC_UART
#define IDC_UART_RBR			(IDC_UART_BASE + 0x00)
#define IDC_UART_THR			(IDC_UART_BASE + 0x00)
#define IDC_UART_DLL			(IDC_UART_BASE + 0x00)
#define IDC_UART_DLM			(IDC_UART_BASE + 0x04)
#define IDC_UART_IER			(IDC_UART_BASE + 0x04)
#define IDC_UART_IIR			(IDC_UART_BASE + 0x08)
#define IDC_UART_FCR			(IDC_UART_BASE + 0x08)
#define IDC_UART_LCR			(IDC_UART_BASE + 0x0C)
#define IDC_UART_MCR			(IDC_UART_BASE + 0x10)
#define IDC_UART_LSR			(IDC_UART_BASE + 0x14)
#define IDC_UART_MSR			(IDC_UART_BASE + 0x18)
#define IDC_UART_HIGHSPEED		(IDC_UART_BASE + 0x24)
#define IDC_UART_SAMPLE_COUNT		(IDC_UART_BASE + 0x28)
#define IDC_UART_SAMPLE_POINT		(IDC_UART_BASE + 0x2C)
#define IDC_UART_RXTRIG			(IDC_UART_BASE + 0x50)
#define IDC_UART_FRACDIV_L		(IDC_UART_BASE + 0x54)
#define IDC_UART_FRACDIV_M		(IDC_UART_BASE + 0x58)
#define IDC_UART_FCR_RD			(IDC_UART_BASE + 0x5C)
#define IDC_PM_STATUS			(IDC_UART_BASE + 0xBC)
#define IDC_PRI0			(IDC_UART_BASE + 0xC0)
#define IDC_PRI0_BITEN			(IDC_UART_BASE + 0xC4)
#define IDC_PAT0			(IDC_UART_BASE + 0xC8)
#define IDC_PAT0_BITEN			(IDC_UART_BASE + 0xCC)
#define IDC_PRI(_n)			(IDC_PRI0 + ((_n) << 4))
#define IDC_PRI_BITEN(_n)		(IDC_PRI0_BITEN + ((_n) << 4))
#define IDC_PAT(_n)			(IDC_PAT0 + ((_n) << 4))
#define IDC_PAT_BITEN(_n)		(IDC_PAT0_BITEN + ((_n) << 4))

//IER
#define IDC_UART_IER_ALLOFF				0x0000
#define IDC_UART_IER_ERBFI				0x0001
#define IDC_UART_IER_ETBEI				0x0002
#define IDC_UART_IER_INT_MASK				0x00ef

//HIGHSPEED
#define	IDC_UART_HIGHSPEED_X				0x0003	// baud = clock/UART_RATE_STEP_COUNT

//FCR
#define IDC_UART_FCR_FIFOEN				0x0001
#define IDC_UART_FCR_CLRR				0x0002
#define IDC_UART_FCR_CLRT				0x0004
#define IDC_UART_FCR_FIFOINI				0x0007
#define IDC_UART_FCR_RXTRIG				0x00c0

#define IDC_UART_TxFIFO_DEPTH				32
#define IDC_UART_RxFIFO_DEPTH				32

//IIR (RO)
#define IDC_UART_IIR_INT_INVALID			0x0001
#define IDC_UART_IIR_THR_EMPTY				0x0002  // TX Empty
#define IDC_UART_IIR_RDA				0x0004  // Receive Data Available
#define IDC_UART_IIR_RDT				0x000c  // Receive Data Timeout
#define IDC_UART_IIR_INT_MASK				0x003f

//===============================LCR================================
//WLS
#define IDC_UART_WLS_8					0x0003
#define IDC_UART_WLS_7					0x0002
#define IDC_UART_WLS_6					0x0001
#define IDC_UART_WLS_5					0x0000
#define IDC_UART_DATA_MASK				0x0003

//Parity
#define IDC_UART_NONE_PARITY				0x0000
#define IDC_UART_ODD_PARITY				0x0008
#define IDC_UART_EVEN_PARITY				0x0018
#define IDC_UART_ONE_PARITY				0x0028
#define IDC_UART_ZERO_PARITY				0x0038
#define IDC_UART_PARITY_MASK				0x0038

//Stop bits
#define IDC_UART_1_STOP					0x0000
#define IDC_UART_1_5_STOP				0x0004	// Only valid for 5 data bits
#define IDC_UART_2_STOP					0x0004
#define IDC_UART_STOP_MASK				0x0004

#define IDC_UART_LCR_DLAB				0x0080
//===============================LCR================================

//LSR
#define IDC_UART_LSR_DR					0x0001
#define IDC_UART_LSR_TEMT				0x0040

#endif // __IDC_REG_H__
