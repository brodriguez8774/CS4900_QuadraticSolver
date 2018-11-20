/**
 * CS 4900
 * Header file for Variadic Macro to Console spike.
 */


// Import headers.
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Function Prototypes.
void va_printf_func (const char *source_file_name,
                    int source_line_num,
                    const char *source_format_string,
                    ...);


// Macro definition.
#define va_printf(source_format_string, ...) \
    va_printf_func (__FILE__, __LINE__, source_format_string, __VA_ARGS__)


/**
 * Function called by va_printf macro. Used for printing output of unknown length args.
 * Notes:
 *  * It seems to just segfault if you use a bad/wrong format string specifier.
 *      Unlike normal printf, it will not give detailed warnings/errors about such.
 *  * Due to how va_list and va_start work, calling macro needs at least one variable defined.
 *      This variable is where the __VA_ARGS__ call will start looking for new args to handle.
 */
void va_printf_func(const char *source_file_name,
                    int source_line_num,
                    const char *source_format_string,
                    ...) {
    // Create initial formatted string, with default formatting.
    char* format_string = calloc(1024, sizeof(char*));
    sprintf(format_string, "[%s %d] %s", source_file_name, source_line_num, source_format_string);

    // Handle variable length arg input.
    va_list va_arglist;
    va_start(va_arglist, source_format_string);

    // Print to console.
    vprintf(format_string, va_arglist);

    // Clean up.
    va_end(va_arglist);
    free(format_string);
}
