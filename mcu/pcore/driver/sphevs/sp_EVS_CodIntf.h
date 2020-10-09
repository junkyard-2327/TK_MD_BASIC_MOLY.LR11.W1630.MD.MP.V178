/*******************************************************************************
 *
 * Filename:
 * ---------
 *	sp_EVS_CodIntf.h
 *
 * Description:
 * ------------
 *  EDrv and codec interface
 *
 * Author:
 * -------
 * -------
 *
*******************************************************************************/
#ifndef SP_EVS_COMMON_H
#define SP_EVS_COMMON_H

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"

#include "l1audio.h"

#define HB_LEN             320   // 320 bytes
#define SPEECH_GOOD_FRAME  0x6b21
#define SPEECH_BAD_FRAME   0x6b20

typedef struct{
    kal_uint16 u2BFI;
    kal_uint16 u2Len;
    kal_uint8 *pucHB;
} EVS_Enc_Pkt;

typedef struct{
    kal_uint16 u2DSP_sampling_rate;
    kal_uint16 u2Max_rate;
    volatile kal_uint16 *pPCMBuf;
    kal_uint16 bDtx;
    kal_uint16 bSIDFst;
    kal_uint16 u2Band;
    kal_uint32 u4Bit_rate;
    EVS_Enc_Pkt EncPkt;
    EVS_ENC_CA_PARAMETER EncCA;
}EVS_Enc_Par;

typedef struct{
    kal_uint16 u2BFI;
    kal_uint16 u2Len;
    kal_uint8 *pucHB;
} EVS_Dec_Pkt;

//#ifndef __EVS_SUPPORT__
typedef struct{
    kal_uint16 u2DSP_sampling_rate;
    volatile kal_uint16 *pPCMBuf;
    EVS_Dec_Pkt DecPkt;
    EVS_DEC_CA_PARAMETER DecCA;
}EVS_Dec_Par;
//#endif

extern EVS_Enc_Par gEVS_EncPar;
extern EVS_Dec_Par gEVS_DecPar;

extern kal_uint8 gaucEVS_EncHB[320];
extern kal_uint8 gaucEVS_DecHB[320];

extern void EVS_Enc_Rst(EVS_Enc_Par *EVS_Par);
extern void EVS_Enc_Run(EVS_Enc_Par *EVS_Par);
extern void EVS_Dec_Rst(EVS_Dec_Par *EVS_Par);
extern void EVS_Dec_Run(EVS_Dec_Par *EVS_Par);

#endif