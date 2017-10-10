#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x01;                          // Set P1.0 to output direction
    volatile unsigned int i;            // volatile to prevent optimization

    while(1) {

        P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR
        for(i = 10000;i != 0;i--);          // sw delay
    }
}
