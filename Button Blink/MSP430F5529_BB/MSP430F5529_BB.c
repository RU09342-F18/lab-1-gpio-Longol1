#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P2DIR &= ~BIT1; //Makes the P2.1 button an input
    P2REN |= BIT1; //enables the pull up resistor for the button
    P2OUT |= BIT1; //sets the resistor to be a pull up
    P4DIR |= BIT7;//makes the P4.7 LED an output

    while(1)
    {
        if((P2IN & BIT1) != 0) //P2IN sits at value 0 until pushed. BIT1 is always 1 so when P2IN button is pushed the statement is executed
        {
            P4OUT |= BIT7; //turns the LED on
        }
        else //button is not pushed P2IN value is 0
        {
            P4OUT &= ~BIT7; //turns the LED off
        }
    }
    return 0;
}
