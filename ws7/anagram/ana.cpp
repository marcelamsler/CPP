#include "ana.h"
#include <string>
#include <set>
#include <algorithm>
#include <iosfwd>

std::set getAllAnagrams(std::string word) {
	std::set<std::string> set{};

	std:sort(word.begin(), word.end());

	do {
	    set.insert(word);
	} while ( std::next_permutation(word.begin(),word.end()));

	return set;
}
