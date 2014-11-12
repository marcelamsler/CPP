#include "word.h"
#include <string>
#include <iosfwd>
#include <iterator>
#include <algorithm>
#include <stdexcept>

Word::Word(std::string const& wordinput) : word { wordinput } {
	if (wordinput.empty())
			throw std::out_of_range("empty Word");

	for_each(wordinput.begin(), wordinput.end(), [](const char c)
	{
		if (!std::isalpha(c))
		throw std::out_of_range("invalid character");
	});
}

void Word::readWord(std::istream &in) {
	char c = in.get();
	std::string tmpWord { };

	while (!std::isalpha(c) && !in.eof()) {
		c = in.get();
	}

	while (std::isalpha(c)) {
		tmpWord.push_back(c);
		c = in.get();
	}

	if (!tmpWord.empty()) {
		word = tmpWord;

		if (in.eof())
			in.clear();
	}
}

