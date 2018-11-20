# Makefile for Integration Tests.

SRC_DIR = ../../src


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: default all clean test_int_all quad_solver

# Default command if nothing is passed.
default: test_int_all
all: default


# Run quad solver makefile found in src folder.
quad_solver:
	make -C $(SRC_DIR)

test_int_all: quad_solver
	./test_ranges.sh $(SRC_DIR)
	./test_examples.sh $(SRC_DIR)


# Remove older builds and clear temp files (Does nothing for now).
clean:
	rm -f *.tmp
