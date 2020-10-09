/*****************************************************************************
 *
 * Filename:
 * ---------
 *   CSIF_R11G1_Config.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by Perforce. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
**********************************************************************************************************************************************************
*[File         ]       CSIF_R11G1_Config.h
*[Version      ]       v1.0
*[Revision Date]       2014-06-10
*[Author       ]       Peng-Chih Wang
*[Description  ]
*    The program is for the R11G1 CSIF interrupts callback registry table header file.
*
*[Copyright]
*    Copyright (C) 2005 MediaTek Incorporation. All Rights Reserved.
**********************************************************************************************************************************************************
*/

//registry ICC core callback (core index = 0)
            //CSIF handler      code
#if defined(__EL1D_ENABLE__)            
M_ICC_CSIF_INFO(EL1D_LPWR_SLP_Process_Sleep_Ack_From_ICC,   ICC_ID0,	0)
M_ICC_CSIF_INFO(EL1D_Sonic_CsifIrqICC,   ICC_ID1,	1)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID2,	2)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID3,	3)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID4,	4)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID5,	5)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID6,	6)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID7,	7)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID8,	8)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID9,	9)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID10,	10)
M_ICC_CSIF_INFO(EL1D_RxDspRpt_AFC_IRQ_Handler,   ICC_ID11,	11)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID12,	12)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID13,	13)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID14,	14)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID15,	15)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID16,	16)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID17,	17)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID18,	18)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID19,	19)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID20,	20)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID21,	21)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID22,	22)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID23,	23)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID24,	24)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID25,	25)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID26,	26)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID27,	27)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID28,	28)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID29,	29)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID30,	30)
M_ICC_CSIF_INFO(CSIF_Remote_Callback_ICC,   ICC_RemoteCallback,	31)
//CSIF error handler,    code
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_C2S_IRQ_OVFL,	0)
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_S2S_IRQ_OVFL,	1)
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_GPI,	2)
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_MPU,	3)
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_WRITE_ERR,	4)
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_READ_ERR,	5)
M_ICC_CSIF_ERR_INFO(CS_SRAM_CTRL_ICC_ERROR,   ICC_SRAM_CTRL_ERR_0,	6)
M_ICC_CSIF_ERR_INFO(CS_SRAM_CTRL_ICC_ERROR,   ICC_SRAM_CTRL_ERR_1,	7)
#if (!defined(CSIF_REMOTE_TEST))
//CSIF ICC remote callbck
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Remote_callback_ZI_Backup, ZI_Back_Up)
#endif
#if (defined(CSIF_MOMORY_BACKUP_TEST))
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Memory_Callback_Pass, Memory_Check)
#elif (defined(CSIF_REMOTE_TEST))
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_0, 0)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_1, 1)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_2, 2)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_3, 3)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_4, 4)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_5, 5)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_6, 6)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_7, 7)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_8, 8)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_9, 9)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_10, A)
M_ICC_CSIF_Remote_Callback_INFO(CSIF_Prestest_11, B)
#endif

//registry IMC core callback (core index = 1)
            //CSIF handler      code
M_IMC_CSIF_INFO(EL1D_LPWR_SLP_Process_Sleep_Ack_From_IMC,   IMC_ID0,	0)
M_IMC_CSIF_INFO(EL1D_Sonic_CsifIrqIMC,   IMC_ID1,	1)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID2,	2)
M_IMC_CSIF_INFO(EL1D_RxLPwr_Idle_Inner_Abort_Dump_Handler,   IMC_ID3,	3)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID4,	4)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID5,	5)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID6,	6)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID7,	7)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID8,	8)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID9,	9)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID10,	10)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID11,	11)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID12,	12)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID13,	13)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID14,	14)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID15,	15)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID16,	16)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID17,	17)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID18,	18)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID19,	19)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID20,	20)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID21,	21)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID22,	22)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID23,	23)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID24,	24)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID25,	25)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID26,	26)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID27,	27)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID28,	28)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID29,	29)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID30,	30)
M_IMC_CSIF_INFO(CSIF_Remote_Callback_IMC,   IMC_RemoteCallback,	31)
                //CSIF error handler,    code
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_C2S_IRQ_OVFL, 	0)
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_S2S_IRQ_OVFL,	1)
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_GPI,	2)
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_MPU,	3)
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_WRITE_ERR,	4)
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_READ_ERR,	5)
M_IMC_CSIF_ERR_INFO(CS_SRAM_CTRL_IMC_ERROR,   IMC_SRAM_CTRL_ERR_0,	6)
M_IMC_CSIF_ERR_INFO(CS_SRAM_CTRL_MMU_ERROR,   MMU_SRAM_CTRL_ERR_0,	7)
#if (!defined(CSIF_REMOTE_TEST))
//CSIF IMC remote callbck
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Remote_callback_ZI_Backup, ZI_Back_Up)
#endif
#if (defined(CSIF_MOMORY_BACKUP_TEST))
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Memory_Callback_Pass, Memory_Check)
#elif (defined(CSIF_REMOTE_TEST))
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_0, 0)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_1, 1)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_2, 2)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_3, 3)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_4, 4)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_5, 5)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_6, 6)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_7, 7)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_8, 8)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_9, 9)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_10, A)
M_IMC_CSIF_Remote_Callback_INFO(CSIF_Prestest_11, B)
#endif
//registry MPC core callback (core index = 2)
            //CSIF handler      code
M_MPC_CSIF_INFO(EL1D_LPWR_SLP_Process_Sleep_Ack_From_MPC,   MPC_ID0,	0)
M_MPC_CSIF_INFO(EL1D_Sonic_CsifIrqMPC,   MPC_ID1,	1)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID2,	2)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID3,	3)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID4,	4)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID5,	5)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID6,	6)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID7,	7)
M_MPC_CSIF_INFO(EL1D_POS_MEAS_MPC_TD2FD_DONE_ISR,   MPC_ID8,	8)
M_MPC_CSIF_INFO(EL1D_POS_MEAS_MPC_PERCEELL_DONE_ISR,   MPC_ID9,	9)
M_MPC_CSIF_INFO(EL1D_POS_MEAS_MPC_PERCEELL_DONE_ISR,   MPC_ID10,	10)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID11,	11)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID12,	12)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID13,	13)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID14,	14)
M_MPC_CSIF_INFO(EL1D_POS_MEAS_MPC_ABORT_DONE_ISR,   MPC_ID15,	15)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID16,	16)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID17,	17)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID18,   18)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID19,	19)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID20,	20)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID21,   21)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID22,   22)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID23,	23)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID24,	24)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID25,   25)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID26,   26)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID27,   27)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID28,   28)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID29,   29)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID30,   30)
M_MPC_CSIF_INFO(CSIF_Remote_Callback_MPC,   MPC_RemoteCallback,   31)
                //CSIF error handler,    code
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_C2S_IRQ_OVFL, 	0)
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_S2S_IRQ_OVFL, 	1)
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_GPI, 	2)
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_MPU, 	3)
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_WRITE_ERR,	4)
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_READ_ERR,	5)
M_MPC_CSIF_ERR_INFO(CS_SRAM_CTRL_MPC_ERROR,   MPC_SRAM_CTRL_ERR_0,	6)
M_MPC_CSIF_ERR_INFO(CS_SRAM_CTRL_MPC_ERROR,   MPC_SRAM_CTRL_ERR_1,	7)
#if (!defined(CSIF_REMOTE_TEST))
//CSIF MPC remote callbck
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Remote_callback_ZI_Backup, ZI_Back_Up)
#endif
#if (defined(CSIF_MOMORY_BACKUP_TEST))
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Memory_Callback_Pass, Memory_Check)
#elif (defined(CSIF_REMOTE_TEST))
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_0, 0)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_1, 1)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_2, 2)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_3, 3)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_4, 4)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_5, 5)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_6, 6)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_7, 7)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_8, 8)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_9, 9)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_10, A)
M_MPC_CSIF_Remote_Callback_INFO(CSIF_Prestest_11, B)
#endif

#else //__EL1D_ENABLE__
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID0,	0)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID1,  1)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID2,	2)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID3,	3)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID4,	4)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID5,	5)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID6,	6)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID7,	7)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID8,	8)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID9,	9)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID10,	10)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID11,	11)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID12,	12)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID13,	13)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID14,	14)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID15,	15)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID16,	16)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID17,	17)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID18,	18)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID19,	19)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID20,	20)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID21,	21)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID22,	22)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID23,	23)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID24,	24)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID25,	25)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID26,	26)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID27,	27)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID28,	28)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID29,	29)
M_ICC_CSIF_INFO(CSIF_Invalid,   ICC_ID30,	30)
M_ICC_CSIF_INFO(CSIF_Remote_Callback_ICC,   ICC_RemoteCallback,	31)
                //CSIF error handler,    code
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_C2S_IRQ_OVFL,	0)
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_S2S_IRQ_OVFL,	1)
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_GPI,	2)
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_MPU,	3)
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_WRITE_ERR,	4)
M_ICC_CSIF_ERR_INFO(CSIF_Invalid,   ICC_READ_ERR,	5)
M_ICC_CSIF_ERR_INFO(CS_SRAM_CTRL_ICC_ERROR,   ICC_SRAM_CTRL_ERR_0,	6)
M_ICC_CSIF_ERR_INFO(CS_SRAM_CTRL_ICC_ERROR,   ICC_SRAM_CTRL_ERR_1,	7)

//registry IMC core callback (core index = 1)
            //CSIF handler      code
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID0,	0)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID1,	1)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID2,	2)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID3,	3)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID4,	4)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID5,	5)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID6,	6)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID7,	7)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID8,	8)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID9,	9)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID10,	10)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID11,	11)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID12,	12)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID13,	13)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID14,	14)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID15,	15)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID16,	16)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID17,	17)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID18,	18)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID19,	19)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID20,	20)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID21,	21)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID22,	22)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID23,	23)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID24,	24)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID25,	25)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID26,	26)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID27,	27)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID28,	28)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID29,	29)
M_IMC_CSIF_INFO(CSIF_Invalid,   IMC_ID30,	30)
M_IMC_CSIF_INFO(CSIF_Remote_Callback_IMC,   IMC_RemoteCallback,	31)
                //CSIF error handler,    code
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_C2S_IRQ_OVFL, 	0)
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_S2S_IRQ_OVFL,	1)
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_GPI,	2)
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_MPU,	3)
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_WRITE_ERR,	4)
M_IMC_CSIF_ERR_INFO(CSIF_Invalid,   IMC_READ_ERR,	5)
M_IMC_CSIF_ERR_INFO(CS_SRAM_CTRL_IMC_ERROR,   IMC_SRAM_CTRL_ERR_0,	6)
M_IMC_CSIF_ERR_INFO(CS_SRAM_CTRL_MMU_ERROR,   MMU_SRAM_CTRL_ERR_0,	7)

//registry MPC core callback (core index = 2)
            //CSIF handler      code
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID0,	0)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID1,	1)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID2,	2)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID3,	3)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID4,	4)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID5,	5)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID6,	6)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID7,	7)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID8,	8)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID9,	9)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID10,	10)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID11,	11)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID12,	12)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID13,	13)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID14,	14)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID15,	15)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID16,	16)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID17,	17)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID18,   18)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID19,	19)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID20,	20)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID21,   21)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID22,   22)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID23,	23)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID24,	24)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID25,   25)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID26,   26)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID27,   27)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID28,   28)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID29,   29)
M_MPC_CSIF_INFO(CSIF_Invalid,   MPC_ID30,   30)
M_MPC_CSIF_INFO(CSIF_Remote_Callback_MPC,   MPC_RemoteCallback,   31)
                //CSIF error handler,    code
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_C2S_IRQ_OVFL, 	0)
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_S2S_IRQ_OVFL, 	1)
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_GPI, 	2)
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_MPU, 	3)
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_WRITE_ERR,	4)
M_MPC_CSIF_ERR_INFO(CSIF_Invalid,   MPC_READ_ERR,	5)
M_MPC_CSIF_ERR_INFO(CS_SRAM_CTRL_MPC_ERROR,   MPC_SRAM_CTRL_ERR_0,	6)
M_MPC_CSIF_ERR_INFO(CS_SRAM_CTRL_MPC_ERROR,   MPC_SRAM_CTRL_ERR_1,	7)

#endif // __EL1D_ENABLE__

