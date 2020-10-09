/******************************************************************************
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
 * ---------
 *   drv_pcc.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   Header file of PCC(PHY Capture Controller) driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 12 01 2015 zeke.chang
 * [MOLY00136571] [UMOLY][Trunk][LR11][PCC/PPC]Update Driver.
 * Update PCC driver for path-automapping func.
 *
 * 08 11 2015 zeke.chang
 * [MOLY00136571] [UMOLY][Trunk][LR11][PCC/PPC]Update Driver.
 * Update PCC/PCC driver for Jade.
 *
 * 07 09 2015 zeke.chang
 * [MOLY00127536] [UMOLY][Trunk][PCC]Add new API
 * Add ATIME enable/disable API.
 *
 * 07 02 2015 zeke.chang
 * [MOLY00125461] [UMOLY][TK6291_DEV][PCC]Add new API
 * Add APIs for ATIME enable/disable.
 *
 * 03 24 2015 zeke.chang
 * [MOLY00088478] [UMOLY][SIB_DRV] Add new PCC driver for SIB capture application
 * Update PCC driver.
 *
 * 12.12.2014
 * First Version Released
 *
 *****************************************************************************/

#ifndef __DRV_PCC_H__
#define __DRV_PCC_H__

#include "irqid.h"
#include "intrCtrl.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drv_comm.h"

#include "reg_pcc.h"

/* Enum Define */
typedef enum {
	EN_PCC_DFESYS_LTE_ADC_52MHZ_WITH_CMP = 0,
	EN_PCC_DFESYS_LTE_ADC_52MHZ_BYPASS_CMP = 1,
	EN_PCC_DFESYS_LTE_ADC_52MHZ_TRUNCATE_8B = 2,
	EN_PCC_DFESYS_LTE_ADC_104MHZ_WITH_CMP = 3,
	EN_PCC_DFESYS_LTE_ADC_104MHZ_BYPASS_CMP = 4,
	EN_PCC_DFESYS_LTE_ADC_104MHZ_TRUNCATE_8B = 5,
	EN_PCC_DFESYS_LTE_INTP_DEMOD = 6,
	EN_PCC_DFESYS_LTE_INTP_CM = 7,
	EN_PCC_DFESYS_LTE_INTP_CS = 8,
	EN_PCC_DFESYS_LTE_INTP_DEMOD_CM = 9,
	EN_PCC_DFESYS_3G_TDD_ADC = 10,
	EN_PCC_DFESYS_3G_TDD_RXIQ = 11,
	EN_PCC_DFESYS_3G_TDD_INTP = 12,
	EN_PCC_DFESYS_3G_FDD_ADC = 13,
	EN_PCC_DFESYS_3G_FDD_INTP_DEMOD =14,
	EN_PCC_DFESYS_CAPTURE_NODE_MAX = 15
} EN_PCC_DFESYS_CAPTURE_NODE;

typedef enum {
	EN_PCC_ADC_PATH_SEL_IQ_PRESYNC = 0,
	EN_PCC_ADC_PATH_SEL_COMPRESSOR,
	EN_PCC_ADC_PATH_SEL_MAX
} EN_PCC_ADC_PATH_SEL;

typedef enum {
	EN_PCC_SIB_MODE_MASTER = 0,
	EN_PCC_SIB_MODE_SLAVE
} EN_PCC_SIB_MODE;

typedef enum {
	EN_PCC_FSM_STATUS_IDLE = 0,
	EN_PCC_FSM_STATUS_FIRST_STARTPK_TRANSFER,
	EN_PCC_FSM_STATUS_DATAPK_TRANSFER,
	EN_PCC_FSM_STATUS_STARTPK_TRANSFER_CON
} EN_PCC_FSM_STATUS;

typedef enum {
	EN_PCC_PK_FSM_STATUS_IDLE = 0,
	EN_PCC_PK_FSM_STATUS_AT1_STARTPK_TRANSFER,
	EN_PCC_PK_FSM_STATUS_AT2_STARTPK_TRANSFER,
	EN_PCC_PK_FSM_STATUS_AT3_STARTPK_TRANSFER,
	EN_PCC_PK_FSM_STATUS_AT4_STARTPK_TRANSFER,
	EN_PCC_PK_FSM_STATUS_ADJ_STARTPK_TRANSFER
} EN_PCC_PK_FSM_STATUS;

typedef enum {
	EN_PCC_PTG_MODE_SIN = 0,
	EN_PCC_PTG_MODE_RAMP,
	EN_PCC_PTG_MODE_RECTANGLE,
	EN_PCC_PTG_MODE_MAX
} EN_PCC_PTG_MODE;

typedef enum {
	EN_PCC_INPUT_SEL_PRESYNC = 0,
	EN_PCC_INPUT_SEL_PTG,
	EN_PCC_INPUT_SEL_MAX
} EN_PCC_INPUT_SEL;

typedef enum {
	EN_PCC_ANTENNA1_RFCARRIER1 = 1,
	EN_PCC_ANTENNA1_RFCARRIER2 = 2,
	EN_PCC_ANTENNA2_RFCARRIER1 = 4,
	EN_PCC_ANTENNA2_RFCARRIER2 = 8,
	EN_PCC_DEFAULT = 0
} EN_PCC_ANTENNA_RFCARRIER;

/*****************************************************/
/*The config structures need to be set in normal case*/
/*****************************************************/
typedef struct _ST_ATB_PATH_SEL {
	kal_bool b8P11Enable;
	kal_bool b8P12Enable;
	kal_bool b8P21Enable;
	kal_bool b8P22Enable;
	kal_bool b8AdjEnable;
} ST_ATB_PATH_SEL;

typedef struct _ST_PCC_ATB_VLD_CTRL_CONFIG {
	kal_uint8 u8VLDCountLimitAT1;
	kal_uint8 u8VLDCountLimitAT2;
	kal_uint8 u8VLDCountLimitAT3;
	kal_uint8 u8VLDCountLimitAT4;
	kal_uint16 u16VLDCountLimitAT5;
	kal_bool b8ATBReorder;
	kal_bool b8LimitAT5VLDRegion;
} ST_PCC_ATB_VLD_CTRL_CONFIG;

typedef struct _ST_PCC_COMP_CONFIG {
	kal_uint8 u8CNLen0;
	kal_uint8 u8CNLen1;
	kal_uint8 u8CNLen2;
	kal_uint8 u8Vth0;
	kal_uint8 u8Vth1;
	kal_bool b8DivEn;
	kal_uint8 u8DivFac;
} ST_PCC_COMP_CONFIG;

typedef struct _ST_PCC_ATID_CONFIG {
	kal_uint8 u8ATID_PK_START;  //u8ATIDS0
	kal_uint8 u8ATID_P11;       //u8ATIDS1
	kal_uint8 u8ATID_P12;       //u8ATIDS2
	kal_uint8 u8ATID_P21;       //u8ATIDS3
	kal_uint8 u8ATID_P22;       //u8ATIDS4
	kal_uint8 u8ATID_ADJ;       //u8ATIDS5
} ST_PCC_ATID_CONFIG;

typedef struct _ST_PCC_DFE_ATB_PATH_CONFIG {
	kal_bool b8DFE_ATBPath0_Enable;
	kal_bool b8DFE_ATBPath1_Enable;
	kal_bool b8DFE_ATBPath2_Enable;
	kal_bool b8DFE_ATBPath3_Enable;
	kal_bool b8DFE_ATBPath4_Enable;
	kal_bool b8DFE_ATBPath5_Enable;
} ST_PCC_DFE_ATB_PATH_CONFIG;

typedef struct _ST_PCC_DATA_INFO_CONFIG {
    kal_uint32 u32DataPacketLength;
    kal_uint32 u32InfoUpdatePeriod;
} ST_PCC_DATA_INFO_CONFIG;

typedef struct _ST_PCC_CAPTURE_CONFIG {
	EN_PCC_DFESYS_CAPTURE_NODE enCapNode;
	ST_ATB_PATH_SEL stATBPathSel;
} ST_PCC_CAPTURE_CONFIG;

typedef struct _ST_PCC_MULTISIB_CONFIG {
	kal_bool b8MultiSIBEn;
	EN_PCC_SIB_MODE enSIBMode;
} ST_PCC_MULTISIB_CONFIG;

typedef struct _ST_PCC_INT_CONFIG {
    kal_bool b8ATBFullIntEn;
    kal_bool b8CompFullIntEn;
} ST_PCC_INT_CONFIG;

/*The general config structure in use*/
typedef struct _ST_PCC_CONFIG {
	ST_PCC_CAPTURE_CONFIG* pstCapCfg;
	ST_PCC_ATID_CONFIG* pstATIDCfg;
	ST_PCC_DATA_INFO_CONFIG* pstDataInfoCfg;
	ST_PCC_COMP_CONFIG* pstCompCfg;
	ST_PCC_ATB_VLD_CTRL_CONFIG* pstATBVldCtrlCfg;
	ST_PCC_MULTISIB_CONFIG* pstMultiSIBCfg;
	ST_PCC_DFE_ATB_PATH_CONFIG* pstDfeATBPathCfg;
	ST_PCC_INT_CONFIG* pstPCCIntCfg;
} ST_PCC_CONFIG;	

/*********************************************************/
/*The config structures need not to be set in normal case*/
/*These config can be left to use the default value      */
/*********************************************************/
typedef struct _ST_PCC_PK_SYNCWORD {
	kal_uint32 u32PNStart;
	kal_uint32 u32PNStop;
	kal_uint32 u32PNFull;
} ST_PCC_PK_SYNCWORD;

typedef struct _ST_PCC_ANTENNA_RFCARRIER_SEL {
	EN_PCC_ANTENNA_RFCARRIER enP11;
	EN_PCC_ANTENNA_RFCARRIER enP12;
	EN_PCC_ANTENNA_RFCARRIER enP21;
	EN_PCC_ANTENNA_RFCARRIER enP22;
} ST_PCC_ANTENNA_RFCARRIER_SEL;

typedef struct _ST_PCC_ATBYTES_CONFIG {
	kal_uint8 u8ATBytesS0;
	kal_uint8 u8ATBytesS1;
	kal_uint8 u8ATBytesS2;
	kal_uint8 u8ATBytesS3;
	kal_uint8 u8ATBytesS4;
	kal_uint8 u8ATBytesS5;
} ST_PCC_ATBYTES_CONFIG;

/*********************************************************/
/* The structures used to get status */
/*********************************************************/
typedef struct _ST_PCC_FIFO_STATUS {
	kal_bool b8ATBFull;
	kal_bool b8CompFull;
	kal_uint8 u8FifoDepthAT1;
	kal_uint8 u8FifoDepthAT2;
	kal_uint8 u8FifoDepthAT3;
	kal_uint8 u8FifoDepthAT4;
} ST_PCC_FIFO_STATUS;

typedef struct _ST_PCC_FSM_STATUS {
	EN_PCC_FSM_STATUS enP11Status;
	EN_PCC_FSM_STATUS enP12Status;
	EN_PCC_FSM_STATUS enP21Status;
	EN_PCC_FSM_STATUS enP22Status;
	EN_PCC_PK_FSM_STATUS enPKStatus;
	EN_PCC_FSM_STATUS enAdjStatus;
} ST_PCC_FSM_STATUS;

typedef struct _ST_PCC_THROUGHPUT_STATUS {
	kal_uint32 u32ATBReadyNum0;
	kal_uint32 u32ATBReadyNum1;
	kal_uint32 u32ATBReadyNum2;
	kal_uint32 u32ATBReadyNum3;
	kal_uint32 u32ATBReadyNum4;
	kal_uint32 u32ATBReadyNum5;
	kal_uint32 u32CompValidNum0;
	kal_uint32 u32CompValidNum1;
	kal_uint32 u32CompValidNum2;
	kal_uint32 u32CompValidNum3;
	kal_uint32 u32PresyncValidNum0;
	kal_uint32 u32PresyncValidNum1;
	kal_uint32 u32PresyncValidNum2;
	kal_uint32 u32PresyncValidNum3;
	kal_uint32 u32InfoValidNum;
} ST_PCC_THROUGHPUT_STATUS;

/*********************************************************/
/* The structures used for pattern gen config */
/*********************************************************/
typedef struct _ST_PCC_PTG_CONFIG {
	EN_PCC_PTG_MODE enPTGMode;
	kal_uint16 u16ACCStep;
	kal_uint16 u16RecPeriod;
	kal_uint16 u16RecAmp;
	kal_uint8 u8VldPeriod0;
	kal_uint8 u8VldPeriod1;
	kal_uint8 u8VldPeriod2;
	kal_uint8 u8VldPeriod3;
} ST_PCC_PTG_CONFIG;


/* IRQ Define */
typedef void (*pcc_intr_cb)(void);
#define PCC_FULL_IRQID (IRQ_DFE_PCC_FULL_CODE)


/* Default ATID Define */
#define DEFAULT_ATID_PKSTART (0x68)
#define DEFAULT_ATID_P11 (0x69)
#define DEFAULT_ATID_P12 (0x6A)
#define DEFAULT_ATID_P21 (0x6B)
#define DEFAULT_ATID_P22 (0x6C)
#define DEFAULT_ATID_ADJ (0x6D)

/* Default Compressor Setting Define */
#define DEFAULT_CNLEN0 (0x0F)
#define DEFAULT_CNLEN1 (0x06)
#define DEFAULT_CNLEN2 (0x03)
#define DEFAULT_VTH0   (0x06)
#define DEFAULT_VTH1   (0x03)

/* Default ATB Vld Control Setting Define */
#define DEFAULT_AT1_VLD_LIMIT (0)
#define DEFAULT_AT2_VLD_LIMIT (0)
#define DEFAULT_AT3_VLD_LIMIT (0)
#define DEFAULT_AT4_VLD_LIMIT (0)
#define DEFAULT_ADJ_VLD_LIMIT (0x3C)
#define DEFAULT_ATB_DISABLE_REGION_EN (0)
#define DEFAULT_ATB_REORDER_EN (0)


/***********************************/
/*      Normal Functions           */
/***********************************/

/*
 * [FUNCTION]
 *      Trigger PCC Start
 *
 * [PARAMETERS]
 *      none
 *
 * [RETURN]
 *      none
 */
#define DRV_PCC_Start()		\
        do{                 \
            PCC_WTL_CLOCK_CTRL_ON();\
		    DRV_WriteReg32(REG_PCC_CTRL0_START_STOP, CTRL_PCC_START);\
		}while(0)

/*
 * [FUNCTION]
 *      Trigger PCC Stop
 *
 * [PARAMETERS]
 *      none
 *
 * [RETURN]
 *      none
 */
#define DRV_PCC_Stop()		\
		DRV_WriteReg32(REG_PCC_CTRL0_START_STOP, CTRL_PCC_STOP)

/*
 * [FUNCTION]
 *      Get PCC Start/Stop Status
 *
 * [PARAMETERS]
 *      none
 *
 * [RETURN]
 *      0x1 for PCC is running
 *      0x0 for PCC is not running
 */
#define DRV_PCC_Start_Stop_Status_Get()    \
        (DRV_Reg32(REG_PCC_CTRL0_START_STOP) & 0x1)

/*
 * [FUNCTION]
 *      Set all register back to default values
 *
 * [PARAMETERS]
 *      none
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Init(void);

/*
 * [FUNCTION]
 *      Set Simple PCC Capture Config. A simplified configuration function of DRV_PCC_Config()
 *
 * [PARAMETERS]
 *      EN_PCC_DFESYS_CAPTURE_NODE enCapNode, ST_ATB_PATH_SEL *pstPathSel, ST_PCC_DATA_INFO_CONFIG* pstDataInfoCfg
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Simple_Capture_Config(EN_PCC_DFESYS_CAPTURE_NODE enCapNode, ST_ATB_PATH_SEL* pstPathSel, ST_PCC_DATA_INFO_CONFIG* pstDataInfoCfg);

/*
 * [FUNCTION]
 *      A function to set ATID config only
 *
 * [PARAMETERS]
 *      ST_PCC_ATID_CONFIG* pstATIDCfg
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_ATID_Config(ST_PCC_ATID_CONFIG* pstATIDCfg);

/*
 * [FUNCTION]
 *      A function to set Compressor Config only
 *
 * [PARAMETERS]
 *      ST_PCC_COMP_CONFIG* pstCompConfig
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Comp_Config_Set(ST_PCC_COMP_CONFIG* pstCompConfig);

/*
 * [FUNCTION]
 *      A function to set ATB Valid control Config only
 *
 * [PARAMETERS]
 *      ST_PCC_ATB_VLD_CTRL_CONFIG* pstATBVldCtrlConfig
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_ATB_Valid_Ctrl_Set(ST_PCC_ATB_VLD_CTRL_CONFIG* pstATBVldCtrlConfig);

/*
 * [FUNCTION]
 *      Set PCC Common Configuration for whole general config
 *
 * [PARAMETERS]
 *      ST_PCC_CONFIG* pstConfig
 *      
 *    ST_PCC_CONFIG include following configuration structure:
 *    --------------------------------------------------------
 *      ST_PCC_CAPTURE_CONFIG* pstCapCfg;                //set capture_node and ATB path_sel
 *      ST_PCC_ATID_CONFIG* pstATIDCfg;                  //set ATID of each ATB path
 *      ST_PCC_DATA_INFO_CONFIG* pstDataInfoCfg;         //set data_packet_length and info_update_period
 *      ST_PCC_COMP_CONFIG* pstCompCfg;                  //set compressor parameters of CNLengths, Vths, divisor enable or not
 *      ST_PCC_ATB_VLD_CTRL_CONFIG* pstATBVldCtrlCfg;    //set ATB vld limit optimize settings
 *      ST_PCC_MULTISIB_CONFIG* pstMultiSIBCfg;          //set multiSIB enable/disable and SIB mode in multiSIB
 *      ST_PCC_DFE_ATB_PATH_CONFIG* pstDfeATBPathCfg;    //set DFE_ATB trigger enable
 *      ST_PCC_INT_CONFIG* pstPCCIntCfg;                 //set interrupt enable/disable for ATB FIFO full and compressor FIFO full
 *
 *      If any structure pointer within ST_PCC_CONFIG is NULL, then this structure setting will be set to default value.
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Config_Set(ST_PCC_CONFIG* pstConfig);

/*
 * [FUNCTION]
 *      Get PCC Common Configuration
 *
 * [PARAMETERS]
 *      ST_PCC_CONFIG* pstConfig
 *      
 *    ST_PCC_CONFIG include following configuration structure:
 *    --------------------------------------------------------
 *      ST_PCC_CAPTURE_CONFIG* pstCapCfg;                //set capture_node and ATB path_sel
 *      ST_PCC_ATID_CONFIG* pstATIDCfg;                  //set ATID of each ATB path
 *      ST_PCC_DATA_INFO_CONFIG* pstDataInfoCfg;         //set data_packet_length and info_update_period
 *      ST_PCC_COMP_CONFIG* pstCompCfg;                  //set compressor parameters of CNLengths, Vths, divisor enable or not
 *      ST_PCC_ATB_VLD_CTRL_CONFIG* pstATBVldCtrlCfg;    //set ATB vld limit optimize settings
 *      ST_PCC_MULTISIB_CONFIG* pstMultiSIBCfg;          //set multiSIB enable/disable and SIB mode in multiSIB
 *      ST_PCC_DFE_ATB_PATH_CONFIG* pstDfeATBPathCfg;    //set DFE_ATB trigger enable
 *      ST_PCC_INT_CONFIG* pstPCCIntCfg;                 //set interrupt enable/disable for ATB FIFO full and compressor FIFO full
 *
 *      If any structure pointer within ST_PCC_CONFIG is NULL, then will not get this structure setting
 *      You can get the setting you interested with other structure pointer set to NULL
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Config_Get(ST_PCC_CONFIG* pstConfig);

/*
 * [FUNCTION]
 *      Function to register callback function when PCC full interrupt triggered
 *
 * [PARAMETERS]
 *      pcc_intr_cb callback
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Regist_CB(pcc_intr_cb callback);

/*
 * [FUNCTION]
 *      Do PCC Soft Reset
 *
 * [PARAMETERS]
 *      void
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Soft_Reset(void);

/*
 * [FUNCTION]
 *      Set PCC SIB Mode
 *
 * [PARAMETERS]
 *      EN_PCC_SIB_MODE
 *
 * [RETURN]
 *      none
 */
#define DRV_PCC_SIB_Mode_Set(mode)    \
			do{ 						  \
				if(EN_PCC_SIB_MODE_MASTER == mode)		  \
					DRV_PCC_SIB_Mode_Master();			  \
				else									  \
					DRV_PCC_SIB_Mode_Slave();			  \
			}while(0)

/*
 * [FUNCTION]
 *		Get PCC SIB Mode
 *
 * [PARAMETERS]
 *		void
 *
 * [RETURN]
 *		EN_PCC_SIB_MODE
 */
#define DRV_PCC_SIB_Mode_Get()    \
            (EN_PCC_SIB_MODE)((DRV_Reg32(REG_PCC_CTRL1_CAPTURE_CFG)>>OFS_PCC_MULTI_SIB_INOUT_SEL) & MASK_PCC_MULTI_SIB_INOUT_SEL)
            
/*
 * [FUNCTION]
 *		Enable MultiSIB
 *
 * [PARAMETERS]
 *		void
 *
 * [RETURN]
 *		none
 */
#define DRV_PCC_MultiSIB_Enable()    \
			DRV_WriteReg32(REG_PCC_CTRL1_CAPTURE_CFG, (DRV_Reg32(REG_PCC_CTRL1_CAPTURE_CFG) | CTRL_PCC_MULTI_SIB_ENABLE))

/*
 * [FUNCTION]
 *		Disable MultiSIB
 *
 * [PARAMETERS]
 *		void
 *
 * [RETURN]
 *		none
 */
#define DRV_PCC_MultiSIB_Disable()    \
			DRV_WriteReg32(REG_PCC_CTRL1_CAPTURE_CFG, (DRV_Reg32(REG_PCC_CTRL1_CAPTURE_CFG) & CTRL_PCC_MULTI_SIB_DISABLE))

/*
 * [FUNCTION]
 *		Get MultiSIB Status
 *
 * [PARAMETERS]
 *		void
 *
 * [RETURN]
 *		1 for MultiSIB is Enable
 *      0 for MultiSIB is Disable
 */
#define DRV_PCC_MultiSIB_Status_Get()    \
            ((DRV_Reg32(REG_PCC_CTRL1_CAPTURE_CFG)>>OFS_PCC_MULTI_SIB_EN) & MASK_PCC_MULTI_SIB_EN)

/*
 * [FUNCTION]
 *      Set PCC SyncWord used in the packet
 *
 * [PARAMETERS]
 *      ST_PCC_PK_SYNCWORD* pstSyncWord
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_PK_SYNCWORD_Set(ST_PCC_PK_SYNCWORD* pstSyncWord);				//if use default setting, no need to set

/*
 * [FUNCTION]
 *      Get PCC SyncWord used in the packet
 *
 * [PARAMETERS]
 *      ST_PCC_PK_SYNCWORD* pstSyncWord
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_PK_SYNCWORD_Get(ST_PCC_PK_SYNCWORD* pstSyncWord);

/*
 * [FUNCTION]
 *      Set the number of bytes on adata to be captured, minus 1
 *
 * [PARAMETERS]
 *      ST_PCC_ATBYTES_CONFIG* pstATBCtrlConfig
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_ATBytes_Set(ST_PCC_ATBYTES_CONFIG* pstATBytesConfig);		    //if use default setting, no need to set

/*
 * [FUNCTION]
 *      Get the number of bytes on adata to be captured, minus 1
 *
 * [PARAMETERS]
 *      ST_PCC_ATBYTES_CONFIG* pstATBCtrlConfig
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_ATBytes_Get(ST_PCC_ATBYTES_CONFIG* pstATBytesConfig);

/*
 * [FUNCTION]
 *      Get the FIFO status in PCC.
 *
 * [PARAMETERS]
 *      ST_PCC_FIFO_STATUS* pstFIFOStatus
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_FIFO_Status_Get(ST_PCC_FIFO_STATUS* pstFIFOStatus);

/*
 * [FUNCTION]
 *      Reset PCC FIFO status
 *
 * [PARAMETERS]
 *      void
 *
 * [RETURN]
 *      void
 */
void DRV_PCC_FIFO_Status_Reset(void);			//clear atb_full & comp_full status, and reset fifo depth from at1~at4

/*
 * [FUNCTION]
 *      Get PCC FSM status
 *
 * [PARAMETERS]
 *      ST_PCC_FSM_STATUS* pstFSMStatus
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_FSM_Status_Get(ST_PCC_FSM_STATUS* pstFSMStatus);

/*
 * [FUNCTION]
 *      Set Antenna and RFCarrier mapping
 *
 * [PARAMETERS]
 *      ST_PCC_ANTENNA_RFCARRIER_SEL* stAntCarSel
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Antenna_RFCarrier_Set(ST_PCC_ANTENNA_RFCARRIER_SEL* pstAntCarSel);

/*
 * [FUNCTION]
 *      Get Antenna and RFCarrier mapping
 *
 * [PARAMETERS]
 *      ST_PCC_ANTENNA_RFCARRIER_SEL* stAntCarSel
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Antenna_RFCarrier_Get(ST_PCC_ANTENNA_RFCARRIER_SEL* pstAntCarSel);

/*
 * [FUNCTION]
 *      Set ADC PathSel, from PreSync or compressor
 *
 * [PARAMETERS]
 *      EN_PCC_ADC_PATH_SEL enADCPathSel
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_ADC_PathSel_Set(EN_PCC_ADC_PATH_SEL enADCPathSel);

/*
 * [FUNCTION]
 *      Get ADC PathSel, from PreSync or compressor
 *
 * [PARAMETERS]
 *      void
 *
 * [RETURN]
 *      EN_PCC_ADC_PATH_SEL
 */
EN_PCC_ADC_PATH_SEL DRV_PCC_ADC_PathSel_Get(void);



/***********************************/
/*      Debug Functions           */
/***********************************/


/*
 * [FUNCTION]
 *      Set PCC throughput measure window length
 *
 * [PARAMETERS]
 *      kal_uint32 u32Length
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Throughput_Measure_Window_Length_Set(kal_uint32 u32Length);

/*
 * [FUNCTION]
 *      Get PCC throughput measure window length
 *
 * [PARAMETERS]
 *      void
 *
 * [RETURN]
 *      kal_uint32 length
 */
kal_uint32 DRV_PCC_Throughput_Measure_Window_Length_Get(void);

/*
 * [FUNCTION]
 *      Get PCC throughput measure status
 *
 * [PARAMETERS]
 *      void
 *
 * [RETURN]
 *      KAL_TRUE for measure done
 *      KAL_FALSE for measure still ongoing
 */
static INLINE kal_bool DRV_PCC_Throughput_Measure_Done(void)
{
		return ((DRV_Reg32(REG_PCC_THRPT_CTRL0) & BIT_PCC_THRPT_MEASURE_DONE)==BIT_PCC_THRPT_MEASURE_DONE)? KAL_TRUE: KAL_FALSE;
}

/*
 * [FUNCTION]
 *      Get PCC throughput measure result
 *
 * [PARAMETERS]
 *      ST_PCC_THROUGHPUT_STATUS* pstThrptStatus
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */		
kal_bool DRV_PCC_Throughput_Measure_Status_Get(ST_PCC_THROUGHPUT_STATUS* pstThrptStatus);

/*
 * [FUNCTION]
 *      Get PCC valid waittime measure result
 *
 * [PARAMETERS]
 *      void
 *
 * [RETURN]
 *      kal_uint32 valid waittime
 */
static INLINE kal_uint32 DRV_PCC_Throughput_Valid_WaitTime_Get(void)
{
		return (kal_uint32)(DRV_Reg32(REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME) & MASK_PCC_VALID_WAIT_TIME);
}

/*
 * [FUNCTION]
 *      Set PCC input path, from DFE_PreSync or Pattern Gen
 *
 * [PARAMETERS]
 *      EN_PCC_INPUT_SEL enInputSel
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_Input_Path_Set(EN_PCC_INPUT_SEL enInputSel);

/*
 * [FUNCTION]
 *      Set PCC Pattern Gen Config
 *
 * [PARAMETERS]
 *      ST_PCC_PTG_CONFIG* pstPTGConfig
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
EN_PCC_INPUT_SEL DRV_PCC_Input_Path_Get(void);

/*
 * [FUNCTION]
 *      Set PCC Pattern Gen Config
 *
 * [PARAMETERS]
 *      ST_PCC_PTG_CONFIG* pstPTGConfig
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_PTG_Config_Set(ST_PCC_PTG_CONFIG* pstPTGConfig);

/*
 * [FUNCTION]
 *      Get PCC Pattern Gen Config
 *
 * [PARAMETERS]
 *      ST_PCC_PTG_CONFIG* pstPTGConfig
 *
 * [RETURN]
 *      KAL_TRUE for success
 *      KAL_FALSE for fail
 */
kal_bool DRV_PCC_PTG_Config_Get(ST_PCC_PTG_CONFIG* pstPTGConfig);

/*
 * [FUNCTION]
 *      Enable PCC Throughput measure function
 *
 * [PARAMETERS]
 *      void
 *
 * [RETURN]
 *      void
 */
#define DRV_PCC_Throughput_Measure_Enable()	\
		DRV_WriteReg32(REG_PCC_THRPT_CTRL0, (DRV_Reg32(REG_PCC_THRPT_CTRL0) | CTRL_PCC_THRPT_MEASURE_ENABLE))

/*
 * [FUNCTION]
 *      Disable PCC Throughput measure function
 *
 * [PARAMETERS]
 *      void
 *
 * [RETURN]
 *      void
 */
#define DRV_PCC_Throughput_Measure_Disable()	\
		DRV_WriteReg32(REG_PCC_THRPT_CTRL0, (DRV_Reg32(REG_PCC_THRPT_CTRL0) & (~CTRL_PCC_THRPT_MEASURE_ENABLE)))

/*
 * [FUNCTION]
 *      Reset PCC valid waittime measure result
 *
 * [PARAMETERS]
 *      void
 *
 * [RETURN]
 *      void
 */
#define DRV_PCC_Throughput_Valid_WaitTime_Reset()	\
		do{											\
			DRV_WriteReg32(REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME, 												\
			               (DRV_Reg32(REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME)| CTRL_PCC_VALID_WAIT_TIME_RST));	\
			DRV_WriteReg32(REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME, 												\
			               (DRV_Reg32(REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME)& ~CTRL_PCC_VALID_WAIT_TIME_RST));	\
		}while(0)

/*
 * [FUNCTION]
 *		Enable PCC valid waittime measure function
 *
 * [PARAMETERS]
 *		void
 *
 * [RETURN]
 *		void
 */
#define DRV_PCC_Throughput_Valid_WaitTime_Measure_Enable()	\
			DRV_WriteReg32(REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME, (DRV_Reg32(REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME) | CTRL_PCC_VALID_WAIT_TIME_ENABLE))

/*
 * [FUNCTION]
 *		Disable PCC valid waittime measure function
 *
 * [PARAMETERS]
 *		void
 *
 * [RETURN]
 *		void
 */
#define DRV_PCC_Throughput_Valid_WaitTime_Measure_Disable()	\
			DRV_WriteReg32(REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME, (DRV_Reg32(REG_PCC_THRPT_CTRL17_VALID_WAIT_TIME) & (~CTRL_PCC_VALID_WAIT_TIME_ENABLE)))

/*
 * [FUNCTION]
 *		Enable PCC Pattern Gen
 *
 * [PARAMETERS]
 *		void
 *
 * [RETURN]
 *		void
 */
#define DRV_PCC_PTG_Enable()	\
		DRV_WriteReg32(REG_PCC_PATGEN_CTRL0, (DRV_Reg32(REG_PCC_PATGEN_CTRL0) | CTRL_PCC_PTG_ENABLE))

/*
 * [FUNCTION]
 *		Disable PCC Pattern Gen
 *
 * [PARAMETERS]
 *		void
 *
 * [RETURN]
 *		void
 */
#define DRV_PCC_PTG_Disable()	\
		DRV_WriteReg32(REG_PCC_PATGEN_CTRL0, (DRV_Reg32(REG_PCC_PATGEN_CTRL0) & (~CTRL_PCC_PTG_ENABLE)))

/*
 * [FUNCTION]
 *		Enable ATIME control bit outside the PCC module
 *
 * [PARAMETERS]
 *		void
 *
 * [RETURN]
 *		void
 */
#define DRV_PCC_USE_ATIME_ENABLE()    \
        DRV_WriteReg32(0xF60E012C, (DRV_Reg32(0xF60E012C) | 0x1))

/*
 * [FUNCTION]
 *		Disable ATIME control bit outside the PCC module
 *
 * [PARAMETERS]
 *		void
 *
 * [RETURN]
 *		void
 */
#define DRV_PCC_USE_ATIME_DISABLE()    \
        DRV_WriteReg32(0xF60E012C, (DRV_Reg32(0xF60E012C) & (~0x1)))


/*New Features on Jade*/
#ifdef CHIP_JADE
#define DRV_PCC_Ini_Comp_Ignore_Enable()    \
        DRV_WriteReg32(REG_PCC_CTRL1_CAPTURE_CFG, (DRV_Reg32(REG_PCC_CTRL1_CAPTURE_CFG) | CTRL_PCC_INI_CMP_IGNORE_ENABLE))

#define DRV_PCC_Ini_Comp_Ignore_Disable()   \
        DRV_WriteReg32(REG_PCC_CTRL1_CAPTURE_CFG, (DRV_Reg32(REG_PCC_CTRL1_CAPTURE_CFG) & CTRL_PCC_INI_CMP_IGNORE_DISABLE))

#define DRV_PCC_Comp_Rst_Enable()    \
        DRV_WriteReg32(REG_PCC_CTRL8_COMP_CFG, (DRV_Reg32(REG_PCC_CTRL8_COMP_CFG) | CTRL_COMP_RST_ENABLE))

#define DRV_PCC_Comp_Rst_Disable()    \
        DRV_WriteReg32(REG_PCC_CTRL8_COMP_CFG, (DRV_Reg32(REG_PCC_CTRL8_COMP_CFG) & CTRL_COMP_RST_DISABLE))
#endif


//new add for PCC CLK power down control in DFESYS
//TK6291 is default on, but Jade is default off.
//Need to turn on before PCC_START
#define PCC_WTL_CLOCK_CTRL_ON()    \
        do{                        \
            DRV_WriteReg32(REG_DFESYS_CFG_PDN_W_CON0, (DRV_Reg32(REG_DFESYS_CFG_PDN_W_CON0)&(~BIT_PDN_W_TRACE_WTL_PWDOWN)));        \
            DRV_WriteReg32(REG_DFESYS_CFG_PDN_T_CON1, (DRV_Reg32(REG_DFESYS_CFG_PDN_T_CON1)&(~BIT_PDN_T_TRACE_WTL_PWDOWN)));        \
            DRV_WriteReg32(REG_DFESYS_CFG_PDN_L_CON2, (DRV_Reg32(REG_DFESYS_CFG_PDN_L_CON2)&(~BIT_PDN_L_TRACE_WTL_PWDOWN)));        \
        }while(0)

#define PCC_WTL_CLOCK_CTRL_OFF()    \
		do{ 					   \
			DRV_WriteReg32(REG_DFESYS_CFG_PDN_W_CON0, (DRV_Reg32(REG_DFESYS_CFG_PDN_W_CON0)|BIT_PDN_W_TRACE_WTL_PWDOWN));		\
			DRV_WriteReg32(REG_DFESYS_CFG_PDN_T_CON1, (DRV_Reg32(REG_DFESYS_CFG_PDN_T_CON1)|BIT_PDN_T_TRACE_WTL_PWDOWN));		\
			DRV_WriteReg32(REG_DFESYS_CFG_PDN_L_CON2, (DRV_Reg32(REG_DFESYS_CFG_PDN_L_CON2)|BIT_PDN_L_TRACE_WTL_PWDOWN));		\
		}while(0)
     
#endif // end of __DRV_PCC_H__
