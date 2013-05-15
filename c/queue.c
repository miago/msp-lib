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
int queuePointer;
//lifo message queue

void initQueue(){
    int a = 0;
	queuePointer = 0;

    for( a = 0; a < MAX_MSG_POOL; a++ ){
    	clearMessage( &messagePool[a] );
    	messagePool[a].processed = MSG_PROCESSED;
    }
}

int putMessage( message *msg ){
	//TODO add mutex
	if( queuePointer == ( MAX_MSG_QUEUE - 1 )){
		return QUEUE_FULL;
	}
	else {
		messages[queuePointer] = msg;
		queuePointer++;
	}

	return QUEUE_OK;
}

int getMessage( message **msg ){
	if( queuePointer == 0 ){
		return QUEUE_EMPTY;
	}
	else {
		queuePointer--;
		*msg = messages[queuePointer];
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

int getQueuePointer(){
	return queuePointer;
}

int getNrOfUnprocMessages(){
	int a;
	int b = 0;
	for( a = 0; a < MAX_MSG_POOL; a++ ){
		if( messagePool[a].processed == MSG_UNPROCESSED ){
			b++;
		}
	}

	return b;
}
