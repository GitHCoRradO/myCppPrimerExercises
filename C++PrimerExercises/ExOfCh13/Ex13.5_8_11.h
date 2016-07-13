#ifndef EX_13_5_8_11
#define EX_13_5_8_11

#include <string>
using std::string;

class HasPtr {
public:
	//constructors
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
	//copy constructor
	HasPtr(const HasPtr&);
	//copy-assignment operator
	HasPtr& operator=(const HasPtr&);
	//destructor
	~HasPtr() { }
private:
	string *ps;
	int i;
};
HasPtr::HasPtr(const HasPtr &hp) {
	ps = new string(*hp.ps);
	i = hp.i;
}

HasPtr& HasPtr::operator=(const HasPtr& rho) {
	ps = new string(*rho.ps);
	i = rho.i;
	return *this;
}

#endif
