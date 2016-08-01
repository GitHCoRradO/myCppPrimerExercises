#ifndef EX_13_31_H
#define EX_13_31_H

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class HasPtr {
friend void swap(HasPtr &, HasPtr &);
friend void print_data(const HasPtr &);
public:
	HasPtr(const string &s = string(), int n = 0) : ps(new string(s)), i(n) { }
	HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { }
	HasPtr &operator=(HasPtr);
	bool operator<(const HasPtr &);
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

bool HasPtr::operator<(const HasPtr &rhs) {
	if(*ps < *rhs.ps)
		return true;
	else if(*ps == *rhs.ps) {
		if(i < rhs.i)
			return true;
		else
			return false;
	}
	else
		return false;
}

void print_data(const HasPtr &hp) {
	cout << *hp.ps << " " << hp.i;
}
#endif
