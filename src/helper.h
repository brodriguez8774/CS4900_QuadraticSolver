/**
 * CS 4900
 * Header file for misc project helper functions and macros.
 *
 * Includes things like "error and quit" handling and log handling.
 */


// Import headers.
#ifndef _QUAD_SOLVER_CORE_IMPORTS
    #define _QUAD_SOLVER_CORE_IMPORTS
    #include <ctype.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
#endif // _QUAD_SOLVER_CORE_IMPORTS


// Constant Defines.
#define MAX_ANSWER_LENGTH 30    // The maximum number of chars used to store the quadratic equation answers.
#define MAX_LOG_STRING_LENGTH 2048


// Function Prototypes.
void *calloc_or_quit(size_t nmemb, size_t size);
void code_error_quit(const char *message);
void va_log_print(const char *s_file_name, int s_line_num, const char *s_format_string, ...);
void va_log_info(const char *s_file_name, int s_line_num, const char *s_format_string, ...);
void va_log_warn(const char *s_file_name, int s_line_num, const char *s_format_string, ...);
void va_log_error(const char *s_file_name, int s_line_num, const char *s_format_string, ...);

void va_to_console(const char *s_file_name,
    int s_line_num,
    const char *log_level,
    struct tm * timeinfo,
    const char *s_format_string,
    va_list va_arglist);

void va_to_info_file(const char *s_file_name,
    int s_line_num,
    const char *log_level,
    struct tm * timeinfo,
    const char *s_format_string,
    va_list va_arglist);

void va_to_warn_file(const char *s_file_name,
    int s_line_num,
    const char *log_level,
    struct tm * timeinfo,
    const char *s_format_string,
    va_list va_arglist);

void va_to_error_file(const char *s_file_name,
    int s_line_num,
    const char *log_level,
    struct tm * timeinfo,
    const char *s_format_string,
    va_list va_arglist);


// Macro definitions.
#define log_info(s_format_string, ...) \
    va_log_info(__FILE__, __LINE__, s_format_string, __VA_ARGS__)

#define log_warn(s_format_string, ...) \
    va_log_warn(__FILE__, __LINE__, s_format_string, __VA_ARGS__)

#define log_error(s_format_string, ...) \
    va_log_error(__FILE__, __LINE__, s_format_string, __VA_ARGS__)
