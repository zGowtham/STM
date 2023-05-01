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
RCC->APB2ENR = 0x0000000C;
GPIOA->CRL = 0X00000088;
GPIOA->CRH = 0X00000000;
	
GPIOB->CRL = 0X00000022;
GPIOB->CRH = 0X00000000;
	
while(1)
{
	
	if(GPIOA->IDR == 0x000000001)
	{
		GPIOB->ODR = 0x00000001;
	}
	
	if(GPIOA->IDR == 0x000000000)
	{
		GPIOB->BRR = 0x00000001;
	}
	
	
	if(GPIOA->IDR == 0x000000002)
	{
		GPIOB->ODR = 0x00000007;
	}
	
	if(GPIOA->IDR == 0x000000000)
	{
		GPIOB->BRR = 0x00000002;
	}
	/*
	
	if(GPIOA->IDR == 0x00000003)
	{
	GPIOB->ODR = 0x00000003;
	}
	
	*/
}
}
