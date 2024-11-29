/*
 * Advent of Code 2021
 * Day 1: Sonar Sweep
 *
 * Jack Morgan <https://github.com/jackrgm>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_depth_magnitude(FILE *readings, int part) {
	int current = 0;
	int magnitude = 0;
	int previous = 0;
	int loopcount = 0;
	int measure_win[3];

	rewind(readings);

	while(fscanf(readings, "%d", &current) != EOF) {
		if(part == 1) {
			if(loopcount == 0) {
				loopcount = 1;
				previous = current;
			} else {
				if(current > previous) {
					magnitude++;
				}
				previous = current;
			}
		} else if(part == 2) {
			/*
			 * Three-measurement sliding window; remove value at [head], shift
			 * items toward [head], add new value at [tail], capture as the
			 * latest three-measurement window, compare current window to old
			 * window, repeat until EOF.
			 */
			if(loopcount <= 2) {
				measure_win[loopcount] = current;

				if(loopcount == 2) {
					previous = measure_win[0] + measure_win[1] + measure_win[2];
				}

				loopcount++;
			} else {
				measure_win[0] = measure_win[1];
				measure_win[1] = measure_win[2];
				measure_win[2] = current;

				if(loopcount > 2) {
					if((measure_win[0] + measure_win[1] + measure_win[2]) >
					previous) {
						magnitude++;
					}
				}
				
				previous = measure_win[0] + measure_win[1] + measure_win[2];
			}
		}
	}

	return magnitude;
}


int main(int argc, char *argv[]) {
	char *filepath = argv[2];
	FILE *infile;
	int part = 0;
	char *puzzle_part = argv[1];
	char *puzzle_part_check;

	if(argc < 3) {
		printf("Error: too few arguments\n");
		printf("Usage: day1 <part> <filepath>\n");
		printf("Example (to use part 2): day1 2 ./input\n");
		return 1;
	}

	part = strtol(puzzle_part, &puzzle_part_check, 0);

	if(strcmp(puzzle_part, puzzle_part_check) == 0) {
		printf("Error: Invalid input for part\n");
		return 1;
	}
	else if(part != 1 && part != 2) {
		printf("Error: No such part \'%d\'\n", part);
		return 1;
	}

	infile = fopen(filepath, "r");
	
	if(infile != NULL) {
		printf("Answer (part %d): %d\n", part, get_depth_magnitude(infile, part));
		fclose(infile);
	} else {
		printf("Error opening file\n");
	}

	return 0;
}
