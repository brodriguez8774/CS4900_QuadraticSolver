static double test_x = 0;
static double test_sqrt_x = 0;
static double test_x_input = 0;

/**
 * Mocks sqrt function.
 *
 * Requires '-Wl,--wrap=sqrt' flag when linking.
 */
double __wrap_sqrt(double x) {
    test_x_input = x;
    return test_sqrt_x;
}

void mock_sqrt_setup(double x, double sqrt_x) {
    test_x = x;
    test_sqrt_x = sqrt_x;
}

void mock_sqrt_get(double *x, double *sqrt_x) {
    *x = test_x_input;
    *sqrt_x = test_sqrt_x;
}