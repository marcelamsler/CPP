#include "getline_iterator.h"
#include <string>

std::string getlineIterator::operator *() {

	std::string value { };

	if (input)
		std::getline(*input, value) ;

	return value;

}

bool getlineIterator::operator ==(const getlineIterator& other) const {

	return (!input || !input->good()) && (!other.input || !other.input->good());

}

