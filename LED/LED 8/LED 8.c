#include<stm32f10x.h>

void delay(int x)
{
	while(x--);
}

void main()
{
	RCC->APB2ENR = 1<<4;  
		
	GPIOC->CRL = 0X02020202;
	GPIOC->CRH = 0X20202020; 	//13th bit cuz we have an inbuilt LED there

	
	while(1)
	{
		
		delay(5000);
		GPIOC->ODR = 1<<15 | 1<<13 | 1<<11 | 1<<9 | 1<<7 | 1<<5 | 1<<3 | 1<<1;
		delay(5000);
		GPIOC->BRR = 1<<15 | 1<<13 | 1<<11 | 1<<9 | 1<<7 | 1<<5 | 1<<3 | 1<<1;
		delay(5000);
		GPIOC->ODR = 1<<14 | 1<<12 | 1<<10 | 1<<8 | 1<<6 | 1<<4 | 1<<2 | 1<<0;
		delay(5000);
		GPIOC->BRR = 1<<14 | 1<<12 | 1<<10 | 1<<8 | 1<<6 | 1<<4 | 1<<2 | 1<<0;
		delay(5000);
		
		//Output Data register
			
	}
	

	
	
}