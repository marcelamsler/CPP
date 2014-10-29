#include "ana.h"
#include <iostream>
#include <set>
#include <iterator>
#include <fstream>
#include <algorithm>

int main (){
	std::set<std::string> set{};

	std::ifstream myfile;
	myfile.open("/usr/share/dict/words");

	std::istream_iterator<std::string> it{myfile};

	std::istream_iterator<std::string> eof{};

	while (it != eof) {
		std::set<std::string> anagram_set{getAllAnagrams(*it)};
		set.insert(anagram_set.begin(), anagram_set.end());
		it++;
	}

	std::ostream_iterator<std::string> out{std::cout, "\n"};

	std::copy(set.begin(), set.end(), out);

}
