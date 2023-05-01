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
	
	int i;
	char number[10] = {0x3F,0x06,0x5B,0x4F,0X66,0x6D,0x7D,0x07,0x7F,0x4F};
	
	RCC->APB2ENR = 1<<2;			//PORTA
	
	GPIOA->CRH = 0x22222222; // all are outputs
	GPIOA->CRL = 0x22222222;
	
	
	while(1)
	{
	
		for(i=0;i<=9;i++)
		{
		GPIOA->ODR=number[i];
		delay(10);
		}
		
	}
}