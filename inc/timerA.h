/*
* This file is part of msp-lib
*
* Copyright (C) 2013 Mirco Gysin <miagox@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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
