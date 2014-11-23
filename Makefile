#
# Copyright (c) 2014 - Sean R. Lang
#

CC = gcc
CFLAGS = --std=c99 -Wall

.PHONY: all clean


all: shell

shell: shell.o command.o
	${CC} ${CFLAGS} -o shell shell.c

shell.o: shell.c shell.h return_code.h debug.h
	${CC} ${CFLAGS} -c -o shell.o shell.c

command.o: command.h command.c debug.h
	${CC} ${CFLAGS} -c -o command.o command.c

clean:
	@rm -v *.o
	@rm -v shell
