#ifndef EX_9_49_H
#define EX_9_49_H

#include <string>
using std::string;

unsigned number_of_a_d(const string &s) {
	unsigned num = 0;
	string::size_type pos = 0;
	while ((pos = s.find_first_not_of("aceimnorsuvwxz",pos)) != string::npos) {
		++num;
		++pos;
	}
	return num;
}

#endif
