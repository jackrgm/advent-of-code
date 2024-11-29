/*
 * Advent of Code 2021
 * Day 2: Dive!
 *
 * Jack Morgan <https://github.com/jackrgm>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dive(FILE *coordinates, int part) {
	int aim = 0;
	int depth = 0;
	char dir[8];
	int dist = 0;
	int horiz = 0;

	rewind(coordinates);

	while(fscanf(coordinates, "%s %d", dir, &dist) != EOF) {
		if(strcmp(dir, "forward") == 0) {
			if(part == 1) {
				horiz += dist;
			} else {
				horiz += dist;
				depth += (aim * dist);
			}
		} else if(strcmp(dir, "down") == 0) {
			if(part == 1) {
				depth += dist;
			} else {
				aim += dist;
			}
		} else if(strcmp(dir, "up") == 0) {
			if(part == 1) {
				depth -= dist;
			} else {
				aim -= dist;
			}
		}
	}

	return horiz * depth;
}


int main(int argc, char *argv[]) {
	int answer = -1;
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
		printf("Answer (part %d): %d\n", part, dive(infile, part));
		fclose(infile);
	} else {
		printf("Error opening file\n");
	}

	return 0;
}
