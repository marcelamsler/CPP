#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <ring6.h>

void testValueCtorWithLargeInput() {

	Ring6 four { 19 };

	ASSERT_EQUAL(Ring6 { 4 }, four);

}

void testDefaultCtor() {

	Ring6 v { };

	ASSERT_EQUAL(0, v.value());

}

void testValueCtor() {

	Ring6 four { 4 };

	ASSERT_EQUAL(4, four.value());

}

void testOutputOperator() {

	std::ostringstream out;

	out << Ring6 { 4 };

	ASSERT_EQUAL("Ring6{4}", out.str());

}

void testAdditionWithInt() {

	Ring6 two { 2 };

	auto four = two + 2u;

	ASSERT_EQUAL(Ring6 { 4 }, four);

	ASSERT_EQUAL(typeid(Ring6).name(),

	typeid(decltype(four)).name());

}

void testAssignmentBackToIntExplicitCtor() {

	Ring6 three { 8 };

	unsigned u3 = three;

	auto eight = three + 5u;

	ASSERT_EQUAL(8u, eight);

	ASSERT_EQUAL(3u, u3);

	ASSERT_EQUAL(3u, three);

}

void testAdditionWithIntExplicitCtor() {

	Ring6 two { 2 };

	auto four = two + Ring6 { 2u };

	ASSERT_EQUAL(Ring6 { 4 }, four);

	ASSERT_EQUAL(typeid(Ring6).name(),

	typeid(decltype(four)).name());

}

void runAllTests(int argc, char const *argv[]) {
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testValueCtorWithLargeInput));
	s.push_back(CUTE(testDefaultCtor));
	s.push_back(CUTE(testValueCtor));
	s.push_back(CUTE(testOutputOperator));
	s.push_back(CUTE(testAdditionWithInt));
	s.push_back(CUTE(testAssignmentBackToIntExplicitCtor));
	s.push_back(CUTE(testAdditionWithIntExplicitCtor));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}

