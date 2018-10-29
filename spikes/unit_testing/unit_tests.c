/**
 * CS 4900
 * Unit testing spike.
 */


/**
 * Description:
 *  Spike to test basic unit testing, using CUnit.
 */


// Import headers.
#include <ctype.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dummy_functions.h"


// Method Declaration.
void basic_test();
void test_dummy_functions();


/**
 * Program's main.
 * Initializes and runs program.
 *
 * See http://cunit.sourceforge.net/example.html for another example of setting up CUnit.
 */
int main(int argc, char* argv[]) {

    // Initialize CUnit registry and check for errors.
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Add a suite to registry.
    // First 0 is initialization method. Second 0 is teardown method. 0 because currently undefined.
    CU_pSuite test_suite = CU_add_suite("basic_test_suite", 0, 0);

    // Test that suite was added successfully.
    if (test_suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Now add tests to given suite.
    if ((CU_add_test(test_suite, "basic_test", basic_test) == NULL) ||
        (CU_add_test(test_suite, "dummy_functions", test_dummy_functions) == NULL)) {
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
 * A test to examine CUnit functionality using trivial tests.
 * To see all possible assertion types, see http://cunit.sourceforge.net/doc/writing_tests.html.
 */
void basic_test(void) {
    // Various assertions that values are equal or not equal.
    CU_ASSERT_EQUAL(1, 1);
    CU_ASSERT_NOT_EQUAL(1, 2);
    CU_ASSERT_EQUAL('a', 'a');
    CU_ASSERT_NOT_EQUAL('a', 'b');
    CU_ASSERT_EQUAL("abc", "abc");
    CU_ASSERT_NOT_EQUAL("ABC", "abc");

    // Various assertions that values are true (non-zero) or false (zero).
    CU_ASSERT_TRUE(1);
    CU_ASSERT_FALSE(0);
    CU_ASSERT_FALSE(NULL);
}


/**
 * Tests return values of functions in dummy_functions.c.
 */
void test_dummy_functions(void) {
    CU_ASSERT_EQUAL(2, basic_add(1, 1));
    CU_ASSERT_EQUAL(0, basic_subtract(1, 1));
}
