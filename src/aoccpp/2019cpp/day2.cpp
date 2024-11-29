#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

/**
 * @brief Reads in intcodes from a given file and inserts them sequentially into
 * a given dynamic array.
 * @param ic A given dynamic array (which will be the list of intcodes)
 * @param f A given filepath
 * @return Whether or not the operation succeeded.
 */
int read(std::vector<int>& ic, std::string f);

/**
 * @brief Processes a list of intcodes based on the opcodes within the list.
 * @param ic A given dynamic array (the populated list of intcodes)
 * @param n An opcode noun-parameter
 * @param v An opcode verb-parameter
 */
void process(std::vector<int>& ic, int n, int v);

/**
 * @brief Prints the computed list of intcodes to standard output.
 * @param ic A given dynamic array (the computed list of intcodes)
 */
void print(std::vector<int>& ic);

int main(int argc, char *argv[]) {
	std::string file = argv[1];
	std::vector<int> intcodes;
	
	// Checks if filepath is valid before continuing with anything.
	if(read(intcodes, file) == 1) {
		std::cerr << "Unable to open file. ";
		std::cerr << "Did you type the filepath correctly?" << "\n";
		exit(1);
	} else {
		std::cout << "Read complete. Array size is " << intcodes.size();
		std::cout << ".\n";
	}
	
	// Print the vector before and after the processing for PART 1.
	std::cout << "Vector contents BEFORE processing: ";
	print(intcodes);
	
	// Process the incodes using the parameters given in the AOC2019 DAY2 brief
	process(intcodes, 12, 2);
	std::cout << "Opcode 99 reached." << "\n";
	
	std::cout << "Vector contents AFTER processing: ";
	print(intcodes);
	
	/*
	 * Brute force the noun-verb parameter tuning to find the noun-verb 
	 * parameters that generates the given specified output (19690720) in the 
	 * AOC2019 DAY2 briefing.
	 */
	for (int n = 0; n <= 99; n++) {
		for (int v = 0; v <= 99; v++) {
			intcodes.clear();
			read(intcodes, file);
			process(intcodes, n, v);
			
			if (intcodes[0] == 19690720) {
				std::cout << "Target output found.\n";
				std::cout << "Parameters used to generate the output are ";
				std::cout << n << " (noun), " << v << " (verb).\n";
				std::cout << "100 x " << n << " + " << v << " = ";
				std::cout << 100 * n + v << ".\n";
			}
		}
	}
}

/**
 * To read in the file this function definition takes the approach of feeding
 * the file into the program via an ifstream object. The function recursively
 * pushes identified ints into the provided vector sequentially and spits out
 * commas into a variable for practical reasons, at least until I discover a
 * better way. 
 *
 * The comma-holding bin variable is 100% recyclable and is fully
 * compostable, with its value decaying entirely after the function ends.
 * Thanks to this sustainable approach, comma-emissions are minimised, 
 * supporting the development towards reducing our comma-footprint on the world.
 */
int read(std::vector<int>& ic, std::string f) {
	int intcode;
	char comma; // Used to eat up all the delicious commas in the input.
	std::ifstream iFile;
	
	iFile.open(f);

	// Filepath validation.
	if(!iFile) {
		return 1;
	}
	
	// Go through each integer, adding them to the array as they're discovered.
	while(iFile >> intcode >> comma) {
		ic.push_back(intcode);
	}

	// Catch the last int. Not sure why it misses one off at the end, TBH.
	iFile >> intcode;
	ic.push_back(intcode);
		
	iFile.close();
	return 0;
}

/**
 * The main approach here is to use array arithmetic with some variable
 * abstraction. First we define the 1-4 integer placements as specified on
 * the AOC2019 DAY2 brief - i.e. 0,1,2,3 where '0' is an opcode, '1' is a 
 * operand to be computed with '2' using either addition or multiplication 
 * specified  by the opcode, and the sum is stored in position '3', traversing 
 * in 4 integer segments. By defining these positions with variables we can 
 * simplify the problem through abstraction when performing the calculations in 
 * the switch cases.
 *
 * This definition was later modified to support the use of noun and verb 
 * parameters to dictate the processing of the intcode list.
 */
void process(std::vector<int>& ic, int n, int v) {
	int opcode;
	int operand1;
	int operand2;
	int sum;
	int quit = 0;
	
	// Overwrite the noun and verb positions in the intcode vector.
	ic[1] = n;
	ic[2] = v;
	
	for(int i = 0; i < ic.size(); i += 4) {
		// Map placements to representations.
		opcode = ic[i];
		operand1 = ic[i+1];
		operand2 = ic[i+2];
		sum = ic[i+3];
		
		switch (opcode) {
			// Addition.
			case 1:
				ic[sum] = ic[operand1] + ic[operand2];
				break;
				
			// Multiplication.
			case 2:
				ic[sum] = ic[operand1] * ic[operand2];
				break;
				
			// Termination.
			case 99:
				return;
				
			default:
				std::cerr << "Opcode is not in Santa's file. This incident ";
				std::cerr << "will be reported."<< "\n";
		}
	}
	
	return;
}

/**
 * Simple implementation; iteratively print each index, inserting a comma (,)
 * in between each index iteration except for the last entry (instead the last
 * entry gets a nice little line break for Christmas).
 */
void print(std::vector<int>& ic) {
	for(int i = 0; i < ic.size(); i++) {
		std::cout << ic[i];
		if (i < ic.size() - 1) {
			std::cout << ",";
		} else {
			std::cout << ".\n";
		}
	}	
}
