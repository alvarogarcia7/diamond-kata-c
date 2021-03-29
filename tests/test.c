#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>

#include "../prod.h"

static void single_letter(void **state)
{
    char *result = diamond("A");

    assert_string_equal("A", result);

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
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
