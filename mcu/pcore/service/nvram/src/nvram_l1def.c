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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * nvram_l1def.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file provides a fuction for NVRAM Task to get L1 default value
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "nvram_main.h"         /* nvram_ltable_entry_struct & nvram_ptr, should be removed in the future */
#include "nvram_l1def.h"

#ifdef __MTK_TARGET__
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
// #include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h" /* Task message communiction */

/* L1 calibration data defination */
#include "l1cal.h"
#include "l1d_public.h"
#include "l1d_data_pcore.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"
#include "l1d_custom_rf.h"
#include "mml1_rf_global.h"
#endif /* __MTK_TARGET__ */ 
kal_bool l1d_DRDI_had_done = KAL_FALSE;
kal_bool Is_2GDRDI_Enable = KAL_FALSE;

void L1D_CustomDynamicGetParam(kal_uint16 setIdx)
{
   #if defined(__MTK_TARGET__) && !defined(L1_NOT_PRESENT)
   kal_uint32 band;
   kal_uint32 i, j;
   for(band= 0; band < FrequencyBandCount; band++)
   {
      #if defined(__2G_MIPI_SUPPORT__)
      if(l1d_mipi_ctrl_data[setIdx].GGE_MIPI_CTRL_TABLE[band] != 0)
      {
         /*l1d_custom_mipi.c 2G mipi ctrl data point init*/
         kal_mem_cpy(GGE_MIPI_CTRL_TABLE[band],l1d_mipi_ctrl_data[setIdx].GGE_MIPI_CTRL_TABLE[band],(sizeof(l1cal_mipi_ctrl_table_band_T)));
      }	
      #endif			
      /*m12193.c  Tx_Power_Offset point init*/
      #if defined(__TX_POWER_OFFSET_SUPPORT__) || defined (__SAR_TX_POWER_BACKOFF_SUPPORT__)
      if(L1D_TX_Power_Offset_Data[setIdx].Tx_Power_Offset_GMSK[band]!=0)
      {
         kal_mem_cpy(Tx_Power_Offset_GMSK[band],L1D_TX_Power_Offset_Data[setIdx].Tx_Power_Offset_GMSK[band],(sizeof(tx_power_offset_t)));
      }
         #if defined(__EPSK_TX__)
      if(L1D_TX_Power_Offset_Data[setIdx].Tx_Power_Offset_EPSK[band]!=0)
      {
         kal_mem_cpy(Tx_Power_Offset_EPSK[band],L1D_TX_Power_Offset_Data[setIdx].Tx_Power_Offset_EPSK[band],(sizeof(tx_power_offset_t)));
      }
         #endif /* defined(__EPSK_TX__) */ 
      #endif /*__TX_POWER_OFFSET_SUPPORT__ || defined (__SAR_TX_POWER_BACKOFF_SUPPORT__)*/	
      if(L1D_Cal_Data[setIdx].AGC_PATHLOSS_TABLE[band] != 0)
      { 
         kal_mem_cpy(AGC_PATHLOSS_TABLE[band],L1D_Cal_Data[setIdx].AGC_PATHLOSS_TABLE[band],(sizeof(sAGCGAINOFFSET) * PLTABLE_SIZE)); 
      }
      if(L1D_Cal_Data[setIdx].RampData[band]!=0)
      {
         kal_mem_cpy(RampData[band], L1D_Cal_Data[setIdx].RampData[band], sizeof(sRAMPDATA));	
      }
      #if defined(__EPSK_TX__)
      if(L1D_Cal_Data[setIdx].RampData_EPSK[band]!=0)
      {
         kal_mem_cpy(RampData_EPSK[band], L1D_Cal_Data[setIdx].RampData_EPSK[band], sizeof(sRAMPDATA));
      }
      #endif /* defined(__EPSK_TX__) */ 
      if(L1D_Cal_Data[setIdx].InterRampData[band]!=0)
      {
         kal_mem_cpy(InterRampData[band], L1D_Cal_Data[setIdx].InterRampData[band], sizeof(sMIDRAMPDATA));
      }
      #if defined(__EPSK_TX__)
      for(i = 0; i < 4; i++)
      {
         if(L1D_Cal_Data[setIdx].InterRampData[band]!=0)
         {
            kal_mem_cpy((*(EPSK_InterRampData[band])[i]),(*(L1D_Cal_Data[setIdx].EPSK_InterRampData[band])[i]),sizeof(sMIDRAMPDATA));
         }
      }
      #endif /* defined(__EPSK_TX__) */ 
      #if defined(__PS_SERVICE__) 
      if(L1D_Cal_Data[setIdx].tx_power_rollback_gmsk[band] != 0)
      {
         kal_mem_cpy(tx_power_rollback_gmsk[band], L1D_Cal_Data[setIdx].tx_power_rollback_gmsk[band], sizeof(sTX_POWER_ROLLBACK));
      }
         #if defined(__EGPRS_MODE__) 
      if(L1D_Cal_Data[setIdx].tx_power_rollback_epsk[band] != 0)
      {
         kal_mem_cpy(tx_power_rollback_epsk[band], L1D_Cal_Data[setIdx].tx_power_rollback_epsk[band], sizeof(sTX_POWER_ROLLBACK));
      }
         #endif /*defined(__EGPRS_MODE__)*/        	  
      #endif /*defined(__PS_SERVICE__)*/
      #if defined(__2G_TX_POWER_CONTROL_SUPPORT__)   
         #if IS_TXPC_CL_AUXADC_SUPPORT || IS_TXPC_CL_BSI_SUPPORT

      if(L1D_Cal_Data[setIdx].TXADC_Data[band]!=0)
      {
         kal_mem_cpy(TXADC_Data[band], L1D_Cal_Data[setIdx].TXADC_Data[band], sizeof(sTXPC_ADCDATA));
      }
      if(L1D_Cal_Data[setIdx].TXTEMP_Data[band]!=0)
      {
         kal_mem_cpy(TXTEMP_Data[band], L1D_Cal_Data[setIdx].TXTEMP_Data[band], sizeof(sTXPC_TEMPDATA));
      }
            #if defined(__EPSK_TX__)
      if(L1D_Cal_Data[setIdx].TXADC_Data_EPSK[band]!=0)
      {
         kal_mem_cpy(TXADC_Data_EPSK[band], L1D_Cal_Data[setIdx].TXADC_Data_EPSK[band], sizeof(sTXPC_ADCDATA));
      }
       if(L1D_Cal_Data[setIdx].TXTEMP_Data_EPSK[band]!=0)
      {
         kal_mem_cpy(TXTEMP_Data_EPSK[band], L1D_Cal_Data[setIdx].TXTEMP_Data_EPSK[band], sizeof(sTXPC_TEMPDATA));
      }
            #endif
         #endif
      #endif
      #if defined(__MULTI_LNA_MODE_CALIBRATION_SUPPORT__)
      if(L1D_Cal_Data[setIdx].LNA_PATHLOSS_TABLE[band] != 0)
      { 
         kal_mem_cpy(LNA_PATHLOSS_TABLE[band],L1D_Cal_Data[setIdx].LNA_PATHLOSS_TABLE[band],(sizeof(sLNAGAINOFFSET) * PLTABLE_SIZE)); 
      }
      #endif
   }
	/*l1d_custom_frontend.c 2G front end data point init*/
	#if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)	
      kal_mem_cpy(&l1d_rf_custom_input_data, l1d_front_end_data[setIdx].l1d_rf_custom_input_data, sizeof(l1d_rf_custom_input_data_T));
	#endif
    /*  TAS init */
	#if defined(__TAS_SUPPORT__)||defined(__TAS_FOR_C2K_ONOFF_SUPPORT__) 
      kal_mem_cpy( &L1_TAS_Custom_Params,l1d_front_end_data[setIdx].L1_TAS_Custom_Params, sizeof(l1_tas_custom_params_T) );
	   kal_mem_cpy( &L1_TAS_Custom_PData,l1d_front_end_data[setIdx].L1_TAS_Custom_PData, sizeof(l1_tas_custom_pdata_T) );
         #if defined( __TAS_ANTENNA_IDX_ON_TEST_SIM__)
      kal_mem_cpy(&L1_TAS_Init_Ant_Params,l1d_front_end_data[setIdx].L1_TAS_Init_Ant_Params, sizeof(l1_tas_init_ant_params_T));
         #endif
	#endif
   #if IS_2G_DAT_SUPPORT
   kal_mem_cpy (&(l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_A_NVRAM->l1d_custom_dat_fe_cat_a),l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_A_NVRAM->l1d_custom_dat_fe_cat_a_ptr,sizeof(L1D_CUSTOM_DAT_FE_CAT_A_T));
   kal_mem_cpy (&(l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_B_NVRAM->l1d_custom_dat_fe_cat_b),l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_B_NVRAM->l1d_custom_dat_fe_cat_b_ptr,sizeof(L1D_CUSTOM_DAT_FE_CAT_B_T));

      #if defined(__2G_MIPI_SUPPORT__)
   for(i=0;i<L1D_DAT_MAX_CAT_A_CONFIG_NUM;i++)
   {
      for(j=0;j<L1D_DAT_MAX_MIPI_EVNET_NUM;j++)
      {
         kal_mem_cpy (&(l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_A_NVRAM->l1d_dat_cat_a_mipi_event[i][j]),(l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_A_NVRAM->l1d_dat_cat_a_mipi_event_ptr[i]+ j),sizeof(sGGE_MIPIEVENT));
      }

      for(j=0;j<L1D_DAT_MAX_MIPI_DATA_NUM;j++)
      {
         kal_mem_cpy (&(l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_A_NVRAM->l1d_dat_cat_a_mipi_data[i][j]),(l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_A_NVRAM->l1d_dat_cat_a_mipi_data_ptr[i]+ j),sizeof(sGGE_MIPIDATA_SUBBAND));
      }
   }
   for(i=0;i<L1D_DAT_MAX_CAT_B_CONFIG_NUM;i++)
   {
      for(j=0;j<L1D_DAT_MAX_MIPI_EVNET_NUM;j++)
      {
         kal_mem_cpy (&(l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_B_NVRAM->l1d_dat_cat_b_mipi_event[i][j]),(l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_B_NVRAM->l1d_dat_cat_b_mipi_event_ptr[i]+ j),sizeof(sGGE_MIPIEVENT));
      }

      for(j=0;j<L1D_DAT_MAX_MIPI_DATA_NUM;j++)
      {
         kal_mem_cpy (&(l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_B_NVRAM->l1d_dat_cat_b_mipi_data[i][j]),(l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_B_NVRAM->l1d_dat_cat_b_mipi_data_ptr[i]+ j),sizeof(sGGE_MIPIDATA_SUBBAND));
      }
   }   
      #endif
   kal_mem_cpy( &L1_DAT_Custom_FE_ROUTE_NVRAM,l1d_front_end_data[setIdx].L1_DAT_Custom_FE_ROUTE_NVRAM, sizeof(L1D_CUSTOM_DAT_FE_ROUTE_NVRAM_T) );
   kal_mem_cpy( &L1_DAT_Custom_FE_CAT_A_NVRAM,l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_A_NVRAM, sizeof(L1D_CUSTOM_DAT_FE_CAT_A_NVRAM_T) );
   kal_mem_cpy( &L1_DAT_Custom_FE_CAT_B_NVRAM,l1d_front_end_data[setIdx].L1_DAT_Custom_FE_CAT_B_NVRAM, sizeof(L1D_CUSTOM_DAT_FE_CAT_B_NVRAM_T) );

   #endif
   kal_mem_cpy(&(afc_crystal_data.AFC_XO_CapID), &(L1D_Cal_Data[setIdx].afc_crystal_data->AFC_XO_CapID), sizeof(l1cal_crystalCapData_T));
   #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
   kal_mem_cpy(&(CLoad_FreqOffset_data.CLoad_FreqOffset), &(L1D_Cal_Data[setIdx].Cload_FreqOffset_Data->CLoad_FreqOffset), sizeof(sCloadParameter));
   #endif
   kal_mem_cpy(&tx_apc_voltage_compensation, L1D_Cal_Data[setIdx].tx_apc_voltage_compensation, sizeof(sTX_POWER_VOLTAGE_COMPENSATION));
  
   //kal_mem_cpy(&l1d_custom_band_support, &l1d_custom_band_support_SetDefault, sizeof(l1cal_l1CustomBandSupport_T));
   kal_mem_cpy(&l1d_custom_band_support, L1D_Custom_Band_Support_Data_Array[setIdx], sizeof(l1cal_l1CustomBandSupport_T));


  // L1D_CustomDynamicGetBandSupportParam(setIdx);
  #endif
}
void L1D_CustomDynamicInit()
{
#if defined(__MTK_TARGET__) && !defined(L1_NOT_PRESENT)
   unsigned short l1d_Drdi_SetIndex;
   Is_2GDRDI_Enable = L1D_CUSTOM_DYNAMIC_SUPPORT;
   #if IS_2G_DRDI_SUPPORT
   if(Is_2GDRDI_Enable)
  {
   if(!l1d_DRDI_had_done)
      {
         l1d_Drdi_SetIndex=0;
      #if IS_L1_RF_DRDI_CUSTOM_SETTING_FROM_MML1
   	   /* Get DRDI result parameters from MML1 */
         l1d_Drdi_SetIndex = MML1_RF_DRDI_Dynamic_GetParamAddr(MML1_RF_2G);
   		/* set the pointer to RF custom data by set index */
   	   L1D_CustomDynamicGetParam(l1d_Drdi_SetIndex);
   	   l1d_DRDI_had_done = KAL_TRUE;
      #else
   	   /*always support MML1 DRDI*/
      #endif
      }
   }
   else 
   L1D_CustomDynamicGetParam(0);
  #else
   L1D_CustomDynamicGetParam(0);
  #endif 
#endif
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_L1_default_value_to_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lid         [IN]        
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_get_L1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size)
{
#if defined(__MTK_TARGET__) && !defined(L1_NOT_PRESENT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    l1cal_agcPathLoss_T *agc;
    l1cal_rampTable_T *ramp;

    /* l1cal_txiq_T  txiq; */
    FrequencyBand band = FrequencyBand850;

    l1cal_interRampData_T *interRamp;

#if defined(__EPSK_TX__)
    l1cal_EPSK_interRampData_T *EPSK_interRamp;
#endif 
   // l1cal_crystalAfcData_T *crystalAfc;
    l1cal_crystalCapData_T *crystalCap;
#if defined(__F32_XOSC_REMOVAL_SUPPORT__)    
    l1cal_CloadParameter_T *cloadfreqoffset;
#endif
    nvram_ltable_entry_struct *ldi;

#if defined(__PS_SERVICE__) 
    l1cal_tx_power_rollback_T *tx_power_rollback;
#endif
  /*Add DRDI feature*/
    L1D_CustomDynamicInit();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_util_get_data_item(&ldi, lid);

    kal_mem_set(buffer, 0x00, ldi->size);
    
    switch (lid)
    {
        case NVRAM_EF_L1_AGCPATHLOSS_LID:
            /* L1 Data - AGC */
            agc = (l1cal_agcPathLoss_T*) buffer;
            for (i = 0; i < FrequencyBandCount; i++)
            {
                if (AGC_PATHLOSS_TABLE[i] != 0)
                {
                    kal_mem_cpy(
                        &agc->agcPathLoss[i][0],
                        AGC_PATHLOSS_TABLE[i],
                        (sizeof(sAGCGAINOFFSET) * PLTABLE_SIZE));
                }
            }
            break;
        case NVRAM_EF_L1_RAMPTABLE_GSM850_LID:
        case NVRAM_EF_L1_RAMPTABLE_GSM900_LID:
        case NVRAM_EF_L1_RAMPTABLE_DCS1800_LID:
        case NVRAM_EF_L1_RAMPTABLE_PCS1900_LID:
            /* L1 Data - Ramp */
            ramp = (l1cal_rampTable_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_RAMPTABLE_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_RAMPTABLE_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_RAMPTABLE_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_RAMPTABLE_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            if (RampData[band] != 0)
            {
                extern void L1D_RF_InitEmptyRampData( int rf_band, int is_epsk );
                L1D_RF_InitEmptyRampData( (int)band, (int)0/*gmsk*/ );
                kal_mem_cpy(&ramp->rampData, RampData[band], sizeof(sRAMPDATA));
            }
            break;
        #if defined(__EPSK_TX__)
        case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID:
        case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID:
        case NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID:
        case NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID:
            /* L1 Data - Ramp */
            ramp = (l1cal_rampTable_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            if (RampData_EPSK[band] != 0)
            {
                extern void L1D_RF_InitEmptyRampData( int rf_band, int is_epsk );
                L1D_RF_InitEmptyRampData( (int)band, (int)1/*epsk*/ );
                kal_mem_cpy(&ramp->rampData, RampData_EPSK[band], sizeof(sRAMPDATA));
            }
            break;
        #endif /* defined(__EPSK_TX__) */ 
        case NVRAM_EF_L1_AFCDATA_LID:
            /* L1 Data - Afc */
        {
            extern void L1D_RF_GetAFCData( void *buffer );
            L1D_RF_GetAFCData( buffer );
        }
            break;
        case NVRAM_EF_L1_TXIQ_LID:
            /* L1 Data - TX IQ */
            //txiq.TxTrimI   = bbtx_trim_i;
            //txiq.TxTrimQ   = bbtx_trim_q;
            //txiq.TxOffsetI = bbtx_offset_i;
            //txiq.TxOffsetQ = bbtx_offset_q;
            //kal_mem_cpy(buffer, &txiq, sizeof(l1cal_txiq_T));
            //L1D_RF_Custom_BBTXParameter_Update();
            BBTXParameters.apc_bat_low_voltage =tx_apc_voltage_compensation.BAT_LOW_VOLTAGE;
            BBTXParameters.apc_bat_high_voltage =tx_apc_voltage_compensation.BAT_HIGH_VOLTAGE;
            BBTXParameters.apc_bat_low_temperature =tx_apc_voltage_compensation.BAT_LOW_TEMPERATURE;
            BBTXParameters.apc_bat_high_temperature =tx_apc_voltage_compensation.BAT_HIGH_TEMPERATURE;
            BBTXParameters.ap_update_volinfo_period =tx_apc_voltage_compensation.AP_UPDATE_VOLTINFO_PERIOD;
            kal_mem_cpy(buffer, &BBTXParameters, sizeof(l1cal_txiq_T));
            break;
        case NVRAM_EF_L1_RFSPECIALCOEF_LID:
            /* L1 Data - RF Special coef */
        {
            extern void L1D_RF_Init_SpecialCoef(void);

            L1D_RF_Init_SpecialCoef();
        }
            kal_mem_cpy(buffer, &RFSpecialCoef, sizeof(l1cal_rfspecialcoef_T));
            break;
        case NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID:
        case NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID:
        case NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID:
        case NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID:
            interRamp = (l1cal_interRampData_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            /* Shine modified start */
            if (InterRampData[band] != 0)
            {
                extern void L1D_RF_InitEmptyInterRampData( void* p );
                L1D_RF_InitEmptyInterRampData( InterRampData[band] );
                kal_mem_cpy(&(interRamp->interRampData[0]), InterRampData[band], sizeof(sMIDRAMPDATA));
            }
            /* Shine modified end */
            break;

        #if defined(__EPSK_TX__)
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID:
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID:
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID:
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID:
            EPSK_interRamp = (l1cal_EPSK_interRampData_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            for (i = 0; i < 4; i++)
            {
                if ((*(EPSK_InterRampData[band])[i]) != 0)
                {
                    extern void L1D_RF_InitEmptyInterRampData( void *p );
                    L1D_RF_InitEmptyInterRampData( (*(EPSK_InterRampData[band])[i]) );
                    kal_mem_cpy(
                        &(EPSK_interRamp->EPSK_interRampData[i]),
                        (*(EPSK_InterRampData[band])[i]),
                        sizeof(sMIDRAMPDATA));
                }
            }
            break;
        #endif /* defined(__EPSK_TX__) */ 

        case NVRAM_EF_L1_CRYSTAL_AFCDATA_LID:
            /* Shine modified start */
            //crystalAfc = (l1cal_crystalAfcData_T*) buffer;
            //kal_mem_cpy(&(crystalAfc->XO_SlopeAreaData[0]), XO_SlopeAreaData_RO, sizeof(l1cal_crystalAfcData_T));
            /* Shine modified end */
            break;
        case NVRAM_EF_L1_CRYSTAL_CAPDATA_LID:
            /* Shine modified start */
            //L1D_RF_CAPID_Update();
            crystalCap = (l1cal_crystalCapData_T*) buffer;
            kal_mem_cpy(&(crystalCap->cap_id), &(afc_crystal_data.AFC_XO_CapID), sizeof(l1cal_crystalCapData_T));
            /* Shine modified end */
            break;
        #if defined(__PS_SERVICE__) 
        case NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_LID:
            //L1D_RF_Custom_TX_Power_Rollback_Table_Update_GPRS();
            tx_power_rollback = (l1cal_tx_power_rollback_T*) buffer;
            for (i = 0; i < FrequencyBandCount; i++)
            {
                if (tx_power_rollback_gmsk[i] != 0)
                {
                    kal_mem_cpy(&(tx_power_rollback->rollback_data[i]), tx_power_rollback_gmsk[i], sizeof(sTX_POWER_ROLLBACK));
                }
            }        	  
        	  break;
        #if defined(__EGPRS_MODE__) 
        case NVRAM_EF_L1_EPSK_TX_POWER_ROLLBACK_TABLE_LID:
            //L1D_RF_Custom_TX_Power_Rollback_Table_Update_EGPRS();
              tx_power_rollback = (l1cal_tx_power_rollback_T*) buffer;
            for (i = 0; i < FrequencyBandCount; i++)
            {
                if (tx_power_rollback_epsk[i] != 0)
                {
                    kal_mem_cpy(&(tx_power_rollback->rollback_data[i]), tx_power_rollback_epsk[i], sizeof(sTX_POWER_ROLLBACK));
                }
            }        	  
        	  break;
        #endif /*defined(__EGPRS_MODE__)*/        	  
        #endif /*defined(__PS_SERVICE__)*/
        #if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
        case NVRAM_EF_L1_GMSK_TXPC_LID:
            L1D_RF_TXPC_GET_L1_SETTING( (sTXPC_L1CAL*)buffer, 0 /*GMSK*/ );
            break;
        #if defined(__EPSK_TX__)
        case NVRAM_EF_L1_EPSK_TXPC_LID:
            L1D_RF_TXPC_GET_L1_SETTING( (sTXPC_L1CAL*)buffer, 1 /*EPSK*/ );
            break;
        #endif /*defined(__EPSK_TX__)*/
        #endif /*defined(__2G_TX_POWER_CONTROL_SUPPORT__)*/
        #if defined(__MULTI_LNA_MODE_CALIBRATION_SUPPORT__)
        case NVRAM_EF_L1_LNAPATHLOSS_LID:
            /* L1 Data - LNA */
            L1D_RF_GetLnaPathLossTable( (sLNAPATHLOSS_L1CAL*)buffer );
            break;
        #endif /*defined(__MULTI_LNA_MODE_CALIBRATION_SUPPORT__)*/
        #if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)
        case NVRAM_EF_L1_2G_RF_PARAMETER_LID:
            kal_mem_cpy(buffer, &l1d_rf_custom_input_data, sizeof(l1d_rf_custom_input_data_T));
		    break;
        #endif
        #if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
        #if !defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__)|| defined(__MULTI_RAT_AFC_TADC_SHARE_SUPPORT__)
        case NVRAM_EF_L1_TEMPERATURE_ADC_LID:
            L1D_RF_TXPC_Get_Temp_ADC( (sTEMPERATURE_ADC_L1CAL*)buffer );
            break;
        #endif /*!defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__)|| defined(__MULTI_RAT_AFC_TADC_SHARE_SUPPORT__)*/
        #endif /*defined(__2G_TX_POWER_CONTROL_SUPPORT__)*/
        #if defined(__F32_XOSC_REMOVAL_SUPPORT__)
        case NVRAM_EF_L1_CLOAD_FREQ_OFFSET_LID:
           // L1D_RF_GetCLoadFreqOffset( (kal_int32*)buffer );
            cloadfreqoffset = (l1cal_CloadParameter_T*) buffer;
            kal_mem_cpy(&(cloadfreqoffset->CLoad_FreqOffset), &(CLoad_FreqOffset_data.CLoad_FreqOffset), sizeof(l1cal_CloadParameter_T));
            break;
        #endif /*defined(__F32_XOSC_REMOVAL_SUPPORT__)*/
        #if defined(__2G_TX_GAIN_RF_CALIBRATION__)
        case NVRAM_EF_L1_GAINRF_LID:
            L1D_RF_GetGainRF((l1cal_gainrf_T*)buffer);
            break;
        #endif
        #if defined(MT6176_2G_RF)
        case NVRAM_EF_L1_RFC_LID:
        {
            L1D_RF_RFCData_Init_Pcore();
            L1D_RF_Get_RFC_Result((l1cal_mmrfc_result_T*)buffer);
            break;
        }
        #endif
        #if defined(__2G_MIPI_SUPPORT__)
        case NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM850_LID:
        case NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM900_LID:
        case NVRAM_EF_L1_MIPI_CTRL_TABLE_DCS1800_LID:
        case NVRAM_EF_L1_MIPI_CTRL_TABLE_PCS1900_LID:
            switch (lid)
            {
                case NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_MIPI_CTRL_TABLE_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_MIPI_CTRL_TABLE_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            if (GGE_MIPI_CTRL_TABLE[band] != 0)
            {
                kal_mem_cpy(buffer, GGE_MIPI_CTRL_TABLE[band], sizeof(l1cal_mipi_ctrl_table_band_T));
            }
            break;
        #endif
        case NVRAM_EF_L1_CUSTOM_BAND_SUPPORT_LID:
        {
           kal_mem_cpy(buffer, &l1d_custom_band_support, sizeof(l1cal_l1CustomBandSupport_T));
        }
        break;

#if defined(__TX_POWER_OFFSET_SUPPORT__) || defined (__SAR_TX_POWER_BACKOFF_SUPPORT__)
        case NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM850_LID:
        case NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM900_LID:
        case NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_DCS_LID:
        case NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_PCS_LID:
           switch (lid)
           {
               case NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM850_LID:
                   band = FrequencyBand850;
                   break;
               case NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM900_LID:
                   band = FrequencyBand900;
                   break;
               case NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_DCS_LID:
                   band = FrequencyBand1800;
                   break;
               case NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_PCS_LID:
                   band = FrequencyBand1900;
                   break;
           }
           kal_mem_cpy(buffer, Tx_Power_Offset_GMSK[band], sizeof(tx_power_offset_t));
           break;
   #if defined(__EPSK_TX__)
        case NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM850_LID:
        case NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM900_LID:
        case NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_DCS_LID:
        case NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_PCS_LID:
           switch (lid)
           {
               case NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM850_LID:
                   band = FrequencyBand850;
                   break;
               case NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM900_LID:
                   band = FrequencyBand900;
                   break;
               case NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_DCS_LID:
                   band = FrequencyBand1800;
                   break;
               case NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_PCS_LID:
                   band = FrequencyBand1900;
                   break;
           }
           kal_mem_cpy(buffer, Tx_Power_Offset_EPSK[band], sizeof(tx_power_offset_t));
           break;
   #endif /*defined(__EPSK_TX__)*/
#endif /*__TX_POWER_OFFSET_SUPPORT__ || defined (__SAR_TX_POWER_BACKOFF_SUPPORT__)*/
        #if defined(__TAS_SUPPORT__)||defined(__TAS_FOR_C2K_ONOFF_SUPPORT__)   
        case NVRAM_EF_L1_TAS_CUSTOM_PARAMES_LID:
           kal_mem_cpy( buffer, &L1_TAS_Custom_Params, sizeof(l1_tas_custom_params_T) );
           break;
        case NVRAM_EF_L1_TAS_CUSTOM_PDATA_LID:
           kal_mem_cpy( buffer,&L1_TAS_Custom_PData, sizeof(l1_tas_custom_pdata_T) );
           break;
           #if defined(__TAS_ANTENNA_IDX_ON_TEST_SIM__)
        case NVRAM_EF_L1_TAS_ANT_INIT_PARAMES_LID:
           kal_mem_cpy(buffer,&L1_TAS_Init_Ant_Params, sizeof(l1_tas_init_ant_params_T));
           break;
           #endif 
        #endif
        #if IS_2G_DAT_SUPPORT
        case NVRAM_EF_L1_DAT_CUSTOM_FE_ROUTE_PARAMES_LID:
           kal_mem_cpy( buffer,&L1_DAT_Custom_FE_ROUTE_NVRAM, sizeof(l1_dat_custom_fe_route_params_T) );
           break;   
        case NVRAM_EF_L1_DAT_CUSTOM_FE_CAT_A_PARAMES_LID:
           kal_mem_cpy( buffer,&L1_DAT_Custom_FE_CAT_A_NVRAM, sizeof(l1_dat_custom_fe_cata_params_T) );
           break;       
        case NVRAM_EF_L1_DAT_CUSTOM_FE_CAT_B_PARAMES_LID:
           kal_mem_cpy( buffer,&L1_DAT_Custom_FE_CAT_B_NVRAM, sizeof(l1_dat_custom_fe_catb_params_T) );
           break;
        #endif
		
        default:
            ASSERT(KAL_FALSE);
            break;
    }

#endif /* __MTK_TARGET__ */ 

}

