#include <p18cxxx.h>
#include "k18.h"
#include "ds18b20.h"

void delay()
{
int i;
for(i = 10000; i--;);
}

void main(void)
{
	int tp;
	int a = 0X0BB8;
	//int b = 0X0006;
	k18_init();
	
	TRIS_COL1 = 0;
	TRIS_COL2 = 0;
	TRIS_COL3 = 0;
	TRIS_COL4 = 0;
	TRIS_COL5 = 0;
	TRIS_COL6 = 0;
	TRIS_COL7 = 0;
	TRIS_COL8 = 0;
	
	COL1 = 1;
	COL2 = 1;
	COL3 = 1;
	COL4 = 1;
	COL5 = 1;
	COL6 = 1;
	COL7 = 1;
	COL8 = 1;
	
	TRISD = 0X00;

	while(1)
	{
		tp = get_temp();
		tp &= 0X3FFF;
		
		if(tp > a) //下半部分的灯
		{
			PORTD = 0X0F;
        	Delay10Ms(10);                                                                                                                                                                      
        	PORTD = 0X00;//0X00
        	Delay10Ms(10);   
  		}
  		else if(tp < (a - 0X64)) //上半部分的灯
  		{
	  		PORTD = 0XF0;
	  		Delay10Ms(10);   
	  		PORTD = 0X00;
	  		Delay10Ms(10);   
  		}
  		else
  		{
  			PORTD = 0X0F;
  			Delay10Ms(10); 
  			PORTD = 0X00;
  			Delay10Ms(10); 
		}
	}
}