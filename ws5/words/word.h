#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iostream>
#include <boost/operators.hpp>

struct Word
		: boost::less_than_comparable<Word>
		, boost::equality_comparable<Word>{
	std::string word;
	Word(std::string const wordInput);
	void readWord(std::istream &in);
	bool operator <(Word const& otherWord) const;
	bool operator ==(Word const& otherWord) const {
		return word == otherWord.word;
	}
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
