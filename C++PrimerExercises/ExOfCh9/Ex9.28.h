#ifndef EX_9_28_H
#define EX_9_28_H

#include <forward_list>
#include <string>
using std::string;
using std::forward_list;

void insert_string(forward_list<string> &flist, const string &str1, const string &str2) {
	auto prev = flist.before_begin();
	for (auto curr = flist.begin(); curr != flist.end(); prev = curr++) {
		if (*curr == str1) {
			flist.insert_after(curr,str2);
			return;
		}
	}
	flist.insert_after(prev,str2);
}

#endif
