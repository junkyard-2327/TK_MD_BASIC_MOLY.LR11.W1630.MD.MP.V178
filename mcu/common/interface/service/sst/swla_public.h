#ifndef SWLA_PUBLIC_H
#define SWLA_PUBLIC_H

#include "drv_asm.h"

kal_uint32 SLA_Enable(void);
kal_uint32 SLA_Disable(void);
void SLA_TriggerLogging(kal_uint32 fEnable);
kal_bool SLA_RetreiveLoggingBuffer(kal_uint8 **startAddr, kal_uint32 *size, kal_uint8 **currPtr);
kal_bool SLA_RetreiveHeader(kal_uint8 **MADesc, kal_uint32 *szMADesc, kal_uint8 **ARef, kal_uint32 *szARef);
kal_uint32 SLA_HookLogging(void);
void SLA_LoggingLISR(kal_uint32 ID);
void SLA_SleepComp(void);
kal_uint32 SLA_Respond(void);
kal_bool SLA_IsEnabled(void);
kal_uint32 SLA_TurnOn(void);
kal_uint32 SLA_TurnOff(void);
kal_uint32 SLA_Init(void);	
kal_bool SLA_IsRunning(void);
MALMO_ASM_MODE SLA_MALMO_ASM_GetMode(void);
void SLA_MALMO_ASM_Stop(void);
kal_bool SLA_MALMO_ASM_Start_LA(MALMO_ASM_MODE mode);
kal_bool SLA_MALMO_ASM_Start_HwSwtrMode(kal_uint32 sampling_rate);
kal_uint32 SLA_MALMO_ASM_Start_BusMonitorMode(kal_uint32* range);

typedef enum 
{
   SA_stop = 0,
   SA_start = 1,
   SA_label = 2
} SA_ACTION_T;

typedef enum 
{
   TAG_NEST_BEGIN   = 0xE0,
   TAG_NEST_END     = 0xE1,
   TAG_SINGLE_LABEL = 0xE2,
   TAG_BEGIN_POINT  = 0xE3,
   TAG_END_POINT    = 0xE4
} SA_TAG_T;	

void SLA_CustomLogging(kal_char *customJob, SA_ACTION_T saAction);
void SLA_HWLogging(kal_char *customJob, SA_ACTION_T saAction);
kal_bool SLA_Mode_Start (MALMO_ASM_MODE mode, kal_uint32 sampling_rate, kal_uint32* range);
kal_bool SLA_RetreiveL1coreLoggingBuffer(kal_uint8 **startAddr, kal_uint32 *size, kal_uint8 **currPtr);
kal_bool SLA_RetreiveL1Header(kal_uint8 **MADesc, kal_uint32 *szMADesc, kal_uint8 **ARef, kal_uint32 *szARef) ;
MALMO_ASM_MODE SLA_Get_Mode(void);
kal_bool SLA_Set_Default_Mode(MALMO_ASM_MODE setMode);


#endif
