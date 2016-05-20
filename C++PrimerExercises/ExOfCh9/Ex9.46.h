#ifndef EX_9_46_H
#define EX_9_46_H

#include <iostream>
#include <string>
using std::string;

void add_addresses(string &name, const string &pref, const string &suff) {
	name.insert(0, pref, 0, pref.size());
	name.insert(name.size(), suff, 0, suff.size());
}
#endif
