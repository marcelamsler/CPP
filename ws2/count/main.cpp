#include "charc.h"
#include <ostream>

int main () {
	CharCounter counter{std::cin};
//	std::cout << counter.countNonWhiteSpaceChar();
//	std::cout << counter.CountAllChars();
//	std::cout << counter.countWords();
//	std::cout << counter.countLines();

	counter.printMultTable(10);
}




