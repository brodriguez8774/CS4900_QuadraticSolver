TARGET = float 
LIBS = -lm
CC = gcc
CFLAGS = -Wall -pedantic -std=gnu99 -g

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

# Remove older builds
clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)

# Update time of modification
touch:
	touch *.h
	touch *.c

# Advanced memory usage stats as well as crash reporting
valgrind: $(TARGET)
	valgrind --leak-check=full --show-reachable=yes ./$(TARGET)

# Debug
debug:
	gdb $(TARGET)

# Run compiled code
test:
	./$(TARGET) 123456.78