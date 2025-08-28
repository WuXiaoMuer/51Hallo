#include <STC89C5xRC.H>

#include "public.h"
#include "smg.h"
#include "key.h"
#include "interrupt.h"
#include "timer.h"
#include "buzzer.h"
#include "lcd1602.h"
#include "ds18b20.h"

static u8 u8_strlen(const char *s){
    u8 n=0; while(s && *s){ n++; s++; if(n==255) break; } return n;
}

static void lcd_print_center(u8 y, const char *str){
    u8 len = u8_strlen(str);
    u8 x = 0;
    if(len < 16) x = (16 - len) / 2;
    lcd1602_show_string(x, y, (u8*)str);
}

static void anim_progress(unsigned int step_ms){
    u8 i;
    char bar[17];
    for(i=0;i<16;i++) bar[i]=' ';
    bar[16]='\0';
    lcd_print_center(0, "Initializing..");
    for(i=0;i<=16;i++){
        u8 k; for(k=0;k<i;k++) bar[k]=(char)0xFF;
        for(k=i;k<16;k++) bar[k]=' ';
        lcd1602_show_string(0,1,(u8*)bar);
        Delayms(step_ms);
    }
}

void main(){
	unsigned long num = 0;
	u8 key=0;
	P20=1;
	buzzer_set(0);
	
	
	Ext_Init();
	Timer0_Init();
	EA = 1;//总中断

	// Progress bar only, then show DS18B20 temperature
	smg_enable(0);
	lcd1602_init();
	//lcd1602_clear();
	anim_progress(20);
	{
		u8 ok;
		float tf=0.0;
		ok = ds18b20_init();
		if(ok==0){
			ds18b20_start();
			
			tf = ds18b20_read_temperture();
		}
		{
			char line[17];
			int tx10;
			char sign;
			unsigned int v,i,d;
			lcd1602_clear();
			lcd_print_center(0, (ok==0)?"Temperature":"Sensor Error");
			if(ok==0){
				// format float to one decimal without printf
				tx10 = (tf>=0)? (int)(tf*10.0+0.5) : (int)(tf*10.0-0.5);
				sign = (tx10<0)?'-':'+';
				v = (tx10<0)?-tx10:tx10;
				i = v/10; d = v%10;
				line[0]=sign;
				line[1]=(char)('0'+(i/10)%10);
				line[2]=(char)('0'+(i%10));
				line[3]='.';
				line[4]=(char)('0'+d);
				line[5]='C';
				line[6]='\0';
				lcd_print_center(1, line);
			}
		}
	}

	// SMG boot animation disabled temporarily per request
	while(1){
		key = key_scan();
		if(key == 1){
			// K1: example toggle P20
			P20=!P20;
		}else if(key == 2){
			// K2: increment displayed number as demo
			num = (num + 1) % 100000000UL;
			smg_num(num);
		}else if(key == 3){
			// K3: reset number
			num = 0;
			smg_num(num);
		}else if(key == 4){
			// K4: toggle passive buzzer (software square wave)
			buzzer_toggle();
		}
		buzzer_update();
	}
}