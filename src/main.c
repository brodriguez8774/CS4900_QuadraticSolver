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

#include "argparse.h"
#include "helper.h"


// Constant Defines.


// Global Variable Declaration.


// Method Declaration.
void display_help_text();
void display_invalid_arg_text();
void run_quad_solver();
void exit_program();


/**
 * Program's main.
 * Initializes and runs program.
 */
int main(int argc, char* argv[]) {
    printf("\n");

    ARGPARSE *argparse = argparse_new();

    if (argc == 1) {
        // No args provided. Display help.
        display_help_text();
    } else if (argc == 2) {
        // One arg provided.

        // Handling for -h (help) arg.
        if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
            display_help_text();
        } else {
            // No other commands supported yet. Display warning and close.
            display_invalid_arg_text();
        }

    } else if (argc == 3) {
        // Two args provided. Display warning and close.
        display_invalid_arg_text();
    } else if (argc == 4) {
        // Three args provided.
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        int c = atoi(argv[3]);

        // Check for valid args.
        if ((a == 0) && (b == 0) && (c == 0)) {
            // Invalid args provided. Exiting.
            printf("Recieved %dx^2 + %dx + %d. Invalid equation.\n", a, b, c);
            printf("Note that non-integer values are parsed as \"0\".\n");
            printf("Please try again.\n");
        } else {
            // At least one of a, b, or c is non-zero. Execute solver.
            run_quad_solver(a, b, c);
        }
    } else {
        // Four or more args provided. Display warning and close.
        display_invalid_arg_text();
    }

    printf("argparse: %p\n", (void *) argparse);

    argparse_free(argparse);

    exit_program(0);
}


/**
 * Displays program help text.
 * Called when no args are provided, or -h arg is provided.
 */
void display_help_text() {
    printf("Quadratic Equation Solver Help Menu\n");
    printf("\n");
    printf("Description:\n");
    printf("  This program solves quadratic equations.\n");
    printf("  Equations are expected to be in the format ax^2 + bx + c = 0.\n");
    printf("  Expected input values are a, b, and c, separated by spaces.\n");
    printf("  The program will calculate and display the result, as well as warnings about possible rounding, if applicable.\n");
    printf("\n");
    printf("Example program input:\n");
    printf("  quad_solver 4 2 1\n");
    printf("  Will solve for the equation 4x^2 + 2x + 1 = 0\n");
    printf("\n");
    printf("To see this help menu again, pass the \"-h\" or \"--help\" args.\n");
}


/**
 * Displays warning text for invalid user args.
 */
void display_invalid_arg_text() {
    printf("Invalid args passed.\n");
    printf("Please use the --help for more information.\n");
}


/**
 * Runs the quad solver program.
 */
void run_quad_solver(int a, int b, int c) {
    printf("Calculating %dx^2 + %dx + %d.\n", a, b, c);
}

/**
 * Handles program exit and cleanup.
 */
void exit_program(int exit_code) {
    printf("\nExiting program with code of %d.\n", exit_code);
    exit(exit_code);
}
