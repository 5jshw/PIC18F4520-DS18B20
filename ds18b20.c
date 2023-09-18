#include <p18cxxx.h>
#include <delays.h>
#include "k18.h"
#include "ds18b20.h"

void reset_ds18b20(void) //��λ
{
	unsigned int i;
	DQ_LOW();
	Delay100TCYx(48);
	DQ_HIGH();
}

unsigned char ack_ds18b20(void) //�ȴ�Ӧ��
{
	unsigned char Value = 1;
	DQ_HIGH();
	while(DQ == 1);
	while(DQ == 0) Value = 0;
	
	Delay10TCYx(20);
	if(Value) return 0;
	return 1;
}

unsigned int read_ds18b20(void) //��ȡ
{
	int i = 0;
	unsigned int u = 0;
	
	for (i = 0;i < 16; i++)
	{
		DQ_LOW();
		Delay10TCYx(2);
		u >>= 1;
		DQ_HIGH();
		Delay10TCYx(5);
		if(DQ) u |= 0X8000;
		Delay10TCYx(56);
	}
	return (u);
}

void write_ds18b20(unsigned int ku) //д��ָ��
{
	int i =0;
	for (i = 0;i < 8;i++)
	{
		DQ_LOW();
		Delay10TCYx(2);
		DQ = ku & 0X01;
		Delay10TCYx(50);
		DQ_HIGH();
		Delay10TCYx(2);
		ku >>= 1;
	}
}

unsigned int get_temp(void) //��ȡ�¶�
{   
     int i;
     unsigned int tp,flag;
     flag = 1;
     reset_ds18b20();//��λ
     ack_ds18b20();//�ӻ�Ӧ��
     write_ds18b20(SkipROM);//����ROMƥ��
     write_ds18b20(B20Convert);//�����¶�ת������
     reset_ds18b20();//��λ
     ack_ds18b20();//�ӻ�Ӧ��
     write_ds18b20(SkipROM);//����ROMƥ��
     write_ds18b20(B20ReadScr);//���Ͷ��¶�����
     Delay10TCYx(150);/*150us*/ 
     tp = read_ds18b20();/*�����¶�*/ 
            
     if(tp>0x0fff) /*�ж��Ƿ�Ϊ���£����Ǹ��£�ȡ����һ����6.25*/
     {      
            tp =~ tp;
            tp++;
            tp = (unsigned int)(tp*6.25);
            tp |= 0xC000;
     }
     else
           tp = (unsigned int)(tp*6.25);/*������*/
           
     return (tp);
}