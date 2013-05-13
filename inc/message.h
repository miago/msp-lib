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

//Message queue priority
#define MSG_P_0         0 //Highest
#define MSG_P_1         1 //Normal
#define MSG_P_3         2 //Low
#define MSG_P_4         3 //Lowest
#define MSG_P_5         4 //Whatever
#define MSG_P_6         5 //only if you want
#define MSG_P_UNDEF     6

#define MSG_UNPROCESSED 0
#define MSG_PROCESSED   1
#define MSG_INTERRUPTED 2

#define MSG_U_UNDEF		0
#define MSG_EVT_UNDEF	0
#define MSG_ID_UNDEF	0


typedef struct{
        int source;
        int destination;
        int priority;
        int id;
        int event;
        int processed;
        unsigned char *argument;
} message;

#endif
