


#if !defined(__SMART_PHONE_MODEM__)

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"

#include "dcl.h"

#include "afe.h"

#if defined(__ENABLE_SPEECH_DVT__)
extern kal_bool Is_Sph_DVT_BT_Mode_NB(void);
#endif // defined(__ENABLE_SPEECH_DVT__)

#define WriteREG(_addr, _value) (*(volatile kal_uint32 *)(_addr) = (_value))


// ----------------------------------------------------------------------------
// Register Definition
// ----------------------------------------------------------------------------


#if defined(MT6755) || defined(MT6750)

// #define AP_AUDSYS_BASE   0xA1220000

#define AUDIO_TOP_CON0                  (BASE_MADDR_AUDIO + 0x0000)
#define AUDIO_TOP_CON1                  (BASE_MADDR_AUDIO + 0x0004)
//#define AUDIO_TOP_CON2                  (BASE_MADDR_AUDIO + 0x0008)
#define AUDIO_TOP_CON3                  (BASE_MADDR_AUDIO + 0x000C)
#define AFE_DAC_CON0                    (BASE_MADDR_AUDIO + 0x0010)
#define AFE_DAC_CON1                    (BASE_MADDR_AUDIO + 0x0014)
#define AFE_I2S_CON                     (BASE_MADDR_AUDIO + 0x0018)
#define AFE_DAIBT_CON0                  (BASE_MADDR_AUDIO + 0x001C)
                                        
#define AP_AFE_CONN0                    (BASE_MADDR_AUDIO + 0x0020)
#define AP_AFE_CONN1                    (BASE_MADDR_AUDIO + 0x0024)
#define AP_AFE_CONN2                    (BASE_MADDR_AUDIO + 0x0028)
#define AP_AFE_CONN3                    (BASE_MADDR_AUDIO + 0x002C)
#define AP_AFE_CONN4                    (BASE_MADDR_AUDIO + 0x0030)
#define AP_AFE_CONN5                    (BASE_MADDR_AUDIO + 0x005C)
#define AP_AFE_CONN6                    (BASE_MADDR_AUDIO + 0x00BC)
#define AP_AFE_CONN9                    (BASE_MADDR_AUDIO + 0x0468)
#define AP_AFE_CONN10                   (BASE_MADDR_AUDIO + 0x046C)

#define AFE_I2S_CON1                    (BASE_MADDR_AUDIO + 0x0034)
#define AFE_I2S_CON2                    (BASE_MADDR_AUDIO + 0x0038)
#define AFE_MRGIF_CON                   (BASE_MADDR_AUDIO + 0x003C)
#define AFE_I2S_CON3                    (BASE_MADDR_AUDIO + 0x004C)

#define AFE_ADDA_DL_SRC2_CON0           (BASE_MADDR_AUDIO + 0x0108)
#define AFE_ADDA_DL_SRC2_CON1           (BASE_MADDR_AUDIO + 0x010C)
#define AFE_ADDA_UL_SRC_CON0            (BASE_MADDR_AUDIO + 0x0114)
#define AFE_ADDA_UL_SRC_CON1            (BASE_MADDR_AUDIO + 0x0118)

#define AFE_ADDA_UL_DL_CON0             (BASE_MADDR_AUDIO + 0x0124)
#define AFE_ADDA_NEWIF_CFG0             (BASE_MADDR_AUDIO + 0x0138)
#define AFE_ADDA_NEWIF_CFG1             (BASE_MADDR_AUDIO + 0x013C)


//#define AFE_SIDDETONE_MON               (BASE_MADDR_AUDIO + 0x01D4)
//#define AFE_SIDDETONE_CON0              (BASE_MADDR_AUDIO + 0x01E0)
//#define AFE_SIDDETONE_COEFF             (BASE_MADDR_AUDIO + 0x01E4)
#define AFE_SIDDETONE_CON1              (BASE_MADDR_AUDIO + 0x01E8)
//#define AFE_SIDDETONE_GAIN              (BASE_MADDR_AUDIO + 0x01EC)

#define AFE_SGEN_CON0                   (BASE_MADDR_AUDIO + 0x01F0)
#define AFE_TOP_CON0                    (BASE_MADDR_AUDIO + 0x0200)
#define AFE_GAIN1_CON0                  (BASE_MADDR_AUDIO + 0x0410)

#define AFE_GAIN1_CONN                  (BASE_MADDR_AUDIO + 0x0420)

#define AFE_GAIN2_CON0                  (BASE_MADDR_AUDIO + 0x0428)
#define AFE_GAIN2_CONN                  (BASE_MADDR_AUDIO + 0x0438)
#define AFE_GAIN2_CONN2                 (BASE_MADDR_AUDIO + 0x0440)
#define AFE_GAIN2_CONN3                 (BASE_MADDR_AUDIO + 0x0444)

#define PCM_INTF_CON1                   (BASE_MADDR_AUDIO + 0x0530)
#define PCM_INTF_CON2                   (BASE_MADDR_AUDIO + 0x0538)
#define PCM_INTF_CON                    (BASE_MADDR_AUDIO + 0x053C)
//#define FOC_ROM_SIG                     (BASE_MADDR_AUDIO + 0x0630)



// ----------------------------------------------------------------------------
// Register Setting for different scenario 
// ----------------------------------------------------------------------------


void PMIC_AudioConfig(void)
{
    DCL_HANDLE handle;
    PMU_CTRL_MISC_SET_REGISTER_VALUE setVal;
    PMU_CTRL_MISC_GET_REGISTER_VALUE getVal;
	  PMU_CTRL_MISC_GET_HW_VERSION val;
#if defined(MT6750)
    return; //In Jade Minus MDOnly Project, the voice call during bringup is not needed. The related PMIC control sequence is not ready.
#endif
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);	
    
    //0D06 0000
    setVal.offset = ((0<<31) | 0x0D06);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D04 0155
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0x0155);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //029E 0001
    setVal.offset = ((0<<31) | 0x029E);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    

    //029C 0001
    setVal.offset = ((0<<31) | 0x029C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    

    //0D0E 0040
    setVal.offset = ((0<<31) | 0x0D0E);
    setVal.value  = (0x0040);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D0E 0040
    setVal.offset = ((0<<31) | 0x0D0E);
    setVal.value  = (0x0040);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    


#if defined(MT6755_EVB) //ACC MODE
    //0D1A 0021
    setVal.offset = ((0<<31) | 0x0D1A);
    setVal.value  = (0x0021);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D1A 2121
    setVal.offset = ((0<<31) | 0x0D1A);
    setVal.value  = (0x2121);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D08 0311
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x0311);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    

    //0D0A 0331
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x0331);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0D08 5311
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x5311);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D0A 5331
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x5331);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);            
#else                   //DCC MODE
    //2090 2060
    setVal.offset = ((0<<31) | 0x2090);
    setVal.value  = (0x2060);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);      
    
    //2090 2061
    setVal.offset = ((0<<31) | 0x2090);
    setVal.value  = (0x2061);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D1A 0021
    setVal.offset = ((0<<31) | 0x0D1A);
    setVal.value  = (0x0021);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D1A 2121
    setVal.offset = ((0<<31) | 0x0D1A);
    setVal.value  = (0x2121);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
        
    //0D08 0317
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x0317);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D0A 0337
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x0337);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);   
    
    //0D08 5317
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x5317);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    AFE_DELAY(100);  
    //0D08 5313
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x5313);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);   
    
    //0D0A 5337
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x5337);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    AFE_DELAY(100);
    //0D0A 5333
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x5333);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);            
#endif

    //023E 6000
    setVal.offset = ((0<<31) | 0x023E);
    setVal.value  = (0x6000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //2014 0040
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0x0040);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2012 0000
    setVal.offset = ((0<<31) | 0x2012);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2000 0001
    setVal.offset = ((0<<31) | 0x2000);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //200A 0002
    setVal.offset = ((0<<31) | 0x200A);
    setVal.value  = (0x0002);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //200C 0001
    setVal.offset = ((0<<31) | 0x200C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 0155
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0x0155);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //029C 0001
    setVal.offset = ((0<<31) | 0x029C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //023E F000
    setVal.offset = ((0<<31) | 0x023E);
    setVal.value  = (0xF000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    AFE_DELAY(100);

    //2014 8000
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2098 1515
    setVal.offset = ((0<<31) | 0x2098);
    setVal.value  = (0x1515);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2096 8C01
    setVal.offset = ((0<<31) | 0x2096);
    setVal.value  = (0x8C01);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    AFE_DELAY(100);
    
    //2014 8000
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2020 0006
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x0006);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //201C C3A1
    setVal.offset = ((0<<31) | 0x201C);
    setVal.value  = (0xC3A1);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2020 0003
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x0003);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2020 000B
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x000B);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2008 001E
    setVal.offset = ((0<<31) | 0x2008);
    setVal.value  = (0x001E);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2000 0001
    setVal.offset = ((0<<31) | 0x2000);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2038 3330
    setVal.offset = ((0<<31) | 0x2038);
    setVal.value  = (0x3330);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2002 3300
    setVal.offset = ((0<<31) | 0x2002);
    setVal.value  = (0x3300);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2002 3300
    setVal.offset = ((0<<31) | 0x2002);
    setVal.value  = (0x3300);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2004 0001
    setVal.offset = ((0<<31) | 0x2004);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2012 0000
    setVal.offset = ((0<<31) | 0x2012);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2040 0080
    setVal.offset = ((0<<31) | 0x2040);
    setVal.value  = (0x0080);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2042 0101
    setVal.offset = ((0<<31) | 0x2042);
    setVal.value  = (0x0101);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 A155
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0xA155);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D06 0100
    setVal.offset = ((0<<31) | 0x0D06);
    setVal.value  = (0x0100);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0800 0000
    setVal.offset = ((0<<31) | 0x0800);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0CF2 2080
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2080);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0CFE 0400
    setVal.offset = ((0<<31) | 0x0CFE);
    setVal.value  = (0x0400);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 A055
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0xA055);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0806 001F
    setVal.offset = ((0<<31) | 0x0806);
    setVal.value  = (0x001F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //for HS
    //0CF4 0100
    setVal.offset = ((0<<31) | 0x0CF4);
    setVal.value  = (0x0100);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 A255
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0xA255);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  


    //0CF2 2089
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2089);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0CF2 2109
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2109);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0CF2 2119
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2119);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0806 0009
    setVal.offset = ((0<<31) | 0x0806);
    setVal.value  = (0x0009);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    
    AFE_DELAY(100);           
}


void ApAudSys_config(void)
{
	WriteREG(AUDIO_TOP_CON0, 0x60004000); //script=0x60004000
	WriteREG(AFE_TOP_CON0, 0x00000000); //not in script
	//WriteREG(AFE_DAC_CON0, 0x00000001); // 0x11220010, not in script


#if APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K

	WriteREG(AFE_GAIN1_CONN, 0x03000000); // I11->o18  I10->o17
	
	WriteREG(AP_AFE_CONN0, 0x00000000); 
	WriteREG(AP_AFE_CONN1, 0x00000000);
	WriteREG(AP_AFE_CONN2, 0x00000000);
	WriteREG(AP_AFE_CONN3, 0x08000000); // MD1, I14->O03
	
	WriteREG(AP_AFE_CONN4, 0x00000000);
	WriteREG(AP_AFE_CONN5, 0x00000000);
	WriteREG(AP_AFE_CONN6, 0x00010000); // MD1, I21->O04
    


#else // phone call

	   WriteREG(AP_AFE_CONN0, 0x00000000); // from script
	   WriteREG(AP_AFE_CONN1, 0x00000000);
	   WriteREG(AP_AFE_CONN2, 0x00000000);
	   WriteREG(AP_AFE_CONN3, 0x08000000); // MD1, I14->O03
	   WriteREG(AP_AFE_CONN4, 0x00012001); // MD1, I04->O18, I03->O17, I14->O04
	   WriteREG(AP_AFE_CONN5, 0x00000000);
	   WriteREG(AP_AFE_CONN6, 0x00000000);

#endif //APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K

#if APAUDSYS_DVT_8K
		WriteREG(AFE_GAIN1_CON0, 0x0000C801); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C0A40A8); //sinegen: O13 and O14,  8k, ch2 (08k/64)*4=500Hz, ch1 (08k/64)*8=1kHz
#elif APAUDSYS_DVT_16K
        WriteREG(AFE_GAIN1_CON0, 0x0000C841); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C4A44A8); //sinegen: O13 and O14, 16k, ch2 (16k/64)*4=1kHz, ch1 (16k/64)*8=2kHz

#elif APAUDSYS_DVT_32K
        WriteREG(AFE_GAIN1_CON0, 0x0000C881); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C8A48A8); //sinegen: O13 and O14, 32k, ch2 (32k/64)*4=2kHz, ch1 (32k/64)*8=4kHz
#endif
// sidetone
WriteREG(AFE_SIDDETONE_CON1, 0x00000000); //SIDETONE DISABLE


#if  APAUDSYS_DVT_32K
		WriteREG(PCM_INTF_CON,	0x00000057); // MD1
#elif  APAUDSYS_DVT_8K
		WriteREG(PCM_INTF_CON,	0x00000047); // MD1
#else //16K
		WriteREG(PCM_INTF_CON,	0x0000004F); // MD1
#endif
  	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013c




#if	APAUDSYS_DVT_16K

	
	WriteREG(AFE_I2S_CON1, 0x00000409);	
	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);	
	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script
	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124
	WriteREG(AFE_DAC_CON1, 0x00000400); //0x11220014, from script

#elif  APAUDSYS_DVT_8K


    WriteREG(AFE_I2S_CON1, 0x00000009);

    WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001); // 0x11220114
    WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x0f001821); // 0x11220108
    WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    WriteREG(AFE_DAC_CON1, 0x00000000); //0x11220014, from script
#elif  APAUDSYS_DVT_32K // 32k
   		
    WriteREG(AFE_I2S_CON1, 0x00000809);
		

    //WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00140001); // 0x11220114

    WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00140001); // 0x11220114
    WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x6f001821); // 0x11220108
    WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    WriteREG(AFE_DAC_CON1, 0x00000800); //0x11220014, from script



#else // for phone call script 
	WriteREG(PCM_INTF_CON, 0x0000004F);// 16K
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); //16K

	WriteREG(AFE_I2S_CON1, 0x00000409); //i2s2 OUT SAMPLE RATE = 16k

	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000); //0dB gain
	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // DL Sampling rate=16k audio mode
	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // UL Sampling rate=16k audio mode
	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // ULSample rate <=32k
	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // ul/dl enable	
	WriteREG(AFE_DAC_CON1, 0x00000400); // I2s sample rate =16k



#endif
	
	WriteREG(AFE_I2S_CON, 0x10000009); //master mode i2s in
	WriteREG(AFE_DAC_CON0, 0x00001001); // 0x11220010, from script, power on
#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
    // No UL, DL is output by earphone
	PMIC_AudioConfigForAPAUDSYSDVT();
#else //#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
    // Normal phone call
	PMIC_AudioConfig();
#endif //#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)	
}

#elif defined(MT6797) 
// #define AP_AUDSYS_BASE   0xA1220000
#define AUDIO_PWR                       (BASE_MADDR_TOP_LEVEL_CLOCK_GENERATOR     + 0x6314)

#define AUDIO_TOP_CON0                  (BASE_MADDR_AUDIO + 0x0000)
#define AUDIO_TOP_CON1                  (BASE_MADDR_AUDIO + 0x0004)
//#define AUDIO_TOP_CON2                  (BASE_MADDR_AUDIO + 0x0008)
#define AUDIO_TOP_CON3                  (BASE_MADDR_AUDIO + 0x000C)
#define AFE_DAC_CON0                    (BASE_MADDR_AUDIO + 0x0010)
#define AFE_DAC_CON1                    (BASE_MADDR_AUDIO + 0x0014)
#define AFE_I2S_CON                     (BASE_MADDR_AUDIO + 0x0018)
#define AFE_DAIBT_CON0                  (BASE_MADDR_AUDIO + 0x001C)
                                        
#define AP_AFE_CONN0                    (BASE_MADDR_AUDIO + 0x0020)
#define AP_AFE_CONN1                    (BASE_MADDR_AUDIO + 0x0024)
#define AP_AFE_CONN2                    (BASE_MADDR_AUDIO + 0x0028)
#define AP_AFE_CONN3                    (BASE_MADDR_AUDIO + 0x002C)
#define AP_AFE_CONN4                    (BASE_MADDR_AUDIO + 0x0030)
#define AP_AFE_CONN5                    (BASE_MADDR_AUDIO + 0x005C)
#define AP_AFE_CONN6                    (BASE_MADDR_AUDIO + 0x00BC)
#define AP_AFE_CONN9                    (BASE_MADDR_AUDIO + 0x0440)
#define AP_AFE_CONN10                   (BASE_MADDR_AUDIO + 0x0444)
#define AP_AFE_CONN17                   (BASE_MADDR_AUDIO + 0x0460)
#define AP_AFE_CONN18                   (BASE_MADDR_AUDIO + 0x0464)

#define AFE_I2S_CON1                    (BASE_MADDR_AUDIO + 0x0034)
#define AFE_I2S_CON2                    (BASE_MADDR_AUDIO + 0x0038)
#define AFE_MRGIF_CON                   (BASE_MADDR_AUDIO + 0x003C)
#define AFE_I2S_CON3                    (BASE_MADDR_AUDIO + 0x004C)

#define AFE_ADDA_DL_SRC2_CON0           (BASE_MADDR_AUDIO + 0x0108)
#define AFE_ADDA_DL_SRC2_CON1           (BASE_MADDR_AUDIO + 0x010C)
#define AFE_ADDA_UL_SRC_CON0            (BASE_MADDR_AUDIO + 0x0114)
#define AFE_ADDA_UL_SRC_CON1            (BASE_MADDR_AUDIO + 0x0118)

#define AFE_ADDA_UL_DL_CON0             (BASE_MADDR_AUDIO + 0x0124)
#define AFE_ADDA_NEWIF_CFG0             (BASE_MADDR_AUDIO + 0x0138)
#define AFE_ADDA_NEWIF_CFG1             (BASE_MADDR_AUDIO + 0x013C)
#define AFE_ADDA_NEWIF_CFG2             (BASE_MADDR_AUDIO + 0x0140)

//#define AFE_SIDDETONE_MON               (BASE_MADDR_AUDIO + 0x01D4)
//#define AFE_SIDDETONE_CON0              (BASE_MADDR_AUDIO + 0x01E0)
//#define AFE_SIDDETONE_COEFF             (BASE_MADDR_AUDIO + 0x01E4)
#define AFE_SIDDETONE_CON1              (BASE_MADDR_AUDIO + 0x01E8)
//#define AFE_SIDDETONE_GAIN              (BASE_MADDR_AUDIO + 0x01EC)

#define AFE_SGEN_CON0                   (BASE_MADDR_AUDIO + 0x01F0)
#define AFE_TOP_CON0                    (BASE_MADDR_AUDIO + 0x0200)
#define AFE_GAIN1_CON0                  (BASE_MADDR_AUDIO + 0x0410)

#define AFE_GAIN1_CONN                  (BASE_MADDR_AUDIO + 0x0420)

#define AFE_GAIN2_CON0                  (BASE_MADDR_AUDIO + 0x0428)
#define AFE_GAIN2_CONN                  (BASE_MADDR_AUDIO + 0x0438)
#define AFE_GAIN2_CONN2                 (BASE_MADDR_AUDIO + 0x0430)
#define AFE_GAIN2_CONN3                 (BASE_MADDR_AUDIO + 0x0434)

#define PCM_INTF_CON1                   (BASE_MADDR_AUDIO + 0x0530)
#define PCM_INTF_CON2                   (BASE_MADDR_AUDIO + 0x0538)
#define PCM_INTF_CON                    (BASE_MADDR_AUDIO + 0x053C)
//#define FOC_ROM_SIG                     (BASE_MADDR_AUDIO + 0x0630)



// ----------------------------------------------------------------------------
// Register Setting for different scenario 
// ----------------------------------------------------------------------------


void PMIC_AudioConfig(void)
{
    DCL_HANDLE handle;
    PMU_CTRL_MISC_SET_REGISTER_VALUE setVal;
    PMU_CTRL_MISC_GET_REGISTER_VALUE getVal;
	  PMU_CTRL_MISC_GET_HW_VERSION val;

    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);	
    
    // 02AA 0008
    setVal.offset = ((0<<31) | 0x02AA);
    setVal.value  = (0x0008);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    
    AFE_DELAY(100); 
    
    // 02AC 0008
    setVal.offset = ((0<<31) | 0x02AC);
    setVal.value  = (0x0008);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    
    
    //0D06 0000
    setVal.offset = ((0<<31) | 0x0D06);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D04 0155
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0x0155);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //029E 0001
    setVal.offset = ((0<<31) | 0x029E);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    

    //029C 0001
    setVal.offset = ((0<<31) | 0x029C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    

    //0D0E 0040
    setVal.offset = ((0<<31) | 0x0D0E);
    setVal.value  = (0x0040);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D0E 0040
    setVal.offset = ((0<<31) | 0x0D0E);
    setVal.value  = (0x0040);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    


#if defined(MT6797_EVB) //ACC MODE
    //0D1A 0021
    setVal.offset = ((0<<31) | 0x0D1A);
    setVal.value  = (0x0021);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D1A 2121
    setVal.offset = ((0<<31) | 0x0D1A);
    setVal.value  = (0x2121);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D08 0311
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x0311);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    

    //0D0A 0331
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x0331);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0D08 5311
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x5311);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D0A 5331
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x5331);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);            
#else                   //DCC MODE
    //2090 2060
    setVal.offset = ((0<<31) | 0x2090);
    setVal.value  = (0x2060);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);      
    
    //2090 2061
    setVal.offset = ((0<<31) | 0x2090);
    setVal.value  = (0x2061);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D1A 0021
    setVal.offset = ((0<<31) | 0x0D1A);
    setVal.value  = (0x0021);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D1A 2121
    setVal.offset = ((0<<31) | 0x0D1A);
    setVal.value  = (0x2121);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
        
    //0D08 0317
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x0317);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D0A 0337
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x0337);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);   
    
    //0D08 5317
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x5317);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    AFE_DELAY(100);  
    //0D08 5313
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x5313);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);   
    
    //0D0A 5337
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x5337);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    AFE_DELAY(100);
    //0D0A 5333
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x5333);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);            
#endif

    //023E 3800
    setVal.offset = ((0<<31) | 0x023E);
    setVal.value  = (0x3800);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    
    //023A 00FD
    setVal.offset = ((0<<31) | 0x023A);
    setVal.value  = (0x00FD);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //2014 0040
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0x0040);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    
    //2012 0001
    //setVal.offset = ((0<<31) | 0x2012);
    //setVal.value  = (0x0001);
    //DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2000 0001
    setVal.offset = ((0<<31) | 0x2000);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //200A 0002
    setVal.offset = ((0<<31) | 0x200A);
    setVal.value  = (0x0002);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //200C 0001
    setVal.offset = ((0<<31) | 0x200C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 0155
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0x0155);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //029C 0001
    setVal.offset = ((0<<31) | 0x029C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //023E F000
    setVal.offset = ((0<<31) | 0x023E);
    setVal.value  = (0xF000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    AFE_DELAY(100);

    //2014 8000
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2098 1515
    setVal.offset = ((0<<31) | 0x2098);
    setVal.value  = (0x1515);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2096 8C01
    setVal.offset = ((0<<31) | 0x2096);
    setVal.value  = (0x8C01);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    AFE_DELAY(100);
    
    //2014 8000
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2020 0006
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x0006);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //201C C3A1
    setVal.offset = ((0<<31) | 0x201C);
    setVal.value  = (0xC3A1);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2020 0003
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x0003);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2020 000B
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x000B);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2008 001E
    setVal.offset = ((0<<31) | 0x2008);
    setVal.value  = (0x001E);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2000 0001
    setVal.offset = ((0<<31) | 0x2000);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2038 3330
    setVal.offset = ((0<<31) | 0x2038);
    setVal.value  = (0x3330);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2002 3300
    setVal.offset = ((0<<31) | 0x2002);
    setVal.value  = (0x3300);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2002 3300
    setVal.offset = ((0<<31) | 0x2002);
    setVal.value  = (0x3300);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2004 0001
    setVal.offset = ((0<<31) | 0x2004);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
		
		//203C B02F inverse RXCK
    setVal.offset = ((0<<31) | 0x203C);
    setVal.value  = (0xB02F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    //2012 0000
    setVal.offset = ((0<<31) | 0x2012);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2040 0080
    setVal.offset = ((0<<31) | 0x2040);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2042 0101
    setVal.offset = ((0<<31) | 0x2042);
    setVal.value  = (0x0101);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 A155
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0xA155);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D06 0100
    setVal.offset = ((0<<31) | 0x0D06);
    setVal.value  = (0x0100);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0800 0000
    setVal.offset = ((0<<31) | 0x0800);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0CF2 2080
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2080);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0CFE 0400
    setVal.offset = ((0<<31) | 0x0CFE);
    setVal.value  = (0x0400);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 A055
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0xA055);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0806 001F
    setVal.offset = ((0<<31) | 0x0806);
    setVal.value  = (0x001F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //for HS
    //0CF4 0100
    setVal.offset = ((0<<31) | 0x0CF4);
    setVal.value  = (0x0100);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 A255
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0xA255);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  


    //0CF2 2089
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2089);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0CF2 2109
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2109);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0CF2 2119
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2119);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0806 0009
    setVal.offset = ((0<<31) | 0x0806);
    setVal.value  = (0x0009);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    
    AFE_DELAY(100);           
}
void ApAudSys_config(void)
{
	// [RIMIND] Require by ShihHsin Tai, 	0x1000_629c = 32¡¦b1101 
	WriteREG(AUDIO_PWR, 	0x0000000D);
	WriteREG(AUDIO_TOP_CON0, 0x60004000); //script=0x60004000
	WriteREG(AFE_TOP_CON0, 0x00000000); //not in script
	//WriteREG(AFE_DAC_CON0, 0x00000001); // 0x11220010, not in script


#if APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K

	WriteREG(AFE_GAIN1_CONN, 0x03000000); // I11->o18  I10->o17
	
	WriteREG(AP_AFE_CONN0, 0x00000000); 
	WriteREG(AP_AFE_CONN1, 0x00000000);
	WriteREG(AP_AFE_CONN2, 0x00000000);
	WriteREG(AP_AFE_CONN3, 0x00004000); // MD1, I14->O03
	WriteREG(AP_AFE_CONN4, 0x00204000); // MD1, I14->O04, I21->O04   
	WriteREG(AP_AFE_CONN5, 0x00000000);

#else // phone call

  WriteREG(AP_AFE_CONN3, 0x00204000); // MD1, I14->O03
  WriteREG(AP_AFE_CONN4, 0x00204000); // MD1, I14->O04
  WriteREG(AP_AFE_CONN17, 0x00000008); // MD1, I03->O17
  WriteREG(AP_AFE_CONN18, 0x00000010); // MD1, I04->O18

#endif //APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K

#if APAUDSYS_DVT_8K
		WriteREG(AFE_GAIN1_CON0, 0x0000C801); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C0A40A8); //sinegen: O13 and O14,  8k, ch2 (08k/64)*4=500Hz, ch1 (08k/64)*8=1kHz
#elif APAUDSYS_DVT_16K
    WriteREG(AFE_GAIN1_CON0, 0x0000C841); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C4A44A8); //sinegen: O13 and O14, 16k, ch2 (16k/64)*4=1kHz, ch1 (16k/64)*8=2kHz

#elif APAUDSYS_DVT_32K
    WriteREG(AFE_GAIN1_CON0, 0x0000C881); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C8A48A8); //sinegen: O13 and O14, 32k, ch2 (32k/64)*4=2kHz, ch1 (32k/64)*8=4kHz
#endif
// sidetone
WriteREG(AFE_SIDDETONE_CON1, 0x00000000); //SIDETONE DISABLE


#if  APAUDSYS_DVT_32K
		WriteREG(PCM_INTF_CON,	0x00000057); // MD1
#elif  APAUDSYS_DVT_8K
		WriteREG(PCM_INTF_CON,	0x00000047); // MD1
#else //16K
		WriteREG(PCM_INTF_CON,	0x0000004F); // MD1
#endif
  	WriteREG(AFE_ADDA_NEWIF_CFG2, 0x13117180); // 0x1122013c




#if	APAUDSYS_DVT_16K

	
	WriteREG(AFE_I2S_CON1, 0x00000409);	
	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);	
	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script
	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124
	WriteREG(AFE_DAC_CON1, 0x00000400); //0x11220014, from script

#elif  APAUDSYS_DVT_8K


    WriteREG(AFE_I2S_CON1, 0x00000009);

    WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001); // 0x11220114
    WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x0f001821); // 0x11220108
    WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    WriteREG(AFE_ADDA_NEWIF_CFG2, 0x03117180); // 0x1122013C, from script

    WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    WriteREG(AFE_DAC_CON1, 0x00000000); //0x11220014, from script
#elif  APAUDSYS_DVT_32K // 32k
   		
    WriteREG(AFE_I2S_CON1, 0x00000809);
		

    //WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00140001); // 0x11220114

    WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00040001); // 0x11220114
    WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x6f001821); // 0x11220108
    WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    WriteREG(AFE_ADDA_NEWIF_CFG2, 0x23117180); // 0x1122013C, from script

    WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    WriteREG(AFE_DAC_CON1, 0x00000800); //0x11220014, from script



#else // for phone call script 
	WriteREG(PCM_INTF_CON, 0x0000004F);// 16K
	
	WriteREG(AFE_ADDA_NEWIF_CFG2, 0x13117180); //16K
	
	WriteREG(AFE_I2S_CON1, 0x00000409); //i2s2 OUT SAMPLE RATE = 16k

	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000); //0dB gain
	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // DL Sampling rate=16k audio mode
	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00020001); // UL Sampling rate=16k audio mode
	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 
	WriteREG(AFE_ADDA_NEWIF_CFG2, 0x13117180); // ULSample rate <=32k
	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // ul/dl enable	
	WriteREG(AFE_DAC_CON1, 0x00000400); // I2s sample rate =16k



#endif
	
	WriteREG(AFE_I2S_CON, 0x10000009); //master mode i2s in
	WriteREG(AFE_DAC_CON0, 0x00001001); // 0x11220010, from script, power on
#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
    // No UL, DL is output by earphone
	PMIC_AudioConfigForAPAUDSYSDVT();
#else //#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
    // Normal phone call
	PMIC_AudioConfig();
#endif //#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)	
}
#elif defined(MT6757) || defined(MT6750S) && !(MT6757P)

#define AUDIO_PWR                       (BASE_MADDR_TOP_LEVEL_CLOCK_GENERATOR     + 0x6314)

#define AUDIO_TOP_CON0                  (BASE_MADDR_AUDIO + 0x0000)
#define AUDIO_TOP_CON1                  (BASE_MADDR_AUDIO + 0x0004)
//#define AUDIO_TOP_CON2                  (BASE_MADDR_AUDIO + 0x0008)
#define AUDIO_TOP_CON3                  (BASE_MADDR_AUDIO + 0x000C)
#define AFE_DAC_CON0                    (BASE_MADDR_AUDIO + 0x0010)
#define AFE_DAC_CON1                    (BASE_MADDR_AUDIO + 0x0014)
#define AFE_I2S_CON                     (BASE_MADDR_AUDIO + 0x0018)
#define AFE_DAIBT_CON0                  (BASE_MADDR_AUDIO + 0x001C)
                                        
#define AP_AFE_CONN0                    (BASE_MADDR_AUDIO + 0x0020)
#define AP_AFE_CONN1                    (BASE_MADDR_AUDIO + 0x0024)
#define AP_AFE_CONN2                    (BASE_MADDR_AUDIO + 0x0028)
#define AP_AFE_CONN3                    (BASE_MADDR_AUDIO + 0x002C)
#define AP_AFE_CONN4                    (BASE_MADDR_AUDIO + 0x0030)
#define AP_AFE_CONN5                    (BASE_MADDR_AUDIO + 0x005C)
#define AP_AFE_CONN6                    (BASE_MADDR_AUDIO + 0x00BC)
#define AP_AFE_CONN9                    (BASE_MADDR_AUDIO + 0x0440)
#define AP_AFE_CONN10                   (BASE_MADDR_AUDIO + 0x0444)
#define AP_AFE_CONN17                   (BASE_MADDR_AUDIO + 0x0460)
#define AP_AFE_CONN18                   (BASE_MADDR_AUDIO + 0x0464)

#define AFE_I2S_CON1                    (BASE_MADDR_AUDIO + 0x0034)
#define AFE_I2S_CON2                    (BASE_MADDR_AUDIO + 0x0038)
#define AFE_MRGIF_CON                   (BASE_MADDR_AUDIO + 0x003C)
#define AFE_I2S_CON3                    (BASE_MADDR_AUDIO + 0x004C)

#define AFE_ADDA_DL_SRC2_CON0           (BASE_MADDR_AUDIO + 0x0108)
#define AFE_ADDA_DL_SRC2_CON1           (BASE_MADDR_AUDIO + 0x010C)
#define AFE_ADDA_UL_SRC_CON0            (BASE_MADDR_AUDIO + 0x0114)
#define AFE_ADDA_UL_SRC_CON1            (BASE_MADDR_AUDIO + 0x0118)

#define AFE_ADDA_UL_DL_CON0             (BASE_MADDR_AUDIO + 0x0124)
#define AFE_ADDA_NEWIF_CFG0             (BASE_MADDR_AUDIO + 0x0138)
#define AFE_ADDA_NEWIF_CFG1             (BASE_MADDR_AUDIO + 0x013C)


//#define AFE_SIDDETONE_MON               (BASE_MADDR_AUDIO + 0x01D4)
//#define AFE_SIDDETONE_CON0              (BASE_MADDR_AUDIO + 0x01E0)
//#define AFE_SIDDETONE_COEFF             (BASE_MADDR_AUDIO + 0x01E4)
#define AFE_SIDDETONE_CON1              (BASE_MADDR_AUDIO + 0x01E8)
//#define AFE_SIDDETONE_GAIN              (BASE_MADDR_AUDIO + 0x01EC)

#define AFE_SGEN_CON0                   (BASE_MADDR_AUDIO + 0x01F0)
#define AFE_TOP_CON0                    (BASE_MADDR_AUDIO + 0x0200)
#define AFE_GAIN1_CON0                  (BASE_MADDR_AUDIO + 0x0410)

#define AFE_CONN7                (BASE_MADDR_AUDIO + 0x0420) 

#define AFE_GAIN2_CON0                  (BASE_MADDR_AUDIO + 0x0428)
#define AFE_CONN8                (BASE_MADDR_AUDIO + 0x0438) 
#define AFE_CONN9                (BASE_MADDR_AUDIO + 0x0440) 
#define AFE_CONN10                 (BASE_MADDR_AUDIO + 0x0444) 

#define PCM_INTF_CON1                   (BASE_MADDR_AUDIO + 0x0530)
#define PCM_INTF_CON2                   (BASE_MADDR_AUDIO + 0x0538)
#define PCM_INTF_CON                    (BASE_MADDR_AUDIO + 0x053C)
//#define FOC_ROM_SIG                     (BASE_MADDR_AUDIO + 0x0630)             

void PMIC_AudioConfig(void)
{
    DCL_HANDLE handle;
    PMU_CTRL_MISC_SET_REGISTER_VALUE setVal;
    PMU_CTRL_MISC_GET_REGISTER_VALUE getVal;
	  PMU_CTRL_MISC_GET_HW_VERSION val;

    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);	
    
    //0D06 0000
    setVal.offset = ((0<<31) | 0x0D06);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D04 0155
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0x0155);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //029E 0001
    setVal.offset = ((0<<31) | 0x029E);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    

    //029C 0001
    setVal.offset = ((0<<31) | 0x029C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    

    //0D0E 0040
    setVal.offset = ((0<<31) | 0x0D0E);
    setVal.value  = (0x0040);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D0E 0040
    setVal.offset = ((0<<31) | 0x0D0E);
    setVal.value  = (0x0040);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    


#if 0// In 6757, no ACC mode defined(MT6757_EVB) //ACC MODE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else                   //DCC MODE
    //2090 2060
    setVal.offset = ((0<<31) | 0x2090);
    setVal.value  = (0x2060);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);      
    
    //2090 2061
    setVal.offset = ((0<<31) | 0x2090);
    setVal.value  = (0x2061);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D1A 0021
    setVal.offset = ((0<<31) | 0x0D1A);
    setVal.value  = (0x0021);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D1A 2121
    setVal.offset = ((0<<31) | 0x0D1A);
    setVal.value  = (0x2121);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
        
    //0D08 0317
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x0317);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    
    //0D0A 0337
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x0337);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);   
    
    //0D08 5317
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x5317);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    AFE_DELAY(100);  
    //0D08 5313
    setVal.offset = ((0<<31) | 0x0D08);
    setVal.value  = (0x5313);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);   
    
    //0D0A 5337
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x5337);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    AFE_DELAY(100);
    //0D0A 5333
    setVal.offset = ((0<<31) | 0x0D0A);
    setVal.value  = (0x5333);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);            
#endif

    //023E 6000
    setVal.offset = ((0<<31) | 0x023E);
    setVal.value  = (0x6000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //2014 0040
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0x0040);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2012 0000
    setVal.offset = ((0<<31) | 0x2012);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2000 0001
    setVal.offset = ((0<<31) | 0x2000);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //200A 0002
    setVal.offset = ((0<<31) | 0x200A);
    setVal.value  = (0x0002);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //200C 0001
    setVal.offset = ((0<<31) | 0x200C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 0155
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0x0155);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //029C 0001
    setVal.offset = ((0<<31) | 0x029C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //023E F000
    setVal.offset = ((0<<31) | 0x023E);
    setVal.value  = (0xF000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    AFE_DELAY(100);

    //2014 8000 
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2098 1515
    setVal.offset = ((0<<31) | 0x2098);
    setVal.value  = (0x1515);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2096 8C01
    setVal.offset = ((0<<31) | 0x2096);
    setVal.value  = (0x8C01);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    AFE_DELAY(100);
    
    //2014 8000
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2020 0006
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x0006);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //201C C3A1
    setVal.offset = ((0<<31) | 0x201C);
    setVal.value  = (0xC3A1);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2020 0003
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x0003);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2020 000B
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x000B);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2008 001E
    setVal.offset = ((0<<31) | 0x2008);
    setVal.value  = (0x001E);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2000 0001
    setVal.offset = ((0<<31) | 0x2000);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2038 3330
    setVal.offset = ((0<<31) | 0x2038);
    setVal.value  = (0x3330);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2002 3300
    setVal.offset = ((0<<31) | 0x2002);
    setVal.value  = (0x3300);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2002 3300
    setVal.offset = ((0<<31) | 0x2002);
    setVal.value  = (0x3300);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
		//203C B02F inverse RXCK
    setVal.offset = ((0<<31) | 0x203C);
    setVal.value  = (0xB02F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 

    //2004 0001
    setVal.offset = ((0<<31) | 0x2004);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2012 0000 => when sine gen value 0000, 2040 and 2042 will not work
    setVal.offset = ((0<<31) | 0x2012);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2040 0080 => sine gen, remove 
    //setVal.offset = ((0<<31) | 0x2040);
    //setVal.value  = (0x0080);
    //DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //2042 0101 => sine gen, remove 
    //setVal.offset = ((0<<31) | 0x2042);
    //setVal.value  = (0x0101);
    //DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 A155
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0xA155);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D06 0100
    setVal.offset = ((0<<31) | 0x0D06);
    setVal.value  = (0x0100);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0800 0000
    setVal.offset = ((0<<31) | 0x0800);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0CF2 2080
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2080);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0CFE 0400
    setVal.offset = ((0<<31) | 0x0CFE);
    setVal.value  = (0x0400);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 A055
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0xA055);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0806 001F
    setVal.offset = ((0<<31) | 0x0806);
    setVal.value  = (0x001F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //for HS
    //0CF4 0100
    setVal.offset = ((0<<31) | 0x0CF4);
    setVal.value  = (0x0100);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  

    //0D04 A255
    setVal.offset = ((0<<31) | 0x0D04);
    setVal.value  = (0xA255);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  


    //0CF2 2089
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2089);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0CF2 2109
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2109);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0CF2 2119
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x2119);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    //0806 0009
    setVal.offset = ((0<<31) | 0x0806);
    setVal.value  = (0x0009);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    
    
    AFE_DELAY(100);           
}
void ApAudSys_config(void)
{
	// [RIMIND] Require by ShihHsin Tai, 	0x1000_629c = 32¡¦b1101 
	WriteREG(AUDIO_PWR, 	0x0000000D);
	WriteREG(AUDIO_TOP_CON0, 0x60004000); //script=0x60004000
	WriteREG(AFE_TOP_CON0, 0x00000000); //not in script
	//WriteREG(AFE_DAC_CON0, 0x00000001); // 0x11220010, not in script

#if APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K

	//WriteREG(AFE_GAIN1_CONN, 0x03000000); // I11->o18  I10->o17
    WriteREG(AP_AFE_CONN17, 0x00000400); //I10->o17
    WriteREG(AP_AFE_CONN018, 0x00000800); // I11->o18  
	WriteREG(AP_AFE_CONN0, 0x00000000); 
	WriteREG(AP_AFE_CONN1, 0x00000000);
	WriteREG(AP_AFE_CONN2, 0x00000000);
	WriteREG(AP_AFE_CONN3, 0x00004000); // MD1, I14->O03
	
	WriteREG(AP_AFE_CONN4, 0x00200000); // MD1, I21->O04
	WriteREG(AP_AFE_CONN5, 0x00000000);
	//WriteREG(AP_AFE_CONN6, 0x00010000); // MD1, I21->O04
  	
  


#else // phone call

	   WriteREG(AP_AFE_CONN0, 0x00000000); // from script
	   WriteREG(AP_AFE_CONN1, 0x00000000);
	   WriteREG(AP_AFE_CONN2, 0x00000000);
	   WriteREG(AP_AFE_CONN3, 0x00004000); // MD1, I14->O03
	   WriteREG(AP_AFE_CONN4, 0x00004000); //I14->O04
	   WriteREG(AP_AFE_CONN17, 0x00000008); // I03->O17
	   WriteREG(AP_AFE_CONN18, 0x00000010); // I04->O18
	   WriteREG(AP_AFE_CONN5, 0x00000000);
	   WriteREG(AP_AFE_CONN6, 0x00000000);

#endif //APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K

#if APAUDSYS_DVT_8K
		WriteREG(AFE_GAIN1_CON0, 0x0000C801); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C0A40A8); //sinegen: O13 and O14,  8k, ch2 (08k/64)*4=500Hz, ch1 (08k/64)*8=1kHz
#elif APAUDSYS_DVT_16K
        WriteREG(AFE_GAIN1_CON0, 0x0000C841); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C4A44A8); //sinegen: O13 and O14, 16k, ch2 (16k/64)*4=1kHz, ch1 (16k/64)*8=2kHz

#elif APAUDSYS_DVT_32K
        WriteREG(AFE_GAIN1_CON0, 0x0000C881); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C8A48A8); //sinegen: O13 and O14, 32k, ch2 (32k/64)*4=2kHz, ch1 (32k/64)*8=4kHz
#endif
// sidetone
WriteREG(AFE_SIDDETONE_CON1, 0x00000000); //SIDETONE DISABLE


#if  APAUDSYS_DVT_32K
		WriteREG(PCM_INTF_CON,	0x00000057); // MD1
#elif  APAUDSYS_DVT_8K
		WriteREG(PCM_INTF_CON,	0x00000047); // MD1
#else //16K
		WriteREG(PCM_INTF_CON,	0x0000004F); // MD1
#endif
  	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013c




#if	APAUDSYS_DVT_16K

	
	WriteREG(AFE_I2S_CON1, 0x00000409);	
	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);	
	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script
	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124
	WriteREG(AFE_DAC_CON1, 0x00000400); //0x11220014, from script

#elif  APAUDSYS_DVT_8K


    WriteREG(AFE_I2S_CON1, 0x00000009);

    WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001); // 0x11220114
    WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x0f001821); // 0x11220108
    WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    WriteREG(AFE_DAC_CON1, 0x00000000); //0x11220014, from script
#elif  APAUDSYS_DVT_32K // 32k
   		
    WriteREG(AFE_I2S_CON1, 0x00000809);
		

    //WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00140001); // 0x11220114

    WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00140001); // 0x11220114
    WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x6f001821); // 0x11220108
    WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    WriteREG(AFE_DAC_CON1, 0x00000800); //0x11220014, from script



#else // for phone call script 
	WriteREG(PCM_INTF_CON, 0x0000004F);// 16K
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); //16K

	WriteREG(AFE_I2S_CON1, 0x00000409); //i2s2 OUT SAMPLE RATE = 16k

	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000); //0dB gain
	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // DL Sampling rate=16k audio mode
	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // UL Sampling rate=16k audio mode
	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // ULSample rate <=32k
	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // ul/dl enable	
	WriteREG(AFE_DAC_CON1, 0x00000400); // I2s sample rate =16k



#endif
	
	WriteREG(AFE_I2S_CON, 0x10000009); //master mode i2s in
	WriteREG(AFE_DAC_CON0, 0x00001001); // 0x11220010, from script, power on
#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
    // No UL, DL is output by earphone
	PMIC_AudioConfigForAPAUDSYSDVT();
#else //#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
    // Normal phone call
	PMIC_AudioConfig();
#endif //#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)	
}
#elif defined(MT6757P)
#define AUDIO_PWR                       (BASE_MADDR_TOP_LEVEL_CLOCK_GENERATOR     + 0x6314)
#define AUDIO_TOP_CON0                  (BASE_MADDR_AUDIO + 0x0000)
#define AUDIO_TOP_CON1                  (BASE_MADDR_AUDIO + 0x0004)
//#define AUDIO_TOP_CON2                  (BASE_MADDR_AUDIO + 0x0008)
#define AUDIO_TOP_CON3                  (BASE_MADDR_AUDIO + 0x000C)
#define AFE_DAC_CON0                    (BASE_MADDR_AUDIO + 0x0010)
#define AFE_DAC_CON1                    (BASE_MADDR_AUDIO + 0x0014)
#define AFE_I2S_CON                     (BASE_MADDR_AUDIO + 0x0018)
#define AFE_DAIBT_CON0                  (BASE_MADDR_AUDIO + 0x001C)
                                        
#define AP_AFE_CONN0                    (BASE_MADDR_AUDIO + 0x0020)
#define AP_AFE_CONN1                    (BASE_MADDR_AUDIO + 0x0024)
#define AP_AFE_CONN2                    (BASE_MADDR_AUDIO + 0x0028)
#define AP_AFE_CONN3                    (BASE_MADDR_AUDIO + 0x002C)
#define AP_AFE_CONN4                    (BASE_MADDR_AUDIO + 0x0030)
#define AP_AFE_CONN5                    (BASE_MADDR_AUDIO + 0x005C)
#define AP_AFE_CONN6                    (BASE_MADDR_AUDIO + 0x00BC)
#define AP_AFE_CONN9                    (BASE_MADDR_AUDIO + 0x0440)
#define AP_AFE_CONN10                   (BASE_MADDR_AUDIO + 0x0444)
#define AP_AFE_CONN17                   (BASE_MADDR_AUDIO + 0x0460)
#define AP_AFE_CONN18                   (BASE_MADDR_AUDIO + 0x0464)

#define AFE_I2S_CON1                    (BASE_MADDR_AUDIO + 0x0034)
#define AFE_I2S_CON2                    (BASE_MADDR_AUDIO + 0x0038)
#define AFE_MRGIF_CON                   (BASE_MADDR_AUDIO + 0x003C)
#define AFE_I2S_CON3                    (BASE_MADDR_AUDIO + 0x004C)

#define AFE_ADDA_DL_SRC2_CON0           (BASE_MADDR_AUDIO + 0x0108)
#define AFE_ADDA_DL_SRC2_CON1           (BASE_MADDR_AUDIO + 0x010C)
#define AFE_ADDA_UL_SRC_CON0            (BASE_MADDR_AUDIO + 0x0114)
#define AFE_ADDA_UL_SRC_CON1            (BASE_MADDR_AUDIO + 0x0118)

#define AFE_ADDA_UL_DL_CON0             (BASE_MADDR_AUDIO + 0x0124)
#define AFE_ADDA_NEWIF_CFG0             (BASE_MADDR_AUDIO + 0x0138)
#define AFE_ADDA_NEWIF_CFG1             (BASE_MADDR_AUDIO + 0x013C)


//#define AFE_SIDDETONE_MON               (BASE_MADDR_AUDIO + 0x01D4)
//#define AFE_SIDDETONE_CON0              (BASE_MADDR_AUDIO + 0x01E0)
//#define AFE_SIDDETONE_COEFF             (BASE_MADDR_AUDIO + 0x01E4)
#define AFE_SIDDETONE_CON1              (BASE_MADDR_AUDIO + 0x01E8)
//#define AFE_SIDDETONE_GAIN              (BASE_MADDR_AUDIO + 0x01EC)

#define AFE_SGEN_CON0                   (BASE_MADDR_AUDIO + 0x01F0)
#define AFE_TOP_CON0                    (BASE_MADDR_AUDIO + 0x0200)
#define AFE_GAIN1_CON0                  (BASE_MADDR_AUDIO + 0x0410)

#define AFE_CONN7                (BASE_MADDR_AUDIO + 0x0420) 

#define AFE_GAIN2_CON0                  (BASE_MADDR_AUDIO + 0x0428)
#define AFE_CONN8                (BASE_MADDR_AUDIO + 0x0438) 
#define AFE_CONN9                (BASE_MADDR_AUDIO + 0x0440) 
#define AFE_CONN10                 (BASE_MADDR_AUDIO + 0x0444) 

#define PCM_INTF_CON1                   (BASE_MADDR_AUDIO + 0x0530)
#define PCM_INTF_CON2                   (BASE_MADDR_AUDIO + 0x0538)
#define PCM_INTF_CON                    (BASE_MADDR_AUDIO + 0x053C)
//#define FOC_ROM_SIG                     (BASE_MADDR_AUDIO + 0x0630)             

void PMIC_AudioConfig(void)
{
    DCL_HANDLE handle;
    PMU_CTRL_MISC_SET_REGISTER_VALUE setVal;
    PMU_CTRL_MISC_GET_REGISTER_VALUE getVal;
	  PMU_CTRL_MISC_GET_HW_VERSION val;

    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);	
    
    //uplink analog part
    //0x361A 0x0010
    setVal.offset = ((0<<31) | 0x361A);
    setVal.value  = (0x0010);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);    
    //0x361A 0x0000
    setVal.offset = ((0<<31) | 0x361A);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);  
    //0x044C 0x0800
    setVal.offset = ((0<<31) | 0x044C);
    setVal.value  = (0x8001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 

    //0x3624 0x0001
    setVal.offset = ((0<<31) | 0x3624);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    //0x0412 0x0102
    setVal.offset = ((0<<31) | 0x0412);
    setVal.value  = (0x0102);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    //0x6090 0x2060
    setVal.offset = ((0<<31) | 0x6090);
    setVal.value  = (0x2060);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    //0x6090 0x2061
    setVal.offset = ((0<<31) | 0x6090);
    setVal.value  = (0x2061);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    //0x3632 0x0021
    setVal.offset = ((0<<31) | 0x3632);
    setVal.value  = (0x0021);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    //0x361E 0x0347
    setVal.offset = ((0<<31) | 0x361E);
    setVal.value  = (0x0347);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    //0x3620 0x03C7
    setVal.offset = ((0<<31) | 0x3620);
    setVal.value  = (0x03C7);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    //0x361E 0x5347
    setVal.offset = ((0<<31) | 0x361E);
    setVal.value  = (0x5347);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    //0x3620 0x53C7
    setVal.offset = ((0<<31) | 0x3620);
    setVal.value  = (0x53C7);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 
    AFE_DELAY(100);  
    //0x361E 0x5343
    setVal.offset = ((0<<31) | 0x361E);
    setVal.value  = (0x5343);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x3620 0x53C3
    setVal.offset = ((0<<31) | 0x3620);
    setVal.value  = (0x53C3);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x361E 0x5B43
    setVal.offset = ((0<<31) | 0x361E);
    setVal.value  = (0x5B43);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x3620 0x5BC3
    setVal.offset = ((0<<31) | 0x3620);
    setVal.value  = (0x5BC3);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    
    //uplink digital part
    
    //0x242E 0x0049
    setVal.offset = ((0<<31) | 0x0224);
    setVal.value  = (0xCECC);
    
    //0x242E 0x0049
    setVal.offset = ((0<<31) | 0x242E);
    setVal.value  = (0x0049);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6014 0x0000
    setVal.offset = ((0<<31) | 0x6014);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6012 0x0000
    setVal.offset = ((0<<31) | 0x6012);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x603A 0x0338
    setVal.offset = ((0<<31) | 0x603A);
    setVal.value  = (0x0338);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x603C 0xB02F
    setVal.offset = ((0<<31) | 0x603C);
    setVal.value  = (0xB02F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6000 0x0001
    setVal.offset = ((0<<31) | 0x6000);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x600A 0x0002
    setVal.offset = ((0<<31) | 0x600A);
    setVal.value  = (0x0002);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x600C 0x0001
    setVal.offset = ((0<<31) | 0x600C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    
    //downlink digital part
    //0x361A 0x0000
    setVal.offset = ((0<<31) | 0x361A);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x3604 0x8000
    setVal.offset = ((0<<31) | 0x3604);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    AFE_DELAY(250);  
    //0x6014 0x8000
    setVal.offset = ((0<<31) | 0x6014);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6098 0x1515
    setVal.offset = ((0<<31) | 0x6098);
    setVal.value  = (0x1515);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6096 0xC801
    setVal.offset = ((0<<31) | 0x6096);
    setVal.value  = (0xC801);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    AFE_DELAY(250);
    //0x6014 0x8000
    setVal.offset = ((0<<31) | 0x6014);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6020 0x0006
    setVal.offset = ((0<<31) | 0x6020);
    setVal.value  = (0x0006);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x601C 0xCBA1
    setVal.offset = ((0<<31) | 0x601C);
    setVal.value  = (0xCBA1);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6020 0x0003
    setVal.offset = ((0<<31) | 0x6020);
    setVal.value  = (0x0003);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6020 0x000B
    setVal.offset = ((0<<31) | 0x6020);
    setVal.value  = (0x000B);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6008 0x001D
    setVal.offset = ((0<<31) | 0x6008);
    setVal.value  = (0x001D);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6000 0x0001
    setVal.offset = ((0<<31) | 0x6000);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6038 0x3331
    setVal.offset = ((0<<31) | 0x6038);
    setVal.value  = (0x3331);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6002 0x3300
    setVal.offset = ((0<<31) | 0x6002);
    setVal.value  = (0x3300);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x6004 0x0003
    setVal.offset = ((0<<31) | 0x6004);
    setVal.value  = (0x0003);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    
    //downlink analog part    
    //0x3604 0xC000
    setVal.offset = ((0<<31) | 0x3604);
    setVal.value  = (0xC000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x361C 0x0005
    setVal.offset = ((0<<31) | 0x361C);
    setVal.value  = (0x0005);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x361C 0x0015
    setVal.offset = ((0<<31) | 0x361C);
    setVal.value  = (0x0015);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    AFE_DELAY(100);
    //0x3800 0x0000
    setVal.offset = ((0<<31) | 0x3800);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x360C 0x0010
    setVal.offset = ((0<<31) | 0x360C);
    setVal.value  = (0x0010);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x3618 0x0055
    setVal.offset = ((0<<31) | 0x3618);
    setVal.value  = (0x0055);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x3616 0x4900
    setVal.offset = ((0<<31) | 0x3616);
    setVal.value  = (0x4900);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x3618 0x0055
    setVal.offset = ((0<<31) | 0x3618);
    setVal.value  = (0x0055);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x360C 0x0090
    setVal.offset = ((0<<31) | 0x360C);
    setVal.value  = (0x0090);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x360C 0x0092
    setVal.offset = ((0<<31) | 0x360C);
    setVal.value  = (0x0092);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x360C 0x0093
    setVal.offset = ((0<<31) | 0x360C);
    setVal.value  = (0x0093);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x3806 0x0009
    setVal.offset = ((0<<31) | 0x3806);
    setVal.value  = (0x0009);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x361A 0x0001
    setVal.offset = ((0<<31) | 0x361A);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x3600 0x0009
    setVal.offset = ((0<<31) | 0x3600);
    setVal.value  = (0x0009);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x3612 0x0001
    setVal.offset = ((0<<31) | 0x3612);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    //0x360C 0x009B
    setVal.offset = ((0<<31) | 0x360C);
    setVal.value  = (0x009B);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
}

void ApAudSys_config(void)
{
	// [RIMIND] Require by ShihHsin Tai, 	0x1000_629c = 32¡¦b1101 
	WriteREG(AUDIO_PWR, 	0x0000000D);
	WriteREG(AUDIO_TOP_CON0, 0x60004000); //script=0x60004000
	WriteREG(AFE_TOP_CON0, 0x00000000); //not in script
	//WriteREG(AFE_DAC_CON0, 0x00000001); // 0x11220010, not in script

#if APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K

	//WriteREG(AFE_GAIN1_CONN, 0x03000000); // I11->o18  I10->o17
    WriteREG(AP_AFE_CONN17, 0x00000400); //I10->o17
    WriteREG(AP_AFE_CONN018, 0x00000800); // I11->o18  
	WriteREG(AP_AFE_CONN0, 0x00000000); 
	WriteREG(AP_AFE_CONN1, 0x00000000);
	WriteREG(AP_AFE_CONN2, 0x00000000);
	WriteREG(AP_AFE_CONN3, 0x00004000); // MD1, I14->O03
	
	WriteREG(AP_AFE_CONN4, 0x00200000); // MD1, I21->O04
	WriteREG(AP_AFE_CONN5, 0x00000000);
	//WriteREG(AP_AFE_CONN6, 0x00010000); // MD1, I21->O04
  	
  


#else // phone call

	   WriteREG(AP_AFE_CONN0, 0x00000000); // from script
	   WriteREG(AP_AFE_CONN1, 0x00000000);
	   WriteREG(AP_AFE_CONN2, 0x00000000);
	   WriteREG(AP_AFE_CONN3, 0x00004000); // MD1, I14->O03
	   WriteREG(AP_AFE_CONN4, 0x00004000); //I14->O04
	   WriteREG(AP_AFE_CONN17, 0x00000008); // I03->O17
	   WriteREG(AP_AFE_CONN18, 0x00000010); // I04->O18
	   WriteREG(AP_AFE_CONN5, 0x00000000);
	   WriteREG(AP_AFE_CONN6, 0x00000000);

#endif //APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K

#if APAUDSYS_DVT_8K
		WriteREG(AFE_GAIN1_CON0, 0x0000C801); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C0A40A8); //sinegen: O13 and O14,  8k, ch2 (08k/64)*4=500Hz, ch1 (08k/64)*8=1kHz
#elif APAUDSYS_DVT_16K
        WriteREG(AFE_GAIN1_CON0, 0x0000C841); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C4A44A8); //sinegen: O13 and O14, 16k, ch2 (16k/64)*4=1kHz, ch1 (16k/64)*8=2kHz

#elif APAUDSYS_DVT_32K
        WriteREG(AFE_GAIN1_CON0, 0x0000C881); // enable Gain1
		WriteREG(AFE_SGEN_CON0, 0x8C8A48A8); //sinegen: O13 and O14, 32k, ch2 (32k/64)*4=2kHz, ch1 (32k/64)*8=4kHz
#endif
// sidetone
WriteREG(AFE_SIDDETONE_CON1, 0x00000000); //SIDETONE DISABLE


#if  APAUDSYS_DVT_32K
		WriteREG(PCM_INTF_CON,	0x00000057); // MD1
#elif  APAUDSYS_DVT_8K
		WriteREG(PCM_INTF_CON,	0x00000047); // MD1
#else //16K
		WriteREG(PCM_INTF_CON,	0x0000004F); // MD1
#endif
  	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013c




#if	APAUDSYS_DVT_16K

	
	WriteREG(AFE_I2S_CON1, 0x00000409);	
	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);	
	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script
	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124
	WriteREG(AFE_DAC_CON1, 0x00000400); //0x11220014, from script

#elif  APAUDSYS_DVT_8K


    WriteREG(AFE_I2S_CON1, 0x00000009);

    WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001); // 0x11220114
    WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x0f001821); // 0x11220108
    WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    WriteREG(AFE_DAC_CON1, 0x00000000); //0x11220014, from script
#elif  APAUDSYS_DVT_32K // 32k
   		
    WriteREG(AFE_I2S_CON1, 0x00000809);
		

    //WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00140001); // 0x11220114

    WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00140001); // 0x11220114
    WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x6f001821); // 0x11220108
    WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    WriteREG(AFE_DAC_CON1, 0x00000800); //0x11220014, from script



#else // for phone call script 
	WriteREG(PCM_INTF_CON, 0x0000004F);// 16K
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); //16K

	WriteREG(AFE_I2S_CON1, 0x00000409); //i2s2 OUT SAMPLE RATE = 16k

	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000); //0dB gain
	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // DL Sampling rate=16k audio mode
	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // UL Sampling rate=16k audio mode
	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // ULSample rate <=32k
	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // ul/dl enable	
	WriteREG(AFE_DAC_CON1, 0x00000400); // I2s sample rate =16k



#endif
	
	WriteREG(AFE_I2S_CON, 0x10000009); //master mode i2s in
	WriteREG(AFE_DAC_CON0, 0x00001001); // 0x11220010, from script, power on
#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
    // No UL, DL is output by earphone
	PMIC_AudioConfigForAPAUDSYSDVT();
#else //#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
    // Normal phone call
	PMIC_AudioConfig();
#endif //#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)	
}
#endif

#endif // !defined(__SMART_PHONE_MODEM__)
