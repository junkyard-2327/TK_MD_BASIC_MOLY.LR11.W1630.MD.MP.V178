/*
 * ebc_drv.h
 *
 *  Created on: 2014/6/10
 *      Author: MTK07117
 */

#ifndef EBC_DRV_H_
#define EBC_DRV_H_

#if !defined(GEN_FOR_PC)
#include "ebc_reg.h"
#include "mdl_reg.h"
#include "mdp_reg.h"
#include "mtol_reg.h"
#include "kal_general_types.h"
#endif

// ============== define Channel Map ==================
enum EBC_CH_ID {
	EBC_MDL_DFE_ID = 0,
	EBC_MDL_RAKE_ID,
	EBC_MDL_RXBRP_ID,
	EBC_MDL_MPC_ID,
	EBC_MDL_IMC_ID,
	EBC_MDL_ICC_ID,
	EBC_MDP_MPC_ID,
	EBC_MDP_IMC_ID,
	EBC_MDP_ICC_ID,
	EBC_MTOL_MPC_ID,
	EBC_MTOL_IMC_ID,
	EBC_MTOL_ICC_ID,
	EBC_CH_NUM
};

#define EBC_MDL_ID_BEGIN	(EBC_MDL_DFE_ID)
#define EBC_MDP_ID_BEGIN	(EBC_MDP_MPC_ID)
#define EBC_MTOL_ID_BEGIN	(EBC_MTOL_MPC_ID)

#if !defined(GEN_FOR_PC)
typedef union {
	// all channel
	kal_uint32 ALL;
	// all channel of each type
	struct {
		kal_uint32 MDL_ALL:  6;	//ch id = 0~5
		kal_uint32 MDP_ALL:  3;	//ch id = 6~8
		kal_uint32 MTOL_ALL: 3;	//ch id = 9~11
	};
	// each channel
	struct {
		kal_uint32 MDL_DFE:  1;	//ch id = 0
		kal_uint32 MDL_RAKE: 1;	//ch id = 1
		kal_uint32 MDL_RXBRP:1;	//ch id = 2
		kal_uint32 MDL_MPC:  1;	//ch id = 3
		kal_uint32 MDL_IMC:  1;	//ch id = 4
		kal_uint32 MDL_ICC:  1;	//ch id = 5
		kal_uint32 MDP_MPC:  1;	//ch id = 6
		kal_uint32 MDP_IMC:  1;	//ch id = 7
		kal_uint32 MDP_ICC:  1;	//ch id = 8
		kal_uint32 MTOL_MPC: 1;	//ch id = 9
		kal_uint32 MTOL_IMC: 1;	//ch id = 10
		kal_uint32 MTOL_ICC: 1;	//ch id = 11
	};
}EBC_CH_MAP;

// ==================== Init Info ======================
typedef struct {
	kal_uint32 base_addr;
	kal_uint32 size;
} EBC_EMI_Info;

typedef struct {
	EBC_CH_MAP 	 ChEn;
	kal_uint32 	 OptionFlag;
	// return error, argu: channel id, base addr, size
	kal_int32  (*flush_callback_ex)(kal_uint32, kal_uint32, kal_uint32);
	void (*buffer_full_callback)(void);
	EBC_EMI_Info ChBuf[EBC_CH_NUM];
} EBC_Init_Info;

#define EBC_INIT_INFO_DEFAULT 	{{0}, 0, 0, 0}
#define EBC_OPT_NO_UNMASK_IRQ	0x01

// ================== Handle Record ===================
typedef struct {
    kal_uint32 buf_sz;
    kal_uint32 base_addr;
    kal_uint32 start_addr;
    kal_bool   IsWrapped;
} EBC_HANDLE_CH_RECORD;

typedef struct {
    kal_bool                IsEn;
    EBC_HANDLE_CH_RECORD    ChRecord[EBC_CH_NUM];
} EBC_HANDLE_RECORD;

// ================== Error Code ======================
typedef enum {
	EBC_NO_ERROR = 0,
	EBC_FLASH_TIMEOUT = 0x01,
	EBC_ABORT_TIMEOUT = 0x02,
	EBC_WRONG_START_ADDR_EX = 0x04,
	EBC_DBG_MODE_EN_FAIL = 0x08,
	EBC_HANDLE_POWER_DOWN_DATA_FAIL = 0x10
}EBC_ERR;

// =================== EBC API ========================

/* @brief EBC driver init
 * @param initial info. & register callback function */
kal_int32 ebc_drv_init(EBC_Init_Info* pInitInfo);

/* @brief EBC driver stop in exception mode */
kal_int32 ebc_drv_stop_ex(void);

/* @brief EBC driver un-mask CIRQ */
void ebc_drv_unmask_cirq(void);

/* @brief EBC driver get all buffer full state */
kal_uint32 ebc_drv_get_buf_full_state(void);

/* @brief EBC driver clear buffer full state
 * @param buffer map: one bit one buffer  */
kal_uint32 ebc_drv_clr_buf_full_state(kal_uint32 BufMap);

// ===== Debug API for driver test or exception ======

/* @brief EBC driver flush logger for exception debug and
 * blocking thread until flush ending or time out
 * @param timeout_tick: the tick number of time out */
kal_int32 ebc_drv_flush_logger_ex(kal_uint32 timeout_tick);

/* @brief EBC driver get active channel for exception debug
 * @param channel buffer: one bit one channel */
kal_uint32 ebc_drv_get_active_ch_ex();

/* @brief EBC driver get base address for exception debug
 * @param channel id: indicate return channel */
kal_uint32 EBC_get_ch_base_addr_ex(kal_int32 ChID);

/* @brief EBC driver get start address for exception debug
 * @param channel id: indicate return channel */
kal_uint32 EBC_get_ch_start_addr_ex(kal_int32 ChID);

/* @brief EBC driver flush for exception debug and
 * auto test mode*/
kal_uint32 ebc_drv_get_flush_abort_state(void);

/* @brief EBC driver flush for exception debug and
 * auto test mode*/
void ebc_drv_flush_ex(void);

/* @brief EBC driver handle buffer full for exception debug
 * and auto test mode*/
kal_int32 ebc_drv_handle_buffer_full_ex();

/* @brief EBC driver handle remaining date for exception debug
 * and auto test mode*/
kal_int32 ebc_drv_handle_remaining_data_ex();

/* @brief EBC driver open coresonic & md32 debug mode
 * for exception*/
kal_int32 ebc_drv_debug_mdoe_en_ex();

// ==================== extern API =====================
/* @brief EBC driver check coresonic core status
 * for exception*/
extern kal_bool Sonic_IsSyncFinished(void);

#endif

#endif /* EBC_DRV_H_ */
