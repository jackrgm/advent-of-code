#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "aoccon.h"
#include "aoclib.h"

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
	} else {
		*part = 1;
	}

	return AOC_SUCCESS;
}

int validate_day(int day) {
	if (day < 1 || day > 25) {
		return AOC_ERR_DAYRANGE;
	}

	return AOC_SUCCESS;
}

void aocprintusage(const char *progname) {
	printf("Usage: %s -d day -p part [-f filepath] [-c configpath]\n", progname);
}

int aocparseint(char opt, const char *optarg, const char *progname) {
	char *endptr;

	long value = strtol(optarg, &endptr, 10);

	if (endptr == optarg || *endptr != '\0') {
		fprintf(stderr, "%s: %s: Invalid integer\n", progname, optarg);
		exit(EXIT_FAILURE);
	}

	return (int)value;
}

struct aocinput aocgetinput(int argc, char **argv) {
	struct aocinput in = { -1, -1, NULL, NULL};
	int opt;

	// TODO Somewhere causing segfault
	while ((opt = getopt(argc, argv, "d:p:f:c")) != -1) {
		switch (opt) {
			case 'd':
				in.day = aocparseint('d', optarg, argv[0]);
				break;
			case 'p':
				in.part = aocparseint('p', optarg, argv[0]);
				break;
			case 'f':
				in.filepath = optarg;
				break;
			case 'c':
				// TODO Implement config file reader.
				perror("Config file reading not yet implemented.");
				exit(EXIT_FAILURE);
			default:
				aocprintusage(argv[0]);
		}
	}
}

// TODO Is this still needed?
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
