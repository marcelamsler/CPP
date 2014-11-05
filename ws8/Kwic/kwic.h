#ifndef KWIC_H_
#define KWIC_H_

#include "word.h"
#include <iosfwd>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>

struct VariationCreator {
	std::set<std::vector<Word>> variations { };
	std::set<Word> currentLine;

	void operator()(std::vector<Word> line) {
		createVariations(line);
	}

	void createVariations(std::vector<Word> line);

	void print(std::ostream &out) const;

	void printLineSet(std::vector<Word> words, std::ostream &out) const;
};

void printKwicVariations(std::istream &in, std::ostream &out);

inline std::istream& operator >>(std::istream &in, std::vector<Word> &lineSet) {

	std::string line { };
	std::getline(in, line);

	std::istringstream iss { };
	iss.str(line);

	while (!iss.eof()) {
		Word w { };
		iss >> w;
		lineSet.push_back(w);
	}
	return in;
}

#endif /* KWIC_H_ */
