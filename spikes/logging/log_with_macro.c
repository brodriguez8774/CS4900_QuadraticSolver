/**
 * CS 4900
 * Log with Macro spike.
 */


/**
 * Description:
 *  Spike to test basic logging to file using macro-based logging.
 */


// Import headers.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "log_with_macro.h"



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

    log_info(log_text);

    exit(0);
}
