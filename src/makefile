# Made from http://stackoverflow.com/questions/1484817/how-do-i-make-a-simple-makefile-for-gcc-on-linux

TARGET = quad_solver
LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g

.PHONY: default all clean

default: $(TARGET)
all: default

# Link given dependencies into binary named TARGET
# $^ will be replaced with 'main.o argparse.o ...'
$(TARGET): main.o argparse.o compute.o helper.o prompt.o
	${CC} -o $(TARGET) $^ $(LIBS)

main.o: main.c argparse.h compute.h helper.h prompt.h

argparse.o: argparse.c argparse.h helper.h

compute.o: compute.c compute.h helper.h

helper.o: helper.c helper.h

prompt.o: prompt.c prompt.h helper.h

clean:
	-rm -f *.o
	-rm -f $(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-reachable=yes ./$(TARGET) -n 2 4 8

unit_tests : unit_tests.c argparse.o compute.o helper.o prompt.o
	${CC} -o unit_tests $^ $(LIBS) -lcunit

test: unit_tests
	valgrind --leak-check=full --show-reachable=yes ./unit_tests
