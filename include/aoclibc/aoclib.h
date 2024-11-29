#ifndef AOCLIB_H
#define AOCLIB_H

/* Consistent values for functions that return status codes. SYSERR covers
general system issues like out of memory. NOTIMPL covers incomplete code. */
enum aoc_status {
	AOC_SUCCESS = 0,
	AOC_FAILURE = -1,
	AOC_BADINPUT = -2,
	AOC_SYSERR = -3,
	AOC_NOTIMPL = -4
};

struct aoc_answer {
	enum aoc_status state;
	unsigned val;
};

#endif
