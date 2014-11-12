#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>


struct Word {

	Word(std::string const& wordInput);
	Word() = default;

	std::string getWord() const{return word;};

	void readWord(std::istream &in);

	bool operator <(Word const& otherWord) const {
		return std::lexicographical_compare(word.begin(), word.end(), otherWord.word.begin(), otherWord.word.end(), [](char const& c1, char const& c2) {
			return tolower(c1) < tolower(c2);
		});
	}

	bool operator >(Word const& otherWord) const {
			return  otherWord < *this;
		}

	bool operator ==(Word const& otherWord) const {
			return !(*this < otherWord) && !(*this > otherWord);
	}

	bool operator !=(Word const& otherWord) const {
				return !(*this == otherWord);
	}

	bool operator <=(Word const& otherWord) const {
		return *this < otherWord || *this == otherWord;
	}

	bool operator >=(Word const& otherWord) const {
		return *this > otherWord || *this == otherWord;
	}

		private:
			std::string word;
};

inline std::istream& operator >>(std::istream &in, Word &word){
	word.readWord(in);
	return in;
}

inline std::ostream& operator << (std::ostream &out, Word const& word){
	out << word.getWord();
	return out;
}


#endif /* WORD_H_ */
