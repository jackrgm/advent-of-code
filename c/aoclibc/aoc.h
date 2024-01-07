#ifndef AOC_H
#define AOC_H

#define AOC_SUCCESS 0

// Argument wasn't supplied with the day option (-d / --day).
#define AOC_ERR_DAY_NOARG 1

// Argument wasn't supplied with the part option (-p / --part).
#define AOC_ERR_PART_NOARG 2

// Unknown option or argument supplied.
#define AOC_ERR_UNKNOWN 3

// Day option (-d / --day) wasn't supplied. 
#define AOC_ERR_NODAY 4

// Day not in the range of 1-25.
#define AOC_ERR_DAYRANGE 5

int get_day_part(int argc, char **argv, int *day, int *part);
int validate_day(int day);

#endif
