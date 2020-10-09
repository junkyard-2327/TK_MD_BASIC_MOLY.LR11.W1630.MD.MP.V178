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
 *   elm.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file for ELM.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(__ELM_H__)
#define __ELM_H__
/* ==================== */
/*	CONFIGURATIONS		*/
/* ==================== */
/* ==================== */
/*	INCLUDES			*/
/* ==================== */
#include "reg_base.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "sync_data.h"

#include "drv_comm.h"
/*******************************************************************************
 * Feature Option
 *******************************************************************************/
// Turned-On MD EMI latency profiling of TL1/2GL1 SW
// Note: It uses MD ELM and conflicts with SWLA ELM add-on
//#if defined(__MTK_INTERNAL__) 
    #if !defined(__SWLA_ADDON_ELM__) && !defined(__SWLA_EBM_ADDON_SUPPORT__)
      #if defined(TK6291) || defined(JADE)
        #define __ELM_RUNTIME_PROFILE__
      #endif 
    #endif //!defined(__SWLA_ADDON_ELM__) && !defined(__SWLA_EBM_ADDON_SUPPORT__)
//#endif /* __MTK_INTERNAL__ */


/* ==================== */
/*	DEFINITIONS			*/
/* ==================== */

/* ==================== */
/*	ELM CONTROL API		*/
/* ==================== */
//#define ELM_KEY_WORD		(0x6291<<16)
#define ELM_KEY_WORD		(0x2454<<16)

#define REG_ELM_CLK					    (BASE_MADDR_ELM_TOPRESERVED + 0x0004)	
#define REG_ELM_CTRL					(BASE_MADDR_ELM_TOPRESERVED + 0x0008)
#define REG_ELM_STAT					(BASE_MADDR_ELM_TOPRESERVED + 0x0034)

// ELM Set Mode (HW/SW Mode)
enum {
	ELM_SW_MODE = 0,
	ELM_HW_MODE = 1,
	
};

#define ELM_SET_MODE(m) \
	do {\
		;\
	} while(0)



// ELM init
#define ELM_INIT()	\
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CLK, ELM_KEY_WORD | 0x1);\
		} while(0)

// ELM clear
#define ELM_CLR()	\
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CTRL, 0);\
		} while(0)

// ELM Start
#define ELM_START() \
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CTRL, 1);\
		} while(0)

// ELM Pause
#define ELM_PAUSE() \
		do {\
			DRV_WriteReg32_NPW(REG_ELM_CTRL, 3);\
		} while(0)

// ELM Counter Selection
enum {	
	ELM_RD = 0,
	ELM_WR = 1
};

enum {
	ELM_TYPE_TRANS = 0,
	ELM_TYPE_LATENCY = 1
};


#define ELM_GET_CNT(rw, type, idx, p_cnt) \
	do {\
		*p_cnt = DRV_Reg32(REG_ELM_STAT + (((rw ) + (type<< 1)) << 2));\
	} while(0)
#define ELM_GET_CUR_CNT(rw, type, p_cnt) \
	do {\
		*p_cnt = DRV_Reg32(REG_ELM_STAT + (((rw) + (type<< 1)) << 2));\
	} while(0)

// ELM Summary (Current HW_idx, Overrun indication)
#define ELM_GET_SUMMARY(p_hw_idx, p_overrun) \
	do {\
		;\
	} while(0)

typedef struct _ELM_LOG_T
{
	kal_uint32 w_trans;
	kal_uint32 w_latency;
	kal_uint32 r_trans;
	kal_uint32 r_latency;
} ELM_LOG_T;


// for spv compatibility
#define ELM_GET_LOG(c, l) do { \
			ELM_GET_CNT(ELM_WR, ELM_TYPE_TRANS, (c), &((l).w_trans));\
			ELM_GET_CNT(ELM_WR, ELM_TYPE_LATENCY, (c), &((l).w_latency));\
			ELM_GET_CNT(ELM_RD, ELM_TYPE_TRANS, (c), &((l).r_trans));\
			ELM_GET_CNT(ELM_RD, ELM_TYPE_LATENCY, (c), &((l).r_latency));\
		} while (0)
		
#define ELM_SM_Start() ELM_START()
#define ELM_SM_Pause() ELM_PAUSE()
#define ELM_SM_Stop() ELM_CLR()
	


#endif  /* !__ELM_H__ */
