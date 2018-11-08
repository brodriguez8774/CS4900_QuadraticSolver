# Makefile for Unit Tests

LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g
SRC_DIR = ../../src
WRAPPED = -Wl,--wrap=sqrt

.PHONY: default all clean test_unit_all

default: test_unit_all
all: default

test_unit_all: test_my_sqrt.out
	./test_my_sqrt.out

test_my_sqrt.out: my_sqrt.o test_my_sqrt.o mock_sqrt.o
	${CC} -o $@ $^ $(LIBS) $(WRAPPED)

my_sqrt.o: $(SRC_DIR)/my_sqrt.c $(SRC_DIR)/my_sqrt.h
	${CC} -c -o $@ $< ${CFLAGS}

test_my_sqrt.o: test_my_sqrt.c

mock_sqrt.o: mock_sqrt.c

clean:
	-rm -f *.o *.out
