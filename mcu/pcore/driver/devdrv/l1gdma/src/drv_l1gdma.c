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

#include "l1gdma_reg.h"
#include "drv_l1gdma.h"
#include "intrCtrl.h"

#include "dcl.h"
#include "drv_hisr.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drvpdn.h"

#if !defined(DRV_L1GDMA_OFF)

/*****************************************************************************
 *                       SYMBOL Definition                                   *
 *****************************************************************************/

//#define GDMA_PDN_SUPPORT
#define GDMA_LISR_ONLY

//#define GDMA_PF_SUPPORT
//#ifdef GDMA_PF_SUPPORT
//    #define GDMA_PF_1X
//    #define GDMA_PF_2X
//#endif

#define FDMA_BST_BUS(src,dst)   (BST_SIZE_64 | DST_BUS_WIDTH(dst) | SRC_BUS_WIDTH(src))
#define DEFAULT_FDMA_BST_BUS    (BST_SIZE_64 | DST_BUS_WIDTH_4 | SRC_BUS_WIDTH_4)

#ifdef GDMA_PF_SUPPORT
    #ifdef GDMA_PF_1X
        #define DEFAULT_GDMA_AXI_CON    (AHB2AXI_BUFFERABLE_EN | AHB2AXI_MERGE_EN | PF_ENABLE)
    #else
        #define DEFAULT_GDMA_AXI_CON    (AHB2AXI_BUFFERABLE_EN | AHB2AXI_MERGE_EN | PF_ENABLE | PF_LEN_SEL)
    #endif
#else // GDMA_PF_SUPPORT
    #define DEFAULT_GDMA_AXI_CON        (AHB2AXI_BUFFERABLE_EN | AHB2AXI_MERGE_EN)
#endif // GDMA_PF_SUPPORT

#define L1_GDMA_CG_SET (L1_BASE_MADDR_L1MCU_CONF+0x4)
#define L1_GDMA_CG_CLR (L1_BASE_MADDR_L1MCU_CONF+0x8)

/*****************************************************************************
 *                       Global/External Variable                            *
 *****************************************************************************/

#if defined(GDMA_PDN_SUPPORT)
static kal_uint32   fdma_pdn_clr_flag = 0;
static kal_uint32   hdma_pdn_clr_flag = 0;
static kal_bool     gdma_pdn_set = KAL_TRUE;
#endif


/*****************************************************************************
 *                       function declaration                                *
 *****************************************************************************/

//function declaration.
void drv_l1gdma_hisr(void);
void drv_l1gdma_get_cbinfo(kal_uint32 int_idx);

/*****************************************************************************
 *                       LISR/HISR/Callback Functions                        *
 *****************************************************************************/

/*****************************************************************************
 *                       Basic Driver Implementation                         *
 *****************************************************************************/

/*---------------------------------------------------------------------------*
 * FakeAPI for TD build
 *---------------------------------------------------------------------------*/

//void DMA_Config_Internal(kal_uint8 dma_no, void *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start){}
//kal_uint8 DMA_GetChannel(kal_uint32 DMA_CODE){return 0;}

/*---------------------------------------------------------------------------*
 * PDN Support API
 *---------------------------------------------------------------------------*/
#if defined(GDMA_PDN_SUPPORT)
void GDMA_PDN_CHK(void) {
    if(gdma_pdn_set && (fdma_pdn_clr_flag || hdma_pdn_clr_flag)) {
        PDN_CLR(PDN_MDGDMA);
        gdma_pdn_set = KAL_FALSE;
    }
    else if(!gdma_pdn_set && !fdma_pdn_clr_flag && !hdma_pdn_clr_flag) {
        PDN_SET(PDN_MDGDMA);
        gdma_pdn_set = KAL_TRUE;
    }
}

void FDMA_PDN_SET(kal_uint32 channel) {
    fdma_pdn_clr_flag &= (~(1 << channel));
    GDMA_PDN_CHK();
}

void FDMA_PDN_CLR(kal_uint32 channel) {
    fdma_pdn_clr_flag |= (1 << channel);
    GDMA_PDN_CHK();
}

kal_uint32 FDMA_PDN_STS(kal_uint32 channel) {
    if(fdma_pdn_clr_flag & (1 << channel)) {
        return 0;
    }
    return 1;
}

void HDMA_PDN_SET(kal_uint32 channel) {
    hdma_pdn_clr_flag &= (~(1 << channel));
    GDMA_PDN_CHK();
}

void HDMA_PDN_CLR(kal_uint32 channel) {
    hdma_pdn_clr_flag |= (1 << channel);
    GDMA_PDN_CHK();
}

kal_uint32 HDMA_PDN_STS(kal_uint32 channel) {
    if(hdma_pdn_clr_flag & (1 << channel)) {
        return 0;
    }
    return 1;
}
#else //GDMA_PDN_SUPPORT
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif //GDMA_PDN_SUPPORT

/*---------------------------------------------------------------------------*
 * Debug
 *---------------------------------------------------------------------------*/

typedef struct l1gdma_s {
    volatile kal_bool       inited;
    volatile kal_uint8      chn_started;
    volatile kal_uint32     intr_status[2];
    volatile kal_uint32     intr_unmask[2];
    volatile kal_uint32     cb_status[2];
    l1gdma_cbParameter_t    cb_info;
    volatile kal_uint32 intr_index;
} l1gdma_t;

static l1gdma_t g_l1gdma = {0};

/*---------------------------------------------------------------------------*
 * Utility API
 *---------------------------------------------------------------------------*/

__inline void pdn_clr()
{
    DRV_WriteReg32(L1_GDMA_CG_CLR, (1 << 4));
}

/*---------------------------------------------------------------------------*
 * FUNCTION                                                            
 *   drv_l1gdma_lisr
 *
 * DESCRIPTION                                                           
 *   GDMA interrupt handler (LISR)
 *
 * CALLS  
 *   It is called when L1_GDMA interrupt is coming
 *
 * PARAMETERS
 *   None
 *   
 * RETURNS
 *   None
 *---------------------------------------------------------------------------*/
void drv_l1gdma_lisr(kal_uint32 v)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef GDMA_LISR_ONLY
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
#else
/* under construction !*/
#endif
#endif
}


/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_l1gdma_ex_init
 *
 * DESCRIPTION
 *   This function is to initial L1_GDMA s/w module in exception flow.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   KAL_TRUE
 *   KAL_FALSE
 *---------------------------------------------------------------------------*/
kal_bool drv_l1gdma_ex_init(void)
{
    kal_uint32 i = 0;

    /* Check all channels are in idle state */
    for (i = 0; i < GDMA_CH_MAX; i++) {
        if ((DRV_Reg32(GDMA_FDCSR(i)) & FDMA_STAT(i))) {
            return KAL_FALSE;
        }
    }
    // Disable PFB
    DRV_WriteReg32(GDMA_AXI_CON, DEFAULT_GDMA_AXI_CON);
    g_l1gdma.inited = KAL_TRUE;

    return KAL_TRUE;
}


void drv_l1gdma_clear_status(l1gdma_channel_type_e chId)
{
    DRV_WriteReg32(GDMA_GISAR0, (0x11111111 << chId));
}


/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_l1gdma_init
 *
 * DESCRIPTION
 *   This function is to initial L1_GDMA s/w module.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *---------------------------------------------------------------------------*/
void drv_l1gdma_init(void)
{
    g_l1gdma.chn_started = 0;

    /*
     * We config L1_GDMA only if PCore only to make sure we don't corrupt L1Core's setting.
     */
#ifdef __PCORE_ONLY__
    // Temp solution to un-gate MDL1_GDMA clock
    #define L1GDMA_CG_BASE  (L1_BASE_MADDR_L1MCU_CONF + 0x8)
    #define L1GDMA_CG_BIT   (1 << 4)
    DRV_WriteReg32(L1GDMA_CG_BASE, L1GDMA_CG_BIT);
    // AXI configuration settings
    DRV_WriteReg32(GDMA_AXI_CON, DEFAULT_GDMA_AXI_CON);
#endif

    g_l1gdma.inited = KAL_TRUE;

#if defined(GDMA_PDN_SUPPORT)
    gdma_pdn_set = PDN_STS(PDN_MDGDMA)?KAL_TRUE: KAL_FALSE;
#endif
}


/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_l1gdma_set_config
 *
 * DESCRIPTION
 *   This function is to configure the L1_GDMA. (channel tx mode, src address, dst address, tx size, bst/bus width)
 *
 * PARAMETERS
 *   l1gdma_cfg_t *gdmaCfg_p
 *
 * RETURNS
 *   KAL_TRUE
 *   KAL_FALSE
 *---------------------------------------------------------------------------*/
kal_bool drv_l1gdma_set_config(l1gdma_cfg_t *gdmaCfg_p)
{
    kal_uint8 chId;
    kal_uint32 bd_dat_cs_en_value = 0;

    if (gdmaCfg_p->gdma_sel_channel >= GDMA_CH_MAX) {
        return KAL_FALSE;
    }
#if 0
/* under construction !*/
#endif
    pdn_clr();

    if (g_l1gdma.inited == KAL_FALSE) {
        drv_l1gdma_init();
    }

    //channel n is being active
    if (DRV_Reg32(GDMA_FDCSR(gdmaCfg_p->gdma_sel_channel)) & FDMA_STAT(gdmaCfg_p->gdma_sel_channel)) {
        //No need to call FDMA_PDN_SET()
        return KAL_FALSE;
    }

    chId = gdmaCfg_p->gdma_sel_channel;
    // clear started bit
    g_l1gdma.chn_started &= ~(1 << chId);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    switch (gdmaCfg_p->gdma_mod)
    {
        case GDMA_MOD_LINKLIST:
            DRV_WriteReg32(GDMA_FDCSR(chId), (DRV_Reg32(GDMA_FDCSR(chId)) & ((chId % 2 == 0) ? 0xFFFFF9FF : 0xF9FFFFFF)) | bd_dat_cs_en_value); //set list mode
            //DRV_Reg32(GDMA_FDCSR(chId < 2 ? 0 : 1)) &= (((chId % 2 == 0) ? 0xFFFFF9FF : 0xF9FFFFFF) | FDMA_BD_CS_EN(chId));
            DRV_WriteReg32(GDMA_FDSAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_src_Gpd); //set src GPD address
            DRV_WriteReg32(GDMA_FDDAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_dst_Gpd); //set dst GPD address
            DRV_WriteReg32(GDMA_FDCR(chId), FDMA_BST_BUS(gdmaCfg_p->gdma_bus_width.src_bus_width, gdmaCfg_p->gdma_bus_width.dst_bus_width)); //set bst/bus width
#if 0
/* under construction !*/
#endif
            break;
        case GDMA_MOD_BASIC:
            // set basic mode
            DRV_WriteReg32(GDMA_FDCSR(chId), (DRV_Reg32(GDMA_FDCSR(chId)) & ((chId % 2 == 0) ? 0xFFFFF9FF : 0xF9FFFFFF)) | FDMA_MODE_BASIC(chId));
            // set burst/bus size
            DRV_WriteReg32(GDMA_FDCR(chId), FDMA_BST_BUS(gdmaCfg_p->gdma_bus_width.src_bus_width, gdmaCfg_p->gdma_bus_width.dst_bus_width));
            // set data size
            DRV_WriteReg32(GDMA_SIZE(chId), gdmaCfg_p->gdma_mod_basic_tx_size);
            DRV_WriteReg32(GDMA_FDSAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_src_Gpd);
            DRV_WriteReg32(GDMA_FDDAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_dst_Gpd);
#if 0
/* under construction !*/
#endif
            break;
        case GDMA_MOD_DESCRIPTOR:
            DRV_WriteReg32(GDMA_FDCSR(chId), (DRV_Reg32(GDMA_FDCSR(chId)) & ((chId % 2 == 0) ? 0xFFFFF9FF : 0xF9FFFFFF)) | FDMA_MODE_DESCRPT(chId) | bd_dat_cs_en_value); //set descriptor mode
            DRV_WriteReg32(GDMA_FDSAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_src_Gpd); //set src GPD address
            DRV_WriteReg32(GDMA_FDDAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_dst_Gpd); //set dst GPD address
            DRV_WriteReg32(GDMA_FDCR(chId), FDMA_BST_BUS(gdmaCfg_p->gdma_bus_width.src_bus_width, gdmaCfg_p->gdma_bus_width.dst_bus_width)); //set bst/bus width
#if 0
/* under construction !*/
#endif
            break;
        default:
            break;
    }
#if 0
/* under construction !*/
#endif
    return KAL_TRUE;
}


/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_l1gdma_start_cmd
 *
 * DESCRIPTION
 *   This function is to start or resume the assigned L1_GDMA channel.
 *
 * PARAMETERS
 *   l1gdma_start_cmd_type_e cmd
 *
 * RETURNS
 *   KAL_TRUE
 *   KAL_FALSE
 *---------------------------------------------------------------------------*/
kal_bool drv_l1gdma_start_cmd(l1gdma_channel_type_e chId, l1gdma_start_cmd_type_e cmd)
{
#if 0
/* under construction !*/
#endif
    pdn_clr();

    /* channel n is being active */
    if ((cmd == GDMA_START) && (DRV_Reg32(GDMA_FDCSR(chId)) & FDMA_STAT(chId))) {
        //No need to call FDMA_PDN_SET()
        return KAL_FALSE;
    }
    /* Initialize GDMA */
    if (g_l1gdma.inited== KAL_FALSE) {
        drv_l1gdma_init();
    }
    /* START command is not allowed if channel is active */
    if ((cmd == GDMA_START) && (g_l1gdma.chn_started & (1<<chId))) {
#if 0
/* under construction !*/
#endif
        return KAL_FALSE;
    }
    /* TODO : RESUME command only support for linked list mode */

    DRV_WriteReg32(GDMA_GIMRK0, ~(g_l1gdma.intr_unmask[0]));
    DRV_WriteReg32(GDMA_GIMRK1, ~(g_l1gdma.intr_unmask[1]));
#if 1
    DRV_WriteReg32_NPW(GDMA_FDCR(chId), DRV_Reg32(GDMA_FDCR(chId)) | ((cmd == GDMA_START) ? FDMA_START : FDMA_RESUME));
#else
/* under construction !*/
/* under construction !*/
#endif

    g_l1gdma.chn_started |= (1 << chId);

    return KAL_TRUE;
}


/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_l1gdma_stop_cmd
 *
 * DESCRIPTION
 *   This function is to stop the L1_GDMA.
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *---------------------------------------------------------------------------*/
void drv_l1gdma_stop_cmd(l1gdma_channel_type_e chId)
{
#if 0
/* under construction !*/
/* under construction !*/
#endif
    pdn_clr();

#if 1
    DRV_WriteReg32_NPW(GDMA_FDCR(chId), DRV_Reg32(GDMA_FDCR(chId)) | FDMA_STOP);
#else
/* under construction !*/
#endif
    g_l1gdma.chn_started &= ~(1 << chId);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_l1gdma_set_priority
 *
 * DESCRIPTION
 *   This function is to set priority of a channel
 *
 * PARAMETERS
 *   chId [in] Channel ID
 *   Priority [in] Priority ID. Value of l1gdma_priority_e.
 *
 * RETURNS
 *   None
 *---------------------------------------------------------------------------*/
#define GDMA_PRI_HIGH_VALUE     (0)
#define GDMA_PRI_MEDIAN_VALUE   (0x00007FFF)
#define GDMA_PRI_LOW_VALUE      (0x0000FFFF)
void drv_l1gdma_set_priority(l1gdma_channel_type_e chId, l1gdma_priority_e priority)
{
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
}


/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_l1gdma_get_curGPD
 *
 * DESCRIPTION
 *   This function is to get current GPD src and dst address.
 *
 * PARAMETERS
 *   l1gdma_gpd_addr_t *cur_gpd_addr
 *
 * RETURNS
 *   None
 *---------------------------------------------------------------------------*/
void drv_l1gdma_get_curGPD(l1gdma_channel_type_e chId, l1gdma_gpd_addr_t *cur_gpd_addr)
{
#if 0
/* under construction !*/
#endif

    if (g_l1gdma.inited == KAL_FALSE) {
        drv_l1gdma_init();
    }
#if 0
/* under construction !*/
/* under construction !*/
#endif
    if (cur_gpd_addr != NULL) {
        cur_gpd_addr->gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR(chId));
        cur_gpd_addr->gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR(chId));
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_l1gdma_get_status
 *
 * DESCRIPTION
 *   This function is to get L1_GDMA status (active or not).
 *
 * PARAMETERS
 *   l1gdma_channel_type_e ch_type
 *
 * RETURNS
 *   None
 *---------------------------------------------------------------------------*/
l1gdma_status_type_e drv_l1gdma_get_status(l1gdma_channel_type_e chId)
{
    pdn_clr();
#if 0
/* under construction !*/
#endif
    if (DRV_Reg32(GDMA_FDCSR(chId)) & FDMA_STAT(chId)) {
        return GDMA_STARTED;
    } else {
#if 0
/* under construction !*/
#endif
        return GDMA_STOP;
    }
}


/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_l1gdma_register_callback
 *
 * DESCRIPTION
 *   This function is used to register L1_GDMA call back function.
 *
 * PARAMETERS
 *   pwrsv_pcbType_e cbtype
 *   l1gdma_pcb_f callback
 *
 * RETURNS
 *   KAL_TRUE
 *   KAL_FALSE
 *---------------------------------------------------------------------------*/
kal_bool drv_l1gdma_register_callback(l1gdma_cbType_t *cbType, l1gdma_pcb_f callback)
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
#endif
    return KAL_TRUE;
}


void drv_l1gdma_get_cbinfo(kal_uint32 int_idx)
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
    else if (int_idx < GDMA_GPD_CS_ERR)
    {
        g_l1gdma.cb_info.gdma_int_type = GDMA_GPD_CS_ERR;
        g_l1gdma.cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx - GDMA_GPD_CS_ERR)));
        g_l1gdma.cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx - GDMA_GPD_CS_ERR)));
    }
    else
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    }
}


/*---------------------------------------------------------------------------*
 * FUNCTION                                                            
 *   drv_l1gdma_hisr
 *
 * DESCRIPTION                                                           
 *   L1_GDMA Callback HISR
 *
 * CALLS
 *
 * PARAMETERS
 *   void
 *
 * RETURNS
 *   None
 *---------------------------------------------------------------------------*/
void drv_l1gdma_hisr(void)
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
#endif
}

#else /*!defined(DRV_L1GDMA_OFF)*/

#endif /*!defined(DRV_L1GDMA_OFF)*/


