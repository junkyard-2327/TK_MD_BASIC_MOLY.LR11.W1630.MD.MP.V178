#include "kal_general_types.h"
#include "kal_public_api.h"
#include "syscomp_config.h"
#include "kal_public_defs.h"
#include "cache_sw.h"   //? ask SS, it ought not be exposed from RCU_MEMORY_SIZE
#include "mmu.h"
#include "l1sp_trc_l1core.h"
#include "audio_cc.h"
#include "audio_ringbuf.h"
#include "cc_irq_public.h"
#include "l1audio_trace_l1core.h"
//#include "common_def.h"
#include "l1aud_common_def.h"
#include "us_timer.h"

#define AUD_1TICK(tick)          (tick * ((KAL_TICKS_10_MSEC) >> 1))       /* New Tick Transfer   1tick       */
#define AUD_10TICK(tick)         (tick * (KAL_TICKS_50_MSEC))               /* New Tick Transfer  10tick      */

#define true         (kal_bool)(1==1)
#define false        (kal_bool)(1==0)

static struct {
   kal_uint32   retrieved_events_L;
   kal_uint32   events_l1FN_L;
   kal_uint32   P2L_buf_L[CC_BUFFER_SIZE]; 
   kal_uint32   L2P_buf_L[CC_BUFFER_SIZE];      
} l1audio_L;

typedef struct {
   void         (*code_L)(kal_uint32, kal_uint32, kal_uint32, kal_uint32, kal_uint32, kal_uint32);
   kal_uint32   data1_L;
   kal_uint32   data2_L;
   kal_uint32   data3_L;
   kal_uint32   data4_L;
   kal_uint32   data5_L;
   kal_uint32   data6_L;      
} AM_QFunction_L;

typedef enum {	 
   AM_STATE_IDLE_L,
   AM_STATE_2G_L,
   AM_STATE_3G_L,
   AM_STATE_4G_L,         

}AM_STATE_L; 

static struct {
   AM_STATE_L   state_L;  
   RINGBUFFER_T(AM_QFunction_L,8) qfunc_L;
   kal_bool     tch_state_L; // true: TCH on; false: TCH off
   kal_uint32   cntHandover_L;
   kal_uint32   hasHandover_L;
   kal_timerid  sp3g_timer_L;
}am_L;

static struct {
   unsigned short DSP_IO_L;
}am_register_backup_L;

//Extern Funtions
extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
//2G
extern unsigned short L1D_Audio_ChkDspInitDone();
extern kal_uint32 L1I_GetTimeStamp( void );
extern unsigned short L1D_Audio_RestartDSP();
extern void L1D_Audio_NoNeedDSP();
extern void L1D_ENABLE_DTIRQ( void );

#if defined(_MODEM_RESYNC_3G_) 
#ifndef TK6291_FAKE_COMPILE
extern void      UL1D_Speech_Resync_Reset_Time_Offset();
extern kal_int16 UL1D_Speech_Resync_Get_Time_Offset();
extern void      UL1D_Speech_Resync_Update_Time_Offset(kal_bool direction);
//3G TDD Modem Resync
extern void      TL1C_Reset_Time_Drift();
extern kal_int16 TL1C_Get_Time_Drift();
extern void      TL1C_Update_Time_Drift(kal_bool direction);
#endif //#ifndef TK6291_FAKE_COMPILE
#endif


DEFINE_NC_SHARED_VAR(kalcc_rcuid, aud_P2L_rcu);
DEFINE_RCU_DNC_SHARED_ARRAY(kal_uint8, aud_P2L_rcu_mem, 				RCU_MEMORY_SIZE(CC_BUFFER_SIZE * sizeof(kal_uint32), 2)); // 1024 bytes * 1 blocks

DEFINE_NC_SHARED_VAR(kalcc_rcuid, aud_L2P_rcu);
DEFINE_RCU_DNC_SHARED_ARRAY(kal_uint8, aud_L2P_rcu_mem, 				RCU_MEMORY_SIZE(CC_BUFFER_SIZE * sizeof(kal_uint32), 2)); // 1024 bytes * 1 blocks

DECLARE_SHARED_VAR(cc_eventgrpid, AUD_P2L);
DEFINE_NC_SHARED_VAR(cc_eventgrpid, AUD_P2L);

DECLARE_SHARED_VAR(cc_eventgrpid, AUD_L2P);	
DEFINE_NC_SHARED_VAR(cc_eventgrpid, AUD_L2P);


kal_uint32 convert_64us_diff_to_ms(kal_uint32 prev, kal_uint32 cur)
{
   kal_uint32 result;
   result = (cur >= prev) ? (cur - prev) : (0xFFFFFFFF - prev + cur);
   result = (result *64) / 1000;
   return(result);
}


void AM_Init_L( void )
{
   RB_INIT( am_L.qfunc_L );  
   am_L.state_L = AM_STATE_IDLE_L;   
   am_L.tch_state_L = false; 
   am_L.cntHandover_L   = 0;
   am_L.hasHandover_L   = 0;
}

static void AM_Enqueue_L( void (*code)(kal_uint32, kal_uint32, kal_uint32, kal_uint32, kal_uint32, kal_uint32), 
                        kal_uint32 data1, kal_uint32 data2, 
                        kal_uint32 data3, kal_uint32 data4, 
                        kal_uint32 data5, kal_uint32 data6, kal_bool isCritical )
{
   L1Audio_Msg_PutQ(0);
   if (isCritical) { // only 2g speech on will go to here 		
		   L1Audio_Msg_PutQ(1);
       kal_uint32 savedMask;
       AM_QFunction_L qf;

		   savedMask = SaveAndSetIRQMask(); 
		   L1D_ENABLE_DTIRQ();       

       qf.code_L  = code;
       qf.data1_L = data1;
     	 qf.data2_L = data2; 
       qf.data3_L = data3;
     	 qf.data4_L = data4; 
       qf.data5_L = data5;
     	 qf.data6_L = data6; 
       L1Audio_Msg_PutQ(0);
	     RB_PUT( am_L.qfunc_L, qf );
	     L1Audio_Msg_PutQ(1);
		   RestoreIRQMask(savedMask);
   } else {// Direct execute in task	
      L1Audio_Msg_PutQ(2);	
      code( data1 , data2, data3 , data4, data5 , data6 );
   }
   L1Audio_Msg_PutQ(3);
}

kal_bool AM_IsSpeechOn_L( void ){
   return AM_STATE_2G_L == am_L.state_L	|| AM_STATE_3G_L == am_L.state_L || AM_STATE_4G_L == am_L.state_L;
}

void AM_FlushQFunction_L( void )
{
#ifndef  L1D_TEST
   int i = 0;
   while( !RB_EMPTY(am_L.qfunc_L) ){
      kal_sleep_task( AUD_1TICK(1) );
      ASSERT(i++ <= 5 ); // It is possible in the current design the CTIRQ disappears just after putting into the queue.
   }
#endif
}

int gg;
kal_bool AM_AudioManager( kal_bool handover, kal_uint16 speech_mode, kal_int8 sub_channel )
{
   AM_QFunction_L func;

   L1Audio_Msg_AM_AudioManager( handover, speech_mode, sub_channel, L1Audio_Speech_State(am_L.state_L));
   #if IS_SPEECH_RESYNC_SUPPORT
      if(L1D_Get_Speech_Re_Sync_Flag())
         L1Audio_Msg_AM_2G_Resync( am_L.speech_mode_L, speech_mode);      
   #endif
    
   if( AM_STATE_2G_L == am_L.state_L ){
	   if( handover ||  0 == am_L.hasHandover_L){
	   	  L1Audio_Msg_AM_Handover(speech_mode, sub_channel);   	  
	      ASSERT( CC_IRQ_SUCCESS == cc_irq_trigger_interrupt(CC_IRQ_L2P_DSP, IRQ_L2P_2G_HANDOVER, (kal_uint32)speech_mode, (kal_uint32)sub_channel) ); 
	      am_L.cntHandover_L ++;
	      am_L.hasHandover_L = 1;
	   }
   }

#if defined(_MODEM_RESYNC_2G_)  
   if( AM_STATE_2G_L == am_L.state_L ){
       int16 time_drift = L1D_Get_Time_Drift(); //us	
       L1Audio_Msg_AM_Resync( 0, time_drift);
       if(time_drift > 1000){
       	  L1Audio_Msg_AM_Update_Time_Drift( 1 );//Q
       	  L1D_Update_Time_Drift(true);       	  
       	  //notify DSP
       	  SAL_8K_Resync(true, 8, true, 8);
       }else if(time_drift < -1000){
       	  L1Audio_Msg_AM_Update_Time_Drift( 0 );//Q
       	  L1D_Update_Time_Drift(false);        	  
       	  //notify DSP
       	  SAL_8K_Resync(true, -8, true, -8);
       }
   }
#endif
   
   if( !RB_EMPTY( am_L.qfunc_L ) ) {
      RB_GET( am_L.qfunc_L, func );
      gg ++;
      L1Audio_Msg_GetQ( func.code_L, func.data1_L, func.data2_L, func.data3_L, func.data4_L, func.data5_L, func.data6_L );
      func.code_L( func.data1_L, func.data2_L, func.data3_L, func.data4_L, func.data5_L, func.data6_L );
   }

	return false;
}

void cc_DSP_2G_Handover_L( kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 sub_channel, 
                         kal_uint32 dummy1, kal_uint32 dummy2, kal_uint32 dummy3 )
{
    ASSERT( CC_DUMMY_PARAM == dummy1 && CC_DUMMY_PARAM == dummy2 && CC_DUMMY_PARAM == dummy3 );

#if defined(_MODEM_RESYNC_2G_) 
     	 L1Audio_Msg_AM_Reset_Time_Drift();//Q
      	L1D_Reset_Time_Drift();
#endif  
   ASSERT( am_L.cntHandover_L > 0);
   {
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask(); 
   am_L.cntHandover_L--;
   RestoreIRQMask(savedMask);
   }
   
   SAL_2G_Handover(enc_mod, dec_mod, sub_channel);   
}

		   
void cc_2G_Handover_L(kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 sub_channel)
{
   //ASSERT( AM_STATE_2G == am.state );
   if( AM_STATE_2G_L != am_L.state_L ){
      kal_prompt_trace(MOD_L1SPL1, "cc_2G_Handover Skip %d %d", am_L.tch_state_L, am_L.state_L);
      return;	
   }
   kal_prompt_trace(MOD_L1SPL1, "cc_2G_Handover Enter %d ", am_L.tch_state_L);
   AM_Enqueue_L( cc_DSP_2G_Handover_L,  enc_mod, dec_mod, sub_channel, 
                                    CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM, 
                                    am_L.tch_state_L );
   AM_FlushQFunction_L();
   kal_prompt_trace(MOD_L1SPL1, "cc_2G_Handover Leave");
}	

void cc_DSP_2G_Call_Open_L(kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 sub_channel, 
                         kal_uint32 dummy1, kal_uint32 dummy2, kal_uint32 dummy3 )
{
    ASSERT( CC_DUMMY_PARAM == dummy1 && CC_DUMMY_PARAM == dummy2 && CC_DUMMY_PARAM == dummy3 );

#if defined(_MODEM_RESYNC_2G_)  	  
      L1Audio_Msg_AM_Reset_Time_Drift();
	     L1D_Reset_Time_Drift();
#elif defined(_2G_DSP_SMR_SUPPORT_)
      SAL_2G_SMR_Switch(true);
#endif 

   SAL_2G_Call_Open(enc_mod, dec_mod, sub_channel);
}	

void cc_2G_Call_Open_L(kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 sub_channel)
{
#if defined(_SWITCH_AFE_CLK_)      
   uint16 L1D_GetRF(uint16 mode);
   uint16 RF_2G = L1D_GetRF(MML1_RF_2G);
   L1Audio_Msg_L1D_GetRF(RF_2G);
#endif 	
	 kal_prompt_trace(MOD_L1SPL1, "cc_2G_Call_Open Enter");
#if defined(_SWITCH_AFE_CLK_)               
      if( 2 == RF_2G){ //return :   1 -> RF1,  2-> RF2
         *MD2GSYS_AFE_CK_SEL = 0x0;         
      }
#endif  	 
   //ASSERT( 0 == am.cntHandover || 2 == am.cntHandover);
   {
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask(); 
   am_L.cntHandover_L = 0;
   am_L.hasHandover_L = 0;
   RestoreIRQMask(savedMask);
   }

   
   AM_Enqueue_L( cc_DSP_2G_Call_Open_L, enc_mod, dec_mod, sub_channel, 
                                    CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM, 
                                    am_L.tch_state_L  );
   AM_FlushQFunction_L();
   am_L.state_L = AM_STATE_2G_L;     
   kal_prompt_trace(MOD_L1SPL1, "cc_2G_Call_Open Leave"); 
}	

void cc_DSP_2G_Call_Close_L(kal_uint32 dsp_end, 
                          kal_uint32 dummy1, kal_uint32 dummy2, kal_uint32 dummy3, kal_uint32 dummy4, kal_uint32 dummy5 )
{
   ASSERT( CC_DUMMY_PARAM == dummy1 && CC_DUMMY_PARAM == dummy2 && CC_DUMMY_PARAM == dummy3 && CC_DUMMY_PARAM == dummy4 && CC_DUMMY_PARAM == dummy5 );
   
#if defined(_2G_DSP_SMR_SUPPORT_)
   SAL_2G_SMR_Switch(false);
#endif     
   SAL_2G_Call_Close(dsp_end);
}

void cc_2G_Call_Close_L(kal_uint32 dsp_end)
{
#if defined(_SWITCH_AFE_CLK_)      
   uint16 L1D_GetRF(uint16 mode);
   uint16 RF_2G = L1D_GetRF(MML1_RF_2G);
   L1Audio_Msg_L1D_GetRF(RF_2G);
#endif 		
	 kal_prompt_trace(MOD_L1SPL1, "cc_2G_Call_Close Enter");
#if defined(_SWITCH_AFE_CLK_)         
      if( 2 == RF_2G){ //return :   1 -> RF1,  2-> RF2
         *MD2GSYS_AFE_CK_SEL = 0x1;
      }
#endif  
   AM_Enqueue_L( cc_DSP_2G_Call_Close_L, dsp_end, 
                                     CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM,
                                     false );
   AM_FlushQFunction_L();
   am_L.state_L = AM_STATE_IDLE_L;     
   kal_prompt_trace(MOD_L1SPL1, "cc_2G_Call_Close Leave");  
}

void cc_DSP_3G_Call_Open_L(kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 dtx, kal_uint32 delR, kal_uint32 delW, kal_uint32 delM)
{
#if defined(_MODEM_RESYNC_3G_)	
		L1Audio_Msg_AM_3G_Reset_Time_Drift();
#if defined( __UMTS_RAT__ ) 	    
    if(gmss_is_wcdma_mode_activated()){
		   UL1D_Speech_Resync_Reset_Time_Offset();
    }else if(gmss_is_tdscdma_mode_activated()){
       TL1C_Reset_Time_Drift();
    }else{
    	 ASSERT(0);
    }
#endif		
#endif
   SAL_3G_Call_Open(enc_mod, dec_mod, dtx, delR, delW, delM);  
}

void sp3g_updateL1DSync(void)
{
#if defined(_MODEM_RESYNC_3G_)     
#if defined( __UMTS_RAT__ )
	   if(gmss_is_wcdma_mode_activated()){	   	
#ifndef TK6291_FAKE_COMPILE
	       int16 time_drift = UL1D_Speech_Resync_Get_Time_Offset(); //us	
#else //#ifndef TK6291_FAKE_COMPILE
	       int16 time_drift = 0;
#endif //#ifndef TK6291_FAKE_COMPILE
	       kal_dev_trace(TRACE_INFO,   SP3G_L1D_Resync, 1, time_drift);
	       if(time_drift > 1000){
	       	  kal_dev_trace(TRACE_INFO, 	   L1D_RESYNC_UPDATE,  1);     	  
#ifndef TK6291_FAKE_COMPILE
	       	  UL1D_Speech_Resync_Update_Time_Offset(true);	       	 	       	  
#endif //#ifndef TK6291_FAKE_COMPILE
	       	  SAL_8K_Resync(true, 8, true, 8);	       	  
	       }else if(time_drift < -1000){
	       	  kal_dev_trace(TRACE_INFO, 	   L1D_RESYNC_UPDATE,  0);  
#ifndef TK6291_FAKE_COMPILE
	       	  UL1D_Speech_Resync_Update_Time_Offset(false); 	       	  
#endif //#ifndef TK6291_FAKE_COMPILE
	       	  SAL_8K_Resync(true, -8, true, -8);	       	  
	       }
	   }else if(gmss_is_tdscdma_mode_activated()){	   		
#ifndef TK6291_FAKE_COMPILE
	       int16 time_drift = TL1C_Get_Time_Drift(); //us	
#else //#ifndef TK6291_FAKE_COMPILE
	       int16 time_drift = 0;
#endif //#ifndef TK6291_FAKE_COMPILE
	       kal_dev_trace(TRACE_INFO, 	    SP3G_L1D_Resync, 2, time_drift);
	       if(time_drift > 1000){	       	
	       	  kal_dev_trace(TRACE_INFO, 	   L1D_RESYNC_UPDATE,  1);  
#ifndef TK6291_FAKE_COMPILE
	       	  TL1C_Update_Time_Drift(true);	       	 
#endif //#ifndef TK6291_FAKE_COMPILE
	       	  SAL_8K_Resync(true, 8, true, 8);
	       }else if(time_drift < -1000){	       	
	       	  kal_dev_trace(TRACE_INFO, 	   L1D_RESYNC_UPDATE,  0);  
#ifndef TK6291_FAKE_COMPILE
	       	  TL1C_Update_Time_Drift(false);        	  
#endif //#ifndef TK6291_FAKE_COMPILE
	       	  SAL_8K_Resync(true, -8, true, -8);
	       }
	   }else{
    	 ASSERT(0);
     }
#endif	    
#endif
   //kal_set_timer(am.sp3g_timer, (kal_timer_func_ptr)(sp3g_updateL1DSync), NULL, AUD_1TICK(4), AUD_1TICK(0));	
}

void cc_3G_Call_Open_L(kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 dtx, kal_uint32 delR, kal_uint32 delW, kal_uint32 delM, kal_uint32 u32CurTime64us)
{
   kal_uint32 u32CurTime64usLocal, u32delay, u32delaySample;

   kal_prompt_trace(MOD_L1SP, "cc_3G_Call_Open Enter delR=%d delW=%d", delR, delW);

   u32CurTime64usLocal = fma_get_glb_ts();
   u32delay = convert_64us_diff_to_ms(u32CurTime64us, u32CurTime64usLocal); //ms
   u32delaySample = (u32delay % 20) * 8; //sample
   if( (u32delaySample >= delR || u32delaySample >= delW) && (0 != u32delaySample) )
   {
      delR += 160;
      delW += 160;
   }
   delR -= u32delaySample;
   delW -= u32delaySample;

   AM_Enqueue_L( cc_DSP_3G_Call_Open_L, enc_mod, dec_mod, dtx, delR, delW, delM, 
                                    false );
   AM_FlushQFunction_L(); 
   
   //kal_set_timer(am.sp3g_timer, (kal_timer_func_ptr)(sp3g_updateL1DSync), NULL, AUD_1TICK(4), AUD_1TICK(0));
      
   am_L.state_L = AM_STATE_3G_L; 
   kal_prompt_trace(MOD_L1SP, "cc_3G_Call_Open Leave delR=%d delW=%d P_to_L1_delay=%dms", delR, delW, u32delay);
}

void cc_DSP_3G_Call_Close_L(kal_uint32 dsp_end, kal_uint32 dummy1, kal_uint32 dummy2, kal_uint32 dummy3, kal_uint32 dummy4, kal_uint32 dummy5)
{
   ASSERT( CC_DUMMY_PARAM == dummy1 && CC_DUMMY_PARAM == dummy2 && CC_DUMMY_PARAM == dummy3 && CC_DUMMY_PARAM == dummy4 && CC_DUMMY_PARAM == dummy5 );   
   SAL_3G_Call_Close(dsp_end);
}

void cc_3G_Call_Close_L(kal_uint32 dsp_end)
{
   kal_prompt_trace(MOD_L1SPL1, "cc_3G_Call_Close Enter");
   //kal_cancel_timer(am.sp3g_timer);
   AM_Enqueue_L( cc_DSP_3G_Call_Close_L, dsp_end, 
                                     CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM,
                                     false );
   AM_FlushQFunction_L();   
   am_L.state_L = AM_STATE_IDLE_L; 
   kal_prompt_trace(MOD_L1SPL1, "cc_3G_Call_Close Leave"); 
}

void cc_DSP_4G_Call_Open_temp_L(kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 dtx, kal_uint32 delR, kal_uint32 delW, kal_uint32 delM)
{
   SAL_4G_Call_Open_temp( enc_mod, dec_mod, dtx, delR, delW, delM);
}

void cc_4G_Call_Open_temp_L(kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 dtx, kal_uint32 delR, kal_uint32 delW, kal_uint32 delM, kal_uint32 u32CurTime64us)
{
   kal_uint32 u32CurTime64usLocal, u32delay, u32delaySample;

   kal_prompt_trace(MOD_L1SPL1, "cc_4G_Call_Open_temp Enter");

   u32CurTime64usLocal = fma_get_glb_ts();
   u32delay = convert_64us_diff_to_ms(u32CurTime64us, u32CurTime64usLocal); //ms
   u32delaySample = (u32delay % 20) * 8; //sample
   if( (u32delaySample >= delR || u32delaySample >= delW) && (0 != u32delaySample) )
   {
      delR += 160;
      delW += 160;
   }
   delR -= u32delaySample;
   delW -= u32delaySample;

   AM_Enqueue_L( cc_DSP_4G_Call_Open_temp_L, enc_mod, dec_mod, dtx, delR, delW, delM, 
                                         false );
   AM_FlushQFunction_L(); 
   am_L.state_L = AM_STATE_4G_L; 
   kal_prompt_trace(MOD_L1SP, "cc_4G_Call_Open_temp Leave delR=%d delW=%d P_to_L1_delay=%dms", delR, delW, u32delay);
}

void cc_DSP_4G_Call_Close_temp_L(kal_uint32 dsp_end, kal_uint32 dummy1, kal_uint32 dummy2, kal_uint32 dummy3, kal_uint32 dummy4, kal_uint32 dummy5)
{   
   ASSERT( CC_DUMMY_PARAM == dummy1 && CC_DUMMY_PARAM == dummy2 && CC_DUMMY_PARAM == dummy3 && CC_DUMMY_PARAM == dummy4 && CC_DUMMY_PARAM == dummy5 );
   SAL_4G_G_Codec_Call_Close(dsp_end);
}

void cc_4G_Call_Close_temp_L(kal_uint32 dsp_end)
{
   kal_prompt_trace(MOD_L1SPL1, "cc_4G_Call_Close_temp Enter");
   AM_Enqueue_L( cc_DSP_4G_Call_Close_temp_L, dsp_end, 
                                          CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM,
                                          false );
   AM_FlushQFunction_L(); 
   am_L.state_L = AM_STATE_IDLE_L; 
   kal_prompt_trace(MOD_L1SPL1, "cc_4G_Call_Close_temp Leave");
}

#if 1
void cc_DSP_4G_G_Codec_Call_Open_temp_L(kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 dtx, kal_uint32 delR, kal_uint32 delW, kal_uint32 delM)
{
   SAL_4G_G_Codec_Call_Open(enc_mod, dec_mod, dtx, delR, delW, delM);
}

void cc_4G_G_Codec_Call_Open_temp_L(kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 dtx, kal_uint32 delR, kal_uint32 delW, kal_uint32 delM, kal_uint32 u32CurTime64us)
{
   kal_uint32 u32CurTime64usLocal, u32delay, u32delaySample;

   kal_prompt_trace(MOD_L1SPL1, "cc_4G_G_Codec_Call_Open_temp Enter");

   u32CurTime64usLocal = fma_get_glb_ts();
   u32delay = convert_64us_diff_to_ms(u32CurTime64us, u32CurTime64usLocal); //ms
   u32delaySample = (u32delay % 20) * 8; //sample
   if( (u32delaySample >= delR || u32delaySample >= delW) && (0 != u32delaySample) )
   {
      delR += 160;
      delW += 160;
   }
   delR -= u32delaySample;
   delW -= u32delaySample;

   AM_Enqueue_L( cc_DSP_4G_G_Codec_Call_Open_temp_L, enc_mod, dec_mod, dtx, delR, delW, delM, 
                                                 false );
   AM_FlushQFunction_L(); 
   am_L.state_L = AM_STATE_4G_L; 
   kal_prompt_trace(MOD_L1SP, "cc_4G_G_Codec_Call_Open_temp Leave delR=%d delW=%d P_to_L1_delay=%dms", delR, delW, u32delay);

}

void cc_DSP_4G_G_Codec_Call_Close_temp_L(kal_uint32 dsp_end, kal_uint32 dummy1, kal_uint32 dummy2, kal_uint32 dummy3, kal_uint32 dummy4, kal_uint32 dummy5)
{   
   ASSERT( CC_DUMMY_PARAM == dummy1 && CC_DUMMY_PARAM == dummy2 && CC_DUMMY_PARAM == dummy3 && CC_DUMMY_PARAM == dummy4 && CC_DUMMY_PARAM == dummy5 );
   SAL_4G_G_Codec_Call_Close(dsp_end);
}

void cc_4G_G_Codec_Call_Close_temp_L(kal_uint32 dsp_end)
{
   kal_prompt_trace(MOD_L1SPL1, "cc_4G_G_Codec_Call_Close_temp Enter");
   AM_Enqueue_L( cc_DSP_4G_Call_Close_temp_L, dsp_end, 
                                          CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM, CC_DUMMY_PARAM,
                                          false );
   AM_FlushQFunction_L(); 
   am_L.state_L = AM_STATE_IDLE_L; 
   kal_prompt_trace(MOD_L1SPL1, "cc_4G_G_Codec_Call_Close_temp Leave");
}
#endif

void cc_L1D_Audio_ChkDspInitDone_L()
{
   while( 0 == L1D_Audio_ChkDspInitDone()){
		   kal_sleep_task(AUD_1TICK(1));
	 }	
}



void L1Audio_Task_L(unsigned argc, void *argv)
{
   void L1Aud_Handler_L( kal_uint32 P2LBuf[CC_BUFFER_SIZE], kal_uint32 L2PBuf[CC_BUFFER_SIZE] );
   kal_uint32 retrieved_events;
   int i;
   kal_uint32 P2LBuf[CC_BUFFER_SIZE]; 
   kal_uint32 L2PBuf[CC_BUFFER_SIZE];   
   kal_uint32 *P2L_rcu_buf;
   kal_uint32 *L2P_rcu_buf;	  
   
   //am.sp3g_timer = kal_create_timer("sp3g_timer");
   
   while( 1 ) {
      // clear internal buffer
      for( i = 0; i < CC_BUFFER_SIZE ; i++){
         P2LBuf[i] = L2PBuf[i] = 0 ;
      }   
      kal_prompt_trace(MOD_L1SPL1, "L1AUD_TASK_L clear internal buffer");
      // P->L receives PCore's Messages
      kalcc_retrieve_eg_events(SHARED_pVAR(AUD_P2L), 1 << AUD_P2L_MESSAGE_BIT, KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND);
         
      l1audio_L.retrieved_events_L = retrieved_events;
      l1audio_L.events_l1FN_L = L1I_GetTimeStamp();
      
      kal_prompt_trace(MOD_L1SPL1, "L1AUD_TASK_L receive a P2L event");
   
      //Retrieve Params
      P2L_rcu_buf = rcu_get_read_lock(SHARED_VAR(aud_P2L_rcu));
      dynamic_switch_cacheable_region(&P2L_rcu_buf, ALIGNTOCACHELINE(CC_BUFFER_SIZE * sizeof(kal_uint32)), PAGE_CACHEABLE);
      
      for(i=0; i<CC_BUFFER_SIZE; i++){
         P2LBuf[i] = P2L_rcu_buf[i];
         kal_prompt_trace(MOD_L1SPL1, "L1AUD_TASK_L receive a P2L data[%d] = %x", i, P2LBuf[i]);
      }      
      dynamic_switch_cacheable_region(&P2L_rcu_buf, ALIGNTOCACHELINE(CC_BUFFER_SIZE * sizeof(kal_uint32)), PAGE_NO_CACHE);
      ASSERT( KAL_SUCCESS == rcu_free_read_lock(P2L_rcu_buf));
       
      ASSERT(P2LBuf[1] <= CC_MAX_DATA);     
      
      L1Aud_Handler_L( P2LBuf, L2PBuf );
      
      ASSERT(L2PBuf[1] <= CC_MAX_DATA);
   
      // L -> P sends returns
      //Prepare Params
      L2P_rcu_buf = rcu_get_free_buff(SHARED_VAR(aud_L2P_rcu));
      dynamic_switch_cacheable_region(&L2P_rcu_buf, ALIGNTOCACHELINE(CC_BUFFER_SIZE * sizeof(kal_uint32)), PAGE_CACHEABLE);
      
      for(i=0; i<CC_BUFFER_SIZE; i++){
         kal_prompt_trace(MOD_L1SPL1, "L1AUD_TASK_L receive a L2P data[%d] = %x", i, L2PBuf[i]);
         L2P_rcu_buf[i] = L2PBuf[i];
      }      
      dynamic_switch_cacheable_region(&L2P_rcu_buf, ALIGNTOCACHELINE(CC_BUFFER_SIZE * sizeof(kal_uint32)), PAGE_NO_CACHE);
      ASSERT(KAL_SUCCESS == rcu_commit_data(L2P_rcu_buf));
      
      //Send A CrossCore Message
      kalcc_set_eg_events(SHARED_pVAR(AUD_L2P), 0xFF, KAL_OR);         
      kal_prompt_trace(MOD_L1SPL1, "L1AUD_TASK_L set a L2P event");
      
      ASSERT( ( P2LBuf[0] | 0x8000 ) == L2PBuf[0] );  
   }//end of while
   
}


void L1SP_TCH_Notify_L( kal_bool bOn )
{
   ASSERT( CC_IRQ_SUCCESS == cc_irq_trigger_interrupt(CC_IRQ_L2P_DSP, IRQ_L2P_TCH_NOTIFY, (kal_uint32)bOn, 0));
   am_L.tch_state_L = bOn;
   L1Audio_Msg_TCH_NOTIFY(L1AUDIO_Str_onoff(0), L1Audio_Speech_State(am_L.state_L));
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
#endif

//void SP4G_emac_timing_update(l1sp_emac_volte_timing_info_struct* p_timing_info){
//   
//}


void L1Aud_Handler_L( kal_uint32 P2LBuf[CC_BUFFER_SIZE], kal_uint32 L2PBuf[CC_BUFFER_SIZE] )
{
   switch(P2LBuf[0]){
   case MSG_P2L_2G_CALL_ON:
      ASSERT( 3 == P2LBuf[1]);
      cc_2G_Call_Open_L(P2LBuf[2], P2LBuf[3], P2LBuf[4]);  
      
      L2PBuf[0] = MSG_L2P_2G_CALL_ON_ACK;
      L2PBuf[1] = 0;
      break;
   case MSG_P2L_2G_CALL_OFF:
      ASSERT( 1 == P2LBuf[1]);
      cc_2G_Call_Close_L(P2LBuf[2]);    
      
      L2PBuf[0] = MSG_L2P_2G_CALL_OFF_ACK;
      L2PBuf[1] = 0;        
      break;   
   case MSG_P2L_2G_HANDOVER:
      ASSERT( 3 == P2LBuf[1]);
      cc_2G_Handover_L(P2LBuf[2], P2LBuf[3], P2LBuf[4]);

      L2PBuf[0] = MSG_L2P_2G_HANDOVER_ACK;
      L2PBuf[1] = 0;              
      break;
   case MSG_P2L_3G_CALL_ON:
      ASSERT( 7 == P2LBuf[1]);
      cc_3G_Call_Open_L(P2LBuf[2], P2LBuf[3], P2LBuf[4], P2LBuf[5], P2LBuf[6], P2LBuf[7], P2LBuf[8]);      
      
      L2PBuf[0] = MSG_L2P_3G_CALL_ON_ACK;
      L2PBuf[1] = 0;              
      break;
   case MSG_P2L_3G_CALL_OFF:
      ASSERT( 1 == P2LBuf[1]);
      cc_3G_Call_Close_L(P2LBuf[2]);
      
      L2PBuf[0] = MSG_L2P_3G_CALL_OFF_ACK;
      L2PBuf[1] = 0;              
      break;
   case MSG_P2L_4G_CALL_ON:
      ASSERT( 7 == P2LBuf[1]);
      cc_4G_Call_Open_temp_L(P2LBuf[2], P2LBuf[3], P2LBuf[4], P2LBuf[5], P2LBuf[6], P2LBuf[7], P2LBuf[8]);
      
      L2PBuf[0] = MSG_L2P_4G_CALL_ON_ACK;
      L2PBuf[1] = 0;              
      break;   
   case MSG_P2L_4G_CALL_OFF:
      ASSERT( 1 == P2LBuf[1]);
      cc_4G_Call_Close_temp_L(P2LBuf[2]);        

      L2PBuf[0] = MSG_L2P_4G_CALL_OFF_ACK;
      L2PBuf[1] = 0;              
      break;   
   case MSG_P2L_4G_G_Codec_CALL_ON:
      ASSERT( 7 == P2LBuf[1]);
      cc_4G_G_Codec_Call_Open_temp_L(P2LBuf[2], P2LBuf[3], P2LBuf[4], P2LBuf[5], P2LBuf[6], P2LBuf[7], P2LBuf[8]);

      L2PBuf[0] = MSG_L2P_4G_G_Codec_CALL_ON_ACK;
      L2PBuf[1] = 0;
      break;
   case MSG_P2L_4G_G_Codec_CALL_OFF:
      ASSERT( 1 == P2LBuf[1]);
      cc_4G_G_Codec_Call_Close_temp_L(P2LBuf[2]);

      L2PBuf[0] = MSG_L2P_4G_G_Codec_CALL_OFF_ACK;
      L2PBuf[1] = 0;
      break;
   case MSG_P2L_AUD_RESTART_DSP:
      {
         unsigned short DSP_status;     
         ASSERT( 0 == P2LBuf[1]);
         DSP_status = L1D_Audio_RestartDSP();
         
         L2PBuf[0] = MSG_L2P_AUD_RESTART_DSP_ACK;
         L2PBuf[1] = 1;  
         L2PBuf[2] = DSP_status;                
      }
      break;   
   case MSG_P2L_AUD_NONEEDDSP:     
      {         
         ASSERT( 0 == P2LBuf[1]);
         L1D_Audio_NoNeedDSP();
         
         L2PBuf[0] = MSG_L2P_AUD_NONEEDDSP_ACK;
         L2PBuf[1] = 0;                 
      }  
      break;   
   case MSG_P2L_L1D_AUD_CHKDSPINITDONE:
      {         
         ASSERT( 0 == P2LBuf[1]);
         cc_L1D_Audio_ChkDspInitDone_L();
         
         L2PBuf[0] = MSG_L2P_L1D_AUD_CHKDSPINITDONE_ACK;
         L2PBuf[1] = 0;                
      }    	
   	  break;      
   default:
      ASSERT(0);
      break;   
   }
}


//Fix build error with mcu\l1core\modem\tl1\tl1sim\tl1sim_dummy.c
#if !( defined(__L1CORE__) && defined(__L1_STANDALONE__) )
void SP3G_UpdateL1AInFo( kal_uint8 bitmap, kal_uint8 value )
{
}
#endif //#if !(defined(__L1CORE__) && defined(__L1_STANDALONE__))

static void l1audio_main_L(task_entry_struct * task_entry_ptr)
{
   kal_set_active_module_id(MOD_L1SPL1);
   
   L1Audio_Task_L( 0, 0 );
}

static kal_bool l1audio_init_L(void)
{ 
   kal_status ret;

   ret = kalcc_create_event_group( SHARED_pVAR(AUD_P2L), "receive_AUD_P2L_eg" );
   ASSERT(KAL_SUCCESS == ret);   	
   
   SHARED_VAR(aud_L2P_rcu) = rcu_create((void *)SHARED_ARRAY(aud_L2P_rcu_mem), 			
                                                RCU_MEMORY_SIZE(CC_BUFFER_SIZE * sizeof(kal_uint32), 2), 
                                                CC_BUFFER_SIZE * sizeof(kal_uint32), 0);
   AM_Init_L();
   return KAL_TRUE;
}
kal_bool l1spl1_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct l1spl1_handler_info =
   {
      l1audio_main_L,          /* task entry function */
      l1audio_init_L,          /* task initialization function */
      NULL,          /* task configuration function */

   };

   *handle = (comptask_handler_struct *)&l1spl1_handler_info;

   return KAL_TRUE;
}

void l1sp_register_backup()
{
	 L1Audio_Msg_AM_L1D_Backup(0, *SHARE2_D2MCON);
	 am_register_backup_L.DSP_IO_L = *SHARE2_D2MCON;
}

void l1sp_register_restore()
{
	L1Audio_Msg_AM_L1D_Backup(1, am_register_backup_L.DSP_IO_L);
	
	*SHARE2_D2MCON = am_register_backup_L.DSP_IO_L;
	L1Audio_Msg_AM_L1D_Backup(2, *SHARE2_D2MCON);
}
