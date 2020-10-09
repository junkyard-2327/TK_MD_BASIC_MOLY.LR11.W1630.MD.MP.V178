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
 *   dsp_excep_hdlr.h
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
 
#ifndef __CS_EXCEP_HDLR_FORMAT_H__
#define __CS_EXCEP_HDLR_FORMAT_H__

// ----------------- macro definition ---------------
#define CS_CORE_NUMBER    (3)
// ----------------- data type Definition -------------------
typedef enum {
  CS_EXCEPTION_ASSERTION = 0x45584300,
  CS_EXCEPTION_FATAL_ERROR,
  CS_EXCEPTION_CTI_EVENT,
  CS_EXCEPTION_UNKNOWN
} CS_EXCEPTION_TYPE_T;

#if defined(__GNUC__)
typedef struct __attribute__((packed)) {
#else
#pragma pack(1)
typedef struct {
#endif // __GNUC__
  unsigned long line_num;
  unsigned long para1;
  unsigned long para2;
  unsigned long para3;
  unsigned char file_name[32];
} ASSERTION_INFO_T;
#if !defined(__GNUC__)
#pragma pack()
#endif // __GNUC__

#if defined(__GNUC__)
typedef struct __attribute__((packed)) {
#else
#pragma pack(1)
typedef struct {
#endif // __GNUC__
  unsigned long error_status;
  unsigned long error_pc;
  unsigned long error_lr;
  unsigned long error_address;
  unsigned long error_code1;
  unsigned long error_code2;
} FATAL_ERROR_INFO_T;
#if !defined(__GNUC__)
#pragma pack()
#endif // __GNUC__

#if defined(__GNUC__)
typedef struct __attribute__((packed)) {
#else
#pragma pack(1)
typedef struct {
#endif
  CS_EXCEPTION_TYPE_T except_type;
  union {
    ASSERTION_INFO_T   assert;
    FATAL_ERROR_INFO_T fatal;
  }except_content;
} CORESONIC_EXCEPTION_INFO_T;
#if !defined(__GNUC__)
#pragma pack()
#endif // __GNUC__

typedef struct {
    unsigned long              core_num;
    CORESONIC_EXCEPTION_INFO_T core_error[CS_CORE_NUMBER]; 
} CORESONIC_EXCEPTION_RECORD_T;


#endif /* __CS_EXCEP_HDLR_FORMAT_H__ */