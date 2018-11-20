/**
 * helper.c
 * Contains miscellaneous helper functions for the project.
 *
 * Includes things like "error and quit" handling and log handling.
 */


// Import headers.
#include "helper.h"


/**
 * Same arguments as calloc, but calls log_error on error and exits.
 */
void *calloc_or_quit(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if (ptr == NULL) {
        log_error(1, "%s", "Failed to allocate memory.");
        exit(1);
    }

    return ptr;
}


/**
 * Logs error message and exits program with error code of 1.
 */
void code_error_quit(const char *message) {
    log_error(1, "%s", message);
    exit(1);
}


/**
 * Wrapper function for info message logging.
 * Calls appropriate logging sub-functions.
 */
void va_log_info(int log_mode, const char *s_file_name, int s_line_num, const char *s_format_string, ...) {
    char *log_level = "INFO";
    time_t rawtime;
    struct tm * timeinfo;
    va_list va_arglist;

    // Get time info.
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    // Call appropriate logging sub-fucntions and handle variable length arg input.
    // Check if logging is enabled.
    if (log_mode) {
        // To console.
        va_start(va_arglist, s_format_string);
        va_log_to_console(__FILE__, __LINE__, log_level, timeinfo, s_format_string, va_arglist);
        va_end(va_arglist);
        // To info file.
        va_start(va_arglist, s_format_string);
        va_to_info_file(__FILE__, __LINE__, log_level, timeinfo, s_format_string, va_arglist);
        va_end(va_arglist);
    } else {
        // To console.
        va_start(va_arglist, s_format_string);
        va_print_to_console(s_format_string, va_arglist);
        va_end(va_arglist);
    }
}


/**
 * Wrapper function for warn message logging.
 * Calls appropriate logging sub-functions.
 */
void va_log_warn(int log_mode, const char *s_file_name, int s_line_num, const char *s_format_string, ...) {
    char *log_level = "WARN";
    time_t rawtime;
    struct tm * timeinfo;
    va_list va_arglist;

    // Get time info.
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    // Call appropriate logging sub-fucntions and handle variable length arg input.
    // Check if logging is enabled.
    if (log_mode) {
        // To console.
        va_start(va_arglist, s_format_string);
        va_log_to_console(__FILE__, __LINE__, log_level, timeinfo, s_format_string, va_arglist);
        va_end(va_arglist);

        // To info file.
        va_start(va_arglist, s_format_string);
        va_to_info_file(__FILE__, __LINE__, log_level, timeinfo, s_format_string, va_arglist);
        va_end(va_arglist);

        // To warn file.
        va_start(va_arglist, s_format_string);
        va_to_warn_file(__FILE__, __LINE__, log_level, timeinfo, s_format_string, va_arglist);
        va_end(va_arglist);
    } else {
        // To console.
        va_start(va_arglist, s_format_string);
        va_print_to_console(s_format_string, va_arglist);
        va_end(va_arglist);
    }
}


/**
 * Wrapper function for error message logging.
 * Calls appropriate logging sub-functions.
 */
void va_log_error(int log_mode, const char *s_file_name, int s_line_num, const char *s_format_string, ...) {
    char *log_level = "ERROR";
    time_t rawtime;
    struct tm * timeinfo;
    va_list va_arglist;

    // Get time info.
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    // Call appropriate logging sub-fucntions and handle variable length arg input.
    // Check if logging is enabled.
    if (log_mode) {
        // To console.
        va_start(va_arglist, s_format_string);
        va_log_to_console(__FILE__, __LINE__, log_level, timeinfo, s_format_string, va_arglist);
        va_end(va_arglist);

        // To info file.
        va_start(va_arglist, s_format_string);
        va_to_info_file(__FILE__, __LINE__, log_level, timeinfo, s_format_string, va_arglist);
        va_end(va_arglist);

        // To warn file.
        va_start(va_arglist, s_format_string);
        va_to_warn_file(__FILE__, __LINE__, log_level, timeinfo, s_format_string, va_arglist);
        va_end(va_arglist);

        // To error file.
        va_start(va_arglist, s_format_string);
        va_to_error_file(__FILE__, __LINE__, log_level, timeinfo, s_format_string, va_arglist);
        va_end(va_arglist);
    } else {
        // To console.
        va_start(va_arglist, s_format_string);
        va_print_to_console(s_format_string, va_arglist);
        va_end(va_arglist);
    }
}


/**
 * Print variable length message to console.
 * Does not have datetime or source file information.
 */
void va_print_to_console(const char *s_format_string, va_list va_arglist) {

    char *format_string;

    // Create formatted string, with default formatting.
    format_string = calloc(MAX_LOG_STRING_LENGTH, sizeof(char*));
    sprintf(format_string, "%s\n", s_format_string);

    // Print to console.
    vprintf(format_string, va_arglist);

    // Clean up.
    free(format_string);
}


/**
 * Log variable length message to console.
 */
void va_log_to_console(const char *s_file_name,
                    int s_line_num,
                    const char *log_level,
                    struct tm * timeinfo,
                    const char *s_format_string,
                    va_list va_arglist) {

    char *format_string;

    // Create formatted string, with default formatting.
    format_string = calloc(MAX_LOG_STRING_LENGTH, sizeof(char*));
    sprintf(format_string, "[%d-%d-%d %d:%d:%d] [%s] %s %d: %s\n",
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
        log_level, s_file_name, s_line_num, s_format_string
    );

    // Print to console.
    vprintf(format_string, va_arglist);

    // Clean up.
    free(format_string);
}


/**
 * Log variable length message to info file.
 */
void va_to_info_file(const char *s_file_name,
                        int s_line_num,
                        const char *log_level,
                        struct tm * timeinfo,
                        const char *s_format_string,
                        va_list va_arglist) {

    char *format_string;
    FILE *log_file;

    // Create initial formatted string, with default formatting.
    format_string = calloc_or_quit(MAX_LOG_STRING_LENGTH, sizeof(char*));
    sprintf(format_string, "[%d-%d-%d %d:%d:%d] [%s] %s %d: %s\n",
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
        log_level, s_file_name, s_line_num, s_format_string
    );

    // Save to log file.
    log_file = fopen("log/info.txt", "a+");
    vfprintf(log_file, format_string, va_arglist);

    // Clean up.
    fclose(log_file);
    free(format_string);
}


/**
 * Log variable length message to warn file.
 */
void va_to_warn_file(const char *s_file_name,
                        int s_line_num,
                        const char *log_level,
                        struct tm * timeinfo,
                        const char *s_format_string,
                        va_list va_arglist) {

    char *format_string;
    FILE *log_file;

    // Create initial formatted string, with default formatting.
    format_string = calloc_or_quit(MAX_LOG_STRING_LENGTH, sizeof(char*));
    sprintf(format_string, "[%d-%d-%d %d:%d:%d] [%s] %s %d: %s\n",
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
        log_level, s_file_name, s_line_num, s_format_string
    );

    // Save to log file.
    log_file = fopen("log/warn.txt", "a+");
    vfprintf(log_file, format_string, va_arglist);

    // Clean up.
    fclose(log_file);
    free(format_string);
}


/**
 * Log variable length message to error file.
 */
void va_to_error_file(const char *s_file_name,
                        int s_line_num,
                        const char *log_level,
                        struct tm * timeinfo,
                        const char *s_format_string,
                        va_list va_arglist) {

    char *format_string;
    FILE *log_file;

    // Create initial formatted string, with default formatting.
    format_string = calloc_or_quit(MAX_LOG_STRING_LENGTH, sizeof(char*));
    sprintf(format_string, "[%d-%d-%d %d:%d:%d] [%s] %s %d: %s\n",
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
        log_level, s_file_name, s_line_num, s_format_string
    );

    // Save to log file.
    log_file = fopen("log/error.txt", "a+");
    vfprintf(log_file, format_string, va_arglist);

    // Clean up.
    fclose(log_file);
    free(format_string);
}
