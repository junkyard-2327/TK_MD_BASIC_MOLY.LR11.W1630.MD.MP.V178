/********************************************************************************************
 *     LEGAL DISCLAIMER 
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES 
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED 
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS 
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED, 
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR 
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY 
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, 
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK 
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION 
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *     
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH 
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, 
 *     
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE 
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
 *     
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS 
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.  
 ************************************************************************************************/


/*******************************************************************************
 *
 * Filename:
 * ---------
 * unionTag_db.c
 *
 * Project:
 * --------
 * MOLY
 *
 * Description:
 * ------------
 * This file used for pre-processing to build unionTag DB
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * $Log$
 *
 * 05 28 2015 samuel.yang
 * [MOLY00116993] [TK6291] Modify codegen file to show xL1TST related PS logs on L1 core
 * .
 *
 * 12 31 2014 peng-an.chen
 * [MOLY00089125] [UMOLY] Universal Bin SW integration
 * Remove pcore unionTag for full load integration
 *
 * 09 05 2014 victor.chan
 * [MOLY00063930] [Cgen] UMOLY DEV Check-in
 * 	Fixed LWG full load codegen build error
 *
 * 01 21 2014 wcpuser_integrator
 * [MOLY00054475] SGLTE option rename
 * .
 *
 * 10 18 2013 danny.kuo
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * Integration change.
 *
 * 10 18 2013 wenxiu.zhao
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * .
 *
 * 10 18 2013 xiaogang.pan
 * [MOLY00041595] [MT6290E1][MMDS_DC] MMDC feature patch back to MOLY trunk
 * 	.
 *
 * 10 11 2013 xiaogang.pan
 * .
 *
 * 09 26 2013 danny.kuo
 * [MOLY00028800] [MMDC] PS Domain Switch Manager (PSDM) development
 * 	.
 *
 * 09 26 2013 xiaogang.pan
 * [MOLY00034698] mmdc duplicate module
 * 	.
 *
 * 09 26 2013 danny.kuo
 * [MOLY00028800] [MMDC] PS Domain Switch Manager (PSDM) development
 * 	.
 * 09 23 2013 xiaogang.pan
 * .
 *
 * 08 06 2013 stanleyhy.chen
 * [MOLY00032633] 4G Nbr Cell Info
 * Move unionTag related setting to lte_sec domain
 *
 * 08 06 2013 stanleyhy.chen
 * [MOLY00032633] 4G Nbr Cell Info
 * 4G Nbr Cell Info in OA Domain
 *
 * 03 18 2013 jerry.chang
 * [MOLY00009186] [SIBE/USIME/DBME] Multi-Mode CBr merge to MOLY
 * .
 *
 * 03 18 2013 yenchih.yang
 * [MOLY00009186] [SIBE/USIME/DBME] Multi-Mode CBr merge to MOLY
 * .
 *
 * 01 29 2013 ken.liu
 * [MOLY00009212] LTE Multimode merge back to MOLY
 * add log header.
 *
 *==============================================================================
 *  How to add a new unionTag script
 * 1. Put the unionTag script into the proper folder e.g: \dhl\database\unionTag
 *                                                  \dhl\database_classb\unionTag
 *                                                  \dhl\database_classb_umts\unionTag
 *                                                  \dhl\database_modis\unionTag
 * 2. #include <xxx.txt>. 
 *    Notably, you should use #include <xxx.txt> rather than "xxx.txt"
 *    If you have two different scripts with the same name in database\unionTag
 *    and database_modis\unionTag, please make sure you use #include <xxx.txt>.
 *    If you use #include "xxx.txt", Codegen will process \dhl\database\unionTag\xxx.txt
 *    instead of \dhl\database_modis\unionTag\xxx.txt. So you are suggested to use
 *    #include <xxx.txt> all the way.
 *******************************************************************************/
#ifdef _MODIS_ON_VC9_
#define __w64
#endif
 
#ifdef STDC_HEADERS
#undef STDC_HEADERS //it will include stdio.h
#endif

#include <FT_GL1TST_UnionTag.txt>
#include <FT_UL1TST_UnionTag.txt>
#include <FT_EL1TST_UnionTag.txt>
#include <FT_MML1TST_UnionTag.txt>

