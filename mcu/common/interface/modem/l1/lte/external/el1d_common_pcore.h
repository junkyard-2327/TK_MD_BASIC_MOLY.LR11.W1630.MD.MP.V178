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
 * el1d_common_pcore.h
 *
 * Project:
 * --------
 * MT6755
 *
 * Description:
 * ------------
 * EL1D DSP Table Common define
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
 * removed!
 *
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _EL1D_COMMON_PCORE_H_
#define  _EL1D_COMMON_PCORE_H_


#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"

#include "sync_data.h"
#include "cache_sw.h"
#include "mmu.h"

/*******************************************************************************
 * #define
 ******************************************************************************/
#define DSPEMI_ADDR_READY  0xA7A75A5A

#if defined(__PCORE__)
#define EL1D_DEFINE_DNC_SHARED_VAR(type, name)                    DEFINE_DNC_SHARED_VAR(type, name)

#define EL1D_DECLARE_SHARED_VAR(type, name)                       DECLARE_SHARED_VAR(type, name)
#define EL1D_DECLARE_SHARED_ARRAY(type, name, size)               DECLARE_SHARED_ARRAY(type, name, size)

#define EL1D_SHARED_VAR(name)      SHARED_VAR(name)
#define EL1D_SHARED_ARRAY(name)    SHARED_ARRAY(name)
#define EL1D_SHARED_pVAR(name)     SHARED_pVAR(name)
#define EL1D_SHARED_pARRAY(name)   SHARED_pARRAY(name)

#elif defined(__L1CORE__)
#define EL1D_DEFINE_DNC_SHARED_VAR(type, name)                    DEFINE_DNC_SHARED_VAR(type, name)

#define EL1D_DECLARE_SHARED_VAR(type, name)                       DECLARE_SHARED_VAR(type, name)
#define EL1D_DECLARE_SHARED_ARRAY(type, name, size)               DECLARE_SHARED_ARRAY(type, name, size)

#define EL1D_SHARED_VAR(name)      SHARED_VAR(name)
#define EL1D_SHARED_ARRAY(name)    SHARED_ARRAY(name)
#define EL1D_SHARED_pVAR(name)     SHARED_pVAR(name)
#define EL1D_SHARED_pARRAY(name)   SHARED_pARRAY(name)

#endif

#define EL1D_CUSTOM_DEFINE_SHARED_VAR(type, name)                 EL1D_DEFINE_DNC_SHARED_VAR(type, name)

#define EL1D_CUSTOM_DECLARE_SHARED_VAR(type, name)                EL1D_DECLARE_SHARED_VAR(type, name)
#define EL1D_CUSTOM_DECLARE_SHARED_ARRAY(type, name, size)        EL1D_DECLARE_SHARED_ARRAY(type, name, size)

/* SHM Usage Macros for RF data */
#define EL1D_CUSTOM_SHARED_VAR(name)                  EL1D_SHARED_VAR(name)
#define EL1D_CUSTOM_SHARED_ARRAY(name)                EL1D_SHARED_ARRAY(name)
#define EL1D_CUSTOM_SHARED_pVAR(name)                 EL1D_SHARED_pVAR(name)
#define EL1D_CUSTOM_SHARED_pARRAY(name)               EL1D_SHARED_pARRAY(name)

#define EL1D_ALIGNTOCACHELINE(size) ALIGNTOCACHELINE(size)

#if !defined(L1_SIM) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
#define EL1D_CUSTOM_SHARED_DATA_SET_TO_CACHE(ptr, size)   dynamic_switch_cacheable_region(&(ptr), EL1D_ALIGNTOCACHELINE(size), PAGE_CACHEABLE )
#define EL1D_CUSTOM_SHARED_DATA_SET_TO_NOCACHE(ptr, size) dynamic_switch_cacheable_region(&(ptr), EL1D_ALIGNTOCACHELINE(size), PAGE_NO_CACHE )

#define EL1D_CUSTOM_SHARED_DATA_CACHE_FLUSH(ptr, size)        \
{ \
   dynamic_switch_cacheable_region( &(ptr), EL1D_ALIGNTOCACHELINE(size), PAGE_NO_CACHE ); \
   dynamic_switch_cacheable_region( &(ptr), EL1D_ALIGNTOCACHELINE(size), PAGE_CACHEABLE ); \
}
#else
#define EL1D_CUSTOM_SHARED_DATA_SET_TO_CACHE(ptr, size)
#define EL1D_CUSTOM_SHARED_DATA_SET_TO_NOCACHE(ptr, size)
#define EL1D_CUSTOM_SHARED_DATA_CACHE_FLUSH(ptr, size)
#endif

#define EL1D_NVRAM_ERROR_CHECK           0x6291

/*******************************************************************************
 * typedef
 ******************************************************************************/

/** RF Calibration data structure */
typedef struct
{
   kal_uint32 u4g_imc_mpc_rxt2f_droop_tbl_nonca_addr;          /*DSP Boot*/
   kal_uint32 u4g_imc_mpc_rxt2f_droop_tbl_nonca_cm_addr;       /*DSP Boot*/
   kal_uint32 u4g_imc_mpc_rxt2f_droop_tbl_abb_tia0abb0_addr;   /*RX/CM*/
   kal_uint32 u4g_imc_mpc_rxt2f_droop_tbl_abb_tia0abb1_addr;   /*RX/CM*/
   kal_uint32 u4g_imc_mpc_rxt2f_droop_tbl_abb_tia1abb0_addr;   /*RX/CM*/
   kal_uint32 u4g_imc_mpc_rxt2f_droop_tbl_abb_tia1abb1_addr;   /*RX/CM*/
   kal_uint32 u4g_imc_mpc_rxt2f_droop_tbl_prenco_addr  ;       /*RX/CM*/
   kal_uint32 u4g_imc_mpc_rxt2f_droop_tbl_postnco_addr ;       /*RX/CM*/
   kal_uint32 u4g_icc_crs_mrs_ne_coef_addr ;                   /*DSP Boot*/
   kal_uint32 u4g_icc_md_coef_addr ;                           /*DSP Boot*/
   kal_uint32 u4g_imc_csi_hw_tbl_addr ;                        /*DSP Boot*/
   kal_uint32 u4g_imc_dmrs_coef_addr;                          /*DSP Boot*/
   kal_uint32 u4g_mpc_ncm_ne_coef_addr ;                       /*DSP Boot*/
   kal_uint32 u4g_mpc_cmpath_droop_tbl_nonca_addr ;            /*DSP Boot*/
   kal_uint32 status; //ready pattern

} LTE_DSPTABLE_EMI_T;

/** EL1D TX Feature structure */
typedef struct
{
   kal_uint32 tx_feature_0;
   kal_uint32 tx_feature_1;
} LTE_EL1D_TX_FEATURE_T;

/** EL1D RX Feature structure */
/** 
 * @brief   See @ref LTE_EL1D_RX_FEATURE_T
 * @details rx_feature_2_ntf_dsp: 
 *          BIT1 ~BIT31: Reserved.
 *          BIT0 ~BIT0 : Inform BRP to disable CMCC CR2CQI mapping table. TRUE: is to disable. FALSE: is to enable only for TM8(implement in BRP)
 * @date    2016.02.25
 */
typedef struct
{
   kal_uint32 rx_feature_0_lp_turn_off;
   kal_uint32 rx_feature_1_arx_manual;
   kal_uint32 rx_feature_2_ntf_dsp;
   kal_uint32 rx_feature_3;
   kal_uint32 rx_feature_4;
} LTE_EL1D_RX_FEATURE_T;

/** EL1D CS Feature structure */
typedef struct
{
   kal_uint32 cs_feature_0;
   kal_uint32 cs_feature_1;
} LTE_EL1D_CS_FEATURE_T;

/** EL1D CM Feature structure */
typedef struct
{
   kal_uint32 cm_feature_0;
   kal_uint32 cm_feature_1;
} LTE_EL1D_CM_FEATURE_T;

/** EL1D Common Feature structure */
typedef struct
{
   kal_uint32 common_feature_0_lock_sleep;
   kal_uint32 common_feature_1_force_on_cg_sram;
   kal_uint32 common_feature_2;
   kal_uint32 common_feature_3;
   kal_uint32 common_feature_4;
   kal_uint32 common_feature_5;
   kal_uint32 common_feature_6;
   kal_uint32 error_check;
} LTE_EL1D_COMMON_FEATURE_T;

/** EL1D Feature structure */
typedef struct
{
   LTE_EL1D_TX_FEATURE_T      el1d_tx;
   LTE_EL1D_RX_FEATURE_T      el1d_rx; 
   LTE_EL1D_CS_FEATURE_T      el1d_cs;
   LTE_EL1D_CM_FEATURE_T      el1d_cm;
   LTE_EL1D_COMMON_FEATURE_T  el1d_common;
} LTE_EL1D_FEATURE_NVRAM_T;


/*===============================================================================*/

/*******************************************************************************
 * Functions Prototype
 ******************************************************************************/

void el1d_dsptable_shm_data_pointer_init(void);
void EL1D_FEATURE_NVRAM_TO_SHM(void);


#endif /* End of #ifndef _EL1D_DSPTABLE_COMMON_H_ */

