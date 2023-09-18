#include <p18cxxx.h>
#include <delays.h>
#include "k18.h"
#include "delay.h"


void Delay10Ms(unsigned char ms)
{
	Delay10KTCYx((((Fosc/4000)*ms)/1000));
}

void DelayMs(unsigned char ms)
{
	Delay1KTCYx((((Fosc/4000)*ms)/1000));
}

void Delay10us(unsigned char us)
{
	Delay10TCYx(((Fosc/1000000)*us));
}