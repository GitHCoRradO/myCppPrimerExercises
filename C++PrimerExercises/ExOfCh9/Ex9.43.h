#ifndef EX_9_43_H
#define EX_9_43_H

#include <string>
using std::string;


//return the index of substr in mainstr after the position pos in mainstr
unsigned index_of_sub(const string &mainstr, const string &substr, unsigned pos) {
	unsigned i = pos, j = 0;
	while ((i <= mainstr.size() - 1) && (j <= substr.size() - 1)) {
		if(mainstr[i] == substr[j]) {
			++i;
			++j;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= substr.size())
		return i - substr.size();
	else
		return -1;
}

//replace the first occurence of oldVal with newVal in s
void replace_old_to_new(string &s, const string &oldVal, const string &newVal) {
	unsigned idx = index_of_sub(s, oldVal, 0);
	if (idx != static_cast<unsigned>(-1)) {
		s.erase(idx, oldVal.size());
		s.insert(idx, newVal);
	}
}

#endif
