#include <timerA.h>
#include <msp430.h>

void setTimerA0Mode( char mode ){
	if( mode == TAMODE_STOP ){
		TA0CTL &= ~( BIT5 + BIT4 );
	} else if( mode == TAMODE_UP ){
		TA0CTL &= ~( BIT5 );
		TA0CTL |= BIT4;
	} else if( mode == TAMODE_CONT ){
		TA0CTL &= ~( BIT4 );
		TA0CTL |= BIT5;
	} else if( mode == TAMODE_UP_DW ){
		TA0CTL |= ( BIT4 + BIT5 );
	}
}

void setTimerA0Top(){
	//TODO
}

void setTimerA0ClockSource( char source ){
	if( source == TA_TACLK ){
		TA0CTL &= ~( BIT9 + BIT8 );
	} else if( source == TA_ACLK ){
		TA0CTL &= ~( BIT9 );
		TA0CTL |= BIT8;
	} else if( source == TA_SMCLK ){
		TA0CTL &= ~( BIT8 );
		TA0CTL |= BIT9;
	} else if( source == TA_INCLK ){
		TA0CTL |= ( BIT8 + BIT9 );
	}
}

void setTimerA0Divider( char divider ){
	if( divider == TA_DIV_1 ){
		TA0CTL &= ~( BIT6 + BIT7 );
	} else if ( divider == TA_DIV_2 ){
		TA0CTL &= ~( BIT7 );
		TA0CTL |= BIT6;
	} else if ( divider == TA_DIV_4 ){
		TA0CTL &= ~( BIT6 );
		TA0CTL |= BIT7;
	} else if ( divider == TA_DIV_8 ){
		TA0CTL |= ( BIT6 + BIT7 );
	}
}

void resetTimerA0Counter(){
	//TODO TACLR
}

void enableTimerA0CCInterrupt(){
	TACCTL0 |= BIT4;
}

void disableTimerA0CCInterrupt(){
	TACCTL0 &= ~BIT4;
}
