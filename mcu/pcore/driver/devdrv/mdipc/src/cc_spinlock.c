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
 *   cc_spinlock.c
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This Module defines CC spinlock(only for MD1<->MD3).
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* This file only support MD3 */
#if defined(__CDMA2000_RAT__)/*_MD3_SUPPORT_*/
/* below for MD3 -------------------------------------------------- */ 
#include "spinlock.h"
#include "cc_irq_adaptation.h"

/* for start to own the spinlock timing check*/
//#define CC_SPINLOCK_TIMING_DEBUG

typedef enum {
    L1CORE = 0x11UL,
    PSCORE = 0x22UL,
    MD3 = 0x33UL
} CC_SPINLOCK_OWNER;

typedef enum {
    L1_MD3_32K = 0x113300UL,	
    PS_MD3 = 0x223300UL
} CC_SPINLOCK_DIRECTION;

typedef struct
{
   kal_uint32 owner;
   kal_uint32 caller_LR;
#if defined(CC_SPINLOCK_TIMING_DEBUG)   
   kal_uint32 start_us;/* the value is us counter *//* the time start to get spinlock */   
   kal_uint32 take_us;/* the value is us counter *//* the time own the spinlock */
#endif   
   /* when give up spinlock, we would check the duration smaller than 60 Qbit, so we don't record the time of give up spinlock. */    
} CC_SPINLOCK_LOG_T;

#if defined(__PCORE__)
/* the spinlock for PScore & MD3 */
CC_SPINLOCK_T cc_ps_md3_spinlock;
CC_SPINLOCK_LOG_T *cc_spinlock_ps_md3_log;
#else/* L1CORE */
/* the spinlock for L1core & MD3 32k-Less */
CC_SPINLOCK_T cc_l1_md3_32k_spinlock;
CC_SPINLOCK_LOG_T *cc_spinlock_l1_md3_32k_log;
#endif

/*------------------------------------------------------------------------
 * cc_spinlockid    cc_spin_create_spinlock
 * Purpose:	Get the pointer of spinlock for "PS2MD3_SPINLOCK"(spinlock for PScore & MD3) or "L12MD3_32K_SPINLOCK"(spinlock for L1core & MD3 32K-Less). 
 * Parameters:
 *    Input:	kal_char *lock_name: The name of spinlock, only could be "PS2MD3_SPINLOCK" or "L12MD3_32K_SPINLOCK" now.
 *              
 *    Output:	None
 * returns :	cc_spinlockid: the pointer of spinlock
 * Note    :    This function could get the pointer of spinlock for "PS2MD3_SPINLOCK" or "L12MD3_32K_SPINLOCK".
 *              The function could be called many times with same "lock_name".
 *              The pointer would be use in "cc_spin_take_spinlock" and "cc_spin_give_spinlock".
 *------------------------------------------------------------------------
 */
cc_spinlockid cc_spin_create_spinlock(kal_char *lock_name)
{

    CC_SPINLOCK_T *cc_spinlock_p;
    kal_uint32 caller_LR;

    GET_RETURN_ADDRESS(caller_LR);

    if (!CC_IRQ_MD3_IS_EXIST())/* If there is no MD3, fatatl error */
    {       
        kal_fatal_error_handler(KAL_ERROR_C2K_IS_NOT_SUPPORT, caller_LR);
    }

#if defined(__PCORE__)
	/* spinlock for PScore & MD3 */
    if(kal_mem_cmp(lock_name, "PS2MD3_SPINLOCK", sizeof(lock_name))==0)
    {
        cc_spinlock_p = &cc_ps_md3_spinlock;
        cc_spinlock_p->spinlock_p = (spinlock_t *)cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_PS2MD3_SPINLOCK, sizeof(spinlock_t));
		
        /* spinlock_init() would clear lock to 0. Due to MD1 and MD3 didn't sync to scheduler, we can't clear clock to 0 by MD1 or MD3.(It may race condition.)
          Fortunately, the lock is on MD1 and MD3 share memory and it would clear to 0 by AP, we trust AP side... */
        //spinlock_init((spinlock_t * )cc_spinlock_p->spinlock_p);
        cc_spinlock_p->direction = PS_MD3;         

        cc_spinlock_ps_md3_log = (CC_SPINLOCK_LOG_T *)cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_PS2MD3_SPINLOCK_LOG, sizeof(CC_SPINLOCK_LOG_T));
    }
#else/* L1CORE */
	/* spinlock for L1core & MD3 */
    if(kal_mem_cmp(lock_name, "L12MD3_32K_SPINLOCK", sizeof(lock_name))==0)
    {
        cc_spinlock_p = &cc_l1_md3_32k_spinlock;    
        cc_spinlock_p->spinlock_p = (spinlock_t *)cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_L12MD3_32K_SPINLOCK, sizeof(spinlock_t));

        /* spinlock_init() would clear lock to 0. Due to MD1 and MD3 didn't sync to scheduler, we can't clear clock to 0 by MD1 or MD3.(It may race condition.)
          Fortunately, the lock is on MD1 and MD3 share memory and it would clear to 0 by AP, we trust AP side... */
        //spinlock_init((spinlock_t * )cc_spinlock_p->spinlock_p);		
        cc_spinlock_p->direction = L1_MD3_32K;		  

        cc_spinlock_l1_md3_32k_log = (CC_SPINLOCK_LOG_T *)cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_L12MD3_32K_SPINLOCK_LOG, sizeof(CC_SPINLOCK_LOG_T));		
    }
#endif
    else
    {/* the spinlock is not support */
        EXT_ASSERT(0, caller_LR, 0, 0);
    }

    return cc_spinlock_p;

}

/*------------------------------------------------------------------------
 * kal_status    cc_spin_take_spinlock
 * Purpose:	Take the spinlock for "PS2MD3_SPINLOCK"(spinlock for PScore & MD3) or "L12MD3_32K_SPINLOCK"(spinlock for L1core & MD3 32K-Less). 
 * Parameters:
 *    Input:	cc_spinlockid ext_spinlock_id_ptr: The spinlock pointer of "PS2MD3_SPINLOCK" or "L12MD3_32K_SPINLOCK".
 *              kal_wait_mode wait_mode: KAL_INFINITE_WAIT/KAL_NO_WAIT .
 *    Output:	None
 * returns :	KAL_SUCCESS: get the spinlock successfully.
 *              KAL_SPINLOCK_NOT_AVAILABLE: spinlock not available  
 * Note    :    This function would take the spinlock for "PS2MD3_SPINLOCK" or "L12MD3_32K_SPINLOCK".
 *              User must not take same spinlock more than 1 times.
 *              
 *------------------------------------------------------------------------
 */
kal_status cc_spin_take_spinlock(cc_spinlockid ext_spinlock_id_ptr, kal_wait_mode wait_mode)
{
    kal_uint32 caller_LR;
    kal_bool  success = 0;
    CC_SPINLOCK_LOG_T *cc_spinlock_log = NULL;
    kal_uint32 owner = 0;	
	
    GET_RETURN_ADDRESS(caller_LR);

    /* we don't check whether MD3 exist or not due to it would be check in cc_spin_create_spinlock() */

    if(ext_spinlock_id_ptr == NULL )
    {/* the pointer of spinlock is error */
        EXT_ASSERT(0, caller_LR, 0, 0);    
    }

#if defined(__PCORE__)
    if(ext_spinlock_id_ptr->direction == PS_MD3)
    {
        cc_spinlock_log = cc_spinlock_ps_md3_log;
        owner = PSCORE;
    }
#else/* L1CORE */	
    if(ext_spinlock_id_ptr->direction == L1_MD3_32K)
    {
        cc_spinlock_log = cc_spinlock_l1_md3_32k_log;
        owner = L1CORE;		
    }	
#endif	
    else
    {/* this spinlock is not init yet */
        EXT_ASSERT(0, caller_LR, 0, 0);    
    }

    if(cc_spinlock_log->owner == owner)
    {/* Same core could not take same spinlock more than 1 times */
        EXT_ASSERT(0, caller_LR, 0, 0);  		
    }

#if defined(CC_SPINLOCK_TIMING_DEBUG)
    cc_spinlock_log->start_us = CC_IRQ_GET_US(); /* open when debugging */
#endif

    if(wait_mode == KAL_INFINITE_WAIT)
    {
        ext_spinlock_id_ptr->irq_status = spin_lock( (spinlock_t * )(ext_spinlock_id_ptr->spinlock_p) );
        success = 1;		
    }
    else if(wait_mode == KAL_NO_WAIT)
    {
        //EXT_ASSERT(0, caller_LR, 0, 0);/* due to we have no time to test and no user request, it is not support now. */		
        ext_spinlock_id_ptr->irq_status = spin_trylock( (spinlock_t * )(ext_spinlock_id_ptr->spinlock_p), &success ); 
		/* success may be 0 or 1 */
    }	

    if(success == 1)/* get spinlock */
    {/* Note: it means we get the spinlock and the IRQ is disable now. we shouldn't do too many things. Here is for logging. */
        cc_spinlock_log->owner = owner;     
        cc_spinlock_log->caller_LR = caller_LR;

#if defined(CC_SPINLOCK_TIMING_DEBUG)		
        cc_spinlock_log->take_us = CC_IRQ_GET_US(); /* open when debugging */
#endif
		
        return KAL_SUCCESS;
    }
    else/* no spinlock */
    {
        return KAL_SPINLOCK_NOT_AVAILABLE;   
    }

}

/*------------------------------------------------------------------------
 * void    cc_spin_give_spinlock
 * Purpose:	Give up the spinlock for "PS2MD3_SPINLOCK"(spinlock for PScore & MD3) or "L12MD3_32K_SPINLOCK"(spinlock for L1core & MD3 32K-Less). 
 * Parameters:
 *    Input:	cc_spinlockid ext_spinlock_id_ptr: The spinlock pointer of "PS2MD3_SPINLOCK" or "L12MD3_32K_SPINLOCK".
 *              
 *    Output:	None
 * returns :	None
 * Note    :    This function would give up the spinlock for "PS2MD3_SPINLOCK" or "L12MD3_32K_SPINLOCK".
 *              Only the spinlock owner could give up spinlock.
 *              
 *------------------------------------------------------------------------
 */
void cc_spin_give_spinlock(cc_spinlockid ext_spinlock_id_ptr)
{
    kal_uint32 giver_LR;
    CC_SPINLOCK_LOG_T *cc_spinlock_log = NULL;
    kal_uint32 owner = 0;	
	
    GET_RETURN_ADDRESS(giver_LR);

    /* we don't check whether MD3 exist or not due to it would be check in cc_spin_create_spinlock() */

    if(ext_spinlock_id_ptr == NULL )
    {/* the pointer of spinlock is error */
        EXT_ASSERT(0, giver_LR, 0, 0);    
    }

#if defined(__PCORE__)
    if(ext_spinlock_id_ptr->direction == PS_MD3)
    {
        cc_spinlock_log = cc_spinlock_ps_md3_log;
        owner = PSCORE;
    }
#else/* L1CORE */	
    if(ext_spinlock_id_ptr->direction == L1_MD3_32K)
    {
        cc_spinlock_log = cc_spinlock_l1_md3_32k_log;
        owner = L1CORE;		
    }
#endif	
    else
    {/* this spinlock is not init yet */
        EXT_ASSERT(0, giver_LR, 0, 0);    
    }

    if(cc_spinlock_log->owner == owner)/* Only the spinlock owner could give up spinlock. */
    {
        cc_spinlock_log->owner = 0;    
        spin_unlock((spinlock_t * )(ext_spinlock_id_ptr->spinlock_p), ext_spinlock_id_ptr->irq_status);		
    }
    else
    {/* only the owner could give up spinlock */
        EXT_ASSERT(0, giver_LR, cc_spinlock_log->owner, owner);    
    }    

}

/* up for MD3    -------------------------------------------------- */
#endif/*_MD3_SUPPORT_*/
