
#ifndef PRIME_NUMBER_ITERATOR_H_
#define PRIME_NUMBER_ITERATOR_H_

#include <boost/operators.hpp>

struct prime_number_iterator : boost::input_iterator_helper<prime_number_iterator, unsigned>{

	prime_number_iterator() = default;

	explicit prime_number_iterator(unsigned numberOfPrimes) :
			numberOfPrimes { numberOfPrimes }
	{
		currentPrime = next_prime(currentPrime);
	}

	bool operator == (prime_number_iterator const &otherIterator) const{
		return numberOfPrimes == 0 && otherIterator.numberOfPrimes == numberOfPrimes;
	}

	unsigned operator *() const{
		return currentPrime;
	}

	void operator ++ () {
		numberOfPrimes--;
		currentPrime = next_prime(currentPrime);
	}

private:
	unsigned numberOfPrimes {};
	unsigned currentPrime{};
	unsigned next_prime(unsigned x);
	bool is_prime(unsigned n);

};



#endif /* PRIME_NUMBER_ITERATOR_H_ */
