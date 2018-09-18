#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1SEL &= BIT0; //P1SEL is turned off because the functions are not needed
    P1SEL2 &= BIT0; //P1SEL2 is turned off because the functions are not needed
    P1DIR |= (BIT0 | BIT6); //P1.0 and P1.6 are made outputs

    int i1; //counter 1
    int i2; //counter 2

    while(1)
    {
        if(i1 > 20000) //when counter reaches 20000 the if statement will be executed
        {
            P1OUT ^= BIT0; // P1.0 LED is toggled
            i1 = 0; //counter is set back to 0
        }
        if(i2 > 5000) //when counter reaches 5000 the if statement will be executed
        {
            P1OUT ^= BIT6; //P1.6 LED is toggled
            i2 = 0; //counter is set back to 0
        }

        i1++; //counter is incremented
        i2++;//counter is incremented
    }
    return 0;
}
