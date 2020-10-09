#ifndef _L1SP_TRC_L1CORE_H
#define _L1SP_TRC_L1CORE_H

#include "kal_trace.h"

#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before l1sp_trc.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */

#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before nvram_trc.h"
#endif


#define TRACE_GROUP_AAAA          TRACE_GROUP_1
#define TRACE_GROUP_BBBB          TRACE_INFO

#define TRACE_GROUP_GGGG          (2)


#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "l1sp_trc_l1core_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_L1SPL1)

   //LCORE
   TRC_MSG(AM_L_SP3G_UPDATEL1DSYNC, "[SPH_L]sp3g_updateL1DSync_dummy timer_hisr_state_L=%x")
   TRC_MSG(AM_L_SP3G_UPDATEL1DSYNC_TIMER, "[SPH_L]L1AL_Timer_L_HISR timer_hisr_state_L=%x")
   TRC_MSG(AM_L_CC_2G_HANDOVER_SKIP, "[SPH_L]cc_2G_Handover Skip %d %d")
   TRC_MSG(AM_L_CC_2G_HANDOVER_ENTER, "[SPH_L]cc_2G_Handover Enter %d ")
   TRC_MSG(AM_L_CC_2G_HANDOVER_LEAVE, "[SPH_L]cc_2G_Handover Leave")
	 TRC_MSG(AM_L_CC_2G_CALLOPEN_ENTER, "[SPH_L]cc_2G_Call_Open Enter %d ")
   TRC_MSG(AM_L_CC_2G_CALLOPEN_LEAVE, "[SPH_L]cc_2G_Call_Open Leave") 
	 TRC_MSG(AM_L_CC_2G_CALLCLOSE_ENTER, "[SPH_L]cc_2G_Call_Close Enter %d")
   TRC_MSG(AM_L_CC_2G_CALLCLOSE_LEAVE, "[SPH_L]cc_2G_Call_Close Leave")  
   TRC_MSG(AM_L_CC_3G_CALLOPEN_ENTER, "[SPH_L]cc_3G_Call_Open Enter delR=%d delW=%d")
   TRC_MSG(AM_L_CC_3G_CALLOPEN_LEAVE, "[SPH_L]cc_3G_Call_Open Leave delR=%d delW=%d P_to_L1_delay=%dms")
   TRC_MSG(AM_L_CC_3G_CALLCLOSE_ENTER, "[SPH_L]cc_3G_Call_Close Enter")
   TRC_MSG(AM_L_CC_3G_CALLCLOSE_LEAVE, "[SPH_L]cc_3G_Call_Close Leave") 
   TRC_MSG(AM_L_CC_4G_CALLOPEN_ENTER,  "[SPH_L]cc_4G_Call_Open_temp Enter")
   TRC_MSG(AM_L_CC_4G_CALLOPEN_LEAVE,  "[SPH_L]cc_4G_Call_Open_temp Leave delR=%d delW=%d P_to_L1_delay=%dms")
   TRC_MSG(AM_L_CC_4G_CALLCLOSE_ENTER, "[SPH_L]cc_4G_Call_Close_temp Enter")
   TRC_MSG(AM_L_CC_4G_CALLCLOSE_LEAVE, "[SPH_L]cc_4G_Call_Close_temp Leave")
   TRC_MSG(AM_L_CC_4G_GCALLOPEN_ENTER,  "[SPH_L]cc_4G_G_Codec_Call_Open_temp Enter")
   TRC_MSG(AM_L_CC_4G_GCALLOPEN_LEAVE,  "[SPH_L]cc_4G_G_Codec_Call_Open_temp Leave delR=%d delW=%d P_to_L1_delay=%dms")
   TRC_MSG(AM_L_CC_4G_GCALLCLOSE_ENTER, "[SPH_L]cc_4G_G_Codec_Call_Close_temp Enter")
   TRC_MSG(AM_L_CC_4G_GCALLCLOSE_LEAVE, "[SPH_L]cc_4G_G_Codec_Call_Close_temp Leave")
   TRC_MSG(AM_L_L1AUD_TASK_CLRBUF, "[SPH_L]L1AUD_TASK_L clear internal buffer")
   TRC_MSG(AM_L_L1AUD_TASK_P2L, "[SPH_L]L1AUD_TASK_L receive a P2L event")
   TRC_MSG(AM_L_L1AUD_TASK_P2L_DATA, "[SPH_L]L1AUD_TASK_L receive a P2L data[%d] = %x")
   TRC_MSG(AM_L_L1AUD_TASK_L2P_DATA, "[SPH_L]L1AUD_TASK_L receive a L2P data[%d] = %x")
   TRC_MSG(AM_L_L1AUD_TASK_L2P, "[SPH_L]L1AUD_TASK_L set a L2P event")

   TRC_MSG(SP3G_L1A_UPDATE_INFO_L, "[SPH_L] SP3G Update Info bitmap %d, val %d")
     
   TRC_MSG(SP3G_L1D_Resync, "[SPH_L][SP3G L1D Resync] %d offeset=%d")
   TRC_MSG(L1D_RESYNC_UPDATE, "[SPH_L][SP3G L1D Resync]Update %d")

   TRC_MSG(AM_L_CC_4G_EVSCALLOPEN_ENTER, "cc_4G_EVS_Codec_Call_Open_temp_L Enter")
   TRC_MSG(AM_L_CC_4G_EVSCALLOPEN_LEAVE, "cc_4G_EVS_Codec_Call_Open_temp_L Leave delR=%d delW=%d P_to_L1_delay=%dms")
   TRC_MSG(AM_L_CC_4G_EVSCALLCLOSE_ENTER, "cc_4G_EVS_Codec_Call_Close_temp_L Enter")
   TRC_MSG(AM_L_CC_4G_EVSCALLCLOSE_LEAVE, "cc_4G_EVS_Codec_Call_Close_temp_L Leave")


END_TRACE_MAP(MOD_L1SPL1)
#endif // _L1SP_TRC_H
