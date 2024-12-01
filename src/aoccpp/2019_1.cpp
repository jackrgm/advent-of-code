/* 
 * Calculates the total fuel requirement of the Elven spacecraft featured in the
 * first day of Advent of Code 2019 (The Tyranny of the Rocket Equation), based 
 * on the mass of each module within the spacecraft.
 */
#include <fstream>
#include <iostream>
#include <sstream>

/**
 * @brief Calculates the fuel requirements for a given list of module mass
 * values.
 * @param filepath The filepath of the target list of module masses (text file)
 */
void calc(std::string inputfile);

int fuelreq = 0; // Total fuel required to support all module mass.
int literalfuelreq = 0; // Total fuel required to support modules and its fuel.

int main(int argc, char *argv[]) {

	// The program parameter will be the target filepath for the calc function.
	std::string file = argv[1];
	
	// Calculate the total fuel requirements of every module on the spacecraft.
	calc(file);
	
	// Print the calculation output to stdout.
	std::cout << "The total fuel requirement for the module list is ";
	std::cout << fuelreq << " units." << "\n";
	std::cout << "The literal fuel requirement for the whole spacecraft is ";
	std::cout << literalfuelreq << " units." << "\n";
}

void calc (std::string filepath) {
	std::ifstream input(filepath);
	std::string inputline;
	
	while(std::getline(input, inputline)) {
		int currentmodule = 0;
		
		// Read in the line of the file of the corresponding iteration.
		std::istringstream inputmodule(inputline);
		
		if (!(inputmodule >> currentmodule)) {
			break;
		}
		
		// Calculate fuel requirements for the current module and add to total.
		fuelreq += (currentmodule / 3) - 2;
	
		// Calculate the literal fuel requirements for the module and its fuel.
		while (currentmodule > 0) {
			currentmodule = (currentmodule / 3 ) - 2;
			
			// Add (positive) calculations to the total literal fuel pool.
			if (currentmodule > 0) {
				literalfuelreq += currentmodule;
			}
		}
	}
	
	return;
}
