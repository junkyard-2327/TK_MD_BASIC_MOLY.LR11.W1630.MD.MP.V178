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
 * umts_nvram_def.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *
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
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef NVRAM_NOT_PRESENT

#include "kal_general_types.h"
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "nvram_enums.h"
#include "nvram_defs.h"
/*
 *   User Headers & Default value
 */
#include "errc_nvram_def.h" 
#include "errc_nvram_editor.h"


#ifdef __LTE_RAT__

static nvram_ef_errc_performance_para_struct const NVRAM_EF_ERRC_PERFORMANCE_PARA_DEFAULT[] =
{
	{

		0x14,       //tband_ind
		0x1E,       //tbarred_cell
		0x1E,       //tbarred_freq
		0x14,       //tcsg_cell
		0x02,       //carrs_interval
		0x20,       //list1_used_carr_max
		0xFE48,     //skip_bw_rsrp_th
		0xFFC4,     //skip_bw_rsrq_th
		0x3C,       //tsib_ng_rej
		0x04,       //nsib_ng_max
		0x3C,       //tnsib_clear
		0x05,       //est_s_rxlev_th
		0x03,       //est_s_qual_th
		NVRAM_EF_ERRC_PERFORMANCE_TRACH,     //trach

		{
			{
	    	//filter_coef_inrterval[0].interva_k0~19
			0x01, 0x02, 0x03, 0x04, 0x06,
        	0x07, 0x09, 0x0A, 0x0c, 0x0D,
        	0x0E, 0x0F, 0x11, 0x12, 0x13,
        	0x14, 0x14, 0x14, 0x14, 0x14
	        },

			{
			//filter_coef_inrterval[1].interva_k0~19
			0x01, 0x02, 0x03, 0x04, 0x05,
        	0x06, 0x07, 0x08, 0x09, 0x0A,
        	0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        	0x10, 0x11, 0x12, 0x13, 0x14
	        },

			{
			//filter_coef_inrterval[2].interva_k0~19
			0x01, 0x02, 0x02, 0x03, 0x04,
        	0x05, 0x06, 0x06, 0x07, 0x07,
        	0x08, 0x08, 0x08, 0x09, 0x09,
        	0x0A, 0x0A, 0x0B, 0x0B, 0x0C
		    },

			{
		 	//filter_coef_inrterval[3].interva_k0~19
			0x01, 0x02, 0x02, 0x03, 0x03,
        	0x04, 0x04, 0x05, 0x05, 0x06,
        	0x06, 0x06, 0x06, 0x07, 0x07,
        	0x07, 0x08, 0x08, 0x09, 0x09
			}
		},

		0x00,   //eutran_neighbour_cellreport_flg
		0x01,   //iir_filter_coef_rsrp
		0x01,   //iir_filter_coef_rsrp
		0x0001, //th0_interval
		0x00B5, //th1_interval
		0x00F1, //th2_interval
		0x0501, //th3_interval
		0x0A01, //th4_interval

		NVRAM_EF_ERRC_PERFORMANCE_MAX_KRAERR,   //max_kraerr
		NVRAM_EF_ERRC_PERFORMANCE_TRAERR,   //traerr
        NVRAM_EF_ERRC_PERFORMANCE_TVALID_RAERR,   //tvalid_raerr

		0x10,  //mib_crc_ng_max
		0x10,  //sib1_crc_ng_max
		0x10,  //si1_crc_ng_max
		0x10,  //si_crc_ng_max
		0x20,  //sib10_crc_ng_max
		0x20,  //sib11_crc_ng_max
		0x20,  //sib12_crc_ng_max
		0x28,  //mib_sib1_protect_tim_val
        0x0A,  //sib2_9_protect_tim_val
        0x05,  //crc_ng_tim_shift
        0x0A,  //standby_mib_sib1_protect_tim_val
        0x0A,  //standby_sib2_9_protect_tim_val
#ifndef __DISABLE_3G_AFR__
        0x10+
#endif        
        0x0F,  //csfb_enhancement_item_status [b1: not used] [b2: reduce lau, enable] [b3: defer si13, enable] [b4: 2g afr, enable] [b5: 3g afr, enable]
        0x04,  //csfb_enhancement_item_status_in_test_mode [b1: not used] [b2: reduce lau, disable] [b3: defer si13, enable] [b4: 2g afr, disable] [b5: 3g afr, disable]
        0x00,  //is_eia0_by_sp1;
        0x00,  //background_search_status_in_test_mode [b1: BG_SEARCH_2G4_FDD, off] [b2: BG_SEARCH_3G4_FDD, off] [b3: BG_SEARCH_2G4_TDD, off] [b4: BG_SEARCH_3G4_TDD, off]

#if defined(TK6291) && defined(__RF_BYPASS__)
        {   //designated_carrier_inf
            0x00,   //freq_num
            {       //freq_list[20]
                {   //freq_list[0]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000  
                },
                {   //freq_list[1]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000  
                },
                {   //freq_list[2]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000  
                },
                {   //freq_list[3]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000  
                },
                {   //freq_list[4]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000  
                },
                {   //freq_list[5]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[6]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[7]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[8]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[9]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[10]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[11]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[12]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[13]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[14]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[15]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[16]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[17]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[18]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[19]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                }
            },

            0x00,   //black_freq_num
            {       //black_freq_list[16]
                {   //freq_list[0]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, 
                    0x00    //bandwidth
                },
                {   //freq_list[1]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, 
                    0x00    //bandwidth
                },
                {   //freq_list[2]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, 
                    0x00    //bandwidth
                },
                {   //freq_list[3]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, 
                    0x00    //bandwidth
                },
                {   //freq_list[4]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[5]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[6]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[7]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[8]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[9]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[10]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[11]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[12]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[13]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[14]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[15]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                }
            },

            0x00,   //priority_band_inf_num
            {       //priority_band_inf[16]
                {       //priority_band_inf[0]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[1]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[2]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[3]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[4]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[5]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[6]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[7]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[8]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[9]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[10]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[11]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[12]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[13]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[14]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[15]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                }
            }
        },
#else        
        {   //designated_carrier_inf
            0x05,   //freq_num
            {       //freq_list[20]
                {   //freq_list[0]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x9952  //39250
                },
                {   //freq_list[1]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x95CE  //38350
                },
                {   //freq_list[2]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x940C  //37900
                },
                {   //freq_list[3]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x94D4  //38100
                },
                {   //freq_list[4]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x9826  //38950
                },
                {   //freq_list[5]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[6]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[7]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[8]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[9]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[10]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[11]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[12]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[13]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[14]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[15]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[16]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[17]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[18]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[19]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                }
            },

            0x04,   //black_freq_num
            {       //black_freq_list[16]
                {   //freq_list[0]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x975E, //38750
                    0x05    //bandwidth
                },
                {   //freq_list[1]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x9A1A, //39450
                    0x05    //bandwidth
                },
                {   //freq_list[2]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x9D94, //40340
                    0x05    //bandwidth
                },
                {   //freq_list[3]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0xA0B4, //41140
                    0x05    //bandwidth
                },
                {   //freq_list[4]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[5]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[6]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[7]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[8]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[9]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[10]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[11]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[12]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[13]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[14]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[15]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                }
            },

            0x00,   //priority_band_inf_num
            {       //priority_band_inf[16]
                {       //priority_band_inf[0]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[1]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[2]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[3]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[4]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[5]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[6]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[7]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[8]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[9]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[10]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[11]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[12]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[13]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[14]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[15]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                }
            }
        },
#endif        
        0x02,  //afr_timer(seconds)
        0x04,  //csfb_enhancement_item_status_2 [b1: 2G_FDD_eCSFB, disable] [b2: 3G_FDD_eCSFB, disable] [b3: 2G_TDD_eCSFB, enable] [b4: 3G_TDD_eCSFB, disable]
        0x00,  //csfb_enhancement_item_status_2_in_test_mode [b1: 2G_FDD_eCSFB, disable] [b2: 3G_FDD_eCSFB, disable] [b3: 2G_TDD_eCSFB, disable] [b4: 3G_TDD_eCSFB, disable]
        0x012C,  //errc_detection_timer(seconds)
        0x0005,  //errc_conn_pg_local_rel_timer
        0xFE14,  //lte_to_c2k_rsrp_threshold, -492(qdBm)
        0x0018,  //c2k_to_lte_rsrp_delta. 24(qdB)
        0x0014,  //hsr_inactive_timer_val(minutes)
        0x02,   //hsr_on_thrs
        0x05,   //hsr_off_thrs
        0x00,   //hsr_monitor_mode
        {
            {
                //hsr_preload_freq_list[0]
                0x01,   //BJ-SH
                38500,  //earfcn
            },
            {
                //hsr_preload_freq_list[1]
                0x01,   //BJ-SH
                38350,  //earfcn
            },
            {
                //hsr_preload_freq_list[2]
                0x01,   //BJ-SH
                38098,  //earfcn
            },
            {
                //hsr_preload_freq_list[3]
                0x01,   //BJ-SH
                38150,  //earfcn
            },
            {
                //hsr_preload_freq_list[4]
                0x01,   //BJ-SH
                38400,  //earfcn
	},
            {
                //hsr_preload_freq_list[5]
                0x01,   //BJ-SH
                38550,  //earfcn
            },
            {
                //hsr_preload_freq_list[6]
                0x01,   //BJ-SH
                38145,  //earfcn
            },
            {
                //hsr_preload_freq_list[7]
                0x01,   //BJ-SH
                38100,  //earfcn
            },
            {
                //hsr_preload_freq_list[8]
                0x01,   //BJ-SH
                40936,  //earfcn
            },
            {
                //hsr_preload_freq_list[9]
                0x01,   //BJ-SH
                38356,  //earfcn
            },
        },
        0x00,   //hsr_using_8475

#ifdef __NVRAM_EVENTB2_THRESHOLD_ADJ__
        0x0000,  // rsrq_threshold default value
        0x0000,  // max_rsrp_threshold default value
        0x0000,  // rsrp_delta default value
#else
        0x0000,  // rsrq_threshold = 0
        0x0000,  // max_rsrp_threshold = 0
        0x0000,  // rsrp_delta = 0
#endif /*__NVRAM_EVENTB2_THRESHOLD_ADJ__*/

#ifdef __QQUALMIN_THRES_CUSTOM__
        0xFFEE,  // default q_qualmin_thres_nvram = -18; 0 to deactivate enhancement
#else
        0x0000,  // q_qualmin_thres_nvram = 0 to deactivate enhancement 
#endif /*__QQUALMIN_THRES_CUSTOM__*/

#ifdef __RESEL_THRES_CUSTOM__
        0xFF88,  // rsrp_serving_low_p_nvram = -120
        0xFFB5,  // rsrp_gsm_x_low_p_nvram = -75
        0xFFAB,  // rsrp_umts_x_low_p_nvram = -85
        0xFFFA,  // rsrp_c2k_x_low_p_nvram = -6
        0xFFF2,  // rsrq_serving_threshold_nvram = -14		  
#else
        0x0000,  // rsrp_serving_low_p_nvram, 0 means off
        0x0000,  // rsrp_gsm_x_low_p_nvram, 0 means off
        0x0000,  // rsrp_umts_x_low_p_nvram, 0 means off
        0x0000,  // rsrp_c2k_x_low_p_nvram, 0 means off
        0x0000,  // rsrq_serving_threshold_nvram, 0 means off
#endif /*__RESEL_THRES_CUSTOM__*/
        {
            {0x03, 0x01, 0x00, 0xff, 0xff, 0xff}, // plmnid0:  310 xxx
            {0x03, 0x01, 0x01, 0xff, 0xff, 0xff}, // plmnid1:  311 xxx
            {0x03, 0x01, 0x02, 0xff, 0xff, 0xff}, // plmnid2:  312 xxx
            {0x03, 0x01, 0x03, 0xff, 0xff, 0xff}, // plmnid3:  313 xxx
            {0x03, 0x01, 0x04, 0xff, 0xff, 0xff}, // plmnid4:  314 xxx
            {0x03, 0x01, 0x05, 0xff, 0xff, 0xff}, // plmnid5:  315 xxx
            {0x03, 0x01, 0x06, 0xff, 0xff, 0xff}, // plmnid6:  316 xxx
            {0x03, 0x03, 0x00, 0xff, 0xff, 0xff}, // plmnid7:  330 xxx
            {0x03, 0x07, 0x06, 0xff, 0xff, 0xff}, // plmnid8:  376 xxx
            {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, // plmnid9:  xxx xxx
            {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, // plmnid10: xxx xxx
            {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}  // plmnid11: xxx xxx
        },
#ifdef __NVRAM_EVENTB2_THRESHOLD_ADJ__
        0x0000,  // rsrq_threshold_vilte default value
        0x0000,  // max_rsrp_threshold_vilte default value
        0x0000,  // rsrp_delta_vilte default value
#else
        0x0000,  // rsrq_threshold_vilte = 0
        0x0000,  // max_rsrp_threshold_vilte = 0
        0x0000,  // rsrp_delta_vilte = 0
#endif /*__NVRAM_EVENTB2_THRESHOLD_ADJ__*/
	},
};

static nvram_ef_errc_stored_cell_struct const NVRAM_EF_ERRC_STORED_CELL_DEFAULT[] =
{
    // cell[32]
    {
        {
            {
                // cell[0]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[1]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[2]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[3]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[4]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[5]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[6]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[7]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },  

            {
                // cell[8]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[9]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[10]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[11]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[12]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[13]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[14]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[15]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },    

            {
                // cell[16]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[17]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[18]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[19]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[20]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[21]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[22]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[23]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },  

            {
                // cell[24]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[25]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[26]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[27]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[28]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[29]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[30]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },

            {
                // cell[31]
                0x0000,         //earfcn
                0x0000,         //pci
                0x00000000,     //cell_id
                0x00,           //is_valid
                0x00,           //is_detected_by_latest_search
                0x00,           //is_detected_by_cell
                0x00,           //is_detected_by_current_search
            },        
        },
#ifdef __BAND_EXTENSION_SUPPORT__
        // cmcc_band_bmp[32]
        {
            0x84,   //cmcc_band_bmp[0]: band3,8
            0x00,   //cmcc_band_bmp[1]
            0x00,   //cmcc_band_bmp[2]
            0x00,   //cmcc_band_bmp[3]
            0x00,   //cmcc_band_bmp[4]
            0x00,   //cmcc_band_bmp[5]
            0x00,   //cmcc_band_bmp[6]
            0x00,   //cmcc_band_bmp[7]
            0x00,   //cmcc_band_bmp[8]
            0x00,   //cmcc_band_bmp[9]
            0x00,   //cmcc_band_bmp[10]
            0x00,   //cmcc_band_bmp[11]
            0x00,   //cmcc_band_bmp[12]
            0x00,   //cmcc_band_bmp[13]
            0x00,   //cmcc_band_bmp[14]
            0x00,   //cmcc_band_bmp[15]
            0x00,   //cmcc_band_bmp[16]
            0x00,   //cmcc_band_bmp[17]
            0x00,   //cmcc_band_bmp[18]
            0x00,   //cmcc_band_bmp[19]
            0x00,   //cmcc_band_bmp[20]
            0x00,   //cmcc_band_bmp[21]
            0x00,   //cmcc_band_bmp[22]
            0x00,   //cmcc_band_bmp[23]
            0x00,   //cmcc_band_bmp[24]
            0x00,   //cmcc_band_bmp[25]
            0x00,   //cmcc_band_bmp[26]
            0x00,   //cmcc_band_bmp[27]
            0x00,   //cmcc_band_bmp[28]
            0x00,   //cmcc_band_bmp[29]
            0x00,   //cmcc_band_bmp[30]
            0x00,   //cmcc_band_bmp[31]  
        },
#else
        // cmcc_band_bmp[8]
        {
            0x84,   //cmcc_band_bmp[0]: band3,8
            0x00,   //cmcc_band_bmp[1]
            0x00,   //cmcc_band_bmp[2]
            0x00,   //cmcc_band_bmp[3]
            0x00,   //cmcc_band_bmp[4]
            0x00,   //cmcc_band_bmp[5]
            0x00,   //cmcc_band_bmp[6]
            0x00,   //cmcc_band_bmp[7]
        },
#endif
    },
};

static nvram_ef_errc_afr_setting_struct const NVRAM_EF_ERRC_AFR_SETTING_DEFAULT[] =
{
    {
        {
            {
                //hplmn_afr_mapping[0]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[1]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[2]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[3]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[4]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[5]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[6]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[7]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            }
        }
    }
};


static nvram_ef_lte_cap_struct const NVRAM_EF_LTE_CAP_DEFAULT[] =
{
    0xf0, //eea_support
#ifdef __VOLTE_SUPPORT__    
    0xf0, //eia_support
#else
    0x70, //eia_support
#endif

#ifdef __VOLTE_SUPPORT__
    0x0B,  //bit 1: srvcc_to_geran_utran_support  //bit2: nf_support //bit3+4: LTE power class =>2 denotes class 3
#else
    0x08,  //bit 1: srvcc_to_geran_utran_support  //bit2: nf_support //bit3+4: LTE power class =>2 denotes class 3
#endif    

	0x00,  //op_femtocell_system_selection

#ifdef __BAND_EXTENSION_SUPPORT__
    {//nvram_errc_disable_bw
        //band_list[256]
        0x00,   //band[000]
        0x00,   //band[001]
        0x00,   //band[002]
        0x00,   //band[003]
        0x00,   //band[004]
        0x00,   //band[005]
        0x00,   //band[006]
        0x00,   //band[007]
        0x00,   //band[008]
        0x00,   //band[009]
        0x00,   //band[010]
        0x00,   //band[011]
        0x00,   //band[012]
        0x00,   //band[013]
        0x00,   //band[014]
        0x00,   //band[015]
        0x00,   //band[016]
        0x00,   //band[017]
        0x00,   //band[018]
        0x00,   //band[019]
        0x00,   //band[020]
        0x00,   //band[021]
        0x00,   //band[022]
        0x00,   //band[023]
        0x00,   //band[024]
        0x00,   //band[025]
        0x00,   //band[026]
        0x00,   //band[027]
        0x00,   //band[028]
        0x00,   //band[029]
        0x00,   //band[030]
        0x00,   //band[031]
        0x00,   //band[032]
        0x00,   //band[033]
        0x00,   //band[034]
        0x00,   //band[035]
        0x00,   //band[036]
        0x00,   //band[037]
        0x00,   //band[038]
        0x00,   //band[039]
        0x00,   //band[040]
        0x00,   //band[041]
        0x00,   //band[042]
        0x00,   //band[043]
        0x00,   //band[044]
        0x00,   //band[045]
        0x00,   //band[046]
        0x00,   //band[047]
        0x00,   //band[048]
        0x00,   //band[049]
        0x00,   //band[050]
        0x00,   //band[051]
        0x00,   //band[052]
        0x00,   //band[053]
        0x00,   //band[054]
        0x00,   //band[055]
        0x00,   //band[056]
        0x00,   //band[057]
        0x00,   //band[058]
        0x00,   //band[059]
        0x00,   //band[060]
        0x00,   //band[061]
        0x00,   //band[062]
        0x00,   //band[063]
        0x00,   //band[064]
        0x00,   //band[065]
        0x00,   //band[066]
        0x00,   //band[067]
        0x00,   //band[068]
        0x00,   //band[069]
        0x00,   //band[070]
        0x00,   //band[071]
        0x00,   //band[072]
        0x00,   //band[073]
        0x00,   //band[074]
        0x00,   //band[075]
        0x00,   //band[076]
        0x00,   //band[077]
        0x00,   //band[078]
        0x00,   //band[079]
        0x00,   //band[080]
        0x00,   //band[081]
        0x00,   //band[082]
        0x00,   //band[083]
        0x00,   //band[084]
        0x00,   //band[085]
        0x00,   //band[086]
        0x00,   //band[087]
        0x00,   //band[088]
        0x00,   //band[089]
        0x00,   //band[090]
        0x00,   //band[091]
        0x00,   //band[092]
        0x00,   //band[093]
        0x00,   //band[094]
        0x00,   //band[095]
        0x00,   //band[096]
        0x00,   //band[097]
        0x00,   //band[098]
        0x00,   //band[099]
        0x00,   //band[100]
        0x00,   //band[101]
        0x00,   //band[102]
        0x00,   //band[103]
        0x00,   //band[104]
        0x00,   //band[105]
        0x00,   //band[106]
        0x00,   //band[107]
        0x00,   //band[108]
        0x00,   //band[109]
        0x00,   //band[110]
        0x00,   //band[111]
        0x00,   //band[112]
        0x00,   //band[113]
        0x00,   //band[114]
        0x00,   //band[115]
        0x00,   //band[116]
        0x00,   //band[117]
        0x00,   //band[118]
        0x00,   //band[119]
        0x00,   //band[120]
        0x00,   //band[121]
        0x00,   //band[122]
        0x00,   //band[123]
        0x00,   //band[124]
        0x00,   //band[125]
        0x00,   //band[126]
        0x00,   //band[127]
        0x00,   //band[128]
        0x00,   //band[129]
        0x00,   //band[130]
        0x00,   //band[131]
        0x00,   //band[132]
        0x00,   //band[133]
        0x00,   //band[134]
        0x00,   //band[135]
        0x00,   //band[136]
        0x00,   //band[137]
        0x00,   //band[138]
        0x00,   //band[139]
        0x00,   //band[140]
        0x00,   //band[141]
        0x00,   //band[142]
        0x00,   //band[143]
        0x00,   //band[144]
        0x00,   //band[145]
        0x00,   //band[146]
        0x00,   //band[147]
        0x00,   //band[148]
        0x00,   //band[149]
        0x00,   //band[150]
        0x00,   //band[151]
        0x00,   //band[152]
        0x00,   //band[153]
        0x00,   //band[154]
        0x00,   //band[155]
        0x00,   //band[156]
        0x00,   //band[157]
        0x00,   //band[158]
        0x00,   //band[159]
        0x00,   //band[160]
        0x00,   //band[161]
        0x00,   //band[162]
        0x00,   //band[163]
        0x00,   //band[164]
        0x00,   //band[165]
        0x00,   //band[166]
        0x00,   //band[167]
        0x00,   //band[168]
        0x00,   //band[169]
        0x00,   //band[170]
        0x00,   //band[171]
        0x00,   //band[172]
        0x00,   //band[173]
        0x00,   //band[174]
        0x00,   //band[175]
        0x00,   //band[176]
        0x00,   //band[177]
        0x00,   //band[178]
        0x00,   //band[179]
        0x00,   //band[180]
        0x00,   //band[181]
        0x00,   //band[182]
        0x00,   //band[183]
        0x00,   //band[184]
        0x00,   //band[185]
        0x00,   //band[186]
        0x00,   //band[187]
        0x00,   //band[188]
        0x00,   //band[189]
        0x00,   //band[190]
        0x00,   //band[191]
        0x00,   //band[192]
        0x00,   //band[193]
        0x00,   //band[194]
        0x00,   //band[195]
        0x00,   //band[196]
        0x00,   //band[197]
        0x00,   //band[198]
        0x00,   //band[199]
        0x00,   //band[200]
        0x00,   //band[201]
        0x00,   //band[202]
        0x00,   //band[203]
        0x00,   //band[204]
        0x00,   //band[205]
        0x00,   //band[206]
        0x00,   //band[207]
        0x00,   //band[208]
        0x00,   //band[209]
        0x00,   //band[210]
        0x00,   //band[211]
        0x00,   //band[212]
        0x00,   //band[213]
        0x00,   //band[214]
        0x00,   //band[215]
        0x00,   //band[216]
        0x00,   //band[217]
        0x00,   //band[218]
        0x00,   //band[219]
        0x00,   //band[220]
        0x00,   //band[221]
        0x00,   //band[222]
        0x00,   //band[223]
        0x00,   //band[224]
        0x00,   //band[225]
        0x00,   //band[226]
        0x00,   //band[227]
        0x00,   //band[228]
        0x00,   //band[229]
        0x00,   //band[230]
        0x00,   //band[231]
        0x00,   //band[232]
        0x00,   //band[233]
        0x00,   //band[234]
        0x00,   //band[235]
        0x00,   //band[236]
        0x00,   //band[237]
        0x00,   //band[238]
        0x00,   //band[239]
        0x00,   //band[240]
        0x00,   //band[241]
        0x00,   //band[242]
        0x00,   //band[243]
        0x00,   //band[244]
        0x00,   //band[245]
        0x00,   //band[246]
        0x00,   //band[247]
        0x00,   //band[248]
        0x00,   //band[249]
        0x00,   //band[250]
        0x00,   //band[251]
        0x00,   //band[252]
        0x00,   //band[253]
        0x00,   //band[254]
        0x00    //band[255]
    },
#else
  {//nvram_errc_disable_bw
        //band_list[64]
        0x00,   //band[01]
        0x00,   //band[02]
        0x00,   //band[03]
        0x00,   //band[04]
        0x00,   //band[05]
        0x00,   //band[06]
        0x00,   //band[07]
        0x00,   //band[08]
        0x00,   //band[09]
        0x00,   //band[10]
        0x00,   //band[11]
        0x00,   //band[12]
        0x00,   //band[13]
        0x00,   //band[14]
        0x00,   //band[15]
        0x00,   //band[16]
        0x00,   //band[17]
        0x00,   //band[18]
        0x00,   //band[19]
        0x00,   //band[20]
        0x00,   //band[21]
        0x00,   //band[22]
        0x00,   //band[23]
        0x00,   //band[24]
        0x00,   //band[25]
        0x00,   //band[26]
        0x00,   //band[27]
        0x00,   //band[28]
        0x00,   //band[29]
        0x00,   //band[30]
        0x00,   //band[31]
        0x00,   //band[32]
        0x00,   //band[33]
        0x00,   //band[34]
        0x00,   //band[35]
        0x00,   //band[36]
        0x00,   //band[37]
        0x00,   //band[38]
        0x00,   //band[39]
        0x00,   //band[40]
        0x00,   //band[41]
        0x00,   //band[42]
        0x00,   //band[43]
        0x00,   //band[44]
        0x00,   //band[45]
        0x00,   //band[46]
        0x00,   //band[47]
        0x00,   //band[48]
        0x00,   //band[49]
        0x00,   //band[50]
        0x00,   //band[51]
        0x00,   //band[52]
        0x00,   //band[53]
        0x00,   //band[54]
        0x00,   //band[55]
        0x00,   //band[56]
        0x00,   //band[57]
        0x00,   //band[58]
        0x00,   //band[59]
        0x00,   //band[60]
        0x00,   //band[61]
        0x00,   //band[62]
        0x00,   //band[63]
        0x00    //band[64]  
    },
#endif

    {//nvram_errc_partial_band_inf_struct
      0x00,
       { //nvram_errc_partial_band_list_struct
	    // partial band list [0] - band, dl_lower_earfcn, dl_upper_earfcn, ul_lower_earfcn, ul_upper_earfcn
        {0x0000,0x00000000,0x00000000,0x00000000,0x00000000},
        // partial band list [1] 
        {0x0000,0x00000000,0x00000000,0x00000000,0x00000000},
        // partial band list [2] 
        {0x0000,0x00000000,0x00000000,0x00000000,0x00000000},
        // partial band list [3] 
        {0x0000,0x00000000,0x00000000,0x00000000,0x00000000},
        // partial band list [4] 
        {0x0000,0x00000000,0x00000000,0x00000000,0x00000000},
        // partial band list [5] 
        {0x0000,0x00000000,0x00000000,0x00000000,0x00000000},
        // partial band list [6] 
        {0x0000,0x00000000,0x00000000,0x00000000,0x00000000},
        // partial band list [7] 
        {0x0000,0x00000000,0x00000000,0x00000000,0x00000000},
        // partial band list [8] 
        {0x0000,0x00000000,0x00000000,0x00000000,0x00000000},
        // partial band list [9] 
        {0x0000,0x00000000,0x00000000,0x00000000,0x00000000}
      }
    },
};


static nvram_ef_ue_eutra_cap_struct const NVRAM_EF_UE_EUTRA_CAP_CSFB_DEFAULT[] =
{
{
    //MTK related
	0x03,       //ue_eutra_cap_ver

    //spec related
#if defined(__LTE_REPORT_CAP_AS_REL_10__)    //AS_REL_10
	0x02,       //access_stratum_release, Rel-10
#elif defined(__LTE_REPORT_CAP_AS_REL_11__)  //AS_REL_11
	0x03,       //access_stratum_release, Rel-11
#else                                        //DEFAULT
	0x02,       //access_stratum_release, Rel-10
#endif
	0x06,       //ue_category
	
	{//pdcp_param
		{
    	//rohc_profiles[0~8]
#ifndef __DISABLE_PROFILE_ROHCV1_RTP__	        //0x0001 ROHC RTP  	
		    NVRAM_ERRC_CAP_ROHCV1_PROFILE_RTP, 
#else
		    0x00,
#endif

#ifndef __DISABLE_PROFILE_ROHCV1_UDP__	        //0x0002 ROHC UDP
		    NVRAM_ERRC_CAP_ROHCV1_PROFILE_UDP, 
#else
		    0x00,
#endif

		    NVRAM_ERRC_CAP_ROHCV1_PROFILE_ESP,	//0x0003 ROHC ESP 
		
#ifndef __DISABLE_PROFILE_ROHCV1_IP__	        //0x0004 ROHC IP
		    NVRAM_ERRC_CAP_ROHCV1_PROFILE_IP, 
#else
		    0x00,
#endif

#ifndef __DISABLE_PROFILE_ROHCV1_TCP__	        //0x0006 ROHC TCP
		    NVRAM_ERRC_CAP_ROHCV1_PROFILE_TCP, 
#else
		    0x00,
#endif

#ifndef __DISABLE_PROFILE_ROHCV2_RTP__	        //0x0101 ROHCv2 RTP 	
            NVRAM_ERRC_CAP_ROHCV2_PROFILE_RTP, 
#else
            0x00,
#endif

#ifndef __DISABLE_PROFILE_ROHCV2_UDP__	        //0x0102 ROHCv2 UDP
    	    NVRAM_ERRC_CAP_ROHCV2_PROFILE_UDP, 
#else
            0x00,
#endif

    	    NVRAM_ERRC_CAP_ROHCV2_PROFILE_ESP,  //0x0103 ROHCv2 ESP
    	
#ifndef __DISABLE_PROFILE_ROHCV2_IP__	        //0x0104 ROHCv2 IP    	
    	    NVRAM_ERRC_CAP_ROHCV2_PROFILE_IP
#else
            0x00
#endif    	
        },

#ifdef ROHC_MAX_NUMBER_CONTEXT_SESSION_ENUM
#if (ROHC_MAX_NUMBER_CONTEXT_SESSION_ENUM >= 0 && ROHC_MAX_NUMBER_CONTEXT_SESSION_ENUM <14)
		ROHC_MAX_NUMBER_CONTEXT_SESSION_ENUM
#else
#error "ROHC_MAX_NUMBER_CONTEXT_SESSION_ENUM should lie in [0, 13]"
#endif
#else
		0x04    //max_num_rohc_sessions, cs16
#endif		
	},

    {//phylayer_param
		0x00,   //ue_tx_ante_sel_fdd
		0x00,   //ue_tx_ante_sel_tdd
		0x01    //ue_specific_ref_sigs
	},    

#ifndef __DISABLE_SRVCC_FGI_ORANGE__
    0xA240001E |
#ifdef __VOLTE_SUPPORT__
    0x00800020 |
#endif
#endif
    0x5D0FFEC0, //feature_group_ind_fdd

#ifndef __DISABLE_SRVCC_FGI_ORANGE__
    0xA240001E |
#ifdef __VOLTE_SUPPORT__
    0x00800020 |
#endif
#endif
    0x5D0FFEC0, //feature_group_ind_tdd

    {//phylayer_param_v920
		0x01,   //enhancedDualLayerFDD_r9
		0x01    //enhancedDualLayerTDD_r9
	}, 

    {//interrat_param_geram_v920
		0x00,   //dtm_r9
		0x01    //e_RedirectionGERAN_r9
	},

    {//interrat_param_utra_v920
		0x01,   //e_RedirectionUTRA_r9_fdd
		0x01    //e_RedirectionUTRA_r9_tdd
	},
	
	0x00,   //deviceType_r9

    {//csg_prox_ind_param_r9
		0x01,   //intraFreqProximityIndication_r9
		0x01,   //interFreqProximityIndication_r9
		0x01    //utran_ProximityIndication_r9
	},

    {//nei_cell_si_acq_r9
		0x01,   //intraFreqSI_AcquisitionForHO_r9_fdd
		0x01,   //intraFreqSI_AcquisitionForHO_r9_tdd
		0x01,   //interFreqSI_AcquisitionForHO_r9_fdd
		0x01,   //interFreqSI_AcquisitionForHO_r9_tdd
		0x01,   //utran_SI_AcquisitionForHO_r9_fdd
		0x01    //utran_SI_AcquisitionForHO_r9_tdd
	},

    {//son_param_r9
		0x01    //rach_Report_r9
	},
        
	0xDE800000,   //feature_group_ind_add_r9_fdd
	0xDE800000,   //feature_group_ind_add_r9_tdd

    {//fdd_add_ue_eutra_cap_r9
		{//phylayer_param_r9
    		0x00,   //ue_tx_ante_sel
    		0x00    //ue_specific_ref_sigs
    	},

        0x00000000, //feature_group_ind_r9
    	0x00000000, //feature_group_ind_add_r9

        {//interrat_param_utra_r9
    		0x00    //e_RedirectionUTRA_r9
    	},

        {//nei_cell_si_acq_r9
    		0x00,   //intraFreqSI_AcquisitionForHO_r9
    		0x00,   //interFreqSI_AcquisitionForHO_r9
    		0x00    //utran_SI_AcquisitionForHO_r9
    	}
	},

    {//tdd_add_ue_eutra_cap_r9
		{//phylayer_param_r9
    		0x00,   //ue_tx_ante_sel
    		0x00    //ue_specific_ref_sigs
    	},

        0x00000000, //feature_group_ind_r9
    	0x00000000, //feature_group_ind_add_r9

        {//interrat_param_utra_r9
    		0x00    //e_RedirectionUTRA_r9
    	},

        {//nei_cell_si_acq_r9
    		0x00,   //intraFreqSI_AcquisitionForHO_r9
    		0x00,   //interFreqSI_AcquisitionForHO_r9
    		0x00    //utran_SI_AcquisitionForHO_r9
    	}
	},
        
    {//interrat_param_utra_v9c0
		0x00,   //voiceOverPS_HS_UTRA_FDD_r9
		0x00,   //voiceOverPS_HS_UTRA_TDD128_r9
		0x00,   //srvcc_FromUTRA_FDD_ToUTRA_FDD_r9
		0x00,   //srvcc_FromUTRA_FDD_ToGERAN_r9
		0x00,   //srvcc_FromUTRA_TDD128_ToUTRA_TDD128_r9
		0x00    //srvcc_FromUTRA_TDD128_ToGERAN_r9
	},

    {//phylayer_param_v9d0
		0x01,   //tm5_FDD_r9
		0x01    //tm5_TDD_r9
	},   

    {//irat_param_utra_tdd_v1020
		0x01,   //e_RedirectionUTRA_TDD_r10_fdd
		0x01    //e_RedirectionUTRA_TDD_r10_tdd
	},

    {//phylayer_param_v1130
		0x01,    //tdd_SpecialSubframe_r11

//__LTE_R11__
        0x01, //crs_interf_handl_r11
        0x00, //ePDCCH_r11
        0x01, //multi_ACK_CSI_reporting_r11
        0x01, //ss_CCH_interf_Handl_r11
        0x00, //tx_div_PUCCH1b_ch_select_r11
        0x00  //ul_CoMP_r11
	},

    {//irat_param_utra_v9h0
        0x01  //mfbi_utra_r9
    },

    {//otdoa_pos_cap_r10
#ifdef __LTE_OTDOA_SUPPORT__
        0x01, //otdoa_ue_assisted_r10
        0x01  //inter_freq_rstd_meas_r10
#else
        0x00, //not support otdoa_ue_assisted_r10
        0x00  //not support inter_freq_rstd_meas_r10
#endif
    },

    {//phylayer_param_v1020
        0x00, //two_antenna_ports_for_puscch_r10
        0x01, //tm9_with_8tx_fdd_r10
        0x01, //pmi_disabling_r10
        0x01, //cross_carrier_scheduling_r10
#ifdef __DISABLE_SIMULTANEOUS_PUCCH_PUSCH__
        0x00, //simultaneous_pucch_pusch_r10
#else
        0x01, //simultaneous_pucch_pusch_r10
#endif
#ifdef __DISABLE_MULTI_CLUSTER_PUSCH_WITHIN_CC__
        0x00, //multi_cluster_pusch_within_cc_r10
#else
        0x01, //multi_cluster_pusch_within_cc_r10
#endif
        0x01  //non_contiguous_ul_ra_with_cc_info_r10 
    },

    0xD5F60000, //feature_group_ind_r10_fdd
    0xD5F60000, //feature_group_ind_r10_tdd

    {//nw_perf_meas_param_r10
        0x01, //logged_measurements_idle_r10
        0x01  //standalone_GNSS_location_r10
    },


    {//fdd_add_ue_eutra_cap_r10
        0x01,       //pmi_disabling_r10
        0x00000000  //fgi_r10
    },

    {//tdd_add_ue_eutra_cap_r10
        0x01,       //pmi_disabling_r10
        0x00000000  //fgi_r10
    },

    {//pdcp_param_v1130
        0x01, //pdcp_SN_extension_r11
        0x00  //support_rohc_context_continue_r11
    },

    {//meas_param_v1130
        0x01  //rsrq_meas_wideband_r11
    },

    {//other_param_r11
        0x00, //in_device_coex_ind_r11
        0x01, //power_pref_ind_r11
        0x01  //ue_rx_tx_time_diff_measurements_r11
    },

    {//fdd_add_ue_eutra_cap_r11
        0x00, //ePDCCH_r11
        0x01, //multi_ACK_CSI_reporting_r11
        0x01, //ss_CCH_interf_Handl_r11
        0x00, //tx_div_PUCCH1b_ch_select_r11
        0x01, //rsrq_meas_wideband_r11
        0x00  //in_device_coex_ind_r11
    },

    {//tdd_add_ue_eutra_cap_r11
        0x00, //ePDCCH_r11
        0x01, //multi_ACK_CSI_reporting_r11
        0x01, //ss_CCH_interf_Handl_r11
        0x00, //tx_div_PUCCH1b_ch_select_r11
        0x01, //rsrq_meas_wideband_r11
        0x00  //in_device_coex_ind_r11
    },

    {//phylayer_param_v1170
        0x01, //bit1
        0x01  //bit2
    },

#ifdef __BAND_EXTENSION_SUPPORT__
    {//rf_param_v1130
        0x00, //simultaneous_Rx_Tx_r11
        0x00, //supported_CSI_Proc_r11_max_num
        0x00  //multiple_timing_advance_r11
    },
#else
    {//rf_param_v1130
        0x00, //multiple_Timing_Advance_r11
        0x00, //simultaneous_Rx_Tx_r11
        0x00  //supported_CSI_Proc_r11_max_num
    },
#endif

    {//irat_param_c2k_hrpd
        0x01, //tx_Config_HRPD
        0x01  //rx_Config_HRPD
    },

    {//irat_param_c2k_1xrtt
        0x01, //tx_Config_1XRTT
        0x02  //rx_Config_1XRTT
    },

    {//irat_param_c2k_1xrtt_v920
        0x00, //e_CSFB_1XRTT_r9
        0x00  //e_CSFB_ConcPS_Mob1XRTT_r9
    },

    {//irat_param_c2k_1xrtt_v1020
        0x00 //e_CSFB_dual_1XRTT_r10
    },

    {//irat_param_c2k_v1130
        0x00 //cdma2000_NW_Sharing_11
    },

    {//mbms_param_r11
        0x01, //mbms_scell_r11
        0x01  //mbms_non_serving_cell_r11
    },

    {//fdd_add_ue_eutra_cap_v1180
        0x01, //mbms_scell_r11
        0x01  //mbms_non_serving_cell_r11
    },

    {//tdd_add_ue_eutra_cap_v1180
        0x01, //mbms_scell_r11
        0x01  //mbms_non_serving_cell_r11
    },
    
    0x01, //freq_band_retrieval_r11
    
    0x01, //freq_band_priority_adjustment-r12

    {//nvram_errc_capa_lwa_param_r13_struct
        0x00,   //lwa_r13
        0x01,   //lwa_split_bearer_r13
        0x00    //lwa_buffer_size_r13
    }

// end __LTE_R11__

}
};


static nvram_ef_ue_eutra_cap_struct const NVRAM_EF_UE_EUTRA_CAP_MMDC_DEFAULT[] =
{
{
	//MTK related
	0x03,       //ue_eutra_cap_ver

    //spec related
#if defined(__LTE_REPORT_CAP_AS_REL_10__)    //AS_REL_10
	0x02,       //access_stratum_release, Rel-10
#elif defined(__LTE_REPORT_CAP_AS_REL_11__)  //AS_REL_11
	0x03,       //access_stratum_release, Rel-11
#else                                        //DEFAULT
	0x02,       //access_stratum_release, Rel-10
#endif
	0x06,       //ue_category
	
	{//pdcp_param
		{
    	//rohc_profiles[0~8]
#ifndef __DISABLE_PROFILE_ROHCV1_RTP__	        //0x0001 ROHC RTP  	
		    NVRAM_ERRC_CAP_ROHCV1_PROFILE_RTP, 
#else
		    0x00,
#endif

#ifndef __DISABLE_PROFILE_ROHCV1_UDP__	        //0x0002 ROHC UDP
		    NVRAM_ERRC_CAP_ROHCV1_PROFILE_UDP, 
#else
		    0x00,
#endif

		    NVRAM_ERRC_CAP_ROHCV1_PROFILE_ESP,	//0x0003 ROHC ESP 
		
#ifndef __DISABLE_PROFILE_ROHCV1_IP__	        //0x0004 ROHC IP
		    NVRAM_ERRC_CAP_ROHCV1_PROFILE_IP, 
#else
		    0x00,
#endif

#ifndef __DISABLE_PROFILE_ROHCV1_TCP__	        //0x0006 ROHC TCP
		    NVRAM_ERRC_CAP_ROHCV1_PROFILE_TCP, 
#else
		    0x00,
#endif

#ifndef __DISABLE_PROFILE_ROHCV2_RTP__	        //0x0101 ROHCv2 RTP 	
            NVRAM_ERRC_CAP_ROHCV2_PROFILE_RTP, 
#else
            0x00,
#endif

#ifndef __DISABLE_PROFILE_ROHCV2_UDP__	        //0x0102 ROHCv2 UDP
    	    NVRAM_ERRC_CAP_ROHCV2_PROFILE_UDP, 
#else
            0x00,
#endif

    	    NVRAM_ERRC_CAP_ROHCV2_PROFILE_ESP,  //0x0103 ROHCv2 ESP
    	
#ifndef __DISABLE_PROFILE_ROHCV2_IP__	        //0x0104 ROHCv2 IP    	
    	    NVRAM_ERRC_CAP_ROHCV2_PROFILE_IP
#else
            0x00
#endif    	
        },

#ifdef ROHC_MAX_NUMBER_CONTEXT_SESSION_ENUM
#if (ROHC_MAX_NUMBER_CONTEXT_SESSION_ENUM >= 0 && ROHC_MAX_NUMBER_CONTEXT_SESSION_ENUM <14)
		ROHC_MAX_NUMBER_CONTEXT_SESSION_ENUM
#else
#error "ROHC_MAX_NUMBER_CONTEXT_SESSION_ENUM should lie in [0, 13]"
#endif
#else
		0x04    //max_num_rohc_sessions, cs16
#endif		
	},

    {//phylayer_param
		0x01,   //ue_tx_ante_sel_fdd
		0x01,   //ue_tx_ante_sel_tdd
		0x01    //ue_specific_ref_sigs
	},    

#ifndef __DISABLE_SRVCC_FGI_ORANGE__
    0xA240001E |
#ifdef __VOLTE_SUPPORT__
    0x00800020 |
#endif
#endif
    0x5D0FFEC0, //feature_group_ind_fdd
        
#ifndef __DISABLE_SRVCC_FGI_ORANGE__
    0xA240001E |
#ifdef __VOLTE_SUPPORT__
    0x00800020 |
#endif
#endif
    0x5D0FFEC0, //feature_group_ind_tdd


    {//phylayer_param_v920
		0x01,   //enhancedDualLayerFDD_r9
		0x01    //enhancedDualLayerTDD_r9
	}, 

    {//interrat_param_geram_v920
		0x00,   //dtm_r9
		0x01    //e_RedirectionGERAN_r9
	},

    {//interrat_param_utra_v920
		0x01,   //e_RedirectionUTRA_r9_fdd
		0x01    //e_RedirectionUTRA_r9_tdd
	},
	
	0x00,   //deviceType_r9

    {//csg_prox_ind_param_r9
		0x01,   //intraFreqProximityIndication_r9
		0x01,   //interFreqProximityIndication_r9
		0x01    //utran_ProximityIndication_r9
	},

    {//nei_cell_si_acq_r9
		0x01,   //intraFreqSI_AcquisitionForHO_r9_fdd
		0x01,   //intraFreqSI_AcquisitionForHO_r9_tdd
		0x01,   //interFreqSI_AcquisitionForHO_r9_fdd
		0x01,   //interFreqSI_AcquisitionForHO_r9_tdd
		0x01,   //utran_SI_AcquisitionForHO_r9_fdd
		0x01    //utran_SI_AcquisitionForHO_r9_tdd
	},

    {//son_param_r9
		0x01    //rach_Report_r9
	},
        
	0xDE800000,   //feature_group_ind_add_r9_fdd
	0xDE800000,   //feature_group_ind_add_r9_tdd

    {//fdd_add_ue_eutra_cap_r9
		{//phylayer_param_r9
    		0x00,   //ue_tx_ante_sel
    		0x00    //ue_specific_ref_sigs
    	},

        0x00000000, //feature_group_ind_r9
    	0x00000000, //feature_group_ind_add_r9

        {//interrat_param_utra_r9
    		0x00    //e_RedirectionUTRA_r9
    	},

        {//nei_cell_si_acq_r9
    		0x00,   //intraFreqSI_AcquisitionForHO_r9
    		0x00,   //interFreqSI_AcquisitionForHO_r9
    		0x00    //utran_SI_AcquisitionForHO_r9
    	}
	},

    {//tdd_add_ue_eutra_cap_r9
		{//phylayer_param_r9
    		0x00,   //ue_tx_ante_sel
    		0x00    //ue_specific_ref_sigs
    	},

        0x00000000, //feature_group_ind_r9
    	0x00000000, //feature_group_ind_add_r9

        {//interrat_param_utra_r9
    		0x00    //e_RedirectionUTRA_r9
    	},

        {//nei_cell_si_acq_r9
    		0x00,   //intraFreqSI_AcquisitionForHO_r9
    		0x00,   //interFreqSI_AcquisitionForHO_r9
    		0x00    //utran_SI_AcquisitionForHO_r9
    	}
	},
        
    {//interrat_param_utra_v9c0
		0x00,   //voiceOverPS_HS_UTRA_FDD_r9
		0x00,   //voiceOverPS_HS_UTRA_TDD128_r9
		0x00,   //srvcc_FromUTRA_FDD_ToUTRA_FDD_r9
		0x00,   //srvcc_FromUTRA_FDD_ToGERAN_r9
		0x00,   //srvcc_FromUTRA_TDD128_ToUTRA_TDD128_r9
		0x00    //srvcc_FromUTRA_TDD128_ToGERAN_r9
	},

    {//phylayer_param_v9d0
		0x01,   //tm5_FDD_r9
		0x01    //tm5_TDD_r9
	},   

    {//irat_param_utra_tdd_v1020
		0x01,   //e_RedirectionUTRA_TDD_r10_fdd
		0x01    //e_RedirectionUTRA_TDD_r10_tdd
	},

    {//phylayer_param_v1130
		0x01,    //tdd_SpecialSubframe_r11

//__LTE_R11__
        0x01, //crs_interf_handl_r11
        0x00, //ePDCCH_r11
        0x01, //multi_ACK_CSI_reporting_r11
        0x01, //ss_CCH_interf_Handl_r11
        0x00, //tx_div_PUCCH1b_ch_select_r11
        0x00  //ul_CoMP_r11
	},

    {//irat_param_utra_v9h0
        0x01  //mfbi_utra_r9
    },

    {//otdoa_pos_cap_r10
#ifdef __LTE_OTDOA_SUPPORT__
        0x01, //otdoa_ue_assisted_r10
        0x01  //inter_freq_rstd_meas_r10
#else
        0x00, //not support otdoa_ue_assisted_r10
        0x00  //not support inter_freq_rstd_meas_r10
#endif
    },

    {//phylayer_param_v1020
        0x00, //two_antenna_ports_for_puscch_r10
        0x01, //tm9_with_8tx_fdd_r10
        0x01, //pmi_disabling_r10
        0x01, //cross_carrier_scheduling_r10
#ifdef __DISABLE_SIMULTANEOUS_PUCCH_PUSCH__
        0x00, //simultaneous_pucch_pusch_r10
#else
        0x01, //simultaneous_pucch_pusch_r10
#endif
#ifdef __DISABLE_MULTI_CLUSTER_PUSCH_WITHIN_CC__
        0x00, //multi_cluster_pusch_within_cc_r10
#else
        0x01, //multi_cluster_pusch_within_cc_r10
#endif
        0x01  //non_contiguous_ul_ra_with_cc_info_r10
    },

    0xD5F60000, //feature_group_ind_r10_fdd
    0xD5F60000, //feature_group_ind_r10_tdd

    {//nw_perf_meas_param_r10
        0x01, //logged_measurements_idle_r10
        0x01  //standalone_GNSS_location_r10
    },


    {//fdd_add_ue_eutra_cap_r10
        0x01,       //pmi_disabling_r10
        0x00000000  //fgi_r10
    },

    {//tdd_add_ue_eutra_cap_r10
        0x01,       //pmi_disabling_r10
        0x00000000  //fgi_r10
    },

    {//pdcp_param_v1130
        0x01, //pdcp_SN_extension_r11
        0x00  //support_rohc_context_continue_r11
    },

    {//meas_param_v1130
        0x01  //rsrq_meas_wideband_r11
    },

    {//other_param_r11
        0x00, //in_device_coex_ind_r11
        0x01, //power_pref_ind_r11
        0x01  //ue_rx_tx_time_diff_measurements_r11
    },

    {//fdd_add_ue_eutra_cap_r11
        0x00, //ePDCCH_r11
        0x01, //multi_ACK_CSI_reporting_r11
        0x01, //ss_CCH_interf_Handl_r11
        0x00, //tx_div_PUCCH1b_ch_select_r11
        0x01, //rsrq_meas_wideband_r11
        0x00  //in_device_coex_ind_r11
    },

    {//tdd_add_ue_eutra_cap_r11
        0x00, //ePDCCH_r11
        0x01, //multi_ACK_CSI_reporting_r11
        0x01, //ss_CCH_interf_Handl_r11
        0x00, //tx_div_PUCCH1b_ch_select_r11
        0x01, //rsrq_meas_wideband_r11
        0x00  //in_device_coex_ind_r11
    },

    {//phylayer_param_v1170
        0x01, //bit1
        0x01  //bit2
    },

#ifdef __BAND_EXTENSION_SUPPORT__
    {//rf_param_v1130
        0x00, //simultaneous_Rx_Tx_r11
        0x00, //supported_CSI_Proc_r11_max_num
        0x00  //multiple_timing_advance_r11
    },
#else
    {//rf_param_v1130
        0x00, //multiple_Timing_Advance_r11
        0x00, //simultaneous_Rx_Tx_r11
        0x00  //supported_CSI_Proc_r11_max_num
    },
#endif

    {//irat_param_c2k_hrpd
        0x01, //tx_Config_HRPD
        0x01  //rx_Config_HRPD
    },

    {//irat_param_c2k_1xrtt
        0x01, //tx_Config_1XRTT
        0x02  //rx_Config_1XRTT
    },

    {//irat_param_c2k_1xrtt_v920
        0x00, //e_CSFB_1XRTT_r9
        0x00  //e_CSFB_ConcPS_Mob1XRTT_r9
    },

    {//irat_param_c2k_1xrtt_v1020
        0x00 //e_CSFB_dual_1XRTT_r10
    },

    {//irat_param_c2k_v1130
        0x00 //cdma2000_NW_Sharing_11
    },

    {//mbms_param_r11
        0x01, //mbms_scell_r11
        0x01  //mbms_non_serving_cell_r11
    },

    {//fdd_add_ue_eutra_cap_v1180
        0x01, //mbms_scell_r11
        0x01  //mbms_non_serving_cell_r11
    },

    {//tdd_add_ue_eutra_cap_v1180
        0x01, //mbms_scell_r11
        0x01  //mbms_non_serving_cell_r11
    },

    0x01, //freq_band_retrieval_r11
    
    0x01, //freq_band_priority_adjustment-r12

    {//nvram_errc_capa_lwa_param_r13_struct
        0x00,   //lwa_r13
        0x01,   //lwa_split_bearer_r13
        0x00    //lwa_buffer_size_r13
    }

// end __LTE_R11__

}
};


static nvram_ef_errc_lte_ca_combin_mask_struct const NVRAM_EF_ERRC_CA_COMBIN_MASK_DEFAULT[] =
{
  {
    { /* White list, default all enable*/
        0xffffffff, /*inter band bitmask band1~band32, the MSB is Band1*/
        0xffffff00, /*inter band bitmask band33~band42, the MSB is Band33*/
        0x00000000, /*reserved for inter band bitmask*/
        0xffc00000, /*intra NCCA band, the MSB is band 4A_4A*/ 
        0xffffffff, /*intra CCA band 1~band32, the MSB is band 1*/ 
        0xfff00000, /*intra CCA band 33~band64, the MSB is band 33*/ 
    },
    { /* Black list, default all disable*/
        0x00000000, /*inter band bitmask band1~band32, the MSB is Band1*/
        0x00000000, /*inter band bitmask band33~band42, the MSB is Band33*/
        0x00000000, /*reserved for inter band bitmask*/
        0x00000000, /*intra NCCA band, the MSB is band 4A_4A*/ 
        0x00000000, /*intra CCA band 1~band32, the MSB is band 1*/ 
        0x00000000, /*intra CCA band 33~band64, the MSB is band 33*/ 
    }
  }
};


static nvram_ef_errc_lte_feature_ctrl_struct const NVRAM_EF_ERRC_LTE_FEATURE_CTRL_DEFAULT[] =
{
{
    /*  lte_feature_set
     * bit 0: LTE CA . 1 = enable, 0 = disable.
     * bit 1: FFS
     * bit 2: FFS
     * bit 3: FFS
     * bit 4: FFS
     * bit 5: FFS
     * bit 6: HPUE. 1 = enable, 0 = disable.
     * bit 7: UL64QAM. 1 = enable, 0 = disable.
     */
    0x01 |
    0x40 |
#if defined(MT6755)  //Jade, Jade- disable UL64QAM
    0x00
#elif  defined(MT6750S) //Rosa enable UL64QAM
    0x80
#elif  defined(MT6757P) //Kibo+ enable UL64QAM, Kibo+ also defines MT6757 hence the order to decide UL64QAM supported status of MT6757P must be in front of MT6757
    0x80
#elif  defined(MT6757)  //Kibo not enable UL64QAM
    0x00
#else     
    0x00
#endif    

}
};


static nvram_ef_errc_vzw_lte_scan_enhance_struct const NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_DEFAULT[] =
{
    {
        0x05,  /* LTE_scan_idle_interval,         unit in second, value range [1..120], default: 5 (default = 5 second, range: 1 - 120 sec, increment: 1 second) */
        0x05,  /* LTE_scan_idle_max,              unit in integer, value range [1..10], default: 5 (default = 5, range: 1 - 10, increment: 1) */
        0x0C,  /* LTE_scan_active_duration_1xRTT, unit in 500 milisecond, value range [1..20], default: 12 (default = 6 seconds, range: 500ms - 10 sec, increment: 500ms) */
        0x03,  /* LTE_scan_active_duration_DO,    unit in 100 milisecond, value range [1..10], default: 3 (default = 300ms, range: 100 - 1000 ms, increment: 100ms) */
        0x0078,  /* LTE_scan_active_interval_1xRTT, unit in 500 milisecond, value range [1..360], default: 120 (default = 1 minute, range: 1 - 3 minute, increment: 500ms) */
        0x0078,  /* LTE_scan_active_interval_DO,    unit in 500 milisecond, value range [1..360], default: 120 (default = 1 minute, range: 1 - 3 minute, increment: 500ms) */
    }
};

static nvram_ef_errc_vzw_lte_scan_enhance_struct const NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_DEFAULT[] =
{
    {
        0x05,  /* LTE_scan_idle_interval,         unit in second, value range [1..120], default: 5 (default = 5 second, range: 1 - 120 sec, increment: 1 second) */
        0x05,  /* LTE_scan_idle_max,              unit in integer, value range [1..10], default: 5 (default = 5, range: 1 - 10, increment: 1) */
        0x06,  /* LTE_scan_active_duration_1xRTT, unit in 500 milisecond, value range [1..20], default: 12 (default = 6 seconds, range: 500ms - 10 sec, increment: 500ms) */
        0x03,  /* LTE_scan_active_duration_DO,    unit in 100 milisecond, value range [1..10], default: 3 (default = 300ms, range: 100 - 1000 ms, increment: 100ms) */
        0x0078,  /* LTE_scan_active_interval_1xRTT, unit in 500 milisecond, value range [1..360], default: 120 (default = 1 minute, range: 1 - 3 minute, increment: 500ms) */
        0x0078,  /* LTE_scan_active_interval_DO,    unit in 500 milisecond, value range [1..360], default: 120 (default = 1 minute, range: 1 - 3 minute, increment: 500ms) */
    }
};


#endif

#ifdef __CHANNEL_LOCK__
static nvram_ef_ch_lock_info_struct const NVRAM_EF_CH_LOCK_INFO_DEFAULT[] =
{
    {
        KAL_TRUE, // lock_supported
        0x00,        // lock_state, INACTIVE
        { 0x00, 0x00 },    // EAS info, don't care
        { 0x00, 0x00 },    // UAS info, don't care
        { 0x00, 0x00 }     // GAS info, don't care
    }
};
#endif /* __CHANNEL_LOCK__ */


ltable_entry_struct logical_data_item_table_errc[] =
{
#ifdef __LTE_RAT__
	{

		NVRAM_EF_ERRC_STORED_CARRIER_LID,
		NVRAM_EF_ERRC_STORED_CARRIER_TOTAL,
		NVRAM_EF_ERRC_STORED_CARRIER_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"ER1A",
		VER(NVRAM_EF_ERRC_STORED_CARRIER_LID)
	},

	{

		NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
		NVRAM_EF_ERRC_PERFORMANCE_PARA_TOTAL,
		NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ERRC_PERFORMANCE_PARA_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"ER1B",
		VER(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID)
	},

	{

		NVRAM_EF_ERRC_FINGER_PRINT_LID,
		NVRAM_EF_ERRC_FINGER_PRINT_TOTAL,
		NVRAM_EF_ERRC_FINGER_PRINT_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"ER1C",
		VER(NVRAM_EF_ERRC_FINGER_PRINT_LID)
	},

	{

		NVRAM_EF_ERRC_LEARNED_MCC_LID,
		NVRAM_EF_ERRC_LEARNED_MCC_TOTAL,
		NVRAM_EF_ERRC_LEARNED_MCC_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"ER1D",
		VER(NVRAM_EF_ERRC_LEARNED_MCC_LID)
	},	  

	{

		NVRAM_EF_ERRC_STORED_CELL_LID,
		NVRAM_EF_ERRC_STORED_CELL_TOTAL,
		NVRAM_EF_ERRC_STORED_CELL_SIZE,
                NVRAM_NORMAL(NVRAM_EF_ERRC_STORED_CELL_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"ER1E",
		VER(NVRAM_EF_ERRC_STORED_CELL_LID)
	},
		
	{

		NVRAM_EF_ERRC_AFR_SETTING_LID,
		NVRAM_EF_ERRC_AFR_SETTING_TOTAL,
		NVRAM_EF_ERRC_AFR_SETTING_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ERRC_AFR_SETTING_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"ER1F",
		VER(NVRAM_EF_ERRC_AFR_SETTING_LID)
	},

	{

		NVRAM_EF_LTE_CAP_LID,
		NVRAM_EF_LTE_CAP_TOTAL,
		NVRAM_EF_LTE_CAP_SIZE,
		NVRAM_NORMAL(NVRAM_EF_LTE_CAP_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"LTEA",
		VER(NVRAM_EF_LTE_CAP_LID)
	},

	{

		NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
		NVRAM_EF_UE_EUTRA_CAP_CSFB_TOTAL,
		NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE,
		NVRAM_NORMAL(NVRAM_EF_UE_EUTRA_CAP_CSFB_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"LTEB",
		VER(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID)
	},	  

	{

		NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
		NVRAM_EF_UE_EUTRA_CAP_MMDC_TOTAL,
		NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE,
		NVRAM_NORMAL(NVRAM_EF_UE_EUTRA_CAP_MMDC_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"LTEC",
		VER(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID)
	},

	{

		NVRAM_EF_ERRC_VZW_MRU_LID,
		NVRAM_EF_ERRC_VZW_MRU_TOTAL,
		NVRAM_EF_ERRC_VZW_MRU_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"LTED",
		VER(NVRAM_EF_ERRC_VZW_MRU_LID)
	},			 

	{

		NVRAM_EF_LTE_CAP_CA_COMBIN_MASK_LID,
		NVRAM_EF_LTE_CA_COMBIN_MASK_TOTAL,
		NVRAM_EF_LTE_CA_COMBIN_MASK_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ERRC_CA_COMBIN_MASK_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"LTEE",
		VER(NVRAM_EF_LTE_CAP_CA_COMBIN_MASK_LID)
	},	 

	{

		NVRAM_EF_LTE_FEATURE_CTRL_LID,
		NVRAM_EF_LTE_FEATURE_CTRL_TOTAL,
		NVRAM_EF_LTE_FEATURE_CTRL_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ERRC_LTE_FEATURE_CTRL_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"LTEF",
		VER(NVRAM_EF_LTE_FEATURE_CTRL_LID)
	},	 

	{

		NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_LID,
		NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_TOTAL,
		NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"LTEG",
		VER(NVRAM_EF_ERRC_VZW_LTE_SCAN_ENHANCE_LID)
	},
	{
	    NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_LID,
		NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_TOTAL,
		NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"LTEJ",
		VER(NVRAM_EF_ERRC_LTE_SCAN_ENHANCE_LID)
	},
#endif

#ifdef __CHANNEL_LOCK__
    {
            NVRAM_EF_CH_LOCK_INFO_LID,
            NVRAM_EF_CH_LOCK_INFO_TOTAL,
            NVRAM_EF_CH_LOCK_INFO_SIZE,
            NVRAM_NORMAL(NVRAM_EF_CH_LOCK_INFO_DEFAULT),
            NVRAM_CATEGORY_USER,
            NVRAM_ATTR_AVERAGE,
            "MT33",
            VER(NVRAM_EF_CH_LOCK_INFO_LID)
    },
#endif /* __CHANNEL_LOCK__ */

#ifdef __LTE_RAT__
    {
		NVRAM_EF_ERRC_RCM_CA_ENABLE_LIST_LID,
		NVRAM_EF_ERRC_RCM_CA_ENABLE_LIST_TOTAL,
		NVRAM_EF_ERRC_RCM_CA_ENABLE_LIST_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"LTEH",
		VER(NVRAM_EF_ERRC_RCM_CA_ENABLE_LIST_LID)
	},
	{
		NVRAM_EF_ERRC_RCM_CA_DISABLE_LIST_LID,
		NVRAM_EF_ERRC_RCM_CA_DISABLE_LIST_TOTAL,
		NVRAM_EF_ERRC_RCM_CA_DISABLE_LIST_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"LTEI",
		VER(NVRAM_EF_ERRC_RCM_CA_DISABLE_LIST_LID)
	},
#endif	
	
	NVRAM_LTABLE_END
};


#endif
