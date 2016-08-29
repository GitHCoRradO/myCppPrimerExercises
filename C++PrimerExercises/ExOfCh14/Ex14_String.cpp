#include "./Ex14_String.h"

#include <algorithm>
using std::for_each;
#include <vector>
using std::vector;
/*
#include <iterator>
using std::make_move_iterator;
*/

pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
	auto str = alloc.allocate(e - b);
	return { str, std::uninitialized_copy(b, e, str) };
}

String::String(const char *s) {
	const char *sl = s;	//const char *sl = const_cast<char *>(s);  //??
	while (*sl)
		++sl;
	auto newstr = alloc_n_copy(s, ++sl);
	first = newstr.first;
	last = newstr.second;
}

String::String(const String &rhs) {
	auto newstr = alloc_n_copy(rhs.first, rhs.last);
	first = newstr.first;
	last = newstr.second;
	cout << "copy constructor" << endl;
}

void String::free() {
	if (first) {	//I think first would never be nullptr
		for_each(first, last, [this](char &c) { alloc.destroy(&c); });
		alloc.deallocate(first, last - first);
	}
}

String::~String() {
	free();
}

String &String::operator=(const String &rhs) {
	auto newstr = alloc_n_copy(rhs.first, rhs.last);
	free();
	first = newstr.first;
	last = newstr.second;
	cout << "copy assignment operator" << endl;
	return *this;
}

String::String(String &&rhs) noexcept : first(rhs.first), last(rhs.last) {
	rhs.first = rhs.last = nullptr;
	cout << "move constructor" << endl;
}
String &String::operator=(String &&rhs) noexcept {
	if (this != &rhs) {
		free();
		first = rhs.first;
		last = rhs.last;
		rhs.first = rhs.last = nullptr;
	}
	cout << "move assignment operator" << endl;
	return *this;
}
ostream &operator<<(ostream &os, const String &rhs) {
	os << rhs.first; // not sure about this
	return os;
}

bool operator==(const String &lhs, const String &rhs) {
	return lhs.size() == rhs.size() && std::equal(lhs.first, lhs.last, rhs.first);
}
bool operator!=(const String &lhs, const String &rhs) {
	return !(lhs == rhs);
}
bool operator<(const String &lhs, const String &rhs) {
	return std::lexicographical_compare(lhs.first, lhs.last, rhs.first, rhs.last);
}
bool operator>(const String &lhs, const String &rhs) {
	return rhs > lhs;
}
bool operator<=(const String &lhs, const String &rhs) {
	return !(lhs > rhs);
}
bool operator>=(const String &lhs, const String &rhs) {
	return !(lhs < rhs);
}

int main() {
        return 0;
}
