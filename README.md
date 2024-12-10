# JackRGM's Advent of Code Solutions

            _\/_ 
             /\    JackRGM's
             /\         _______    _______ 
            /  \       (  ___  )  (  ____ \
           o/~*\o      | (   ) |  | (    \/
           /o   \      | |   | |  | |      
          /~~*~*~\o    | |   | |  | |      
         o/    o \     | |   | |  | |      
         /~o~*~~~~\    | (___) |  | (____/\
        /__*__o__*_\o  (_______)  (_______/
        o  ..||..
           \====/             Solutions
            \__/

[Advent of Code](https://adventofcode.com/2023/about) (AOC) is a popular, well-established, Christmas-themed event which releases a set of programming puzzles each December. Thousands of participants attempt, solve, and share solutions to these puzzles as a way to enjoy and expand their knowledge of programming.

This repository is a collection of all my solutions to AOC puzzles, in multiple languages.

## Executables

Solutions are organised by languages, and each language has its own executable.

* `aocc` - Written in C.
* `aoccpp` - Written in C++.
* `aocjava` - Written in Java.
* `aocpy` - Written in Python.

These executables are used to run specific solutions, all solutions, or the latest solution (default behaviour without arguments).

## Building and Running

To build `aocc` and `aoccpp` from a Unix command line, run:

    mkdir -p build && cmake -B build && cmake --build build

To run, for example, the solution for 2024, day 1, part 1, in C:

    ./build/aocc -y 2024 -d 1 -p 1

## Options

* `-y` / `--year` - Specify the year. If ommited, it will use the year of the most recent solution.
* `-d` / `--day` - Specify the day. If ommited, it will use the day of the most recent solution (for the specified year).
* `-p` / `--part` - Specify the solution part. If ommited, it will use part 2 if it's available, otherwise it will use part 1.
