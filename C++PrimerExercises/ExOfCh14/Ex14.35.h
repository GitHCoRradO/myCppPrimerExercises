#ifndef EX_14_35_H
#define EX_14_35_H

#include <iostream>
using std::istream;
#include <string>
using std::string;

class ReadLine {
public:
	string operator()(istream &is) const;
};
inline string ReadLine::operator()(istream &is) const {
	string line;
	getline(is, line);
	if (is)
		return line;
	else
		return string();
}
#endif
