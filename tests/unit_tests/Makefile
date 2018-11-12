# Makefile for Unit Tests

LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g
SRC_DIR = ../../src
CUNIT_DIR = ../cunit

.PHONY: default all clean test_unit_all

default: test_unit_all
all: default

test_unit_all: test_my_sqrt.out
	./test_my_sqrt.out

test_my_sqrt.out: my_sqrt.o test_my_sqrt.o mock_sqrt.o cunit.o
	${CC} -o $@ $^ $(LIBS) -Wl,--wrap=sqrt

my_sqrt.o: $(SRC_DIR)/my_sqrt.c $(SRC_DIR)/my_sqrt.h
	${CC} -c -o $@ $< ${CFLAGS}

test_my_sqrt.o: test_my_sqrt.c mock_sqrt.h

mock_sqrt.o: mock_sqrt.c

cunit.o: $(CUNIT_DIR)/cunit.c $(CUNIT_DIR)/cunit.h
	${CC} -c -o $@ $< ${CFLAGS}

clean:
	-rm -f *.o *.out
