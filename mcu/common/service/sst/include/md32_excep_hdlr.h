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
 *   md32_excep_hdlr.h
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

#ifndef __MD32_EXCEP_HDLR_H__
#define __MD32_EXCEP_HDLR_H__

#if !defined(__OFFLINE_EX_LOG_PARSER__)
#include "md32_boot.h"
#include "kal_general_types.h"
#endif /*__OFFLINE_EX_LOG_PARSER__*/

/*******************************************************************************
 * Definition 
 *******************************************************************************/
#define MD32_NUM_CORES                               3
#define MD32_EX_FILENAME_SIZE                        64 
#define MD32_EX_ASSERT_LINE_TYPE_NUMBER              0x1
#define MD32_EX_ASSERT_EXT_TYPE_NUMBER               0x2
#define MD32_EX_FATAL_ERROR_TYPE_NUMBER              0x3
#define MD32_EX_FATAL_ERROR_EXT_TYPE_NUMBER			 0x4
#define MD32_EX_FILL_FINISH_PATTERN                  0xFD32FD32
#define MD32_EXCEPTION_SYNC_TIME					 0x100000
#define MD32_EXCEPTION_FLOW_HANDSHAKE_SYNC_TIME      0x10000
#define MD32_EXCEPTION_PCORE_WAIT_L1CORE_REPORT_TIME 0x100000

/*******************************************************************************
 * CMIF Exception record structure for MD32  
 *******************************************************************************/
typedef enum{
    MD32_EX_NONE,
    MD32_ASSERT_LINE = MD32_EX_ASSERT_LINE_TYPE_NUMBER,
    MD32_ASSERT_EXT  = MD32_EX_ASSERT_EXT_TYPE_NUMBER,
    MD32_FATAL_ERROR = MD32_EX_FATAL_ERROR_TYPE_NUMBER,
	MD32_CTI_EXCEPTION = MD32_EX_FATAL_ERROR_EXT_TYPE_NUMBER,
    MD32_EX_END=0xff
}MD32_EX_TYPE;


typedef struct{
    /* Total: 20 words */
    kal_uint32 ex_code[3];                                 /* 3 words, 0x58 */ 
    kal_uint32 ex_line;                                    /* 1 words, 0x64 */
    kal_char   ex_filename[MD32_EX_FILENAME_SIZE];         /* 16 words, 0x68 */
}MD32_EX_CMIF_AssertLog;


typedef struct{
    /* Total:  17 words */
    kal_uint32 ex_code[2];                                  /* 2 words, 0x58 */

    kal_uint32 ifabtpc;                                     /* 2 words, 0x60 */
    kal_uint32 ifabtcau;                                             /* 0x64 */ 

    kal_uint32 daabtcau;                                    /* 4 words, 0x68 */
    kal_uint32 daabtpc;                                              /* 0x6C */ 
    kal_uint32 daabtad;                                              /* 0x70 */ 
    kal_uint32 daabtsp;                                              /* 0x74 */ 

    kal_uint32 lr;                                          /* 2 words, 0x78 */
    kal_uint32 sp;                                                   /* 0x7C */
                                                                            
    kal_uint32 interrupt_count;                             /* 1 word,  0x80 */

    kal_uint32 vic_mask;                                    /* 2 words, 0x84 */
    kal_uint32 vic_pending;                                          /* 0x88 */ 

    kal_uint32 cirq_mask_31_0;                              /* 4 words, 0x8C */
    kal_uint32 cirq_mask_63_32;                                      /* 0x90 */ 
    kal_uint32 cirq_pend_31_0;                                       /* 0x94 */ 
    kal_uint32 cirq_pend_63_32;                                      /* 0x98 */ 
}MD32_EX_CMIF_FatalErrorLog;


typedef union{
    MD32_EX_CMIF_AssertLog assert_info;
    MD32_EX_CMIF_FatalErrorLog fatal_error_info; 
}MD32_EX_CMIF_AssertFatalErrorLog;


typedef struct {
    /* Total: 1 + 1 + max(17, 20) words, maximum: 30 words */
    kal_uint32 fill_finish;                                 /* 0x50 */
    MD32_EX_TYPE    ex_type;                                /* 0x54 */
    MD32_EX_CMIF_AssertFatalErrorLog ex_log_info;           /* 0x58, maximum: 30 words*/
    kal_uint32 ex_log_mem_addr;                             /* 0xA8 */
    kal_uint32    md32_active_mode;                         /* offset: 0xAC  */
}MD32_ExceptionLogCore_T;


/** Causion: The total log size for 3* MD32s is 392 bytes.
             It means there are 128 bytes for each MD32s core */
typedef struct {
  MD32_ExceptionLogCore_T core[MD32_NUM_CORES];
}MD32_ExceptionLog_T;

typedef enum{
    MD32_BRP_FAIL_BIT_MASK = (1 << 0),
    MD32_DFE_FAIL_BIT_MASK = (1 << 1),
    MD32_RAKE_FAIL_BIT_MASK= (1 << 2)
}MD32_EX_CORE_BIT_MASK_TYPE;


/*******************************************************************************
 * Function delcation 
 *******************************************************************************/
extern void INT_GetMD32ExceptionRecord(MD32_ExceptionLog_T *record);
extern void INT_GetMD32DumpMemoryInfo(kal_uint32 **info, unsigned short *count);
extern kal_bool INT_SyncMD32ExceptionInfo(void);
extern void INT_EnableMD32MemoryDump(void);
//extern void INT_DumpMD32ExceptionInfo(kal_uint32 trace_type/*0=cadefa*/, kal_char* sys_info_str, kal_uint32 len);

extern kal_uint32 INT_GetMD32FailCore(void);

#define MD32_EX_RC_OFF	0x50

extern kal_bool MD32_RequestEMIFlush(void);
extern kal_bool MD32_AckEMIFlushFinish(void);


#endif /* __MD32_EXCEP_HDLR_H__  */

