#include<stm32f10x.h>

void delay(int x)
{
	while(x--);
}

void main()
{
	RCC->APB2ENR = 1<<4;  //4 because we are using PORTC in decimal system.   // //pg.146 for APB2ENR
	
	// APB2ENR -> Enable register, APB2
	// if you are also using PORTB 
	//	RCC->APB2ENR = 1<<4||1<<3; 3 because PORTB is 3;
	
	
	
	//Reset and clock control
	//Timer, I2C and UART are in APB1 ->36MHz
	//GPIO, few timers APB2-72MHz
	
	
	GPIOC->CRL = 0X00000000;
	GPIOC->CRH = 0X00200000; 	//13th bit cuz we have an inbuilt LED there
	
	//GPIOC->CRH = 1<<21;
	
	//pg 171
	
	//CNFy Output mode
	// GPIO - general purpose
	//TImer, UART, I2C - alternate function
	
	
	while(1)
	{
	
		GPIOC->ODR = 1<<13;
		delay(1000);
		
		//Output Data register
		
		GPIOC->BRR = 1<<13;
		delay(1000);
		
		//Bit reset register
	
	}
	
	/*
	
		while(1)
	{
	
		GPIOC->BSRR = 1<<13;
		delay(1000);
		
		GPIOC->BSRR = 1<<29;
		delay(1000);
	}
	
	*/
	
	
}