#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1SEL &= ~BIT0; //sets the P1SEL to 0 because the functions from that multiplexer are not needed
	P1SEL2 &= ~BIT0; //sets the P1SEL2 to 0 because the functions from that multiplexer are not needed
	P1DIR |= BIT6; //This sets the LED at Pin 1.6 to 1 which means it is an output

	while(1) //infinite loop
	{
	    P1OUT ^= BIT6; //XOR P1OUT with BIT6 toggles the LED at Pin 1.6 on and off
	    __delay_cycles(25000); //cycle speed
	}

	return 0;
}
