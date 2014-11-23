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

#include "debug.h"
#include "shell.h"
#include "command.h"
#include "return_code.h"


/* Set of commands built into the shell. */
extern slash_command_t command_table[SLASH_MAX_COMMAND_NUM];
/* Index of commands used to keep track of number of commands added */
unsigned short int num_commands = 0;


/*
 * Add a new shell command to the list of built-ins. May or may not end up 
 * being useful in the long run, but will be used within shell_init() for
 * command initializations.
 */
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

/* Returns a string prompt for the Slash shell. */
char * slash_prompt() {
	return SLASH_PROMPT;
}

/* Parse the arguments out of the input string to be passed to the command. */
void * parse_args(char * input_str) {
	return NULL;
}

/*
 * Extracts a built-in command from within the input string.
 * Returns the corresponding slash_command_t. If the input string is actually
 * supposed to be a call to an external program, then SLASH_EXTERNAL_CMD is
 * returned instead.
 */
slash_command_t * extract_slash_command(char * input_str) {
	return NULL;
}

/*
 * Execute the command given with the arguments specified. A bit of a special
 * case must be made for external programs, but otherwise this is a fairly
 * common interface point.
 * Returns the StatusCode retrieved as a result of the execution of the command.
 */
StatusCode slash_execute(slash_command_t * cmd, void * args) {
	if (!cmd) {
		return SLASH_ERROR;
	}
	return cmd->function(args);
}

/*
 * Main method to handle the inside of a REPL setup.
 * 	Reads in input.
 * 	Parses into expected format.
 * 	Executes command.
 * 	Retrieves result.
 */
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

/* Main method, need I say much more? */
int main(int argc, char * argv[]) {
	// initializations
	int status = SLASH_SUCCESS;

	// signal handlers TODO(srlang)

	// REPL loop (yes, I know, ATM machine)
	while (1) {
		status = shell_main();
		if (status == SLASH_FATAL) {
			break;
		}
	}
	return status;
}
