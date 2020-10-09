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
 *
 * Filename:
 * ---------
 * l1audio_service.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   L1SP Task / L1Audio Service
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "drv_mdap_interface.h"
#include "sal_dsp.h"

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "intrCtrl.h"
#include "string.h"
#include "hisr_config.h"
#include "kal_public_defs.h"
#include "reg_base.h"
#include "l1sm_public.h"
#include "sp_cc.h"
#include "sleepdrv_interface.h"
#include "kal_trace.h"
#include "l1sp_trc.h"
#include "l1audio.h"
#include "audio_def.h"
#include "media.h"
#include "l1audio_trace.h"
#include "ddload.h"
#include "am.h"
#include "afe.h"
#include "l1aud_common_def.h"
//#include "speech_def.h"
#include "sal_def.h"
#include "sal_exp.h"
#include "us_timer.h"
#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
#include "RM_public.h"
#include "reg_base.h"
//#include "drv_iomux.h"


#endif

#if defined(__SMART_PHONE_MODEM__)
#include "bgSnd.h" // for BGSND_INIT() 
#endif // defined(__SMART_PHONE_MODEM__)

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#endif

#include "mml1_rf_global.h"

//#define TK6291_FAKE_COMPILE
//#define TK6291_NO_SPEECH_HW

#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )

#if defined(MT6280) || defined(MT6589) // smart phone modem, super dongle. 
#define  MAX_HISR_HANDLER        8 // 3g, pnw, vm, epl, bgsnd, record (for tranditional hosted dongle,  6 is enough, i.e. 3g, datacard, vm, epl)
#elif defined(MT6290)
#define  MAX_HISR_HANDLER        9 // 3g, pnw, vm, epl, bgsnd(ul+dl), record (for tranditional hosted dongle,  6 is enough, i.e. 3g, datacard, vm, epl)
#elif defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
   #if defined(__VOLTE_SUPPORT__)
      #define  MAX_HISR_HANDLER       15 // 3g(ul+dl), pnw(ul+dl), DACA for bt (ul+dl), vm, epl, bgsnd(ul+dl), record, 4G AMR (ul+dl), 4G G-codec (ul+dl)
   #else //#if defined(__VOLTE_SUPPORT__)
      #define  MAX_HISR_HANDLER       12 // 3g, pnw, DACA for bt, vm, epl, bgsnd(ul+dl), record, cvsd
   #endif //#if defined(__VOLTE_SUPPORT__)
#else
	#error Need to check the HISR number for the new chip
#endif // by chip

#else // no 3g
#if defined(MT6280) || defined(MT6589) // smart phone modem, super dongle. 
#define  MAX_HISR_HANDLER        6 // pnw, vm, epl, bgsnd, record  (for tranditional hosted dongle,  4 is enough, i.e. datacard, vm, epl)
#elif defined(MT6290)
#define  MAX_HISR_HANDLER        7 // 3g, pnw, vm, epl, bgsnd(ul+dl), record (for tranditional hosted dongle,  5 is enough, i.e. datacard, vm, epl)
#elif defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(TK6291) || defined(MT6755) || defined(MT6797)) || defined(MT6757) || defined(MT6750S)
#define  MAX_HISR_HANDLER       10 // pnw, DACA for bt, vm, epl, bgsnd(ul+dl), record, cvsd

#else
	#error Need to check the HISR number for the new chip
#endif // by chip

#endif

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );
void toneLoopbackRecInit( void );
extern void DisableIRQ(void);

#ifdef MTK_SLEEP_ENABLE
   #define  GET_SLEEP_HANDLE()   {  l1audio.sleep_handle=SleepDrv_GetHandle();       }
   #define  SLEEP_LOCK()         {  SleepDrv_SleepDisable( l1audio.sleep_handle );   }
   #define  SLEEP_UNLOCK()       {  SleepDrv_SleepEnable( l1audio.sleep_handle );    }
#else
   #define  GET_SLEEP_HANDLE()
   #define  SLEEP_LOCK()
   #define  SLEEP_UNLOCK()
#endif

#ifndef TK6291_FAKE_COMPILE
extern uint32 L1I_GetTimeStamp( void );
#endif //#ifndef TK6291_FAKE_COMPILE

#if (defined( __CENTRALIZED_SLEEP_MANAGER__ ) && defined(MTK_SLEEP_ENABLE) )
#if defined(__AUDIO_POWERON_RESET_DSP__)
   #ifndef TK6291_FAKE_COMPILE
   extern unsigned short  cc_L1D_Audio_RestartDSP( void );
   extern void            cc_L1D_Audio_NoNeedDSP( void );
   #endif //#ifndef TK6291_FAKE_COMPILE
   extern void AFE_Init_status(kal_bool flag);
#else
   #ifndef TK6291_FAKE_COMPILE
   extern kal_uint8  L1SM_IntGetHandle( void );
   extern void       L1SM_Multi_SW_WakeUp(void); 
   extern void       L1SM_IntSleepDisable( kal_uint8 handle );
   extern void       L1SM_IntSleepEnable( kal_uint8 handle );
   extern kal_uint8  L1D_MD2G_PWD_GetHandle( void );
   extern      void  L1D_MD2G_PWD_Disable( kal_uint8 handle );
   extern      void  L1D_MD2G_PWD_Enable( kal_uint8 handle );
   #endif //#ifndef TK6291_FAKE_COMPILE
#endif // defined(__AUDIO_POWERON_RESET_DSP__)
#endif //(defined( __CENTRALIZED_SLEEP_MANAGER__ ) && defined(MTK_SLEEP_ENABLE) )

/* ------------------------------------------------------------------------------ */

static struct {
   uint32               sleppModeLocker;
   uint32               dspUser;
   kal_eventgrpid       aud_events;
   uint16               media_flag;
   uint16               d2c_itype;
   uint32               d2c_l1FN;
   uint32               retrieved_events;
   uint32               events_l1FN;
   kal_hisrid           hisr;

   L1Audio_EventHandler evHandler[MAX_AUDIO_FUNCTIONS];
   void                 *evData[MAX_AUDIO_FUNCTIONS];
   uint32               id_flag;
   uint32               event_flag;
   L1Audio_EventHandler hisrHandler[MAX_HISR_HANDLER];
   uint16               hisrMagicNo[MAX_HISR_HANDLER];
   void                 *hisrUserData[MAX_HISR_HANDLER];
   uint16               hisrMagicFlag;
   uint8                sleep_handle;
   int8                 dsp_slow_idle_counter;

   uint16               debug_info[NUM_DEBUG_INFO];

   kal_uint8            md2g_pdn_handle;
   kal_uint8            l1sm_handle;
   kal_uint8            audio_cpd_count;
   kal_semid            sema;
   bool                 is_Initialized;
	bool                 isD2MIntAvalibaleUnderSleep; // does Dsp to MCU interrupt can trigger under MCU sleep
} l1audio;


typedef struct{
    
    uint32 ul_framesize,  dl_framesize;
    uint32 ul_write_addr, dl_write_addr;
    volatile uint32* pu32_scp_ul_read; // invalidate cache
    volatile uint16* pu16_fd216_ul_write;
    volatile uint32* pu32_scp_dl_read; // invalidate cache
    volatile uint16* pu16_fd216_dl_write;
    
    volatile uint32* pu32_scp_ul_read_tmp;// invalidate cache
    volatile uint32* pu32_scp_dl_read_tmp;// invalidate cache
    
    uint32 ul_addr, dl_addr;
    
    kal_uint32 t_ul_get_start, t_ul_get_end; // time
    kal_uint32 t_ul_put_start, t_ul_put_end;
    
    kal_uint32 t_dl_get_start, t_dl_get_end;
    kal_uint32 t_dl_put_start, t_dl_put_end;

    kal_uint32 t_before_while, t_after_while;

}OPENDSP_T;

OPENDSP_T OpenDsp;
#define MODEM_FTR  ((volatile uint32*)(0xF00D0088)) // FTR free time runner	

extern void  od_memcpy(uint16 *dst, uint32 * src, uint32 len);


//#define L1_BASE_MADDR_SHARE_D1          REG_BASE(0xF77A0000)

#define  HW_WRITE(ptr,data)         (*(ptr) = (data))
#define  HW_READ(ptr)               (*(ptr)) 
#define  DSP_WRITE(addr, data)      HW_WRITE(addr, (kal_uint16)(data) )
#define  DSP_READ(addr)             HW_READ(addr)
   
#define DP_D2C_TASK4          ((APBADDR)(L1_BASE_MADDR_SHARE_D1+0x0060))     /* 4th FW tsk interrupt                                 */
#define DP_D2C_TASK5          ((APBADDR)(L1_BASE_MADDR_SHARE_D1+0x0064))     /* 5th FW tsk interrupt                                 */
#define DP_D2C_TASK6          ((APBADDR)(L1_BASE_MADDR_SHARE_D1+0x0068))     /* 6th FW tsk interrupt   															 */
#define DP_D2C_TASK7          ((APBADDR)(L1_BASE_MADDR_SHARE_D1+0x006C))     /* 6th FW tsk interrupt   															 */
/* ------------------------------------------------------------------------------ */
#ifndef TK6291_FAKE_COMPILE
extern void L1D_DSP_EnableDspSlowIdle( void );
#endif //#ifndef TK6291_FAKE_COMPILE
int8 L1Audio_Disable_DSPSlowIdle(void)
{
   uint32 savedMask;
   int8    dis_check_counter;

   savedMask = SaveAndSetIRQMask();
   l1audio.dsp_slow_idle_counter++;
   dis_check_counter = l1audio.dsp_slow_idle_counter;

   //DP_SLOW_IDLE_CTRL = 0xFFFF;
   RestoreIRQMask( savedMask );

   return dis_check_counter;
}

int8 L1Audio_Enable_DSPSlowIdle(void)
{
   uint32 savedMask;
   int8    en_check_counter;

   savedMask = SaveAndSetIRQMask();
   l1audio.dsp_slow_idle_counter--;
   en_check_counter = l1audio.dsp_slow_idle_counter;

#ifndef TK6291_FAKE_COMPILE
   if ( l1audio.dsp_slow_idle_counter == 0 )
       ;//L1D_DSP_EnableDspSlowIdle();
#endif //#ifndef TK6291_FAKE_COMPILE

   RestoreIRQMask( savedMask );
   ASSERT( en_check_counter >= 0 );

   return en_check_counter;
}

kal_bool L1Audio_CheckAudioID( kal_uint16 audio_id )
{
   if( l1audio.id_flag & (1 << audio_id) )
      return true;
   return false;
}

uint16 L1Audio_GetAudioID( void )
{
   uint32 I;
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
      if( (l1audio.id_flag & (1<<I)) == 0 ) {
         l1audio.id_flag |= (1<<I);
         break;
      }
   }
   RestoreIRQMask( savedMask );

   ASSERT( (l1audio.sleppModeLocker & (1 << I)) == 0 );
   ASSERT_REBOOT( I < MAX_AUDIO_FUNCTIONS );
   return (uint16)I;
}

void L1Audio_FreeAudioID( uint16 aud_id )
{
   uint32 savedMask;
   uint32 retrieved_events;
   kal_retrieve_eg_events(l1audio.aud_events,(1<<aud_id),KAL_OR_CONSUME,&retrieved_events,0);
   ASSERT( (l1audio.sleppModeLocker & (1 << aud_id)) == 0 );
   ASSERT( l1audio.id_flag & (1<<aud_id) );
   savedMask = SaveAndSetIRQMask();
   l1audio.id_flag &= ~(1<<aud_id);
   l1audio.retrieved_events &= ~(1<<aud_id);
   RestoreIRQMask( savedMask );
}

void L1Audio_SetEventHandler( uint16 audio_id, L1Audio_EventHandler handler )
{
   l1audio.evHandler[audio_id] = handler;
}

void L1Audio_SetEvent( uint16 audio_id, void *data )
{
   l1audio.evData[audio_id] = data;
   /* Activate L1Audio Task */
   kal_set_eg_events( l1audio.aud_events, 1 << audio_id, KAL_OR );
}

void L1Audio_LSetEvent( uint16 audio_id, void *data )
{
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   l1audio.evData[audio_id] = data;
   l1audio.event_flag |= (1 << audio_id);
   RestoreIRQMask( savedMask );

   /* Activate L1Audio HISR */
   kal_activate_hisr( l1audio.hisr );
}

void L1Audio_CCSetEvent( void )
{
   /* Activate L1Audio HISR */
   kal_activate_hisr( l1audio.hisr );
}

bool L1Audio_CheckFlag( uint16 audio_id )
{
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   if( l1audio.sleppModeLocker & (1 << audio_id) )
      return true;
   return false;
}

#if defined( __CENTRALIZED_SLEEP_MANAGER__ )

static void Audio_Wake_DSP(uint16 audio_id, kal_bool flag)
{
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL, audio_id, flag);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL, audio_id, flag);
      
   if(flag)
   {
#ifndef TK6291_FAKE_COMPILE
      RM_Resource_Control (RM_MODEM_DSP_1, flag);
#endif //#ifndef TK6291_FAKE_COMPILE

#if defined(MTK_SLEEP_ENABLE)
   #if defined(__AUDIO_POWERON_RESET_DSP__)
      #ifndef TK6291_NO_SPEECH_HW
      AFE_RegisterStore();                               //restore AFE register
      #endif //#ifndef TK6291_NO_SPEECH_HW
      {
         #ifndef TK6291_FAKE_COMPILE
         unsigned short DSP_status;     
         DSP_status = cc_L1D_Audio_RestartDSP();
         ASSERT(!DSP_status);
         #endif //#ifndef TK6291_FAKE_COMPILE
      }
   #else
      #ifndef TK6291_FAKE_COMPILE
      L1SM_IntSleepDisable( l1audio.l1sm_handle );
      L1SM_Multi_SW_WakeUp();
      L1D_MD2G_PWD_Disable(l1audio.md2g_pdn_handle);
      L1SM_IntSleepEnable( l1audio.l1sm_handle );
      #endif //#ifndef TK6291_FAKE_COMPILE
   #endif
#endif
      l1audio.audio_cpd_count++;
   } else {
#if defined(MTK_SLEEP_ENABLE)
   #if defined(__AUDIO_POWERON_RESET_DSP__)
      #ifndef TK6291_FAKE_COMPILE
      cc_L1D_Audio_NoNeedDSP();
      #endif //#ifndef TK6291_FAKE_COMPILE
      #ifndef TK6291_NO_SPEECH_HW
      AFE_RegisterBackup();                         //Backup AFE register
      #endif //#ifndef TK6291_NO_SPEECH_HW
   #else
      #ifndef TK6291_FAKE_COMPILE
      L1D_MD2G_PWD_Enable(l1audio.md2g_pdn_handle);
      #endif //#ifndef TK6291_FAKE_COMPILE
   #endif
#endif
      #ifndef TK6291_FAKE_COMPILE
      RM_Resource_Control (RM_MODEM_DSP_1, flag);
      #endif //#ifndef TK6291_FAKE_COMPILE
      l1audio.audio_cpd_count--;
   }
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL_DONE, audio_id, flag);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL_DONE, audio_id, flag);
}
#endif //( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))

void L1Audio_SetFlag( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_A,audio_id,l1audio.dspUser);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_A,audio_id,l1audio.dspUser);

   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( (l1audio.sleppModeLocker & (1 << audio_id)) == 0 );
	ASSERT( (l1audio.dspUser & (1 << audio_id)) == 0 );
	
   if( l1audio.dspUser == 0 ) {
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
      Audio_Wake_DSP(audio_id, KAL_TRUE);
#endif
   }

	if (false == l1audio.isD2MIntAvalibaleUnderSleep && l1audio.sleppModeLocker == 0) {
      	SLEEP_LOCK();
	}

   savedMask = SaveAndSetIRQMask();
	if (false == l1audio.isD2MIntAvalibaleUnderSleep) {
	   l1audio.sleppModeLocker |= (1 << audio_id);	
	}
   l1audio.dspUser |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   kal_give_sem( l1audio.sema ); 
}

void L1Audio_ClearFlag( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())  
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_A,audio_id,l1audio.dspUser);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_A,audio_id,l1audio.dspUser);

	kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
	ASSERT( l1audio.dspUser & (1 << audio_id) );
	if (false == l1audio.isD2MIntAvalibaleUnderSleep) {
   	ASSERT( l1audio.sleppModeLocker & (1 << audio_id) );
	}

   savedMask = SaveAndSetIRQMask();
	if (false == l1audio.isD2MIntAvalibaleUnderSleep) {
	   l1audio.sleppModeLocker &= ~(1 << audio_id);
	}
   l1audio.dspUser &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );

	if((false == l1audio.isD2MIntAvalibaleUnderSleep) && (l1audio.sleppModeLocker == 0) ) {
      SLEEP_UNLOCK();
   }
	
   if( l1audio.dspUser == 0 ) {      
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
      Audio_Wake_DSP(audio_id, KAL_FALSE);
#endif
   }
   kal_give_sem( l1audio.sema ); 
}

void L1Audio_SetFlag_MD2G( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_MD2G_A,audio_id,l1audio.dspUser);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_MD2G_A,audio_id,l1audio.dspUser);

   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( (l1audio.dspUser & (1 << audio_id)) == 0 );

   if( l1audio.dspUser == 0 ) {
#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
      Audio_Wake_DSP(audio_id,KAL_TRUE);
#endif
   }

   savedMask = SaveAndSetIRQMask();
   l1audio.dspUser |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   kal_give_sem( l1audio.sema ); 
}

void L1Audio_ClearFlag_MD2G( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())  
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_MD2G_A,audio_id,l1audio.dspUser);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_MD2G_A,audio_id,l1audio.dspUser);
      
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.dspUser & (1 << audio_id) );

   savedMask = SaveAndSetIRQMask();
   l1audio.dspUser &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );
   
   if(l1audio.dspUser == 0 ) {
#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
      Audio_Wake_DSP(audio_id,KAL_FALSE);
#endif
   }
   kal_give_sem( l1audio.sema ); 
}


void L1Audio_AllowSleep( kal_uint16 audio_id )
{
   uint32 savedMask;

   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.sleppModeLocker & (1 << audio_id) );

   savedMask = SaveAndSetIRQMask();
   l1audio.sleppModeLocker &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );

   if( l1audio.sleppModeLocker == 0)
      SLEEP_UNLOCK();
}

void L1Audio_DisallowSleep( kal_uint16 audio_id )
{
   uint32 savedMask;

   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( (l1audio.sleppModeLocker & (1 << audio_id)) == 0 );

   savedMask = SaveAndSetIRQMask();
   l1audio.sleppModeLocker |= (1 << audio_id);
   RestoreIRQMask( savedMask );

   if(l1audio.sleppModeLocker)
      SLEEP_LOCK();
}

/* ------------------------------------------------------------------------------ */
/*  L1Audio HISR                                                                  */
/* ------------------------------------------------------------------------------ */

void L1Audio_HISR( void )
{
   uint32 savedMask;
   int32  I;

  //L1Audio_Disable_DSPSlowIdle();

   if( l1audio.hisrMagicFlag ) {
      for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
         if( l1audio.hisrMagicFlag & (1<<I) ) {
            savedMask = SaveAndSetIRQMask();
            l1audio.hisrMagicFlag &= ~(1<<I);
            RestoreIRQMask( savedMask );
            l1audio.hisrHandler[I]( l1audio.hisrUserData[I] );
         }
      }
   }

   if( l1audio.event_flag ) {
      int16 I;
      for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
         if( l1audio.event_flag & (1<<I) ) {
            savedMask = SaveAndSetIRQMask();
            l1audio.event_flag &= ~(1<<I);
            RestoreIRQMask( savedMask );
            L1Audio_SetEvent( I, l1audio.evData[I] );
         }
      }
   }

   SP_CC_Event_Handler();
   // To restore slow idle ctrl for DSP
   //L1Audio_Enable_DSPSlowIdle();
}


void L1Audio_TrigD2CHisr(uint16 magicNo)
{
	int32 I;
	   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( magicNo == l1audio.hisrMagicNo[I] ) {
         l1audio.hisrMagicFlag |= (1<<I);
         kal_activate_hisr(l1audio.hisr);
         return; 
      }
   }
	
}

#if defined(__OPEN_DSP_SPEECH_SUPPORT__)
void L1SP_OD_UL_GET()
{
    
  uint32 dur;
  dur = 0;  	
      
	uint32 time_value = *(MODEM_FTR); // FTR free time runner		
    
    L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), 0x1111, 0x1, (*DPRAM_base(SPH_OD_UL_CNTR )));    
    
    
	L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), ((time_value) >> 16), (time_value& 0xFFFF),0);
  {
  	 uint32 ftime = fma_get_glb_ts();  	 
  	 L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), ((ftime) >> 16), (ftime& 0xFFFF),1);
  }			
    // UL Get Start
    
    addUlIrqCnt();
    L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), 0, 0, getUlIrqCnt());

    
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(0), (OpenDsp.t_ul_get_start = ust_get_current_time()));	
    L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(1), *DPRAM_base(SPH_OD_INT_CTRL2)); 
	L1Audio_Msg_DSP_OD_DELAY_TIME(L1AUDIO_OD_Val(0),SAL_OpenDSP_IsOFF());
	ASSERT(SAL_OpenDSP_IsOFF() == 0);

	// check DSP and SCP Handshake
	if((*DPRAM_base(SPH_OD_HANDSHAKE_OD) != 1) && (*DPRAM_base(SPH_OD_HANDSHAKE_OD) != 2)) {
		L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Val(0),(*DPRAM_base(SPH_OD_HANDSHAKE_OD)));
		time_value= *(MODEM_FTR); // FTR free time runner		
		L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), ((time_value) >> 16), (time_value& 0xFFFF),2);
		ASSERT(0);
	}	
	time_value= *(MODEM_FTR); // FTR free time runner	
	L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), ((time_value) >> 16), (time_value& 0xFFFF),3); 
	*DPRAM_base(SPH_FRC_TIME_UP) = time_value >> 16;
	*DPRAM_base(SPH_FRC_TIME_DOWN) = time_value & 0xFFFF;
	L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), *DPRAM_base(SPH_FRC_TIME_UP), *DPRAM_base(SPH_FRC_TIME_DOWN),4);
    *DPRAM_base(SPH_OD_INT_CTRL2) |= 0x0001;  // set SPH_OD_INT_CTRL2 to 0x1
    Drv_MD2AP_SetScenario(MDAPI_BIT14);      // mcu interrupts OpenDsp UL INT


    L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(0), *DPRAM_base(SPH_OD_HANDSHAKE_OD)); 
    L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(1), *DPRAM_base(SPH_OD_INT_CTRL2)); 

    OpenDsp.t_before_while = ust_get_current_time(); 
    while(1){
        if((*DPRAM_base(SPH_OD_INT_CTRL2)&0x1) == 0){
                Drv_MD2AP_ClearScenario(MDAPI_BIT14); // clear OpenDsp INT
                break;
        }
    }
    //counter after polling
    L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), 0x1111, 0x2, (*DPRAM_base(SPH_OD_UL_CNTR )));    
        
    OpenDsp.t_after_while = ust_get_current_time();

    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(8), ((dur = ust_us_duration(OpenDsp.t_before_while, OpenDsp.t_after_while))));
	L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(1), *DPRAM_base(SPH_OD_INT_CTRL2)); 
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(1), (OpenDsp.t_ul_get_end = ust_get_current_time()));
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(2), (ust_us_duration(OpenDsp.t_ul_get_start, OpenDsp.t_ul_get_end)));
	if(dur > 1000){
		time_value= *(MODEM_FTR); // FTR free time runner
		L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), ((time_value) >> 16), (time_value& 0xFFFF),5);
		//ASSERT(dur <= 1000);
	}
	
}


void L1SP_OD_UL_PUT()
{
  uint32 dur;
  dur = 0;  
  uint32 time_value = *(MODEM_FTR); // FTR free time runner		
	L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(1), ((time_value) >> 16), (time_value& 0xFFFF),0);
	{
  	 uint32 ftime = fma_get_glb_ts();  	 
  	 L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(1), ((ftime) >> 16), (ftime& 0xFFFF),1);
  }	
    OpenDsp.t_ul_put_start = ust_get_current_time();
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(3), OpenDsp.t_ul_put_start);
	L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(0), OpenDsp.t_ul_get_start);
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(7), ((dur = ust_us_duration(OpenDsp.t_ul_get_start, OpenDsp.t_ul_put_start))));
	L1Audio_Msg_DSP_OD_DELAY_TIME(L1AUDIO_OD_Val(0),SAL_OpenDSP_IsOFF());
	ASSERT(SAL_OpenDSP_IsOFF() == 0);
	
	if(dur > 11000){
		L1Audio_Msg_DSP_OD_DELAY_TIME(L1AUDIO_OD_Time(7),dur);
		time_value = *(MODEM_FTR); // FTR free time runner				
		L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(1), ((time_value) >> 16), (time_value& 0xFFFF),2);
	}
    
    uint32 hi = (*DPRAM_base(SPH_OD_TCM_ADDR_H)) << 16;
    uint32 lo = (*DPRAM_base(SPH_OD_TCM_ADDR_L));
    uint32 addr = (hi | lo) + 0xC0020000 ;  
    OpenDsp.ul_addr = addr;



    L1Audio_Msg_DSP_OD_INT_ADDRESS(L1AUDIO_OD_Addr(0), (addr >> 16), addr); // TCM address


    OpenDsp.pu16_fd216_ul_write = SAL_PcmEx_GetBuf(SAL_PCMEX_OD_BUF_UL); // read UL DM
    OpenDsp.pu32_scp_ul_read = addr; // ul tone
    OpenDsp.ul_framesize = SAL_PcmEx_GetBufLen(SAL_PCMEX_OD_BUF_UL);


    L1Audio_Msg_DSP_OD_INT_ADDRESS(L1AUDIO_OD_Addr(1), ((uint32)(OpenDsp.pu32_scp_ul_read)) >> 16,    (uint32)(OpenDsp.pu32_scp_ul_read)); // ul read addr
    L1Audio_Msg_DSP_OD_INT_ADDRESS(L1AUDIO_OD_Addr(2), ((uint32)(OpenDsp.pu16_fd216_ul_write)) >> 16, (uint32)(OpenDsp.pu16_fd216_ul_write)); //ul write addr


    L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(2), OpenDsp.ul_framesize); 


    if(OpenDsp.ul_addr!=0 && OpenDsp.dl_addr!=0){
        OpenDsp.pu32_scp_dl_read_tmp = OpenDsp.dl_addr;
        L1Audio_Msg_DSP_OD_TMP_VAL(L1AUDIO_OD_Val(4), (OpenDsp.ul_addr >> 16), OpenDsp.ul_addr, OpenDsp.pu32_scp_ul_read[0],     OpenDsp.pu32_scp_ul_read[1],     OpenDsp.pu32_scp_ul_read[2],     OpenDsp.pu32_scp_ul_read[3]);
        L1Audio_Msg_DSP_OD_TMP_VAL(L1AUDIO_OD_Val(4), (OpenDsp.dl_addr >> 16), OpenDsp.dl_addr, OpenDsp.pu32_scp_dl_read_tmp[0], OpenDsp.pu32_scp_dl_read_tmp[1], OpenDsp.pu32_scp_dl_read_tmp[2], OpenDsp.pu32_scp_dl_read_tmp[3]);
        
        uint32 *t = OpenDsp.pu16_fd216_ul_write;
        L1Audio_Msg_DSP_OD_TMP_VAL(L1AUDIO_OD_Val(5), ((uint32)(OpenDsp.pu16_fd216_ul_write)) >> 16, (uint32)(OpenDsp.pu16_fd216_ul_write), t[0], t[1], t[2], t[3]);

    }
		od_memcpy(OpenDsp.pu16_fd216_ul_write, OpenDsp.pu32_scp_ul_read, OpenDsp.ul_framesize << 1);
    uint32 *tmp = OpenDsp.pu16_fd216_ul_write;
    L1Audio_Msg_DSP_OD_TMP_VAL(L1AUDIO_OD_Val(5), ((uint32)(OpenDsp.pu16_fd216_ul_write)) >> 16, (uint32)(OpenDsp.pu16_fd216_ul_write), tmp[0], tmp[1], tmp[2], tmp[3]);

	
    SAL_OpenDSP_Handshake_MD(1, 0);
    OpenDsp.t_ul_put_end = ust_get_current_time();
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(4), OpenDsp.t_ul_put_end);
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(5), (ust_us_duration(OpenDsp.t_ul_put_start, OpenDsp.t_ul_put_end)));                     
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(6), (ust_us_duration(OpenDsp.t_ul_get_start, OpenDsp.t_ul_put_end)));  
    L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(0), *DPRAM_base(SPH_OD_HANDSHAKE_OD)); 

}


void L1SP_OD_DL_GET()
{    

  

  uint32 dur;
  dur = 0;
	uint32 time_value= *(MODEM_FTR); // FTR free time runner	
    
    L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), 0x2222, 0x1, (*DPRAM_base(SPH_OD_DL_CNTR )));
    
    
	L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(2), ((time_value) >> 16), (time_value& 0xFFFF),0);
  {
  	 uint32 ftime = fma_get_glb_ts();  	 
  	 L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(2), ((ftime) >> 16), (ftime& 0xFFFF),1); 
  }	
  	
    // DL Get Start
    
    addDlIrqCnt();
    L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), 0, 0, getDlIrqCnt());

    OpenDsp.t_dl_get_start = ust_get_current_time();
	L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(9), OpenDsp.t_dl_get_start);	
    L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(1), *DPRAM_base(SPH_OD_INT_CTRL2)); 
	L1Audio_Msg_DSP_OD_DELAY_TIME(L1AUDIO_OD_Val(0),SAL_OpenDSP_IsOFF());
	ASSERT(SAL_OpenDSP_IsOFF() == 0);

	// check DSP and SCP Handshake
	if((*DPRAM_base(SPH_OD_HANDSHAKE_OD) != 1) && (*DPRAM_base(SPH_OD_HANDSHAKE_OD) != 2)) {
		L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Val(0),(*DPRAM_base(SPH_OD_HANDSHAKE_OD)));
		time_value= *(MODEM_FTR); // FTR free time runner		
		L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(2), ((time_value) >> 16), (time_value& 0xFFFF),2);
		ASSERT(0);
	}	

	time_value= *(MODEM_FTR); // FTR free time runner	
	L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(2), ((time_value) >> 16), (time_value& 0xFFFF),3);
	*DPRAM_base(SPH_FRC_TIME_UP) = time_value >> 16;
	*DPRAM_base(SPH_FRC_TIME_DOWN) = time_value & 0xFFFF;	
	L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(2), *DPRAM_base(SPH_FRC_TIME_UP), *DPRAM_base(SPH_FRC_TIME_DOWN),4);
		
    *DPRAM_base(SPH_OD_INT_CTRL2) |= 0x0001;  // set SPH_OD_INT_CTRL2 to 0x1
    Drv_MD2AP_SetScenario(MDAPI_BIT14);      // mcu interrupts OpenDsp DL


    L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(0), *DPRAM_base(SPH_OD_HANDSHAKE_OD)); 
    L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(1), *DPRAM_base(SPH_OD_INT_CTRL2)); 

    OpenDsp.t_before_while = ust_get_current_time(); 

    while(1){
        if((*DPRAM_base(SPH_OD_INT_CTRL2)&0x1) == 0){
                Drv_MD2AP_ClearScenario(MDAPI_BIT14); // clear INT
                break;
        }
    }
    
    //counter after polling
    L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(0), 0x2222, 0x2, (*DPRAM_base(SPH_OD_DL_CNTR )));
    OpenDsp.t_after_while = ust_get_current_time();

    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(17), ((dur = ust_us_duration(OpenDsp.t_before_while, OpenDsp.t_after_while))));
	L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(1), *DPRAM_base(SPH_OD_INT_CTRL2)); 
    OpenDsp.t_dl_get_end = ust_get_current_time();
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(10), OpenDsp.t_dl_get_end);
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(11), (ust_us_duration(OpenDsp.t_dl_get_start, OpenDsp.t_dl_get_end)));
	if(dur > 1000){
		time_value= *(MODEM_FTR); // FTR free time runner
		L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(2), ((time_value) >> 16), (time_value& 0xFFFF),5);		 
		//ASSERT(dur <= 1000);
	}
	
}


void L1SP_OD_DL_PUT(){
    
  uint32 dur;
  dur = 0;  
	uint32 time_value = *(MODEM_FTR); // FTR free time runner		
	L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(3), ((time_value) >> 16), (time_value& 0xFFFF),0);	
	{
  	 uint32 ftime = fma_get_glb_ts();  	 
  	 L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(3), ((ftime) >> 16), (ftime& 0xFFFF),1); 
  }	
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(12), (OpenDsp.t_dl_put_start = ust_get_current_time()));
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(16), (dur = (ust_us_duration(OpenDsp.t_dl_get_start, OpenDsp.t_dl_put_start))));
	L1Audio_Msg_DSP_OD_DELAY_TIME(L1AUDIO_OD_Val(0),SAL_OpenDSP_IsOFF());
	ASSERT(SAL_OpenDSP_IsOFF() == 0);
	
    if(dur > 3500){
		L1Audio_Msg_DSP_OD_DELAY_TIME(L1AUDIO_OD_Time(16),dur);
		time_value = *(MODEM_FTR); // FTR free time runner		
		L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(3), ((time_value) >> 16), (time_value& 0xFFFF),2);			
	}
    //ASSERT(dur <= 3500);
    
    uint32 hi = (*DPRAM_base(SPH_OD_TCM_ADDR_H)) << 16;
    uint32 lo = (*DPRAM_base(SPH_OD_TCM_ADDR_L));
    uint32 addr = (hi | lo) + 0xC0020000 ;
    OpenDsp.dl_addr = addr;
     
    L1Audio_Msg_DSP_OD_INT_ADDRESS(L1AUDIO_OD_Addr(3), (addr >> 16), addr); // TCM address

    OpenDsp.pu16_fd216_dl_write = SAL_PcmEx_GetBuf(SAL_PCMEX_OD_BUF_DL); // read DL DM
    OpenDsp.pu32_scp_dl_read = addr; // DL tone = 4k
    OpenDsp.dl_framesize = SAL_PcmEx_GetBufLen(SAL_PCMEX_OD_BUF_DL);


    L1Audio_Msg_DSP_OD_INT_ADDRESS(L1AUDIO_OD_Addr(4), ((uint32)(OpenDsp.pu32_scp_dl_read)) >> 16,    (uint32)(OpenDsp.pu32_scp_dl_read)); // ul read addr
    L1Audio_Msg_DSP_OD_INT_ADDRESS(L1AUDIO_OD_Addr(5), ((uint32)(OpenDsp.pu16_fd216_dl_write)) >> 16, (uint32)(OpenDsp.pu16_fd216_dl_write)); //ul write addr


    L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(3), OpenDsp.dl_framesize);


    if(OpenDsp.ul_addr!=0 && OpenDsp.dl_addr!=0){
        
        OpenDsp.pu32_scp_ul_read_tmp = OpenDsp.ul_addr;
        L1Audio_Msg_DSP_OD_TMP_VAL(L1AUDIO_OD_Val(6), (OpenDsp.ul_addr >> 16), OpenDsp.ul_addr, OpenDsp.pu32_scp_ul_read_tmp[0], OpenDsp.pu32_scp_ul_read_tmp[1], OpenDsp.pu32_scp_ul_read_tmp[2], OpenDsp.pu32_scp_ul_read_tmp[3]);
        L1Audio_Msg_DSP_OD_TMP_VAL(L1AUDIO_OD_Val(6), (OpenDsp.dl_addr >> 16), OpenDsp.dl_addr, OpenDsp.pu32_scp_dl_read[0],     OpenDsp.pu32_scp_dl_read[1],     OpenDsp.pu32_scp_dl_read[2],     OpenDsp.pu32_scp_dl_read[3]);
        uint32 *t = OpenDsp.pu16_fd216_dl_write;
        L1Audio_Msg_DSP_OD_TMP_VAL(L1AUDIO_OD_Val(7), ((uint32)(OpenDsp.pu16_fd216_dl_write)) >> 16, (uint32)(OpenDsp.pu16_fd216_dl_write), t[0], t[1], t[2], t[3]);

    }
		od_memcpy(OpenDsp.pu16_fd216_dl_write, OpenDsp.pu32_scp_dl_read, OpenDsp.dl_framesize  << 1);		

	uint32 *tmp = OpenDsp.pu16_fd216_dl_write;

    L1Audio_Msg_DSP_OD_TMP_VAL(L1AUDIO_OD_Val(7), ((uint32)(OpenDsp.pu16_fd216_dl_write)) >> 16, (uint32)(OpenDsp.pu16_fd216_dl_write), tmp[0], tmp[1], tmp[2], tmp[3]);


    SAL_OpenDSP_Handshake_MD(0, 1);

    
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(13), (OpenDsp.t_dl_put_end = ust_get_current_time()));
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(14), (ust_us_duration(OpenDsp.t_dl_put_start, OpenDsp.t_dl_put_end)));                     
    L1Audio_Msg_DSP_OD_INT_TIME(L1AUDIO_OD_Time(15), (ust_us_duration(OpenDsp.t_dl_get_start, OpenDsp.t_dl_put_end)));
    L1Audio_Msg_DSP_OD_INT_VALUE(L1AUDIO_OD_Val(0), *DPRAM_base(SPH_OD_HANDSHAKE_OD)); 

}
#endif /*#if defined(__OPEN_DSP_SPEECH_SUPPORT__)*/


void L1SP_D2C_LISR( uint16 itype )
{
	uint32 sph_int = 0;
	bool dsp_ok = false;
	bool from_sph;

   l1audio.d2c_itype = itype;
#ifndef TK6291_FAKE_COMPILE
   l1audio.d2c_l1FN = 0;//L1I_GetTimeStamp();
#else //#ifndef TK6291_FAKE_COMPILE
   l1audio.d2c_l1FN = 0;
#endif //#ifndef TK6291_FAKE_COMPILE
   L1Audio_Msg_DSP_INT( itype );

   if(itype == D2C_DSP_DEAD_INT_ID){
#ifndef  L1D_TEST
      ASSERT_DUMP_PARAM_T dump_param;
      dump_param.addr[0] = (kal_uint32)(DPRAM_CPU_base +0x0A0*2);
      dump_param.len[0]  = 70*2;
      dump_param.addr[1] = (kal_uint32)(DPRAM2_CPU_base+0x130*2);
      dump_param.len[1]  = 180*2;
      dump_param.addr[2] = 0;    //End of dump param
      EXT_ASSERT_DUMP(0, 0x20060622, 0, 0, &dump_param);
#else
      extern void  L1DTest_AssertFail(void);
      L1DTest_AssertFail();
#endif
   }

   from_sph = SAL_DSPINT_Resolve(itype, &sph_int);//the itype should be the real one sent directly from DSP

	L1Audio_Msg_DSP_D2C_SPEECH_INT(L1AUDIO_Str_Bool(from_sph), (sph_int >> 16), sph_int);
	
	if(from_sph) {
		
		kal_int16 i;
		for( i=1; i< SAL_DSPINT_PRIO_MAX; i++) {
			if(sph_int & (1 << i)) {
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
				#endif /*#if 0*/
								#if defined(__OPEN_DSP_SPEECH_SUPPORT__)
                	if(SAL_DSPINT_PRIO_OD_UL_GET == i){
                        L1SP_OD_UL_GET();
                    }
                    if(SAL_DSPINT_PRIO_OD_UL_PUT == i){
                        L1SP_OD_UL_PUT();
                    }
                    if(SAL_DSPINT_PRIO_OD_DL_GET == i){
                        L1SP_OD_DL_GET();
                    }
                    if(SAL_DSPINT_PRIO_OD_DL_PUT == i){
                        L1SP_OD_DL_PUT();
                    }
                #endif /*#if defined(__OPEN_DSP_SPEECH_SUPPORT__)*/
					L1Audio_TrigD2CHisr(DP_D2C_INT_MAPPING_BASIC+i); // please reference to 
				#if 0
/* under construction !*/
				#endif /*#if 0*/
	         dsp_ok |= true;
			}
		}
		/*
		// original mapping
      if(sph_int & SAL_DSPINT_ID_REC_VM){ // vm record
	  		L1Audio_TrigD2CHisr(DP_D2C_VM_REC_INT);
         dsp_ok |= true;
      }

		if(sph_int & SAL_DSPINT_ID_REC_PCM){ // pcm record
	  		L1Audio_TrigD2CHisr(DP_D2C_PCM_REC_INT);
         dsp_ok |= true;
      }
	  
      if(sph_int & SAL_DSPINT_ID_PNW_DL){ // pnw
			 L1Audio_TrigD2CHisr(DP_D2C_PCM_EX_DL); // DP_D2C_PCM_EX_DL, pcmNway
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_DACA_DL){ // data card
         L1Audio_TrigD2CHisr(DP_D2C_DACA_REQ_DL); // data card
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_3G_DL){ // 3g dl
         //L1SP_D2C_LISR(DP_D2C_3G_DONE_DL);//Don't trigger LISR here. 3G driver will trigger HISR by it's timing
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_BGS){ // background sound
         L1Audio_TrigD2CHisr(D2C_SOUND_EFFECT_INT_ID); // background sound, SND_EFFECT_MAGIC_NO
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_AVBT){ //AVBT
         L1Audio_TrigD2CHisr(D2C_AUDIO_VIA_BT_ID);
         dsp_ok |= true;
      }

      if(sph_int & SAL_DSPINT_ID_REC_EPL){
         L1Audio_TrigD2CHisr(DP_D2C_VMEPL_REC_INT); // call record pcm, call record vm
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_PNW_UL){
         L1Audio_TrigD2CHisr(DP_D2C_PCM_EX_UL); // pcmnway ul
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_DACA_UL){
         L1Audio_TrigD2CHisr(DP_D2C_DACA_REQ_UL); // data card
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_3G_UL){
         L1Audio_TrigD2CHisr(DP_D2C_3G_DONE_UL); // 3g
         dsp_ok |= true;
      }
	 */
	 
      if(0 != sph_int){//After DSP send D2C and turn on bit in DP_D2C_SPEECH_UL_INT, but  MCU doesnt  receive D2C. Handover causes VBIReset which will clean DP_D2C_SPEECH_UL_INT
         if (!dsp_ok) {
            extern void L1D_WIN_DisableAllEvents(uint16 except_irq_mask);
            DisableIRQ();
            ASSERT(0);
            //L1D_WIN_DisableAllEvents( 0 ); /* disable all TDMA events */
            ASSERT_REBOOT(0);
         }
      }else{
	   	L1Audio_Msg_DSP_D2C_SPEECH_INT_SKIP((sph_int >> 16), sph_int);
      }
	  
	// if(from_sph)  
		return;
   } 

   l1audio.media_flag = itype;
   kal_activate_hisr(l1audio.hisr);
}

void L1Audio_ActivateHisrHandler(kal_uint16 magic_no, void *userData)
{
   uint32 I, uMask32;
   uMask32 = SaveAndSetIRQMask();
   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( magic_no == l1audio.hisrMagicNo[I] ) {
         l1audio.hisrMagicFlag |= (1<<I);
         l1audio.hisrUserData[I] = userData;
      }
   }
   RestoreIRQMask( uMask32 );
   if(l1audio.hisrMagicFlag != 0)
      kal_activate_hisr(l1audio.hisr);
}

void L1Audio_HookHisrHandler( kal_uint16 magic_no, L1Audio_EventHandler handler, void *userData )
{
   int32 I;
   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( l1audio.hisrMagicNo[I] == 0 ) {
         l1audio.hisrMagicNo[I] = magic_no;
         l1audio.hisrHandler[I] = handler;
         l1audio.hisrUserData[I] = userData;
         break;
      }
   }
   ASSERT_REBOOT( I != MAX_HISR_HANDLER );
}

void L1Audio_UnhookHisrHandler( kal_uint16 magic_no )
{
   int32 I;
   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( l1audio.hisrMagicNo[I] == magic_no ) {
         l1audio.hisrMagicNo[I] = 0;
         break;
      }
   }
   ASSERT_REBOOT( I != MAX_HISR_HANDLER );
}

void L1Audio_SetDebugInfo( kal_uint16 debug_info[NUM_DEBUG_INFO])
{
   memcpy(l1audio.debug_info, debug_info, NUM_DEBUG_INFO*sizeof(uint16));
}

void L1Audio_SetDebugInfoN( kal_uint16 index, kal_uint16 debug_info )
{
   l1audio.debug_info[index] = debug_info;
}

kal_uint16 L1Audio_GetDebugInfo( kal_uint8 index )
{
   ASSERT( index < NUM_DEBUG_INFO );
   return l1audio.debug_info[index];
}

/* ------------------------------------------------------------------------------ */
/*  Debug functions used to verify the data written to DSP                        */
/* ------------------------------------------------------------------------------ */
#if VERIFY_DATA_TO_DSP
#include   "fat_fs.h"
kal_uint8  bDSPBuffer[8192];
kal_uint16 uDSPBufferRead;
kal_uint16 uDSPBufferWrite;
kal_uint32 uDSPBufferSize;
kal_uint16 fname[12] = { 'E', ':', '\\', 'D', 'A', 'T', 'A', '.', 'D', 'A', 'T', 0x00 };
FS_HANDLE  fs_handle = 0;

void VERIFY_DATA_TO_DSP_START( void )
{
   if( fs_handle )
      FS_Close( fs_handle );
   fs_handle = FS_Open( (const kal_wchar*)fname, FS_CREATE_ALWAYS );
   ASSERT( fs_handle > 0 );
   uDSPBufferSize = 8192;
   uDSPBufferRead = 0;
   uDSPBufferWrite = 0;
}

void VERIFY_DATA_TO_DSP_RESUME( void )
{
   kal_uint32 uFileSize;
   kal_int32  ret;
   fs_handle = FS_Open( (const kal_wchar*)fname, FS_READ_WRITE|FS_CREATE );
   ASSERT( fs_handle > 0 );
   if(FS_GetFileSize(fs_handle, &uFileSize) < 0)
     ASSERT(0);
   if(FS_Seek(fs_handle, uFileSize, FS_FILE_BEGIN) < 0)
     ASSERT(0);
   uDSPBufferSize = 8192;
}

void VERIFY_DATA_TO_DSP_STOP( void )
{
   if( fs_handle )
   {
      if (FS_Close( fs_handle ) != 0)
         ASSERT(0);
      fs_handle = 0;
   }
}

void VERIFY_DATA_TO_DSP_WRITE_DATA( const kal_uint16 *buf, int32 len )
{
   kal_uint32 uDSPBufferFree;
   if( uDSPBufferWrite < uDSPBufferRead )
   {  /// DDDDWxxxxxxxRDD
      uDSPBufferFree = uDSPBufferRead - uDSPBufferWrite - 1;
      ASSERT( len*2 <= uDSPBufferFree );
      memcpy(bDSPBuffer+uDSPBufferWrite, buf, len*2);
      uDSPBufferWrite += len*2;
   }
   else
   {  /// xxxRDDDDDDWxxxx
      kal_uint32 free_1, free_2, write_count;
      free_1 = uDSPBufferSize - uDSPBufferWrite;
      free_2 = uDSPBufferRead - 1;
      uDSPBufferFree = free_1 + free_2;
      ASSERT( len*2 <= uDSPBufferFree );
      write_count = ( len*2 > free_1 )? free_1 : len*2;
      memcpy(bDSPBuffer+uDSPBufferWrite, buf, write_count);
      uDSPBufferWrite += write_count;
      if( uDSPBufferWrite==uDSPBufferSize )
         uDSPBufferWrite = 0;
      write_count = len*2 - write_count;
      if( write_count )
         memcpy(bDSPBuffer+uDSPBufferWrite, buf, write_count);
      uDSPBufferWrite += write_count;
   }
}

void VERIFY_DATA_TO_DSP_SAVE_DATA( void )
{
   if( fs_handle != 0 && uDSPBufferRead != uDSPBufferWrite )
   {
      kal_uint32 uDSPBufferUsed;
      kal_uint32 uDataSaved;
      if( uDSPBufferRead < uDSPBufferWrite )
      {  /// xxxRDDDDDDWxxxx
         uDSPBufferUsed = uDSPBufferWrite - uDSPBufferRead;
         FS_Write( fs_handle, bDSPBuffer+uDSPBufferRead, uDSPBufferUsed, &uDataSaved );
         ASSERT( uDSPBufferUsed == uDataSaved );
         uDSPBufferRead += uDataSaved;
      }
      else
      {  /// DDDDWxxxxxxxRDD
         kal_uint32 used_1, used_2, write_count;
         used_1 = uDSPBufferSize - uDSPBufferRead;
         FS_Write( fs_handle, bDSPBuffer+uDSPBufferRead, used_1, &uDataSaved );
         ASSERT( used_1 == uDataSaved );
         used_2 = uDSPBufferWrite;
         FS_Write( fs_handle, bDSPBuffer, used_2, &uDataSaved );
         ASSERT( used_2 == uDataSaved );
         uDSPBufferRead = uDataSaved;
      }
   }
}
#endif

/* ------------------------------------------------------------------------------ */
/*  L1Audio Task                                                                  */
/* ------------------------------------------------------------------------------ */

#ifndef TK6291_FAKE_COMPILE
extern unsigned short L1D_Audio_ChkDspInitDone();
#endif //#ifndef TK6291_FAKE_COMPILE

#ifdef __DHL_MODULE__
void tst_dummy_callback(const kal_uint8* pData, kal_uint32 nLen){
}	
#endif

kal_enhmutexid sp_handover_mutex; //just for 4G and 4G
#if defined(__VOLTE_SUPPORT__)
kal_enhmutexid sp4g_dl_mutex;
kal_enhmutexid sp4g_ul_mutex;
uint32 g_retrieved_events;
#endif

kal_enhmutexid sp_cc_mutex;
#define  DSP_DSP_EXCEPTION_ID             0x003E
#define  DSP_MPU_VIOLATION                0x003F

void L1Audio_DSP2MCU_Interrupt(){
	
   volatile uint16  data1, data2;

   //static kal_uint32 uReentry = 0;

   //if( uReentry )
   //{  ASSERT_bypass(0);  }
   //uReentry = 1;
		kal_trace( TRACE_FUNC, AUDIO_SERVICE_DSP2MCU);
   // mask D2C interrupt and Ack D2M interrupt 
   IRQMask(IRQ_DSP2CPU_CODE); ///////////////////////////////////Include ??

   data1 = DSP_READ( SHARE_D2MSTA );

   // TASK4 
   data2 = DSP_READ( DP_D2C_TASK4 );
   if( data1&0x10 && data2!=0x8888 )
   {  if( data2!=0x0000 )
      {
         //void L1SP_D2C_LISR( uint16 itype );
         kal_trace( TRACE_FUNC, AUDIO_SERVICE_DSP2MCU_TASK4);
         L1SP_D2C_LISR( data2 );
      }
   }

   //TASK5
   data2 = DSP_READ( DP_D2C_TASK5 );
   if( data1&0x20 && data2!=0x0000 )
   {
      //void L1SP_D2C_LISR( uint16 itype );
      kal_trace( TRACE_FUNC, AUDIO_SERVICE_DSP2MCU_TASK5);
      L1SP_D2C_LISR( data2 );
   }


   //TASK6 
   data2 = DSP_READ( DP_D2C_TASK6 );
   if( data1&0x40 && data2!=0x0000 )
   {
      //void L1SP_D2C_LISR( uint16 itype );
      kal_trace( TRACE_FUNC, AUDIO_SERVICE_DSP2MCU_TASK6);
      L1SP_D2C_LISR( data2 );
   }


   /** TASK7 ***************************/
   // IO(0x7) is used for DSP crash interrupt
   data2 = DSP_READ( DP_D2C_TASK7 );
   if( data1&0x80 )
   {
   	#if defined(__OPEN_DSP_SPEECH_SUPPORT__)
   	  uint32 time_value = *(MODEM_FTR); // FTR free time runner			  
		L1Audio_Msg_DSP_OD_FRC(L1AUDIO_OD_FRC(4), ((time_value) >> 16), (time_value& 0xFFFF),0);
		#endif
      if( data2==DSP_DSP_EXCEPTION_ID )  /* DSP crash*/
      {
      	 DSP_WRITE( DP_MCU_STATUS_, 0 );           /* freeze DSP */
      	 kal_trace( TRACE_FUNC, AUDIO_SERVICE_DSP2MCU_TASK7_DSP_DIE);
      #ifndef L1D_TEST
         ASSERT(0);
      #endif
      }
      else if( data2==DSP_MPU_VIOLATION )
      {
         ASSERT(0);
      }
   }
   

   //uReentry=0;

   // unmask D2C interrupt 
   IRQUnmask(IRQ_DSP2CPU_CODE);

   

}

bool L1Audio_IsInitialized(){
   return l1audio.is_Initialized;
}

#if 1
void L1Audio_Task(unsigned argc, void *argv)
{
   uint32 retrieved_events;
   uint32 I;
   kal_uint16 initaud_id;

   /*-----------------------------*/
   /* enable FD216 DSP event (pcore) */
   /*-----------------------------*/
   
   IRQSensitivity(IRQ_DSP2CPU_CODE,  LEVEL_SENSITIVE);
   IRQ_Register_LISR(IRQ_DSP2CPU_CODE, L1Audio_DSP2MCU_Interrupt, "L1Audio_DSP2CPU" );
   IRQUnmask(IRQ_DSP2CPU_CODE);
   
#ifdef __DHL_MODULE__
   tst_vc_register_channel(TVCI_VM_LOGGING, tst_dummy_callback);
#endif

   sp_cc_mutex = kal_create_enh_mutex( "SP_CC_MUTEX" );
   SP_CC_Init();

   sp_handover_mutex = kal_create_enh_mutex( "SP_HANDOVER_ENH_MUTEX" );
#if defined(__VOLTE_SUPPORT__)
   sp4g_dl_mutex = kal_create_enh_mutex( "SP4G_DL_MUTEX" );
   sp4g_ul_mutex = kal_create_enh_mutex( "SP4G_UL_MUTEX" );
#endif
   l1audio.aud_events = kal_create_event_group("L1Audio");
   l1audio.hisr = kal_init_hisr(L1AUDIO_HISR);

   GET_SLEEP_HANDLE();
   
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ ) && defined(MTK_SLEEP_ENABLE) && !defined(__AUDIO_POWERON_RESET_DSP__) )
#ifndef TK6291_FAKE_COMPILE
   l1audio.md2g_pdn_handle = L1D_MD2G_PWD_GetHandle();
   l1audio.l1sm_handle = L1SM_IntGetHandle();
#endif //#ifndef TK6291_FAKE_COMPILE
#endif

#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
   {
   extern kal_enhmutexid sp_mutex;
   sp_mutex = kal_create_enh_mutex( "SP_MUTEX" );
   }  
#endif   

#if defined(MT6755) ||  defined(MT6797) ||  defined(MT6757) || defined(MT6750S)
	l1audio.isD2MIntAvalibaleUnderSleep = KAL_TRUE;
#else
	l1audio.isD2MIntAvalibaleUnderSleep = KAL_FALSE;
#endif

#if defined(__OPEN_DSP_SPEECH_SUPPORT__)
	l1audio.isD2MIntAvalibaleUnderSleep = KAL_FALSE;
#endif

   l1audio.sleppModeLocker        = 0;
   l1audio.dspUser  = 0;
   l1audio.dsp_slow_idle_counter = 0;
   l1audio.event_flag   = 0;
   l1audio.id_flag      = 0;
   l1audio.media_flag   = 0;
   l1audio.sema = kal_create_sem( "Aud_Sema", 1 );  

   l1audio.hisrMagicFlag = 0;
   for( I = 0; I < MAX_HISR_HANDLER; I++ )
      l1audio.hisrMagicNo[I] = 0;

	// wait for DSP init done

//	while( 0 == L1D_Audio_ChkDspInitDone()){
//		kal_sleep_task(1);
//	}
//  kalcc_retrieve_eg_events(SHARED_pVAR(AUD_L2P), 1 << AUD_L2P_CHK_DSPINIT_DONE, KAL_AND, &retrieved_events, KAL_SUSPEND);
   cc_L1D_Audio_ChkDspInitDone();
	
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   initaud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( initaud_id );
#endif   
   DSP_DynamicDownload_Init();

   AM_Init();
   AFE_Init();
#if defined(__AUDIO_POWERON_RESET_DSP__)
   {
      uint32 _savedMask;
      _savedMask = SaveAndSetIRQMask();
      AFE_Init_status(KAL_TRUE);
#ifndef TK6291_NO_SPEECH_HW
      AFE_RegisterBackup();
#endif //#ifndef TK6291_NO_SPEECH_HW
      RestoreIRQMask(_savedMask);
   }
#endif

   L1SP_Init();

#if defined(__VOLTE_SUPPORT__)
#if defined(MT6276)
   ktInit( L1Audio_GetAudioID(), 0 );
   toneInit( L1Audio_GetAudioID(), 0 );
#else //#if defined(MT6276)
   for( I = 0; I < TOTAL_TONE_NUM; I++ )
   {
      ktInit( L1Audio_GetAudioID(), I );
      toneInit( L1Audio_GetAudioID(), I );
   }
#endif //#if defined(MT6276)
#endif //#if defined(__VOLTE_SUPPORT__)

   // mediaInit( L1Audio_GetAudioID() );

//    toneLoopbackRecInit(); // remove legency file and function

#if defined(__SMART_PHONE_MODEM__)
   EXT_BGSND_init();
#endif
	
#ifdef __CTM_SUPPORT__
   l1ctm_init();
#endif

#if defined(__DATA_CARD_SPEECH__)
   SP_Strm_Init();
#endif
   memset( &(l1audio.debug_info), 0, sizeof(l1audio.debug_info) );

#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOnFIR( L1SP_SPEECH );
   AFE_TurnOnFIR( L1SP_VOICE );
#endif // ANALOG_AFE_PATH_EXIST

#if defined(__CVSD_CODEC_SUPPORT__) 
   BT_SCO_Init();
#endif

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1Audio_ClearFlag( initaud_id );
   L1Audio_FreeAudioID( initaud_id );
#endif

#if defined(MT6595) && (MDAFE_DVT_CASE1 || MDAFE_DVT_CASE2 || MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
		kal_sleep_task( AUD_1TICK(3) );
		L1SP_Speech_On(1);
#endif
   l1audio.is_Initialized = true;
   while( 1 ) {
#if VERIFY_DATA_TO_DSP
      VERIFY_DATA_TO_DSP_SAVE_DATA();
#endif
      kal_retrieve_eg_events(l1audio.aud_events,0xFFFFFFFF,KAL_OR_CONSUME,&retrieved_events,KAL_SUSPEND);
      l1audio.retrieved_events = retrieved_events;
#ifndef TK6291_FAKE_COMPILE
      l1audio.events_l1FN = 0;//L1I_GetTimeStamp();
#else //#ifndef TK6291_FAKE_COMPILE
      l1audio.events_l1FN = 0;
#endif //#ifndef TK6291_FAKE_COMPILE
      for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
         if ( l1audio.retrieved_events & (1<<I) ) {
            l1audio.evHandler[I]( l1audio.evData[I] );
         }
      }
      // if( (l1audio.sleppModeLocker == 0))
      //   SLEEP_UNLOCK();
   }
}
#endif

uint32 L1Audio_GetEventGroup( void )
{
   uint32 retrieved_events;
   kal_retrieve_eg_events( l1audio.aud_events, 0xFFFF, KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND );
   return retrieved_events;
}

void L1Audio_ExeEventHandler( uint32 event )
{
   ASSERT_REBOOT( event < MAX_AUDIO_FUNCTIONS );
   l1audio.evHandler[event]( l1audio.evData[event] );
}

void L1Audio_ResetDevice(void)
{
#if defined(MT6755) || defined(MT6797) ||  defined(MT6757) || defined(MT6750S)
	extern kal_bool INT_QueryL1COREExceptionStatus(void);
	if(true != INT_QueryL1COREExceptionStatus() ) 
#endif //defined(MT6755) || defined(MT6797)	   		
	{
	   AFE_Init();
	}
}
/* ------------------------------------------------------------------------------ */

static char *_get_next_arg(char **ppstring)
{
   char *pstring = *ppstring, *pstring_t;
   kal_uint8 ch;

   if( *pstring=='\0' )
      return NULL;

   while(1)
   { // find start
      ch = *pstring;
      if( ch!=' ' && ch!='\t' )
         break;
      pstring++;
   }

   pstring_t = pstring;

   while(1)
   {
      ch = *pstring;
      if( ch=='\0' )
         break;
      else if( ch==' ' || ch=='\t' )
      {
         *pstring = '\0';
         pstring++;
         break;
      }
      pstring++;
   }

   *ppstring = (char *)pstring;

   return pstring_t;
}

static void dispatcher(char **ppstring, int (*entry_main)(int argc, char **argv))
{
   int argc = 0;
   char *argv[16];

   while(1)
   {
      char *args = _get_next_arg( ppstring );

      if( args==NULL )
      {
         entry_main( argc, argv );
         break;
      }
      else if( strcmp( args, "|" )==0 )
      {
         argv[argc] = NULL;
         entry_main( argc, argv );
         argc = 0;
      }
      else
         argv[argc++] = args;
   }
}

void l1audio_console(kal_uint8 index, kal_char *string)
{
   int (*entry_main)(int argc, char **argv);
   char *pstring = (char *)string;

   entry_main = NULL;
   switch(index)
   {
      case 99: /* VoRTP unit test */
      {
         break;
      }
      default:
         break;
   }
   if( entry_main!=NULL )
      dispatcher(&pstring, entry_main);
}


void l1audio_console_handler(kal_char *string)
{
   //(void)string; //just for integrating MCU TONE
   //int ii=atoi(string);

#if defined(MT6735) && (!defined(__SMART_PHONE_MODEM__))
   (void)string;
   if(strcmp(string, "VIO18")==0) {
      void set_vio18_setting(int val);
      kal_trace( TRACE_FUNC, TRC_MSG(AUDIO_SERVICE_L1AUDIO_CONSOLE_HANDLER_VIO18_ON);
      set_vio18_setting(1);
   }
   else if(strcmp(string, "VIO18OFF")==0) {
      void set_vio18_setting(int val);
      kal_trace( TRACE_FUNC, AUDIO_SERVICE_L1AUDIO_CONSOLE_HANDLER_VIO18_OFF);
      set_vio18_setting(0);
   }
#endif //#if defined(MT6735)

   if(strcmp(string, "0")==0) {
 		  //void Spc_SpeechOn( kal_uint8 RAT_Mode );
	    //Spc_SpeechOn( 0 );
  		void L1SP_Speech_On( uint8 RAT_Mode );
   		L1SP_Speech_On(0);
   }
   else if(strcmp(string, "1")==0) {
    	//void Spc_SpeechOff( void );
    	//Spc_SpeechOff();
    	void L1SP_Speech_Off( void );
    	L1SP_Speech_Off();
   }
   else if(strcmp(string, "2")==0) {
				void cc_2G_Call_Open(kal_uint32 enc_mod, kal_uint32 dec_mod, kal_uint32 sub_channel);
				cc_2G_Call_Open(2, 2, 1);
   }
   else if(strcmp(string, "3")==0) {

				void cc_2G_Call_Close(kal_uint32 dsp_end);
				cc_2G_Call_Close(KAL_TRUE);
   }
   
   else if(strcmp(string, "5")==0) {

				void setForceSendUL(bool x);
				setForceSendUL(1);
				kal_prompt_trace(MOD_L1SP, "[INJ] getForceSendUL 1");

   }
   
   else if(strcmp(string, "6")==0) {

				void setForceSendUL(bool x);
				setForceSendUL(0);
				kal_prompt_trace(MOD_L1SP, "[INJ] getForceSendUL 0");

   }
   else if(strcmp(string, "7")==0) {

				void spc_RttConfig(bool enable);
				spc_RttConfig(1);
				kal_prompt_trace(MOD_L1SP, "[INJ] spc_RttConfig");
   }
   else if(strcmp(string, "8")==0) {
				uint8 s1[] = {'1','2','3','4','5','\0'};
				uint8 s2[] = {'6','7','8','9','0','\0'};
				uint8 s3[] = {'A','B','C','D','E','\0'};
				uint8 s4[] = {'F','G','H','I','J','\0'};
				void TTY_LTE_PSR_DL_PutString(kal_uint8 call_id, kal_uint8 string[256], kal_uint16 length);
				TTY_LTE_PSR_DL_PutString(1, s1, 5);
				TTY_LTE_PSR_DL_PutString(2, s2, 5);
				TTY_LTE_PSR_DL_PutString(3, s3, 5);
				TTY_LTE_PSR_DL_PutString(1, s4, 5);
				kal_prompt_trace(MOD_L1SP, "[INJ] putAndSendString");
   }
   else if(strcmp(string, "9")==0) {
				uint8 s1[] = {'1','2','3','4','5','\0'};
				uint8 s2[] = {'6','7','8','9','0','\0'};
				uint8 s3[] = {'A','B','C','D','E','\0'};
				uint8 s4[] = {'F','G','H','I','J','\0'};
				void SP_L4C_SetERTTSTR(kal_uint8 call_id, kal_uint8 string[256], kal_uint16 length);
				SP_L4C_SetERTTSTR(1, s1, 5);
				SP_L4C_SetERTTSTR(2, s2, 5);
				SP_L4C_SetERTTSTR(3, s3, 5);
				SP_L4C_SetERTTSTR(1, s4, 5);
				kal_prompt_trace(MOD_L1SP, "[INJ] SP_L4C_SetERTTSTR");
   }
   else if(strcmp(string, "10")==0) {
				kal_uint8 call_id = 0;
				kal_uint8 buf[256] = {0};
				kal_uint16 length = 4;
				kal_uint16 ret;
				kal_uint16 TTY_LTE_PSR_UL_GetChar(kal_uint8 call_id, kal_uint8 *buf);
				
				ret = TTY_LTE_PSR_UL_GetChar(1, buf);
				kal_prompt_trace(MOD_L1SP, "[INJ] [TTY_LTE_PSR_UL_GetChar] callid = %d, buf = %x, length = %d %d", 1, buf[0], ret);
				
				ret = TTY_LTE_PSR_UL_GetChar(2, buf+1);
				kal_prompt_trace(MOD_L1SP, "[INJ] [TTY_LTE_PSR_UL_GetChar] callid = %d, buf = %x, length = %d %d", 2, buf[1], ret);
				
				ret = TTY_LTE_PSR_UL_GetChar(3, buf+2);
				kal_prompt_trace(MOD_L1SP, "[INJ] [TTY_LTE_PSR_UL_GetChar] callid = %d, buf = %x, length = %d %d", 3, buf[2], ret);
   }

/*
   (void)string;
	if(strcmp(string, "speechOn")==0){
		L1SP_Speech_On(0);
	} else if(strcmp(string, "speechOff")==0) {
		L1SP_Speech_Off();
	} else if(strcmp(string, "get2gRF")==0) {
		uint16 L1D_GetRF(uint16 mode);
	   uint16 RF_2G = L1D_GetRF(MML1_RF_2G);
	   L1Audio_Msg_L1D_GetRF(RF_2G);
	}
#if defined(__ENABLE_SPEECH_DVT__)
        extern void Speech_DVT_Test_Main(kal_char *string);
        Speech_DVT_Test_Main(string);
#endif // defined(__ENABLE_SPEECH_DVT__)*/
}

/* ----------------------------------------------------------------------------- */
/*  Function ptr prototype [HAL rule]                                            */
/* ----------------------------------------------------------------------------- */
//[MED]
static fp_audio_alloc_aud_mem      audio_alloc_aud_mem = NULL;
static fp_audio_alloc_aud_mem      audio_alloc_aud_mem_cacheable= NULL;
static fp_audio_free_aud_mem       audio_free_aud_mem = NULL;
static fp_send_proc_call_req       send_proc_call_req = NULL;
static fp_send_proc_call_req       send_proc_call_req2 = NULL;
static fp_audio_set_path_volume    audio_set_path_vol = NULL;
static fp_audio_get_active_mode    audio_get_active_mode = NULL;
static fp_get_meta_data_file       audio_get_meta_file = NULL;
static fp_get_meta_data_array      audio_get_meta_array = NULL;

void Audio_MedFuncReg(Media_Func_Reg_Type *func){
      audio_alloc_aud_mem           = (fp_audio_alloc_aud_mem)  func->alloc_mem;
      audio_alloc_aud_mem_cacheable = (fp_audio_alloc_aud_mem)  func->alloc_mem_cacheable;
      audio_free_aud_mem            = (fp_audio_free_aud_mem)   func->free_mem;
      audio_set_path_vol            = (fp_audio_set_path_volume)func->set_path_volume;
      audio_get_active_mode         = (fp_audio_get_active_mode)func->get_active_mode;
      send_proc_call_req            = (fp_send_proc_call_req)   func->send_proc_call;
      send_proc_call_req2           = (fp_send_proc_call_req)   func->send_proc_call2;
      audio_get_meta_file           = (fp_get_meta_data_file)   func->get_meta_file;
      audio_get_meta_array          = (fp_get_meta_data_array)  func->get_meta_array;
}

void *audio_alloc_ext_mem(kal_int32 size, char* file_p, long line_p){
   void *ptr = NULL;
   if (size == 0){
        return NULL;
     }
   ptr = (void*) audio_alloc_aud_mem(size,file_p,line_p);
   if(ptr){
        memset(ptr, 0, size);
   }
   kal_wap_trace(MOD_L1SP, TRACE_INFO, "[AUD][MEM] get buffer from: %s, %d", file_p, line_p);
   return ptr;
}

void *audio_alloc_ext_mem_cacheable(kal_int32 size, char* file_p, long line_p){
   void *ptr = NULL;
   if (size == 0){
        return NULL;
   }
   ptr = (void*) audio_alloc_aud_mem_cacheable(size,file_p,line_p);
   if(ptr){
        memset(ptr, 0, size);
   }
   kal_wap_trace(MOD_L1SP, TRACE_INFO, "[AUD][MEM] get buffer from: %s, %d", file_p, line_p);
   return ptr;
}

void audio_free_ext_mem(void **ptr, char* file_p, long line_p){
   audio_free_aud_mem(ptr,file_p,line_p);
   kal_wap_trace(MOD_L1SP, TRACE_INFO, "[AUD][MEM] free buffer from: %s, %d", file_p, line_p);
}


void L1Audio_InProcCall2(in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{
#ifndef MED_NOT_PRESENT
   send_proc_call_req2(MOD_L1SP, func, func_arg1, func_arg2);
#endif
}

void L1Audio_InProcCall(in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{
//#ifndef MED_NOT_PRESENT
   send_proc_call_req(MOD_L1SP, func, func_arg1, func_arg2);
//#endif
}

void aud_set_volume_internal(kal_uint8 audio_mode){
   audio_set_path_vol(audio_mode);
}

kal_uint8 aud_get_mode_internal(void){
  return audio_get_active_mode();
}

/*
kal_bool aud_get_meta_file(kal_wchar *filename, aud_info_struct *aud_info_p){
  return audio_get_meta_file(filename, aud_info_p);
}

kal_bool aud_get_meta_array(kal_char *ptr, kal_uint32 size, aud_info_struct *aud_info_p){
  return audio_get_meta_array(ptr, size, aud_info_p);
}
*/
//[BT] A2DP, phase out
/*
static fp_a2dp_set_br_from_qos_init   set_br_from_qos_init = NULL;
static fp_a2dp_set_br_from_qos        set_br_from_qos = NULL;

void Audio_BTFuncReg(BT_Func_Reg_Type *func){
      set_br_from_qos_init           = (fp_a2dp_set_br_from_qos_init)func->a2dp_set_br_init;
      set_br_from_qos                = (fp_a2dp_set_br_from_qos)     func->a2dp_set_br;
}


void a2dp_set_br_init_internal(kal_uint32 bit_rate_cur){
   set_br_from_qos_init(bit_rate_cur);
}

kal_uint32 a2dp_set_br_internal(kal_uint8 qos, kal_uint32 bit_rate_prev, kal_uint32 (*SetCodecBitRate)(kal_uint32)){
   return set_br_from_qos(qos, bit_rate_prev, (*SetCodecBitRate));
}
*/

#if defined(__SMART_PHONE_MODEM__)
#include "task_config.h"
#include "ccci.h"

extern void SpcIO_A2M_hisr(CCCI_BUFF_T *bufp);
extern void SpcIO_M2A_hisr(CCCI_BUFF_T *bufp);
extern void SpcIO_Init(void);
#endif

/***********************************************************/
/* Export to MED/AUDL task                                 */
/***********************************************************/

kal_bool SP_Drv_Init_Bootup(void)
{
#if defined (__SMART_PHONE_MODEM__)
   kal_int32 ret;
   ret = ccci_owner_init(CCCI_PCM_CHANNEL_ACK, kal_get_task_by_moduleID(MOD_MED), SpcIO_A2M_hisr);
   if (ret != CCCI_SUCCESS) {
       ASSERT(0);
   }
   ret = ccci_owner_init(CCCI_PCM_CHANNEL, kal_get_task_by_moduleID(MOD_MED), SpcIO_M2A_hisr);
   if (ret != CCCI_SUCCESS) {
       ASSERT(0);
   }
#endif

   return KAL_TRUE;
}

kal_bool SP_Drv_Init_Task(void)
{
#if defined (__SMART_PHONE_MODEM__)
   SpcIO_Init();
#endif
   
   return KAL_TRUE;
}
