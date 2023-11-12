/*
 * Advent of Code 2020
 * Day 1: Report Repair
 *
 * Jack Morgan <https://github.com/jackrgm>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_expenses(FILE *report) {
	int count = 0;

	rewind(report);

	while(!feof(report)) {
		if(fgetc(report) == '\n') {
			count++;
		}
	}

	return count;
}

int * get_expenses(FILE *report, int count) {
	char buff[5];
	char *buffcheck;
	int *expenses = malloc(sizeof(int)*count);

	if(!expenses) {
		return NULL;
	}

	rewind(report);

	for (int i = 0; i < count; i++) {
		//fgets(buff, 5, report);
		//expenses[i] = strtol(buff, &buffcheck, 10);

		fscanf(report, "%d", &expenses[i]);

		printf("Expense [i]: %d\n", expenses[i]);
		
		if(strcmp(buff, buffcheck) == 0) {
			return NULL;
		}
	}

	return expenses;
}

/*
 * Returns the puzzle answer, or -1 otherwise (i.e. no matches for that input).
 */
int fix_expenses(FILE *report, int *expenses, int count, int part) {
	rewind(report);

	/*
	 * Starting with the first expense in the report (selection; i), check it
	 * against all proceeding expenses in the report (comparates; j); if there's
	 * no suitable comparate, the next expense in the list becomes the
	 * selection.
	 *
	 * Part 2 follows the same trend, adding a second comparate (k).
	 */
	for(int i = 0; i < count; i++) {
		for(int j = 0; j < count; j++) {
			if(part == 1) {
				if(expenses[i] + expenses[j] == 2020) {
					return (expenses[i] * expenses[j]);
				}
			}

			if(part == 2) {
				for(int k = 0; k < count; k++) {
					if(expenses[i] + expenses[j] + expenses[k] == 2020) {
						return (expenses[i] * expenses[j] * expenses[k]);
					}
				}
			}
		}
	}

	return -1;
}

int main(int argc, char *argv[]) {
	int answer = -1;
	int count = 0;
	int *expenses;
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
		count = count_expenses(infile);
		printf("%d entries found in expense report\n", count);
		expenses = get_expenses(infile, count);
		
		if(expenses) {
			answer = fix_expenses(infile, expenses, count, part);
			if(answer == -1) {
				printf("No fixes found for expense report (no matching entries "
				"that make '2020' or problems computing entries)\n");
			} else {
				printf("Answer (part %d): %d\n", part, answer);
			}
		} else {
			printf("Error: problem getting expenses from report\n");
			free(expenses);
			return 1;
		}
		free(expenses);
		fclose(infile);
	} else {
		printf("Error opening file\n");
	}

	return 0;
}
