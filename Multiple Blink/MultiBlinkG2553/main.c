#include <msp430.h>


/**
 * blink.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= 0x41;                  // configure P1.0  and P1.6 as output
    P1OUT |= 0x01;                  // configure P1.0 as output


    while(1) {
               volatile unsigned int counter;            // volatile to prevent optimization

               if(counter%500 == 0)        // blinks every 500 counts
                       {
                           P1OUT ^= BIT6;              // toggle P1.6
                       }
                       if(counter%2000 == 0)       // Blinks every 2000 counts
                       {
                           P1OUT ^= BIT0;          //toggle P1.0
                           counter = 0;            // restart counter to prevent overflow
                       }
                       counter++;
        }
}
