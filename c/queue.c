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

#include <queue.h>
#include <message.h>

message *messages[MAX_MSG_QUEUE];
message messagePool[MAX_MSG_POOL];
int fifoIn, fifoOut, fifoAvl;
//lifo message queue

void initQueue(){
    int a = 0;
    fifoAvl = 0;
    fifoIn = 0;
    fifoOut = 0;

    for( a = 0; a < MAX_MSG_POOL; a++ ){
    	clearMessage( &messagePool[a] );
    	messagePool[a].processed = MSG_PROCESSED;
    }
}

int putMessage( message *msg ){
	//TODO add mutex
	if( fifoAvl == MAX_MSG_QUEUE ){
		return QUEUE_FULL;
	}

	else {
		messages[fifoIn] = msg;
		fifoAvl++;
		fifoIn = ( fifoIn + 1 ) % MAX_MSG_QUEUE;
		return QUEUE_OK;
	}

	return QUEUE_OK;
}

int getMessageQueueStatus(){
	if( fifoAvl == 0 ){
		return QUEUE_EMPTY;
	} else if( fifoAvl == MAX_MSG_QUEUE ){
		return QUEUE_FULL;
	}
	return QUEUE_OK;
}

int getMessage( message **msg ){
	if( fifoAvl == 0 ){
		return QUEUE_EMPTY;
	}
	else {
		*msg = messages[fifoOut];
		fifoOut = ( fifoOut + 1 ) % MAX_MSG_QUEUE;
		fifoAvl--;
	}

	return QUEUE_OK;
}

int getFreeMessage( message **msg ){
	int a = 0;
	for( a = 0; a < MAX_MSG_POOL; a++ ){
		if( messagePool[a].processed == MSG_PROCESSED ){
			clearMessage( &messagePool[a] );
			*msg = &messagePool[a];
			return QUEUE_OK;
		}
	}
	return QUEUE_ERROR;
}

void clearMessage( message *msg ){
	msg->destination = MSG_U_UNDEF;
	msg->source = MSG_U_UNDEF;
	msg->event = MSG_EVT_UNDEF;
	msg->id = MSG_P_UNDEF;
	msg->priority = MSG_P_UNDEF;
	msg->processed = MSG_UNPROCESSED;
}

int getNrOfUnprocMessages(){
	return fifoAvl;
}
