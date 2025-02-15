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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   hmu.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file implement the function of Host Interface Management Unit.
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * 01 07 2016 ap.wang
 * [MOLY00156091] [HMU] Fix USB multi event unsync
 * .
 *
 * 11 10 2015 ap.wang
 * [MOLY00148746] [HMU] Check timer feature
 * .
 *
 * 11 10 2015 ap.wang
 * [MOLY00148746] [HMU] Check timer feature
 *
 * 01 07 2015 ap.wang
 * [MOLY00091565] [HMU] Modify assert to fatal for CR dispatch
 * .
 *
 * 12 31 2014 ap.wang
 * [MOLY00089916] [HMU] HIF ON/OFF for power saving
 * .
 *
 * 11 17 2014 ap.wang
 * [MOLY00084709] [HMU] Modify for GPT enable on MODIS
 * .
 *
 * 08 06 2014 ap.wang
 * [MOLY00074692] [HMU] Modify exception init function table
 * .
 *
 * 07 04 2014 ap.wang
 * [MOLY00071481] [HMU] Add HIF boot init to Application init
 * .
 *
 * 07 01 2014 ap.wang
 * [MOLY00071092] [HMU] Add tick count
 * .
 *
 * 06 10 2014 ap.wang
 * [MOLY00067367] [HMU] Modify GPT timer to MS callback for R8 on MOLY
 * .
 *
 * 04 28 2014 ap.wang
 * [MOLY00063912] [HMU] HMU temp solution for K2 MD2
 * HMU temp solution for K2 MD2
 *
 * 04 17 2014 box.wu
 * [MOLY00063010] [MT6595] HIF polling timeout check
 * cldma timeout check
 *
 * 03 21 2014 ap.wang
 * [MOLY00060351] [ETHERCORE] add ethercore enhancement feature
 * Add ethercore DL retry
 *
 * 02 26 2014 ap.wang
 * [MOLY00057680] [L2][HMU][DHL] L2 trace and L2 timestamp support
 * 	Add L2trc_fill_4G_time to HMU GPT for L2 trace
 *
 * 11 07 2013 ap.wang
 * [MOLY00043564] [klocwork_95][LTE] in hmu.c, line 345
 * 	Fix Klocwork warning: succeeded might be used uninitialized in this function.
 *
 * 08 28 2013 ap.wang
 * [MOLY00035451] [HMU] Add L2 trace log
 * 	[HMU] Add L2 trace for event trigger
 *
 * 08 27 2013 ap.wang
 * [MOLY00035456] [HMU] Modify for multi hif exception init
 * 	[HMU] Modify for multi dev type exception init
 *
 * 07 31 2013 ap.wang
 * [MOLY00031843] [HMU] Add trace log
 * .
 *
 * 07 31 2013 ap.wang
 * [MOLY00031843] [HMU] Add trace log
 * [HMU] Add trace log
 *
 * 03 11 2013 ap.wang
 * [MOLY00011696] [HMU] HMU code refine and compile warning fix
 * [HMU] Add copyright header and change ipc_reload condition
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"

#include "nvram_interface.h"
#include "nvram_data_items.h"
#include "hmu_conf_data.h"
#include "hmu.h"
#include "hmu_debug.h"
#include "swla_public.h"

#if defined(__IPCORE_SUPPORT__) && !defined(IPCORE_NOT_PRESENT)
#include "ipc_api.h"
#endif

#include "dcl_gpt.h"
#include "kal_internal_api.h" // for fatal error code
#include "us_timer.h"
#include "ccci_if.h"

#if !defined(_MTK_TARGET_) && defined(_MSC_VER) && (_MSC_VER >= 1500)
#pragma warning( disable : 4100 )
#endif

#define HMU_LOCK(_s) _s = SaveAndSetIRQMask()
#define HMU_UNLOCK(_s)    RestoreIRQMask(_s)

static DCL_HANDLE hmu_gpt_handle = 0 ;

static kal_enhmutexid hmu_gpt_mutex = NULL ; 

static kal_bool hmu_gpt_enable = KAL_TRUE ; 

static kal_uint32 hmu_hifeg_enable = 0 ; // hifeg enable bit mask
static kal_uint32 hmu_hifeg_enable_mask = 0 ; // use to indicate which hifeg need to enable at first time

static kal_bool hmu_dsp_timer_exist = KAL_FALSE ; 


static hmu_internal_state_struct hmu_internal_state = {KAL_FALSE, KAL_FALSE, NULL}; 
extern hmu_tick_interval hmu_tick_interval_table[];

extern hmu_uldrv_except_initfunc uldrv_except_init_func_table[];
extern unsigned int uldrv_except_init_func_table_num;

#if defined(__MTK_TARGET__)
#if defined(__CLDMACORE_SUPPORT__) || defined(__CCIFCORE_SUPPORT__)
kal_uint32 hmu_trigger_hif_pending_count = 0;
#endif
#endif

kal_uint32 hmu_tick = 0;

// Timer source correctness detection
#define HMU_TIMER_SOURCE_TIMEOUT_ERROR   (5 * 1000 * 1000) // us 
#define HMU_TIMER_SOURCE_TIMEOUT_WARNING (5 * 1000)        // us 

static kal_bool hmu_detect_timer_enable = KAL_TRUE;
static kal_uint32 hmu_detect_start_time = 0;
static kal_uint32 duration = 0;
/*****************************************************************************
 *  @brief hmu_get_current_time is to get current time
 *  @param NA
 *  @return kal_uint32 current time
 *  Unit: micro second
 *
 *****************************************************************************/
kal_uint32 hmu_get_current_time()
{
#if defined(__MTK_TARGET__)
    return ust_get_current_time();
#else // MODIS
    return 0;
#endif
}

/*****************************************************************************
 *  @brief hmu_get_duration is to calculate the duration between start time and end time
 *  @param start: start time
 *              end:   end time
 *  @return kal_uint32 time duration
 *  Unit: micro second
 *
 *****************************************************************************/
kal_uint32 hmu_get_duration(kal_uint32 start, kal_uint32 end)
{
#if defined(__MTK_TARGET__)
    return ust_us_duration(start, end);
#else // MODIS
    return 0;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  hmu_hifeg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 hmu_hifeg_init(){
	if (hmu_internal_state.hmuHifEgId == NULL){
		hmu_internal_state.hmuHifEgId = kal_create_event_group(HIF_DRV_EG_NAME) ;
	}
	return HMU_OK ;
}

/*****************************************************************************
 * FUNCTION
 *  hmu_hifeg_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __CCMNI_IT__
void ccmni_it_reload_rgpds();
#endif 

#if defined(__ETHERCORE_SUPPORT__) && !defined(ETHERCORE_NOT_PRESENT)
void ethc_check_dl_handle_packet_retry(void);
#endif

kal_status hmu_hifeg_set(kal_uint32 events) {
    kal_int32 index = 0;
    hmu_tick_interval *hif;
    
    /*
     * Check if each uplink IP stream GPD is required to be relaoded or not. 
     * Note that, the uplink GPD realoding will be done in IPCORE context not here.
     */
    if (HIF_DRV_EG_HIF_TICK_EVENT_GROUP & events) {
#if defined(__IPCORE_SUPPORT__) && !defined(IPCORE_NOT_PRESENT)
        ipc_check_ul_reload_retry();
#endif
#if defined(__ETHERCORE_SUPPORT__) && !defined(ETHERCORE_NOT_PRESENT)
        ethc_check_dl_handle_packet_retry();
#endif
#ifdef __CCMNI_IT__
        /* Use for CCMNI_IT rgpds reload, move from sdiocore to here*/
        ccmni_it_reload_rgpds();
#endif 
    }

    /* Clear events if interval is not reached */
    for(index = 0; hmu_tick_interval_table[index].hif_event != 0; index++){
        hif = &(hmu_tick_interval_table[index]);
        if (hif->hif_current_tick > 0){
            events &= ~(hif->hif_event);
            hif->hif_current_tick--;
        }
        else{
            hif->hif_current_tick = hif->hif_event_tick_count;
        }   
    }

#if defined(__MTK_TARGET__)
#if defined(__CLDMACORE_SUPPORT__) || defined(__CCIFCORE_SUPPORT__)
#define HIF_PENDING_LIMIT (4000)
	/* add hif pending count and this count should be reset  when hif polling task wakes up */ 
    if (events & HIF_DRV_EG_HIF_TICK_EVENT_CLDMA){
    	if (hmu_trigger_hif_pending_count++ > HIF_PENDING_LIMIT) {
    		/* assert if over pending limit */
    		kal_fatal_error_handler(KAL_ERROR_HMU_DETECT_LONG_TIME_NO_RESPONSE,0);
    	}
    }
#endif
#endif
    // Check timer
    hmu_check_timer(events);

    hmu_data_trace(HMU_DATA_EVENT_TRIGGER, hmu_gpt_enable, events, hmu_tick++, duration);
    return kal_set_eg_events(hmu_internal_state.hmuHifEgId, events, KAL_OR) ;
}

/*****************************************************************************
 * FUNCTION
 *  hmu_hifeg_wait
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 hmu_hifeg_wait(kal_uint32 events) {
    kal_uint32  rt_event = 0;
    kal_uint32  save_irqmask;
    HMU_LOCK(save_irqmask);
    if(((hmu_hifeg_enable_mask | events) ^ hmu_hifeg_enable_mask) != 0){
        hmu_hifeg_enable |= events;
        hmu_hifeg_enable_mask |= events;
    }
    HMU_UNLOCK(save_irqmask);
	kal_retrieve_eg_events(hmu_internal_state.hmuHifEgId, events, KAL_OR_CONSUME, &rt_event, KAL_SUSPEND);
    return rt_event;
}

static void hmu_gpt_callback(void *data) // HISR level !!  
{
	SGPT_CTRL_START_T re_schedule;

	if (hmu_gpt_enable == KAL_TRUE){
        re_schedule.u2Tick=HMU_GPTIMER_PRIODIC_INTERVAL ;
        re_schedule.pfCallback=hmu_gpt_callback;
        re_schedule.vPara=NULL;
        l2trc_fill_4G_time();
        hmu_hifeg_set(hmu_hifeg_enable & HIF_DRV_EG_HIF_TICK_EVENT_GROUP); 

        DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&re_schedule) ;
   	}
}

void hmu_stop_hif_sys_timer(){
	//kal_take_enh_mutex(hmu_gpt_mutex);

	hmu_gpt_enable = KAL_FALSE ; 

	DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_STOP, (DCL_CTRL_DATA_T*)NULL) ;

	//kal_give_enh_mutex(hmu_gpt_mutex);	
}

void hmu_start_hif_sys_timer(){
 	SGPT_CTRL_START_T start;

	//kal_take_enh_mutex(hmu_gpt_mutex);

	hmu_gpt_enable = KAL_TRUE ; 
	
	start.u2Tick=HMU_GPTIMER_PRIODIC_INTERVAL;
	start.pfCallback=hmu_gpt_callback;
	start.vPara=NULL;
	DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start) ;
	//kal_give_enh_mutex(hmu_gpt_mutex);	
}

void hmu_dsp_timer_kick(){
	hmu_hifeg_set(hmu_hifeg_enable & HIF_DRV_EG_HIF_TICK_EVENT_GROUP);
    if (hmu_dsp_timer_exist == KAL_TRUE){
        hmu_stop_hif_sys_timer();
    }
}

static void hmu_init_hif_timer()
{
    SGPT_CTRL_START_T start;

    start.u2Tick=HMU_GPTIMER_PRIODIC_INTERVAL;
    start.pfCallback=hmu_gpt_callback;
    start.vPara=NULL;

    hmu_dsp_timer_exist = KAL_FALSE ;		
    hmu_gpt_enable = KAL_TRUE ; 	
    DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start) ;

}

void hmu_switch_hif_timer(hmuTimerSource_enum source)
{
	SGPT_CTRL_START_T start;

     
	start.u2Tick=HMU_GPTIMER_PRIODIC_INTERVAL;
	start.pfCallback=hmu_gpt_callback;
	start.vPara=NULL;
	     
	kal_take_enh_mutex(hmu_gpt_mutex);
	if (source == HMU_TIMER_SOURCE_DSP){
            SLA_CustomLogging("DSP", SA_label);
	    hmu_dsp_timer_exist = KAL_TRUE ;		
	    //hmu_gpt_enable = KAL_FALSE ; 
	    //DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_STOP, (DCL_CTRL_DATA_T*)NULL) ;
	    hmu_data_trace(HMU_CHANGE_TIMER_DSP); 
	}else if(source == HMU_TIMER_SOURCE_SYS){	
	    SLA_CustomLogging("GPT", SA_label);
            hmu_dsp_timer_exist = KAL_FALSE ;		
            if( (hmu_hifeg_enable & HIF_DRV_EG_HIF_TICK_EVENT_GROUP) != 0){
	        hmu_gpt_enable = KAL_TRUE ; 	
	        DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start) ;
            }  
	    hmu_data_trace(HMU_CHANGE_TIMER_GPT); 
	}
	kal_give_enh_mutex(hmu_gpt_mutex);	

}

kal_int32 hmu_boot_init()
{
	if (hmu_internal_state.hmuBootInit == KAL_TRUE) {
		return HMU_ALREADY_INIT; 
	}

	hmu_hifeg_init() ;

	if (hmu_gpt_handle == 0) {
        hmu_gpt_handle = DclSGPT_Open(DCL_GPT_CB_MS, FLAGS_NONE);		
		if (hmu_gpt_handle == DCL_HANDLE_INVALID || hmu_gpt_handle == DCL_HANDLE_OCCUPIED){
			ASSERT(0);
		}
	}

	if (hmu_gpt_mutex == NULL) {
		hmu_gpt_mutex = kal_create_enh_mutex("hmu_timer_mutex");
		if (hmu_gpt_mutex == NULL) {
			ASSERT(0);
		}
	}	

    hmu_init_hif_timer() ;

 	hmu_internal_state.hmuBootInit = KAL_TRUE ;
	return 0 ;
}



/*****************************************************************************
 * FUNCTION
 *  hmu_except_init
 *
 * DESCRIPTION
 *  Trigger an upper layer device module to hook with TTYCORE and then proceed 
 *  exception flow if an exception happens before hmu_init() completes.
 *
 * PARAMETERS
 *  N/A
 *
 * RETURNS
 *  KAL_TRUE if caller is allowed to proceed the exception flow; 
 *  KAL_FALSE if there's no proper callback function registered by 
 *            upper layer device modules or something wrong while executing 
 *            the callback function.
 *****************************************************************************/
kal_bool hmu_except_init(void)
{
    kal_bool        succeeded = KAL_TRUE;
    kal_bool        ret = 0;
    kal_uint32      idx;
	
    for (idx = 0; idx < uldrv_except_init_func_table_num; idx++) {
        if (uldrv_except_init_func_table[idx].except_init_func != NULL){
            ret = uldrv_except_init_func_table[idx].except_init_func(uldrv_except_init_func_table[idx].port_id, 0, NULL);
        }
        if (ret != 0){
            succeeded = KAL_FALSE;
        }
    }	
    
    return succeeded;
}

/*****************************************************************************
 * FUNCTION
 *  hif_boot_init
 * DESCRIPTION
 *  HIF boot init function to initial HIF module without task.
 * PARAMETERS
 *  
 * RETURNS
 *  success or fail
 *****************************************************************************/
kal_int32 hif_boot_init()
{
    hmu_boot_init();
	return 0 ;
}

/*****************************************************************************
 * FUNCTION
 *  hmu_hifeg_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 hmu_hifeg_stop(kal_uint32 events) {
    kal_uint32          save_irqmask;
    HMU_LOCK(save_irqmask);
    hmu_hifeg_enable &= ~events;
    hmu_hifeg_enable_mask |= events;
    if( (hmu_hifeg_enable & HIF_DRV_EG_HIF_TICK_EVENT_GROUP) == 0){
        hmu_stop_hif_sys_timer();
	hmu_check_timer_stop();
    }
    HMU_UNLOCK(save_irqmask);
    hmu_data_trace(HMU_HIFEG_STOP, kal_get_active_module_id(), events, hmu_hifeg_enable);
    return hmu_hifeg_enable;
}

/*****************************************************************************
 * FUNCTION
 *  hmu_hifeg_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 hmu_hifeg_start(kal_uint32 events) {
    kal_uint32          save_irqmask;
    HMU_LOCK(save_irqmask);
    hmu_check_timer_start();
    hmu_hifeg_enable |= events;
    hmu_hifeg_enable_mask |= events;
    if (hmu_dsp_timer_exist == KAL_FALSE){
        hmu_start_hif_sys_timer(); 
    }
    HMU_UNLOCK(save_irqmask);
    hmu_data_trace(HMU_HIFEG_START, kal_get_active_module_id(), events, hmu_hifeg_enable);
    return hmu_hifeg_enable;
}

/*****************************************************************************
 * FUNCTION
 * hmu_check_timer_start / hmu_check_timer_stop 
 * DESCRIPTION
 * Start / Stop HMU checking timer
 * PARAMETERS
 *  
 * RETURNS
 *****************************************************************************/
void hmu_check_timer_start()
{
    hmu_detect_timer_enable = KAL_TRUE;
    /*
     * Case 1. when stop timer then start, need to get current time again
     * Case 2. when dsp change to gpt, dsp will call set_eg again, so will get checking timer
     *         So, need to check hmu_hifeg_enable then get current time
    */
    if(hmu_detect_start_time == 0 || hmu_hifeg_enable == 0)
        hmu_detect_start_time = hmu_get_current_time();
}
void hmu_check_timer_stop()
{
     hmu_detect_timer_enable = KAL_FALSE;
     hmu_detect_start_time = 0;
}

/*****************************************************************************
 * FUNCTION
 * hmu_check_timer 
 * DESCRIPTION
 * Check HMU timer source whether is normal 
 * PARAMETERS
 *  
 * RETURNS
 * HMU_CHECK_TIMER_ENUM : return checking result
 *****************************************************************************/
kal_uint32 hmu_check_timer(kal_uint32 events)
{
    if(hmu_detect_start_time != 0)
        duration = hmu_get_duration(hmu_detect_start_time, hmu_get_current_time());
    hmu_detect_start_time = hmu_get_current_time();
    if(duration > HMU_TIMER_SOURCE_TIMEOUT_ERROR && hmu_detect_timer_enable){ // error log
        hmu_data_trace(HMU_DATA_EVENT_TRIGGER_TIMEOUT_ERROR, hmu_gpt_enable, events, hmu_tick++, duration);
#ifdef __HIF_CCCI_SUPPORT__
	if(hmu_gpt_enable == KAL_FALSE)
            CCCI_ERROR_CODE_ASSERT(CCCI_FA_HMU_DSP_TIMER_BROKEN, duration, hmu_gpt_enable);
	else if(hmu_gpt_enable == KAL_TRUE)
            CCCI_ERROR_CODE_ASSERT(CCCI_FA_HMU_GPT_TIMER_BROKEN, duration, hmu_gpt_enable);
#else
        EXT_ASSERT(KAL_FALSE, hmu_tick, duration, hmu_gpt_enable);
#endif
	return HMU_CHECK_TIMER_ERROR;
    }
    else if( duration > HMU_TIMER_SOURCE_TIMEOUT_WARNING && hmu_detect_timer_enable){ // warning log
        hmu_data_trace(HMU_DATA_EVENT_TRIGGER_TIMEOUT_WARNING, hmu_gpt_enable, events, hmu_tick++, duration);
        return HMU_CHECK_TIMER_WARNING;
    }
    else{ // normal log
	return HMU_CHECK_TIMER_SUCCESS;
    }
	
}

