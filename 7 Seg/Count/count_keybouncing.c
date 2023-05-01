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
int i,count=0;
	
	char number[10] = {0x3F,0x06,0x5B,0x4F,0X66,0x6D,0x7D,0x07,0x7F,0x4F};
	
	RCC->APB2ENR = 1<<2,1<<3;
	GPIOA->CRH = 0x00000000;
	GPIOA->CRL = 0x00000008;

	GPIOB->CRH = 0x22222222;
	GPIOB->CRL = 0x22222222;
	
	
	while(1)
	{
		if(GPIOA->IDR==0x00000001)
		{
			count++;
			GPIOB->ODR=number[count];
			delay(10);
			//while(GPIOA->IDR==0x00000001);
		}
		
	}
}