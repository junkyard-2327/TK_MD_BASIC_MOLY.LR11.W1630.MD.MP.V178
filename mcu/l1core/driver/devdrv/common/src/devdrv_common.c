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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    drvdrv_common.c
 *
 * Project:
 * --------
 *   Tataka_Software
 *
 * Description:
 * ------------
 *   This Module defines device driver common functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "drv_comm.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "reg_base.h"
#include "intrCtrl.h"

#include "kal_trace.h"
#include "system_trc.h"
#include "init_trc_api.h"
#include "init.h"
#include "dcl.h"
#include "drv_cmif.h"
#include "csif_global_extern.h"


#ifdef __MTK_TARGET__
   #include "ex_public.h"
#ifdef __MULTI_BOOT__
   #include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */
#endif /* __MTK_TARGET__ */

#if defined(__RESOURCE_MANAGER__)
#include "rm.h"
#endif //__RESOURCE_MANAGER__

#include "us_timer.h"
#include "drv_hisr.h"

#ifdef DRV_HIF_SUPPORT
#include "hif_hal.h"
#endif

#if defined(__SCC_SIB_SUPPORT__)
#include "scc.h"
#endif

#if defined(__SMART_PHONE_MODEM__)

#if defined(DRV_MISC_TDMA_L1_MACRO)
#include "RM_public.h"
#endif

#endif /* __SMART_PHONE_MODEM__ */
#if defined(DRV_EMIMPU)
extern void emimpu_init(void);
#endif /* DRV_EMIMPU */

//extern void DRVPDN_ini(void);
//extern void DMA_Ini(void);
extern void WDT_init(void);
//extern void spi_init(void);

#if 0 // Fix build error
/* under construction !*/
#endif

extern void GCU_Disable_ReverseBit(void);
//extern void USB2UART_init(void);
extern void Visual_Init(void);
//extern void che_hw_init(void);
//extern void lpwr_init(void);

#if 0 // Fix build error
#if !defined(DCL_MSDC_INTERFACE)
/* under construction !*/
#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
/* under construction !*/
#endif//defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
#endif//!defined(DCL_MSDC_INTERFACE)
#endif

#ifdef __WIFI_SUPPORT__
extern void wndrv_HWinit(void);
#endif
extern void custom_drv_deinit(void);
#if defined(ISP_SUPPORT)
extern void CalInit(void);
#endif
#if defined(DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS)
extern kal_uint8 UartPortOwnedByMD[3];
#endif // #if defined(DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS)
extern kal_bool INT_QueryExceptionStatus(void);

/*lint -e552*/
boot_mode_type system_boot_mode = UNKNOWN_BOOT_MODE;
/*lint +e552*/
extern kal_uint16 INT_BootMode(void);

#ifdef IC_MODULE_TEST
   extern void IC_ModuleTest_Start(void);
#endif   /*IC_MODULE_TEST*/

#if defined(IC_BURNIN_TEST) || defined(DRV_MISC_GPT1_AS_OS_TICK)
extern void INT_Timer_Interrupt(void);
#endif //IC_BURNIN_TEST

typedef void (* MEMCPY_FUNC)(const void *srcaddr, void *dstaddr, kal_uint32 len);
#ifdef DRV_MISC_DMA_NO_MEMCPY
   void (* DRV_MEMCPY)(const void *srcaddr, void *dstaddr, kal_uint32 len);
#elif defined(DRV_MISC_DMA_MEMCPY)
   extern kal_bool DMA_memcpy(const void *src, const void *dst, kal_uint32 length);
   void (* DRV_MEMCPY_PTR)(const void *srcaddr, void *dstaddr, kal_uint32 len);
   void DRV_MEMCPY(const void *srcaddr, void *dstaddr, kal_uint32 len);
#endif   /**/

//#if defined(__IRDA_SUPPORT__) && !defined(__MEUT__) && !defined(__MEIT__)
/*TY adds this 2004/10/27*/
//extern UartDriver_strcut ircomm_uart_api;
//#endif

#if defined(__BTMTK__) && (defined(__BT_SPP_PROFILE__) || defined(__BT_HFG_PROFILE__))
extern Seriport_HANDLER_T  SPPA_Uart_Drv_Handler;
extern void bchs_host_controller_power_off(void);
#elif defined __CMUX_SUPPORT__
extern Seriport_HANDLER_T  CmuxUart_Drv_Handler;
#endif

#ifdef __SWDBG_SUPPORT__
extern kal_uint8 SWDBG_Profile;
#endif  /* _SWDBG_SUPPORT__ */

#ifdef  __BTMODULE_MT6601__
extern void BT_Radio_Shutdown(void);
#endif

#if (defined( DRV_MULTIPLE_SIM) && (!defined(DRV_2_SIM_CONTROLLER)))
extern void sim_MT6302_init(void);
#endif

#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_MISC_REG_DBG__)
#define DRV_MISC_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_MISC_Reg(addr)                        DRV_DBG_Reg(addr)
#define DRV_MISC_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)
#define DRV_MISC_Reg32(addr)                      DRV_DBG_Reg32(addr)
#define DRV_MISC_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)
#define DRV_MISC_Reg8(addr)                       DRV_DBG_Reg8(addr)
#define DRV_MISC_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)
#define DRV_MISC_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)
#define DRV_MISC_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)
#define DRV_MISC_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)
#define DRV_MISC_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)
#define DRV_MISC_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_MISC_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)
#define DRV_MISC_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)
#define DRV_MISC_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value)
#else
#define DRV_MISC_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_MISC_Reg(addr)                        DRV_Reg(addr)
#define DRV_MISC_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)
#define DRV_MISC_Reg32(addr)                      DRV_Reg32(addr)
#define DRV_MISC_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)
#define DRV_MISC_Reg8(addr)                       DRV_Reg8(addr)
#define DRV_MISC_ClearBits(addr,data)             DRV_ClearBits(addr,data)
#define DRV_MISC_SetBits(addr,data)               DRV_SetBits(addr,data)
#define DRV_MISC_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)
#define DRV_MISC_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)
#define DRV_MISC_SetBits32(addr,data)             DRV_SetBits32(addr,data)
#define DRV_MISC_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_MISC_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)
#define DRV_MISC_SetBits8(addr,data)              DRV_SetBits8(addr,data)
#define DRV_MISC_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value)
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_MISC_REG_DBG__)

#ifdef __DRV_COMM_REG_DBG__
DRV_REG_DBG_STRUCT    DRV_REG_DBG_INFO_DATA;

static void drv_reg_dbg_trace(kal_uint8 write, kal_uint16 line, kal_uint32 addr, kal_uint32 value)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void drv_reg_dbg_trace_write16(kal_uint16 line, kal_uint32 addr, kal_uint32 data)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   
}

void drv_reg_dbg_trace_write32(kal_uint16 line, kal_uint32 addr, kal_uint32 data)
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
   #endif
}

void drv_reg_dbg_trace_write8(kal_uint16 line, kal_uint32 addr, kal_uint32 data)
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
   #endif
}

kal_uint16 drv_reg_dbg_trace_read16(kal_uint16 line, kal_uint32 addr)
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
#endif   
}

kal_uint32 drv_reg_dbg_trace_read32(kal_uint16 line, kal_uint32 addr)
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
   #endif
}

kal_uint32 drv_reg_dbg_trace_read8(kal_uint16 line, kal_uint32 addr)
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
   #endif
}

#endif //__DRV_COMM_REG_DBG__

#if defined(__MTK_TARGET__)
/* bb reg dump setting */
EX_BBREG_DUMP devdrv_dump;
const kal_uint32 devdrv_dump_regions[] = {
  #if defined(MT6290)||defined(MT6595)||defined(TK6291)||defined(MT6755)||defined(MT6797)||defined(MT6757)||defined(MT6750S)
  /*Base Address,                length,   type(0/1=byte access, 2=16-bit access, 4=32-bit access)  */
    L1_BASE_MADDR_L1MCU_BUSMOM,  0x0608, 4,

    #if 0 //workaround for TK6291 register base porting
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
  #else /* MT6290 */
    #error "Unsupported Chip"
    //    0, 0, 0
  #endif/* MT6290 */
};
#endif /* __MTK_TARGET__ */


/*To get all customized data*/
void Drv_Customize_Init(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
}

/*************************************************************************
* FUNCTION
*   Drv_query_boot_mode
*
* DESCRIPTION
*   Return boot mode.
*
* PARAMETERS
*
* RETURNS
*   FACTORY_BOOT, NORMAL_BOOT and USBMS_BOOT
*
* GLOBALS AFFECTED
*
*************************************************************************/
boot_mode_type Drv_query_boot_mode(void)
{
#if 1

#ifdef __MULTI_BOOT__

#ifdef __USB_ENABLE__
    PW_CTRL_IS_USB_BOOT CtrlVal;
    DCL_HANDLE handle;
#endif /* __USB_ENABLE__ */

   if( INT_BootMode() == MTK_FACTORY_MODE )
      return FACTORY_BOOT;

#ifdef __USB_ENABLE__

    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
    DclPW_Close(handle);
   if((kal_bool)CtrlVal.val == KAL_TRUE )
      return USBMS_BOOT;

#endif /* __USB_ENABLE__ */

#endif /* __MULTI_BOOT__ */
#endif
   return NORMAL_BOOT;
}

/*************************************************************************
* FUNCTION
*   Drv_PW_Init
*
* DESCRIPTION
*   PW initialization
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void Drv_PW_Init(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __L1_STANDALONE__
   #ifdef PMIC_PRESENT
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
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
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
/* under construction !*/
#if defined(__DRV_NO_USB_CHARGER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif   /*PMIC_PRESENT*/
#else /*__L1_STANDALONE__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   /*__L1_STANDALONE__*/
#endif
}

/*
* FUNCTION
*  Drv_Init_Phase1
*
* DESCRIPTION
*     This function is the NFB phase1 (Primary ROM) initial function for
*     all device drivers.
*     This function is called once to initialize the device driver.
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*
* NOTE XXX
*   All sub functions reference by this function should be placed on
*   Primary ROM for NFB projects. Or it cannot boot up because Drv_Init()
*   executed before Secondary ROM loaded.
*   Please make sure all sub-functions under custom.lib that referenced by
*   Drv_Init() list in NFB scatter file.
*/

void Drv_Init_Phase1(void)
{

#if defined(__FPGA__)

/**/
/* =========== Below is Init Flow of FPGA =============== */
/**/

#if defined(__SCC_SIB_SUPPORT__)
   // Init SIB Related IP Driver
   scc_init();
#endif

    CMIF_Init();
    //CSIF_Init(); // Move to EL1D task

   /* update the system boot mode */
/*lint -e552*/
    system_boot_mode = Drv_query_boot_mode(); 
/*lint +e552*/
    print_boot_mode();


/**/
/* =========== Above is Init Flow of FPGA =============== */
/**/

#else     /* Not __FPGA__, means ASIC */

/**/
/* =========== Below is Init Flow of ASIC  =============== */
/**/

#if defined(DRV_GPT_GPT3) && (!defined(__LTE_RAT__))
   DCL_HANDLE gpt_handle;
#endif //defined(DRV_GPT_GPT3)
#ifndef DRV_RTC_NOT_EXIST
   DCL_HANDLE rtc_handler;
#endif //#ifndef DRV_RTC_NOT_EXIST

#if defined(__MTK_TARGET__)
   /* register bb reg dump */
   devdrv_dump.regions = (kal_uint32*)devdrv_dump_regions;
   devdrv_dump.num = sizeof(devdrv_dump_regions) / (sizeof(kal_uint32) * 3);
   devdrv_dump.bbreg_dump_callback = NULL;
   EX_REGISTER_BBREG_DUMP(&devdrv_dump);
#endif /* __MTK_TARGET__ */

#if defined(__HW_US_TIMER_SUPPORT__ )
   USC_Start();
#endif

//[2014/02/10 : WCD/OSS1/SS10 Anderson Tsai confirmed it should exist on L1core]
#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__
    if (INT_GetSysStaByCmd(CHK_USB_META_WO_BAT, NULL)==KAL_TRUE)
    {

        DCL_HANDLE handle;
        DclPMU_Initialize();
        handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
        DclPMU_Control(handle, CHR_SET_CHARGE_WITHOUT_BATTERY, NULL);
        DclPMU_Close(handle);

    }
#endif //#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__

#if defined(__SCC_SIB_SUPPORT__)
   // Init SIB Related IP Driver
   scc_init();
#endif

   //CSIF_Init(); // Move to EL1D Task
   CMIF_Init();
#if defined(__DSP_FCORE4__)
   INT_Trace_Enter(INIT_DRV1_MDCIHW, 1);
   mdci_hw_init(1,0x0);
   INT_Trace_Exit(INIT_DRV1_MDCIHW, 1);
#endif

#if defined(DRV_EMIMPU)
   INT_Trace_Enter(INIT_DRV1_EMIMPU, 1);
   emimpu_init();
   INT_Trace_Exit(INIT_DRV1_EMIMPU, 1);
#endif /* DRV_EMIMPU */

#if 0 // To fix build error
#ifndef DRV_PWM_NOT_EXIST
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

   /*To get all customized data*/
   INT_Trace_Enter(INIT_DRV1_CUSTOM, 1);

   Drv_Customize_Init();
#if 0 // Fix build error
/* under construction !*/
#endif

   INT_Trace_Exit(INIT_DRV1_CUSTOM, 1);

   #if defined(DRV_GPT_GPT3) && (!defined(__LTE_RAT__))
    INT_Trace_Enter(INIT_DRV1_GPT3, 1);
    /*turn on gpt3 to count powen on period*/
    DclFGPT_Initialize();
    gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
    DclFGPT_Control(gpt_handle,FGPT_CMD_START,0);
    DclFGPT_Close(gpt_handle);
    INT_Trace_Exit(INIT_DRV1_GPT3, 1);
   #endif

   #if defined(MULTI_MEDIA_EXIST)
      INT_Trace_Enter(INIT_DRV1_VISUAL, 1);
      Visual_Init();
      INT_Trace_Exit(INIT_DRV1_VISUAL, 1);
   #endif /* defined(MULTI_MEDIA_EXIST)*/

   #ifdef DRV_MISC_DMA_NO_MEMCPY
      DRV_MEMCPY = (MEMCPY_FUNC)0x48000150;
   #elif defined(DRV_MISC_DMA_MEMCPY)
      DRV_MEMCPY_PTR = (MEMCPY_FUNC)0x48000134;
   #endif

   INT_Trace_Enter(INIT_DRV1_GPTI, 1);
   DclSGPT_Initialize();
   INT_Trace_Exit(INIT_DRV1_GPTI, 1);

   INT_Trace_Enter(INIT_DRV1_WDT, 1);
   WDT_init();
   INT_Trace_Exit(INIT_DRV1_WDT, 1);

#if 0 // To fix build error
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifndef DRV_RTC_NOT_EXIST
   // need to set XOSC earlier
   INT_Trace_Enter(INIT_DRV1_XOSC, 1);
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
   DclRTC_Control(rtc_handler, RTC_CMD_SETXOSC, (DCL_CTRL_DATA_T *)NULL);
   INT_Trace_Exit(INIT_DRV1_XOSC, 1);
#endif /*DRV_RTC_NOT_EXIST*/

#ifdef __CS_FAC_DET__
   INT_Trace_Enter(INIT_DRV1_CSFACDET, 1);
   cs_fac_det = cs_fac_det_get_interface();
   cs_fac_det->drv_init();
   INT_Trace_Exit(INIT_DRV1_CSFACDET, 1);
#endif // #ifdef __CS_FAC_DET__

#ifdef  __DRV_EXT_ACCESSORY_DETECTION__
   {
        INT_Trace_Enter(INIT_DRV1_EXTACCDET, 1);
       aux_ext_acc_det = aux_custom_get_ext_accessory_det();
       aux_ext_acc_det->drv_init();
        INT_Trace_Exit(INIT_DRV1_EXTACCDET, 1);
   }
#endif // #ifdef  __DRV_EXT_ACCESSORY_DETECTION__

#if defined(__RESOURCE_MANAGER__)
   INT_Trace_Enter(INIT_DRV1_RM, 1);
   RMInit();
   INT_Trace_Exit(INIT_DRV1_RM, 1);
#endif //__RESOURCE_MANAGER__

#ifndef DRV_RTC_NOT_EXIST
#ifdef DRV_RTC_HW_CALI
   print_bootup_trace_enter(SST_INIT_DRV1_RTCHW);
   DclRTC_Control(rtc_handler, RTC_CMD_HW_INIT, (DCL_CTRL_DATA_T *)NULL);
   print_bootup_trace_exit(SST_INIT_DRV1_RTCHW);
#endif
#endif /*DRV_RTC_NOT_EXIST*/
    //DclPW_Initialize();

//[2014/02/10 : WCD/OSS1/SS10 Anderson Tsai confirmed it should exist on L1core]
    DclPMU_Initialize();


    Drv_PW_Init();

   /* update the system boot mode */
/*lint -e552*/
   system_boot_mode = Drv_query_boot_mode();
/*lint +e552*/
      print_boot_mode();


/**/
/* =========== Above is Init Flow of ASIC  =============== */
/**/

#endif
}

/*
* FUNCTION
*  Drv_Init_Phase2
*
* DESCRIPTION
*     This function is the NFB phase2 (Secondary ROM) initial function for
*     all device drivers.
*     This function is called once to initialize the device driver.
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*
* NOTE XXX
*   All sub functions reference by this function should be placed on
*   Secondary ROM for NFB projects.
*/
void Drv_Init_Phase2(void)
{

#if defined(__FPGA__)

/**/
/* =========== Below is Init Flow of FPGA =============== */
/**/






/**/
/* =========== Above is Init Flow of FPGA =============== */
/**/

#else     /* Not __FPGA__, means ASIC */

/**/
/* =========== Below is Init Flow of ASIC  =============== */
/**/

#ifndef DRV_RTC_NOT_EXIST
   DCL_HANDLE rtc_handler;
#endif /*DRV_RTC_NOT_EXIST*/

#if defined(IC_BURNIN_TEST) || defined(DRV_MISC_GPT1_AS_OS_TICK)
   /*AB: Enable GPT1 for OS tick in the burn-in test load*/
   extern void GPT_init(kal_uint8 timerNum, void (*GPT_Callback)(void));
   extern void GPT_ResetTimer(kal_uint8 timerNum,kal_uint16 countValue,kal_bool autoReload);
   extern void GPT_Start(kal_uint8 timerNum);
   GPT_init(1, INT_Timer_Interrupt);
   GPT_ResetTimer(1, 4, KAL_TRUE);
   GPT_Start(1);
#endif //IC_BURNIN_TEST

#ifndef DRV_KBD_NOT_EXIST
   INT_Trace_Enter(INIT_DRV2_KBD, 1);
   DclSKBD_Initialize();
   INT_Trace_Exit(INIT_DRV2_KBD, 1);
#endif /*DRV_KBD_NOT_EXIST*/
#ifndef DRV_RTC_NOT_EXIST
   INT_Trace_Enter(INIT_DRV2_RTCSW, 1);
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
    DclRTC_Control(rtc_handler, RTC_CMD_INIT_TC_AL_INTR, (DCL_CTRL_DATA_T *)NULL);
   INT_Trace_Exit(INIT_DRV2_RTCSW, 1);
#endif /*DRV_RTC_NOT_EXIST*/

#ifdef __SIM_DRV_MULTI_DRV_ARCH__
   INT_Trace_Enter(INIT_DRV2_SIM, 1);
   DclSIM_Initialize();
   INT_Trace_Exit(INIT_DRV2_SIM, 1);
#endif

#if (defined( DRV_MULTIPLE_SIM) && (!defined(DRV_2_SIM_CONTROLLER)))
   INT_Trace_Enter(INIT_DRV2_SIMMT6302, 1);
   sim_MT6302_init();
   INT_Trace_Exit(INIT_DRV2_SIMMT6302, 1);
 #endif

#if 0 // Fix build error
#if (defined(ATEST_DRV_ENABLE) && !defined(ATEST_DRV_MSDC)) || defined(MT6595)
/* under construction !*/
#else   //defined(ATEST_DRV_ENABLE) && !defined(ATEST_DRV_MSDC)
/* under construction !*/
#if !defined(DCL_MSDC_INTERFACE)
/* under construction !*/
#else
/* under construction !*/
#endif//!defined(DCL_MSDC_INTERFACE)
/* under construction !*/
#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
/* under construction !*/
#if !defined(DCL_MSDC_INTERFACE)
/* under construction !*/
#endif//!defined(DCL_MSDC_INTERFACE)
/* under construction !*/
#endif//defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
#endif  //defined(ATEST_DRV_ENABLE) && !defined(ATEST_DRV_MSDC)
#endif

#ifdef IC_MODULE_TEST
   IC_ModuleTest_Start();
#endif   /*IC_MODULE_TEST*/

#ifdef MT6218B/*only 6218B has this */
   GCU_Disable_ReverseBit();
#endif
#ifdef __SWDBG_SUPPORT__

   /* initialize SWDBG */
   INT_Trace_Enter(INIT_DRV2_SWDBG, 1);
   swdbg_init();
   INT_Trace_Exit(INIT_DRV2_SWDBG, 1);

#endif   /* __SWDBG_SUPPORT__ */

     /* ISP/Camera initialize */
#if defined(ISP_SUPPORT)
     INT_Trace_Enter(INIT_DRV2_CIS_ENTER, 1);
     CalInit();
     INT_Trace_Exit(INIT_DRV2_CIS_ENTER, 1);
#endif

#ifdef __WIFI_SUPPORT__
   INT_Trace_Enter(INIT_DRV2_WN, 1);
   wndrv_HWinit();
   INT_Trace_Exit(INIT_DRV2_WN, 1);
#endif

#if 0   //There is no I2C driver request for MT6290
/* under construction !*/
#if defined(DRV_I2C_25_SERIES)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
// PXS is init at phase2 because it is external devices
// Currently, do NOT think it should be put in phase1
#if defined(__PXS_ENABLE__) && !defined(IC_MODULE_TEST) && !defined(IC_BURNIN_TEST)
   DclPXS_Initialize();
#endif // #if defined(__PXS_ENABLE__) && !defined(IC_MODULE_TEST) && !defined(IC_BURNIN_TEST)


#ifdef CAS_SMD_SUPPORT
   INT_Trace_Enter(INIT_DRV2_ICC, 1);
    DalIccInit();
   INT_Trace_Exit(INIT_DRV2_ICC, 1);
#endif

#if 0 // Init BTIF_HWInit_VFIFO(); in bluetooth module
#if defined(__BTMODULE_MT6236__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6276__)
/* under construction !*/
#endif
/* under construction !*/
#endif // 0

//#ifdef DRV_HIF_SUPPORT
    //hif_init();
//#endif
//#ifdef DRV_SPI_SUPPORT
    //spi_init();
//#endif
#if defined(__TOUCH_PANEL_CAPACITY__)
   DclSTS_Initialize();
#endif

#if defined(MOTION_SENSOR_SUPPORT)
   INT_Trace_Enter(INIT_DRV2_MSENS, 1);
   motion_sensor_init();
   INT_Trace_Exit(INIT_DRV2_MSENS, 1);
#endif

#if 0 // To fix build error
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/**/
/* =========== Above is Init Flow of ASIC  =============== */
/**/

#endif
}

/*
* FUNCTION
*  Drv_Deinit
*
* DESCRIPTION
*     This function is the deinitial function for all device drivers.
*     This function is called once to deinitialize the device driver.
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void Drv_Deinit(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef  __BTMODULE_MT6601__
/* under construction !*/
#endif
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

#if defined(DRV_MISC_DMA_MEMCPY)
void DRV_MEMCPY(const void *srcaddr, void *dstaddr, kal_uint32 len)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   
}
#endif   /*DRV_MISC_DMA_MEMCPY*/


kal_bool Drv_WriteReg(kal_uint32 addr, kal_uint16 data)
{
#ifdef __LTE_RAT__
   if (addr < 0xB0000000)
      return KAL_FALSE;
#else
   if (addr < 0x70000000)
      return KAL_FALSE;
#endif
   DRV_MISC_WriteReg(addr,data);
   return KAL_TRUE;
}

kal_bool Drv_ReadReg(kal_uint32 addr, kal_uint16 *data)
{
#ifdef __LTE_RAT__
   if (addr < 0xB0000000)
      return KAL_FALSE;
#else
   if (addr < 0x70000000)
      return KAL_FALSE;
#endif

   *data = DRV_MISC_Reg(addr);
   return KAL_TRUE;
}

kal_uint32 drv_get_current_time(void)
{

#if defined(DRV_MISC_TDMA_NO_TIME)
   ASSERT(0);
#endif   /*DRV_MISC_TDMA_NO_TIME*/

#if defined(DRV_MISC_TDMA_TIME_BASE)
   return (DRV_MISC_Reg32(TDMA_base+0x0230));
#elif defined(DRV_MISC_TDMA_TIME_BASE_8200)
    return (DRV_MISC_Reg32(0x82000230));
#elif defined(DRV_MISC_TDMA_TIME_BASE_8020)
    return (DRV_MISC_Reg32(0x80200230));
#elif defined(DRV_MISC_TDMA_TIME_BASE_8406)
    return (DRV_MISC_Reg32(0x84060230));
#elif defined(DRV_MISC_TDMA_L1_MACRO)
    //return (HW_TDMA_GET_32KCNT());
    // 2014/12/04 , replace 32KCNT function by request of TH Yeh & Hsiao-Hsien Chen
    return RM_GetF32k();
#elif defined(DRV_MISC_TOPSM_32K_RTC) /* Get 32K ticks */
    return DRV_MISC_Reg32(BASE_ADDR_MDTOPSM+0x0104);
#else
   return 0;
#endif

}

kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time)
{
    kal_uint32 result=0;
#if defined(DRV_MISC_TDMA_NO_TIME)
   ASSERT(0);
#endif   /*DRV_MISC_TDMA_NO_TIME*/

    if (previous_time > current_time)
    {
//#if defined(DRV_MISC_TDMA_TIME_MAX_80000)
#if defined(DRV_MISC_TDMA_TIME_MAX_19BITS)
        result = 0x80000 - previous_time + current_time;
#elif defined(DRV_MISC_TDMA_TIME_MAX_24BITS)
      result = 0x1000000 - previous_time + current_time;
#elif defined(DRV_MISC_TDMA_TIME_MAX_32BITS) || defined(DRV_MISC_TOPSM_32K_RTC)
      result = 0xFFFFFFFF - previous_time + current_time + 1;
#else /* use us_counter=>Qbit as tick*/
      result = 0;
#endif
    }
    else
    {
        result = current_time - previous_time;
    }
    return result;
}

kal_uint32 drv_get_duration_ms(kal_uint32 previous_time)
{
    kal_uint32 result;
    kal_uint32 current_time;
   kal_uint64 temp_value;

    current_time = drv_get_current_time();
    result = drv_get_duration_tick(previous_time, current_time);
   /* X ms = result x 1000/32K = (result x 125)>>12 */
   temp_value = (kal_uint64)(((kal_uint64) result)*125);
    result = (kal_uint32)(temp_value>>12);
    return result;
}

#ifdef DRV_MEMORY_TRACE_DEBUG
DRV_DBG_STRUCT DRV_DBG_INFO_DATA;
/*drv_dbg_trace(NAND_READ_START,drv_get_current_time(),0,0);*/
void drv_dbg_trace(kal_uint16 index, kal_uint32 time, kal_uint32 data1, kal_uint32 data2)
{
   kal_uint32        savedMask;
   savedMask = SaveAndSetIRQMask();
   {
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].tag = index;
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].time = time;
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].data1 = data1;
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].data2 = data2;
      DRV_DBG_INFO_DATA.dbg_data_idx++;
   }
   RestoreIRQMask(savedMask);
}
#endif   /*DRV_MEMORY_TRACE_DEBUG*/

/*************************************************************************
   APIs for driver debugging
*************************************************************************/
#if defined(__TST_MODULE__)
#if (!defined(MTK_KAL_MNT))&&(!defined(KAL_ON_OSCAR))&&(!defined(MCD_DLL_EXPORT))&&(!defined(L1_SIM))&&(!defined(__FUE__))
void drv_trace0(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type)
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
#endif
}

void drv_trace1(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1)
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
#endif   
}

void drv_trace2(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2)
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
   #endif
}

void drv_trace4(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4)
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
#endif   
}

void drv_trace8(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4,
                kal_uint32 data5, kal_uint32 data6, kal_uint32 data7, kal_uint32 data8)
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
#endif   
}
#endif /* (!defined(MTK_KAL_MNT))&&(!defined(KAL_ON_OSCAR))&&(!defined(MCD_DLL_EXPORT))&&(!defined(L1_SIM))*/
#endif // #if defined(__TST_MODULE__)

kal_uint8 drv_dummy_return(void)
{
   return 0;
}

