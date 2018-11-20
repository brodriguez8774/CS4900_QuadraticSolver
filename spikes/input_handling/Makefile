# Makefile for Input Handling spikes.

LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g
SRC_DIR = ../../src


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: default all clean arg_parse simple_parse std_in

# Default command if nothing is passed.
default:
	@echo Please specify spike: [ arg_parse, simple_parse, std_in ]
all: default


# Arg parse spike.
arg_parse: spike_arg_parse.o src_arg_parse.o helper.o prompt.o
	${CC} -o arg_parse.out $^ $(LIBS)
spike_arg_parse.o: arg_parse.c
	${CC} -c -o $@ $< ${CFLAGS}
src_arg_parse.o: $(SRC_DIR)/argparse.c
	${CC} -c -o $@ $< ${CFLAGS}
helper.o: $(SRC_DIR)/helper.c
	${CC} -c -o $@ $< ${CFLAGS}
prompt.o: $(SRC_DIR)/prompt.c
	${CC} -c -o $@ $< ${CFLAGS}

# Simple parse spike.
simple_parse: simple_parse.o
	${CC} -o simple_parse.out $^ $(LIBS)
simple_parse.o: simple_parse.c

# Std in spike.
std_in: std_in.o
	${CC} -o std_in.out $^ $(LIBS)
std_in.o: std_in.c


# Remove older builds and clear temp files.
clean:
	-rm -f *.o *.out
