
#ifndef _SP_ENHANCE_H
#define _SP_ENHANCE_H

#include "l1aud_common_def.h"
#include "sal_def.h"

uint8 SPE_GetSpeechMode(void);

void L1SP_EnableSpeechEnhancement( bool enable );
bool spe_isSpeFweOn(void);


kal_uint16 *SPE_getAllWbSpeechModePara(void);
kal_int16 *SPE_getAllWbSpeechFirCoeff_InputOnly(void);
kal_int16 *SPE_getAllWbSpeechFirCoeff_OutputOnly(void);


void SPE_LoadSpeechPara( uint16 c_para[NUM_COMMON_PARAS], uint16 m_para[NUM_MODE_PARAS],uint16 v_para[NUM_VOL_PARAS],
	uint16 m_paraWb[NUM_MODE_PARAS]);

void spe_updateSpeAppMask(uint8 updateFlags, bool enable);

void spe_updateSpeUsrMaskWithWholeValue(uint16 newValue);
void spe_updateSpeUsrSubMaskWithWholeValue(uint16 newValue);

void spe_setHacModeNeeded(bool isNeed);
void SPE_MagiClarityData(short MagiClarityData[32]);

// ----------------------------------------------------------------------------
// DSP filter/function related parameter/coefficient setting
// ----------------------------------------------------------------------------
void spe_setMagiCon(void);
void spe_DisableMagiCon(void);
void spe_setNotchFilterParam(int16 *param, bool is2In1Spk);

void SPE_SetActiveEchoRefInfo(uint16 sphMode);
void SPE_SetEchoRefInfo(bool isEchoRefOn, uint16 echoRefMicIndex, uint16 delayAndSwitch4Dsp, uint16 sphMode);
bool SPE_AgcInfo_IsNxpPaOn(void);
bool SPE_AgcInfo_IsUSBEchoRefOn(void);
void spe_AGC_config(bool isOn, bool isEchoRefOn);

void SetSpeechEnhancement(bool ec);
void SPE_WaitSPEDynready( Sal_Enh_Dyn_Sta_t DYN_Sta ) ;
void spe_AGC_config_dc(bool isOn, bool isEchoRefOn);


typedef enum{
	SpeechEnh_All = 0, //default path : UL+DL
	SpeechEnh_UL, 
	SpeechEnh_DL, 
}SpeechEnh_path; 
void SetSPEnhancePath(uint8 path);


#endif
