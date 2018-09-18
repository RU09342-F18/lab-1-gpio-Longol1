#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR &= ~BIT3; //This sets P1.3 Button to an input
	P1DIR |= BIT0; //this sets the P1.0 LED to an output
	
	while(1) //infinite loop
	{
	    if((P1IN & BIT3) == 0) //P1IN sits at 1 when not pressed, so when pressed P1In button will lower to 0 and make the statement equal to 0. Executing the statement
	    {
	        P1OUT |= BIT0; //Turns the P1.0 LED to on
	    }
	    else //When P1In isn't pressed it sits at 1
	    {
	        P1OUT &= ~BIT0; //Turns the P1.0 LED off
	    }
	}
	return 0;
}
