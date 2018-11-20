# Makefile for Unit Tests.

LIBS = -lm -lcunit
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g
SRC_DIR = ../../src
CUNIT_DIR = ../cunit


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: default all clean test_unit_all

# Default command if nothing is passed.
default: test_unit_all
all: default


# Run all unit tests.
test_unit_all: test_my_sqrt.out unit_tests.out
	./test_my_sqrt.out
	./unit_tests.out

# Mini Cunit Library tests.
test_my_sqrt.out: my_sqrt.o test_my_sqrt.o mock_sqrt.o cunit.o
	${CC} -o $@ $^ $(LIBS) -Wl,--wrap=sqrt
my_sqrt.o: $(SRC_DIR)/my_sqrt.c $(SRC_DIR)/my_sqrt.h
	${CC} -c -o $@ $< ${CFLAGS}
test_my_sqrt.o: test_my_sqrt.c mock_sqrt.h
mock_sqrt.o: mock_sqrt.c
cunit.o: $(CUNIT_DIR)/cunit.c $(CUNIT_DIR)/cunit.h
	${CC} -c -o $@ $< ${CFLAGS}

# Cunit Library tests.
unit_tests.out : unit_tests.o $(SRC_DIR)/argparse.o $(SRC_DIR)/compute.o $(SRC_DIR)/my_sqrt.o $(SRC_DIR)/helper.o $(SRC_DIR)/prompt.o
	${CC} -o unit_tests.out $^ $(LIBS)
unit_tests.o: unit_tests.c


# Remove older builds and clear temp files.
clean:
	-rm -f *.o *.out
