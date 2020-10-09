#ifndef __UART_HW_H__
#define __UART_HW_H__

#include "reg_base.h"

#define UART1_RBR               ((volatile kal_uint32*)(UART1_base+0x0000))
#define UART1_THR               ((volatile kal_uint32*)(UART1_base+0x0000))
#define UART1_IER               ((volatile kal_uint32*)(UART1_base+0x0004))
#define UART1_IIR               ((volatile kal_uint32*)(UART1_base+0x0008))
#define UART1_FCR               ((volatile kal_uint32*)(UART1_base+0x0008))
#define UART1_LCR               ((volatile kal_uint32*)(UART1_base+0x000C))
#define UART1_MCR               ((volatile kal_uint32*)(UART1_base+0x0010))
#define UART1_LSR               ((volatile kal_uint32*)(UART1_base+0x0014))
#define UART1_MSR               ((volatile kal_uint32*)(UART1_base+0x0018))
#define UART1_SCR               ((volatile kal_uint32*)(UART1_base+0x001C))
#define UART1_DLL               ((volatile kal_uint32*)(UART1_base+0x0000))
#define UART1_DLM               ((volatile kal_uint32*)(UART1_base+0x0004))
#define UART1_EFR               ((volatile kal_uint32*)(UART1_base+0x0008))
#define UART1_XON1              ((volatile kal_uint32*)(UART1_base+0x0010))
#define UART1_XON2              ((volatile kal_uint32*)(UART1_base+0x0014))
#define UART1_XOFF1             ((volatile kal_uint32*)(UART1_base+0x0018))
#define UART1_XOFF2             ((volatile kal_uint32*)(UART1_base+0x001C))
#define UART1_AUTOBAUD_EN       ((volatile kal_uint32*)(UART1_base+0x0020))
#define UART1_HIGHSPEED         ((volatile kal_uint32*)(UART1_base+0x0024))
#define UART1_SAMPLE_COUNT      ((volatile kal_uint32*)(UART1_base+0x0028))
#define UART1_SAMPLE_POINT      ((volatile kal_uint32*)(UART1_base+0x002C))
#define UART1_RATEFIX_AD        ((volatile kal_uint32*)(UART1_base+0x0034))
#define UART1_AUTOBAUDSAMPLE    ((volatile kal_uint32*)(UART1_base+0x0038))
#define UART1_GUARD             ((volatile kal_uint32*)(UART1_base+0x003C))


#define UART2_RBR               ((volatile kal_uint32*)(UART2_base+0x0000))
#define UART2_THR               ((volatile kal_uint32*)(UART2_base+0x0000))
#define UART2_IER               ((volatile kal_uint32*)(UART2_base+0x0004))
#define UART2_IIR               ((volatile kal_uint32*)(UART2_base+0x0008))
#define UART2_FCR               ((volatile kal_uint32*)(UART2_base+0x0008))
#define UART2_LCR               ((volatile kal_uint32*)(UART2_base+0x000C))
#define UART2_MCR               ((volatile kal_uint32*)(UART2_base+0x0010))
#define UART2_LSR               ((volatile kal_uint32*)(UART2_base+0x0014))
#define UART2_MSR               ((volatile kal_uint32*)(UART2_base+0x0018))
#define UART2_SCR               ((volatile kal_uint32*)(UART2_base+0x001C))
#define UART2_DLL               ((volatile kal_uint32*)(UART2_base+0x0000))
#define UART2_DLM               ((volatile kal_uint32*)(UART2_base+0x0004))
#define UART2_EFR               ((volatile kal_uint32*)(UART2_base+0x0008))
#define UART2_XON1              ((volatile kal_uint32*)(UART2_base+0x0010))
#define UART2_XON2              ((volatile kal_uint32*)(UART2_base+0x0014))
#define UART2_XOFF1             ((volatile kal_uint32*)(UART2_base+0x0018))
#define UART2_XOFF2             ((volatile kal_uint32*)(UART2_base+0x001C))
#define UART2_AUTOBAUD_EN       ((volatile kal_uint32*)(UART2_base+0x0020))
#define UART2_HIGHSPEED         ((volatile kal_uint32*)(UART2_base+0x0024))
#define UART2_SAMPLE_COUNT      ((volatile kal_uint32*)(UART2_base+0x0028))
#define UART2_SAMPLE_POINT      ((volatile kal_uint32*)(UART2_base+0x002C))
#define UART2_RATEFIX_AD        ((volatile kal_uint32*)(UART2_base+0x0034))
#define UART2_AUTOBAUDSAMPLE    ((volatile kal_uint32*)(UART2_base+0x0038))
#define UART2_GUARD             ((volatile kal_uint32*)(UART2_base+0x003C))


/* IER */
#define   IER_HW_NORMALINTS         0x000d

/* LCR */
#define   UART_LCR_DLAB             0x0080

/* LSR */
#define   UART_LSR_THRE             0x0020
#define   UART_LSR_DR               0x0001




#endif /* __UART_HW_H__ */
