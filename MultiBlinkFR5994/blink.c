//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  Texas Instruments, Inc
//  July 2013
//***************************************************************************************

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x03;                          // Set P1.0 and P1.1 to output direction
    P1OUT |= 0x02;                          // Turn on P1.1
       while(1) {
           volatile unsigned int i;            // volatile to prevent optimization

           P1OUT ^= 0x03;                      // Toggle P1.0 and P1.1 using exclusive-OR
           for(i = 20000; i != 0; i--);  //Delay
           P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR
           for(i = 20000; i != 0; i--);  //Delay

    }
}
