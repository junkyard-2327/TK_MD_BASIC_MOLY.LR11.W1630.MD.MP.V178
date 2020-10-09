/*****************************************************************************
 *
 * Filename:
 * ---------
 *   CSIF_R11G1_Local_ASM_Define.h
 *
 * Project:
 * --------
 *   R11G1 Project
 *
 * Description:
 * ------------
 *   History for each file.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by Perforce. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 *
 * 07 18 2014 peng-chih.wang
 * [MOLY00072226] [TK6291] L1Core CSIF driver integration
 * add CSIF pretest load option for testcase (CUSTOM_OPTION += __CSIF_PRETEST_LOAD_ONLY__.)
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by Perforce. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
**********************************************************************************************************************************************************
*[File         ]       CSIF_R11G1_Local_ASM_Define.h
*[Version      ]       v1.0
*[Revision Date]       2014-06-10
*[Author       ]       Peng-Chih Wang
*[Description  ]
*    The program is for the R11G1 CSIF CR rename header file.
*
*[Copyright]
*    Copyright (C) 2005 MediaTek Incorporation. All Rights Reserved.
**********************************************************************************************************************************************************
*/

#ifndef __CSIF_R11G1_LOCAL_ASM_DEFINE_H__

#define __CSIF_R11G1_LOCAL_ASM_DEFINE_H__

//for ICC core register 
#define ICC_DSPCSIF_C2S_IRQ_SET                     ((volatile UINT32P)(ICC_CSIF_BASE+0x0))
#define ICC_DSPCSIF_C2S_IRQ_READ                    ((volatile UINT32P)(ICC_CSIF_BASE+0x4))
#define ICC_DSPCSIF_S2C_IRQ_READ                    ((volatile UINT32P)(ICC_CSIF_BASE+0x8))
#define ICC_DSPCSIF_S2C_IRQ_CLR                     ((volatile UINT32P)(ICC_CSIF_BASE+0xC))
#define ICC_DSPCSIF_S2C_IRQ_ENABLE                  ((volatile UINT32P)(ICC_CSIF_BASE+0x10))
#define ICC_DSPCSIF_VAS_VALID                       ((volatile UINT32P)(ICC_CSIF_BASE+0x14))
#define ICC_DSPCSIF_VAS_ACK                         ((volatile UINT32P)(ICC_CSIF_BASE+0x18))
#define ICC_DSPCSIF_VAS_SKIP                        ((volatile UINT32P)(ICC_CSIF_BASE+0x1C))
#define ICC_DSPCSIF_TASK_ID                         ((volatile UINT32P)(ICC_CSIF_BASE+0x20))
#define ICC_DSPCSIF_GPI_S_READ                      ((volatile UINT32P)(ICC_CSIF_BASE+0x24))
#define ICC_DSPCSIF_GPI_C_SET                       ((volatile UINT32P)(ICC_CSIF_BASE+0x28))
#define ICC_DSPCSIF_GPI_C_CLEAR                     ((volatile UINT32P)(ICC_CSIF_BASE+0x2C))
#define ICC_DSPCSIF_GPI_C_READ                      ((volatile UINT32P)(ICC_CSIF_BASE+0x30))
#define ICC_DSPCSIF_CR4_ERROR                       ((volatile UINT32P)(ICC_CSIF_BASE+0x34))
#define ICC_DSPCSIF_CR4_ERROR_ENABLE                ((volatile UINT32P)(ICC_CSIF_BASE+0x38))
#define ICC_DSPCSIF_ERROR_C2S_OVFL                  ((volatile UINT32P)(ICC_CSIF_BASE+0x3C))
#define ICC_DSPCSIF_ERROR_C2S_OVFL_CLR              ((volatile UINT32P)(ICC_CSIF_BASE+0x40))
#define ICC_DSPCSIF_ERROR_S2C_OVFL                  ((volatile UINT32P)(ICC_CSIF_BASE+0x44))
#define ICC_DSPCSIF_ERROR_S2C_OVFL_CLR              ((volatile UINT32P)(ICC_CSIF_BASE+0x48))
#define ICC_DSPCSIF_ERROR_ACD_CONFLICT              ((volatile UINT32P)(ICC_CSIF_BASE+0x4C))
#define ICC_DSPCSIF_ERROR_ACD_CONFLICT_CLR          ((volatile UINT32P)(ICC_CSIF_BASE+0x50))
#define ICC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR       ((volatile UINT32P)(ICC_CSIF_BASE+0x54))
#define ICC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR_CLR   ((volatile UINT32P)(ICC_CSIF_BASE+0x58))
#define ICC_DSPCSIF_DSP_RANGE_START_ADDR            ((volatile UINT32P)(ICC_CSIF_BASE+0x5C))
#define ICC_DSPCSIF_DSP_RANGE_SIZE                  ((volatile UINT32P)(ICC_CSIF_BASE+0x60))
#define ICC_DSPCSIF_CR4_RANGE_START_ADDR            ((volatile UINT32P)(ICC_CSIF_BASE+0x64))
#define ICC_DSPCSIF_CR4_RANGE_SIZE                  ((volatile UINT32P)(ICC_CSIF_BASE+0x68))


//for IMC core
#define IMC_DSPCSIF_C2S_IRQ_SET                     ((volatile UINT32P)(IMC_CSIF_BASE+0x0))
#define IMC_DSPCSIF_C2S_IRQ_READ                    ((volatile UINT32P)(IMC_CSIF_BASE+0x4))
#define IMC_DSPCSIF_S2C_IRQ_READ                    ((volatile UINT32P)(IMC_CSIF_BASE+0x8))
#define IMC_DSPCSIF_S2C_IRQ_CLR                     ((volatile UINT32P)(IMC_CSIF_BASE+0xC))
#define IMC_DSPCSIF_S2C_IRQ_ENABLE                  ((volatile UINT32P)(IMC_CSIF_BASE+0x10))
#define IMC_DSPCSIF_VAS_VALID                       ((volatile UINT32P)(IMC_CSIF_BASE+0x14))
#define IMC_DSPCSIF_VAS_ACK                         ((volatile UINT32P)(IMC_CSIF_BASE+0x18))
#define IMC_DSPCSIF_VAS_SKIP                        ((volatile UINT32P)(IMC_CSIF_BASE+0x1C))
#define IMC_DSPCSIF_TASK_ID                         ((volatile UINT32P)(IMC_CSIF_BASE+0x20))
#define IMC_DSPCSIF_GPI_S_READ                      ((volatile UINT32P)(IMC_CSIF_BASE+0x24))
#define IMC_DSPCSIF_GPI_C_SET                       ((volatile UINT32P)(IMC_CSIF_BASE+0x28))
#define IMC_DSPCSIF_GPI_C_CLEAR                     ((volatile UINT32P)(IMC_CSIF_BASE+0x2C))
#define IMC_DSPCSIF_GPI_C_READ                      ((volatile UINT32P)(IMC_CSIF_BASE+0x30))
#define IMC_DSPCSIF_CR4_ERROR                       ((volatile UINT32P)(IMC_CSIF_BASE+0x34))
#define IMC_DSPCSIF_CR4_ERROR_ENABLE                ((volatile UINT32P)(IMC_CSIF_BASE+0x38))
#define IMC_DSPCSIF_ERROR_C2S_OVFL                  ((volatile UINT32P)(IMC_CSIF_BASE+0x3C))
#define IMC_DSPCSIF_ERROR_C2S_OVFL_CLR              ((volatile UINT32P)(IMC_CSIF_BASE+0x40))
#define IMC_DSPCSIF_ERROR_S2C_OVFL                  ((volatile UINT32P)(IMC_CSIF_BASE+0x44))
#define IMC_DSPCSIF_ERROR_S2C_OVFL_CLR              ((volatile UINT32P)(IMC_CSIF_BASE+0x48))
#define IMC_DSPCSIF_ERROR_ACD_CONFLICT_CLR          ((volatile UINT32P)(IMC_CSIF_BASE+0x50))
#define IMC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR       ((volatile UINT32P)(IMC_CSIF_BASE+0x54))
#define IMC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR_CLR   ((volatile UINT32P)(IMC_CSIF_BASE+0x58))
#define IMC_DSPCSIF_DSP_RANGE_START_ADDR            ((volatile UINT32P)(IMC_CSIF_BASE+0x5C))
#define IMC_DSPCSIF_DSP_RANGE_SIZE                  ((volatile UINT32P)(IMC_CSIF_BASE+0x60))
#define IMC_DSPCSIF_CR4_RANGE_START_ADDR            ((volatile UINT32P)(IMC_CSIF_BASE+0x64))
#define IMC_DSPCSIF_CR4_RANGE_SIZE                  ((volatile UINT32P)(IMC_CSIF_BASE+0x68))

//for MPC core
#define MPC_DSPCSIF_C2S_IRQ_SET                     ((volatile UINT32P)(MPC_CSIF_BASE+0x0))
#define MPC_DSPCSIF_C2S_IRQ_READ                    ((volatile UINT32P)(MPC_CSIF_BASE+0x4))
#define MPC_DSPCSIF_S2C_IRQ_READ                    ((volatile UINT32P)(MPC_CSIF_BASE+0x8))
#define MPC_DSPCSIF_S2C_IRQ_CLR                     ((volatile UINT32P)(MPC_CSIF_BASE+0xC))
#define MPC_DSPCSIF_S2C_IRQ_ENABLE                  ((volatile UINT32P)(MPC_CSIF_BASE+0x10))
#define MPC_DSPCSIF_VAS_VALID                       ((volatile UINT32P)(MPC_CSIF_BASE+0x14))
#define MPC_DSPCSIF_VAS_ACK                         ((volatile UINT32P)(MPC_CSIF_BASE+0x18))
#define MPC_DSPCSIF_VAS_SKIP                        ((volatile UINT32P)(MPC_CSIF_BASE+0x1C))
#define MPC_DSPCSIF_TASK_ID                         ((volatile UINT32P)(MPC_CSIF_BASE+0x20))
#define MPC_DSPCSIF_GPI_S_READ                      ((volatile UINT32P)(MPC_CSIF_BASE+0x24))
#define MPC_DSPCSIF_GPI_C_SET                       ((volatile UINT32P)(MPC_CSIF_BASE+0x28))
#define MPC_DSPCSIF_GPI_C_CLEAR                     ((volatile UINT32P)(MPC_CSIF_BASE+0x2C))
#define MPC_DSPCSIF_GPI_C_READ                      ((volatile UINT32P)(MPC_CSIF_BASE+0x30))
#define MPC_DSPCSIF_CR4_ERROR                       ((volatile UINT32P)(MPC_CSIF_BASE+0x34))
#define MPC_DSPCSIF_CR4_ERROR_ENABLE                ((volatile UINT32P)(MPC_CSIF_BASE+0x38))
#define MPC_DSPCSIF_ERROR_C2S_OVFL                  ((volatile UINT32P)(MPC_CSIF_BASE+0x3C))
#define MPC_DSPCSIF_ERROR_C2S_OVFL_CLR              ((volatile UINT32P)(MPC_CSIF_BASE+0x40))
#define MPC_DSPCSIF_ERROR_S2C_OVFL                  ((volatile UINT32P)(MPC_CSIF_BASE+0x44))
#define MPC_DSPCSIF_ERROR_S2C_OVFL_CLR              ((volatile UINT32P)(MPC_CSIF_BASE+0x48))
#define MPC_DSPCSIF_ERROR_ACD_CONFLICT              ((volatile UINT32P)(MPC_CSIF_BASE+0x4C))
#define MPC_DSPCSIF_ERROR_ACD_CONFLICT_CLR          ((volatile UINT32P)(MPC_CSIF_BASE+0x50))
#define MPC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR       ((volatile UINT32P)(MPC_CSIF_BASE+0x54))
#define MPC_DSPCSIF_DSP_ERROR_DSM_ACCESS_ADDR_CLR   ((volatile UINT32P)(MPC_CSIF_BASE+0x58))
#define MPC_DSPCSIF_DSP_RANGE_START_ADDR            ((volatile UINT32P)(MPC_CSIF_BASE+0x5C))
#define MPC_DSPCSIF_DSP_RANGE_SIZE                  ((volatile UINT32P)(MPC_CSIF_BASE+0x60))
#define MPC_DSPCSIF_CR4_RANGE_START_ADDR            ((volatile UINT32P)(MPC_CSIF_BASE+0x64))
#define MPC_DSPCSIF_CR4_RANGE_SIZE                  ((volatile UINT32P)(MPC_CSIF_BASE+0x68))

#endif //__CSIF_R11G1_LOCAL_ASM_DEFINE_H__
