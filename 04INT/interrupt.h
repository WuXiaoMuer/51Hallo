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
	IT0 = 1;			//INT0(P3.2)?????
	EX0 = 1;			//??INT0??

	IT1 = 1;			//INT1(P3.3)?????
	EX1 = 1;			//??INT1??
}