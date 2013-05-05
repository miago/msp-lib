#ifndef __TIMER_A__
#define __TIMER_A__

//prototypes

void setTimerA0Mode( char mode );
void setTimerA0Top( void );
void setTimerA0ClockSource( char source );
void setTimerA0Divider( char divider );
void resetTimerA0Counter( void );
void enableTimerA0CCInterrupt( void );
void disableTimerA0CCInterrupt( void );


//Timer mode
 
#define TAMODE_STOP	0
#define TAMODE_UP	1
#define TAMODE_CONT	2
#define TAMODE_UP_DW	3
#define TAMODE_UNDEF	4
 
#define TA_TACLK	0
#define TA_ACLK		1
#define TA_SMCLK	2
#define TA_INCLK	3
#define TA_UNDEF	4

#define TA_DIV_1	0
#define TA_DIV_2	1
#define TA_DIV_4	2
#define TA_DIV_8	3
#define TA_DIV_UNDEF	4

#endif
