#include <msp430.h>
#include <launchpad.h>

void initLeds( void ){
	LED_DIR |= (LED_0 + LED_1); // Set P1.0 and P1.6 to output direction
	LED_OUT |= (LED_0 + LED_1); // Set the LEDs off
}