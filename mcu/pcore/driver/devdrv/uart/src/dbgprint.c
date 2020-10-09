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
 *   dbgprint.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   This Module defines debug function for driver.
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 06 18 2015 da.li
 * [MOLY00121478] [UMOLY][JADE]UART driver compile error fix
 * Compile error fix on JADE(MT6755).
 *
 * 06 16 2015 da.li
 * [MOLY00121478] [UMOLY][JADE]UART driver compile error fix
 * UART driver compile error fix.
 *
 * 06 15 2015 da.li
 * [MOLY00121478] [UMOLY][JADE]UART driver compile error fix
 * UART driver compile error fix on MT6755(JADE).
 *
 * 05 12 2015 shenghui.shi
 * [MOLY00112994] [Need Patch] UMOLY build error for TK6291_E1EVB(LWTG1_L1S_V2SKU1) [L1CORE]
 * .
 *
 * 05 11 2015 shenghui.shi
 * [MOLY00081492] [UART] update uart driver
 * pdn clear UART/GDMA clock before use UART driver
 *
 * 05 22 2014 shenghui.shi
 * [MOLY00065467] [TK6291] update UART driver for TK6291
 * .
 *
 * 05 22 2014 shenghui.shi
 * [MOLY00065467] [TK6291] update UART driver for TK6291
 * update dbg_print() API
 *
 * 05 19 2014 shenghui.shi
 * [MOLY00065467] [TK6291] update UART driver for TK6291
 * Revert uart dbgprint.c to version1. to fixed dbg_print() undefined error.
 *
 * 12 10 2013 shenghui.shi
 * [MOLY00049628] MT6595 UART merge to Trunk
 * .
 *
 * 11 13 2013 shenghui.shi
 * [MOLY00046360] add SLT UART  logging API
 * .
 *
 * 09 03 2013 shenghui.shi
 * [MOLY00035768] fix uart build warnning
 * 	.
 *
 * 09 03 2013 shenghui.shi
 * [MOLY00035768] fix uart build warnning
 * .
 *
 * 07 18 2013 shenghui.shi
 * [MOLY00027330] [ARM7toMOLY] ARM7 Build/SYSGEN/Functions Update to TRUNK
 * add dbgprint for ARM7 using SUART0 port.
 *
 * 03 06 2013 ansel.liao
 * [MOLY00006575] add temporary feature: can use CPU mode UART in normal build
 * Integration change.
 *
 * 03 05 2013 ansel.liao
 * [MOLY00006575] add temporary feature: can use CPU mode UART in normal build
 * temporary feature
 *
 * 11 30 2012 ansel.liao
 * [MOLY00006575] Add UART/HDMA Driver
 * add dbg_flush and corresponding drvtest
 *
 * 11 23 2012 ansel.liao
 * [MOLY00006575] Add UART/HDMA Driver
 * Add UART/HDMA driver
 ****************************************************************************/
#define MAXCHARS	512
#define MAXFRACT    	10000
#define NumFract        4

#include "drv_comm.h"
#include "stdarg.h"
#include "dcl.h"

#include "kal_public_api.h"
#include "uart_internal.h"
#include "uart_hw.h"
#include "drvpdn.h"

#ifdef  DRV_DEBUG

#if (defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__)
#define DBG_PRINT_PORT		uart_port2 // Use UART2 as debug port (UART_SH0)
#else /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
#define DBG_PRINT_PORT		uart_port1 // Use UART1 as debug port (UART_MD)
#endif /* end of else of "defined(MT6290) && defined(__ARM7EJ_S__)" */
#define DBG_PRINT_BAUD		UART_BAUD_115200

extern kal_bool INT_QueryExceptionStatus(); 
extern kal_uint32 UART_BaseAddr[MAX_UART_PORT_NUM];
extern UARTStruct UARTPort[MAX_UART_PORT_NUM];

extern void U_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid);
static void itoa(char **buf, int i, int base);
void itof(char **buf, int i);

static kal_bool dbg_init_flag = KAL_FALSE;

char print_buf[MAXCHARS];

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
#endif

static void dbg_uart_init(void){

	kal_uint32 port = DBG_PRINT_PORT;
	kal_uint32 uart_base = UART_BaseAddr[DBG_PRINT_PORT];
	
	
#if defined(__MTK_TARGET__)
	switch(port){
		case uart_port1: 
			PDN_CLR(PDN_UART0);
			break;
		case uart_port2: 
			PDN_CLR(PDN_UART1);
			break;
#ifdef __UART3_SUPPORT__
		case uart_port3: 
			PDN_CLR(PDN_UART2);
			break;
#endif
		default: break;
	}
#endif

	DRV_WriteReg(UART_IER(uart_base), UART_IER_ALLOFF);
	DRV_WriteReg32(UART_DMA_EN(uart_base), 0x0); //disable DMA
	DRV_WriteReg32(UART_LCR(uart_base), 0xBF);
	DRV_WriteReg32(UART_EFR(uart_base), 0x0);  //no flow control;
	DRV_WriteReg32(UART_LCR(uart_base), 0x03);  //word len = 8 bit;  stop bit =1; parity = false;
	DRV_WriteReg32(UART_FCR(uart_base), 0x05);  //set fifo enable ,and clear Tx and Rx  fifo.
	U_SetBaudRate(DBG_PRINT_PORT, DBG_PRINT_BAUD, (module_type)(DBG_PRINT_PORT));

}

static void dbg_UARTPutByte(kal_uint8 data)
{
   volatile kal_uint16 LSR;
   kal_uint32 uart_base = UART_BaseAddr[DBG_PRINT_PORT];
   while(1)
   {
   	  LSR = DRV_Reg32(UART_LSR(uart_base));
      if((LSR & UART_LSR_THRE))
      {
       	 DRV_WriteReg32(UART_THR(uart_base), data);
         break;
      }
   }
}

void dbg_print(char *fmt,...)
{
#if (!defined(IC_MODULE_TEST))
	int i;
	va_list ap;
	double dval;
	int ival;
	char *p, *sval;
	char *bp, cval;
	int fract;
	unsigned short len;

	char print_buf[MAXCHARS];
	bp= print_buf;
	*bp= 0;
	if(dbg_init_flag == KAL_FALSE){
		 dbg_uart_init();
		 dbg_init_flag = KAL_TRUE;
	}

	va_start (ap, fmt);
	for(p= fmt; *p; p++)
	{
		if (*p != '%')
		{
			*bp++= *p;
			continue;
		}
		switch (*++p)
		{
			case 'd':
				ival= va_arg(ap, int);
				if (ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				itoa (&bp, ival, 10);
				break;

			case 'o':
				ival= va_arg(ap, int);
				if (ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				*bp++= '0';
				itoa (&bp, ival, 8);
				break;

			case 'x':
				ival= va_arg(ap, int);
				if(ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				*bp++= '0';
				*bp++= 'x';
				itoa (&bp, ival, 16);
				break;

			case 'X':
				ival= va_arg(ap, int);
				bp += sprintf(bp, "0x%x", ival);
				break;

			case 'c':
				cval= va_arg(ap, int);
				*bp++= cval;
				break;

			case 'f':
				dval= va_arg(ap, double);
				if(dval < 0)
				{
					*bp++= '-';
					dval= -dval;
				}
				if(dval >= 1.0)
					itoa (&bp, (int)dval, 10);
				else
					*bp++= '0';
				*bp++= '.';
				fract= (int)((dval- (double)(int)dval)*(double)(MAXFRACT));
				itof(&bp, fract);
				break;

			case 's':
				for(sval = va_arg(ap, char *) ; *sval ; sval++ )
					*bp++= *sval;
				break;
		}
	}
	*bp= 0;
	len = (unsigned short)(bp - print_buf);
	

	for(i = 0; i < len; i++)
	{
		dbg_UARTPutByte(print_buf[i]);		
	}
	
	va_end (ap);
#endif

}

char print_buf2[MAXCHARS];
void dbg_printWithTime(char *fmt,...)
{
#if !defined(__LTE_REMOVE_TEMPERAL__)

#if (!defined(IC_MODULE_TEST))
	int i;
	va_list ap;
	double dval;
	int ival;
	char *p, *sval;
	char *bp, cval;
	int fract;
	unsigned short len;

	char print_buf[MAXCHARS];
	bp= print_buf;
	*bp= 0;
	if(dbg_init_flag == KAL_FALSE){
		 dbg_uart_init();
		 dbg_init_flag = KAL_TRUE;
	}

	va_start (ap, fmt);
	for(p= fmt; *p; p++)
	{
		if (*p != '%')
		{
			*bp++= *p;
			continue;
		}
		switch (*++p)
		{
			case 'd':
				ival= va_arg(ap, int);
				if (ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				itoa (&bp, ival, 10);
				break;

			case 'o':
				ival= va_arg(ap, int);
				if (ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				*bp++= '0';
				itoa (&bp, ival, 8);
				break;

			case 'x':
				ival= va_arg(ap, int);
				if(ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				*bp++= '0';
				*bp++= 'x';
				itoa (&bp, ival, 16);
				break;

			case 'X':
				ival= va_arg(ap, int);
				bp += sprintf(bp, "0x%x", ival);
				break;

			case 'c':
				cval= va_arg(ap, int);
				*bp++= cval;
				break;

			case 'f':
				dval= va_arg(ap, double);
				if(dval < 0)
				{
					*bp++= '-';
					dval= -dval;
				}
				if(dval >= 1.0)
					itoa (&bp, (int)dval, 10);
				else
					*bp++= '0';
				*bp++= '.';
				fract= (int)((dval- (double)(int)dval)*(double)(MAXFRACT));
				itof(&bp, fract);
				break;

			case 's':
				for(sval = va_arg(ap, char *) ; *sval ; sval++ )
					*bp++= *sval;
				break;
		}
	}
	*bp= 0;
	len = (unsigned short)(bp - print_buf);
	

	for(i = 0; i < len; i++)
	{
		dbg_UARTPutByte(print_buf[i]);		
	}
	
	va_end (ap);

#endif
#endif /* !defined(__LTE_REMOVE_TEMPERAL__) */

}

void dbg_flush(void)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

void itof(char **buf, int i)
{
	char *s;
#define LEN	20
	int rem, j;
	static char rev[LEN+1];

	rev[LEN] = 0;
	s = &rev[LEN];
	for (j= 0 ; j < NumFract ; j++)
		{
		rem = i % 10;
			*--s = rem + '0';
		i /= 10;
		}
	while (*s)
		{
		(*buf)[0] = *s++;
		++(*buf);
		}
}

static void itoa(char **buf, int i, int base)
{
	char *s;
#define LEN	20
	int rem;
	static char rev[LEN+1];

	rev[LEN] = 0;
	if (i == 0)
		{
		(*buf)[0] = '0';
		++(*buf);
		return;
		}
	s = &rev[LEN];
	while (i)
		{
		rem = i % base;
		if (rem < 10)
			*--s = rem + '0';
		else if (base == 16)
			*--s = "abcdef"[rem - 10];
		i /= base;
		}
	while (*s)
		{
		(*buf)[0] = *s++;
		++(*buf);
		}
}
#else

void dbg_printWithTime(char *fmt,...){}
void dbg_print(char *fmt,...){}
void dbg_flush(void){}


#if defined(__IC_SLT__)

#define DBG_PRINT_PORT		uart_port1 // Use UART1 as debug port (UART_MD)
#define DBG_PRINT_BAUD		UART_BAUD_115200


extern kal_uint32 UART_BaseAddr[MAX_UART_PORT_NUM];
static kal_bool dbg_init_flag = KAL_FALSE;

extern void U_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid);
static void itoa(char **buf, int i, int base);
static void dbg_uart_init(void); 
static void dbg_UARTPutByte(kal_uint8 data);
void itof(char **buf, int i);

void slt_dbg_flush(void){};

void slt_dbg_print(char *fmt,...)
{
#if 1
	int i;
	va_list ap;
	double dval;
	int ival;
	char *p, *sval;
	char *bp, cval;
	int fract;
	unsigned short len;

	char print_buf[MAXCHARS];
	bp= print_buf;
	*bp= 0;
	if(dbg_init_flag == KAL_FALSE){
		 dbg_uart_init();
		 dbg_init_flag = KAL_TRUE;
	}

	va_start (ap, fmt);
	for(p= fmt; *p; p++)
	{
		if (*p != '%')
		{
			*bp++= *p;
			continue;
		}
		switch (*++p)
		{
			case 'd':
				ival= va_arg(ap, int);
				if (ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				itoa (&bp, ival, 10);
				break;

			case 'o':
				ival= va_arg(ap, int);
				if (ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				*bp++= '0';
				itoa (&bp, ival, 8);
				break;

			case 'x':
				ival= va_arg(ap, int);
				if(ival < 0)
				{
					*bp++= '-';
					ival= -ival;
				}
				*bp++= '0';
				*bp++= 'x';
				itoa (&bp, ival, 16);
				break;

			case 'X':
				ival= va_arg(ap, int);
				bp += sprintf(bp, "0x%x", ival);
				break;

			case 'c':
				cval= va_arg(ap, int);
				*bp++= cval;
				break;

			case 'f':
				dval= va_arg(ap, double);
				if(dval < 0)
				{
					*bp++= '-';
					dval= -dval;
				}
				if(dval >= 1.0)
					itoa (&bp, (int)dval, 10);
				else
					*bp++= '0';
				*bp++= '.';
				fract= (int)((dval- (double)(int)dval)*(double)(MAXFRACT));
				itof(&bp, fract);
				break;

			case 's':
				for(sval = va_arg(ap, char *) ; *sval ; sval++ )
					*bp++= *sval;
				break;
		}
	}
	*bp= 0;
	len = (unsigned short)(bp - print_buf);
	

	for(i = 0; i < len; i++)
	{
		dbg_UARTPutByte(print_buf[i]);		
	}
	
	va_end (ap);
#endif
}

static void dbg_uart_init(void){
	kal_uint32 port = DBG_PRINT_PORT;
	kal_uint32 uart_base = UART_BaseAddr[DBG_PRINT_PORT];
	
	
#if defined(__MTK_TARGET__)
	switch(port){
		case uart_port1: 
			PDN_CLR(PDN_UART0);
			break;
		case uart_port2: 
			PDN_CLR(PDN_UART1);
			break;
#ifdef __UART3_SUPPORT__
		case uart_port3: 
			PDN_CLR(PDN_UART2);
			break;
#endif
		default: break;
	}
#endif

	DRV_WriteReg(UART_IER(uart_base), UART_IER_ALLOFF);
	DRV_WriteReg32(UART_DMA_EN(uart_base), 0x0); //disable DMA
	DRV_WriteReg32(UART_LCR(uart_base), 0xBF);
	DRV_WriteReg32(UART_EFR(uart_base), 0x0);  //no flow control;
	DRV_WriteReg32(UART_LCR(uart_base), 0x03);  //word len = 8 bit;  stop bit =1; parity = false;
	DRV_WriteReg32(UART_FCR(uart_base), 0x05);  //set fifo enable ,and clear Tx and Rx  fifo.
	U_SetBaudRate(DBG_PRINT_PORT, DBG_PRINT_BAUD, (module_type)(DBG_PRINT_PORT));

}

static void dbg_UARTPutByte(kal_uint8 data)
{
   volatile kal_uint16 LSR;
   kal_uint32 uart_base = UART_BaseAddr[DBG_PRINT_PORT];
   while(1)
   {
   	  LSR = DRV_Reg32(UART_LSR(uart_base));
      if((LSR & UART_LSR_THRE))
      {
       	 DRV_WriteReg32(UART_THR(uart_base), data);
         break;
      }
   }
}
void itof(char **buf, int i)
{
	char *s;
#define LEN	20
	int rem, j;
	static char rev[LEN+1];

	rev[LEN] = 0;
	s = &rev[LEN];
	for (j= 0 ; j < NumFract ; j++)
	{
		rem = i % 10;
			*--s = rem + '0';
		i /= 10;
	}
	while (*s)
	{
		(*buf)[0] = *s++;
		++(*buf);
	}
}

static void itoa(char **buf, int i, int base)
{
	char *s;
#define LEN	20
	int rem;
	static char rev[LEN+1];

	rev[LEN] = 0;
	if (i == 0)
	{
		(*buf)[0] = '0';
		++(*buf);
		return;
	}
	s = &rev[LEN];
	while (i)
	{
		rem = i % base;
		if (rem < 10)
			*--s = rem + '0';
		else if (base == 16)
			*--s = "abcdef"[rem - 10];
		i /= base;
	}
	while (*s)
	{
		(*buf)[0] = *s++;
		++(*buf);
	}
}
#endif
#endif
