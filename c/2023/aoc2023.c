#include <stdio.h>
#include <stdlib.h>

#include "../aoclibc/aoc.h"
#include "2023/day1.h"

int buildpath(char **inpath, char *basepath, int day) {
	int reqsize = snprintf(NULL, 0, "%s%d.txt", basepath, day);

	if (reqsize < 0) {
		perror("Error calculating required size for input path");
		return 1;
	}

	*inpath = malloc(reqsize);

	if (*inpath == NULL) {
		perror("Error allocating size for input path");
		return 1;
	}

	int res = snprintf(*inpath, reqsize, "%s%d.txt", basepath,
		day);

	if (res < 0 || res >= reqsize) {
		perror("Input path string build failed");
		free(*inpath);
		return 1;
	}

	return 0;
}

int main(int argc, char **argv) {
	int (*solutions[])(FILE *, int) = {
		aoc2023_day1
	};

	int day;
	int part;

	get_day_part(argc, argv, &day, &part);

	if (validate_day(day) == AOC_ERR_DAYRANGE) {
		fprintf(stderr, "Error: invalid day. Expected number in the range 1-25"
			" but got '%d'.\n", day);
		return EXIT_FAILURE;
	}

	char *inpath;

	// TODO Implement paths or basepath as config file readings
	int result = buildpath(&inpath, "inputs/2023/day", day);

	if (result) {
		perror("Error building input file path string");
		free(inpath);
		return EXIT_FAILURE;
	}

	FILE *file;
	file = fopen(inpath, "r");

	if (file == NULL) {
		printf("%s: Error opening the file.\n", argv[0]);
		free(inpath);
		return EXIT_FAILURE;
	}

	printf("%d\n", solutions[day](file, part));

	if(fclose(file)) {
		perror("Error closing the file");
	}

	free(inpath);

	return 0;
}
