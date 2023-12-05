#include <stdio.h>

#include "2023/day1.h"

void run_all() {
	printf("Not yet implemented.\n");
}

void run_solution(int year, int day, int part) {
	printf("Not yet implemented.\n");
}

int main(int argc, char **argv) {
	// TODO Parse arguements (-a/--all, -d2021.25.2, etc.)
	// TODO Supply file path as arg

	FILE *file;
	file = fopen("inputs/2023/day1.txt", "r");

	if (file == NULL) {
		printf("%s: Error opening the file.\n", argv[0]);
		return 1;
	}

	printf("2023 DAY 1 PART 2: %d\n", aoc2023_day1_part2(file));

	fclose(file);

	return 0;
}
