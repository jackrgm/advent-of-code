#include <iostream>
#include <sstream>
#include <stdexcept>
#include "aoccpp/2024.h"

namespace AOCCPP {
	static void getColumns(std::ifstream& file, std::vector<int>& leftcol,
		std::vector<int>& rightcol) {

		if (!file) {
			throw std::runtime_error("File could not be opened.");
		}

		std::string line;
		int n1, n2;

		while(std::getline(file, line)) {
			std::istringstream stream(line);

			if (stream >> n1 >> n2) {
				leftcol.push_back(n1);
				rightcol.push_back(n2);
			} else {
				throw std::runtime_error("Unexpected file contents (bad input).");
			}
		}
	}

	static int processColumns(const std::vector<int>& leftcol,
		const std::vector<int>& rightcol, int part) {

		if (leftcol.size() != rightcol.size()) {
			throw std::runtime_error("Column vectors are of different size.");
		}

		int total = 0;

		if (part == 1) {
			for (size_t i = 0; i < leftcol.size(); i++) {
				int diff = std::abs(leftcol[i] - rightcol[i]);
				total += diff;
			}
		} else {
			for (size_t i = 0; i < leftcol.size(); i++) {
				int count = 0;

				for (size_t j = 0; j < rightcol.size(); j++) {
					if (leftcol[i] == rightcol[j]) {
						count++;
					}
				}

				if (count > 0) {
					total += leftcol[i] * count;
				}
			}
		}

		return total;
	}

	int AOC2024::day1(std::ifstream& file, int part) {
		std::vector<int> leftcol;
		std::vector<int> rightcol;

		getColumns(file, leftcol, rightcol);
		
		std::sort(leftcol.begin(), leftcol.end());
		std::sort(rightcol.begin(), rightcol.end());

		return processColumns(leftcol, rightcol, part);
	}
}
