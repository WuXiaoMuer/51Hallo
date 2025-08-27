void uart1_send_char(char c)
{
		TI = 0;
    SBUF = c;
    while (!TI);        // �ȴ��������
		TI = 0;
}
void Uart1_Isr(void) interrupt 4
{
	if (RI)				//��⴮��1�����ж�
	{
		unsigned char c=SBUF;
		uart1_send_char(c);
		P23=!P23;
		RI = 0;			//�������1�����ж�����λ
	}
}

void Uart1_Init(void)	//9600bps@11.0592MHz
{
//	TMOD|=0X20;	//���ü�����������ʽ2
//	SCON=0X50;	//����Ϊ������ʽ1
//	PCON=0X80;	//�����ʼӱ�
//	TH1=0XFA;	//��������ʼֵ����
//	TL1=0XFA;
//	ES=1;		//�򿪽����ж�
//	TR1=1;		//�򿪼�����		
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xFD;			//���ö�ʱ��ʼֵ
	TH1 = 0xFD;			//���ö�ʱ����ֵ
	ET1 = 0;			//��ֹ��ʱ���ж�
	TR1 = 1;			//��ʱ��1��ʼ��ʱ
	ES = 1;				//ʹ�ܴ���1�ж�
}

