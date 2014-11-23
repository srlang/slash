/*
 * command.c
 *
 * Copyright (c) 2014 - Sean R. Lang
 */

#include "command.h"

slash_command_t ECHO = {
	.name = "echo",
	.description = "print stuff to the console",
	.function = echo
};
