#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iostream>
#include <boost/operators.hpp>
#include <boost/algorithm/string.hpp>


struct Word
		: boost::less_than_comparable<Word>
		, boost::equality_comparable<Word> {
		Word(std::string const wordInput);
	std::string word;
void readWord(std::istream &in);
	bool operator <(Word const& otherWord) const;
	inline bool operator ==(Word const& otherWord) const {
		std::string w1{word};
		std::string w2{otherWord.word};
		boost::algorithm::to_lower(w1);
		boost::algorithm::to_lower(w2);
		return  w1 == w2 ;
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
