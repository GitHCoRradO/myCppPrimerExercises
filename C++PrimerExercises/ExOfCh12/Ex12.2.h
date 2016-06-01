#ifndef EX_12_2_H
#define EX_12_2_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>
using std::vector;
using std::string;
using std::shared_ptr;
using std::initializer_list;
using std::out_of_range;
using std::make_shared;

class StrBlob {
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

#endif
