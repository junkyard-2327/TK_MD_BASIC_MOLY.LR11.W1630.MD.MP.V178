/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   emi.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file for EMI.
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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(__EMI_H__)
/* ==================== */
/*	CONFIGURATIONS		*/
/* ==================== */
/* ==================== */
/*	INCLUDES			*/
/* ==================== */
#include "emi_mt6290.h"
/* ================ */
/*	DEFINITIONS		*/
/* ================ */
/* ==================== */
/*	EXPORTED FUNCTIONS	*/
/* ==================== */
/*
 * Initiate EMI profiling counters
 */
kal_int32 emi_profiling_init();

/*
 * Start EMI profiling counters
 */
kal_int32 emi_profiling_start();

/*
 * Pause EMI profiling counters
 */
kal_int32 emi_profiling_pause();

/*
 * Clear EMI profiling counters
 */
kal_int32 emi_profiling_clear();

/*
 * Dump EMI profiling counters
 */
kal_int32 emi_profiling_dump();
#endif  /* !__EMI_H__ */
