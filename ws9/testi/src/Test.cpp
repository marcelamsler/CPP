#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <functional>

using std::placeholders::_1;
using std::placeholders::_2;

void sumTest() {
	double x {-4.1};
	double y {34.5};
	auto func = std::bind(std::plus<double>{}, _1, _2);
	ASSERT_EQUAL(x + y, func(x, y));
}

void expression2Test() {
	double x {-4.1};
	double y {34.5};
	auto func = std::bind(std::minus<double>{}, std::bind(std::multiplies<double>{}, 2, _1),
			std::bind(std::divides<double>{}, _2, 3));
	ASSERT_EQUAL((2 * x) - (y / 3), func(x, y));
}

void expression3Test() {
	unsigned x {42};
	unsigned y {4};
	auto func = std::bind(std::modulus<unsigned>{}, std::bind(std::multiplies<unsigned>{}, _1, _1), _2);
	ASSERT_EQUAL((x * x) % y, func(x, y));
}

void expression4Test() {
	double x {42};
	auto func = std::bind(static_cast<double(*)(double)>(&std::sqrt), std::bind(std::multiplies<double>{}, _1, _1));
	ASSERT_EQUAL(std::fabs(x), func(x));
}

void expression5Test(){
	double x {4.0};
	double y {2.0};
	auto xDivBy2 = std::bind(std::divides<double>{}, _1, 2);
	auto firstExp = std::bind(std::negate<double>{}, xDivBy2);
	auto subSqrtExp = std::bind(std::multiplies<double>{}, xDivBy2, std::bind(std::minus<double>{}, xDivBy2, _2));
	auto secondExp = std::bind(static_cast<double(*)(double)>(&std::sqrt), subSqrtExp);
	auto func = std::bind(std::plus<double>{},firstExp, secondExp);

	ASSERT_EQUAL((-(x/2) + std::sqrt((x/2)*((x/2) - y))), func(x, y));
}



void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(sumTest));
	s.push_back(CUTE(expression2Test));
	s.push_back(CUTE(expression3Test));
	s.push_back(CUTE(expression4Test));
	s.push_back(CUTE(expression5Test));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



