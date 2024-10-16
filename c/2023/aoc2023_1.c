#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aoc2023.h"
#include "../common/aoclib.h"
#include "../common/aocio.h"

#define MAXNUMWORDSTRSIZE 6

enum nwmstatus {NOMATCH, PARTIAL, FULL};

unsigned concatint(unsigned first, unsigned second) {
    unsigned digitshift = 10;

    while(second >= digitshift) {
        digitshift *= 10;
	}

	return first * digitshift + second;
}

enum nwmstatus checknumwordmatch(char *str) {
    const char *numwords[] = {"one", "two", "three", "four", "five", "six",
		"seven", "eight", "nine"};

    int input_len = strlen(str);

    for (int i = 0; i < sizeof(numwords) / sizeof(numwords[0]); i++) {
        int word_len = strlen(numwords[i]);

        if (input_len == word_len && strcmp(str, numwords[i]) == 0) {
            return FULL;
        }
        
        if (input_len < word_len && strncmp(str, numwords[i], input_len) == 0) {
            return PARTIAL;
        }
    }

	return NOMATCH;
}

int nwtoi(const char *str) {
	if (strcmp(str, "one") == 0) return 1;
	else if (strcmp(str, "two") == 0) return 2;
	else if (strcmp(str, "three") == 0) return 3;
	else if (strcmp(str, "four") == 0) return 4;
	else if (strcmp(str, "five") == 0) return 5;
	else if (strcmp(str, "six") == 0) return 6;
	else if (strcmp(str, "seven") == 0) return 7;
	else if (strcmp(str, "eight") == 0) return 8;
	else if (strcmp(str, "nine") == 0) return 9;
	else return -1;
}

struct aoc_answer aoc2023_day1(FILE *file, int part) {
	struct aoc_answer ans = {AOC_SUCCESS, 0};

	if (part < 1 || part > 2 || file == NULL) {
		ans.state = AOC_BADINPUT;
		return ans;
	}

	rewind(file);

	char c;
	unsigned first = 0, firstfound = 0, second = -1;

	int i = 0;
	char tmpstr[MAXNUMWORDSTRSIZE];

	while ((c = fgetc(file)) != EOF) {
		if (isdigit(c)) {
			if (!firstfound) {
				first = c - '0';
				firstfound++;
			} else {
				second = c - '0';
			}
		}

		if (part == 2 && isalpha(c)) {
			tmpstr[i] = c;
			tmpstr[i+1] = '\0';

			switch (checknumwordmatch(tmpstr)) {
				case NOMATCH:
					tmpstr[0] = '\0';
					i = 0;
					break;
				case PARTIAL:
					i++;
					break;
				case FULL:
					if (!firstfound) {
						first = nwtoi(tmpstr);
						firstfound++;
					} else {
						second = nwtoi(tmpstr);
					}

					tmpstr[0] = '\0';
					i = 0;
			}
		}

		if (c == '\n') {
			if (second == -1) {
				second = first;
			}

			ans.val += concatint(first, second);
			firstfound = 0;
			second = -1;
		}
	}

	return ans;
}
