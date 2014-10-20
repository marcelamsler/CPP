#ifndef WORDLIST_H_
#define WORDLIST_H_

#include "word.h"
#include <iostream>
#include <list>

std::list<Word> createWordList(std::istream &in){
	std::list<Word> list{};

	while (in.good()){
		Word w{""};
		std::cin >> w;
		list.push_back(w);
	}
	return list;
}



#endif /* WORDLIST_H_ */
