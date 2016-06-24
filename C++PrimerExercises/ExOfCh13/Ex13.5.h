#ifndef EX_13_5
#define EX_13_5

#include <string>
using std::string;

class HasPtr {
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
	HasPtr(const HasPtr&);
private:
	string *ps;
	int i;
};
HasPtr::HasPtr(const HasPtr &hp) {
	ps = new string(*hp.ps);
	i = hp.i;
}

#endif
