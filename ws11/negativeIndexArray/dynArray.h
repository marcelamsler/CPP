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
	using const_reverse_iterator = typename VectorType::const_reverse_iterator;
	VectorType vec{};

public:

	//Constructors
	dynArray() = default;
	dynArray(std::initializer_list<T> list) : vec(list){}
	dynArray(unsigned count, T value): vec(count, value){}

	template <typename ITER>
	dynArray(ITER begin, ITER end) : vec(begin, end){}

	//Element Access

	T& at(int index) {
		if (index < 0)
			return vec.at(vec.size() + index);
		else
			return vec.at(index);
	}

	T& at(int index) const {
			if (index < 0)
				return vec.at(vec.size() + index);
			else
				return vec.at(index);
	}

	T& operator[](int index) {
		return at(index);
	}

	T& operator[](int index) const{
		return at(index);
	}

	T& front () {
		return at(0);
	}

	T& back () {
		return at(size()-1);
	}

	//iterator-functions

	iterator begin () {
		return vec.begin();
	}

	const_iterator cbegin() const{
		return vec.cbegin();
	}

	iterator end () {
			return vec.end();
	}

	const_iterator cend() const{
			return vec.cend();
	}

	iterator rbegin () {
		return vec.rbegin();
	}

	const_reverse_iterator crbegin() const{
		return vec.crbegin();
	}

	iterator rend () {
			return vec.rend();
	}

	const_reverse_iterator crend() const{
			return vec.crend();
	}

	//Capacity

	bool empty() const {
		return vec.empty();
	}

	size_type size() const{
		return vec.size();
	}

	size_type capacity() const {
		return vec.capacity();
	}

	//Modifiers

	void clear() {
		vec.clear();
	}

	iterator erase (const_iterator pos) {
		return vec.erase(pos);
	}

	iterator erase (const_iterator first, const_iterator last) {
		return vec.erase(first, last);
	}

	void push_back(T element) {
		vec.push_back(element);
	}

	void pop_back () {
		vec.pop_back();
	}

	void resize (size_type newSize) {
		vec.resize(newSize);
	}

	void resize (size_type newSize, const T& value) {
			vec.resize(newSize, value);
	}

};

template <typename T>
inline dynArray<T> makeDynArray(std::initializer_list<T> list) {
	return dynArray<T> {list};
}



#endif /* DYNARRAY_H_ */
