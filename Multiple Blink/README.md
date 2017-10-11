# Multiple Blink
Philip Quinn: Utilizing modulus and a counter within a while loop, two LEDs can be toggled at different rates that are multiples of each other. For example, within this project modulus of 500 and 2000 are checked. If counter%500 evaluates to 0, then one LED1 is toggled; if counter%2000 evaluates to 0, then another LED2 is toggled and the counter is set to 0 to prevent overflow. In this way, LED1 blinks 4 times as often as LED2.


