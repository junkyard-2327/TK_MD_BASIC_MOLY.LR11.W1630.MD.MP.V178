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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	afe.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Audio Manager
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.32  $
 * $Modtime:   Aug 01 2005 17:46:08  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1audio/am.h-arc  $
 *
 * 07 11 2016 ting-ni.chen
 * [MOLY00188920] [cx880]MO：卡1 ?信， MT：卡1 移? 卡2 移?（4G Volte），打?mtklog，vmlog，富迪log，MO打MT卡1，必定??的??
 * Fix build warnings
 *
 * 05 11 2016 thomas.chen
 * [MOLY00177679] [CU Pre-test][魅族Z180][MT6750][?4G][第一?摸底??]???音通??束后接??行窄??音通?，接通?MT端??高清?音HD??
 * 	
 * 	.
 *
 * 03 30 2016 thomas.chen
 * [MOLY00171791] [MT6755][Jade M6][MP3][MTBF][Lab][HQ][Ericsson]"Externel (EE),0,0,99,/data/core/,1,modem,md1:(MCU_PCORE) [Fatal error (task)] err_code1:0x00002307 err_code2:0x0457031A erro_code3:0x00002543"during MTBF test.
 * 	
 * 	ALPS02633740 MED is blocked too long
 *
 * 03 26 2016 thomas.chen
 * [MOLY00171157] [Common issue][MT6755][Jade][MP3][M][CSFB DSDS][overnight][FDD][SH][TTLIA] DUT Externel (EE),0,0,99,/data/core/,1,modem,md1:(MCU_PCORE) [Fatal error (data abort)] err_code1:0x00000004 err_code2:0x00449A74 err_code3:0x00000B4C CaDeFa Supported
 * .
 *
 * 11 12 2015 sheila.chen
 * [MOLY00149073] [Need Patch] [Volunteer Patch] HD voice for WWOP
 * HD Voice.
 *
 * 11 04 2015 thomas.chen
 * [MOLY00147759] sphdrv logging trace reduction
 * .
 *
 * 09 01 2015 ting-ni.chen
 * [MOLY00139885] [UMOLY] fix LR11 build warnings
 * LR11 build warnings
 *
 * 06 12 2015 ting-ni.chen
 * [MOLY00120200] 6291Plus development
 * 6291 Pcore modification
 *
 * 06 11 2015 ting-ni.chen
 * [MOLY00120200] 6291Plus development
 * 	L1Core function name modification (prepare for 6291 plus)
 *
 * 02 03 2015 fu-shing.ju
 * [MOLY00091627] TK6291 development
 * Sync Audio driver with MOLY TRUNK W15.05.P1.
 *
 * 01 13 2014 thomas.chen
 * [MOLY00053440] [MT6582LTE][IMS][VOLTE] VoLTE Data Plan Feature In
 * .
 *
 * 10 28 2013 thomas.chen
 * [MOLY00043994] In VT call without receiving ESPEECH:1, the speech driver cannot playback the sound from the network. In addtion, without receiving ESPEECH:1,  the acousticloopback should work well as before
 * .
 *
 * 10 01 2013 thomas.chen
 * [MOLY00038820] Add L4C Event interface
 * .
 *
 * 08 05 2013 sheila.chen
 * [MOLY00011218] [MT6290] Code modification
 * remove unused afe code
 *
 * 05 14 2013 sheila.chen
 * [MOLY00022118] [Volunteer Patch] DRC2.0 (MagiLoudness) Integration
 * DRC 2.0 modification
 *
 * 05 03 2013 sheila.chen
 * [MOLY00008234] [MT6572/MT6582] Integration
 * 3-in-1 speaker interface
 *
 * 01 08 2013 sheila.chen
 * [MOLY00008474] [MT6589] Fix 8k control bug when device switch
 * set mode bug fix
 *
 * 12 18 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Set Mode Modification
 *
 * 12 04 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * 1. Depop
 * 
 * 2. remove unused VM playback function
 *
 * 11 29 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * 1. Remove unused Sherif
 * 
 * 2. Remove SRC control in AM
 * 
 * 3. add DL mute
 * 
 * 4. modify enhancement log
 * 
 * 5. Phase in enhancement dynamic change
 * 
 * 6. CTM
 *
 * 11 21 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Warming removal 3
 * 
 * Fix CTM potential bug
 *
 * 11 20 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * 1. Idel VM with EPL bug fix
 * 
 * 2. Warnming Remove
 * 
 * 3. Dynamic feed in the enhancment parameter
 *
 * 11 01 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * 1. Sidetone update
 * 
 * 2. digital gain setting (AGC, DL volume)
 * 
 * 3. FIX AFE setting to privent too many noise
 * 
 * 4. Fix PCM MSB, LSB mapping mismatch
 * 5. Turn on enhancement
 * 6. Add Acroustic loopback code
 *
 * 10 29 2012 jy.huang
 * [MOLY00000755] Check in 3G speech delay improvement(phase1+3)
 * .
 * 
 * 09 25 2012 thomas.chen
 * [MOLY00004111] Integrate the PNW and DACA interface with SAL
 * .
 * 
 * 09 20 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * add compile option for analog AFE
 * 
 * 09 11 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Phase in call PCM record and EPL record in the same time
 * 
 * 07 27 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Fix build warning.
 * 
 * 07 25 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Phase in PCMNWAY, param AM manager with 2 parameter, and recording.
 *
 * 07 16 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Phase in 75+80. Integration change.
 *
 * 07 16 2012 kh.hung
 * [MOLY00000706] Remove compile warning
 * .
 *
 * 07 13 2012 jy.huang
 * [MOLY00000755] Check in 3G speech delay improvement(phase1+3)
 * .
 *
 * 06 08 2012 kh.hung
 * removed!
 * .
 *
 * 05 14 2012 jy.huang
 * removed!
 * .
 *
 * 05 11 2012 kh.hung
 * removed!
 * .
 *
 * 03 30 2012 thomas.chen
 * removed!
 * .
 *
 * 03 15 2012 thomas.chen
 * removed!
 * .
 *
 * 12 13 2011 thomas.chen
 * removed!
 * .
 *
 * 11 29 2011 lanus.chao
 * removed!
 * .
 *
 * 10 31 2011 dior.lin
 * removed!
 * Update I2S buffer size.
 *
 *******************************************************************************/
#ifndef AM_H
#define AM_H

#include "l1aud_common_def.h"
#include "sal_def.h"

#define  ASP_TYPE_VOICE       0

#define  ASP_FS_8K            0x00
#define  ASP_FS_11K           0x11
#define  ASP_FS_12K           0x12
#define  ASP_FS_16K           0x20
#define  ASP_FS_22K           0x21
#define  ASP_FS_24K           0x22
#define  ASP_FS_32K           0x40
#define  ASP_FS_44K           0x41
#define  ASP_FS_48K           0x42

typedef enum{
   AM_RECORD_NONE = 0, 
   AM_RECORD_8K,
   AM_RECORD_16K
}AM_RECORD_FORMAT; 

void     AM_Init( void );
void     AM_SetDSP2GReset(bool v);
//bool     AM_AudioManager( bool handover,uint16 speech_mode, int8 sub_channel );
//void     AM_AudioManager_OS_Tick( void );
void     AM_FlushQFunction( void );
void     AM_FillSilencePattern( volatile uint16 *addr, uint16 info, uint16 speech_mode );
void     AM_FillSilencePatternInBuffer( uint16 *buffer, uint16 speech_mode );
uint16   AM_GetSpeechPatternLength( uint8 speech_mode );
bool     AM_CodecMode_IsLegal(uint8 codec_mode);
void     AM_SpeechOn(uint32 rat_mode, uint32 extraInfo);
void     AM_SpeechOff( uint32 info );
bool     AM_IsSpeechOn( void );
void     AM_SetDAIMode ( uint8 mode );
bool     AM_IsDAIMode( void );
void     AM_WriteFirCoeffs( const int16 *in_coeff, const int16 *out_coeff );
void AM_WriteWbFirCoeffs( const int16 wb_in_coeff[90], const int16 wb_out_coeff[90] );
void     AM_VMRecordOn( uint16 speech_mode );
void     AM_VMRecordOff( void );
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void     AM_KeyToneOn( void );
void     AM_KeyToneOff( void );
void     AM_ToneOn( void );
void     AM_ToneOff( void );
void     AM_PCM8K_PlaybackOn( void );
void     AM_PCM8K_PlaybackOff( bool wait );
void     AM_PCM16K_PlaybackOn( void );       /* PCM16K is for MT6205B only */
void     AM_PCM16K_PlaybackOff( bool wait );

uint32   AM_GetRecordFormat(void);
typedef enum{
   AM_PCM8KREC_APP_TYPE_PCMREC = 0,
   AM_PCM8KREC_APP_TYPE_VMEPL,
}AM_PCM8KREC_APP_TYPE; 

void     AM_PCM8K_RecordOn( AM_PCM8KREC_APP_TYPE appType );
void     AM_PCM8K_RecordOff( bool wait, AM_PCM8KREC_APP_TYPE appType );
void     AM_PCM16K_RecordOn( void );         /*PCM16K recording support 6219 and latter version*/
void     AM_PCM16K_RecordOff( bool wait );
bool     AM_IsVMPlaybackOn( void );
void     AM_VRRecordOn( uint32 trainPhase );
void     AM_VRRecordOff( uint32 trainPhase );
bool     AM_IsULSpeechMuted( void );
void     AM_Mute_UL_EnhResult_Speech(bool mute);
void     AM_Mute_UL_Source_Speech(bool mute);
void     AM_Mute_UL_Codec_Speech( bool mute );
void     AM_Mute_DL_8K_Speech( bool mute );
void     AM_Mute_DL_Speech_Traffic( bool mute );

// PCMNWAY function inside AM 
typedef enum {
	AM_PCMEX_TYPE_DEDICATION = 0, // under call
//	AM_PCMEX_TYPE_IDLE_WO_ENH, // without call, voice path, no enhancement
	AM_PCMEX_TYPE_IDLE, // without call, speech quality like, with enhancement
	AM_PCMEX_TYPE_REC_ONLY_CAL,  // record only DMNR calibration
	AM_PCMEX_TYPE_REC_PLAY_CAL,  // rec&play DMNR calibration
	AM_PCMEX_TYPE_DACA_DEDICATION,  // data card under call (speech on)
	AM_PCMEX_TYPE_DACA_IDLE_WO_ENH, // data card without call, voice path, no enhancement 
	AM_PCMEX_TYPE_DACA_IDLE, // data card without call, speech quality like, with enhancement

	AM_PCMEX_TYPE_UNDEF = 0xffff,
} AM_PCMEX_TYPE;

void     AM_PCM_EX_On( AM_PCMEX_TYPE type, uint32 cfg_ptr);
void     AM_PCM_EX_Off( AM_PCMEX_TYPE type, uint32 cfg_ptr);
bool     AM_IsVoIPOn( void );
bool     AM_IsConflictState( void );
bool     AM_IsKeyToneOn( void );
bool     AM_IsToneOn( void );
bool     AM_IsVoiceOn( void );

// PCM router control function
void AM_PcmRouter_On(void);
void AM_PcmRouter_Off(void);

// [Phase out] PCM path control functions, defualt is 16k PCM, so we don't need to open it. 
// void     AM_PCM_Mode_Off(void);
// void     AM_PCM_Mode_On(kal_uint16 data);
// kal_bool AM_IsPcmModeOn( void );

// Bluetooth earphone control functions
void     AM_BluetoothOn( uint8 bt_mode);
void     AM_BluetoothOff( void );
bool     AM_IsBluetoothOn( void );
bool     AM_IsBTCordlessMode( void );

// Bluetooth cordkess mode control functions
void     AM_BTCordlessOn( void );
void     AM_BTCordlessOff( void );

// Sound effect control functions
void     AM_SND_PlaybackOn( void );
void     AM_SND_PlaybackOff( bool wait );

// Functions for modem loopback test 
void     AM_SetLoopBackTest( bool enable );
bool     AM_IsLoopBackTest( void );

void     AM_EnableToneLoopBackFlag( kal_bool param );

// network information
void     AM_SetSpeechMode( uint16 speech_mode, int8 sub_channel );
uint16   AM_GetSpeechMode(void);
bool     AM_IsSpeechWB( void );
uint32   AM_GetNetworkRate( void );

// InterRAT
void     AM_InterRAT_3G_to_2G( void );
void     AM_InterRAT_4G_to_2G();

void     AM_InterRAT_2G_to_3G( kal_uint32 codec );
void     AM_3G_INTRARAT(kal_uint32 codec);
void     AM_InterRAT_4G_to_3G(uint32 codec
);
void     AM_InterRAT_2G_to_4G(uint32 codec);
void     AM_InterRAT_3G_to_4G(uint32 codec);
void     AM_4G_INTRARAT(kal_uint32 codec);
kal_bool AM_Is_4G();

//block filter run time switch function, used in sp_enhance.c
void     AM_SwitchCompFilter( kal_uint16 par );
//block filter turn on/off
void     AM_TurnOnBlockFilter( void );
void     AM_TurnOffBlockFilter( void );


bool     AM_IsAmInSpeechState( void );


bool     AM_IsDataCardOn( void );

// sw digital gain related
void AM_DSP_SetAudioDigitalGain(kal_uint16 digitalVol);
kal_uint16 AM_DSP_GetAudioDigitalGain(void);
void AM_DSP_SetSpeechDigitalGain(kal_uint16 digitalVol);
kal_uint16 AM_DSP_GetSpeechDigitalGain(void);
void AM_DSP_SetSpeechUplinkDigitalGain(kal_uint16 digitalVol);
kal_uint16 AM_DSP_GetSpeechUplinkDigitalGain(void);
void AM_DSP_SetSpeechUplinkSwAgcGain(kal_uint16 digitalVol);
kal_uint16 AM_GetSpeechEnhRefDigitalGain(void);
void AM_DSP_SetSpeechEnhRefDigitalGain(kal_uint16 digitalVol);

// dsp filter/enhancement parameter/coefficient related
void AM_SetNotchFilterParam(int16 *param);
void AM_DSP_WriteNotchFilterParam(void);

int16 AM_IsAudioPlaybackOn( void );
uint16 AM_GetSpeechMode( void );

void AM_SetBlockMED( uint32 RAT, bool b, uint32 pos );
void AM_Set2GCodecInfo(uint16 speech_mode, int8 sub_channel);

void addDlIrqCnt(void);
uint32 getDlIrqCnt(void);
void addUlIrqCnt(void);
uint32 getUlIrqCnt(void);

#endif


