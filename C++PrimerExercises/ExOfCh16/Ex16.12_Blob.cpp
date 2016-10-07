#include "./Ex16.12_Blob.h"

#include <stdexcept>
using std::out_of_range;

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}

template <typename T>
T &Blob<T>::front() {
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
const T &Blob<T>::front() const {
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T &Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
const T &Blob<T>::back() const {
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T &Blob<T>::operator[](size_type i) {
	check(i, "out of range of Blob");
	return (*data)[i];
}

template <typename T>
const T &Blob<T>::operator[](size_type i) const {
	check(i, "out of range of Blob");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
	check(0, "pop back on empty Blob");
	data->pop_back;
}

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
	return lhs.data == rhs.data;
} 
