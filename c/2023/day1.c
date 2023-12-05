#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int aoc2023_day1_part1(FILE *file) {
	rewind(file);

	int ch;
	int concat;
	int total = 0;
	int first = 0;
	int second = 0;
	bool is_first = true;
	bool second_set = false;

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

	return total;
}

int aoc2023_day1_part2(FILE *file) {
	int words = 9;
	char wordnums[words][6];

	struct word_numbers {
		char word[6];
		int num;
	};

	struct word_numbers numlist[9];

	strcpy(numlist[0].word, "one");
	strcpy(numlist[1].word, "two");
	strcpy(numlist[2].word, "three");
	strcpy(numlist[3].word, "four");
	strcpy(numlist[4].word, "five");
	strcpy(numlist[5].word, "six");
	strcpy(numlist[6].word, "seven");
	strcpy(numlist[7].word, "eight");
	strcpy(numlist[8].word, "nine");

	numlist[0].num = 1;
	numlist[1].num = 2;
	numlist[2].num = 3;
	numlist[3].num = 4;
	numlist[4].num = 5;
	numlist[5].num = 6;
	numlist[6].num = 7;
	numlist[7].num = 8;
	numlist[8].num = 9;

	char line [1024];

	int concat;
	int total = 0;
	int first = 0;
	int second = 0;
	bool is_first = true;
	bool second_set = false;

	while(fgets(line, sizeof(line), file) != NULL) {
		for (int i = 0; i < words; ++i) {
			if (strstr(line, numlist[i].word) != NULL) {
				// Match.
				if (is_first) {
					is_first = false;
					first = numlist[i].num;
				} else {
					second = numlist[i].num;
					second_set = true;
				}
			}
		}
	}

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

	return total;
}
