#include "public.h"

void delay_10us(u16 ten_us)	//@11.0592MHz
{
	while(ten_us--){
	unsigned char data i;

	i = 2;
	while (--i);
	}
}


void Delay10us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 2;
	while (--i);
}

void Delayms(unsigned int ms){
	ms *= 100;
	while(ms--){
		Delay10us();
	}
}


