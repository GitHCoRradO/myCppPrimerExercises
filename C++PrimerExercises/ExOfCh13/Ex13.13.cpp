#include "./Ex13.13.h"
#include <vector>
using std::vector;

void f(const X& rx, X x) {
	vector<X> vec;
	vec.reserve(2);		//without vec.reserve(2); each of  "X(const X&)" and "~X()" would be printed 1 more time.why?
	vec.push_back(rx);
	vec.push_back(x);
}
int main() {
	X *px = new X;
	f(*px, *px);
	delete px;
	return 0;
}	
