#include "charc.h"
#include <string>
#include <iostream>
#include <iomanip>


int CharCounter::countNonWhiteSpaceChar() const{
	int length{-1};
	char c{};
	while(CharCounter::instream.good()) {
		CharCounter::instream >> c;
		length++;
	}

	return length;
}

int CharCounter::CountAllChars() const {
	std::string line{};
	std::getline(CharCounter::instream, line);
	return line.length();

}

int CharCounter::countWords() const {
	int length{-1};
	std::string word{};
	while(CharCounter::instream.good()) {
			CharCounter::instream >> word;
			length++;
	}

	return length;
}

int CharCounter::countLines() const {

	int length{-1};
	std::string line{};
	while(CharCounter::instream.good()) {
		std:getline(CharCounter::instream, line);
		length++;
	}

	return length;

}

int CharCounter::sum() const {
	int input{0};
	int sum{0};
	int count{0};
	while(CharCounter::instream >> input) {
		count ++;
		sum = sum + input;
	}
	return sum/count;
}

void CharCounter::printMultTable(int size) const {

	for (int i = 0; i <= size; i++) {
		std::string line{};
		for (int j = 0; j <= size; j++) {
			std::cout << std::setw(10);
			std::cout << (i/(double)j);
		}
		std::cout << "\n";
	}

}







