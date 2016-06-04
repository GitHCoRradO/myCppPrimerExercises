#ifndef EX_12_22_H
#define EX_12_22_H

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
class ConstStrBlobPtr;
class StrBlob {
friend class ConstStrBlobPtr;
public:
        typedef vector<string>::size_type size_type;
        StrBlob();
        StrBlob(initializer_list<string> il);
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        //add and remove elements
        void push_back(const string &t) { data->push_back(t); }
        void pop_back();
        //element access
        string &front();
        string &back();
        string &front() const;
        string &back() const;
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



class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() : curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
	const string &deref() const;
	ConstStrBlobPtr &incr();
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

const string &ConstStrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
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
