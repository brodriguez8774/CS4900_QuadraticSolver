# Makefile for Variadic Macro spikes.

LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: default all clean to_console to_file

# Default command if nothing is passed.
default:
	@echo Please specify spike: [ to_console, to_file ]
all: default


# Variadic Macro To console spike.
to_console: variadic_macro_to_console.o
	${CC} -o variadic_macro_to_console.out $^ $(LIBS)
variadic_macro_to_console.o: variadic_macro_to_console.c

# Variadic Macro To file spike.
to_file: variadic_macro_to_file.o
	${CC} -o variadic_macro_to_file.out $^ $(LIBS)
variadic_macro_to_file.o: variadic_macro_to_file.c


# Remove older builds and clear temp files.
clean:
	-rm -f *.o *.out log_file.txt
