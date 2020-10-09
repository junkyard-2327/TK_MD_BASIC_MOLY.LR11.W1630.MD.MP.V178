/*******************************************************************************
 *
 * Filename:
 * ---------
 *	sp_EVS_drv.h
 *
 * Description:
 * ------------
 *  EDrv (ENC) global internal variables
 *
 * Author:
 * -------
 * -------
 *
*******************************************************************************/

#ifndef SP_EVS_DRV_H
#define SP_EVS_DRV_H

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"

#include "l1audio.h"

#define true         (kal_bool)(1==1)
#define false        (kal_bool)(1==0)

#define EVS_PRI280_LEN        56
#define EVS_PRI720_LEN        144
#define EVS_PRI800_LEN        160
#define EVS_PRI960_LEN        192
#define EVS_PRI1320_LEN       264
#define EVS_PRI1640_LEN       328
#define EVS_PRI2440_LEN       488
#define EVS_PRI3200_LEN       640
#define EVS_PRI4800_LEN       960
#define EVS_PRI6400_LEN       1280
#define EVS_PRI9600_LEN       1920
#define EVS_PRI12800_LEN      2560
#define EVS_PRI_NODATA_LEN    0
#define EVS_AWBIO_NODATA_LEN  0
#define EVS_PRI_SID_LEN       48
#define EVS_AWBIO_SID_UPDATE_LEN     35
#define EVS_AWBIO_SID_FIRST_LEN      0
#define EVS_UNDEF_RATE    0x44

typedef enum {
    EVS_AWB660 = 11,
    EVS_AWB885,
    EVS_AWB1265,
    EVS_AWB1425, 
    EVS_AWB1585, 
    EVS_AWB1825, 
    EVS_AWB1985, 
    EVS_AWB2305, 
    EVS_AWB2385, 
    EVS_PRI590,
    EVS_PRI720,
    EVS_PRI800,
    EVS_PRI960,
    EVS_PRI1320,
    EVS_PRI1640,
    EVS_PRI2440,
    EVS_PRI3200,
    EVS_PRI4800,
    EVS_PRI6400,
    EVS_PRI9600,
    EVS_PRI12800
    
}EVS_VM_ID;

typedef struct{
    kal_uint32 u4EncFrameCntr, u4DecFrameCntr;
    kal_uint32 u4EncMaxCyc, u4DecMaxCyc;
    kal_uint32 u4EncTotalCyc, u4DecTotalCyc;
    
}EVS_Dbg;

typedef struct{
    SP4G_Codec Enc_Codec;
    SP4G_Codec VM_Codec_ID;
    kal_uint16 bEnc_Rdy;
    kal_uint16 bDec_Rdy;
    kal_uint16 bDtx_Pre;
    kal_uint16 bCA_ena_Pre;
    kal_uint16 bEncInitEna, bDecInitEna;
    kal_uint16 bEncInitDone, bDecInitDone;
    kal_uint16 bDec_test; // only for test
    kal_uint16 bEnc_test; // only for test
    kal_uint16 u2Enc_ID;
    kal_uint16 u2Enc_BW;
    kal_uint16 u2Enc_Rate;
    kal_uint16 u2Enc_Sta, u2Dec_Sta;
    kal_uint8  ucDVFS_Hdl_Num;
    EVS_Dbg EVSDbg;
}EVS_Drv_Par;

typedef struct{
    kal_uint32 u4DSP_sampling_rate;
    kal_uint32 u4BFI;
    kal_uint32 u4Len;
    kal_uint32 u4FrameMode;
    kal_uint8  aucHB[320];
}EVS_Drv2_Par;

extern EVS_Drv_Par gEVS_DrvPar;
extern EVS_Drv2_Par gEVS_Drv2Par;

#endif