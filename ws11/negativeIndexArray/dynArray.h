#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <vector>

template <typename T>
class dynArray {
	using VectorType = std::vector<T>;
	using size_type = typename VectorType::size_type;
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

};

template <typename T>
inline dynArray<T> makeDynArray(std::initializer_list<T> list) {
	return dynArray<T> {list};
}



#endif /* DYNARRAY_H_ */
