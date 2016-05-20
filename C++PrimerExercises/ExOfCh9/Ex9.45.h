#ifndef EX_9_45_H
#define EX_9_45_H

#include <iostream>
#include <string>
using std::string;

void add_addresses(string &name, const string &pref, const string &suff) {
	name.insert(name.begin(), pref.begin(), pref.end());
	name.append(suff);
}
#endif
