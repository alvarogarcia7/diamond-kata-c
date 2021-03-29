#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>

#include "../prod.h"

static void single_letter(void **state)
{
    char **result = diamond("B");

    assert_string_equal("B", result[0]);
    assert_null(result[1]);

    free(result);
}

static void two_letters(void **state)
{
    char **result = diamond("AB");

    assert_string_equal(" A ", result[0]);
    assert_string_equal("B B", result[1]);
    assert_string_equal(" A ", result[2]);
    assert_null(result[3]);

    free(result);
}

static void three_letters(void **state)
{
    char **result = diamond("ABC");

    assert_string_equal("  A  ", result[0]);
    assert_string_equal(" B B ", result[1]);
    assert_string_equal("C   C", result[2]);
    assert_string_equal(" B B ", result[3]);
    assert_string_equal("  A  ", result[4]);
    assert_null(result[3]);

    free(result);
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
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
