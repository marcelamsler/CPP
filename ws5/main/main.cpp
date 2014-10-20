#include "word.h"
#include "wordlist.h"
#include "iostream"
#include <list>
#include <algorithm>

int main(){
	std::list<Word> list = createWordList(std::cin);

	for_each(list.begin(), list.end(), [](Word w){
		std::cout << w << std::endl;
	});


}
