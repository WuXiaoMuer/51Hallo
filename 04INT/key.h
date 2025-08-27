u8 key_scan(void){
	static u8 key=1;
	if(key==1 && (P31 == 0)){
		Delayms(20);
		key=0;
		if(P31 == 0) return 1;
	}else if(P31 == 1 ){
		key=1;
	}
	return 0;
}