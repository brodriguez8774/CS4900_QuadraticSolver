/**
 * CS 4900
 * Header file for Variadic Macro to Log spike.
 */


// Import headers.
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Function Prototypes.
void va_log_func (const char *source_file_name,
                    int source_line_num,
                    const char *source_format_string,
                    ...);


// Macro definition.
#define va_log(source_format_string, ...) \
    va_log_func (__FILE__, __LINE__, source_format_string, __VA_ARGS__)


/**
 * Function called by va_printf macro. Used for printing output of unknown length args.
 * Notes:
 *  * It seems to just segfault if you use a bad/wrong format string specifier.
 *      Unlike normal printf, it will not give detailed warnings/errors about such.
 *  * Due to how va_list and va_start work, calling macro needs at least one variable defined.
 *      This variable is where the __VA_ARGS__ call will start looking for new args to handle.
 */
void va_log_func(const char *source_file_name,
                    int source_line_num,
                    const char *source_format_string,
                    ...) {

    // Get time info.
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    // Create initial formatted string, with default formatting.
    char* format_string = calloc(1024, sizeof(char*));
    sprintf(format_string, "[%d-%d-%d %d:%d:%d] %s %d: %s",
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
        source_file_name, source_line_num, source_format_string
    );

    // Handle variable length arg input.
    va_list va_arglist;
    va_start(va_arglist, source_format_string);

    // Save to log file.
    FILE* log_file;
    log_file = fopen("log_file.txt", "a+");
    vfprintf(log_file, format_string, va_arglist);

    // Clean up.
    fclose(log_file);
    va_end(va_arglist);
    free(format_string);
}
