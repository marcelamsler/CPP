#include <boost/iterator/counting_iterator.hpp>
#include <boost/iterator/filter_iterator.hpp>
#include <iostream>

struct is_prime {
	bool operator()(int const n) const {
		if (n <= 3) {
			return n > 1;
		} else if (n % 2 == 0 || n % 3 == 0) {
			return false;
		} else {
			for (int i = 5; i * i <= n; i += 6) {
				if (n % i == 0 || n % (i + 2) == 0) {
					return false;
				}
			}
			return true;
		}
	}
};

int main() {

	using counter = boost::counting_iterator<int>;

	using filter = boost::filter_iterator<is_prime, counter>;

	std::ostream_iterator<int> out { std::cout, " " };

	auto filter_first = filter { is_prime { }, counter { 0 }, counter { 40} };
	auto filter_last = filter { is_prime { }, counter { 40 }, counter { 40 } };

	copy(filter_first, filter_last, out);

}
