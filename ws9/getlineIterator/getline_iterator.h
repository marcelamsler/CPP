#ifndef GETLINE_ITERATOR_H_
#define GETLINE_ITERATOR_H_

#include <boost/operators.hpp>
#include <string>

struct getlineIterator : boost::input_iterator_helper<getlineIterator, std::string> {

	getlineIterator() = default;

	explicit getlineIterator(std::istream& in) : input(&in) {
			std::getline(*input, currentLine);
	}

	std::string operator *();

	getlineIterator& operator++();

	bool operator ==(const getlineIterator& other) const;

private:

	std::istream *input { };
	std::string currentLine{};

};

#endif /* GETLINE_ITERATOR_H_ */
