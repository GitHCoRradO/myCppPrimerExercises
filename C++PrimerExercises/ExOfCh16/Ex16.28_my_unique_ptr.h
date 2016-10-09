#ifndef EX_16_28_MY_UNIQUE_PTR_H
#define EX_16_28_MY_UNIQUE_PTR_H

#include "./Ex16.28_Delete.h"

template <typename, typename> class My_unique_ptr;
template <typename T, typename D>
void swap(My_unique_ptr<T, D> &, My_unique_ptr<T, D> &);


template <typename T, typename D = Delete>
class My_unique_ptr {
friend void swap<T, D>(My_unique_ptr<T, D> &, My_unique_ptr<T, D> &);

public:
	//constructors
	My_unique_ptr() = default;
	
	explicit My_unique_ptr(T *p) : ptr(p) { }

	//copy and copy assignment prevented
	My_unique_ptr(const My_unique_ptr &) = delete;
	My_unique_ptr &operator=(const My_unique_ptr &) = delete;

	//move constructor
	My_unique_ptr(My_unique_ptr &&mup) noexcept : ptr(mup.ptr) { mup.ptr = nullptr; }

	//move assignment operator
	My_unique_ptr &operator=(My_unique_ptr &&rhs) noexcept {
		if (ptr != rhs.ptr) {
			deleter(ptr);
			ptr = nullptr;
			::swap(*this, rhs);
		}
		return *this;
	}

	//other utilities
	T &operator*() const { return *ptr; }

	T *operator->() const { return &*ptr; }
	
	operator bool() const { return ptr ? true : false; }

	T *get() const { return ptr; }

	void swap(My_unique_ptr &mup) { ::swap(*this, mup); }

	void reset() { deleter(ptr); ptr = nullptr; }

	void reset(T *p) { deleter(ptr); ptr = p; }

	T *release() { T *ret = ptr; ptr = nullptr; return ret; }

	//destructor
	~My_unique_ptr() { deleter(ptr); }

private:
	T *ptr;
	D deleter = D();
};
template <typename T, typename D>
inline void swap(My_unique_ptr<T, D> &lhs, My_unique_ptr<T, D> &rhs) {
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.deleter, rhs.deleter);
}
#endif
