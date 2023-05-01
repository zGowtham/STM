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
int i,j,k,l;
	
	RCC->APB2ENR = 1<<2 | 1<<3;
	
	GPIOA->CRH = 0X22222222;
	GPIOA->CRL = 0X22222222;
	GPIOB->CRH = 0X22222222;
	GPIOB->CRL = 0X22222222;
	
	while(1)
	{
	
	for(i=7,j=8; i>0,j<16; i--,j++)	
	{
		
	GPIOA->ODR = 1<<i | 1<<j;
	GPIOB->ODR = 1<<i | 1<<j;
	delay(5);
	}
		
	for(i=7,j=8; i>0,j<16; i--,j++)	
	{		
	GPIOA->BRR = 1<<i | 1<<j;
	GPIOB->BRR = 1<<i | 1<<j;
	delay(5);		
	}
	
	}
	
}