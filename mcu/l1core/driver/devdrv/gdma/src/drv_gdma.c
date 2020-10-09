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

#include "drv_comm.h"

#include "gdma_reg.h"
#include "drv_gdma.h"
#include "intrCtrl.h"

#include "dcl.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drvpdn.h"
#include "sleepdrv_interface.h"
#include "dcm_sw.h"
#include "us_timer.h"
#include "spinlock.h"
#include "ex_public.h"


#if !defined(DRV_L1GDMA_OFF)

/*****************************************************************************
 *                       SYMBOL Definition                                   *
 *****************************************************************************/

/*
 * Use LISR or HISR
 */
#define GDMA_LISR_ONLY
//#define FDMA_DEBUG_HISTORY
//#define TRAVERSE_GPD_ASSERT

/*
 * Use pre-fetch or not
 */
//#define GDMA_PF_SUPPORT
#ifdef GDMA_PF_SUPPORT
    #define GDMA_PF_1X
    //#define GDMA_PF_2X
#endif

/**
 * PSGDMA PDN API cross core usage support
 */
#define GDMA_PDN_SUPPORT_CC

/**
 * Define MDGDMA PDN global variable
 */
#if defined(GDMA_PDN_SUPPORT_CC)
    DEFINE_NC_SHARED_VAR_ASSIGN(kal_uint32, ps_fdma_pdn_clr_flag)
    #define PSGDMA_FDMA_PDN_CLR_FLAG    (SHARED_VAR(ps_fdma_pdn_clr_flag))
#if defined(__KAL_CROSS_CORE_SUPPORT__)
    DEFINE_NC_SHARED_VAR(spinlock_t, ps_gdma_pdn_lock)
    #define PSGDMA_PDN_LOCK             (SHARED_VAR(ps_gdma_pdn_lock))
#endif // __KAL_CROSS_CORE_SUPPORT__
#endif // GDMA_PDN_SUPPORT_CC

/* CSR default setting */
#define FDMA_BST_BUS(src,dst)   (BST_SIZE_64 | DST_BUS_WIDTH(dst) | SRC_BUS_WIDTH(src))

/* Critical Session */
#define FDMA_ENTER_CRITICAL_SECTION(status_irq)     status_irq = SaveAndSetIRQMask();
#define FDMA_LEAVE_CRITICAL_SECTION(status_irq)     RestoreIRQMask(status_irq);

/* Spinlock */
#if defined(GDMA_PDN_SUPPORT_CC)
    #if defined(__KAL_CROSS_CORE_SUPPORT__)
        #define SPINLOCK_DECLARE                kal_uint32 status = 0
        #define PSGDMA_SPINLOCK_INIT            spinlock_init(&(PSGDMA_PDN_LOCK))
        #define PSGDMA_SPIN_LOCK(status)        status = spin_lock(&(PSGDMA_PDN_LOCK))
        #define PSGDMA_SPIN_UNLOCK(status)      spin_unlock(&(PSGDMA_PDN_LOCK), status)
    #else
        #define SPINLOCK_DECLARE
        #define PSGDMA_SPINLOCK_INIT
        #define PSGDMA_SPIN_LOCK(status)
        #define PSGDMA_SPIN_UNLOCK(status)
    #endif
#endif // GDMA_PDN_SUPPORT_CC

#define FDMA_LOG_CNT (100)

/* Prefetch definition */
#ifdef GDMA_PF_SUPPORT
    #ifdef GDMA_PF_1X
        #define DEFAULT_GDMA_AXI_CON    (AHB2AXI_BUFFERABLE_EN | AHB2AXI_MERGE_EN | PF_ENABLE)
    #else
        #define DEFAULT_GDMA_AXI_CON    (AHB2AXI_BUFFERABLE_EN | AHB2AXI_MERGE_EN | PF_ENABLE | PF_LEN_SEL)
    #endif
#else // GDMA_PF_SUPPORT
    #define DEFAULT_GDMA_AXI_CON        (AHB2AXI_BUFFERABLE_EN | AHB2AXI_MERGE_EN)
#endif // GDMA_PF_SUPPORT

#if defined(FDMA_DEBUG_HISTORY)

#define API_LOGGING(_command, _irq_status, _caller, _channel, _extra) \
    FDMA_ENTER_CRITICAL_SECTION((_irq_status)); \
    GET_RETURN_ADDRESS((_caller)); \
    g_l1gdma_log.api_log[g_l1gdma_log.count].channel = (_channel); \
    g_l1gdma_log.api_log[g_l1gdma_log.count].command = (_command); \
    g_l1gdma_log.api_log[g_l1gdma_log.count].caller = (_caller); \
    g_l1gdma_log.api_log[g_l1gdma_log.count].uscnt = ust_get_current_time(); \
    g_l1gdma_log.api_log[g_l1gdma_log.count++].extra = (kal_uint32)(_extra); \
    if (g_l1gdma_log.count >= FDMA_LOG_CNT) \
        g_l1gdma_log.count = 0; \
    FDMA_LEAVE_CRITICAL_SECTION(_irq_status);

#define API_LOGGING_PDN_SET(_caller, _channel, _extra) \
    GET_RETURN_ADDRESS((_caller)); \
    g_l1gdma_log.api_log[g_l1gdma_log.count].channel = (_channel); \
    g_l1gdma_log.api_log[g_l1gdma_log.count].command = GDMA_LOG_PDN_SET; \
    g_l1gdma_log.api_log[g_l1gdma_log.count].caller = (_caller); \
    g_l1gdma_log.api_log[g_l1gdma_log.count].uscnt = ust_get_current_time(); \
    g_l1gdma_log.api_log[g_l1gdma_log.count++].extra = (_extra); \
    if (g_l1gdma_log.count >= FDMA_LOG_CNT) \
        g_l1gdma_log.count = 0;

#define API_LOGGING_PDN_CLR(_caller, _channel, _extra) \
    GET_RETURN_ADDRESS((_caller)); \
    g_l1gdma_log.api_log[g_l1gdma_log.count].channel = (_channel); \
    g_l1gdma_log.api_log[g_l1gdma_log.count].command = GDMA_LOG_PDN_CLR; \
    g_l1gdma_log.api_log[g_l1gdma_log.count].caller = (_caller); \
    g_l1gdma_log.api_log[g_l1gdma_log.count].uscnt = ust_get_current_time(); \
    g_l1gdma_log.api_log[g_l1gdma_log.count++].extra = (_extra); \
    if (g_l1gdma_log.count >= FDMA_LOG_CNT) \
        g_l1gdma_log.count = 0;

#else // FDMA_DEBUG_HISTORY

#define API_LOGGING(_command, _irq_status, _caller, _channel, _extra)
#define API_LOGGING_PDN_SET(_caller, _channel, _extra)
#define API_LOGGING_PDN_CLR(_caller, _channel, _extra)

#endif // FDMA_DEBUG_HISTORY


/*****************************************************************************
 *                       Type Definition                                     *
 *****************************************************************************/

/* FDMA global information */
typedef struct l1gdma_s {
    volatile kal_bool   inited;
    volatile kal_uint8  chn_started;
    kal_uint8 ostd_handle;
    volatile kal_uint32 intr_status[2];
    volatile kal_uint32 intr_unmask[2];
    volatile kal_uint32 cb_status[2];
    kal_uint32          intr_cnt[GDMA_INT_TYPE_MAX];
    gdma_pcb_f          Callback[GDMA_INT_TYPE_MAX];
    gdma_cbParameter_t  cb_info;
    volatile kal_uint32 intr_index;
} l1gdma_t;

/* Logging type */
typedef enum {
    GDMA_LOG_DUMMY,
    GDMA_LOG_CONFIG,
    GDMA_LOG_PRE_START,
    GDMA_LOG_START,
    GDMA_LOG_STOP,
    GDMA_LOG_POST_STOP,
    GDMA_LOG_GET_STATUS,
    GDMA_LOG_SET_PRIORITY,
    GDMA_LOG_PDN_SET,
    GDMA_LOG_PDN_CLR,
} log_type_e;

/* Logging item */
typedef struct log_item_s {
    gdma_channel_type_e channel;
    log_type_e command;
    kal_uint32 caller;
    kal_uint32 uscnt;
    kal_uint32 extra;
} log_item_t;

/* Logging structure */
typedef struct l1gdma_log_s {
    volatile kal_uint32 count;
    log_item_t api_log[FDMA_LOG_CNT];
} l1gdma_log_t;

/* GPD structure */
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

/*****************************************************************************
 *                       Global/External Variable                            *
 *****************************************************************************/

#if !defined(GDMA_LISR_ONLY)
static kal_hisrid gdma_hisrid;
#endif

static kal_uint32 fdma_sw_lock = 0;
static kal_uint32 gdma_is_swlock = KAL_FALSE;

static kal_uint32 fdma_pdn_clr = 0;
static kal_uint32 gdma_is_pdn_clr = KAL_FALSE;

EX_BBREG_DUMP gdma_dump;
const kal_uint32 gdma_dump_regions[] = {
    L1_BASE_MADDR_L1GDMA, 0x850, 4,
};

/*****************************************************************************
 *                       Function Declaration                                *
 *****************************************************************************/

void drv_gdma_hisr(void);
void drv_gdma_get_cbinfo(kal_uint32 int_idx);
void drv_gdma_set_priority_int(gdma_channel_type_e chId, gdma_priority_e priority, kal_bool pdn);

/*****************************************************************************
 *                       LISR/HISR/Callback Functions                        *
 *****************************************************************************/

static void drv_default_callback(gdma_cbParameter_t *gpd_info)
{
    kal_uint32 ASSERT_IN_GDMA_DEFAULT_CALLBACK = 0;
    ASSERT(ASSERT_IN_GDMA_DEFAULT_CALLBACK);
    return;
}

kal_bool gdma_bbreg_dump_callback(void)
{
    PDN_CLR(PDN_GDMA);
    return KAL_TRUE;
}

/*****************************************************************************
 *                       Basic Driver Implementation                         *
 *****************************************************************************/

/*---------------------------------------------------------------------------*
 * Debug
 *---------------------------------------------------------------------------*/

static l1gdma_t g_l1gdma = {0};
#if defined(FDMA_DEBUG_HISTORY)
static l1gdma_log_t g_l1gdma_log = {0};
#endif // FDMA_DEBUG_HISTORY

/*---------------------------------------------------------------------------*
 * Utility API
 *---------------------------------------------------------------------------*/

void GDMA_SWLOCK_CHK()
{
    kal_uint32 saved_mask;

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    if ((gdma_is_swlock == KAL_FALSE) && fdma_sw_lock != 0) {
        SleepDrv_SleepDisable(g_l1gdma.ostd_handle);
        gdma_is_swlock = KAL_TRUE;
    } else if ((gdma_is_swlock == KAL_TRUE) && (fdma_sw_lock == 0)) {
        SleepDrv_SleepEnable(g_l1gdma.ostd_handle);
        gdma_is_swlock = KAL_FALSE;
    }
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
}

void FDMA_SW_LOCK(kal_uint32 channel)
{
    kal_uint32 saved_mask;

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    fdma_sw_lock |= (1 << channel);
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
    GDMA_SWLOCK_CHK();
}

void FDMA_SW_UNLOCK(kal_uint32 channel)
{
    kal_uint32 saved_mask;

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    fdma_sw_lock &= (~(1 << channel));
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
    GDMA_SWLOCK_CHK();
}

void GDMA_PDN_CHK(gdma_channel_type_e chId)
{
    kal_uint32 saved_mask = 0;
#if defined(FDMA_DEBUG_HISTORY)
    kal_uint32 caller = 0;
#endif

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    if ((gdma_is_pdn_clr == KAL_FALSE) && fdma_pdn_clr != 0) {
        API_LOGGING_PDN_CLR(caller, chId, fdma_pdn_clr);
        PDN_CLR(PDN_GDMA);
        //DCM_ForceOffModemBusDCM(1);
        gdma_is_pdn_clr = KAL_TRUE;
    } else if ((gdma_is_pdn_clr == KAL_TRUE) && (fdma_pdn_clr == 0)) {
        API_LOGGING_PDN_SET(caller, chId, fdma_pdn_clr);
        //PDN_SET(PDN_GDMA);
        //DCM_ForceOffModemBusDCM(0);
        gdma_is_pdn_clr = KAL_FALSE;
    }
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
}

/**
 * KAL_TRUE     : PDN is set
 * KAL_FALSE    : PDN is clear
 */
kal_bool FDMA_PDN_STS(kal_uint32 channel)
{
    if (fdma_pdn_clr & (1 << channel)) {
        return KAL_FALSE;
    }
    return KAL_TRUE;
}

void FDMA_PDN_CLR(gdma_channel_type_e channel)
{
    kal_uint32 saved_mask = 0;

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    fdma_pdn_clr |= (1 << channel);
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
    GDMA_PDN_CHK(channel);
}

void FDMA_PDN_SET(gdma_channel_type_e channel)
{
    kal_uint32 saved_mask = 0;

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    fdma_pdn_clr &= (~(1 << channel));
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
    GDMA_PDN_CHK(channel);
}

void fdma_traverse_gpd(dma_gpd_t *gpd, kal_bool uncached_addr)
{
#if defined(TRAVERSE_GPD_ASSERT)
    dma_gpd_t *gpd_ptr = NULL;

    if (uncached_addr == KAL_TRUE) {
        gpd_ptr = (dma_gpd_t *)(((kal_uint32)gpd) & 0x0FFFFFFF);
    }

    while (gpd_ptr->hwo != 0) {
        if (gpd_ptr->nextPtr != 0x0) {
            if (uncached_addr == KAL_TRUE)
                gpd_ptr = (dma_gpd_t *)((gpd_ptr->nextPtr) & 0x0FFFFFFF);
            else
                gpd_ptr = (dma_gpd_t *)(gpd_ptr->nextPtr);
        } else {
            EXT_ASSERT(0, (kal_uint32)gpd_ptr, 0, 0);
        }
    }
#endif // TRAVERSE_GPD_ASSERT
}

/*---------------------------------------------------------------------------*
 * Exported API
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_lisr
 *
 * DESCRIPTION
 *   GDMA interrupt handler (LISR)
 *
 * CALLS
 *   It is called when GDMA interrupt is coming
 *
 * PARAMETERS
 *   v [in] GDMA interrupt ID.
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
void drv_gdma_lisr(kal_uint32 v)
{
    kal_uint32 saved_mask = 0, index = 0;

    ASSERT(GDMA_INTR_ID == v);
    IRQMask(GDMA_INTR_ID);

#ifdef GDMA_LISR_ONLY

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);

    g_l1gdma.intr_status[0] = DRV_Reg32(GDMA_GISAR0);
    g_l1gdma.intr_status[1] = DRV_Reg32(GDMA_GISAR1);
    DRV_WriteReg32(GDMA_GISAR0, g_l1gdma.intr_status[0]);
    DRV_WriteReg32(GDMA_GISAR1, g_l1gdma.intr_status[1]);

    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
    IRQClearInt(GDMA_INTR_ID);
    IRQUnmask(GDMA_INTR_ID);

    for (index = 0; index < GDMA_INT_TYPE_MAX; index++) {
        if (((index < GDMA_BD_DAT_CS_ERR) &&
            (g_l1gdma.cb_status[0] & (1 << index)) &&
            (g_l1gdma.intr_status[0] & (1 << index)))
            ||
            ((index >= GDMA_BD_DAT_CS_ERR) &&
            (g_l1gdma.cb_status[1] & (1 << (index - GDMA_BD_DAT_CS_ERR))) &&
            (g_l1gdma.intr_status[1] & (1 << (index - GDMA_BD_DAT_CS_ERR))))) {
            drv_gdma_get_cbinfo(index);
            g_l1gdma.intr_index = index;
            g_l1gdma.Callback[index](&g_l1gdma.cb_info);
            g_l1gdma.intr_cnt[index]++;
        }
    }

#else
    kal_activate_hisr(gdma_hisrid);
#endif
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_init
 *
 * DESCRIPTION
 *   This function is to reset the hardware GDMA module.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
void drv_gdma_init(void)
{
    kal_uint32 i;

    /* DCM Initial setting */
    //DCM_L1mBus2xDontUseL2Out(0);

    PDN_CLR(PDN_GDMA);

    for (i = 0; i < GDMA_INT_TYPE_MAX; i++) {
        g_l1gdma.Callback[i] = drv_default_callback;
    }

    g_l1gdma.chn_started = 0;

    IRQ_Register_LISR(GDMA_INTR_ID, drv_gdma_lisr, "L1_GDMA handler");
#if !defined(GDMA_LISR_ONLY)
    gdma_hisrid = kal_init_hisr(GDMA_HISR);
#endif
    IRQSensitivity(GDMA_INTR_ID, LEVEL_SENSITIVE);
    IRQClearInt(GDMA_INTR_ID);
    IRQUnmask(GDMA_INTR_ID);

#if 1
    DRV_WriteReg32_NPW(GDMA_AXI_CON, DEFAULT_GDMA_AXI_CON);
    PDN_SET(PDN_GDMA);
#endif

    g_l1gdma.ostd_handle = SleepDrv_GetHandle();
    //SleepDrv_SleepDisable(g_l1gdma.ostd_handle);
    PSGDMA_SPINLOCK_INIT;
    /*
     * Dump BB register
     */
    gdma_dump.regions = (kal_uint32*)gdma_dump_regions;
    gdma_dump.num = sizeof(gdma_dump_regions)/(sizeof(kal_uint32) * 3);
    gdma_dump.bbreg_dump_callback = gdma_bbreg_dump_callback;
    EX_REGISTER_BBREG_DUMP(&gdma_dump);

    g_l1gdma.inited = KAL_TRUE;
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_set_config
 *
 * DESCRIPTION
 *   This function is used to configure the GDMA.
 *
 * PARAMETERS
 *   gdmaCfg_p [in] Configuration information.
 *
 * RETURNS
 *   KAL_FALSE
 *   KAL_TRUE
 *
 *---------------------------------------------------------------------------*/
kal_bool drv_gdma_set_config(gdma_cfg_t *gdmaCfg_p)
{
    kal_uint8 chId;
    kal_uint32 bd_dat_cs_en_value = 0;
    kal_uint32 gpd_cs_en_value = 0;
    kal_uint32 fixed_mode = 0;
    kal_uint32 saved_mask = 0;
#if defined(FDMA_DEBUG_HISTORY)
    kal_uint32 caller = 0;
#endif

    if (gdmaCfg_p->gdma_sel_channel >= GDMA_CH_MAX) {
        return KAL_FALSE;
    }

    if (g_l1gdma.inited == KAL_FALSE) {
        drv_gdma_init();
    }

    /* PDN clear */
    FDMA_PDN_CLR(gdmaCfg_p->gdma_sel_channel);

    /* Channel n is being active */
    if (DRV_Reg32(GDMA_FDCSR(gdmaCfg_p->gdma_sel_channel)) & FDMA_STAT(gdmaCfg_p->gdma_sel_channel)) {
        // Channel is active, no need to call FDMA_PDN_SET()
        return KAL_FALSE;
    }

    API_LOGGING(GDMA_LOG_CONFIG, saved_mask, caller, gdmaCfg_p->gdma_sel_channel, gdmaCfg_p->gdma_gpd_addr.gdma_src_Gpd);

    chId = gdmaCfg_p->gdma_sel_channel;
    // clear started bit
    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    g_l1gdma.chn_started &= ~(1 << chId);
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);

    /* enable BD data checksum */
    if (gdmaCfg_p->gdma_bd_dat_cs_en == KAL_TRUE)
        bd_dat_cs_en_value = FDMA_BD_CS_EN(chId);

    /* enable GPD checksum */
    if (gdmaCfg_p->gdma_gpd_cs_en == KAL_TRUE)
        gpd_cs_en_value = FDMA_CS_EN(chId);

    if (gdmaCfg_p->gdma_mod == GDMA_MOD_MEMSET)
        fixed_mode = SA_FIXED;

    switch (gdmaCfg_p->gdma_mod)
    {
        case GDMA_MOD_LINKLIST:
            FDMA_ENTER_CRITICAL_SECTION(saved_mask);
            DRV_WriteReg32(GDMA_FDCSR(chId),(DRV_Reg32(GDMA_FDCSR(chId)) & ((chId % 2 == 0) ? 0xFFFFF0FF : 0xF0FFFFFF)) | bd_dat_cs_en_value | gpd_cs_en_value);
            FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
            DRV_WriteReg32(GDMA_FDSAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_src_Gpd);
            DRV_WriteReg32(GDMA_FDDAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_dst_Gpd);
            DRV_WriteReg32(GDMA_FDCR(chId), FDMA_BST_BUS(gdmaCfg_p->gdma_bus_width.src_bus_width, gdmaCfg_p->gdma_bus_width.dst_bus_width));
            drv_gdma_set_priority_int(chId, gdmaCfg_p->gdma_priority, KAL_FALSE);
            break;
        case GDMA_MOD_BASIC:
        case GDMA_MOD_MEMSET:
            FDMA_ENTER_CRITICAL_SECTION(saved_mask);
            DRV_WriteReg32(GDMA_FDCSR(chId), (DRV_Reg32(GDMA_FDCSR(chId)) & ((chId % 2 == 0) ? 0xFFFFF0FF : 0xF0FFFFFF)) | FDMA_MODE_BASIC(chId));
            FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
            DRV_WriteReg32(GDMA_FDCR(chId), FDMA_BST_BUS(gdmaCfg_p->gdma_bus_width.src_bus_width, gdmaCfg_p->gdma_bus_width.dst_bus_width) | fixed_mode);
            DRV_WriteReg32(GDMA_SIZE(chId), gdmaCfg_p->gdma_mod_basic_tx_size);
            DRV_WriteReg32(GDMA_FDSAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_src_Gpd);
            DRV_WriteReg32(GDMA_FDDAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_dst_Gpd);
            drv_gdma_set_priority_int(chId, gdmaCfg_p->gdma_priority, KAL_FALSE);
            break;
        case GDMA_MOD_DESCRIPTOR:
            FDMA_ENTER_CRITICAL_SECTION(saved_mask);
            DRV_WriteReg32(GDMA_FDCSR(chId), (DRV_Reg32(GDMA_FDCSR(chId)) & ((chId % 2 == 0) ? 0xFFFFF0FF : 0xF0FFFFFF)) | FDMA_MODE_DESCRPT(chId) | bd_dat_cs_en_value | gpd_cs_en_value);
            FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
            DRV_WriteReg32(GDMA_FDSAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_src_Gpd);
            DRV_WriteReg32(GDMA_FDDAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_dst_Gpd);
            DRV_WriteReg32(GDMA_FDCR(chId), FDMA_BST_BUS(gdmaCfg_p->gdma_bus_width.src_bus_width, gdmaCfg_p->gdma_bus_width.dst_bus_width));
            drv_gdma_set_priority_int(chId, gdmaCfg_p->gdma_priority, KAL_FALSE);
            break;
        default:
            break;
    }
    FDMA_PDN_SET(gdmaCfg_p->gdma_sel_channel);

    return KAL_TRUE;
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_start_cmd
 *
 * DESCRIPTION
 *   This function is to start or resume the assigned gdma channel.
 *
 * PARAMETERS
 *   chId   [in] Channel ID. A value of gdma_channel_type_e enumeratnion.
 *   cmd    [in] Start command. A value of gdma_start_cmd_type_e enumeration.
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
kal_bool drv_gdma_start_cmd(gdma_channel_type_e chId, gdma_start_cmd_type_e cmd)
{
    kal_uint32 saved_mask = 0;
#if defined(FDMA_DEBUG_HISTORY)
    kal_uint32 caller = 0;
#endif

    /* Channel n is being active */
    if ((cmd == GDMA_START) && (DRV_Reg32(GDMA_FDCSR(chId)) & FDMA_STAT(chId))) {
        // Channel is active, no need to call FDMA_PDN_SET()
        return KAL_FALSE;
    }
    /* Initialize GDMA */
    if (g_l1gdma.inited == KAL_FALSE) {
        drv_gdma_init();
    }
    /* START command is not allowed if channel is active */
    if ((cmd == GDMA_START) && (g_l1gdma.chn_started & (1 << chId))) {
        // Channel is active, no need to call FDMA_PDN_SET()
        return KAL_FALSE;
    }
    /* TODO : RESUME command only support for linked list mode */

    /* S/W lock sleep & PDN operation */
    FDMA_SW_LOCK(chId);
    FDMA_PDN_CLR(chId);

    API_LOGGING(GDMA_LOG_START, saved_mask, caller, chId, cmd);

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    DRV_WriteReg32(GDMA_GIMRK0, ~(g_l1gdma.intr_unmask[0]));
    DRV_WriteReg32(GDMA_GIMRK1, ~(g_l1gdma.intr_unmask[1]));
    DRV_WriteReg32_NPW(GDMA_AXI_CON, DEFAULT_GDMA_AXI_CON);
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
#if 1
    // If CH_03 and use basic mode, ADT user
    //if (chId == GDMA_CH_03 && ((DRV_Reg32(GDMA_FDCSR(GDMA_CH_03)) & FDMA_MODE_BASIC(GDMA_CH_03)) > 0))
    //    FDMA_SW_LOCK(chId);
    DRV_WriteReg32_NPW(GDMA_FDCR(chId), DRV_Reg32(GDMA_FDCR(chId)) | ((cmd == GDMA_START) ? FDMA_START : FDMA_RESUME));
#else
/* under construction !*/
/* under construction !*/
#endif

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    g_l1gdma.chn_started |= (1 << chId);
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);

    return KAL_TRUE;
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_stop_cmd
 *
 * DESCRIPTION
 *   This function is to stop the GDMA.
 *
 * PARAMETERS
 *   chId [in] Channel ID. A value of gdma_channel_type_e enumeratnion.
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
void drv_gdma_stop_cmd(gdma_channel_type_e chId)
{
    kal_uint32 saved_mask = 0;
#if defined(FDMA_DEBUG_HISTORY)
    kal_uint32 caller = 0;
#endif

    FDMA_PDN_CLR(chId);

    API_LOGGING(GDMA_LOG_STOP, saved_mask, caller, chId, GDMA_LOG_DUMMY);
    DRV_WriteReg32_NPW(GDMA_FDCR(chId), DRV_Reg32(GDMA_FDCR(chId)) | FDMA_STOP);

    /* Wait channel into inactive state */
    while ((DRV_Reg32(GDMA_FDCSR(chId)) & FDMA_STAT(chId)) > 0) {};

    // L1 LISR/HISR channes control lock sleep themselves
    //if (chId == GDMA_CH_03)
    //    FDMA_SW_UNLOCK(chId);
    /* Clear channel interrupt */
    drv_gdma_clear_intr(chId);

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    g_l1gdma.chn_started &= ~(1 << chId);
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
    FDMA_PDN_SET(chId);
    FDMA_SW_UNLOCK(chId);
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_set_priority
 *
 * DESCRIPTION
 *   This function is to set priority of a channel
 *
 * PARAMETERS
 *   chId       [in] Channel ID. A value of gdma_channel_type_e enumeratnion.
 *   Priority   [in] Priority ID. A value of gdma_priority_e.
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
#define GDMA_PRI_HIGH_VALUE     (0)
#define GDMA_PRI_MEDIAN_VALUE   (0x00007FFF)
#define GDMA_PRI_LOW_VALUE      (0x0000FFFF)
void drv_gdma_set_priority(gdma_channel_type_e chId, gdma_priority_e priority)
{
    drv_gdma_set_priority_int(chId, priority, KAL_TRUE);
}

void drv_gdma_set_priority_int(gdma_channel_type_e chId, gdma_priority_e priority, kal_bool pdn)
{
    if (pdn == KAL_TRUE)
        FDMA_PDN_CLR(chId);
    switch (priority)
    {
        case GDMA_PRI_HIGH:
            DRV_WriteReg32_NPW(GDMA_GPMTR(chId), GDMA_PRI_HIGH_VALUE);
            break;
        case GDMA_PRI_MEDIAN:
            DRV_WriteReg32_NPW(GDMA_GPMTR(chId), GDMA_PRI_MEDIAN_VALUE);
            break;
        case GDMA_PRI_LOW:
            DRV_WriteReg32_NPW(GDMA_GPMTR(chId), GDMA_PRI_LOW_VALUE);
            break;
        default:
            break;
    }
    if (pdn == KAL_TRUE)
        FDMA_PDN_SET(chId);
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_get_curGPD
 *
 * DESCRIPTION
 *   This function is to get current GPD src and dst address.
 *
 * PARAMETERS
 *   chId           [in] Channel ID. A value of gdma_channel_type_e enumeratnion.
 *   cur_gpd_addr   [out] Pointer to store GPD information.
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
void drv_gdma_get_curGPD(gdma_channel_type_e chId, gdma_gpd_addr_t *cur_gpd_addr)
{
    /* Check initialization */
    if (g_l1gdma.inited == KAL_FALSE) {
        drv_gdma_init();
    }

    FDMA_PDN_CLR(chId);
    if (cur_gpd_addr != NULL) {
        cur_gpd_addr->gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR(chId));
        cur_gpd_addr->gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR(chId));
    }
    FDMA_PDN_SET(chId);
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_get_status
 *
 * DESCRIPTION
 *   This function is to get gdma status (active or not).
 *
 * PARAMETERS
 *   chId [in] Channel ID. A value of gdma_channel_type_e enumeratnion.
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
gdma_status_type_e drv_gdma_get_status(gdma_channel_type_e chId)
{
#if defined(FDMA_DEBUG_HISTORY)
    kal_uint32 saved_mask = 0;
    kal_uint32 caller = 0;
#endif

    if (g_l1gdma.inited == KAL_FALSE) {
        drv_gdma_init();
    }

    API_LOGGING(GDMA_LOG_GET_STATUS, saved_mask, caller, chId, GDMA_LOG_DUMMY);
    FDMA_PDN_CLR(chId);
    if (DRV_Reg32(GDMA_FDCSR(chId)) & FDMA_STAT(chId)) {
        return GDMA_STARTED;
    } else {
        return GDMA_STOP;
    }
    FDMA_PDN_SET(chId);
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_calculate_bd_chksum
 *
 * DESCRIPTION
 *   This function implements checksum algorithm of BD data buffer.
 *
 * PARAMETERS
 *   data_ptr [in] Pointer to data buffer.
 *   data_len [in] Size of data_ptr in bytes.
 *
 * RETURNS
 *   Checksum value of data.
 *
 *---------------------------------------------------------------------------*/
kal_uint8 drv_gdma_calculate_bd_chksum(void *data_ptr, kal_uint32 data_len)
{
    kal_uint8 chksum = 0, *ptr = 0;
    kal_uint32 i = 0;

    ptr = (kal_uint8*)data_ptr;
    for (i = 0; i < data_len; i++, ptr++) {
        chksum = chksum ^ *ptr;
    }

    return chksum;
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_register_callback
 *
 * DESCRIPTION
 *   This function is used to register GDMA call back function.
 *
 * PARAMETERS
 *   cbType     [in] Interrupt type. A value of gdma_cbType_t.
 *   callback   [in] Pointer to callback function.
 *
 * RETURNS
 *   KAL_TRUE
 *   KAL_FALSE
 *
 *---------------------------------------------------------------------------*/
kal_bool drv_gdma_register_callback(gdma_cbType_t *cbType, gdma_pcb_f callback)
{
    kal_uint32 saved_mask = 0;

    if (callback == NULL || cbType == NULL)
        return KAL_FALSE;

    if ((cbType->gdma_int_type + cbType->gdma_channel) >= GDMA_INT_TYPE_MAX)
        return KAL_FALSE;

    if (g_l1gdma.inited == KAL_FALSE) {
        drv_gdma_init();
    }

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    g_l1gdma.Callback[cbType->gdma_int_type + cbType->gdma_channel] = callback;
    if (cbType->gdma_int_type < GDMA_BD_DAT_CS_ERR) {
        g_l1gdma.cb_status[0] |= (0x1 << (cbType->gdma_int_type + cbType->gdma_channel));
        g_l1gdma.intr_unmask[0] |= (0x1 << (cbType->gdma_int_type + cbType->gdma_channel));
    } else {
        g_l1gdma.cb_status[1] |= (0x1 << (cbType->gdma_int_type - GDMA_BD_DAT_CS_ERR + cbType->gdma_channel));
        g_l1gdma.intr_unmask[1] |= (0x1 << (cbType->gdma_int_type - GDMA_BD_DAT_CS_ERR + cbType->gdma_channel));
    }
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);

    return KAL_TRUE;
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_clear_intr
 *
 * DESCRIPTION
 *   This function is used to clear a channel's interrupt status.
 *
 * PARAMETERS
 *   chId [in] Channel ID. A value of gdma_channel_type_e enumeratnion.
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
void drv_gdma_clear_intr(gdma_channel_type_e chId)
{
    kal_uint32 saved_mask = 0;

    FDMA_PDN_CLR(chId);
    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    DRV_WriteReg32(GDMA_GISAR0, (0x11111111 << (kal_uint32)chId));
    DRV_WriteReg32(GDMA_GISAR1, (0x1 << (kal_uint32)chId));
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
    FDMA_PDN_SET(chId);
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_clear_all_intr
 *
 * DESCRIPTION
 *   This function is used to clear all GDMA interrupt status.
 *   This function is for internal usage only.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
void drv_gdma_clear_all_intr()
{
    kal_uint32 intr_sts = 0;
    kal_uint32 saved_mask = 0;

    FDMA_ENTER_CRITICAL_SECTION(saved_mask);
    intr_sts = DRV_Reg32(GDMA_GISAR0);
    DRV_WriteReg32(GDMA_GISAR0, intr_sts);
    intr_sts = DRV_Reg32(GDMA_GISAR1);
    DRV_WriteReg32(GDMA_GISAR1, intr_sts);
    FDMA_LEAVE_CRITICAL_SECTION(saved_mask);
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_pre_start
 *
 * DESCRIPTION
 *   This function is used to config NECESSARY bus settings before starting
 *   GDMA.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
void drv_gdma_pre_start(gdma_channel_type_e chId)
{
#if 0
#if defined(FDMA_DEBUG_HISTORY)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_post_stop
 *
 * DESCRIPTION
 *   This function is used to config NECESSARY bus settings after GDMA transfer
 *   is done.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
void drv_gdma_post_stop(gdma_channel_type_e chId)
{
#if defined(FDMA_DEBUG_HISTORY)
    kal_uint32 saved_mask = 0;
    kal_uint32 caller = 0;
#endif

    API_LOGGING(GDMA_LOG_POST_STOP, saved_mask, caller, chId, GDMA_LOG_DUMMY);
    FDMA_PDN_SET(chId);
    FDMA_SW_UNLOCK(chId);
}

void drv_gdma_lock_sleep()
{
    //SleepDrv_SleepDisable(g_l1gdma.ostd_handle2);
}

void drv_gdma_unlock_sleep()
{
    //SleepDrv_SleepEnable(g_l1gdma.ostd_handle2);
}

void drv_gdma_get_cbinfo(kal_uint32 int_idx)
{
    if (int_idx < GDMA_DST_DONE)
    {
        g_l1gdma.cb_info.gdma_int_type = GDMA_SRC_DONE;
        g_l1gdma.cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR(int_idx));
        g_l1gdma.cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR(int_idx));
    }
    else if (int_idx < GDMA_SRC_QUE_EMPTY)
    {
        g_l1gdma.cb_info.gdma_int_type = GDMA_DST_DONE;
        g_l1gdma.cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx - GDMA_DST_DONE)));
        g_l1gdma.cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx - GDMA_DST_DONE)));
    }
    else if (int_idx < GDMA_DST_QUE_EMPTY)
    {
        g_l1gdma.cb_info.gdma_int_type = GDMA_SRC_QUE_EMPTY;
        g_l1gdma.cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx - GDMA_SRC_QUE_EMPTY)));
        g_l1gdma.cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx - GDMA_SRC_QUE_EMPTY)));
    }
    else if (int_idx < GDMA_LEN_ERR)
    {
        g_l1gdma.cb_info.gdma_int_type = GDMA_DST_QUE_EMPTY;
        g_l1gdma.cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx - GDMA_DST_QUE_EMPTY)));
        g_l1gdma.cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx - GDMA_DST_QUE_EMPTY)));
    }
    else if (int_idx < GDMA_ALO_LEN_ERR)
    {
        g_l1gdma.cb_info.gdma_int_type = GDMA_LEN_ERR;
        g_l1gdma.cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx - GDMA_LEN_ERR)));
        g_l1gdma.cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx - GDMA_LEN_ERR)));
    }
    else if (int_idx < GDMA_BD_CS_ERR)
    {
        g_l1gdma.cb_info.gdma_int_type = GDMA_ALO_LEN_ERR;
        g_l1gdma.cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx - GDMA_ALO_LEN_ERR)));
        g_l1gdma.cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx - GDMA_ALO_LEN_ERR)));
    }
    else if (int_idx < GDMA_GPD_CS_ERR)
    {
        g_l1gdma.cb_info.gdma_int_type = GDMA_BD_CS_ERR;
        g_l1gdma.cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx - GDMA_BD_CS_ERR)));
        g_l1gdma.cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx - GDMA_BD_CS_ERR)));
    }
    else if (int_idx < GDMA_BD_DAT_CS_ERR)
    {
        g_l1gdma.cb_info.gdma_int_type = GDMA_GPD_CS_ERR;
        g_l1gdma.cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx - GDMA_GPD_CS_ERR)));
        g_l1gdma.cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx - GDMA_GPD_CS_ERR)));
    }
    else
    {
        g_l1gdma.cb_info.gdma_int_type = GDMA_BD_DAT_CS_ERR;
        g_l1gdma.cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx - GDMA_BD_DAT_CS_ERR)));
        g_l1gdma.cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx - GDMA_BD_DAT_CS_ERR)));
    }
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_hisr
 *
 * DESCRIPTION
 *   GDMA HISR.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
void drv_gdma_hisr(void)
{
    kal_uint32 savedMask;
    kal_uint32 index;

    savedMask = SaveAndSetIRQMask();

    g_l1gdma.intr_status[0] = DRV_Reg32(GDMA_GISAR0);
    g_l1gdma.intr_status[1] = DRV_Reg32(GDMA_GISAR1);
    DRV_WriteReg32(GDMA_GISAR0, g_l1gdma.intr_status[0]);
    DRV_WriteReg32(GDMA_GISAR1, g_l1gdma.intr_status[1]);

    RestoreIRQMask(savedMask);

    IRQClearInt(GDMA_INTR_ID);
    IRQUnmask(GDMA_INTR_ID);

    for (index = 0; index < GDMA_INT_TYPE_MAX; index++) {
        if (((index < GDMA_BD_DAT_CS_ERR) &&
            (g_l1gdma.cb_status[0] & (1 << index)) &&
            (g_l1gdma.intr_status[0] & (1 << index)))
            ||
            ((index >= GDMA_BD_DAT_CS_ERR) &&
            (g_l1gdma.cb_status[1] & (1 << index)) &&
            (g_l1gdma.intr_status[1] & (1 << index)))) {
            drv_gdma_get_cbinfo(index);
            g_l1gdma.Callback[index](&g_l1gdma.cb_info);
        }
    }

    for (index = 0; index < GDMA_CH_MAX; index++) {
        if(DRV_Reg32(GDMA_FDCSR(index)) & FDMA_MODE_BASIC(index)) {
            //Basic mode
            if(g_l1gdma.intr_status[0] & FDMA_DST_DONE(index)) {
                //FDMA_SW_UNLOCK(index);
                //FDMA_PDN_SET(index);
            }
        } else {
            //Link-list mdoe or descriptor mode
            if(g_l1gdma.intr_status[0] & FDMA_QE_DST_INT(index)) {
                //FDMA_SW_UNLOCK(index);
                //FDMA_PDN_SET(index);
            }
        }
    }
}

#define MD_PS_PERI_CKEN             ((0xF0120000+0x48))
    #define CG_PSGDMA               (1 << 1)

#define DRVPDN_REG(addr)            *(volatile kal_uint32 *)(addr)
#define DRVPDN_PS_MDPERI_ON(module) DRVPDN_REG(MD_PS_PERI_CKEN) |= (CG_ ## module)

void drv_psgdma_pdn_clr(kal_uint32 channel)
{
    SPINLOCK_DECLARE;

    PSGDMA_SPIN_LOCK(status);
    // Update global flag
    PSGDMA_FDMA_PDN_CLR_FLAG |= (1 << channel);
    // Ungate PSGDMA clock
    DRVPDN_PS_MDPERI_ON(PSGDMA);
    PSGDMA_SPIN_UNLOCK(status);
}

#else /*!defined(DRV_L1GDMA_OFF)*/

#endif /*!defined(DRV_L1GDMA_OFF)*/


