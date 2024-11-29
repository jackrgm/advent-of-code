/*
Advent of Code 2022
Day 2: Rock Paper Scissors

https://adventofcode.com/2022/day/2
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#define ELF_ROCK "A"
#define ELF_PAPER "B"
#define ELF_SCISSORS "C"

#define MY_ROCK "X"
#define MY_PAPER "Y"
#define MY_SCISSORS "Z"

#define NEED_LOSE "X"
#define NEED_DRAW "Y"
#define NEED_WIN "Z"

void printBadElfChoice(std::string elfChoice) {
	std::cerr << "The Elf commited serious war crimes by using an illegal"
		" weapon (\"" << elfChoice << "\"), instead of one of the legal"
		" choices of ROCK (\"A\"), PAPER (\"B\"), or SCISSORS (\"C\"). You"
		" witness some authorative-looking Elves approach the offender and haul"
		" them off to a place the Elves at the camp refer to as"
		" \'the naughty list\'. The authoritve Elves return, presenting a"
		" different Elf, who you understand is to be your new opponent.\n";
}

void printBadRockReply(std::string myChoice) {
	std::cerr << "The Elf, smirking, whips their arm and reveals a clenched"
		" fist, but their face quickly turns to horror as you, in response,"
		" pull out a Karabiner 98k kurz bolt-action rifle and point it towards"
		" their face. The other Elves in the camp look on with shock and fear"
		" as an elder Elf approaches you. The elder gently places their hand"
		" on the barrel of your gun, lowering it, and softly clarifies to you"
		" that you cannot use that ('that' of course being"
		" \"" << myChoice << "\"). You withdraw your Kar98k rifle, embarassed,"
		" but you carry on with the game and the whole camp quickly returns to"
		" ease. You now understand that you should play only one of ROCK"
		" (\"X\"), PAPER (\"Y\"), or SCISSORS (\"Z\").\n";
}

void printBadPaperReply(std::string myChoice) {
	std::cerr << "The Elf quickly reveals a flat palm, with their brows low and"
		" tongue playfully sticking out. Their tongue withdraws as they become"
		" puzzled by the ground beneath them darkening. Noticing a shadow"
		" engulfing them they look up with widened eyes, as does the rest of"
		" the camp, to notice a large piano dangling above the Elf, swinging"
		" from a nearby crane. The elder Elf rushes over, waving, to halt"
		" whatever it is you're about to do. Recovering their breath, they tell"
		" you that you cannot use that (\'that\' of course being \""
		<< myChoice << "\"). You give a signal to the operator who drives the"
		" crane and the piano away. Disgruntled, but understanding, you carry"
		" on with the game. You now understand that you should play only one of"
		" ROCK (\"X\"), PAPER (\"Y\"), or SCISSORS (\"Z\").\n";
}

void printBadScissorsReply(std::string myChoice) {
	std::cerr << "Determined, and in one sharp swoop the Elf sharply reveals"
		" their hand; index and middle fingers extended with ring and pinky"
		" fingers, as well as their thumb, in flexion. The Elf quickly"
		" withdraws in panic as you excitedly yell \'En garde!\' as you"
		" unsheathe a great but wildly dangerous rapier blade. As you swing"
		" your sword in dance, the elder Elf cautiously approaches you from"
		" behind as the other Elves in the camp look on, mildly afraid but"
		" mostly puzzled. The elder taps your shoulder and informs you that you"
		" cannot use that (\'that\' of course being \"" << myChoice << "\")."
		" You look around to notice the scene you've caused. Confused by the"
		" camp's reaction, you nevertheless sheathe your blade away to ease the"
		" tension. All the elves in the camp return to calm as you carry on"
		" with the game. You now understand that you should play only one of"
		" ROCK (\"X\"), PAPER (\"Y\"), or SCISSORS (\"Z\").\n";
}

int calcStrategyGuide(std::string filename, int part) {
	std::fstream file;

	int total = 0;
	int round = 0;

	const int scoreForRock = 1;
	const int scoreForPaper = 2;
	const int scoreForScissors = 3;

	const int lose = 0;
	const int draw = 3;
	const int win = 6;
	
	file.open(filename);

	if (!file.is_open()) {
		std::cerr << "Error: can't open file (is filename correct?)\n";
		std::cerr << "Filename was: \"" << filename << "\".\n";
	}

	std::string line;

	std::string elfChoice = "";
	std::string myChoice = "";

	while(getline(file, line)) {
		std::istringstream ss(line);

		ss >> elfChoice >> myChoice;

		if (elfChoice == ELF_ROCK) {
			if ((part == 1 && myChoice == MY_ROCK)
				|| (part == 2 && myChoice == NEED_DRAW)) {
				round = draw + scoreForRock;
			} else if ((part == 1 && myChoice == MY_PAPER)
				|| (part == 2 && myChoice == NEED_WIN)) {
				round = win + scoreForPaper;
			} else if ((part == 1 && myChoice == MY_SCISSORS)
				|| (part == 2 && myChoice == NEED_LOSE)) {
				round = lose + scoreForScissors;
			} else {
				printBadRockReply(myChoice);
			}
		} else if (elfChoice == ELF_PAPER) {
			if ((part == 1 && myChoice == MY_ROCK)
				|| (part == 2 && myChoice == NEED_LOSE)) {
				round = lose + scoreForRock;
			} else if ((part == 1 && myChoice == MY_PAPER)
				|| (part == 2 && myChoice == NEED_DRAW)) {
				round = draw + scoreForPaper;
			} else if ((part == 1 && myChoice == MY_SCISSORS)
				|| (part == 2 && myChoice == NEED_WIN)) {
				round = win + scoreForScissors;
			} else {
				printBadPaperReply(myChoice);
			}
		} else if (elfChoice == ELF_SCISSORS) {
			if ((part == 1 && myChoice == MY_ROCK)
				|| (part == 2 && myChoice == NEED_WIN)) {
				round = win + scoreForRock;
			} else if (( part == 1 && myChoice == MY_PAPER)
				|| (part == 2 && myChoice == NEED_LOSE)) {
				round = lose + scoreForPaper;
			} else if (part == 1 && myChoice == MY_SCISSORS
				|| (part == 2 && myChoice == NEED_DRAW)) {
				round = draw + scoreForScissors;
			} else {
				printBadScissorsReply(myChoice);
			}
		} else {
			printBadElfChoice(elfChoice);
		}

		total += round;
		round = 0;
	}

	return total;
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
		std::cout << "Part 1: " << calcStrategyGuide(filename, 1) << "\n";
	} else if (partnum == "2") {
		std::cout << "Part 2: " << calcStrategyGuide(filename, 2) << "\n";
	} else {
		std::cerr << "Error: unrecognised part number: " << partnum << "\n";
	}
}
