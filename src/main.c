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


/**
 * Known Issues:
 *
 */


// Import headers.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fenv.h>

#include "argparse.h"
#include "helper.h"
#include "prompt.h"


// Constant Defines.
#define MAX_ANSWER_LENGTH 30	//the maximum number of characters that can be used to store the answers of the quadratic equation

// Global Variable Declaration.


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
        5);

    // logging option
    ARGKEY arg_logging = argparse_add_argument(
        argparse, "--log", "-l", "Enable logging mode.", 0);
    char logging_mode = 0; // TODO: Use this logging flag in our code

    // test input 3 numbers with flag
    ARGKEY arg_nums = argparse_add_argument(
        argparse, "--nums", "-n", "Accepts three numbers 'A B C'. See NUM_FORMAT", 3);
    char nums_set = 0;

    char parse_errors = argparse_parse(argparse, argc, argv);
    if (parse_errors == 0) {
        const char **string_nums = NULL;

        nums_set = argparse_get_argument(argparse, arg_nums, NULL, &string_nums);
        logging_mode = argparse_get_argument(argparse, arg_logging, NULL, NULL);

        if (logging_mode) {
            printf("TODO: Do logging!\n");
        }

        double a = 0;
        double b = 0;
        double c = 0;

        if (nums_set) {
            printf("A: %s\nB: %s\nC: %s\n", string_nums[0], string_nums[1], string_nums[2]);

            // Three args provided.
            a = strtod(string_nums[0], NULL);
            b = strtod(string_nums[1], NULL);
            c = strtod(string_nums[2], NULL);
        } else {
            char *input_string = prompt_user("Please enter A B C.", NULL, 255);
            printf("Got: '%s'\n", input_string);
            // TODO: Parse input_string into a, b, c
            free(input_string);
        }


        a = -2;
        b = 4;
        c = 0;

        // Check for valid args.
        if (a == 0) {
            // Invalid args provided. Exiting.
            printf("Recieved %fx^2 + %fx + %f. Invalid equation, A can't be zero.\n", a, b, c);
            printf("Note that non-integer values are parsed as \"0\".\n");
            printf("Please try again.\n");
        } else {
            // At least one of a, b, or c is non-zero. Execute solver.
            run_quad_solver(a, b, c);
        }
    }

    argparse_free(argparse);

    exit_program(0);
}

/**
 * Runs the quad solver equation and outputs results.
 */
void run_quad_solver(double a, double b, double c) {
    printf("Calculating %fx^2 + %fx + %f.\n", a, b, c);

    //used to store the results of the quadratic solver as a string because the answer may not always be a number
    char *x_plus_to_string = calloc_or_quit(MAX_ANSWER_LENGTH, 1);
    char *x_minus_to_string = calloc_or_quit(MAX_ANSWER_LENGTH, 1);

    //stores a simple yes or no depending on if a rounding error was determined
    char *x_plus_rounding_error = calloc_or_quit(4, 1);
    x_plus_rounding_error = "No\0";
    char *x_minus_rounding_error = calloc_or_quit(4, 1);
    x_minus_rounding_error = "No\0";

    //remove any possible lingering floating point exceptions
    feclearexcept(FE_ALL_EXCEPT);

    //determines the value of x1 using the quadratic formula
    float x_plus = (((-1 * b) + sqrt((b * b) - (4 * a * c))) / (2 * a));

    //if rounding error detected while calculating x1
	if (fetestexcept(FE_INEXACT) && FE_INEXACT) {
		x_plus_rounding_error = "Yes\0";
	}

    //if x1 is imaginary
    if (isnan(x_plus)) {
    	x_plus_to_string = "Imaginary\0";
    } else { //else convert float to string
    	sprintf(x_plus_to_string, "%f", x_plus);
    }

    //remove any possible lingering floating point exceptions
    feclearexcept(FE_ALL_EXCEPT);

    //determines the value of x2 using the quadratic formula
    float x_minus = (((-1 * b) - sqrt((b * b) - (4 * a * c))) / (2 * a));

    //if rounding error detected while calculating x2
	if (fetestexcept(FE_INEXACT) && FE_INEXACT) {
		x_minus_rounding_error = "Yes\0";
	}

    //if x2 is imaginary
    if (isnan(x_minus)) {
    	x_minus_to_string = "Imaginary\0";
    } else { //else convert float to string
    	sprintf(x_minus_to_string, "%f", x_minus);
    }

    printf("Results:\n\tX1: %s\n\tPossible rounding error: %s\n\n\tX2: %s\n\tPossible rounding error: %s\n", x_plus_to_string, x_plus_rounding_error, x_minus_to_string, x_minus_rounding_error);
}

/**
 * Handles program exit and cleanup.
 */
void exit_program(int exit_code) {
    printf("\nExiting program with code of %d.\n", exit_code);
    exit(exit_code);
}
