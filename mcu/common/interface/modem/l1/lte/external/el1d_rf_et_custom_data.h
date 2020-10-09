/******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

/***************************************************************************//**
 * @file       el1d_rf_et_custom_data.h
 * @author     Arthur Hung (MTK06691)
 * @date       2015.5.18
 * @brief      EL1D RF ET custom data header file
 * @details    Provide common RF ET custom data structure for PCORE and L1CORE (SHM)
 ******************************************************************************/

#ifndef __EL1D_RF_ET_CUSTOM_DATA_H__
#define __EL1D_RF_ET_CUSTOM_DATA_H__

/*******************************************************************************
 * #include
 ******************************************************************************/
#include "el1d_rf_custom_data.h"

/*******************************************************************************
 * #define
 ******************************************************************************/
// ET table parameters
#define LTE_ET_TX_EVENT_NUM                                          (  6 )
#define LTE_ET_TX_DATA_NUM                                           ( 15 )
	
#define LTE_ET_TPC_EVENT_NUM                                         ( 3 )
#define LTE_ET_SUBBAND_NUM_PER_DATA                                  ( 8 )  //support 8 subbands
#define ETM_REGISTER_NUMBER_PER_BANK                                 ( 8 )  // 1 register bank has 8 registers
#define LTE_ET_TPC_DATA_NUM                                          ( 1 + ETM_REGISTER_NUMBER_PER_BANK + 1 )   // Bank Write Switch + Bank Size + Bank Use Switch
#define LTE_ET_SECTION_TABLE_DATA_NUM                                ( 4 )
	
#define LTE_ET_LUT_VPA_EVENT_NUM                                     ( 5 )
#define LTE_ET_SCH_LUT_VPA_EVENT_NUM                                 ( 1 )
#define LTE_ET_SCH_LOOKUP_VPA_SECTION_DATA_NUM                       ( 1 )
#define LTE_ET_PRE_LOOKUP_VPA_SECTION_DATA_NUM                       ( 3 )
#define LTE_ET_LOOKUP_VPA_SECTION_TABLE_DATA_NUM                     ( 4 )
#define LTE_ET_LOOKUP_VPA_SECTION_NUM                                ( 15 )   //16:0.5:23,index by target power
	
#define LTE_ET_SCH_BW_SWITCH_EVENT_NUM                               (  1 )
#define LTE_ET_SCH_BW_SWITCH_SECTION_DATA_NUM                        (  1 )
#define LTE_ET_PRE_BW_SWITCH_SECTION_DATA_NUM                        (  2 )
#define LTE_ET_BW_SWITCH_SECTION_TABLE_DATA_NUM                      (  2 )
#define LTE_ET_BW_SWITCH_SECTION_NUM                                 (  6 )   //support 6 BW switch scenario

#define LTE_ET_MODE_SETTING_SECTION_TABLE_DATA_NUM                   (  2 )  // Mode setting data count
#define LTE_ET_MODE_SETTING_SWITCH_SECTION_NUM                       (  1 )  // Mode setting mode count

#define LTE_ET_DPD_TPC_DATA_NUM                                      (  4 )  // DPD voltage level setting data count

/***************************
*   ET Table Special Pattern
***************************/
//ET PA SECTION DATA PATTERN
#define LTE_ET_SEC_DATA0              0x2000
#define LTE_ET_SEC_DATA1              0x2001
#define LTE_ET_SEC_DATA2              0x2002
#define LTE_ET_SEC_DATA3              0x2003
#define LTE_ET_SEC_DATA4              0x2004

//ET PA LOOKUP_VPA_SECTION DATA PATTERN
#define LTE_ET_LOOKUP_VPA_SEC_DATA0   0x3000
#define LTE_ET_LOOKUP_VPA_SEC_DATA1   0x3001
#define LTE_ET_LOOKUP_VPA_SEC_DATA2   0x3002
#define LTE_ET_LOOKUP_VPA_SEC_DATA3   0x3003
#define LTE_ET_LOOKUP_VPA_SEC_DATA4   0x3004

//ET BW SWITCH DATA PATTERN
#define LTE_ET_BW_SEC_DATA0           0x4000
#define LTE_ET_BW_SEC_DATA1           0x4001
#define LTE_ET_BW_SEC_DATA2           0x4002
#define LTE_ET_BW_SEC_DATA3           0x4003
#define LTE_ET_BW_SEC_DATA4           0x4004

//ET FEATURE MASK
#define LTE_FEATURE_ET_BANK_SEL       0x0001
#define LTE_FEATURE_ET_BANK_PRELOAD   0x0002

#define IS_ET_MULTI_REG_BANKS_ENABLE   1
#define ET_REG_BANKS_NUMBER            4   //0~3
#define ET_REG_BANKS_ADDR_OFFSET       8   //ex:0x20,28,30,38
#define ET_VPA_OFFSET_VOLTAGE_MINIMUM_VALUE                          ( 0 )
#define ET_VPA_NORMALIZATION_FACTOR                                  ( 10 )
#define ET_VPA_OFFSET_VOLTAGE_REGISTER_SHIFT                         ( 1 )


/*******************************************************************************************************************************
 *  ETM Type Related Definitions
 *
 *******************************************************************************************************************************/

// A60935B

#define ET_A60935B_VPA_DAC_RESOLUTION                                ( 415 ) //unit: 0.1 mv
#define LTE_ET_ETM_DAC_MINIMUM_VALUE_LIMIT_A60935B                   ( 0x0D )
#define ET_A60935B_OUTER_LOOP_GAIN_1dot5x                            ( 0x00000022 )
#define ET_A60935B_OUTER_LOOP_GAIN_2dot0x                            ( 0x0000002A )
#define ET_A60935B_OUTER_LOOP_GAIN_2dot5x                            ( 0x00000032 )
#define ET_A60935B_OUTER_LOOP_GAIN_3dot0x                            ( 0x0000003A )

#define LTE_ET_A60935B_HFP_DAC_THRESHOLD1                            ( 0x6C )   // 4.5V, 41.5mV X 108
#define LTE_ET_A60935B_HFP_DAC_THRESHOLD2                            ( 0x65 )   // 4.2V, 41.5mV X 101
#define LTE_ET_A60935B_HFP_DAC_THRESHOLD3                            ( 0x3C )   // 2.5V, 41.5mV X 60

#define LTE_ET_A60935B_HFP_EA_RSS_LEVEL0                             ( 0x0D )   // HFP_DAC > LTE_ET_HFP_DAC_THRESHOLD1
#define LTE_ET_A60935B_HFP_EA_RSS_LEVEL1                             ( 0x0D )   // LTE_ET_HFP_DAC_THRESHOLD1 > HFP_DAC > LTE_ET_HFP_DAC_THRESHOLD2
#define LTE_ET_A60935B_HFP_EA_RSS_LEVEL2                             ( 0x0A )   // LTE_ET_HFP_DAC_THRESHOLD2 > HFP_DAC > LTE_ET_HFP_DAC_THRESHOLD3
#define LTE_ET_A60935B_HFP_EA_RSS_LEVEL3                             ( 0x0B )   // LTE_ET_HFP_DAC_THRESHOLD3 > HFP_DAC



// MT6300

#define ET_MT6300_VPA_DAC_RESOLUTION                                 ( 409 ) //unit: 0.1 mv
#define LTE_ET_ETM_DAC_MINIMUM_VALUE_LIMIT_MT6300                    ( 0x0D )

#define LTE_ET_MT6300_HFP_DAC_THRESHOLD1                             ( 0x6E )   // 4.5V, 40.9mV X 110
#define LTE_ET_MT6300_HFP_DAC_THRESHOLD2                             ( 0x66 )   // 4.2V, 40.9mV X 102
#define LTE_ET_MT6300_HFP_DAC_THRESHOLD3                             ( 0x3D )   // 2.5V, 40.9mV X 61

#define LTE_ET_MT6300_HFP_EA_RSS_LEVEL0                              ( 0x01 )   // HFP_DAC > LTE_ET_HFP_DAC_THRESHOLD1
#define LTE_ET_MT6300_HFP_EA_RSS_LEVEL1                              ( 0x01 )   // LTE_ET_HFP_DAC_THRESHOLD1 > HFP_DAC > LTE_ET_HFP_DAC_THRESHOLD2
#define LTE_ET_MT6300_HFP_EA_RSS_LEVEL2                              ( 0x0A )   // LTE_ET_HFP_DAC_THRESHOLD2 > HFP_DAC > LTE_ET_HFP_DAC_THRESHOLD3
#define LTE_ET_MT6300_HFP_EA_RSS_LEVEL3                              ( 0x0B )   // LTE_ET_HFP_DAC_THRESHOLD3 > HFP_DAC


/*******************************************************************************************************************************
 *  RG00 Format
 *******************************************************************************************************************************/

/*******************************************************************************************************************************
 7            RG_RST  RG_RST  

 *******************************************************************************************************************************/

#define ET_MT6300_RG_RST_SHIFT                                       ( 7 )
#define ET_MT6300_RG_RST_MASK                                        ( 0x80 )

#define ET_MT6300_RG_RST_DISABLE                                     ( 0x00 )
#define ET_MT6300_RG_RST_ENABLE                                      ( 0x01 )


/*******************************************************************************************************************************
 6		 RG_DCDC_BIAS_EN if set, DCDC bias & system bias will be enable

 *******************************************************************************************************************************/

#define ET_MT6300_RG_DCDC_BIAS_EN_SHIFT                              ( 6 )
#define ET_MT6300_RG_DCDC_BIAS_EN_MASK                               ( 0x40 )

#define ET_MT6300_RG_DCDC_BIAS_DISABLE                               ( 0x00 )
#define ET_MT6300_RG_DCDC_BIAS_ENABLE                                ( 0x01 )


/*******************************************************************************************************************************
 5		 RG_LA_INBIAS_EN if set, LA input bias & system bias will be enable

 *******************************************************************************************************************************/

#define ET_MT6300_RG_LA_INBIAS_EN_SHIFT                              ( 5 )
#define ET_MT6300_RG_LA_INBIAS_EN_MASK                               ( 0x20 )
	
#define ET_MT6300_RG_LA_INBIAS_DISABLE                               ( 0x00 )
#define ET_MT6300_RG_LA_INBIAS_ENABLE                                ( 0x01 )


/*******************************************************************************************************************************
 4		 RG_SYS_BIAS_EN  if set, system bias will be enable

 *******************************************************************************************************************************/

#define ET_MT6300_RG_SYS_BIAS_EN_SHIFT                               ( 4 )
#define ET_MT6300_RG_SYS_BIAS_EN_MASK                                ( 0x10 )
		
#define ET_MT6300_RG_SYS_BIAS_DISABLE                                ( 0x00 )
#define ET_MT6300_RG_SYS_BIAS_ENABLE                                 ( 0x01 )


/*******************************************************************************************************************************
 3		 RG_BYPASS	 if set, LFP will operates under bypass mode

 *******************************************************************************************************************************/

#define ET_MT6300_RG_BYPASS_SHIFT                                    ( 3 )
#define ET_MT6300_RG_BYPASS_MASK                                     ( 0x08 )
			
#define ET_MT6300_RG_BYPASS_DISABLE                                  ( 0x00 )
#define ET_MT6300_RG_BYPASS_ENABLE                                   ( 0x01 )


/*******************************************************************************************************************************
 2		 RG_BK_EN	 if set 0, every signal in BK will be default value.

 *******************************************************************************************************************************/

#define ET_MT6300_RG_BK_EN_SHIFT                                     ( 2 )
#define ET_MT6300_RG_BK_EN_MASK                                      ( 0x04 )
			
#define ET_MT6300_RG_BK_EN_DISABLE                                   ( 0x00 )
#define ET_MT6300_RG_BK_EN_ENABLE                                    ( 0x01 )


/*******************************************************************************************************************************
 1:0         RG_BK_SEL	 bank select

 *******************************************************************************************************************************/

#define ET_MT6300_RG_BK_SEL_SHIFT                                    ( 0 )
#define ET_MT6300_RG_BK_SEL_MASK                                     ( 0x03 )
			
#define ET_MT6300_RG_BK_SEL_BK00                                     ( 0x00 )
#define ET_MT6300_RG_BK_SEL_BK01                                     ( 0x01 )
#define ET_MT6300_RG_BK_SEL_BK10                                     ( 0x02 )
#define ET_MT6300_RG_BK_SEL_BK11                                     ( 0x03 )



/*******************************************************************************************************************************
 *  RG09 Format
 *******************************************************************************************************************************/

/*******************************************************************************************************************************
 7		 BK00_RG_HFP_BYPASS_EN	 Bypasses HFP to VBAT when HFP is disabled

 *******************************************************************************************************************************/

#define ET_MT6300_RG_HFP_BYPASS_EN_SHIFT                             ( 7 )
#define ET_MT6300_RG_HFP_BYPASS_EN_MASK                              ( 0x80 )

#define ET_MT6300_RG_HFP_BYPASS_DISABLE                              ( 0x00 )
#define ET_MT6300_RG_HFP_BYPASS_ENABLE                               ( 0x01 )


/*******************************************************************************************************************************
 6		 BK00_RG_HFP_AUTO_BYPASS_EN  When this bit is set HFP will automatically bypass to the VBAT supply when it is in the buck:boost range

 *******************************************************************************************************************************/

#define ET_MT6300_RG_HFP_AUTO_BYPASS_EN_SHIFT                        ( 6 )
#define ET_MT6300_RG_HFP_AUTO_BYPASS_EN_MASK                         ( 0x40 )

#define ET_MT6300_RG_HFP_AUTO_BYPASS_DISABLE                         ( 0x00 )
#define ET_MT6300_RG_HFP_AUTO_BYPASS_ENABLE                          ( 0x01 )


/*******************************************************************************************************************************
 5		 BK00_RG_HFP_FPWM	 Force HFP always operate under PWM mode

 *******************************************************************************************************************************/

#define ET_MT6300_RG_HFP_FPWM_SHIFT                                  ( 5 )
#define ET_MT6300_RG_HFP_FPWM_MASK                                   ( 0x20 )

#define ET_MT6300_RG_HFP_FPWM_DISABLE                                ( 0x00 )
#define ET_MT6300_RG_HFP_FPWM_ENABLE                                 ( 0x01 )


/*******************************************************************************************************************************
 4		 BK00_RG_LFP_FPWM	 Force LFP always operate under PWM mode

 *******************************************************************************************************************************/

#define ET_MT6300_RG_LFP_FPWM_SHIFT                                  ( 4 )
#define ET_MT6300_RG_LFP_FPWM_MASK                                   ( 0x10 )

#define ET_MT6300_RG_LFP_FPWM_DISABLE                                ( 0x00 )
#define ET_MT6300_RG_LFP_FPWM_ENABLE                                 ( 0x01 )


/*******************************************************************************************************************************
 2		 BK00_RG_LFP_EN  Enable/disable LFP.

 *******************************************************************************************************************************/

#define ET_MT6300_RG_LFP_EN_SHIFT                                    ( 2 )
#define ET_MT6300_RG_LFP_EN_MASK                                     ( 0x04 )

#define ET_MT6300_RG_LFP_DISABLE                                     ( 0x00 )
#define ET_MT6300_RG_LFP_ENABLE                                      ( 0x01 )


/*******************************************************************************************************************************
 1		 BK00_RG_HFP_EN  Enable/disable HFP.

 *******************************************************************************************************************************/

#define ET_MT6300_RG_HFP_EN_SHIFT                                    ( 1 )
#define ET_MT6300_RG_HFP_EN_MASK                                     ( 0x02 )

#define ET_MT6300_RG_HFP_DISABLE                                     ( 0x00 )
#define ET_MT6300_RG_HFP_ENABLE                                      ( 0x01 )


/*******************************************************************************************************************************
 0		 BK00_RG_ET_MODE 1: ET Mode

 *******************************************************************************************************************************/

#define ET_MT6300_RG_ET_MODE_SHIFT                                   ( 0 )
#define ET_MT6300_RG_ET_MODE_MASK                                    ( 0x01 )

#define ET_MT6300_RG_ET_MODE_DISABLE                                 ( 0x00 )
#define ET_MT6300_RG_ET_MODE_ENABLE                                  ( 0x01 )





/*********************************************************************************************
 *  RG0A Format
 *********************************************************************************************/

/*********************************************************************************************
 7:6	 BK00_RG_LA_GAIN_SEL gain adjust in LA
 00: 1.5
 01: 2.0
 10: 2.5 (default)
 11: 3.0
 *********************************************************************************************/

#define ET_MT6300_OUTER_LOOP_GAIN_SHIFT                              ( 6 )
#define ET_MT6300_OUTER_LOOP_GAIN_MASK                               ( 0xC0 )

#define ET_MT6300_OUTER_LOOP_GAIN_1dot5x                             ( 0x00 )
#define ET_MT6300_OUTER_LOOP_GAIN_2dot0x                             ( 0x01 )
#define ET_MT6300_OUTER_LOOP_GAIN_2dot5x                             ( 0x02 )
#define ET_MT6300_OUTER_LOOP_GAIN_3dot0x                             ( 0x03 )

/*********************************************************************************************
 5:4	 BK00_RG_LFP_PWRSEL_MODE input power selection:
 0X:auto compare from PWRSEL_VTH
 10:from BAT
 11:from BB
 *********************************************************************************************/

#define ET_MT6300_LFP_PWRSEL_MODE_SHIFT                              ( 4 )
#define ET_MT6300_LFP_PWRSEL_MODE_MASK                               ( 0x30 )
	
#define ET_MT6300_LFP_PWRSEL_MODE_SEL_BY_THRESHOLD_1                 ( 0x00 )
#define ET_MT6300_LFP_PWRSEL_MODE_SEL_BY_THRESHOLD_2                 ( 0x01 )
#define ET_MT6300_LFP_PWRSEL_MODE_FROM_BATTERY                       ( 0x02 )
#define ET_MT6300_LFP_PWRSEL_MODE_FROM_HFP                           ( 0x03 )

/*********************************************************************************************
 3:0	 BK00_RG_LFP_PWRSEL_VTH  input power selection threshold
 0000(2.8V)~1111 (4.3)
 *********************************************************************************************/

#define ET_MT6300_LFP_PWRSEL_VTH_SHIFT                               ( 0 )
#define ET_MT6300_LFP_PWRSEL_VTH_MASK                                ( 0x0F )


/*********************************************************************************************
 *  RG0D Format
 *********************************************************************************************/

/*********************************************************************************************
 7		 BK00_RG_LA_LOW_POWER_EN LA output pull down
 0: off; 1:on
 *********************************************************************************************/

#define ET_MT6300_RG_LA_LOW_POWER_EN_SHIFT                           ( 7 )
#define ET_MT6300_RG_LA_LOW_POWER_EN_MASK                            ( 0x80 )

#define ET_MT6300_RG_LA_LOW_POWER_EN_OFF                             ( 0 )
#define ET_MT6300_RG_LA_LOW_POWER_EN_ON                              ( 1 )

/*********************************************************************************************
 6:4		BK00_RG_LA_INBW	Low-pass filter bandwidth of input buffer
 000: 50MHz
 001: 22.2MHz
 010: 14.2MHz
 011: 10.5MHz
 100: 10.5MHz
 101: 8.33MHz
 110: 6.9MHz
 111 5.88MHz
 *********************************************************************************************/

#define ET_MT6300_RG_LA_INBW_SHIFT                                   ( 4 )
#define ET_MT6300_RG_LA_INBW_MASK                                    ( 0x70 )

#define ET_MT6300_RG_LA_INBW_50_00MHZ                                ( 0x00 )
#define ET_MT6300_RG_LA_INBW_22_20MHZ                                ( 0x01 )
#define ET_MT6300_RG_LA_INBW_14_20MHZ                                ( 0x02 )
#define ET_MT6300_RG_LA_INBW_10_50MHZ_1                              ( 0x03 )
#define ET_MT6300_RG_LA_INBW_10_50MHZ_2                              ( 0x04 )
#define ET_MT6300_RG_LA_INBW_08_33MHZ                                ( 0x05 )
#define ET_MT6300_RG_LA_INBW_06_90MHZ                                ( 0x06 )
#define ET_MT6300_RG_LA_INBW_05_88MHZ                                ( 0x07 )

/*********************************************************************************************
 3:2	 BK00_RG_LA_INBUF_BIAS	 bias for input buffer
 00:x 0.7
 01:x 0.85 
 10:x 1 (default)
 11:x 1.15
 *********************************************************************************************/

#define ET_MT6300_RG_LA_INBUF_BIAS_SHIFT                             ( 2 )
#define ET_MT6300_RG_LA_INBUF_BIAS_MASK                              ( 0x0C )

#define ET_MT6300_RG_LA_INBUF_BIAS_X_0_70                            ( 0x00 )
#define ET_MT6300_RG_LA_INBUF_BIAS_X_0_85                            ( 0x01 )
#define ET_MT6300_RG_LA_INBUF_BIAS_X_1_00                            ( 0x02 )
#define ET_MT6300_RG_LA_INBUF_BIAS_X_1_15                            ( 0x03 )

/*********************************************************************************************
 1:0	 BK00_RG_LA_BIAS Global bias for classAB opamp
 00:x 0.8
 01:x  1 (default)
 10:x 1.2
 11:x 1.4
 *********************************************************************************************/

#define ET_MT6300_RG_LA_BIAS_SHIFT                                   ( 0 )
#define ET_MT6300_RG_LA_BIAS_MASK                                    ( 0x03 )

#define ET_MT6300_RG_LA_BIAS_X_0_8                                   ( 0x00 )
#define ET_MT6300_RG_LA_BIAS_X_1_0                                   ( 0x01 )
#define ET_MT6300_RG_LA_BIAS_X_1_2                                   ( 0x02 )
#define ET_MT6300_RG_LA_BIAS_X_1_4                                   ( 0x03 )


/*********************************************************************************************
 *  RG0E Format
 *********************************************************************************************/

/*********************************************************************************************
 7		 BK00_RG_LA_HIGH4V	 Additional Reference voltage setting for output stage PMOS to avoid high voltage stressed.
 PVDD50_LA>4V (set 0)
 PVDD50_LA<4V (set 1)

 *********************************************************************************************/

#define ET_MT6300_RG_LA_HIGH4V_SHIFT                                 ( 7 )
#define ET_MT6300_RG_LA_HIGH4V_MASK                                  ( 0x80 )

#define ET_MT6300_RG_LA_HIGH4V_TRUE                                  ( 0 )
#define ET_MT6300_RG_LA_HIGH4V_FALSE                                 ( 1 )

/*********************************************************************************************
 6:4	 BK00_RG_LA_OUTBIAS  Output stage sense_ref bias control
 000:
 001:
 010:
 011: (default)
 100:
 101:
 110:
 111:
 *********************************************************************************************/

#define ET_MT6300_RG_LA_OUTBIAS_SHIFT                                ( 4 )
#define ET_MT6300_RG_LA_OUTBIAS_MASK                                 ( 0x70 )

#define ET_MT6300_RG_LA_OUTBIAS_LEVEL0                               ( 0x00 )
#define ET_MT6300_RG_LA_OUTBIAS_LEVEL1                               ( 0x01 )
#define ET_MT6300_RG_LA_OUTBIAS_LEVEL2                               ( 0x02 )
#define ET_MT6300_RG_LA_OUTBIAS_LEVEL3                               ( 0x03 )
#define ET_MT6300_RG_LA_OUTBIAS_LEVEL4                               ( 0x04 )
#define ET_MT6300_RG_LA_OUTBIAS_LEVEL5                               ( 0x05 )
#define ET_MT6300_RG_LA_OUTBIAS_LEVEL6                               ( 0x06 )
#define ET_MT6300_RG_LA_OUTBIAS_LEVEL7                               ( 0x07 )

/*********************************************************************************************
 3:2	 BK00_RG_LA_OPBW Tunable OP bandwidth for feedback RC network (w/I FB res 4k)
 00: 200f 40MHz
 01: 400 20MHz
 10: 1p 10MHz
 11: 2p 5MHz
 *********************************************************************************************/

#define ET_MT6300_RG_LA_OPBW_SHIFT                                   ( 2 )
#define ET_MT6300_RG_LA_OPBW_MASK                                    ( 0x0C )

#define ET_MT6300_RG_LA_OPBW_200F                                    ( 0x00 )
#define ET_MT6300_RG_LA_OPBW_400F                                    ( 0x01 )
#define ET_MT6300_RG_LA_OPBW_001P                                    ( 0x02 )
#define ET_MT6300_RG_LA_OPBW_002P                                    ( 0x03 )

/*********************************************************************************************
 1		 BK00_RG_LA_OPFF Feed-forward path enable for classAB OP
 0: turn off
 1: trun on (default)
 *********************************************************************************************/

#define ET_MT6300_RG_LA_OPFF_SHIFT                                   ( 1 )
#define ET_MT6300_RG_LA_OPFF_MASK                                    ( 0x02 )

#define ET_MT6300_RG_LA_OPFF_OFF                                     ( 0 )
#define ET_MT6300_RG_LA_OPFF_ON                                      ( 1 )

/*********************************************************************************************
 0		 BK00_RG_LA_OPLOAD	 ClassAB architecture selection
 0: 3-stage opamp (default)
 1: 2-stage opamp
 *********************************************************************************************/

#define ET_MT6300_RG_LA_OPLOAD_SHIFT                                 ( 0 )
#define ET_MT6300_RG_LA_OPLOAD_MASK                                  ( 0x01 )

#define ET_MT6300_RG_LA_OPLOAD_3_STAGE                               ( 0 )
#define ET_MT6300_RG_LA_OPLOAD_2_STAGE                               ( 1 )





#define ETM_REGISTER_INDEX_00          0x00
#define ETM_REGISTER_INDEX_01          0x01
#define ETM_REGISTER_INDEX_02          0x02
#define ETM_REGISTER_INDEX_03          0x03
#define ETM_REGISTER_INDEX_04          0x04
#define ETM_REGISTER_INDEX_05          0x05
#define ETM_REGISTER_INDEX_06          0x06
#define ETM_REGISTER_INDEX_07          0x07
#define ETM_REGISTER_INDEX_08          0x08
#define ETM_REGISTER_INDEX_09          0x09
#define ETM_REGISTER_INDEX_10          0x0A
#define ETM_REGISTER_INDEX_11          0x0B
#define ETM_REGISTER_INDEX_12          0x0C
#define ETM_REGISTER_INDEX_13          0x0D
#define ETM_REGISTER_INDEX_14          0x0E
#define ETM_REGISTER_INDEX_15          0x0F
#define ETM_REGISTER_INDEX_16          0x10
#define ETM_REGISTER_INDEX_17          0x11
#define ETM_REGISTER_INDEX_18          0x12
#define ETM_REGISTER_INDEX_19          0x13
#define ETM_REGISTER_INDEX_20          0x14
#define ETM_REGISTER_INDEX_21          0x15
#define ETM_REGISTER_INDEX_22          0x16
#define ETM_REGISTER_INDEX_23          0x17
#define ETM_REGISTER_INDEX_24          0x18
#define ETM_REGISTER_INDEX_25          0x19
#define ETM_REGISTER_INDEX_26          0x1A
#define ETM_REGISTER_INDEX_27          0x1B
#define ETM_REGISTER_INDEX_28          0x1C
#define ETM_REGISTER_INDEX_29          0x1D
#define ETM_REGISTER_INDEX_30          0x1E
#define ETM_REGISTER_INDEX_31          0x1F
#define ETM_REGISTER_INDEX_32          0x20
#define ETM_REGISTER_INDEX_33          0x21
#define ETM_REGISTER_INDEX_34          0x22
#define ETM_REGISTER_INDEX_35          0x23
#define ETM_REGISTER_INDEX_36          0x24
#define ETM_REGISTER_INDEX_37          0x25
#define ETM_REGISTER_INDEX_38          0x26
#define ETM_REGISTER_INDEX_39          0x27
#define ETM_REGISTER_INDEX_40          0x28
#define ETM_REGISTER_INDEX_41          0x29
#define ETM_REGISTER_INDEX_42          0x2A
#define ETM_REGISTER_INDEX_43          0x2B
#define ETM_REGISTER_INDEX_44          0x2C
#define ETM_REGISTER_INDEX_45          0x2D
#define ETM_REGISTER_INDEX_46          0x2E
#define ETM_REGISTER_INDEX_47          0x2F
#define ETM_REGISTER_INDEX_48          0x30
#define ETM_REGISTER_INDEX_49          0x31
#define ETM_REGISTER_INDEX_50          0x32
#define ETM_REGISTER_INDEX_51          0x33
#define ETM_REGISTER_INDEX_52          0x34
#define ETM_REGISTER_INDEX_53          0x35
#define ETM_REGISTER_INDEX_54          0x36
#define ETM_REGISTER_INDEX_55          0x37
#define ETM_REGISTER_INDEX_56          0x38
#define ETM_REGISTER_INDEX_57          0x39
#define ETM_REGISTER_INDEX_58          0x3A
#define ETM_REGISTER_INDEX_59          0x3B
#define ETM_REGISTER_INDEX_60          0x3C
#define ETM_REGISTER_INDEX_61          0x3D
#define ETM_REGISTER_INDEX_62          0x3E
#define ETM_REGISTER_INDEX_63          0x3F
#define ETM_REGISTER_INDEX_64          0x40
#define ETM_REGISTER_INDEX_65          0x41
#define ETM_REGISTER_INDEX_66          0x42
#define ETM_REGISTER_INDEX_67          0x43
#define ETM_REGISTER_INDEX_68          0x44
#define ETM_REGISTER_INDEX_69          0x45
#define ETM_REGISTER_INDEX_70          0x46
#define ETM_REGISTER_INDEX_71          0x47
#define ETM_REGISTER_INDEX_72          0x48
#define ETM_REGISTER_INDEX_73          0x49
#define ETM_REGISTER_INDEX_74          0x4A
#define ETM_REGISTER_INDEX_75          0x4B
#define ETM_REGISTER_INDEX_76          0x4C
#define ETM_REGISTER_INDEX_77          0x4D
#define ETM_REGISTER_INDEX_78          0x4E
#define ETM_REGISTER_INDEX_79          0x4F
#define ETM_REGISTER_INDEX_80          0x50
#define ETM_REGISTER_INDEX_81          0x51
#define ETM_REGISTER_INDEX_82          0x52
#define ETM_REGISTER_INDEX_83          0x53
#define ETM_REGISTER_INDEX_84          0x54
#define ETM_REGISTER_INDEX_85          0x55
#define ETM_REGISTER_INDEX_86          0x56
#define ETM_REGISTER_INDEX_87          0x57
#define ETM_REGISTER_INDEX_88          0x58
#define ETM_REGISTER_INDEX_89          0x59
#define ETM_REGISTER_INDEX_90          0x5A
#define ETM_REGISTER_INDEX_91          0x5B
#define ETM_REGISTER_INDEX_92          0x5C
#define ETM_REGISTER_INDEX_93          0x5D
#define ETM_REGISTER_INDEX_94          0x5E
#define ETM_REGISTER_INDEX_95          0x5F
#define ETM_REGISTER_INDEX_96          0x60
#define ETM_REGISTER_INDEX_97          0x61
#define ETM_REGISTER_INDEX_98          0x62
#define ETM_REGISTER_INDEX_99          0x63
#define ETM_REGISTER_INDEX_100         0x64
#define ETM_REGISTER_INDEX_101         0x65
#define ETM_REGISTER_INDEX_102         0x66
#define ETM_REGISTER_INDEX_103         0x67
#define ETM_REGISTER_INDEX_104         0x68
#define ETM_REGISTER_INDEX_105         0x69
#define ETM_REGISTER_INDEX_106         0x6A
#define ETM_REGISTER_INDEX_107         0x6B
#define ETM_REGISTER_INDEX_108         0x6C
#define ETM_REGISTER_INDEX_109         0x6D
#define ETM_REGISTER_INDEX_110         0x6E
#define ETM_REGISTER_INDEX_111         0x6F
#define ETM_REGISTER_INDEX_112         0x70
#define ETM_REGISTER_INDEX_113         0x71
#define ETM_REGISTER_INDEX_114         0x72
#define ETM_REGISTER_INDEX_115         0x73
#define ETM_REGISTER_INDEX_116         0x74
#define ETM_REGISTER_INDEX_117         0x75
#define ETM_REGISTER_INDEX_118         0x76
#define ETM_REGISTER_INDEX_119         0x77
#define ETM_REGISTER_INDEX_120         0x78
#define ETM_REGISTER_INDEX_121         0x79
#define ETM_REGISTER_INDEX_122         0x7A
#define ETM_REGISTER_INDEX_123         0x7B
#define ETM_REGISTER_INDEX_124         0x7C
#define ETM_REGISTER_INDEX_125         0x7D
#define ETM_REGISTER_INDEX_126         0x7E
#define ETM_REGISTER_INDEX_127         0x7F
#define ETM_REGISTER_INDEX_128         0x80
#define ETM_REGISTER_INDEX_129         0x81
#define ETM_REGISTER_INDEX_130         0x82
#define ETM_REGISTER_INDEX_131         0x83
#define ETM_REGISTER_INDEX_132         0x84
#define ETM_REGISTER_INDEX_133         0x85
#define ETM_REGISTER_INDEX_134         0x86
#define ETM_REGISTER_INDEX_135         0x87
#define ETM_REGISTER_INDEX_136         0x88
#define ETM_REGISTER_INDEX_137         0x89
#define ETM_REGISTER_INDEX_138         0x8A
#define ETM_REGISTER_INDEX_139         0x8B
#define ETM_REGISTER_INDEX_140         0x8C
#define ETM_REGISTER_INDEX_141         0x8D
#define ETM_REGISTER_INDEX_142         0x8E
#define ETM_REGISTER_INDEX_143         0x8F
#define ETM_REGISTER_INDEX_144         0x90
#define ETM_REGISTER_INDEX_145         0x91
#define ETM_REGISTER_INDEX_146         0x92
#define ETM_REGISTER_INDEX_147         0x93
#define ETM_REGISTER_INDEX_148         0x94
#define ETM_REGISTER_INDEX_149         0x95
#define ETM_REGISTER_INDEX_150         0x96
#define ETM_REGISTER_INDEX_151         0x97
#define ETM_REGISTER_INDEX_152         0x98
#define ETM_REGISTER_INDEX_153         0x99
#define ETM_REGISTER_INDEX_154         0x9A
#define ETM_REGISTER_INDEX_155         0x9B
#define ETM_REGISTER_INDEX_156         0x9C
#define ETM_REGISTER_INDEX_157         0x9D
#define ETM_REGISTER_INDEX_158         0x9E
#define ETM_REGISTER_INDEX_159         0x9F



#define LTE_BAND_ET_TX_EVENT(bs,s)                                     bs##_ET_TX_EVENT_##s
#define LTE_BAND_ET_TX_EVENT_TEMP(bs,s)                                LTE_BAND_ET_TX_EVENT(bs,s)
#define LTE_ET_TX_EVENT(b,s)                                           LTE_BAND_ET_TX_EVENT_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_TX_EVENT(s)                                    LTE_BAND_ET_TX_EVENT(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_TX_EVENT(bs,s)                              bs##_BYPASS_ET_TX_EVENT_##s
#define LTE_BAND_BYPASS_ET_TX_EVENT_TEMP(bs,s)                         LTE_BAND_BYPASS_ET_TX_EVENT(bs,s)
#define LTE_BYPASS_ET_TX_EVENT(b,s)                                    LTE_BAND_BYPASS_ET_TX_EVENT_TEMP(b##_##s,s)

#define LTE_BAND_ET_TX_DATA(bs,s)                                      bs##_ET_TX_DATA_##s
#define LTE_BAND_ET_TX_DATA_TEMP(bs,s)                                 LTE_BAND_ET_TX_DATA(bs,s)
#define LTE_ET_TX_DATA(b,s)                                            LTE_BAND_ET_TX_DATA_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_TX_DATA(s)                                     LTE_BAND_ET_TX_DATA(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_TX_DATA(bs,s)                               bs##_BYPASS_ET_TX_DATA_##s
#define LTE_BAND_BYPASS_ET_TX_DATA_TEMP(bs,s)                          LTE_BAND_BYPASS_ET_TX_DATA(bs,s)
#define LTE_BYPASS_ET_TX_DATA(b,s)                                     LTE_BAND_BYPASS_ET_TX_DATA_TEMP(b##_##s,s)

#define LTE_BAND_ET_TPC_EVENT(bs,s)                                    bs##_ET_TPC_EVENT_##s
#define LTE_BAND_ET_TPC_EVENT_TEMP(bs,s)                               LTE_BAND_ET_TPC_EVENT(bs,s)
#define LTE_ET_TPC_EVENT(b,s)                                          LTE_BAND_ET_TPC_EVENT_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_TPC_EVENT(s)                                   LTE_BAND_ET_TPC_EVENT(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_TPC_EVENT(bs,s)                             bs##_BYPASS_ET_TPC_EVENT_##s
#define LTE_BAND_BYPASS_ET_TPC_EVENT_TEMP(bs,s)                        LTE_BAND_BYPASS_ET_TPC_EVENT(bs,s)
#define LTE_BYPASS_ET_TPC_EVENT(b,s)                                   LTE_BAND_BYPASS_ET_TPC_EVENT_TEMP(b##_##s,s)

#define LTE_BAND_ET_TPC_DATA(bs,s)                                     bs##_ET_TPC_DATA_##s
#define LTE_BAND_ET_TPC_DATA_TEMP(bs,s)                                LTE_BAND_ET_TPC_DATA(bs,s)
#define LTE_ET_TPC_DATA(b,s)                                           LTE_BAND_ET_TPC_DATA_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_TPC_DATA(s)                                    LTE_BAND_ET_TPC_DATA(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_TPC_DATA(bs,s)                              bs##_BYPASS_ET_TPC_DATA_##s
#define LTE_BAND_BYPASS_ET_TPC_DATA_TEMP(bs,s)                         LTE_BAND_BYPASS_ET_TPC_DATA(bs,s)
#define LTE_BYPASS_ET_TPC_DATA(b,s)                                    LTE_BAND_BYPASS_ET_TPC_DATA_TEMP(b##_##s,s)

#define LTE_BAND_ET_TPC_SECTION_DATA(bs,s)                             bs##_ET_TPC_SECTION_DATA_##s
#define LTE_BAND_ET_TPC_SECTION_DATA_TEMP(bs,s)                        LTE_BAND_ET_TPC_SECTION_DATA(bs,s)
#define LTE_ET_TPC_SECTION_DATA(b,s)                                   LTE_BAND_ET_TPC_SECTION_DATA_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_TPC_SECTION_DATA(s)                            LTE_BAND_ET_TPC_SECTION_DATA(LTE_BandNone,s)                                                                       

#define LTE_BAND_BYPASS_ET_TPC_SECTION_DATA(bs,s)                      bs##_BYPASS_ET_TPC_SECTION_DATA_##s
#define LTE_BAND_BYPASS_ET_TPC_SECTION_DATA_TEMP(bs,s)                 LTE_BAND_BYPASS_ET_TPC_SECTION_DATA(bs,s)
#define LTE_BYPASS_ET_TPC_SECTION_DATA(b,s)                            LTE_BAND_BYPASS_ET_TPC_SECTION_DATA_TEMP(b##_##s,s)

#define LTE_BAND_ET_LOOKUP_VPA_DATA(bs,s)                              bs##_ET_LOOKUP_VPA_DATA_##s
#define LTE_BAND_ET_LOOKUP_VPA_DATA_TEMP(bs,s)                         LTE_BAND_ET_LOOKUP_VPA_DATA(bs,s)
#define LTE_ET_LOOKUP_VPA_DATA(b,s)                                    LTE_BAND_ET_LOOKUP_VPA_DATA_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_LOOKUP_VPA_DATA(s)                             LTE_BAND_ET_LOOKUP_VPA_DATA(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_LOOKUP_VPA_DATA(bs,s)                       bs##_BYPASS_ET_LOOKUP_VPA_DATA_##s
#define LTE_BAND_BYPASS_ET_LOOKUP_VPA_DATA_TEMP(bs,s)                  LTE_BAND_BYPASS_ET_LOOKUP_VPA_DATA(bs,s)
#define LTE_BYPASS_ET_LOOKUP_VPA_DATA(b,s)                             LTE_BAND_BYPASS_ET_LOOKUP_VPA_DATA_TEMP(b##_##s,s)

#define LTE_BAND_ET_LOOKUP_VPA_SECTION_DATA(bs,s)                      bs##_ET_LOOKUP_VPA_SECTION_DATA_##s
#define LTE_BAND_ET_LOOKUP_VPA_SECTION_DATA_TEMP(bs,s)                 LTE_BAND_ET_LOOKUP_VPA_SECTION_DATA(bs,s)
#define LTE_ET_LOOKUP_VPA_SECTION_DATA(b,s)                            LTE_BAND_ET_LOOKUP_VPA_SECTION_DATA_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_LOOKUP_VPA_SECTION_DATA(s)                     LTE_BAND_ET_LOOKUP_VPA_SECTION_DATA(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_LOOKUP_VPA_SECTION_DATA(bs,s)               bs##_BYPASS_ET_LOOKUP_VPA_SECTION_DATA_##s
#define LTE_BAND_BYPASS_ET_LOOKUP_VPA_SECTION_DATA_TEMP(bs,s)          LTE_BAND_BYPASS_ET_LOOKUP_VPA_SECTION_DATA(bs,s)
#define LTE_BYPASS_ET_LOOKUP_VPA_SECTION_DATA(b,s)                     LTE_BAND_BYPASS_ET_LOOKUP_VPA_SECTION_DATA_TEMP(b##_##s,s)

#define LTE_BAND_ET_BW_SWITCH_DATA(bs,s)                               bs##_ET_BW_SWITCH_DATA_##s
#define LTE_BAND_ET_BW_SWITCH_DATA_TEMP(bs,s)                          LTE_BAND_ET_BW_SWITCH_DATA(bs,s)
#define LTE_ET_BW_SWITCH_DATA(b,s)                                     LTE_BAND_ET_BW_SWITCH_DATA_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_BW_SWITCH_DATA(s)                              LTE_BAND_ET_BW_SWITCH_DATA(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_BW_SWITCH_DATA(bs,s)                        bs##_BYPASS_ET_BW_SWITCH_DATA_##s
#define LTE_BAND_BYPASS_ET_BW_SWITCH_DATA_TEMP(bs,s)                   LTE_BAND_BYPASS_ET_BW_SWITCH_DATA(bs,s)
#define LTE_BYPASS_ET_BW_SWITCH_DATA(b,s)                              LTE_BAND_BYPASS_ET_BW_SWITCH_DATA_TEMP(b##_##s,s)

#define LTE_BAND_ET_BW_SWITCH_SECTION_DATA(bs,s)                       bs##_ET_BW_SWITCH_SECTION_DATA_##s
#define LTE_BAND_ET_BW_SWITCH_SECTION_DATA_TEMP(bs,s)                  LTE_BAND_ET_BW_SWITCH_SECTION_DATA(bs,s)
#define LTE_ET_BW_SWITCH_SECTION_DATA(b,s)                             LTE_BAND_ET_BW_SWITCH_SECTION_DATA_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_BW_SWITCH_SECTION_DATA(s)                      LTE_BAND_ET_BW_SWITCH_SECTION_DATA(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_BW_SWITCH_SECTION_DATA(bs,s)                bs##_BYPASS_ET_BW_SWITCH_SECTION_DATA_##s
#define LTE_BAND_BYPASS_ET_BW_SWITCH_SECTION_DATA_TEMP(bs,s)           LTE_BAND_BYPASS_ET_BW_SWITCH_SECTION_DATA(bs,s)
#define LTE_BYPASS_ET_BW_SWITCH_SECTION_DATA(b,s)                      LTE_BAND_BYPASS_ET_BW_SWITCH_SECTION_DATA_TEMP(b##_##s,s)

#define LTE_BAND_ET_MODE_SETTING_DATA(bs,s)                            bs##_ET_MODE_SETTING_DATA_##s
#define LTE_BAND_ET_MODE_SETTING_DATA_TEMP(bs,s)                       LTE_BAND_ET_MODE_SETTING_DATA(bs,s)
#define LTE_ET_MODE_SETTING_DATA(b,s)                                  LTE_BAND_ET_MODE_SETTING_DATA_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_MODE_SETTING_DATA(s)                           LTE_BAND_ET_MODE_SETTING_DATA(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_MODE_SETTING_DATA(bs,s)                     bs##_BYPASS_ET_MODE_SETTING_DATA_##s
#define LTE_BAND_BYPASS_ET_MODE_SETTING_DATA_TEMP(bs,s)                LTE_BAND_BYPASS_ET_MODE_SETTING_DATA(bs,s)
#define LTE_BYPASS_ET_MODE_SETTING_DATA(b,s)                           LTE_BAND_BYPASS_ET_MODE_SETTING_DATA_TEMP(b##_##s,s)

#define LTE_BAND_EtCompParamPerBand(bs,s)                              bs##_EtCompParamPerBand_##s
#define LTE_BAND_EtCompParamPerBand_TEMP(bs,s)                         LTE_BAND_EtCompParamPerBand(bs,s)
#define LTE_EtCompParamPerBand(b,s)                                    LTE_BAND_EtCompParamPerBand_TEMP(b##_##s,s)

#define LTE_BAND_EtCompParamPerBand(bs,s)                              bs##_EtCompParamPerBand_##s
#define LTE_BAND_EtCompParamPerBand_TEMP(bs,s)                         LTE_BAND_EtCompParamPerBand(bs,s)
#define LTE_EtCompParamPerBand(b,s)                                    LTE_BAND_EtCompParamPerBand_TEMP(b##_##s,s)

#define LTE_BAND_BYPASS_EtCompParamPerBand(bs,s)                       bs##_BYPASS_EtCompParamPerBand_##s
#define LTE_BAND_BYPASS_EtCompParamPerBand_TEMP(bs,s)                  LTE_BAND_BYPASS_EtCompParamPerBand(bs,s)
#define LTE_BYPASS_EtCompParamPerBand(b,s)                             LTE_BAND_BYPASS_EtCompParamPerBand_TEMP(b##_##s,s)

#define LTE_BAND_EtVinLutDataPerBand(bs,s)                             bs##_EtVinLutDataPerBand_##s
#define LTE_BAND_EtVinLutDataPerBand_TEMP(bs,s)                        LTE_BAND_EtVinLutDataPerBand(bs,s)
#define LTE_EtVinLutDataPerBand(b,s)                                   LTE_BAND_EtVinLutDataPerBand_TEMP(b##_##s,s)

#define LTE_BAND_BYPASS_EtVinLutDataPerBand(bs,s)                      bs##_BYPASS_EtVinLutDataPerBand_##s
#define LTE_BAND_BYPASS_EtVinLutDataPerBand_TEMP(bs,s)                 LTE_BAND_BYPASS_EtVinLutDataPerBand(bs,s)
#define LTE_BYPASS_EtVinLutDataPerBand(b,s)                            LTE_BAND_BYPASS_EtVinLutDataPerBand_TEMP(b##_##s,s)

#define LTE_BAND_ET_OUTER_LOOP_GAIN_SETTING(bs,s)                      bs##_ET_OUTER_LOOP_GAIN_SETTING_##s
#define LTE_BAND_ET_OUTER_LOOP_GAIN_SETTING_TEMP(bs,s)                 LTE_BAND_ET_OUTER_LOOP_GAIN_SETTING(bs,s)
#define LTE_ET_OUTER_LOOP_GAIN_SETTING(b,s)                            LTE_BAND_ET_OUTER_LOOP_GAIN_SETTING_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_OUTER_LOOP_GAIN_SETTING(s)                     LTE_BAND_ET_OUTER_LOOP_GAIN_SETTING(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_OUTER_LOOP_GAIN_SETTING(bs,s)               bs##_BYPASS_ET_OUTER_LOOP_GAIN_SETTING_##s
#define LTE_BAND_BYPASS_ET_OUTER_LOOP_GAIN_SETTING_TEMP(bs,s)          LTE_BAND_BYPASS_ET_OUTER_LOOP_GAIN_SETTING(bs,s)
#define LTE_BYPASS_ET_OUTER_LOOP_GAIN_SETTING(b,s)                     LTE_BAND_BYPASS_ET_OUTER_LOOP_GAIN_SETTING_TEMP(b##_##s,s)

#define LTE_BAND_ET_VPA_OFFSET_VOLTAGE_SETTING(bs,s)                   bs##_ET_VPA_OFFSET_VOLTAGE_SETTING_##s
#define LTE_BAND_ET_VPA_OFFSET_VOLTAGE_SETTING_TEMP(bs,s)              LTE_BAND_ET_VPA_OFFSET_VOLTAGE_SETTING(bs,s)
#define LTE_ET_VPA_OFFSET_VOLTAGE_SETTING(b,s)                         LTE_BAND_ET_VPA_OFFSET_VOLTAGE_SETTING_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_VPA_OFFSET_VOLTAGE_SETTING(s)                  LTE_BAND_ET_VPA_OFFSET_VOLTAGE_SETTING(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING(bs,s)            bs##_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING_##s
#define LTE_BAND_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING_TEMP(bs,s)       LTE_BAND_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING(bs,s)
#define LTE_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING(b,s)                  LTE_BAND_BYPASS_ET_VPA_OFFSET_VOLTAGE_SETTING_TEMP(b##_##s,s)

#define LTE_BAND_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING(bs,s)               bs##_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_##s
#define LTE_BAND_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_TEMP(bs,s)          LTE_BAND_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING(bs,s)
#define LTE_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING(b,s)                     LTE_BAND_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING(s)              LTE_BAND_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING(bs,s)        bs##_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_##s
#define LTE_BAND_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_TEMP(bs,s)   LTE_BAND_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING(bs,s)
#define LTE_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING(b,s)              LTE_BAND_BYPASS_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_TEMP(b##_##s,s)

#define LTE_BAND_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING(bs,s)               bs##_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_##s
#define LTE_BAND_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_TEMP(bs,s)          LTE_BAND_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING(bs,s)
#define LTE_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING(b,s)                     LTE_BAND_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_TEMP(b##_##s,s)
#define LTE_BANDNONE_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING(s)              LTE_BAND_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING(LTE_BandNone,s)

#define LTE_BAND_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING(bs,s)        bs##_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_##s
#define LTE_BAND_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_TEMP(bs,s)   LTE_BAND_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING(bs,s)
#define LTE_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING(b,s)              LTE_BAND_BYPASS_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_TEMP(b##_##s,s)

/*******************************************************************************
 * Typedef
 ******************************************************************************/
/* ET customization related structure */

// ET Tx event/ET TPC event/ET LOOKUP VPA event
typedef struct
{
   kal_uint16         mipi_elm_type;             //mipi element type
   LTE_MIPI_DATA_STSP mipi_data_stsp;            //data start stop
   kal_uint16         mipi_evt_type;             //event type
   kal_uint32         mipi_evt_offset;           //event offset
} LTE_ET_EVENT_TABLE_T;

//ET Tx Data
typedef struct
{
   kal_uint16 mipi_elm_type;          //mipi element type
   kal_uint16 mipi_port_sel;          //port selection
   kal_uint16 mipi_data_seq;          //data write sequence format
   kal_uint16 mipi_usid;
   LTE_MIPI_DATA_EXPAND_TABLE_T mipi_subband_data[LTE_ET_SUBBAND_NUM_PER_DATA];
}LTE_ET_DATA_SUBBAND_TABLE_T;

//ET TPC Data
typedef struct
{
   kal_uint16 mipi_elm_type;          //mipi element type
   kal_uint16 mipi_port_sel;          //port selection
   kal_uint16 mipi_data_seq;          //data write sequence format
   kal_uint16 mipi_usid;              //mipi usid
   kal_uint16 mipi_addr;              //mipi addr
   kal_uint16 mipi_data;              //mipi data
}LTE_ET_DATA_TABLE_T;

//ET TPC Section Data
typedef struct
{
   kal_uint16 mipi_tpc_sec_data[ LTE_ET_SECTION_TABLE_DATA_NUM ];
}LTE_ET_SECTION_DATA_T;

typedef struct
{
   LTE_ET_SECTION_DATA_T mipi_tpc_section_table[ LTE_MIPI_TPC_SECTION_NUM ];
}LTE_ET_TPC_SECTION_TABLE_T;

//ET Lookup VPA Section Data
typedef struct
{
   kal_uint16 mipi_sec_data[LTE_ET_LOOKUP_VPA_SECTION_TABLE_DATA_NUM];
}LTE_ET_LOOKUP_VPA_SECTION_DATA_T;

typedef struct
{
   kal_uint16 mipi_subband_freq;
   LTE_ET_LOOKUP_VPA_SECTION_DATA_T et_lut_vpa_sec_data_table[ LTE_ET_LOOKUP_VPA_SECTION_NUM ];
}LTE_ET_LOOKUP_VPA_SECTION_TABLE_T;

//ET BW Switch Data
typedef struct
{
   kal_uint16 mipi_sec_data[LTE_ET_BW_SWITCH_SECTION_TABLE_DATA_NUM];
}LTE_ET_BW_SWITCH_SECTION_DATA_T;

typedef struct
{
   kal_uint16 sub_freq[ LTE_ET_SUBBAND_NUM_PER_DATA ];
   kal_uint16 numValidSubband;
} ET_MIPI_SUBFREQ_GROUP_T;

/* ET feature */
extern LTE_RfcEtCompParamPerBand_T*        LTE_EtCompParamPerBand_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern LTE_RfcEtCompParamPerBand_T*        LTE_BYPASS_EtCompParamPerBand_SetDefault[LTE_BYPASS_MAX_SUPPORT_BAND_NUM];
extern LTE_RfcEtVpaPmAmLutPerBand_T*       LTE_EtVinLutTblPerBand_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern LTE_RfcEtVpaPmAmLutPerBand_T*       LTE_BYPASS_EtVinLutTblPerBand_SetDefault[LTE_BYPASS_MAX_SUPPORT_BAND_NUM];
extern LTE_ET_EVENT_TABLE_T*               LTE_ET_TX_EVENT_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern LTE_ET_DATA_SUBBAND_TABLE_T*        LTE_ET_TX_DATA_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern LTE_ET_EVENT_TABLE_T*               LTE_ET_TPC_EVENT_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern LTE_ET_DATA_TABLE_T*                LTE_ET_TPC_DATA_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern LTE_ET_TPC_SECTION_TABLE_T*         LTE_ET_TPC_SECTION_DATA_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern LTE_ET_DATA_TABLE_T*                LTE_ET_LOOKUP_VPA_DATA_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern LTE_ET_LOOKUP_VPA_SECTION_TABLE_T*  LTE_ET_LOOKUP_VPA_SECTION_DATA_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern LTE_ET_DATA_TABLE_T*                LTE_ET_BW_SWITCH_DATA_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern LTE_ET_BW_SWITCH_SECTION_DATA_T*    LTE_ET_BW_SWITCH_SECTION_DATA_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern LTE_ET_DATA_TABLE_T*                LTE_ET_MODE_SETTING_DATA_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern kal_uint16*                         LTE_ET_OUTER_LOOP_GAIN_SETTING_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern kal_uint16*                         LTE_ET_VPA_OFFSET_VOLTAGE_SETTING_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern kal_uint16*                         LTE_ET_MAXIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern kal_uint16*                         LTE_ET_MINIMUM_OUTPUT_VOLTAGE_SETTING_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM_WITH_BYPASS_HRM];
extern LTE_RfcEtCompParamPerBand_T*        LTE_ETCOMPPARAMPERBAND_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern LTE_RfcEtCompParamPerBand_T*        LTE_BYPASS_ETCOMPPARAMPERBAND_SetDefault[LTE_BYPASS_MAX_SUPPORT_BAND_NUM];
extern LTE_RfcEtVpaPmAmLutPerBand_T*       LTE_ETVINLUTDATAPERBAND_SetDefault[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern LTE_RfcEtVpaPmAmLutPerBand_T*       LTE_BYPASS_ETVINLUTDATAPERBAND_SetDefault[LTE_BYPASS_MAX_SUPPORT_BAND_NUM];
extern kal_uint16                          LTE_ET_ENABLE;

#endif /*__EL1D_RF_ET_CUSTOM_DATA_H__*/

