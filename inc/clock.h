#ifndef __CLOCK_H__
#define __CLOCK_H__


//prototypes

void setACLK( int source, int divider );
void setMCLK( int source, int divider );
void setSMCLK( int source, int divider );
void setDCOCLK( char freq );
void disableDCO( void );
void disableWDT( void );




//DCO Options

#define DCO_16M 	0
#define DCO_12M 	1
#define DCO_8M  	2
#define DCO_1M  	3
#define DCO_DIS 	4
#define DCO_UNDEF	5

//ACKL Options
#define ACLK_VLO	0
#define ACLK_LFXT1	1
#define ACLK_UNDEF	2

//MCLK Options
#define MCLK_DCO	0
#define MCLK_LFTX1	1
#define MCLK_VLO	2
#define MCLK_UNDEF	3

//SMCLK Options
#define SMCLK_DCO	0
#define SMCLK_LFTX1	1
#define SMCLK_VLO	2
#define SMCLK_UNDEF	3

//Dividers
#define CLK_DIV_1	0
#define CLK_DIV_2	1
#define CLK_DIV_4	2
#define CLK_DIV_8	3
#define CLK_DIV_UNDEF	4

#endif
