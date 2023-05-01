#include<stm32f10x.h>

void delay(unsigned int time_delay)
{
for(;time_delay>0;time_delay--)
	{
	  int j=65000;
		while(j--);
	}
}


int main()
{

	RCC->APB2ENR = 1<<2;
	
	GPIOA->CRH = 0X00000000;
	GPIOA->CRL = 0X00000028;
	
	while(1)
	{
	if(GPIOA->IDR == 0X00000001)
	{
	GPIOA->ODR = 0x00000038;
	delay(10);
	GPIOA->BRR = 0x00000018;
	delay(10);		
	}
	
	}
}