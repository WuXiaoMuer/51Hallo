#include <STC89C5xRC.H>
#include "public.h"
#include "key.h"

// Return priority: K1>P31, K2>P30, K3>P32, K4>P33
u8 key_scan(void){
	static u8 p31_prev=1, p30_prev=1, p32_prev=1, p33_prev=1;
	// K1 (P31)
	if(p31_prev==1 && P31==0){
		Delayms(20);
		if(P31==0){ p31_prev=0; return 1; }
	}
	else if(P31==1){ p31_prev=1; }
	// K2 (P30)
	if(p30_prev==1 && P30==0){
		Delayms(20);
		if(P30==0){ p30_prev=0; return 2; }
	}
	else if(P30==1){ p30_prev=1; }
	// K3 (P32)
	if(p32_prev==1 && P32==0){
		Delayms(20);
		if(P32==0){ p32_prev=0; return 3; }
	}
	else if(P32==1){ p32_prev=1; }
	// K4 (P33)
	if(p33_prev==1 && P33==0){
		Delayms(20);
		if(P33==0){ p33_prev=0; return 4; }
	}
	else if(P33==1){ p33_prev=1; }

	return 0;
}


