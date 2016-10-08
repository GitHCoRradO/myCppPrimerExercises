#ifndef EX_16_16_H
#define EX_16_16_H

#include <memory>
using std::allocator;
#include <utility>
using std::pair;
#include <initializer_list>
using std::initializer_list;

template <typename T>
class Vec {
public:
	Vec() :
	elements(nullptr), first_free(nullptr), cap(nullptr) { }
	Vec(initializer_list<T>);
	Vec(const Vec &);
	Vec &operator=(const Vec &);
	~Vec();
	void push_back(const T &);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T *begin() const { return elements; }
	T *end() const { return first_free; }
private:
	allocator<T> alloc;
	void chk_n_alloc()
	{ if (size() == capacity()) reallocate(); }
	pair<T *, T *> alloc_n_copy(const T *, const T *);
	void free();
	void reallocate();
	T *elements;
	T *first_free;
	T *cap;
};

template <typename T>
void Vec<T>::free() {
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

template <typename T>
void Vec<T>::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::push_back(const T &elem) {
	chk_n_alloc();
	alloc.construct(first_free++, elem);
}

template <typename T>
pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e) {
	auto data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
Vec<T>::Vec(const Vec &v) {
	auto newdata = alloc_n_copy(v.begin(), v.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::~Vec() { free(); }

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T>
Vec<T>::Vec(initializer_list<T> il) {
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
#endif
