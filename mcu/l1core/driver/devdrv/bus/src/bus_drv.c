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
 * 11 20 2015 wellken.chen
 * [MOLY00149896] [Bus][Jade][Everest] Change MDL1A0_L1MCU_PWR_AWARE setting, for Everest AP DCM can't enter issue
 *
 * 10 20 2015 wellken.chen
 * [MOLY00145818] [Bus][MT6797][System Service] Enable l2sram bypass feature on Everest
 *
 * 09 23 2015 wellken.chen
 * [MOLY00136101] [Bus][System Service] Update Jade & Everest SMI setting on bus driver
 *
 * 09 14 2015 wellken.chen
 * [MOLY00136101] [Bus][System Service] Update Jade & Everest SMI setting on bus driver
 *
 * 08 18 2015 wellken.chen
 * [MOLY00136101] [Bus][System Service] Update Jade & Everest SMI setting on bus driver
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
 * 07 29 2015 wellken.chen
 * [MOLY00133212] [Bus][System Service] Add bus config for low power feature
 *
 * 07 22 2015 wellken.chen
 * [MOLY00130947] [BUS][ELM][System Service] Move ELM init function into set smi function, because ELM clock need to re-init while dorment back
 *
 * 07 14 2015 wellken.chen
 * [MOLY00128823] [Jade][Bus] Update Jade L1 SMI setting
 *
 * 07 14 2015 wellken.chen
 * [MOLY00128633] [MT6755][System Service][Bus] Enable L1 APB postwrite function
 *
 * 07 08 2015 wellken.chen
 * [MOLY00127295] [Bus] Reset the default bus debugging value
 *
 * 07 08 2015 wellken.chen
 * [MOLY00127295] [Bus] Reset the default bus debugging value
 *
 * 06 26 2015 wellken.chen
 * [MOLY00123496] [MT6755][BRINGUP_FIRSTCALL][Bus][System Service] Update bus driver for domain setting and Jade
 *
 * 06 23 2015 wellken.chen
 * [MOLY00123496] [MT6755][BRINGUP_FIRSTCALL][Bus][System Service] Update bus driver for domain setting and Jade
 *
 * 05 21 2015 wellken.chen
 * [MOLY00112212] [Bus][System Service] Disable L2SRAM slice function
 *
 * 05 08 2015 wellken.chen
 * [MOLY00112212] [Bus][System Service] Disable L2SRAM slice function
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
 * 08 29 2014 yh.peng
 * [MOLY00076001] [TK6291] Init flow support check in.UMOLY CoSim porting done.
 *
 * 08 25 2014 yh.peng
 * [MOLY00076001] [TK6291] Init flow support check in.Check in for RTL CoSim support.
 *
 * 07 31 2014 wellken.chen
 * [MOLY00074124] [SystemService][DebuggingSuite][TK6291] Support multi-core exception
 *
 * 06 09 2014 yh.peng
 * [MOLY00067412] [TK6291][SystemService] Check in FPGA basic load for bring up to scheduling.
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
#define MDL1AO_L1MCUSYS_BUS_CON1	(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_CONF + 0x204)
#define MDL1A0_L1MCUSYS_BUS_CON2	(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_CONF + 0x208)

#define MDL1A0_L1MCU_PWR_AWARE		(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_CONF + 0x190)
#define MDL1A0_L1AO_PWR_AWARE		(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_CONF + 0x194)

#define MDL1_BUS_AHB_CONFIG1		(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_BUS_CONFG + 0x224)
#define MDL1_BUS_AHB_CONFIG2		(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_BUS_CONFG + 0x228)
#define MDL1_BUS_AHB_CONFIG3		(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_BUS_CONFG + 0x22C)
#define MDL1_BUS_AXI_CONFIG0		(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_BUS_CONFG + 0x400)


#define MDL1SYSBUS_BASE		(L1_BASE_MADDR_L1MCU_SMI_CONFIG)
#define MDINFRABUS_BASE		(BASE_MADDR_MDSMICFG)
#define MEMINFRABUS_BASE	(BASE_MADDR_APINFRA_MD_SMI)


//domain related, from MPU owner
#define MDL1MCU_GDMA_AXIDOMAIN		(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_CONF + 0x220)/*[2:0] MCU and GDMA domain, bit7 for updates should be 1*/
#define MD_L1_BUS_AXIDOMAIN_CON1	(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_BUS_CONFG + 0x450)
#define MD_L1_BUS_AXIDOMAIN_CON2	(volatile kal_uint32 *)(L1_BASE_MADDR_MDL1_BUS_CONFG + 0x454)

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



BUSDRV_INFO l1busInfo = {0};


#ifdef __MTK_TARGET__ /* should NOT be compiled on MODIS */
kal_bool BusDrv_VirtualMapping(kal_uint8 enable)
{
	//l1core sys default virtual mapping default = enable
	//bankA = bank0
	//bankB = bank1
	//modeml1_ao_config: 0xF60F0200 bit[31:28] to control CPU2EMI remapping
	return KAL_TRUE;
}

kal_bool BusDrv_MCUOutstanding(kal_uint8 enable)
{
	//l1core sys default mcu outstanding = enable
	//modeml1_ao_config: 0xF60F020C,  L1MCU2EMI_SI0_OUTSTANDING_DISABLE, bit[12], default = 0x0
	return KAL_TRUE;
}

kal_bool BusDrv_Enable_PostWriteBuffer(kal_uint8 enable)
{
	//l1core sys default post write buffer = enable
	//modeml1_ao_config: 0xF60F0208,  MDL1A0_L1MCUSYS_BUS_CON2, bit[16], default = 0x1

	if (enable)
	{
		*MDL1A0_L1MCUSYS_BUS_CON2 |= 0x10000;
	}
	else
	{
		*MDL1A0_L1MCUSYS_BUS_CON2 &= ~(0x10000);
	}
	
	return KAL_TRUE;
}

kal_bool BusDrv_Enable_APBPostWrite(kal_uint8 enable)
{
#if defined(TK6291)
	//l1core sys default APB post write = disable, must enable this
	//modeml1_ao_config: 0xF68B0224,  	MDL1_BUS_AHB_CONFIG1, bit[16], default = 0x1
	//modeml2_ao_config: 0xF68B0228,  	MDL1_BUS_AHB_CONFIG2, bit[16], default = 0x1
	//modeml3_ao_config: 0xF68B022C,  	MDL1_BUS_AHB_CONFIG3, bit[16], default = 0x1
	if (enable)
	{
		*MDL1_BUS_AHB_CONFIG1 &= ~(0x10000);
		*MDL1_BUS_AHB_CONFIG2 &= ~(0x10000);
		*MDL1_BUS_AHB_CONFIG3 &= ~(0x10000);
	}
	else
	{
		*MDL1_BUS_AHB_CONFIG1 |= 0x10000;
		*MDL1_BUS_AHB_CONFIG2 |= 0x10000;
		*MDL1_BUS_AHB_CONFIG3 |= 0x10000;
	}

#elif defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
	//l1core sys default APB post write = disable, must enable this
	//MDL1_BUS_AHB_CONFIG3: 0xF68B022C,	slv1_post_write_dis, bit[0], default = 0x1
	//MDL1_BUS_AHB_CONFIG3: 0xF68B022C,	slv2_post_write_dis, bit[1], default = 0x1
	//MDL1_BUS_AHB_CONFIG3: 0xF68B022C,	slv3_post_write_dis, bit[2], default = 0x1
	//MDL1_BUS_AHB_CONFIG3: 0xF68B022C,	slv4_post_write_dis, bit[3], default = 0x1
	//MDL1_BUS_AHB_CONFIG3: 0xF68B022C,	slv5_post_write_dis, bit[4], default = 0x1
	//MDL1_BUS_AHB_CONFIG3: 0xF68B022C,	slv6_post_write_dis, bit[5], default = 0x1
	//MDL1_BUS_AHB_CONFIG3: 0xF68B022C,	slv7_post_write_dis, bit[6], default = 0x1

	if (enable)
	{
		*MDL1_BUS_AHB_CONFIG3 &= ~(0x7F);
	}
	else
	{
		*MDL1_BUS_AHB_CONFIG3 |= 0x7F;
	}

#endif
	
	return KAL_TRUE;
}

kal_bool BusDrv_Enable_L2SRAMSliceBypass(kal_uint8 enable)
{
#if defined(MT6797) || defined(MT6757) //Jade might hang while enable this feature
	//l1sys enable l2sram slice
	//MDL1AO_L1MCUSYS_BUS_CON1 0xF60F0204 bit[31],  l2sram_slice_bypass_dis default = 0x1(bypass disable)
	if (enable)
	{
		*MDL1AO_L1MCUSYS_BUS_CON1 &= ~(0x80000000);
	}
	else
	{
		*MDL1AO_L1MCUSYS_BUS_CON1 |= 0x80000000;

	}	
#endif

	return KAL_TRUE;
}


kal_bool BusDrv_Enable_PrefetchBuffer(kal_uint8 enable)
{
	//l1core sys has pfb driver, not including in bus driver
	return KAL_TRUE;
}


kal_bool BusDrv_Set_MDL1SysBus_SMI(void)
{
	//larb0 L1PERI
	*(volatile kal_uint32 *)(MDL1SYSBUS_BASE + 0x104) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb0: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb0: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb0: enable outstanding control
													(0x01	<< 19) +	//reg_smi_ostd_w_max_larb0: 1W
													(0x01	<< 14) +	//reg_smi_ostd_r_max_larb0: 1R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb0: select soft limiter mode
													(0x0	<< 12) +	//reg_smi_bw_filter_en_larb0: enable bw limiter
													(0x51);				//reg_smi_filter_max_gnt_larb0: max BW R=25M, W=25M
	//larb1 DFE
	*(volatile kal_uint32 *)(MDL1SYSBUS_BASE + 0x108) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb1: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb1: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb1: enable outstanding control
													(0x01	<< 19) +	//reg_smi_ostd_w_max_larb1: 1W
													(0x01	<< 14) +	//reg_smi_ostd_r_max_larb1: 1R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb1: select soft limiter mode
													(0x0	<< 12) +	//reg_smi_bw_filter_en_larb1: enable bw limiter
													(0x51);				//reg_smi_filter_max_gnt_larb1: max BW R=25M, W=25M
#if defined(TK6291)
	//larb2 RXBRP
	*(volatile kal_uint32 *)(MDL1SYSBUS_BASE + 0x10C) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb2: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb2: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb2: enable outstanding control
													(0x05	<< 19) +	//reg_smi_ostd_w_max_larb2: 8W
													(0x03	<< 14) +	//reg_smi_ostd_r_max_larb2: 8R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb2: select soft limiter mode
													(0x1	<< 12) +	//reg_smi_bw_filter_en_larb2: enable bw limiter
													(0x68B);			//reg_smi_filter_max_gnt_larb2: max BW R=250M, W=250M
#elif defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
	//larb2 RXBRP
	*(volatile kal_uint32 *)(MDL1SYSBUS_BASE + 0x10C) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb2: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb2: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb2: enable outstanding control
													(0x08	<< 19) +	//reg_smi_ostd_w_max_larb2: 8W
													(0x02	<< 14) +	//reg_smi_ostd_r_max_larb2: 8R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb2: select soft limiter mode
													(0x0	<< 12) +	//reg_smi_bw_filter_en_larb2: enable bw limiter
													(0x68B);			//reg_smi_filter_max_gnt_larb2: max BW R=250M, W=250M
#endif

	//larb3 RAKE/MD2G
	*(volatile kal_uint32 *)(MDL1SYSBUS_BASE + 0x110) = (0x0 <<26) +	//reg_smi_ostd_r_soft_en_larb3: select ostd soft control for read channel
													(0x0	<< 25) +	//reg_smi_ostd_w_soft_en_larb3: select ostd soft control for write channel	
													(0x1	<< 24) +	//reg_smi_ostd_ctrl_en_en_larb3: enable outstanding control
													(0x01	<< 19) +	//reg_smi_ostd_w_max_larb3: 1W
													(0x01	<< 14) +	//reg_smi_ostd_r_max_larb3: 1R
													(0x0	<< 13) +	//reg_smi_hfilter_en_larb3: select soft limiter mode
													(0x0	<< 12) +	//reg_smi_bw_filter_en_larb3: enable bw limiter
													(0x29);				//reg_smi_filter_max_gnt_larb3: max BW R=3M, W=2M

#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
		*(volatile kal_uint32 *)(MDL1_BUS_AXI_CONFIG0) |= 0x3; 
#endif

	return KAL_TRUE;
}

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
#if defined(TK6291)	|| defined(MT6755) || defined(MT6797) || defined(MT6757) ||defined(MT6750S)
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
	//ELM default is gated, need dormant reset again
	ELM_INIT();

	//reset l1core domain setting, from mpu owner providing setting
	*MD_L1_BUS_AXIDOMAIN_CON1 = 0xFFFFFFFF;
	*MD_L1_BUS_AXIDOMAIN_CON2 = 0xFFFFFFFF;

	//enable APB post write function
	//dormant must reset this setting
	BusDrv_Enable_APBPostWrite(1);

	//l1core needs to set MDINFRABUS_BASE & MDL1SYSBUS_BASE & MEMINFRABUS_BASE
	BusDrv_Set_MDInfraBus_SMI();
	BusDrv_Set_MDL1SysBus_SMI();
	BusDrv_Set_MEMInfraBus_SMI();

	return KAL_TRUE;	
}

kal_bool BusDrv_SetLowPowerGolden(void)
{
#if defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
	//enable this for low power golden setting, from DE's request
	*MDL1A0_L1MCU_PWR_AWARE |= 0x702;
	*MDL1A0_L1AO_PWR_AWARE |= 0x1;
#endif
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
#if 1 //test emi force latency related
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
/* under construction !*/
#if 1
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

kal_bool BusDrv_Init(void)
{
	//disable post write buffer feature on l1 sys
	BusDrv_Enable_PostWriteBuffer(0);

    //reset bus driver info
    kal_mem_set(&l1busInfo, 0, sizeof(BUSDRV_INFO));

	//initial smi related setting
	BusDrv_SetSMI();

	//init bus low power golden setting, AO APB
	BusDrv_SetLowPowerGolden();

	//enable l2sram bypass
	BusDrv_Enable_L2SRAMSliceBypass(1);

	//BusDrv_Test_Misc();
    return KAL_TRUE;
}

kal_bool BusDrv_GetDumpInfo(void **ppstart, kal_uint32 *pu32Len)
{
    l1busInfo.busErr_Cfg = 0;
    l1busInfo.busErr_Addr = 0;

    l1busInfo.busErr_Domain = 0;
    l1busInfo.busErr_MID = 0;

    l1busInfo.busDrv_Status0 = 0;
    l1busInfo.busDrv_Status1 = 0;

    l1busInfo.dummy0 = 0;
    l1busInfo.dummy1 = 0;

    *ppstart = (void*)(&l1busInfo);
    *pu32Len = sizeof(BUSDRV_INFO);

	Drv_MDAPInterface_Dump();
    return KAL_TRUE;
}

#endif /* should NOT be compiled on MODIS */
