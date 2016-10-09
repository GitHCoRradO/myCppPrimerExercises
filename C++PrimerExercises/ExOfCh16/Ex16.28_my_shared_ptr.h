#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H

#include <functional>
#include "./Ex16.28_Delete.h"


template <typename T> class My_shared_ptr;

template <typename T>
void swap(My_shared_ptr<T> &lhs, My_shared_ptr<T> &rhs) {
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.ref_count, rhs.ref_count);
	swap(lhs.deleter, rhs.deleter);
}
/*  operator== for std::function<void (T *)> objects not easy to define.

template <typename T>
bool operator==(My_shared_ptr<T> &lhs, My_shared_ptr<T> &rhs) {
	return lhs.ptr == rhs.ptr && lhs.ref_count == rhs.ref_count && ;
}
*/

template <typename T>
class My_shared_ptr {
friend void swap<T>(My_shared_ptr<T> &, My_shared_ptr<T> &);
//friend bool operator==<T> (const My_shared_ptr<T> &, const My_shared_ptr<T> &);

public:
	//constructors
	My_shared_ptr() : ptr(nullptr), ref_count(nullptr), deleter(Delete()) { }

	explicit My_shared_ptr(T *p) : ptr(p), ref_count(new size_t(1)), deleter(Delete()) { }

	My_shared_ptr(T *p, const std::function<void (T *)> &d) :
	ptr(p), ref_count(new size_t(1)), deleter(d) { }
	
	//copy constructor
	My_shared_ptr(const My_shared_ptr &msp) : ptr(msp.ptr), ref_count(msp.ref_count),
	deleter(msp.deleter)
	{ ++*ref_count; }

	//copy assignment operator
	My_shared_ptr &operator=(const My_shared_ptr &rhs) {
		++*rhs.ref_count;
		decrement_n_destroy();
		ptr = rhs.ptr;
		ref_count = rhs.ref_count;
		deleter = rhs.deleter;
		return *this;
	}
	
	//move constructor
	My_shared_ptr(My_shared_ptr &&msp) noexcept :
	ptr(msp.ptr), ref_count(msp.ref_count), deleter(std::move(msp.deleter))
	{ msp.ptr = nullptr; msp.ref_count = nullptr; }

	//move assignment operator
	My_shared_ptr &operator=(My_shared_ptr &&rhs) noexcept {
		//I do not think this implementation guards against self assignment
		::swap(*this, rhs);
		rhs.decrement_n_destroy();
		return *this;
	}		
	

	//other utilities
	T *get() const { return ptr; }

	bool unique() { return *ref_count == 1; }

	size_t use_count() { return *ref_count; }

	operator bool() const { return ptr ? true : false; }

	T &operator*() const { return *ptr; }

	T *operator->() const { return &*ptr; }

	void swap(My_shared_ptr &rhs) { ::swap(*this, rhs); }

	void reset() { decrement_n_destroy(); }

	void reset(T *p) {
		if (ptr != p) {
			decrement_n_destroy();
			ptr = p;
			ref_count = new size_t(1);
			deleter = Delete();
		}
	}

	void reset(T *p, const std::function<void (T *)> &d) {
		reset(p);
		deleter = d;
	}

	//destructor
	~My_shared_ptr() { decrement_n_destroy(); }

private:
	void decrement_n_destroy() {
		if(ptr && --*ref_count == 0) {
			delete ref_count;
			deleter(ptr);
		}
		else if(!ptr)
			delete ref_count;
		ref_count = nullptr;
		ptr = nullptr;
	}
	
	T *ptr;
	size_t *ref_count;
	std::function<void (T *)> deleter;

};
#endif
