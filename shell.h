/*
 * shell.h
 *
 * Copyright (c) 2014 - Sean R. Lang
 */

#ifndef _SHELL_H
#define _SHELL_H

#define SLASH_MAX_COMMAND_NUM			20
#define SLASH_MAX_INPUT_STRING_LENGTH	80

#define SLASH_PROMPT	"SLASH > "

typedef struct slash_command {
	char * name;
	char * description;
	ReturnCode (* function) (void *);
} slash_command_t;

#endif /*_SHELL_H*/
