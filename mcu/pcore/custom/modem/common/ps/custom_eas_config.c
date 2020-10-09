/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * custom_eas_config.c
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the EAS configuration.
 *
 * Author:
 * -------
 * -------
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "custom_eas_config.h"

/*4G Background Search interval parameter setting:
  Any modification for these value should according to the defined range.
  Otherwise,MD will use the default value instead of setting value.
  Please noted that the maximum value should greater or equal to the initial value.
  NOTE: You may set the delta value to ZERO for fix interval.
*/  
kal_uint8 lte_bgsrch_intv_para[]={  2,/*Initial value(minutes),range:(2..120),default value:2*/
                                  120,/*Maximum value(minutes),range:(2..120),default value:120*/
                                    1 /*Delta value(minutes),  range:(0..5)  ,default value:1*/
                                  };

/*****************************************************************************
* FUNCTION
*   eas_custom_get_bgsrch_intv_para
* DESCRIPTION
*   The function gives 4G background search interval parameters.
*
* PARAMETERS
*  The output value pointers
* RETURNS
*  void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void eas_custom_get_bgsrch_intv_para(kal_uint8 *a_intv_init_ptr,
                                     kal_uint8 *a_intv_max_ptr,
                                     kal_uint8 *a_intv_delta_ptr )
{
    if (a_intv_init_ptr)
    {
        *a_intv_init_ptr  = lte_bgsrch_intv_para[0];
    }
    if (a_intv_max_ptr)
    {
        *a_intv_max_ptr   = lte_bgsrch_intv_para[1];
    }
    if (a_intv_delta_ptr)
    {
        *a_intv_delta_ptr = lte_bgsrch_intv_para[2];
    }

}                                                                       

#if defined (__AS_SPECIFIC_CHANNEL_SRCH__)|| defined(UNIT_TEST)
kal_bool eas_custom_specific_channel_srch = KAL_FALSE;


/**
 * The specific channels
 * How to use:
 * Max number is define in NUM_OF_LTE_SPECIFIC_CHANNELS.
 * If user only want to config EARFCNs less than NUM_OF_LTE_SPECIFIC_CHANNELS in some band, just fill invalid EARFCN.
 * For example, if band 1 only need 3 EARFCNs, just fill {300,301,302,0xffff}
 */
kal_uint32 specific_earfcn[NUM_OF_LTE_SPECIFIC_BANDS][NUM_OF_LTE_SPECIFIC_CHANNELS]     = 
{
    {  300,  301,  302,  500}, /* band  1 */
    {  900,  901,  902,  903}, /* band  2 */
    { 1575, 1576, 1577, 1578}, /* band  3 */
    { 2175, 2176, 2177, 2178}, /* band  4 */
    { 2525, 2526, 2527, 2528}, /* band  5 */
    { 2700, 2701, 2702, 2703}, /* band  6 */
    { 3100, 3101, 3102, 3103}, /* band  7 */
    { 3625, 3626, 3627, 3628}, /* band  8 */
    { 3975, 3976, 3977, 3978}, /* band  9 */
    { 4450, 4451, 4452, 4453}, /* band 10 */
    { 4850, 4851, 4852, 4853}, /* band 11 */
    { 5095, 5096, 5097, 5098}, /* band 12 */
    { 5230, 5231, 5232, 5233}, /* band 13 */
    { 5330, 5331, 5332, 5333}, /* band 14 */
    {65535,65535,65535,65535}, /* band 15 */
    {65535,65535,65535,65535}, /* band 16 */
    { 5790, 5791, 5792,65535}, /* band 17 */
    {65535,65535,65535,65535}, /* band 18 */
    { 6075, 6076, 6077, 6078}, /* band 19 */
    { 6300, 6301, 6302, 6303}, /* band 20 */
    { 6525, 6526, 6527, 6528}, /* band 21 */
    {65535,65535,65535,65535}, /* band 22 */
    {65535,65535,65535,65535}, /* band 23 */
    {65535,65535,65535,65535}, /* band 24 */
    { 8365, 8366, 8367, 8368}  /* band 25 */
};
#endif

#ifdef __LTE_R11__
/*******************************************************************************
 * Allowed to customize our own PLMN and LTE band requirements mapping here.
 * By referring to this data, ERRC build EUTRA Capability accordingly in order 
 * to deal with legacy network issues.
 * 
 * Bit 1: Required
 *     0: Not required
 ******************************************************************************/
#ifdef __BAND_EXTENSION_SUPPORT__
const eas_custom_eutra_cap_plmn_config CUSTOM_EUTRA_CAP_PLMN_CFG[] = 
{
    /*          B8~B1, B16~B9, B24~B17, B32~B25, B40~B33, B48~B41, B56~B49, B64~B57, B72~B65, B80~B73, B88~B81, B96~B89, B104~B97, B112~B105, B120~B113, B128~B121, B136~B129, B144~B137, B152~B145, B160~B153, B168~B161, B176~B169, B184~B177, B192~B185, B200~B193, B208~B201, B216~B209, B224~B217, B232~B225, B240~B233, B248~B241, B256~B249 */
    {"23420F", { 0xC5,   0x00,    0x08,    0x00,    0xA0,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // H3G, UK
    {"23410F", {   0xC5,     0x00,      0x08,      0x00,      0xA0,      0x00,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // O2, UK
    {"23411F", {   0xC5,     0x00,      0x08,      0x00,      0xA0,      0x00,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // O2, UK
    {"23415F", {   0xC5,     0x00,      0x08,      0x00,      0xA0,      0x00,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // Vodafone, UK

    {"310030", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00,      0x02,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // AT&T, USA
    {"310150", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00,      0x02,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // AT&T, USA
    {"310170", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00,      0x02,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // AT&T, USA
    {"310280", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00,      0x02,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // AT&T, USA
    {"310380", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00,      0x02,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // AT&T, USA
    {"310410", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00,      0x02,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // AT&T, USA
    
    {"330110", {   0x08,     0x08,      0x01,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // Claro, Puerto Rico
    {"37002F", {   0x08,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // Claro, Dominican Republic

    
    {"334010", {   0x08,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // AT&T, Mexico
    {"334050", {   0x08,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // AT&T, Mexico
    {"334090", {   0x08,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // AT&T, Mexico
    {"334020", {   0x08,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x02,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // Telcel, Mexico
    {"334030", {   0x02,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // Movistar, Mexico
    {"455FFF", {   0xC5,     0x00,      0x00,	   0x00,      0x80,      0x00,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,	      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,	     0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // Macao

    {"45002F", { 0x85,   0x00,    0x00,    0x02,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // KT, Korea
    {"45004F", { 0x85,   0x00,    0x00,    0x02,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // KT, Korea
    {"45008F", { 0x85,   0x00,    0x00,    0x02,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // KT, Korea
    {"45003F", { 0x15,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // SKT, Korea
    {"45005F", { 0x15,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // SKT, Korea
    {"45011F", { 0x15,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // SKT, Korea

    {"45400F", { 0xC4,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CSL, HongKong
    {"45401F", { 0xC4,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CITIC Telecom, MVNO on CSL, HongKong
    {"45402F", { 0xC4,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CSL, HongKong
    {"45409F", { 0xC4,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // China Motion Telecom, MVNO on CSL, HongKong
    {"45410F", { 0xC4,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CSL/New World PCS Ltd, HongKong
    {"45418F", { 0xC4,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CSL, HongKong
    {"45416F", { 0x44,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // HKT/PCCW, HongKong
    {"45419F", { 0x44,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // HKT/PCCW, HongKong
    {"45420F", { 0x44,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // HKT/PCCW, HongKong
    {"45429F", { 0x44,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // HKT/PCCW, HongKong
    {"45411F", { 0xC5,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // China-HongKong Telecom, MVNO on PCCW & 3, HongKong
    {"45407F", { 0x44,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // China Unicom (Hong Kong) Ltd, MVNO on PCCW, HongKong
//    {"45403F", { 0xC5,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // 3, HongKong
//    {"45404F", { 0xC5,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // 3, HongKong
//    {"45405F", { 0xC5,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // 3, HongKong
//    {"45414F", { 0xC5,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // 3, HongKong
//    {"45406F", { 0xC4,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // SmarTone, HongKong
//    {"45415F", { 0xC4,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // SmarTone, HongKong
//    {"45417F", { 0xC4,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // SmarTone, HongKong
//    {"45422F", { 0xC4,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // Formerly P Plus Communications, acquired by SmarTone, HongKong
//    {"45412F", { 0x44,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CMHK, HongKong
//    {"45413F", { 0x44,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CMHK, MVNO on PCCW (3G), HongKong

    {"46000F", { 0xC5,   0x00,    0x00,    0x00,    0xE2,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CMCC, China
    {"46002F", { 0xC5,   0x00,    0x00,    0x00,    0xE2,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CMCC, China
    {"46004F", { 0xC5,   0x00,    0x00,    0x00,    0xE2,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CMCC, China
    {"46007F", { 0xC5,   0x00,    0x00,    0x00,    0xE2,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CMCC, China
    {"46008F", { 0xC5,   0x00,    0x00,    0x00,    0xE2,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CMCC, China
    {"46001F", { 0x85,   0x00,    0x00,    0x00,    0xE0,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CU, China
    {"46006F", { 0x85,   0x00,    0x00,    0x00,    0xE0,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CU, China
    {"46009F", { 0x85,   0x00,    0x00,    0x00,    0xE0,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CU, China
    {"46003F", { 0x5D,   0x00,    0x00,    0x02,    0x80,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CT, China
    {"46005F", { 0x5D,   0x00,    0x00,    0x02,    0x80,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CT, China
    {"46011F", { 0x5D,   0x00,    0x00,    0x02,    0x80,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CT, China

    /* All TW LTE bands included */
    {"46689F", { 0xC4,   0x00,    0x00,    0x08,    0x20,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // T-Star, Taiwan
    {"46690F", { 0xC4,   0x00,    0x00,    0x08,    0x20,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // T-Star, Taiwan
    {"46692F", { 0xC4,   0x00,    0x00,    0x08,    0x20,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // CHT, Taiwan
    {"46697F", { 0xC4,   0x00,    0x00,    0x08,    0x20,    0x01,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // TWN, Taiwan
    {"46692F", {   0xC4,     0x00,      0x00,      0x08,      0x20,      0x01,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // CHT, Taiwan
    {"46601F", {   0xC4,     0x00,      0x00,      0x08,      0x20,      0x01,      0x00,      0x00,      0x00,     0x00,      0x00,      0x00,      0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00,       0x00,        0x00,        0x00,        0x00,        0x00,        0x00,        0x00 }},  // FET, Taiwan

    {"502FFF", { 0xD4,   0x00,    0x00,    0x00,    0xa0,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // Malaysia

    {"722310", { 0x08,   0x00,    0x00,    0x08,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // Claro, Argentina
    {"722320", { 0x08,   0x00,    0x00,    0x08,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // Claro, Argentina
    {"722330", { 0x08,   0x00,    0x00,    0x08,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // Claro, Argentina
    {"732101", { 0x40,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // Claro, Colombia

#ifdef UNIT_TEST
    {"00195F", { 0x18,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x02,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x48  }},  // For UT
    {"00196F", { 0x18,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x02,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // For UT
    {"00197F", { 0x10,   0x00,    0x00,    0x00,    0x80,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // For UT
    {"00198F", { 0x10,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // For UT
    {"00199F", { 0x00,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // For UT
    {"999",    { 0x00,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // For UT
    {"",       { 0x00,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // For UT
    {"9999999",{ 0x00,   0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,    0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00  }},  // For UT
#endif

    {"FFFFFF", { 0xFF,   0xFF,    0xFF,    0xFF,    0xFF,    0xFF,    0xFF,    0xFF,    0xFF,    0xFF,    0xFF,    0xFF,     0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF  }}   // END (don't touch and put your new entry above this line)
};
#else
const eas_custom_eutra_cap_plmn_config CUSTOM_EUTRA_CAP_PLMN_CFG[] = 
{
    /*          B8 ~ B1, B16 ~ B9, B24 ~ B17, B32 ~ B25, B40 ~ B33, B48 ~ B41, B56 ~ B49, B64 ~ B57 */
    {"23420F", {   0xC5,     0x00,      0x08,      0x00,      0xA0,      0x00,      0x00,      0x00}},  // H3G, UK
    
    {"310030", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00}},  // AT&T, USA
    {"310150", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00}},  // AT&T, USA
    {"310170", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00}},  // AT&T, USA
    {"310280", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00}},  // AT&T, USA
    {"310380", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00}},  // AT&T, USA
    {"310410", {   0x1A,     0x28,      0x01,      0x30,      0x00,      0x00,      0x00,      0x00}},  // AT&T, USA

    {"330110", {   0x08,     0x08,      0x01,      0x00,      0x00,      0x00,      0x00,      0x00}},  // Claro, Puerto Rico
    {"37002F", {   0x08,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // Claro, Dominican Republic
    
    {"334010", {   0x08,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // AT&T, Mexico
    {"334050", {   0x08,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // AT&T, Mexico
    {"334090", {   0x08,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // AT&T, Mexico
    {"334020", {   0x08,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // Telcel, Mexico
    {"334030", {   0x02,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // Movistar, Mexico
    {"455FFF", {   0xC5,     0x00,      0x00,	   0x00,      0x80,      0x00,      0x00,      0x00}},  // Macao  

    {"45002F", {   0x85,     0x00,      0x00,      0x02,      0x80,      0x00,      0x00,      0x00}},  // KT, Korea
    {"45004F", {   0x85,     0x00,      0x00,      0x02,      0x80,      0x00,      0x00,      0x00}},  // KT, Korea
    {"45008F", {   0x85,     0x00,      0x00,      0x02,      0x80,      0x00,      0x00,      0x00}},  // KT, Korea
    {"45003F", {   0x15,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // SKT, Korea
    {"45005F", {   0x15,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // SKT, Korea
    {"45011F", {   0x15,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // SKT, Korea

    {"45400F", {   0xC4,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // CSL, HongKong
    {"45401F", {   0xC4,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // CITIC Telecom, MVNO on CSL, HongKong
    {"45402F", {   0xC4,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // CSL, HongKong
    {"45409F", {   0xC4,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // China Motion Telecom, MVNO on CSL, HongKong
    {"45410F", {   0xC4,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // CSL/New World PCS Ltd, HongKong
    {"45418F", {   0xC4,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // CSL, HongKong
    {"45416F", {   0x44,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // HKT/PCCW, HongKong
    {"45419F", {   0x44,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // HKT/PCCW, HongKong
    {"45420F", {   0x44,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // HKT/PCCW, HongKong
    {"45429F", {   0x44,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // HKT/PCCW, HongKong
    {"45411F", {   0xC5,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // China-HongKong Telecom, MVNO on PCCW & 3, HongKong
    {"45407F", {   0x44,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // China Unicom (Hong Kong) Ltd, MVNO on PCCW, HongKong
//    {"45403F", {   0xC5,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // 3, HongKong
//    {"45404F", {   0xC5,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // 3, HongKong
//    {"45405F", {   0xC5,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // 3, HongKong
//    {"45414F", {   0xC5,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // 3, HongKong
//    {"45406F", {   0xC4,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // SmarTone, HongKong
//    {"45415F", {   0xC4,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // SmarTone, HongKong
//    {"45417F", {   0xC4,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // SmarTone, HongKong
//    {"45422F", {   0xC4,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // Formerly P Plus Communications, acquired by SmarTone, HongKong
//    {"45412F", {   0x44,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // CMHK, HongKong
//    {"45413F", {   0x44,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // CMHK, MVNO on PCCW (3G), HongKong

    {"46000F", {   0xC5,     0x00,      0x00,      0x00,      0xE2,      0x01,      0x00,      0x00}},  // CMCC, China
    {"46002F", {   0xC5,     0x00,      0x00,      0x00,      0xE2,      0x01,      0x00,      0x00}},  // CMCC, China
    {"46004F", {   0xC5,     0x00,      0x00,      0x00,      0xE2,      0x01,      0x00,      0x00}},  // CMCC, China
    {"46007F", {   0xC5,     0x00,      0x00,      0x00,      0xE2,      0x01,      0x00,      0x00}},  // CMCC, China
    {"46008F", {   0xC5,     0x00,      0x00,      0x00,      0xE2,      0x01,      0x00,      0x00}},  // CMCC, China
    {"46001F", {   0x85,     0x00,      0x00,      0x00,      0xE0,      0x01,      0x00,      0x00}},  // CU, China
    {"46006F", {   0x85,     0x00,      0x00,      0x00,      0xE0,      0x01,      0x00,      0x00}},  // CU, China
    {"46009F", {   0x85,     0x00,      0x00,      0x00,      0xE0,      0x01,      0x00,      0x00}},  // CU, China
    {"46003F", {   0x5D,     0x00,      0x00,      0x02,      0x80,      0x01,      0x00,      0x00}},  // CT, China
    {"46005F", {   0x5D,     0x00,      0x00,      0x02,      0x80,      0x01,      0x00,      0x00}},  // CT, China
    {"46011F", {   0x5D,     0x00,      0x00,      0x02,      0x80,      0x01,      0x00,      0x00}},  // CT, China

    /* All TW LTE bands included */
    {"46689F", {   0xC4,     0x00,      0x00,      0x08,      0x20,      0x01,      0x00,      0x00}},  // T-Star, Taiwan
    {"46690F", {   0xC4,     0x00,      0x00,      0x08,      0x20,      0x01,      0x00,      0x00}},  // T-Star, Taiwan
    {"46692F", {   0xC4,     0x00,      0x00,      0x08,      0x20,      0x01,      0x00,      0x00}},  // CHT, Taiwan
    {"46697F", {   0xC4,     0x00,      0x00,      0x08,      0x20,      0x01,      0x00,      0x00}},  // TWN, Taiwan

    {"502FFF", {   0xD4,     0x00,      0x00,      0x00,      0xa0,      0x00,      0x00,      0x00}},  // Malaysia

    {"722310", {   0x08,     0x00,      0x00,      0x08,      0x00,      0x00,      0x00,      0x00}},  // Claro, Argentina
    {"722320", {   0x08,     0x00,      0x00,      0x08,      0x00,      0x00,      0x00,      0x00}},  // Claro, Argentina
    {"722330", {   0x08,     0x00,      0x00,      0x08,      0x00,      0x00,      0x00,      0x00}},  // Claro, Argentina
    {"732101", {   0x40,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // Claro, Colombia

#ifdef UNIT_TEST
    {"00197F", {   0x10,     0x00,      0x00,      0x00,      0x80,      0x00,      0x00,      0x00}},  // For UT
    {"00198F", {   0x10,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // For UT
    {"00199F", {   0x00,     0x00,      0x00,      0x00,      0x00,      0x00,      0x00,      0x00}},  // For UT
#endif

    {"FFFFFF", {   0xFF,     0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF,      0xFF}}   // END (don't touch and put your new entry above this line)
};
#endif  /* __BAND_EXTENSION_SUPPORT__ */

const kal_uint32 CUSTOM_EUTRA_CAP_PLMN_CFG_NUM = sizeof(CUSTOM_EUTRA_CAP_PLMN_CFG)/sizeof(eas_custom_eutra_cap_plmn_config);

/* This flag is used to decide if we want to disbale LTE band support not only
 * in the RRC signaling level (@EUTRA Capability), but also in UE internally 
 */
const kal_bool CUSTOM_IS_BAND_ACTUALLY_DISABLED = KAL_FALSE;
/*************************************************************************
* Function
*************************************************************************/

#ifdef __BAND_EXTENSION_SUPPORT__
/****************************************************************************** 
 * Current CA combination bit position:
 *   Inter First
 *     1A__3A, 1A__5A, 1A__7A, 1A_8A, 1A_11A, 1A_18A, 1A_19A, 1A_20A, 1A_21A, 1A_26A, 1A_28A, 2A_4A, 2A__5A, 2A_12A, 2A_13A, 2A_17A,
 *     2A_29A, 2A_30A, 3A__4A, 3A_5A, 3A__7A, 3A__8A, 3A_19A, 3A_20A, 3A_26A, 3A_27A, 3A_28A, 4A_5A, 4A__7A, 4A_12A, 4A_13A, 4A_17A
 *
 *   Inter Second
 *      4A_29A,  4A_30A,  4A_41A,  5A__7A,  5A_12A,  5A_17A,  5A_25A,  5A_30A, 7A__8A,  7A_20A, 7A_28A, 8A_20A, 8A_40A, 11A_18A, 12A_25A, 12A_30A,
 *     17A_30A, 19A_21A, 20A_32A, 20A_38A, 23A_29A, 26A_41A, 29A_30A, 39A_41A, 4A_28A, 25A_26A, 8A_11A, 2A_66A, 5A_66A, 12A_66A, 13A_66A
 *
 *   Inter Third (reserved for future use)
 *     N/A
 *
 *   Intra NCCA
 *     2A_2A, 3A_3A, 4A_4A, 7A_7A, 23A_23A, 25A_25A, 41A_41A, 41A_41C, 41C_41A, 42A_42A, 40A_40A, 66A_66A
 *
 *   IntraCCA First
 *      1A,  2A,  3A,  4A,  5A,  6A,  7A,  8A,  9A, 10A, 11A, 12A, 13A, 14A, 15A, 16A
 *     17A, 18A, 19A, 20A, 21A, 22A, 23A, 24A, 25A, 26A, 27A, 28A, 29A, 30A, 31A, 32A
 *
 *   IntraCCA Second
 *     33A, 34A, 35A, 36A, 37A, 38A, 39A, 40A, 41A, 42A, 43A, 44A, 66A
 *
 * Bit set to 1: Blacklisted CA combination
 *            0: Non-blacklisted CA combination
 ******************************************************************************/
const eas_custom_CA_combination_blacklist_plmn_config CUSTOM_CA_COMBINATION_BLACKLIST_PLMN_CFG[] = 
{
    /*          Inter First,   Inter Second,   Inter Third,   Intra NCCA,  IntraCCA First, IntraCCA Second */
   
    {"46000F", { 0xffffffff,     0xfffffefe,    0x00000000,   0xfc100000,      0xffffffff,      0x00080000} },  // CMCC, China
    {"46002F", { 0xffffffff,     0xfffffefe,    0x00000000,   0xfc100000,      0xffffffff,      0x00080000} },  // CMCC, China
    {"46004F", { 0xffffffff,     0xfffffefe,    0x00000000,   0xfc100000,      0xffffffff,      0x00080000} },  // CMCC, China
    {"46007F", { 0xffffffff,     0xfffffefe,    0x00000000,   0xfc100000,      0xffffffff,      0x00080000} },  // CMCC, China
    {"46008F", { 0xffffffff,     0xfffffefe,    0x00000000,   0xfc100000,      0xffffffff,      0x00080000} },  // CMCC, China
#ifdef UNIT_TEST
    {"12345F", { 0x40000000,     0xfffffefe,    0x00000000,   0xfc100000,      0xffffffff,      0x00080000} },  // test
#endif
    {"FFFFFF", { 0xffffffff,     0xffffffff,    0xffffffff,   0xffffffff,      0xffffffff,      0xffffffff} }   // END (don't touch and put your new entry above this line)
};
const eas_custom_enhanced_CA_combination_blacklist_config CUSTOM_ENHANCED_CA_COMBINATION_BLACKLIST_CFG[] = 
{ 

    {"46000F", {   {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},     {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}} } },  // CMCC, China
    {"46002F", {   {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},     {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}} } },  // CMCC, China
    {"46004F", {   {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},     {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}} } },  // CMCC, China
    {"46007F", {   {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},     {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}} } },  // CMCC, China
    {"46008F", {   {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},     {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}} } },  // CMCC, China
#ifdef UNIT_TEST
    {"12345F", {   {{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},     {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}} } },  // CMCC, China
#endif
    {"FFFFFF", {   {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},     {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      
    	      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},      {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}} } },  // END (don't touch and put your new entry above this line)
};

const kal_uint32 CUSTOM_ENHANCED_CA_COMBINATION_BLACKLIST_CFG_NUM = sizeof(CUSTOM_ENHANCED_CA_COMBINATION_BLACKLIST_CFG)/sizeof(eas_custom_enhanced_CA_combination_blacklist_config);

#else
const eas_custom_CA_combination_blacklist_plmn_config CUSTOM_CA_COMBINATION_BLACKLIST_PLMN_CFG[] = 
{

    {"46000F", {   0xffffffff,     0xfffffe00,      0x00000000,      0xfc000000,      0xffffffff,      0x00000000} },  // CMCC, China
    {"46002F", {   0xffffffff,     0xfffffe00,      0x00000000,      0xfc000000,      0xffffffff,      0x00000000} },  // CMCC, China
    {"46004F", {   0xffffffff,     0xfffffe00,      0x00000000,      0xfc000000,      0xffffffff,      0x00000000} },  // CMCC, China
    {"46007F", {   0xffffffff,     0xfffffe00,      0x00000000,      0xfc000000,      0xffffffff,      0x00000000} },  // CMCC, China
    {"46008F", {   0xffffffff,     0xfffffe00,      0x00000000,      0xfc000000,      0xffffffff,      0x00000000} },  // CMCC, China

    {"FFFFFF", {   0xffffffff,     0xffffffff,      0xffffffff,      0xffffffff,      0xffffffff,      0xffffffff} }   // END (don't touch and put your new entry above this line)
};
const eas_custom_enhanced_CA_combination_blacklist_config CUSTOM_ENHANCED_CA_COMBINATION_BLACKLIST_CFG[] = 
{

    {"46000F", {   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} } },  // CMCC, China
    {"46002F", {   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} } },  // CMCC, China
    {"46004F", {   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} } },  // CMCC, China
    {"46007F", {   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} } },  // CMCC, China
    {"46008F", {   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} } },  // CMCC, China


    {"FFFFFF", {   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      
    	      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} } },  // END (don't touch and put your new entry above this line)
};

const kal_uint32 CUSTOM_ENHANCED_CA_COMBINATION_BLACKLIST_CFG_NUM = sizeof(CUSTOM_ENHANCED_CA_COMBINATION_BLACKLIST_CFG)/sizeof(eas_custom_enhanced_CA_combination_blacklist_config);


#endif  /* __BAND_EXTENSION_SUPPORT__ */

const kal_uint32 CUSTOM_CA_COMBINATION_BLACKLIST_PLMN_CFG_NUM = sizeof(CUSTOM_CA_COMBINATION_BLACKLIST_PLMN_CFG)/sizeof(eas_custom_CA_combination_blacklist_plmn_config);

/*************************************************************************
* Function
*************************************************************************/
const eas_custom_fgi_blacklist_plmn_config CUSTOM_FGI_BLACKLIST_PLMN_CFG[] = 
{
    /*PLMN id, fgi-fdd1~32 MSB=fgi1, fgi-tdd1~32 MSB=fgi1, fgifdd33~41 MSB=fgi33, fgitdd33~41 MSB=fgi33, fgifdd101~116 MSB=101, fgitdd101~116 MSB=101 */
    {"46000F", 0x00000000,           0x00000000,           0x00000000,            0x00000000,            0x00000000,            0x00000000 },  // CMCC, China
    {"46002F", 0x00000000,           0x00000000,           0x00000000,            0x00000000,            0x00000000,            0x00000000 },  // CMCC, China
    {"46004F", 0x00000000,           0x00000000,           0x00000000,            0x00000000,            0x00000000,            0x00000000 },  // CMCC, China
    {"46007F", 0x00000000,           0x00000000,           0x00000000,            0x00000000,            0x00000000,            0x00000000 },  // CMCC, China
    {"46008F", 0x00000000,           0x00000000,           0x00000000,            0x00000000,            0x00000000,            0x00000000 },  // CMCC, China

    /* below is an example to disable FGI 8, 22, 27, 33, 114 */
    //{"46601F", 0x01000420,           0x01000420,           0x80000000,            0x80000000,            0x00040000,            0x00040000 },  // FET

    {"FFFFFF", 0x00000000,           0x00000000,           0x00000000,            0x00000000,            0x00000000,            0x00000000 }   // END (don't touch and put your new entry above this line)
};

const kal_uint32 CUSTOM_FGI_BLACKLIST_PLMN_CFG_NUM = sizeof(CUSTOM_FGI_BLACKLIST_PLMN_CFG)/sizeof(eas_custom_fgi_blacklist_plmn_config);


#if defined(__HSR_ENHANCE__)
/*******************************************************************************
 * Allowed to customize HSR (High Speed Railway) specific PLMN Identities here.
 * By referring to this data, UE decides to start corresponding enhancement 
 * mechanism or not.
 *
 * Currently the maximum allowed number for HSR specific PLMN is 50.
 ******************************************************************************/
const mrs_custom_hsr_plmn_list CUSTOM_MRS_HSR_PLMN_LIST[] = 
{
    {"46000F"}, /*{"46002F"},*/ {"46004F"}, /*{"46007F"}, {"46008F"},*/  // CMCC, China
    {"46001F"}, /*{"46006F"}, {"46009F"},*/                              // CU, China

    {"FFFFFF"}   // END (don't touch and put your new entry above this line)
};

const kal_uint32 CUSTOM_MRS_HSR_PLMN_LIST_NUM = sizeof(CUSTOM_MRS_HSR_PLMN_LIST)/sizeof(mrs_custom_hsr_plmn_list);
#endif  /* END of __HSR_ENHANCE__ */

/*******************************************************************************
 * ROHC profile custom config
 ******************************************************************************/
const custom_eas_lte_rohc_profile_config CUSTOM_EUTRA_ROHC_PROFILE_CFG[]=
{
    /*PLMN id,                profile0x0001,         profile0x0002,         profile0x0003,        profile0x0004,         profile0x0006,        profile0x0101,        profile0x0102,         profile0x0103,        profile0x0104  */
#ifdef UNIT_TEST
    {"12345F",{    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE}},  //for test purpose
    {"12346F",{    KAL_TRUE,     KAL_FALSE,    KAL_TRUE,    KAL_FALSE,      KAL_TRUE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE}},  //for test purpose
#endif
    {"FFFFFF",{    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE,    KAL_FALSE}}  //END
};

const kal_uint32 CUSTOM_EUTRA_ROHC_PROFILE_NUM = sizeof(CUSTOM_EUTRA_ROHC_PROFILE_CFG)/sizeof(custom_eas_lte_rohc_profile_config);


/*******************************************************************************
 *  LWA whitelist
 ******************************************************************************/

#ifdef __LWA_SUPPORT__
const eas_custom_lwa_whitelist_plmn_config CUSTOM_LWA_WHITELIST_PLMN_CFG[] = 
{
    {"46692F", "46692F"},  // HPLMN, CHT; RPLMN, CHT
#ifdef UNIT_TEST
    {"46601F", "FFFFFF"},  // HPLMN, FET; RPLMN, don't care
    {"FFFFFF", "46689F"},  // HPLMN, don't care; RPLMN, T-Star
#endif
    {"FFFFFF", "FFFFFF"}   // END (don't touch and put your new entry above this line)
};

const kal_uint32 CUSTOM_LWA_WHITELIST_PLMN_CFG_NUM = sizeof(CUSTOM_LWA_WHITELIST_PLMN_CFG)/sizeof(eas_custom_lwa_whitelist_plmn_config);
#endif//__LWA_SUPPORT__

#endif  /* END of #ifdef __LTE_R11__ */

/*************************************************************************
* Function
*************************************************************************/

#if defined (__AS_SPECIFIC_CHANNEL_SRCH__)|| defined(UNIT_TEST)
/*****************************************************************************
* FUNCTION
*  eas_custom_set_specific_channel_srch
* DESCRIPTION
*   The function set specific search mode.
*
* PARAMETERS
*   kal_bool
*   TRUE: set specific search mode, FALSE: disable specific search mode.
* RETURNS
*   Void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void eas_custom_set_specific_channel_srch( kal_bool set_value )
{
    eas_custom_specific_channel_srch = set_value;
}
/*****************************************************************************
* FUNCTION
*  eas_custom_is_specific_channel_srch
* DESCRIPTION
*   The function returns whether UE is in specific channel search mode.
*
* PARAMETERS
*  Void
* RETURNS
*  kal_bool
*  TRUE: specific channel search mode, FALSE: normal search mode
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool eas_custom_is_specific_channel_srch(void)
{
    return eas_custom_specific_channel_srch;
}
/*****************************************************************************
* FUNCTION
*  eas_custom_get_specific_earfcn
* DESCRIPTION
*   The function returns custom configured specific earfcn.
*
* PARAMETERS
*   kal_uint8 band: the specific band
*   kal_uint8 earfcn_index: the specific channel index
* RETURNS
*  kal_uint32: earfcn
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 eas_custom_get_specific_earfcn(kal_uint8 band, kal_uint8 earfcn_index)
{
    return specific_earfcn[band][earfcn_index];
}
/*****************************************************************************
* FUNCTION
*  eas_custom_set_specific_earfcn
* DESCRIPTION
*   The function sets custom configured specific earfcn.
*
* PARAMETERS
*   kal_uint8 band: the specific band
*   kal_uint8 earfcn_index: the specific channel index
*   kal_uint32 earfcn: the specific earfcn
* RETURNS
*   Void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void eas_custom_set_specific_earfcn(kal_uint8 band, kal_uint8 earfcn_index, kal_uint32 earfcn)
{
    specific_earfcn[band][earfcn_index] = earfcn;
    return;
}
/*****************************************************************************
* FUNCTION
*  eas_custom_get_lte_specific_band_number
* DESCRIPTION
*   The function returns custom configured the number of specific band.
*
* PARAMETERS
*   void
* RETURNS
*  kal_uint8: NUM_OF_LTE_SPECIFIC_BANDS
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 eas_custom_get_lte_specific_band_number(void)
{
    return (kal_uint8)NUM_OF_LTE_SPECIFIC_BANDS;
}
/*****************************************************************************
* FUNCTION
*  eas_custom_get_lte_specific_channel_number
* DESCRIPTION
*   The function returns custom configured the number of specific earfcn.
*
* PARAMETERS
*   void
* RETURNS
*  kal_uint8: NUM_OF_LTE_SPECIFIC_CHANNELS
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 eas_custom_get_lte_specific_channel_number(void)
{
    return (kal_uint8)NUM_OF_LTE_SPECIFIC_CHANNELS;
}
#endif

#if 0
#ifdef __CUSTOM_EAS_DYN_AFR_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*  __CUSTOM_EAS_DYN_AFR_SETTING__ */
#endif

