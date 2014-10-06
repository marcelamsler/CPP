#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <iostream>

std::vector<std::vector<std::string>> generateDigits() {

	std::vector<std::vector<std::string>> digits{10};

	digits[0].push_back(" - ");
	digits[0].push_back("| |");
	digits[0].push_back("   ");
	digits[0].push_back("| |");
	digits[0].push_back(" - ");

	digits[1].push_back(" - ");
	digits[1].push_back("  |");
	digits[1].push_back("   ");
	digits[1].push_back("  |");
	digits[1].push_back("   ");

	digits[2].push_back(" - ");
	digits[2].push_back("  |");
	digits[2].push_back(" -  ");
	digits[2].push_back("|  ");
	digits[2].push_back(" -  ");

	digits[3].push_back(" - ");
	digits[3].push_back("  |");
	digits[3].push_back(" -  ");
	digits[3].push_back("  |");
	digits[3].push_back(" -  ");

	digits[4].push_back("   ");
	digits[4].push_back("| |");
	digits[4].push_back(" -  ");
	digits[4].push_back("  |");
	digits[4].push_back("   ");

	digits[5].push_back(" - ");
	digits[5].push_back("|  ");
	digits[5].push_back(" - ");
	digits[5].push_back("  |");
	digits[5].push_back(" - ");

	digits[6].push_back(" - ");
	digits[6].push_back("|  ");
	digits[6].push_back(" - ");
	digits[6].push_back("| |");
	digits[6].push_back(" - ");

	digits[7].push_back(" - ");
	digits[7].push_back("  |");
	digits[7].push_back(" - ");
	digits[7].push_back("  |");
	digits[7].push_back("   ");

	digits[8].push_back(" - ");
	digits[8].push_back("| |");
	digits[8].push_back(" - ");
	digits[8].push_back("| |");
	digits[8].push_back(" - ");

	digits[9].push_back(" - ");
	digits[9].push_back("| |");
	digits[9].push_back(" - ");
	digits[9].push_back("  |");
	digits[9].push_back(" - ");

	return digits;

}

void printLargeDigit(unsigned int number, unsigned int size, std::ostream &out) {

	if (number > 9) return;

	std::vector<std::vector<std::string>> digits = generateDigits();

	unsigned int lineNumber{1};

	for_each(digits[number].begin(), digits[number].end(),[&out, &lineNumber, size] (std::string line) {

		if (lineNumber % 2) {
			for (unsigned int i = 1; i < size; i++) {
				line.insert(1, line.substr(1,1));
			}
			out << line << "\n";
		} else {
			for (unsigned int i = 1; i < size; i++) {
				line.insert(1, " ");
			}
			for (unsigned int i = 0; i < size; i++) {
				out << line << "\n";
			}

		}

		lineNumber++;

	});
}



void printMultipleLargeDigits(unsigned int number, unsigned int size, std::ostream &out){
	std::string digits = std::to_string(number);

	for_each(digits.begin(), digits.end(), [&size, &out](const char digit){
		unsigned int bla{};
		bla = digit - '0';
		printLargeDigit(bla, size, out);
	});
}






