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

#include <scheduler.h>
#include <task.h>
#include <queue.h>
#include <stddef.h>

int schedulerRunning;

void initScheduler(){
	schedulerRunning = 0;
}

void scheduler(){
	//get message queue element
	message *sMessage;
	message *auxMessage;

	//Mutex
	if( schedulerRunning == 1 ){
		return;
	}
	schedulerRunning = 1;

	while( getMessage( &sMessage ) != queue_empty ){
		//check if dependencies are met
		if( sMessage->dependency != NULL ){
			auxMessage = sMessage->dependency;
			//sMessage->dependency = sMessage;
			if( auxMessage->status != processed_status ){
				putMessage( sMessage );
				return;
			}
			auxMessage->dependents--;
		}
		sendMessage( sMessage );
	}
	schedulerRunning = 0;
}
