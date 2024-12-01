#include <cstdlib>
#include <iostream>
#include <vector>
#include "aoccpp/2024.h"

namespace AOCCPP {
	int parseinput(std::ifstream& infile, int year, int day, int part) {
		switch (year) {
			case 2024: {
				AOC2024 aoc2024;
				return aoc2024.runsolution(infile, day - 1, part);
			}
			default:
				std::cerr << "Year " << year << " not supported.\n";
				return -1;
		}
	}
}

using namespace AOCCPP;

int main(int argc, char **argv) {
	// TODO Parameterise file name
	std::ifstream infile("inputs/2021_1.txt");

	if (!infile.is_open()) {
		std::cerr << "Error opening file\n";
		return EXIT_FAILURE;
	}

	AOCCPP::parseinput(infile, 2024, 1, 1);
	infile.close();

	return EXIT_SUCCESS;
}
