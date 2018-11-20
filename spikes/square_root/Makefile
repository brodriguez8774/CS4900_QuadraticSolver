# Makefile for Square Root spikes.

TARGET = sqrt
LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=gnu99 -g


# Ensure that commands run as intended, even if file with same name exists.
.PHONY: default all clean

# Default command if nothing is passed.
default: $(TARGET)
all: default


# Expect a .o for each .c file in the directory.
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
# Get all .h files in the directory.
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@


# Remove older builds and clear temp files.
clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)

# Update time of modification.
touch:
	touch *.h
	touch *.c

# Advanced memory usage stats as well as crash reporting.
valgrind: $(TARGET)
	valgrind --leak-check=full --show-reachable=yes ./$(TARGET)

# Debug.
debug:
	gdb $(TARGET)

# Run compiled code.
test:
	./$(TARGET) 123456.78
