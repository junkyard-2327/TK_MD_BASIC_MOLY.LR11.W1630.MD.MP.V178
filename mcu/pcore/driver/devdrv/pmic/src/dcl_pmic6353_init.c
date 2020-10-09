/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2015
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
 *     dcl_pmic6353_init.c
 *
 * Project:
 * --------
 *     MOLY Software
 *
 * Description:
 * ------------
 *     This file is for PMIC 6353
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "init.h"
#include "dcl.h"

extern DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr);
extern void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value);

void PMIC_DRV_SetData(DCL_UINT32 addr, DCL_UINT32 bitmask, DCL_UINT16 value, DCL_UINT32 bank)
{
   DCL_UINT32 temp;
   addr |= (bank << 31);
   temp = (~(bitmask)) & DRV_Read_PMIC_Data(addr);
   temp |= ((value) & (bitmask));
   DRV_Write_PMIC_Data(addr,temp);
}

// MT6353 ECO_E1
void dcl_pmic6353_modem_only_init(void)
{
	// DDUVLO_DEB_EN[0:0] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x6       , 0x1       , 0x1       , 0x0);

	// RG_STRUP_AUXADC_START_SEL[2:2] = 0x1 => Filby, ZF, SW Huang, 12/9
	PMIC_DRV_SetData(0xC       , 0x4       , 0x4       , 0x0);

	// RG_STRUP_AUXADC_RSTB_SEL[3:3] = 0x1 => Filby, ZF, SW Huang, 12/9
	PMIC_DRV_SetData(0xC       , 0x8       , 0x8       , 0x0);

	// STRUP_PWROFF_SEQ_EN[0:0] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0xE       , 0x1       , 0x1       , 0x0);

	// STRUP_PWROFF_PREOFF_EN[1:1] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0xE       , 0x2       , 0x2       , 0x0);

	// RG_STRUP_ENVTEM_CTRL[15:15] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x18      , 0x8000    , 0x8000    , 0x0);

	// RG_STRUP_VCORE2_PG_H2L_EN[4:4] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x10      , 0x10      , 0x0);

	// RG_STRUP_VMCH_PG_H2L_EN[5:5] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x20      , 0x20      , 0x0);

	// RG_STRUP_VMC_PG_H2L_EN[6:6] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x40      , 0x40      , 0x0);

	// RG_STRUP_VUSB33_PG_H2L_EN[7:7] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x80      , 0x80      , 0x0);

	// RG_STRUP_VSRAM_PROC_PG_H2L_EN[8:8] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x100     , 0x100     , 0x0);

	// RG_STRUP_VPROC_PG_H2L_EN[9:9] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x200     , 0x200     , 0x0);

	// RG_STRUP_VDRAM_PG_H2L_EN[10:10] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x400     , 0x400     , 0x0);

	// RG_STRUP_VAUD28_PG_H2L_EN[11:11] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x800     , 0x800     , 0x0);

	// RG_STRUP_VEMC_PG_H2L_EN[12:12] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x1000    , 0x1000    , 0x0);

	// RG_STRUP_VS1_PG_H2L_EN[13:13] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x2000    , 0x2000    , 0x0);

	// RG_STRUP_VCORE_PG_H2L_EN[14:14] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x4000    , 0x4000    , 0x0);

	// RG_STRUP_VAUX18_PG_H2L_EN[15:15] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x1C      , 0x8000    , 0x8000    , 0x0);

	// RG_RST_DRVSEL[12:12] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x24      , 0x1000    , 0x1000    , 0x0);

	// RG_EN_DRVSEL[13:13] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x24      , 0x2000    , 0x2000    , 0x0);

	// RG_SRCLKEN_IN0_HW_MODE[4:4] = 0x1 => Lan, 12/7
	PMIC_DRV_SetData(0x204     , 0x10      , 0x10      , 0x0);

	// RG_SRCLKEN_IN1_HW_MODE[5:5] = 0x1 => Lan, 12/7
	PMIC_DRV_SetData(0x204     , 0x20      , 0x20      , 0x0);

	// RG_OSC_SEL_HW_MODE[6:6] = 0x1 => Lan, 12/7
	PMIC_DRV_SetData(0x204     , 0x40      , 0x40      , 0x0);

	// RG_SMT_WDTRSTB_IN[0:0] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x222     , 0x1       , 0x1       , 0x0);

	// RG_SMT_HOMEKEY[1:1] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x222     , 0x2       , 0x2       , 0x0);

	// RG_SMT_SRCLKEN_IN0[2:2] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x222     , 0x4       , 0x4       , 0x0);

	// RG_SMT_SRCLKEN_IN1[3:3] = 0x1 => 12/1 , Kim
	PMIC_DRV_SetData(0x222     , 0x8       , 0x8       , 0x0);

	// CLK_75K_32K_SEL[2:2] = 0x1 => Angela/ IC, 12/10
	PMIC_DRV_SetData(0x268     , 0x4       , 0x4       , 0x0);

	// CLK_LDO_CALI_75K_CK_PDN[0:0] = 0x1 => 12/24, ZF, power down, align fly mode. LDO auto calibration, so far PMIC not operate the function. 
	PMIC_DRV_SetData(0x27A     , 0x1       , 0x1       , 0x0);

	// CLK_G_SMPS_AUD_CK_PDN_HWEN[1:1] = 0x0 => 12/24, ZF, type-C work around function.( Sleep mode need operate, need this clk)
	PMIC_DRV_SetData(0x286     , 0x2       , 0x0       , 0x0);

	// CLK_BUCK_VPA_9M_CK_PDN_HWEN[9:9] = 0x0 => 12/24, ZF, need SW mode for MD/PA control
	PMIC_DRV_SetData(0x286     , 0x200     , 0x0       , 0x0);

	// BUCK_VPA_EN_OC_SDN_SEL[4:4] = 0x1 => Willy, 12/7
	PMIC_DRV_SetData(0x422     , 0x10      , 0x10      , 0x0);

	// RG_VSRAM_PROC_VSLEEP_VOLTAGE[4:3] = 0x0 => Chc, 12/9,  Design 00: 0.7V
	PMIC_DRV_SetData(0x43E     , 0x18      , 0x0       , 0x0);

	// RG_VPA_RZSEL[1:0] = 0x1 => 2/2, Mason/ CW/ Yichia/ SJ/ Ice,  VPA corner issue. 2/18, Jade Minus HW Project meeting.
	PMIC_DRV_SetData(0x440     , 0x3       , 0x1       , 0x0);

	// RG_VPA_CSMIR[7:6] = 0x2 => 2/2, Mason/ CW/ Yichia/ SJ/ Ice,  VPA corner issue. 2/18, Jade Minus HW Project meeting.
	PMIC_DRV_SetData(0x440     , 0xC0      , 0x80      , 0x0);

	// RG_VPA_SLP[11:10] = 0x2 => 2/2, Mason/ CW/ Yichia/ SJ/ Ice,  VPA corner issue. 2/18, Jade Minus HW Project meeting.
	PMIC_DRV_SetData(0x440     , 0xC00     , 0x800     , 0x0);

	// RG_VPA_ZX_OS[7:6] = 0x3 => 2/2, Mason/ CW/ Yichia/ SJ/ Ice,  VPA corner issue. 2/18, Jade Minus HW Project meeting.
	PMIC_DRV_SetData(0x442     , 0xC0      , 0xC0      , 0x0);

	// RG_VCORE_RZSEL[6:4] = 0x4 => 1/20, Tim/ YT/ Ice, for VCORE/ VCORE2 transient improve & stability confirm in Corner. 2/18, Jade Minus HW Project meeting.
	PMIC_DRV_SetData(0x448     , 0x70      , 0x40      , 0x0);

	// DA_QI_VS1_BURST[10:8] = 0x5 => YT, 12/7
	PMIC_DRV_SetData(0x466     , 0x700     , 0x500     , 0x0);

	// RG_VCORE2_RZSEL[6:4] = 0x4 => 1/20, Tim/ YT/ Ice, for VCORE/ VCORE2 transient improve & stability confirm in Corner. 2/18, Jade Minus HW Project meeting.
	PMIC_DRV_SetData(0x46A     , 0x70      , 0x40      , 0x0);

	// BUCK_VPROC_VOSEL_CTRL[1:1] = 0x1 => 12/22 Align with fly suspend mode, ZF/ Kashi/ Willy/Chia-Lin/ Mark. No DVS VOSEL in SW mode.
	PMIC_DRV_SetData(0x600     , 0x2       , 0x2       , 0x0);

	// BUCK_VPROC_VOSEL_SEL[5:3] = 0x0 => ZF, align with default if no FS mode, 12/15
	PMIC_DRV_SetData(0x602     , 0x38      , 0x0       , 0x0);

	// BUCK_VPROC_SFCHG_FRATE[6:0] = 0x11 => Tim, 12/9
	PMIC_DRV_SetData(0x606     , 0x7F      , 0x11      , 0x0);

	// BUCK_VPROC_SFCHG_RRATE[14:8] = 0x4 => Tim, 12/9
	PMIC_DRV_SetData(0x606     , 0x7F00    , 0x400     , 0x0);

	// BUCK_VPROC_TRANS_TD[1:0] = 0x3 => Tim, 12/9
	PMIC_DRV_SetData(0x610     , 0x3       , 0x3       , 0x0);

	// BUCK_VPROC_TRANS_CTRL[5:4] = 0x1 => Tim, 12/9
	PMIC_DRV_SetData(0x610     , 0x30      , 0x10      , 0x0);

	// BUCK_VPROC_VSLEEP_EN[8:8] = 0x1 => Willy, 12/9
	PMIC_DRV_SetData(0x610     , 0x100     , 0x100     , 0x0);

	// BUCK_VS1_VOSEL_CTRL[1:1] = 0x1 => Lan, 12/7, VOSEL HW mode
	PMIC_DRV_SetData(0x612     , 0x2       , 0x2       , 0x0);

	// BUCK_VS1_VOSEL[6:0] = 0x50 => Willy, 12/9
	PMIC_DRV_SetData(0x620     , 0x7F      , 0x50      , 0x0);

	// BUCK_VS1_VSLEEP_EN[8:8] = 0x1 => Willy, 12/9, sleep HW mode
	PMIC_DRV_SetData(0x626     , 0x100     , 0x100     , 0x0);

	// BUCK_VCORE_VOSEL_CTRL[1:1] = 0x1 => Willy, 12/9, VOSEL HW mode
	PMIC_DRV_SetData(0x628     , 0x2       , 0x2       , 0x0);

	// BUCK_VCORE_VOSEL_SEL[5:3] = 0x0 => ZF, align with default if no FS mode, 12/15
	PMIC_DRV_SetData(0x62A     , 0x38      , 0x0       , 0x0);

	// BUCK_VCORE_SFCHG_FRATE[6:0] = 0x11 => Tim, 12/9
	PMIC_DRV_SetData(0x62E     , 0x7F      , 0x11      , 0x0);

	// BUCK_VCORE_SFCHG_RRATE[14:8] = 0x4 => Tim, 12/9
	PMIC_DRV_SetData(0x62E     , 0x7F00    , 0x400     , 0x0);

	// BUCK_VCORE_TRANS_TD[1:0] = 0x3 => Tim, 12/9
	PMIC_DRV_SetData(0x638     , 0x3       , 0x3       , 0x0);

	// BUCK_VCORE_VSLEEP_EN[8:8] = 0x1 => Tim, 12/9, sleep HW mode
	PMIC_DRV_SetData(0x638     , 0x100     , 0x100     , 0x0);

	// BUCK_VCORE2_VOSEL_CTRL[1:1] = 0x1 => Tim, 12/9, VOSEL HW mode
	PMIC_DRV_SetData(0x63A     , 0x2       , 0x2       , 0x0);

	// BUCK_VCORE2_VOSEL_SEL[5:3] = 0x0 => ZF, align with default if no FS mode, 12/15
	PMIC_DRV_SetData(0x63C     , 0x38      , 0x0       , 0x0);

	// BUCK_VCORE2_SFCHG_FRATE[6:0] = 0x11 => Tim, 12/9
	PMIC_DRV_SetData(0x640     , 0x7F      , 0x11      , 0x0);

	// BUCK_VCORE2_SFCHG_RRATE[14:8] = 0x4 => Tim, 12/9
	PMIC_DRV_SetData(0x640     , 0x7F00    , 0x400     , 0x0);

	// BUCK_VCORE2_TRANS_TD[1:0] = 0x3 => Tim, 12/9
	PMIC_DRV_SetData(0x64A     , 0x3       , 0x3       , 0x0);

	// BUCK_VCORE2_VSLEEP_EN[8:8] = 0x1 => Tim, 12/9, Sleep HW mode
	PMIC_DRV_SetData(0x64A     , 0x100     , 0x100     , 0x0);

	// BUCK_VPA_SFCHG_FRATE[6:0] = 0x0 => 2/2, Mason/ CW/ Yichia/ SJ/ Ice,  VPA corner issue. 2/18, Jade Minus HW Project meeting.
	PMIC_DRV_SetData(0x64E     , 0x7F      , 0x0       , 0x0);

	// BUCK_VPA_SFCHG_RRATE[14:8] = 0x1 => 2/2, Mason/ CW/ Yichia/ SJ/ Ice,  VPA corner issue. 2/18, Jade Minus HW Project meeting.
	PMIC_DRV_SetData(0x64E     , 0x7F00    , 0x100     , 0x0);

	// BUCK_VPA_DVS_BW_TD[9:8] = 0x1 => Mason, 12/9
	PMIC_DRV_SetData(0x654     , 0x300     , 0x100     , 0x0);

	// LDO_VLDO28_FAST_TRAN_CL_EN[8:8] = 0x0 => Willy: No Constant load
	PMIC_DRV_SetData(0xA1E     , 0x100     , 0x0       , 0x0);

	// LDO_VSRAM_PROC_VOSEL_CTRL[1:1] = 0x1 => Willy, 12/9, VOSEL HW mode
	PMIC_DRV_SetData(0xA20     , 0x2       , 0x2       , 0x0);

	// LDO_VSRAM_PROC_VOSEL_SEL[5:3] = 0x0 => ZF, align with default if no FS mode, 12/15
	PMIC_DRV_SetData(0xA20     , 0x38      , 0x0       , 0x0);

	// LDO_VRF12_FAST_TRAN_CL_EN[8:8] = 0x0 => Willy, 12/9, off fast transient
	PMIC_DRV_SetData(0xA46     , 0x100     , 0x0       , 0x0);

	// LDO_VDRAM_FAST_TRAN_CL_EN[8:8] = 0x0 => Willy, 12/9, off constant load
	PMIC_DRV_SetData(0xA6C     , 0x100     , 0x0       , 0x0);

	// LDO_VMC_OCFB_EN[9:9] = 0x1 => Willy, 12/7, Turn on OCFB
	PMIC_DRV_SetData(0xA7C     , 0x200     , 0x200     , 0x0);

	// LDO_VMC_FAST_TRAN_CL_EN[8:8] = 0x0 => Willy, 12/25, disable constant load for VMC
	PMIC_DRV_SetData(0xA7E     , 0x100     , 0x0       , 0x0);

	// LDO_VMCH_OCFB_EN[9:9] = 0x1 => Willy, 12/7, Turn on OCFB
	PMIC_DRV_SetData(0xA82     , 0x200     , 0x200     , 0x0);

	// LDO_VMCH_FAST_TRAN_CL_EN[8:8] = 0x0 => Willy, 12/7, turm off constant load
	PMIC_DRV_SetData(0xA84     , 0x100     , 0x0       , 0x0);

	// LDO_VEMC33_FAST_TRAN_CL_EN[8:8] = 0x0 => 12/25, disable constant load for fast transient.
	PMIC_DRV_SetData(0xA8E     , 0x100     , 0x0       , 0x0);

	// RG_VMCH_VOSEL[9:8] = 0x1 => 12/16, VMCH=3.0V
	PMIC_DRV_SetData(0xAB2     , 0x300     , 0x100     , 0x0);

	// RG_VEMC33_CL_EN[9:9] = 0x0 => 12/25, turn off dummy load
	PMIC_DRV_SetData(0xAB8     , 0x200     , 0x0       , 0x0);

	// RG_VMC_VOSEL[10:8] = 0x6 => 12/16, VMCH=3.0V
	PMIC_DRV_SetData(0xAC2     , 0x700     , 0x600     , 0x0);

	// RG_VDRAM_PCUR_CAL[13:12] = 0x3 => 1/28,Robert/ Chc/ Ice, for VDRAM SS Corner DCS Ringing Issue. 2/16, Arnold_Y/ Ice, DRAM stress evaluation. 2/18, Jade Minus HW Project meeting.
	PMIC_DRV_SetData(0xAD4     , 0x3000    , 0x3000    , 0x0);

	// AUXADC_TRIM_CH2_SEL[5:4] = 0x1 => 12/9, Filby, Chuan-hung
	PMIC_DRV_SetData(0xEB4     , 0x30      , 0x10      , 0x0);

	// AUXADC_TRIM_CH3_SEL[7:6] = 0x1 => 12/9, Filby, Chuan-hung
	PMIC_DRV_SetData(0xEB4     , 0xC0      , 0x40      , 0x0);

	// AUXADC_TRIM_CH4_SEL[9:8] = 0x1 => 12/9, Filby, Chuan-hung
	PMIC_DRV_SetData(0xEB4     , 0x300     , 0x100     , 0x0);

	// AUXADC_TRIM_CH5_SEL[11:10] = 0x1 => 12/9, Filby, Chuan-hung
	PMIC_DRV_SetData(0xEB4     , 0xC00     , 0x400     , 0x0);

	// AUXADC_TRIM_CH6_SEL[13:12] = 0x1 => 12/9, Filby, Chuan-hung
	PMIC_DRV_SetData(0xEB4     , 0x3000    , 0x1000    , 0x0);

	// AUXADC_TRIM_CH7_SEL[15:14] = 0x2 => 12/9, Filby, Chuan-hung
	PMIC_DRV_SetData(0xEB4     , 0xC000    , 0x8000    , 0x0);

	// AUXADC_TRIM_CH8_SEL[1:0] = 0x1 => 12/9, Filby, Chuan-hung
	PMIC_DRV_SetData(0xEB6     , 0x3       , 0x1       , 0x0);

	// AUXADC_TRIM_CH9_SEL[3:2] = 0x1 => 12/9, Filby, Chuan-hung
	PMIC_DRV_SetData(0xEB6     , 0xC       , 0x4       , 0x0);

	// AUXADC_TRIM_CH10_SEL[5:4] = 0x1 => 12/9, Filby, Chuan-hung
	PMIC_DRV_SetData(0xEB6     , 0x30      , 0x10      , 0x0);

	// AUXADC_TRIM_CH11_SEL[7:6] = 0x1 => 12/9, Filby, Chuan-hung
	PMIC_DRV_SetData(0xEB6     , 0xC0      , 0x40      , 0x0);

	// AUXADC_START_SHADE_EN[14:14] = 0x1 => 12/9, Chuan-Hung
	PMIC_DRV_SetData(0xEC8     , 0x4000    , 0x4000    , 0x0);

	// AUXADC_MDBG_DET_PRD[9:0] = 0xC => Filby, ZF, SW Huang, 12/9
	PMIC_DRV_SetData(0xF18     , 0x3FF     , 0xC       , 0x0);

	// AUXADC_MDRT_DET_PRD[9:0] = 0xC => Filby, ZF, SW Huang, 12/9
	PMIC_DRV_SetData(0xF1E     , 0x3FF     , 0xC       , 0x0);

	// AUXADC_MDRT_DET_EN[15:15] = 0x1 => Filby, ZF, SW Huang, 12/9
	PMIC_DRV_SetData(0xF1E     , 0x8000    , 0x8000    , 0x0);

	// AUXADC_MDRT_DET_WKUP_EN[2:2] = 0x1 => Filby, ZF, SW Huang, 12/9
	PMIC_DRV_SetData(0xF22     , 0x4       , 0x4       , 0x0);

}
