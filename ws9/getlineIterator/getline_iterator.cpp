#include "getline_iterator.h"
#include <string>

std::string getlineIterator::operator *() {
	return currentLine;
}

getlineIterator& getlineIterator::operator++() {
	std::getline(*input, currentLine);

	if (input->eof() && !currentLine.empty())
		input->clear();

	return *this;
}

bool getlineIterator::operator ==(const getlineIterator& other) const {

	return (!input || input->eof()) && (!other.input || other.input->eof());

}

