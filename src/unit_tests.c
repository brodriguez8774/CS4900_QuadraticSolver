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
void quad_solver_tests();
void test_computation_struct();


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
    if (CU_add_test(test_suite, "test_computation_struct", test_computation_struct) == NULL) {
    // if (CU_add_test(test_suite, "quad_solver_tests", quad_solver_tests) == NULL) {
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
    COMPUTATION_STRUCT *a_struct;

    printf("\n");

    // float float_1 = 5.5500;
    // float float_2 = 5.5509;
    // CU_ASSERT_DOUBLE_EQUAL(float_1, float_2, 0.001);

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
    a_float = 1.23456789876543210;
    a_struct = computation_struct_new(a_float);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_float, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "1.234568");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    // TODO: Should this fail? I'm not very familiar with the floating point exceptions but I think it should.
    CU_ASSERT_EQUAL(a_struct->rounding_error, 1);
    computation_struct_free(a_struct);
}
