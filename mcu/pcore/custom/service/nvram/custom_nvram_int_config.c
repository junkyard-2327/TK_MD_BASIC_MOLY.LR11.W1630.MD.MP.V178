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

/*******************************************************************************
 * Filename:
 * ---------
 * custom_nvram_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   The file contains nvram configuration default value.
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_NOT_PRESENT

#include "kal_general_types.h"

#include "nvram_enums.h"            /* NVRAM_CLEAN_FOLDER_FACTORY */
#include "custom_nvram_int_config.h"
#include "nvram_data_items.h"
#include "ccci_if.h" //for SBP ccci misc info
#include "ps_public_utility.h"
#include "nvram_interface.h"
#include "nvram_editor_data_item.h"
#include "sim_public_enum.h"

#include "gmss_public.h"

#if defined(__MTK_TARGET__) || defined(__UE_SIMULATOR__)
#if defined(__UMTS_RAT__)
#include "hal_ul1_struct.h" //for UL1_IS_3G_FDD_EXIST_PCORE()
#include "tl1_cc_public.h" //for TL1_IS_3G_TDD_EXIST
#endif
#if defined(__EL1_ENABLE__)
#include "el1_public_api.h" //for EL1_IS_4G_FDD_EXIST() and EL1_IS_4G_TDD_EXIST()
#endif
#endif

#include "sbp_public_utility.h"

#ifndef __MTK_TARGET__
extern unsigned int g_w32_MoDIS_SBPID; //for SBP support in MoDIS
extern unsigned int g_w32_MoDIS_WMID; //for WM ID in MoDIS
#endif

#ifdef __GEMINI_3G_SWITCH__
extern kal_uint8 MASTER_SIM_CFG;
#endif

#if defined(__PCORE__)
extern kal_uint32 default_sbp_id;
#endif
extern kal_uint32 sbp_sub_id;

extern void gmss_set_duplex_mode(umts_duplex_mode_type mode_3g, lte_duplex_mode_type mode_4g);
void custom_nvram_set_world_mode_id(kal_uint32 world_mode);
/*******************************************************************************
 * Global variables
 *******************************************************************************/
#if defined (__MML1_ADT_ENABLE__) && defined(__MTK_TARGET__)
DEFINE_NC_SHARED_VAR(kal_uint32,nvram_rat_mode)
DEFINE_NC_SHARED_VAR_ASSIGN(kal_bool, nvram_read_done, KAL_FALSE)
#endif


/*
 * Restore factory begin
 */


/*****************************************************************************
 * FUNCTION
 *  nvram_custom_get_max_record_size
 * DESCRIPTION
 *  Return the maximum record size, every nvram lid record size cannot bigger than this
 * PARAMETERS
 * RETURNS
 *  maximum record size
 *****************************************************************************/
kal_uint32 nvram_custom_max_record_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return NVRAM_CUSTOM_CFG_MAX_RECORD_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_custom_lock_pattern
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_bool nvram_custom_lock_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (NVRAM_CUSTOM_CFG_DEFAULT_LOCK_STATUS == __UNLOCKED__)
    return KAL_FALSE;
#else
    return KAL_TRUE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_set_world_mode_id
 * DESCRIPTION
 * similar to custom_nvram_config()
 * PARAMETERS
 *  world_mode  [IN]
 * RETURNS
 *  none
 *****************************************************************************/

void custom_nvram_set_world_mode_id(kal_uint32 world_mode)
{
    nvram_ef_sbp_modem_data_config_struct sbp_data_buf;
        
    if (world_mode != 0)
    {
       /* World Mode ID Format: 0|0|Lf|Lt|W|C|T|G 
               validiate with efuse
            */
#if defined(__MTK_TARGET__) || defined(__UE_SIMULATOR__)
#if defined(__EL1_ENABLE__)
        if (((EL1_IS_4G_FDD_EXIST() != KAL_TRUE) && ((world_mode & 0x20) != 0))
            || ((EL1_IS_4G_TDD_EXIST() != KAL_TRUE) && ((world_mode & 0x10) != 0)))
        {
            DEBUG_ASSERT(0);
        }
#endif
#if defined(__UMTS_RAT__)
        if (((UL1_IS_3G_FDD_EXIST_PCORE() != KAL_TRUE) && ((world_mode & 0x08) != 0))
            || ((TL1_IS_3G_TDD_EXIST() != KAL_TRUE) && ((world_mode & 0x02) != 0)))
        {
            DEBUG_ASSERT(0);
        }
#endif
#endif
            
        /* Read current settings in NVRAM */
        nvram_external_read_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                                 1, 
                                 (kal_uint8*)&sbp_data_buf, 
                                 NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);
        
        sbp_set_md_feature_data(SBP_WORLD_MODE, (kal_uint8)world_mode, &sbp_data_buf);
  
        /* Write the new settings back to NVRAM */
        nvram_external_write_data(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID, 
                                  1, 
                                  (kal_uint8*)&sbp_data_buf, 
                                  NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_config
 * DESCRIPTION
 *  Pre-process nvram data items at nvram task init.
 *  This function will be always invoked at nvram task init, right after NVRAM initialization.
 *  User can pre-process nvram data items via using NVRMA external API here.
 *     nvram_external_write_data()
 *     nvram_external_read_data()
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
void custom_nvram_config(void)
{
#if defined (__MML1_ADT_ENABLE__) && defined(__MTK_TARGET__)
   kal_bool   error_no;
   kal_uint32 pdu_length = sizeof(nvram_ef_rac_preference_struct);

   SHARED_VAR(nvram_read_done) = KAL_FALSE;   
   nvram_ef_rac_preference_struct *nvram_ef_rac_setting = (nvram_ef_rac_preference_struct *)get_ctrl_buffer(sizeof(nvram_ef_rac_preference_struct));
   
   error_no = nvram_external_read_data(NVRAM_EF_RAC_PREFERENCE_LID, 1, (kal_uint8 *)nvram_ef_rac_setting, pdu_length);
   ASSERT(error_no == KAL_TRUE);
   
   SHARED_VAR(nvram_rat_mode) = nvram_ef_rac_setting->rat_mode;
   SHARED_VAR(nvram_read_done) = KAL_TRUE;

   free_ctrl_buffer(nvram_ef_rac_setting);
#endif

    kal_uint32 misc_info[4];
    kal_uint32 sbp_id = 0;
    kal_uint32 world_mode = 0;
    kal_uint32 sub_id = 0;
    protocol_id_enum ps_id;

#ifndef __MTK_TARGET__
    sbp_id = g_w32_MoDIS_SBPID;
    world_mode = g_w32_MoDIS_WMID;
    
#elif defined(__HIF_CCCI_SUPPORT__)
    if (ccci_misc_data_feature_support(CCMSG_ID_MISCINFO_SBP_ID, 16, misc_info) == CCCI_MISC_INFO_SUPPORT)
    {
        /* CCCI_MISC_INFO_SUPPORT means AP has sent SBP ID or WM ID to modem */
        sbp_id = misc_info[0];
        world_mode = misc_info[1];        
		sub_id = misc_info[2];
    #if defined(__PCORE__)
        default_sbp_id = sbp_id;
	    sbp_sub_id = sub_id;
    #endif
    }
#endif

    
#ifdef __GEMINI_3G_SWITCH__
{   // Read current SIM MAP setting
    kal_uint8 data[8];

    nvram_external_read_data(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, data, NVRAM_EF_SYS_CACHE_OCTET_SIZE);
    MASTER_SIM_CFG = data[L4C_SETTING_3G_SERVICE_BITMAP];
}
#endif

    /****************************************************************** 
      Update SBP ID first and then WorldMode ID 
      Otherwise NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID would be overwrite
     ******************************************************************/
    /* SBP Multiple context */
    for (ps_id = PROTOCOL_1; ps_id < MAX_SIM_NUM ; ps_id++)
    {
        custom_nvram_set_sbp_id(sbp_id, KAL_FALSE, NULL, ps_id);
    }
    
    custom_nvram_set_world_mode_id(world_mode);
}


/*****************************************************************************
 * FUNCTION
 *  custom_default_mode_config
 *
 * DESCRIPTION
 *  Pre-process default GMSS duplex mode at nvram task init.
 *  This function will be always invoked at nvram task init, right after NVRAM initialization
 *  This function must be called after CCCI info is handled (custom_nvram_config)
 *  User can pre-process nvram data items via using NVRMA external API here:
 *     nvram_external_write_data()
 *     nvram_external_read_data()
 *
 * PARAMETERS
 *  none
 *
 * RETURNS
 *  none
 *****************************************************************************/
void custom_default_mode_config(void)
{
    kal_uint8 i;
    kal_uint8 op_id = sbp_query_id();
    kal_uint8 wm_id = sbp_query_md_feature_data(SBP_WORLD_MODE);
    kal_uint8 *buffer = NULL;
    kal_uint16 sim_idx;
    nvram_ef_nwsel_data_struct *nwsel_data_ptr = NULL;
    umts_duplex_mode_type umts_duplex_mode;
    lte_duplex_mode_type lte_duplex_mode;

    buffer = (kal_uint8*) get_ctrl_buffer(NVRAM_EF_NWSEL_DATA_SIZE);

    switch (wm_id)
    {
        case GMSS_WM_LWCTG:
        case GMSS_WM_LWTG:

            for (i = 0; i < MAX_SIM_NUM; i++)
            {
                #ifdef __GEMINI_3G_SWITCH__
                sim_idx = 1 + (kal_uint16)(l4c_gemini_get_actual_sim_id((sim_interface_enum)i));
                #else
                sim_idx = i+1;
                #endif

                nvram_external_read_data(
                    NVRAM_EF_NWSEL_DATA_LID, sim_idx, buffer, NVRAM_EF_NWSEL_DATA_SIZE);

                nwsel_data_ptr = (nvram_ef_nwsel_data_struct*)buffer;

                if (((nwsel_data_ptr->gmss_data.umts_duplex_mode == UMTS_WCDMA_DUPLEX_MODE) ||
                     (nwsel_data_ptr->gmss_data.umts_duplex_mode == UMTS_TDSCDMA_DUPLEX_MODE)) &&
                    ((nwsel_data_ptr->gmss_data.lte_duplex_mode == LTE_FDD_DUPLEX_MODE) ||
                     (nwsel_data_ptr->gmss_data.lte_duplex_mode == LTE_TDD_DUPLEX_MODE) ||
                     (nwsel_data_ptr->gmss_data.lte_duplex_mode == LTE_FDD_TDD_DUPLEX_MODE)))
                {
                    /* NVRAM setting is valid, use directly */
                    umts_duplex_mode = nwsel_data_ptr->gmss_data.umts_duplex_mode;
                    lte_duplex_mode = nwsel_data_ptr->gmss_data.lte_duplex_mode;
                }
                else
                {
                    /* NVRAM setting is not valid, decide default duplex mode by op_id */
                    switch (op_id)
                    {
                        /* L+T */
                        case 1:     /* CMCC */
                            umts_duplex_mode = UMTS_TDSCDMA_DUPLEX_MODE;
                            lte_duplex_mode = LTE_FDD_TDD_DUPLEX_MODE;
                            break;

                        /* L+W */
                        case 0:     /* Open Market */
                        default:
                            umts_duplex_mode = UMTS_WCDMA_DUPLEX_MODE;
                            lte_duplex_mode = LTE_FDD_TDD_DUPLEX_MODE;                            
                            break;
                    }

                    nwsel_data_ptr->gmss_data.umts_duplex_mode = (kal_uint8)umts_duplex_mode;
                    nwsel_data_ptr->gmss_data.lte_duplex_mode = (kal_uint8)lte_duplex_mode;

                    nvram_external_write_data(
                        NVRAM_EF_NWSEL_DATA_LID, sim_idx, buffer, NVRAM_EF_NWSEL_DATA_SIZE);
                }

                /* Currently duplex mode is unique for all SIMs (Apply setting of SIM1) */
                if (i == 0)
                {
                    gmss_set_duplex_mode(umts_duplex_mode, lte_duplex_mode);
                }
            }
            break;

        /* L+W */
        case GMSS_WM_LWCG:
        case GMSS_WM_LWG:
            gmss_set_duplex_mode(UMTS_WCDMA_DUPLEX_MODE, LTE_FDD_TDD_DUPLEX_MODE);
            break;

        /* Lf+W */
        case GMSS_WM_LFWG:
        case GMSS_WM_LFWCG:
            gmss_set_duplex_mode(UMTS_WCDMA_DUPLEX_MODE, LTE_FDD_DUPLEX_MODE);        
            break;

        /* L+T */
        case GMSS_WM_LTG:
        case GMSS_WM_LCTG:
            gmss_set_duplex_mode(UMTS_TDSCDMA_DUPLEX_MODE, LTE_FDD_TDD_DUPLEX_MODE);
            break;

        /* Lt+T */
        case GMSS_WM_LTTG:
        case GMSS_WM_LTCTG:
            gmss_set_duplex_mode(UMTS_TDSCDMA_DUPLEX_MODE, LTE_TDD_DUPLEX_MODE);
            break;

        /* Lt+W */
        case GMSS_WM_LTWG:
        case GMSS_WM_LTWCG:
            gmss_set_duplex_mode(UMTS_WCDMA_DUPLEX_MODE, LTE_TDD_DUPLEX_MODE);
            break;

        /* Lf+T */
        case GMSS_WM_LFTG:
        case GMSS_WM_LFCTG:
            gmss_set_duplex_mode(UMTS_TDSCDMA_DUPLEX_MODE, LTE_FDD_DUPLEX_MODE);
            break;

        default:
            DEBUG_ASSERT(0);

            gmss_set_duplex_mode(UMTS_TDSCDMA_DUPLEX_MODE, LTE_FDD_TDD_DUPLEX_MODE);
            break;
    }

    free_ctrl_buffer(buffer);
}

#endif /* NVRAM_NOT_PRESENT */
