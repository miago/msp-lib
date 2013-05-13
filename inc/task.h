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

#ifndef __TASK_H__
#define __TASK_H__

#include <message.h>
#define TASK_MAX        10

#define TASK_OK         0
#define TASK_FULL       1

#define TASK_EXECUTED   0
#define TASK_404        1

typedef struct{
	unsigned char *cmdName;
	int user;
	void (*handler)(message *);
}task;

int registerTask( task *tsk );
int sendMessage( message *msg );
task* getTaskByCmdName( unsigned char * commandName, int length );

#endif
