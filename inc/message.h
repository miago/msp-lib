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

#ifndef __MESSAGE_H__
#define __MESSAGE_H__


//Message queue users
#define MSG_U_UART      0 
#define MSG_U_LED       1
#define MSG_U_BUTTON    2
#define MSG_U_MAIN      3

//Message queue events
#define MSG_EVT_ON      0
#define MSG_EVT_OFF     1
#define MSG_EVT_UNDEF   2
#define MSG_EVT_TOGGLE  3

//Message queue priority
#define MSG_P_0         0 //Highest
#define MSG_P_1         1 //Normal
#define MSG_P_3         2 //Low
#define MSG_P_4         3 //Lowest


typedef struct{
        char source;
        char destination;
        char priority;
        char event;
}message;

#endif