/*
 * shell.h
 *
 * Copyright (c) 2014 - Sean R. Lang
 */

#ifndef _SHELL_H
#define _SHELL_H

#include "return_code.h"
#include "command.h"

#define SLASH_MAX_INPUT_STRING_LENGTH	80

#define SLASH_PROMPT	"SLASH > "


StatusCode shell_main();
StatusCode slash_execute(slash_command_t * cmd, void * args);
slash_command_t * extract_slash_command(char * input_str);
void * parse_args(char * input_str);
char * slash_prompt();
StatusCode init_shell();
StatusCode add_new_shell_command(char * name, char * desc,
									StatusCode (*function)(void * args));

#endif /*_SHELL_H*/
