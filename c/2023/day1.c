#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../aoclibc/aocfile.h"

#define INIT_BUFFSIZE 256

struct intpair {
	int first;
	int second;
};

// Returns 1 if any ints were captured, 0 if no ints were captured.
int getints(char *line, int first, int second) {
	struct intpair ints;
	int offset;

	if (sscanf(line, "%*[^0123456789]%d%n", &ints.first, &offset) == EOF) {
		return 0;	
	}

	while (sscanf(line, "%*[^0123456789%d%n", &ints.second, &numread) != EOF) {

	}

	return 1;
}

int aoc2023_day1(FILE *file, int part) {
	if (part < 1 || part > 2) {
		return -1;
	}

	size_t buffsize = 256;
	char *line = malloc(buffsize);

	if (line == NULL) {
		perror("Error allocating memory for line");
		return -1;
	}

	while ((line = dfgets(line, buffsize, file)) != NULL) {
		if (part == 1) {
			aoc2023_day1_part1(line);
		} else {
			aoc2023_day1_part2(line);
		}
	}

	free(line);

	return 0;
}

struct intpair parse_numwords(char *input, const char **numwords,
	size_t numwords_size
) {
	struct intpair ints = {0, 0};
	int first_found = 0;
	char *skip;

	for (int i = 0; i < numwords_size; i++) {
		const char *substr = strstr(input, numwords[i]);

		if (substr != NULL) {
			ints.first = i + 1;
			strcpy(skip, substr + strlen(numwords[i]));
			first_found = true;
			break;
		}
	}

	if (first_found) {
		for (int i = 0; i < numwords_size; i++) {
			const char *substr = strstr(skip, numwords[i]);

			if (substr != NULL) {
				ints.second = i + 1;
				break;
			}
		}
	} else {
		fprintf(stderr, "No first numberword found in line: %s", input);
	}

	return ints;
}

// TODO Gone about this the wrong way, I need to check for ints AND words
	// I need a first and last occurance of an int/numberword
	/*
		FIRST_INSTANCE
			checkforint()
			if (not found)
				check for nword()
			if found:
				strip the occurance for SECOND
		SECOND/LAST_INSTANCE
			if (first_found)
				checkforint()
				checkfornword
		Need way to keep searching and update until new line etc.
		Maybe delete occurance and repeat until not found anymore
		Also need to track if second has been found at all, etc.
int aoc2023_day1_part2(FILE *file) {
	const char *numwords[] = {
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	size_t numwords_size = sizeof(numwords) / sizeof(numwords[0]);

	char line[1024];
	int concat;
	int total = 0;

	strcpy(line, "4four1eleven4");
	
	struct intpair ints = parse_numwords(line, numwords, numwords_size);
	printf("1: %d 2: %d\n", ints.first, ints.second);

	/*
	while(fgets(line, sizeof(line), file) != NULL) {
		struct intpair ints = parse_numwords(line, numwords, numwords_size);

		char *newline = strchr(line, '\n');

		if (newline != NULL) {
			*newline = '\0';
		}

		concat = ints.first * 10 + ints.second;
		total += concat;

		printf("Line: \"%s\", int.first: %d, int.second: %d, concat: %d, \
			total: %d\n", line, ints.first, ints.second, concat, total);
	}

	return total;
}
*/
