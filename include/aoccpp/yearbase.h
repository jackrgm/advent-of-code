#ifndef YEARBASE_H
#define YEARBASE_H

#include <fstream>
#include <functional>

namespace AOCCPP {
	class YearBase {
	protected:
		std::function<int(std::ifstream&, int)> solutions[25];
		static int placeholder(std::ifstream& file, int part);

	public:
		YearBase();
		int runsolution(std::ifstream& file, int day, int part);
	};
}

#endif
