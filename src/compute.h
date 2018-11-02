/**
 * CS 4900
 * Header file for quad solver computing.
 */


// Import headers.
#ifndef _QUAD_SOLVER_COMPUTE_H
    #define _QUAD_SOLVER_COMPUTE_H
    #include <fenv.h>
    #include <math.h>
    #include "helper.h"


// Struct typedef declaration.
typedef struct {
    int string_needs_free;  // Bool to hold if x_as_string needs a free() or not.
    int rounding_error;     // Bool to hold if rounding error was detected.
    float x;                // Computated value, unmodified.
    char *x_as_string;      // Answer may not always be a number. Use this for safe printing.
    char *rounding_error_display;   // Print display for rounding error.
} COMPUTATION_STRUCT;


// Function Prototypes.
COMPUTATION_STRUCT *computation_struct_new(float original_x);
void computation_struct_free(COMPUTATION_STRUCT *computation_struct);
COMPUTATION_STRUCT *calculate_x_plus(float a, float b, float c);
COMPUTATION_STRUCT *calculate_x_minus(float a, float b, float c);


#endif // _QUAD_SOLVER_COMPUTE_H
