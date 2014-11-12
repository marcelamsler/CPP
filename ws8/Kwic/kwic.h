#ifndef KWIC_H_
#define KWIC_H_

#include "word.h"
#include <iosfwd>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>

using WordVector = std::vector<Word>;


struct VariationCreator {

	void operator()(WordVector const& line) {
		createVariations(line);
	}
	std::set<WordVector> getVariations() const {return variations;};

	void createVariations(WordVector const& line);

	void print(std::ostream &out) const;

	void printLineSet(WordVector const &words, std::ostream &out) const;

private:
	std::set<WordVector> variations { };
};

void printKwicVariations(std::istream &in, std::ostream &out);

inline std::istream& operator >>(std::istream &in, WordVector &lineSet) {

	std::string line { };
	std::getline(in, line);
	std::istringstream input{line};

	lineSet = WordVector{std::istream_iterator<Word> {input}, std::istream_iterator<Word>{}};

	return in;
}

#endif /* KWIC_H_ */
