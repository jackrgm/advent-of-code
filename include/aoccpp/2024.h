#ifndef AOC2024_H
#define AOC2024_H

#include <fstream>
#include "aoccpp/yearbase.h"

namespace AOCCPP {
	struct AOC2024 : public YearBase {
		static int day1(std::ifstream& file, int part);

		AOC2024() {
			solutions[0] = &AOC2024::day1;
		}
	};
}

#endif
