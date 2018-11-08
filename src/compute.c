
/**
 * CS 4900
 * Contains functions quad solver computing.
 */


// Import headers.
#include <fenv.h>
#include <math.h>
#include "compute.h"
#include "my_sqrt.h"


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


/**
 * Calculate x plus.
 */
COMPUTATION_STRUCT *calculate_x_plus(float a, float b, float c) {
    float x_plus = 0;
    double determinant = 0;
    double squared = 0;
    COMPUTATION_STRUCT *x_plus_struct;

    // printf("Calculating (%f + (%f^2 - 4*%f*%f)^(1/2))/(2*%f)\n", (-1*b), b, a, c, a);

    // Removes any possible lingering floating point exceptions.
    feclearexcept(FE_ALL_EXCEPT);

    // Determines the value of x_plus using the quadratic formula
    determinant = (b * b) - (4 * a * c);
    if (my_sqrt(determinant, &squared) != 0) {
        // TODO: Should this function return an error code?
        code_error_quit("Invalid parameters");
    }
    x_plus = (((-1 * b) + squared) / (2 * a));
    x_plus_struct = computation_struct_new(x_plus);

    return x_plus_struct;
}


/**
 * Calculate x minus.
 */
COMPUTATION_STRUCT *calculate_x_minus(float a, float b, float c) {
    float x_minus;
    double determinant = 0;
    double squared = 0;
    COMPUTATION_STRUCT *x_minus_struct;

    // printf("Calculating (%f - (%f^2 - 4*%f*%f)^(1/2)/(2*%f)))\n", (-1*b), b, a, c, a);

    // Removes any possible lingering floating point exceptions.
    feclearexcept(FE_ALL_EXCEPT);

    // Determines the value of x_plus using the quadratic formula
    determinant = (b * b) - (4 * a * c);
    if (my_sqrt(determinant, &squared) != 0) {
        // TODO: Should this function return an error code?
        code_error_quit("Invalid parameters");
    }
    x_minus = (((-1 * b) - squared) / (2 * a));
    x_minus_struct = computation_struct_new(x_minus);

    return x_minus_struct;
}
