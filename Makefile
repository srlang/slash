#
# Copyright (c) 2014 - Sean R. Lang
#

CC = gcc
CFLAGS = --std=c99 -Wall -Werror

.PHONY: all


all: shell

shell: shell.o
	${CC} ${CFLAGS} -o shell shell.c

shell.o: shell.c shell.h return_code.h
	${CC} ${CFLAGS} -c -o shell.o shell.c
