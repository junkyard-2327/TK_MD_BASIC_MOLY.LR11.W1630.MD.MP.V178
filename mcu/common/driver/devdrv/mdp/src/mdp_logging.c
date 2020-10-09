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
 *   mdp_logging.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Definition of MDP Logging 
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 06 03 2015 peng-chih.wang
 * [MOLY00118217] L1core / DSP Common Header Switch
 * common header switch.
 *
 * 05 06 2015 peng-chih.wang
 * [MOLY00110712] [TK6291] phase-in mcu side MDP driver
 * resolve PCBIT error.
 *
 ****************************************************************************/
    
#if defined(__MTK_TARGET__)
    #include "dsp_header_define_csif.h"
    
    //configure MDP buffer size 
    #define MDP_EMI_BUF_SIZE_1KB      (0x400)
    #define MDP_EMI_BUF_SIZE_256KB    (0x40000)
    #define MDP_EMI_BUF_SIZE_512KB    (0x80000)
    #define MDP_EMI_BUF_SIZE_1MB      (0x100000)
    #define MDP_EMI_BUF_SIZE_2MB      (0x200000)
    #define MDP_EMI_BUF_SIZE_4MB      (0x400000)
    #define MDP_EMI_BUF_SIZE_8MB      (0x800000)
    #define MDP_EMI_BUF_SIZE_16MB     (0x1000000)
    #define MDP_EMI_BUF_SIZE_32MB     (0x2000000)
    #define MDP_EMI_BUF_SIZE_64MB     (0x4000000)

    #define MDP_LOGGING_BUF_SIZE_ICC  (MDP_EMI_BUF_SIZE_512KB)
    #define MDP_LOGGING_BUF_SIZE_IMC  (MDP_EMI_BUF_SIZE_512KB)
    #define MDP_LOGGING_BUF_SIZE_MPC  (MDP_EMI_BUF_SIZE_512KB)
#if defined(__PCORE__)
    #include "mdl_logging.h"
    #include "kal_general_types.h"
    //allocate MDP buffer
    DEFINE_DNC_ALIGNED_SHARED_ARRAY(kal_uint32, mdp_logging_buf_icc, (MDP_LOGGING_BUF_SIZE_ICC/4), 64)
    DEFINE_DNC_ALIGNED_SHARED_ARRAY(kal_uint32, mdp_logging_buf_imc, (MDP_LOGGING_BUF_SIZE_IMC/4), 64)
    DEFINE_DNC_ALIGNED_SHARED_ARRAY(kal_uint32, mdp_logging_buf_mpc, (MDP_LOGGING_BUF_SIZE_MPC/4), 64) 
    
    //shared buffer address info
    #define g_mdp_logging_buf_icc       SHARED_ARRAY(mdp_logging_buf_icc)
    #define g_mdp_logging_buf_imc       SHARED_ARRAY(mdp_logging_buf_imc)
    #define g_mdp_logging_buf_mpc       SHARED_ARRAY(mdp_logging_buf_mpc)  
    
    //shared buffer pointer info
    //volatile unsigned int g_mdp_logging_buf_icc_ptr = (unsigned int)(g_mdp_logging_buf_icc);
    //volatile unsigned int g_mdp_logging_buf_imc_ptr = (unsigned int)(g_mdp_logging_buf_imc);
    //volatile unsigned int g_mdp_logging_buf_mpc_ptr = (unsigned int)(g_mdp_logging_buf_mpc);
    
    //shared buffer size info
    volatile kal_uint32 g_mdp_logging_buf_icc_size = MDP_LOGGING_BUF_SIZE_ICC;
    volatile kal_uint32 g_mdp_logging_buf_imc_size = MDP_LOGGING_BUF_SIZE_IMC;
    volatile kal_uint32 g_mdp_logging_buf_mpc_size = MDP_LOGGING_BUF_SIZE_MPC;
    
    //function prototype
    void MdpBufferInit(void);
    
    //MdlConfigStruct_t g_mdl_config[MDL_LOGGING_CHANNEL_NUM];
    /*************************************************************************
    * FUNCTION
    *  MdpBufferInit
    *
    * DESCRIPTION
    *  This function is to registry MDP shared buffer info for ICC/IMC/MPC.
    *
    * PARAMETERS
    *  N/A
    *
    * RETURNS
    *  N/A
    *
    *************************************************************************/
    void MdpBufferInit()
    {
        //ICC
        g_mdl_config[EBC_MDP_ICC_ID].enable = 1;
        g_mdl_config[EBC_MDP_ICC_ID].id = EBC_MDP_ICC_ID;    
        g_mdl_config[EBC_MDP_ICC_ID].buf_addr = g_mdp_logging_buf_icc;
        g_mdl_config[EBC_MDP_ICC_ID].buf_size = g_mdp_logging_buf_icc_size;
    
        //IMC
        g_mdl_config[EBC_MDP_IMC_ID].enable = 1;
        g_mdl_config[EBC_MDP_IMC_ID].id = EBC_MDP_IMC_ID;    
        g_mdl_config[EBC_MDP_IMC_ID].buf_addr = g_mdp_logging_buf_imc;
        g_mdl_config[EBC_MDP_IMC_ID].buf_size = g_mdp_logging_buf_imc_size;
    
        //MPC
        g_mdl_config[EBC_MDP_MPC_ID].enable = 1;
        g_mdl_config[EBC_MDP_MPC_ID].id = EBC_MDP_MPC_ID;    
        g_mdl_config[EBC_MDP_MPC_ID].buf_addr = g_mdp_logging_buf_mpc;
        g_mdl_config[EBC_MDP_MPC_ID].buf_size = g_mdp_logging_buf_mpc_size;
    }
    
#elif defined(__L1CORE__)
#if 0//nvram feature
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
	#include "kal_general_types.h"
    #include "kal_public_api.h"
    #include "kal_public_defs.h"
    //allocate MDP buffer
    DEFINE_NC_SHARED_ARRAY(kal_uint32, mdp_logging_buf_icc, (MDP_LOGGING_BUF_SIZE_ICC/4))
    DEFINE_NC_SHARED_ARRAY(kal_uint32, mdp_logging_buf_imc, (MDP_LOGGING_BUF_SIZE_IMC/4))
    DEFINE_NC_SHARED_ARRAY(kal_uint32, mdp_logging_buf_mpc, (MDP_LOGGING_BUF_SIZE_MPC/4))
    
    //allocate MDP setting from nvram
    volatile kal_uint32 g_mdp_setting=0; //default disable
    volatile kal_uint32 g_mdp_el1_send_req;
    volatile kal_uint32 g_mdp_nvram_read_ready;

#if 0//nvram feature    
/* under construction !*/
/* under construction !*/
#endif
    
    //shared buff address info
    #define g_mdp_logging_buf_icc       SHARED_ARRAY(mdp_logging_buf_icc)
    #define g_mdp_logging_buf_imc       SHARED_ARRAY(mdp_logging_buf_imc)
    #define g_mdp_logging_buf_mpc       SHARED_ARRAY(mdp_logging_buf_mpc) 
    
    //shared buff size info
    volatile kal_uint32 g_mdp_logging_buf_icc_size = MDP_LOGGING_BUF_SIZE_ICC;
    volatile kal_uint32 g_mdp_logging_buf_imc_size = MDP_LOGGING_BUF_SIZE_IMC;
    volatile kal_uint32 g_mdp_logging_buf_mpc_size = MDP_LOGGING_BUF_SIZE_MPC;
    
    //function prototype
    void mdp_csif_init(void);
#if 0//nvram feature  	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
    /*************************************************************************
    * FUNCTION
    *  mdp_csif_init
    *
    * DESCRIPTION
    *  This function is to pass MDP buffer info to CoreSonic within CSIF DSM.
    *
    * PARAMETERS
    *  N/A
    *
    * RETURNS
    *  N/A
    *
    *************************************************************************/
    void mdp_csif_init()
    {
#if 0//nvram feature  	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        {
#if 0//nvram feature  			
/* under construction !*/
/* under construction !*/
#endif

#if 0 //to-do-list: to resolve PCBIT error
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
    }

#if 0//nvram feature  	    
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
#endif //__PCORE__

#else
    void MdpBufferInit(void)
    {
    }
    void mdp_csif_init(void)
    {
    }
#if 0//nvram feature  		
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
#endif //__MTK_TARGET__
