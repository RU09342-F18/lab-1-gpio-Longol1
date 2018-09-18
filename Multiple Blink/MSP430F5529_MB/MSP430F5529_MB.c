#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1SEL &= BIT0; //P1SEL is turned off because functions are not needed
    P1DIR |= BIT0; //Pin 1.0 LED is raised to a 1 because it is used as an output
    P4DIR |= BIT7; //Pin 4.7 LED is raised to a 1 because it is used as an output also

    int i1; //counter 1
    int i2; //counter 2

    while(1) //infinite loop
    {

        if(i1 > 25000) //Everytime I1 reaches 25000 the code within the statement will run
        {
            P1OUT ^= BIT0; //P1.0 LED is toggled on and off
            i1 = 0; //resets the counter back to 0 so it can increment back to the desired value
        }
        if(i2 > 10000)//Everytime I2 reaches 25000 the code within the statement will run
        {
            P4OUT ^= BIT7; //P4.7 LED is toggled on and off
            i2 = 0; //resets the counter back to 0 so it can increment back to the desired value
        }
        i1++; //increments the counter i1
        i2++; //increments the counter i2
    }


    return 0;
}
