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
 *   spc_excep_hdlr.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   This file provides typedefs and definiton for PS index trace.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __SPC_EXCEP_HDLR_FORMAT_H__
#define __SPC_EXCEP_HDLR_FORMAT_H__

// ----------------- macro definition ---------------
// ----------------- data type Definition -------------------

enum {
    CMIF_MD32_EX_ASSERT_LINE        = 0x1,
    CMIF_MD32_EX_ASSERT_EXT         = 0x2,
    CMIF_MD32_EX_FATAL_ERROR        = 0x3,
    CMIF_MD32_EX_FATAL_ERROR_EXT    = 0x4,
};

/* Should sync to SPCore: Start */

enum {
    SPC_EX_STATUS_INIT = 0,
    SPC_EX_STATUS_INIT_DONE,
    SPC_EX_STATUS_TRIGGER_CTI,
    SPC_EX_STATUS_SAVE_EX_INFO,
    SPC_EX_STATUS_SAVE_EX_DONE,
    SPC_EX_STATUS_SAVE_SW_VERSION,
    SPC_EX_STATUS_SAVE_SW_VERSION_DONE,
    SPC_EX_STATUS_SAVE_TCM_DATA,
    SPC_EX_STATUS_SAVE_CPU_REGISTERS,
    SPC_EX_STATUS_SAVE_EX_INFO_TO_SRAM,
    SPC_EX_STATUS_SAVE_EX_INFO_TO_SRAM_DONE,
    SPC_EX_STATUS_CACHE_FLUSH,
    SPC_EX_STATUS_CACHE_FLUSH_DONE,
    SPC_EX_STATUS_READY,
    SPC_EX_STATUS_END,
};

enum {
    SPC_EX_REASON_CTI = 0,
    SPC_EX_REASON_ASSERT,
    SPC_EX_REASON_ABORT,
    SPC_EX_REASON_OTHERS,
    SPC_EX_REASON_UNKNOWN,
    SPC_EX_REASON_END,
};

#if defined(__GNUC__)
typedef struct __attribute__((packed)) _assert_info {
#else
#pragma pack(1)
typedef struct _assert_info {
#endif
    kal_uint32 arg1;
    kal_uint32 arg2;
    kal_uint32 arg3;
    kal_int32 line;
    kal_int8 file[64];
} assert_info_t;
#if !defined(__GNUC__)
#pragma pack()
#endif // __GNUC__

#if defined(__GNUC__)
typedef struct __attribute__((packed)) _fatal_error_info {
#else
#pragma pack(1)
typedef struct _fatal_error_info {
#endif
    kal_uint32 lr;
    kal_uint32 error_code;
} fatal_error_info_t;
#if !defined(__GNUC__)
#pragma pack()
#endif // __GNUC__

#if defined(__GNUC__)
typedef struct __attribute__((packed)) _spc_ex_info {
#else
#pragma pack(1)
typedef struct _spc_ex_info {
#endif
    kal_uint32 ex_reason;
    union {
        assert_info_t assert;
        fatal_error_info_t fatal;
    } ex_info;
} spc_ex_info_t;
#if !defined(__GNUC__)
#pragma pack()
#endif // __GNUC__

#if defined(__GNUC__)
typedef struct __attribute__((packed)) _spc_ex_handshake_info {
#else
#pragma pack(1)
typedef struct _spc_ex_handshake_info {
#endif
    volatile kal_uint32 ex_status;
    spc_ex_info_t info;
} spc_ex_handshake_info_t;
#if !defined(__GNUC__)
#pragma pack()
#endif // __GNUC__

/* Should sync to SPCore: End */

#if defined(__GNUC__)
typedef struct __attribute__((packed)) _spc_ex_record {
#else
#pragma pack(1)
typedef struct _spc_ex_record {
#endif
    kal_uint32 power_on;
    spc_ex_info_t info;
} spc_ex_record_t;
#if !defined(__GNUC__)
#pragma pack()
#endif // __GNUC__

#define SPC_EXCEPTION_RECORD_T spc_ex_record_t

#endif /* __SPC_EXCEP_HDLR_FORMAT_H__ */
