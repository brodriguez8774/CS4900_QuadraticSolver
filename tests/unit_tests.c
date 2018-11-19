/**
 * CS 4900
 * Unit testing for quad solver.
 */


/**
 * Description:
 *  Unit testing for quad solver, using cunit.
 */


// Import headers.
#include <fenv.h>
#include <CUnit/Basic.h>
#include "../src/argparse.h"
#include "../src/compute.h"
#include "../src/helper.h"


// Method Declaration.
void test_argparse();
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
    if ((CU_add_test(test_suite, "test_argparse", test_argparse) == NULL) ||
        (CU_add_test(test_suite, "test_computation_struct", test_computation_struct) == NULL)) {

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
 * Tests creation and return values of argparse.
 */
void test_argparse(void) {
    int arg_count = 2;
    char *prologue = "Test Prologue (Title)";
    char *description = "Test Description";
    char *epilogue = "Test Epilogue";

    ARGPARSE *argparse = argparse_new(prologue, description, epilogue, arg_count);
    CU_ASSERT_PTR_NOT_NULL(argparse);
    CU_ASSERT_EQUAL(argparse->prologue, prologue);
    CU_ASSERT_EQUAL(argparse->description, description);
    CU_ASSERT_EQUAL(argparse->epilogue, epilogue);
    CU_ASSERT_EQUAL(argparse->arguments_size, (arg_count + 1));

    argparse_free(argparse);

}


/**
 * Tests that the computation struct will create and free properly.
 */
void test_computation_struct(void) {
    double a_double;
    COMPUTATION_STRUCT *a_struct;

    printf("\n");

    // Test with value "0".
    a_double = 0;
    a_struct = computation_struct_new(a_double);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_double, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "0.0000000000E+00");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    computation_struct_free(a_struct);

    // Test with value "1".
    a_double = 1;
    a_struct = computation_struct_new(a_double);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_double, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "1.0000000000E+00");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    computation_struct_free(a_struct);

    // Test with value "-1".
    a_double = -1;
    a_struct = computation_struct_new(a_double);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_double, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "-1.0000000000E+00");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    computation_struct_free(a_struct);

    // Test with value "5.55".
    a_double = 5.55;
    a_struct = computation_struct_new(a_double);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_double, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "5.5500000000E+00");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    computation_struct_free(a_struct);

    // Test with value "-5.55".
    a_double = -5.55;
    a_struct = computation_struct_new(a_double);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_DOUBLE_EQUAL(a_struct->x, a_double, 0.000001);
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "-5.5500000000E+00");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    computation_struct_free(a_struct);

    // Test with value "Infinity".
    a_double = INFINITY;
    a_struct = computation_struct_new(a_double);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_TRUE(isinf(a_struct->x));
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "INF");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    computation_struct_free(a_struct);

    // Test with value "-Infinity".
    a_double = -INFINITY;
    a_struct = computation_struct_new(a_double);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_TRUE(isinf(a_struct->x));
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "-INF");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 1);
    computation_struct_free(a_struct);

    // Test with value "NaN".
    a_double = NAN;
    a_struct = computation_struct_new(a_double);
    CU_ASSERT_PTR_NOT_NULL(a_struct);
    CU_ASSERT_TRUE(isnan(a_struct->x));
    CU_ASSERT_STRING_EQUAL(a_struct->x_as_string, "Imaginary");
    CU_ASSERT_EQUAL(a_struct->string_needs_free, 0);
    computation_struct_free(a_struct);
}
