#include <msp430.h> 


/**
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;           // Disable the GPIO power-on default high-impedance mode
    P1DIR |= 0x01;                  // configure P1.0 as output
    P1REN |= 0x02;                  // Enabling connect of a resistor to P5.5
    P1OUT |= 0X02;                  // Initializes LED to on, sets the P1.3 Resistor to a pull up resistor

    volatile unsigned int i;        // volatile to prevent optimization

    while(1)
    {
        while(P1IN & BIT1)//While button is High, turn off LED
        {
            P1OUT &= ~BIT0;
        }
        P1OUT |= 0x01;              // toggle P1.0
    }
}
