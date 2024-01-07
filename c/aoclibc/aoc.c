#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aoc.h"

int get_day_part(int argc, char **argv, int *day, int *part) {
	*day = -1;
	*part = -1;

	int inday;
	int inpart;

	// TODO Simplify.
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--day") == 0 || strcmp(argv[i], "-d") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                inday = atoi(argv[++i]);
            } else {
                return AOC_ERR_DAY_NOARG;
            }
        } else if (strcmp(argv[i], "--part") == 0 || strcmp(argv[i], "-p") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                inpart = atoi(argv[++i]);
            } else {
				return AOC_ERR_PART_NOARG;
            }
        } else {
			return AOC_ERR_UNKNOWN;
        }
    }

    if (inday == -1) {
		return AOC_ERR_NODAY;
    }

	*day = inday;

	if (inpart != -1) {
		*part = inpart;
	}

	return AOC_SUCCESS;
}

int validate_day(int day) {
	if (day < 1 || day > 25) {
		return AOC_ERR_DAYRANGE;
	}

	return AOC_SUCCESS;
}
