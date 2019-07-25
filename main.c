#include <LPC21xx.H> 

void pll_init()// initialise PLL function
{
 PLLCON = 0x01;  
 PLLCFG = 0x24;  
 PLLFEED = 0xAA;  
 PLLFEED = 0x55;
 
 while(!(PLLSTAT & 1<<10));
 
 PLLCON = 0x03;   
 PLLFEED = 0xAA;  
 PLLFEED = 0x55;
 VPBDIV = 0x01; 
}
void timer0_init(void)// timer initialisation
{
   	T0TCR = 0x00;  
    T0PR = 59999;  
            
    T0TCR = 0x02;   
}
void delay(unsigned int counts) //Creating daleay of Timer0
{
    T0TCR = 0x02;       
    T0TCR = 0x01;       
   
    while(T0TC < counts);
   
    T0TCR = 0x00;       
	T0TC=0x00;
}

int main()
{
pll_init();
timer0_init()
	
	IODIR0=0xFFFFFFFF;
	while(1)
	{
	 IOSET0=0xFFFFFFFF;// Set all pins of port 0
	 delay(1000);
	 IOCLR0=0xFFFFFFFF;// Clear all pins of port 0
	 delay(1000);
	 }
}
