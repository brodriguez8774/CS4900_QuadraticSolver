# Makefile for Make spikes.

LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: default all clean read_from_file

# Default command if nothing is passed.
default: read_from_file
all: default


# Read from file spike.
read_from_file: read_from_file.o
	${CC} -o read_from_file.out $^ $(LIBS)
	make read
read_from_file.o: read_from_file.c

read:
	./read_from_file.out < input.txt


# Remove older builds and clear temp files.
clean:
	-rm -f *.o *.out



