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
 *   SST_secure.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is header file for SST_secure.c
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
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __SST_SECURE_H__
#define __SST_SECURE_H__

/*******************************************************************************
 * Included header files
 *******************************************************************************/

#include "kal_general_types.h"

#if defined(__PCORE__)
#include "sst_interface.h"
#include "nvram_data_items.h"
#include "kal_public_defs.h"
#include "reg_base.h"
#endif /* __PCORE__ */

/*************************************************************************
 * External global data declaration
 *************************************************************************/

/*************************************************************************
 * External Function Declaration
 *************************************************************************/

/*************************************************************************
 * Type definitions
 *************************************************************************/
 
/* max size of NVRAM secret key in bytes*/
#define NVRAM_KEY_GEN_AES_LEN                        32
#define NVRAM_KEY_GEN_MAX_KEY_LEN                    256

/* Error types of get NVRAM key*/
#define GET_NVRAM_KEY_ERROR_NONE                      0
#define GET_NVRAM_KEY_ERROR_KEY_BUFFER_INVALID       -1  // input buffer pointer is NULL
#define GET_NVRAM_KEY_ERROR_KEY_SEED_BUFFER_INVALID  -2  // input seed buffer pointer is NULL
#define GET_NVRAM_KEY_ERROR_KEY_LEN_EXCEED_MAX       -3  // input len exceed NVRAM_KEY_MAX_LEN
#define GET_NVRAM_KEY_ERROR_KEY_SEED_LEN_NOT_MATCH   -4

#if defined(__PCORE__)

#define PROTECTED_LID_ERROR_NONE                      0x0
#define PROTECTED_LID_ERROR_SECURE_NOT_ALLOWED        0x1000
#define PROTECTED_LID_ERROR_NORMAL_R_FORBID           0x1001
#define PROTECTED_LID_ERROR_NORMAL_W_FORBID           0x1002

#define SST_PROTECTED_NVRAM_LID_READ_LIMIT             0x1
#define SST_PROTECTED_NVRAM_LID_WRITE_LIMIT            0x2

// For checkin function of secure nvram API
typedef struct sst_protected_nvram_lid_struct {
    nvram_lid_enum          m_lid;
    kal_uint16              m_attr;
} SST_PROTECTED_NVRAM_LID;

// TODO : module ID == task ID ??
typedef struct sst_allowed_task_struct {
    module_type             m_mod_id;
} SST_ALLOWED_TASK;

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
#if defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__)
#define SECURE_RO_SIZE_OVERHEAD 0	//SEC_RO has no GFH for external phone
#else
#define SECURE_RO_SIZE_OVERHEAD 404 
#endif /*defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__)*/
#else
#define SECURE_RO_SIZE_OVERHEAD  0
#endif


// AP HRID location
#if defined(TK6291)

// No HRID, use MEID instead 
#define EFUSE_HRID0                         ((volatile unsigned *)(0xFFFFFFFF))
#define EFUSE_HRID1                         ((volatile unsigned *)(0xFFFFFFFF))

/* Efuse base from MD view
 * 0xC0206000 MT6755, MT6797, MT6750, MT6757, MT6757P, MT6750S(ROSA)
 */
// from Everest/Elbrus/Whitney these high-end project, efuse has 128 bits
#elif defined(MT6755) || defined(MT6797) || defined(MT6750) || defined(MT6757) || defined(MT6757P) || defined(MT6750S)
#define EFUSE_HRID0                         ((volatile unsigned *)(EFUSE_base+0x0140))
#define EFUSE_HRID1                         ((volatile unsigned *)(EFUSE_base+0x0144))
#else

#error "Not Supported Chips"

#endif


/*************************************************************************
 * Export API of SSS and SST
 *************************************************************************/
extern kal_bool   SST_Is_Secure_BB(void);

extern kal_bool SST_Get_ChipUID(kal_char *pUid, kal_int32 buf_len);


extern void SST_Secure_Algo (kal_uint8 Direction, kal_uint32 ContentAddr,
                             kal_uint32 ContentLen, kal_uint8 *CustomSeed,
                             kal_uint8 *ResText);

extern void SST_Secure_Algo_With_Level (kal_uint8 Direction, kal_uint32 ContentAddr,
                        kal_uint32 ContentLen, kal_uint8 *CustomSeed, kal_uint32 Level,
                        kal_uint8 *ResText);

extern kal_bool SST_Get_NVRAM_Key(kal_uint32 *p_key, kal_uint32 *p_addr, kal_uint32 *p_len);
   
extern void SST_Get_Secure_RO (kal_uint8 *CustomSeed, kal_uint8 *ResText, kal_uint32 ResLen);

extern void SST_DTLB_Init (void);

extern void SST_SetBootupMode(kal_bool bIsFactoryBin);

extern kal_int32 SST_VerifyNFBImageContent(void* func_ptr, void* cache_ctrl_ptr, kal_uint32 binRes);

extern void SST_VerifyNFBSecondaryImage(void);

extern kal_int32 SST_VerifyImageContent(kal_uint32 secinfo_addr, kal_uint32 mac_addr, kal_bool bFactoryBin);

extern kal_int32 SST_VerifyExtBootloader(kal_uint32 ebl_addr, kal_uint32 ebl_len, kal_uint32 ebl_header_addr, kal_uint32 ebl_header_len);

extern void SST_Load_Data_For_SUSBDL(void* func_ptr);

extern kal_bool SST_CheckImageInfo(void);

extern kal_uint32 SST_GetBootloaderSize(void);

extern kal_uint32 SST_GetUAImageHeadSize(void);

extern kal_uint32 SST_GetUAImageTailSize(void);

extern kal_bool SST_SearchUAImageHead(kal_uint8 *buff, kal_uint32 buff_size, kal_uint8* info_buff, kal_uint32 *info_size);

extern kal_bool SST_SearchUAImageTail(kal_uint8 *buff, kal_uint32 buff_size, kal_uint8* info_buff, kal_uint32 *info_size);

extern kal_uint32 SST_VerifyBinaryByParent(kal_uint32 *pParentBinary, kal_uint32 *pTargetBinary);

extern kal_bool SST_VerifyMAUI(kal_uint32 *pParentBin, kal_uint32 *pMAUI);

extern kal_bool SST_VerifyDspROM(kal_uint32 *pParentBin, kal_uint32 *pDSP);

extern kal_uint32 SST_CheckBootloaderHash(kal_uint32* pBinary);

extern void SSS_Init_Share_Crypto_Drv(void * cb_ts_record, void * cb_ts_info, kal_uint32 init_tbl);

extern void SSS_Init_Crypto_Drv(void * cb_ts_record, void * cb_ts_info);

extern kal_uint32* SST_GetToken(void);

extern void SST_SetToken(kal_uint32 *pToken, kal_uint32 tokenLen);

extern kal_bool bl_Is_Brom_Cmd_Mode_Disabled(void);

/*****************************************************************************
 * FUNCTION
 *  SST_NVRAM_Data_Access_Check
 * DESCRIPTION
 *  This function is to check the access to sensive or secure NVRAM data item.
 *  It is for internal used for NVRAM and security.
 * PARAMETERS
 *  LID:                               [IN]    NVRAM LID
 *  rw:                                 [IN]    read or write access : 0 => read, 1 => write
 *  is_secure_data_access:   [IN]    Secure or normal access : 0 => normal, 1 => secure
 * RETURNS
 *  unsigned 32 bits
 * RETURN VALUES
 *  0 :  check pass
 *  otherwise :  check failed, please must not allowed to read nvram if checking failed
 *****************************************************************************/
extern kal_uint32 SST_NVRAM_Data_Access_Check(nvram_lid_enum LID, kal_int32 rw, kal_bool is_secure_data_access, void * reserved_ptr);

extern kal_int32 SST_Get_Chip_Unique_Seed(unsigned * hrid0, unsigned * hrid1);


#endif /* __PCORE__ */

#if !defined(__SECURE_RO_ENABLE__) && defined(__NVRAM_KEY_RUNTIME_GEN__)
extern kal_int32 SST_Get_NVRAM_SW_Key(void * pNVKey, kal_uint32 nNVKeySize, void * pKeySeed, kal_uint32 nKeySeedSize);
#endif /* !__SECURE_RO_ENABLE__ &&  __NVRAM_KEY_RUNTIME_GEN__ */

extern kal_bool SST_Is_SW_Dbg_Enabled(void);


#endif //__SST_SECURE_H__
