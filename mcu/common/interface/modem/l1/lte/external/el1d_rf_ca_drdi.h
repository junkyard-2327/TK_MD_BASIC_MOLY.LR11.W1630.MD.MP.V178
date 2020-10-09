/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   el1_rf_ca.h
 *
 * Project:
 * --------
 *   MT6176 RF (Orion+)
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *
 *
 *******************************************************************************/

/*===============================================================================================*/

//#ifndef __EL1D_RF_CA_DRDI_H__
//#define __EL1D_RF_CA_DRDI_H__

/*******************************************************************************
 * #include
 ******************************************************************************/
#include "el1d_rf_ca_undef.h"

/*******************************************************************************
 * #define
 ******************************************************************************/
/*------------------*/
/* Macro Definition */
/*------------------*/
#define LTE_ROUTE_OF_CACFG_IND_SET(i,c,x,s) i##_CC##c##_##x##_MIPI_TBL_IDX_##s
#define LTE_ROUTE_OF_SET(i,c,x,s)           LTE_ROUTE_OF_CACFG_IND_SET(i,c,x,s)

#define CONSTRUCT_ROUTE_SET(r)              (((1<<((r>>4)&0xF))<<16)|(1<<(r&0xF)))
#define ROUTE_GROUP_CHECK_SET(g,e)          ((e>>16)&(1<<g))
#define ROUTE_MAP_ROUTE_SET(g,r)            (ROUTE_GROUP_CHECK_SET(g,CONSTRUCT_ROUTE_SET(r))?(CONSTRUCT_ROUTE_SET(r)&0xFFFF):0)
#define ROUTE_MAP_IND_SET(g,i,x,s)          (ROUTE_MAP_ROUTE_SET(g,LTE_ROUTE_OF_SET(i,0,x,s)) | ROUTE_MAP_ROUTE_SET(g,LTE_ROUTE_OF_SET(i,1,x,s)))
#define ROUTE_MAP_GROUP_SET_TEMP(g,x,s)     (ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_00_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_01_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_02_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_03_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_04_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_05_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_06_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_07_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_08_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_09_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_10_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_11_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_12_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_13_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_14_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_15_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_16_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_17_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_18_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_19_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_20_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_21_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_22_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_23_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_24_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_25_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_26_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_27_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_28_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_29_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_30_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_31_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_32_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_33_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_34_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_35_##s,x,s) | \
                                             ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_36_##s,x,s) | ROUTE_MAP_IND_SET(g,LTE_CACFG_IND_37_##s,x,s) )
#define ROUTE_MAP_GROUP_SET(g,x,s)           ROUTE_MAP_GROUP_SET_TEMP(g,x,s)

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*------------------------*/
/* MIPI RX Route Settings */
/*------------------------*/
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<5)
/*CA Band*/ #define  __MIPI_RX_ROUTE21__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<6)
/*CA Band*/ #define  __MIPI_RX_ROUTE22__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<7)
/*CA Band*/ #define  __MIPI_RX_ROUTE23__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<8)
/*CA Band*/ #define  __MIPI_RX_ROUTE24__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<9)
/*CA Band*/ #define  __MIPI_RX_ROUTE25__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<10)
/*CA Band*/ #define  __MIPI_RX_ROUTE26__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<11)
/*CA Band*/ #define  __MIPI_RX_ROUTE27__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<12)
/*CA Band*/ #define  __MIPI_RX_ROUTE28__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<13)
/*CA Band*/ #define  __MIPI_RX_ROUTE29__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<14)
/*CA Band*/ #define  __MIPI_RX_ROUTE30__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(1,RX,SetNumber) & (1<<15)
/*CA Band*/ #define  __MIPI_RX_ROUTE31__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<0)
/*CA Band*/ #define  __MIPI_RX_ROUTE32__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<1)
/*CA Band*/ #define  __MIPI_RX_ROUTE33__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<2)
/*CA Band*/ #define  __MIPI_RX_ROUTE34__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<3)
/*CA Band*/ #define  __MIPI_RX_ROUTE35__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<4)
/*CA Band*/ #define  __MIPI_RX_ROUTE36__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<5)
/*CA Band*/ #define  __MIPI_RX_ROUTE37__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<6)
/*CA Band*/ #define  __MIPI_RX_ROUTE38__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<7)
/*CA Band*/ #define  __MIPI_RX_ROUTE39__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<8)
/*CA Band*/ #define  __MIPI_RX_ROUTE40__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<9)
/*CA Band*/ #define  __MIPI_RX_ROUTE41__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<10)
/*CA Band*/ #define  __MIPI_RX_ROUTE42__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<11)
/*CA Band*/ #define  __MIPI_RX_ROUTE43__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<12)
/*CA Band*/ #define  __MIPI_RX_ROUTE44__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<13)
/*CA Band*/ #define  __MIPI_RX_ROUTE45__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<14)
/*CA Band*/ #define  __MIPI_RX_ROUTE46__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(2,RX,SetNumber) & (1<<15)
/*CA Band*/ #define  __MIPI_RX_ROUTE47__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<0)
/*CA Band*/ #define  __MIPI_RX_ROUTE48__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<1)
/*CA Band*/ #define  __MIPI_RX_ROUTE49__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<2)
/*CA Band*/ #define  __MIPI_RX_ROUTE50__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<3)
/*CA Band*/ #define  __MIPI_RX_ROUTE51__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<4)
/*CA Band*/ #define  __MIPI_RX_ROUTE52__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<5)
/*CA Band*/ #define  __MIPI_RX_ROUTE53__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<6)
/*CA Band*/ #define  __MIPI_RX_ROUTE54__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<7)
/*CA Band*/ #define  __MIPI_RX_ROUTE55__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<8)
/*CA Band*/ #define  __MIPI_RX_ROUTE56__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<9)
/*CA Band*/ #define  __MIPI_RX_ROUTE57__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<10)
/*CA Band*/ #define  __MIPI_RX_ROUTE58__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<11)
/*CA Band*/ #define  __MIPI_RX_ROUTE59__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<12)
/*CA Band*/ #define  __MIPI_RX_ROUTE60__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<13)
/*CA Band*/ #define  __MIPI_RX_ROUTE61__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<14)
/*CA Band*/ #define  __MIPI_RX_ROUTE62__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(3,RX,SetNumber) & (1<<15)
/*CA Band*/ #define  __MIPI_RX_ROUTE63__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<0)
/*CA Band*/ #define  __MIPI_RX_ROUTE64__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<1)
/*CA Band*/ #define  __MIPI_RX_ROUTE65__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<2)
/*CA Band*/ #define  __MIPI_RX_ROUTE66__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<3)
/*CA Band*/ #define  __MIPI_RX_ROUTE67__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<4)
/*CA Band*/ #define  __MIPI_RX_ROUTE68__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<5)
/*CA Band*/ #define  __MIPI_RX_ROUTE69__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<6)
/*CA Band*/ #define  __MIPI_RX_ROUTE70__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<7)
/*CA Band*/ #define  __MIPI_RX_ROUTE71__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<8)
/*CA Band*/ #define  __MIPI_RX_ROUTE72__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<9)
/*CA Band*/ #define  __MIPI_RX_ROUTE73__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<10)
/*CA Band*/ #define  __MIPI_RX_ROUTE74__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<11)
/*CA Band*/ #define  __MIPI_RX_ROUTE75__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<12)
/*CA Band*/ #define  __MIPI_RX_ROUTE76__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<13)
/*CA Band*/ #define  __MIPI_RX_ROUTE77__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<14)
/*CA Band*/ #define  __MIPI_RX_ROUTE78__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(4,RX,SetNumber) & (1<<15)
/*CA Band*/ #define  __MIPI_RX_ROUTE79__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<0)
/*CA Band*/ #define  __MIPI_RX_ROUTE80__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<1)
/*CA Band*/ #define  __MIPI_RX_ROUTE81__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<2)
/*CA Band*/ #define  __MIPI_RX_ROUTE82__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<3)
/*CA Band*/ #define  __MIPI_RX_ROUTE83__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<4)
/*CA Band*/ #define  __MIPI_RX_ROUTE84__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<5)
/*CA Band*/ #define  __MIPI_RX_ROUTE85__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<6)
/*CA Band*/ #define  __MIPI_RX_ROUTE86__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<7)
/*CA Band*/ #define  __MIPI_RX_ROUTE87__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<8)
/*CA Band*/ #define  __MIPI_RX_ROUTE88__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<9)
/*CA Band*/ #define  __MIPI_RX_ROUTE89__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<10)
/*CA Band*/ #define  __MIPI_RX_ROUTE90__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<11)
/*CA Band*/ #define  __MIPI_RX_ROUTE91__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<12)
/*CA Band*/ #define  __MIPI_RX_ROUTE92__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<13)
/*CA Band*/ #define  __MIPI_RX_ROUTE93__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<14)
/*CA Band*/ #define  __MIPI_RX_ROUTE94__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(5,RX,SetNumber) & (1<<15)
/*CA Band*/ #define  __MIPI_RX_ROUTE95__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<0)
/*CA Band*/ #define  __MIPI_RX_ROUTE96__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<1)
/*CA Band*/ #define  __MIPI_RX_ROUTE97__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<2)
/*CA Band*/ #define  __MIPI_RX_ROUTE98__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<3)
/*CA Band*/ #define  __MIPI_RX_ROUTE99__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<4)
/*CA Band*/ #define  __MIPI_RX_ROUTE100__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<5)
/*CA Band*/ #define  __MIPI_RX_ROUTE101__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<6)
/*CA Band*/ #define  __MIPI_RX_ROUTE102__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<7)
/*CA Band*/ #define  __MIPI_RX_ROUTE103__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<8)
/*CA Band*/ #define  __MIPI_RX_ROUTE104__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<9)
/*CA Band*/ #define  __MIPI_RX_ROUTE105__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<10)
/*CA Band*/ #define  __MIPI_RX_ROUTE106__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<11)
/*CA Band*/ #define  __MIPI_RX_ROUTE107__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<12)
/*CA Band*/ #define  __MIPI_RX_ROUTE108__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<13)
/*CA Band*/ #define  __MIPI_RX_ROUTE109__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<14)
/*CA Band*/ #define  __MIPI_RX_ROUTE110__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(6,RX,SetNumber) & (1<<15)
/*CA Band*/ #define  __MIPI_RX_ROUTE111__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<0)
/*CA Band*/ #define  __MIPI_RX_ROUTE112__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<1)
/*CA Band*/ #define  __MIPI_RX_ROUTE113__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<2)
/*CA Band*/ #define  __MIPI_RX_ROUTE114__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<3)
/*CA Band*/ #define  __MIPI_RX_ROUTE115__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<4)
/*CA Band*/ #define  __MIPI_RX_ROUTE116__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<5)
/*CA Band*/ #define  __MIPI_RX_ROUTE117__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<6)
/*CA Band*/ #define  __MIPI_RX_ROUTE118__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<7)
/*CA Band*/ #define  __MIPI_RX_ROUTE119__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<8)
/*CA Band*/ #define  __MIPI_RX_ROUTE120__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<9)
/*CA Band*/ #define  __MIPI_RX_ROUTE121__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<10)
/*CA Band*/ #define  __MIPI_RX_ROUTE122__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<11)
/*CA Band*/ #define  __MIPI_RX_ROUTE123__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<12)
/*CA Band*/ #define  __MIPI_RX_ROUTE124__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<13)
/*CA Band*/ #define  __MIPI_RX_ROUTE125__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<14)
/*CA Band*/ #define  __MIPI_RX_ROUTE126__
/*CA Band*/ #endif
/*CA Band*/
/*CA Band*/ #if ROUTE_MAP_GROUP_SET(7,RX,SetNumber) & (1<<15)
/*CA Band*/ #define  __MIPI_RX_ROUTE127__
/*CA Band*/ #endif
/*CA Band*/

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/*-----------------------*/
/* RX CA Common Settings */
/*-----------------------*/
#ifdef __MIPI_RX_ROUTE21__
#define MIPI_RX_ROUTE_IND21         LTE_Route21
#else
#define MIPI_RX_ROUTE_IND21         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE22__
#define MIPI_RX_ROUTE_IND22         LTE_Route22
#else
#define MIPI_RX_ROUTE_IND22         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE23__
#define MIPI_RX_ROUTE_IND23         LTE_Route23
#else
#define MIPI_RX_ROUTE_IND23         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE24__
#define MIPI_RX_ROUTE_IND24         LTE_Route24
#else
#define MIPI_RX_ROUTE_IND24         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE25__
#define MIPI_RX_ROUTE_IND25         LTE_Route25
#else
#define MIPI_RX_ROUTE_IND25         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE26__
#define MIPI_RX_ROUTE_IND26         LTE_Route26
#else
#define MIPI_RX_ROUTE_IND26         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE27__
#define MIPI_RX_ROUTE_IND27         LTE_Route27
#else
#define MIPI_RX_ROUTE_IND27         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE28__
#define MIPI_RX_ROUTE_IND28         LTE_Route28
#else
#define MIPI_RX_ROUTE_IND28         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE29__
#define MIPI_RX_ROUTE_IND29         LTE_Route29
#else
#define MIPI_RX_ROUTE_IND29         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE30__
#define MIPI_RX_ROUTE_IND30         LTE_Route30
#else
#define MIPI_RX_ROUTE_IND30         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE31__
#define MIPI_RX_ROUTE_IND31         LTE_Route31
#else
#define MIPI_RX_ROUTE_IND31         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE32__
#define MIPI_RX_ROUTE_IND32         LTE_Route32
#else
#define MIPI_RX_ROUTE_IND32         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE33__
#define MIPI_RX_ROUTE_IND33         LTE_Route33
#else
#define MIPI_RX_ROUTE_IND33         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE34__
#define MIPI_RX_ROUTE_IND34         LTE_Route34
#else
#define MIPI_RX_ROUTE_IND34         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE35__
#define MIPI_RX_ROUTE_IND35         LTE_Route35
#else
#define MIPI_RX_ROUTE_IND35         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE36__
#define MIPI_RX_ROUTE_IND36         LTE_Route36
#else
#define MIPI_RX_ROUTE_IND36         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE37__
#define MIPI_RX_ROUTE_IND37         LTE_Route37
#else
#define MIPI_RX_ROUTE_IND37         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE38__
#define MIPI_RX_ROUTE_IND38         LTE_Route38
#else
#define MIPI_RX_ROUTE_IND38         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE39__
#define MIPI_RX_ROUTE_IND39         LTE_Route39
#else
#define MIPI_RX_ROUTE_IND39         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE40__
#define MIPI_RX_ROUTE_IND40         LTE_Route40
#else
#define MIPI_RX_ROUTE_IND40         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE41__
#define MIPI_RX_ROUTE_IND41         LTE_Route41
#else
#define MIPI_RX_ROUTE_IND41         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE42__
#define MIPI_RX_ROUTE_IND42         LTE_Route42
#else
#define MIPI_RX_ROUTE_IND42         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE43__
#define MIPI_RX_ROUTE_IND43         LTE_Route43
#else
#define MIPI_RX_ROUTE_IND43         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE44__
#define MIPI_RX_ROUTE_IND44         LTE_Route44
#else
#define MIPI_RX_ROUTE_IND44         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE45__
#define MIPI_RX_ROUTE_IND45         LTE_Route45
#else
#define MIPI_RX_ROUTE_IND45         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE46__
#define MIPI_RX_ROUTE_IND46         LTE_Route46
#else
#define MIPI_RX_ROUTE_IND46         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE47__
#define MIPI_RX_ROUTE_IND47         LTE_Route47
#else
#define MIPI_RX_ROUTE_IND47         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE48__
#define MIPI_RX_ROUTE_IND48         LTE_Route48
#else
#define MIPI_RX_ROUTE_IND48         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE49__
#define MIPI_RX_ROUTE_IND49         LTE_Route49
#else
#define MIPI_RX_ROUTE_IND49         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE50__
#define MIPI_RX_ROUTE_IND50         LTE_Route50
#else
#define MIPI_RX_ROUTE_IND50         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE51__
#define MIPI_RX_ROUTE_IND51         LTE_Route51
#else
#define MIPI_RX_ROUTE_IND51         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE52__
#define MIPI_RX_ROUTE_IND52         LTE_Route52
#else
#define MIPI_RX_ROUTE_IND52         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE53__
#define MIPI_RX_ROUTE_IND53         LTE_Route53
#else
#define MIPI_RX_ROUTE_IND53         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE54__
#define MIPI_RX_ROUTE_IND54         LTE_Route54
#else
#define MIPI_RX_ROUTE_IND54         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE55__
#define MIPI_RX_ROUTE_IND55         LTE_Route55
#else
#define MIPI_RX_ROUTE_IND55         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE56__
#define MIPI_RX_ROUTE_IND56         LTE_Route56
#else
#define MIPI_RX_ROUTE_IND56         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE57__
#define MIPI_RX_ROUTE_IND57         LTE_Route57
#else
#define MIPI_RX_ROUTE_IND57         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE58__
#define MIPI_RX_ROUTE_IND58         LTE_Route58
#else
#define MIPI_RX_ROUTE_IND58         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE59__
#define MIPI_RX_ROUTE_IND59         LTE_Route59
#else
#define MIPI_RX_ROUTE_IND59         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE60__
#define MIPI_RX_ROUTE_IND60         LTE_Route60
#else
#define MIPI_RX_ROUTE_IND60         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE61__
#define MIPI_RX_ROUTE_IND61         LTE_Route61
#else
#define MIPI_RX_ROUTE_IND61         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE62__
#define MIPI_RX_ROUTE_IND62         LTE_Route62
#else
#define MIPI_RX_ROUTE_IND62         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE63__
#define MIPI_RX_ROUTE_IND63         LTE_Route63
#else
#define MIPI_RX_ROUTE_IND63         LTE_BandNone
#endif

#ifdef __MIPI_RX_ROUTE64__
#define MIPI_RX_ROUTE_IND64         LTE_Route64
#else
#define MIPI_RX_ROUTE_IND64         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE65__
#define MIPI_RX_ROUTE_IND65         LTE_Route65
#else
#define MIPI_RX_ROUTE_IND65         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE66__
#define MIPI_RX_ROUTE_IND66         LTE_Route66
#else
#define MIPI_RX_ROUTE_IND66         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE67__
#define MIPI_RX_ROUTE_IND67         LTE_Route67
#else
#define MIPI_RX_ROUTE_IND67         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE68__
#define MIPI_RX_ROUTE_IND68         LTE_Route68
#else
#define MIPI_RX_ROUTE_IND68         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE69__
#define MIPI_RX_ROUTE_IND69         LTE_Route69
#else
#define MIPI_RX_ROUTE_IND69         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE70__
#define MIPI_RX_ROUTE_IND70         LTE_Route70
#else
#define MIPI_RX_ROUTE_IND70         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE71__
#define MIPI_RX_ROUTE_IND71         LTE_Route71
#else
#define MIPI_RX_ROUTE_IND71         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE72__
#define MIPI_RX_ROUTE_IND72         LTE_Route72
#else
#define MIPI_RX_ROUTE_IND72         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE73__
#define MIPI_RX_ROUTE_IND73         LTE_Route73
#else
#define MIPI_RX_ROUTE_IND73         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE74__
#define MIPI_RX_ROUTE_IND74         LTE_Route74
#else
#define MIPI_RX_ROUTE_IND74         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE75__
#define MIPI_RX_ROUTE_IND75         LTE_Route75
#else
#define MIPI_RX_ROUTE_IND75         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE76__
#define MIPI_RX_ROUTE_IND76         LTE_Route76
#else
#define MIPI_RX_ROUTE_IND76         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE77__
#define MIPI_RX_ROUTE_IND77         LTE_Route77
#else
#define MIPI_RX_ROUTE_IND77         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE78__
#define MIPI_RX_ROUTE_IND78         LTE_Route78
#else
#define MIPI_RX_ROUTE_IND78         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE79__
#define MIPI_RX_ROUTE_IND79         LTE_Route79
#else
#define MIPI_RX_ROUTE_IND79         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE80__
#define MIPI_RX_ROUTE_IND80         LTE_Route80
#else
#define MIPI_RX_ROUTE_IND80         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE81__
#define MIPI_RX_ROUTE_IND81         LTE_Route81
#else
#define MIPI_RX_ROUTE_IND81         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE82__
#define MIPI_RX_ROUTE_IND82         LTE_Route82
#else
#define MIPI_RX_ROUTE_IND82         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE83__
#define MIPI_RX_ROUTE_IND83         LTE_Route83
#else
#define MIPI_RX_ROUTE_IND83         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE84__
#define MIPI_RX_ROUTE_IND84         LTE_Route84
#else
#define MIPI_RX_ROUTE_IND84         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE85__
#define MIPI_RX_ROUTE_IND85         LTE_Route85
#else
#define MIPI_RX_ROUTE_IND85         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE86__
#define MIPI_RX_ROUTE_IND86         LTE_Route86
#else
#define MIPI_RX_ROUTE_IND86         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE87__
#define MIPI_RX_ROUTE_IND87         LTE_Route87
#else
#define MIPI_RX_ROUTE_IND87         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE88__
#define MIPI_RX_ROUTE_IND88         LTE_Route88
#else
#define MIPI_RX_ROUTE_IND88         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE89__
#define MIPI_RX_ROUTE_IND89         LTE_Route89
#else
#define MIPI_RX_ROUTE_IND89         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE90__
#define MIPI_RX_ROUTE_IND90         LTE_Route90
#else
#define MIPI_RX_ROUTE_IND90         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE91__
#define MIPI_RX_ROUTE_IND91         LTE_Route91
#else
#define MIPI_RX_ROUTE_IND91         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE92__
#define MIPI_RX_ROUTE_IND92         LTE_Route92
#else
#define MIPI_RX_ROUTE_IND92         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE93__
#define MIPI_RX_ROUTE_IND93         LTE_Route93
#else
#define MIPI_RX_ROUTE_IND93         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE94__
#define MIPI_RX_ROUTE_IND94         LTE_Route94
#else
#define MIPI_RX_ROUTE_IND94         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE95__
#define MIPI_RX_ROUTE_IND95         LTE_Route95
#else
#define MIPI_RX_ROUTE_IND95         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE96__
#define MIPI_RX_ROUTE_IND96         LTE_Route96
#else
#define MIPI_RX_ROUTE_IND96         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE97__
#define MIPI_RX_ROUTE_IND97         LTE_Route97
#else
#define MIPI_RX_ROUTE_IND97         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE98__
#define MIPI_RX_ROUTE_IND98         LTE_Route98
#else
#define MIPI_RX_ROUTE_IND98         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE99__
#define MIPI_RX_ROUTE_IND99         LTE_Route99
#else
#define MIPI_RX_ROUTE_IND99         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE100__
#define MIPI_RX_ROUTE_IND100         LTE_Route100
#else
#define MIPI_RX_ROUTE_IND100         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE101__
#define MIPI_RX_ROUTE_IND101         LTE_Route101
#else
#define MIPI_RX_ROUTE_IND101         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE102__
#define MIPI_RX_ROUTE_IND102         LTE_Route102
#else
#define MIPI_RX_ROUTE_IND102         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE103__
#define MIPI_RX_ROUTE_IND103         LTE_Route103
#else
#define MIPI_RX_ROUTE_IND103         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE104__
#define MIPI_RX_ROUTE_IND104         LTE_Route104
#else
#define MIPI_RX_ROUTE_IND104         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE105__
#define MIPI_RX_ROUTE_IND105         LTE_Route105
#else
#define MIPI_RX_ROUTE_IND105         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE106__
#define MIPI_RX_ROUTE_IND106         LTE_Route106
#else
#define MIPI_RX_ROUTE_IND106         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE107__
#define MIPI_RX_ROUTE_IND107         LTE_Route107
#else
#define MIPI_RX_ROUTE_IND107         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE108__
#define MIPI_RX_ROUTE_IND108         LTE_Route108
#else
#define MIPI_RX_ROUTE_IND108         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE109__
#define MIPI_RX_ROUTE_IND109         LTE_Route109
#else
#define MIPI_RX_ROUTE_IND109         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE110__
#define MIPI_RX_ROUTE_IND110         LTE_Route110
#else
#define MIPI_RX_ROUTE_IND110         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE111__
#define MIPI_RX_ROUTE_IND111         LTE_Route111
#else
#define MIPI_RX_ROUTE_IND111         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE112__
#define MIPI_RX_ROUTE_IND112         LTE_Route112
#else
#define MIPI_RX_ROUTE_IND112         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE113__
#define MIPI_RX_ROUTE_IND113         LTE_Route113
#else
#define MIPI_RX_ROUTE_IND113         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE114__
#define MIPI_RX_ROUTE_IND114         LTE_Route114
#else
#define MIPI_RX_ROUTE_IND114         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE115__
#define MIPI_RX_ROUTE_IND115         LTE_Route115
#else
#define MIPI_RX_ROUTE_IND115         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE116__
#define MIPI_RX_ROUTE_IND116         LTE_Route116
#else
#define MIPI_RX_ROUTE_IND116         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE117__
#define MIPI_RX_ROUTE_IND117         LTE_Route117
#else
#define MIPI_RX_ROUTE_IND117         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE118__
#define MIPI_RX_ROUTE_IND118         LTE_Route118
#else
#define MIPI_RX_ROUTE_IND118         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE119__
#define MIPI_RX_ROUTE_IND119         LTE_Route119
#else
#define MIPI_RX_ROUTE_IND119         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE120__
#define MIPI_RX_ROUTE_IND120         LTE_Route120
#else
#define MIPI_RX_ROUTE_IND120         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE121__
#define MIPI_RX_ROUTE_IND121         LTE_Route121
#else
#define MIPI_RX_ROUTE_IND121         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE122__
#define MIPI_RX_ROUTE_IND122         LTE_Route122
#else
#define MIPI_RX_ROUTE_IND122         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE123__
#define MIPI_RX_ROUTE_IND123         LTE_Route123
#else
#define MIPI_RX_ROUTE_IND123         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE124__
#define MIPI_RX_ROUTE_IND124         LTE_Route124
#else
#define MIPI_RX_ROUTE_IND124         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE125__
#define MIPI_RX_ROUTE_IND125         LTE_Route125
#else
#define MIPI_RX_ROUTE_IND125         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE126__
#define MIPI_RX_ROUTE_IND126         LTE_Route126
#else
#define MIPI_RX_ROUTE_IND126         LTE_BandNone
#endif
#ifdef __MIPI_RX_ROUTE127__
#define MIPI_RX_ROUTE_IND127         LTE_Route127
#else
#define MIPI_RX_ROUTE_IND127         LTE_BandNone
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

//#endif /* End of #ifndef __EL1D_RF_CA_DRDI_H__ */

