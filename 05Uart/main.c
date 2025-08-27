#include <STC89C5xRC.H>

#include "public.h"
#include "smg.h"
#include "key.h"
#include "interrupt.h"
#include "timer.h"
#include "uart.h"


void main(){
	unsigned long num = 00000000;
	u8 key=0;
	smg_num(num);
	P20=1;
	
	
	Ext_Init();
	Timer0_Init();
	//Timer1_Init();
	
	Uart1_Init();
	EA = 1;//×ÜÖÐ¶Ï
	while(1){
		//smg_show();
		
		
		key = key_scan();
		if(key == 1){
			P20=!P20;
		}
	}
}