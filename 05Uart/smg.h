unsigned char smg_code[11]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x00};


unsigned char smg_buff[8]={10,10,10,10,10,10,10,10};//0-9

void smg_show(void){
	int i = 0;
	for(i=0; i<8; i++){
		switch(i){
			case 0: P22 = 1;P23 = 1;P24 = 1;break;
			case 1: P22 = 0;P23 = 1;P24 = 1;break;
			case 2: P22 = 1;P23 = 0;P24 = 1;break;
			case 3: P22 = 0;P23 = 0;P24 = 1;break;
			case 4: P22 = 1;P23 = 1;P24 = 0;break;
			case 5: P22 = 0;P23 = 1;P24 = 0;break;
			case 6: P22 = 1;P23 = 0;P24 = 0;break;
			case 7: P22 = 0;P23 = 0;P24 = 0;break;
		}
		P0 = smg_code[smg_buff[i]];
		Delay10us();
		P0 = 0x00;
	}
}
void smg_num(unsigned long num){
	int i=0;
	for(i=7;i>=0;i--){
		smg_buff[i] = num%10;
		num /= 10;
	}
}