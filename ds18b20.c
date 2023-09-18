#include <p18cxxx.h>
#include <delays.h>
#include "k18.h"
#include "ds18b20.h"

void reset_ds18b20(void) //复位
{
	unsigned int i;
	DQ_LOW();
	Delay100TCYx(48);
	DQ_HIGH();
}

unsigned char ack_ds18b20(void) //等待应答
{
	unsigned char Value = 1;
	DQ_HIGH();
	while(DQ == 1);
	while(DQ == 0) Value = 0;
	
	Delay10TCYx(20);
	if(Value) return 0;
	return 1;
}

unsigned int read_ds18b20(void) //读取
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

void write_ds18b20(unsigned int ku) //写入指令
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

unsigned int get_temp(void) //读取温度
{   
     int i;
     unsigned int tp,flag;
     flag = 1;
     reset_ds18b20();//复位
     ack_ds18b20();//从机应答
     write_ds18b20(SkipROM);//忽略ROM匹配
     write_ds18b20(B20Convert);//发送温度转化命令
     reset_ds18b20();//复位
     ack_ds18b20();//从机应答
     write_ds18b20(SkipROM);//忽略ROM匹配
     write_ds18b20(B20ReadScr);//发送读温度命令
     Delay10TCYx(150);/*150us*/ 
     tp = read_ds18b20();/*读出温度*/ 
            
     if(tp>0x0fff) /*判断是否为负温，若是负温，取反加一，乘6.25*/
     {      
            tp =~ tp;
            tp++;
            tp = (unsigned int)(tp*6.25);
            tp |= 0xC000;
     }
     else
           tp = (unsigned int)(tp*6.25);/*是正温*/
           
     return (tp);
}