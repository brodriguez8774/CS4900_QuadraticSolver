# Makefile for Tests.


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: default all clean test

# Default command if nothing is passed.
default: test
all: default


# Run all types of tests.
test:
	make -C unit_tests
	make -C integration_tests


# Remove older builds and clear temp files.
clean:
	make -C unit_tests clean
	make -C integration_tests clean
