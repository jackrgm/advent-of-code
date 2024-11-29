#! /bin/bash

# Temporary rudimentary test solution; will likely use CMake and an established
# test framework in future.

tmpdir=$(mktemp -d -t tmpdir.XXXXXX)
gcc aoc2023_t1.c ../aoc2023_1.c -o "$tmpdir/aoc2023_t1"
"$tmpdir/aoc2023_t1"
rm -rf "$tmpdir"
