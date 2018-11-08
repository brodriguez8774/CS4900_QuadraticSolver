#include <stdio.h>
#include "../../src/my_sqrt.h"

/**
 * TODO: This is a work in progress.
 *
 * Currently this shows that my_sqrt's sqrt() function has been mocked.
 * It will always return 1, instead of computing the correct value of 2.
 */
int main(int argc, char *argv[]) {
    int error = 0;
    int my_sqrt_error = 0;
    double x = 4.0f;
    double out = 0;

    printf("Hello!\n");

    my_sqrt_error = my_sqrt(x, &out);
    printf("my_sqrt_error: %d\n", my_sqrt_error);
    printf("Computed value: %f\n", out);

    return error;
}
