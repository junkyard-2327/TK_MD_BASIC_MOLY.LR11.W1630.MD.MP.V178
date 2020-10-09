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
 * -----------
 *   drv_mdap_interface.c
 *
 * Project:
 * -----------
 *   UMOLY
 *
 * Description:
 * ------------
 *   MD/AP interface driver related code
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
 *
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
 *
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
 *
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
 *
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_mdap_interface.h"
#include "reg_base.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

//not enable on TK6291
#if (defined(MT6755) || defined(MT6797) || defined(MT6757) || defined(MT6750S)) && defined(__MTK_TARGET__)
#define APMDINTERFACE_ENABLE

#if defined(MT6797)
#include "drv_hisr.h"
#define APMDINTERFACE_ENABLE_LISR
#endif

#endif


#define AP2MD_DBG_HISTORYCNT	32
#define AP2MD_HISR_CALLBACKCNT		16

typedef struct _AP2MD_DBGINFO {
	kal_uint32	u32AP2MD_Lisr_Src;
	kal_uint32	u32AP2MD_Lisr_Dst;
	kal_uint32	u32AP2MD_Hisr0_Src;
	kal_uint32	u32AP2MD_Hisr0_Dst;
	kal_uint32	u32AP2MD_Hisr1_Src;
	kal_uint32	u32AP2MD_Hisr1_Dst;

	kal_uint32	u32AP2MD_Hisr_waitcnt;
} AP2MD_DBGINFO;



typedef struct _MDAP_INTERFACE_INFO {
	kal_uint32	u32MD2AP_InitStatus;
	kal_uint32	u32AP2MD_InitStatus;
	kal_uint32	u32MD2AP_Status;
	kal_uint32	u32AP2MD_Status;

	kal_uint32	u32MD2AP_SetIndex;
	kal_uint32	u32MD2AP_ClrIndex;
	kal_uint32		u32MD2AP_HistoryIndex;

	kal_bool		u32AP2MD_Lisr_FromSCP[AP2MD_HISR_CALLBACKCNT];
	AP2MD_DBGINFO	APMD_History[AP2MD_DBG_HISTORYCNT];
	
	kal_uint32	u32Reserve[10];
} MDAP_INTERFACE_INFO;


/*******************************************************************************
 * Functions
 *******************************************************************************/
void Drv_MDAPInterface_PS_LISR(void);
void Drv_MDAPInterface_L1_LISR(void);
void Drv_MDAPInterface_PS_HISR(void);
void Drv_MDAPInterface_L1_HISR(void);

#if defined(APMDINTERFACE_ENABLE)

#include "intrCtrl.h"

#define BASE_MD_TOP_DCM 0xF0130000
 
#define MD2SPM_DVFS_CON	(volatile kal_uint32 *)(BASE_MD_TOP_DCM + 0xC00)
#define MD2SPM_DVFS_SET	(volatile kal_uint32 *)(BASE_MD_TOP_DCM + 0xC04)
#define MD2SPM_DVFS_CLR	(volatile kal_uint32 *)(BASE_MD_TOP_DCM + 0xC08)

#define SPM2MD_DVFS_CON	(volatile kal_uint32 *)(BASE_MD_TOP_DCM + 0xC0C)



#if defined(__PCORE__)
#define MDAP_INTERFACE_IRQCODE	IRQ_SPM2MD_DVFS_MDPERISYS_CODE

#if defined(APMDINTERFACE_ENABLE_LISR)	//if enable LISR mechanism
#define MDSYS_TOP_CTL_0			(volatile kal_uint32 *)(BASE_MADDR_MDPERIMISC + 0x400)
#define SPM2MD_SRC_CON			(volatile kal_uint32 *)(BASE_MADDR_SCP_CFGREG + 0x2030)

#define HISR_CLR_WAITCNT		100
static kal_uint32 				u32_AP2MD_HistoryCnt = 0;
static DRV_AP2MD_HISRCALLBACK	ap2md_hisr_callback[AP2MD_HISR_CALLBACKCNT];

#endif

#elif defined(__L1CORE__)
#define MDAP_INTERFACE_IRQCODE	IRQ_MD2L1_DVFS_CODE
#endif

static MDAP_INTERFACE_INFO		mdap_interface_info = {0};
static kal_hisrid 				mdap_interface_hisrid;


kal_bool _Drv_MD2AP_SetScenario(MD2AP_SCENARIO value)
{
	//write 1 enable
	*MD2SPM_DVFS_SET = value;
	return KAL_TRUE;
}

kal_bool _Drv_MD2AP_ClearScenario(MD2AP_SCENARIO value)
{
	//write 1 clear
	*MD2SPM_DVFS_CLR = value;
	return KAL_TRUE;
}

kal_bool _Drv_MDAPInterface_Dump(void)
{
	mdap_interface_info.u32MD2AP_Status = *MD2SPM_DVFS_CON;
	mdap_interface_info.u32AP2MD_Status = *SPM2MD_DVFS_CON;
	return KAL_TRUE;
}

kal_bool Drv_AP2MD_MaskIRQ(void)
{
	IRQMask(MDAP_INTERFACE_IRQCODE);
	return KAL_TRUE;
}

kal_bool Drv_AP2MD_UnmaskIRQ(void)
{
	IRQUnmask(MDAP_INTERFACE_IRQCODE);
	return KAL_TRUE;
}

kal_bool _Drv_MDAPInterface_Init(void)
{
	//reset structure
	kal_mem_set(&mdap_interface_info, 0, sizeof(MDAP_INTERFACE_INFO));

#if defined(APMDINTERFACE_ENABLE_LISR)	//if enable LISR mechanism

	#if defined(__PCORE__)
		//reset callback
		kal_mem_set(ap2md_hisr_callback, 0, AP2MD_HISR_CALLBACKCNT * sizeof(DRV_AP2MD_HISRCALLBACK));
	
		//unmask MD internal mask bit
		*MDSYS_TOP_CTL_0 |= ((0x1 << AP2MD_AUDIO_ACK_PCORE) | (0x1 << AP2MD_AUDIO_NORMALFUN_PCORE) | (0x1 << AP2MD_GEOFENCE_NORMALFUN_PCORE));

		//init the interface source from SCP or APMCU
		//if need to clear INT source, we need to know the source register address
		mdap_interface_info.u32AP2MD_Lisr_FromSCP[AP2MD_AUDIO_ACK_PCORE] = KAL_TRUE;
		mdap_interface_info.u32AP2MD_Lisr_FromSCP[AP2MD_AUDIO_NORMALFUN_PCORE] = KAL_TRUE;
		mdap_interface_info.u32AP2MD_Lisr_FromSCP[AP2MD_GEOFENCE_NORMALFUN_PCORE] = KAL_TRUE;
			
	IRQ_Register_LISR(MDAP_INTERFACE_IRQCODE, Drv_MDAPInterface_PS_LISR, "MDAP_PS_LISR");
    mdap_interface_hisrid = kal_init_hisr(MDAP_PS_HISR);

	#elif defined(__L1CORE__)
	IRQ_Register_LISR(MDAP_INTERFACE_IRQCODE, Drv_MDAPInterface_L1_LISR, "MDAP_L1_LISR");
    mdap_interface_hisrid = kal_init_hisr(MDAP_L1_HISR);
	#endif

    IRQSensitivity(MDAP_INTERFACE_IRQCODE, LEVEL_SENSITIVE);
	Drv_AP2MD_UnmaskIRQ();
#endif

	mdap_interface_info.u32MD2AP_InitStatus = *MD2SPM_DVFS_CON;
	mdap_interface_info.u32AP2MD_InitStatus = *SPM2MD_DVFS_CON;

	return KAL_TRUE;
}

kal_bool _Drv_MDAPInterface_RegisterCallback(AP2MD_SCENARIO funID, DRV_AP2MD_HISRCALLBACK funp)
{
#if defined(APMDINTERFACE_ENABLE_LISR)	//if enable LISR mechanism
#if defined(__PCORE__)
	//only available user can register callback function
	if (((funID == AP2MD_AUDIO_NORMALFUN_PCORE) || (funID == AP2MD_GEOFENCE_NORMALFUN_PCORE)) && funp)
	{
		ap2md_hisr_callback[funID] = funp;
		return KAL_TRUE;
	}
#elif defined(__L1CORE__)
	//l1core currently has no user
#endif
#endif

		return KAL_FALSE;
	}

#if defined(__PCORE__)
void Drv_MDAPInterface_PS_LISR(void)
{
	//mask the irq, and unmask in HISR
	Drv_AP2MD_MaskIRQ();
	
#if defined(APMDINTERFACE_ENABLE_LISR)	//if enable LISR mechanism
	mdap_interface_info.APMD_History[u32_AP2MD_HistoryCnt].u32AP2MD_Lisr_Src = *SPM2MD_SRC_CON;
	mdap_interface_info.APMD_History[u32_AP2MD_HistoryCnt].u32AP2MD_Lisr_Dst = *SPM2MD_DVFS_CON;
#endif

	kal_activate_hisr(mdap_interface_hisrid);
	return;
}

void Drv_MDAPInterface_PS_HISR(void)
{	
#if defined(APMDINTERFACE_ENABLE_LISR)	//if enable LISR mechanism
	kal_uint32 i = 0, u32spm2mdStatus = 0, u32WaitCnt = 0;

	mdap_interface_info.APMD_History[u32_AP2MD_HistoryCnt].u32AP2MD_Hisr0_Src = *SPM2MD_SRC_CON;
	mdap_interface_info.APMD_History[u32_AP2MD_HistoryCnt].u32AP2MD_Hisr0_Dst = *SPM2MD_DVFS_CON;

	//get the status first
	u32spm2mdStatus = *SPM2MD_DVFS_CON;
	
	for (i = AP2MD_PCORE_START; i <= AP2MD_PCORE_END; i ++)
	{
		//check the corresponding bit enable or not
		if (u32spm2mdStatus & (0x1 << i))
		{
			if (i == AP2MD_AUDIO_ACK_PCORE)
			{
				//specific scenario, because AP can't clear MD scenario bit directly
				//AP use this ack mechanism to clear MD2AP scenario bit by MDMCU
				_Drv_MD2AP_ClearScenario(MD2AP_AUDIO_FEATURE);
			}
			else if (ap2md_hisr_callback[i])	//check the HISR callback is registered or not
			{
				ap2md_hisr_callback[i](u32spm2mdStatus);
			}
		}

		//check the source is SCP or not
		//clear SCP source control corresponding bit
		if (mdap_interface_info.u32AP2MD_Lisr_FromSCP[i])
		{
			do
			{
				*SPM2MD_SRC_CON |= (0x1 << i);		//this register is write 1 to clear
				u32WaitCnt ++;
			} while ((*SPM2MD_SRC_CON & (0x1 << i)) && u32WaitCnt < HISR_CLR_WAITCNT);
		}
	}
	
	mdap_interface_info.APMD_History[u32_AP2MD_HistoryCnt].u32AP2MD_Hisr_waitcnt = u32WaitCnt;
	mdap_interface_info.APMD_History[u32_AP2MD_HistoryCnt].u32AP2MD_Hisr1_Src = *SPM2MD_SRC_CON;
	mdap_interface_info.APMD_History[u32_AP2MD_HistoryCnt].u32AP2MD_Hisr1_Dst = *SPM2MD_DVFS_CON;
	u32_AP2MD_HistoryCnt ++;

	if (u32_AP2MD_HistoryCnt >= AP2MD_DBG_HISTORYCNT)
	{
		u32_AP2MD_HistoryCnt = 0;
	}
#endif

	//unmask IRQ at the end step
	Drv_AP2MD_UnmaskIRQ();
	return;
}
#elif defined(__L1CORE__)
void Drv_MDAPInterface_L1_LISR(void)
{
	//L1 has no LISR user, needn't implement
	Drv_AP2MD_MaskIRQ();
	kal_activate_hisr(mdap_interface_hisrid);
	return;
}

void Drv_MDAPInterface_L1_HISR(void)
{
	//L1 has no LISR user, needn't implement
	Drv_AP2MD_UnmaskIRQ();
	return;
}
#endif

#else	//defined(APMDINTERFACE_ENABLE)

kal_bool _Drv_MD2AP_SetScenario(MD2AP_SCENARIO value)
{
	return KAL_TRUE;
}

kal_bool _Drv_MD2AP_ClearScenario(MD2AP_SCENARIO value)
{
	return KAL_TRUE;
}

kal_bool _Drv_MDAPInterface_Dump(void)
{
	return KAL_TRUE;
}

kal_bool _Drv_MDAPInterface_Init(void)
{
	return KAL_TRUE;
}

kal_bool _Drv_MDAPInterface_RegisterCallback(AP2MD_SCENARIO funID, DRV_AP2MD_HISRCALLBACK funp)
{
	return KAL_TRUE;
}

void Drv_MDAPInterface_PS_LISR(void)
{
	return;
}

void Drv_MDAPInterface_L1_LISR(void)
{
	return;
}

void Drv_MDAPInterface_PS_HISR(void)
{
	return;
}

void Drv_MDAPInterface_L1_HISR(void)
{
	return;
}

#endif	//defined(APMDINTERFACE_ENABLE)


