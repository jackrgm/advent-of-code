#ifndef AOCCON_H
#define AOCCON_H

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

// If part isn't provided or is invalid, it defaults to 1.
int get_day_part(int argc, char **argv, int *day, int *part);

int validate_day(int day);

struct aocinput {
	int day;
	int part;
	char *filepath;
	char *configpath;
};

struct aocinput aocgetinput(int argc, char **argv);
int aocparseint(char opt, const char *optarg, const char *progname);
void aocprintusage(const char *progname);

#endif
