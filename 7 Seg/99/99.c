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
	
	int i,j;
	char number[10] = {0x3F,0x06,0x5B,0x4F,0X66,0x6D,0x7D,0x07,0x7F,0x4F};
	
	RCC->APB2ENR = 1<<2 | 1<<3 | 1<<4;
  
	GPIOA->CRH = 0X22222222;
	GPIOA->CRL = 0X22222222;
	GPIOB->CRH = 0X22222222;
	GPIOB->CRL = 0X22222222;
	
	GPIOC->CRH = 0X88000000;
	GPIOC->CRL = 0X00000000;
	
	while(1)
	{
	
	if(GPIOC->IDR == 1<<14)   //IDR->input
	{
		for(i=0;i<10;i++)
		{
		GPIOB->ODR = number[i];
		delay(10);
				
				for(j=0;j<10; j++)
				{
				GPIOA->ODR = number[j];
				delay(10);
				}
		}
		
	}

	
	if(GPIOC->IDR == 1<<15)
	{
		for(i=9;i>=0;i--)
		{
		GPIOB->ODR = number[i];
		delay(10);
				
				for(j=9;j>=0;j--)
				{
				GPIOA->ODR = number[j];
				delay(10);
				}
		}
		
	}
	
	}
}
