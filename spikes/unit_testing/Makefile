# Makefile for Unit Testing spikes.

LIBS = -lm -lcunit
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: default all clean unit_tests

# Default command if nothing is passed.
default: unit_tests
all: default


# Unit test spike.
unit_tests: unit_tests.o dummy_functions.o
	${CC} -o unit_tests.out $^ $(LIBS)
unit_tests.o: unit_tests.c
dummy_functions.o: dummy_functions.c


# Remove older builds and clear temp files.
clean:
	-rm -f *.o *.out
