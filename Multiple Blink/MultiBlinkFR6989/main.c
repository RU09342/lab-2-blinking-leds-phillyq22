#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

    P1DIR |= 0x01;	// enable P1.0
	P9DIR |= 0x80;  //enable P9.7

	P1OUT = 0;//set to 0
	P9OUT = 0;//set to 0

	unsigned int counter;

	while(1)
	{
	    if(counter % 500 == 0)//flip P1.0 every 500 counts
	    {
	        P1OUT ^= 0x01;
	    }
	    if(counter % 2000 == 0)//Flip P9.7 every 2000 counts
	    {
	        P9OUT ^= 0x80;
	        counter = 0;//set counter to 0 to prevent overflow
	    }
	    counter++;
	}
	
}
