# Made from http://stackoverflow.com/questions/1484817/how-do-i-make-a-simple-makefile-for-gcc-on-linux

TARGET = quad_solver
LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g

.PHONY: default all clean

default: $(TARGET)
all: default

# Expect a .o for each .c file in the directory
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
# Get all .h files in the directory
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-reachable=yes ./$(TARGET)
