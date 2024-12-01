#include <iostream>
#include "aoccpp/yearbase.h"

namespace AOCCPP {
	YearBase::YearBase() {
		for (int i = 0; i < 25; ++i) {
			solutions[i] = &YearBase::placeholder;
		}
	}

	int YearBase::placeholder(std::ifstream& file, int part) {
		std::cerr << "Solution not yet implemented\n";
		return -1;
	}

	int YearBase::runsolution(std::ifstream& file, int day, int part) {
		if (day < 0 || day > 24) {
			std::cerr << "Invalid day\n";
			return -1;
		}

		if (part != 1 && part != 2) {
			std::cerr << "Invalid part\n";
			return - 1;
		}

		// TODO Do an index safety check (out of bounds, index is valid etc.)

		return solutions[day](file, part);
	}
}
