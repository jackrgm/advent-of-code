/*
Advent of Code 2022
Day 3: Rucksack Reorganization

https://adventofcode.com/2022/day/3
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>

std::pair<std::string, std::string> split(std::string input) {
	std::pair<std::string, std::string> result;
	
	result.first = input.substr(0, input.size()/2);
	result.second = input.substr(input.size()/2);

	return result;
}

std::string getIntersection(std::string slotA, std::string slotB) {
	std::set<char> setA(begin(slotA), end(slotA));
	std::set<char> setB(begin(slotB), end(slotB));

	std::string intersection;

	std::set_intersection(begin(setA), end(setA),
		begin(setB), end(setB), back_inserter(intersection));

	return intersection;
}

int getPriority(char input) {
	if (!((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z'))) {
		return -9999;
	}

	// Convert lowercase Ascii values to one-based values.
	if (input >= 'a') {
		return input - 'a' + 1;
	}

	// Convert uppercase Ascii values to one-based values (following lowercase).
	return input - 'A' + 27;
}

int prioritise(std::string input) {
	int result = 0;

	for (int i = 0; i < input.size(); i++) {
		result += getPriority(input.at(i));
	}

	return result;
}

int identifyItems(std::fstream & file) {
	typedef std::pair<std::string, std::string> rucksack;
	std::string line;
	int prioritySum = 0;

	while(getline(file, line)) {
		rucksack compartments = split(line);
		std::string errantItems = getIntersection(compartments.first,
			compartments.second);
		prioritySum += prioritise(errantItems);
	}

	return prioritySum;
}

int identifyBadges(std::fstream & file) {
	std::string line;
	std::string errantBadges;

	int i = 1;
	int prioritySum = 0;

	while(getline(file, line)) {
		if (i == 1) {
			// String will get replaced with only intersecting items afterwards.
			errantBadges = line;
		} else {
			errantBadges = getIntersection(errantBadges, line);
		}

		// Finished processing a group.
		if (i == 3) {
			prioritySum += prioritise(errantBadges);
			i = 0;
		}

		i++;
	}

	return prioritySum;
}

/*
I may introduce a proper unit testing framework to my AOC solutions in future,
but for now - and since we're working in the domain of the magical Christmas
land of safety and casual coding - this rudimentary test function meets the
quality assurance requirements of the Elves.
*/
void test() {
	std::cout << "Testing split(\"aAabBb\")...\n";
	std::cout << "\tExpecting: <aAa, bBb>\n";
	std::pair<std::string, std::string> sp = split("aaabbb");
	std::cout << "\tGot: <" << sp.first << ", " << sp.second << ">\n";

	std::cout << "Testing getIntersection(\"aAxyza\", \"bBxyzb\")...\n";
	std::cout << "\tExpecting: \"xyz\"\n";
	std::cout << "\tGot: \"" << getIntersection("aAxyza", "bBxyzb") << "\"\n";

	std::cout << "Testing getIntersection(\"aAzzza\", \"bBzzzb\")...\n";
	std::cout << "\tExpecting: \"z\"\n";
	std::cout << "\tGot: \"" << getIntersection("aAzzza", "bBzzzb") << "\"\n";

	std::cout << "Testing getPriority('£')...\n";
	std::cout << "\tExpecting: -9999\n";
	std::cout << "\tGot: " << getPriority('£') << "\n";

	std::cout << "Testing getPriority('a')...\n";
	std::cout << "\tExpecting: 1\n";
	std::cout << "\tGot: " << getPriority('a') << "\n";

	std::cout << "Testing getPriority('z')...\n";
	std::cout << "\tExpecting: 26\n";
	std::cout << "\tGot: " << getPriority('z') << "\n";

	std::cout << "Testing getPriority('A')...\n";
	std::cout << "\tExpecting: 27\n";
	std::cout << "\tGot: " << getPriority('A') << "\n";

	std::cout << "Testing getPriority('Z')...\n";
	std::cout << "\tExpecting: 52\n";
	std::cout << "\tGot: " << getPriority('Z') << "\n";

	std::cout << "Testing prioritise(\"abc\")...\n";
	std::cout << "\tExpecting: 6 (1+2+3)\n";
	std::cout << "\tGot: " << prioritise("abc") << "\n";

	std::cout << "Testing prioritise(\"ee\")...\n";
	std::cout << "\tExpecting: 10 (5+5)\n";
	std::cout << "\tGot: " << prioritise("ee") << "\n";

	std::cout << "Testing prioritise(\"ABC\")...\n";
	std::cout << "\tExpecting: 84 (27+28+29)\n";
	std::cout << "\tGot: " << prioritise("ABC") << "\n";
}

void printUsage(std::string programName) {
	std::cout << programName << ": Usage: "
		<< programName << " [-t] [-1 | -2 filename]\n";
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printUsage(argv[0]);
		return 1;
	}

	if (std::string(&argv[1][1]) == "t") {
		test();
		return 0;
	}

	if (argc < 3) {
		printUsage(argv[0]);
		return 1;
	}

	std::fstream file(argv[2]);

	if (!file.is_open()) {
		std::cerr << argv[0] << ": Error: file not found (\""
			<< argv[2] << "\").\n";
		return -1;
	}

	std::string part(&argv[1][1]);

	if (part != "1" && part != "2") {
		printUsage(argv[0]);
		return 1;
	}

	std::cout << "Part " << part << ": ";

	if (part == "1") {
		std::cout << identifyItems(file);
	} else {
		std::cout << identifyBadges(file);
	}

	std::cout << "\n";

	return 0;
}
