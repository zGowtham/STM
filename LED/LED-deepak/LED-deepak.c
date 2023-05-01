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
GPIOA->CRL = 0X00008822;
	
while(1)
{
if(GPIOA->IDR==1<<3)
{
GPIOA->ODR = 1<<1;
}

if(GPIOA->IDR==0X0000000E) // E is used in the first digit because we are dealing with the first PORT
{
GPIOA->BRR = 1<<1;
}



}

}