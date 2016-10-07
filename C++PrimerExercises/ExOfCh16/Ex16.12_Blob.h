#ifndef EX_16_12_BLOB_H
#define EX_16_12_BLOB_H

#include <vector>
using std::vector;
#include <initializer_list>
using std::initializer_list;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <string>
using std::string;

template <typename T> class Blob;

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;

	//constructors
	Blob() : data(make_shared<vector<T>>()) { }
	Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) { }

	//member functions
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	
	T &front();
	const T &front() const;
	T &back();
	const T &back() const;
	T &operator[](size_type);
	const T &operator[](size_type) const;
private:
	shared_ptr<vector<T>> data;
	void check(size_type, const string &) const;
};


#endif
