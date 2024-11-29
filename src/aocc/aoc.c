#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "common/aoc_common.h"
#include "common/aoc_console.h"

AOC_STATUS buildpath(char **inpath, char *basepath, int day) {
	int reqsize = snprintf(NULL, 0, "%s%d.txt", basepath, day);

	if (reqsize < 0) {
		perror("Error calculating required size for input path");
		return AOC_FAILURE;
	}

	*inpath = malloc(reqsize);

	if (*inpath == NULL) {
		perror("Error allocating size for input path");
		return AOC_FAILURE;
	}

	int res = snprintf(*inpath, reqsize, "%s%d.txt", basepath,
		day);

	if (res < 0 || res >= reqsize) {
		perror("Input path string build failed");
		free(*inpath);
		return AOC_FAILURE;
	}

	return AOC_SUCCESS;
}

int main(int argc, char **argv) {
	const struct aocinput in = aocgetinput(argc, argv);

	if (!in.filepath) {
		perror("bad");
		exit(EXIT_FAILURE);
	}
	
	printf("day: %d, part: %d, filepath: %s\n", in.day, in.part, in.filepath);
	exit(EXIT_SUCCESS);

	// TODO aocvalidateinput(in);

	FILE *file;
	file = fopen(in.filepath, "r");

	if (file == NULL) {
		// TODO Resolve magic number
		char errmsg[256];
		snprintf(errmsg, sizeof(errmsg), "%s: %s: ", argv[0], in.filepath);
		perror(errmsg);
		free(file);
		return EXIT_FAILURE;
	}

	// TODO Call day(part) here

	if(fclose(file)) {
		// TODO Resolve magic number
		char errmsg[256];
		snprintf(errmsg, sizeof(errmsg), "%s: error closing file: ", argv[0]);
		perror("Error closing the file");
	}

	free(file);

	return 0;
}
