#include "kwic.h"
#include "word.h"
#include <iosfwd>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

void VariationCreator::printLineSet(std::vector<Word> words, std::ostream &out) const {
	for_each(words.begin(), words.end(), [&](Word word) {
		out << word << " ";
	});

	out << "\n";
}

void VariationCreator::print(std::ostream &out) const {
	for_each(variations.begin(), variations.end(), [&](std::vector<Word> line) {
		printLineSet(line, out);
	});
}

void VariationCreator::createVariations(std::vector<Word> line) {
	for (size_t i = 0; i < line.size(); i++) {
		std::vector<Word> newLine { };
		std::rotate_copy(line.begin(), line.begin() + i, line.end(), std::back_inserter(newLine));
		variations.insert(newLine);
	}
}

void printKwicVariations(std::istream &in, std::ostream &out) {

	std::set<std::vector<Word>> lines { };

	while (in.good()) {
		std::vector<Word> lineVector;
		in >> lineVector;
		lines.insert(lineVector);
	}

	for_each(lines.begin(), lines.end(), VariationCreator { }).print(out);

}

