#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <sstream>
#include "getline_iterator.h"

void testMultipleLines() {
	std::istringstream is {"bla bla\n bli bli \n blo blo"};
	std::vector<std::string> v {getlineIterator{is}, getlineIterator{}};
	ASSERT_EQUAL(3, v.size());
	ASSERT_EQUAL(8, v.at(2).size());
}

void testEqualityEOF() {
	ASSERT_EQUAL(getlineIterator{}, getlineIterator{});
}

void testDereferencingAndOperators(){
	std::istringstream is {"bla bla\n bli bli\n blo blo"};
	getlineIterator it {is};
	ASSERT_EQUAL(*it, "bla bla");
	it++;
	ASSERT_EQUAL(*it, " bli bli");
	++it;
	ASSERT_EQUAL(*it, " blo blo");
}


void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testMultipleLines));
	s.push_back(CUTE(testEqualityEOF));
	s.push_back(CUTE(testDereferencingAndOperators));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



