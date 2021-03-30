#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>

#include "../prod.h"

static void single_letter(void **state)
{
    char **result = diamond_create("B");

    assert_string_equal("B", result[0]);
    assert_null(result[1]);
    diamond_free(result);
}

static void two_letters(void **state)
{
    char **result = diamond_create("AB");

    assert_string_equal(" A ", result[0]);
    assert_string_equal("B B", result[1]);
    assert_string_equal(" A ", result[2]);
    assert_null(result[3]);
    diamond_free(result);
}

static void three_letters(void **state)
{
    char **result = diamond_create("ABC");

    assert_string_equal("  A  ", result[0]);
    assert_string_equal(" B B ", result[1]);
    assert_string_equal("C   C", result[2]);
    assert_string_equal(" B B ", result[3]);
    assert_string_equal("  A  ", result[4]);
    assert_null(result[5]);
    diamond_free(result);
}

static void four_letters(void **state)
{
    char **result = diamond_create("ABCD");

    assert_string_equal("   A   ", result[0]);
    assert_string_equal("  B B  ", result[1]);
    assert_string_equal(" C   C ", result[2]);
    assert_string_equal("D     D", result[3]);
    assert_string_equal(" C   C ", result[4]);
    assert_string_equal("  B B  ", result[5]);
    assert_string_equal("   A   ", result[6]);
    assert_null(result[7]);
    diamond_free(result);
}
static void five_letters(void **state)
{
    char **result = diamond_create("ABCDE");

    assert_string_equal("    A    ", result[0]);
    assert_string_equal("   B B   ", result[1]);
    assert_string_equal("  C   C  ", result[2]);
    assert_string_equal(" D     D ", result[3]);
    assert_string_equal("E       E", result[4]);
    assert_string_equal(" D     D ", result[5]);
    assert_string_equal("  C   C  ", result[6]);
    assert_string_equal("   B B   ", result[7]);
    assert_string_equal("    A    ", result[8]);
    assert_null(result[9]);
    diamond_free(result);
}


/* A test case that does nothing and succeeds. */
static void canary_test(void **state) {
    (void) state; /* unused */
    assert_int_equal(0, 0);
}
int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(canary_test)
            , cmocka_unit_test(single_letter)
            , cmocka_unit_test(two_letters)
            , cmocka_unit_test(three_letters)
            , cmocka_unit_test(four_letters)
            , cmocka_unit_test(five_letters)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
