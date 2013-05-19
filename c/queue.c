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
#include <events.h>
#include <stddef.h>

#define GET_LOCK		fifoMutex=1
#define RELEASE_LOCK	fifoMutex=0

message *messages[MAX_MSG_QUEUE];
message messagePool[MAX_MSG_POOL];
int fifoIn, fifoOut, fifoAvl;

//I see deadlocks here!!!!
//TODO when locked return;
int fifoMutex;
//fifo message queue

void initQueue(){
    int a = 0;
    fifoAvl = 0;
    fifoIn = 0;
    fifoOut = 0;
    fifoMutex = 0;

    for( a = 0; a < MAX_MSG_POOL; a++ ){
    	clearMessage( &messagePool[a] );
    	messagePool[a].status = processed_status;
    }

}

QUEUE_STATUS putMessage( message *msg ){
	while( fifoMutex != 0 );
	GET_LOCK;
	if( fifoAvl == MAX_MSG_QUEUE ){
		RELEASE_LOCK;
		return queue_full;
	}

	else {
		messages[fifoIn] = msg;
		fifoAvl++;
		fifoIn = ( fifoIn + 1 ) % MAX_MSG_QUEUE;
		RELEASE_LOCK;
		return queue_ok;
	}
	RELEASE_LOCK;
	return queue_ok;
}

QUEUE_STATUS getMessageQueueStatus(){
	if( fifoAvl == 0 ){
		return queue_empty;
	} else if( fifoAvl == MAX_MSG_QUEUE ){
		return queue_full;
	}
	return queue_ok;
}

QUEUE_STATUS getMessage( message **msg ){
	while( fifoMutex != 0 );
	GET_LOCK;
	if( fifoAvl == 0 ){
		RELEASE_LOCK;
		return queue_empty;
	}
	else {
		*msg = messages[fifoOut];
		fifoOut = ( fifoOut + 1 ) % MAX_MSG_QUEUE;
		fifoAvl--;
	}
	RELEASE_LOCK;
	return queue_ok;
}

QUEUE_STATUS getFreeMessage( message **msg ){
	int a = 0;
	while( fifoMutex != 0 );
	GET_LOCK;
	for( a = 0; a < MAX_MSG_POOL; a++ ){
		if( ( messagePool[a].status == processed_status ) && ( messagePool[a].dependents == 0 ) ){
			clearMessage( &messagePool[a] );
			*msg = &messagePool[a];
			RELEASE_LOCK;
			return queue_ok;
		}
	}
	RELEASE_LOCK;
	return queue_error;
}

void clearMessage( message *msg ){
	msg->destination = undef_user;
	msg->source = undef_user;
	msg->event = undef_event;
	msg->id = MSG_ID_UNDEF;
	msg->priority = undef_priority;
	msg->status = unprocessed_status;
	msg->dependency = NULL;
	msg->dependents = 0;
}

int getNrOfUnprocMessages(){
	return fifoAvl;
}
