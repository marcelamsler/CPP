#include <string>
#include <stack>
#include <algorithm>
#include <boost/algorithm/string.hpp>

bool is_palindrome(std::string word){
	if(word.size() % 2) return false;

	boost::algorithm::to_lower(word);

	std::string reversedWord{word.crbegin(), word.crend()};

	return word == reversedWord;

}
