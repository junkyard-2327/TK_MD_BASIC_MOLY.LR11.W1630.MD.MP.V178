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
//#define CC_BUFF_IT
//#define CC_SYS_COMM_IT
//#define CC_ILM_MD1_MD3_IT
//#define CC_RPC_MD1_MD3_IT
/* Direct(Parameter) mode test is default on */

/* sub-test for CC_ILM_MD1_MD3_IT */
//#define KAL_ILM /* this option would test CC MSG from KAL layer in MD1, the "CC_ILM_MD1_MD3_IT" must open */

#define CC_SPINLOCK_MD1_MD3_IT

 /* due to there is CC SYS SYNC between MD1 and MD3 we could bypass CC SYS IRQ in driver(param/buffer mode) test 
    config "shift_cc_sys" to 1 to bypass.
    if "shift_cc_sys" is 0, you should disable HS1 to do test.
 */
kal_int32 shift_cc_sys = 0;

#if defined(KAL_ILM)   
#if defined(__PCORE__)/* always test with MD3 */
#include "global_modid.h"
extern kal_bool kal_cc_irq_msg_send(ilm_struct *ilm_ptr);
#define SRC_MOD_ID  MOD_SIM
#define DST_MOD_ID  MOD_UIM_MD3
#elif defined(__L1CORE__)/* always test with MD3 */
#include "global_modid.h"
extern kal_bool kal_cc_irq_msg_send(ilm_struct *ilm_ptr);
#define SRC_MOD_ID  MOD_SIM
#define DST_MOD_ID  MOD_UIM_MD3
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */
#define SRC_MOD_ID  MOD_UIM
#define DST_MOD_ID  MOD_SIM_MD1
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */
#define SRC_MOD_ID  MOD_UIM
#define DST_MOD_ID  MOD_SIM_MD1
#else
#error "DEFINE ERROR"
#endif
#endif

/*****************************************************************************
 * Type Definition                                                           *
 *****************************************************************************/
#if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */
#define CC_IRQ_IT_COMMON_CHANNEL_NUMBER          ((CC_IRQ_TX_MD3_CHANNEL_NUMBER > CC_IRQ_RX_MD3_CHANNEL_NUMBER)?CC_IRQ_TX_MD3_CHANNEL_NUMBER:CC_IRQ_RX_MD3_CHANNEL_NUMBER)
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */ /* MD3 should modify this */
  #define CC_IRQ_IT_COMMON_CHANNEL_NUMBER    CC_IRQ_RX_MD1_CHANNEL_NUMBER
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */ /* MD3 should modify this */
  #define CC_IRQ_IT_COMMON_CHANNEL_NUMBER    CC_IRQ_RX_MD1_CHANNEL_NUMBER
#endif
kal_uint32 wolf_CC_IRQ_IT_COMMON_CHANNEL_NUMBER;

#if defined(__PCORE__)/* always test with MD3 */
#define CC_IRQ_IT_RX_IRQ_SHIFT    CC_IRQ_MD32P_BASE
#define CC_IRQ_IT_TX_IRQ_SHIFT    CC_IRQ_P2MD3_BASE	
#define CC_SYS_IT_RX_COMM_SHIFT   CC_SYS_COMM_MD32P_BASE
#define CC_SYS_IT_TX_COMM_SHIFT   CC_SYS_COMM_P2MD3_BASE
#elif defined(__L1CORE__)/* always test with MD3 */
#define CC_IRQ_IT_RX_IRQ_SHIFT    CC_IRQ_MD32L_BASE
#define CC_IRQ_IT_TX_IRQ_SHIFT    CC_IRQ_L2MD3_BASE
#define CC_SYS_IT_RX_COMM_SHIFT   CC_SYS_COMM_MD32L_BASE
#define CC_SYS_IT_TX_COMM_SHIFT   CC_SYS_COMM_L2MD3_BASE
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */
#define CC_IRQ_IT_RX_IRQ_SHIFT    CC_IRQ_P2MD3_BASE
#define CC_IRQ_IT_TX_IRQ_SHIFT    CC_IRQ_MD32P_BASE
#define CC_SYS_IT_RX_COMM_SHIFT   CC_SYS_COMM_P2MD3_BASE
#define CC_SYS_IT_TX_COMM_SHIFT   CC_SYS_COMM_MD32P_BASE
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */
#define CC_IRQ_IT_RX_IRQ_SHIFT    CC_IRQ_L2MD3_BASE
#define CC_IRQ_IT_TX_IRQ_SHIFT    CC_IRQ_MD32L_BASE
#define CC_SYS_IT_RX_COMM_SHIFT   CC_SYS_COMM_L2MD3_BASE
#define CC_SYS_IT_TX_COMM_SHIFT   CC_SYS_COMM_MD32L_BASE
#else
#error "DEFINE ERROR"
#endif

/* for ILM test between MD1/MD3 */
#if defined(__PCORE__)/* always test with MD3 */
#define CC_IRQ_MSG_TX_INDEX       CC_IRQ_P2MD3_SYS
#define CC_IRQ_MSG_RX_INDEX       CC_IRQ_MD32P_SYS
#elif defined(__L1CORE__)/* always test with MD3 */
#define CC_IRQ_MSG_TX_INDEX       CC_IRQ_L2MD3_SYS
#define CC_IRQ_MSG_RX_INDEX       CC_IRQ_MD32L_SYS
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */
#define CC_IRQ_MSG_TX_INDEX       CC_IRQ_MD32P_SYS
#define CC_IRQ_MSG_RX_INDEX       CC_IRQ_P2MD3_SYS
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */
#define CC_IRQ_MSG_TX_INDEX       CC_IRQ_MD32L_SYS
#define CC_IRQ_MSG_RX_INDEX       CC_IRQ_L2MD3_SYS
#else
#error "DEFINE ERROR"
#endif

/* for RPC test between MD1/MD3 */
#if defined(__PCORE__)/* always test with MD3 */
#define CC_IRQ_UT_RX_RPC_SHIFT    CC_IRQ_RPC_MD32P_BASE
#define CC_IRQ_UT_TX_RPC_SHIFT    CC_IRQ_RPC_P2MD3_BASE
#elif defined(__L1CORE__)/* always test with MD3 */
#define CC_IRQ_UT_RX_RPC_SHIFT    CC_IRQ_RPC_MD32L_BASE
#define CC_IRQ_UT_TX_RPC_SHIFT    CC_IRQ_RPC_L2MD3_BASE
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */
#define CC_IRQ_UT_RX_RPC_SHIFT    CC_IRQ_RPC_P2MD3_BASE
#define CC_IRQ_UT_TX_RPC_SHIFT    CC_IRQ_RPC_MD32P_BASE
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */
#define CC_IRQ_UT_RX_RPC_SHIFT    CC_IRQ_RPC_L2MD3_BASE
#define CC_IRQ_UT_TX_RPC_SHIFT    CC_IRQ_RPC_MD32L_BASE
#else
#error "DEFINE ERROR"
#endif

#define CC_IRQ_INTSRAM_ZI    __attribute__ ((zero_init, section ("INTSRAM_ZI")))
/*****************************************************************************
 * Data Declaration                                                          *
 *****************************************************************************/
#define MAX_CHANNEL_SUPPORT 16

typedef struct {
    volatile kal_uint32 md32_to_cr4_test_start;
    volatile kal_uint32 md32_to_cr4_test_end;
    volatile kal_uint32 cr4_to_md32_test_start;
    volatile kal_uint32 cr4_to_md32_test_end;    
    volatile kal_uint32 share_para1;
    volatile kal_uint32 share_para2;
    volatile kal_uint32 share_para3;
    volatile kal_uint32 share_para1_arr[MAX_CHANNEL_SUPPORT];/*CC_IRQ_MAX_CHANNEL*/
    volatile kal_uint32 share_para2_arr[MAX_CHANNEL_SUPPORT];
    volatile kal_uint32 share_para3_arr[MAX_CHANNEL_SUPPORT];
    volatile kal_uint32 cr4_to_md32_unmask_enable;
    volatile kal_uint32 md32_to_cr4_unmask_enable;
    volatile kal_int32 cr4_to_md32_tx_notify;/*dir1_tx_notify*/
    volatile kal_int32 md32_to_cr4_tx_notify;/*dir2_tx_notify*/
} cc_irq_it_share_t;

cc_irq_it_share_t *cc_irq_it_share_var;/* for test case sync between MD1 & MD3 */

#if defined(__PCORE__)/* always test with MD3 */
extern kal_uint32 cc_irq_ps2md3_share_data_addr;
extern kal_uint32 cc_irq_md32ps_share_data_addr;
#elif defined(__L1CORE__)/* always test with MD3 */
extern kal_uint32 cc_irq_l12md3_share_data_addr;
extern kal_uint32 cc_irq_md32l1_share_data_addr;
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */
extern kal_uint32 cc_irq_ps2md3_share_data_addr;
extern kal_uint32 cc_irq_md32ps_share_data_addr;
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */
extern kal_uint32 cc_irq_l12md3_share_data_addr;
extern kal_uint32 cc_irq_md32l1_share_data_addr;
#else
#error "DEFINE ERROR"
#endif

#if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */
static kal_uint32 cc_irq_index[CC_IRQ_RX_MD3_CHANNEL_NUMBER] = {CC_IRQ_IRQ_CODE_FROM_MD3};
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */ /* MD3 should modify this */
static kal_uint32 cc_irq_index[CC_IRQ_RX_MD1_CHANNEL_NUMBER] = {CC_IRQ_IRQ_CODE_FROM_MD1};
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */ /* MD3 should modify this */
static kal_uint32 cc_irq_index[CC_IRQ_RX_MD1_CHANNEL_NUMBER] = {CC_IRQ_IRQ_CODE_FROM_MD1};
#endif

static kal_uint32 cc_irq_test_case = 0;
static kal_uint32 cc_irq_it_1_magic[MAX_CHANNEL_SUPPORT];
static kal_uint32 cc_irq_it_2_magic[MAX_CHANNEL_SUPPORT][CC_IRQ_PARA_NUMBER];
static kal_uint32 cc_irq_it_seq[CC_IRQ_PARA_NUMBER];
static kal_uint32 cc_irq_it_2_seq[MAX_CHANNEL_SUPPORT][CC_IRQ_PARA_NUMBER];

static volatile kal_uint32 test_done = 0;
static kal_uint32 tx_seq = 0;
volatile static kal_int32 next_rx_index;    //- test case 8

static kal_uint32 cc_irq_it_buff_test = 0;/* 0==> for buffer mode, 1==> for param mode */

/* use to double confirm the test case is complete */
static kal_uint32 cc_irq_test_case_PARAM_END = 0;
static kal_uint32 cc_irq_test_case_BUFF_END = 0;
static kal_uint32 cc_irq_test_case_SYS_END = 0;
static kal_uint32 cc_irq_test_case_ILM_END = 0;
static kal_uint32 cc_irq_test_case_RPC_END = 0;
static kal_uint32 cc_irq_test_case_CC_spinlock_END = 0;

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
#define CC_IRQ_NO_WAIT_TEST_DONE   1
#define CC_IRQ_TX_SEQ_MAX    0xFF
//#define CC_IRQ_TEST_SEQ_MAX        (0xFF)

//- TEST STATUS
enum {
    CC_IRQ_TEST_STATUS_ENABLE = 1,
    CC_IRQ_TEST_STATUS_DISABLE = 2,
} ;

//- Test Items 
enum {
/*test for Param mode*/ 
    CC_IRQ_IT_MD3_TO_MD1_PARAM_WAIT_RESP = 100,
    CC_IRQ_IT_MD1_TO_MD3_PARAM_WAIT_RESP,/*101*/
    CC_IRQ_IT_MD3_TO_MD1_PARAM_MUL_SRC,/*102*/
    CC_IRQ_IT_MD1_TO_MD3_PARAM_MUL_SRC,/*103*/
    CC_IRQ_IT_MD3_TO_MD1_PARAM_NESTED_TRIGGER,/*104*/
    CC_IRQ_IT_MD1_TO_MD3_PARAM_NESTED_TRIGGER,/*105*/
    CC_IRQ_IT_MD3_TO_MD1_PARAM_PREEMPT_TEST,/*106*/
    //CC_IRQ_IT_MD1_TO_MD3_PARAM_PREEMPT_TEST,/*107*/ /* MD3 doesn't support */
/*test for Buffer mode*/    
    CC_IRQ_IT_MD3_TO_MD1_BUFF_BASIC_ACK = 200,
    CC_IRQ_IT_MD1_TO_MD3_BUFF_BASIC_ACK,/*201*/
    CC_IRQ_IT_MD3_TO_MD1_BUFF_BASIC_NO_ACK,/*202*/
    CC_IRQ_IT_MD1_TO_MD3_BUFF_BASIC_NO_ACK,/*203*/
    CC_IRQ_IT_MD3_TO_MD1_BUFF_VAR_LEN_ACK,/*204*/
    CC_IRQ_IT_MD1_TO_MD3_BUFF_VAR_LEN_ACK,/*205*/
    CC_IRQ_IT_MD3_TO_MD1_BUFF_VAR_LEN_NO_ACK,/*206*/
    CC_IRQ_IT_MD1_TO_MD3_BUFF_VAR_LEN_NO_ACK,/*207*/
    CC_IRQ_IT_MD3_TO_MD1_BUFF_COMB,/*208*/
    CC_IRQ_IT_MD1_TO_MD3_BUFF_COMB,/*209*/
/*test for CC SYS */
    CC_IRQ_SYS_COMM_IT_MD3_TO_MD1_BASIC = 300,
    CC_IRQ_SYS_COMM_IT_MD1_TO_MD3_BASIC,/*301*/
    CC_IRQ_SYS_COMM_IT_MD3_TO_MD1_BASIC_POLLING,/*302*/
    CC_IRQ_SYS_COMM_IT_MD1_TO_MD3_BASIC_POLLING,/*303*/
    CC_IRQ_SYS_COMM_IT_MD3_TO_MD1_MASK,/*304*/
    CC_IRQ_SYS_COMM_IT_MD1_TO_MD3_MASK,/*305*/
/*test for CC MSG */
    CC_IRQ_MSG_IT_MD3_TO_MD1_BASIC = 400,
    CC_IRQ_MSG_IT_MD1_TO_MD3_BASIC,/*401*/
    CC_IRQ_MSG_IT_MD3_TO_MD1_VAR_LEN,/*402*/
    CC_IRQ_MSG_IT_MD1_TO_MD3_VAR_LEN,/*403*/
/*    CC_IRQ_UT_L12PS_MSG_CON_TX,
    CC_IRQ_UT_PS2L1_MSG_CON_TX,
    CC_IRQ_UT_L12PS_MSG_TIME_PROFILE_LEN1,
    CC_IRQ_UT_PS2L1_MSG_TIME_PROFILE_LEN1,
    CC_IRQ_UT_L12PS_MSG_TIME_PROFILE_LEN2,
    CC_IRQ_UT_PS2L1_MSG_TIME_PROFILE_LEN2,  */  
/*test for CC RPC */
    CC_IRQ_RPC_IT_MD3_TO_MD1_NOIN_NOOUT = 500,
    CC_IRQ_RPC_IT_MD1_TO_MD3_NOIN_NOOUT,/*501*/
    CC_IRQ_RPC_IT_MD3_TO_MD1_IN_NOOUT,/*502*/   
    CC_IRQ_RPC_IT_MD1_TO_MD3_IN_NOOUT,/*503*/    
    CC_IRQ_RPC_IT_MD3_TO_MD1_IN_OUT,/*504*/   
    CC_IRQ_RPC_IT_MD1_TO_MD3_IN_OUT,/*505*/   
    CC_IRQ_RPC_IT_MD3_TO_MD1_IN_OUT_MAX,/*506*/   
    CC_IRQ_RPC_IT_MD1_TO_MD3_IN_OUT_MAX,/*507*/    
/*test for CC spinlock ability */
    CC_SPINLOCK_IT_TEST_1 = 601,
    CC_SPINLOCK_IT_TEST_2,/*602*/
    CC_SPINLOCK_IT_TEST_3,/*603*/
    CC_SPINLOCK_IT_TEST_4,/*604*/    
    CC_SPINLOCK_IT_TEST_5,/*605*/
    CC_SPINLOCK_IT_TEST_6,/*606*/     
    CC_SPINLOCK_IT_TEST_7,/*607*/
    CC_SPINLOCK_IT_TEST_8,/*608*/
    CC_SPINLOCK_IT_TEST_9,/*609*/
    CC_SPINLOCK_IT_TEST_10,/*610*/    
    CC_SPINLOCK_IT_TEST_11,/*611*/
    CC_SPINLOCK_IT_TEST_12,/*612*/     
};

void cc_irq_it_buff_isr(kal_uint32 index, kal_uint32 addr, kal_uint32 length, kal_uint32 no_use);
static void cc_irq_it_param_isr(kal_uint32 irq_index, kal_uint32 para1, kal_uint32 para2, kal_uint32 para3);
void cc_irq_it_set_pri(kal_uint32 cc_irq_id, kal_uint32 pri);
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
void cc_irq_it_md1_md3()
{
    wolf_CC_IRQ_IT_COMMON_CHANNEL_NUMBER = CC_IRQ_IT_COMMON_CHANNEL_NUMBER;
    kal_uint32 i, j;
    cc_irq_it_share_var = (cc_irq_it_share_t *)cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_MD32PS_CCIT_SHARE, sizeof(cc_irq_it_share_t));

    /* due to MD3 boot up faster than MD1, "cc_irq_it_share_var" is init by MD3 */		

#if defined(CC_SPINLOCK_MD1_MD3_IT)/* define for test CC spinlock */ 
        extern void cc_spinlock_ability_it();
        cc_spinlock_ability_it();
        ASSERT(0);
#endif

#if defined(CC_ILM_MD1_MD3_IT)/* define for test CC SYS ILM*/ 
    if(CC_IRQ_MD3_IS_EXIST())
    {
        extern void cc_irq_msg_it();
        cc_irq_msg_it();
    }
#endif

#if defined(CC_RPC_MD1_MD3_IT)/* define for test CC SYS RPC */
    if(CC_IRQ_MD3_IS_EXIST())
    {
        extern void cc_irq_rpc_it();
        cc_irq_rpc_it();
    }	
#endif

#if defined(CC_SYS_COMM_IT)/* define for test CC SYS IRQ */
extern void cc_irq_sys_comm_it();
    cc_irq_sys_comm_it();
#endif

 /* due to there is CC SYS SYNC between MD1 and MD3 we could bypass CC SYS IRQ in below test 
    config "shift_cc_sys" to 1 to bypass.
    if "shift_cc_sys" is 0, you should disable HS1 to do test.
 */

    //- Register call back function
    for(i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
        ASSERT(CC_IRQ_SUCCESS == cc_irq_register_callback(i+CC_IRQ_IT_RX_IRQ_SHIFT, cc_irq_it_cb));
        CC_IRQ_DRV_MASK(cc_irq_index[i]);            
    }

    /* set priority */
    for (i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
        cc_irq_it_set_pri(cc_irq_index[i], i);
    }

    /* init some parameters for IT */		
    for (i = 0; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
        cc_irq_it_1_magic[i] = 0x5AF00000 | (i << 16);    //- [15:0] is reserved for sequence number;
        for (j = 0; j < 3; j++)
        {
            cc_irq_it_2_magic[i][j] = 0xFF000000 | (i << 20) | (j << 16);    //- [15:0] is reserved for sequence number;
        }
    }

/* test para mode */
extern void cc_irq_param_test();
    cc_irq_param_test();

#if defined(CC_BUFF_IT)/* define for test buffer mode */
extern void cc_irq_buff_test();
    cc_irq_buff_test();
#endif

}


/*****************************************************************************
 * Internal Function                                                         *
 *****************************************************************************/
void cc_irq_param_test()
{/* test para mode */

    cc_irq_it_buff_test = 0;

    //- Test 1 - MD3 triggers interrupt (same source) to MD1 and wait process done, then trigger another time.
    cc_irq_test_case = CC_IRQ_IT_MD3_TO_MD1_PARAM_WAIT_RESP;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_basic_test_rx();
#else/* MD3 */
    cc_irq_basic_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - MD1 triggers interrupt (same source) to MD3 and wait process done, then trigger another time.
    cc_irq_test_case = CC_IRQ_IT_MD1_TO_MD3_PARAM_WAIT_RESP;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_basic_test_tx();
#else/* MD3 */
    cc_irq_basic_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);
    
    //- Test 3 - MD3 triggers interrupt to MD1 with all the IRQ sequentially. When all the IRQ are processed done, trigger another time.
    cc_irq_test_case = CC_IRQ_IT_MD3_TO_MD1_PARAM_MUL_SRC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_multi_test_rx();
#else/* MD3 */
    cc_irq_multi_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 4 - MD1 triggers interrupt to MD3 with all the IRQ sequentially. When all the IRQ are processed done, trigger another time.
    cc_irq_test_case = CC_IRQ_IT_MD1_TO_MD3_PARAM_MUL_SRC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_multi_test_tx();
#else/* MD3 */
    cc_irq_multi_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 5 - MD3 triggers interrupt to MD1 with nested trigger count being max for all the IRQ and check behavior.
    cc_irq_test_case = CC_IRQ_IT_MD3_TO_MD1_PARAM_NESTED_TRIGGER;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);    
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_trans_max_test_rx();
#else/* MD3 */
    cc_irq_trans_max_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 6 - MD1 triggers interrupt to MD3 with nested trigger count being max for all the IRQ and check behavior.
    cc_irq_test_case = CC_IRQ_IT_MD1_TO_MD3_PARAM_NESTED_TRIGGER;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_trans_max_test_tx();
#else/* MD3 */
    cc_irq_trans_max_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 7 - MD3 trigger CC IRQ with lowest priority, wait MD1 ack, then trigger higher priority
    //- Be sure that CC IRQ with larger index has lower priority.
    cc_irq_test_case = CC_IRQ_IT_MD3_TO_MD1_PARAM_PREEMPT_TEST;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_pri_test_rx();
#else/* MD3 */
    cc_irq_pri_test_tx();
#endif    
    test_item_deinit(cc_irq_test_case);    

#if 0/* MD3 doesn't support */    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__PCORE__)||defined(__L1CORE__)
/* under construction !*/
#else/* MD3 */
/* under construction !*/
#endif
/* under construction !*/
#endif

    cc_irq_test_case_PARAM_END = 1;

}

static void cc_irq_it_param_isr(kal_uint32 irq_index, kal_uint32 para1, kal_uint32 para2, kal_uint32 para3)
{
    kal_uint32 correct_seq_1, correct_seq_2, correct_seq_3;
    kal_uint32 i, j, savedMask;
    
    switch (cc_irq_test_case)
    {
#if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */
    case CC_IRQ_IT_MD3_TO_MD1_PARAM_WAIT_RESP:
#else /* MD3 test with PCORE/L1CORE */
    case CC_IRQ_IT_MD1_TO_MD3_PARAM_WAIT_RESP:
#endif
        {
            //- test case 1 will only receive irq from index shift_cc_sys
            if (irq_index != shift_cc_sys)
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
            cc_irq_it_share_var->share_para1 = para1;
            cc_irq_it_share_var->share_para2 = para2;
            cc_irq_it_share_var->share_para3 = para3;

            CC_IRQ_DMB();
            
            if (cc_irq_it_seq[0] == CC_IRQ_TX_SEQ_MAX &&
                cc_irq_it_seq[1] == CC_IRQ_TX_SEQ_MAX &&
                cc_irq_it_seq[2] == CC_IRQ_TX_SEQ_MAX )
            {
                test_done = 1;
            }
        }
        break;
#if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */
    case CC_IRQ_IT_MD3_TO_MD1_PARAM_MUL_SRC:
#else /* MD3 test with PCORE/L1CORE */
    case CC_IRQ_IT_MD1_TO_MD3_PARAM_MUL_SRC:
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
            
            cc_irq_it_share_var->share_para1_arr[irq_index] = para1;
            cc_irq_it_share_var->share_para2_arr[irq_index] = para2;
            cc_irq_it_share_var->share_para3_arr[irq_index] = para3;

            CC_IRQ_DMB();

            CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);
            
            test_done = 1;
            for (i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
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

            CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
        }
        break;
#if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */
    case CC_IRQ_IT_MD3_TO_MD1_PARAM_NESTED_TRIGGER:
#else /* MD3 test with PCORE/L1CORE */
    case CC_IRQ_IT_MD1_TO_MD3_PARAM_NESTED_TRIGGER:
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

            CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);
        
            test_done = 1;
            for (i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
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
        
            CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
        }
        break;
#if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */
    case CC_IRQ_IT_MD3_TO_MD1_PARAM_PREEMPT_TEST:
#else /* MD3 test with PCORE/L1CORE */
    //case CC_IRQ_IT_MD1_TO_MD3_PARAM_PREEMPT_TEST: /* MD3 doesn't support */
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
#if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */
            cc_irq_it_share_var->cr4_to_md32_tx_notify--;
#else /* MD3 test with PCORE/L1CORE */
            cc_irq_it_share_var->md32_to_cr4_tx_notify--;
#endif
            if(next_rx_index-shift_cc_sys>=0)
            ASSERT(CC_IRQ_SUCCESS==cc_irq_unmask(CC_IRQ_IT_RX_IRQ_SHIFT+next_rx_index));

            while(next_rx_index-shift_cc_sys >= 0);
            test_done = 1;            
        }
        break;
    default:
        ASSERT(0);
    }
}

static void cc_irq_it_cb(kal_uint32 para1, kal_uint32 para2, kal_uint32 para3)
{
    kal_uint32 irq_code, index;

#if defined(__PCORE__)||defined(__L1CORE__)
    irq_code = IRQ_Current_LISR();
#else/* MD3 */
    irq_code = IRQ_Current_LISR(); /* MD3 should modify this */
#endif

    for(index = shift_cc_sys; index < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; index++)
    {
        if (irq_code == cc_irq_index[index])
        {
#if defined(CC_BUFF_IT)        
            if (cc_irq_it_buff_test)
               {cc_irq_it_buff_isr(index, para1, para2, para3);}
			else
#endif 			
               {cc_irq_it_param_isr(index, para1, para2, para3);}
        }
    }
}

static kal_uint32 get_free_space_by_channel(kal_uint32 cc_irq_share_data_addr, kal_uint32 cc_index_offset)
{
    kal_uint32 read_ptr, write_ptr;
    CC_IRQ_SHARE_MEM_T      *cc_irq_share_data_addr_ptr;

    cc_irq_share_data_addr_ptr = (CC_IRQ_SHARE_MEM_T *)cc_irq_share_data_addr;

    read_ptr = cc_irq_share_data_addr_ptr->cc_irq_param_read_index[cc_index_offset];
    write_ptr = cc_irq_share_data_addr_ptr->cc_irq_param_write_index[cc_index_offset];

    if (write_ptr >= read_ptr)
        return CC_IRQ_NESTED_TRIGGER_MAX - (write_ptr - read_ptr);
    else
        return read_ptr - write_ptr - 1;
}

static void test_item_init(kal_uint32 test_case, kal_uint32 unmask_irq)
{
    kal_uint32 i, j;
    
    test_done = 0;

#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_it_share_var->cr4_to_md32_test_start = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(cc_irq_it_share_var->md32_to_cr4_test_start != CC_IRQ_TEST_STATUS_ENABLE);
    cc_irq_it_share_var->cr4_to_md32_test_end = CC_IRQ_TEST_STATUS_DISABLE;
    cc_irq_it_share_var->cr4_to_md32_unmask_enable = 0;
    cc_irq_it_share_var->cr4_to_md32_tx_notify = CC_IRQ_IT_COMMON_CHANNEL_NUMBER - 1;
    CC_IRQ_DMB();
#else/* MD3 */
    cc_irq_it_share_var->md32_to_cr4_test_start = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(cc_irq_it_share_var->cr4_to_md32_test_start != CC_IRQ_TEST_STATUS_ENABLE);
    cc_irq_it_share_var->md32_to_cr4_test_end = CC_IRQ_TEST_STATUS_DISABLE;
    cc_irq_it_share_var->md32_to_cr4_unmask_enable = 0;
    cc_irq_it_share_var->md32_to_cr4_tx_notify = CC_IRQ_IT_COMMON_CHANNEL_NUMBER - 1;
    CC_IRQ_DMB();
#endif
    
    tx_seq = 0;
    
    for (i = 0; i < CC_IRQ_PARA_NUMBER; i++)
    {
        cc_irq_it_seq[i] = 0;
        for(j = 0; j < MAX_CHANNEL_SUPPORT; j++)
        {
            cc_irq_it_2_seq[j][i] = 0;
        }
    }
    
    if (unmask_irq == CC_IRQ_UNMASK_IRQ)
    {
        for(i = 0; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
        {
            CC_IRQ_DRV_UNMASK(cc_irq_index[i]);
        }
    }
}

static void test_item_deinit(kal_uint32 test_case)
{
    kal_uint32 i, free_space_cnt = 0;

    for(i = 0; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
        CC_IRQ_DRV_MASK(cc_irq_index[i]);
    }

#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_it_share_var->cr4_to_md32_test_start = CC_IRQ_TEST_STATUS_DISABLE;
    cc_irq_it_share_var->cr4_to_md32_test_end = CC_IRQ_TEST_STATUS_ENABLE; 
    CC_IRQ_DMB();
    while(cc_irq_it_share_var->md32_to_cr4_test_end != CC_IRQ_TEST_STATUS_ENABLE);
#else/* MD3 */
    cc_irq_it_share_var->md32_to_cr4_test_start = CC_IRQ_TEST_STATUS_DISABLE;
    cc_irq_it_share_var->md32_to_cr4_test_end = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(cc_irq_it_share_var->cr4_to_md32_test_end != CC_IRQ_TEST_STATUS_ENABLE);
#endif

    for(i = 0; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
#if defined(__PCORE__)/* always test with MD3 */
        free_space_cnt = get_free_space_by_channel(cc_irq_md32ps_share_data_addr, i);
#elif defined(__L1CORE__)/* always test with MD3 */
        free_space_cnt = get_free_space_by_channel(cc_irq_md32l1_share_data_addr, i);
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */
        free_space_cnt = get_free_space_by_channel(cc_irq_ps2md3_share_data_addr, i);
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */
        free_space_cnt = get_free_space_by_channel(cc_irq_l12md3_share_data_addr, i);
#endif
        EXT_ASSERT(free_space_cnt == CC_IRQ_NESTED_TRIGGER_MAX, free_space_cnt, i, 0);
    }
}



/*****************************************************************************************
CC IRQ Parameter mode test
*****************************************************************************************/
void cc_irq_basic_test_tx()
{
    while(tx_seq < CC_IRQ_TX_SEQ_MAX)
    {
        cc_irq_it_share_var->share_para1 = 0;
        cc_irq_it_share_var->share_para2 = 0;
        cc_irq_it_share_var->share_para3 = 0;
    
        CC_IRQ_DMB();
    
        cc_irq_trigger_interrupt(CC_IRQ_IT_TX_IRQ_SHIFT+shift_cc_sys, cc_irq_it_1_magic[0] | tx_seq, cc_irq_it_1_magic[1] | tx_seq, cc_irq_it_1_magic[2] | tx_seq);
        
        while(1)
        {
            if (cc_irq_it_share_var->share_para1 == (cc_irq_it_1_magic[0] | tx_seq) && \
                cc_irq_it_share_var->share_para2 == (cc_irq_it_1_magic[1] | tx_seq) && \
                cc_irq_it_share_var->share_para3 == (cc_irq_it_1_magic[2] | tx_seq))
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
    kal_uint32 irq_respond[CC_IRQ_IT_COMMON_CHANNEL_NUMBER];
    kal_uint32 i, end_test_loop;
    kal_int32  ret;
    
    while(tx_seq < CC_IRQ_TX_SEQ_MAX)
    {
        for(i = 0; i < 3; i++)
        {
            cc_irq_it_share_var->share_para1_arr[i] = 0;
            cc_irq_it_share_var->share_para2_arr[i] = 0;
            cc_irq_it_share_var->share_para3_arr[i] = 0;

            CC_IRQ_DMB();
        }
        for(i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
        {
            ret = cc_irq_trigger_interrupt(CC_IRQ_IT_TX_IRQ_SHIFT + i, cc_irq_it_2_magic[i][0] | tx_seq, cc_irq_it_2_magic[i][1] | tx_seq, cc_irq_it_2_magic[i][2] | tx_seq);

            ASSERT(ret == CC_IRQ_SUCCESS);
        }

        for(i = 0; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
            irq_respond[i] = 0;

        end_test_loop = 0;
        while(end_test_loop == 0)
        {
            for(i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER;i++)
            {
                if (cc_irq_it_share_var->share_para1_arr[i] == (cc_irq_it_2_magic[i][0] | tx_seq))
                    irq_respond[i] |= (1 << 0);
                if (cc_irq_it_share_var->share_para2_arr[i] == (cc_irq_it_2_magic[i][1] | tx_seq))
                    irq_respond[i] |= (1 << 1);
                if (cc_irq_it_share_var->share_para3_arr[i] == (cc_irq_it_2_magic[i][2] | tx_seq))
                    irq_respond[i] |= (1 << 2);
            }

            for(i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (irq_respond[i] != 7)
                    break;
            }

            if (i == CC_IRQ_IT_COMMON_CHANNEL_NUMBER)
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
        for(i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
        {
            ret = cc_irq_trigger_interrupt(CC_IRQ_IT_TX_IRQ_SHIFT+i, cc_irq_it_2_magic[i][0] | tx_seq, cc_irq_it_2_magic[i][1] | tx_seq, cc_irq_it_2_magic[i][2] | tx_seq);
            ASSERT(ret == CC_IRQ_SUCCESS);                    
        }
    
        tx_seq++;
    }

#if defined(__PCORE__)/* always test with MD3 */
    //- notify MD3 to unmask irq and process.
    for(i = 1; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
        free_space_cnt = get_free_space_by_channel(cc_irq_ps2md3_share_data_addr, i);
        EXT_ASSERT(free_space_cnt == 0, free_space_cnt, i, 0);
    }
    cc_irq_it_share_var->cr4_to_md32_unmask_enable = 1;
#elif defined(__L1CORE__)/* always test with MD3 */
    //- notify MD3 to unmask irq and process.
    for(i = 1; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
        free_space_cnt = get_free_space_by_channel(cc_irq_l12md3_share_data_addr, i);
        EXT_ASSERT(free_space_cnt == 0, free_space_cnt, i, 0);
    }
    cc_irq_it_share_var->cr4_to_md32_unmask_enable = 1;
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */
    //- notify PSCORE to unmask irq and process.
    for(i = 1; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
        free_space_cnt = get_free_space_by_channel(cc_irq_md32ps_share_data_addr, i);
        EXT_ASSERT(free_space_cnt == 0, free_space_cnt, i, 0);
    }
    cc_irq_it_share_var->md32_to_cr4_unmask_enable = 1;
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */
    //- notify L1CORE to unmask irq and process.
    for(i = 1; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
        free_space_cnt = get_free_space_by_channel(cc_irq_md32l1_share_data_addr, i);
        EXT_ASSERT(free_space_cnt == 0, free_space_cnt, i, 0);
    }
    cc_irq_it_share_var->md32_to_cr4_unmask_enable = 1;
#endif

}

void cc_irq_trans_max_test_rx()
{
    kal_uint32 i;

#if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */
    //- wait for MD3 sends all packets
    while(cc_irq_it_share_var->md32_to_cr4_unmask_enable == 0);
#else /* MD3 test with PCORE/L1CORE */
    //- wait for MD1 sends all packets
    while(cc_irq_it_share_var->cr4_to_md32_unmask_enable == 0);
#endif

    //- unmask IRQs
    for(i = 0; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
        CC_IRQ_DRV_UNMASK(cc_irq_index[i]);
    }

    //- wait for all irq processed
    while(test_done == 0);
}

void cc_irq_pri_test_tx()
{
    kal_uint32 i, index;
    kal_int32  ret;
	
    for(i = 0; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER-shift_cc_sys; i++)
    {
        index = CC_IRQ_IT_COMMON_CHANNEL_NUMBER - 1 - i;
        
        ret = cc_irq_trigger_interrupt(CC_IRQ_IT_TX_IRQ_SHIFT+index, cc_irq_it_2_magic[index][0] | tx_seq, cc_irq_it_2_magic[index][1] | tx_seq, cc_irq_it_2_magic[index][2] | tx_seq);
        ASSERT(ret == CC_IRQ_SUCCESS);

    //- wait receiver core response
#if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */
        while(index == cc_irq_it_share_var->md32_to_cr4_tx_notify);
#else/* MD3 test with PCORE/L1CORE */
        while(index == cc_irq_it_share_var->cr4_to_md32_tx_notify);
#endif
    }
}

void cc_irq_pri_test_rx()
{
    //- unmask IRQ high highest priority.
    next_rx_index = CC_IRQ_IT_COMMON_CHANNEL_NUMBER - 1;
    ASSERT(CC_IRQ_SUCCESS==cc_irq_unmask(CC_IRQ_IT_RX_IRQ_SHIFT+CC_IRQ_IT_COMMON_CHANNEL_NUMBER - 1));
    while(test_done == 0);
}

void cc_irq_it_set_pri(kal_uint32 cc_irq_id, kal_uint32 pri)
{
#if defined(MT6755)
    kal_uint32 reg_val, mask, off;
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
static kal_uint32 const cc_sys_comm_ut_p2md3_channel[] = {CC_SYS_COMM_P2MD3_MSG, CC_SYS_COMM_P2MD3_RPC};
static kal_uint32 const cc_sys_comm_ut_md32p_channel[] = {CC_SYS_COMM_MD32P_MSG, CC_SYS_COMM_MD32P_RPC};
static kal_uint32 const cc_sys_comm_ut_l2md3_channel[] = {CC_SYS_COMM_L2MD3_MSG, CC_SYS_COMM_L2MD3_RPC};
static kal_uint32 const cc_sys_comm_ut_md32l_channel[] = {CC_SYS_COMM_MD32L_MSG, CC_SYS_COMM_MD32L_RPC};

#if defined(__PCORE__)/* always test with MD3 */
#define CC_SYS_COMM_TX_CHANNEL    cc_sys_comm_ut_p2md3_channel
#define CC_SYS_COMM_RX_CHANNEL    cc_sys_comm_ut_md32p_channel
#elif defined(__L1CORE__)/* always test with MD3 */
#define CC_SYS_COMM_TX_CHANNEL    cc_sys_comm_ut_l2md3_channel
#define CC_SYS_COMM_RX_CHANNEL    cc_sys_comm_ut_md32l_channel
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */
#define CC_SYS_COMM_TX_CHANNEL    cc_sys_comm_ut_md32p_channel
#define CC_SYS_COMM_RX_CHANNEL    cc_sys_comm_ut_p2md3_channel
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */
#define CC_SYS_COMM_TX_CHANNEL    cc_sys_comm_ut_md32l_channel
#define CC_SYS_COMM_RX_CHANNEL    cc_sys_comm_ut_l2md3_channel
#else
#error "DEFINE ERROR"
#endif

#define CC_SYS_COMM_PARA_NUMBER    2

/* due to buffer design, the buffer number must not less than 2(the buffer we could use is "num-1") */
#define CC_SYS_COMM_MASK_TEST_TX_CNT    (CC_IRQ_NESTED_TRIGGER_MAX-1)

void cc_irq_sys_comm_it_cb(kal_uint32 comm_id, kal_uint32 para1, kal_uint32 para2)
{
    kal_uint32 correct_seq_1, correct_seq_2, savedMask;
    kal_uint32 i, j;
    kal_uint32 seq_max = CC_IRQ_TX_SEQ_MAX;
    kal_uint32 data_index = comm_id - CC_SYS_IT_RX_COMM_SHIFT;
	
    if (cc_irq_test_case == CC_IRQ_SYS_COMM_IT_MD3_TO_MD1_MASK || cc_irq_test_case == CC_IRQ_SYS_COMM_IT_MD1_TO_MD3_MASK)
        seq_max = CC_SYS_COMM_MASK_TEST_TX_CNT;
	
    switch(cc_irq_test_case)
    {
#if defined(__PCORE__)||defined(__L1CORE__)
    case CC_IRQ_SYS_COMM_IT_MD3_TO_MD1_BASIC:
#else/* MD3 */
    case CC_IRQ_SYS_COMM_IT_MD1_TO_MD3_BASIC:
#endif
        correct_seq_1 = cc_irq_it_2_magic[data_index][0] | cc_irq_it_2_seq[data_index][0];
        correct_seq_2 = cc_irq_it_2_magic[data_index][1] | cc_irq_it_2_seq[data_index][1];
        if (correct_seq_1 != para1 || correct_seq_2 != para2)
        {
            EXT_ASSERT(0, para1, para2, comm_id);
        }
        cc_irq_it_2_seq[data_index][0]++;
        cc_irq_it_2_seq[data_index][1]++;

        cc_irq_it_share_var->share_para1_arr[data_index] = para1;
        cc_irq_it_share_var->share_para2_arr[data_index] = para2;
        CC_IRQ_DMB();

        CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);
            
        test_done = 1;
        for (i = 0; i < sizeof(CC_SYS_COMM_RX_CHANNEL) / sizeof(kal_uint32); i++)
        {
            for (j = 0; j < CC_SYS_COMM_PARA_NUMBER; j++)
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
        CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
        break;
#if defined(__PCORE__)||defined(__L1CORE__)
    case CC_IRQ_SYS_COMM_IT_MD3_TO_MD1_BASIC_POLLING:
#else/* MD3 */
    case CC_IRQ_SYS_COMM_IT_MD1_TO_MD3_BASIC_POLLING:
#endif
        correct_seq_1 = cc_irq_it_2_magic[data_index][0] | cc_irq_it_2_seq[data_index][0];
        correct_seq_2 = cc_irq_it_2_magic[data_index][1] | cc_irq_it_2_seq[data_index][1];
        if (correct_seq_1 != para1 || correct_seq_2 != para2)
        {
            EXT_ASSERT(0, para1, para2, comm_id);
        }
        cc_irq_it_2_seq[data_index][0]++;
        cc_irq_it_2_seq[data_index][1]++;

        CC_IRQ_DMB();

        CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);
            
        test_done = 1;
        for (i = 0; i < sizeof(CC_SYS_COMM_RX_CHANNEL) / sizeof(kal_uint32); i++)
        {
            for (j = 0; j < CC_SYS_COMM_PARA_NUMBER; j++)
            {
                if (cc_irq_it_2_seq[i][j] != seq_max)
                {
                    test_done = 0;
                    break;
                }
            }

            if(test_done == 0)
                break;
        }
        CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
        break;
#if defined(__PCORE__)||defined(__L1CORE__)
    case CC_IRQ_SYS_COMM_IT_MD3_TO_MD1_MASK:
#else/* MD3 */
    case CC_IRQ_SYS_COMM_IT_MD1_TO_MD3_MASK:
#endif
        correct_seq_1 = cc_irq_it_2_magic[data_index][0] | cc_irq_it_2_seq[data_index][0];
        correct_seq_2 = cc_irq_it_2_magic[data_index][1] | cc_irq_it_2_seq[data_index][1];
        if (correct_seq_1 != para1 || correct_seq_2 != para2)
        {
            EXT_ASSERT(0, para1, para2, comm_id);
        }
        cc_irq_it_2_seq[data_index][0]++;
        cc_irq_it_2_seq[data_index][1]++;

        CC_IRQ_DMB();

        CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);
            
        test_done = 1;

        /* we only use first comm_id to test buffer full */
        for (j = 0; j < CC_SYS_COMM_PARA_NUMBER; j++)
        {
            if (cc_irq_it_2_seq[0][j] != seq_max)
            {
                test_done = 0;
                break;
            }
        }

        if(test_done == 0)
            break;
       
        CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
        break;		
    default:
        ASSERT(0);
    }
}

void cc_irq_sys_comm_it_cb_0(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_it_cb(0+CC_SYS_IT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_it_cb_1(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_it_cb(1+CC_SYS_IT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_it_cb_2(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_it_cb(2+CC_SYS_IT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_it_cb_3(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_it_cb(3+CC_SYS_IT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_it_cb_4(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_it_cb(4+CC_SYS_IT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_it_cb_5(kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_comm_it_cb(5+CC_SYS_IT_RX_COMM_SHIFT, para1, para2);
}

void cc_irq_sys_comm_basic_tx()
{
    kal_uint32 i, tx_ch, data_index;
    kal_int32  ret;    

    for (i = 0; i < sizeof(CC_SYS_COMM_TX_CHANNEL) / sizeof(kal_uint32); i++)
    {
        cc_sys_comm_test_channel = i;
        cc_irq_it_share_var->share_para1 = 0;
        cc_irq_it_share_var->share_para2 = 0;
        CC_IRQ_DMB();
        tx_seq = 0;
    	
        while(tx_seq < CC_IRQ_TX_SEQ_MAX)
        {
            tx_ch = CC_SYS_COMM_TX_CHANNEL[i];
            data_index = CC_SYS_COMM_TX_CHANNEL[i] - CC_SYS_IT_TX_COMM_SHIFT;			
            ret = cc_sys_comm_tx(tx_ch, cc_irq_it_2_magic[data_index][0] | tx_seq, cc_irq_it_2_magic[data_index][1] | tx_seq);
            ASSERT(ret == CC_SYS_COMM_SUCCESS);

            while(1)
            {
                if (cc_irq_it_share_var->share_para1_arr[data_index] == (cc_irq_it_2_magic[data_index][0] | tx_seq) && \
                    cc_irq_it_share_var->share_para2_arr[data_index] == (cc_irq_it_2_magic[data_index][1] | tx_seq) )
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
    kal_uint32 i, tx_ch, data_index;
    kal_int32  ret;

    tx_seq = 0;
    while(tx_seq < CC_IRQ_TX_SEQ_MAX)
    {
        for (i = 0; i < sizeof(CC_SYS_COMM_TX_CHANNEL) / sizeof(kal_uint32); i++)
        {
            tx_ch = CC_SYS_COMM_TX_CHANNEL[i];
            data_index = CC_SYS_COMM_TX_CHANNEL[i] - CC_SYS_IT_TX_COMM_SHIFT;        
            ret = cc_sys_comm_tx_polling(tx_ch, cc_irq_it_2_magic[data_index][0] | tx_seq, cc_irq_it_2_magic[data_index][1] | tx_seq);        	
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
    kal_uint32 tx_ch, data_index;
    kal_int32  ret;

    tx_seq = 0;
    while(tx_seq < CC_SYS_COMM_MASK_TEST_TX_CNT)
    {/* we only use first comm_id to test buffer full */

        tx_ch = CC_SYS_COMM_TX_CHANNEL[0];
        data_index = CC_SYS_COMM_TX_CHANNEL[0] - CC_SYS_IT_TX_COMM_SHIFT;        
        ret = cc_sys_comm_tx_polling(tx_ch, cc_irq_it_2_magic[data_index][0] | tx_seq, cc_irq_it_2_magic[data_index][1] | tx_seq);        	
        ASSERT(ret == CC_SYS_COMM_SUCCESS);
        
        tx_seq++;
    }

#if defined(__PCORE__)||defined(__L1CORE__)   
    cc_irq_it_share_var->cr4_to_md32_unmask_enable = 1;
#else/* MD3 */
    cc_irq_it_share_var->md32_to_cr4_unmask_enable = 1;
#endif
}

void cc_irq_mask_test_rx()
{

#if defined(__PCORE__)/* always test with MD3 */
    while(cc_irq_it_share_var->md32_to_cr4_unmask_enable == 0);
    ASSERT(CC_IRQ_SUCCESS==cc_irq_unmask(CC_IRQ_MD32P_SYS));
#elif defined(__L1CORE__)/* always test with MD3 */
    while(cc_irq_it_share_var->md32_to_cr4_unmask_enable == 0);
    ASSERT(CC_IRQ_SUCCESS==cc_irq_unmask(CC_IRQ_MD32L_SYS));
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */
    while(cc_irq_it_share_var->cr4_to_md32_unmask_enable == 0);
    ASSERT(CC_IRQ_SUCCESS==cc_irq_unmask(CC_IRQ_P2MD3_SYS));
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */
    while(cc_irq_it_share_var->cr4_to_md32_unmask_enable == 0);
    ASSERT(CC_IRQ_SUCCESS==cc_irq_unmask(CC_IRQ_L2MD3_SYS));
#else
#error "DEFINE ERROR"
#endif

    while(test_done == 0);
}

void cc_irq_sys_comm_it()
{/* test case for CC SYS */
    kal_uint32 i, j;

#if defined(__PCORE__)/* always test with MD3 */
    ASSERT(CC_IRQ_SUCCESS==cc_irq_mask(CC_IRQ_MD32P_SYS));
#elif defined(__L1CORE__)/* always test with MD3 */
    ASSERT(CC_IRQ_SUCCESS==cc_irq_mask(CC_IRQ_MD32L_SYS));
#elif defined(__MD3_PCORE__)/* MD3 test with PCORE */
    ASSERT(CC_IRQ_SUCCESS==cc_irq_mask(CC_IRQ_P2MD3_SYS));
#elif defined(__MD3_L1CORE__)/* MD3 test with L1CORE */
    ASSERT(CC_IRQ_SUCCESS==cc_irq_mask(CC_IRQ_L2MD3_SYS));
#else
#error "DEFINE ERROR"
#endif  
    
    for (i = 0; i < MAX_CHANNEL_SUPPORT; i++)
    {
        cc_irq_it_1_magic[i] = 0x5AF00000 | (i << 16);    //- [15:0] is reserved for sequence number;
        for (j = 0; j < 3; j++)
        {
            cc_irq_it_2_magic[i][j] = 0xFF000000 | (i << 20) | (j << 16);    //- [15:0] is reserved for sequence number;
        }
    }

    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_IT_RX_COMM_SHIFT + 0, cc_irq_sys_comm_it_cb_0));
    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_IT_RX_COMM_SHIFT + 1, cc_irq_sys_comm_it_cb_1));
//    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_IT_RX_COMM_SHIFT + 2, cc_irq_sys_comm_it_cb_2));
//    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_IT_RX_COMM_SHIFT + 3, cc_irq_sys_comm_it_cb_3));
//    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_IT_RX_COMM_SHIFT + 4, cc_irq_sys_comm_it_cb_4));
//    ASSERT(CC_SYS_COMM_SUCCESS == cc_sys_comm_channel_init(CC_SYS_IT_RX_COMM_SHIFT + 5, cc_irq_sys_comm_it_cb_5));

    //- Test 1 - basic test: MD3 send message to MD1 by “cc_sys_comm_tx”, wait process done, then trigger another time.
    cc_irq_test_case = CC_IRQ_SYS_COMM_IT_MD3_TO_MD1_BASIC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_sys_comm_basic_rx();
#else/* MD3 */
    cc_irq_sys_comm_basic_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - basic test: MD1 send message to MD3 by “cc_sys_comm_tx”, wait process done, then trigger another time.
    cc_irq_test_case = CC_IRQ_SYS_COMM_IT_MD1_TO_MD3_BASIC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_sys_comm_basic_tx();
#else/* MD3 */
    cc_irq_sys_comm_basic_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 3 - basic test: MD3 send message to MD1 by “cc_sys_comm_tx_polling”,  without wait process done.
    cc_irq_test_case = CC_IRQ_SYS_COMM_IT_MD3_TO_MD1_BASIC_POLLING;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_sys_comm_basic_polling_rx();
#else/* MD3 */
    cc_irq_sys_comm_basic_polling_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 4 - basic test: MD1 send message to MD3 by “cc_sys_comm_tx_polling”,  without wait process done.
    cc_irq_test_case = CC_IRQ_SYS_COMM_IT_MD1_TO_MD3_BASIC_POLLING;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_sys_comm_basic_polling_tx();
#else/* MD3 */
    cc_irq_sys_comm_basic_polling_rx();
#endif
    test_item_deinit(cc_irq_test_case);
    
    //- Test 5 - basic test: MD3 send message to MD1 with nested trigger count being max.
    cc_irq_test_case = CC_IRQ_SYS_COMM_IT_MD3_TO_MD1_MASK;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_mask_test_rx();
#else/* MD3 */
    cc_irq_mask_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 6 - basic test: MD1 send message to MD3 with nested trigger count being max.
    cc_irq_test_case = CC_IRQ_SYS_COMM_IT_MD1_TO_MD3_MASK;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_mask_test_tx();
#else/* MD3 */
    cc_irq_mask_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);
cc_irq_test_case_SYS_END = 1;

}


/*****************************************************************************************
CC IRQ buffer mode test
*****************************************************************************************/
#define CC_IRQ_IT_BUFF_BASIC_BUFF_LEN     12
#define CC_IRQ_BUFF_TEST_INIT_PKT_LEN     27
#define CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_LOOP    32
#define CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1    (32 - 4)
#define CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2    (64 - 4)

kal_uint8 test_buff[CC_IRQ_IT_COMMON_CHANNEL_NUMBER][CC_IRQ_BUFF_MAX + 4];

void cc_irq_it_buff_isr(kal_uint32 index, kal_uint32 addr, kal_uint32 length, kal_uint32 no_use)
{
    kal_uint32 i, savedMask;
    kal_uint8  *ptr;

    ptr = (kal_uint8*)addr;
    switch(cc_irq_test_case)
    {
#if defined(__PCORE__)||defined(__L1CORE__)
    case CC_IRQ_IT_MD3_TO_MD1_BUFF_BASIC_ACK:
    case CC_IRQ_IT_MD3_TO_MD1_BUFF_BASIC_NO_ACK:
#else/* MD3 */
    case CC_IRQ_IT_MD1_TO_MD3_BUFF_BASIC_ACK:
    case CC_IRQ_IT_MD1_TO_MD3_BUFF_BASIC_NO_ACK:
#endif
        {
            ASSERT(length == CC_IRQ_IT_BUFF_BASIC_BUFF_LEN);
            ASSERT(ptr != NULL);
            
            if (*(ptr + 0) != ((kal_uint8)index & 0xFF) || \
            	  *(ptr + 1) != 0xFF || \
            	  *(ptr + 2) != (cc_irq_it_2_seq[index][0] & 0xFF) || \
            	  *(ptr + 3) != ((cc_irq_it_2_seq[index][0] >> 8) & 0xFF))
            {
                ASSERT(0);
            }
            for (i = 4; i < CC_IRQ_IT_BUFF_BASIC_BUFF_LEN; i++)
            {
                if (*(ptr + i) != (index & 0xFF))
                    ASSERT(0);
            }
            cc_irq_it_2_seq[index][0]++;
            
            CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);
            test_done = 1;
            for (i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[i][0] != CC_IRQ_TX_SEQ_MAX)
                {
                    test_done = 0;
                    break;
                }
            }
            CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
#if defined(__PCORE__)||defined(__L1CORE__)
            cc_irq_it_share_var->md32_to_cr4_tx_notify = 1;
#else/* MD3 */
            cc_irq_it_share_var->cr4_to_md32_tx_notify = 1;
#endif
        }
        break;
#if defined(__PCORE__)||defined(__L1CORE__)
    case CC_IRQ_IT_MD3_TO_MD1_BUFF_VAR_LEN_ACK:
    case CC_IRQ_IT_MD3_TO_MD1_BUFF_VAR_LEN_NO_ACK:
#else/* MD3 */
    case CC_IRQ_IT_MD1_TO_MD3_BUFF_VAR_LEN_ACK:
    case CC_IRQ_IT_MD1_TO_MD3_BUFF_VAR_LEN_NO_ACK:
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
            
            CC_IRQ_DRV_MASK_ALL_INTERRUPT(savedMask);
            test_done = 1;
            for (i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[i][0] != CC_IRQ_BUFF_MAX - CC_IRQ_BUFF_TEST_INIT_PKT_LEN + 1)
                {
                    test_done = 0;
                    break;
                }
            }
            CC_IRQ_DRV_RESTORE_ALL_INTERRUPT(savedMask);
#if defined(__PCORE__)||defined(__L1CORE__)
            cc_irq_it_share_var->md32_to_cr4_tx_notify = 1;
#else/* MD3 */
            cc_irq_it_share_var->cr4_to_md32_tx_notify = 1;
#endif
        }
        break;
#if defined(__PCORE__)||defined(__L1CORE__)
        case CC_IRQ_IT_MD3_TO_MD1_BUFF_COMB:
#else/* MD3 */
        case CC_IRQ_IT_MD1_TO_MD3_BUFF_COMB:
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
            for (i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[i][1] != 3)
                {
                    test_done = 0;
                    break;
                }
            }
        }
        break;        
    default:
        ASSERT(0);
    }
}

void cc_irq_buff_basic_test_tx(kal_uint32 wait_rx_ack)
{
    kal_uint32 i, j;
    kal_int32  ret;

    for(i = shift_cc_sys; i < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; i++)
    {
        /* prepare buffer */
        test_buff[i][0] = i & 0xFF;        
        test_buff[i][1] = 0xFF;
        
        for(j = 4; j < CC_IRQ_IT_BUFF_BASIC_BUFF_LEN;j++)
            test_buff[i][j] = i & 0xFF;
    	
        tx_seq = 0;
        while(tx_seq < CC_IRQ_TX_SEQ_MAX)
        {
            test_buff[i][2] = tx_seq & 0xFF;
            test_buff[i][3] = (tx_seq >> 8) & 0xFF;

            if (wait_rx_ack == 1)
            {
#if defined(__PCORE__)||defined(__L1CORE__)
                cc_irq_it_share_var->cr4_to_md32_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(i + CC_IRQ_IT_TX_IRQ_SHIFT, (void*)test_buff[i], CC_IRQ_IT_BUFF_BASIC_BUFF_LEN);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(cc_irq_it_share_var->cr4_to_md32_tx_notify == 0);
#else/* MD3 */
                cc_irq_it_share_var->md32_to_cr4_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(i + CC_IRQ_IT_TX_IRQ_SHIFT, (void*)test_buff[i], CC_IRQ_IT_BUFF_BASIC_BUFF_LEN);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(cc_irq_it_share_var->md32_to_cr4_tx_notify == 0);
#endif
            }
            else
            {
                while(1)
                {
                    if(cc_irq_buffer_channel_full(i + CC_IRQ_IT_TX_IRQ_SHIFT)||cc_irq_param_channel_full(i + CC_IRQ_IT_TX_IRQ_SHIFT))
                    {
                        /*wait*/
                    }
                    else
                    {
                        ret = cc_irq_trigger_interrupt_with_buff(i + CC_IRQ_IT_TX_IRQ_SHIFT, (void*)test_buff[i], CC_IRQ_IT_BUFF_BASIC_BUFF_LEN);

						if (ret == CC_IRQ_SUCCESS)
                            break;
                        else
                            ASSERT(0);
                    }					
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

    for (chl = 0; chl < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; chl++)
    {
        kal_mem_set((void*)test_buff[chl], (kal_uint8)(chl & 0xFF), CC_IRQ_BUFF_MAX);
    }

    for (pkt_len = CC_IRQ_BUFF_TEST_INIT_PKT_LEN; pkt_len <= CC_IRQ_BUFF_MAX; pkt_len++)
    {
        /* prepare packet */
        for (chl = 0; chl < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; chl++)
        {
            /* recover previous end mark to index */
            test_buff[chl][pkt_len - 2] = (chl & 0xFF);
        	
            test_buff[chl][0] = (kal_uint8)(pkt_len & 0xFF);
            test_buff[chl][1] = (kal_uint8)((pkt_len >> 8) & 0xFF);
            test_buff[chl][pkt_len - 1] = 0xFF;    /* end mark */
        }
        
        for (chl = shift_cc_sys; chl < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; chl++)
        {
            if (wait_rx_ack == 1)
            {
#if defined(__PCORE__)||defined(__L1CORE__)
                cc_irq_it_share_var->cr4_to_md32_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_IT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(cc_irq_it_share_var->cr4_to_md32_tx_notify == 0);
#else/* MD3 */
                cc_irq_it_share_var->md32_to_cr4_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_IT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(cc_irq_it_share_var->md32_to_cr4_tx_notify == 0);
#endif                    
            }
            else
            {
                while(1)
                {
                    if(cc_irq_buffer_channel_full(chl + CC_IRQ_IT_TX_IRQ_SHIFT)||cc_irq_param_channel_full(chl + CC_IRQ_IT_TX_IRQ_SHIFT))
                    {
                        /*wait*/
                    }
                    else
                    {
                        ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_IT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);

						if (ret == CC_IRQ_SUCCESS)
                            break;
                        else
                            ASSERT(0);
                    }					             
                }
            }
        }
    }
}

void cc_irq_buff_var_len_rx()
{
    while(test_done == 0);
}

void cc_irq_buff_pccif_comb_tx()
{
    kal_uint32 chl;
    kal_int32  ret;
	
    for (chl = 0; chl < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; chl++)
    {
        kal_mem_set((void*)test_buff[chl], (kal_uint8)(chl & 0xFF), CC_IRQ_BUFF_MAX);
        test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 + 3 - 1] = 0xFF;
    }	
    
    for (chl = shift_cc_sys; chl < CC_IRQ_IT_COMMON_CHANNEL_NUMBER; chl++)
    {
        for (pkt_start = 1; pkt_start <= 3; pkt_start++)
        {
            for (pkt_len = CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 3; pkt_len <= CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 + 3; pkt_len++)
            {
                test_buff[chl][pkt_start] = (kal_uint8)(pkt_len & 0xFF);
                test_buff[chl][pkt_start + pkt_len - 1] = 0xFF;
                while(1)
                {
                    if(cc_irq_buffer_channel_full(chl + CC_IRQ_IT_TX_IRQ_SHIFT)||cc_irq_param_channel_full(chl + CC_IRQ_IT_TX_IRQ_SHIFT))
                    {
                        /*wait*/
                    }
                    else
                    {
                        ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_IT_TX_IRQ_SHIFT, (void*)test_buff[chl] + pkt_start, pkt_len);

						if (ret == CC_IRQ_SUCCESS)
                            break;
                        else
                            ASSERT(0);
                    }					                
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
    cc_irq_it_buff_test = 1;

    //- Test 1 - MD3 triggers interrupt to MD1 with buffer length 12 and wait process done, then trigger another time, for all the CC IRQ sequentially.
    cc_irq_test_case = CC_IRQ_IT_MD3_TO_MD1_BUFF_BASIC_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_buff_basic_test_rx();
#else/* MD3 */
    cc_irq_buff_basic_test_tx(1);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - MD1 triggers interrupt to MD3 with buffer length 12 and wait process done, then trigger another time, for all the CC IRQ sequentially.
    cc_irq_test_case = CC_IRQ_IT_MD1_TO_MD3_BUFF_BASIC_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_buff_basic_test_tx(1);
#else/* MD3 */
    cc_irq_buff_basic_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 3 - MD3 triggers interrupt to MD1 with buffer length 12 and without wait process done, then trigger another time, for all the CC IRQ sequentially.

    cc_irq_test_case = CC_IRQ_IT_MD3_TO_MD1_BUFF_BASIC_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_buff_basic_test_rx();
#else/* MD3 */
    cc_irq_buff_basic_test_tx(0);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 4 - MD1 triggers interrupt to MD3 with buffer length 12 and without wait process done, then trigger another time, for all the CC IRQ sequentially.
    cc_irq_test_case = CC_IRQ_IT_MD1_TO_MD3_BUFF_BASIC_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_buff_basic_test_tx(0);
#else/* MD3 */
    cc_irq_buff_basic_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 5 - MD3 triggers interrupt to MD1 with buffer length variable and wait process done, then trigger another time for all the CC IRQ sequentially.
    cc_irq_test_case = CC_IRQ_IT_MD3_TO_MD1_BUFF_VAR_LEN_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_buff_var_len_rx();
#else/* MD3 */
    cc_irq_buff_var_len_tx(1);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 6 - MD1 triggers interrupt to MD3 with buffer length variable and wait process done, then trigger another time for all the CC IRQ sequentially.
    cc_irq_test_case = CC_IRQ_IT_MD1_TO_MD3_BUFF_VAR_LEN_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_buff_var_len_tx(1);
#else/* MD3 */
    cc_irq_buff_var_len_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 7 - MD3 triggers interrupt to MD1 with buffer length variable and without wait process done, then trigger another time for all the CC IRQ sequentially.
    cc_irq_test_case = CC_IRQ_IT_MD3_TO_MD1_BUFF_VAR_LEN_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_buff_var_len_rx();
#else/* MD3 */
    cc_irq_buff_var_len_tx(0);
#endif
    test_item_deinit(cc_irq_test_case);
    
    //- Test 8 - MD1 triggers interrupt to MD3 with buffer length variable and without wait process done, then trigger another time for all the CC IRQ sequentially.
    cc_irq_test_case = CC_IRQ_IT_MD1_TO_MD3_BUFF_VAR_LEN_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_buff_var_len_tx(0);
#else/* MD3 */
    cc_irq_buff_var_len_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 9 - combination of different start address and packet length (mod 4 = 0, mod 4 = 1, mod 4 = 2, mod 4 = 3), MD3 to MD1
    cc_irq_test_case = CC_IRQ_IT_MD3_TO_MD1_BUFF_COMB;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_buff_pccif_comb_rx();
#else/* MD3 */
    cc_irq_buff_pccif_comb_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 10 - combination of different start address and packet length (mod 4 = 0, mod 4 = 1, mod 4 = 2, mod 4 = 3), MD1 to MD3
    cc_irq_test_case = CC_IRQ_IT_MD1_TO_MD3_BUFF_COMB;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_buff_pccif_comb_tx();
#else/* MD3 */
    cc_irq_buff_pccif_comb_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    cc_irq_it_buff_test = 0;
    cc_irq_test_case_BUFF_END = 1;
}


/*****************************************************************************************
CC IRQ ILM test
*****************************************************************************************/
#define CC_IRQ_MSG_IT_BASIC_LP_LEN      32
#define CC_IRQ_MSG_IT_BASIC_LP_P_LEN    (CC_IRQ_MSG_IT_BASIC_LP_LEN - sizeof(local_para_struct))
#define CC_IRQ_MSG_IT_VAR_LEN_MAX       (2048 - 4)/* why we need -4 ??*/
#define CC_IRQ_MSG_IT_QUE_PKT_MAX       2048
#define CC_IRQ_MSG_IT_TX_SKT_NUM        16
#define CC_IRQ_MSG_TIME_PROFILE_ITER    32

#if defined(KAL_ILM)
kal_uint32 cc_irq_it_msg_check_ilm = 0;
#else
kal_uint32 cc_irq_it_msg_check_ilm = 1;
#endif
kal_uint32 cc_irq_it_msg_con_tested[CC_IRQ_MSG_IT_TX_SKT_NUM];

CC_IRQ_INTSRAM_ZI kal_uint32 dbg_enter_cnt;

void cc_irq_ut_msg_isr(ilm_struct *ilm_ptr)	
{/* If you change this name, you should also change it in "cc_irq_msg.c"*/
    kal_uint32 i;
    kal_uint8  *buf_ptr;
    
    if (cc_irq_it_msg_check_ilm)
    {
        ASSERT(ilm_ptr->dest_mod_id == (0xFFFF - cc_irq_it_seq[0]));
        //ASSERT(ilm_ptr->sap_id     == (0xAA00 | (cc_irq_it_seq[0] % 0x100)));/* MD3 don't support */
        ASSERT(ilm_ptr->msg_id     == (0x5500 | (cc_irq_it_seq[0] >> 8)));
    }

    if (ilm_ptr->local_para_ptr!=NULL)
    {    
        ASSERT(ilm_ptr->local_para_ptr-> ref_count == 1);
    } 
	
    switch(cc_irq_test_case)
    {
#if defined(__PCORE__)||defined(__L1CORE__)
    case CC_IRQ_MSG_IT_MD3_TO_MD1_BASIC:
#else/* MD3 */
    case CC_IRQ_MSG_IT_MD1_TO_MD3_BASIC:
#endif
        {
            EXT_ASSERT(ilm_ptr->local_para_ptr->msg_len == CC_IRQ_MSG_IT_BASIC_LP_LEN, ilm_ptr->local_para_ptr->msg_len, 0, 0);
            
            for (i = 0; i < CC_IRQ_MSG_IT_BASIC_LP_P_LEN; i++)
            {
                buf_ptr = (kal_uint8*)(ilm_ptr->local_para_ptr) + sizeof(local_para_struct) + i;
                if (i == (cc_irq_it_seq[0] % CC_IRQ_MSG_IT_BASIC_LP_P_LEN))
                {
                    ASSERT(*buf_ptr == 0xFF);
                }
                else
                {
                    ASSERT(*buf_ptr == 0xCC);
                }
            }
			
#if defined(KAL_ILM)&&(defined(__PCORE__)||defined(__L1CORE__))/* test CC MSG from KAL layer in MD1 */
            ASSERT(KAL_TRUE == kal_cc_irq_msg_send(ilm_ptr));
#endif
			
            cc_irq_it_seq[0]++;
            if (cc_irq_it_seq[0] == (CC_IRQ_TX_SEQ_MAX+1))
                test_done = 1;
        }
        break;
#if defined(__PCORE__)||defined(__L1CORE__)
    case CC_IRQ_MSG_IT_MD3_TO_MD1_VAR_LEN:
#else/* MD3 */
    case CC_IRQ_MSG_IT_MD1_TO_MD3_VAR_LEN:
#endif
        {
            kal_uint8 pattern = cc_irq_it_seq[0] & 0xFF;

            if (ilm_ptr->local_para_ptr!=NULL)/* there may be no user data, so local_para_ptr would be NULL */
            { 
			
                ASSERT(cc_irq_it_seq[0] + sizeof(local_para_struct) == ilm_ptr->local_para_ptr->msg_len);
            
                for (i = 0; i < ilm_ptr->local_para_ptr->msg_len - sizeof(local_para_struct); i++)
                {
                    ASSERT(*((kal_uint8*)(ilm_ptr->local_para_ptr) + sizeof(local_para_struct) + i) == pattern);
                }
            }
#if defined(KAL_ILM)&&(defined(__PCORE__)||defined(__L1CORE__))/* test CC MSG from KAL layer in MD1 */
            ASSERT(KAL_TRUE == kal_cc_irq_msg_send(ilm_ptr));
#endif

            if (cc_irq_it_seq[0] == CC_IRQ_MSG_IT_VAR_LEN_MAX - sizeof(local_para_struct))
                test_done = 1;
            
            cc_irq_it_seq[0]++;
        }
    break;
#if 0	
#if defined(__PCORE__)||defined(__L1CORE__)
/* under construction !*/
#else/* MD3 */
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__PCORE__)||defined(__L1CORE__)
/* under construction !*/
#else/* MD3 */
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif		
    default:
        {
            ASSERT(0);
        }
    }
}

void cc_irq_msg_var_len_tx()
{
    local_para_struct *test_ptr;
	ilm_struct ilm_ptr;
    
    for (tx_seq = 0; tx_seq <= CC_IRQ_MSG_IT_VAR_LEN_MAX - sizeof(local_para_struct); tx_seq++)
    {
        test_ptr = (local_para_struct *)construct_local_para(tx_seq + sizeof(local_para_struct), 0);
        kal_mem_set((void*)test_ptr + sizeof(local_para_struct), tx_seq & 0xFF, tx_seq);
#if defined(KAL_ILM)
        ilm_ptr.src_mod_id = SRC_MOD_ID;
        ilm_ptr.dest_mod_id = DST_MOD_ID;
        ilm_ptr.sap_id = 0xAA00 | (tx_seq % 0x100);
        ilm_ptr.msg_id = 0x5500 | (tx_seq >> 8);
        ilm_ptr.local_para_ptr = (local_para_struct*)test_ptr;
        ilm_ptr.peer_buff_ptr = NULL;		
  #if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */	
        msg_send5(ilm_ptr.src_mod_id, ilm_ptr.dest_mod_id, ilm_ptr.sap_id, ilm_ptr.msg_id,
                   ilm_ptr.local_para_ptr);
  #elif defined(__MD3_PCORE__)||defined(__MD3_L1CORE__)
        msg_send5(ilm_ptr.src_mod_id, ilm_ptr.dest_mod_id, ilm_ptr.sap_id, ilm_ptr.msg_id,
                   ilm_ptr.local_para_ptr);  
  #endif
  
#else
        ilm_ptr.src_mod_id = tx_seq & 0xFFFF;
        ilm_ptr.dest_mod_id = 0xFFFF - tx_seq;
        ilm_ptr.sap_id = 0xAA00 | (tx_seq % 0x100);
        ilm_ptr.msg_id = 0x5500 | (tx_seq >> 8);
        ilm_ptr.local_para_ptr = (local_para_struct*)test_ptr;
        ilm_ptr.peer_buff_ptr = NULL;

        cc_irq_msg_send(&ilm_ptr);
        free_local_para(test_ptr);
#endif		
    }
}

void cc_irq_msg_var_len_rx()
{
    while(test_done == 0);
}

void cc_irq_msg_basic_tx()
{
    local_para_struct *test_ptr;
    kal_uint8         *buf_ptr;
	ilm_struct ilm_ptr;
	
    for (tx_seq = 0; tx_seq <= CC_IRQ_TX_SEQ_MAX; tx_seq++)
    {
        test_ptr = (local_para_struct *)construct_local_para(CC_IRQ_MSG_IT_BASIC_LP_LEN, 0);
        kal_mem_set((void*)test_ptr + sizeof(local_para_struct), 0xCC, CC_IRQ_MSG_IT_BASIC_LP_P_LEN);
    	
        buf_ptr = (kal_uint8*)test_ptr + sizeof(local_para_struct) + tx_seq % CC_IRQ_MSG_IT_BASIC_LP_P_LEN;
        *buf_ptr = 0xFF;
#if defined(KAL_ILM)
        ilm_ptr.src_mod_id = SRC_MOD_ID;
        ilm_ptr.dest_mod_id = DST_MOD_ID;
        ilm_ptr.sap_id = 0xAA00 | (tx_seq % 0x100);
        ilm_ptr.msg_id = 0x5500 | (tx_seq >> 8);
        ilm_ptr.local_para_ptr = (local_para_struct*)test_ptr;
        ilm_ptr.peer_buff_ptr = NULL;
  #if defined(__PCORE__)||defined(__L1CORE__)/* always test with MD3 */	
        msg_send5(ilm_ptr.src_mod_id, ilm_ptr.dest_mod_id, ilm_ptr.sap_id, ilm_ptr.msg_id,
                   ilm_ptr.local_para_ptr);
  #elif defined(__MD3_PCORE__)||defined(__MD3_L1CORE__)/* Linag 請看是否修改*/
        msg_send5(ilm_ptr.src_mod_id, ilm_ptr.dest_mod_id, ilm_ptr.sap_id, ilm_ptr.msg_id,
                   ilm_ptr.local_para_ptr);  
  #endif
  
#else
        ilm_ptr.src_mod_id = tx_seq & 0xFFFF;
        ilm_ptr.dest_mod_id = 0xFFFF - tx_seq;
        ilm_ptr.sap_id = 0xAA00 | (tx_seq % 0x100);
        ilm_ptr.msg_id = 0x5500 | (tx_seq >> 8);
        ilm_ptr.local_para_ptr = (local_para_struct*)test_ptr;
        ilm_ptr.peer_buff_ptr = NULL;

        cc_irq_msg_send(&ilm_ptr);
        free_local_para(test_ptr);
#endif		
    }
}

void cc_irq_msg_basic_rx()
{
    while(test_done == 0);
}

kal_uint8 cc_irq_msg_it_pkt_que[CC_IRQ_MSG_IT_QUE_PKT_MAX][CC_IRQ_BUFF_MAX];
kal_uint32 cc_irq_msg_it_pkt_len[CC_IRQ_MSG_IT_QUE_PKT_MAX];
kal_uint8 cc_irq_msg_it_pkt_used[CC_IRQ_MSG_IT_QUE_PKT_MAX];
kal_uint32 cc_irq_msg_it_skt_start[CC_IRQ_MSG_IT_TX_SKT_NUM];
kal_uint32 cc_irq_msg_it_skt_end[CC_IRQ_MSG_IT_TX_SKT_NUM];
kal_uint32 cc_irq_msg_it_pkt_ptr = 0;

void cc_irq_msg_con_skt_tx()
{
    kal_uint32 i, j, pkt_per_msg;
    local_para_struct *msg;
	ilm_struct ilm_ptr;    
	
    for(i = 0; i < CC_IRQ_MSG_IT_QUE_PKT_MAX; i++)
        cc_irq_msg_it_pkt_used[i] = 0;
    
    cc_irq_msg_it_pkt_ptr = 0;
    
    for (i = 0; i < CC_IRQ_MSG_IT_TX_SKT_NUM; i++)
    {
        msg = (local_para_struct *)construct_local_para(CC_IRQ_MSG_IT_VAR_LEN_MAX + sizeof(local_para_struct), 0);
        for (j = 0; j < CC_IRQ_MSG_IT_VAR_LEN_MAX - sizeof(local_para_struct); j+= 4)
        {
            *(kal_uint32*)((kal_uint32)msg + sizeof(local_para_struct) + j) = 0x88000000 | ((i & 0xFF) << 16) | j;
        }
        cc_irq_msg_it_skt_start[i] = cc_irq_msg_it_pkt_ptr;

        ilm_ptr.src_mod_id = 0x5555;
        ilm_ptr.dest_mod_id = 0xAAAA;
        ilm_ptr.sap_id = 0xFFFF;
        ilm_ptr.msg_id = 0x0000;
        ilm_ptr.local_para_ptr = msg;
        ilm_ptr.peer_buff_ptr = NULL;

        cc_irq_msg_send(&ilm_ptr);
        free_local_para(msg);
        cc_irq_msg_it_skt_end[i] = cc_irq_msg_it_pkt_ptr - 1;
    }
    
    pkt_per_msg = cc_irq_msg_it_skt_end[0] - cc_irq_msg_it_skt_start[0] + 1;
    ASSERT(pkt_per_msg != 0);
    
    for (i = 1; i < CC_IRQ_MSG_IT_TX_SKT_NUM; i++)
    {
        ASSERT(cc_irq_msg_it_skt_end[i] - cc_irq_msg_it_skt_start[i] + 1 == pkt_per_msg);
    }

    for (i = 0; i < pkt_per_msg; i++)
    {
        for (j = 0; j < CC_IRQ_MSG_IT_TX_SKT_NUM; j++)
        {
            kal_uint32 pkt_index = cc_irq_msg_it_skt_start[j] + i;
          
            cc_irq_trigger_interrupt_with_buff(CC_IRQ_MSG_TX_INDEX, (void*)cc_irq_msg_it_pkt_que[pkt_index], cc_irq_msg_it_pkt_len[pkt_index]);
        }
    }
}

__attribute__ ((section ("INTSRAM_ROCODE"))) 
void cc_irq_ut_msg_time_isr_log()
{
    msg_time_profile_proc_rx_lisr = CC_IRQ_GET_US();
}

void cc_irq_msg_con_skt_rx()
{
    cc_irq_it_msg_check_ilm = 0;
    cc_irq_unmask(CC_IRQ_MSG_RX_INDEX);
    while(test_done == 0);
}

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__L1CORE__)        
/* under construction !*/
#else
/* under construction !*/
#endif
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
/* under construction !*/
#if defined(__L1CORE__)
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif
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
#endif
void cc_irq_msg_it()
{
//extern void cc_sys_comm_init();
//    cc_sys_comm_init();

    //- Test 1 - MD3 send a ILM with 32 bytes length to MD1
    cc_irq_test_case = CC_IRQ_MSG_IT_MD3_TO_MD1_BASIC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_msg_basic_rx();
#else/* MD3 */
    cc_irq_msg_basic_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - MD1 send a ILM with 32 bytes length to MD3
    cc_irq_test_case = CC_IRQ_MSG_IT_MD1_TO_MD3_BASIC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_msg_basic_tx();
#else/* MD3 */
    cc_irq_msg_basic_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 3 - MD3 send a ILM with variable length to MD1
    cc_irq_test_case = CC_IRQ_MSG_IT_MD3_TO_MD1_VAR_LEN;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_msg_var_len_rx();
#else/* MD3 */
    cc_irq_msg_var_len_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 4 - MD1 send a ILM with variable length to MD3
    cc_irq_test_case = CC_IRQ_MSG_IT_MD1_TO_MD3_VAR_LEN;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_msg_var_len_tx();
#else/* MD3 */
    cc_irq_msg_var_len_rx();
#endif
    test_item_deinit(cc_irq_test_case);

/*
    //- Test 7 - L1CORE send ILM to PCORE with concurrently
    cc_irq_test_case = CC_IRQ_UT_L12PS_MSG_CON_TX;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_msg_con_skt_rx();
#else
    cc_irq_msg_con_skt_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 8 - PCORE send ILM to L1CORE with concurrently
    cc_irq_test_case = CC_IRQ_UT_PS2L1_MSG_CON_TX;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_msg_con_skt_tx();
#else
    cc_irq_msg_con_skt_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 9 - Time profile: MD3->MD1, length: 128B
    cc_irq_test_case = CC_IRQ_UT_L12PS_MSG_TIME_PROFILE_LEN1;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_msg_time_profile_rx(0);
#else
    cc_irq_msg_time_profile_tx(128, 0);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 10 - Time profile: MD1->MD3, length: 128B
    cc_irq_test_case = CC_IRQ_UT_PS2L1_MSG_TIME_PROFILE_LEN1;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
        cc_irq_msg_time_profile_tx(128, 0);
#else
        cc_irq_msg_time_profile_rx(0);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 11 - Time profile: MD3->MD1, length: 128B
    cc_irq_test_case = CC_IRQ_UT_L12PS_MSG_TIME_PROFILE_LEN2;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
        cc_irq_msg_time_profile_rx(1);
#else
        cc_irq_msg_time_profile_tx(1024, 1);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 12 - Time profile: MD3->MD1, length: 128B
    cc_irq_test_case = CC_IRQ_UT_L12PS_MSG_TIME_PROFILE_LEN2;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__PCORE__)
    cc_irq_msg_time_profile_rx(1);
#else
    cc_irq_msg_time_profile_tx(1024, 1);
#endif
    test_item_deinit(cc_irq_test_case);
*/
    cc_irq_test_case_ILM_END = 1;
}

/*****************************************************************************************
CC IRQ RPC test
*****************************************************************************************/
kal_int32 ret_value;
#define ARRAY_NUM 254
typedef struct RPC_STRUCT
{
    kal_int32 aa;
    kal_uint32 num;	
    kal_int32 bb[5];
} RPC_T;

typedef struct RPC_MAX_STRUCT
{
    kal_int32 aa;      /* 4B */
    kal_uint32 num;	   /* 4B */
    kal_int32 bb[ARRAY_NUM]; /* 254*4=1016 */
} RPC_MAX_T;

void cc_irq_rpc_rx()
{
    while(test_done == 0);
}

void cc_irq_rpc_tx()
{
    kal_int32 ret = 0, i, bb_sum = 0;
	RPC_T     input_para;

    input_para.aa = 0; 
    input_para.num = 5;	
    for(i=0; i<5;i++)
    {
        input_para.bb[i] = i;
        bb_sum = bb_sum + i;
    }
	
    switch(cc_irq_test_case)
    {
        case CC_IRQ_RPC_IT_MD3_TO_MD1_NOIN_NOOUT:
        case CC_IRQ_RPC_IT_MD1_TO_MD3_NOIN_NOOUT:
            for (tx_seq = 0; tx_seq <= CC_IRQ_TX_SEQ_MAX; tx_seq++)
            {
                ret = cc_irq_rpc_call(CC_IRQ_UT_TX_RPC_SHIFT + 0, 0, NULL, 0, NULL);

                ASSERT(tx_seq == ret);
            }
            break;
        case CC_IRQ_RPC_IT_MD3_TO_MD1_IN_NOOUT:
        case CC_IRQ_RPC_IT_MD1_TO_MD3_IN_NOOUT:
            for (tx_seq = 0; tx_seq <= CC_IRQ_TX_SEQ_MAX; tx_seq++)
            {
                input_para.aa = tx_seq;
                ret = cc_irq_rpc_call(CC_IRQ_UT_TX_RPC_SHIFT + 1, sizeof(RPC_T), &input_para, 0, NULL);

                ASSERT(tx_seq == ret);
            }
            break;
        case CC_IRQ_RPC_IT_MD3_TO_MD1_IN_OUT:
        case CC_IRQ_RPC_IT_MD1_TO_MD3_IN_OUT:
            for (tx_seq = 0; tx_seq <= CC_IRQ_TX_SEQ_MAX; tx_seq++)
            {

                input_para.aa = tx_seq;
                /* we also use the address of input parameters to put output parameters */
                ret = cc_irq_rpc_call(CC_IRQ_UT_TX_RPC_SHIFT + 2, sizeof(RPC_T), &input_para, sizeof(kal_int32)*5, input_para.bb);

                EXT_ASSERT((tx_seq + bb_sum) == ret, tx_seq, ret, bb_sum);

                ASSERT(input_para.aa == tx_seq);/* no change */
                ASSERT(input_para.num == 5);/* no change */				
                ASSERT(input_para.bb[0] == 111);				
                ASSERT(input_para.bb[1] == 111);
                ASSERT(input_para.bb[2] == 111);
                ASSERT(input_para.bb[3] == 111);				
                ASSERT(input_para.bb[4] == 111);

                for(i=0; i<5;i++)
                {/* re-init*/
                    input_para.bb[i] = i;
                }
            }
            break;
        default:
            ASSERT(0);
            break;
			
    }

}

RPC_MAX_T     input_para_g;/* due to stack size of task is not enough, we use global parameter to test max RPC */
void cc_irq_rpc_tx_max()
{
    kal_uint32 ret = 0, i, bb_sum = 0;

    switch(cc_irq_test_case)
    {
        case CC_IRQ_RPC_IT_MD3_TO_MD1_IN_OUT_MAX:
        case CC_IRQ_RPC_IT_MD1_TO_MD3_IN_OUT_MAX:
            for (tx_seq = 0; tx_seq <= CC_IRQ_TX_SEQ_MAX; tx_seq++)
            {
                //do{
                    input_para_g.aa = tx_seq;
                    bb_sum = 0;
                    input_para_g.num = ARRAY_NUM;	
                    for(i=0; i<input_para_g.num;i++)
                    {/* re-init*/
                        input_para_g.bb[i] = i;
                        bb_sum = bb_sum + i;
                    }
					
                    /* we also use the address of input parameters to put output parameters */
                    ret = cc_irq_rpc_call(CC_IRQ_UT_TX_RPC_SHIFT + 3, sizeof(RPC_MAX_T), &input_para_g, sizeof(RPC_MAX_T), &input_para_g);
                //}while(ret == CC_IRQ_RPC_SHRAE_BUFFER_FULL);

                EXT_ASSERT((tx_seq + bb_sum) == ret, tx_seq, ret, bb_sum);

                ASSERT(input_para_g.aa == tx_seq);/* no change */
                ASSERT(input_para_g.bb[0] == 111);				
                ASSERT(input_para_g.bb[1] == 111);
                ASSERT(input_para_g.bb[2] == 111);
                ASSERT(input_para_g.bb[3] == 111);				
                ASSERT(input_para_g.bb[ARRAY_NUM-1] == 111);
            }
            break;
        default:
            ASSERT(0);
            break;
			
    }

}

kal_int32 test_func(kal_int32 aa, kal_uint32 num, kal_int32 * bb)
{
    kal_int32 i, sum = 0 ;

    for(i=0; i<num;i++)
    {
        sum = sum + bb[i];
    }
	
    for(i=0; i<num;i++)
    {
        bb[i] = 111;
    }
	
    return aa+sum;
}

void rpc_test_func_no_input_no_output(kal_uint32 rpc_buffer_index)
{ /* no input and output parameters , only return value */
    ASSERT(cc_irq_rpc_put_output_param(rpc_buffer_index, cc_irq_it_seq[0], 0, NULL) == CC_IRQ_RPC_SUCCESS);
	
    cc_irq_it_seq[0]++;
    if (cc_irq_it_seq[0] == (CC_IRQ_TX_SEQ_MAX+1))
        test_done = 1;
} 

void rpc_test_func_with_input_no_output(kal_uint32 rpc_buffer_index)
{/* with input but no output parameters , return the input value */
    RPC_T rpc_input;
    ASSERT(cc_irq_rpc_get_input_param(rpc_buffer_index, sizeof(RPC_T), &rpc_input) == CC_IRQ_RPC_SUCCESS);
	ret_value = rpc_input.aa;
    ASSERT(cc_irq_rpc_put_output_param(rpc_buffer_index, ret_value, 0, NULL) == CC_IRQ_RPC_SUCCESS);
	
    cc_irq_it_seq[0]++;
    if (cc_irq_it_seq[0] == (CC_IRQ_TX_SEQ_MAX+1))
        test_done = 1;
}

void rpc_test_func_with_input_with_output(kal_uint32 rpc_buffer_index)
{/* with input and output parameters , return the ... */
    RPC_T rpc_input;
    ASSERT(cc_irq_rpc_get_input_param(rpc_buffer_index, sizeof(RPC_T), &rpc_input) == CC_IRQ_RPC_SUCCESS);
    ret_value = test_func(rpc_input.aa, rpc_input.num, rpc_input.bb);
    ASSERT(cc_irq_rpc_put_output_param(rpc_buffer_index, ret_value, sizeof(kal_int32)*5, rpc_input.bb) == CC_IRQ_RPC_SUCCESS);

    cc_irq_it_seq[0]++;
    if (cc_irq_it_seq[0] == (CC_IRQ_TX_SEQ_MAX+1))
        test_done = 1;
}

void rpc_test_func_with_input_with_output_max(kal_uint32 rpc_buffer_index)
{/* with input and output parameters , return the ... */
    RPC_MAX_T rpc_input, rpc_output;
    ASSERT(cc_irq_rpc_get_input_param(rpc_buffer_index, sizeof(RPC_MAX_T), &rpc_input) == CC_IRQ_RPC_SUCCESS);
    ret_value = test_func(rpc_input.aa, rpc_input.num, rpc_input.bb);
    kal_mem_cpy(&rpc_output, &rpc_input, sizeof(RPC_MAX_T));
    ASSERT(cc_irq_rpc_put_output_param(rpc_buffer_index, ret_value, sizeof(RPC_MAX_T), &rpc_output) == CC_IRQ_RPC_SUCCESS);

    cc_irq_it_seq[0]++;
    if (cc_irq_it_seq[0] == (CC_IRQ_TX_SEQ_MAX+1))
        test_done = 1;
}

void cc_irq_rpc_it()
{
    /* Register all RPC function */
    ASSERT(cc_irq_rpc_register_callback(CC_IRQ_UT_RX_RPC_SHIFT + 0, rpc_test_func_no_input_no_output) == CC_IRQ_RPC_SUCCESS);
    ASSERT(cc_irq_rpc_register_callback(CC_IRQ_UT_RX_RPC_SHIFT + 1, rpc_test_func_with_input_no_output) == CC_IRQ_RPC_SUCCESS);
    ASSERT(cc_irq_rpc_register_callback(CC_IRQ_UT_RX_RPC_SHIFT + 2, rpc_test_func_with_input_with_output) == CC_IRQ_RPC_SUCCESS); 
    ASSERT(cc_irq_rpc_register_callback(CC_IRQ_UT_RX_RPC_SHIFT + 3, rpc_test_func_with_input_with_output_max) == CC_IRQ_RPC_SUCCESS);
	
    //- Test 1 - MD3 send a RPC with no input and output parameters to PCORE
    cc_irq_test_case = CC_IRQ_RPC_IT_MD3_TO_MD1_NOIN_NOOUT;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_rpc_rx();
#else/* MD3 */
    cc_irq_rpc_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - PCORE send a RPC with no input and output parameters to MD3
    cc_irq_test_case = CC_IRQ_RPC_IT_MD1_TO_MD3_NOIN_NOOUT;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_rpc_tx();
#else/* MD3 */
    cc_irq_rpc_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 3 - MD3 send a RPC with input but no output parameters to MD1
    cc_irq_test_case = CC_IRQ_RPC_IT_MD3_TO_MD1_IN_NOOUT;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_rpc_rx();
#else/* MD3 */
    cc_irq_rpc_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 4 - MD1 send a RPC with input but no output parameters to MD3
    cc_irq_test_case = CC_IRQ_RPC_IT_MD1_TO_MD3_IN_NOOUT;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_rpc_tx();
#else/* MD3 */
    cc_irq_rpc_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 5 - MD3 send a RPC with input and output parameters to MD1
    cc_irq_test_case = CC_IRQ_RPC_IT_MD3_TO_MD1_IN_OUT;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_rpc_rx();
#else/* MD3 */
    cc_irq_rpc_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 6 - MD1 send a RPC with input and output parameters to MD3
    cc_irq_test_case = CC_IRQ_RPC_IT_MD1_TO_MD3_IN_OUT;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_rpc_tx();
#else/* MD3 */
    cc_irq_rpc_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 7 - MD3 send a RPC with MAX input and output parameters to MD1
    cc_irq_test_case = CC_IRQ_RPC_IT_MD3_TO_MD1_IN_OUT_MAX;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_rpc_rx();
#else/* MD3 */
    cc_irq_rpc_tx_max();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 8 - MD1 send a RPC with MAX input and output parameters to MD3
    cc_irq_test_case = CC_IRQ_RPC_IT_MD1_TO_MD3_IN_OUT_MAX;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_rpc_tx_max();
#else/* MD3 */
    cc_irq_rpc_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    cc_irq_test_case_RPC_END = 1;
}

/*****************************************************************************************
CC spinlock ability test
*****************************************************************************************/
#define PATTERN_INIT 0x0
#define PATTERN 0x12345678
#define PATTERN_L1 0xAAAA5555
#define PATTERN_FOR_CHECK 0xA5A5A5A5

typedef enum EXCLUSIVE_STATE_T
{
    OPEN  =  0 ,
    EXCLUSIVE = 1,
    OTHER = 2
}EXCLUSIVE_STATE;

typedef enum EXCLUSIVE_RETVAL_T
{
    EX_SUCCESS  =  0 ,
    EX_FAIL = 1
}EXCLUSIVE_RETVAL;

__attribute__((noinline)) void Rd_S_4_EX(volatile unsigned int *a, int b)
{
    __asm__ __volatile__(
         "LDREX   r0, [r0]    \n\t");
}
/*
Rd_S_4_EX:
@====================================
@   r0:  n: src
@===================================   
   STMDB   sp!, {r4-r12}
#if defined(__CR4__)
   LDREX   r0, [r0]
#endif
   LDMIA   sp!, {r4-r12}
   BX lr 
*/
__attribute__((noinline)) int Wr_S_4_EX(volatile unsigned int *a, int b)
{
    register int ret __asm__("r8");
	
    __asm__ __volatile__(
         "STREX   r8, r1, [r0]    \n\t");
	
	return ret; 
}
/*
Wr_S_4_EX:
@====================================
@   r0:  n: dst
@   r1:  n: pattern
@===================================   
   STMDB   sp!, {r4-r12}
   MOV     r2, r0
#if defined(__CR4__)
   STREX   r0, r1, [r2]
#endif
   LDMIA   sp!, {r4-r12}
   BX lr
*/

void Clr_EX()
{
    __asm__ __volatile__(
         "CLREX    \n\t"
     );
}
/*
Clr_EX:  
   STMDB   sp!, {r4-r12}
#if defined(__CR4__)
   CLREX
#endif
   LDMIA   sp!, {r4-r12}
   BX lr 
*/

#define CHECK_EX_STATE(DESTNATION, RESULT) \
    do{ \
        RESULT = Wr_S_4_EX(DESTNATION, PATTERN_FOR_CHECK); \
        if (RESULT == 1) {RESULT = OPEN;} \
        else {RESULT = EXCLUSIVE;} \
    }while(0)
//------------------------------------
void cc_spinlock_sync(kal_uint32 my_state, kal_uint32 wait_state)
{
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_it_share_var->cr4_to_md32_tx_notify = my_state;
    CC_IRQ_DMB();
    while(cc_irq_it_share_var->md32_to_cr4_tx_notify != wait_state);	
#else/* MD3 */
    cc_irq_it_share_var->md32_to_cr4_tx_notify = my_state;
    CC_IRQ_DMB();
    while(cc_irq_it_share_var->cr4_to_md32_tx_notify != wait_state);	
#endif
}

static void cc_spinlock_test_item_init()
{
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_it_share_var->cr4_to_md32_test_start = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(cc_irq_it_share_var->md32_to_cr4_test_start != CC_IRQ_TEST_STATUS_ENABLE);
    cc_irq_it_share_var->cr4_to_md32_test_end = CC_IRQ_TEST_STATUS_DISABLE;
    cc_irq_it_share_var->cr4_to_md32_tx_notify = 0;
    CC_IRQ_DMB();
#else/* MD3 */
    cc_irq_it_share_var->md32_to_cr4_test_start = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(cc_irq_it_share_var->cr4_to_md32_test_start != CC_IRQ_TEST_STATUS_ENABLE);
    cc_irq_it_share_var->md32_to_cr4_test_end = CC_IRQ_TEST_STATUS_DISABLE;
    cc_irq_it_share_var->md32_to_cr4_tx_notify = 0;
    CC_IRQ_DMB();
#endif
}

static void cc_spinlock_test_item_deinit()
{
#if defined(__PCORE__)||defined(__L1CORE__)
    cc_irq_it_share_var->cr4_to_md32_test_start = CC_IRQ_TEST_STATUS_DISABLE;
    cc_irq_it_share_var->cr4_to_md32_test_end = CC_IRQ_TEST_STATUS_ENABLE; 
    CC_IRQ_DMB();
    while(cc_irq_it_share_var->md32_to_cr4_test_end != CC_IRQ_TEST_STATUS_ENABLE);
#else/* MD3 */
    cc_irq_it_share_var->md32_to_cr4_test_start = CC_IRQ_TEST_STATUS_DISABLE;
    cc_irq_it_share_var->md32_to_cr4_test_end = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(cc_irq_it_share_var->cr4_to_md32_test_end != CC_IRQ_TEST_STATUS_ENABLE);
#endif
}

kal_uint32 *EXACC_destination;/* The address of exclusive operation on MD1 & MD3 share memory. EXACC_destination = 0x4....  */
kal_spinlockid cc_spinlock_p;/* spinlock pointer */
kal_int32 *ccl_share_parameter;/* the share value which be protected by spinlock */
kal_uint32 cc_spin_test_time = 0xFFFF;
void cc_spinlock_ability_it()
{/* test case for CC spinlock ability */

    int retval;
    EXCLUSIVE_STATE final_state;

#if defined(__PCORE__)||defined(__MD3_PCORE__)	
    EXACC_destination = cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_PS2MD3_SPINLOCK, sizeof(kal_uint32));
#elif defined(__L1CORE__)||defined(__MD3_L1CORE__)
	EXACC_destination = cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_L12MD3_32K_SPINLOCK, sizeof(kal_uint32));
#else
    #error "DEFINE ERROR"
#endif
        
    // Exclusive Access Integration Test

    /*
    ** Test Case 1 : MD1 LoadExcl(x,n) -> MD1 StoreExcl(x,n) -> MD3 LoadExcl(x,n) -> MD3 StoreExcl(x,n)
    ** Pass Criteria :  MD1/MD3 StoreExcl(x,n): Success
    **                  Value: Updated by MD1/MD3 StoreExcl(x,n).
    **                  Final State: MD1-OPEN, MD3-OPEN
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_1; 

    cc_spinlock_test_item_init();

#if defined(__PCORE__)||defined(__L1CORE__)//MD1
    *EXACC_destination = PATTERN_INIT;

    //Enter Open State
    Clr_EX();
	
    //MD1 LoadExcl(x,n) and StoreExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
    retval = Wr_S_4_EX(EXACC_destination, PATTERN);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_SUCCESS) && (final_state == OPEN) && (*EXACC_destination == PATTERN)), final_state, *EXACC_destination, 0);
	
    //Let MD3 go 
    cc_spinlock_sync(0x2, 0x2);// 

#else                                        //MD3
    cc_spinlock_sync(0x1, 0x2);// wait MD1 done
    
    //MD3 LoadExcl(x,n) and StoreExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
    retval = Wr_S_4_EX(EXACC_destination, PATTERN_L1);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_SUCCESS) && (final_state == OPEN) && (*EXACC_destination == PATTERN_L1)), final_state, *EXACC_destination, 0);

    //Let MD1 go 
    cc_spinlock_sync(0x2, 0x2);// 	
#endif
    cc_spinlock_test_item_deinit();

    /*
    ** Test Case 2 : MD3 LoadExcl(x,n) -> MD3 StoreExcl(x,n) -> MD1 LoadExcl(x,n) -> MD1 StoreExcl(x,n)
    ** Pass Criteria :  MD1/MD3 StoreExcl(x,n): Success
    **                  Value: Updated by MD1/MD3 StoreExcl(x,n).
    **                  Final State: MD1-OPEN, MD3-OPEN
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_2; 

    cc_spinlock_test_item_init();

#if defined(__MD3_PCORE__)||defined(__MD3_L1CORE__)    //MD3
    *EXACC_destination = PATTERN_INIT;

    //Enter Open State
    Clr_EX();
	
    //MD3 LoadExcl(x,n) and StoreExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
    retval = Wr_S_4_EX(EXACC_destination, PATTERN);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_SUCCESS) && (final_state == OPEN) && (*EXACC_destination == PATTERN)), final_state, *EXACC_destination, 0);
	
    //Let MD1 go 
    cc_spinlock_sync(0x20, 0x20);// 

#else                                        //MD1
    cc_spinlock_sync(0x1, 0x20);// wait MD3 done
    
    //MD1 LoadExcl(x,n) and StoreExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
    retval = Wr_S_4_EX(EXACC_destination, PATTERN_L1);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_SUCCESS) && (final_state == OPEN) && (*EXACC_destination == PATTERN_L1)), final_state, *EXACC_destination, 0);

    //Let MD3 go 
    cc_spinlock_sync(0x20, 0x20);// 	
#endif
    cc_spinlock_test_item_deinit();

    /*
    ** Test Case 3 : MD1 LoadExcl(x,n) -> MD3 LoadExcl(x,n) -> MD3 StoreExcl(x,n) -> MD1 StoreExcl(x,n)
    ** Pass Criteria :  MD3 StoreExcl(x,n): Success, MD1 StoreExcl(x,n): Fail
    **                  Value: Updated by MD3 StoreExcl(x,n).
    **                  Final State: MD1-OPEN, MD3-OPEN
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_3; 

    cc_spinlock_test_item_init();

#if defined(__PCORE__)||defined(__L1CORE__)    //MD1
    *EXACC_destination = PATTERN_INIT;

    //Enter Open State
    Clr_EX();
	
    //MD1 LoadExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
	
    //Let MD3 go and wait
    cc_spinlock_sync(0x3, 0x3);// 2

    //MD1 StoreExcl(x,n)
    retval = Wr_S_4_EX(EXACC_destination, PATTERN);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_FAIL) && (final_state == OPEN) && (*EXACC_destination == PATTERN_L1)), final_state, *EXACC_destination, 0);

#else                                        //MD3
    cc_spinlock_sync(0x1, 0x3);// wait MD1 Load
    
    //MD3 LoadExcl(x,n) and StoreExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
    retval = Wr_S_4_EX(EXACC_destination, PATTERN_L1);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_SUCCESS) && (final_state == OPEN) && (*EXACC_destination == PATTERN_L1)), final_state, *EXACC_destination, 0);

    //Let MD1 go
    cc_spinlock_sync(0x3, 0x3);// 2	
#endif
    cc_spinlock_test_item_deinit();

    /*
    ** Test Case 4 : MD3 LoadExcl(x,n) -> MD1 LoadExcl(x,n) -> MD1 StoreExcl(x,n) -> MD3 StoreExcl(x,n)
    ** Pass Criteria :  MD1 StoreExcl(x,n): Success, MD3 StoreExcl(x,n): Fail
    **                  Value: Updated by MD1 StoreExcl(x,n).
    **                  Final State: MD1-OPEN, MD3-OPEN
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_4; 

    cc_spinlock_test_item_init();

#if defined(__MD3_PCORE__)||defined(__MD3_L1CORE__)    //MD3
    *EXACC_destination = PATTERN_INIT;

    //Enter Open State
    Clr_EX();
	
    //MD3 LoadExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
	
    //Let MD1 go and wait
    cc_spinlock_sync(0x30, 0x30);// 2

    //MD3 StoreExcl(x,n)
    retval = Wr_S_4_EX(EXACC_destination, PATTERN);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_FAIL) && (final_state == OPEN) && (*EXACC_destination == PATTERN_L1)), final_state, *EXACC_destination, 0);

#else                                        //MD1
    cc_spinlock_sync(0x1, 0x30);// wait MD3 Load
    
    //MD1 LoadExcl(x,n) and StoreExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
    retval = Wr_S_4_EX(EXACC_destination, PATTERN_L1);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_SUCCESS) && (final_state == OPEN) && (*EXACC_destination == PATTERN_L1)), final_state, *EXACC_destination, 0);

    //Let MD3 go
    cc_spinlock_sync(0x30, 0x30);// 2	
#endif
    cc_spinlock_test_item_deinit();


//--------------------------------------------
//--------------------------------------------
//wolf MD3只有在LDREX後的寫入才會是STREX, 其他都是普通STR 
    /*
    ** Test Case 5 : MD1 LoadExcl(x,n) -> MD3 Store
    ** Pass Criteria :  MD3 Store: Sucess                  
    **                  Value: Do updated by MD3 Store.   
    **                  Final State: MD1-OPEN, MD3-OPEN             
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_5; 

    cc_spinlock_test_item_init();

#if defined(__PCORE__)||defined(__L1CORE__)    //MD1
    *EXACC_destination = PATTERN_INIT;

    //Enter Open State
    Clr_EX();
    //MD1 LoadExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
    //Waiting MD3 StoreExcl(x,!n)
    cc_spinlock_sync(0x5, 0x5);// 2
    cc_spinlock_sync(0xF, 0xF);// 4

    CHECK_EX_STATE(EXACC_destination, final_state);
//MD1's design    EXT_ASSERT(((final_state == EXCLUSIVE) && (*EXACC_destination == PATTERN_FOR_CHECK)), final_state, *EXACC_destination, 0);
    EXT_ASSERT(((final_state == OPEN) && (*EXACC_destination == PATTERN_L1)), final_state, *EXACC_destination, 0);
#else                                        //MD3
    cc_spinlock_sync(0x1, 0x5);// 1
    
    //MD3 StoreExcl(x,!n)
    retval = Wr_S_4_EX(EXACC_destination, PATTERN_L1);/* In MD3, it is normal write */
    CC_IRQ_DMB();

    cc_spinlock_sync(0x5, 0x5);// 3
    cc_spinlock_sync(0xF, 0xF);// 4

//MD1's design        EXT_ASSERT(((retval == EX_FAIL) && (*EXACC_destination != PATTERN_L1)),final_state, *EXACC_destination, 0);
    EXT_ASSERT(((retval == EX_SUCCESS) && (*EXACC_destination == PATTERN_L1)),final_state, *EXACC_destination, 0);
#endif
    cc_spinlock_test_item_deinit();

    /*
    ** Test Case 6 : MD3 LoadExcl(x,n) -> MD1 StoreExcl(x,!n)
    ** Pass Criteria :  MD1 StoreExcl(x,!n): Fail
    **                  Value: Do not updated by MD1 StoreExcl(x,!n).
    **                  Final State: MD3-EXLCUSIVE, MD1-OPEN
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_6; 

    cc_spinlock_test_item_init();

#if defined(__MD3_PCORE__)||defined(__MD3_L1CORE__)    //MD3
    *EXACC_destination = PATTERN_INIT;

    //Enter Open State
    Clr_EX();
    //MD3 LoadExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
    //Waiting MD1 StoreExcl(x,!n)
    cc_spinlock_sync(0x50, 0x50);// 2
    cc_spinlock_sync(0xF, 0xF);// 4

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((final_state == EXCLUSIVE) && (*EXACC_destination == PATTERN_FOR_CHECK)), final_state, *EXACC_destination, 0);
#else                                        //MD1
    cc_spinlock_sync(0x1, 0x50);// 1
    
    //MD1 StoreExcl(x,!n)
    retval = Wr_S_4_EX(EXACC_destination, PATTERN_L1);
    CC_IRQ_DMB();

    cc_spinlock_sync(0x50, 0x50);// 3
    cc_spinlock_sync(0xF, 0xF);// 4

    EXT_ASSERT(((retval == EX_FAIL) && (*EXACC_destination != PATTERN_L1)),final_state, *EXACC_destination, 0);
#endif
    cc_spinlock_test_item_deinit();

    /*
    ** Test Case 7 : MD1 LoadExcl(x,n) -> MD3 StoreExcl(x,!n) -> MD1 StoreExcl(x,n)   
    ** Pass Criteria :  MD1 StoreExcl(x,n): fail                  attention!! differe from MD1's design,(Due to MD3 is normal Store)
    **                  MD3 StoreExcl(x,!n): sucess               in MD1's design, MD3 should write fail, and MD1 write success
    **                  Final State: MD1-OPEN, MD3-OPEN           
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_7;    
    cc_spinlock_test_item_init();

#if defined(__PCORE__)||defined(__L1CORE__)    //MD1
    //Initialization
    *EXACC_destination = PATTERN_INIT;
    //Enter Open State
    Clr_EX();
    //MD1 LoadExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
    //Waiting MD3 StoreExcl(x,!n)
    cc_spinlock_sync(0x7,0x7);// 2
    //MD1 StoreExcl(x,n)
    retval = Wr_S_4_EX(EXACC_destination, PATTERN);
    CC_IRQ_DMB();

    cc_spinlock_sync(0x3,0x7);// 4
    cc_spinlock_sync(0xF,0xF);// 5

    CHECK_EX_STATE(EXACC_destination, final_state);
//MD1's design    EXT_ASSERT(((retval == EX_SUCCESS) && (final_state == OPEN) && (*EXACC_destination == PATTERN)), final_state, *EXACC_destination, 0);
    EXT_ASSERT(((retval == EX_FAIL) && (final_state == OPEN) && (*EXACC_destination == PATTERN_L1)), final_state, *EXACC_destination, 0);
#else                                        //MD3
    cc_spinlock_sync(0x1,0x7);// 1
    
    //MD3 StoreExcl(x,!n)
    retval = Wr_S_4_EX(EXACC_destination, PATTERN_L1);
    CC_IRQ_DMB();

    cc_spinlock_sync(0x7,0x3);// 3
    cc_spinlock_sync(0xF,0xF);// 5

//MD1's design        EXT_ASSERT(((retval == EX_FAIL) && (*EXACC_destination != PATTERN_L1)), final_state, *EXACC_destination, 0);
    EXT_ASSERT(((retval == EX_SUCCESS) && (*EXACC_destination == PATTERN_L1)), final_state, *EXACC_destination, 0);
#endif
    cc_spinlock_test_item_deinit();

    /*
    ** Test Case 8 : MD3 LoadExcl(x,n) -> MD1 StoreExcl(x,!n) -> MD3 StoreExcl(x,n)
    ** Pass Criteria :  MD3 StoreExcl(x,n): Success                
    **                  MD1 StoreExcl(x,!n): Fail
    **                  Final State: MD1-OPEN, MD3-OPEN
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_8;    
    cc_spinlock_test_item_init();

#if defined(__MD3_PCORE__)||defined(__MD3_L1CORE__)    //MD3
    //Initialization
    *EXACC_destination = PATTERN_INIT;
    //Enter Open State
    Clr_EX();
    //MD3 LoadExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);
    //Waiting MD1 StoreExcl(x,!n)
    cc_spinlock_sync(0x70,0x70);// 2
    //MD3 StoreExcl(x,n)
    retval = Wr_S_4_EX(EXACC_destination, PATTERN);
    CC_IRQ_DMB();

    cc_spinlock_sync(0x3,0x70);// 4
    cc_spinlock_sync(0xF,0xF);// 5

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_SUCCESS) && (final_state == OPEN) && (*EXACC_destination == PATTERN)), final_state, *EXACC_destination, 0);
#else                                        //MD1
    cc_spinlock_sync(0x1,0x70);// 1
    
    //MD1 StoreExcl(x,!n)
    retval = Wr_S_4_EX(EXACC_destination, PATTERN_L1);
    CC_IRQ_DMB();

    cc_spinlock_sync(0x70,0x3);// 3
    cc_spinlock_sync(0xF,0xF);// 5

    EXT_ASSERT(((retval == EX_FAIL) && (*EXACC_destination != PATTERN_L1)), final_state, *EXACC_destination, 0);
#endif
    cc_spinlock_test_item_deinit();


    /*                 wolf MD3的LoadExcl(x,n)不會影響到MD1的狀態
    ** Test Case 9 : MD1 LoadExcl(x,n) -> MD3 LoadExcl(x,n) -> MD1 StoreExcl(x,n) -> MD3 StoreExcl(x,n)
    ** Pass Criteria :  MD3 StoreExcl(x,n): Fail, MD1 StoreExcl(x,n): Success
    **                  Value: Updated by MD3 StoreExcl(x,n).
    **                  Final State: MD1-OPEN, MD3-OPEN
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_9; 

    cc_spinlock_test_item_init();

#if defined(__PCORE__)||defined(__L1CORE__)    //MD1
    *EXACC_destination = PATTERN_INIT;

    //Enter Open State
    Clr_EX();
	
    //MD1 LoadExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);//1
	
    //Let MD3 go and wait
    cc_spinlock_sync(0x9, 0x9);// 2

    //MD1 StoreExcl(x,n)
    retval = Wr_S_4_EX(EXACC_destination, PATTERN);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_SUCCESS) && (final_state == OPEN) && (*EXACC_destination == PATTERN)), final_state, *EXACC_destination, 0);

    //Let MD3 go and wait
    cc_spinlock_sync(0x7, 0x7);// 2
	
#else                                        //MD3
    cc_spinlock_sync(0x1, 0x9);// wait MD1 Load
    
    //MD3 LoadExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);

    //Let MD1 go and wait
    cc_spinlock_sync(0x9, 0x7);// 2	

    //MD3 StoreExcl(x,n)	
    retval = Wr_S_4_EX(EXACC_destination, PATTERN_L1);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_FAIL) && (final_state == OPEN) && (*EXACC_destination != PATTERN_L1)), final_state, *EXACC_destination, 0);

    //Let MD1 go
    cc_spinlock_sync(0x7, 0x7);// 2	
#endif
    cc_spinlock_test_item_deinit();
	
    /*
    ** Test Case 10 : MD3 LoadExcl(x,n) -> MD1 LoadExcl(x,n) -> MD3 StoreExcl(x,n) -> MD1 StoreExcl(x,n)
    ** Pass Criteria :  MD3 StoreExcl(x,n): Success, MD1 StoreExcl(x,n): Fail
    **                  Value: Updated by MD3 StoreExcl(x,n).
    **                  Final State: MD1-OPEN, MD3-OPEN
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_10; 

    cc_spinlock_test_item_init();

#if defined(__MD3_PCORE__)||defined(__MD3_L1CORE__)    //MD3
    *EXACC_destination = PATTERN_INIT;

    //Enter Open State
    Clr_EX();
	
    //MD3 LoadExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);//1
	
    //Let MD1 go and wait
    cc_spinlock_sync(0xA, 0xA);// 2

    //MD3 StoreExcl(x,n)
    retval = Wr_S_4_EX(EXACC_destination, PATTERN);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_SUCCESS) && (final_state == OPEN) && (*EXACC_destination == PATTERN)), final_state, *EXACC_destination, 0);

    //Let MD1 go and wait
    cc_spinlock_sync(0x7, 0x7);// 2
	
#else                                        //MD1
    cc_spinlock_sync(0x1, 0xA);// wait MD3 Load
    
    //MD1 LoadExcl(x,n)
    Rd_S_4_EX(EXACC_destination, (int) NULL);

    //Let MD3 go and wait
    cc_spinlock_sync(0xA, 0x7);// 2	

    //MD1 StoreExcl(x,n)	
    retval = Wr_S_4_EX(EXACC_destination, PATTERN_L1);

    CHECK_EX_STATE(EXACC_destination, final_state);
    EXT_ASSERT(((retval == EX_FAIL) && (final_state == OPEN) && (*EXACC_destination != PATTERN_L1)), final_state, *EXACC_destination, 0);

    //Let MD3 go
    cc_spinlock_sync(0x7, 0x7);// 2	
#endif
    cc_spinlock_test_item_deinit();	

    *EXACC_destination = 0; /* we would test real spinlock, so clear this lock to 0 */

    /*
    ** Test Case 11 : real spinlock test, KAL_INFINITE_WAIT
    ** Pass Criteria :  
    **                  
    **                  
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_11;    

#if defined(__PCORE__)||defined(__MD3_PCORE__)	
    cc_spinlock_p = cc_spin_create_spinlock("PS2MD3_SPINLOCK");
#elif defined(__L1CORE__)||defined(__MD3_L1CORE__)
	cc_spinlock_p = cc_spin_create_spinlock("L12MD3_32K_SPINLOCK");
#else
    #error "DEFINE ERROR"
#endif

    ccl_share_parameter = (kal_int32 *)cc_irq_get_md1_md3_user_shared_memory(CC_SHARE_MEM_MD32PS_CC_CRITICAL_SHARE, sizeof(kal_int32));
    kal_int32 value = 0;

	
    cc_spinlock_test_item_init();

    while(cc_spin_test_time>0)
    {
#if defined(__PCORE__)||defined(__L1CORE__)    //MD1
        ASSERT(cc_spin_take_spinlock(cc_spinlock_p, KAL_INFINITE_WAIT) == KAL_SUCCESS);
        value = *ccl_share_parameter;
        *ccl_share_parameter = *ccl_share_parameter + 1;
        EXT_ASSERT(*ccl_share_parameter==value+1, value, *ccl_share_parameter, cc_spin_test_time);
        cc_spin_give_spinlock(cc_spinlock_p);
#else                                        //MD3
        ASSERT(cc_spin_take_spinlock(cc_spinlock_p, KAL_INFINITE_WAIT) == KAL_SUCCESS);
        value = *ccl_share_parameter;
        *ccl_share_parameter = *ccl_share_parameter - 1;
        EXT_ASSERT(*ccl_share_parameter==value-1, value, *ccl_share_parameter, cc_spin_test_time);
        cc_spin_give_spinlock(cc_spinlock_p);
#endif
        cc_spin_test_time--;
    }

    cc_spinlock_test_item_deinit();

    /*
    ** Test Case 12 : real spinlock test, KAL_NO_WAIT
    ** Pass Criteria :  
    **                  
    **                  
    */
    cc_irq_test_case = CC_SPINLOCK_IT_TEST_12;    
    cc_spin_test_time = 0xFFFF;
	
    cc_spinlock_test_item_init();

    while(cc_spin_test_time>0)
    {
#if defined(__PCORE__)||defined(__L1CORE__)    //MD1
        while(cc_spin_take_spinlock(cc_spinlock_p, KAL_NO_WAIT) == KAL_SPINLOCK_NOT_AVAILABLE);
        value = *ccl_share_parameter;
        *ccl_share_parameter = *ccl_share_parameter + 1;
        EXT_ASSERT(*ccl_share_parameter==value+1, value, *ccl_share_parameter, cc_spin_test_time);
        cc_spin_give_spinlock(cc_spinlock_p);
#else                                        //MD3
        while(cc_spin_take_spinlock(cc_spinlock_p, KAL_NO_WAIT) == KAL_SPINLOCK_NOT_AVAILABLE);
        value = *ccl_share_parameter;
        *ccl_share_parameter = *ccl_share_parameter - 1;
        EXT_ASSERT(*ccl_share_parameter==value-1, value, *ccl_share_parameter, cc_spin_test_time);
        cc_spin_give_spinlock(cc_spinlock_p);
#endif
        cc_spin_test_time--;
    }

    cc_spinlock_test_item_deinit();


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__PCORE__)||defined(__L1CORE__)    //Acore
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else                                        //Bcore
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
#endif
/* under construction !*/
#endif

cc_irq_test_case_CC_spinlock_END = 1;

}

#endif
