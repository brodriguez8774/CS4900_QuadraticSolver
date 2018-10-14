/**
 * CS 4900
 * Arg parse spike.
 */


/**
 * Description:
 *  Spike to test handling argv with full Arg Parse.
 */


// Import headers.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../src/argparse.h"
#include "../../src/helper.h"


// Method Declaration.
void run_quad_solver();
void exit_program();


/**
 * Program's main.
 * Initializes and runs program.
 */
int main(int argc, char* argv[]) {
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
        "Created by Steven H Johnson, Brandon Rodriquez, and Joshua Sziede.",
        4);

    // Expecting three positional arguments.
    ARGKEY arg_a = argparse_add_argument(argparse, "A", NULL, "See NUM_FORMAT.");
    ARGKEY arg_b = argparse_add_argument(argparse, "B", NULL, "See NUM_FORMAT.");
    ARGKEY arg_c = argparse_add_argument(argparse, "C", NULL, "See NUM_FORMAT.");

    // debug option
    ARGKEY arg_debug = argparse_add_argument(
        argparse, "--debug", "-d", "Enable debug mode.");
    char debug_mode = 0; // TODO: Use this debug flag in our code?

    char parse_errors = argparse_parse(argparse, argc, argv);
    if (parse_errors == 0) {
        const char *string_a = NULL;
        const char *string_b = NULL;
        const char *string_c = NULL;

        argparse_get_argument(argparse, arg_a, &string_a);
        argparse_get_argument(argparse, arg_b, &string_b);
        argparse_get_argument(argparse, arg_c, &string_c);

        debug_mode = argparse_get_argument(argparse, arg_debug, NULL);

        printf("A: %s\nB: %s\nC: %s\n", string_a, string_b, string_c);
        printf("Debug Mode: %d\n", debug_mode);

        // Three args provided.
        double a = strtod(string_a, NULL);
        double b = strtod(string_b, NULL);
        double c = strtod(string_c, NULL);

        // Check for valid args.
        if (a == 0) {
            // Invalid args provided. Exiting.
            printf("Recieved %fx^2 + %fx + %f. Invalid equation, A can't be zero.\n", a, b, c);
            printf("Note that non-integer values are parsed as \"0\".\n");
            printf("Please try again.\n");
        } else {
            // At least one of a, b, or c is non-zero. Execute solver.
            printf("Quad solver computing logic here.\n");
        }
    }

    argparse_free(argparse);

    exit(0);
}
