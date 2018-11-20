# Makefile for Unit Tests

.PHONY: default all clean test

default: test
all: default

test:
	make -C unit_tests
	make -C integration_tests

clean:
	make -C unit_tests clean
	make -C integration_tests clean
