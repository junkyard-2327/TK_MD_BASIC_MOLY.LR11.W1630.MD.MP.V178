/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *   cmif.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
  * $Revision$
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CMIF_H__
#define __CMIF_H__


#define __CMIF_MD32S_CORE__  (defined(__CORE_BRP__) || defined(__CORE_DFE__) || defined(__CORE_RAKE__))

#if __CMIF_MD32S_CORE__
#include "reg_base.h"
#include "mos_public.h"

#else  /* __CMIF_MD32S_CORE__ */
#include "kal_public_api.h"
#include "kal_general_types.h"

#endif /* __CMIF_MD32S_CORE__ */

/*******************************************************************************
  * CMIF Memory Definition 
  *******************************************************************************/
#define CMIF_NUM_INTERRUPT_U3G_SOURCES               (32)
#define CMIF_NUM_INTERRUPT_U4G_SOURCES               (32)

/* MD32 Side */
#define CMIF_BRP_BASE_ADDR                           (CMIF_base)
#define CMIF_RAKE_BASE_ADDR                          (CMIF_base)
#define CMIF_DFE_BASE_ADDR                           (CMIF_base)

/* CR4 side */
#define CMIF_CR4_BRP_BASE_ADDR                       (0xF9358000)
#define CMIF_CR4_RAKE_BASE_ADDR                      (0xF9B58000)
#define CMIF_CR4_DFE_BASE_ADDR                       (0xF7B58000)

/* CR4 side for BRP */
#define CMIF_C2M_U3G_BRP_INTERRUPT_STATUS_OFFSET     (0x0C)
#define CMIF_C2M_U3G_BRP_INTERRUPT_SET_OFFSET        (0x10)
#define CMIF_C2M_U3G_BRP_INTERRUPT_CLEAN_OFFSET      (0x10)
#define CMIF_C2M_U4G_BRP_INTERRUPT_STATUS_OFFSET     (0x14)
#define CMIF_C2M_U4G_BRP_INTERRUPT_SET_OFFSET        (0x18)
#define CMIF_C2M_U4G_BRP_INTERRUPT_CLEAN_OFFSET      (0x18)

/* BRP */
#define CMIF_M2C_U3G_BRP_INTERRUPT_STATUS_OFFSET     (0x1C)
#define CMIF_M2C_U3G_BRP_INTERRUPT_SET_OFFSET        (0x20)
#define CMIF_M2C_U3G_BRP_INTERRUPT_CLEAN_OFFSET      (0x20)
#define CMIF_M2C_U4G_BRP_INTERRUPT_STATUS_OFFSET     (0x24)
#define CMIF_M2C_U4G_BRP_INTERRUPT_SET_OFFSET        (0x28)
#define CMIF_M2C_U4G_BRP_INTERRUPT_CLEAN_OFFSET      (0x28)

/* CR4 side for Rake */
#define CMIF_C2M_U3G_RAKE_INTERRUPT_STATUS_OFFSET    (0x0C)
#define CMIF_C2M_U3G_RAKE_INTERRUPT_SET_OFFSET       (0x10)
#define CMIF_C2M_U3G_RAKE_INTERRUPT_CLEAN_OFFSET     (0x10)

/* RAKE  */
#define CMIF_M2C_U3G_RAKE_INTERRUPT_STATUS_OFFSET    (0x1C)
#define CMIF_M2C_U3G_RAKE_INTERRUPT_SET_OFFSET       (0x20)
#define CMIF_M2C_U3G_RAKE_INTERRUPT_CLEAN_OFFSET     (0x20)

/* CR4 side for DFE */
#define CMIF_C2M_U3G_DFE_INTERRUPT_STATUS_OFFSET     (0x0C)
#define CMIF_C2M_U3G_DFE_INTERRUPT_SET_OFFSET        (0x10)
#define CMIF_C2M_U3G_DFE_INTERRUPT_CLEAN_OFFSET      (0x10)
#define CMIF_C2M_U4G_DFE_INTERRUPT_STATUS_OFFSET     (0x14)
#define CMIF_C2M_U4G_DFE_INTERRUPT_SET_OFFSET        (0x18)
#define CMIF_C2M_U4G_DFE_INTERRUPT_CLEAN_OFFSET      (0x18)

/* DFE */
#define CMIF_M2C_U3G_DFE_INTERRUPT_STATUS_OFFSET     (0x1C)
#define CMIF_M2C_U3G_DFE_INTERRUPT_SET_OFFSET        (0x20)
#define CMIF_M2C_U3G_DFE_INTERRUPT_CLEAN_OFFSET      (0x20)
#define CMIF_M2C_U4G_DFE_INTERRUPT_STATUS_OFFSET     (0x24)
#define CMIF_M2C_U4G_DFE_INTERRUPT_SET_OFFSET        (0x28)
#define CMIF_M2C_U4G_DFE_INTERRUPT_CLEAN_OFFSET      (0x28)


/*******************************************************************************
 * Typedefs 
 *******************************************************************************/
#if __CMIF_MD32S_CORE__
typedef mos_char                cmif_char;
typedef mos_uint8               cmif_uint8;
typedef mos_int8                cmif_int8;
typedef mos_uint16              cmif_uint16;
typedef mos_int16               cmif_int16;
typedef mos_uint32              cmif_uint32;
typedef mos_int32               cmif_int32;
typedef mos_bool                cmif_bool;

#define CMIF_TRUE               MOS_TRUE
#*define CMIF_FALSE              MOS_FALSE

#else /* __CMIF_MD32S_CORE__ */
typedef kal_char                cmif_char;   
typedef kal_uint8               cmif_uint8;  
typedef kal_int8                cmif_int8;   
typedef kal_uint16              cmif_uint16; 
typedef kal_int16               cmif_int16;  
typedef kal_uint32              cmif_uint32; 
typedef kal_int32               cmif_int32;  
typedef kal_bool                cmif_bool;

#define CMIF_TRUE               KAL_TRUE
#define CMIF_FALSE              KAL_FALSE

#endif /* __CMIF_MD32S_CORE__ */

#define CMIF_REG_READ(addr)          *(addr)
#define CMIF_REG_WRITE(addr, value)  *(addr) = (value)

// Define status register type
typedef struct{
    cmif_uint32 mask31_0;    
}CMIF_Mask_t;

// Define user callback function type
typedef void (*CMIF_InterruptEntryFun)(CMIF_Mask_t*);

#if __CMIF_MD32S_CORE__
#include "cmif_md32.h"

/* MD32 side */
/**
  *   CMIF Init function
  */
extern void CMIF_Init();

#else
#include "drv_cmif_l1core.h"
#endif


/*******************************************************************************
 * Debug feature 
 *******************************************************************************/
#if defined(__CMIF_DEBUG__)

#if __CMIF_MD32S_CORE__
/* MD32 side */
#define CMIF_DEBUG_API_RECORD_SIZE        8 
#define CMIF_DEBUG_ISR_HANDLE_CODE_SIZE   8 

#else  /*  __CMIF_MD32S_CORE__ */

#define CMIF_DEBUG_API_RECORD_SIZE        16 
#define CMIF_DEBUG_ISR_HANDLE_CODE_SIZE   16 

#endif /*  __CMIF_MD32S_CORE__ */


typedef enum CMIF_DebugInterrupt_enum{
    CMIF_DEBUG_U3G_INTERRUPT,
    CMIF_DEBUG_U4G_INTERRUPT
}CMIF_DebugInterruptType;

typedef cmif_uint8 CMIF_DebugISRCode;

/** The Ring Buffer */
typedef struct{
    CMIF_DebugISRCode code[CMIF_DEBUG_ISR_HANDLE_CODE_SIZE];
    cmif_uint32 top_index;
}CMIF_DebugISRCodeList;

typedef struct{
    CMIF_Mask_t before;
    CMIF_Mask_t after;
    cmif_uint32 set_addr;     /**< The control register address */
    cmif_uint32 set_value;    /**< The writing value for the control regsiters */
    cmif_uint32 caller;       /**< The caller address */
}CMIF_DebugRecord;

/** The Ring Buffer */
typedef struct{
    CMIF_DebugRecord records[CMIF_DEBUG_API_RECORD_SIZE];
    cmif_uint32 top_index; 
}CMIF_DebugRecordList;

void cmif_DebugAddRecord(CMIF_Mask_t* before,
                         CMIF_Mask_t* after,
                         cmif_uint32 set_addr,
                         cmif_uint32 set_value,
                         cmif_uint32 caller);

#if __CMIF_MD32S_CORE__
void cmif_DebugAddISRHandleCode(CMIF_DebugISRCode code, CMIF_DebugInterruptType isr_type);
#else /*  __CMIF_MD32S_CORE__  */
void cmif_DebugAddISRHandleCode(CMIF_DebugISRCode code, CMIF_MD32_Core_t, CMIF_DebugInterruptType isr_type);
#endif /* __CMIF_MD32S_CORE__  */

#endif /* __CMIF_DEBUG__  */


#endif   /* __CMIF_H__ */
