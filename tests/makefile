# Makefile for Unit Tests

LIBS = -lm -lcunit
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g
SRC_DIR = ../src
WRAPPED = -Wl,--wrap=sqrt

.PHONY: default all clean run_tests

default: test
all: default

test: unit_tests.out
	./unit_tests.out

unit_tests.out : unit_tests.o $(SRC_DIR)/argparse.o $(SRC_DIR)/compute.o $(SRC_DIR)/my_sqrt.o $(SRC_DIR)/helper.o $(SRC_DIR)/prompt.o
	${CC} -o unit_tests.out $^ $(LIBS)

unit_tests.o: unit_tests.c

clean:
	-rm -f *.o *.out
