#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void f() {
	cout << "this is function f()." << endl;
}
void f(int i) {
	cout << "this is function f(int)." << endl;
}
void f(int i1, int i2) {
	cout << "this is function f(int, int)." << endl;
}
void f(double d1, double d2) {
	cout << "this is function f(double, double)." << endl;
}
void f(double, double d2 = 3.14);
int main() {
	f(2.56, 42);	//compile error.ambiguous call.
	f(42);
	f(42, 0);
	f(2.56, 3.14);
	return 0;
}
