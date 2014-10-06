#include <iostream>
#include "chcount.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
int main(){
	std::vector<std::vector<unsigned int>> m = multab(5);
	for_each(m.begin(),m.end(),[](const std::vector<unsigned int> v) {
		std::copy(v.begin(), v.end(), std::ostream_iterator<unsigned int>(std::cout, " "));
		std::cout << '\n';
	});

}



