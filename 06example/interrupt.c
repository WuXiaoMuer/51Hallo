#include <STC89C5xRC.H>
#include "interrupt.h"

void INT0_Isr(void) interrupt 0
{
	P20 = 1;
}

void INT1_Isr(void) interrupt 2
{
	P20 = 0;
}

void Ext_Init(void)
{
	IT0 = 1;
	EX0 = 1;

	IT1 = 1;
	EX1 = 1;
}


