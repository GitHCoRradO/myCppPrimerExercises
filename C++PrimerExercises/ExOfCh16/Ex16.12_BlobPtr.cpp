#include "./Ex16.12_BlobPtr.h"
#include <stdexcept>

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++() {
	check(curr, "increment past end of Blob");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--() {
	--curr;
	check(curr, "decrement past begin of Blob");
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("BlobPtrs points to different Blobs");
	return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("BlobPtrs points to different Blobs");
	return lhs.curr != rhs.curr;
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw std::runtime_error("BlobPtrs points to different Blobs");
	return lhs.curr < rhs.curr;
}
