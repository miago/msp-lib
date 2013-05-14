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

#include <task.h>
#include <string.h>

task *tasks[TASK_MAX];

int taskCounter = 0;
int match = 0;

int registerTask( task *tsk ){

	if( taskCounter == ( TASK_MAX-1 ) ){
		return TASK_FULL;
	}
	else {
		tasks[taskCounter] = tsk;
		taskCounter++;
	}

	return TASK_OK;
}

int sendMessage( message *msg ){
	int id = msg->destination;
	int id_task = 0;
	int a = 0;

	for( a = 0; a < taskCounter; a++ ){
		id_task = tasks[a]->user;
		if( id_task == id ){
			match++;
			//found a matching task
			tasks[a]->handler( msg );
			return TASK_EXECUTED;
		}
	}
	return TASK_404;
}

task* getTaskByCmdName( unsigned char * commandName, int length ){
	int a = 0;

	for( a = 0; a < taskCounter; a++ ){
		if( strncmp( ( const char * ) commandName, ( const char * ) tasks[a]->cmdName, length ) == 0 ){
			return tasks[a];
		}
	}

	return NULL;
}
