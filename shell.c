/* 
 * shell.c
 *
 * Copyright (c) 2014 Sean R. Lang
 *
 *
 * This file will contain the main logic behind the basic userland shell I am
 * attempting to make. This is purely an academic exercise, but the opportunity
 * for expansion--being paramount to a well-engineered software development
 * project--will still be a decent factor in this project.
 */

#include <stdio.h>
#include <stdlib.h>

#include "shell.h"
#include "return_code.h"


/* Set of commands built into the shell. */
slash_command_t command_table[SLASH_MAX_COMMAND_NUM];
/* Index of commands used to keep track of number of commands added */
unsigned short int num_commands = 0;


// commentline
StatusCode add_new_shell_command(char * name, char * desc, 
									StatusCode (*function)(void * args)) {
	if (num_commands + 1 < SLASH_MAX_COMMAND_NUM) {
		command_table[num_commands].name = name;
		command_table[num_commands].description = desc;
		command_table[num_commands].function = function;
		num_commands++;
		return SLASH_SUCCESS;
	} else {
		return SLASH_ERROR;
	}
}

/*
 * Initialize the shell: properties, built-ins, etc.
 * Returns a StatusCode. 
 */
StatusCode init_shell() {
	return SLASH_SUCCESS;
}

char * slash_prompt() {
	return SLASH_PROMPT;
}

void * parse_args(char * input_str) {
	return NULL;
}

slash_command_t * extract_slash_command(char * input_str) {
	return NULL;
}

StatusCode slash_execute(slash_command_t * cmd, void * args) {
	if (!cmd) {
		return SLASH_ERROR;
	}
	return cmd->function(args);
}

StatusCode shell_main() {
	// get input
	char input_string[SLASH_MAX_INPUT_STRING_LENGTH + 1];
	char * prompt = slash_prompt();
	printf("%s", prompt);
	free(prompt);
	fgets(input_string, SLASH_MAX_INPUT_STRING_LENGTH, stdin);

	// parse into worthwhile info
	slash_command_t * command = extract_slash_command(input_string);
	void * args = parse_args(input_string);

	// execute results and return error code
	return slash_execute(command, args);
}

int main(int argc, char * argv[]) {
	return SLASH_SUCCESS;
}
