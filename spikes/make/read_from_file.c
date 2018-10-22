/**
 * CS 4900
 * Make read from file spike.
 */


/**
 * Description:
 *  Spike to test using make to automatically read input from a file.
 *  This file is mostly copied from the input_handling/std_in spike.
 */


// Import headers.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


#define BUFFER_SIZE 1024

/**
 * Program's main.
 * Initializes and runs program.
 */
int main(int argc, char* argv[]) {
    int index;
    char* input_buffer;     // Buffer to hold user input.
    char* buffer_position;  // Position in input buffer.
    char* input_string;     // Instance of a full line of user input.
    off_t read_value;       // Number of characters initially read in.

    input_buffer = calloc(1, BUFFER_SIZE+1);

    // Read input from console.
    // Uses buffer in case multiple lines are read in at once.
    write(1, "Enter input: ", 14);
    read_value = read(0, input_buffer, BUFFER_SIZE);
    if (read_value < 0) {
        fprintf(stderr, "Failed to read line.\n");
    }

    // Iterate through buffer of input, until null terminator (\0) is found.
    // For each end of line (\n), pause read in and handle current input.
    buffer_position = input_buffer;
    while (*buffer_position != '\0') {
        index = 0;
        input_string = calloc(1, BUFFER_SIZE+1);

        // Parse until end of line found.
        while (*buffer_position != '\n') {
            // Prevent segmentation fault if line longer than BUFFER_SIZE
            if (index < BUFFER_SIZE) {
                input_string[index] = *buffer_position;
            }
            ++buffer_position;
            index++;
        }
        if (index >= BUFFER_SIZE) {
            fprintf(stderr, "Warning line was stripped because it was too long.\n");
        }
        ++buffer_position;

        printf("Input: %s\n", input_string);
        free(input_string);
    }
    free(input_buffer);

    exit(0);
}
