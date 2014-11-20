
#ifndef PRIME_NUMBER_ITERATOR_H_
#define PRIME_NUMBER_ITERATOR_H_

#include <boost/operators.hpp>

struct prime_number_iterator : boost::input_iterator_helper<prime_number_iterator, unsigned>{

	prime_number_iterator() = default;

	explicit prime_number_iterator(int countLimit) : countLimit(countLimit){}

	bool operator == (prime_number_iterator const &otherIterator) const{
		return countLimit == 0 && otherIterator.countLimit == countLimit;
	}

	unsigned operator *() const{

	}

	void operator ++ () {
		countLimit++;
	}

private:
	unsigned countLimit {};

};



#endif /* PRIME_NUMBER_ITERATOR_H_ */
