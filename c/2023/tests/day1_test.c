#include <stdio.h>

#include "test_common.h"
#include "../day1.h"

void t_day1_single_line_test() {
	FILE *file = tmpfile();

	if (file == NULL) {
		fprintf(stderr, "Test error: tmpfile error (file: %s, line: %d)\n",
			__FILE__, __LINE__);
		return;
	}

	fprintf(file, "a1b2c3d4e5f");

	TEST(aoc2023_day1(file, 1) == 15);

	fclose(file);
}

void t_day1_four_line_test() {
	FILE *file = tmpfile();

	if (file == NULL) {
		fprintf(stderr, "Test error: tmpfile error (file: %s, line: %d)\n",
			__FILE__, __LINE__);
		return;
	}

	fprintf(file, "1abc2\n"
		"pqr3stu8vwx\n"
		"a1b2c3d4e5f\n"
		"treb7uchet\n");

	TEST(aoc2023_day1(file, 1) == 142);

	fclose(file);
}

void t_day1() {
	t_day1_single_line_test();
	t_day1_four_line_test();
}

void main() {
	t_day1();
}
