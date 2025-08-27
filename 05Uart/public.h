
typedef unsigned char u8;

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