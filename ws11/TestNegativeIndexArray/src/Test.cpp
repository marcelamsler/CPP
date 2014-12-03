#include <dynArray.h>
#include <sstream>
#include <iterator>
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void testDefaultConstructor() {
	dynArray<char> a {};
	ASSERT_EQUAL(0,a.size());
}

void testInitializerListConstructor() {
	dynArray<int> a{1,2,3,4,5};
	ASSERT_EQUAL(5,a.size());
}

void testCountAndValueConstructor() {
	dynArray<double> a(10,3.14);
	ASSERT_EQUAL(10,a.size());
}
void testIteratorConstructor() {
	std::istringstream input {"test the iterator constructor"};
	dynArray<std::string> a{std::istream_iterator<std::string>{input},std::istream_iterator<std::string>{}};
	ASSERT_EQUAL(4,a.size());
}

void testCountAndValueConstructorWithTwoInts() {
	dynArray<int> a (1,2);
	dynArray<int> b {1,2};
	ASSERT_EQUAL(1, a.size());
	ASSERT_EQUAL(2, b.size());
}

void testNormalIndexAccess(){
	dynArray<int> a{1,2,3,4,5};
	ASSERT_EQUAL(1, a.at(0));
	ASSERT_EQUAL(1, a[0]);
	ASSERT_EQUAL(5, a.at(4));
	ASSERT_EQUAL(5, a[4]);
}

void testNegativeIndexAccess(){
	dynArray<int> a{1,2,3,4,5};
	ASSERT_EQUAL(5, a.at(-1));
	ASSERT_EQUAL(5, a[-1]);
	ASSERT_EQUAL(1, a.at(-5));
	ASSERT_EQUAL(1, a[-5]);

}

void testFactoryMethodForInitializerList() {
	auto a = makeDynArray({"42", "is", "the", "answer"});
	ASSERT_EQUAL(4, a.size());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testDefaultConstructor));
	s.push_back(CUTE(testInitializerListConstructor));
	s.push_back(CUTE(testCountAndValueConstructor));
	s.push_back(CUTE(testIteratorConstructor));
	s.push_back(CUTE(testCountAndValueConstructorWithTwoInts));
	s.push_back(CUTE(testNormalIndexAccess));
	s.push_back(CUTE(testNegativeIndexAccess));
	s.push_back(CUTE(testFactoryMethodForInitializerList));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



