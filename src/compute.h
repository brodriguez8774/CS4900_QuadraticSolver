/**
 * CS 4900
 * Header file for quad solver computing.
 */


// Import headers.
#ifndef _QUAD_SOLVER_COMPUTE_H
    #define _QUAD_SOLVER_COMPUTE_H
    #include "helper.h"


// Struct typedef declaration.
typedef struct {
    int string_needs_free;  // Bool to hold if x_as_string needs a free() or not.
    double x;                // Computated value, unmodified.
    char *x_as_string;      // Answer may not always be a number. Use this for safe printing.
} COMPUTATION_STRUCT;


// Function Prototypes.
COMPUTATION_STRUCT *computation_struct_new(double original_x);
void computation_struct_free(COMPUTATION_STRUCT *computation_struct);
int calculate_roots(double a, double b, double c, COMPUTATION_STRUCT **root1, COMPUTATION_STRUCT **root2);


#endif // _QUAD_SOLVER_COMPUTE_H
