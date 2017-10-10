

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x01;                          // Set P1.0 to output direction
    P2DIR |= 0x01;                          // Set P2.0 to output direction

    P1OUT |= 0x01;                          // Turn on P1.0
    P2OUT |= 0x01;                          // Turn on P2.0
       while(1) {
           volatile unsigned int counter;            // volatile to prevent optimization

           if(counter%500 == 0)                     // blinks every 500 counts
                   {
                       P1OUT ^= BIT1;              // toggle P1.1
                   }
                   if(counter%2000 == 0)       // Blinks every 2000 counts
                   {
                       P2OUT ^= BIT1;          //toggle P2.1
                       counter = 0;            // restart counter to prevent overflow
                   }
                   counter++;

    }
}
