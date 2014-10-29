#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <palin.h>

void testAnnaPalindrome() {

	ASSERT(is_palindrome("Anna"));
}

void testOttoPalindrome() {

	ASSERT(is_palindrome("Otto"));
}

void testLongerPalindrome(){
	ASSERT(is_palindrome("blaBlaoOalbalb"));
}

void testWrongPalindrome(){
	ASSERT(!is_palindrome("blaBlabööbalblb"));
}


void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testAnnaPalindrome));
	s.push_back(CUTE(testOttoPalindrome));
	s.push_back(CUTE(testLongerPalindrome));
	s.push_back(CUTE(testWrongPalindrome));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



