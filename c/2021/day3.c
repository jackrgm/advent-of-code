/*
 * Advent of Code 2021
 * Day 3: Binary Diagnostic
 *
 * Jack Morgan <https://github.com/jackrgm>
 */

#include "../aoclib-c/aocutil.h"
#include "../aoclib-c/aocfile.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO Galaxy brain moment? */
	/* Make a 2D array of chars; transforming file contents to a 2Darr grid */
	/* columns = the first bit thing to compute to gamma rate using commonbit*/
	/* etc, you now the drill */

	/* I could probably heavily simplify all this by using fgetc to build the
	   2D array */
	/* int iter = 0;
		while not EOF; bla = fgetc(file)
		if bla == \n
			iter = 0*/
		
/* Compute the power consumption. */
static int cmppowcon(FILE *report, int size) {
	/*int bit_0 = 0;
	int bit_1 = 1;
	int columns = count_columns(report);
	int epsilon[columns];
	int epsilon_dec = 0;
	char in;
	int iter_bin = 0;
	int iter_col = 0;
	int iter_row = 0; 
	int lines = countlin(report);
	int gamma[columns];
	int gamma_dec = 0;*/
	int gamma_dec;
	char *gamma;
	int epsilon_dec;
	char *epsilon;
	int iterbin = 0;
	int powcon = -1;

	rewind(report);
/*
	while((in = fgetc(report)) != EOF) {
		if(in != '\n') {
			int x = in - '0';
			diags[iter_row][iter_col] = x;
			iter_col++;
		} else {
			iter_col = 0;
			iter_row++;
		}
	}

	for(int i = 0; i < columns; i++) {
		for(int j = 0; j < lines; j++) {
			if(diags[j][i] == 0) {
				bit_0++;
			} else {
				bit_1++;
			}
		}

		if(bit_0 > bit_1) {
			gamma[i] = 0;
			epsilon[i] = 1;

		} else {
			gamma[i] = 1;
			epsilon[i] = 0;
		}
		
		bit_0 = 0;
		bit_1 = 0;
	}*/

	/* Convert gamma and epsilon binary codes to decimal. */
	for(int i = (strlen(gamma) - 1); i >= 0; i--) {
		gamma_dec += (pow(2, iterbin) * gamma[i]);
		epsilon_dec += (pow(2, iterbin) * epsilon[i]);
		iterbin++;
	}

	return gamma_dec * epsilon_dec;
}

/*
 * Compute the life support rating <TODO ...>
 */
static int cmplifesup(FILE *report) {
	return -1337;
}

int part_1(FILE *infile, int *answer) {
	size_t lines;
	char **report;

	*answer = 0;
	lines = count_lines(infile);
	report = malloc(lines * sizeof(char*));

	if(!report) {
		return 1;
	}

	if(getlss(infile, report, lines) == 1) {
		return 2;
	}
	
	/* *answer = cmppowcon(report); */

	for(int i = 0; i < lines; i++) {
		printf("%s\n", report[i]);
		free(report[i]);
	}

	free(report);
	
	printf("Lines: %d\n", lines);

	*answer = 1337;

	return 0;
}

int part_2(FILE *infile, int *answer) {
	*answer = 0;
	//int lifesup;
	//cmplifesup(infile);
	return 0;
}

int main(int argc, char **argv) {
	int answer = 0;
	int part = -1;
	int status = 1;

	part = parse_aoc(argc, argv);

	if(part < 0) {
		return 1;
	}

	char *infpath = argv[2];

	FILE *infile = fopen(infpath, "r");
	
	if(infile == NULL) {
		printf("%s: problem finding/opening file\n", argv[0]);
		return 1;
	}

	if(part == 1) {
		switch(part_1(infile, &answer)) {
			case 1:
				printf("%s: problem allocating memory\n", argv[0]);
				break;
			case 2:
				printf("%s: problem reading data from file\n", argv[0]);
				break;
			default:
				status = 0;
		}
	} else {
		switch(part_2(infile, &answer)) {
			case 1:
				printf("%s: some error lol\n", argv[0]);
				break;
			default:
				status = 0;
		}
	}

	fclose(infile);

	if(!status) {
		printf("%d\n", answer);
	}

	return status;
}
