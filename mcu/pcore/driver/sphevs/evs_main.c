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
 * Filename:
 * ---------
 *   evs_main.c
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This file includes primary functions of sph EVS task.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "string.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "cache_sw.h"
#include "SST_intrCtrl.h"
#include "sphevs_msgid.h"
#include "sp_EVS_drv.h"
#include "sp_EVS_exp.h"
#include "sp_EVS_CodIntf.h"
#include "sp_EVS_trc.h"
#include "sal_def.h"
#include "sal_exp.h" 
#include "swip_export.h" //security

#include "dvfs_interface.h"
#include "pcore_dvfs_public.h"

//#define EVS_EVALUATION
kal_int32 yh_EVS_Dbg[20] = {0}; 
kal_uint32 EDrv_bit_rate_extract(SP4G_Codec EVSCod);
kal_uint16 EDrv_Enc_Len_To_Rate(kal_uint16 u2Len);
static void sph_evs_main(task_entry_struct *task_entry_ptr);
static kal_bool sph_evs_init(void);
static void sph_evs_process(ilm_struct *ilm_ptr);
static void EDrv_encoder_set_par(EVS_Enc_ILM *pEncILM);
static void EDrv_decoder_set_par(EVS_Dec_ILM *pDecILM);

kal_uint32 SaveAndSetIRQMask(void);
void RestoreIRQMask(kal_uint32);

kal_uint16 SBR = 0;//security
kal_int16 EVS_Dec_PCM[640];

extern const uint16 EVS_Primary_FrameBitLength[16];
extern const uint16 EVS_AWB_RAB_subflow[16][5];
extern SP4G_CODEC_EVS_AWB_SID_TYPE EVS_decoder_get_SID_type(void);

/*************************************************************************
* FUNCTION
*  sph_evs_create
*
* DESCRIPTION
*  This function implements sph evs entity's create handler.
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool sph_evs_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct sph_evs_handler_info = 
    {
        sph_evs_main,  /* task entry function */
        sph_evs_init,       /* task initialization function */
        NULL       /* task reset handler */
    };

    *handle = (comptask_handler_struct*) & sph_evs_handler_info;
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  sph_evs_init
*
* DESCRIPTION
*  Speech EVS Task initialization function.
*
* PARAMETERS
* IN      task_indx
* RETURNS
*  kal_bool
*
* GLOBALS AFFECTED
*
*************************************************************************/

static kal_bool sph_evs_init(void)
{
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  sph_evs_main
*
* DESCRIPTION
*  Speech EVS Task main function.
*
* PARAMETERS
* IN      task_indx
* RETURNS
*  kal_bool
*
* GLOBALS AFFECTED
*
*************************************************************************/

static void sph_evs_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct current_ilm;
    
    while(1)
    {
        msg_receive_extq(&current_ilm);
        kal_set_active_module_id(MOD_SPH_EVS);
        sph_evs_process((void*)&current_ilm); 
        destroy_ilm(&current_ilm);
    }
}

static void sph_evs_process(ilm_struct *ilm_ptr)
{
    kal_uint32 u4cycleCnt0 = 0, u4cycleCnt1 = 0, u4duration = 0;
    kal_uint32 u4AveCyc = 0;
    kal_uint8 *pucHB;
    kal_int16 *i2PCM_Buf;
    uint16 fsize;
    volatile uint16 *ptr16_FD216;
    uint16 *ptr16;
    kal_uint32 i;
    kal_uint16 u2HBLenCntr;
    
    uint32 savedMask;
    
    EVS_Enc_ILM *pEncRstILM;
    EVS_Dec_ILM *pDecRstILM;
    EVS_Enc_ILM *pEncRunILM;
    EVS_Dec_ILM *pDecRunILM;
    
    SP4G_CODEC_EVS_AWB_SID_TYPE AWBIO_SID_Type;

#ifdef __EVS_SUPPORT__    
    if(MSG_ID_SPH_EVS_ENC_RST == ilm_ptr->msg_id)
    {
        pEncRstILM = (EVS_Enc_ILM *)(ilm_ptr->local_para_ptr);        
        EDrv_encoder_set_par(pEncRstILM);
        
        kal_trace(TRACE_GROUP_EVS, EVS_ENC_RST, gEVS_EncPar.u2DSP_sampling_rate, gEVS_EncPar.u2Max_rate, gEVS_EncPar.pPCMBuf, 
                                                gEVS_EncPar.bDtx, gEVS_EncPar.u4Bit_rate, gEVS_EncPar.EncPkt.pucHB, gEVS_EncPar.EncCA.enable, 
                                                gEVS_EncPar.EncCA.rf_fec_indicator, gEVS_EncPar.EncCA.rf_fec_offset);
        EVS_Enc_Rst(&gEVS_EncPar);
        gEVS_DrvPar.bEncInitDone = true;
        gEVS_DrvPar.EVSDbg.u4EncFrameCntr = 0;
        gEVS_DrvPar.EVSDbg.u4EncMaxCyc = 0;
        gEVS_DrvPar.EVSDbg.u4EncTotalCyc = 0;
        savedMask = SaveAndSetIRQMask();
        gEVS_DrvPar.u2Enc_Sta = 0;
        RestoreIRQMask(savedMask);
    }
    else if(MSG_ID_SPH_EVS_DEC_RST == ilm_ptr->msg_id)
    {
        pDecRstILM = (EVS_Dec_ILM *)(ilm_ptr->local_para_ptr);
        EDrv_decoder_set_par(pDecRstILM);
        kal_trace(TRACE_GROUP_EVS, EVS_DEC_RST, gEVS_DecPar.u2DSP_sampling_rate, gEVS_DecPar.pPCMBuf, gEVS_DecPar.DecPkt.u2Len, gEVS_DecPar.DecPkt.u2BFI, 
                                                gEVS_DecPar.DecPkt.pucHB, gEVS_DecPar.DecCA.FrameMode); 
        EVS_Dec_Rst(&gEVS_DecPar);
        gEVS_DrvPar.bDecInitDone = true;
        gEVS_DrvPar.EVSDbg.u4DecFrameCntr = 0;
        gEVS_DrvPar.EVSDbg.u4DecMaxCyc = 0;
        gEVS_DrvPar.EVSDbg.u4DecTotalCyc = 0;
        savedMask = SaveAndSetIRQMask();
        gEVS_DrvPar.u2Dec_Sta = 0;
        RestoreIRQMask(savedMask);
    }
    else if(MSG_ID_SPH_EVS_ENC_RUN == ilm_ptr->msg_id)
    {
        pEncRunILM = (EVS_Enc_ILM *)(ilm_ptr->local_para_ptr);        
        EDrv_encoder_set_par(pEncRunILM);
        
        kal_trace(TRACE_GROUP_EVS, EVS_ENC_RUN, gEVS_EncPar.u2DSP_sampling_rate, gEVS_EncPar.u2Max_rate, gEVS_EncPar.pPCMBuf, 
                                                gEVS_EncPar.bDtx, gEVS_EncPar.u4Bit_rate, gEVS_EncPar.EncPkt.pucHB, gEVS_EncPar.EncCA.enable, 
                                                gEVS_EncPar.EncCA.rf_fec_indicator, gEVS_EncPar.EncCA.rf_fec_offset);        

        kal_trace(TRACE_GROUP_EVS, EVS_ENC_ID, gEVS_DrvPar.u2Enc_ID, gEVS_DrvPar.u2Enc_BW, gEVS_DrvPar.u2Enc_Rate);
        
        if((gEVS_DrvPar.bDtx_Pre != gEVS_EncPar.bDtx) || (gEVS_DrvPar.bCA_ena_Pre != gEVS_EncPar.EncCA.enable))
        {
            EVS_Enc_Rst(&gEVS_EncPar);
            gEVS_DrvPar.bEncInitDone = true;
        }
    #ifdef EVS_EVALUATION    
        GET_CURRENT_TIME(u4cycleCnt0);
    #endif
        DVFS_SetScenario(gEVS_DrvPar.ucDVFS_Hdl_Num, DVFS_SCENARIO_EVS_CODEC_ON);        
        EVS_Enc_Run(&gEVS_EncPar); 
        kal_prompt_trace(MOD_L1SP, "SWIP_error_msg = %d", yh_EVS_Dbg[0]);        
        DVFS_SetScenario(gEVS_DrvPar.ucDVFS_Hdl_Num, DVFS_SCENARIO_EVS_CODEC_OFF);
    #ifdef EVS_EVALUATION 
        GET_CURRENT_TIME(u4cycleCnt1);
        GET_DURATION(u4duration, u4cycleCnt0, u4cycleCnt1);
        
        gEVS_DrvPar.EVSDbg.u4EncFrameCntr++;
        u4duration = u4duration/20000;
        if(u4duration > gEVS_DrvPar.EVSDbg.u4EncMaxCyc)
        {
            gEVS_DrvPar.EVSDbg.u4EncMaxCyc = u4duration;
        }
        gEVS_DrvPar.EVSDbg.u4EncTotalCyc += u4duration;
        u4AveCyc = gEVS_DrvPar.EVSDbg.u4EncTotalCyc/gEVS_DrvPar.EVSDbg.u4EncFrameCntr;
        
        kal_trace(TRACE_GROUP_EVS, EVS_ENC_TIME, gEVS_DrvPar.EVSDbg.u4EncMaxCyc, u4AveCyc);
    #endif
        kal_trace(TRACE_GROUP_EVS, EVS_ENC_DBG, gEVS_EncPar.EncPkt.u2Len, gEVS_EncPar.EncPkt.u2BFI, gEVS_EncPar.u2Band);	
        pucHB = gEVS_EncPar.EncPkt.pucHB;
        if((gEVS_EncPar.EncPkt.u2Len & 0x7) != 0)
        {
            u2HBLenCntr = gEVS_EncPar.EncPkt.u2Len/8 + 2;
        }
        else
        {
            u2HBLenCntr = gEVS_EncPar.EncPkt.u2Len/8;
        }
        for(i = 0; i < u2HBLenCntr; i++)
        {
            kal_trace(TRACE_GROUP_EVS, EVS_ENC_HB, *pucHB);
            pucHB++;
        }
        
        //Get codec ID
        //Check AWBIO mode
        if(SP4G_CODEC_EVS_AWB_ID == gEVS_DrvPar.u2Enc_ID) // AWBIO mode
        {
            if(EVS_AWBIO_NODATA_LEN == gEVS_EncPar.EncPkt.u2Len)
            {
                gEVS_DrvPar.Enc_Codec = SP4G_CODEC_EVS_AWB_00_00_NODATA;
            }
            else if(EVS_AWBIO_SID_UPDATE_LEN == gEVS_EncPar.EncPkt.u2Len)
            {
                gEVS_DrvPar.Enc_Codec = SP4G_CODEC_EVS_AWB_02_00_SID;
            }
            else if(EVS_AWB_RAB_subflow[gEVS_DrvPar.u2Enc_Rate][4] == gEVS_EncPar.EncPkt.u2Len)
            {
                // gEVS_DrvPar.Enc_Codec does not need to change
            }
            else
            {
                kal_trace(TRACE_GROUP_EVS, EVS_ENC_COD_UND);
            }            
        }
        //Check primary mode
        else if(EVS_PRI_NODATA_LEN == gEVS_EncPar.EncPkt.u2Len)
        {
            gEVS_DrvPar.Enc_Codec = gEVS_DrvPar.u2Enc_ID + (gEVS_EncPar.u2Band << 4) + SP4G_CODEC_EVS_000_0_NODATA;
        }
        else if(EVS_PRI_SID_LEN == gEVS_EncPar.EncPkt.u2Len)
        {
            gEVS_DrvPar.Enc_Codec = gEVS_DrvPar.u2Enc_ID + (gEVS_EncPar.u2Band << 4) + SP4G_CODEC_EVS_002_4_SID;
        }
        else if(EDrv_Enc_Len_To_Rate(gEVS_EncPar.EncPkt.u2Len) != EVS_UNDEF_RATE)
        {
            gEVS_DrvPar.Enc_Codec = gEVS_DrvPar.u2Enc_ID + (gEVS_EncPar.u2Band << 4) + EDrv_Enc_Len_To_Rate(gEVS_EncPar.EncPkt.u2Len); 
        }
        else
        {
            kal_trace(TRACE_GROUP_EVS, EVS_ENC_COD_UND);
        }
        kal_trace(TRACE_GROUP_EVS, EVS_ENC_COD, gEVS_DrvPar.Enc_Codec);
        gEVS_DrvPar.bDtx_Pre = gEVS_EncPar.bDtx;
        gEVS_DrvPar.bCA_ena_Pre = gEVS_EncPar.EncCA.enable;
        gEVS_DrvPar.bEnc_Rdy = true;
        savedMask = SaveAndSetIRQMask();
        gEVS_DrvPar.u2Enc_Sta = 0;
        RestoreIRQMask(savedMask);
    }
    else if(MSG_ID_SPH_EVS_DEC_RUN == ilm_ptr->msg_id)
    {
        pDecRstILM = (EVS_Dec_ILM *)(ilm_ptr->local_para_ptr);
        EDrv_decoder_set_par(pDecRstILM);
        
        AWBIO_SID_Type = EVS_decoder_get_SID_type();
        
        if(40 == gEVS_DecPar.DecPkt.u2Len)
        {
            if(SP4G_CODEC_EVS_AWB_SID_TYPE_FIRST == AWBIO_SID_Type)
            {
                gEVS_DecPar.DecPkt.u2BFI = SPEECH_GOOD_FRAME;
                gEVS_DecPar.DecPkt.u2Len = EVS_AWBIO_SID_FIRST_LEN;           
            }            
            else if(SP4G_CODEC_EVS_AWB_SID_TYPE_UPDATE == AWBIO_SID_Type)
            {
                gEVS_DecPar.DecPkt.u2Len = EVS_AWBIO_SID_UPDATE_LEN;
            }
            else if(SP4G_CODEC_EVS_AWB_SID_TYPE_NONSID == AWBIO_SID_Type)
            {
                ASSERT(0);
            }            
        }        
        else if((EVS_PRI_NODATA_LEN == gEVS_DecPar.DecPkt.u2Len) || (EVS_AWBIO_NODATA_LEN == gEVS_DecPar.DecPkt.u2Len))
        {
            gEVS_DecPar.DecPkt.u2BFI = SPEECH_BAD_FRAME;
        }
        
        kal_trace(TRACE_GROUP_EVS, EVS_DEC_RUN, gEVS_DecPar.u2DSP_sampling_rate, gEVS_DecPar.pPCMBuf, gEVS_DecPar.DecPkt.u2Len, gEVS_DecPar.DecPkt.u2BFI, 
                                                gEVS_DecPar.DecPkt.pucHB, gEVS_DecPar.DecCA.FrameMode);

        pucHB = gEVS_DecPar.DecPkt.pucHB;
                
        if((gEVS_DecPar.DecPkt.u2Len & 0x7) != 0)
        {
            u2HBLenCntr = gEVS_DecPar.DecPkt.u2Len/8 + 2;
        }
        else
        {
            u2HBLenCntr = gEVS_DecPar.DecPkt.u2Len/8;
        }
        for(i = 0; i < u2HBLenCntr; i++)
        {
            kal_trace(TRACE_GROUP_EVS, EVS_DEC_HB, *pucHB);
            pucHB++;
        }
    #ifdef EVS_EVALUATION 
        GET_CURRENT_TIME(u4cycleCnt0);
    #endif
        DVFS_SetScenario(gEVS_DrvPar.ucDVFS_Hdl_Num, DVFS_SCENARIO_EVS_CODEC_ON);
        EVS_Dec_Run(&gEVS_DecPar);
        DVFS_SetScenario(gEVS_DrvPar.ucDVFS_Hdl_Num, DVFS_SCENARIO_EVS_CODEC_OFF);
    #ifdef EVS_EVALUATION
        GET_CURRENT_TIME(u4cycleCnt1);
        GET_DURATION(u4duration, u4cycleCnt0, u4cycleCnt1);
        u4duration = u4duration/20000;
        gEVS_DrvPar.EVSDbg.u4DecFrameCntr++;
        if(u4duration > gEVS_DrvPar.EVSDbg.u4DecMaxCyc)
        {
            gEVS_DrvPar.EVSDbg.u4DecMaxCyc = u4duration;
        }
        gEVS_DrvPar.EVSDbg.u4DecTotalCyc += u4duration;
        u4AveCyc = gEVS_DrvPar.EVSDbg.u4DecTotalCyc/gEVS_DrvPar.EVSDbg.u4DecFrameCntr;
        kal_trace(TRACE_GROUP_EVS, EVS_DEC_TIME, gEVS_DrvPar.EVSDbg.u4DecMaxCyc, u4AveCyc);
    #endif
        
        fsize = SAL_PcmEx_GetBufLen(SAL_PCMEX_EXTCOD_BUF_DL);
        ptr16_FD216 = SAL_PcmEx_GetBuf(SAL_PCMEX_EXTCOD_BUF_DL);
        ptr16 = gEVS_DecPar.pPCMBuf;
        for(i=0; i<fsize; i++)
        {
            ptr16_FD216[i] = ptr16[i];
        }
        savedMask = SaveAndSetIRQMask();
        gEVS_DrvPar.u2Dec_Sta = 0;
        RestoreIRQMask(savedMask);
    }
#endif //__EVS_SUPPORT__
}

static void EDrv_encoder_set_par(EVS_Enc_ILM *pEncILM)
{
    //EDrv info	
    gEVS_DrvPar.Enc_Codec = pEncILM->pEVS_EncPar->codec;	
    gEVS_DrvPar.u2Enc_ID = GET_SP4G_CODEC_ENUM_EVS_ID(pEncILM->pEVS_EncPar->codec);
    gEVS_DrvPar.u2Enc_BW = GET_SP4G_CODEC_ENUM_EVS_BW(pEncILM->pEVS_EncPar->codec);
    gEVS_DrvPar.u2Enc_Rate = GET_SP4G_CODEC_ENUM_EVS_RATE(pEncILM->pEVS_EncPar->codec);
        
    gEVS_EncPar.u2DSP_sampling_rate = (kal_uint16)(pEncILM->pEVS_EncPar->EVS_PCM_bw);
    gEVS_EncPar.u2Max_rate = (kal_uint16)((pEncILM->pEVS_EncPar->EVS_network_request_bw) >> 4);
    gEVS_EncPar.pPCMBuf = (volatile kal_uint16 *)pEncILM->pPCMBuf;
    gEVS_EncPar.bDtx = (kal_uint16)(pEncILM->pEVS_EncPar->DTX);
    gEVS_EncPar.u4Bit_rate = EDrv_bit_rate_extract(gEVS_DrvPar.Enc_Codec);
    gEVS_EncPar.EncPkt.pucHB = &gaucEVS_EncHB[0];
    
    // CA parameter
    gEVS_EncPar.EncCA.enable = pEncILM->pEVS_EncPar->EVS_CA_Par.enable;
    gEVS_EncPar.EncCA.rf_fec_indicator = pEncILM->pEVS_EncPar->EVS_CA_Par.rf_fec_indicator;
    gEVS_EncPar.EncCA.rf_fec_offset = pEncILM->pEVS_EncPar->EVS_CA_Par.rf_fec_offset;
}

static void EDrv_decoder_set_par(EVS_Dec_ILM *pDecILM)
{
    gEVS_DecPar.u2DSP_sampling_rate = (kal_uint16)(pDecILM->pEVS_DecPar->EVS_PCM_bw);
    gEVS_DecPar.pPCMBuf = (volatile kal_uint16 *)&EVS_Dec_PCM[0];
    gEVS_DecPar.DecPkt.u2Len = (kal_uint16) pDecILM->u4HBLen;
    gEVS_DecPar.DecPkt.u2BFI = SPEECH_GOOD_FRAME;
    gEVS_DecPar.DecPkt.pucHB = pDecILM->pHB;
    
    // CA parameter
    gEVS_DecPar.DecCA.FrameMode = pDecILM->pEVS_DecPar->EVS_CA_Par.FrameMode;	
}

kal_uint32 EDrv_bit_rate_extract(SP4G_Codec EVSCod)
{
	uint32 u4Bit_rate = 0;
	gEVS_DrvPar.VM_Codec_ID = 0;
	switch(EVSCod)
	{		
		case SP4G_CODEC_EVS_08K_005_9:
		case SP4G_CODEC_EVS_16K_005_9:
		case SP4G_CODEC_EVS_32K_005_9:
		case SP4G_CODEC_EVS_48K_005_9:
			u4Bit_rate = 5900;
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI590;
			break;
			
		case SP4G_CODEC_EVS_AWB_06_60:
			u4Bit_rate = 6600;
			gEVS_DrvPar.VM_Codec_ID = EVS_AWB660;
			break;
			
		case SP4G_CODEC_EVS_08K_007_2:
		case SP4G_CODEC_EVS_16K_007_2:
		case SP4G_CODEC_EVS_32K_007_2:
		case SP4G_CODEC_EVS_48K_007_2:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI720;
			u4Bit_rate = 7200;
			break;
		
		case SP4G_CODEC_EVS_08K_008_0:
		case SP4G_CODEC_EVS_16K_008_0:
		case SP4G_CODEC_EVS_32K_008_0:
		case SP4G_CODEC_EVS_48K_008_0:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI800;
			u4Bit_rate = 8000;
			break;
			
		case SP4G_CODEC_EVS_AWB_08_85:
			gEVS_DrvPar.VM_Codec_ID = EVS_AWB885;
			u4Bit_rate = 8850;
			break;			
		
		case SP4G_CODEC_EVS_08K_009_6:
		case SP4G_CODEC_EVS_16K_009_6:
		case SP4G_CODEC_EVS_32K_009_6:
		case SP4G_CODEC_EVS_48K_009_6:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI960;
			u4Bit_rate = 9600;
			break;
		
		case SP4G_CODEC_EVS_AWB_12_65:
			gEVS_DrvPar.VM_Codec_ID = EVS_AWB1265;
			u4Bit_rate = 12650;
			break;			
		
		case SP4G_CODEC_EVS_08K_013_2:
		case SP4G_CODEC_EVS_16K_013_2:
		case SP4G_CODEC_EVS_32K_013_2:
		case SP4G_CODEC_EVS_48K_013_2:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI1320;
			u4Bit_rate = 13200;
			break;

		case SP4G_CODEC_EVS_AWB_14_25:
			gEVS_DrvPar.VM_Codec_ID = EVS_AWB1425;
			u4Bit_rate = 14250;
			break;

		case SP4G_CODEC_EVS_AWB_15_85:
			gEVS_DrvPar.VM_Codec_ID = EVS_AWB1585;
			u4Bit_rate = 15850;
			break;

		case SP4G_CODEC_EVS_08K_016_4:
		case SP4G_CODEC_EVS_16K_016_4:
		case SP4G_CODEC_EVS_32K_016_4:
		case SP4G_CODEC_EVS_48K_016_4:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI1640;
			u4Bit_rate = 16400;
			break;

		case SP4G_CODEC_EVS_AWB_18_25:
			gEVS_DrvPar.VM_Codec_ID = EVS_AWB1825;
			u4Bit_rate = 18250;
			break;

		case SP4G_CODEC_EVS_AWB_19_85:
			gEVS_DrvPar.VM_Codec_ID = EVS_AWB1985;
			u4Bit_rate = 19850;
			break;

		case SP4G_CODEC_EVS_AWB_23_05:
			gEVS_DrvPar.VM_Codec_ID = EVS_AWB2305;
			u4Bit_rate = 23050;
			break;

		case SP4G_CODEC_EVS_AWB_23_85:
			gEVS_DrvPar.VM_Codec_ID = EVS_AWB2385;
			u4Bit_rate = 23850;
			break;
		
		case SP4G_CODEC_EVS_08K_024_4:
		case SP4G_CODEC_EVS_16K_024_4:
		case SP4G_CODEC_EVS_32K_024_4:
		case SP4G_CODEC_EVS_48K_024_4:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI2440;
			u4Bit_rate = 24400;
			break;
			
		case SP4G_CODEC_EVS_08K_032_0:
		case SP4G_CODEC_EVS_16K_032_0:
		case SP4G_CODEC_EVS_32K_032_0:
		case SP4G_CODEC_EVS_48K_032_0:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI3200;
			u4Bit_rate = 32000;
			break;
			
		case SP4G_CODEC_EVS_08K_048_0:
		case SP4G_CODEC_EVS_16K_048_0:
		case SP4G_CODEC_EVS_32K_048_0:
		case SP4G_CODEC_EVS_48K_048_0:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI4800;
			u4Bit_rate = 48000;
			break;
			
		case SP4G_CODEC_EVS_08K_064_0:
		case SP4G_CODEC_EVS_16K_064_0:
		case SP4G_CODEC_EVS_32K_064_0:
		case SP4G_CODEC_EVS_48K_064_0:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI6400;
			u4Bit_rate = 64000;
			break;
		
		case SP4G_CODEC_EVS_08K_096_0:
		case SP4G_CODEC_EVS_16K_096_0:
		case SP4G_CODEC_EVS_32K_096_0:
		case SP4G_CODEC_EVS_48K_096_0:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI9600;
			u4Bit_rate = 96000;
			break;
		
		case SP4G_CODEC_EVS_08K_128_0:
		case SP4G_CODEC_EVS_16K_128_0:
		case SP4G_CODEC_EVS_32K_128_0:
		case SP4G_CODEC_EVS_48K_128_0:
			gEVS_DrvPar.VM_Codec_ID = EVS_PRI12800;
			u4Bit_rate = 128000;
			break;
			
		case SP4G_CODEC_EVS_08K_000_0_LOST:
		case SP4G_CODEC_EVS_08K_000_0_NODATA:
		case SP4G_CODEC_EVS_16K_000_0_LOST:
		case SP4G_CODEC_EVS_16K_000_0_NODATA:
		case SP4G_CODEC_EVS_32K_000_0_LOST:
		case SP4G_CODEC_EVS_32K_000_0_NODATA:
		case SP4G_CODEC_EVS_48K_000_0_LOST:
		case SP4G_CODEC_EVS_48K_000_0_NODATA:
		case SP4G_CODEC_EVS_AWB_00_00_LOST:
		case SP4G_CODEC_EVS_AWB_00_00_NODATA:
			u4Bit_rate = 0;
			break;

		default:
			ASSERT(0);
			break;
	}
	return u4Bit_rate;
}

kal_uint16 EDrv_Enc_Len_To_Rate(kal_uint16 u2Len)
{
    kal_uint16 u2Rate;
    switch(u2Len)
    {
    	  case EVS_PRI280_LEN:
    	      u2Rate = SP4G_CODEC_EVS_002_8;
    	      break;
        case EVS_PRI720_LEN: 
            u2Rate = SP4G_CODEC_EVS_007_2;
    	      break; 
        case EVS_PRI800_LEN:  
            u2Rate = SP4G_CODEC_EVS_008_0;
    	      break;
        case EVS_PRI960_LEN:  
            u2Rate = SP4G_CODEC_EVS_009_6;
    	      break;
        case EVS_PRI1320_LEN: 
            u2Rate = SP4G_CODEC_EVS_013_2;
    	      break;
        case EVS_PRI1640_LEN: 
            u2Rate = SP4G_CODEC_EVS_016_4;
    	      break;
        case EVS_PRI2440_LEN: 
            u2Rate = SP4G_CODEC_EVS_024_4;
    	      break;
        case EVS_PRI3200_LEN: 
            u2Rate = SP4G_CODEC_EVS_032_0;
    	      break;
        case EVS_PRI4800_LEN: 
            u2Rate = SP4G_CODEC_EVS_048_0;
    	      break;
        case EVS_PRI6400_LEN: 
            u2Rate = SP4G_CODEC_EVS_064_0;
    	      break;
        case EVS_PRI9600_LEN: 
            u2Rate = SP4G_CODEC_EVS_096_0;
    	      break;
        case EVS_PRI12800_LEN:
            u2Rate = SP4G_CODEC_EVS_128_0;
    	      break;
        default:
            u2Rate = EVS_UNDEF_RATE;
            break;    	
    }
    return u2Rate;
}
