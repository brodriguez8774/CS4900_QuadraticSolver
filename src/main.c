/**
 * CS 4900
 * Quadratic Equation Solver
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


// Constant Defines.


// Global Variable Declaration.


// Method Declaration.
void display_help_text();
void exit_program();


/**
 * Program's main.
 * Initializes and runs program.
 */
int main(int argc, char* argv[]) {

    // No commands provided. Display help.
    if (argc == 1) {
        display_help_text();
    } else {

        // Handling for -h (help) arg.
        if ( ((argc == 2) && (strcmp(argv[1], "-h") == 0)) ||
             ((argc == 2) && (strcmp(argv[1], "--help") == 0)) ) {
            display_help_text();
            exit_program(0);
        }

        printf("You have provided one or more args. No handling yet.\n");
        // Display passed args.
        for (int index = 0; index < (argc - 1); index++) {
            printf("%s\n", argv[index + 1]);
        }
    }

    exit_program(0);
}


/**
 * Displays program help text.
 * Called when no args are provided, or -h arg is provided.
 */
void display_help_text() {
    printf("\nQuadratic Equation Solver Help Menu\n");
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
    printf("\n");
}


/**
 * Handles program exit and cleanup.
 */
void exit_program(int exit_code) {
    printf("Exiting program with code of %d.\n", exit_code);
    exit(exit_code);
}
