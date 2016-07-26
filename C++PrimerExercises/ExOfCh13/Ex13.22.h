#ifndef EX_13_22_H
#define EX_13_22_H

#include <string>
using std::string;

class HasPtr {
public:
	//constructors
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
	HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { }
	HasPtr &operator=(const HasPtr &);
	~HasPtr() { delete ps; }
private:
	string *ps;
	int i;
};

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
	auto newp = new string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}

#endif
