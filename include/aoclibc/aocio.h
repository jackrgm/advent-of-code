#ifndef AOCIO_H
#define AOCIO_H

#include <stdio.h>

/* Dynamic fgets. Returns NULL on error. Call free(line) later. */
char *dfgets(char *line, size_t buffsize, FILE *stream);

#endif
