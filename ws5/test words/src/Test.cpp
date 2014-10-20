#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "word.h"
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

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(wordInvariantTest));
	s.push_back(CUTE(wordInputOperatorTest1));
	s.push_back(CUTE(wordInputOperatorTest2));
	s.push_back(CUTE(wordOutputOperatorTest));
	s.push_back(CUTE(wordCompareTest1));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



