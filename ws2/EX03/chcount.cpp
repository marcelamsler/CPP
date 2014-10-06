#include <iterator>
#include <algorithm>
#include <string>

int chcount (std::istream &in) {
	return std::distance(std::istream_iterator<char>{in},std::istream_iterator<char>{});

}

int wcount (std::istream &in) {
	return std::distance(std::istream_iterator<std::string>{in},std::istream_iterator<std::string>{});

}

int acount (std::istream &in) {
	return std::count(std::istreambuf_iterator<char>{in},std::istreambuf_iterator<char>{}, 'a');

}

int countn (std::istream &in) {
	return std::count(std::istreambuf_iterator<char>{in},std::istreambuf_iterator<char>{}, '\n');
}

int sumi (std::istream &in) {
	return std::accumulate(std::istream_iterator<int>{in},std::istream_iterator<int>{}, 0);

}

std::vector<std::vector<unsigned int>> multab (size_t multvalue) {
	std::vector<std::vector<unsigned int>> w(multvalue);
	unsigned int i{1};

	std::for_each(w.begin(),w.end(),[&](std::vector<unsigned int>&innervector){
		unsigned int j{1};
		std::generate_n(std::back_inserter(innervector),multvalue,[&j, &i]{return j++*i;});
		++i;
	});
	return w;

}





