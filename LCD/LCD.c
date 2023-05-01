#include<stm32f10x.h>

#define RS 1<<14
#define EN 1<<15

void delay(int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<65000;j++);	
}


void pulse()
{
GPIOC->ODR |=EN; //(32-16 is reserved, so, 1st 4 is 0 and 5th pin is 8 because 8421 -> 15 is EN here)
delay(5);
	
GPIOC->BRR |=EN;
delay(5);	
}

void command(char a)
{
	
GPIOA->BRR = 0x000000FF;
	
	
GPIOC->BRR |=RS;
GPIOA->ODR |=(a&0xF0)>>4;
pulse();
	
GPIOA->BRR = 0x000000FF;
	
GPIOC->BRR |=1<<14;
GPIOA->ODR |=(a&0x0F);
pulse();
	
}

void data(char a)
{
	
GPIOA->BRR = 0x000000FF; //
	
GPIOC->ODR |=RS;
GPIOA->ODR |=(a&0xF0)>>4;
pulse();
	
GPIOA->BRR = 0x000000FF;
	
GPIOC->ODR |=RS;
GPIOA->ODR |=(a&0x0F);
pulse();
	
}


/*
void LCD(int a, int b)
{
  GPIOC->ODR = b<<14;   //14th pin is RS | line no. 35
	
	GPIOA->ODR = (a)&(0xf0)>>4;
	pulse();
	GPIOA-> ODR =((a)&(0x0f));
	pulse();	
}

*/


void string(char *ptr)
{
while(*ptr)
{
data(*ptr++);
}
}


int main()
{
	RCC->APB2ENR = 1<<2|1<<4;
	
	GPIOA->CRH = 0x00000000;
	GPIOA->CRL = 0x22222222;
	
	GPIOC->CRH = 0x22000000;
	GPIOC->CRL = 0x00000000;
	
	command(0x02);
	command(0x28); //4 bit
	command(0x0E);
	
	command(0x01);
	while(1)
	{
	command(0x80);
  string("Baddy");
	command(0XC0);
	string("Morning");
	}
		
}
