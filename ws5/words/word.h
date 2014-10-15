#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iosfwd>

struct Word {
	std::string word;
	Word(std::string wordInput):word{wordInput}{};
	void readWord(std::istream &in);
};

inline std::istream operator >>(std::istream &in, Word &word){
	word.readWord(in);
	return in;
}


#endif /* WORD_H_ */
