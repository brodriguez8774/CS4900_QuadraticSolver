# Makefile for Logging spikes.

LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: default all clean log_with_function log_with_macro

# Default command if nothing is passed.
default:
	@echo Please specify spike: [ log_with_function, log_with_macro ]
all: default


# Log with function spike.
log_with_function: log_with_function.o
	${CC} -o log_with_function.out $^ $(LIBS)
log_with_function.o: log_with_function.c

# Log with macro spike.
log_with_macro: log_with_macro.o
	${CC} -o log_with_macro.out $^ $(LIBS)
log_with_macro.o: log_with_macro.c


# Remove older builds and clear temp files.
clean:
	-rm -f *.o *.out log_file.txt
