#include <STC89C5xRC.H>
#include "uart.h"

void uart1_send_char(char c)
{
	TI = 0;
	SBUF = c;
	while (!TI);
	TI = 0;
}

void Uart1_Isr(void) interrupt 4
{
	if (RI)
	{
		unsigned char c=SBUF;
		uart1_send_char(c);
		RI = 0;
	}
}

void Uart1_Init(void)	//9600bps@11.0592MHz
{
	PCON &= 0x7F;
	SCON = 0x50;
	AUXR &= 0xBF;
	AUXR &= 0xFE;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TL1 = 0xFD;
	TH1 = 0xFD;
	ET1 = 0;
	TR1 = 1;
	ES = 1;
}


