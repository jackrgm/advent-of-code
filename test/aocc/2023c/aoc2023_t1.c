#include <stdio.h>

#include "../../common/aoclib.h"
#include "../../common/aoctest.h"
#include "../aoc2023.h"

void aoc_2023test_1_singleline_part1() {
	FILE *file = tmpfile();

	if (file == NULL) {
		fprintf(stderr, "Test error: tmpfile error (file: %s, line: %d)\n",
			__FILE__, __LINE__);
		return;
	}

	fprintf(file, "aaa1aaatwoaaa3aaafouraaa5aaasix\n");
	rewind(file);

	TESTINT(15, aoc2023_day1(file, 1).val);

	fclose(file);
}

void aoc_2023test_1_officialexample_part1() {
	FILE *file = tmpfile();

	if (file == NULL) {
		fprintf(stderr, "Test error: tmpfile error (file: %s, line: %d)\n",
			__FILE__, __LINE__);
		return;
	}

	fprintf(file, "1abc2\npqr3stu8vwx\na1b2c3d4e5f\ntreb7uchet\n");

	TESTINT(142, aoc2023_day1(file, 1).val);

	fclose(file);
}

void aoc_2023test_1_singleline_part2() {
	FILE *file = tmpfile();

	if (file == NULL) {
		fprintf(stderr, "Test error: tmpfile error (file: %s, line: %d)\n",
			__FILE__, __LINE__);
		return;
	}

	fprintf(file, "aaa1aaatwoaaa3aaafouraaa5aaasix\n");

	TESTINT(16, aoc2023_day1(file, 2).val);

	fclose(file);
}

void aoc_2023test_1_officialexample_part2() {
	FILE *file = tmpfile();

	if (file == NULL) {
		fprintf(stderr, "Test error: tmpfile error (file: %s, line: %d)\n",
			__FILE__, __LINE__);
		return;
	}

	fprintf(file, "two1nine\neightwothree\nabcone2threexyz\nxtwone3four\n"
		"4nineeightseven2\nzoneight234\n7pqrstsixteen\n");

	TESTINT(281, aoc2023_day1(file, 2).val);

	fclose(file);
}

int main() {
	aoc_2023test_1_singleline_part1();
	aoc_2023test_1_officialexample_part1();
	aoc_2023test_1_singleline_part2();
	aoc_2023test_1_officialexample_part2();
}
