#include <msp430.h>

#include <clock.h>


//set the Auxiliary Clock
//sourced either from a 32768-Hz watch crystal or the internal LF oscillator.
void setACLK( int source, int divider ){
	//either VLO or LFTX1
	if( source == ACLK_VLO ){
		BCSCTL3 &= ~BIT4;
		BCSCTL3 |= BIT5;
	} else if ( source == ACLK_LFXT1 ){
		BCSCTL3 &= ~( BIT4 + BIT5 );
	}

	if( divider == CLK_DIV_1 ){
		BCSCTL1 &= ~( BIT4 + BIT5 ); 
	} else if ( divider == CLK_DIV_2 ){
		BCSCTL1 &= ~( BIT5 );
		BCSCTL1 |= BIT4;
	} else if ( divider == CLK_DIV_4 ){
		BCSCTL1 &= ~( BIT4 );
		BCSCTL1 |= BIT5;
	} else if ( divider == CLK_DIV_8 ){
		BCSCTL1 |= ( BIT4 + BIT5 );
	}
}

//set the Main System Clock
//the system clock used by the CPU.
void setMCLK( int source, int divider ){
	if( source == MCLK_VLO ){
		//Have to change the ACLK too!
		setACLK( ACLK_VLO, CLK_DIV_UNDEF );
		
		BCSCTL2 |= SELM_3;
	} else if( source == MCLK_LFTX1 ){
		//Have to change the ACLK too!
		setACLK( ACLK_LFXT1, CLK_DIV_UNDEF );
		
		BCSCTL2 |= SELM_3;
	} else if( source == MCLK_DCO ){
		BCSCTL2 &= ~( SELM_0 );
	}
	
	if( divider == CLK_DIV_1 ){
		BCSCTL2 &= ~( BIT4 + BIT5 ); 
	} else if ( divider == CLK_DIV_2 ){
		BCSCTL2 &= ~( BIT5 );
		BCSCTL2 |= BIT4;
	} else if ( divider == CLK_DIV_4 ){
		BCSCTL2 &= ~( BIT4 );
		BCSCTL2 |= BIT5;
	} else if ( divider == CLK_DIV_8 ){
		BCSCTL2 |= ( BIT4 + BIT5 );
	}
}

//set the Sub-Main Clock
//the sub-system clock used by the peripheral modules.
void setSMCLK( int source, int divider ){
	if( source == SMCLK_VLO ){
		//Have to change the ACLK too!
		setACLK( ACLK_VLO, CLK_DIV_UNDEF );
		
		BCSCTL2 |= BIT3;
	} else if( source == SMCLK_LFTX1 ){
		//Have to change the ACLK too!
		setACLK( ACLK_LFXT1, CLK_DIV_UNDEF );
		
		BCSCTL2 |= BIT3;
	} else if( source == SMCLK_DCO ){
		BCSCTL2 &= BIT3;
	}
	
	if( divider == CLK_DIV_1 ){
		BCSCTL2 &= ~( BIT1 + BIT2 ); 
	} else if ( divider == CLK_DIV_2 ){
		BCSCTL2 &= ~( BIT2 );
		BCSCTL2 |= BIT1;
	} else if ( divider == CLK_DIV_4 ){
		BCSCTL2 &= ~( BIT1 );
		BCSCTL2 |= BIT2;
	} else if ( divider == CLK_DIV_8 ){
		BCSCTL2 |= ( BIT1 + BIT2 );
	}
}

//set the Digital Controlled Oscillator
void setDCOCLK( char freq ){

	//DCOCTL  = DCOx * 3 | MODx * 5
	//BCSCTL1 = XT2OFF | XTS | DIVAx * 2 | RSELx * 4
	
	switch( freq ){
	case DCO_1M: 
		DCOCTL = CALDCO_1MHZ;
		BCSCTL1 = CALBC1_1MHZ;
		break;	
	case DCO_8M: 
		DCOCTL = CALDCO_8MHZ;
		BCSCTL1 = CALBC1_8MHZ;
		break;	
	case DCO_12M: 
		DCOCTL = CALDCO_12MHZ;
		BCSCTL1 = CALBC1_8MHZ;
		break;	
	case DCO_16M: 
		DCOCTL = CALDCO_16MHZ;
		BCSCTL1 = CALBC1_16MHZ;
		break;	
	default:
		DCOCTL = CALDCO_1MHZ;
		BCSCTL1 = CALBC1_1MHZ;
	}
}

//disable the DCO
void disableDCO( void ){
	//TODO
}

//disable the watchdog
void disableWDT( void ){
	WDTCTL = WDTPW + WDTHOLD;
}
