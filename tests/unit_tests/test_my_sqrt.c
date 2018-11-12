#include <stdio.h>
#include "../../src/my_sqrt.h"
#include "../cunit/cunit.h"
#include "mock_sqrt.h"

void test_my_sqrt_4_returns_2() {
    int my_sqrt_error = 0;
    double mock_x_in = 4.0f;
    double mock_x_out = 2.0f;
    double passed_x_in = 0;
    double passed_x_out = 0;
    double x_out = 0;

    mock_sqrt_setup(mock_x_in, mock_x_out);

    my_sqrt_error = my_sqrt(mock_x_in, &x_out);

    mock_sqrt_get(&passed_x_in, &passed_x_out);

    assert_eq("my_sqrt returned error", 0, my_sqrt_error);
    assert_feq("mock_sqrt did not get right argument", passed_x_in, mock_x_in);
    assert_feq("my_sqrt modified mock_sqrt return value", passed_x_out, x_out);
}

void test_my_sqrt_nan_has_error() {
    int my_sqrt_error = 0;
    double x_in = NAN;
    double x_out = 0;

    mock_sqrt_setup(0, 0);

    my_sqrt_error = my_sqrt(x_in, &x_out);

    assert_neq("my_sqrt didn't return error", 0, my_sqrt_error);
}

void test_my_sqrt_inf_has_error() {
    int my_sqrt_error = 0;
    double x_in = INFINITY;
    double x_out = 0;

    mock_sqrt_setup(0, 0);

    my_sqrt_error = my_sqrt(x_in, &x_out);

    assert_neq("my_sqrt didn't return error", 0, my_sqrt_error);
}

void test_my_sqrt_negative_returns_nan_and_sqrt_not_called() {
    int my_sqrt_error = 0;
    double x_in = -1.0f;
    double x_out = 0;

    mock_sqrt_setup(0, 0); // zero will be returned if mock_sqrt called

    my_sqrt_error = my_sqrt(x_in, &x_out);

    assert_eq("my_sqrt returned error", 0, my_sqrt_error);
    assert_true("Expected NAN", isnan(x_out));
}

/**
 * Test my_sqrt by mocking the math library sqrt() function.
 */
int main(int argc, char *argv[]) {
    int error = 0;

    // init cunit
    cunit_init();

    test_my_sqrt_4_returns_2();
    test_my_sqrt_nan_has_error();
    test_my_sqrt_inf_has_error();
    test_my_sqrt_negative_returns_nan_and_sqrt_not_called();

    return error;
}
