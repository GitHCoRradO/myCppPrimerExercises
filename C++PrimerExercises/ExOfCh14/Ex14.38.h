#ifndef EX_14_38_H
#define EX_14_38_H

#include <string>
using std::string;

class length_bound {
private:
	unsigned lower;
	unsigned upper;
public:
	length_bound(unsigned l, unsigned u) : lower(l), upper(u) { }
	bool operator()(const string &) const;
};
inline bool length_bound::operator()(const string &s) const {
	if (lower <= s.size() && upper >= s.size())
		return true;
	else
		return false;
	//return lower <= s.size() && upper >= s.size();
}

#endif
