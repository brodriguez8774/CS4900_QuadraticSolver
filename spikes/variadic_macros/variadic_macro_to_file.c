/**
 * CS 4900
 * Variadic Macro to Log spike.
 */


/**
 * Description:
 *  Spike to test creating macros with dynamic number of passed args. Saves to log file.
 */


// Import headers.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variadic_macro_to_file.h"


/**
 * Program's main.
 * Initializes and runs program.
 */
int main(int argc, char* argv[]) {
    va_log("%s\n", "Hello world!");
    va_log("%s %s\n", "Hello", "world!");
    va_log("%s %d %d\n", "Nov", 20, 2018);
    exit(0);
}
