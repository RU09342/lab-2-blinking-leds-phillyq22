#include <msp430.h> 


/**
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= 0x01;                  // configure P1.0 as output
    P1REN |= 0x08;                  // Enabling connect of a resistor to P1.3
    P1OUT |= 0X09;                  // Initializes LED to on, sets the P1.3 Resistor to a pull up resistor

    volatile unsigned int i;        // volatile to prevent optimization

    while(1)
    {
        while(P1IN & BIT3)
        {
            P1OUT &= ~BIT0;
        }
        P1OUT |= 0x01;              // toggle P1.0
    }
}
