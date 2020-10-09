#include <stdio.h>
#include "kal_general_types.h"
#include "uart_hw.h"
#include "uart_sw_int.h"


void UART_WriteReg(volatile kal_uint32* addr, kal_uint16 data)
{
   *(kal_uint8*) addr = (kal_uint8)data;
}

kal_uint16 UART_ReadReg(volatile kal_uint32* addr)
{
   volatile kal_uint8 tmp;
   tmp = *(kal_uint8*) addr;
   return (kal_uint16)tmp;
}


void UART_PutByte(kal_uint8 data)
{
   volatile kal_uint16 LSR;
   while(1)
   {
      LSR = UART_ReadReg(UART1_LSR);

      if ( LSR & UART_LSR_THRE )
      {
         UART_WriteReg(UART1_THR, (kal_uint16)data);
         break;
      }
   }
}



void UART_SendBufbyPort(kal_uint8 port, kal_uint8* array, kal_uint32 length)
{
    kal_uint32 i;
    volatile kal_uint16 LSR;
    volatile kal_uint32* _LSR, *_THR;
    
    _LSR = (port == 1) ? UART1_LSR : UART2_LSR;
    _THR = (port == 1) ? UART1_THR : UART2_THR;

    for(i = 0; i < length; i++) {
      LSR = UART_ReadReg(_LSR);

      if ( LSR & UART_LSR_THRE )
      {
         UART_WriteReg(_THR, (kal_uint16)(*(array+i)));
         break;
      }
    }
}


void UART_GetByte_nonLoop(kal_uint8 *buffer, kal_uint16 *datain)
{
   volatile kal_uint16  LSR;
  
   LSR = UART_ReadReg(UART1_LSR);
   if (LSR & UART_LSR_DR)
   {
      *buffer = (kal_uint8)UART_ReadReg(UART1_RBR);
      *datain = 1;
   }
   else
      *datain = 0;
}


void UART_init()
{
    UART_SETUP(1, 0x40, 0x0);
    UART_SETUP(2, 0x40, 0x0);
}
