/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   us_timer.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for providing timer of microsecond precision.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(__US_TIMER_H__)
#define __US_TIMER_H__

#if defined(MT9999) /* All Chips in MOLY support US Timer*/
#else /* MT9999 */
#define __HW_US_TIMER_SUPPORT__
#endif /* MT9999 */

#include "reg_base.h"
#include "cpu.h"
#include "drv_comm.h"

//For L1 simulation
#include "md2g_drv.h"

/*******************************************************************************
 * Define registers.
 *******************************************************************************/
#if defined(TK6291)||defined(MT6755)||defined(MT6797)||defined(MT6757)||defined(MT6750S) /* UMOLY */
  #if defined(__L1CORE__)
     #define BASE_FMA_SOURCE    L1_BASE_MADDR_TOPSM
     #define BASE_ADDR_FMA      L1_BASE_MADDR_GLOBAL_TS_SHADOW
     #define USCNT_CON          (BASE_FMA_SOURCE + 0x0800)
     #define FRC_SOURCE_VAL     (BASE_FMA_SOURCE + 0x0830)
     #define TS_SOURCE_VAL      (BASE_FMA_SOURCE + 0x0840)
  #elif defined(__PCORE__)
     #define BASE_FMA_SOURCE    BASE_MADDR_MDTOPSM
     #define BASE_ADDR_FMA      BASE_MADDR_PCORE_FMA
     #define USCNT_CON          (BASE_FMA_SOURCE     + 0x0080)
     #define FRC_SOURCE_VAL     (BASE_FMA_SOURCE     + 0x0088)
     #define TS_SOURCE_VAL      (L1_BASE_MADDR_TOPSM + 0x0840)
  #else
     #error "Not defined __L1CORE__ and __PCORE__ "
  #endif


  #if defined(__FAST_FRC__) /* FMA is supported */
    #if defined(__L1CORE__)
    #if defined(TK6291) /* TBC...*/
        #define USCNTI_VAL           (FRC_SOURCE_VAL)
        #define TIMESTAMP_VAL        (TS_SOURCE_VAL)    
    #else
        #define USCNTI_VAL         (BASE_ADDR_FMA       + 0x0004)
        #define TIMESTAMP_VAL      (BASE_ADDR_FMA       + 0x0000)    
    #endif
    #elif defined(__PCORE__)  
    #define USCNTI_VAL         (BASE_ADDR_FMA       + 0x0000)
    #define TIMESTAMP_VAL      (BASE_ADDR_FMA       + 0x0010)
    #endif
  #else
    #define USCNTI_VAL            (FRC_SOURCE_VAL)
    #define TIMESTAMP_VAL      (TS_SOURCE_VAL)
  #endif /* __FAST_FRC__ */
#else /* TK6291 */
    #define BASE_FMA_SOURCE BASE_MADDR_MDTOPSM
    #define USCNTI_VAL         (volatile kal_uint32 *)(BASE_FMA_SOURCE+0x0088)
#endif /* TK6291 */


#if KAL_MICROSECS_PER_TICK==4615  /* (12/13)*5000us */
    #define USCNT_TO_FRAME(sus) (((sus)*58161)>>28) /* Error rate: 0.0000266% */
#elif KAL_MICROSECS_PER_TICK==5000
    #define USCNT_TO_FRAME(sus) (((sus)*53687)>>28) /* Error rate: 0.0001700% */
#elif KAL_MICROSECS_PER_TICK==1000
     #define USCNT_TO_FRAME(sus) (((sus)*4294967)>>32) /* Error rate: 0.0000069% */
#else  /* KAL_MICROSECS_PER_TICK== */
    #error "Un-Support Frame Period"
#endif /* KAL_MICROSECS_PER_TICK== */

#define USCNT_TO_QBIT(us)  (((us)*1109)>>10)  /*Error rate: 1 qbit error per 3000 qbits, allowd max log duration: 4s */
#define USCNT_WRAP         0xFFFFFFFF

#ifdef ESIM_BUILD_CONFIG
    #define USCNT_START_CODE   0x62900001
    #define USCNT_STOP_CODE    0x62900000

#endif /* ESIM_BUILD_CONFIG */

/*******************************************************************************
 * Define macros.
 *******************************************************************************/
#if defined(__HW_US_TIMER_SUPPORT__)
    extern void USC_Start( void );
    extern void USC_Stop( void );
    extern void USC_Cal_32KFM( kal_uint32 Cal_32K, kal_uint32 Cal_26M);
    extern kal_uint32 USC_Get_TimeStamp( void );
    #if defined(__LTE_L1SIM__)
        #define ust_get_current_time()  HW_READ(((volatile kal_uint32*)USCNTI_VAL))
        #define fma_get_glb_ts()        (ust_get_current_time()>>6)
    #elif defined(__UE_SIMULATOR__) || defined(ESIM_BUILD_CONFIG) /* == !__MTK_TARGET__ ? */
        extern kal_uint32 osc_platform_us_counter_get(void);
        extern kal_uint32 osc_platform_64us_counter_get(void);
        #define ust_get_current_time()        osc_platform_us_counter_get()
        #define ust_get_current_time_source() osc_platform_us_counter_get()
        #define fma_get_glb_ts()              osc_platform_64us_counter_get()
    #elif defined(__ESL_COSIM_LTE__)
        #define ust_get_current_time()        DRV_Reg32(0xFFFF3000)
        #define ust_get_current_time_source() ust_get_current_time()
        #define fma_get_glb_ts()              (ust_get_current_time()>>6)
    #elif !defined(__MTK_TARGET__) /* Pure OSCAR */
        extern kal_uint32 osc_platform_us_counter_get(void);
        extern kal_uint32 osc_platform_64us_counter_get(void);
        #define ust_get_current_time()        osc_platform_us_counter_get()
        #define ust_get_current_time_source() osc_platform_us_counter_get()
        #define fma_get_glb_ts()              osc_platform_64us_counter_get()
    #else
        #if defined(__PCORE__) && defined(__CENTRALIZED_SLEEP_MANAGER__)
            extern volatile kal_uint32 ostd_patch_us_timer_period;
            #define ust_get_current_time()        ((DRV_Reg32((kal_uint32) USCNTI_VAL)/KAL_CLOCK_RATIO_REAL) + ostd_patch_us_timer_period )
            #define ust_get_current_time_source() ((DRV_Reg32((kal_uint32) FRC_SOURCE_VAL)/KAL_CLOCK_RATIO_REAL) + ostd_patch_us_timer_period )
        #elif defined(__L1CORE__) || defined(__PCORE__)
            #define ust_get_current_time()        (DRV_Reg32((kal_uint32) USCNTI_VAL)/KAL_CLOCK_RATIO_REAL)
            #define ust_get_current_time_source() (DRV_Reg32((kal_uint32) FRC_SOURCE_VAL)/KAL_CLOCK_RATIO_REAL)
        #else /* __L1CORE__ */
            #error "Not defined __L1CORE__ and __PCORE__"
        #endif /* __L1CORE__ */
        #define fma_get_glb_ts()              (DRV_Reg32(TIMESTAMP_VAL)/KAL_CLOCK_RATIO_REAL)
    #endif

    /* Get duration, unit = Qbit */
    #define ust_get_duration(prev, cur)  USCNT_TO_QBIT((((cur) >= (prev))? (((cur) - (prev))): ((USCNT_WRAP - (prev) + (cur) + 1))))

    /* Get duration, unit = us */
    #define ust_us_duration(start, end)   (((end) >= (start))? (((end) - (start))): ((USCNT_WRAP - (start) + (end) + 1)))

#else   /* __HW_US_TIMER_SUPPORT__ */
#error "MOLY chips always support the HW US Timer"

#endif  /* __HW_US_TIMER_SUPPORT__ */

/**
 * ust_busy_wait - a busy loop wait for a period
 * @us: qbit to wait
 *
 * This macro contains a busy loop to wait a period of specified microsends.
 * There is a maximal iteration count in the busy loop to prevent from infinite loop. 
 * (EX: timer is not working.)
 * ==> Update the design, if the ust does not work, CPU blocking at this macro.
 *     Because it's hard to find the delay loop issue when FRC is stop.
 */
#define ust_busy_wait(qbit)                                   \
do {                                                          \
    kal_uint32 t1, t2, zerocount = 0xFFFFF;                   \
    if ((qbit) == 0) {break;}                                 \
    t1 = ust_get_current_time();                              \
    do {                                                      \
        t2 = ust_get_current_time();                          \
        if (t1 == t2) { zerocount--; }                        \
        else if (ust_get_duration(t1, t2) >= (qbit)) { break; } \
    } while (zerocount);                                      \
    if(0==zerocount)                                          \
    {                                                         \
        kal_uint32 FRC_IS_NOT_INIT = 0;                       \
        ASSERT(FRC_IS_NOT_INIT);                              \
    }                                                         \
} while (0)

#define ust_us_busyloop(us)                                   \
do {                                                          \
    kal_uint32 t1, t2, zerocount = 0xFFFFF;                   \
    if ((us) == 0) {break;}                                   \
    t1 = ust_get_current_time();                              \
    do {                                                      \
        t2 = ust_get_current_time();                          \
        if (t1 == t2) { zerocount--; }                        \
        else if (ust_us_duration(t1, t2) >= (us)) { break; } \
    } while (zerocount);                                      \
    if(0==zerocount)                                          \
    {                                                         \
        kal_uint32 FRC_IS_NOT_INIT = 0;                       \
        ASSERT(FRC_IS_NOT_INIT);                              \
    }                                                         \
} while (0)


#endif  /* !__US_TIMER_H__ */

