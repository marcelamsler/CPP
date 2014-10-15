#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iostream>

struct Word {
	std::string word;
	Word(std::string wordInput);
	void readWord(std::istream &in);
};

inline std::istream& operator >>(std::istream &in, Word &word){
	word.readWord(in);
	return in;
}

inline std::ostream& operator << (std::ostream &out, Word &word){
	out << word.word;
	return out;
}


#endif /* WORD_H_ */
