#ifndef EX_9_4_H
#define EX_9_4_H

#include <iostream>
#include <vector>
using std::vector;

vector<int>::const_iterator int_found(vector<int>::const_iterator beg, vector<int>::const_iterator end, int i) {
	for(;beg != end; ++beg) {
		if(*beg == i)
			return beg;
	}
	std::cerr << "int i not found in range.returning an iterator to one past the last element." << std::endl;
	return end;
}

#endif
