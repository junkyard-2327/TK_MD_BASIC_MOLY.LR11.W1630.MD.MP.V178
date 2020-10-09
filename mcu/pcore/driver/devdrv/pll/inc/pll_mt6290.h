/*******************************************************************************
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
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   pll_mt6290.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   PLL Related Functions
 *
 * Author:
 * -------
 * -------
 *
 * ============================================================================
 * $Log$
 *
 ******************************************************************************/

#ifndef __PLL_MT6290__
#define __PLL_MT6290__

/*******************************************************************************
 * Locally Used Options
 ******************************************************************************/

/*******************************************************************************
 * Include header files
 ******************************************************************************/

#if !defined(MT6290)
    #error "This header should only be included in MT6290 Project"
#endif

#include "kal_general_types.h"
#include "reg_base.h"

/*******************************************************************************
 * Define exported macro
 ******************************************************************************/

#if PLL_FOR_FPGA
    #define BUS_CLOCK_MHZ       20      // Mostly Used BUS1X Clock Frquency
#else
    #define BUS_CLOCK_MHZ       60      // BUS1X Clock Frequency
#endif

/*******************************************************************************
 * Define data structure
 ******************************************************************************/

/* SPI clock divisor */
typedef enum {
    CLKCTL_SPI_DIV_4 = 0,
    CLKCTL_SPI_DIV_5,
    CLKCTL_SPI_DIV_6,
    CLKCTL_SPI_DIV_7,
    CLKCTL_SPI_DIV_8,
    CLKCTL_SPI_DIV_9,
    CLKCTL_SPI_DIV_10,
    CLKCTL_SPI_DIV_11,
    CLKCTL_SPI_DIV_12,
    CLKCTL_SPI_DIV_14,
    CLKCTL_SPI_DIV_18,
    CLKCTL_SPI_DIV_20,
    CLKCTL_SPI_DIV_26,
    CLKCTL_SPI_DIV_64,
    CLKCTL_SPI_DIV_128,
    CLKCTL_SPI_DIV_256
} spi_clk_div;

/* MSDC clock divisor */
typedef enum {
    CLKCTL_MSDC_PREDIV_1 = 0,
    CLKCTL_MSDC_PREDIV_2,
    CLKCTL_MSDC_PREDIV_3,
    CLKCTL_MSDC_PREDIV_4,
    CLKCTL_MSDC_PREDIV_5,
    CLKCTL_MSDC_PREDIV_6,
    CLKCTL_MSDC_PREDIV_7,
    CLKCTL_MSDC_PREDIV_8
} msdc_clk_pre_div;

typedef enum {
    CLKCTL_MSDC_POSTDIV_1 = 0,
    CLKCTL_MSDC_POSTDIV_2,
    CLKCTL_MSDC_POSTDIV_3,
    CLKCTL_MSDC_POSTDIV_4,
    CLKCTL_MSDC_POSTDIV_5,
    CLKCTL_MSDC_POSTDIV_6,
    CLKCTL_MSDC_POSTDIV_7,
    CLKCTL_MSDC_POSTDIV_8
} msdc_clk_post_div;

/* MSDC PLL selection */
typedef enum {
    MSDC_PLL_208MHZ = 0,
    MSDC_PLL_200MHZ
} msdc_pll_clk;

/* Trace Bus1X selection */
typedef enum {
    TRACE_BUS1X_60MHZ = 0,
    TRACE_BUS1X_61MHZ,
    TRACE_BUS1X_62MHZ,
    TRACE_BUS1X_63MHZ,
    TRACE_BUS1X_64MHZ,
    TRACE_BUS1X_65MHZ
} trace_bus1x_clk;

/*******************************************************************************
 * Define exported function prototype
 ******************************************************************************/

extern void INT_SetPLL_Phase2();

extern void enable_ap_clk();
extern void set_spi_clk_div(spi_clk_div div);
extern void set_msdc0_clk_div(msdc_clk_pre_div prediv, msdc_clk_post_div postdiv);
extern void set_msdc1_clk_div(msdc_clk_pre_div prediv, msdc_clk_post_div postdiv);
extern void set_msdc_pll_clock(msdc_pll_clk clk);
extern void set_trace_bus1x_clock(trace_bus1x_clk clk);

/*******************************************************************************
 * Define HW register
 ******************************************************************************/

#define MDCLKCTL_R_MDCLKCTL_CODA_VERSION    (BASE_ADDR_MDCLKCTL+0x0)
#define MDCLKCTL_CLKONCTL                   (BASE_ADDR_MDCLKCTL+0x4)
#define MDCLKCTL_CLKSRCSEL0                 (BASE_ADDR_MDCLKCTL+0x8)
#define MDCLKCTL_CLKSRCSEL1                 (BASE_ADDR_MDCLKCTL+0xC)
#define MDCLKCTL_CLKSPDCTL	                (BASE_ADDR_MDCLKCTL+0x14)
#define MDCLKCTL_MDCLKONCTL	                (BASE_ADDR_MDCLKCTL+0x18)
#define MDCLKCTL_APCLKONCTL	                (BASE_ADDR_MDCLKCTL+0x1C)
#define MDCLKCTL_CLKSWCCTL	                (BASE_ADDR_MDCLKCTL+0x20)
#define MDCLKCTL_SRCLKEN_CTL	            (BASE_ADDR_MDCLKCTL+0x24)
#define MDCLKCTL_SRCLKEN_CTL2	            (BASE_ADDR_MDCLKCTL+0x28)
#define MDCLKCTL_SLEEP_CNT	                (BASE_ADDR_MDCLKCTL+0x2C)
#define MDCLKCTL_RING_OSC_CTL	            (BASE_ADDR_MDCLKCTL+0x100)
#define MDCLKCTL_RAND_NUM	                (BASE_ADDR_MDCLKCTL+0x104)
#define MDCLKCTL_FREQ_METER_CTL	            (BASE_ADDR_MDCLKCTL+0x108)
#define MDCLKCTL_FREQ_XTAL_CNT	            (BASE_ADDR_MDCLKCTL+0x10C)
#define MDCLKCTL_CKMON_CNT	                (BASE_ADDR_MDCLKCTL+0x110)
#define MDCLKCTL_FREQ_METER_H	            (BASE_ADDR_MDCLKCTL+0x114)
#define MDCLKCTL_FREQ_METER_L	            (BASE_ADDR_MDCLKCTL+0x118)
#define MDCLKCTL_CKMON_CTL	                (BASE_ADDR_MDCLKCTL+0x11C)
#define MDCLKCTL_PLLGP_MONCTL	            (BASE_ADDR_MDCLKCTL+0x300)
#define MDCLKCTL_ARM7PLL_CTL	            (BASE_ADDR_MDCLKCTL+0x308)
#define MDCLKCTL_CR4PLL_CTL	                (BASE_ADDR_MDCLKCTL+0x30C)
#define MDCLKCTL_UNIVPLL_CTL	            (BASE_ADDR_MDCLKCTL+0x310)
#define MDCLKCTL_ISPPLL_CTL	                (BASE_ADDR_MDCLKCTL+0x314)
#define MDCLKCTL_EMIDDS_CTL	                (BASE_ADDR_MDCLKCTL+0x31C)
#define MDCLKCTL_DSPPLL_CTL	                (BASE_ADDR_MDCLKCTL+0x320)
#define MDCLKCTL_LTEWHPLL_CTL	            (BASE_ADDR_MDCLKCTL+0x324)
#define MDCLKCTL_LTEWPLL_CTL	            (BASE_ADDR_MDCLKCTL+0x328)
#define MDCLKCTL_OGTWPLL_CTL	            (BASE_ADDR_MDCLKCTL+0x32C)
#define MDCLKCTL_LTEPLL_CTL0	            (BASE_ADDR_MDCLKCTL+0x330)
#define MDCLKCTL_LTEPLL_CTL1	            (BASE_ADDR_MDCLKCTL+0x334)
#define MDCLKCTL_LTEPLL_CTL2	            (BASE_ADDR_MDCLKCTL+0x338)
#define MDCLKCTL_LTEPLL_CTL3	            (BASE_ADDR_MDCLKCTL+0x33C)
#define MDCLKCTL_TDPLL_CTL0	                (BASE_ADDR_MDCLKCTL+0x340)
#define MDCLKCTL_TDPLL_CTL1	                (BASE_ADDR_MDCLKCTL+0x344)
#define MDCLKCTL_MEMPLL_CTL0	            (BASE_ADDR_MDCLKCTL+0x350)
#define MDCLKCTL_MEMPLL_CTL1	            (BASE_ADDR_MDCLKCTL+0x354)
#define MDCLKCTL_MEMPLL_CTL2	            (BASE_ADDR_MDCLKCTL+0x358)
#define MDCLKCTL_MEMPLL2_CTL0	            (BASE_ADDR_MDCLKCTL+0x35C)
#define MDCLKCTL_MEMPLL2_CTL1	            (BASE_ADDR_MDCLKCTL+0x360)
#define MDCLKCTL_MEMPLL2_CTL2	            (BASE_ADDR_MDCLKCTL+0x364)
#define MDCLKCTL_MEMPLL3_CTL0	            (BASE_ADDR_MDCLKCTL+0x368)
#define MDCLKCTL_MEMPLL3_CTL1	            (BASE_ADDR_MDCLKCTL+0x36C)
#define MDCLKCTL_MEMPLL3_CTL2	            (BASE_ADDR_MDCLKCTL+0x370)
#define MDCLKCTL_MEMPLL4_CTL0	            (BASE_ADDR_MDCLKCTL+0x374)
#define MDCLKCTL_MEMPLL4_CTL1	            (BASE_ADDR_MDCLKCTL+0x378)
#define MDCLKCTL_MEMPLL4_CTL2	            (BASE_ADDR_MDCLKCTL+0x37C)
#define MDCLKCTL_POP_MEMPLL_CTL0	        (BASE_ADDR_MDCLKCTL+0x380)
#define MDCLKCTL_POP_MEMPLL_CTL1	        (BASE_ADDR_MDCLKCTL+0x384)
#define MDCLKCTL_POP_MEMPLL_CTL2	        (BASE_ADDR_MDCLKCTL+0x388)
#define MDCLKCTL_POP_MEMPLL3_CTL0	        (BASE_ADDR_MDCLKCTL+0x38C)
#define MDCLKCTL_POP_MEMPLL3_CTL1	        (BASE_ADDR_MDCLKCTL+0x390)
#define MDCLKCTL_POP_MEMPLL3_CTL2	        (BASE_ADDR_MDCLKCTL+0x394)
#define MDCLKCTL_MEMPLL_JMETER_CTL	        (BASE_ADDR_MDCLKCTL+0x398)
#define MDCLKCTL_MEMPLL0_JMETER_STS	        (BASE_ADDR_MDCLKCTL+0x3A0)
#define MDCLKCTL_MEMPLL1_JMETER_STS	        (BASE_ADDR_MDCLKCTL+0x3A4)
#define MDCLKCTL_MEMPLL2_JMETER_STS	        (BASE_ADDR_MDCLKCTL+0x3A8)
#define MDCLKCTL_MEMPLL3_JMETER_STS	        (BASE_ADDR_MDCLKCTL+0x3AC)
#define MDCLKCTL_MEMPLL_PCW	                (BASE_ADDR_MDCLKCTL+0x3B0)
#define MDCLKCTL_POP_MEMPLL_PCW	            (BASE_ADDR_MDCLKCTL+0x3B4)
#define MDCLKCTL_PLL_FORCE_ON	            (BASE_ADDR_MDCLKCTL+0x400)
#define MDCLKCTL_MDTOPSM_SW_CTL	            (BASE_ADDR_MDCLKCTL+0x404)
#define MDCLKCTL_APTOPSM_SW_CTL	            (BASE_ADDR_MDCLKCTL+0x408)
#define MDCLKCTL_LTEL1_TOPSM_SW_CTL	        (BASE_ADDR_MDCLKCTL+0x40C)
#define MDCLKCTL_MODEM_TOPSM_SW_CTL	        (BASE_ADDR_MDCLKCTL+0x410)
#define MDCLKCTL_PLL_DLY_CTL0	            (BASE_ADDR_MDCLKCTL+0x420)
#define MDCLKCTL_PLL_DLY_CTL1	            (BASE_ADDR_MDCLKCTL+0x424)
#define MDCLKCTL_PLL_DLY_CTL2           	(BASE_ADDR_MDCLKCTL+0x428)
#define MDCLKCTL_PLL_DLY_CTL3	            (BASE_ADDR_MDCLKCTL+0x42C)
#define MDCLKCTL_PLL_DLY_CTL4	            (BASE_ADDR_MDCLKCTL+0x430)
#define MDCLKCTL_PLL_DLY_CTL5	            (BASE_ADDR_MDCLKCTL+0x434)
#define MDCLKCTL_PLL_ON_CTL0	            (BASE_ADDR_MDCLKCTL+0x438)
#define MDCLKCTL_PLL_ON_CTL1	            (BASE_ADDR_MDCLKCTL+0x43C)
#define MDCLKCTL_PLL_ON_CTL2	            (BASE_ADDR_MDCLKCTL+0x440)
#define MDCLKCTL_PLL_ON_CTL3	            (BASE_ADDR_MDCLKCTL+0x444)
#define MDCLKCTL_DCXO_ON_CTL	            (BASE_ADDR_MDCLKCTL+0x448)
#define MDCLKCTL_PLLFH_CTL	                (BASE_ADDR_MDCLKCTL+0x500)
#define MDCLKCTL_CR4PLL_FH_CTL1	            (BASE_ADDR_MDCLKCTL+0x524)
#define MDCLKCTL_CR4PLL_FH_CTL2	            (BASE_ADDR_MDCLKCTL+0x528)
#define MDCLKCTL_CR4PLL_FH_CTL3	            (BASE_ADDR_MDCLKCTL+0x52C)
#define MDCLKCTL_CR4PLL_FH_CTL4	            (BASE_ADDR_MDCLKCTL+0x530)
#define MDCLKCTL_CR4PLL_FH_CTL5	            (BASE_ADDR_MDCLKCTL+0x534)
#define MDCLKCTL_ARM7PLL_FH_CTL1	        (BASE_ADDR_MDCLKCTL+0x544)
#define MDCLKCTL_ARM7PLL_FH_CTL2	        (BASE_ADDR_MDCLKCTL+0x548)
#define MDCLKCTL_ARM7PLL_FH_CTL3	        (BASE_ADDR_MDCLKCTL+0x54C)
#define MDCLKCTL_ARM7PLL_FH_CTL4	        (BASE_ADDR_MDCLKCTL+0x550)
#define MDCLKCTL_ARM7PLL_FH_CTL5	        (BASE_ADDR_MDCLKCTL+0x554)
#define MDCLKCTL_DSPPLL_FH_CTL1	            (BASE_ADDR_MDCLKCTL+0x564)
#define MDCLKCTL_DSPPLL_FH_CTL2	            (BASE_ADDR_MDCLKCTL+0x568)
#define MDCLKCTL_DSPPLL_FH_CTL3	            (BASE_ADDR_MDCLKCTL+0x56C)
#define MDCLKCTL_DSPPLL_FH_CTL4	            (BASE_ADDR_MDCLKCTL+0x570)
#define MDCLKCTL_DSPPLL_FH_CTL5	            (BASE_ADDR_MDCLKCTL+0x574)
#define MDCLKCTL_ISPPLL_FH_CTL1	            (BASE_ADDR_MDCLKCTL+0x5A4)
#define MDCLKCTL_ISPPLL_FH_CTL2	            (BASE_ADDR_MDCLKCTL+0x5A8)
#define MDCLKCTL_ISPPLL_FH_CTL3	            (BASE_ADDR_MDCLKCTL+0x5AC)
#define MDCLKCTL_ISPPLL_FH_CTL4	            (BASE_ADDR_MDCLKCTL+0x5B0)
#define MDCLKCTL_ISPPLL_FH_CTL5	            (BASE_ADDR_MDCLKCTL+0x5B4)
#define MDCLKCTL_EMIDDS_FH_CTL1	            (BASE_ADDR_MDCLKCTL+0x5C0)
#define MDCLKCTL_EMIDDS_FH_CTL2	            (BASE_ADDR_MDCLKCTL+0x5C4)
#define MDCLKCTL_EMIDDS_FH_CTL3	            (BASE_ADDR_MDCLKCTL+0x5C8)
#define MDCLKCTL_EMIDDS_FH_CTL4	            (BASE_ADDR_MDCLKCTL+0x5CC)
#define MDCLKCTL_EMIDDS_FH_CTL5	            (BASE_ADDR_MDCLKCTL+0x5D0)
#define MDCLKCTL_STATUS_0	                (BASE_ADDR_MDCLKCTL+0x800)
#define MDCLKCTL_STATUS_1	                (BASE_ADDR_MDCLKCTL+0x804)
#define MDCLKCTL_STATUS_2	                (BASE_ADDR_MDCLKCTL+0x808)
#define MDCLKCTL_STATUS_3	                (BASE_ADDR_MDCLKCTL+0x80C)
#define MDCLKCTL_STATUS_4	                (BASE_ADDR_MDCLKCTL+0x810)
#define MDCLKCTL_STATUS_5	                (BASE_ADDR_MDCLKCTL+0x814)
#define MDCLKCTL_STATUS_6	                (BASE_ADDR_MDCLKCTL+0x818)
#define MDCLKCTL_STATUS_7	                (BASE_ADDR_MDCLKCTL+0x81C)
#define MDCLKCTL_DUMMY	                    (BASE_ADDR_MDCLKCTL+0x1000)
#define MDCLKCTL_DUMMY2	                    (BASE_ADDR_MDCLKCTL+0x1004)
#define MDCLKCTL_TOP_DUMMY	                (BASE_ADDR_MDCLKCTL+0x1008)
#define MDCLKCTL_TOP_STATUS	                (BASE_ADDR_MDCLKCTL+0x100C)
#define MDCLKCTL_FPGA_EMICTL	            (BASE_ADDR_MDCLKCTL+0x4000)
#define MDCLKCTL_FPGA_CLKSPDCTL	            (BASE_ADDR_MDCLKCTL+0x4004)

#define APCLKCTL_R_APCLKCTL_CODA_VERSION	(BASE_ADDR_APCLKCTL+0x8000)
#define APCLKCTL_CLKONCTL	                (BASE_ADDR_APCLKCTL+0x8004)
#define APCLKCTL_CLKSRCSEL2	                (BASE_ADDR_APCLKCTL+0x8010)
#define APCLKCTL_CLKSPDCTL	                (BASE_ADDR_APCLKCTL+0x8014)
#define APCLKCTL_MDCLKONCTL	                (BASE_ADDR_APCLKCTL+0x8018)
#define APCLKCTL_APCLKONCTL	                (BASE_ADDR_APCLKCTL+0x801C)
#define APCLKCTL_CA7PLL_CTL	                (BASE_ADDR_APCLKCTL+0x8304)
#define APCLKCTL_MSDCPLL_CTL	            (BASE_ADDR_APCLKCTL+0x8318)
#define APCLKCTL_PLL_ON_CTL0	            (BASE_ADDR_APCLKCTL+0x8438)
#define APCLKCTL_PLL_ON_CTL1	            (BASE_ADDR_APCLKCTL+0x843C)
#define APCLKCTL_CA7PLL_FH_CTL1	            (BASE_ADDR_APCLKCTL+0x8504)
#define APCLKCTL_CA7PLL_FH_CTL2	            (BASE_ADDR_APCLKCTL+0x8508)
#define APCLKCTL_CA7PLL_FH_CTL3	            (BASE_ADDR_APCLKCTL+0x850C)
#define APCLKCTL_CA7PLL_FH_CTL4	            (BASE_ADDR_APCLKCTL+0x8510)
#define APCLKCTL_CA7PLL_FH_CTL5	            (BASE_ADDR_APCLKCTL+0x8514)
#define APCLKCTL_MSDCPLL_FH_CTL1	        (BASE_ADDR_APCLKCTL+0x8584)
#define APCLKCTL_MSDCPLL_FH_CTL2	        (BASE_ADDR_APCLKCTL+0x8588)
#define APCLKCTL_MSDCPLL_FH_CTL3        	(BASE_ADDR_APCLKCTL+0x858C)
#define APCLKCTL_MSDCPLL_FH_CTL4	        (BASE_ADDR_APCLKCTL+0x8590)
#define APCLKCTL_MSDCPLL_FH_CTL5	        (BASE_ADDR_APCLKCTL+0x8594)
#define APCLKCTL_DUMMY	                    (BASE_ADDR_APCLKCTL+0x9000)

#endif  /* !__PLL_MT6290__ */
