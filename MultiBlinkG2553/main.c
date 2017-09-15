#include <msp430.h>


/**
 * blink.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= 0x41;                  // configure P1.0 as output
    P1OUT |= 0x01;

    volatile unsigned int i;        // volatile to prevent optimization

    while(1)
    {
        P1OUT ^= 0x41;              // toggle P1.0
        for(i=100000; i>0; i--);  // delay
        P1OUT ^= 0x40;
        for(i=100000; i>0; i--);  // delay
    }
}
