void uart1_send_char(char c)
{
		TI = 0;
    SBUF = c;
    while (!TI);        // 等待发送完成
		TI = 0;
}
void Uart1_Isr(void) interrupt 4
{
	if (RI)				//检测串口1接收中断
	{
		unsigned char c=SBUF;
		uart1_send_char(c);
		P23=!P23;
		RI = 0;			//清除串口1接收中断请求位
	}
}

void Uart1_Init(void)	//9600bps@11.0592MHz
{
//	TMOD|=0X20;	//设置计数器工作方式2
//	SCON=0X50;	//设置为工作方式1
//	PCON=0X80;	//波特率加倍
//	TH1=0XFA;	//计数器初始值设置
//	TL1=0XFA;
//	ES=1;		//打开接收中断
//	TR1=1;		//打开计数器		
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	AUXR &= 0xBF;		//定时器时钟12T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFD;			//设置定时初始值
	TH1 = 0xFD;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
	ES = 1;				//使能串口1中断
}

