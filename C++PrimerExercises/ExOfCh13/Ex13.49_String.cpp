#include "./Ex13.49_String.h"

#include <algorithm>
using std::for_each;
#include <iostream>
using std::cout;
using std::endl;
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
/*
String::String(String &&rhs) {
	auto newstr = alloc.allocate(rhs.size());
	auto end = std::uninitialized_copy(make_move_iterator(rhs.first), make_move_iterator(rhs.last), newstr);
	first = newstr;
	last = end;
	rhs.first = rhs.last = nullptr;
}
String &String::operator=(String &&rhs) {
	if (this != &rhs) {
		free();
		auto newstr = alloc.allocate(rhs.size());
		auto end = std::uninitialized_copy(make_move_iterator(rhs.first), make_move_iterator(rhs.last), newstr);
		first = newstr;
		last = end;
		rhs.first = rhs.last = nullptr;
	}
	return *this;
}
*/
/*
there is no need to call allocate on alloc when we move resource from one String to another.we need only to change the first and last member.this
way the new String takes over onwership of the chars in dynamic memory(alloc).after all,after the move or move assignment,any operations on the moved
from String--i.e.String.size(),String.length(),String.free()--have nothing to do with its orignal String.alloc,which stores the chars,for
String.first and String.last are both set to nullptr.
since the move operations involve only assigning to pointers,we can be sure that no exception would be thrown during moving Strings.
*/

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
void foo(String x) { }

void bar(const String &x) { }

String baz() {
        String ret("world");
        return ret;
}

int main() {
        String s0;
        String s1("hello");
        String s2(s0);		//copy constructor
        String s3 = s1;		//copy constructor
        s2 = s1;		//copy assignment operator

        foo(s1);		//copy constructor
        bar(s1);		//copy constructor
        foo("temporary");	//String(const char *)
        bar("temporary");	//copy constructor
        String s4 = baz();	//move constrctor

        vector<String> svec;
        svec.push_back(s0);		//move constructor
        svec.push_back(s1);		//move constructor
        svec.push_back(baz());		//move constructor
        svec.push_back("good job");	//move constructor
        return 0;
}
