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
 *   kalcc_afm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
 *   .
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef _CC_AFM_H
#define _CC_AFM_H

#include "kal_general_types.h"
#include "kalcc_ctrl_buff_pool.h"
#include "spinlock.h"

#include "kal_internal_api.h" /*for kal_history_node_t*/

/*******************************************************************************
 * define
 *******************************************************************************/



/*******************************************************************************
 * Constant definitions
 *******************************************************************************/

#define CC_AFM_CB_ID         0x88888888 
#define CC_AFM_HEAD_STAMP    0xF3F3
#define CC_AFM_FOOT_STAMP    0xF4F4
#define CC_AFM_END_STAMP     0xEEEE
#define CC_AFM_MAX_PRINT_LEN 128
#define CC_AFM_INUSE         0
#define CC_AFM_FREE          1
#define CC_AFM_STS_BIT       1
#define CC_AFM_ALLOC_STAMP   0xFFFFFFFF

/*******************************************************************************
 * Data structure definitions
 *******************************************************************************/
    

typedef struct CC_AFM_MB_HISROTY_STRUCT {
   const kal_char*                file_name;
   kal_uint32                     line;
   kal_uint32                     size;
   kal_uint32                     ticks_stamp;
   kal_buff_state                 buffer_state;
   kal_uint16                     alloc_id;
} CC_AFM_MB_HISROTY_T;

typedef struct CC_AFM_MB_STAT_STRUCT
{
    LCD_IP_CQUEUE( CC_AFM_MB_HISROTY_T, KAL_MAX_BUFF_HISTORY ) buff_history;
} CC_AFM_MB_STAT_T;

typedef struct CC_AFM_POOL_STATISTIC_STURCT
{
    kal_uint16   current_allocation;
    kal_uint16   max_num_allocation;
    kal_uint32   max_size_requested;
} CC_AFM_POOL_STATISTIC_T;


typedef struct CC_AFM_POOL_STAT_STRUCT
{
    CC_AFM_POOL_STATISTIC_T pool_info;
    CC_AFM_MB_STAT_T        *buff_stat;
} CC_AFM_POOL_STAT_T;

typedef struct CC_AFM_POOL_CB_STRUCT
{
    kal_uint32 buff_size;
    kal_uint16 buff_nr;
    kal_uint16 left_buff_nr;
    struct CC_AFM_MB_HEAD_STRUCT *free_head;
    struct CC_AFM_MB_HEADGUD_STRUCT *static_head;
    CC_AFM_POOL_STAT_T *pool_stat;
    struct CC_AFM_CB_STRUCT *afm;
    kal_uint16 subpool_index;
    kal_uint16 reserved;
    kal_uint32 buff_addr_start;
    kal_uint32 buff_addr_end;
} CC_AFM_POOL_CB_T;

typedef struct CC_AFM_CB_STRUCT
{
    kal_uint32 id;
    kal_uint16 subpool_nr;
    kal_uint16 operating_owner;  //mod_id
    CC_AFM_POOL_CB_T afm_pool[0];   // pool[0] is embedded in CC_AFM_CB_T, size is 0
} CC_AFM_CB_T;


typedef struct CC_AFM_MB_HEAD_STRUCT
{
    struct CC_AFM_MB_HEAD_STRUCT *next_free;
    CC_AFM_POOL_CB_T *pool;
    kal_uint16 buff_index;
    kal_uint16 operating_owner;
    kal_uint16 size;
    kal_uint8  reserved[6];
} CC_AFM_MB_HEAD_T;

typedef struct CC_AFM_MB_HEADGUD_STRUCT
{
    struct CC_AFM_MB_HEADGUD_STRUCT     *static_next;
    kal_uint16                          stamp;
    kal_uint16                          buff_index;
    kal_uint8                           padding[4];
} CC_AFM_MB_HEADGUD_T;


typedef struct CC_AFM_MB_FOOTGUD_STRUCT
{
    kal_uint16      stamp;
    kal_uint16      buff_index;
    kal_uint8       padding[28];
} CC_AFM_MB_FOOTGUD_T;


typedef struct
{
    CC_AFM_MB_HISROTY_T     history;
    kal_uint32              count;
} CC_AFM_CM_OPERATOR;


typedef struct
{
    CC_AFM_CM_OPERATOR     top_operator;
    CC_AFM_CM_OPERATOR     second_operator;
    CC_AFM_CM_OPERATOR     third_operator;
} CC_AFM_POOL_TOP3_OPERATOR;


/*******************************************************************************
 * Macros definitions
 *******************************************************************************/
#define CC_AFM_PREPARE_NISTORY_NODE(new_node, file, line_num, Size, ticks, state, mod_id) \
    new_node.file_name = file;      new_node.line = line_num;       new_node.size = Size; \
    new_node.ticks_stamp = ticks;   new_node.buffer_state = state;  new_node.alloc_id = mod_id;

#define CC_AFM_GET_INDEXED_SUBPOOL(afm_id, idx) (CC_AFM_POOL_CB_T *)((kal_uint8*)(afm_id) + sizeof(CC_AFM_CB_T) + (sizeof(CC_AFM_POOL_CB_T) * (idx)))

#define CC_AFM_GET_HEADGUD(afm_mb) (CC_AFM_MB_HEADGUD_T *)((kal_uint8*)(afm_mb) + sizeof(CC_AFM_MB_HEAD_T))

#define CC_AFM_GET_FOOTGUD(afm_mb) (CC_AFM_MB_FOOTGUD_T *)((kal_uint8*)(afm_mb) + sizeof(CC_AFM_MB_HEAD_T) + sizeof(CC_AFM_MB_HEADGUD_T) + ((CC_AFM_MB_HEAD_T*)(afm_mb))->pool->buff_size)

#define CC_AFM_SET_HEADGUD(afm_head, buff_id, gudptn) \
    { \
        ((CC_AFM_MB_HEADGUD_T*)(afm_head))->buff_index = buff_id; \
        ((CC_AFM_MB_HEADGUD_T*)(afm_head))->stamp = gudptn; \
    }

#define CC_AFM_SET_FOOTGUD(afm_foot, buff_id, gudptn) \
    { \
        ((CC_AFM_MB_FOOTGUD_T*)(afm_foot))->buff_index = buff_id; \
        ((CC_AFM_MB_FOOTGUD_T*)(afm_foot))->stamp = gudptn; \
    }

/* legacy macro, use to get first free head of pool 0, replaced by CC_AFM_GET_INDEXED_SUBPOOL(subpool_nr)*/
#define CC_AFM_GET_FIRST_FREEHEAD(afm_id, buf_no, first_freehead) \
    { \
        kal_int32 idx, sz = 0; \
        CC_AFM_POOL_CB_T * subpool =  CC_AFM_GET_INDEXED_SUBPOOL(afm_id, 0); \
        for(idx = 0; idx < (buf_no); idx++) { \
            sz += ((subpool->buff_size + sizeof(CC_AFM_MB_HEAD_T)) * subpool->buff_nr); \
            subpool += sizeof(CC_AFM_POOL_CB_T); \
        } \
        first_freehead = (CC_AFM_MB_HEAD_T *)((kal_uint8*)(afm_id) + sizeof(CC_AFM_CB_T) + (sizeof(CC_AFM_POOL_CB_T) * (afm_id->subpool_nr)) + sz); \
   }

/* unused macro */
#define CC_AFM_GET_FIRST_FREEHEAD_GUDPTN(afm_id, subpool_sz, subpool_nr, buf_no, first_freehead) \
    { \
        kal_int32 idx, sz = 0; \
        for(idx = 0; idx < (buf_no); idx++) { \
            sz += ((subpool_sz[idx]+sizeof(CC_AFM_MB_HEAD_T)+sizeof(CC_AFM_MB_HEADGUD_T)+sizeof(CC_AFM_MB_FOOTGUD_T)) * subpool_nr[idx]); \
        } \
        first_freehead = (CC_AFM_MB_HEAD_T *)((kal_uint8*)(afm_id) + sizeof(CC_AFM_CB_T) + (sizeof(CC_AFM_POOL_CB_T) * (afm_id->subpool_nr)) + sz); \
   }


/* unused macro */
#define CC_AFM_GET_AFMPOOL_END(afm_id, subpool_sz, subpool_nr, total_buf_no, end_addr) \
   { \
	   kal_int32 idx, sz = 0; \
	   for(idx = 0; idx < (total_buf_no); idx++) { \
	       sz += ((subpool_sz[idx]+sizeof(CC_AFM_MB_HEAD_T)) * subpool_nr[idx]); \
	   } \
	   end_addr = (kal_uint32)((kal_uint8*)(afm_id) + sizeof(CC_AFM_CB_T) + (sizeof(CC_AFM_POOL_CB_T) * (afm_id->subpool_nr)) + sz); \
   }

/* unused macro */
#define CC_AFM_GET_AFMPOOL_END_GUDPTN(afm_id, subpool_sz, subpool_nr, total_buf_no, end_addr) \
   { \
	   kal_int32 idx, sz = 0; \
	   for(idx = 0; idx < (total_buf_no); idx++) { \
	       sz += ((subpool_sz[idx]+sizeof(CC_AFM_MB_HEAD_T)+sizeof(CC_AFM_MB_HEADGUD_T)+sizeof(CC_AFM_MB_FOOTGUD_T)) * subpool_nr[idx]); \
	   } \
	   end_addr = (kal_uint32)((kal_uint8*)(afm_id) + sizeof(CC_AFM_CB_T) + (sizeof(CC_AFM_POOL_CB_T) * (afm_id->subpool_nr)) + sz); \
   }


#define CC_AFM_MB_HEADGUD_SET_INUSE(afm_mb_headgud) \
        (afm_mb_headgud)->static_next = (CC_AFM_MB_HEADGUD_T *)((kal_uint32)(afm_mb_headgud)->static_next | CC_AFM_STS_BIT)
    
#define CC_AFM_MB_HEADGUD_SET_FREE(afm_mb_headgud) \
	    (afm_mb_headgud)->static_next = (CC_AFM_MB_HEADGUD_T *)((kal_uint32)(afm_mb_headgud)->static_next & ~CC_AFM_STS_BIT)
	        
#define CC_AFM_MB_HEADGUD_STATE(afm_mb_headgud) \
		(((kal_uint32)(afm_mb_headgud)->static_next & CC_AFM_STS_BIT)? CC_AFM_INUSE: CC_AFM_FREE)

#define CC_AFM_MB_HEADGUD_NEXT(afm_mb_headgud) \
		(CC_AFM_MB_HEADGUD_T *)((kal_uint32)(afm_mb_headgud)->static_next & ~CC_AFM_STS_BIT)

#define CC_AFM_MB_HEADGUD_SET_NEXT(oldval, newval) \
		(CC_AFM_MB_HEADGUD_T *)((kal_uint32)(newval) | ((kal_uint32)(oldval) & CC_AFM_STS_BIT))

#define CC_AFM_MB_SET_OWNER(afm_mb, mod_id) \
       ((CC_AFM_MB_HEAD_T *)(afm_mb))->operating_owner = (kal_uint16)(mod_id)


#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__))
#define CC_AFM_ROUNDUP_2_CACHE_LINE(value) (value) = ((((value) + (CPU_CACHE_LINE_SIZE-1)) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET)

#define CC_AFM_ROUNDDOWN_2_CACHE_LINE(value) (value) = (((value) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET)

#define CC_AFM_GET_CACHE_LINE_ALIGN_PAD(value) (((((value) + (CPU_CACHE_LINE_SIZE-1)) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET)-value)
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __DYNAMIC_SWITCH_CACHEABILITY__) */

#define CC_AFM_ROUNDUP_2_4B(value) (value) = ((((value) + (4-1)) >> 2) << 2)

/********* define macro to caculate require size, internal part ***************/
#define __ALIGN4(sz) (((sz) + 3) & ~3)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__))
#define __ALIGNCACHE(sz) (((sz) + CPU_CACHE_LINE_SIZE-1) & ~(CPU_CACHE_LINE_SIZE-1))
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __DYNAMIC_SWITCH_CACHEABILITY__) */

#define _KAL_CC_AFM_MB_OVERHEAD(option) (sizeof(CC_AFM_MB_HEAD_T) + (option & CC_AFM_OPT_DBG ? sizeof(CC_AFM_MB_HEADGUD_T) + sizeof(CC_AFM_MB_FOOTGUD_T) : 0))
#define _KAL_CC_AFM_POOLSIZE_BASE(pcount) \
    (sizeof(CC_AFM_CB_T) + sizeof(CC_AFM_POOL_CB_T) * pcount
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__))
#define _KAL_CC_AFM_POOLSIZE_PARTITION(option, sz, nr) \
        (nr) * (__ALIGNCACHE(sz) + __ALIGNCACHE(_KAL_CC_AFM_MB_OVERHEAD(option))) 
#endif

/*******************************   PUBLIC API  ********************************/

#define KAL_CC_AFM_POOL_OVERHEAD(option, subpool_count) (_KAL_CC_AFM_POOLSIZE_BASE((subpool_count), (option)))
#define KAL_CC_AFM_SUBPOOL_OVERHEAD(option, sz, nr) (_KAL_CC_AFM_POOLSIZE_PARTITION((option), (sz), (nr)))

/*******************************   EXTERN API  ********************************/
extern void kalcc_afm_create( void *mem_addr, kal_uint32 size, kal_uint32 subpool_nr);

/*************************************************************************
* FUNCTION
*  kalcc_retrivev_mb_statistic
*
* DESCRIPTION
*  Retrieve specific CC AFM buffer statistic
*
* PARAMETERS
*  1. [IN]) Buffer pointer to be tracked.
*  2. [OUT] CC AFM memory block statistic pointer for return
*
* RETURNS
*
* IMPLEMENTATION FLAVORS
*   N/A
*
*************************************************************************/
extern void kalcc_retrivev_mb_statistic(CC_AFM_MB_HEAD_T *afm_mb, CC_AFM_MB_STAT_T **afm_mb_stat);


/*************************************************************************
* FUNCTION
*  kalcc_retrivev_last_history_node
*
* DESCRIPTION
*  Retrieve last history from specific CC AFM buffer statistic
*
* PARAMETERS
*  1. [IN] CC AFM memory block statistic pointer 
*  2. [OUT] the ponter of the last histody node in statistic
*
* RETURNS
*  history node
*
* IMPLEMENTATION FLAVORS
*   N/A
*
*************************************************************************/
extern void kalcc_retrivev_last_history_node(CC_AFM_MB_STAT_T *afm_mb_stat, CC_AFM_MB_HISROTY_T *afm_mb_his);


/*************************************************************************
* FUNCTION
*  kalcc_retrieve_top_allocater
*
* DESCRIPTION
*  Retrieve specific CC AFM pool top 3 allocater
*
* PARAMETERS
*  1. [IN] CC AFM pool pointer
*  2. [OUT] the ponter of the top 3 operator node in statistic
*
* RETURNS
*
* IMPLEMENTATION FLAVORS
*   N/A
*
*************************************************************************/
extern void kalcc_retrieve_top_allocater(CC_AFM_POOL_CB_T *afm_pool, CC_AFM_POOL_TOP3_OPERATOR *operator);


#endif   /* _KAL_CC_AFM_H */
