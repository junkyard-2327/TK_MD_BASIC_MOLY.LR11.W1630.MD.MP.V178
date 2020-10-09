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
 *   cc_irq_it.c
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   CC IRQ IT.
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
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "cc_irq_public.h"
#include "cc_irq_int.h"
#include "cc_irq_adaptation.h"
#include "intrCtrl.h"
#include "cc_sys_comm_public.h"
#include "cache_util.h"

#include <stdlib.h>
#if defined(CC_IRQ_IT)
/* select test*/
/*Note: this file isn't pass in JADE due to there is no basic load in JADE.
There are many task running in "MT6755_SP(LWCTG1_MODEM).mak", so this IT can not pass.
*/
//#define CC_SYS_COMM_UT
#define CC_BUFF_UT
#define __CC_IRQ_ON_PCCIF__


/*****************************************************************************
 * Type Definition                                                           *
 *****************************************************************************/
#if defined(__PCORE__)||defined(__L1CORE__)
#define CC_IRQ_UT_COMMON_CHANNEL_NUMBER          8/*((CC_IRQ_TX_MD1_CHANNEL_NUMBER > CC_IRQ_RX_MD1_CHANNEL_NUMBER)?CC_IRQ_TX_MD1_CHANNEL_NUMBER:CC_IRQ_RX_MD1_CHANNEL_NUMBER)*/
#endif

#if defined(__PCORE__)
#define CC_IRQ_UT_RX_IRQ_SHIFT    CC_IRQ_L2P_BASE
#define CC_IRQ_UT_TX_IRQ_SHIFT    CC_IRQ_P2L_BASE	
#define CC_SYS_UT_RX_COMM_SHIFT   CC_SYS_COMM_L2P_BASE
#elif defined(__L1CORE__)
#define CC_IRQ_UT_RX_IRQ_SHIFT    CC_IRQ_P2L_BASE
#define CC_IRQ_UT_TX_IRQ_SHIFT    CC_IRQ_L2P_BASE
#define CC_SYS_UT_RX_COMM_SHIFT   CC_SYS_COMM_P2L_BASE
#else
#error "DEFINE ERROR"
#endif

#define CC_IRQ_INTSRAM_ZI    __attribute__ ((zero_init, section ("INTSRAM_ZI")))
#define LockIRQ()                    SaveAndSetIRQMask()
#define RestoreIRQ(mask)             RestoreIRQMask(mask)
/*****************************************************************************
 * Data Declaration                                                          *
 *****************************************************************************/
typedef struct {
    kal_uint32 md32_to_cr4_test_start;
    kal_uint32 md32_to_cr4_test_end;
    kal_uint32 cr4_to_md32_test_start;
    kal_uint32 cr4_to_md32_test_end;    
    kal_uint32 share_para1;
    kal_uint32 share_para2;
    kal_uint32 share_para3;
    kal_uint32 share_para1_arr[CC_IRQ_MAX_CHANNEL];
    kal_uint32 share_para2_arr[CC_IRQ_MAX_CHANNEL];
    kal_uint32 share_para3_arr[CC_IRQ_MAX_CHANNEL];
    kal_uint32 cr4_to_md32_unmask_enable;
    kal_uint32 md32_to_cr4_unmask_enable;
    kal_int32 cr4_to_md32_tx_notify;/*dir1_tx_notify*/
    kal_int32 md32_to_cr4_tx_notify;/*dir2_tx_notify*/
} cc_irq_it_share_t;
DEFINE_NC_SHARED_VAR(volatile cc_irq_it_share_t, cc_irq_share_var)
DECLARE_SHARED_VAR(volatile CC_IRQ_SHARE_MEM_T, cc_irq_l12ps_share_data)
DECLARE_SHARED_VAR(volatile CC_IRQ_SHARE_MEM_T, cc_irq_ps2l1_share_data)
static kal_uint32 cc_irq_test_case = 0;
static kal_uint32 cc_irq_it_1_magic[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
static kal_uint32 cc_irq_it_2_magic[CC_IRQ_UT_COMMON_CHANNEL_NUMBER][CC_IRQ_PARA_NUMBER];
static kal_uint32 cc_irq_it_seq[CC_IRQ_PARA_NUMBER];
static kal_uint32 cc_irq_it_2_seq[CC_IRQ_UT_COMMON_CHANNEL_NUMBER][CC_IRQ_PARA_NUMBER];
static kal_uint32 cc_irq_index[CC_IRQ_RX_MD1_CHANNEL_NUMBER] = {CC_IRQ_IRQ_CODE};
static volatile kal_uint32 test_done = 0;
static kal_uint32 tx_seq = 0;
volatile static kal_int32 next_rx_index;    //- test case 8
static kal_uint32 cc_irq_test_case_SYS_END = 0;

static kal_uint32 cc_irq_ut_buff_test = 0;     
static kal_uint32 cc_irq_test_case_BUFF_END = 0;



/* variable for msg time profile */
CC_IRQ_INTSRAM_ZI kal_uint32 msg_time_profile_proc_start_tx;
CC_IRQ_INTSRAM_ZI kal_uint32 msg_time_profile_proc_return_from_tx;
CC_IRQ_INTSRAM_ZI kal_uint32 msg_time_profile_proc_rx_lisr;
CC_IRQ_INTSRAM_ZI kal_uint32 msg_time_profile_proc_rx_start_rx;
CC_IRQ_INTSRAM_ZI kal_uint32 msg_time_profile_proc_rx_return_from_tx_ilm;
kal_uint32 msg_time_record_tx_max[4];
kal_uint32 msg_time_record_rx_max[4];

/*****************************************************************************
 * Internal Definition                                                       *
 *****************************************************************************/
#define CC_IRQ_UNMASK_IRQ    0
#define CC_IRQ_NO_UNMASK_IRQ    1
#define CC_IRQ_WAIT_TEST_DONE   0
#define CC_IRQ_NO_WAIT_TEST_DONE   1
#define CC_IRQ_TX_SEQ_MAX    0xFFFF
#define CC_IRQ_STRESS_IRQ_mask_state_cc_irq    0
#define CC_IRQ_STRESS_IRQ_UNmask_state_cc_irq    1
#define CC_IRQ_TEST_SEQ_MAX        (0xFFFF)
#define CC_IRQ_RANDOM_TEST_OP_PERIOD_US    0x4000

//- TEST STATUS
enum {
    CC_IRQ_TEST_STATUS_ENABLE = 1,
    CC_IRQ_TEST_STATUS_DISABLE = 2,
    CC_IRQ_WAIT_TX_SEND = 3,
    CC_IRQ_WAIT_TX_SEND_ACK = 4,
    CC_IRQ_WAIT_TX_MAX
} ;

//- Test Items for PARA and Buffer mode
enum {
    CC_IRQ_UT_L12PS_WAIT_RESP = 1,
    CC_IRQ_UT_PS2L1_WAIT_RESP,/*2*/
    CC_IRQ_UT_L12PS_MUL_SRC,/*3*/
    CC_IRQ_UT_PS2L1_MUL_SRC,/*4*/
    CC_IRQ_UT_L12PS_NESTED_TRIGGER,/*5*/
    CC_IRQ_UT_PS2L1_NESTED_TRIGGER,/*6*/
    CC_IRQ_UT_L12PS_PREEMPT_TEST,/*7*/
    CC_IRQ_UT_PS2L1_PREEMPT_TEST,/*8*/
    CC_IRQ_UT_RANDOMD_TEST,/*9*/
/*test for Buffer mode*/    
    CC_IRQ_UT_L12PS_BUFF_BASIC_TEST = 200,
    CC_IRQ_UT_PS2L1_BUFF_BASIC_TEST,/*201*/
    CC_IRQ_UT_L12PS_BUFF_BASIC_TEST_NO_ACK,/*202*/
    CC_IRQ_UT_PS2L1_BUFF_BASIC_TEST_NO_ACK,/*203*/
    CC_IRQ_UT_L12PS_BUFF_VAR_LEN,/*204*/
    CC_IRQ_UT_PS2L1_BUFF_VAR_LEN,/*205*/
    CC_IRQ_UT_L12PS_BUFF_VAR_LEN_NO_ACK,/*206*/
    CC_IRQ_UT_PS2L1_BUFF_VAR_LEN_NO_ACK,/*207*/
#if defined(__CC_IRQ_ON_PCCIF__)
    CC_IRQ_UT_L12PS_BUFF_PCCIF_WRAP,
    CC_IRQ_UT_PS2L1_BUFF_PCCIF_WRAP,
    CC_IRQ_UT_L12PS_BUFF_PCCIF_COMB,
    CC_IRQ_UT_PS2L1_BUFF_PCCIF_COMB,
#endif
/*test for CC SYS */
    CC_IRQ_SYS_COMM_UT_L12PS_BASIC = 300,
    CC_IRQ_SYS_COMM_UT_PS2L1_BASIC,
    CC_IRQ_SYS_COMM_UT_L12PS_BASIC_POLLING,
    CC_IRQ_SYS_COMM_UT_PS2L1_BASIC_POLLING,
    CC_IRQ_SYS_COMM_UT_L12PS_MASK,
    CC_IRQ_SYS_COMM_UT_PS2L1_MASK,
};

void cc_irq_ut_buff_isr(kal_uint32 index, kal_uint32 addr, kal_uint32 length, kal_uint32 no_use);
static void cc_irq_it_isr(kal_uint32 irq_index, kal_uint32 para1, kal_uint32 para2, kal_uint32 para3);
void cc_irq_ut_set_pri(kal_uint32 cc_irq_id, kal_uint32 pri);
static void cc_irq_it_cb(kal_uint32 para1, kal_uint32 para2, kal_uint32 para3);
static void test_item_init(kal_uint32 test_case, kal_uint32 unmask_irq);
static void test_item_deinit(kal_uint32 test_case);
void cc_irq_basic_test_rx();
void cc_irq_basic_test_tx();
void cc_irq_multi_test_tx();
void cc_irq_multi_test_rx();
void cc_irq_trans_max_test_rx();
void cc_irq_trans_max_test_tx();
void cc_irq_pri_test_rx();
void cc_irq_pri_test_tx();
/*****************************************************************************
 * External definition                                                       *
 *****************************************************************************/
void cc_irq_it()
{
    kal_uint32 i, j;

    //- disable all interrupt to avoid bother by other one 
    for(i = 0; i < 128; i++)
    {
        IRQMask(i);            
    }
	//- If the other core still use CC IRQ before entering idle task, we should open it
    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        IRQUnmask(cc_irq_index[i]);            
    }


#if defined(CC_SYS_COMM_UT)/* define for test CC SYS IRQ */
extern void cc_irq_sys_comm_ut();
    cc_irq_sys_comm_ut();
#endif

 /* due to there is CC SYS SYNC between MD1 and MD3 we bypass CC SYS IRQ in below test */

    //- Initialization
    for(i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        ASSERT(CC_IRQ_SUCCESS == cc_irq_register_callback(i+CC_IRQ_UT_RX_IRQ_SHIFT, cc_irq_it_cb));
        IRQMask(cc_irq_index[i]);            
    }

    /* set priority */
    for (i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        cc_irq_ut_set_pri(cc_irq_index[i], i);
    }
        
    for (i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        cc_irq_it_1_magic[i] = 0x5AF00000 | (i << 16);    //- [15:0] is reserved for sequence number;
        for (j = 0; j < 3; j++)
        {
            cc_irq_it_2_magic[i][j] = 0xFF000000 | (i << 20) | (j << 16);    //- [15:0] is reserved for sequence number;
        }
    }

#if defined(CC_BUFF_UT)/* define for test buffer mode */
extern void cc_irq_buff_test();
    cc_irq_buff_test();
#endif

/* default for test para mode */
    //- Test 1 - L1CORE triggers interrupt (same source) to PCORE and wait process done.
    cc_irq_test_case = CC_IRQ_UT_L12PS_WAIT_RESP;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_basic_test_rx();
#else
    cc_irq_basic_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - PCORE triggers interrupt (same source) to L1CORE and wait process done.
    cc_irq_test_case = CC_IRQ_UT_PS2L1_WAIT_RESP;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_basic_test_tx();
#else
    cc_irq_basic_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);
    
    //- Test 3 - L1CORE triggers interrupt to PCORE with multiple sources interleaved.
    cc_irq_test_case = CC_IRQ_UT_L12PS_MUL_SRC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_multi_test_rx();
#else
    cc_irq_multi_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 4 - PCORE triggers interrupt to L1CORE with multiple sources interleaved.
    cc_irq_test_case = CC_IRQ_UT_PS2L1_MUL_SRC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_multi_test_tx();
#else
    cc_irq_multi_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 5 - L1CORE triggers interrupt to PCORE with nested trigger count being max and check behavior.
    cc_irq_test_case = CC_IRQ_UT_L12PS_NESTED_TRIGGER;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);    
#if defined(__PCORE__)
    cc_irq_trans_max_test_rx();
#else
    cc_irq_trans_max_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 6 - PCORE triggers interrupt to L1CORE with nested trigger count being max and check behavior.
    cc_irq_test_case = CC_IRQ_UT_PS2L1_NESTED_TRIGGER;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_trans_max_test_tx();
#else
    cc_irq_trans_max_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 7 - L1CORE trigger CC IRQ with lowest priority, wait PCORE ack, then trigger higher priority
    //- Be sure that CC IRQ with larger index has lower priority.
    cc_irq_test_case = CC_IRQ_UT_L12PS_PREEMPT_TEST;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_pri_test_rx();
#else
    cc_irq_pri_test_tx();
#endif    
    test_item_deinit(cc_irq_test_case);    
    
    //- Test 8 - PCORE trigger CC IRQ with lowest priority, wait L1CORE ack, then trigger higher priority
    //- Be sure that CC IRQ with larger index has lower priority.
    cc_irq_test_case = CC_IRQ_UT_PS2L1_PREEMPT_TEST;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_pri_test_tx();
#else
    cc_irq_pri_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

}


/*****************************************************************************
 * Internal Function                                                         *
 *****************************************************************************/
static void cc_irq_it_isr(kal_uint32 irq_index, kal_uint32 para1, kal_uint32 para2, kal_uint32 para3)
{
    kal_uint32 correct_seq_1, correct_seq_2, correct_seq_3;
    kal_uint32 i, j, savedMask;
    
    switch (cc_irq_test_case)
    {
#if defined(__L1CORE__)
    case CC_IRQ_UT_PS2L1_WAIT_RESP:
#elif defined(__PCORE__)
    case CC_IRQ_UT_L12PS_WAIT_RESP:
#endif
        {
            //- test case 1 will only receive irq from index 1
            if (irq_index != 1)
                ASSERT(0);

            correct_seq_1 = cc_irq_it_1_magic[0] | cc_irq_it_seq[0];
            correct_seq_2 = cc_irq_it_1_magic[1] | cc_irq_it_seq[1];
            correct_seq_3 = cc_irq_it_1_magic[2] | cc_irq_it_seq[2];

            if (correct_seq_1 != para1 || correct_seq_2 != para2 || correct_seq_3 != para3)
            {
                EXT_ASSERT(0, para1, para2, para3);
            }

            cc_irq_it_seq[0]++;
            cc_irq_it_seq[1]++;
            cc_irq_it_seq[2]++;
            
            //- write parameter to share memory 
            SHARED_VAR(cc_irq_share_var).share_para1 = para1;
            SHARED_VAR(cc_irq_share_var).share_para2 = para2;
            SHARED_VAR(cc_irq_share_var).share_para3 = para3;

            CC_IRQ_DMB();
            
            if (cc_irq_it_seq[0] == CC_IRQ_TX_SEQ_MAX &&
                cc_irq_it_seq[1] == CC_IRQ_TX_SEQ_MAX &&
                cc_irq_it_seq[2] == CC_IRQ_TX_SEQ_MAX )
            {
                test_done = 1;
            }
        }
        break;
#if defined(__L1CORE__)
    case CC_IRQ_UT_PS2L1_MUL_SRC:
#elif defined(__PCORE__)
    case CC_IRQ_UT_L12PS_MUL_SRC:
#endif
        {
            correct_seq_1 = cc_irq_it_2_magic[irq_index][0] | cc_irq_it_2_seq[irq_index][0];
            correct_seq_2 = cc_irq_it_2_magic[irq_index][1] | cc_irq_it_2_seq[irq_index][1];
            correct_seq_3 = cc_irq_it_2_magic[irq_index][2] | cc_irq_it_2_seq[irq_index][2];

            if (correct_seq_1 != para1 || correct_seq_2 != para2 || correct_seq_3 != para3)
            {
                EXT_ASSERT(0, para1, para2, para3);
            }
            
            cc_irq_it_2_seq[irq_index][0]++;
            cc_irq_it_2_seq[irq_index][1]++;
            cc_irq_it_2_seq[irq_index][2]++;
            
            SHARED_VAR(cc_irq_share_var).share_para1_arr[irq_index] = para1;
            SHARED_VAR(cc_irq_share_var).share_para2_arr[irq_index] = para2;
            SHARED_VAR(cc_irq_share_var).share_para3_arr[irq_index] = para3;

            CC_IRQ_DMB();

            savedMask = SaveAndSetIRQMask();
            
            test_done = 1;
            for (i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                for (j = 0; j < CC_IRQ_PARA_NUMBER; j++)
                {
                    if (cc_irq_it_2_seq[i][j] != CC_IRQ_TX_SEQ_MAX)
                    {
                        test_done = 0;
                        break;
                    }
                }

                if(test_done == 0)
                    break;
            }

            RestoreIRQMask(savedMask);
        }
        break;
#if defined(__L1CORE__)
    case CC_IRQ_UT_PS2L1_NESTED_TRIGGER:
#elif defined(__PCORE__)
    case CC_IRQ_UT_L12PS_NESTED_TRIGGER:
#endif
        {
            correct_seq_1 = cc_irq_it_2_magic[irq_index][0] | cc_irq_it_2_seq[irq_index][0];
            correct_seq_2 = cc_irq_it_2_magic[irq_index][1] | cc_irq_it_2_seq[irq_index][1];
            correct_seq_3 = cc_irq_it_2_magic[irq_index][2] | cc_irq_it_2_seq[irq_index][2];

            if (correct_seq_1 != para1 || correct_seq_2 != para2 || correct_seq_3 != para3)
            {
                EXT_ASSERT(0, para1, para2, para3);
            }

            cc_irq_it_2_seq[irq_index][0]++;
            cc_irq_it_2_seq[irq_index][1]++;
            cc_irq_it_2_seq[irq_index][2]++;

            savedMask = SaveAndSetIRQMask();
        
            test_done = 1;
            for (i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                for (j = 0; j < CC_IRQ_PARA_NUMBER; j++)
                {
                    if (cc_irq_it_2_seq[i][j] != CC_IRQ_NESTED_TRIGGER_MAX - 1)
                    {
                        test_done = 0;
                        break;
                    }
                }
        
                if(test_done == 0)
                    break;
            }
        
            RestoreIRQMask(savedMask);
        }
        break;
#if defined(__PCORE__)
    case CC_IRQ_UT_L12PS_PREEMPT_TEST:
#elif defined(__L1CORE__)
    case CC_IRQ_UT_PS2L1_PREEMPT_TEST:
#endif
        {
           if (irq_index != next_rx_index)
                EXT_ASSERT(0, irq_index, next_rx_index, 0);
            
            correct_seq_1 = cc_irq_it_2_magic[irq_index][0] | cc_irq_it_2_seq[irq_index][0];
            correct_seq_2 = cc_irq_it_2_magic[irq_index][1] | cc_irq_it_2_seq[irq_index][1];
            correct_seq_3 = cc_irq_it_2_magic[irq_index][2] | cc_irq_it_2_seq[irq_index][2];
            
            if (correct_seq_1 != para1 || correct_seq_2 != para2 || correct_seq_3 != para3)
            {
                EXT_ASSERT(0, para1, para2, para3);
            }
            
            //- unmask higher priority CC IRQ.
            next_rx_index--;            
            
            //- notify another core to trigger next CC IRQ.
#if defined(__PCORE__)
            SHARED_VAR(cc_irq_share_var).cr4_to_md32_tx_notify--;
#else
            SHARED_VAR(cc_irq_share_var).md32_to_cr4_tx_notify--;
#endif
            if(next_rx_index-1>=0)
            ASSERT(CC_IRQ_SUCCESS==cc_irq_unmask(CC_IRQ_UT_RX_IRQ_SHIFT+next_rx_index));

            while(next_rx_index-1 >= 0);
            test_done = 1;            
        }
        break;
    case CC_IRQ_UT_RANDOMD_TEST:
        {
            correct_seq_1 = cc_irq_it_2_magic[irq_index][0] | cc_irq_it_2_seq[irq_index][0];
            correct_seq_2 = cc_irq_it_2_magic[irq_index][1] | cc_irq_it_2_seq[irq_index][1];
            correct_seq_3 = cc_irq_it_2_magic[irq_index][2] | cc_irq_it_2_seq[irq_index][2];

            if (correct_seq_1 != para1 || correct_seq_2 != para2 || correct_seq_3 != para3)
            {
                EXT_ASSERT(0, para1, para2, para3);
            }
        
            cc_irq_it_2_seq[irq_index][0] = (cc_irq_it_2_seq[irq_index][0] + 1) % (CC_IRQ_TEST_SEQ_MAX + 1);
            cc_irq_it_2_seq[irq_index][1] = (cc_irq_it_2_seq[irq_index][1] + 1) % (CC_IRQ_TEST_SEQ_MAX + 1);
            cc_irq_it_2_seq[irq_index][2] = (cc_irq_it_2_seq[irq_index][2] + 1) % (CC_IRQ_TEST_SEQ_MAX + 1);
        }
        break;
    default:
        ASSERT(0);
    }
}

static void cc_irq_it_cb(kal_uint32 para1, kal_uint32 para2, kal_uint32 para3)
{
    kal_uint32 irq_code, index;

    irq_code = IRQ_Current_LISR();

    for(index = 1; index < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; index++)
    {
        if (irq_code == cc_irq_index[index])
        {
#if defined(CC_BUFF_UT)        
            if (cc_irq_ut_buff_test)
               {cc_irq_ut_buff_isr(index, para1, para2, para3);}
			else
#endif 			
               {cc_irq_it_isr(index, para1, para2, para3);}
        }
    }
}

static kal_uint32 get_free_space_by_channel(volatile CC_IRQ_SHARE_MEM_T *p_share, kal_uint32 cc_index_offset)
{
    kal_uint32 read_ptr, write_ptr;

    read_ptr = p_share->cc_irq_param_read_index[cc_index_offset];
    write_ptr = p_share->cc_irq_param_write_index[cc_index_offset];

    if (write_ptr >= read_ptr)
        return CC_IRQ_NESTED_TRIGGER_MAX - (write_ptr - read_ptr);
    else
        return read_ptr - write_ptr - 1;
}

static void test_item_init(kal_uint32 test_case, kal_uint32 unmask_irq)
{
    kal_uint32 i, j;
    
    test_done = 0;

#if defined(__L1CORE__)
    SHARED_VAR(cc_irq_share_var).md32_to_cr4_test_start = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(SHARED_VAR(cc_irq_share_var).cr4_to_md32_test_start != CC_IRQ_TEST_STATUS_ENABLE);
    SHARED_VAR(cc_irq_share_var).md32_to_cr4_test_end = CC_IRQ_TEST_STATUS_DISABLE;
    SHARED_VAR(cc_irq_share_var).md32_to_cr4_unmask_enable = 0;
    SHARED_VAR(cc_irq_share_var).md32_to_cr4_tx_notify = CC_IRQ_UT_COMMON_CHANNEL_NUMBER - 1;
    CC_IRQ_DMB();
#else
    SHARED_VAR(cc_irq_share_var).cr4_to_md32_test_start = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(SHARED_VAR(cc_irq_share_var).md32_to_cr4_test_start != CC_IRQ_TEST_STATUS_ENABLE);
    SHARED_VAR(cc_irq_share_var).cr4_to_md32_test_end = CC_IRQ_TEST_STATUS_DISABLE;
    SHARED_VAR(cc_irq_share_var).cr4_to_md32_unmask_enable = 0;
    SHARED_VAR(cc_irq_share_var).cr4_to_md32_tx_notify = CC_IRQ_UT_COMMON_CHANNEL_NUMBER - 1;
    CC_IRQ_DMB();
#endif
    
    tx_seq = 0;
    
    for (i = 0; i < CC_IRQ_PARA_NUMBER; i++)
    {
        cc_irq_it_seq[i] = 0;
        for(j = 0; j < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; j++)
        {
            cc_irq_it_2_seq[j][i] = 0;
        }
    }
    
    if (unmask_irq == CC_IRQ_UNMASK_IRQ)
    {
        for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
        {
            IRQUnmask(cc_irq_index[i]);
        }
    }
}

static void test_item_deinit(kal_uint32 test_case)
{
    kal_uint32 i, free_space_cnt;

    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        IRQMask(cc_irq_index[i]);
    }

#if defined(__L1CORE__)
    SHARED_VAR(cc_irq_share_var).md32_to_cr4_test_start = CC_IRQ_TEST_STATUS_DISABLE;
    SHARED_VAR(cc_irq_share_var).md32_to_cr4_test_end = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(SHARED_VAR(cc_irq_share_var).cr4_to_md32_test_end != CC_IRQ_TEST_STATUS_ENABLE);
#else
    SHARED_VAR(cc_irq_share_var).cr4_to_md32_test_start = CC_IRQ_TEST_STATUS_DISABLE;
    SHARED_VAR(cc_irq_share_var).cr4_to_md32_test_end = CC_IRQ_TEST_STATUS_ENABLE; 
    CC_IRQ_DMB();
    while(SHARED_VAR(cc_irq_share_var).md32_to_cr4_test_end != CC_IRQ_TEST_STATUS_ENABLE);
#endif

    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
#if defined(__L1CORE__)
        free_space_cnt = get_free_space_by_channel(SHARED_pVAR(cc_irq_l12ps_share_data), i);
#else
        free_space_cnt = get_free_space_by_channel(SHARED_pVAR(cc_irq_ps2l1_share_data), i);
#endif
        EXT_ASSERT(free_space_cnt == CC_IRQ_NESTED_TRIGGER_MAX, free_space_cnt, i, 0);
    }
}



/*****************************************************************************
 * Public Function                                                           *
 *****************************************************************************/
kal_uint32 cc_irq_test_init_done = 0;
kal_uint32 per_irq_tx_seq[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
kal_uint32 mask_state_cc_irq[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
kal_uint32 next_mask_process_time[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
kal_uint32 next_send_time_cc_irq[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
kal_uint32 cc_irq_prev_usc = 0;

kal_uint32 last_channel_full_time;

void cc_irq_random_test()
{
    kal_uint32 current_time, i, j;
    kal_int32  ret;
	
    current_time = CC_IRQ_GET_US();

    if (cc_irq_prev_usc > current_time)
    {
        for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
        {
            next_mask_process_time[i] = current_time + (rand() % CC_IRQ_RANDOM_TEST_OP_PERIOD_US);
            next_send_time_cc_irq[i] = current_time + (rand() % CC_IRQ_RANDOM_TEST_OP_PERIOD_US);
        }
    }
    cc_irq_prev_usc = current_time;    
    
    if (cc_irq_test_init_done == 0)
    {
        cc_irq_test_init_done = 1;
        
        for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
        {
            ASSERT(CC_IRQ_SUCCESS == cc_irq_register_callback(i, cc_irq_it_cb));
        }

        for (i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
        {
            cc_irq_it_1_magic[i] = 0x5AF00000 | (i << 16);    //- [15:0] is reserved for sequence number;
            for (j = 0; j < 3; j++)
            {
                cc_irq_it_2_magic[i][j] = 0xFF000000 | (i << 20) | (j << 16);    //- [15:0] is reserved for sequence number;
            }
        }

        
        for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
        {
            mask_state_cc_irq[i] = CC_IRQ_STRESS_IRQ_mask_state_cc_irq;
            next_mask_process_time[i] = current_time + (rand() % CC_IRQ_RANDOM_TEST_OP_PERIOD_US);
            next_send_time_cc_irq[i] = current_time + (rand() % CC_IRQ_RANDOM_TEST_OP_PERIOD_US);
        
            per_irq_tx_seq[i] = 0;
        }
        cc_irq_test_case = CC_IRQ_UT_RANDOMD_TEST;
        test_item_init(CC_IRQ_UT_RANDOMD_TEST, CC_IRQ_NO_UNMASK_IRQ);    
    }
    
    //- mask state process
    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        //- process mask state
        if (current_time > next_mask_process_time[i])
        {
            //- change mask state
            if (mask_state_cc_irq[i] == CC_IRQ_STRESS_IRQ_mask_state_cc_irq)
            {
                IRQUnmask(cc_irq_index[i]);
                mask_state_cc_irq[i] = CC_IRQ_STRESS_IRQ_UNmask_state_cc_irq;
            }
            else
            {
                IRQMask(cc_irq_index[i]);
                mask_state_cc_irq[i] = CC_IRQ_STRESS_IRQ_mask_state_cc_irq;
            }
            next_mask_process_time[i] = current_time + (rand() % CC_IRQ_RANDOM_TEST_OP_PERIOD_US);
        }

        //- process send
        if (current_time > next_send_time_cc_irq[i])
        {
#if defined(__L1CORE__)
            if (get_free_space_by_channel(SHARED_pVAR(cc_irq_l12ps_share_data), i) >= 1)
#else
            if (get_free_space_by_channel(SHARED_pVAR(cc_irq_ps2l1_share_data), i) >= 1)
#endif
            {
                ret = cc_irq_trigger_interrupt(CC_IRQ_UT_TX_IRQ_SHIFT+i, cc_irq_it_2_magic[i][0] | per_irq_tx_seq[i], cc_irq_it_2_magic[i][1] | per_irq_tx_seq[i], cc_irq_it_2_magic[i][2] | per_irq_tx_seq[i]);
                ASSERT(ret == CC_IRQ_SUCCESS);
                per_irq_tx_seq[i] = (per_irq_tx_seq[i] + 1) % (CC_IRQ_TEST_SEQ_MAX + 1);
            }
            else
            {
                last_channel_full_time = CC_IRQ_GET_US();
            }

            next_send_time_cc_irq[i] = current_time + (rand() % CC_IRQ_RANDOM_TEST_OP_PERIOD_US);
        }
    }
}

void cc_irq_basic_test_tx()
{
    while(tx_seq < CC_IRQ_TX_SEQ_MAX)
    {
        SHARED_VAR(cc_irq_share_var).share_para1 = 0;
        SHARED_VAR(cc_irq_share_var).share_para2 = 0;
        SHARED_VAR(cc_irq_share_var).share_para3 = 0;
    
        CC_IRQ_DMB();
    
        cc_irq_trigger_interrupt(CC_IRQ_UT_TX_IRQ_SHIFT+1, cc_irq_it_1_magic[0] | tx_seq, cc_irq_it_1_magic[1] | tx_seq, cc_irq_it_1_magic[2] | tx_seq);
        
        while(1)
        {
            if (SHARED_VAR(cc_irq_share_var).share_para1 == (cc_irq_it_1_magic[0] | tx_seq) && \
                SHARED_VAR(cc_irq_share_var).share_para2 == (cc_irq_it_1_magic[1] | tx_seq) && \
                SHARED_VAR(cc_irq_share_var).share_para3 == (cc_irq_it_1_magic[2] | tx_seq))
            {
                break;
            }
        }
            
        tx_seq++;
    }
}

void cc_irq_basic_test_rx()
{
    while (test_done == 0);
}

void cc_irq_multi_test_tx()
{
    kal_uint32 irq_respond[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
    kal_uint32 i, end_test_loop;
    kal_int32  ret;
    
    while(tx_seq < CC_IRQ_TX_SEQ_MAX)
    {
        for(i = 0; i < 3; i++)
        {
            SHARED_VAR(cc_irq_share_var).share_para1_arr[i] = 0;
            SHARED_VAR(cc_irq_share_var).share_para2_arr[i] = 0;
            SHARED_VAR(cc_irq_share_var).share_para3_arr[i] = 0;

            CC_IRQ_DMB();
        }
        for(i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
        {
            ret = cc_irq_trigger_interrupt(CC_IRQ_UT_TX_IRQ_SHIFT + i, cc_irq_it_2_magic[i][0] | tx_seq, cc_irq_it_2_magic[i][1] | tx_seq, cc_irq_it_2_magic[i][2] | tx_seq);

            ASSERT(ret == CC_IRQ_SUCCESS);
        }

        for(i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            irq_respond[i] = 0;

        end_test_loop = 0;
        while(end_test_loop == 0)
        {
            for(i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER;i++)
            {
                if (SHARED_VAR(cc_irq_share_var).share_para1_arr[i] == (cc_irq_it_2_magic[i][0] | tx_seq))
                    irq_respond[i] |= (1 << 0);
                if (SHARED_VAR(cc_irq_share_var).share_para2_arr[i] == (cc_irq_it_2_magic[i][1] | tx_seq))
                    irq_respond[i] |= (1 << 1);
                if (SHARED_VAR(cc_irq_share_var).share_para3_arr[i] == (cc_irq_it_2_magic[i][2] | tx_seq))
                    irq_respond[i] |= (1 << 2);
            }

            for(i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (irq_respond[i] != 7)
                    break;
            }

            if (i == CC_IRQ_UT_COMMON_CHANNEL_NUMBER)
                end_test_loop = 1;
        }
        
        tx_seq++;
    }
}

void cc_irq_multi_test_rx()
{
    while (test_done == 0);
}

void cc_irq_trans_max_test_tx()
{
    kal_uint32 i, free_space_cnt;
    kal_int32  ret;
	
    while(tx_seq < CC_IRQ_NESTED_TRIGGER_MAX - 1)
    {
        for(i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
        {
            ret = cc_irq_trigger_interrupt(CC_IRQ_UT_TX_IRQ_SHIFT+i, cc_irq_it_2_magic[i][0] | tx_seq, cc_irq_it_2_magic[i][1] | tx_seq, cc_irq_it_2_magic[i][2] | tx_seq);
            ASSERT(ret == CC_IRQ_SUCCESS);                    
        }
    
        tx_seq++;
    }

#if defined(__L1CORE__)
    //- notify PCORE to unmask irq and process.
    for(i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        free_space_cnt = get_free_space_by_channel(SHARED_pVAR(cc_irq_l12ps_share_data), i);
        EXT_ASSERT(free_space_cnt == 0, free_space_cnt, i, 0);
    }
    SHARED_VAR(cc_irq_share_var).md32_to_cr4_unmask_enable = 1;    
#else
    //- notify L1CORE to unmask irq and process.
    for(i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        free_space_cnt = get_free_space_by_channel(SHARED_pVAR(cc_irq_ps2l1_share_data), i);
        EXT_ASSERT(free_space_cnt == 0, free_space_cnt, i, 0);
    }
    SHARED_VAR(cc_irq_share_var).cr4_to_md32_unmask_enable = 1;
#endif
}

void cc_irq_trans_max_test_rx()
{
    kal_uint32 i;

#if defined(__L1CORE__)	
    //- wait for PCORE sends all packets
    while(SHARED_VAR(cc_irq_share_var).cr4_to_md32_unmask_enable == 0);
#else
    //- wait for L1CORE sends all packets
    while(SHARED_VAR(cc_irq_share_var).md32_to_cr4_unmask_enable == 0);
#endif

    //- unmask IRQs
    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        IRQUnmask(cc_irq_index[i]);
    }

    //- wait for all irq processed
    while(test_done == 0);
}

void cc_irq_pri_test_tx()
{
    kal_uint32 i, index;
    kal_int32  ret;
	
    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER-1; i++)
    {
        index = CC_IRQ_UT_COMMON_CHANNEL_NUMBER - 1 - i;
        
        ret = cc_irq_trigger_interrupt(CC_IRQ_UT_TX_IRQ_SHIFT+index, cc_irq_it_2_magic[index][0] | tx_seq, cc_irq_it_2_magic[index][1] | tx_seq, cc_irq_it_2_magic[index][2] | tx_seq);
        ASSERT(ret == CC_IRQ_SUCCESS);

    //- wait receiver core response
#if defined(__PCORE__)
        while(index == SHARED_VAR(cc_irq_share_var).md32_to_cr4_tx_notify);
#else
        while(index == SHARED_VAR(cc_irq_share_var).cr4_to_md32_tx_notify);
#endif
    }
}

void cc_irq_pri_test_rx()
{
    //- unmask IRQ high highest priority.
    next_rx_index = CC_IRQ_UT_COMMON_CHANNEL_NUMBER - 1;
    ASSERT(CC_IRQ_SUCCESS==cc_irq_unmask(CC_IRQ_UT_RX_IRQ_SHIFT+CC_IRQ_UT_COMMON_CHANNEL_NUMBER - 1));
    while(test_done == 0);
}

void cc_irq_ut_set_pri(kal_uint32 cc_irq_id, kal_uint32 pri)
{
    kal_uint32 reg_val, mask, off;
#if defined(MT6755)
    reg_val = *(volatile kal_uint32 *)(MDCIRQ_PRLV(cc_irq_id));
    off = (cc_irq_id % 4) * 8;
    mask = ~(0xFFUL << off);
    reg_val &= mask;
    reg_val |= (pri << off);
    *(volatile kal_uint32 *)(MDCIRQ_PRLV(cc_irq_id)) = reg_val;
#else
#error "unsupported chip"
#endif
}


/*****************************************************************************************
 CC SYS test
*****************************************************************************************/
kal_uint32 cc_sys_comm_test_channel;
static kal_uint32 const cc_sys_comm_ut_p2l_channel[] = {CC_SYS_COMM_P2L_IPC, CC_SYS_COMM_P2L_EVG, CC_SYS_COMM_P2L_MUTEX};
static kal_uint32 const cc_sys_comm_ut_l2p_channel[] = {CC_SYS_COMM_L2P_IPC, CC_SYS_COMM_L2P_EVG, CC_SYS_COMM_L2P_MUTEX};

#if defined(__PCORE__)
#define CC_SYS_COMM_TX_CHANNEL    cc_sys_comm_ut_p2l_channel
#define CC_SYS_COMM_RX_CHANNEL    cc_sys_comm_ut_l2p_channel
#else
#define CC_SYS_COMM_TX_CHANNEL    cc_sys_comm_ut_l2p_channel
#define CC_SYS_COMM_RX_CHANNEL    cc_sys_comm_ut_p2l_channel
#endif

#define CC_SYS_COMM_PARA_NUMBER    2
#define CC_SYS_COMM_MASK_TEST_TX_CNT    4

void cc_irq_sys_comm_ut_cb(kal_uint32 index, kal_uint32 para1, kal_uint32 para2)
{
    kal_uint32 correct_seq_1, correct_seq_2, savedMask;
    kal_uint32 i, j;
    kal_uint32 seq_max = CC_IRQ_TX_SEQ_MAX;
	
    if (cc_irq_test_case == CC_IRQ_SYS_COMM_UT_L12PS_MASK || cc_irq_test_case == CC_IRQ_SYS_COMM_UT_PS2L1_MASK)
        seq_max = CC_SYS_COMM_MASK_TEST_TX_CNT;
	
    switch(cc_irq_test_case)
    {
#if defined(__PCORE__)
    case CC_IRQ_SYS_COMM_UT_L12PS_BASIC:
#else
    case CC_IRQ_SYS_COMM_UT_PS2L1_BASIC:
#endif
        correct_seq_1 = cc_irq_it_2_magic[index][0] | cc_irq_it_2_seq[index][0];
        correct_seq_2 = cc_irq_it_2_magic[index][1] | cc_irq_it_2_seq[index][1];
        if (correct_seq_1 != para1 || correct_seq_2 != para2)
        {
            EXT_ASSERT(0, para1, para2, index);
        }
        cc_irq_it_2_seq[index][0]++;
        cc_irq_it_2_seq[index][1]++;

        SHARED_VAR(cc_irq_share_var).share_para1_arr[index] = para1;
        SHARED_VAR(cc_irq_share_var).share_para2_arr[index] = para2;
        CC_IRQ_DMB();

        savedMask = SaveAndSetIRQMask();
            
        test_done = 1;
        for (i = 0; i < sizeof(CC_SYS_COMM_RX_CHANNEL) / sizeof(kal_uint32); i++)
        {
            for (j = 0; j < CC_SYS_COMM_PARA_NUMBER; j++)
            {
                if (cc_irq_it_2_seq[CC_SYS_COMM_RX_CHANNEL[i]][j] != CC_IRQ_TX_SEQ_MAX)
                {
                    test_done = 0;
                    break;
                }
            }

            if(test_done == 0)
                break;
        }
        RestoreIRQMask(savedMask);
        break;
#if defined(__PCORE__)
    case CC_IRQ_SYS_COMM_UT_L12PS_MASK:
    case CC_IRQ_SYS_COMM_UT_L12PS_BASIC_POLLING:
#else
    case CC_IRQ_SYS_COMM_UT_PS2L1_MASK:
    case CC_IRQ_SYS_COMM_UT_PS2L1_BASIC_POLLING:
#endif
        correct_seq_1 = cc_irq_it_2_magic[index][0] | cc_irq_it_2_seq[index][0];
        correct_seq_2 = cc_irq_it_2_magic[index][1] | cc_irq_it_2_seq[index][1];
        if (correct_seq_1 != para1 || correct_seq_2 != para2)
        {
            EXT_ASSERT(0, para1, para2, index);
        }
        cc_irq_it_2_seq[index][0]++;
        cc_irq_it_2_seq[index][1]++;

        CC_IRQ_DMB();

        savedMask = SaveAndSetIRQMask();
            
        test_done = 1;
        for (i = 0; i < sizeof(CC_SYS_COMM_RX_CHANNEL) / sizeof(kal_uint32); i++)
        {
            for (j = 0; j < CC_SYS_COMM_PARA_NUMBER; j++)
            {
                if (cc_irq_it_2_seq[CC_SYS_COMM_RX_CHANNEL[i]][j] != seq_max)
                {
                    test_done = 0;
                    break;
                }
            }

            if(test_done == 0)
                break;
        }
        RestoreIRQMask(savedMask);
        break;
    default:
        ASSERT(0);
    }
}

void cc_irq_sys_comm_ut_cb_0(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_ut_cb(0+CC_SYS_UT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_ut_cb_1(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_ut_cb(1+CC_SYS_UT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_ut_cb_2(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_ut_cb(2+CC_SYS_UT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_ut_cb_3(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_ut_cb(3+CC_SYS_UT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_ut_cb_4(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_ut_cb(4+CC_SYS_UT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_ut_cb_5(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_ut_cb(5+CC_SYS_UT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_basic_tx()
{
    kal_uint32 i, tx_ch;
    kal_int32  ret;    

    for (i = 0; i < sizeof(CC_SYS_COMM_TX_CHANNEL) / sizeof(kal_uint32); i++)
    {
        cc_sys_comm_test_channel = i;
        SHARED_VAR(cc_irq_share_var).share_para1 = 0;
        SHARED_VAR(cc_irq_share_var).share_para2 = 0;
        CC_IRQ_DMB();
        tx_seq = 0;
    	
        while(tx_seq < CC_IRQ_TX_SEQ_MAX)
        {
            tx_ch = CC_SYS_COMM_TX_CHANNEL[i];
            ret = cc_sys_comm_tx(tx_ch, cc_irq_it_2_magic[tx_ch][0] | tx_seq, cc_irq_it_2_magic[tx_ch][1] | tx_seq);
            ASSERT(ret == CC_SYS_COMM_SUCCESS);

            while(1)
            {
                if (SHARED_VAR(cc_irq_share_var).share_para1_arr[tx_ch] == (cc_irq_it_2_magic[tx_ch][0] | tx_seq) && \
                    SHARED_VAR(cc_irq_share_var).share_para2_arr[tx_ch] == (cc_irq_it_2_magic[tx_ch][1] | tx_seq) )
                    break;
            }
            
            tx_seq++;
        }
    }
}

void cc_irq_sys_comm_basic_rx()
{
    while(test_done == 0);
}

void cc_irq_sys_comm_basic_polling_tx()
{
    kal_uint32 i;
    kal_int32  ret;

    tx_seq = 0;
    while(tx_seq < CC_IRQ_TX_SEQ_MAX)
    {
        for (i = 0; i < sizeof(CC_SYS_COMM_TX_CHANNEL) / sizeof(kal_uint32); i++)
        {
            ret = cc_sys_comm_tx_polling(CC_SYS_COMM_TX_CHANNEL[i], cc_irq_it_2_magic[CC_SYS_COMM_TX_CHANNEL[i]][0] | tx_seq, cc_irq_it_2_magic[CC_SYS_COMM_TX_CHANNEL[i]][1] | tx_seq);        	
            ASSERT(ret == CC_SYS_COMM_SUCCESS);
        }
        
        tx_seq++;
    }
}

void cc_irq_sys_comm_basic_polling_rx()
{
    while(test_done == 0);
}

void cc_irq_mask_test_tx()
{
    kal_uint32 i;
    kal_int32  ret;

    tx_seq = 0;
    while(tx_seq < CC_SYS_COMM_MASK_TEST_TX_CNT)
    {
        for (i = 0; i < sizeof(CC_SYS_COMM_TX_CHANNEL) / sizeof(kal_uint32); i++)
        {
            ret = cc_sys_comm_tx_polling(CC_SYS_COMM_TX_CHANNEL[i], cc_irq_it_2_magic[CC_SYS_COMM_TX_CHANNEL[i]][0] | tx_seq, cc_irq_it_2_magic[CC_SYS_COMM_TX_CHANNEL[i]][1] | tx_seq);        	
            ASSERT(ret == CC_SYS_COMM_SUCCESS);
        }
        
        tx_seq++;
    }

#if defined(__PCORE__)    
    SHARED_VAR(cc_irq_share_var).cr4_to_md32_unmask_enable = 1;
#else
    SHARED_VAR(cc_irq_share_var).md32_to_cr4_unmask_enable = 1;
#endif
}

void cc_irq_mask_test_rx()
{
#if defined(__PCORE__)
    while(SHARED_VAR(cc_irq_share_var).md32_to_cr4_unmask_enable == 0);
    ASSERT(CC_IRQ_SUCCESS==cc_irq_unmask(CC_IRQ_L2P_SYS));
#else
    while(SHARED_VAR(cc_irq_share_var).cr4_to_md32_unmask_enable == 0);
    ASSERT(CC_IRQ_SUCCESS==cc_irq_unmask(CC_IRQ_P2L_SYS));
#endif

    while(test_done == 0);
}

void cc_irq_sys_comm_ut()
{/* test case for CC SYS */
    kal_uint32 i, j;
	
#if defined(__PCORE__)
    ASSERT(CC_IRQ_SUCCESS==cc_irq_mask(CC_IRQ_L2P_SYS));
#else
    ASSERT(CC_IRQ_SUCCESS==cc_irq_mask(CC_IRQ_P2L_SYS));
#endif    
    
	  for (i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        cc_irq_it_1_magic[i] = 0x5AF00000 | (i << 16);    //- [15:0] is reserved for sequence number;
        for (j = 0; j < 3; j++)
        {
            cc_irq_it_2_magic[i][j] = 0xFF000000 | (i << 20) | (j << 16);    //- [15:0] is reserved for sequence number;
        }
    }

    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_UT_RX_COMM_SHIFT + 0, cc_irq_sys_comm_ut_cb_0));
    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_UT_RX_COMM_SHIFT + 1, cc_irq_sys_comm_ut_cb_1));
    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_UT_RX_COMM_SHIFT + 2, cc_irq_sys_comm_ut_cb_2));
//    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_UT_RX_COMM_SHIFT + 3, cc_irq_sys_comm_ut_cb_3));
//    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_UT_RX_COMM_SHIFT + 4, cc_irq_sys_comm_ut_cb_4));
//    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_UT_RX_COMM_SHIFT + 5, cc_irq_sys_comm_ut_cb_5));

    //- Test 1 - basic test: L1CORE send message to PCORE
    cc_irq_test_case = CC_IRQ_SYS_COMM_UT_L12PS_BASIC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_sys_comm_basic_rx();
#else
    cc_irq_sys_comm_basic_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - basic test: PCORE send message to L1CORE
    cc_irq_test_case = CC_IRQ_SYS_COMM_UT_PS2L1_BASIC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_sys_comm_basic_tx();
#else
    cc_irq_sys_comm_basic_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 3 - basic test: L1CORE send message to PCORE
    cc_irq_test_case = CC_IRQ_SYS_COMM_UT_L12PS_BASIC_POLLING;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_sys_comm_basic_polling_rx();
#else
    cc_irq_sys_comm_basic_polling_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 4 - basic test: PCORE send message to L1CORE
    cc_irq_test_case = CC_IRQ_SYS_COMM_UT_PS2L1_BASIC_POLLING;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_sys_comm_basic_polling_tx();
#else
    cc_irq_sys_comm_basic_polling_rx();
#endif
    test_item_deinit(cc_irq_test_case);
    
    //- Test 5 - basic test: L1CORE send message to PCORE
    cc_irq_test_case = CC_IRQ_SYS_COMM_UT_L12PS_MASK;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_mask_test_rx();
#else
    cc_irq_mask_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 6 - basic test: PCORE send message to L1CORE
    cc_irq_test_case = CC_IRQ_SYS_COMM_UT_PS2L1_MASK;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_mask_test_tx();
#else
    cc_irq_mask_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);
cc_irq_test_case_SYS_END = 1;
//    while(1);
}


/*****************************************************************************************
 buff test
*****************************************************************************************/
#define CC_IRQ_UT_BUFF_BASIC_BUFF_LEN     12
#define CC_IRQ_UT_BUFF_BASIC_TX_NUMBER    65535
#define CC_IRQ_BUFF_TEST_INIT_PKT_LEN     27
#define CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_LOOP    32
#define CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1    (32 - 4)
#define CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2    (64 - 4)

kal_uint8 test_buff[CC_IRQ_UT_COMMON_CHANNEL_NUMBER][CC_IRQ_BUFF_MAX + 4];

/* dbg log */
kal_uint32 dbg_ptr, dbg_i;

void cc_irq_ut_buff_isr(kal_uint32 index, kal_uint32 addr, kal_uint32 length, kal_uint32 no_use)
{
    kal_uint32 i, savedMask;
    kal_uint8  *ptr;

    ptr = (kal_uint8*)addr;
    switch(cc_irq_test_case)
    {
#if defined(__PCORE__)
    case CC_IRQ_UT_L12PS_BUFF_BASIC_TEST:
    case CC_IRQ_UT_L12PS_BUFF_BASIC_TEST_NO_ACK:
#else
    case CC_IRQ_UT_PS2L1_BUFF_BASIC_TEST:
    case CC_IRQ_UT_PS2L1_BUFF_BASIC_TEST_NO_ACK:
#endif
        {
            ASSERT(length == CC_IRQ_UT_BUFF_BASIC_BUFF_LEN);
            ASSERT(ptr != NULL);
            
            if (*(ptr + 0) != ((kal_uint8)index & 0xFF) || \
            	  *(ptr + 1) != 0xFF || \
            	  *(ptr + 2) != (cc_irq_it_2_seq[index][0] & 0xFF) || \
            	  *(ptr + 3) != ((cc_irq_it_2_seq[index][0] >> 8) & 0xFF))
            {
                ASSERT(0);
            }
            for (i = 4; i < CC_IRQ_UT_BUFF_BASIC_BUFF_LEN; i++)
            {
                if (*(ptr + i) != (index & 0xFF))
                    ASSERT(0);
            }
            cc_irq_it_2_seq[index][0]++;
            
            savedMask = SaveAndSetIRQMask();
            test_done = 1;
            for (i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[i][0] != CC_IRQ_TX_SEQ_MAX)
                {
                    test_done = 0;
                    break;
                }
            }
            RestoreIRQMask(savedMask);
#if defined(__PCORE__)
            SHARED_VAR(cc_irq_share_var).md32_to_cr4_tx_notify = 1;
#else
            SHARED_VAR(cc_irq_share_var).cr4_to_md32_tx_notify = 1;
#endif
        }
        break;
#if defined(__PCORE__)
    case CC_IRQ_UT_L12PS_BUFF_VAR_LEN:
    case CC_IRQ_UT_L12PS_BUFF_VAR_LEN_NO_ACK:
#else
    case CC_IRQ_UT_PS2L1_BUFF_VAR_LEN:
    case CC_IRQ_UT_PS2L1_BUFF_VAR_LEN_NO_ACK:
#endif        
        {
            ASSERT(length == (cc_irq_it_2_seq[index][0] + CC_IRQ_BUFF_TEST_INIT_PKT_LEN));
            if (*(ptr + 0) != ((kal_uint8)(length & 0xFF)) || \
            	  *(ptr + 1) != ((kal_uint8)((length >> 8) & 0xFF)) || \
   	            *(ptr + length - 1) != 0xFF)
   	        {
   	            ASSERT(0);
   	        }
   	        
   	        for (i = 2; i < length - 1;i++)
   	        {
   	            ASSERT(*(ptr + i) == (kal_uint8)index);
   	        }

            cc_irq_it_2_seq[index][0]++;
            
            savedMask = SaveAndSetIRQMask();
            test_done = 1;
            for (i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[i][0] != CC_IRQ_BUFF_MAX - CC_IRQ_BUFF_TEST_INIT_PKT_LEN + 1)
                {
                    test_done = 0;
                    break;
                }
            }
            RestoreIRQMask(savedMask);
#if defined(__PCORE__)
            SHARED_VAR(cc_irq_share_var).md32_to_cr4_tx_notify = 1;
#else
            SHARED_VAR(cc_irq_share_var).cr4_to_md32_tx_notify = 1;
#endif
        }
        break;
#if defined(__CC_IRQ_ON_PCCIF__)
#if defined(__PCORE__)
        case CC_IRQ_UT_L12PS_BUFF_PCCIF_WRAP:
#else
        case CC_IRQ_UT_PS2L1_BUFF_PCCIF_WRAP:
#endif
        {
            if (cc_irq_it_2_seq[index][0] % 2)
            {
                ASSERT(length == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1);
            }
            else
            {
                ASSERT(length == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2);
            }

   	        for (i = 0; i < length - 1;i++)
   	        {
   	            dbg_ptr = (kal_uint32)ptr;
   	            dbg_i = i;
   	            ASSERT(*(ptr + i) == (kal_uint8)index);
   	        }
   	        
   	        ASSERT(*(ptr + length - 1) == 0xFF);
            
            cc_irq_it_2_seq[index][0]++;
            
            test_done = 1;
            for (i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[index][0] != CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_LOOP)
                {
                    test_done = 0;
                    break;
                }
            }
        }
        break;
#if defined(__PCORE__)
        case CC_IRQ_UT_L12PS_BUFF_PCCIF_COMB:
#else
        case CC_IRQ_UT_PS2L1_BUFF_PCCIF_COMB:
#endif
        {
            /* 
            cc_irq_it_2_seq[index][0] == 0 => pkt_len == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 3;
            cc_irq_it_2_seq[index][0] == 1 => pkt_len == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 2;
            cc_irq_it_2_seq[index][0] == 2 => pkt_len == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 1;
            ...
            cc_irq_it_2_seq[index][0] == 6 => pkt_len == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 + 3;
            */
            ASSERT (length == cc_irq_it_2_seq[index][0] + CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 3);
            ASSERT (*(ptr + length - 1) == 0xFF);
            
            /* check payload */
            for(i = 1; i < length - 1; i++)
            {
                ASSERT(*(ptr + i) == (kal_uint8)(index & 0xFF));
            }
            
            cc_irq_it_2_seq[index][0]++;
            if (cc_irq_it_2_seq[index][0] == 7)
            {
                cc_irq_it_2_seq[index][0] = 0;
                cc_irq_it_2_seq[index][1]++;
            }	
            
            test_done = 1;
            for (i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[i][1] != 3)
                {
                    test_done = 0;
                    break;
                }
            }
        }
        break;
#endif        
    default:
        ASSERT(0);
    }
}

void cc_irq_buff_basic_test_tx(kal_uint32 wait_rx_ack)
{
    kal_uint32 i, j;
    kal_int32  ret;

    for(i = 1; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        /* prepare buffer */
        test_buff[i][0] = i & 0xFF;        
        test_buff[i][1] = 0xFF;
        
        for(j = 4; j < CC_IRQ_UT_BUFF_BASIC_BUFF_LEN;j++)
            test_buff[i][j] = i & 0xFF;
    	
        tx_seq = 0;
        while(tx_seq < CC_IRQ_TX_SEQ_MAX)
        {
            test_buff[i][2] = tx_seq & 0xFF;
            test_buff[i][3] = (tx_seq >> 8) & 0xFF;

            if (wait_rx_ack == 1)
            {
#if defined(__PCORE__)
                SHARED_VAR(cc_irq_share_var).cr4_to_md32_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(i + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[i], CC_IRQ_UT_BUFF_BASIC_BUFF_LEN);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(SHARED_VAR(cc_irq_share_var).cr4_to_md32_tx_notify == 0);
#else
                SHARED_VAR(cc_irq_share_var).md32_to_cr4_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(i + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[i], CC_IRQ_UT_BUFF_BASIC_BUFF_LEN);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(SHARED_VAR(cc_irq_share_var).md32_to_cr4_tx_notify == 0);
#endif
            }
            else
            {
                while(1)
                {
#if 0                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
                    if(cc_irq_buffer_channel_full(i + CC_IRQ_UT_TX_IRQ_SHIFT)||cc_irq_param_channel_full(i + CC_IRQ_UT_TX_IRQ_SHIFT))
                    {
                        /*wait*/
                    }
                    else
                    {
                        ret = cc_irq_trigger_interrupt_with_buff(i + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[i], CC_IRQ_UT_BUFF_BASIC_BUFF_LEN);

						if (ret == CC_IRQ_SUCCESS)
                            break;
                        else
                            ASSERT(0);
                    }					
#endif
                }
            }
            
            tx_seq++;
        }
    }
}

void cc_irq_buff_basic_test_rx()
{
    while(test_done == 0);
}

kal_uint32 pkt_len, pkt_start;

void cc_irq_buff_var_len_tx(kal_uint32 wait_rx_ack)
{
    kal_uint32 chl;
    kal_int32  ret;

    for (chl = 0; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
    {
        kal_mem_set((void*)test_buff[chl], (kal_uint8)(chl & 0xFF), CC_IRQ_BUFF_MAX);
    }

    for (pkt_len = CC_IRQ_BUFF_TEST_INIT_PKT_LEN; pkt_len <= CC_IRQ_BUFF_MAX; pkt_len++)
    {
        /* prepare packet */
        for (chl = 0; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
        {
            /* recover previous end mark to index */
            test_buff[chl][pkt_len - 2] = (chl & 0xFF);
        	
            test_buff[chl][0] = (kal_uint8)(pkt_len & 0xFF);
            test_buff[chl][1] = (kal_uint8)((pkt_len >> 8) & 0xFF);
            test_buff[chl][pkt_len - 1] = 0xFF;    /* end mark */
        }
        
        for (chl = 1; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
        {
            if (wait_rx_ack == 1)
            {
#if defined(__PCORE__)
                SHARED_VAR(cc_irq_share_var).cr4_to_md32_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(SHARED_VAR(cc_irq_share_var).cr4_to_md32_tx_notify == 0);
#else
                SHARED_VAR(cc_irq_share_var).md32_to_cr4_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(SHARED_VAR(cc_irq_share_var).md32_to_cr4_tx_notify == 0);
#endif                    
            }
            else
            {
                while(1)
                {
#if 0                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
                    if(cc_irq_buffer_channel_full(chl + CC_IRQ_UT_TX_IRQ_SHIFT)||cc_irq_param_channel_full(chl + CC_IRQ_UT_TX_IRQ_SHIFT))
                    {
                        /*wait*/
                    }
                    else
                    {
                        ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);

						if (ret == CC_IRQ_SUCCESS)
                            break;
                        else
                            ASSERT(0);
                    }					
#endif                
                }
            }
        }
    }
}

void cc_irq_buff_var_len_rx()
{
    while(test_done == 0);
}

void cc_irq_buff_pccif_wrap_tx()
{
    kal_uint32 chl, i;
    kal_int32  ret;
    
    for (chl = 1; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
    {
        kal_mem_set((void*)test_buff[chl], (kal_uint8)(chl & 0xFF), CC_IRQ_BUFF_MAX);
        
        for (i = 0; i < CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_LOOP; i++)
        {
            if (i % 2)
            {
                test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 1] = 0xFF;
                test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2 - 1] = (kal_uint8)chl & 0xFF;
                pkt_len = CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1;
            }
            else
            {
                test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 1] = (kal_uint8)chl & 0xFF;
                test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2 - 1] = 0xFF;
                pkt_len = CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2;
            }

            while(1)
            {
#if 0                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
                    if(cc_irq_buffer_channel_full(chl + CC_IRQ_UT_TX_IRQ_SHIFT)||cc_irq_param_channel_full(chl + CC_IRQ_UT_TX_IRQ_SHIFT))
                    {
                        /*wait*/
                    }
                    else
                    {
                        ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);

						if (ret == CC_IRQ_SUCCESS)
                            break;
                        else
                            ASSERT(0);
                    }					
#endif            
            }
        }
    }
}

void cc_irq_buff_pccif_wrap_rx()
{
    while(test_done == 0);
}

void cc_irq_buff_pccif_comb_tx()
{
    kal_uint32 chl;
    kal_int32  ret;
	
    for (chl = 0; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
    {
        kal_mem_set((void*)test_buff[chl], (kal_uint8)(chl & 0xFF), CC_IRQ_BUFF_MAX);
        test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 + 3 - 1] = 0xFF;
    }	
    
    for (chl = 1; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
    {
        for (pkt_start = 1; pkt_start <= 3; pkt_start++)
        {
            for (pkt_len = CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 3; pkt_len <= CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 + 3; pkt_len++)
            {
                test_buff[chl][pkt_start] = (kal_uint8)(pkt_len & 0xFF);
                test_buff[chl][pkt_start + pkt_len - 1] = 0xFF;
                while(1)
                {
#if 0                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
                    if(cc_irq_buffer_channel_full(chl + CC_IRQ_UT_TX_IRQ_SHIFT)||cc_irq_param_channel_full(chl + CC_IRQ_UT_TX_IRQ_SHIFT))
                    {
                        /*wait*/
                    }
                    else
                    {
                        ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[chl] + pkt_start, pkt_len);

						if (ret == CC_IRQ_SUCCESS)
                            break;
                        else
                            ASSERT(0);
                    }					
#endif                
                }
                test_buff[chl][pkt_start] = (kal_uint8)(chl & 0xFF);
                test_buff[chl][pkt_start + pkt_len - 1] = (kal_uint8)(chl & 0xFF);
            }
        }
    }
}

void cc_irq_buff_pccif_comb_rx()
{
    while(test_done == 0);
}

void cc_irq_buff_test()
{
    cc_irq_ut_buff_test = 1;

    //- Test 1 - CORE1 send multiple packet with length 12 (not include header) to CORE2 through each channel.
    cc_irq_test_case = CC_IRQ_UT_L12PS_BUFF_BASIC_TEST;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_basic_test_rx();
#else
    cc_irq_buff_basic_test_tx(1);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - CORE2 send multiple packet with length 12 (not include header) to CORE1 through each channel.
    cc_irq_test_case = CC_IRQ_UT_PS2L1_BUFF_BASIC_TEST;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_basic_test_tx(1);
#else
    cc_irq_buff_basic_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 3 - CORE1 send multiple packet with length 12 (not include header) to CORE2 through each channel. (no ack)
    cc_irq_test_case = CC_IRQ_UT_L12PS_BUFF_BASIC_TEST_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_basic_test_rx();
#else
    cc_irq_buff_basic_test_tx(0);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 4 - CORE2 send multiple packet with length 12 (not include header) to CORE1 through each channel. (no ack)
    cc_irq_test_case = CC_IRQ_UT_PS2L1_BUFF_BASIC_TEST_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_basic_test_tx(0);
#else
    cc_irq_buff_basic_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 5 - CORE2 send variable length packet to CORE1 through each channel
    cc_irq_test_case = CC_IRQ_UT_L12PS_BUFF_VAR_LEN;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_var_len_rx();
#else
    cc_irq_buff_var_len_tx(1);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 6 - CORE1 send variable length packet to CORE2 through each channel
    cc_irq_test_case = CC_IRQ_UT_PS2L1_BUFF_VAR_LEN;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_var_len_tx(1);
#else
    cc_irq_buff_var_len_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 7 - CORE2 send variable length packet to CORE1 through each channel (no ack)
    cc_irq_test_case = CC_IRQ_UT_L12PS_BUFF_VAR_LEN_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_var_len_rx();
#else
    cc_irq_buff_var_len_tx(0);
#endif
    test_item_deinit(cc_irq_test_case);
    
    //- Test 8 - CORE1 send variable length packet to CORE2 through each channel (no ack)
    cc_irq_test_case = CC_IRQ_UT_PS2L1_BUFF_VAR_LEN_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_var_len_tx(0);
#else
    cc_irq_buff_var_len_rx();
#endif
    test_item_deinit(cc_irq_test_case);




#if defined(__CC_IRQ_ON_PCCIF__)
    //- Special Test 1 - CORE2 triggers tx with wrap case on PCCIF and send packet to CORE1
    cc_irq_test_case = CC_IRQ_UT_L12PS_BUFF_PCCIF_WRAP;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_pccif_wrap_rx();
#else
    cc_irq_buff_pccif_wrap_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Special Test 2 - CORE2 triggers tx with wrap case on PCCIF and send packet to CORE2
    cc_irq_test_case = CC_IRQ_UT_PS2L1_BUFF_PCCIF_WRAP;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_pccif_wrap_tx();
#else
    cc_irq_buff_pccif_wrap_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Special Test 3 - combination of different start address and packet length (mod 4 = 0, mod 4 = 1, mod 4 = 2, mod 4 = 3), CORE 2 to CORE 1
    cc_irq_test_case = CC_IRQ_UT_L12PS_BUFF_PCCIF_COMB;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_pccif_comb_rx();
#else
    cc_irq_buff_pccif_comb_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Special Test 4 - combination of different start address and packet length (mod 4 = 0, mod 4 = 1, mod 4 = 2, mod 4 = 3), CORE 1 to CORE 2
    cc_irq_test_case = CC_IRQ_UT_PS2L1_BUFF_PCCIF_COMB;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_buff_pccif_comb_tx();
#else
    cc_irq_buff_pccif_comb_rx();
#endif
    test_item_deinit(cc_irq_test_case);

#endif    /* defined(__CC_IRQ_ON_PCCIF__) */

    cc_irq_ut_buff_test = 0;
    cc_irq_test_case_BUFF_END = 1;
}

void cc_irq_ut_msg_isr(ilm_struct *ilm_ptr)
{
    ASSERT(0);
}

#endif
