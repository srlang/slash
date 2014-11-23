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
	const char * name;
	const char * description;
	StatusCode (* function) (void * args);
} slash_command_t;


// Command functions
StatusCode echo(void * args);
StatusCode external(void * args);
StatusCode dos(void * args);

// Command objects
slash_command_t ECHO = {
	.name = "echo",
	.description = "print stuff to the console",
	.function = echo
};

slash_command_t EXTERNAL = {
	.name = "external",
	.description = "call an external program",
	.function = external
};

slash_command_t DOS = {
	.name = "dos",
	.description = "why?",
	.function = dos
};

slash_command_t command_table[3] = {
	ECHO,
	DOS,
	EXTERNAL,
};

#endif /*_COMMAND_H*/
