
/**
 * CS 4900
 * Contains functions quad solver computing.
 */


// Import headers.
#include "compute.h"


/**
 * Creates computation struct.
 */
COMPUTATION_STRUCT *computation_struct_new(float original_x) {
    COMPUTATION_STRUCT *computation_struct = calloc_or_quit(1, sizeof(COMPUTATION_STRUCT));
    computation_struct->x = original_x;

    // Determines if rounding error was detected while calculating x_plus.
    if (fetestexcept(FE_INEXACT) && FE_INEXACT) {
        computation_struct->rounding_error = 1;
        computation_struct->rounding_error_display = "Yes\0";
    } else {
        computation_struct->rounding_error = 0;
        computation_struct->rounding_error_display = "No\0";
    }

    // Check if x is imaginary. If so, set as "Imaginary". Else, convert float to string.
    if (isnan(computation_struct->x)) {
        computation_struct->string_needs_free = 0;
        computation_struct->x_as_string = "Imaginary\0";
    } else {
        computation_struct->string_needs_free = 1;
        computation_struct->x_as_string = calloc_or_quit(MAX_ANSWER_LENGTH, sizeof(char*));
        sprintf(computation_struct->x_as_string, "%f", computation_struct->x);
    }

    // Remove any possible lingering floating point exceptions.
    feclearexcept(FE_ALL_EXCEPT);

    // Print out struct values.
    // printf("x: %f\nx Rounding Error: %d\n\n", computation_struct->x, computation_struct->rounding_error);

    return computation_struct;
}


/**
 *  Removes computation_struct and free's memory.
 */
void computation_struct_free(COMPUTATION_STRUCT *computation_struct) {
    if (computation_struct->string_needs_free) {
        free(computation_struct->x_as_string);
    }
    free(computation_struct);
}
