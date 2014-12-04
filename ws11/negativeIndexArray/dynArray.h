#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <vector>
#include <iterator>

template <typename T>
class dynArray {
	using VectorType = std::vector<T>;
	using size_type = typename VectorType::size_type;
	using iterator = typename VectorType::iterator;
	using const_iterator = typename VectorType::const_iterator;
	using reverse_iterator = typename VectorType::reverse_iterator;
	using reverse_const_iterator = typename VectorType::const_reverse_iterator;
	VectorType vec{};

public:
	dynArray() = default;
	dynArray(std::initializer_list<T> list) : vec(list){}
	dynArray(unsigned count, T value): vec(count, value){}

	template <typename ITER>
	dynArray(ITER begin, ITER end) : vec(begin, end){}

	T& at(int index) {
		if (index < 0)
			return vec.at(vec.size() + index);
		else
			return vec.at(index);
	}

	size_type size() const{
		return vec.size();
	}

	T& operator[](int index) {
		return at(index);
	}

	//iterator-functions

	iterator begin () {
		return vec.begin();
	}

	const_iterator cbegin(){
		return vec.cbegin();
	}

	iterator end () {
			return vec.end();
	}

	const_iterator cend(){
			return vec.cend();
	}

	iterator rbegin () {
		return vec.rbegin();
	}

	const_iterator crbegin(){
		return vec.crbegin();
	}

	iterator rend () {
			return vec.rend();
	}

	const_iterator crend(){
			return vec.crend();
	}







};

template <typename T>
inline dynArray<T> makeDynArray(std::initializer_list<T> list) {
	return dynArray<T> {list};
}



#endif /* DYNARRAY_H_ */
