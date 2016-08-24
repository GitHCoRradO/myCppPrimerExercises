#ifndef EX_13_44_H
#define EX_13_44_H

#include <memory>
using std::allocator;
#include <utility>
using std::pair;

class String {
public:
	//constructors
	//String() : first(nullptr), last(nullptr) { }  // such default constructor would lead to error.any String should be
							// null terminated.
	String() : String("") { }
	String(const char *);
	//copy control
	String(const String&);
	String &operator=(const String&);
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

#endif
