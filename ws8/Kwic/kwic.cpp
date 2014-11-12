#include "kwic.h"
#include "word.h"
#include <iosfwd>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

void VariationCreator::printLineSet(WordVector const &words, std::ostream &out) const {
	copy(words.begin(), words.end(), std::ostream_iterator<Word>{out, " "});
	out << "\n";
}

void VariationCreator::print(std::ostream &out) const {
	out << "\n";
	for_each(variations.begin(), variations.end(), [&](WordVector line) {
		printLineSet(line, out);
	});
}

void VariationCreator::createVariations(WordVector const& line) {
	for (size_t i = 0; i < line.size(); i++) {
		WordVector newLine { };
		std::rotate_copy(line.begin(), line.begin() + i, line.end(), std::back_inserter(newLine));
		variations.insert(newLine);
	}
}

void printKwicVariations(std::istream &in, std::ostream &out) {

	std::set<WordVector> lines {std::istream_iterator<WordVector>{in},std::istream_iterator<WordVector>{}};

	for_each(lines.begin(), lines.end(), VariationCreator { }).print(out);

}

