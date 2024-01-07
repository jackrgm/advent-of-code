#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dfgets(char *line, size_t buffsize, FILE *restrict stream) {
	size_t len = 0;

	while (fgets(line + len, buffsize, stream) != NULL) {
		len = strlen(line);

		if (len == 0) {
			return NULL;
		}

		if (line[len - 1] == '\n') {
			return line;
		}

		buffsize *= 2;
		line = realloc(line, buffsize);

		if (line == NULL) {
			return NULL;
		}
	}

	return NULL;
}
