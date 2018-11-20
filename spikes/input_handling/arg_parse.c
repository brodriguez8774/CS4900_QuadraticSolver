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
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../src/argparse.h"
#include "../../src/helper.h"
#include "../../src/prompt.h"


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
        "Created by Steven H Johnson, Brandon Rodriguez, and Joshua Sziede.",
        5);

    // test input 3 numbers with flag
    ARGKEY arg_nums = argparse_add_argument(
        argparse, "--nums", "-n", "Accepts three numbers 'A B C'. See NUM_FORMAT", 3);
    char nums_set = 0;

    char parse_errors = argparse_parse(argparse, argc, argv);
    if (parse_errors == 0) {
        const char **string_nums = NULL;

        nums_set = argparse_get_argument(argparse, arg_nums, NULL, &string_nums);
        double a = 0;
        double b = 0;
        double c = 0;

        // Check if arg was provided.
        if (nums_set) {
            a = strtod(string_nums[0], NULL);
            b = strtod(string_nums[1], NULL);
            c = strtod(string_nums[2], NULL);
            printf("Received value:\n %f\n %f\n %f\n", a, b, c);
        } else {
            printf("No values passed. Please use -n <values> to pass a value.\n");
        }
    }

    argparse_free(argparse);
    exit(0);
}
