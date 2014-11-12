#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "word.h"
#include "kwic.h"
#include <sstream>
#include <vector>
#include <stdexcept>

void wordInvariantTest() {
	ASSERT_THROWS(Word w{" "}, std::out_of_range);
}

void emptyWordTest() {
	ASSERT_THROWS(Word w{""}, std::out_of_range);
}

void wordInputOperatorTest1() {
	Word w { "compl" };
	std::stringstream is { "compl33tely ~ weird !!??!! 4matted in_put" };

	Word readw {};
	is >> readw;
	ASSERT_EQUAL(w.getWord(), readw.getWord());
}

void wordInputOperatorTest2() {
	Word w { "tely" };
	std::stringstream is { "33tely ~ weird !!??!! 4matted in_put" };
	Word readw {};
	is >> readw;
	ASSERT_EQUAL(w.getWord(), readw.getWord());
}

void wordOutputOperatorTest() {
	Word w1 { "testfirstWord" };
	Word w2 { "testsecondWord" };
	std::stringstream os { };
	os << w1 << ", " << w2;
	ASSERT_EQUAL("testfirstWord, testsecondWord", os.str());

}

void wordCompareTest1() {
	Word w1 { "a" };
	Word w2 { "b" };

	ASSERT(w1 < w2);
	ASSERT(w1 <= w2);
	ASSERT(w2 > w1);
	ASSERT(w2 >= w1);
	ASSERT(w1 != w2);
}

void wordCompareCaseTest() {
	Word w1 { "a" };
	Word w2 { "B" };

	ASSERT(w1 < w2);
	ASSERT(w1 <= w2);
	ASSERT(w2 > w1);
	ASSERT(w2 >= w1);
	ASSERT(w1 != w2);
}

void wordEqualityTest() {
	Word w1 { "HelloWorld" };
	Word w2 { "hEllowOrld" };
	ASSERT(w1 == w2);
}

void wordEOFTest() {
	std::stringstream input { "I lose my word" };
	std::vector<Word> inputWords { std::istream_iterator<Word> { input }, std::istream_iterator<Word> { } };
	ASSERT_EQUAL(4, inputWords.size());
}
void readEmptyWord() {
	std::stringstream input { "" };
	Word w { };
	input >> w;
	ASSERT(!input);
	ASSERT_EQUAL(Word { }, w);
}
void consecutiveReads() {
	std::stringstream input { "one two" };
	Word w { };
	input >> w;
	ASSERT_EQUAL(Word { "one" }, w);
	input >> w;
	ASSERT_EQUAL(Word { "two" }, w);
}

void createVariationsTest() {
	VariationCreator creator { };
	std::vector<Word> lineVector { std::string { "b" }, std::string { "c" }, std::string { "d" } };
	creator.createVariations(lineVector);
	ASSERT_EQUAL(3, creator.getVariations().size());
}

void kwicTestOneLine() {
	std::stringstream is { "ab cd efd" };
	std::stringstream os { };

	printKwicVariations(is, os);

	ASSERT_EQUAL("\nab cd efd \ncd efd ab \nefd ab cd \n", os.str());
}

void kwicTestOneLineWithWeirdInput() {
	std::stringstream is { "Compl33tely ~ weird !!??!! 4matted in_put" };
	std::stringstream os { };

	printKwicVariations(is, os);

	ASSERT_EQUAL("\nCompl tely weird matted in put \n"
			"in put Compl tely weird matted \n"
			"matted in put Compl tely weird \n"
			"put Compl tely weird matted in \n"
			"tely weird matted in put Compl \n"
			"weird matted in put Compl tely \n", os.str());
}

void kwicTestTwoLine() {
	std::stringstream is { "this is a test\n this is another test" };
	std::stringstream os { };
	printKwicVariations(is, os);

	ASSERT_EQUAL("\na test this is \n"
			"another test this is \n"
			"is a test this \n"
			"is another test this \n"
			"test this is a \n"
			"test this is another \n"
			"this is a test \n"
			"this is another test \n", os.str());
}

void vectorPerLineInputOperatorTest() {
	std::stringstream is { };
	std::stringstream os { };
	std::vector<std::vector<Word>> lineContainer { };

	is << "this is\n a test\n this is\n another test";

	while (is.good()) {
		std::vector<Word> lineVector;
		is >> lineVector;
		lineContainer.push_back(lineVector);
	}

	ASSERT_EQUAL(4, lineContainer.size());

	std::vector<Word> firstVector { Word { "this" }, Word { "is" } };
	std::vector<Word> lastVector { Word { "another" }, Word { "test" } };

	ASSERT_EQUAL(firstVector, lineContainer.at(0));
	ASSERT_EQUAL(lastVector, lineContainer.at(3));
}

void runAllTests(int argc, char const *argv[]) {
	cute::suite s;
	s.push_back(CUTE(wordInvariantTest));
	s.push_back(CUTE(emptyWordTest));
	s.push_back(CUTE(wordInputOperatorTest1));
	s.push_back(CUTE(wordInputOperatorTest2));
	s.push_back(CUTE(wordOutputOperatorTest));
	s.push_back(CUTE(wordCompareTest1));
	s.push_back(CUTE(wordCompareCaseTest));
	s.push_back(CUTE(wordEqualityTest));
	s.push_back(CUTE(wordEOFTest));
	s.push_back(CUTE(readEmptyWord));
	s.push_back(CUTE(consecutiveReads));
	s.push_back(CUTE(createVariationsTest));
	s.push_back(CUTE(kwicTestOneLine));
	s.push_back(CUTE(kwicTestOneLineWithWeirdInput));
	s.push_back(CUTE(kwicTestTwoLine));
	s.push_back(CUTE(vectorPerLineInputOperatorTest));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}

