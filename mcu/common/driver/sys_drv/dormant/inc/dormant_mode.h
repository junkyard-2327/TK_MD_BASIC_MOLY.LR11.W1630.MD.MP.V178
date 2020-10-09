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
 *   dormant_mode.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines device information related stuff
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"

#ifndef __DORMANT_MODE_H__
#define __DORMANT_MODE_H__


#if defined(__MTK_TARGET__)
  #define __SECTION__(S)        __attribute__((__section__(#S)))
  #define __ZI__                __attribute__((zero_init))
  #if defined(__GNUC__)
    #define __Long_Call__       __attribute__((long_call))
  #else /*! __GNUC__ */
    #define __Long_Call__ 
  #endif /* __GNUC__ */
  #define __DOR_TCM_DATA__          __SECTION__(INTSRAM_RW)
  #define __DOR_TCM_BSS__           __SECTION__(INTSRAM_ZI) __ZI__ 
  #define __DOR_TCM_CONST__         __SECTION__(INTSRAM_RODATA)
  #define __DOR_TCM_FUNC__          __Long_Call__  __SECTION__(INTSRAM_ROCODE)
  #define __DOR_TCM_LOCAL_FUNC__    __SECTION__(INTSRAM_ROCODE)

  #define __DOR_NONCACHED_DATA__    __SECTION__(NONCACHEDRW)
  #define __DOR_NONCACHED_BSS__     __SECTION__(NONCACHEDZI) __ZI__

#else

#define __DOR_TCM_DATA__  
#define __DOR_TCM_BSS__  
#define __DOR_TCM_CONST__  
#define __DOR_TCM_FUNC__  
#define __DOR_TCM_LOCAL_FUNC__  

#define __DOR_NONCACHED_DATA__  
#define __DOR_NONCACHED_BSS__  

#endif /* __MTK_TARGET__ */

/* 
 * Dormant mode storage size definition 
 */
#define DORMANT_TCM_STORAGE_SIZE   (512)
#define DORMANT_EMI_STORAGE_SIZE   (64)
#define DORMANT_STACK_SIZE         (512)

/*
 * Dormant mode support routines
 */
extern void dormant_mode_init(void);
extern void enter_dormant_mode(void);
extern void leave_dormant_mode(void);
extern void arm_dormant_reset_handler(void);
extern void dormant_mode_reset_interwork(void);


/* 
 * Platform dependent HW register definition 
 */
#if 0
#if defined(MT6290)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(MT6595)
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
#elif defined(TK6291)
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
#endif /* !MT6575 */
/* under construction !*/
/* under construction !*/
#endif /* change include mechanism after TK6291 */

//#if defined(TK6291)
//    #define CACHE_FLUSH_IN_DORMANT 0
//#endif /* Chip Features */


#endif
