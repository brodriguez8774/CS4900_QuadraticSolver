/**
 * CS 4900
 * Variadic Macro spike.
 */


/**
 * Description:
 *  Spike to test creating macros with dynamic number of passed args.
 */


// Import headers.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variadic_macro.h"



/**
 * Program's main.
 * Initializes and runs program.
 */
int main(int argc, char* argv[]) {
    va_printf("%s\n", "Hello world!");
    va_printf("%s %s\n", "Hello", "world!");
    va_printf("%s %d %d\n", "Nov", 20, 2018);
    exit(0);
}
