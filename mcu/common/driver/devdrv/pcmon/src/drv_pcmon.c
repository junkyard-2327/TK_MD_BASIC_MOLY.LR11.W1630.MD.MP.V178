/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   drv_pcmon.c
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *
 *
 * Author:
 *   mtk08073
 *
 *
 * ==========================================================================
 * $Log$
 *
 * 08 17 2016 alan-tl.lin
 * [MOLY00197357] [PDAMON] Refine RMPU violation backup flow
 * .
 *
 * 02 16 2016 alan-tl.lin
 * [MOLY00165020] [PCMon] Mask CTI event in production release load
 * Mask CTI event bit in user load
 *
 * 02 03 2016 alan-tl.lin
 * [MOLY00159660] [System Service][MOLY Kernel Internal Request] EMI RMPU design change
 * Backup PCMON for RMPU violation case
 *
 * 09 23 2015 alan-tl.lin
 * [MOLY00142374] [SystemService][DebuggingSuite][Internal Refinement]Support l1core exception long time no response
 * [PCMON] Add L1 PCMON API for PSCore usage
 *
 * 09 22 2015 alan-tl.lin
 * [MOLY00142815] [PCMON] Fix Klocwork
 *
 * 09 18 2015 alan-tl.lin
 * [MOLY00142432] [UMOLY] System initialize PCM init check in.
 * [PCMON] Add PCMON BB dump & L1 PCMON API on PSCore
 *
 * 07 06 2015 alan-tl.lin
 * [MOLY00110270] [PCMon] Driver porting
 * Add DA information
 *
 * 04 30 2015 alan-tl.lin
 * [MOLY00110270] [PCMon] Driver porting
 * [TK6291][PCMon] Initial version of driver. Support IA only.
 *
 * 07 31 2014 alan-tl.lin
 * [MOLY00063269] [System Service][MOLY Kernel Internal Request] Add/Show PCMON information in exception flow
 * [TK6291] PCMon driver check-in
 ****************************************************************************/

#include "irqid.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ex_public.h"
#include "mcu_pmu_montr.h"

#include "drv_comm.h"
#include "drv_gdma.h"
#include "ect.h"

#include "pcmon_reg.h"
#include "drv_pcmon.h"


#if !defined(DRV_PCM_OFF)

/*****************************************************************************
 *                       Symbol Definition                                   *
 *****************************************************************************/

#define PCMON_STOP_SRC_MASK     0x5FF
#define PCMON_STOP_SRC_SHIFT    16

/**
 * Internal option
 * If this option is set, trigger ASSERT if any driver error.
 */
#define DRV_PCM_DBG_ASSERT      (0)

/**
 * Internal option
 * If this option is set, trigger ASSERT if any driver error.
 */
#define DRV_PCM_PERF_LOG        (0)

/*****************************************************************************
 *                       Global/External Variable                            *
 *****************************************************************************/

#if defined(__PCORE__)
EX_BBREG_DUMP pcmon_dump;
const kal_uint32 pcmon_dump_regions[] = {
    L1_PCMON_BASE, 0x500, 4,
    PCMON_BASE, 0x500, 4
};
#endif // __PCORE__

/* HISR ID */
static kal_hisrid pcm_hisrid;

/* Backup profiling enumeration */
typedef enum {
    PCM_PERF_INIT,
    PCM_PERF_TAG_00 = PCM_PERF_INIT,
    PCM_PERF_TAG_01,
    PCM_PERF_TAG_02,
    PCM_PERF_TAG_03,
    PCM_PERF_TAG_04,
    PCM_PERF_TAG_05,
    PCM_PERF_TAG_06,
    PCM_PERF_TAG_07,
    PCM_PERF_TAG_08,
    PCM_PERF_TAG_09,
    PCM_PERF_TAG_10,
    PCM_PERF_TAG_11,
    PCM_PERF_TAG_12,
    PCM_PERF_TAG_13,
    PCM_PERF_TAG_14,
    PCM_PERF_TAG_15,
    PCM_PERF_MAX,
} PCM_PROFILE_INDEX;

#if (DRV_PCM_PERF_LOG)
/* Backup profiling log */
__attribute__((zero_init, section("INTSRAM_ZI"))) kal_uint32 g_pcm_perf_log[PCM_PERF_MAX];
#endif

/*****************************************************************************
 *                       Macros                                              *
 *****************************************************************************/

/**
 * Performance logging
 */
#if (DRV_PCM_PERF_LOG)
#define PCM_PERF_LOG(idx) \
    g_pcm_perf_log[idx] = MCU_PMU_ReadCounter(PMU_CYCLE_COUNTER)
#else // DRV_PCM_PERF_LOG
#define PCM_PERF_LOG(idx)
#endif // DRV_PCM_PERF_LOG

/**
 * Driver debugging
 */
#if (DRV_PCM_DBG_ASSERT)
#define PCM_DBG_ASSERT  ASSERT(0)
#else
#define PCM_DBG_ASSERT
#endif

/*****************************************************************************
 *                       Function Declaration                                *
 *****************************************************************************/


/*****************************************************************************
 *                       Basic Driver Implementation                         *
 *****************************************************************************/

#if defined(__PCORE__)
kal_bool pcmon_bbreg_dump_callback(void)
{
    drv_pcm_stop_capture();
    drv_l1pcm_stop_capture();
    return KAL_TRUE;
}
#endif // __PCORE__

/******************************************************************************
 * FUNCTION
 *   drv_pcm_initialize
 *
 * DESCRIPTION
 *   This function is to initialize SW PCMON module.
 *
 * PARAMETERS
 *   none
 *
 * RETURNS
 *   PCMON_OK
 *
 ******************************************************************************/
PCMON_RET drv_pcm_initialize(void)
{
#if defined(__PCORE__)
    pcmon_dump.regions = (kal_uint32*)pcmon_dump_regions;
    pcmon_dump.num = sizeof(pcmon_dump_regions)/(sizeof(kal_uint32) * 3);
    pcmon_dump.bbreg_dump_callback = pcmon_bbreg_dump_callback;
    EX_REGISTER_BBREG_DUMP(&pcmon_dump);
#endif // __PCORE__
    /* Create HISR for polling backup done */
    pcm_hisrid = kal_init_hisr(PCM_HISR);

    return PCMON_OK;
}


/******************************************************************************
 * FUNCTION
 *   drv_pcm_reset
 *
 * DESCRIPTION
 *   This function is to reset the hardware PCMON module.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 ******************************************************************************/
void drv_pcm_reset(void)
{
}


/******************************************************************************
 * FUNCTION
 *   drv_pcm_set_config
 *
 * DESCRIPTION
 *   This function is to configure the PCMON module.
 *
 * PARAMETERS
 *   pcm_cfg [in] PCMON config parameters
 *
 * RETURNS
 *   PCMON_OK
 *
 ******************************************************************************/
PCMON_RET drv_pcm_set_config(pcm_config *pcm_cfg)
{
    // Stop PCMon first
    drv_pcm_stop_capture();
    // Set configuration
    DRV_WriteReg32(PCMON_CTRL_0, (DRV_Reg32(PCMON_CTRL_0) & ~(PCMON_DIFF_MASK)) | PCMON_DIFF(pcm_cfg->pc_diff));
    return PCMON_OK;
}


/******************************************************************************
 * FUNCTION
 *   drv_pcm_get_config
 *
 * DESCRIPTION
 *   This function is to get configure info of PCMON.
 *
 * PARAMETERS
 *   pcm_cfg [out] Structure pointer to PCMON config parameters
 *
 * RETURNS
 *   None
 *
 ******************************************************************************/
void drv_pcm_get_config(pcm_config *pcm_cfg)
{
    // After 91/Jade project, this API is not support
}


/******************************************************************************
 * FUNCTION
 *   drv_pcm_start_capture
 *
 * DESCRIPTION
 *   This function is to start record instruction address, context ID, and
 *   data address from ETM interface.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   PCMON_OK
 *   PCMON_ALREADY_STARTED
 *
 ******************************************************************************/
PCMON_RET drv_pcm_start_capture(void)
{
#if defined(__PRODUCTION_RELEASE__)
    /*
     * In user load, mask RMPU event
     */
    if (kal_query_systemInit() == KAL_TRUE)
        DRV_WriteReg32(PCMON_CTRL_0, DRV_Reg32(PCMON_CTRL_0) | PCMON_EVT_MASK_RMPU);
#endif
    // If PCMon is stopped, we re-start it
    if ((DRV_Reg32(PCMON_RECORD_STATUS) & PCMON_IS_STOPPED) > 0) {
        DRV_WriteReg32(PCMON_CTRL_1, PCMON_RESTART);
        return PCMON_OK;
    } else {
        return PCMON_ALREADY_STARTED;
    }
}

PCMON_RET drv_l1pcm_start_capture(void)
{
#if defined(__PCORE__)
    // If PCMon is stopped, we re-start it
    if ((DRV_Reg32(L1PCMON_RECORD_STATUS) & PCMON_IS_STOPPED) > 0) {
        DRV_WriteReg32(L1PCMON_CTRL_1, PCMON_RESTART);
        return PCMON_OK;
    } else {
        return PCMON_ALREADY_STARTED;
    }
#else // __PCORE__
    return PCMON_UNSUPPORTED;
#endif // __PCORE__
}

/******************************************************************************
 * FUNCTION
 *   drv_pcm_stop_capture
 *
 * DESCRIPTION
 *   This function is to stop PCMON from recording.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   PCMON_OK
 *   PCMON_ALREADY_STOPPED
 *
 ******************************************************************************/
PCMON_RET drv_pcm_stop_capture(void)
{
#if 1
    DRV_WriteReg32(PCMON_CTRL_1, PCMON_STOP);
    // Polling stop bit
    while ((DRV_Reg32(PCMON_RECORD_STATUS) & PCMON_IS_STOPPED) == 0) ;
    return PCMON_OK;
#else
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
}


PCMON_RET drv_l1pcm_stop_capture(void)
{
#if defined(__PCORE__)
    DRV_WriteReg32(L1PCMON_CTRL_1, PCMON_STOP);
    // Polling stop bit
    while ((DRV_Reg32(L1PCMON_RECORD_STATUS) & PCMON_IS_STOPPED) == 0) ;
    return PCMON_OK;
#else // __PCORE__
    return PCMON_UNSUPPORTED;
#endif // __PCORE__
}

/******************************************************************************
 * FUNCTION
 *   drv_pcm_get_pc_pair
 *
 * DESCRIPTION
 *   This function is to get discontinuous program counter pair.
 *
 * PARAMETERS
 *   num [in] Pair index. From 0 to 31
 *   pc0 [out] Source program counter
 *   pc1 [out] Destination program counter
 *
 * RETURNS
 *   PCMON_OK
 *   PCMON_INVALID_ARGUMENT
 *
 ******************************************************************************/
PCMON_RET drv_pcm_get_pc_pair(kal_uint8 num, kal_uint32 *pc0, kal_uint32 *pc1)
{
    if ((num >= PCMON_TOTAL_RECORD_COUNT) ||
        (pc0 == NULL) ||
        (pc1 == NULL))
        return PCMON_INVALID_ARGUMENT;

    *pc0 = DRV_Reg32(PCMON_PC_(2 * num));
    *pc1 = DRV_Reg32(PCMON_PC_(2 * num + 1));;
    return PCMON_OK;
}


PCMON_RET drv_l1pcm_get_pc_pair(kal_uint8 num, kal_uint32 *pc0, kal_uint32 *pc1)
{
#if defined(__PCORE__)
    if ((num >= PCMON_TOTAL_RECORD_COUNT) ||
        (pc0 == NULL) ||
        (pc1 == NULL))
        return PCMON_INVALID_ARGUMENT;

    *pc0 = DRV_Reg32(L1PCMON_PC_(2 * num));
    *pc1 = DRV_Reg32(L1PCMON_PC_(2 * num + 1));;
    return PCMON_OK;
#else // __PCORE__
    return PCMON_UNSUPPORTED;
#endif // __PCORE__
}

/******************************************************************************
 * FUNCTION
 *   drv_pcm_get_cid_pair
 *
 * DESCRIPTION
 *   This function is to get context ID pair correspond to program counter pair.
 *
 * PARAMETERS
 *   num    [in] Pair index. From 0 to 31
 *   cid0   [out] Context ID 0
 *   cid1   [out] Context ID 1
 *
 * RETURNS
 *   PCMON_OK
 *
 ******************************************************************************/
PCMON_RET drv_pcm_get_cid_pair(kal_uint8 num, kal_uint32 *cid0, kal_uint32 *cid1)
{
    if ((num >= PCMON_TOTAL_RECORD_COUNT) ||
        (cid0 == NULL) ||
        (cid1 == NULL))
        return PCMON_INVALID_ARGUMENT;

    *cid0 = DRV_Reg32(PCMON_CID_(2 * num));
    *cid1 = DRV_Reg32(PCMON_CID_(2 * num + 1));
    return PCMON_OK;
}

/******************************************************************************
 * FUNCTION
 *   drv_pcm_get_da
 *
 * DESCRIPTION
 *   This function is to get program counter and data address from PCMON.
 *
 * PARAMETERS
 *   num    [in] Pair index. From 0 to 31.
 *   pc     [out] Pointer to kal_uint32 to store program counter value
 *   da     [out] Pointer to kal_uint32 to store data address value
 *
 * RETURNS
 *   PCMON_OK
 *   PCMON_INVALID_ARGUMENT
 *
 ******************************************************************************/
PCMON_RET drv_pcm_get_da(kal_uint8 num, kal_uint32 *pc, kal_uint32 *da)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    kal_uint32 tag = 0;
    kal_uint32 pc_pair_pc = 0, ia_da_pc = 0, da_temp = 0;
    kal_int32 tag_delta = 0, da_delta = 0;

    if ((num >= PCMON_TOTAL_RECORD_COUNT) ||
        (pc == NULL) ||
        (da == NULL))
        return PCMON_INVALID_ARGUMENT;

    *pc = 0;
    *da = 0;

#if defined(TK6291)
    tag_delta = -1;
    da_delta = 2;
#endif

    pc_pair_pc = DRV_Reg32(PCMON_PC_(2 * num + 1));
    tag = DRV_Reg32(PCMON_IADA_TAG(num + tag_delta));
    tag = (tag & (PCMON_TAG_IDX_MASK << PCMON_TAG_IDX_SHIFT)) >> PCMON_TAG_IDX_SHIFT;
    tag = tag + da_delta;
    ia_da_pc = DRV_Reg32(PCMON_IADA_PC(tag));
    da_temp = DRV_Reg32(PCMON_IADA_DA(tag));

    *pc = ia_da_pc | 1;
    *da = da_temp;

    // Correct DA
    if ((num != 0) && (ia_da_pc == pc_pair_pc)) {
        *pc = pc_pair_pc;
    }

    return PCMON_OK;
#endif
}

PCMON_RET drv_l1pcm_get_da(kal_uint8 num, kal_uint32 *pc, kal_uint32 *da)
{
#if defined(__PCORE__)
    kal_uint32 tag = 0;
    kal_uint32 pc_pair_pc = 0, ia_da_pc = 0, da_temp = 0;
    kal_int32 tag_delta = 0, da_delta = 0;

    if ((num >= PCMON_TOTAL_RECORD_COUNT) ||
        (pc == NULL) ||
        (da == NULL))
        return PCMON_INVALID_ARGUMENT;

    *pc = 0;
    *da = 0;
#if defined(TK6291)
    tag_delta = -1;
    da_delta = 2;
#endif

    pc_pair_pc = DRV_Reg32(L1PCMON_PC_(2 * num + 1));
    tag = DRV_Reg32(PCMON_IADA_TAG(num + tag_delta));
    tag = (tag & (PCMON_TAG_IDX_MASK << PCMON_TAG_IDX_SHIFT)) >> PCMON_TAG_IDX_SHIFT;
    tag = tag + da_delta;
    ia_da_pc = DRV_Reg32(L1PCMON_IADA_PC(tag));
    da_temp = DRV_Reg32(L1PCMON_IADA_DA(tag));

    *pc = ia_da_pc | 1;
    *da = da_temp;

    // Correct DA
    if ((num != 0) && (ia_da_pc == pc_pair_pc)) {
        *pc = pc_pair_pc;
    }

    return PCMON_OK;
#else // __PCORE__
    return PCMON_UNSUPPORTED;
#endif // __PCORE__
}

/******************************************************************************
 * FUNCTION
 *   drv_pcm_get_pc_count
 *
 * DESCRIPTION
 *   This function is to get record count of PC
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   Record count of program counter
 *
 ******************************************************************************/
kal_uint32 drv_pcm_get_pc_count()
{
    kal_uint32 pcmon_status = 0;

    // If PCMon IA record is not wrap, get record count from register
    pcmon_status = DRV_Reg32(PCMON_RECORD_STATUS);
    if ((pcmon_status & PCMON_IA_WRAP) == 0) {
        return ((pcmon_status & (PCMON_IA_COUNT_MASK << PCMON_IA_COUNT_SHIFT)) >> PCMON_IA_COUNT_SHIFT);
    } else {
        return PCMON_TOTAL_RECORD_COUNT;
    }
}


kal_uint32 drv_l1pcm_get_pc_count()
{
#if defined(__PCORE__)
    kal_uint32 pcmon_status = 0;

    // If PCMon IA record is not wrap, get record count from register
    pcmon_status = DRV_Reg32(L1PCMON_RECORD_STATUS);
    if ((pcmon_status & PCMON_IA_WRAP) == 0) {
        return ((pcmon_status & (PCMON_IA_COUNT_MASK << PCMON_IA_COUNT_SHIFT)) >> PCMON_IA_COUNT_SHIFT);
    } else {
        return PCMON_TOTAL_RECORD_COUNT;
    }
#else // __PCORE__
    return PCMON_UNSUPPORTED;
#endif // __PCORE__
}

/******************************************************************************
 * FUNCTION
 *   drv_pcm_get_da_count
 *
 * DESCRIPTION
 *   This function is to get record count of DA
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   Record count of data address
 *
 ******************************************************************************/
kal_uint32 drv_pcm_get_da_count()
{
    kal_uint32 pcmon_status = 0;

    // If PCMon DA record is not wrap, get record count from register
    pcmon_status = DRV_Reg32(PCMON_RECORD_STATUS);
    if ((pcmon_status & PCMON_DA_WRAP) == 0) {
        return ((pcmon_status & (PCMON_DA_COUNT_MASK << PCMON_DA_COUNT_SHIFT)) >> PCMON_DA_COUNT_SHIFT);
    } else {
        return PCMON_TOTAL_RECORD_COUNT;
    }
}

kal_uint32 drv_l1pcm_get_da_count()
{
#if defined(__PCORE__)
    kal_uint32 pcmon_status = 0;

    // If PCMon DA record is not wrap, get record count from register
    pcmon_status = DRV_Reg32(L1PCMON_RECORD_STATUS);
    if ((pcmon_status & PCMON_DA_WRAP) == 0) {
        return ((pcmon_status & (PCMON_DA_COUNT_MASK << PCMON_DA_COUNT_SHIFT)) >> PCMON_DA_COUNT_SHIFT);
    } else {
        return PCMON_TOTAL_RECORD_COUNT;
    }
#else // __PCORE__
    return PCMON_UNSUPPORTED;
#endif // __PCORE__
}

PCMON_RET drv_pcm_get_stop_source(kal_uint32 *source)
{
    kal_uint32 record_status = 0;

    record_status = DRV_Reg32(PCMON_RECORD_STATUS);
    /* PCMon is stopped */
    if (((record_status & PCMON_IS_STOPPED) > 0) && (record_status & PCMON_TRIG_RMPU) > 0) {
        if (source != NULL) {
            *source = (record_status & PCMON_STOP_SRC_MASK) >> PCMON_STOP_SRC_SHIFT;
        }
        return PCMON_OK;
    /* PCMon is not stopped */
    } else {
        if (source != NULL)
            *source = PCMON_SRC_NONE;
        return PCMON_FAIL;
    }
}

/**
 * Shared global variable to detect backup done
 */
#if defined(__PCORE__)
    DEFINE_NC_SHARED_VAR_ASSIGN(volatile kal_uint32, g_ps_pcm_hisr_count, 0)
    DEFINE_NC_SHARED_VAR_ASSIGN(volatile kal_uint32, g_l1_pcm_hisr_count, 0)
#else // __PCORE__
    DEFINE_NC_SHARED_VAR(volatile kal_uint32, g_ps_pcm_hisr_count)
    DEFINE_NC_SHARED_VAR(volatile kal_uint32, g_l1_pcm_hisr_count)
#endif // __PCORE__

#define PS_PCM_HISR_COUNT   (SHARED_VAR(g_ps_pcm_hisr_count))
#define L1_PCM_HISR_COUNT   (SHARED_VAR(g_l1_pcm_hisr_count))

kal_bool g_psgdma_busy = KAL_FALSE;
kal_bool g_psgdma_timeout[2] = { KAL_FALSE, KAL_FALSE };

/**
 * Define PSGDMA channel used by PCore and L1Core
 */
#if defined(__PCORE__)
    #define PSGDMA_BACKUP_CHN       (GDMA_CH_00)
#elif defined(__L1CORE__)
    #define PSGDMA_BACKUP_CHN       (GDMA_CH_01)
#endif

/**
 * Define PCMON Backup Address & Length
 */
#define PCMON_BACKUP_PC_ADDR        (BASE_ADDR_MDPCMON+0x100)
#define PCMON_BACKUP_PC_SIZE        (0x100)
#define PCMON_BACKUP_DA_ADDR        (BASE_ADDR_MDPCMON+0x400)
#define PCMON_BACKUP_DA_SIZE        (0x100)

/**
 * Define PSGDMA CSR
 */
#define PSGDMA_BASE                 (0x80020000)

#define PSGDMA_FDCSR(n)             (PSGDMA_BASE + 0x10U + (4*(n/2)))
    #define FDMA_STAT(n)            (0x1 << ((n % 2) * 16))
    #define FDMA_MODE_BASIC(n)      (0x1 << (9 + (n % 2) * 16))

#define PSGDMA_CH_REG_OFFSET        0x20
#define PSGDMA_FDCR(n)              (PSGDMA_BASE + 0x20U + (n*PSGDMA_CH_REG_OFFSET))
    #define FDMA_START              (0x1 << 0)
    #define FDMA_RESUME             (0x1 << 1)
    #define FDMA_STOP               (0x1 << 2)

    #define BST_SIZE_OFFSET         13
    #define BST_SIZE_64             (6 << BST_SIZE_OFFSET)

    #define DST_BUS_WIDTH_OFFSET    6
    #define DST_BUS_WIDTH_4         (2 << DST_BUS_WIDTH_OFFSET)

    #define SRC_BUS_WIDTH_OFFSET    4
    #define SRC_BUS_WIDTH_4         (2 << SRC_BUS_WIDTH_OFFSET)

#define PSGDMA_FDSAR(n)             (PSGDMA_BASE + 0x24U + (n*PSGDMA_CH_REG_OFFSET))
#define PSGDMA_FDDAR(n)             (PSGDMA_BASE + 0x28U + (n*PSGDMA_CH_REG_OFFSET))

#define FDMA_BST_BUS_CFG            (BST_SIZE_64 | DST_BUS_WIDTH_4 | SRC_BUS_WIDTH_4)

/******************************************************************************
 * FUNCTION
 *   pcmon_wait_us
 *
 * DESCRIPTION
 *   Busy wait in us.
 *
 ******************************************************************************/
INLINE static void pcmon_wait_us(kal_uint32 us)
{
   kal_uint32 delay;

   for (delay = (CPU_CLOCK_MHZ >> 4) * us; delay != 0; delay--)
   {
      __asm__("nop"); __asm__("nop"); __asm__("nop"); __asm__("nop");
      __asm__("nop"); __asm__("nop"); __asm__("nop"); __asm__("nop");
      __asm__("nop"); __asm__("nop"); __asm__("nop"); __asm__("nop");
      __asm__("nop"); __asm__("nop"); __asm__("nop"); __asm__("nop");
   }
}

/******************************************************************************
 * FUNCTION
 *   drv_pcm_backup_and_restart
 *
 * DESCRIPTION
 *   Backup PCMon record
 *
 ******************************************************************************/
 __attribute__ ((section ("INTSRAM_ROCODE"))) PCMON_RET drv_pcm_backup_and_restart(kal_bool mcu, PCM_RECORD *data_ptr, kal_bool mask)
{
    kal_uint32 backup_src = 0;
    kal_uint32 *backup_dst = 0;
    kal_uint32 saved_mask = 0;

    PCM_PERF_LOG(PCM_PERF_INIT);

    if (data_ptr == NULL) {
        PCM_DBG_ASSERT;
        return PCMON_INVALID_ARGUMENT;
    }

    /* PCMon is stopped */
    if ((DRV_Reg32(PCMON_RECORD_STATUS) & PCMON_IS_STOPPED) > 0) {

        PCM_PERF_LOG(PCM_PERF_TAG_01);

        /* Backup by MCU */
        if (mcu == KAL_TRUE) {
            /* Backup piped PC/CID */
            data_ptr->pc_piped[0].pc = DRV_Reg32(BASE_ADDR_MDPCMON + 0x20);
            data_ptr->pc_piped[0].cid = DRV_Reg32(BASE_ADDR_MDPCMON + 0x24);
            data_ptr->pc_piped[1].pc = DRV_Reg32(BASE_ADDR_MDPCMON + 0x28);
            data_ptr->pc_piped[1].cid = DRV_Reg32(BASE_ADDR_MDPCMON + 0x2C);
            data_ptr->pc_piped[2].pc = DRV_Reg32(BASE_ADDR_MDPCMON + 0x30);
            data_ptr->pc_piped[2].cid = DRV_Reg32(BASE_ADDR_MDPCMON + 0x34);
            PCM_PERF_LOG(PCM_PERF_TAG_02);

            /* Backup piped PC/DA */
            data_ptr->da_piped[0].pc = DRV_Reg32(BASE_ADDR_MDPCMON + 0x38);
            data_ptr->da_piped[0].da = DRV_Reg32(BASE_ADDR_MDPCMON + 0x3C);
            data_ptr->da_piped[1].pc = DRV_Reg32(BASE_ADDR_MDPCMON + 0x40);
            data_ptr->da_piped[1].da = DRV_Reg32(BASE_ADDR_MDPCMON + 0x44);
            PCM_PERF_LOG(PCM_PERF_TAG_03);

            /* Backup PC/CID record */
            backup_dst = (kal_uint32*)&data_ptr->pc_record[0];
            for (backup_src = PCMON_BACKUP_PC_ADDR; backup_src < PCMON_BACKUP_PC_ADDR + PCMON_BACKUP_PC_SIZE; backup_src += 4, backup_dst++) {
                *backup_dst = DRV_Reg32(backup_src);
            }
            PCM_PERF_LOG(PCM_PERF_TAG_04);

            /* Backup DA record */
            backup_dst = (kal_uint32*)&data_ptr->da_record[0];
            for (backup_src = PCMON_BACKUP_DA_ADDR; backup_src < PCMON_BACKUP_DA_ADDR + PCMON_BACKUP_DA_SIZE; backup_src += 4, backup_dst++) {
                *backup_dst = DRV_Reg32(backup_src);
            }
            PCM_PERF_LOG(PCM_PERF_TAG_05);
        /* Backup by PS GDMA */
        } else {
            /* PS GDMA is busy ?? */
            if ((DRV_Reg32(PSGDMA_FDCSR(PSGDMA_BACKUP_CHN)) & FDMA_STAT(PSGDMA_BACKUP_CHN)) > 0) {
                g_psgdma_busy = KAL_TRUE;
            } else {
                PCM_PERF_LOG(PCM_PERF_TAG_02);
#if defined(__PCORE__)
                FDMA_PDN_CLR(PSGDMA_BACKUP_CHN);
#else
                drv_psgdma_pdn_clr(PSGDMA_BACKUP_CHN);
#endif
                PCM_PERF_LOG(PCM_PERF_TAG_03);
                DRV_WriteReg32(PSGDMA_FDCSR(PSGDMA_BACKUP_CHN), (DRV_Reg32(PSGDMA_FDCSR(PSGDMA_BACKUP_CHN)) & ((PSGDMA_BACKUP_CHN % 2 == 0) ? 0xFFFFF0FF : 0xF0FFFFFF)) | FDMA_MODE_BASIC(PSGDMA_BACKUP_CHN));
                DRV_WriteReg32(PSGDMA_FDCR(PSGDMA_BACKUP_CHN), (PCMON_BACKUP_DA_SIZE << 16) | FDMA_BST_BUS_CFG);
                DRV_WriteReg32(PSGDMA_FDSAR(PSGDMA_BACKUP_CHN), PCMON_BACKUP_DA_ADDR);
                DRV_WriteReg32(PSGDMA_FDDAR(PSGDMA_BACKUP_CHN), (kal_uint32)&data_ptr->da_record[0]);
                DRV_WriteReg32_NPW(PSGDMA_FDCR(PSGDMA_BACKUP_CHN), DRV_Reg32(PSGDMA_FDCR(PSGDMA_BACKUP_CHN)) | FDMA_START);
                PCM_PERF_LOG(PCM_PERF_TAG_04);
                kal_activate_hisr(pcm_hisrid);
                PCM_PERF_LOG(PCM_PERF_TAG_05);
            }
        }

        if (mcu == KAL_TRUE) {
            saved_mask = SaveAndSetIRQMask();
            /* Mask/Unmask RMPU source */
            if (mask == KAL_TRUE) {
                DRV_WriteReg32_NPW(PCMON_DEV_CTRL_0, DRV_Reg32(PCMON_CTRL_0) | PCMON_EVT_MASK_RMPU);
            } else {
                DRV_WriteReg32_NPW(PCMON_DEV_CTRL_0, DRV_Reg32(PCMON_CTRL_0) & (~(PCMON_EVT_MASK_RMPU)));
            }
            RestoreIRQMask(saved_mask);
            PCM_PERF_LOG(PCM_PERF_TAG_06);

            /* Restart PCMon */
            drv_pcm_start_capture();
            PCM_PERF_LOG(PCM_PERF_TAG_07);
        }

        return PCMON_OK;
    /* PCMon is not stopped */
    } else {
        PCM_DBG_ASSERT;
        return PCMON_FAIL;
    }
}

/******************************************************************************
 * FUNCTION
 *   drv_pcm_mask_stop_source
 *
 * DESCRIPTION
 *   Mask/Unmask stop source of PCMon
 *
 ******************************************************************************/
PCMON_RET drv_pcm_mask_stop_source(kal_uint32 source, kal_bool mask)
{
    kal_uint32 mask_ctrl = 0;
    kal_uint32 saved_mask = 0;

    if (source == PCMON_SRC_NONE) {
        PCM_DBG_ASSERT;
        return PCMON_OK;
    }

    if (source & PCMON_SRC_AP_BUSMON)
        mask_ctrl |= PCMON_EVT_MASK_BUSMON_AP;
    if (source & PCMON_SRC_PS_BUSMON)
        mask_ctrl |= PCMON_EVT_MASK_BUSMON_PS;
    if (source & PCMON_SRC_L1_BUSMON)
        mask_ctrl |= PCMON_EVT_MASK_BUSMON_L1;
    if (source & PCMON_SRC_CTI)
        mask_ctrl |= PCMON_EVT_MASK_CTI;
    if (source & PCMON_SRC_AP_BUSERR)
        mask_ctrl |= PCMON_EVT_MASK_BUS_AP;
    if (source & PCMON_SRC_PS_BUSERR)
        mask_ctrl |= PCMON_EVT_MASK_BUS_PS;
    if (source & PCMON_SRC_L1_BUSERR)
        mask_ctrl |= PCMON_EVT_MASK_BUS_L1;
    if (source & PCMON_SRC_RGU)
        mask_ctrl |= PCMON_EVT_MASK_RGU;
    if (source & PCMON_SRC_RMPU)
        mask_ctrl |= PCMON_EVT_MASK_RMPU;

    saved_mask = SaveAndSetIRQMask();
    /* Mask/Unmask RMPU source */
    if (mask == KAL_TRUE) {
        DRV_WriteReg32_NPW(PCMON_DEV_CTRL_0, DRV_Reg32(PCMON_CTRL_0) | PCMON_EVT_MASK_RMPU);
    } else {
        DRV_WriteReg32_NPW(PCMON_DEV_CTRL_0, DRV_Reg32(PCMON_CTRL_0) & (~(PCMON_EVT_MASK_RMPU)));
    }
    RestoreIRQMask(saved_mask);

    return PCMON_OK;
}

/******************************************************************************
 * FUNCTION
 *   drv_pcm_poll_backup_done
 *
 * DESCRIPTION
 *   A function to poll PCMon backup flow is done
 *
 ******************************************************************************/
PCMON_RET drv_pcm_poll_backup_done()
{
    PCM_RECORD *data_ptr = NULL;
    kal_uint32 counter = 0;

    PCM_PERF_LOG(PCM_PERF_TAG_06);
    /* Polling backup channel */
    while ((DRV_Reg32(PSGDMA_FDCSR(PSGDMA_BACKUP_CHN)) & FDMA_STAT(PSGDMA_BACKUP_CHN))) {
        pcmon_wait_us(1);
        counter++;
        if (counter >= 5000) {
            g_psgdma_timeout[0] = KAL_TRUE;
            break;
        }
    }
    PCM_PERF_LOG(PCM_PERF_TAG_07);

    data_ptr = ECT_GetPCMON_BK_Buf_Ptr();

    if (data_ptr != NULL) {
        /* Backup piped PC/CID */
        data_ptr->pc_piped[0].pc = DRV_Reg32(BASE_ADDR_MDPCMON + 0x20);
        data_ptr->pc_piped[0].cid = DRV_Reg32(BASE_ADDR_MDPCMON + 0x24);
        data_ptr->pc_piped[1].pc = DRV_Reg32(BASE_ADDR_MDPCMON + 0x28);
        data_ptr->pc_piped[1].cid = DRV_Reg32(BASE_ADDR_MDPCMON + 0x2C);
        data_ptr->pc_piped[2].pc = DRV_Reg32(BASE_ADDR_MDPCMON + 0x30);
        data_ptr->pc_piped[2].cid = DRV_Reg32(BASE_ADDR_MDPCMON + 0x34);
        PCM_PERF_LOG(PCM_PERF_TAG_08);

        /* Backup piped PC/DA */
        data_ptr->da_piped[0].pc = DRV_Reg32(BASE_ADDR_MDPCMON + 0x38);
        data_ptr->da_piped[0].da = DRV_Reg32(BASE_ADDR_MDPCMON + 0x3C);
        data_ptr->da_piped[1].pc = DRV_Reg32(BASE_ADDR_MDPCMON + 0x40);
        data_ptr->da_piped[1].da = DRV_Reg32(BASE_ADDR_MDPCMON + 0x44);
        PCM_PERF_LOG(PCM_PERF_TAG_09);
    } else {
        PCM_DBG_ASSERT;
    }

    /* Restart PCMon */
    drv_pcm_start_capture();
    PCM_PERF_LOG(PCM_PERF_TAG_10);

#if defined(__PCORE__)
    PS_PCM_HISR_COUNT = PS_PCM_HISR_COUNT + 1;
    PCM_PERF_LOG(PCM_PERF_TAG_11);

    /* Wait until L1 core backup done */
    counter = 0;
    while (PS_PCM_HISR_COUNT != L1_PCM_HISR_COUNT) {
        pcmon_wait_us(1);
        counter++;
        if (counter >= 5000) {
            g_psgdma_timeout[1] = KAL_TRUE;
            break;
        }
    }
    PCM_PERF_LOG(PCM_PERF_TAG_12);

    /* Gate clock */
    FDMA_PDN_SET(GDMA_CH_00);
    FDMA_PDN_SET(GDMA_CH_01);
    PCM_PERF_LOG(PCM_PERF_TAG_13);
#else // __PCORE__
    L1_PCM_HISR_COUNT = L1_PCM_HISR_COUNT + 1;
    PCM_PERF_LOG(PCM_PERF_TAG_11);
#endif // __PCORE__

    return PCMON_OK;
}


/******************************************************************************
 * FUNCTION
 *   drv_pcm_is_backup_done
 *
 * DESCRIPTION
 *   A function to check if backup flow of PCore and L1Core are all done.
 *
 ******************************************************************************/
kal_bool drv_pcm_is_backup_done()
{
    if ((PS_PCM_HISR_COUNT != 0) && (PS_PCM_HISR_COUNT == L1_PCM_HISR_COUNT))
        return KAL_TRUE;
    else
        return KAL_FALSE;
}

/******************************************************************************
 * FUNCTION
 *   drv_pcm_hisr
 *
 * DESCRIPTION
 *   A HISR to poll backup is done
 *
 ******************************************************************************/
void drv_pcm_hisr(void)
{
    drv_pcm_poll_backup_done();
}

#else /*!defined(DRV_PCM_OFF)*/

#endif /*!defined(DRV_PCM_OFF)*/

