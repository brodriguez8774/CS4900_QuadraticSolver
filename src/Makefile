# Makefile for Quad Solver.
# Made from http://stackoverflow.com/questions/1484817/how-do-i-make-a-simple-makefile-for-gcc-on-linux

TARGET = quad_solver
LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: default all clean

# Default command if nothing is passed.
default: $(TARGET)
all: default


# Link given dependencies into binary named TARGET
# $^ will be replaced with 'main.o argparse.o ...'
$(TARGET): main.o argparse.o compute.o my_sqrt.o helper.o prompt.o
	${CC} -o $(TARGET) $^ $(LIBS)

main.o: main.c argparse.h compute.h helper.h prompt.h
argparse.o: argparse.c argparse.h helper.h
compute.o: compute.c compute.h helper.h
my_sqrt.o: my_sqrt.c my_sqrt.h
helper.o: helper.c helper.h
prompt.o: prompt.c prompt.h helper.h


# Remove older builds and clear temp files.
clean:
	-rm -f *.o
	-rm -f $(TARGET)
	-rm -f ./log/*.txt

# Advanced memory usage stats as well as crash reporting.
valgrind: $(TARGET)
	valgrind --leak-check=full --show-reachable=yes ./$(TARGET) -n 2 4 8
