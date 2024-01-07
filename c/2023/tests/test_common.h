#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <stdio.h>

#define TEST(condition) \
    do {\
        if (!(condition)) {\
            fprintf(stderr, "Test failed: %s, file %s, line %d\n", #condition, \
			__FILE__, __LINE__);\
        }\
    } while (0)

#endif
