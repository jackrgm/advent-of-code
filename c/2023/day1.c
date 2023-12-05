#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int aoc2023_day1_part1(FILE *file) {
	int ch;
	int concat;
	int total = 0;

	bool is_first = true;
	bool second_set = false;

	int first = 0;
	int second = 0;

	while ((ch = getc(file)) != EOF) {
        if (isdigit(ch)) {
			if (is_first) {
					is_first = false;
					first = ch - '0';
			} else {
				second = ch - '0';
				second_set = true;
			}
        } else if (ch == '\n') {
			// If a second integer isn't found, use the first for concatenation.
			if (!second_set) {
				second = first;
			}

			concat = first * 10 + second;
			total += concat;

			is_first = true;
			second_set = false;

			concat = 0;
			first = 0;
			second = 0;
        }
    }

    concat = first * 10 + second;
    total += concat;

	return total;
}
