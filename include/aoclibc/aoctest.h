#ifndef AOCTEST_H
#define AOCTEST_H

#include <stdio.h>

#define TESTINT(expected, actual) \
    do {\
		int exp = (expected);\
		int act = (actual);\
        if (exp != act) {\
            fprintf(stderr, "Test failed: %s\n"\
				"\tExpected: %d, actual: %d\n"\
				"\tIn file \"%s\" at line %d\n",\
				__func__, exp, act, __FILE__, __LINE__);\
        }\
    } while (0)

#endif
