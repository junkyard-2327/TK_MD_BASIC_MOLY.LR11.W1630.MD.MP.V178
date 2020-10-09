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
 *   cpu.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   For CPU related functions
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 10 06 2015 yh.peng
 * [MOLY00144206] [LR11] fix build warning
 * .fix build warning.
 *
 * 04 13 2015 yh.peng
 * [MOLY00107303] [TK6291] Check in L1CR4 TCM vir to phy API.
 * Check in TCM vir to phy address translation API.
 *
 * 07 16 2013 cindy.tu
 * [MOLY00027330] [ARM7toMOLY] ARM7 Build/SYSGEN/Functions Update to TRUNK
 *
 * 04 16 2013 chin-chieh.hung
 * [MOLY00013348] [MT6290 Bring-up] Basic Platform Support
 * Firstcall branch, MOLY Trunk Code Sync
 *
 * 04 08 2013 chin-chieh.hung
 * [MOLY00013348] [MT6290 Bring-up] Basic Platform Support
 * update CR4 performance monitor counter macro setting
 *
 * 03 27 2013 chin-chieh.hung
 * [MOLY00012803] malmo asm software tracer support
 * Add MALMO-SWTR support for MT6290
 *
 * 02 05 2013 cindy.tu
 * [MOLY00009879] Rename MT7208 projects to MT6290
 * <saved by Perforce>
 *
 * 02 04 2013 cindy.tu
 * [MOLY00009879] Rename MT7208 projects to MT6290
 * <saved by Perforce>
 ****************************************************************************/


#ifndef __CPU_H__
#define __CPU_H__

#include "kal_public_defs.h"
#if defined(__CR4__)
#include "cp15.h"
#endif
//#ifdef __STACK_ALIGN_MPU__
//#include "mpu.h"
//#endif /* end of __STACK_ALIGN_MPU__ */

/*************************************************************************
 * Define constants
 *************************************************************************/
/* CPU Configurations */

#define CPU_TCM_VIR_TO_PHY(addr, ret_var)		                        \
    do{ 															    \
    	if(((kal_uint32)addr >= 0) && ((kal_uint32)addr < 0x80000))     \
    	{															    \
    		ret_var = (kal_uint32)((addr) | 0x72000000) ;                 \
    	}                                                               \
    	else														    \
    	{															    \
    		ASSERT(0);												    \
    	}															    \
    }while(0);

#define CPU_FREQUENCY_MHZ    (CPU_CLOCK_MHZ)             /* CPU Frequency: N Mhz */

#define CPU_CYCLE_TIME_NS    (((double)1000)/CPU_FREQUENCY_MHZ)

/* CPU Performance Counter Setting */
#define CPU_PMU_DIVISOR       (1U)
#define CPU_PMU_DIV_TIME_NS   ((CPU_CYCLE_TIME_NS*CPU_PMU_DIVISOR))

/* Poor Performance
 * Suggestion: use the const value n and macro is optimized at compiling time
 */

//Assumption: n*1000 + (CPU_PMU_DIV_TIME_NS/2) < (2^32 - 1)  ==> maximal n: about 4,000,000 us
#define CPU_US2PMUTICK(n)   ((kal_uint32)((((n)*1000UL)               + (CPU_PMU_DIV_TIME_NS/2)) / CPU_PMU_DIV_TIME_NS))

//Assumption: n*1000*1000 + (CPU_PMU_DIV_TIME_NS/2) < (2^32 - 1) ==> maximal n:about 4,000 ms
#define CPU_MS2PMUTICK(n)   ((kal_uint32)((((n)*1000UL*1000UL)        + (CPU_PMU_DIV_TIME_NS/2)) / CPU_PMU_DIV_TIME_NS))

//Assumption: n*1000*1000*1000 + (CPU_PMU_DIV_TIME_NS/2) < (2^32 - 1) ==> maximal n:about 4 sec
//#define CPU_SEC2PMUTICK(n)  ((((n)*1000UL*1000UL*1000UL) + (CPU_PMU_DIV_TIME_NS/2)) / CPU_PMU_DIV_TIME_NS)
#define CPU_SEC2PMUTICK(n)  ((kal_uint32)((n)*(1000UL*1000UL*1000UL / CPU_PMU_DIV_TIME_NS)))


//Assumption: return 64-bit unsigned long long integer
#define CPU_PMUTICK2US(n)   ((kal_uint64)((((n)*CPU_PMU_DIV_TIME_NS) + (CPU_PMU_DIV_TIME_NS/2))/1000UL))
#define CPU_PMUTICK2MS(n)   ((kal_uint64)((((n)*CPU_PMU_DIV_TIME_NS) + (CPU_PMU_DIV_TIME_NS/2))/1000UL/1000UL))
#define CPU_PMUTICK2SEC(n)  ((kal_uint64)((((n)*CPU_PMU_DIV_TIME_NS) + (CPU_PMU_DIV_TIME_NS/2))/1000UL/1000UL/1000UL))

#define CPU_PMUTICK2QBIT(n) ((kal_uint64)((n)*13*CPU_PMU_DIV_TIME_NS/12/1000))

#define CPU_QBIT2PMUTICK(n) ((kal_uint32)((n)*12*1000UL/13/CPU_PMU_DIV_TIME_NS))



#define CPU_PMU_COUNTER_WRAP    (0xFFFFFFFFUL)
#define CPU_PMU_COUNTER_US_WRAP ((kal_uint32)CPU_PMUTICK2US(CPU_PMU_COUNTER_WRAP))

#ifdef MT6290
#define CPU_EVENT_COUNTER_NUM  (0x3U)
#define CPU_EVENT_COUNTER_MASK (0x7U)
#else
#define CPU_EVENT_COUNTER_NUM  (0x0U)
#define CPU_EVENT_COUNTER_MASK (0x0U)

#endif

/*************************************************************************
 * Define Types
 *************************************************************************/
/*CPU Event Count Control Block */
typedef struct CEC_CB_s{
    kal_uint16 counter_id;
    kal_uint16 event_id;
    kal_uint32 counter_value;
    struct CEC_CB_s *next;
    kal_bool occupied;
}CEC_CB;

typedef enum{
    CEC_OP_NOT_AVAILABLE = 0,
    CEC_OP_CONFIG,            /* Config the event count setting */
    CEC_OP_RESTART,           /* Stop, set config, clear counter, start counting */
    CEC_OP_GET_VALUE,         /* Get the current counter value */
    CEC_OP_STOP_AND_GET_VALUE,/* Stop and update the counter_value */
    CEC_OP_CLR,               /* Clear event conter value */
    CEC_OP_START,             /* Start monitor counter */
    CEC_OP_STOP,              /* Start monitor counter */
    CEC_OP_MAX
}CEC_OPS;

/* Refreence: Events and Performance Monitor Chapter in the CPU's TRM */
typedef enum{
    CEC_EID_CCACHE_MISS = 0x01,
    CEC_EID_DCACHE_MISS = 0x03,
    CEC_EID_DCACHE_ACCESS = 0x04,
    CEC_EID_DATA_READ_ARCH_EXEC = 0x06,
    CEC_EID_DATA_WRITE_ARCH_EXEC = 0x07,
    CEC_EID_INST_ARCH_EXEC = 0x08,
    CEC_EID_EXECPTION_TAKEN = 0x09,
    CEC_EID_DCACHE_WRITE_BACK = 0x42,
    CEC_EID_STORE_BUFFER_MERGE = 0x50,
    CEC_EID_CYCLE_COUNT = 0xFF
}CEC_EVENT_ID;

/*************************************************************************
 * Define MACROS
 *************************************************************************/
#if 1 /* Disable These debug information/mechanism */
#define CPU_SET_CONTEXT_ID(context_id)
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* the input(start, end) is 32-bit PMU ticks */
#define cpu_event_get_duration(start, end) \
    (((end) >= (start))? ((end) - (start)): ((CPU_PMU_COUNTER_WRAP - (start) + (end) + 1)))

/* the input(start, end) is 64-bit us */
#define cpu_event_get_us_duration(start, end) \
    (((end) >= (start))? ((end) - (start)): ((CPU_PMU_COUNTER_US_WRAP - (start) + (end) + 1)))

#if defined(__MTK_MMU_V2__)
extern unsigned int CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE(void);
#define cpu_event_counter_get_cycle(counter)                                   \
do {                                                                           \
    (counter) = CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE();                      \
} while (0)

#else /* __MTK_MMU_V2__ */

#if defined(__GNUC__)
#define cpu_event_counter_get_cycle(counter)                                   \
do{                                                                            \
    __asm__ __volatile__                                                       \
    (                                                                          \
       "mrc p15, 0, %0, c9, c13, 0\r\n"                                        \
       :"=r"(counter)                                                          \
       :                                                                       \
    );                                                                         \
}while(0)

#else  /* else of __GNUC__ */
#define cpu_event_counter_get_cycle(counter)                                   \
do{                                                                            \
    (counter) = mon_counter_get_cycle();                                       \
}while(0)

#endif /* end of "else of __GNUC__" */

extern unsigned int mon_counter_get_cycle(void);
extern kal_status cpu_event_counter_init(void);
extern kal_status cpu_event_count_get_instance(CEC_CB **inst);
extern kal_status cpu_event_count_free_instance(CEC_CB **inst);
extern kal_status cpu_event_count_ops(CEC_CB *inst, CEC_OPS op);
extern kal_uint32 cpu_event_count_occupied(void);

#endif /* end of "else of __MTK_MMU_V2__" */

#endif  /* end of __CPU_H__ */

