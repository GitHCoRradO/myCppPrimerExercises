#ifndef EX_14_STRBLOB_STRBLOBPTR_CONSTSTRBLOBPTR_H
#define EX_14_STRBLOB_STRBLOBPTR_CONSTSTRBLOBPTR_H

#include <memory>
#include <string>
#include <initializer_list>
#include <vector>
#include <stdexcept>
using std::size_t;
using std::string;
using std::initializer_list;
using std::weak_ptr;
using std::shared_ptr;
using std::vector;
using std::runtime_error;
using std::out_of_range;
using std::make_shared;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
friend class StrBlobPtr;
friend class ConstStrBlobPtr;
friend bool operator==(const StrBlob &, const StrBlob &);
friend bool operator!=(const StrBlob &, const StrBlob &);
friend bool operator<(const StrBlob &, const StrBlob &);
friend bool operator>(const StrBlob &, const StrBlob &);
friend bool operator<=(const StrBlob &, const StrBlob &);
friend bool operator>=(const StrBlob &, const StrBlob &);
public:
        typedef vector<string>::size_type size_type;
        StrBlob();
        StrBlob(initializer_list<string> il);
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
	//subscript operator
	string &operator[](size_type t) { check(t, "out of range"); return data->at(t); }
	const string &operator[](size_type t) const { check(t, "out of range"); return data->at(t); }
        //add and remove elements
        void push_back(const string &t) { data->push_back(t); }
        void pop_back();
        //element access
        string &front();
        string &back();
        string &front() const;
        string &back() const;

        StrBlobPtr begin();
        StrBlobPtr end();

	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;
	
private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }

void StrBlob::check(size_type i, const string &msg) const {
        if (i >= data->size())
                throw out_of_range(msg);
}

string &StrBlob::front() {
        check(0, "front on empty StrBlob");
        return data->front();
}
string &StrBlob::front() const {
        check(0, "front on empty StrBlob");
        return data->front();
}
string &StrBlob::back() {
        check(0, "back on empty StrBlob");
        return data->back();
}
string &StrBlob::back() const {
        check(0, "back on empty StrBlob");
        return data->back();
}

void StrBlob::pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
}



class StrBlobPtr {
friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }

	//subscript operator
	string &operator[](size_t);
	const string &operator[](size_t) const;

	//pre- and post- increment and decrement operators
	StrBlobPtr &operator++();
	StrBlobPtr &operator--();
	
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);

	//pointer arithmetic operators
	StrBlobPtr operator+(size_t) const;
	StrBlobPtr operator-(size_t) const;
	StrBlobPtr &operator+=(size_t);
	StrBlobPtr &operator-=(size_t);

	//dereference andd arrow operators
	string &operator*() const { 
		auto p = check(curr, "dereference past the end of vector");
		return (*p)[curr];
	}
	string *operator->() const {
		return &this->operator*();
	}
	
private:
	shared_ptr<vector<string>> check(size_t, const string &) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}



StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() {
                auto ret = StrBlobPtr(*this, data->size());
                return ret;
        }
bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
	return (*lhs.data) == (*rhs.data);
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
	return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
	return (*lhs.data) < (*rhs.data);
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
	return !(lhs == rhs || lhs < rhs);
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
	return lhs < rhs || lhs == rhs;
}
  
bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
	return lhs > rhs || lhs == rhs;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs < rhs || lhs == rhs);
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs < rhs || lhs == rhs;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs > rhs || lhs == rhs;
}

inline string &StrBlobPtr::operator[](size_t t) {
	auto p = check(t, "out of range");
	return p->at(t);
}
inline const string &StrBlobPtr::operator[](size_t t) const {
	auto p = check(t, "out of range");
	return p->at(t);
}

StrBlobPtr &StrBlobPtr::operator++() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
StrBlobPtr &StrBlobPtr::operator--() {
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}
StrBlobPtr StrBlobPtr::operator--(int) {
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n) {
	curr += n;
	check(curr + 1, "StrBlobPtr past the end of vector"); 
	return *this;
}
StrBlobPtr &StrBlobPtr::operator-=(size_t n) {
	curr -= n;
	check(curr, "StrBlobPtr beyond the begin of vector");
	return *this;
}
StrBlobPtr StrBlobPtr::operator+(size_t n) const {
	StrBlobPtr ret = *this;
	ret += n;
	return ret;
}
StrBlobPtr StrBlobPtr::operator-(size_t n) const {
	StrBlobPtr ret = *this;
	ret -= n;
	return ret;
}

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() : curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
	ConstStrBlobPtr &incr();

	//dereference and arrow operators
	const string &operator*() const {
		auto p = check(curr, "deference past the end");
		return (*p)[curr];
	}
	const string *operator->() const {
		return &this->operator*();
	}
	
private:
	shared_ptr<vector<string>> check(size_t, const string &) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound ConstStrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}


ConstStrBlobPtr &ConstStrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() const {
                auto ret = ConstStrBlobPtr(*this, data->size());
                return ret;
        }


#endif
