#include <iostream>
#include "aoccpp/2024.h"

namespace AOCCPP {
	static void getColumns(std::ifstream& file, std::vector<int>& leftcol,
		std::vector<int>& rightcol) {
		// TODO Implement: read file and capture columns accurately
	}

	static int getTotalDiff(const std::vector<int>& leftcol,
		const std::vector<int>& rightcol) {
		// TODO Implement
			// For each index, calculate the difference between the two columns
			// for that equivalent index (leftcol[i], rightcol[i]), and add it
			// to a running total (result += differenceForThisIndex).
			// At the end, return result.
	}

	int AOC2024::day1(std::ifstream& file, int part) {
		std::vector leftcol;
		std::vector rightcol;

		getColumns(file, leftcol, rightcol);
		
		std::sort(leftcol.begin(), leftcol.end());
		std::sort(rightcol.begin(), rightcol.end());

		return getTotalDiff(leftcol, rightcol);
	}
}
