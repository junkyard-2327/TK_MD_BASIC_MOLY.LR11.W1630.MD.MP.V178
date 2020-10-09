/*******************************************************************************
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
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   scc.h
 *
 * Project:
 * --------
 *   UMOLY
 *
 * Description:
 * ------------
 *   SCC External Header File
 *
 * Author:
 * -------
 * -------
 *
 * ============================================================================
 * $Log$
 *
 * 10 13 2015 gh.huang
 * [MOLY00126218] [TK6291][SIB_DRV] Update SCC/SDF Module for SIB Official Release - Add an API for Mu Window Force-On Indication
 *
 * 04 22 2015 gh.huang
 * [MOLY00098317] [TK6291][SIB_DRV] Add SDF Module and Migrate SCC to UMOLY Trunk - Change API/MSG names for PCC/PPC
 *
 * 04 21 2015 gh.huang
 * [MOLY00098317] [TK6291][SIB_DRV] Add SDF Module and Migrate SCC to UMOLY Trunk - Add PCC/BWL APIs and Messages
 *
 * 03 10 2015 gh.huang
 * [MOLY00098317] [TK6291][SIB_DRV] Add SDF Module and Migrate SCC to UMOLY Trunk
 *
 * 02 03 2015 gh.huang
 * [MOLY00093777] [TK6291][SIB_DRV] Add SCC Module Related Sources - Add Resource Lock and Enanble Option
 *
 *
 ****************************************************************************/

#ifndef __SCC_H__
#define __SCC_H__

/*******************************************************************************
 * Define exported macro
 ******************************************************************************/
#ifdef __PCORE__
#define SCC_ON_PCORE    1
#endif
#ifdef __L1CORE__
#define SCC_ON_L1CORE   1
#endif

/*******************************************************************************
 * Include header files
 ******************************************************************************/
#include "kal_general_types.h"
#include "reg_base.h"

#if SCC_ON_L1CORE
#include "drv_pcc.h"
#endif

/*******************************************************************************
 * Define data structure
 ******************************************************************************/
typedef enum {
   SCC_OK = 0,
   SCC_FAIL,
   SCC_DISABLED,
   SCC_RES_LOCKED,
   SCC_SDF_STARTED,
   SCC_FEATURE_NOT_SUPPORTED
} SCC_RESULT;

typedef enum {
   SCC_LINK_READY = 0,
   SCC_LINK_NOT_READY
} SCC_LINK_STATUS;

typedef enum {
   SCC_CAPTURE_NOT_RUNNING = 0,
   SCC_CAPTURE_RUNNING
} SCC_CAPTURE_STATUS;

typedef enum {
   MODEM_L1_PORT = 0,
   MTAD_PORT,
   C2K_PORT,
   LTEL2_PORT,
   PTRNGEN1_PORT,
   HSPAL2_PORT,
   SDF_PORT,
   FLUSH_MSTR_PORT,
   TOTAL_PORT_NUM
} CSTF_PORT;

typedef enum {
   SCC_SDF_8BIT_WIDTH,
   SCC_SDF_16BIT_WIDTH
} SCC_SDF_WIDTH_SEL;

typedef struct {
   kal_bool in_progress;
   kal_bool overflowed;
} SCC_SDF_STATUS;

typedef enum {
   SCC_MCULOG = 0,
   SCC_DSPLOG_MDL,
   SCC_DSPLOG_MDP,
   SCC_DSPLOG_MTOL,
   SCC_LOG_PATH_NUM
} SCC_LOG_PATH;

/*******************************************************************************
 * Define exported function prototype
 ******************************************************************************/

/*
 * [FUNCTION]
 *      Initialize SCC required resources
 *
 * [PARAMETERS]
 *      N/A
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - init operation succeeded
 *          SCC_FAIL - init operation failed
 */
SCC_RESULT scc_init();

/*
 * [FUNCTION]
 *      Get SIB's STP link status
 *
 * [PARAMETERS]
 *      *status:
 *          SCC_LINK_STATUS enum as a return value to indicate link ready or not ready
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - status has been got successfully
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 */
SCC_RESULT scc_link_status(SCC_LINK_STATUS *status);

/*
 * [FUNCTION]
 *      Allocate bandwidth for specified CSTF port
 *
 * [PARAMETERS]
 *      port:
 *          CSTF_PORT enum to specify CSTF port
 *
 *      MBps:
 *          Specified bandwidth in MBps
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - bandwidth allocation operation succeeded
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource 
 */
SCC_RESULT scc_bandwidth_alloc(CSTF_PORT port, kal_uint16 MBps);

/*
 * [FUNCTION]
 *      Get bandwidth allocation status for specified CSTF port
 *
 * [PARAMETERS]
 *      port:
 *          CSTF_PORT enum to specify CSTF port
 *
 *      *MBps:
 *          As a return value to indicate allocated bandwidth in MBps
 *
 *      *pct:
 *          As a return value to indicate allocated bandwidth percentage
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - status has been got successfully
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource 
 */
SCC_RESULT scc_bandwidth_status(CSTF_PORT port, kal_uint16 *MBps, kal_uint8 *pct);

#if SCC_ON_L1CORE
/*
 * [FUNCTION]
 *      Set PCC config and start PCC capture
 *
 * [PARAMETERS]
 *      enCapNode:
 *          EN_PCC_DFESYS_CAPTURE_NODE enum to specify capture node
 *
 *      *pstPathSel:
 *          As an input to specify selected path for capture
 *
 *      *pstDataInfoCfg:
 *          As an input to specify data config for capture
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - config&stop operation succeeded
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 */
SCC_RESULT scc_pcc_config_and_start(EN_PCC_DFESYS_CAPTURE_NODE enCapNode, ST_ATB_PATH_SEL *pstPathSel, ST_PCC_DATA_INFO_CONFIG *pstDataInfoCfg);

/*
 * [FUNCTION]
 *      Stop PCC capture
 *
 * [PARAMETERS]
 *      N/A
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - stop operation succeeded
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 */
SCC_RESULT scc_pcc_stop();

/*
 * [FUNCTION]
 *      Get PCC capture status
 *
 * [PARAMETERS]
 *      *status:
 *          As a return value to indicate PCC capture running or not running
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - status has been got successfully
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 */
SCC_RESULT scc_pcc_status(SCC_CAPTURE_STATUS *status);

/*
 * [FUNCTION]
 *      Set PCC compressor config
 *
 * [PARAMETERS]
 *      *pstCompCfg:
 *          As an input to specify compressor config
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - config operation succeeded
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 */
SCC_RESULT scc_pcc_compressor_config(ST_PCC_COMP_CONFIG *pstCompCfg);

/*
 * [FUNCTION]
 *      Set PCC antenna and RFcarrier config
 *
 * [PARAMETERS]
 *      *pstCompCfg:
 *          As an input to specify antenna and RFcarrier config
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - config operation succeeded
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 */
SCC_RESULT scc_pcc_an_ca_config(ST_PCC_ANTENNA_RFCARRIER_SEL *pstAntCarSel);

/*
 * [FUNCTION]
 *      Get PCC FIFO status
 *
 * [PARAMETERS]
 *      *pstFIFOStatus:
 *          As a return value to indicate FIFO status
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - status has been got successfully
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 */
SCC_RESULT scc_pcc_fifo_status(ST_PCC_FIFO_STATUS *pstFIFOStatus);
#endif

#if SCC_ON_L1CORE
SCC_RESULT scc_ppc_start();
SCC_RESULT scc_ppc_stop();
SCC_RESULT scc_ppc_config();
SCC_RESULT scc_ppc_status();
#endif

/*
 * [FUNCTION]
 *      Set SDF config
 *
 * [PARAMETERS]
 *      width:
 *          SCC_SDF_WIDTH_SEL enum to specify selected SDF signal width
 *
 *      en_bitmap:
 *          bitmap to specify enabled signals for SDF monitoring
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - config has been set successfully
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 *          SCC_SDF_STARTED - SDF is already in running state, and therefore could not be configured
 */
SCC_RESULT scc_sdf_config(SCC_SDF_WIDTH_SEL width, kal_uint32 en_bitmap);

/*
 * [FUNCTION]
 *      Get SDF status
 *
 * [PARAMETERS]
 *      *status:
 *          As a return value to indicate SDF's status
 *          - Whether running or not
 *          - Ever occurred overflow or not
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - status has been got successfully
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 */
SCC_RESULT scc_sdf_status(SCC_SDF_STATUS *status);

/*
 * [FUNCTION]
 *      Start SDF
 *
 * [PARAMETERS]
 *      N/A
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - SDF has been started successfully
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 */
SCC_RESULT scc_sdf_start();

/*
 * [FUNCTION]
 *      Stop SDF
 *
 * [PARAMETERS]
 *      N/A
 *
 * [RETURN]
 *      SCC_RESULT enum:
 *          SCC_OK - SDF has been stopped successfully
 *          SCC_FAIL - API operation failed due to SCC channel issue, and therefore need users to re-call API again
 *          SCC_DISABLED - SCC corresponding feature option not enabled
 *          SCC_RES_LOCKED - other thread is calling SCC API and using SCC resource
 */
SCC_RESULT scc_sdf_stop();

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
#endif

/*
 * [FUNCTION]
 *      Return if selected log path output is set to SIB or not
 *
 * [PARAMETERS]
 *      path:
 *          SCC_LOG_PATH enum to specify selected log path
 *
 * [RETURN]
 *      kal_bool:
 *          KAL_TRUE - log path is to SIB
 *          KAL_FLASE - log path is to EMI
 */
kal_bool scc_is_log_path_to_sib(SCC_LOG_PATH path);

#if SCC_ON_L1CORE
/*
 * [FUNCTION]
 *      Indicate if Mu window shall be forced on
 *
 * [PARAMETERS]
 *      N/A
 *
 * [RETURN]
 *      kal_bool:
 *          KAL_TRUE - Mu window shall be forced on
 *          KAL_FLASE - Mu window need not be forced on
 */
kal_bool scc_force_mu_on_ind();
#endif

#endif  /* !__SCC_H__ */
