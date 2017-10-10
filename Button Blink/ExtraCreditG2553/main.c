#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= 0x41; //Set path output to LED Port 1.0 and LED Port 1.6
	P1REN |= BIT3;  //enable resistor to connect LED and button
	P1OUT |= BIT3;  //Enable button as output
	P1OUT &= ~BIT0; // Start the LED off
	while(1)
	{
	    if(P1IN & BIT3)//If the button is not pressed.
	        {
	            P1OUT &= ~BIT0;//Turn off the RED LED
	            P1OUT |= BIT6;//Turn on the Green LED
	        }
	        else
	        {
                P1OUT &= ~BIT6;//Turn off the Green LED
	            P1OUT |= BIT0;//Turn on the Red LED
	        }
	}
	
}
