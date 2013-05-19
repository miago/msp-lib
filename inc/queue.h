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

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <message.h>

#define MAX_MSG_QUEUE	10
#define MAX_MSG_POOL	10

typedef enum{
	queue_ok,
	queue_full,
	queue_empty,
	queue_error
} QUEUE_STATUS;

void initQueue();

QUEUE_STATUS putMessage( message *msg );

QUEUE_STATUS getMessage( message **msg );

QUEUE_STATUS getFreeMessage( message **msg );

QUEUE_STATUS getMessageQueueStatus();

void clearMessage( message *msg );

int getNrOfUnprocMessages();

#endif

