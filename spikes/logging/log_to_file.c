/**
 * CS 4900
 * Log to File spike.
 */


/**
 * Description:
 *  Spike to test basic logging to file.
 */


// Import headers.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Method Declaration.
void log_info();


/**
 * Program's main.
 * Initializes and runs program.
 */
int main(int argc, char* argv[]) {
    char* log_text;

    if (argc > 1) {
        log_text = argv[1];
    } else {
        log_text = "No args provided for logging.";
    }

    log_info(__FILE__, __LINE__, __func__, log_text);

    exit(0);
}


/**
 * Logs text data to file.
 * Note: Use mode "a+" to keep log through consecutive program launches.
 *      Current mode of "w+" resets log file on each call.
 */
void log_info(char* file, int line, char* func, char* log_text) {
    FILE* log_file;
    time_t rawtime;
    struct tm * timeinfo;

    // Get current time.
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    log_file = fopen("log_file.txt", "w+");
    fprintf(log_file, "[%d-%d-%d %d:%d:%d] %s %d (%s): %s\n",
        // asctime(timeinfo),
        timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
        file, line, func, log_text
    );
    fclose(log_file);
}
