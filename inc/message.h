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

#include <users.h>

//Message queue priority

typedef enum{
	highest_priority	= 0,
	high_priority 		= 1,
	normal_priority		= 2,
	low_priority		= 3,
	lowest_priority		= 4,
	undef_priority		= 5
} MESSAGE_PRIORITY;

typedef enum{
	unprocessed_status	= 0,
	processed_status	= 1,
	interrupted_status	= 2,
	undefinded_status	= 3
} MESSAGE_STATUS;

#define MSG_ID_UNDEF	0

struct message_el {
        MESSAGE_Q_USERS source;
        MESSAGE_Q_USERS destination;
        MESSAGE_PRIORITY priority;
        int id;
        int event;
        MESSAGE_STATUS status;
        struct message_el *dependency;
        int dependents;
        unsigned char *argument;
};

typedef struct message_el message;

#endif
