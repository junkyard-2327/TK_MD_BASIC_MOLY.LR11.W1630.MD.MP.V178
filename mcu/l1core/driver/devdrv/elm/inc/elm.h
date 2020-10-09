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
 *   elm.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file for ELM.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(__L1CORE_ELM_H__)
#define __L1CORE_ELM_H__
/* ==================== */
/*	CONFIGURATIONS		*/
/* ==================== */
/* ==================== */
/*	INCLUDES			*/
/* ==================== */
#include "reg_base.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "sync_data.h"
#include "us_timer.h"

#include "drv_comm.h"

/*******************************************************************************
 * Feature Option
 *******************************************************************************/
// Turned-On MD EMI latency profiling of TL1/2GL1 SW
// Note: It uses MD ELM and conflicts with SWLA ELM add-on
//#if defined(__MTK_INTERNAL__) 
    #if !defined(__SWLA_ADDON_ELM__) && !defined(__SWLA_EBM_ADDON_SUPPORT__)
      #if 1 //defined(TK6291) || defined(MT6755)
        #define __ELM_RUNTIME_PROFILE__
      #endif 
    #endif //!defined(__SWLA_ADDON_ELM__) && !defined(__SWLA_EBM_ADDON_SUPPORT__)
//#endif /* __MTK_INTERNAL__ */


/* ==================== */
/*	DEFINITIONS			*/
/* ==================== */

/* ==================== */
/*	ELM CONTROL API		*/
/* ==================== */
//#define ELM_KEY_WORD		(0x6291<<16)
#define ELM_KEY_WORD		(0x2454<<16)

#define REG_ELM_CLK					    (L1_BASE_MADDR_L1ELM_TOP + 0x0004)	
#define REG_ELM_CTRL					(L1_BASE_MADDR_L1ELM_TOP + 0x0008)
#define REG_ELM_STAT					(L1_BASE_MADDR_L1ELM_TOP + 0x0034)

// ELM Set Mode (HW/SW Mode)
enum {
	ELM_SW_MODE = 0,
	ELM_HW_MODE = 1,
	
};

#define ELM_SET_MODE(m) \
	do {\
		;\
	} while(0)



// ELM init
#define ELM_INIT()	\
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CLK, ELM_KEY_WORD | 0x1);\
		} while(0)

// ELM clear
#define ELM_CLR()	\
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CTRL, 0);\
		} while(0)

// ELM Start
#define ELM_START() \
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CTRL, 1);\
		} while(0)

// ELM Pause
#define ELM_PAUSE() \
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CTRL, 3);\
		} while(0)

// ELM Counter Selection
enum {	
	ELM_RD = 0,
	ELM_WR = 1
};

enum {
	ELM_TYPE_TRANS = 0,
	ELM_TYPE_LATENCY = 1
};


#define ELM_GET_CNT(rw, type, idx, p_cnt) \
	do {\
		*p_cnt = DRV_Reg32(REG_ELM_STAT + (((rw ) + (type<< 1)) << 2));\
	} while(0)
#define ELM_GET_CUR_CNT(rw, type, p_cnt) \
	do {\
		*p_cnt = DRV_Reg32(REG_ELM_STAT + (((rw) + (type<< 1)) << 2));\
	} while(0)

// ELM Summary (Current HW_idx, Overrun indication)
#define ELM_GET_SUMMARY(p_hw_idx, p_overrun) \
	do {\
		*p_hw_idx = (DRV_Reg32(REG_ELM_STAT + (0x1 << 4)) >> 8) & 0x00000003;\
		*p_overrun = (DRV_Reg32(REG_ELM_STAT + (0x1 << 4))) & 0x000000FF;\
	} while(0)

// only for exception handler.
extern kal_uint8 _ELM_latency_status(void);
extern void _ELM_exception_saved(void);
//for 60qbit check
extern void _ELM_debug_start(void);
extern void _ELM_debug_stop(void);
extern void _ELM_debug_dump(void);

typedef struct _ELM_GENERNAL_PROFILE_T
{
    kal_int32 duration;
    kal_uint32 Cur_RAT;
    kal_uint32 w_trans;
    kal_uint32 r_trans;
    kal_uint32 avg_rlat;
    kal_uint32 avg_wlat;
} ELM_GENERNAL_PROFILE_T;



#ifdef __ELM_RUNTIME_PROFILE__


typedef struct _ELM_PROFILE_TICK_T
{
    kal_int32 duration;
    kal_uint32 tick_count;
	kal_uint32 tick_valid_count;
} ELM_PROFILE_TICK_T;



#define ELM_DADA_IN_TCM
#define ELM_SW_MODE_PROFILE

//#define __ELM_TEST__


#define ELM_COMMAND_PRD						(650<<8)
#define ELM_COMMAND_HW_MODE					(1<<2)
#define ELM_COMMAND_PAUSE					(3)
#define ELM_COMMAND_START					(1)
#define ELM_COMMAND_STOP					(0)
#define ELM_COUNTER_STATUS(n)				((L1_BASE_MADDR_L1ELM_TOP + 0x0810)+n<<2)
#define ELM_COMMAND_HW_IDEX					((L1_BASE_MADDR_L1ELM_TOP + 0x0820))

#define ELM_RAT_2G 0
#define ELM_RAT_3G 1
#define ELM_RAT_4G 2

#define ELM_MIN_TRANS 10


#ifdef __ELM_TEST__
#define ELM_HISTORY_SIZE 1024
#else
#define ELM_HISTORY_SIZE 64
#endif

#define ELM_GET_DURATION(d,t1,t2) do{\
                                 d = ((t2) >= (t1)) ? ((t2) - (t1)) : (0xFFFFFFFF - (t1) + (t2));\
                              }while(0)

#if 0// defined(__CR4__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define ELM_HW_TIME_WINDOW (4523) //4900 qbit = 4523 us
#define ELM_GET_CURRENT_TIME(v) do{\
                                v = ust_get_current_time(); \
                             }while(0)
#endif

#ifdef __ELM_TEST__
#define ELM_PROFILE_CACULATE_TICK_COUNT() \
do {\
	extern kal_uint32 elm_profile_tick_cur_time; \
	extern ELM_PROFILE_TICK_T elm_profile_tick_per[ELM_HISTORY_SIZE];\
	extern kal_uint32 elm_tick_idex;\
	extern kal_uint32 elm_profile_tick_prev_time;\
	extern kal_uint32 elm_profile_history_idx;\
	extern kal_uint32 elm_start_idex;\
	ELM_GET_CURRENT_TIME(elm_profile_tick_cur_time);\
	elm_profile_tick_per[elm_tick_idex].tick_count++;\
	ELM_GET_DURATION(elm_profile_tick_per[elm_tick_idex].duration,elm_profile_tick_prev_time,elm_profile_tick_cur_time);\
	if(elm_profile_tick_per[elm_tick_idex].duration > 1000000)\
	{		\
		if(elm_profile_history_idx > elm_start_idex)\
		{\
			elm_profile_tick_per[elm_tick_idex].tick_valid_count = elm_profile_history_idx - elm_start_idex;\
		}\
		else\
		{\
			elm_profile_tick_per[elm_tick_idex].tick_valid_count = ELM_HISTORY_SIZE - elm_start_idex + elm_profile_history_idx + 1 ;\
		}\
		elm_start_idex = elm_profile_history_idx;\
		elm_tick_idex = (elm_tick_idex + 1) % ELM_HISTORY_SIZE ;\
		elm_profile_tick_per[elm_tick_idex].duration = 0;\
		elm_profile_tick_per[elm_tick_idex].tick_count= 0;\
		elm_profile_tick_prev_time = elm_profile_tick_cur_time;\
	}\
} while (0)
#else
#define ELM_PROFILE_CACULATE_TICK_COUNT() {}
#endif


//SW mode
#define ELM_PROFILE_START(caller) \
do { \
	extern kal_uint32 elm_profile_target_caller; \
	ELM_PROFILE_CACULATE_TICK_COUNT();\
	if(caller == elm_profile_target_caller) \
	{ \
		extern kal_uint32 elm_profile_history_idx; \
		extern kal_uint32 elm_profile_prev_time; \
		extern ELM_GENERNAL_PROFILE_T elm_profile_history[ELM_HISTORY_SIZE]; \
		ELM_GET_CURRENT_TIME(elm_profile_prev_time);\
		elm_profile_history_idx = (elm_profile_history_idx + 1) % ELM_HISTORY_SIZE ; \
		elm_profile_history[elm_profile_history_idx].duration = 0; \
		elm_profile_history[elm_profile_history_idx].Cur_RAT = caller; \
		DRV_WriteReg32_NPW(REG_ELM_CTRL, ELM_COMMAND_STOP);\
		DRV_WriteReg32_NPW(REG_ELM_CTRL, ELM_COMMAND_START);\
	}\
} while (0)


#define ELM_PROFILE_GET_LOG(caller) \
do { \
	extern kal_uint32 elm_profile_target_caller; \
	if(caller == elm_profile_target_caller) \
	{ \
		extern kal_uint32 elm_profile_cur_time; \
		extern kal_uint32 elm_profile_history_idx; \
		extern kal_uint32 elm_profile_prev_time; \
		extern kal_uint32 elm_profile_dur_time; \
		extern kal_uint32 elm_profile_w_latency; \
		extern kal_uint32 elm_profile_r_latency; \
		extern ELM_GENERNAL_PROFILE_T elm_profile_history[ELM_HISTORY_SIZE]; \
		extern ELM_GENERNAL_PROFILE_T elm_profile_history_w_worst;\
		extern ELM_GENERNAL_PROFILE_T elm_profile_history_r_worst;\
		ELM_GET_CURRENT_TIME(elm_profile_cur_time);\
		ELM_GET_DURATION(elm_profile_dur_time,elm_profile_prev_time,elm_profile_cur_time);\
		if (elm_profile_dur_time > 60) { \
			elm_profile_history[elm_profile_history_idx].duration = elm_profile_dur_time;\
			DRV_WriteReg32_NPW(REG_ELM_CTRL, ELM_COMMAND_PAUSE);\
			ELM_GET_CUR_CNT(ELM_WR, ELM_TYPE_TRANS, &elm_profile_history[elm_profile_history_idx].w_trans); \
			ELM_GET_CUR_CNT(ELM_WR, ELM_TYPE_LATENCY, &elm_profile_w_latency); \
			if (elm_profile_history[elm_profile_history_idx].w_trans > ELM_MIN_TRANS) elm_profile_history[elm_profile_history_idx].avg_wlat = elm_profile_w_latency / elm_profile_history[elm_profile_history_idx].w_trans; \
			else elm_profile_history[elm_profile_history_idx].avg_wlat = 0; \
			ELM_GET_CUR_CNT(ELM_RD, ELM_TYPE_TRANS, &elm_profile_history[elm_profile_history_idx].r_trans); \
			ELM_GET_CUR_CNT(ELM_RD, ELM_TYPE_LATENCY, &elm_profile_r_latency); \
			if (elm_profile_history[elm_profile_history_idx].r_trans > ELM_MIN_TRANS) elm_profile_history[elm_profile_history_idx].avg_rlat = elm_profile_r_latency / elm_profile_history[elm_profile_history_idx].r_trans; \
			else elm_profile_history[elm_profile_history_idx].avg_rlat = 0; \
			if (elm_profile_history[elm_profile_history_idx].avg_wlat > elm_profile_history_w_worst.avg_wlat) { \
				elm_profile_history_w_worst.duration = elm_profile_history[elm_profile_history_idx].duration; \
				elm_profile_history_w_worst.w_trans = elm_profile_history[elm_profile_history_idx].w_trans; \
				elm_profile_history_w_worst.r_trans = elm_profile_history[elm_profile_history_idx].r_trans; \
				elm_profile_history_w_worst.avg_wlat = elm_profile_history[elm_profile_history_idx].avg_wlat; \
				elm_profile_history_w_worst.avg_rlat = elm_profile_history[elm_profile_history_idx].avg_rlat; \
			} \
			if (elm_profile_history[elm_profile_history_idx].avg_rlat > elm_profile_history_r_worst.avg_rlat) { \
				elm_profile_history_r_worst.duration = elm_profile_history[elm_profile_history_idx].duration; \
				elm_profile_history_r_worst.w_trans = elm_profile_history[elm_profile_history_idx].w_trans; \
				elm_profile_history_r_worst.r_trans = elm_profile_history[elm_profile_history_idx].r_trans; \
				elm_profile_history_r_worst.avg_wlat = elm_profile_history[elm_profile_history_idx].avg_wlat; \
				elm_profile_history_r_worst.avg_rlat = elm_profile_history[elm_profile_history_idx].avg_rlat; \
			} \
		} else { \
			elm_profile_history[elm_profile_history_idx].w_trans = 0; \
			elm_profile_history[elm_profile_history_idx].r_trans = 0; \
			elm_profile_history[elm_profile_history_idx].avg_wlat = 0; \
			elm_profile_history[elm_profile_history_idx].avg_rlat = 0; \
		} \
	}\
} while (0)

#define ELM_PROFILE_SET_CALLER(MODEM_RAT, ISsleep) \
do { \
	extern kal_uint32 elm_profile_target_caller; \
	extern kal_uint32 elm_profile_MD_status[3];\
	if(MODEM_RAT <= ELM_RAT_4G)\
	{\
		elm_profile_MD_status[MODEM_RAT] = ISsleep;\
		if(elm_profile_MD_status[ELM_RAT_2G] == KAL_FALSE)\
		{\
			elm_profile_target_caller = ELM_RAT_2G;\
		}\
		else\
		{\
			if(elm_profile_MD_status[ELM_RAT_4G] == KAL_FALSE)\
			{\
				elm_profile_target_caller = ELM_RAT_4G;\
			}\
			else if(elm_profile_MD_status[ELM_RAT_3G] == KAL_FALSE)\
			{\
				elm_profile_target_caller = ELM_RAT_3G;\
			}\
			else\
			{\
				elm_profile_target_caller = ELM_RAT_2G;\
			}\
		}\
	}\
} while (0)

#define ELM_GET_READ_WORST_LOG(l) do { \
	extern ELM_GENERNAL_PROFILE_T elm_profile_history_r_worst;\
	l.duration = elm_profile_history_r_worst.duration; \
	l.w_trans = elm_profile_history_r_worst.w_trans; \
	l.r_trans = elm_profile_history_r_worst.r_trans; \
	l.avg_wlat = elm_profile_history_r_worst.avg_wlat; \
	l.avg_rlat = elm_profile_history_r_worst.avg_rlat; \
} while (0)

#define ELM_GET_WRITE_WORST_LOG(l) do { \
	extern ELM_GENERNAL_PROFILE_T elm_profile_history_w_worst;\
	l.duration = elm_profile_history_w_worst.duration; \
	l.w_trans = elm_profile_history_w_worst.w_trans; \
	l.r_trans = elm_profile_history_w_worst.r_trans; \
	l.avg_wlat = elm_profile_history_w_worst.avg_wlat; \
	l.avg_rlat = elm_profile_history_w_worst.avg_rlat; \
} while (0)

#define ELM_GET_LAST_HISTORY_LOG(l) do { \
	extern ELM_GENERNAL_PROFILE_T elm_profile_history[ELM_HISTORY_SIZE]; \
	extern kal_uint32 elm_profile_history_idx; \
	if( elm_profile_history_idx < ELM_HISTORY_SIZE) { \
		l.duration = elm_profile_history[elm_profile_history_idx].duration; \
		l.w_trans = elm_profile_history[elm_profile_history_idx].w_trans; \
		l.r_trans = elm_profile_history[elm_profile_history_idx].r_trans; \
		l.avg_wlat = elm_profile_history[elm_profile_history_idx].avg_wlat; \
		l.avg_rlat = elm_profile_history[elm_profile_history_idx].avg_rlat; \
	}\
} while (0)

#else 

//__ELM_RUNTIME_PROFILE__ DISABLE
#define ELM_PROFILE_START(caller) {}
#define ELM_PROFILE_GET_LOG(caller) {}
#define ELM_PROFILE_SET_CALLER(MODEM_RAT, ISsleep) {}

#define ELM_GET_READ_WORST_LOG(l) {}
#define ELM_GET_WRITE_WORST_LOG(l) {}
#define ELM_GET_LAST_HISTORY_LOG(l) {}
#endif //__ELM_RUNTIME_PROFILE__

#define ELM_SM_Start() ELM_START()
#define ELM_SM_Pause() ELM_PAUSE()
#define ELM_SM_Stop() ELM_CLR()
	
typedef struct _ELM_LOG_T
{
	kal_uint32 w_trans;
	kal_uint32 w_latency;
	kal_uint32 r_trans;
	kal_uint32 r_latency;
} ELM_LOG_T;


// for spv compatibility
#define ELM_GET_LOG(c, l) do { \
			ELM_GET_CNT(ELM_WR, ELM_TYPE_TRANS, (c), &((l).w_trans));\
			ELM_GET_CNT(ELM_WR, ELM_TYPE_LATENCY, (c), &((l).w_latency));\
			ELM_GET_CNT(ELM_RD, ELM_TYPE_TRANS, (c), &((l).r_trans));\
			ELM_GET_CNT(ELM_RD, ELM_TYPE_LATENCY, (c), &((l).r_latency));\
		} while (0)

#define ELM_L1Core_GET(l) do { \
	DRV_WriteReg32_NPW(REG_ELM_CTRL, 0x1)\
	ELM_GET_LOG(0,l);\
} while (0)

#endif  /* !__ELM_H__ */
