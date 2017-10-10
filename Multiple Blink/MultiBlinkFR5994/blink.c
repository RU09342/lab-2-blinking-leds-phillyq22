

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x03;                          // Set P1.0 and P1.1 to output direction
    P1OUT |= 0x02;                          // Turn on P1.1
       while(1) {
           volatile unsigned int counter;            // volatile to prevent optimization

           if(counter%500 == 0)        // blinks every 500 counts
                   {
                       P1OUT ^= BIT0;              // toggle P1.0
                   }
                   if(counter%2000 == 0)       // Blinks every 2000 counts
                   {
                       P4OUT ^= BIT1;          //toggle P1.1
                       counter = 0;            // restart counter to prevent overflow
                   }
                   counter++;
    }
}
