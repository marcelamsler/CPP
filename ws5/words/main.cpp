#include "word.h"
#include "iostream"
#include <vector>
#include <algorithm>

int main(){
	std::vector<Word> list{};

	while(std::cin.good()){
		Word w{""};
		std::cin >> w;
		list.push_back(w);
	}

	for_each(list.begin(), list.end(), [](Word w){
		std::cout << w;
	});


}
