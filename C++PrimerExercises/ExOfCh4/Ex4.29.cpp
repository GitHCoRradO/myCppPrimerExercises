#include <iostream>
using std::cout;
using std::endl;
int main() {
	int x[10];
	int *p = x;
	cout << sizeof(x)/sizeof(*x) << endl;	//prints 10.
	cout << sizeof(p)/sizeof(*p) << endl;	//no idea about the result.the result printed by my machine is 1. here is a reference:http://stackoverflow.com/questions/2428765/why-the-size-of-a-pointer-is-4bytes-in-c/2428809#2428809
	return 0;
}
