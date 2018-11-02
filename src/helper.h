/**
 * CS 4900
 * Header file for misc project helper functions and macros.
 */


// Import headers.
#ifndef _QUAD_SOLVER_CORE_IMPORTS
    #define _QUAD_SOLVER_CORE_IMPORTS
    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
#endif // _QUAD_SOLVER_CORE_IMPORTS


// Constant Defines.
#define MAX_ANSWER_LENGTH 30    // The maximum number of chars used to store the quadratic equation answers.


// Function Prototypes.
void *calloc_or_quit(size_t nmemb, size_t size);
void code_error_quit(const char *message);


/**
 * Log to info file macro.
 */
#define log_info(log_text) { \
    FILE* log_file; \
    time_t rawtime; \
    struct tm * timeinfo; \
\
    time ( &rawtime ); \
    timeinfo = localtime ( &rawtime ); \
\
    log_file = fopen("log/info.txt", "a+"); \
    fprintf(log_file, "INFO [%d-%d-%d %d:%d:%d] %s %d (%s): %s\n", \
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, \
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
        __FILE__, __LINE__, __func__, log_text \
    ); \
    fclose(log_file); \
\
    printf("INFO [%d-%d-%d %d:%d:%d] %s %d (%s): %s\n", \
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, \
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
        __FILE__, __LINE__, __func__, log_text \
    ); \
}


/**
 * Log to warn file macro.
 */
#define log_warn(log_text) { \
    FILE* log_file; \
    time_t rawtime; \
    struct tm * timeinfo; \
\
    time ( &rawtime ); \
    timeinfo = localtime ( &rawtime ); \
\
    log_file = fopen("log/info.txt", "a+"); \
    fprintf(log_file, "WARN [%d-%d-%d %d:%d:%d] %s %d (%s): %s\n", \
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, \
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
        __FILE__, __LINE__, __func__, log_text \
    ); \
    fclose(log_file); \
\
    log_file = fopen("log/warn.txt", "a+"); \
    fprintf(log_file, "WARN [%d-%d-%d %d:%d:%d] %s %d (%s): %s\n", \
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, \
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
        __FILE__, __LINE__, __func__, log_text \
    ); \
    fclose(log_file); \
\
    printf("WARN [%d-%d-%d %d:%d:%d] %s %d (%s): %s\n", \
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, \
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
        __FILE__, __LINE__, __func__, log_text \
    ); \
}


/**
 * Log to error file macro.
 */
#define log_error(log_text) { \
    FILE* log_file; \
    time_t rawtime; \
    struct tm * timeinfo; \
\
    time ( &rawtime ); \
    timeinfo = localtime ( &rawtime ); \
\
    log_file = fopen("log/info.txt", "a+"); \
    fprintf(log_file, "ERR [%d-%d-%d %d:%d:%d] %s %d (%s): %s\n", \
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, \
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
        __FILE__, __LINE__, __func__, log_text \
    ); \
    fclose(log_file); \
\
    log_file = fopen("log/warn.txt", "a+"); \
    fprintf(log_file, "ERR [%d-%d-%d %d:%d:%d] %s %d (%s): %s\n", \
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, \
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
        __FILE__, __LINE__, __func__, log_text \
    ); \
    fclose(log_file); \
\
    log_file = fopen("log/error.txt", "a+"); \
    fprintf(log_file, "ERR [%d-%d-%d %d:%d:%d] %s %d (%s): %s\n", \
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, \
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
        __FILE__, __LINE__, __func__, log_text \
    ); \
    fclose(log_file); \
\
    printf("ERR [%d-%d-%d %d:%d:%d] %s %d (%s): %s\n", \
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, \
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, \
        __FILE__, __LINE__, __func__, log_text \
    ); \
}
