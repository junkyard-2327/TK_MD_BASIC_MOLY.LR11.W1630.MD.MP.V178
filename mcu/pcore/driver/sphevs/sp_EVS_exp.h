/*******************************************************************************
 *
 * Filename:
 * ---------
 *	sp_EVS_exp.h
 *
 * Description:
 * ------------
 *  EDrv extenal interface for SDrv
 *
 * Author:
 * -------
 * -------
 *
*******************************************************************************/

#ifndef SP_EVS_EXP_H
#define SP_EVS_EXP_H

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"

#include "l1audio.h"

#define EVS_CAPABILITY_BW (SP4G_CODEC_EVS_16K)
#define EVS_PCM_BW        (SP4G_CODEC_EVS_16K)

typedef struct {
    LOCAL_PARA_HDR
    EVS_ENCODER_PARAMETER *pEVS_EncPar;
    kal_int16 *pPCMBuf;
}EVS_Enc_ILM;

typedef struct {
    LOCAL_PARA_HDR
    SP4G_Codec frame_type;
    EVS_DECODER_PARAMETER *pEVS_DecPar;
    kal_uint8 *pHB;
    kal_uint32 u4HBLen;
}EVS_Dec_ILM;

void EDrv_encoder_clean(void);
void EDrv_encoder_execute(EVS_ENCODER_PARAMETER *pEVS_Enc_Par, kal_int16 *pPCMBuf);
void EDrv_decoder_clean(void);
void EDrv_decoder_execute(SP4G_Codec frame_type, EVS_DECODER_PARAMETER *pEVS_DecPar, kal_uint8 *pHB, kal_uint32 u4HBLen);
void EDrv_decoder_execute_ARM7(SP4G_Codec frame_type, EVS_DECODER_PARAMETER *pEVS_DecPar, kal_uint8 *pHB, kal_uint32 u4HBLen, kal_int16 *pPCMBuf);
SP4G_Codec EDrv_encoder_get_TXCodecMode(void);
kal_uint8* EDrv_encoder_get_HBAddr(void); 
kal_int32 EDrv_encoder_get_HBBitLength(void);
kal_int32 EDrv_encoder_get_IsULReady(void);
void EDrv_encoder_set_ULEmpty(void);
kal_int32 EDrv_encoder_get_IsSIDFirst(void);

#endif