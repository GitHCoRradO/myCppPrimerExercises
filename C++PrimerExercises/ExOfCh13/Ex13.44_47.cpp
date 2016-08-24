#include "./Ex13.44.h"

#include <algorithm>
using std::for_each;
#include <iostream>
using std::cout;

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
	cout << "String::String(const String &)";
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
	cout << "String &String::operator=(const String&)";
	return *this;
}

int main() {
	return 0;
}
