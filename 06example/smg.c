#include <STC89C5xRC.H>
#include "public.h"
#include "smg.h"

static unsigned char smg_code[11] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x00};
static unsigned char smg_buff[8] = {10,10,10,10,10,10,10,10};
static unsigned char smg_idx = 0; // current digit index 0..7
static unsigned char smg_on = 1;

void smg_show(void){
	if(!smg_on){ P0 = 0x00; return; }
	P0 = 0x00;

	// select current digit via P22/P23/P24 (assumed 3-to-8 decoder)
	switch(smg_idx){
		case 0: P22 = 1;P23 = 1;P24 = 1;break;
		case 1: P22 = 0;P23 = 1;P24 = 1;break;
		case 2: P22 = 1;P23 = 0;P24 = 1;break;
		case 3: P22 = 0;P23 = 0;P24 = 1;break;
		case 4: P22 = 1;P23 = 1;P24 = 0;break;
		case 5: P22 = 0;P23 = 1;P24 = 0;break;
		case 6: P22 = 1;P23 = 0;P24 = 0;break;
		case 7: P22 = 0;P23 = 0;P24 = 0;break;
	}
	P0 = smg_code[smg_buff[smg_idx]];

	// next digit for next interrupt
	smg_idx++;
	if(smg_idx >= 8) smg_idx = 0;
}

void smg_enable(unsigned char on){
	smg_on = on ? 1 : 0;
	if(!smg_on){ P0 = 0x00; }
}

void smg_num(unsigned long num){
	int i=0;
	for(i=7;i>=0;i--){
		smg_buff[i] = num%10;
		num /= 10;
	}
}

void smg_fill(u8 digit){
	int i;
	if(digit>9) digit = 10;
	for(i=0;i<8;i++){
		smg_buff[i] = digit;
	}
}


