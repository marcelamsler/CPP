#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "prime_number_iterator.h"
#include <ostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <string>


void thisIsATest() {
	prime_number_iterator it {4};
	prime_number_iterator end {};

	std::stringstream str{};
	std::ostream_iterator<unsigned> out{str, ","};

	std::copy(it, end, out);

	ASSERT_EQUAL("2,3,5,7", str.str());

}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



