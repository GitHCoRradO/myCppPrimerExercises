#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	char *const p = new char[11](), *q = p, c;
	while (cin >> c && q != p + 10)		//the 11th character of p will always be 0 indicating the null character of a C-style string
		*q++ = c;
	//unsigned size = q - p;	//no need.
	cout << p << endl;
	delete [] p;		//p points to a null-terminated C-style string.we do not need to worry whether we input less characters than we previously allocated
	return 0;		//for the remaining chars will be value initialized to 0.
}				//problem arises:what if we input 1010.we know that the full array in dynamic memory would be 10100000000
				//why does the output only print 1010?
