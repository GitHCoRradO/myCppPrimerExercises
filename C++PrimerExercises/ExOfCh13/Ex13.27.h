#ifndef EX_13_27_H
#define EX_13_27_H
#include <string>
using std::string;
using std::size_t;

class HasPtr {
public:
	//constructors
	HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) { }
	HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
	HasPtr& operator=(const HasPtr&);
	~HasPtr();
private:
	string *ps;
	int i;
	size_t *use;
};
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
	++*rhs.use;
	if(--*use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use =rhs.use;
	return *this;
}
HasPtr::~HasPtr() {
	if(--*use == 0) {
		delete ps;
		delete use;
	}
}
#endif
