#ifndef _SPH_EVS_TRC_H
#define _SPH_EVS_TRC_H

#include "kal_trace.h"

/* !!! should be modified */
#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
#include "sp_EVS_trc_gen.h"
#endif /* TST Trace Defintion */
#endif


#define TRACE_GROUP_EVS          TRACE_GROUP_1

BEGIN_TRACE_MAP(MOD_SPH_EVS)

   TRC_MSG(EVS_ENC_ID                                                         ,"[EVS] Enc_ID: 0x%x BW: 0x%x Rate: 0x%x")
   TRC_MSG(EVS_ENC_RST                                                        ,"[EVS] Enc_Rst, SampRate: %d, MaxRate: %d, PCMBuf: 0x%x, Dtx: %d, BitRate: %d, HBAddr: 0x%x, CA_Ena: %d, CA_Indi: %d, CA_off: %d")
   TRC_MSG(EVS_DEC_RST                                                        ,"[EVS] Dec_Rst, SampRate: %d, PCMBuf: 0x%x, Len: %d, BFI: %d, HBAddr: 0x%x, CA_FrameMode: %d")
   TRC_MSG(EVS_ENC_RUN                                                        ,"[EVS] Enc_Run, SampRate: %d, MaxRate: %d, PCMBuf: 0x%x, Dtx: %d, BitRate: %d, HBAddr: 0x%x, CA_Ena: %d, CA_Indi: %d, CA_off: %d")
   TRC_MSG(EVS_DEC_RUN                                                        ,"[EVS] Dec_Run, SampRate: %d, PCMBuf: 0x%x, Len: %d, BFI: %d, HBAddr: 0x%x, CA_FrameMode: %d")
   TRC_MSG(EVS_ENC_TIME                                                       ,"[EVS] Enc_Time, Max: %d, Ave: %d")
   TRC_MSG(EVS_DEC_TIME                                                       ,"[EVS] Dec_Time, Max: %d, Ave: %d")
   TRC_MSG(EVS_ENC_DBG                                                        ,"[EVS] Enc_Dbg, Len: %d, BFI: 0x%x, Band: 0x%x")
   TRC_MSG(EVS_ENC_HB                                                         ,"[EVS] Enc_HB, 0x%x")
   TRC_MSG(EVS_DEC_HB                                                         ,"[EVS] Dec_HB, 0x%x")
   TRC_MSG(EVS_ENC_COD_UND                                                    ,"[EVS] Enc_Cod_Undef")  
   TRC_MSG(EVS_ENC_COD                                                        ,"[EVS] Enc_Cod, 0x%x")
   TRC_MSG(EVS_ENC_RST_MSG                                                    ,"[EVS] Enc_Rst_Msg")
   TRC_MSG(EVS_ENC_RUN_MSG                                                    ,"[EVS] Enc_Run_Msg")
   TRC_MSG(EVS_DEC_RST_MSG                                                    ,"[EVS] Dec_Rst_Msg")
   TRC_MSG(EVS_DEC_RUN_MSG                                                    ,"[EVS] Dec_Run_Msg")
   TRC_MSG(EVS_ENC_SID_FST                                                    ,"[EVS] Enc_SID_Fst, %d")
   TRC_MSG(EVS_DEC_RUN_HRT_FAIL                                               ,"[EVS] Dec_HRT_Fail")
   TRC_MSG(EVS_ENC_RUN_HRT_FAIL                                               ,"[EVS] Enc_HRT_Fail")

END_TRACE_MAP(MOD_SPH_EVS)

#endif //_SPH_EVS_TRC_H