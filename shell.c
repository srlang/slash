/* 
 * shell.c
 *
 * Copyright (C) 2014 Sean R. Lang
 */

#include <stdio.h>
#include <stdlib.h>

#include "shell.h"
#include "return_code.h"


slash_command_t command_table[SLASH_MAX_COMMAND_NUM];


unsigned short int num_commands = 0;
// commentline
ReturnCode add_new_shell_command(char * name, char * desc, 
									ReturnCode (*function)(void * args)) {
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

ReturnCode init_shell() {
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

ReturnCode slash_execute(slash_command_t * cmd, void * args) {
	if (!cmd) {
		return SLASH_ERROR;
	}
	return cmd->function(args);
}

ReturnCode shell_main() {
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
