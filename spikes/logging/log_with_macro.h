/**
 * CS 4900
 * Header file for Logging with Macro spike.
 */


/**
 * Description:
 *  Header file to hold logging macro.
 */


// Import headers.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/**
 * Macro to log to file.
 */
#define log_info(log_text) { \
    FILE* log_file; \
    time_t rawtime; \
    struct tm * timeinfo; \
\
    time ( &rawtime ); \
    timeinfo = localtime ( &rawtime ); \
\
    log_file = fopen("log_file.txt", "w+"); \
    fprintf(log_file, "[%d-%d-%d %d:%d:%d] %s %d (%s): %s\n", \
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, \
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
        __FILE__, __LINE__, __func__, log_text \
    ); \
    fclose(log_file); \
}
