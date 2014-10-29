#include <string>
#include <stack>
#include <algorithm>
#include <boost/algorithm/string.hpp>

bool is_palindrome(std::string word){
	if(word.size() % 2) return false;

	boost::algorithm::to_lower(word);

	std::stack<char> stack{};

	for_each(word.begin(), word.end(), [&](char c){

			if (!stack.empty() && stack.top() == c) {
				stack.pop();
			} else {
				stack.push(c);
			}
	});

	return stack.empty();

}
