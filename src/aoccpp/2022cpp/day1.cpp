/*
Advent of Code 2022
Day 1: Calorie Counting

https://adventofcode.com/2022/day/1
*/

#include <fstream>
#include <iostream>
#include <string>

int inventoryCalories(std::string filename, int part) {
	int current = 0;
	int highest = 0;
	std::fstream file;

	// Used in part 2.
	int top_1 = -1;
	int top_2 = -2;
	int top_3 = -3;

	file.open(filename);

	if (!file.is_open()) {
		std::cerr << "Error: can't open file (is filename correct?)\n";
		std::cerr << "Filename was: \"" << filename << "\".\n";
	}

	std::string line;

	// Read the file, line by line, calculating the highest set(s) as we go.
	while(getline(file, line)) {
		// Determine if the set is the highest so far (discard the set after).
		if (line == "" || file.eof()) {
			if (current > highest) {
				highest = current;
			}
				
			current = 0;

			// Part 2: update the top 3 rankings if necessary.
			if (part == 2) {
				if (highest > top_1) {
					top_3 = top_2;
					top_2 = top_1;
					top_1 = highest;
				} else if (highest > top_2) {
					top_3 = top_2;
					top_2 = highest;
				} else if (highest > top_3) {
					top_3 = highest;
				}

				highest = 0;
			}
		} else {
			current += std::stoi(line);
		}
	}

	if (part == 1) {
		return highest;
	} else {
		return (top_1 + top_2 + top_3);
	}
}

void printUsage(std::string progName) {
		std::cout << "Usage: " << progName << " <1 | 2> <filename>\n";
}

int main(int argc, char* argv[]) {
	// argc 1 / argv[0] is the program name.
	if (argc < 3) {
		printUsage(argv[0]);
		return 1;
	}

	std::string partnum = argv[1];
	std::string filename = argv[2];

	if (!(partnum == "1" || partnum == "2")) {
		printUsage(argv[0]);
		return 1;
	}

	if (partnum == "1") {
		std::cout << "Part 1: " << inventoryCalories(filename, 1) << "\n";
	} else if (partnum == "2") {
		std::cout << "Part 2: " << inventoryCalories(filename, 2) << "\n";
	} else {
		std::cerr << "Error: unrecognised part number: " << partnum << "\n";
	}
}
