/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   l1_rtb.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Real Time Base for 3G Gemini project
 *
 * Author:
 * -------
 * -------
 *
 * $Log$
 *
 * 05 17 2017 akansha.jain
 * [MOLY00248337] [MT6757CH][Kibo+][J-CA][PHONE][Overnight][HQ][MTBF][Lab][Ericsson][Gemini][ASSERT] file:l1core/modem/gl1/l1c/m11301.c line:6432
 * CQ ALPS0328902 fix
 *
 * 03 10 2016 deepti.varadarajan
 * [MOLY00168546] [MT6755][Jade][MP3][M][CSFB DSDS][FDD][SH][CS Performance][LAT2]DUTsim2 doesn't receive paging when sim1PS
 * [ALPS02574474] : Paging Missed for MT call- cross core header file
 *
 * 03 02 2016 deepti.varadarajan
 * [MOLY00165592] [RTB]API to get hardware reservation information during RF conflict
 * Addition of comment in header file for auto sync purpose
 *
 * 02 25 2016 deepti.varadarajan
 * MOLY00165592 : New RTB API for RF Conflict information
 *
 * 12 02 2015 terence.chen
 * [MOLY00151325] Handshake the SRLTE or L+C status with MD3 RTBA.
 * Handshake the SRLTE or L+C status with MD3 RTBA.
 *
 * 12 02 2015 terence.chen
 * [MOLY00151325] Handshake the SRLTE or L+C status with MD3 RTBA.
 * Handshake the SRLTE or L+C status with MD3 RTBA.
 *
 * 12 02 2015 terence.chen
 * [MOLY00151325] Handshake the SRLTE or L+C status with MD3 RTBA.
 * Handshake the SRLTE or L+C status with MD3 RTBA.
 *
 * 10 28 2015 terence.chen
 * [MOLY00147141] Add new RTB parameters
 * Add ChannelType in MD1_MD3_CCIRQ_BUFFER_RESOURCE and Add new RTB channel priority.
 *
 * 09 23 2015 terence.chen
 * [MOLY00141786] [MT6755][SRLTE][L+C] Support connectivity of C2K on dual SIM
 * Check-in L+C.
 *
 * 09 17 2015 terence.chen
 * [MOLY00141960] [MT6291] Check-in Gemini+ modification
 * Modify the higher priority channel query function for LTE.
 *
 * 09 07 2015 bhaskar.ganapuram
 * [MOLY00140044] [Jade][SRLTE][ADZ] RF Conflcit when 1xRTT Call Release
 * ;Added tid for MD1 to MD3 interface and vice versa.(CQ:ALPS02278637)
 *
 * 07 28 2015 terence.chen
 * [MOLY00132718] Pass RTB assert information to each RAT
 * .
 *
 * 06 17 2015 mohamed.idhrees
 * [MOLY00114877] [TK6291E1][L1C] EL1C_RTIMER_NUM value needs to be increased
 * EL1C_RTIMER_NUM increased to 22
 *
 * 05 20 2015 mohamed.idhrees
 * [MOLY00114877] [TK6291E1][L1C] EL1C_RTIMER_NUM value to be increased from 10 to 16
 * EL1C_RTIMER_NUM value increased from 10 to 16
 *
 * 05 20 2015 mohamed.idhrees
 * [MOLY00112586] [TK6291E1][GCF][ANITE][3G][FDD][8.3.7.1a CS] Test Fail
 * .
 *
 * 05 05 2015 arkadeep.sett
 * [MOLY00111246] L+W MM Gemini+ xL1SIM Changes to UMOLY trunk
 * 	Propagating L1C and RTB changes for LW_GEMINI from chi-chung.lin Gemini sanity branch to UMOLY trunk
 *
 * 03 04 2015 rick.wu
 * [MOLY00083549] [MT6291] Merge GL1 codes from MT6291_DEV to UMOLY
 * Fix cross header build error in Gemini project
 *
 * 03 03 2015 rick.wu
 * [MOLY00083549] [MT6291] Merge GL1 codes from MT6291_DEV to UMOLY
 * Fix UMOLY Gemini build error
 *
 * 12 15 2014 terence.chen
 * [MOLY00083240] [UMOLY] Check-in MOLY and universal bin into UMOLY.
 * 	Correct the header file.
 *
 * 02 11 2014 terence.chen
 * [MOLY00055725] [4G Gemini][WG][CS Performance][Moving] fatal : (0xb13, 0x30884b) ¡V SWL1H
 * Modify the definition of FRC_WRAP_COMPENSATION.
 *
 * 01 22 2014 terence.chen
 * [MOLY00054324] [4G Gemini][Merge] MOLY.MM.GEMINI.DEV Merge back to MOLY.
 *
 *
 ****************************************************************************/

#ifndef L1_RTB_H
#define L1_RTB_H

// Don't use compile option in this header file because this header is shared between MD1 and MD3.
// The compile option between MD1 and MD3 is independent.
// Don't include the MD1 only header file, because MD3 can't include the MD1 only header files.

/* --- RTB priorities of timers --- */
#define RTB_TIMER_PRIORITY_0    0
#define RTB_TIMER_PRIORITY_4    4
#define RTB_TIMER_PRIORITY_5    5
#define RTB_TIMER_PRIORITY_10  10
#define RTB_TIMER_PRIORITY_20  20
#define RTB_TIMER_PRIORITY_30  30
#define RTB_TIMER_PRIORITY_40  40
#define RTB_TIMER_PRIORITY_45  45 //For cell search
#define RTB_TIMER_PRIORITY_47  47
#define RTB_TIMER_PRIORITY_50  50
#define RTB_TIMER_PRIORITY_52  52
#define RTB_TIMER_PRIORITY_53  53 // For 3G PS starvation
#define RTB_TIMER_PRIORITY_56  56 // For paging
#define RTB_TIMER_PRIORITY_58  58
#define RTB_TIMER_PRIORITY_60  60
#define RTB_TIMER_PRIORITY_65  65
#define RTB_TIMER_PRIORITY_MASK 0xFF

#define GL1C_RTIMER_NUM  ( 16 * ( RTB_SIM_NUM ) )
#define UL1C_RTIMER_NUM  12  // UL1C needs 10 and UL1D needs 2.
#define TL1C_RTIMER_NUM  9
#define C2K_RTIMER_NUM   16  // Includes 1xRTT and EVDO.
#define EL1C_RTIMER_NUM  22  // MOLY00114877: Increased from 10 to 16 and to 22

/* The resolution of FRC on MOLY is micro second. */
#define GL1_FRAME          ( 4615 )
#define GL1_FRAME2RTB( x ) ( (x)*GL1_FRAME )
#define GL1_EBIT2RTB( x )  ( ((x)*6)/13 )
#define RTB2GL1_EBIT( x )  ( ((x)*13)/6 )

#define UL1_FRAME          ( 10000 )
#define UL1_FRAME2RTB( x ) ( (x)*UL1_FRAME )
#define UL1_ECHIP2RTB( x ) ( ((x)*25)/(2*384) )
#define RTB2UL1_ECHIP( x ) ( ((x)*2*384)/25 )

#define TL1_SUBFRAME              ( 5000 )
#define TL1_SUBFRAME2RTB( x )     ( (x)*TL1_SUBFRAME )
#define TL1_ECHIP2RTB( x )        ( ((x)*25)/256 )
#define RTB2TL1_ECHIP( x )        ( ((x)*256)/25 )
#define TD_SUBFRAME_TO_ECHIP( x ) ( (x)*51200 )

#define EL1_SUBFRAME          ( 1000 )
#define EL1_SUBFRAME2RTB( x ) ( (x)*EL1_SUBFRAME )
#define RTB2EL1_SUBFRAME( x ) ( (x)/EL1_SUBFRAME )

#define RTB_RF_MARGIN ( 666 )

#if defined (__GEMINI_WCDMA__)

/* 3G and 4G reuse BRP(Bit Rate Process) on MT6291 (L+W_Gemini )and they
  * cannot use BRP at the same time, so RTB&MLL1 needs to add additional 
  * margin for it. A margin of 2ms is required only in case 4G powers down RF 
  * and 3G powers on RF */
#define RTB_RF_MARGIN_4G_TO_3G_SWITCH ( 2000 ) //2ms
#endif /*__GEMINI_WCDMA__ */

#define PM2GMARGIN    ( 13846 )  // 3 2G frames

#define NORESERVATION (-1)

#define FRC_WRAP      0xFFFFFFFF
#define FRC_WRAP_HALF 0x7FFFFFFF
#define FRC_WRAP_COMPENSATION 0x100000000 //FRC_WRAP + 1

#define SIM_SHIFT_OFFSET( x )   ( (x)*4 )
#define UL1_TL1_EL1_ACTIVE_MASK     0x00EEEE
#define TL1_ACTIVE                  0x004444
#define EL1_ACTIVE                  0x008888
#define UL1_TL1_EL1_C2K_ACTIVE_MASK 0xFFEEEE
#define SIM1_GL1_ACTIVE         0x0001
#define SIM1_UL1_ACTIVE         0x0002
#define SIM1_TL1_ACTIVE         0x0004
#define SIM1_EL1_ACTIVE         0x0008
#define SIM2_GL1_ACTIVE         0x0010
#define SIM2_UL1_ACTIVE         0x0020
#define SIM2_TL1_ACTIVE         0x0040
#define SIM2_EL1_ACTIVE         0x0080
#define SIM3_GL1_ACTIVE         0x0100
#define SIM3_UL1_ACTIVE         0x0200
#define SIM3_TL1_ACTIVE         0x0400
#define SIM3_EL1_ACTIVE         0x0800
#define SIM4_GL1_ACTIVE         0x1000
#define SIM4_UL1_ACTIVE         0x2000
#define SIM4_TL1_ACTIVE         0x4000
#define SIM4_EL1_ACTIVE         0x8000
#define SIM1_1XRTT_ACTIVE       0x010000
#define SIM2_1XRTT_ACTIVE       0x020000
#define SIM3_1XRTT_ACTIVE       0x040000
#define SIM4_1XRTT_ACTIVE       0x080000
#define SIM1_EVDO_ACTIVE        0x100000


typedef enum
{
    ConflictWithNone,
    ConflictWith2GBCCh,
    ConflictWith2GNBCCh,
    ConflictWith2GPCh,
    ConflictWith2GOther,
    ConflictWithC2K,
    ConflictWith3GSIB_HIGH,
    ConflictWith3GSIB_LOW,
    ConflictWith3GPICH,
    ConflictWith3GOther,
    ConflictWith4GBCCH,
    ConflictWith4GNBCCH_HIGH,
    ConflictWith4GNBCCH_MIDDLE,
    ConflictWith4GNBCCH_LOW,
    ConflictWith4GPCH,
    ConflictWith4GOther
} RTBConflictType;

typedef enum
{
    GL1C_RTB = 0,
    UL1C_RTB,
    TL1C_RTB,
    C2K_RTB,
    EL1C_RTB,
    COUNT_RTB
} RTB_RAT_E;

typedef enum
{
    RTB_EVDO = 0,
    RTB_1xRTT
} RTB_C2K_RAT_E;

typedef enum
{
    RTB_SIM1 = 0,
    RTB_SIM2,
    RTB_SIM3,
    RTB_SIM4,
    RTB_SIM1_1xRTT,
    RTB_SIM_NUM
}RTB_SIM_INDEX;

typedef enum
{
    // The corresponding timer doesn't insert into RTB.
    // Feedback parameters: (1)Assert Cause (2)SIM index (3)Channel type (para1)
    NO_RELATIVE_TIMER = 0,
    
    // The reservation length is smaller than 0.
    // Feedback parameters: (1)Assert Cause (2)SIM index (3)Channel type (para1)
    INVALID_RESERVATION_LENGTH,
    
    // Max number of inserted timer is reached.
    // Feedback parameters: (1)Assert Cause (2)SIM index (3)Max count (para1)
    EXCEED_MAX_TIMER_SIZE,
    
    // The ChannelDelay length is smaller than 0.
    // Feedback parameters: (1)Assert Cause (2)SIM index (3)Channel delay (para1)
    INVALID_CHANNEL_DELAY_LENGTH,
    
    // The InsertAtCurrentFrame should be false for all RAT except UL1.
    // Feedback parameters: (1)Assert Cause (2)SIM index 
    INVALID_INSERT_CURRENT_FRAME_VALUE,
    
    // The FindTimerLength is smaller than 0.
    // Feedback parameters: (1)Assert Cause (2)SIM index (3)Channel type (para1)
    INVALID_FIND_TIMER_LENGTH,
    
    // The CheckLength is smaller than 0.
    // Feedback parameters: (1)Assert Cause (2)SIM index (3)Channel type (para1)
    INVALID_CHECK_LENGTH,
    
    // The timer doesn't remove after the expected start time.
    // Feedback parameters: (1)Assert Cause (2)SIM index (3)Channel type (para1) (4)Start time of timer (para2)
    FORGET_TO_REMOVE_TIMER,
    
    // The number of protected channel exceeds the maximum.
    // Feedback parameters: (1) Assert Cause (2)SIM index (3)Max count (para1)
    EXCEED_MAX_PROTECT_SIZE,
    
    // The protection and cancelling protection is not paired.  Cancel protection of an un-protected timer.
    // Feedback parameters: (1)Assert Cause (2)SIM index (3)Channel type (para1)
    CANCEL_UN_PROTECTED_TIMER,
    
    // This function is only valid for GL1.
    // Feedback parameters: (1)Assert Cause (2)SIM index
    INVALID_USER
}RTB_ASSERT_CAUSE;

// Function index from MD3 to MD1
#define CCIRQ_L1R_C2KCheckRTBResource           0
#define CCIRQ_L1R_C2KQueryRTBInformation        1
#define CCIRQ_L1R_C2KCheckResourceConfirm       2
#define CCIRQ_L1R_StartTimer                    3
#define CCIRQ_L1R_ProtectChannel                4
#define CCIRQ_L1R_CancelProtection              5
#define CCIRQ_L1R_ClearReservation              6
#define CCIRQ_L1R_ChangeTimerPriority           7
#define CCIRQ_L1R_SwitchActiveRAT               8
#define CCIRQ_L1R_AdjustTimerPosition           9
#define CCIRQ_L1R_ClearPassedReservation        10
#define CCIRQ_L1R_ClearTimer                    11
#define CCIRQ_L1R_C2KUpdateRATConfig            12

// Function index from MD1 to MD3
#define CCIRQ_Answer_L1R_C2KCheckRTBResource    0
#define CCIRQ_Answer_L1R_C2KQueryRTBInformation 1
#define CCIRQ_C2K_GSMLTEActiveInactive          2
#define CCIRQ_CL1_AssertFunction                3
#define CCIRQ_C2K_SRLTE_INFO_CNF                4

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 rat;
    kal_uint32 ChannelType;
    kal_uint32 ChannelPriority;
    kal_uint32 CheckDelay;
    kal_uint32 CheckLength;
    kal_uint32 NormalReservedLength;
    kal_uint32 MinReservedLength;
    kal_uint32 SIM_Index;
} MD3_MD1_CCIRQ_BUFFER_RESOURCE;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 ChannelType;
    kal_uint32 FindHigherTimer;
    kal_uint32 HigherTimerDelay;
    kal_uint32 HigherTimerReservation;
    kal_uint32 ReserveSuccessfully;
    kal_uint32 ActuallyReservedLength;
}MD1_MD3_CCIRQ_BUFFER_RESOURCE;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 rat;
    kal_int32  CheckDelay;
    kal_uint32 SIM_Index;
} MD3_MD1_CCIRQ_BUFFER_INFORMATION;

typedef struct
{
    kal_uint32 func_index;
    kal_int32  HWReservedLength;
    kal_uint32 ConflictReport;
    kal_uint32 RAT_Status;
} MD1_MD3_CCIRQ_BUFFER_INFORMATION;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 rat;
    kal_uint32 tid;
} MD3_MD1_CCIRQ_BUFFER_CONFIRM;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 GSMOnly;
    kal_uint32 Active;
    kal_uint32 tid;
} MD1_MD3_CCIRQ_BUFFER_CONFIRM;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 rat;
    kal_uint32 ChannelType;
    kal_uint32 ChannelDelay;
    kal_uint32 ChannelPriority;
    kal_uint32 ReservedLength;
    kal_uint32 SIM_Index;
} MD3_MD1_CCIRQ_BUFFER_STARTTIMER;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 rat;
    kal_uint32 ChannelType;
    kal_uint32 SIM_Index;
} MD3_MD1_CCIRQ_BUFFER_PROTECTION;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 rat;
    kal_uint32 SIM_Index;
} MD3_MD1_CCIRQ_BUFFER_CLEARRESERVATION;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 rat;
    kal_uint32 ChannelType;
    kal_uint32 NewPriority;
    kal_uint32 SIM_Index;
} MD3_MD1_CCIRQ_BUFFER_CHANGEPRIORITY;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 rat;
    kal_uint32 activate;
    kal_uint32 SIM_Index;
} MD3_MD1_CCIRQ_BUFFER_SWITCHACTIVERAT;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 rat;
    kal_uint32 ChannelType;
    kal_uint32 Delay;
    kal_uint32 SIM_Index;
} MD3_MD1_CCIRQ_BUFFER_ADJUSTPOSITION;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 rat;
    kal_uint32 ChannelType;
    kal_uint32 SIM_Index;
} MD3_MD1_CCIRQ_BUFFER_CLEARTIMER;

typedef struct
{
    kal_uint32 func_index;
} MD3_MD1_CCIRQ_BUFFER_CLEARPASSEDRESERVATION;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 c2k_in_srlte;
} MD3_MD1_CCIRQ_BUFFER_C2K_IN_SRLTE_OR_NOT;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 assert_cause;  /* Define in RTB_ASSERT_CAUSE enum. */
    kal_uint32 sim_index;
    kal_uint32 para1;
    kal_uint32 para2;
} MD1_MD3_CCIRQ_BUFFER_RTB_ASSERT_INFORMATION;

typedef struct
{
    kal_uint32 func_index;
    kal_uint32 lte_ative;
    kal_uint32 gsm_ative;
} MD1_MD3_CCIRQ_BUFFER_SRLTE_INFO_CNF;

typedef struct
{
    kal_bool  FindHigherTimer;
    kal_int32 HigherTimerDelay;
    kal_int32 HigherTimerReservation;
} RTB_HIGHER_PRIORITY_CH_INFO;


/* RTB common external API to each RAT. */
void L1R_InitFramerData( void );
void L1R_StartTimer( RTB_RAT_E rat, kal_int16 ChannelType, kal_bool InsertAtCurrentFrame, kal_int32 ChannelDelay, kal_int32 ChannelPriority, kal_uint32 ReservedLength, RTB_SIM_INDEX SIM_Index );
void L1R_SetExpiredTimer( RTB_RAT_E rat, kal_int16 ChannelType, RTB_SIM_INDEX SIM_Index );
void L1R_FindTimer( RTB_RAT_E rat, kal_int16 ChannelType, kal_int32 FindTimerLength, RTB_SIM_INDEX SIM_Index,  kal_bool* FindHigherTimer );
void L1R_ReserveHWResource( RTB_RAT_E rat, kal_int16 ChannelType, kal_int32 ReservedLength, RTB_SIM_INDEX SIM_Index, kal_bool* ReserveSuccessfully );
void L1R_ClearTimer( RTB_RAT_E rat, kal_int16 ChannelType, RTB_SIM_INDEX SIM_Index );

void L1R_ProtectChannel( RTB_RAT_E rat, kal_int16 ChannelType, RTB_SIM_INDEX SIM_Index );
void L1R_CancelProtection( RTB_RAT_E rat, kal_int16 ChannelType, RTB_SIM_INDEX SIM_Index );

void L1R_FindTimerDelay( RTB_RAT_E rat, kal_int16 ChannelType , kal_bool InsertAtCurrentFrame, kal_int32 ChannelPriority, kal_int32 CheckDelay, kal_int32 CheckLength, RTB_SIM_INDEX SIM_Index, kal_bool* FindHigherTimer, kal_int32* HigherTimerDelay );
void L1R_FindTimerDelayandReservation( RTB_RAT_E rat, kal_int16 ChannelType , kal_bool InsertAtCurrentFrame, kal_int32 ChannelPriority, 
        kal_int32 CheckDelay, kal_int32 CheckLength, RTB_SIM_INDEX SIM_Index, kal_uint8 check_gap_num, RTB_HIGHER_PRIORITY_CH_INFO* Channel_Info );
void L1R_GetOtherRATReservedLength( RTB_RAT_E rat, RTB_SIM_INDEX SIM_Index, kal_int32 CheckDelay, kal_int32* HWReservedLength );

void L1R_ClearReservation( RTB_RAT_E rat, RTB_SIM_INDEX SIM_Index );
void L1R_ChangeTimerPriority( RTB_RAT_E rat, kal_int16 ChannelType, kal_int32 NewPriority, RTB_SIM_INDEX SIM_Index );
void L1R_GetConflictReport( RTB_RAT_E rat, RTBConflictType* ConflictReport );
void L1R_SwitchActiveRAT( RTB_RAT_E rat, kal_bool activate, RTB_SIM_INDEX SIM_Index );

void L1R_ExtendFrame( RTB_RAT_E rat, kal_int32 ExtendQuantity );
void L1R_AdjustTimerPosition ( RTB_RAT_E rat, kal_int16 ChannelType, kal_int32 Delay, RTB_SIM_INDEX SIM_Index );
void L1R_GetRATStatus( kal_uint32* RAT_Status );
void L1R_ClearPassedReservation( void );
/* Used Get information during RF conflict */
kal_bool L1R_CheckHWReservation(RTB_RAT_E rat, RTB_SIM_INDEX SIM_Index, kal_int64 *HWReservation_StartTime, kal_int64 *HWReservation_EndTime);
void L1R_NotifyHWReservation( RTB_RAT_E rat, kal_int16 ChannelType, RTB_SIM_INDEX SIM_Index );
kal_bool L1R_QueryForRTBTimer(  RTB_RAT_E rat, kal_int16 ChannelType, RTB_SIM_INDEX SIM_Index );

/* RTB external API to GL1. */
void L1R_Increase2GTime( void );
//void L1R_Set2GTime( Time* time );
void L1R_FrameTick_2G( void );

/* RTB external API to TL1. */
void L1R_Peer2GOpenConfirm( void );
void L1R_SwitchPeer2GActive( kal_bool activate );

/* RTB external API to C2K */
//void L1R_C2KCheckRTBResource( RTB_RAT_E rat, kal_int16 ChannelType , kal_bool InsertAtCurrentFrame, kal_int32 ChannelPriority, kal_int32 CheckDelay, kal_int32 CheckLength, kal_int32 NormalReservedLength, kal_int32 MinReservedLength, RTB_SIM_INDEX SIM_Index, kal_bool* FindHigherTimer, kal_int32* HigherTimerDelay, kal_int32* HigherTimerReservation, kal_bool* ReserveSuccessfully, kal_int32* ActuallyReservedLength );
void L1R_C2KCheckRTBResource( RTB_RAT_E rat, kal_int16 ChannelType , kal_bool InsertAtCurrentFrame, kal_int32 ChannelPriority, kal_int32 CheckDelay, kal_int32 CheckLength, kal_int32 NormalReservedLength, kal_int32 MinReservedLength, RTB_SIM_INDEX SIM_Index );
//void L1R_C2KQueryRTBInformation( RTB_RAT_E rat, RTB_SIM_INDEX SIM_Index, kal_int32 CheckDelay, kal_int32* HWReservedLength, RTBConflictType* ConflictReport, kal_uint32* RAT_Status );
void L1R_C2KQueryRTBInformation( RTB_RAT_E rat, RTB_SIM_INDEX SIM_Index, kal_int32 CheckDelay );
void L1R_SwitchActiveInactive( RTB_RAT_E rat, kal_bool Active );
void L1R_C2KCheckResourceConfirm( RTB_C2K_RAT_E rat, kal_uint32 tid);
#if SIMULATION_SUPPORT
void L1R_Adjust2GAGCHPriority( kal_bool Adjust_Priority, kal_int32 New_Priority );
#endif

#endif
