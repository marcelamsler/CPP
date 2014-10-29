#include <palin.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

int main() {

	std::ifstream myfile;
	myfile.open("/usr/share/dict/words");

	std::istream_iterator<std::string> it{myfile};

	std::istream_iterator<std::string> eof{};

	std::ostream_iterator<std::string> out {std::cout, "\n"};

	std::copy_if(it, eof, out, is_palindrome);

}
