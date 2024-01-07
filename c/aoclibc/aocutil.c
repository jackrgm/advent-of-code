#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_aoc(int argc, char **argv) {
	char *inpart;
	char *inpart_valid;
	int part = -1;

	if(argc < 3) {
		printf("%s: too few arguments (%s <part> <infile>)\n", argv[0],
		argv[0]);
		return -1;
	}

	inpart = argv[1];

	part = strtol(inpart, &inpart_valid, 0);

	if(strcmp(inpart, inpart_valid) == 0) {
		printf("%s: invalid input for part; expected a number\n",
		argv[0]);
		return -2;
	} else if(part < 1 || part > 2) {
		printf("%s: no such part \'%s\'\n", argv[0], argv[1]);
		return -3;
	}

	return part;
}
