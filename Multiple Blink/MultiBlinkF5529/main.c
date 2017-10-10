#include <msp430.h> 


/**
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= 0x01;                  // configure P1.0 as output
    P4DIR |= 0x80;                  // configure P4.7 as output
    P1OUT = 0x00;                   // Set to 0
    P4OUT = 0X00;                   // Set to 0
    unsigned int counter;

    while(1)
    {
        if(counter%500 == 0)        // blinks every 500 counts
        {
            P1OUT ^= 0x01;              // toggle P1.0
        }
        if(counter%2000 == 0)       // Blinks every 2000 counts
        {
            P4OUT ^= 0x80;          //toggle P4.7
            counter = 0;            // restart counter to prevent overflow
        }
        counter++;
    }
}
