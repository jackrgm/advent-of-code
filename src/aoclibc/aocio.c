#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aocio.h"

char *dfgets(char *str, size_t buffsize, FILE *stream) {
	size_t len = 0;

	while (fgets(str + len, buffsize, stream) != NULL) {
		len = strlen(str);

		if (len == 0) {
			return NULL;
		}

		if (str[len - 1] == '\n') {
			return str;
		}

		buffsize *= 2;
		// TODO NULL check etc - check ChatGPT for feedback
		str = realloc(str, buffsize);

		if (str == NULL) {
			return NULL;
		}
	}

	return NULL;
}
