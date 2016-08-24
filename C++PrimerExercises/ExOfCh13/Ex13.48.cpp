#include "./Ex13.44.h"

#include <algorithm>
using std::for_each;
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

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
	cout << "copy assignment" << endl;
	return *this;
}

void foo(String x) { }

void bar(const String &x) { }

String baz() {
	String ret("world");
	return ret;
}

int main() {
	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	s2 = s1;
	
	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s4 = baz();

	vector<String> svec;
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(baz());
	svec.push_back("good job");
	return 0;
}
