#ifndef RING6_H_
#define RING6_H_

#include <ostream>


struct Ring6 {

	Ring6(unsigned value=0u):val{value % 6}{}

	unsigned value() const {return val;}

	operator unsigned() const {return val;}

	inline bool operator ==(Ring6 const &otherRing) {
		return val == otherRing.value();
	}

	private:
		unsigned val {};

};

std::ostream& operator <<(std::ostream& out, Ring6 const& r);

#endif /* RING6_H_ */
