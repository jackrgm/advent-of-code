/*
 * Advent of Code 2020
 * Day 1
 * Jack Morgan (https://github.com/jackrgm)
 */

#include <fstream>
#include <iostream>
#include <unordered_map>

void part1() {
	int x;
	std::fstream report;
	std::unordered_map<int,bool> expenses;

	report.open("input_day1.txt", std::ios::in);

	if (report.is_open()) {
		while (report >> x) {
			// don't need to id both entries; one will give us the other
			if (expenses[x]) {
				std::cout << "Part 1 answer: " << x * (2020 - x) << "\n";
				break;
			} else {
				// mark the first then do the math when we find the first again
				expenses[2020-x] = true;
			}
		}

		report.close();
	} else {
		std::cout << "Error: input file (./input_day1.txt) not found\n";
	}
}

void part2() {
	// TODO
}

int main() {
	part1();
	part2();

	return 0;
}
