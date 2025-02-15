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
 *   maui_GFH_body.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain the GFH body and content for all MAUI parts
 *
 * Author:
 * -------
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "br_GFH.h"
#include "br_GFH_file_info.h"
#include "br_GFH_maui_info.h"
#include "br_GFH_flash_info.h"
#include "br_GFH_cbr_info.h"
#include "br_GFH_maui_sec.h"
#include "br_GFH_secure_ro_info.h"
#include "br_GFH_binary_location.h"
#include "SST_init.h"

#include "GFH_defs.h"
#include "maui_GFH_body.h"

#include "feature_def.h"

#include "custom_img_config.h"

#include "kal_general_types.h"

#ifdef _NAND_FLASH_BOOTING_
#include "NAND_DAL_Version.h"
#endif

#ifdef __BOOT_CERT_V2__
#include "boot_cert_pattern.h"
#endif 

//==============================================================================
// Linker symbols
//==============================================================================

extern kal_uint32 Image$$ROM$$Base;

extern kal_uint32 INT_VECTOR_CODE$$Base;
extern kal_uint32 INT_VECTOR_CODE$$Limit;


extern kal_uint32 Image$$ROM_GFH$$Length;
extern kal_uint32 Load$$ROM_GFH$$Base;


extern kal_uint32 Image$$SECURE_RO_S_GFH$$Length;
extern kal_uint32 Load$$SECURE_RO_S_GFH$$Base;

extern kal_uint32 Image$$SECURE_RO_ME_GFH$$Length;
extern kal_uint32 Load$$SECURE_RO_ME_GFH$$Base;

//==============================================================================
// Section definition
//==============================================================================

#undef __section

#ifdef __MTK_TARGET__
#define __section(S)                         __attribute__ ((used,section(#S)))
#else
#define __section(S)
#endif

#define __maui_iv_region_section__           __section(MAUI_IV_REGION)
#define __maui_gfh__                         __section(MAUI_GFH)
#define __maui_signature_section__           __section(MAUI_SIGNATURE_SECTION)
#define __secure_ro_s_gfh__                  __section(SECURE_RO_S_GFH)
#define __secure_ro_s_signature_section__    __section(SECURE_RO_S_SIGNATURE_SECTION)
#define __secure_ro_me_gfh__                 __section(SECURE_RO_ME_GFH)
#define __secure_ro_me_signature_section__   __section(SECURE_RO_ME_SIGNATURE_SECTION)

/* SECURE RO S is not ready yet, we use a macro to disable it first */
#define __SECURE_RO_S_DISABLE__

//==============================================================================
// MAUI parameters
//==============================================================================

//Define where the MAUI locates
#if defined (_NAND_FLASH_BOOTING_)

#define MAUI_DEVICE_TYPE           F_NAND_FDM50
#define BINARY_ATTRIBUTE           0

#elif defined (__EMMC_BOOTING__)

#define MAUI_DEVICE_TYPE           F_EMMC_DATA_REGION
#define BINARY_ATTRIBUTE           0

#elif defined(__X_BOOTING__)

#define MAUI_DEVICE_TYPE           F_XBOOT
#define BINARY_ATTRIBUTE           0

#else

#if defined(__SERIAL_FLASH_EN__)
#define MAUI_DEVICE_TYPE           F_SF
#else
#define MAUI_DEVICE_TYPE           F_NOR
#endif

#if defined(__XIP_SHADOWING__)
#define BINARY_ATTRIBUTE           0
#else
#endif
#define BINARY_ATTRIBUTE           FILE_INFO_ATTR_XIP

#endif


//Define the size of MAUI iv region
#define MAUI_IV_REGION_LEN         0x80
#define MAUI_IV_REGION_MARK        "IV_REGION"

//Define the signature type of MAUI binaries
#define P_MAUI_SIGNATURE_TYPE      SIG_SINGLE
#define P_MAUI_SIGNATURE_LEN       SIG_SINGLE_LEN

//Constants
#define DUMMY_END (0xffffffff)

//Define the version of MAUI software
#define MAUI_VERSION               1
#define SECURE_RO_VERSION          1


//==============================================================================
// MAUI's initial vector region
//==============================================================================

__maui_iv_region_section__ const char g_maui_iv_region[MAUI_IV_REGION_LEN] = MAUI_IV_REGION_MARK;


//==============================================================================
// MAUI's GFH header body
//==============================================================================


__maui_gfh__ const MAUI_GFH g_maui_gfh = 
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         MAUI_VERSION,
#ifndef __FACTORY_BIN__         
         PRIMARY_MAUI,
#else
         PRIMARY_FACTORY_BIN,
#endif
         MAUI_DEVICE_TYPE,
         P_MAUI_SIGNATURE_TYPE,
         
         (kal_uint32)(&Load$$ROM_GFH$$Base) + MAUI_IV_REGION_LEN,
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_ROM,
         (kal_uint32)(&Image$$ROM_GFH$$Length) - MAUI_IV_REGION_LEN,
         P_MAUI_SIGNATURE_LEN,
         (kal_uint32)(&Image$$ROM$$Base),
         BINARY_ATTRIBUTE
      },

      //GFH_MAUI_INFO_v2
      {  
         GFH_HEADER(GFH_MAUI_INFO, 2),

         //platform_id & project_id
         "N/A",
         "N/A",

         1, //BL_MAUI_PAIRED_VER,
         FEATURE_COMBINATION,
         FEATURE_COMBINATINO_EX,
         0,
         SW_MINOR_VER,
#ifdef __SECURE_DATA_STORAGE__         
         SDS_START_ADDR, 
         SDS_TOTAL_SIZE,
#else
         0,
         0,
#endif
#ifdef MT6280
		2,
#else
         MIN_FLASHTOOL_VER_REQURIEMENT,
#endif     
#ifdef __BOOT_CERT_V2__
         (kal_uint32)&g_SRD_INFO,
         (kal_uint32)sizeof(g_SRD_INFO),
#else
         0,0,
#endif
         {0}
         
      },

      //GFH_FLASH_INFO_v1
      {
         GFH_HEADER(GFH_FLASH_INFO, 1),
#ifdef _NAND_FLASH_BOOTING_            
         { 0x30, (FDM_MAJOR_VER+0x30), (FDM_MINOR_VER1+0x30), (FDM_MINOR_VER2+0x30),
           0x30, (DAL_MAJOR_VER+0x30), (DAL_MINOR_VER1+0x30), (DAL_MINOR_VER2+0x30) 
         },
#endif            
      },

      //GFH_CBR_INFO_v2
      {
         GFH_HEADER(GFH_CBR_INFO, 2),
         0, //CBR_REGION_NORMAL_BLOCK_NUM,
         0, //CBR_REGION_SPARE_BLOCK_NUM,
         0,
         0
      },

#ifdef __MTK_SECURE_PLATFORM__      
      //GFH_MAUI_SEC_v1 
      {
         GFH_HEADER(GFH_MAUI_SEC, 1),
      },
#endif /* __MTK_SECURE_PLATFORM__ */
      
      //GFH_MAUI_CODE_KEY_v1, for Code binaries
      {  
         GFH_HEADER(GFH_MAUI_CODE_KEY, 1),
      },

      //GFH_MAUI_SECURE_RO_KEY_v1, for Secure RO
      /*{  
         GFH_HEADER(GFH_MAUI_SECURE_RO_KEY, 1),
      },*/

#ifdef __FOTA_DM__
      //GFH_FOTA_INFO_v1
      {
         GFH_HEADER(GFH_FOTA_INFO, 1),
         FOTA_PACKAGE_STORAGE_BASE,
         FOTA_PACKAGE_STORAGE_SIZE,
         FOTA_BACKUP_STORAGE_BASE,
         FOTA_BACKUP_STORAGE_SIZE,
         FOTA_EXTRA_RESERVED_BLOCKS,       
      },
#endif

#ifdef __XIP_SHADOWING__
      //GFH_BINARY_LOCATION_v1
      {
         GFH_HEADER(GFH_BINARY_LOCATION, 1),
#ifndef __FACTORY_BIN__ 
         MAUI_ROM_START_ADDR
#else
         FACTORY_ROM_START_ADDR
#endif
      },
#endif

      //GFH_VEC_INFO_v1
      {
         GFH_HEADER(GFH_VEC_INFO, 1),
		 (kal_uint32)(&INT_VECTOR_CODE$$Base),
         (kal_uint32)(&INT_VECTOR_CODE$$Limit)	 
      },

};

//==============================================================================
// MAUI's Signature
//==============================================================================
__maui_signature_section__ const unsigned long g_maui_sig[P_MAUI_SIGNATURE_LEN>>2] = {SIG_HASH_VER};

//==============================================================================
// Misc
//==============================================================================
kal_uint32 DummyReference()
{
    kal_uint32 size = 0;

    size += (kal_uint32)(&g_maui_iv_region)+(kal_uint32)(&g_maui_gfh)+(kal_uint32)(&g_maui_sig);

    return size;
}


