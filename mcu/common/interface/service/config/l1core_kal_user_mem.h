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
 *   ctrl_buff_pool.h
 *
 * Project:
 * --------
 *   Maui_Software
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _KAL_USER_MEM_H
#define _KAL_USER_MEM_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "stack_buff_pool.h"

/**************************Customer config interface Begin********************/
/*Customer interface I:
 *
 * Discription:
 *
 * Customer can adjust system memory size here.
 * This value will be added into total size of system memory.
 * Define a negative value to shrink(not recommended), positive value to increase. 
 *
 * Tips:
 * Customer may increase it if runs out of system memory(E.g 
 * Third party application use heavily KAL API like evshed_create, kal_create_sem, 
 * kal_create_eventgroup that consume system memory more than predefined value).
 * Customer may also shrink this if want to save some RAM size. However, this 
 * is not recommended. 
 *
 * See also:
 * tools\sys_mem_gen.pl
 * 
 * 
 * Build command : 
 * make c,r custom
 *
 *Build command on Modis:
 * make clean_modis custom
 * && make remake_modis custom 
 */ 
#define CUSTOM_CFG_GLOBAL_MEM_SIZE_IN_BYTES 0

/*Customer interface II:
 *
 * Discription:
 * Customer can adjust event pool number for event scheduler
 * This value is the actual event pool number
 *
 * Tips:
 * It's rare for customer to adjust this value. However, in case
 * of runs out of event when using event scheduler, this is the 
 * place for customer to adjust the event number. It's not recommended
 * to shrink this value.
 * 
 * Build command: 
 * make sysgen && make c,r config custom
 *
 * Build command on Modis:
 * make sys_mem_gen_modis && make clean_modis config custom
 * && make remake_modis config custom
 * */ 

#if defined(__CS_SERVICE__) && defined(__PS_SERVICE__)
#if defined(__GADGET_SUPPORT__)
#define KAL_MIN_EVSHED_BUFF_NUM (80 + 500)
#elif defined(__SIP__)
#define KAL_MIN_EVSHED_BUFF_NUM 160
#else
#define KAL_MIN_EVSHED_BUFF_NUM 80
#endif
#elif defined(__CS_SERVICE__)
#if defined(__GADGET_SUPPORT__)
#define KAL_MIN_EVSHED_BUFF_NUM 540
#elif defined(__SIP__)
#define KAL_MIN_EVSHED_BUFF_NUM 160
#else
#define KAL_MIN_EVSHED_BUFF_NUM 40
#endif
#else
#define KAL_MIN_EVSHED_BUFF_NUM 40
#endif	/* defined(__CS_SERVICE__) && defined(__PS_SERVICE__) */

/*Customer interface III:
 *
 * Discription:
 * Customer can adjust control buffer size here.
 * This value will be added into total number of control buffer. 
 * Define a negative value to decrease (not recommended ), positive 
 * value to increase.
 * 
 * Tips:
 * The control buffer number is well-tuned. It's not recommended to 
 * shrink this value.
 *
 * Build command: 
 * make sysgen && make c,r config custom
 *
 * Build command on Modis:
 * make sys_mem_gen_modis && make clean_modis config custom
 * && make remake_modis config custom
 *
 * */ 
typedef enum {
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE32     = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE64     = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE128    = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE256    = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE512    = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE1024   = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE2048   = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE4096   = 0,
#if defined(__UMTS_RAT__) || defined(__LTE_RAT__)
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE8192   = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE16384  = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE32768  = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE65536  = 0,
   NUM_CUSTOM_CTRL_BUFF_POOL_SIZE100000 = 0,
#endif
} custom_ctrl_num_buff_pool_size;
/**************************Customer config interface END**********************/


/*
 * NOTICE: The following are pre-defined configration. Cutomer should not
 * modify here. 
 * 
 * */


/*************************KAL private memory config stuff*******************/
#if defined(__UMTS_RAT__) || defined(__LTE_RAT__)
#define RPS_CREATED_CTRL_BUFF_POOLS 13
#else   /* __UMTS_RAT__ || __LTE_RAT__ */
#define RPS_CREATED_CTRL_BUFF_POOLS       8
#endif  /* __UMTS_RAT__ || __LTE_RAT__ */

/* Buffer thresholds expressed in percentage */
#define FLC_CTRL_BUFF_UPPER_THRSHLD1 ( 90 )
#define FLC_CTRL_BUFF_UPPER_THRSHLD2 ( 95 )

/*************************************************************************
 * Type Definitions
 *************************************************************************/
/* For performance reason, general buffer pool is allocated for 2^n size */
typedef enum {
   CTRL_BUFF_POOL_SIZE32      = 32,
   CTRL_BUFF_POOL_SIZE64      = 64,
   CTRL_BUFF_POOL_SIZE128     = 128,
   CTRL_BUFF_POOL_SIZE256     = 256,
   CTRL_BUFF_POOL_SIZE512     = 512,
   CTRL_BUFF_POOL_SIZE1024    = 1024,
   CTRL_BUFF_POOL_SIZE2048    = 2048,
   CTRL_BUFF_POOL_SIZE4096    = 4096,
#if defined(__UMTS_RAT__) || defined(__LTE_RAT__)
   CTRL_BUFF_POOL_SIZE8192    = 8192,
   CTRL_BUFF_POOL_SIZE16384   = 16384,
   CTRL_BUFF_POOL_SIZE32768   = 32768,
   CTRL_BUFF_POOL_SIZE65536   = 65536,
   CTRL_BUFF_POOL_SIZE100000  = 100000,
   CTRL_BUFF_POOL_MAX_BUFF_SIZE = CTRL_BUFF_POOL_SIZE100000
#else   /* __UMTS_RAT__ || __LTE_RAT__ */
   CTRL_BUFF_POOL_MAX_BUFF_SIZE = CTRL_BUFF_POOL_SIZE4096
#endif  /* __UMTS_RAT__ || __LTE_RAT__ */
} ctrl_buff_pool_size;


#if defined(_SIMULATION)
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32     = 20,
   NUM_CTRL_BUFF_POOL_SIZE64     = 10,
   NUM_CTRL_BUFF_POOL_SIZE128    = 10,
   NUM_CTRL_BUFF_POOL_SIZE256    = 10,
   NUM_CTRL_BUFF_POOL_SIZE512    = 10,
   NUM_CTRL_BUFF_POOL_SIZE1024   = 10,
   NUM_CTRL_BUFF_POOL_SIZE2048   = 8,
   NUM_CTRL_BUFF_POOL_SIZE4096   = 3,
   NUM_CTRL_BUFF_POOL_SIZE8192   = 2,
   NUM_CTRL_BUFF_POOL_SIZE16384  = 2,
   NUM_CTRL_BUFF_POOL_SIZE32768  = 1,
   NUM_CTRL_BUFF_POOL_SIZE65536  = 1,
   NUM_CTRL_BUFF_POOL_SIZE100000 = 0
} ctrl_num_buff_pool_size;
#elif defined(__KTEST__)
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32     = 20,
   NUM_CTRL_BUFF_POOL_SIZE64     = 10,
   NUM_CTRL_BUFF_POOL_SIZE128    = 10,
   NUM_CTRL_BUFF_POOL_SIZE256    = 10,
   NUM_CTRL_BUFF_POOL_SIZE512    = 10,
   NUM_CTRL_BUFF_POOL_SIZE1024   = 10,
   NUM_CTRL_BUFF_POOL_SIZE2048   = 8,
   NUM_CTRL_BUFF_POOL_SIZE4096   = 5,
   NUM_CTRL_BUFF_POOL_SIZE8192   = 5,
   NUM_CTRL_BUFF_POOL_SIZE16384  = 5,
   NUM_CTRL_BUFF_POOL_SIZE32768  = 5,
   NUM_CTRL_BUFF_POOL_SIZE65536  = 5,
   NUM_CTRL_BUFF_POOL_SIZE100000 = 5
} ctrl_num_buff_pool_size;

#elif defined(__GEMINI_WCDMA__)
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32     = 620,
   NUM_CTRL_BUFF_POOL_SIZE64     = 520,
   NUM_CTRL_BUFF_POOL_SIZE128    = 150,
   NUM_CTRL_BUFF_POOL_SIZE256    = 320,
   NUM_CTRL_BUFF_POOL_SIZE512    = 55,
   NUM_CTRL_BUFF_POOL_SIZE1024   = 35,
   NUM_CTRL_BUFF_POOL_SIZE2048   = 30,
   NUM_CTRL_BUFF_POOL_SIZE4096   = 20,
   NUM_CTRL_BUFF_POOL_SIZE8192   = 8,
   NUM_CTRL_BUFF_POOL_SIZE16384  = 7,
   NUM_CTRL_BUFF_POOL_SIZE32768  = 4,
   NUM_CTRL_BUFF_POOL_SIZE65536  = 3,
#if defined(__MTK_TARGET__)
   NUM_CTRL_BUFF_POOL_SIZE100000 = 0
#else
   NUM_CTRL_BUFF_POOL_SIZE100000 = 3
#endif
} ctrl_num_buff_pool_size;
#elif defined(__LTE_RAT__) && defined(__UMTS_RAT__)
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32     = 620,
   NUM_CTRL_BUFF_POOL_SIZE64     = 260,
   NUM_CTRL_BUFF_POOL_SIZE128    = 150,
   NUM_CTRL_BUFF_POOL_SIZE256    = 160,
   NUM_CTRL_BUFF_POOL_SIZE512    = 55,
   NUM_CTRL_BUFF_POOL_SIZE1024   = 35,
   NUM_CTRL_BUFF_POOL_SIZE2048   = 30,
   NUM_CTRL_BUFF_POOL_SIZE4096   = 20,
   NUM_CTRL_BUFF_POOL_SIZE8192   = 8,
   NUM_CTRL_BUFF_POOL_SIZE16384  = 7,
   NUM_CTRL_BUFF_POOL_SIZE32768  = 4,
   NUM_CTRL_BUFF_POOL_SIZE65536  = 3,
#if defined(__MTK_TARGET__)   
   NUM_CTRL_BUFF_POOL_SIZE100000 = 0
#else
   NUM_CTRL_BUFF_POOL_SIZE100000 = 3
#endif
} ctrl_num_buff_pool_size;
#elif defined(__LTE_RAT__)
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32     = 420,
   NUM_CTRL_BUFF_POOL_SIZE64     = 190,
   NUM_CTRL_BUFF_POOL_SIZE128    = 80,
   NUM_CTRL_BUFF_POOL_SIZE256    = 105,
   NUM_CTRL_BUFF_POOL_SIZE512    = 24,
   NUM_CTRL_BUFF_POOL_SIZE1024   = 25,
   NUM_CTRL_BUFF_POOL_SIZE2048   = 30,
   NUM_CTRL_BUFF_POOL_SIZE4096   = 20,
   NUM_CTRL_BUFF_POOL_SIZE8192   = 6,
   NUM_CTRL_BUFF_POOL_SIZE16384  = 6,
   NUM_CTRL_BUFF_POOL_SIZE32768  = 4,
   NUM_CTRL_BUFF_POOL_SIZE65536  = 3,
#if defined(__MTK_TARGET__)
   NUM_CTRL_BUFF_POOL_SIZE100000 = 0
#else
   NUM_CTRL_BUFF_POOL_SIZE100000 = 3 // for MoDIS Only - 3G ASN.1 CODEC usage
#endif
} ctrl_num_buff_pool_size;

#elif defined(__UMTS_RAT__)

   #if defined(__UMTS_TDD128_MODE__)
      #if defined(__UMTS_R5__) /* __UMTS_R5__ */
         #if defined(__GEMINI__) || defined(__SGLTE__)
            typedef enum {
		          NUM_CTRL_BUFF_POOL_SIZE32     = 375,
		          NUM_CTRL_BUFF_POOL_SIZE64     = 185,
		          NUM_CTRL_BUFF_POOL_SIZE128    = 130,
		          NUM_CTRL_BUFF_POOL_SIZE256    = 105,
		          NUM_CTRL_BUFF_POOL_SIZE512    = 65,
		          NUM_CTRL_BUFF_POOL_SIZE1024   = 25,
		          NUM_CTRL_BUFF_POOL_SIZE2048   = 15,
		          NUM_CTRL_BUFF_POOL_SIZE4096   = 10,
		          NUM_CTRL_BUFF_POOL_SIZE8192   = 7,
		          NUM_CTRL_BUFF_POOL_SIZE16384  = 6,
		          NUM_CTRL_BUFF_POOL_SIZE32768  = 3,
		          NUM_CTRL_BUFF_POOL_SIZE65536  = 3,
		          #if defined(__MTK_TARGET__)   
		          NUM_CTRL_BUFF_POOL_SIZE100000 = 0
		          #else
		          NUM_CTRL_BUFF_POOL_SIZE100000 = 3
		          #endif
		       } ctrl_num_buff_pool_size;
	      #else 
	      	typedef enum {
	            NUM_CTRL_BUFF_POOL_SIZE32     = 300,
	            NUM_CTRL_BUFF_POOL_SIZE64     = 185,
	            NUM_CTRL_BUFF_POOL_SIZE128    = 130,
	            NUM_CTRL_BUFF_POOL_SIZE256    = 105,
	            NUM_CTRL_BUFF_POOL_SIZE512    = 65,
	            NUM_CTRL_BUFF_POOL_SIZE1024   = 25,
	            NUM_CTRL_BUFF_POOL_SIZE2048   = 14,
	            NUM_CTRL_BUFF_POOL_SIZE4096   = 10,
	            NUM_CTRL_BUFF_POOL_SIZE8192   = 7,
	            NUM_CTRL_BUFF_POOL_SIZE16384  = 6,
	            NUM_CTRL_BUFF_POOL_SIZE32768  = 3,
	            NUM_CTRL_BUFF_POOL_SIZE65536  = 3,
	            #if defined(__MTK_TARGET__)   
	            NUM_CTRL_BUFF_POOL_SIZE100000 = 0
	            #else
	            NUM_CTRL_BUFF_POOL_SIZE100000 = 3
	            #endif
	         } ctrl_num_buff_pool_size;
	      #endif
      #endif  /* __UMTS_R5__ */
   #else  /* __UMTS_TDD128_MODE__ */
      #if defined(__UMTS_R7__)    /*__UMTS_R7__*/
        typedef enum {
               NUM_CTRL_BUFF_POOL_SIZE32     = 610,
               NUM_CTRL_BUFF_POOL_SIZE64     = 260,
               NUM_CTRL_BUFF_POOL_SIZE128    = 150,
               NUM_CTRL_BUFF_POOL_SIZE256    = 110,
               NUM_CTRL_BUFF_POOL_SIZE512    = 55,
               NUM_CTRL_BUFF_POOL_SIZE1024   = 35,
               NUM_CTRL_BUFF_POOL_SIZE2048   = 20,
               NUM_CTRL_BUFF_POOL_SIZE4096   = 10,
               NUM_CTRL_BUFF_POOL_SIZE8192   = 8,
               NUM_CTRL_BUFF_POOL_SIZE16384  = 7,
               NUM_CTRL_BUFF_POOL_SIZE32768  = 4,
               NUM_CTRL_BUFF_POOL_SIZE65536  = 3,
               #if defined(__MTK_TARGET__)   
               NUM_CTRL_BUFF_POOL_SIZE100000 = 0
               #else
               NUM_CTRL_BUFF_POOL_SIZE100000 = 3
               #endif
            } ctrl_num_buff_pool_size;
      #elif defined(__UMTS_R5__)  /* __UMTS_R5__ */
            typedef enum {
               NUM_CTRL_BUFF_POOL_SIZE32     = 550,
               NUM_CTRL_BUFF_POOL_SIZE64     = 190,
               NUM_CTRL_BUFF_POOL_SIZE128    = 145,
         #if defined(__GEMINI_MONITOR_PAGE_DURING_TRANSFER__)  /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
               NUM_CTRL_BUFF_POOL_SIZE256    = 120,
               #else
               NUM_CTRL_BUFF_POOL_SIZE256    = 100,
               #endif
               NUM_CTRL_BUFF_POOL_SIZE512    = 50,
               NUM_CTRL_BUFF_POOL_SIZE1024   = 30,
               NUM_CTRL_BUFF_POOL_SIZE2048   = 15,
               NUM_CTRL_BUFF_POOL_SIZE4096   = 10,
               NUM_CTRL_BUFF_POOL_SIZE8192   = 8,
               NUM_CTRL_BUFF_POOL_SIZE16384  = 6,
               NUM_CTRL_BUFF_POOL_SIZE32768  = 3,
               NUM_CTRL_BUFF_POOL_SIZE65536  = 3,
               #if defined(__MTK_TARGET__)   
               NUM_CTRL_BUFF_POOL_SIZE100000 = 0
               #else
               NUM_CTRL_BUFF_POOL_SIZE100000 = 3
               #endif
            } ctrl_num_buff_pool_size;
      #else  /* __UMTS_R5__ */
         typedef enum {
            NUM_CTRL_BUFF_POOL_SIZE32     = 500,
            NUM_CTRL_BUFF_POOL_SIZE64     = 225,
            NUM_CTRL_BUFF_POOL_SIZE128    = 130,
            NUM_CTRL_BUFF_POOL_SIZE256    = 95,
            NUM_CTRL_BUFF_POOL_SIZE512    = 40,
            NUM_CTRL_BUFF_POOL_SIZE1024   = 34,
            NUM_CTRL_BUFF_POOL_SIZE2048   = 14,
            NUM_CTRL_BUFF_POOL_SIZE4096   = 10,
            NUM_CTRL_BUFF_POOL_SIZE8192   = 10,
            NUM_CTRL_BUFF_POOL_SIZE16384  = 4,
            NUM_CTRL_BUFF_POOL_SIZE32768  = 3,
            NUM_CTRL_BUFF_POOL_SIZE65536  = 3,
            #if defined(__MTK_TARGET__)   
            NUM_CTRL_BUFF_POOL_SIZE100000 = 0
            #else
            NUM_CTRL_BUFF_POOL_SIZE100000 = 3
            #endif
         } ctrl_num_buff_pool_size;
      #endif  /* __UMTS_R5__ */
   #endif /* __UMTS_TDD128_MODE__ */

#elif defined(__CS_SERVICE__) && defined(__PS_SERVICE__)    /* __UMTS_RAT__ */

/* GPRS Class B Solution */
#if ( GEMINI_PLUS > 2 )
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 185,
   NUM_CTRL_BUFF_POOL_SIZE64   = 50,
   NUM_CTRL_BUFF_POOL_SIZE128  = 40,
   NUM_CTRL_BUFF_POOL_SIZE256  = 30,
   NUM_CTRL_BUFF_POOL_SIZE512  = 27,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 10,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 10,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;
#elif defined(__GEMINI__) || defined(__SGLTE__)
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 175,
   NUM_CTRL_BUFF_POOL_SIZE64   = 50,
   NUM_CTRL_BUFF_POOL_SIZE128  = 30,
   NUM_CTRL_BUFF_POOL_SIZE256  = 30,
   NUM_CTRL_BUFF_POOL_SIZE512  = 14,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 10,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 7,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;
#else /* defined(__GEMINI__) */
typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 100,
   NUM_CTRL_BUFF_POOL_SIZE64   = 50,
   NUM_CTRL_BUFF_POOL_SIZE128  = 30,
   NUM_CTRL_BUFF_POOL_SIZE256  = 30,
   NUM_CTRL_BUFF_POOL_SIZE512  = 14,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 10,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 5,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;
#endif /* defined(__GEMINI__) */

#elif defined(__CS_SERVICE__)   /* __UMTS_RAT__ */

#if defined(IC_BURNIN_TEST)

/* Reduce the No. of buffer to reduce memory consumption. */

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 10,
   NUM_CTRL_BUFF_POOL_SIZE64   = 5,
   NUM_CTRL_BUFF_POOL_SIZE128  = 5,
   NUM_CTRL_BUFF_POOL_SIZE256  = 5,
   NUM_CTRL_BUFF_POOL_SIZE512  = 2,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 5,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 3,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 1
} ctrl_num_buff_pool_size;

#elif defined(LOW_COST_SUPPORT) /* LOW_COST_SUPPORT */

#if defined(__LOW_COST_SUPPORT_ULC__) /* __LOW_COST_SUPPORT_ULC__ */

#if defined(__GEMINI__) || defined(__SGLTE__) /* __GEMINI__ */

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 92, /*98*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 18, /*20*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 40,
   NUM_CTRL_BUFF_POOL_SIZE256  = 28, /*30*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 20,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 9,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 6,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#else /* __GEMINI__ */

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 57,/*63*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 18,/*20*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 30,
   NUM_CTRL_BUFF_POOL_SIZE256  = 15,/*17*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 8,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 8,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 4,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#endif /* __GEMINI__ */

#else /* __LOW_COST_SUPPORT_ULC__ */

#if ( GEMINI_PLUS > 3 )

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 92, /*98*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 36, /*38*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 40,
   NUM_CTRL_BUFF_POOL_SIZE256  = 30, /*32*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 20,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 12,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 13,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#elif ( GEMINI_PLUS > 2 )

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 92, /*98*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 31, /*33*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 40,
   NUM_CTRL_BUFF_POOL_SIZE256  = 29, /*31*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 20,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 10,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 10,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#elif defined(__GEMINI__) || defined(__SGLTE__) /* __GEMINI__ */

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 92,/*98*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 18,/*20*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 40,
   NUM_CTRL_BUFF_POOL_SIZE256  = 28,/*30*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 20,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 9,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 7,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#else /* __GEMINI__ */

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 92,/*98*/
   NUM_CTRL_BUFF_POOL_SIZE64   = 18,/*20*/
   NUM_CTRL_BUFF_POOL_SIZE128  = 40,
   NUM_CTRL_BUFF_POOL_SIZE256  = 28,/*30*/
   NUM_CTRL_BUFF_POOL_SIZE512  = 20,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 9,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 7,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#endif /* __GEMINI__ */

#endif /* __LOW_COST_SUPPORT_ULC__ */

#else  /* LOW_COST_SUPPORT (default configuration for BASIC, UDVT load) */

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 63,
   NUM_CTRL_BUFF_POOL_SIZE64   = 20,
   NUM_CTRL_BUFF_POOL_SIZE128  = 30,
   NUM_CTRL_BUFF_POOL_SIZE256  = 17,
   NUM_CTRL_BUFF_POOL_SIZE512  = 8,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 8,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 4,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#endif  /* LOW_COST_SUPPORT */

#else

typedef enum {
   NUM_CTRL_BUFF_POOL_SIZE32   = 63,
   NUM_CTRL_BUFF_POOL_SIZE64   = 20,
   NUM_CTRL_BUFF_POOL_SIZE128  = 30,
   NUM_CTRL_BUFF_POOL_SIZE256  = 17,
   NUM_CTRL_BUFF_POOL_SIZE512  = 8,
   NUM_CTRL_BUFF_POOL_SIZE1024 = 8,
   NUM_CTRL_BUFF_POOL_SIZE2048 = 4,
   NUM_CTRL_BUFF_POOL_SIZE4096 = 0
} ctrl_num_buff_pool_size;

#endif  /* __UMTS_RAT__ */

/*************************************************************************
 * Exported Global Variables
 *************************************************************************/
extern buff_pool_info_struct ctrl_buff_pool_info_g[ RPS_CREATED_CTRL_BUFF_POOLS];

/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
extern void config_ctrl_buff_info( void );
#endif /*_KAL_USER_MEM_H*/


