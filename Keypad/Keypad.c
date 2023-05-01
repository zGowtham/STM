#include<stm32f10x.h>

void delay(unsigned int time_delay)
{
for(;time_delay>0;time_delay--)
	{
	  int j=65000;
		while(j--);
	}
}

void value(int a, int b, int c, int d)
{
if(GPIOA->IDR == 1<<3)
GPIOB->ODR = a;

if(GPIOA->IDR == 1<<2)
GPIOB->ODR = b;
	
if(GPIOA->IDR == 1<<1)
GPIOB->ODR = c;
	
if(GPIOA->IDR == 1<<0)
GPIOB->ODR = d;	
}


int main()
{

	RCC->APB2ENR = 1<<2|1<<3|1<<4;
	
	GPIOA->CRH = 0x00000000;
	GPIOA->CRL = 0X00008888;
	
	GPIOB->CRH = 0x00000000;
	GPIOB->CRL = 0X22222222;
	
	GPIOC->CRH = 0x22200000;
	GPIOC->CRL = 0X00000000;
	
	while(1)
	{
	
		GPIOC->ODR = 1<<13;
		GPIOC->BRR = 1<<14;
		GPIOC->BRR = 1<<15;
		
		if((GPIOA->IDR == 1<<3) || (GPIOA->IDR == 1<<2) || (GPIOA->IDR == 1<<1) || (GPIOA->IDR == 1<<0))
		{
		value(0x31,0x34,0x37,0x2A);
		while((GPIOA->IDR == 1<<3) || (GPIOA->IDR == 1<<2) || (GPIOA->IDR == 1<<1) || (GPIOA->IDR == 1<<0));
		}
		
		GPIOC->BRR = 1<<13;
		GPIOC->ODR = 1<<14;
		GPIOC->BRR = 1<<15;
		
		if((GPIOA->IDR == 1<<3) || (GPIOA->IDR == 1<<2) || (GPIOA->IDR == 1<<1) || (GPIOA->IDR == 1<<0))
		{
		value(0x32,0x35,0x38,0x30);
		while((GPIOA->IDR == 1<<3) || (GPIOA->IDR == 1<<2) || (GPIOA->IDR == 1<<1) || (GPIOA->IDR == 1<<0));
		}
		
		GPIOC->BRR = 1<<13;
		GPIOC->BRR = 1<<14;
		GPIOC->ODR = 1<<15;
		
		if((GPIOA->IDR == 1<<3) || (GPIOA->IDR == 1<<2) || (GPIOA->IDR == 1<<1) || (GPIOA->IDR == 1<<0))
		{
		value(0x33,0x36,0x39,0x23);
		while((GPIOA->IDR == 1<<3) || (GPIOA->IDR == 1<<2) || (GPIOA->IDR == 1<<1) || (GPIOA->IDR == 1<<0));
		}
		
	}
	

}