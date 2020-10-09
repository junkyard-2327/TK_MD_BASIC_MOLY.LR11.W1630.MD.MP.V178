#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "reg_base.h"
#include "md2g_drv.h"
#include "string.h"

#include "sp_EVS_trc.h"

#include "sp_EVS_drv.h"
#include "sp_EVS_exp.h"
#include "sp_EVS_CodIntf.h"
#include "sphevs_msgid.h"

//#include "pccif_dev.h"
//#include "pccif_if.h"
//#include "pccif_arm7_system.h"
#include "cache_sw.h"
#include "SST_intrCtrl.h"

kal_uint32 SaveAndSetIRQMask(void);
void RestoreIRQMask(kal_uint32);

SP4G_Codec EDrv_encoder_get_TXCodecMode(void)
{
	return gEVS_DrvPar.Enc_Codec;
}

kal_uint8* EDrv_encoder_get_HBAddr(void)
{
	return gEVS_EncPar.EncPkt.pucHB;
}

kal_int32 EDrv_encoder_get_HBBitLength(void)
{
	return gEVS_EncPar.EncPkt.u2Len;  //provide bu codec
}

kal_int32 EDrv_encoder_get_IsULReady(void)
{
	return gEVS_DrvPar.bEnc_Rdy;
}

void EDrv_encoder_set_ULEmpty(void)
{
	gEVS_DrvPar.bEnc_Rdy = false;
}

kal_int32 EDrv_encoder_get_IsSIDFirst(void)
{
	kal_trace(TRACE_GROUP_EVS, EVS_ENC_SID_FST, gEVS_EncPar.bSIDFst);
	return gEVS_EncPar.bSIDFst;
}

void EDrv_encoder_clean(void)
{
	gEVS_DrvPar.bEncInitEna = true;
}


void EDrv_encoder_execute(EVS_ENCODER_PARAMETER *pEVS_EncPar, kal_int16 *pPCMBuf)
{
#ifdef __EVS_SUPPORT__
    EVS_Enc_ILM *EncRstILM;
    EVS_Enc_ILM *EncRunILM;
    
    kal_uint32 savedMask;
    
    //Check Enc running status
    if(0 == gEVS_DrvPar.u2Enc_Sta)
    {
        if(true == gEVS_DrvPar.bEncInitEna)
        {
            EncRstILM = (EVS_Enc_ILM *) construct_local_para( sizeof(EVS_Enc_ILM), TD_CTRL/*TD_RESET*/ );
            EncRstILM->pEVS_EncPar = pEVS_EncPar;
            EncRstILM->pPCMBuf = pPCMBuf;
            //EVS Enc Rst: Send ILM to EVS task 
            msg_send6(MOD_L1SP, MOD_SPH_EVS, 0x0, MSG_ID_SPH_EVS_ENC_RST, (local_para_struct *)EncRstILM, NULL);
            kal_trace(TRACE_GROUP_EVS, EVS_ENC_RST_MSG);
            gEVS_DrvPar.bEncInitEna = false;
        }
        
        EncRunILM = (EVS_Enc_ILM *) construct_local_para( sizeof(EVS_Enc_ILM), TD_CTRL/*TD_RESET*/ );
        EncRunILM->pEVS_EncPar = pEVS_EncPar;
        EncRunILM->pPCMBuf = pPCMBuf;
        //EVS Enc Run: Send ILM to EVS task
        savedMask = SaveAndSetIRQMask();
        gEVS_DrvPar.u2Enc_Sta = 1;
        RestoreIRQMask(savedMask);
        msg_send6(MOD_L1SP, MOD_SPH_EVS, 0x0, MSG_ID_SPH_EVS_ENC_RUN, (local_para_struct *)EncRunILM, NULL);
        kal_trace(TRACE_GROUP_EVS, EVS_ENC_RUN_MSG);
    }
    else
    {
        //kal_trace(TRACE_GROUP_EVS, EVS_ENC_RUN_HRT_FAIL);
        kal_prompt_trace(MOD_L1SP, "EVS_ENC_RUN_HRT_FAIL");
    }
#endif //__EVS_SUPPORT__
}

void EDrv_decoder_clean(void)
{
    gEVS_DrvPar.bDecInitEna = true;
}

void EDrv_decoder_execute(SP4G_Codec frame_type, EVS_DECODER_PARAMETER *pEVS_DecPar, kal_uint8 *pHB, kal_uint32 u4HBLen)
{
#ifdef __EVS_SUPPORT__

    EVS_Dec_ILM *DecRstILM;
    EVS_Dec_ILM *DecRunILM;

    kal_uint32 savedMask;

    //Check Dec running status
    if(0 == gEVS_DrvPar.u2Dec_Sta)
    { 
        if(true == gEVS_DrvPar.bDecInitEna)
        {
            DecRstILM = (EVS_Dec_ILM *) construct_local_para( sizeof(EVS_Dec_ILM), TD_CTRL/*TD_RESET*/ );
            DecRstILM->frame_type = frame_type;
            DecRstILM->pEVS_DecPar = pEVS_DecPar;
            DecRstILM->pHB = pHB;
            DecRstILM->u4HBLen = u4HBLen;
            //EVS Dec Rst: Send ILM to EVS task 
            msg_send6(MOD_L1SP, MOD_SPH_EVS, 0x0, MSG_ID_SPH_EVS_DEC_RST, (local_para_struct *)DecRstILM, NULL);
            kal_trace(TRACE_GROUP_EVS, EVS_DEC_RST_MSG);
            gEVS_DrvPar.bDecInitEna = false;
        }
        
        DecRunILM = (EVS_Dec_ILM *) construct_local_para( sizeof(EVS_Dec_ILM), TD_CTRL/*TD_RESET*/ );
        DecRunILM->frame_type = frame_type;
        DecRunILM->pEVS_DecPar = pEVS_DecPar;
        DecRunILM->pHB = pHB;
        DecRunILM->u4HBLen = u4HBLen;
        
        //EVS Dec Run: Send ILM to EVS task 
        savedMask = SaveAndSetIRQMask();
        gEVS_DrvPar.u2Dec_Sta = 1;
        RestoreIRQMask(savedMask);
        msg_send6(MOD_L1SP, MOD_SPH_EVS, 0x0, MSG_ID_SPH_EVS_DEC_RUN, (local_para_struct *)DecRunILM, NULL);
        kal_trace(TRACE_GROUP_EVS, EVS_DEC_RUN_MSG);
    }
    else
    {
        //kal_trace(TRACE_GROUP_EVS, EVS_DEC_RUN_HRT_FAIL);
        kal_prompt_trace(MOD_L1SP, "EVS_DEC_RUN_HRT_FAIL");
    }
    
#endif //__EVS_SUPPORT__
}
