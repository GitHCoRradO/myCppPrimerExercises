#ifndef EX13_13_H
#define EX13_13_H

#include <iostream>
using std::cout;
using std::endl;

struct X {
	X() { cout << "X()" << endl; }
	X(const X&) { cout << "X(const X&)" << endl; }
	X& operator=(const X&) { cout << "X& operator=(const X&)" << endl; return *this; }
	~X() { cout << "~X()" << endl; }
};

#endif
