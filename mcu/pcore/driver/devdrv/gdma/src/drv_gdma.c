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
#include "spinlock.h"

#include "gdma_reg.h"
#include "drv_gdma.h"
#include "intrCtrl.h"

#include "dcl.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drvpdn.h"

#if !defined(DRV_GDMA_OFF)

/*****************************************************************************
 *                       SYMBOL Definition                                   *
 *****************************************************************************/

#define BST_SIZE_OFFSET 13
#define BST_SIZE_64     (6 << BST_SIZE_OFFSET)
#define BST_SIZE_32     (5 << BST_SIZE_OFFSET)
#define BST_SIZE_16     (4 << BST_SIZE_OFFSET)
#define BST_SIZE_8      (3 << BST_SIZE_OFFSET)
#define BST_SIZE_4      (2 << BST_SIZE_OFFSET)

#define DST_BUS_WIDTH_OFFSET 6
#define DST_BUS_WIDTH_4     (2 << DST_BUS_WIDTH_OFFSET)
#define DST_BUS_WIDTH_2     (1 << DST_BUS_WIDTH_OFFSET)
#define DST_BUS_WIDTH_1     (0 << DST_BUS_WIDTH_OFFSET)
#define DST_BUS_WIDTH(x)    ((x) << DST_BUS_WIDTH_OFFSET)

#define SRC_BUS_WIDTH_OFFSET 4
#define SRC_BUS_WIDTH_4     (2 << SRC_BUS_WIDTH_OFFSET)
#define SRC_BUS_WIDTH_2     (1 << SRC_BUS_WIDTH_OFFSET)
#define SRC_BUS_WIDTH_1     (0 << SRC_BUS_WIDTH_OFFSET)
#define SRC_BUS_WIDTH(x)    ((x) << SRC_BUS_WIDTH_OFFSET)

#define FDMA_BST_BUS(src,dst)   (BST_SIZE_64 | DST_BUS_WIDTH(dst) | SRC_BUS_WIDTH(src))
#define DEFAULT_FDMA_BST_BUS    (BST_SIZE_64 | DST_BUS_WIDTH_4 | SRC_BUS_WIDTH_4)

/**
 * Support PDN operations or not
 */
#define GDMA_PDN_SUPPORT

/**
 * PSGDMA PDN API cross core usage support
 */
#define GDMA_PDN_SUPPORT_CC

/*****************************************************************************
 *                       Global/External Variable                            *
 *****************************************************************************/

static gdma_pcb_f   gdmaCallback[GDMA_INT_TYPE_MAX];
static kal_uint32   gdmaCB_status = 0;
static kal_uint32   gdma_int_status = 0;
static kal_uint32   gdma_int_unmask = 0;
static kal_uint8    gdma_init_flag = 0;
static kal_uint8    gdma_start_trigger;
static gdma_cbParameter_t gdma_cb_info;

#if defined(GDMA_PDN_SUPPORT_CC)
    DEFINE_NC_SHARED_VAR_ASSIGN(kal_uint32, ps_fdma_pdn_clr_flag, 0)
    #define FDMA_PDN_CLR_FLAG   (SHARED_VAR(ps_fdma_pdn_clr_flag))
#if defined(__KAL_CROSS_CORE_SUPPORT__)
    DEFINE_NC_SHARED_VAR(spinlock_t, ps_gdma_pdn_lock)
    #define PSGDMA_PDN_LOCK     (SHARED_VAR(ps_gdma_pdn_lock))
#endif // __KAL_CROSS_CORE_SUPPORT__
#else // GDMA_PDN_SUPPORT_CC
    #define FDMA_PDN_CLR_FLAG   (ps_fdma_pdn_clr_flag)
#endif // GDMA_PDN_SUPPORT_CC

#if defined(GDMA_PDN_SUPPORT)
    #if !defined(GDMA_PDN_SUPPORT_CC)
        static kal_uint32   ps_fdma_pdn_clr_flag = 0;
    #endif // GDMA_PDN_SUPPORT_CC
    static kal_uint32   hdma_pdn_clr_flag = 0;
    static kal_bool     gdma_pdn_set = KAL_TRUE;
#endif

static kal_hisrid gdma_hisrid;

/*****************************************************************************
 *                       Function Declaration                                *
 *****************************************************************************/

void drv_gdma_hisr(void);

/*****************************************************************************
 *                       LISR/HISR/Callback Functions                        *
 *****************************************************************************/

static void drv_default_callback(gdma_cbParameter_t *gpd_info)
{
    kal_uint32 ASSERT_IN_GDMA_DEFAULT_CALLBACK = 0;
    ASSERT(ASSERT_IN_GDMA_DEFAULT_CALLBACK); 
    return;
}

/*****************************************************************************
 *                       Basic Driver Implementation                         *
 *****************************************************************************/

/*---------------------------------------------------------------------------*
 * Macros
 *---------------------------------------------------------------------------*/

/* Critical Session */
#define MDGDMA_ENTER_CRITICAL_SECTION(status_irq)     status_irq = SaveAndSetIRQMask();
#define MDGDMA_LEAVE_CRITICAL_SECTION(status_irq)     RestoreIRQMask(status_irq);

/* Spinlock */
#if defined(GDMA_PDN_SUPPORT_CC)
    #if defined(__KAL_CROSS_CORE_SUPPORT__)
        #define SPINLOCK_DECLARE                kal_uint32 status = 0
        #define MDGDMA_SPINLOCK_INIT            spinlock_init(&(PSGDMA_PDN_LOCK))
        #define MDGDMA_SPIN_LOCK(status)        status = spin_lock(&(PSGDMA_PDN_LOCK))
        #define MDGDMA_SPIN_UNLOCK(status)      spin_unlock(&(PSGDMA_PDN_LOCK), status)
    #else
        #define SPINLOCK_DECLARE
        #define MDGDMA_SPINLOCK_INIT
        #define MDGDMA_SPIN_LOCK(status)
        #define MDGDMA_SPIN_UNLOCK(status)
    #endif
#else // GDMA_PDN_SUPPORT_CC
    #define SPINLOCK_DECLARE                kal_uint32 status = 0
    #define MDGDMA_SPIN_LOCK(status)        MDGDMA_ENTER_CRITICAL_SECTION(status)
    #define MDGDMA_SPIN_UNLOCK(status)      MDGDMA_LEAVE_CRITICAL_SECTION(status)
#endif // GDMA_PDN_SUPPORT_CC

/*---------------------------------------------------------------------------*
 * PDN Support API
 *---------------------------------------------------------------------------*/

#if defined(GDMA_PDN_SUPPORT)

void GDMA_PDN_CHK(void)
{
    SPINLOCK_DECLARE;

    MDGDMA_SPIN_LOCK(status);
    if (gdma_pdn_set && (FDMA_PDN_CLR_FLAG || hdma_pdn_clr_flag)) {
        PDN_CLR(PDN_GDMA);
        gdma_pdn_set = KAL_FALSE;
    }
    else if(!gdma_pdn_set && !FDMA_PDN_CLR_FLAG && !hdma_pdn_clr_flag) {
        PDN_SET(PDN_GDMA);
        gdma_pdn_set = KAL_TRUE;
    }
    MDGDMA_SPIN_UNLOCK(status);
}

void FDMA_PDN_SET(kal_uint32 channel)
{
    SPINLOCK_DECLARE;

    MDGDMA_SPIN_LOCK(status);
    FDMA_PDN_CLR_FLAG &= (~(1 << channel));
    MDGDMA_SPIN_UNLOCK(status);
    GDMA_PDN_CHK();
}

void FDMA_PDN_CLR(kal_uint32 channel)
{
    SPINLOCK_DECLARE;

    MDGDMA_SPIN_LOCK(status);
    FDMA_PDN_CLR_FLAG |= (1 << channel);
    MDGDMA_SPIN_UNLOCK(status);
    GDMA_PDN_CHK();
}

kal_uint32 FDMA_PDN_STS(kal_uint32 channel)
{
    if (FDMA_PDN_CLR_FLAG & (1 << channel)) {
        return 0;
    }
    return 1;
}

void HDMA_PDN_SET(kal_uint32 channel)
{
    kal_uint32 saved_mask;

    MDGDMA_ENTER_CRITICAL_SECTION(saved_mask);
    hdma_pdn_clr_flag &= (~(1 << channel));
    MDGDMA_LEAVE_CRITICAL_SECTION(saved_mask);
    GDMA_PDN_CHK();
}

void HDMA_PDN_CLR(kal_uint32 channel)
{
    kal_uint32 saved_mask;

    MDGDMA_ENTER_CRITICAL_SECTION(saved_mask);
    hdma_pdn_clr_flag |= (1 << channel);
    MDGDMA_LEAVE_CRITICAL_SECTION(saved_mask);
    GDMA_PDN_CHK();
}

kal_uint32 HDMA_PDN_STS(kal_uint32 channel)
{
    if (hdma_pdn_clr_flag & (1 << channel)) {
        return 0;
    }
    return 1;
}

#else //GDMA_PDN_SUPPORT

void FDMA_PDN_SET(kal_uint32 channel) {}
void FDMA_PDN_CLR(kal_uint32 channel) {}
kal_uint32 FDMA_PDN_STS(kal_uint32 channel) {return 0;}
void HDMA_PDN_SET(kal_uint32 channel) {}
void HDMA_PDN_CLR(kal_uint32 channel) {}
kal_uint32 HDMA_PDN_STS(kal_uint32 channel) {return 0;}

#endif //GDMA_PDN_SUPPORT

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
 *   None
 *  
 * RETURNS
 *   None
 *---------------------------------------------------------------------------*/
void drv_gdma_lisr(kal_uint32 v)
{
    ASSERT(GDMA_INTR_ID == v);
    IRQMask(GDMA_INTR_ID);
    kal_activate_hisr(gdma_hisrid);
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
 
 *---------------------------------------------------------------------------*/
void drv_gdma_init(void)
{
    kal_uint32 i = 0;

    for (i = 0; i < GDMA_INT_TYPE_MAX; i++) {
        gdmaCallback[i] = drv_default_callback;
    }

    gdma_start_trigger = 0;
    
    IRQ_Register_LISR(GDMA_INTR_ID, drv_gdma_lisr, "GDMA handler");
    gdma_hisrid = kal_init_hisr(GDMA_HISR);
    IRQSensitivity(GDMA_INTR_ID, LEVEL_SENSITIVE);
    IRQClearInt(GDMA_INTR_ID);
    IRQUnmask(GDMA_INTR_ID);
    MDGDMA_SPINLOCK_INIT;
#if defined(GDMA_PDN_SUPPORT)
    gdma_pdn_set = PDN_STS(PDN_GDMA) ? KAL_TRUE : KAL_FALSE;
#endif
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_set_config
 *
 * DESCRIPTION
 *   This function is to configure the gdma.
 *   (channel tx mode, src address, dst address, tx size, bst/bus width)
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
    kal_uint32 gpd_cs_en_value = 0;

    if (gdmaCfg_p->gdma_sel_channel >= GDMA_CH_MAX) {
        return KAL_FALSE;
    }
    FDMA_PDN_CLR(gdmaCfg_p->gdma_sel_channel);

    if (gdma_init_flag == 0) {
        drv_gdma_init();
        gdma_init_flag = 1;
    }

    //channel n is being active
    if (DRV_Reg32(GDMA_FDCSR(gdmaCfg_p->gdma_sel_channel)) & FDMA_STAT(gdmaCfg_p->gdma_sel_channel)) {
        //No need to call FDMA_PDN_SET()
        return KAL_FALSE;
    }
    
    chId = gdmaCfg_p->gdma_sel_channel;

    /* enable GPD checksum */
    if (gdmaCfg_p->gdma_gpd_cs_en == KAL_TRUE)
        gpd_cs_en_value = FDMA_CS_EN(chId);

    switch (gdmaCfg_p->gdma_mod)
    {
        case GDMA_MOD_LINKLIST:
            DRV_WriteReg32(GDMA_FDCSR(chId), (DRV_Reg32(GDMA_FDCSR(chId)) & ((chId % 2 == 0) ? 0xFFFFF0FF : 0xF0FFFFFF)) | gpd_cs_en_value);
            DRV_WriteReg32(GDMA_FDSAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_src_Gpd);
            DRV_WriteReg32(GDMA_FDDAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_dst_Gpd);
            DRV_WriteReg32(GDMA_FDCR(chId), FDMA_BST_BUS(gdmaCfg_p->gdma_bus_width.src_bus_width, gdmaCfg_p->gdma_bus_width.dst_bus_width));
            break;
        case GDMA_MOD_BASIC:
            DRV_WriteReg32(GDMA_FDCSR(chId), (DRV_Reg32(GDMA_FDCSR(chId)) & ((chId % 2 == 0) ? 0xFFFFF0FF : 0xF0FFFFFF)) | FDMA_MODE_BASIC(chId));
            DRV_WriteReg32(GDMA_FDCR(chId), ((gdmaCfg_p->gdma_mod_basic_tx_size << 16) | FDMA_BST_BUS(gdmaCfg_p->gdma_bus_width.src_bus_width, gdmaCfg_p->gdma_bus_width.dst_bus_width)));
            DRV_WriteReg32(GDMA_FDSAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_src_Gpd);
            DRV_WriteReg32(GDMA_FDDAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_dst_Gpd);
            break;
        case GDMA_MOD_DESCRIPTOR:
            DRV_WriteReg32(GDMA_FDCSR(chId), (DRV_Reg32(GDMA_FDCSR(chId)) & ((chId % 2 == 0) ? 0xFFFFF0FF : 0xF0FFFFFF)) | FDMA_MODE_DESCRPT(chId) | gpd_cs_en_value);
            DRV_WriteReg32(GDMA_FDSAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_src_Gpd);
            DRV_WriteReg32(GDMA_FDDAR(chId), gdmaCfg_p->gdma_gpd_addr.gdma_dst_Gpd);
            DRV_WriteReg32(GDMA_FDCR(chId), FDMA_BST_BUS(gdmaCfg_p->gdma_bus_width.src_bus_width, gdmaCfg_p->gdma_bus_width.dst_bus_width));
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
 *   chId [in] Channel ID. A value of gdma_channel_type_e enumeratnion.
 *   cmd [in] Start command. A value of gdma_start_cmd_type_e enumeration.
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
kal_bool drv_gdma_start_cmd(gdma_channel_type_e chId, gdma_start_cmd_type_e cmd)
{
    FDMA_PDN_CLR(chId);
    if ((cmd == GDMA_START) && (DRV_Reg32(GDMA_FDCSR(chId)) & FDMA_STAT(chId))) {   //channel n is being active
        //No need to call FDMA_PDN_SET()
        return KAL_FALSE;
    }

    if (gdma_init_flag == 0)
    {
        drv_gdma_init();
        gdma_init_flag = 1;
    }

    //RESUME cmd should be used when the Ch was STOPPED before.
    if ((cmd == GDMA_RESUME) && !(gdma_start_trigger & (1<<chId))) {
        FDMA_PDN_SET(chId);
        return KAL_FALSE;
    }
    
    DRV_WriteReg32(GDMA_GIMRK0, ~gdma_int_unmask);
    DRV_Reg32(GDMA_FDCR(chId)) |= (cmd == GDMA_START) ? FDMA_START : FDMA_RESUME;

    gdma_start_trigger |= (1<<chId);
    
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
    kal_bool pdn = FDMA_PDN_STS(chId);
    FDMA_PDN_CLR(chId);
    DRV_Reg32(GDMA_FDCR(chId)) |= FDMA_STOP;
    gdma_start_trigger &= ~(1<<chId);
    if(pdn) {
        FDMA_PDN_SET(chId);
    }       
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_get_curGPD
 *
 * DESCRIPTION
 *   This function is to get current GPD src and dst address.
 *
 * PARAMETERS
 *   chId [in] Channel ID. A value of gdma_channel_type_e enumeratnion.
 *   cur_gpd_addr [out] A pointer to store GPD pointer information.
 *
 * RETURNS
 *   None
 *
 *---------------------------------------------------------------------------*/
void drv_gdma_get_curGPD(gdma_channel_type_e chId, gdma_gpd_addr_t *cur_gpd_addr)
{
    kal_bool pdn;
    if (gdma_init_flag == 0) {
        drv_gdma_init();
        gdma_init_flag = 1;
    }
    pdn = FDMA_PDN_STS(chId);
    FDMA_PDN_CLR(chId);
    if (cur_gpd_addr != NULL) {
        cur_gpd_addr->gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR(chId));
        cur_gpd_addr->gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR(chId));
    }
    if (pdn) {
        FDMA_PDN_SET(chId);
    }   
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
    if (gdma_init_flag == 0) {
        drv_gdma_init();
        gdma_init_flag = 1;
    }
    FDMA_PDN_CLR(chId);
    if (DRV_Reg32(GDMA_FDCSR(chId)) & FDMA_STAT(chId)) {
        return GDMA_STARTED;
    } else {
        FDMA_PDN_SET(chId);
        return GDMA_STOP;
    }
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
    kal_uint32 savedMask = 0;

    savedMask = SaveAndSetIRQMask();
    DRV_WriteReg32(GDMA_GISAR0, (0x11111111 << (kal_uint32)chId));
    RestoreIRQMask(savedMask);
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_clear_all_intr
 *
 * DESCRIPTION
 *   This function is used to clear all GDMA interrupt status.
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
    kal_uint32 savedMask = 0;

    savedMask = SaveAndSetIRQMask();
    intr_sts = DRV_Reg32(GDMA_GISAR0);
    DRV_WriteReg32(GDMA_GISAR0, intr_sts);
    RestoreIRQMask(savedMask);
}

/*---------------------------------------------------------------------------*
 * FUNCTION
 *   drv_gdma_register_callback
 *
 * DESCRIPTION
 *   This function is used to register GDMA call back function.
 *
 * PARAMETERS
 *   cbType [in] Interrupt type. A value of gdma_cbType_t.
 *   callback [in] A pointer to callback function.
 *
 * RETURNS
 *   KAL_TRUE
 *   KAL_FALSE
 *
 *---------------------------------------------------------------------------*/
kal_bool drv_gdma_register_callback(gdma_cbType_t *cbType, gdma_pcb_f callback)
{
    kal_uint32 savedMask = 0;

    if (callback == NULL || cbType == NULL)
        return KAL_FALSE;

    if ((cbType->gdma_int_type + cbType->gdma_channel) >= GDMA_INT_TYPE_MAX)
        return KAL_FALSE;

    if (gdma_init_flag == 0) {
        drv_gdma_init();
        gdma_init_flag = 1;
    }

    savedMask = SaveAndSetIRQMask();
    gdmaCallback[cbType->gdma_int_type + cbType->gdma_channel] = callback;
    gdmaCB_status |= (0x1 << (cbType->gdma_int_type + cbType->gdma_channel));
    gdma_int_unmask |= (0x1 << (cbType->gdma_int_type + cbType->gdma_channel));
    RestoreIRQMask(savedMask);

    return KAL_TRUE;
}


void drv_gdma_get_cbinfo(kal_uint32 int_idx)
{
    if (int_idx < GDMA_DST_DONE)
    {
        gdma_cb_info.gdma_int_type = GDMA_SRC_DONE;
        gdma_cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR(int_idx));
        gdma_cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR(int_idx));       
    }
    else if (int_idx < GDMA_SRC_QUE_EMPTY)
    {
        gdma_cb_info.gdma_int_type = GDMA_DST_DONE;
        gdma_cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx >> 4)));
        gdma_cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx >> 4)));        
    }
    else if (int_idx < GDMA_DST_QUE_EMPTY)
    {
        gdma_cb_info.gdma_int_type = GDMA_SRC_QUE_EMPTY;
        gdma_cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx>>8)));
        gdma_cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx>>8)));      
    }
    else if (int_idx < GDMA_LEN_ERR)
    {
        gdma_cb_info.gdma_int_type = GDMA_DST_QUE_EMPTY;
        gdma_cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx>>12)));
        gdma_cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx>>12)));     
    }
    else if (int_idx < GDMA_ALO_LEN_ERR)
    {
        gdma_cb_info.gdma_int_type = GDMA_LEN_ERR;
        gdma_cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx>>16)));
        gdma_cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx>>16)));     
    }
    else if (int_idx < GDMA_BD_CS_ERR)
    {
        gdma_cb_info.gdma_int_type = GDMA_ALO_LEN_ERR;
        gdma_cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx>>20)));
        gdma_cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx>>20)));     
    }
    else if (int_idx < GDMA_GPD_CS_ERR)
    {
        gdma_cb_info.gdma_int_type = GDMA_BD_CS_ERR;
        gdma_cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx>>24)));
        gdma_cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx>>24)));     
    }
    else
    {
        gdma_cb_info.gdma_int_type = GDMA_GPD_CS_ERR;
        gdma_cb_info.gpd_info.gdma_src_Gpd = DRV_Reg32(GDMA_FDSCPR((kal_uint32)(int_idx>>28)));
        gdma_cb_info.gpd_info.gdma_dst_Gpd = DRV_Reg32(GDMA_FDDCPR((kal_uint32)(int_idx>>28)));     
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
    
    gdma_int_status = DRV_Reg32(GDMA_GISAR0);
    DRV_WriteReg32(GDMA_GISAR0, gdma_int_status);
    RestoreIRQMask(savedMask);

    IRQClearInt(GDMA_INTR_ID);
    IRQUnmask(GDMA_INTR_ID);

    for (index = 0; index < GDMA_INT_TYPE_MAX; index++)
    {
        if (gdmaCB_status & (1 << index) && (gdma_int_status & (1 << index)))
        {
            drv_gdma_get_cbinfo(index);
            gdmaCallback[index](&gdma_cb_info);
        }
    }

    for (index = 0; index < GDMA_CH_MAX; index++) {
        if(DRV_Reg32(GDMA_FDCSR(index)) & FDMA_MODE_BASIC(index)) {
            //Basic mode
            if(gdma_int_status & FDMA_DST_DONE(index)) {
                FDMA_PDN_SET(index);
            }           
        }
        else {
            //Link-list mdoe or descriptor mode
            if(gdma_int_status & FDMA_QE_DST_INT(index)) {
                FDMA_PDN_SET(index);
            }                       
        }
    }
}

#else /*!defined(DRV_GDMA_OFF)*/

#endif /*!defined(DRV_GDMA_OFF)*/
