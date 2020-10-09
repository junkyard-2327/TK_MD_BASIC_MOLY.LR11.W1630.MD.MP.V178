/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 * aud_custom_exp.h
 *
 * Project:
 * --------
 *   DUMA
 *
 * Description:
 * ------------
 * This file is the header of audio customization related function or definition.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 *
 * 02 03 2015 fu-shing.ju
 * [MOLY00091627] TK6291 development
 * Sync Audio driver with MOLY TRUNK W15.05.P1.
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
 * 05 22 2013 sheila.chen
 * [MOLY00023100] [Volunteer Patch][[MP Feature Patch Back] [Vibration Speaker] Speech HAL part (make 2-in1, 3-in-1 difference)
 * 3-in-1 speaker modification. (to indicate 2-in-1 or 3-in-1)
 *
 * 05 03 2013 sheila.chen
 * [MOLY00008234] [MT6572/MT6582] Integration
 * 3-in-1 speaker interface
 *
 * 03 08 2013 sheila.chen
 * [MOLY00008234] [MT6572/MT6582] Integration
 * Lenovo's new feature for MT6582 & MT657
 *
 * 11 21 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Warming removal 3
 * 
 * Fix CTM potential bug
 * 
 * 10 15 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * 1. enable background sound
 * 
 * 2. change WB em data structure
 * 
 * 09 11 2012 sheila.chen
 * [MOLY00000112] [MT6583] Pre-integration
 * Sync Mode number
 *
 * 07 16 2012 sheila.chen
 * NULL
 * phase in 75+80.
 *
 * 06 27 2012 sheila.chen
 * removed!
 * Phase-in pcm2way
 *
 * 06 04 2012 sheila.chen
 * removed!
 * .
 *
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef AUDIO_CUSTOM_EXP_H
#define AUDIO_CUSTOM_EXP_H


/* audio nvram structure definition*/

typedef struct _AUDIO_CUSTOM_PARAM_STRUCT
{
   /* volume setting */
   char volume[3][7];
   /* speech enhancement */
   unsigned short speech_common_para[12];
   unsigned short speech_mode_para[8][16];
   unsigned short speech_volume_para[4];//in the feature, should extend to [MAX_VOL_CATE][MAX_VOL_TYPE][4]
   /* debug info */
   unsigned short debug_info[16];
   /* speech input FIR */
   short          sph_in_fir[6][45];
   /* speech output FIR */
   short          sph_out_fir[6][45];
   /* digital gain of DL speech */
   unsigned short Digi_DL_Speech;
   /* digital gain of uplink speech */
   unsigned short Digi_Microphone;
   /* FM record volume*/
   unsigned short FM_Record_Volume;    
   /* user mode : normal mode, earphone mode, loud speaker mode */
   unsigned short Bluetooth_Sync_Type;
   unsigned short Bluetooth_Sync_Length;
   unsigned short bt_pcm_in_vol;
   unsigned short bt_pcm_out_vol;
   unsigned short user_mode;
   /* auto VM record setting */
   unsigned short bSupportVM;
   unsigned short bAutoVM;
   unsigned short uMicbiasVolt;
} AUDIO_CUSTOM_PARAM_STRUCT;

#ifdef SPC_MSG_ORG_VER	
typedef struct _AUDIO_CUSTOM_WB_PARAM_STRUCT_
{
   /* WB speech enhancement */
   unsigned short speech_mode_wb_para[8][16];
   /* WB speech input FIR */
   short          sph_wb_fir[6][90];
   /* WB speech output FIR */
   short          input_out_fir_flag; // 0: input, 1: output
} AUDIO_CUSTOM_WB_PARAM_STRUCT;
#else
typedef struct _AUDIO_CUSTOM_WB_PARAM_STRUCT_
{
    /* WB speech enhancement */
    unsigned short speech_mode_wb_para[8][16];
    /* WB speech input FIR */
    short          sph_wb_in_fir[6][90];
    /* WB speech output FIR */
    short          sph_wb_out_fir[6][90];
} AUDIO_CUSTOM_WB_PARAM_STRUCT;
#endif //#ifdef SPC_MSG_ORG_VER	

typedef struct _AUDIO_CUSTOM_DMNR_PARAM_STRUCT_
{
   /* NB DMNR parameters */
   short DMNR_para[NUM_DMNR_PARAM];
   /* WB DMNR parameters */
   short WB_DMNR_para[NUM_WB_DMNR_PARAM];

	/* Loud speaker used NB DMNR parameters */	
   short LSpk_DMNR_para[NUM_DMNR_PARAM];
   /* Loud speaker used WB DMNR parameters */
   short LSpk_WB_DMNR_para[NUM_WB_DMNR_PARAM];
	
} AUDIO_CUSTOM_DMNR_PARAM_STRUCT;

typedef struct _AUDIO_CUSTOM_MAGI_CONFERENCE_STRUCT_
{
	unsigned short sph_voice_tracking_mode_para[16]; 
	unsigned short sph_voice_tracking_mode_wb_para[16];
	
} AUDIO_CUSTOM_MAGI_CONFERENCE_STRUCT;

typedef struct _AUDIO_VIBSPK_PARAMETER_STRUCT_
{
	short notch_filter_para[15];
	bool is2In1Spk; // true for 2-in-1 speaker, false for 3-in-1 speaker.
	
} AUDIO_VIBSPK_PARAMETER_STRUCT;

typedef struct _AUDIO_NXP_SMARTPA_PARAMETER_STRUCT_
{
	bool isNxpFeatureOptOn;
	short chip_delay_with_switch;
	short mic_index; // bit wise definition ordered from main mic to reference mic. Only one bit is set!! bit 0: o17, bit 1: o18, bit 2: o23, bit 3: o24, bit 4: o25, 
	
} AUDIO_NXP_SMARTPA_PARAMETER_STRUCT;

typedef struct _AUDIO_CUSTOM_HAC_PARAM_STRUCT
{
	/* speech enhancement */
	unsigned short speech_hac_mode_nb_para[16];
	/* WB speech enhancement */
	unsigned short speech_hac_mode_wb_para[16];

	/* speech input FIR */
	short 			sph_hac_in_fir[45];
	/* speech output FIR */
	short 			sph_hac_out_fir[45];

	/* WB speech input FIR */
	short 			sph_hac_wb_in_fir[90];
	/* WB speech output FIR */
	short 			sph_hac_wb_out_fir[90];

} AUDIO_CUSTOM_HAC_PARAM_STRUCT;


#endif
