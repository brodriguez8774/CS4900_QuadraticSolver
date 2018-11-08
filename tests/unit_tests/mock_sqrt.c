static short x = 0;

/**
 * Mocks sqrt function.
 *
 * Requires '-Wl,--wrap=sqrt' flag when linking.
 */
double __wrap_sqrt(double x) {
    return 1.0f;
}
