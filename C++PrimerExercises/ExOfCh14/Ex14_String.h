#ifndef EX_14_STRING_H
#define EX_14_STRING_H

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
#include <memory>
using std::allocator;
#include <utility>
using std::pair;

class String {
friend ostream &operator<<(ostream &, const String &);
friend bool operator==(const String &, const String &);
friend bool operator!=(const String &, const String &);
friend bool operator<(const String &, const String &);
friend bool operator>(const String &, const String &);
friend bool operator<=(const String &, const String &);
friend bool operator>=(const String &, const String &);
public:
	//constructors
	//String() : first(nullptr), last(nullptr) { }  // such default constructor would lead to error.any String should be
							// null terminated.
	String() : String("") { }
	String(const char *);
	//copy constructor
	String(const String&);
	//copy assignment operator
	String &operator=(const String&);
	//move constructor
	String(String &&) noexcept;
	//move assignment operator
	String &operator=(String &&) noexcept;
	//destructor
	~String();
	//other members
	size_t size() const { return last - first; }		//total number of chars including the null char
	/* number of chars excluding the null char.
	considering this function,there should not be a String with String.size() == 0.
	thus,size() >= 1.when size() == 1,the only char in this String should be null char corresponding to C-style string "".
	*/
	size_t length() const { return  last - first - 1; }		
	
private:
	pair<char *, char *> alloc_n_copy(const char *, const char *);
	void free();
	allocator<char> alloc;
	char *first;
	char *last;
};
ostream &operator<<(ostream &, const String &);
bool operator==(const String &, const String &);
bool operator!=(const String &, const String &);
bool operator<(const String &, const String &);
bool operator>(const String &, const String &);
bool operator<=(const String &, const String &);
bool operator>=(const String &, const String &);
#endif
