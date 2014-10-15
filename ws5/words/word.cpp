#include "word.h"
#include <string>
#include <iosfwd>
#include <iterator>
#include <algorithm>
#include <stdexcept>

Word::Word(std::string wordinput):word{wordinput}
{
	for_each(wordinput.begin(), wordinput.end(), [](const char c)
			{if (!std::isalpha(c))
				throw std::out_of_range("invalid character");
			});
}

Word::readWord(std::istream &in){



}



