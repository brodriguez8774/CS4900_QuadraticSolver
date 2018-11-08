/**
 * CS 4900
 * Math Library sqrt() wrapper.
 */
#include <math.h>

/**
 * Wrap sqrt() function.
 *
 * Return 0 if x is NAN or INFINITY.
 *
 * If x is less than zero than out will be NAN.
 * Otherwise out = sqrt(x).
 */
int my_sqrt(double x, double *out) {
    int error = 0;

    if (isnan(x) || x == INFINITY) {
        // Can't sqrt() these
        error = 1;
    } else if (x < 0) {
        // Imaginary
        *out = NAN;
    } else {
        // Valid
        *out = sqrt(x);
    }

    return error;
}
