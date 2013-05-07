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

message *messages[MAX_QUEUE];
int queuePointer;
//lifo message queue

void initQueue(){
        queuePointer = 0;
}

char putMessage( message *msg ){
        if(queuePointer == ( MAX_QUEUE - 1 )){
                return QUEUE_FULL;
        }
        else {
                messages[queuePointer] = msg;
                queuePointer++;
        }
        
        return QUEUE_OK;
}

char getMessage( message *msg ){
        if( queuePointer == 0 ){
                return QUEUE_EMPTY;
        }
        else {
                queuePointer--;
                msg = messages[queuePointer];
        }
        
        return QUEUE_OK;
}