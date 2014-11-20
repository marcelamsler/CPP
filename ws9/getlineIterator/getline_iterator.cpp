#include "getline_iterator.h"
#include <string>

std::string getlineIterator::operator *() {
	return currentLine;
}

getlineIterator& getlineIterator::operator++() {
	std::string tmpLine { };
	std::getline(*input, tmpLine);

	while (tmpLine.empty() && input->good()) {
		std::getline(*input, tmpLine);
	}

	if (!tmpLine.empty()) {
		currentLine = tmpLine;

		if (input->eof()) {
			input->clear();
		}
	}

	return *this;
}

bool getlineIterator::operator ==(const getlineIterator& other) const {

	return (!input || input->eof()) && (!other.input || other.input->eof());

}

