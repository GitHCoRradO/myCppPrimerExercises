#ifndef EX_16_12_BLOBPTR_H
#define EX_16_12_BLOBPTR_H

#include "./Ex16.12_Blob.h"

using std::weak_ptr;

template <typename T> class BlobPtr;
template <typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> class BlobPtr {
friend bool operator==<T>(const BlobPtr&, const BlobPtr&);
friend bool operator!=<T>(const BlobPtr&, const BlobPtr&);
friend bool operator< <T>(const BlobPtr&, const BlobPtr&);
public:
	//constructors
	BlobPtr() : curr(0) { }
	BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
	
	//member functions
	T &operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	
	BlobPtr operator++();
	BlobPtr operator--();

	BlobPtr operator++(int);
	BlobPtr operator--(int);
private:
	shared_ptr<vector<T>> check(size_t, const string &) const;
	weak_ptr<vector<T>> wptr;
	size_t curr;
};

#endif
