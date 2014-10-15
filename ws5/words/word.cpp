#include "word.h"
#include <string>
#include <iosfwd>
#include <iterator>
#include <algorithm>
#include <stdexcept>

Word::Word(std::string wordinput):word{wordinput}
{
	for_each(wordinput.begin(), wordinput.end(), [](const char c)
		{
			if (!std::isalpha(c))
				throw std::out_of_range("invalid character");
		});
}

void Word::readWord(std::istream &in){
	char c{};
	in >> c;
	while(std::isalpha(c)){
		word.push_back(c);
		in >> c;
	}
}



