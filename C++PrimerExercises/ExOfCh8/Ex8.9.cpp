#include <iostream>
#include <sstream>
#include <string>
#include "./Ex8.1.h"
using std::string;

int main() {
	string str("I am the king of this World!");
	std::istringstream sstrm(str);
	//std::istringstream &is = func(sstrm);
	/*
	Ex8.9.cpp:10:31: error: invalid initialization of reference of type ‘std::istringstream& {aka std::__cxx11::basic_istringstream<char>&}’ from expression of type ‘std::istream {aka std::basic_istream<char>}’
  std::istringstream &is = func(sstrm);
	*/
	std::istream &is = func(sstrm);
	std::cout << is.good() << endl;	//this endl does not use std:: in this source file.but "using std::endl;" is written in Ex8.1.h.  Does this affect the endl here?
	return 0;
}
