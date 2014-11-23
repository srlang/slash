/*
 * command.h
 *
 * Copyright (c) 2014 - Sean R. Lang
 */

#ifndef _COMMAND_H
#define _COMMAND_H

#include "return_code.h"

#define SLASH_MAX_COMMAND_NUM			20

typedef struct slash_command {
	char * name;
	char * description;
	StatusCode (* function) (void * args);
} slash_command_t;

slash_command_t command_table[SLASH_MAX_COMMAND_NUM];

StatusCode echo(void * args);

#endif /*_COMMAND_H*/
