#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P4SEL &= ~BIT0; //setting the Pin 4 select to 0 because the functions are not sued
	P4DIR |= BIT7; //this is setting Pin4.7 LED to an output

	while(1) //infinite while loop
	{
	    P4OUT ^= BIT7; //XOR P4OUT with bit7 just toggles the pin 4.7 LED on and off
	    __delay_cycles(25000); //the cycle speed
	}

	return 0;
}
