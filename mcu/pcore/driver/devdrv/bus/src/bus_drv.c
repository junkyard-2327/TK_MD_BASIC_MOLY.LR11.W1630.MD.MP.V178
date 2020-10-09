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
 * -----------
 *   bus_drv.c
 *
 * Project:
 * -----------
 *   MOLY
 *
 * Description:
 * ------------
 *   Bus Related Driver Code
 *   (Refer to WR8's Bus Driver API Interface, But Not Include Prefetch Buffer API)
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 11 24 2016 shin-chieh.tsai
 * [MOLY00214885] [MT6750S][System Service]Update bus driver setting definition for ROSA
 * .
 *
 * 05 13 2016 shin-chieh.tsai
 * [MOLY00179246] [Olympus][Bus][System Service] Update Olympus SMI setting on bus driver
 * Add Olympus defined flavor in bus related files.
 *
 * 01 07 2016 wellken.chen
 * [MOLY00156467] [Bus][System Service] Patch back from LR11.W1539 to LR11
 *
 * 09 09 2015 wellken.chen
 * [MOLY00141202] [MT6755][Bus][System Service] Enable pscore APB postwrite function
 *
 * 08 07 2015 wellken.chen
 * [MOLY00136101] [Bus][System Service] Update Jade & Everest SMI setting on bus driver
 *
 * 08 07 2015 wellken.chen
 * [MOLY00136101] [Bus][System Service] Update Jade & Everest SMI setting on bus driver
 *
 * 07 29 2015 wellken.chen
 * [MOLY00133297] [MD2AP Interface][System Service] Add md2ap interface value dump with bus driver dump
 *
 * 07 22 2015 wellken.chen
 * [MOLY00130947] [BUS][ELM][System Service] Move ELM init function into set smi function, because ELM clock need to re-init while dorment back
 *
 * 07 08 2015 wellken.chen
 * [MOLY00127295] [Bus] Reset the default bus debugging value
 *
 * 06 23 2015 wellken.chen
 * [MOLY00123496] [MT6755][BRINGUP_FIRSTCALL][Bus][System Service] Update bus driver for domain setting and Jade
 *
 * 06 18 2015 wellken.chen
 * [MOLY00122375] [Bus][System Service] Disable pscore AXI2AHB bufferable function
 *
 * 04 10 2015 wellken.chen
 * [MOLY00099511] [TK6291] Update SMI realted setting
 *
 * 04 08 2015 wellken.chen
 * [MOLY00106212] [SPV][TK6291] Update SPV related API
 *
 * 03 18 2015 wellken.chen
 * [MOLY00099511] [TK6291] Update SMI realted setting
 *
 * 02 09 2015 wellken.chen
 * [MOLY00092944] [Bus][TK6291] Disable l1 system post write buffer function in bus driver init
 *
 * 07 31 2014 wellken.chen
 * [MOLY00074124] [SystemService][DebuggingSuite][TK6291] Support multi-core exception
 *
 ****************************************************************************/
#include "bus_drv.h"
#include "reg_base.h"
#include "kal_public_api.h"

#include "elm.h"
#include "drv_mdap_interface.h"
/*************************************************************************
 * Define HW register
 *************************************************************************/
#define MDINFRABUS_BASE		(BASE_MADDR_MDSMICFG)

#if defined(TK6291)	
#define MEMINFRABUS_BASE	(BASE_MADDR_MEMINFRA_DMA_SMI)
#else
#define MEMINFRABUS_BASE	(BASE_MADDR_APINFRA_MD_SMI)
#endif


#define PSMCU_BUS_TOP_CTRL_REG0		(volatile kal_uint32 *)(BASE_MADDR_PSMCU_MISC_REG + 0x07C)
#define PSMCU_BUS_TOP_CTRL_REG1		(volatile kal_uint32 *)(BASE_MADDR_PSMCU_MISC_REG + 0x080)
#define PSMCU_BRIDGE_CTRL_REG0		(volatile kal_uint32 *)(BASE_MADDR_PSMCU_MISC_REG + 0x098)

//domain related, from MPU owner
#define P_MCUDOMAIN              	(volatile kal_uint32 *)(BASE_MADDR_MDPERIMISC + 0xF0)
#define P_BUS_AXIDOMAIN				(volatile kal_uint32 *)(BASE_MADDR_MDPERIMISC + 0x28)

/*******************************************************************************
 * Locally Used Macro Function
 *******************************************************************************/
typedef struct _BUSDRV_INFO {
    kal_uint32      busErr_Cfg;
    kal_uint32      busErr_Addr;

    kal_uint32      busErr_Domain;
    kal_uint32      busErr_MID;
    
    kal_uint32      busDrv_Status0;
    kal_uint32      busDrv_Status1;

    kal_uint32      dummy0;
    kal_uint32      dummy1;
} BUSDRV_INFO;



BUSDRV_INFO pbusInfo = {0};


#ifdef __MTK_TARGET__ /* should NOT be compiled on MODIS */
kal_bool BusDrv_VirtualMapping(kal_uint8 enable)
{
	//pcore sys default virtual mapping always is enable, can't disable it
	//bankA = bank0
	//bankB = bank1
	return KAL_TRUE;
}

kal_bool BusDrv_MCUOutstanding(kal_uint8 enable)
{
	//pcore sys default mcu outstanding = enable
	//psmcu_misc: 0xF020007C, psmcu_axi_cr4_si_outstanding_disable, bit[20], default = 0x0
	return KAL_TRUE;
}

kal_bool BusDrv_Enable_PostWriteBuffer(kal_uint8 enable)
{
	//pcore sys has no pwb
	return KAL_TRUE;
}

kal_bool BusDrv_Enable_PrefetchBuffer(kal_uint8 enable)
{
	//pcore sys has pfb driver, not including in bus driver
	return KAL_TRUE;
}

#if 0	//pscore needn't control L1 SMI
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

kal_bool BusDrv_Set_MDInfraBus_SMI(void)
{
	//larb0 REG2DMA
	*(volatile kal_uint32 *)(MDINFRABUS_BASE + 0x104) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb0: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb0: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb0: enable outstanding control
													(0x01	<< 19) +	//reg_smi_ostd_w_max_larb0: 1W
													(0x01	<< 14) +	//reg_smi_ostd_r_max_larb0: 1R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb0: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb0: enable bw limiter
													(0xC5);				//reg_smi_filter_max_gnt_larb0: max BW R=M, W=M
	//larb1 GDMA
	*(volatile kal_uint32 *)(MDINFRABUS_BASE + 0x108) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb1: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb1: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb1: enable outstanding control
													(0x01	<< 19) +	//reg_smi_ostd_w_max_larb1: 1W
													(0x01	<< 14) +	//reg_smi_ostd_r_max_larb1: 1R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb1: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb1: enable bw limiter
													(0xC5);				//reg_smi_filter_max_gnt_larb1: max BW R=M, W=M

	//larb2 HSPAL2
	*(volatile kal_uint32 *)(MDINFRABUS_BASE + 0x10C) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb2: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb2: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb2: enable outstanding control
													(0x01	<< 19) +	//reg_smi_ostd_w_max_larb2: 1W
													(0x01	<< 14) +	//reg_smi_ostd_r_max_larb2: 1R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb2: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb2: enable bw limiter
													(0xC5);				//reg_smi_filter_max_gnt_larb2: max BW R=M, W=M
	//larb3 L1SYS2MD
	*(volatile kal_uint32 *)(MDINFRABUS_BASE + 0x110) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb3: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb3: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb3: enable outstanding control
													(0xF	<< 19) +	//reg_smi_ostd_w_max_larb3: 16W
													(0xC	<< 14) +	//reg_smi_ostd_r_max_larb3: 16R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb3: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb3: enable bw limiter
													(0x6EF);				//reg_smi_filter_max_gnt_larb3: max BW R=145M, W=115M

	//larb4 ARM7
	*(volatile kal_uint32 *)(MDINFRABUS_BASE + 0x114) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb4: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb4: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb4: enable outstanding control
													(0x01	<< 19) +	//reg_smi_ostd_w_max_larb4: 1W
													(0x01	<< 14) +	//reg_smi_ostd_r_max_larb4: 1R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb4: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb4: enable bw limiter
													(0xC5);				//reg_smi_filter_max_gnt_larb4: max BW R=145M, W=115M
													
	//larb5 PSPERI
	*(volatile kal_uint32 *)(MDINFRABUS_BASE + 0x118) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb5: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb5: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb5: enable outstanding control
													(0x01	<< 19) +	//reg_smi_ostd_w_max_larb5: 1W
													(0x01	<< 14) +	//reg_smi_ostd_r_max_larb5: 1R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb5: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb5: enable bw limiter
													(0xC5);				//reg_smi_filter_max_gnt_larb5: max BW R=145M, W=115M
													
	//larb6 L2DMA
	*(volatile kal_uint32 *)(MDINFRABUS_BASE + 0x11C) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb6: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb6: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb6: enable outstanding control
													(0x04	<< 19) +	//reg_smi_ostd_w_max_larb6: 4W
													(0x04	<< 14) +	//reg_smi_ostd_r_max_larb6: 4R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb6: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb6: enable bw limiter
													(0x2A0);				//reg_smi_filter_max_gnt_larb6: max BW R=99M, W=70M

	//larb7 ADOE
	*(volatile kal_uint32 *)(MDINFRABUS_BASE + 0x120) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb6: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb6: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb6: enable outstanding control
													(0x01	<< 19) +	//reg_smi_ostd_w_max_larb6: 1W
													(0x01	<< 14) +	//reg_smi_ostd_r_max_larb6: 1R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb6: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb6: enable bw limiter
													(0xC5);				//reg_smi_filter_max_gnt_larb6: max BW R=145M, W=115M

	return KAL_TRUE;
}


kal_bool BusDrv_Set_MEMInfraBus_SMI(void)
{
	//TK6291 is MEM sys
	//others is APinfra sys
#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
	//larb0 MDDMA2EMI
	*(volatile kal_uint32 *)(MEMINFRABUS_BASE + 0x104) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb0: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb0: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb0: enable outstanding control
													(0x16	<< 19) +	//reg_smi_ostd_w_max_larb0: 22W
													(0x16	<< 14) +	//reg_smi_ostd_r_max_larb0: 22R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb0: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb0: enable bw limiter
													(0x98F);			//reg_smi_filter_max_gnt_larb0: max BW R=300M, W=500M
	//larb1 LTEL1SYS2EMI
	*(volatile kal_uint32 *)(MEMINFRABUS_BASE + 0x108) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb0: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb1: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb1: enable outstanding control
													(0xF	<< 19) +	//reg_smi_ostd_w_max_larb1: 16W
													(0xF	<< 14) +	//reg_smi_ostd_r_max_larb1: 16R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb1: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb1: enable bw limiter
													(0x6FB);			//reg_smi_filter_max_gnt_larb1: max BW R=200M, W=380M
#endif
	return KAL_TRUE;
}

kal_bool BusDrv_SetSMI(void)
{
#if defined(TK6291)
	//=================================================	
	//TK6291 if enable AXI2AHB path bufferable function
	//bankF APB transaction might change to bankB
	//bank6 might change to bank2, address bit[30] will has issue!!!
	//=================================================	
	//disable psmcu_axi_ps2reg_slice_postwrite_dis
	//0xF020007C bit[25]: 0x0=>0x1
	*PSMCU_BUS_TOP_CTRL_REG0 |= 0x2000000;

	//disable psmcu_axi_ps2reg_x2h_buffer_en
	//0xF0200080 bit[0]: 0x1=>0x0
	*PSMCU_BUS_TOP_CTRL_REG1 &= ~(0x1);

	//disable psmcu_bridge_psmcu2reg_aslice_postwrite_dis
	//0xF0200098 bit[8]: 0x0=>0x1
	*PSMCU_BRIDGE_CTRL_REG0 |= 0x100;
#endif

	//reset pscore domain setting, from mpu owner providing setting
	*P_BUS_AXIDOMAIN = 0x00777771;

	//ELM default is gated, need dormant reset again
	ELM_INIT();

	//l1core needs to set MDINFRABUS_BASE & MEMINFRABUS_BASE
	BusDrv_Set_MDInfraBus_SMI();
	BusDrv_Set_MEMInfraBus_SMI();

	return KAL_TRUE;	
}

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
#endif
kal_bool BusDrv_Init(void)
{
    //reset bus driver info
    kal_mem_set(&pbusInfo, 0, sizeof(BUSDRV_INFO));

	//initial smi related setting
	BusDrv_SetSMI();
	
	//BusDrv_Test_Misc();

    return KAL_TRUE;
}

kal_bool BusDrv_GetDumpInfo(void **ppstart, kal_uint32 *pu32Len)
{
    pbusInfo.busErr_Cfg = 0;
    pbusInfo.busErr_Addr = 0;

    pbusInfo.busErr_Domain = 0;
    pbusInfo.busErr_MID = 0;

    pbusInfo.busDrv_Status0 = 0;
    pbusInfo.busDrv_Status1 = 0;

    pbusInfo.dummy0 = 0;
    pbusInfo.dummy1 = 0;

    *ppstart = (void*)(&pbusInfo);
    *pu32Len = sizeof(BUSDRV_INFO);

	Drv_MDAPInterface_Dump();	
    return KAL_TRUE;
}

#endif /* should NOT be compiled on MODIS */
