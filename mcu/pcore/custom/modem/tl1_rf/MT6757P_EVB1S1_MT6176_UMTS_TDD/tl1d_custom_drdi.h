/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  tl1d_custom_drdi.h
 *
 * Project:
 * --------
 *  MOLY
 *
 * Description:
 * ------------
 *  Dynamic Radio-setting Dedicated Image.
 *  DRDI parameters custom macro definitions
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/

#ifndef  _TL1D_CUSTOM_DRDI_H_
#define  _TL1D_CUSTOM_DRDI_H_


/*******************************************************************************
** Includes
*******************************************************************************/
#include "kal_general_types.h"
#include "mml1_custom_drdi.h"


/*****************************************************************************
* Constant    : TL1_CUSTOM_TOTAL_SET_NUMS
* Group       : Real target, Internals, TL1 common operation
* Description : Constant to be used as the number of total configuration sets
*****************************************************************************/

typedef  struct {
kal_uint16 uwAction1;
kal_int16  swAction1TimingAdv;
kal_uint16 uwAction2;
kal_int16  swAction2TimingAdv;
kal_uint16 uwAction3;
kal_int16  swAction3TimingAdv;
kal_uint16 uwAction4;
kal_int16  swAction4TimingAdv;
kal_uint16 uwAction5;
kal_int16  swAction5TimingAdv;
kal_uint16 uwAction6;
kal_int16  swAction6TimingAdv;
kal_uint16 uwAction7;
kal_int16  swAction7TimingAdv;
kal_uint16 uwAction8;
kal_int16  swAction8TimingAdv;
kal_uint16 uwAction9;
kal_int16  swAction9TimingAdv;
kal_uint16 uwAction10;
kal_int16  swAction10TimingAdv;
kal_uint16 uwAction11;
kal_int16  swAction11TimingAdv;
kal_uint16 uwAction12;
kal_int16  swAction12TimingAdv;
kal_uint16 uwAction13;
kal_int16  swAction13TimingAdv;
kal_uint16 uwAction14;
kal_int16  swAction14TimingAdv;
kal_uint16 uwAction15;
kal_int16  swAction15TimingAdv;
kal_uint16 uwAction16;
kal_int16  swAction16TimingAdv;
kal_uint16 uwAction17;
kal_int16  swAction17TimingAdv;
kal_uint16 uwAction18;
kal_int16  swAction18TimingAdv;
kal_uint16 uwAction19;
kal_int16  swAction19TimingAdv;
kal_uint16 uwAction20;
kal_int16  swAction20TimingAdv;
kal_uint16 uwAction21;
kal_int16  swAction21TimingAdv;
kal_uint16 uwAction22;
kal_int16  swAction22TimingAdv;
kal_uint16 uwAction23;
kal_int16  swAction23TimingAdv;
kal_uint16 uwAction24;
kal_int16  swAction24TimingAdv;
kal_uint16 uwAction25;
kal_int16  swAction25TimingAdv;
/*kal_uint16 uwAction26;
kal_int16  swAction26TimingAdv;
kal_uint16 uwAction27;
kal_int16  swAction27TimingAdv;
kal_uint16 uwAction28;
kal_int16  swAction28TimingAdv;
kal_uint16 uwAction29;
kal_int16  swAction29TimingAdv;
kal_uint16 uwAction30;
kal_int16  swAction30TimingAdv;*/
} T_ACTION_TIMING_STRUCT;

typedef  struct {	
T_ACTION_TIMING_STRUCT tEnableDownlink;
T_ACTION_TIMING_STRUCT tDisableDownlink;
T_ACTION_TIMING_STRUCT tEnableUplink;
T_ACTION_TIMING_STRUCT tDisableUplink;
T_ACTION_TIMING_STRUCT tDlsGapCtrl;
T_ACTION_TIMING_STRUCT tUlsGapCtrl;
T_ACTION_TIMING_STRUCT tUlDlGapCtrl;
T_ACTION_TIMING_STRUCT tEnableUplinkF;
T_ACTION_TIMING_STRUCT tDisableUplinkF;
T_ACTION_TIMING_STRUCT tEnableUplinkE;
T_ACTION_TIMING_STRUCT tDisableUplinkE;

} T_RF_PROG_SEQ_STRUCT;



typedef  struct {
kal_uint32 uwTxCtrlUseBitsSet;
kal_uint32 uwTx2G34PaHModeSet;
kal_uint32 uwTx2G34PaMModeSet;
kal_uint32 uwTx2G34PaLModeSet;
kal_uint32 uwTx2G01PaHModeSet;
kal_uint32 uwTx2G01PaMModeSet;
kal_uint32 uwTx2G01PaLModeSet;
kal_uint32 uwTx1G90PaHModeSet;
kal_uint32 uwTx1G90PaMModeSet;
kal_uint32 uwTx1G90PaLModeSet;
kal_uint32 uwTxCtrlDisable;
} BPI_AREA1_STRUCT;


typedef  struct {
kal_uint32 uwRxCtrlUseBitsSet;
kal_uint32 uwRxBand2G34Set;
kal_uint32 uwRxBand2G01Set;
kal_uint32 uwRxBand1G90Set;
kal_uint32 uwRxCtrlDisable;
} BPI_AREA2_STRUCT;


typedef  struct {
kal_uint32 uwPaEnableUseBitsSet;
kal_uint32 uwPaEnable2G34Set;
kal_uint32 uwPaEnable2G01Set;
kal_uint32 uwPaEnable1G90Set;
kal_uint32 uwPaDisable;
} BPI_AREA3_STRUCT;

typedef  struct {
kal_uint32 uwAreaUseBitsSet;
kal_uint32 uwAreaEnable;
kal_uint32 uwAreaDisable;
} BPI_AREANORMAL_STRUCT;

typedef  struct {
kal_uint32 uwPaStage;
BPI_AREA1_STRUCT tBpiArea1PaModeSet;
BPI_AREA2_STRUCT tBpiArea2BandModeSel;
#ifdef __TAS_SUPPORT__
BPI_AREA1_STRUCT tBpiArea1PaModeSetAnt1;
BPI_AREA2_STRUCT tBpiArea2BandModeSelAnt1;
#endif
BPI_AREA3_STRUCT tBpiArea3PaCtrlSet;
BPI_AREANORMAL_STRUCT  tBpiArea4Set;
BPI_AREANORMAL_STRUCT  tBpiArea5Set;
} T_BPI_SETTING_STRUCT;


typedef  struct {
kal_uint16 uwMaskVoltBit;	
kal_uint16 uwB34ApcHighGainV;
kal_uint16 uwB34ApcMidGainV;
kal_uint16 uwB34ApcLowGainV;
kal_uint16 uwB39ApcHighGainV;
kal_uint16 uwB39ApcMidGainV;
kal_uint16 uwB39ApcLowGainV;
kal_uint16 uwPadding;

} T_ABB_APC_VOLT_STRUCT;

typedef  struct {
kal_uint16 uwTx2G01SelRFport;  /*TX BAND34*/
kal_uint16 uwTx1G90SelRFport;  /*TX BAND39*/
kal_uint16 uwTx2G34SelRFport;  /*TX BAND40*/
kal_uint16 uwRx2G01SelRFport;  /*RX BAND34*/
kal_uint16 uwRx1G90SelRFport;  /*RX BAND39*/
kal_uint16 uwRx2G34SelRFport;  /*RX BAND40*/
} T_RF_PORT_SEL_STRUCT;


typedef  struct {
kal_uint16 uwRXIQSwap;  /*RX  0:  NO IQ SWAP     1: IQ SWAP */
kal_uint16 uwTXIQSwap;  /*TX  0:  NO IQ SWAP     1: IQ SWAP */
} T_IQ_SWAP_CFG_STRUCT;

typedef  struct {
kal_uint16 uwBand34HighGainV;   /*B34 High Gain VPA voltage */
kal_uint16 uwBand34MidGainV;    /*B34 Mid Gain VPA voltage */
kal_uint16 uwBand34LowGainV;    /*B34 Low Gain VPA voltage */
kal_uint16 uwBand39HighGainV;   /*B39 High Gain VPA voltage */
kal_uint16 uwBand39MidGainV;    /*B39 Mid Gain VPA voltage */
kal_uint16 uwBand39LowGainV;    /*B39 Low Gain VPA voltage */
} T_VPA_VOLT_STRUCT;

typedef  struct {
kal_uint16 uwPadding[128];   /*reserve for future use */

} T_PADDING_RESV_STRUCT;

#ifdef __TAS_SUPPORT__
typedef struct{
kal_uint16 uwTasEnable;
kal_uint16 uwTasDefaultMainAntenna;
kal_uint16 uwTasDefaultType;
kal_uint16 uwTasTypebyBand;
kal_uint16 uwTasForceTxAntEnable;
kal_uint16 uwTasForceTxAntIdx;
kal_uint16 uwTasWithTestSimEnable;
kal_uint16 uwTasWithCommParamRscpD;
kal_uint16 uwTasWithSarParamRscpD;
kal_uint16 uwTasWithCommParamHTP;
kal_uint16 uwTasWithSarParamHTP;
kal_uint16 uwTasWithCommParamHTPOft;
}T_TAS_SETTING_STRUCT;

#ifdef __TAS_ANTENNA_IDX_ON_TEST_SIM__
typedef struct{
kal_uint16 uwTasTestSimAntIdxB34;
kal_uint16 uwTasTestSimAntIdxB39;
kal_uint16 uwTasTestSimAntIdxB40;
}T_TAS_TESTSIM_ANT_IDX_STRUCT;
#endif

#endif

typedef  struct {
T_BPI_SETTING_STRUCT   tBpiSetting;
T_ABB_APC_VOLT_STRUCT  tAbbApcVoltCfg;
T_RF_PORT_SEL_STRUCT  tOtPortSelCfg;
T_IQ_SWAP_CFG_STRUCT   tTrxIQswapCfg;
T_VPA_VOLT_STRUCT      tVpaVoltCfg;
#ifdef __TAS_SUPPORT__
T_TAS_SETTING_STRUCT   tTasSetting;
#ifdef __TAS_ANTENNA_IDX_ON_TEST_SIM__
T_TAS_TESTSIM_ANT_IDX_STRUCT tTasTestSimAntIdx;
#endif
#endif
#if defined(__TX_POWER_OFFSET_SUPPORT__)
kal_uint16  uwSwtpPowerOffset[2][20][4];
#endif
T_PADDING_RESV_STRUCT  tReserverData;
} T_TD_CUSTOMIZATION_STRUCT;



typedef  struct {
kal_uint16 uwDeviceID1;
kal_uint16 uwDeviceID2;
kal_uint16 uwDeviceID3;
kal_uint16 uwDeviceID4;
} T_MIPI_DEVICE_STRUCT;

typedef  struct {
kal_uint16 uwElementType;
kal_uint16 uwDataStart;
kal_uint16 uwDataStop;
} T_MIPI_EVENT_ITEM_STRUCT;

typedef  struct {
kal_uint16 uwElementTypeAndPort;
kal_uint16 uwDataLowBand34;
kal_uint16 uwDataHighBand34;
kal_uint16 uwDataLowBand39;
kal_uint16 uwDataHighBand39;
} T_MIPI_DATA_ITEM_STRUCT;

typedef  struct {
kal_uint16 uwElementTypeAndPort;
kal_uint16 uwDataLow;
kal_uint16 uwDataHigh;
} T_MIPI_INIT_ITEM_STRUCT;


typedef  struct {
T_MIPI_EVENT_ITEM_STRUCT uwEvent1;
T_MIPI_EVENT_ITEM_STRUCT uwEvent2;
T_MIPI_EVENT_ITEM_STRUCT uwEvent3;
T_MIPI_EVENT_ITEM_STRUCT uwEvent4;
} T_MIPI_EVENT_STRUCT;

typedef  struct {
T_MIPI_DATA_ITEM_STRUCT uwData1;
T_MIPI_DATA_ITEM_STRUCT uwData2;
T_MIPI_DATA_ITEM_STRUCT uwData3;
T_MIPI_DATA_ITEM_STRUCT uwData4;
T_MIPI_DATA_ITEM_STRUCT uwData5;
T_MIPI_DATA_ITEM_STRUCT uwData6;
T_MIPI_DATA_ITEM_STRUCT uwData7;
T_MIPI_DATA_ITEM_STRUCT uwData8;
T_MIPI_DATA_ITEM_STRUCT uwData9;
T_MIPI_DATA_ITEM_STRUCT uwData10;
T_MIPI_DATA_ITEM_STRUCT uwData11;
T_MIPI_DATA_ITEM_STRUCT uwData12;
} T_MIPI_DATA_STRUCT;

typedef  struct {
T_MIPI_INIT_ITEM_STRUCT uwData1;
T_MIPI_INIT_ITEM_STRUCT uwData2;
T_MIPI_INIT_ITEM_STRUCT uwData3;
T_MIPI_INIT_ITEM_STRUCT uwData4;
T_MIPI_INIT_ITEM_STRUCT uwData5;
T_MIPI_INIT_ITEM_STRUCT uwData6;
T_MIPI_INIT_ITEM_STRUCT uwData7;
T_MIPI_INIT_ITEM_STRUCT uwData8;
T_MIPI_INIT_ITEM_STRUCT uwData9;
T_MIPI_INIT_ITEM_STRUCT uwData10;
T_MIPI_INIT_ITEM_STRUCT uwData11;
T_MIPI_INIT_ITEM_STRUCT uwData12;
} T_MIPI_INIT_DATA_STRUCT;

typedef  struct {
T_MIPI_DATA_ITEM_STRUCT uwData1;
T_MIPI_DATA_ITEM_STRUCT uwData2;
T_MIPI_DATA_ITEM_STRUCT uwData3;
T_MIPI_DATA_ITEM_STRUCT uwData4;
T_MIPI_DATA_ITEM_STRUCT uwData5;
} T_MIPI_PA_DATA_STRUCT;

typedef  struct {
T_MIPI_EVENT_STRUCT  eRxOnEvent;
T_MIPI_EVENT_STRUCT  eRxOffEvent;
T_MIPI_EVENT_STRUCT  eTxOnEvent;
T_MIPI_EVENT_STRUCT  eTxOffEvent;
} T_MIPI_EVENT_ALL_STRUCT;

typedef  struct {
T_MIPI_DATA_STRUCT   eRxOnData;
T_MIPI_DATA_STRUCT   eRxOffData;
T_MIPI_DATA_STRUCT   eTxOnData;
T_MIPI_DATA_STRUCT   eTxOffData;
} T_MIPI_DATA_ALL_STRUCT;

typedef  struct {
T_MIPI_PA_DATA_STRUCT    ePAHighMode;
T_MIPI_PA_DATA_STRUCT    ePAMiddleMode;
T_MIPI_PA_DATA_STRUCT    ePALowMode;
} T_MIPI_PA_MODE_STRUCT;

typedef  struct {
kal_uint16  uwInitRegNum;   
T_MIPI_DEVICE_STRUCT  eMipiDeviceID;
T_MIPI_INIT_DATA_STRUCT  eMipiInit; 
T_MIPI_EVENT_ALL_STRUCT eMipiEvent;
T_MIPI_DATA_ALL_STRUCT  eMipiData;
T_MIPI_PA_MODE_STRUCT   ePaData;
} T_MIPI_CUSTOMIZATION_STRUCT;

typedef struct
{
   T_TD_CUSTOMIZATION_STRUCT         *rfTable_p;
   T_MIPI_CUSTOMIZATION_STRUCT       *mipiTable_p;
   T_RF_PROG_SEQ_STRUCT              *timingTable_p;
}tl1CustomDynamicInitMipiData;

typedef enum
{
	ANTENNA_0		= 0,
	ANTENNA_1		= 1,
	ANTENNA_NUM		= 2
}ANTENNA_SEL;


#if defined(_T12193_C_) 
#if IS_MML1_DRDI_ENABLE
kal_uint16  gTdsDrdiFlag = 1;
#else
kal_uint16  gTdsDrdiFlag = 0;
#endif

#else
extern kal_uint16  gTdsDrdiFlag;
#endif

#if IS_MML1_DRDI_ENABLE
#define TL1_CUSTOM_TOTAL_SET_NUMS     MML1_DRDI_REMAP_TDS_REAL_SET_NUMS 
#else
#define TL1_CUSTOM_TOTAL_SET_NUMS     1
#endif
 
extern const kal_uint16 NVRAM_EF_AST_TL1_TEMP_DAC_DATA_DEFAULT[];
extern const kal_uint16 NVRAM_EF_AST_TL1_AFC_DATA_DEFAULT[];
extern const kal_int16  NVRAM_EF_AST_TL1_PATHLOSS_33_35_37_39_DEFAULT[];
extern const kal_int16  NVRAM_EF_AST_TL1_PATHLOSS_34_DEFAULT[];
extern const kal_int16  NVRAM_EF_AST_TL1_PATHLOSS_40_DEFAULT[];
extern const kal_int16  NVRAM_EF_AST_TL1_TXDAC_33_35_37_39_DEFAULT[];
extern const kal_int16  NVRAM_EF_AST_TL1_TXDAC_34_DEFAULT[];
extern const kal_int16  NVRAM_EF_AST_TL1_TXDAC_40_DEFAULT[];
extern const kal_int16  NVRAM_EF_AST_TL1_ABB_CAL_DEFAULT[];
extern const kal_uint32  NVRAM_EF_AST_TL1_CAP_DATA_DEFAULT[];
extern const kal_int16  NVRAM_EF_AST_TL1_TXCLPC_33_35_37_39_DEFAULT[];
extern const kal_int16  NVRAM_EF_AST_TL1_TXCLPC_34_DEFAULT[];
extern const kal_int16  NVRAM_EF_AST_TL1_TXCLPC_40_DEFAULT[];

extern T_TD_CUSTOMIZATION_STRUCT AST_TL1_RF_PARAMETER_DEFAULT_SetDefault[];
extern  T_MIPI_CUSTOMIZATION_STRUCT	  AST_TL1_RFFE_PARAMETER_DEFAULT_SetDefault[];
extern T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_SetDefault[];
extern tl1CustomDynamicInitMipiData tl1CustomMipiData[TL1_CUSTOM_TOTAL_SET_NUMS];

#if IS_MML1_DRDI_ENABLE
#if TL1_CUSTOM_TOTAL_SET_NUMS > 0 
/*Include build for Set0 custom folder*/ 
extern T_TD_CUSTOMIZATION_STRUCT AST_TL1_RF_PARAMETER_DEFAULT_Set0[];   
extern T_MIPI_CUSTOMIZATION_STRUCT	  AST_TL1_RFFE_PARAMETER_DEFAULT_Set0[];
extern T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_Set0[];
#endif 
#if TL1_CUSTOM_TOTAL_SET_NUMS > 1 
/*Include build for Set1 custom folder*/ 
extern T_TD_CUSTOMIZATION_STRUCT AST_TL1_RF_PARAMETER_DEFAULT_Set1[];   
extern T_MIPI_CUSTOMIZATION_STRUCT	 AST_TL1_RFFE_PARAMETER_DEFAULT_Set1[];
extern T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_Set1[];
#endif 
#if TL1_CUSTOM_TOTAL_SET_NUMS > 2 
/*Include build for Set1 custom folder*/ 
extern T_TD_CUSTOMIZATION_STRUCT AST_TL1_RF_PARAMETER_DEFAULT_Set2[];   
extern T_MIPI_CUSTOMIZATION_STRUCT	 AST_TL1_RFFE_PARAMETER_DEFAULT_Set2[];
extern T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_Set2[];
#endif    
#if TL1_CUSTOM_TOTAL_SET_NUMS > 3 
/*Include build for Set1 custom folder*/ 
extern T_TD_CUSTOMIZATION_STRUCT AST_TL1_RF_PARAMETER_DEFAULT_Set3[];   
extern T_MIPI_CUSTOMIZATION_STRUCT	 AST_TL1_RFFE_PARAMETER_DEFAULT_Set3[];
extern T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_Set3[];
#endif 
#if TL1_CUSTOM_TOTAL_SET_NUMS > 4 
/*Include build for Set1 custom folder*/ 
extern T_TD_CUSTOMIZATION_STRUCT AST_TL1_RF_PARAMETER_DEFAULT_Set4[];   
extern T_MIPI_CUSTOMIZATION_STRUCT	 AST_TL1_RFFE_PARAMETER_DEFAULT_Set4[];
extern T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_Set4[];
#endif 
#if TL1_CUSTOM_TOTAL_SET_NUMS > 5 
/*Include build for Set1 custom folder*/ 
extern T_TD_CUSTOMIZATION_STRUCT AST_TL1_RF_PARAMETER_DEFAULT_Set5[];   
extern T_MIPI_CUSTOMIZATION_STRUCT	 AST_TL1_RFFE_PARAMETER_DEFAULT_Set5[];
extern T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_Set5[];
#endif 
#if TL1_CUSTOM_TOTAL_SET_NUMS > 6 
/*Include build for Set1 custom folder*/ 
extern T_TD_CUSTOMIZATION_STRUCT AST_TL1_RF_PARAMETER_DEFAULT_Set6[];   
extern T_MIPI_CUSTOMIZATION_STRUCT	 AST_TL1_RFFE_PARAMETER_DEFAULT_Set6[];
extern T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_Set6[];
#endif 
#if TL1_CUSTOM_TOTAL_SET_NUMS > 7 
/*Include build for Set1 custom folder*/ 
extern T_TD_CUSTOMIZATION_STRUCT AST_TL1_RF_PARAMETER_DEFAULT_Set7[];   
extern T_MIPI_CUSTOMIZATION_STRUCT	 AST_TL1_RFFE_PARAMETER_DEFAULT_Set7[];
extern T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_Set7[];
#endif 
#if TL1_CUSTOM_TOTAL_SET_NUMS > 8 
/*Include build for Set1 custom folder*/ 
extern T_TD_CUSTOMIZATION_STRUCT AST_TL1_RF_PARAMETER_DEFAULT_Set8[];   
extern T_MIPI_CUSTOMIZATION_STRUCT	 AST_TL1_RFFE_PARAMETER_DEFAULT_Set8[];
extern T_RF_PROG_SEQ_STRUCT   AST_TL1_SEQ_DEFAULT_Set8[];
#endif 
#endif

#ifdef __TAS_SUPPORT__
/* Transmit Antenna Selection feature usage */
#define TDD_TAS_PIN_NULL                               (-1)
#define TDD_TAS_BPI_PIN_GEN(var1, var2, var3, var4, s) \
                    (((kal_uint32)(TDD_TAS_BPI_PIN0_BPI_NUM_##s==TDD_TAS_PIN_NULL?0:((var1)<<(TDD_TAS_BPI_PIN0_BPI_NUM_##s)))) \
                       | ((kal_uint32)(TDD_TAS_BPI_PIN1_BPI_NUM_##s==TDD_TAS_PIN_NULL?0:((var2)<<(TDD_TAS_BPI_PIN1_BPI_NUM_##s)))) \
                       | ((kal_uint32)(TDD_TAS_BPI_PIN2_BPI_NUM_##s==TDD_TAS_PIN_NULL?0:((var3)<<(TDD_TAS_BPI_PIN2_BPI_NUM_##s)))) \
                       | ((kal_uint32)(TDD_TAS_BPI_PIN3_BPI_NUM_##s==TDD_TAS_PIN_NULL?0:((var4)<<(TDD_TAS_BPI_PIN3_BPI_NUM_##s)))))
#endif

#endif /* _TL1D_CUSTOM_DRDI_H_*/
