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
 *
 * Filename:
 * ---------
 * am.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Audio Manager(AM) for Audio Mode Changes
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.152  $
 * $Modtime:   Aug 17 2005 11:17:12  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1audio/am.c-arc  $
 *
 * 03 05 2020 chengyang.wu
 * [MOLY00503206] [Rosa][BSP+][Q0] HD icon not shown on MT WFC call from RJIL network
 * 	
 * 	.
 *
 * 08 15 2017 ting-ni.chen
 * [MOLY00270553] 177420 �i��Z??�j�i?�X�j�j?�X�j���p�A??�A??�A�d?�B��???
 * 	
 * 	Fix HR pattern length bug.
 *
 * 08 15 2017 ting-ni.chen
 * [MOLY00270553] 177420 �i��Z??�j�i?�X�j�j?�X�j���p�A??�A??�A�d?�B��???
 * Fix HR pattern length bug.
 *
 * 07 05 2016 ting-ni.chen
 * [MOLY00188920] [cx880]MO�G�d1 ?�H�A MT�G�d1 ��? �d2 ��?�]4G Volte�^�A��?mtklog�Avmlog�A�I�}log�AMO��MT�d1�A���w??��??
 * OD lock sleep mode
 *
 * 05 11 2016 thomas.chen
 * [MOLY00177679] [CU Pre-test][�y��Z180][MT6750][?4G][�Ĥ@?�N��??]???���q??���Z��??�毶??���q?�A���q?MT��??���M?��HD??
 * 	
 * 	.
 *
 * 05 05 2016 fu-shing.ju
 * [MOLY00174395] [EVS] Speech Driver
 * EVS Speech Driver.
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
 * 02 25 2016 ys.hsieh
 * [MOLY00164966] 4G_G.711 speech driver porting
 * 4G_G.711 speech driver porting (W1603)
 *
 * 01 13 2016 ting-ni.chen
 * [MOLY00147644] [Everest][AP][SCP] workaround check-in on MD branch
 * [OpenDSP] Patch back
 *
 * 11 12 2015 sheila.chen
 * [MOLY00149073] [Need Patch] [Volunteer Patch] HD voice for WWOP
 * HD Voice.
 *
 * 11 09 2015 miyavi.tsai
 * [MOLY00148424] add  complier option in CCCI control flow for open dsp project
 * .
 *
 * 11 04 2015 thomas.chen
 * [MOLY00147759] sphdrv logging trace reduction
 * .
 *
 * 10 23 2015 ting-ni.chen
 * [MOLY00146582] [Jade] Speech Phase in SRC Plus
 * SPE.
 *
 * 09 07 2015 ting-ni.chen
 * [MOLY00140775] [MT6755][E2][FT][TDD][CA pre-Scout FT][NJ][Overnight](MCU_PCORE)[ASSERT] file:pcore/driver/audio/src/v1/am.c line:1477
 * [MT6755][E2][FT][TDD][CA pre-Scout FT][NJ][Overnight](MCU_PCORE)[ASSERT]
 *
 * 09 01 2015 miyavi.tsai
 * [MOLY00139885] [UMOLY] fix LR11 build warnings
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
 * 05 29 2015 ys.hsieh
 * [MOLY00093009] [FOCUS ISSUE][K2][CMCC][DSDS][VoLTE][Sanity][HZ][EE] file:m12100.c line:12374
 * 	UMOLY trunk patch back TOD NB + WB
 *
 * 05 21 2015 thomas.chen
 * [MOLY00115122] [UMOLY Round 2][Klocwork] in //UMOLY_CBr/peng-an.chen/UMOLY_KW.Round2/mcu/pcore/driver/audio/src/v1/am.c, line 2070
 * .
 *
 * 04 17 2015 ting-ni.chen
 * [MOLY00108052] [TK6291E1][Overnight][FDD][HK Office] Assert fail: am.c 138 - AUDL
 * kal_sleep_task
 *
 * 04 16 2015 thomas.chen
 * [MOLY00107860] L1D Resync
 * .
 *
 * 04 08 2015 sungshen.wu
 * [MOLY00106375] [TK6291E1][Overnight][FDD]Assert fail: am.c 197 - (LISR)CTIRQ1
 * .CRIRQ sends 2 handover, and lcore process too slow cause assert on second handover.
 *
 * 04 07 2015 fu-shing.ju
 * [MOLY00091627] TK6291 development
 * Add VoLTE code.
 *
 * 03 27 2015 thomas.chen
 * [MOLY00104508] 3G Call Patch
 * .
 *
 * 03 26 2015 thomas.chen
 * [MOLY00104367] TK6291 2G phonecall patch
 *
 * 03 26 2015 thomas.chen
 * [MOLY00104367] TK6291 2G phonecall patch
 * .
 *
 * 02 26 2015 che-jui.chang
 * [MOLY00097052] [UMOLY][Speech]Timer tick macro modification
 *
 * 02 06 2015 thomas.chen
 * [MOLY00095040] [MOLY][UBIN][Sanity] 4G CSFB fatal error - UL2D_FDD CSR
 * .
 *
 * 02 03 2015 fu-shing.ju
 * [MOLY00091627] TK6291 development
 * Sync Audio driver with MOLY TRUNK W15.05.P1.
 *
 * 05 02 2014 sheila.chen
 * [MOLY00061869] [UMoly] check-in
 * .
 *
 * 02 12 2014 sheila.chen
 * [MOLY00050441] [MT6595 Bring-Up] speech related code
 * 95 ENH Basic
 *  	
 * 	Merging
 *  	
 * 	//MOLY_CBr/sheila.chen/MOLY_95It/mcu/driver/audio/src/...
 *  	
 * 	to //MOLY/TRUNK/MOLY/mcu/driver/audio/src/...
 *
 * 01 13 2014 thomas.chen
 * [MOLY00053440] [MT6582LTE][IMS][VOLTE] VoLTE Data Plan Feature In
 * .
 *
 * 01 13 2014 thomas.chen
 * [MOLY00053440] [MT6582LTE][IMS][VOLTE] VoLTE Data Plan Feature In
 * .
 *
 * 12 26 2013 thomas.chen
 * [MOLY00051708] SMR support
 * .
 *
 * 12 09 2013 lanus.chao
 * [MOLY00046252] Add  MT6595 chip option
 * .
 *
 * 10 28 2013 thomas.chen
 * [MOLY00043994] In VT call without receiving ESPEECH:1, the speech driver cannot playback the sound from the network. In addtion, without receiving ESPEECH:1,  the acousticloopback should work well as before
 * .
 *
 * 10 28 2013 thomas.chen
 * [MOLY00043947] Remove EES_ENABLE in speech driver
 * .
 *
 * 10 08 2013 thomas.chen
 * [MOLY00040462] [Volunteer Patch]the speech driver supports TCH_Notify even in 2G only project
 * .
 *
 * 10 01 2013 thomas.chen
 * [MOLY00038820] Add L4C Event interface
 * .
 *
 * 08 13 2013 sheila.chen
 * [MOLY00011218] [MT6290] Code modification
 * remove unused define
 *
 * 08 05 2013 sheila.chen
 * [MOLY00011218] [MT6290] Code modification
 * remove unused afe code
 *
 * 07 22 2013 sheila.chen
 * [MOLY00028293] [MT6280] Super Dongle Integration
 * super dongle merge back
 * 1. pcm start volume
 * 2. fix src coefficient by DSP's request
 * 3. fix bgSnd timer name
 * 4. WB parameter position adding (80) [Rimind to ask 90]
 * 5. fix build warning
 * 6. when bt cordless mode fors
 * 7. add daca interface
 * 8. fix spc log typo
 *
 * 07 11 2013 sheila.chen
 * [MOLY00026590] [Volunteer Patch][MT6582] Loudspeaker mode DMNR
 * loudSpk DMNR for ddload change
 *
 * 06 25 2013 thomas.chen
 * [MOLY00023049] [Volunteer Patch] L1Audio phase in Speech-Modem-Resync for Fixed-AFC
 * .
 *
 * 05 14 2013 sheila.chen
 * [MOLY00022118] [Volunteer Patch] DRC2.0 (MagiLoudness) Integration
 * DRC 2.0 modification
 *
 * 05 13 2013 thomas.chen
 * [MOLY00022315] When switch on/off BT mode, default 3G codec setting  depends on current network
 * .
 *
 * 05 03 2013 sheila.chen
 * [MOLY00008234] [MT6572/MT6582] Integration
 * 3-in-1 speaker interface
 *
 * 04 26 2013 sheila.chen
 * [MOLY00020824] [MT6589][EE] Assert fail: spc_io.c 424 - DRVHISR
 * prevent enqueue 2g speech on preempt by L1D CTIRQ
 *
 * 04 24 2013 sheila.chen
 * [MOLY00020692] [Rose][Free Test][EE][md1]The "EE" about "md1" pops up after we tap "Add" and wait 2 seconds.
 * remove trace
 *
 * 04 23 2013 sheila.chen
 * [MOLY00008234] [MT6572/MT6582] Integration
 * remove prompt trace
 *
 * 04 19 2013 thomas.chen
 * [MOLY00020343] [Side Effect][JB3][Call] Call 112 in mute status, it'll delay 10 seconds to hear the sound (5/5)
 * .
 *
 * 03 27 2013 thomas.chen
 * [MOLY00012413] [ALPS.JB2.MP.V1.9 Regression Test][JB2][Free test][VT call] After make MO VT call, it will show "Video call cannot be setup".(1/5)
 * .
 *
 * 03 20 2013 sheila.chen
 * [MOLY00008234] [MT6572/MT6582] Integration
 * Dynamic download change
 *
 * 03 20 2013 wayne.wang
 * [MOLY00002694] [SAL] Speech abstration layer phased in
 * SAL - merge back for MT6290
 *
 * 03 08 2013 sheila.chen
 * [MOLY00008234] [MT6572/MT6582] Integration
 * Lenovo's new feature for MT6582 & MT657
 *
 * 02 05 2013 sheila.chen
 * [MOLY00008234] [MT6572/MT6582] Integration
 * Provide Dynamic EPL, and vm recording for loopback
 *
 * 01 28 2013 thomas.chen
 * [MOLY00009486] Add Resync log for 3g call and update M delay
 * .
 *
 * 01 25 2013 sheila.chen
 * [MOLY00009423] Idel record, AGC is close.
 * when idle VM record and 16k record, AGC should be open
 *
 * 01 24 2013 sheila.chen
 * [MOLY00009310] DL volume is incorrectly set under idle pcmnway begin
 * Fix bug that DL gain is fix under idle pcmNway
 *
 * 01 18 2013 sheila.chen
 * [MOLY00008440] [MT6589] Disable AGC under BT mode
 * Move AGC from hw to enhancement to fix the AGC incorrectly open under BT mode
 *
 * 01 09 2013 sheila.chen
 * [MOLY00008584] [Need Patch] [Sanity Fail][EE][ASSERT] file:vm.c line:539 happen when end VT call
 * Init PCMEX setting local variable
 *
 * 01 08 2013 sheila.chen
 * [MOLY00008474] [MT6589] Fix 8k control bug when device switch
 * set mode bug fix
 *
 * 12 18 2012 sheila.chen
 * [MOLY00007673] [P188T10_ DVT1][MT6589][CMCC Case][FT][Nanjing][2.1][M]_��59?_13:42:46_����q???��_B����
 * Add sherif mute check. 
 * Move the mute position after SAL_SPH_CALL_ON
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
 * 11 29 2012 wayne.wang
 * [MOLY00002694] [SAL] Speech abstration layer phased in
 * .
 *
 * 11 20 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * 1. Idel VM with EPL bug fix
 * 
 * 2. Warnming Remove
 * 
 * 3. Dynamic feed in the enhancment parameter
 *
 * 11 15 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * fix p4w potential bug
 *
 * 11 08 2012 sheila.chen
 * [MOLY00005929] [Pre-SQC1][Blocking][TE][Call]Mute not work for the call
 * Mute function implement
 *
 * 11 08 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * reload function for Fir check-in error
 *
 * 11 07 2012 sheila.chen
 * [MOLY00005853] [MT6589_EVB2][Lab test][Beijing][8470_23G]Assert fail: afe_common.c 739 - AUDIO
 * sync the am path usage
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
 * 11 01 2012 jy.huang
 * [MOLY00000755] Check in 3G speech delay improvement(phase1+3)
 * .
 *
 * 10 31 2012 jy.huang
 * [MOLY00000755] Check in 3G speech delay improvement(phase1+3)
 * .
 *
 * 10 31 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Fix WB FIR over write NB FIR
 *
 * 10 29 2012 jy.huang
 * [MOLY00000755] Check in 3G speech delay improvement(phase1+3)
 * .
 * 
 * 10 23 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * WB FIR coefficient
 *  settubg
 * 
 * 10 22 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * DMNR coefficient setting
 * 
 * 10 17 2012 wayne.wang
 * [MOLY00002694] [SAL] Speech abstration layer phased in
 * SAL - epl plus the refmic logging
 * 
 * 10 16 2012 wayne.wang
 * [MOLY00002694] [SAL] Speech abstration layer phased in
 * SAL - vm and epl record
 * 
 * 10 08 2012 wayne.wang
 * [MOLY00002694] [SAL] Speech abstration layer phased in
 * SAL - pcm record
 * 
 * 10 08 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * MT6589 phone call setting merge back
 * 
 * 10 08 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * fix voip error usage in pcm4way
 * 
 * 09 25 2012 thomas.chen
 * [MOLY00004111] Integrate the PNW and DACA interface with SAL
 * .
 * 
 * 09 20 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * add compile option for analog AFE
 * 
 * 09 14 2012 thomas.chen
 * [MOLY00003558] [MT6280][WW FT][HK][CSL][3G_DM][TTL] Assert fail: vm.c 1378 0x0 0x0 0x0 - L1Audio
 * .
 * 
 * 09 11 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Phase in call PCM record and EPL record in the same time
 * 
 * 09 10 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Phase-in VM/VOC basic
 * 
 * 09 10 2012 wayne.wang
 * [MOLY00002694] [SAL] Speech abstration layer phased in
 * SAL- 3g data path
 * 
 * 09 06 2012 wayne.wang
 * [MOLY00002694] [SAL] Speech abstration layer phased in
 * SAL - speech enhacnement and dsp speech init
 * 
 * 08 29 2012 wayne.wang
 * [MOLY00002694] [SAL] Speech abstration layer phased in
 * SAL phase in
 * 
 * 08 27 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * .
 * 
 * 08 22 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Integration change.
 *  
 * Add background sound modem reset handling
 * Temp remove bgs capability in MD side.
 * 
 * 08 21 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Phase in background sound and SAL
 * 
 * 07 30 2012 thomas.chen
 * [MOLY00001393] Fix build Error
 * .
 * 
 * 07 30 2012 thomas.chen
 * [MOLY00001376] Update L1D_ENABLE_DTIRQ protection
 * .
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
 * 07 13 2012 jy.huang
 * [MOLY00000755] Check in 3G speech delay improvement(phase1+3)
 * .
 *
 * 07 10 2012 thomas.chen
 * [MOLY00000332] [Blocking Issue][pre-SQC][MT6280][India FT][Chandigarh][3GSM][Aircel] Assert fail sp_3g.c 1435 - UL2D
 * .
 *
 * 07 10 2012 sheila.chen
 * [MOLY00000332] [Blocking Issue][pre-SQC][MT6280][India FT][Chandigarh][3GSM][Aircel] Assert fail sp_3g.c 1435 - UL2D
 * Help to check-in.
 *
 * 06 08 2012 kh.hung
 * removed!
 * .
 *
 * 06 05 2012 li.yu
 * removed!
 * Add trace for 2G re-sync
 *
 * 05 25 2012 yicheng.pan
 * removed!
 * 2G resync Threshold API.
 *
 * 05 21 2012 sheila.chen
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
 * 04 02 2012 thomas.chen
 * removed!
 * .
 *
 *
 *******************************************************************************/
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "md2g_drv.h"
#include "string.h"

#include "media.h"
#include "l1audio_trace.h"
#include "audio_def.h"
#include "l1audio.h"
#include "afe.h"
#include "ddload.h"
#include "am.h"
#include "l1aud_common_def.h"
#include "speech_def.h"
#include "afe_def.h"
#if defined(__BT_SUPPORT__)
#include "bt_api.h"
#endif
#include "sp_daca.h"
#include "pcm4way.h"
#include "sp_enhance.h"

#include "sal_def.h"
#include "sal_exp.h"
#include "sal_impl.h"
#include "sp_cc.h"

#include "us_timer.h"

#include "sp_drv.h"

//#define TK6291_FAKE_COMPILE

#define __BT_SUPPORT__
#define AM_RECORD_SLEEP_TICK 40

#define  TQ_WRAP_COUNT                       5000

#define AM_2G_RESYNC_THRESHOLD  1083
/* ========================================================================= */
uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );
bool is_EVS_codec(uint8 codec);
void EVS_encoder_clean(void);
void EVS_decoder_clean(void);

/* ========================================================================= */
#define  AM_STATE_KEYTONE  (1<<L1SP_KEYTONE  )
#define  AM_STATE_TONE     (1<<L1SP_TONE     )
#define  AM_STATE_SPEECH   (1<<L1SP_SPEECH   )
#define  AM_STATE_VOIP   (1<<(L1SP_MAX_AUDIO+0)   )
#define  AM_STATE_VOICE    (1<<L1SP_VOICE    )
#define  AM_STATE_DAI      (1<<L1SP_DAI      )
#define  AM_STATE_AUDIO    (1<<L1SP_AUDIO  )
#define  AM_STATE_SND_EFFECT  (1<<L1SP_SND_EFFECT)
#define  AM_STATE_AvBT     (1 << (L1SP_MAX_AUDIO + 1))
#define  AM_STATE_AVSYNC   (1 << (L1SP_MAX_AUDIO + 2))
#define  AM_STATE_DACA     (1 << (L1SP_MAX_AUDIO + 3))

#define AM_CONFLICT_STATE (AM_STATE_SPEECH + AM_STATE_VOIP + AM_STATE_VOICE + AM_STATE_AUDIO) 

/*========  Speech State : record features in dedicated-mode speech  ========= */
#define SP_STATE_VMR          (1 << 0)
#define SP_STATE_PCM8K_REC    (1 << 1)
#define SP_STATE_PCMNWAY      (1 << 2)
#define SP_STATE_DACA         (1 << 3)
#define SP_STATE_VMR_EPL      (1 << 4)  // VM record with EPL

/*========  VoIP State ======================================= */    
#define VOIP_STATE_VMR          (1 << 0)

#define VOIP_STATE_REC_ONLY_CAL (1 << 1)
#define VOIP_STATE_REC_PLAY_CAL (1 << 2)


/*=============  DSP&AFE IO types  ============================ */
#define NORMAL_MODE        0
#define DAI_MODE           1
#define BT_CORDLESS_MODE   2
#define BT_EARPHONE_MODE   3
#define PCM_MODE           4

/*============= low byte flags of *DP_AUDIO_PAR ============================ */
#define VOICE_INPUT_FILTER_FLAG     0x1
#define VOICE_OUTPUT_FILTER_FLAG    0x2
#define VOICE_WB_AMR_FLAG           0x8
#define VOICE_16K_SWITCH_FLAG       0x10
#define VOICE_MIC_MUTE_FLAG         0x20
#define VOICE_SIDETONE_FILTER_FLAG  0


#define  DSP_IO4_On()         { *SHARE2_D2MCON |= 0x10;  }
#define  DSP_IO5_On()         { *SHARE2_D2MCON |= 0x20;  }
#define  DSP_IO6_On()         { *SHARE2_D2MCON |= 0x40;  }
#define  DSP_IO7_On()         { *SHARE2_D2MCON |= 0x80;  }

/* ========================================================================= */

/* To work around the bug of DSP when handover in short time,
   Do not set handover flag to DSP, but VBI_Reset and other setting remain */
#define NOT_HANDOVER_IN_SHORT_TIME

#define  VBI_Reset()          { *SHARE2_M2DI1 = 0x0838; \
                                L1Audio_Msg_VBI_RESET(); }
#define  VBI_End()            { *SHARE2_M2DI1 = 0x0839; \
                                L1Audio_Msg_VBI_END(); }

/* =========== Block Filter Switch Between old/New Usage===================== */
volatile kal_uint16 *g_Compen_Blk_Flt;

typedef struct {
   void     (*code)(uint32, uint32);
   uint32   data;
	uint32   data2;
} AM_QFunction;

static struct {
#if defined( NOT_HANDOVER_IN_SHORT_TIME )
   uint32    l1FN_HO;
#endif
   uint16   state;
   uint16   speech_mode;
   uint16   ul_speech_mode; //behavior is the same as 3/4G
   int16    speech_off_delay;
   int8     sub_channel;
   int8     ul_sub_channel; //behavior is the same as 3/4G

	uint16  audioDigitalGain;
	uint16  speechDigitalGain;
	uint16  speechUplinkDigitalGain;
	uint16  speechUplinkSwAgcGain;
	uint16  speechDlEnhRefDigtalGain;
#if defined(__BT_SUPPORT__)
   uint16  bt_digital_gain; // temporary value for keeping origial dl volume in other mode
   // uint16  bt_mic_gain; // temporary value for keeping origial up volume in other mode
   // uint16  bt_dlEnhRef_digital_gain; // temporary  value for keeping origial dl enhancement reference volum in the other mode
#endif

   RINGBUFFER_T(AM_QFunction,8) qfunc;
#if __SP3G_PLATFORM__
   RINGBUFFER_T(AM_QFunction,8) qfunc2;   // modem-unrelated
#endif

   uint8    speech_state;
   uint8	voip_state;   
   uint8    io_type;
	
   bool     fLoopBack;
   kal_bool pre_isWBLink;
	 kal_bool needBlockMED_3G;
	 kal_bool needBlockMED_4G;
	bool     isFirCoeffSet; 
// #if __RELOAD_DSP_COEFF__
   int16    in_coeff_tmp[45];
   int16    out_coeff_tmp[45];
	int16    wb_in_coeff_tmp[90];
	int16    wb_out_coeff_tmp[90];
// #endif
   bool     toneLoopbackRec;
   bool     sp3g_flag;
#if defined(__VOLTE_SUPPORT__)
   bool     sp4g_flag;
   int      codec_4g;
#endif
   
   AM_RECORD_FORMAT record_format;
   bool     dsp_2g_reset;
} am;

//#if defined(__VOLTE_SUPPORT__)
//#define IsWBLink(speech_codec) (SP4G_CODEC_G722 == speech_codec ) || ((speech_codec >= 0x20) && (speech_codec <= 0x28)) || ( (SP4G_CODEC_EVS_16K_005_9 <= speech_codec) && (SP4G_CODEC_EVS_16K_128_0 >= speech_codec) ) || ( (SP4G_CODEC_EVS_AWB_06_60 <= codec) && (SP4G_CODEC_EVS_AWB_23_85 >= codec) )
//#else
//#define IsWBLink(speech_codec) ((speech_codec) >= 0x20)
//#endif

// void AM_DSP_SetSRCCtrl( uint32 data, uint32 extraInfo );
/* --------------------------------------------------------------------------*/
void SP4G_Call_Close();
void SP4G_Call_Open(uint16 codec);
kal_uint32 SP4G_GetCodecMode(void);

extern kal_uint8 AFE_GetAfeSate(void);

// #if __RELOAD_DSP_COEFF__
static void AM_ReloadDSPCoefficient( void );
// #endif

static void AM_Enqueue( void (*code)(uint32, uint32), uint32 data, uint32 data2, bool isCritical )
{
   //uint32 savedMask;

// #if __RELOAD_DSP_COEFF__
   /* For 65nm process, MCU has to reload DSP coefficient at each wake-up */
   if (am.state == 0){
   	  DSP_IO4_On();
      DSP_IO5_On();      
      DSP_IO6_On();      
      DSP_IO7_On();
      AM_ReloadDSPCoefficient();
    }

  code( data , data2 );
}

/* --------------------------------------------------------------------------*/
#define AM_WriteAspParam(asp_type,asp_fs,del_w,del_m)             \
{                                                                 \
   *DP_ASP_TYPE    = asp_type;                                    \
   *DP_ASP_FS      = asp_fs;                                      \
   *DP_ASP_DEL_W   = del_w;                                       \
   *DP_ASP_DEL_M   = del_m;                                       \
   DSP_TONE_FORCE_KT_8K = 0x8000;                                 \
}

/* --------------------------------------------------------------------------*/

#define AM_WriteSpeechParameters( sc_flags, sc_mode, sd_mode )    \
{                                                                 \
   *DP_SC_MODE          = sd_mode | (sc_mode << 8);               \
   *DP_SC_VAD           = (sc_mode>2)? 1:0;                       \
   *DP_SC_FLAGS         = sc_flags;                               \
}

/* ========================================================================= */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

/*....................................*/

#ifdef  L1D_TEST
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif

/*....................................*/
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
#endif
/*....................................*/

#ifdef  L1D_TEST
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
#endif
#endif

#ifdef __HQA_AUDIO__
const int16 Speech_All_Pass_FIR_Coeff[45] =
   { /* All pass filter */
    32767,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0
   };
#endif

/*
// phase out, move into SAL
static void AM_Write_Speech_Delay( uint16 speech_mode, int8 sub_channel, uint16 delay )
{
   uint16 n = (uint16)L1D_GetT2();

   if( n >= 13 )
      n -= 13;
   //MT6280, wayne, what is this for?? the speech mode num should be 3+8+9=20
   if (speech_mode>=0x20)
      speech_mode-=(0x20-0x0B);

   ASSERT(speech_mode<(sizeof(DSP_PCM_MARGIN_TABLE)/sizeof(DSP_PCM_MARGIN_TABLE[0])));
#ifdef L1D_TEST
   if((PollLoopbackMode()==1)||(PollLoopbackMode()==2))
   {
      if ( speech_mode < 0x0B )
      {
         *DP_DEL_PCM_R     = DSP_PCM_DELAY_TABLE2[n][0];
         *DP_DEL_PCM_W     = DSP_PCM_DELAY_TABLE2[n][1];
      }
      else
      {
         *DP_DEL_PCM_R     = DSP_WB_AMR_PCM_DELAY_TABLE2[n][0];
         *DP_DEL_PCM_W     = DSP_WB_AMR_PCM_DELAY_TABLE2[n][1];
      }
      *DP_MARGIN_VBIPCM_W  = DSP_PCM_MARGIN_TABLE2[speech_mode];
   }
   else
#endif
   {
      if (sub_channel == 0)
      {
         *DP_DEL_PCM_R     = DSP_PCM_DELAY_TABLE_SUBCH0[n][0];
         *DP_DEL_PCM_W     = DSP_PCM_DELAY_TABLE_SUBCH0[n][1];
      }
      else
      {
         *DP_DEL_PCM_R     = DSP_PCM_DELAY_TABLE_SUBCH1[n][0];
         *DP_DEL_PCM_W     = DSP_PCM_DELAY_TABLE_SUBCH1[n][1];
         n += 13;
      }
      L1Audio_Msg_AM_DELAY_TABLE( n );
      *DP_MARGIN_VBIPCM_W  = DSP_PCM_MARGIN_TABLE[speech_mode];
   }
   *DP_SC_EVLUATE_DELAY = delay;
}
*/

const  uint16  DSP_PCM_IDLE_DELAY_TABLE[7][3] =
{
   { 0x20, 0x20 , 0x4B+(16<<10)+(2<<8)}, // for AMR codec
   { 0x20, 0x20 , 0x96+(16<<10)+(2<<8)}, // for speech codec except AMR
   { 0x0A, 0x0A , 0x4F+(16<<10)+(2<<8)}, // for PCM8K_Playback.....
   { 0x0A, 0x0A , 0x28+(16<<10)+(2<<8)}, // for PCM16K
   { 0x0A, 0x0A , 0x9F+(16<<10)+(2<<8)},  // for Keytone/Tone/
   { 0x0A, 0x0A , 0x96+(16<<10)+(2<<8)}, // for PCM8K_Playback/VoIP
   //{ 0x10, 0x100, 0x96+(16<<10)+(2<<8)}  // for 3G Speech
   { 27*8, 14*8, 0x20+(16<<10)+(2<<8)}  // for 3G Speech
};

static void AM_Write_Idle_Delay( uint8 type )
{
/*   *DP_DEL_PCM_R        = DSP_PCM_IDLE_DELAY_TABLE[type][0];
   *DP_DEL_PCM_W        = DSP_PCM_IDLE_DELAY_TABLE[type][1];
   *DP_MARGIN_VBIPCM_W  = DSP_PCM_IDLE_DELAY_TABLE[type][2];
   *DP_SC_EVLUATE_DELAY = 0;*/
}


/* Note: The speech pattern length for amr-wb can be calculated from
lenSpeechBitsAMR_WB in amr_table.h; therefore, remove them out.
Those for amr might be removed if vm.c does not handle amr any more. */
static const uint8 SpeechPatternLength[] = {
   (uint8)((260 + 15) / 16),           /*  FR       */
   (uint8)((112 + 15) / 16),           /*  HR       */
   (uint8)((244 + 15) / 16),           /* EFR       */
   (uint8)((244 + 15) / 16),           /* AMR 12.2K */
   (uint8)((204 + 15) / 16),           /* AMR 10.2K */
   (uint8)((159 + 15) / 16),           /* AMR 7.95K */
   (uint8)((148 + 15) / 16),           /* AMR 7.4K  */
   (uint8)((134 + 15) / 16),           /* AMR 6.7K  */
   (uint8)((118 + 15) / 16),           /* AMR 5.9K  */
   (uint8)((103 + 15) / 16),           /* AMR 5.15K */
   (uint8)(( 95 + 15) / 16),           /* AMR 4.75K */
#if 1//#if defined(AMRWB_DECODE) || defined(__AMRWB_LINK_SUPPORT__)
   (uint8)((132 + 15) / 16),           /* AMR-WB 6.60  */
   (uint8)((177 + 15) / 16),           /* AMR-WB 8.85  */
   (uint8)((253 + 15) / 16),           /* AMR-WB 12.65 */
   (uint8)((285 + 15) / 16),           /* AMR-WB 14.25 */
   (uint8)((317 + 15) / 16),           /* AMR-WB 15.85 */
   (uint8)((365 + 15) / 16),           /* AMR-WB 18.25 */
   (uint8)((397 + 15) / 16),           /* AMR-WB 19.85 */
   (uint8)((461 + 15) / 16),           /* AMR-WB 23.05 */
   (uint8)((477 + 15) / 16),           /* AMR-WB 23.85 */
#endif
   (uint8)(9+2),                       /* EVS_AWB660   */
   (uint8)(12+2),                      /* EVS_AWB885   */
   (uint8)(16+2),                      /* EVS_AWB1265  */
   (uint8)(18+2),                      /* EVS_AWB1425  */
   (uint8)(20+2),                      /* EVS_AWB1585  */
   (uint8)(23+2),                      /* EVS_AWB1825  */
   (uint8)(25+2),                      /* EVS_AWB1985  */
   (uint8)(29+2),                      /* EVS_AWB2305  */
   (uint8)(30+2),                      /* EVS_AWB2385  */
   (uint8)(10+2),                      /* EVS_PRI590   */
   (uint8)(9+2),                       /* EVS_PRI720   */
   (uint8)(10+2),                      /* EVS_PRI800   */
   (uint8)(12+2),                      /* EVS_PRI960   */
   (uint8)(17+2),                      /* EVS_PRI1320  */
   (uint8)(21+2),                      /* EVS_PRI1640  */
   (uint8)(31+2),                      /* EVS_PRI2440  */
   (uint8)(40+2),                      /* EVS_PRI3200  */
   (uint8)(60+2),                      /* EVS_PRI4800  */
   (uint8)(80+2),                      /* EVS_PRI6400  */
   (uint8)(120+2),                     /* EVS_PRI9600  */
   (uint8)(160+2)                      /* EVS_PRI12800 */
};

bool AM_CodecMode_IsLegal(uint8 codec_mode)
{
   if (codec_mode <= 0xA) {
      return true;
   }
#if 1//#if defined(AMRWB_DECODE) || defined(__AMRWB_LINK_SUPPORT__)
   if ( (codec_mode >= 0x20) && (codec_mode <= 0x28) ) {
      return true;
   }
#endif
   return false;
}

uint16 AM_GetSpeechPatternLength( uint8 speech_mode )
{
   if((speech_mode >= 11) && (speech_mode <= 31))
   {
      speech_mode = speech_mode - 11 + 20;
   }
   else if( speech_mode >= 0x20 )
   {
      speech_mode = speech_mode - 0x20 + 0x0B;
   }
   if( speech_mode<(sizeof(SpeechPatternLength)/sizeof(SpeechPatternLength[0])))
      return (uint16)SpeechPatternLength[speech_mode];
   else
      return 0;
}
//Need to add new pattern for MT6280

static const uint16 SpeechSilencePattern[][31] = {
   {  0x4820,0xD617,0x0284,0x2480,0x9249,0x8924,0x8002,0x4924,       /* FR       */
      0x2492,0x0289,0x2480,0x9249,0x8924,0x8002,0x4924,0x2492,
      0x0009                                                   },
   {  0x4E20,0x875E,0x5473,0x8482,0x00E9,0x0000,0x0000         },    /* HR       */
   {  0x7A10,0x092D,0xB55F,0x7C06,0x185C,0xDE06,0x4230,0x0103,       /* EFR      */
      0xA012,0x001A,0x0000,0x0000,0x0D6C,0x0000,0x0000,0x0000  },
   {  0x00e2,0x5dfc,0xf095,0xcd4e,0x24da,0x0e04,0xf0fb,0x4f2e,       /* AMR12.2  */
      0x4430,0x9fa8,0x0319,0x56c0,0xc144,0x0278,0x70ea,0x0004  },
   {  0xe00a,0xf2e7,0x516b,0x19a1,0xc10d,0x145a,0x4c96,0x25e0,       /* AMR10.2  */
      0x5ce6,0x17b9,0x0982,0x225d,0x00c4                       },
   {  0x033c,0xe5cd,0xd9fb,0x387f,0x420c,0x8c99,0x58d7,0x1156,       /* AMR7.95  */
      0x397f,0x1074                                            },
   {  0xe00a,0xf2e7,0x9ac5,0x4433,0x185b,0x3e05,0xdc64,0xc886,       /* AMR7.4   */
      0xcd2e,0x0000                                            },
   {  0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,       /* AMR6.7   */
      0x0002                                                   },
   {  0xe00a,0xf2e7,0xb196,0xa8ae,0xbcb7,0x6fb9,0x0193,0x002e  },    /* AMR5.9   */
   {  0x3c0a,0x7e51,0x652c,0x5e91,0xd023,0xea5a,0x005b         },    /* AMR5.15  */
   {  0x3c0a,0x3e51,0x6529,0x3a49,0x977f,0x3565                },    /* AMR4.75  */
   {  0x1480,0x02ee,0xd706,0x09f4,0x4e01,0x2ada,0x59ef,0x2a20,0x0001  },    /* AMR-WB 6.60  */
   {  0x1290,0x0460,0x78f1,0xae42,0x2330,0x98c8,0x0120,0x57f8,0xa4b5,0xa681,0x25a0,0x0000  },     /* AMR-WB 8.85  */
   {  0x1290,0x0460,0x78f1,0x4142,0xc702,0x3f49,0xd446,0x7295,0x55c0,0x1028,0x7159,0xe315,0x96cf,0x8328,0x06a7,0x1f2c },     /* AMR-WB 12.65  */
   {  0x1290,0x0460,0x78f1,0x1542,0x8839,0x8c07,0x462d,0x59f4,0x3069,0x55c3,0x6028,0xa539,0x1724,0x2ebb,0xa182,0x92da,0xd156,0x1e06 },     /* AMR-WB 14.25  */
   {  0x1290,0x0460,0x78f1,0x1542,0x00b8,0xc095,0x381e,0xf446,0x6959,0x6870,0x5f5c,0xe028,0xb886,0x2724,0xcbb3,0x820b,0xcaa0,0x5692,0x6053,0x1c05 },     /* AMR-WB 15.85  */
   {  0x1290,0x0460,0x78f1,0xff42,0x0604,0xd0c8,0x8460,0x63e0,0x7b44,0xce75,0x3c14,0xea27,0x285d,0xf790,0x13eb,0xec97,0x5f93,0x28bb,0x2648,0x3b81,0x2de6,0x1529,0x1529 },     /* AMR-WB 18.25  */
   {  0x1290,0x0460,0x78f1,0x3942,0xf104,0x2b51,0x40cb,0xd864,0xc463,0x75ce,0x5d7d,0x3c8f,0xfa23,0x285d,0xd690,0xfa27,0xc515,0x93ea,0xbb5f,0x1e28,0xc5ea,0xfa2f,0x2c8c,0x45d8,0x1529 },     /* AMR-WB 19.85  */
   {  0x1290,0x0460,0x78f1,0x1742,0x2098,0xaa41,0x4330,0xb286,0xd023,0xc463,0x5ce6,0x6e55,0xe3d7,0x14ef,0xb10f,0x2017,0xf1e0,0xf68f,0x8735,0x1c66,0x5b22,0x3765,0xc86c,0xdb41,0x84d3,0x522a,0x8696,0xc4b6,0x1c2a },     /* AMR-WB 23.05  */
   {  0x1290,0x0460,0x78f1,0x1742,0x2098,0xaa41,0x4330,0xb286,0xd023,0x4f63,0xce6c,0x0555,0x5926,0x4c7e,0x1af1,0xc5df,0xe01e,0x2daf,0xdc74,0x56be,0xe4c0,0xf38a,0xa07a,0x5585,0x41fb,0x784d,0x932d,0x4798,0x914b,0x0f52 }     /* AMR-WB 27.85  */   
};

void AM_FillSilencePattern( volatile uint16 *addr, uint16 info, uint16 speech_mode )
{
#ifndef  L1D_TEST
   const uint16 *pat_info;
   uint32 I, len;
   if( speech_mode >= 0x20 )
      speech_mode = speech_mode - 0x20 + 0x0B;

   if( speech_mode >= (sizeof(SpeechPatternLength)/sizeof(SpeechPatternLength[0])) )
      return;

   pat_info = SpeechSilencePattern[speech_mode];
   len = (uint16)SpeechPatternLength[speech_mode];

   *addr++ = info;
   for( I = 0; I < len; I++ )
      *addr++ = *pat_info++;
#endif
}

void AM_FillSilencePatternInBuffer( uint16 *buffer, uint16 speech_mode )
{
#ifndef  L1D_TEST
   const uint16 *pat_info;
   uint32 I, len;
   if( speech_mode >= 0x20 )
      speech_mode = speech_mode - 0x20 + 0x0B;

   if( speech_mode >= (sizeof(SpeechPatternLength)/sizeof(SpeechPatternLength[0])) )
      return;

   pat_info = SpeechSilencePattern[speech_mode];
   len = (uint16)SpeechPatternLength[speech_mode];

   for( I = 0; I < len; I++ )
      *buffer++ = *pat_info++;
#endif
}

/* -------------------------------------------------------------------------- */
extern uint32 L1I_GetTimeStamp( void );

void AM_SetDSP2GReset(bool v)
{
	 am.dsp_2g_reset = v;
}

void AM_Set2GCodecInfo(uint16 speech_mode, int8 sub_channel)//
{
    am.ul_speech_mode = speech_mode;
    am.ul_sub_channel = sub_channel;
}

void AM_Get2GCodecInfo(uint16 *speech_mode, int8 *sub_channel)//
{
    *speech_mode = am.ul_speech_mode;
    *sub_channel = am.ul_sub_channel;
}

void AM_FlushQFunction( void )
{
#ifndef  L1D_TEST
   while( !RB_EMPTY(am.qfunc) )
      kal_sleep_task( AUD_1TICK(1) );
#endif
}

/* ========================================================================= */
/*   Interface Functions                                                     */
/* ========================================================================= */
// static uint8 audio_coeff_flag = 0; // move to am structure --> am.isFirCoeffSet
#define COMPEN_FILTER_SIZE 45

const signed short Sidetone_FIR[31] =
{
-4678, 11792,  407,  204,  407, -6978, 12257,  2929, -2945,  2929,
0, 0,  0,  0,  0, 0, 0,  0, 0,  0,
0, 0,  0,  0,  0, 0, 0,  0, 0,  0,
0
};

static void AM_WriteSidetoneFIR( void )
{
   int I;
   const int16 *ptr;
   volatile uint16* dsp_ptr;
   int coff_len;
   
   coff_len = SAL_FLTCOEFLEN_SIDETONE;

   /* Write audio FIR filter coeficients */
   ptr = Sidetone_FIR; //MT6280, wayne comeback to check this

  dsp_ptr = SAL_Sidetone_GetFltCoefAddr();
  
   for( I = coff_len; --I >= 0; )
      *dsp_ptr++ = *ptr++;
}

static void AM_WriteSpeechCompensationFilter( const int16 in_coeff[45], const int16 out_coeff[45] )
{
   int i;
   volatile uint16* dsp_ptr;

   /* Write audio FIR filter coeficients */
   dsp_ptr = SAL_BKF_GetFltCoefAddr_NB_UL(); 

   for( i=0; i<SAL_FLTCOEFLEN_BKF_NB; i++ )
#ifndef __HQA_AUDIO__
      *dsp_ptr ++ = *in_coeff++;
#else
      *dsp_ptr ++ = Speech_All_Pass_FIR_Coeff[i];
#endif

   dsp_ptr = SAL_BKF_GetFltCoefAddr_NB_DL(); 

   for( i=0; i<SAL_FLTCOEFLEN_BKF_NB; i++ )
#ifndef  __HQA_AUDIO__
      *dsp_ptr ++ = *out_coeff++;
#else
      *dsp_ptr ++ = Speech_All_Pass_FIR_Coeff[i];
#endif

}

void AM_WriteFirCoeffs( const int16 in_coeff[45], const int16 out_coeff[45] )
{
   if(am.toneLoopbackRec)
      return;

// #if __RELOAD_DSP_COEFF__
   memcpy(am.in_coeff_tmp, in_coeff, 45*sizeof(int16));
   memcpy(am.out_coeff_tmp, out_coeff, 45*sizeof(int16));
// #endif

   am.isFirCoeffSet= true;

   /* Write audio FIR filter coeficients */
   AM_WriteSpeechCompensationFilter(in_coeff, out_coeff);

   /* enable input/output filtering */
   SAL_BKF_Switch(true, true);

}

static void AM_WriteWbSpeechCompensationFilter( const int16 wb_in_coeff[90], const int16 wb_out_coeff[90] )
{
		int i;
		volatile uint16* dsp_ptr;
		
		
	   /* Write audio FIR filter coeficients */
	   dsp_ptr = SAL_BKF_GetFltCoefAddr_WB_UL(); 

	   for( i=0; i<SAL_FLTCOEFLEN_BKF_WB; i++ ){
#ifndef __HQA_AUDIO__
	      *dsp_ptr ++ = *wb_in_coeff++;
#else
			if(i<SAL_FLTCOEFLEN_BKF_NB){
		      *dsp_ptr ++ = Speech_All_Pass_FIR_Coeff[i];
			} else {
				*dsp_ptr ++ = 0;
			}
#endif
	   }
	   dsp_ptr = SAL_BKF_GetFltCoefAddr_WB_DL(); 

	   for( i=0; i<SAL_FLTCOEFLEN_BKF_WB; i++ )
#ifndef  __HQA_AUDIO__
	      *dsp_ptr ++ = *wb_out_coeff++;
#else
	      if(i<SAL_FLTCOEFLEN_BKF_NB){
		      *dsp_ptr ++ = Speech_All_Pass_FIR_Coeff[i];
			} else {
				*dsp_ptr ++ = 0;
			}
#endif

}
void AM_WriteWbFirCoeffs( const int16 wb_in_coeff[90], const int16 wb_out_coeff[90] )
{
	
// #if __RELOAD_DSP_COEFF__	
	memcpy(am.wb_in_coeff_tmp, wb_in_coeff, 90*sizeof(int16));
   memcpy(am.wb_out_coeff_tmp, wb_out_coeff, 90*sizeof(int16));
// #endif

	//write FIR coefiicient when some application is running. 
	// Otherwise, the coefficient will be reloaed under AM_Enqueue()
	if(am.state !=0) {
		AM_WriteWbSpeechCompensationFilter(am.wb_in_coeff_tmp, am.wb_out_coeff_tmp);
	}
}

// SRC coefiicient using in DSP
const signed short Audio_Flt_Coeff[82] =
{
     0,    96,   162,   -92,  -488,  -302,   408,   372,  -660,  -780,
   782,  1272,  -958, -2094,  1088,  3458, -1200, -6426,  1266, 20318,
 30834, 20318,  1266, -6426, -1200,  3458,  1088, -2094,  -958,  1272,
   782,  -780,  -660,   372,   408,  -302,  -488,   -92,   162,    96,
     0,  /* SRC Up-Sampling */
     0,     0,   -36,  -175,  -262,   -51,   277,   146,  -376,  -317,
   489,   595,  -597, -1034,   689,  1777,  -744, -3351,   727, 10500,
 15852, 10500,   727, -3351,  -744,  1777,   689, -1034,  -597,   595,
   489,  -317,  -376,   146,   277,   -51,  -262,  -175,   -36,     0,
     0  /* SRC Down-Sampling */
};
const signed short Sph_SRCPlus_Flt_Coeff[75] =
{
 50, 163, 186, 27, -141, -49, 157, 87, -185, -143, 211,
218, -233, -313, 243, 431, -239, -573, 214, 743, -160, -945,
68, 1188, 76,-1486, -297, 1867, 639,-2392,-1199, 3213, 2245,
-4839,-4904,10502,28344,28344,10502,-4904,-4839, 2245, 3213,-1199,
-2392, 639, 1867, -297,-1486, 76, 1188, 68, -945, -160, 743,
214, -573, -239, 431, 243, -313, -233, 218, 211, -143, -185,
87, 157, -49, -141, 27, 186, 163, 50, 0

/*  -12,    16,    48,   -98,  -312,  -234,   100,   180,  -130,  -238,   136,   312,  -134,  -404,   122,   512,   -94,  -640,
   46,   792,    28,  -970,  -134,  1188,   286, -1458,  -510,  1818,   852, -2336, -1464,  3052,  2446, -4652, -5070, 10232,
28264, 28264, 10232, -5070, -4652,  2446,  3052, -1464, -2336,   852,  1818,  -510, -1458,   286,  1188,  -134,  -970,    28,
   92,    46,  -640,   -94,   512,   122,  -404,  -134,   312,   136,  -238,  -130,   180,   100,  -234,  -312,   -98,    48,
   16,   -12,     0 /* SRC Up-Sampling */
};
const signed short Sph_AGC_HP_Flt_Coeff[40] =
{
   -7358, 15521,  7644,-15288,  7644, -7960, 16132,  8192,-16383,  8192, /* UL WB HP-IIR-137Hz (20ms task)*/
   -7831, 15995,  7579,-15158,  7579, -7347, 15512,  8192,-16384,  8192, /* UL NB HP-IIR-137Hz (20ms task)*/
   -8009, 16194,  7884,-15768,  7884, -7758, 15943,  8192,-16384,  8192, /* UL WB HP-IIR-75Hz (20ms task)*/
   -6450, 14504,  7030,-14060,  7030, -7685, 15779,  8193,-16384,  8193  /* UL NB HP-IIR-75Hz (20ms task)*/
};

static void AM_WriteAntiAliasFilter( void )
{
   volatile uint16* dsp_ptr;
   int I;
   const int16 *ptr;

   /* Write Audio filter coefficients */
   ptr = Audio_Flt_Coeff;


   dsp_ptr = SAL_SRC_GetFltCoefAddr();


   //SRC FIR coeff
   for( I = SAL_FLTCOEFLEN_SRC; --I >= 0 ; )
      *dsp_ptr++ = *ptr++;
 
   ptr = Sph_SRCPlus_Flt_Coeff;
   dsp_ptr = SAL_SRCPlus_GetFltCoefAddr();
   //SRCPlus FIR coeff
   for( I = SAL_FLTCOEFLEN_SRCPLUS; --I >= 0 ; )
      *dsp_ptr++ = *ptr++;
  
   //AGC HP IIR coeff
   ptr = Sph_AGC_HP_Flt_Coeff;
   dsp_ptr = SAL_AGC_GetFltCoefAddr();
   for( I = SAL_FLTCOEFLEN_AGC; --I >= 0 ; )
      *dsp_ptr++ = *ptr++;
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

signed short Sph_Notch_Filter_Param[SAL_PARAMETERLEN_NOTCH] = {
	-7708, 15853, 7980, -15929, 7980, 
	-7788, 15937, 8180, -16330, 8180,
	-7948, 16103, 8190, -16346, 8190
};

void AM_SetNotchFilterParam(int16 *param)
{
	memcpy(Sph_Notch_Filter_Param, param, SAL_PARAMETERLEN_NOTCH*sizeof(int16));
}

/**
	This function should used when DSP is turn on
*/
void AM_DSP_WriteNotchFilterParam( void )
{
	int I;
	volatile uint16* toPtr = SAL_Notch_GetFltCoefAddr();	
	int16 *fromPtr = Sph_Notch_Filter_Param;
	
	for( I = SAL_PARAMETERLEN_NOTCH; --I >= 0 ; )
      *toPtr++ = *fromPtr++;
}


// #if __RELOAD_DSP_COEFF__

/* For 65nm process, MCU has to reload DSP coefficient at each wake-up */
static void AM_ReloadDSPCoefficient( void )
{
   AM_WriteSidetoneFIR();

   if(!am.toneLoopbackRec)
      AM_WriteSpeechCompensationFilter(am.in_coeff_tmp, am.out_coeff_tmp);
	
	AM_WriteWbSpeechCompensationFilter(am.wb_in_coeff_tmp, am.wb_out_coeff_tmp);

   AM_WriteAntiAliasFilter();
   L1SP_Reload_MagiClarity_Para();

   if ( !(am.state & AM_STATE_SPEECH) )
      L1SP_Reload_SPE_Para();
}
// #endif

/* ========================================================================= */
/*   internal function Functions                                                     */
/* ========================================================================= */

/**
	This function should call "after AFE_Turnoff8K" and "before AFE_TurnOn8K".
	No user, so phase it out. The AFE_SetVoice8KMode is set directly by AP 
*/
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
#ifdef __DUAL_MIC_SUPPORT__			
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //__DUAL_MIC_SUPPORT__
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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_VMRecordOff( uint32 data , uint32 extraInfo);

extern kal_uint32 SP3G_GetCodecMode(void);

static uint32 dlIrqCnt =0; 
static uint32 ulIrqCnt =0; 
void addDlIrqCnt(void){ dlIrqCnt++; }
uint32 getDlIrqCnt(void){return dlIrqCnt;}
void addUlIrqCnt(void){ ulIrqCnt++; }
uint32 getUlIrqCnt(void){return ulIrqCnt;}
static void AM_DSP_SpeechOn( uint32 rat_mode, uint32 extraInfo )
{
      if(0==extraInfo) {
                               dlIrqCnt =0; 
                                ulIrqCnt =0; 
   }
   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
   L1Audio_Msg_AM_Switch( AM_Switch_Name(5), L1AUDIO_Str_onoff(1) );

   am.speech_off_delay = 0;
   
   //*AFE_VMCU_CON1 &= ~0x0200;
   //*DP_AUDIO_PAR &= ~(VOICE_16K_SWITCH_FLAG);//wayne, no more used by DSP
	// am_SetDevice();
	AFE_TurnOn8K();//SAL user need to handle this for DSP Speech

	// SAL_Set_Device(L1SP_GetSpeechMode()); // the devicde is set when l1sp_SetSpeechMode before speech is on.
   // [OpenDSP]
#if defined(__OPEN_DSP_SPEECH_SUPPORT__)
   SAL_OpenDSP_Ctrl(1); // Notify DSP to enable OpenDSP  0, no openDSP; 1, openDSP;
   SAL_OpenDSP_Timeout_Thres(); // DL: 5ms; UL:15ms
   kal_prompt_trace(MOD_L1SP, "[OD] SAL_OpenDSP_Ctrl = %d",1);
#endif  

   if(rat_mode == RAT_2G_MODE)
   {
#if defined(__VOLTE_SUPPORT__)      
      am.sp4g_flag = false;
#endif        	
      am.sp3g_flag = false;
   	  if(L1SP_TCH_State()){ 	
         AM_Get2GCodecInfo(&am.speech_mode, &am.sub_channel);   	
      }else{
         am.speech_mode = 0;
         am.sub_channel = 0;
      } 
      cc_2G_Call_Open(am.speech_mode, am.speech_mode, am.sub_channel);
   }
      
#if defined( __UMTS_RAT__ )
   else if(rat_mode == RAT_3G_MODE
#ifdef __VIDEO_CALL_SUPPORT__
       || rat_mode == RAT_3G324M_MODE
#endif
   ){
   	kal_uint16 delayR, delayW;
    kal_uint32 u32CurTime64us;
		
		am.speech_mode = SP3G_GetCodecMode();
      am.sp3g_flag = true;
#if defined(__VOLTE_SUPPORT__)            
      am.sp4g_flag = false;
#endif
		// only use Bit[0] to inidicate the resync require
		if((extraInfo&1)!=0) {
			
			SP3G_GetSyncDelayRW( &delayR, &delayW, &u32CurTime64us);
		} else {
			u32CurTime64us = fma_get_glb_ts();
      	delayR = DSP_PCM_IDLE_DELAY_TABLE[6][0];
			delayW = DSP_PCM_IDLE_DELAY_TABLE[6][1];
		}

		cc_3G_Call_Open(am.speech_mode, am.speech_mode, SP3G_IsDTXOn(), delayR, delayW, DSP_PCM_IDLE_DELAY_TABLE[6][2], u32CurTime64us);
   }
#endif
#if defined(__VOLTE_SUPPORT__)
   else if(rat_mode == RAT_4G_MODE){
      am.speech_mode = SP4G_GetCodecMode();      
      am.sp3g_flag = false;           
      am.sp4g_flag = true;
      //get InitCodec
      //SAL_4G_Call_Open(am.speech_mode);
      SP4G_Call_Open(am.speech_mode);
   }
#endif
#if defined(__OPEN_DSP_SPEECH_SUPPORT__)
	ASSERT(SAL_OpenDSP_IsOFF());  // ASSERT when Re-speech on, make sure OpenDSP state is 0 (Idle) 
    SAL_OpenDSP_State_Switch(1);	// switch OpenDSP state to 1, the DSP will switch state to 2	
#endif
   // l1sp_CodecStatusNotification(am.speech_mode);   
   am.state |= AM_STATE_SPEECH;
   l1sp_NetworkStatusNotification(); 
}

uint32 AM_GetNetworkRate()
{
#if defined(__VOLTE_SUPPORT__)          
    if(L1SP_GetState() == L1SP_STATE_4G_SPEECH_ON || L1SP_GetState() == L1SP_STATE_4G_SPEECH_CLOSING)
      return RAT_4G_MODE;
#endif    
    if(L1SP_GetState() == L1SP_STATE_3G_SPEECH_ON || L1SP_GetState() == L1SP_STATE_3G324M_SPEECH_ON || L1SP_GetState() == L1SP_STATE_3G_SPEECH_CLOSING)
      return RAT_3G_MODE;
    if(L1SP_GetState() == L1SP_STATE_2G_SPEECH_ON)
      return RAT_2G_MODE;   

	return RAT_NONE_MODE;

}

/**
	@rat_mode: indicat the 2g/3g call status
	@extraInfo: bit[0]: need to resync or not
*/
void AM_SpeechOn(uint32 rat_mode, uint32 extraInfo)
{
#ifdef ANALOG_AFE_PATH_EXIST
   kal_uint8 DisIdleCount=3;
   while(AFE_GetAfeSate()==2) //afe IdleOff state
   {
      
      kal_sleep_task( AUD_1TICK(3) );
      DisIdleCount--;
      if(!DisIdleCount)
         break;
   }
#endif //ANALOG_AFE_PATH_EXIST
   L1Audio_Msg_AM_Speech(1);   
   AM_Enqueue( AM_DSP_SpeechOn, rat_mode, extraInfo, (rat_mode == RAT_2G_MODE) && L1SP_TCH_State() );

#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOnSpeaker( L1SP_SPEECH );
   AFE_TurnOnMicrophone( L1SP_SPEECH );
#else 
	AFE_TurnOnPathWork( L1SP_SPEECH );
#endif //ANALOG_AFE_PATH_EXIST
   if(rat_mode == RAT_2G_MODE)
      AM_FlushQFunction();
}

void AM_SetBlockMED(uint32 RAT, bool b, uint32 pos)
{
	 L1Audio_Msg_BlockMED(SAL_APP_TYPE_4GCall == RAT, b, pos);
   if(SAL_APP_TYPE_4GCall == RAT){
      am.needBlockMED_4G = b;      
   } else {
      am.needBlockMED_3G = b;
   }
}

static void AM_DSP_SpeechOff( uint32 data , uint32 extraInfo)
{
       kal_prompt_trace("MOD_L1SP", "[DEBUG]IRQ cont in this call: dl=%d, ul=%d", dlIrqCnt, ulIrqCnt); 
   (void)data;
   uint32 uMask32;
   
   L1Audio_Msg_AM_Switch( AM_Switch_Name(5), L1AUDIO_Str_onoff(0) );
   am.speech_off_delay = 10;
   DP_KT_ATT = 0x0; // avoid SD buffer repeating if tone/keytone continues
   /*
   if( am.speech_state & SP_STATE_VMR )            // call drop while conversation recording 
      AM_DSP_VMRecordOff( 0 , 0 );
	*/
#if defined(__OPEN_DSP_SPEECH_SUPPORT__)
   uint8 DisIdleCount = 20;
	 kal_uint32 t_start;
   while(SAL_OpenDSP_IsRunning() == 0) /* DSP in Running state */
   {   		
      kal_sleep_task( AUD_1TICK(2) );
      DisIdleCount--;
      if(!DisIdleCount)
         break;	  
   }
   ASSERT(SAL_OpenDSP_IsRunning());  // ASSERT when DSP state is not 2 (Running) 
   SAL_OpenDSP_State_Switch(0);  // switch DSP state to 3, the DSP will switch state to 0
   t_start = ust_get_current_time();
   kal_prompt_trace(MOD_L1SP, "[OD] OpenDSP_State_Switch start = %d", t_start);
   DisIdleCount = 3;
   while(SAL_OpenDSP_IsOFF() == 0) /* DSP returns to idle state */
   {   		
      kal_sleep_task( AUD_1TICK(3) );
      DisIdleCount--;
      if(!DisIdleCount)
         break;
	  kal_prompt_trace(MOD_L1SP, "[OD] OpenDSP_State_Switch end = %d",ust_us_duration(t_start, ust_get_current_time()));
   }
   kal_prompt_trace(MOD_L1SP, "[OD] OpenDSP_State_Switch end = %d",ust_us_duration(t_start, ust_get_current_time()));	
   kal_prompt_trace(MOD_L1SP, "[OD] SAL_OpenDSP_IsOFF = %d",SAL_OpenDSP_IsOFF());
   ASSERT(SAL_OpenDSP_IsOFF());  // ASSERT when DSP state is not 0 (Idle)    
#endif 		
	 while(1){
	    uMask32 = SaveAndSetIRQMask();
	    L1Audio_Msg_BlockMED_Status(am.needBlockMED_3G, am.needBlockMED_4G);
      if(am.needBlockMED_3G || am.needBlockMED_4G){
         RestoreIRQMask( uMask32 );
         kal_sleep_task( AUD_1TICK(2) );
      }else{
         am.state &= ~AM_STATE_SPEECH;	 
         RestoreIRQMask( uMask32 );
         break;
      }
   }
   
#if defined(__VOLTE_SUPPORT__)
   if(am.sp4g_flag){
      SP4G_Call_Close();
      am.sp4g_flag = false;
   }else
#endif
#if defined( __UMTS_RAT__ )
   if( am.sp3g_flag ){
   	  cc_3G_Call_Close(am.state == 0);
    
      am.sp3g_flag = false;
   }
   else
#endif
   cc_2G_Call_Close(am.state == 0);

	if( ((am.state & ~AM_STATE_AUDIO) == 0) || ((data&1)!=0))
      AFE_TurnOff8K();

}


/**
	@info: bit[0]: need to force dsp8k off or not; 1 for force, 0 for not
*/
void AM_SpeechOff( uint32 info )
{
#if defined(__VOLTE_SUPPORT__)
   KT_StopAndWait();
   TONE_StopAndWait();
#endif

#ifdef ANALOG_AFE_PATH_EXIST
#ifndef  L1D_TEST
   AFE_TurnOffMicrophone( L1SP_SPEECH );
   AFE_TurnOffSpeaker( L1SP_SPEECH );
#endif
#else // no analog afe path
	AFE_TurnOffPathWork( L1SP_SPEECH );
#endif //ANALOG_AFE_PATH_EXIST

   L1Audio_Msg_AM_Speech(0);
   AM_Enqueue( AM_DSP_SpeechOff, info, 0, false );

   AM_FlushQFunction();
}

bool AM_IsSpeechOn( void )
{
   return( (bool)((am.state & AM_STATE_SPEECH) != 0) );
}

bool AM_IsDataCardOn( void )
{
   return( (bool)((am.speech_state &= SP_STATE_DACA) != 0) );  
}

bool AM_IsAmInSpeechState( void )
{
	if ((am.state & (AM_STATE_SPEECH | AM_STATE_VOICE | AM_STATE_VOIP )) != 0)
		return true;
	else 
		return false;
}

void AM_SetSpeechMode( uint16 speech_mode, int8 sub_channel )
{
   am.speech_mode = speech_mode;
   am.sub_channel = sub_channel;
}

uint16 AM_GetSpeechMode(void)
{
	return am.speech_mode; 
}

kal_bool AM_IsSpeechWB( void )
{      
   return IsWBLink(am.speech_mode);
}

#if defined( __UMTS_RAT__ )
void AM_DSP_RAT_sub_2G( uint32 data , uint32 extraInfo)
{
   (void)data;
   if( !(am.state & AM_STATE_SPEECH) )
      return;
   //VBI_End();   //When DSP in NB-AMR, driver set SC,SD mode as WB-AMR, and DSP will assert, and vice versa 
#if defined(__VOLTE_SUPPORT__)      
	if(extraInfo == SAL_APP_TYPE_4GCall){
   	SP4G_Call_Close();
      am.sp4g_flag = false;	   
	}else 
#endif	   
	if(extraInfo == SAL_APP_TYPE_3GCall){	   
   	cc_3G_Call_Close(true);
      am.sp3g_flag = false;
   }    

   
   cc_2G_Call_Open(am.speech_mode, am.speech_mode, am.sub_channel);   
   l1sp_NetworkStatusNotification();
   // l1sp_CodecStatusNotification(am.speech_mode);      
}

void AM_DSP_InterRAT_3G_to_2G( uint32 codec , uint32 extraInfo)
{
   AM_DSP_RAT_sub_2G(0, SAL_APP_TYPE_3GCall);
   L1Audio_Msg_INTERRAT_3G_TO_2G(am.speech_mode);
}

#if defined(__VOLTE_SUPPORT__) 
void AM_DSP_InterRAT_4G_to_2G( uint32 codec , uint32 extraInfo)
{
   AM_DSP_RAT_sub_2G(0, SAL_APP_TYPE_4GCall);
   L1Audio_Msg_INTERRAT_4G_TO_2G(am.speech_mode);
}
#endif

void AM_InterRAT_3G_to_2G()
{
   AM_Enqueue( AM_DSP_InterRAT_3G_to_2G, 0, 0, false );
   AM_FlushQFunction();
}

#if defined(__VOLTE_SUPPORT__) 
void AM_InterRAT_4G_to_2G()
{   
   AM_Enqueue( AM_DSP_InterRAT_4G_to_2G, 0, 0, false );
   AM_FlushQFunction();   
}
#endif 

void AM_DSP_RAT_sub_3G(uint32 codec , uint32 extraInfo)
{
   kal_uint16 u16DelayR, u16DelayW;
   kal_uint32 u32CurTime64us;
	am.speech_mode = codec;
   if( !(am.state & AM_STATE_SPEECH) )
      return;
   if(extraInfo == SAL_APP_TYPE_2GCall){        
      cc_2G_Call_Close(true);
   }else if(extraInfo == SAL_APP_TYPE_3GCall){   
      cc_3G_Call_Close(true);
   }
#if defined(__VOLTE_SUPPORT__)      
   else if(extraInfo == SAL_APP_TYPE_4GCall){
      SP4G_Call_Close();
      am.sp4g_flag = false;
   } 
#endif
   
   SP3G_GetSyncDelayRW( &u16DelayR, &u16DelayW, &u32CurTime64us);
   SAL_3G_Upd_Enc_Cod(codec);//for 3g codec internal, MT6280
   SAL_3G_Upd_Dec_Cod(codec);//for 3g codec internal, MT6280
   cc_3G_Call_Open(codec, codec, SP3G_IsDTXOn(), u16DelayR, u16DelayW, DSP_PCM_IDLE_DELAY_TABLE[6][2], u32CurTime64us);
   L1Audio_Msg_SP3G_FORCE_RESYNC( codec, codec, u16DelayR, u16DelayW);
   am.sp3g_flag = true;
   l1sp_NetworkStatusNotification();     
   // l1sp_CodecStatusNotification(am.speech_mode);      
}

void AM_DSP_InterRAT_2G_to_3G( uint32 codec , uint32 extraInfo)
{
   AM_DSP_RAT_sub_3G(codec, SAL_APP_TYPE_2GCall);
   L1Audio_Msg_INTERRAT_2G_TO_3G(codec);
}

void AM_DSP_3G_INTRARAT (uint32 codec, uint32 extraInfo)
{
   AM_DSP_RAT_sub_3G(codec, SAL_APP_TYPE_3GCall);
   L1Audio_Msg_3G_INTRARAT(codec);   
}

#if defined(__VOLTE_SUPPORT__) 
void AM_DSP_InterRAT_4G_to_3G( uint32 codec , uint32 extraInfo)
{
   AM_DSP_RAT_sub_3G(codec, SAL_APP_TYPE_4GCall);
   L1Audio_Msg_INTERRAT_4G_TO_3G(codec);
}
#endif

void AM_InterRAT_2G_to_3G(uint32 codec)
{
   AM_Enqueue( AM_DSP_InterRAT_2G_to_3G, codec, 0, false );
   AM_FlushQFunction();
}

void AM_3G_INTRARAT(uint32 codec)
{
   AM_Enqueue( AM_DSP_3G_INTRARAT, codec, 0, false );
   AM_FlushQFunction();
}
#if defined(__VOLTE_SUPPORT__) 
void AM_InterRAT_4G_to_3G(uint32 codec)
{   
   AM_Enqueue( AM_DSP_InterRAT_4G_to_3G, codec, 0, false );
   AM_FlushQFunction();
}
#endif
#endif

#if defined(__VOLTE_SUPPORT__)      
void AM_DSP_RAT_sub_4G(uint32 codec , uint32 extraInfo)
{
   //kal_uint16 u16DelayR, u16DelayW; //unused
	am.speech_mode = codec;
   if( !(am.state & AM_STATE_SPEECH) )
      return;
   if(extraInfo == SAL_APP_TYPE_2GCall)
      cc_2G_Call_Close(true);
   else if(extraInfo == SAL_APP_TYPE_3GCall){
      cc_3G_Call_Close(true);
      am.sp3g_flag = false;
   }else{
      SP4G_Call_Close();
      
   }
   
   //SP3G_GetSyncDelayRW( &u16DelayR, &u16DelayW);//????
   //SAL_4G_Upd_Enc_Cod(codec);//for 3g codec internal, MT6280
   //SAL_4G_Upd_Dec_Cod(codec);//for 3g codec internal, MT6280
   
   //SAL_4G_Call_Open(codec);
   SP4G_Call_Open(codec);
   l1sp_NetworkStatusNotification();  
   // l1sp_CodecStatusNotification(am.speech_mode);      
   am.sp4g_flag = true;
}

void AM_DSP_InterRAT_2G_to_4G( uint32 codec , uint32 extraInfo)
{
   //ASSERT(codec < SP4G_CODEC_G711 || codec > SP4G_CODEC_G729);//context is under task level, so g-series cannot be used
   AM_DSP_RAT_sub_4G(codec, SAL_APP_TYPE_2GCall);
   L1Audio_Msg_INTERRAT_2G_TO_4G(codec);
}

void AM_DSP_InterRAT_3G_to_4G( uint32 codec , uint32 extraInfo)
{
   //ASSERT(codec < SP4G_CODEC_G711 || codec > SP4G_CODEC_G729);//context is under task level, so g-series cannot be used
   AM_DSP_RAT_sub_4G(codec, SAL_APP_TYPE_3GCall);
   L1Audio_Msg_INTERRAT_3G_TO_4G(codec);
}

void AM_DSP_4G_INTRARAT (uint32 codec, uint32 extraInfo)
{
   //ASSERT(codec < SP4G_CODEC_G711 || codec > SP4G_CODEC_G729); context is under task level, so g-series can be used
   AM_DSP_RAT_sub_4G(codec, SAL_APP_TYPE_4GCall);
   L1Audio_Msg_4G_INTRARAT(codec);   
}

void AM_InterRAT_2G_to_4G(uint32 codec)
{
   AM_Enqueue( AM_DSP_InterRAT_2G_to_4G, codec, 0, false );
   AM_FlushQFunction();
}

void AM_InterRAT_3G_to_4G(uint32 codec)
{   
   AM_Enqueue( AM_DSP_InterRAT_3G_to_4G, codec, 0, false );
   AM_FlushQFunction();
}

void AM_4G_INTRARAT(uint32 codec)
{
   AM_Enqueue( AM_DSP_4G_INTRARAT, codec, 0, false );
   AM_FlushQFunction();
}

void SAL_4G_AMRCall_Open(int codec, kal_bool isDTX, kal_uint16 u16DelayR, kal_uint16 u16DelayW, const uint16 idle_delay, kal_uint32 u32CurTime64us);
void SAL_4G_AMRCall_Close();
#if defined(__G_CODEC_SUPPORT__)
void SAL_4G_GSeriesCall_Open(int codec, kal_uint16 u16DelayR, kal_uint16 u16DelayW, const uint16 idle_delay, kal_uint32 u32CurTime64us);
void SAL_4G_GSeriesCall_Close(int codec);
#endif
#if defined(__EVS_CODEC_SUPPORT__)
void SAL_4G_EVSCall_Open(int codec, kal_uint16 u16DelayR, kal_uint16 u16DelayW, const uint16 idle_delay, kal_uint32 u32CurTime64us);
void SAL_4G_EVSCall_Close(int codec);
#endif //#if defined(__EVS_CODEC_SUPPORT__)

/*void SAL_4G_Call_Open(int codec){
   ASSERT(am.codec_4g == -1);
   am.codec_4g = codec;
#if defined(__G_CODEC_SUPPORT__)   
   if((codec >= SP4G_CODEC_G711) && (codec <= SP4G_CODEC_G729)){      
      kal_uint16 u16DelayR, u16DelayW;
      SP4G_GetSyncDelayRW( &u16DelayR, &u16DelayW);
      SAL_4G_GSeriesCall_Open(codec, u16DelayR, u16DelayW, DSP_PCM_IDLE_DELAY_TABLE[6][2], u32CurTime64us);      
   }else
#endif      
   {
      kal_uint16 u16DelayR, u16DelayW;
      SP4G_GetSyncDelayRW( &u16DelayR, &u16DelayW);
      SAL_4G_AMRCall_Open(codec, SP4G_IsDTXOn(), u16DelayR, u16DelayW, DSP_PCM_IDLE_DELAY_TABLE[6][2], u32CurTime64us);            
   }  
}*/
void SP4G_Call_Open(uint16 codec)
{
   kal_uint16 delayR, delayW;
   kal_uint32 u32CurTime64us;

   ASSERT(am.codec_4g == -1);
   am.codec_4g = codec;
   SP4G_GetSyncDelayRW( &delayR, &delayW, &u32CurTime64us);
#if defined(__G_CODEC_SUPPORT__)   
   if((codec >= SP4G_CODEC_G711) && (codec <= SP4G_CODEC_G729)){
      SAL_4G_GSeriesCall_Open(codec, delayR, delayW, DSP_PCM_IDLE_DELAY_TABLE[6][2], u32CurTime64us);      
   }else
#endif
   {
#if defined(__EVS_CODEC_SUPPORT__)
      if(is_EVS_codec(codec)){
         SAL_4G_EVSCall_Open(codec, delayR, delayW, DSP_PCM_IDLE_DELAY_TABLE[6][2], u32CurTime64us);      
      }else
#endif //#if defined(__EVS_CODEC_SUPPORT__)
      {
         SAL_4G_AMRCall_Open(codec, SP4G_IsDTXOn(), delayR, delayW, DSP_PCM_IDLE_DELAY_TABLE[6][2], u32CurTime64us);
      }
   }
}

void SP4G_Call_Close(){
   ASSERT(am.codec_4g != -1);
#if defined(__G_CODEC_SUPPORT__)     
   if((am.codec_4g >= SP4G_CODEC_G711) && (am.codec_4g <= SP4G_CODEC_G729)){
      SAL_4G_GSeriesCall_Close(SAL_PCM_NARROWBAND);
   }else
#endif      
   {
#if defined(__EVS_CODEC_SUPPORT__)
      if(is_EVS_codec(am.codec_4g)){
         SAL_4G_EVSCall_Close(SAL_PCM_NARROWBAND);
      }else
#endif //#if defined(__EVS_CODEC_SUPPORT__)
      {
         SAL_4G_AMRCall_Close();
      }
   }
   am.codec_4g = -1; 
}
//extern void SAL_Set4G(bool b);
void SAL_4G_AMRCall_Open(int codec, kal_bool isDTX, kal_uint16 u16DelayR, kal_uint16 u16DelayW, const uint16 idle_delay, kal_uint32 u32CurTime64us)
{
   //SP4G_GetSyncDelayRW( &u16DelayR, &u16DelayW);
   SAL_3G_Upd_Enc_Cod(codec);
   SAL_3G_Upd_Dec_Cod(codec);
   //cc_3G_Call_Open(codec, codec, SP4G_IsDTXOn(), u16DelayR, u16DelayW, DSP_PCM_IDLE_DELAY_TABLE[6][2]);
   //SAL_Set4G(true);
   cc_4G_Call_Open_temp(codec, codec, isDTX, u16DelayR, u16DelayW, idle_delay, u32CurTime64us);
   L1Audio_Msg_SP4G_FORCE_RESYNC( codec, codec, u16DelayR, u16DelayW);
};

void SAL_4G_AMRCall_Close()
{
   cc_4G_Call_Close_temp(am.state == 0);  
   //SAL_Set4G(false); 
}


void SAL_4G_GSeriesCall_Open(int codec, kal_uint16 u16DelayR, kal_uint16 u16DelayW, const uint16 idle_delay, kal_uint32 u32CurTime64us){
   int I;
   int band_mod = SAL_NB;
   if(SP4G_CODEC_G722 == codec )
			band_mod = SAL_WB;

   //SAL_Set4G(true);
   //memset(&cfg, 0, sizeof(Sal_PCMEx_Config_t));
   //cfg.idle = false;//true;
   //cfg.swi  = SAL_PCMEX_SWITCH_ON;
   //cfg.type = SAL_PCMEX_TYPE_VOLTE;	
   //cfg.band = band;//SAL_PCM_NARROWBAND
   //SAL_PcmEx_Config(&cfg);

   /*if(band == SAL_PCM_WIDEBAND)
   {
      AMR_codec_temp = SP4G_CODEC_WBAMR_12_65;
   }
   else
   {
      AMR_codec_temp = SP4G_CODEC_AMR_12_2;
   }
   SAL_3G_Upd_Enc_Cod(AMR_codec_temp);
   SAL_3G_Upd_Dec_Cod(AMR_codec_temp);*/
   cc_4G_G_Codec_Call_Open(band_mod, u16DelayR, u16DelayW, idle_delay, u32CurTime64us);   

   ASSERT(SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF) && SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF));	 

   SAL_PcmEx_SetStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_ON);
   SAL_PcmEx_SetStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_ON);  

   {
      void GSeries_Encode_Init(SP4G_Codec codec);
      void GSeries_Decode_Init(SP4G_Codec codec);
      GSeries_Encode_Init(codec);
      GSeries_Decode_Init(codec);
      //SP4G_SetCodec(codec);//fix
   } 
   
   for(I = 0; ;I ++){
      kal_bool is_ready = true;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /*#if 0*/
      //{
      int test_return_DL, test_return_UL;
	  test_return_DL = SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_RDY);
	  test_return_UL = SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_RDY);
      if( !test_return_DL)
         is_ready &= false;

      if( !test_return_UL)
         is_ready &= false;		
	    kal_trace( TRACE_FUNC, SAL_4G_GSeriesCall_Open_CheckState_UL_DL, I, test_return_DL, test_return_UL, is_ready);
      //}
#endif /*#if 0*/

      if(is_ready)
         break;

#ifndef L1D_TEST
      ASSERT(I < 22);  // wait 200ms  
      kal_sleep_task( AUD_1TICK(2) );
#endif
   }         
   kal_prompt_trace(MOD_L1SP, "[SAL_4G_GSeriesCall_Open] SAL_PcmEx_CheckState OK");

  
}


void SAL_4G_GSeriesCall_Close(int codec){
   Sal_PCMEx_Config_t cfg;

   memset(&cfg, 0, sizeof(Sal_PCMEx_Config_t));
   /* the begining of configure the SAL */ 
	ASSERT(SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF) || SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_RDY));
	ASSERT(SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF) || SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_RDY));
               
   SAL_PcmEx_SetStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF);
   SAL_PcmEx_SetStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF);

   cfg.swi = SAL_PCMEX_SWITCH_OFF;
   cfg.type = SAL_PCMEX_TYPE_EXT_COD;
   cfg.band = SAL_PCM_NARROWBAND;
   
   SAL_PcmEx_Config(&cfg);
   ////SAL_Set4G(false); 
   {
      void GSeries_Encode_DeInit();
      void GSeries_Decode_DeInit();
   }   

   //fsju
   cc_4G_G_Codec_Call_Close(am.state == 0);
} 


void SAL_4G_EVSCall_Open(int codec, kal_uint16 u16DelayR, kal_uint16 u16DelayW, const uint16 idle_delay, kal_uint32 u32CurTime64us)
{
   int I;
   //int AMR_codec_temp;
   //Sal_PCMEx_Config_t cfg;
   int band_mod = SAL_WB;

   /*switch( GET_SP4G_CODEC_ENUM_EVS_BW(codec) )
   {
      case SP4G_CODEC_EVS_08K:
         band = SAL_NB;
         break;
      case SP4G_CODEC_EVS_16K:
         band = SAL_WB;
         break;
      case SP4G_CODEC_EVS_32K:
         ASSERT(0);
         band = SAL_SWB;
         break;
      case SP4G_CODEC_EVS_48K:
         ASSERT(0);
         band = SAL_FB;
         break;
      default:
         ASSERT(0);
         break;
   }*/

   //TODO, fsju. The band is set to MAX EVS capability(computation power).
   //band = SAL_PCM_WIDEBAND;

   //SAL_Set4G(true);
   //memset(&cfg, 0, sizeof(Sal_PCMEx_Config_t));
   //cfg.idle = false;//true;
   //cfg.swi  = SAL_PCMEX_SWITCH_ON;
   //cfg.type = SAL_PCMEX_TYPE_EXT_COD;   
   //cfg.band = band;//SAL_PCM_NARROWBAND
   //SAL_PcmEx_Config(&cfg);

   /*if(band == SAL_PCM_WIDEBAND)
   {
      AMR_codec_temp = 0x20;//SP4G_CODEC_WBAMR_12_65;
   }
   else
   {
      AMR_codec_temp = 0x3;//SP4G_CODEC_AMR_12_2;
   }

   SAL_3G_Upd_Enc_Cod(AMR_codec_temp);
   SAL_3G_Upd_Dec_Cod(AMR_codec_temp);*/


   //TODO, how to set? fsju?????
   band_mod = SAL_WB;

   //cc_4G_EVS_Codec_Call_Open(codec, codec, 0/*isDTX*/, u16DelayR, u16DelayW, idle_delay, u32CurTime64us);
   cc_4G_EVS_Codec_Call_Open(band_mod, u16DelayR, u16DelayW, idle_delay, u32CurTime64us);

   ASSERT(SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF) && SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF));   

   SAL_PcmEx_SetStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_ON);
   SAL_PcmEx_SetStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_ON);  
    
   {
      //TODO, fsju, initial encoder and decoder
      EVS_encoder_clean();
      EVS_decoder_clean();
   } 

   for(I = 0; ;I ++){
      kal_bool is_ready = true;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /*#if 0*/
      int test_return_DL, test_return_UL;
      test_return_DL = SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_RDY);
      test_return_UL = SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_RDY);
      if( !test_return_DL)
         is_ready &= false;

      if( !test_return_UL)
         is_ready &= false;     
      //kal_prompt_trace(MOD_L1SP, "[SAL_4G_EVSCall_Open] I=%d SAL_PcmEx_CheckStateDL=%d SAL_PcmEx_CheckStateUL=%d is_ready=%d", I, test_return_DL, test_return_UL, is_ready);
      L1Audio_Msg_SP4G_EVSSeriesCall_Open(I, test_return_DL, test_return_UL, is_ready);
#endif /*#if 0*/

      if(is_ready)
         break;

#ifndef L1D_TEST
      ASSERT(I < 22);  // wait 200ms  
      kal_sleep_task( AUD_1TICK(2) );
#endif
   }         
   //kal_prompt_trace(MOD_L1SP, "[SAL_4G_EVSCall_Open] SAL_PcmEx_CheckState OK");
   L1Audio_Msg_SP4G_EVSSeriesCall_Open_OK();
}

void SAL_4G_EVSCall_Close(int codec)
{
   Sal_PCMEx_Config_t cfg;

   memset(&cfg, 0, sizeof(Sal_PCMEx_Config_t));
   /* the begining of configure the SAL */ 
   ASSERT(SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF) || SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_RDY));
   ASSERT(SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF) || SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_RDY));
               
   SAL_PcmEx_SetStateUL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF);
   SAL_PcmEx_SetStateDL(SAL_PCMEX_TYPE_EXT_COD, SAL_PCMEX_OFF);

   cfg.swi = SAL_PCMEX_SWITCH_OFF;
   cfg.type = SAL_PCMEX_TYPE_EXT_COD;
   cfg.band = SAL_PCM_NARROWBAND;
   
   SAL_PcmEx_Config(&cfg);
   ////SAL_Set4G(false); 
   {
      //TODO, fsju
      //Disable EVS encoder and decoder
      ;
      ;
   }

   //fsju
   cc_4G_EVS_Codec_Call_Close(am.state == 0);
} 

#endif

kal_bool AM_Is_4G()
{
#if defined(__VOLTE_SUPPORT__)  	
   return am.sp4g_flag;   
#else
   return KAL_FALSE;
#endif
}

/*
void AM_DSP_SetSRCCtrl( uint32 data , uint32 extraInfo)
{
   #define LIMITER_INIT_BIT    (1<<0)
   #define MIC1_UL_W2N_SRC_BIT (1<<1)
   #define MIC1_DL_W2N_SRC_BIT (1<<2)
   #define SIDETONE_BIT        0

   #define BIT6                (1<<6) //wayne, second mic W2N
   #define BIT7                (1<<7) //wayne, ul n2w
   #define BIT8                (1<<8) //wayne, dl w2n
   #define BIT9                (1<<9)
   #define BIT10               (1<<10)
   #define BIT11               (1<<11)
   #define BIT12               (1<<12)
   #define BIT13               (1<<13)

   kal_uint8  sph_mode    = L1SP_GetSpeechMode();
   kal_bool   isWBLink = IsWBLink(am.speech_mode);
   kal_uint32 v = 0;
   (void)data;
   switch(sph_mode){
   case  SPH_MODE_NORMAL:
      if(isWBLink){
         v = SIDETONE_BIT;
      }else{
         v = SIDETONE_BIT + MIC1_DL_W2N_SRC_BIT + MIC1_UL_W2N_SRC_BIT;
         #if defined(__DUAL_MIC_SUPPORT__)
         v |= BIT6;
         #endif          
      }   
      break;
   case  SPH_MODE_BT_EARPHONE:
   case  SPH_MODE_BT_CARKIT:
      if(isWBLink){
         v = BIT8 + BIT7;
      }else{
         v = 0;
      }
      break;
   case  SPH_MODE_EARPHONE:
   case  SPH_MODE_LOUDSPK:
      if(isWBLink){
         v = 0;
      }else{
         v = MIC1_DL_W2N_SRC_BIT + MIC1_UL_W2N_SRC_BIT;
      }
      break;
   case  SPH_MODE_BT_CORDLESS:
   case  SPH_MODE_LINEIN_VIA_BT_CORDLESS:
      v = BIT13 + MIC1_DL_W2N_SRC_BIT + MIC1_UL_W2N_SRC_BIT;//MT6280, what is BIT13?
      break;
   }

   L1Audio_Msg_AM_SRC1((*DP_SCR_CTRL), am.speech_mode, sph_mode);
   *DP_SCR_CTRL = v + ((*DP_SCR_CTRL) & 0x1);
   L1Audio_Msg_AM_SRC2((*DP_SCR_CTRL), am.speech_mode, sph_mode);
}


void AM_SetSRCCtrl(void)
{
   AM_Enqueue( AM_DSP_SetSRCCtrl, 0, 0, true );
   AM_FlushQFunction();
}
*/

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static const uint16 DAITEST_CMD_TABLE[] =
{  0x8000,    /* 0: DAI TEST MODE 0  */
   0x0200,    /* 1: DAI TEST MODE 1  */
   0x0400,    /* 2: DAI TEST MODE 2  */
   0x0800,    /* 3: DAI TEST MODE 3  */
   0x1000,    /* 4: BT Cordless Mode */
   0x2000,    /* 5: BT Earphone Mode */
   0x8000,    /* 6: Speech Mode      */
   0x0000     /* 7: NOne             */
};

//AM_DSP_SetDAIMode AM_DSP_SetDAIMode
/*static void AM_DSP_SetDAIMode( uint32 mode , uint32 extraInfo)
{
   if( am.state & AM_STATE_VOICE )
      return;
   if( (am.state & AM_STATE_SPEECH) == 0 )
      return;

   if( mode == 4 )
      mode = 3;
   if( mode > 3 )
      mode = 0;

   VBI_End();
   AFE_TurnOff8K();

   if( mode == 0 ) {
      AFE_TurnOffDAI();
      AFE_TurnOn8K();               // Turn On 8K int   
      // *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x8000;
      VBI_Reset();
      am.state &= ~AM_STATE_DAI;
      am.io_type = NORMAL_MODE;
   }
   else {
      AFE_TurnOnDAI();
      AFE_TurnOn8K();               // Turn On 8K int   
      // * DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | DAITEST_CMD_TABLE[mode];
      VBI_Reset();
      am.state |= AM_STATE_DAI;
      am.io_type = DAI_MODE;
   }
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
}*/

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_VMRecordOn( uint32 speech_mode , uint32 extraInfo)
{
	Sal_VM_Config_t cfg_t;
	memset(&cfg_t, 0, sizeof(Sal_VM_Config_t));

	cfg_t.swi = SAL_VM_SWITCH_ON;

   if( am.state & (AM_STATE_SPEECH |AM_STATE_VOIP |AM_STATE_VOICE) ) {       /* Conversation Recording */
      ASSERT(!(am.speech_state & SP_STATE_VMR));
	  cfg_t.idle = false;
      am.speech_state |= SP_STATE_VMR;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(0) , L1AUDIO_Str_onoff(1) );
   }
   else {                                    /* VM in idle mode */
      ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
      AFE_TurnOn8K();
	  cfg_t.idle = true;
	  
#if defined(AMRWB_ENCODE)
      if(speech_mode>=0x20 && speech_mode<=0x28) { /* AMR-WB */
         // *AFE_VMCU_CON1 &= ~0x0200;
      }
      if (speech_mode>=0x20 && speech_mode<=0x28) { /* AMR-WB */
      } else 
#endif//#if defined(AMRWB_ENCODE)
      if (speech_mode>=0x03 && speech_mode<=0x0A) { /* AMR */
         //*AFE_VMCU_CON1 |= 0x0200; // FIXME: 
      } else { /* Voice Memo */ //what is this for??
      }
	  cfg_t.codec = speech_mode;
	  cfg_t.delR = DSP_PCM_IDLE_DELAY_TABLE[0][0];
	  cfg_t.delW = DSP_PCM_IDLE_DELAY_TABLE[0][1];
	  cfg_t.delM = DSP_PCM_IDLE_DELAY_TABLE[0][2];
      am.state |= AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(1) );
   }

   SAL_VM_Config(&cfg_t);

}

void AM_VMRecordOn( uint16 speech_mode )
{
#ifdef ANALOG_AFE_PATH_EXIST
	
   kal_uint8 DisIdleCount=3;

   if( (am.state & (AM_STATE_SPEECH|AM_STATE_VOIP)) == 0 ) /* Not in Conversation Recording */
   {
      while(AFE_GetAfeSate()==2) //afe IdleOff state
      {
         
         kal_sleep_task( AUD_1TICK(3) );
         DisIdleCount--;
         if(!DisIdleCount)
            break;
      }
   }
#endif 

#ifdef ANALOG_AFE_PATH_EXIST
   if( AFE_GetInputSource() == L1SP_LNA_FMRR )
   {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
   }
   else {
      if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) )
      {
         AFE_TurnOnMicrophone( L1SP_VOICE );
      }
   }
#else
	if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) )
   {
      AFE_TurnOnPathWork( L1SP_VOICE );
   }
#endif

   AM_Enqueue( AM_DSP_VMRecordOn, speech_mode, 0, false );

   AM_FlushQFunction();
   if(!(am.state & AM_STATE_SPEECH) && (speech_mode <= 0xA) && !(am.state & AM_STATE_VOIP) ) {
      spe_updateSpeAppMask(0xff, false);
	   spe_updateSpeAppMask(SPH_ENH_MASK_ULNR | SPH_ENH_MASK_AGC, true);
      SetSpeechEnhancement(true);
      //SPE_SetULNR(true);
   }
}


static void AM_DSP_VMRecordOff( uint32 data , uint32 extraInfo)
{
   (void)data;
   Sal_VM_Config_t cfg_t;
	memset(&cfg_t, 0, sizeof(Sal_VM_Config_t));

   cfg_t.swi = SAL_VM_SWITCH_OFF;
   cfg_t.idle = false;

   if(am.speech_state & SP_STATE_VMR) /* Conversation Recording */
   {
      am.speech_state &= ~SP_STATE_VMR;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(0) , L1AUDIO_Str_onoff(0) );
	  SAL_VM_Config(&cfg_t);
   }
   else  /* VM in idle mode */
   {
   	  cfg_t.idle = true;
      am.state &= ~AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(0) );

	  SAL_VM_Config(&cfg_t);
	  
      // *DP_16k_CompenFlt_Flag = 0;          /* Switch 16k compensation filter off */
      if( am.state == 0 ) {
         AFE_TurnOff8K();
      }
   }
}

void AM_VMRecordOff( void )
{
   if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) ) {
   	  SetSpeechEnhancement(false);
	  spe_updateSpeAppMask(0xff, true);
      //SPE_SetULNR(false);
   }
#ifdef ANALOG_AFE_PATH_EXIST
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_LINEIN );
   }
   else {
      if( !(am.state & AM_STATE_VOIP) )        
      AFE_TurnOffMicrophone( L1SP_VOICE );
   }
#else // no analog afe path exist
	if( !(am.state & AM_STATE_VOIP) ) {
      AFE_TurnOffPathWork( L1SP_VOICE );
	}
#endif
   AM_Enqueue( AM_DSP_VMRecordOff, 0, 0, false );
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
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
#ifdef ANALOG_AFE_PATH_EXIST
/* under construction !*/
#else
/* under construction !*/
#endif //ANALOG_AFE_PATH_EXIST
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
#ifdef ANALOG_AFE_PATH_EXIST
/* under construction !*/
#else
/* under construction !*/
#endif //ANALOG_AFE_PATH_EXIST
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef ANALOG_AFE_PATH_EXIST	
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_KeyToneOn( uint32 data , uint32 extraInfo)
{
   (void)data;
   ASSERT(!(am.state & AM_STATE_KEYTONE));
   L1Audio_Msg_AM_Switch( AM_Switch_Name(0), L1AUDIO_Str_onoff(1) );

   AFE_TurnOn8K();
   if( (am.state & ~AM_STATE_AVSYNC) == 0 ) {
      AM_Write_Idle_Delay(4);
      VBI_Reset();
   }
   am.state |= AM_STATE_KEYTONE;
}

void AM_KeyToneOn( void )
{
      AM_Enqueue( AM_DSP_KeyToneOn, 0, 0, false );
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOnSpeaker( L1SP_KEYTONE );
#else
	AFE_TurnOnPathWork(L1SP_KEYTONE);
#endif
}

static void AM_DSP_KeyToneOff( uint32 data , uint32 extraInfo)
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(0), L1AUDIO_Str_onoff(0) );
   am.state &= ~AM_STATE_KEYTONE;

   if(am.state == 0)
      VBI_End();

   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
}

void AM_KeyToneOff( void )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOffSpeaker( L1SP_KEYTONE );
#else
	AFE_TurnOffPathWork(L1SP_KEYTONE);
#endif //ANALOG_AFE_PATH_EXIST
   AM_Enqueue( AM_DSP_KeyToneOff, 0, 0, false );
}

bool AM_IsKeyToneOn( void )
{
   if (am.state & AM_STATE_KEYTONE)
      return true;
   return false;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_ToneOn( uint32 data , uint32 extraInfo)
{
   (void)data;
   ASSERT(!(am.state & AM_STATE_TONE));
   L1Audio_Msg_AM_Switch( AM_Switch_Name(1), L1AUDIO_Str_onoff(1) );

   AFE_TurnOn8K();
   if( (am.state & ~AM_STATE_AVSYNC) == 0) {
      AM_Write_Idle_Delay(4);
      VBI_Reset();
   }
   am.state |= AM_STATE_TONE;
}

void AM_ToneOn( void )
{
   AM_Enqueue( AM_DSP_ToneOn, 0, 0, false );
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOnSpeaker( L1SP_TONE );
#else
	AFE_TurnOnPathWork( L1SP_TONE );
#endif // ANALOG_AFE_PATH_EXIST

}

static void AM_DSP_ToneOff( uint32 data , uint32 extraInfo)
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(1), L1AUDIO_Str_onoff(0) );
   am.state &= ~AM_STATE_TONE;

   if( am.state == 0 )
      VBI_End();

   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
}

void AM_ToneOff( void )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOffSpeaker( L1SP_TONE );
#else
	AFE_TurnOffPathWork( L1SP_TONE );
#endif //ANALOG_AFE_PATH_EXIST
   AM_Enqueue( AM_DSP_ToneOff, 0, 0, false );
}

bool AM_IsToneOn( void )
{
   if (am.state & AM_STATE_TONE)
      return true;
   return false;
}


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_PCM8K_PlaybackOn( uint32 data , uint32 extraInfo)
{
   (void)data;

   AFE_TurnOn8K();
   if( am.state == 0 ) {
   	SAL_App_Open(DSP_PCM_IDLE_DELAY_TABLE[2][0], DSP_PCM_IDLE_DELAY_TABLE[2][1], DSP_PCM_IDLE_DELAY_TABLE[2][2]);
   }
#if defined(BGSND_ENABLE) || defined(__SMART_PHONE_MODEM__)
   if ( data == 1 )
   {
      ASSERT(!(am.state & AM_STATE_SND_EFFECT));
      am.state |= AM_STATE_SND_EFFECT;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(9), L1AUDIO_Str_onoff(1) );
   }
   else
#endif // #if defined(BGSND_ENABLE) || defined(__SMART_PHONE_MODEM__)
   {
      ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
      am.state |= AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(2), L1AUDIO_Str_onoff(1) );
   }
}

void AM_PCM8K_PlaybackOn( void )
{
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOn, 0, 0, false );

   if(!(am.state & AM_STATE_SPEECH)){
#ifdef ANALOG_AFE_PATH_EXIST		
      AFE_TurnOnSpeaker( L1SP_VOICE );
#else
		AFE_TurnOnPathWork( L1SP_VOICE );
#endif
   }

   AM_FlushQFunction();
}

static void AM_DSP_PCM8K_PlaybackOff( uint32 data , uint32 extraInfo)
{
   (void)data;

#if defined(BGSND_ENABLE) || defined(__SMART_PHONE_MODEM__)
   if( data == 1 )
   {
      am.state &= ~AM_STATE_SND_EFFECT;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(9), L1AUDIO_Str_onoff(0) );
   }
   else
#endif // #if defined(BGSND_ENABLE) || defined(__SMART_PHONE_MODEM__)
   {
      am.state &= ~AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(2), L1AUDIO_Str_onoff(0) );
   }
      SAL_App_Close(am.state == 0);

   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
}

void AM_PCM8K_PlaybackOff( bool wait )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOffSpeaker( L1SP_VOICE );
#else
	AFE_TurnOffPathWork( L1SP_VOICE );
#endif
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOff, 0, 0, false );

   if( wait )
      AM_FlushQFunction();
}

#if defined(BGSND_ENABLE) || defined(__SMART_PHONE_MODEM__)
bool AM_IsBgsndOn( void ){
   if (am.state & AM_STATE_SND_EFFECT)
      return true;
   return false;
}
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_PCM16K_PlaybackOn( uint32 data , uint32 extraInfo)
{
   (void)data;
   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
   L1Audio_Msg_AM_Switch( AM_Switch_Name(3), L1AUDIO_Str_onoff(1) );

   AFE_TurnOn8K();
   //*DP_AUDIO_PAR |= VOICE_WB_AMR_FLAG;
   AM_Write_Idle_Delay(3);
   VBI_Reset();

   am.state |= AM_STATE_VOICE;
}

void AM_PCM16K_PlaybackOn( void )
{
   AM_Enqueue( AM_DSP_PCM16K_PlaybackOn, 0, 0, false );
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOnSpeaker( L1SP_VOICE );
#else
	AFE_TurnOnPathWork( L1SP_VOICE );
#endif // ANALOG_AFE_PATH_EXIST

   AM_FlushQFunction();
}

static void AM_DSP_PCM16K_PlaybackOff( uint32 data , uint32 extraInfo)
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(3), L1AUDIO_Str_onoff(0) );

   am.state &= ~AM_STATE_VOICE;
   //*DP_AUDIO_PAR &= ~VOICE_WB_AMR_FLAG;
   if( am.state == 0 )
      VBI_End();

   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
}

void AM_PCM16K_PlaybackOff( bool wait )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOffSpeaker( L1SP_VOICE );
#else
	AFE_TurnOffPathWork( L1SP_VOICE );
#endif // ANALOG_AFE_PATH_EXIST
   AM_Enqueue( AM_DSP_PCM16K_PlaybackOff, 0, 0, false );

   if( wait )
      AM_FlushQFunction();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

uint32 AM_GetRecordFormat()
{
   return am.record_format;
}

static void AM_DSP_PCM16K_RecordOn( uint32 data , uint32 extraInfo)
{
   (void)data;
	(void)extraInfo;
	Sal_PCMEx_Config_t cfg_t;
	memset(&cfg_t, 0, sizeof(Sal_PCMEx_Config_t));

   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
   am.record_format = AM_RECORD_16K;

	
	cfg_t.idle = true;
	cfg_t.band = SAL_PCM_WIDEBAND;
	cfg_t.type = SAL_PCMEX_TYPE_REC_NML;
	cfg_t.swi = SAL_PCMEX_SWITCH_ON;
	cfg_t.delR = DSP_PCM_IDLE_DELAY_TABLE[3][0];
	cfg_t.delW = DSP_PCM_IDLE_DELAY_TABLE[3][1];
	cfg_t.delM = DSP_PCM_IDLE_DELAY_TABLE[3][2];

	//config related digital device(nb/wb), 
	// am_SetDevice();
	
   AFE_TurnOn8K();

	SAL_PcmEx_Config(&cfg_t);

   am.state |= AM_STATE_VOICE;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(10), L1AUDIO_Str_onoff(1) );
}

void AM_PCM16K_RecordOn( void )
{
	ASSERT( !( am.state & AM_STATE_SPEECH ) );

#if 0	
/* under construction !*/
/* under construction !*/
#endif 	

#ifdef ANALOG_AFE_PATH_EXIST
	// [removed]delay off process, 

	// open microphone hardware by different source
   if( AFE_GetInputSource() == L1SP_LNA_FMRR )
   {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
   }
   else
   {
      AFE_TurnOnMicrophone( L1SP_VOICE );
   }
#else
	// line in is phase out
	AFE_TurnOnPathWork( L1SP_VOICE );
#endif //ANALOG_AFE_PATH_EXIST

   AM_Enqueue( AM_DSP_PCM16K_RecordOn, 0, 0, false );
   AM_FlushQFunction();


	// enable enhancment
// #if !defined(MT6280)	// let "SetSpeechEnhancement" to decide open the enhancment or not 
// #if defined(WB_SPE_SUPPORT) 
	if(!(am.state & AM_STATE_SPEECH))
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode())
#endif
   {
			//SPE_SetULNR(true);   
			spe_updateSpeAppMask(0xff, false);
			spe_updateSpeAppMask(SPH_ENH_MASK_ULNR | SPH_ENH_MASK_AGC, true);
			SetSpeechEnhancement(true);
   }
// #endif // WB_SPE_SUPPORT
// #endif //!defined(MT6280)

}

static void AM_DSP_PCM16K_RecordOff( uint32 data , uint32 extraInfo)
{
   (void)data;
	(void)extraInfo; 
	Sal_PCMEx_Config_t cfg_t;
	memset(&cfg_t, 0, sizeof(Sal_PCMEx_Config_t));

   cfg_t.swi = SAL_PCMEX_SWITCH_OFF;	
   am.state &= ~AM_STATE_VOICE;
   am.record_format = AM_RECORD_NONE;
   cfg_t.idle = false;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(10), L1AUDIO_Str_onoff(0) );
	
   if( am.state == 0 ) {
   	cfg_t.idle = true;
   }
   cfg_t.type = SAL_PCMEX_TYPE_REC_NML;
 
   SAL_PcmEx_Config(&cfg_t);

   if( am.state == 0 ) {
      AFE_TurnOff8K();
   }
}

void AM_PCM16K_RecordOff( bool wait )
{
   ASSERT( !( am.state & AM_STATE_SPEECH ) );

	// turn off speech enhancment
// #if !defined(MT6280)	 // let "SetSpeechEnhancement" to decide close the enhancment or not 
// #if defined(WB_SPE_SUPPORT) 	
	if(!(am.state & AM_STATE_SPEECH))
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode())
	#endif
   {
			//SPE_SetULNR(false);        
      	SetSpeechEnhancement(false);
			spe_updateSpeAppMask(0xff, true);
   }
// #endif // WB_SPE_SUPPORT
// #endif //!defined(MT6280)


#ifdef ANALOG_AFE_PATH_EXIST
	// close microphone hardware by different source
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_LINEIN );
   }
   else {
      AFE_TurnOffMicrophone( L1SP_VOICE );
   }
#else
	AFE_TurnOffPathWork( L1SP_VOICE );
#endif //ANALOG_AFE_PATH_EXIST

   AM_Enqueue( AM_DSP_PCM16K_RecordOff, 0, 0, false );

   if( wait )
      AM_FlushQFunction();
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_PCM8K_RecordOn( uint32 appType , uint32 extraInfo)
{
	(void)extraInfo;

	Sal_PCMEx_Config_t cfg_t;
	memset(&cfg_t, 0, sizeof(Sal_PCMEx_Config_t));

	cfg_t.idle = false;
	cfg_t.swi = SAL_PCMEX_SWITCH_ON;

   am.record_format = AM_RECORD_8K;

   if( am.state & (AM_STATE_SPEECH | AM_STATE_VOIP)) { 
		// REMIND: Call record and VM EPL can work in the same time, 
		// but they use same interrupt and setting. 
		
		if (AM_PCM8KREC_APP_TYPE_PCMREC == appType) { // Conversation Recording 
	      ASSERT(!(am.speech_state & SP_STATE_PCM8K_REC));
			cfg_t.type = SAL_PCMEX_TYPE_REC_NML;
			am.speech_state |= SP_STATE_PCM8K_REC;

			L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(1) , L1AUDIO_Str_onoff(1) );
		} else if(AM_PCM8KREC_APP_TYPE_VMEPL == appType) { // VM EPL
			ASSERT(!(am.speech_state & SP_STATE_VMR_EPL));
			//cfg_t.epl_comPar0 = 6;//wayne come back;
			cfg_t.type = SAL_PCMEX_TYPE_REC_EPL;
			am.speech_state |= SP_STATE_VMR_EPL;
			L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(4) , L1AUDIO_Str_onoff(1) );
		} else {
			ASSERT(0); // unknown application type
		}      
      
   }else{
   	if(AM_PCM8KREC_APP_TYPE_VMEPL == appType) { // idle epl
			ASSERT_REBOOT((am.state & AM_STATE_VOICE));
			ASSERT_REBOOT(!(am.speech_state & SP_STATE_VMR_EPL));
			am.speech_state |= SP_STATE_VMR_EPL;
		
			cfg_t.idle = false;
			cfg_t.type = SAL_PCMEX_TYPE_REC_EPL;
			
   	} else { // idle record
   		ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
			am.state |= AM_STATE_VOICE;
			
			cfg_t.idle = true;			
			cfg_t.type = SAL_PCMEX_TYPE_REC_NML;
			cfg_t.band = SAL_PCM_NARROWBAND;
			cfg_t.delR = DSP_PCM_IDLE_DELAY_TABLE[2][0];
			cfg_t.delW = DSP_PCM_IDLE_DELAY_TABLE[2][1];
			cfg_t.delM = DSP_PCM_IDLE_DELAY_TABLE[2][2];
   	}
      L1Audio_Msg_AM_Switch( AM_Switch_Name(4), L1AUDIO_Str_onoff(1) );       
       
	}
   if(cfg_t.idle)
   	AFE_TurnOn8K();
   SAL_PcmEx_Config(&cfg_t);
}

void AM_PCM8K_RecordOn( AM_PCM8KREC_APP_TYPE appType )
{

#if 0 
/* under construction !*/
#if defined(__BT_SUPPORT__)
/* under construction !*/
#endif
/* under construction !*/
#endif 

#ifdef ANALOG_AFE_PATH_EXIST
	// delay off, code remove

	//open microphone by different source
   if( AFE_GetInputSource() == L1SP_LNA_FMRR )
   {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
      //kal_sleep_task( AUD_1TICK(AM_RECORD_SLEEP_TICK) );
   }
   else {
      if(!(am.state & AM_STATE_SPEECH))
      {
         AFE_TurnOnMicrophone( L1SP_VOICE );
      }
   }
#else
	if(!(am.state & AM_STATE_SPEECH))
   {
      AFE_TurnOnPathWork( L1SP_VOICE );
   }
#endif //ANALOG_AFE_PATH_EXIST

   AM_Enqueue( AM_DSP_PCM8K_RecordOn, (uint32)appType, 0, false );
   AM_FlushQFunction();

   if(!(am.state & (AM_STATE_SPEECH | AM_STATE_VOIP)))
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode())
#endif
   {
			//SPE_SetULNR(true);   
			spe_updateSpeAppMask(0xff, false);
			spe_updateSpeAppMask(SPH_ENH_MASK_ULNR | SPH_ENH_MASK_AGC, true);
			SetSpeechEnhancement(true);
   }
}

static void AM_DSP_PCM8K_RecordOff( uint32 appType , uint32 extraInfo)
{
	Sal_PCMEx_Config_t cfg_t;
	memset(&cfg_t, 0, sizeof(Sal_PCMEx_Config_t));

   am.record_format = AM_RECORD_NONE;
   cfg_t.swi = SAL_PCMEX_SWITCH_OFF;
   cfg_t.idle = false;

   if(AM_PCM8KREC_APP_TYPE_PCMREC == appType)
		cfg_t.type = SAL_PCMEX_TYPE_REC_NML;
   if(AM_PCM8KREC_APP_TYPE_VMEPL == appType)
		cfg_t.type = SAL_PCMEX_TYPE_REC_EPL;

   if(am.speech_state & (SP_STATE_PCM8K_REC|SP_STATE_VMR_EPL) ) // under call
   {
   	if(AM_PCM8KREC_APP_TYPE_PCMREC == appType) {
	      am.speech_state &= ~SP_STATE_PCM8K_REC;
   	} else if(AM_PCM8KREC_APP_TYPE_VMEPL == appType){
   		am.speech_state &= ~SP_STATE_VMR_EPL;
   	} else {
   		ASSERT(0); // unknow application type
   	}


		if(AM_PCM8KREC_APP_TYPE_PCMREC == appType) {
	      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(1) , L1AUDIO_Str_onoff(0) );
   	} else if(AM_PCM8KREC_APP_TYPE_VMEPL == appType){
   		L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(4) , L1AUDIO_Str_onoff(0) );
   	} 
      
   }
   else
   {
   	if(AM_PCM8KREC_APP_TYPE_VMEPL == appType) { // idle VM epl
   		am.speech_state &= ~SP_STATE_VMR_EPL;
   	} else { // idle record   		
   		am.state &= ~AM_STATE_VOICE;
   	}
      
      L1Audio_Msg_AM_Switch( AM_Switch_Name(4), L1AUDIO_Str_onoff(0) );
   }
   if( am.state == 0 ) {
   	cfg_t.idle = true;
   }
   
   SAL_PcmEx_Config(&cfg_t);
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
   
}

void AM_PCM8K_RecordOff( bool wait , AM_PCM8KREC_APP_TYPE appType)
{
   if(!(am.state & (AM_STATE_SPEECH | AM_STATE_VOIP)))
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode())
#endif
      {
      //SPE_SetULNR(false);        
        SetSpeechEnhancement(false);
	    spe_updateSpeAppMask(0xff, true);
      }
#ifdef ANALOG_AFE_PATH_EXIST   
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_LINEIN );
   }
   else {
      if(!(am.state & AM_STATE_SPEECH))
        {
         AFE_TurnOffMicrophone( L1SP_VOICE );
        }
   }
#else
	if(!(am.state & (AM_STATE_SPEECH | AM_STATE_VOIP))) // for idle record 
	{
		AFE_TurnOffPathWork( L1SP_VOICE );
	}
#endif // ANALOG_AFE_PATH_EXIST

   AM_Enqueue( AM_DSP_PCM8K_RecordOff, (uint32)appType, 0, false );

   if( wait )
      AM_FlushQFunction();
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int16 AM_IsAudioPlaybackOn( void )
{
   if( am.state & AM_STATE_AUDIO )
      return( *DP_ASP_FS );
   return -1;
}

int16 AM_IsIdleState( void )
{
   if( am.state == 0 )
      return true;
   return false;
}

bool AM_IsVMPlaybackOn( void )
{
   if( am.state & AM_STATE_VOICE)
      return true;
   return false;
}

bool AM_IsVoiceOn( void )
{
   if( am.state & ~AM_STATE_AUDIO)
      return true;
   return false;
}

/* ==========================================================================*/
void AM_Mute_UL_EnhResult_Speech(bool mute)
{
	kal_trace(TRACE_INFO, L1SP_MUTE_DSP_UL_ENH_RESULT_CONTROL, mute);	
	SAL_Mute_Ctrl(SAL_MUTE_UL_IN_EN, mute); // in the enhancement end point, which is set -60db to the result. 
}

void AM_Mute_UL_Source_Speech(bool mute)
{
	kal_trace(TRACE_INFO, L1SP_MUTE_DSP_UL_SOURCE_CONTROL, mute);	
	SAL_Mute_Ctrl(SAL_MUTE_UL_PRE_EN, mute); // in the enhancement entry point, when use this, please do not use the 
}	

void AM_Mute_UL_Codec_Speech( bool mute )
{
	kal_trace(TRACE_INFO, L1SP_MUTE_DSP_UL_CODEC_CONTROL, mute);
	SAL_Mute_Ctrl(SAL_MUTE_UL_POS_EN, mute); // need to under this position, or background sound won't be mute. 
}

bool AM_IsULSpeechMuted( void )
{
	return SAL_Mute_Check(SAL_MUTE_UL_POS_EN);
}

void AM_Mute_DL_8K_Speech( bool mute )
{
	kal_trace(TRACE_INFO, L1SP_MUTE_DSP_DL_8K_CONTROL, mute);
	SAL_Mute_Ctrl(SAL_MUTE_DL_8K, mute);

	// check the SHERIF STATE after right
	ASSERT(mute == SAL_Mute_Check(SAL_MUTE_DL_8K));	
}

void AM_Mute_DL_Speech_Traffic( bool mute )
{
	kal_trace(TRACE_INFO, L1SP_MUTE_DSP_DL_TRAFFIC_CONTROL, mute);
	SAL_Mute_Ctrl(SAL_MUTE_DL_PRE_EN, mute); //considering the VT case using P2W, so mute data at this point , not at SAL_MUTE_DL_PRE_SD

	// check the SHERIF STATE after right
	ASSERT(mute == SAL_Mute_Check(SAL_MUTE_DL_PRE_EN));	
}




void AM_Init( void )
{
	 am.dsp_2g_reset = false;
	
   am.record_format = AM_RECORD_NONE;
   RB_INIT( am.qfunc );
   am.state = 0;
   am.speech_mode = 0;
   am.sub_channel = 0;
   am.speech_off_delay = 0;
   am.pre_isWBLink = KAL_FALSE;

	am.isFirCoeffSet = false;

   //*DP_ASP_DEL_W        = 95;
   //*DP_ASP_DEL_M        = 95;

   SAL_Dsp_Sph_Init();


   AM_WriteSidetoneFIR();

   if( am.isFirCoeffSet == KAL_FALSE ) {
#if 1//#ifdef __AMRWB_LINK_SUPPORT__		
		AM_WriteWbFirCoeffs( WB_Speech_Input_FIR_Coeff[0], WB_Speech_Output_FIR_Coeff[0] );
#endif
      AM_WriteFirCoeffs( Speech_Input_FIR_Coeff[0], Speech_Output_FIR_Coeff[0] );
   }
   AM_WriteAntiAliasFilter();
   
   AM_WriteAspParam( ASP_TYPE_VOICE, ASP_FS_8K, 95, 95 );

   DSP_IO4_On();
   DSP_IO5_On();      
   DSP_IO6_On();      
   DSP_IO7_On();

   am.io_type = NORMAL_MODE;
   am.speech_state = 0;
   am.voip_state = 0;   
   am.fLoopBack = false;
   am.sp3g_flag = false;
#if defined(__VOLTE_SUPPORT__)         
   am.sp4g_flag = false;
   am.codec_4g  = -1;
#endif   
   
   am.toneLoopbackRec = false;

	AM_DSP_SetAudioDigitalGain(DG_DAF);
	AM_DSP_SetSpeechDigitalGain(DG_DL_Speech);
	AM_DSP_SetSpeechUplinkDigitalGain(DG_Microphone);
	AM_DSP_SetSpeechEnhRefDigitalGain(DG_DL_Speech); //am.speechDlEnhRefDigtalGain init
}

/* ========================================================================= */
/*   Bluetooth control Functions                                             */
/* ========================================================================= */
#if defined(__BT_SUPPORT__)
extern const unsigned short default_bt_pcm_in_vol;
extern const unsigned short default_bt_pcm_out_vol;
extern const unsigned short default_bt_pcm_out_enh_ref_vol;

static void AM_DSP_BluetoothOn( uint32 data , uint32 extraInfo)
{
	Sal_BT_Config cfg_t;
	memset(&cfg_t, 0, sizeof(Sal_BT_Config));
	cfg_t.feed_cfg = true;


   // Adjust the uplink and downlink gain
   am.bt_digital_gain = AM_DSP_GetSpeechDigitalGain(); //*DP_VOL_OUT_PCM;
   // am.bt_mic_gain = AM_DSP_GetSpeechUplinkDigitalGain(); //*DP_VOL_IN_PCM;
   // am.bt_dlEnhRef_digital_gain = AM_GetSpeechEnhRefDigitalGain(); // use am.speechDlEnhRefDigtalGain

   // Zero-pending
   cfg_t.linear_ctrl = SAL_BT_LINEAR_GAIN_CONFIG_ZPAD;
   cfg_t.mode = SAL_BT_MODE_LINEAR;
   // MSB first
   cfg_t.linear_reverse = false;
   
   //set mode and uplink gain
   cfg_t.linear_ul_gain = 1;

   //*DP_VOL_OUT_PCM = default_bt_pcm_out_vol;
   AM_DSP_SetSpeechDigitalGain(default_bt_pcm_out_vol); // *DP_VOL_OUT_PCM = 0x1000;
   AM_DSP_SetSpeechUplinkSwAgcGain(0); // AGC set to 0 db
	AM_DSP_SetSpeechEnhRefDigitalGain(default_bt_pcm_out_enh_ref_vol); // 0db 

   //de-feature bt cordless in Moly
      
	AFE_SetBtFlag(KAL_TRUE);

	SAL_BT_Config(&cfg_t);
   
   
   am.io_type = BT_EARPHONE_MODE;
	L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
}

static void AM_DSP_BluetoothOff( uint32 data , uint32 extraInfo)
{
	Sal_BT_Config cfg_t;
	memset(&cfg_t, 0, sizeof(Sal_BT_Config));
	
   cfg_t.feed_cfg = false;
   
   AFE_SetBtFlag(KAL_FALSE);

	// restore the value to default
   AM_DSP_SetSpeechDigitalGain(am.bt_digital_gain); 
   AM_DSP_SetSpeechUplinkSwAgcGain(am.speechUplinkSwAgcGain);
	AM_DSP_SetSpeechEnhRefDigitalGain(am.speechDlEnhRefDigtalGain);

   SAL_BT_Config(&cfg_t);

   am.io_type = NORMAL_MODE;
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
}

//*******************************************************************//
//*   bt_mode:        1 for cordless mode, 2 for earphone mode      *//
//*   bt_sync_type:   0 for short sync, 1 for long sync             *//
//*   bt_sync_length: range from 1 to 8                             *//
//*******************************************************************//
#if 0 // [FIXME] useless?? 
/* under construction !*/
/* under construction !*/
#endif

void AM_BluetoothOn( uint8 bt_mode )
{
	ASSERT(bt_mode == 2); // expected earphone mode only
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
#endif 

   AM_Enqueue( AM_DSP_BluetoothOn, 0, 0, false );

   AM_FlushQFunction();
}

void AM_BluetoothOff( void )
{
#if !defined(__SMART_PHONE_MODEM__)
   TONE_StopAndWait();
   KT_StopAndWait();
#endif

   AM_Enqueue( AM_DSP_BluetoothOff, 0, 0, false );
   AM_FlushQFunction();
}

bool AM_IsBluetoothOn( void )
{
   return SAL_BT_IsEnable();
}

bool AM_IsBTCordlessMode( void )
{
   return false;//( (*DP_AUDIO_PAR&0x1000)!=0 );
}

#endif   // __BT_SUPPORT__
/* ========================================================================= */
/*
static void AM_DSP_PCM_Mode_On( uint32 data , uint32 extraInfo)
{
   AFE_TurnOnPcm(8); //param is snyc type & snyc length, mode b in ap
   
   if(am.state != 0)
   {
      //if(am.state & AM_STATE_SPEECH)
         //AM_FillSilencePattern( DSP_TX_TCH_S0_0, 2, am.speech_mode );
      AFE_TurnOn8K();
      if(am.state & ( AM_STATE_SPEECH | AM_STATE_VOICE ) )
         VBI_Reset();
   }

   am.io_type = PCM_MODE;
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
}

static void AM_DSP_PCM_Mode_Off( uint32 data , uint32 extraInfo)
{
   AFE_TurnOffPcm(0);
   am.io_type = NORMAL_MODE;
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
}

void AM_PCM_Mode_On(kal_uint16 data)
{
#if 0 // useless
   uint32 param = 0;
   param |= (Bluetooth_Sync_Type << 3);    // bt_sync_type will be either 0 for short sync, or 1 for long sync
   param |= (Bluetooth_Sync_Length - 1);   // 1 <= bt_sync_length <= 8
#endif 
   AM_Enqueue( AM_DSP_PCM_Mode_On, 0, 0, false );
   AM_FlushQFunction();
}

void AM_PCM_Mode_Off(void)
{
   AM_Enqueue( AM_DSP_PCM_Mode_Off, 0, 0, false );
   AM_FlushQFunction();
}

kal_bool AM_IsPcmModeOn( void )
{
   if(am.io_type == PCM_MODE)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}
*/

/* ========================================================================= */

#if defined(BGSND_ENABLE) || defined(__SMART_PHONE_MODEM__)
void AM_SND_PlaybackOn( void )
{
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOn, 1, 0, false );	

   if( !AM_IsSpeechOn() ) {
#ifdef ANALOG_AFE_PATH_EXIST			
		AFE_TurnOnSpeaker( L1SP_SND_EFFECT );
#else
		AFE_TurnOnPathWork( L1SP_SND_EFFECT );
#endif
   }

   AM_FlushQFunction();
}

void AM_SND_PlaybackOff( bool wait )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOffSpeaker( L1SP_SND_EFFECT );
#else
	AFE_TurnOffPathWork( L1SP_SND_EFFECT );
#endif

   AM_Enqueue( AM_DSP_PCM8K_PlaybackOff, 1, 0, false );

   if( wait )
      AM_FlushQFunction();
}
#endif // defined(BGSND_ENABLE) || defined(__SMART_PHONE_MODEM__)

/* ========================================================================= */
/*   PCM_EX control Functions                                            */
/* ========================================================================= */

void AM_DSP_PCM_EX_On(uint32 type, uint32 data)
{
   kal_bool flag; 
   uint8 voip_state = 0;  
	
   Sal_PCMEx_Config_t cfg;
	memset(&cfg, 0, sizeof(Sal_PCMEx_Config_t));

	
	flag = true;     //this flag is used to choose one among multiple options 	
   switch(type)
   {
      case AM_PCMEX_TYPE_DACA_DEDICATION: // 100:  //DACA ACTIVE
      	if(flag){
			   L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(3) , L1AUDIO_Str_onoff(1) );
	         ASSERT(!(am.speech_state & SP_STATE_DACA)); 	         
	         am.speech_state |= SP_STATE_DACA;         
				
			   cfg.idle = false;
				
				flag=false;
      	}
      case AM_PCMEX_TYPE_DACA_IDLE_WO_ENH: //101:  //DACA IDLE
			if(flag){
			   ASSERT_REBOOT( !(am.state & AM_STATE_DACA) ); 	        	
	        	ASSERT(am.state == 0);
	         am.state |= AM_STATE_DACA;
	
	        	cfg.idle = true;
				
				flag=false;
	      }
			cfg.swi  = SAL_PCMEX_SWITCH_ON;
			cfg.type = SAL_PCMEX_TYPE_DACA;	
			{
			_DACA_EX_T *dacaExData = (_DACA_EX_T *)data;
			cfg.band = (dacaExData->app_type & DACA_USE_NB) ? SAL_PCM_NARROWBAND : SAL_PCM_WIDEBAND;
			}
      
         break;         	      
		// ======================================================================
      case AM_PCMEX_TYPE_DEDICATION: // 0:  //PCM4WAY CTM
	      if(flag){
	         L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(2) , L1AUDIO_Str_onoff(1) );
	         ASSERT(!(am.speech_state & SP_STATE_PCMNWAY)); 
	         
	         am.speech_state |= SP_STATE_PCMNWAY;
				
			   cfg.idle = false;         
				
				flag=false;
	      } 
		/*
      case AM_PCMEX_TYPE_IDLE_WO_ENH: // 1:  //PCM2WAY Voice
	      if(flag){
	         ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
	        	ASSERT(am.state == 0);
				am.state |= AM_STATE_VOICE;         
				
	        	cfg.idle = true;
				
				flag = false;
	      } 
		*/
      case AM_PCMEX_TYPE_IDLE: //2: PCM2WAY VoIP
	      if(flag){
	         ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );          
	        	ASSERT(am.state == 0);			
	         am.state |= AM_STATE_VOIP;    
				
	        	cfg.idle = true;
				flag = false;
	      }
			
			cfg.swi  = SAL_PCMEX_SWITCH_ON;
			cfg.type = SAL_PCMEX_TYPE_PNW;	    
			
			{
			
			_PCMEX_T *pcmExData = (_PCMEX_T *)data;

			cfg.D2M_ul1 = (0!=(pcmExData->cfgUL1 & USE_D2M_PATH));
			cfg.M2D_ul1 = (0!=(pcmExData->cfgUL1 & USE_M2D_PATH));
			cfg.afterEnh_ul1 = (0!=(pcmExData->cfgUL1 & DATA_SELECT_AFTER_ENH));

			cfg.D2M_ul2 = (0!=(pcmExData->cfgUL2 & USE_D2M_PATH));
			cfg.M2D_ul2 = (0!=(pcmExData->cfgUL2 & USE_M2D_PATH));
			cfg.afterEnh_ul2 = (0!=(pcmExData->cfgUL2 & DATA_SELECT_AFTER_ENH));

			cfg.D2M_ul3 = (0!=(pcmExData->cfgUL3 & USE_D2M_PATH));
			cfg.M2D_ul3 = (0!=(pcmExData->cfgUL3 & USE_M2D_PATH));
			cfg.afterEnh_ul3 = (0!=(pcmExData->cfgUL3 & DATA_SELECT_AFTER_ENH));

			cfg.D2M_ul4 = (0!=(pcmExData->cfgUL4 & USE_D2M_PATH));
			cfg.M2D_ul4 = (0!=(pcmExData->cfgUL4 & USE_M2D_PATH));
			cfg.afterEnh_ul4 = (0!=(pcmExData->cfgUL4 & DATA_SELECT_AFTER_ENH));
			
			cfg.D2M_dl = (0!=(pcmExData->cfgDL & USE_D2M_PATH));
			cfg.M2D_dl = (0!=(pcmExData->cfgDL & USE_M2D_PATH));
			cfg.afterEnh_dl = (0!=(pcmExData->cfgDL & DATA_SELECT_AFTER_ENH));
			

			if(cfg.idle){
				if(pcmExData->bandInfo == PCMEX_BAND_WB){
					cfg.band = SAL_PCM_WIDEBAND;			 
				}else if (pcmExData->bandInfo == PCMEX_BAND_NB){
					cfg.band = SAL_PCM_NARROWBAND;			 
				}else{ // should never been here
					ASSERT(0);  				
				}
			} else {
				cfg.band = SAL_PCM_DYNAMIC;
			} 
			
			}
			
         break;
		// ======================================================================	
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
	  case AM_PCMEX_TYPE_REC_ONLY_CAL: //3: record only dmnr calibration	      
	      if(flag){voip_state = VOIP_STATE_REC_ONLY_CAL;flag=false;}
	  case AM_PCMEX_TYPE_REC_PLAY_CAL: //4: record and play dmnr calibration	
	      if(flag){voip_state = VOIP_STATE_REC_PLAY_CAL;flag=false;}
	      	   
			ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 			
			ASSERT_REBOOT( !(am.voip_state & voip_state) ); 
			
        	ASSERT(am.state == 0);
         am.state |= AM_STATE_VOIP; 			
			am.voip_state |= voip_state;

			{ // Turn On AGC
			Sal_AGC_Config_t cfg;
			memset(&cfg, 0, sizeof(Sal_AGC_Config_t));
		
			cfg.main_switch = true;
			cfg.gain_switch = true;
			cfg.hpiir_switch = true;
			cfg.vad_switch = true;
			cfg.init_req = true;

			cfg.cosim = false;
			SAL_AGC1_Config(&cfg);
			SAL_AGC2_Config(&cfg);
			}

			// Turn on UL Path 
		   SAL_ENH_SetULPath(true);   
        	cfg.idle = true;
			cfg.swi  = SAL_PCMEX_SWITCH_ON;
			cfg.type = SAL_PCMEX_TYPE_PNW;	
			cfg.DMNR_cal = true;      

			
			{				
			_PCMEX_T *pcmExData = (_PCMEX_T *)data;
			cfg.D2M_ul1 = (0!=(pcmExData->cfgUL1 & USE_D2M_PATH));
			cfg.M2D_ul1 = (0!=(pcmExData->cfgUL1 & USE_M2D_PATH));
			cfg.afterEnh_ul1 = (0!=(pcmExData->cfgUL1 & DATA_SELECT_AFTER_ENH));

			cfg.D2M_ul2 = (0!=(pcmExData->cfgUL2 & USE_D2M_PATH));
			cfg.M2D_ul2 = (0!=(pcmExData->cfgUL2 & USE_M2D_PATH));
			cfg.afterEnh_ul2 = (0!=(pcmExData->cfgUL2 & DATA_SELECT_AFTER_ENH));

			cfg.D2M_ul3 = (0!=(pcmExData->cfgUL3 & USE_D2M_PATH));
			cfg.M2D_ul3 = (0!=(pcmExData->cfgUL3 & USE_M2D_PATH));
			cfg.afterEnh_ul3 = (0!=(pcmExData->cfgUL3 & DATA_SELECT_AFTER_ENH));

			cfg.D2M_ul4 = (0!=(pcmExData->cfgUL4 & USE_D2M_PATH));
			cfg.M2D_ul4 = (0!=(pcmExData->cfgUL4 & USE_M2D_PATH));
			cfg.afterEnh_ul4 = (0!=(pcmExData->cfgUL4 & DATA_SELECT_AFTER_ENH));
			
			cfg.D2M_dl = (0!=(pcmExData->cfgDL & USE_D2M_PATH));
			cfg.M2D_dl = (0!=(pcmExData->cfgDL & USE_M2D_PATH));
			cfg.afterEnh_dl = (0!=(pcmExData->cfgDL & DATA_SELECT_AFTER_ENH));
			
			if(pcmExData->bandInfo == PCMEX_BAND_WB){
				cfg.band = SAL_PCM_WIDEBAND;			 
			}else if (pcmExData->bandInfo == PCMEX_BAND_NB){
				cfg.band = SAL_PCM_NARROWBAND;			 
			}else{ // should never been here
				ASSERT(0);  				
			}
			}
			break;
#endif
      default:
         ASSERT(0); break;                 
   }

   if(cfg.idle == true){
      cfg.delR = DSP_PCM_IDLE_DELAY_TABLE[5][0];
      cfg.delW = DSP_PCM_IDLE_DELAY_TABLE[5][1];
      cfg.delM = DSP_PCM_IDLE_DELAY_TABLE[5][2];
      AFE_TurnOn8K();
	}

	SAL_PcmEx_Config(&cfg);
}


void AM_DSP_PCM_EX_Off(uint32 type, uint32 data)
{
   kal_bool flag;   
   uint8 voip_state = 0;     
	
   Sal_PCMEx_Config_t cfg;
	memset(&cfg, 0, sizeof(Sal_PCMEx_Config_t));

	flag = true;     //this flag is used to choose one among multiple options       
   switch(type)
   {
      case AM_PCMEX_TYPE_DACA_DEDICATION:  //100: DACA ACTIVE
      	if(flag ){
         	am.speech_state &= ~SP_STATE_DACA;
	         L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(3) , L1AUDIO_Str_onoff(0) );    
				
         	cfg.idle = false;

				flag = false;
      	}     
      case AM_PCMEX_TYPE_DACA_IDLE_WO_ENH:  //101: DACA IDLE
      	if(flag ){
	         am.state &= ~AM_STATE_DACA;        	
	        	ASSERT(am.state == 0);
				
	        	cfg.idle = true;

				flag =false;
      	}

			cfg.swi = SAL_PCMEX_SWITCH_OFF;
			cfg.type = SAL_PCMEX_TYPE_DACA;
			
         break;                  	            			
		// ======================================================================
      case AM_PCMEX_TYPE_DEDICATION:  //PCM4WAY CTM
      	if(flag ){
	         am.speech_state &= ~SP_STATE_PCMNWAY;
      	   L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(2) , L1AUDIO_Str_onoff(0) );                   
				
   	      cfg.idle = false;

				flag = false;
      	}
		/*
      case AM_PCMEX_TYPE_IDLE_WO_ENH:  //PCM2WAY Voice
      	if(flag ){
      	   am.state &= ~AM_STATE_VOICE;
   	     	ASSERT(am.state == 0);
				
	        	cfg.idle = true;
				
     			flag = false;
      	} 
      	*/
      case AM_PCMEX_TYPE_IDLE:  //PCM2WAY VoIP
      	if(flag ){
	         am.state &= ~AM_STATE_VOIP;         
   	     	ASSERT(am.state == 0);
				
      	  	cfg.idle = true;

				flag = false;
      	}

			cfg.swi = SAL_PCMEX_SWITCH_OFF;
			cfg.type = SAL_PCMEX_TYPE_PNW;
			
         break;
		// ======================================================================
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)			
	   case AM_PCMEX_TYPE_REC_ONLY_CAL: //3: record only dmnr calibration	      
	      if(flag){voip_state = VOIP_STATE_REC_ONLY_CAL;flag=false;}
	   case AM_PCMEX_TYPE_REC_PLAY_CAL: //4: record and play dmnr calibration	
	      if(flag){voip_state = VOIP_STATE_REC_PLAY_CAL;flag=false;}
         am.voip_state &= ~voip_state;
			am.state &= ~AM_STATE_VOIP;
			
         cfg.idle = true;
         cfg.swi = SAL_PCMEX_SWITCH_OFF;
			cfg.type = SAL_PCMEX_TYPE_PNW;
			cfg.DMNR_cal = false;
						
			SAL_ENH_SetULPath(false);
			{ // Turn off AGC. 
			Sal_AGC_Config_t cfg;
			memset(&cfg, 0, sizeof(Sal_AGC_Config_t));
	
			cfg.main_switch = false;
			cfg.gain_switch = false;
			cfg.hpiir_switch = false;
			cfg.vad_switch = false;
			cfg.init_req = false;

			cfg.cosim = false;
			SAL_AGC1_Config(&cfg);
			SAL_AGC2_Config(&cfg);
			}
	  	   break;		 
#endif			
      default:
         ASSERT(0);
         break;                  
   }    


	SAL_PcmEx_Config(&cfg);
   if(cfg.idle == true){
	   AFE_TurnOff8K();
   }   
}

/**
	@type: AM_PCMEX_TYPE, indicate the PCM EX type
	@p2exData: Addess of "glable variable" like pcmEx, dacaEx
*/
void  AM_PCM_EX_On( AM_PCMEX_TYPE type, uint32 p2exData)
{
	kal_uint8 aud_func;
   if(type == AM_PCMEX_TYPE_IDLE 
		|| type == AM_PCMEX_TYPE_REC_ONLY_CAL 
		|| type == AM_PCMEX_TYPE_REC_PLAY_CAL
		|| type == AM_PCMEX_TYPE_DACA_IDLE )
   {	
#ifdef ANALOG_AFE_PATH_EXIST   
      AFE_SetDigitalGain( L1SP_SPEECH, 100 );  
#else
		// AFE_DigitalOnly_SetDigitalGain(L1SP_SPEECH, -4);
#endif
		
#if defined(AEC_ENABLE)
#if SPE_LOUDSPK_DMNR
		DSP_DynamicDownload( DDID_SPH_TCH_1 );
#else
      DSP_DynamicDownload( DDID_NOISE_REDUCTION );   
#endif
#endif

		aud_func = L1SP_SPEECH;
   }	
   else 
#ifdef ANALOG_AFE_PATH_EXIST  		
		if(!(am.state & AM_STATE_SPEECH)) 
#endif			
	{
      aud_func = L1SP_VOICE;
   }

   AM_Enqueue( AM_DSP_PCM_EX_On, type, p2exData, false );
	

#ifdef ANALOG_AFE_PATH_EXIST   
	// turn on speaker or microhpone by different AM application type. 
	if(aud_func < L1SP_MAX_AUDIO)
	{
		if(type == AM_PCMEX_TYPE_REC_ONLY_CAL){ //case when calibration with record only
			AFE_TurnOnMicrophone( aud_func );
		} else { //default
			AFE_TurnOnSpeaker( aud_func );
			AFE_TurnOnMicrophone( aud_func );
		}
	}
#else
	AFE_TurnOnPathWork(aud_func);
#endif //ANALOG_AFE_PATH_EXIST   

   AM_FlushQFunction();
}


void  AM_PCM_EX_Off( AM_PCMEX_TYPE type, uint32 p2exData)
{

	// find out the aud_func
   kal_uint8 aud_func = L1SP_MAX_AUDIO;

   if( type == AM_PCMEX_TYPE_IDLE 
		|| type == AM_PCMEX_TYPE_REC_ONLY_CAL 
		|| type == AM_PCMEX_TYPE_REC_PLAY_CAL
		|| type == AM_PCMEX_TYPE_DACA_IDLE ) {
      aud_func = L1SP_SPEECH;
   } else {
      aud_func = L1SP_VOICE;
   }


#ifdef ANALOG_AFE_PATH_EXIST
	// turn off speaker or microhpone by different AM application type. 
   if(aud_func < L1SP_MAX_AUDIO)
   {
		if(type == AM_PCMEX_TYPE_REC_ONLY_CAL){ //case when calibration with record only
			AFE_TurnOffMicrophone( aud_func );
		} else {
			AFE_TurnOffSpeaker( aud_func );
			AFE_TurnOffMicrophone( aud_func );
		}
   }
#else
	AFE_TurnOffPathWork(aud_func);
#endif //ANALOG_AFE_PATH_EXIST


   AM_Enqueue(AM_DSP_PCM_EX_Off, type, p2exData, false );
   AM_FlushQFunction();
}

bool AM_IsVoIPOn( void )
{
   return( (bool)((am.state & AM_STATE_VOIP) != 0) );
}

/* ========================================================================= */

uint16 AM_Status( void )
{
   return am.state;
}

void AM_EnableToneLoopBackFlag( kal_bool param )
{
   if(param)
      am.toneLoopbackRec = KAL_TRUE;
   else
      am.toneLoopbackRec = KAL_FALSE;
}
/* ========================================================================= */
/*   Functions for DSP PCM Router                                            */
/* ========================================================================= */
#define PCM_ROUTER_DELAY_READ 0
#define PCM_ROUTER_DELAY_WRITE 0xF0
#define PCM_ROUTER_DELAY_DL 0x38
#define PCM_ROUTER_DELAY_UL 0x118

void AM_DSP_PcmRouter_On( uint32 voiceMode, uint32 extraInfo )
{
	
	Sal_PCM_Router_t pcmrt; 

   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
	L1Audio_Msg_AM_Switch( AM_Switch_Name(11), L1AUDIO_Str_onoff(1) );

	// setting
	memset(&pcmrt, 0 , sizeof(Sal_PCM_Router_t));
	
	pcmrt.cod_band = 0; //voiceMode; 
	pcmrt.dev_band = voiceMode;
	pcmrt.delR = PCM_ROUTER_DELAY_READ;
	pcmrt.delW = PCM_ROUTER_DELAY_WRITE;
	pcmrt.delM_DL = PCM_ROUTER_DELAY_DL;
	pcmrt.delM_UL = PCM_ROUTER_DELAY_UL;	

	// turn on 8k
	AFE_TurnOn8K();	
	
	SAL_PCM_Router_Open(&pcmrt);
	
	am.state |= AM_STATE_VOIP; 
}



void AM_PcmRouter_On(void)
{
	kal_uint8 voiceMode;

	// the following chips did not provide the function 
#if defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6571) || defined(MT6592) || defined(MT6290)
	ASSERT(0);
#endif
	
	voiceMode = AFE_GetVoice8KMode();
	
	AM_Enqueue( AM_DSP_PcmRouter_On, voiceMode, 0, false );

	AFE_TurnOnPathWork(L1SP_SPEECH);
	
	AM_FlushQFunction();

}

void AM_DSP_PcmRouter_Off( uint32 info, uint32 extraInfo )
{
	L1Audio_Msg_AM_Switch( AM_Switch_Name(11), L1AUDIO_Str_onoff(0) );

	SAL_PCM_Router_Close(true);

	AFE_TurnOff8K();

	am.state &= (~AM_STATE_VOIP);
}


void AM_PcmRouter_Off(void)
{

	AFE_TurnOffPathWork( L1SP_SPEECH );


   AM_Enqueue( AM_DSP_PcmRouter_Off, 0, 0, false );

   AM_FlushQFunction();
}


/* ========================================================================= */
/*   Functions for Modem LoopBack Test                                       */
/* ========================================================================= */

bool AM_IsLoopBackTest( void )
{
   return am.fLoopBack;
}

void AM_SetLoopBackTest(bool enable)
{
	//this function should be phased out or changed to based on SAL, 2012.11.15 wayne
   if(AM_IsSpeechOn())
   {
      //if(enable)
       //  *DP_SC_FLAGS = 0x632;
      //else if(am.fLoopBack)
       //  *DP_SC_FLAGS = 0x633;
   }
   am.fLoopBack = enable;
}

/* ========================================================================= */
/*   Functions for Buletooth Cordless Mode                                   */
/* ========================================================================= */
static void AM_DSP_BTCordlessOn( uint32 data, uint32 extraInfo)
{
   (void)data;

#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOnSpeaker( L1SP_VOICE );
   AFE_TurnOnMicrophone( L1SP_VOICE );
#else
	AFE_TurnOnPathWork( L1SP_VOICE );
#endif //ANALOG_AFE_PATH_EXIST
   AFE_TurnOn8K();
   if ( am.state == 0 ) {
      VBI_Reset();
   }
   am.state |= AM_STATE_VOICE;
}

void AM_BTCordlessOn( void )
{
   AM_Enqueue( AM_DSP_BTCordlessOn, 0, 0, false );

   AM_FlushQFunction();
}

static void AM_DSP_BTCordlessOff( uint32 data , uint32 extraInfo)
{
   (void)data;
   am.state &= ~AM_STATE_VOICE;
   if ( am.state == 0 ) {
      VBI_End();
      AFE_TurnOff8K();
   }
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOffMicrophone( L1SP_VOICE );
   AFE_TurnOffSpeaker( L1SP_VOICE );
#else
	AFE_TurnOffPathWork( L1SP_VOICE );
#endif //ANALOG_AFE_PATH_EXIST
}

void AM_BTCordlessOff( void )
{
   AM_Enqueue( AM_DSP_BTCordlessOff, 0, 0, false );

   AM_FlushQFunction();
}

bool AM_IsConflictState( void )
{
   if( am.state & AM_CONFLICT_STATE )
      return true;
   else
      return false;
}

//Run under task level
void AM_SwitchCompFilter( kal_uint16 par )
{
//this function should be phased out. 2012.11.5 wayne
/*   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   if( par == 0 ){
      *DP_AUDIO_PAR &= ~( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
      g_Compen_Blk_Flt = COMPEN_BLOCK_FLT_PAR;
   }
   else{
      *COMPEN_BLOCK_FLT_PAR_PTR &= ~( VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
      g_Compen_Blk_Flt = DP_AUDIO_PAR;
   }
   RestoreIRQMask(savedMask);
   savedMask = (kal_uint32)g_Compen_Blk_Flt;
   L1Audio_Msg_SWITCH_FILT( par, savedMask );*/
}
void AM_TurnOnBlockFilter( void )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOnFIR( L1SP_SPEECH );
#endif
}

void AM_TurnOffBlockFilter( void )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOffFIR( L1SP_SPEECH );
#endif
}

void AM_VBIEnd(void)
{
   VBI_End();
}


kal_uint32 AM_Get2GResyncThreshold(void)
{
   return AM_2G_RESYNC_THRESHOLD;
}

//=============================================================================
// sw digital gain related
//=============================================================================

void AM_DSP_SetAudioDigitalGain(kal_uint16 digitalVol)
{
	am.audioDigitalGain = digitalVol;
	*DP_DigiGain_Setting = digitalVol;

	L1Audio_Msg_AM_DSP_GAIN(AM_Gain_Name(0), digitalVol);
}

kal_uint16 AM_DSP_GetAudioDigitalGain(void)
{
	return *DP_DigiGain_Setting;
}

void AM_DSP_SetSpeechDigitalGain(kal_uint16 digitalVol)
{
	am.speechDigitalGain = digitalVol;
	SAL_DGain_Set_DL(digitalVol);

	L1Audio_Msg_AM_DSP_GAIN(AM_Gain_Name(1), digitalVol);
}

kal_uint16 AM_DSP_GetSpeechDigitalGain(void)
{
	return SAL_DGain_Get_DL();
}

void AM_DSP_SetSpeechUplinkDigitalGain(kal_uint16 digitalVol)
{
	am.speechUplinkDigitalGain = digitalVol;
	SAL_DGain_Set_UL(digitalVol);

	L1Audio_Msg_AM_DSP_GAIN(AM_Gain_Name(2), digitalVol);
}

kal_uint16 AM_DSP_GetSpeechUplinkDigitalGain(void)
{
	return SAL_DGain_Get_UL();
}

void AM_DSP_SetSpeechUplinkSwAgcGain(kal_uint16 digitalVol)
{
	am.speechUplinkSwAgcGain = digitalVol;
	SAL_AGC_SetGain(digitalVol);

	L1Audio_Msg_AM_DSP_GAIN(AM_Gain_Name(3), digitalVol);
}

kal_uint16 AM_GetSpeechEnhRefDigitalGain(void)
{
	return am.speechDlEnhRefDigtalGain;
}

void AM_DSP_SetSpeechEnhRefDigitalGain(kal_uint16 digitalVol)
{
	am.speechDlEnhRefDigtalGain = digitalVol;
	SAL_ENH_Gain_Set_DL(digitalVol);

	L1Audio_Msg_AM_DSP_GAIN(AM_Gain_Name(4), digitalVol);
}

