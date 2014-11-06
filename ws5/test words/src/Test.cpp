#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "word.h"
#include "kwic.h"
#include <sstream>
#include <vector>
#include <stdexcept>


void wordInvariantTest(){
	ASSERT_THROWS(Word w{" "}, std::out_of_range);
}

void wordInputOperatorTest1() {
	Word w{"compl"};
	std::stringstream is {"compl33tely ~ weird !!??!! 4matted in_put"};

	Word readw {""};
	is >> readw;
	ASSERT_EQUAL(w.word, readw.word);
}

void wordInputOperatorTest2() {
	Word w{"tely"};
	std::stringstream is {"33tely ~ weird !!??!! 4matted in_put"};
	Word readw {""};
	is >> readw;
	ASSERT_EQUAL(w.word, readw.word);
}

void wordOutputOperatorTest(){
	Word w1{"testfirstWord"};
	Word w2{"testsecondWord"};
	std::stringstream os{};
	os << w1 << ", " << w2;
	ASSERT_EQUAL("testfirstWord, testsecondWord", os.str());

}

void wordCompareTest1(){
	Word w1{"a"};
	Word w2{"b"};

	ASSERT(w1 < w2);
	ASSERT(w1 <= w2);
	ASSERT(w2 > w1);
	ASSERT(w2 >= w1);
	ASSERT(w1 != w2);
}

void wordEqualityTest(){
	Word w1{"HelloWorld"};
	Word w2{"helloworlD"};
	ASSERT(w1 == w2);
}

void createVariationsTest() {
	VariationCreator creator{};
	std::vector<Word> lineVector{std::string{"b"},std::string{"c"},std::string{"d"}};
	creator.createVariations(lineVector);
	ASSERT_EQUAL(3, creator.variations.size());

	std::vector<Word> secondVariation{std::string{"c"},std::string{"d"},std::string{"b"}};
	std::vector<Word> thirdVariation{std::string{"d"},std::string{"b"},std::string{"c"}};

	auto it = creator.variations.begin();
	ASSERT_EQUAL(lineVector, *it++);
	ASSERT_EQUAL(secondVariation, *it++);
	ASSERT_EQUAL(thirdVariation, *it);
}

void kwicTestOneLine() {
	std::stringstream is{};
	std::stringstream os{};
	is << "ab cd efd";
	printKwicVariations(is, os);

	ASSERT_EQUAL( "ab cd efd \ncd efd ab \nefd ab cd \n", os.str());
}

void kwicTestTwoLine() {
	std::stringstream is{};
	std::stringstream os{};
	is << "this is a test\n this is another test";
	printKwicVariations(is, os);

	ASSERT_EQUAL(
			"a test this is \n"
			"another test this is \n"
			"is a test this \n"
			"is another test this \n"
			"test this is a \n"
			"test this is another \n"
			"this is a test \n"
			"this is another test \n",
			os.str()
	);
}

void vectorPerLineInputOperatorTest() {
	std::stringstream is{};
	std::stringstream os{};
	std::vector<std::vector<Word>> lineContainer{};

	is << "this is\n a test\n this is\n another test";

	while(is.good()) {
		std::vector<Word> lineVector;
		is >> lineVector;
		lineContainer.push_back(lineVector);
	}

	ASSERT_EQUAL(4, lineContainer.size());
}



void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(wordInvariantTest));
	s.push_back(CUTE(wordInputOperatorTest1));
	s.push_back(CUTE(wordInputOperatorTest2));
	s.push_back(CUTE(wordOutputOperatorTest));
	s.push_back(CUTE(wordCompareTest1));
	s.push_back(CUTE(wordEqualityTest));
	s.push_back(CUTE(createVariationsTest));
	s.push_back(CUTE(kwicTestOneLine));
	s.push_back(CUTE(kwicTestTwoLine));
	s.push_back(CUTE(vectorPerLineInputOperatorTest));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



