/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2016
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
 * waal_defs.h
 *
 * Project:
 * --------
 * UMOLY
 *
 * Description:
 * ------------
 * WAAL common definitions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _WAAL_DEFS_H
#define _WAAL_DEFS_H
/****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "ccci_ipc_if.h"

#include "waal_ipc_msg_struct.h"

/****************************************************************************/
 
/****************************************************************************
 * Definitions
 ****************************************************************************/

#define WAAL_ASSERT             ASSERT
#define WAAL_DBG_ASSERT         DEBUG_ASSERT

/* Defined in ccci_ipc_if.h */
#define WAAL_MOD_LWAD           APMOD_LWAD

/* 3584 (CCCI_IPC_BUFF_SIZE) - 128 (CC ILM header size) */
#define WAAL_CC_ILM_BUF_SIZE    (3456)

#define WAAL_INTERFACE_VER      1

/* Time: millisecond */
#define WAAL_TIME_FAILED_TO_SEND_CC_ILM     (100 * KAL_MILLISECS_PER_TICK)

/****************************************************************************
 * Macros
 ****************************************************************************/

#define waal_trace(...)     kal_brief_trace(__VA_ARGS__)

#define waal_set_state(_ctxt, _s) do { \
    waal_trace(TRC_STATE, WAAL_SET_STATE, _ctxt->waal_state, _s); \
    _ctxt->waal_state = _s; \
} while(0)

#define waal_set_meas_state(_ctxt, _s) do { \
    waal_trace(TRC_STATE, WAAL_SET_MEASUREMENT_STATE, _ctxt->waal_meas_state, _s); \
    _ctxt->waal_meas_state = _s; \
} while(0)

/****************************************************************************
 * Unit Test
 ****************************************************************************/

#ifdef __WAAL_GTEST__
#define STATIC
#else
#define STATIC  static
#endif

/****************************************************************************
 * Type definitions
 ****************************************************************************/

typedef enum
{
    WAAL_STATE_INITED,
    WAAL_STATE_DISCONNECTED,
    WAAL_STATE_DISCONNECTING,
    WAAL_STATE_CONNECTING,
    WAAL_STATE_CONNECTED,
} waal_state_enum;

typedef enum
{
    WAAL_MEASUREMENT_STATE_STOPPED,
    WAAL_MEASUREMENT_STATE_STARTED,
} waal_measurement_state_enum;

/****************************************************************************/

typedef struct _waal_context
{
    waal_state_enum waal_state;
    waal_measurement_state_enum waal_meas_state;

    kal_uint8 wlan_mac_address[6];
    kal_bool band_2_dot_4_supported;
    kal_bool band_5_supported;

    lwad_waal_wlan_measurement_ind_struct *lwad_wlan_meas_ind;
} waal_context;

/****************************************************************************/
#endif /* _WAAL_DEFS_H */
