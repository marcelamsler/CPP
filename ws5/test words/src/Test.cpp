#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "word.h"
#include <sstream>
#include <vector>

void firstWordTest() {
	Word w{"compl"};
	std::stringstream is {"compl33tely ~ weird !!??!! 4matted in_put"};

	Word readw {""};
	is >> readw;
	ASSERT_EQUAL(w.word, readw.word);
}

void secondWordTest() {
	Word w{"tely"};
	std::stringstream is {"33tely ~ weird !!??!! 4matted in_put"};

	Word readw {""};
	is >> readw;
	ASSERT_EQUAL(w.word, readw.word);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(firstWordTest));
	s.push_back(CUTE(secondWordTest));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



