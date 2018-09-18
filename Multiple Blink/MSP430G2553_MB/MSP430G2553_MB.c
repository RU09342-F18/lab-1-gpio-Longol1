#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1SEL &= BIT0; //P1SEL is turned off because functions are not needed
	P1SEL2 &= BIT0; //P1SEL2 is turned off because functions are not needed
	P1DIR |= (BIT0 | BIT6); // P1.0 and 1.6 are both going to be used as outputs

	int i1; //counter 1
	int i2; //counter 2

	while(1) //infinite loop
	{
	    if(i1 > 20000) //when counter gets to 20000 it will run the statement
	    {
	        P1OUT ^= BIT0; //P1.0 LED is getting toggled on and off
	        i1 = 0; //resets the counter back to 0
	    }
	    if(i2 > 5000) //when counter gets to 5000 it will run the statement
	    {
	        P1OUT ^= BIT6; //P1.6 LED is getting toggled on and off
	        i2 = 0; //resets the counter back to 0
	    }

	    i1++; //increments the counter
	    i2++; //increments the counter
	}
	return 0;
}
