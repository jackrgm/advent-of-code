/*
 * Advent of Code (AOC) C Library - File Operations
 * Jack Morgan <https://github.com/jackrgm>
 */

#ifndef AOCFILE_H
#define AOCFILE_H

#include <stdio.h>

/* Returns the number of lines in a given file. */
size_t count_lines(FILE *infile);

/*
 * Returns the number of columns in a given file, assuming the file has a
 * consistent amount of columns for all lines.
 */
size_t count_columns(FILE *infile);

/*
 * Load a list of strings from a file into a given array. The array is assumed
 * empty and any contents will be overriden. Dynamic memory allocation is used
 * when inserting new strings and so the array elements will need to be freed.
 */
int getlss(FILE *infile, char **array, int array_size);

#endif
