/**
 * CS 4900
 * Simple parse spike.
 */


/**
 * Description:
 *  Spike to test simplistic handling of std in.
 */


// Import headers.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Method Declaration.
void display_help_text();


/**
 * Program's main.
 * Initializes and runs program.
 */
int main(int argc, char* argv[]) {
    printf("\n");

    if (argc == 4) {
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
            printf("Quad solver computing logic here.\n");
        }
    } else if (argc == 2) {
        // One arg provided.

        // Handling for -h (help) arg.
        if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
            display_help_text();
        } else {
            // No other commands supported yet.
            printf("Unrecognized argument.\n");
        }
    } else {
        // Four or more args provided. Display warning and close.
        display_help_text();
    }

    exit(0);
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
