/******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*******************************************************************************/

/******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   mrs_eas_capability.h
 *
 * Project:
 * --------------------------------------------------------
 *   Multimode
 *
 * Description:
 * --------------------------------------------------------
 *   The EAS capability stored in MRS context.
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * 03 07 2017 ivy.wang
 * [MOLY00232926] [RCM][MP5] HPUE develop
 * .
 *
 * 11 30 2016 ivy.wang
 * [MOLY00215885] [Rosa][UL64QAM][CA] Modify CA and UL64QAM due to new project Rosa w/ MT6750S
 * .
 *
 * 11 29 2016 ivy.wang
 * [MOLY00215885] [Rosa][UL64QAM][CA] Modify CA and UL64QAM due to new project Rosa w/ MT6750S
 * Modify CA,UL64QAM eFuse setting due to new project Rosa MT6750S.
 *
 * 10 18 2016 otto.liu
 * [MOLY00207643] [LR11][MP5] c2k supported band list feature
 *
 * 08 30 2016 ivy.wang
 * [MOLY00200197] New Feature UL64QAM on 6291
 * .
 *
 * 08 12 2016 morton.lin
 * [MOLY00190747] [6291][LTE BAND EXTENSION] Band 66 support - [PS] MRS EAS and COMMON
 * [MRS][COMMON & EAS] Internal definitions and code (1630MP)
 *
 * 08 12 2016 morton.lin
 * [MOLY00190737] [6291][LTE BAND EXTENSION] Band 66 support - [PS] MRS/SCSI interface
 * [MRS COMMON & EAS][SCSI] Interface and common definitions (1630MP)
 *
 * 07 25 2016 morton.lin
 * [MOLY00191172] [6291][MP3][Olympus E2] Hardware Segment Code feature support
 * 	
 * 	[MP5][KIBO+] Add Segment Code handling
 *
 * 05 12 2016 morton.lin
 * [MOLY00178939] [MT6797L]modem,md1:(MCU_L1CORE)  [ASSERT] file:l1core/modem/el1/el1d/src/common/ldsp_err_chk_cm.c line:115
 * MT6797 eFuse setting correction (W1603.MP)
 *
 * 03 04 2016 morton.lin
 * [MOLY00167381] [Olympus][E1][MRS] Add eFuse setting for MD SW usage
 * [MRS] Add Olympus eFuse setting
 *
 * 02 05 2016 morton.lin
 * [MOLY00164497] [Top1][XSIX-2812][X6][Pre-?ï¿½ï¿½?][ç³»ï¿½?]æµ‹ï¿½??ï¿½ï¿½??ï¿½å·¥ç¨‹æ¨¡å¼?ï¿?bandï¼Œï¿½??ï¿½ï¿½??ï¿½ï¿½?ä¸?ï¿??ï¿½ï¿½?å¹¶ï¿½?modem?ï¿½ï¿½??ï¿½å?¯ï?ï¿?é¡»ï¿½??ï¿½åˆ·?ï¿½ï¿½??ï¿½ä»¥?ï¿½ï¿½?
 * [MRS] Add new callback function to let L4/EM user set/get AS BAND setting which is not taking Duplex Mode into account (W1603MP)
 *
 * 01 11 2016 morton.lin
 * [MOLY00142643] [MT6291][MT6755][ERRC] MOLY code sync
 * [MRS] PLMN ID LIST interface change
 *
 * 01 08 2016 shin.chen
 * [MOLY00153524] [6291] Vivo BlackList feature
 *
 * 12 23 2015 nicky.chou
 * [MOLY00154210] [MT6755][E2][GCF][Anritsu][4G][FDD][MP3][17.4.11.2][eMBMS][E01-E03] Fail on this case
 * .
 *
 * 12 22 2015 morton.lin
 * [MOLY00153975] [MT6755][L+W][Overnight][FDD][HK][LAT2] CU SIM can not camp on 4G NW in 234G mode, but LTE only can  camp on 4G
 * [MRS] Reduce LTE support bands for legacy network interoperability issue (merge back)
 *
 * 12 02 2015 sabrina.hsu
 * [MOLY00151252] World Mode ID & Support Band collision check
 * WMID band check.
 *
 * 12 01 2015 chih-chien.lin
 * [MOLY00150744] [LTE-A] Limit device operation on partial band
 * add function to judge whether in partial band and indicate the unsupported range
 *
 * 11 04 2015 ivy.wang
 * [MOLY00144296] modem license check in MRS
 * .
 *
 * 10 14 2015 ivy.wang
 * [MOLY00144381] [ERRC] VzW feature sync to LR11
 * dynamic band.
 *
 * 10 14 2015 ivy.wang
 * [MOLY00144381] [ERRC] VzW feature sync to LR11
 * .
 *
 * 10 12 2015 chi-chung.lin
 * [MOLY00144274] [MOLY->UMOLY][MOLY00136067][SBM]New Feature : Partial Channel Bandwidth supported.
 * 	.
 *
 * 10 07 2015 ivy.wang
 * [MOLY00144381] [ERRC] VzW feature sync to LR11
 * dynamic band (fix build error).
 *
 * 10 07 2015 ivy.wang
 * [MOLY00144407] [VzW][ERRC] new SIB14 in EVTH tbl
 * dynamic band.
 *
 * 10 07 2015 ivy.wang
 * [MOLY00144381] [ERRC] VzW feature sync to LR11
 * dynamic band.
 *
 * 08 04 2015 chi-chung.lin
 * [MOLY00133208] [RCM] Jade efuse code revision
 * 	.
 *
 * 07 27 2015 chih-chien.lin
 * [MOLY00132591][ERRC][CEL]CMCC B38/41 CA issue [CEL] consider freq_pri
 *
 * 06 01 2015 henry.lai
 * [MOLY00092508] [MT6291][LTE-C2K] AS Inter RAT feature
 * .
 *
 * 04 16 2015 doug.shih
 * [MOLY00091463] [MT6291] ERRC RCM/MRS development
 * 1. [CR1515] Network-requested CA Band Combination Capability Signalling
 * 2. [CR1535] Introduction of UE capability for eMBMS reception on SCell and Non-Serving Cell
 * 3. C2K FGI/Capability IE refinement
 * (OA domain).
 *
 * 03 16 2015 justin.li
 * [MOLY00098827] [MT6291][ERRC-CEL] Extension EARFCN feature
 * .
 *
 * 03 09 2015 ivy.wang
 * [MOLY00097236] [TK6291 FPGA][pre-1stCallTest][UMOLY][4G] Assert @ lcel_paging.c #910
 * [MOLY00091983] [VzW][6.2.16.1] FEMTO SYSTEM SELECTION(VZ_REQ_LTEDATA_6820)
 *
 * 02 10 2015 doug.shih
 * [MOLY00091463] [MT6291] ERRC RCM/MRS development
 * Extend encoded EUTRAN UE capability buffer size.
 *
 * 11 14 2014 henry.lai
 * [MOLY00079072] [MT6291] Change EARFCN from kal_uint16 to kal_uint32 for CEL part
 * 	.
 *
 * 11 13 2014 doug.shih
 * [MOLY00068710] [MT6291_DEV] Sync MOLY to MT6291_DEV
 * Merge MT6291_DEV code to UMOLY trunk.
 *
 * 08 01 2014 menghau.wu
 * [MOLY00073987] [MT6290E2][MRS] Create mrs_eas_max_band_cap_for_user() to L4C for user friendly UI
 * Create mrs_eas_max_band_cap_for_user() to L4C for user friendly UI
 *
 * 01 21 2014 wcpuser_integrator
 * [MOLY00054475] SGLTE option rename
 * .
 *
 * 11 13 2013 adeline.chang
 * [MOLY00046027] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * .
 *
 * 10 21 2013 hong-yuan.yang
 * [MOLY00040050] [MultiMode] Dynamic band selection
 * .
 *
 * 09 26 2013 adeline.chang
 * [MOLY00038974] [LTE Gemini] Add SIM index as input parameter for two MRS API
 * .
 *
 * 08 23 2013 adeline.chang
 * [MOLY00034813] [MT6290] DL/UL EARFCN check using DL/UL BW
 * .
 *
 * 07 12 2013 hong-yuan.yang
 * [MOLY00028770] add eas fdd/tdd judge api in MRS
 * .modify enum
 *
 * 07 05 2013 hong-yuan.yang
 * [MOLY00028770] add eas fdd/tdd judge api in MRS
 * .add fdd/tdd jdg api
 *
 * 07 05 2013 hong-yuan.yang
 * [MOLY00028770] add eas fdd/tdd judge api in MRS
 * .add eas fdd/tdd judge api in MRS
 *
 * 05 13 2013 shih-chieh.liao
 * [MOLY00022028] LTE MM.IT errc merge to MOLY
 * merge mrs
 *
 * 01 22 2013 david.niu
 * [MOLY00009205] [MRS] Code checked-in for MOLY branch
 * .
 *
 *****************************************************************************/

#ifndef _MRS_EAS_CAPABILITY_H
#define _MRS_EAS_CAPABILITY_H

#include "mrs_as_inter_core_def.h"
#include "mrs_as_enums.h"
#include "mrs_as_struct.h"
#include "reg_base.h"
#include "global_type.h"

/*****************************************************************************
 * Macros Without Parameters
 *****************************************************************************/

/* Pcore EFUSE reading */
typedef volatile unsigned long* APBADDR32;

#define HW_READ(ptr)                             (*(ptr))
#define BitFieldGet(_src, _strtBit, _maskBit)    ((_src >> _strtBit) & _maskBit)
#define MASK_1_BIT            0x0001

#if defined(TK6291) && defined(__FPGA__)
/**
 * For temporary FPGA EFUSE emulation:
 *   Due to FPGA cannot have real EFUSE bit to return HW capability,
 *   we simply read a fixed register address and check if its value equals to FPGA_4G_FULL_VALUE,
 *   then we return LTE_FDD_DISABLE/LTE_TDD_DISABLE/LTE_CA_DISABLE accordingly.
 */
#define FPGA_EFUSE_base       0x8000001C
#define FPGA_4G_FULL_VALUE    0x05000000
#define LTE_EFUSE_OPTION      ((APBADDR32)(FPGA_EFUSE_base))

#elif defined(TK6291) && defined(TK6291_S00)
/**
 * For TK6291 EFUSE:
 *   bit 13 - LTE_FDD_DISABLE 
 *   bit 14 - LTE_TDD_DISABLE
 *   bit 15 - LTE_CA_DISABLE
 */
#define LTE_FDD_DISABLE_BIT       13
#define LTE_TDD_DISABLE_BIT       14
#define LTE_CA_DISABLE_BIT        15
#define LTE_EFUSE_OFFSET        0x44  /* TK6291 LTE EFUSE offset */
#define LTE_EFUSE_OPTION      ((APBADDR32)(EFUSE_base + LTE_EFUSE_OFFSET))

#elif defined(MT6755) || defined(MT6757) || defined(MT6757P) || defined(MT6750S)
/**
 * For MT6755/MT6757 EFUSE:
 *   bit 0 - LTE_FDD_DISABLE 
 *   bit 1 - LTE_TDD_DISABLE
 *   bit 2 - LTE_CA_DISABLE
 *   bit11- LTE_UL64QAM_DISABLE
 */
#define LTE_FDD_DISABLE_BIT       0
#define LTE_TDD_DISABLE_BIT       1
#define LTE_CA_DISABLE_BIT        2
#if defined(MT6757) || defined(MT6757P)
#define LTE_UL64QAM_ENABLE_BIT      11
#endif
#define LTE_EFUSE_OFFSET        0x44  /* MT6755/MT6757 LTE EFUSE offset */
#define LTE_EFUSE_OPTION      ((APBADDR32)(EFUSE_base + LTE_EFUSE_OFFSET))
#if defined(MT6755) || defined(MT6750S)
/* 20161129 confirmed w/ Rich Chen, WX Lin, Allen Lu, UL64QAM for Jade/Jade-/Rosa is on 0x10206048[30] 
 * 0x10206048[30] = 1¡¦b1 : enable 64QAM
 * 0x10206048[30] = 1¡¦b0 : disable 64QAM */
#define LTE_EFUSE_OFFSET_2        0x48  /* MT6755/MT6750 LTE EFUSE offset */
#define LTE_EFUSE_OPTION_2      ((APBADDR32)(EFUSE_base + LTE_EFUSE_OFFSET_2))
#define LTE_UL64QAM_ENABLE_BIT      30
#endif
#if defined(MT6757) || defined(MT6757P)
/**
 * For MT6757 E2 or KIBO/KIBO+ (MT6757P) Segment Code:
 *   bit 0~2: T / M / Normal (CPU clock rate) -> All 'Normal' (20160720)
 *   bit   3: 6M C2K DISABLE
 *   bit   4: LTE CA DISABLE
 */
#define SEG_CODE_6M_C2K_DISABLE_BIT  3
#define SEG_CODE_CA_DISABLE_BIT      4
#define SEG_CODE_OFFSET           0x54
#define LTE_SEG_CODE_OPTION       ((APBADDR32)(EFUSE_base + SEG_CODE_OFFSET))
#endif

/* 20161129 confirmed w/ Rich Chen, WX Lin, Allen Lu, UL64QAM for Jade/Jade-/Rosa is on 0x10206048[30] 
 * the segment code is no longer used for UL64QAM */
#if 0 
#if defined(MT6755)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#elif defined(MT6797)
/**
 * For MT6797 EFUSE:
 *   bit 5 - LTE_FDD_DISABLE 
 *   bit 6 - LTE_TDD_DISABLE
 *   bit 7 - LTE_CA_DISABLE
 */
#define LTE_FDD_DISABLE_BIT       5
#define LTE_TDD_DISABLE_BIT       6
#define LTE_CA_DISABLE_BIT        7
#define LTE_EFUSE_OFFSET        0x4C  /* MT6797 LTE EFUSE offset */
#define LTE_EFUSE_OPTION      ((APBADDR32)(EFUSE_base + LTE_EFUSE_OFFSET))

#else
    // should add code for new chip
    #error "please check chip version and notify RCM owner to add new efuse code"
#endif

#if defined(__LTE_R11__)
#define LTE_CA_DEFAULT_VALUE  KAL_TRUE
#define LTE_UL64QAM_DEFAULT_VALUE  KAL_TRUE
#else
#define LTE_CA_DEFAULT_VALUE  KAL_FALSE
#define LTE_UL64QAM_DEFAULT_VALUE  KAL_FALSE
#endif

/* Original: 2; After B66 support: 8
 * (This value should be aligned with EL1D_RF_GET_BAND_SUPPORT_MASK() interface 
 *  and the LTE Band number in the NVRAM_EF_AS_BAND_SETTING_LID)
 */
#define LTE_BAND_MASK_WORD_COUNT    8

/*****************************************************************************
 * Macros With Parameters
 *****************************************************************************/


/*****************************************************************************
 * Enums without tags
 *****************************************************************************/
/* Workaround for MT6291 FGPA Digital IQ */
/* #if defined(TK6291) && defined(__RF_BYPASS__) */
#define EAS_LOCK_MULTI_FREQ_NUM_MAX      4
#define EAS_LOCK_MULTI_FREQ_NUM_EMPTY    0

/*****************************************************************************
 * Type Definitions
 *****************************************************************************/
typedef struct {
    kal_uint16   band; 
    EARFCN       dl_lower_earfcn;
    EARFCN       dl_upper_earfcn;
    EARFCN       ul_lower_earfcn;
    EARFCN       ul_upper_earfcn;
} eas_partial_band_list_struct;
	
typedef struct {
    kal_uint8	valid_num;
    eas_partial_band_list_struct  band_list[EAS_EF_ERRC_PARTIAL_BAND_NUM]; 
} eas_partial_band_inf_struct;

typedef struct {
    EARFCN       earfcn; 
    kal_uint16   lte_band_num;
    kal_uint16  *lte_band_list_ptr;
}earfcn_list_struct;


/* Workaround for MT6291 FGPA Digital IQ */
/* #if defined(TK6291) && defined(__RF_BYPASS__) */
typedef struct {
    kal_uint8     lock_multi_freq_num;
    kal_uint16    lock_multi_freq[EAS_LOCK_MULTI_FREQ_NUM_MAX];
} eas_lock_multi_freq_capa_struct;


//#ifdef __BAND_EXTENSION_SUPPORT__
typedef struct {
    kal_uint8  lte_band_list[SIZE_LTE_BAND_MASK_TABLE_EXTENDED];
} mrs_lte_band_list_struct;
//#endif


#ifdef __BAND_EXTENSION_SUPPORT__
typedef struct {
#ifdef __UNIT_TEST__
    kal_uint32  eutra_capa_length; 
    kal_uint8   eutra_capa[EUTRAN_CAPA_MAX_LEN];
#endif /* __UNIT_TEST__ */
    kal_uint8   eea_support;/*MSB: EEA0, EEA1,.....EEA7*/
    kal_uint8   eia_support;/*MSB: EIA0, EIA1,.....EIA7*/
    kal_uint8   eas_power_class;
//#ifdef __SGLTE__
    kal_bool is_band_39_ori_support;
//#endif /* __SGLTE__ */
    kal_uint8   is_band_ori_support[SIZE_LTE_BAND_MASK_TABLE_EXTENDED];
/* Workaround for MT6291 FGPA Digital IQ */
/* #if defined(TK6291) && defined(__RF_BYPASS__) */
    eas_lock_multi_freq_capa_struct  lock_multi_dl_freq_capa;
	kal_uint8	data[3]; // for LTE_CAP write back to NVRAM
	kal_uint8	op_femtocell_system_selection;	/* VzW : 6.2.16.1	FEMTOCELL SYSTEM SELECTION */
    kal_uint8   disable_bw_bmp[LTE_BAND_NUM_EXTENDED];
    eas_partial_band_inf_struct partial_band_inf;
    kal_uint8   nvram_lte_band[SIZE_LTE_BAND_MASK_TABLE_EXTENDED];
} eas_capability_context_struct;
#else
typedef struct {
#ifdef __UNIT_TEST__
    kal_uint32  eutra_capa_length; 
    kal_uint8   eutra_capa[EUTRAN_CAPA_MAX_LEN];
#endif /* __UNIT_TEST__ */
    kal_uint8   eea_support;/*MSB: EEA0, EEA1,.....EEA7*/
    kal_uint8   eia_support;/*MSB: EIA0, EIA1,.....EIA7*/
    kal_uint8   eas_power_class;
//#ifdef __SGLTE__
    kal_bool is_band_39_ori_support;
//#endif /* __SGLTE__ */
    kal_uint8   is_band_ori_support[SIZE_LTE_BAND];
/* Workaround for MT6291 FGPA Digital IQ */
/* #if defined(TK6291) && defined(__RF_BYPASS__) */
    eas_lock_multi_freq_capa_struct  lock_multi_dl_freq_capa;
	kal_uint8	data[3]; // for LTE_CAP write back to NVRAM
	kal_uint8	op_femtocell_system_selection;	/* VwZ : 6.2.16.1	FEMTOCELL SYSTEM SELECTION */
    kal_uint8   disable_bw_bmp[LTE_BAND_NUM];
    eas_partial_band_inf_struct partial_band_inf;
    kal_uint8   nvram_lte_band[SIZE_LTE_BAND]; 
} eas_capability_context_struct;
#endif  /* END of #ifdef __BAND_EXTENSION_SUPPORT__ */

typedef enum {
  EAS_BAND_PHY_FREQ_MIN,
  EAS_BAND_PHY_FREQ_MAX,  
  EAS_BAND_EARFCN_MIN,  
  EAS_BAND_EARFCN_MAX,
  EAS_BAND_EARFCN_FREQ_INFO_NUM
} eas_band_earfcn_freq_info_enum;

typedef enum {
  EAS_CELL_MODE_UNKNOWN,
  EAS_CELL_MODE_FDD,
  EAS_CELL_MODE_TDD
} eas_cell_mode_enum;

typedef enum {
  EAS_COUNTRY_JAPAN
} eas_country_enum;

typedef enum {
  EAS_CAT_4,
  EAS_CAT_6,
  EAS_CAT_8
} eas_category_enum;

#ifdef UNIT_TEST
typedef struct {
    kal_uint32 band_mask_word_count;
    kal_uint32 band_mask[LTE_BAND_MASK_WORD_COUNT];
} eas_rf_supported_bands_struct;
#endif /* UNIT_TEST */

/*****************************************************************************
 * Declarations Of Exported Globals
 *****************************************************************************/

/* mrs_eas_is_lte_fdd_exist: read efuse status to check whether LTE FDD is supported in 6291 */
kal_bool mrs_eas_is_lte_fdd_exist(void);

/* mrs_eas_is_lte_tdd_exist: read efuse status to check whether LTE TDD is supported in 6291 */
kal_bool mrs_eas_is_lte_tdd_exist(void);

/* mrs_eas_is_lte_ca_enable: read efuse status to check whether LTE CA is supported in 6291 */
kal_bool mrs_eas_is_lte_ca_enable(void);

/* mrs_eas_is_lte_ul64qam_enable: read efuse status to check whether LTE UL64QAM is supported in 6291 */
kal_bool mrs_eas_is_lte_ul64qam_enable(void);

eas_category_enum mrs_eas_ue_category(MRS_SIM_INDEX sim_index);

kal_bool mrs_eas_is_supported_band(MRS_SIM_INDEX sim_index,
                                           kal_uint16    lte_band);

kal_bool mrs_eas_is_rf_supported_band(kal_uint16 lte_band);

kal_bool mrs_eas_get_unsupported_range(MRS_SIM_INDEX sim_index, kal_uint16 lte_band, EARFCN* l1, EARFCN* r1, EARFCN* l2, EARFCN* r2);

void mrs_eas_convert_dl_earfcn(EARFCN        dl_earfcn,
                               kal_uint16   *lte_band_ptr,
                               kal_uint32   *phy_freq_ptr);

void mrs_eas_convert_ul_earfcn(EARFCN        ul_earfcn,
                               kal_uint16   *lte_band_ptr,
                               kal_uint32   *phy_freq_ptr);


kal_bool mrs_eas_is_supported_dl_earfcn(MRS_SIM_INDEX sim_index,
                                        EARFCN        dl_earfcn);

kal_bool mrs_eas_is_supported_ul_earfcn(MRS_SIM_INDEX sim_index, 
                                        EARFCN        ul_earfcn);

kal_bool mrs_eas_is_dl_earfcn_overlap(EARFCN  dl_earfcn1,
                                      EARFCN  dl_earfcn2);

kal_bool mrs_eas_is_ul_earfcn_overlap(EARFCN  ul_earfcn1,
                                      EARFCN  ul_earfcn2);

kal_bool mrs_eas_partical_band_range_chk(kal_uint16  lte_band,
                                         EARFCN      dl_lower_earfcn,
                                         EARFCN      dl_upper_earfcn,
                                         EARFCN      ul_lower_earfcn,
                                         EARFCN      ul_upper_earfcn);


kal_uint32 mrs_eas_convert_dl_earfcn_to_freq(EARFCN  dl_earfcn);


EARFCN mrs_eas_convert_to_best_dl_earfcn_mfbi(MRS_SIM_INDEX sim_index,
                                              EARFCN        dl_earfcn,
                                              kal_uint16    band_indicator,
                                              kal_uint8     lte_band_num,
                                              kal_uint16   *lte_band_list_ptr,
                                              eas_bandwidth_enum band_width,
                                              kal_bool      allow_disabled_bands);

EARFCN mrs_eas_convert_to_best_dl_earfcn_mfbi_freq_pri(MRS_SIM_INDEX sim_index,
                                                       EARFCN        dl_earfcn,
                                                       kal_uint16    band_indicator,
                                                       kal_uint8     lte_band_num,
                                                       kal_uint16   *lte_band_list_ptr,
                                                       kal_bool      freq_pri,
                                                       eas_bandwidth_enum band_width,
                                                       kal_bool      allow_disabled_bands);

kal_uint32 mrs_eas_convert_dl_earfcn_to_target_band(EARFCN        dl_earfcn,
                                                    kal_uint16    target_band);

kal_uint32 mrs_eas_convert_ul_earfcn_to_target_band(EARFCN        ul_earfcn,
                                                    kal_uint16    target_band);

kal_bool mrs_eas_is_ca_supplemental_dl_earfcn(EARFCN  dl_earfcn);

kal_bool mrs_eas_is_ca_supplemental_dl_band(kal_uint16  lte_band);

kal_uint32 mrs_eas_multi_band_conversion(MRS_SIM_INDEX sim_index,
                                         EARFCN        earfcn,
                                         kal_uint16    lte_band_num,
                                         kal_uint16   *lte_band_list_ptr);

kal_uint32 mrs_eas_multi_band_conversion_rej_redirection(MRS_SIM_INDEX       sim_index,
                                                         EARFCN              redirection_earfcn,
                                                         kal_uint8           freq_num,
                                                         earfcn_list_struct *earfcn_list_ptr);


kal_bool mrs_eas_is_lte_fdd_support(MRS_SIM_INDEX sim_index);

kal_bool mrs_eas_is_lte_tdd_support(MRS_SIM_INDEX sim_index);

kal_uint8 mrs_eas_get_eea_support(MRS_SIM_INDEX sim_index);

kal_uint8 mrs_eas_get_eia_support(MRS_SIM_INDEX sim_index);

#ifdef __HPUE_FEATURE_SUPPORT__
kal_uint8 mrs_eas_get_powerclass(MRS_SIM_INDEX sim_index, kal_uint16 lte_band);

kal_bool mrs_eas_HPUE_HW_support(MRS_SIM_INDEX sim_index);
#else
kal_uint8 mrs_eas_get_powerclass(MRS_SIM_INDEX sim_index);
#endif

kal_uint8 mrs_eas_get_femtocell_system_selection(MRS_SIM_INDEX sim_index);

void mrs_eas_set_femtocell_system_selection(MRS_SIM_INDEX sim_index, kal_uint8 fss);

void mrs_eas_read_nvram_cnf_handler(kal_uint16 nvram_file_id, kal_uint8* data, kal_uint16 len);

#ifdef __UNIT_TEST__
void mrs_eas_set_ue_eutra_capability(MRS_SIM_INDEX sim_index, kal_uint8 *p_ue_eutra_cap, kal_uint32 cap_length);
#endif /* __UNIT_TEST__ */

kal_uint32 mrs_eas_get_ue_eutra_capability(MRS_SIM_INDEX sim_index, kal_uint8 **pp_ue_eutra_capa);

kal_uint32 mrs_eas_get_ue_eutra_capability_by_plmn(MRS_SIM_INDEX sim_index, kal_uint8 **pp_ue_eutra_capa, mrs_plmn_id_list *p_plmn_id_list);

eas_cell_mode_enum mrs_eas_jdg_cell_mode_by_band(kal_uint16 lte_band);

eas_cell_mode_enum mrs_eas_jdg_cell_mode_by_earfcn(EARFCN earfcn);

kal_bool mrs_eas_is_supported_dl_earfcn_with_bw_check(MRS_SIM_INDEX      sim_index,
                                                      EARFCN             dl_earfcn, 
                                                      eas_bandwidth_enum band_width,
                                                      kal_bool           allow_disabled_bands);

kal_bool mrs_eas_is_supported_ul_earfcn_with_bw_check(MRS_SIM_INDEX      sim_index,
                                                      EARFCN             ul_earfcn, 
                                                      eas_bandwidth_enum band_width);

kal_bool mrs_eas_is_supported_dl_bandwidth(MRS_SIM_INDEX sim_index,
                                           kal_uint16    lte_band, 
                                           eas_bandwidth_enum band_width);

kal_bool mrs_eas_band_setting_update(MRS_SIM_INDEX sim_index, kal_uint8* lte_band_bmp);
//#ifdef __BAND_EXTENSION_SUPPORT__
kal_bool mrs_eas_band_setting_update_without_duplex_mode(MRS_SIM_INDEX sim_index, kal_uint8* lte_band_bmp);
//#endif

void mrs_eas_max_band_cap_for_user(kal_uint8  *lte_band);
//#ifdef __BAND_EXTENSION_SUPPORT__
void mrs_eas_max_band_cap_for_user_extended(mrs_lte_band_list_struct *lte_band);
//#endif

//#ifdef __SGLTE__
kal_bool mrs_eas_is_supported_band_in_nvram_stored(MRS_SIM_INDEX sim_index,
                                                   kal_uint16    lte_band);
kal_bool mrs_eas_is_supported_earfcn_in_nvram_stored(MRS_SIM_INDEX sim_index,
                                                     EARFCN  dl_earfcn);
//#endif /* __SGLTE__ */

/* Workaround for MT6291 FGPA Digital IQ */
#if defined(TK6291) && defined(__RF_BYPASS__)
void mrs_eas_set_lock_multi_freq_capa(eas_lock_multi_freq_capa_struct *lock_multi_freq_capa);
#endif  /* #if defined(TK6291) && defined(__RF_BYPASS__) */

kal_bool mrs_eas_is_supported_c2k_band(kal_uint8 band);

void mrs_eas_band_control_func(kal_uint16 lte_band, eas_band_control_enum band_ctrl_info);

kal_bool mrs_eas_is_mcc_match_country(eas_country_enum country,kal_uint8 mcc1,kal_uint8 mcc2,kal_uint8 mcc3);

void mrs_eas_add_remove_band(kal_uint16 lte_band, eas_band_control_enum band_ctrl_info);

#ifdef UNIT_TEST
void mrs_eas_set_rf_supported_band_mask(
    kal_uint32 band_mask_word_count, kal_uint32* p_band_mask);
#endif /* UNIT_TEST */

void mrs_eas_get_context_nvram_lte_band(kal_uint8* p_lte_band_mask, MRS_SIM_INDEX sim_index);

void mrs_eas_set_context_nvram_lte_band(kal_uint8* p_lte_band_mask, MRS_SIM_INDEX sim_index);

void mrs_eas_get_em_lte_support_band(MRS_SIM_INDEX sim_index, kal_uint8 *p_lte_support_band);

kal_uint8 mrs_eas_WMID_lte_band_check(MRS_SIM_INDEX sim_index);

void mrs_eas_add_black_cell_list_notification(void);

void mrs_eas_clear_black_cell_list_notification(void);

void mrs_eas_retrieve_c2k_supported_band_list(kal_uint32 *band_list);

void mrs_eas_compose_c2k_supported_band_list(kal_uint32 c2k_band_support);

#endif /* _MRS_EAS_CAPABILITY_H */

