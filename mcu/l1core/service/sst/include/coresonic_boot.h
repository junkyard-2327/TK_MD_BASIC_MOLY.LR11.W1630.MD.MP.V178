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
 *   coresonic_boot.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
 *
 * Author:
 * -------
 *   
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files.
 *******************************************************************************/
#ifndef CORESONIC_BOOT_H
#define CORESONIC_BOOT_H

#include "coresonic_boot_public.h"
#include "coresonic_access_ctrl_public.h"


typedef enum
{
    PM=0,
    ICM,
    MAX_MEM_TYPE
}DSP_MEM_TYPE;

typedef enum
{
    SIGNAL_LOW=0,
    SIGNAL_HIGH
}DSP_COMP_SIGNAL;

typedef enum
{
    CORENAME=0,
    PROJECT,
    FLAVOR,
	LABEL,
	BUILD_TIME
}DSP_VERSION_INFO;

#define CORESONIC_HRD_BEGIN_MAGIC_NUM1      (0x32524448)
#define CORESONIC_HRD_BEGIN_MAGIC_NUM2      (0x4E474542)
#define CORESONIC_HRD_END_MAGIC_NUM1        (0x32524448)
#define CORESONIC_HRD_END_MAGIC_NUM2        (0x44424545)

#define MAX_KEY_NUM                         (4)

// error code definition
#define EXE_OK                              (0)
#define READ_CORESONIC_HDR_FAILED           (1)
#define READ_CORESONIC_PM_FAILED            (2)
#define READ_CORESONIC_ICM_FAILED           (3)
#define BOOT_CORESONIC_FAILED               (4)
#define WRONG_CORESONIC_HRD_CONTENT         (5)
#define RESET_DEFAULT_VALUE_TEST_FAILED     (6)
#define WRONG_PM_ICM_LENGTH                 (7)
#define WRONG_BOOT_INC_SIZE                 (8)
#define WRONG_PM_WRITE_CNT                  (9)
#define WRONG_ICM_WRITE_CNT                 (10)
#define CHECK_PM_CRC32_FAILED               (11)
#define CHECK_ICM_CRC32_FAILED              (12)
#define BT_COMP_SIGNAL_SHOULD_BE_LOW        (13)
#define BT_COMP_SIGNAL_SHOULD_BE_HIGH       (14)
#define SET_CORESONIC_BOOT_START_FAILED     (15)
//#define WRONG_CORESONIC_C2CRF_CTRL_STATE    (16)
//#define WRONG_CORESONIC_PM_ICM_CTRL_STATE   (17)

typedef struct
{
    kal_uint32          m_pm_addr;
    kal_uint32          m_icm_addr;
    kal_uint32          m_dspbt_ctrl;
    kal_uint32          m_dspbt_status;
    kal_uint32          m_dspbt_pm_length;
    kal_uint32          m_dspbt_icm_length;
    kal_uint32          m_dspbt_pm_icm_length;
    kal_uint32          m_dspbt_inc_size;
    kal_uint32          m_dspbt_pm_crc32;
    kal_uint32          m_dspbt_icm_crc32;
    kal_uint32          m_dspbt_pm_read_cnt;
    kal_uint32          m_dspbt_pm_write_cnt;
    kal_uint32          m_dspbt_icm_read_cnt;
    kal_uint32          m_dspbt_icm_write_cnt;
    kal_uint32          m_dspbt_dynamic_dl;
//    kal_uint32          m_dspbt_c2crf_en;
//    kal_uint32          m_dspbt_pm_icm_access;
    kal_uint32         m_cidd_offset;
    kal_uint32         m_cidd_length;
    kal_uint32         m_cidd_crc;
    kal_uint32         m_IsVersionMismatched;
}coresonic_reg_addr;

typedef struct
{
    kal_uint32          m_icm_base;
    kal_uint32          m_struct_addr;
}coresonic_dsp_version;

typedef struct
{
    kal_uint32          m_core_id;
    kal_uint32          m_pm_length;
    kal_uint32          m_pm_checksum;
    kal_uint32          m_icm_length;
    kal_uint32          m_icm_checksum;
}coresonic_dsp_hdr;

typedef struct
{
    kal_uint32          m_begin_magic_num1;
    kal_uint32          m_begin_magic_num2;
    kal_uint32          m_attr;
    kal_uint32          m_coresonic_core_num;
    coresonic_dsp_hdr   m_coresonic_core[MAX_CORESONIC_NUM];
    kal_uint32          m_end_magic_num1;
    kal_uint32          m_end_magic_num2;
}coresonic_hdr;

typedef struct
{
    kal_uint32          m_cidd_core_id;
    kal_uint32          m_cidd_pm_length;
    kal_uint32          m_cidd_pm_checksum;
    kal_uint32          m_cidd_pm_offset;
    kal_uint32          m_cidd_icm_length;
    kal_uint32          m_cidd_icm_checksum;
    kal_uint32          m_cidd_icm_offset;
}cidd_coresonic_dsp_hdr;

typedef struct
{
    kal_uint32              m_begin_magic_num1;
    kal_uint32              m_begin_magic_num2;
    kal_uint32              m_attr;
    kal_uint32              m_coresonic_core_num;
    coresonic_dsp_hdr       m_coresonic_core[MAX_CORESONIC_NUM];
    cidd_coresonic_dsp_hdr  m_cidd_coresonic_core[MAX_CORESONIC_NUM];
    kal_uint32              m_end_magic_num1;
    kal_uint32              m_end_magic_num2;
}coresonic_hdr_suprt_cidd;

typedef struct dma_gpd_s {
    kal_uint8 hwo:1;
    kal_uint8 bdp:1;
    kal_uint8 bps:1;
    kal_uint8 resv1:4;
    kal_uint8 ioc:1;
    kal_uint8 cksum;
    kal_uint16 alowbufLen:16;
    kal_uint32 nextPtr;
    kal_uint32 bufPtr;
    kal_uint16 bufLen;
    kal_uint8 extLen;   // TGPD : ExtensionLength, RGPD : TransferredDataBufferLength[23:16]
    kal_uint8 bufLen2;  // TGPD : DataBufferLength[23:16], RGPD : AllowDataBufferLength[23:16]
} dma_gpd_t;

typedef enum
{
    NONE=0,
    XOR_CIPHER_ENABLED=1,
    XOR_CHECKSUM_ENABLED=2,
    SW_CIDD_ENABLED=4
}coresonic_image_attr;

#endif  /* CORESONIC_BOOT_H */
