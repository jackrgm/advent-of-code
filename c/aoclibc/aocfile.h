#ifndef AOCFILE_H
#define AOCFILE_H

#include <stdio.h>

/* Dynamic fgets. Returns NULL on error. Call free(line) later. */
char *dfgets(char *line, size_t buffsize, FILE *restrict stream);

#endif
