/*****************************************************************************
 *
 * Filename:
 * ---------
 *   CSIF_Global_Variables.c
 *
 * Project:
 * --------
 *   R11GX Project depend on makefile configuration
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
*[File         ]       CSIF_Global_Variables.c
*[Version      ]       v1.0
*[Revision Date]       2014-06-10
*[Author       ]       Peng-Chih Wang
*[Description  ]
*    The program is for the CSIF interrupts handling.
*
*[Copyright]
*    Copyright (C) 2005 MediaTek Incorporation. All Rights Reserved.
**********************************************************************************************************************************************************
*/

//type define header file
#include "csif_local_define.h"

//global CSIF DMS base address for common folder extern
kal_uint32* const pICC_CSIF_DSM_BASE = (kal_uint32*)ICC_CSIF_DSM_BASE;
kal_uint32* const pIMC_CSIF_DSM_BASE = (kal_uint32*)IMC_CSIF_DSM_BASE;
kal_uint32* const pMPC_CSIF_DSM_BASE = (kal_uint32*)MPC_CSIF_DSM_BASE;

//Extern user callback prototype
#undef M_ICC_CSIF_INFO
#undef M_ICC_CSIF_ERR_INFO
#undef M_IMC_CSIF_INFO
#undef M_IMC_CSIF_ERR_INFO
#undef M_MPC_CSIF_INFO
#undef M_MPC_CSIF_ERR_INFO
#undef M_ICC_CSIF_Remote_Callback_INFO
#undef M_IMC_CSIF_Remote_Callback_INFO
#undef M_MPC_CSIF_Remote_Callback_INFO
#define M_ICC_CSIF_INFO(CSIFHandler, Code, Value) extern void CSIFHandler(kal_uint32);
#define M_ICC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) extern void CSIFErrHandler(kal_uint32);
#define M_IMC_CSIF_INFO(CSIFHandler, Code, Value) extern void CSIFHandler(kal_uint32);
#define M_IMC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) extern void CSIFErrHandler(kal_uint32);
#define M_MPC_CSIF_INFO(CSIFHandler, Code, Value) extern void CSIFHandler(kal_uint32);
#define M_MPC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) extern void CSIFErrHandler(kal_uint32);
#define M_ICC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) extern void CSIFCallback(kal_uint32); 
#define M_IMC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) extern void CSIFCallback(kal_uint32);  
#define M_MPC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) extern void CSIFCallback(kal_uint32);  
#include "csif_config.h"

//CSIF handler function pointer array
kal_uint32 pfICCCSIFFunc[ICC_CSIF_INTERRUPT_NUM] =
{
    #undef M_ICC_CSIF_INFO
    #undef M_ICC_CSIF_ERR_INFO
    #undef M_IMC_CSIF_INFO
    #undef M_IMC_CSIF_ERR_INFO
    #undef M_MPC_CSIF_INFO
    #undef M_MPC_CSIF_ERR_INFO
    #undef M_ICC_CSIF_Remote_Callback_INFO
    #undef M_IMC_CSIF_Remote_Callback_INFO
    #undef M_MPC_CSIF_Remote_Callback_INFO
    #define M_ICC_CSIF_INFO(CSIFHandler, Code, Value) (kal_uint32)&(CSIFHandler),
    #define M_ICC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_IMC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_IMC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) 
    #define M_MPC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_MPC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) 
    #define M_ICC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    #define M_IMC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE)
    #define M_MPC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    
    #include "csif_config.h"
    
};

//CSIF error handler function pointer array
kal_uint32 pfICCCSIFErrFunc[ICC_CSIF_ERR_INTERRUPT_NUM] =
{
    #undef M_ICC_CSIF_INFO
    #undef M_ICC_CSIF_ERR_INFO
    #undef M_IMC_CSIF_INFO
    #undef M_IMC_CSIF_ERR_INFO
    #undef M_MPC_CSIF_INFO
    #undef M_MPC_CSIF_ERR_INFO
    #undef M_ICC_CSIF_Remote_Callback_INFO
    #undef M_IMC_CSIF_Remote_Callback_INFO
    #undef M_MPC_CSIF_Remote_Callback_INFO
    #define M_ICC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_ICC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) (kal_uint32)&(CSIFErrHandler),
    #define M_IMC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_IMC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) 
    #define M_MPC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_MPC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) 
    #define M_ICC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    #define M_IMC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE)
    #define M_MPC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    
    #include "csif_config.h"
    
};

kal_uint32 pfIMCCSIFFunc[IMC_CSIF_INTERRUPT_NUM] =
{
    #undef M_ICC_CSIF_INFO
    #undef M_ICC_CSIF_ERR_INFO
    #undef M_IMC_CSIF_INFO
    #undef M_IMC_CSIF_ERR_INFO
    #undef M_MPC_CSIF_INFO
    #undef M_MPC_CSIF_ERR_INFO
    #undef M_ICC_CSIF_Remote_Callback_INFO
    #undef M_IMC_CSIF_Remote_Callback_INFO
    #undef M_MPC_CSIF_Remote_Callback_INFO
    #define M_ICC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_ICC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_IMC_CSIF_INFO(CSIFHandler, Code, Value) (kal_uint32)&(CSIFHandler),
    #define M_IMC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) 
    #define M_MPC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_MPC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) 
    #define M_ICC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    #define M_IMC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE)
    #define M_MPC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    
    #include "csif_config.h"
    
};

//CSIF error handler function pointer array
kal_uint32 pfIMCCSIFErrFunc[IMC_CSIF_ERR_INTERRUPT_NUM] =
{
    #undef M_ICC_CSIF_INFO
    #undef M_ICC_CSIF_ERR_INFO
    #undef M_IMC_CSIF_INFO
    #undef M_IMC_CSIF_ERR_INFO
    #undef M_MPC_CSIF_INFO
    #undef M_MPC_CSIF_ERR_INFO
    #undef M_ICC_CSIF_Remote_Callback_INFO
    #undef M_IMC_CSIF_Remote_Callback_INFO
    #undef M_MPC_CSIF_Remote_Callback_INFO
    #define M_ICC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_ICC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_IMC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_IMC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) (kal_uint32)&(CSIFErrHandler),
    #define M_MPC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_MPC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_ICC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    #define M_IMC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE)
    #define M_MPC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    
    #include "csif_config.h"
    
};

kal_uint32 pfMPCCSIFFunc[MPC_CSIF_INTERRUPT_NUM] =
{
    #undef M_ICC_CSIF_INFO
    #undef M_ICC_CSIF_ERR_INFO
    #undef M_IMC_CSIF_INFO
    #undef M_IMC_CSIF_ERR_INFO
    #undef M_MPC_CSIF_INFO
    #undef M_MPC_CSIF_ERR_INFO    
    #undef M_ICC_CSIF_Remote_Callback_INFO
    #undef M_IMC_CSIF_Remote_Callback_INFO
    #undef M_MPC_CSIF_Remote_Callback_INFO
    #define M_ICC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_ICC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_IMC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_IMC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_MPC_CSIF_INFO(CSIFHandler, Code, Value) (kal_uint32)&(CSIFHandler),
    #define M_MPC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_ICC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    #define M_IMC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE)
    #define M_MPC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    
    #include "csif_config.h"
    
};

//CSIF error handler function pointer array
kal_uint32 pfMPCCSIFErrFunc[MPC_CSIF_ERR_INTERRUPT_NUM] =
{
    #undef M_ICC_CSIF_INFO
    #undef M_ICC_CSIF_ERR_INFO
    #undef M_IMC_CSIF_INFO
    #undef M_IMC_CSIF_ERR_INFO
    #undef M_MPC_CSIF_INFO
    #undef M_MPC_CSIF_ERR_INFO
    #undef M_ICC_CSIF_Remote_Callback_INFO
    #undef M_IMC_CSIF_Remote_Callback_INFO
    #undef M_MPC_CSIF_Remote_Callback_INFO
    #define M_ICC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_ICC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_IMC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_IMC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_MPC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_MPC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) (kal_uint32)&(CSIFErrHandler),
    #define M_ICC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    #define M_IMC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE)
    #define M_MPC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 

    #include "csif_config.h"
    
};

//CSIF remote callback function pointer array
kal_uint32 pfICCCSIFRemoteCallbackFunc[ICC_CSIF_Remote_Callback_INTERRUPT_NUM] =
{
    #undef M_ICC_CSIF_INFO
    #undef M_ICC_CSIF_ERR_INFO
    #undef M_IMC_CSIF_INFO
    #undef M_IMC_CSIF_ERR_INFO
    #undef M_MPC_CSIF_INFO
    #undef M_MPC_CSIF_ERR_INFO
    #undef M_ICC_CSIF_Remote_Callback_INFO
    #undef M_IMC_CSIF_Remote_Callback_INFO
    #undef M_MPC_CSIF_Remote_Callback_INFO
    #define M_ICC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_ICC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_IMC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_IMC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_MPC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_MPC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) 
    #define M_ICC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) (kal_uint32)&(CSIFCallback), 
    #define M_IMC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE)
    #define M_MPC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 

    #include "csif_config.h"
    
};
kal_uint32 pfIMCCSIFRemoteCallbackFunc[IMC_CSIF_Remote_Callback_INTERRUPT_NUM] =
{
    #undef M_ICC_CSIF_INFO
    #undef M_ICC_CSIF_ERR_INFO
    #undef M_IMC_CSIF_INFO
    #undef M_IMC_CSIF_ERR_INFO
    #undef M_MPC_CSIF_INFO
    #undef M_MPC_CSIF_ERR_INFO
    #undef M_ICC_CSIF_Remote_Callback_INFO
    #undef M_IMC_CSIF_Remote_Callback_INFO
    #undef M_MPC_CSIF_Remote_Callback_INFO
    #define M_ICC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_ICC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_IMC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_IMC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_MPC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_MPC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) 
    #define M_ICC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 
    #define M_IMC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) (kal_uint32)&(CSIFCallback), 
    #define M_MPC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) 

    #include "csif_config.h"
    
};
kal_uint32 pfMPCCSIFRemoteCallbackFunc[MPC_CSIF_Remote_Callback_INTERRUPT_NUM] =
{
    #undef M_ICC_CSIF_INFO
    #undef M_ICC_CSIF_ERR_INFO
    #undef M_IMC_CSIF_INFO
    #undef M_IMC_CSIF_ERR_INFO
    #undef M_MPC_CSIF_INFO
    #undef M_MPC_CSIF_ERR_INFO
    #undef M_ICC_CSIF_Remote_Callback_INFO
    #undef M_IMC_CSIF_Remote_Callback_INFO
    #undef M_MPC_CSIF_Remote_Callback_INFO
    #define M_ICC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_ICC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_IMC_CSIF_INFO(CSIFHandler, Code, Value) 
    #define M_IMC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value)
    #define M_MPC_CSIF_INFO(CSIFHandler, Code, Value)
    #define M_MPC_CSIF_ERR_INFO(CSIFErrHandler, Code, Value) 
    #define M_ICC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE)
    #define M_IMC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE)
    #define M_MPC_CSIF_Remote_Callback_INFO(CSIFCallback, CODE) (kal_uint32)&(CSIFCallback),  

    #include "csif_config.h"
    
};
#undef M_ICC_CSIF_INFO
#undef M_ICC_CSIF_ERR_INFO
#undef M_IMC_CSIF_INFO
#undef M_IMC_CSIF_ERR_INFO
#undef M_MPC_CSIF_INFO
#undef M_MPC_CSIF_ERR_INFO
#undef M_ICC_CSIF_Remote_Callback_INFO
#undef M_IMC_CSIF_Remote_Callback_INFO
#undef M_MPC_CSIF_Remote_Callback_INFO
