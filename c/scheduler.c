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

int schedPass = 0;

void initScheduler(){
        
}

void scheduler(){
        //get message queue element
        message *sMessage;
        
        int error;
        int u_source;
        
        error = getMessage( sMessage );
        
        u_source = sMessage->source;

        
        if( error == QUEUE_OK ){
                //task received
                schedPass++;
                sendMessage( sMessage );
        } else{
                
        }
        
}