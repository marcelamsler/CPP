#include "ana.h"
#include <iostream>
#include <set>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>

int main (){
	std::set<std::string> set{};

	std::ifstream myfile;
	myfile.open("/usr/share/dict/words");

	std::istream_iterator<std::string> it{myfile};
	std::istream_iterator<std::string> it2{myfile};

	std::istream_iterator<std::string> eof{};

	while (it != eof) {
		std::set<std::string> anagram_set{getAllAnagrams(*it)};
		std::vector<std::string> valid_anagrams{};
		std::set_intersection(anagram_set.begin(), anagram_set.end(), it2, eof, valid_anagrams.begin());
		set.insert(valid_anagrams.begin(), valid_anagrams.end());
		it++;
	}

	std::ostream_iterator<std::string> out{std::cout, "\n"};

	std::copy(set.begin(), set.end(), out);

}
