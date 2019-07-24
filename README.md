# Led_proper_delay
LED interfacing with LPC 2148 with accurate delay


This project contains main.c file
Main.c contains following information



Purpose of this project is to initialise all ports of LPC2148 and to understanghow the timer works 
File consist of following main function

pll_init: used to initialise PLL with CCLK=PCLK=60MHZ




timer0_init: timer 0 initialisation


main: main code to run program


#In addition to this three more file are added:
main_led1.c
main_led_4.c
main_led_8.c

These three file contins embedded c code to interface single led to pin 16,four led to pin 16-19,eigth led to pin 16-23.


All these files having delay of 1 second.Means these leds will on and off after 1second.

