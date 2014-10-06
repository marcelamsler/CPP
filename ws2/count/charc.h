#ifndef CHARC_H_
#define CHARC_H_

#include <iostream>
#include <string>

struct CharCounter {
	std::istream &instream;

	int countNonWhiteSpaceChar() const;

	int CountAllChars() const;

	int countWords() const;

	int countLines() const;

	int sum() const;

	void printMultTable(int size) const;
};





#endif /* CHARC_H_ */
