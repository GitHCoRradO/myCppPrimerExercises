#ifndef EX_9_4_H
#define EX_9_4_H

#include <vector>
using std::vector;

bool int_in_range(vector<int>::const_iterator beg, vector<int>::const_iterator end, int i) {
	for(;beg != end; ++beg) {
		if(*beg == i)
			return true;
	}
	return false;
}

#endif
