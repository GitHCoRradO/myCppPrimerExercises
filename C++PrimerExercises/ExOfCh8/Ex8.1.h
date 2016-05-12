#ifndef EX_8_1_H
#define EX_8_1_H

#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::cout;
using std::endl;

istream &func(istream &is) {
	string str;
	while (is >> str) {
		cout << str << endl;
	}
	is.clear();
	return is;
}

#endif
