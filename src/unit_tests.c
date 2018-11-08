/**
 * CS 4900
 * Unit testing for quad solver.
 */


/**
 * Description:
 *  Unit testing for quad solver, using cunit.
 */


// Import headers.
#include <CUnit/Basic.h>
#include "compute.h"
#include "helper.h"


// Method Declaration.
void test_computation_struct();
void test_x_plus_computation();
void test_x_minus_computation();


/**
 * Program's main.
 * Initializes and runs program.
 *
 * See http://cunit.sourceforge.net for CUnit documentation.
 */
int main(int argc, char* argv[]) {

    // COMPUTATION_STRUCT *a_struct = computation_struct_new(5.55);
    // computation_struct_free(a_struct);

    // Initialize CUnit registry and check for errors.
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Add a suite to registry.
    // First 0 is initialization method. Second 0 is teardown method. 0 because currently undefined.
    CU_pSuite test_suite = CU_add_suite("quad_solver_suite", 0, 0);

    // Test that suite was added successfully.
    if (test_suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Now add tests to given suite.
    if ((CU_add_test(test_suite, "test_computation_struct", test_computation_struct) == NULL) ||
        (CU_add_test(test_suite, "test_x_plus_computation", test_x_plus_computation) == NULL) ||
        (CU_add_test(test_suite, "test_x_minus_computation", test_x_minus_computation) == NULL)) {

        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run tests with basic settings.
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}


/**
 * Tests that the computation struct will create and free properly.
 */
void test_computation_struct(void) {
    float a_float;
    double a_double;
    COMPUTATION_STRUCT *a_struct;

    printf("\n");

    // Test with value "0".
    feclearexcept(FE_ALL_EXCEPT);   // Removes possible lingering floating point exceptions.
    a_float = 0;
    a_struct = computation_struct_new(a_float);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_float, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "0.000000");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    CU_ASSERT_EQUAL(a_struct->rounding_error, 0);
    computation_struct_free(a_struct);

    // Test with value "1".
    feclearexcept(FE_ALL_EXCEPT);   // Removes possible lingering floating point exceptions.
    a_float = 1;
    a_struct = computation_struct_new(a_float);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_float, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "1.000000");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    CU_ASSERT_EQUAL(a_struct->rounding_error, 0);
    computation_struct_free(a_struct);

    // Test with value "-1".
    feclearexcept(FE_ALL_EXCEPT);   // Removes possible lingering floating point exceptions.
    a_float = -1;
    a_struct = computation_struct_new(a_float);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_float, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "-1.000000");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    CU_ASSERT_EQUAL(a_struct->rounding_error, 0);
    computation_struct_free(a_struct);

    // Test with value "5.55".
    feclearexcept(FE_ALL_EXCEPT);   // Removes possible lingering floating point exceptions.
    a_float = 5.55;
    a_struct = computation_struct_new(a_float);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_float, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "5.550000");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    CU_ASSERT_EQUAL(a_struct->rounding_error, 0);
    computation_struct_free(a_struct);

    // Test with value "-5.55".
    feclearexcept(FE_ALL_EXCEPT);   // Removes possible lingering floating point exceptions.
    a_float = -5.55;
    a_struct = computation_struct_new(a_float);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_float, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "-5.550000");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    CU_ASSERT_EQUAL(a_struct->rounding_error, 0);
    computation_struct_free(a_struct);

    // Test with value "Infinity".
    feclearexcept(FE_ALL_EXCEPT);   // Removes possible lingering floating point exceptions.
    a_float = INFINITY;
    a_struct = computation_struct_new(a_float);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_TRUE(isinf(a_struct->x));
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "inf");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    CU_ASSERT_EQUAL(a_struct->rounding_error, 0);
    computation_struct_free(a_struct);

    // Test with value "-Infinity".
    feclearexcept(FE_ALL_EXCEPT);   // Removes possible lingering floating point exceptions.
    a_float = -INFINITY;
    a_struct = computation_struct_new(a_float);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_TRUE(isinf(a_struct->x));
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "-inf");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    CU_ASSERT_EQUAL(a_struct->rounding_error, 0);
    computation_struct_free(a_struct);

    // Test with value "NaN".
    feclearexcept(FE_ALL_EXCEPT);   // Removes possible lingering floating point exceptions.
    a_float = NAN;
    a_struct = computation_struct_new(a_float);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_TRUE(isnan(a_struct->x));
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "Imaginary");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 0);
    CU_ASSERT_EQUAL(a_struct->rounding_error, 0);
    computation_struct_free(a_struct);

    // Test with value "1.23456789876543210". Should round.
    feclearexcept(FE_ALL_EXCEPT);   // Removes possible lingering floating point exceptions.
    a_double = 1.23456789876543210;
    a_float = (float) a_double;
    a_struct = computation_struct_new(a_float);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_float, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "1.234568");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    // TODO: Should this fail? I'm not very familiar with the floating point exceptions but I think it should.
    CU_ASSERT_EQUAL(a_struct->rounding_error, 1);
    computation_struct_free(a_struct);
}


/**
 * Tests that the computation struct will create and free properly.
 * Note: Only valid input should make it to this method. Thus don't test with bad a/b/c values.
 */
void test_x_plus_computation(void) {
    COMPUTATION_STRUCT *a_struct;

    printf("\n");

    // a=2, b=3, c=1.
    a_struct = calculate_x_plus(2, 3, 1);
    CU_ASSERT_DOUBLE_EQUAL(-0.5, a_struct->x, 0.01);
    computation_struct_free(a_struct);

    // a=-4, b=-7, c=-3.
    a_struct = calculate_x_plus(-4, -7, -3);
    CU_ASSERT_DOUBLE_EQUAL(-1, a_struct->x, 0.1);
    computation_struct_free(a_struct);

    // a=1.5788, b=14.0789, c=3.212.
    a_struct = calculate_x_plus(1.5788, 14.0789, 3.212);
    CU_ASSERT_DOUBLE_EQUAL(-0.234298, a_struct->x, 0.000001);
    computation_struct_free(a_struct);

    // a=-6.54, b=59, c=2.7.
    a_struct = calculate_x_plus(-6.54, 59, 2.7);
    CU_ASSERT_DOUBLE_EQUAL(-0.045532, a_struct->x, 0.000001);
    computation_struct_free(a_struct);

    // a=1, b=1, c=1.
    a_struct = calculate_x_plus(1, 1, 1);
    CU_ASSERT_TRUE(isnan(a_struct->x));
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "Imaginary");
    computation_struct_free(a_struct);
}


/**
 * Tests that the computation struct will create and free properly.
 * Note: Only valid input should make it to this method. Thus don't test with bad a/b/c values.
 */
void test_x_minus_computation(void) {
    COMPUTATION_STRUCT *a_struct;

    printf("\n");

    // a=2, b=3, c=1.
    a_struct = calculate_x_minus(2, 3, 1);
    CU_ASSERT_DOUBLE_EQUAL(-1, a_struct->x, 0.1);
    computation_struct_free(a_struct);

    // a=-4, b=-7, c=-3.
    a_struct = calculate_x_minus(-4, -7, -3);
    CU_ASSERT_DOUBLE_EQUAL(-0.75, a_struct->x, 0.001);
    computation_struct_free(a_struct);

    // a=1.5788, b=14.0789, c=3.212.
    a_struct = calculate_x_minus(1.5788, 14.0789, 3.212);
    CU_ASSERT_DOUBLE_EQUAL(-8.683170, a_struct->x, 0.000001);
    computation_struct_free(a_struct);

    // a=-6.54, b=59, c=2.7.
    a_struct = calculate_x_minus(-6.54, 59, 2.7);
    CU_ASSERT_DOUBLE_EQUAL(9.066939, a_struct->x, 0.000001);
    computation_struct_free(a_struct);

    // a=1, b=1, c=1.
    a_struct = calculate_x_minus(1, 1, 1);
    CU_ASSERT_TRUE(isnan(a_struct->x));
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "Imaginary");
    computation_struct_free(a_struct);

}
