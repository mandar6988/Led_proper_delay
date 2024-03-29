#include <LPC21xx.H> 
# define led 1<<16 // Led is connected to P0.16 
void pll_init()// PLL initialisation
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
void timer0_init(void)// timer0 initialisation
{
    T0TCR = 0x00;  
    T0PR = 59999;        
    T0TCR = 0x02;   
}
void delay(unsigned int counts) //creating delay with timer 
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
	
	IODIR0=led;
	while(1)
	{
	 IOSET0=led;
	 delay(1000);
	 IOCLR0=led;
	 delay(1000);
	 }
}
