/**
 * CS 4900
 * Quadratic Equation Solver
 * 2018-09-17
 *
 * Authors:
 *  Steven H Johnson
 *  Brandon Rodriguez
 *  Joshua Sziede
 */


/**
 * Description:
 *  Console program to solve quadratic equations. See program help for more details.
 */


// Import headers.
#include <float.h>
#include <math.h>
#include "argparse.h"
#include "compute.h"
#include "helper.h"
#include "prompt.h"


// Method Declaration.
void run_quad_solver(double a, double b, double c, int logging_mode);
char parse_doubles(const char *string, double *a, double *b, double *c);
void exit_program(int exit_code, int logging_mode);


/**
 * Program's main.
 * Initializes and runs program.
 */
int main(int argc, char* argv[]) {
    int exit_code = 1;
    printf("\n");

    ARGPARSE *argparse = argparse_new(
        "Quadratic Equation Solver",
        "  This program solves quadratic equations.\n"
        "  Equations are expected to be in the format ax^2 + bx + c = 0.\n"
        "  Expected input values are a, b, and c, separated by spaces.\n"
        "  The program will calculate and display the result, as well as "
        "warnings about possible rounding, if applicable.\n\n"
        "NUM_FORMAT: A, B, C are in the following format: n[.n][En]\n"
        "            where n is any number of digits.\n"
        "            Examples: 4.24, 4.24E7, 0.0003E1, 234E2",
        "Created by Steven H Johnson, Brandon Rodriguez, and Joshua Sziede.",
        5);

    // logging option
    ARGKEY arg_logging = argparse_add_argument(
        argparse, "--log", "-l", "Enable logging mode.", 0);
    char logging_mode = 0;

    // test input 3 numbers with flag
    ARGKEY arg_nums = argparse_add_argument(
        argparse, "--nums", "-n", "Accepts three numbers 'A B C'. See NUM_FORMAT", 3);
    int nums_set = 0;

    char parse_errors = argparse_parse(argparse, argc, argv);
    if (parse_errors == 0) {
        const char **string_nums = NULL;

        nums_set = argparse_get_argument(argparse, arg_nums, NULL, &string_nums);
        logging_mode = argparse_get_argument(argparse, arg_logging, NULL, NULL);

        if (logging_mode) {
            log_info(logging_mode, "%s", "Logging is enabled.");
        }

        double a = 0;
        double b = 0;
        double c = 0;

        if (nums_set) {
            // Three args A B C provided.
            a = strtod(string_nums[0], NULL);
            b = strtod(string_nums[1], NULL);
            c = strtod(string_nums[2], NULL);
        } else {
            // Need to prompt for A B C
            char *input_string = prompt_user("Please enter A B C.", NULL, 255, logging_mode);
            if (parse_doubles(input_string, &a, &b, &c) != 0) {
                log_error(logging_mode, "%s", "Unexpected number format. Please use 'A B C'");
                exit_code = 1;
            }
            free(input_string);
        }
        log_info(logging_mode, "Received floats:\nA: %.10E\nB: %.10E\nC: %.10E", a, b, c);

        // Check for valid args.
        if (a == 0) {
            // Invalid args provided. Exiting.
            log_warn(logging_mode, "Recieved %fx^2 + %fx + %f. Invalid equation, A can't be zero.", a, b, c);
            log_warn(logging_mode, "%s", "Note that non-integer values are parsed as \"0\".");
            log_warn(logging_mode, "%s", "Please try again.");
        // a, b, c > 0 or NAN
        } else if ((a > 0 && (a < FLT_MIN || a > FLT_MAX)) || isnan(a)) {
            log_warn(logging_mode, "The first value is not within the exclusive range %.10e - %.10e", FLT_MIN, FLT_MAX);
            log_warn(logging_mode, "%s", "Please try again.");
        } else if ((b > 0 && (b < FLT_MIN || b > FLT_MAX)) || isnan(b)) {
            log_warn(logging_mode, "The second value is not within the exclusive range %.10e - %.10e", FLT_MIN, FLT_MAX);
            log_warn(logging_mode, "%s", "Please try again.");
        } else if ((c > 0 && (c < FLT_MIN || c > FLT_MAX)) || isnan(c)) {
            log_warn(logging_mode, "The last value is not within the exclusive range %.10e - %.10e", FLT_MIN, FLT_MAX);
            log_warn(logging_mode, "%s", "Please try again.");
        // a, b, c < 0
        } else if (a < 0 && (a < -FLT_MAX || a > -FLT_MIN)) {
            log_warn(logging_mode, "The first value is not within the exclusive range %.10e - %.10e", -FLT_MAX, -FLT_MIN);
            log_warn(logging_mode, "%s", "Please try again.");
        } else if (b < 0 && (b < -FLT_MAX || b > -FLT_MIN)) {
            log_warn(logging_mode, "The second value is not within the exclusive range %.10e - %.10e", -FLT_MAX, -FLT_MIN);
            log_warn(logging_mode, "%s", "Please try again.");
        } else if (c < 0 && (c < -FLT_MAX || c > -FLT_MIN)) {
            log_warn(logging_mode, "The last value is not within the exclusive range %.10e - %.10e", -FLT_MAX, -FLT_MIN);
            log_warn(logging_mode, "%s", "Please try again.");
        } else {
            // Values are valid. Execute solver.
            run_quad_solver(a, b, c, logging_mode);
            exit_code = 0;
        }
    }

    argparse_free(argparse);

    exit_program(exit_code, logging_mode);
}


/**
 * Runs the quad solver equation and outputs results.
 */
void run_quad_solver(double a, double b, double c, int logging_mode) {
    log_info(logging_mode, "Calculating %.01Ex^2 + %.01Ex + %.01E = 0.", a, b, c);

    COMPUTATION_STRUCT *root1;
    COMPUTATION_STRUCT *root2;
    int inexact = 0;

    inexact = calculate_roots(a, b, c, &root1, &root2);

    char *round_error = "No";
    if (inexact) {
        round_error = "Yes";
    }

    log_info(logging_mode, "Results:\n\tr1: %s\n\n\tr2: %s\n\n\tInexact: %s",
        root1->x_as_string, root2->x_as_string, round_error);

    computation_struct_free(root1);
    computation_struct_free(root2);
}


/**
 * Convert a string in the form "A B C" to doubles. Whitespace is ignored.
 *
 * Returns 0 if no error, 1 if error.
 */
char parse_doubles(const char *string, double *a, double *b, double *c) {

    if (sscanf(string, "%lf %lf %lf", a, b, c) != 3) {
        return 1;
    }

    return 0;
    char *token = calloc_or_quit(MAX_ANSWER_LENGTH+1, 1);
    char x = '\0';
    size_t i = 0;
    size_t offset = 0;
    char count = 0; // to keep track which double to set
    double value = 0;

    for (i = 0; i < strlen(string); ++i) {
        x = string[i];
        if (x == ' ' || x == '\0' || x == '\n' || x == '\t') {
            // We found a full token
            if (i - offset > MAX_ANSWER_LENGTH) {
                return 1; // Too long to parse
            } else if (i - offset == 0) {
                // Extra whitespace should just be ignored
                ++offset;
                continue;
            }
            strncpy(token, string + offset, i - offset);
            token[i - offset] = '\0'; // NULL terminate the string
            offset = i + 1; // reset offset for next token
            value = strtod(token, NULL);
            if (count == 0) {
                *a = value;
            } else if (count == 1) {
                *b = value;
            } else if (count == 2) {
                *c = value;
            } else {
                return 1; // Too many numbers returned
            }
            ++count;
        }
    }

    if (count != 3) {
        return 1; // Not enough doubles parsed
    }

    return 0;
}


/**
 * Handles program exit and cleanup.
 */
void exit_program(int exit_code, int logging_mode) {
    // Check if code is non-zero. If so, log as error. Else log as info.
    printf("\n");
    if (exit_code) {
        log_error(logging_mode, "Exiting program with code of %d.", exit_code);
    } else {
        log_info(logging_mode, "Exiting program with code of %d.", exit_code);
    }
    exit(exit_code);
}
