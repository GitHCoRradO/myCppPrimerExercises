#ifndef EX_13_30_H
#define EX_13_30_H

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class HasPtr {
friend void swap(HasPtr &, HasPtr &);
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
	HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { }
	HasPtr &operator=(HasPtr);
	~HasPtr() { delete ps; }
private:
	string *ps;
	int i;
};

HasPtr &HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	cout << "swap(HasPtr &,HasPtr &); called!" << endl;
}

#endif
