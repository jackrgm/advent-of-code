#include <stdio.h>

size_t count_lines(FILE *infile) {
	size_t count = 0;

	rewind(infile);

	while(!feof(infile)) {
		if(fgetc(infile) == '\n') {
			count++;
		}
	}

	return count;
}

size_t count_columns(FILE *infile) {
	size_t count = 0;

	rewind(infile);

	while(fgetc(infile) != '\n') {
		count++;
	}

	return count;
}

/* TODO use fgets (standard lib) + dynamic buffer */
int getlss(FILE *infile, char **array, int array_size) {
	int iter_lss = 0;
	char buff[13];
	//char *lnbuff = NULL;
	//ssize_t lnlength;
	//size_t lnsize = 0;

	if(!infile) {
		return 1;
	}

	rewind(infile);

	/*
	while((lnlength = getline(&lnbuff, &lnsize, infile)) != -1 ) {
		if(lnbuff[lnlength-1] == '\n') {
			lnbuff[lnlength-1] = '\0';
		}

		array[iter_lss] = strdup(lnbuff);
		iter_lss++;
	}

	free(lnbuff);
	*/

	// https://stackoverflow.com/questions/27326839/how-to-read-input-of-unknown-length-using-fgets
	while(fgets(buff, sizeof(buff), infile) != 0) {

	}

	return 0;
}
