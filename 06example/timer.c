#include <STC89C5xRC.H>
#include "timer.h"
#include "smg.h"

static volatile unsigned long g_millis = 0;

unsigned long millis(void)
{
	return g_millis;
}

void Timer0_Isr(void) interrupt 1
{
	static int i=0;
	i++;
	g_millis++;
	//smg_show();
	if(i>=500){
		i=0;
		P20=!P20;
	}
	TL0 = 0x66;
	TH0 = 0xFC;
}

void Timer0_Init(void)
{
	AUXR &= 0x7F;
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TL0 = 0x66;
	TH0 = 0xFC;
	TF0 = 0;
	TR0 = 1;
	ET0 = 1;
}


