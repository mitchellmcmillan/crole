/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "tests.h"

#include <inttypes.h>

void run_tests(test *tests)
{
    for (unsigned int i = 0; tests[i]; i++)
        (*tests[i])();
}

int main()
{
    test tests[] = {
    	&test_dllist,
    	&test_ref,
        &test_vec,
    	NULL
    };
    
    run_tests(tests);
    
	printf("\n%s%"PRId64"/%"PRId64" tests passed\n" ANSI_COLOUR_RESET,
		tests_failed ? ANSI_COLOUR_RED : ANSI_COLOUR_GREEN, tests_passed, tests_passed + tests_failed);
    
    return tests_failed ? 1 : 0;
}
