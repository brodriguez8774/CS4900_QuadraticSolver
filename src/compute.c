
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
COMPUTATION_STRUCT *computation_struct_new(double original_x) {
    COMPUTATION_STRUCT *computation_struct = calloc_or_quit(1, sizeof(COMPUTATION_STRUCT));
    computation_struct->x = original_x;

    // Check if x is imaginary. If so, set as "Imaginary". Else, convert float to string.
    if (isnan(computation_struct->x)) {
        computation_struct->string_needs_free = 0;
        computation_struct->x_as_string = "Imaginary\0";
    } else {
        computation_struct->string_needs_free = 1;
        computation_struct->x_as_string = calloc_or_quit(MAX_ANSWER_LENGTH, sizeof(char*));
        sprintf(computation_struct->x_as_string, "%.10E", computation_struct->x);
    }

    // Print out struct values.
    // printf("x: %f\n", computation_struct->x);

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

int calculate_roots(double a, double b, double c, COMPUTATION_STRUCT **root1, COMPUTATION_STRUCT **root2) {
    double r1 = NAN;
    double r2 = NAN;
    double rooted = NAN;
    int inexact = 0;

    // Remove any possible lingering floating point exceptions.
    feclearexcept(FE_ALL_EXCEPT);

    double determinant = (b * b) - 4 * a * c;

    if (my_sqrt(determinant, &rooted) != 0) {
        code_error_quit("Invalid parameters");
    }

    // See Page 7 of "What Every Computer Scientist Should Know About Floating-Point Arithmetic"
    // For Quadratic Equation that limits precision loss.
    if (b < 0) {
        r1 = (-b + rooted) / (2 * a);
        r2 = c / (a * r1);
    } else if (b > 0) {
        r1 = (-b - rooted) / (2 * a);
        r2 = c / (a * r1);
    } else {
        if (my_sqrt(c / a, &r1) != 0) {
            code_error_quit("Invalid parameters");
        }
        r2 = -r1;
    }

    if (fetestexcept(FE_INEXACT) && FE_INEXACT) {
        inexact = 1;
    }

    //printf("Roots: %.10E, %.10E\n", r1, r2);

    *root1 = computation_struct_new(r1);
    *root2 = computation_struct_new(r2);

    return inexact;
}
