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
 *   sleepdrv_interface.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the public access for sleep mode operation.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 24 2016 ws.yan
 * [MOLY00214692] [ROSA]add compile option MT6750S
 * 	
 * 	.
 *
 * 02 18 2016 kevin-kh.liu
 * [MOLY00165387] [Olympus][MP3] Sleep Mode Modifications
 * 	
 * 	Add chip Olympus option - common & l1core md_sm interface part
 *
 * 08 03 2015 hsiao-hsien.chen
 * [MOLY00131673] [Jade] Sleep mode code modification.
 * Add chip option for Everest.
 *
 * 07 29 2015 ethan.hsieh
 * [MOLY00131103] Sleep Mode Debug Shared Memory Mechanism Improvement
 *
 * 06 26 2015 hsiao-hsien.chen
 * [MOLY00124235] [MT6755][BRINGUP_FIRSTCALL]Fix FRC/Timestamp sync problem for bringup debug
 * 	.
 *
 * 06 10 2015 hsiao-hsien.chen
 * [MOLY00072109] [MT6291] Sleep mode code modification.
 * Modify topsm/sleepdrv code for Jade.
 *
 * 04 27 2015 hsiao-hsien.chen
 * [MOLY00072109] [MT6291] Sleep mode code modification.
 * Add enum back.
 *
 * 04 27 2015 hsiao-hsien.chen
 * [MOLY00072109] [MT6291] Sleep mode code modification.
 * Add new L1Core/PCore common file.
 *
 * 04 22 2015 hsiao-hsien.chen
 * [MOLY00072109] [MT6291] Sleep mode code modification.
 * Modify CCIRQ interface with EL1.
 *
 * 02 06 2015 hsiao-hsien.chen
 * [MOLY00072109] [MT6291] Sleep mode code modification.
 * Add CCIRQ interface for sleep mode.
 *
 * 11 14 2014 hsiao-hsien.chen
 * [MOLY00072109] [MT6291] Sleep mode code modification.
 * modify extern api for enable frc.
 *
 * 10 25 2013 alvin.chen
 * [MOLY00043719] [MT6290][MDTOPSM] Patch for Phone Field trial activity
 * Integration change.
 *
 * 10 03 2013 alvin.chen
 * [MOLY00040177] [MT6290][MD_TOPSM] Add FRC enable API for Early Stage Debug
 * <saved by Perforce>
 *
 * 07 26 2013 barry.hong
 * [MOLY00030921] [MT6290]Low Power Feature patch back from CBr
 * Low Power Feature patch back from CBr
 *
 * 02 26 2013 jeff.lee
 * reorg. header file.
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __SLEEPDRV_INTERFACE_H__
#define __SLEEPDRV_INTERFACE_H__

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "sleepdrv_common.h"

#if defined(__SMART_PHONE_MODEM__) && defined(__MODEM_CCCI_EXIST__) && defined(__HIF_SDIO_SUPPORT__)
#define PHONE_TYPE_FOR_HQA
#endif

#if defined(TK6291) || defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)
typedef void (*SleepDrv_CCIRQ_CALLBACK_P)(kal_uint32 data1, kal_uint32 data2);
void SleepDrv_RegisterCcirqCallback(SleepDrv_CCIRQ_CMD_E cmd, SleepDrv_CCIRQ_CALLBACK_P funcp);
void SleepDrv_TriggerCcirqInterrupt(SleepDrv_CCIRQ_CMD_E cmd, kal_uint32 data1, kal_uint32 data2);
#endif /* defined(TK6291) */

kal_uint8 SleepDrv_GetHandle( void );
void SleepDrv_SleepDisable( kal_uint8 handleCount );
void SleepDrv_SleepEnable( kal_uint8 handleCount );
void SleepDrv_UpdateL1SlpDbgShmFixBuf(SLP_DBG_SHM_FIX_REG_INDEX index, kal_uint32 value);
void SleepDrv_SlpDbgShmRingBufAdd(SLP_DBG_SHM_RING_BUFFER_INDEX index, kal_uint32 status, kal_uint32 dbg_info);

/* Enable FRC API for exception handling */
extern void MD_TOPSM_EnableFRC(void); // Can remove later
extern void MODEM_TOPSM_EnableFRC(void);
extern void MODEM_TOPSM_EnableFRCandTimestamp(void);

typedef enum
{
   SLEEPDRV_EL1C,              /* NULL inject */
   SLEEPDRV_EL1SM,
   SLEEPDRV_NUM
} SleepDrv_PCore_Locker;

extern void SleepDrv_LockPcoreSleepMode(SleepDrv_PCore_Locker locker, kal_bool enable);
extern void SleepDrv_LockLMACPower(SleepDrv_PCore_Locker locker, kal_bool enable);

#endif
